# 1 "n61_tlbsrch.S"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "n61_tlbsrch.S"
# 1 "../include/asm.h" 1



# 1 "../include/regdef.h" 1
# 5 "../include/asm.h" 2
# 1 "../include/sysdep.h" 1
# 6 "../include/asm.h" 2
# 2 "n61_tlbsrch.S" 2
# 1 "../include/regdef.h" 1
# 3 "n61_tlbsrch.S" 2
# 1 "../include/inst_test.h" 1

# 1 "../include/cpu_cde.h" 1
# 1 "../include/lab_config.h" 1
# 2 "../include/cpu_cde.h" 2
# 3 "../include/inst_test.h" 2
# 4 "n61_tlbsrch.S" 2

.text; .globl n61_tlbsrch_test; .align 3; .cfi_startproc ; .type n61_tlbsrch_test, @function; n61_tlbsrch_test:
    addi.w $r23, $r23 ,0x1
 li.w $r25, 0x0

###tlb hit: G=0
    li.w $r13, 0x000000aa; csrwr $r13, 0x18; li.w $r14, 8<<13; li.w $r15, 0x2<<13; add.w $r13, $r15, $r14; csrwr $r13, 0x11; tlbsrch; csrrd $r14, 0x10; li.w $r13, 0x00000001; bne $r14, $r13, inst_error
###tlb hit: G=1
    li.w $r13, 0x000000ff; csrwr $r13, 0x18; li.w $r14, 8<<13; li.w $r15, 0x10<<13; add.w $r13, $r15, $r14; csrwr $r13, 0x11; tlbsrch; csrrd $r14, 0x10; li.w $r13, 0x0000000f; bne $r14, $r13, inst_error
###tlb miss: no matching asid
    csrwr $r0, 0x10; li.w $r13, 0x000003f0; csrwr $r13, 0x18; li.w $r14, 8<<13; li.w $r15, 0x2<<13; add.w $r13, $r15, $r14; csrwr $r13, 0x11; tlbsrch; csrrd $r14, 0x10; srli.w $r14, $r14, 31; li.w $r13, 0x1; bne $r14, $r13, inst_error
###tlb miss: no matching VPN
    csrwr $r0, 0x10; li.w $r13, 0x000000aa; csrwr $r13, 0x18; li.w $r14, 8<<13; li.w $r15, 0xff<<13; add.w $r13, $r15, $r14; csrwr $r13, 0x11; tlbsrch; csrrd $r14, 0x10; srli.w $r14, $r14, 31; li.w $r13, 0x1; bne $r14, $r13, inst_error

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
.cfi_endproc ; .size n61_tlbsrch_test,.-n61_tlbsrch_test;
