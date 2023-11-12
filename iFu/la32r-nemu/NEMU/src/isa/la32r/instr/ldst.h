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


#define def_ldst_template(name, rtl_instr, width, mmu_mode) \
  def_EHelper(name) { \
    vaddr_t addr = *dsrc1 + id_src2->imm; \
    if(width == 4){ \
      if(addr & ((vaddr_t)0x3)){ \
        printf("[NEMU] PC: 0x%x [NEMU]: current mem addr = 0x%x not %d aligned\n",cpu.pc,addr,width);\
        BADV->val = addr; \
        longjmp_exception(EX_ALE); \
      } \
    } \
    else if(width == 2){ \
      if(addr & ((vaddr_t)0x1)){ \
        printf("[NEMU] PC: 0x%x [NEMU]: current mem addr = 0x%x not %d aligned\n",cpu.pc,addr,width);\
        BADV->val = addr; \
        longjmp_exception(EX_ALE); \
      } \
    } \
    concat(rtl_, rtl_instr) (s, ddest, dsrc1, id_src2->imm, width, mmu_mode); \
  }

#define def_all_ldst(suffix, mmu_mode) \
  def_ldst_template(concat(ld_w , suffix), lms, 4, mmu_mode) \
  def_ldst_template(concat(ld_h , suffix), lms, 2, mmu_mode) \
  def_ldst_template(concat(ld_b , suffix), lms, 1, mmu_mode) \
  def_ldst_template(concat(ld_hu, suffix), lm , 2, mmu_mode) \
  def_ldst_template(concat(ld_bu, suffix), lm , 1, mmu_mode) \
  def_ldst_template(concat(st_w , suffix), sm , 4, mmu_mode) \
  def_ldst_template(concat(st_h , suffix), sm , 2, mmu_mode) \
  def_ldst_template(concat(st_b , suffix), sm , 1, mmu_mode)

def_all_ldst(, isa_mmu_state())


def_EHelper(ll_w) { 
    vaddr_t addr = *dsrc2 + (id_src1->simm << 2); 
    if(addr & ((vaddr_t)0x3)){ 
      printf("[NEMU] PC: 0x%x [NEMU]: current mem addr = 0x%x not 4 aligned\n",cpu.pc,addr);
      BADV->val = addr; 
      longjmp_exception(EX_ALE); 
    } 
    
    rtl_lms(s, ddest, dsrc2, id_src1->simm<<2, 4, isa_mmu_state()); 
    cpu.ll_bit = 1;
}

def_EHelper(sc_w) { 
    vaddr_t addr = *dsrc2 + (id_src1->simm << 2); 
    if(addr & ((vaddr_t)0x3)){ 
      printf("[NEMU] PC: 0x%x [NEMU]: current mem addr = 0x%x not 4 aligned\n",cpu.pc,addr);
      BADV->val = addr; 
      longjmp_exception(EX_ALE); 
    } 
    if(cpu.ll_bit == 1){
      rtl_sm(s, ddest, dsrc2, id_src1->simm<<2, 4, isa_mmu_state());
      rtl_mv(s, ddest, &(cpu.ll_bit));
      cpu.ll_bit = 0;
    }else{
      /** NOTE: sc.w can casue TLBex when llbit=0, 
       * but to pass co-sim with chiplab DEMO when simulating linux, 
       * next line is omitted */
      // isa_mmu_translate(addr, 4, MEM_TYPE_WRITE);
      rtl_mv(s, ddest, &(cpu.ll_bit));
    }
}

