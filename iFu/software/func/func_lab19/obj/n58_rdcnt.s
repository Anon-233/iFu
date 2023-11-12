# 1 "n58_rdcnt.S"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "n58_rdcnt.S"
# 1 "../include/asm.h" 1



# 1 "../include/regdef.h" 1
# 5 "../include/asm.h" 2
# 1 "../include/sysdep.h" 1
# 6 "../include/asm.h" 2
# 2 "n58_rdcnt.S" 2
# 1 "../include/regdef.h" 1
# 3 "n58_rdcnt.S" 2
# 1 "../include/inst_test.h" 1

# 1 "../include/cpu_cde.h" 1
# 1 "../include/lab_config.h" 1
# 2 "../include/cpu_cde.h" 2
# 3 "../include/inst_test.h" 2
# 4 "n58_rdcnt.S" 2

.text; .globl n58_rdcnt_test; .align 3; .cfi_startproc ; .type n58_rdcnt_test, @function; n58_rdcnt_test:

    addi.w $r23, $r23 ,1
    li.w $r18, 0x3b
    li.w $r25, 0x0
    li.w $r30, 0x1111ffff
    move $r13, $r30
    csrwr $r13, 0x40

 # li.w $r4, 0
# li.w $r5, 0
##inst test
###1
    rdcntvl.w $r13
 # or $r4, $r4, $r13
    rdcntid $r12
    bne $r12, $r30, inst_error
    rdcntvh.w $r14
 # or $r5, $r5, $r14
    rdcntid $r12
    bne $r12, $r30, inst_error
    li.w $r30, 0xffff1111
    move $r12, $r30
    csrwr $r12, 0x40
    rdcntvl.w $r15
 # or $r4, $r4, $r15
    rdcntid $r12
    bne $r12, $r30, inst_error
    rdcntvh.w $r16
 # or $r5, $r5, $r16
    rdcntid $r12
    bne $r12, $r30, inst_error
    sub.w $r13, $r15, $r13
    sub.w $r14, $r16, $r14
    bltu $r13, $r14, inst_error

###2
    li.w $r30, 0xffffffff
    move $r13, $r30
    csrwr $r13, 0x40
    li.w $r19, (0x100000 +0xd0004)
    st.w $r27, $r19, 4
    rdcntvl.w $r13
 # or $r4, $r4, $r13
    rdcntid $r12
    st.w $r27, $r19, 0
    ld.w $r17, $r19, 4
    bne $r17, $r27, inst_error
    bne $r12, $r30, inst_error
    st.w $r19, $r19, 4
    st.w $r27, $r19, 4
    rdcntvh.w $r14
 # or $r5, $r5, $r14
    rdcntid $r12
    st.w $r27, $r19, 0
    ld.w $r17, $r19, 4
    bne $r17, $r27, inst_error
    bne $r12, $r30, inst_error
    li.w $r30, 0xffff0000
    move $r12, $r30
    csrwr $r12, 0x40
    rdcntvl.w $r15
 # or $r4, $r4, $r15
    rdcntid $r12
    bne $r12, $r30, inst_error
    rdcntvh.w $r16
 # or $r5, $r5, $r16
    rdcntid $r12
    bne $r12, $r30, inst_error
    sub.w $r13, $r15, $r13
    sub.w $r14, $r16, $r14
    bltu $r13, $r14, inst_error

###3
    li.w $r30, 0xffff
    move $r13, $r30
    csrwr $r13, 0x40
    li.w $r19, 0xf
    li.w $r20, 0xf
    div.w $r19, $r13, $r18
    rdcntvl.w $r13
 # or $r4, $r4, $r13
    rdcntid $r12
    beq $r20, $r19, inst_error
    bne $r12, $r30, inst_error
    li.w $r19, 0xf
    li.w $r20, 0xf
    div.w $r19, $r13, $r18
    rdcntvh.w $r14
 # or $r5, $r5, $r14
    rdcntid $r12
    beq $r20, $r19, inst_error
    bne $r12, $r30, inst_error
    li.w $r30, 0x0
    move $r12, $r30
    csrwr $r12, 0x40
    rdcntvl.w $r15
 # or $r4, $r4, $r15
    rdcntid $r12
    bne $r12, $r30, inst_error
    rdcntvh.w $r16
 # or $r5, $r5, $r16
    rdcntid $r12
    bne $r12, $r30, inst_error
    sub.w $r13, $r15, $r13
    sub.w $r14, $r16, $r14
    bltu $r13, $r14, inst_error

