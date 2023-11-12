# 1 "n76_dcacop_op1.S"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "n76_dcacop_op1.S"
# 1 "../include/asm.h" 1



# 1 "../include/regdef.h" 1
# 5 "../include/asm.h" 2
# 1 "../include/sysdep.h" 1
# 6 "../include/asm.h" 2
# 2 "n76_dcacop_op1.S" 2
# 1 "../include/regdef.h" 1
# 3 "n76_dcacop_op1.S" 2
# 1 "../include/inst_test.h" 1

# 1 "../include/cpu_cde.h" 1
# 1 "../include/lab_config.h" 1
# 2 "../include/cpu_cde.h" 2
# 3 "../include/inst_test.h" 2
# 4 "n76_dcacop_op1.S" 2

.text; .globl n76_dcacop_op1; .align 3; .cfi_startproc ; .type n76_dcacop_op1, @function; n76_dcacop_op1:
    addi.w $r23, $r23, 0x1
    add.w $r25, $r0, $r0

    la.local $r19, start
start:
# clear DMW
    csrwr $r0, 0x180
    csrwr $r0, 0x181
 # set up the DMW, let the MAT=01(Coherent Cached)
    li.w $r13, 0xe0000000
    and $r13, $r19, $r13
    srli.w $r14, $r13, 0x4
    li.w $r15, 0x11
    or $r13, $r13, $r14
    or $r13, $r13, $r15
    csrwr $r13, 0x181
    invtlb 0x0, $r0, $r0

    li.w $r19, 0xd0100000
# set up the inst DMW, let the MAT=01(Coherent Cached)
    li.w $r13, 0xe0000000
    and $r13, $r19, $r13
    srli.w $r14, $r13, 0x4
    li.w $r15, 0x11
    or $r13, $r13, $r14
    or $r13, $r13, $r15
    csrwr $r13, 0x180
    invtlb 0x0, $r0, $r0

 # set up the PRMD, let DA=0, PG=1, and PRL=0

    li.w $r12, 0x10
    li.w $r13, 0x1f
    csrxchg $r12, $r13, 0x0

 # the size of cacop li.wne: 16Bytes( 4 insts)

    li.w $r12, 0xd0100000
    li.w $r13, 0xffffffff
    st.w $r13, $r12, 0x0
    ld.w $r13, $r12, 0x0
    li.w $r13, 0xeeeeeeee
    st.w $r13, $r12, 0x0

# deal with the coherence in the old cacop in dcacop by index

    li.w $r12, 0xd0100000

    li.w $r13, 0xffffffff
    slli.w $r13, $r13, 4
    li.w $r14, 0xffffffff
    slli.w $r14, $r14, 4 +8
    li.w $r15, 0x0
    nor $r14, $r15, $r14
    and $r13, $r13, $r14

    and $r12, $r12, $r13

    li.w $r13, 0x0
    li.w $r14, 2
invalid_cache_line:
    cacop 0x09, $r12, 0x0
    addi.w $r12, $r12, 0x1
    addi.w $r13, $r13, 0x1
    bne $r13, $r14, invalid_cache_line

# set up the DMW, let the MAT=00(Strongly-Ordered UnCached)
    li.w $r13, 0xe0000000
    and $r13, $r19, $r13
    srli.w $r14, $r13, 0x4
    li.w $r15, 0x1
    or $r13, $r13, $r14
    or $r13, $r13, $r15
    csrwr $r13, 0x180
    invtlb 0x0, $r0, $r0

    li.w $r12, 0xd0100000
    ld.w $r13, $r12, 0x0
    li.w $r14, 0xeeeeeeee
    bne $r13, $r14, inst_error

inst_pass:
###detect exception
    bne $r25, $r0, inst_error
###score ++
    addi.w $r26, $r26, 0x1
###output
inst_error:
    li.w $r12, 0x8
    li.w $r13, 0x1f
    csrxchg $r12, $r13, 0x0

    slli.w $r13, $r23, 24
    or $r12, $r13, $r26
    st.w $r12, $r24, 0x0
    jirl $r0, $r1, 0x0
.cfi_endproc ; .size n76_dcacop_op1,.-n76_dcacop_op1;
