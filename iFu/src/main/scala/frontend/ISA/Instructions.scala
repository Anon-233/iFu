package frontend.ISA

import chisel3.util.BitPat
//变量名要大写,"_"要去掉
object Instructions {
  def ADDW            = BitPat("b00000000000100000???????????????")    //
  def SUBW            = BitPat("b00000000000100010???????????????")
  def SLT             = BitPat("b00000000000100100???????????????")
  def SLTU            = BitPat("b00000000000100101???????????????")
  def NOR             = BitPat("b00000000000101000???????????????")
  def AND             = BitPat("b00000000000101001???????????????")
  def OR              = BitPat("b00000000000101010???????????????")
  def XOR
  def lu12i_w
  def addi_w
  def slti
  def sltui
  def pcaddi
  def pcaddu12i
  def andn
  //One One-Two之间：xd
  def orn
  def andi
  def ori
  def xori
  def mul_w
  def mulh_w
  def mulh_wu
  def div_w
  def mod_w
  def div_wu
  def mod_wu
  def slli_w
  def srli_w
  def srai_w
  def sll_w
  //Two-Three lxx
  def srl_w
  def sra_w
  def jirl
  def b
  def bl
  def beq
  def bne
  def blt
  def bge
  def bltu
  def bgeu
  def ll_w
  def sc_w
  def ld_b
  def ld_bu
  //Three-Four lsy
  def ld_h
  def ld_hu
  def ld_w
  def st_b
  def st_h
  def st_w
  def syscall
  def break
  def csrrd
  def csrwr
  def csrxchg
  def ertn
  def rdcntid_w
  def rdcntvl_w
  def rdcntvh_w
  //Four
  def idle
  def tlbsrch
  def tlbrd
  def tlbwr
  def tlbfill
  def invtlb
  def cacop
  def preld
  def dbar
  def ibar

}