###4
    li.w $r30, 0xff
    move $r13, $r30
    csrwr $r13, 0x40
    rdcntvl.w $r13
 # or $r4, $r4, $r13
    rdcntid $r12
    div.w $r19, $r12, $r18
    bne $r12, $r30, inst_error
    rdcntvh.w $r14
 # or $r5, $r5, $r14
    rdcntid $r12
    div.w $r19, $r12, $r18
    bne $r12, $r30, inst_error
    li.w $r30, 0xffff11
    move $r12, $r30
    csrwr $r12, 0x40
    rdcntvl.w $r15
 # or $r4, $r4, $r15
    rdcntid $r12
    bne $r12, $r30, inst_error
    rdcntvh.w $r16
 # or $r5, $r5, $r16
    rdcntid $r12
    bne $r12, $r30, inst_error
    sub.w $r13, $r15, $r13
    sub.w $r14, $r16, $r14
    bltu $r13, $r14, inst_error

###5
    li.w $r30, 0xf
    move $r13, $r30
    csrwr $r13, 0x40
    li.w $r19, 0xf
    li.w $r20, 0xf
    mul.w $r19, $r18, $r19
    rdcntvl.w $r13
 # or $r4, $r4, $r13
    rdcntid $r12
    beq $r20, $r19, inst_error
    bne $r12, $r30, inst_error
    li.w $r19, 0xf
    li.w $r20, 0xf
    mul.w $r19, $r18, $r19
    rdcntvh.w $r14
 # or $r5, $r5, $r14
    rdcntid $r12
    beq $r20, $r19, inst_error
    bne $r12, $r30, inst_error
    li.w $r30, 0xf11
    move $r12, $r30
    csrwr $r12, 0x40
    rdcntvl.w $r15
 # or $r4, $r4, $r15
    rdcntid $r12
    bne $r12, $r30, inst_error
    rdcntvh.w $r16
 # or $r5, $r5, $r16
    rdcntid $r12
    bne $r12, $r30, inst_error
    sub.w $r13, $r15, $r13
    sub.w $r14, $r16, $r14
    bltu $r13, $r14, inst_error

###6
    li.w $r30, 0xfffff
    move $r13, $r30
    csrwr $r13, 0x40
    rdcntvl.w $r13
 # or $r4, $r4, $r13
    rdcntid $r12
    mul.w $r19, $r12, $r18
    bne $r12, $r30, inst_error
    rdcntvh.w $r14
 # or $r5, $r5, $r14
    rdcntid $r12
    mul.w $r19, $r12, $r18
    bne $r12, $r30, inst_error
    li.w $r30, 0x11fff
    move $r12, $r30
    csrwr $r12, 0x40
    rdcntvl.w $r15
 # or $r4, $r4, $r15
    rdcntid $r12
    bne $r12, $r30, inst_error
    rdcntvh.w $r16
 # or $r5, $r5, $r16
    rdcntid $r12
    bne $r12, $r30, inst_error
    sub.w $r13, $r15, $r13
    sub.w $r14, $r16, $r14
    bltu $r13, $r14, inst_error

###7
    li.w $r30, 0x23232
    move $r13, $r30
    csrwr $r13, 0x40
    csrwr $r19, 0x6
    rdcntvl.w $r13
 # or $r4, $r4, $r13
    rdcntid $r12
    csrwr $r20, 0x6
    bne $r12, $r30, inst_error
    csrwr $r19, 0x6
    rdcntvh.w $r14
 # or $r5, $r5, $r14
    rdcntid $r12
    csrwr $r20, 0x6
    bne $r12, $r30, inst_error
    li.w $r30, 0xabab
    move $r12, $r30
    csrwr $r12, 0x40
    rdcntvl.w $r15
 # or $r4, $r4, $r15
    rdcntid $r12
    bne $r12, $r30, inst_error
    rdcntvh.w $r16
 # or $r5, $r5, $r16
    rdcntid $r12
    bne $r12, $r30, inst_error
    sub.w $r13, $r15, $r13
    sub.w $r14, $r16, $r14
    bltu $r13, $r14, inst_error

#1:
# rdcntvl.w $r13
 # or $r4, $r4, $r13
 # rdcntvh.w $r13
 # or $r5, $r5, $r13
 # li.w $r13, 0xffffffff
# bne $r13, $r4, 1b
# bne $r13, $r5, 1b

###detect exception
  bne $r25, $r0, inst_error
###score +++
  addi.w $r26, $r26, 1
###output ($r23<<24)|$r26
inst_error:
  slli.w $r13, $r23, 24
  or $r12, $r13, $r26
  st.w $r12, $r24, 0
  jirl $r0, $r1, 0
.cfi_endproc ; .size n58_rdcnt_test,.-n58_rdcnt_test;
