# 1 "n35_mod_w.S"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "n35_mod_w.S"
# 1 "../include/asm.h" 1



# 1 "../include/regdef.h" 1
# 5 "../include/asm.h" 2
# 1 "../include/sysdep.h" 1
# 6 "../include/asm.h" 2
# 2 "n35_mod_w.S" 2
# 1 "../include/regdef.h" 1
# 3 "n35_mod_w.S" 2
# 1 "../include/inst_test.h" 1

# 1 "../include/cpu_cde.h" 1
# 1 "../include/lab_config.h" 1
# 2 "../include/cpu_cde.h" 2
# 3 "../include/inst_test.h" 2
# 4 "n35_mod_w.S" 2

.text; .globl n35_mod_w_test; .align 3; .cfi_startproc ; .type n35_mod_w_test, @function; n35_mod_w_test:

    addi.w $r23, $r23 ,1
    li.w $r25, 0x0
###test inst
    li.w $r12, 0x56bedfa4; li.w $r13, 0x20831400; mod.w $r15, $r12, $r13; li.w $r16, 0x15b8b7a4; bne $r16, $r15, inst_error
    li.w $r12, 0xfda5ea8a; li.w $r13, 0xfac1873c; mod.w $r15, $r12, $r13; li.w $r16, 0xfda5ea8a; bne $r16, $r15, inst_error
    li.w $r12, 0x53eb4a70; li.w $r13, 0x07e13dd1; mod.w $r15, $r12, $r13; li.w $r16, 0x051ee046; bne $r16, $r15, inst_error
    li.w $r12, 0x323676e0; li.w $r13, 0xdc3a3f10; mod.w $r15, $r12, $r13; li.w $r16, 0x0e70b5f0; bne $r16, $r15, inst_error
    li.w $r12, 0xc3e0f060; li.w $r13, 0xe9c97944; mod.w $r15, $r12, $r13; li.w $r16, 0xf04dfdd8; bne $r16, $r15, inst_error
    li.w $r12, 0x7c7b85f2; li.w $r13, 0xdb7e6dc0; mod.w $r15, $r12, $r13; li.w $r16, 0x0ef6cf32; bne $r16, $r15, inst_error
    li.w $r12, 0x3bbf1da0; li.w $r13, 0xe73f9eea; mod.w $r15, $r12, $r13; li.w $r16, 0x0a3e5b74; bne $r16, $r15, inst_error
    li.w $r12, 0x8786a50c; li.w $r13, 0x412dc050; mod.w $r15, $r12, $r13; li.w $r16, 0xc8b4655c; bne $r16, $r15, inst_error
    li.w $r12, 0xee98aaf8; li.w $r13, 0x36730f80; mod.w $r15, $r12, $r13; li.w $r16, 0xee98aaf8; bne $r16, $r15, inst_error
    li.w $r12, 0x68d65d90; li.w $r13, 0xd6d52b70; mod.w $r15, $r12, $r13; li.w $r16, 0x1680b470; bne $r16, $r15, inst_error
    li.w $r12, 0x17779850; li.w $r13, 0x511b1fba; mod.w $r15, $r12, $r13; li.w $r16, 0x17779850; bne $r16, $r15, inst_error
    li.w $r12, 0x7bfc98c0; li.w $r13, 0xdffb8d8c; mod.w $r15, $r12, $r13; li.w $r16, 0x1bef4164; bne $r16, $r15, inst_error
    li.w $r12, 0xa1090e30; li.w $r13, 0x9f634c20; mod.w $r15, $r12, $r13; li.w $r16, 0xa1090e30; bne $r16, $r15, inst_error
    li.w $r12, 0x944789e0; li.w $r13, 0xbc1aeab0; mod.w $r15, $r12, $r13; li.w $r16, 0xd82c9f30; bne $r16, $r15, inst_error
    li.w $r12, 0x91913c20; li.w $r13, 0x0d7fa4a0; mod.w $r15, $r12, $r13; li.w $r16, 0xfd8e6120; bne $r16, $r15, inst_error
    li.w $r12, 0xa0792145; li.w $r13, 0xd9316a68; mod.w $r15, $r12, $r13; li.w $r16, 0xee164c75; bne $r16, $r15, inst_error
    li.w $r12, 0x0dac1e00; li.w $r13, 0x692a0470; mod.w $r15, $r12, $r13; li.w $r16, 0x0dac1e00; bne $r16, $r15, inst_error
    li.w $r12, 0x816e4490; li.w $r13, 0x16df3f00; mod.w $r15, $r12, $r13; li.w $r16, 0xf3ca7f90; bne $r16, $r15, inst_error
    li.w $r12, 0x9471ab8a; li.w $r13, 0xc428d407; mod.w $r15, $r12, $r13; li.w $r16, 0xd048d783; bne $r16, $r15, inst_error
    li.w $r12, 0x18197510; li.w $r13, 0x859b3ae8; mod.w $r15, $r12, $r13; li.w $r16, 0x18197510; bne $r16, $r15, inst_error
    li.w $r12, 0x28852031; li.w $r13, 0x7eab85d6; mod.w $r15, $r12, $r13; li.w $r16, 0x28852031; bne $r16, $r15, inst_error
    li.w $r12, 0x21707800; li.w $r13, 0xea3c3580; mod.w $r15, $r12, $r13; li.w $r16, 0x0bacad80; bne $r16, $r15, inst_error
    li.w $r12, 0xf434d0f8; li.w $r13, 0xd2606068; mod.w $r15, $r12, $r13; li.w $r16, 0xf434d0f8; bne $r16, $r15, inst_error
    li.w $r12, 0x89fa9ce0; li.w $r13, 0x8b746d5c; mod.w $r15, $r12, $r13; li.w $r16, 0xfe862f84; bne $r16, $r15, inst_error
    li.w $r12, 0x2fb0dcbc; li.w $r13, 0xb3896224; mod.w $r15, $r12, $r13; li.w $r16, 0x2fb0dcbc; bne $r16, $r15, inst_error
    li.w $r12, 0xc7b128a4; li.w $r13, 0x0600b15d; mod.w $r15, $r12, $r13; li.w $r16, 0xfdb764e9; bne $r16, $r15, inst_error
    li.w $r12, 0x57d6fe0a; li.w $r13, 0x2dbec2d0; mod.w $r15, $r12, $r13; li.w $r16, 0x2a183b3a; bne $r16, $r15, inst_error
    li.w $r12, 0xa78bba58; li.w $r13, 0x1d1ce488; mod.w $r15, $r12, $r13; li.w $r16, 0xfee267f0; bne $r16, $r15, inst_error
    li.w $r12, 0x6dacf9c8; li.w $r13, 0x45e5c7a0; mod.w $r15, $r12, $r13; li.w $r16, 0x27c73228; bne $r16, $r15, inst_error
    li.w $r12, 0x62d0a060; li.w $r13, 0xb3708762; mod.w $r15, $r12, $r13; li.w $r16, 0x164127c2; bne $r16, $r15, inst_error
    li.w $r12, 0x12763f9c; li.w $r13, 0xf896d530; mod.w $r15, $r12, $r13; li.w $r16, 0x03a3e9fc; bne $r16, $r15, inst_error
    li.w $r12, 0x098ef6a0; li.w $r13, 0xcf035c50; mod.w $r15, $r12, $r13; li.w $r16, 0x098ef6a0; bne $r16, $r15, inst_error
    li.w $r12, 0x3a2491a3; li.w $r13, 0x1f054400; mod.w $r15, $r12, $r13; li.w $r16, 0x1b1f4da3; bne $r16, $r15, inst_error
    li.w $r12, 0xdd12c65c; li.w $r13, 0x8874feb8; mod.w $r15, $r12, $r13; li.w $r16, 0xdd12c65c; bne $r16, $r15, inst_error
    li.w $r12, 0x6d394d48; li.w $r13, 0xfddfc888; mod.w $r15, $r12, $r13; li.w $r16, 0x00ce4060; bne $r16, $r15, inst_error
    li.w $r12, 0x17c525ee; li.w $r13, 0xff6e16fc; mod.w $r15, $r12, $r13; li.w $r16, 0x0066d44a; bne $r16, $r15, inst_error
    li.w $r12, 0xa752a72f; li.w $r13, 0xe35b51ba; mod.w $r15, $r12, $r13; li.w $r16, 0xfd40b201; bne $r16, $r15, inst_error
    li.w $r12, 0xd92de300; li.w $r13, 0x15a8cfe5; mod.w $r15, $r12, $r13; li.w $r16, 0xeed6b2e5; bne $r16, $r15, inst_error
    li.w $r12, 0xe775a23d; li.w $r13, 0xa45ef71c; mod.w $r15, $r12, $r13; li.w $r16, 0xe775a23d; bne $r16, $r15, inst_error
    li.w $r12, 0x31f98592; li.w $r13, 0xd61078b1; mod.w $r15, $r12, $r13; li.w $r16, 0x0809fe43; bne $r16, $r15, inst_error
    li.w $r12, 0x80553a33; li.w $r13, 0xeca4bbf1; mod.w $r15, $r12, $r13; li.w $r16, 0xf478d28d; bne $r16, $r15, inst_error
    li.w $r12, 0x5e6dac0d; li.w $r13, 0x048e06c9; mod.w $r15, $r12, $r13; li.w $r16, 0x03552459; bne $r16, $r15, inst_error
    li.w $r12, 0x85b28db3; li.w $r13, 0x78d48e18; mod.w $r15, $r12, $r13; li.w $r16, 0xfe871bcb; bne $r16, $r15, inst_error
    li.w $r12, 0x59f96b98; li.w $r13, 0x0455de88; mod.w $r15, $r12, $r13; li.w $r16, 0x034408f8; bne $r16, $r15, inst_error
    li.w $r12, 0x6b36df10; li.w $r13, 0x7744092c; mod.w $r15, $r12, $r13; li.w $r16, 0x6b36df10; bne $r16, $r15, inst_error
    li.w $r12, 0x1f9e644f; li.w $r13, 0xad18886c; mod.w $r15, $r12, $r13; li.w $r16, 0x1f9e644f; bne $r16, $r15, inst_error
    li.w $r12, 0x6d189a72; li.w $r13, 0x645d8aac; mod.w $r15, $r12, $r13; li.w $r16, 0x08bb0fc6; bne $r16, $r15, inst_error
    li.w $r12, 0x0c1166a8; li.w $r13, 0x6526ce40; mod.w $r15, $r12, $r13; li.w $r16, 0x0c1166a8; bne $r16, $r15, inst_error
    li.w $r12, 0x5af79440; li.w $r13, 0xa7727e50; mod.w $r15, $r12, $r13; li.w $r16, 0x026a1290; bne $r16, $r15, inst_error
    li.w $r12, 0xebbd6e70; li.w $r13, 0x0d2b4b5b; mod.w $r15, $r12, $r13; li.w $r16, 0xf8e8b9cb; bne $r16, $r15, inst_error
    li.w $r12, 0xb2180178; li.w $r13, 0x9cb33ba8; mod.w $r15, $r12, $r13; li.w $r16, 0xb2180178; bne $r16, $r15, inst_error
    li.w $r12, 0x9d4133d8; li.w $r13, 0xb268ae15; mod.w $r15, $r12, $r13; li.w $r16, 0xead885c3; bne $r16, $r15, inst_error
    li.w $r12, 0xbd4528a6; li.w $r13, 0x4ebd7e00; mod.w $r15, $r12, $r13; li.w $r16, 0xbd4528a6; bne $r16, $r15, inst_error
    li.w $r12, 0xe4bd1250; li.w $r13, 0x488abc1c; mod.w $r15, $r12, $r13; li.w $r16, 0xe4bd1250; bne $r16, $r15, inst_error
    li.w $r12, 0xa2a77eae; li.w $r13, 0x299d2a20; mod.w $r15, $r12, $r13; li.w $r16, 0xf5e1d2ee; bne $r16, $r15, inst_error
    li.w $r12, 0x4b688500; li.w $r13, 0x16d5bb7c; mod.w $r15, $r12, $r13; li.w $r16, 0x06e7528c; bne $r16, $r15, inst_error
    li.w $r12, 0xa1da497c; li.w $r13, 0xc7ed1a50; mod.w $r15, $r12, $r13; li.w $r16, 0xd9ed2f2c; bne $r16, $r15, inst_error
    li.w $r12, 0x62260fe8; li.w $r13, 0x5ba0b130; mod.w $r15, $r12, $r13; li.w $r16, 0x06855eb8; bne $r16, $r15, inst_error
    li.w $r12, 0x9bb3f6d9; li.w $r13, 0x41e136a4; mod.w $r15, $r12, $r13; li.w $r16, 0xdd952d7d; bne $r16, $r15, inst_error
    li.w $r12, 0xd5fcd1d6; li.w $r13, 0xc073ea20; mod.w $r15, $r12, $r13; li.w $r16, 0xd5fcd1d6; bne $r16, $r15, inst_error
    li.w $r12, 0xaaceef00; li.w $r13, 0xb934eec0; mod.w $r15, $r12, $r13; li.w $r16, 0xf19a0040; bne $r16, $r15, inst_error
    li.w $r12, 0xf21b28a8; li.w $r13, 0x724b7460; mod.w $r15, $r12, $r13; li.w $r16, 0xf21b28a8; bne $r16, $r15, inst_error
    li.w $r12, 0x630e69e4; li.w $r13, 0x3d1cde06; mod.w $r15, $r12, $r13; li.w $r16, 0x25f18bde; bne $r16, $r15, inst_error
    li.w $r12, 0xbe57f2e4; li.w $r13, 0x3e9c0ea0; mod.w $r15, $r12, $r13; li.w $r16, 0xfcf40184; bne $r16, $r15, inst_error
    li.w $r12, 0x4e2c28a6; li.w $r13, 0x72662240; mod.w $r15, $r12, $r13; li.w $r16, 0x4e2c28a6; bne $r16, $r15, inst_error
    li.w $r12, 0x5f95c708; li.w $r13, 0xcf41487b; mod.w $r15, $r12, $r13; li.w $r16, 0x2ed70f83; bne $r16, $r15, inst_error
    li.w $r12, 0x8dceffe3; li.w $r13, 0xdc6a3b80; mod.w $r15, $r12, $r13; li.w $r16, 0xf8904d63; bne $r16, $r15, inst_error
    li.w $r12, 0xf5d4fec0; li.w $r13, 0xf2a8f09c; mod.w $r15, $r12, $r13; li.w $r16, 0xf5d4fec0; bne $r16, $r15, inst_error
    li.w $r12, 0x881dab60; li.w $r13, 0x9a380358; mod.w $r15, $r12, $r13; li.w $r16, 0xede5a808; bne $r16, $r15, inst_error
    li.w $r12, 0xd07715a0; li.w $r13, 0x66e639b3; mod.w $r15, $r12, $r13; li.w $r16, 0xd07715a0; bne $r16, $r15, inst_error
    li.w $r12, 0x782095ce; li.w $r13, 0x93be3000; mod.w $r15, $r12, $r13; li.w $r16, 0x0bdec5ce; bne $r16, $r15, inst_error
    li.w $r12, 0x89ec82ca; li.w $r13, 0xe20b2a70; mod.w $r15, $r12, $r13; li.w $r16, 0xe3cb037a; bne $r16, $r15, inst_error
    li.w $r12, 0xa193b0e0; li.w $r13, 0x20fa0b00; mod.w $r15, $r12, $r13; li.w $r16, 0xe387c6e0; bne $r16, $r15, inst_error
    li.w $r12, 0x3557ea04; li.w $r13, 0x75c478d0; mod.w $r15, $r12, $r13; li.w $r16, 0x3557ea04; bne $r16, $r15, inst_error
    li.w $r12, 0xa832f328; li.w $r13, 0xee25c038; mod.w $r15, $r12, $r13; li.w $r16, 0xef9bf248; bne $r16, $r15, inst_error
    li.w $r12, 0x52b5d68a; li.w $r13, 0x8899c4a8; mod.w $r15, $r12, $r13; li.w $r16, 0x52b5d68a; bne $r16, $r15, inst_error
    li.w $r12, 0x5eec8ab7; li.w $r13, 0x90af59cc; mod.w $r15, $r12, $r13; li.w $r16, 0x5eec8ab7; bne $r16, $r15, inst_error
    li.w $r12, 0xd93d3180; li.w $r13, 0x72d03460; mod.w $r15, $r12, $r13; li.w $r16, 0xd93d3180; bne $r16, $r15, inst_error
    li.w $r12, 0x77866a8e; li.w $r13, 0x32659e96; mod.w $r15, $r12, $r13; li.w $r16, 0x12bb2d62; bne $r16, $r15, inst_error
    li.w $r12, 0x5958f077; li.w $r13, 0xeb2bd5ec; mod.w $r15, $r12, $r13; li.w $r16, 0x06084827; bne $r16, $r15, inst_error
    li.w $r12, 0x6efa1a58; li.w $r13, 0xb3f65f42; mod.w $r15, $r12, $r13; li.w $r16, 0x22f0799a; bne $r16, $r15, inst_error
    li.w $r12, 0xbe718690; li.w $r13, 0xe54a2a9e; mod.w $r15, $r12, $r13; li.w $r16, 0xf3dd3154; bne $r16, $r15, inst_error
    li.w $r12, 0xd5e2a4b0; li.w $r13, 0x9a860828; mod.w $r15, $r12, $r13; li.w $r16, 0xd5e2a4b0; bne $r16, $r15, inst_error
    li.w $r12, 0x52d16644; li.w $r13, 0x2d06d3ac; mod.w $r15, $r12, $r13; li.w $r16, 0x25ca9298; bne $r16, $r15, inst_error
    li.w $r12, 0xea72e2b6; li.w $r13, 0xec307a80; mod.w $r15, $r12, $r13; li.w $r16, 0xfe426836; bne $r16, $r15, inst_error
    li.w $r12, 0xca150860; li.w $r13, 0x68ac4460; mod.w $r15, $r12, $r13; li.w $r16, 0xca150860; bne $r16, $r15, inst_error
    li.w $r12, 0x99a81ef8; li.w $r13, 0x49569c66; mod.w $r15, $r12, $r13; li.w $r16, 0xe2febb5e; bne $r16, $r15, inst_error
    li.w $r12, 0x3181e9f0; li.w $r13, 0x6f9b9c74; mod.w $r15, $r12, $r13; li.w $r16, 0x3181e9f0; bne $r16, $r15, inst_error
    li.w $r12, 0x15dd1e40; li.w $r13, 0x50a72ba0; mod.w $r15, $r12, $r13; li.w $r16, 0x15dd1e40; bne $r16, $r15, inst_error
    li.w $r12, 0xf61afe37; li.w $r13, 0xb6fcbca3; mod.w $r15, $r12, $r13; li.w $r16, 0xf61afe37; bne $r16, $r15, inst_error
    li.w $r12, 0x682fedd2; li.w $r13, 0xb339543e; mod.w $r15, $r12, $r13; li.w $r16, 0x1b694210; bne $r16, $r15, inst_error
    li.w $r12, 0xe58a4420; li.w $r13, 0xe3744db0; mod.w $r15, $r12, $r13; li.w $r16, 0xe58a4420; bne $r16, $r15, inst_error
    li.w $r12, 0xb6b9f08a; li.w $r13, 0x199a6c48; mod.w $r15, $r12, $r13; li.w $r16, 0xe9eec91a; bne $r16, $r15, inst_error
    li.w $r12, 0xdebcb606; li.w $r13, 0xe8bbaeb0; mod.w $r15, $r12, $r13; li.w $r16, 0xf6010756; bne $r16, $r15, inst_error
    li.w $r12, 0x3a71821e; li.w $r13, 0x75017300; mod.w $r15, $r12, $r13; li.w $r16, 0x3a71821e; bne $r16, $r15, inst_error
    li.w $r12, 0x16be834c; li.w $r13, 0xa7ea3340; mod.w $r15, $r12, $r13; li.w $r16, 0x16be834c; bne $r16, $r15, inst_error
    li.w $r12, 0x7130e360; li.w $r13, 0xb8ecacc0; mod.w $r15, $r12, $r13; li.w $r16, 0x2a1d9020; bne $r16, $r15, inst_error
    li.w $r12, 0x48e68d72; li.w $r13, 0x61958b0f; mod.w $r15, $r12, $r13; li.w $r16, 0x48e68d72; bne $r16, $r15, inst_error
    li.w $r12, 0xda594800; li.w $r13, 0x8045367d; mod.w $r15, $r12, $r13; li.w $r16, 0xda594800; bne $r16, $r15, inst_error
    li.w $r12, 0xe8c2df9a; li.w $r13, 0xe6c66c34; mod.w $r15, $r12, $r13; li.w $r16, 0xe8c2df9a; bne $r16, $r15, inst_error
    li.w $r12, 0x9e516c26; li.w $r13, 0xef3e3bd4; mod.w $r15, $r12, $r13; li.w $r16, 0xf21a4102; bne $r16, $r15, inst_error
    li.w $r12, 0x7f9c4ad4; li.w $r13, 0x6c56d48c; mod.w $r15, $r12, $r13; li.w $r16, 0x13457648; bne $r16, $r15, inst_error
    li.w $r12, 0x30322930; li.w $r13, 0x1b8d3720; mod.w $r15, $r12, $r13; li.w $r16, 0x14a4f210; bne $r16, $r15, inst_error
    li.w $r12, 0xf7bed7b0; li.w $r13, 0xdb77e540; mod.w $r15, $r12, $r13; li.w $r16, 0xf7bed7b0; bne $r16, $r15, inst_error
    li.w $r12, 0xa0c7d748; li.w $r13, 0x8de61300; mod.w $r15, $r12, $r13; li.w $r16, 0xa0c7d748; bne $r16, $r15, inst_error
    li.w $r12, 0xdeb2f704; li.w $r13, 0xfd2b0c11; mod.w $r15, $r12, $r13; li.w $r16, 0xfdd97249; bne $r16, $r15, inst_error
    li.w $r12, 0xc08e13d8; li.w $r13, 0x1f025330; mod.w $r15, $r12, $r13; li.w $r16, 0xfe92ba38; bne $r16, $r15, inst_error
    li.w $r12, 0x1c4fb5a4; li.w $r13, 0x9f16309a; mod.w $r15, $r12, $r13; li.w $r16, 0x1c4fb5a4; bne $r16, $r15, inst_error
    li.w $r12, 0xc79dd5a8; li.w $r13, 0x1708cffa; mod.w $r15, $r12, $r13; li.w $r16, 0xf5af759c; bne $r16, $r15, inst_error
    li.w $r12, 0xee856ae8; li.w $r13, 0x80b4ba58; mod.w $r15, $r12, $r13; li.w $r16, 0xee856ae8; bne $r16, $r15, inst_error
    li.w $r12, 0x8f9fc561; li.w $r13, 0xbd96c9d4; mod.w $r15, $r12, $r13; li.w $r16, 0xd208fb8d; bne $r16, $r15, inst_error
    li.w $r12, 0xb992d620; li.w $r13, 0xced24e3e; mod.w $r15, $r12, $r13; li.w $r16, 0xeac087e2; bne $r16, $r15, inst_error
    li.w $r12, 0x4967f580; li.w $r13, 0xe1381905; mod.w $r15, $r12, $r13; li.w $r16, 0x0bd8278a; bne $r16, $r15, inst_error
    li.w $r12, 0x722d059f; li.w $r13, 0x705cea80; mod.w $r15, $r12, $r13; li.w $r16, 0x01d01b1f; bne $r16, $r15, inst_error
    li.w $r12, 0x15053974; li.w $r13, 0x8b5e5c00; mod.w $r15, $r12, $r13; li.w $r16, 0x15053974; bne $r16, $r15, inst_error
    li.w $r12, 0x664c2a8c; li.w $r13, 0x50bf0b96; mod.w $r15, $r12, $r13; li.w $r16, 0x158d1ef6; bne $r16, $r15, inst_error
    li.w $r12, 0x92395380; li.w $r13, 0x15c2099e; mod.w $r15, $r12, $r13; li.w $r16, 0xff038396; bne $r16, $r15, inst_error
    li.w $r12, 0xf24a2a85; li.w $r13, 0xca406d34; mod.w $r15, $r12, $r13; li.w $r16, 0xf24a2a85; bne $r16, $r15, inst_error
    li.w $r12, 0x9187ed80; li.w $r13, 0xb8ff4cc8; mod.w $r15, $r12, $r13; li.w $r16, 0xd888a0b8; bne $r16, $r15, inst_error
    li.w $r12, 0x00000000; li.w $r13, 0xa7bb1ef0; mod.w $r15, $r12, $r13; li.w $r16, 0x00000000; bne $r16, $r15, inst_error
    li.w $r12, 0x00000000; li.w $r13, 0x3050efec; mod.w $r15, $r12, $r13; li.w $r16, 0x00000000; bne $r16, $r15, inst_error
    li.w $r12, 0x00000000; li.w $r13, 0x94e29c00; mod.w $r15, $r12, $r13; li.w $r16, 0x00000000; bne $r16, $r15, inst_error

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
.cfi_endproc ; .size n35_mod_w_test,.-n35_mod_w_test;
