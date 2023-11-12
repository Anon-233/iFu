# 1 "n71_tlb_ex.S"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "n71_tlb_ex.S"
# 1 "../include/asm.h" 1



# 1 "../include/regdef.h" 1
# 5 "../include/asm.h" 2
# 1 "../include/sysdep.h" 1
# 6 "../include/asm.h" 2
# 2 "n71_tlb_ex.S" 2
# 1 "../include/regdef.h" 1
# 3 "n71_tlb_ex.S" 2
# 1 "../include/inst_test.h" 1

# 1 "../include/cpu_cde.h" 1
# 1 "../include/lab_config.h" 1
# 2 "../include/cpu_cde.h" 2
# 3 "../include/inst_test.h" 2
# 4 "n71_tlb_ex.S" 2

.text; .globl n71_tlb_ex_test; .align 3; .cfi_startproc ; .type n71_tlb_ex_test, @function; n71_tlb_ex_test:
    addi.w $r23, $r23, 0x1

    invtlb 0x0, $r0, $r0


    li.w $r12, 0x1
    csrwr $r12, 0x44

    li.w $r12, 0x1c008000
    csrwr $r12, 0xc
    li.w $r13, 0x1c000000 + 0xf000
    csrwr $r13, 0x88

    li.w $r15, 0x0c000001
    li.w $r12, 0x1c008000
    li.w $r13, 0xffffe000
    and $r16, $r12, $r13
    srli.w $r16, $r16, 0x4
    li.w $r13, 0x4d
    or $r13, $r16, $r13
    li.w $r14, 0x14d
    or $r14, $r16, $r14
    addi.w $r16, $r15, 0x0; addi.w $r17, $r12, 0x0; addi.w $r18, $r13, 0x0; addi.w $r19, $r14, 0x0; csrwr $r16, 0x10 ; li.w $r16, 0xffffe000 ; and $r17, $r17, $r16 ; csrwr $r17, 0x11 ; csrwr $r18, 0x12 ; csrwr $r19, 0x13 ; tlbwr ; addi.w $r15, $r15, 0x1 ; li.w $r16, 0x1<<13 ; li.w $r17, 0x2<<8 ; add.w $r12, $r12, $r16 ; add.w $r13, $r13, $r17 ; add.w $r14, $r14, $r17 ;
    addi.w $r16, $r15, 0x0; addi.w $r17, $r12, 0x0; addi.w $r18, $r13, 0x0; addi.w $r19, $r14, 0x0; csrwr $r16, 0x10 ; li.w $r16, 0xffffe000 ; and $r17, $r17, $r16 ; csrwr $r17, 0x11 ; csrwr $r18, 0x12 ; csrwr $r19, 0x13 ; tlbwr ; addi.w $r15, $r15, 0x1 ; li.w $r16, 0x1<<13 ; li.w $r17, 0x2<<8 ; add.w $r12, $r12, $r16 ; add.w $r13, $r13, $r17 ; add.w $r14, $r14, $r17 ;
    addi.w $r16, $r15, 0x0; addi.w $r17, $r12, 0x0; addi.w $r18, $r13, 0x0; addi.w $r19, $r14, 0x0; csrwr $r16, 0x10 ; li.w $r16, 0xffffe000 ; and $r17, $r17, $r16 ; csrwr $r17, 0x11 ; csrwr $r18, 0x12 ; csrwr $r19, 0x13 ; tlbwr ; addi.w $r15, $r15, 0x1 ; li.w $r16, 0x1<<13 ; li.w $r17, 0x2<<8 ; add.w $r12, $r12, $r16 ; add.w $r13, $r13, $r17 ; add.w $r14, $r14, $r17 ;
    addi.w $r16, $r15, 0x0; addi.w $r17, $r12, 0x0; addi.w $r18, $r13, 0x0; addi.w $r19, $r14, 0x0; csrwr $r16, 0x10 ; li.w $r16, 0xffffe000 ; and $r17, $r17, $r16 ; csrwr $r17, 0x11 ; csrwr $r18, 0x12 ; csrwr $r19, 0x13 ; tlbwr ; addi.w $r15, $r15, 0x1 ; li.w $r16, 0x1<<13 ; li.w $r17, 0x2<<8 ; add.w $r12, $r12, $r16 ; add.w $r13, $r13, $r17 ; add.w $r14, $r14, $r17 ;
    addi.w $r16, $r15, 0x0; addi.w $r17, $r12, 0x0; addi.w $r18, $r13, 0x0; addi.w $r19, $r14, 0x0; csrwr $r16, 0x10 ; li.w $r16, 0xffffe000 ; and $r17, $r17, $r16 ; csrwr $r17, 0x11 ; csrwr $r18, 0x12 ; csrwr $r19, 0x13 ; tlbwr ; addi.w $r15, $r15, 0x1 ; li.w $r16, 0x1<<13 ; li.w $r17, 0x2<<8 ; add.w $r12, $r12, $r16 ; add.w $r13, $r13, $r17 ; add.w $r14, $r14, $r17 ;
    addi.w $r16, $r15, 0x0; addi.w $r17, $r12, 0x0; addi.w $r18, $r13, 0x0; addi.w $r19, $r14, 0x0; csrwr $r16, 0x10 ; li.w $r16, 0xffffe000 ; and $r17, $r17, $r16 ; csrwr $r17, 0x11 ; csrwr $r18, 0x12 ; csrwr $r19, 0x13 ; tlbwr ; addi.w $r15, $r15, 0x1 ; li.w $r16, 0x1<<13 ; li.w $r17, 0x2<<8 ; add.w $r12, $r12, $r16 ; add.w $r13, $r13, $r17 ; add.w $r14, $r14, $r17 ;
    addi.w $r16, $r15, 0x0; addi.w $r17, $r12, 0x0; addi.w $r18, $r13, 0x0; addi.w $r19, $r14, 0x0; csrwr $r16, 0x10 ; li.w $r16, 0xffffe000 ; and $r17, $r17, $r16 ; csrwr $r17, 0x11 ; csrwr $r18, 0x12 ; csrwr $r19, 0x13 ; tlbwr ; addi.w $r15, $r15, 0x1 ; li.w $r16, 0x1<<13 ; li.w $r17, 0x2<<8 ; add.w $r12, $r12, $r16 ; add.w $r13, $r13, $r17 ; add.w $r14, $r14, $r17 ;
    addi.w $r16, $r15, 0x0; addi.w $r17, $r12, 0x0; addi.w $r18, $r13, 0x0; addi.w $r19, $r14, 0x0; csrwr $r16, 0x10 ; li.w $r16, 0xffffe000 ; and $r17, $r17, $r16 ; csrwr $r17, 0x11 ; csrwr $r18, 0x12 ; csrwr $r19, 0x13 ; tlbwr ; addi.w $r15, $r15, 0x1 ; li.w $r16, 0x1<<13 ; li.w $r17, 0x2<<8 ; add.w $r12, $r12, $r16 ; add.w $r13, $r13, $r17 ; add.w $r14, $r14, $r17 ;
    addi.w $r16, $r15, 0x0; addi.w $r17, $r12, 0x0; addi.w $r18, $r13, 0x0; addi.w $r19, $r14, 0x0; csrwr $r16, 0x10 ; li.w $r16, 0xffffe000 ; and $r17, $r17, $r16 ; csrwr $r17, 0x11 ; csrwr $r18, 0x12 ; csrwr $r19, 0x13 ; tlbwr ; addi.w $r15, $r15, 0x1 ; li.w $r16, 0x1<<13 ; li.w $r17, 0x2<<8 ; add.w $r12, $r12, $r16 ; add.w $r13, $r13, $r17 ; add.w $r14, $r14, $r17 ;
    addi.w $r16, $r15, 0x0; addi.w $r17, $r12, 0x0; addi.w $r18, $r13, 0x0; addi.w $r19, $r14, 0x0; csrwr $r16, 0x10 ; li.w $r16, 0xffffe000 ; and $r17, $r17, $r16 ; csrwr $r17, 0x11 ; csrwr $r18, 0x12 ; csrwr $r19, 0x13 ; tlbwr ; addi.w $r15, $r15, 0x1 ; li.w $r16, 0x1<<13 ; li.w $r17, 0x2<<8 ; add.w $r12, $r12, $r16 ; add.w $r13, $r13, $r17 ; add.w $r14, $r14, $r17 ;

    li.w $r12, 0xd0000
    li.w $r13, 0xffffe000
    and $r16, $r12, $r13
    srli.w $r16, $r16, 0x4
    li.w $r13, 0x4d
    or $r13, $r16, $r13
    li.w $r14, 0x14d
    or $r14, $r16, $r14
    addi.w $r16, $r15, 0x0; addi.w $r17, $r12, 0x0; addi.w $r18, $r13, 0x0; addi.w $r19, $r14, 0x0; csrwr $r16, 0x10 ; li.w $r16, 0xffffe000 ; and $r17, $r17, $r16 ; csrwr $r17, 0x11 ; csrwr $r18, 0x12 ; csrwr $r19, 0x13 ; tlbwr ; addi.w $r15, $r15, 0x1 ; li.w $r16, 0x1<<13 ; li.w $r17, 0x2<<8 ; add.w $r12, $r12, $r16 ; add.w $r13, $r13, $r17 ; add.w $r14, $r14, $r17 ;
    addi.w $r16, $r15, 0x0; addi.w $r17, $r12, 0x0; addi.w $r18, $r13, 0x0; addi.w $r19, $r14, 0x0; csrwr $r16, 0x10 ; li.w $r16, 0xffffe000 ; and $r17, $r17, $r16 ; csrwr $r17, 0x11 ; csrwr $r18, 0x12 ; csrwr $r19, 0x13 ; tlbwr ; addi.w $r15, $r15, 0x1 ; li.w $r16, 0x1<<13 ; li.w $r17, 0x2<<8 ; add.w $r12, $r12, $r16 ; add.w $r13, $r13, $r17 ; add.w $r14, $r14, $r17 ;

    la.local $r12, 7f
