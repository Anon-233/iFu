/***************************************************************************************
 * Copyright (c) 2020-2021 Institute of Computing Technology, Chinese Academy of Sciences
 * Copyright (c) 2020-2021 Peng Cheng Laboratory
 *
 * XiangShan is licensed under Mulan PSL v2.
 * You can use this software according to the terms and conditions of the Mulan PSL v2.
 * You may obtain a copy of Mulan PSL v2 at:
 *          http://license.coscl.org.cn/MulanPSL2
 *
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
 * EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
 * MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
 *
 * See the Mulan PSL v2 for more details.
 ***************************************************************************************/

#include "difftest.h"

#include "goldenmem.h"
#include "ram.h"
#include "spikedasm.h"

static const char* reg_name[DIFFTEST_NR_REG] = {
    "r0", "ra", "tp", "sp", "a0", "a1", "a2", "a3", "a4", "a5",
    "a6", "a7", "t0", "t1", "t2", "t3", "t4", "t5", "t6", "t7",
    "t8", " x", "fp", "s0", "s1", "s2", "s3", "s4", "s5", "s6",
    "s7", "s8",
    "crmd", "prmd", "euen", "ecfg", "era", "badv", "eentry", "tlbidx", "tlbehi", "tlbelo0",
    "tlbelo1", "asid", "pgdl", "pgdh", "save0", "save1", "save2", "save3", "tid", "tcfg",
    "tval", "llbctl", "tlbrentry", "dmw0", "dmw1", "estat", "this_pc"};

void printf_red(const char* s) { printf("\033[0m\033[1;31m%s\033[0m", s); }
void printf_green(const char* s) { printf("\033[0m\033[1;32m%s\033[0m", s); }
void printf_yellow(const char* s) { printf("\033[0m\033[1;33m%s\033[0m", s); }


Difftest** difftest = NULL;

int difftest_init() {
    difftest = new Difftest*[NUM_CORES];  // NUM_CORES = 1
    for (int i = 0; i < NUM_CORES; i++) {   // 遍历每个core
        difftest[i] = new Difftest(i);      // 生成一个对应的diff
    }
    return 0;
}

int init_nemuproxy() {  // ??? 不知道代理有什么用
    for (int i = 0; i < NUM_CORES; i++) {
        difftest[i]->update_nemuproxy(i);
    }
    return 0;
}

int difftest_state() {
    for (int i = 0; i < NUM_CORES; i++) {
        if (difftest[i]->get_trap_valid()) {
            return difftest[i]->get_trap_code();  // 如果有trap，返回trap code
        }
    }
    return -1;
}

int difftest_step() {
    for (int i = 0; i < NUM_CORES; i++) {
        int ret = difftest[i]->step();
        if (ret) {
            return ret;
        }
    }
    return 0;
}

Difftest::Difftest(int coreid) : id(coreid) {
    state = new DiffState();
    clear_step();
}

void Difftest::update_nemuproxy(int coreid) {
    proxy = new DIFF_PROXY(coreid);
}

