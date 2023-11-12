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

#include <stdlib.h>
#include <isa.h>
#include <cpu/cpu.h>
#include <memory/paddr.h>
#include <memory/vaddr.h>
#include "../local-include/csr.h"
#include "../local-include/intr.h"
#include "../local-include/mmu.h"

struct tlb_struct tlb [CONFIG_TLB_ENTRIES];
int last_hit_index [2] = {0,1}; // need be two different num
int last_hit_replace = 0;

void init_mmu() {
  int i;
  for (i = 0; i < CONFIG_TLB_ENTRIES; i ++) {
    tlb[i].hi.E = tlb[i].lo[0].V = tlb[i].lo[1].V = 0;
  }
}

static inline void update_tlb(uint32_t idx) {
  tlb[idx].hi.PS = TLBIDX->ps;
  tlb[idx].hi.VPPN = TLBEHI->vppn;
  tlb[idx].hi.ASID = ASID->asid;

  tlb[idx].lo[0].V = TLBELO0->v;
  tlb[idx].lo[0].D = TLBELO0->d;
  tlb[idx].lo[0].PLV = TLBELO0->plv;
  tlb[idx].lo[0].MAT = TLBELO0->mat;
  tlb[idx].lo[0].PPN = TLBELO0->ppn;

  tlb[idx].lo[1].V = TLBELO1->v;
  tlb[idx].lo[1].D = TLBELO1->d;
  tlb[idx].lo[1].PLV = TLBELO1->plv;
  tlb[idx].lo[1].MAT = TLBELO1->mat;  
  tlb[idx].lo[1].PPN = TLBELO1->ppn;

  tlb[idx].hi.G = TLBELO0->g & TLBELO1->g;
  if(ESTAT->ecode != 0x3f){
    tlb[idx].hi.E = ~(TLBIDX->ne);
  }else{
    tlb[idx].hi.E = 1;
  }
}

void tlbwr(){
  update_tlb(TLBIDX->index);
}

void tlbfill(uint32_t idx){
  update_tlb(idx);
}

int tlbsrch(){
  int i = 0;
  int find = 0;
  for(i = 0; i < CONFIG_TLB_ENTRIES; i ++ ){
    if(tlb[i].hi.E){
      if((tlb[i].hi.G == 1) || (ASID->asid == tlb[i].hi.ASID)){
        if(tlb[i].hi.PS == 12){
          if(TLBEHI->vppn == tlb[i].hi.VPPN){
            TLBIDX->index = i;
            TLBIDX->ne = 0;
            find ++;
          }
        }
        else if(tlb[i].hi.PS == 21){
          if((TLBEHI->vppn >> 9) == (tlb[i].hi.VPPN >> 9)){
            TLBIDX->index = i;
            TLBIDX->ne = 0;
            find ++;
          }        
        }
      }
    }
  }
  if(find == 0)
    TLBIDX->ne = 1;
  if(find > 1){
    printf("[NEMU] ERROR: multiple tlb entries searched, please check tlb\n");
    exit(1);
  }

  return find;
}

