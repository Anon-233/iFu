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
#include <difftest.h>
#include "../local-include/intr.h"
#include "../local-include/csr.h"
#include "../local-include/mmu.h"

/* copy from isa/riscv64 */

static void csr_prepare() {
  cpu.crmd = CRMD->val;
  cpu.prmd = PRMD->val;
  cpu.euen = EUEN->val;
  cpu.ecfg = ECFG->val;
  cpu.estat = ESTAT->val;
  cpu.era  = ERA->val;
  cpu.badv = BADV->val;
  cpu.eentry = EENTRY->val;
  cpu.tlbidx = TLBIDX->val;
  cpu.tlbehi = TLBEHI->val;
  cpu.tlbelo0 = TLBELO0->val;
  cpu.tlbelo1 = TLBELO1->val;
  cpu.asid = ASID->val;
  cpu.pgdl = PGDL->val;
  cpu.pgdh = PGDH->val;
  cpu.save0 = SAVE0->val;
  cpu.save1 = SAVE1->val;
  cpu.save2 = SAVE2->val;
  cpu.save3 = SAVE3->val;
  cpu.tid = TID->val;
  cpu.tcfg = TCFG->val;
  cpu.tval = TVAL->val;
  // cpu.ticlr = TICLR->val;
  cpu.llbctl = csrid_read(0x60); 
  cpu.tlbrentry = TLBRENTRY->val;
  cpu.dmw0 = DMW0->val;
  cpu.dmw1 = DMW1->val;
}

static void csr_writeback() {
  CRMD->val = cpu.crmd;
  PRMD->val = cpu.prmd;
  EUEN->val = cpu.euen;
  ECFG->val = cpu.ecfg;
  ESTAT->val = cpu.estat;
  ERA->val = cpu.era ;
  BADV->val = cpu.badv;
  EENTRY->val = cpu.eentry;
  TLBIDX->val = cpu.tlbidx;
  TLBEHI->val = cpu.tlbehi;
  TLBELO0->val = cpu.tlbelo0;
  TLBELO1->val = cpu.tlbelo1;
  ASID->val = cpu.asid;
  PGDL->val = cpu.pgdl;
  PGDH->val = cpu.pgdh;
  SAVE0->val = cpu.save0;
  SAVE1->val = cpu.save1;
  SAVE2->val = cpu.save2;
  SAVE3->val = cpu.save3;
  TID->val = cpu.tid;
  TCFG->val = cpu.tcfg;
  TVAL->val = cpu.tval;
  // TICLR->val = cpu.ticlr;
  LLBCTL->val = cpu.llbctl;
  TLBRENTRY->val = cpu.tlbrentry;
  DMW0->val = cpu.dmw0;
  DMW1->val = cpu.dmw1;

  cpu.ll_bit = (cpu.llbctl & 0x1);
}

void isa_difftest_regcpy(void *dut, bool direction, bool do_csr) {
  if (direction == DIFFTEST_TO_REF) {
    memcpy(&cpu, dut, DIFFTEST_REG_SIZE);
    if(do_csr)
      csr_writeback();
  } else {
    if(do_csr)
      csr_prepare();
    memcpy(dut, &cpu, DIFFTEST_REG_SIZE);
  }
}

void isa_difftest_csrcpy(void *dut, bool direction) {
  if (direction == DIFFTEST_TO_REF) {
    memcpy(csr_array, dut, 4096 * sizeof(rtlreg_t));
  } else {
    memcpy(dut, csr_array, 4096 * sizeof(rtlreg_t));
  }
}

void isa_difftest_raise_intr(word_t NO) {  
  /* here we use this func only to handle TIME INTR and HW INTR
   * that means we need to set ESTAT, instead of call raise_intr()
   */

  // cpu.pc = raise_intr(NO, cpu.pc);  
  ESTAT->is_2_12 = NO;
  // isa_query_intr();
  
}

void isa_difftest_timercpy(void *dut) {
  struct la32_timer* ms = (struct la32_timer*)dut;
  cpu.stable_counter_id = ms->counter_id;
  cpu.stable_counter_lo = ms->stable_counter_l;
  cpu.stable_counter_hi = ms->stable_counter_h;

  TVAL->val = ms->time_val;
}

void isa_difftest_tlbcpy(uint32_t index, void *dut){
  assert(index <= CONFIG_TLB_ENTRIES);
  
  struct tlb_struct* tlb_temp = (struct tlb_struct*) dut;
  tlb[index].hi = tlb_temp->hi;
  tlb[index].lo[0] = tlb_temp->lo[0];
  tlb[index].lo[1] = tlb_temp->lo[1];
}


void isa_difftest_guided_exec(void * guide) {
  return ;
}


void isa_difftest_uarchstatus_cpy(void *dut, bool direction) {
  return ;
}

uint32_t tlbfill_index_diff;

void isa_difftest_tlbfill_index_set(uint32_t index) {
  tlbfill_index_diff = index;
}

void isa_difftest_estat_sync(uint32_t index, uint32_t mask) {
  ESTAT->val = (ESTAT->val & ~mask) | (index & mask);
  // ESTAT->val = index;
}

int isa_difftest_cosim_end() {
  return cosim_end;
}
