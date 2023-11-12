# 1 "n32_mul_w.S"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "n32_mul_w.S"
# 1 "../include/asm.h" 1



# 1 "../include/regdef.h" 1
# 5 "../include/asm.h" 2
# 1 "../include/sysdep.h" 1
# 6 "../include/asm.h" 2
# 2 "n32_mul_w.S" 2
# 1 "../include/regdef.h" 1
# 3 "n32_mul_w.S" 2
# 1 "../include/inst_test.h" 1

# 1 "../include/cpu_cde.h" 1
# 1 "../include/lab_config.h" 1
# 2 "../include/cpu_cde.h" 2
# 3 "../include/inst_test.h" 2
# 4 "n32_mul_w.S" 2

.text; .globl n32_mul_w_test; .align 3; .cfi_startproc ; .type n32_mul_w_test, @function; n32_mul_w_test:

    addi.w $r23, $r23 ,1
    li.w $r25, 0x0
###test inst
    li.w $r12, 0x45b90738; li.w $r13, 0xd70d64f0; mul.w $r15, $r12, $r13; li.w $r16, 0x0a20a480; bne $r15, $r16, inst_error
    li.w $r12, 0x99a451b0; li.w $r13, 0xbe3d9998; mul.w $r15, $r12, $r13; li.w $r16, 0x8552b080; bne $r15, $r16, inst_error
    li.w $r12, 0x85931c58; li.w $r13, 0xfb710fb5; mul.w $r15, $r12, $r13; li.w $r16, 0xda843238; bne $r15, $r16, inst_error
    li.w $r12, 0x650e4043; li.w $r13, 0x64c17218; mul.w $r15, $r12, $r13; li.w $r16, 0x7076dc48; bne $r15, $r16, inst_error
    li.w $r12, 0xa00c6c50; li.w $r13, 0x8e9df080; mul.w $r15, $r12, $r13; li.w $r16, 0x78d12800; bne $r15, $r16, inst_error
    li.w $r12, 0x99c874b6; li.w $r13, 0xd7ce83e0; mul.w $r15, $r12, $r13; li.w $r16, 0xe7934140; bne $r15, $r16, inst_error
    li.w $r12, 0x1c62f360; li.w $r13, 0x34580400; mul.w $r15, $r12, $r13; li.w $r16, 0xb4cd8000; bne $r15, $r16, inst_error
    li.w $r12, 0x99b80b00; li.w $r13, 0x6c463000; mul.w $r15, $r12, $r13; li.w $r16, 0x84100000; bne $r15, $r16, inst_error
    li.w $r12, 0xdc823390; li.w $r13, 0x5208f838; mul.w $r15, $r12, $r13; li.w $r16, 0x1aeec780; bne $r15, $r16, inst_error
    li.w $r12, 0xe53080d8; li.w $r13, 0x848a9c5a; mul.w $r15, $r12, $r13; li.w $r16, 0xf600ebf0; bne $r15, $r16, inst_error
    li.w $r12, 0x7f2163d8; li.w $r13, 0xab5bba80; mul.w $r15, $r12, $r13; li.w $r16, 0x9904dc00; bne $r15, $r16, inst_error
    li.w $r12, 0xea7b88c0; li.w $r13, 0x23eed510; mul.w $r15, $r12, $r13; li.w $r16, 0xd3004c00; bne $r15, $r16, inst_error
    li.w $r12, 0x7389b4fd; li.w $r13, 0xea063940; mul.w $r15, $r12, $r13; li.w $r16, 0x0ba79440; bne $r15, $r16, inst_error
    li.w $r12, 0xbcdf9b20; li.w $r13, 0xc1451978; mul.w $r15, $r12, $r13; li.w $r16, 0x4e96d700; bne $r15, $r16, inst_error
    li.w $r12, 0xdcacfd50; li.w $r13, 0x809d0a80; mul.w $r15, $r12, $r13; li.w $r16, 0x7273c800; bne $r15, $r16, inst_error
    li.w $r12, 0x55ed3100; li.w $r13, 0xbe5ba9f2; mul.w $r15, $r12, $r13; li.w $r16, 0x3a915200; bne $r15, $r16, inst_error
    li.w $r12, 0xcedb5fd8; li.w $r13, 0xe1793b60; mul.w $r15, $r12, $r13; li.w $r16, 0x4672b900; bne $r15, $r16, inst_error
    li.w $r12, 0x9d32f1b0; li.w $r13, 0xbb2016b8; mul.w $r15, $r12, $r13; li.w $r16, 0x2362d680; bne $r15, $r16, inst_error
    li.w $r12, 0x7091ae43; li.w $r13, 0xdb390460; mul.w $r15, $r12, $r13; li.w $r16, 0x9b456520; bne $r15, $r16, inst_error
    li.w $r12, 0x549bf440; li.w $r13, 0xd1dc9f40; mul.w $r15, $r12, $r13; li.w $r16, 0x2ab0d000; bne $r15, $r16, inst_error
    li.w $r12, 0x63b241cc; li.w $r13, 0x48aefe14; mul.w $r15, $r12, $r13; li.w $r16, 0xbfdd8bf0; bne $r15, $r16, inst_error
    li.w $r12, 0x4c925040; li.w $r13, 0x0855d2c8; mul.w $r15, $r12, $r13; li.w $r16, 0x7d633200; bne $r15, $r16, inst_error
    li.w $r12, 0xdb2dfd2c; li.w $r13, 0x6c0e9f09; mul.w $r15, $r12, $r13; li.w $r16, 0xad443a8c; bne $r15, $r16, inst_error
    li.w $r12, 0xdfdc9250; li.w $r13, 0xbf1f15c3; mul.w $r15, $r12, $r13; li.w $r16, 0x04b402f0; bne $r15, $r16, inst_error
    li.w $r12, 0x1b339b35; li.w $r13, 0x98c14bc0; mul.w $r15, $r12, $r13; li.w $r16, 0x0021eec0; bne $r15, $r16, inst_error
    li.w $r12, 0xc8618b98; li.w $r13, 0x69452a40; mul.w $r15, $r12, $r13; li.w $r16, 0x1141d600; bne $r15, $r16, inst_error
    li.w $r12, 0x2aea0580; li.w $r13, 0x7f50d684; mul.w $r15, $r12, $r13; li.w $r16, 0xf943d600; bne $r15, $r16, inst_error
    li.w $r12, 0x5c69f5ec; li.w $r13, 0x9ee23bd2; mul.w $r15, $r12, $r13; li.w $r16, 0xfcf11f98; bne $r15, $r16, inst_error
    li.w $r12, 0xb7b66b40; li.w $r13, 0x8b50c179; mul.w $r15, $r12, $r13; li.w $r16, 0xa013f140; bne $r15, $r16, inst_error
    li.w $r12, 0x514e33b6; li.w $r13, 0x7dc39988; mul.w $r15, $r12, $r13; li.w $r16, 0x30153eb0; bne $r15, $r16, inst_error
    li.w $r12, 0x27c24e12; li.w $r13, 0xbc0e6874; mul.w $r15, $r12, $r13; li.w $r16, 0x70beb028; bne $r15, $r16, inst_error
    li.w $r12, 0xe7e6eddc; li.w $r13, 0x13a7cad0; mul.w $r15, $r12, $r13; li.w $r16, 0x21d4dac0; bne $r15, $r16, inst_error
    li.w $r12, 0xa85111c0; li.w $r13, 0xa29d50f0; mul.w $r15, $r12, $r13; li.w $r16, 0x844ca400; bne $r15, $r16, inst_error
    li.w $r12, 0x73d52eb8; li.w $r13, 0x142ba310; mul.w $r15, $r12, $r13; li.w $r16, 0x32fa1380; bne $r15, $r16, inst_error
    li.w $r12, 0x41156884; li.w $r13, 0x794c5fb2; mul.w $r15, $r12, $r13; li.w $r16, 0x9ddba7c8; bne $r15, $r16, inst_error
    li.w $r12, 0xa8774820; li.w $r13, 0xb2cf0480; mul.w $r15, $r12, $r13; li.w $r16, 0xaaa49000; bne $r15, $r16, inst_error
    li.w $r12, 0xb69bcb80; li.w $r13, 0x88d55520; mul.w $r15, $r12, $r13; li.w $r16, 0xdf8af000; bne $r15, $r16, inst_error
    li.w $r12, 0xe84175d8; li.w $r13, 0x94048f1c; mul.w $r15, $r12, $r13; li.w $r16, 0xaf5c8ba0; bne $r15, $r16, inst_error
    li.w $r12, 0x6fdedbd8; li.w $r13, 0x67dd7f60; mul.w $r15, $r12, $r13; li.w $r16, 0x341a9900; bne $r15, $r16, inst_error
    li.w $r12, 0xa2319526; li.w $r13, 0xd5f88700; mul.w $r15, $r12, $r13; li.w $r16, 0x40770a00; bne $r15, $r16, inst_error
    li.w $r12, 0x61f8b9bc; li.w $r13, 0x146e6d38; mul.w $r15, $r12, $r13; li.w $r16, 0xd445ad20; bne $r15, $r16, inst_error
    li.w $r12, 0xb9002828; li.w $r13, 0x0310a1b9; mul.w $r15, $r12, $r13; li.w $r16, 0xc4de2ce8; bne $r15, $r16, inst_error
    li.w $r12, 0xb4418f47; li.w $r13, 0x943f129c; mul.w $r15, $r12, $r13; li.w $r16, 0xc27f4d44; bne $r15, $r16, inst_error
    li.w $r12, 0xd7011f8c; li.w $r13, 0x70d8ea80; mul.w $r15, $r12, $r13; li.w $r16, 0x6585be00; bne $r15, $r16, inst_error
    li.w $r12, 0x058b9998; li.w $r13, 0x55395538; mul.w $r15, $r12, $r13; li.w $r16, 0x3b611140; bne $r15, $r16, inst_error
    li.w $r12, 0xc13b7fc0; li.w $r13, 0xda192fbb; mul.w $r15, $r12, $r13; li.w $r16, 0x0caa9140; bne $r15, $r16, inst_error
    li.w $r12, 0x776d24b0; li.w $r13, 0x66f0a9a4; mul.w $r15, $r12, $r13; li.w $r16, 0x1423b0c0; bne $r15, $r16, inst_error
    li.w $r12, 0x6c6ae338; li.w $r13, 0x5c4abc80; mul.w $r15, $r12, $r13; li.w $r16, 0x827ebc00; bne $r15, $r16, inst_error
    li.w $r12, 0x9dc090e0; li.w $r13, 0xb6324980; mul.w $r15, $r12, $r13; li.w $r16, 0x55585000; bne $r15, $r16, inst_error
    li.w $r12, 0x86d609de; li.w $r13, 0xcd4bcb2e; mul.w $r15, $r12, $r13; li.w $r16, 0x9e52cfe4; bne $r15, $r16, inst_error
    li.w $r12, 0x1400c7dc; li.w $r13, 0x466a6d5e; mul.w $r15, $r12, $r13; li.w $r16, 0x967a0ec8; bne $r15, $r16, inst_error
    li.w $r12, 0xa2d88860; li.w $r13, 0x26423686; mul.w $r15, $r12, $r13; li.w $r16, 0x52dba240; bne $r15, $r16, inst_error
    li.w $r12, 0x6770770a; li.w $r13, 0x812cbe10; mul.w $r15, $r12, $r13; li.w $r16, 0x6f18dca0; bne $r15, $r16, inst_error
    li.w $r12, 0x95627048; li.w $r13, 0xc1bae8ca; mul.w $r15, $r12, $r13; li.w $r16, 0xf1bdd8d0; bne $r15, $r16, inst_error
    li.w $r12, 0x1dbadda0; li.w $r13, 0x5d2b0f50; mul.w $r15, $r12, $r13; li.w $r16, 0x9741a200; bne $r15, $r16, inst_error
    li.w $r12, 0xc7cf4f96; li.w $r13, 0x7dd33820; mul.w $r15, $r12, $r13; li.w $r16, 0x29f4c2c0; bne $r15, $r16, inst_error
    li.w $r12, 0xa1d8f960; li.w $r13, 0xb83e3183; mul.w $r15, $r12, $r13; li.w $r16, 0xbf02fc20; bne $r15, $r16, inst_error
    li.w $r12, 0xcc2c955e; li.w $r13, 0x63c2877e; mul.w $r15, $r12, $r13; li.w $r16, 0x8bf21644; bne $r15, $r16, inst_error
    li.w $r12, 0xd2d44530; li.w $r13, 0x602b39e6; mul.w $r15, $r12, $r13; li.w $r16, 0x4d2dd920; bne $r15, $r16, inst_error
    li.w $r12, 0x886c3ad7; li.w $r13, 0xe011a4c0; mul.w $r15, $r12, $r13; li.w $r16, 0xaf24dd40; bne $r15, $r16, inst_error
    li.w $r12, 0x0c45d0c8; li.w $r13, 0x830e02fb; mul.w $r15, $r12, $r13; li.w $r16, 0x57054418; bne $r15, $r16, inst_error
    li.w $r12, 0x49979c44; li.w $r13, 0x298742f0; mul.w $r15, $r12, $r13; li.w $r16, 0x604807c0; bne $r15, $r16, inst_error
    li.w $r12, 0x2037c800; li.w $r13, 0xfb355f34; mul.w $r15, $r12, $r13; li.w $r16, 0xa68ca000; bne $r15, $r16, inst_error
    li.w $r12, 0x21e68aeb; li.w $r13, 0xc1cc4ec0; mul.w $r15, $r12, $r13; li.w $r16, 0x897fca40; bne $r15, $r16, inst_error
    li.w $r12, 0xe2c488b8; li.w $r13, 0x8ed6a9d8; mul.w $r15, $r12, $r13; li.w $r16, 0x6de4d340; bne $r15, $r16, inst_error
    li.w $r12, 0x0622c000; li.w $r13, 0x849e669e; mul.w $r15, $r12, $r13; li.w $r16, 0x21f28000; bne $r15, $r16, inst_error
    li.w $r12, 0xfe11325e; li.w $r13, 0x5a980480; mul.w $r15, $r12, $r13; li.w $r16, 0x4132a700; bne $r15, $r16, inst_error
    li.w $r12, 0xb582a660; li.w $r13, 0x27161c30; mul.w $r15, $r12, $r13; li.w $r16, 0x3ef1b200; bne $r15, $r16, inst_error
    li.w $r12, 0xde436ee0; li.w $r13, 0x0b8fd2ea; mul.w $r15, $r12, $r13; li.w $r16, 0x09b718c0; bne $r15, $r16, inst_error
    li.w $r12, 0x3ca5ebcc; li.w $r13, 0x7fca89b0; mul.w $r15, $r12, $r13; li.w $r16, 0xc03a4840; bne $r15, $r16, inst_error
    li.w $r12, 0xed8ac2a2; li.w $r13, 0x8e11d628; mul.w $r15, $r12, $r13; li.w $r16, 0xe523d550; bne $r15, $r16, inst_error
    li.w $r12, 0xee62ac9c; li.w $r13, 0x446aed90; mul.w $r15, $r12, $r13; li.w $r16, 0x59e583c0; bne $r15, $r16, inst_error
    li.w $r12, 0xa5a41fa0; li.w $r13, 0x901ecf7a; mul.w $r15, $r12, $r13; li.w $r16, 0x5a897240; bne $r15, $r16, inst_error
    li.w $r12, 0x1665a95c; li.w $r13, 0x01fa0f1c; mul.w $r15, $r12, $r13; li.w $r16, 0x27e2ea10; bne $r15, $r16, inst_error
    li.w $r12, 0xf760c288; li.w $r13, 0x024d9a70; mul.w $r15, $r12, $r13; li.w $r16, 0x0242eb80; bne $r15, $r16, inst_error
    li.w $r12, 0xb91b1700; li.w $r13, 0xff6a7770; mul.w $r15, $r12, $r13; li.w $r16, 0x198b1000; bne $r15, $r16, inst_error
    li.w $r12, 0x38a15d4c; li.w $r13, 0x4d378f48; mul.w $r15, $r12, $r13; li.w $r16, 0xf7d3b160; bne $r15, $r16, inst_error
    li.w $r12, 0xe1d0a988; li.w $r13, 0x29062820; mul.w $r15, $r12, $r13; li.w $r16, 0x95c27100; bne $r15, $r16, inst_error
    li.w $r12, 0xb657c3ec; li.w $r13, 0x42373c21; mul.w $r15, $r12, $r13; li.w $r16, 0x02ef916c; bne $r15, $r16, inst_error
    li.w $r12, 0x8cd72e00; li.w $r13, 0x0657e392; mul.w $r15, $r12, $r13; li.w $r16, 0xc2823c00; bne $r15, $r16, inst_error
    li.w $r12, 0xcffca4a4; li.w $r13, 0xf52aba30; mul.w $r15, $r12, $r13; li.w $r16, 0x85e606c0; bne $r15, $r16, inst_error
    li.w $r12, 0xd823b826; li.w $r13, 0xed601012; mul.w $r15, $r12, $r13; li.w $r16, 0xaa4552ac; bne $r15, $r16, inst_error
    li.w $r12, 0x306f7f24; li.w $r13, 0x6384a554; mul.w $r15, $r12, $r13; li.w $r16, 0x3c17ebd0; bne $r15, $r16, inst_error
    li.w $r12, 0x0c59e770; li.w $r13, 0x3e387808; mul.w $r15, $r12, $r13; li.w $r16, 0x47cbbb80; bne $r15, $r16, inst_error
    li.w $r12, 0xc1dd451c; li.w $r13, 0xe125f520; mul.w $r15, $r12, $r13; li.w $r16, 0x97d86f80; bne $r15, $r16, inst_error
    li.w $r12, 0xef4e68d4; li.w $r13, 0x9ff2ad9b; mul.w $r15, $r12, $r13; li.w $r16, 0xa5b8bc5c; bne $r15, $r16, inst_error
    li.w $r12, 0x7ef6ec24; li.w $r13, 0xb177da10; mul.w $r15, $r12, $r13; li.w $r16, 0xdd416a40; bne $r15, $r16, inst_error
    li.w $r12, 0x6fb25f72; li.w $r13, 0x791ebb10; mul.w $r15, $r12, $r13; li.w $r16, 0x583a3d20; bne $r15, $r16, inst_error
    li.w $r12, 0x58101600; li.w $r13, 0xd3840640; mul.w $r15, $r12, $r13; li.w $r16, 0xbc898000; bne $r15, $r16, inst_error
    li.w $r12, 0x07affc60; li.w $r13, 0x5ea8d5b0; mul.w $r15, $r12, $r13; li.w $r16, 0x94f96200; bne $r15, $r16, inst_error
    li.w $r12, 0xf952c740; li.w $r13, 0x73978b1c; mul.w $r15, $r12, $r13; li.w $r16, 0x7dfd8b00; bne $r15, $r16, inst_error
    li.w $r12, 0x8f689828; li.w $r13, 0x91565574; mul.w $r15, $r12, $r13; li.w $r16, 0x7b5a3a20; bne $r15, $r16, inst_error
    li.w $r12, 0x914d8000; li.w $r13, 0xba3b44b8; mul.w $r15, $r12, $r13; li.w $r16, 0x85b40000; bne $r15, $r16, inst_error
    li.w $r12, 0x4d2e3cf5; li.w $r13, 0x70e9d5e8; mul.w $r15, $r12, $r13; li.w $r16, 0x159c1708; bne $r15, $r16, inst_error
    li.w $r12, 0xb037ad58; li.w $r13, 0x11952040; mul.w $r15, $r12, $r13; li.w $r16, 0xbfce5600; bne $r15, $r16, inst_error
    li.w $r12, 0xa4246038; li.w $r13, 0x111ad568; mul.w $r15, $r12, $r13; li.w $r16, 0x7085aec0; bne $r15, $r16, inst_error
    li.w $r12, 0xef964a3a; li.w $r13, 0xd18d5d08; mul.w $r15, $r12, $r13; li.w $r16, 0x519b63d0; bne $r15, $r16, inst_error
    li.w $r12, 0xa4a7728e; li.w $r13, 0x97843fdc; mul.w $r15, $r12, $r13; li.w $r16, 0x884f6408; bne $r15, $r16, inst_error
    li.w $r12, 0xdf30b100; li.w $r13, 0x250933f8; mul.w $r15, $r12, $r13; li.w $r16, 0x236e7800; bne $r15, $r16, inst_error
    li.w $r12, 0x1d5818a4; li.w $r13, 0xe5093304; mul.w $r15, $r12, $r13; li.w $r16, 0x940d0e90; bne $r15, $r16, inst_error
    li.w $r12, 0x15122298; li.w $r13, 0xcbbb9870; mul.w $r15, $r12, $r13; li.w $r16, 0xc9816280; bne $r15, $r16, inst_error
    li.w $r12, 0x88ca117e; li.w $r13, 0x0e125f90; mul.w $r15, $r12, $r13; li.w $r16, 0x0d0398e0; bne $r15, $r16, inst_error
    li.w $r12, 0xdf4ef397; li.w $r13, 0xda63b6b6; mul.w $r15, $r12, $r13; li.w $r16, 0xacb3875a; bne $r15, $r16, inst_error
    li.w $r12, 0x6683ae60; li.w $r13, 0x63fc1988; mul.w $r15, $r12, $r13; li.w $r16, 0x187c0300; bne $r15, $r16, inst_error
    li.w $r12, 0xe6a56cae; li.w $r13, 0xd0003efb; mul.w $r15, $r12, $r13; li.w $r16, 0x9483b29a; bne $r15, $r16, inst_error
    li.w $r12, 0x7d58aade; li.w $r13, 0x5b2167ac; mul.w $r15, $r12, $r13; li.w $r16, 0xd4f01f28; bne $r15, $r16, inst_error
    li.w $r12, 0x61118bd0; li.w $r13, 0x9e016e14; mul.w $r15, $r12, $r13; li.w $r16, 0x0b424c40; bne $r15, $r16, inst_error
    li.w $r12, 0x7fdd22be; li.w $r13, 0xfdcc9fee; mul.w $r15, $r12, $r13; li.w $r16, 0xad924ea4; bne $r15, $r16, inst_error
    li.w $r12, 0x70e273a0; li.w $r13, 0xd87fc19c; mul.w $r15, $r12, $r13; li.w $r16, 0xdf8a1580; bne $r15, $r16, inst_error
    li.w $r12, 0x3940dad6; li.w $r13, 0xa37c292b; mul.w $r15, $r12, $r13; li.w $r16, 0x429907f2; bne $r15, $r16, inst_error
    li.w $r12, 0xba7ab435; li.w $r13, 0x2322d7d0; mul.w $r15, $r12, $r13; li.w $r16, 0xbf14ee10; bne $r15, $r16, inst_error
    li.w $r12, 0x0b238760; li.w $r13, 0x2bff2a02; mul.w $r15, $r12, $r13; li.w $r16, 0xe31ccec0; bne $r15, $r16, inst_error
    li.w $r12, 0xaa6a9390; li.w $r13, 0x8d3ab108; mul.w $r15, $r12, $r13; li.w $r16, 0xc1fb2c80; bne $r15, $r16, inst_error
    li.w $r12, 0xe3667224; li.w $r13, 0xbf514d80; mul.w $r15, $r12, $r13; li.w $r16, 0x7cf1e600; bne $r15, $r16, inst_error
    li.w $r12, 0x53b1b42e; li.w $r13, 0x7c608578; mul.w $r15, $r12, $r13; li.w $r16, 0x67285b90; bne $r15, $r16, inst_error
    li.w $r12, 0x8241ddf4; li.w $r13, 0x4a8d0e90; mul.w $r15, $r12, $r13; li.w $r16, 0xa6943140; bne $r15, $r16, inst_error
    li.w $r12, 0x7cdcd5cf; li.w $r13, 0xe584065f; mul.w $r15, $r12, $r13; li.w $r16, 0xecb231d1; bne $r15, $r16, inst_error
    li.w $r12, 0x50445224; li.w $r13, 0xb34e8c5c; mul.w $r15, $r12, $r13; li.w $r16, 0x687134f0; bne $r15, $r16, inst_error
    li.w $r12, 0x436d75a7; li.w $r13, 0x2cb9b728; mul.w $r15, $r12, $r13; li.w $r16, 0x81e3c318; bne $r15, $r16, inst_error
    li.w $r12, 0xdb906f30; li.w $r13, 0x0eafa7d0; mul.w $r15, $r12, $r13; li.w $r16, 0x3fb2a700; bne $r15, $r16, inst_error
    li.w $r12, 0x5aa5b57e; li.w $r13, 0xeb138c80; mul.w $r15, $r12, $r13; li.w $r16, 0x1475a700; bne $r15, $r16, inst_error
    li.w $r12, 0xbc61fc9c; li.w $r13, 0x2c0b0f78; mul.w $r15, $r12, $r13; li.w $r16, 0xb66f8d20; bne $r15, $r16, inst_error
    li.w $r12, 0x8b3566b7; li.w $r13, 0x2b021ecc; mul.w $r15, $r12, $r13; li.w $r16, 0xbb054bd4; bne $r15, $r16, inst_error
    li.w $r12, 0x666e54e8; li.w $r13, 0xed91452c; mul.w $r15, $r12, $r13; li.w $r16, 0x37411fe0; bne $r15, $r16, inst_error
    li.w $r12, 0xc6e59380; li.w $r13, 0xfa935180; mul.w $r15, $r12, $r13; li.w $r16, 0xc8f54000; bne $r15, $r16, inst_error
    li.w $r12, 0xd921e0b0; li.w $r13, 0x1f7d65c0; mul.w $r15, $r12, $r13; li.w $r16, 0x3cfdf400; bne $r15, $r16, inst_error
    li.w $r12, 0x7b8db2e2; li.w $r13, 0x84d37b50; mul.w $r15, $r12, $r13; li.w $r16, 0xa9807ca0; bne $r15, $r16, inst_error
    li.w $r12, 0xf89e1b58; li.w $r13, 0x26be32a0; mul.w $r15, $r12, $r13; li.w $r16, 0x9f784700; bne $r15, $r16, inst_error
    li.w $r12, 0x524aa0a6; li.w $r13, 0x0b334594; mul.w $r15, $r12, $r13; li.w $r16, 0xd3839df8; bne $r15, $r16, inst_error
    li.w $r12, 0xa3be10e8; li.w $r13, 0x18dbc860; mul.w $r15, $r12, $r13; li.w $r16, 0x1af39700; bne $r15, $r16, inst_error
    li.w $r12, 0x073cf5be; li.w $r13, 0x4fbf4882; mul.w $r15, $r12, $r13; li.w $r16, 0xccd43a7c; bne $r15, $r16, inst_error
    li.w $r12, 0x91db7100; li.w $r13, 0x1f78ebb0; mul.w $r15, $r12, $r13; li.w $r16, 0xaf98b000; bne $r15, $r16, inst_error
    li.w $r12, 0xc49e36d8; li.w $r13, 0x2044fa90; mul.w $r15, $r12, $r13; li.w $r16, 0xabedc980; bne $r15, $r16, inst_error
    li.w $r12, 0xaf4ab2b8; li.w $r13, 0xf0086f40; mul.w $r15, $r12, $r13; li.w $r16, 0x4bea7600; bne $r15, $r16, inst_error
    li.w $r12, 0xc72f0de2; li.w $r13, 0x407a26e0; mul.w $r15, $r12, $r13; li.w $r16, 0x62efb1c0; bne $r15, $r16, inst_error
    li.w $r12, 0x95d26876; li.w $r13, 0x9aaece1c; mul.w $r15, $r12, $r13; li.w $r16, 0xaf4660e8; bne $r15, $r16, inst_error
    li.w $r12, 0x72e2ec10; li.w $r13, 0xb9098e00; mul.w $r15, $r12, $r13; li.w $r16, 0xbb80e000; bne $r15, $r16, inst_error
    li.w $r12, 0xdeb27a9c; li.w $r13, 0x506c0849; mul.w $r15, $r12, $r13; li.w $r16, 0x8e89d67c; bne $r15, $r16, inst_error
    li.w $r12, 0x530194f0; li.w $r13, 0x00000000; mul.w $r15, $r12, $r13; li.w $r16, 0x00000000; bne $r15, $r16, inst_error
    li.w $r12, 0x5a1a4f60; li.w $r13, 0x00000000; mul.w $r15, $r12, $r13; li.w $r16, 0x00000000; bne $r15, $r16, inst_error
    li.w $r12, 0x5cc4e136; li.w $r13, 0x00000000; mul.w $r15, $r12, $r13; li.w $r16, 0x00000000; bne $r15, $r16, inst_error
    li.w $r12, 0xab7a14c0; li.w $r13, 0x00000000; mul.w $r15, $r12, $r13; li.w $r16, 0x00000000; bne $r15, $r16, inst_error
    li.w $r12, 0x44d126d0; li.w $r13, 0x00000000; mul.w $r15, $r12, $r13; li.w $r16, 0x00000000; bne $r15, $r16, inst_error
    li.w $r12, 0x0f114ff0; li.w $r13, 0x00000000; mul.w $r15, $r12, $r13; li.w $r16, 0x00000000; bne $r15, $r16, inst_error
    li.w $r12, 0x60bfe48e; li.w $r13, 0x00000000; mul.w $r15, $r12, $r13; li.w $r16, 0x00000000; bne $r15, $r16, inst_error
    li.w $r12, 0x102ceba0; li.w $r13, 0x00000000; mul.w $r15, $r12, $r13; li.w $r16, 0x00000000; bne $r15, $r16, inst_error
    li.w $r12, 0x7b21e54d; li.w $r13, 0x00000000; mul.w $r15, $r12, $r13; li.w $r16, 0x00000000; bne $r15, $r16, inst_error
    li.w $r12, 0x5d72f954; li.w $r13, 0x00000000; mul.w $r15, $r12, $r13; li.w $r16, 0x00000000; bne $r15, $r16, inst_error
    li.w $r12, 0x2699b2d4; li.w $r13, 0x00000000; mul.w $r15, $r12, $r13; li.w $r16, 0x00000000; bne $r15, $r16, inst_error
    li.w $r12, 0x66b6dc30; li.w $r13, 0x00000000; mul.w $r15, $r12, $r13; li.w $r16, 0x00000000; bne $r15, $r16, inst_error
    li.w $r12, 0x00000000; li.w $r13, 0x4ae569a0; mul.w $r15, $r12, $r13; li.w $r16, 0x00000000; bne $r15, $r16, inst_error
    li.w $r12, 0x00000000; li.w $r13, 0x2582c9c0; mul.w $r15, $r12, $r13; li.w $r16, 0x00000000; bne $r15, $r16, inst_error
    li.w $r12, 0x00000000; li.w $r13, 0xa2f01d2e; mul.w $r15, $r12, $r13; li.w $r16, 0x00000000; bne $r15, $r16, inst_error
    li.w $r12, 0x00000000; li.w $r13, 0x2c5300d7; mul.w $r15, $r12, $r13; li.w $r16, 0x00000000; bne $r15, $r16, inst_error
    li.w $r12, 0x00000000; li.w $r13, 0x7a95fab0; mul.w $r15, $r12, $r13; li.w $r16, 0x00000000; bne $r15, $r16, inst_error
    li.w $r12, 0x00000000; li.w $r13, 0xf415d1b4; mul.w $r15, $r12, $r13; li.w $r16, 0x00000000; bne $r15, $r16, inst_error
    li.w $r12, 0x00000000; li.w $r13, 0x0caf7d5c; mul.w $r15, $r12, $r13; li.w $r16, 0x00000000; bne $r15, $r16, inst_error
    li.w $r12, 0x00000000; li.w $r13, 0xae15e524; mul.w $r15, $r12, $r13; li.w $r16, 0x00000000; bne $r15, $r16, inst_error
    li.w $r12, 0x00000000; li.w $r13, 0x00000000; mul.w $r15, $r12, $r13; li.w $r16, 0x00000000; bne $r15, $r16, inst_error
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
.cfi_endproc ; .size n32_mul_w_test,.-n32_mul_w_test;
