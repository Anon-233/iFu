# 1 "tlb_initialization.S"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "tlb_initialization.S"
# 1 "../include/asm.h" 1



# 1 "../include/regdef.h" 1
# 5 "../include/asm.h" 2
# 1 "../include/sysdep.h" 1
# 6 "../include/asm.h" 2
# 2 "tlb_initialization.S" 2
# 1 "../include/regdef.h" 1
# 3 "tlb_initialization.S" 2
# 1 "../include/inst_test.h" 1

# 1 "../include/cpu_cde.h" 1
# 1 "../include/lab_config.h" 1
# 2 "../include/cpu_cde.h" 2
# 3 "../include/inst_test.h" 2
# 4 "tlb_initialization.S" 2

.text; .globl tlb_initialization; .align 3; .cfi_startproc ; .type tlb_initialization, @function; tlb_initialization:

 # addi.w $r23, $r23 ,1
# li.w $r25, 0x0

    li.w $r12, 0x0c000000 #index
    li.w $r14, 8<<13
    li.w $r15, 1<<13
    add.w $r13, $r14, $r15 #VPN

    li.w $r14, 0x000000aa
    csrwr $r14, 0x18

    invtlb 0, $r0, $r0

###TLB item 1
    li.w $r16, 0x0034ab00 ; li.w $r17, 0x00ffab00 ; addi.w $r14, $r12, 0x0 ; addi.w $r15, $r13, 0x0 ; csrwr $r14, 0x10 ; csrwr $r15, 0x11 ; csrwr $r16, 0x12 ; csrwr $r17, 0x13 ; tlbwr ; addi.w $r12, $r12, 0x1 ; li.w $r17, 1<<13 ; add.w $r13, $r13, $r17
###TLB item 2
    li.w $r16, 0x0035ab00 ; li.w $r17, 0x0100ab00 ; addi.w $r14, $r12, 0x0 ; addi.w $r15, $r13, 0x0 ; csrwr $r14, 0x10 ; csrwr $r15, 0x11 ; csrwr $r16, 0x12 ; csrwr $r17, 0x13 ; tlbwr ; addi.w $r12, $r12, 0x1 ; li.w $r17, 1<<13 ; add.w $r13, $r13, $r17
###TLB item 3
    li.w $r16, 0x0036ab00 ; li.w $r17, 0x0101ab00 ; addi.w $r14, $r12, 0x0 ; addi.w $r15, $r13, 0x0 ; csrwr $r14, 0x10 ; csrwr $r15, 0x11 ; csrwr $r16, 0x12 ; csrwr $r17, 0x13 ; tlbwr ; addi.w $r12, $r12, 0x1 ; li.w $r17, 1<<13 ; add.w $r13, $r13, $r17
###TLB item 4
    li.w $r16, 0x0037ab00 ; li.w $r17, 0x0102ab00 ; addi.w $r14, $r12, 0x0 ; addi.w $r15, $r13, 0x0 ; csrwr $r14, 0x10 ; csrwr $r15, 0x11 ; csrwr $r16, 0x12 ; csrwr $r17, 0x13 ; tlbwr ; addi.w $r12, $r12, 0x1 ; li.w $r17, 1<<13 ; add.w $r13, $r13, $r17
####TLB item 5
# li.w $r16, 0x0038ab00 ; li.w $r17, 0x0103ab00 ; addi.w $r14, $r12, 0x0 ; addi.w $r15, $r13, 0x0 ; csrwr $r14, 0x10 ; csrwr $r15, 0x11 ; csrwr $r16, 0x12 ; csrwr $r17, 0x13 ; tlbwr ; addi.w $r12, $r12, 0x1 ; li.w $r17, 1<<13 ; add.w $r13, $r13, $r17
####TLB item 6
# li.w $r16, 0x0039ab00 ; li.w $r17, 0x0104ab00 ; addi.w $r14, $r12, 0x0 ; addi.w $r15, $r13, 0x0 ; csrwr $r14, 0x10 ; csrwr $r15, 0x11 ; csrwr $r16, 0x12 ; csrwr $r17, 0x13 ; tlbwr ; addi.w $r12, $r12, 0x1 ; li.w $r17, 1<<13 ; add.w $r13, $r13, $r17
####TLB item 7
# li.w $r16, 0x003aab00 ; li.w $r17, 0x00ffab00 ; addi.w $r14, $r12, 0x0 ; addi.w $r15, $r13, 0x0 ; csrwr $r14, 0x10 ; csrwr $r15, 0x11 ; csrwr $r16, 0x12 ; csrwr $r17, 0x13 ; tlbwr ; addi.w $r12, $r12, 0x1 ; li.w $r17, 1<<13 ; add.w $r13, $r13, $r17
####TLB item 8
# li.w $r16, 0x0134ab00 ; li.w $r17, 0x01ffab00 ; addi.w $r14, $r12, 0x0 ; addi.w $r15, $r13, 0x0 ; csrwr $r14, 0x10 ; csrwr $r15, 0x11 ; csrwr $r16, 0x12 ; csrwr $r17, 0x13 ; tlbwr ; addi.w $r12, $r12, 0x1 ; li.w $r17, 1<<13 ; add.w $r13, $r13, $r17
####TLB item 9
# li.w $r16, 0x0234ab00 ; li.w $r17, 0x02ffab00 ; addi.w $r14, $r12, 0x0 ; addi.w $r15, $r13, 0x0 ; csrwr $r14, 0x10 ; csrwr $r15, 0x11 ; csrwr $r16, 0x12 ; csrwr $r17, 0x13 ; tlbwr ; addi.w $r12, $r12, 0x1 ; li.w $r17, 1<<13 ; add.w $r13, $r13, $r17
####TLB item 10
# li.w $r16, 0x0334ab00 ; li.w $r17, 0x03ffab00 ; addi.w $r14, $r12, 0x0 ; addi.w $r15, $r13, 0x0 ; csrwr $r14, 0x10 ; csrwr $r15, 0x11 ; csrwr $r16, 0x12 ; csrwr $r17, 0x13 ; tlbwr ; addi.w $r12, $r12, 0x1 ; li.w $r17, 1<<13 ; add.w $r13, $r13, $r17

    li.w $r14, 0x000000ab
    csrwr $r14, 0x18

