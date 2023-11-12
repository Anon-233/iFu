// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_fst_c.h"
#include "Vsimu_top__Syms.h"


void Vsimu_top___024root__trace_chg_sub_8(Vsimu_top___024root* vlSelf, VerilatedFst::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vsimu_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsimu_top___024root__trace_chg_sub_8\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 11900);
    // Body
    if (VL_UNLIKELY((vlSelf->__Vm_traceActivity[1U] 
                     | vlSelf->__Vm_traceActivity[2U]))) {
        bufp->chgSData(oldp+0,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                               [0x27U]),14);
        bufp->chgSData(oldp+1,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellout__wallacefor__BRA__39__KET____DOT__bi__COut),14);
        bufp->chgBit(oldp+2,((1U & (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__39__KET____DOT__bi__DOT__FifSig) 
                                     & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x27U] >> 0xdU) 
                                        | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x27U] 
                                           >> 0xcU))) 
                                    | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                        [0x27U] >> 0xdU) 
                                       & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x27U] >> 0xcU))))));
        bufp->chgBit(oldp+3,((1U & ((((((~ (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__39__KET____DOT__bi__DOT__FifSig)) 
                                        & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                              [0x27U] 
                                              >> 0xdU))) 
                                       & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x27U] >> 0xcU)) 
                                      | (((~ (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__39__KET____DOT__bi__DOT__FifSig)) 
                                          & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [0x27U] 
                                             >> 0xdU)) 
                                         & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                               [0x27U] 
                                               >> 0xcU)))) 
                                     | (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__39__KET____DOT__bi__DOT__FifSig) 
                                         & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                               [0x27U] 
                                               >> 0xdU))) 
                                        & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                              [0x27U] 
                                              >> 0xcU)))) 
                                    | (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__39__KET____DOT__bi__DOT__FifSig) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x27U] 
                                           >> 0xdU)) 
                                       & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x27U] >> 0xcU))))));
        bufp->chgCData(oldp+4,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__39__KET____DOT__bi__DOT__SecSig),4);
        bufp->chgBit(oldp+5,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                    [0x27U] >> 0xbU))));
        bufp->chgBit(oldp+6,((1U & ((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__39__KET____DOT__bi__DOT__ForSig) 
                                      >> 1U) & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__39__KET____DOT__bi__DOT__ForSig) 
                                                | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                   [0x27U] 
                                                   >> 0xbU))) 
                                    | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__39__KET____DOT__bi__DOT__ForSig) 
                                       & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x27U] >> 0xbU))))));
        bufp->chgBit(oldp+7,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                    [0x27U] >> 9U))));
        bufp->chgBit(oldp+8,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                    [0x27U] >> 8U))));
        bufp->chgBit(oldp+9,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                    [0x27U] >> 7U))));
        bufp->chgBit(oldp+10,((1U & (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                       [0x27U] >> 9U) 
                                      & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x27U] >> 8U) 
                                         | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x27U] 
                                            >> 7U))) 
                                     | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x27U] >> 8U) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x27U] 
                                           >> 7U))))));
        bufp->chgBit(oldp+11,((1U & ((((((~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [0x27U] 
                                             >> 9U)) 
                                         & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                               [0x27U] 
                                               >> 8U))) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x27U] 
                                           >> 7U)) 
                                       | (((~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                               [0x27U] 
                                               >> 9U)) 
                                           & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                              [0x27U] 
                                              >> 8U)) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x27U] 
                                                >> 7U)))) 
                                      | (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x27U] 
                                           >> 9U) & 
                                          (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                              [0x27U] 
                                              >> 8U))) 
                                         & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                               [0x27U] 
                                               >> 7U)))) 
                                     | (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x27U] >> 9U) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x27U] 
                                            >> 8U)) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x27U] 
                                           >> 7U))))));
        bufp->chgBit(oldp+12,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x27U] >> 0xaU))));
        bufp->chgBit(oldp+13,((1U & ((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__39__KET____DOT__bi__DOT__ThiSig) 
                                       >> 1U) & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__39__KET____DOT__bi__DOT__ThiSig) 
                                                 | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                    [0x27U] 
                                                    >> 0xaU))) 
                                     | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__39__KET____DOT__bi__DOT__ThiSig) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x27U] 
                                           >> 0xaU))))));
        bufp->chgBit(oldp+14,((1U & (((((IData)((0U 
                                                 == (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__39__KET____DOT__bi__DOT__ThiSig))) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x27U] 
                                           >> 0xaU)) 
                                       | ((IData)((1U 
                                                   == (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__39__KET____DOT__bi__DOT__ThiSig))) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x27U] 
                                                >> 0xaU)))) 
                                      | ((IData)((2U 
                                                  == (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__39__KET____DOT__bi__DOT__ThiSig))) 
                                         & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                               [0x27U] 
                                               >> 0xaU)))) 
                                     | ((IData)((3U 
                                                 == (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__39__KET____DOT__bi__DOT__ThiSig))) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x27U] 
                                           >> 0xaU))))));
        bufp->chgBit(oldp+15,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x27U] >> 2U))));
        bufp->chgBit(oldp+16,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x27U] >> 1U))));
        bufp->chgBit(oldp+17,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                               [0x27U])));
        bufp->chgBit(oldp+18,((1U & (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                       [0x27U] >> 2U) 
                                      & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x27U] >> 1U) 
                                         | vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x27U])) 
                                     | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x27U] >> 1U) 
                                        & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                        [0x27U])))));
        bufp->chgBit(oldp+19,((1U & ((((((~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [0x27U] 
                                             >> 2U)) 
                                         & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                               [0x27U] 
                                               >> 1U))) 
                                        & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                        [0x27U]) | 
                                       (((~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [0x27U] 
                                             >> 2U)) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x27U] 
                                            >> 1U)) 
                                        & (~ vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x27U]))) 
                                      | (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x27U] 
                                           >> 2U) & 
                                          (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                              [0x27U] 
                                              >> 1U))) 
                                         & (~ vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x27U]))) 
                                     | (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x27U] >> 2U) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x27U] 
                                            >> 1U)) 
                                        & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                        [0x27U])))));
        bufp->chgBit(oldp+20,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x27U] >> 4U))));
        bufp->chgBit(oldp+21,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x27U] >> 3U))));
        bufp->chgBit(oldp+22,((1U & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__39__KET____DOT__bi__InData 
                                      & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x27U] >> 4U) 
                                         | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x27U] 
                                            >> 3U))) 
                                     | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x27U] >> 4U) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x27U] 
                                           >> 3U))))));
        bufp->chgBit(oldp+23,((1U & ((((((~ vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__39__KET____DOT__bi__InData) 
                                         & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                               [0x27U] 
                                               >> 4U))) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x27U] 
                                           >> 3U)) 
                                       | (((~ vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__39__KET____DOT__bi__InData) 
                                           & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                              [0x27U] 
                                              >> 4U)) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x27U] 
                                                >> 3U)))) 
                                      | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__39__KET____DOT__bi__InData 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x27U] 
                                                >> 4U))) 
                                         & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                               [0x27U] 
                                               >> 3U)))) 
                                     | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__39__KET____DOT__bi__InData 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x27U] 
                                            >> 4U)) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x27U] 
                                           >> 3U))))));
        bufp->chgBit(oldp+24,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x27U] >> 0xdU))));
        bufp->chgBit(oldp+25,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x27U] >> 0xcU))));
        bufp->chgBit(oldp+26,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__39__KET____DOT__bi__DOT__SecSig))));
        bufp->chgBit(oldp+27,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x27U] >> 6U))));
        bufp->chgBit(oldp+28,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x27U] >> 5U))));
        bufp->chgBit(oldp+29,((1U & (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__39__KET____DOT__bi__DOT__SecSig) 
                                      & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x27U] >> 6U) 
                                         | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x27U] 
                                            >> 5U))) 
                                     | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x27U] >> 6U) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x27U] 
                                           >> 5U))))));
        bufp->chgBit(oldp+30,((1U & ((((((~ (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__39__KET____DOT__bi__DOT__SecSig)) 
                                         & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                               [0x27U] 
                                               >> 6U))) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x27U] 
                                           >> 5U)) 
                                       | (((~ (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__39__KET____DOT__bi__DOT__SecSig)) 
                                           & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                              [0x27U] 
                                              >> 6U)) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x27U] 
                                                >> 5U)))) 
                                      | (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__39__KET____DOT__bi__DOT__SecSig) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x27U] 
                                                >> 6U))) 
                                         & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                               [0x27U] 
                                               >> 5U)))) 
                                     | (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__39__KET____DOT__bi__DOT__SecSig) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x27U] 
                                            >> 6U)) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x27U] 
                                           >> 5U))))));
        bufp->chgBit(oldp+31,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__39__KET____DOT__bi__DOT__SecSig) 
                                     >> 3U))));
        bufp->chgBit(oldp+32,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__39__KET____DOT__bi__DOT__SecSig) 
                                     >> 2U))));
        bufp->chgBit(oldp+33,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__39__KET____DOT__bi__DOT__SecSig) 
                                     >> 1U))));
        bufp->chgBit(oldp+34,((1U & ((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__39__KET____DOT__bi__DOT__SecSig) 
                                       >> 3U) & (IData)(
                                                        (0U 
                                                         != 
                                                         (6U 
                                                          & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__39__KET____DOT__bi__DOT__SecSig))))) 
                                     | (IData)((6U 
                                                == 
                                                (6U 
                                                 & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__39__KET____DOT__bi__DOT__SecSig))))))));
        bufp->chgBit(oldp+35,((1U & ((((IData)((2U 
                                                == 
                                                (0xeU 
                                                 & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__39__KET____DOT__bi__DOT__SecSig)))) 
                                       | (IData)((4U 
                                                  == 
                                                  (0xeU 
                                                   & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__39__KET____DOT__bi__DOT__SecSig))))) 
                                      | (IData)((8U 
                                                 == 
                                                 (0xeU 
                                                  & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__39__KET____DOT__bi__DOT__SecSig))))) 
                                     | (IData)((0xeU 
                                                == 
                                                (0xeU 
                                                 & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__39__KET____DOT__bi__DOT__SecSig))))))));
        bufp->chgSData(oldp+36,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                [3U]),14);
        bufp->chgSData(oldp+37,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellout__wallacefor__BRA__3__KET____DOT__bi__COut),14);
        bufp->chgBit(oldp+38,((1U & (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__3__KET____DOT__bi__DOT__FifSig) 
                                      & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [3U] >> 0xdU) 
                                         | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [3U] >> 0xcU))) 
                                     | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [3U] >> 0xdU) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [3U] >> 0xcU))))));
        bufp->chgBit(oldp+39,((1U & ((((((~ (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__3__KET____DOT__bi__DOT__FifSig)) 
                                         & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                               [3U] 
                                               >> 0xdU))) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [3U] >> 0xcU)) 
                                       | (((~ (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__3__KET____DOT__bi__DOT__FifSig)) 
                                           & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                              [3U] 
                                              >> 0xdU)) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [3U] 
                                                >> 0xcU)))) 
                                      | (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__3__KET____DOT__bi__DOT__FifSig) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [3U] 
                                                >> 0xdU))) 
                                         & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                               [3U] 
                                               >> 0xcU)))) 
                                     | (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__3__KET____DOT__bi__DOT__FifSig) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [3U] >> 0xdU)) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [3U] >> 0xcU))))));
        bufp->chgCData(oldp+40,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__3__KET____DOT__bi__DOT__SecSig),4);
        bufp->chgBit(oldp+41,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [3U] >> 0xbU))));
        bufp->chgBit(oldp+42,((1U & ((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__3__KET____DOT__bi__DOT__ForSig) 
                                       >> 1U) & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__3__KET____DOT__bi__DOT__ForSig) 
                                                 | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                    [3U] 
                                                    >> 0xbU))) 
                                     | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__3__KET____DOT__bi__DOT__ForSig) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [3U] >> 0xbU))))));
        bufp->chgBit(oldp+43,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [3U] >> 9U))));
        bufp->chgBit(oldp+44,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [3U] >> 8U))));
        bufp->chgBit(oldp+45,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [3U] >> 7U))));
        bufp->chgBit(oldp+46,((1U & (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                       [3U] >> 9U) 
                                      & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [3U] >> 8U) 
                                         | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [3U] >> 7U))) 
                                     | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [3U] >> 8U) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [3U] >> 7U))))));
        bufp->chgBit(oldp+47,((1U & ((((((~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [3U] >> 9U)) 
                                         & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                               [3U] 
                                               >> 8U))) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [3U] >> 7U)) 
                                       | (((~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                               [3U] 
                                               >> 9U)) 
                                           & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                              [3U] 
                                              >> 8U)) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [3U] 
                                                >> 7U)))) 
                                      | (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [3U] >> 9U) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [3U] 
                                                >> 8U))) 
                                         & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                               [3U] 
                                               >> 7U)))) 
                                     | (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [3U] >> 9U) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [3U] >> 8U)) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [3U] >> 7U))))));
        bufp->chgBit(oldp+48,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [3U] >> 0xaU))));
        bufp->chgBit(oldp+49,((1U & ((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__3__KET____DOT__bi__DOT__ThiSig) 
                                       >> 1U) & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__3__KET____DOT__bi__DOT__ThiSig) 
                                                 | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                    [3U] 
                                                    >> 0xaU))) 
                                     | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__3__KET____DOT__bi__DOT__ThiSig) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [3U] >> 0xaU))))));
        bufp->chgBit(oldp+50,((1U & (((((IData)((0U 
                                                 == (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__3__KET____DOT__bi__DOT__ThiSig))) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [3U] >> 0xaU)) 
                                       | ((IData)((1U 
                                                   == (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__3__KET____DOT__bi__DOT__ThiSig))) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [3U] 
                                                >> 0xaU)))) 
                                      | ((IData)((2U 
                                                  == (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__3__KET____DOT__bi__DOT__ThiSig))) 
                                         & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                               [3U] 
                                               >> 0xaU)))) 
                                     | ((IData)((3U 
                                                 == (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__3__KET____DOT__bi__DOT__ThiSig))) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [3U] >> 0xaU))))));
        bufp->chgBit(oldp+51,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [3U] >> 2U))));
        bufp->chgBit(oldp+52,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [3U] >> 1U))));
        bufp->chgBit(oldp+53,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                               [3U])));
        bufp->chgBit(oldp+54,((1U & (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                       [3U] >> 2U) 
                                      & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [3U] >> 1U) 
                                         | vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [3U])) | (
                                                   (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                    [3U] 
                                                    >> 1U) 
                                                   & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                   [3U])))));
        bufp->chgBit(oldp+55,((1U & ((((((~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [3U] >> 2U)) 
                                         & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                               [3U] 
                                               >> 1U))) 
                                        & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                        [3U]) | (((~ 
                                                   (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                    [3U] 
                                                    >> 2U)) 
                                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                     [3U] 
                                                     >> 1U)) 
                                                 & (~ 
                                                    vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                    [3U]))) 
                                      | (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [3U] >> 2U) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [3U] 
                                                >> 1U))) 
                                         & (~ vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [3U]))) 
                                     | (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [3U] >> 2U) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [3U] >> 1U)) 
                                        & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                        [3U])))));
        bufp->chgBit(oldp+56,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [3U] >> 4U))));
        bufp->chgBit(oldp+57,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [3U] >> 3U))));
        bufp->chgBit(oldp+58,((1U & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__3__KET____DOT__bi__InData 
                                      & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [3U] >> 4U) 
                                         | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [3U] >> 3U))) 
                                     | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [3U] >> 4U) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [3U] >> 3U))))));
        bufp->chgBit(oldp+59,((1U & ((((((~ vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__3__KET____DOT__bi__InData) 
                                         & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                               [3U] 
                                               >> 4U))) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [3U] >> 3U)) 
                                       | (((~ vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__3__KET____DOT__bi__InData) 
                                           & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                              [3U] 
                                              >> 4U)) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [3U] 
                                                >> 3U)))) 
                                      | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__3__KET____DOT__bi__InData 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [3U] 
                                                >> 4U))) 
                                         & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                               [3U] 
                                               >> 3U)))) 
                                     | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__3__KET____DOT__bi__InData 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [3U] >> 4U)) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [3U] >> 3U))))));
        bufp->chgBit(oldp+60,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [3U] >> 0xdU))));
        bufp->chgBit(oldp+61,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [3U] >> 0xcU))));
        bufp->chgBit(oldp+62,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__3__KET____DOT__bi__DOT__SecSig))));
        bufp->chgBit(oldp+63,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [3U] >> 6U))));
        bufp->chgBit(oldp+64,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [3U] >> 5U))));
        bufp->chgBit(oldp+65,((1U & (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__3__KET____DOT__bi__DOT__SecSig) 
                                      & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [3U] >> 6U) 
                                         | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [3U] >> 5U))) 
                                     | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [3U] >> 6U) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [3U] >> 5U))))));
        bufp->chgBit(oldp+66,((1U & ((((((~ (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__3__KET____DOT__bi__DOT__SecSig)) 
                                         & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                               [3U] 
                                               >> 6U))) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [3U] >> 5U)) 
                                       | (((~ (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__3__KET____DOT__bi__DOT__SecSig)) 
                                           & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                              [3U] 
                                              >> 6U)) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [3U] 
                                                >> 5U)))) 
                                      | (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__3__KET____DOT__bi__DOT__SecSig) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [3U] 
                                                >> 6U))) 
                                         & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                               [3U] 
                                               >> 5U)))) 
                                     | (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__3__KET____DOT__bi__DOT__SecSig) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [3U] >> 6U)) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [3U] >> 5U))))));
        bufp->chgBit(oldp+67,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__3__KET____DOT__bi__DOT__SecSig) 
                                     >> 3U))));
        bufp->chgBit(oldp+68,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__3__KET____DOT__bi__DOT__SecSig) 
                                     >> 2U))));
        bufp->chgBit(oldp+69,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__3__KET____DOT__bi__DOT__SecSig) 
                                     >> 1U))));
        bufp->chgBit(oldp+70,((1U & ((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__3__KET____DOT__bi__DOT__SecSig) 
                                       >> 3U) & (IData)(
                                                        (0U 
                                                         != 
                                                         (6U 
                                                          & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__3__KET____DOT__bi__DOT__SecSig))))) 
                                     | (IData)((6U 
                                                == 
                                                (6U 
                                                 & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__3__KET____DOT__bi__DOT__SecSig))))))));
        bufp->chgBit(oldp+71,((1U & ((((IData)((2U 
                                                == 
                                                (0xeU 
                                                 & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__3__KET____DOT__bi__DOT__SecSig)))) 
                                       | (IData)((4U 
                                                  == 
                                                  (0xeU 
                                                   & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__3__KET____DOT__bi__DOT__SecSig))))) 
                                      | (IData)((8U 
                                                 == 
                                                 (0xeU 
                                                  & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__3__KET____DOT__bi__DOT__SecSig))))) 
                                     | (IData)((0xeU 
                                                == 
                                                (0xeU 
                                                 & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__3__KET____DOT__bi__DOT__SecSig))))))));
        bufp->chgSData(oldp+72,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                [0x28U]),14);
        bufp->chgSData(oldp+73,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellout__wallacefor__BRA__40__KET____DOT__bi__COut),14);
        bufp->chgBit(oldp+74,((1U & (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__40__KET____DOT__bi__DOT__FifSig) 
                                      & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x28U] >> 0xdU) 
                                         | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x28U] 
                                            >> 0xcU))) 
                                     | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x28U] >> 0xdU) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x28U] 
                                           >> 0xcU))))));
        bufp->chgBit(oldp+75,((1U & ((((((~ (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__40__KET____DOT__bi__DOT__FifSig)) 
                                         & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                               [0x28U] 
                                               >> 0xdU))) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x28U] 
                                           >> 0xcU)) 
                                       | (((~ (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__40__KET____DOT__bi__DOT__FifSig)) 
                                           & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                              [0x28U] 
                                              >> 0xdU)) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x28U] 
                                                >> 0xcU)))) 
                                      | (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__40__KET____DOT__bi__DOT__FifSig) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x28U] 
                                                >> 0xdU))) 
                                         & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                               [0x28U] 
                                               >> 0xcU)))) 
                                     | (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__40__KET____DOT__bi__DOT__FifSig) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x28U] 
                                            >> 0xdU)) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x28U] 
                                           >> 0xcU))))));
        bufp->chgCData(oldp+76,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__40__KET____DOT__bi__DOT__SecSig),4);
        bufp->chgBit(oldp+77,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x28U] >> 0xbU))));
        bufp->chgBit(oldp+78,((1U & ((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__40__KET____DOT__bi__DOT__ForSig) 
                                       >> 1U) & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__40__KET____DOT__bi__DOT__ForSig) 
                                                 | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                    [0x28U] 
                                                    >> 0xbU))) 
                                     | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__40__KET____DOT__bi__DOT__ForSig) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x28U] 
                                           >> 0xbU))))));
        bufp->chgBit(oldp+79,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x28U] >> 9U))));
        bufp->chgBit(oldp+80,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x28U] >> 8U))));
        bufp->chgBit(oldp+81,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x28U] >> 7U))));
        bufp->chgBit(oldp+82,((1U & (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                       [0x28U] >> 9U) 
                                      & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x28U] >> 8U) 
                                         | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x28U] 
                                            >> 7U))) 
                                     | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x28U] >> 8U) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x28U] 
                                           >> 7U))))));
        bufp->chgBit(oldp+83,((1U & ((((((~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [0x28U] 
                                             >> 9U)) 
                                         & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                               [0x28U] 
                                               >> 8U))) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x28U] 
                                           >> 7U)) 
                                       | (((~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                               [0x28U] 
                                               >> 9U)) 
                                           & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                              [0x28U] 
                                              >> 8U)) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x28U] 
                                                >> 7U)))) 
                                      | (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x28U] 
                                           >> 9U) & 
                                          (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                              [0x28U] 
                                              >> 8U))) 
                                         & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                               [0x28U] 
                                               >> 7U)))) 
                                     | (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x28U] >> 9U) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x28U] 
                                            >> 8U)) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x28U] 
                                           >> 7U))))));
        bufp->chgBit(oldp+84,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x28U] >> 0xaU))));
        bufp->chgBit(oldp+85,((1U & ((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__40__KET____DOT__bi__DOT__ThiSig) 
                                       >> 1U) & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__40__KET____DOT__bi__DOT__ThiSig) 
                                                 | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                    [0x28U] 
                                                    >> 0xaU))) 
                                     | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__40__KET____DOT__bi__DOT__ThiSig) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x28U] 
                                           >> 0xaU))))));
        bufp->chgBit(oldp+86,((1U & (((((IData)((0U 
                                                 == (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__40__KET____DOT__bi__DOT__ThiSig))) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x28U] 
                                           >> 0xaU)) 
                                       | ((IData)((1U 
                                                   == (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__40__KET____DOT__bi__DOT__ThiSig))) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x28U] 
                                                >> 0xaU)))) 
                                      | ((IData)((2U 
                                                  == (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__40__KET____DOT__bi__DOT__ThiSig))) 
                                         & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                               [0x28U] 
                                               >> 0xaU)))) 
                                     | ((IData)((3U 
                                                 == (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__40__KET____DOT__bi__DOT__ThiSig))) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x28U] 
                                           >> 0xaU))))));
        bufp->chgBit(oldp+87,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x28U] >> 2U))));
        bufp->chgBit(oldp+88,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x28U] >> 1U))));
        bufp->chgBit(oldp+89,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                               [0x28U])));
        bufp->chgBit(oldp+90,((1U & (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                       [0x28U] >> 2U) 
                                      & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x28U] >> 1U) 
                                         | vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x28U])) 
                                     | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x28U] >> 1U) 
                                        & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                        [0x28U])))));
        bufp->chgBit(oldp+91,((1U & ((((((~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [0x28U] 
                                             >> 2U)) 
                                         & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                               [0x28U] 
                                               >> 1U))) 
                                        & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                        [0x28U]) | 
                                       (((~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [0x28U] 
                                             >> 2U)) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x28U] 
                                            >> 1U)) 
                                        & (~ vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x28U]))) 
                                      | (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x28U] 
                                           >> 2U) & 
                                          (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                              [0x28U] 
                                              >> 1U))) 
                                         & (~ vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x28U]))) 
                                     | (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x28U] >> 2U) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x28U] 
                                            >> 1U)) 
                                        & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                        [0x28U])))));
        bufp->chgBit(oldp+92,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x28U] >> 4U))));
        bufp->chgBit(oldp+93,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x28U] >> 3U))));
        bufp->chgBit(oldp+94,((1U & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__40__KET____DOT__bi__InData 
                                      & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x28U] >> 4U) 
                                         | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x28U] 
                                            >> 3U))) 
                                     | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x28U] >> 4U) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x28U] 
                                           >> 3U))))));
        bufp->chgBit(oldp+95,((1U & ((((((~ vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__40__KET____DOT__bi__InData) 
                                         & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                               [0x28U] 
                                               >> 4U))) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x28U] 
                                           >> 3U)) 
                                       | (((~ vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__40__KET____DOT__bi__InData) 
                                           & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                              [0x28U] 
                                              >> 4U)) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x28U] 
                                                >> 3U)))) 
                                      | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__40__KET____DOT__bi__InData 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x28U] 
                                                >> 4U))) 
                                         & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                               [0x28U] 
                                               >> 3U)))) 
                                     | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__40__KET____DOT__bi__InData 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x28U] 
                                            >> 4U)) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x28U] 
                                           >> 3U))))));
        bufp->chgBit(oldp+96,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x28U] >> 0xdU))));
        bufp->chgBit(oldp+97,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x28U] >> 0xcU))));
        bufp->chgBit(oldp+98,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__40__KET____DOT__bi__DOT__SecSig))));
        bufp->chgBit(oldp+99,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x28U] >> 6U))));
        bufp->chgBit(oldp+100,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x28U] >> 5U))));
        bufp->chgBit(oldp+101,((1U & (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__40__KET____DOT__bi__DOT__SecSig) 
                                       & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x28U] 
                                           >> 6U) | 
                                          (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x28U] 
                                           >> 5U))) 
                                      | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x28U] >> 6U) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x28U] 
                                            >> 5U))))));
        bufp->chgBit(oldp+102,((1U & ((((((~ (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__40__KET____DOT__bi__DOT__SecSig)) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x28U] 
                                                >> 6U))) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x28U] 
                                            >> 5U)) 
                                        | (((~ (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__40__KET____DOT__bi__DOT__SecSig)) 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                               [0x28U] 
                                               >> 6U)) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x28U] 
                                                 >> 5U)))) 
                                       | (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__40__KET____DOT__bi__DOT__SecSig) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x28U] 
                                                 >> 6U))) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x28U] 
                                                >> 5U)))) 
                                      | (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__40__KET____DOT__bi__DOT__SecSig) 
                                          & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [0x28U] 
                                             >> 6U)) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x28U] 
                                            >> 5U))))));
        bufp->chgBit(oldp+103,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__40__KET____DOT__bi__DOT__SecSig) 
                                      >> 3U))));
        bufp->chgBit(oldp+104,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__40__KET____DOT__bi__DOT__SecSig) 
                                      >> 2U))));
        bufp->chgBit(oldp+105,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__40__KET____DOT__bi__DOT__SecSig) 
                                      >> 1U))));
        bufp->chgBit(oldp+106,((1U & ((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__40__KET____DOT__bi__DOT__SecSig) 
                                        >> 3U) & (IData)(
                                                         (0U 
                                                          != 
                                                          (6U 
                                                           & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__40__KET____DOT__bi__DOT__SecSig))))) 
                                      | (IData)((6U 
                                                 == 
                                                 (6U 
                                                  & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__40__KET____DOT__bi__DOT__SecSig))))))));
        bufp->chgBit(oldp+107,((1U & ((((IData)((2U 
                                                 == 
                                                 (0xeU 
                                                  & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__40__KET____DOT__bi__DOT__SecSig)))) 
                                        | (IData)((4U 
                                                   == 
                                                   (0xeU 
                                                    & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__40__KET____DOT__bi__DOT__SecSig))))) 
                                       | (IData)((8U 
                                                  == 
                                                  (0xeU 
                                                   & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__40__KET____DOT__bi__DOT__SecSig))))) 
                                      | (IData)((0xeU 
                                                 == 
                                                 (0xeU 
                                                  & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__40__KET____DOT__bi__DOT__SecSig))))))));
        bufp->chgSData(oldp+108,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                 [0x29U]),14);
        bufp->chgSData(oldp+109,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellout__wallacefor__BRA__41__KET____DOT__bi__COut),14);
        bufp->chgBit(oldp+110,((1U & (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__41__KET____DOT__bi__DOT__FifSig) 
                                       & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x29U] 
                                           >> 0xdU) 
                                          | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [0x29U] 
                                             >> 0xcU))) 
                                      | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x29U] >> 0xdU) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x29U] 
                                            >> 0xcU))))));
        bufp->chgBit(oldp+111,((1U & ((((((~ (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__41__KET____DOT__bi__DOT__FifSig)) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x29U] 
                                                >> 0xdU))) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x29U] 
                                            >> 0xcU)) 
                                        | (((~ (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__41__KET____DOT__bi__DOT__FifSig)) 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                               [0x29U] 
                                               >> 0xdU)) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x29U] 
                                                 >> 0xcU)))) 
                                       | (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__41__KET____DOT__bi__DOT__FifSig) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x29U] 
                                                 >> 0xdU))) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x29U] 
                                                >> 0xcU)))) 
                                      | (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__41__KET____DOT__bi__DOT__FifSig) 
                                          & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [0x29U] 
                                             >> 0xdU)) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x29U] 
                                            >> 0xcU))))));
        bufp->chgCData(oldp+112,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__41__KET____DOT__bi__DOT__SecSig),4);
        bufp->chgBit(oldp+113,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x29U] >> 0xbU))));
        bufp->chgBit(oldp+114,((1U & ((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__41__KET____DOT__bi__DOT__ForSig) 
                                        >> 1U) & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__41__KET____DOT__bi__DOT__ForSig) 
                                                  | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                     [0x29U] 
                                                     >> 0xbU))) 
                                      | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__41__KET____DOT__bi__DOT__ForSig) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x29U] 
                                            >> 0xbU))))));
        bufp->chgBit(oldp+115,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x29U] >> 9U))));
        bufp->chgBit(oldp+116,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x29U] >> 8U))));
        bufp->chgBit(oldp+117,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x29U] >> 7U))));
        bufp->chgBit(oldp+118,((1U & (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                        [0x29U] >> 9U) 
                                       & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x29U] 
                                           >> 8U) | 
                                          (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x29U] 
                                           >> 7U))) 
                                      | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x29U] >> 8U) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x29U] 
                                            >> 7U))))));
        bufp->chgBit(oldp+119,((1U & ((((((~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                              [0x29U] 
                                              >> 9U)) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x29U] 
                                                >> 8U))) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x29U] 
                                            >> 7U)) 
                                        | (((~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x29U] 
                                                >> 9U)) 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                               [0x29U] 
                                               >> 8U)) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x29U] 
                                                 >> 7U)))) 
                                       | (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x29U] 
                                            >> 9U) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x29U] 
                                                 >> 8U))) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x29U] 
                                                >> 7U)))) 
                                      | (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x29U] 
                                           >> 9U) & 
                                          (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x29U] 
                                           >> 8U)) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x29U] 
                                            >> 7U))))));
        bufp->chgBit(oldp+120,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x29U] >> 0xaU))));
        bufp->chgBit(oldp+121,((1U & ((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__41__KET____DOT__bi__DOT__ThiSig) 
                                        >> 1U) & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__41__KET____DOT__bi__DOT__ThiSig) 
                                                  | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                     [0x29U] 
                                                     >> 0xaU))) 
                                      | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__41__KET____DOT__bi__DOT__ThiSig) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x29U] 
                                            >> 0xaU))))));
        bufp->chgBit(oldp+122,((1U & (((((IData)((0U 
                                                  == (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__41__KET____DOT__bi__DOT__ThiSig))) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x29U] 
                                            >> 0xaU)) 
                                        | ((IData)(
                                                   (1U 
                                                    == (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__41__KET____DOT__bi__DOT__ThiSig))) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x29U] 
                                                 >> 0xaU)))) 
                                       | ((IData)((2U 
                                                   == (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__41__KET____DOT__bi__DOT__ThiSig))) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x29U] 
                                                >> 0xaU)))) 
                                      | ((IData)((3U 
                                                  == (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__41__KET____DOT__bi__DOT__ThiSig))) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x29U] 
                                            >> 0xaU))))));
        bufp->chgBit(oldp+123,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x29U] >> 2U))));
        bufp->chgBit(oldp+124,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x29U] >> 1U))));
        bufp->chgBit(oldp+125,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                [0x29U])));
        bufp->chgBit(oldp+126,((1U & (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                        [0x29U] >> 2U) 
                                       & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x29U] 
                                           >> 1U) | 
                                          vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x29U])) 
                                      | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x29U] >> 1U) 
                                         & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x29U])))));
        bufp->chgBit(oldp+127,((1U & ((((((~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                              [0x29U] 
                                              >> 2U)) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x29U] 
                                                >> 1U))) 
                                         & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x29U]) | 
                                        (((~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                              [0x29U] 
                                              >> 2U)) 
                                          & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [0x29U] 
                                             >> 1U)) 
                                         & (~ vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x29U]))) 
                                       | (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x29U] 
                                            >> 2U) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x29U] 
                                                 >> 1U))) 
                                          & (~ vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [0x29U]))) 
                                      | (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x29U] 
                                           >> 2U) & 
                                          (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x29U] 
                                           >> 1U)) 
                                         & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x29U])))));
        bufp->chgBit(oldp+128,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x29U] >> 4U))));
        bufp->chgBit(oldp+129,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x29U] >> 3U))));
        bufp->chgBit(oldp+130,((1U & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__41__KET____DOT__bi__InData 
                                       & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x29U] 
                                           >> 4U) | 
                                          (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x29U] 
                                           >> 3U))) 
                                      | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x29U] >> 4U) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x29U] 
                                            >> 3U))))));
        bufp->chgBit(oldp+131,((1U & ((((((~ vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__41__KET____DOT__bi__InData) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x29U] 
                                                >> 4U))) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x29U] 
                                            >> 3U)) 
                                        | (((~ vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__41__KET____DOT__bi__InData) 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                               [0x29U] 
                                               >> 4U)) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x29U] 
                                                 >> 3U)))) 
                                       | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__41__KET____DOT__bi__InData 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x29U] 
                                                 >> 4U))) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x29U] 
                                                >> 3U)))) 
                                      | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__41__KET____DOT__bi__InData 
                                          & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [0x29U] 
                                             >> 4U)) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x29U] 
                                            >> 3U))))));
        bufp->chgBit(oldp+132,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x29U] >> 0xdU))));
        bufp->chgBit(oldp+133,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x29U] >> 0xcU))));
        bufp->chgBit(oldp+134,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__41__KET____DOT__bi__DOT__SecSig))));
        bufp->chgBit(oldp+135,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x29U] >> 6U))));
        bufp->chgBit(oldp+136,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x29U] >> 5U))));
        bufp->chgBit(oldp+137,((1U & (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__41__KET____DOT__bi__DOT__SecSig) 
                                       & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x29U] 
                                           >> 6U) | 
                                          (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x29U] 
                                           >> 5U))) 
                                      | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x29U] >> 6U) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x29U] 
                                            >> 5U))))));
        bufp->chgBit(oldp+138,((1U & ((((((~ (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__41__KET____DOT__bi__DOT__SecSig)) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x29U] 
                                                >> 6U))) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x29U] 
                                            >> 5U)) 
                                        | (((~ (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__41__KET____DOT__bi__DOT__SecSig)) 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                               [0x29U] 
                                               >> 6U)) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x29U] 
                                                 >> 5U)))) 
                                       | (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__41__KET____DOT__bi__DOT__SecSig) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x29U] 
                                                 >> 6U))) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x29U] 
                                                >> 5U)))) 
                                      | (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__41__KET____DOT__bi__DOT__SecSig) 
                                          & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [0x29U] 
                                             >> 6U)) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x29U] 
                                            >> 5U))))));
        bufp->chgBit(oldp+139,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__41__KET____DOT__bi__DOT__SecSig) 
                                      >> 3U))));
        bufp->chgBit(oldp+140,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__41__KET____DOT__bi__DOT__SecSig) 
                                      >> 2U))));
        bufp->chgBit(oldp+141,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__41__KET____DOT__bi__DOT__SecSig) 
                                      >> 1U))));
        bufp->chgBit(oldp+142,((1U & ((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__41__KET____DOT__bi__DOT__SecSig) 
                                        >> 3U) & (IData)(
                                                         (0U 
                                                          != 
                                                          (6U 
                                                           & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__41__KET____DOT__bi__DOT__SecSig))))) 
                                      | (IData)((6U 
                                                 == 
                                                 (6U 
                                                  & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__41__KET____DOT__bi__DOT__SecSig))))))));
        bufp->chgBit(oldp+143,((1U & ((((IData)((2U 
                                                 == 
                                                 (0xeU 
                                                  & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__41__KET____DOT__bi__DOT__SecSig)))) 
                                        | (IData)((4U 
                                                   == 
                                                   (0xeU 
                                                    & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__41__KET____DOT__bi__DOT__SecSig))))) 
                                       | (IData)((8U 
                                                  == 
                                                  (0xeU 
                                                   & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__41__KET____DOT__bi__DOT__SecSig))))) 
                                      | (IData)((0xeU 
                                                 == 
                                                 (0xeU 
                                                  & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__41__KET____DOT__bi__DOT__SecSig))))))));
        bufp->chgSData(oldp+144,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                 [0x2aU]),14);
        bufp->chgSData(oldp+145,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellout__wallacefor__BRA__42__KET____DOT__bi__COut),14);
        bufp->chgBit(oldp+146,((1U & (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__42__KET____DOT__bi__DOT__FifSig) 
                                       & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x2aU] 
                                           >> 0xdU) 
                                          | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [0x2aU] 
                                             >> 0xcU))) 
                                      | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x2aU] >> 0xdU) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x2aU] 
                                            >> 0xcU))))));
        bufp->chgBit(oldp+147,((1U & ((((((~ (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__42__KET____DOT__bi__DOT__FifSig)) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x2aU] 
                                                >> 0xdU))) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x2aU] 
                                            >> 0xcU)) 
                                        | (((~ (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__42__KET____DOT__bi__DOT__FifSig)) 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                               [0x2aU] 
                                               >> 0xdU)) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x2aU] 
                                                 >> 0xcU)))) 
                                       | (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__42__KET____DOT__bi__DOT__FifSig) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x2aU] 
                                                 >> 0xdU))) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x2aU] 
                                                >> 0xcU)))) 
                                      | (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__42__KET____DOT__bi__DOT__FifSig) 
                                          & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [0x2aU] 
                                             >> 0xdU)) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x2aU] 
                                            >> 0xcU))))));
        bufp->chgCData(oldp+148,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__42__KET____DOT__bi__DOT__SecSig),4);
        bufp->chgBit(oldp+149,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x2aU] >> 0xbU))));
        bufp->chgBit(oldp+150,((1U & ((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__42__KET____DOT__bi__DOT__ForSig) 
                                        >> 1U) & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__42__KET____DOT__bi__DOT__ForSig) 
                                                  | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                     [0x2aU] 
                                                     >> 0xbU))) 
                                      | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__42__KET____DOT__bi__DOT__ForSig) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x2aU] 
                                            >> 0xbU))))));
        bufp->chgBit(oldp+151,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x2aU] >> 9U))));
        bufp->chgBit(oldp+152,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x2aU] >> 8U))));
        bufp->chgBit(oldp+153,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x2aU] >> 7U))));
        bufp->chgBit(oldp+154,((1U & (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                        [0x2aU] >> 9U) 
                                       & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x2aU] 
                                           >> 8U) | 
                                          (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x2aU] 
                                           >> 7U))) 
                                      | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x2aU] >> 8U) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x2aU] 
                                            >> 7U))))));
        bufp->chgBit(oldp+155,((1U & ((((((~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                              [0x2aU] 
                                              >> 9U)) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x2aU] 
                                                >> 8U))) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x2aU] 
                                            >> 7U)) 
                                        | (((~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x2aU] 
                                                >> 9U)) 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                               [0x2aU] 
                                               >> 8U)) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x2aU] 
                                                 >> 7U)))) 
                                       | (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x2aU] 
                                            >> 9U) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x2aU] 
                                                 >> 8U))) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x2aU] 
                                                >> 7U)))) 
                                      | (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x2aU] 
                                           >> 9U) & 
                                          (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x2aU] 
                                           >> 8U)) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x2aU] 
                                            >> 7U))))));
        bufp->chgBit(oldp+156,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x2aU] >> 0xaU))));
        bufp->chgBit(oldp+157,((1U & ((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__42__KET____DOT__bi__DOT__ThiSig) 
                                        >> 1U) & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__42__KET____DOT__bi__DOT__ThiSig) 
                                                  | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                     [0x2aU] 
                                                     >> 0xaU))) 
                                      | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__42__KET____DOT__bi__DOT__ThiSig) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x2aU] 
                                            >> 0xaU))))));
        bufp->chgBit(oldp+158,((1U & (((((IData)((0U 
                                                  == (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__42__KET____DOT__bi__DOT__ThiSig))) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x2aU] 
                                            >> 0xaU)) 
                                        | ((IData)(
                                                   (1U 
                                                    == (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__42__KET____DOT__bi__DOT__ThiSig))) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x2aU] 
                                                 >> 0xaU)))) 
                                       | ((IData)((2U 
                                                   == (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__42__KET____DOT__bi__DOT__ThiSig))) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x2aU] 
                                                >> 0xaU)))) 
                                      | ((IData)((3U 
                                                  == (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__42__KET____DOT__bi__DOT__ThiSig))) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x2aU] 
                                            >> 0xaU))))));
        bufp->chgBit(oldp+159,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x2aU] >> 2U))));
        bufp->chgBit(oldp+160,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x2aU] >> 1U))));
        bufp->chgBit(oldp+161,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                [0x2aU])));
        bufp->chgBit(oldp+162,((1U & (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                        [0x2aU] >> 2U) 
                                       & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x2aU] 
                                           >> 1U) | 
                                          vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x2aU])) 
                                      | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x2aU] >> 1U) 
                                         & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x2aU])))));
        bufp->chgBit(oldp+163,((1U & ((((((~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                              [0x2aU] 
                                              >> 2U)) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x2aU] 
                                                >> 1U))) 
                                         & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x2aU]) | 
                                        (((~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                              [0x2aU] 
                                              >> 2U)) 
                                          & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [0x2aU] 
                                             >> 1U)) 
                                         & (~ vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x2aU]))) 
                                       | (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x2aU] 
                                            >> 2U) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x2aU] 
                                                 >> 1U))) 
                                          & (~ vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [0x2aU]))) 
                                      | (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x2aU] 
                                           >> 2U) & 
                                          (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x2aU] 
                                           >> 1U)) 
                                         & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x2aU])))));
        bufp->chgBit(oldp+164,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x2aU] >> 4U))));
        bufp->chgBit(oldp+165,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x2aU] >> 3U))));
        bufp->chgBit(oldp+166,((1U & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__42__KET____DOT__bi__InData 
                                       & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x2aU] 
                                           >> 4U) | 
                                          (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x2aU] 
                                           >> 3U))) 
                                      | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x2aU] >> 4U) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x2aU] 
                                            >> 3U))))));
        bufp->chgBit(oldp+167,((1U & ((((((~ vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__42__KET____DOT__bi__InData) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x2aU] 
                                                >> 4U))) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x2aU] 
                                            >> 3U)) 
                                        | (((~ vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__42__KET____DOT__bi__InData) 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                               [0x2aU] 
                                               >> 4U)) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x2aU] 
                                                 >> 3U)))) 
                                       | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__42__KET____DOT__bi__InData 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x2aU] 
                                                 >> 4U))) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x2aU] 
                                                >> 3U)))) 
                                      | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__42__KET____DOT__bi__InData 
                                          & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [0x2aU] 
                                             >> 4U)) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x2aU] 
                                            >> 3U))))));
        bufp->chgBit(oldp+168,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x2aU] >> 0xdU))));
        bufp->chgBit(oldp+169,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x2aU] >> 0xcU))));
        bufp->chgBit(oldp+170,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__42__KET____DOT__bi__DOT__SecSig))));
        bufp->chgBit(oldp+171,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x2aU] >> 6U))));
        bufp->chgBit(oldp+172,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x2aU] >> 5U))));
        bufp->chgBit(oldp+173,((1U & (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__42__KET____DOT__bi__DOT__SecSig) 
                                       & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x2aU] 
                                           >> 6U) | 
                                          (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x2aU] 
                                           >> 5U))) 
                                      | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x2aU] >> 6U) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x2aU] 
                                            >> 5U))))));
        bufp->chgBit(oldp+174,((1U & ((((((~ (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__42__KET____DOT__bi__DOT__SecSig)) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x2aU] 
                                                >> 6U))) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x2aU] 
                                            >> 5U)) 
                                        | (((~ (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__42__KET____DOT__bi__DOT__SecSig)) 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                               [0x2aU] 
                                               >> 6U)) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x2aU] 
                                                 >> 5U)))) 
                                       | (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__42__KET____DOT__bi__DOT__SecSig) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x2aU] 
                                                 >> 6U))) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x2aU] 
                                                >> 5U)))) 
                                      | (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__42__KET____DOT__bi__DOT__SecSig) 
                                          & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [0x2aU] 
                                             >> 6U)) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x2aU] 
                                            >> 5U))))));
        bufp->chgBit(oldp+175,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__42__KET____DOT__bi__DOT__SecSig) 
                                      >> 3U))));
        bufp->chgBit(oldp+176,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__42__KET____DOT__bi__DOT__SecSig) 
                                      >> 2U))));
        bufp->chgBit(oldp+177,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__42__KET____DOT__bi__DOT__SecSig) 
                                      >> 1U))));
        bufp->chgBit(oldp+178,((1U & ((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__42__KET____DOT__bi__DOT__SecSig) 
                                        >> 3U) & (IData)(
                                                         (0U 
                                                          != 
                                                          (6U 
                                                           & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__42__KET____DOT__bi__DOT__SecSig))))) 
                                      | (IData)((6U 
                                                 == 
                                                 (6U 
                                                  & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__42__KET____DOT__bi__DOT__SecSig))))))));
        bufp->chgBit(oldp+179,((1U & ((((IData)((2U 
                                                 == 
                                                 (0xeU 
                                                  & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__42__KET____DOT__bi__DOT__SecSig)))) 
                                        | (IData)((4U 
                                                   == 
                                                   (0xeU 
                                                    & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__42__KET____DOT__bi__DOT__SecSig))))) 
                                       | (IData)((8U 
                                                  == 
                                                  (0xeU 
                                                   & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__42__KET____DOT__bi__DOT__SecSig))))) 
                                      | (IData)((0xeU 
                                                 == 
                                                 (0xeU 
                                                  & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__42__KET____DOT__bi__DOT__SecSig))))))));
        bufp->chgSData(oldp+180,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                 [0x2bU]),14);
        bufp->chgSData(oldp+181,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellout__wallacefor__BRA__43__KET____DOT__bi__COut),14);
        bufp->chgBit(oldp+182,((1U & (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__43__KET____DOT__bi__DOT__FifSig) 
                                       & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x2bU] 
                                           >> 0xdU) 
                                          | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [0x2bU] 
                                             >> 0xcU))) 
                                      | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x2bU] >> 0xdU) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x2bU] 
                                            >> 0xcU))))));
        bufp->chgBit(oldp+183,((1U & ((((((~ (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__43__KET____DOT__bi__DOT__FifSig)) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x2bU] 
                                                >> 0xdU))) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x2bU] 
                                            >> 0xcU)) 
                                        | (((~ (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__43__KET____DOT__bi__DOT__FifSig)) 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                               [0x2bU] 
                                               >> 0xdU)) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x2bU] 
                                                 >> 0xcU)))) 
                                       | (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__43__KET____DOT__bi__DOT__FifSig) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x2bU] 
                                                 >> 0xdU))) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x2bU] 
                                                >> 0xcU)))) 
                                      | (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__43__KET____DOT__bi__DOT__FifSig) 
                                          & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [0x2bU] 
                                             >> 0xdU)) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x2bU] 
                                            >> 0xcU))))));
        bufp->chgCData(oldp+184,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__43__KET____DOT__bi__DOT__SecSig),4);
        bufp->chgBit(oldp+185,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x2bU] >> 0xbU))));
        bufp->chgBit(oldp+186,((1U & ((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__43__KET____DOT__bi__DOT__ForSig) 
                                        >> 1U) & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__43__KET____DOT__bi__DOT__ForSig) 
                                                  | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                     [0x2bU] 
                                                     >> 0xbU))) 
                                      | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__43__KET____DOT__bi__DOT__ForSig) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x2bU] 
                                            >> 0xbU))))));
        bufp->chgBit(oldp+187,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x2bU] >> 9U))));
        bufp->chgBit(oldp+188,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x2bU] >> 8U))));
        bufp->chgBit(oldp+189,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x2bU] >> 7U))));
        bufp->chgBit(oldp+190,((1U & (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                        [0x2bU] >> 9U) 
                                       & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x2bU] 
                                           >> 8U) | 
                                          (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x2bU] 
                                           >> 7U))) 
                                      | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x2bU] >> 8U) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x2bU] 
                                            >> 7U))))));
        bufp->chgBit(oldp+191,((1U & ((((((~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                              [0x2bU] 
                                              >> 9U)) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x2bU] 
                                                >> 8U))) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x2bU] 
                                            >> 7U)) 
                                        | (((~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x2bU] 
                                                >> 9U)) 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                               [0x2bU] 
                                               >> 8U)) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x2bU] 
                                                 >> 7U)))) 
                                       | (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x2bU] 
                                            >> 9U) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x2bU] 
                                                 >> 8U))) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x2bU] 
                                                >> 7U)))) 
                                      | (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x2bU] 
                                           >> 9U) & 
                                          (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x2bU] 
                                           >> 8U)) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x2bU] 
                                            >> 7U))))));
        bufp->chgBit(oldp+192,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x2bU] >> 0xaU))));
        bufp->chgBit(oldp+193,((1U & ((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__43__KET____DOT__bi__DOT__ThiSig) 
                                        >> 1U) & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__43__KET____DOT__bi__DOT__ThiSig) 
                                                  | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                     [0x2bU] 
                                                     >> 0xaU))) 
                                      | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__43__KET____DOT__bi__DOT__ThiSig) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x2bU] 
                                            >> 0xaU))))));
        bufp->chgBit(oldp+194,((1U & (((((IData)((0U 
                                                  == (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__43__KET____DOT__bi__DOT__ThiSig))) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x2bU] 
                                            >> 0xaU)) 
                                        | ((IData)(
                                                   (1U 
                                                    == (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__43__KET____DOT__bi__DOT__ThiSig))) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x2bU] 
                                                 >> 0xaU)))) 
                                       | ((IData)((2U 
                                                   == (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__43__KET____DOT__bi__DOT__ThiSig))) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x2bU] 
                                                >> 0xaU)))) 
                                      | ((IData)((3U 
                                                  == (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__43__KET____DOT__bi__DOT__ThiSig))) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x2bU] 
                                            >> 0xaU))))));
        bufp->chgBit(oldp+195,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x2bU] >> 2U))));
        bufp->chgBit(oldp+196,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x2bU] >> 1U))));
        bufp->chgBit(oldp+197,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                [0x2bU])));
        bufp->chgBit(oldp+198,((1U & (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                        [0x2bU] >> 2U) 
                                       & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x2bU] 
                                           >> 1U) | 
                                          vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x2bU])) 
                                      | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x2bU] >> 1U) 
                                         & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x2bU])))));
        bufp->chgBit(oldp+199,((1U & ((((((~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                              [0x2bU] 
                                              >> 2U)) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x2bU] 
                                                >> 1U))) 
                                         & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x2bU]) | 
                                        (((~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                              [0x2bU] 
                                              >> 2U)) 
                                          & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [0x2bU] 
                                             >> 1U)) 
                                         & (~ vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x2bU]))) 
                                       | (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x2bU] 
                                            >> 2U) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x2bU] 
                                                 >> 1U))) 
                                          & (~ vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [0x2bU]))) 
                                      | (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x2bU] 
                                           >> 2U) & 
                                          (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x2bU] 
                                           >> 1U)) 
                                         & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x2bU])))));
        bufp->chgBit(oldp+200,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x2bU] >> 4U))));
        bufp->chgBit(oldp+201,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x2bU] >> 3U))));
        bufp->chgBit(oldp+202,((1U & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__43__KET____DOT__bi__InData 
                                       & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x2bU] 
                                           >> 4U) | 
                                          (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x2bU] 
                                           >> 3U))) 
                                      | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x2bU] >> 4U) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x2bU] 
                                            >> 3U))))));
        bufp->chgBit(oldp+203,((1U & ((((((~ vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__43__KET____DOT__bi__InData) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x2bU] 
                                                >> 4U))) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x2bU] 
                                            >> 3U)) 
                                        | (((~ vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__43__KET____DOT__bi__InData) 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                               [0x2bU] 
                                               >> 4U)) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x2bU] 
                                                 >> 3U)))) 
                                       | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__43__KET____DOT__bi__InData 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x2bU] 
                                                 >> 4U))) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x2bU] 
                                                >> 3U)))) 
                                      | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__43__KET____DOT__bi__InData 
                                          & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [0x2bU] 
                                             >> 4U)) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x2bU] 
                                            >> 3U))))));
        bufp->chgBit(oldp+204,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x2bU] >> 0xdU))));
        bufp->chgBit(oldp+205,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x2bU] >> 0xcU))));
        bufp->chgBit(oldp+206,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__43__KET____DOT__bi__DOT__SecSig))));
        bufp->chgBit(oldp+207,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x2bU] >> 6U))));
        bufp->chgBit(oldp+208,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x2bU] >> 5U))));
        bufp->chgBit(oldp+209,((1U & (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__43__KET____DOT__bi__DOT__SecSig) 
                                       & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x2bU] 
                                           >> 6U) | 
                                          (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x2bU] 
                                           >> 5U))) 
                                      | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x2bU] >> 6U) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x2bU] 
                                            >> 5U))))));
        bufp->chgBit(oldp+210,((1U & ((((((~ (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__43__KET____DOT__bi__DOT__SecSig)) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x2bU] 
                                                >> 6U))) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x2bU] 
                                            >> 5U)) 
                                        | (((~ (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__43__KET____DOT__bi__DOT__SecSig)) 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                               [0x2bU] 
                                               >> 6U)) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x2bU] 
                                                 >> 5U)))) 
                                       | (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__43__KET____DOT__bi__DOT__SecSig) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x2bU] 
                                                 >> 6U))) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x2bU] 
                                                >> 5U)))) 
                                      | (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__43__KET____DOT__bi__DOT__SecSig) 
                                          & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [0x2bU] 
                                             >> 6U)) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x2bU] 
                                            >> 5U))))));
        bufp->chgBit(oldp+211,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__43__KET____DOT__bi__DOT__SecSig) 
                                      >> 3U))));
        bufp->chgBit(oldp+212,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__43__KET____DOT__bi__DOT__SecSig) 
                                      >> 2U))));
        bufp->chgBit(oldp+213,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__43__KET____DOT__bi__DOT__SecSig) 
                                      >> 1U))));
        bufp->chgBit(oldp+214,((1U & ((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__43__KET____DOT__bi__DOT__SecSig) 
                                        >> 3U) & (IData)(
                                                         (0U 
                                                          != 
                                                          (6U 
                                                           & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__43__KET____DOT__bi__DOT__SecSig))))) 
                                      | (IData)((6U 
                                                 == 
                                                 (6U 
                                                  & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__43__KET____DOT__bi__DOT__SecSig))))))));
        bufp->chgBit(oldp+215,((1U & ((((IData)((2U 
                                                 == 
                                                 (0xeU 
                                                  & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__43__KET____DOT__bi__DOT__SecSig)))) 
                                        | (IData)((4U 
                                                   == 
                                                   (0xeU 
                                                    & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__43__KET____DOT__bi__DOT__SecSig))))) 
                                       | (IData)((8U 
                                                  == 
                                                  (0xeU 
                                                   & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__43__KET____DOT__bi__DOT__SecSig))))) 
                                      | (IData)((0xeU 
                                                 == 
                                                 (0xeU 
                                                  & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__43__KET____DOT__bi__DOT__SecSig))))))));
        bufp->chgSData(oldp+216,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                 [0x2cU]),14);
        bufp->chgSData(oldp+217,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellout__wallacefor__BRA__44__KET____DOT__bi__COut),14);
        bufp->chgBit(oldp+218,((1U & (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__44__KET____DOT__bi__DOT__FifSig) 
                                       & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x2cU] 
                                           >> 0xdU) 
                                          | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [0x2cU] 
                                             >> 0xcU))) 
                                      | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x2cU] >> 0xdU) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x2cU] 
                                            >> 0xcU))))));
        bufp->chgBit(oldp+219,((1U & ((((((~ (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__44__KET____DOT__bi__DOT__FifSig)) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x2cU] 
                                                >> 0xdU))) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x2cU] 
                                            >> 0xcU)) 
                                        | (((~ (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__44__KET____DOT__bi__DOT__FifSig)) 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                               [0x2cU] 
                                               >> 0xdU)) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x2cU] 
                                                 >> 0xcU)))) 
                                       | (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__44__KET____DOT__bi__DOT__FifSig) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x2cU] 
                                                 >> 0xdU))) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x2cU] 
                                                >> 0xcU)))) 
                                      | (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__44__KET____DOT__bi__DOT__FifSig) 
                                          & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [0x2cU] 
                                             >> 0xdU)) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x2cU] 
                                            >> 0xcU))))));
        bufp->chgCData(oldp+220,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__44__KET____DOT__bi__DOT__SecSig),4);
        bufp->chgBit(oldp+221,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x2cU] >> 0xbU))));
        bufp->chgBit(oldp+222,((1U & ((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__44__KET____DOT__bi__DOT__ForSig) 
                                        >> 1U) & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__44__KET____DOT__bi__DOT__ForSig) 
                                                  | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                     [0x2cU] 
                                                     >> 0xbU))) 
                                      | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__44__KET____DOT__bi__DOT__ForSig) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x2cU] 
                                            >> 0xbU))))));
        bufp->chgBit(oldp+223,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x2cU] >> 9U))));
        bufp->chgBit(oldp+224,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x2cU] >> 8U))));
        bufp->chgBit(oldp+225,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x2cU] >> 7U))));
        bufp->chgBit(oldp+226,((1U & (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                        [0x2cU] >> 9U) 
                                       & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x2cU] 
                                           >> 8U) | 
                                          (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x2cU] 
                                           >> 7U))) 
                                      | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x2cU] >> 8U) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x2cU] 
                                            >> 7U))))));
        bufp->chgBit(oldp+227,((1U & ((((((~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                              [0x2cU] 
                                              >> 9U)) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x2cU] 
                                                >> 8U))) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x2cU] 
                                            >> 7U)) 
                                        | (((~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x2cU] 
                                                >> 9U)) 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                               [0x2cU] 
                                               >> 8U)) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x2cU] 
                                                 >> 7U)))) 
                                       | (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x2cU] 
                                            >> 9U) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x2cU] 
                                                 >> 8U))) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x2cU] 
                                                >> 7U)))) 
                                      | (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x2cU] 
                                           >> 9U) & 
                                          (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x2cU] 
                                           >> 8U)) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x2cU] 
                                            >> 7U))))));
        bufp->chgBit(oldp+228,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x2cU] >> 0xaU))));
        bufp->chgBit(oldp+229,((1U & ((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__44__KET____DOT__bi__DOT__ThiSig) 
                                        >> 1U) & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__44__KET____DOT__bi__DOT__ThiSig) 
                                                  | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                     [0x2cU] 
                                                     >> 0xaU))) 
                                      | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__44__KET____DOT__bi__DOT__ThiSig) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x2cU] 
                                            >> 0xaU))))));
        bufp->chgBit(oldp+230,((1U & (((((IData)((0U 
                                                  == (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__44__KET____DOT__bi__DOT__ThiSig))) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x2cU] 
                                            >> 0xaU)) 
                                        | ((IData)(
                                                   (1U 
                                                    == (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__44__KET____DOT__bi__DOT__ThiSig))) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x2cU] 
                                                 >> 0xaU)))) 
                                       | ((IData)((2U 
                                                   == (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__44__KET____DOT__bi__DOT__ThiSig))) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x2cU] 
                                                >> 0xaU)))) 
                                      | ((IData)((3U 
                                                  == (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__44__KET____DOT__bi__DOT__ThiSig))) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x2cU] 
                                            >> 0xaU))))));
        bufp->chgBit(oldp+231,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x2cU] >> 2U))));
        bufp->chgBit(oldp+232,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x2cU] >> 1U))));
        bufp->chgBit(oldp+233,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                [0x2cU])));
        bufp->chgBit(oldp+234,((1U & (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                        [0x2cU] >> 2U) 
                                       & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x2cU] 
                                           >> 1U) | 
                                          vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x2cU])) 
                                      | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x2cU] >> 1U) 
                                         & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x2cU])))));
        bufp->chgBit(oldp+235,((1U & ((((((~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                              [0x2cU] 
                                              >> 2U)) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x2cU] 
                                                >> 1U))) 
                                         & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x2cU]) | 
                                        (((~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                              [0x2cU] 
                                              >> 2U)) 
                                          & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [0x2cU] 
                                             >> 1U)) 
                                         & (~ vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x2cU]))) 
                                       | (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x2cU] 
                                            >> 2U) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x2cU] 
                                                 >> 1U))) 
                                          & (~ vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [0x2cU]))) 
                                      | (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x2cU] 
                                           >> 2U) & 
                                          (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x2cU] 
                                           >> 1U)) 
                                         & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x2cU])))));
        bufp->chgBit(oldp+236,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x2cU] >> 4U))));
        bufp->chgBit(oldp+237,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x2cU] >> 3U))));
        bufp->chgBit(oldp+238,((1U & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__44__KET____DOT__bi__InData 
                                       & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x2cU] 
                                           >> 4U) | 
                                          (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x2cU] 
                                           >> 3U))) 
                                      | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x2cU] >> 4U) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x2cU] 
                                            >> 3U))))));
        bufp->chgBit(oldp+239,((1U & ((((((~ vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__44__KET____DOT__bi__InData) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x2cU] 
                                                >> 4U))) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x2cU] 
                                            >> 3U)) 
                                        | (((~ vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__44__KET____DOT__bi__InData) 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                               [0x2cU] 
                                               >> 4U)) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x2cU] 
                                                 >> 3U)))) 
                                       | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__44__KET____DOT__bi__InData 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x2cU] 
                                                 >> 4U))) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x2cU] 
                                                >> 3U)))) 
                                      | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__44__KET____DOT__bi__InData 
                                          & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [0x2cU] 
                                             >> 4U)) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x2cU] 
                                            >> 3U))))));
        bufp->chgBit(oldp+240,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x2cU] >> 0xdU))));
        bufp->chgBit(oldp+241,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x2cU] >> 0xcU))));
        bufp->chgBit(oldp+242,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__44__KET____DOT__bi__DOT__SecSig))));
        bufp->chgBit(oldp+243,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x2cU] >> 6U))));
        bufp->chgBit(oldp+244,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x2cU] >> 5U))));
        bufp->chgBit(oldp+245,((1U & (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__44__KET____DOT__bi__DOT__SecSig) 
                                       & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x2cU] 
                                           >> 6U) | 
                                          (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x2cU] 
                                           >> 5U))) 
                                      | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x2cU] >> 6U) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x2cU] 
                                            >> 5U))))));
        bufp->chgBit(oldp+246,((1U & ((((((~ (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__44__KET____DOT__bi__DOT__SecSig)) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x2cU] 
                                                >> 6U))) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x2cU] 
                                            >> 5U)) 
                                        | (((~ (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__44__KET____DOT__bi__DOT__SecSig)) 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                               [0x2cU] 
                                               >> 6U)) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x2cU] 
                                                 >> 5U)))) 
                                       | (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__44__KET____DOT__bi__DOT__SecSig) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x2cU] 
                                                 >> 6U))) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x2cU] 
                                                >> 5U)))) 
                                      | (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__44__KET____DOT__bi__DOT__SecSig) 
                                          & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [0x2cU] 
                                             >> 6U)) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x2cU] 
                                            >> 5U))))));
        bufp->chgBit(oldp+247,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__44__KET____DOT__bi__DOT__SecSig) 
                                      >> 3U))));
        bufp->chgBit(oldp+248,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__44__KET____DOT__bi__DOT__SecSig) 
                                      >> 2U))));
        bufp->chgBit(oldp+249,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__44__KET____DOT__bi__DOT__SecSig) 
                                      >> 1U))));
        bufp->chgBit(oldp+250,((1U & ((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__44__KET____DOT__bi__DOT__SecSig) 
                                        >> 3U) & (IData)(
                                                         (0U 
                                                          != 
                                                          (6U 
                                                           & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__44__KET____DOT__bi__DOT__SecSig))))) 
                                      | (IData)((6U 
                                                 == 
                                                 (6U 
                                                  & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__44__KET____DOT__bi__DOT__SecSig))))))));
        bufp->chgBit(oldp+251,((1U & ((((IData)((2U 
                                                 == 
                                                 (0xeU 
                                                  & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__44__KET____DOT__bi__DOT__SecSig)))) 
                                        | (IData)((4U 
                                                   == 
                                                   (0xeU 
                                                    & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__44__KET____DOT__bi__DOT__SecSig))))) 
                                       | (IData)((8U 
                                                  == 
                                                  (0xeU 
                                                   & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__44__KET____DOT__bi__DOT__SecSig))))) 
                                      | (IData)((0xeU 
                                                 == 
                                                 (0xeU 
                                                  & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__44__KET____DOT__bi__DOT__SecSig))))))));
        bufp->chgSData(oldp+252,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                 [0x2dU]),14);
        bufp->chgSData(oldp+253,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellout__wallacefor__BRA__45__KET____DOT__bi__COut),14);
        bufp->chgBit(oldp+254,((1U & (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__45__KET____DOT__bi__DOT__FifSig) 
                                       & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x2dU] 
                                           >> 0xdU) 
                                          | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [0x2dU] 
                                             >> 0xcU))) 
                                      | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x2dU] >> 0xdU) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x2dU] 
                                            >> 0xcU))))));
        bufp->chgBit(oldp+255,((1U & ((((((~ (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__45__KET____DOT__bi__DOT__FifSig)) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x2dU] 
                                                >> 0xdU))) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x2dU] 
                                            >> 0xcU)) 
                                        | (((~ (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__45__KET____DOT__bi__DOT__FifSig)) 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                               [0x2dU] 
                                               >> 0xdU)) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x2dU] 
                                                 >> 0xcU)))) 
                                       | (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__45__KET____DOT__bi__DOT__FifSig) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x2dU] 
                                                 >> 0xdU))) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x2dU] 
                                                >> 0xcU)))) 
                                      | (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__45__KET____DOT__bi__DOT__FifSig) 
                                          & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [0x2dU] 
                                             >> 0xdU)) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x2dU] 
                                            >> 0xcU))))));
        bufp->chgCData(oldp+256,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__45__KET____DOT__bi__DOT__SecSig),4);
        bufp->chgBit(oldp+257,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x2dU] >> 0xbU))));
        bufp->chgBit(oldp+258,((1U & ((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__45__KET____DOT__bi__DOT__ForSig) 
                                        >> 1U) & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__45__KET____DOT__bi__DOT__ForSig) 
                                                  | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                     [0x2dU] 
                                                     >> 0xbU))) 
                                      | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__45__KET____DOT__bi__DOT__ForSig) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x2dU] 
                                            >> 0xbU))))));
        bufp->chgBit(oldp+259,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x2dU] >> 9U))));
        bufp->chgBit(oldp+260,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x2dU] >> 8U))));
        bufp->chgBit(oldp+261,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x2dU] >> 7U))));
        bufp->chgBit(oldp+262,((1U & (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                        [0x2dU] >> 9U) 
                                       & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x2dU] 
                                           >> 8U) | 
                                          (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x2dU] 
                                           >> 7U))) 
                                      | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x2dU] >> 8U) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x2dU] 
                                            >> 7U))))));
        bufp->chgBit(oldp+263,((1U & ((((((~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                              [0x2dU] 
                                              >> 9U)) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x2dU] 
                                                >> 8U))) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x2dU] 
                                            >> 7U)) 
                                        | (((~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x2dU] 
                                                >> 9U)) 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                               [0x2dU] 
                                               >> 8U)) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x2dU] 
                                                 >> 7U)))) 
                                       | (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x2dU] 
                                            >> 9U) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x2dU] 
                                                 >> 8U))) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x2dU] 
                                                >> 7U)))) 
                                      | (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x2dU] 
                                           >> 9U) & 
                                          (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x2dU] 
                                           >> 8U)) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x2dU] 
                                            >> 7U))))));
        bufp->chgBit(oldp+264,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x2dU] >> 0xaU))));
        bufp->chgBit(oldp+265,((1U & ((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__45__KET____DOT__bi__DOT__ThiSig) 
                                        >> 1U) & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__45__KET____DOT__bi__DOT__ThiSig) 
                                                  | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                     [0x2dU] 
                                                     >> 0xaU))) 
                                      | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__45__KET____DOT__bi__DOT__ThiSig) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x2dU] 
                                            >> 0xaU))))));
        bufp->chgBit(oldp+266,((1U & (((((IData)((0U 
                                                  == (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__45__KET____DOT__bi__DOT__ThiSig))) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x2dU] 
                                            >> 0xaU)) 
                                        | ((IData)(
                                                   (1U 
                                                    == (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__45__KET____DOT__bi__DOT__ThiSig))) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x2dU] 
                                                 >> 0xaU)))) 
                                       | ((IData)((2U 
                                                   == (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__45__KET____DOT__bi__DOT__ThiSig))) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x2dU] 
                                                >> 0xaU)))) 
                                      | ((IData)((3U 
                                                  == (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__45__KET____DOT__bi__DOT__ThiSig))) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x2dU] 
                                            >> 0xaU))))));
        bufp->chgBit(oldp+267,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x2dU] >> 2U))));
        bufp->chgBit(oldp+268,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x2dU] >> 1U))));
        bufp->chgBit(oldp+269,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                [0x2dU])));
        bufp->chgBit(oldp+270,((1U & (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                        [0x2dU] >> 2U) 
                                       & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x2dU] 
                                           >> 1U) | 
                                          vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x2dU])) 
                                      | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x2dU] >> 1U) 
                                         & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x2dU])))));
        bufp->chgBit(oldp+271,((1U & ((((((~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                              [0x2dU] 
                                              >> 2U)) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x2dU] 
                                                >> 1U))) 
                                         & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x2dU]) | 
                                        (((~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                              [0x2dU] 
                                              >> 2U)) 
                                          & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [0x2dU] 
                                             >> 1U)) 
                                         & (~ vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x2dU]))) 
                                       | (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x2dU] 
                                            >> 2U) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x2dU] 
                                                 >> 1U))) 
                                          & (~ vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [0x2dU]))) 
                                      | (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x2dU] 
                                           >> 2U) & 
                                          (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x2dU] 
                                           >> 1U)) 
                                         & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x2dU])))));
        bufp->chgBit(oldp+272,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x2dU] >> 4U))));
        bufp->chgBit(oldp+273,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x2dU] >> 3U))));
        bufp->chgBit(oldp+274,((1U & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__45__KET____DOT__bi__InData 
                                       & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x2dU] 
                                           >> 4U) | 
                                          (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x2dU] 
                                           >> 3U))) 
                                      | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x2dU] >> 4U) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x2dU] 
                                            >> 3U))))));
        bufp->chgBit(oldp+275,((1U & ((((((~ vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__45__KET____DOT__bi__InData) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x2dU] 
                                                >> 4U))) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x2dU] 
                                            >> 3U)) 
                                        | (((~ vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__45__KET____DOT__bi__InData) 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                               [0x2dU] 
                                               >> 4U)) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x2dU] 
                                                 >> 3U)))) 
                                       | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__45__KET____DOT__bi__InData 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x2dU] 
                                                 >> 4U))) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x2dU] 
                                                >> 3U)))) 
                                      | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__45__KET____DOT__bi__InData 
                                          & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [0x2dU] 
                                             >> 4U)) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x2dU] 
                                            >> 3U))))));
        bufp->chgBit(oldp+276,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x2dU] >> 0xdU))));
        bufp->chgBit(oldp+277,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x2dU] >> 0xcU))));
        bufp->chgBit(oldp+278,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__45__KET____DOT__bi__DOT__SecSig))));
        bufp->chgBit(oldp+279,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x2dU] >> 6U))));
        bufp->chgBit(oldp+280,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x2dU] >> 5U))));
        bufp->chgBit(oldp+281,((1U & (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__45__KET____DOT__bi__DOT__SecSig) 
                                       & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x2dU] 
                                           >> 6U) | 
                                          (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x2dU] 
                                           >> 5U))) 
                                      | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x2dU] >> 6U) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x2dU] 
                                            >> 5U))))));
        bufp->chgBit(oldp+282,((1U & ((((((~ (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__45__KET____DOT__bi__DOT__SecSig)) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x2dU] 
                                                >> 6U))) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x2dU] 
                                            >> 5U)) 
                                        | (((~ (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__45__KET____DOT__bi__DOT__SecSig)) 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                               [0x2dU] 
                                               >> 6U)) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x2dU] 
                                                 >> 5U)))) 
                                       | (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__45__KET____DOT__bi__DOT__SecSig) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x2dU] 
                                                 >> 6U))) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x2dU] 
                                                >> 5U)))) 
                                      | (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__45__KET____DOT__bi__DOT__SecSig) 
                                          & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [0x2dU] 
                                             >> 6U)) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x2dU] 
                                            >> 5U))))));
        bufp->chgBit(oldp+283,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__45__KET____DOT__bi__DOT__SecSig) 
                                      >> 3U))));
        bufp->chgBit(oldp+284,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__45__KET____DOT__bi__DOT__SecSig) 
                                      >> 2U))));
        bufp->chgBit(oldp+285,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__45__KET____DOT__bi__DOT__SecSig) 
                                      >> 1U))));
        bufp->chgBit(oldp+286,((1U & ((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__45__KET____DOT__bi__DOT__SecSig) 
                                        >> 3U) & (IData)(
                                                         (0U 
                                                          != 
                                                          (6U 
                                                           & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__45__KET____DOT__bi__DOT__SecSig))))) 
                                      | (IData)((6U 
                                                 == 
                                                 (6U 
                                                  & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__45__KET____DOT__bi__DOT__SecSig))))))));
        bufp->chgBit(oldp+287,((1U & ((((IData)((2U 
                                                 == 
                                                 (0xeU 
                                                  & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__45__KET____DOT__bi__DOT__SecSig)))) 
                                        | (IData)((4U 
                                                   == 
                                                   (0xeU 
                                                    & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__45__KET____DOT__bi__DOT__SecSig))))) 
                                       | (IData)((8U 
                                                  == 
                                                  (0xeU 
                                                   & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__45__KET____DOT__bi__DOT__SecSig))))) 
                                      | (IData)((0xeU 
                                                 == 
                                                 (0xeU 
                                                  & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__45__KET____DOT__bi__DOT__SecSig))))))));
        bufp->chgSData(oldp+288,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                 [0x2eU]),14);
        bufp->chgSData(oldp+289,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellout__wallacefor__BRA__46__KET____DOT__bi__COut),14);
        bufp->chgBit(oldp+290,((1U & (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__46__KET____DOT__bi__DOT__FifSig) 
                                       & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x2eU] 
                                           >> 0xdU) 
                                          | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [0x2eU] 
                                             >> 0xcU))) 
                                      | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x2eU] >> 0xdU) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x2eU] 
                                            >> 0xcU))))));
        bufp->chgBit(oldp+291,((1U & ((((((~ (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__46__KET____DOT__bi__DOT__FifSig)) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x2eU] 
                                                >> 0xdU))) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x2eU] 
                                            >> 0xcU)) 
                                        | (((~ (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__46__KET____DOT__bi__DOT__FifSig)) 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                               [0x2eU] 
                                               >> 0xdU)) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x2eU] 
                                                 >> 0xcU)))) 
                                       | (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__46__KET____DOT__bi__DOT__FifSig) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x2eU] 
                                                 >> 0xdU))) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x2eU] 
                                                >> 0xcU)))) 
                                      | (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__46__KET____DOT__bi__DOT__FifSig) 
                                          & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [0x2eU] 
                                             >> 0xdU)) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x2eU] 
                                            >> 0xcU))))));
        bufp->chgCData(oldp+292,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__46__KET____DOT__bi__DOT__SecSig),4);
        bufp->chgBit(oldp+293,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x2eU] >> 0xbU))));
        bufp->chgBit(oldp+294,((1U & ((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__46__KET____DOT__bi__DOT__ForSig) 
                                        >> 1U) & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__46__KET____DOT__bi__DOT__ForSig) 
                                                  | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                     [0x2eU] 
                                                     >> 0xbU))) 
                                      | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__46__KET____DOT__bi__DOT__ForSig) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x2eU] 
                                            >> 0xbU))))));
        bufp->chgBit(oldp+295,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x2eU] >> 9U))));
        bufp->chgBit(oldp+296,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x2eU] >> 8U))));
        bufp->chgBit(oldp+297,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x2eU] >> 7U))));
        bufp->chgBit(oldp+298,((1U & (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                        [0x2eU] >> 9U) 
                                       & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x2eU] 
                                           >> 8U) | 
                                          (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x2eU] 
                                           >> 7U))) 
                                      | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x2eU] >> 8U) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x2eU] 
                                            >> 7U))))));
        bufp->chgBit(oldp+299,((1U & ((((((~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                              [0x2eU] 
                                              >> 9U)) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x2eU] 
                                                >> 8U))) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x2eU] 
                                            >> 7U)) 
                                        | (((~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x2eU] 
                                                >> 9U)) 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                               [0x2eU] 
                                               >> 8U)) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x2eU] 
                                                 >> 7U)))) 
                                       | (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x2eU] 
                                            >> 9U) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x2eU] 
                                                 >> 8U))) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x2eU] 
                                                >> 7U)))) 
                                      | (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x2eU] 
                                           >> 9U) & 
                                          (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x2eU] 
                                           >> 8U)) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x2eU] 
                                            >> 7U))))));
        bufp->chgBit(oldp+300,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x2eU] >> 0xaU))));
        bufp->chgBit(oldp+301,((1U & ((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__46__KET____DOT__bi__DOT__ThiSig) 
                                        >> 1U) & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__46__KET____DOT__bi__DOT__ThiSig) 
                                                  | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                     [0x2eU] 
                                                     >> 0xaU))) 
                                      | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__46__KET____DOT__bi__DOT__ThiSig) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x2eU] 
                                            >> 0xaU))))));
        bufp->chgBit(oldp+302,((1U & (((((IData)((0U 
                                                  == (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__46__KET____DOT__bi__DOT__ThiSig))) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x2eU] 
                                            >> 0xaU)) 
                                        | ((IData)(
                                                   (1U 
                                                    == (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__46__KET____DOT__bi__DOT__ThiSig))) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x2eU] 
                                                 >> 0xaU)))) 
                                       | ((IData)((2U 
                                                   == (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__46__KET____DOT__bi__DOT__ThiSig))) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x2eU] 
                                                >> 0xaU)))) 
                                      | ((IData)((3U 
                                                  == (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__46__KET____DOT__bi__DOT__ThiSig))) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x2eU] 
                                            >> 0xaU))))));
        bufp->chgBit(oldp+303,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x2eU] >> 2U))));
        bufp->chgBit(oldp+304,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x2eU] >> 1U))));
        bufp->chgBit(oldp+305,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                [0x2eU])));
        bufp->chgBit(oldp+306,((1U & (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                        [0x2eU] >> 2U) 
                                       & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x2eU] 
                                           >> 1U) | 
                                          vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x2eU])) 
                                      | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x2eU] >> 1U) 
                                         & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x2eU])))));
        bufp->chgBit(oldp+307,((1U & ((((((~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                              [0x2eU] 
                                              >> 2U)) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x2eU] 
                                                >> 1U))) 
                                         & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x2eU]) | 
                                        (((~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                              [0x2eU] 
                                              >> 2U)) 
                                          & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [0x2eU] 
                                             >> 1U)) 
                                         & (~ vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x2eU]))) 
                                       | (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x2eU] 
                                            >> 2U) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x2eU] 
                                                 >> 1U))) 
                                          & (~ vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [0x2eU]))) 
                                      | (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x2eU] 
                                           >> 2U) & 
                                          (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x2eU] 
                                           >> 1U)) 
                                         & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x2eU])))));
        bufp->chgBit(oldp+308,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x2eU] >> 4U))));
        bufp->chgBit(oldp+309,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x2eU] >> 3U))));
        bufp->chgBit(oldp+310,((1U & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__46__KET____DOT__bi__InData 
                                       & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x2eU] 
                                           >> 4U) | 
                                          (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x2eU] 
                                           >> 3U))) 
                                      | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x2eU] >> 4U) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x2eU] 
                                            >> 3U))))));
        bufp->chgBit(oldp+311,((1U & ((((((~ vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__46__KET____DOT__bi__InData) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x2eU] 
                                                >> 4U))) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x2eU] 
                                            >> 3U)) 
                                        | (((~ vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__46__KET____DOT__bi__InData) 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                               [0x2eU] 
                                               >> 4U)) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x2eU] 
                                                 >> 3U)))) 
                                       | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__46__KET____DOT__bi__InData 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x2eU] 
                                                 >> 4U))) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x2eU] 
                                                >> 3U)))) 
                                      | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__46__KET____DOT__bi__InData 
                                          & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [0x2eU] 
                                             >> 4U)) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x2eU] 
                                            >> 3U))))));
        bufp->chgBit(oldp+312,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x2eU] >> 0xdU))));
        bufp->chgBit(oldp+313,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x2eU] >> 0xcU))));
        bufp->chgBit(oldp+314,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__46__KET____DOT__bi__DOT__SecSig))));
        bufp->chgBit(oldp+315,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x2eU] >> 6U))));
        bufp->chgBit(oldp+316,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x2eU] >> 5U))));
        bufp->chgBit(oldp+317,((1U & (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__46__KET____DOT__bi__DOT__SecSig) 
                                       & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x2eU] 
                                           >> 6U) | 
                                          (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x2eU] 
                                           >> 5U))) 
                                      | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x2eU] >> 6U) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x2eU] 
                                            >> 5U))))));
        bufp->chgBit(oldp+318,((1U & ((((((~ (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__46__KET____DOT__bi__DOT__SecSig)) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x2eU] 
                                                >> 6U))) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x2eU] 
                                            >> 5U)) 
                                        | (((~ (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__46__KET____DOT__bi__DOT__SecSig)) 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                               [0x2eU] 
                                               >> 6U)) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x2eU] 
                                                 >> 5U)))) 
                                       | (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__46__KET____DOT__bi__DOT__SecSig) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x2eU] 
                                                 >> 6U))) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x2eU] 
                                                >> 5U)))) 
                                      | (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__46__KET____DOT__bi__DOT__SecSig) 
                                          & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [0x2eU] 
                                             >> 6U)) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x2eU] 
                                            >> 5U))))));
        bufp->chgBit(oldp+319,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__46__KET____DOT__bi__DOT__SecSig) 
                                      >> 3U))));
        bufp->chgBit(oldp+320,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__46__KET____DOT__bi__DOT__SecSig) 
                                      >> 2U))));
        bufp->chgBit(oldp+321,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__46__KET____DOT__bi__DOT__SecSig) 
                                      >> 1U))));
        bufp->chgBit(oldp+322,((1U & ((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__46__KET____DOT__bi__DOT__SecSig) 
                                        >> 3U) & (IData)(
                                                         (0U 
                                                          != 
                                                          (6U 
                                                           & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__46__KET____DOT__bi__DOT__SecSig))))) 
                                      | (IData)((6U 
                                                 == 
                                                 (6U 
                                                  & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__46__KET____DOT__bi__DOT__SecSig))))))));
        bufp->chgBit(oldp+323,((1U & ((((IData)((2U 
                                                 == 
                                                 (0xeU 
                                                  & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__46__KET____DOT__bi__DOT__SecSig)))) 
                                        | (IData)((4U 
                                                   == 
                                                   (0xeU 
                                                    & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__46__KET____DOT__bi__DOT__SecSig))))) 
                                       | (IData)((8U 
                                                  == 
                                                  (0xeU 
                                                   & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__46__KET____DOT__bi__DOT__SecSig))))) 
                                      | (IData)((0xeU 
                                                 == 
                                                 (0xeU 
                                                  & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__46__KET____DOT__bi__DOT__SecSig))))))));
        bufp->chgSData(oldp+324,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                 [0x2fU]),14);
        bufp->chgSData(oldp+325,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellout__wallacefor__BRA__47__KET____DOT__bi__COut),14);
        bufp->chgBit(oldp+326,((1U & (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__47__KET____DOT__bi__DOT__FifSig) 
                                       & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x2fU] 
                                           >> 0xdU) 
                                          | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [0x2fU] 
                                             >> 0xcU))) 
                                      | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x2fU] >> 0xdU) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x2fU] 
                                            >> 0xcU))))));
        bufp->chgBit(oldp+327,((1U & ((((((~ (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__47__KET____DOT__bi__DOT__FifSig)) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x2fU] 
                                                >> 0xdU))) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x2fU] 
                                            >> 0xcU)) 
                                        | (((~ (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__47__KET____DOT__bi__DOT__FifSig)) 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                               [0x2fU] 
                                               >> 0xdU)) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x2fU] 
                                                 >> 0xcU)))) 
                                       | (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__47__KET____DOT__bi__DOT__FifSig) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x2fU] 
                                                 >> 0xdU))) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x2fU] 
                                                >> 0xcU)))) 
                                      | (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__47__KET____DOT__bi__DOT__FifSig) 
                                          & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [0x2fU] 
                                             >> 0xdU)) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x2fU] 
                                            >> 0xcU))))));
        bufp->chgCData(oldp+328,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__47__KET____DOT__bi__DOT__SecSig),4);
        bufp->chgBit(oldp+329,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x2fU] >> 0xbU))));
        bufp->chgBit(oldp+330,((1U & ((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__47__KET____DOT__bi__DOT__ForSig) 
                                        >> 1U) & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__47__KET____DOT__bi__DOT__ForSig) 
                                                  | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                     [0x2fU] 
                                                     >> 0xbU))) 
                                      | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__47__KET____DOT__bi__DOT__ForSig) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x2fU] 
                                            >> 0xbU))))));
        bufp->chgBit(oldp+331,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x2fU] >> 9U))));
        bufp->chgBit(oldp+332,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x2fU] >> 8U))));
        bufp->chgBit(oldp+333,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x2fU] >> 7U))));
        bufp->chgBit(oldp+334,((1U & (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                        [0x2fU] >> 9U) 
                                       & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x2fU] 
                                           >> 8U) | 
                                          (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x2fU] 
                                           >> 7U))) 
                                      | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x2fU] >> 8U) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x2fU] 
                                            >> 7U))))));
        bufp->chgBit(oldp+335,((1U & ((((((~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                              [0x2fU] 
                                              >> 9U)) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x2fU] 
                                                >> 8U))) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x2fU] 
                                            >> 7U)) 
                                        | (((~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x2fU] 
                                                >> 9U)) 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                               [0x2fU] 
                                               >> 8U)) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x2fU] 
                                                 >> 7U)))) 
                                       | (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x2fU] 
                                            >> 9U) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x2fU] 
                                                 >> 8U))) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x2fU] 
                                                >> 7U)))) 
                                      | (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x2fU] 
                                           >> 9U) & 
                                          (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x2fU] 
                                           >> 8U)) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x2fU] 
                                            >> 7U))))));
        bufp->chgBit(oldp+336,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x2fU] >> 0xaU))));
        bufp->chgBit(oldp+337,((1U & ((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__47__KET____DOT__bi__DOT__ThiSig) 
                                        >> 1U) & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__47__KET____DOT__bi__DOT__ThiSig) 
                                                  | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                     [0x2fU] 
                                                     >> 0xaU))) 
                                      | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__47__KET____DOT__bi__DOT__ThiSig) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x2fU] 
                                            >> 0xaU))))));
        bufp->chgBit(oldp+338,((1U & (((((IData)((0U 
                                                  == (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__47__KET____DOT__bi__DOT__ThiSig))) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x2fU] 
                                            >> 0xaU)) 
                                        | ((IData)(
                                                   (1U 
                                                    == (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__47__KET____DOT__bi__DOT__ThiSig))) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x2fU] 
                                                 >> 0xaU)))) 
                                       | ((IData)((2U 
                                                   == (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__47__KET____DOT__bi__DOT__ThiSig))) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x2fU] 
                                                >> 0xaU)))) 
                                      | ((IData)((3U 
                                                  == (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__47__KET____DOT__bi__DOT__ThiSig))) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x2fU] 
                                            >> 0xaU))))));
        bufp->chgBit(oldp+339,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x2fU] >> 2U))));
        bufp->chgBit(oldp+340,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x2fU] >> 1U))));
        bufp->chgBit(oldp+341,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                [0x2fU])));
        bufp->chgBit(oldp+342,((1U & (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                        [0x2fU] >> 2U) 
                                       & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x2fU] 
                                           >> 1U) | 
                                          vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x2fU])) 
                                      | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x2fU] >> 1U) 
                                         & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x2fU])))));
        bufp->chgBit(oldp+343,((1U & ((((((~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                              [0x2fU] 
                                              >> 2U)) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x2fU] 
                                                >> 1U))) 
                                         & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x2fU]) | 
                                        (((~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                              [0x2fU] 
                                              >> 2U)) 
                                          & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [0x2fU] 
                                             >> 1U)) 
                                         & (~ vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x2fU]))) 
                                       | (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x2fU] 
                                            >> 2U) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x2fU] 
                                                 >> 1U))) 
                                          & (~ vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [0x2fU]))) 
                                      | (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x2fU] 
                                           >> 2U) & 
                                          (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x2fU] 
                                           >> 1U)) 
                                         & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x2fU])))));
        bufp->chgBit(oldp+344,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x2fU] >> 4U))));
        bufp->chgBit(oldp+345,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x2fU] >> 3U))));
        bufp->chgBit(oldp+346,((1U & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__47__KET____DOT__bi__InData 
                                       & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x2fU] 
                                           >> 4U) | 
                                          (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x2fU] 
                                           >> 3U))) 
                                      | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x2fU] >> 4U) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x2fU] 
                                            >> 3U))))));
        bufp->chgBit(oldp+347,((1U & ((((((~ vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__47__KET____DOT__bi__InData) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x2fU] 
                                                >> 4U))) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x2fU] 
                                            >> 3U)) 
                                        | (((~ vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__47__KET____DOT__bi__InData) 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                               [0x2fU] 
                                               >> 4U)) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x2fU] 
                                                 >> 3U)))) 
                                       | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__47__KET____DOT__bi__InData 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x2fU] 
                                                 >> 4U))) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x2fU] 
                                                >> 3U)))) 
                                      | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__47__KET____DOT__bi__InData 
                                          & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [0x2fU] 
                                             >> 4U)) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x2fU] 
                                            >> 3U))))));
        bufp->chgBit(oldp+348,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x2fU] >> 0xdU))));
        bufp->chgBit(oldp+349,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x2fU] >> 0xcU))));
        bufp->chgBit(oldp+350,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__47__KET____DOT__bi__DOT__SecSig))));
        bufp->chgBit(oldp+351,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x2fU] >> 6U))));
        bufp->chgBit(oldp+352,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x2fU] >> 5U))));
        bufp->chgBit(oldp+353,((1U & (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__47__KET____DOT__bi__DOT__SecSig) 
                                       & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x2fU] 
                                           >> 6U) | 
                                          (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x2fU] 
                                           >> 5U))) 
                                      | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x2fU] >> 6U) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x2fU] 
                                            >> 5U))))));
        bufp->chgBit(oldp+354,((1U & ((((((~ (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__47__KET____DOT__bi__DOT__SecSig)) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x2fU] 
                                                >> 6U))) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x2fU] 
                                            >> 5U)) 
                                        | (((~ (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__47__KET____DOT__bi__DOT__SecSig)) 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                               [0x2fU] 
                                               >> 6U)) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x2fU] 
                                                 >> 5U)))) 
                                       | (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__47__KET____DOT__bi__DOT__SecSig) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x2fU] 
                                                 >> 6U))) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x2fU] 
                                                >> 5U)))) 
                                      | (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__47__KET____DOT__bi__DOT__SecSig) 
                                          & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [0x2fU] 
                                             >> 6U)) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x2fU] 
                                            >> 5U))))));
        bufp->chgBit(oldp+355,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__47__KET____DOT__bi__DOT__SecSig) 
                                      >> 3U))));
        bufp->chgBit(oldp+356,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__47__KET____DOT__bi__DOT__SecSig) 
                                      >> 2U))));
        bufp->chgBit(oldp+357,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__47__KET____DOT__bi__DOT__SecSig) 
                                      >> 1U))));
        bufp->chgBit(oldp+358,((1U & ((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__47__KET____DOT__bi__DOT__SecSig) 
                                        >> 3U) & (IData)(
                                                         (0U 
                                                          != 
                                                          (6U 
                                                           & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__47__KET____DOT__bi__DOT__SecSig))))) 
                                      | (IData)((6U 
                                                 == 
                                                 (6U 
                                                  & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__47__KET____DOT__bi__DOT__SecSig))))))));
        bufp->chgBit(oldp+359,((1U & ((((IData)((2U 
                                                 == 
                                                 (0xeU 
                                                  & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__47__KET____DOT__bi__DOT__SecSig)))) 
                                        | (IData)((4U 
                                                   == 
                                                   (0xeU 
                                                    & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__47__KET____DOT__bi__DOT__SecSig))))) 
                                       | (IData)((8U 
                                                  == 
                                                  (0xeU 
                                                   & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__47__KET____DOT__bi__DOT__SecSig))))) 
                                      | (IData)((0xeU 
                                                 == 
                                                 (0xeU 
                                                  & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__47__KET____DOT__bi__DOT__SecSig))))))));
        bufp->chgSData(oldp+360,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                 [0x30U]),14);
        bufp->chgSData(oldp+361,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellout__wallacefor__BRA__48__KET____DOT__bi__COut),14);
        bufp->chgBit(oldp+362,((1U & (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__48__KET____DOT__bi__DOT__FifSig) 
                                       & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x30U] 
                                           >> 0xdU) 
                                          | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [0x30U] 
                                             >> 0xcU))) 
                                      | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x30U] >> 0xdU) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x30U] 
                                            >> 0xcU))))));
        bufp->chgBit(oldp+363,((1U & ((((((~ (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__48__KET____DOT__bi__DOT__FifSig)) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x30U] 
                                                >> 0xdU))) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x30U] 
                                            >> 0xcU)) 
                                        | (((~ (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__48__KET____DOT__bi__DOT__FifSig)) 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                               [0x30U] 
                                               >> 0xdU)) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x30U] 
                                                 >> 0xcU)))) 
                                       | (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__48__KET____DOT__bi__DOT__FifSig) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x30U] 
                                                 >> 0xdU))) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x30U] 
                                                >> 0xcU)))) 
                                      | (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__48__KET____DOT__bi__DOT__FifSig) 
                                          & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [0x30U] 
                                             >> 0xdU)) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x30U] 
                                            >> 0xcU))))));
        bufp->chgCData(oldp+364,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__48__KET____DOT__bi__DOT__SecSig),4);
        bufp->chgBit(oldp+365,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x30U] >> 0xbU))));
        bufp->chgBit(oldp+366,((1U & ((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__48__KET____DOT__bi__DOT__ForSig) 
                                        >> 1U) & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__48__KET____DOT__bi__DOT__ForSig) 
                                                  | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                     [0x30U] 
                                                     >> 0xbU))) 
                                      | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__48__KET____DOT__bi__DOT__ForSig) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x30U] 
                                            >> 0xbU))))));
        bufp->chgBit(oldp+367,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x30U] >> 9U))));
        bufp->chgBit(oldp+368,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x30U] >> 8U))));
        bufp->chgBit(oldp+369,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x30U] >> 7U))));
        bufp->chgBit(oldp+370,((1U & (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                        [0x30U] >> 9U) 
                                       & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x30U] 
                                           >> 8U) | 
                                          (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x30U] 
                                           >> 7U))) 
                                      | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x30U] >> 8U) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x30U] 
                                            >> 7U))))));
        bufp->chgBit(oldp+371,((1U & ((((((~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                              [0x30U] 
                                              >> 9U)) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x30U] 
                                                >> 8U))) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x30U] 
                                            >> 7U)) 
                                        | (((~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x30U] 
                                                >> 9U)) 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                               [0x30U] 
                                               >> 8U)) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x30U] 
                                                 >> 7U)))) 
                                       | (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x30U] 
                                            >> 9U) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x30U] 
                                                 >> 8U))) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x30U] 
                                                >> 7U)))) 
                                      | (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x30U] 
                                           >> 9U) & 
                                          (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x30U] 
                                           >> 8U)) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x30U] 
                                            >> 7U))))));
        bufp->chgBit(oldp+372,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x30U] >> 0xaU))));
        bufp->chgBit(oldp+373,((1U & ((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__48__KET____DOT__bi__DOT__ThiSig) 
                                        >> 1U) & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__48__KET____DOT__bi__DOT__ThiSig) 
                                                  | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                     [0x30U] 
                                                     >> 0xaU))) 
                                      | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__48__KET____DOT__bi__DOT__ThiSig) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x30U] 
                                            >> 0xaU))))));
        bufp->chgBit(oldp+374,((1U & (((((IData)((0U 
                                                  == (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__48__KET____DOT__bi__DOT__ThiSig))) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x30U] 
                                            >> 0xaU)) 
                                        | ((IData)(
                                                   (1U 
                                                    == (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__48__KET____DOT__bi__DOT__ThiSig))) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x30U] 
                                                 >> 0xaU)))) 
                                       | ((IData)((2U 
                                                   == (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__48__KET____DOT__bi__DOT__ThiSig))) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x30U] 
                                                >> 0xaU)))) 
                                      | ((IData)((3U 
                                                  == (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__48__KET____DOT__bi__DOT__ThiSig))) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x30U] 
                                            >> 0xaU))))));
        bufp->chgBit(oldp+375,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x30U] >> 2U))));
        bufp->chgBit(oldp+376,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x30U] >> 1U))));
        bufp->chgBit(oldp+377,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                [0x30U])));
        bufp->chgBit(oldp+378,((1U & (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                        [0x30U] >> 2U) 
                                       & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x30U] 
                                           >> 1U) | 
                                          vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x30U])) 
                                      | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x30U] >> 1U) 
                                         & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x30U])))));
        bufp->chgBit(oldp+379,((1U & ((((((~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                              [0x30U] 
                                              >> 2U)) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x30U] 
                                                >> 1U))) 
                                         & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x30U]) | 
                                        (((~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                              [0x30U] 
                                              >> 2U)) 
                                          & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [0x30U] 
                                             >> 1U)) 
                                         & (~ vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x30U]))) 
                                       | (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x30U] 
                                            >> 2U) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x30U] 
                                                 >> 1U))) 
                                          & (~ vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [0x30U]))) 
                                      | (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x30U] 
                                           >> 2U) & 
                                          (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x30U] 
                                           >> 1U)) 
                                         & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x30U])))));
        bufp->chgBit(oldp+380,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x30U] >> 4U))));
        bufp->chgBit(oldp+381,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x30U] >> 3U))));
        bufp->chgBit(oldp+382,((1U & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__48__KET____DOT__bi__InData 
                                       & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x30U] 
                                           >> 4U) | 
                                          (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x30U] 
                                           >> 3U))) 
                                      | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x30U] >> 4U) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x30U] 
                                            >> 3U))))));
        bufp->chgBit(oldp+383,((1U & ((((((~ vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__48__KET____DOT__bi__InData) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x30U] 
                                                >> 4U))) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x30U] 
                                            >> 3U)) 
                                        | (((~ vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__48__KET____DOT__bi__InData) 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                               [0x30U] 
                                               >> 4U)) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x30U] 
                                                 >> 3U)))) 
                                       | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__48__KET____DOT__bi__InData 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x30U] 
                                                 >> 4U))) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x30U] 
                                                >> 3U)))) 
                                      | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__48__KET____DOT__bi__InData 
                                          & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [0x30U] 
                                             >> 4U)) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x30U] 
                                            >> 3U))))));
        bufp->chgBit(oldp+384,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x30U] >> 0xdU))));
        bufp->chgBit(oldp+385,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x30U] >> 0xcU))));
        bufp->chgBit(oldp+386,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__48__KET____DOT__bi__DOT__SecSig))));
        bufp->chgBit(oldp+387,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x30U] >> 6U))));
        bufp->chgBit(oldp+388,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x30U] >> 5U))));
        bufp->chgBit(oldp+389,((1U & (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__48__KET____DOT__bi__DOT__SecSig) 
                                       & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x30U] 
                                           >> 6U) | 
                                          (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x30U] 
                                           >> 5U))) 
                                      | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x30U] >> 6U) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x30U] 
                                            >> 5U))))));
        bufp->chgBit(oldp+390,((1U & ((((((~ (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__48__KET____DOT__bi__DOT__SecSig)) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x30U] 
                                                >> 6U))) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x30U] 
                                            >> 5U)) 
                                        | (((~ (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__48__KET____DOT__bi__DOT__SecSig)) 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                               [0x30U] 
                                               >> 6U)) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x30U] 
                                                 >> 5U)))) 
                                       | (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__48__KET____DOT__bi__DOT__SecSig) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x30U] 
                                                 >> 6U))) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x30U] 
                                                >> 5U)))) 
                                      | (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__48__KET____DOT__bi__DOT__SecSig) 
                                          & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [0x30U] 
                                             >> 6U)) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x30U] 
                                            >> 5U))))));
        bufp->chgBit(oldp+391,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__48__KET____DOT__bi__DOT__SecSig) 
                                      >> 3U))));
        bufp->chgBit(oldp+392,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__48__KET____DOT__bi__DOT__SecSig) 
                                      >> 2U))));
        bufp->chgBit(oldp+393,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__48__KET____DOT__bi__DOT__SecSig) 
                                      >> 1U))));
        bufp->chgBit(oldp+394,((1U & ((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__48__KET____DOT__bi__DOT__SecSig) 
                                        >> 3U) & (IData)(
                                                         (0U 
                                                          != 
                                                          (6U 
                                                           & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__48__KET____DOT__bi__DOT__SecSig))))) 
                                      | (IData)((6U 
                                                 == 
                                                 (6U 
                                                  & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__48__KET____DOT__bi__DOT__SecSig))))))));
        bufp->chgBit(oldp+395,((1U & ((((IData)((2U 
                                                 == 
                                                 (0xeU 
                                                  & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__48__KET____DOT__bi__DOT__SecSig)))) 
                                        | (IData)((4U 
                                                   == 
                                                   (0xeU 
                                                    & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__48__KET____DOT__bi__DOT__SecSig))))) 
                                       | (IData)((8U 
                                                  == 
                                                  (0xeU 
                                                   & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__48__KET____DOT__bi__DOT__SecSig))))) 
                                      | (IData)((0xeU 
                                                 == 
                                                 (0xeU 
                                                  & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__48__KET____DOT__bi__DOT__SecSig))))))));
        bufp->chgSData(oldp+396,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                 [0x31U]),14);
        bufp->chgSData(oldp+397,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellout__wallacefor__BRA__49__KET____DOT__bi__COut),14);
        bufp->chgBit(oldp+398,((1U & (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__49__KET____DOT__bi__DOT__FifSig) 
                                       & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x31U] 
                                           >> 0xdU) 
                                          | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [0x31U] 
                                             >> 0xcU))) 
                                      | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x31U] >> 0xdU) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x31U] 
                                            >> 0xcU))))));
        bufp->chgBit(oldp+399,((1U & ((((((~ (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__49__KET____DOT__bi__DOT__FifSig)) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x31U] 
                                                >> 0xdU))) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x31U] 
                                            >> 0xcU)) 
                                        | (((~ (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__49__KET____DOT__bi__DOT__FifSig)) 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                               [0x31U] 
                                               >> 0xdU)) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x31U] 
                                                 >> 0xcU)))) 
                                       | (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__49__KET____DOT__bi__DOT__FifSig) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x31U] 
                                                 >> 0xdU))) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x31U] 
                                                >> 0xcU)))) 
                                      | (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__49__KET____DOT__bi__DOT__FifSig) 
                                          & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [0x31U] 
                                             >> 0xdU)) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x31U] 
                                            >> 0xcU))))));
        bufp->chgCData(oldp+400,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__49__KET____DOT__bi__DOT__SecSig),4);
        bufp->chgBit(oldp+401,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x31U] >> 0xbU))));
        bufp->chgBit(oldp+402,((1U & ((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__49__KET____DOT__bi__DOT__ForSig) 
                                        >> 1U) & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__49__KET____DOT__bi__DOT__ForSig) 
                                                  | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                     [0x31U] 
                                                     >> 0xbU))) 
                                      | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__49__KET____DOT__bi__DOT__ForSig) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x31U] 
                                            >> 0xbU))))));
        bufp->chgBit(oldp+403,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x31U] >> 9U))));
        bufp->chgBit(oldp+404,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x31U] >> 8U))));
        bufp->chgBit(oldp+405,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x31U] >> 7U))));
        bufp->chgBit(oldp+406,((1U & (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                        [0x31U] >> 9U) 
                                       & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x31U] 
                                           >> 8U) | 
                                          (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x31U] 
                                           >> 7U))) 
                                      | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x31U] >> 8U) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x31U] 
                                            >> 7U))))));
        bufp->chgBit(oldp+407,((1U & ((((((~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                              [0x31U] 
                                              >> 9U)) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x31U] 
                                                >> 8U))) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x31U] 
                                            >> 7U)) 
                                        | (((~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x31U] 
                                                >> 9U)) 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                               [0x31U] 
                                               >> 8U)) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x31U] 
                                                 >> 7U)))) 
                                       | (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x31U] 
                                            >> 9U) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x31U] 
                                                 >> 8U))) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x31U] 
                                                >> 7U)))) 
                                      | (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x31U] 
                                           >> 9U) & 
                                          (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x31U] 
                                           >> 8U)) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x31U] 
                                            >> 7U))))));
        bufp->chgBit(oldp+408,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x31U] >> 0xaU))));
        bufp->chgBit(oldp+409,((1U & ((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__49__KET____DOT__bi__DOT__ThiSig) 
                                        >> 1U) & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__49__KET____DOT__bi__DOT__ThiSig) 
                                                  | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                     [0x31U] 
                                                     >> 0xaU))) 
                                      | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__49__KET____DOT__bi__DOT__ThiSig) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x31U] 
                                            >> 0xaU))))));
        bufp->chgBit(oldp+410,((1U & (((((IData)((0U 
                                                  == (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__49__KET____DOT__bi__DOT__ThiSig))) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x31U] 
                                            >> 0xaU)) 
                                        | ((IData)(
                                                   (1U 
                                                    == (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__49__KET____DOT__bi__DOT__ThiSig))) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x31U] 
                                                 >> 0xaU)))) 
                                       | ((IData)((2U 
                                                   == (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__49__KET____DOT__bi__DOT__ThiSig))) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x31U] 
                                                >> 0xaU)))) 
                                      | ((IData)((3U 
                                                  == (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__49__KET____DOT__bi__DOT__ThiSig))) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x31U] 
                                            >> 0xaU))))));
        bufp->chgBit(oldp+411,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x31U] >> 2U))));
        bufp->chgBit(oldp+412,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x31U] >> 1U))));
        bufp->chgBit(oldp+413,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                [0x31U])));
        bufp->chgBit(oldp+414,((1U & (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                        [0x31U] >> 2U) 
                                       & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x31U] 
                                           >> 1U) | 
                                          vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x31U])) 
                                      | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x31U] >> 1U) 
                                         & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x31U])))));
        bufp->chgBit(oldp+415,((1U & ((((((~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                              [0x31U] 
                                              >> 2U)) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x31U] 
                                                >> 1U))) 
                                         & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x31U]) | 
                                        (((~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                              [0x31U] 
                                              >> 2U)) 
                                          & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [0x31U] 
                                             >> 1U)) 
                                         & (~ vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x31U]))) 
                                       | (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x31U] 
                                            >> 2U) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x31U] 
                                                 >> 1U))) 
                                          & (~ vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [0x31U]))) 
                                      | (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x31U] 
                                           >> 2U) & 
                                          (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x31U] 
                                           >> 1U)) 
                                         & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x31U])))));
        bufp->chgBit(oldp+416,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x31U] >> 4U))));
        bufp->chgBit(oldp+417,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x31U] >> 3U))));
        bufp->chgBit(oldp+418,((1U & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__49__KET____DOT__bi__InData 
                                       & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x31U] 
                                           >> 4U) | 
                                          (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x31U] 
                                           >> 3U))) 
                                      | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x31U] >> 4U) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x31U] 
                                            >> 3U))))));
        bufp->chgBit(oldp+419,((1U & ((((((~ vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__49__KET____DOT__bi__InData) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x31U] 
                                                >> 4U))) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x31U] 
                                            >> 3U)) 
                                        | (((~ vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__49__KET____DOT__bi__InData) 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                               [0x31U] 
                                               >> 4U)) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x31U] 
                                                 >> 3U)))) 
                                       | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__49__KET____DOT__bi__InData 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x31U] 
                                                 >> 4U))) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x31U] 
                                                >> 3U)))) 
                                      | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__49__KET____DOT__bi__InData 
                                          & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [0x31U] 
                                             >> 4U)) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x31U] 
                                            >> 3U))))));
        bufp->chgBit(oldp+420,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x31U] >> 0xdU))));
        bufp->chgBit(oldp+421,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x31U] >> 0xcU))));
        bufp->chgBit(oldp+422,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__49__KET____DOT__bi__DOT__SecSig))));
        bufp->chgBit(oldp+423,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x31U] >> 6U))));
        bufp->chgBit(oldp+424,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x31U] >> 5U))));
        bufp->chgBit(oldp+425,((1U & (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__49__KET____DOT__bi__DOT__SecSig) 
                                       & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x31U] 
                                           >> 6U) | 
                                          (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x31U] 
                                           >> 5U))) 
                                      | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x31U] >> 6U) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x31U] 
                                            >> 5U))))));
        bufp->chgBit(oldp+426,((1U & ((((((~ (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__49__KET____DOT__bi__DOT__SecSig)) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x31U] 
                                                >> 6U))) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x31U] 
                                            >> 5U)) 
                                        | (((~ (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__49__KET____DOT__bi__DOT__SecSig)) 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                               [0x31U] 
                                               >> 6U)) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x31U] 
                                                 >> 5U)))) 
                                       | (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__49__KET____DOT__bi__DOT__SecSig) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x31U] 
                                                 >> 6U))) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x31U] 
                                                >> 5U)))) 
                                      | (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__49__KET____DOT__bi__DOT__SecSig) 
                                          & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [0x31U] 
                                             >> 6U)) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x31U] 
                                            >> 5U))))));
        bufp->chgBit(oldp+427,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__49__KET____DOT__bi__DOT__SecSig) 
                                      >> 3U))));
        bufp->chgBit(oldp+428,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__49__KET____DOT__bi__DOT__SecSig) 
                                      >> 2U))));
        bufp->chgBit(oldp+429,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__49__KET____DOT__bi__DOT__SecSig) 
                                      >> 1U))));
        bufp->chgBit(oldp+430,((1U & ((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__49__KET____DOT__bi__DOT__SecSig) 
                                        >> 3U) & (IData)(
                                                         (0U 
                                                          != 
                                                          (6U 
                                                           & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__49__KET____DOT__bi__DOT__SecSig))))) 
                                      | (IData)((6U 
                                                 == 
                                                 (6U 
                                                  & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__49__KET____DOT__bi__DOT__SecSig))))))));
        bufp->chgBit(oldp+431,((1U & ((((IData)((2U 
                                                 == 
                                                 (0xeU 
                                                  & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__49__KET____DOT__bi__DOT__SecSig)))) 
                                        | (IData)((4U 
                                                   == 
                                                   (0xeU 
                                                    & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__49__KET____DOT__bi__DOT__SecSig))))) 
                                       | (IData)((8U 
                                                  == 
                                                  (0xeU 
                                                   & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__49__KET____DOT__bi__DOT__SecSig))))) 
                                      | (IData)((0xeU 
                                                 == 
                                                 (0xeU 
                                                  & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__49__KET____DOT__bi__DOT__SecSig))))))));
        bufp->chgSData(oldp+432,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                 [4U]),14);
        bufp->chgSData(oldp+433,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellout__wallacefor__BRA__4__KET____DOT__bi__COut),14);
        bufp->chgBit(oldp+434,((1U & (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__4__KET____DOT__bi__DOT__FifSig) 
                                       & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [4U] >> 0xdU) 
                                          | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [4U] >> 0xcU))) 
                                      | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [4U] >> 0xdU) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [4U] >> 0xcU))))));
        bufp->chgBit(oldp+435,((1U & ((((((~ (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__4__KET____DOT__bi__DOT__FifSig)) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [4U] 
                                                >> 0xdU))) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [4U] >> 0xcU)) 
                                        | (((~ (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__4__KET____DOT__bi__DOT__FifSig)) 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                               [4U] 
                                               >> 0xdU)) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [4U] 
                                                 >> 0xcU)))) 
                                       | (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__4__KET____DOT__bi__DOT__FifSig) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [4U] 
                                                 >> 0xdU))) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [4U] 
                                                >> 0xcU)))) 
                                      | (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__4__KET____DOT__bi__DOT__FifSig) 
                                          & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [4U] >> 0xdU)) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [4U] >> 0xcU))))));
        bufp->chgCData(oldp+436,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__4__KET____DOT__bi__DOT__SecSig),4);
        bufp->chgBit(oldp+437,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [4U] >> 0xbU))));
        bufp->chgBit(oldp+438,((1U & ((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__4__KET____DOT__bi__DOT__ForSig) 
                                        >> 1U) & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__4__KET____DOT__bi__DOT__ForSig) 
                                                  | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                     [4U] 
                                                     >> 0xbU))) 
                                      | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__4__KET____DOT__bi__DOT__ForSig) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [4U] >> 0xbU))))));
        bufp->chgBit(oldp+439,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [4U] >> 9U))));
        bufp->chgBit(oldp+440,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [4U] >> 8U))));
        bufp->chgBit(oldp+441,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [4U] >> 7U))));
        bufp->chgBit(oldp+442,((1U & (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                        [4U] >> 9U) 
                                       & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [4U] >> 8U) 
                                          | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [4U] >> 7U))) 
                                      | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [4U] >> 8U) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [4U] >> 7U))))));
        bufp->chgBit(oldp+443,((1U & ((((((~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                              [4U] 
                                              >> 9U)) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [4U] 
                                                >> 8U))) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [4U] >> 7U)) 
                                        | (((~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [4U] 
                                                >> 9U)) 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                               [4U] 
                                               >> 8U)) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [4U] 
                                                 >> 7U)))) 
                                       | (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [4U] >> 9U) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [4U] 
                                                 >> 8U))) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [4U] 
                                                >> 7U)))) 
                                      | (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [4U] >> 9U) 
                                          & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [4U] >> 8U)) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [4U] >> 7U))))));
        bufp->chgBit(oldp+444,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [4U] >> 0xaU))));
        bufp->chgBit(oldp+445,((1U & ((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__4__KET____DOT__bi__DOT__ThiSig) 
                                        >> 1U) & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__4__KET____DOT__bi__DOT__ThiSig) 
                                                  | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                     [4U] 
                                                     >> 0xaU))) 
                                      | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__4__KET____DOT__bi__DOT__ThiSig) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [4U] >> 0xaU))))));
        bufp->chgBit(oldp+446,((1U & (((((IData)((0U 
                                                  == (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__4__KET____DOT__bi__DOT__ThiSig))) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [4U] >> 0xaU)) 
                                        | ((IData)(
                                                   (1U 
                                                    == (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__4__KET____DOT__bi__DOT__ThiSig))) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [4U] 
                                                 >> 0xaU)))) 
                                       | ((IData)((2U 
                                                   == (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__4__KET____DOT__bi__DOT__ThiSig))) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [4U] 
                                                >> 0xaU)))) 
                                      | ((IData)((3U 
                                                  == (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__4__KET____DOT__bi__DOT__ThiSig))) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [4U] >> 0xaU))))));
        bufp->chgBit(oldp+447,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [4U] >> 2U))));
        bufp->chgBit(oldp+448,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [4U] >> 1U))));
        bufp->chgBit(oldp+449,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                [4U])));
        bufp->chgBit(oldp+450,((1U & (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                        [4U] >> 2U) 
                                       & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [4U] >> 1U) 
                                          | vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [4U])) | 
                                      ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                        [4U] >> 1U) 
                                       & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                       [4U])))));
        bufp->chgBit(oldp+451,((1U & ((((((~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                              [4U] 
                                              >> 2U)) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [4U] 
                                                >> 1U))) 
                                         & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [4U]) | ((
                                                   (~ 
                                                    (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                     [4U] 
                                                     >> 2U)) 
                                                   & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                      [4U] 
                                                      >> 1U)) 
                                                  & (~ 
                                                     vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                     [4U]))) 
                                       | (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [4U] >> 2U) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [4U] 
                                                 >> 1U))) 
                                          & (~ vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [4U]))) 
                                      | (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [4U] >> 2U) 
                                          & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [4U] >> 1U)) 
                                         & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [4U])))));
        bufp->chgBit(oldp+452,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [4U] >> 4U))));
        bufp->chgBit(oldp+453,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [4U] >> 3U))));
        bufp->chgBit(oldp+454,((1U & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__4__KET____DOT__bi__InData 
                                       & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [4U] >> 4U) 
                                          | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [4U] >> 3U))) 
                                      | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [4U] >> 4U) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [4U] >> 3U))))));
        bufp->chgBit(oldp+455,((1U & ((((((~ vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__4__KET____DOT__bi__InData) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [4U] 
                                                >> 4U))) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [4U] >> 3U)) 
                                        | (((~ vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__4__KET____DOT__bi__InData) 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                               [4U] 
                                               >> 4U)) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [4U] 
                                                 >> 3U)))) 
                                       | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__4__KET____DOT__bi__InData 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [4U] 
                                                 >> 4U))) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [4U] 
                                                >> 3U)))) 
                                      | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__4__KET____DOT__bi__InData 
                                          & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [4U] >> 4U)) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [4U] >> 3U))))));
        bufp->chgBit(oldp+456,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [4U] >> 0xdU))));
        bufp->chgBit(oldp+457,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [4U] >> 0xcU))));
        bufp->chgBit(oldp+458,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__4__KET____DOT__bi__DOT__SecSig))));
        bufp->chgBit(oldp+459,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [4U] >> 6U))));
        bufp->chgBit(oldp+460,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [4U] >> 5U))));
        bufp->chgBit(oldp+461,((1U & (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__4__KET____DOT__bi__DOT__SecSig) 
                                       & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [4U] >> 6U) 
                                          | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [4U] >> 5U))) 
                                      | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [4U] >> 6U) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [4U] >> 5U))))));
        bufp->chgBit(oldp+462,((1U & ((((((~ (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__4__KET____DOT__bi__DOT__SecSig)) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [4U] 
                                                >> 6U))) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [4U] >> 5U)) 
                                        | (((~ (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__4__KET____DOT__bi__DOT__SecSig)) 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                               [4U] 
                                               >> 6U)) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [4U] 
                                                 >> 5U)))) 
                                       | (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__4__KET____DOT__bi__DOT__SecSig) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [4U] 
                                                 >> 6U))) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [4U] 
                                                >> 5U)))) 
                                      | (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__4__KET____DOT__bi__DOT__SecSig) 
                                          & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [4U] >> 6U)) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [4U] >> 5U))))));
        bufp->chgBit(oldp+463,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__4__KET____DOT__bi__DOT__SecSig) 
                                      >> 3U))));
        bufp->chgBit(oldp+464,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__4__KET____DOT__bi__DOT__SecSig) 
                                      >> 2U))));
        bufp->chgBit(oldp+465,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__4__KET____DOT__bi__DOT__SecSig) 
                                      >> 1U))));
        bufp->chgBit(oldp+466,((1U & ((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__4__KET____DOT__bi__DOT__SecSig) 
                                        >> 3U) & (IData)(
                                                         (0U 
                                                          != 
                                                          (6U 
                                                           & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__4__KET____DOT__bi__DOT__SecSig))))) 
                                      | (IData)((6U 
                                                 == 
                                                 (6U 
                                                  & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__4__KET____DOT__bi__DOT__SecSig))))))));
        bufp->chgBit(oldp+467,((1U & ((((IData)((2U 
                                                 == 
                                                 (0xeU 
                                                  & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__4__KET____DOT__bi__DOT__SecSig)))) 
                                        | (IData)((4U 
                                                   == 
                                                   (0xeU 
                                                    & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__4__KET____DOT__bi__DOT__SecSig))))) 
                                       | (IData)((8U 
                                                  == 
                                                  (0xeU 
                                                   & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__4__KET____DOT__bi__DOT__SecSig))))) 
                                      | (IData)((0xeU 
                                                 == 
                                                 (0xeU 
                                                  & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__4__KET____DOT__bi__DOT__SecSig))))))));
        bufp->chgSData(oldp+468,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                 [0x32U]),14);
        bufp->chgSData(oldp+469,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellout__wallacefor__BRA__50__KET____DOT__bi__COut),14);
        bufp->chgBit(oldp+470,((1U & (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__50__KET____DOT__bi__DOT__FifSig) 
                                       & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x32U] 
                                           >> 0xdU) 
                                          | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [0x32U] 
                                             >> 0xcU))) 
                                      | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x32U] >> 0xdU) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x32U] 
                                            >> 0xcU))))));
        bufp->chgBit(oldp+471,((1U & ((((((~ (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__50__KET____DOT__bi__DOT__FifSig)) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x32U] 
                                                >> 0xdU))) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x32U] 
                                            >> 0xcU)) 
                                        | (((~ (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__50__KET____DOT__bi__DOT__FifSig)) 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                               [0x32U] 
                                               >> 0xdU)) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x32U] 
                                                 >> 0xcU)))) 
                                       | (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__50__KET____DOT__bi__DOT__FifSig) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x32U] 
                                                 >> 0xdU))) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x32U] 
                                                >> 0xcU)))) 
                                      | (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__50__KET____DOT__bi__DOT__FifSig) 
                                          & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [0x32U] 
                                             >> 0xdU)) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x32U] 
                                            >> 0xcU))))));
        bufp->chgCData(oldp+472,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__50__KET____DOT__bi__DOT__SecSig),4);
        bufp->chgBit(oldp+473,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x32U] >> 0xbU))));
        bufp->chgBit(oldp+474,((1U & ((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__50__KET____DOT__bi__DOT__ForSig) 
                                        >> 1U) & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__50__KET____DOT__bi__DOT__ForSig) 
                                                  | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                     [0x32U] 
                                                     >> 0xbU))) 
                                      | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__50__KET____DOT__bi__DOT__ForSig) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x32U] 
                                            >> 0xbU))))));
        bufp->chgBit(oldp+475,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x32U] >> 9U))));
        bufp->chgBit(oldp+476,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x32U] >> 8U))));
        bufp->chgBit(oldp+477,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x32U] >> 7U))));
        bufp->chgBit(oldp+478,((1U & (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                        [0x32U] >> 9U) 
                                       & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x32U] 
                                           >> 8U) | 
                                          (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x32U] 
                                           >> 7U))) 
                                      | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x32U] >> 8U) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x32U] 
                                            >> 7U))))));
        bufp->chgBit(oldp+479,((1U & ((((((~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                              [0x32U] 
                                              >> 9U)) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x32U] 
                                                >> 8U))) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x32U] 
                                            >> 7U)) 
                                        | (((~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x32U] 
                                                >> 9U)) 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                               [0x32U] 
                                               >> 8U)) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x32U] 
                                                 >> 7U)))) 
                                       | (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x32U] 
                                            >> 9U) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x32U] 
                                                 >> 8U))) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x32U] 
                                                >> 7U)))) 
                                      | (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x32U] 
                                           >> 9U) & 
                                          (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x32U] 
                                           >> 8U)) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x32U] 
                                            >> 7U))))));
        bufp->chgBit(oldp+480,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x32U] >> 0xaU))));
        bufp->chgBit(oldp+481,((1U & ((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__50__KET____DOT__bi__DOT__ThiSig) 
                                        >> 1U) & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__50__KET____DOT__bi__DOT__ThiSig) 
                                                  | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                     [0x32U] 
                                                     >> 0xaU))) 
                                      | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__50__KET____DOT__bi__DOT__ThiSig) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x32U] 
                                            >> 0xaU))))));
        bufp->chgBit(oldp+482,((1U & (((((IData)((0U 
                                                  == (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__50__KET____DOT__bi__DOT__ThiSig))) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x32U] 
                                            >> 0xaU)) 
                                        | ((IData)(
                                                   (1U 
                                                    == (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__50__KET____DOT__bi__DOT__ThiSig))) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x32U] 
                                                 >> 0xaU)))) 
                                       | ((IData)((2U 
                                                   == (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__50__KET____DOT__bi__DOT__ThiSig))) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x32U] 
                                                >> 0xaU)))) 
                                      | ((IData)((3U 
                                                  == (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__50__KET____DOT__bi__DOT__ThiSig))) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x32U] 
                                            >> 0xaU))))));
        bufp->chgBit(oldp+483,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x32U] >> 2U))));
        bufp->chgBit(oldp+484,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x32U] >> 1U))));
        bufp->chgBit(oldp+485,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                [0x32U])));
        bufp->chgBit(oldp+486,((1U & (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                        [0x32U] >> 2U) 
                                       & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x32U] 
                                           >> 1U) | 
                                          vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x32U])) 
                                      | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x32U] >> 1U) 
                                         & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x32U])))));
        bufp->chgBit(oldp+487,((1U & ((((((~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                              [0x32U] 
                                              >> 2U)) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x32U] 
                                                >> 1U))) 
                                         & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x32U]) | 
                                        (((~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                              [0x32U] 
                                              >> 2U)) 
                                          & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [0x32U] 
                                             >> 1U)) 
                                         & (~ vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x32U]))) 
                                       | (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x32U] 
                                            >> 2U) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x32U] 
                                                 >> 1U))) 
                                          & (~ vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [0x32U]))) 
                                      | (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x32U] 
                                           >> 2U) & 
                                          (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x32U] 
                                           >> 1U)) 
                                         & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x32U])))));
        bufp->chgBit(oldp+488,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x32U] >> 4U))));
        bufp->chgBit(oldp+489,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x32U] >> 3U))));
        bufp->chgBit(oldp+490,((1U & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__50__KET____DOT__bi__InData 
                                       & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x32U] 
                                           >> 4U) | 
                                          (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x32U] 
                                           >> 3U))) 
                                      | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x32U] >> 4U) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x32U] 
                                            >> 3U))))));
        bufp->chgBit(oldp+491,((1U & ((((((~ vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__50__KET____DOT__bi__InData) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x32U] 
                                                >> 4U))) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x32U] 
                                            >> 3U)) 
                                        | (((~ vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__50__KET____DOT__bi__InData) 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                               [0x32U] 
                                               >> 4U)) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x32U] 
                                                 >> 3U)))) 
                                       | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__50__KET____DOT__bi__InData 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x32U] 
                                                 >> 4U))) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x32U] 
                                                >> 3U)))) 
                                      | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__50__KET____DOT__bi__InData 
                                          & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [0x32U] 
                                             >> 4U)) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x32U] 
                                            >> 3U))))));
        bufp->chgBit(oldp+492,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x32U] >> 0xdU))));
        bufp->chgBit(oldp+493,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x32U] >> 0xcU))));
        bufp->chgBit(oldp+494,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__50__KET____DOT__bi__DOT__SecSig))));
        bufp->chgBit(oldp+495,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x32U] >> 6U))));
        bufp->chgBit(oldp+496,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x32U] >> 5U))));
        bufp->chgBit(oldp+497,((1U & (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__50__KET____DOT__bi__DOT__SecSig) 
                                       & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x32U] 
                                           >> 6U) | 
                                          (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x32U] 
                                           >> 5U))) 
                                      | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x32U] >> 6U) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x32U] 
                                            >> 5U))))));
        bufp->chgBit(oldp+498,((1U & ((((((~ (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__50__KET____DOT__bi__DOT__SecSig)) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x32U] 
                                                >> 6U))) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x32U] 
                                            >> 5U)) 
                                        | (((~ (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__50__KET____DOT__bi__DOT__SecSig)) 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                               [0x32U] 
                                               >> 6U)) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x32U] 
                                                 >> 5U)))) 
                                       | (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__50__KET____DOT__bi__DOT__SecSig) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x32U] 
                                                 >> 6U))) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x32U] 
                                                >> 5U)))) 
                                      | (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__50__KET____DOT__bi__DOT__SecSig) 
                                          & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [0x32U] 
                                             >> 6U)) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x32U] 
                                            >> 5U))))));
        bufp->chgBit(oldp+499,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__50__KET____DOT__bi__DOT__SecSig) 
                                      >> 3U))));
        bufp->chgBit(oldp+500,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__50__KET____DOT__bi__DOT__SecSig) 
                                      >> 2U))));
        bufp->chgBit(oldp+501,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__50__KET____DOT__bi__DOT__SecSig) 
                                      >> 1U))));
        bufp->chgBit(oldp+502,((1U & ((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__50__KET____DOT__bi__DOT__SecSig) 
                                        >> 3U) & (IData)(
                                                         (0U 
                                                          != 
                                                          (6U 
                                                           & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__50__KET____DOT__bi__DOT__SecSig))))) 
                                      | (IData)((6U 
                                                 == 
                                                 (6U 
                                                  & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__50__KET____DOT__bi__DOT__SecSig))))))));
        bufp->chgBit(oldp+503,((1U & ((((IData)((2U 
                                                 == 
                                                 (0xeU 
                                                  & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__50__KET____DOT__bi__DOT__SecSig)))) 
                                        | (IData)((4U 
                                                   == 
                                                   (0xeU 
                                                    & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__50__KET____DOT__bi__DOT__SecSig))))) 
                                       | (IData)((8U 
                                                  == 
                                                  (0xeU 
                                                   & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__50__KET____DOT__bi__DOT__SecSig))))) 
                                      | (IData)((0xeU 
                                                 == 
                                                 (0xeU 
                                                  & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__50__KET____DOT__bi__DOT__SecSig))))))));
        bufp->chgSData(oldp+504,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                 [0x33U]),14);
        bufp->chgSData(oldp+505,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellout__wallacefor__BRA__51__KET____DOT__bi__COut),14);
        bufp->chgBit(oldp+506,((1U & (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__51__KET____DOT__bi__DOT__FifSig) 
                                       & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x33U] 
                                           >> 0xdU) 
                                          | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [0x33U] 
                                             >> 0xcU))) 
                                      | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x33U] >> 0xdU) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x33U] 
                                            >> 0xcU))))));
        bufp->chgBit(oldp+507,((1U & ((((((~ (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__51__KET____DOT__bi__DOT__FifSig)) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x33U] 
                                                >> 0xdU))) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x33U] 
                                            >> 0xcU)) 
                                        | (((~ (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__51__KET____DOT__bi__DOT__FifSig)) 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                               [0x33U] 
                                               >> 0xdU)) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x33U] 
                                                 >> 0xcU)))) 
                                       | (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__51__KET____DOT__bi__DOT__FifSig) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x33U] 
                                                 >> 0xdU))) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x33U] 
                                                >> 0xcU)))) 
                                      | (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__51__KET____DOT__bi__DOT__FifSig) 
                                          & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [0x33U] 
                                             >> 0xdU)) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x33U] 
                                            >> 0xcU))))));
        bufp->chgCData(oldp+508,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__51__KET____DOT__bi__DOT__SecSig),4);
        bufp->chgBit(oldp+509,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x33U] >> 0xbU))));
        bufp->chgBit(oldp+510,((1U & ((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__51__KET____DOT__bi__DOT__ForSig) 
                                        >> 1U) & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__51__KET____DOT__bi__DOT__ForSig) 
                                                  | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                     [0x33U] 
                                                     >> 0xbU))) 
                                      | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__51__KET____DOT__bi__DOT__ForSig) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x33U] 
                                            >> 0xbU))))));
        bufp->chgBit(oldp+511,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x33U] >> 9U))));
        bufp->chgBit(oldp+512,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x33U] >> 8U))));
        bufp->chgBit(oldp+513,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x33U] >> 7U))));
        bufp->chgBit(oldp+514,((1U & (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                        [0x33U] >> 9U) 
                                       & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x33U] 
                                           >> 8U) | 
                                          (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x33U] 
                                           >> 7U))) 
                                      | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x33U] >> 8U) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x33U] 
                                            >> 7U))))));
        bufp->chgBit(oldp+515,((1U & ((((((~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                              [0x33U] 
                                              >> 9U)) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x33U] 
                                                >> 8U))) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x33U] 
                                            >> 7U)) 
                                        | (((~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x33U] 
                                                >> 9U)) 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                               [0x33U] 
                                               >> 8U)) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x33U] 
                                                 >> 7U)))) 
                                       | (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x33U] 
                                            >> 9U) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x33U] 
                                                 >> 8U))) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x33U] 
                                                >> 7U)))) 
                                      | (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x33U] 
                                           >> 9U) & 
                                          (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x33U] 
                                           >> 8U)) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x33U] 
                                            >> 7U))))));
        bufp->chgBit(oldp+516,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x33U] >> 0xaU))));
        bufp->chgBit(oldp+517,((1U & ((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__51__KET____DOT__bi__DOT__ThiSig) 
                                        >> 1U) & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__51__KET____DOT__bi__DOT__ThiSig) 
                                                  | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                     [0x33U] 
                                                     >> 0xaU))) 
                                      | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__51__KET____DOT__bi__DOT__ThiSig) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x33U] 
                                            >> 0xaU))))));
        bufp->chgBit(oldp+518,((1U & (((((IData)((0U 
                                                  == (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__51__KET____DOT__bi__DOT__ThiSig))) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x33U] 
                                            >> 0xaU)) 
                                        | ((IData)(
                                                   (1U 
                                                    == (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__51__KET____DOT__bi__DOT__ThiSig))) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x33U] 
                                                 >> 0xaU)))) 
                                       | ((IData)((2U 
                                                   == (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__51__KET____DOT__bi__DOT__ThiSig))) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x33U] 
                                                >> 0xaU)))) 
                                      | ((IData)((3U 
                                                  == (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__51__KET____DOT__bi__DOT__ThiSig))) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x33U] 
                                            >> 0xaU))))));
        bufp->chgBit(oldp+519,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x33U] >> 2U))));
        bufp->chgBit(oldp+520,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x33U] >> 1U))));
        bufp->chgBit(oldp+521,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                [0x33U])));
        bufp->chgBit(oldp+522,((1U & (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                        [0x33U] >> 2U) 
                                       & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x33U] 
                                           >> 1U) | 
                                          vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x33U])) 
                                      | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x33U] >> 1U) 
                                         & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x33U])))));
        bufp->chgBit(oldp+523,((1U & ((((((~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                              [0x33U] 
                                              >> 2U)) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x33U] 
                                                >> 1U))) 
                                         & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x33U]) | 
                                        (((~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                              [0x33U] 
                                              >> 2U)) 
                                          & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [0x33U] 
                                             >> 1U)) 
                                         & (~ vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x33U]))) 
                                       | (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x33U] 
                                            >> 2U) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x33U] 
                                                 >> 1U))) 
                                          & (~ vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [0x33U]))) 
                                      | (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x33U] 
                                           >> 2U) & 
                                          (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x33U] 
                                           >> 1U)) 
                                         & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x33U])))));
        bufp->chgBit(oldp+524,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x33U] >> 4U))));
        bufp->chgBit(oldp+525,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x33U] >> 3U))));
        bufp->chgBit(oldp+526,((1U & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__51__KET____DOT__bi__InData 
                                       & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x33U] 
                                           >> 4U) | 
                                          (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x33U] 
                                           >> 3U))) 
                                      | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x33U] >> 4U) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x33U] 
                                            >> 3U))))));
        bufp->chgBit(oldp+527,((1U & ((((((~ vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__51__KET____DOT__bi__InData) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x33U] 
                                                >> 4U))) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x33U] 
                                            >> 3U)) 
                                        | (((~ vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__51__KET____DOT__bi__InData) 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                               [0x33U] 
                                               >> 4U)) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x33U] 
                                                 >> 3U)))) 
                                       | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__51__KET____DOT__bi__InData 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x33U] 
                                                 >> 4U))) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x33U] 
                                                >> 3U)))) 
                                      | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__51__KET____DOT__bi__InData 
                                          & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [0x33U] 
                                             >> 4U)) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x33U] 
                                            >> 3U))))));
        bufp->chgBit(oldp+528,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x33U] >> 0xdU))));
        bufp->chgBit(oldp+529,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x33U] >> 0xcU))));
        bufp->chgBit(oldp+530,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__51__KET____DOT__bi__DOT__SecSig))));
        bufp->chgBit(oldp+531,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x33U] >> 6U))));
        bufp->chgBit(oldp+532,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x33U] >> 5U))));
        bufp->chgBit(oldp+533,((1U & (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__51__KET____DOT__bi__DOT__SecSig) 
                                       & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x33U] 
                                           >> 6U) | 
                                          (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x33U] 
                                           >> 5U))) 
                                      | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x33U] >> 6U) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x33U] 
                                            >> 5U))))));
        bufp->chgBit(oldp+534,((1U & ((((((~ (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__51__KET____DOT__bi__DOT__SecSig)) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x33U] 
                                                >> 6U))) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x33U] 
                                            >> 5U)) 
                                        | (((~ (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__51__KET____DOT__bi__DOT__SecSig)) 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                               [0x33U] 
                                               >> 6U)) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x33U] 
                                                 >> 5U)))) 
                                       | (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__51__KET____DOT__bi__DOT__SecSig) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x33U] 
                                                 >> 6U))) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x33U] 
                                                >> 5U)))) 
                                      | (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__51__KET____DOT__bi__DOT__SecSig) 
                                          & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [0x33U] 
                                             >> 6U)) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x33U] 
                                            >> 5U))))));
        bufp->chgBit(oldp+535,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__51__KET____DOT__bi__DOT__SecSig) 
                                      >> 3U))));
        bufp->chgBit(oldp+536,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__51__KET____DOT__bi__DOT__SecSig) 
                                      >> 2U))));
        bufp->chgBit(oldp+537,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__51__KET____DOT__bi__DOT__SecSig) 
                                      >> 1U))));
        bufp->chgBit(oldp+538,((1U & ((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__51__KET____DOT__bi__DOT__SecSig) 
                                        >> 3U) & (IData)(
                                                         (0U 
                                                          != 
                                                          (6U 
                                                           & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__51__KET____DOT__bi__DOT__SecSig))))) 
                                      | (IData)((6U 
                                                 == 
                                                 (6U 
                                                  & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__51__KET____DOT__bi__DOT__SecSig))))))));
        bufp->chgBit(oldp+539,((1U & ((((IData)((2U 
                                                 == 
                                                 (0xeU 
                                                  & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__51__KET____DOT__bi__DOT__SecSig)))) 
                                        | (IData)((4U 
                                                   == 
                                                   (0xeU 
                                                    & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__51__KET____DOT__bi__DOT__SecSig))))) 
                                       | (IData)((8U 
                                                  == 
                                                  (0xeU 
                                                   & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__51__KET____DOT__bi__DOT__SecSig))))) 
                                      | (IData)((0xeU 
                                                 == 
                                                 (0xeU 
                                                  & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__51__KET____DOT__bi__DOT__SecSig))))))));
        bufp->chgSData(oldp+540,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                 [0x34U]),14);
        bufp->chgSData(oldp+541,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellout__wallacefor__BRA__52__KET____DOT__bi__COut),14);
        bufp->chgBit(oldp+542,((1U & (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__52__KET____DOT__bi__DOT__FifSig) 
                                       & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x34U] 
                                           >> 0xdU) 
                                          | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [0x34U] 
                                             >> 0xcU))) 
                                      | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x34U] >> 0xdU) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x34U] 
                                            >> 0xcU))))));
        bufp->chgBit(oldp+543,((1U & ((((((~ (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__52__KET____DOT__bi__DOT__FifSig)) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x34U] 
                                                >> 0xdU))) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x34U] 
                                            >> 0xcU)) 
                                        | (((~ (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__52__KET____DOT__bi__DOT__FifSig)) 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                               [0x34U] 
                                               >> 0xdU)) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x34U] 
                                                 >> 0xcU)))) 
                                       | (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__52__KET____DOT__bi__DOT__FifSig) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x34U] 
                                                 >> 0xdU))) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x34U] 
                                                >> 0xcU)))) 
                                      | (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__52__KET____DOT__bi__DOT__FifSig) 
                                          & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [0x34U] 
                                             >> 0xdU)) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x34U] 
                                            >> 0xcU))))));
        bufp->chgCData(oldp+544,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__52__KET____DOT__bi__DOT__SecSig),4);
        bufp->chgBit(oldp+545,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x34U] >> 0xbU))));
        bufp->chgBit(oldp+546,((1U & ((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__52__KET____DOT__bi__DOT__ForSig) 
                                        >> 1U) & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__52__KET____DOT__bi__DOT__ForSig) 
                                                  | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                     [0x34U] 
                                                     >> 0xbU))) 
                                      | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__52__KET____DOT__bi__DOT__ForSig) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x34U] 
                                            >> 0xbU))))));
        bufp->chgBit(oldp+547,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x34U] >> 9U))));
        bufp->chgBit(oldp+548,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x34U] >> 8U))));
        bufp->chgBit(oldp+549,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x34U] >> 7U))));
        bufp->chgBit(oldp+550,((1U & (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                        [0x34U] >> 9U) 
                                       & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x34U] 
                                           >> 8U) | 
                                          (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x34U] 
                                           >> 7U))) 
                                      | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x34U] >> 8U) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x34U] 
                                            >> 7U))))));
        bufp->chgBit(oldp+551,((1U & ((((((~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                              [0x34U] 
                                              >> 9U)) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x34U] 
                                                >> 8U))) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x34U] 
                                            >> 7U)) 
                                        | (((~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x34U] 
                                                >> 9U)) 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                               [0x34U] 
                                               >> 8U)) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x34U] 
                                                 >> 7U)))) 
                                       | (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x34U] 
                                            >> 9U) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x34U] 
                                                 >> 8U))) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x34U] 
                                                >> 7U)))) 
                                      | (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x34U] 
                                           >> 9U) & 
                                          (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x34U] 
                                           >> 8U)) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x34U] 
                                            >> 7U))))));
        bufp->chgBit(oldp+552,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x34U] >> 0xaU))));
        bufp->chgBit(oldp+553,((1U & ((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__52__KET____DOT__bi__DOT__ThiSig) 
                                        >> 1U) & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__52__KET____DOT__bi__DOT__ThiSig) 
                                                  | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                     [0x34U] 
                                                     >> 0xaU))) 
                                      | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__52__KET____DOT__bi__DOT__ThiSig) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x34U] 
                                            >> 0xaU))))));
        bufp->chgBit(oldp+554,((1U & (((((IData)((0U 
                                                  == (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__52__KET____DOT__bi__DOT__ThiSig))) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x34U] 
                                            >> 0xaU)) 
                                        | ((IData)(
                                                   (1U 
                                                    == (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__52__KET____DOT__bi__DOT__ThiSig))) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x34U] 
                                                 >> 0xaU)))) 
                                       | ((IData)((2U 
                                                   == (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__52__KET____DOT__bi__DOT__ThiSig))) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x34U] 
                                                >> 0xaU)))) 
                                      | ((IData)((3U 
                                                  == (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__52__KET____DOT__bi__DOT__ThiSig))) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x34U] 
                                            >> 0xaU))))));
        bufp->chgBit(oldp+555,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x34U] >> 2U))));
        bufp->chgBit(oldp+556,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x34U] >> 1U))));
        bufp->chgBit(oldp+557,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                [0x34U])));
        bufp->chgBit(oldp+558,((1U & (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                        [0x34U] >> 2U) 
                                       & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x34U] 
                                           >> 1U) | 
                                          vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x34U])) 
                                      | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x34U] >> 1U) 
                                         & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x34U])))));
        bufp->chgBit(oldp+559,((1U & ((((((~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                              [0x34U] 
                                              >> 2U)) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x34U] 
                                                >> 1U))) 
                                         & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x34U]) | 
                                        (((~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                              [0x34U] 
                                              >> 2U)) 
                                          & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [0x34U] 
                                             >> 1U)) 
                                         & (~ vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x34U]))) 
                                       | (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x34U] 
                                            >> 2U) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x34U] 
                                                 >> 1U))) 
                                          & (~ vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [0x34U]))) 
                                      | (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x34U] 
                                           >> 2U) & 
                                          (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x34U] 
                                           >> 1U)) 
                                         & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x34U])))));
        bufp->chgBit(oldp+560,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x34U] >> 4U))));
        bufp->chgBit(oldp+561,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x34U] >> 3U))));
        bufp->chgBit(oldp+562,((1U & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__52__KET____DOT__bi__InData 
                                       & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x34U] 
                                           >> 4U) | 
                                          (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x34U] 
                                           >> 3U))) 
                                      | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x34U] >> 4U) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x34U] 
                                            >> 3U))))));
        bufp->chgBit(oldp+563,((1U & ((((((~ vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__52__KET____DOT__bi__InData) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x34U] 
                                                >> 4U))) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x34U] 
                                            >> 3U)) 
                                        | (((~ vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__52__KET____DOT__bi__InData) 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                               [0x34U] 
                                               >> 4U)) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x34U] 
                                                 >> 3U)))) 
                                       | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__52__KET____DOT__bi__InData 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x34U] 
                                                 >> 4U))) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x34U] 
                                                >> 3U)))) 
                                      | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__52__KET____DOT__bi__InData 
                                          & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [0x34U] 
                                             >> 4U)) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x34U] 
                                            >> 3U))))));
        bufp->chgBit(oldp+564,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x34U] >> 0xdU))));
        bufp->chgBit(oldp+565,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x34U] >> 0xcU))));
        bufp->chgBit(oldp+566,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__52__KET____DOT__bi__DOT__SecSig))));
        bufp->chgBit(oldp+567,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x34U] >> 6U))));
        bufp->chgBit(oldp+568,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x34U] >> 5U))));
        bufp->chgBit(oldp+569,((1U & (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__52__KET____DOT__bi__DOT__SecSig) 
                                       & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x34U] 
                                           >> 6U) | 
                                          (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x34U] 
                                           >> 5U))) 
                                      | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x34U] >> 6U) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x34U] 
                                            >> 5U))))));
        bufp->chgBit(oldp+570,((1U & ((((((~ (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__52__KET____DOT__bi__DOT__SecSig)) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x34U] 
                                                >> 6U))) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x34U] 
                                            >> 5U)) 
                                        | (((~ (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__52__KET____DOT__bi__DOT__SecSig)) 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                               [0x34U] 
                                               >> 6U)) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x34U] 
                                                 >> 5U)))) 
                                       | (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__52__KET____DOT__bi__DOT__SecSig) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x34U] 
                                                 >> 6U))) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x34U] 
                                                >> 5U)))) 
                                      | (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__52__KET____DOT__bi__DOT__SecSig) 
                                          & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [0x34U] 
                                             >> 6U)) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x34U] 
                                            >> 5U))))));
        bufp->chgBit(oldp+571,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__52__KET____DOT__bi__DOT__SecSig) 
                                      >> 3U))));
        bufp->chgBit(oldp+572,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__52__KET____DOT__bi__DOT__SecSig) 
                                      >> 2U))));
        bufp->chgBit(oldp+573,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__52__KET____DOT__bi__DOT__SecSig) 
                                      >> 1U))));
        bufp->chgBit(oldp+574,((1U & ((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__52__KET____DOT__bi__DOT__SecSig) 
                                        >> 3U) & (IData)(
                                                         (0U 
                                                          != 
                                                          (6U 
                                                           & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__52__KET____DOT__bi__DOT__SecSig))))) 
                                      | (IData)((6U 
                                                 == 
                                                 (6U 
                                                  & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__52__KET____DOT__bi__DOT__SecSig))))))));
        bufp->chgBit(oldp+575,((1U & ((((IData)((2U 
                                                 == 
                                                 (0xeU 
                                                  & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__52__KET____DOT__bi__DOT__SecSig)))) 
                                        | (IData)((4U 
                                                   == 
                                                   (0xeU 
                                                    & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__52__KET____DOT__bi__DOT__SecSig))))) 
                                       | (IData)((8U 
                                                  == 
                                                  (0xeU 
                                                   & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__52__KET____DOT__bi__DOT__SecSig))))) 
                                      | (IData)((0xeU 
                                                 == 
                                                 (0xeU 
                                                  & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__52__KET____DOT__bi__DOT__SecSig))))))));
        bufp->chgSData(oldp+576,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                 [0x35U]),14);
        bufp->chgSData(oldp+577,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellout__wallacefor__BRA__53__KET____DOT__bi__COut),14);
        bufp->chgBit(oldp+578,((1U & (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__53__KET____DOT__bi__DOT__FifSig) 
                                       & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x35U] 
                                           >> 0xdU) 
                                          | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [0x35U] 
                                             >> 0xcU))) 
                                      | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x35U] >> 0xdU) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x35U] 
                                            >> 0xcU))))));
        bufp->chgBit(oldp+579,((1U & ((((((~ (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__53__KET____DOT__bi__DOT__FifSig)) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x35U] 
                                                >> 0xdU))) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x35U] 
                                            >> 0xcU)) 
                                        | (((~ (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__53__KET____DOT__bi__DOT__FifSig)) 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                               [0x35U] 
                                               >> 0xdU)) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x35U] 
                                                 >> 0xcU)))) 
                                       | (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__53__KET____DOT__bi__DOT__FifSig) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x35U] 
                                                 >> 0xdU))) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x35U] 
                                                >> 0xcU)))) 
                                      | (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__53__KET____DOT__bi__DOT__FifSig) 
                                          & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [0x35U] 
                                             >> 0xdU)) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x35U] 
                                            >> 0xcU))))));
        bufp->chgCData(oldp+580,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__53__KET____DOT__bi__DOT__SecSig),4);
        bufp->chgBit(oldp+581,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x35U] >> 0xbU))));
        bufp->chgBit(oldp+582,((1U & ((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__53__KET____DOT__bi__DOT__ForSig) 
                                        >> 1U) & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__53__KET____DOT__bi__DOT__ForSig) 
                                                  | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                     [0x35U] 
                                                     >> 0xbU))) 
                                      | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__53__KET____DOT__bi__DOT__ForSig) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x35U] 
                                            >> 0xbU))))));
        bufp->chgBit(oldp+583,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x35U] >> 9U))));
        bufp->chgBit(oldp+584,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x35U] >> 8U))));
        bufp->chgBit(oldp+585,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x35U] >> 7U))));
        bufp->chgBit(oldp+586,((1U & (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                        [0x35U] >> 9U) 
                                       & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x35U] 
                                           >> 8U) | 
                                          (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x35U] 
                                           >> 7U))) 
                                      | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x35U] >> 8U) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x35U] 
                                            >> 7U))))));
        bufp->chgBit(oldp+587,((1U & ((((((~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                              [0x35U] 
                                              >> 9U)) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x35U] 
                                                >> 8U))) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x35U] 
                                            >> 7U)) 
                                        | (((~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x35U] 
                                                >> 9U)) 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                               [0x35U] 
                                               >> 8U)) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x35U] 
                                                 >> 7U)))) 
                                       | (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x35U] 
                                            >> 9U) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x35U] 
                                                 >> 8U))) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x35U] 
                                                >> 7U)))) 
                                      | (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x35U] 
                                           >> 9U) & 
                                          (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x35U] 
                                           >> 8U)) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x35U] 
                                            >> 7U))))));
        bufp->chgBit(oldp+588,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x35U] >> 0xaU))));
        bufp->chgBit(oldp+589,((1U & ((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__53__KET____DOT__bi__DOT__ThiSig) 
                                        >> 1U) & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__53__KET____DOT__bi__DOT__ThiSig) 
                                                  | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                     [0x35U] 
                                                     >> 0xaU))) 
                                      | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__53__KET____DOT__bi__DOT__ThiSig) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x35U] 
                                            >> 0xaU))))));
        bufp->chgBit(oldp+590,((1U & (((((IData)((0U 
                                                  == (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__53__KET____DOT__bi__DOT__ThiSig))) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x35U] 
                                            >> 0xaU)) 
                                        | ((IData)(
                                                   (1U 
                                                    == (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__53__KET____DOT__bi__DOT__ThiSig))) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x35U] 
                                                 >> 0xaU)))) 
                                       | ((IData)((2U 
                                                   == (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__53__KET____DOT__bi__DOT__ThiSig))) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x35U] 
                                                >> 0xaU)))) 
                                      | ((IData)((3U 
                                                  == (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__53__KET____DOT__bi__DOT__ThiSig))) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x35U] 
                                            >> 0xaU))))));
        bufp->chgBit(oldp+591,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x35U] >> 2U))));
        bufp->chgBit(oldp+592,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x35U] >> 1U))));
        bufp->chgBit(oldp+593,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                [0x35U])));
        bufp->chgBit(oldp+594,((1U & (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                        [0x35U] >> 2U) 
                                       & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x35U] 
                                           >> 1U) | 
                                          vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x35U])) 
                                      | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x35U] >> 1U) 
                                         & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x35U])))));
        bufp->chgBit(oldp+595,((1U & ((((((~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                              [0x35U] 
                                              >> 2U)) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x35U] 
                                                >> 1U))) 
                                         & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x35U]) | 
                                        (((~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                              [0x35U] 
                                              >> 2U)) 
                                          & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [0x35U] 
                                             >> 1U)) 
                                         & (~ vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x35U]))) 
                                       | (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x35U] 
                                            >> 2U) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x35U] 
                                                 >> 1U))) 
                                          & (~ vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [0x35U]))) 
                                      | (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x35U] 
                                           >> 2U) & 
                                          (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x35U] 
                                           >> 1U)) 
                                         & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x35U])))));
        bufp->chgBit(oldp+596,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x35U] >> 4U))));
        bufp->chgBit(oldp+597,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x35U] >> 3U))));
        bufp->chgBit(oldp+598,((1U & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__53__KET____DOT__bi__InData 
                                       & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x35U] 
                                           >> 4U) | 
                                          (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x35U] 
                                           >> 3U))) 
                                      | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x35U] >> 4U) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x35U] 
                                            >> 3U))))));
        bufp->chgBit(oldp+599,((1U & ((((((~ vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__53__KET____DOT__bi__InData) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x35U] 
                                                >> 4U))) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x35U] 
                                            >> 3U)) 
                                        | (((~ vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__53__KET____DOT__bi__InData) 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                               [0x35U] 
                                               >> 4U)) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x35U] 
                                                 >> 3U)))) 
                                       | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__53__KET____DOT__bi__InData 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x35U] 
                                                 >> 4U))) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x35U] 
                                                >> 3U)))) 
                                      | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__53__KET____DOT__bi__InData 
                                          & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [0x35U] 
                                             >> 4U)) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x35U] 
                                            >> 3U))))));
        bufp->chgBit(oldp+600,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x35U] >> 0xdU))));
        bufp->chgBit(oldp+601,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x35U] >> 0xcU))));
        bufp->chgBit(oldp+602,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__53__KET____DOT__bi__DOT__SecSig))));
        bufp->chgBit(oldp+603,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x35U] >> 6U))));
        bufp->chgBit(oldp+604,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x35U] >> 5U))));
        bufp->chgBit(oldp+605,((1U & (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__53__KET____DOT__bi__DOT__SecSig) 
                                       & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x35U] 
                                           >> 6U) | 
                                          (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x35U] 
                                           >> 5U))) 
                                      | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x35U] >> 6U) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x35U] 
                                            >> 5U))))));
        bufp->chgBit(oldp+606,((1U & ((((((~ (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__53__KET____DOT__bi__DOT__SecSig)) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x35U] 
                                                >> 6U))) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x35U] 
                                            >> 5U)) 
                                        | (((~ (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__53__KET____DOT__bi__DOT__SecSig)) 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                               [0x35U] 
                                               >> 6U)) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x35U] 
                                                 >> 5U)))) 
                                       | (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__53__KET____DOT__bi__DOT__SecSig) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x35U] 
                                                 >> 6U))) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x35U] 
                                                >> 5U)))) 
                                      | (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__53__KET____DOT__bi__DOT__SecSig) 
                                          & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [0x35U] 
                                             >> 6U)) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x35U] 
                                            >> 5U))))));
        bufp->chgBit(oldp+607,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__53__KET____DOT__bi__DOT__SecSig) 
                                      >> 3U))));
        bufp->chgBit(oldp+608,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__53__KET____DOT__bi__DOT__SecSig) 
                                      >> 2U))));
        bufp->chgBit(oldp+609,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__53__KET____DOT__bi__DOT__SecSig) 
                                      >> 1U))));
        bufp->chgBit(oldp+610,((1U & ((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__53__KET____DOT__bi__DOT__SecSig) 
                                        >> 3U) & (IData)(
                                                         (0U 
                                                          != 
                                                          (6U 
                                                           & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__53__KET____DOT__bi__DOT__SecSig))))) 
                                      | (IData)((6U 
                                                 == 
                                                 (6U 
                                                  & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__53__KET____DOT__bi__DOT__SecSig))))))));
        bufp->chgBit(oldp+611,((1U & ((((IData)((2U 
                                                 == 
                                                 (0xeU 
                                                  & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__53__KET____DOT__bi__DOT__SecSig)))) 
                                        | (IData)((4U 
                                                   == 
                                                   (0xeU 
                                                    & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__53__KET____DOT__bi__DOT__SecSig))))) 
                                       | (IData)((8U 
                                                  == 
                                                  (0xeU 
                                                   & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__53__KET____DOT__bi__DOT__SecSig))))) 
                                      | (IData)((0xeU 
                                                 == 
                                                 (0xeU 
                                                  & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__53__KET____DOT__bi__DOT__SecSig))))))));
        bufp->chgSData(oldp+612,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                 [0x36U]),14);
        bufp->chgSData(oldp+613,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellout__wallacefor__BRA__54__KET____DOT__bi__COut),14);
        bufp->chgBit(oldp+614,((1U & (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__54__KET____DOT__bi__DOT__FifSig) 
                                       & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x36U] 
                                           >> 0xdU) 
                                          | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [0x36U] 
                                             >> 0xcU))) 
                                      | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x36U] >> 0xdU) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x36U] 
                                            >> 0xcU))))));
        bufp->chgBit(oldp+615,((1U & ((((((~ (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__54__KET____DOT__bi__DOT__FifSig)) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x36U] 
                                                >> 0xdU))) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x36U] 
                                            >> 0xcU)) 
                                        | (((~ (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__54__KET____DOT__bi__DOT__FifSig)) 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                               [0x36U] 
                                               >> 0xdU)) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x36U] 
                                                 >> 0xcU)))) 
                                       | (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__54__KET____DOT__bi__DOT__FifSig) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x36U] 
                                                 >> 0xdU))) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x36U] 
                                                >> 0xcU)))) 
                                      | (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__54__KET____DOT__bi__DOT__FifSig) 
                                          & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [0x36U] 
                                             >> 0xdU)) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x36U] 
                                            >> 0xcU))))));
        bufp->chgCData(oldp+616,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__54__KET____DOT__bi__DOT__SecSig),4);
        bufp->chgBit(oldp+617,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x36U] >> 0xbU))));
        bufp->chgBit(oldp+618,((1U & ((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__54__KET____DOT__bi__DOT__ForSig) 
                                        >> 1U) & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__54__KET____DOT__bi__DOT__ForSig) 
                                                  | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                     [0x36U] 
                                                     >> 0xbU))) 
                                      | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__54__KET____DOT__bi__DOT__ForSig) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x36U] 
                                            >> 0xbU))))));
        bufp->chgBit(oldp+619,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x36U] >> 9U))));
        bufp->chgBit(oldp+620,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x36U] >> 8U))));
        bufp->chgBit(oldp+621,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x36U] >> 7U))));
        bufp->chgBit(oldp+622,((1U & (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                        [0x36U] >> 9U) 
                                       & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x36U] 
                                           >> 8U) | 
                                          (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x36U] 
                                           >> 7U))) 
                                      | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x36U] >> 8U) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x36U] 
                                            >> 7U))))));
        bufp->chgBit(oldp+623,((1U & ((((((~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                              [0x36U] 
                                              >> 9U)) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x36U] 
                                                >> 8U))) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x36U] 
                                            >> 7U)) 
                                        | (((~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x36U] 
                                                >> 9U)) 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                               [0x36U] 
                                               >> 8U)) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x36U] 
                                                 >> 7U)))) 
                                       | (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x36U] 
                                            >> 9U) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x36U] 
                                                 >> 8U))) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x36U] 
                                                >> 7U)))) 
                                      | (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x36U] 
                                           >> 9U) & 
                                          (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x36U] 
                                           >> 8U)) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x36U] 
                                            >> 7U))))));
        bufp->chgBit(oldp+624,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x36U] >> 0xaU))));
        bufp->chgBit(oldp+625,((1U & ((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__54__KET____DOT__bi__DOT__ThiSig) 
                                        >> 1U) & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__54__KET____DOT__bi__DOT__ThiSig) 
                                                  | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                     [0x36U] 
                                                     >> 0xaU))) 
                                      | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__54__KET____DOT__bi__DOT__ThiSig) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x36U] 
                                            >> 0xaU))))));
        bufp->chgBit(oldp+626,((1U & (((((IData)((0U 
                                                  == (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__54__KET____DOT__bi__DOT__ThiSig))) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x36U] 
                                            >> 0xaU)) 
                                        | ((IData)(
                                                   (1U 
                                                    == (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__54__KET____DOT__bi__DOT__ThiSig))) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x36U] 
                                                 >> 0xaU)))) 
                                       | ((IData)((2U 
                                                   == (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__54__KET____DOT__bi__DOT__ThiSig))) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x36U] 
                                                >> 0xaU)))) 
                                      | ((IData)((3U 
                                                  == (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__54__KET____DOT__bi__DOT__ThiSig))) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x36U] 
                                            >> 0xaU))))));
        bufp->chgBit(oldp+627,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x36U] >> 2U))));
        bufp->chgBit(oldp+628,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x36U] >> 1U))));
        bufp->chgBit(oldp+629,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                [0x36U])));
        bufp->chgBit(oldp+630,((1U & (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                        [0x36U] >> 2U) 
                                       & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x36U] 
                                           >> 1U) | 
                                          vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x36U])) 
                                      | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x36U] >> 1U) 
                                         & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x36U])))));
        bufp->chgBit(oldp+631,((1U & ((((((~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                              [0x36U] 
                                              >> 2U)) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x36U] 
                                                >> 1U))) 
                                         & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x36U]) | 
                                        (((~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                              [0x36U] 
                                              >> 2U)) 
                                          & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [0x36U] 
                                             >> 1U)) 
                                         & (~ vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x36U]))) 
                                       | (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x36U] 
                                            >> 2U) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x36U] 
                                                 >> 1U))) 
                                          & (~ vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [0x36U]))) 
                                      | (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x36U] 
                                           >> 2U) & 
                                          (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x36U] 
                                           >> 1U)) 
                                         & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x36U])))));
        bufp->chgBit(oldp+632,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x36U] >> 4U))));
        bufp->chgBit(oldp+633,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x36U] >> 3U))));
        bufp->chgBit(oldp+634,((1U & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__54__KET____DOT__bi__InData 
                                       & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x36U] 
                                           >> 4U) | 
                                          (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x36U] 
                                           >> 3U))) 
                                      | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x36U] >> 4U) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x36U] 
                                            >> 3U))))));
        bufp->chgBit(oldp+635,((1U & ((((((~ vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__54__KET____DOT__bi__InData) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x36U] 
                                                >> 4U))) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x36U] 
                                            >> 3U)) 
                                        | (((~ vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__54__KET____DOT__bi__InData) 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                               [0x36U] 
                                               >> 4U)) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x36U] 
                                                 >> 3U)))) 
                                       | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__54__KET____DOT__bi__InData 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x36U] 
                                                 >> 4U))) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x36U] 
                                                >> 3U)))) 
                                      | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__54__KET____DOT__bi__InData 
                                          & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [0x36U] 
                                             >> 4U)) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x36U] 
                                            >> 3U))))));
        bufp->chgBit(oldp+636,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x36U] >> 0xdU))));
        bufp->chgBit(oldp+637,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x36U] >> 0xcU))));
        bufp->chgBit(oldp+638,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__54__KET____DOT__bi__DOT__SecSig))));
        bufp->chgBit(oldp+639,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x36U] >> 6U))));
        bufp->chgBit(oldp+640,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x36U] >> 5U))));
        bufp->chgBit(oldp+641,((1U & (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__54__KET____DOT__bi__DOT__SecSig) 
                                       & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x36U] 
                                           >> 6U) | 
                                          (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x36U] 
                                           >> 5U))) 
                                      | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x36U] >> 6U) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x36U] 
                                            >> 5U))))));
        bufp->chgBit(oldp+642,((1U & ((((((~ (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__54__KET____DOT__bi__DOT__SecSig)) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x36U] 
                                                >> 6U))) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x36U] 
                                            >> 5U)) 
                                        | (((~ (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__54__KET____DOT__bi__DOT__SecSig)) 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                               [0x36U] 
                                               >> 6U)) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x36U] 
                                                 >> 5U)))) 
                                       | (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__54__KET____DOT__bi__DOT__SecSig) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x36U] 
                                                 >> 6U))) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x36U] 
                                                >> 5U)))) 
                                      | (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__54__KET____DOT__bi__DOT__SecSig) 
                                          & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [0x36U] 
                                             >> 6U)) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x36U] 
                                            >> 5U))))));
        bufp->chgBit(oldp+643,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__54__KET____DOT__bi__DOT__SecSig) 
                                      >> 3U))));
        bufp->chgBit(oldp+644,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__54__KET____DOT__bi__DOT__SecSig) 
                                      >> 2U))));
        bufp->chgBit(oldp+645,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__54__KET____DOT__bi__DOT__SecSig) 
                                      >> 1U))));
        bufp->chgBit(oldp+646,((1U & ((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__54__KET____DOT__bi__DOT__SecSig) 
                                        >> 3U) & (IData)(
                                                         (0U 
                                                          != 
                                                          (6U 
                                                           & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__54__KET____DOT__bi__DOT__SecSig))))) 
                                      | (IData)((6U 
                                                 == 
                                                 (6U 
                                                  & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__54__KET____DOT__bi__DOT__SecSig))))))));
        bufp->chgBit(oldp+647,((1U & ((((IData)((2U 
                                                 == 
                                                 (0xeU 
                                                  & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__54__KET____DOT__bi__DOT__SecSig)))) 
                                        | (IData)((4U 
                                                   == 
                                                   (0xeU 
                                                    & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__54__KET____DOT__bi__DOT__SecSig))))) 
                                       | (IData)((8U 
                                                  == 
                                                  (0xeU 
                                                   & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__54__KET____DOT__bi__DOT__SecSig))))) 
                                      | (IData)((0xeU 
                                                 == 
                                                 (0xeU 
                                                  & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__54__KET____DOT__bi__DOT__SecSig))))))));
        bufp->chgSData(oldp+648,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                 [0x37U]),14);
        bufp->chgSData(oldp+649,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellout__wallacefor__BRA__55__KET____DOT__bi__COut),14);
        bufp->chgBit(oldp+650,((1U & (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__55__KET____DOT__bi__DOT__FifSig) 
                                       & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x37U] 
                                           >> 0xdU) 
                                          | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [0x37U] 
                                             >> 0xcU))) 
                                      | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x37U] >> 0xdU) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x37U] 
                                            >> 0xcU))))));
        bufp->chgBit(oldp+651,((1U & ((((((~ (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__55__KET____DOT__bi__DOT__FifSig)) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x37U] 
                                                >> 0xdU))) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x37U] 
                                            >> 0xcU)) 
                                        | (((~ (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__55__KET____DOT__bi__DOT__FifSig)) 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                               [0x37U] 
                                               >> 0xdU)) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x37U] 
                                                 >> 0xcU)))) 
                                       | (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__55__KET____DOT__bi__DOT__FifSig) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x37U] 
                                                 >> 0xdU))) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x37U] 
                                                >> 0xcU)))) 
                                      | (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__55__KET____DOT__bi__DOT__FifSig) 
                                          & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [0x37U] 
                                             >> 0xdU)) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x37U] 
                                            >> 0xcU))))));
        bufp->chgCData(oldp+652,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__55__KET____DOT__bi__DOT__SecSig),4);
        bufp->chgBit(oldp+653,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x37U] >> 0xbU))));
        bufp->chgBit(oldp+654,((1U & ((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__55__KET____DOT__bi__DOT__ForSig) 
                                        >> 1U) & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__55__KET____DOT__bi__DOT__ForSig) 
                                                  | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                     [0x37U] 
                                                     >> 0xbU))) 
                                      | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__55__KET____DOT__bi__DOT__ForSig) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x37U] 
                                            >> 0xbU))))));
        bufp->chgBit(oldp+655,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x37U] >> 9U))));
        bufp->chgBit(oldp+656,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x37U] >> 8U))));
        bufp->chgBit(oldp+657,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x37U] >> 7U))));
        bufp->chgBit(oldp+658,((1U & (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                        [0x37U] >> 9U) 
                                       & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x37U] 
                                           >> 8U) | 
                                          (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x37U] 
                                           >> 7U))) 
                                      | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x37U] >> 8U) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x37U] 
                                            >> 7U))))));
        bufp->chgBit(oldp+659,((1U & ((((((~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                              [0x37U] 
                                              >> 9U)) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x37U] 
                                                >> 8U))) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x37U] 
                                            >> 7U)) 
                                        | (((~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x37U] 
                                                >> 9U)) 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                               [0x37U] 
                                               >> 8U)) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x37U] 
                                                 >> 7U)))) 
                                       | (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x37U] 
                                            >> 9U) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x37U] 
                                                 >> 8U))) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x37U] 
                                                >> 7U)))) 
                                      | (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x37U] 
                                           >> 9U) & 
                                          (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x37U] 
                                           >> 8U)) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x37U] 
                                            >> 7U))))));
        bufp->chgBit(oldp+660,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x37U] >> 0xaU))));
        bufp->chgBit(oldp+661,((1U & ((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__55__KET____DOT__bi__DOT__ThiSig) 
                                        >> 1U) & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__55__KET____DOT__bi__DOT__ThiSig) 
                                                  | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                     [0x37U] 
                                                     >> 0xaU))) 
                                      | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__55__KET____DOT__bi__DOT__ThiSig) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x37U] 
                                            >> 0xaU))))));
        bufp->chgBit(oldp+662,((1U & (((((IData)((0U 
                                                  == (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__55__KET____DOT__bi__DOT__ThiSig))) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x37U] 
                                            >> 0xaU)) 
                                        | ((IData)(
                                                   (1U 
                                                    == (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__55__KET____DOT__bi__DOT__ThiSig))) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x37U] 
                                                 >> 0xaU)))) 
                                       | ((IData)((2U 
                                                   == (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__55__KET____DOT__bi__DOT__ThiSig))) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x37U] 
                                                >> 0xaU)))) 
                                      | ((IData)((3U 
                                                  == (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__55__KET____DOT__bi__DOT__ThiSig))) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x37U] 
                                            >> 0xaU))))));
        bufp->chgBit(oldp+663,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x37U] >> 2U))));
        bufp->chgBit(oldp+664,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x37U] >> 1U))));
        bufp->chgBit(oldp+665,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                [0x37U])));
        bufp->chgBit(oldp+666,((1U & (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                        [0x37U] >> 2U) 
                                       & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x37U] 
                                           >> 1U) | 
                                          vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x37U])) 
                                      | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x37U] >> 1U) 
                                         & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x37U])))));
        bufp->chgBit(oldp+667,((1U & ((((((~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                              [0x37U] 
                                              >> 2U)) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x37U] 
                                                >> 1U))) 
                                         & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x37U]) | 
                                        (((~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                              [0x37U] 
                                              >> 2U)) 
                                          & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [0x37U] 
                                             >> 1U)) 
                                         & (~ vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x37U]))) 
                                       | (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x37U] 
                                            >> 2U) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x37U] 
                                                 >> 1U))) 
                                          & (~ vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [0x37U]))) 
                                      | (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x37U] 
                                           >> 2U) & 
                                          (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x37U] 
                                           >> 1U)) 
                                         & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x37U])))));
        bufp->chgBit(oldp+668,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x37U] >> 4U))));
        bufp->chgBit(oldp+669,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x37U] >> 3U))));
        bufp->chgBit(oldp+670,((1U & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__55__KET____DOT__bi__InData 
                                       & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x37U] 
                                           >> 4U) | 
                                          (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x37U] 
                                           >> 3U))) 
                                      | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x37U] >> 4U) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x37U] 
                                            >> 3U))))));
        bufp->chgBit(oldp+671,((1U & ((((((~ vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__55__KET____DOT__bi__InData) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x37U] 
                                                >> 4U))) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x37U] 
                                            >> 3U)) 
                                        | (((~ vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__55__KET____DOT__bi__InData) 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                               [0x37U] 
                                               >> 4U)) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x37U] 
                                                 >> 3U)))) 
                                       | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__55__KET____DOT__bi__InData 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x37U] 
                                                 >> 4U))) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x37U] 
                                                >> 3U)))) 
                                      | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__55__KET____DOT__bi__InData 
                                          & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [0x37U] 
                                             >> 4U)) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x37U] 
                                            >> 3U))))));
        bufp->chgBit(oldp+672,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x37U] >> 0xdU))));
        bufp->chgBit(oldp+673,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x37U] >> 0xcU))));
        bufp->chgBit(oldp+674,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__55__KET____DOT__bi__DOT__SecSig))));
        bufp->chgBit(oldp+675,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x37U] >> 6U))));
        bufp->chgBit(oldp+676,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x37U] >> 5U))));
        bufp->chgBit(oldp+677,((1U & (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__55__KET____DOT__bi__DOT__SecSig) 
                                       & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x37U] 
                                           >> 6U) | 
                                          (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x37U] 
                                           >> 5U))) 
                                      | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x37U] >> 6U) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x37U] 
                                            >> 5U))))));
        bufp->chgBit(oldp+678,((1U & ((((((~ (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__55__KET____DOT__bi__DOT__SecSig)) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x37U] 
                                                >> 6U))) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x37U] 
                                            >> 5U)) 
                                        | (((~ (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__55__KET____DOT__bi__DOT__SecSig)) 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                               [0x37U] 
                                               >> 6U)) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x37U] 
                                                 >> 5U)))) 
                                       | (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__55__KET____DOT__bi__DOT__SecSig) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x37U] 
                                                 >> 6U))) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x37U] 
                                                >> 5U)))) 
                                      | (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__55__KET____DOT__bi__DOT__SecSig) 
                                          & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [0x37U] 
                                             >> 6U)) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x37U] 
                                            >> 5U))))));
        bufp->chgBit(oldp+679,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__55__KET____DOT__bi__DOT__SecSig) 
                                      >> 3U))));
        bufp->chgBit(oldp+680,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__55__KET____DOT__bi__DOT__SecSig) 
                                      >> 2U))));
        bufp->chgBit(oldp+681,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__55__KET____DOT__bi__DOT__SecSig) 
                                      >> 1U))));
        bufp->chgBit(oldp+682,((1U & ((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__55__KET____DOT__bi__DOT__SecSig) 
                                        >> 3U) & (IData)(
                                                         (0U 
                                                          != 
                                                          (6U 
                                                           & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__55__KET____DOT__bi__DOT__SecSig))))) 
                                      | (IData)((6U 
                                                 == 
                                                 (6U 
                                                  & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__55__KET____DOT__bi__DOT__SecSig))))))));
        bufp->chgBit(oldp+683,((1U & ((((IData)((2U 
                                                 == 
                                                 (0xeU 
                                                  & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__55__KET____DOT__bi__DOT__SecSig)))) 
                                        | (IData)((4U 
                                                   == 
                                                   (0xeU 
                                                    & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__55__KET____DOT__bi__DOT__SecSig))))) 
                                       | (IData)((8U 
                                                  == 
                                                  (0xeU 
                                                   & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__55__KET____DOT__bi__DOT__SecSig))))) 
                                      | (IData)((0xeU 
                                                 == 
                                                 (0xeU 
                                                  & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__55__KET____DOT__bi__DOT__SecSig))))))));
        bufp->chgSData(oldp+684,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                 [0x38U]),14);
        bufp->chgSData(oldp+685,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellout__wallacefor__BRA__56__KET____DOT__bi__COut),14);
        bufp->chgBit(oldp+686,((1U & (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__56__KET____DOT__bi__DOT__FifSig) 
                                       & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x38U] 
                                           >> 0xdU) 
                                          | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [0x38U] 
                                             >> 0xcU))) 
                                      | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x38U] >> 0xdU) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x38U] 
                                            >> 0xcU))))));
        bufp->chgBit(oldp+687,((1U & ((((((~ (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__56__KET____DOT__bi__DOT__FifSig)) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x38U] 
                                                >> 0xdU))) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x38U] 
                                            >> 0xcU)) 
                                        | (((~ (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__56__KET____DOT__bi__DOT__FifSig)) 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                               [0x38U] 
                                               >> 0xdU)) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x38U] 
                                                 >> 0xcU)))) 
                                       | (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__56__KET____DOT__bi__DOT__FifSig) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x38U] 
                                                 >> 0xdU))) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x38U] 
                                                >> 0xcU)))) 
                                      | (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__56__KET____DOT__bi__DOT__FifSig) 
                                          & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [0x38U] 
                                             >> 0xdU)) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x38U] 
                                            >> 0xcU))))));
        bufp->chgCData(oldp+688,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__56__KET____DOT__bi__DOT__SecSig),4);
        bufp->chgBit(oldp+689,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x38U] >> 0xbU))));
        bufp->chgBit(oldp+690,((1U & ((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__56__KET____DOT__bi__DOT__ForSig) 
                                        >> 1U) & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__56__KET____DOT__bi__DOT__ForSig) 
                                                  | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                     [0x38U] 
                                                     >> 0xbU))) 
                                      | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__56__KET____DOT__bi__DOT__ForSig) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x38U] 
                                            >> 0xbU))))));
        bufp->chgBit(oldp+691,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x38U] >> 9U))));
        bufp->chgBit(oldp+692,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x38U] >> 8U))));
        bufp->chgBit(oldp+693,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x38U] >> 7U))));
        bufp->chgBit(oldp+694,((1U & (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                        [0x38U] >> 9U) 
                                       & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x38U] 
                                           >> 8U) | 
                                          (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x38U] 
                                           >> 7U))) 
                                      | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x38U] >> 8U) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x38U] 
                                            >> 7U))))));
        bufp->chgBit(oldp+695,((1U & ((((((~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                              [0x38U] 
                                              >> 9U)) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x38U] 
                                                >> 8U))) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x38U] 
                                            >> 7U)) 
                                        | (((~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x38U] 
                                                >> 9U)) 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                               [0x38U] 
                                               >> 8U)) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x38U] 
                                                 >> 7U)))) 
                                       | (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x38U] 
                                            >> 9U) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x38U] 
                                                 >> 8U))) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x38U] 
                                                >> 7U)))) 
                                      | (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x38U] 
                                           >> 9U) & 
                                          (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x38U] 
                                           >> 8U)) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x38U] 
                                            >> 7U))))));
        bufp->chgBit(oldp+696,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x38U] >> 0xaU))));
        bufp->chgBit(oldp+697,((1U & ((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__56__KET____DOT__bi__DOT__ThiSig) 
                                        >> 1U) & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__56__KET____DOT__bi__DOT__ThiSig) 
                                                  | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                     [0x38U] 
                                                     >> 0xaU))) 
                                      | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__56__KET____DOT__bi__DOT__ThiSig) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x38U] 
                                            >> 0xaU))))));
        bufp->chgBit(oldp+698,((1U & (((((IData)((0U 
                                                  == (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__56__KET____DOT__bi__DOT__ThiSig))) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x38U] 
                                            >> 0xaU)) 
                                        | ((IData)(
                                                   (1U 
                                                    == (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__56__KET____DOT__bi__DOT__ThiSig))) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x38U] 
                                                 >> 0xaU)))) 
                                       | ((IData)((2U 
                                                   == (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__56__KET____DOT__bi__DOT__ThiSig))) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x38U] 
                                                >> 0xaU)))) 
                                      | ((IData)((3U 
                                                  == (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__56__KET____DOT__bi__DOT__ThiSig))) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x38U] 
                                            >> 0xaU))))));
        bufp->chgBit(oldp+699,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x38U] >> 2U))));
        bufp->chgBit(oldp+700,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x38U] >> 1U))));
        bufp->chgBit(oldp+701,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                [0x38U])));
        bufp->chgBit(oldp+702,((1U & (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                        [0x38U] >> 2U) 
                                       & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x38U] 
                                           >> 1U) | 
                                          vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x38U])) 
                                      | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x38U] >> 1U) 
                                         & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x38U])))));
        bufp->chgBit(oldp+703,((1U & ((((((~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                              [0x38U] 
                                              >> 2U)) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x38U] 
                                                >> 1U))) 
                                         & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x38U]) | 
                                        (((~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                              [0x38U] 
                                              >> 2U)) 
                                          & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [0x38U] 
                                             >> 1U)) 
                                         & (~ vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x38U]))) 
                                       | (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x38U] 
                                            >> 2U) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x38U] 
                                                 >> 1U))) 
                                          & (~ vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [0x38U]))) 
                                      | (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x38U] 
                                           >> 2U) & 
                                          (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x38U] 
                                           >> 1U)) 
                                         & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x38U])))));
        bufp->chgBit(oldp+704,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x38U] >> 4U))));
        bufp->chgBit(oldp+705,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x38U] >> 3U))));
        bufp->chgBit(oldp+706,((1U & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__56__KET____DOT__bi__InData 
                                       & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x38U] 
                                           >> 4U) | 
                                          (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x38U] 
                                           >> 3U))) 
                                      | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x38U] >> 4U) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x38U] 
                                            >> 3U))))));
        bufp->chgBit(oldp+707,((1U & ((((((~ vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__56__KET____DOT__bi__InData) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x38U] 
                                                >> 4U))) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x38U] 
                                            >> 3U)) 
                                        | (((~ vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__56__KET____DOT__bi__InData) 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                               [0x38U] 
                                               >> 4U)) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x38U] 
                                                 >> 3U)))) 
                                       | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__56__KET____DOT__bi__InData 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x38U] 
                                                 >> 4U))) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x38U] 
                                                >> 3U)))) 
                                      | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__56__KET____DOT__bi__InData 
                                          & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [0x38U] 
                                             >> 4U)) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x38U] 
                                            >> 3U))))));
        bufp->chgBit(oldp+708,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x38U] >> 0xdU))));
        bufp->chgBit(oldp+709,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x38U] >> 0xcU))));
        bufp->chgBit(oldp+710,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__56__KET____DOT__bi__DOT__SecSig))));
        bufp->chgBit(oldp+711,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x38U] >> 6U))));
        bufp->chgBit(oldp+712,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x38U] >> 5U))));
        bufp->chgBit(oldp+713,((1U & (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__56__KET____DOT__bi__DOT__SecSig) 
                                       & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x38U] 
                                           >> 6U) | 
                                          (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x38U] 
                                           >> 5U))) 
                                      | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x38U] >> 6U) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x38U] 
                                            >> 5U))))));
        bufp->chgBit(oldp+714,((1U & ((((((~ (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__56__KET____DOT__bi__DOT__SecSig)) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x38U] 
                                                >> 6U))) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x38U] 
                                            >> 5U)) 
                                        | (((~ (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__56__KET____DOT__bi__DOT__SecSig)) 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                               [0x38U] 
                                               >> 6U)) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x38U] 
                                                 >> 5U)))) 
                                       | (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__56__KET____DOT__bi__DOT__SecSig) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x38U] 
                                                 >> 6U))) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x38U] 
                                                >> 5U)))) 
                                      | (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__56__KET____DOT__bi__DOT__SecSig) 
                                          & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [0x38U] 
                                             >> 6U)) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x38U] 
                                            >> 5U))))));
        bufp->chgBit(oldp+715,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__56__KET____DOT__bi__DOT__SecSig) 
                                      >> 3U))));
        bufp->chgBit(oldp+716,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__56__KET____DOT__bi__DOT__SecSig) 
                                      >> 2U))));
        bufp->chgBit(oldp+717,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__56__KET____DOT__bi__DOT__SecSig) 
                                      >> 1U))));
        bufp->chgBit(oldp+718,((1U & ((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__56__KET____DOT__bi__DOT__SecSig) 
                                        >> 3U) & (IData)(
                                                         (0U 
                                                          != 
                                                          (6U 
                                                           & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__56__KET____DOT__bi__DOT__SecSig))))) 
                                      | (IData)((6U 
                                                 == 
                                                 (6U 
                                                  & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__56__KET____DOT__bi__DOT__SecSig))))))));
        bufp->chgBit(oldp+719,((1U & ((((IData)((2U 
                                                 == 
                                                 (0xeU 
                                                  & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__56__KET____DOT__bi__DOT__SecSig)))) 
                                        | (IData)((4U 
                                                   == 
                                                   (0xeU 
                                                    & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__56__KET____DOT__bi__DOT__SecSig))))) 
                                       | (IData)((8U 
                                                  == 
                                                  (0xeU 
                                                   & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__56__KET____DOT__bi__DOT__SecSig))))) 
                                      | (IData)((0xeU 
                                                 == 
                                                 (0xeU 
                                                  & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__56__KET____DOT__bi__DOT__SecSig))))))));
        bufp->chgSData(oldp+720,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                 [0x39U]),14);
        bufp->chgSData(oldp+721,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellout__wallacefor__BRA__57__KET____DOT__bi__COut),14);
        bufp->chgBit(oldp+722,((1U & (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__57__KET____DOT__bi__DOT__FifSig) 
                                       & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x39U] 
                                           >> 0xdU) 
                                          | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [0x39U] 
                                             >> 0xcU))) 
                                      | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x39U] >> 0xdU) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x39U] 
                                            >> 0xcU))))));
        bufp->chgBit(oldp+723,((1U & ((((((~ (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__57__KET____DOT__bi__DOT__FifSig)) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x39U] 
                                                >> 0xdU))) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x39U] 
                                            >> 0xcU)) 
                                        | (((~ (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__57__KET____DOT__bi__DOT__FifSig)) 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                               [0x39U] 
                                               >> 0xdU)) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x39U] 
                                                 >> 0xcU)))) 
                                       | (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__57__KET____DOT__bi__DOT__FifSig) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x39U] 
                                                 >> 0xdU))) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x39U] 
                                                >> 0xcU)))) 
                                      | (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__57__KET____DOT__bi__DOT__FifSig) 
                                          & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [0x39U] 
                                             >> 0xdU)) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x39U] 
                                            >> 0xcU))))));
        bufp->chgCData(oldp+724,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__57__KET____DOT__bi__DOT__SecSig),4);
        bufp->chgBit(oldp+725,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x39U] >> 0xbU))));
        bufp->chgBit(oldp+726,((1U & ((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__57__KET____DOT__bi__DOT__ForSig) 
                                        >> 1U) & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__57__KET____DOT__bi__DOT__ForSig) 
                                                  | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                     [0x39U] 
                                                     >> 0xbU))) 
                                      | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__57__KET____DOT__bi__DOT__ForSig) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x39U] 
                                            >> 0xbU))))));
        bufp->chgBit(oldp+727,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x39U] >> 9U))));
        bufp->chgBit(oldp+728,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x39U] >> 8U))));
        bufp->chgBit(oldp+729,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x39U] >> 7U))));
        bufp->chgBit(oldp+730,((1U & (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                        [0x39U] >> 9U) 
                                       & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x39U] 
                                           >> 8U) | 
                                          (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x39U] 
                                           >> 7U))) 
                                      | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x39U] >> 8U) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x39U] 
                                            >> 7U))))));
        bufp->chgBit(oldp+731,((1U & ((((((~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                              [0x39U] 
                                              >> 9U)) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x39U] 
                                                >> 8U))) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x39U] 
                                            >> 7U)) 
                                        | (((~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x39U] 
                                                >> 9U)) 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                               [0x39U] 
                                               >> 8U)) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x39U] 
                                                 >> 7U)))) 
                                       | (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x39U] 
                                            >> 9U) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x39U] 
                                                 >> 8U))) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x39U] 
                                                >> 7U)))) 
                                      | (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x39U] 
                                           >> 9U) & 
                                          (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x39U] 
                                           >> 8U)) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x39U] 
                                            >> 7U))))));
        bufp->chgBit(oldp+732,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x39U] >> 0xaU))));
        bufp->chgBit(oldp+733,((1U & ((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__57__KET____DOT__bi__DOT__ThiSig) 
                                        >> 1U) & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__57__KET____DOT__bi__DOT__ThiSig) 
                                                  | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                     [0x39U] 
                                                     >> 0xaU))) 
                                      | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__57__KET____DOT__bi__DOT__ThiSig) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x39U] 
                                            >> 0xaU))))));
        bufp->chgBit(oldp+734,((1U & (((((IData)((0U 
                                                  == (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__57__KET____DOT__bi__DOT__ThiSig))) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x39U] 
                                            >> 0xaU)) 
                                        | ((IData)(
                                                   (1U 
                                                    == (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__57__KET____DOT__bi__DOT__ThiSig))) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x39U] 
                                                 >> 0xaU)))) 
                                       | ((IData)((2U 
                                                   == (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__57__KET____DOT__bi__DOT__ThiSig))) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x39U] 
                                                >> 0xaU)))) 
                                      | ((IData)((3U 
                                                  == (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__57__KET____DOT__bi__DOT__ThiSig))) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x39U] 
                                            >> 0xaU))))));
        bufp->chgBit(oldp+735,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x39U] >> 2U))));
        bufp->chgBit(oldp+736,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x39U] >> 1U))));
        bufp->chgBit(oldp+737,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                [0x39U])));
        bufp->chgBit(oldp+738,((1U & (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                        [0x39U] >> 2U) 
                                       & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x39U] 
                                           >> 1U) | 
                                          vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x39U])) 
                                      | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x39U] >> 1U) 
                                         & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x39U])))));
        bufp->chgBit(oldp+739,((1U & ((((((~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                              [0x39U] 
                                              >> 2U)) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x39U] 
                                                >> 1U))) 
                                         & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x39U]) | 
                                        (((~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                              [0x39U] 
                                              >> 2U)) 
                                          & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [0x39U] 
                                             >> 1U)) 
                                         & (~ vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x39U]))) 
                                       | (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x39U] 
                                            >> 2U) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x39U] 
                                                 >> 1U))) 
                                          & (~ vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [0x39U]))) 
                                      | (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x39U] 
                                           >> 2U) & 
                                          (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x39U] 
                                           >> 1U)) 
                                         & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x39U])))));
        bufp->chgBit(oldp+740,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x39U] >> 4U))));
        bufp->chgBit(oldp+741,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x39U] >> 3U))));
        bufp->chgBit(oldp+742,((1U & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__57__KET____DOT__bi__InData 
                                       & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x39U] 
                                           >> 4U) | 
                                          (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x39U] 
                                           >> 3U))) 
                                      | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x39U] >> 4U) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x39U] 
                                            >> 3U))))));
        bufp->chgBit(oldp+743,((1U & ((((((~ vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__57__KET____DOT__bi__InData) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x39U] 
                                                >> 4U))) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x39U] 
                                            >> 3U)) 
                                        | (((~ vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__57__KET____DOT__bi__InData) 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                               [0x39U] 
                                               >> 4U)) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x39U] 
                                                 >> 3U)))) 
                                       | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__57__KET____DOT__bi__InData 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x39U] 
                                                 >> 4U))) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x39U] 
                                                >> 3U)))) 
                                      | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__57__KET____DOT__bi__InData 
                                          & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [0x39U] 
                                             >> 4U)) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x39U] 
                                            >> 3U))))));
        bufp->chgBit(oldp+744,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x39U] >> 0xdU))));
        bufp->chgBit(oldp+745,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x39U] >> 0xcU))));
        bufp->chgBit(oldp+746,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__57__KET____DOT__bi__DOT__SecSig))));
        bufp->chgBit(oldp+747,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x39U] >> 6U))));
        bufp->chgBit(oldp+748,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x39U] >> 5U))));
        bufp->chgBit(oldp+749,((1U & (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__57__KET____DOT__bi__DOT__SecSig) 
                                       & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x39U] 
                                           >> 6U) | 
                                          (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x39U] 
                                           >> 5U))) 
                                      | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x39U] >> 6U) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x39U] 
                                            >> 5U))))));
        bufp->chgBit(oldp+750,((1U & ((((((~ (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__57__KET____DOT__bi__DOT__SecSig)) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x39U] 
                                                >> 6U))) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x39U] 
                                            >> 5U)) 
                                        | (((~ (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__57__KET____DOT__bi__DOT__SecSig)) 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                               [0x39U] 
                                               >> 6U)) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x39U] 
                                                 >> 5U)))) 
                                       | (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__57__KET____DOT__bi__DOT__SecSig) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x39U] 
                                                 >> 6U))) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x39U] 
                                                >> 5U)))) 
                                      | (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__57__KET____DOT__bi__DOT__SecSig) 
                                          & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [0x39U] 
                                             >> 6U)) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x39U] 
                                            >> 5U))))));
        bufp->chgBit(oldp+751,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__57__KET____DOT__bi__DOT__SecSig) 
                                      >> 3U))));
        bufp->chgBit(oldp+752,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__57__KET____DOT__bi__DOT__SecSig) 
                                      >> 2U))));
        bufp->chgBit(oldp+753,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__57__KET____DOT__bi__DOT__SecSig) 
                                      >> 1U))));
        bufp->chgBit(oldp+754,((1U & ((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__57__KET____DOT__bi__DOT__SecSig) 
                                        >> 3U) & (IData)(
                                                         (0U 
                                                          != 
                                                          (6U 
                                                           & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__57__KET____DOT__bi__DOT__SecSig))))) 
                                      | (IData)((6U 
                                                 == 
                                                 (6U 
                                                  & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__57__KET____DOT__bi__DOT__SecSig))))))));
        bufp->chgBit(oldp+755,((1U & ((((IData)((2U 
                                                 == 
                                                 (0xeU 
                                                  & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__57__KET____DOT__bi__DOT__SecSig)))) 
                                        | (IData)((4U 
                                                   == 
                                                   (0xeU 
                                                    & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__57__KET____DOT__bi__DOT__SecSig))))) 
                                       | (IData)((8U 
                                                  == 
                                                  (0xeU 
                                                   & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__57__KET____DOT__bi__DOT__SecSig))))) 
                                      | (IData)((0xeU 
                                                 == 
                                                 (0xeU 
                                                  & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__57__KET____DOT__bi__DOT__SecSig))))))));
        bufp->chgSData(oldp+756,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                 [0x3aU]),14);
        bufp->chgSData(oldp+757,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellout__wallacefor__BRA__58__KET____DOT__bi__COut),14);
        bufp->chgBit(oldp+758,((1U & (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__58__KET____DOT__bi__DOT__FifSig) 
                                       & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x3aU] 
                                           >> 0xdU) 
                                          | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [0x3aU] 
                                             >> 0xcU))) 
                                      | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x3aU] >> 0xdU) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x3aU] 
                                            >> 0xcU))))));
        bufp->chgBit(oldp+759,((1U & ((((((~ (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__58__KET____DOT__bi__DOT__FifSig)) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x3aU] 
                                                >> 0xdU))) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x3aU] 
                                            >> 0xcU)) 
                                        | (((~ (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__58__KET____DOT__bi__DOT__FifSig)) 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                               [0x3aU] 
                                               >> 0xdU)) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x3aU] 
                                                 >> 0xcU)))) 
                                       | (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__58__KET____DOT__bi__DOT__FifSig) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x3aU] 
                                                 >> 0xdU))) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x3aU] 
                                                >> 0xcU)))) 
                                      | (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__58__KET____DOT__bi__DOT__FifSig) 
                                          & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [0x3aU] 
                                             >> 0xdU)) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x3aU] 
                                            >> 0xcU))))));
        bufp->chgCData(oldp+760,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__58__KET____DOT__bi__DOT__SecSig),4);
        bufp->chgBit(oldp+761,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x3aU] >> 0xbU))));
        bufp->chgBit(oldp+762,((1U & ((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__58__KET____DOT__bi__DOT__ForSig) 
                                        >> 1U) & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__58__KET____DOT__bi__DOT__ForSig) 
                                                  | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                     [0x3aU] 
                                                     >> 0xbU))) 
                                      | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__58__KET____DOT__bi__DOT__ForSig) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x3aU] 
                                            >> 0xbU))))));
        bufp->chgBit(oldp+763,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x3aU] >> 9U))));
        bufp->chgBit(oldp+764,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x3aU] >> 8U))));
        bufp->chgBit(oldp+765,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x3aU] >> 7U))));
        bufp->chgBit(oldp+766,((1U & (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                        [0x3aU] >> 9U) 
                                       & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x3aU] 
                                           >> 8U) | 
                                          (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x3aU] 
                                           >> 7U))) 
                                      | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x3aU] >> 8U) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x3aU] 
                                            >> 7U))))));
        bufp->chgBit(oldp+767,((1U & ((((((~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                              [0x3aU] 
                                              >> 9U)) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x3aU] 
                                                >> 8U))) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x3aU] 
                                            >> 7U)) 
                                        | (((~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x3aU] 
                                                >> 9U)) 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                               [0x3aU] 
                                               >> 8U)) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x3aU] 
                                                 >> 7U)))) 
                                       | (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x3aU] 
                                            >> 9U) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x3aU] 
                                                 >> 8U))) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x3aU] 
                                                >> 7U)))) 
                                      | (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x3aU] 
                                           >> 9U) & 
                                          (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x3aU] 
                                           >> 8U)) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x3aU] 
                                            >> 7U))))));
        bufp->chgBit(oldp+768,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x3aU] >> 0xaU))));
        bufp->chgBit(oldp+769,((1U & ((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__58__KET____DOT__bi__DOT__ThiSig) 
                                        >> 1U) & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__58__KET____DOT__bi__DOT__ThiSig) 
                                                  | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                     [0x3aU] 
                                                     >> 0xaU))) 
                                      | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__58__KET____DOT__bi__DOT__ThiSig) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x3aU] 
                                            >> 0xaU))))));
        bufp->chgBit(oldp+770,((1U & (((((IData)((0U 
                                                  == (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__58__KET____DOT__bi__DOT__ThiSig))) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x3aU] 
                                            >> 0xaU)) 
                                        | ((IData)(
                                                   (1U 
                                                    == (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__58__KET____DOT__bi__DOT__ThiSig))) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x3aU] 
                                                 >> 0xaU)))) 
                                       | ((IData)((2U 
                                                   == (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__58__KET____DOT__bi__DOT__ThiSig))) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x3aU] 
                                                >> 0xaU)))) 
                                      | ((IData)((3U 
                                                  == (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__58__KET____DOT__bi__DOT__ThiSig))) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x3aU] 
                                            >> 0xaU))))));
        bufp->chgBit(oldp+771,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x3aU] >> 2U))));
        bufp->chgBit(oldp+772,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x3aU] >> 1U))));
        bufp->chgBit(oldp+773,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                [0x3aU])));
        bufp->chgBit(oldp+774,((1U & (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                        [0x3aU] >> 2U) 
                                       & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x3aU] 
                                           >> 1U) | 
                                          vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x3aU])) 
                                      | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x3aU] >> 1U) 
                                         & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x3aU])))));
        bufp->chgBit(oldp+775,((1U & ((((((~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                              [0x3aU] 
                                              >> 2U)) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x3aU] 
                                                >> 1U))) 
                                         & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x3aU]) | 
                                        (((~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                              [0x3aU] 
                                              >> 2U)) 
                                          & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [0x3aU] 
                                             >> 1U)) 
                                         & (~ vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x3aU]))) 
                                       | (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x3aU] 
                                            >> 2U) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x3aU] 
                                                 >> 1U))) 
                                          & (~ vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [0x3aU]))) 
                                      | (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x3aU] 
                                           >> 2U) & 
                                          (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x3aU] 
                                           >> 1U)) 
                                         & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x3aU])))));
    }
}

void Vsimu_top___024root__trace_chg_sub_9(Vsimu_top___024root* vlSelf, VerilatedFst::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vsimu_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsimu_top___024root__trace_chg_sub_9\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 12676);
    // Body
    if (VL_UNLIKELY((vlSelf->__Vm_traceActivity[1U] 
                     | vlSelf->__Vm_traceActivity[2U]))) {
        bufp->chgBit(oldp+0,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                    [0x3aU] >> 4U))));
        bufp->chgBit(oldp+1,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                    [0x3aU] >> 3U))));
        bufp->chgBit(oldp+2,((1U & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__58__KET____DOT__bi__InData 
                                     & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x3aU] >> 4U) 
                                        | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x3aU] 
                                           >> 3U))) 
                                    | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                        [0x3aU] >> 4U) 
                                       & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x3aU] >> 3U))))));
        bufp->chgBit(oldp+3,((1U & ((((((~ vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__58__KET____DOT__bi__InData) 
                                        & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                              [0x3aU] 
                                              >> 4U))) 
                                       & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x3aU] >> 3U)) 
                                      | (((~ vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__58__KET____DOT__bi__InData) 
                                          & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [0x3aU] 
                                             >> 4U)) 
                                         & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                               [0x3aU] 
                                               >> 3U)))) 
                                     | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__58__KET____DOT__bi__InData 
                                         & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                               [0x3aU] 
                                               >> 4U))) 
                                        & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                              [0x3aU] 
                                              >> 3U)))) 
                                    | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__58__KET____DOT__bi__InData 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x3aU] 
                                           >> 4U)) 
                                       & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x3aU] >> 3U))))));
        bufp->chgBit(oldp+4,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                    [0x3aU] >> 0xdU))));
        bufp->chgBit(oldp+5,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                    [0x3aU] >> 0xcU))));
        bufp->chgBit(oldp+6,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__58__KET____DOT__bi__DOT__SecSig))));
        bufp->chgBit(oldp+7,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                    [0x3aU] >> 6U))));
        bufp->chgBit(oldp+8,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                    [0x3aU] >> 5U))));
        bufp->chgBit(oldp+9,((1U & (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__58__KET____DOT__bi__DOT__SecSig) 
                                     & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x3aU] >> 6U) 
                                        | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x3aU] 
                                           >> 5U))) 
                                    | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                        [0x3aU] >> 6U) 
                                       & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x3aU] >> 5U))))));
        bufp->chgBit(oldp+10,((1U & ((((((~ (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__58__KET____DOT__bi__DOT__SecSig)) 
                                         & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                               [0x3aU] 
                                               >> 6U))) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x3aU] 
                                           >> 5U)) 
                                       | (((~ (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__58__KET____DOT__bi__DOT__SecSig)) 
                                           & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                              [0x3aU] 
                                              >> 6U)) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x3aU] 
                                                >> 5U)))) 
                                      | (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__58__KET____DOT__bi__DOT__SecSig) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x3aU] 
                                                >> 6U))) 
                                         & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                               [0x3aU] 
                                               >> 5U)))) 
                                     | (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__58__KET____DOT__bi__DOT__SecSig) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x3aU] 
                                            >> 6U)) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x3aU] 
                                           >> 5U))))));
        bufp->chgBit(oldp+11,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__58__KET____DOT__bi__DOT__SecSig) 
                                     >> 3U))));
        bufp->chgBit(oldp+12,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__58__KET____DOT__bi__DOT__SecSig) 
                                     >> 2U))));
        bufp->chgBit(oldp+13,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__58__KET____DOT__bi__DOT__SecSig) 
                                     >> 1U))));
        bufp->chgBit(oldp+14,((1U & ((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__58__KET____DOT__bi__DOT__SecSig) 
                                       >> 3U) & (IData)(
                                                        (0U 
                                                         != 
                                                         (6U 
                                                          & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__58__KET____DOT__bi__DOT__SecSig))))) 
                                     | (IData)((6U 
                                                == 
                                                (6U 
                                                 & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__58__KET____DOT__bi__DOT__SecSig))))))));
        bufp->chgBit(oldp+15,((1U & ((((IData)((2U 
                                                == 
                                                (0xeU 
                                                 & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__58__KET____DOT__bi__DOT__SecSig)))) 
                                       | (IData)((4U 
                                                  == 
                                                  (0xeU 
                                                   & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__58__KET____DOT__bi__DOT__SecSig))))) 
                                      | (IData)((8U 
                                                 == 
                                                 (0xeU 
                                                  & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__58__KET____DOT__bi__DOT__SecSig))))) 
                                     | (IData)((0xeU 
                                                == 
                                                (0xeU 
                                                 & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__58__KET____DOT__bi__DOT__SecSig))))))));
        bufp->chgSData(oldp+16,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                [0x3bU]),14);
        bufp->chgSData(oldp+17,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellout__wallacefor__BRA__59__KET____DOT__bi__COut),14);
        bufp->chgBit(oldp+18,((1U & (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__59__KET____DOT__bi__DOT__FifSig) 
                                      & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x3bU] >> 0xdU) 
                                         | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x3bU] 
                                            >> 0xcU))) 
                                     | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x3bU] >> 0xdU) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x3bU] 
                                           >> 0xcU))))));
        bufp->chgBit(oldp+19,((1U & ((((((~ (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__59__KET____DOT__bi__DOT__FifSig)) 
                                         & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                               [0x3bU] 
                                               >> 0xdU))) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x3bU] 
                                           >> 0xcU)) 
                                       | (((~ (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__59__KET____DOT__bi__DOT__FifSig)) 
                                           & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                              [0x3bU] 
                                              >> 0xdU)) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x3bU] 
                                                >> 0xcU)))) 
                                      | (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__59__KET____DOT__bi__DOT__FifSig) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x3bU] 
                                                >> 0xdU))) 
                                         & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                               [0x3bU] 
                                               >> 0xcU)))) 
                                     | (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__59__KET____DOT__bi__DOT__FifSig) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x3bU] 
                                            >> 0xdU)) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x3bU] 
                                           >> 0xcU))))));
        bufp->chgCData(oldp+20,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__59__KET____DOT__bi__DOT__SecSig),4);
        bufp->chgBit(oldp+21,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x3bU] >> 0xbU))));
        bufp->chgBit(oldp+22,((1U & ((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__59__KET____DOT__bi__DOT__ForSig) 
                                       >> 1U) & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__59__KET____DOT__bi__DOT__ForSig) 
                                                 | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                    [0x3bU] 
                                                    >> 0xbU))) 
                                     | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__59__KET____DOT__bi__DOT__ForSig) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x3bU] 
                                           >> 0xbU))))));
        bufp->chgBit(oldp+23,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x3bU] >> 9U))));
        bufp->chgBit(oldp+24,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x3bU] >> 8U))));
        bufp->chgBit(oldp+25,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x3bU] >> 7U))));
        bufp->chgBit(oldp+26,((1U & (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                       [0x3bU] >> 9U) 
                                      & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x3bU] >> 8U) 
                                         | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x3bU] 
                                            >> 7U))) 
                                     | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x3bU] >> 8U) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x3bU] 
                                           >> 7U))))));
        bufp->chgBit(oldp+27,((1U & ((((((~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [0x3bU] 
                                             >> 9U)) 
                                         & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                               [0x3bU] 
                                               >> 8U))) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x3bU] 
                                           >> 7U)) 
                                       | (((~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                               [0x3bU] 
                                               >> 9U)) 
                                           & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                              [0x3bU] 
                                              >> 8U)) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x3bU] 
                                                >> 7U)))) 
                                      | (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x3bU] 
                                           >> 9U) & 
                                          (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                              [0x3bU] 
                                              >> 8U))) 
                                         & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                               [0x3bU] 
                                               >> 7U)))) 
                                     | (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x3bU] >> 9U) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x3bU] 
                                            >> 8U)) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x3bU] 
                                           >> 7U))))));
        bufp->chgBit(oldp+28,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x3bU] >> 0xaU))));
        bufp->chgBit(oldp+29,((1U & ((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__59__KET____DOT__bi__DOT__ThiSig) 
                                       >> 1U) & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__59__KET____DOT__bi__DOT__ThiSig) 
                                                 | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                    [0x3bU] 
                                                    >> 0xaU))) 
                                     | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__59__KET____DOT__bi__DOT__ThiSig) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x3bU] 
                                           >> 0xaU))))));
        bufp->chgBit(oldp+30,((1U & (((((IData)((0U 
                                                 == (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__59__KET____DOT__bi__DOT__ThiSig))) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x3bU] 
                                           >> 0xaU)) 
                                       | ((IData)((1U 
                                                   == (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__59__KET____DOT__bi__DOT__ThiSig))) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x3bU] 
                                                >> 0xaU)))) 
                                      | ((IData)((2U 
                                                  == (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__59__KET____DOT__bi__DOT__ThiSig))) 
                                         & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                               [0x3bU] 
                                               >> 0xaU)))) 
                                     | ((IData)((3U 
                                                 == (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__59__KET____DOT__bi__DOT__ThiSig))) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x3bU] 
                                           >> 0xaU))))));
        bufp->chgBit(oldp+31,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x3bU] >> 2U))));
        bufp->chgBit(oldp+32,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x3bU] >> 1U))));
        bufp->chgBit(oldp+33,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                               [0x3bU])));
        bufp->chgBit(oldp+34,((1U & (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                       [0x3bU] >> 2U) 
                                      & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x3bU] >> 1U) 
                                         | vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x3bU])) 
                                     | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x3bU] >> 1U) 
                                        & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                        [0x3bU])))));
        bufp->chgBit(oldp+35,((1U & ((((((~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [0x3bU] 
                                             >> 2U)) 
                                         & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                               [0x3bU] 
                                               >> 1U))) 
                                        & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                        [0x3bU]) | 
                                       (((~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [0x3bU] 
                                             >> 2U)) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x3bU] 
                                            >> 1U)) 
                                        & (~ vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x3bU]))) 
                                      | (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x3bU] 
                                           >> 2U) & 
                                          (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                              [0x3bU] 
                                              >> 1U))) 
                                         & (~ vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x3bU]))) 
                                     | (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x3bU] >> 2U) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x3bU] 
                                            >> 1U)) 
                                        & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                        [0x3bU])))));
        bufp->chgBit(oldp+36,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x3bU] >> 4U))));
        bufp->chgBit(oldp+37,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x3bU] >> 3U))));
        bufp->chgBit(oldp+38,((1U & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__59__KET____DOT__bi__InData 
                                      & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x3bU] >> 4U) 
                                         | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x3bU] 
                                            >> 3U))) 
                                     | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x3bU] >> 4U) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x3bU] 
                                           >> 3U))))));
        bufp->chgBit(oldp+39,((1U & ((((((~ vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__59__KET____DOT__bi__InData) 
                                         & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                               [0x3bU] 
                                               >> 4U))) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x3bU] 
                                           >> 3U)) 
                                       | (((~ vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__59__KET____DOT__bi__InData) 
                                           & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                              [0x3bU] 
                                              >> 4U)) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x3bU] 
                                                >> 3U)))) 
                                      | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__59__KET____DOT__bi__InData 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x3bU] 
                                                >> 4U))) 
                                         & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                               [0x3bU] 
                                               >> 3U)))) 
                                     | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__59__KET____DOT__bi__InData 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x3bU] 
                                            >> 4U)) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x3bU] 
                                           >> 3U))))));
        bufp->chgBit(oldp+40,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x3bU] >> 0xdU))));
        bufp->chgBit(oldp+41,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x3bU] >> 0xcU))));
        bufp->chgBit(oldp+42,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__59__KET____DOT__bi__DOT__SecSig))));
        bufp->chgBit(oldp+43,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x3bU] >> 6U))));
        bufp->chgBit(oldp+44,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x3bU] >> 5U))));
        bufp->chgBit(oldp+45,((1U & (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__59__KET____DOT__bi__DOT__SecSig) 
                                      & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x3bU] >> 6U) 
                                         | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x3bU] 
                                            >> 5U))) 
                                     | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x3bU] >> 6U) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x3bU] 
                                           >> 5U))))));
        bufp->chgBit(oldp+46,((1U & ((((((~ (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__59__KET____DOT__bi__DOT__SecSig)) 
                                         & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                               [0x3bU] 
                                               >> 6U))) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x3bU] 
                                           >> 5U)) 
                                       | (((~ (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__59__KET____DOT__bi__DOT__SecSig)) 
                                           & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                              [0x3bU] 
                                              >> 6U)) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x3bU] 
                                                >> 5U)))) 
                                      | (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__59__KET____DOT__bi__DOT__SecSig) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x3bU] 
                                                >> 6U))) 
                                         & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                               [0x3bU] 
                                               >> 5U)))) 
                                     | (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__59__KET____DOT__bi__DOT__SecSig) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x3bU] 
                                            >> 6U)) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x3bU] 
                                           >> 5U))))));
        bufp->chgBit(oldp+47,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__59__KET____DOT__bi__DOT__SecSig) 
                                     >> 3U))));
        bufp->chgBit(oldp+48,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__59__KET____DOT__bi__DOT__SecSig) 
                                     >> 2U))));
        bufp->chgBit(oldp+49,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__59__KET____DOT__bi__DOT__SecSig) 
                                     >> 1U))));
        bufp->chgBit(oldp+50,((1U & ((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__59__KET____DOT__bi__DOT__SecSig) 
                                       >> 3U) & (IData)(
                                                        (0U 
                                                         != 
                                                         (6U 
                                                          & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__59__KET____DOT__bi__DOT__SecSig))))) 
                                     | (IData)((6U 
                                                == 
                                                (6U 
                                                 & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__59__KET____DOT__bi__DOT__SecSig))))))));
        bufp->chgBit(oldp+51,((1U & ((((IData)((2U 
                                                == 
                                                (0xeU 
                                                 & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__59__KET____DOT__bi__DOT__SecSig)))) 
                                       | (IData)((4U 
                                                  == 
                                                  (0xeU 
                                                   & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__59__KET____DOT__bi__DOT__SecSig))))) 
                                      | (IData)((8U 
                                                 == 
                                                 (0xeU 
                                                  & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__59__KET____DOT__bi__DOT__SecSig))))) 
                                     | (IData)((0xeU 
                                                == 
                                                (0xeU 
                                                 & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__59__KET____DOT__bi__DOT__SecSig))))))));
        bufp->chgSData(oldp+52,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                [5U]),14);
        bufp->chgSData(oldp+53,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellout__wallacefor__BRA__5__KET____DOT__bi__COut),14);
        bufp->chgBit(oldp+54,((1U & (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__5__KET____DOT__bi__DOT__FifSig) 
                                      & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [5U] >> 0xdU) 
                                         | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [5U] >> 0xcU))) 
                                     | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [5U] >> 0xdU) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [5U] >> 0xcU))))));
        bufp->chgBit(oldp+55,((1U & ((((((~ (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__5__KET____DOT__bi__DOT__FifSig)) 
                                         & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                               [5U] 
                                               >> 0xdU))) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [5U] >> 0xcU)) 
                                       | (((~ (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__5__KET____DOT__bi__DOT__FifSig)) 
                                           & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                              [5U] 
                                              >> 0xdU)) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [5U] 
                                                >> 0xcU)))) 
                                      | (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__5__KET____DOT__bi__DOT__FifSig) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [5U] 
                                                >> 0xdU))) 
                                         & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                               [5U] 
                                               >> 0xcU)))) 
                                     | (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__5__KET____DOT__bi__DOT__FifSig) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [5U] >> 0xdU)) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [5U] >> 0xcU))))));
        bufp->chgCData(oldp+56,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__5__KET____DOT__bi__DOT__SecSig),4);
        bufp->chgBit(oldp+57,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [5U] >> 0xbU))));
        bufp->chgBit(oldp+58,((1U & ((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__5__KET____DOT__bi__DOT__ForSig) 
                                       >> 1U) & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__5__KET____DOT__bi__DOT__ForSig) 
                                                 | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                    [5U] 
                                                    >> 0xbU))) 
                                     | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__5__KET____DOT__bi__DOT__ForSig) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [5U] >> 0xbU))))));
        bufp->chgBit(oldp+59,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [5U] >> 9U))));
        bufp->chgBit(oldp+60,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [5U] >> 8U))));
        bufp->chgBit(oldp+61,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [5U] >> 7U))));
        bufp->chgBit(oldp+62,((1U & (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                       [5U] >> 9U) 
                                      & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [5U] >> 8U) 
                                         | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [5U] >> 7U))) 
                                     | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [5U] >> 8U) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [5U] >> 7U))))));
        bufp->chgBit(oldp+63,((1U & ((((((~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [5U] >> 9U)) 
                                         & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                               [5U] 
                                               >> 8U))) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [5U] >> 7U)) 
                                       | (((~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                               [5U] 
                                               >> 9U)) 
                                           & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                              [5U] 
                                              >> 8U)) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [5U] 
                                                >> 7U)))) 
                                      | (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [5U] >> 9U) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [5U] 
                                                >> 8U))) 
                                         & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                               [5U] 
                                               >> 7U)))) 
                                     | (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [5U] >> 9U) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [5U] >> 8U)) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [5U] >> 7U))))));
        bufp->chgBit(oldp+64,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [5U] >> 0xaU))));
        bufp->chgBit(oldp+65,((1U & ((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__5__KET____DOT__bi__DOT__ThiSig) 
                                       >> 1U) & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__5__KET____DOT__bi__DOT__ThiSig) 
                                                 | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                    [5U] 
                                                    >> 0xaU))) 
                                     | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__5__KET____DOT__bi__DOT__ThiSig) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [5U] >> 0xaU))))));
        bufp->chgBit(oldp+66,((1U & (((((IData)((0U 
                                                 == (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__5__KET____DOT__bi__DOT__ThiSig))) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [5U] >> 0xaU)) 
                                       | ((IData)((1U 
                                                   == (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__5__KET____DOT__bi__DOT__ThiSig))) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [5U] 
                                                >> 0xaU)))) 
                                      | ((IData)((2U 
                                                  == (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__5__KET____DOT__bi__DOT__ThiSig))) 
                                         & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                               [5U] 
                                               >> 0xaU)))) 
                                     | ((IData)((3U 
                                                 == (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__5__KET____DOT__bi__DOT__ThiSig))) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [5U] >> 0xaU))))));
        bufp->chgBit(oldp+67,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [5U] >> 2U))));
        bufp->chgBit(oldp+68,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [5U] >> 1U))));
        bufp->chgBit(oldp+69,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                               [5U])));
        bufp->chgBit(oldp+70,((1U & (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                       [5U] >> 2U) 
                                      & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [5U] >> 1U) 
                                         | vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [5U])) | (
                                                   (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                    [5U] 
                                                    >> 1U) 
                                                   & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                   [5U])))));
        bufp->chgBit(oldp+71,((1U & ((((((~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [5U] >> 2U)) 
                                         & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                               [5U] 
                                               >> 1U))) 
                                        & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                        [5U]) | (((~ 
                                                   (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                    [5U] 
                                                    >> 2U)) 
                                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                     [5U] 
                                                     >> 1U)) 
                                                 & (~ 
                                                    vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                    [5U]))) 
                                      | (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [5U] >> 2U) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [5U] 
                                                >> 1U))) 
                                         & (~ vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [5U]))) 
                                     | (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [5U] >> 2U) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [5U] >> 1U)) 
                                        & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                        [5U])))));
        bufp->chgBit(oldp+72,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [5U] >> 4U))));
        bufp->chgBit(oldp+73,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [5U] >> 3U))));
        bufp->chgBit(oldp+74,((1U & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__5__KET____DOT__bi__InData 
                                      & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [5U] >> 4U) 
                                         | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [5U] >> 3U))) 
                                     | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [5U] >> 4U) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [5U] >> 3U))))));
        bufp->chgBit(oldp+75,((1U & ((((((~ vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__5__KET____DOT__bi__InData) 
                                         & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                               [5U] 
                                               >> 4U))) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [5U] >> 3U)) 
                                       | (((~ vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__5__KET____DOT__bi__InData) 
                                           & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                              [5U] 
                                              >> 4U)) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [5U] 
                                                >> 3U)))) 
                                      | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__5__KET____DOT__bi__InData 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [5U] 
                                                >> 4U))) 
                                         & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                               [5U] 
                                               >> 3U)))) 
                                     | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__5__KET____DOT__bi__InData 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [5U] >> 4U)) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [5U] >> 3U))))));
        bufp->chgBit(oldp+76,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [5U] >> 0xdU))));
        bufp->chgBit(oldp+77,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [5U] >> 0xcU))));
        bufp->chgBit(oldp+78,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__5__KET____DOT__bi__DOT__SecSig))));
        bufp->chgBit(oldp+79,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [5U] >> 6U))));
        bufp->chgBit(oldp+80,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [5U] >> 5U))));
        bufp->chgBit(oldp+81,((1U & (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__5__KET____DOT__bi__DOT__SecSig) 
                                      & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [5U] >> 6U) 
                                         | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [5U] >> 5U))) 
                                     | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [5U] >> 6U) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [5U] >> 5U))))));
        bufp->chgBit(oldp+82,((1U & ((((((~ (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__5__KET____DOT__bi__DOT__SecSig)) 
                                         & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                               [5U] 
                                               >> 6U))) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [5U] >> 5U)) 
                                       | (((~ (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__5__KET____DOT__bi__DOT__SecSig)) 
                                           & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                              [5U] 
                                              >> 6U)) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [5U] 
                                                >> 5U)))) 
                                      | (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__5__KET____DOT__bi__DOT__SecSig) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [5U] 
                                                >> 6U))) 
                                         & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                               [5U] 
                                               >> 5U)))) 
                                     | (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__5__KET____DOT__bi__DOT__SecSig) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [5U] >> 6U)) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [5U] >> 5U))))));
        bufp->chgBit(oldp+83,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__5__KET____DOT__bi__DOT__SecSig) 
                                     >> 3U))));
        bufp->chgBit(oldp+84,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__5__KET____DOT__bi__DOT__SecSig) 
                                     >> 2U))));
        bufp->chgBit(oldp+85,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__5__KET____DOT__bi__DOT__SecSig) 
                                     >> 1U))));
        bufp->chgBit(oldp+86,((1U & ((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__5__KET____DOT__bi__DOT__SecSig) 
                                       >> 3U) & (IData)(
                                                        (0U 
                                                         != 
                                                         (6U 
                                                          & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__5__KET____DOT__bi__DOT__SecSig))))) 
                                     | (IData)((6U 
                                                == 
                                                (6U 
                                                 & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__5__KET____DOT__bi__DOT__SecSig))))))));
        bufp->chgBit(oldp+87,((1U & ((((IData)((2U 
                                                == 
                                                (0xeU 
                                                 & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__5__KET____DOT__bi__DOT__SecSig)))) 
                                       | (IData)((4U 
                                                  == 
                                                  (0xeU 
                                                   & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__5__KET____DOT__bi__DOT__SecSig))))) 
                                      | (IData)((8U 
                                                 == 
                                                 (0xeU 
                                                  & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__5__KET____DOT__bi__DOT__SecSig))))) 
                                     | (IData)((0xeU 
                                                == 
                                                (0xeU 
                                                 & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__5__KET____DOT__bi__DOT__SecSig))))))));
        bufp->chgSData(oldp+88,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                [0x3cU]),14);
        bufp->chgSData(oldp+89,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellout__wallacefor__BRA__60__KET____DOT__bi__COut),14);
        bufp->chgBit(oldp+90,((1U & (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__60__KET____DOT__bi__DOT__FifSig) 
                                      & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x3cU] >> 0xdU) 
                                         | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x3cU] 
                                            >> 0xcU))) 
                                     | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x3cU] >> 0xdU) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x3cU] 
                                           >> 0xcU))))));
        bufp->chgBit(oldp+91,((1U & ((((((~ (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__60__KET____DOT__bi__DOT__FifSig)) 
                                         & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                               [0x3cU] 
                                               >> 0xdU))) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x3cU] 
                                           >> 0xcU)) 
                                       | (((~ (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__60__KET____DOT__bi__DOT__FifSig)) 
                                           & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                              [0x3cU] 
                                              >> 0xdU)) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x3cU] 
                                                >> 0xcU)))) 
                                      | (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__60__KET____DOT__bi__DOT__FifSig) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x3cU] 
                                                >> 0xdU))) 
                                         & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                               [0x3cU] 
                                               >> 0xcU)))) 
                                     | (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__60__KET____DOT__bi__DOT__FifSig) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x3cU] 
                                            >> 0xdU)) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x3cU] 
                                           >> 0xcU))))));
        bufp->chgCData(oldp+92,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__60__KET____DOT__bi__DOT__SecSig),4);
        bufp->chgBit(oldp+93,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x3cU] >> 0xbU))));
        bufp->chgBit(oldp+94,((1U & ((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__60__KET____DOT__bi__DOT__ForSig) 
                                       >> 1U) & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__60__KET____DOT__bi__DOT__ForSig) 
                                                 | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                    [0x3cU] 
                                                    >> 0xbU))) 
                                     | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__60__KET____DOT__bi__DOT__ForSig) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x3cU] 
                                           >> 0xbU))))));
        bufp->chgBit(oldp+95,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x3cU] >> 9U))));
        bufp->chgBit(oldp+96,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x3cU] >> 8U))));
        bufp->chgBit(oldp+97,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x3cU] >> 7U))));
        bufp->chgBit(oldp+98,((1U & (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                       [0x3cU] >> 9U) 
                                      & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x3cU] >> 8U) 
                                         | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x3cU] 
                                            >> 7U))) 
                                     | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x3cU] >> 8U) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x3cU] 
                                           >> 7U))))));
        bufp->chgBit(oldp+99,((1U & ((((((~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [0x3cU] 
                                             >> 9U)) 
                                         & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                               [0x3cU] 
                                               >> 8U))) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x3cU] 
                                           >> 7U)) 
                                       | (((~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                               [0x3cU] 
                                               >> 9U)) 
                                           & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                              [0x3cU] 
                                              >> 8U)) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x3cU] 
                                                >> 7U)))) 
                                      | (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x3cU] 
                                           >> 9U) & 
                                          (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                              [0x3cU] 
                                              >> 8U))) 
                                         & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                               [0x3cU] 
                                               >> 7U)))) 
                                     | (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x3cU] >> 9U) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x3cU] 
                                            >> 8U)) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x3cU] 
                                           >> 7U))))));
        bufp->chgBit(oldp+100,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x3cU] >> 0xaU))));
        bufp->chgBit(oldp+101,((1U & ((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__60__KET____DOT__bi__DOT__ThiSig) 
                                        >> 1U) & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__60__KET____DOT__bi__DOT__ThiSig) 
                                                  | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                     [0x3cU] 
                                                     >> 0xaU))) 
                                      | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__60__KET____DOT__bi__DOT__ThiSig) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x3cU] 
                                            >> 0xaU))))));
        bufp->chgBit(oldp+102,((1U & (((((IData)((0U 
                                                  == (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__60__KET____DOT__bi__DOT__ThiSig))) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x3cU] 
                                            >> 0xaU)) 
                                        | ((IData)(
                                                   (1U 
                                                    == (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__60__KET____DOT__bi__DOT__ThiSig))) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x3cU] 
                                                 >> 0xaU)))) 
                                       | ((IData)((2U 
                                                   == (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__60__KET____DOT__bi__DOT__ThiSig))) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x3cU] 
                                                >> 0xaU)))) 
                                      | ((IData)((3U 
                                                  == (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__60__KET____DOT__bi__DOT__ThiSig))) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x3cU] 
                                            >> 0xaU))))));
        bufp->chgBit(oldp+103,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x3cU] >> 2U))));
        bufp->chgBit(oldp+104,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x3cU] >> 1U))));
        bufp->chgBit(oldp+105,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                [0x3cU])));
        bufp->chgBit(oldp+106,((1U & (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                        [0x3cU] >> 2U) 
                                       & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x3cU] 
                                           >> 1U) | 
                                          vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x3cU])) 
                                      | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x3cU] >> 1U) 
                                         & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x3cU])))));
        bufp->chgBit(oldp+107,((1U & ((((((~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                              [0x3cU] 
                                              >> 2U)) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x3cU] 
                                                >> 1U))) 
                                         & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x3cU]) | 
                                        (((~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                              [0x3cU] 
                                              >> 2U)) 
                                          & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [0x3cU] 
                                             >> 1U)) 
                                         & (~ vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x3cU]))) 
                                       | (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x3cU] 
                                            >> 2U) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x3cU] 
                                                 >> 1U))) 
                                          & (~ vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [0x3cU]))) 
                                      | (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x3cU] 
                                           >> 2U) & 
                                          (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x3cU] 
                                           >> 1U)) 
                                         & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x3cU])))));
        bufp->chgBit(oldp+108,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x3cU] >> 4U))));
        bufp->chgBit(oldp+109,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x3cU] >> 3U))));
        bufp->chgBit(oldp+110,((1U & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__60__KET____DOT__bi__InData 
                                       & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x3cU] 
                                           >> 4U) | 
                                          (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x3cU] 
                                           >> 3U))) 
                                      | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x3cU] >> 4U) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x3cU] 
                                            >> 3U))))));
        bufp->chgBit(oldp+111,((1U & ((((((~ vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__60__KET____DOT__bi__InData) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x3cU] 
                                                >> 4U))) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x3cU] 
                                            >> 3U)) 
                                        | (((~ vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__60__KET____DOT__bi__InData) 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                               [0x3cU] 
                                               >> 4U)) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x3cU] 
                                                 >> 3U)))) 
                                       | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__60__KET____DOT__bi__InData 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x3cU] 
                                                 >> 4U))) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x3cU] 
                                                >> 3U)))) 
                                      | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__60__KET____DOT__bi__InData 
                                          & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [0x3cU] 
                                             >> 4U)) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x3cU] 
                                            >> 3U))))));
        bufp->chgBit(oldp+112,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x3cU] >> 0xdU))));
        bufp->chgBit(oldp+113,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x3cU] >> 0xcU))));
        bufp->chgBit(oldp+114,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__60__KET____DOT__bi__DOT__SecSig))));
        bufp->chgBit(oldp+115,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x3cU] >> 6U))));
        bufp->chgBit(oldp+116,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x3cU] >> 5U))));
        bufp->chgBit(oldp+117,((1U & (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__60__KET____DOT__bi__DOT__SecSig) 
                                       & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x3cU] 
                                           >> 6U) | 
                                          (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x3cU] 
                                           >> 5U))) 
                                      | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x3cU] >> 6U) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x3cU] 
                                            >> 5U))))));
        bufp->chgBit(oldp+118,((1U & ((((((~ (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__60__KET____DOT__bi__DOT__SecSig)) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x3cU] 
                                                >> 6U))) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x3cU] 
                                            >> 5U)) 
                                        | (((~ (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__60__KET____DOT__bi__DOT__SecSig)) 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                               [0x3cU] 
                                               >> 6U)) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x3cU] 
                                                 >> 5U)))) 
                                       | (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__60__KET____DOT__bi__DOT__SecSig) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x3cU] 
                                                 >> 6U))) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x3cU] 
                                                >> 5U)))) 
                                      | (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__60__KET____DOT__bi__DOT__SecSig) 
                                          & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [0x3cU] 
                                             >> 6U)) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x3cU] 
                                            >> 5U))))));
        bufp->chgBit(oldp+119,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__60__KET____DOT__bi__DOT__SecSig) 
                                      >> 3U))));
        bufp->chgBit(oldp+120,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__60__KET____DOT__bi__DOT__SecSig) 
                                      >> 2U))));
        bufp->chgBit(oldp+121,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__60__KET____DOT__bi__DOT__SecSig) 
                                      >> 1U))));
        bufp->chgBit(oldp+122,((1U & ((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__60__KET____DOT__bi__DOT__SecSig) 
                                        >> 3U) & (IData)(
                                                         (0U 
                                                          != 
                                                          (6U 
                                                           & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__60__KET____DOT__bi__DOT__SecSig))))) 
                                      | (IData)((6U 
                                                 == 
                                                 (6U 
                                                  & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__60__KET____DOT__bi__DOT__SecSig))))))));
        bufp->chgBit(oldp+123,((1U & ((((IData)((2U 
                                                 == 
                                                 (0xeU 
                                                  & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__60__KET____DOT__bi__DOT__SecSig)))) 
                                        | (IData)((4U 
                                                   == 
                                                   (0xeU 
                                                    & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__60__KET____DOT__bi__DOT__SecSig))))) 
                                       | (IData)((8U 
                                                  == 
                                                  (0xeU 
                                                   & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__60__KET____DOT__bi__DOT__SecSig))))) 
                                      | (IData)((0xeU 
                                                 == 
                                                 (0xeU 
                                                  & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__60__KET____DOT__bi__DOT__SecSig))))))));
        bufp->chgSData(oldp+124,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                 [0x3dU]),14);
        bufp->chgSData(oldp+125,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellout__wallacefor__BRA__61__KET____DOT__bi__COut),14);
        bufp->chgBit(oldp+126,((1U & (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__61__KET____DOT__bi__DOT__FifSig) 
                                       & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x3dU] 
                                           >> 0xdU) 
                                          | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [0x3dU] 
                                             >> 0xcU))) 
                                      | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x3dU] >> 0xdU) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x3dU] 
                                            >> 0xcU))))));
        bufp->chgBit(oldp+127,((1U & ((((((~ (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__61__KET____DOT__bi__DOT__FifSig)) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x3dU] 
                                                >> 0xdU))) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x3dU] 
                                            >> 0xcU)) 
                                        | (((~ (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__61__KET____DOT__bi__DOT__FifSig)) 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                               [0x3dU] 
                                               >> 0xdU)) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x3dU] 
                                                 >> 0xcU)))) 
                                       | (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__61__KET____DOT__bi__DOT__FifSig) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x3dU] 
                                                 >> 0xdU))) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x3dU] 
                                                >> 0xcU)))) 
                                      | (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__61__KET____DOT__bi__DOT__FifSig) 
                                          & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [0x3dU] 
                                             >> 0xdU)) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x3dU] 
                                            >> 0xcU))))));
        bufp->chgCData(oldp+128,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__61__KET____DOT__bi__DOT__SecSig),4);
        bufp->chgBit(oldp+129,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x3dU] >> 0xbU))));
        bufp->chgBit(oldp+130,((1U & ((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__61__KET____DOT__bi__DOT__ForSig) 
                                        >> 1U) & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__61__KET____DOT__bi__DOT__ForSig) 
                                                  | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                     [0x3dU] 
                                                     >> 0xbU))) 
                                      | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__61__KET____DOT__bi__DOT__ForSig) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x3dU] 
                                            >> 0xbU))))));
        bufp->chgBit(oldp+131,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x3dU] >> 9U))));
        bufp->chgBit(oldp+132,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x3dU] >> 8U))));
        bufp->chgBit(oldp+133,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x3dU] >> 7U))));
        bufp->chgBit(oldp+134,((1U & (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                        [0x3dU] >> 9U) 
                                       & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x3dU] 
                                           >> 8U) | 
                                          (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x3dU] 
                                           >> 7U))) 
                                      | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x3dU] >> 8U) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x3dU] 
                                            >> 7U))))));
        bufp->chgBit(oldp+135,((1U & ((((((~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                              [0x3dU] 
                                              >> 9U)) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x3dU] 
                                                >> 8U))) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x3dU] 
                                            >> 7U)) 
                                        | (((~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x3dU] 
                                                >> 9U)) 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                               [0x3dU] 
                                               >> 8U)) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x3dU] 
                                                 >> 7U)))) 
                                       | (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x3dU] 
                                            >> 9U) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x3dU] 
                                                 >> 8U))) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x3dU] 
                                                >> 7U)))) 
                                      | (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x3dU] 
                                           >> 9U) & 
                                          (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x3dU] 
                                           >> 8U)) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x3dU] 
                                            >> 7U))))));
        bufp->chgBit(oldp+136,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x3dU] >> 0xaU))));
        bufp->chgBit(oldp+137,((1U & ((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__61__KET____DOT__bi__DOT__ThiSig) 
                                        >> 1U) & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__61__KET____DOT__bi__DOT__ThiSig) 
                                                  | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                     [0x3dU] 
                                                     >> 0xaU))) 
                                      | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__61__KET____DOT__bi__DOT__ThiSig) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x3dU] 
                                            >> 0xaU))))));
        bufp->chgBit(oldp+138,((1U & (((((IData)((0U 
                                                  == (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__61__KET____DOT__bi__DOT__ThiSig))) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x3dU] 
                                            >> 0xaU)) 
                                        | ((IData)(
                                                   (1U 
                                                    == (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__61__KET____DOT__bi__DOT__ThiSig))) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x3dU] 
                                                 >> 0xaU)))) 
                                       | ((IData)((2U 
                                                   == (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__61__KET____DOT__bi__DOT__ThiSig))) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x3dU] 
                                                >> 0xaU)))) 
                                      | ((IData)((3U 
                                                  == (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__61__KET____DOT__bi__DOT__ThiSig))) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x3dU] 
                                            >> 0xaU))))));
        bufp->chgBit(oldp+139,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x3dU] >> 2U))));
        bufp->chgBit(oldp+140,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x3dU] >> 1U))));
        bufp->chgBit(oldp+141,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                [0x3dU])));
        bufp->chgBit(oldp+142,((1U & (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                        [0x3dU] >> 2U) 
                                       & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x3dU] 
                                           >> 1U) | 
                                          vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x3dU])) 
                                      | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x3dU] >> 1U) 
                                         & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x3dU])))));
        bufp->chgBit(oldp+143,((1U & ((((((~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                              [0x3dU] 
                                              >> 2U)) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x3dU] 
                                                >> 1U))) 
                                         & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x3dU]) | 
                                        (((~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                              [0x3dU] 
                                              >> 2U)) 
                                          & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [0x3dU] 
                                             >> 1U)) 
                                         & (~ vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x3dU]))) 
                                       | (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x3dU] 
                                            >> 2U) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x3dU] 
                                                 >> 1U))) 
                                          & (~ vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [0x3dU]))) 
                                      | (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x3dU] 
                                           >> 2U) & 
                                          (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x3dU] 
                                           >> 1U)) 
                                         & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x3dU])))));
        bufp->chgBit(oldp+144,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x3dU] >> 4U))));
        bufp->chgBit(oldp+145,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x3dU] >> 3U))));
        bufp->chgBit(oldp+146,((1U & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__61__KET____DOT__bi__InData 
                                       & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x3dU] 
                                           >> 4U) | 
                                          (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x3dU] 
                                           >> 3U))) 
                                      | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x3dU] >> 4U) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x3dU] 
                                            >> 3U))))));
        bufp->chgBit(oldp+147,((1U & ((((((~ vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__61__KET____DOT__bi__InData) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x3dU] 
                                                >> 4U))) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x3dU] 
                                            >> 3U)) 
                                        | (((~ vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__61__KET____DOT__bi__InData) 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                               [0x3dU] 
                                               >> 4U)) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x3dU] 
                                                 >> 3U)))) 
                                       | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__61__KET____DOT__bi__InData 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x3dU] 
                                                 >> 4U))) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x3dU] 
                                                >> 3U)))) 
                                      | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__61__KET____DOT__bi__InData 
                                          & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [0x3dU] 
                                             >> 4U)) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x3dU] 
                                            >> 3U))))));
        bufp->chgBit(oldp+148,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x3dU] >> 0xdU))));
        bufp->chgBit(oldp+149,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x3dU] >> 0xcU))));
        bufp->chgBit(oldp+150,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__61__KET____DOT__bi__DOT__SecSig))));
        bufp->chgBit(oldp+151,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x3dU] >> 6U))));
        bufp->chgBit(oldp+152,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x3dU] >> 5U))));
        bufp->chgBit(oldp+153,((1U & (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__61__KET____DOT__bi__DOT__SecSig) 
                                       & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x3dU] 
                                           >> 6U) | 
                                          (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x3dU] 
                                           >> 5U))) 
                                      | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x3dU] >> 6U) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x3dU] 
                                            >> 5U))))));
        bufp->chgBit(oldp+154,((1U & ((((((~ (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__61__KET____DOT__bi__DOT__SecSig)) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x3dU] 
                                                >> 6U))) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x3dU] 
                                            >> 5U)) 
                                        | (((~ (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__61__KET____DOT__bi__DOT__SecSig)) 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                               [0x3dU] 
                                               >> 6U)) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x3dU] 
                                                 >> 5U)))) 
                                       | (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__61__KET____DOT__bi__DOT__SecSig) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x3dU] 
                                                 >> 6U))) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x3dU] 
                                                >> 5U)))) 
                                      | (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__61__KET____DOT__bi__DOT__SecSig) 
                                          & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [0x3dU] 
                                             >> 6U)) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x3dU] 
                                            >> 5U))))));
        bufp->chgBit(oldp+155,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__61__KET____DOT__bi__DOT__SecSig) 
                                      >> 3U))));
        bufp->chgBit(oldp+156,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__61__KET____DOT__bi__DOT__SecSig) 
                                      >> 2U))));
        bufp->chgBit(oldp+157,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__61__KET____DOT__bi__DOT__SecSig) 
                                      >> 1U))));
        bufp->chgBit(oldp+158,((1U & ((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__61__KET____DOT__bi__DOT__SecSig) 
                                        >> 3U) & (IData)(
                                                         (0U 
                                                          != 
                                                          (6U 
                                                           & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__61__KET____DOT__bi__DOT__SecSig))))) 
                                      | (IData)((6U 
                                                 == 
                                                 (6U 
                                                  & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__61__KET____DOT__bi__DOT__SecSig))))))));
        bufp->chgBit(oldp+159,((1U & ((((IData)((2U 
                                                 == 
                                                 (0xeU 
                                                  & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__61__KET____DOT__bi__DOT__SecSig)))) 
                                        | (IData)((4U 
                                                   == 
                                                   (0xeU 
                                                    & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__61__KET____DOT__bi__DOT__SecSig))))) 
                                       | (IData)((8U 
                                                  == 
                                                  (0xeU 
                                                   & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__61__KET____DOT__bi__DOT__SecSig))))) 
                                      | (IData)((0xeU 
                                                 == 
                                                 (0xeU 
                                                  & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__61__KET____DOT__bi__DOT__SecSig))))))));
        bufp->chgSData(oldp+160,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                 [0x3eU]),14);
        bufp->chgSData(oldp+161,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellout__wallacefor__BRA__62__KET____DOT__bi__COut),14);
        bufp->chgBit(oldp+162,((1U & (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__62__KET____DOT__bi__DOT__FifSig) 
                                       & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x3eU] 
                                           >> 0xdU) 
                                          | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [0x3eU] 
                                             >> 0xcU))) 
                                      | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x3eU] >> 0xdU) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x3eU] 
                                            >> 0xcU))))));
        bufp->chgBit(oldp+163,((1U & ((((((~ (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__62__KET____DOT__bi__DOT__FifSig)) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x3eU] 
                                                >> 0xdU))) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x3eU] 
                                            >> 0xcU)) 
                                        | (((~ (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__62__KET____DOT__bi__DOT__FifSig)) 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                               [0x3eU] 
                                               >> 0xdU)) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x3eU] 
                                                 >> 0xcU)))) 
                                       | (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__62__KET____DOT__bi__DOT__FifSig) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x3eU] 
                                                 >> 0xdU))) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x3eU] 
                                                >> 0xcU)))) 
                                      | (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__62__KET____DOT__bi__DOT__FifSig) 
                                          & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [0x3eU] 
                                             >> 0xdU)) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x3eU] 
                                            >> 0xcU))))));
        bufp->chgCData(oldp+164,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__62__KET____DOT__bi__DOT__SecSig),4);
        bufp->chgBit(oldp+165,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x3eU] >> 0xbU))));
        bufp->chgBit(oldp+166,((1U & ((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__62__KET____DOT__bi__DOT__ForSig) 
                                        >> 1U) & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__62__KET____DOT__bi__DOT__ForSig) 
                                                  | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                     [0x3eU] 
                                                     >> 0xbU))) 
                                      | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__62__KET____DOT__bi__DOT__ForSig) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x3eU] 
                                            >> 0xbU))))));
        bufp->chgBit(oldp+167,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x3eU] >> 9U))));
        bufp->chgBit(oldp+168,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x3eU] >> 8U))));
        bufp->chgBit(oldp+169,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x3eU] >> 7U))));
        bufp->chgBit(oldp+170,((1U & (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                        [0x3eU] >> 9U) 
                                       & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x3eU] 
                                           >> 8U) | 
                                          (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x3eU] 
                                           >> 7U))) 
                                      | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x3eU] >> 8U) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x3eU] 
                                            >> 7U))))));
        bufp->chgBit(oldp+171,((1U & ((((((~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                              [0x3eU] 
                                              >> 9U)) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x3eU] 
                                                >> 8U))) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x3eU] 
                                            >> 7U)) 
                                        | (((~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x3eU] 
                                                >> 9U)) 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                               [0x3eU] 
                                               >> 8U)) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x3eU] 
                                                 >> 7U)))) 
                                       | (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x3eU] 
                                            >> 9U) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x3eU] 
                                                 >> 8U))) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x3eU] 
                                                >> 7U)))) 
                                      | (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x3eU] 
                                           >> 9U) & 
                                          (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x3eU] 
                                           >> 8U)) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x3eU] 
                                            >> 7U))))));
        bufp->chgBit(oldp+172,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x3eU] >> 0xaU))));
        bufp->chgBit(oldp+173,((1U & ((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__62__KET____DOT__bi__DOT__ThiSig) 
                                        >> 1U) & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__62__KET____DOT__bi__DOT__ThiSig) 
                                                  | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                     [0x3eU] 
                                                     >> 0xaU))) 
                                      | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__62__KET____DOT__bi__DOT__ThiSig) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x3eU] 
                                            >> 0xaU))))));
        bufp->chgBit(oldp+174,((1U & (((((IData)((0U 
                                                  == (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__62__KET____DOT__bi__DOT__ThiSig))) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x3eU] 
                                            >> 0xaU)) 
                                        | ((IData)(
                                                   (1U 
                                                    == (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__62__KET____DOT__bi__DOT__ThiSig))) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x3eU] 
                                                 >> 0xaU)))) 
                                       | ((IData)((2U 
                                                   == (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__62__KET____DOT__bi__DOT__ThiSig))) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x3eU] 
                                                >> 0xaU)))) 
                                      | ((IData)((3U 
                                                  == (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__62__KET____DOT__bi__DOT__ThiSig))) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x3eU] 
                                            >> 0xaU))))));
        bufp->chgBit(oldp+175,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x3eU] >> 2U))));
        bufp->chgBit(oldp+176,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x3eU] >> 1U))));
        bufp->chgBit(oldp+177,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                [0x3eU])));
        bufp->chgBit(oldp+178,((1U & (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                        [0x3eU] >> 2U) 
                                       & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x3eU] 
                                           >> 1U) | 
                                          vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x3eU])) 
                                      | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x3eU] >> 1U) 
                                         & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x3eU])))));
        bufp->chgBit(oldp+179,((1U & ((((((~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                              [0x3eU] 
                                              >> 2U)) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x3eU] 
                                                >> 1U))) 
                                         & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x3eU]) | 
                                        (((~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                              [0x3eU] 
                                              >> 2U)) 
                                          & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [0x3eU] 
                                             >> 1U)) 
                                         & (~ vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x3eU]))) 
                                       | (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x3eU] 
                                            >> 2U) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x3eU] 
                                                 >> 1U))) 
                                          & (~ vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [0x3eU]))) 
                                      | (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x3eU] 
                                           >> 2U) & 
                                          (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x3eU] 
                                           >> 1U)) 
                                         & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x3eU])))));
        bufp->chgBit(oldp+180,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x3eU] >> 4U))));
        bufp->chgBit(oldp+181,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x3eU] >> 3U))));
        bufp->chgBit(oldp+182,((1U & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__62__KET____DOT__bi__InData 
                                       & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x3eU] 
                                           >> 4U) | 
                                          (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x3eU] 
                                           >> 3U))) 
                                      | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x3eU] >> 4U) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x3eU] 
                                            >> 3U))))));
        bufp->chgBit(oldp+183,((1U & ((((((~ vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__62__KET____DOT__bi__InData) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x3eU] 
                                                >> 4U))) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x3eU] 
                                            >> 3U)) 
                                        | (((~ vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__62__KET____DOT__bi__InData) 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                               [0x3eU] 
                                               >> 4U)) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x3eU] 
                                                 >> 3U)))) 
                                       | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__62__KET____DOT__bi__InData 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x3eU] 
                                                 >> 4U))) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x3eU] 
                                                >> 3U)))) 
                                      | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__62__KET____DOT__bi__InData 
                                          & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [0x3eU] 
                                             >> 4U)) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x3eU] 
                                            >> 3U))))));
        bufp->chgBit(oldp+184,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x3eU] >> 0xdU))));
        bufp->chgBit(oldp+185,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x3eU] >> 0xcU))));
        bufp->chgBit(oldp+186,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__62__KET____DOT__bi__DOT__SecSig))));
        bufp->chgBit(oldp+187,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x3eU] >> 6U))));
        bufp->chgBit(oldp+188,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x3eU] >> 5U))));
        bufp->chgBit(oldp+189,((1U & (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__62__KET____DOT__bi__DOT__SecSig) 
                                       & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x3eU] 
                                           >> 6U) | 
                                          (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x3eU] 
                                           >> 5U))) 
                                      | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x3eU] >> 6U) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x3eU] 
                                            >> 5U))))));
        bufp->chgBit(oldp+190,((1U & ((((((~ (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__62__KET____DOT__bi__DOT__SecSig)) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x3eU] 
                                                >> 6U))) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x3eU] 
                                            >> 5U)) 
                                        | (((~ (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__62__KET____DOT__bi__DOT__SecSig)) 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                               [0x3eU] 
                                               >> 6U)) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x3eU] 
                                                 >> 5U)))) 
                                       | (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__62__KET____DOT__bi__DOT__SecSig) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x3eU] 
                                                 >> 6U))) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x3eU] 
                                                >> 5U)))) 
                                      | (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__62__KET____DOT__bi__DOT__SecSig) 
                                          & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [0x3eU] 
                                             >> 6U)) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x3eU] 
                                            >> 5U))))));
        bufp->chgBit(oldp+191,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__62__KET____DOT__bi__DOT__SecSig) 
                                      >> 3U))));
        bufp->chgBit(oldp+192,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__62__KET____DOT__bi__DOT__SecSig) 
                                      >> 2U))));
        bufp->chgBit(oldp+193,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__62__KET____DOT__bi__DOT__SecSig) 
                                      >> 1U))));
        bufp->chgBit(oldp+194,((1U & ((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__62__KET____DOT__bi__DOT__SecSig) 
                                        >> 3U) & (IData)(
                                                         (0U 
                                                          != 
                                                          (6U 
                                                           & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__62__KET____DOT__bi__DOT__SecSig))))) 
                                      | (IData)((6U 
                                                 == 
                                                 (6U 
                                                  & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__62__KET____DOT__bi__DOT__SecSig))))))));
        bufp->chgBit(oldp+195,((1U & ((((IData)((2U 
                                                 == 
                                                 (0xeU 
                                                  & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__62__KET____DOT__bi__DOT__SecSig)))) 
                                        | (IData)((4U 
                                                   == 
                                                   (0xeU 
                                                    & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__62__KET____DOT__bi__DOT__SecSig))))) 
                                       | (IData)((8U 
                                                  == 
                                                  (0xeU 
                                                   & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__62__KET____DOT__bi__DOT__SecSig))))) 
                                      | (IData)((0xeU 
                                                 == 
                                                 (0xeU 
                                                  & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__62__KET____DOT__bi__DOT__SecSig))))))));
        bufp->chgSData(oldp+196,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                 [0x3fU]),14);
        bufp->chgSData(oldp+197,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellout__wallacefor__BRA__63__KET____DOT__bi__COut),14);
        bufp->chgBit(oldp+198,((1U & (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__63__KET____DOT__bi__DOT__FifSig) 
                                       & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x3fU] 
                                           >> 0xdU) 
                                          | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [0x3fU] 
                                             >> 0xcU))) 
                                      | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x3fU] >> 0xdU) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x3fU] 
                                            >> 0xcU))))));
        bufp->chgBit(oldp+199,((1U & ((((((~ (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__63__KET____DOT__bi__DOT__FifSig)) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x3fU] 
                                                >> 0xdU))) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x3fU] 
                                            >> 0xcU)) 
                                        | (((~ (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__63__KET____DOT__bi__DOT__FifSig)) 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                               [0x3fU] 
                                               >> 0xdU)) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x3fU] 
                                                 >> 0xcU)))) 
                                       | (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__63__KET____DOT__bi__DOT__FifSig) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x3fU] 
                                                 >> 0xdU))) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x3fU] 
                                                >> 0xcU)))) 
                                      | (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__63__KET____DOT__bi__DOT__FifSig) 
                                          & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [0x3fU] 
                                             >> 0xdU)) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x3fU] 
                                            >> 0xcU))))));
        bufp->chgCData(oldp+200,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__63__KET____DOT__bi__DOT__SecSig),4);
        bufp->chgBit(oldp+201,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x3fU] >> 0xbU))));
        bufp->chgBit(oldp+202,((1U & ((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__63__KET____DOT__bi__DOT__ForSig) 
                                        >> 1U) & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__63__KET____DOT__bi__DOT__ForSig) 
                                                  | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                     [0x3fU] 
                                                     >> 0xbU))) 
                                      | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__63__KET____DOT__bi__DOT__ForSig) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x3fU] 
                                            >> 0xbU))))));
        bufp->chgBit(oldp+203,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x3fU] >> 9U))));
        bufp->chgBit(oldp+204,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x3fU] >> 8U))));
        bufp->chgBit(oldp+205,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x3fU] >> 7U))));
        bufp->chgBit(oldp+206,((1U & (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                        [0x3fU] >> 9U) 
                                       & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x3fU] 
                                           >> 8U) | 
                                          (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x3fU] 
                                           >> 7U))) 
                                      | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x3fU] >> 8U) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x3fU] 
                                            >> 7U))))));
        bufp->chgBit(oldp+207,((1U & ((((((~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                              [0x3fU] 
                                              >> 9U)) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x3fU] 
                                                >> 8U))) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x3fU] 
                                            >> 7U)) 
                                        | (((~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x3fU] 
                                                >> 9U)) 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                               [0x3fU] 
                                               >> 8U)) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x3fU] 
                                                 >> 7U)))) 
                                       | (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x3fU] 
                                            >> 9U) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x3fU] 
                                                 >> 8U))) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x3fU] 
                                                >> 7U)))) 
                                      | (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x3fU] 
                                           >> 9U) & 
                                          (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x3fU] 
                                           >> 8U)) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x3fU] 
                                            >> 7U))))));
        bufp->chgBit(oldp+208,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x3fU] >> 0xaU))));
        bufp->chgBit(oldp+209,((1U & ((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__63__KET____DOT__bi__DOT__ThiSig) 
                                        >> 1U) & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__63__KET____DOT__bi__DOT__ThiSig) 
                                                  | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                     [0x3fU] 
                                                     >> 0xaU))) 
                                      | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__63__KET____DOT__bi__DOT__ThiSig) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x3fU] 
                                            >> 0xaU))))));
        bufp->chgBit(oldp+210,((1U & (((((IData)((0U 
                                                  == (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__63__KET____DOT__bi__DOT__ThiSig))) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x3fU] 
                                            >> 0xaU)) 
                                        | ((IData)(
                                                   (1U 
                                                    == (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__63__KET____DOT__bi__DOT__ThiSig))) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x3fU] 
                                                 >> 0xaU)))) 
                                       | ((IData)((2U 
                                                   == (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__63__KET____DOT__bi__DOT__ThiSig))) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x3fU] 
                                                >> 0xaU)))) 
                                      | ((IData)((3U 
                                                  == (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__63__KET____DOT__bi__DOT__ThiSig))) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x3fU] 
                                            >> 0xaU))))));
        bufp->chgBit(oldp+211,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x3fU] >> 2U))));
        bufp->chgBit(oldp+212,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x3fU] >> 1U))));
        bufp->chgBit(oldp+213,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                [0x3fU])));
        bufp->chgBit(oldp+214,((1U & (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                        [0x3fU] >> 2U) 
                                       & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x3fU] 
                                           >> 1U) | 
                                          vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x3fU])) 
                                      | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x3fU] >> 1U) 
                                         & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x3fU])))));
        bufp->chgBit(oldp+215,((1U & ((((((~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                              [0x3fU] 
                                              >> 2U)) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x3fU] 
                                                >> 1U))) 
                                         & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x3fU]) | 
                                        (((~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                              [0x3fU] 
                                              >> 2U)) 
                                          & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [0x3fU] 
                                             >> 1U)) 
                                         & (~ vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x3fU]))) 
                                       | (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x3fU] 
                                            >> 2U) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x3fU] 
                                                 >> 1U))) 
                                          & (~ vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [0x3fU]))) 
                                      | (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x3fU] 
                                           >> 2U) & 
                                          (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x3fU] 
                                           >> 1U)) 
                                         & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x3fU])))));
        bufp->chgBit(oldp+216,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x3fU] >> 4U))));
        bufp->chgBit(oldp+217,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x3fU] >> 3U))));
        bufp->chgBit(oldp+218,((1U & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__63__KET____DOT__bi__InData 
                                       & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x3fU] 
                                           >> 4U) | 
                                          (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x3fU] 
                                           >> 3U))) 
                                      | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x3fU] >> 4U) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x3fU] 
                                            >> 3U))))));
        bufp->chgBit(oldp+219,((1U & ((((((~ vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__63__KET____DOT__bi__InData) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x3fU] 
                                                >> 4U))) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x3fU] 
                                            >> 3U)) 
                                        | (((~ vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__63__KET____DOT__bi__InData) 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                               [0x3fU] 
                                               >> 4U)) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x3fU] 
                                                 >> 3U)))) 
                                       | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__63__KET____DOT__bi__InData 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x3fU] 
                                                 >> 4U))) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x3fU] 
                                                >> 3U)))) 
                                      | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__63__KET____DOT__bi__InData 
                                          & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [0x3fU] 
                                             >> 4U)) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x3fU] 
                                            >> 3U))))));
        bufp->chgBit(oldp+220,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x3fU] >> 0xdU))));
        bufp->chgBit(oldp+221,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x3fU] >> 0xcU))));
        bufp->chgBit(oldp+222,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__63__KET____DOT__bi__DOT__SecSig))));
        bufp->chgBit(oldp+223,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x3fU] >> 6U))));
        bufp->chgBit(oldp+224,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [0x3fU] >> 5U))));
        bufp->chgBit(oldp+225,((1U & (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__63__KET____DOT__bi__DOT__SecSig) 
                                       & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x3fU] 
                                           >> 6U) | 
                                          (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x3fU] 
                                           >> 5U))) 
                                      | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x3fU] >> 6U) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x3fU] 
                                            >> 5U))))));
        bufp->chgBit(oldp+226,((1U & ((((((~ (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__63__KET____DOT__bi__DOT__SecSig)) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x3fU] 
                                                >> 6U))) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x3fU] 
                                            >> 5U)) 
                                        | (((~ (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__63__KET____DOT__bi__DOT__SecSig)) 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                               [0x3fU] 
                                               >> 6U)) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x3fU] 
                                                 >> 5U)))) 
                                       | (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__63__KET____DOT__bi__DOT__SecSig) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [0x3fU] 
                                                 >> 6U))) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [0x3fU] 
                                                >> 5U)))) 
                                      | (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__63__KET____DOT__bi__DOT__SecSig) 
                                          & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [0x3fU] 
                                             >> 6U)) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x3fU] 
                                            >> 5U))))));
        bufp->chgBit(oldp+227,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__63__KET____DOT__bi__DOT__SecSig) 
                                      >> 3U))));
        bufp->chgBit(oldp+228,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__63__KET____DOT__bi__DOT__SecSig) 
                                      >> 2U))));
        bufp->chgBit(oldp+229,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__63__KET____DOT__bi__DOT__SecSig) 
                                      >> 1U))));
        bufp->chgBit(oldp+230,((1U & ((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__63__KET____DOT__bi__DOT__SecSig) 
                                        >> 3U) & (IData)(
                                                         (0U 
                                                          != 
                                                          (6U 
                                                           & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__63__KET____DOT__bi__DOT__SecSig))))) 
                                      | (IData)((6U 
                                                 == 
                                                 (6U 
                                                  & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__63__KET____DOT__bi__DOT__SecSig))))))));
        bufp->chgBit(oldp+231,((1U & ((((IData)((2U 
                                                 == 
                                                 (0xeU 
                                                  & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__63__KET____DOT__bi__DOT__SecSig)))) 
                                        | (IData)((4U 
                                                   == 
                                                   (0xeU 
                                                    & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__63__KET____DOT__bi__DOT__SecSig))))) 
                                       | (IData)((8U 
                                                  == 
                                                  (0xeU 
                                                   & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__63__KET____DOT__bi__DOT__SecSig))))) 
                                      | (IData)((0xeU 
                                                 == 
                                                 (0xeU 
                                                  & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__63__KET____DOT__bi__DOT__SecSig))))))));
        bufp->chgSData(oldp+232,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                 [6U]),14);
        bufp->chgSData(oldp+233,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellout__wallacefor__BRA__6__KET____DOT__bi__COut),14);
        bufp->chgBit(oldp+234,((1U & (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__6__KET____DOT__bi__DOT__FifSig) 
                                       & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [6U] >> 0xdU) 
                                          | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [6U] >> 0xcU))) 
                                      | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [6U] >> 0xdU) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [6U] >> 0xcU))))));
        bufp->chgBit(oldp+235,((1U & ((((((~ (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__6__KET____DOT__bi__DOT__FifSig)) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [6U] 
                                                >> 0xdU))) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [6U] >> 0xcU)) 
                                        | (((~ (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__6__KET____DOT__bi__DOT__FifSig)) 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                               [6U] 
                                               >> 0xdU)) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [6U] 
                                                 >> 0xcU)))) 
                                       | (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__6__KET____DOT__bi__DOT__FifSig) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [6U] 
                                                 >> 0xdU))) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [6U] 
                                                >> 0xcU)))) 
                                      | (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__6__KET____DOT__bi__DOT__FifSig) 
                                          & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [6U] >> 0xdU)) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [6U] >> 0xcU))))));
        bufp->chgCData(oldp+236,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__6__KET____DOT__bi__DOT__SecSig),4);
        bufp->chgBit(oldp+237,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [6U] >> 0xbU))));
        bufp->chgBit(oldp+238,((1U & ((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__6__KET____DOT__bi__DOT__ForSig) 
                                        >> 1U) & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__6__KET____DOT__bi__DOT__ForSig) 
                                                  | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                     [6U] 
                                                     >> 0xbU))) 
                                      | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__6__KET____DOT__bi__DOT__ForSig) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [6U] >> 0xbU))))));
        bufp->chgBit(oldp+239,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [6U] >> 9U))));
        bufp->chgBit(oldp+240,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [6U] >> 8U))));
        bufp->chgBit(oldp+241,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [6U] >> 7U))));
        bufp->chgBit(oldp+242,((1U & (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                        [6U] >> 9U) 
                                       & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [6U] >> 8U) 
                                          | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [6U] >> 7U))) 
                                      | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [6U] >> 8U) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [6U] >> 7U))))));
        bufp->chgBit(oldp+243,((1U & ((((((~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                              [6U] 
                                              >> 9U)) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [6U] 
                                                >> 8U))) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [6U] >> 7U)) 
                                        | (((~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [6U] 
                                                >> 9U)) 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                               [6U] 
                                               >> 8U)) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [6U] 
                                                 >> 7U)))) 
                                       | (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [6U] >> 9U) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [6U] 
                                                 >> 8U))) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [6U] 
                                                >> 7U)))) 
                                      | (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [6U] >> 9U) 
                                          & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [6U] >> 8U)) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [6U] >> 7U))))));
        bufp->chgBit(oldp+244,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [6U] >> 0xaU))));
        bufp->chgBit(oldp+245,((1U & ((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__6__KET____DOT__bi__DOT__ThiSig) 
                                        >> 1U) & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__6__KET____DOT__bi__DOT__ThiSig) 
                                                  | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                     [6U] 
                                                     >> 0xaU))) 
                                      | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__6__KET____DOT__bi__DOT__ThiSig) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [6U] >> 0xaU))))));
        bufp->chgBit(oldp+246,((1U & (((((IData)((0U 
                                                  == (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__6__KET____DOT__bi__DOT__ThiSig))) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [6U] >> 0xaU)) 
                                        | ((IData)(
                                                   (1U 
                                                    == (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__6__KET____DOT__bi__DOT__ThiSig))) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [6U] 
                                                 >> 0xaU)))) 
                                       | ((IData)((2U 
                                                   == (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__6__KET____DOT__bi__DOT__ThiSig))) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [6U] 
                                                >> 0xaU)))) 
                                      | ((IData)((3U 
                                                  == (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__6__KET____DOT__bi__DOT__ThiSig))) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [6U] >> 0xaU))))));
        bufp->chgBit(oldp+247,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [6U] >> 2U))));
        bufp->chgBit(oldp+248,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [6U] >> 1U))));
        bufp->chgBit(oldp+249,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                [6U])));
        bufp->chgBit(oldp+250,((1U & (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                        [6U] >> 2U) 
                                       & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [6U] >> 1U) 
                                          | vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [6U])) | 
                                      ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                        [6U] >> 1U) 
                                       & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                       [6U])))));
        bufp->chgBit(oldp+251,((1U & ((((((~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                              [6U] 
                                              >> 2U)) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [6U] 
                                                >> 1U))) 
                                         & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [6U]) | ((
                                                   (~ 
                                                    (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                     [6U] 
                                                     >> 2U)) 
                                                   & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                      [6U] 
                                                      >> 1U)) 
                                                  & (~ 
                                                     vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                     [6U]))) 
                                       | (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [6U] >> 2U) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [6U] 
                                                 >> 1U))) 
                                          & (~ vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [6U]))) 
                                      | (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [6U] >> 2U) 
                                          & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [6U] >> 1U)) 
                                         & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [6U])))));
        bufp->chgBit(oldp+252,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [6U] >> 4U))));
        bufp->chgBit(oldp+253,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [6U] >> 3U))));
        bufp->chgBit(oldp+254,((1U & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__6__KET____DOT__bi__InData 
                                       & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [6U] >> 4U) 
                                          | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [6U] >> 3U))) 
                                      | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [6U] >> 4U) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [6U] >> 3U))))));
        bufp->chgBit(oldp+255,((1U & ((((((~ vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__6__KET____DOT__bi__InData) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [6U] 
                                                >> 4U))) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [6U] >> 3U)) 
                                        | (((~ vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__6__KET____DOT__bi__InData) 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                               [6U] 
                                               >> 4U)) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [6U] 
                                                 >> 3U)))) 
                                       | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__6__KET____DOT__bi__InData 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [6U] 
                                                 >> 4U))) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [6U] 
                                                >> 3U)))) 
                                      | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__6__KET____DOT__bi__InData 
                                          & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [6U] >> 4U)) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [6U] >> 3U))))));
        bufp->chgBit(oldp+256,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [6U] >> 0xdU))));
        bufp->chgBit(oldp+257,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [6U] >> 0xcU))));
        bufp->chgBit(oldp+258,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__6__KET____DOT__bi__DOT__SecSig))));
        bufp->chgBit(oldp+259,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [6U] >> 6U))));
        bufp->chgBit(oldp+260,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [6U] >> 5U))));
        bufp->chgBit(oldp+261,((1U & (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__6__KET____DOT__bi__DOT__SecSig) 
                                       & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [6U] >> 6U) 
                                          | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [6U] >> 5U))) 
                                      | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [6U] >> 6U) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [6U] >> 5U))))));
        bufp->chgBit(oldp+262,((1U & ((((((~ (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__6__KET____DOT__bi__DOT__SecSig)) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [6U] 
                                                >> 6U))) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [6U] >> 5U)) 
                                        | (((~ (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__6__KET____DOT__bi__DOT__SecSig)) 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                               [6U] 
                                               >> 6U)) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [6U] 
                                                 >> 5U)))) 
                                       | (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__6__KET____DOT__bi__DOT__SecSig) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [6U] 
                                                 >> 6U))) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [6U] 
                                                >> 5U)))) 
                                      | (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__6__KET____DOT__bi__DOT__SecSig) 
                                          & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [6U] >> 6U)) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [6U] >> 5U))))));
        bufp->chgBit(oldp+263,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__6__KET____DOT__bi__DOT__SecSig) 
                                      >> 3U))));
        bufp->chgBit(oldp+264,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__6__KET____DOT__bi__DOT__SecSig) 
                                      >> 2U))));
        bufp->chgBit(oldp+265,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__6__KET____DOT__bi__DOT__SecSig) 
                                      >> 1U))));
        bufp->chgBit(oldp+266,((1U & ((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__6__KET____DOT__bi__DOT__SecSig) 
                                        >> 3U) & (IData)(
                                                         (0U 
                                                          != 
                                                          (6U 
                                                           & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__6__KET____DOT__bi__DOT__SecSig))))) 
                                      | (IData)((6U 
                                                 == 
                                                 (6U 
                                                  & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__6__KET____DOT__bi__DOT__SecSig))))))));
        bufp->chgBit(oldp+267,((1U & ((((IData)((2U 
                                                 == 
                                                 (0xeU 
                                                  & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__6__KET____DOT__bi__DOT__SecSig)))) 
                                        | (IData)((4U 
                                                   == 
                                                   (0xeU 
                                                    & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__6__KET____DOT__bi__DOT__SecSig))))) 
                                       | (IData)((8U 
                                                  == 
                                                  (0xeU 
                                                   & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__6__KET____DOT__bi__DOT__SecSig))))) 
                                      | (IData)((0xeU 
                                                 == 
                                                 (0xeU 
                                                  & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__6__KET____DOT__bi__DOT__SecSig))))))));
        bufp->chgSData(oldp+268,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                 [7U]),14);
        bufp->chgSData(oldp+269,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellout__wallacefor__BRA__7__KET____DOT__bi__COut),14);
        bufp->chgBit(oldp+270,((1U & (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__7__KET____DOT__bi__DOT__FifSig) 
                                       & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [7U] >> 0xdU) 
                                          | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [7U] >> 0xcU))) 
                                      | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [7U] >> 0xdU) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [7U] >> 0xcU))))));
        bufp->chgBit(oldp+271,((1U & ((((((~ (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__7__KET____DOT__bi__DOT__FifSig)) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [7U] 
                                                >> 0xdU))) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [7U] >> 0xcU)) 
                                        | (((~ (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__7__KET____DOT__bi__DOT__FifSig)) 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                               [7U] 
                                               >> 0xdU)) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [7U] 
                                                 >> 0xcU)))) 
                                       | (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__7__KET____DOT__bi__DOT__FifSig) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [7U] 
                                                 >> 0xdU))) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [7U] 
                                                >> 0xcU)))) 
                                      | (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__7__KET____DOT__bi__DOT__FifSig) 
                                          & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [7U] >> 0xdU)) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [7U] >> 0xcU))))));
        bufp->chgCData(oldp+272,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__7__KET____DOT__bi__DOT__SecSig),4);
        bufp->chgBit(oldp+273,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [7U] >> 0xbU))));
        bufp->chgBit(oldp+274,((1U & ((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__7__KET____DOT__bi__DOT__ForSig) 
                                        >> 1U) & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__7__KET____DOT__bi__DOT__ForSig) 
                                                  | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                     [7U] 
                                                     >> 0xbU))) 
                                      | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__7__KET____DOT__bi__DOT__ForSig) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [7U] >> 0xbU))))));
        bufp->chgBit(oldp+275,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [7U] >> 9U))));
        bufp->chgBit(oldp+276,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [7U] >> 8U))));
        bufp->chgBit(oldp+277,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [7U] >> 7U))));
        bufp->chgBit(oldp+278,((1U & (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                        [7U] >> 9U) 
                                       & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [7U] >> 8U) 
                                          | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [7U] >> 7U))) 
                                      | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [7U] >> 8U) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [7U] >> 7U))))));
        bufp->chgBit(oldp+279,((1U & ((((((~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                              [7U] 
                                              >> 9U)) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [7U] 
                                                >> 8U))) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [7U] >> 7U)) 
                                        | (((~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [7U] 
                                                >> 9U)) 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                               [7U] 
                                               >> 8U)) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [7U] 
                                                 >> 7U)))) 
                                       | (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [7U] >> 9U) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [7U] 
                                                 >> 8U))) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [7U] 
                                                >> 7U)))) 
                                      | (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [7U] >> 9U) 
                                          & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [7U] >> 8U)) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [7U] >> 7U))))));
        bufp->chgBit(oldp+280,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [7U] >> 0xaU))));
        bufp->chgBit(oldp+281,((1U & ((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__7__KET____DOT__bi__DOT__ThiSig) 
                                        >> 1U) & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__7__KET____DOT__bi__DOT__ThiSig) 
                                                  | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                     [7U] 
                                                     >> 0xaU))) 
                                      | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__7__KET____DOT__bi__DOT__ThiSig) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [7U] >> 0xaU))))));
        bufp->chgBit(oldp+282,((1U & (((((IData)((0U 
                                                  == (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__7__KET____DOT__bi__DOT__ThiSig))) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [7U] >> 0xaU)) 
                                        | ((IData)(
                                                   (1U 
                                                    == (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__7__KET____DOT__bi__DOT__ThiSig))) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [7U] 
                                                 >> 0xaU)))) 
                                       | ((IData)((2U 
                                                   == (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__7__KET____DOT__bi__DOT__ThiSig))) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [7U] 
                                                >> 0xaU)))) 
                                      | ((IData)((3U 
                                                  == (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__7__KET____DOT__bi__DOT__ThiSig))) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [7U] >> 0xaU))))));
        bufp->chgBit(oldp+283,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [7U] >> 2U))));
        bufp->chgBit(oldp+284,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [7U] >> 1U))));
        bufp->chgBit(oldp+285,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                [7U])));
        bufp->chgBit(oldp+286,((1U & (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                        [7U] >> 2U) 
                                       & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [7U] >> 1U) 
                                          | vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [7U])) | 
                                      ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                        [7U] >> 1U) 
                                       & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                       [7U])))));
        bufp->chgBit(oldp+287,((1U & ((((((~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                              [7U] 
                                              >> 2U)) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [7U] 
                                                >> 1U))) 
                                         & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [7U]) | ((
                                                   (~ 
                                                    (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                     [7U] 
                                                     >> 2U)) 
                                                   & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                      [7U] 
                                                      >> 1U)) 
                                                  & (~ 
                                                     vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                     [7U]))) 
                                       | (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [7U] >> 2U) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [7U] 
                                                 >> 1U))) 
                                          & (~ vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [7U]))) 
                                      | (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [7U] >> 2U) 
                                          & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [7U] >> 1U)) 
                                         & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [7U])))));
        bufp->chgBit(oldp+288,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [7U] >> 4U))));
        bufp->chgBit(oldp+289,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [7U] >> 3U))));
        bufp->chgBit(oldp+290,((1U & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__7__KET____DOT__bi__InData 
                                       & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [7U] >> 4U) 
                                          | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [7U] >> 3U))) 
                                      | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [7U] >> 4U) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [7U] >> 3U))))));
        bufp->chgBit(oldp+291,((1U & ((((((~ vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__7__KET____DOT__bi__InData) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [7U] 
                                                >> 4U))) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [7U] >> 3U)) 
                                        | (((~ vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__7__KET____DOT__bi__InData) 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                               [7U] 
                                               >> 4U)) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [7U] 
                                                 >> 3U)))) 
                                       | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__7__KET____DOT__bi__InData 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [7U] 
                                                 >> 4U))) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [7U] 
                                                >> 3U)))) 
                                      | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__7__KET____DOT__bi__InData 
                                          & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [7U] >> 4U)) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [7U] >> 3U))))));
        bufp->chgBit(oldp+292,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [7U] >> 0xdU))));
        bufp->chgBit(oldp+293,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [7U] >> 0xcU))));
        bufp->chgBit(oldp+294,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__7__KET____DOT__bi__DOT__SecSig))));
        bufp->chgBit(oldp+295,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [7U] >> 6U))));
        bufp->chgBit(oldp+296,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [7U] >> 5U))));
        bufp->chgBit(oldp+297,((1U & (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__7__KET____DOT__bi__DOT__SecSig) 
                                       & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [7U] >> 6U) 
                                          | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [7U] >> 5U))) 
                                      | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [7U] >> 6U) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [7U] >> 5U))))));
        bufp->chgBit(oldp+298,((1U & ((((((~ (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__7__KET____DOT__bi__DOT__SecSig)) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [7U] 
                                                >> 6U))) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [7U] >> 5U)) 
                                        | (((~ (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__7__KET____DOT__bi__DOT__SecSig)) 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                               [7U] 
                                               >> 6U)) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [7U] 
                                                 >> 5U)))) 
                                       | (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__7__KET____DOT__bi__DOT__SecSig) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [7U] 
                                                 >> 6U))) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [7U] 
                                                >> 5U)))) 
                                      | (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__7__KET____DOT__bi__DOT__SecSig) 
                                          & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [7U] >> 6U)) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [7U] >> 5U))))));
        bufp->chgBit(oldp+299,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__7__KET____DOT__bi__DOT__SecSig) 
                                      >> 3U))));
        bufp->chgBit(oldp+300,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__7__KET____DOT__bi__DOT__SecSig) 
                                      >> 2U))));
        bufp->chgBit(oldp+301,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__7__KET____DOT__bi__DOT__SecSig) 
                                      >> 1U))));
        bufp->chgBit(oldp+302,((1U & ((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__7__KET____DOT__bi__DOT__SecSig) 
                                        >> 3U) & (IData)(
                                                         (0U 
                                                          != 
                                                          (6U 
                                                           & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__7__KET____DOT__bi__DOT__SecSig))))) 
                                      | (IData)((6U 
                                                 == 
                                                 (6U 
                                                  & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__7__KET____DOT__bi__DOT__SecSig))))))));
        bufp->chgBit(oldp+303,((1U & ((((IData)((2U 
                                                 == 
                                                 (0xeU 
                                                  & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__7__KET____DOT__bi__DOT__SecSig)))) 
                                        | (IData)((4U 
                                                   == 
                                                   (0xeU 
                                                    & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__7__KET____DOT__bi__DOT__SecSig))))) 
                                       | (IData)((8U 
                                                  == 
                                                  (0xeU 
                                                   & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__7__KET____DOT__bi__DOT__SecSig))))) 
                                      | (IData)((0xeU 
                                                 == 
                                                 (0xeU 
                                                  & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__7__KET____DOT__bi__DOT__SecSig))))))));
        bufp->chgSData(oldp+304,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                 [8U]),14);
        bufp->chgSData(oldp+305,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellout__wallacefor__BRA__8__KET____DOT__bi__COut),14);
        bufp->chgBit(oldp+306,((1U & (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__8__KET____DOT__bi__DOT__FifSig) 
                                       & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [8U] >> 0xdU) 
                                          | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [8U] >> 0xcU))) 
                                      | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [8U] >> 0xdU) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [8U] >> 0xcU))))));
        bufp->chgBit(oldp+307,((1U & ((((((~ (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__8__KET____DOT__bi__DOT__FifSig)) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [8U] 
                                                >> 0xdU))) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [8U] >> 0xcU)) 
                                        | (((~ (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__8__KET____DOT__bi__DOT__FifSig)) 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                               [8U] 
                                               >> 0xdU)) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [8U] 
                                                 >> 0xcU)))) 
                                       | (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__8__KET____DOT__bi__DOT__FifSig) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [8U] 
                                                 >> 0xdU))) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [8U] 
                                                >> 0xcU)))) 
                                      | (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__8__KET____DOT__bi__DOT__FifSig) 
                                          & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [8U] >> 0xdU)) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [8U] >> 0xcU))))));
        bufp->chgCData(oldp+308,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__8__KET____DOT__bi__DOT__SecSig),4);
        bufp->chgBit(oldp+309,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [8U] >> 0xbU))));
        bufp->chgBit(oldp+310,((1U & ((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__8__KET____DOT__bi__DOT__ForSig) 
                                        >> 1U) & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__8__KET____DOT__bi__DOT__ForSig) 
                                                  | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                     [8U] 
                                                     >> 0xbU))) 
                                      | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__8__KET____DOT__bi__DOT__ForSig) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [8U] >> 0xbU))))));
        bufp->chgBit(oldp+311,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [8U] >> 9U))));
        bufp->chgBit(oldp+312,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [8U] >> 8U))));
        bufp->chgBit(oldp+313,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [8U] >> 7U))));
        bufp->chgBit(oldp+314,((1U & (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                        [8U] >> 9U) 
                                       & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [8U] >> 8U) 
                                          | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [8U] >> 7U))) 
                                      | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [8U] >> 8U) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [8U] >> 7U))))));
        bufp->chgBit(oldp+315,((1U & ((((((~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                              [8U] 
                                              >> 9U)) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [8U] 
                                                >> 8U))) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [8U] >> 7U)) 
                                        | (((~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [8U] 
                                                >> 9U)) 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                               [8U] 
                                               >> 8U)) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [8U] 
                                                 >> 7U)))) 
                                       | (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [8U] >> 9U) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [8U] 
                                                 >> 8U))) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [8U] 
                                                >> 7U)))) 
                                      | (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [8U] >> 9U) 
                                          & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [8U] >> 8U)) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [8U] >> 7U))))));
        bufp->chgBit(oldp+316,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [8U] >> 0xaU))));
        bufp->chgBit(oldp+317,((1U & ((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__8__KET____DOT__bi__DOT__ThiSig) 
                                        >> 1U) & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__8__KET____DOT__bi__DOT__ThiSig) 
                                                  | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                     [8U] 
                                                     >> 0xaU))) 
                                      | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__8__KET____DOT__bi__DOT__ThiSig) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [8U] >> 0xaU))))));
        bufp->chgBit(oldp+318,((1U & (((((IData)((0U 
                                                  == (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__8__KET____DOT__bi__DOT__ThiSig))) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [8U] >> 0xaU)) 
                                        | ((IData)(
                                                   (1U 
                                                    == (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__8__KET____DOT__bi__DOT__ThiSig))) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [8U] 
                                                 >> 0xaU)))) 
                                       | ((IData)((2U 
                                                   == (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__8__KET____DOT__bi__DOT__ThiSig))) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [8U] 
                                                >> 0xaU)))) 
                                      | ((IData)((3U 
                                                  == (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__8__KET____DOT__bi__DOT__ThiSig))) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [8U] >> 0xaU))))));
        bufp->chgBit(oldp+319,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [8U] >> 2U))));
        bufp->chgBit(oldp+320,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [8U] >> 1U))));
        bufp->chgBit(oldp+321,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                [8U])));
        bufp->chgBit(oldp+322,((1U & (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                        [8U] >> 2U) 
                                       & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [8U] >> 1U) 
                                          | vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [8U])) | 
                                      ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                        [8U] >> 1U) 
                                       & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                       [8U])))));
        bufp->chgBit(oldp+323,((1U & ((((((~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                              [8U] 
                                              >> 2U)) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [8U] 
                                                >> 1U))) 
                                         & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [8U]) | ((
                                                   (~ 
                                                    (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                     [8U] 
                                                     >> 2U)) 
                                                   & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                      [8U] 
                                                      >> 1U)) 
                                                  & (~ 
                                                     vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                     [8U]))) 
                                       | (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [8U] >> 2U) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [8U] 
                                                 >> 1U))) 
                                          & (~ vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [8U]))) 
                                      | (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [8U] >> 2U) 
                                          & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [8U] >> 1U)) 
                                         & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [8U])))));
        bufp->chgBit(oldp+324,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [8U] >> 4U))));
        bufp->chgBit(oldp+325,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [8U] >> 3U))));
        bufp->chgBit(oldp+326,((1U & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__8__KET____DOT__bi__InData 
                                       & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [8U] >> 4U) 
                                          | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [8U] >> 3U))) 
                                      | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [8U] >> 4U) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [8U] >> 3U))))));
        bufp->chgBit(oldp+327,((1U & ((((((~ vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__8__KET____DOT__bi__InData) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [8U] 
                                                >> 4U))) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [8U] >> 3U)) 
                                        | (((~ vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__8__KET____DOT__bi__InData) 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                               [8U] 
                                               >> 4U)) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [8U] 
                                                 >> 3U)))) 
                                       | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__8__KET____DOT__bi__InData 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [8U] 
                                                 >> 4U))) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [8U] 
                                                >> 3U)))) 
                                      | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__8__KET____DOT__bi__InData 
                                          & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [8U] >> 4U)) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [8U] >> 3U))))));
        bufp->chgBit(oldp+328,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [8U] >> 0xdU))));
        bufp->chgBit(oldp+329,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [8U] >> 0xcU))));
        bufp->chgBit(oldp+330,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__8__KET____DOT__bi__DOT__SecSig))));
        bufp->chgBit(oldp+331,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [8U] >> 6U))));
        bufp->chgBit(oldp+332,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [8U] >> 5U))));
        bufp->chgBit(oldp+333,((1U & (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__8__KET____DOT__bi__DOT__SecSig) 
                                       & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [8U] >> 6U) 
                                          | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [8U] >> 5U))) 
                                      | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [8U] >> 6U) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [8U] >> 5U))))));
        bufp->chgBit(oldp+334,((1U & ((((((~ (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__8__KET____DOT__bi__DOT__SecSig)) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [8U] 
                                                >> 6U))) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [8U] >> 5U)) 
                                        | (((~ (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__8__KET____DOT__bi__DOT__SecSig)) 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                               [8U] 
                                               >> 6U)) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [8U] 
                                                 >> 5U)))) 
                                       | (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__8__KET____DOT__bi__DOT__SecSig) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [8U] 
                                                 >> 6U))) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [8U] 
                                                >> 5U)))) 
                                      | (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__8__KET____DOT__bi__DOT__SecSig) 
                                          & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [8U] >> 6U)) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [8U] >> 5U))))));
        bufp->chgBit(oldp+335,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__8__KET____DOT__bi__DOT__SecSig) 
                                      >> 3U))));
        bufp->chgBit(oldp+336,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__8__KET____DOT__bi__DOT__SecSig) 
                                      >> 2U))));
        bufp->chgBit(oldp+337,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__8__KET____DOT__bi__DOT__SecSig) 
                                      >> 1U))));
        bufp->chgBit(oldp+338,((1U & ((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__8__KET____DOT__bi__DOT__SecSig) 
                                        >> 3U) & (IData)(
                                                         (0U 
                                                          != 
                                                          (6U 
                                                           & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__8__KET____DOT__bi__DOT__SecSig))))) 
                                      | (IData)((6U 
                                                 == 
                                                 (6U 
                                                  & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__8__KET____DOT__bi__DOT__SecSig))))))));
        bufp->chgBit(oldp+339,((1U & ((((IData)((2U 
                                                 == 
                                                 (0xeU 
                                                  & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__8__KET____DOT__bi__DOT__SecSig)))) 
                                        | (IData)((4U 
                                                   == 
                                                   (0xeU 
                                                    & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__8__KET____DOT__bi__DOT__SecSig))))) 
                                       | (IData)((8U 
                                                  == 
                                                  (0xeU 
                                                   & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__8__KET____DOT__bi__DOT__SecSig))))) 
                                      | (IData)((0xeU 
                                                 == 
                                                 (0xeU 
                                                  & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__8__KET____DOT__bi__DOT__SecSig))))))));
        bufp->chgSData(oldp+340,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                 [9U]),14);
        bufp->chgSData(oldp+341,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellout__wallacefor__BRA__9__KET____DOT__bi__COut),14);
        bufp->chgBit(oldp+342,((1U & (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__9__KET____DOT__bi__DOT__FifSig) 
                                       & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [9U] >> 0xdU) 
                                          | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [9U] >> 0xcU))) 
                                      | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [9U] >> 0xdU) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [9U] >> 0xcU))))));
        bufp->chgBit(oldp+343,((1U & ((((((~ (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__9__KET____DOT__bi__DOT__FifSig)) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [9U] 
                                                >> 0xdU))) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [9U] >> 0xcU)) 
                                        | (((~ (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__9__KET____DOT__bi__DOT__FifSig)) 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                               [9U] 
                                               >> 0xdU)) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [9U] 
                                                 >> 0xcU)))) 
                                       | (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__9__KET____DOT__bi__DOT__FifSig) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [9U] 
                                                 >> 0xdU))) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [9U] 
                                                >> 0xcU)))) 
                                      | (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__9__KET____DOT__bi__DOT__FifSig) 
                                          & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [9U] >> 0xdU)) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [9U] >> 0xcU))))));
        bufp->chgCData(oldp+344,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__9__KET____DOT__bi__DOT__SecSig),4);
        bufp->chgBit(oldp+345,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [9U] >> 0xbU))));
        bufp->chgBit(oldp+346,((1U & ((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__9__KET____DOT__bi__DOT__ForSig) 
                                        >> 1U) & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__9__KET____DOT__bi__DOT__ForSig) 
                                                  | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                     [9U] 
                                                     >> 0xbU))) 
                                      | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__9__KET____DOT__bi__DOT__ForSig) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [9U] >> 0xbU))))));
        bufp->chgBit(oldp+347,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [9U] >> 9U))));
        bufp->chgBit(oldp+348,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [9U] >> 8U))));
        bufp->chgBit(oldp+349,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [9U] >> 7U))));
        bufp->chgBit(oldp+350,((1U & (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                        [9U] >> 9U) 
                                       & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [9U] >> 8U) 
                                          | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [9U] >> 7U))) 
                                      | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [9U] >> 8U) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [9U] >> 7U))))));
        bufp->chgBit(oldp+351,((1U & ((((((~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                              [9U] 
                                              >> 9U)) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [9U] 
                                                >> 8U))) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [9U] >> 7U)) 
                                        | (((~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [9U] 
                                                >> 9U)) 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                               [9U] 
                                               >> 8U)) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [9U] 
                                                 >> 7U)))) 
                                       | (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [9U] >> 9U) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [9U] 
                                                 >> 8U))) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [9U] 
                                                >> 7U)))) 
                                      | (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [9U] >> 9U) 
                                          & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [9U] >> 8U)) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [9U] >> 7U))))));
        bufp->chgBit(oldp+352,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [9U] >> 0xaU))));
        bufp->chgBit(oldp+353,((1U & ((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__9__KET____DOT__bi__DOT__ThiSig) 
                                        >> 1U) & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__9__KET____DOT__bi__DOT__ThiSig) 
                                                  | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                     [9U] 
                                                     >> 0xaU))) 
                                      | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__9__KET____DOT__bi__DOT__ThiSig) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [9U] >> 0xaU))))));
        bufp->chgBit(oldp+354,((1U & (((((IData)((0U 
                                                  == (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__9__KET____DOT__bi__DOT__ThiSig))) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [9U] >> 0xaU)) 
                                        | ((IData)(
                                                   (1U 
                                                    == (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__9__KET____DOT__bi__DOT__ThiSig))) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [9U] 
                                                 >> 0xaU)))) 
                                       | ((IData)((2U 
                                                   == (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__9__KET____DOT__bi__DOT__ThiSig))) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [9U] 
                                                >> 0xaU)))) 
                                      | ((IData)((3U 
                                                  == (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__9__KET____DOT__bi__DOT__ThiSig))) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [9U] >> 0xaU))))));
        bufp->chgBit(oldp+355,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [9U] >> 2U))));
        bufp->chgBit(oldp+356,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [9U] >> 1U))));
        bufp->chgBit(oldp+357,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                [9U])));
        bufp->chgBit(oldp+358,((1U & (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                        [9U] >> 2U) 
                                       & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [9U] >> 1U) 
                                          | vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [9U])) | 
                                      ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                        [9U] >> 1U) 
                                       & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                       [9U])))));
        bufp->chgBit(oldp+359,((1U & ((((((~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                              [9U] 
                                              >> 2U)) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [9U] 
                                                >> 1U))) 
                                         & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [9U]) | ((
                                                   (~ 
                                                    (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                     [9U] 
                                                     >> 2U)) 
                                                   & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                      [9U] 
                                                      >> 1U)) 
                                                  & (~ 
                                                     vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                     [9U]))) 
                                       | (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [9U] >> 2U) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [9U] 
                                                 >> 1U))) 
                                          & (~ vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [9U]))) 
                                      | (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [9U] >> 2U) 
                                          & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [9U] >> 1U)) 
                                         & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [9U])))));
        bufp->chgBit(oldp+360,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [9U] >> 4U))));
        bufp->chgBit(oldp+361,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [9U] >> 3U))));
        bufp->chgBit(oldp+362,((1U & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__9__KET____DOT__bi__InData 
                                       & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [9U] >> 4U) 
                                          | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [9U] >> 3U))) 
                                      | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [9U] >> 4U) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [9U] >> 3U))))));
        bufp->chgBit(oldp+363,((1U & ((((((~ vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__9__KET____DOT__bi__InData) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [9U] 
                                                >> 4U))) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [9U] >> 3U)) 
                                        | (((~ vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__9__KET____DOT__bi__InData) 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                               [9U] 
                                               >> 4U)) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [9U] 
                                                 >> 3U)))) 
                                       | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__9__KET____DOT__bi__InData 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [9U] 
                                                 >> 4U))) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [9U] 
                                                >> 3U)))) 
                                      | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__9__KET____DOT__bi__InData 
                                          & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [9U] >> 4U)) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [9U] >> 3U))))));
        bufp->chgBit(oldp+364,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [9U] >> 0xdU))));
        bufp->chgBit(oldp+365,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [9U] >> 0xcU))));
        bufp->chgBit(oldp+366,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__9__KET____DOT__bi__DOT__SecSig))));
        bufp->chgBit(oldp+367,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [9U] >> 6U))));
        bufp->chgBit(oldp+368,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                      [9U] >> 5U))));
        bufp->chgBit(oldp+369,((1U & (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__9__KET____DOT__bi__DOT__SecSig) 
                                       & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [9U] >> 6U) 
                                          | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [9U] >> 5U))) 
                                      | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [9U] >> 6U) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [9U] >> 5U))))));
        bufp->chgBit(oldp+370,((1U & ((((((~ (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__9__KET____DOT__bi__DOT__SecSig)) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [9U] 
                                                >> 6U))) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [9U] >> 5U)) 
                                        | (((~ (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__9__KET____DOT__bi__DOT__SecSig)) 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                               [9U] 
                                               >> 6U)) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [9U] 
                                                 >> 5U)))) 
                                       | (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__9__KET____DOT__bi__DOT__SecSig) 
                                           & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                 [9U] 
                                                 >> 6U))) 
                                          & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                [9U] 
                                                >> 5U)))) 
                                      | (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__9__KET____DOT__bi__DOT__SecSig) 
                                          & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [9U] >> 6U)) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [9U] >> 5U))))));
        bufp->chgBit(oldp+371,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__9__KET____DOT__bi__DOT__SecSig) 
                                      >> 3U))));
        bufp->chgBit(oldp+372,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__9__KET____DOT__bi__DOT__SecSig) 
                                      >> 2U))));
        bufp->chgBit(oldp+373,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__9__KET____DOT__bi__DOT__SecSig) 
                                      >> 1U))));
        bufp->chgBit(oldp+374,((1U & ((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__9__KET____DOT__bi__DOT__SecSig) 
                                        >> 3U) & (IData)(
                                                         (0U 
                                                          != 
                                                          (6U 
                                                           & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__9__KET____DOT__bi__DOT__SecSig))))) 
                                      | (IData)((6U 
                                                 == 
                                                 (6U 
                                                  & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__9__KET____DOT__bi__DOT__SecSig))))))));
        bufp->chgBit(oldp+375,((1U & ((((IData)((2U 
                                                 == 
                                                 (0xeU 
                                                  & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__9__KET____DOT__bi__DOT__SecSig)))) 
                                        | (IData)((4U 
                                                   == 
                                                   (0xeU 
                                                    & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__9__KET____DOT__bi__DOT__SecSig))))) 
                                       | (IData)((8U 
                                                  == 
                                                  (0xeU 
                                                   & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__9__KET____DOT__bi__DOT__SecSig))))) 
                                      | (IData)((0xeU 
                                                 == 
                                                 (0xeU 
                                                  & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__9__KET____DOT__bi__DOT__SecSig))))))));
        bufp->chgBit(oldp+376,(((IData)(vlSelf->simu_top__DOT__soc__DOT__m0_arvalid) 
                                & (IData)(vlSelf->simu_top__DOT__soc__DOT__m0_arready))));
        bufp->chgBit(oldp+377,(((IData)(vlSelf->simu_top__DOT__soc__DOT__m0_awvalid) 
                                & (IData)(vlSelf->simu_top__DOT__soc__DOT__m0_awready))));
        bufp->chgBit(oldp+378,(((IData)(vlSelf->simu_top__DOT__soc__DOT__m0_wvalid) 
                                & (IData)(vlSelf->simu_top__DOT__soc__DOT__m0_wready))));
        bufp->chgBit(oldp+379,(((IData)(vlSelf->simu_top__DOT__soc__DOT__sram_axi_ram__DOT__ram_r_en) 
                                & (~ (IData)(vlSelf->simu_top__DOT__soc__DOT__sram_axi_ram__DOT__ram_r_a_data_arlen_last)))));
        bufp->chgBit(oldp+380,(((IData)(vlSelf->simu_top__DOT__soc__DOT__sram_axi_ram__DOT__ram_r_a_pop) 
                                & (IData)(vlSelf->simu_top__DOT__soc__DOT__sram_axi_ram__DOT__ram_r_a_queue_valid))));
        bufp->chgBit(oldp+381,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__AXI_SLAVE_MUX__DOT__s_rready) 
                                      | (~ (IData)(vlSelf->simu_top__DOT__soc__DOT__sram_axi_ram__DOT__ram_r_rvalid))))));
        bufp->chgBit(oldp+382,(((IData)(vlSelf->simu_top__DOT__soc__DOT__sram_axi_ram__DOT__ram_w_en) 
                                & (~ (IData)(vlSelf->simu_top__DOT__soc__DOT__sram_axi_ram__DOT__ram_w_wlast)))));
        bufp->chgBit(oldp+383,(((IData)(vlSelf->simu_top__DOT__soc__DOT__sram_axi_ram__DOT__ram_w_a_pop) 
                                & (IData)(vlSelf->simu_top__DOT__soc__DOT__sram_axi_ram__DOT__ram_w_a_queue_valid))));
        bufp->chgBit(oldp+384,(((IData)(vlSelf->simu_top__DOT__soc__DOT__sram_axi_ram__DOT__ram_w_a_pop) 
                                & ((IData)(vlSelf->simu_top__DOT__soc__DOT__sram_axi_ram__DOT__ram_w_b_pop) 
                                   | (~ (IData)(vlSelf->simu_top__DOT__soc__DOT__sram_axi_ram__DOT__ram_w_b_valid))))));
        bufp->chgBit(oldp+385,(((IData)(vlSelf->simu_top__DOT__soc__DOT__sram_axi_ram__DOT__ram_w_b_pop) 
                                & (IData)(vlSelf->simu_top__DOT__soc__DOT__sram_axi_ram__DOT__ram_w_b_queue_valid))));
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[2U])) {
        bufp->chgBit(oldp+386,(vlSelf->simu_top__DOT__soc__DOT__cpu_bvalid));
        bufp->chgBit(oldp+387,(vlSelf->simu_top__DOT__soc__DOT__cpu_arready));
        bufp->chgIData(oldp+388,(vlSelf->simu_top__DOT__soc__DOT__m0_rdata),32);
        bufp->chgBit(oldp+389,(vlSelf->simu_top__DOT__soc__DOT__cpu_rvalid));
        bufp->chgBit(oldp+390,(vlSelf->simu_top__DOT__soc__DOT__m0_awvalid));
        bufp->chgBit(oldp+391,(vlSelf->simu_top__DOT__soc__DOT__m0_wvalid));
        bufp->chgBit(oldp+392,(vlSelf->simu_top__DOT__soc__DOT__m0_bready));
        bufp->chgBit(oldp+393,(vlSelf->simu_top__DOT__soc__DOT__m0_arvalid));
        bufp->chgBit(oldp+394,(vlSelf->simu_top__DOT__soc__DOT__m0_rready));
        bufp->chgBit(oldp+395,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__AXI_SLAVE_MUX__DOT__s_awvalid))));
        bufp->chgBit(oldp+396,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__AXI_SLAVE_MUX__DOT__s_wvalid))));
        bufp->chgBit(oldp+397,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__AXI_SLAVE_MUX__DOT__s_bready))));
        bufp->chgBit(oldp+398,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__AXI_SLAVE_MUX__DOT__s_arvalid))));
        bufp->chgBit(oldp+399,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__AXI_SLAVE_MUX__DOT__s_rready))));
        bufp->chgBit(oldp+400,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__AXI_SLAVE_MUX__DOT__s_awvalid) 
                                      >> 3U))));
        bufp->chgBit(oldp+401,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__AXI_SLAVE_MUX__DOT__s_wvalid) 
                                      >> 3U))));
        bufp->chgBit(oldp+402,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__AXI_SLAVE_MUX__DOT__s_bready) 
                                      >> 3U))));
        bufp->chgBit(oldp+403,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__AXI_SLAVE_MUX__DOT__s_arvalid) 
                                      >> 3U))));
        bufp->chgBit(oldp+404,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__AXI_SLAVE_MUX__DOT__s_rready) 
                                      >> 3U))));
        bufp->chgBit(oldp+405,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__AXI_SLAVE_MUX__DOT__s_awvalid) 
                                      >> 2U))));
        bufp->chgBit(oldp+406,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__AXI_SLAVE_MUX__DOT__s_wvalid) 
                                      >> 2U))));
        bufp->chgBit(oldp+407,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__AXI_SLAVE_MUX__DOT__s_bready) 
                                      >> 2U))));
        bufp->chgBit(oldp+408,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__AXI_SLAVE_MUX__DOT__s_arvalid) 
                                      >> 2U))));
        bufp->chgBit(oldp+409,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__AXI_SLAVE_MUX__DOT__s_rready) 
                                      >> 2U))));
        bufp->chgBit(oldp+410,(vlSelf->simu_top__DOT__soc__DOT__conf_axi_ram__DOT__ram_r_en));
        bufp->chgCData(oldp+411,(vlSelf->simu_top__DOT__soc__DOT__conf_s_ram_wen),4);
        bufp->chgBit(oldp+412,(vlSelf->simu_top__DOT__soc__DOT__APB_DEV__DOT__apb_valid_cpu));
        bufp->chgCData(oldp+413,(vlSelf->simu_top__DOT__soc__DOT__APB_DEV__DOT__AA_axi2apb_bridge_cpu__DOT__csr_rw_sm_nxt),4);
        bufp->chgBit(oldp+414,(vlSelf->simu_top__DOT__soc__DOT__APB_DEV__DOT__nand_module__DOT__NAND__DOT__NANDtag));
        bufp->chgBit(oldp+415,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__AXI_SLAVE_MUX__DOT__s_awvalid) 
                                      >> 1U))));
        bufp->chgBit(oldp+416,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__AXI_SLAVE_MUX__DOT__s_wvalid) 
                                      >> 1U))));
        bufp->chgBit(oldp+417,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__AXI_SLAVE_MUX__DOT__s_bready) 
                                      >> 1U))));
        bufp->chgBit(oldp+418,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__AXI_SLAVE_MUX__DOT__s_arvalid) 
                                      >> 1U))));
        bufp->chgBit(oldp+419,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__AXI_SLAVE_MUX__DOT__s_rready) 
                                      >> 1U))));
        bufp->chgBit(oldp+420,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__AXI_SLAVE_MUX__DOT__s_awvalid) 
                                      >> 4U))));
        bufp->chgBit(oldp+421,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__AXI_SLAVE_MUX__DOT__s_wvalid) 
                                      >> 4U))));
        bufp->chgBit(oldp+422,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__AXI_SLAVE_MUX__DOT__s_bready) 
                                      >> 4U))));
        bufp->chgBit(oldp+423,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__AXI_SLAVE_MUX__DOT__s_arvalid) 
                                      >> 4U))));
        bufp->chgBit(oldp+424,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__AXI_SLAVE_MUX__DOT__s_rready) 
                                      >> 4U))));
        bufp->chgCData(oldp+425,(vlSelf->simu_top__DOT__soc__DOT__AXI_SLAVE_MUX__DOT__s_awvalid),5);
        bufp->chgCData(oldp+426,(vlSelf->simu_top__DOT__soc__DOT__AXI_SLAVE_MUX__DOT__s_wvalid),5);
        bufp->chgCData(oldp+427,(vlSelf->simu_top__DOT__soc__DOT__AXI_SLAVE_MUX__DOT__s_bready),5);
        bufp->chgCData(oldp+428,(vlSelf->simu_top__DOT__soc__DOT__AXI_SLAVE_MUX__DOT__s_arvalid),5);
        bufp->chgCData(oldp+429,(vlSelf->simu_top__DOT__soc__DOT__AXI_SLAVE_MUX__DOT__s_rready),5);
        bufp->chgBit(oldp+430,(vlSelf->simu_top__DOT__soc__DOT__AXI_SLAVE_MUX__DOT__wr_dir_ins));
        bufp->chgBit(oldp+431,(vlSelf->simu_top__DOT__soc__DOT__AXI_SLAVE_MUX__DOT__rd_dir_ins));
        bufp->chgBit(oldp+432,(vlSelf->simu_top__DOT__soc__DOT__conf_axi_ram__DOT__ram_r_a_data_push));
        bufp->chgBit(oldp+433,(vlSelf->simu_top__DOT__soc__DOT__conf_axi_ram__DOT__ram_r_a_pop));
        bufp->chgBit(oldp+434,(vlSelf->simu_top__DOT__soc__DOT__conf_axi_ram__DOT__ram_r_a_push));
        bufp->chgBit(oldp+435,(vlSelf->simu_top__DOT__soc__DOT__conf_axi_ram__DOT__ram_r_a_queue_push));
        bufp->chgBit(oldp+436,(vlSelf->simu_top__DOT__soc__DOT__conf_axi_ram__DOT__ram_w_a_data_push));
        bufp->chgBit(oldp+437,(vlSelf->simu_top__DOT__soc__DOT__conf_axi_ram__DOT__ram_w_a_pop));
        bufp->chgBit(oldp+438,(vlSelf->simu_top__DOT__soc__DOT__conf_axi_ram__DOT__ram_w_a_push));
        bufp->chgBit(oldp+439,(vlSelf->simu_top__DOT__soc__DOT__conf_axi_ram__DOT__ram_w_a_queue_push));
        bufp->chgBit(oldp+440,(vlSelf->simu_top__DOT__soc__DOT__conf_axi_ram__DOT__ram_w_b_pop));
        bufp->chgBit(oldp+441,(vlSelf->simu_top__DOT__soc__DOT__conf_axi_ram__DOT__ram_w_b_queue_push));
        bufp->chgBit(oldp+442,(vlSelf->simu_top__DOT__soc__DOT__conf_axi_ram__DOT__ram_w_en));
        bufp->chgBit(oldp+443,(vlSelf->simu_top__DOT__soc__DOT__conf_axi_ram__DOT__ram_w_go));
        bufp->chgBit(oldp+444,((0U != (IData)(vlSelf->simu_top__DOT__soc__DOT__conf_s_ram_wen))));
        bufp->chgBit(oldp+445,(vlSelf->simu_top__DOT__soc__DOT__confreg__DOT__write_timer));
        bufp->chgBit(oldp+446,(vlSelf->simu_top__DOT__soc__DOT__confreg__DOT__write_uart_valid));
        bufp->chgCData(oldp+447,(vlSelf->simu_top__DOT__soc__DOT__confreg__DOT__next_state),3);
        bufp->chgSData(oldp+448,(vlSelf->simu_top__DOT__soc__DOT__confreg__DOT__btn_key_tmp),16);
        bufp->chgBit(oldp+449,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__ds_allowin));
        bufp->chgBit(oldp+450,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__es_allowin));
        bufp->chgBit(oldp+451,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__ms_allowin));
        bufp->chgBit(oldp+452,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__fs_to_ds_valid));
        bufp->chgBit(oldp+453,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__ds_to_es_valid));
        bufp->chgBit(oldp+454,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__es_to_ms_valid));
        bufp->chgBit(oldp+455,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__ms_to_ws_valid));
        bufp->chgQData(oldp+456,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__mul_result),64);
        bufp->chgBit(oldp+458,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__icacop_op_en));
        bufp->chgBit(oldp+459,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__dcacop_op_en));
        bufp->chgIData(oldp+460,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__if_stage__DOT__nextpc),32);
        bufp->chgBit(oldp+461,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__fetch_en));
        bufp->chgBit(oldp+462,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__btb_add_entry));
        bufp->chgBit(oldp+463,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__btb_operate_en));
        bufp->chgBit(oldp+464,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__btb_pre_error));
        bufp->chgBit(oldp+465,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__btb_target_error));
        bufp->chgBit(oldp+466,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__id_stage__DOT__br_taken));
        bufp->chgIData(oldp+467,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__id_stage__DOT__br_target),32);
        bufp->chgBit(oldp+468,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__data_fetch));
        bufp->chgWData(oldp+469,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__ds_to_es_bus),350);
        bufp->chgWData(oldp+480,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__es_to_ms_bus),425);
        bufp->chgWData(oldp+494,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__ms_to_ws_bus),460);
        bufp->chgQData(oldp+509,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__br_bus),33);
        bufp->chgQData(oldp+511,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__ms_to_ds_forward_bus),39);
        bufp->chgBit(oldp+513,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__inst_valid));
        bufp->chgCData(oldp+514,((0xffU & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__if_stage__DOT__nextpc 
                                           >> 4U))),8);
        bufp->chgCData(oldp+515,((0xfU & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__if_stage__DOT__nextpc)),4);
        bufp->chgBit(oldp+516,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__inst_addr_ok));
        bufp->chgBit(oldp+517,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__inst_data_ok));
        bufp->chgIData(oldp+518,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__inst_rdata),32);
        bufp->chgBit(oldp+519,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__inst_ret_valid));
        bufp->chgBit(oldp+520,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__data_valid));
        bufp->chgBit(oldp+521,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__data_addr_ok));
        bufp->chgBit(oldp+522,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__axi_bridge__DOT__rd_requst_can_receive));
        bufp->chgBit(oldp+523,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__data_ret_valid));
        bufp->chgBit(oldp+524,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__preld_en));
        bufp->chgIData(oldp+525,((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__if_stage__DOT__nextpc 
                                  >> 0xdU)),19);
        bufp->chgBit(oldp+526,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__if_stage__DOT__nextpc 
                                      >> 0xcU))));
        bufp->chgCData(oldp+527,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__dcache__DOT__way0_bank0_addra),8);
        bufp->chgIData(oldp+528,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__dcache__DOT__bank_dina),32);
        bufp->chgCData(oldp+529,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__dcache__DOT__way0_bank0_wea),4);
        bufp->chgCData(oldp+530,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__dcache__DOT__way0_bank1_addra),8);
        bufp->chgCData(oldp+531,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__dcache__DOT__way0_bank1_wea),4);
        bufp->chgCData(oldp+532,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__dcache__DOT__way0_bank2_addra),8);
        bufp->chgCData(oldp+533,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__dcache__DOT__way0_bank2_wea),4);
        bufp->chgCData(oldp+534,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__dcache__DOT__way0_bank3_addra),8);
        bufp->chgCData(oldp+535,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__dcache__DOT__way0_bank3_wea),4);
        bufp->chgCData(oldp+536,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__dcache__DOT__way1_bank0_addra),8);
        bufp->chgCData(oldp+537,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__dcache__DOT__way1_bank0_wea),4);
        bufp->chgCData(oldp+538,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__dcache__DOT__way1_bank1_addra),8);
        bufp->chgCData(oldp+539,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__dcache__DOT__way1_bank1_wea),4);
        bufp->chgCData(oldp+540,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__dcache__DOT__way1_bank2_addra),8);
        bufp->chgCData(oldp+541,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__dcache__DOT__way1_bank2_wea),4);
        bufp->chgCData(oldp+542,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__dcache__DOT__way1_bank3_addra),8);
        bufp->chgCData(oldp+543,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__dcache__DOT__way1_bank3_wea),4);
        bufp->chgCData(oldp+544,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__dcache__DOT__tagv_addra),8);
        bufp->chgBit(oldp+545,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__dcache__DOT__way0_tagv_wea));
        bufp->chgBit(oldp+546,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__dcache__DOT__way1_tagv_wea));
        bufp->chgCData(oldp+547,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__dcache__DOT__main_state_index),8);
        bufp->chgBit(oldp+548,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__dcache__DOT__main_idle2lookup));
        bufp->chgBit(oldp+549,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__dcache__DOT__main_lookup2lookup));
        bufp->chgBit(oldp+550,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__dcache__DOT__tagv_wea_en));
        bufp->chgBit(oldp+551,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__dcache__DOT__way0_wr_en));
        bufp->chgBit(oldp+552,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__dcache__DOT__way1_wr_en));
        bufp->chgBit(oldp+553,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__dcache__DOT__req_or_inst_valid));
        bufp->chgBit(oldp+554,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__exe_stage__DOT__es_ready_go));
        bufp->chgBit(oldp+555,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__exe_stage__DOT__dcache_req_or_inst_en));
        bufp->chgCData(oldp+556,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__icache__DOT__bank_addra),8);
        bufp->chgIData(oldp+557,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__icache__DOT__bank_dina),32);
        bufp->chgCData(oldp+558,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__icache__DOT__way0_bank0_wea),4);
        bufp->chgCData(oldp+559,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__icache__DOT__way0_bank1_wea),4);
        bufp->chgCData(oldp+560,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__icache__DOT__way0_bank2_wea),4);
        bufp->chgCData(oldp+561,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__icache__DOT__way0_bank3_wea),4);
        bufp->chgCData(oldp+562,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__icache__DOT__way1_bank0_wea),4);
        bufp->chgCData(oldp+563,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__icache__DOT__way1_bank1_wea),4);
        bufp->chgCData(oldp+564,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__icache__DOT__way1_bank2_wea),4);
        bufp->chgCData(oldp+565,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__icache__DOT__way1_bank3_wea),4);
        bufp->chgCData(oldp+566,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__icache__DOT__tagv_addra),8);
        bufp->chgBit(oldp+567,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__icache__DOT__way0_tagv_wea));
        bufp->chgBit(oldp+568,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__icache__DOT__way1_tagv_wea));
        bufp->chgBit(oldp+569,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__icache__DOT__tagv_wea_en));
        bufp->chgBit(oldp+570,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__icache__DOT__way0_wr_en));
        bufp->chgBit(oldp+571,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__icache__DOT__way1_wr_en));
        bufp->chgCData(oldp+572,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__icache__DOT__real_offset),4);
        bufp->chgCData(oldp+573,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__icache__DOT__real_index),8);
        bufp->chgBit(oldp+574,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__icache__DOT__req_or_inst_valid));
        bufp->chgBit(oldp+575,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__id_stage__DOT__ds_ready_go));
        bufp->chgBit(oldp+576,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__id_stage__DOT__btb_pre_error_flush));
        bufp->chgBit(oldp+577,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__id_stage__DOT__rj_eq_rd));
        bufp->chgBit(oldp+578,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__id_stage__DOT__rj_lt_rd_sign));
        bufp->chgBit(oldp+579,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__id_stage__DOT__rj_lt_rd_unsign));
        bufp->chgBit(oldp+580,((1U & (IData)((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__ms_to_ds_forward_bus 
                                              >> 0x25U)))));
        bufp->chgCData(oldp+581,((0x1fU & (IData)((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__ms_to_ds_forward_bus 
                                                   >> 0x20U)))),5);
        bufp->chgIData(oldp+582,((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__ms_to_ds_forward_bus)),32);
        bufp->chgBit(oldp+583,((1U & (IData)((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__ms_to_ds_forward_bus 
                                              >> 0x26U)))));
        bufp->chgIData(oldp+584,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__id_stage__DOT__rj_value_forward_es),32);
        bufp->chgIData(oldp+585,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__id_stage__DOT__rkd_value_forward_es),32);
        bufp->chgBit(oldp+586,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__if_stage__DOT__fs_ready_go));
        bufp->chgBit(oldp+587,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__if_stage__DOT__fs_allowin));
        bufp->chgBit(oldp+588,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__if_stage__DOT__to_fs_valid));
        bufp->chgBit(oldp+589,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__if_stage__DOT__pfs_ready_go));
        bufp->chgBit(oldp+590,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__if_stage__DOT__pfs_excp_adef));
        bufp->chgBit(oldp+591,((1U & (IData)((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__br_bus 
                                              >> 0x20U)))));
        bufp->chgIData(oldp+592,((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__br_bus)),32);
        bufp->chgBit(oldp+593,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__if_stage__DOT__flush_inst_delay));
        bufp->chgBit(oldp+594,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__if_stage__DOT__flush_inst_go_dirt));
        bufp->chgBit(oldp+595,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__mem_stage__DOT__ms_ready_go));
        bufp->chgIData(oldp+596,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__mem_stage__DOT__ms_final_result),32);
        bufp->chgIData(oldp+597,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__mem_stage__DOT__ms_rdata),32);
        bufp->chgCData(oldp+598,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__mem_stage__DOT__mem_byteLoaded),8);
        bufp->chgSData(oldp+599,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__mem_stage__DOT__mem_halfLoaded),16);
        bufp->chgCData(oldp+600,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__10__KET____DOT__bi__DOT__ThiSig),2);
        bufp->chgCData(oldp+601,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__10__KET____DOT__bi__DOT__ForSig),2);
        bufp->chgBit(oldp+602,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__10__KET____DOT__bi__DOT__FifSig));
        bufp->chgBit(oldp+603,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__10__KET____DOT__bi__DOT__ForSig) 
                                      >> 1U))));
        bufp->chgBit(oldp+604,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__10__KET____DOT__bi__DOT__ForSig))));
        bufp->chgBit(oldp+605,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__10__KET____DOT__bi__DOT__ThiSig) 
                                      >> 1U))));
        bufp->chgBit(oldp+606,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__10__KET____DOT__bi__DOT__ThiSig))));
        bufp->chgCData(oldp+607,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__11__KET____DOT__bi__DOT__ThiSig),2);
        bufp->chgCData(oldp+608,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__11__KET____DOT__bi__DOT__ForSig),2);
        bufp->chgBit(oldp+609,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__11__KET____DOT__bi__DOT__FifSig));
        bufp->chgBit(oldp+610,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__11__KET____DOT__bi__DOT__ForSig) 
                                      >> 1U))));
        bufp->chgBit(oldp+611,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__11__KET____DOT__bi__DOT__ForSig))));
        bufp->chgBit(oldp+612,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__11__KET____DOT__bi__DOT__ThiSig) 
                                      >> 1U))));
        bufp->chgBit(oldp+613,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__11__KET____DOT__bi__DOT__ThiSig))));
        bufp->chgCData(oldp+614,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__12__KET____DOT__bi__DOT__ThiSig),2);
        bufp->chgCData(oldp+615,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__12__KET____DOT__bi__DOT__ForSig),2);
        bufp->chgBit(oldp+616,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__12__KET____DOT__bi__DOT__FifSig));
        bufp->chgBit(oldp+617,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__12__KET____DOT__bi__DOT__ForSig) 
                                      >> 1U))));
        bufp->chgBit(oldp+618,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__12__KET____DOT__bi__DOT__ForSig))));
        bufp->chgBit(oldp+619,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__12__KET____DOT__bi__DOT__ThiSig) 
                                      >> 1U))));
        bufp->chgBit(oldp+620,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__12__KET____DOT__bi__DOT__ThiSig))));
        bufp->chgCData(oldp+621,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__13__KET____DOT__bi__DOT__ThiSig),2);
        bufp->chgCData(oldp+622,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__13__KET____DOT__bi__DOT__ForSig),2);
        bufp->chgBit(oldp+623,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__13__KET____DOT__bi__DOT__FifSig));
        bufp->chgBit(oldp+624,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__13__KET____DOT__bi__DOT__ForSig) 
                                      >> 1U))));
        bufp->chgBit(oldp+625,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__13__KET____DOT__bi__DOT__ForSig))));
        bufp->chgBit(oldp+626,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__13__KET____DOT__bi__DOT__ThiSig) 
                                      >> 1U))));
        bufp->chgBit(oldp+627,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__13__KET____DOT__bi__DOT__ThiSig))));
        bufp->chgCData(oldp+628,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__14__KET____DOT__bi__DOT__ThiSig),2);
        bufp->chgCData(oldp+629,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__14__KET____DOT__bi__DOT__ForSig),2);
        bufp->chgBit(oldp+630,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__14__KET____DOT__bi__DOT__FifSig));
        bufp->chgBit(oldp+631,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__14__KET____DOT__bi__DOT__ForSig) 
                                      >> 1U))));
        bufp->chgBit(oldp+632,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__14__KET____DOT__bi__DOT__ForSig))));
        bufp->chgBit(oldp+633,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__14__KET____DOT__bi__DOT__ThiSig) 
                                      >> 1U))));
        bufp->chgBit(oldp+634,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__14__KET____DOT__bi__DOT__ThiSig))));
        bufp->chgCData(oldp+635,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__15__KET____DOT__bi__DOT__ThiSig),2);
        bufp->chgCData(oldp+636,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__15__KET____DOT__bi__DOT__ForSig),2);
        bufp->chgBit(oldp+637,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__15__KET____DOT__bi__DOT__FifSig));
        bufp->chgBit(oldp+638,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__15__KET____DOT__bi__DOT__ForSig) 
                                      >> 1U))));
        bufp->chgBit(oldp+639,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__15__KET____DOT__bi__DOT__ForSig))));
        bufp->chgBit(oldp+640,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__15__KET____DOT__bi__DOT__ThiSig) 
                                      >> 1U))));
        bufp->chgBit(oldp+641,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__15__KET____DOT__bi__DOT__ThiSig))));
        bufp->chgCData(oldp+642,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__16__KET____DOT__bi__DOT__ThiSig),2);
        bufp->chgCData(oldp+643,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__16__KET____DOT__bi__DOT__ForSig),2);
        bufp->chgBit(oldp+644,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__16__KET____DOT__bi__DOT__FifSig));
        bufp->chgBit(oldp+645,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__16__KET____DOT__bi__DOT__ForSig) 
                                      >> 1U))));
        bufp->chgBit(oldp+646,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__16__KET____DOT__bi__DOT__ForSig))));
        bufp->chgBit(oldp+647,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__16__KET____DOT__bi__DOT__ThiSig) 
                                      >> 1U))));
        bufp->chgBit(oldp+648,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__16__KET____DOT__bi__DOT__ThiSig))));
        bufp->chgCData(oldp+649,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__17__KET____DOT__bi__DOT__ThiSig),2);
        bufp->chgCData(oldp+650,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__17__KET____DOT__bi__DOT__ForSig),2);
        bufp->chgBit(oldp+651,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__17__KET____DOT__bi__DOT__FifSig));
        bufp->chgBit(oldp+652,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__17__KET____DOT__bi__DOT__ForSig) 
                                      >> 1U))));
        bufp->chgBit(oldp+653,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__17__KET____DOT__bi__DOT__ForSig))));
        bufp->chgBit(oldp+654,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__17__KET____DOT__bi__DOT__ThiSig) 
                                      >> 1U))));
        bufp->chgBit(oldp+655,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__17__KET____DOT__bi__DOT__ThiSig))));
        bufp->chgCData(oldp+656,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__18__KET____DOT__bi__DOT__ThiSig),2);
        bufp->chgCData(oldp+657,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__18__KET____DOT__bi__DOT__ForSig),2);
        bufp->chgBit(oldp+658,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__18__KET____DOT__bi__DOT__FifSig));
        bufp->chgBit(oldp+659,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__18__KET____DOT__bi__DOT__ForSig) 
                                      >> 1U))));
        bufp->chgBit(oldp+660,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__18__KET____DOT__bi__DOT__ForSig))));
        bufp->chgBit(oldp+661,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__18__KET____DOT__bi__DOT__ThiSig) 
                                      >> 1U))));
        bufp->chgBit(oldp+662,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__18__KET____DOT__bi__DOT__ThiSig))));
        bufp->chgCData(oldp+663,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__19__KET____DOT__bi__DOT__ThiSig),2);
        bufp->chgCData(oldp+664,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__19__KET____DOT__bi__DOT__ForSig),2);
        bufp->chgBit(oldp+665,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__19__KET____DOT__bi__DOT__FifSig));
        bufp->chgBit(oldp+666,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__19__KET____DOT__bi__DOT__ForSig) 
                                      >> 1U))));
        bufp->chgBit(oldp+667,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__19__KET____DOT__bi__DOT__ForSig))));
        bufp->chgBit(oldp+668,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__19__KET____DOT__bi__DOT__ThiSig) 
                                      >> 1U))));
        bufp->chgBit(oldp+669,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__19__KET____DOT__bi__DOT__ThiSig))));
        bufp->chgCData(oldp+670,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__1__KET____DOT__bi__DOT__ThiSig),2);
        bufp->chgCData(oldp+671,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__1__KET____DOT__bi__DOT__ForSig),2);
        bufp->chgBit(oldp+672,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__1__KET____DOT__bi__DOT__FifSig));
        bufp->chgBit(oldp+673,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__1__KET____DOT__bi__DOT__ForSig) 
                                      >> 1U))));
        bufp->chgBit(oldp+674,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__1__KET____DOT__bi__DOT__ForSig))));
        bufp->chgBit(oldp+675,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__1__KET____DOT__bi__DOT__ThiSig) 
                                      >> 1U))));
        bufp->chgBit(oldp+676,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__1__KET____DOT__bi__DOT__ThiSig))));
        bufp->chgCData(oldp+677,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__20__KET____DOT__bi__DOT__ThiSig),2);
        bufp->chgCData(oldp+678,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__20__KET____DOT__bi__DOT__ForSig),2);
        bufp->chgBit(oldp+679,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__20__KET____DOT__bi__DOT__FifSig));
        bufp->chgBit(oldp+680,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__20__KET____DOT__bi__DOT__ForSig) 
                                      >> 1U))));
        bufp->chgBit(oldp+681,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__20__KET____DOT__bi__DOT__ForSig))));
        bufp->chgBit(oldp+682,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__20__KET____DOT__bi__DOT__ThiSig) 
                                      >> 1U))));
        bufp->chgBit(oldp+683,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__20__KET____DOT__bi__DOT__ThiSig))));
        bufp->chgCData(oldp+684,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__21__KET____DOT__bi__DOT__ThiSig),2);
        bufp->chgCData(oldp+685,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__21__KET____DOT__bi__DOT__ForSig),2);
        bufp->chgBit(oldp+686,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__21__KET____DOT__bi__DOT__FifSig));
        bufp->chgBit(oldp+687,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__21__KET____DOT__bi__DOT__ForSig) 
                                      >> 1U))));
        bufp->chgBit(oldp+688,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__21__KET____DOT__bi__DOT__ForSig))));
        bufp->chgBit(oldp+689,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__21__KET____DOT__bi__DOT__ThiSig) 
                                      >> 1U))));
        bufp->chgBit(oldp+690,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__21__KET____DOT__bi__DOT__ThiSig))));
        bufp->chgCData(oldp+691,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__22__KET____DOT__bi__DOT__ThiSig),2);
        bufp->chgCData(oldp+692,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__22__KET____DOT__bi__DOT__ForSig),2);
        bufp->chgBit(oldp+693,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__22__KET____DOT__bi__DOT__FifSig));
        bufp->chgBit(oldp+694,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__22__KET____DOT__bi__DOT__ForSig) 
                                      >> 1U))));
        bufp->chgBit(oldp+695,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__22__KET____DOT__bi__DOT__ForSig))));
        bufp->chgBit(oldp+696,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__22__KET____DOT__bi__DOT__ThiSig) 
                                      >> 1U))));
        bufp->chgBit(oldp+697,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__22__KET____DOT__bi__DOT__ThiSig))));
        bufp->chgCData(oldp+698,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__23__KET____DOT__bi__DOT__ThiSig),2);
        bufp->chgCData(oldp+699,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__23__KET____DOT__bi__DOT__ForSig),2);
        bufp->chgBit(oldp+700,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__23__KET____DOT__bi__DOT__FifSig));
        bufp->chgBit(oldp+701,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__23__KET____DOT__bi__DOT__ForSig) 
                                      >> 1U))));
        bufp->chgBit(oldp+702,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__23__KET____DOT__bi__DOT__ForSig))));
        bufp->chgBit(oldp+703,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__23__KET____DOT__bi__DOT__ThiSig) 
                                      >> 1U))));
        bufp->chgBit(oldp+704,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__23__KET____DOT__bi__DOT__ThiSig))));
        bufp->chgCData(oldp+705,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__24__KET____DOT__bi__DOT__ThiSig),2);
        bufp->chgCData(oldp+706,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__24__KET____DOT__bi__DOT__ForSig),2);
        bufp->chgBit(oldp+707,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__24__KET____DOT__bi__DOT__FifSig));
        bufp->chgBit(oldp+708,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__24__KET____DOT__bi__DOT__ForSig) 
                                      >> 1U))));
        bufp->chgBit(oldp+709,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__24__KET____DOT__bi__DOT__ForSig))));
        bufp->chgBit(oldp+710,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__24__KET____DOT__bi__DOT__ThiSig) 
                                      >> 1U))));
        bufp->chgBit(oldp+711,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__24__KET____DOT__bi__DOT__ThiSig))));
        bufp->chgCData(oldp+712,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__25__KET____DOT__bi__DOT__ThiSig),2);
        bufp->chgCData(oldp+713,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__25__KET____DOT__bi__DOT__ForSig),2);
        bufp->chgBit(oldp+714,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__25__KET____DOT__bi__DOT__FifSig));
        bufp->chgBit(oldp+715,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__25__KET____DOT__bi__DOT__ForSig) 
                                      >> 1U))));
        bufp->chgBit(oldp+716,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__25__KET____DOT__bi__DOT__ForSig))));
        bufp->chgBit(oldp+717,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__25__KET____DOT__bi__DOT__ThiSig) 
                                      >> 1U))));
        bufp->chgBit(oldp+718,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__25__KET____DOT__bi__DOT__ThiSig))));
        bufp->chgCData(oldp+719,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__26__KET____DOT__bi__DOT__ThiSig),2);
        bufp->chgCData(oldp+720,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__26__KET____DOT__bi__DOT__ForSig),2);
        bufp->chgBit(oldp+721,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__26__KET____DOT__bi__DOT__FifSig));
        bufp->chgBit(oldp+722,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__26__KET____DOT__bi__DOT__ForSig) 
                                      >> 1U))));
        bufp->chgBit(oldp+723,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__26__KET____DOT__bi__DOT__ForSig))));
        bufp->chgBit(oldp+724,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__26__KET____DOT__bi__DOT__ThiSig) 
                                      >> 1U))));
        bufp->chgBit(oldp+725,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__26__KET____DOT__bi__DOT__ThiSig))));
        bufp->chgCData(oldp+726,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__27__KET____DOT__bi__DOT__ThiSig),2);
        bufp->chgCData(oldp+727,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__27__KET____DOT__bi__DOT__ForSig),2);
        bufp->chgBit(oldp+728,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__27__KET____DOT__bi__DOT__FifSig));
        bufp->chgBit(oldp+729,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__27__KET____DOT__bi__DOT__ForSig) 
                                      >> 1U))));
        bufp->chgBit(oldp+730,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__27__KET____DOT__bi__DOT__ForSig))));
        bufp->chgBit(oldp+731,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__27__KET____DOT__bi__DOT__ThiSig) 
                                      >> 1U))));
        bufp->chgBit(oldp+732,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__27__KET____DOT__bi__DOT__ThiSig))));
        bufp->chgCData(oldp+733,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__28__KET____DOT__bi__DOT__ThiSig),2);
        bufp->chgCData(oldp+734,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__28__KET____DOT__bi__DOT__ForSig),2);
        bufp->chgBit(oldp+735,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__28__KET____DOT__bi__DOT__FifSig));
        bufp->chgBit(oldp+736,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__28__KET____DOT__bi__DOT__ForSig) 
                                      >> 1U))));
        bufp->chgBit(oldp+737,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__28__KET____DOT__bi__DOT__ForSig))));
        bufp->chgBit(oldp+738,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__28__KET____DOT__bi__DOT__ThiSig) 
                                      >> 1U))));
        bufp->chgBit(oldp+739,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__28__KET____DOT__bi__DOT__ThiSig))));
        bufp->chgCData(oldp+740,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__29__KET____DOT__bi__DOT__ThiSig),2);
        bufp->chgCData(oldp+741,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__29__KET____DOT__bi__DOT__ForSig),2);
        bufp->chgBit(oldp+742,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__29__KET____DOT__bi__DOT__FifSig));
        bufp->chgBit(oldp+743,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__29__KET____DOT__bi__DOT__ForSig) 
                                      >> 1U))));
        bufp->chgBit(oldp+744,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__29__KET____DOT__bi__DOT__ForSig))));
        bufp->chgBit(oldp+745,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__29__KET____DOT__bi__DOT__ThiSig) 
                                      >> 1U))));
        bufp->chgBit(oldp+746,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__29__KET____DOT__bi__DOT__ThiSig))));
        bufp->chgCData(oldp+747,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__2__KET____DOT__bi__DOT__ThiSig),2);
        bufp->chgCData(oldp+748,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__2__KET____DOT__bi__DOT__ForSig),2);
        bufp->chgBit(oldp+749,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__2__KET____DOT__bi__DOT__FifSig));
        bufp->chgBit(oldp+750,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__2__KET____DOT__bi__DOT__ForSig) 
                                      >> 1U))));
        bufp->chgBit(oldp+751,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__2__KET____DOT__bi__DOT__ForSig))));
        bufp->chgBit(oldp+752,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__2__KET____DOT__bi__DOT__ThiSig) 
                                      >> 1U))));
        bufp->chgBit(oldp+753,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__2__KET____DOT__bi__DOT__ThiSig))));
        bufp->chgCData(oldp+754,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__30__KET____DOT__bi__DOT__ThiSig),2);
        bufp->chgCData(oldp+755,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__30__KET____DOT__bi__DOT__ForSig),2);
        bufp->chgBit(oldp+756,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__30__KET____DOT__bi__DOT__FifSig));
        bufp->chgBit(oldp+757,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__30__KET____DOT__bi__DOT__ForSig) 
                                      >> 1U))));
        bufp->chgBit(oldp+758,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__30__KET____DOT__bi__DOT__ForSig))));
        bufp->chgBit(oldp+759,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__30__KET____DOT__bi__DOT__ThiSig) 
                                      >> 1U))));
        bufp->chgBit(oldp+760,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__30__KET____DOT__bi__DOT__ThiSig))));
        bufp->chgCData(oldp+761,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__31__KET____DOT__bi__DOT__ThiSig),2);
        bufp->chgCData(oldp+762,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__31__KET____DOT__bi__DOT__ForSig),2);
        bufp->chgBit(oldp+763,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__31__KET____DOT__bi__DOT__FifSig));
        bufp->chgBit(oldp+764,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__31__KET____DOT__bi__DOT__ForSig) 
                                      >> 1U))));
        bufp->chgBit(oldp+765,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__31__KET____DOT__bi__DOT__ForSig))));
        bufp->chgBit(oldp+766,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__31__KET____DOT__bi__DOT__ThiSig) 
                                      >> 1U))));
        bufp->chgBit(oldp+767,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__31__KET____DOT__bi__DOT__ThiSig))));
        bufp->chgCData(oldp+768,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__32__KET____DOT__bi__DOT__ThiSig),2);
        bufp->chgCData(oldp+769,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__32__KET____DOT__bi__DOT__ForSig),2);
        bufp->chgBit(oldp+770,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__32__KET____DOT__bi__DOT__FifSig));
        bufp->chgBit(oldp+771,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__32__KET____DOT__bi__DOT__ForSig) 
                                      >> 1U))));
        bufp->chgBit(oldp+772,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__32__KET____DOT__bi__DOT__ForSig))));
        bufp->chgBit(oldp+773,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__32__KET____DOT__bi__DOT__ThiSig) 
                                      >> 1U))));
        bufp->chgBit(oldp+774,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__32__KET____DOT__bi__DOT__ThiSig))));
        bufp->chgCData(oldp+775,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__33__KET____DOT__bi__DOT__ThiSig),2);
        bufp->chgCData(oldp+776,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__33__KET____DOT__bi__DOT__ForSig),2);
        bufp->chgBit(oldp+777,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__33__KET____DOT__bi__DOT__FifSig));
        bufp->chgBit(oldp+778,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__33__KET____DOT__bi__DOT__ForSig) 
                                      >> 1U))));
        bufp->chgBit(oldp+779,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__33__KET____DOT__bi__DOT__ForSig))));
        bufp->chgBit(oldp+780,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__33__KET____DOT__bi__DOT__ThiSig) 
                                      >> 1U))));
        bufp->chgBit(oldp+781,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__33__KET____DOT__bi__DOT__ThiSig))));
        bufp->chgCData(oldp+782,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__34__KET____DOT__bi__DOT__ThiSig),2);
        bufp->chgCData(oldp+783,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__34__KET____DOT__bi__DOT__ForSig),2);
        bufp->chgBit(oldp+784,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__34__KET____DOT__bi__DOT__FifSig));
        bufp->chgBit(oldp+785,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__34__KET____DOT__bi__DOT__ForSig) 
                                      >> 1U))));
        bufp->chgBit(oldp+786,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__34__KET____DOT__bi__DOT__ForSig))));
        bufp->chgBit(oldp+787,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__34__KET____DOT__bi__DOT__ThiSig) 
                                      >> 1U))));
        bufp->chgBit(oldp+788,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__34__KET____DOT__bi__DOT__ThiSig))));
        bufp->chgCData(oldp+789,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__35__KET____DOT__bi__DOT__ThiSig),2);
        bufp->chgCData(oldp+790,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__35__KET____DOT__bi__DOT__ForSig),2);
        bufp->chgBit(oldp+791,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__35__KET____DOT__bi__DOT__FifSig));
        bufp->chgBit(oldp+792,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__35__KET____DOT__bi__DOT__ForSig) 
                                      >> 1U))));
        bufp->chgBit(oldp+793,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__35__KET____DOT__bi__DOT__ForSig))));
        bufp->chgBit(oldp+794,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__35__KET____DOT__bi__DOT__ThiSig) 
                                      >> 1U))));
        bufp->chgBit(oldp+795,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__35__KET____DOT__bi__DOT__ThiSig))));
        bufp->chgCData(oldp+796,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__36__KET____DOT__bi__DOT__ThiSig),2);
        bufp->chgCData(oldp+797,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__36__KET____DOT__bi__DOT__ForSig),2);
        bufp->chgBit(oldp+798,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__36__KET____DOT__bi__DOT__FifSig));
        bufp->chgBit(oldp+799,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__36__KET____DOT__bi__DOT__ForSig) 
                                      >> 1U))));
        bufp->chgBit(oldp+800,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__36__KET____DOT__bi__DOT__ForSig))));
        bufp->chgBit(oldp+801,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__36__KET____DOT__bi__DOT__ThiSig) 
                                      >> 1U))));
        bufp->chgBit(oldp+802,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__36__KET____DOT__bi__DOT__ThiSig))));
        bufp->chgCData(oldp+803,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__37__KET____DOT__bi__DOT__ThiSig),2);
        bufp->chgCData(oldp+804,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__37__KET____DOT__bi__DOT__ForSig),2);
        bufp->chgBit(oldp+805,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__37__KET____DOT__bi__DOT__FifSig));
        bufp->chgBit(oldp+806,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__37__KET____DOT__bi__DOT__ForSig) 
                                      >> 1U))));
        bufp->chgBit(oldp+807,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__37__KET____DOT__bi__DOT__ForSig))));
        bufp->chgBit(oldp+808,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__37__KET____DOT__bi__DOT__ThiSig) 
                                      >> 1U))));
        bufp->chgBit(oldp+809,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__37__KET____DOT__bi__DOT__ThiSig))));
        bufp->chgCData(oldp+810,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__38__KET____DOT__bi__DOT__ThiSig),2);
        bufp->chgCData(oldp+811,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__38__KET____DOT__bi__DOT__ForSig),2);
        bufp->chgBit(oldp+812,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__38__KET____DOT__bi__DOT__FifSig));
        bufp->chgBit(oldp+813,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__38__KET____DOT__bi__DOT__ForSig) 
                                      >> 1U))));
        bufp->chgBit(oldp+814,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__38__KET____DOT__bi__DOT__ForSig))));
        bufp->chgBit(oldp+815,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__38__KET____DOT__bi__DOT__ThiSig) 
                                      >> 1U))));
        bufp->chgBit(oldp+816,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__38__KET____DOT__bi__DOT__ThiSig))));
        bufp->chgCData(oldp+817,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__39__KET____DOT__bi__DOT__ThiSig),2);
        bufp->chgCData(oldp+818,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__39__KET____DOT__bi__DOT__ForSig),2);
        bufp->chgBit(oldp+819,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__39__KET____DOT__bi__DOT__FifSig));
        bufp->chgBit(oldp+820,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__39__KET____DOT__bi__DOT__ForSig) 
                                      >> 1U))));
        bufp->chgBit(oldp+821,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__39__KET____DOT__bi__DOT__ForSig))));
        bufp->chgBit(oldp+822,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__39__KET____DOT__bi__DOT__ThiSig) 
                                      >> 1U))));
        bufp->chgBit(oldp+823,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__39__KET____DOT__bi__DOT__ThiSig))));
        bufp->chgCData(oldp+824,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__3__KET____DOT__bi__DOT__ThiSig),2);
        bufp->chgCData(oldp+825,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__3__KET____DOT__bi__DOT__ForSig),2);
        bufp->chgBit(oldp+826,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__3__KET____DOT__bi__DOT__FifSig));
        bufp->chgBit(oldp+827,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__3__KET____DOT__bi__DOT__ForSig) 
                                      >> 1U))));
        bufp->chgBit(oldp+828,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__3__KET____DOT__bi__DOT__ForSig))));
        bufp->chgBit(oldp+829,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__3__KET____DOT__bi__DOT__ThiSig) 
                                      >> 1U))));
        bufp->chgBit(oldp+830,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__3__KET____DOT__bi__DOT__ThiSig))));
        bufp->chgCData(oldp+831,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__40__KET____DOT__bi__DOT__ThiSig),2);
        bufp->chgCData(oldp+832,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__40__KET____DOT__bi__DOT__ForSig),2);
        bufp->chgBit(oldp+833,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__40__KET____DOT__bi__DOT__FifSig));
        bufp->chgBit(oldp+834,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__40__KET____DOT__bi__DOT__ForSig) 
                                      >> 1U))));
        bufp->chgBit(oldp+835,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__40__KET____DOT__bi__DOT__ForSig))));
        bufp->chgBit(oldp+836,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__40__KET____DOT__bi__DOT__ThiSig) 
                                      >> 1U))));
        bufp->chgBit(oldp+837,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__40__KET____DOT__bi__DOT__ThiSig))));
        bufp->chgCData(oldp+838,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__41__KET____DOT__bi__DOT__ThiSig),2);
        bufp->chgCData(oldp+839,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__41__KET____DOT__bi__DOT__ForSig),2);
        bufp->chgBit(oldp+840,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__41__KET____DOT__bi__DOT__FifSig));
        bufp->chgBit(oldp+841,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__41__KET____DOT__bi__DOT__ForSig) 
                                      >> 1U))));
        bufp->chgBit(oldp+842,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__41__KET____DOT__bi__DOT__ForSig))));
        bufp->chgBit(oldp+843,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__41__KET____DOT__bi__DOT__ThiSig) 
                                      >> 1U))));
        bufp->chgBit(oldp+844,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__41__KET____DOT__bi__DOT__ThiSig))));
        bufp->chgCData(oldp+845,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__42__KET____DOT__bi__DOT__ThiSig),2);
        bufp->chgCData(oldp+846,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__42__KET____DOT__bi__DOT__ForSig),2);
        bufp->chgBit(oldp+847,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__42__KET____DOT__bi__DOT__FifSig));
        bufp->chgBit(oldp+848,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__42__KET____DOT__bi__DOT__ForSig) 
                                      >> 1U))));
        bufp->chgBit(oldp+849,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__42__KET____DOT__bi__DOT__ForSig))));
        bufp->chgBit(oldp+850,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__42__KET____DOT__bi__DOT__ThiSig) 
                                      >> 1U))));
        bufp->chgBit(oldp+851,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__42__KET____DOT__bi__DOT__ThiSig))));
        bufp->chgCData(oldp+852,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__43__KET____DOT__bi__DOT__ThiSig),2);
        bufp->chgCData(oldp+853,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__43__KET____DOT__bi__DOT__ForSig),2);
        bufp->chgBit(oldp+854,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__43__KET____DOT__bi__DOT__FifSig));
        bufp->chgBit(oldp+855,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__43__KET____DOT__bi__DOT__ForSig) 
                                      >> 1U))));
        bufp->chgBit(oldp+856,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__43__KET____DOT__bi__DOT__ForSig))));
        bufp->chgBit(oldp+857,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__43__KET____DOT__bi__DOT__ThiSig) 
                                      >> 1U))));
        bufp->chgBit(oldp+858,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__43__KET____DOT__bi__DOT__ThiSig))));
        bufp->chgCData(oldp+859,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__44__KET____DOT__bi__DOT__ThiSig),2);
        bufp->chgCData(oldp+860,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__44__KET____DOT__bi__DOT__ForSig),2);
        bufp->chgBit(oldp+861,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__44__KET____DOT__bi__DOT__FifSig));
        bufp->chgBit(oldp+862,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__44__KET____DOT__bi__DOT__ForSig) 
                                      >> 1U))));
        bufp->chgBit(oldp+863,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__44__KET____DOT__bi__DOT__ForSig))));
        bufp->chgBit(oldp+864,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__44__KET____DOT__bi__DOT__ThiSig) 
                                      >> 1U))));
        bufp->chgBit(oldp+865,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__44__KET____DOT__bi__DOT__ThiSig))));
        bufp->chgCData(oldp+866,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__45__KET____DOT__bi__DOT__ThiSig),2);
        bufp->chgCData(oldp+867,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__45__KET____DOT__bi__DOT__ForSig),2);
        bufp->chgBit(oldp+868,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__45__KET____DOT__bi__DOT__FifSig));
        bufp->chgBit(oldp+869,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__45__KET____DOT__bi__DOT__ForSig) 
                                      >> 1U))));
        bufp->chgBit(oldp+870,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__45__KET____DOT__bi__DOT__ForSig))));
        bufp->chgBit(oldp+871,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__45__KET____DOT__bi__DOT__ThiSig) 
                                      >> 1U))));
        bufp->chgBit(oldp+872,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__45__KET____DOT__bi__DOT__ThiSig))));
        bufp->chgCData(oldp+873,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__46__KET____DOT__bi__DOT__ThiSig),2);
        bufp->chgCData(oldp+874,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__46__KET____DOT__bi__DOT__ForSig),2);
        bufp->chgBit(oldp+875,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__46__KET____DOT__bi__DOT__FifSig));
        bufp->chgBit(oldp+876,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__46__KET____DOT__bi__DOT__ForSig) 
                                      >> 1U))));
        bufp->chgBit(oldp+877,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__46__KET____DOT__bi__DOT__ForSig))));
        bufp->chgBit(oldp+878,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__46__KET____DOT__bi__DOT__ThiSig) 
                                      >> 1U))));
        bufp->chgBit(oldp+879,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__46__KET____DOT__bi__DOT__ThiSig))));
        bufp->chgCData(oldp+880,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__47__KET____DOT__bi__DOT__ThiSig),2);
        bufp->chgCData(oldp+881,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__47__KET____DOT__bi__DOT__ForSig),2);
        bufp->chgBit(oldp+882,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__47__KET____DOT__bi__DOT__FifSig));
        bufp->chgBit(oldp+883,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__47__KET____DOT__bi__DOT__ForSig) 
                                      >> 1U))));
        bufp->chgBit(oldp+884,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__47__KET____DOT__bi__DOT__ForSig))));
        bufp->chgBit(oldp+885,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__47__KET____DOT__bi__DOT__ThiSig) 
                                      >> 1U))));
        bufp->chgBit(oldp+886,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__47__KET____DOT__bi__DOT__ThiSig))));
        bufp->chgCData(oldp+887,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__48__KET____DOT__bi__DOT__ThiSig),2);
        bufp->chgCData(oldp+888,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__48__KET____DOT__bi__DOT__ForSig),2);
        bufp->chgBit(oldp+889,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__48__KET____DOT__bi__DOT__FifSig));
        bufp->chgBit(oldp+890,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__48__KET____DOT__bi__DOT__ForSig) 
                                      >> 1U))));
        bufp->chgBit(oldp+891,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__48__KET____DOT__bi__DOT__ForSig))));
        bufp->chgBit(oldp+892,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__48__KET____DOT__bi__DOT__ThiSig) 
                                      >> 1U))));
        bufp->chgBit(oldp+893,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__48__KET____DOT__bi__DOT__ThiSig))));
        bufp->chgCData(oldp+894,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__49__KET____DOT__bi__DOT__ThiSig),2);
        bufp->chgCData(oldp+895,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__49__KET____DOT__bi__DOT__ForSig),2);
        bufp->chgBit(oldp+896,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__49__KET____DOT__bi__DOT__FifSig));
        bufp->chgBit(oldp+897,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__49__KET____DOT__bi__DOT__ForSig) 
                                      >> 1U))));
        bufp->chgBit(oldp+898,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__49__KET____DOT__bi__DOT__ForSig))));
        bufp->chgBit(oldp+899,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__49__KET____DOT__bi__DOT__ThiSig) 
                                      >> 1U))));
        bufp->chgBit(oldp+900,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__49__KET____DOT__bi__DOT__ThiSig))));
        bufp->chgCData(oldp+901,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__4__KET____DOT__bi__DOT__ThiSig),2);
        bufp->chgCData(oldp+902,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__4__KET____DOT__bi__DOT__ForSig),2);
        bufp->chgBit(oldp+903,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__4__KET____DOT__bi__DOT__FifSig));
        bufp->chgBit(oldp+904,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__4__KET____DOT__bi__DOT__ForSig) 
                                      >> 1U))));
        bufp->chgBit(oldp+905,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__4__KET____DOT__bi__DOT__ForSig))));
        bufp->chgBit(oldp+906,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__4__KET____DOT__bi__DOT__ThiSig) 
                                      >> 1U))));
        bufp->chgBit(oldp+907,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__4__KET____DOT__bi__DOT__ThiSig))));
        bufp->chgCData(oldp+908,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__50__KET____DOT__bi__DOT__ThiSig),2);
        bufp->chgCData(oldp+909,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__50__KET____DOT__bi__DOT__ForSig),2);
        bufp->chgBit(oldp+910,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__50__KET____DOT__bi__DOT__FifSig));
        bufp->chgBit(oldp+911,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__50__KET____DOT__bi__DOT__ForSig) 
                                      >> 1U))));
        bufp->chgBit(oldp+912,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__50__KET____DOT__bi__DOT__ForSig))));
        bufp->chgBit(oldp+913,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__50__KET____DOT__bi__DOT__ThiSig) 
                                      >> 1U))));
        bufp->chgBit(oldp+914,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__50__KET____DOT__bi__DOT__ThiSig))));
        bufp->chgCData(oldp+915,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__51__KET____DOT__bi__DOT__ThiSig),2);
        bufp->chgCData(oldp+916,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__51__KET____DOT__bi__DOT__ForSig),2);
        bufp->chgBit(oldp+917,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__51__KET____DOT__bi__DOT__FifSig));
        bufp->chgBit(oldp+918,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__51__KET____DOT__bi__DOT__ForSig) 
                                      >> 1U))));
        bufp->chgBit(oldp+919,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__51__KET____DOT__bi__DOT__ForSig))));
        bufp->chgBit(oldp+920,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__51__KET____DOT__bi__DOT__ThiSig) 
                                      >> 1U))));
        bufp->chgBit(oldp+921,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__51__KET____DOT__bi__DOT__ThiSig))));
        bufp->chgCData(oldp+922,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__52__KET____DOT__bi__DOT__ThiSig),2);
        bufp->chgCData(oldp+923,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__52__KET____DOT__bi__DOT__ForSig),2);
        bufp->chgBit(oldp+924,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__52__KET____DOT__bi__DOT__FifSig));
        bufp->chgBit(oldp+925,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__52__KET____DOT__bi__DOT__ForSig) 
                                      >> 1U))));
        bufp->chgBit(oldp+926,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__52__KET____DOT__bi__DOT__ForSig))));
        bufp->chgBit(oldp+927,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__52__KET____DOT__bi__DOT__ThiSig) 
                                      >> 1U))));
        bufp->chgBit(oldp+928,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__52__KET____DOT__bi__DOT__ThiSig))));
        bufp->chgCData(oldp+929,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__53__KET____DOT__bi__DOT__ThiSig),2);
        bufp->chgCData(oldp+930,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__53__KET____DOT__bi__DOT__ForSig),2);
        bufp->chgBit(oldp+931,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__53__KET____DOT__bi__DOT__FifSig));
        bufp->chgBit(oldp+932,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__53__KET____DOT__bi__DOT__ForSig) 
                                      >> 1U))));
        bufp->chgBit(oldp+933,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__53__KET____DOT__bi__DOT__ForSig))));
        bufp->chgBit(oldp+934,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__53__KET____DOT__bi__DOT__ThiSig) 
                                      >> 1U))));
        bufp->chgBit(oldp+935,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__53__KET____DOT__bi__DOT__ThiSig))));
        bufp->chgCData(oldp+936,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__54__KET____DOT__bi__DOT__ThiSig),2);
        bufp->chgCData(oldp+937,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__54__KET____DOT__bi__DOT__ForSig),2);
        bufp->chgBit(oldp+938,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__54__KET____DOT__bi__DOT__FifSig));
        bufp->chgBit(oldp+939,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__54__KET____DOT__bi__DOT__ForSig) 
                                      >> 1U))));
        bufp->chgBit(oldp+940,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__54__KET____DOT__bi__DOT__ForSig))));
        bufp->chgBit(oldp+941,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__54__KET____DOT__bi__DOT__ThiSig) 
                                      >> 1U))));
        bufp->chgBit(oldp+942,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__54__KET____DOT__bi__DOT__ThiSig))));
        bufp->chgCData(oldp+943,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__55__KET____DOT__bi__DOT__ThiSig),2);
        bufp->chgCData(oldp+944,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__55__KET____DOT__bi__DOT__ForSig),2);
        bufp->chgBit(oldp+945,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__55__KET____DOT__bi__DOT__FifSig));
        bufp->chgBit(oldp+946,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__55__KET____DOT__bi__DOT__ForSig) 
                                      >> 1U))));
        bufp->chgBit(oldp+947,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__55__KET____DOT__bi__DOT__ForSig))));
        bufp->chgBit(oldp+948,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__55__KET____DOT__bi__DOT__ThiSig) 
                                      >> 1U))));
        bufp->chgBit(oldp+949,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__55__KET____DOT__bi__DOT__ThiSig))));
        bufp->chgCData(oldp+950,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__56__KET____DOT__bi__DOT__ThiSig),2);
        bufp->chgCData(oldp+951,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__56__KET____DOT__bi__DOT__ForSig),2);
        bufp->chgBit(oldp+952,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__56__KET____DOT__bi__DOT__FifSig));
        bufp->chgBit(oldp+953,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__56__KET____DOT__bi__DOT__ForSig) 
                                      >> 1U))));
        bufp->chgBit(oldp+954,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__56__KET____DOT__bi__DOT__ForSig))));
        bufp->chgBit(oldp+955,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__56__KET____DOT__bi__DOT__ThiSig) 
                                      >> 1U))));
        bufp->chgBit(oldp+956,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__56__KET____DOT__bi__DOT__ThiSig))));
        bufp->chgCData(oldp+957,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__57__KET____DOT__bi__DOT__ThiSig),2);
        bufp->chgCData(oldp+958,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__57__KET____DOT__bi__DOT__ForSig),2);
        bufp->chgBit(oldp+959,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__57__KET____DOT__bi__DOT__FifSig));
        bufp->chgBit(oldp+960,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__57__KET____DOT__bi__DOT__ForSig) 
                                      >> 1U))));
        bufp->chgBit(oldp+961,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__57__KET____DOT__bi__DOT__ForSig))));
        bufp->chgBit(oldp+962,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__57__KET____DOT__bi__DOT__ThiSig) 
                                      >> 1U))));
        bufp->chgBit(oldp+963,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__57__KET____DOT__bi__DOT__ThiSig))));
        bufp->chgCData(oldp+964,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__58__KET____DOT__bi__DOT__ThiSig),2);
        bufp->chgCData(oldp+965,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__58__KET____DOT__bi__DOT__ForSig),2);
        bufp->chgBit(oldp+966,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__58__KET____DOT__bi__DOT__FifSig));
        bufp->chgBit(oldp+967,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__58__KET____DOT__bi__DOT__ForSig) 
                                      >> 1U))));
        bufp->chgBit(oldp+968,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__58__KET____DOT__bi__DOT__ForSig))));
        bufp->chgBit(oldp+969,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__58__KET____DOT__bi__DOT__ThiSig) 
                                      >> 1U))));
        bufp->chgBit(oldp+970,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__58__KET____DOT__bi__DOT__ThiSig))));
        bufp->chgCData(oldp+971,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__59__KET____DOT__bi__DOT__ThiSig),2);
        bufp->chgCData(oldp+972,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__59__KET____DOT__bi__DOT__ForSig),2);
        bufp->chgBit(oldp+973,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__59__KET____DOT__bi__DOT__FifSig));
        bufp->chgBit(oldp+974,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__59__KET____DOT__bi__DOT__ForSig) 
                                      >> 1U))));
        bufp->chgBit(oldp+975,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__59__KET____DOT__bi__DOT__ForSig))));
        bufp->chgBit(oldp+976,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__59__KET____DOT__bi__DOT__ThiSig) 
                                      >> 1U))));
        bufp->chgBit(oldp+977,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__59__KET____DOT__bi__DOT__ThiSig))));
        bufp->chgCData(oldp+978,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__5__KET____DOT__bi__DOT__ThiSig),2);
        bufp->chgCData(oldp+979,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__5__KET____DOT__bi__DOT__ForSig),2);
        bufp->chgBit(oldp+980,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__5__KET____DOT__bi__DOT__FifSig));
        bufp->chgBit(oldp+981,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__5__KET____DOT__bi__DOT__ForSig) 
                                      >> 1U))));
        bufp->chgBit(oldp+982,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__5__KET____DOT__bi__DOT__ForSig))));
        bufp->chgBit(oldp+983,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__5__KET____DOT__bi__DOT__ThiSig) 
                                      >> 1U))));
        bufp->chgBit(oldp+984,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__5__KET____DOT__bi__DOT__ThiSig))));
        bufp->chgCData(oldp+985,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__60__KET____DOT__bi__DOT__ThiSig),2);
        bufp->chgCData(oldp+986,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__60__KET____DOT__bi__DOT__ForSig),2);
        bufp->chgBit(oldp+987,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__60__KET____DOT__bi__DOT__FifSig));
        bufp->chgBit(oldp+988,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__60__KET____DOT__bi__DOT__ForSig) 
                                      >> 1U))));
        bufp->chgBit(oldp+989,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__60__KET____DOT__bi__DOT__ForSig))));
        bufp->chgBit(oldp+990,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__60__KET____DOT__bi__DOT__ThiSig) 
                                      >> 1U))));
        bufp->chgBit(oldp+991,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__60__KET____DOT__bi__DOT__ThiSig))));
        bufp->chgCData(oldp+992,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__61__KET____DOT__bi__DOT__ThiSig),2);
        bufp->chgCData(oldp+993,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__61__KET____DOT__bi__DOT__ForSig),2);
        bufp->chgBit(oldp+994,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__61__KET____DOT__bi__DOT__FifSig));
        bufp->chgBit(oldp+995,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__61__KET____DOT__bi__DOT__ForSig) 
                                      >> 1U))));
        bufp->chgBit(oldp+996,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__61__KET____DOT__bi__DOT__ForSig))));
        bufp->chgBit(oldp+997,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__61__KET____DOT__bi__DOT__ThiSig) 
                                      >> 1U))));
        bufp->chgBit(oldp+998,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__61__KET____DOT__bi__DOT__ThiSig))));
        bufp->chgCData(oldp+999,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__62__KET____DOT__bi__DOT__ThiSig),2);
        bufp->chgCData(oldp+1000,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__62__KET____DOT__bi__DOT__ForSig),2);
        bufp->chgBit(oldp+1001,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__62__KET____DOT__bi__DOT__FifSig));
        bufp->chgBit(oldp+1002,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__62__KET____DOT__bi__DOT__ForSig) 
                                       >> 1U))));
        bufp->chgBit(oldp+1003,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__62__KET____DOT__bi__DOT__ForSig))));
        bufp->chgBit(oldp+1004,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__62__KET____DOT__bi__DOT__ThiSig) 
                                       >> 1U))));
        bufp->chgBit(oldp+1005,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__62__KET____DOT__bi__DOT__ThiSig))));
        bufp->chgCData(oldp+1006,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__63__KET____DOT__bi__DOT__ThiSig),2);
        bufp->chgCData(oldp+1007,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__63__KET____DOT__bi__DOT__ForSig),2);
        bufp->chgBit(oldp+1008,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__63__KET____DOT__bi__DOT__FifSig));
        bufp->chgBit(oldp+1009,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__63__KET____DOT__bi__DOT__ForSig) 
                                       >> 1U))));
        bufp->chgBit(oldp+1010,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__63__KET____DOT__bi__DOT__ForSig))));
        bufp->chgBit(oldp+1011,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__63__KET____DOT__bi__DOT__ThiSig) 
                                       >> 1U))));
        bufp->chgBit(oldp+1012,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__63__KET____DOT__bi__DOT__ThiSig))));
        bufp->chgCData(oldp+1013,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__6__KET____DOT__bi__DOT__ThiSig),2);
        bufp->chgCData(oldp+1014,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__6__KET____DOT__bi__DOT__ForSig),2);
        bufp->chgBit(oldp+1015,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__6__KET____DOT__bi__DOT__FifSig));
        bufp->chgBit(oldp+1016,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__6__KET____DOT__bi__DOT__ForSig) 
                                       >> 1U))));
        bufp->chgBit(oldp+1017,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__6__KET____DOT__bi__DOT__ForSig))));
        bufp->chgBit(oldp+1018,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__6__KET____DOT__bi__DOT__ThiSig) 
                                       >> 1U))));
        bufp->chgBit(oldp+1019,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__6__KET____DOT__bi__DOT__ThiSig))));
        bufp->chgCData(oldp+1020,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__7__KET____DOT__bi__DOT__ThiSig),2);
        bufp->chgCData(oldp+1021,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__7__KET____DOT__bi__DOT__ForSig),2);
        bufp->chgBit(oldp+1022,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__7__KET____DOT__bi__DOT__FifSig));
        bufp->chgBit(oldp+1023,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__7__KET____DOT__bi__DOT__ForSig) 
                                       >> 1U))));
        bufp->chgBit(oldp+1024,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__7__KET____DOT__bi__DOT__ForSig))));
        bufp->chgBit(oldp+1025,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__7__KET____DOT__bi__DOT__ThiSig) 
                                       >> 1U))));
        bufp->chgBit(oldp+1026,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__7__KET____DOT__bi__DOT__ThiSig))));
        bufp->chgCData(oldp+1027,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__8__KET____DOT__bi__DOT__ThiSig),2);
        bufp->chgCData(oldp+1028,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__8__KET____DOT__bi__DOT__ForSig),2);
        bufp->chgBit(oldp+1029,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__8__KET____DOT__bi__DOT__FifSig));
        bufp->chgBit(oldp+1030,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__8__KET____DOT__bi__DOT__ForSig) 
                                       >> 1U))));
        bufp->chgBit(oldp+1031,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__8__KET____DOT__bi__DOT__ForSig))));
        bufp->chgBit(oldp+1032,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__8__KET____DOT__bi__DOT__ThiSig) 
                                       >> 1U))));
        bufp->chgBit(oldp+1033,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__8__KET____DOT__bi__DOT__ThiSig))));
        bufp->chgCData(oldp+1034,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__9__KET____DOT__bi__DOT__ThiSig),2);
        bufp->chgCData(oldp+1035,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__9__KET____DOT__bi__DOT__ForSig),2);
        bufp->chgBit(oldp+1036,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__9__KET____DOT__bi__DOT__FifSig));
        bufp->chgBit(oldp+1037,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__9__KET____DOT__bi__DOT__ForSig) 
                                       >> 1U))));
        bufp->chgBit(oldp+1038,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__9__KET____DOT__bi__DOT__ForSig))));
        bufp->chgBit(oldp+1039,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__9__KET____DOT__bi__DOT__ThiSig) 
                                       >> 1U))));
        bufp->chgBit(oldp+1040,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__9__KET____DOT__bi__DOT__ThiSig))));
        bufp->chgBit(oldp+1041,(vlSelf->simu_top__DOT__soc__DOT__sram_axi_ram__DOT__ram_r_a_data_push));
        bufp->chgBit(oldp+1042,(vlSelf->simu_top__DOT__soc__DOT__sram_axi_ram__DOT__ram_r_a_pop));
        bufp->chgBit(oldp+1043,(vlSelf->simu_top__DOT__soc__DOT__sram_axi_ram__DOT__ram_r_a_push));
        bufp->chgBit(oldp+1044,(vlSelf->simu_top__DOT__soc__DOT__sram_axi_ram__DOT__ram_r_a_queue_push));
        bufp->chgBit(oldp+1045,(vlSelf->simu_top__DOT__soc__DOT__sram_axi_ram__DOT__ram_r_en));
        bufp->chgBit(oldp+1046,(vlSelf->simu_top__DOT__soc__DOT__sram_axi_ram__DOT__ram_w_a_data_push));
        bufp->chgBit(oldp+1047,(vlSelf->simu_top__DOT__soc__DOT__sram_axi_ram__DOT__ram_w_a_pop));
        bufp->chgBit(oldp+1048,(vlSelf->simu_top__DOT__soc__DOT__sram_axi_ram__DOT__ram_w_a_push));
        bufp->chgBit(oldp+1049,(vlSelf->simu_top__DOT__soc__DOT__sram_axi_ram__DOT__ram_w_a_queue_push));
        bufp->chgBit(oldp+1050,(vlSelf->simu_top__DOT__soc__DOT__sram_axi_ram__DOT__ram_w_b_pop));
        bufp->chgBit(oldp+1051,(vlSelf->simu_top__DOT__soc__DOT__sram_axi_ram__DOT__ram_w_b_queue_push));
        bufp->chgBit(oldp+1052,(vlSelf->simu_top__DOT__soc__DOT__sram_axi_ram__DOT__ram_w_en));
        bufp->chgBit(oldp+1053,(vlSelf->simu_top__DOT__soc__DOT__sram_axi_ram__DOT__ram_w_go));
    }
    bufp->chgBit(oldp+1054,(vlSelf->aclk));
    bufp->chgBit(oldp+1055,(vlSelf->aresetn));
    bufp->chgBit(oldp+1056,(vlSelf->enable_delay));
    bufp->chgIData(oldp+1057,(vlSelf->random_seed),23);
    bufp->chgBit(oldp+1058,(vlSelf->ram_ren));
    bufp->chgIData(oldp+1059,(vlSelf->ram_raddr),32);
    bufp->chgIData(oldp+1060,(vlSelf->ram_rdata),32);
    bufp->chgCData(oldp+1061,(vlSelf->ram_wen),4);
    bufp->chgIData(oldp+1062,(vlSelf->ram_waddr),32);
    bufp->chgIData(oldp+1063,(vlSelf->ram_wdata),32);
    bufp->chgIData(oldp+1064,(vlSelf->debug0_wb_pc),32);
    bufp->chgBit(oldp+1065,(vlSelf->debug0_wb_rf_wen));
    bufp->chgCData(oldp+1066,(vlSelf->debug0_wb_rf_wnum),5);
    bufp->chgIData(oldp+1067,(vlSelf->debug0_wb_rf_wdata),32);
    bufp->chgIData(oldp+1068,(vlSelf->num_data),32);
    bufp->chgBit(oldp+1069,(vlSelf->open_trace));
    bufp->chgBit(oldp+1070,(vlSelf->num_monitor));
    bufp->chgCData(oldp+1071,(vlSelf->confreg_uart_data),8);
    bufp->chgBit(oldp+1072,(vlSelf->write_uart_valid));
    bufp->chgWData(oldp+1073,(vlSelf->uart_ctr_bus),128);
    bufp->chgBit(oldp+1077,(vlSelf->uart_rx));
    bufp->chgBit(oldp+1078,(vlSelf->uart_tx));
    bufp->chgSData(oldp+1079,(vlSelf->led),16);
    bufp->chgCData(oldp+1080,(vlSelf->led_rg0),2);
    bufp->chgCData(oldp+1081,(vlSelf->led_rg1),2);
    bufp->chgCData(oldp+1082,(vlSelf->num_csn),8);
    bufp->chgCData(oldp+1083,(vlSelf->num_a_g),7);
    bufp->chgCData(oldp+1084,(vlSelf->btn_key_col),4);
    bufp->chgCData(oldp+1085,(vlSelf->btn_key_row),4);
    bufp->chgCData(oldp+1086,(vlSelf->btn_step),2);
    bufp->chgCData(oldp+1087,(vlSelf->__SYM__switch),8);
    bufp->chgBit(oldp+1088,(((IData)(vlSelf->simu_top__DOT__soc__DOT__m0_awready) 
                             & ((IData)(vlSelf->simu_top__DOT__soc__DOT__delay__DOT__mask_aw) 
                                | (~ (IData)(vlSelf->enable_delay))))));
    bufp->chgBit(oldp+1089,(((IData)(vlSelf->simu_top__DOT__soc__DOT__m0_wready) 
                             & ((IData)(vlSelf->simu_top__DOT__soc__DOT__delay__DOT__mask_w) 
                                | (~ (IData)(vlSelf->enable_delay))))));
    bufp->chgBit(oldp+1090,((1U & (~ (IData)(vlSelf->aresetn)))));
    bufp->chgBit(oldp+1091,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__APB_DEV__DOT__uart0__DOT__isomode)
                                    ? ((~ (IData)(vlSelf->simu_top__DOT__soc__DOT__APB_DEV__DOT__uart0__DOT__rx_en)) 
                                       | (IData)(vlSelf->uart_tx))
                                    : (IData)(vlSelf->uart_rx)))));
    bufp->chgBit(oldp+1092,((1U & ((~ (IData)(vlSelf->aresetn)) 
                                   | (IData)(vlSelf->simu_top__DOT__soc__DOT__conf_axi_ram__DOT__ram_r_a_pop)))));
    bufp->chgIData(oldp+1093,(vlSelf->__SYM__switch),32);
    bufp->chgIData(oldp+1094,(((0x8000U & ((IData)(vlSelf->__SYM__switch) 
                                           << 8U)) 
                               | ((0x2000U & ((IData)(vlSelf->__SYM__switch) 
                                              << 7U)) 
                                  | ((0x800U & ((IData)(vlSelf->__SYM__switch) 
                                                << 6U)) 
                                     | ((0x200U & ((IData)(vlSelf->__SYM__switch) 
                                                   << 5U)) 
                                        | ((0x80U & 
                                            ((IData)(vlSelf->__SYM__switch) 
                                             << 4U)) 
                                           | ((0x20U 
                                               & ((IData)(vlSelf->__SYM__switch) 
                                                  << 3U)) 
                                              | ((8U 
                                                  & ((IData)(vlSelf->__SYM__switch) 
                                                     << 2U)) 
                                                 | (2U 
                                                    & ((IData)(vlSelf->__SYM__switch) 
                                                       << 1U)))))))))),32);
    bufp->chgBit(oldp+1095,(((0U == (IData)(vlSelf->simu_top__DOT__soc__DOT__confreg__DOT__state)) 
                             & (~ (IData)((0xfU == (IData)(vlSelf->btn_key_row)))))));
    bufp->chgBit(oldp+1096,(((7U == (IData)(vlSelf->simu_top__DOT__soc__DOT__confreg__DOT__state)) 
                             & (0xfU == (IData)(vlSelf->btn_key_row)))));
    bufp->chgBit(oldp+1097,(((IData)(vlSelf->simu_top__DOT__soc__DOT__confreg__DOT__btn_step0_r) 
                             & (~ (IData)(vlSelf->btn_step)))));
    bufp->chgBit(oldp+1098,((1U & ((~ (IData)(vlSelf->simu_top__DOT__soc__DOT__confreg__DOT__btn_step0_r)) 
                                   & (IData)(vlSelf->btn_step)))));
    bufp->chgBit(oldp+1099,(((IData)(vlSelf->simu_top__DOT__soc__DOT__confreg__DOT__btn_step1_r) 
                             & (~ ((IData)(vlSelf->btn_step) 
                                   >> 1U)))));
    bufp->chgBit(oldp+1100,(((~ (IData)(vlSelf->simu_top__DOT__soc__DOT__confreg__DOT__btn_step1_r)) 
                             & ((IData)(vlSelf->btn_step) 
                                >> 1U))));
    bufp->chgBit(oldp+1101,((1U & ((~ (IData)(vlSelf->aresetn)) 
                                   | (IData)(vlSelf->simu_top__DOT__soc__DOT__sram_axi_ram__DOT__ram_r_a_pop)))));
}
