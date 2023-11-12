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
#include <memory/paddr.h>
#include "local-include/csr.h"
#include "local-include/mmu.h"
#include "local-include/intr.h"

//load some inst for test
static const uint32_t img [] = {
0x28000000,
0x20000000,
0x2c000000,
0x80000000 // 	nemu_trap

};

static void restart() {
  /* Set the initial program counter. */
  cpu.pc = 0x1c000000;

  /* The zero register is always 0. */
  cpu.gpr[0]._32 = 0;
}

int cosim_end;

void init_isa() {
  cosim_end = 0;
  printf("[NEMU] ####### INIT HERE ########\n");
  printf("[NEMU] TLB_ENTRY = %d\n",CONFIG_TLB_ENTRIES);
  printf("[NEMU] PALEN = %d\n",CONFIG_PALEN);
  
  init_csr();

  CRMD->plv  = 0;
  CRMD->ie   = 0;
  CRMD->da   = 1;
  CRMD->pg   = 0;
  CRMD->datf = 0;
  CRMD->datm = 0;
  EUEN->fpe = 0;
  ECFG->lie  = 0;
  ESTAT->is_01 = 0;
  TCFG->en   = 0;
  LLBCTL->klo = 0;
  DMW0->plv0 = 0;
  DMW0->plv3 = 0;
  DMW1->plv0 = 0;
  DMW1->plv3 = 0;

  CPUID->coreid = 0;
  TID->val = 0;

  cpu.ll_bit = 0;
  cpu.inst_idle = 0;
  ASID->asidbits = 10;

  /* Load built-in image. */
  memcpy(guest_to_host(0x1c000000), img, sizeof(img));

  /* Initialize this virtual computer system. */
  restart();

  init_mmu();

}