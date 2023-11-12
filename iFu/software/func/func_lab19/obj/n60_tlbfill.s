# 1 "n60_tlbfill.S"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "n60_tlbfill.S"
# 1 "../include/asm.h" 1



# 1 "../include/regdef.h" 1
# 5 "../include/asm.h" 2
# 1 "../include/sysdep.h" 1
# 6 "../include/asm.h" 2
# 2 "n60_tlbfill.S" 2
# 1 "../include/regdef.h" 1
# 3 "n60_tlbfill.S" 2
# 1 "../include/inst_test.h" 1

# 1 "../include/cpu_cde.h" 1
# 1 "../include/lab_config.h" 1
# 2 "../include/cpu_cde.h" 2
# 3 "../include/inst_test.h" 2
# 4 "n60_tlbfill.S" 2

.text; .globl n60_tlbfill_test; .align 3; .cfi_startproc ; .type n60_tlbfill_test, @function; n60_tlbfill_test:
    addi.w $r23, $r23 ,0x1
 li.w $r25, 0x0

    li.w $r12, 0x0c000000 #index
    li.w $r13, 0xabc<<13 #VPN
    li.w $r14, 0x0fabc041 #PFN1
    li.w $r15, 0x0ffbc041 #PFN1
    csrwr $r12, 0x10
    csrwr $r13, 0x11
    csrwr $r14, 0x12
    csrwr $r15, 0x13
    tlbfill
    tlbfill
    tlbfill
    tlbfill

    li.w $r18, 32
    li.w $r17, 0x0
    li.w $r16, 0x0
    li.w $r12, 0x0c000000

2:
    addi.w $r13, $r12, 0x0
    csrwr $r13, 0x10
    tlbrd
    csrrd $r13, 0x11
    li.w $r14, 0xffffe000
    and $r13, $r13, $r14
    li.w $r14, 0xabc << 13
    bne $r13, $r14, 1f
    addi.w $r17, $r17, 0x1
1:
    addi.w $r16, $r16, 0x1
    addi.w $r12, $r12, 0x1
    bne $r16, $r18, 2b

    li.w $r13, 0x0
    beq $r17, $r13, inst_error

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
.cfi_endproc ; .size n60_tlbfill_test,.-n60_tlbfill_test;
