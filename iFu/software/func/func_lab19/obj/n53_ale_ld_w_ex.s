# 1 "n53_ale_ld_w_ex.S"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "n53_ale_ld_w_ex.S"
# 1 "../include/asm.h" 1



# 1 "../include/regdef.h" 1
# 5 "../include/asm.h" 2
# 1 "../include/sysdep.h" 1
# 6 "../include/asm.h" 2
# 2 "n53_ale_ld_w_ex.S" 2
# 1 "../include/regdef.h" 1
# 3 "n53_ale_ld_w_ex.S" 2
# 1 "../include/inst_test.h" 1

# 1 "../include/cpu_cde.h" 1
# 1 "../include/lab_config.h" 1
# 2 "../include/cpu_cde.h" 2
# 3 "../include/inst_test.h" 2
# 4 "n53_ale_ld_w_ex.S" 2

.text; .globl n53_ale_ld_w_ex_test; .align 3; .cfi_startproc ; .type n53_ale_ld_w_ex_test, @function; n53_ale_ld_w_ex_test:

  addi.w $r23, $r23, 1
  li.w $r16, 0x35
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
  li.w $r14, 0x3958f252; li.w $r15, 0x3958f252; li.w $r4, 0xd059c; li.w $r5, 0xb27f9788; addi.w $r7, $r4, -0x7bb; st.w $r5, $r4, -0x7bc
  la.local $r27, 1f
1:
  ld.w $r14, $r4, -0x7bb
  bne $r25, $r30, inst_error
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
  li.w $r14, 0xc0442bd0; li.w $r15, 0xc0442bd0; li.w $r4, 0xd7748; li.w $r5, 0x3101bbec; addi.w $r7, $r4, 0x000006a2; st.w $r5, $r4, 0x000006a0
  la.local $r27, 1f
  st.w $r27, $r19, 4
1:
  ld.w $r14, $r4, 0x6a2
  st.w $r27, $r19, 0
  ld.w $r13, $r19, 4
  bne $r13, $r27, inst_error
  bne $r25, $r30, inst_error
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
  li.w $r14, 0x68929b5c; li.w $r15, 0x68929b5c; li.w $r4, 0xd59dc; li.w $r5, 0x94a1ade4; addi.w $r7, $r4, 0x00004ee; st.w $r5, $r4, 0x00004ec
  la.local $r27, 1f
  li.w $r19, 0xf
  li.w $r20, 0xf
  div.w $r19, $r13, $r16
1:
  ld.w $r14, $r4, 0x4ee
  beq $r20, $r19, inst_error
  bne $r25, $r30, inst_error
  bne $r14, $r15, inst_error
  csrrd $r12, 0x7
  bne $r7, $r12, inst_error

###4
  li.w $r25, 0x06
  li.w $r14, 0x7423d85f; li.w $r15, 0x7423d85f; li.w $r4, 0xd7748; li.w $r5, 0xe2b0a2c0; addi.w $r7, $r4, 0x0000173; st.w $r5, $r4, 0x0000170
  la.local $r27, 1f
1:
  ld.w $r14, $r4, 0x173
  div.w $r12, $r12, $r16
  bne $r25, $r30, inst_error
  bne $r14, $r15, inst_error
  csrrd $r12, 0x7
  bne $r7, $r12, inst_error

###5
  li.w $r25, 0x06
  li.w $r14, 0xdd064458; li.w $r15, 0xdd064458; li.w $r4, 0xd5bac; li.w $r5, 0x0f9edafa; addi.w $r7, $r4, 0x0000003e; st.w $r5, $r4, 0x0000003c
  la.local $r27, 1f
  li.w $r19, 0xf
  li.w $r20, 0xf
  mul.w $r19, $r16, $r19
1:
  ld.w $r14, $r4, 0x3e
  beq $r20, $r19, inst_error
  bne $r25, $r30, inst_error
  bne $r14, $r15, inst_error
  csrrd $r12, 0x7
  bne $r7, $r12, inst_error

###6
  li.w $r25, 0x06
  li.w $r14, 0x15148b6c; li.w $r15, 0x15148b6c; li.w $r4, 0xd0704; li.w $r5, 0x5077f320; addi.w $r7, $r4, -0x1c1; st.w $r5, $r4, -0x1c4
  la.local $r27, 1f
1:
  ld.w $r14, $r4, -0x1c1
  mul.w $r12, $r12, $r16
  bne $r25, $r30, inst_error
  bne $r14, $r15, inst_error
  csrrd $r12, 0x7
  bne $r7, $r12, inst_error

###7
  li.w $r25, 0x06
  li.w $r14, 0x3958f252; li.w $r15, 0x3958f252; li.w $r4, 0xd759c; li.w $r5, 0xb27f9788; addi.w $r7, $r4, -0x7bb; st.w $r5, $r4, -0x7bc
  la.local $r27, 1f
  csrwr $r25, 0x6
1:
  ld.w $r14, $r4, -0x7bb
  csrwr $r12, 0x6
  bne $r25, $r30, inst_error
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
.cfi_endproc ; .size n53_ale_ld_w_ex_test,.-n53_ale_ld_w_ex_test;