void tlbrd(){
  if(tlb[TLBIDX->index].hi.E){
    TLBEHI->vppn = tlb[TLBIDX->index].hi.VPPN;
    TLBIDX->ps = tlb[TLBIDX->index].hi.PS;
    ASID->asid = tlb[TLBIDX->index].hi.ASID;

    TLBELO0->g = TLBELO1->g = tlb[TLBIDX->index].hi.G;
    TLBELO0->v = tlb[TLBIDX->index].lo[0].V;
    TLBELO0->d = tlb[TLBIDX->index].lo[0].D;
    TLBELO0->plv = tlb[TLBIDX->index].lo[0].PLV;
    TLBELO0->mat = tlb[TLBIDX->index].lo[0].MAT;
    TLBELO0->ppn = tlb[TLBIDX->index].lo[0].PPN;

    TLBELO1->v = tlb[TLBIDX->index].lo[1].V;
    TLBELO1->d = tlb[TLBIDX->index].lo[1].D;
    TLBELO1->plv = tlb[TLBIDX->index].lo[1].PLV;
    TLBELO1->mat = tlb[TLBIDX->index].lo[1].MAT;
    TLBELO1->ppn = tlb[TLBIDX->index].lo[1].PPN;    
  }else{
    TLBEHI->vppn = 0;//tlb[TLBIDX->index].hi.VPPN;
    TLBIDX->ps = 0;//tlb[TLBIDX->index].hi.PS;
    ASID->asid = 0;//tlb[TLBIDX->index].hi.ASID;

    TLBELO0->g = 0;//TLBELO1->g = tlb[TLBIDX->index].hi.G;
    TLBELO0->v = 0;//tlb[TLBIDX->index].lo[0].V;
    TLBELO0->d = 0;//tlb[TLBIDX->index].lo[0].D;
    TLBELO0->plv = 0;//tlb[TLBIDX->index].lo[0].PLV;
    TLBELO0->mat = 0;//tlb[TLBIDX->index].lo[0].MAT;
    TLBELO0->ppn = 0;//tlb[TLBIDX->index].lo[0].PPN;

    TLBELO1->g = 0;
    TLBELO1->v = 0;//tlb[TLBIDX->index].lo[1].V;
    TLBELO1->d = 0;//tlb[TLBIDX->index].lo[1].D;
    TLBELO1->plv = 0;//tlb[TLBIDX->index].lo[1].PLV;
    TLBELO1->mat = 0;//tlb[TLBIDX->index].lo[1].MAT;
    TLBELO1->ppn = 0;//tlb[TLBIDX->index].lo[1].PPN;       
  }
  TLBIDX->ne = ~(tlb[TLBIDX->index].hi.E);
}

void invtlb(uint32_t op, uint32_t asid, uint32_t va){
  int i = 0;
  switch (op)
  {
  case 0x0:
  case 0x1:
    for(i=0; i<CONFIG_TLB_ENTRIES; i++){
      tlb[i].hi.E = 0;
    }
    break;
  case 0x2:
    for(i=0; i<CONFIG_TLB_ENTRIES; i++){
      if(tlb[i].hi.G == 1)
        tlb[i].hi.E = 0;
    }
    break;
  case 0x3:
    for(i=0; i<CONFIG_TLB_ENTRIES; i++){
      if(tlb[i].hi.G == 0)
        tlb[i].hi.E = 0;
    }
    break;
  case 0x4:
    for(i=0; i<CONFIG_TLB_ENTRIES; i++){
      if((tlb[i].hi.G == 0) && (tlb[i].hi.ASID == asid))
        tlb[i].hi.E = 0;
    }
    break;
  case 0x5:
    for(i=0; i<CONFIG_TLB_ENTRIES; i++){
      if((tlb[i].hi.G == 0) && (tlb[i].hi.ASID == asid)){
        if(tlb[i].hi.PS == 12){
          if(tlb[i].hi.VPPN == (va >> 13)){
            tlb[i].hi.E = 0;
          }
        }else if(tlb[i].hi.PS == 21){
          if((tlb[i].hi.VPPN >> 9) == (va >> 22)){
            tlb[i].hi.E = 0;
          }
        }
      }
    }
    break;  
  case 0x6:
    for(i=0; i<CONFIG_TLB_ENTRIES; i++){
      if((tlb[i].hi.G == 1) || tlb[i].hi.ASID == asid){
        if(tlb[i].hi.PS == 12){
          if(tlb[i].hi.VPPN == (va >> 13)){
            tlb[i].hi.E = 0;
          }
        }else if(tlb[i].hi.PS == 21){
          if((tlb[i].hi.VPPN >> 9) == (va >> 22)){
            tlb[i].hi.E = 0;
          }
        }
      }
    }
    break;
  default:
    printf("[NEMU]: Unknown op 0x%x for INVTLB, exception INE will occur.\n",op);
    longjmp_exception(EX_INE); 
    break;
  }
}