###TLB item 5
    li.w $r16, 0x0038ab00 ; li.w $r17, 0x0103ab00 ; addi.w $r14, $r12, 0x0 ; addi.w $r15, $r13, 0x0 ; csrwr $r14, 0x10 ; csrwr $r15, 0x11 ; csrwr $r16, 0x12 ; csrwr $r17, 0x13 ; tlbwr ; addi.w $r12, $r12, 0x1 ; li.w $r17, 1<<13 ; add.w $r13, $r13, $r17
###TLB item 6
    li.w $r16, 0x0039ab00 ; li.w $r17, 0x0104ab00 ; addi.w $r14, $r12, 0x0 ; addi.w $r15, $r13, 0x0 ; csrwr $r14, 0x10 ; csrwr $r15, 0x11 ; csrwr $r16, 0x12 ; csrwr $r17, 0x13 ; tlbwr ; addi.w $r12, $r12, 0x1 ; li.w $r17, 1<<13 ; add.w $r13, $r13, $r17
###TLB item 7
    li.w $r16, 0x003aab00 ; li.w $r17, 0x00ffab00 ; addi.w $r14, $r12, 0x0 ; addi.w $r15, $r13, 0x0 ; csrwr $r14, 0x10 ; csrwr $r15, 0x11 ; csrwr $r16, 0x12 ; csrwr $r17, 0x13 ; tlbwr ; addi.w $r12, $r12, 0x1 ; li.w $r17, 1<<13 ; add.w $r13, $r13, $r17
###TLB item 8
    li.w $r16, 0x0134ab00 ; li.w $r17, 0x01ffab00 ; addi.w $r14, $r12, 0x0 ; addi.w $r15, $r13, 0x0 ; csrwr $r14, 0x10 ; csrwr $r15, 0x11 ; csrwr $r16, 0x12 ; csrwr $r17, 0x13 ; tlbwr ; addi.w $r12, $r12, 0x1 ; li.w $r17, 1<<13 ; add.w $r13, $r13, $r17
