# 1 "n72_dmw_test.S"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "n72_dmw_test.S"
# 1 "../include/asm.h" 1



# 1 "../include/regdef.h" 1
# 5 "../include/asm.h" 2
# 1 "../include/sysdep.h" 1
# 6 "../include/asm.h" 2
# 2 "n72_dmw_test.S" 2
# 1 "../include/regdef.h" 1
# 3 "n72_dmw_test.S" 2
# 1 "../include/inst_test.h" 1

# 1 "../include/cpu_cde.h" 1
# 1 "../include/lab_config.h" 1
# 2 "../include/cpu_cde.h" 2
# 3 "../include/inst_test.h" 2
# 4 "n72_dmw_test.S" 2

.text; .globl n72_dmw_test; .align 3; .cfi_startproc ; .type n72_dmw_test, @function; n72_dmw_test:
    addi.w $r23, $r23 ,0x1
 li.w $r25, 0x0



    li.w $r12, 0xf
    li.w $r13, 0xe0000000
    st.w $r12, $r13, 0x0


    li.w $r20, 0x4c000020
    li.w $r13, 0xc0000000
    st.w $r20, $r13, 0x0

    li.w $r19, 0xbb
    li.w $r13, 0x80000000
    st.w $r19, $r13, 0x0


    li.w $r12, 0xc
    li.w $r13, 0x90000000
    st.w $r12, $r13, 0x0


    li.w $r12, 0xec000009
    csrwr $r12, 0x180

    invtlb 0x0, $r0, $r0

    li.w $r12, 0x48000008
    csrwr $r12, 0x181

    csrwr $r0, 0x11

    invtlb 0x0, $r0, $r0


    la.local $r12, 1f
1:
    add.w $r0, $r0, $r0
    li.w $r13, 0xffffe000
    and $r16, $r12, $r13
    srli.w $r16, $r16, 0x4
    li.w $r13, 0x4d
    or $r13, $r16, $r13
    li.w $r14, 0x14d
    or $r14, $r16, $r14
    li.w $r15, 0x0c000000
    csrwr $r15, 0x10
    csrwr $r12, 0x11
    csrwr $r13, 0x12
    csrwr $r14, 0x13
    tlbwr

    la.local $r12, 1b
    li.w $r13, 0x2000
    add.w $r12, $r12, $r13
    li.w $r13, 0xffffe000
    and $r16, $r12, $r13
    srli.w $r16, $r16, 0x4
    li.w $r13, 0x4d
    or $r13, $r16, $r13
    li.w $r14, 0x14d
    or $r14, $r16, $r14
    li.w $r15, 0x0c000001
    csrwr $r15, 0x10
    csrwr $r12, 0x11
    csrwr $r13, 0x12
    csrwr $r14, 0x13
    tlbwr

    li.w $r12, (0x100000 +0xd0000)
    li.w $r13, 0xffffe000
    and $r16, $r12, $r13
    srli.w $r16, $r16, 0x4
    li.w $r13, 0x4f
    or $r13, $r16, $r13
    li.w $r14, 0x14f
    or $r14, $r16, $r14
    li.w $r15, 0x0c000002
    csrwr $r15, 0x10
    csrwr $r12, 0x11
    csrwr $r13, 0x12
    csrwr $r14, 0x13
    tlbwr

    li.w $r12, 0x1c008000
    li.w $r13, 0xffffe000
    and $r16, $r12, $r13
    srli.w $r16, $r16, 0x4
    li.w $r13, 0x4d
    or $r13, $r16, $r13
    li.w $r14, 0x14d
    or $r14, $r16, $r14
    li.w $r15, 0x0c000003
    csrwr $r15, 0x10
    csrwr $r12, 0x11
    csrwr $r13, 0x12
    csrwr $r14, 0x13
    tlbwr


    li.w $r12, 0x0c000004 ; li.w $r13, 0xe0000000 ; li.w $r14, 0x900004d ; li.w $r15, 0x00000000 ; csrwr $r12, 0x10 ; csrwr $r13, 0x11 ; csrwr $r14, 0x12 ; csrwr $r15, 0x13 ; tlbwr ;
    csrwr $r0, 0x11


    li.w $r12, 0x10
    li.w $r13, 0x1f
    csrxchg $r12, $r13, 0x0

    li.w $r12, 0xe0000000
    ld.w $r15, $r12, 0x0


    li.w $r12, 0x3
    li.w $r13, 0x3
    csrxchg $r12, $r13, 0x0

    li.w $r12, 0xe0000000
    ld.w $r12, $r12, 0x0
    bne $r12, $r15, inst_error

    add.w $r14, $r1, $r0
    li.w $r12, 0xe0000000
    jirl $r1, $r12, 0
    add.w $r1, $r14, $r0






    li.w $r12, 0x40000000
    ld.w $r18, $r12, 0x0

    bne $r25, $r0, inst_error
    li.w $r12, (0x100000 +0xd0000); li.w $r25, 0xf; st.w $r25, $r12, 0
    syscall 0
    li.w $r25, 0x0


    li.w $r12, 0x08
    li.w $r13, 0x1f
    csrxchg $r12, $r13, 0x0

    bne $r15, $r20, inst_error
    bne $r18, $r19, inst_error

###detect exception
    bne $r25, $r0, inst_error
###score ++
    addi.w $r26, $r26, 1
###output ($r23<<24)|$r26
inst_error:
    slli.w $r15, $r23, 24
    or $r12, $r15, $r26
    st.w $r12, $r24, 0x0
    jirl $r0, $r1, 0x0
.cfi_endproc ; .size n72_dmw_test,.-n72_dmw_test;
