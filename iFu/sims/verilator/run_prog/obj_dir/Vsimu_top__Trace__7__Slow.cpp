// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_fst_c.h"
#include "Vsimu_top__Syms.h"


VL_ATTR_COLD void Vsimu_top___024root__trace_full_sub_8(Vsimu_top___024root* vlSelf, VerilatedFst::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vsimu_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsimu_top___024root__trace_full_sub_8\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullSData(oldp+11900,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                [0x27U]),14);
    bufp->fullSData(oldp+11901,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellout__wallacefor__BRA__39__KET____DOT__bi__COut),14);
    bufp->fullBit(oldp+11902,((1U & (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__39__KET____DOT__bi__DOT__FifSig) 
                                      & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x27U] >> 0xdU) 
                                         | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x27U] 
                                            >> 0xcU))) 
                                     | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x27U] >> 0xdU) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x27U] 
                                           >> 0xcU))))));
    bufp->fullBit(oldp+11903,((1U & ((((((~ (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__39__KET____DOT__bi__DOT__FifSig)) 
                                         & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                               [0x27U] 
                                               >> 0xdU))) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x27U] 
                                           >> 0xcU)) 
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
                                           [0x27U] 
                                           >> 0xcU))))));
    bufp->fullCData(oldp+11904,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__39__KET____DOT__bi__DOT__SecSig),4);
    bufp->fullBit(oldp+11905,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x27U] >> 0xbU))));
    bufp->fullBit(oldp+11906,((1U & ((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__39__KET____DOT__bi__DOT__ForSig) 
                                       >> 1U) & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__39__KET____DOT__bi__DOT__ForSig) 
                                                 | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                    [0x27U] 
                                                    >> 0xbU))) 
                                     | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__39__KET____DOT__bi__DOT__ForSig) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x27U] 
                                           >> 0xbU))))));
    bufp->fullBit(oldp+11907,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x27U] >> 9U))));
    bufp->fullBit(oldp+11908,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x27U] >> 8U))));
    bufp->fullBit(oldp+11909,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x27U] >> 7U))));
    bufp->fullBit(oldp+11910,((1U & (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
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
    bufp->fullBit(oldp+11911,((1U & ((((((~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
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
    bufp->fullBit(oldp+11912,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x27U] >> 0xaU))));
    bufp->fullBit(oldp+11913,((1U & ((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__39__KET____DOT__bi__DOT__ThiSig) 
                                       >> 1U) & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__39__KET____DOT__bi__DOT__ThiSig) 
                                                 | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                    [0x27U] 
                                                    >> 0xaU))) 
                                     | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__39__KET____DOT__bi__DOT__ThiSig) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x27U] 
                                           >> 0xaU))))));
    bufp->fullBit(oldp+11914,((1U & (((((IData)((0U 
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
    bufp->fullBit(oldp+11915,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x27U] >> 2U))));
    bufp->fullBit(oldp+11916,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x27U] >> 1U))));
    bufp->fullBit(oldp+11917,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                               [0x27U])));
    bufp->fullBit(oldp+11918,((1U & (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                       [0x27U] >> 2U) 
                                      & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x27U] >> 1U) 
                                         | vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x27U])) 
                                     | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x27U] >> 1U) 
                                        & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                        [0x27U])))));
    bufp->fullBit(oldp+11919,((1U & ((((((~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
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
    bufp->fullBit(oldp+11920,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x27U] >> 4U))));
    bufp->fullBit(oldp+11921,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x27U] >> 3U))));
    bufp->fullBit(oldp+11922,((1U & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__39__KET____DOT__bi__InData 
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
    bufp->fullBit(oldp+11923,((1U & ((((((~ vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__39__KET____DOT__bi__InData) 
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
    bufp->fullBit(oldp+11924,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x27U] >> 0xdU))));
    bufp->fullBit(oldp+11925,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x27U] >> 0xcU))));
    bufp->fullBit(oldp+11926,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__39__KET____DOT__bi__DOT__SecSig))));
    bufp->fullBit(oldp+11927,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x27U] >> 6U))));
    bufp->fullBit(oldp+11928,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x27U] >> 5U))));
    bufp->fullBit(oldp+11929,((1U & (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__39__KET____DOT__bi__DOT__SecSig) 
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
    bufp->fullBit(oldp+11930,((1U & ((((((~ (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__39__KET____DOT__bi__DOT__SecSig)) 
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
    bufp->fullBit(oldp+11931,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__39__KET____DOT__bi__DOT__SecSig) 
                                     >> 3U))));
    bufp->fullBit(oldp+11932,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__39__KET____DOT__bi__DOT__SecSig) 
                                     >> 2U))));
    bufp->fullBit(oldp+11933,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__39__KET____DOT__bi__DOT__SecSig) 
                                     >> 1U))));
    bufp->fullBit(oldp+11934,((1U & ((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__39__KET____DOT__bi__DOT__SecSig) 
                                       >> 3U) & (IData)(
                                                        (0U 
                                                         != 
                                                         (6U 
                                                          & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__39__KET____DOT__bi__DOT__SecSig))))) 
                                     | (IData)((6U 
                                                == 
                                                (6U 
                                                 & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__39__KET____DOT__bi__DOT__SecSig))))))));
    bufp->fullBit(oldp+11935,((1U & ((((IData)((2U 
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
    bufp->fullSData(oldp+11936,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                [3U]),14);
    bufp->fullSData(oldp+11937,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellout__wallacefor__BRA__3__KET____DOT__bi__COut),14);
    bufp->fullBit(oldp+11938,((1U & (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__3__KET____DOT__bi__DOT__FifSig) 
                                      & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [3U] >> 0xdU) 
                                         | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [3U] >> 0xcU))) 
                                     | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [3U] >> 0xdU) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [3U] >> 0xcU))))));
    bufp->fullBit(oldp+11939,((1U & ((((((~ (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__3__KET____DOT__bi__DOT__FifSig)) 
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
    bufp->fullCData(oldp+11940,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__3__KET____DOT__bi__DOT__SecSig),4);
    bufp->fullBit(oldp+11941,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [3U] >> 0xbU))));
    bufp->fullBit(oldp+11942,((1U & ((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__3__KET____DOT__bi__DOT__ForSig) 
                                       >> 1U) & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__3__KET____DOT__bi__DOT__ForSig) 
                                                 | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                    [3U] 
                                                    >> 0xbU))) 
                                     | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__3__KET____DOT__bi__DOT__ForSig) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [3U] >> 0xbU))))));
    bufp->fullBit(oldp+11943,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [3U] >> 9U))));
    bufp->fullBit(oldp+11944,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [3U] >> 8U))));
    bufp->fullBit(oldp+11945,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [3U] >> 7U))));
    bufp->fullBit(oldp+11946,((1U & (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                       [3U] >> 9U) 
                                      & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [3U] >> 8U) 
                                         | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [3U] >> 7U))) 
                                     | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [3U] >> 8U) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [3U] >> 7U))))));
    bufp->fullBit(oldp+11947,((1U & ((((((~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
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
    bufp->fullBit(oldp+11948,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [3U] >> 0xaU))));
    bufp->fullBit(oldp+11949,((1U & ((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__3__KET____DOT__bi__DOT__ThiSig) 
                                       >> 1U) & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__3__KET____DOT__bi__DOT__ThiSig) 
                                                 | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                    [3U] 
                                                    >> 0xaU))) 
                                     | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__3__KET____DOT__bi__DOT__ThiSig) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [3U] >> 0xaU))))));
    bufp->fullBit(oldp+11950,((1U & (((((IData)((0U 
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
    bufp->fullBit(oldp+11951,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [3U] >> 2U))));
    bufp->fullBit(oldp+11952,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [3U] >> 1U))));
    bufp->fullBit(oldp+11953,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                               [3U])));
    bufp->fullBit(oldp+11954,((1U & (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
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
    bufp->fullBit(oldp+11955,((1U & ((((((~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
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
    bufp->fullBit(oldp+11956,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [3U] >> 4U))));
    bufp->fullBit(oldp+11957,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [3U] >> 3U))));
    bufp->fullBit(oldp+11958,((1U & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__3__KET____DOT__bi__InData 
                                      & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [3U] >> 4U) 
                                         | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [3U] >> 3U))) 
                                     | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [3U] >> 4U) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [3U] >> 3U))))));
    bufp->fullBit(oldp+11959,((1U & ((((((~ vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__3__KET____DOT__bi__InData) 
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
    bufp->fullBit(oldp+11960,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [3U] >> 0xdU))));
    bufp->fullBit(oldp+11961,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [3U] >> 0xcU))));
    bufp->fullBit(oldp+11962,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__3__KET____DOT__bi__DOT__SecSig))));
    bufp->fullBit(oldp+11963,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [3U] >> 6U))));
    bufp->fullBit(oldp+11964,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [3U] >> 5U))));
    bufp->fullBit(oldp+11965,((1U & (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__3__KET____DOT__bi__DOT__SecSig) 
                                      & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [3U] >> 6U) 
                                         | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [3U] >> 5U))) 
                                     | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [3U] >> 6U) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [3U] >> 5U))))));
    bufp->fullBit(oldp+11966,((1U & ((((((~ (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__3__KET____DOT__bi__DOT__SecSig)) 
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
    bufp->fullBit(oldp+11967,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__3__KET____DOT__bi__DOT__SecSig) 
                                     >> 3U))));
    bufp->fullBit(oldp+11968,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__3__KET____DOT__bi__DOT__SecSig) 
                                     >> 2U))));
    bufp->fullBit(oldp+11969,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__3__KET____DOT__bi__DOT__SecSig) 
                                     >> 1U))));
    bufp->fullBit(oldp+11970,((1U & ((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__3__KET____DOT__bi__DOT__SecSig) 
                                       >> 3U) & (IData)(
                                                        (0U 
                                                         != 
                                                         (6U 
                                                          & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__3__KET____DOT__bi__DOT__SecSig))))) 
                                     | (IData)((6U 
                                                == 
                                                (6U 
                                                 & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__3__KET____DOT__bi__DOT__SecSig))))))));
    bufp->fullBit(oldp+11971,((1U & ((((IData)((2U 
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
    bufp->fullSData(oldp+11972,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                [0x28U]),14);
    bufp->fullSData(oldp+11973,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellout__wallacefor__BRA__40__KET____DOT__bi__COut),14);
    bufp->fullBit(oldp+11974,((1U & (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__40__KET____DOT__bi__DOT__FifSig) 
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
    bufp->fullBit(oldp+11975,((1U & ((((((~ (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__40__KET____DOT__bi__DOT__FifSig)) 
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
    bufp->fullCData(oldp+11976,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__40__KET____DOT__bi__DOT__SecSig),4);
    bufp->fullBit(oldp+11977,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x28U] >> 0xbU))));
    bufp->fullBit(oldp+11978,((1U & ((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__40__KET____DOT__bi__DOT__ForSig) 
                                       >> 1U) & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__40__KET____DOT__bi__DOT__ForSig) 
                                                 | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                    [0x28U] 
                                                    >> 0xbU))) 
                                     | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__40__KET____DOT__bi__DOT__ForSig) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x28U] 
                                           >> 0xbU))))));
    bufp->fullBit(oldp+11979,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x28U] >> 9U))));
    bufp->fullBit(oldp+11980,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x28U] >> 8U))));
    bufp->fullBit(oldp+11981,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x28U] >> 7U))));
    bufp->fullBit(oldp+11982,((1U & (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
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
    bufp->fullBit(oldp+11983,((1U & ((((((~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
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
    bufp->fullBit(oldp+11984,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x28U] >> 0xaU))));
    bufp->fullBit(oldp+11985,((1U & ((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__40__KET____DOT__bi__DOT__ThiSig) 
                                       >> 1U) & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__40__KET____DOT__bi__DOT__ThiSig) 
                                                 | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                    [0x28U] 
                                                    >> 0xaU))) 
                                     | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__40__KET____DOT__bi__DOT__ThiSig) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x28U] 
                                           >> 0xaU))))));
    bufp->fullBit(oldp+11986,((1U & (((((IData)((0U 
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
    bufp->fullBit(oldp+11987,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x28U] >> 2U))));
    bufp->fullBit(oldp+11988,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x28U] >> 1U))));
    bufp->fullBit(oldp+11989,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                               [0x28U])));
    bufp->fullBit(oldp+11990,((1U & (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                       [0x28U] >> 2U) 
                                      & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x28U] >> 1U) 
                                         | vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x28U])) 
                                     | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x28U] >> 1U) 
                                        & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                        [0x28U])))));
    bufp->fullBit(oldp+11991,((1U & ((((((~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
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
    bufp->fullBit(oldp+11992,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x28U] >> 4U))));
    bufp->fullBit(oldp+11993,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x28U] >> 3U))));
    bufp->fullBit(oldp+11994,((1U & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__40__KET____DOT__bi__InData 
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
    bufp->fullBit(oldp+11995,((1U & ((((((~ vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__40__KET____DOT__bi__InData) 
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
    bufp->fullBit(oldp+11996,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x28U] >> 0xdU))));
    bufp->fullBit(oldp+11997,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x28U] >> 0xcU))));
    bufp->fullBit(oldp+11998,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__40__KET____DOT__bi__DOT__SecSig))));
    bufp->fullBit(oldp+11999,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x28U] >> 6U))));
    bufp->fullBit(oldp+12000,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x28U] >> 5U))));
    bufp->fullBit(oldp+12001,((1U & (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__40__KET____DOT__bi__DOT__SecSig) 
                                      & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x28U] >> 6U) 
                                         | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x28U] 
                                            >> 5U))) 
                                     | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x28U] >> 6U) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x28U] 
                                           >> 5U))))));
    bufp->fullBit(oldp+12002,((1U & ((((((~ (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__40__KET____DOT__bi__DOT__SecSig)) 
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
    bufp->fullBit(oldp+12003,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__40__KET____DOT__bi__DOT__SecSig) 
                                     >> 3U))));
    bufp->fullBit(oldp+12004,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__40__KET____DOT__bi__DOT__SecSig) 
                                     >> 2U))));
    bufp->fullBit(oldp+12005,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__40__KET____DOT__bi__DOT__SecSig) 
                                     >> 1U))));
    bufp->fullBit(oldp+12006,((1U & ((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__40__KET____DOT__bi__DOT__SecSig) 
                                       >> 3U) & (IData)(
                                                        (0U 
                                                         != 
                                                         (6U 
                                                          & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__40__KET____DOT__bi__DOT__SecSig))))) 
                                     | (IData)((6U 
                                                == 
                                                (6U 
                                                 & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__40__KET____DOT__bi__DOT__SecSig))))))));
    bufp->fullBit(oldp+12007,((1U & ((((IData)((2U 
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
    bufp->fullSData(oldp+12008,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                [0x29U]),14);
    bufp->fullSData(oldp+12009,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellout__wallacefor__BRA__41__KET____DOT__bi__COut),14);
    bufp->fullBit(oldp+12010,((1U & (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__41__KET____DOT__bi__DOT__FifSig) 
                                      & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x29U] >> 0xdU) 
                                         | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x29U] 
                                            >> 0xcU))) 
                                     | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x29U] >> 0xdU) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x29U] 
                                           >> 0xcU))))));
    bufp->fullBit(oldp+12011,((1U & ((((((~ (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__41__KET____DOT__bi__DOT__FifSig)) 
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
    bufp->fullCData(oldp+12012,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__41__KET____DOT__bi__DOT__SecSig),4);
    bufp->fullBit(oldp+12013,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x29U] >> 0xbU))));
    bufp->fullBit(oldp+12014,((1U & ((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__41__KET____DOT__bi__DOT__ForSig) 
                                       >> 1U) & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__41__KET____DOT__bi__DOT__ForSig) 
                                                 | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                    [0x29U] 
                                                    >> 0xbU))) 
                                     | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__41__KET____DOT__bi__DOT__ForSig) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x29U] 
                                           >> 0xbU))))));
    bufp->fullBit(oldp+12015,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x29U] >> 9U))));
    bufp->fullBit(oldp+12016,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x29U] >> 8U))));
    bufp->fullBit(oldp+12017,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x29U] >> 7U))));
    bufp->fullBit(oldp+12018,((1U & (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                       [0x29U] >> 9U) 
                                      & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x29U] >> 8U) 
                                         | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x29U] 
                                            >> 7U))) 
                                     | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x29U] >> 8U) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x29U] 
                                           >> 7U))))));
    bufp->fullBit(oldp+12019,((1U & ((((((~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
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
                                           >> 9U) & 
                                          (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                              [0x29U] 
                                              >> 8U))) 
                                         & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                               [0x29U] 
                                               >> 7U)))) 
                                     | (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x29U] >> 9U) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x29U] 
                                            >> 8U)) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x29U] 
                                           >> 7U))))));
    bufp->fullBit(oldp+12020,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x29U] >> 0xaU))));
    bufp->fullBit(oldp+12021,((1U & ((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__41__KET____DOT__bi__DOT__ThiSig) 
                                       >> 1U) & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__41__KET____DOT__bi__DOT__ThiSig) 
                                                 | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                    [0x29U] 
                                                    >> 0xaU))) 
                                     | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__41__KET____DOT__bi__DOT__ThiSig) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x29U] 
                                           >> 0xaU))))));
    bufp->fullBit(oldp+12022,((1U & (((((IData)((0U 
                                                 == (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__41__KET____DOT__bi__DOT__ThiSig))) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x29U] 
                                           >> 0xaU)) 
                                       | ((IData)((1U 
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
    bufp->fullBit(oldp+12023,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x29U] >> 2U))));
    bufp->fullBit(oldp+12024,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x29U] >> 1U))));
    bufp->fullBit(oldp+12025,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                               [0x29U])));
    bufp->fullBit(oldp+12026,((1U & (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                       [0x29U] >> 2U) 
                                      & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x29U] >> 1U) 
                                         | vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x29U])) 
                                     | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x29U] >> 1U) 
                                        & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                        [0x29U])))));
    bufp->fullBit(oldp+12027,((1U & ((((((~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
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
                                           >> 2U) & 
                                          (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                              [0x29U] 
                                              >> 1U))) 
                                         & (~ vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x29U]))) 
                                     | (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x29U] >> 2U) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x29U] 
                                            >> 1U)) 
                                        & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                        [0x29U])))));
    bufp->fullBit(oldp+12028,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x29U] >> 4U))));
    bufp->fullBit(oldp+12029,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x29U] >> 3U))));
    bufp->fullBit(oldp+12030,((1U & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__41__KET____DOT__bi__InData 
                                      & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x29U] >> 4U) 
                                         | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x29U] 
                                            >> 3U))) 
                                     | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x29U] >> 4U) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x29U] 
                                           >> 3U))))));
    bufp->fullBit(oldp+12031,((1U & ((((((~ vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__41__KET____DOT__bi__InData) 
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
    bufp->fullBit(oldp+12032,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x29U] >> 0xdU))));
    bufp->fullBit(oldp+12033,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x29U] >> 0xcU))));
    bufp->fullBit(oldp+12034,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__41__KET____DOT__bi__DOT__SecSig))));
    bufp->fullBit(oldp+12035,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x29U] >> 6U))));
    bufp->fullBit(oldp+12036,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x29U] >> 5U))));
    bufp->fullBit(oldp+12037,((1U & (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__41__KET____DOT__bi__DOT__SecSig) 
                                      & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x29U] >> 6U) 
                                         | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x29U] 
                                            >> 5U))) 
                                     | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x29U] >> 6U) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x29U] 
                                           >> 5U))))));
    bufp->fullBit(oldp+12038,((1U & ((((((~ (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__41__KET____DOT__bi__DOT__SecSig)) 
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
    bufp->fullBit(oldp+12039,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__41__KET____DOT__bi__DOT__SecSig) 
                                     >> 3U))));
    bufp->fullBit(oldp+12040,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__41__KET____DOT__bi__DOT__SecSig) 
                                     >> 2U))));
    bufp->fullBit(oldp+12041,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__41__KET____DOT__bi__DOT__SecSig) 
                                     >> 1U))));
    bufp->fullBit(oldp+12042,((1U & ((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__41__KET____DOT__bi__DOT__SecSig) 
                                       >> 3U) & (IData)(
                                                        (0U 
                                                         != 
                                                         (6U 
                                                          & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__41__KET____DOT__bi__DOT__SecSig))))) 
                                     | (IData)((6U 
                                                == 
                                                (6U 
                                                 & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__41__KET____DOT__bi__DOT__SecSig))))))));
    bufp->fullBit(oldp+12043,((1U & ((((IData)((2U 
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
    bufp->fullSData(oldp+12044,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                [0x2aU]),14);
    bufp->fullSData(oldp+12045,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellout__wallacefor__BRA__42__KET____DOT__bi__COut),14);
    bufp->fullBit(oldp+12046,((1U & (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__42__KET____DOT__bi__DOT__FifSig) 
                                      & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x2aU] >> 0xdU) 
                                         | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x2aU] 
                                            >> 0xcU))) 
                                     | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x2aU] >> 0xdU) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x2aU] 
                                           >> 0xcU))))));
    bufp->fullBit(oldp+12047,((1U & ((((((~ (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__42__KET____DOT__bi__DOT__FifSig)) 
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
    bufp->fullCData(oldp+12048,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__42__KET____DOT__bi__DOT__SecSig),4);
    bufp->fullBit(oldp+12049,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x2aU] >> 0xbU))));
    bufp->fullBit(oldp+12050,((1U & ((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__42__KET____DOT__bi__DOT__ForSig) 
                                       >> 1U) & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__42__KET____DOT__bi__DOT__ForSig) 
                                                 | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                    [0x2aU] 
                                                    >> 0xbU))) 
                                     | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__42__KET____DOT__bi__DOT__ForSig) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x2aU] 
                                           >> 0xbU))))));
    bufp->fullBit(oldp+12051,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x2aU] >> 9U))));
    bufp->fullBit(oldp+12052,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x2aU] >> 8U))));
    bufp->fullBit(oldp+12053,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x2aU] >> 7U))));
    bufp->fullBit(oldp+12054,((1U & (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                       [0x2aU] >> 9U) 
                                      & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x2aU] >> 8U) 
                                         | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x2aU] 
                                            >> 7U))) 
                                     | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x2aU] >> 8U) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x2aU] 
                                           >> 7U))))));
    bufp->fullBit(oldp+12055,((1U & ((((((~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
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
                                           >> 9U) & 
                                          (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                              [0x2aU] 
                                              >> 8U))) 
                                         & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                               [0x2aU] 
                                               >> 7U)))) 
                                     | (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x2aU] >> 9U) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x2aU] 
                                            >> 8U)) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x2aU] 
                                           >> 7U))))));
    bufp->fullBit(oldp+12056,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x2aU] >> 0xaU))));
    bufp->fullBit(oldp+12057,((1U & ((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__42__KET____DOT__bi__DOT__ThiSig) 
                                       >> 1U) & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__42__KET____DOT__bi__DOT__ThiSig) 
                                                 | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                    [0x2aU] 
                                                    >> 0xaU))) 
                                     | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__42__KET____DOT__bi__DOT__ThiSig) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x2aU] 
                                           >> 0xaU))))));
    bufp->fullBit(oldp+12058,((1U & (((((IData)((0U 
                                                 == (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__42__KET____DOT__bi__DOT__ThiSig))) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x2aU] 
                                           >> 0xaU)) 
                                       | ((IData)((1U 
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
    bufp->fullBit(oldp+12059,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x2aU] >> 2U))));
    bufp->fullBit(oldp+12060,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x2aU] >> 1U))));
    bufp->fullBit(oldp+12061,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                               [0x2aU])));
    bufp->fullBit(oldp+12062,((1U & (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                       [0x2aU] >> 2U) 
                                      & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x2aU] >> 1U) 
                                         | vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x2aU])) 
                                     | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x2aU] >> 1U) 
                                        & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                        [0x2aU])))));
    bufp->fullBit(oldp+12063,((1U & ((((((~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
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
                                           >> 2U) & 
                                          (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                              [0x2aU] 
                                              >> 1U))) 
                                         & (~ vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x2aU]))) 
                                     | (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x2aU] >> 2U) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x2aU] 
                                            >> 1U)) 
                                        & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                        [0x2aU])))));
    bufp->fullBit(oldp+12064,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x2aU] >> 4U))));
    bufp->fullBit(oldp+12065,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x2aU] >> 3U))));
    bufp->fullBit(oldp+12066,((1U & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__42__KET____DOT__bi__InData 
                                      & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x2aU] >> 4U) 
                                         | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x2aU] 
                                            >> 3U))) 
                                     | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x2aU] >> 4U) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x2aU] 
                                           >> 3U))))));
    bufp->fullBit(oldp+12067,((1U & ((((((~ vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__42__KET____DOT__bi__InData) 
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
    bufp->fullBit(oldp+12068,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x2aU] >> 0xdU))));
    bufp->fullBit(oldp+12069,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x2aU] >> 0xcU))));
    bufp->fullBit(oldp+12070,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__42__KET____DOT__bi__DOT__SecSig))));
    bufp->fullBit(oldp+12071,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x2aU] >> 6U))));
    bufp->fullBit(oldp+12072,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x2aU] >> 5U))));
    bufp->fullBit(oldp+12073,((1U & (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__42__KET____DOT__bi__DOT__SecSig) 
                                      & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x2aU] >> 6U) 
                                         | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x2aU] 
                                            >> 5U))) 
                                     | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x2aU] >> 6U) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x2aU] 
                                           >> 5U))))));
    bufp->fullBit(oldp+12074,((1U & ((((((~ (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__42__KET____DOT__bi__DOT__SecSig)) 
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
    bufp->fullBit(oldp+12075,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__42__KET____DOT__bi__DOT__SecSig) 
                                     >> 3U))));
    bufp->fullBit(oldp+12076,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__42__KET____DOT__bi__DOT__SecSig) 
                                     >> 2U))));
    bufp->fullBit(oldp+12077,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__42__KET____DOT__bi__DOT__SecSig) 
                                     >> 1U))));
    bufp->fullBit(oldp+12078,((1U & ((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__42__KET____DOT__bi__DOT__SecSig) 
                                       >> 3U) & (IData)(
                                                        (0U 
                                                         != 
                                                         (6U 
                                                          & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__42__KET____DOT__bi__DOT__SecSig))))) 
                                     | (IData)((6U 
                                                == 
                                                (6U 
                                                 & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__42__KET____DOT__bi__DOT__SecSig))))))));
    bufp->fullBit(oldp+12079,((1U & ((((IData)((2U 
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
    bufp->fullSData(oldp+12080,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                [0x2bU]),14);
    bufp->fullSData(oldp+12081,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellout__wallacefor__BRA__43__KET____DOT__bi__COut),14);
    bufp->fullBit(oldp+12082,((1U & (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__43__KET____DOT__bi__DOT__FifSig) 
                                      & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x2bU] >> 0xdU) 
                                         | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x2bU] 
                                            >> 0xcU))) 
                                     | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x2bU] >> 0xdU) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x2bU] 
                                           >> 0xcU))))));
    bufp->fullBit(oldp+12083,((1U & ((((((~ (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__43__KET____DOT__bi__DOT__FifSig)) 
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
    bufp->fullCData(oldp+12084,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__43__KET____DOT__bi__DOT__SecSig),4);
    bufp->fullBit(oldp+12085,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x2bU] >> 0xbU))));
    bufp->fullBit(oldp+12086,((1U & ((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__43__KET____DOT__bi__DOT__ForSig) 
                                       >> 1U) & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__43__KET____DOT__bi__DOT__ForSig) 
                                                 | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                    [0x2bU] 
                                                    >> 0xbU))) 
                                     | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__43__KET____DOT__bi__DOT__ForSig) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x2bU] 
                                           >> 0xbU))))));
    bufp->fullBit(oldp+12087,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x2bU] >> 9U))));
    bufp->fullBit(oldp+12088,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x2bU] >> 8U))));
    bufp->fullBit(oldp+12089,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x2bU] >> 7U))));
    bufp->fullBit(oldp+12090,((1U & (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                       [0x2bU] >> 9U) 
                                      & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x2bU] >> 8U) 
                                         | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x2bU] 
                                            >> 7U))) 
                                     | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x2bU] >> 8U) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x2bU] 
                                           >> 7U))))));
    bufp->fullBit(oldp+12091,((1U & ((((((~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
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
                                           >> 9U) & 
                                          (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                              [0x2bU] 
                                              >> 8U))) 
                                         & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                               [0x2bU] 
                                               >> 7U)))) 
                                     | (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x2bU] >> 9U) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x2bU] 
                                            >> 8U)) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x2bU] 
                                           >> 7U))))));
    bufp->fullBit(oldp+12092,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x2bU] >> 0xaU))));
    bufp->fullBit(oldp+12093,((1U & ((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__43__KET____DOT__bi__DOT__ThiSig) 
                                       >> 1U) & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__43__KET____DOT__bi__DOT__ThiSig) 
                                                 | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                    [0x2bU] 
                                                    >> 0xaU))) 
                                     | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__43__KET____DOT__bi__DOT__ThiSig) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x2bU] 
                                           >> 0xaU))))));
    bufp->fullBit(oldp+12094,((1U & (((((IData)((0U 
                                                 == (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__43__KET____DOT__bi__DOT__ThiSig))) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x2bU] 
                                           >> 0xaU)) 
                                       | ((IData)((1U 
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
    bufp->fullBit(oldp+12095,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x2bU] >> 2U))));
    bufp->fullBit(oldp+12096,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x2bU] >> 1U))));
    bufp->fullBit(oldp+12097,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                               [0x2bU])));
    bufp->fullBit(oldp+12098,((1U & (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                       [0x2bU] >> 2U) 
                                      & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x2bU] >> 1U) 
                                         | vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x2bU])) 
                                     | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x2bU] >> 1U) 
                                        & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                        [0x2bU])))));
    bufp->fullBit(oldp+12099,((1U & ((((((~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
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
                                           >> 2U) & 
                                          (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                              [0x2bU] 
                                              >> 1U))) 
                                         & (~ vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x2bU]))) 
                                     | (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x2bU] >> 2U) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x2bU] 
                                            >> 1U)) 
                                        & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                        [0x2bU])))));
    bufp->fullBit(oldp+12100,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x2bU] >> 4U))));
    bufp->fullBit(oldp+12101,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x2bU] >> 3U))));
    bufp->fullBit(oldp+12102,((1U & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__43__KET____DOT__bi__InData 
                                      & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x2bU] >> 4U) 
                                         | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x2bU] 
                                            >> 3U))) 
                                     | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x2bU] >> 4U) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x2bU] 
                                           >> 3U))))));
    bufp->fullBit(oldp+12103,((1U & ((((((~ vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__43__KET____DOT__bi__InData) 
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
    bufp->fullBit(oldp+12104,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x2bU] >> 0xdU))));
    bufp->fullBit(oldp+12105,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x2bU] >> 0xcU))));
    bufp->fullBit(oldp+12106,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__43__KET____DOT__bi__DOT__SecSig))));
    bufp->fullBit(oldp+12107,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x2bU] >> 6U))));
    bufp->fullBit(oldp+12108,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x2bU] >> 5U))));
    bufp->fullBit(oldp+12109,((1U & (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__43__KET____DOT__bi__DOT__SecSig) 
                                      & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x2bU] >> 6U) 
                                         | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x2bU] 
                                            >> 5U))) 
                                     | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x2bU] >> 6U) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x2bU] 
                                           >> 5U))))));
    bufp->fullBit(oldp+12110,((1U & ((((((~ (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__43__KET____DOT__bi__DOT__SecSig)) 
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
    bufp->fullBit(oldp+12111,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__43__KET____DOT__bi__DOT__SecSig) 
                                     >> 3U))));
    bufp->fullBit(oldp+12112,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__43__KET____DOT__bi__DOT__SecSig) 
                                     >> 2U))));
    bufp->fullBit(oldp+12113,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__43__KET____DOT__bi__DOT__SecSig) 
                                     >> 1U))));
    bufp->fullBit(oldp+12114,((1U & ((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__43__KET____DOT__bi__DOT__SecSig) 
                                       >> 3U) & (IData)(
                                                        (0U 
                                                         != 
                                                         (6U 
                                                          & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__43__KET____DOT__bi__DOT__SecSig))))) 
                                     | (IData)((6U 
                                                == 
                                                (6U 
                                                 & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__43__KET____DOT__bi__DOT__SecSig))))))));
    bufp->fullBit(oldp+12115,((1U & ((((IData)((2U 
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
    bufp->fullSData(oldp+12116,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                [0x2cU]),14);
    bufp->fullSData(oldp+12117,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellout__wallacefor__BRA__44__KET____DOT__bi__COut),14);
    bufp->fullBit(oldp+12118,((1U & (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__44__KET____DOT__bi__DOT__FifSig) 
                                      & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x2cU] >> 0xdU) 
                                         | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x2cU] 
                                            >> 0xcU))) 
                                     | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x2cU] >> 0xdU) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x2cU] 
                                           >> 0xcU))))));
    bufp->fullBit(oldp+12119,((1U & ((((((~ (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__44__KET____DOT__bi__DOT__FifSig)) 
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
    bufp->fullCData(oldp+12120,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__44__KET____DOT__bi__DOT__SecSig),4);
    bufp->fullBit(oldp+12121,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x2cU] >> 0xbU))));
    bufp->fullBit(oldp+12122,((1U & ((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__44__KET____DOT__bi__DOT__ForSig) 
                                       >> 1U) & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__44__KET____DOT__bi__DOT__ForSig) 
                                                 | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                    [0x2cU] 
                                                    >> 0xbU))) 
                                     | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__44__KET____DOT__bi__DOT__ForSig) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x2cU] 
                                           >> 0xbU))))));
    bufp->fullBit(oldp+12123,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x2cU] >> 9U))));
    bufp->fullBit(oldp+12124,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x2cU] >> 8U))));
    bufp->fullBit(oldp+12125,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x2cU] >> 7U))));
    bufp->fullBit(oldp+12126,((1U & (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                       [0x2cU] >> 9U) 
                                      & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x2cU] >> 8U) 
                                         | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x2cU] 
                                            >> 7U))) 
                                     | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x2cU] >> 8U) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x2cU] 
                                           >> 7U))))));
    bufp->fullBit(oldp+12127,((1U & ((((((~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
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
                                           >> 9U) & 
                                          (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                              [0x2cU] 
                                              >> 8U))) 
                                         & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                               [0x2cU] 
                                               >> 7U)))) 
                                     | (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x2cU] >> 9U) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x2cU] 
                                            >> 8U)) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x2cU] 
                                           >> 7U))))));
    bufp->fullBit(oldp+12128,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x2cU] >> 0xaU))));
    bufp->fullBit(oldp+12129,((1U & ((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__44__KET____DOT__bi__DOT__ThiSig) 
                                       >> 1U) & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__44__KET____DOT__bi__DOT__ThiSig) 
                                                 | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                    [0x2cU] 
                                                    >> 0xaU))) 
                                     | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__44__KET____DOT__bi__DOT__ThiSig) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x2cU] 
                                           >> 0xaU))))));
    bufp->fullBit(oldp+12130,((1U & (((((IData)((0U 
                                                 == (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__44__KET____DOT__bi__DOT__ThiSig))) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x2cU] 
                                           >> 0xaU)) 
                                       | ((IData)((1U 
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
    bufp->fullBit(oldp+12131,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x2cU] >> 2U))));
    bufp->fullBit(oldp+12132,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x2cU] >> 1U))));
    bufp->fullBit(oldp+12133,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                               [0x2cU])));
    bufp->fullBit(oldp+12134,((1U & (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                       [0x2cU] >> 2U) 
                                      & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x2cU] >> 1U) 
                                         | vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x2cU])) 
                                     | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x2cU] >> 1U) 
                                        & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                        [0x2cU])))));
    bufp->fullBit(oldp+12135,((1U & ((((((~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
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
                                           >> 2U) & 
                                          (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                              [0x2cU] 
                                              >> 1U))) 
                                         & (~ vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x2cU]))) 
                                     | (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x2cU] >> 2U) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x2cU] 
                                            >> 1U)) 
                                        & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                        [0x2cU])))));
    bufp->fullBit(oldp+12136,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x2cU] >> 4U))));
    bufp->fullBit(oldp+12137,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x2cU] >> 3U))));
    bufp->fullBit(oldp+12138,((1U & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__44__KET____DOT__bi__InData 
                                      & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x2cU] >> 4U) 
                                         | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x2cU] 
                                            >> 3U))) 
                                     | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x2cU] >> 4U) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x2cU] 
                                           >> 3U))))));
    bufp->fullBit(oldp+12139,((1U & ((((((~ vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__44__KET____DOT__bi__InData) 
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
    bufp->fullBit(oldp+12140,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x2cU] >> 0xdU))));
    bufp->fullBit(oldp+12141,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x2cU] >> 0xcU))));
    bufp->fullBit(oldp+12142,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__44__KET____DOT__bi__DOT__SecSig))));
    bufp->fullBit(oldp+12143,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x2cU] >> 6U))));
    bufp->fullBit(oldp+12144,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x2cU] >> 5U))));
    bufp->fullBit(oldp+12145,((1U & (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__44__KET____DOT__bi__DOT__SecSig) 
                                      & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x2cU] >> 6U) 
                                         | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x2cU] 
                                            >> 5U))) 
                                     | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x2cU] >> 6U) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x2cU] 
                                           >> 5U))))));
    bufp->fullBit(oldp+12146,((1U & ((((((~ (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__44__KET____DOT__bi__DOT__SecSig)) 
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
    bufp->fullBit(oldp+12147,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__44__KET____DOT__bi__DOT__SecSig) 
                                     >> 3U))));
    bufp->fullBit(oldp+12148,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__44__KET____DOT__bi__DOT__SecSig) 
                                     >> 2U))));
    bufp->fullBit(oldp+12149,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__44__KET____DOT__bi__DOT__SecSig) 
                                     >> 1U))));
    bufp->fullBit(oldp+12150,((1U & ((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__44__KET____DOT__bi__DOT__SecSig) 
                                       >> 3U) & (IData)(
                                                        (0U 
                                                         != 
                                                         (6U 
                                                          & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__44__KET____DOT__bi__DOT__SecSig))))) 
                                     | (IData)((6U 
                                                == 
                                                (6U 
                                                 & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__44__KET____DOT__bi__DOT__SecSig))))))));
    bufp->fullBit(oldp+12151,((1U & ((((IData)((2U 
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
    bufp->fullSData(oldp+12152,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                [0x2dU]),14);
    bufp->fullSData(oldp+12153,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellout__wallacefor__BRA__45__KET____DOT__bi__COut),14);
    bufp->fullBit(oldp+12154,((1U & (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__45__KET____DOT__bi__DOT__FifSig) 
                                      & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x2dU] >> 0xdU) 
                                         | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x2dU] 
                                            >> 0xcU))) 
                                     | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x2dU] >> 0xdU) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x2dU] 
                                           >> 0xcU))))));
    bufp->fullBit(oldp+12155,((1U & ((((((~ (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__45__KET____DOT__bi__DOT__FifSig)) 
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
    bufp->fullCData(oldp+12156,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__45__KET____DOT__bi__DOT__SecSig),4);
    bufp->fullBit(oldp+12157,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x2dU] >> 0xbU))));
    bufp->fullBit(oldp+12158,((1U & ((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__45__KET____DOT__bi__DOT__ForSig) 
                                       >> 1U) & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__45__KET____DOT__bi__DOT__ForSig) 
                                                 | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                    [0x2dU] 
                                                    >> 0xbU))) 
                                     | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__45__KET____DOT__bi__DOT__ForSig) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x2dU] 
                                           >> 0xbU))))));
    bufp->fullBit(oldp+12159,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x2dU] >> 9U))));
    bufp->fullBit(oldp+12160,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x2dU] >> 8U))));
    bufp->fullBit(oldp+12161,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x2dU] >> 7U))));
    bufp->fullBit(oldp+12162,((1U & (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                       [0x2dU] >> 9U) 
                                      & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x2dU] >> 8U) 
                                         | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x2dU] 
                                            >> 7U))) 
                                     | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x2dU] >> 8U) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x2dU] 
                                           >> 7U))))));
    bufp->fullBit(oldp+12163,((1U & ((((((~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
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
                                           >> 9U) & 
                                          (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                              [0x2dU] 
                                              >> 8U))) 
                                         & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                               [0x2dU] 
                                               >> 7U)))) 
                                     | (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x2dU] >> 9U) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x2dU] 
                                            >> 8U)) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x2dU] 
                                           >> 7U))))));
    bufp->fullBit(oldp+12164,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x2dU] >> 0xaU))));
    bufp->fullBit(oldp+12165,((1U & ((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__45__KET____DOT__bi__DOT__ThiSig) 
                                       >> 1U) & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__45__KET____DOT__bi__DOT__ThiSig) 
                                                 | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                    [0x2dU] 
                                                    >> 0xaU))) 
                                     | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__45__KET____DOT__bi__DOT__ThiSig) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x2dU] 
                                           >> 0xaU))))));
    bufp->fullBit(oldp+12166,((1U & (((((IData)((0U 
                                                 == (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__45__KET____DOT__bi__DOT__ThiSig))) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x2dU] 
                                           >> 0xaU)) 
                                       | ((IData)((1U 
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
    bufp->fullBit(oldp+12167,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x2dU] >> 2U))));
    bufp->fullBit(oldp+12168,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x2dU] >> 1U))));
    bufp->fullBit(oldp+12169,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                               [0x2dU])));
    bufp->fullBit(oldp+12170,((1U & (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                       [0x2dU] >> 2U) 
                                      & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x2dU] >> 1U) 
                                         | vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x2dU])) 
                                     | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x2dU] >> 1U) 
                                        & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                        [0x2dU])))));
    bufp->fullBit(oldp+12171,((1U & ((((((~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
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
                                           >> 2U) & 
                                          (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                              [0x2dU] 
                                              >> 1U))) 
                                         & (~ vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x2dU]))) 
                                     | (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x2dU] >> 2U) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x2dU] 
                                            >> 1U)) 
                                        & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                        [0x2dU])))));
    bufp->fullBit(oldp+12172,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x2dU] >> 4U))));
    bufp->fullBit(oldp+12173,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x2dU] >> 3U))));
    bufp->fullBit(oldp+12174,((1U & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__45__KET____DOT__bi__InData 
                                      & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x2dU] >> 4U) 
                                         | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x2dU] 
                                            >> 3U))) 
                                     | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x2dU] >> 4U) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x2dU] 
                                           >> 3U))))));
    bufp->fullBit(oldp+12175,((1U & ((((((~ vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__45__KET____DOT__bi__InData) 
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
    bufp->fullBit(oldp+12176,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x2dU] >> 0xdU))));
    bufp->fullBit(oldp+12177,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x2dU] >> 0xcU))));
    bufp->fullBit(oldp+12178,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__45__KET____DOT__bi__DOT__SecSig))));
    bufp->fullBit(oldp+12179,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x2dU] >> 6U))));
    bufp->fullBit(oldp+12180,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x2dU] >> 5U))));
    bufp->fullBit(oldp+12181,((1U & (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__45__KET____DOT__bi__DOT__SecSig) 
                                      & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x2dU] >> 6U) 
                                         | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x2dU] 
                                            >> 5U))) 
                                     | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x2dU] >> 6U) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x2dU] 
                                           >> 5U))))));
    bufp->fullBit(oldp+12182,((1U & ((((((~ (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__45__KET____DOT__bi__DOT__SecSig)) 
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
    bufp->fullBit(oldp+12183,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__45__KET____DOT__bi__DOT__SecSig) 
                                     >> 3U))));
    bufp->fullBit(oldp+12184,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__45__KET____DOT__bi__DOT__SecSig) 
                                     >> 2U))));
    bufp->fullBit(oldp+12185,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__45__KET____DOT__bi__DOT__SecSig) 
                                     >> 1U))));
    bufp->fullBit(oldp+12186,((1U & ((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__45__KET____DOT__bi__DOT__SecSig) 
                                       >> 3U) & (IData)(
                                                        (0U 
                                                         != 
                                                         (6U 
                                                          & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__45__KET____DOT__bi__DOT__SecSig))))) 
                                     | (IData)((6U 
                                                == 
                                                (6U 
                                                 & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__45__KET____DOT__bi__DOT__SecSig))))))));
    bufp->fullBit(oldp+12187,((1U & ((((IData)((2U 
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
    bufp->fullSData(oldp+12188,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                [0x2eU]),14);
    bufp->fullSData(oldp+12189,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellout__wallacefor__BRA__46__KET____DOT__bi__COut),14);
    bufp->fullBit(oldp+12190,((1U & (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__46__KET____DOT__bi__DOT__FifSig) 
                                      & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x2eU] >> 0xdU) 
                                         | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x2eU] 
                                            >> 0xcU))) 
                                     | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x2eU] >> 0xdU) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x2eU] 
                                           >> 0xcU))))));
    bufp->fullBit(oldp+12191,((1U & ((((((~ (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__46__KET____DOT__bi__DOT__FifSig)) 
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
    bufp->fullCData(oldp+12192,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__46__KET____DOT__bi__DOT__SecSig),4);
    bufp->fullBit(oldp+12193,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x2eU] >> 0xbU))));
    bufp->fullBit(oldp+12194,((1U & ((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__46__KET____DOT__bi__DOT__ForSig) 
                                       >> 1U) & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__46__KET____DOT__bi__DOT__ForSig) 
                                                 | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                    [0x2eU] 
                                                    >> 0xbU))) 
                                     | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__46__KET____DOT__bi__DOT__ForSig) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x2eU] 
                                           >> 0xbU))))));
    bufp->fullBit(oldp+12195,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x2eU] >> 9U))));
    bufp->fullBit(oldp+12196,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x2eU] >> 8U))));
    bufp->fullBit(oldp+12197,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x2eU] >> 7U))));
    bufp->fullBit(oldp+12198,((1U & (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                       [0x2eU] >> 9U) 
                                      & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x2eU] >> 8U) 
                                         | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x2eU] 
                                            >> 7U))) 
                                     | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x2eU] >> 8U) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x2eU] 
                                           >> 7U))))));
    bufp->fullBit(oldp+12199,((1U & ((((((~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
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
                                           >> 9U) & 
                                          (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                              [0x2eU] 
                                              >> 8U))) 
                                         & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                               [0x2eU] 
                                               >> 7U)))) 
                                     | (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x2eU] >> 9U) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x2eU] 
                                            >> 8U)) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x2eU] 
                                           >> 7U))))));
    bufp->fullBit(oldp+12200,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x2eU] >> 0xaU))));
    bufp->fullBit(oldp+12201,((1U & ((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__46__KET____DOT__bi__DOT__ThiSig) 
                                       >> 1U) & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__46__KET____DOT__bi__DOT__ThiSig) 
                                                 | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                    [0x2eU] 
                                                    >> 0xaU))) 
                                     | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__46__KET____DOT__bi__DOT__ThiSig) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x2eU] 
                                           >> 0xaU))))));
    bufp->fullBit(oldp+12202,((1U & (((((IData)((0U 
                                                 == (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__46__KET____DOT__bi__DOT__ThiSig))) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x2eU] 
                                           >> 0xaU)) 
                                       | ((IData)((1U 
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
    bufp->fullBit(oldp+12203,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x2eU] >> 2U))));
    bufp->fullBit(oldp+12204,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x2eU] >> 1U))));
    bufp->fullBit(oldp+12205,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                               [0x2eU])));
    bufp->fullBit(oldp+12206,((1U & (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                       [0x2eU] >> 2U) 
                                      & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x2eU] >> 1U) 
                                         | vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x2eU])) 
                                     | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x2eU] >> 1U) 
                                        & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                        [0x2eU])))));
    bufp->fullBit(oldp+12207,((1U & ((((((~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
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
                                           >> 2U) & 
                                          (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                              [0x2eU] 
                                              >> 1U))) 
                                         & (~ vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x2eU]))) 
                                     | (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x2eU] >> 2U) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x2eU] 
                                            >> 1U)) 
                                        & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                        [0x2eU])))));
    bufp->fullBit(oldp+12208,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x2eU] >> 4U))));
    bufp->fullBit(oldp+12209,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x2eU] >> 3U))));
    bufp->fullBit(oldp+12210,((1U & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__46__KET____DOT__bi__InData 
                                      & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x2eU] >> 4U) 
                                         | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x2eU] 
                                            >> 3U))) 
                                     | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x2eU] >> 4U) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x2eU] 
                                           >> 3U))))));
    bufp->fullBit(oldp+12211,((1U & ((((((~ vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__46__KET____DOT__bi__InData) 
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
    bufp->fullBit(oldp+12212,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x2eU] >> 0xdU))));
    bufp->fullBit(oldp+12213,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x2eU] >> 0xcU))));
    bufp->fullBit(oldp+12214,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__46__KET____DOT__bi__DOT__SecSig))));
    bufp->fullBit(oldp+12215,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x2eU] >> 6U))));
    bufp->fullBit(oldp+12216,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x2eU] >> 5U))));
    bufp->fullBit(oldp+12217,((1U & (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__46__KET____DOT__bi__DOT__SecSig) 
                                      & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x2eU] >> 6U) 
                                         | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x2eU] 
                                            >> 5U))) 
                                     | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x2eU] >> 6U) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x2eU] 
                                           >> 5U))))));
    bufp->fullBit(oldp+12218,((1U & ((((((~ (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__46__KET____DOT__bi__DOT__SecSig)) 
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
    bufp->fullBit(oldp+12219,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__46__KET____DOT__bi__DOT__SecSig) 
                                     >> 3U))));
    bufp->fullBit(oldp+12220,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__46__KET____DOT__bi__DOT__SecSig) 
                                     >> 2U))));
    bufp->fullBit(oldp+12221,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__46__KET____DOT__bi__DOT__SecSig) 
                                     >> 1U))));
    bufp->fullBit(oldp+12222,((1U & ((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__46__KET____DOT__bi__DOT__SecSig) 
                                       >> 3U) & (IData)(
                                                        (0U 
                                                         != 
                                                         (6U 
                                                          & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__46__KET____DOT__bi__DOT__SecSig))))) 
                                     | (IData)((6U 
                                                == 
                                                (6U 
                                                 & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__46__KET____DOT__bi__DOT__SecSig))))))));
    bufp->fullBit(oldp+12223,((1U & ((((IData)((2U 
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
    bufp->fullSData(oldp+12224,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                [0x2fU]),14);
    bufp->fullSData(oldp+12225,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellout__wallacefor__BRA__47__KET____DOT__bi__COut),14);
    bufp->fullBit(oldp+12226,((1U & (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__47__KET____DOT__bi__DOT__FifSig) 
                                      & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x2fU] >> 0xdU) 
                                         | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x2fU] 
                                            >> 0xcU))) 
                                     | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x2fU] >> 0xdU) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x2fU] 
                                           >> 0xcU))))));
    bufp->fullBit(oldp+12227,((1U & ((((((~ (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__47__KET____DOT__bi__DOT__FifSig)) 
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
    bufp->fullCData(oldp+12228,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__47__KET____DOT__bi__DOT__SecSig),4);
    bufp->fullBit(oldp+12229,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x2fU] >> 0xbU))));
    bufp->fullBit(oldp+12230,((1U & ((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__47__KET____DOT__bi__DOT__ForSig) 
                                       >> 1U) & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__47__KET____DOT__bi__DOT__ForSig) 
                                                 | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                    [0x2fU] 
                                                    >> 0xbU))) 
                                     | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__47__KET____DOT__bi__DOT__ForSig) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x2fU] 
                                           >> 0xbU))))));
    bufp->fullBit(oldp+12231,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x2fU] >> 9U))));
    bufp->fullBit(oldp+12232,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x2fU] >> 8U))));
    bufp->fullBit(oldp+12233,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x2fU] >> 7U))));
    bufp->fullBit(oldp+12234,((1U & (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                       [0x2fU] >> 9U) 
                                      & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x2fU] >> 8U) 
                                         | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x2fU] 
                                            >> 7U))) 
                                     | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x2fU] >> 8U) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x2fU] 
                                           >> 7U))))));
    bufp->fullBit(oldp+12235,((1U & ((((((~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
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
                                           >> 9U) & 
                                          (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                              [0x2fU] 
                                              >> 8U))) 
                                         & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                               [0x2fU] 
                                               >> 7U)))) 
                                     | (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x2fU] >> 9U) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x2fU] 
                                            >> 8U)) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x2fU] 
                                           >> 7U))))));
    bufp->fullBit(oldp+12236,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x2fU] >> 0xaU))));
    bufp->fullBit(oldp+12237,((1U & ((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__47__KET____DOT__bi__DOT__ThiSig) 
                                       >> 1U) & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__47__KET____DOT__bi__DOT__ThiSig) 
                                                 | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                    [0x2fU] 
                                                    >> 0xaU))) 
                                     | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__47__KET____DOT__bi__DOT__ThiSig) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x2fU] 
                                           >> 0xaU))))));
    bufp->fullBit(oldp+12238,((1U & (((((IData)((0U 
                                                 == (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__47__KET____DOT__bi__DOT__ThiSig))) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x2fU] 
                                           >> 0xaU)) 
                                       | ((IData)((1U 
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
    bufp->fullBit(oldp+12239,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x2fU] >> 2U))));
    bufp->fullBit(oldp+12240,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x2fU] >> 1U))));
    bufp->fullBit(oldp+12241,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                               [0x2fU])));
    bufp->fullBit(oldp+12242,((1U & (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                       [0x2fU] >> 2U) 
                                      & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x2fU] >> 1U) 
                                         | vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x2fU])) 
                                     | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x2fU] >> 1U) 
                                        & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                        [0x2fU])))));
    bufp->fullBit(oldp+12243,((1U & ((((((~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
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
                                           >> 2U) & 
                                          (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                              [0x2fU] 
                                              >> 1U))) 
                                         & (~ vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x2fU]))) 
                                     | (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x2fU] >> 2U) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x2fU] 
                                            >> 1U)) 
                                        & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                        [0x2fU])))));
    bufp->fullBit(oldp+12244,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x2fU] >> 4U))));
    bufp->fullBit(oldp+12245,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x2fU] >> 3U))));
    bufp->fullBit(oldp+12246,((1U & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__47__KET____DOT__bi__InData 
                                      & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x2fU] >> 4U) 
                                         | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x2fU] 
                                            >> 3U))) 
                                     | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x2fU] >> 4U) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x2fU] 
                                           >> 3U))))));
    bufp->fullBit(oldp+12247,((1U & ((((((~ vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__47__KET____DOT__bi__InData) 
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
    bufp->fullBit(oldp+12248,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x2fU] >> 0xdU))));
    bufp->fullBit(oldp+12249,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x2fU] >> 0xcU))));
    bufp->fullBit(oldp+12250,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__47__KET____DOT__bi__DOT__SecSig))));
    bufp->fullBit(oldp+12251,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x2fU] >> 6U))));
    bufp->fullBit(oldp+12252,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x2fU] >> 5U))));
    bufp->fullBit(oldp+12253,((1U & (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__47__KET____DOT__bi__DOT__SecSig) 
                                      & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x2fU] >> 6U) 
                                         | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x2fU] 
                                            >> 5U))) 
                                     | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x2fU] >> 6U) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x2fU] 
                                           >> 5U))))));
    bufp->fullBit(oldp+12254,((1U & ((((((~ (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__47__KET____DOT__bi__DOT__SecSig)) 
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
    bufp->fullBit(oldp+12255,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__47__KET____DOT__bi__DOT__SecSig) 
                                     >> 3U))));
    bufp->fullBit(oldp+12256,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__47__KET____DOT__bi__DOT__SecSig) 
                                     >> 2U))));
    bufp->fullBit(oldp+12257,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__47__KET____DOT__bi__DOT__SecSig) 
                                     >> 1U))));
    bufp->fullBit(oldp+12258,((1U & ((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__47__KET____DOT__bi__DOT__SecSig) 
                                       >> 3U) & (IData)(
                                                        (0U 
                                                         != 
                                                         (6U 
                                                          & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__47__KET____DOT__bi__DOT__SecSig))))) 
                                     | (IData)((6U 
                                                == 
                                                (6U 
                                                 & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__47__KET____DOT__bi__DOT__SecSig))))))));
    bufp->fullBit(oldp+12259,((1U & ((((IData)((2U 
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
    bufp->fullSData(oldp+12260,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                [0x30U]),14);
    bufp->fullSData(oldp+12261,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellout__wallacefor__BRA__48__KET____DOT__bi__COut),14);
    bufp->fullBit(oldp+12262,((1U & (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__48__KET____DOT__bi__DOT__FifSig) 
                                      & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x30U] >> 0xdU) 
                                         | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x30U] 
                                            >> 0xcU))) 
                                     | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x30U] >> 0xdU) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x30U] 
                                           >> 0xcU))))));
    bufp->fullBit(oldp+12263,((1U & ((((((~ (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__48__KET____DOT__bi__DOT__FifSig)) 
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
    bufp->fullCData(oldp+12264,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__48__KET____DOT__bi__DOT__SecSig),4);
    bufp->fullBit(oldp+12265,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x30U] >> 0xbU))));
    bufp->fullBit(oldp+12266,((1U & ((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__48__KET____DOT__bi__DOT__ForSig) 
                                       >> 1U) & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__48__KET____DOT__bi__DOT__ForSig) 
                                                 | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                    [0x30U] 
                                                    >> 0xbU))) 
                                     | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__48__KET____DOT__bi__DOT__ForSig) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x30U] 
                                           >> 0xbU))))));
    bufp->fullBit(oldp+12267,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x30U] >> 9U))));
    bufp->fullBit(oldp+12268,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x30U] >> 8U))));
    bufp->fullBit(oldp+12269,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x30U] >> 7U))));
    bufp->fullBit(oldp+12270,((1U & (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                       [0x30U] >> 9U) 
                                      & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x30U] >> 8U) 
                                         | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x30U] 
                                            >> 7U))) 
                                     | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x30U] >> 8U) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x30U] 
                                           >> 7U))))));
    bufp->fullBit(oldp+12271,((1U & ((((((~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
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
                                           >> 9U) & 
                                          (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                              [0x30U] 
                                              >> 8U))) 
                                         & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                               [0x30U] 
                                               >> 7U)))) 
                                     | (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x30U] >> 9U) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x30U] 
                                            >> 8U)) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x30U] 
                                           >> 7U))))));
    bufp->fullBit(oldp+12272,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x30U] >> 0xaU))));
    bufp->fullBit(oldp+12273,((1U & ((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__48__KET____DOT__bi__DOT__ThiSig) 
                                       >> 1U) & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__48__KET____DOT__bi__DOT__ThiSig) 
                                                 | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                    [0x30U] 
                                                    >> 0xaU))) 
                                     | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__48__KET____DOT__bi__DOT__ThiSig) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x30U] 
                                           >> 0xaU))))));
    bufp->fullBit(oldp+12274,((1U & (((((IData)((0U 
                                                 == (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__48__KET____DOT__bi__DOT__ThiSig))) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x30U] 
                                           >> 0xaU)) 
                                       | ((IData)((1U 
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
    bufp->fullBit(oldp+12275,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x30U] >> 2U))));
    bufp->fullBit(oldp+12276,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x30U] >> 1U))));
    bufp->fullBit(oldp+12277,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                               [0x30U])));
    bufp->fullBit(oldp+12278,((1U & (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                       [0x30U] >> 2U) 
                                      & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x30U] >> 1U) 
                                         | vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x30U])) 
                                     | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x30U] >> 1U) 
                                        & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                        [0x30U])))));
    bufp->fullBit(oldp+12279,((1U & ((((((~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
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
                                           >> 2U) & 
                                          (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                              [0x30U] 
                                              >> 1U))) 
                                         & (~ vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x30U]))) 
                                     | (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x30U] >> 2U) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x30U] 
                                            >> 1U)) 
                                        & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                        [0x30U])))));
    bufp->fullBit(oldp+12280,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x30U] >> 4U))));
    bufp->fullBit(oldp+12281,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x30U] >> 3U))));
    bufp->fullBit(oldp+12282,((1U & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__48__KET____DOT__bi__InData 
                                      & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x30U] >> 4U) 
                                         | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x30U] 
                                            >> 3U))) 
                                     | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x30U] >> 4U) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x30U] 
                                           >> 3U))))));
    bufp->fullBit(oldp+12283,((1U & ((((((~ vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__48__KET____DOT__bi__InData) 
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
    bufp->fullBit(oldp+12284,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x30U] >> 0xdU))));
    bufp->fullBit(oldp+12285,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x30U] >> 0xcU))));
    bufp->fullBit(oldp+12286,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__48__KET____DOT__bi__DOT__SecSig))));
    bufp->fullBit(oldp+12287,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x30U] >> 6U))));
    bufp->fullBit(oldp+12288,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x30U] >> 5U))));
    bufp->fullBit(oldp+12289,((1U & (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__48__KET____DOT__bi__DOT__SecSig) 
                                      & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x30U] >> 6U) 
                                         | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x30U] 
                                            >> 5U))) 
                                     | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x30U] >> 6U) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x30U] 
                                           >> 5U))))));
    bufp->fullBit(oldp+12290,((1U & ((((((~ (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__48__KET____DOT__bi__DOT__SecSig)) 
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
    bufp->fullBit(oldp+12291,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__48__KET____DOT__bi__DOT__SecSig) 
                                     >> 3U))));
    bufp->fullBit(oldp+12292,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__48__KET____DOT__bi__DOT__SecSig) 
                                     >> 2U))));
    bufp->fullBit(oldp+12293,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__48__KET____DOT__bi__DOT__SecSig) 
                                     >> 1U))));
    bufp->fullBit(oldp+12294,((1U & ((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__48__KET____DOT__bi__DOT__SecSig) 
                                       >> 3U) & (IData)(
                                                        (0U 
                                                         != 
                                                         (6U 
                                                          & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__48__KET____DOT__bi__DOT__SecSig))))) 
                                     | (IData)((6U 
                                                == 
                                                (6U 
                                                 & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__48__KET____DOT__bi__DOT__SecSig))))))));
    bufp->fullBit(oldp+12295,((1U & ((((IData)((2U 
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
    bufp->fullSData(oldp+12296,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                [0x31U]),14);
    bufp->fullSData(oldp+12297,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellout__wallacefor__BRA__49__KET____DOT__bi__COut),14);
    bufp->fullBit(oldp+12298,((1U & (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__49__KET____DOT__bi__DOT__FifSig) 
                                      & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x31U] >> 0xdU) 
                                         | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x31U] 
                                            >> 0xcU))) 
                                     | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x31U] >> 0xdU) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x31U] 
                                           >> 0xcU))))));
    bufp->fullBit(oldp+12299,((1U & ((((((~ (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__49__KET____DOT__bi__DOT__FifSig)) 
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
    bufp->fullCData(oldp+12300,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__49__KET____DOT__bi__DOT__SecSig),4);
    bufp->fullBit(oldp+12301,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x31U] >> 0xbU))));
    bufp->fullBit(oldp+12302,((1U & ((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__49__KET____DOT__bi__DOT__ForSig) 
                                       >> 1U) & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__49__KET____DOT__bi__DOT__ForSig) 
                                                 | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                    [0x31U] 
                                                    >> 0xbU))) 
                                     | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__49__KET____DOT__bi__DOT__ForSig) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x31U] 
                                           >> 0xbU))))));
    bufp->fullBit(oldp+12303,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x31U] >> 9U))));
    bufp->fullBit(oldp+12304,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x31U] >> 8U))));
    bufp->fullBit(oldp+12305,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x31U] >> 7U))));
    bufp->fullBit(oldp+12306,((1U & (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                       [0x31U] >> 9U) 
                                      & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x31U] >> 8U) 
                                         | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x31U] 
                                            >> 7U))) 
                                     | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x31U] >> 8U) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x31U] 
                                           >> 7U))))));
    bufp->fullBit(oldp+12307,((1U & ((((((~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
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
                                           >> 9U) & 
                                          (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                              [0x31U] 
                                              >> 8U))) 
                                         & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                               [0x31U] 
                                               >> 7U)))) 
                                     | (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x31U] >> 9U) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x31U] 
                                            >> 8U)) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x31U] 
                                           >> 7U))))));
    bufp->fullBit(oldp+12308,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x31U] >> 0xaU))));
    bufp->fullBit(oldp+12309,((1U & ((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__49__KET____DOT__bi__DOT__ThiSig) 
                                       >> 1U) & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__49__KET____DOT__bi__DOT__ThiSig) 
                                                 | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                    [0x31U] 
                                                    >> 0xaU))) 
                                     | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__49__KET____DOT__bi__DOT__ThiSig) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x31U] 
                                           >> 0xaU))))));
    bufp->fullBit(oldp+12310,((1U & (((((IData)((0U 
                                                 == (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__49__KET____DOT__bi__DOT__ThiSig))) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x31U] 
                                           >> 0xaU)) 
                                       | ((IData)((1U 
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
    bufp->fullBit(oldp+12311,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x31U] >> 2U))));
    bufp->fullBit(oldp+12312,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x31U] >> 1U))));
    bufp->fullBit(oldp+12313,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                               [0x31U])));
    bufp->fullBit(oldp+12314,((1U & (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                       [0x31U] >> 2U) 
                                      & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x31U] >> 1U) 
                                         | vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x31U])) 
                                     | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x31U] >> 1U) 
                                        & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                        [0x31U])))));
    bufp->fullBit(oldp+12315,((1U & ((((((~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
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
                                           >> 2U) & 
                                          (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                              [0x31U] 
                                              >> 1U))) 
                                         & (~ vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x31U]))) 
                                     | (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x31U] >> 2U) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x31U] 
                                            >> 1U)) 
                                        & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                        [0x31U])))));
    bufp->fullBit(oldp+12316,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x31U] >> 4U))));
    bufp->fullBit(oldp+12317,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x31U] >> 3U))));
    bufp->fullBit(oldp+12318,((1U & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__49__KET____DOT__bi__InData 
                                      & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x31U] >> 4U) 
                                         | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x31U] 
                                            >> 3U))) 
                                     | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x31U] >> 4U) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x31U] 
                                           >> 3U))))));
    bufp->fullBit(oldp+12319,((1U & ((((((~ vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__49__KET____DOT__bi__InData) 
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
    bufp->fullBit(oldp+12320,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x31U] >> 0xdU))));
    bufp->fullBit(oldp+12321,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x31U] >> 0xcU))));
    bufp->fullBit(oldp+12322,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__49__KET____DOT__bi__DOT__SecSig))));
    bufp->fullBit(oldp+12323,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x31U] >> 6U))));
    bufp->fullBit(oldp+12324,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x31U] >> 5U))));
    bufp->fullBit(oldp+12325,((1U & (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__49__KET____DOT__bi__DOT__SecSig) 
                                      & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x31U] >> 6U) 
                                         | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x31U] 
                                            >> 5U))) 
                                     | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x31U] >> 6U) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x31U] 
                                           >> 5U))))));
    bufp->fullBit(oldp+12326,((1U & ((((((~ (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__49__KET____DOT__bi__DOT__SecSig)) 
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
    bufp->fullBit(oldp+12327,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__49__KET____DOT__bi__DOT__SecSig) 
                                     >> 3U))));
    bufp->fullBit(oldp+12328,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__49__KET____DOT__bi__DOT__SecSig) 
                                     >> 2U))));
    bufp->fullBit(oldp+12329,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__49__KET____DOT__bi__DOT__SecSig) 
                                     >> 1U))));
    bufp->fullBit(oldp+12330,((1U & ((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__49__KET____DOT__bi__DOT__SecSig) 
                                       >> 3U) & (IData)(
                                                        (0U 
                                                         != 
                                                         (6U 
                                                          & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__49__KET____DOT__bi__DOT__SecSig))))) 
                                     | (IData)((6U 
                                                == 
                                                (6U 
                                                 & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__49__KET____DOT__bi__DOT__SecSig))))))));
    bufp->fullBit(oldp+12331,((1U & ((((IData)((2U 
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
    bufp->fullSData(oldp+12332,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                [4U]),14);
    bufp->fullSData(oldp+12333,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellout__wallacefor__BRA__4__KET____DOT__bi__COut),14);
    bufp->fullBit(oldp+12334,((1U & (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__4__KET____DOT__bi__DOT__FifSig) 
                                      & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [4U] >> 0xdU) 
                                         | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [4U] >> 0xcU))) 
                                     | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [4U] >> 0xdU) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [4U] >> 0xcU))))));
    bufp->fullBit(oldp+12335,((1U & ((((((~ (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__4__KET____DOT__bi__DOT__FifSig)) 
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
    bufp->fullCData(oldp+12336,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__4__KET____DOT__bi__DOT__SecSig),4);
    bufp->fullBit(oldp+12337,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [4U] >> 0xbU))));
    bufp->fullBit(oldp+12338,((1U & ((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__4__KET____DOT__bi__DOT__ForSig) 
                                       >> 1U) & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__4__KET____DOT__bi__DOT__ForSig) 
                                                 | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                    [4U] 
                                                    >> 0xbU))) 
                                     | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__4__KET____DOT__bi__DOT__ForSig) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [4U] >> 0xbU))))));
    bufp->fullBit(oldp+12339,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [4U] >> 9U))));
    bufp->fullBit(oldp+12340,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [4U] >> 8U))));
    bufp->fullBit(oldp+12341,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [4U] >> 7U))));
    bufp->fullBit(oldp+12342,((1U & (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                       [4U] >> 9U) 
                                      & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [4U] >> 8U) 
                                         | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [4U] >> 7U))) 
                                     | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [4U] >> 8U) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [4U] >> 7U))))));
    bufp->fullBit(oldp+12343,((1U & ((((((~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [4U] >> 9U)) 
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
    bufp->fullBit(oldp+12344,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [4U] >> 0xaU))));
    bufp->fullBit(oldp+12345,((1U & ((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__4__KET____DOT__bi__DOT__ThiSig) 
                                       >> 1U) & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__4__KET____DOT__bi__DOT__ThiSig) 
                                                 | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                    [4U] 
                                                    >> 0xaU))) 
                                     | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__4__KET____DOT__bi__DOT__ThiSig) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [4U] >> 0xaU))))));
    bufp->fullBit(oldp+12346,((1U & (((((IData)((0U 
                                                 == (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__4__KET____DOT__bi__DOT__ThiSig))) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [4U] >> 0xaU)) 
                                       | ((IData)((1U 
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
    bufp->fullBit(oldp+12347,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [4U] >> 2U))));
    bufp->fullBit(oldp+12348,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [4U] >> 1U))));
    bufp->fullBit(oldp+12349,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                               [4U])));
    bufp->fullBit(oldp+12350,((1U & (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                       [4U] >> 2U) 
                                      & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [4U] >> 1U) 
                                         | vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [4U])) | (
                                                   (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                    [4U] 
                                                    >> 1U) 
                                                   & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                   [4U])))));
    bufp->fullBit(oldp+12351,((1U & ((((((~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [4U] >> 2U)) 
                                         & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                               [4U] 
                                               >> 1U))) 
                                        & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                        [4U]) | (((~ 
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
    bufp->fullBit(oldp+12352,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [4U] >> 4U))));
    bufp->fullBit(oldp+12353,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [4U] >> 3U))));
    bufp->fullBit(oldp+12354,((1U & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__4__KET____DOT__bi__InData 
                                      & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [4U] >> 4U) 
                                         | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [4U] >> 3U))) 
                                     | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [4U] >> 4U) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [4U] >> 3U))))));
    bufp->fullBit(oldp+12355,((1U & ((((((~ vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__4__KET____DOT__bi__InData) 
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
    bufp->fullBit(oldp+12356,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [4U] >> 0xdU))));
    bufp->fullBit(oldp+12357,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [4U] >> 0xcU))));
    bufp->fullBit(oldp+12358,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__4__KET____DOT__bi__DOT__SecSig))));
    bufp->fullBit(oldp+12359,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [4U] >> 6U))));
    bufp->fullBit(oldp+12360,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [4U] >> 5U))));
    bufp->fullBit(oldp+12361,((1U & (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__4__KET____DOT__bi__DOT__SecSig) 
                                      & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [4U] >> 6U) 
                                         | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [4U] >> 5U))) 
                                     | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [4U] >> 6U) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [4U] >> 5U))))));
    bufp->fullBit(oldp+12362,((1U & ((((((~ (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__4__KET____DOT__bi__DOT__SecSig)) 
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
    bufp->fullBit(oldp+12363,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__4__KET____DOT__bi__DOT__SecSig) 
                                     >> 3U))));
    bufp->fullBit(oldp+12364,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__4__KET____DOT__bi__DOT__SecSig) 
                                     >> 2U))));
    bufp->fullBit(oldp+12365,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__4__KET____DOT__bi__DOT__SecSig) 
                                     >> 1U))));
    bufp->fullBit(oldp+12366,((1U & ((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__4__KET____DOT__bi__DOT__SecSig) 
                                       >> 3U) & (IData)(
                                                        (0U 
                                                         != 
                                                         (6U 
                                                          & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__4__KET____DOT__bi__DOT__SecSig))))) 
                                     | (IData)((6U 
                                                == 
                                                (6U 
                                                 & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__4__KET____DOT__bi__DOT__SecSig))))))));
    bufp->fullBit(oldp+12367,((1U & ((((IData)((2U 
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
    bufp->fullSData(oldp+12368,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                [0x32U]),14);
    bufp->fullSData(oldp+12369,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellout__wallacefor__BRA__50__KET____DOT__bi__COut),14);
    bufp->fullBit(oldp+12370,((1U & (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__50__KET____DOT__bi__DOT__FifSig) 
                                      & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x32U] >> 0xdU) 
                                         | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x32U] 
                                            >> 0xcU))) 
                                     | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x32U] >> 0xdU) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x32U] 
                                           >> 0xcU))))));
    bufp->fullBit(oldp+12371,((1U & ((((((~ (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__50__KET____DOT__bi__DOT__FifSig)) 
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
    bufp->fullCData(oldp+12372,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__50__KET____DOT__bi__DOT__SecSig),4);
    bufp->fullBit(oldp+12373,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x32U] >> 0xbU))));
    bufp->fullBit(oldp+12374,((1U & ((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__50__KET____DOT__bi__DOT__ForSig) 
                                       >> 1U) & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__50__KET____DOT__bi__DOT__ForSig) 
                                                 | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                    [0x32U] 
                                                    >> 0xbU))) 
                                     | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__50__KET____DOT__bi__DOT__ForSig) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x32U] 
                                           >> 0xbU))))));
    bufp->fullBit(oldp+12375,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x32U] >> 9U))));
    bufp->fullBit(oldp+12376,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x32U] >> 8U))));
    bufp->fullBit(oldp+12377,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x32U] >> 7U))));
    bufp->fullBit(oldp+12378,((1U & (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                       [0x32U] >> 9U) 
                                      & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x32U] >> 8U) 
                                         | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x32U] 
                                            >> 7U))) 
                                     | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x32U] >> 8U) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x32U] 
                                           >> 7U))))));
    bufp->fullBit(oldp+12379,((1U & ((((((~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
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
                                           >> 9U) & 
                                          (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                              [0x32U] 
                                              >> 8U))) 
                                         & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                               [0x32U] 
                                               >> 7U)))) 
                                     | (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x32U] >> 9U) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x32U] 
                                            >> 8U)) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x32U] 
                                           >> 7U))))));
    bufp->fullBit(oldp+12380,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x32U] >> 0xaU))));
    bufp->fullBit(oldp+12381,((1U & ((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__50__KET____DOT__bi__DOT__ThiSig) 
                                       >> 1U) & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__50__KET____DOT__bi__DOT__ThiSig) 
                                                 | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                    [0x32U] 
                                                    >> 0xaU))) 
                                     | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__50__KET____DOT__bi__DOT__ThiSig) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x32U] 
                                           >> 0xaU))))));
    bufp->fullBit(oldp+12382,((1U & (((((IData)((0U 
                                                 == (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__50__KET____DOT__bi__DOT__ThiSig))) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x32U] 
                                           >> 0xaU)) 
                                       | ((IData)((1U 
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
    bufp->fullBit(oldp+12383,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x32U] >> 2U))));
    bufp->fullBit(oldp+12384,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x32U] >> 1U))));
    bufp->fullBit(oldp+12385,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                               [0x32U])));
    bufp->fullBit(oldp+12386,((1U & (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                       [0x32U] >> 2U) 
                                      & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x32U] >> 1U) 
                                         | vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x32U])) 
                                     | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x32U] >> 1U) 
                                        & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                        [0x32U])))));
    bufp->fullBit(oldp+12387,((1U & ((((((~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
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
                                           >> 2U) & 
                                          (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                              [0x32U] 
                                              >> 1U))) 
                                         & (~ vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x32U]))) 
                                     | (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x32U] >> 2U) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x32U] 
                                            >> 1U)) 
                                        & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                        [0x32U])))));
    bufp->fullBit(oldp+12388,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x32U] >> 4U))));
    bufp->fullBit(oldp+12389,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x32U] >> 3U))));
    bufp->fullBit(oldp+12390,((1U & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__50__KET____DOT__bi__InData 
                                      & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x32U] >> 4U) 
                                         | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x32U] 
                                            >> 3U))) 
                                     | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x32U] >> 4U) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x32U] 
                                           >> 3U))))));
    bufp->fullBit(oldp+12391,((1U & ((((((~ vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__50__KET____DOT__bi__InData) 
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
    bufp->fullBit(oldp+12392,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x32U] >> 0xdU))));
    bufp->fullBit(oldp+12393,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x32U] >> 0xcU))));
    bufp->fullBit(oldp+12394,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__50__KET____DOT__bi__DOT__SecSig))));
    bufp->fullBit(oldp+12395,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x32U] >> 6U))));
    bufp->fullBit(oldp+12396,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x32U] >> 5U))));
    bufp->fullBit(oldp+12397,((1U & (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__50__KET____DOT__bi__DOT__SecSig) 
                                      & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x32U] >> 6U) 
                                         | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x32U] 
                                            >> 5U))) 
                                     | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x32U] >> 6U) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x32U] 
                                           >> 5U))))));
    bufp->fullBit(oldp+12398,((1U & ((((((~ (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__50__KET____DOT__bi__DOT__SecSig)) 
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
    bufp->fullBit(oldp+12399,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__50__KET____DOT__bi__DOT__SecSig) 
                                     >> 3U))));
    bufp->fullBit(oldp+12400,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__50__KET____DOT__bi__DOT__SecSig) 
                                     >> 2U))));
    bufp->fullBit(oldp+12401,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__50__KET____DOT__bi__DOT__SecSig) 
                                     >> 1U))));
    bufp->fullBit(oldp+12402,((1U & ((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__50__KET____DOT__bi__DOT__SecSig) 
                                       >> 3U) & (IData)(
                                                        (0U 
                                                         != 
                                                         (6U 
                                                          & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__50__KET____DOT__bi__DOT__SecSig))))) 
                                     | (IData)((6U 
                                                == 
                                                (6U 
                                                 & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__50__KET____DOT__bi__DOT__SecSig))))))));
    bufp->fullBit(oldp+12403,((1U & ((((IData)((2U 
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
    bufp->fullSData(oldp+12404,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                [0x33U]),14);
    bufp->fullSData(oldp+12405,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellout__wallacefor__BRA__51__KET____DOT__bi__COut),14);
    bufp->fullBit(oldp+12406,((1U & (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__51__KET____DOT__bi__DOT__FifSig) 
                                      & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x33U] >> 0xdU) 
                                         | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x33U] 
                                            >> 0xcU))) 
                                     | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x33U] >> 0xdU) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x33U] 
                                           >> 0xcU))))));
    bufp->fullBit(oldp+12407,((1U & ((((((~ (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__51__KET____DOT__bi__DOT__FifSig)) 
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
    bufp->fullCData(oldp+12408,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__51__KET____DOT__bi__DOT__SecSig),4);
    bufp->fullBit(oldp+12409,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x33U] >> 0xbU))));
    bufp->fullBit(oldp+12410,((1U & ((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__51__KET____DOT__bi__DOT__ForSig) 
                                       >> 1U) & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__51__KET____DOT__bi__DOT__ForSig) 
                                                 | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                    [0x33U] 
                                                    >> 0xbU))) 
                                     | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__51__KET____DOT__bi__DOT__ForSig) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x33U] 
                                           >> 0xbU))))));
    bufp->fullBit(oldp+12411,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x33U] >> 9U))));
    bufp->fullBit(oldp+12412,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x33U] >> 8U))));
    bufp->fullBit(oldp+12413,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x33U] >> 7U))));
    bufp->fullBit(oldp+12414,((1U & (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                       [0x33U] >> 9U) 
                                      & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x33U] >> 8U) 
                                         | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x33U] 
                                            >> 7U))) 
                                     | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x33U] >> 8U) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x33U] 
                                           >> 7U))))));
    bufp->fullBit(oldp+12415,((1U & ((((((~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
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
                                           >> 9U) & 
                                          (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                              [0x33U] 
                                              >> 8U))) 
                                         & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                               [0x33U] 
                                               >> 7U)))) 
                                     | (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x33U] >> 9U) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x33U] 
                                            >> 8U)) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x33U] 
                                           >> 7U))))));
    bufp->fullBit(oldp+12416,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x33U] >> 0xaU))));
    bufp->fullBit(oldp+12417,((1U & ((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__51__KET____DOT__bi__DOT__ThiSig) 
                                       >> 1U) & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__51__KET____DOT__bi__DOT__ThiSig) 
                                                 | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                    [0x33U] 
                                                    >> 0xaU))) 
                                     | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__51__KET____DOT__bi__DOT__ThiSig) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x33U] 
                                           >> 0xaU))))));
    bufp->fullBit(oldp+12418,((1U & (((((IData)((0U 
                                                 == (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__51__KET____DOT__bi__DOT__ThiSig))) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x33U] 
                                           >> 0xaU)) 
                                       | ((IData)((1U 
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
    bufp->fullBit(oldp+12419,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x33U] >> 2U))));
    bufp->fullBit(oldp+12420,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x33U] >> 1U))));
    bufp->fullBit(oldp+12421,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                               [0x33U])));
    bufp->fullBit(oldp+12422,((1U & (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                       [0x33U] >> 2U) 
                                      & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x33U] >> 1U) 
                                         | vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x33U])) 
                                     | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x33U] >> 1U) 
                                        & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                        [0x33U])))));
    bufp->fullBit(oldp+12423,((1U & ((((((~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
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
                                           >> 2U) & 
                                          (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                              [0x33U] 
                                              >> 1U))) 
                                         & (~ vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x33U]))) 
                                     | (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x33U] >> 2U) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x33U] 
                                            >> 1U)) 
                                        & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                        [0x33U])))));
    bufp->fullBit(oldp+12424,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x33U] >> 4U))));
    bufp->fullBit(oldp+12425,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x33U] >> 3U))));
    bufp->fullBit(oldp+12426,((1U & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__51__KET____DOT__bi__InData 
                                      & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x33U] >> 4U) 
                                         | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x33U] 
                                            >> 3U))) 
                                     | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x33U] >> 4U) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x33U] 
                                           >> 3U))))));
    bufp->fullBit(oldp+12427,((1U & ((((((~ vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__51__KET____DOT__bi__InData) 
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
    bufp->fullBit(oldp+12428,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x33U] >> 0xdU))));
    bufp->fullBit(oldp+12429,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x33U] >> 0xcU))));
    bufp->fullBit(oldp+12430,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__51__KET____DOT__bi__DOT__SecSig))));
    bufp->fullBit(oldp+12431,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x33U] >> 6U))));
    bufp->fullBit(oldp+12432,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x33U] >> 5U))));
    bufp->fullBit(oldp+12433,((1U & (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__51__KET____DOT__bi__DOT__SecSig) 
                                      & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x33U] >> 6U) 
                                         | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x33U] 
                                            >> 5U))) 
                                     | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x33U] >> 6U) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x33U] 
                                           >> 5U))))));
    bufp->fullBit(oldp+12434,((1U & ((((((~ (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__51__KET____DOT__bi__DOT__SecSig)) 
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
    bufp->fullBit(oldp+12435,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__51__KET____DOT__bi__DOT__SecSig) 
                                     >> 3U))));
    bufp->fullBit(oldp+12436,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__51__KET____DOT__bi__DOT__SecSig) 
                                     >> 2U))));
    bufp->fullBit(oldp+12437,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__51__KET____DOT__bi__DOT__SecSig) 
                                     >> 1U))));
    bufp->fullBit(oldp+12438,((1U & ((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__51__KET____DOT__bi__DOT__SecSig) 
                                       >> 3U) & (IData)(
                                                        (0U 
                                                         != 
                                                         (6U 
                                                          & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__51__KET____DOT__bi__DOT__SecSig))))) 
                                     | (IData)((6U 
                                                == 
                                                (6U 
                                                 & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__51__KET____DOT__bi__DOT__SecSig))))))));
    bufp->fullBit(oldp+12439,((1U & ((((IData)((2U 
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
    bufp->fullSData(oldp+12440,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                [0x34U]),14);
    bufp->fullSData(oldp+12441,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellout__wallacefor__BRA__52__KET____DOT__bi__COut),14);
    bufp->fullBit(oldp+12442,((1U & (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__52__KET____DOT__bi__DOT__FifSig) 
                                      & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x34U] >> 0xdU) 
                                         | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x34U] 
                                            >> 0xcU))) 
                                     | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x34U] >> 0xdU) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x34U] 
                                           >> 0xcU))))));
    bufp->fullBit(oldp+12443,((1U & ((((((~ (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__52__KET____DOT__bi__DOT__FifSig)) 
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
    bufp->fullCData(oldp+12444,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__52__KET____DOT__bi__DOT__SecSig),4);
    bufp->fullBit(oldp+12445,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x34U] >> 0xbU))));
    bufp->fullBit(oldp+12446,((1U & ((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__52__KET____DOT__bi__DOT__ForSig) 
                                       >> 1U) & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__52__KET____DOT__bi__DOT__ForSig) 
                                                 | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                    [0x34U] 
                                                    >> 0xbU))) 
                                     | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__52__KET____DOT__bi__DOT__ForSig) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x34U] 
                                           >> 0xbU))))));
    bufp->fullBit(oldp+12447,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x34U] >> 9U))));
    bufp->fullBit(oldp+12448,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x34U] >> 8U))));
    bufp->fullBit(oldp+12449,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x34U] >> 7U))));
    bufp->fullBit(oldp+12450,((1U & (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                       [0x34U] >> 9U) 
                                      & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x34U] >> 8U) 
                                         | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x34U] 
                                            >> 7U))) 
                                     | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x34U] >> 8U) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x34U] 
                                           >> 7U))))));
    bufp->fullBit(oldp+12451,((1U & ((((((~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
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
                                           >> 9U) & 
                                          (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                              [0x34U] 
                                              >> 8U))) 
                                         & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                               [0x34U] 
                                               >> 7U)))) 
                                     | (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x34U] >> 9U) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x34U] 
                                            >> 8U)) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x34U] 
                                           >> 7U))))));
    bufp->fullBit(oldp+12452,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x34U] >> 0xaU))));
    bufp->fullBit(oldp+12453,((1U & ((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__52__KET____DOT__bi__DOT__ThiSig) 
                                       >> 1U) & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__52__KET____DOT__bi__DOT__ThiSig) 
                                                 | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                    [0x34U] 
                                                    >> 0xaU))) 
                                     | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__52__KET____DOT__bi__DOT__ThiSig) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x34U] 
                                           >> 0xaU))))));
    bufp->fullBit(oldp+12454,((1U & (((((IData)((0U 
                                                 == (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__52__KET____DOT__bi__DOT__ThiSig))) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x34U] 
                                           >> 0xaU)) 
                                       | ((IData)((1U 
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
    bufp->fullBit(oldp+12455,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x34U] >> 2U))));
    bufp->fullBit(oldp+12456,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x34U] >> 1U))));
    bufp->fullBit(oldp+12457,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                               [0x34U])));
    bufp->fullBit(oldp+12458,((1U & (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                       [0x34U] >> 2U) 
                                      & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x34U] >> 1U) 
                                         | vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x34U])) 
                                     | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x34U] >> 1U) 
                                        & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                        [0x34U])))));
    bufp->fullBit(oldp+12459,((1U & ((((((~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
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
                                           >> 2U) & 
                                          (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                              [0x34U] 
                                              >> 1U))) 
                                         & (~ vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x34U]))) 
                                     | (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x34U] >> 2U) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x34U] 
                                            >> 1U)) 
                                        & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                        [0x34U])))));
    bufp->fullBit(oldp+12460,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x34U] >> 4U))));
    bufp->fullBit(oldp+12461,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x34U] >> 3U))));
    bufp->fullBit(oldp+12462,((1U & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__52__KET____DOT__bi__InData 
                                      & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x34U] >> 4U) 
                                         | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x34U] 
                                            >> 3U))) 
                                     | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x34U] >> 4U) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x34U] 
                                           >> 3U))))));
    bufp->fullBit(oldp+12463,((1U & ((((((~ vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__52__KET____DOT__bi__InData) 
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
    bufp->fullBit(oldp+12464,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x34U] >> 0xdU))));
    bufp->fullBit(oldp+12465,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x34U] >> 0xcU))));
    bufp->fullBit(oldp+12466,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__52__KET____DOT__bi__DOT__SecSig))));
    bufp->fullBit(oldp+12467,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x34U] >> 6U))));
    bufp->fullBit(oldp+12468,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x34U] >> 5U))));
    bufp->fullBit(oldp+12469,((1U & (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__52__KET____DOT__bi__DOT__SecSig) 
                                      & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x34U] >> 6U) 
                                         | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x34U] 
                                            >> 5U))) 
                                     | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x34U] >> 6U) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x34U] 
                                           >> 5U))))));
    bufp->fullBit(oldp+12470,((1U & ((((((~ (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__52__KET____DOT__bi__DOT__SecSig)) 
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
    bufp->fullBit(oldp+12471,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__52__KET____DOT__bi__DOT__SecSig) 
                                     >> 3U))));
    bufp->fullBit(oldp+12472,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__52__KET____DOT__bi__DOT__SecSig) 
                                     >> 2U))));
    bufp->fullBit(oldp+12473,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__52__KET____DOT__bi__DOT__SecSig) 
                                     >> 1U))));
    bufp->fullBit(oldp+12474,((1U & ((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__52__KET____DOT__bi__DOT__SecSig) 
                                       >> 3U) & (IData)(
                                                        (0U 
                                                         != 
                                                         (6U 
                                                          & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__52__KET____DOT__bi__DOT__SecSig))))) 
                                     | (IData)((6U 
                                                == 
                                                (6U 
                                                 & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__52__KET____DOT__bi__DOT__SecSig))))))));
    bufp->fullBit(oldp+12475,((1U & ((((IData)((2U 
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
    bufp->fullSData(oldp+12476,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                [0x35U]),14);
    bufp->fullSData(oldp+12477,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellout__wallacefor__BRA__53__KET____DOT__bi__COut),14);
    bufp->fullBit(oldp+12478,((1U & (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__53__KET____DOT__bi__DOT__FifSig) 
                                      & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x35U] >> 0xdU) 
                                         | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x35U] 
                                            >> 0xcU))) 
                                     | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x35U] >> 0xdU) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x35U] 
                                           >> 0xcU))))));
    bufp->fullBit(oldp+12479,((1U & ((((((~ (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__53__KET____DOT__bi__DOT__FifSig)) 
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
    bufp->fullCData(oldp+12480,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__53__KET____DOT__bi__DOT__SecSig),4);
    bufp->fullBit(oldp+12481,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x35U] >> 0xbU))));
    bufp->fullBit(oldp+12482,((1U & ((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__53__KET____DOT__bi__DOT__ForSig) 
                                       >> 1U) & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__53__KET____DOT__bi__DOT__ForSig) 
                                                 | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                    [0x35U] 
                                                    >> 0xbU))) 
                                     | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__53__KET____DOT__bi__DOT__ForSig) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x35U] 
                                           >> 0xbU))))));
    bufp->fullBit(oldp+12483,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x35U] >> 9U))));
    bufp->fullBit(oldp+12484,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x35U] >> 8U))));
    bufp->fullBit(oldp+12485,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x35U] >> 7U))));
    bufp->fullBit(oldp+12486,((1U & (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                       [0x35U] >> 9U) 
                                      & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x35U] >> 8U) 
                                         | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x35U] 
                                            >> 7U))) 
                                     | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x35U] >> 8U) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x35U] 
                                           >> 7U))))));
    bufp->fullBit(oldp+12487,((1U & ((((((~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
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
                                           >> 9U) & 
                                          (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                              [0x35U] 
                                              >> 8U))) 
                                         & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                               [0x35U] 
                                               >> 7U)))) 
                                     | (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x35U] >> 9U) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x35U] 
                                            >> 8U)) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x35U] 
                                           >> 7U))))));
    bufp->fullBit(oldp+12488,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x35U] >> 0xaU))));
    bufp->fullBit(oldp+12489,((1U & ((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__53__KET____DOT__bi__DOT__ThiSig) 
                                       >> 1U) & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__53__KET____DOT__bi__DOT__ThiSig) 
                                                 | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                    [0x35U] 
                                                    >> 0xaU))) 
                                     | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__53__KET____DOT__bi__DOT__ThiSig) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x35U] 
                                           >> 0xaU))))));
    bufp->fullBit(oldp+12490,((1U & (((((IData)((0U 
                                                 == (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__53__KET____DOT__bi__DOT__ThiSig))) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x35U] 
                                           >> 0xaU)) 
                                       | ((IData)((1U 
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
    bufp->fullBit(oldp+12491,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x35U] >> 2U))));
    bufp->fullBit(oldp+12492,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x35U] >> 1U))));
    bufp->fullBit(oldp+12493,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                               [0x35U])));
    bufp->fullBit(oldp+12494,((1U & (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                       [0x35U] >> 2U) 
                                      & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x35U] >> 1U) 
                                         | vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x35U])) 
                                     | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x35U] >> 1U) 
                                        & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                        [0x35U])))));
    bufp->fullBit(oldp+12495,((1U & ((((((~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
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
                                           >> 2U) & 
                                          (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                              [0x35U] 
                                              >> 1U))) 
                                         & (~ vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x35U]))) 
                                     | (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x35U] >> 2U) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x35U] 
                                            >> 1U)) 
                                        & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                        [0x35U])))));
    bufp->fullBit(oldp+12496,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x35U] >> 4U))));
    bufp->fullBit(oldp+12497,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x35U] >> 3U))));
    bufp->fullBit(oldp+12498,((1U & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__53__KET____DOT__bi__InData 
                                      & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x35U] >> 4U) 
                                         | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x35U] 
                                            >> 3U))) 
                                     | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x35U] >> 4U) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x35U] 
                                           >> 3U))))));
    bufp->fullBit(oldp+12499,((1U & ((((((~ vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__53__KET____DOT__bi__InData) 
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
    bufp->fullBit(oldp+12500,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x35U] >> 0xdU))));
    bufp->fullBit(oldp+12501,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x35U] >> 0xcU))));
    bufp->fullBit(oldp+12502,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__53__KET____DOT__bi__DOT__SecSig))));
    bufp->fullBit(oldp+12503,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x35U] >> 6U))));
    bufp->fullBit(oldp+12504,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x35U] >> 5U))));
    bufp->fullBit(oldp+12505,((1U & (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__53__KET____DOT__bi__DOT__SecSig) 
                                      & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x35U] >> 6U) 
                                         | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x35U] 
                                            >> 5U))) 
                                     | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x35U] >> 6U) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x35U] 
                                           >> 5U))))));
    bufp->fullBit(oldp+12506,((1U & ((((((~ (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__53__KET____DOT__bi__DOT__SecSig)) 
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
    bufp->fullBit(oldp+12507,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__53__KET____DOT__bi__DOT__SecSig) 
                                     >> 3U))));
    bufp->fullBit(oldp+12508,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__53__KET____DOT__bi__DOT__SecSig) 
                                     >> 2U))));
    bufp->fullBit(oldp+12509,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__53__KET____DOT__bi__DOT__SecSig) 
                                     >> 1U))));
    bufp->fullBit(oldp+12510,((1U & ((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__53__KET____DOT__bi__DOT__SecSig) 
                                       >> 3U) & (IData)(
                                                        (0U 
                                                         != 
                                                         (6U 
                                                          & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__53__KET____DOT__bi__DOT__SecSig))))) 
                                     | (IData)((6U 
                                                == 
                                                (6U 
                                                 & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__53__KET____DOT__bi__DOT__SecSig))))))));
    bufp->fullBit(oldp+12511,((1U & ((((IData)((2U 
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
    bufp->fullSData(oldp+12512,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                [0x36U]),14);
    bufp->fullSData(oldp+12513,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellout__wallacefor__BRA__54__KET____DOT__bi__COut),14);
    bufp->fullBit(oldp+12514,((1U & (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__54__KET____DOT__bi__DOT__FifSig) 
                                      & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x36U] >> 0xdU) 
                                         | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x36U] 
                                            >> 0xcU))) 
                                     | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x36U] >> 0xdU) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x36U] 
                                           >> 0xcU))))));
    bufp->fullBit(oldp+12515,((1U & ((((((~ (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__54__KET____DOT__bi__DOT__FifSig)) 
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
    bufp->fullCData(oldp+12516,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__54__KET____DOT__bi__DOT__SecSig),4);
    bufp->fullBit(oldp+12517,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x36U] >> 0xbU))));
    bufp->fullBit(oldp+12518,((1U & ((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__54__KET____DOT__bi__DOT__ForSig) 
                                       >> 1U) & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__54__KET____DOT__bi__DOT__ForSig) 
                                                 | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                    [0x36U] 
                                                    >> 0xbU))) 
                                     | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__54__KET____DOT__bi__DOT__ForSig) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x36U] 
                                           >> 0xbU))))));
    bufp->fullBit(oldp+12519,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x36U] >> 9U))));
    bufp->fullBit(oldp+12520,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x36U] >> 8U))));
    bufp->fullBit(oldp+12521,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x36U] >> 7U))));
    bufp->fullBit(oldp+12522,((1U & (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                       [0x36U] >> 9U) 
                                      & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x36U] >> 8U) 
                                         | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x36U] 
                                            >> 7U))) 
                                     | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x36U] >> 8U) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x36U] 
                                           >> 7U))))));
    bufp->fullBit(oldp+12523,((1U & ((((((~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
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
                                           >> 9U) & 
                                          (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                              [0x36U] 
                                              >> 8U))) 
                                         & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                               [0x36U] 
                                               >> 7U)))) 
                                     | (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x36U] >> 9U) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x36U] 
                                            >> 8U)) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x36U] 
                                           >> 7U))))));
    bufp->fullBit(oldp+12524,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x36U] >> 0xaU))));
    bufp->fullBit(oldp+12525,((1U & ((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__54__KET____DOT__bi__DOT__ThiSig) 
                                       >> 1U) & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__54__KET____DOT__bi__DOT__ThiSig) 
                                                 | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                    [0x36U] 
                                                    >> 0xaU))) 
                                     | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__54__KET____DOT__bi__DOT__ThiSig) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x36U] 
                                           >> 0xaU))))));
    bufp->fullBit(oldp+12526,((1U & (((((IData)((0U 
                                                 == (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__54__KET____DOT__bi__DOT__ThiSig))) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x36U] 
                                           >> 0xaU)) 
                                       | ((IData)((1U 
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
    bufp->fullBit(oldp+12527,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x36U] >> 2U))));
    bufp->fullBit(oldp+12528,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x36U] >> 1U))));
    bufp->fullBit(oldp+12529,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                               [0x36U])));
    bufp->fullBit(oldp+12530,((1U & (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                       [0x36U] >> 2U) 
                                      & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x36U] >> 1U) 
                                         | vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x36U])) 
                                     | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x36U] >> 1U) 
                                        & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                        [0x36U])))));
    bufp->fullBit(oldp+12531,((1U & ((((((~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
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
                                           >> 2U) & 
                                          (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                              [0x36U] 
                                              >> 1U))) 
                                         & (~ vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x36U]))) 
                                     | (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x36U] >> 2U) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x36U] 
                                            >> 1U)) 
                                        & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                        [0x36U])))));
    bufp->fullBit(oldp+12532,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x36U] >> 4U))));
    bufp->fullBit(oldp+12533,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x36U] >> 3U))));
    bufp->fullBit(oldp+12534,((1U & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__54__KET____DOT__bi__InData 
                                      & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x36U] >> 4U) 
                                         | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x36U] 
                                            >> 3U))) 
                                     | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x36U] >> 4U) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x36U] 
                                           >> 3U))))));
    bufp->fullBit(oldp+12535,((1U & ((((((~ vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__54__KET____DOT__bi__InData) 
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
    bufp->fullBit(oldp+12536,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x36U] >> 0xdU))));
    bufp->fullBit(oldp+12537,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x36U] >> 0xcU))));
    bufp->fullBit(oldp+12538,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__54__KET____DOT__bi__DOT__SecSig))));
    bufp->fullBit(oldp+12539,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x36U] >> 6U))));
    bufp->fullBit(oldp+12540,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x36U] >> 5U))));
    bufp->fullBit(oldp+12541,((1U & (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__54__KET____DOT__bi__DOT__SecSig) 
                                      & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x36U] >> 6U) 
                                         | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x36U] 
                                            >> 5U))) 
                                     | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x36U] >> 6U) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x36U] 
                                           >> 5U))))));
    bufp->fullBit(oldp+12542,((1U & ((((((~ (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__54__KET____DOT__bi__DOT__SecSig)) 
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
    bufp->fullBit(oldp+12543,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__54__KET____DOT__bi__DOT__SecSig) 
                                     >> 3U))));
    bufp->fullBit(oldp+12544,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__54__KET____DOT__bi__DOT__SecSig) 
                                     >> 2U))));
    bufp->fullBit(oldp+12545,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__54__KET____DOT__bi__DOT__SecSig) 
                                     >> 1U))));
    bufp->fullBit(oldp+12546,((1U & ((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__54__KET____DOT__bi__DOT__SecSig) 
                                       >> 3U) & (IData)(
                                                        (0U 
                                                         != 
                                                         (6U 
                                                          & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__54__KET____DOT__bi__DOT__SecSig))))) 
                                     | (IData)((6U 
                                                == 
                                                (6U 
                                                 & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__54__KET____DOT__bi__DOT__SecSig))))))));
    bufp->fullBit(oldp+12547,((1U & ((((IData)((2U 
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
    bufp->fullSData(oldp+12548,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                [0x37U]),14);
    bufp->fullSData(oldp+12549,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellout__wallacefor__BRA__55__KET____DOT__bi__COut),14);
    bufp->fullBit(oldp+12550,((1U & (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__55__KET____DOT__bi__DOT__FifSig) 
                                      & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x37U] >> 0xdU) 
                                         | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x37U] 
                                            >> 0xcU))) 
                                     | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x37U] >> 0xdU) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x37U] 
                                           >> 0xcU))))));
    bufp->fullBit(oldp+12551,((1U & ((((((~ (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__55__KET____DOT__bi__DOT__FifSig)) 
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
    bufp->fullCData(oldp+12552,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__55__KET____DOT__bi__DOT__SecSig),4);
    bufp->fullBit(oldp+12553,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x37U] >> 0xbU))));
    bufp->fullBit(oldp+12554,((1U & ((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__55__KET____DOT__bi__DOT__ForSig) 
                                       >> 1U) & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__55__KET____DOT__bi__DOT__ForSig) 
                                                 | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                    [0x37U] 
                                                    >> 0xbU))) 
                                     | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__55__KET____DOT__bi__DOT__ForSig) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x37U] 
                                           >> 0xbU))))));
    bufp->fullBit(oldp+12555,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x37U] >> 9U))));
    bufp->fullBit(oldp+12556,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x37U] >> 8U))));
    bufp->fullBit(oldp+12557,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x37U] >> 7U))));
    bufp->fullBit(oldp+12558,((1U & (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                       [0x37U] >> 9U) 
                                      & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x37U] >> 8U) 
                                         | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x37U] 
                                            >> 7U))) 
                                     | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x37U] >> 8U) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x37U] 
                                           >> 7U))))));
    bufp->fullBit(oldp+12559,((1U & ((((((~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
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
                                           >> 9U) & 
                                          (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                              [0x37U] 
                                              >> 8U))) 
                                         & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                               [0x37U] 
                                               >> 7U)))) 
                                     | (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x37U] >> 9U) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x37U] 
                                            >> 8U)) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x37U] 
                                           >> 7U))))));
    bufp->fullBit(oldp+12560,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x37U] >> 0xaU))));
    bufp->fullBit(oldp+12561,((1U & ((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__55__KET____DOT__bi__DOT__ThiSig) 
                                       >> 1U) & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__55__KET____DOT__bi__DOT__ThiSig) 
                                                 | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                    [0x37U] 
                                                    >> 0xaU))) 
                                     | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__55__KET____DOT__bi__DOT__ThiSig) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x37U] 
                                           >> 0xaU))))));
    bufp->fullBit(oldp+12562,((1U & (((((IData)((0U 
                                                 == (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__55__KET____DOT__bi__DOT__ThiSig))) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x37U] 
                                           >> 0xaU)) 
                                       | ((IData)((1U 
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
    bufp->fullBit(oldp+12563,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x37U] >> 2U))));
    bufp->fullBit(oldp+12564,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x37U] >> 1U))));
    bufp->fullBit(oldp+12565,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                               [0x37U])));
    bufp->fullBit(oldp+12566,((1U & (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                       [0x37U] >> 2U) 
                                      & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x37U] >> 1U) 
                                         | vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x37U])) 
                                     | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x37U] >> 1U) 
                                        & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                        [0x37U])))));
    bufp->fullBit(oldp+12567,((1U & ((((((~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
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
                                           >> 2U) & 
                                          (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                              [0x37U] 
                                              >> 1U))) 
                                         & (~ vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x37U]))) 
                                     | (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x37U] >> 2U) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x37U] 
                                            >> 1U)) 
                                        & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                        [0x37U])))));
    bufp->fullBit(oldp+12568,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x37U] >> 4U))));
    bufp->fullBit(oldp+12569,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x37U] >> 3U))));
    bufp->fullBit(oldp+12570,((1U & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__55__KET____DOT__bi__InData 
                                      & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x37U] >> 4U) 
                                         | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x37U] 
                                            >> 3U))) 
                                     | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x37U] >> 4U) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x37U] 
                                           >> 3U))))));
    bufp->fullBit(oldp+12571,((1U & ((((((~ vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__55__KET____DOT__bi__InData) 
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
    bufp->fullBit(oldp+12572,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x37U] >> 0xdU))));
    bufp->fullBit(oldp+12573,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x37U] >> 0xcU))));
    bufp->fullBit(oldp+12574,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__55__KET____DOT__bi__DOT__SecSig))));
    bufp->fullBit(oldp+12575,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x37U] >> 6U))));
    bufp->fullBit(oldp+12576,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x37U] >> 5U))));
    bufp->fullBit(oldp+12577,((1U & (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__55__KET____DOT__bi__DOT__SecSig) 
                                      & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x37U] >> 6U) 
                                         | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x37U] 
                                            >> 5U))) 
                                     | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x37U] >> 6U) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x37U] 
                                           >> 5U))))));
    bufp->fullBit(oldp+12578,((1U & ((((((~ (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__55__KET____DOT__bi__DOT__SecSig)) 
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
    bufp->fullBit(oldp+12579,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__55__KET____DOT__bi__DOT__SecSig) 
                                     >> 3U))));
    bufp->fullBit(oldp+12580,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__55__KET____DOT__bi__DOT__SecSig) 
                                     >> 2U))));
    bufp->fullBit(oldp+12581,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__55__KET____DOT__bi__DOT__SecSig) 
                                     >> 1U))));
    bufp->fullBit(oldp+12582,((1U & ((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__55__KET____DOT__bi__DOT__SecSig) 
                                       >> 3U) & (IData)(
                                                        (0U 
                                                         != 
                                                         (6U 
                                                          & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__55__KET____DOT__bi__DOT__SecSig))))) 
                                     | (IData)((6U 
                                                == 
                                                (6U 
                                                 & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__55__KET____DOT__bi__DOT__SecSig))))))));
    bufp->fullBit(oldp+12583,((1U & ((((IData)((2U 
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
    bufp->fullSData(oldp+12584,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                [0x38U]),14);
    bufp->fullSData(oldp+12585,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellout__wallacefor__BRA__56__KET____DOT__bi__COut),14);
    bufp->fullBit(oldp+12586,((1U & (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__56__KET____DOT__bi__DOT__FifSig) 
                                      & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x38U] >> 0xdU) 
                                         | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x38U] 
                                            >> 0xcU))) 
                                     | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x38U] >> 0xdU) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x38U] 
                                           >> 0xcU))))));
    bufp->fullBit(oldp+12587,((1U & ((((((~ (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__56__KET____DOT__bi__DOT__FifSig)) 
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
    bufp->fullCData(oldp+12588,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__56__KET____DOT__bi__DOT__SecSig),4);
    bufp->fullBit(oldp+12589,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x38U] >> 0xbU))));
    bufp->fullBit(oldp+12590,((1U & ((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__56__KET____DOT__bi__DOT__ForSig) 
                                       >> 1U) & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__56__KET____DOT__bi__DOT__ForSig) 
                                                 | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                    [0x38U] 
                                                    >> 0xbU))) 
                                     | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__56__KET____DOT__bi__DOT__ForSig) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x38U] 
                                           >> 0xbU))))));
    bufp->fullBit(oldp+12591,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x38U] >> 9U))));
    bufp->fullBit(oldp+12592,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x38U] >> 8U))));
    bufp->fullBit(oldp+12593,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x38U] >> 7U))));
    bufp->fullBit(oldp+12594,((1U & (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                       [0x38U] >> 9U) 
                                      & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x38U] >> 8U) 
                                         | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x38U] 
                                            >> 7U))) 
                                     | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x38U] >> 8U) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x38U] 
                                           >> 7U))))));
    bufp->fullBit(oldp+12595,((1U & ((((((~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
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
                                           >> 9U) & 
                                          (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                              [0x38U] 
                                              >> 8U))) 
                                         & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                               [0x38U] 
                                               >> 7U)))) 
                                     | (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x38U] >> 9U) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x38U] 
                                            >> 8U)) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x38U] 
                                           >> 7U))))));
    bufp->fullBit(oldp+12596,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x38U] >> 0xaU))));
    bufp->fullBit(oldp+12597,((1U & ((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__56__KET____DOT__bi__DOT__ThiSig) 
                                       >> 1U) & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__56__KET____DOT__bi__DOT__ThiSig) 
                                                 | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                    [0x38U] 
                                                    >> 0xaU))) 
                                     | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__56__KET____DOT__bi__DOT__ThiSig) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x38U] 
                                           >> 0xaU))))));
    bufp->fullBit(oldp+12598,((1U & (((((IData)((0U 
                                                 == (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__56__KET____DOT__bi__DOT__ThiSig))) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x38U] 
                                           >> 0xaU)) 
                                       | ((IData)((1U 
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
    bufp->fullBit(oldp+12599,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x38U] >> 2U))));
    bufp->fullBit(oldp+12600,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x38U] >> 1U))));
    bufp->fullBit(oldp+12601,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                               [0x38U])));
    bufp->fullBit(oldp+12602,((1U & (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                       [0x38U] >> 2U) 
                                      & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x38U] >> 1U) 
                                         | vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x38U])) 
                                     | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x38U] >> 1U) 
                                        & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                        [0x38U])))));
    bufp->fullBit(oldp+12603,((1U & ((((((~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
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
                                           >> 2U) & 
                                          (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                              [0x38U] 
                                              >> 1U))) 
                                         & (~ vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x38U]))) 
                                     | (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x38U] >> 2U) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x38U] 
                                            >> 1U)) 
                                        & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                        [0x38U])))));
    bufp->fullBit(oldp+12604,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x38U] >> 4U))));
    bufp->fullBit(oldp+12605,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x38U] >> 3U))));
    bufp->fullBit(oldp+12606,((1U & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__56__KET____DOT__bi__InData 
                                      & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x38U] >> 4U) 
                                         | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x38U] 
                                            >> 3U))) 
                                     | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x38U] >> 4U) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x38U] 
                                           >> 3U))))));
    bufp->fullBit(oldp+12607,((1U & ((((((~ vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__56__KET____DOT__bi__InData) 
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
    bufp->fullBit(oldp+12608,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x38U] >> 0xdU))));
    bufp->fullBit(oldp+12609,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x38U] >> 0xcU))));
    bufp->fullBit(oldp+12610,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__56__KET____DOT__bi__DOT__SecSig))));
    bufp->fullBit(oldp+12611,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x38U] >> 6U))));
    bufp->fullBit(oldp+12612,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x38U] >> 5U))));
    bufp->fullBit(oldp+12613,((1U & (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__56__KET____DOT__bi__DOT__SecSig) 
                                      & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x38U] >> 6U) 
                                         | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x38U] 
                                            >> 5U))) 
                                     | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x38U] >> 6U) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x38U] 
                                           >> 5U))))));
    bufp->fullBit(oldp+12614,((1U & ((((((~ (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__56__KET____DOT__bi__DOT__SecSig)) 
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
    bufp->fullBit(oldp+12615,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__56__KET____DOT__bi__DOT__SecSig) 
                                     >> 3U))));
    bufp->fullBit(oldp+12616,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__56__KET____DOT__bi__DOT__SecSig) 
                                     >> 2U))));
    bufp->fullBit(oldp+12617,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__56__KET____DOT__bi__DOT__SecSig) 
                                     >> 1U))));
    bufp->fullBit(oldp+12618,((1U & ((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__56__KET____DOT__bi__DOT__SecSig) 
                                       >> 3U) & (IData)(
                                                        (0U 
                                                         != 
                                                         (6U 
                                                          & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__56__KET____DOT__bi__DOT__SecSig))))) 
                                     | (IData)((6U 
                                                == 
                                                (6U 
                                                 & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__56__KET____DOT__bi__DOT__SecSig))))))));
    bufp->fullBit(oldp+12619,((1U & ((((IData)((2U 
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
    bufp->fullSData(oldp+12620,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                [0x39U]),14);
    bufp->fullSData(oldp+12621,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellout__wallacefor__BRA__57__KET____DOT__bi__COut),14);
    bufp->fullBit(oldp+12622,((1U & (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__57__KET____DOT__bi__DOT__FifSig) 
                                      & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x39U] >> 0xdU) 
                                         | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x39U] 
                                            >> 0xcU))) 
                                     | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x39U] >> 0xdU) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x39U] 
                                           >> 0xcU))))));
    bufp->fullBit(oldp+12623,((1U & ((((((~ (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__57__KET____DOT__bi__DOT__FifSig)) 
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
    bufp->fullCData(oldp+12624,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__57__KET____DOT__bi__DOT__SecSig),4);
    bufp->fullBit(oldp+12625,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x39U] >> 0xbU))));
    bufp->fullBit(oldp+12626,((1U & ((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__57__KET____DOT__bi__DOT__ForSig) 
                                       >> 1U) & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__57__KET____DOT__bi__DOT__ForSig) 
                                                 | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                    [0x39U] 
                                                    >> 0xbU))) 
                                     | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__57__KET____DOT__bi__DOT__ForSig) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x39U] 
                                           >> 0xbU))))));
    bufp->fullBit(oldp+12627,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x39U] >> 9U))));
    bufp->fullBit(oldp+12628,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x39U] >> 8U))));
    bufp->fullBit(oldp+12629,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x39U] >> 7U))));
    bufp->fullBit(oldp+12630,((1U & (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                       [0x39U] >> 9U) 
                                      & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x39U] >> 8U) 
                                         | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x39U] 
                                            >> 7U))) 
                                     | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x39U] >> 8U) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x39U] 
                                           >> 7U))))));
    bufp->fullBit(oldp+12631,((1U & ((((((~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
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
                                           >> 9U) & 
                                          (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                              [0x39U] 
                                              >> 8U))) 
                                         & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                               [0x39U] 
                                               >> 7U)))) 
                                     | (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x39U] >> 9U) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x39U] 
                                            >> 8U)) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x39U] 
                                           >> 7U))))));
    bufp->fullBit(oldp+12632,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x39U] >> 0xaU))));
    bufp->fullBit(oldp+12633,((1U & ((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__57__KET____DOT__bi__DOT__ThiSig) 
                                       >> 1U) & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__57__KET____DOT__bi__DOT__ThiSig) 
                                                 | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                    [0x39U] 
                                                    >> 0xaU))) 
                                     | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__57__KET____DOT__bi__DOT__ThiSig) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x39U] 
                                           >> 0xaU))))));
    bufp->fullBit(oldp+12634,((1U & (((((IData)((0U 
                                                 == (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__57__KET____DOT__bi__DOT__ThiSig))) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x39U] 
                                           >> 0xaU)) 
                                       | ((IData)((1U 
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
    bufp->fullBit(oldp+12635,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x39U] >> 2U))));
    bufp->fullBit(oldp+12636,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x39U] >> 1U))));
    bufp->fullBit(oldp+12637,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                               [0x39U])));
    bufp->fullBit(oldp+12638,((1U & (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                       [0x39U] >> 2U) 
                                      & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x39U] >> 1U) 
                                         | vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x39U])) 
                                     | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x39U] >> 1U) 
                                        & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                        [0x39U])))));
    bufp->fullBit(oldp+12639,((1U & ((((((~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
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
                                           >> 2U) & 
                                          (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                              [0x39U] 
                                              >> 1U))) 
                                         & (~ vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x39U]))) 
                                     | (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x39U] >> 2U) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x39U] 
                                            >> 1U)) 
                                        & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                        [0x39U])))));
    bufp->fullBit(oldp+12640,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x39U] >> 4U))));
    bufp->fullBit(oldp+12641,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x39U] >> 3U))));
    bufp->fullBit(oldp+12642,((1U & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__57__KET____DOT__bi__InData 
                                      & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x39U] >> 4U) 
                                         | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x39U] 
                                            >> 3U))) 
                                     | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x39U] >> 4U) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x39U] 
                                           >> 3U))))));
    bufp->fullBit(oldp+12643,((1U & ((((((~ vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__57__KET____DOT__bi__InData) 
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
    bufp->fullBit(oldp+12644,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x39U] >> 0xdU))));
    bufp->fullBit(oldp+12645,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x39U] >> 0xcU))));
    bufp->fullBit(oldp+12646,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__57__KET____DOT__bi__DOT__SecSig))));
    bufp->fullBit(oldp+12647,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x39U] >> 6U))));
    bufp->fullBit(oldp+12648,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x39U] >> 5U))));
    bufp->fullBit(oldp+12649,((1U & (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__57__KET____DOT__bi__DOT__SecSig) 
                                      & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x39U] >> 6U) 
                                         | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x39U] 
                                            >> 5U))) 
                                     | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x39U] >> 6U) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x39U] 
                                           >> 5U))))));
    bufp->fullBit(oldp+12650,((1U & ((((((~ (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__57__KET____DOT__bi__DOT__SecSig)) 
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
    bufp->fullBit(oldp+12651,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__57__KET____DOT__bi__DOT__SecSig) 
                                     >> 3U))));
    bufp->fullBit(oldp+12652,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__57__KET____DOT__bi__DOT__SecSig) 
                                     >> 2U))));
    bufp->fullBit(oldp+12653,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__57__KET____DOT__bi__DOT__SecSig) 
                                     >> 1U))));
    bufp->fullBit(oldp+12654,((1U & ((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__57__KET____DOT__bi__DOT__SecSig) 
                                       >> 3U) & (IData)(
                                                        (0U 
                                                         != 
                                                         (6U 
                                                          & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__57__KET____DOT__bi__DOT__SecSig))))) 
                                     | (IData)((6U 
                                                == 
                                                (6U 
                                                 & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__57__KET____DOT__bi__DOT__SecSig))))))));
    bufp->fullBit(oldp+12655,((1U & ((((IData)((2U 
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
    bufp->fullSData(oldp+12656,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                [0x3aU]),14);
    bufp->fullSData(oldp+12657,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellout__wallacefor__BRA__58__KET____DOT__bi__COut),14);
    bufp->fullBit(oldp+12658,((1U & (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__58__KET____DOT__bi__DOT__FifSig) 
                                      & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x3aU] >> 0xdU) 
                                         | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x3aU] 
                                            >> 0xcU))) 
                                     | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x3aU] >> 0xdU) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x3aU] 
                                           >> 0xcU))))));
    bufp->fullBit(oldp+12659,((1U & ((((((~ (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__58__KET____DOT__bi__DOT__FifSig)) 
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
    bufp->fullCData(oldp+12660,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__58__KET____DOT__bi__DOT__SecSig),4);
    bufp->fullBit(oldp+12661,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x3aU] >> 0xbU))));
    bufp->fullBit(oldp+12662,((1U & ((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__58__KET____DOT__bi__DOT__ForSig) 
                                       >> 1U) & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__58__KET____DOT__bi__DOT__ForSig) 
                                                 | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                    [0x3aU] 
                                                    >> 0xbU))) 
                                     | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__58__KET____DOT__bi__DOT__ForSig) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x3aU] 
                                           >> 0xbU))))));
    bufp->fullBit(oldp+12663,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x3aU] >> 9U))));
    bufp->fullBit(oldp+12664,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x3aU] >> 8U))));
    bufp->fullBit(oldp+12665,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x3aU] >> 7U))));
    bufp->fullBit(oldp+12666,((1U & (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                       [0x3aU] >> 9U) 
                                      & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x3aU] >> 8U) 
                                         | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x3aU] 
                                            >> 7U))) 
                                     | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x3aU] >> 8U) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x3aU] 
                                           >> 7U))))));
    bufp->fullBit(oldp+12667,((1U & ((((((~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
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
                                           >> 9U) & 
                                          (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                              [0x3aU] 
                                              >> 8U))) 
                                         & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                               [0x3aU] 
                                               >> 7U)))) 
                                     | (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x3aU] >> 9U) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x3aU] 
                                            >> 8U)) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x3aU] 
                                           >> 7U))))));
    bufp->fullBit(oldp+12668,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x3aU] >> 0xaU))));
    bufp->fullBit(oldp+12669,((1U & ((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__58__KET____DOT__bi__DOT__ThiSig) 
                                       >> 1U) & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__58__KET____DOT__bi__DOT__ThiSig) 
                                                 | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                    [0x3aU] 
                                                    >> 0xaU))) 
                                     | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__58__KET____DOT__bi__DOT__ThiSig) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x3aU] 
                                           >> 0xaU))))));
    bufp->fullBit(oldp+12670,((1U & (((((IData)((0U 
                                                 == (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__58__KET____DOT__bi__DOT__ThiSig))) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x3aU] 
                                           >> 0xaU)) 
                                       | ((IData)((1U 
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
    bufp->fullBit(oldp+12671,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x3aU] >> 2U))));
    bufp->fullBit(oldp+12672,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x3aU] >> 1U))));
    bufp->fullBit(oldp+12673,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                               [0x3aU])));
    bufp->fullBit(oldp+12674,((1U & (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                       [0x3aU] >> 2U) 
                                      & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x3aU] >> 1U) 
                                         | vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x3aU])) 
                                     | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x3aU] >> 1U) 
                                        & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                        [0x3aU])))));
    bufp->fullBit(oldp+12675,((1U & ((((((~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
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
                                           >> 2U) & 
                                          (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                              [0x3aU] 
                                              >> 1U))) 
                                         & (~ vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x3aU]))) 
                                     | (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x3aU] >> 2U) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x3aU] 
                                            >> 1U)) 
                                        & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                        [0x3aU])))));
}

