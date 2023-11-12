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

def_EHelper(csrrd) { 
  rtl_hostcall(s, HOSTCALL_CSR, s0, NULL, NULL, id_src1->imm);
  rtl_mv(s, ddest, s0);
}

def_EHelper(csrwr) { 
  rtl_mv(s, s1, ddest);
  rtl_hostcall(s, HOSTCALL_CSR, s0, s1, NULL, id_src1->imm);
  rtl_mv(s, ddest, s0);
}

def_EHelper(csrxchg) { 
/* ((old_value & ~rj) | (new_value & rj)) & W_MASK */

  rtlreg_t inv_rj = 0;
  rtlreg_t * temp = &inv_rj;
  rtl_and(s, s1, dsrc2, ddest);
  rtl_hostcall(s, HOSTCALL_CSR, s0, NULL, NULL, id_src1->imm);
  *temp = ~(*dsrc2);  // ~ rj
  rtl_and(s, s2, s0, temp);
  rtl_or(s, s1, s1, s2);
  rtl_hostcall(s, HOSTCALL_CSR, s0, s1, NULL, id_src1->imm);
  rtl_mv(s, ddest, s0);
}