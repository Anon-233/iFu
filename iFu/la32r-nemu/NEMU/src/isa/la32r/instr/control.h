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

def_EHelper(beq) {
  rtl_jrelop(s, RELOP_EQ, dsrc1, dsrc2, id_dest->imm);
}

def_EHelper(bne) {
  rtl_jrelop(s, RELOP_NE, dsrc1, dsrc2, id_dest->imm);
}

def_EHelper(blt) {
  rtl_jrelop(s, RELOP_LT, dsrc1, dsrc2, id_dest->imm);
}

def_EHelper(bge) {
  rtl_jrelop(s, RELOP_GE, dsrc1, dsrc2, id_dest->imm);
}

def_EHelper(bltu) {
  rtl_jrelop(s, RELOP_LTU, dsrc1, dsrc2, id_dest->imm);
}

def_EHelper(bgeu) {
  rtl_jrelop(s, RELOP_GEU, dsrc1, dsrc2, id_dest->imm);
}

def_EHelper(b) {
  rtl_j(s, id_src1->imm);
}

def_EHelper(bl) {
  rtl_li(s, ddest, id_src2->imm);
  rtl_j(s, id_src1->imm);
}

def_EHelper(jirl) {
  rtl_addi(s, s0, dsrc1, id_src2->imm);
  rtl_li(s, ddest, s->snpc);
  rtl_jr(s, s0);
}