####TLB item 15
# li.w $r16, 0x0834ab00 ; li.w $r17, 0x08ffab00 ; addi.w $r14, $r12, 0x0 ; addi.w $r15, $r13, 0x0 ; csrwr $r14, 0x10 ; csrwr $r15, 0x11 ; csrwr $r16, 0x12 ; csrwr $r17, 0x13 ; tlbwr ; addi.w $r12, $r12, 0x1 ; li.w $r17, 1<<13 ; add.w $r13, $r13, $r17
####TLB item 16
# li.w $r16, 0x0934ab00 ; li.w $r17, 0x09ffab00 ; addi.w $r14, $r12, 0x0 ; addi.w $r15, $r13, 0x0 ; csrwr $r14, 0x10 ; csrwr $r15, 0x11 ; csrwr $r16, 0x12 ; csrwr $r17, 0x13 ; tlbwr ; addi.w $r12, $r12, 0x1 ; li.w $r17, 1<<13 ; add.w $r13, $r13, $r17
####TLB item 17
# li.w $r16, 0x0a34ab00 ; li.w $r17, 0x0affab00 ; addi.w $r14, $r12, 0x0 ; addi.w $r15, $r13, 0x0 ; csrwr $r14, 0x10 ; csrwr $r15, 0x11 ; csrwr $r16, 0x12 ; csrwr $r17, 0x13 ; tlbwr ; addi.w $r12, $r12, 0x1 ; li.w $r17, 1<<13 ; add.w $r13, $r13, $r17
####TLB item 18
# li.w $r16, 0x0b34ab00 ; li.w $r17, 0x0bffab00 ; addi.w $r14, $r12, 0x0 ; addi.w $r15, $r13, 0x0 ; csrwr $r14, 0x10 ; csrwr $r15, 0x11 ; csrwr $r16, 0x12 ; csrwr $r17, 0x13 ; tlbwr ; addi.w $r12, $r12, 0x1 ; li.w $r17, 1<<13 ; add.w $r13, $r13, $r17
####TLB item 19
# li.w $r16, 0x0c34ab00 ; li.w $r17, 0x0cffab00 ; addi.w $r14, $r12, 0x0 ; addi.w $r15, $r13, 0x0 ; csrwr $r14, 0x10 ; csrwr $r15, 0x11 ; csrwr $r16, 0x12 ; csrwr $r17, 0x13 ; tlbwr ; addi.w $r12, $r12, 0x1 ; li.w $r17, 1<<13 ; add.w $r13, $r13, $r17
####TLB item 20
# li.w $r16, 0x0d34ab00 ; li.w $r17, 0x0dffab00 ; addi.w $r14, $r12, 0x0 ; addi.w $r15, $r13, 0x0 ; csrwr $r14, 0x10 ; csrwr $r15, 0x11 ; csrwr $r16, 0x12 ; csrwr $r17, 0x13 ; tlbwr ; addi.w $r12, $r12, 0x1 ; li.w $r17, 1<<13 ; add.w $r13, $r13, $r17

    li.w $r14, 0x000000ac
    csrwr $r14, 0x18

###TLB item 9
    li.w $r16, 0x0e34ab00 ; li.w $r17, 0x0effab00 ; addi.w $r14, $r12, 0x0 ; addi.w $r15, $r13, 0x0 ; csrwr $r14, 0x10 ; csrwr $r15, 0x11 ; csrwr $r16, 0x12 ; csrwr $r17, 0x13 ; tlbwr ; addi.w $r12, $r12, 0x1 ; li.w $r17, 1<<13 ; add.w $r13, $r13, $r17
###TLB item 10
    li.w $r16, 0x0f34ab00 ; li.w $r17, 0x0fffab00 ; addi.w $r14, $r12, 0x0 ; addi.w $r15, $r13, 0x0 ; csrwr $r14, 0x10 ; csrwr $r15, 0x11 ; csrwr $r16, 0x12 ; csrwr $r17, 0x13 ; tlbwr ; addi.w $r12, $r12, 0x1 ; li.w $r17, 1<<13 ; add.w $r13, $r13, $r17
###TLB item 11
    li.w $r16, 0x034ab100 ; li.w $r17, 0x0ffab100 ; addi.w $r14, $r12, 0x0 ; addi.w $r15, $r13, 0x0 ; csrwr $r14, 0x10 ; csrwr $r15, 0x11 ; csrwr $r16, 0x12 ; csrwr $r17, 0x13 ; tlbwr ; addi.w $r12, $r12, 0x1 ; li.w $r17, 1<<13 ; add.w $r13, $r13, $r17
###TLB item 12
    li.w $r16, 0x034ab200 ; li.w $r17, 0x0ffab200 ; addi.w $r14, $r12, 0x0 ; addi.w $r15, $r13, 0x0 ; csrwr $r14, 0x10 ; csrwr $r15, 0x11 ; csrwr $r16, 0x12 ; csrwr $r17, 0x13 ; tlbwr ; addi.w $r12, $r12, 0x1 ; li.w $r17, 1<<13 ; add.w $r13, $r13, $r17
