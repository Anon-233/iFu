# 1 "n70_tlb_4MB.S"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "n70_tlb_4MB.S"
# 1 "../include/asm.h" 1



# 1 "../include/regdef.h" 1
# 5 "../include/asm.h" 2
# 1 "../include/sysdep.h" 1
# 6 "../include/asm.h" 2
# 2 "n70_tlb_4MB.S" 2
# 1 "../include/regdef.h" 1
# 3 "n70_tlb_4MB.S" 2
# 1 "../include/inst_test.h" 1

# 1 "../include/cpu_cde.h" 1
# 1 "../include/lab_config.h" 1
# 2 "../include/cpu_cde.h" 2
# 3 "../include/inst_test.h" 2
# 4 "n70_tlb_4MB.S" 2

.text; .globl n70_tlb_4MB; .align 3; .cfi_startproc ; .type n70_tlb_4MB, @function; n70_tlb_4MB:
    addi.w $r23, $r23 ,0x1
 li.w $r25, 0x0

    invtlb 0x0, $r0, $r0

    li.w $r12, 0x15000000 #index with 4MB PS
    li.w $r14, 8<<23
    li.w $r15, 1<<23
    add.w $r13, $r14, $r15 #VPN

    li.w $r14, 0x000000aa
    csrwr $r14, 0x18

###TLB item 1
    li.w $r16, 0x00003400 ; li.w $r17, 0x00007000 ; addi.w $r14, $r12, 0x0 ; addi.w $r15, $r13, 0x0 ; csrwr $r14, 0x10 ; csrwr $r15, 0x11 ; csrwr $r16, 0x12 ; csrwr $r17, 0x13 ; tlbwr ; addi.w $r12, $r12, 0x1 ; li.w $r17, 1<<23 ; add.w $r13, $r13, $r17
###TLB item 2
    li.w $r16, 0x00003500 ; li.w $r17, 0x00007100 ; addi.w $r14, $r12, 0x0 ; addi.w $r15, $r13, 0x0 ; csrwr $r14, 0x10 ; csrwr $r15, 0x11 ; csrwr $r16, 0x12 ; csrwr $r17, 0x13 ; tlbwr ; addi.w $r12, $r12, 0x1 ; li.w $r17, 1<<23 ; add.w $r13, $r13, $r17
###TLB item 3
    li.w $r16, 0x00003600 ; li.w $r17, 0x00007200 ; addi.w $r14, $r12, 0x0 ; addi.w $r15, $r13, 0x0 ; csrwr $r14, 0x10 ; csrwr $r15, 0x11 ; csrwr $r16, 0x12 ; csrwr $r17, 0x13 ; tlbwr ; addi.w $r12, $r12, 0x1 ; li.w $r17, 1<<23 ; add.w $r13, $r13, $r17
###TLB item 4 G=1
    li.w $r16, 0x00003640 ; li.w $r17, 0x00007240 ; addi.w $r14, $r12, 0x0 ; addi.w $r15, $r13, 0x0 ; csrwr $r14, 0x10 ; csrwr $r15, 0x11 ; csrwr $r16, 0x12 ; csrwr $r17, 0x13 ; tlbwr ; addi.w $r12, $r12, 0x1 ; li.w $r17, 1<<23 ; add.w $r13, $r13, $r17

    csrwr $r0, 0x11
    csrwr $r0, 0x12
    csrwr $r0, 0x13
    csrwr $r0, 0x10

###tlb hit: G=0
    li.w $r13, 0x000000aa; csrwr $r13, 0x18; li.w $r14, 8<<23; li.w $r15, 0x1<<23; add.w $r13, $r15, $r14; csrwr $r13, 0x11; tlbsrch; csrrd $r14, 0x10; li.w $r13, 0x00000000; bne $r14, $r13, inst_error
    li.w $r13, 0x000000aa; csrwr $r13, 0x18; li.w $r14, 8<<23; li.w $r15, 0x2<<23; add.w $r13, $r15, $r14; csrwr $r13, 0x11; tlbsrch; csrrd $r14, 0x10; li.w $r13, 0x00000001; bne $r14, $r13, inst_error
    li.w $r13, 0x000000aa; csrwr $r13, 0x18; li.w $r14, 8<<23; li.w $r15, 0x3<<23; add.w $r13, $r15, $r14; csrwr $r13, 0x11; tlbsrch; csrrd $r14, 0x10; li.w $r13, 0x00000002; bne $r14, $r13, inst_error
###tlb hit: G=1
    li.w $r13, 0x000000bb; csrwr $r13, 0x18; li.w $r14, 8<<23; li.w $r15, 0x4<<23; add.w $r13, $r15, $r14; csrwr $r13, 0x11; tlbsrch; csrrd $r14, 0x10; li.w $r13, 0x00000003; bne $r14, $r13, inst_error
###tlb miss: no matching asid
    csrwr $r0, 0x10; li.w $r13, 0x000003f0; csrwr $r13, 0x18; li.w $r14, 8<<23; li.w $r15, 0x2<<23; add.w $r13, $r15, $r14; csrwr $r13, 0x11; tlbsrch; csrrd $r14, 0x10; srli.w $r14, $r14, 31; li.w $r13, 0x1; bne $r14, $r13, inst_error
###tlb miss: no matching VPN
    csrwr $r0, 0x10; li.w $r13, 0x000000aa; csrwr $r13, 0x18; li.w $r14, 8<<23; li.w $r15, 0x7f<<23; add.w $r13, $r15, $r14; csrwr $r13, 0x11; tlbsrch; csrrd $r14, 0x10; srli.w $r14, $r14, 31; li.w $r13, 0x1; bne $r14, $r13, inst_error

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
.cfi_endproc ; .size n70_tlb_4MB,.-n70_tlb_4MB;
