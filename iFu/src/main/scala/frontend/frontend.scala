package frontend

import iFu.common.{CoreBundle, CoreModule}
import chisel3._
import chisel3.util.{isPow2, log2Ceil}
import frontend.Parameters._
import iFu.BankedPredictor
import iFu.frontend.{FetchBufferResp, ICache}
import iFu.frontend.predictors.{MaskLower, globalHistoryLength}
//TODO 重命名FrontEndExceptions,GlobalHistory,如果之后RAS增加计数器，Histories的update函数需要更改，
//TODO FetchBundle重命名为FetchBufferEntry
import chisel3.util._
object Parameters{
    val fetchWidth = 8
    val bankWidth = 4
    val BSRC_SZ = 3
    val globalHistoryLength = 16
    val nRasEntries = 32
    val fetchBytes = fetchWidth * 4
    val CFI_SZ = 3
    val ftqSz = 40 //numFTQEntries
    val localHistoryLength = 16

}

object WrapDec
{
    // "n" is the number of increments, so we wrap at n-1.
    def apply(value: UInt, n: Int): UInt = {
        if (isPow2(n)) {
            (value - 1.U)(log2Ceil(n)-1,0)
        } else {
            val wrap = (value === 0.U)
            Mux(wrap, (n-1).U, value - 1.U)
        }
    }
}
object WrapInc
{
    // "n" is the number of increments, so we wrap at n-1.
    def apply(value: UInt, n: Int): UInt = {
        if (isPow2(n)) {
            (value + 1.U)(log2Ceil(n)-1,0)
        } else {
            val wrap = (value === (n-1).U)
            Mux(wrap, 0.U, value + 1.U)
        }
    }
}

class S3 extends CoreBundle{
    val pc      = UInt(vaddrBits.W)
    val insts   = UInt((fetchWidth * coreInstrBits).W)
    val mask    = UInt(fetchWidth.W)
    val xcpt    = new FrontendExceptions
    val ghist   = new GlobalHistory
    val fsrc    = UInt(BSRC_SZ.W)
}
class FrontendExceptions extends Bundle {
    val pf = new Bundle {
        val valid = Bool()
    }
    val gf = new Bundle {
        val valid = Bool()
    }
    val ae = new Bundle {
        val valid = Bool()
    }
}
class GlobalHistory extends CoreBundle {
    val old_history = UInt(globalHistoryLength.W)
    val current_saw_branch_not_taken = Bool()
    val new_saw_branch_not_taken = Bool()
    val new_saw_branch_taken = Bool()
    val ras_idx = UInt(log2Ceil(nRasEntries).W)

    def histories(bank: Int) = {
        if (bank == 0) {
            old_history
        } else {
            Mux(new_saw_branch_taken, old_history << 1 | 1.U,
                Mux(new_saw_branch_not_taken, old_history << 1,
                    old_history))
        }
    }

    def ===(other: GlobalHistory): Bool = {
        ((old_history === other.old_history) &&
                (new_saw_branch_not_taken === other.new_saw_branch_not_taken) &&
                (new_saw_branch_taken === other.new_saw_branch_taken)
                )
    }

    def =/=(other: GlobalHistory): Bool = !(this === other)

