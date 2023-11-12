# 1 "n81_atomic_ins.S"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "n81_atomic_ins.S"
# 1 "../include/asm.h" 1



# 1 "../include/regdef.h" 1
# 5 "../include/asm.h" 2
# 1 "../include/sysdep.h" 1
# 6 "../include/asm.h" 2
# 2 "n81_atomic_ins.S" 2
# 1 "../include/regdef.h" 1
# 3 "n81_atomic_ins.S" 2
# 1 "../include/inst_test.h" 1

# 1 "../include/cpu_cde.h" 1
# 1 "../include/lab_config.h" 1
# 2 "../include/cpu_cde.h" 2
# 3 "../include/inst_test.h" 2
# 4 "n81_atomic_ins.S" 2

.text; .globl n81_atomic_ins_test; .align 3; .cfi_startproc ; .type n81_atomic_ins_test, @function; n81_atomic_ins_test:

    li.w $r12, 0x80
    li.w $r13, 0x180
    csrxchg $r12, $r13, 0x0

    addi.w $r23, $r23 ,1
    li.w $r25, 0x0
    li.w $r12, 0x2
    li.w $r13, 0x2
    csrxchg $r13, $r12, 0x60
    li.w $r20, (0x100000 +0xd0004)

##inst test
###1
    li.w $r19, 0xffff1234
    st.w $r19, $r20, 0
    ll.w $r13, $r20, 0
    bne $r19, $r13, inst_error

    csrrd $r14, 0x60
    li.w $r15, 0x1
    and $r14, $r14, $r15
    bne $r14, $r15, inst_error

    li.w $r19, 0x1234ffff
    move $r13, $r19
    sc.w $r13, $r20, 0
    li.w $r12, 0x1
    bne $r13, $r12, inst_error

    csrrd $r14, 0x60
    li.w $r15, 0x1
    and $r14, $r14, $r15
    li.w $r15, 0x0
    bne $r14, $r15, inst_error

    ld.w $r13, $r20, 0
    bne $r19, $r13, inst_error

###2
    li.w $r19, 0xf1234
    st.w $r19, $r20, 0
    ll.w $r13, $r20, 0
    bne $r19, $r13, inst_error

    li.w $r12, 0x2
    li.w $r13, 0x2
    csrxchg $r13, $r12, 0x60
    li.w $r15, 0x1
    and $r13, $r13, $r15
    bne $r13, $r15, inst_error

    csrrd $r14, 0x60
    li.w $r15, 0x1
    and $r14, $r14, $r15
    li.w $r15, 0x0
    bne $r14, $r15, inst_error

    li.w $r13, 0x4ffff
    sc.w $r13, $r20, 0
    li.w $r12, 0x0
    bne $r13, $r12, inst_error

    csrrd $r14, 0x60
    li.w $r15, 0x1
    and $r14, $r14, $r15
    li.w $r15, 0x0
    bne $r14, $r15, inst_error

    ld.w $r13, $r20, 0
    bne $r19, $r13, inst_error

###3
    li.w $r19, 0xff1212
    li.w $r12, 0x4
    li.w $r13, 0x4
    csrxchg $r13, $r12, 0x60
    csrrd $r13, 0x0
    li.w $r12, 0x7
    csrxchg $r13, $r12, 0x1
    la.local $r12, 1f
    csrwr $r12, 0x6

    st.w $r19, $r20, 0
    ll.w $r13, $r20, 0
    bne $r19, $r13, inst_error

    csrrd $r14, 0x60
    li.w $r15, 0x1
    and $r14, $r14, $r15
    bne $r14, $r15, inst_error

    ertn
1:
    csrrd $r14, 0x60
    li.w $r15, 0x5
    and $r14, $r14, $r15
    li.w $r15, 0x1
    bne $r14, $r15, inst_error

    li.w $r19, 0x1212ff
    move $r13, $r19
    sc.w $r13, $r20, 0
    li.w $r12, 0x1
    bne $r13, $r12, inst_error

    csrrd $r14, 0x60
    li.w $r15, 0x1
    and $r14, $r14, $r15
    li.w $r15, 0x0
    bne $r14, $r15, inst_error

    ld.w $r13, $r20, 0
    bne $r19, $r13, inst_error


###4
    li.w $r19, 0xffabab
    csrrd $r13, 0x0
    li.w $r12, 0x7
    csrxchg $r13, $r12, 0x1
    la.local $r12, 1f
    csrwr $r12, 0x6

    st.w $r19, $r20, 0
    ll.w $r13, $r20, 0
    bne $r19, $r13, inst_error

    csrrd $r14, 0x60
    li.w $r15, 0x1
    and $r14, $r14, $r15
    bne $r14, $r15, inst_error

    ertn
1:
    csrrd $r14, 0x60
    li.w $r15, 0x5
    and $r14, $r14, $r15
    li.w $r15, 0x0
    bne $r14, $r15, inst_error

    li.w $r13, 0xababff
    sc.w $r13, $r20, 0
    li.w $r12, 0x0
    bne $r13, $r12, inst_error

    csrrd $r14, 0x60
    li.w $r15, 0x1
    and $r14, $r14, $r15
    li.w $r15, 0x0
    bne $r14, $r15, inst_error

    ld.w $r13, $r20, 0
    bne $r19, $r13, inst_error

    li.w $r12, 0x0
    li.w $r13, 0x180
    csrxchg $r12, $r13, 0x0

###score +++
  addi.w $r26, $r26, 1
###output ($r23<<24)|$r26
inst_error:
  slli.w $r13, $r23, 24
  or $r12, $r13, $r26
  st.w $r12, $r24, 0
  jirl $r0, $r1, 0
.cfi_endproc ; .size n81_atomic_ins_test,.-n81_atomic_ins_test;
