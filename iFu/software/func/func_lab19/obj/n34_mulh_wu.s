# 1 "n34_mulh_wu.S"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "n34_mulh_wu.S"
# 1 "../include/asm.h" 1



# 1 "../include/regdef.h" 1
# 5 "../include/asm.h" 2
# 1 "../include/sysdep.h" 1
# 6 "../include/asm.h" 2
# 2 "n34_mulh_wu.S" 2
# 1 "../include/regdef.h" 1
# 3 "n34_mulh_wu.S" 2
# 1 "../include/inst_test.h" 1

# 1 "../include/cpu_cde.h" 1
# 1 "../include/lab_config.h" 1
# 2 "../include/cpu_cde.h" 2
# 3 "../include/inst_test.h" 2
# 4 "n34_mulh_wu.S" 2

.text; .globl n34_mulh_wu_test; .align 3; .cfi_startproc ; .type n34_mulh_wu_test, @function; n34_mulh_wu_test:

    addi.w $r23, $r23 ,1
    li.w $r25, 0x0
###test inst
    li.w $r12, 0x99c9a500; li.w $r13, 0x6c1a1b60; mulh.wu $r15, $r12, $r13; li.w $r16, 0x40f0c088; bne $r15, $r16, inst_error
    li.w $r12, 0xee026dc0; li.w $r13, 0xd85e0aec; mulh.wu $r15, $r12, $r13; li.w $r16, 0xc9297ba5; bne $r15, $r16, inst_error
    li.w $r12, 0xa49b33d4; li.w $r13, 0x894d6a78; mulh.wu $r15, $r12, $r13; li.w $r16, 0x5848d5e0; bne $r15, $r16, inst_error
    li.w $r12, 0xd16d0152; li.w $r13, 0xbcd4f694; mulh.wu $r15, $r12, $r13; li.w $r16, 0x9a7a44f5; bne $r15, $r16, inst_error
    li.w $r12, 0x9880cf50; li.w $r13, 0xd7e33d18; mulh.wu $r15, $r12, $r13; li.w $r16, 0x809b8cb9; bne $r15, $r16, inst_error
    li.w $r12, 0x686decfc; li.w $r13, 0x2bb09c9f; mulh.wu $r15, $r12, $r13; li.w $r16, 0x11d28245; bne $r15, $r16, inst_error
    li.w $r12, 0x290ca739; li.w $r13, 0xc1cc4ec0; mulh.wu $r15, $r12, $r13; li.w $r16, 0x1f134cc7; bne $r15, $r16, inst_error
    li.w $r12, 0x1d1eb998; li.w $r13, 0xd5b8328e; mulh.wu $r15, $r12, $r13; li.w $r16, 0x184f8441; bne $r15, $r16, inst_error
    li.w $r12, 0x79b7d394; li.w $r13, 0x0ba99ece; mulh.wu $r15, $r12, $r13; li.w $r16, 0x058b8bf3; bne $r15, $r16, inst_error
    li.w $r12, 0x0d7f9488; li.w $r13, 0x3647ab9c; mulh.wu $r15, $r12, $r13; li.w $r16, 0x02dcb0c3; bne $r15, $r16, inst_error
    li.w $r12, 0x3196de58; li.w $r13, 0x4c28d54e; mulh.wu $r15, $r12, $r13; li.w $r16, 0x0ec0b2e6; bne $r15, $r16, inst_error
    li.w $r12, 0x473a0e0a; li.w $r13, 0xe0925338; mulh.wu $r15, $r12, $r13; li.w $r16, 0x3e7b828c; bne $r15, $r16, inst_error
    li.w $r12, 0x3721c560; li.w $r13, 0xe7f35d08; mulh.wu $r15, $r12, $r13; li.w $r16, 0x31f3e230; bne $r15, $r16, inst_error
    li.w $r12, 0x536cd050; li.w $r13, 0x675dc658; mulh.wu $r15, $r12, $r13; li.w $r16, 0x21af56fa; bne $r15, $r16, inst_error
    li.w $r12, 0x2310a2f4; li.w $r13, 0x07cd8030; mulh.wu $r15, $r12, $r13; li.w $r16, 0x01119a56; bne $r15, $r16, inst_error
    li.w $r12, 0xc2fd5307; li.w $r13, 0x034a3375; mulh.wu $r15, $r12, $r13; li.w $r16, 0x02817c64; bne $r15, $r16, inst_error
    li.w $r12, 0x79fba360; li.w $r13, 0xcc308ea8; mulh.wu $r15, $r12, $r13; li.w $r16, 0x614ba958; bne $r15, $r16, inst_error
    li.w $r12, 0x3f1c7b7a; li.w $r13, 0x89f4a9ff; mulh.wu $r15, $r12, $r13; li.w $r16, 0x22028f22; bne $r15, $r16, inst_error
    li.w $r12, 0x6451cbd8; li.w $r13, 0x85dc2080; mulh.wu $r15, $r12, $r13; li.w $r16, 0x3474c1ee; bne $r15, $r16, inst_error
    li.w $r12, 0x8885fb40; li.w $r13, 0x65a9fc18; mulh.wu $r15, $r12, $r13; li.w $r16, 0x36378303; bne $r15, $r16, inst_error
    li.w $r12, 0x71f5e890; li.w $r13, 0x1c7fba40; mulh.wu $r15, $r12, $r13; li.w $r16, 0x0cafc157; bne $r15, $r16, inst_error
    li.w $r12, 0x527b08db; li.w $r13, 0xc4c2d838; mulh.wu $r15, $r12, $r13; li.w $r16, 0x3f64f9ae; bne $r15, $r16, inst_error
    li.w $r12, 0xd2d00316; li.w $r13, 0x5ce48028; mulh.wu $r15, $r12, $r13; li.w $r16, 0x4c7eebe7; bne $r15, $r16, inst_error
    li.w $r12, 0xa47ba800; li.w $r13, 0x83d06930; mulh.wu $r15, $r12, $r13; li.w $r16, 0x54b12f06; bne $r15, $r16, inst_error
    li.w $r12, 0xcb3eee22; li.w $r13, 0x59a7fa20; mulh.wu $r15, $r12, $r13; li.w $r16, 0x472e3d6c; bne $r15, $r16, inst_error
    li.w $r12, 0x4092ce98; li.w $r13, 0xef2cbae3; mulh.wu $r15, $r12, $r13; li.w $r16, 0x3c54573f; bne $r15, $r16, inst_error
    li.w $r12, 0x76a3d520; li.w $r13, 0x0219a7f1; mulh.wu $r15, $r12, $r13; li.w $r16, 0x00f92b7e; bne $r15, $r16, inst_error
    li.w $r12, 0x4dba87a0; li.w $r13, 0xabfd53c0; mulh.wu $r15, $r12, $r13; li.w $r16, 0x3438835d; bne $r15, $r16, inst_error
    li.w $r12, 0xb21ddb80; li.w $r13, 0x86c4337c; mulh.wu $r15, $r12, $r13; li.w $r16, 0x5dc42393; bne $r15, $r16, inst_error
    li.w $r12, 0x24bf43c2; li.w $r13, 0x5ebb156c; mulh.wu $r15, $r12, $r13; li.w $r16, 0x0d9915aa; bne $r15, $r16, inst_error
    li.w $r12, 0x88933830; li.w $r13, 0x9b18625e; mulh.wu $r15, $r12, $r13; li.w $r16, 0x52be254c; bne $r15, $r16, inst_error
    li.w $r12, 0x3bd6f96c; li.w $r13, 0x1c413041; mulh.wu $r15, $r12, $r13; li.w $r16, 0x069ac024; bne $r15, $r16, inst_error
    li.w $r12, 0x0b093c0a; li.w $r13, 0xf967e2ce; mulh.wu $r15, $r12, $r13; li.w $r16, 0x0ac075e3; bne $r15, $r16, inst_error
    li.w $r12, 0xf0e46398; li.w $r13, 0x95dbf923; mulh.wu $r15, $r12, $r13; li.w $r16, 0x8d03ebc7; bne $r15, $r16, inst_error
    li.w $r12, 0x109f0e5c; li.w $r13, 0xc6bd4b78; mulh.wu $r15, $r12, $r13; li.w $r16, 0x0ce74f6f; bne $r15, $r16, inst_error
    li.w $r12, 0x23a1f870; li.w $r13, 0x88a80670; mulh.wu $r15, $r12, $r13; li.w $r16, 0x13056f2b; bne $r15, $r16, inst_error
    li.w $r12, 0x383bf8e0; li.w $r13, 0x78e11c9e; mulh.wu $r15, $r12, $r13; li.w $r16, 0x1a8d8fa8; bne $r15, $r16, inst_error
    li.w $r12, 0x7a249e47; li.w $r13, 0xde35e25c; mulh.wu $r15, $r12, $r13; li.w $r16, 0x6a0576d6; bne $r15, $r16, inst_error
    li.w $r12, 0x9bbd1a87; li.w $r13, 0x87bced28; mulh.wu $r15, $r12, $r13; li.w $r16, 0x5293a823; bne $r15, $r16, inst_error
    li.w $r12, 0x58b0b4c2; li.w $r13, 0x4b2eaf04; mulh.wu $r15, $r12, $r13; li.w $r16, 0x1a0bf157; bne $r15, $r16, inst_error
    li.w $r12, 0xabb5baa8; li.w $r13, 0xe59a0d6c; mulh.wu $r15, $r12, $r13; li.w $r16, 0x9a00e44b; bne $r15, $r16, inst_error
    li.w $r12, 0xef331cb8; li.w $r13, 0xb5a98f8c; mulh.wu $r15, $r12, $r13; li.w $r16, 0xa9bd922c; bne $r15, $r16, inst_error
    li.w $r12, 0xfbd21f10; li.w $r13, 0xe381c1fc; mulh.wu $r15, $r12, $r13; li.w $r16, 0xdfcaf53e; bne $r15, $r16, inst_error
    li.w $r12, 0x0e437d14; li.w $r13, 0xf76494cd; mulh.wu $r15, $r12, $r13; li.w $r16, 0x0dc8b855; bne $r15, $r16, inst_error
    li.w $r12, 0x36f97280; li.w $r13, 0xd2dc44ac; mulh.wu $r15, $r12, $r13; li.w $r16, 0x2d47ed0a; bne $r15, $r16, inst_error
    li.w $r12, 0xc0196848; li.w $r13, 0x23e672e2; mulh.wu $r15, $r12, $r13; li.w $r16, 0x1af0664a; bne $r15, $r16, inst_error
    li.w $r12, 0xad0af755; li.w $r13, 0x46ab8a3c; mulh.wu $r15, $r12, $r13; li.w $r16, 0x2fc4f364; bne $r15, $r16, inst_error
    li.w $r12, 0x78c438e8; li.w $r13, 0xb59296e0; mulh.wu $r15, $r12, $r13; li.w $r16, 0x55a7e351; bne $r15, $r16, inst_error
    li.w $r12, 0x95417ec8; li.w $r13, 0xcdef10ec; mulh.wu $r15, $r12, $r13; li.w $r16, 0x7810d489; bne $r15, $r16, inst_error
    li.w $r12, 0xabd42ba4; li.w $r13, 0x9f4dfd40; mulh.wu $r15, $r12, $r13; li.w $r16, 0x6aed1fe7; bne $r15, $r16, inst_error
    li.w $r12, 0x9c767890; li.w $r13, 0x13f10784; mulh.wu $r15, $r12, $r13; li.w $r16, 0x0c301b12; bne $r15, $r16, inst_error
    li.w $r12, 0x337174a4; li.w $r13, 0x53b2a442; mulh.wu $r15, $r12, $r13; li.w $r16, 0x10d1aeb6; bne $r15, $r16, inst_error
    li.w $r12, 0x8bbc4c00; li.w $r13, 0x4f9ed450; mulh.wu $r15, $r12, $r13; li.w $r16, 0x2b75cd8e; bne $r15, $r16, inst_error
    li.w $r12, 0x98e39c2e; li.w $r13, 0xdb32e0b0; mulh.wu $r15, $r12, $r13; li.w $r16, 0x82e91940; bne $r15, $r16, inst_error
    li.w $r12, 0x6b08ed68; li.w $r13, 0x1ec93800; mulh.wu $r15, $r12, $r13; li.w $r16, 0x0cdf2d3e; bne $r15, $r16, inst_error
    li.w $r12, 0xdedaacc4; li.w $r13, 0x652203d0; mulh.wu $r15, $r12, $r13; li.w $r16, 0x5809e285; bne $r15, $r16, inst_error
    li.w $r12, 0xa7151a96; li.w $r13, 0x4efab6b6; mulh.wu $r15, $r12, $r13; li.w $r16, 0x338c0ff5; bne $r15, $r16, inst_error
    li.w $r12, 0xb11df5a0; li.w $r13, 0x7312ec50; mulh.wu $r15, $r12, $r13; li.w $r16, 0x4f9d8cf1; bne $r15, $r16, inst_error
    li.w $r12, 0x800e4cb0; li.w $r13, 0x39de6540; mulh.wu $r15, $r12, $r13; li.w $r16, 0x1cf26e1f; bne $r15, $r16, inst_error
    li.w $r12, 0x6ba01e66; li.w $r13, 0x6141f7c8; mulh.wu $r15, $r12, $r13; li.w $r16, 0x28e36757; bne $r15, $r16, inst_error
    li.w $r12, 0x05c01d30; li.w $r13, 0x51b5330e; mulh.wu $r15, $r12, $r13; li.w $r16, 0x01d5db36; bne $r15, $r16, inst_error
    li.w $r12, 0x7b685660; li.w $r13, 0x557152ba; mulh.wu $r15, $r12, $r13; li.w $r16, 0x2930459d; bne $r15, $r16, inst_error
    li.w $r12, 0x4396b2d6; li.w $r13, 0x7d40f2c4; mulh.wu $r15, $r12, $r13; li.w $r16, 0x2111bb17; bne $r15, $r16, inst_error
    li.w $r12, 0xa33d54b2; li.w $r13, 0x1ff7f310; mulh.wu $r15, $r12, $r13; li.w $r16, 0x1462886b; bne $r15, $r16, inst_error
    li.w $r12, 0x827d4976; li.w $r13, 0x46c7d260; mulh.wu $r15, $r12, $r13; li.w $r16, 0x24141cb6; bne $r15, $r16, inst_error
    li.w $r12, 0xb2c46680; li.w $r13, 0x2106dc9b; mulh.wu $r15, $r12, $r13; li.w $r16, 0x17101bdd; bne $r15, $r16, inst_error
    li.w $r12, 0x61e8744c; li.w $r13, 0xf0485710; mulh.wu $r15, $r12, $r13; li.w $r16, 0x5be597b4; bne $r15, $r16, inst_error
    li.w $r12, 0x510523c0; li.w $r13, 0xc4eef4ec; mulh.wu $r15, $r12, $r13; li.w $r16, 0x3e538fa9; bne $r15, $r16, inst_error
    li.w $r12, 0x6cab5300; li.w $r13, 0x24d47fd0; mulh.wu $r15, $r12, $r13; li.w $r16, 0x0fa24bce; bne $r15, $r16, inst_error
    li.w $r12, 0x113f38b0; li.w $r13, 0x960f0fb8; mulh.wu $r15, $r12, $r13; li.w $r16, 0x0a1c0efa; bne $r15, $r16, inst_error
    li.w $r12, 0xa4cd966c; li.w $r13, 0x8946015e; mulh.wu $r15, $r12, $r13; li.w $r16, 0x585f1698; bne $r15, $r16, inst_error
    li.w $r12, 0x997ab490; li.w $r13, 0x8318fc14; mulh.wu $r15, $r12, $r13; li.w $r16, 0x4e98c507; bne $r15, $r16, inst_error
    li.w $r12, 0x3bf04cfc; li.w $r13, 0x4303bb23; mulh.wu $r15, $r12, $r13; li.w $r16, 0x0fb0c3c7; bne $r15, $r16, inst_error
    li.w $r12, 0xf58f5fa3; li.w $r13, 0x6095f500; mulh.wu $r15, $r12, $r13; li.w $r16, 0x5ca59b52; bne $r15, $r16, inst_error
    li.w $r12, 0xabaa4e80; li.w $r13, 0x370ea7f2; mulh.wu $r15, $r12, $r13; li.w $r16, 0x24eb6acc; bne $r15, $r16, inst_error
    li.w $r12, 0x3a8cff75; li.w $r13, 0xc7c89600; mulh.wu $r15, $r12, $r13; li.w $r16, 0x2db17b0a; bne $r15, $r16, inst_error
    li.w $r12, 0x6952957c; li.w $r13, 0x9f95ba00; mulh.wu $r15, $r12, $r13; li.w $r16, 0x41a7e46f; bne $r15, $r16, inst_error
    li.w $r12, 0xf003fcc0; li.w $r13, 0x6bf9ab92; mulh.wu $r15, $r12, $r13; li.w $r16, 0x653bbf60; bne $r15, $r16, inst_error
    li.w $r12, 0x948df508; li.w $r13, 0x9aa84872; mulh.wu $r15, $r12, $r13; li.w $r16, 0x59bf0c99; bne $r15, $r16, inst_error
    li.w $r12, 0xe14aa0c0; li.w $r13, 0xf0d16230; mulh.wu $r15, $r12, $r13; li.w $r16, 0xd3ee3b0a; bne $r15, $r16, inst_error
    li.w $r12, 0xb1d8a680; li.w $r13, 0x99f2fdf0; mulh.wu $r15, $r12, $r13; li.w $r16, 0x6af34ab9; bne $r15, $r16, inst_error
    li.w $r12, 0x06d53ad0; li.w $r13, 0x6289382a; mulh.wu $r15, $r12, $r13; li.w $r16, 0x02a14a1f; bne $r15, $r16, inst_error
    li.w $r12, 0xb406d184; li.w $r13, 0xce15399c; mulh.wu $r15, $r12, $r13; li.w $r16, 0x90ec69aa; bne $r15, $r16, inst_error
    li.w $r12, 0xff4c6260; li.w $r13, 0xf71b2a00; mulh.wu $r15, $r12, $r13; li.w $r16, 0xf66dc9db; bne $r15, $r16, inst_error
    li.w $r12, 0x02f13cac; li.w $r13, 0xea42d2c0; mulh.wu $r15, $r12, $r13; li.w $r16, 0x02b14612; bne $r15, $r16, inst_error
    li.w $r12, 0x7fb89370; li.w $r13, 0x6495a978; mulh.wu $r15, $r12, $r13; li.w $r16, 0x322ec492; bne $r15, $r16, inst_error
    li.w $r12, 0xdb044c80; li.w $r13, 0x5bb448cc; mulh.wu $r15, $r12, $r13; li.w $r16, 0x4e74c47f; bne $r15, $r16, inst_error
    li.w $r12, 0xa90dec6c; li.w $r13, 0xf03cd014; mulh.wu $r15, $r12, $r13; li.w $r16, 0x9ea53651; bne $r15, $r16, inst_error
    li.w $r12, 0x72b3e604; li.w $r13, 0x3ccf167e; mulh.wu $r15, $r12, $r13; li.w $r16, 0x1b3ef373; bne $r15, $r16, inst_error
    li.w $r12, 0xf181714c; li.w $r13, 0xe0304af4; mulh.wu $r15, $r12, $r13; li.w $r16, 0xd37ed21d; bne $r15, $r16, inst_error
    li.w $r12, 0x7a1bddc0; li.w $r13, 0x5b74305c; mulh.wu $r15, $r12, $r13; li.w $r16, 0x2b9f5384; bne $r15, $r16, inst_error
    li.w $r12, 0x53901b70; li.w $r13, 0x582d6690; mulh.wu $r15, $r12, $r13; li.w $r16, 0x1cc85b3d; bne $r15, $r16, inst_error
    li.w $r12, 0x1abfafc4; li.w $r13, 0x4c4d5a00; mulh.wu $r15, $r12, $r13; li.w $r16, 0x07f8fd3d; bne $r15, $r16, inst_error
    li.w $r12, 0xc401c3d9; li.w $r13, 0x644283da; mulh.wu $r15, $r12, $r13; li.w $r16, 0x4cc39de9; bne $r15, $r16, inst_error
    li.w $r12, 0xc3d92a7c; li.w $r13, 0x10f8e302; mulh.wu $r15, $r12, $r13; li.w $r16, 0x0cfbfab4; bne $r15, $r16, inst_error
    li.w $r12, 0x58474c02; li.w $r13, 0x9f6992fe; mulh.wu $r15, $r12, $r13; li.w $r16, 0x36f8b023; bne $r15, $r16, inst_error
    li.w $r12, 0xbb0f6845; li.w $r13, 0x164774b0; mulh.wu $r15, $r12, $r13; li.w $r16, 0x1047897f; bne $r15, $r16, inst_error
    li.w $r12, 0x3a0547ba; li.w $r13, 0x97b4583e; mulh.wu $r15, $r12, $r13; li.w $r16, 0x2261fd05; bne $r15, $r16, inst_error
    li.w $r12, 0xc418111b; li.w $r13, 0xf49130d0; mulh.wu $r15, $r12, $r13; li.w $r16, 0xbb562753; bne $r15, $r16, inst_error
    li.w $r12, 0x696fdee5; li.w $r13, 0x716028d0; mulh.wu $r15, $r12, $r13; li.w $r16, 0x2eb1fc25; bne $r15, $r16, inst_error
    li.w $r12, 0x6b09a660; li.w $r13, 0xe6f17192; mulh.wu $r15, $r12, $r13; li.w $r16, 0x608f9f0c; bne $r15, $r16, inst_error
    li.w $r12, 0xe52e58ea; li.w $r13, 0xc1a21800; mulh.wu $r15, $r12, $r13; li.w $r16, 0xad590dd9; bne $r15, $r16, inst_error
    li.w $r12, 0x1060c3f6; li.w $r13, 0x0eede718; mulh.wu $r15, $r12, $r13; li.w $r16, 0x00f48315; bne $r15, $r16, inst_error
    li.w $r12, 0xdf061f84; li.w $r13, 0xd9f51b0d; mulh.wu $r15, $r12, $r13; li.w $r16, 0xbde1b924; bne $r15, $r16, inst_error
    li.w $r12, 0x2ef301f4; li.w $r13, 0x5f1a8bd0; mulh.wu $r15, $r12, $r13; li.w $r16, 0x11710c0b; bne $r15, $r16, inst_error
    li.w $r12, 0x46c24000; li.w $r13, 0x73818980; mulh.wu $r15, $r12, $r13; li.w $r16, 0x1fed10a3; bne $r15, $r16, inst_error
    li.w $r12, 0x257e27d0; li.w $r13, 0x1dcebf84; mulh.wu $r15, $r12, $r13; li.w $r16, 0x045d9213; bne $r15, $r16, inst_error
    li.w $r12, 0xa94202b9; li.w $r13, 0x78c54868; mulh.wu $r15, $r12, $r13; li.w $r16, 0x4fd960f2; bne $r15, $r16, inst_error
    li.w $r12, 0x2981ba00; li.w $r13, 0xfa88781d; mulh.wu $r15, $r12, $r13; li.w $r16, 0x289ed008; bne $r15, $r16, inst_error
    li.w $r12, 0x3ee64b08; li.w $r13, 0x5534a83a; mulh.wu $r15, $r12, $r13; li.w $r16, 0x14ef6706; bne $r15, $r16, inst_error
    li.w $r12, 0x9178bce0; li.w $r13, 0x6bd37980; mulh.wu $r15, $r12, $r13; li.w $r16, 0x3d45a280; bne $r15, $r16, inst_error
    li.w $r12, 0x0bcfbae8; li.w $r13, 0xe12afb00; mulh.wu $r15, $r12, $r13; li.w $r16, 0x0a638eef; bne $r15, $r16, inst_error
    li.w $r12, 0xeea80fda; li.w $r13, 0x99dd6bd0; mulh.wu $r15, $r12, $r13; li.w $r16, 0x8f70dd11; bne $r15, $r16, inst_error
    li.w $r12, 0xcd7ccc40; li.w $r13, 0x79ffffca; mulh.wu $r15, $r12, $r13; li.w $r16, 0x61ed792b; bne $r15, $r16, inst_error
    li.w $r12, 0xf0d9a3fc; li.w $r13, 0xbd1da000; mulh.wu $r15, $r12, $r13; li.w $r16, 0xb1ec8d40; bne $r15, $r16, inst_error
    li.w $r12, 0x575f3e98; li.w $r13, 0x71669498; mulh.wu $r15, $r12, $r13; li.w $r16, 0x26b40d4a; bne $r15, $r16, inst_error
    li.w $r12, 0x1cc38b14; li.w $r13, 0x5973913a; mulh.wu $r15, $r12, $r13; li.w $r16, 0x0a0cf782; bne $r15, $r16, inst_error
    li.w $r12, 0x89c6f81f; li.w $r13, 0xa2802db0; mulh.wu $r15, $r12, $r13; li.w $r16, 0x5774e516; bne $r15, $r16, inst_error
    li.w $r12, 0x455a3838; li.w $r13, 0x847ad600; mulh.wu $r15, $r12, $r13; li.w $r16, 0x23e3cbf5; bne $r15, $r16, inst_error
    li.w $r12, 0x3dfb93e4; li.w $r13, 0x4f109ba8; mulh.wu $r15, $r12, $r13; li.w $r16, 0x1324a80c; bne $r15, $r16, inst_error
    li.w $r12, 0x7a51a910; li.w $r13, 0x2038e3d6; mulh.wu $r15, $r12, $r13; li.w $r16, 0x0f6563db; bne $r15, $r16, inst_error
    li.w $r12, 0xa0042132; li.w $r13, 0x78d9f754; mulh.wu $r15, $r12, $r13; li.w $r16, 0x4b8a2da8; bne $r15, $r16, inst_error
    li.w $r12, 0x194f7a4e; li.w $r13, 0xc9fad040; mulh.wu $r15, $r12, $r13; li.w $r16, 0x13f8333b; bne $r15, $r16, inst_error
    li.w $r12, 0x28e55f80; li.w $r13, 0xa3d2a69c; mulh.wu $r15, $r12, $r13; li.w $r16, 0x1a2bb294; bne $r15, $r16, inst_error
    li.w $r12, 0xbcc4d7a8; li.w $r13, 0x923c7e90; mulh.wu $r15, $r12, $r13; li.w $r16, 0x6bd4de73; bne $r15, $r16, inst_error
    li.w $r12, 0x9f32e060; li.w $r13, 0x3178e100; mulh.wu $r15, $r12, $r13; li.w $r16, 0x1ec3e8b7; bne $r15, $r16, inst_error
    li.w $r12, 0xe9b87330; li.w $r13, 0x372b4f78; mulh.wu $r15, $r12, $r13; li.w $r16, 0x325e2b48; bne $r15, $r16, inst_error
    li.w $r12, 0x10483e78; li.w $r13, 0xefa70d6a; mulh.wu $r15, $r12, $r13; li.w $r16, 0x0f3e124d; bne $r15, $r16, inst_error
    li.w $r12, 0x6285d9a4; li.w $r13, 0x48238818; mulh.wu $r15, $r12, $r13; li.w $r16, 0x1bc351e3; bne $r15, $r16, inst_error
    li.w $r12, 0x8ee83024; li.w $r13, 0x2a47e0d0; mulh.wu $r15, $r12, $r13; li.w $r16, 0x179a37ca; bne $r15, $r16, inst_error
    li.w $r12, 0x4f1eb000; li.w $r13, 0x22e9e3b4; mulh.wu $r15, $r12, $r13; li.w $r16, 0x0aca5cae; bne $r15, $r16, inst_error
    li.w $r12, 0x57aea34c; li.w $r13, 0x00000000; mulh.wu $r15, $r12, $r13; li.w $r16, 0x00000000; bne $r15, $r16, inst_error
    li.w $r12, 0x04dbdd80; li.w $r13, 0x00000000; mulh.wu $r15, $r12, $r13; li.w $r16, 0x00000000; bne $r15, $r16, inst_error
    li.w $r12, 0x79d5a6b7; li.w $r13, 0x00000000; mulh.wu $r15, $r12, $r13; li.w $r16, 0x00000000; bne $r15, $r16, inst_error
    li.w $r12, 0x9ad90f8c; li.w $r13, 0x00000000; mulh.wu $r15, $r12, $r13; li.w $r16, 0x00000000; bne $r15, $r16, inst_error
    li.w $r12, 0x8237f918; li.w $r13, 0x00000000; mulh.wu $r15, $r12, $r13; li.w $r16, 0x00000000; bne $r15, $r16, inst_error
    li.w $r12, 0xc5ecadb0; li.w $r13, 0x00000000; mulh.wu $r15, $r12, $r13; li.w $r16, 0x00000000; bne $r15, $r16, inst_error
    li.w $r12, 0x00000000; li.w $r13, 0xcec8f500; mulh.wu $r15, $r12, $r13; li.w $r16, 0x00000000; bne $r15, $r16, inst_error
    li.w $r12, 0x00000000; li.w $r13, 0x0fed823c; mulh.wu $r15, $r12, $r13; li.w $r16, 0x00000000; bne $r15, $r16, inst_error
    li.w $r12, 0x00000000; li.w $r13, 0x3ac7f7a0; mulh.wu $r15, $r12, $r13; li.w $r16, 0x00000000; bne $r15, $r16, inst_error
    li.w $r12, 0x00000000; li.w $r13, 0x04e4cfaa; mulh.wu $r15, $r12, $r13; li.w $r16, 0x00000000; bne $r15, $r16, inst_error
    li.w $r12, 0x00000000; li.w $r13, 0x00000000; mulh.wu $r15, $r12, $r13; li.w $r16, 0x00000000; bne $r15, $r16, inst_error
###detect exception
    bne $r25, $r0, inst_error
   
###score ++
    addi.w $r26, $r26, 1
###output ($r23<<24)|$r26
inst_error:
    slli.w $r13, $r23, 24
    ;;;
    or $r12, $r13, $r26
    ;;;
    st.w $r12, $r24, 0
    jirl $r0, $r1, 0
.cfi_endproc ; .size n34_mulh_wu_test,.-n34_mulh_wu_test;
