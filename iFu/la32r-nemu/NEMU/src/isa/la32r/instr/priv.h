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

#include "../local-include/intr.h"
#include "../local-include/csr.h"
#include "../local-include/mmu.h"

def_EHelper(syscall) {
  // printf("PC: 0x%x [DEBUG]: this is syscall\n",cpu.pc);
  rtl_li(s, s1, s->pc);
  rtl_hostcall(s, HOSTCALL_TRAP, s0, s1, NULL, EX_SYS);
  rtl_jr(s, s0);

  if(id_src1->imm == 0x11){
    printf("[NEMU] This is syscall 0x11, end\n");
    cosim_end = 1;

    // end
    save_globals(s);
    rtl_hostcall(s, HOSTCALL_EXIT, NULL, &cpu.gpr[4]._32, NULL, 0); // gpr[4] is $v0
    longjmp_exec(NEMU_EXEC_END);
  }
}

def_EHelper(break) {
  // printf("PC: 0x%x [DEBUG]: this is break\n",cpu.pc);  
  rtl_li(s, s1, s->pc);
  rtl_hostcall(s, HOSTCALL_TRAP, s0, s1, NULL, EX_BRK);
  rtl_jr(s, s0);  
}

def_EHelper(ertn) {
  // printf("PC: 0x%x [DEBUG]: this is ertn\n",cpu.pc);  
  rtl_hostcall(s, HOSTCALL_PRIV, s0, NULL, NULL, PRIV_ERET);  
  if(LLBCTL->klo == 1){
    LLBCTL->klo = 0;
  }else{
    cpu.ll_bit = 0;
  }
  rtl_jr(s, s0); 
}

def_EHelper(idle) {
  // printf("PC: 0x%x [DEBUG]: this is idle\n",cpu.pc);  
  cpu.inst_idle = 1;
  rtl_hostcall(s, HOSTCALL_PRIV, s0, NULL, NULL, PRIV_IDLE);  
  rtl_jr(s, s0); 
}

def_EHelper(tlbsrch) {
  // printf("PC: 0x%x [DEBUG]: this is tlbsrch\n",cpu.pc);  
  rtl_hostcall(s, HOSTCALL_TLB, NULL, NULL, NULL, TLB_SRCH); 
}

def_EHelper(tlbrd) {
  // printf("PC: 0x%x [DEBUG]: this is tlbrd\n",cpu.pc);  
  rtl_hostcall(s, HOSTCALL_TLB, NULL, NULL, NULL, TLB_RD); 
}

def_EHelper(tlbwr) {
  // printf("PC: 0x%x [DEBUG]: this is tlbwr\n",cpu.pc);  
  rtl_hostcall(s, HOSTCALL_TLB, NULL, NULL, NULL, TLB_WR); 
}

def_EHelper(tlbfill) {
  // printf("PC: 0x%x [DEBUG]: this is tlbfill\n",cpu.pc);  
  rtl_hostcall(s, HOSTCALL_TLB, NULL, NULL, NULL, TLB_FILL); 
}

def_EHelper(invtlb) {
  // printf("PC: 0x%x [DEBUG]: this is invtlb\n",cpu.pc);  
  if(CRMD->plv == 0x3){
    // printf("PC: 0x%x [NEMU]: this is TLB inst but plv is %d, exception.\n",cpu.pc,CRMD->plv);
    longjmp_exception(EX_IPE);
  }else{
    invtlb(id_dest->imm, *dsrc2, *dsrc1);
  }
}