7:
    li.w $r13, 0xffffe000
    and $r16, $r12, $r13
    srli.w $r16, $r16, 0x4
    li.w $r13, 0x4d
    or $r13, $r16, $r13
    li.w $r14, 0x14d
    or $r14, $r16, $r14
    addi.w $r16, $r15, 0x0; addi.w $r17, $r12, 0x0; addi.w $r18, $r13, 0x0; addi.w $r19, $r14, 0x0; csrwr $r16, 0x10 ; li.w $r16, 0xffffe000 ; and $r17, $r17, $r16 ; csrwr $r17, 0x11 ; csrwr $r18, 0x12 ; csrwr $r19, 0x13 ; tlbwr ; addi.w $r15, $r15, 0x1 ; li.w $r16, 0x1<<13 ; li.w $r17, 0x2<<8 ; add.w $r12, $r12, $r16 ; add.w $r13, $r13, $r17 ; add.w $r14, $r14, $r17 ;
    addi.w $r16, $r15, 0x0; addi.w $r17, $r12, 0x0; addi.w $r18, $r13, 0x0; addi.w $r19, $r14, 0x0; csrwr $r16, 0x10 ; li.w $r16, 0xffffe000 ; and $r17, $r17, $r16 ; csrwr $r17, 0x11 ; csrwr $r18, 0x12 ; csrwr $r19, 0x13 ; tlbwr ; addi.w $r15, $r15, 0x1 ; li.w $r16, 0x1<<13 ; li.w $r17, 0x2<<8 ; add.w $r12, $r12, $r16 ; add.w $r13, $r13, $r17 ; add.w $r14, $r14, $r17 ;
    addi.w $r16, $r15, 0x0; addi.w $r17, $r12, 0x0; addi.w $r18, $r13, 0x0; addi.w $r19, $r14, 0x0; csrwr $r16, 0x10 ; li.w $r16, 0xffffe000 ; and $r17, $r17, $r16 ; csrwr $r17, 0x11 ; csrwr $r18, 0x12 ; csrwr $r19, 0x13 ; tlbwr ; addi.w $r15, $r15, 0x1 ; li.w $r16, 0x1<<13 ; li.w $r17, 0x2<<8 ; add.w $r12, $r12, $r16 ; add.w $r13, $r13, $r17 ; add.w $r14, $r14, $r17 ;
    addi.w $r16, $r15, 0x0; addi.w $r17, $r12, 0x0; addi.w $r18, $r13, 0x0; addi.w $r19, $r14, 0x0; csrwr $r16, 0x10 ; li.w $r16, 0xffffe000 ; and $r17, $r17, $r16 ; csrwr $r17, 0x11 ; csrwr $r18, 0x12 ; csrwr $r19, 0x13 ; tlbwr ; addi.w $r15, $r15, 0x1 ; li.w $r16, 0x1<<13 ; li.w $r17, 0x2<<8 ; add.w $r12, $r12, $r16 ; add.w $r13, $r13, $r17 ; add.w $r14, $r14, $r17 ;
    addi.w $r16, $r15, 0x0; addi.w $r17, $r12, 0x0; addi.w $r18, $r13, 0x0; addi.w $r19, $r14, 0x0; csrwr $r16, 0x10 ; li.w $r16, 0xffffe000 ; and $r17, $r17, $r16 ; csrwr $r17, 0x11 ; csrwr $r18, 0x12 ; csrwr $r19, 0x13 ; tlbwr ; addi.w $r15, $r15, 0x1 ; li.w $r16, 0x1<<13 ; li.w $r17, 0x2<<8 ; add.w $r12, $r12, $r16 ; add.w $r13, $r13, $r17 ; add.w $r14, $r14, $r17 ;


    li.w $r12, 0x80
    li.w $r13, 0x180
    csrxchg $r12, $r13, 0x0


    li.w $r12, 0x13
    li.w $r13, 0x1f
    csrxchg $r12, $r13, 0x0

