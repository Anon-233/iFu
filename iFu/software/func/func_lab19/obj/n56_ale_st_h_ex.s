# 1 "n56_ale_st_h_ex.S"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "n56_ale_st_h_ex.S"
# 1 "../include/asm.h" 1



# 1 "../include/regdef.h" 1
# 5 "../include/asm.h" 2
# 1 "../include/sysdep.h" 1
# 6 "../include/asm.h" 2
# 2 "n56_ale_st_h_ex.S" 2
# 1 "../include/regdef.h" 1
# 3 "n56_ale_st_h_ex.S" 2
# 1 "../include/inst_test.h" 1

# 1 "../include/cpu_cde.h" 1
# 1 "../include/lab_config.h" 1
# 2 "../include/cpu_cde.h" 2
# 3 "../include/inst_test.h" 2
# 4 "n56_ale_st_h_ex.S" 2

.text; .globl n56_ale_st_h_ex_test; .align 3; .cfi_startproc ; .type n56_ale_st_h_ex_test, @function; n56_ale_st_h_ex_test:

  addi.w $r23, $r23, 1
  li.w $r16, 0x38
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
  li.w $r14, 0x8003602a; li.w $r15, 0x8003602a; li.w $r4, 0xd602a; li.w $r5, 0x47cdf6da; addi.w $r7, $r4, -0x7cb; st.w $r14, $r4, -0x7ce
  la.local $r27, 1f
1:
  st.h $r5, $r4, -0x7cb
  bne $r25, $r30, inst_error
  ld.w $r14, $r4, -0x7ce
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

  li.w $r17, 0
  li.w $r12, (0x100000 +0xd0000); li.w $r25, 0x6; st.w $r25, $r12, 0

###2
  li.w $r19, (0x100000 +0xd0000)
  li.w $r25, 0x06
  li.w $r14, 0x6e9ce24e; li.w $r15, 0x6e9ce24e; li.w $r4, 0xd2c08; li.w $r5, 0x6e9ce24e; addi.w $r7, $r4, 0x000009b; st.w $r14, $r4, 0x0000098
  la.local $r27, 1f
  st.w $r19, $r19, 4
  st.w $r27, $r19, 4
1:
  st.h $r5, $r4, 0x9b
  st.w $r27, $r19, 0
  ld.w $r13, $r19, 4
  bne $r13, $r27, inst_error
  bne $r25, $r30, inst_error
  ld.w $r14, $r4, 0x98
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
  li.w $r14, 0x419f9f3b; li.w $r15, 0x419f9f3b; li.w $r4, 0xd1356; li.w $r5, 0xbb1afce8; addi.w $r7, $r4, 0x00001d3; st.w $r14, $r4, 0x00001d2
  la.local $r27, 1f
  li.w $r19, 0xf
  li.w $r20, 0xf
  div.w $r19, $r13, $r16
1:
  st.h $r5, $r4, 0x1d3
  beq $r20, $r19, inst_error
  bne $r25, $r30, inst_error
  ld.w $r14, $r4, 0x1d2
  bne $r14, $r15, inst_error
  csrrd $r12, 0x7
  bne $r7, $r12, inst_error

###4
  li.w $r25, 0x06
  li.w $r14, 0x80033729; li.w $r15, 0x80033729; li.w $r4, 0xd372c; li.w $r5, 0x190a65ca; addi.w $r7, $r4, -0x70f; st.w $r14, $r4, -0x710
  la.local $r27, 1f
1:
  st.h $r5, $r4, -0x70f
  div.w $r12, $r12, $r16
  bne $r25, $r30, inst_error
  ld.w $r14, $r4, -0x710
  bne $r14, $r15, inst_error
  csrrd $r12, 0x7
  bne $r7, $r12, inst_error

###5
  li.w $r25, 0x06
  li.w $r14, 0x80031ff3; li.w $r15, 0x80031ff3; li.w $r4, 0xd1ff0; li.w $r5, 0x9fcc4ca0; addi.w $r7, $r4, -0x49d; st.w $r14, $r4, -0x4a0
  la.local $r27, 1f
  li.w $r19, 0xf
  li.w $r20, 0xf
  mul.w $r19, $r16, $r19
1:
  st.h $r5, $r4, -0x49d
  beq $r20, $r19, inst_error
  bne $r25, $r30, inst_error
  ld.w $r14, $r4, -0x4a0
  bne $r14, $r15, inst_error
  csrrd $r12, 0x7
  bne $r7, $r12, inst_error

###6
  li.w $r25, 0x06
  li.w $r14, 0x73b35a2b; li.w $r15, 0x73b35a2b; li.w $r4, 0xd351b; li.w $r5, 0xbd6f420a; addi.w $r7, $r4, 0x00006f2; st.w $r14, $r4, 0x00006f1
  la.local $r27, 1f
1:
  st.h $r5, $r4, 0x6f2
  mul.w $r12, $r12, $r16
  bne $r25, $r30, inst_error
  ld.w $r14, $r4, 0x6f1
  bne $r14, $r15, inst_error
  csrrd $r12, 0x7
  bne $r7, $r12, inst_error

###7
  li.w $r25, 0x06
  li.w $r14, 0xa5210b0a; li.w $r15, 0xa5210b0a; li.w $r4, 0xd63d7; li.w $r5, 0x00e95990; addi.w $r7, $r4, 0x00007c6; st.w $r14, $r4, 0x00007c5
  la.local $r27, 1f
  csrwr $r25, 0x6
1:
  st.h $r14, $r4, 0x7c6
  csrwr $r12, 0x6
  bne $r25, $r30, inst_error
  ld.w $r14, $r4, 0x7c5
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
.cfi_endproc ; .size n56_ale_st_h_ex_test,.-n56_ale_st_h_ex_test;
