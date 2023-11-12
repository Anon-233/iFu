/***************************************************************************************
* Copyright (c) 2014-2021 Zihao Yu, Nanjing University
* Copyright (c) 2020-2021 Institute of Computing Technology, Chinese Academy of Sciences
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
#include <cpu/cpu.h>
#include <difftest.h>

#ifdef CONFIG_LARGE_COPY
static void nemu_large_memcpy(void *dest, void *src, size_t n) {
  uint64_t *_dest = (uint64_t *)dest;
  uint64_t *_src  = (uint64_t *)src;
  while (n >= sizeof(uint64_t)) {
    if (*_src != 0) {
      *_dest = *_src;
    }
    _dest++;
    _src++;
    n -= sizeof(uint64_t);
  }
  if (n > 0) {
    uint8_t *dest8 = (uint8_t *)_dest;
    uint8_t *src8  = (uint8_t *)_src;
    while (n > 0) {
      *dest8 = *src8;
      dest8++;
      src8++;
      n--;
    }
  }
}
#endif

void difftest_memcpy(paddr_t nemu_addr, void *dut_buf, size_t n, bool direction) {
#ifdef CONFIG_LARGE_COPY
  if (direction == DIFFTEST_TO_REF) nemu_large_memcpy(guest_to_host(nemu_addr), dut_buf, n);
  else nemu_large_memcpy(dut_buf, guest_to_host(nemu_addr), n);
#else
  if (direction == DIFFTEST_TO_REF) memcpy(guest_to_host(nemu_addr), dut_buf, n);
  else memcpy(dut_buf, guest_to_host(nemu_addr), n);
#endif
}

void difftest_regcpy(void *dut, bool direction, bool do_csr) {
  isa_difftest_regcpy(dut, direction, do_csr);
}

void difftest_timercpy(void *dut) {
  isa_difftest_timercpy(dut);
}

void difftest_estat_sync(uint32_t index, uint32_t mask) {
  isa_difftest_estat_sync(index, mask);
}

void difftest_tlbcpy(uint32_t index, void *dut) {
  isa_difftest_tlbcpy(index, dut);
}

void difftest_tlbfill_index_set(uint32_t index) {
  isa_difftest_tlbfill_index_set(index);
}

//#ifdef RV64_FULL_DIFF
void difftest_csrcpy(void *dut, bool direction) {
  isa_difftest_csrcpy(dut, direction);
}

void difftest_uarchstatus_cpy(void *dut, bool direction) {
  isa_difftest_uarchstatus_cpy(dut, direction);
}

int difftest_store_commit(uint64_t saddr, uint64_t sdata) {
#ifdef CONFIG_DIFFTEST_STORE_COMMIT
  return check_store_commit(saddr, sdata);
#else
  return 0;
#endif
}
//#endif

void difftest_exec(uint64_t n) {
  cpu_exec(n);
}

//#ifdef CONFIG_GUIDED_EXEC
void difftest_guided_exec(void * guide) {
  isa_difftest_guided_exec(guide);
}
//#endif

void difftest_raise_intr(word_t NO) {
  isa_difftest_raise_intr(NO);
}

int difftest_cosim_end() {
  return isa_difftest_cosim_end();
}



void difftest_init() {
  init_mem();

  /* Perform ISA dependent initialization. */
  init_isa();
  /* create dummy address space for serial */
  //add_mmio_map("difftest.serial", 0xa10003f8, new_space(8), 8, NULL);
}

#ifdef CONFIG_MULTICORE_DIFF
uint8_t *golden_pmem = NULL;

void difftest_set_mhartid(int n) {
  isa_difftest_set_mhartid(n);
}

void difftest_put_gmaddr(uint8_t* ptr) {
  golden_pmem = ptr;
}

#endif