### TLB refill error
    li.w $r17, 0x3
    lu12i.w $r30, 0xe
    li.w $r31, 0x200ff << 13
    la.local $r27, 1f
1:
    ld.w $r14, $r31, 0x0
    bne $r25, $r30, inst_error
    li.w $r12, (0x100000 +0xd0000); li.w $r25, 0xf; st.w $r25, $r12, 0
    syscall 0

### TLB page invalid error in ld


    li.w $r12, 0x08
    li.w $r13, 0x1f
    csrxchg $r12, $r13, 0x0

    li.w $r12, (0x100000 +0xd0000); li.w $r25, 0x8; st.w $r25, $r12, 0

    ###fill in a present but invalid TLB item
    li.w $r12, 0x0c000000 ; li.w $r13, 0x20fff<<13 ; li.w $r14, 0x000f004c ; li.w $r15, 0x000a004c ; csrwr $r12, 0x10 ; csrwr $r13, 0x11 ; csrwr $r14, 0x12 ; csrwr $r15, 0x13 ; tlbwr ;
    csrwr $r0, 0x11


    li.w $r12, 0x13
    li.w $r13, 0x1f
    csrxchg $r12, $r13, 0x0

    li.w $r17, 0x3
    lu12i.w $r30, 0x1
    li.w $r31, 0x20fff<<13
    la.local $r27, 2f
    li.w $r12, 0xffffffff
