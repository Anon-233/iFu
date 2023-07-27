package iFu.backend

object CSRs {
    val CRMD            = 0x0;
    val PRMD            = 0x1;
    val ECTL            = 0x4;
    val ESTAT           = 0x5;
    val ERA             = 0x6;
    val BADV            = 0x7;
    val EENTRY          = 0xc;
    val TLBIDX          = 0x10;
    val TLBEHI          = 0x11;
    val TLBELO0         = 0x12;
    val TLBELO1         = 0x13;
    val ASID            = 0x18;
    val PGDL            = 0x19;
    val PGDH            = 0x1a;
    val PGD             = 0x1b;
    val CPUID           = 0x20;
    val SAVE0           = 0x30;
    val SAVE1           = 0x31;
    val SAVE2           = 0x32;
    val SAVE3           = 0x33;
    val TID             = 0x40;
    val TCFG            = 0x41;
    val TVAL            = 0x42;
    val CNTC            = 0x43;
    val TICLR           = 0x44;
    val LLBCTL          = 0x60;
    val TLBRENTRY       = 0x88;
    val DMW0            = 0x180;
    val DMW1            = 0x181;
    val BRK             = 0x100;
    val DISABLE_CACHE   = 0x101;
}