int Difftest::step() {
    progress = false;
    ticks++;

    // TODO: update nemu/xs to fix this_pc comparison
    dut.csr.this_pc = dut.commit[0].pc;  // ???
    // printf_yellow("=============================\n");
    // printf("this_pc: 0x%x\n", dut.csr.this_pc);
    // printf_green("================================\n");

    if (check_timeout()) {
        return 1;
    }
    do_first_instr_commit();
    if (do_store_check()) {
        return 1;
    }

    if (!has_commit) {
        return 0;
    }
    static int cnt = 0;
    static unsigned long long clk = 0;
    static unsigned long long total_commit = 0;
    num_commit = 0;  // reset num_commit this cycle to 0
    // interrupt has the highest priority
    if (dut.excp.interrupt) {
        dut.csr.this_pc = dut.excp.exceptionPC;
        do_interrupt();
    } else if (dut.excp.exception) {
        // We ignored instrAddrMisaligned exception (0) for better debug interface
        // XiangShan should always support RVC, so instrAddrMisaligned will never happen
        // TODO: update NEMU, for now, NEMU will update pc when exception happen
        dut.csr.this_pc = dut.excp.exceptionPC;
        do_exception();
    } else {
        // TODO: is this else necessary?
        // while (num_commit < DIFFTEST_COMMIT_WIDTH && dut.commit[num_commit].valid) {
        //     do_instr_commit(num_commit);
        //     dut.commit[num_commit].valid = 0;  // ???
        //     num_commit++;
        // }
        for (int i = 0; i < DIFFTEST_COMMIT_WIDTH; i++) {
            if (dut.commit[i].valid) {
                do_instr_commit(i);
                num_commit++;
                cnt++;
                total_commit++;
            }
        }
    }

    clk++;

    if (cnt >= 10000) {
        printf_green("10k instructions committed\n");
        printf("===> now ipc: %lf <===\n", 1.0 * total_commit / clk);
        cnt = 0;
    }

    if (!progress) {
        return 0;
    }

    proxy->regcpy(ref_regs_ptr, REF_TO_DUT);

    if (num_commit > 0) {
        // state->record_group(dut.commit[0].pc, num_commit);
        for (int i = 0; i < DIFFTEST_COMMIT_WIDTH; i++) {
            if (dut.commit[i].valid) {
                state->record_group(dut.commit[i].pc, num_commit);
                break;
            }
        }
    }

    for (int i = 0; i < DIFFTEST_COMMIT_WIDTH; i++) {
        dut.commit[i].valid = 0;
    }

    // swap nemu_pc and ref.csr.this_pc for comparison
    // uint64_t nemu_next_pc = ref.csr.this_pc;
    // ref.csr.this_pc = nemu_this_pc;
    // nemu_this_pc = nemu_next_pc;
    int NUM_REGS = DIFFTEST_NR_REG - 1;
    if (memcmp(dut_regs_ptr, ref_regs_ptr, NUM_REGS * sizeof(uint32_t))) {
        display();
        for (int i = 0; i < NUM_REGS; i++) {
            if (dut_regs_ptr[i] != ref_regs_ptr[i]) {
                printf("\033[0m\033[1;33m%7s different at pc = 0x%010lx, right= 0x%016lx, wrong = 0x%016lx\033[0m\n",
                       reg_name[i], ref.csr.this_pc, ref_regs_ptr[i], dut_regs_ptr[i]);
            }
        }
        return 1;
    }

    return 0;
}

void Difftest::do_interrupt() {
    state->record_abnormal_inst(dut.commit[0].pc, dut.commit[0].inst, RET_INT, dut.excp.interrupt);
    proxy->raise_intr(dut.excp.interrupt | (1ULL << 63));
    progress = true;
}

void Difftest::do_exception() {
    state->record_abnormal_inst(dut.excp.exceptionPC, dut.commit[0].inst, RET_EXC, dut.excp.exception);
    if (dut.excp.exception == 12 || dut.excp.exception == 13 || dut.excp.exception == 15) {
        // printf("exception cause: %d\n", dut.event.exception);
        struct ExecutionGuide guide;
        guide.exceptionNo = dut.excp.exception;
        // guide.mtval = dut.csr.mtval;
        // guide.stval = dut.csr.stval;
        proxy->guided_exec(&guide);
    } else {
        proxy->exec(1);
    }
    progress = true;
}

