# 1 "n77_icacop_op2.S"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "n77_icacop_op2.S"
# 1 "../include/asm.h" 1



# 1 "../include/regdef.h" 1
# 5 "../include/asm.h" 2
# 1 "../include/sysdep.h" 1
# 6 "../include/asm.h" 2
# 2 "n77_icacop_op2.S" 2
# 1 "../include/regdef.h" 1
# 3 "n77_icacop_op2.S" 2
# 1 "../include/inst_test.h" 1

# 1 "../include/cpu_cde.h" 1
# 1 "../include/lab_config.h" 1
# 2 "../include/cpu_cde.h" 2
# 3 "../include/inst_test.h" 2
# 4 "n77_icacop_op2.S" 2

.text; .globl n77_icacop_op2; .align 3; .cfi_startproc ; .type n77_icacop_op2, @function; n77_icacop_op2:
    addi.w $r23, $r23, 0x1
    add.w $r25, $r0, $r0


    li.w $r12, 0x1
    csrwr $r12, 0x44

    li.w $r12, 0x1c008000
    csrwr $r12, 0xc
    li.w $r13, 0x1c000000 + 0xf000
    csrwr $r13, 0x88

    la.local $r19, start
start:
# clear DMW
    csrwr $r0, 0x180
    csrwr $r0, 0x181
 # set up the DMW, let the MAT=01(Coherent Cached)
    li.w $r13, 0xe0000000
    and $r13, $r19, $r13
    srli.w $r14, $r13, 0x4
    li.w $r15, 0x19
    or $r13, $r13, $r14
    or $r13, $r13, $r15
    csrwr $r13, 0x180
    invtlb 0x0, $r0, $r0

 # set up the CRMD, let DA=0, PG=1, and PRL=0

    li.w $r12, 0x10
    li.w $r13, 0x1f
    csrxchg $r12, $r13, 0x0

 # the size of cacop li.wne: 16Bytes( 4 insts)
    .align 4
code_block:
    b jump_point_1 #1
    add.w $r0, $r0, $r0 #2
    add.w $r0, $r0, $r0 #2
    add.w $r0, $r0, $r0 #2
    .align 4
code_to_be_changed:
    b inst_error #3
jump_point_1:
    b jump_point_2
    add.w $r0, $r0, $r0 #4
    add.w $r0, $r0, $r0 #4
    .align 4
new_code:
    b excp_test
jump_point_2:
    add.w $r0, $r0, $r0 #4
    add.w $r0, $r0, $r0 #4
    add.w $r0, $r0, $r0 #4

change_code:

# set up the DMW, let the MAT=00(Strongly-Ordered UnCached)
    li.w $r13, 0xe0000000
    and $r13, $r19, $r13
    srli.w $r14, $r13, 0x4
    li.w $r15, 0x9
    or $r13, $r13, $r14
    or $r13, $r13, $r15
    csrwr $r13, 0x180
    invtlb 0x0, $r0, $r0

 # bypass the icacop and directly write to the physical memory
    la.local $r12, code_to_be_changed
    la.local $r13, new_code
    ld.w $r14, $r13, 0x0
    li.w $r15, 0x1000
    add.w $r14, $r14, $r15
    st.w $r14, $r12, 0x0

# deal with the coherence in the old cacop in icacop by hitting
    cacop 0x10, $r12, 0x0

# set up the DMW, let the MAT=01(Coherent Cached)
    li.w $r13, 0xe0000000
    and $r13, $r19, $r13
    srli.w $r14, $r13, 0x4
    li.w $r15, 0x19
    or $r13, $r13, $r14
    or $r13, $r13, $r15
    csrwr $r13, 0x180
    invtlb 0x0, $r0, $r0

 # go back to the changed code
    b code_to_be_changed

excp_test:

# next codes are used to test if invalid addr would triger tlb error
# set PG=1, DA=0
    li.w $r12, 0x10
    li.w $r13, 0x18
    csrxchg $r12, $r13, 0x0

 # fill in an present but invalid TLB entry
    li.w $r12, 0x0c000000 ; li.w $r13, 0x80f00000 ; li.w $r14, 0x00abc040 ; li.w $r15, 0x00afc040 ; csrwr $r12, 0x10 ; csrwr $r13, 0x11 ; csrwr $r14, 0x12 ; csrwr $r15, 0x13 ; tlbwr ;
 # fill in a present and valid item and prl = 0 TLB entry
    li.w $r12, 0x0c000001 ; li.w $r13, 0xff000000 ; li.w $r14, 0x000c0041 ; li.w $r15, 0x000d0041 ; csrwr $r12, 0x10 ; csrwr $r13, 0x11 ; csrwr $r14, 0x12 ; csrwr $r15, 0x13 ; tlbwr ;

    csrrd $r12, 0x0
    li.w $r13, 0x3
    and $r17, $r12, $r13

 # test if cacop can triger tlb refill error or not
    lu12i.w $r30, 0xe
    li.w $r31, 0x2aeff << 13
    la.local $r27, tlb_refill_error
tlb_refill_error:
    cacop 0x10, $r31, 0x0
    bne $r25, $r30, inst_error
    csrrd $r12, 0x0
    li.w $r13, 0x7
    and $r12, $r12, $r13
    bne $r17, $r12, inst_error

# test if cacop can triger tlb page invalid error or not
    li.w $r12, (0x100000 +0xd0000)
    li.w $r13, 0x8
    st.w $r13, $r12, 0

    li.w $r12, (0x100000 +0xd0000)
    li.w $r13, 0x8
    st.w $r13, $r12, 0

    lu12i.w $r30, 0x1
    li.w $r31, 0x80f00000
    la.local $r27, tlb_invalid_error
tlb_invalid_error:
    cacop 0x10, $r31, 0x0
    bne $r25, $r30, inst_error
    csrrd $r12, 0x0
    li.w $r13, 0x7
    and $r12, $r12, $r13
    bne $r17, $r12, inst_error

inst_pass:
###detect exception
# bne $r25, $r0, inst_error
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
.cfi_endproc ; .size n77_icacop_op2,.-n77_icacop_op2;
