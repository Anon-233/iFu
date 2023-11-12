# 1 "n33_mulh_w.S"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "n33_mulh_w.S"
# 1 "../include/asm.h" 1



# 1 "../include/regdef.h" 1
# 5 "../include/asm.h" 2
# 1 "../include/sysdep.h" 1
# 6 "../include/asm.h" 2
# 2 "n33_mulh_w.S" 2
# 1 "../include/regdef.h" 1
# 3 "n33_mulh_w.S" 2
# 1 "../include/inst_test.h" 1

# 1 "../include/cpu_cde.h" 1
# 1 "../include/lab_config.h" 1
# 2 "../include/cpu_cde.h" 2
# 3 "../include/inst_test.h" 2
# 4 "n33_mulh_w.S" 2

.text; .globl n33_mulh_w_test; .align 3; .cfi_startproc ; .type n33_mulh_w_test, @function; n33_mulh_w_test:

    addi.w $r23, $r23 ,1
    li.w $r25, 0x0
###test inst
    li.w $r12, 0x45b90738; li.w $r13, 0xd70d64f0; mulh.w $r15, $r12, $r13; li.w $r16, 0xf4d903bb; bne $r15, $r16, inst_error
    li.w $r12, 0x99a451b0; li.w $r13, 0xbe3d9998; mulh.w $r15, $r12, $r13; li.w $r16, 0x1a4b01ae; bne $r15, $r16, inst_error
    li.w $r12, 0x85931c58; li.w $r13, 0xfb710fb5; mulh.w $r15, $r12, $r13; li.w $r16, 0x022e0ede; bne $r15, $r16, inst_error
    li.w $r12, 0x650e4043; li.w $r13, 0x64c17218; mulh.w $r15, $r12, $r13; li.w $r16, 0x27c5ede2; bne $r15, $r16, inst_error
    li.w $r12, 0xa00c6c50; li.w $r13, 0x8e9df080; mulh.w $r15, $r12, $r13; li.w $r16, 0x2a7f453e; bne $r15, $r16, inst_error
    li.w $r12, 0x99c874b6; li.w $r13, 0xd7ce83e0; mulh.w $r15, $r12, $r13; li.w $r16, 0x100c6ff4; bne $r15, $r16, inst_error
    li.w $r12, 0x1c62f360; li.w $r13, 0x34580400; mulh.w $r15, $r12, $r13; li.w $r16, 0x05cddbe4; bne $r15, $r16, inst_error
    li.w $r12, 0x99b80b00; li.w $r13, 0x6c463000; mulh.w $r15, $r12, $r13; li.w $r16, 0xd4bd99c9; bne $r15, $r16, inst_error
    li.w $r12, 0xdc823390; li.w $r13, 0x5208f838; mulh.w $r15, $r12, $r13; li.w $r16, 0xf4a0762c; bne $r15, $r16, inst_error
    li.w $r12, 0xe53080d8; li.w $r13, 0x848a9c5a; mulh.w $r15, $r12, $r13; li.w $r16, 0x0cedfd5c; bne $r15, $r16, inst_error
    li.w $r12, 0x7f2163d8; li.w $r13, 0xab5bba80; mulh.w $r15, $r12, $r13; li.w $r16, 0xd5f77755; bne $r15, $r16, inst_error
    li.w $r12, 0xea7b88c0; li.w $r13, 0x23eed510; mulh.w $r15, $r12, $r13; li.w $r16, 0xfcfad0a2; bne $r15, $r16, inst_error
    li.w $r12, 0x7389b4fd; li.w $r13, 0xea063940; mulh.w $r15, $r12, $r13; li.w $r16, 0xf614f983; bne $r15, $r16, inst_error
    li.w $r12, 0xbcdf9b20; li.w $r13, 0xc1451978; mulh.w $r15, $r12, $r13; li.w $r16, 0x1072da6a; bne $r15, $r16, inst_error
    li.w $r12, 0xdcacfd50; li.w $r13, 0x809d0a80; mulh.w $r15, $r12, $r13; li.w $r16, 0x1193d5fc; bne $r15, $r16, inst_error
    li.w $r12, 0x55ed3100; li.w $r13, 0xbe5ba9f2; mulh.w $r15, $r12, $r13; li.w $r16, 0xe9f79db9; bne $r15, $r16, inst_error
    li.w $r12, 0xcedb5fd8; li.w $r13, 0xe1793b60; mulh.w $r15, $r12, $r13; li.w $r16, 0x05dc29af; bne $r15, $r16, inst_error
    li.w $r12, 0x9d32f1b0; li.w $r13, 0xbb2016b8; mulh.w $r15, $r12, $r13; li.w $r16, 0x1a94e275; bne $r15, $r16, inst_error
    li.w $r12, 0x7091ae43; li.w $r13, 0xdb390460; mulh.w $r15, $r12, $r13; li.w $r16, 0xefd4042c; bne $r15, $r16, inst_error
    li.w $r12, 0x549bf440; li.w $r13, 0xd1dc9f40; mulh.w $r15, $r12, $r13; li.w $r16, 0xf0c048d0; bne $r15, $r16, inst_error
    li.w $r12, 0x63b241cc; li.w $r13, 0x48aefe14; mulh.w $r15, $r12, $r13; li.w $r16, 0x1c4e489c; bne $r15, $r16, inst_error
    li.w $r12, 0x4c925040; li.w $r13, 0x0855d2c8; mulh.w $r15, $r12, $r13; li.w $r16, 0x027e3e22; bne $r15, $r16, inst_error
    li.w $r12, 0xdb2dfd2c; li.w $r13, 0x6c0e9f09; mulh.w $r15, $r12, $r13; li.w $r16, 0xf0754c72; bne $r15, $r16, inst_error
    li.w $r12, 0xdfdc9250; li.w $r13, 0xbf1f15c3; mulh.w $r15, $r12, $r13; li.w $r16, 0x082517d4; bne $r15, $r16, inst_error
    li.w $r12, 0x1b339b35; li.w $r13, 0x98c14bc0; mulh.w $r15, $r12, $r13; li.w $r16, 0xf50792e7; bne $r15, $r16, inst_error
    li.w $r12, 0xc8618b98; li.w $r13, 0x69452a40; mulh.w $r15, $r12, $r13; li.w $r16, 0xe920fb5e; bne $r15, $r16, inst_error
    li.w $r12, 0x2aea0580; li.w $r13, 0x7f50d684; mulh.w $r15, $r12, $r13; li.w $r16, 0x1557a5d1; bne $r15, $r16, inst_error
    li.w $r12, 0x5c69f5ec; li.w $r13, 0x9ee23bd2; mulh.w $r15, $r12, $r13; li.w $r16, 0xdcf11afe; bne $r15, $r16, inst_error
    li.w $r12, 0xb7b66b40; li.w $r13, 0x8b50c179; mulh.w $r15, $r12, $r13; li.w $r16, 0x20f2d35b; bne $r15, $r16, inst_error
    li.w $r12, 0x514e33b6; li.w $r13, 0x7dc39988; mulh.w $r15, $r12, $r13; li.w $r16, 0x27f14e94; bne $r15, $r16, inst_error
    li.w $r12, 0x27c24e12; li.w $r13, 0xbc0e6874; mulh.w $r15, $r12, $r13; li.w $r16, 0xf572a01c; bne $r15, $r16, inst_error
    li.w $r12, 0xe7e6eddc; li.w $r13, 0x13a7cad0; mulh.w $r15, $r12, $r13; li.w $r16, 0xfe265835; bne $r15, $r16, inst_error
    li.w $r12, 0xa85111c0; li.w $r13, 0xa29d50f0; mulh.w $r15, $r12, $r13; li.w $r16, 0x1ffc597a; bne $r15, $r16, inst_error
    li.w $r12, 0x73d52eb8; li.w $r13, 0x142ba310; mulh.w $r15, $r12, $r13; li.w $r16, 0x0920663d; bne $r15, $r16, inst_error
    li.w $r12, 0x41156884; li.w $r13, 0x794c5fb2; mulh.w $r15, $r12, $r13; li.w $r16, 0x1ed68915; bne $r15, $r16, inst_error
    li.w $r12, 0xa8774820; li.w $r13, 0xb2cf0480; mulh.w $r15, $r12, $r13; li.w $r16, 0x1a64deef; bne $r15, $r16, inst_error
    li.w $r12, 0xb69bcb80; li.w $r13, 0x88d55520; mulh.w $r15, $r12, $r13; li.w $r16, 0x2229cfd4; bne $r15, $r16, inst_error
    li.w $r12, 0xe84175d8; li.w $r13, 0x94048f1c; mulh.w $r15, $r12, $r13; li.w $r16, 0x0a03f608; bne $r15, $r16, inst_error
    li.w $r12, 0x6fdedbd8; li.w $r13, 0x67dd7f60; mulh.w $r15, $r12, $r13; li.w $r16, 0x2d637581; bne $r15, $r16, inst_error
    li.w $r12, 0xa2319526; li.w $r13, 0xd5f88700; mulh.w $r15, $r12, $r13; li.w $r16, 0x0f669a83; bne $r15, $r16, inst_error
    li.w $r12, 0x61f8b9bc; li.w $r13, 0x146e6d38; mulh.w $r15, $r12, $r13; li.w $r16, 0x07d1b12e; bne $r15, $r16, inst_error
    li.w $r12, 0xb9002828; li.w $r13, 0x0310a1b9; mulh.w $r15, $r12, $r13; li.w $r16, 0xff2663a0; bne $r15, $r16, inst_error
    li.w $r12, 0xb4418f47; li.w $r13, 0x943f129c; mulh.w $r15, $r12, $r13; li.w $r16, 0x1fe1ae2e; bne $r15, $r16, inst_error
    li.w $r12, 0xd7011f8c; li.w $r13, 0x70d8ea80; mulh.w $r15, $r12, $r13; li.w $r16, 0xededc132; bne $r15, $r16, inst_error
    li.w $r12, 0x058b9998; li.w $r13, 0x55395538; mulh.w $r15, $r12, $r13; li.w $r16, 0x01d897ed; bne $r15, $r16, inst_error
    li.w $r12, 0xc13b7fc0; li.w $r13, 0xda192fbb; mulh.w $r15, $r12, $r13; li.w $r16, 0x094afe25; bne $r15, $r16, inst_error
    li.w $r12, 0x776d24b0; li.w $r13, 0x66f0a9a4; mulh.w $r15, $r12, $r13; li.w $r16, 0x3005c214; bne $r15, $r16, inst_error
    li.w $r12, 0x6c6ae338; li.w $r13, 0x5c4abc80; mulh.w $r15, $r12, $r13; li.w $r16, 0x27161062; bne $r15, $r16, inst_error
    li.w $r12, 0x9dc090e0; li.w $r13, 0xb6324980; mulh.w $r15, $r12, $r13; li.w $r16, 0x1c530986; bne $r15, $r16, inst_error
    li.w $r12, 0x86d609de; li.w $r13, 0xcd4bcb2e; mulh.w $r15, $r12, $r13; li.w $r16, 0x17ff7c93; bne $r15, $r16, inst_error
    li.w $r12, 0x1400c7dc; li.w $r13, 0x466a6d5e; mulh.w $r15, $r12, $r13; li.w $r16, 0x05808784; bne $r15, $r16, inst_error
    li.w $r12, 0xa2d88860; li.w $r13, 0x26423686; mulh.w $r15, $r12, $r13; li.w $r16, 0xf2140c3a; bne $r15, $r16, inst_error
    li.w $r12, 0x6770770a; li.w $r13, 0x812cbe10; mulh.w $r15, $r12, $r13; li.w $r16, 0xccc14912; bne $r15, $r16, inst_error
    li.w $r12, 0x95627048; li.w $r13, 0xc1bae8ca; mulh.w $r15, $r12, $r13; li.w $r16, 0x19eeeef0; bne $r15, $r16, inst_error
    li.w $r12, 0x1dbadda0; li.w $r13, 0x5d2b0f50; mulh.w $r15, $r12, $r13; li.w $r16, 0x0ad1e2ad; bne $r15, $r16, inst_error
    li.w $r12, 0xc7cf4f96; li.w $r13, 0x7dd33820; mulh.w $r15, $r12, $r13; li.w $r16, 0xe461dd69; bne $r15, $r16, inst_error
    li.w $r12, 0xa1d8f960; li.w $r13, 0xb83e3183; mulh.w $r15, $r12, $r13; li.w $r16, 0x1a641a33; bne $r15, $r16, inst_error
    li.w $r12, 0xcc2c955e; li.w $r13, 0x63c2877e; mulh.w $r15, $r12, $r13; li.w $r16, 0xebcddc1e; bne $r15, $r16, inst_error
    li.w $r12, 0xd2d44530; li.w $r13, 0x602b39e6; mulh.w $r15, $r12, $r13; li.w $r16, 0xef07f962; bne $r15, $r16, inst_error
    li.w $r12, 0x886c3ad7; li.w $r13, 0xe011a4c0; mulh.w $r15, $r12, $r13; li.w $r16, 0x0eea3ae0; bne $r15, $r16, inst_error
    li.w $r12, 0x0c45d0c8; li.w $r13, 0x830e02fb; mulh.w $r15, $r12, $r13; li.w $r16, 0xfa029504; bne $r15, $r16, inst_error
    li.w $r12, 0x49979c44; li.w $r13, 0x298742f0; mulh.w $r15, $r12, $r13; li.w $r16, 0x0bf02a38; bne $r15, $r16, inst_error
    li.w $r12, 0x2037c800; li.w $r13, 0xfb355f34; mulh.w $r15, $r12, $r13; li.w $r16, 0xff65a09f; bne $r15, $r16, inst_error
    li.w $r12, 0x21e68aeb; li.w $r13, 0xc1cc4ec0; mulh.w $r15, $r12, $r13; li.w $r16, 0xf7c351f4; bne $r15, $r16, inst_error
    li.w $r12, 0xe2c488b8; li.w $r13, 0x8ed6a9d8; mulh.w $r15, $r12, $r13; li.w $r16, 0x0cebf803; bne $r15, $r16, inst_error
    li.w $r12, 0x0622c000; li.w $r13, 0x849e669e; mulh.w $r15, $r12, $r13; li.w $r16, 0xfd0af6e8; bne $r15, $r16, inst_error
    li.w $r12, 0xfe11325e; li.w $r13, 0x5a980480; mulh.w $r15, $r12, $r13; li.w $r16, 0xff50e5e2; bne $r15, $r16, inst_error
    li.w $r12, 0xb582a660; li.w $r13, 0x27161c30; mulh.w $r15, $r12, $r13; li.w $r16, 0xf4a0785f; bne $r15, $r16, inst_error
    li.w $r12, 0xde436ee0; li.w $r13, 0x0b8fd2ea; mulh.w $r15, $r12, $r13; li.w $r16, 0xfe79f1a3; bne $r15, $r16, inst_error
    li.w $r12, 0x3ca5ebcc; li.w $r13, 0x7fca89b0; mulh.w $r15, $r12, $r13; li.w $r16, 0x1e464b84; bne $r15, $r16, inst_error
    li.w $r12, 0xed8ac2a2; li.w $r13, 0x8e11d628; mulh.w $r15, $r12, $r13; li.w $r16, 0x0836ec19; bne $r15, $r16, inst_error
    li.w $r12, 0xee62ac9c; li.w $r13, 0x446aed90; mulh.w $r15, $r12, $r13; li.w $r16, 0xfb4ada5c; bne $r15, $r16, inst_error
    li.w $r12, 0xa5a41fa0; li.w $r13, 0x901ecf7a; mulh.w $r15, $r12, $r13; li.w $r16, 0x277d522a; bne $r15, $r16, inst_error
    li.w $r12, 0x1665a95c; li.w $r13, 0x01fa0f1c; mulh.w $r15, $r12, $r13; li.w $r16, 0x002c4643; bne $r15, $r16, inst_error
    li.w $r12, 0xf760c288; li.w $r13, 0x024d9a70; mulh.w $r15, $r12, $r13; li.w $r16, 0xffec246c; bne $r15, $r16, inst_error
    li.w $r12, 0xb91b1700; li.w $r13, 0xff6a7770; mulh.w $r15, $r12, $r13; li.w $r16, 0x0029690d; bne $r15, $r16, inst_error
    li.w $r12, 0x38a15d4c; li.w $r13, 0x4d378f48; mulh.w $r15, $r12, $r13; li.w $r16, 0x1114d36c; bne $r15, $r16, inst_error
    li.w $r12, 0xe1d0a988; li.w $r13, 0x29062820; mulh.w $r15, $r12, $r13; li.w $r16, 0xfb29b14f; bne $r15, $r16, inst_error
    li.w $r12, 0xb657c3ec; li.w $r13, 0x42373c21; mulh.w $r15, $r12, $r13; li.w $r16, 0xecf2bc11; bne $r15, $r16, inst_error
    li.w $r12, 0x8cd72e00; li.w $r13, 0x0657e392; mulh.w $r15, $r12, $r13; li.w $r16, 0xfd2581d5; bne $r15, $r16, inst_error
    li.w $r12, 0xcffca4a4; li.w $r13, 0xf52aba30; mulh.w $r15, $r12, $r13; li.w $r16, 0x02082174; bne $r15, $r16, inst_error
    li.w $r12, 0xd823b826; li.w $r13, 0xed601012; mulh.w $r15, $r12, $r13; li.w $r16, 0x02e66439; bne $r15, $r16, inst_error
    li.w $r12, 0x306f7f24; li.w $r13, 0x6384a554; mulh.w $r15, $r12, $r13; li.w $r16, 0x12d436f0; bne $r15, $r16, inst_error
    li.w $r12, 0x0c59e770; li.w $r13, 0x3e387808; mulh.w $r15, $r12, $r13; li.w $r16, 0x03007f82; bne $r15, $r16, inst_error
    li.w $r12, 0xc1dd451c; li.w $r13, 0xe125f520; mulh.w $r15, $r12, $r13; li.w $r16, 0x077cfe1d; bne $r15, $r16, inst_error
    li.w $r12, 0xef4e68d4; li.w $r13, 0x9ff2ad9b; mulh.w $r15, $r12, $r13; li.w $r16, 0x06437714; bne $r15, $r16, inst_error
    li.w $r12, 0x7ef6ec24; li.w $r13, 0xb177da10; mulh.w $r15, $r12, $r13; li.w $r16, 0xd90d3e0e; bne $r15, $r16, inst_error
    li.w $r12, 0x6fb25f72; li.w $r13, 0x791ebb10; mulh.w $r15, $r12, $r13; li.w $r16, 0x34d8b7a2; bne $r15, $r16, inst_error
    li.w $r12, 0x58101600; li.w $r13, 0xd3840640; mulh.w $r15, $r12, $r13; li.w $r16, 0xf0b29693; bne $r15, $r16, inst_error
    li.w $r12, 0x07affc60; li.w $r13, 0x5ea8d5b0; mulh.w $r15, $r12, $r13; li.w $r16, 0x02d7b093; bne $r15, $r16, inst_error
    li.w $r12, 0xf952c740; li.w $r13, 0x73978b1c; mulh.w $r15, $r12, $r13; li.w $r16, 0xfcfc3bb4; bne $r15, $r16, inst_error
    li.w $r12, 0x8f689828; li.w $r13, 0x91565574; mulh.w $r15, $r12, $r13; li.w $r16, 0x30abad94; bne $r15, $r16, inst_error
    li.w $r12, 0x914d8000; li.w $r13, 0xba3b44b8; mulh.w $r15, $r12, $r13; li.w $r16, 0x1e2b2e25; bne $r15, $r16, inst_error
    li.w $r12, 0x4d2e3cf5; li.w $r13, 0x70e9d5e8; mulh.w $r15, $r12, $r13; li.w $r16, 0x220aba3e; bne $r15, $r16, inst_error
    li.w $r12, 0xb037ad58; li.w $r13, 0x11952040; mulh.w $r15, $r12, $r13; li.w $r16, 0xfa8538dd; bne $r15, $r16, inst_error
    li.w $r12, 0xa4246038; li.w $r13, 0x111ad568; mulh.w $r15, $r12, $r13; li.w $r16, 0xf9dcc982; bne $r15, $r16, inst_error
    li.w $r12, 0xef964a3a; li.w $r13, 0xd18d5d08; mulh.w $r15, $r12, $r13; li.w $r16, 0x02fa582f; bne $r15, $r16, inst_error
    li.w $r12, 0xa4a7728e; li.w $r13, 0x97843fdc; mulh.w $r15, $r12, $r13; li.w $r16, 0x25482191; bne $r15, $r16, inst_error
    li.w $r12, 0xdf30b100; li.w $r13, 0x250933f8; mulh.w $r15, $r12, $r13; li.w $r16, 0xfb40dba2; bne $r15, $r16, inst_error
    li.w $r12, 0x1d5818a4; li.w $r13, 0xe5093304; mulh.w $r15, $r12, $r13; li.w $r16, 0xfce8c358; bne $r15, $r16, inst_error
    li.w $r12, 0x15122298; li.w $r13, 0xcbbb9870; mulh.w $r15, $r12, $r13; li.w $r16, 0xfbb2afa1; bne $r15, $r16, inst_error
    li.w $r12, 0x88ca117e; li.w $r13, 0x0e125f90; mulh.w $r15, $r12, $r13; li.w $r16, 0xf9727eaa; bne $r15, $r16, inst_error
    li.w $r12, 0xdf4ef397; li.w $r13, 0xda63b6b6; mulh.w $r15, $r12, $r13; li.w $r16, 0x04cd8c0a; bne $r15, $r16, inst_error
    li.w $r12, 0x6683ae60; li.w $r13, 0x63fc1988; mulh.w $r15, $r12, $r13; li.w $r16, 0x2809e048; bne $r15, $r16, inst_error
    li.w $r12, 0xe6a56cae; li.w $r13, 0xd0003efb; mulh.w $r15, $r12, $r13; li.w $r16, 0x04c0f562; bne $r15, $r16, inst_error
    li.w $r12, 0x7d58aade; li.w $r13, 0x5b2167ac; mulh.w $r15, $r12, $r13; li.w $r16, 0x2c9edfed; bne $r15, $r16, inst_error
    li.w $r12, 0x61118bd0; li.w $r13, 0x9e016e14; mulh.w $r15, $r12, $r13; li.w $r16, 0xdad7d349; bne $r15, $r16, inst_error
    li.w $r12, 0x7fdd22be; li.w $r13, 0xfdcc9fee; mulh.w $r15, $r12, $r13; li.w $r16, 0xfee69cb0; bne $r15, $r16, inst_error
    li.w $r12, 0x70e273a0; li.w $r13, 0xd87fc19c; mulh.w $r15, $r12, $r13; li.w $r16, 0xee94f3a5; bne $r15, $r16, inst_error
    li.w $r12, 0x3940dad6; li.w $r13, 0xa37c292b; mulh.w $r15, $r12, $r13; li.w $r16, 0xeb4f351f; bne $r15, $r16, inst_error
    li.w $r12, 0xba7ab435; li.w $r13, 0x2322d7d0; mulh.w $r15, $r12, $r13; li.w $r16, 0xf6755053; bne $r15, $r16, inst_error
    li.w $r12, 0x0b238760; li.w $r13, 0x2bff2a02; mulh.w $r15, $r12, $r13; li.w $r16, 0x01ea11f4; bne $r15, $r16, inst_error
    li.w $r12, 0xaa6a9390; li.w $r13, 0x8d3ab108; mulh.w $r15, $r12, $r13; li.w $r16, 0x265e80ac; bne $r15, $r16, inst_error
    li.w $r12, 0xe3667224; li.w $r13, 0xbf514d80; mulh.w $r15, $r12, $r13; li.w $r16, 0x0739e7c6; bne $r15, $r16, inst_error
    li.w $r12, 0x53b1b42e; li.w $r13, 0x7c608578; mulh.w $r15, $r12, $r13; li.w $r16, 0x28a9a18c; bne $r15, $r16, inst_error
    li.w $r12, 0x8241ddf4; li.w $r13, 0x4a8d0e90; mulh.w $r15, $r12, $r13; li.w $r16, 0xdb61c148; bne $r15, $r16, inst_error
    li.w $r12, 0x7cdcd5cf; li.w $r13, 0xe584065f; mulh.w $r15, $r12, $r13; li.w $r16, 0xf3151a6c; bne $r15, $r16, inst_error
    li.w $r12, 0x50445224; li.w $r13, 0xb34e8c5c; mulh.w $r15, $r12, $r13; li.w $r16, 0xe7f4141e; bne $r15, $r16, inst_error
    li.w $r12, 0x436d75a7; li.w $r13, 0x2cb9b728; mulh.w $r15, $r12, $r13; li.w $r16, 0x0bc7ba90; bne $r15, $r16, inst_error
    li.w $r12, 0xdb906f30; li.w $r13, 0x0eafa7d0; mulh.w $r15, $r12, $r13; li.w $r16, 0xfde8e5ee; bne $r15, $r16, inst_error
    li.w $r12, 0x5aa5b57e; li.w $r13, 0xeb138c80; mulh.w $r15, $r12, $r13; li.w $r16, 0xf8975429; bne $r15, $r16, inst_error
    li.w $r12, 0xbc61fc9c; li.w $r13, 0x2c0b0f78; mulh.w $r15, $r12, $r13; li.w $r16, 0xf45deb8a; bne $r15, $r16, inst_error
    li.w $r12, 0x8b3566b7; li.w $r13, 0x2b021ecc; mulh.w $r15, $r12, $r13; li.w $r16, 0xec61009e; bne $r15, $r16, inst_error
    li.w $r12, 0x666e54e8; li.w $r13, 0xed91452c; mulh.w $r15, $r12, $r13; li.w $r16, 0xf89fefde; bne $r15, $r16, inst_error
    li.w $r12, 0xc6e59380; li.w $r13, 0xfa935180; mulh.w $r15, $r12, $r13; li.w $r16, 0x0135c230; bne $r15, $r16, inst_error
    li.w $r12, 0xd921e0b0; li.w $r13, 0x1f7d65c0; mulh.w $r15, $r12, $r13; li.w $r16, 0xfb38104d; bne $r15, $r16, inst_error
    li.w $r12, 0x7b8db2e2; li.w $r13, 0x84d37b50; mulh.w $r15, $r12, $r13; li.w $r16, 0xc48d6ea8; bne $r15, $r16, inst_error
    li.w $r12, 0xf89e1b58; li.w $r13, 0x26be32a0; mulh.w $r15, $r12, $r13; li.w $r16, 0xfee1fbf1; bne $r15, $r16, inst_error
    li.w $r12, 0x524aa0a6; li.w $r13, 0x0b334594; mulh.w $r15, $r12, $r13; li.w $r16, 0x0399b022; bne $r15, $r16, inst_error
    li.w $r12, 0xa3be10e8; li.w $r13, 0x18dbc860; mulh.w $r15, $r12, $r13; li.w $r16, 0xf70a9cf8; bne $r15, $r16, inst_error
    li.w $r12, 0x073cf5be; li.w $r13, 0x4fbf4882; mulh.w $r15, $r12, $r13; li.w $r16, 0x0241385d; bne $r15, $r16, inst_error
    li.w $r12, 0x91db7100; li.w $r13, 0x1f78ebb0; mulh.w $r15, $r12, $r13; li.w $r16, 0xf2758c24; bne $r15, $r16, inst_error
    li.w $r12, 0xc49e36d8; li.w $r13, 0x2044fa90; mulh.w $r15, $r12, $r13; li.w $r16, 0xf883c6c2; bne $r15, $r16, inst_error
    li.w $r12, 0xaf4ab2b8; li.w $r13, 0xf0086f40; mulh.w $r15, $r12, $r13; li.w $r16, 0x0508ac17; bne $r15, $r16, inst_error
    li.w $r12, 0xc72f0de2; li.w $r13, 0x407a26e0; mulh.w $r15, $r12, $r13; li.w $r16, 0xf1b0a744; bne $r15, $r16, inst_error
    li.w $r12, 0x95d26876; li.w $r13, 0x9aaece1c; mulh.w $r15, $r12, $r13; li.w $r16, 0x2a05a9e7; bne $r15, $r16, inst_error
    li.w $r12, 0x72e2ec10; li.w $r13, 0xb9098e00; mulh.w $r15, $r12, $r13; li.w $r16, 0xe0275a3b; bne $r15, $r16, inst_error
    li.w $r12, 0xdeb27a9c; li.w $r13, 0x506c0849; mulh.w $r15, $r12, $r13; li.w $r16, 0xf589b888; bne $r15, $r16, inst_error
    li.w $r12, 0x530194f0; li.w $r13, 0x00000000; mulh.w $r15, $r12, $r13; li.w $r16, 0x00000000; bne $r15, $r16, inst_error
    li.w $r12, 0x5a1a4f60; li.w $r13, 0x00000000; mulh.w $r15, $r12, $r13; li.w $r16, 0x00000000; bne $r15, $r16, inst_error
    li.w $r12, 0x5cc4e136; li.w $r13, 0x00000000; mulh.w $r15, $r12, $r13; li.w $r16, 0x00000000; bne $r15, $r16, inst_error
    li.w $r12, 0xab7a14c0; li.w $r13, 0x00000000; mulh.w $r15, $r12, $r13; li.w $r16, 0x00000000; bne $r15, $r16, inst_error
    li.w $r12, 0x44d126d0; li.w $r13, 0x00000000; mulh.w $r15, $r12, $r13; li.w $r16, 0x00000000; bne $r15, $r16, inst_error
    li.w $r12, 0x0f114ff0; li.w $r13, 0x00000000; mulh.w $r15, $r12, $r13; li.w $r16, 0x00000000; bne $r15, $r16, inst_error
    li.w $r12, 0x60bfe48e; li.w $r13, 0x00000000; mulh.w $r15, $r12, $r13; li.w $r16, 0x00000000; bne $r15, $r16, inst_error
    li.w $r12, 0x102ceba0; li.w $r13, 0x00000000; mulh.w $r15, $r12, $r13; li.w $r16, 0x00000000; bne $r15, $r16, inst_error
    li.w $r12, 0x7b21e54d; li.w $r13, 0x00000000; mulh.w $r15, $r12, $r13; li.w $r16, 0x00000000; bne $r15, $r16, inst_error
    li.w $r12, 0x5d72f954; li.w $r13, 0x00000000; mulh.w $r15, $r12, $r13; li.w $r16, 0x00000000; bne $r15, $r16, inst_error
    li.w $r12, 0x2699b2d4; li.w $r13, 0x00000000; mulh.w $r15, $r12, $r13; li.w $r16, 0x00000000; bne $r15, $r16, inst_error
    li.w $r12, 0x66b6dc30; li.w $r13, 0x00000000; mulh.w $r15, $r12, $r13; li.w $r16, 0x00000000; bne $r15, $r16, inst_error
    li.w $r12, 0x00000000; li.w $r13, 0x4ae569a0; mulh.w $r15, $r12, $r13; li.w $r16, 0x00000000; bne $r15, $r16, inst_error
    li.w $r12, 0x00000000; li.w $r13, 0x2582c9c0; mulh.w $r15, $r12, $r13; li.w $r16, 0x00000000; bne $r15, $r16, inst_error
    li.w $r12, 0x00000000; li.w $r13, 0xa2f01d2e; mulh.w $r15, $r12, $r13; li.w $r16, 0x00000000; bne $r15, $r16, inst_error
    li.w $r12, 0x00000000; li.w $r13, 0x2c5300d7; mulh.w $r15, $r12, $r13; li.w $r16, 0x00000000; bne $r15, $r16, inst_error
    li.w $r12, 0x00000000; li.w $r13, 0x7a95fab0; mulh.w $r15, $r12, $r13; li.w $r16, 0x00000000; bne $r15, $r16, inst_error
    li.w $r12, 0x00000000; li.w $r13, 0xf415d1b4; mulh.w $r15, $r12, $r13; li.w $r16, 0x00000000; bne $r15, $r16, inst_error
    li.w $r12, 0x00000000; li.w $r13, 0x0caf7d5c; mulh.w $r15, $r12, $r13; li.w $r16, 0x00000000; bne $r15, $r16, inst_error
    li.w $r12, 0x00000000; li.w $r13, 0xae15e524; mulh.w $r15, $r12, $r13; li.w $r16, 0x00000000; bne $r15, $r16, inst_error
    li.w $r12, 0x00000000; li.w $r13, 0x00000000; mulh.w $r15, $r12, $r13; li.w $r16, 0x00000000; bne $r15, $r16, inst_error
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
.cfi_endproc ; .size n33_mulh_w_test,.-n33_mulh_w_test;
