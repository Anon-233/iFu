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

#include <isa.h>
#include "local-include/reg.h"
#include "local-include/csr.h"

const char *regsl[] = {
  "r0", "ra", "tp", "sp", "a0", "a1", "a2", "a3",
  "a4", "a5", "a6", "a7", "t0", "t1", "t2", "t3",
  "t4", "t5", "t6", "t7", "t8", " x", "fp", "s0",
  "s1", "s2", "s3", "s4", "s5", "s6", "s7", "s8"
};

void isa_reg_display() {
  int i;
  for (i = 0; i < 32; i ++) {
    printf("%s(r%2d): 0x%08x ", regsl[i], i, cpu.gpr[i]._32);
    if (i % 4 == 3) printf("\n");
  }
  printf("pc: 0x%08x\n", cpu.pc);
  if(isa_mmu_state() == MMU_DIRECT){
    printf("Current MMU state is: MMU_DIRECT\n");
  }else{
    printf("Current MMU state is: MMU_TRANSLATE\n");
  }
  printf("CRMD: 0x%08x,    PRMD: 0x%08x,   EUEN: 0x%08x\n", csr_array[0], csr_array[1], csr_array[2]);
  printf("ECFG: 0x%08x,   ESTAT: 0x%08x,    ERA: 0x%08x\n", csr_array[4], csr_array[5], csr_array[6]);  
  printf("BADV: 0x%08x,  EENTRY: 0x%08x, LLBCTL: 0x%08x\n", csr_array[7], csr_array[12], csr_array[96]);    
  printf("cpu.ll_bit: %d\n",cpu.ll_bit);
  printf("INDEX: 0x%08x, TLBEHI: 0x%08x, TLBELO0: 0x%08x, TLBELO1: 0x%08x\n", csr_array[0x10], csr_array[0x11], csr_array[0x12], csr_array[0x13]);
  printf("ASID: 0x%08x, TLBRENTRY: 0x%08x, DMW0: 0x%08x, DMW1: 0x%08x\n", csr_array[0x18], csr_array[0x88], csr_array[0x180], csr_array[0x181]);
  printf("*******************************************************************************\n");
  fflush(NULL);
}

word_t isa_reg_str2val(const char *s, bool *success) {
  int i;
  *success = true;
  for (i = 0; i < 32; i ++) {
    if (strcmp(regsl[i], s) == 0) return reg_l(i);
  }

  if (strcmp("pc", s) == 0) return cpu.pc;

  *success = false;
  return 0;
}