void Difftest::do_instr_commit(int i) {
    progress = true;
    last_commit = ticks;

    // store the writeback info to debug array
    state->record_inst(dut.commit[i].pc, dut.commit[i].inst, dut.commit[i].wen, dut.commit[i].wdest, dut.commit[i].wdata);

    // sync lr/sc reg status
    /* if (dut.commit[i].scFailed) {
      struct SyncState sync;
      sync.lrscValid = 0;
      sync.lrscAddr = 0;
      proxy->uarchstatus_cpy((uint64_t*)&sync, DUT_TO_REF); // sync lr/sc microarchitectural regs
    } */

    // MMIO accessing should not be a branch or jump, just +2/+4 to get the next pc
    // to skip the checking of an instruction, just copy the reg state to reference design
    if (dut.commit[i].skip) {
        proxy->regcpy(ref_regs_ptr, REF_TO_DIFFTEST);
        ref.csr.this_pc += 4;
        if (dut.commit[i].wen && dut.commit[i].wdest != 0) {
            // TODO: FPR
            ref_regs_ptr[dut.commit[i].wdest] = dut.commit[i].wdata;
        }
        proxy->regcpy(ref_regs_ptr, DIFFTEST_TO_REF);
        return;
    }

    // single step exec
    proxy->exec(1);
}

void Difftest::do_first_instr_commit() {
    if (!has_commit && dut.commit[0].valid && dut.commit[0].pc == FIRST_INST_ADDRESS) {
        printf("nishuodedui, danshiwojuedeburuyuanshen\n");
        printf("The first instruction of core %d has commited. Difftest enabled. \n", id);
        has_commit = 1;
        nemu_this_pc = dut.csr.this_pc;

        proxy->memcpy(FIRST_INST_ADDRESS, get_img_start() + FIRST_INST_ADDRESS, get_img_size(), DIFFTEST_TO_REF);
        proxy->regcpy(dut_regs_ptr, DIFFTEST_TO_REF);
    }
}

int Difftest::do_store_check() {
    for (int i = 0; i < DIFFTEST_STORE_WIDTH; i++) {
        if (!dut.store[i].valid) {
            return 0;
        }
        auto addr = dut.store[i].addr;
        auto data = dut.store[i].data;
        auto mask = dut.store[i].mask;
        if (proxy->store_commit(&addr, &data, &mask)) {
            display();
            printf("Mismatch for store commits %d: \n", i);
            printf("  REF commits addr 0x%lx, data 0x%lx, mask 0x%x\n", addr, data, mask);
            printf("  DUT commits addr 0x%lx, data 0x%lx, mask 0x%x\n",
                   dut.store[i].addr, dut.store[i].data, dut.store[i].mask);
            return 1;
        }
        dut.store[i].valid = 0;
    }
    return 0;
}

