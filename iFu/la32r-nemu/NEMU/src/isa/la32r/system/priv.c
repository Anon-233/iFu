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

#include "../local-include/csr.h"
#include "../local-include/rtl.h"
#include "../local-include/intr.h"
#include "../local-include/mmu.h"
#include "csr_mask.h"
#include <cpu/difftest.h>
#include <cpu/cpu.h>
#include <stdlib.h>

rtlreg_t csr_array[4096] = {};

#define CSRS_EXIST(name, addr) csr_exist[addr] = 1;
static bool csr_exist[4096] = {};

#define CSRS_DEF(name, addr) \
  concat(name, _t)* const name = (concat(name, _t) *)&csr_array[addr];
MAP(CSRS, CSRS_DEF)

void init_csr() {
  MAP(CSRS, CSRS_EXIST)
};

static inline bool csr_is_legal(uint32_t addr) {
  // assert(addr < 4096);
  if(addr >= 4096){
    return false;
  }
  // CSR does not exist
  if(!csr_exist[addr]) {
#ifdef CONFIG_PANIC_ON_UNIMP_CSR
    panic("[NEMU] unimplemented CSR 0x%x", addr);
#endif
    return false;
  }

  return true;
}

static inline word_t* csr_decode(uint32_t addr) {
  assert(addr < 4096);
  return &csr_array[addr];
}

#define is_read(csr) (src == (void *)(csr))
#define is_write(csr) (dest == (void *)(csr))
/* if a csr has readonly bits, which means these bits will be set only 'by hardware',
 * use mask_bitset to csrwr/csrxchg this csr
 */
#define mask_bitset(old, mask, new) (((old) & ~(mask)) | ((new) & (mask)))

static inline word_t csr_read(word_t *src) {
  if(is_read(LLBCTL)){
    return (((*src) & 0xfffffffe) | cpu.ll_bit);
  }
  else if(is_read(PGD)){
    if((BADV->val) & 0x80000000)
        return ((PGDH->val));
    else    
        return ((PGDL->val));
  }
  return *src;
}

static inline void csr_write(word_t *dest, word_t src) {

  if(is_write(CRMD)){
      CRMD->val = mask_bitset(CRMD->val, CRMD_W_MASK, src);
  }
  else if(is_write(PRMD)){
      PRMD->val = mask_bitset(PRMD->val, PRMD_W_MASK, src);
  }
  else if(is_write(EUEN)){
      EUEN->val = mask_bitset(EUEN->val, EUEN_W_MASK, src);
  }
  else if(is_write(ECFG)){
      ECFG->val = mask_bitset(ECFG->val, ECFG_W_MASK, src);
  }
  else if(is_write(ESTAT)){
      ESTAT->val = mask_bitset(ESTAT->val, ESTAT_W_MASK, src);
  }
  else if(is_write(ERA) || is_write(BADV) || is_write(SAVE0) || 
          is_write(SAVE1) || is_write(SAVE2) || is_write(SAVE3) || 
          is_write(TID) || is_write(TCFG)){
      *dest = src;
  }
  else if(is_write(EENTRY)){
      EENTRY->val = mask_bitset(EENTRY->val, EENTRY_W_MASK, src);
  }
  else if(is_write(LLBCTL)){
      if((src & LLBCTL_WCLLB_MASK) != 0){
          cpu.ll_bit = 0;
      }
      LLBCTL->val = mask_bitset(LLBCTL->val, LLBCTL_W_MASK, src);
  }
  else if(is_write(TLBIDX)){
      TLBIDX->val = mask_bitset(TLBIDX->val, TLBIDX_W_MASK, src);
  }
  else if(is_write(TLBEHI)){
      TLBEHI->val = mask_bitset(TLBEHI->val, TLBEHI_W_MASK, src);
  }
  else if(is_write(TLBELO0) || is_write(TLBELO1)){
      *dest = mask_bitset(*dest, TLBELO_W_MASK, src);
  }
  else if(is_write(ASID)){
      ASID->val = mask_bitset(ASID->val, ASID_W_MASK, src);
  }
  else if(is_write(PGDL) || is_write(PGDH)){
      *dest = mask_bitset(*dest, PGDH_W_MASK, src);
  }
  else if(is_write(TLBRENTRY)){
      TLBRENTRY->val = mask_bitset(TLBRENTRY->val, TLBRENTRY_W_MASK, src);
  }
  else if(is_write(DMW0) || is_write(DMW1)){
      *dest = mask_bitset(*dest, DMW0_W_MASK, src);
  }
  else if(is_write(TICLR)){
      if((src & TICLR_CLR_MASK) != 0){
          //CLEAR TIMER INTR !!!
          ESTAT->is_2_12 &= 0x5ff;
      }
  }
  else if(is_write(CPUID) || is_write(TVAL)){
    //do nothing
  }
  else{
      panic("[NEMU] unimplemented CSR");
  }
}


