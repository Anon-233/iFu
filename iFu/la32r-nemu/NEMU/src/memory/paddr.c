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
#include <memory/host.h>
#include <memory/paddr.h>
#include <device/mmio.h>
#include <stdlib.h>
#include <time.h>
#include <cpu/cpu.h>
#include "../local-include/intr.h"

#ifdef CONFIG_USE_MMAP
#include <sys/mman.h>
//static const uint8_t *pmem = (uint8_t *)0x100000000ul;
static const uint8_t *pmem = NULL;
#else
static uint8_t pmem[CONFIG_MSIZE] PG_ALIGN = {};
#endif
#define HOST_PMEM_OFFSET (uint8_t *)(pmem - CONFIG_MBASE)

uint8_t* guest_to_host(paddr_t paddr) { return paddr + HOST_PMEM_OFFSET; }
paddr_t host_to_guest(uint8_t *haddr) { return haddr - HOST_PMEM_OFFSET; }

static inline word_t pmem_read(paddr_t addr, int len) {
  return host_read(guest_to_host(addr), len);
}

static inline void pmem_write(paddr_t addr, int len, word_t data) {
#ifdef CONFIG_DIFFTEST_STORE_COMMIT
  store_commit_queue_push(addr, data, len);
#endif
  host_write(guest_to_host(addr), len, data);
}

void init_mem() {
#ifdef CONFIG_USE_MMAP
  void *ret = mmap((void *)pmem, CONFIG_MSIZE, PROT_READ | PROT_WRITE,
      MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
  if (ret == MAP_FAILED) {
    perror("mmap");
    assert(0);
  }
  pmem = ret;
#endif

#ifdef CONFIG_DIFFTEST_STORE_COMMIT
  for (int i = 0; i < STORE_QUEUE_SIZE; i++) {
    store_commit_queue[i].valid = 0;
  }
#endif

#ifdef CONFIG_MEM_RANDOM
  srand(time(0));
  uint32_t *p = (uint32_t *)pmem;
  int i;
  for (i = 0; i < (int) (CONFIG_MSIZE / sizeof(p[0])); i ++) {
    p[i] = rand();
  }
#endif
}

/* Memory accessing interfaces */

word_t paddr_read(paddr_t addr, int len) {
#ifndef CONFIG_SHARE
  if (likely(in_pmem(addr))) return pmem_read(addr, len);
  else return mmio_read(addr, len);
#else
  if (likely(in_pmem(addr))) return pmem_read(addr, len);
  else {
    printf("[NEMU] ERROR: invalid mem read from paddr " FMT_PADDR ", NEMU raise illegal inst exception\n", addr);
  }
  return 0;
#endif
}

void paddr_write(paddr_t addr, int len, word_t data) {
#ifndef CONFIG_SHARE
  if (likely(in_pmem(addr))) pmem_write(addr, len, data);
  else mmio_write(addr, len, data);
#else
  if (likely(in_pmem(addr))) return pmem_write(addr, len, data);
  else {
    printf("[NEMU] ERROR: invalid mem write to paddr " FMT_PADDR ", NEMU raise illegal inst exception\n", addr);
    return;
  } 
#endif
}


#ifdef CONFIG_DIFFTEST_STORE_COMMIT
store_commit_t store_commit_queue[STORE_QUEUE_SIZE];
static uint64_t head = 0, tail = 0;

void store_commit_queue_push(uint64_t addr, uint64_t data, int len) {
  static int overflow = 0;
  if (overflow) {
    return;
  }
  store_commit_t *commit = store_commit_queue + tail;
  if(commit->valid){ // store commit queue overflow
    overflow = 1;
    printf("[NEMU] [WARNING] difftest store queue overflow, difftest store commit disabled\n");
  };
  uint64_t offset = addr % 4ULL;
  // commit->addr = addr - offset;
  commit->addr = addr;
  commit->valid = 1;
  commit->data = data;

  // printf("addr = 0x%x, data = 0x%x, len = %d\n", addr, data, len);

  switch (len) {
    case 1:
      // commit->data = data & 0x000000ff;
      commit->data = (data & 0xffULL) << (offset << 3);
      // commit->mask = 0x1 << offset;
      break;
    case 2:
      // commit->data = data & 0x0000ffff;
      commit->data = (data & 0xffffULL) << (offset << 3);
      // commit->mask = 0x3 << offset;
      break;
    case 4:
      commit->data = data;
      // commit->data = (data & 0xffffffffULL) << (offset << 3);
      // commit->mask = 0xf << offset;
      break;
    // case 8:
    //   commit->data = data;
    //   commit->mask = 0xff;
    //   break;
    default:
      assert(0);
  }
  tail = (tail + 1) % STORE_QUEUE_SIZE;
}

store_commit_t *store_commit_queue_pop() {
  store_commit_t *result = store_commit_queue + head;
  if (!result->valid) {
    return NULL;
  }
  result->valid = 0;
  head = (head + 1) % STORE_QUEUE_SIZE;
  return result;
}

int check_store_commit(uint64_t addr, uint64_t data) {
  // *addr = *addr - (*addr % 0x8ULL);
  store_commit_t *commit = store_commit_queue_pop();
  int result = 0;

  if (!commit) {
    // printf("head = %d, tail = %d\n", head, tail);
    printf("NEMU does not commit any store instruction.\n");
    result = 1;
  }
  else if (addr != commit->addr || data != commit->data) {
    // *addr = commit->addr;
    // *data = commit->data;
    // *mask = commit->mask;
    printf("ref different at pc = 0x%08x, paddr = 0x%lx, data = 0x%lx\n", cpu.idle_pc, commit->addr, commit->data);
    fflush(NULL);

    result = 1;
  }
  return result;
}

#endif