inline int handle_atomic(int coreid, uint64_t atomicAddr, uint64_t atomicData, uint64_t atomicMask, uint8_t atomicFuop, uint64_t atomicOut) {
    // We need to do atmoic operations here so as to update goldenMem
    if (!(atomicMask == 0xf || atomicMask == 0xf0 || atomicMask == 0xff)) {
        printf("Unrecognized mask: %lx\n", atomicMask);
        return 1;
    }

    if (atomicMask == 0xff) {
        uint64_t rs = atomicData;  // rs2
        uint64_t t = atomicOut;    // original value
        uint64_t ret;
        uint64_t mem;
        read_goldenmem(atomicAddr, &mem, 8);
        if (mem != t && atomicFuop != 007 && atomicFuop != 003) {  // ignore sc_d & lr_d
            printf("Core %d atomic instr mismatch goldenMem, mem: 0x%lx, t: 0x%lx, op: 0x%x, addr: 0x%lx\n", coreid, mem, t, atomicFuop, atomicAddr);
            return 1;
        }
        switch (atomicFuop) {
            case 002:
            case 003:
                ret = t;
                break;
            case 006:
            case 007:
                ret = rs;
                break;
            case 012:
            case 013:
                ret = rs;
                break;
            case 016:
            case 017:
                ret = t + rs;
                break;
            case 022:
            case 023:
                ret = (t ^ rs);
                break;
            case 026:
            case 027:
                ret = t & rs;
                break;
            case 032:
            case 033:
                ret = t | rs;
                break;
            case 036:
            case 037:
                ret = ((int64_t)t < (int64_t)rs) ? t : rs;
                break;
            case 042:
            case 043:
                ret = ((int64_t)t > (int64_t)rs) ? t : rs;
                break;
            case 046:
            case 047:
                ret = (t < rs) ? t : rs;
                break;
            case 052:
            case 053:
                ret = (t > rs) ? t : rs;
                break;
            default:
                printf("Unknown atomic fuOpType: 0x%x\n", atomicFuop);
        }
        update_goldenmem(atomicAddr, &ret, atomicMask, 8);
    }

    if (atomicMask == 0xf || atomicMask == 0xf0) {
        uint32_t rs = (uint32_t)atomicData;  // rs2
        uint32_t t = (uint32_t)atomicOut;    // original value
        uint32_t ret;
        uint32_t mem;
        uint64_t mem_raw;
        uint64_t ret_sel;
        atomicAddr = (atomicAddr & 0xfffffffffffffff8);
        read_goldenmem(atomicAddr, &mem_raw, 8);

        if (atomicMask == 0xf)
            mem = (uint32_t)mem_raw;
        else
            mem = (uint32_t)(mem_raw >> 32);

        if (mem != t && atomicFuop != 006 && atomicFuop != 002) {  // ignore sc_w & lr_w
            printf("Core %d atomic instr mismatch goldenMem, rawmem: 0x%lx mem: 0x%x, t: 0x%x, op: 0x%x, addr: 0x%lx\n", coreid, mem_raw, mem, t, atomicFuop, atomicAddr);
            return 1;
        }
        switch (atomicFuop) {
            case 002:
            case 003:
                ret = t;
                break;
            case 006:
            case 007:
                ret = rs;
                break;  // TODO
            case 012:
            case 013:
                ret = rs;
                break;
            case 016:
            case 017:
                ret = t + rs;
                break;
            case 022:
            case 023:
                ret = (t ^ rs);
                break;
            case 026:
            case 027:
                ret = t & rs;
                break;
            case 032:
            case 033:
                ret = t | rs;
                break;
            case 036:
            case 037:
                ret = ((int32_t)t < (int32_t)rs) ? t : rs;
                break;
            case 042:
            case 043:
                ret = ((int32_t)t > (int32_t)rs) ? t : rs;
                break;
            case 046:
            case 047:
                ret = (t < rs) ? t : rs;
                break;
            case 052:
            case 053:
                ret = (t > rs) ? t : rs;
                break;
            default:
                printf("Unknown atomic fuOpType: 0x%x\n", atomicFuop);
        }
        ret_sel = ret;
        if (atomicMask == 0xf0)
            ret_sel = (ret_sel << 32);
        update_goldenmem(atomicAddr, &ret_sel, atomicMask, 8);
    }
    return 0;
}

int Difftest::check_timeout() {
    // check whether there're any commits since the simulation starts
    if (!has_commit && ticks > last_commit + firstCommit_limit) {
        eprintf("No instruction commits for %lu cycles of core %d. Please check the first instruction.\n",
                firstCommit_limit, id);
        eprintf("Note: The first instruction may lie in 0x10000000 which may executes and commits after 500 cycles.\n");
        eprintf("   Or the first instruction may lie in 0x80000000 which may executes and commits after 2000 cycles.\n");
        display();
        return 1;
    }

    // check whether there're any commits in the last 5000 cycles
    if (has_commit && ticks > last_commit + stuck_limit) {
        eprintf(
            "No instruction of core %d commits for %lu cycles, maybe get stuck\n"
            "(please also check whether a fence.i instruction requires more than %lu cycles to flush the icache)\n",
            id, stuck_limit, stuck_limit);
        eprintf("Let REF run one more instruction.\n");
        proxy->exec(1);
        display();
        return 1;
    }

    return 0;
}

void Difftest::raise_trap(int trapCode) {
    dut.trap.valid = 1;
    dut.trap.code = trapCode;
}

