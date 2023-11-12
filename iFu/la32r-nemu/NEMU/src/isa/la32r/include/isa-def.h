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

#ifndef __ISA_LA32R_H__
#define __ISA_LA32R_H__

#include <common.h>
#include "../local-include/csr.h"

// reg
typedef struct {
  struct {
    rtlreg_t _32;
  } gpr[32];

  rtlreg_t crmd, prmd, euen, ecfg;
  rtlreg_t era, badv, eentry;
  rtlreg_t tlbidx, tlbehi, tlbelo0, tlbelo1;
  rtlreg_t asid, pgdl, pgdh;
  rtlreg_t save0, save1, save2, save3;
  rtlreg_t tid, tcfg, tval;//, ticlr;
  rtlreg_t llbctl, tlbrentry, dmw0, dmw1;
  rtlreg_t estat;
  vaddr_t idle_pc;

  rtlreg_t stable_counter_id;
  rtlreg_t stable_counter_lo;
  rtlreg_t stable_counter_hi;
  
  rtlreg_t ll_bit;  
  bool inst_idle;
  
  vaddr_t pc;
  bool INTR;

} la32r_CPU_state;

// decode
typedef struct {
  union {
    struct {
      uint32_t rd     :  5;
      uint32_t rj     :  5;
      uint32_t opcode :  22;
    } r2;     // ertn tlbxx
    struct {
      uint32_t rd     :  5;
      uint32_t rj     :  5;
      uint32_t rk     :  5;
      uint32_t opcode :  17;
    } r3;     //compute
    struct {
      uint32_t rd     : 5;
      uint32_t rj     : 5;
      uint32_t rk     : 5;
      uint32_t ra     : 5;
      uint32_t opcode : 12;
    } r4;     
    struct {
      uint32_t rd     : 5;
      uint32_t rj     : 5;
      // uint32_t i8     : 8;
      // uint32_t opcode : 14;
      uint32_t i5     : 5;
      uint32_t opcode : 17;
    } r2_i8;  //slli srli srai, actually only 5 bits imm used
    struct {
      uint32_t rd     : 5;
      uint32_t rj     : 5;
      int32_t i12     : 12;
      uint32_t opcode : 10;
    } r2_i12; //imm compute, load, store, cacop
    struct {
      uint32_t rd     : 5;
      uint32_t rj     : 5;
      int32_t i14     : 14;
      uint32_t opcode : 8;
    } r2_i14s; // llsc    
    struct {
      uint32_t rd     : 5;
      uint32_t rj     : 5;
      int32_t i16     : 16;
      uint32_t opcode : 6;
    } r2_i16; //jirl, branch
    struct {
      uint32_t i21_20_16   : 5;
      uint32_t rj          : 5;
      uint32_t i21_15_0    : 16;
      uint32_t opcode      : 6;
    } r1_i21; 
    struct {
      uint32_t rd          : 5;
      uint32_t i20         : 20;
      uint32_t opcode      : 7;
    } r1_i20; //lui12.w pcaddu12i.w
    struct {
      int32_t i26_25_16    : 10;
      uint32_t i26_15_0    : 16;
      uint32_t opcode      : 6;
    } i_26;   //b bl
    struct {
      uint32_t code        :15;
      uint32_t opcode      :17;
    } code_15; // syscall break idle

    uint32_t val;
  } instr;
} la32r_ISADecodeInfo;



#define isa_mmu_state() (((CRMD->da == 0) & (CRMD->pg == 1)) ? MMU_TRANSLATE : MMU_DIRECT)

#define isa_mmu_check(vaddr, len, type) isa_mmu_state()

#endif