2:
    ld.w $r12, $r31, 0x0
    bne $r25, $r30, inst_error
    li.w $r12, (0x100000 +0xd0000); li.w $r25, 0xf; st.w $r25, $r12, 0
    syscall 0

### TLB page invalid error in st


    li.w $r12, 0x08
    li.w $r13, 0x1f
    csrxchg $r12, $r13, 0x0

    li.w $r12, (0x100000 +0xd0000); li.w $r25, 0x9; st.w $r25, $r12, 0

    ###fill in a present but invalid TLB item
    li.w $r12, 0x0c000000 ; li.w $r13, 0x200ab<<13 ; li.w $r14, 0x000c004c ; li.w $r15, 0x000d004c ; csrwr $r12, 0x10 ; csrwr $r13, 0x11 ; csrwr $r14, 0x12 ; csrwr $r15, 0x13 ; tlbwr ;
    csrwr $r0, 0x11


    li.w $r12, 0x13
    li.w $r13, 0x1f
    csrxchg $r12, $r13, 0x0

    li.w $r17, 0x3
    lu12i.w $r30, 0x2
    li.w $r31, 0x200ab<<13
    li.w $r12, 0xfff
    la.local $r27, 3f
3:
    st.w $r12, $r31, 0x0
    bne $r25, $r30, inst_error
    li.w $r12, (0x100000 +0xd0000); li.w $r25, 0xf; st.w $r25, $r12, 0
    syscall 0

### TLB PME

    li.w $r12, 0x08
    li.w $r13, 0x1f
    csrxchg $r12, $r13, 0x0

    li.w $r12, (0x100000 +0xd0000); li.w $r25, 0x7; st.w $r25, $r12, 0

    li.w $r12, 0xd0010
    li.w $r25, 0xff
    st.w $r25, $r12, 0

    ###fill in a present but not dirty TLB item
    li.w $r12, 0x0c000000 ; li.w $r13, 0x200ab<<13 ; li.w $r14, 0x000d04d ; li.w $r15, 0x000d14d ; csrwr $r12, 0x10 ; csrwr $r13, 0x11 ; csrwr $r14, 0x12 ; csrwr $r15, 0x13 ; tlbwr ;


    li.w $r12, 0x10
    li.w $r13, 0x18
    csrxchg $r12, $r13, 0x0

    li.w $r17, 0x0
    lu12i.w $r30, 0x70
    li.w $r31, 0x200ab<<13
    addi.w $r31, $r31, 0x10
    li.w $r12, 0xfff
    la.local $r27, 1f
1:
    st.w $r12, $r31, 0
    bne $r25, $r30, inst_error
    li.w $r12, 0x08
    li.w $r13, 0x1f
    csrxchg $r12, $r13, 0x0
    li.w $r12, 0xd0010
    ld.w $r13, $r12, 0
    li.w $r14, 0xff
    bne $r14, $r13, inst_error