####TLB item 25
# li.w $r16, 0x034ab300 ; li.w $r17, 0x0ffab300 ; addi.w $r14, $r12, 0x0 ; addi.w $r15, $r13, 0x0 ; csrwr $r14, 0x10 ; csrwr $r15, 0x11 ; csrwr $r16, 0x12 ; csrwr $r17, 0x13 ; tlbwr ; addi.w $r12, $r12, 0x1 ; li.w $r17, 1<<13 ; add.w $r13, $r13, $r17
####TLB item 26
# li.w $r16, 0x034ab400 ; li.w $r17, 0x0ffab400 ; addi.w $r14, $r12, 0x0 ; addi.w $r15, $r13, 0x0 ; csrwr $r14, 0x10 ; csrwr $r15, 0x11 ; csrwr $r16, 0x12 ; csrwr $r17, 0x13 ; tlbwr ; addi.w $r12, $r12, 0x1 ; li.w $r17, 1<<13 ; add.w $r13, $r13, $r17
####TLB item 27
# li.w $r16, 0x034ab500 ; li.w $r17, 0x0ffab500 ; addi.w $r14, $r12, 0x0 ; addi.w $r15, $r13, 0x0 ; csrwr $r14, 0x10 ; csrwr $r15, 0x11 ; csrwr $r16, 0x12 ; csrwr $r17, 0x13 ; tlbwr ; addi.w $r12, $r12, 0x1 ; li.w $r17, 1<<13 ; add.w $r13, $r13, $r17
####TLB item 28
# li.w $r16, 0x034ab600 ; li.w $r17, 0x0ffab600 ; addi.w $r14, $r12, 0x0 ; addi.w $r15, $r13, 0x0 ; csrwr $r14, 0x10 ; csrwr $r15, 0x11 ; csrwr $r16, 0x12 ; csrwr $r17, 0x13 ; tlbwr ; addi.w $r12, $r12, 0x1 ; li.w $r17, 1<<13 ; add.w $r13, $r13, $r17
####TLB item 29
# li.w $r16, 0x034ab700 ; li.w $r17, 0x0ffab700 ; addi.w $r14, $r12, 0x0 ; addi.w $r15, $r13, 0x0 ; csrwr $r14, 0x10 ; csrwr $r15, 0x11 ; csrwr $r16, 0x12 ; csrwr $r17, 0x13 ; tlbwr ; addi.w $r12, $r12, 0x1 ; li.w $r17, 1<<13 ; add.w $r13, $r13, $r17
####TLB item 30
# li.w $r16, 0x034ab800 ; li.w $r17, 0x0ffab800 ; addi.w $r14, $r12, 0x0 ; addi.w $r15, $r13, 0x0 ; csrwr $r14, 0x10 ; csrwr $r15, 0x11 ; csrwr $r16, 0x12 ; csrwr $r17, 0x13 ; tlbwr ; addi.w $r12, $r12, 0x1 ; li.w $r17, 1<<13 ; add.w $r13, $r13, $r17

    li.w $r14, 0x000000ad
    csrwr $r14, 0x18

###TLB item 13 G=1
    li.w $r16, 0x034ab940 ; li.w $r17, 0x0ffab940 ; addi.w $r14, $r12, 0x0 ; addi.w $r15, $r13, 0x0 ; csrwr $r14, 0x10 ; csrwr $r15, 0x11 ; csrwr $r16, 0x12 ; csrwr $r17, 0x13 ; tlbwr ; addi.w $r12, $r12, 0x1 ; li.w $r17, 1<<13 ; add.w $r13, $r13, $r17
###TLB item 14 G=1
    li.w $r16, 0x034aba40 ; li.w $r17, 0x0ffaba40 ; addi.w $r14, $r12, 0x0 ; addi.w $r15, $r13, 0x0 ; csrwr $r14, 0x10 ; csrwr $r15, 0x11 ; csrwr $r16, 0x12 ; csrwr $r17, 0x13 ; tlbwr ; addi.w $r12, $r12, 0x1 ; li.w $r17, 1<<13 ; add.w $r13, $r13, $r17
###TLB item 15 G=1
    li.w $r16, 0x034ab740 ; li.w $r17, 0x0ffab740 ; addi.w $r14, $r12, 0x0 ; addi.w $r15, $r13, 0x0 ; csrwr $r14, 0x10 ; csrwr $r15, 0x11 ; csrwr $r16, 0x12 ; csrwr $r17, 0x13 ; tlbwr ; addi.w $r12, $r12, 0x1 ; li.w $r17, 1<<13 ; add.w $r13, $r13, $r17
###TLB item 16 G=1
    li.w $r16, 0x034ab840 ; li.w $r17, 0x0ffab840 ; addi.w $r14, $r12, 0x0 ; addi.w $r15, $r13, 0x0 ; csrwr $r14, 0x10 ; csrwr $r15, 0x11 ; csrwr $r16, 0x12 ; csrwr $r17, 0x13 ; tlbwr ; addi.w $r12, $r12, 0x1 ; li.w $r17, 1<<13 ; add.w $r13, $r13, $r17

###clear tlb csr reg
    csrwr $r0, 0x11
    csrwr $r0, 0x12
    csrwr $r0, 0x13
    csrwr $r0, 0x10

###detect exception
# bne $r25, $r0, inst_error
###score ++
# addi.w $r26, $r26, 1
###output ($r23<<24)|$r26
 #inst_error:
# slli.w $r13, $r23, 24
# or $r12, $r13, $r26
 # st.w $r12, $r24, 0x0
    jirl $r0, $r1, 0x0

.cfi_endproc ; .size tlb_initialization,.-tlb_initialization;