word_t csrid_read(uint32_t csrid) {
  return csr_read(csr_decode(csrid));
}

static void csrrw(rtlreg_t *dest, const rtlreg_t *src, uint32_t csrid) {
  if (!csr_is_legal(csrid)) {
    // read illegal csr, return read result 0
    if (dest != NULL) { *dest = 0; }
    return;
  }
  word_t *csr = csr_decode(csrid);
  word_t tmp = (src != NULL ? *src : 0);
  if (dest != NULL) { *dest = csr_read(csr); }
  if (src != NULL) { csr_write(csr, tmp); }
}

static word_t priv_instr(uint32_t op, const rtlreg_t *src) {
  switch (op) {
    case PRIV_ERET: // ERTN
      CRMD->plv = PRMD->pplv;
      CRMD->ie  = PRMD->pie;
      if(ESTAT->ecode == 0x3f){
        CRMD->da = 0;
        CRMD->pg = 1;
      }
      return ERA->val;
    case PRIV_IDLE: // IDLE
      return cpu.idle_pc;   // cpu.pc is already snpc here.
    default: panic("Unsupported privilige operation = %d", op);
  }
  return 0;
}


void isa_hostcall(uint32_t id, rtlreg_t *dest, const rtlreg_t *src1,
    const rtlreg_t *src2, word_t imm) {
  word_t ret = 0;
  switch (id) {
    case HOSTCALL_CSR: 
      if(CRMD->plv == 0x3){
        // printf("PC: 0x%x [NEMU]: this is CSR inst but plv is %d, exception.\n",cpu.pc,CRMD->plv);
        longjmp_exception(EX_IPE);
      }else{
          csrrw(dest, src1, imm); 
      }
      return;
    case HOSTCALL_TRAP:  // break syscalls
      ret = raise_intr(imm, *src1); 
      break;
    case HOSTCALL_PRIV: 
      if(CRMD->plv == 0x3){
        // printf("PC: 0x%x [NEMU]: this is PRIV inst but plv is %d, exception.\n",cpu.pc,CRMD->plv);
        longjmp_exception(EX_IPE);
      }else{
          ret = priv_instr(imm, src1);
      }
      break;
    case HOSTCALL_TLB:
      if(CRMD->plv == 0x3){
        // printf("PC: 0x%x [NEMU]: this is TLB inst but plv is %d, exception.\n",cpu.pc,CRMD->plv);
        longjmp_exception(EX_IPE);
      }else{
        switch (imm) {
          case TLB_SRCH:
            tlbsrch();
            break;
          case TLB_RD:
            tlbrd();
            break;
          case TLB_WR:
            tlbwr();
            break;
          case TLB_FILL:
            tlbfill( MUXDEF(CONFIG_SHARE, tlbfill_index_diff, random()%CONFIG_TLB_ENTRIES) );
            break;
          default:
            break;
        }
      }
      break;
    default: panic("Unsupported hostcall ID = %d", id);
  }
  if (dest) *dest = ret;
}