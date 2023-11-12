# 1 "n55_ale_ld_hu_ex.S"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "n55_ale_ld_hu_ex.S"
# 1 "../include/asm.h" 1



# 1 "../include/regdef.h" 1
# 5 "../include/asm.h" 2
# 1 "../include/sysdep.h" 1
# 6 "../include/asm.h" 2
# 2 "n55_ale_ld_hu_ex.S" 2
# 1 "../include/regdef.h" 1
# 3 "n55_ale_ld_hu_ex.S" 2
# 1 "../include/inst_test.h" 1

# 1 "../include/cpu_cde.h" 1
# 1 "../include/lab_config.h" 1
# 2 "../include/cpu_cde.h" 2
# 3 "../include/inst_test.h" 2
# 4 "n55_ale_ld_hu_ex.S" 2

.text; .globl n55_ale_ld_hu_ex_test; .align 3; .cfi_startproc ; .type n55_ale_ld_hu_ex_test, @function; n55_ale_ld_hu_ex_test:

  addi.w $r23, $r23, 1
  li.w $r16, 0x37
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
  li.w $r14, 0x93252910; li.w $r15, 0x93252910; li.w $r4, 0xd1348; li.w $r5, 0x0233e52c; addi.w $r7, $r4, -0x6e7; st.w $r5, $r4, -0x6e8
  la.local $r27, 1f
1:
  ld.hu $r14, $r4, -0x6e7
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
  li.w $r14, 0x854aa680; li.w $r15, 0x854aa680; li.w $r4, 0xd2ca8; li.w $r5, 0x2ba90e90; addi.w $r7, $r4, 0x0000577; st.w $r5, $r4, 0x0000574
  la.local $r27, 1f
  st.w $r19, $r19, 4
  st.w $r27, $r19, 4
1:
  ld.hu $r14, $r4, 0x577
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
  li.w $r14, 0x541f6c5c; li.w $r15, 0x541f6c5c; li.w $r4, 0xd1570; li.w $r5, 0x9554e8d4; addi.w $r7, $r4, -0x71d; st.w $r5, $r4, -0x720
  la.local $r27, 1f
  li.w $r19, 0xf
  li.w $r20, 0xf
  div.w $r19, $r13, $r16
1:
  ld.hu $r14, $r4, -0x71d
  beq $r20, $r19, inst_error
  bne $r25, $r30, inst_error
  bne $r14, $r15, inst_error
  csrrd $r12, 0x7
  bne $r7, $r12, inst_error

###4
  li.w $r25, 0x06
  li.w $r14, 0x224cf16c; li.w $r15, 0x224cf16c; li.w $r4, 0xd69cc; li.w $r5, 0x8ef75a20; addi.w $r7, $r4, -0x7bf; st.w $r5, $r4, -0x7c0
  la.local $r27, 1f
1:
  ld.hu $r14, $r4, -0x7bf
  div.w $r12, $r12, $r16
  bne $r25, $r30, inst_error
  bne $r14, $r15, inst_error
  csrrd $r12, 0x7
  bne $r7, $r12, inst_error

###5
  li.w $r25, 0x06
  li.w $r14, 0x516f5fa2; li.w $r15, 0x516f5fa2; li.w $r4, 0xd0438; li.w $r5, 0xcb7ef7d5; addi.w $r7, $r4, -0x2c5; st.w $r5, $r4, -0x2c8
  la.local $r27, 1f
  li.w $r19, 0xf
  li.w $r20, 0xf
  mul.w $r19, $r16, $r19
1:
  ld.hu $r14, $r4, -0x2c5
  beq $r20, $r19, inst_error
  bne $r25, $r30, inst_error
  bne $r14, $r15, inst_error
  csrrd $r12, 0x7
  bne $r7, $r12, inst_error

###6
  li.w $r25, 0x06
  li.w $r14, 0x3537cc30; li.w $r15, 0x3537cc30; li.w $r4, 0xd2c20; li.w $r5, 0x5118e811; addi.w $r7, $r4, 0x0000115; st.w $r5, $r4, 0x0000114
  la.local $r27, 1f
1:
  ld.hu $r14, $r4, 0x115
  mul.w $r12, $r12, $r16
  bne $r25, $r30, inst_error
  bne $r14, $r15, inst_error
  csrrd $r12, 0x7
  bne $r7, $r12, inst_error

###7
  li.w $r25, 0x06
  li.w $r14, 0x63c6e7af; li.w $r15, 0x63c6e7af; li.w $r4, 0xd3d5c; li.w $r5, 0xd80241b4; addi.w $r7, $r4, 0x00003e9; st.w $r5, $r4, 0x00003e8
  la.local $r27, 1f
  csrwr $r25, 0x6
1:
  ld.hu $r14, $r4, 0x3e9
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
.cfi_endproc ; .size n55_ale_ld_hu_ex_test,.-n55_ale_ld_hu_ex_test;