### TLB privilage error


    li.w $r12, 0x08
    li.w $r13, 0x1f
    csrxchg $r12, $r13, 0x0

    li.w $r12, (0x100000 +0xd0000); li.w $r25, 0xa; st.w $r25, $r12, 0

    ###fill in a present and valid item but prl = 0
    li.w $r12, 0x0c000000 ; li.w $r13, 0x200ab<<13 ; li.w $r14, 0x000c0001 ; li.w $r15, 0x000d0001 ; csrwr $r12, 0x10 ; csrwr $r13, 0x11 ; csrwr $r14, 0x12 ; csrwr $r15, 0x13 ; tlbwr ;
    csrwr $r0, 0x11


    li.w $r12, 0x13
    li.w $r13, 0x1f
    csrxchg $r12, $r13, 0x0

    li.w $r17, 0x3
    lu12i.w $r30, 0x7
    li.w $r31, 0x200ab<<13
    li.w $r12, 0xfff
    la.local $r27, 4f
4:
    st.w $r12, $r31, 0x0
    bne $r25, $r30, inst_error
    li.w $r12, (0x100000 +0xd0000); li.w $r25, 0xf; st.w $r25, $r12, 0
    syscall 0

### TLB page modified error


    li.w $r12, 0x08
    li.w $r13, 0x1f
    csrxchg $r12, $r13, 0x0

    li.w $r12, (0x100000 +0xd0000); li.w $r25, 0xb; st.w $r25, $r12, 0

    ###fill in a present and valid item but V=0
    li.w $r12, 0x0c000000 ; li.w $r13, 0x200ab<<13 ; li.w $r14, 0x000c000d ; li.w $r15, 0x000d000d ; csrwr $r12, 0x10 ; csrwr $r13, 0x11 ; csrwr $r14, 0x12 ; csrwr $r15, 0x13 ; tlbwr ;
    csrwr $r0, 0x11


    li.w $r12, 0x13
    li.w $r13, 0x1f
    csrxchg $r12, $r13, 0x0

    li.w $r17, 0x3
    lu12i.w $r30, 0x4
    li.w $r31, 0x200ab<<13
    li.w $r12, 0xfff
    la.local $r27, 5f
5:
    st.w $r12, $r31, 0x0
    bne $r25, $r30, inst_error
    li.w $r12, (0x100000 +0xd0000); li.w $r25, 0xf; st.w $r25, $r12, 0
    syscall 0

### TLB page invalid error in inst fetch


    li.w $r12, 0x08
    li.w $r13, 0x1f
    csrxchg $r12, $r13, 0x0

    li.w $r12, (0x100000 +0xd0000); li.w $r25, 0xc; st.w $r25, $r12, 0

    ###fill in a present but invalid item
    li.w $r12, 0x0c000000 ; li.w $r13, 0x200ff<<13 ; li.w $r14, 0x000c004c ; li.w $r15, 0x000d004c ; csrwr $r12, 0x10 ; csrwr $r13, 0x11 ; csrwr $r14, 0x12 ; csrwr $r15, 0x13 ; tlbwr ;
    csrwr $r0, 0x11


    li.w $r12, 0x13
    li.w $r13, 0x1f
    csrxchg $r12, $r13, 0x0

    li.w $r17, 0x3
    lu12i.w $r30, 0x3
    li.w $r31, 0x200ff<<13
    la.local $r27, 6f
6:
    jirl $r0, $r31, 0x0
    bne $r25, $r30, inst_error
    li.w $r12, (0x100000 +0xd0000); li.w $r25, 0xf; st.w $r25, $r12, 0
    syscall 0

### TLB address error in memory access: adem
# 296 "n71_tlb_ex.S"
### TLB address error in inst fetch: adef
# 324 "n71_tlb_ex.S"
###func end here and recover the DA=1


    li.w $r12, 0x08
    li.w $r13, 0x1f
    csrxchg $r12, $r13, 0x0


    li.w $r12, 0x0
    li.w $r13, 0x180
    csrxchg $r12, $r13, 0x0

###score ++
    addi.w $r26, $r26, 1
###output ($r23<<24)|$r26
inst_error:
    slli.w $r13, $r23, 24
    or $r12, $r13, $r26
    st.w $r12, $r24, 0x0
    jirl $r0, $r1, 0x0
.cfi_endproc ; .size n71_tlb_ex_test,.-n71_tlb_ex_test;
