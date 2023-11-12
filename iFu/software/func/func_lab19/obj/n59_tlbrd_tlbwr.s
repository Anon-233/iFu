# 1 "n59_tlbrd_tlbwr.S"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "n59_tlbrd_tlbwr.S"
# 1 "../include/asm.h" 1



# 1 "../include/regdef.h" 1
# 5 "../include/asm.h" 2
# 1 "../include/sysdep.h" 1
# 6 "../include/asm.h" 2
# 2 "n59_tlbrd_tlbwr.S" 2
# 1 "../include/regdef.h" 1
# 3 "n59_tlbrd_tlbwr.S" 2

.text; .globl n59_tlbrd_tlbwr_test; .align 3; .cfi_startproc ; .type n59_tlbrd_tlbwr_test, @function; n59_tlbrd_tlbwr_test:

    addi.w $r23, $r23 ,1
    li.w $r25, 0x0

###read an invalid TLB item
    li.w $r12, 0x8c000000 #index
 li.w $r13, 8<<13
 li.w $r14, 1<<13
    add.w $r13, $r13, $r14 #VPN
    li.w $r14, 0x0034ab00 #PPN1
    li.w $r15, 0x00ffab00 #PPN2
    csrwr $r12, 0x10
    csrwr $r13, 0x11
    csrwr $r14, 0x12
    csrwr $r15, 0x13
    tlbwr

    li.w $r12, 0x0c000000 #index
    csrwr $r12, 0x10
    tlbrd
    csrrd $r13, 0x11
    bne $r13, $r0, inst_error
    csrrd $r13, 0x12
    bne $r13, $r0, inst_error
    csrrd $r13, 0x13
    bne $r13, $r0, inst_error
    csrrd $r13, 0x10
    li.w $r14, 0x80000000
    bne $r13, $r14, inst_error

###recover the TLB item
    li.w $r12, 0x0c000000 #index
 li.w $r13, 8<<13
 li.w $r14, 1<<13
    add.w $r13, $r13, $r14 #VPN
    li.w $r14, 0x0034ab00 #PPN1
    li.w $r15, 0x00ffab00 #PPN2
    csrwr $r12, 0x10
    csrwr $r13, 0x11
    csrwr $r14, 0x12
    csrwr $r15, 0x13
    tlbwr

###read a valid TLB item
    li.w $r12, 0x0c000000
    csrwr $r12, 0x10
    tlbrd
    csrrd $r13, 0x11
    li.w $r14, 0x00012000
    bne $r13, $r14, inst_error
    csrrd $r13, 0x12
    li.w $r14, 0x0034ab00
    bne $r13, $r14, inst_error
    csrrd $r13, 0x13
    li.w $r14, 0x00ffab00
    bne $r13, $r14, inst_error
    csrrd $r13, 0x10
    li.w $r14, 0x0c000000
    bne $r13, $r14, inst_error

###read a valid TLB item
    li.w $r12, 0x0c000001
    csrwr $r12, 0x10
    tlbrd
    csrrd $r13, 0x11
    li.w $r14, 0x00014000
    bne $r13, $r14, inst_error
    csrrd $r13, 0x12
    li.w $r14, 0x0035ab00
    bne $r13, $r14, inst_error
    csrrd $r13, 0x13
    li.w $r14, 0x0100ab00
    bne $r13, $r14, inst_error
    csrrd $r13, 0x10
    li.w $r14, 0x0c000001
    bne $r13, $r14, inst_error

###detect exception
    bne $r25, $r0, inst_error
###score ++
    addi.w $r26, $r26, 1
###output ($r23<<24)|$r26
inst_error:
    slli.w $r13, $r23, 24
    or $r12, $r13, $r26
    st.w $r12, $r24, 0x0
    jirl $r0, $r1, 0x0

.cfi_endproc ; .size n59_tlbrd_tlbwr_test,.-n59_tlbrd_tlbwr_test;
