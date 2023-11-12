# 1 "n57_ale_st_w_ex.S"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "n57_ale_st_w_ex.S"
# 1 "../include/asm.h" 1



# 1 "../include/regdef.h" 1
# 5 "../include/asm.h" 2
# 1 "../include/sysdep.h" 1
# 6 "../include/asm.h" 2
# 2 "n57_ale_st_w_ex.S" 2
# 1 "../include/regdef.h" 1
# 3 "n57_ale_st_w_ex.S" 2
# 1 "../include/inst_test.h" 1

# 1 "../include/cpu_cde.h" 1
# 1 "../include/lab_config.h" 1
# 2 "../include/cpu_cde.h" 2
# 3 "../include/inst_test.h" 2
# 4 "n57_ale_st_w_ex.S" 2

.text; .globl n57_ale_st_w_ex_test; .align 3; .cfi_startproc ; .type n57_ale_st_w_ex_test, @function; n57_ale_st_w_ex_test:

  addi.w $r23, $r23, 1
  li.w $r16, 0x39
  li.w $r12, (0x100000 +0xd0000); li.w $r25, 0x6; st.w $r25, $r12, 0

  li.w $r12, 0x1
  csrwr $r12, 0x44

  li.w $r12, 0x3
  li.w $r13, 0x7
  csrxchg $r12, $r13, 0x0
  lu12i.w $r30, 0x60
  li.w $r17, 0x3

##inst test
###1
  li.w $r14, 0xb189c470; li.w $r15, 0xb189c470; li.w $r4, 0xd7bd1; li.w $r5, 0xb189c470; addi.w $r7, $r4, 0x0000774; st.w $r14, $r4, 0x0000773
  la.local $r27, 1f
1:
  st.w $r5, $r4, 0x774
  bne $r25, $r30, inst_error
  ld.w $r14, $r4, 0x773
  bne $r14, $r15, inst_error
  li.w $r12, (0x100000 +0xd0000); li.w $r25, 0xf; st.w $r25, $r12, 0
  syscall 0
  csrrd $r12, 0x7
  bne $r7, $r12, inst_error
  csrrd $r12, 0x0
  li.w $r13, 0x7
  and $r12, $r12, $r13
  li.w $r13, 0x0
  bne $r13, $r12, inst_error

  li.w $r17, 0x0
  li.w $r12, (0x100000 +0xd0000); li.w $r25, 0x6; st.w $r25, $r12, 0

###2
  li.w $r19, (0x100000 +0xd0000)
  li.w $r25, 0x06
  li.w $r14, 0xc052b3f0; li.w $r15, 0xc052b3f0; li.w $r4, 0xd23d4; li.w $r5, 0xc052b3f0; addi.w $r7, $r4, 0x00006a2; st.w $r14, $r4, 0x00006a0
  la.local $r27, 1f
  st.w $r19, $r19, 4
  st.w $r27, $r19, 4
1:
  st.w $r5, $r4, 0x6a2
  st.w $r27, $r19, 0
  ld.w $r13, $r19, 4
  bne $r13, $r27, inst_error
  bne $r25, $r30, inst_error
  ld.w $r14, $r4, 0x6a0
  bne $r14, $r15, inst_error
  csrrd $r12, 0x7
  bne $r7, $r12, inst_error
  csrrd $r12, 0x0
  li.w $r13, 0x7
  and $r12, $r12, $r13
  li.w $r13, 0x0
  bne $r13, $r12, inst_error
  li.w $r25, 0x6
  st.w $r25, $r19, 0

###3
  li.w $r25, 0x06
  li.w $r14, 0xa10febaf; li.w $r15, 0xa10febaf; li.w $r4, 0xd8850; li.w $r5, 0x994c0280; addi.w $r7, $r4, 0x000048b; st.w $r14, $r4, 0x0000488
  la.local $r27, 1f
  li.w $r19, 0xf
  li.w $r20, 0xf
  div.w $r19, $r13, $r16
1:
  st.w $r5, $r4, 0x48b
  beq $r20, $r19, inst_error
  bne $r25, $r30, inst_error
  ld.w $r14, $r4, 0x488
  bne $r14, $r15, inst_error
  csrrd $r12, 0x7
  bne $r7, $r12, inst_error

###4
  li.w $r25, 0x06
  li.w $r14, 0xeb54b87c; li.w $r15, 0xeb54b87c; li.w $r4, 0xda256; li.w $r5, 0xeb54b87c; addi.w $r7, $r4, 0x000000c3; st.w $r14, $r4, 0x000000c2
  la.local $r27, 1f
1:
  st.w $r5, $r4, 0xc3
  div.w $r12, $r12, $r16
  bne $r25, $r30, inst_error
  ld.w $r14, $r4, 0xc2
  bne $r14, $r15, inst_error
  csrrd $r12, 0x7
  bne $r7, $r12, inst_error

###5
  li.w $r25, 0x06
  li.w $r14, 0x80032066; li.w $r15, 0x80032066; li.w $r4, 0xd206c; li.w $r5, 0xebdc8860; addi.w $r7, $r4, -0x33e; st.w $r14, $r4, -0x340
  la.local $r27, 1f
  li.w $r19, 0xf
  li.w $r20, 0xf
  mul.w $r19, $r16, $r19
1:
  st.w $r5, $r4, -0x33e
  beq $r20, $r19, inst_error
  bne $r25, $r30, inst_error
  ld.w $r14, $r4, -0x340
  bne $r14, $r15, inst_error
  csrrd $r12, 0x7
  bne $r7, $r12, inst_error

###6
  li.w $r25, 0x06
  li.w $r14, 0x634858c8; li.w $r15, 0x634858c8; li.w $r4, 0xd82d8; li.w $r5, 0x0c41f5e8; addi.w $r7, $r4, -0x777; st.w $r14, $r4, -0x778
  la.local $r27, 1f
1:
  st.w $r5, $r4, -0x777
  mul.w $r12, $r12, $r16
  bne $r25, $r30, inst_error
  ld.w $r14, $r4, -0x778
  bne $r14, $r15, inst_error
  csrrd $r12, 0x7
  bne $r7, $r12, inst_error

###7
  li.w $r25, 0x06
  li.w $r14, 0x80031751; li.w $r15, 0x80031751; li.w $r4, 0xd1750; li.w $r5, 0xcb09da60; addi.w $r7, $r4, -0x6d9; st.w $r14, $r4, -0x6dc
  la.local $r27, 1f
  csrwr $r25, 0x6
1:
  st.w $r14, $r4, -0x6d9
  csrwr $r12, 0x6
  bne $r25, $r30, inst_error
  ld.w $r14, $r4, -0x6dc
  bne $r14, $r15, inst_error
  csrrd $r12, 0x7
  bne $r7, $r12, inst_error

  li.w $r12, 0x0
  li.w $r13, 0x3
  csrxchg $r12, $r13, 0x0
###score +++
  addi.w $r26, $r26, 1
###output ($r23<<24)|$r26
inst_error:
  slli.w $r13, $r23, 24
  or $r12, $r13, $r26
  st.w $r12, $r24, 0
  jirl $r0, $r1, 0
.cfi_endproc ; .size n57_ale_st_w_ex_test,.-n57_ale_st_w_ex_test;