// va -> pa
paddr_t isa_mmu_translate(vaddr_t vaddr, int len, int type) {
  int match_dmw0 = 0;
  int match_dmw1 = 0;
  int match_tlb = 0; int matched_tlb_index = 0; int do_lru=0;
  int even_or_odd = 0; // 1:chose odd page1  0:chose even page0
  if(isa_mmu_state() == MMU_DIRECT){
    return vaddr;  
  }else if(isa_mmu_state() == MMU_TRANSLATE){
    if((((DMW0->plv0 == 1) && (CRMD->plv == 0)) || ((DMW0->plv3 == 1) && (CRMD->plv == 3))) && ((vaddr >> 29) == DMW0->vseg))
      match_dmw0 = 1;
    if((((DMW1->plv0 == 1) && (CRMD->plv == 0)) || ((DMW1->plv3 == 1) && (CRMD->plv == 3))) && ((vaddr >> 29) == DMW1->vseg))
      match_dmw1 = 1;    

    if(match_dmw0 & match_dmw1){
      printf("[NEMU] WARNING: both DMW reg matched.\n");
      exit(1);
    }else if(match_dmw0){
      return (((DMW0->pseg)<<29) | (vaddr & 0x1fffffff));
    }else if(match_dmw1){
      return (((DMW1->pseg)<<29) | (vaddr & 0x1fffffff));
    }else{     // DMW reg not matched, use tlb

      int i = 0;

      for(i = 0; i<2; i++){
        if((tlb[last_hit_index[i]].hi.E == 1) && ((tlb[last_hit_index[i]].hi.G == 1) || (tlb[last_hit_index[i]].hi.ASID == ASID->asid))){
          if(tlb[last_hit_index[i]].hi.PS == 12){
            if((vaddr >> 13) == tlb[last_hit_index[i]].hi.VPPN){
              matched_tlb_index = last_hit_index[i];
              even_or_odd = (vaddr >> 12)%2;
              match_tlb ++;
            }
          }
          else if(tlb[last_hit_index[i]].hi.PS == 21){
            if((vaddr >> 22) == (tlb[last_hit_index[i]].hi.VPPN >> 9)){
              matched_tlb_index = last_hit_index[i];
              even_or_odd = (vaddr >> 21)%2;
              match_tlb ++;
            }        
          }
        }
        if(last_hit_index[0] == last_hit_index[1]) break;
      }      

      if(match_tlb == 0){
        do_lru = 1;
        for(i = 0; i<CONFIG_TLB_ENTRIES; i++){
          if((tlb[i].hi.E == 1) && ((tlb[i].hi.G == 1) || (tlb[i].hi.ASID == ASID->asid))){
            if(tlb[i].hi.PS == 12){
              if((vaddr >> 13) == tlb[i].hi.VPPN){
                matched_tlb_index = i;
                even_or_odd = (vaddr >> 12)%2;
                match_tlb ++;
              }
            }
            else if(tlb[i].hi.PS == 21){
              if((vaddr >> 22) == (tlb[i].hi.VPPN >> 9)){
                matched_tlb_index = i;
                even_or_odd = (vaddr >> 21)%2;
                match_tlb ++;
              }        
            }
          }
        }
      }

      if(match_tlb == 0){
        // printf("PC: 0x%x [NEMU]: EXCEPTION TLBR\n",cpu.pc);  
        BADV->val = vaddr;
        TLBEHI->vppn = vaddr >> 13;
        longjmp_exception(EX_TLBR); 
      }else if(match_tlb > 1){
        printf("[NEMU] ERROR: multiple(%d) tlb entries matched.\n", match_tlb);
        printf("last_hit_index : %d %d\n",last_hit_index[0],last_hit_index[1]);
        exit(1);
      }else if(match_tlb == 1){
        if(tlb[matched_tlb_index].lo[even_or_odd].V == 0){
          if(type == MEM_TYPE_IFETCH){
            // printf("PC: 0x%x [NEMU]: EXCEPTION PIF\n",cpu.pc);  
            BADV->val = vaddr;
            TLBEHI->vppn = vaddr >> 13;
            longjmp_exception(EX_PIF); 
          }else if(type == MEM_TYPE_READ){
            // printf("PC: 0x%x [NEMU]: EXCEPTION PIL\n",cpu.pc);  
            BADV->val = vaddr;
            TLBEHI->vppn = vaddr >> 13;
            longjmp_exception(EX_PIL); 
          }else if(type == MEM_TYPE_WRITE){
            // printf("PC: 0x%x [NEMU]: EXCEPTION PIS\n",cpu.pc);  
            BADV->val = vaddr;
            TLBEHI->vppn = vaddr >> 13;
            longjmp_exception(EX_PIS); 
          }
        }
        if(tlb[matched_tlb_index].lo[even_or_odd].PLV < CRMD->plv){
          // printf("PC: 0x%x [NEMU]: EXCEPTION PPI\n",cpu.pc);  
          BADV->val = vaddr;
          TLBEHI->vppn = vaddr >> 13;
          longjmp_exception(EX_PPI);          
        }
        if((type == MEM_TYPE_WRITE) && (tlb[matched_tlb_index].lo[even_or_odd].D == 0)){
          // printf("PC: 0x%x [NEMU]: EXCEPTION PME\n",cpu.pc);  
          BADV->val = vaddr;
          TLBEHI->vppn = vaddr >> 13;
          longjmp_exception(EX_PME);          
        }
    
        if(do_lru){
          last_hit_index[last_hit_replace] = matched_tlb_index;
          last_hit_replace = 1 - last_hit_replace;
        }

        if(tlb[matched_tlb_index].hi.PS == 12){
          return (((tlb[matched_tlb_index].lo[even_or_odd].PPN) << 12) | (vaddr & 0x00000fff));
        }else if(tlb[matched_tlb_index].hi.PS == 21){
          return ((((tlb[matched_tlb_index].lo[even_or_odd].PPN) << 12) & 0xffe00000) | (vaddr & 0x001fffff));
        }else{
          printf("[NEMU] ERROR: PS != 12 NOR PS != 21, please check tlb\n");
          exit(1);
        }
      }
    }
  }
  printf("[NEMU]: addr translate failed\n");
  return vaddr;
}

void print_tlb_entry(int n){
  printf("tlb[%d]:\n", n);
  printf("HI:0x%016lx\n", tlb[n].hi.val);
  printf("VPPN: 0x%x  PS: 0x%x  G: 0x%x  ASID: 0x%x  E: 0x%x\n",tlb[n].hi.VPPN,tlb[n].hi.PS,tlb[n].hi.G,tlb[n].hi.ASID,tlb[n].hi.E);
  printf("LO[0]:0x%08x\n", tlb[n].lo[0].val);
  printf("PPN0: 0x%x  PLV0: 0x%x  MAT0: 0x%x  D0: 0x%x  V0: 0x%x\n",tlb[n].lo[0].PPN,tlb[n].lo[0].PLV,tlb[n].lo[0].MAT,tlb[n].lo[0].D,tlb[n].lo[0].V);
  printf("LO[1]:0x%08x\n", tlb[n].lo[1].val);
  printf("PPN1: 0x%x  PLV1: 0x%x  MAT1: 0x%x  D1: 0x%x  V1: 0x%x\n",tlb[n].lo[1].PPN,tlb[n].lo[1].PLV,tlb[n].lo[1].MAT,tlb[n].lo[1].D,tlb[n].lo[1].V);
}