void Difftest::clear_step() {
    dut.trap.valid = 0;
    for (int i = 0; i < DIFFTEST_COMMIT_WIDTH; i++) {
        dut.commit[i].valid = 0;
    }
    // dut.sbuffer.resp = 0;
    for (int i = 0; i < DIFFTEST_STORE_WIDTH; i++) {
        dut.store[i].valid = 0;
    }
    for (int i = 0; i < DIFFTEST_COMMIT_WIDTH; i++) {
        dut.load[i].valid = 0;
    }
    // dut.atomic.resp = 0;
    // dut.ptw.resp = 0;
}

void Difftest::display() {
    state->display(this->id);

    printf("\n==============  REF Regs  ==============\n");
    fflush(stdout);
    proxy->isa_reg_display();
    // printf("priviledgeMode: %lu\n", dut.csr.priviledgeMode);
}

void DiffState::display(int coreid) {
    int spike_invalid = test_spike();

    printf("\n============== Commit Group Trace (Core %d) ==============\n", coreid);
    for (int j = 0; j < DEBUG_GROUP_TRACE_SIZE; j++) {
        if (j == ((retire_group_pointer - 1) % DEBUG_INST_TRACE_SIZE)) {
            printf("commit group [%x]: pc %010lx cmtcnt %d ",
                   j, retire_group_pc_queue[j], retire_group_cnt_queue[j]);
            printf_yellow("<-- commit head\n");
        } else {
            printf("commit group [%x]: pc %010lx cmtcnt %d\n",
                   j, retire_group_pc_queue[j], retire_group_cnt_queue[j]);
        }
    }

    printf("\n============== Commit Instr Trace ==============\n");
    for (int j = 0; j < DEBUG_INST_TRACE_SIZE; j++) {
        if (j == ((retire_inst_pointer - 1) % DEBUG_INST_TRACE_SIZE)) {
            switch (retire_inst_type_queue[j]) {
                case RET_NORMAL:
                    printf("\033[0m\033[1;31mcommit inst [%x]: pc %010llx inst %08x wen %x dst %08x data %016llx \033[0m",
                               j, retire_inst_pc_queue[j], retire_inst_inst_queue[j], retire_inst_wen_queue[j] != 0, retire_inst_wdst_queue[j],
                               retire_inst_wdata_queue[j]);
                    break;
                case RET_EXC:
                    printf("\033[0m\033[1;31mexception   [%x]: pc %010llx inst %08x cause %016llx \033[0m",
                               j, retire_inst_pc_queue[j], retire_inst_inst_queue[j], retire_inst_wdata_queue[j]);
                    break;
                case RET_INT:
                    printf("\033[0m\033[1;31minterrupt   [%x]: pc %010llx inst %08x cause %016llx \033[0m",
                               j, retire_inst_pc_queue[j], retire_inst_inst_queue[j], retire_inst_wdata_queue[j]);
                    break;
            }
            printf_red("<-- ERROR\n");
        } else {
            switch (retire_inst_type_queue[j]) {
                case RET_NORMAL:
                    printf("commit inst [%x]: pc %010llx inst %08x wen %x dst %08x data %016llx \n",
                           j, retire_inst_pc_queue[j], retire_inst_inst_queue[j], retire_inst_wen_queue[j] != 0, retire_inst_wdst_queue[j],
                           retire_inst_wdata_queue[j]);
                    break;
                case RET_EXC:
                    printf("exception   [%x]: pc %010llx inst %08x cause %016llx \n",
                           j, retire_inst_pc_queue[j], retire_inst_inst_queue[j], retire_inst_wdata_queue[j]);
                    break;
                case RET_INT:
                    printf("interrupt   [%x]: pc %010llx inst %08x cause %016llx \n",
                           j, retire_inst_pc_queue[j], retire_inst_inst_queue[j], retire_inst_wdata_queue[j]);
                    break;
            }
        }
        if (!spike_invalid) {
            char inst_str[32];
            char dasm_result[64] = {0};
            sprintf(inst_str, "%08x", retire_inst_inst_queue[j]);
            spike_dasm(dasm_result, inst_str);
            printf("%s ", dasm_result);
        }
    }
    fflush(stdout);
}

DiffState::DiffState() {
}
