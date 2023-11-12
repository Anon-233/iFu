# 1 "n30_div_w.S"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "n30_div_w.S"
# 1 "../include/asm.h" 1



# 1 "../include/regdef.h" 1
# 5 "../include/asm.h" 2
# 1 "../include/sysdep.h" 1
# 6 "../include/asm.h" 2
# 2 "n30_div_w.S" 2
# 1 "../include/regdef.h" 1
# 3 "n30_div_w.S" 2
# 1 "../include/inst_test.h" 1

# 1 "../include/cpu_cde.h" 1
# 1 "../include/lab_config.h" 1
# 2 "../include/cpu_cde.h" 2
# 3 "../include/inst_test.h" 2
# 4 "n30_div_w.S" 2

.text; .globl n30_div_w_test; .align 3; .cfi_startproc ; .type n30_div_w_test, @function; n30_div_w_test:

    addi.w $r23, $r23 ,1
    li.w $r25, 0x0
###test inst
    li.w $r12, 0x56bedfa4; li.w $r13, 0x20831400; div.w $r15, $r12, $r13; li.w $r16, 0x00000002; bne $r16, $r15, inst_error
    li.w $r12, 0xfda5ea8a; li.w $r13, 0xfac1873c; div.w $r15, $r12, $r13; li.w $r16, 0x00000000; bne $r16, $r15, inst_error
    li.w $r12, 0x53eb4a70; li.w $r13, 0x07e13dd1; div.w $r15, $r12, $r13; li.w $r16, 0x0000000a; bne $r16, $r15, inst_error
    li.w $r12, 0x323676e0; li.w $r13, 0xdc3a3f10; div.w $r15, $r12, $r13; li.w $r16, 0xffffffff; bne $r16, $r15, inst_error
    li.w $r12, 0xc3e0f060; li.w $r13, 0xe9c97944; div.w $r15, $r12, $r13; li.w $r16, 0x00000002; bne $r16, $r15, inst_error
    li.w $r12, 0x7c7b85f2; li.w $r13, 0xdb7e6dc0; div.w $r15, $r12, $r13; li.w $r16, 0xfffffffd; bne $r16, $r15, inst_error
    li.w $r12, 0x3bbf1da0; li.w $r13, 0xe73f9eea; div.w $r15, $r12, $r13; li.w $r16, 0xfffffffe; bne $r16, $r15, inst_error
    li.w $r12, 0x8786a50c; li.w $r13, 0x412dc050; div.w $r15, $r12, $r13; li.w $r16, 0xffffffff; bne $r16, $r15, inst_error
    li.w $r12, 0xee98aaf8; li.w $r13, 0x36730f80; div.w $r15, $r12, $r13; li.w $r16, 0x00000000; bne $r16, $r15, inst_error
    li.w $r12, 0x68d65d90; li.w $r13, 0xd6d52b70; div.w $r15, $r12, $r13; li.w $r16, 0xfffffffe; bne $r16, $r15, inst_error
    li.w $r12, 0x17779850; li.w $r13, 0x511b1fba; div.w $r15, $r12, $r13; li.w $r16, 0x00000000; bne $r16, $r15, inst_error
    li.w $r12, 0x7bfc98c0; li.w $r13, 0xdffb8d8c; div.w $r15, $r12, $r13; li.w $r16, 0xfffffffd; bne $r16, $r15, inst_error
    li.w $r12, 0xa1090e30; li.w $r13, 0x9f634c20; div.w $r15, $r12, $r13; li.w $r16, 0x00000000; bne $r16, $r15, inst_error
    li.w $r12, 0x944789e0; li.w $r13, 0xbc1aeab0; div.w $r15, $r12, $r13; li.w $r16, 0x00000001; bne $r16, $r15, inst_error
    li.w $r12, 0x91913c20; li.w $r13, 0x0d7fa4a0; div.w $r15, $r12, $r13; li.w $r16, 0xfffffff8; bne $r16, $r15, inst_error
    li.w $r12, 0xa0792145; li.w $r13, 0xd9316a68; div.w $r15, $r12, $r13; li.w $r16, 0x00000002; bne $r16, $r15, inst_error
    li.w $r12, 0x0dac1e00; li.w $r13, 0x692a0470; div.w $r15, $r12, $r13; li.w $r16, 0x00000000; bne $r16, $r15, inst_error
    li.w $r12, 0x816e4490; li.w $r13, 0x16df3f00; div.w $r15, $r12, $r13; li.w $r16, 0xfffffffb; bne $r16, $r15, inst_error
    li.w $r12, 0x9471ab8a; li.w $r13, 0xc428d407; div.w $r15, $r12, $r13; li.w $r16, 0x00000001; bne $r16, $r15, inst_error
    li.w $r12, 0x18197510; li.w $r13, 0x859b3ae8; div.w $r15, $r12, $r13; li.w $r16, 0x00000000; bne $r16, $r15, inst_error
    li.w $r12, 0x28852031; li.w $r13, 0x7eab85d6; div.w $r15, $r12, $r13; li.w $r16, 0x00000000; bne $r16, $r15, inst_error
    li.w $r12, 0x21707800; li.w $r13, 0xea3c3580; div.w $r15, $r12, $r13; li.w $r16, 0xffffffff; bne $r16, $r15, inst_error
    li.w $r12, 0xf434d0f8; li.w $r13, 0xd2606068; div.w $r15, $r12, $r13; li.w $r16, 0x00000000; bne $r16, $r15, inst_error
    li.w $r12, 0x89fa9ce0; li.w $r13, 0x8b746d5c; div.w $r15, $r12, $r13; li.w $r16, 0x00000001; bne $r16, $r15, inst_error
    li.w $r12, 0x2fb0dcbc; li.w $r13, 0xb3896224; div.w $r15, $r12, $r13; li.w $r16, 0x00000000; bne $r16, $r15, inst_error
    li.w $r12, 0xc7b128a4; li.w $r13, 0x0600b15d; div.w $r15, $r12, $r13; li.w $r16, 0xfffffff7; bne $r16, $r15, inst_error
    li.w $r12, 0x57d6fe0a; li.w $r13, 0x2dbec2d0; div.w $r15, $r12, $r13; li.w $r16, 0x00000001; bne $r16, $r15, inst_error
    li.w $r12, 0xa78bba58; li.w $r13, 0x1d1ce488; div.w $r15, $r12, $r13; li.w $r16, 0xfffffffd; bne $r16, $r15, inst_error
    li.w $r12, 0x6dacf9c8; li.w $r13, 0x45e5c7a0; div.w $r15, $r12, $r13; li.w $r16, 0x00000001; bne $r16, $r15, inst_error
    li.w $r12, 0x62d0a060; li.w $r13, 0xb3708762; div.w $r15, $r12, $r13; li.w $r16, 0xffffffff; bne $r16, $r15, inst_error
    li.w $r12, 0x12763f9c; li.w $r13, 0xf896d530; div.w $r15, $r12, $r13; li.w $r16, 0xfffffffe; bne $r16, $r15, inst_error
    li.w $r12, 0x098ef6a0; li.w $r13, 0xcf035c50; div.w $r15, $r12, $r13; li.w $r16, 0x00000000; bne $r16, $r15, inst_error
    li.w $r12, 0x3a2491a3; li.w $r13, 0x1f054400; div.w $r15, $r12, $r13; li.w $r16, 0x00000001; bne $r16, $r15, inst_error
    li.w $r12, 0xdd12c65c; li.w $r13, 0x8874feb8; div.w $r15, $r12, $r13; li.w $r16, 0x00000000; bne $r16, $r15, inst_error
    li.w $r12, 0x6d394d48; li.w $r13, 0xfddfc888; div.w $r15, $r12, $r13; li.w $r16, 0xffffffcd; bne $r16, $r15, inst_error
    li.w $r12, 0x17c525ee; li.w $r13, 0xff6e16fc; div.w $r15, $r12, $r13; li.w $r16, 0xffffffd7; bne $r16, $r15, inst_error
    li.w $r12, 0xa752a72f; li.w $r13, 0xe35b51ba; div.w $r15, $r12, $r13; li.w $r16, 0x00000003; bne $r16, $r15, inst_error
    li.w $r12, 0xd92de300; li.w $r13, 0x15a8cfe5; div.w $r15, $r12, $r13; li.w $r16, 0xffffffff; bne $r16, $r15, inst_error
    li.w $r12, 0xe775a23d; li.w $r13, 0xa45ef71c; div.w $r15, $r12, $r13; li.w $r16, 0x00000000; bne $r16, $r15, inst_error
    li.w $r12, 0x31f98592; li.w $r13, 0xd61078b1; div.w $r15, $r12, $r13; li.w $r16, 0xffffffff; bne $r16, $r15, inst_error
    li.w $r12, 0x80553a33; li.w $r13, 0xeca4bbf1; div.w $r15, $r12, $r13; li.w $r16, 0x00000006; bne $r16, $r15, inst_error
    li.w $r12, 0x5e6dac0d; li.w $r13, 0x048e06c9; div.w $r15, $r12, $r13; li.w $r16, 0x00000014; bne $r16, $r15, inst_error
    li.w $r12, 0x85b28db3; li.w $r13, 0x78d48e18; div.w $r15, $r12, $r13; li.w $r16, 0xffffffff; bne $r16, $r15, inst_error
    li.w $r12, 0x59f96b98; li.w $r13, 0x0455de88; div.w $r15, $r12, $r13; li.w $r16, 0x00000014; bne $r16, $r15, inst_error
    li.w $r12, 0x6b36df10; li.w $r13, 0x7744092c; div.w $r15, $r12, $r13; li.w $r16, 0x00000000; bne $r16, $r15, inst_error
    li.w $r12, 0x1f9e644f; li.w $r13, 0xad18886c; div.w $r15, $r12, $r13; li.w $r16, 0x00000000; bne $r16, $r15, inst_error
    li.w $r12, 0x6d189a72; li.w $r13, 0x645d8aac; div.w $r15, $r12, $r13; li.w $r16, 0x00000001; bne $r16, $r15, inst_error
    li.w $r12, 0x0c1166a8; li.w $r13, 0x6526ce40; div.w $r15, $r12, $r13; li.w $r16, 0x00000000; bne $r16, $r15, inst_error
    li.w $r12, 0x5af79440; li.w $r13, 0xa7727e50; div.w $r15, $r12, $r13; li.w $r16, 0xffffffff; bne $r16, $r15, inst_error
    li.w $r12, 0xebbd6e70; li.w $r13, 0x0d2b4b5b; div.w $r15, $r12, $r13; li.w $r16, 0xffffffff; bne $r16, $r15, inst_error
    li.w $r12, 0xb2180178; li.w $r13, 0x9cb33ba8; div.w $r15, $r12, $r13; li.w $r16, 0x00000000; bne $r16, $r15, inst_error
    li.w $r12, 0x9d4133d8; li.w $r13, 0xb268ae15; div.w $r15, $r12, $r13; li.w $r16, 0x00000001; bne $r16, $r15, inst_error
    li.w $r12, 0xbd4528a6; li.w $r13, 0x4ebd7e00; div.w $r15, $r12, $r13; li.w $r16, 0x00000000; bne $r16, $r15, inst_error
    li.w $r12, 0xe4bd1250; li.w $r13, 0x488abc1c; div.w $r15, $r12, $r13; li.w $r16, 0x00000000; bne $r16, $r15, inst_error
    li.w $r12, 0xa2a77eae; li.w $r13, 0x299d2a20; div.w $r15, $r12, $r13; li.w $r16, 0xfffffffe; bne $r16, $r15, inst_error
    li.w $r12, 0x4b688500; li.w $r13, 0x16d5bb7c; div.w $r15, $r12, $r13; li.w $r16, 0x00000003; bne $r16, $r15, inst_error
    li.w $r12, 0xa1da497c; li.w $r13, 0xc7ed1a50; div.w $r15, $r12, $r13; li.w $r16, 0x00000001; bne $r16, $r15, inst_error
    li.w $r12, 0x62260fe8; li.w $r13, 0x5ba0b130; div.w $r15, $r12, $r13; li.w $r16, 0x00000001; bne $r16, $r15, inst_error
    li.w $r12, 0x9bb3f6d9; li.w $r13, 0x41e136a4; div.w $r15, $r12, $r13; li.w $r16, 0xffffffff; bne $r16, $r15, inst_error
    li.w $r12, 0xd5fcd1d6; li.w $r13, 0xc073ea20; div.w $r15, $r12, $r13; li.w $r16, 0x00000000; bne $r16, $r15, inst_error
    li.w $r12, 0xaaceef00; li.w $r13, 0xb934eec0; div.w $r15, $r12, $r13; li.w $r16, 0x00000001; bne $r16, $r15, inst_error
    li.w $r12, 0xf21b28a8; li.w $r13, 0x724b7460; div.w $r15, $r12, $r13; li.w $r16, 0x00000000; bne $r16, $r15, inst_error
    li.w $r12, 0x630e69e4; li.w $r13, 0x3d1cde06; div.w $r15, $r12, $r13; li.w $r16, 0x00000001; bne $r16, $r15, inst_error
    li.w $r12, 0xbe57f2e4; li.w $r13, 0x3e9c0ea0; div.w $r15, $r12, $r13; li.w $r16, 0xffffffff; bne $r16, $r15, inst_error
    li.w $r12, 0x4e2c28a6; li.w $r13, 0x72662240; div.w $r15, $r12, $r13; li.w $r16, 0x00000000; bne $r16, $r15, inst_error
    li.w $r12, 0x5f95c708; li.w $r13, 0xcf41487b; div.w $r15, $r12, $r13; li.w $r16, 0xffffffff; bne $r16, $r15, inst_error
    li.w $r12, 0x8dceffe3; li.w $r13, 0xdc6a3b80; div.w $r15, $r12, $r13; li.w $r16, 0x00000003; bne $r16, $r15, inst_error
    li.w $r12, 0xf5d4fec0; li.w $r13, 0xf2a8f09c; div.w $r15, $r12, $r13; li.w $r16, 0x00000000; bne $r16, $r15, inst_error
    li.w $r12, 0x881dab60; li.w $r13, 0x9a380358; div.w $r15, $r12, $r13; li.w $r16, 0x00000001; bne $r16, $r15, inst_error
    li.w $r12, 0xd07715a0; li.w $r13, 0x66e639b3; div.w $r15, $r12, $r13; li.w $r16, 0x00000000; bne $r16, $r15, inst_error
    li.w $r12, 0x782095ce; li.w $r13, 0x93be3000; div.w $r15, $r12, $r13; li.w $r16, 0xffffffff; bne $r16, $r15, inst_error
    li.w $r12, 0x89ec82ca; li.w $r13, 0xe20b2a70; div.w $r15, $r12, $r13; li.w $r16, 0x00000003; bne $r16, $r15, inst_error
    li.w $r12, 0xa193b0e0; li.w $r13, 0x20fa0b00; div.w $r15, $r12, $r13; li.w $r16, 0xfffffffe; bne $r16, $r15, inst_error
    li.w $r12, 0x3557ea04; li.w $r13, 0x75c478d0; div.w $r15, $r12, $r13; li.w $r16, 0x00000000; bne $r16, $r15, inst_error
    li.w $r12, 0xa832f328; li.w $r13, 0xee25c038; div.w $r15, $r12, $r13; li.w $r16, 0x00000004; bne $r16, $r15, inst_error
    li.w $r12, 0x52b5d68a; li.w $r13, 0x8899c4a8; div.w $r15, $r12, $r13; li.w $r16, 0x00000000; bne $r16, $r15, inst_error
    li.w $r12, 0x5eec8ab7; li.w $r13, 0x90af59cc; div.w $r15, $r12, $r13; li.w $r16, 0x00000000; bne $r16, $r15, inst_error
    li.w $r12, 0xd93d3180; li.w $r13, 0x72d03460; div.w $r15, $r12, $r13; li.w $r16, 0x00000000; bne $r16, $r15, inst_error
    li.w $r12, 0x77866a8e; li.w $r13, 0x32659e96; div.w $r15, $r12, $r13; li.w $r16, 0x00000002; bne $r16, $r15, inst_error
    li.w $r12, 0x5958f077; li.w $r13, 0xeb2bd5ec; div.w $r15, $r12, $r13; li.w $r16, 0xfffffffc; bne $r16, $r15, inst_error
    li.w $r12, 0x6efa1a58; li.w $r13, 0xb3f65f42; div.w $r15, $r12, $r13; li.w $r16, 0xffffffff; bne $r16, $r15, inst_error
    li.w $r12, 0xbe718690; li.w $r13, 0xe54a2a9e; div.w $r15, $r12, $r13; li.w $r16, 0x00000002; bne $r16, $r15, inst_error
    li.w $r12, 0xd5e2a4b0; li.w $r13, 0x9a860828; div.w $r15, $r12, $r13; li.w $r16, 0x00000000; bne $r16, $r15, inst_error
    li.w $r12, 0x52d16644; li.w $r13, 0x2d06d3ac; div.w $r15, $r12, $r13; li.w $r16, 0x00000001; bne $r16, $r15, inst_error
    li.w $r12, 0xea72e2b6; li.w $r13, 0xec307a80; div.w $r15, $r12, $r13; li.w $r16, 0x00000001; bne $r16, $r15, inst_error
    li.w $r12, 0xca150860; li.w $r13, 0x68ac4460; div.w $r15, $r12, $r13; li.w $r16, 0x00000000; bne $r16, $r15, inst_error
    li.w $r12, 0x99a81ef8; li.w $r13, 0x49569c66; div.w $r15, $r12, $r13; li.w $r16, 0xffffffff; bne $r16, $r15, inst_error
    li.w $r12, 0x3181e9f0; li.w $r13, 0x6f9b9c74; div.w $r15, $r12, $r13; li.w $r16, 0x00000000; bne $r16, $r15, inst_error
    li.w $r12, 0x15dd1e40; li.w $r13, 0x50a72ba0; div.w $r15, $r12, $r13; li.w $r16, 0x00000000; bne $r16, $r15, inst_error
    li.w $r12, 0xf61afe37; li.w $r13, 0xb6fcbca3; div.w $r15, $r12, $r13; li.w $r16, 0x00000000; bne $r16, $r15, inst_error
    li.w $r12, 0x682fedd2; li.w $r13, 0xb339543e; div.w $r15, $r12, $r13; li.w $r16, 0xffffffff; bne $r16, $r15, inst_error
    li.w $r12, 0xe58a4420; li.w $r13, 0xe3744db0; div.w $r15, $r12, $r13; li.w $r16, 0x00000000; bne $r16, $r15, inst_error
    li.w $r12, 0xb6b9f08a; li.w $r13, 0x199a6c48; div.w $r15, $r12, $r13; li.w $r16, 0xfffffffe; bne $r16, $r15, inst_error
    li.w $r12, 0xdebcb606; li.w $r13, 0xe8bbaeb0; div.w $r15, $r12, $r13; li.w $r16, 0x00000001; bne $r16, $r15, inst_error
    li.w $r12, 0x3a71821e; li.w $r13, 0x75017300; div.w $r15, $r12, $r13; li.w $r16, 0x00000000; bne $r16, $r15, inst_error
    li.w $r12, 0x16be834c; li.w $r13, 0xa7ea3340; div.w $r15, $r12, $r13; li.w $r16, 0x00000000; bne $r16, $r15, inst_error
    li.w $r12, 0x7130e360; li.w $r13, 0xb8ecacc0; div.w $r15, $r12, $r13; li.w $r16, 0xffffffff; bne $r16, $r15, inst_error
    li.w $r12, 0x48e68d72; li.w $r13, 0x61958b0f; div.w $r15, $r12, $r13; li.w $r16, 0x00000000; bne $r16, $r15, inst_error
    li.w $r12, 0xda594800; li.w $r13, 0x8045367d; div.w $r15, $r12, $r13; li.w $r16, 0x00000000; bne $r16, $r15, inst_error
    li.w $r12, 0xe8c2df9a; li.w $r13, 0xe6c66c34; div.w $r15, $r12, $r13; li.w $r16, 0x00000000; bne $r16, $r15, inst_error
    li.w $r12, 0x9e516c26; li.w $r13, 0xef3e3bd4; div.w $r15, $r12, $r13; li.w $r16, 0x00000005; bne $r16, $r15, inst_error
    li.w $r12, 0x7f9c4ad4; li.w $r13, 0x6c56d48c; div.w $r15, $r12, $r13; li.w $r16, 0x00000001; bne $r16, $r15, inst_error
    li.w $r12, 0x30322930; li.w $r13, 0x1b8d3720; div.w $r15, $r12, $r13; li.w $r16, 0x00000001; bne $r16, $r15, inst_error
    li.w $r12, 0xf7bed7b0; li.w $r13, 0xdb77e540; div.w $r15, $r12, $r13; li.w $r16, 0x00000000; bne $r16, $r15, inst_error
    li.w $r12, 0xa0c7d748; li.w $r13, 0x8de61300; div.w $r15, $r12, $r13; li.w $r16, 0x00000000; bne $r16, $r15, inst_error
    li.w $r12, 0xdeb2f704; li.w $r13, 0xfd2b0c11; div.w $r15, $r12, $r13; li.w $r16, 0x0000000b; bne $r16, $r15, inst_error
    li.w $r12, 0xc08e13d8; li.w $r13, 0x1f025330; div.w $r15, $r12, $r13; li.w $r16, 0xfffffffe; bne $r16, $r15, inst_error
    li.w $r12, 0x1c4fb5a4; li.w $r13, 0x9f16309a; div.w $r15, $r12, $r13; li.w $r16, 0x00000000; bne $r16, $r15, inst_error
    li.w $r12, 0xc79dd5a8; li.w $r13, 0x1708cffa; div.w $r15, $r12, $r13; li.w $r16, 0xfffffffe; bne $r16, $r15, inst_error
    li.w $r12, 0xee856ae8; li.w $r13, 0x80b4ba58; div.w $r15, $r12, $r13; li.w $r16, 0x00000000; bne $r16, $r15, inst_error
    li.w $r12, 0x8f9fc561; li.w $r13, 0xbd96c9d4; div.w $r15, $r12, $r13; li.w $r16, 0x00000001; bne $r16, $r15, inst_error
    li.w $r12, 0xb992d620; li.w $r13, 0xced24e3e; div.w $r15, $r12, $r13; li.w $r16, 0x00000001; bne $r16, $r15, inst_error
    li.w $r12, 0x4967f580; li.w $r13, 0xe1381905; div.w $r15, $r12, $r13; li.w $r16, 0xfffffffe; bne $r16, $r15, inst_error
    li.w $r12, 0x722d059f; li.w $r13, 0x705cea80; div.w $r15, $r12, $r13; li.w $r16, 0x00000001; bne $r16, $r15, inst_error
    li.w $r12, 0x15053974; li.w $r13, 0x8b5e5c00; div.w $r15, $r12, $r13; li.w $r16, 0x00000000; bne $r16, $r15, inst_error
    li.w $r12, 0x664c2a8c; li.w $r13, 0x50bf0b96; div.w $r15, $r12, $r13; li.w $r16, 0x00000001; bne $r16, $r15, inst_error
    li.w $r12, 0x92395380; li.w $r13, 0x15c2099e; div.w $r15, $r12, $r13; li.w $r16, 0xfffffffb; bne $r16, $r15, inst_error
    li.w $r12, 0xf24a2a85; li.w $r13, 0xca406d34; div.w $r15, $r12, $r13; li.w $r16, 0x00000000; bne $r16, $r15, inst_error
    li.w $r12, 0x9187ed80; li.w $r13, 0xb8ff4cc8; div.w $r15, $r12, $r13; li.w $r16, 0x00000001; bne $r16, $r15, inst_error
    li.w $r12, 0x00000000; li.w $r13, 0xa7bb1ef0; div.w $r15, $r12, $r13; li.w $r16, 0x00000000; bne $r16, $r15, inst_error
    li.w $r12, 0x00000000; li.w $r13, 0x3050efec; div.w $r15, $r12, $r13; li.w $r16, 0x00000000; bne $r16, $r15, inst_error
    li.w $r12, 0x00000000; li.w $r13, 0x94e29c00; div.w $r15, $r12, $r13; li.w $r16, 0x00000000; bne $r16, $r15, inst_error
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
.cfi_endproc ; .size n30_div_w_test,.-n30_div_w_test;
