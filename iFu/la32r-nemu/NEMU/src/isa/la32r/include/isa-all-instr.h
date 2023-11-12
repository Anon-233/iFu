/***************************************************************************************
* Copyright (c) 2021-2022 Weitong Wang, University of Chinese Academy of Sciences
*
* NEMU is licensed under Mulan PSL v2.
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

#include <cpu/decode.h>
#include "../local-include/rtl.h"


#define INSTR_NULLARY(f) \
  f(inv) f(nemu_trap) f(print_led) f(ertn) f(tlbsrch) f(tlbrd) f(tlbwr) f(tlbfill)
#define INSTR_UNARY(f) \
  f(syscall) f(break) f(idle) f(dbar) f(ibar) f(rdcntvl_w) f(rdcntvh_w) f(rdcntid_w)
#define INSTR_BINARY(f) \
  f(lu12i_w) f(pcaddu12i) \
  f(csrrd) f(csrwr) f(b) f(bl) 
  
#define INSTR_TERNARY(f) \
  f(add_w) f(addi_w) f(sub_w) f(slt) f(sltu) f(slti) f(sltui) f(xor) f(nor) f(and) f(or) \
  f(xori) f(ori) f(andi) f(mul_w) f(mulh_w) f(mulh_wu) f(div_w) f(div_wu) f(mod_w) f(mod_wu) \
  f(sll_w) f(srl_w) f(sra_w) f(slli_w) f(srli_w) f(srai_w) \
  f(beq) f(bne) f(blt) f(bge) f(bltu) f(bgeu) f(jirl) \
  f(preld) f(ld_b) f(ld_h) f(ld_w) f(ld_bu) f(ld_hu) f(st_b) f(st_h) f(st_w) \
  f(csrxchg) f(cacop) f(ll_w) f(sc_w) f(invtlb)
def_all_EXEC_ID();

