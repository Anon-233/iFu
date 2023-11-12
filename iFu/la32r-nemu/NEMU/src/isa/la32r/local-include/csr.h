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

#ifndef __CSR_H__
#define __CSR_H__

#include <common.h>
#include <macro.h>

#define CSRS(f) \
  f(CRMD    , 0x0)  f(PRMD    , 0x1)   f(EUEN    , 0x2)  f(ECFG     , 0x4)  f(ESTAT     , 0x5) \
  f(ERA     , 0x6)  f(BADV    , 0x7)   f(EENTRY  , 0xc)  f(TLBIDX   , 0x10) f(TLBEHI    , 0x11) \
  f(TLBELO0 , 0x12) f(TLBELO1 , 0x13)  f(ASID    , 0x18) f(PGDL     , 0x19) \
  f(PGDH    , 0x1a) f(PGD     , 0x1b)  f(CPUID   , 0x20) f(SAVE0    , 0x30) f(SAVE1     , 0x31) f(SAVE2      , 0x32) f(SAVE3    , 0x33) \
  f(TID     , 0x40) f(TCFG    , 0x41)  f(TVAL    , 0x42) f(TICLR    , 0x44) f(LLBCTL    , 0x60) f(TLBRENTRY  , 0x88) \
  f(DMW0    , 0x180) f(DMW1    , 0x181) 

#define CSR_STRUCT_START(name) \
  typedef union { \
    struct {

#define CSR_STRUCT_END(name) \
    }; \
    word_t val; \
  } concat(name, _t);

// uint32_t estat_sync; 

CSR_STRUCT_START(CRMD)
  uint32_t plv : 2;
  uint32_t ie  : 1;
  uint32_t da  : 1;
  uint32_t pg  : 1;
  uint32_t datf: 2;
  uint32_t datm: 2;
  uint32_t pad0: 23;
CSR_STRUCT_END(CRMD)

CSR_STRUCT_START(PRMD)
  uint32_t pplv : 2;
  uint32_t pie  : 1;
  uint32_t pad0 : 29;
CSR_STRUCT_END(PRMD)

CSR_STRUCT_START(EUEN)
  uint32_t fpe  : 1;
  uint32_t pad0 : 31;
CSR_STRUCT_END(EUEN)

CSR_STRUCT_START(ECFG)
  uint32_t lie  : 13;
  uint32_t pad0 : 19;
CSR_STRUCT_END(ECFG)

CSR_STRUCT_START(ESTAT)
  uint32_t is_01    : 2;    // SWI0 SWI1
  uint32_t is_2_12  : 11;   // HWI0~HWI7 TI IPI
  uint32_t pad0     : 3;
  uint32_t ecode    : 6;
  uint32_t esubcode : 9;
  uint32_t pad1     : 1;
CSR_STRUCT_END(ESTAT)

CSR_STRUCT_START(ERA)
CSR_STRUCT_END(ERA)

CSR_STRUCT_START(BADV)
CSR_STRUCT_END(BADV)

CSR_STRUCT_START(EENTRY)
  uint32_t pad0    : 6;
  uint32_t va      : 26;
CSR_STRUCT_END(EENTRY)

CSR_STRUCT_START(CPUID)
  uint32_t coreid  : 9;
  uint32_t pad0    : 23;
CSR_STRUCT_END(CPUID)

CSR_STRUCT_START(SAVE0)
CSR_STRUCT_END(SAVE0)

CSR_STRUCT_START(SAVE1)
CSR_STRUCT_END(SAVE1)

CSR_STRUCT_START(SAVE2)
CSR_STRUCT_END(SAVE2)

CSR_STRUCT_START(SAVE3)
CSR_STRUCT_END(SAVE3)

CSR_STRUCT_START(LLBCTL)
  uint32_t rollb    : 1;
  uint32_t wcllb    : 1;
  uint32_t klo      : 1;
  uint32_t pad0     : 29;
CSR_STRUCT_END(LLBCTL)

CSR_STRUCT_START(TLBIDX)
  uint32_t index    : 5;    // modify this when you need to change TLB entries
  uint32_t pad0     : 19;
  uint32_t ps       : 6;
  uint32_t pad1     : 1;
  uint32_t ne       : 1;
CSR_STRUCT_END(TLBIDX)

CSR_STRUCT_START(TLBEHI)
  uint32_t pad0    : 13;
  uint32_t vppn    : 19;
CSR_STRUCT_END(TLBEHI)

CSR_STRUCT_START(TLBELO0)
  uint32_t v    : 1;
  uint32_t d    : 1;
  uint32_t plv  : 2;
  uint32_t mat  : 2;
  uint32_t g    : 1;
  uint32_t pad0 : 1;
  uint32_t ppn  : 24;
CSR_STRUCT_END(TLBELO0)

CSR_STRUCT_START(TLBELO1)
  uint32_t v    : 1;
  uint32_t d    : 1;
  uint32_t plv  : 2;
  uint32_t mat  : 2;
  uint32_t g    : 1;
  uint32_t pad0 : 1;
  uint32_t ppn  : 24;
CSR_STRUCT_END(TLBELO1)

CSR_STRUCT_START(ASID)
  uint32_t asid      : 10;
  uint32_t pad0      : 6;
  uint32_t asidbits  : 8;
  uint32_t pad1      : 8;
CSR_STRUCT_END(ASID)

CSR_STRUCT_START(PGDL)
  uint32_t pad0      : 12;
  uint32_t base      : 20;
CSR_STRUCT_END(PGDL)

CSR_STRUCT_START(PGDH)
  uint32_t pad0      : 12;
  uint32_t base      : 20;
CSR_STRUCT_END(PGDH)

CSR_STRUCT_START(PGD)
  uint32_t pad0      : 12;
  uint32_t base      : 20;
CSR_STRUCT_END(PGD)

CSR_STRUCT_START(TLBRENTRY)
  uint32_t pad0    : 6;
  uint32_t pa      : 26;
CSR_STRUCT_END(TLBRENTRY)

CSR_STRUCT_START(DMW0)
  uint32_t plv0   : 1;
  uint32_t pad0   : 2;
  uint32_t plv3   : 1;
  uint32_t mat    : 2;
  uint32_t pad1   : 19;
  uint32_t pseg   : 3;
  uint32_t pad2   : 1;
  uint32_t vseg   : 3;
CSR_STRUCT_END(DMW0)

CSR_STRUCT_START(DMW1)
  uint32_t plv0   : 1;
  uint32_t pad0   : 2;
  uint32_t plv3   : 1;
  uint32_t mat    : 2;
  uint32_t pad1   : 19;
  uint32_t pseg   : 3;
  uint32_t pad2   : 1;
  uint32_t vseg   : 3;
CSR_STRUCT_END(DMW1)

CSR_STRUCT_START(TID)
CSR_STRUCT_END(TID)

CSR_STRUCT_START(TCFG)
  uint32_t en        : 1;
  uint32_t periodic  : 1;
  uint32_t initval   : 30;
CSR_STRUCT_END(TCFG)

CSR_STRUCT_START(TVAL)
CSR_STRUCT_END(TVAL)

CSR_STRUCT_START(TICLR)
  uint32_t clr    : 1;
  uint32_t pad0   : 31;
CSR_STRUCT_END(TICLR)

#define CSRS_DECL(name, addr) extern concat(name, _t)* const name;
MAP(CSRS, CSRS_DECL)


word_t csrid_read(uint32_t csrid);
void init_csr();
#endif