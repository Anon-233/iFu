# 1 "n31_div_wu.S"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "n31_div_wu.S"
# 1 "../include/asm.h" 1



# 1 "../include/regdef.h" 1
# 5 "../include/asm.h" 2
# 1 "../include/sysdep.h" 1
# 6 "../include/asm.h" 2
# 2 "n31_div_wu.S" 2
# 1 "../include/regdef.h" 1
# 3 "n31_div_wu.S" 2
# 1 "../include/inst_test.h" 1

# 1 "../include/cpu_cde.h" 1
# 1 "../include/lab_config.h" 1
# 2 "../include/cpu_cde.h" 2
# 3 "../include/inst_test.h" 2
# 4 "n31_div_wu.S" 2

.text; .globl n31_div_wu_test; .align 3; .cfi_startproc ; .type n31_div_wu_test, @function; n31_div_wu_test:

    addi.w $r23, $r23 ,1
    li.w $r25, 0x0
###test inst
    li.w $r12, 0x4e775a80; li.w $r13, 0xb26795ec; div.wu $r15, $r12, $r13; li.w $r16, 0x00000000; bne $r16, $r15, inst_error
    li.w $r12, 0x4e888700; li.w $r13, 0xf0d84fce; div.wu $r15, $r12, $r13; li.w $r16, 0x00000000; bne $r16, $r15, inst_error
    li.w $r12, 0x01dea048; li.w $r13, 0xf2c74100; div.wu $r15, $r12, $r13; li.w $r16, 0x00000000; bne $r16, $r15, inst_error
    li.w $r12, 0x77e68950; li.w $r13, 0x8b0ddad0; div.wu $r15, $r12, $r13; li.w $r16, 0x00000000; bne $r16, $r15, inst_error
    li.w $r12, 0x72013c68; li.w $r13, 0x48cb8680; div.wu $r15, $r12, $r13; li.w $r16, 0x00000001; bne $r16, $r15, inst_error
    li.w $r12, 0x7fb2e9a0; li.w $r13, 0xc9af5700; div.wu $r15, $r12, $r13; li.w $r16, 0x00000000; bne $r16, $r15, inst_error
    li.w $r12, 0xd7042938; li.w $r13, 0x018a7078; div.wu $r15, $r12, $r13; li.w $r16, 0x0000008b; bne $r16, $r15, inst_error
    li.w $r12, 0xbf81441b; li.w $r13, 0x704e3f24; div.wu $r15, $r12, $r13; li.w $r16, 0x00000001; bne $r16, $r15, inst_error
    li.w $r12, 0xeb5994e6; li.w $r13, 0x622f1558; div.wu $r15, $r12, $r13; li.w $r16, 0x00000002; bne $r16, $r15, inst_error
    li.w $r12, 0x11176c40; li.w $r13, 0x8128af78; div.wu $r15, $r12, $r13; li.w $r16, 0x00000000; bne $r16, $r15, inst_error
    li.w $r12, 0x32893870; li.w $r13, 0xab09b9c0; div.wu $r15, $r12, $r13; li.w $r16, 0x00000000; bne $r16, $r15, inst_error
    li.w $r12, 0x403c60c0; li.w $r13, 0x6fe79f00; div.wu $r15, $r12, $r13; li.w $r16, 0x00000000; bne $r16, $r15, inst_error
    li.w $r12, 0xaf855e42; li.w $r13, 0x314b3730; div.wu $r15, $r12, $r13; li.w $r16, 0x00000003; bne $r16, $r15, inst_error
    li.w $r12, 0xdaa8cd0c; li.w $r13, 0xd8f7eb07; div.wu $r15, $r12, $r13; li.w $r16, 0x00000001; bne $r16, $r15, inst_error
    li.w $r12, 0x26aa8c2c; li.w $r13, 0x2db52200; div.wu $r15, $r12, $r13; li.w $r16, 0x00000000; bne $r16, $r15, inst_error
    li.w $r12, 0x933824b0; li.w $r13, 0x97422b30; div.wu $r15, $r12, $r13; li.w $r16, 0x00000000; bne $r16, $r15, inst_error
    li.w $r12, 0x0d527980; li.w $r13, 0x19233f98; div.wu $r15, $r12, $r13; li.w $r16, 0x00000000; bne $r16, $r15, inst_error
    li.w $r12, 0xfcb1d1f0; li.w $r13, 0x2cc89437; div.wu $r15, $r12, $r13; li.w $r16, 0x00000005; bne $r16, $r15, inst_error
    li.w $r12, 0xd711e228; li.w $r13, 0xdc4d82f5; div.wu $r15, $r12, $r13; li.w $r16, 0x00000000; bne $r16, $r15, inst_error
    li.w $r12, 0xe3e9c400; li.w $r13, 0x5e37e5e0; div.wu $r15, $r12, $r13; li.w $r16, 0x00000002; bne $r16, $r15, inst_error
    li.w $r12, 0xec9a8080; li.w $r13, 0x21240ee0; div.wu $r15, $r12, $r13; li.w $r16, 0x00000007; bne $r16, $r15, inst_error
    li.w $r12, 0xb0e35480; li.w $r13, 0x8947ed80; div.wu $r15, $r12, $r13; li.w $r16, 0x00000001; bne $r16, $r15, inst_error
    li.w $r12, 0x0392b91c; li.w $r13, 0x985ef388; div.wu $r15, $r12, $r13; li.w $r16, 0x00000000; bne $r16, $r15, inst_error
    li.w $r12, 0x39856e38; li.w $r13, 0xb0c0860c; div.wu $r15, $r12, $r13; li.w $r16, 0x00000000; bne $r16, $r15, inst_error
    li.w $r12, 0x9a86f9a7; li.w $r13, 0x62ff4728; div.wu $r15, $r12, $r13; li.w $r16, 0x00000001; bne $r16, $r15, inst_error
    li.w $r12, 0x0ce5e850; li.w $r13, 0x47adbcf0; div.wu $r15, $r12, $r13; li.w $r16, 0x00000000; bne $r16, $r15, inst_error
    li.w $r12, 0xf4611640; li.w $r13, 0x5d25556e; div.wu $r15, $r12, $r13; li.w $r16, 0x00000002; bne $r16, $r15, inst_error
    li.w $r12, 0xb7f4a7f2; li.w $r13, 0x2dbcce30; div.wu $r15, $r12, $r13; li.w $r16, 0x00000004; bne $r16, $r15, inst_error
    li.w $r12, 0xd5e74ce0; li.w $r13, 0x7cc662f7; div.wu $r15, $r12, $r13; li.w $r16, 0x00000001; bne $r16, $r15, inst_error
    li.w $r12, 0x9988ceac; li.w $r13, 0xf076e887; div.wu $r15, $r12, $r13; li.w $r16, 0x00000000; bne $r16, $r15, inst_error
    li.w $r12, 0x850dcbd5; li.w $r13, 0x59d75300; div.wu $r15, $r12, $r13; li.w $r16, 0x00000001; bne $r16, $r15, inst_error
    li.w $r12, 0x16d37c76; li.w $r13, 0x674dc83e; div.wu $r15, $r12, $r13; li.w $r16, 0x00000000; bne $r16, $r15, inst_error
    li.w $r12, 0xa9589416; li.w $r13, 0xa35bff94; div.wu $r15, $r12, $r13; li.w $r16, 0x00000001; bne $r16, $r15, inst_error
    li.w $r12, 0xa1909a9f; li.w $r13, 0xa0601410; div.wu $r15, $r12, $r13; li.w $r16, 0x00000001; bne $r16, $r15, inst_error
    li.w $r12, 0x21e6ad92; li.w $r13, 0x38937558; div.wu $r15, $r12, $r13; li.w $r16, 0x00000000; bne $r16, $r15, inst_error
    li.w $r12, 0x34097bd4; li.w $r13, 0x24334f00; div.wu $r15, $r12, $r13; li.w $r16, 0x00000001; bne $r16, $r15, inst_error
    li.w $r12, 0x00d69f51; li.w $r13, 0x638398c6; div.wu $r15, $r12, $r13; li.w $r16, 0x00000000; bne $r16, $r15, inst_error
    li.w $r12, 0xce523680; li.w $r13, 0x3aa421ac; div.wu $r15, $r12, $r13; li.w $r16, 0x00000003; bne $r16, $r15, inst_error
    li.w $r12, 0x06be2bd0; li.w $r13, 0x7e0469c0; div.wu $r15, $r12, $r13; li.w $r16, 0x00000000; bne $r16, $r15, inst_error
    li.w $r12, 0x3c8a3ed0; li.w $r13, 0x96ba84a4; div.wu $r15, $r12, $r13; li.w $r16, 0x00000000; bne $r16, $r15, inst_error
    li.w $r12, 0xcdb7e7a0; li.w $r13, 0xf02ec50b; div.wu $r15, $r12, $r13; li.w $r16, 0x00000000; bne $r16, $r15, inst_error
    li.w $r12, 0x3e73f907; li.w $r13, 0x343cb0fc; div.wu $r15, $r12, $r13; li.w $r16, 0x00000001; bne $r16, $r15, inst_error
    li.w $r12, 0x80c64528; li.w $r13, 0x514002d0; div.wu $r15, $r12, $r13; li.w $r16, 0x00000001; bne $r16, $r15, inst_error
    li.w $r12, 0x307ff23f; li.w $r13, 0x49cb4594; div.wu $r15, $r12, $r13; li.w $r16, 0x00000000; bne $r16, $r15, inst_error
    li.w $r12, 0x1a5c1b18; li.w $r13, 0x354f3820; div.wu $r15, $r12, $r13; li.w $r16, 0x00000000; bne $r16, $r15, inst_error
    li.w $r12, 0x152adedb; li.w $r13, 0x92367480; div.wu $r15, $r12, $r13; li.w $r16, 0x00000000; bne $r16, $r15, inst_error
    li.w $r12, 0x87c6b4d4; li.w $r13, 0x5fe2d74f; div.wu $r15, $r12, $r13; li.w $r16, 0x00000001; bne $r16, $r15, inst_error
    li.w $r12, 0x0a979968; li.w $r13, 0x95636cf8; div.wu $r15, $r12, $r13; li.w $r16, 0x00000000; bne $r16, $r15, inst_error
    li.w $r12, 0x9a022056; li.w $r13, 0xba1fcd4e; div.wu $r15, $r12, $r13; li.w $r16, 0x00000000; bne $r16, $r15, inst_error
    li.w $r12, 0x89ed9f82; li.w $r13, 0x6ede448c; div.wu $r15, $r12, $r13; li.w $r16, 0x00000001; bne $r16, $r15, inst_error
    li.w $r12, 0xe27700a0; li.w $r13, 0x96ae437e; div.wu $r15, $r12, $r13; li.w $r16, 0x00000001; bne $r16, $r15, inst_error
    li.w $r12, 0xfa35607c; li.w $r13, 0x0c845564; div.wu $r15, $r12, $r13; li.w $r16, 0x00000013; bne $r16, $r15, inst_error
    li.w $r12, 0xfd23f6f0; li.w $r13, 0x679ba312; div.wu $r15, $r12, $r13; li.w $r16, 0x00000002; bne $r16, $r15, inst_error
    li.w $r12, 0x80ede740; li.w $r13, 0x91669d00; div.wu $r15, $r12, $r13; li.w $r16, 0x00000000; bne $r16, $r15, inst_error
    li.w $r12, 0x8163addd; li.w $r13, 0x9c11473c; div.wu $r15, $r12, $r13; li.w $r16, 0x00000000; bne $r16, $r15, inst_error
    li.w $r12, 0xa8ff5154; li.w $r13, 0xb2f04618; div.wu $r15, $r12, $r13; li.w $r16, 0x00000000; bne $r16, $r15, inst_error
    li.w $r12, 0x7f5938cd; li.w $r13, 0x0b297e38; div.wu $r15, $r12, $r13; li.w $r16, 0x0000000b; bne $r16, $r15, inst_error
    li.w $r12, 0xc024b7e4; li.w $r13, 0x8cd258b8; div.wu $r15, $r12, $r13; li.w $r16, 0x00000001; bne $r16, $r15, inst_error
    li.w $r12, 0xe4c9469c; li.w $r13, 0x06d92da8; div.wu $r15, $r12, $r13; li.w $r16, 0x00000021; bne $r16, $r15, inst_error
    li.w $r12, 0x945fdc7a; li.w $r13, 0x2f800526; div.wu $r15, $r12, $r13; li.w $r16, 0x00000003; bne $r16, $r15, inst_error
    li.w $r12, 0xcfc7186c; li.w $r13, 0x0dec23ce; div.wu $r15, $r12, $r13; li.w $r16, 0x0000000e; bne $r16, $r15, inst_error
    li.w $r12, 0x1c80a1b0; li.w $r13, 0xc1ca066e; div.wu $r15, $r12, $r13; li.w $r16, 0x00000000; bne $r16, $r15, inst_error
    li.w $r12, 0x8c14bff0; li.w $r13, 0xdbebf5fc; div.wu $r15, $r12, $r13; li.w $r16, 0x00000000; bne $r16, $r15, inst_error
    li.w $r12, 0xfbefef80; li.w $r13, 0x101746e1; div.wu $r15, $r12, $r13; li.w $r16, 0x0000000f; bne $r16, $r15, inst_error
    li.w $r12, 0xfd96711e; li.w $r13, 0xaf0fc990; div.wu $r15, $r12, $r13; li.w $r16, 0x00000001; bne $r16, $r15, inst_error
    li.w $r12, 0x7fb0d7f1; li.w $r13, 0x137ff578; div.wu $r15, $r12, $r13; li.w $r16, 0x00000006; bne $r16, $r15, inst_error
    li.w $r12, 0x6123f8e8; li.w $r13, 0x698d919c; div.wu $r15, $r12, $r13; li.w $r16, 0x00000000; bne $r16, $r15, inst_error
    li.w $r12, 0x1bc6d70c; li.w $r13, 0x175203f8; div.wu $r15, $r12, $r13; li.w $r16, 0x00000001; bne $r16, $r15, inst_error
    li.w $r12, 0x49a78e40; li.w $r13, 0xb48180ca; div.wu $r15, $r12, $r13; li.w $r16, 0x00000000; bne $r16, $r15, inst_error
    li.w $r12, 0x02f09920; li.w $r13, 0x25c6fee0; div.wu $r15, $r12, $r13; li.w $r16, 0x00000000; bne $r16, $r15, inst_error
    li.w $r12, 0x0a15a7d4; li.w $r13, 0x36fc8496; div.wu $r15, $r12, $r13; li.w $r16, 0x00000000; bne $r16, $r15, inst_error
    li.w $r12, 0xfbd91080; li.w $r13, 0xc13d2d2a; div.wu $r15, $r12, $r13; li.w $r16, 0x00000001; bne $r16, $r15, inst_error
    li.w $r12, 0xd0a0b000; li.w $r13, 0x70dedc87; div.wu $r15, $r12, $r13; li.w $r16, 0x00000001; bne $r16, $r15, inst_error
    li.w $r12, 0x29a5da10; li.w $r13, 0xb87e9c40; div.wu $r15, $r12, $r13; li.w $r16, 0x00000000; bne $r16, $r15, inst_error
    li.w $r12, 0x60670d88; li.w $r13, 0x2b231300; div.wu $r15, $r12, $r13; li.w $r16, 0x00000002; bne $r16, $r15, inst_error
    li.w $r12, 0x9e5828c2; li.w $r13, 0x4040cf00; div.wu $r15, $r12, $r13; li.w $r16, 0x00000002; bne $r16, $r15, inst_error
    li.w $r12, 0x61a97c80; li.w $r13, 0x0a2468b8; div.wu $r15, $r12, $r13; li.w $r16, 0x00000009; bne $r16, $r15, inst_error
    li.w $r12, 0x94e8395f; li.w $r13, 0xe5bd280c; div.wu $r15, $r12, $r13; li.w $r16, 0x00000000; bne $r16, $r15, inst_error
    li.w $r12, 0x2aba4e7a; li.w $r13, 0x482d7bc0; div.wu $r15, $r12, $r13; li.w $r16, 0x00000000; bne $r16, $r15, inst_error
    li.w $r12, 0x0f578130; li.w $r13, 0x6a1d0b70; div.wu $r15, $r12, $r13; li.w $r16, 0x00000000; bne $r16, $r15, inst_error
    li.w $r12, 0x9e8536f4; li.w $r13, 0x7a2feeb0; div.wu $r15, $r12, $r13; li.w $r16, 0x00000001; bne $r16, $r15, inst_error
    li.w $r12, 0x6b7dc118; li.w $r13, 0x034fb77a; div.wu $r15, $r12, $r13; li.w $r16, 0x00000020; bne $r16, $r15, inst_error
    li.w $r12, 0xc8b2bb64; li.w $r13, 0x1e1293c0; div.wu $r15, $r12, $r13; li.w $r16, 0x00000006; bne $r16, $r15, inst_error
    li.w $r12, 0x5a45b336; li.w $r13, 0xd4fdd710; div.wu $r15, $r12, $r13; li.w $r16, 0x00000000; bne $r16, $r15, inst_error
    li.w $r12, 0x6a654c20; li.w $r13, 0x8148b638; div.wu $r15, $r12, $r13; li.w $r16, 0x00000000; bne $r16, $r15, inst_error
    li.w $r12, 0xe7940e6c; li.w $r13, 0x7526c3ea; div.wu $r15, $r12, $r13; li.w $r16, 0x00000001; bne $r16, $r15, inst_error
    li.w $r12, 0x18be7274; li.w $r13, 0xe2792f48; div.wu $r15, $r12, $r13; li.w $r16, 0x00000000; bne $r16, $r15, inst_error
    li.w $r12, 0xe434cf56; li.w $r13, 0x7ce3a860; div.wu $r15, $r12, $r13; li.w $r16, 0x00000001; bne $r16, $r15, inst_error
    li.w $r12, 0xfa77a0a8; li.w $r13, 0xb9d39f88; div.wu $r15, $r12, $r13; li.w $r16, 0x00000001; bne $r16, $r15, inst_error
    li.w $r12, 0x50335bbb; li.w $r13, 0x950aa144; div.wu $r15, $r12, $r13; li.w $r16, 0x00000000; bne $r16, $r15, inst_error
    li.w $r12, 0x63c427d6; li.w $r13, 0xe8d25300; div.wu $r15, $r12, $r13; li.w $r16, 0x00000000; bne $r16, $r15, inst_error
    li.w $r12, 0x16c3484f; li.w $r13, 0xdb114140; div.wu $r15, $r12, $r13; li.w $r16, 0x00000000; bne $r16, $r15, inst_error
    li.w $r12, 0x120a7000; li.w $r13, 0xabcddb30; div.wu $r15, $r12, $r13; li.w $r16, 0x00000000; bne $r16, $r15, inst_error
    li.w $r12, 0x1f58c45c; li.w $r13, 0xad2e3d9f; div.wu $r15, $r12, $r13; li.w $r16, 0x00000000; bne $r16, $r15, inst_error
    li.w $r12, 0x24dbaf34; li.w $r13, 0x9aebdeca; div.wu $r15, $r12, $r13; li.w $r16, 0x00000000; bne $r16, $r15, inst_error
    li.w $r12, 0xa8b75800; li.w $r13, 0x7de01766; div.wu $r15, $r12, $r13; li.w $r16, 0x00000001; bne $r16, $r15, inst_error
    li.w $r12, 0xbdba6308; li.w $r13, 0xc7fa2550; div.wu $r15, $r12, $r13; li.w $r16, 0x00000000; bne $r16, $r15, inst_error
    li.w $r12, 0x99a3fd70; li.w $r13, 0x67bd7960; div.wu $r15, $r12, $r13; li.w $r16, 0x00000001; bne $r16, $r15, inst_error
    li.w $r12, 0x6a9dcfc0; li.w $r13, 0x43d097e7; div.wu $r15, $r12, $r13; li.w $r16, 0x00000001; bne $r16, $r15, inst_error
    li.w $r12, 0xc89ce2a6; li.w $r13, 0xffeb1c50; div.wu $r15, $r12, $r13; li.w $r16, 0x00000000; bne $r16, $r15, inst_error
    li.w $r12, 0xf9087cc8; li.w $r13, 0x12400558; div.wu $r15, $r12, $r13; li.w $r16, 0x0000000d; bne $r16, $r15, inst_error
    li.w $r12, 0x71d79ea0; li.w $r13, 0xf9c35ddc; div.wu $r15, $r12, $r13; li.w $r16, 0x00000000; bne $r16, $r15, inst_error
    li.w $r12, 0xa18e9d80; li.w $r13, 0x4e037d7c; div.wu $r15, $r12, $r13; li.w $r16, 0x00000002; bne $r16, $r15, inst_error
    li.w $r12, 0x9fd0aeb1; li.w $r13, 0xf59bf246; div.wu $r15, $r12, $r13; li.w $r16, 0x00000000; bne $r16, $r15, inst_error
    li.w $r12, 0xd8320444; li.w $r13, 0x716e5200; div.wu $r15, $r12, $r13; li.w $r16, 0x00000001; bne $r16, $r15, inst_error
    li.w $r12, 0xe484070c; li.w $r13, 0x73d45434; div.wu $r15, $r12, $r13; li.w $r16, 0x00000001; bne $r16, $r15, inst_error
    li.w $r12, 0xf4d63b98; li.w $r13, 0xb57fc508; div.wu $r15, $r12, $r13; li.w $r16, 0x00000001; bne $r16, $r15, inst_error
    li.w $r12, 0xe2f55044; li.w $r13, 0xf53819b4; div.wu $r15, $r12, $r13; li.w $r16, 0x00000000; bne $r16, $r15, inst_error
    li.w $r12, 0x2a241bb0; li.w $r13, 0x318e3806; div.wu $r15, $r12, $r13; li.w $r16, 0x00000000; bne $r16, $r15, inst_error
    li.w $r12, 0xf66b2609; li.w $r13, 0x49346ff4; div.wu $r15, $r12, $r13; li.w $r16, 0x00000003; bne $r16, $r15, inst_error
    li.w $r12, 0x06927823; li.w $r13, 0xcc065fbd; div.wu $r15, $r12, $r13; li.w $r16, 0x00000000; bne $r16, $r15, inst_error
    li.w $r12, 0x5aa7865c; li.w $r13, 0x37037ada; div.wu $r15, $r12, $r13; li.w $r16, 0x00000001; bne $r16, $r15, inst_error
    li.w $r12, 0x9770dac0; li.w $r13, 0xe8669633; div.wu $r15, $r12, $r13; li.w $r16, 0x00000000; bne $r16, $r15, inst_error
    li.w $r12, 0xa96b6404; li.w $r13, 0x36e6cb60; div.wu $r15, $r12, $r13; li.w $r16, 0x00000003; bne $r16, $r15, inst_error
    li.w $r12, 0xfc71887e; li.w $r13, 0x998680d0; div.wu $r15, $r12, $r13; li.w $r16, 0x00000001; bne $r16, $r15, inst_error
    li.w $r12, 0x1966d6a4; li.w $r13, 0x647c7020; div.wu $r15, $r12, $r13; li.w $r16, 0x00000000; bne $r16, $r15, inst_error
    li.w $r12, 0xa8e220c4; li.w $r13, 0xeb56ad48; div.wu $r15, $r12, $r13; li.w $r16, 0x00000000; bne $r16, $r15, inst_error
    li.w $r12, 0x5950b640; li.w $r13, 0x38742cd3; div.wu $r15, $r12, $r13; li.w $r16, 0x00000001; bne $r16, $r15, inst_error
    li.w $r12, 0xa11a3e87; li.w $r13, 0x5af351a0; div.wu $r15, $r12, $r13; li.w $r16, 0x00000001; bne $r16, $r15, inst_error
    li.w $r12, 0x63d2bd00; li.w $r13, 0x42d0a200; div.wu $r15, $r12, $r13; li.w $r16, 0x00000001; bne $r16, $r15, inst_error
    li.w $r12, 0x8fe90d8e; li.w $r13, 0xb366c608; div.wu $r15, $r12, $r13; li.w $r16, 0x00000000; bne $r16, $r15, inst_error
    li.w $r12, 0x0908a490; li.w $r13, 0x59918c08; div.wu $r15, $r12, $r13; li.w $r16, 0x00000000; bne $r16, $r15, inst_error
    li.w $r12, 0xd30c8a6c; li.w $r13, 0x2ae73552; div.wu $r15, $r12, $r13; li.w $r16, 0x00000004; bne $r16, $r15, inst_error
    li.w $r12, 0x61e924f8; li.w $r13, 0x61bec600; div.wu $r15, $r12, $r13; li.w $r16, 0x00000001; bne $r16, $r15, inst_error
    li.w $r12, 0xf45f6ed8; li.w $r13, 0x131bfc78; div.wu $r15, $r12, $r13; li.w $r16, 0x0000000c; bne $r16, $r15, inst_error
    li.w $r12, 0x1fbf1006; li.w $r13, 0x64e404e0; div.wu $r15, $r12, $r13; li.w $r16, 0x00000000; bne $r16, $r15, inst_error
    li.w $r12, 0x70e216ac; li.w $r13, 0xa748d3f9; div.wu $r15, $r12, $r13; li.w $r16, 0x00000000; bne $r16, $r15, inst_error
    li.w $r12, 0x9ca20f65; li.w $r13, 0xb354a050; div.wu $r15, $r12, $r13; li.w $r16, 0x00000000; bne $r16, $r15, inst_error
    li.w $r12, 0x3aa65400; li.w $r13, 0x472877d0; div.wu $r15, $r12, $r13; li.w $r16, 0x00000000; bne $r16, $r15, inst_error
    li.w $r12, 0xaa245e30; li.w $r13, 0x3f5a2ef4; div.wu $r15, $r12, $r13; li.w $r16, 0x00000002; bne $r16, $r15, inst_error
    li.w $r12, 0x76e27de0; li.w $r13, 0xbef0a908; div.wu $r15, $r12, $r13; li.w $r16, 0x00000000; bne $r16, $r15, inst_error
    li.w $r12, 0x8bd8dae8; li.w $r13, 0x95a7b198; div.wu $r15, $r12, $r13; li.w $r16, 0x00000000; bne $r16, $r15, inst_error
    li.w $r12, 0x771fef95; li.w $r13, 0x40f86998; div.wu $r15, $r12, $r13; li.w $r16, 0x00000001; bne $r16, $r15, inst_error
    li.w $r12, 0x4b881a60; li.w $r13, 0x45aa8b18; div.wu $r15, $r12, $r13; li.w $r16, 0x00000001; bne $r16, $r15, inst_error
    li.w $r12, 0x30bdc4e9; li.w $r13, 0x81168740; div.wu $r15, $r12, $r13; li.w $r16, 0x00000000; bne $r16, $r15, inst_error
    li.w $r12, 0x770c5798; li.w $r13, 0x3f28fa66; div.wu $r15, $r12, $r13; li.w $r16, 0x00000001; bne $r16, $r15, inst_error
    li.w $r12, 0xdeb9ee04; li.w $r13, 0x3126ea9c; div.wu $r15, $r12, $r13; li.w $r16, 0x00000004; bne $r16, $r15, inst_error
    li.w $r12, 0x48ae81f0; li.w $r13, 0x5e0c351c; div.wu $r15, $r12, $r13; li.w $r16, 0x00000000; bne $r16, $r15, inst_error
    li.w $r12, 0x8c73948c; li.w $r13, 0xe6c8142a; div.wu $r15, $r12, $r13; li.w $r16, 0x00000000; bne $r16, $r15, inst_error
    li.w $r12, 0x2d02be90; li.w $r13, 0x3d69ba94; div.wu $r15, $r12, $r13; li.w $r16, 0x00000000; bne $r16, $r15, inst_error
    li.w $r12, 0x622d0eec; li.w $r13, 0x7b68c7db; div.wu $r15, $r12, $r13; li.w $r16, 0x00000000; bne $r16, $r15, inst_error
    li.w $r12, 0x23aeabc0; li.w $r13, 0xa6757640; div.wu $r15, $r12, $r13; li.w $r16, 0x00000000; bne $r16, $r15, inst_error
    li.w $r12, 0xa42405dc; li.w $r13, 0x81ae85b0; div.wu $r15, $r12, $r13; li.w $r16, 0x00000001; bne $r16, $r15, inst_error
    li.w $r12, 0x5ffb5218; li.w $r13, 0xe6ff1010; div.wu $r15, $r12, $r13; li.w $r16, 0x00000000; bne $r16, $r15, inst_error
    li.w $r12, 0x7d92100f; li.w $r13, 0x54b4ea50; div.wu $r15, $r12, $r13; li.w $r16, 0x00000001; bne $r16, $r15, inst_error
    li.w $r12, 0x890efcf8; li.w $r13, 0x44890dbe; div.wu $r15, $r12, $r13; li.w $r16, 0x00000001; bne $r16, $r15, inst_error
    li.w $r12, 0xa40ce6b4; li.w $r13, 0xb0285cf8; div.wu $r15, $r12, $r13; li.w $r16, 0x00000000; bne $r16, $r15, inst_error
    li.w $r12, 0x2c2a9fc2; li.w $r13, 0x2c677764; div.wu $r15, $r12, $r13; li.w $r16, 0x00000000; bne $r16, $r15, inst_error
    li.w $r12, 0x22387270; li.w $r13, 0x1ffac566; div.wu $r15, $r12, $r13; li.w $r16, 0x00000001; bne $r16, $r15, inst_error
    li.w $r12, 0xa41f02e0; li.w $r13, 0xba831348; div.wu $r15, $r12, $r13; li.w $r16, 0x00000000; bne $r16, $r15, inst_error
    li.w $r12, 0x74d4d90c; li.w $r13, 0xf943bdf7; div.wu $r15, $r12, $r13; li.w $r16, 0x00000000; bne $r16, $r15, inst_error
    li.w $r12, 0x7f8f69a8; li.w $r13, 0x101d39a2; div.wu $r15, $r12, $r13; li.w $r16, 0x00000007; bne $r16, $r15, inst_error
    li.w $r12, 0xf36ea730; li.w $r13, 0x18ad84b0; div.wu $r15, $r12, $r13; li.w $r16, 0x00000009; bne $r16, $r15, inst_error
    li.w $r12, 0xb95efa94; li.w $r13, 0x0f34d9c6; div.wu $r15, $r12, $r13; li.w $r16, 0x0000000c; bne $r16, $r15, inst_error
    li.w $r12, 0x36a2aa20; li.w $r13, 0xad414f06; div.wu $r15, $r12, $r13; li.w $r16, 0x00000000; bne $r16, $r15, inst_error
    li.w $r12, 0xfad69b46; li.w $r13, 0xd35319d4; div.wu $r15, $r12, $r13; li.w $r16, 0x00000001; bne $r16, $r15, inst_error
    li.w $r12, 0x3a7dca48; li.w $r13, 0xd0269d48; div.wu $r15, $r12, $r13; li.w $r16, 0x00000000; bne $r16, $r15, inst_error
    li.w $r12, 0xc01fc0f0; li.w $r13, 0x5f2bdce0; div.wu $r15, $r12, $r13; li.w $r16, 0x00000002; bne $r16, $r15, inst_error
    li.w $r12, 0x136c2456; li.w $r13, 0xd2f7a520; div.wu $r15, $r12, $r13; li.w $r16, 0x00000000; bne $r16, $r15, inst_error
    li.w $r12, 0xea6462b8; li.w $r13, 0x27475ad2; div.wu $r15, $r12, $r13; li.w $r16, 0x00000005; bne $r16, $r15, inst_error
    li.w $r12, 0x45f1cbe2; li.w $r13, 0x187f9910; div.wu $r15, $r12, $r13; li.w $r16, 0x00000002; bne $r16, $r15, inst_error
    li.w $r12, 0xc33b85ca; li.w $r13, 0x126449e8; div.wu $r15, $r12, $r13; li.w $r16, 0x0000000a; bne $r16, $r15, inst_error
    li.w $r12, 0x20273480; li.w $r13, 0xf35db380; div.wu $r15, $r12, $r13; li.w $r16, 0x00000000; bne $r16, $r15, inst_error
    li.w $r12, 0xafa66e60; li.w $r13, 0xeb2ac674; div.wu $r15, $r12, $r13; li.w $r16, 0x00000000; bne $r16, $r15, inst_error
    li.w $r12, 0xad868694; li.w $r13, 0xd7866c44; div.wu $r15, $r12, $r13; li.w $r16, 0x00000000; bne $r16, $r15, inst_error
    li.w $r12, 0x702f1d39; li.w $r13, 0xcba2eeb0; div.wu $r15, $r12, $r13; li.w $r16, 0x00000000; bne $r16, $r15, inst_error
    li.w $r12, 0x83f86060; li.w $r13, 0x29370ff3; div.wu $r15, $r12, $r13; li.w $r16, 0x00000003; bne $r16, $r15, inst_error
    li.w $r12, 0xaf7adfb0; li.w $r13, 0xb1424b48; div.wu $r15, $r12, $r13; li.w $r16, 0x00000000; bne $r16, $r15, inst_error
    li.w $r12, 0x9adb0050; li.w $r13, 0xa09fcd00; div.wu $r15, $r12, $r13; li.w $r16, 0x00000000; bne $r16, $r15, inst_error
    li.w $r12, 0xf2f16e2e; li.w $r13, 0x7573d2f8; div.wu $r15, $r12, $r13; li.w $r16, 0x00000002; bne $r16, $r15, inst_error
    li.w $r12, 0x99951902; li.w $r13, 0x8a360740; div.wu $r15, $r12, $r13; li.w $r16, 0x00000001; bne $r16, $r15, inst_error
    li.w $r12, 0x00000000; li.w $r13, 0xbea685ab; div.wu $r15, $r12, $r13; li.w $r16, 0x00000000; bne $r16, $r15, inst_error
    li.w $r12, 0x00000000; li.w $r13, 0x207ed850; div.wu $r15, $r12, $r13; li.w $r16, 0x00000000; bne $r16, $r15, inst_error
    li.w $r12, 0x00000000; li.w $r13, 0x72c14afa; div.wu $r15, $r12, $r13; li.w $r16, 0x00000000; bne $r16, $r15, inst_error
    li.w $r12, 0x00000000; li.w $r13, 0xae5365c0; div.wu $r15, $r12, $r13; li.w $r16, 0x00000000; bne $r16, $r15, inst_error
    li.w $r12, 0x00000000; li.w $r13, 0x9670f9f0; div.wu $r15, $r12, $r13; li.w $r16, 0x00000000; bne $r16, $r15, inst_error
    li.w $r12, 0x00000000; li.w $r13, 0x8e85bf30; div.wu $r15, $r12, $r13; li.w $r16, 0x00000000; bne $r16, $r15, inst_error
    li.w $r12, 0x00000000; li.w $r13, 0x11f1eca7; div.wu $r15, $r12, $r13; li.w $r16, 0x00000000; bne $r16, $r15, inst_error
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
.cfi_endproc ; .size n31_div_wu_test,.-n31_div_wu_test;