    def update(branches: UInt, cfi_taken: Bool, cfi_is_br: Bool, cfi_idx: UInt,
               cfi_valid: Bool, addr: UInt,
               cfi_is_call: Bool, cfi_is_ret: Bool): GlobalHistory = {
        val cfi_idx_fixed = cfi_idx(log2Ceil(fetchWidth) - 1, 0)
        val cfi_idx_oh = UIntToOH(cfi_idx_fixed)
        val new_history = Wire(new GlobalHistory)
        val not_taken_branches = branches & Mux(cfi_valid,
            MaskLower(cfi_idx_oh) & ~Mux(cfi_is_br && cfi_taken, cfi_idx_oh, 0.U(fetchWidth.W)),
            ~(0.U(fetchWidth.W)))
        val cfi_in_bank_0 = cfi_valid && cfi_taken && cfi_idx_fixed < bankWidth.U
        val ignore_second_bank = cfi_in_bank_0 || mayNotBeDualBanked(addr)

        val first_bank_saw_not_taken = not_taken_branches(bankWidth - 1, 0) =/= 0.U || current_saw_branch_not_taken
        new_history.current_saw_branch_not_taken := false.B
        when(ignore_second_bank) {
            new_history.old_history := histories(1)
            new_history.new_saw_branch_not_taken := first_bank_saw_not_taken
            new_history.new_saw_branch_taken := cfi_is_br && cfi_in_bank_0
        }.otherwise {
            new_history.old_history := Mux(cfi_is_br && cfi_in_bank_0, histories(1) << 1 | 1.U,
                Mux(first_bank_saw_not_taken, histories(1) << 1,
                    histories(1)))
            new_history.new_saw_branch_not_taken := not_taken_branches(fetchWidth - 1, bankWidth)
            new_history.new_saw_branch_taken := cfi_valid && cfi_is_br && !cfi_in_bank_0
        }

        new_history.ras_idx := Mux(cfi_valid && cfi_is_call, WrapInc(ras_idx, nRasEntries),
            Mux(cfi_valid && cfi_is_ret, WrapDec(ras_idx, nRasEntries), ras_idx))
        new_history
    }
}
trait HasBoomFrontendParameters extends HasL1ICacheParameters
{
    // How many banks does the ICache use?
    val nBanks = if (cacheParams.fetchBytes <= 8) 1 else 2
    // How many bytes wide is a bank?
    val bankBytes = fetchBytes/nBanks

    val bankWidth = fetchWidth/nBanks

    require(nBanks == 1 || nBanks == 2)



    // How many "chunks"/interleavings make up a cache line?
    val numChunks = cacheParams.blockBytes / bankBytes

    // Which bank is the address pointing to?
    def bank(addr: UInt) = if (nBanks == 2) addr(log2Ceil(bankBytes)) else 0.U
    def isLastBankInBlock(addr: UInt) = {
        (nBanks == 2).B && addr(blockOffBits-1, log2Ceil(bankBytes)) === (numChunks-1).U
    }
    def mayNotBeDualBanked(addr: UInt) = {
        require(nBanks == 2)
        isLastBankInBlock(addr)
    }

    def blockAlign(addr: UInt) = ~(~addr | (cacheParams.blockBytes-1).U)
    def bankAlign(addr: UInt) = ~(~addr | (bankBytes-1).U)

    def fetchIdx(addr: UInt) = addr >> log2Ceil(fetchBytes)

    def nextBank(addr: UInt) = bankAlign(addr) + bankBytes.U
    def nextFetch(addr: UInt) = {
        if (nBanks == 1) {
            bankAlign(addr) + bankBytes.U
        } else {
            require(nBanks == 2)
            bankAlign(addr) + Mux(mayNotBeDualBanked(addr), bankBytes.U, fetchBytes.U)
        }
    }

    def fetchMask(addr: UInt) = {
        val idx = addr.extract(log2Ceil(fetchWidth)+log2Ceil(coreInstBytes)-1, log2Ceil(coreInstBytes))
        if (nBanks == 1) {
            ((1 << fetchWidth)-1).U << idx
        } else {
            val shamt = idx.extract(log2Ceil(fetchWidth)-2, 0)
            val end_mask = Mux(mayNotBeDualBanked(addr), Fill(fetchWidth/2, 1.U), Fill(fetchWidth, 1.U))
            ((1 << fetchWidth)-1).U << shamt & end_mask
        }
    }

