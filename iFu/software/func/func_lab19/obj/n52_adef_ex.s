# 1 "n52_adef_ex.S"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "n52_adef_ex.S"
# 1 "../include/asm.h" 1



# 1 "../include/regdef.h" 1
# 5 "../include/asm.h" 2
# 1 "../include/sysdep.h" 1
# 6 "../include/asm.h" 2
# 2 "n52_adef_ex.S" 2
# 1 "../include/regdef.h" 1
# 3 "n52_adef_ex.S" 2
# 1 "../include/inst_test.h" 1

# 1 "../include/cpu_cde.h" 1
# 1 "../include/lab_config.h" 1
# 2 "../include/cpu_cde.h" 2
# 3 "../include/inst_test.h" 2
# 4 "n52_adef_ex.S" 2

.text; .globl n52_adef_ex_test; .align 3; .cfi_startproc ; .type n52_adef_ex_test, @function; n52_adef_ex_test:

  addi.w $r23, $r23, 1
  li.w $r16, 0x34
  li.w $r12, (0x100000 +0xd0000); li.w $r25, 0x5; st.w $r25, $r12, 0

  li.w $r12, 0x1
  csrwr $r12, 0x44

  li.w $r12, 0x3
  li.w $r13, 0x7
  csrxchg $r12, $r13, 0x0
  lu12i.w $r30, 0x50
  li.w $r17, 0x3

##inst test
###1
  li.w $r27, 0x227f9789; li.w $r7, 0x227f9789; li.w $r29, 0x227f9789
  jirl $r28, $r27, 0
  add.w $r0, $r0, $r0
  bne $r25, $r30, inst_error
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
  li.w $r12, (0x100000 +0xd0000); li.w $r25, 0x5; st.w $r25, $r12, 0

###2
  li.w $r19, (0x100000 +0xd0000)
  li.w $r25, 0x05
  li.w $r27, 0x3101bbed; li.w $r7, 0x3101bbed; li.w $r29, 0x3101bbed
  csrwr $r29, 0x6
  la.local $r28, 1f
  st.w $r19, $r19, 4
  st.w $r27, $r19, 4
1: ertn
  st.w $r27, $r19, 0
  ld.w $r13, $r19, 4
  bne $r13, $r27, inst_error
  bne $r25, $r30, inst_error
  csrrd $r12, 0x7
  bne $r7, $r12, inst_error
  li.w $r25, 0x5
  st.w $r25, $r19, 0

###3
  li.w $r25, 0x05
  li.w $r27, 0x44790977; li.w $r7, 0x44790977; li.w $r29, 0x44790977
  csrwr $r29, 0x6
  la.local $r28, 1f
  li.w $r19, 0xf
  li.w $r20, 0xf
  div.w $r19, $r13, $r16
1: ertn
  beq $r20, $r19, inst_error
  bne $r25, $r30, inst_error
  csrrd $r12, 0x7
  bne $r7, $r12, inst_error

###4
  li.w $r25, 0x05
  li.w $r27, 0x92b0a2c3; li.w $r7, 0x92b0a2c3; li.w $r29, 0x92b0a2c3
  jirl $r28, $r27, 0
  add.w $r0, $r0, $r0
  div.w $r12, $r12, $r16
  bne $r25, $r30, inst_error
  csrrd $r12, 0x7
  bne $r7, $r12, inst_error

###5
  li.w $r25, 0x05
  li.w $r27, 0xaf9edafa; li.w $r7, 0xaf9edafa; li.w $r29, 0xaf9edafa
  csrwr $r29, 0x6
  la.local $r28, 1f
  li.w $r19, 0xf
  li.w $r20, 0xf
  mul.w $r19, $r16, $r19
1: ertn
  beq $r20, $r19, inst_error
  bne $r25, $r30, inst_error
  csrrd $r12, 0x7
  bne $r7, $r12, inst_error

###6
  li.w $r25, 0x05
  li.w $r27, 0xb088f329; li.w $r7, 0xb088f329; li.w $r29, 0xb088f329
  jirl $r28, $r27, 0
  add.w $r0, $r0, $r0
  mul.w $r12, $r12, $r16
  bne $r25, $r30, inst_error
  csrrd $r12, 0x7
  bne $r7, $r12, inst_error

###7
  li.w $r25, 0x05
  li.w $r27, 0x827f97ab; li.w $r7, 0x827f97ab; li.w $r29, 0x827f97ab
  csrwr $r29, 0x6
  la.local $r28, 1f
1: ertn
  csrwr $r12, 0x6
  bne $r25, $r30, inst_error
  csrrd $r12, 0x7
  bne $r7, $r12, inst_error

###should not generate adef excp
## 8
  add.w $r14, $r1, $r0
  li.w $r12, 0x9
  csrwr $r12, 0x180

  li.w $r12, 0x3
  csrxchg $r12, $r12, 0x0

  li.w $r12, 0xd0010
  li.w $r13, 0x4c000020
  st.w $r13, $r12, 0
  andi $r0, $r0, 0
  andi $r0, $r0, 0
  andi $r0, $r0, 0
  andi $r0, $r0, 0
  andi $r0, $r0, 0
  andi $r0, $r0, 0
  andi $r0, $r0, 0
  andi $r0, $r0, 0
  andi $r0, $r0, 0
  jirl $r1, $r12, 0

## 9
  li.w $r12, 0xa0000000
  li.w $r13, 0x4c000020
  st.w $r13, $r12, 0
  andi $r0, $r0, 0
  andi $r0, $r0, 0
  andi $r0, $r0, 0
  andi $r0, $r0, 0
  andi $r0, $r0, 0
  andi $r0, $r0, 0
  andi $r0, $r0, 0
  andi $r0, $r0, 0
  andi $r0, $r0, 0
  jirl $r1, $r12, 0

  li.w $r12, (0x100000 +0xd0000); li.w $r25, 0xf; st.w $r25, $r12, 0
  syscall 0

  li.w $r12, 0x19
  csrwr $r12, 0x180

  add.w $r1, $r14, $r0

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
.cfi_endproc ; .size n52_adef_ex_test,.-n52_adef_ex_test;
