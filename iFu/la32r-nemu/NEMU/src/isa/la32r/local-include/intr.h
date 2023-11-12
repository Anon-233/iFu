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

#ifndef __INTR_H__
#define __INTR_H__

#include <cpu/decode.h>

#define EX_INT  0x0
#define EX_PIL  0x1
#define EX_PIS  0x2
#define EX_PIF  0x3
#define EX_PME  0x4
#define EX_PPI  0x7
#define EX_ADE  0x8
#define EX_ALE  0x9
#define EX_SYS  0xB
#define EX_BRK  0xC
#define EX_INE  0xD
#define EX_IPE  0xE
#define EX_FPD  0xF
#define EX_FPE  0x12
#define EX_TLBR 0x3F

#define SUBEX_ADEF  0x0
#define SUBEX_ADEM  0x1
#define SUBEX_FPE   0x0
#define SUBEX_NULL  0x0  // do not need esubcode

#define PRIV_ERET 1
#define PRIV_IDLE 2

word_t raise_intr(uint32_t ecode, vaddr_t epc);
extern int cosim_end;

#endif