    def bankMask(addr: UInt) = {
        val idx = addr.extract(log2Ceil(fetchWidth)+log2Ceil(coreInstBytes)-1, log2Ceil(coreInstBytes))
        if (nBanks == 1) {
            1.U(1.W)
        } else {
            Mux(mayNotBeDualBanked(addr), 1.U(2.W), 3.U(2.W))
        }
    }
}
//FetchBufferEntry
class FetchBundle extends CoreBundle with HasBoomFrontendParameters
{
    val pc          = UInt(vaddrBits.W)
    val next_pc     = UInt(vaddrBits.W)
    val insts       = Vec(fetchWidth,Bits(coreInstrBits.W))
    val exp_insts   = Vec(fetchWidth,Bits(coreInstrBits.W))
    //Information for sfb
    // NOTE: This IS NOT equivalent to uop.pc_lob, that gets calculated in the FB
    val sfbs        = Vec(fetchWidth,Bool())
    val sfb_masks   = Vec(fetchWidth,UInt((2*fetchWidth).W))
    val sfb_dests   = Vec(fetchWidth,UInt((1+log2Ceil(fetchBytes)).W))
    val shadowable_mask = Vec(fetchWidth,Bool())
    val shadowed_mask   = Vec(fetchWidth,Bool())

    val cfi_idx     = Valid(UInt(log2Ceil(fetchWidth).W))
    val cfi_type    = UInt(CFI_SZ.W)
    val cfi_is_call = Bool()
    val cfi_is_ret  = Bool()
    val cfi_npc_plus4   = Bool()

    val ras_top     = UInt(vaddrBits.W)

    val ftq_idx     = UInt(log2Ceil(ftqSz).W)
    val mask        = UInt(fetchWidth.W)

    val br_mask     = UInt(fetchWidth.W)

    val ghist       = new GlobalHistory
    val lhist       = Vec(nBanks,UInt(localHistoryLength.W))

    val xcpt_pf_if  = Bool()    //I-TLB miss(instruction fetch fault)
    val xcpt_ae_if  = Bool()    //Access exception

    val bp_debug_if_oh = Vec(fetchWidth,Bool())
    val bp_xcpt_if_oh   = Vec(fetchWidth,Bool())

    val bpd_meta    =Vec(nBanks,UInt())

    val fsrc        = UInt(BSRC_SZ.W)
    val tsrc        = UInt(BSRC_SZ.W)

}
//IO for the BOOM Frontend to/from the CPU
class FrontendToCPUIO extends CoreModule
{
    val fetchpacket     = Flipped(new DecoupledIO(new FetchBufferResp))

    // 1 for xcpt/jalr/auipc/flush
    val get_pc      = Flipped(Vec(2,new GetPCFromFtqIO()))
    val debug_ftq_idx = Output(Vec(coreWidth, UInt(log2Ceil(ftqSz).W)))
    val debug_fetch_pc = Input(Vec(coreWidth, UInt(vaddrBits.W)))

    //Breakpoint info
    val status      = Output(new MStatus)
    val bp          = Output(Vec(nBreakpoints,new BP))
    val mcontext    = Output(UInt(mcontextWidth.W))
    val scontext          = Output(UInt(scontextWidth.W))

    val sfence      = Valid(new SFenceReq)
    val brupdate    = Output(new BrUpdateInfo)

    //Redirects change the PC
    val redirect_flush  = Output(Bool())
    val redirect_val    = Output(Bool())
    val redirect_pc     = Output(UInt())    //分支指令的结果
    val redirect_ftq_idx= Output(UInt())
    val redirect_ghist  = Output(new GlobalHistory)

    val commit          = Valid(UInt(ftqSz.W))
    val flush_icache    = Output(Bool())
    val perf            = Input(new FrontendPerfEvents)
}
class FrontendIO extends CoreBundle {
    val cpu = Flipped(new BoomFrontendIO())
//    val ptw = new TLBPTWIO()
    val errors = new ICacheErrors
}

//TODO Frontend.273 bpd，RAS,icache的接口
class Frontend extends CoreModule
{
    val reset_addr = 0.U(vaddrBits)
    val io = IO(new FrontendIO)
    val io_reset_vector =reset_addr

    val bpd = Module(new BankedPredictor)
    bpd.io.f3_fire := false.B
    val ras = Module(new RAS)

    val icache = Module(new ICache())
    icache.io.invalidate := io.cpu.flush_icache

}