VL_ATTR_COLD void Vsimu_top___024root__trace_full_sub_9(Vsimu_top___024root* vlSelf, VerilatedFst::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vsimu_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsimu_top___024root__trace_full_sub_9\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullBit(oldp+12676,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x3aU] >> 4U))));
    bufp->fullBit(oldp+12677,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x3aU] >> 3U))));
    bufp->fullBit(oldp+12678,((1U & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__58__KET____DOT__bi__InData 
                                      & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x3aU] >> 4U) 
                                         | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x3aU] 
                                            >> 3U))) 
                                     | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x3aU] >> 4U) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x3aU] 
                                           >> 3U))))));
    bufp->fullBit(oldp+12679,((1U & ((((((~ vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__58__KET____DOT__bi__InData) 
                                         & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                               [0x3aU] 
                                               >> 4U))) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x3aU] 
                                           >> 3U)) 
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
                                           [0x3aU] 
                                           >> 3U))))));
    bufp->fullBit(oldp+12680,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x3aU] >> 0xdU))));
    bufp->fullBit(oldp+12681,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x3aU] >> 0xcU))));
    bufp->fullBit(oldp+12682,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__58__KET____DOT__bi__DOT__SecSig))));
    bufp->fullBit(oldp+12683,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x3aU] >> 6U))));
    bufp->fullBit(oldp+12684,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x3aU] >> 5U))));
    bufp->fullBit(oldp+12685,((1U & (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__58__KET____DOT__bi__DOT__SecSig) 
                                      & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x3aU] >> 6U) 
                                         | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x3aU] 
                                            >> 5U))) 
                                     | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x3aU] >> 6U) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x3aU] 
                                           >> 5U))))));
    bufp->fullBit(oldp+12686,((1U & ((((((~ (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__58__KET____DOT__bi__DOT__SecSig)) 
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
    bufp->fullBit(oldp+12687,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__58__KET____DOT__bi__DOT__SecSig) 
                                     >> 3U))));
    bufp->fullBit(oldp+12688,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__58__KET____DOT__bi__DOT__SecSig) 
                                     >> 2U))));
    bufp->fullBit(oldp+12689,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__58__KET____DOT__bi__DOT__SecSig) 
                                     >> 1U))));
    bufp->fullBit(oldp+12690,((1U & ((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__58__KET____DOT__bi__DOT__SecSig) 
                                       >> 3U) & (IData)(
                                                        (0U 
                                                         != 
                                                         (6U 
                                                          & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__58__KET____DOT__bi__DOT__SecSig))))) 
                                     | (IData)((6U 
                                                == 
                                                (6U 
                                                 & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__58__KET____DOT__bi__DOT__SecSig))))))));
    bufp->fullBit(oldp+12691,((1U & ((((IData)((2U 
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
    bufp->fullSData(oldp+12692,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                [0x3bU]),14);
    bufp->fullSData(oldp+12693,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellout__wallacefor__BRA__59__KET____DOT__bi__COut),14);
    bufp->fullBit(oldp+12694,((1U & (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__59__KET____DOT__bi__DOT__FifSig) 
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
    bufp->fullBit(oldp+12695,((1U & ((((((~ (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__59__KET____DOT__bi__DOT__FifSig)) 
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
    bufp->fullCData(oldp+12696,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__59__KET____DOT__bi__DOT__SecSig),4);
    bufp->fullBit(oldp+12697,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x3bU] >> 0xbU))));
    bufp->fullBit(oldp+12698,((1U & ((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__59__KET____DOT__bi__DOT__ForSig) 
                                       >> 1U) & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__59__KET____DOT__bi__DOT__ForSig) 
                                                 | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                    [0x3bU] 
                                                    >> 0xbU))) 
                                     | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__59__KET____DOT__bi__DOT__ForSig) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x3bU] 
                                           >> 0xbU))))));
    bufp->fullBit(oldp+12699,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x3bU] >> 9U))));
    bufp->fullBit(oldp+12700,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x3bU] >> 8U))));
    bufp->fullBit(oldp+12701,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x3bU] >> 7U))));
    bufp->fullBit(oldp+12702,((1U & (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
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
    bufp->fullBit(oldp+12703,((1U & ((((((~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
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
    bufp->fullBit(oldp+12704,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x3bU] >> 0xaU))));
    bufp->fullBit(oldp+12705,((1U & ((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__59__KET____DOT__bi__DOT__ThiSig) 
                                       >> 1U) & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__59__KET____DOT__bi__DOT__ThiSig) 
                                                 | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                    [0x3bU] 
                                                    >> 0xaU))) 
                                     | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__59__KET____DOT__bi__DOT__ThiSig) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x3bU] 
                                           >> 0xaU))))));
    bufp->fullBit(oldp+12706,((1U & (((((IData)((0U 
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
    bufp->fullBit(oldp+12707,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x3bU] >> 2U))));
    bufp->fullBit(oldp+12708,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x3bU] >> 1U))));
    bufp->fullBit(oldp+12709,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                               [0x3bU])));
    bufp->fullBit(oldp+12710,((1U & (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                       [0x3bU] >> 2U) 
                                      & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x3bU] >> 1U) 
                                         | vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x3bU])) 
                                     | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x3bU] >> 1U) 
                                        & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                        [0x3bU])))));
    bufp->fullBit(oldp+12711,((1U & ((((((~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
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
    bufp->fullBit(oldp+12712,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x3bU] >> 4U))));
    bufp->fullBit(oldp+12713,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x3bU] >> 3U))));
    bufp->fullBit(oldp+12714,((1U & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__59__KET____DOT__bi__InData 
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
    bufp->fullBit(oldp+12715,((1U & ((((((~ vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__59__KET____DOT__bi__InData) 
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
    bufp->fullBit(oldp+12716,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x3bU] >> 0xdU))));
    bufp->fullBit(oldp+12717,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x3bU] >> 0xcU))));
    bufp->fullBit(oldp+12718,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__59__KET____DOT__bi__DOT__SecSig))));
    bufp->fullBit(oldp+12719,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x3bU] >> 6U))));
    bufp->fullBit(oldp+12720,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x3bU] >> 5U))));
    bufp->fullBit(oldp+12721,((1U & (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__59__KET____DOT__bi__DOT__SecSig) 
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
    bufp->fullBit(oldp+12722,((1U & ((((((~ (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__59__KET____DOT__bi__DOT__SecSig)) 
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
    bufp->fullBit(oldp+12723,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__59__KET____DOT__bi__DOT__SecSig) 
                                     >> 3U))));
    bufp->fullBit(oldp+12724,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__59__KET____DOT__bi__DOT__SecSig) 
                                     >> 2U))));
    bufp->fullBit(oldp+12725,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__59__KET____DOT__bi__DOT__SecSig) 
                                     >> 1U))));
    bufp->fullBit(oldp+12726,((1U & ((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__59__KET____DOT__bi__DOT__SecSig) 
                                       >> 3U) & (IData)(
                                                        (0U 
                                                         != 
                                                         (6U 
                                                          & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__59__KET____DOT__bi__DOT__SecSig))))) 
                                     | (IData)((6U 
                                                == 
                                                (6U 
                                                 & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__59__KET____DOT__bi__DOT__SecSig))))))));
    bufp->fullBit(oldp+12727,((1U & ((((IData)((2U 
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
    bufp->fullSData(oldp+12728,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                [5U]),14);
    bufp->fullSData(oldp+12729,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellout__wallacefor__BRA__5__KET____DOT__bi__COut),14);
    bufp->fullBit(oldp+12730,((1U & (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__5__KET____DOT__bi__DOT__FifSig) 
                                      & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [5U] >> 0xdU) 
                                         | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [5U] >> 0xcU))) 
                                     | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [5U] >> 0xdU) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [5U] >> 0xcU))))));
    bufp->fullBit(oldp+12731,((1U & ((((((~ (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__5__KET____DOT__bi__DOT__FifSig)) 
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
    bufp->fullCData(oldp+12732,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__5__KET____DOT__bi__DOT__SecSig),4);
    bufp->fullBit(oldp+12733,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [5U] >> 0xbU))));
    bufp->fullBit(oldp+12734,((1U & ((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__5__KET____DOT__bi__DOT__ForSig) 
                                       >> 1U) & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__5__KET____DOT__bi__DOT__ForSig) 
                                                 | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                    [5U] 
                                                    >> 0xbU))) 
                                     | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__5__KET____DOT__bi__DOT__ForSig) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [5U] >> 0xbU))))));
    bufp->fullBit(oldp+12735,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [5U] >> 9U))));
    bufp->fullBit(oldp+12736,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [5U] >> 8U))));
    bufp->fullBit(oldp+12737,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [5U] >> 7U))));
    bufp->fullBit(oldp+12738,((1U & (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                       [5U] >> 9U) 
                                      & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [5U] >> 8U) 
                                         | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [5U] >> 7U))) 
                                     | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [5U] >> 8U) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [5U] >> 7U))))));
    bufp->fullBit(oldp+12739,((1U & ((((((~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
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
    bufp->fullBit(oldp+12740,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [5U] >> 0xaU))));
    bufp->fullBit(oldp+12741,((1U & ((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__5__KET____DOT__bi__DOT__ThiSig) 
                                       >> 1U) & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__5__KET____DOT__bi__DOT__ThiSig) 
                                                 | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                    [5U] 
                                                    >> 0xaU))) 
                                     | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__5__KET____DOT__bi__DOT__ThiSig) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [5U] >> 0xaU))))));
    bufp->fullBit(oldp+12742,((1U & (((((IData)((0U 
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
    bufp->fullBit(oldp+12743,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [5U] >> 2U))));
    bufp->fullBit(oldp+12744,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [5U] >> 1U))));
    bufp->fullBit(oldp+12745,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                               [5U])));
    bufp->fullBit(oldp+12746,((1U & (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
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
    bufp->fullBit(oldp+12747,((1U & ((((((~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
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
    bufp->fullBit(oldp+12748,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [5U] >> 4U))));
    bufp->fullBit(oldp+12749,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [5U] >> 3U))));
    bufp->fullBit(oldp+12750,((1U & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__5__KET____DOT__bi__InData 
                                      & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [5U] >> 4U) 
                                         | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [5U] >> 3U))) 
                                     | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [5U] >> 4U) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [5U] >> 3U))))));
    bufp->fullBit(oldp+12751,((1U & ((((((~ vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__5__KET____DOT__bi__InData) 
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
    bufp->fullBit(oldp+12752,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [5U] >> 0xdU))));
    bufp->fullBit(oldp+12753,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [5U] >> 0xcU))));
    bufp->fullBit(oldp+12754,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__5__KET____DOT__bi__DOT__SecSig))));
    bufp->fullBit(oldp+12755,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [5U] >> 6U))));
    bufp->fullBit(oldp+12756,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [5U] >> 5U))));
    bufp->fullBit(oldp+12757,((1U & (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__5__KET____DOT__bi__DOT__SecSig) 
                                      & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [5U] >> 6U) 
                                         | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [5U] >> 5U))) 
                                     | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [5U] >> 6U) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [5U] >> 5U))))));
    bufp->fullBit(oldp+12758,((1U & ((((((~ (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__5__KET____DOT__bi__DOT__SecSig)) 
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
    bufp->fullBit(oldp+12759,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__5__KET____DOT__bi__DOT__SecSig) 
                                     >> 3U))));
    bufp->fullBit(oldp+12760,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__5__KET____DOT__bi__DOT__SecSig) 
                                     >> 2U))));
    bufp->fullBit(oldp+12761,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__5__KET____DOT__bi__DOT__SecSig) 
                                     >> 1U))));
    bufp->fullBit(oldp+12762,((1U & ((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__5__KET____DOT__bi__DOT__SecSig) 
                                       >> 3U) & (IData)(
                                                        (0U 
                                                         != 
                                                         (6U 
                                                          & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__5__KET____DOT__bi__DOT__SecSig))))) 
                                     | (IData)((6U 
                                                == 
                                                (6U 
                                                 & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__5__KET____DOT__bi__DOT__SecSig))))))));
    bufp->fullBit(oldp+12763,((1U & ((((IData)((2U 
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
    bufp->fullSData(oldp+12764,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                [0x3cU]),14);
    bufp->fullSData(oldp+12765,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellout__wallacefor__BRA__60__KET____DOT__bi__COut),14);
    bufp->fullBit(oldp+12766,((1U & (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__60__KET____DOT__bi__DOT__FifSig) 
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
    bufp->fullBit(oldp+12767,((1U & ((((((~ (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__60__KET____DOT__bi__DOT__FifSig)) 
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
    bufp->fullCData(oldp+12768,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__60__KET____DOT__bi__DOT__SecSig),4);
    bufp->fullBit(oldp+12769,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x3cU] >> 0xbU))));
    bufp->fullBit(oldp+12770,((1U & ((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__60__KET____DOT__bi__DOT__ForSig) 
                                       >> 1U) & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__60__KET____DOT__bi__DOT__ForSig) 
                                                 | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                    [0x3cU] 
                                                    >> 0xbU))) 
                                     | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__60__KET____DOT__bi__DOT__ForSig) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x3cU] 
                                           >> 0xbU))))));
    bufp->fullBit(oldp+12771,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x3cU] >> 9U))));
    bufp->fullBit(oldp+12772,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x3cU] >> 8U))));
    bufp->fullBit(oldp+12773,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x3cU] >> 7U))));
    bufp->fullBit(oldp+12774,((1U & (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
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
    bufp->fullBit(oldp+12775,((1U & ((((((~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
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
    bufp->fullBit(oldp+12776,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x3cU] >> 0xaU))));
    bufp->fullBit(oldp+12777,((1U & ((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__60__KET____DOT__bi__DOT__ThiSig) 
                                       >> 1U) & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__60__KET____DOT__bi__DOT__ThiSig) 
                                                 | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                    [0x3cU] 
                                                    >> 0xaU))) 
                                     | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__60__KET____DOT__bi__DOT__ThiSig) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x3cU] 
                                           >> 0xaU))))));
    bufp->fullBit(oldp+12778,((1U & (((((IData)((0U 
                                                 == (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__60__KET____DOT__bi__DOT__ThiSig))) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x3cU] 
                                           >> 0xaU)) 
                                       | ((IData)((1U 
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
    bufp->fullBit(oldp+12779,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x3cU] >> 2U))));
    bufp->fullBit(oldp+12780,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x3cU] >> 1U))));
    bufp->fullBit(oldp+12781,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                               [0x3cU])));
    bufp->fullBit(oldp+12782,((1U & (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                       [0x3cU] >> 2U) 
                                      & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x3cU] >> 1U) 
                                         | vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x3cU])) 
                                     | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x3cU] >> 1U) 
                                        & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                        [0x3cU])))));
    bufp->fullBit(oldp+12783,((1U & ((((((~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
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
                                           >> 2U) & 
                                          (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                              [0x3cU] 
                                              >> 1U))) 
                                         & (~ vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x3cU]))) 
                                     | (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x3cU] >> 2U) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x3cU] 
                                            >> 1U)) 
                                        & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                        [0x3cU])))));
    bufp->fullBit(oldp+12784,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x3cU] >> 4U))));
    bufp->fullBit(oldp+12785,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x3cU] >> 3U))));
    bufp->fullBit(oldp+12786,((1U & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__60__KET____DOT__bi__InData 
                                      & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x3cU] >> 4U) 
                                         | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x3cU] 
                                            >> 3U))) 
                                     | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x3cU] >> 4U) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x3cU] 
                                           >> 3U))))));
    bufp->fullBit(oldp+12787,((1U & ((((((~ vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__60__KET____DOT__bi__InData) 
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
    bufp->fullBit(oldp+12788,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x3cU] >> 0xdU))));
    bufp->fullBit(oldp+12789,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x3cU] >> 0xcU))));
    bufp->fullBit(oldp+12790,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__60__KET____DOT__bi__DOT__SecSig))));
    bufp->fullBit(oldp+12791,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x3cU] >> 6U))));
    bufp->fullBit(oldp+12792,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x3cU] >> 5U))));
    bufp->fullBit(oldp+12793,((1U & (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__60__KET____DOT__bi__DOT__SecSig) 
                                      & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x3cU] >> 6U) 
                                         | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x3cU] 
                                            >> 5U))) 
                                     | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x3cU] >> 6U) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x3cU] 
                                           >> 5U))))));
    bufp->fullBit(oldp+12794,((1U & ((((((~ (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__60__KET____DOT__bi__DOT__SecSig)) 
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
    bufp->fullBit(oldp+12795,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__60__KET____DOT__bi__DOT__SecSig) 
                                     >> 3U))));
    bufp->fullBit(oldp+12796,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__60__KET____DOT__bi__DOT__SecSig) 
                                     >> 2U))));
    bufp->fullBit(oldp+12797,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__60__KET____DOT__bi__DOT__SecSig) 
                                     >> 1U))));
    bufp->fullBit(oldp+12798,((1U & ((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__60__KET____DOT__bi__DOT__SecSig) 
                                       >> 3U) & (IData)(
                                                        (0U 
                                                         != 
                                                         (6U 
                                                          & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__60__KET____DOT__bi__DOT__SecSig))))) 
                                     | (IData)((6U 
                                                == 
                                                (6U 
                                                 & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__60__KET____DOT__bi__DOT__SecSig))))))));
    bufp->fullBit(oldp+12799,((1U & ((((IData)((2U 
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
    bufp->fullSData(oldp+12800,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                [0x3dU]),14);
    bufp->fullSData(oldp+12801,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellout__wallacefor__BRA__61__KET____DOT__bi__COut),14);
    bufp->fullBit(oldp+12802,((1U & (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__61__KET____DOT__bi__DOT__FifSig) 
                                      & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x3dU] >> 0xdU) 
                                         | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x3dU] 
                                            >> 0xcU))) 
                                     | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x3dU] >> 0xdU) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x3dU] 
                                           >> 0xcU))))));
    bufp->fullBit(oldp+12803,((1U & ((((((~ (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__61__KET____DOT__bi__DOT__FifSig)) 
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
    bufp->fullCData(oldp+12804,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__61__KET____DOT__bi__DOT__SecSig),4);
    bufp->fullBit(oldp+12805,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x3dU] >> 0xbU))));
    bufp->fullBit(oldp+12806,((1U & ((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__61__KET____DOT__bi__DOT__ForSig) 
                                       >> 1U) & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__61__KET____DOT__bi__DOT__ForSig) 
                                                 | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                    [0x3dU] 
                                                    >> 0xbU))) 
                                     | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__61__KET____DOT__bi__DOT__ForSig) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x3dU] 
                                           >> 0xbU))))));
    bufp->fullBit(oldp+12807,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x3dU] >> 9U))));
    bufp->fullBit(oldp+12808,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x3dU] >> 8U))));
    bufp->fullBit(oldp+12809,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x3dU] >> 7U))));
    bufp->fullBit(oldp+12810,((1U & (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                       [0x3dU] >> 9U) 
                                      & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x3dU] >> 8U) 
                                         | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x3dU] 
                                            >> 7U))) 
                                     | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x3dU] >> 8U) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x3dU] 
                                           >> 7U))))));
    bufp->fullBit(oldp+12811,((1U & ((((((~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
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
                                           >> 9U) & 
                                          (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                              [0x3dU] 
                                              >> 8U))) 
                                         & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                               [0x3dU] 
                                               >> 7U)))) 
                                     | (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x3dU] >> 9U) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x3dU] 
                                            >> 8U)) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x3dU] 
                                           >> 7U))))));
    bufp->fullBit(oldp+12812,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x3dU] >> 0xaU))));
    bufp->fullBit(oldp+12813,((1U & ((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__61__KET____DOT__bi__DOT__ThiSig) 
                                       >> 1U) & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__61__KET____DOT__bi__DOT__ThiSig) 
                                                 | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                    [0x3dU] 
                                                    >> 0xaU))) 
                                     | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__61__KET____DOT__bi__DOT__ThiSig) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x3dU] 
                                           >> 0xaU))))));
    bufp->fullBit(oldp+12814,((1U & (((((IData)((0U 
                                                 == (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__61__KET____DOT__bi__DOT__ThiSig))) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x3dU] 
                                           >> 0xaU)) 
                                       | ((IData)((1U 
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
    bufp->fullBit(oldp+12815,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x3dU] >> 2U))));
    bufp->fullBit(oldp+12816,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x3dU] >> 1U))));
    bufp->fullBit(oldp+12817,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                               [0x3dU])));
    bufp->fullBit(oldp+12818,((1U & (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                       [0x3dU] >> 2U) 
                                      & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x3dU] >> 1U) 
                                         | vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x3dU])) 
                                     | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x3dU] >> 1U) 
                                        & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                        [0x3dU])))));
    bufp->fullBit(oldp+12819,((1U & ((((((~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
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
                                           >> 2U) & 
                                          (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                              [0x3dU] 
                                              >> 1U))) 
                                         & (~ vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x3dU]))) 
                                     | (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x3dU] >> 2U) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x3dU] 
                                            >> 1U)) 
                                        & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                        [0x3dU])))));
    bufp->fullBit(oldp+12820,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x3dU] >> 4U))));
    bufp->fullBit(oldp+12821,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x3dU] >> 3U))));
    bufp->fullBit(oldp+12822,((1U & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__61__KET____DOT__bi__InData 
                                      & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x3dU] >> 4U) 
                                         | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x3dU] 
                                            >> 3U))) 
                                     | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x3dU] >> 4U) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x3dU] 
                                           >> 3U))))));
    bufp->fullBit(oldp+12823,((1U & ((((((~ vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__61__KET____DOT__bi__InData) 
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
    bufp->fullBit(oldp+12824,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x3dU] >> 0xdU))));
    bufp->fullBit(oldp+12825,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x3dU] >> 0xcU))));
    bufp->fullBit(oldp+12826,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__61__KET____DOT__bi__DOT__SecSig))));
    bufp->fullBit(oldp+12827,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x3dU] >> 6U))));
    bufp->fullBit(oldp+12828,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x3dU] >> 5U))));
    bufp->fullBit(oldp+12829,((1U & (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__61__KET____DOT__bi__DOT__SecSig) 
                                      & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x3dU] >> 6U) 
                                         | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x3dU] 
                                            >> 5U))) 
                                     | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x3dU] >> 6U) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x3dU] 
                                           >> 5U))))));
    bufp->fullBit(oldp+12830,((1U & ((((((~ (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__61__KET____DOT__bi__DOT__SecSig)) 
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
    bufp->fullBit(oldp+12831,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__61__KET____DOT__bi__DOT__SecSig) 
                                     >> 3U))));
    bufp->fullBit(oldp+12832,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__61__KET____DOT__bi__DOT__SecSig) 
                                     >> 2U))));
    bufp->fullBit(oldp+12833,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__61__KET____DOT__bi__DOT__SecSig) 
                                     >> 1U))));
    bufp->fullBit(oldp+12834,((1U & ((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__61__KET____DOT__bi__DOT__SecSig) 
                                       >> 3U) & (IData)(
                                                        (0U 
                                                         != 
                                                         (6U 
                                                          & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__61__KET____DOT__bi__DOT__SecSig))))) 
                                     | (IData)((6U 
                                                == 
                                                (6U 
                                                 & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__61__KET____DOT__bi__DOT__SecSig))))))));
    bufp->fullBit(oldp+12835,((1U & ((((IData)((2U 
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
    bufp->fullSData(oldp+12836,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                [0x3eU]),14);
    bufp->fullSData(oldp+12837,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellout__wallacefor__BRA__62__KET____DOT__bi__COut),14);
    bufp->fullBit(oldp+12838,((1U & (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__62__KET____DOT__bi__DOT__FifSig) 
                                      & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x3eU] >> 0xdU) 
                                         | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x3eU] 
                                            >> 0xcU))) 
                                     | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x3eU] >> 0xdU) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x3eU] 
                                           >> 0xcU))))));
    bufp->fullBit(oldp+12839,((1U & ((((((~ (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__62__KET____DOT__bi__DOT__FifSig)) 
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
    bufp->fullCData(oldp+12840,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__62__KET____DOT__bi__DOT__SecSig),4);
    bufp->fullBit(oldp+12841,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x3eU] >> 0xbU))));
    bufp->fullBit(oldp+12842,((1U & ((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__62__KET____DOT__bi__DOT__ForSig) 
                                       >> 1U) & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__62__KET____DOT__bi__DOT__ForSig) 
                                                 | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                    [0x3eU] 
                                                    >> 0xbU))) 
                                     | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__62__KET____DOT__bi__DOT__ForSig) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x3eU] 
                                           >> 0xbU))))));
    bufp->fullBit(oldp+12843,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x3eU] >> 9U))));
    bufp->fullBit(oldp+12844,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x3eU] >> 8U))));
    bufp->fullBit(oldp+12845,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x3eU] >> 7U))));
    bufp->fullBit(oldp+12846,((1U & (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                       [0x3eU] >> 9U) 
                                      & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x3eU] >> 8U) 
                                         | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x3eU] 
                                            >> 7U))) 
                                     | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x3eU] >> 8U) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x3eU] 
                                           >> 7U))))));
    bufp->fullBit(oldp+12847,((1U & ((((((~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
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
                                           >> 9U) & 
                                          (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                              [0x3eU] 
                                              >> 8U))) 
                                         & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                               [0x3eU] 
                                               >> 7U)))) 
                                     | (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x3eU] >> 9U) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x3eU] 
                                            >> 8U)) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x3eU] 
                                           >> 7U))))));
    bufp->fullBit(oldp+12848,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x3eU] >> 0xaU))));
    bufp->fullBit(oldp+12849,((1U & ((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__62__KET____DOT__bi__DOT__ThiSig) 
                                       >> 1U) & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__62__KET____DOT__bi__DOT__ThiSig) 
                                                 | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                    [0x3eU] 
                                                    >> 0xaU))) 
                                     | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__62__KET____DOT__bi__DOT__ThiSig) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x3eU] 
                                           >> 0xaU))))));
    bufp->fullBit(oldp+12850,((1U & (((((IData)((0U 
                                                 == (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__62__KET____DOT__bi__DOT__ThiSig))) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x3eU] 
                                           >> 0xaU)) 
                                       | ((IData)((1U 
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
    bufp->fullBit(oldp+12851,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x3eU] >> 2U))));
    bufp->fullBit(oldp+12852,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x3eU] >> 1U))));
    bufp->fullBit(oldp+12853,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                               [0x3eU])));
    bufp->fullBit(oldp+12854,((1U & (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                       [0x3eU] >> 2U) 
                                      & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x3eU] >> 1U) 
                                         | vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x3eU])) 
                                     | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x3eU] >> 1U) 
                                        & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                        [0x3eU])))));
    bufp->fullBit(oldp+12855,((1U & ((((((~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
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
                                           >> 2U) & 
                                          (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                              [0x3eU] 
                                              >> 1U))) 
                                         & (~ vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x3eU]))) 
                                     | (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x3eU] >> 2U) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x3eU] 
                                            >> 1U)) 
                                        & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                        [0x3eU])))));
    bufp->fullBit(oldp+12856,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x3eU] >> 4U))));
    bufp->fullBit(oldp+12857,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x3eU] >> 3U))));
    bufp->fullBit(oldp+12858,((1U & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__62__KET____DOT__bi__InData 
                                      & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x3eU] >> 4U) 
                                         | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x3eU] 
                                            >> 3U))) 
                                     | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x3eU] >> 4U) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x3eU] 
                                           >> 3U))))));
    bufp->fullBit(oldp+12859,((1U & ((((((~ vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__62__KET____DOT__bi__InData) 
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
    bufp->fullBit(oldp+12860,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x3eU] >> 0xdU))));
    bufp->fullBit(oldp+12861,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x3eU] >> 0xcU))));
    bufp->fullBit(oldp+12862,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__62__KET____DOT__bi__DOT__SecSig))));
    bufp->fullBit(oldp+12863,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x3eU] >> 6U))));
    bufp->fullBit(oldp+12864,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x3eU] >> 5U))));
    bufp->fullBit(oldp+12865,((1U & (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__62__KET____DOT__bi__DOT__SecSig) 
                                      & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x3eU] >> 6U) 
                                         | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x3eU] 
                                            >> 5U))) 
                                     | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x3eU] >> 6U) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x3eU] 
                                           >> 5U))))));
    bufp->fullBit(oldp+12866,((1U & ((((((~ (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__62__KET____DOT__bi__DOT__SecSig)) 
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
    bufp->fullBit(oldp+12867,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__62__KET____DOT__bi__DOT__SecSig) 
                                     >> 3U))));
    bufp->fullBit(oldp+12868,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__62__KET____DOT__bi__DOT__SecSig) 
                                     >> 2U))));
    bufp->fullBit(oldp+12869,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__62__KET____DOT__bi__DOT__SecSig) 
                                     >> 1U))));
    bufp->fullBit(oldp+12870,((1U & ((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__62__KET____DOT__bi__DOT__SecSig) 
                                       >> 3U) & (IData)(
                                                        (0U 
                                                         != 
                                                         (6U 
                                                          & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__62__KET____DOT__bi__DOT__SecSig))))) 
                                     | (IData)((6U 
                                                == 
                                                (6U 
                                                 & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__62__KET____DOT__bi__DOT__SecSig))))))));
    bufp->fullBit(oldp+12871,((1U & ((((IData)((2U 
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
    bufp->fullSData(oldp+12872,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                [0x3fU]),14);
    bufp->fullSData(oldp+12873,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellout__wallacefor__BRA__63__KET____DOT__bi__COut),14);
    bufp->fullBit(oldp+12874,((1U & (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__63__KET____DOT__bi__DOT__FifSig) 
                                      & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x3fU] >> 0xdU) 
                                         | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x3fU] 
                                            >> 0xcU))) 
                                     | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x3fU] >> 0xdU) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x3fU] 
                                           >> 0xcU))))));
    bufp->fullBit(oldp+12875,((1U & ((((((~ (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__63__KET____DOT__bi__DOT__FifSig)) 
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
    bufp->fullCData(oldp+12876,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__63__KET____DOT__bi__DOT__SecSig),4);
    bufp->fullBit(oldp+12877,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x3fU] >> 0xbU))));
    bufp->fullBit(oldp+12878,((1U & ((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__63__KET____DOT__bi__DOT__ForSig) 
                                       >> 1U) & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__63__KET____DOT__bi__DOT__ForSig) 
                                                 | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                    [0x3fU] 
                                                    >> 0xbU))) 
                                     | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__63__KET____DOT__bi__DOT__ForSig) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x3fU] 
                                           >> 0xbU))))));
    bufp->fullBit(oldp+12879,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x3fU] >> 9U))));
    bufp->fullBit(oldp+12880,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x3fU] >> 8U))));
    bufp->fullBit(oldp+12881,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x3fU] >> 7U))));
    bufp->fullBit(oldp+12882,((1U & (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                       [0x3fU] >> 9U) 
                                      & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x3fU] >> 8U) 
                                         | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x3fU] 
                                            >> 7U))) 
                                     | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x3fU] >> 8U) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x3fU] 
                                           >> 7U))))));
    bufp->fullBit(oldp+12883,((1U & ((((((~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
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
                                           >> 9U) & 
                                          (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                              [0x3fU] 
                                              >> 8U))) 
                                         & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                               [0x3fU] 
                                               >> 7U)))) 
                                     | (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x3fU] >> 9U) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x3fU] 
                                            >> 8U)) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x3fU] 
                                           >> 7U))))));
    bufp->fullBit(oldp+12884,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x3fU] >> 0xaU))));
    bufp->fullBit(oldp+12885,((1U & ((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__63__KET____DOT__bi__DOT__ThiSig) 
                                       >> 1U) & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__63__KET____DOT__bi__DOT__ThiSig) 
                                                 | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                    [0x3fU] 
                                                    >> 0xaU))) 
                                     | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__63__KET____DOT__bi__DOT__ThiSig) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x3fU] 
                                           >> 0xaU))))));
    bufp->fullBit(oldp+12886,((1U & (((((IData)((0U 
                                                 == (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__63__KET____DOT__bi__DOT__ThiSig))) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x3fU] 
                                           >> 0xaU)) 
                                       | ((IData)((1U 
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
    bufp->fullBit(oldp+12887,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x3fU] >> 2U))));
    bufp->fullBit(oldp+12888,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x3fU] >> 1U))));
    bufp->fullBit(oldp+12889,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                               [0x3fU])));
    bufp->fullBit(oldp+12890,((1U & (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                       [0x3fU] >> 2U) 
                                      & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x3fU] >> 1U) 
                                         | vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x3fU])) 
                                     | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x3fU] >> 1U) 
                                        & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                        [0x3fU])))));
    bufp->fullBit(oldp+12891,((1U & ((((((~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
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
                                           >> 2U) & 
                                          (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                              [0x3fU] 
                                              >> 1U))) 
                                         & (~ vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x3fU]))) 
                                     | (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x3fU] >> 2U) 
                                         & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x3fU] 
                                            >> 1U)) 
                                        & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                        [0x3fU])))));
    bufp->fullBit(oldp+12892,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x3fU] >> 4U))));
    bufp->fullBit(oldp+12893,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x3fU] >> 3U))));
    bufp->fullBit(oldp+12894,((1U & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__63__KET____DOT__bi__InData 
                                      & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x3fU] >> 4U) 
                                         | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x3fU] 
                                            >> 3U))) 
                                     | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x3fU] >> 4U) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x3fU] 
                                           >> 3U))))));
    bufp->fullBit(oldp+12895,((1U & ((((((~ vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__63__KET____DOT__bi__InData) 
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
    bufp->fullBit(oldp+12896,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x3fU] >> 0xdU))));
    bufp->fullBit(oldp+12897,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x3fU] >> 0xcU))));
    bufp->fullBit(oldp+12898,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__63__KET____DOT__bi__DOT__SecSig))));
    bufp->fullBit(oldp+12899,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x3fU] >> 6U))));
    bufp->fullBit(oldp+12900,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [0x3fU] >> 5U))));
    bufp->fullBit(oldp+12901,((1U & (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__63__KET____DOT__bi__DOT__SecSig) 
                                      & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [0x3fU] >> 6U) 
                                         | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [0x3fU] 
                                            >> 5U))) 
                                     | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [0x3fU] >> 6U) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [0x3fU] 
                                           >> 5U))))));
    bufp->fullBit(oldp+12902,((1U & ((((((~ (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__63__KET____DOT__bi__DOT__SecSig)) 
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
    bufp->fullBit(oldp+12903,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__63__KET____DOT__bi__DOT__SecSig) 
                                     >> 3U))));
    bufp->fullBit(oldp+12904,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__63__KET____DOT__bi__DOT__SecSig) 
                                     >> 2U))));
    bufp->fullBit(oldp+12905,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__63__KET____DOT__bi__DOT__SecSig) 
                                     >> 1U))));
    bufp->fullBit(oldp+12906,((1U & ((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__63__KET____DOT__bi__DOT__SecSig) 
                                       >> 3U) & (IData)(
                                                        (0U 
                                                         != 
                                                         (6U 
                                                          & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__63__KET____DOT__bi__DOT__SecSig))))) 
                                     | (IData)((6U 
                                                == 
                                                (6U 
                                                 & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__63__KET____DOT__bi__DOT__SecSig))))))));
    bufp->fullBit(oldp+12907,((1U & ((((IData)((2U 
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
    bufp->fullSData(oldp+12908,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                [6U]),14);
    bufp->fullSData(oldp+12909,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellout__wallacefor__BRA__6__KET____DOT__bi__COut),14);
    bufp->fullBit(oldp+12910,((1U & (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__6__KET____DOT__bi__DOT__FifSig) 
                                      & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [6U] >> 0xdU) 
                                         | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [6U] >> 0xcU))) 
                                     | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [6U] >> 0xdU) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [6U] >> 0xcU))))));
    bufp->fullBit(oldp+12911,((1U & ((((((~ (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__6__KET____DOT__bi__DOT__FifSig)) 
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
    bufp->fullCData(oldp+12912,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__6__KET____DOT__bi__DOT__SecSig),4);
    bufp->fullBit(oldp+12913,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [6U] >> 0xbU))));
    bufp->fullBit(oldp+12914,((1U & ((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__6__KET____DOT__bi__DOT__ForSig) 
                                       >> 1U) & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__6__KET____DOT__bi__DOT__ForSig) 
                                                 | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                    [6U] 
                                                    >> 0xbU))) 
                                     | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__6__KET____DOT__bi__DOT__ForSig) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [6U] >> 0xbU))))));
    bufp->fullBit(oldp+12915,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [6U] >> 9U))));
    bufp->fullBit(oldp+12916,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [6U] >> 8U))));
    bufp->fullBit(oldp+12917,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [6U] >> 7U))));
    bufp->fullBit(oldp+12918,((1U & (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                       [6U] >> 9U) 
                                      & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [6U] >> 8U) 
                                         | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [6U] >> 7U))) 
                                     | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [6U] >> 8U) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [6U] >> 7U))))));
    bufp->fullBit(oldp+12919,((1U & ((((((~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [6U] >> 9U)) 
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
    bufp->fullBit(oldp+12920,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [6U] >> 0xaU))));
    bufp->fullBit(oldp+12921,((1U & ((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__6__KET____DOT__bi__DOT__ThiSig) 
                                       >> 1U) & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__6__KET____DOT__bi__DOT__ThiSig) 
                                                 | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                    [6U] 
                                                    >> 0xaU))) 
                                     | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__6__KET____DOT__bi__DOT__ThiSig) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [6U] >> 0xaU))))));
    bufp->fullBit(oldp+12922,((1U & (((((IData)((0U 
                                                 == (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__6__KET____DOT__bi__DOT__ThiSig))) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [6U] >> 0xaU)) 
                                       | ((IData)((1U 
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
    bufp->fullBit(oldp+12923,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [6U] >> 2U))));
    bufp->fullBit(oldp+12924,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [6U] >> 1U))));
    bufp->fullBit(oldp+12925,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                               [6U])));
    bufp->fullBit(oldp+12926,((1U & (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                       [6U] >> 2U) 
                                      & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [6U] >> 1U) 
                                         | vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [6U])) | (
                                                   (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                    [6U] 
                                                    >> 1U) 
                                                   & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                   [6U])))));
    bufp->fullBit(oldp+12927,((1U & ((((((~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [6U] >> 2U)) 
                                         & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                               [6U] 
                                               >> 1U))) 
                                        & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                        [6U]) | (((~ 
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
    bufp->fullBit(oldp+12928,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [6U] >> 4U))));
    bufp->fullBit(oldp+12929,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [6U] >> 3U))));
    bufp->fullBit(oldp+12930,((1U & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__6__KET____DOT__bi__InData 
                                      & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [6U] >> 4U) 
                                         | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [6U] >> 3U))) 
                                     | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [6U] >> 4U) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [6U] >> 3U))))));
    bufp->fullBit(oldp+12931,((1U & ((((((~ vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__6__KET____DOT__bi__InData) 
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
    bufp->fullBit(oldp+12932,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [6U] >> 0xdU))));
    bufp->fullBit(oldp+12933,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [6U] >> 0xcU))));
    bufp->fullBit(oldp+12934,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__6__KET____DOT__bi__DOT__SecSig))));
    bufp->fullBit(oldp+12935,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [6U] >> 6U))));
    bufp->fullBit(oldp+12936,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [6U] >> 5U))));
    bufp->fullBit(oldp+12937,((1U & (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__6__KET____DOT__bi__DOT__SecSig) 
                                      & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [6U] >> 6U) 
                                         | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [6U] >> 5U))) 
                                     | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [6U] >> 6U) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [6U] >> 5U))))));
    bufp->fullBit(oldp+12938,((1U & ((((((~ (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__6__KET____DOT__bi__DOT__SecSig)) 
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
    bufp->fullBit(oldp+12939,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__6__KET____DOT__bi__DOT__SecSig) 
                                     >> 3U))));
    bufp->fullBit(oldp+12940,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__6__KET____DOT__bi__DOT__SecSig) 
                                     >> 2U))));
    bufp->fullBit(oldp+12941,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__6__KET____DOT__bi__DOT__SecSig) 
                                     >> 1U))));
    bufp->fullBit(oldp+12942,((1U & ((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__6__KET____DOT__bi__DOT__SecSig) 
                                       >> 3U) & (IData)(
                                                        (0U 
                                                         != 
                                                         (6U 
                                                          & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__6__KET____DOT__bi__DOT__SecSig))))) 
                                     | (IData)((6U 
                                                == 
                                                (6U 
                                                 & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__6__KET____DOT__bi__DOT__SecSig))))))));
    bufp->fullBit(oldp+12943,((1U & ((((IData)((2U 
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
    bufp->fullSData(oldp+12944,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                [7U]),14);
    bufp->fullSData(oldp+12945,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellout__wallacefor__BRA__7__KET____DOT__bi__COut),14);
    bufp->fullBit(oldp+12946,((1U & (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__7__KET____DOT__bi__DOT__FifSig) 
                                      & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [7U] >> 0xdU) 
                                         | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [7U] >> 0xcU))) 
                                     | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [7U] >> 0xdU) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [7U] >> 0xcU))))));
    bufp->fullBit(oldp+12947,((1U & ((((((~ (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__7__KET____DOT__bi__DOT__FifSig)) 
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
    bufp->fullCData(oldp+12948,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__7__KET____DOT__bi__DOT__SecSig),4);
    bufp->fullBit(oldp+12949,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [7U] >> 0xbU))));
    bufp->fullBit(oldp+12950,((1U & ((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__7__KET____DOT__bi__DOT__ForSig) 
                                       >> 1U) & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__7__KET____DOT__bi__DOT__ForSig) 
                                                 | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                    [7U] 
                                                    >> 0xbU))) 
                                     | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__7__KET____DOT__bi__DOT__ForSig) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [7U] >> 0xbU))))));
    bufp->fullBit(oldp+12951,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [7U] >> 9U))));
    bufp->fullBit(oldp+12952,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [7U] >> 8U))));
    bufp->fullBit(oldp+12953,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [7U] >> 7U))));
    bufp->fullBit(oldp+12954,((1U & (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                       [7U] >> 9U) 
                                      & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [7U] >> 8U) 
                                         | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [7U] >> 7U))) 
                                     | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [7U] >> 8U) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [7U] >> 7U))))));
    bufp->fullBit(oldp+12955,((1U & ((((((~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [7U] >> 9U)) 
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
    bufp->fullBit(oldp+12956,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [7U] >> 0xaU))));
    bufp->fullBit(oldp+12957,((1U & ((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__7__KET____DOT__bi__DOT__ThiSig) 
                                       >> 1U) & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__7__KET____DOT__bi__DOT__ThiSig) 
                                                 | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                    [7U] 
                                                    >> 0xaU))) 
                                     | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__7__KET____DOT__bi__DOT__ThiSig) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [7U] >> 0xaU))))));
    bufp->fullBit(oldp+12958,((1U & (((((IData)((0U 
                                                 == (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__7__KET____DOT__bi__DOT__ThiSig))) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [7U] >> 0xaU)) 
                                       | ((IData)((1U 
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
    bufp->fullBit(oldp+12959,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [7U] >> 2U))));
    bufp->fullBit(oldp+12960,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [7U] >> 1U))));
    bufp->fullBit(oldp+12961,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                               [7U])));
    bufp->fullBit(oldp+12962,((1U & (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                       [7U] >> 2U) 
                                      & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [7U] >> 1U) 
                                         | vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [7U])) | (
                                                   (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                    [7U] 
                                                    >> 1U) 
                                                   & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                   [7U])))));
    bufp->fullBit(oldp+12963,((1U & ((((((~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [7U] >> 2U)) 
                                         & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                               [7U] 
                                               >> 1U))) 
                                        & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                        [7U]) | (((~ 
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
    bufp->fullBit(oldp+12964,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [7U] >> 4U))));
    bufp->fullBit(oldp+12965,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [7U] >> 3U))));
    bufp->fullBit(oldp+12966,((1U & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__7__KET____DOT__bi__InData 
                                      & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [7U] >> 4U) 
                                         | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [7U] >> 3U))) 
                                     | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [7U] >> 4U) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [7U] >> 3U))))));
    bufp->fullBit(oldp+12967,((1U & ((((((~ vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__7__KET____DOT__bi__InData) 
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
    bufp->fullBit(oldp+12968,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [7U] >> 0xdU))));
    bufp->fullBit(oldp+12969,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [7U] >> 0xcU))));
    bufp->fullBit(oldp+12970,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__7__KET____DOT__bi__DOT__SecSig))));
    bufp->fullBit(oldp+12971,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [7U] >> 6U))));
    bufp->fullBit(oldp+12972,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [7U] >> 5U))));
    bufp->fullBit(oldp+12973,((1U & (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__7__KET____DOT__bi__DOT__SecSig) 
                                      & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [7U] >> 6U) 
                                         | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [7U] >> 5U))) 
                                     | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [7U] >> 6U) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [7U] >> 5U))))));
    bufp->fullBit(oldp+12974,((1U & ((((((~ (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__7__KET____DOT__bi__DOT__SecSig)) 
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
    bufp->fullBit(oldp+12975,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__7__KET____DOT__bi__DOT__SecSig) 
                                     >> 3U))));
    bufp->fullBit(oldp+12976,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__7__KET____DOT__bi__DOT__SecSig) 
                                     >> 2U))));
    bufp->fullBit(oldp+12977,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__7__KET____DOT__bi__DOT__SecSig) 
                                     >> 1U))));
    bufp->fullBit(oldp+12978,((1U & ((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__7__KET____DOT__bi__DOT__SecSig) 
                                       >> 3U) & (IData)(
                                                        (0U 
                                                         != 
                                                         (6U 
                                                          & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__7__KET____DOT__bi__DOT__SecSig))))) 
                                     | (IData)((6U 
                                                == 
                                                (6U 
                                                 & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__7__KET____DOT__bi__DOT__SecSig))))))));
    bufp->fullBit(oldp+12979,((1U & ((((IData)((2U 
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
    bufp->fullSData(oldp+12980,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                [8U]),14);
    bufp->fullSData(oldp+12981,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellout__wallacefor__BRA__8__KET____DOT__bi__COut),14);
    bufp->fullBit(oldp+12982,((1U & (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__8__KET____DOT__bi__DOT__FifSig) 
                                      & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [8U] >> 0xdU) 
                                         | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [8U] >> 0xcU))) 
                                     | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [8U] >> 0xdU) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [8U] >> 0xcU))))));
    bufp->fullBit(oldp+12983,((1U & ((((((~ (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__8__KET____DOT__bi__DOT__FifSig)) 
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
    bufp->fullCData(oldp+12984,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__8__KET____DOT__bi__DOT__SecSig),4);
    bufp->fullBit(oldp+12985,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [8U] >> 0xbU))));
    bufp->fullBit(oldp+12986,((1U & ((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__8__KET____DOT__bi__DOT__ForSig) 
                                       >> 1U) & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__8__KET____DOT__bi__DOT__ForSig) 
                                                 | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                    [8U] 
                                                    >> 0xbU))) 
                                     | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__8__KET____DOT__bi__DOT__ForSig) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [8U] >> 0xbU))))));
    bufp->fullBit(oldp+12987,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [8U] >> 9U))));
    bufp->fullBit(oldp+12988,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [8U] >> 8U))));
    bufp->fullBit(oldp+12989,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [8U] >> 7U))));
    bufp->fullBit(oldp+12990,((1U & (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                       [8U] >> 9U) 
                                      & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [8U] >> 8U) 
                                         | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [8U] >> 7U))) 
                                     | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [8U] >> 8U) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [8U] >> 7U))))));
    bufp->fullBit(oldp+12991,((1U & ((((((~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [8U] >> 9U)) 
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
    bufp->fullBit(oldp+12992,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [8U] >> 0xaU))));
    bufp->fullBit(oldp+12993,((1U & ((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__8__KET____DOT__bi__DOT__ThiSig) 
                                       >> 1U) & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__8__KET____DOT__bi__DOT__ThiSig) 
                                                 | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                    [8U] 
                                                    >> 0xaU))) 
                                     | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__8__KET____DOT__bi__DOT__ThiSig) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [8U] >> 0xaU))))));
    bufp->fullBit(oldp+12994,((1U & (((((IData)((0U 
                                                 == (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__8__KET____DOT__bi__DOT__ThiSig))) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [8U] >> 0xaU)) 
                                       | ((IData)((1U 
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
    bufp->fullBit(oldp+12995,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [8U] >> 2U))));
    bufp->fullBit(oldp+12996,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [8U] >> 1U))));
    bufp->fullBit(oldp+12997,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                               [8U])));
    bufp->fullBit(oldp+12998,((1U & (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                       [8U] >> 2U) 
                                      & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [8U] >> 1U) 
                                         | vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [8U])) | (
                                                   (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                    [8U] 
                                                    >> 1U) 
                                                   & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                   [8U])))));
    bufp->fullBit(oldp+12999,((1U & ((((((~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [8U] >> 2U)) 
                                         & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                               [8U] 
                                               >> 1U))) 
                                        & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                        [8U]) | (((~ 
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
    bufp->fullBit(oldp+13000,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [8U] >> 4U))));
    bufp->fullBit(oldp+13001,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [8U] >> 3U))));
    bufp->fullBit(oldp+13002,((1U & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__8__KET____DOT__bi__InData 
                                      & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [8U] >> 4U) 
                                         | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [8U] >> 3U))) 
                                     | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [8U] >> 4U) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [8U] >> 3U))))));
    bufp->fullBit(oldp+13003,((1U & ((((((~ vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__8__KET____DOT__bi__InData) 
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
    bufp->fullBit(oldp+13004,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [8U] >> 0xdU))));
    bufp->fullBit(oldp+13005,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [8U] >> 0xcU))));
    bufp->fullBit(oldp+13006,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__8__KET____DOT__bi__DOT__SecSig))));
    bufp->fullBit(oldp+13007,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [8U] >> 6U))));
    bufp->fullBit(oldp+13008,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [8U] >> 5U))));
    bufp->fullBit(oldp+13009,((1U & (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__8__KET____DOT__bi__DOT__SecSig) 
                                      & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [8U] >> 6U) 
                                         | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [8U] >> 5U))) 
                                     | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [8U] >> 6U) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [8U] >> 5U))))));
    bufp->fullBit(oldp+13010,((1U & ((((((~ (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__8__KET____DOT__bi__DOT__SecSig)) 
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
    bufp->fullBit(oldp+13011,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__8__KET____DOT__bi__DOT__SecSig) 
                                     >> 3U))));
    bufp->fullBit(oldp+13012,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__8__KET____DOT__bi__DOT__SecSig) 
                                     >> 2U))));
    bufp->fullBit(oldp+13013,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__8__KET____DOT__bi__DOT__SecSig) 
                                     >> 1U))));
    bufp->fullBit(oldp+13014,((1U & ((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__8__KET____DOT__bi__DOT__SecSig) 
                                       >> 3U) & (IData)(
                                                        (0U 
                                                         != 
                                                         (6U 
                                                          & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__8__KET____DOT__bi__DOT__SecSig))))) 
                                     | (IData)((6U 
                                                == 
                                                (6U 
                                                 & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__8__KET____DOT__bi__DOT__SecSig))))))));
    bufp->fullBit(oldp+13015,((1U & ((((IData)((2U 
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
    bufp->fullSData(oldp+13016,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                [9U]),14);
    bufp->fullSData(oldp+13017,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellout__wallacefor__BRA__9__KET____DOT__bi__COut),14);
    bufp->fullBit(oldp+13018,((1U & (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__9__KET____DOT__bi__DOT__FifSig) 
                                      & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [9U] >> 0xdU) 
                                         | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [9U] >> 0xcU))) 
                                     | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [9U] >> 0xdU) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [9U] >> 0xcU))))));
    bufp->fullBit(oldp+13019,((1U & ((((((~ (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__9__KET____DOT__bi__DOT__FifSig)) 
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
    bufp->fullCData(oldp+13020,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__9__KET____DOT__bi__DOT__SecSig),4);
    bufp->fullBit(oldp+13021,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [9U] >> 0xbU))));
    bufp->fullBit(oldp+13022,((1U & ((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__9__KET____DOT__bi__DOT__ForSig) 
                                       >> 1U) & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__9__KET____DOT__bi__DOT__ForSig) 
                                                 | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                    [9U] 
                                                    >> 0xbU))) 
                                     | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__9__KET____DOT__bi__DOT__ForSig) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [9U] >> 0xbU))))));
    bufp->fullBit(oldp+13023,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [9U] >> 9U))));
    bufp->fullBit(oldp+13024,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [9U] >> 8U))));
    bufp->fullBit(oldp+13025,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [9U] >> 7U))));
    bufp->fullBit(oldp+13026,((1U & (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                       [9U] >> 9U) 
                                      & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [9U] >> 8U) 
                                         | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [9U] >> 7U))) 
                                     | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [9U] >> 8U) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [9U] >> 7U))))));
    bufp->fullBit(oldp+13027,((1U & ((((((~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [9U] >> 9U)) 
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
    bufp->fullBit(oldp+13028,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [9U] >> 0xaU))));
    bufp->fullBit(oldp+13029,((1U & ((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__9__KET____DOT__bi__DOT__ThiSig) 
                                       >> 1U) & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__9__KET____DOT__bi__DOT__ThiSig) 
                                                 | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                    [9U] 
                                                    >> 0xaU))) 
                                     | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__9__KET____DOT__bi__DOT__ThiSig) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [9U] >> 0xaU))))));
    bufp->fullBit(oldp+13030,((1U & (((((IData)((0U 
                                                 == (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__9__KET____DOT__bi__DOT__ThiSig))) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [9U] >> 0xaU)) 
                                       | ((IData)((1U 
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
    bufp->fullBit(oldp+13031,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [9U] >> 2U))));
    bufp->fullBit(oldp+13032,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [9U] >> 1U))));
    bufp->fullBit(oldp+13033,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                               [9U])));
    bufp->fullBit(oldp+13034,((1U & (((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                       [9U] >> 2U) 
                                      & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [9U] >> 1U) 
                                         | vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [9U])) | (
                                                   (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                    [9U] 
                                                    >> 1U) 
                                                   & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                                   [9U])))));
    bufp->fullBit(oldp+13035,((1U & ((((((~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                             [9U] >> 2U)) 
                                         & (~ (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                               [9U] 
                                               >> 1U))) 
                                        & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                        [9U]) | (((~ 
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
    bufp->fullBit(oldp+13036,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [9U] >> 4U))));
    bufp->fullBit(oldp+13037,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [9U] >> 3U))));
    bufp->fullBit(oldp+13038,((1U & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__9__KET____DOT__bi__InData 
                                      & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [9U] >> 4U) 
                                         | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [9U] >> 3U))) 
                                     | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [9U] >> 4U) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [9U] >> 3U))))));
    bufp->fullBit(oldp+13039,((1U & ((((((~ vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellinp__wallacefor__BRA__9__KET____DOT__bi__InData) 
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
    bufp->fullBit(oldp+13040,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [9U] >> 0xdU))));
    bufp->fullBit(oldp+13041,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [9U] >> 0xcU))));
    bufp->fullBit(oldp+13042,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__9__KET____DOT__bi__DOT__SecSig))));
    bufp->fullBit(oldp+13043,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [9U] >> 6U))));
    bufp->fullBit(oldp+13044,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                     [9U] >> 5U))));
    bufp->fullBit(oldp+13045,((1U & (((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__9__KET____DOT__bi__DOT__SecSig) 
                                      & ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                          [9U] >> 6U) 
                                         | (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                            [9U] >> 5U))) 
                                     | ((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                         [9U] >> 6U) 
                                        & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__WallaceInter
                                           [9U] >> 5U))))));
    bufp->fullBit(oldp+13046,((1U & ((((((~ (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__9__KET____DOT__bi__DOT__SecSig)) 
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
    bufp->fullBit(oldp+13047,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__9__KET____DOT__bi__DOT__SecSig) 
                                     >> 3U))));
    bufp->fullBit(oldp+13048,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__9__KET____DOT__bi__DOT__SecSig) 
                                     >> 2U))));
    bufp->fullBit(oldp+13049,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__9__KET____DOT__bi__DOT__SecSig) 
                                     >> 1U))));
    bufp->fullBit(oldp+13050,((1U & ((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__9__KET____DOT__bi__DOT__SecSig) 
                                       >> 3U) & (IData)(
                                                        (0U 
                                                         != 
                                                         (6U 
                                                          & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__9__KET____DOT__bi__DOT__SecSig))))) 
                                     | (IData)((6U 
                                                == 
                                                (6U 
                                                 & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__9__KET____DOT__bi__DOT__SecSig))))))));
    bufp->fullBit(oldp+13051,((1U & ((((IData)((2U 
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
    bufp->fullBit(oldp+13052,(((IData)(vlSelf->simu_top__DOT__soc__DOT__m0_arvalid) 
                               & (IData)(vlSelf->simu_top__DOT__soc__DOT__m0_arready))));
    bufp->fullBit(oldp+13053,(((IData)(vlSelf->simu_top__DOT__soc__DOT__m0_awvalid) 
                               & (IData)(vlSelf->simu_top__DOT__soc__DOT__m0_awready))));
    bufp->fullBit(oldp+13054,(((IData)(vlSelf->simu_top__DOT__soc__DOT__m0_wvalid) 
                               & (IData)(vlSelf->simu_top__DOT__soc__DOT__m0_wready))));
    bufp->fullBit(oldp+13055,(((IData)(vlSelf->simu_top__DOT__soc__DOT__sram_axi_ram__DOT__ram_r_en) 
                               & (~ (IData)(vlSelf->simu_top__DOT__soc__DOT__sram_axi_ram__DOT__ram_r_a_data_arlen_last)))));
    bufp->fullBit(oldp+13056,(((IData)(vlSelf->simu_top__DOT__soc__DOT__sram_axi_ram__DOT__ram_r_a_pop) 
                               & (IData)(vlSelf->simu_top__DOT__soc__DOT__sram_axi_ram__DOT__ram_r_a_queue_valid))));
    bufp->fullBit(oldp+13057,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__AXI_SLAVE_MUX__DOT__s_rready) 
                                     | (~ (IData)(vlSelf->simu_top__DOT__soc__DOT__sram_axi_ram__DOT__ram_r_rvalid))))));
    bufp->fullBit(oldp+13058,(((IData)(vlSelf->simu_top__DOT__soc__DOT__sram_axi_ram__DOT__ram_w_en) 
                               & (~ (IData)(vlSelf->simu_top__DOT__soc__DOT__sram_axi_ram__DOT__ram_w_wlast)))));
    bufp->fullBit(oldp+13059,(((IData)(vlSelf->simu_top__DOT__soc__DOT__sram_axi_ram__DOT__ram_w_a_pop) 
                               & (IData)(vlSelf->simu_top__DOT__soc__DOT__sram_axi_ram__DOT__ram_w_a_queue_valid))));
    bufp->fullBit(oldp+13060,(((IData)(vlSelf->simu_top__DOT__soc__DOT__sram_axi_ram__DOT__ram_w_a_pop) 
                               & ((IData)(vlSelf->simu_top__DOT__soc__DOT__sram_axi_ram__DOT__ram_w_b_pop) 
                                  | (~ (IData)(vlSelf->simu_top__DOT__soc__DOT__sram_axi_ram__DOT__ram_w_b_valid))))));
    bufp->fullBit(oldp+13061,(((IData)(vlSelf->simu_top__DOT__soc__DOT__sram_axi_ram__DOT__ram_w_b_pop) 
                               & (IData)(vlSelf->simu_top__DOT__soc__DOT__sram_axi_ram__DOT__ram_w_b_queue_valid))));
    bufp->fullBit(oldp+13062,(vlSelf->simu_top__DOT__soc__DOT__cpu_bvalid));
    bufp->fullBit(oldp+13063,(vlSelf->simu_top__DOT__soc__DOT__cpu_arready));
    bufp->fullIData(oldp+13064,(vlSelf->simu_top__DOT__soc__DOT__m0_rdata),32);
    bufp->fullBit(oldp+13065,(vlSelf->simu_top__DOT__soc__DOT__cpu_rvalid));
    bufp->fullBit(oldp+13066,(vlSelf->simu_top__DOT__soc__DOT__m0_awvalid));
    bufp->fullBit(oldp+13067,(vlSelf->simu_top__DOT__soc__DOT__m0_wvalid));
    bufp->fullBit(oldp+13068,(vlSelf->simu_top__DOT__soc__DOT__m0_bready));
    bufp->fullBit(oldp+13069,(vlSelf->simu_top__DOT__soc__DOT__m0_arvalid));
    bufp->fullBit(oldp+13070,(vlSelf->simu_top__DOT__soc__DOT__m0_rready));
    bufp->fullBit(oldp+13071,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__AXI_SLAVE_MUX__DOT__s_awvalid))));
    bufp->fullBit(oldp+13072,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__AXI_SLAVE_MUX__DOT__s_wvalid))));
    bufp->fullBit(oldp+13073,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__AXI_SLAVE_MUX__DOT__s_bready))));
    bufp->fullBit(oldp+13074,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__AXI_SLAVE_MUX__DOT__s_arvalid))));
    bufp->fullBit(oldp+13075,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__AXI_SLAVE_MUX__DOT__s_rready))));
    bufp->fullBit(oldp+13076,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__AXI_SLAVE_MUX__DOT__s_awvalid) 
                                     >> 3U))));
    bufp->fullBit(oldp+13077,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__AXI_SLAVE_MUX__DOT__s_wvalid) 
                                     >> 3U))));
    bufp->fullBit(oldp+13078,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__AXI_SLAVE_MUX__DOT__s_bready) 
                                     >> 3U))));
    bufp->fullBit(oldp+13079,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__AXI_SLAVE_MUX__DOT__s_arvalid) 
                                     >> 3U))));
    bufp->fullBit(oldp+13080,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__AXI_SLAVE_MUX__DOT__s_rready) 
                                     >> 3U))));
    bufp->fullBit(oldp+13081,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__AXI_SLAVE_MUX__DOT__s_awvalid) 
                                     >> 2U))));
    bufp->fullBit(oldp+13082,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__AXI_SLAVE_MUX__DOT__s_wvalid) 
                                     >> 2U))));
    bufp->fullBit(oldp+13083,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__AXI_SLAVE_MUX__DOT__s_bready) 
                                     >> 2U))));
    bufp->fullBit(oldp+13084,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__AXI_SLAVE_MUX__DOT__s_arvalid) 
                                     >> 2U))));
    bufp->fullBit(oldp+13085,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__AXI_SLAVE_MUX__DOT__s_rready) 
                                     >> 2U))));
    bufp->fullBit(oldp+13086,(vlSelf->simu_top__DOT__soc__DOT__conf_axi_ram__DOT__ram_r_en));
    bufp->fullCData(oldp+13087,(vlSelf->simu_top__DOT__soc__DOT__conf_s_ram_wen),4);
    bufp->fullBit(oldp+13088,(vlSelf->simu_top__DOT__soc__DOT__APB_DEV__DOT__apb_valid_cpu));
    bufp->fullCData(oldp+13089,(vlSelf->simu_top__DOT__soc__DOT__APB_DEV__DOT__AA_axi2apb_bridge_cpu__DOT__csr_rw_sm_nxt),4);
    bufp->fullBit(oldp+13090,(vlSelf->simu_top__DOT__soc__DOT__APB_DEV__DOT__nand_module__DOT__NAND__DOT__NANDtag));
    bufp->fullBit(oldp+13091,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__AXI_SLAVE_MUX__DOT__s_awvalid) 
                                     >> 1U))));
    bufp->fullBit(oldp+13092,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__AXI_SLAVE_MUX__DOT__s_wvalid) 
                                     >> 1U))));
    bufp->fullBit(oldp+13093,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__AXI_SLAVE_MUX__DOT__s_bready) 
                                     >> 1U))));
    bufp->fullBit(oldp+13094,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__AXI_SLAVE_MUX__DOT__s_arvalid) 
                                     >> 1U))));
    bufp->fullBit(oldp+13095,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__AXI_SLAVE_MUX__DOT__s_rready) 
                                     >> 1U))));
    bufp->fullBit(oldp+13096,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__AXI_SLAVE_MUX__DOT__s_awvalid) 
                                     >> 4U))));
    bufp->fullBit(oldp+13097,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__AXI_SLAVE_MUX__DOT__s_wvalid) 
                                     >> 4U))));
    bufp->fullBit(oldp+13098,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__AXI_SLAVE_MUX__DOT__s_bready) 
                                     >> 4U))));
    bufp->fullBit(oldp+13099,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__AXI_SLAVE_MUX__DOT__s_arvalid) 
                                     >> 4U))));
    bufp->fullBit(oldp+13100,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__AXI_SLAVE_MUX__DOT__s_rready) 
                                     >> 4U))));
    bufp->fullCData(oldp+13101,(vlSelf->simu_top__DOT__soc__DOT__AXI_SLAVE_MUX__DOT__s_awvalid),5);
    bufp->fullCData(oldp+13102,(vlSelf->simu_top__DOT__soc__DOT__AXI_SLAVE_MUX__DOT__s_wvalid),5);
    bufp->fullCData(oldp+13103,(vlSelf->simu_top__DOT__soc__DOT__AXI_SLAVE_MUX__DOT__s_bready),5);
    bufp->fullCData(oldp+13104,(vlSelf->simu_top__DOT__soc__DOT__AXI_SLAVE_MUX__DOT__s_arvalid),5);
    bufp->fullCData(oldp+13105,(vlSelf->simu_top__DOT__soc__DOT__AXI_SLAVE_MUX__DOT__s_rready),5);
    bufp->fullBit(oldp+13106,(vlSelf->simu_top__DOT__soc__DOT__AXI_SLAVE_MUX__DOT__wr_dir_ins));
    bufp->fullBit(oldp+13107,(vlSelf->simu_top__DOT__soc__DOT__AXI_SLAVE_MUX__DOT__rd_dir_ins));
    bufp->fullBit(oldp+13108,(vlSelf->simu_top__DOT__soc__DOT__conf_axi_ram__DOT__ram_r_a_data_push));
    bufp->fullBit(oldp+13109,(vlSelf->simu_top__DOT__soc__DOT__conf_axi_ram__DOT__ram_r_a_pop));
    bufp->fullBit(oldp+13110,(vlSelf->simu_top__DOT__soc__DOT__conf_axi_ram__DOT__ram_r_a_push));
    bufp->fullBit(oldp+13111,(vlSelf->simu_top__DOT__soc__DOT__conf_axi_ram__DOT__ram_r_a_queue_push));
    bufp->fullBit(oldp+13112,(vlSelf->simu_top__DOT__soc__DOT__conf_axi_ram__DOT__ram_w_a_data_push));
    bufp->fullBit(oldp+13113,(vlSelf->simu_top__DOT__soc__DOT__conf_axi_ram__DOT__ram_w_a_pop));
    bufp->fullBit(oldp+13114,(vlSelf->simu_top__DOT__soc__DOT__conf_axi_ram__DOT__ram_w_a_push));
    bufp->fullBit(oldp+13115,(vlSelf->simu_top__DOT__soc__DOT__conf_axi_ram__DOT__ram_w_a_queue_push));
    bufp->fullBit(oldp+13116,(vlSelf->simu_top__DOT__soc__DOT__conf_axi_ram__DOT__ram_w_b_pop));
    bufp->fullBit(oldp+13117,(vlSelf->simu_top__DOT__soc__DOT__conf_axi_ram__DOT__ram_w_b_queue_push));
    bufp->fullBit(oldp+13118,(vlSelf->simu_top__DOT__soc__DOT__conf_axi_ram__DOT__ram_w_en));
    bufp->fullBit(oldp+13119,(vlSelf->simu_top__DOT__soc__DOT__conf_axi_ram__DOT__ram_w_go));
    bufp->fullBit(oldp+13120,((0U != (IData)(vlSelf->simu_top__DOT__soc__DOT__conf_s_ram_wen))));
    bufp->fullBit(oldp+13121,(vlSelf->simu_top__DOT__soc__DOT__confreg__DOT__write_timer));
    bufp->fullBit(oldp+13122,(vlSelf->simu_top__DOT__soc__DOT__confreg__DOT__write_uart_valid));
    bufp->fullCData(oldp+13123,(vlSelf->simu_top__DOT__soc__DOT__confreg__DOT__next_state),3);
    bufp->fullSData(oldp+13124,(vlSelf->simu_top__DOT__soc__DOT__confreg__DOT__btn_key_tmp),16);
    bufp->fullBit(oldp+13125,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__ds_allowin));
    bufp->fullBit(oldp+13126,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__es_allowin));
    bufp->fullBit(oldp+13127,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__ms_allowin));
    bufp->fullBit(oldp+13128,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__fs_to_ds_valid));
    bufp->fullBit(oldp+13129,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__ds_to_es_valid));
    bufp->fullBit(oldp+13130,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__es_to_ms_valid));
    bufp->fullBit(oldp+13131,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__ms_to_ws_valid));
    bufp->fullQData(oldp+13132,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__mul_result),64);
    bufp->fullBit(oldp+13134,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__icacop_op_en));
    bufp->fullBit(oldp+13135,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__dcacop_op_en));
    bufp->fullIData(oldp+13136,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__if_stage__DOT__nextpc),32);
    bufp->fullBit(oldp+13137,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__fetch_en));
    bufp->fullBit(oldp+13138,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__btb_add_entry));
    bufp->fullBit(oldp+13139,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__btb_operate_en));
    bufp->fullBit(oldp+13140,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__btb_pre_error));
    bufp->fullBit(oldp+13141,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__btb_target_error));
    bufp->fullBit(oldp+13142,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__id_stage__DOT__br_taken));
    bufp->fullIData(oldp+13143,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__id_stage__DOT__br_target),32);
    bufp->fullBit(oldp+13144,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__data_fetch));
    bufp->fullWData(oldp+13145,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__ds_to_es_bus),350);
    bufp->fullWData(oldp+13156,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__es_to_ms_bus),425);
    bufp->fullWData(oldp+13170,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__ms_to_ws_bus),460);
    bufp->fullQData(oldp+13185,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__br_bus),33);
    bufp->fullQData(oldp+13187,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__ms_to_ds_forward_bus),39);
    bufp->fullBit(oldp+13189,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__inst_valid));
    bufp->fullCData(oldp+13190,((0xffU & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__if_stage__DOT__nextpc 
                                          >> 4U))),8);
    bufp->fullCData(oldp+13191,((0xfU & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__if_stage__DOT__nextpc)),4);
    bufp->fullBit(oldp+13192,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__inst_addr_ok));
    bufp->fullBit(oldp+13193,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__inst_data_ok));
    bufp->fullIData(oldp+13194,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__inst_rdata),32);
    bufp->fullBit(oldp+13195,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__inst_ret_valid));
    bufp->fullBit(oldp+13196,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__data_valid));
    bufp->fullBit(oldp+13197,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__data_addr_ok));
    bufp->fullBit(oldp+13198,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__axi_bridge__DOT__rd_requst_can_receive));
    bufp->fullBit(oldp+13199,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__data_ret_valid));
    bufp->fullBit(oldp+13200,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__preld_en));
    bufp->fullIData(oldp+13201,((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__if_stage__DOT__nextpc 
                                 >> 0xdU)),19);
    bufp->fullBit(oldp+13202,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__if_stage__DOT__nextpc 
                                     >> 0xcU))));
    bufp->fullCData(oldp+13203,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__dcache__DOT__way0_bank0_addra),8);
    bufp->fullIData(oldp+13204,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__dcache__DOT__bank_dina),32);
    bufp->fullCData(oldp+13205,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__dcache__DOT__way0_bank0_wea),4);
    bufp->fullCData(oldp+13206,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__dcache__DOT__way0_bank1_addra),8);
    bufp->fullCData(oldp+13207,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__dcache__DOT__way0_bank1_wea),4);
    bufp->fullCData(oldp+13208,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__dcache__DOT__way0_bank2_addra),8);
    bufp->fullCData(oldp+13209,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__dcache__DOT__way0_bank2_wea),4);
    bufp->fullCData(oldp+13210,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__dcache__DOT__way0_bank3_addra),8);
    bufp->fullCData(oldp+13211,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__dcache__DOT__way0_bank3_wea),4);
    bufp->fullCData(oldp+13212,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__dcache__DOT__way1_bank0_addra),8);
    bufp->fullCData(oldp+13213,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__dcache__DOT__way1_bank0_wea),4);
    bufp->fullCData(oldp+13214,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__dcache__DOT__way1_bank1_addra),8);
    bufp->fullCData(oldp+13215,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__dcache__DOT__way1_bank1_wea),4);
    bufp->fullCData(oldp+13216,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__dcache__DOT__way1_bank2_addra),8);
    bufp->fullCData(oldp+13217,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__dcache__DOT__way1_bank2_wea),4);
    bufp->fullCData(oldp+13218,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__dcache__DOT__way1_bank3_addra),8);
    bufp->fullCData(oldp+13219,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__dcache__DOT__way1_bank3_wea),4);
    bufp->fullCData(oldp+13220,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__dcache__DOT__tagv_addra),8);
    bufp->fullBit(oldp+13221,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__dcache__DOT__way0_tagv_wea));
    bufp->fullBit(oldp+13222,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__dcache__DOT__way1_tagv_wea));
    bufp->fullCData(oldp+13223,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__dcache__DOT__main_state_index),8);
    bufp->fullBit(oldp+13224,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__dcache__DOT__main_idle2lookup));
    bufp->fullBit(oldp+13225,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__dcache__DOT__main_lookup2lookup));
    bufp->fullBit(oldp+13226,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__dcache__DOT__tagv_wea_en));
    bufp->fullBit(oldp+13227,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__dcache__DOT__way0_wr_en));
    bufp->fullBit(oldp+13228,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__dcache__DOT__way1_wr_en));
    bufp->fullBit(oldp+13229,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__dcache__DOT__req_or_inst_valid));
    bufp->fullBit(oldp+13230,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__exe_stage__DOT__es_ready_go));
    bufp->fullBit(oldp+13231,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__exe_stage__DOT__dcache_req_or_inst_en));
    bufp->fullCData(oldp+13232,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__icache__DOT__bank_addra),8);
    bufp->fullIData(oldp+13233,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__icache__DOT__bank_dina),32);
    bufp->fullCData(oldp+13234,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__icache__DOT__way0_bank0_wea),4);
    bufp->fullCData(oldp+13235,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__icache__DOT__way0_bank1_wea),4);
    bufp->fullCData(oldp+13236,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__icache__DOT__way0_bank2_wea),4);
    bufp->fullCData(oldp+13237,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__icache__DOT__way0_bank3_wea),4);
    bufp->fullCData(oldp+13238,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__icache__DOT__way1_bank0_wea),4);
    bufp->fullCData(oldp+13239,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__icache__DOT__way1_bank1_wea),4);
    bufp->fullCData(oldp+13240,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__icache__DOT__way1_bank2_wea),4);
    bufp->fullCData(oldp+13241,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__icache__DOT__way1_bank3_wea),4);
    bufp->fullCData(oldp+13242,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__icache__DOT__tagv_addra),8);
    bufp->fullBit(oldp+13243,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__icache__DOT__way0_tagv_wea));
    bufp->fullBit(oldp+13244,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__icache__DOT__way1_tagv_wea));
    bufp->fullBit(oldp+13245,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__icache__DOT__tagv_wea_en));
    bufp->fullBit(oldp+13246,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__icache__DOT__way0_wr_en));
    bufp->fullBit(oldp+13247,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__icache__DOT__way1_wr_en));
    bufp->fullCData(oldp+13248,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__icache__DOT__real_offset),4);
    bufp->fullCData(oldp+13249,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__icache__DOT__real_index),8);
    bufp->fullBit(oldp+13250,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__icache__DOT__req_or_inst_valid));
    bufp->fullBit(oldp+13251,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__id_stage__DOT__ds_ready_go));
    bufp->fullBit(oldp+13252,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__id_stage__DOT__btb_pre_error_flush));
    bufp->fullBit(oldp+13253,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__id_stage__DOT__rj_eq_rd));
    bufp->fullBit(oldp+13254,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__id_stage__DOT__rj_lt_rd_sign));
    bufp->fullBit(oldp+13255,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__id_stage__DOT__rj_lt_rd_unsign));
    bufp->fullBit(oldp+13256,((1U & (IData)((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__ms_to_ds_forward_bus 
                                             >> 0x25U)))));
    bufp->fullCData(oldp+13257,((0x1fU & (IData)((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__ms_to_ds_forward_bus 
                                                  >> 0x20U)))),5);
    bufp->fullIData(oldp+13258,((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__ms_to_ds_forward_bus)),32);
    bufp->fullBit(oldp+13259,((1U & (IData)((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__ms_to_ds_forward_bus 
                                             >> 0x26U)))));
    bufp->fullIData(oldp+13260,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__id_stage__DOT__rj_value_forward_es),32);
    bufp->fullIData(oldp+13261,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__id_stage__DOT__rkd_value_forward_es),32);
    bufp->fullBit(oldp+13262,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__if_stage__DOT__fs_ready_go));
    bufp->fullBit(oldp+13263,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__if_stage__DOT__fs_allowin));
    bufp->fullBit(oldp+13264,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__if_stage__DOT__to_fs_valid));
    bufp->fullBit(oldp+13265,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__if_stage__DOT__pfs_ready_go));
    bufp->fullBit(oldp+13266,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__if_stage__DOT__pfs_excp_adef));
    bufp->fullBit(oldp+13267,((1U & (IData)((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__br_bus 
                                             >> 0x20U)))));
    bufp->fullIData(oldp+13268,((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__br_bus)),32);
    bufp->fullBit(oldp+13269,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__if_stage__DOT__flush_inst_delay));
    bufp->fullBit(oldp+13270,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__if_stage__DOT__flush_inst_go_dirt));
    bufp->fullBit(oldp+13271,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__mem_stage__DOT__ms_ready_go));
    bufp->fullIData(oldp+13272,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__mem_stage__DOT__ms_final_result),32);
    bufp->fullIData(oldp+13273,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__mem_stage__DOT__ms_rdata),32);
    bufp->fullCData(oldp+13274,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__mem_stage__DOT__mem_byteLoaded),8);
    bufp->fullSData(oldp+13275,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__mem_stage__DOT__mem_halfLoaded),16);
    bufp->fullCData(oldp+13276,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__10__KET____DOT__bi__DOT__ThiSig),2);
    bufp->fullCData(oldp+13277,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__10__KET____DOT__bi__DOT__ForSig),2);
    bufp->fullBit(oldp+13278,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__10__KET____DOT__bi__DOT__FifSig));
    bufp->fullBit(oldp+13279,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__10__KET____DOT__bi__DOT__ForSig) 
                                     >> 1U))));
    bufp->fullBit(oldp+13280,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__10__KET____DOT__bi__DOT__ForSig))));
    bufp->fullBit(oldp+13281,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__10__KET____DOT__bi__DOT__ThiSig) 
                                     >> 1U))));
    bufp->fullBit(oldp+13282,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__10__KET____DOT__bi__DOT__ThiSig))));
    bufp->fullCData(oldp+13283,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__11__KET____DOT__bi__DOT__ThiSig),2);
    bufp->fullCData(oldp+13284,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__11__KET____DOT__bi__DOT__ForSig),2);
    bufp->fullBit(oldp+13285,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__11__KET____DOT__bi__DOT__FifSig));
    bufp->fullBit(oldp+13286,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__11__KET____DOT__bi__DOT__ForSig) 
                                     >> 1U))));
    bufp->fullBit(oldp+13287,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__11__KET____DOT__bi__DOT__ForSig))));
    bufp->fullBit(oldp+13288,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__11__KET____DOT__bi__DOT__ThiSig) 
                                     >> 1U))));
    bufp->fullBit(oldp+13289,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__11__KET____DOT__bi__DOT__ThiSig))));
    bufp->fullCData(oldp+13290,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__12__KET____DOT__bi__DOT__ThiSig),2);
    bufp->fullCData(oldp+13291,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__12__KET____DOT__bi__DOT__ForSig),2);
    bufp->fullBit(oldp+13292,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__12__KET____DOT__bi__DOT__FifSig));
    bufp->fullBit(oldp+13293,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__12__KET____DOT__bi__DOT__ForSig) 
                                     >> 1U))));
    bufp->fullBit(oldp+13294,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__12__KET____DOT__bi__DOT__ForSig))));
    bufp->fullBit(oldp+13295,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__12__KET____DOT__bi__DOT__ThiSig) 
                                     >> 1U))));
    bufp->fullBit(oldp+13296,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__12__KET____DOT__bi__DOT__ThiSig))));
    bufp->fullCData(oldp+13297,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__13__KET____DOT__bi__DOT__ThiSig),2);
    bufp->fullCData(oldp+13298,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__13__KET____DOT__bi__DOT__ForSig),2);
    bufp->fullBit(oldp+13299,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__13__KET____DOT__bi__DOT__FifSig));
    bufp->fullBit(oldp+13300,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__13__KET____DOT__bi__DOT__ForSig) 
                                     >> 1U))));
    bufp->fullBit(oldp+13301,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__13__KET____DOT__bi__DOT__ForSig))));
    bufp->fullBit(oldp+13302,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__13__KET____DOT__bi__DOT__ThiSig) 
                                     >> 1U))));
    bufp->fullBit(oldp+13303,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__13__KET____DOT__bi__DOT__ThiSig))));
    bufp->fullCData(oldp+13304,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__14__KET____DOT__bi__DOT__ThiSig),2);
    bufp->fullCData(oldp+13305,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__14__KET____DOT__bi__DOT__ForSig),2);
    bufp->fullBit(oldp+13306,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__14__KET____DOT__bi__DOT__FifSig));
    bufp->fullBit(oldp+13307,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__14__KET____DOT__bi__DOT__ForSig) 
                                     >> 1U))));
    bufp->fullBit(oldp+13308,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__14__KET____DOT__bi__DOT__ForSig))));
    bufp->fullBit(oldp+13309,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__14__KET____DOT__bi__DOT__ThiSig) 
                                     >> 1U))));
    bufp->fullBit(oldp+13310,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__14__KET____DOT__bi__DOT__ThiSig))));
    bufp->fullCData(oldp+13311,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__15__KET____DOT__bi__DOT__ThiSig),2);
    bufp->fullCData(oldp+13312,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__15__KET____DOT__bi__DOT__ForSig),2);
    bufp->fullBit(oldp+13313,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__15__KET____DOT__bi__DOT__FifSig));
    bufp->fullBit(oldp+13314,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__15__KET____DOT__bi__DOT__ForSig) 
                                     >> 1U))));
    bufp->fullBit(oldp+13315,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__15__KET____DOT__bi__DOT__ForSig))));
    bufp->fullBit(oldp+13316,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__15__KET____DOT__bi__DOT__ThiSig) 
                                     >> 1U))));
    bufp->fullBit(oldp+13317,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__15__KET____DOT__bi__DOT__ThiSig))));
    bufp->fullCData(oldp+13318,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__16__KET____DOT__bi__DOT__ThiSig),2);
    bufp->fullCData(oldp+13319,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__16__KET____DOT__bi__DOT__ForSig),2);
    bufp->fullBit(oldp+13320,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__16__KET____DOT__bi__DOT__FifSig));
    bufp->fullBit(oldp+13321,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__16__KET____DOT__bi__DOT__ForSig) 
                                     >> 1U))));
    bufp->fullBit(oldp+13322,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__16__KET____DOT__bi__DOT__ForSig))));
    bufp->fullBit(oldp+13323,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__16__KET____DOT__bi__DOT__ThiSig) 
                                     >> 1U))));
    bufp->fullBit(oldp+13324,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__16__KET____DOT__bi__DOT__ThiSig))));
    bufp->fullCData(oldp+13325,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__17__KET____DOT__bi__DOT__ThiSig),2);
    bufp->fullCData(oldp+13326,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__17__KET____DOT__bi__DOT__ForSig),2);
    bufp->fullBit(oldp+13327,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__17__KET____DOT__bi__DOT__FifSig));
    bufp->fullBit(oldp+13328,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__17__KET____DOT__bi__DOT__ForSig) 
                                     >> 1U))));
    bufp->fullBit(oldp+13329,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__17__KET____DOT__bi__DOT__ForSig))));
    bufp->fullBit(oldp+13330,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__17__KET____DOT__bi__DOT__ThiSig) 
                                     >> 1U))));
    bufp->fullBit(oldp+13331,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__17__KET____DOT__bi__DOT__ThiSig))));
    bufp->fullCData(oldp+13332,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__18__KET____DOT__bi__DOT__ThiSig),2);
    bufp->fullCData(oldp+13333,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__18__KET____DOT__bi__DOT__ForSig),2);
    bufp->fullBit(oldp+13334,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__18__KET____DOT__bi__DOT__FifSig));
    bufp->fullBit(oldp+13335,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__18__KET____DOT__bi__DOT__ForSig) 
                                     >> 1U))));
    bufp->fullBit(oldp+13336,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__18__KET____DOT__bi__DOT__ForSig))));
    bufp->fullBit(oldp+13337,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__18__KET____DOT__bi__DOT__ThiSig) 
                                     >> 1U))));
    bufp->fullBit(oldp+13338,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__18__KET____DOT__bi__DOT__ThiSig))));
    bufp->fullCData(oldp+13339,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__19__KET____DOT__bi__DOT__ThiSig),2);
    bufp->fullCData(oldp+13340,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__19__KET____DOT__bi__DOT__ForSig),2);
    bufp->fullBit(oldp+13341,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__19__KET____DOT__bi__DOT__FifSig));
    bufp->fullBit(oldp+13342,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__19__KET____DOT__bi__DOT__ForSig) 
                                     >> 1U))));
    bufp->fullBit(oldp+13343,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__19__KET____DOT__bi__DOT__ForSig))));
    bufp->fullBit(oldp+13344,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__19__KET____DOT__bi__DOT__ThiSig) 
                                     >> 1U))));
    bufp->fullBit(oldp+13345,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__19__KET____DOT__bi__DOT__ThiSig))));
    bufp->fullCData(oldp+13346,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__1__KET____DOT__bi__DOT__ThiSig),2);
    bufp->fullCData(oldp+13347,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__1__KET____DOT__bi__DOT__ForSig),2);
    bufp->fullBit(oldp+13348,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__1__KET____DOT__bi__DOT__FifSig));
    bufp->fullBit(oldp+13349,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__1__KET____DOT__bi__DOT__ForSig) 
                                     >> 1U))));
    bufp->fullBit(oldp+13350,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__1__KET____DOT__bi__DOT__ForSig))));
    bufp->fullBit(oldp+13351,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__1__KET____DOT__bi__DOT__ThiSig) 
                                     >> 1U))));
    bufp->fullBit(oldp+13352,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__1__KET____DOT__bi__DOT__ThiSig))));
    bufp->fullCData(oldp+13353,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__20__KET____DOT__bi__DOT__ThiSig),2);
    bufp->fullCData(oldp+13354,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__20__KET____DOT__bi__DOT__ForSig),2);
    bufp->fullBit(oldp+13355,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__20__KET____DOT__bi__DOT__FifSig));
    bufp->fullBit(oldp+13356,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__20__KET____DOT__bi__DOT__ForSig) 
                                     >> 1U))));
    bufp->fullBit(oldp+13357,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__20__KET____DOT__bi__DOT__ForSig))));
    bufp->fullBit(oldp+13358,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__20__KET____DOT__bi__DOT__ThiSig) 
                                     >> 1U))));
    bufp->fullBit(oldp+13359,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__20__KET____DOT__bi__DOT__ThiSig))));
    bufp->fullCData(oldp+13360,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__21__KET____DOT__bi__DOT__ThiSig),2);
    bufp->fullCData(oldp+13361,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__21__KET____DOT__bi__DOT__ForSig),2);
    bufp->fullBit(oldp+13362,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__21__KET____DOT__bi__DOT__FifSig));
    bufp->fullBit(oldp+13363,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__21__KET____DOT__bi__DOT__ForSig) 
                                     >> 1U))));
    bufp->fullBit(oldp+13364,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__21__KET____DOT__bi__DOT__ForSig))));
    bufp->fullBit(oldp+13365,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__21__KET____DOT__bi__DOT__ThiSig) 
                                     >> 1U))));
    bufp->fullBit(oldp+13366,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__21__KET____DOT__bi__DOT__ThiSig))));
    bufp->fullCData(oldp+13367,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__22__KET____DOT__bi__DOT__ThiSig),2);
    bufp->fullCData(oldp+13368,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__22__KET____DOT__bi__DOT__ForSig),2);
    bufp->fullBit(oldp+13369,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__22__KET____DOT__bi__DOT__FifSig));
    bufp->fullBit(oldp+13370,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__22__KET____DOT__bi__DOT__ForSig) 
                                     >> 1U))));
    bufp->fullBit(oldp+13371,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__22__KET____DOT__bi__DOT__ForSig))));
    bufp->fullBit(oldp+13372,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__22__KET____DOT__bi__DOT__ThiSig) 
                                     >> 1U))));
    bufp->fullBit(oldp+13373,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__22__KET____DOT__bi__DOT__ThiSig))));
    bufp->fullCData(oldp+13374,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__23__KET____DOT__bi__DOT__ThiSig),2);
    bufp->fullCData(oldp+13375,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__23__KET____DOT__bi__DOT__ForSig),2);
    bufp->fullBit(oldp+13376,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__23__KET____DOT__bi__DOT__FifSig));
    bufp->fullBit(oldp+13377,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__23__KET____DOT__bi__DOT__ForSig) 
                                     >> 1U))));
    bufp->fullBit(oldp+13378,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__23__KET____DOT__bi__DOT__ForSig))));
    bufp->fullBit(oldp+13379,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__23__KET____DOT__bi__DOT__ThiSig) 
                                     >> 1U))));
    bufp->fullBit(oldp+13380,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__23__KET____DOT__bi__DOT__ThiSig))));
    bufp->fullCData(oldp+13381,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__24__KET____DOT__bi__DOT__ThiSig),2);
    bufp->fullCData(oldp+13382,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__24__KET____DOT__bi__DOT__ForSig),2);
    bufp->fullBit(oldp+13383,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__24__KET____DOT__bi__DOT__FifSig));
    bufp->fullBit(oldp+13384,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__24__KET____DOT__bi__DOT__ForSig) 
                                     >> 1U))));
    bufp->fullBit(oldp+13385,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__24__KET____DOT__bi__DOT__ForSig))));
    bufp->fullBit(oldp+13386,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__24__KET____DOT__bi__DOT__ThiSig) 
                                     >> 1U))));
    bufp->fullBit(oldp+13387,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__24__KET____DOT__bi__DOT__ThiSig))));
    bufp->fullCData(oldp+13388,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__25__KET____DOT__bi__DOT__ThiSig),2);
    bufp->fullCData(oldp+13389,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__25__KET____DOT__bi__DOT__ForSig),2);
    bufp->fullBit(oldp+13390,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__25__KET____DOT__bi__DOT__FifSig));
    bufp->fullBit(oldp+13391,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__25__KET____DOT__bi__DOT__ForSig) 
                                     >> 1U))));
    bufp->fullBit(oldp+13392,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__25__KET____DOT__bi__DOT__ForSig))));
    bufp->fullBit(oldp+13393,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__25__KET____DOT__bi__DOT__ThiSig) 
                                     >> 1U))));
    bufp->fullBit(oldp+13394,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__25__KET____DOT__bi__DOT__ThiSig))));
    bufp->fullCData(oldp+13395,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__26__KET____DOT__bi__DOT__ThiSig),2);
    bufp->fullCData(oldp+13396,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__26__KET____DOT__bi__DOT__ForSig),2);
    bufp->fullBit(oldp+13397,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__26__KET____DOT__bi__DOT__FifSig));
    bufp->fullBit(oldp+13398,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__26__KET____DOT__bi__DOT__ForSig) 
                                     >> 1U))));
    bufp->fullBit(oldp+13399,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__26__KET____DOT__bi__DOT__ForSig))));
    bufp->fullBit(oldp+13400,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__26__KET____DOT__bi__DOT__ThiSig) 
                                     >> 1U))));
    bufp->fullBit(oldp+13401,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__26__KET____DOT__bi__DOT__ThiSig))));
    bufp->fullCData(oldp+13402,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__27__KET____DOT__bi__DOT__ThiSig),2);
    bufp->fullCData(oldp+13403,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__27__KET____DOT__bi__DOT__ForSig),2);
    bufp->fullBit(oldp+13404,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__27__KET____DOT__bi__DOT__FifSig));
    bufp->fullBit(oldp+13405,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__27__KET____DOT__bi__DOT__ForSig) 
                                     >> 1U))));
    bufp->fullBit(oldp+13406,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__27__KET____DOT__bi__DOT__ForSig))));
    bufp->fullBit(oldp+13407,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__27__KET____DOT__bi__DOT__ThiSig) 
                                     >> 1U))));
    bufp->fullBit(oldp+13408,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__27__KET____DOT__bi__DOT__ThiSig))));
    bufp->fullCData(oldp+13409,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__28__KET____DOT__bi__DOT__ThiSig),2);
    bufp->fullCData(oldp+13410,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__28__KET____DOT__bi__DOT__ForSig),2);
    bufp->fullBit(oldp+13411,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__28__KET____DOT__bi__DOT__FifSig));
    bufp->fullBit(oldp+13412,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__28__KET____DOT__bi__DOT__ForSig) 
                                     >> 1U))));
    bufp->fullBit(oldp+13413,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__28__KET____DOT__bi__DOT__ForSig))));
    bufp->fullBit(oldp+13414,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__28__KET____DOT__bi__DOT__ThiSig) 
                                     >> 1U))));
    bufp->fullBit(oldp+13415,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__28__KET____DOT__bi__DOT__ThiSig))));
    bufp->fullCData(oldp+13416,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__29__KET____DOT__bi__DOT__ThiSig),2);
    bufp->fullCData(oldp+13417,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__29__KET____DOT__bi__DOT__ForSig),2);
    bufp->fullBit(oldp+13418,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__29__KET____DOT__bi__DOT__FifSig));
    bufp->fullBit(oldp+13419,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__29__KET____DOT__bi__DOT__ForSig) 
                                     >> 1U))));
    bufp->fullBit(oldp+13420,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__29__KET____DOT__bi__DOT__ForSig))));
    bufp->fullBit(oldp+13421,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__29__KET____DOT__bi__DOT__ThiSig) 
                                     >> 1U))));
    bufp->fullBit(oldp+13422,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__29__KET____DOT__bi__DOT__ThiSig))));
    bufp->fullCData(oldp+13423,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__2__KET____DOT__bi__DOT__ThiSig),2);
    bufp->fullCData(oldp+13424,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__2__KET____DOT__bi__DOT__ForSig),2);
    bufp->fullBit(oldp+13425,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__2__KET____DOT__bi__DOT__FifSig));
    bufp->fullBit(oldp+13426,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__2__KET____DOT__bi__DOT__ForSig) 
                                     >> 1U))));
    bufp->fullBit(oldp+13427,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__2__KET____DOT__bi__DOT__ForSig))));
    bufp->fullBit(oldp+13428,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__2__KET____DOT__bi__DOT__ThiSig) 
                                     >> 1U))));
    bufp->fullBit(oldp+13429,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__2__KET____DOT__bi__DOT__ThiSig))));
    bufp->fullCData(oldp+13430,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__30__KET____DOT__bi__DOT__ThiSig),2);
    bufp->fullCData(oldp+13431,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__30__KET____DOT__bi__DOT__ForSig),2);
    bufp->fullBit(oldp+13432,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__30__KET____DOT__bi__DOT__FifSig));
    bufp->fullBit(oldp+13433,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__30__KET____DOT__bi__DOT__ForSig) 
                                     >> 1U))));
    bufp->fullBit(oldp+13434,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__30__KET____DOT__bi__DOT__ForSig))));
    bufp->fullBit(oldp+13435,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__30__KET____DOT__bi__DOT__ThiSig) 
                                     >> 1U))));
    bufp->fullBit(oldp+13436,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__30__KET____DOT__bi__DOT__ThiSig))));
    bufp->fullCData(oldp+13437,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__31__KET____DOT__bi__DOT__ThiSig),2);
    bufp->fullCData(oldp+13438,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__31__KET____DOT__bi__DOT__ForSig),2);
    bufp->fullBit(oldp+13439,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__31__KET____DOT__bi__DOT__FifSig));
    bufp->fullBit(oldp+13440,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__31__KET____DOT__bi__DOT__ForSig) 
                                     >> 1U))));
    bufp->fullBit(oldp+13441,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__31__KET____DOT__bi__DOT__ForSig))));
    bufp->fullBit(oldp+13442,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__31__KET____DOT__bi__DOT__ThiSig) 
                                     >> 1U))));
    bufp->fullBit(oldp+13443,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__31__KET____DOT__bi__DOT__ThiSig))));
    bufp->fullCData(oldp+13444,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__32__KET____DOT__bi__DOT__ThiSig),2);
    bufp->fullCData(oldp+13445,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__32__KET____DOT__bi__DOT__ForSig),2);
    bufp->fullBit(oldp+13446,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__32__KET____DOT__bi__DOT__FifSig));
    bufp->fullBit(oldp+13447,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__32__KET____DOT__bi__DOT__ForSig) 
                                     >> 1U))));
    bufp->fullBit(oldp+13448,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__32__KET____DOT__bi__DOT__ForSig))));
    bufp->fullBit(oldp+13449,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__32__KET____DOT__bi__DOT__ThiSig) 
                                     >> 1U))));
    bufp->fullBit(oldp+13450,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__32__KET____DOT__bi__DOT__ThiSig))));
    bufp->fullCData(oldp+13451,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__33__KET____DOT__bi__DOT__ThiSig),2);
    bufp->fullCData(oldp+13452,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__33__KET____DOT__bi__DOT__ForSig),2);
    bufp->fullBit(oldp+13453,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__33__KET____DOT__bi__DOT__FifSig));
    bufp->fullBit(oldp+13454,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__33__KET____DOT__bi__DOT__ForSig) 
                                     >> 1U))));
    bufp->fullBit(oldp+13455,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__33__KET____DOT__bi__DOT__ForSig))));
    bufp->fullBit(oldp+13456,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__33__KET____DOT__bi__DOT__ThiSig) 
                                     >> 1U))));
    bufp->fullBit(oldp+13457,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__33__KET____DOT__bi__DOT__ThiSig))));
    bufp->fullCData(oldp+13458,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__34__KET____DOT__bi__DOT__ThiSig),2);
    bufp->fullCData(oldp+13459,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__34__KET____DOT__bi__DOT__ForSig),2);
    bufp->fullBit(oldp+13460,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__34__KET____DOT__bi__DOT__FifSig));
    bufp->fullBit(oldp+13461,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__34__KET____DOT__bi__DOT__ForSig) 
                                     >> 1U))));
    bufp->fullBit(oldp+13462,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__34__KET____DOT__bi__DOT__ForSig))));
    bufp->fullBit(oldp+13463,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__34__KET____DOT__bi__DOT__ThiSig) 
                                     >> 1U))));
    bufp->fullBit(oldp+13464,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__34__KET____DOT__bi__DOT__ThiSig))));
    bufp->fullCData(oldp+13465,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__35__KET____DOT__bi__DOT__ThiSig),2);
    bufp->fullCData(oldp+13466,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__35__KET____DOT__bi__DOT__ForSig),2);
    bufp->fullBit(oldp+13467,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__35__KET____DOT__bi__DOT__FifSig));
    bufp->fullBit(oldp+13468,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__35__KET____DOT__bi__DOT__ForSig) 
                                     >> 1U))));
    bufp->fullBit(oldp+13469,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__35__KET____DOT__bi__DOT__ForSig))));
    bufp->fullBit(oldp+13470,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__35__KET____DOT__bi__DOT__ThiSig) 
                                     >> 1U))));
    bufp->fullBit(oldp+13471,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__35__KET____DOT__bi__DOT__ThiSig))));
    bufp->fullCData(oldp+13472,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__36__KET____DOT__bi__DOT__ThiSig),2);
    bufp->fullCData(oldp+13473,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__36__KET____DOT__bi__DOT__ForSig),2);
    bufp->fullBit(oldp+13474,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__36__KET____DOT__bi__DOT__FifSig));
    bufp->fullBit(oldp+13475,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__36__KET____DOT__bi__DOT__ForSig) 
                                     >> 1U))));
    bufp->fullBit(oldp+13476,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__36__KET____DOT__bi__DOT__ForSig))));
    bufp->fullBit(oldp+13477,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__36__KET____DOT__bi__DOT__ThiSig) 
                                     >> 1U))));
    bufp->fullBit(oldp+13478,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__36__KET____DOT__bi__DOT__ThiSig))));
    bufp->fullCData(oldp+13479,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__37__KET____DOT__bi__DOT__ThiSig),2);
    bufp->fullCData(oldp+13480,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__37__KET____DOT__bi__DOT__ForSig),2);
    bufp->fullBit(oldp+13481,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__37__KET____DOT__bi__DOT__FifSig));
    bufp->fullBit(oldp+13482,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__37__KET____DOT__bi__DOT__ForSig) 
                                     >> 1U))));
    bufp->fullBit(oldp+13483,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__37__KET____DOT__bi__DOT__ForSig))));
    bufp->fullBit(oldp+13484,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__37__KET____DOT__bi__DOT__ThiSig) 
                                     >> 1U))));
    bufp->fullBit(oldp+13485,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__37__KET____DOT__bi__DOT__ThiSig))));
    bufp->fullCData(oldp+13486,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__38__KET____DOT__bi__DOT__ThiSig),2);
    bufp->fullCData(oldp+13487,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__38__KET____DOT__bi__DOT__ForSig),2);
    bufp->fullBit(oldp+13488,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__38__KET____DOT__bi__DOT__FifSig));
    bufp->fullBit(oldp+13489,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__38__KET____DOT__bi__DOT__ForSig) 
                                     >> 1U))));
    bufp->fullBit(oldp+13490,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__38__KET____DOT__bi__DOT__ForSig))));
    bufp->fullBit(oldp+13491,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__38__KET____DOT__bi__DOT__ThiSig) 
                                     >> 1U))));
    bufp->fullBit(oldp+13492,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__38__KET____DOT__bi__DOT__ThiSig))));
    bufp->fullCData(oldp+13493,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__39__KET____DOT__bi__DOT__ThiSig),2);
    bufp->fullCData(oldp+13494,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__39__KET____DOT__bi__DOT__ForSig),2);
    bufp->fullBit(oldp+13495,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__39__KET____DOT__bi__DOT__FifSig));
    bufp->fullBit(oldp+13496,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__39__KET____DOT__bi__DOT__ForSig) 
                                     >> 1U))));
    bufp->fullBit(oldp+13497,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__39__KET____DOT__bi__DOT__ForSig))));
    bufp->fullBit(oldp+13498,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__39__KET____DOT__bi__DOT__ThiSig) 
                                     >> 1U))));
    bufp->fullBit(oldp+13499,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__39__KET____DOT__bi__DOT__ThiSig))));
    bufp->fullCData(oldp+13500,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__3__KET____DOT__bi__DOT__ThiSig),2);
    bufp->fullCData(oldp+13501,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__3__KET____DOT__bi__DOT__ForSig),2);
    bufp->fullBit(oldp+13502,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__3__KET____DOT__bi__DOT__FifSig));
    bufp->fullBit(oldp+13503,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__3__KET____DOT__bi__DOT__ForSig) 
                                     >> 1U))));
    bufp->fullBit(oldp+13504,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__3__KET____DOT__bi__DOT__ForSig))));
    bufp->fullBit(oldp+13505,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__3__KET____DOT__bi__DOT__ThiSig) 
                                     >> 1U))));
    bufp->fullBit(oldp+13506,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__3__KET____DOT__bi__DOT__ThiSig))));
    bufp->fullCData(oldp+13507,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__40__KET____DOT__bi__DOT__ThiSig),2);
    bufp->fullCData(oldp+13508,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__40__KET____DOT__bi__DOT__ForSig),2);
    bufp->fullBit(oldp+13509,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__40__KET____DOT__bi__DOT__FifSig));
    bufp->fullBit(oldp+13510,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__40__KET____DOT__bi__DOT__ForSig) 
                                     >> 1U))));
    bufp->fullBit(oldp+13511,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__40__KET____DOT__bi__DOT__ForSig))));
    bufp->fullBit(oldp+13512,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__40__KET____DOT__bi__DOT__ThiSig) 
                                     >> 1U))));
    bufp->fullBit(oldp+13513,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__40__KET____DOT__bi__DOT__ThiSig))));
    bufp->fullCData(oldp+13514,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__41__KET____DOT__bi__DOT__ThiSig),2);
    bufp->fullCData(oldp+13515,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__41__KET____DOT__bi__DOT__ForSig),2);
    bufp->fullBit(oldp+13516,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__41__KET____DOT__bi__DOT__FifSig));
    bufp->fullBit(oldp+13517,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__41__KET____DOT__bi__DOT__ForSig) 
                                     >> 1U))));
    bufp->fullBit(oldp+13518,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__41__KET____DOT__bi__DOT__ForSig))));
    bufp->fullBit(oldp+13519,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__41__KET____DOT__bi__DOT__ThiSig) 
                                     >> 1U))));
    bufp->fullBit(oldp+13520,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__41__KET____DOT__bi__DOT__ThiSig))));
    bufp->fullCData(oldp+13521,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__42__KET____DOT__bi__DOT__ThiSig),2);
    bufp->fullCData(oldp+13522,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__42__KET____DOT__bi__DOT__ForSig),2);
    bufp->fullBit(oldp+13523,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__42__KET____DOT__bi__DOT__FifSig));
    bufp->fullBit(oldp+13524,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__42__KET____DOT__bi__DOT__ForSig) 
                                     >> 1U))));
    bufp->fullBit(oldp+13525,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__42__KET____DOT__bi__DOT__ForSig))));
    bufp->fullBit(oldp+13526,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__42__KET____DOT__bi__DOT__ThiSig) 
                                     >> 1U))));
    bufp->fullBit(oldp+13527,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__42__KET____DOT__bi__DOT__ThiSig))));
    bufp->fullCData(oldp+13528,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__43__KET____DOT__bi__DOT__ThiSig),2);
    bufp->fullCData(oldp+13529,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__43__KET____DOT__bi__DOT__ForSig),2);
    bufp->fullBit(oldp+13530,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__43__KET____DOT__bi__DOT__FifSig));
    bufp->fullBit(oldp+13531,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__43__KET____DOT__bi__DOT__ForSig) 
                                     >> 1U))));
    bufp->fullBit(oldp+13532,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__43__KET____DOT__bi__DOT__ForSig))));
    bufp->fullBit(oldp+13533,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__43__KET____DOT__bi__DOT__ThiSig) 
                                     >> 1U))));
    bufp->fullBit(oldp+13534,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__43__KET____DOT__bi__DOT__ThiSig))));
    bufp->fullCData(oldp+13535,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__44__KET____DOT__bi__DOT__ThiSig),2);
    bufp->fullCData(oldp+13536,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__44__KET____DOT__bi__DOT__ForSig),2);
    bufp->fullBit(oldp+13537,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__44__KET____DOT__bi__DOT__FifSig));
    bufp->fullBit(oldp+13538,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__44__KET____DOT__bi__DOT__ForSig) 
                                     >> 1U))));
    bufp->fullBit(oldp+13539,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__44__KET____DOT__bi__DOT__ForSig))));
    bufp->fullBit(oldp+13540,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__44__KET____DOT__bi__DOT__ThiSig) 
                                     >> 1U))));
    bufp->fullBit(oldp+13541,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__44__KET____DOT__bi__DOT__ThiSig))));
    bufp->fullCData(oldp+13542,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__45__KET____DOT__bi__DOT__ThiSig),2);
    bufp->fullCData(oldp+13543,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__45__KET____DOT__bi__DOT__ForSig),2);
    bufp->fullBit(oldp+13544,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__45__KET____DOT__bi__DOT__FifSig));
    bufp->fullBit(oldp+13545,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__45__KET____DOT__bi__DOT__ForSig) 
                                     >> 1U))));
    bufp->fullBit(oldp+13546,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__45__KET____DOT__bi__DOT__ForSig))));
    bufp->fullBit(oldp+13547,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__45__KET____DOT__bi__DOT__ThiSig) 
                                     >> 1U))));
    bufp->fullBit(oldp+13548,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__45__KET____DOT__bi__DOT__ThiSig))));
    bufp->fullCData(oldp+13549,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__46__KET____DOT__bi__DOT__ThiSig),2);
    bufp->fullCData(oldp+13550,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__46__KET____DOT__bi__DOT__ForSig),2);
    bufp->fullBit(oldp+13551,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__46__KET____DOT__bi__DOT__FifSig));
    bufp->fullBit(oldp+13552,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__46__KET____DOT__bi__DOT__ForSig) 
                                     >> 1U))));
    bufp->fullBit(oldp+13553,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__46__KET____DOT__bi__DOT__ForSig))));
    bufp->fullBit(oldp+13554,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__46__KET____DOT__bi__DOT__ThiSig) 
                                     >> 1U))));
    bufp->fullBit(oldp+13555,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__46__KET____DOT__bi__DOT__ThiSig))));
    bufp->fullCData(oldp+13556,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__47__KET____DOT__bi__DOT__ThiSig),2);
    bufp->fullCData(oldp+13557,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__47__KET____DOT__bi__DOT__ForSig),2);
    bufp->fullBit(oldp+13558,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__47__KET____DOT__bi__DOT__FifSig));
    bufp->fullBit(oldp+13559,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__47__KET____DOT__bi__DOT__ForSig) 
                                     >> 1U))));
    bufp->fullBit(oldp+13560,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__47__KET____DOT__bi__DOT__ForSig))));
    bufp->fullBit(oldp+13561,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__47__KET____DOT__bi__DOT__ThiSig) 
                                     >> 1U))));
    bufp->fullBit(oldp+13562,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__47__KET____DOT__bi__DOT__ThiSig))));
    bufp->fullCData(oldp+13563,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__48__KET____DOT__bi__DOT__ThiSig),2);
    bufp->fullCData(oldp+13564,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__48__KET____DOT__bi__DOT__ForSig),2);
    bufp->fullBit(oldp+13565,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__48__KET____DOT__bi__DOT__FifSig));
    bufp->fullBit(oldp+13566,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__48__KET____DOT__bi__DOT__ForSig) 
                                     >> 1U))));
    bufp->fullBit(oldp+13567,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__48__KET____DOT__bi__DOT__ForSig))));
    bufp->fullBit(oldp+13568,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__48__KET____DOT__bi__DOT__ThiSig) 
                                     >> 1U))));
    bufp->fullBit(oldp+13569,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__48__KET____DOT__bi__DOT__ThiSig))));
    bufp->fullCData(oldp+13570,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__49__KET____DOT__bi__DOT__ThiSig),2);
    bufp->fullCData(oldp+13571,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__49__KET____DOT__bi__DOT__ForSig),2);
    bufp->fullBit(oldp+13572,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__49__KET____DOT__bi__DOT__FifSig));
    bufp->fullBit(oldp+13573,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__49__KET____DOT__bi__DOT__ForSig) 
                                     >> 1U))));
    bufp->fullBit(oldp+13574,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__49__KET____DOT__bi__DOT__ForSig))));
    bufp->fullBit(oldp+13575,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__49__KET____DOT__bi__DOT__ThiSig) 
                                     >> 1U))));
    bufp->fullBit(oldp+13576,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__49__KET____DOT__bi__DOT__ThiSig))));
    bufp->fullCData(oldp+13577,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__4__KET____DOT__bi__DOT__ThiSig),2);
    bufp->fullCData(oldp+13578,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__4__KET____DOT__bi__DOT__ForSig),2);
    bufp->fullBit(oldp+13579,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__4__KET____DOT__bi__DOT__FifSig));
    bufp->fullBit(oldp+13580,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__4__KET____DOT__bi__DOT__ForSig) 
                                     >> 1U))));
    bufp->fullBit(oldp+13581,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__4__KET____DOT__bi__DOT__ForSig))));
    bufp->fullBit(oldp+13582,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__4__KET____DOT__bi__DOT__ThiSig) 
                                     >> 1U))));
    bufp->fullBit(oldp+13583,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__4__KET____DOT__bi__DOT__ThiSig))));
    bufp->fullCData(oldp+13584,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__50__KET____DOT__bi__DOT__ThiSig),2);
    bufp->fullCData(oldp+13585,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__50__KET____DOT__bi__DOT__ForSig),2);
    bufp->fullBit(oldp+13586,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__50__KET____DOT__bi__DOT__FifSig));
    bufp->fullBit(oldp+13587,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__50__KET____DOT__bi__DOT__ForSig) 
                                     >> 1U))));
    bufp->fullBit(oldp+13588,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__50__KET____DOT__bi__DOT__ForSig))));
    bufp->fullBit(oldp+13589,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__50__KET____DOT__bi__DOT__ThiSig) 
                                     >> 1U))));
    bufp->fullBit(oldp+13590,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__50__KET____DOT__bi__DOT__ThiSig))));
    bufp->fullCData(oldp+13591,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__51__KET____DOT__bi__DOT__ThiSig),2);
    bufp->fullCData(oldp+13592,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__51__KET____DOT__bi__DOT__ForSig),2);
    bufp->fullBit(oldp+13593,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__51__KET____DOT__bi__DOT__FifSig));
    bufp->fullBit(oldp+13594,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__51__KET____DOT__bi__DOT__ForSig) 
                                     >> 1U))));
    bufp->fullBit(oldp+13595,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__51__KET____DOT__bi__DOT__ForSig))));
    bufp->fullBit(oldp+13596,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__51__KET____DOT__bi__DOT__ThiSig) 
                                     >> 1U))));
    bufp->fullBit(oldp+13597,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__51__KET____DOT__bi__DOT__ThiSig))));
    bufp->fullCData(oldp+13598,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__52__KET____DOT__bi__DOT__ThiSig),2);
    bufp->fullCData(oldp+13599,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__52__KET____DOT__bi__DOT__ForSig),2);
    bufp->fullBit(oldp+13600,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__52__KET____DOT__bi__DOT__FifSig));
    bufp->fullBit(oldp+13601,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__52__KET____DOT__bi__DOT__ForSig) 
                                     >> 1U))));
    bufp->fullBit(oldp+13602,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__52__KET____DOT__bi__DOT__ForSig))));
    bufp->fullBit(oldp+13603,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__52__KET____DOT__bi__DOT__ThiSig) 
                                     >> 1U))));
    bufp->fullBit(oldp+13604,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__52__KET____DOT__bi__DOT__ThiSig))));
    bufp->fullCData(oldp+13605,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__53__KET____DOT__bi__DOT__ThiSig),2);
    bufp->fullCData(oldp+13606,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__53__KET____DOT__bi__DOT__ForSig),2);
    bufp->fullBit(oldp+13607,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__53__KET____DOT__bi__DOT__FifSig));
    bufp->fullBit(oldp+13608,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__53__KET____DOT__bi__DOT__ForSig) 
                                     >> 1U))));
    bufp->fullBit(oldp+13609,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__53__KET____DOT__bi__DOT__ForSig))));
    bufp->fullBit(oldp+13610,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__53__KET____DOT__bi__DOT__ThiSig) 
                                     >> 1U))));
    bufp->fullBit(oldp+13611,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__53__KET____DOT__bi__DOT__ThiSig))));
    bufp->fullCData(oldp+13612,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__54__KET____DOT__bi__DOT__ThiSig),2);
    bufp->fullCData(oldp+13613,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__54__KET____DOT__bi__DOT__ForSig),2);
    bufp->fullBit(oldp+13614,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__54__KET____DOT__bi__DOT__FifSig));
    bufp->fullBit(oldp+13615,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__54__KET____DOT__bi__DOT__ForSig) 
                                     >> 1U))));
    bufp->fullBit(oldp+13616,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__54__KET____DOT__bi__DOT__ForSig))));
    bufp->fullBit(oldp+13617,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__54__KET____DOT__bi__DOT__ThiSig) 
                                     >> 1U))));
    bufp->fullBit(oldp+13618,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__54__KET____DOT__bi__DOT__ThiSig))));
    bufp->fullCData(oldp+13619,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__55__KET____DOT__bi__DOT__ThiSig),2);
    bufp->fullCData(oldp+13620,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__55__KET____DOT__bi__DOT__ForSig),2);
    bufp->fullBit(oldp+13621,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__55__KET____DOT__bi__DOT__FifSig));
    bufp->fullBit(oldp+13622,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__55__KET____DOT__bi__DOT__ForSig) 
                                     >> 1U))));
    bufp->fullBit(oldp+13623,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__55__KET____DOT__bi__DOT__ForSig))));
    bufp->fullBit(oldp+13624,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__55__KET____DOT__bi__DOT__ThiSig) 
                                     >> 1U))));
    bufp->fullBit(oldp+13625,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__55__KET____DOT__bi__DOT__ThiSig))));
    bufp->fullCData(oldp+13626,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__56__KET____DOT__bi__DOT__ThiSig),2);
    bufp->fullCData(oldp+13627,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__56__KET____DOT__bi__DOT__ForSig),2);
    bufp->fullBit(oldp+13628,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__56__KET____DOT__bi__DOT__FifSig));
    bufp->fullBit(oldp+13629,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__56__KET____DOT__bi__DOT__ForSig) 
                                     >> 1U))));
    bufp->fullBit(oldp+13630,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__56__KET____DOT__bi__DOT__ForSig))));
    bufp->fullBit(oldp+13631,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__56__KET____DOT__bi__DOT__ThiSig) 
                                     >> 1U))));
    bufp->fullBit(oldp+13632,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__56__KET____DOT__bi__DOT__ThiSig))));
    bufp->fullCData(oldp+13633,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__57__KET____DOT__bi__DOT__ThiSig),2);
    bufp->fullCData(oldp+13634,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__57__KET____DOT__bi__DOT__ForSig),2);
    bufp->fullBit(oldp+13635,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__57__KET____DOT__bi__DOT__FifSig));
    bufp->fullBit(oldp+13636,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__57__KET____DOT__bi__DOT__ForSig) 
                                     >> 1U))));
    bufp->fullBit(oldp+13637,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__57__KET____DOT__bi__DOT__ForSig))));
    bufp->fullBit(oldp+13638,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__57__KET____DOT__bi__DOT__ThiSig) 
                                     >> 1U))));
    bufp->fullBit(oldp+13639,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__57__KET____DOT__bi__DOT__ThiSig))));
    bufp->fullCData(oldp+13640,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__58__KET____DOT__bi__DOT__ThiSig),2);
    bufp->fullCData(oldp+13641,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__58__KET____DOT__bi__DOT__ForSig),2);
    bufp->fullBit(oldp+13642,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__58__KET____DOT__bi__DOT__FifSig));
    bufp->fullBit(oldp+13643,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__58__KET____DOT__bi__DOT__ForSig) 
                                     >> 1U))));
    bufp->fullBit(oldp+13644,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__58__KET____DOT__bi__DOT__ForSig))));
    bufp->fullBit(oldp+13645,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__58__KET____DOT__bi__DOT__ThiSig) 
                                     >> 1U))));
    bufp->fullBit(oldp+13646,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__58__KET____DOT__bi__DOT__ThiSig))));
    bufp->fullCData(oldp+13647,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__59__KET____DOT__bi__DOT__ThiSig),2);
    bufp->fullCData(oldp+13648,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__59__KET____DOT__bi__DOT__ForSig),2);
    bufp->fullBit(oldp+13649,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__59__KET____DOT__bi__DOT__FifSig));
    bufp->fullBit(oldp+13650,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__59__KET____DOT__bi__DOT__ForSig) 
                                     >> 1U))));
    bufp->fullBit(oldp+13651,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__59__KET____DOT__bi__DOT__ForSig))));
    bufp->fullBit(oldp+13652,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__59__KET____DOT__bi__DOT__ThiSig) 
                                     >> 1U))));
    bufp->fullBit(oldp+13653,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__59__KET____DOT__bi__DOT__ThiSig))));
    bufp->fullCData(oldp+13654,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__5__KET____DOT__bi__DOT__ThiSig),2);
    bufp->fullCData(oldp+13655,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__5__KET____DOT__bi__DOT__ForSig),2);
    bufp->fullBit(oldp+13656,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__5__KET____DOT__bi__DOT__FifSig));
    bufp->fullBit(oldp+13657,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__5__KET____DOT__bi__DOT__ForSig) 
                                     >> 1U))));
    bufp->fullBit(oldp+13658,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__5__KET____DOT__bi__DOT__ForSig))));
    bufp->fullBit(oldp+13659,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__5__KET____DOT__bi__DOT__ThiSig) 
                                     >> 1U))));
    bufp->fullBit(oldp+13660,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__5__KET____DOT__bi__DOT__ThiSig))));
    bufp->fullCData(oldp+13661,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__60__KET____DOT__bi__DOT__ThiSig),2);
    bufp->fullCData(oldp+13662,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__60__KET____DOT__bi__DOT__ForSig),2);
    bufp->fullBit(oldp+13663,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__60__KET____DOT__bi__DOT__FifSig));
    bufp->fullBit(oldp+13664,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__60__KET____DOT__bi__DOT__ForSig) 
                                     >> 1U))));
    bufp->fullBit(oldp+13665,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__60__KET____DOT__bi__DOT__ForSig))));
    bufp->fullBit(oldp+13666,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__60__KET____DOT__bi__DOT__ThiSig) 
                                     >> 1U))));
    bufp->fullBit(oldp+13667,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__60__KET____DOT__bi__DOT__ThiSig))));
    bufp->fullCData(oldp+13668,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__61__KET____DOT__bi__DOT__ThiSig),2);
    bufp->fullCData(oldp+13669,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__61__KET____DOT__bi__DOT__ForSig),2);
    bufp->fullBit(oldp+13670,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__61__KET____DOT__bi__DOT__FifSig));
    bufp->fullBit(oldp+13671,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__61__KET____DOT__bi__DOT__ForSig) 
                                     >> 1U))));
    bufp->fullBit(oldp+13672,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__61__KET____DOT__bi__DOT__ForSig))));
    bufp->fullBit(oldp+13673,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__61__KET____DOT__bi__DOT__ThiSig) 
                                     >> 1U))));
    bufp->fullBit(oldp+13674,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__61__KET____DOT__bi__DOT__ThiSig))));
    bufp->fullCData(oldp+13675,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__62__KET____DOT__bi__DOT__ThiSig),2);
    bufp->fullCData(oldp+13676,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__62__KET____DOT__bi__DOT__ForSig),2);
    bufp->fullBit(oldp+13677,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__62__KET____DOT__bi__DOT__FifSig));
    bufp->fullBit(oldp+13678,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__62__KET____DOT__bi__DOT__ForSig) 
                                     >> 1U))));
    bufp->fullBit(oldp+13679,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__62__KET____DOT__bi__DOT__ForSig))));
    bufp->fullBit(oldp+13680,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__62__KET____DOT__bi__DOT__ThiSig) 
                                     >> 1U))));
    bufp->fullBit(oldp+13681,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__62__KET____DOT__bi__DOT__ThiSig))));
    bufp->fullCData(oldp+13682,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__63__KET____DOT__bi__DOT__ThiSig),2);
    bufp->fullCData(oldp+13683,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__63__KET____DOT__bi__DOT__ForSig),2);
    bufp->fullBit(oldp+13684,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__63__KET____DOT__bi__DOT__FifSig));
    bufp->fullBit(oldp+13685,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__63__KET____DOT__bi__DOT__ForSig) 
                                     >> 1U))));
    bufp->fullBit(oldp+13686,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__63__KET____DOT__bi__DOT__ForSig))));
    bufp->fullBit(oldp+13687,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__63__KET____DOT__bi__DOT__ThiSig) 
                                     >> 1U))));
    bufp->fullBit(oldp+13688,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__63__KET____DOT__bi__DOT__ThiSig))));
    bufp->fullCData(oldp+13689,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__6__KET____DOT__bi__DOT__ThiSig),2);
    bufp->fullCData(oldp+13690,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__6__KET____DOT__bi__DOT__ForSig),2);
    bufp->fullBit(oldp+13691,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__6__KET____DOT__bi__DOT__FifSig));
    bufp->fullBit(oldp+13692,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__6__KET____DOT__bi__DOT__ForSig) 
                                     >> 1U))));
    bufp->fullBit(oldp+13693,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__6__KET____DOT__bi__DOT__ForSig))));
    bufp->fullBit(oldp+13694,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__6__KET____DOT__bi__DOT__ThiSig) 
                                     >> 1U))));
    bufp->fullBit(oldp+13695,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__6__KET____DOT__bi__DOT__ThiSig))));
    bufp->fullCData(oldp+13696,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__7__KET____DOT__bi__DOT__ThiSig),2);
    bufp->fullCData(oldp+13697,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__7__KET____DOT__bi__DOT__ForSig),2);
    bufp->fullBit(oldp+13698,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__7__KET____DOT__bi__DOT__FifSig));
    bufp->fullBit(oldp+13699,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__7__KET____DOT__bi__DOT__ForSig) 
                                     >> 1U))));
    bufp->fullBit(oldp+13700,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__7__KET____DOT__bi__DOT__ForSig))));
    bufp->fullBit(oldp+13701,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__7__KET____DOT__bi__DOT__ThiSig) 
                                     >> 1U))));
    bufp->fullBit(oldp+13702,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__7__KET____DOT__bi__DOT__ThiSig))));
    bufp->fullCData(oldp+13703,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__8__KET____DOT__bi__DOT__ThiSig),2);
    bufp->fullCData(oldp+13704,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__8__KET____DOT__bi__DOT__ForSig),2);
    bufp->fullBit(oldp+13705,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__8__KET____DOT__bi__DOT__FifSig));
    bufp->fullBit(oldp+13706,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__8__KET____DOT__bi__DOT__ForSig) 
                                     >> 1U))));
    bufp->fullBit(oldp+13707,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__8__KET____DOT__bi__DOT__ForSig))));
    bufp->fullBit(oldp+13708,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__8__KET____DOT__bi__DOT__ThiSig) 
                                     >> 1U))));
    bufp->fullBit(oldp+13709,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__8__KET____DOT__bi__DOT__ThiSig))));
    bufp->fullCData(oldp+13710,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__9__KET____DOT__bi__DOT__ThiSig),2);
    bufp->fullCData(oldp+13711,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__9__KET____DOT__bi__DOT__ForSig),2);
    bufp->fullBit(oldp+13712,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__9__KET____DOT__bi__DOT__FifSig));
    bufp->fullBit(oldp+13713,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__9__KET____DOT__bi__DOT__ForSig) 
                                     >> 1U))));
    bufp->fullBit(oldp+13714,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__9__KET____DOT__bi__DOT__ForSig))));
    bufp->fullBit(oldp+13715,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__9__KET____DOT__bi__DOT__ThiSig) 
                                     >> 1U))));
    bufp->fullBit(oldp+13716,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__wallacefor__BRA__9__KET____DOT__bi__DOT__ThiSig))));
    bufp->fullBit(oldp+13717,(vlSelf->simu_top__DOT__soc__DOT__sram_axi_ram__DOT__ram_r_a_data_push));
    bufp->fullBit(oldp+13718,(vlSelf->simu_top__DOT__soc__DOT__sram_axi_ram__DOT__ram_r_a_pop));
    bufp->fullBit(oldp+13719,(vlSelf->simu_top__DOT__soc__DOT__sram_axi_ram__DOT__ram_r_a_push));
    bufp->fullBit(oldp+13720,(vlSelf->simu_top__DOT__soc__DOT__sram_axi_ram__DOT__ram_r_a_queue_push));
    bufp->fullBit(oldp+13721,(vlSelf->simu_top__DOT__soc__DOT__sram_axi_ram__DOT__ram_r_en));
    bufp->fullBit(oldp+13722,(vlSelf->simu_top__DOT__soc__DOT__sram_axi_ram__DOT__ram_w_a_data_push));
    bufp->fullBit(oldp+13723,(vlSelf->simu_top__DOT__soc__DOT__sram_axi_ram__DOT__ram_w_a_pop));
    bufp->fullBit(oldp+13724,(vlSelf->simu_top__DOT__soc__DOT__sram_axi_ram__DOT__ram_w_a_push));
    bufp->fullBit(oldp+13725,(vlSelf->simu_top__DOT__soc__DOT__sram_axi_ram__DOT__ram_w_a_queue_push));
    bufp->fullBit(oldp+13726,(vlSelf->simu_top__DOT__soc__DOT__sram_axi_ram__DOT__ram_w_b_pop));
    bufp->fullBit(oldp+13727,(vlSelf->simu_top__DOT__soc__DOT__sram_axi_ram__DOT__ram_w_b_queue_push));
    bufp->fullBit(oldp+13728,(vlSelf->simu_top__DOT__soc__DOT__sram_axi_ram__DOT__ram_w_en));
    bufp->fullBit(oldp+13729,(vlSelf->simu_top__DOT__soc__DOT__sram_axi_ram__DOT__ram_w_go));
    bufp->fullBit(oldp+13730,(vlSelf->aclk));
    bufp->fullBit(oldp+13731,(vlSelf->aresetn));
    bufp->fullBit(oldp+13732,(vlSelf->enable_delay));
    bufp->fullIData(oldp+13733,(vlSelf->random_seed),23);
    bufp->fullBit(oldp+13734,(vlSelf->ram_ren));
    bufp->fullIData(oldp+13735,(vlSelf->ram_raddr),32);
    bufp->fullIData(oldp+13736,(vlSelf->ram_rdata),32);
    bufp->fullCData(oldp+13737,(vlSelf->ram_wen),4);
    bufp->fullIData(oldp+13738,(vlSelf->ram_waddr),32);
    bufp->fullIData(oldp+13739,(vlSelf->ram_wdata),32);
    bufp->fullIData(oldp+13740,(vlSelf->debug0_wb_pc),32);
    bufp->fullBit(oldp+13741,(vlSelf->debug0_wb_rf_wen));
    bufp->fullCData(oldp+13742,(vlSelf->debug0_wb_rf_wnum),5);
    bufp->fullIData(oldp+13743,(vlSelf->debug0_wb_rf_wdata),32);
    bufp->fullIData(oldp+13744,(vlSelf->num_data),32);
    bufp->fullBit(oldp+13745,(vlSelf->open_trace));
    bufp->fullBit(oldp+13746,(vlSelf->num_monitor));
    bufp->fullCData(oldp+13747,(vlSelf->confreg_uart_data),8);
    bufp->fullBit(oldp+13748,(vlSelf->write_uart_valid));
    bufp->fullWData(oldp+13749,(vlSelf->uart_ctr_bus),128);
    bufp->fullBit(oldp+13753,(vlSelf->uart_rx));
    bufp->fullBit(oldp+13754,(vlSelf->uart_tx));
    bufp->fullSData(oldp+13755,(vlSelf->led),16);
    bufp->fullCData(oldp+13756,(vlSelf->led_rg0),2);
    bufp->fullCData(oldp+13757,(vlSelf->led_rg1),2);
    bufp->fullCData(oldp+13758,(vlSelf->num_csn),8);
    bufp->fullCData(oldp+13759,(vlSelf->num_a_g),7);
    bufp->fullCData(oldp+13760,(vlSelf->btn_key_col),4);
    bufp->fullCData(oldp+13761,(vlSelf->btn_key_row),4);
    bufp->fullCData(oldp+13762,(vlSelf->btn_step),2);
    bufp->fullCData(oldp+13763,(vlSelf->__SYM__switch),8);
    bufp->fullBit(oldp+13764,(((IData)(vlSelf->simu_top__DOT__soc__DOT__m0_awready) 
                               & ((IData)(vlSelf->simu_top__DOT__soc__DOT__delay__DOT__mask_aw) 
                                  | (~ (IData)(vlSelf->enable_delay))))));
    bufp->fullBit(oldp+13765,(((IData)(vlSelf->simu_top__DOT__soc__DOT__m0_wready) 
                               & ((IData)(vlSelf->simu_top__DOT__soc__DOT__delay__DOT__mask_w) 
                                  | (~ (IData)(vlSelf->enable_delay))))));
    bufp->fullBit(oldp+13766,((1U & (~ (IData)(vlSelf->aresetn)))));
    bufp->fullBit(oldp+13767,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__APB_DEV__DOT__uart0__DOT__isomode)
                                      ? ((~ (IData)(vlSelf->simu_top__DOT__soc__DOT__APB_DEV__DOT__uart0__DOT__rx_en)) 
                                         | (IData)(vlSelf->uart_tx))
                                      : (IData)(vlSelf->uart_rx)))));
    bufp->fullBit(oldp+13768,((1U & ((~ (IData)(vlSelf->aresetn)) 
                                     | (IData)(vlSelf->simu_top__DOT__soc__DOT__conf_axi_ram__DOT__ram_r_a_pop)))));
    bufp->fullIData(oldp+13769,(vlSelf->__SYM__switch),32);
    bufp->fullIData(oldp+13770,(((0x8000U & ((IData)(vlSelf->__SYM__switch) 
                                             << 8U)) 
                                 | ((0x2000U & ((IData)(vlSelf->__SYM__switch) 
                                                << 7U)) 
                                    | ((0x800U & ((IData)(vlSelf->__SYM__switch) 
                                                  << 6U)) 
                                       | ((0x200U & 
                                           ((IData)(vlSelf->__SYM__switch) 
                                            << 5U)) 
                                          | ((0x80U 
                                              & ((IData)(vlSelf->__SYM__switch) 
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
    bufp->fullBit(oldp+13771,(((0U == (IData)(vlSelf->simu_top__DOT__soc__DOT__confreg__DOT__state)) 
                               & (~ (IData)((0xfU == (IData)(vlSelf->btn_key_row)))))));
    bufp->fullBit(oldp+13772,(((7U == (IData)(vlSelf->simu_top__DOT__soc__DOT__confreg__DOT__state)) 
                               & (0xfU == (IData)(vlSelf->btn_key_row)))));
    bufp->fullBit(oldp+13773,(((IData)(vlSelf->simu_top__DOT__soc__DOT__confreg__DOT__btn_step0_r) 
                               & (~ (IData)(vlSelf->btn_step)))));
    bufp->fullBit(oldp+13774,((1U & ((~ (IData)(vlSelf->simu_top__DOT__soc__DOT__confreg__DOT__btn_step0_r)) 
                                     & (IData)(vlSelf->btn_step)))));
    bufp->fullBit(oldp+13775,(((IData)(vlSelf->simu_top__DOT__soc__DOT__confreg__DOT__btn_step1_r) 
                               & (~ ((IData)(vlSelf->btn_step) 
                                     >> 1U)))));
    bufp->fullBit(oldp+13776,(((~ (IData)(vlSelf->simu_top__DOT__soc__DOT__confreg__DOT__btn_step1_r)) 
                               & ((IData)(vlSelf->btn_step) 
                                  >> 1U))));
    bufp->fullBit(oldp+13777,((1U & ((~ (IData)(vlSelf->aresetn)) 
                                     | (IData)(vlSelf->simu_top__DOT__soc__DOT__sram_axi_ram__DOT__ram_r_a_pop)))));
    bufp->fullIData(oldp+13778,(0x20U),32);
    bufp->fullCData(oldp+13779,(1U),4);
    bufp->fullCData(oldp+13780,(1U),2);
    bufp->fullCData(oldp+13781,(0U),2);
    bufp->fullCData(oldp+13782,(0U),4);
    bufp->fullCData(oldp+13783,(0U),3);
    bufp->fullBit(oldp+13784,(0U));
    bufp->fullBit(oldp+13785,(vlSelf->simu_top__DOT__soc__DOT__UART_RI));
    bufp->fullIData(oldp+13786,(0x14U),32);
    bufp->fullIData(oldp+13787,(8U),32);
    bufp->fullIData(oldp+13788,(0x40U),32);
    bufp->fullIData(oldp+13789,(0x80U),32);
    bufp->fullIData(oldp+13790,(0x10U),32);
    bufp->fullBit(oldp+13791,(vlSelf->simu_top__DOT__soc__DOT__APB_DEV__DOT__apb_rw_dma));
    bufp->fullBit(oldp+13792,(vlSelf->simu_top__DOT__soc__DOT__APB_DEV__DOT__apb_psel_dma));
    bufp->fullBit(oldp+13793,(vlSelf->simu_top__DOT__soc__DOT__APB_DEV__DOT__apb_enab_dma));
    bufp->fullIData(oldp+13794,(vlSelf->simu_top__DOT__soc__DOT__APB_DEV__DOT__apb_addr_dma),20);
    bufp->fullIData(oldp+13795,(vlSelf->simu_top__DOT__soc__DOT__APB_DEV__DOT__apb_wdata_dma),32);
    bufp->fullBit(oldp+13796,(vlSelf->simu_top__DOT__soc__DOT__APB_DEV__DOT__apb_valid_dma));
    bufp->fullBit(oldp+13797,(vlSelf->simu_top__DOT__soc__DOT__APB_DEV__DOT__dma_ack_i));
    bufp->fullCData(oldp+13798,(0U),8);
    bufp->fullBit(oldp+13799,(vlSelf->simu_top__DOT__soc__DOT__APB_DEV__DOT__apb_clk_dma));
    bufp->fullBit(oldp+13800,(vlSelf->simu_top__DOT__soc__DOT__APB_DEV__DOT__apb_reset_n_dma));
    bufp->fullCData(oldp+13801,(2U),4);
    bufp->fullCData(oldp+13802,(8U),4);
    bufp->fullCData(oldp+13803,(0U),5);
    bufp->fullCData(oldp+13804,(1U),5);
    bufp->fullCData(oldp+13805,(2U),5);
    bufp->fullCData(oldp+13806,(0xaU),5);
    bufp->fullCData(oldp+13807,(3U),5);
    bufp->fullCData(oldp+13808,(4U),5);
    bufp->fullCData(oldp+13809,(6U),5);
    bufp->fullCData(oldp+13810,(7U),5);
    bufp->fullCData(oldp+13811,(0x10U),5);
    bufp->fullCData(oldp+13812,(0x11U),5);
    bufp->fullCData(oldp+13813,(0x12U),5);
    bufp->fullCData(oldp+13814,(0x13U),5);
    bufp->fullCData(oldp+13815,(0x14U),5);
    bufp->fullCData(oldp+13816,(0x15U),5);
    bufp->fullCData(oldp+13817,(0x16U),5);
    bufp->fullCData(oldp+13818,(0x17U),5);
    bufp->fullCData(oldp+13819,(0x18U),5);
    bufp->fullCData(oldp+13820,(0x19U),5);
    bufp->fullCData(oldp+13821,(0x1aU),5);
    bufp->fullCData(oldp+13822,(0x1bU),5);
    bufp->fullCData(oldp+13823,(((IData)(vlSelf->simu_top__DOT__soc__DOT__UART_RI) 
                                 << 1U)),4);
    bufp->fullBit(oldp+13824,(0U));
    bufp->fullBit(oldp+13825,(0U));
    bufp->fullBit(oldp+13826,((1U & (IData)(vlSelf->simu_top__DOT__soc__DOT__UART_RI))));
    bufp->fullBit(oldp+13827,((1U & ((IData)(vlSelf->simu_top__DOT__soc__DOT__UART_RI) 
                                     << 1U))));
    bufp->fullBit(oldp+13828,(1U));
    bufp->fullBit(oldp+13829,(1U));
    bufp->fullBit(oldp+13830,((1U & (~ (0x7fffffffU 
                                        & (IData)(vlSelf->simu_top__DOT__soc__DOT__UART_RI))))));
    bufp->fullBit(oldp+13831,((1U & (~ ((IData)(vlSelf->simu_top__DOT__soc__DOT__UART_RI) 
                                        << 1U)))));
    bufp->fullBit(oldp+13832,(1U));
    bufp->fullIData(oldp+13833,(1U),32);
    bufp->fullBit(oldp+13834,(1U));
    bufp->fullCData(oldp+13835,(3U),4);
    bufp->fullCData(oldp+13836,(4U),4);
    bufp->fullCData(oldp+13837,(5U),4);
    bufp->fullCData(oldp+13838,(6U),4);
    bufp->fullCData(oldp+13839,(7U),4);
    bufp->fullCData(oldp+13840,(9U),4);
    bufp->fullCData(oldp+13841,(0xaU),4);
    bufp->fullIData(oldp+13842,(0xbU),32);
    bufp->fullIData(oldp+13843,(4U),32);
    bufp->fullIData(oldp+13844,(5U),32);
    bufp->fullCData(oldp+13845,(1U),3);
    bufp->fullCData(oldp+13846,(2U),3);
    bufp->fullCData(oldp+13847,(3U),3);
    bufp->fullCData(oldp+13848,(4U),3);
    bufp->fullCData(oldp+13849,(5U),3);
    bufp->fullCData(oldp+13850,(6U),3);
    bufp->fullCData(oldp+13851,(vlSelf->simu_top__DOT__soc__DOT__AXI_SLAVE_MUX__DOT__s1_bid),4);
    bufp->fullCData(oldp+13852,(vlSelf->simu_top__DOT__soc__DOT__AXI_SLAVE_MUX__DOT__s1_bresp),2);
    bufp->fullCData(oldp+13853,(vlSelf->simu_top__DOT__soc__DOT__AXI_SLAVE_MUX__DOT__s1_rid),4);
    bufp->fullIData(oldp+13854,(vlSelf->simu_top__DOT__soc__DOT__AXI_SLAVE_MUX__DOT__s1_rdata),32);
    bufp->fullCData(oldp+13855,(vlSelf->simu_top__DOT__soc__DOT__AXI_SLAVE_MUX__DOT__s1_rresp),2);
    bufp->fullBit(oldp+13856,(vlSelf->simu_top__DOT__soc__DOT__AXI_SLAVE_MUX__DOT__s1_rlast));
    bufp->fullCData(oldp+13857,(vlSelf->simu_top__DOT__soc__DOT__AXI_SLAVE_MUX__DOT__s4_bid),4);
    bufp->fullCData(oldp+13858,(vlSelf->simu_top__DOT__soc__DOT__AXI_SLAVE_MUX__DOT__s4_bresp),2);
    bufp->fullCData(oldp+13859,(vlSelf->simu_top__DOT__soc__DOT__AXI_SLAVE_MUX__DOT__s4_rid),4);
    bufp->fullIData(oldp+13860,(vlSelf->simu_top__DOT__soc__DOT__AXI_SLAVE_MUX__DOT__s4_rdata),32);
    bufp->fullCData(oldp+13861,(vlSelf->simu_top__DOT__soc__DOT__AXI_SLAVE_MUX__DOT__s4_rresp),2);
    bufp->fullBit(oldp+13862,(vlSelf->simu_top__DOT__soc__DOT__AXI_SLAVE_MUX__DOT__s4_rlast));
    bufp->fullCData(oldp+13863,(vlSelf->simu_top__DOT__soc__DOT__AXI_SLAVE_MUX__DOT__BASE_ADDR[0]),5);
    bufp->fullCData(oldp+13864,(vlSelf->simu_top__DOT__soc__DOT__AXI_SLAVE_MUX__DOT__BASE_ADDR[1]),5);
    bufp->fullCData(oldp+13865,(vlSelf->simu_top__DOT__soc__DOT__AXI_SLAVE_MUX__DOT__BASE_ADDR[2]),5);
    bufp->fullCData(oldp+13866,(vlSelf->simu_top__DOT__soc__DOT__AXI_SLAVE_MUX__DOT__BASE_ADDR[3]),5);
    bufp->fullCData(oldp+13867,(vlSelf->simu_top__DOT__soc__DOT__AXI_SLAVE_MUX__DOT__BASE_ADDR[4]),5);
    bufp->fullCData(oldp+13868,(vlSelf->simu_top__DOT__soc__DOT__AXI_SLAVE_MUX__DOT__rd_sel_group_0),3);
    bufp->fullCData(oldp+13869,(vlSelf->simu_top__DOT__soc__DOT__AXI_SLAVE_MUX__DOT__rd_sel_group_1),3);
    bufp->fullIData(oldp+13870,(5U),32);
    bufp->fullIData(oldp+13871,(vlSelf->simu_top__DOT__soc__DOT__AXI_SLAVE_MUX__DOT__rd_addr_hit_int),32);
    bufp->fullIData(oldp+13872,(3U),32);
    bufp->fullIData(oldp+13873,(2U),32);
    bufp->fullBit(oldp+13874,(0U));
    bufp->fullBit(oldp+13875,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__dcache_unbusy));
    bufp->fullIData(oldp+13876,(0U),32);
    bufp->fullCData(oldp+13877,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__inst_wr_type),3);
    bufp->fullIData(oldp+13878,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__inst_wr_addr),32);
    bufp->fullCData(oldp+13879,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__inst_wr_wstrb),4);
    bufp->fullWData(oldp+13880,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__inst_wr_data),128);
    bufp->fullQData(oldp+13884,(0ULL),64);
    bufp->fullCData(oldp+13886,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__btb__DOT__btb_random_index),5);
    bufp->fullCData(oldp+13887,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__btb__DOT__ras_random_index),4);
    bufp->fullBit(oldp+13888,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__dcache__DOT__preld_st_en));
    bufp->fullBit(oldp+13889,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__dcache__DOT__preld_ld_en));
    bufp->fullBit(oldp+13890,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__dcache__DOT__preld_ld_st_en));
    bufp->fullBit(oldp+13891,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__dcache__DOT__lookup_way0_hit_buffer));
    bufp->fullBit(oldp+13892,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__dcache__DOT__lookup_way1_hit_buffer));
    bufp->fullCData(oldp+13893,(8U),5);
    bufp->fullIData(oldp+13894,(0x100U),32);
    bufp->fullIData(oldp+13895,(0x15U),32);
    bufp->fullBit(oldp+13896,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__id_stage__DOT__br_jirl));
    bufp->fullSData(oldp+13897,(0U),14);
    bufp->fullSData(oldp+13898,(1U),14);
    bufp->fullSData(oldp+13899,(4U),14);
    bufp->fullSData(oldp+13900,(5U),14);
    bufp->fullSData(oldp+13901,(6U),14);
    bufp->fullSData(oldp+13902,(7U),14);
    bufp->fullSData(oldp+13903,(0xcU),14);
    bufp->fullSData(oldp+13904,(0x10U),14);
    bufp->fullSData(oldp+13905,(0x11U),14);
    bufp->fullSData(oldp+13906,(0x12U),14);
    bufp->fullSData(oldp+13907,(0x13U),14);
    bufp->fullSData(oldp+13908,(0x18U),14);
    bufp->fullSData(oldp+13909,(0x19U),14);
    bufp->fullSData(oldp+13910,(0x1aU),14);
    bufp->fullSData(oldp+13911,(0x1bU),14);
    bufp->fullSData(oldp+13912,(0x20U),14);
    bufp->fullSData(oldp+13913,(0x30U),14);
    bufp->fullSData(oldp+13914,(0x31U),14);
    bufp->fullSData(oldp+13915,(0x32U),14);
    bufp->fullSData(oldp+13916,(0x33U),14);
    bufp->fullSData(oldp+13917,(0x40U),14);
    bufp->fullSData(oldp+13918,(0x41U),14);
    bufp->fullSData(oldp+13919,(0x42U),14);
    bufp->fullSData(oldp+13920,(0x43U),14);
    bufp->fullSData(oldp+13921,(0x44U),14);
    bufp->fullSData(oldp+13922,(0x60U),14);
    bufp->fullSData(oldp+13923,(0x88U),14);
    bufp->fullSData(oldp+13924,(0x180U),14);
    bufp->fullSData(oldp+13925,(0x181U),14);
    bufp->fullSData(oldp+13926,(0x100U),14);
    bufp->fullSData(oldp+13927,(0x101U),14);
}
