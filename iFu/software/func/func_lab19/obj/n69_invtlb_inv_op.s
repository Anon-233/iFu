# 1 "n69_invtlb_inv_op.S"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "n69_invtlb_inv_op.S"
# 1 "../include/asm.h" 1



# 1 "../include/regdef.h" 1
# 5 "../include/asm.h" 2
# 1 "../include/sysdep.h" 1
# 6 "../include/asm.h" 2
# 2 "n69_invtlb_inv_op.S" 2
# 1 "../include/regdef.h" 1
# 3 "n69_invtlb_inv_op.S" 2
# 1 "../include/inst_test.h" 1

# 1 "../include/cpu_cde.h" 1
# 1 "../include/lab_config.h" 1
# 2 "../include/cpu_cde.h" 2
# 3 "../include/inst_test.h" 2
# 4 "n69_invtlb_inv_op.S" 2

.text; .globl n69_invtlb_inv_op_test; .align 3; .cfi_startproc ; .type n69_invtlb_inv_op_test, @function; n69_invtlb_inv_op_test:
    li.w $r12, 0x1c008000
    csrwr $r12, 0xc

    li.w $r12, (0x100000 +0xd0000); li.w $r13, 0x3; st.w $r13, $r12, 0

    addi.w $r23, $r23 ,1
    addi.w $r25, $r0, 0x0
###
    csrrd $r17, 0x0
    andi $r17, $r17, 0x7
    la.local $r27, 1f
1:
    invtlb 0x7, $r0, $r0
    lu12i.w $r13, 0x30
    bne $r25, $r13, inst_error

    addi.w $r25, $r0, 0x0
    la.local $r27, 1f
1:
    invtlb 0x8, $r0, $r0
    lu12i.w $r13, 0x30
    bne $r25, $r13, inst_error

    addi.w $r25, $r0, 0x0
    la.local $r27, 1f
1:
    invtlb 0x9, $r0, $r0
    lu12i.w $r13, 0x30
    bne $r25, $r13, inst_error

    addi.w $r25, $r0, 0x0
    la.local $r27, 1f
1:
    invtlb 0xa, $r0, $r0
    lu12i.w $r13, 0x30
    bne $r25, $r13, inst_error

###score ++
    addi.w $r26, $r26, 1
###output ($r23<<24)|$r26
inst_error:
    slli.w $r13, $r23, 24
    or $r12, $r13, $r26
    st.w $r12, $r24, 0x0
    jirl $r0, $r1, 0x0
.cfi_endproc ; .size n69_invtlb_inv_op_test,.-n69_invtlb_inv_op_test;
