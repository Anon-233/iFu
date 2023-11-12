// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_fst_c.h"
#include "Vsimu_top__Syms.h"


VL_ATTR_COLD void Vsimu_top___024root__trace_full_sub_2(Vsimu_top___024root* vlSelf, VerilatedFst::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vsimu_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsimu_top___024root__trace_full_sub_2\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullBit(oldp+4857,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__22__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x7fffffffffe000ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 0xdU))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__22__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x7fffffffffe000ULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 0xdU))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__22__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__22__KET____DOT__ai__DOT__CarrySig
                                     [9U] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__22__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__22__KET____DOT__ai__DOT__CarrySig
                                 [9U]))));
    bufp->fullBit(oldp+4858,((1U & (IData)((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalY 
                                            >> 0x17U)))));
    bufp->fullBit(oldp+4859,((1U & (IData)((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalY 
                                            >> 0x16U)))));
    bufp->fullCData(oldp+4860,((7U & (IData)((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalY 
                                              >> 0x17U)))),3);
    bufp->fullQData(oldp+4861,((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                << 0x18U)),64);
    bufp->fullQData(oldp+4863,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellout__boothfor__BRA__24__KET____DOT__ai__OutX),64);
    bufp->fullBit(oldp+4865,(((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__negx) 
                              | (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__neg2x))));
    bufp->fullBit(oldp+4866,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__negx));
    bufp->fullBit(oldp+4867,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__x));
    bufp->fullBit(oldp+4868,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__neg2x));
    bufp->fullBit(oldp+4869,((1U & (IData)((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                            << 0x18U)))));
    bufp->fullBit(oldp+4870,((1U & (~ (IData)((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               << 0x18U))))));
    bufp->fullBit(oldp+4871,(((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__negx) 
                                & (~ (IData)((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                              << 0x18U)))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__x) 
                                  & (IData)((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                             << 0x18U)))) 
                              | (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__neg2x))));
    bufp->fullBit(oldp+4872,((1U & (IData)((0x3fffffffffc000ULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               << 0xeU))))));
    bufp->fullBit(oldp+4873,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                              [0xaU])));
    bufp->fullBit(oldp+4874,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                                    [0xaU] >> 1U))));
    bufp->fullBit(oldp+4875,((1U & (~ (IData)((0x3fffffffffc000ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 0xeU)))))));
    bufp->fullBit(oldp+4876,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x3fffffffffc000ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 0xeU))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x3fffffffffc000ULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 0xeU))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                                     [0xaU] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                                 [0xaU]))));
    bufp->fullBit(oldp+4877,((1U & (IData)((0x1fffffffffe000ULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               << 0xdU))))));
    bufp->fullBit(oldp+4878,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                              [0xbU])));
    bufp->fullBit(oldp+4879,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                                    [0xbU] >> 1U))));
    bufp->fullBit(oldp+4880,((1U & (~ (IData)((0x1fffffffffe000ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 0xdU)))))));
    bufp->fullBit(oldp+4881,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x1fffffffffe000ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 0xdU))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x1fffffffffe000ULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 0xdU))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                                     [0xbU] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                                 [0xbU]))));
    bufp->fullBit(oldp+4882,((1U & (IData)((0xffffffffff000ULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               << 0xcU))))));
    bufp->fullBit(oldp+4883,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                              [0xcU])));
    bufp->fullBit(oldp+4884,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                                    [0xcU] >> 1U))));
    bufp->fullBit(oldp+4885,((1U & (~ (IData)((0xffffffffff000ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 0xcU)))))));
    bufp->fullBit(oldp+4886,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0xffffffffff000ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 0xcU))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__x) 
                                   & (IData)((0xffffffffff000ULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 0xcU))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                                     [0xcU] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                                 [0xcU]))));
    bufp->fullBit(oldp+4887,((1U & (IData)((0x7fffffffff800ULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               << 0xbU))))));
    bufp->fullBit(oldp+4888,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                              [0xdU])));
    bufp->fullBit(oldp+4889,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                                    [0xdU] >> 1U))));
    bufp->fullBit(oldp+4890,((1U & (~ (IData)((0x7fffffffff800ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 0xbU)))))));
    bufp->fullBit(oldp+4891,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x7fffffffff800ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 0xbU))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x7fffffffff800ULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 0xbU))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                                     [0xdU] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                                 [0xdU]))));
    bufp->fullBit(oldp+4892,((1U & (IData)((0x3fffffffffc00ULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               << 0xaU))))));
    bufp->fullBit(oldp+4893,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                              [0xeU])));
    bufp->fullBit(oldp+4894,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                                    [0xeU] >> 1U))));
    bufp->fullBit(oldp+4895,((1U & (~ (IData)((0x3fffffffffc00ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 0xaU)))))));
    bufp->fullBit(oldp+4896,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x3fffffffffc00ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 0xaU))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x3fffffffffc00ULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 0xaU))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                                     [0xeU] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                                 [0xeU]))));
    bufp->fullBit(oldp+4897,((1U & (IData)((0x1fffffffffe00ULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               << 9U))))));
    bufp->fullBit(oldp+4898,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                              [0xfU])));
    bufp->fullBit(oldp+4899,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                                    [0xfU] >> 1U))));
    bufp->fullBit(oldp+4900,((1U & (~ (IData)((0x1fffffffffe00ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 9U)))))));
    bufp->fullBit(oldp+4901,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x1fffffffffe00ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 9U))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x1fffffffffe00ULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 9U))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                                     [0xfU] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                                 [0xfU]))));
    bufp->fullBit(oldp+4902,((1U & (IData)((0xffffffffff00ULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               << 8U))))));
    bufp->fullBit(oldp+4903,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                              [0x10U])));
    bufp->fullBit(oldp+4904,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                                    [0x10U] >> 1U))));
    bufp->fullBit(oldp+4905,((1U & (~ (IData)((0xffffffffff00ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 8U)))))));
    bufp->fullBit(oldp+4906,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0xffffffffff00ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 8U))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__x) 
                                   & (IData)((0xffffffffff00ULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 8U))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                                     [0x10U] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                                 [0x10U]))));
    bufp->fullBit(oldp+4907,((1U & (IData)((0x7fffffffff80ULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               << 7U))))));
    bufp->fullBit(oldp+4908,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                              [0x11U])));
    bufp->fullBit(oldp+4909,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                                    [0x11U] >> 1U))));
    bufp->fullBit(oldp+4910,((1U & (~ (IData)((0x7fffffffff80ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 7U)))))));
    bufp->fullBit(oldp+4911,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x7fffffffff80ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 7U))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x7fffffffff80ULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 7U))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                                     [0x11U] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                                 [0x11U]))));
    bufp->fullBit(oldp+4912,((1U & (IData)((0x3fffffffffc0ULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               << 6U))))));
    bufp->fullBit(oldp+4913,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                              [0x12U])));
    bufp->fullBit(oldp+4914,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                                    [0x12U] >> 1U))));
    bufp->fullBit(oldp+4915,((1U & (~ (IData)((0x3fffffffffc0ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 6U)))))));
    bufp->fullBit(oldp+4916,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x3fffffffffc0ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 6U))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x3fffffffffc0ULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 6U))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                                     [0x12U] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                                 [0x12U]))));
    bufp->fullBit(oldp+4917,((1U & (IData)((0x1fffffffffe0ULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               << 5U))))));
    bufp->fullBit(oldp+4918,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                              [0x13U])));
    bufp->fullBit(oldp+4919,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                                    [0x13U] >> 1U))));
    bufp->fullBit(oldp+4920,((1U & (~ (IData)((0x1fffffffffe0ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 5U)))))));
    bufp->fullBit(oldp+4921,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x1fffffffffe0ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 5U))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x1fffffffffe0ULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 5U))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                                     [0x13U] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                                 [0x13U]))));
    bufp->fullBit(oldp+4922,((1U & (IData)((0x7fffffffff800000ULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               << 0x17U))))));
    bufp->fullBit(oldp+4923,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                              [1U])));
    bufp->fullBit(oldp+4924,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                                    [1U] >> 1U))));
    bufp->fullBit(oldp+4925,((1U & (~ (IData)((0x7fffffffff800000ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 0x17U)))))));
    bufp->fullBit(oldp+4926,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x7fffffffff800000ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 0x17U))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x7fffffffff800000ULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 0x17U))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                                     [1U] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                                 [1U]))));
    bufp->fullBit(oldp+4927,((1U & (IData)((0xffffffffff0ULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               << 4U))))));
    bufp->fullBit(oldp+4928,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                              [0x14U])));
    bufp->fullBit(oldp+4929,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                                    [0x14U] >> 1U))));
    bufp->fullBit(oldp+4930,((1U & (~ (IData)((0xffffffffff0ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 4U)))))));
    bufp->fullBit(oldp+4931,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0xffffffffff0ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 4U))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__x) 
                                   & (IData)((0xffffffffff0ULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 4U))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                                     [0x14U] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                                 [0x14U]))));
    bufp->fullBit(oldp+4932,((1U & (IData)((0x7fffffffff8ULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               << 3U))))));
    bufp->fullBit(oldp+4933,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                              [0x15U])));
    bufp->fullBit(oldp+4934,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                                    [0x15U] >> 1U))));
    bufp->fullBit(oldp+4935,((1U & (~ (IData)((0x7fffffffff8ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 3U)))))));
    bufp->fullBit(oldp+4936,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x7fffffffff8ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 3U))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x7fffffffff8ULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 3U))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                                     [0x15U] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                                 [0x15U]))));
    bufp->fullBit(oldp+4937,((1U & (IData)((0x3fffffffffcULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               << 2U))))));
    bufp->fullBit(oldp+4938,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                              [0x16U])));
    bufp->fullBit(oldp+4939,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                                    [0x16U] >> 1U))));
    bufp->fullBit(oldp+4940,((1U & (~ (IData)((0x3fffffffffcULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 2U)))))));
    bufp->fullBit(oldp+4941,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x3fffffffffcULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 2U))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x3fffffffffcULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 2U))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                                     [0x16U] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                                 [0x16U]))));
    bufp->fullBit(oldp+4942,((1U & (IData)((0x1fffffffffeULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               << 1U))))));
    bufp->fullBit(oldp+4943,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                              [0x17U])));
    bufp->fullBit(oldp+4944,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                                    [0x17U] >> 1U))));
    bufp->fullBit(oldp+4945,((1U & (~ (IData)((0x1fffffffffeULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 1U)))))));
    bufp->fullBit(oldp+4946,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x1fffffffffeULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 1U))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x1fffffffffeULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 1U))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                                     [0x17U] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                                 [0x17U]))));
    bufp->fullBit(oldp+4947,((1U & (IData)((0xffffffffffULL 
                                            & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX)))));
    bufp->fullBit(oldp+4948,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                              [0x18U])));
    bufp->fullBit(oldp+4949,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                                    [0x18U] >> 1U))));
    bufp->fullBit(oldp+4950,((1U & (~ (IData)((0xffffffffffULL 
                                               & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX))))));
    bufp->fullBit(oldp+4951,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0xffffffffffULL 
                                               & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX)))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__x) 
                                   & (IData)((0xffffffffffULL 
                                              & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX)))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                                     [0x18U] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                                 [0x18U]))));
    bufp->fullBit(oldp+4952,((1U & (IData)((0x7fffffffffULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               >> 1U))))));
    bufp->fullBit(oldp+4953,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                              [0x19U])));
    bufp->fullBit(oldp+4954,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                                    [0x19U] >> 1U))));
    bufp->fullBit(oldp+4955,((1U & (~ (IData)((0x7fffffffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 1U)))))));
    bufp->fullBit(oldp+4956,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x7fffffffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 1U))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x7fffffffffULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 1U))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                                     [0x19U] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                                 [0x19U]))));
    bufp->fullBit(oldp+4957,((1U & (IData)((0x3fffffffffULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               >> 2U))))));
    bufp->fullBit(oldp+4958,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                              [0x1aU])));
    bufp->fullBit(oldp+4959,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                                    [0x1aU] >> 1U))));
    bufp->fullBit(oldp+4960,((1U & (~ (IData)((0x3fffffffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 2U)))))));
    bufp->fullBit(oldp+4961,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x3fffffffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 2U))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x3fffffffffULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 2U))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                                     [0x1aU] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                                 [0x1aU]))));
    bufp->fullBit(oldp+4962,((1U & (IData)((0x1fffffffffULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               >> 3U))))));
    bufp->fullBit(oldp+4963,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                              [0x1bU])));
    bufp->fullBit(oldp+4964,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                                    [0x1bU] >> 1U))));
    bufp->fullBit(oldp+4965,((1U & (~ (IData)((0x1fffffffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 3U)))))));
    bufp->fullBit(oldp+4966,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x1fffffffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 3U))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x1fffffffffULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 3U))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                                     [0x1bU] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                                 [0x1bU]))));
    bufp->fullBit(oldp+4967,((1U & (IData)((0xfffffffffULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               >> 4U))))));
    bufp->fullBit(oldp+4968,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                              [0x1cU])));
    bufp->fullBit(oldp+4969,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                                    [0x1cU] >> 1U))));
    bufp->fullBit(oldp+4970,((1U & (~ (IData)((0xfffffffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 4U)))))));
    bufp->fullBit(oldp+4971,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0xfffffffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 4U))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__x) 
                                   & (IData)((0xfffffffffULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 4U))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                                     [0x1cU] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                                 [0x1cU]))));
    bufp->fullBit(oldp+4972,((1U & (IData)((0x7ffffffffULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               >> 5U))))));
    bufp->fullBit(oldp+4973,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                              [0x1dU])));
    bufp->fullBit(oldp+4974,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                                    [0x1dU] >> 1U))));
    bufp->fullBit(oldp+4975,((1U & (~ (IData)((0x7ffffffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 5U)))))));
    bufp->fullBit(oldp+4976,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x7ffffffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 5U))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x7ffffffffULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 5U))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                                     [0x1dU] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                                 [0x1dU]))));
    bufp->fullBit(oldp+4977,((1U & (IData)((0x3fffffffffc00000ULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               << 0x16U))))));
    bufp->fullBit(oldp+4978,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                              [2U])));
    bufp->fullBit(oldp+4979,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                                    [2U] >> 1U))));
    bufp->fullBit(oldp+4980,((1U & (~ (IData)((0x3fffffffffc00000ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 0x16U)))))));
    bufp->fullBit(oldp+4981,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x3fffffffffc00000ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 0x16U))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x3fffffffffc00000ULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 0x16U))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                                     [2U] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                                 [2U]))));
    bufp->fullBit(oldp+4982,((1U & (IData)((0x3ffffffffULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               >> 6U))))));
    bufp->fullBit(oldp+4983,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                              [0x1eU])));
    bufp->fullBit(oldp+4984,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                                    [0x1eU] >> 1U))));
    bufp->fullBit(oldp+4985,((1U & (~ (IData)((0x3ffffffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 6U)))))));
    bufp->fullBit(oldp+4986,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x3ffffffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 6U))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x3ffffffffULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 6U))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                                     [0x1eU] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                                 [0x1eU]))));
    bufp->fullBit(oldp+4987,((1U & (IData)((0x1ffffffffULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               >> 7U))))));
    bufp->fullBit(oldp+4988,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                              [0x1fU])));
    bufp->fullBit(oldp+4989,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                                    [0x1fU] >> 1U))));
    bufp->fullBit(oldp+4990,((1U & (~ (IData)((0x1ffffffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 7U)))))));
    bufp->fullBit(oldp+4991,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x1ffffffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 7U))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x1ffffffffULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 7U))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                                     [0x1fU] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                                 [0x1fU]))));
    bufp->fullBit(oldp+4992,((1U & (IData)((0xffffffffULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               >> 8U))))));
    bufp->fullBit(oldp+4993,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                              [0x20U])));
    bufp->fullBit(oldp+4994,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                                    [0x20U] >> 1U))));
    bufp->fullBit(oldp+4995,((1U & (~ (IData)((0xffffffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 8U)))))));
    bufp->fullBit(oldp+4996,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0xffffffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 8U))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__x) 
                                   & (IData)((0xffffffffULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 8U))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                                     [0x20U] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                                 [0x20U]))));
    bufp->fullBit(oldp+4997,((1U & (IData)((0x7fffffffULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               >> 9U))))));
    bufp->fullBit(oldp+4998,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                              [0x21U])));
    bufp->fullBit(oldp+4999,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                                    [0x21U] >> 1U))));
    bufp->fullBit(oldp+5000,((1U & (~ (IData)((0x7fffffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 9U)))))));
    bufp->fullBit(oldp+5001,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x7fffffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 9U))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x7fffffffULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 9U))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                                     [0x21U] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                                 [0x21U]))));
    bufp->fullBit(oldp+5002,((1U & (IData)((0x3fffffffULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               >> 0xaU))))));
    bufp->fullBit(oldp+5003,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                              [0x22U])));
    bufp->fullBit(oldp+5004,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                                    [0x22U] >> 1U))));
    bufp->fullBit(oldp+5005,((1U & (~ (IData)((0x3fffffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0xaU)))))));
    bufp->fullBit(oldp+5006,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x3fffffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0xaU))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x3fffffffULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0xaU))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                                     [0x22U] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                                 [0x22U]))));
    bufp->fullBit(oldp+5007,((1U & (IData)((0x1fffffffULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               >> 0xbU))))));
    bufp->fullBit(oldp+5008,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                              [0x23U])));
    bufp->fullBit(oldp+5009,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                                    [0x23U] >> 1U))));
    bufp->fullBit(oldp+5010,((1U & (~ (IData)((0x1fffffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0xbU)))))));
    bufp->fullBit(oldp+5011,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x1fffffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0xbU))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x1fffffffULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0xbU))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                                     [0x23U] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                                 [0x23U]))));
    bufp->fullBit(oldp+5012,((1U & (IData)((0xfffffffULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               >> 0xcU))))));
    bufp->fullBit(oldp+5013,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                              [0x24U])));
    bufp->fullBit(oldp+5014,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                                    [0x24U] >> 1U))));
    bufp->fullBit(oldp+5015,((1U & (~ (IData)((0xfffffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0xcU)))))));
    bufp->fullBit(oldp+5016,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0xfffffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0xcU))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__x) 
                                   & (IData)((0xfffffffULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0xcU))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                                     [0x24U] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                                 [0x24U]))));
    bufp->fullBit(oldp+5017,((1U & (IData)((0x7ffffffULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               >> 0xdU))))));
    bufp->fullBit(oldp+5018,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                              [0x25U])));
    bufp->fullBit(oldp+5019,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                                    [0x25U] >> 1U))));
    bufp->fullBit(oldp+5020,((1U & (~ (IData)((0x7ffffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0xdU)))))));
    bufp->fullBit(oldp+5021,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x7ffffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0xdU))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x7ffffffULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0xdU))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                                     [0x25U] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                                 [0x25U]))));
    bufp->fullBit(oldp+5022,((1U & (IData)((0x3ffffffULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               >> 0xeU))))));
    bufp->fullBit(oldp+5023,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                              [0x26U])));
    bufp->fullBit(oldp+5024,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                                    [0x26U] >> 1U))));
    bufp->fullBit(oldp+5025,((1U & (~ (IData)((0x3ffffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0xeU)))))));
    bufp->fullBit(oldp+5026,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x3ffffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0xeU))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x3ffffffULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0xeU))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                                     [0x26U] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                                 [0x26U]))));
    bufp->fullBit(oldp+5027,((1U & (IData)((0x1ffffffULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               >> 0xfU))))));
    bufp->fullBit(oldp+5028,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                              [0x27U])));
    bufp->fullBit(oldp+5029,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                                    [0x27U] >> 1U))));
    bufp->fullBit(oldp+5030,((1U & (~ (IData)((0x1ffffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0xfU)))))));
    bufp->fullBit(oldp+5031,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x1ffffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0xfU))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x1ffffffULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0xfU))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                                     [0x27U] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                                 [0x27U]))));
    bufp->fullBit(oldp+5032,((1U & (IData)((0x1fffffffffe00000ULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               << 0x15U))))));
    bufp->fullBit(oldp+5033,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                              [3U])));
    bufp->fullBit(oldp+5034,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                                    [3U] >> 1U))));
    bufp->fullBit(oldp+5035,((1U & (~ (IData)((0x1fffffffffe00000ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 0x15U)))))));
    bufp->fullBit(oldp+5036,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x1fffffffffe00000ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 0x15U))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x1fffffffffe00000ULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 0x15U))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                                     [3U] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                                 [3U]))));
    bufp->fullBit(oldp+5037,((1U & (IData)((0xffffffULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               >> 0x10U))))));
    bufp->fullBit(oldp+5038,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                              [0x28U])));
    bufp->fullBit(oldp+5039,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                                    [0x28U] >> 1U))));
    bufp->fullBit(oldp+5040,((1U & (~ (IData)((0xffffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x10U)))))));
    bufp->fullBit(oldp+5041,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0xffffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x10U))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__x) 
                                   & (IData)((0xffffffULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x10U))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                                     [0x28U] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                                 [0x28U]))));
    bufp->fullBit(oldp+5042,((1U & (IData)((0x7fffffULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               >> 0x11U))))));
    bufp->fullBit(oldp+5043,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                              [0x29U])));
    bufp->fullBit(oldp+5044,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                                    [0x29U] >> 1U))));
    bufp->fullBit(oldp+5045,((1U & (~ (IData)((0x7fffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x11U)))))));
    bufp->fullBit(oldp+5046,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x7fffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x11U))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x7fffffULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x11U))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                                     [0x29U] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                                 [0x29U]))));
    bufp->fullBit(oldp+5047,((1U & (IData)((0x3fffffULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               >> 0x12U))))));
    bufp->fullBit(oldp+5048,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                              [0x2aU])));
    bufp->fullBit(oldp+5049,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                                    [0x2aU] >> 1U))));
    bufp->fullBit(oldp+5050,((1U & (~ (IData)((0x3fffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x12U)))))));
    bufp->fullBit(oldp+5051,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x3fffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x12U))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x3fffffULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x12U))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                                     [0x2aU] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                                 [0x2aU]))));
    bufp->fullBit(oldp+5052,((1U & (IData)((0x1fffffULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               >> 0x13U))))));
    bufp->fullBit(oldp+5053,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                              [0x2bU])));
    bufp->fullBit(oldp+5054,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                                    [0x2bU] >> 1U))));
    bufp->fullBit(oldp+5055,((1U & (~ (IData)((0x1fffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x13U)))))));
    bufp->fullBit(oldp+5056,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x1fffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x13U))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x1fffffULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x13U))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                                     [0x2bU] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                                 [0x2bU]))));
    bufp->fullBit(oldp+5057,((1U & (IData)((0xfffffULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               >> 0x14U))))));
    bufp->fullBit(oldp+5058,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                              [0x2cU])));
    bufp->fullBit(oldp+5059,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                                    [0x2cU] >> 1U))));
    bufp->fullBit(oldp+5060,((1U & (~ (IData)((0xfffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x14U)))))));
    bufp->fullBit(oldp+5061,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0xfffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x14U))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__x) 
                                   & (IData)((0xfffffULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x14U))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                                     [0x2cU] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                                 [0x2cU]))));
    bufp->fullBit(oldp+5062,((1U & (IData)((0x7ffffULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               >> 0x15U))))));
    bufp->fullBit(oldp+5063,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                              [0x2dU])));
    bufp->fullBit(oldp+5064,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                                    [0x2dU] >> 1U))));
    bufp->fullBit(oldp+5065,((1U & (~ (IData)((0x7ffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x15U)))))));
    bufp->fullBit(oldp+5066,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x7ffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x15U))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x7ffffULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x15U))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                                     [0x2dU] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                                 [0x2dU]))));
    bufp->fullBit(oldp+5067,((1U & (IData)((0x3ffffULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               >> 0x16U))))));
    bufp->fullBit(oldp+5068,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                              [0x2eU])));
    bufp->fullBit(oldp+5069,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                                    [0x2eU] >> 1U))));
    bufp->fullBit(oldp+5070,((1U & (~ (IData)((0x3ffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x16U)))))));
    bufp->fullBit(oldp+5071,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x3ffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x16U))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x3ffffULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x16U))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                                     [0x2eU] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                                 [0x2eU]))));
    bufp->fullBit(oldp+5072,((1U & (IData)((0x1ffffULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               >> 0x17U))))));
    bufp->fullBit(oldp+5073,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                              [0x2fU])));
    bufp->fullBit(oldp+5074,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                                    [0x2fU] >> 1U))));
    bufp->fullBit(oldp+5075,((1U & (~ (IData)((0x1ffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x17U)))))));
    bufp->fullBit(oldp+5076,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x1ffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x17U))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x1ffffULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x17U))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                                     [0x2fU] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                                 [0x2fU]))));
    bufp->fullBit(oldp+5077,((1U & (IData)((0xffffULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               >> 0x18U))))));
    bufp->fullBit(oldp+5078,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                              [0x30U])));
    bufp->fullBit(oldp+5079,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                                    [0x30U] >> 1U))));
    bufp->fullBit(oldp+5080,((1U & (~ (IData)((0xffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x18U)))))));
    bufp->fullBit(oldp+5081,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0xffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x18U))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__x) 
                                   & (IData)((0xffffULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x18U))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                                     [0x30U] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                                 [0x30U]))));
    bufp->fullBit(oldp+5082,((1U & (IData)((0x7fffULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               >> 0x19U))))));
    bufp->fullBit(oldp+5083,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                              [0x31U])));
    bufp->fullBit(oldp+5084,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                                    [0x31U] >> 1U))));
    bufp->fullBit(oldp+5085,((1U & (~ (IData)((0x7fffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x19U)))))));
    bufp->fullBit(oldp+5086,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x7fffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x19U))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x7fffULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x19U))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                                     [0x31U] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                                 [0x31U]))));
    bufp->fullBit(oldp+5087,((1U & (IData)((0xffffffffff00000ULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               << 0x14U))))));
    bufp->fullBit(oldp+5088,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                              [4U])));
    bufp->fullBit(oldp+5089,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                                    [4U] >> 1U))));
    bufp->fullBit(oldp+5090,((1U & (~ (IData)((0xffffffffff00000ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 0x14U)))))));
    bufp->fullBit(oldp+5091,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0xffffffffff00000ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 0x14U))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__x) 
                                   & (IData)((0xffffffffff00000ULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 0x14U))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                                     [4U] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                                 [4U]))));
    bufp->fullBit(oldp+5092,((1U & (IData)((0x3fffULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               >> 0x1aU))))));
    bufp->fullBit(oldp+5093,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                              [0x32U])));
    bufp->fullBit(oldp+5094,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                                    [0x32U] >> 1U))));
    bufp->fullBit(oldp+5095,((1U & (~ (IData)((0x3fffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x1aU)))))));
    bufp->fullBit(oldp+5096,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x3fffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x1aU))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x3fffULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x1aU))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                                     [0x32U] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                                 [0x32U]))));
    bufp->fullBit(oldp+5097,((1U & (IData)((0x1fffULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               >> 0x1bU))))));
    bufp->fullBit(oldp+5098,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                              [0x33U])));
    bufp->fullBit(oldp+5099,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                                    [0x33U] >> 1U))));
    bufp->fullBit(oldp+5100,((1U & (~ (IData)((0x1fffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x1bU)))))));
    bufp->fullBit(oldp+5101,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x1fffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x1bU))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x1fffULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x1bU))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                                     [0x33U] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                                 [0x33U]))));
    bufp->fullBit(oldp+5102,((1U & (IData)((0xfffULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               >> 0x1cU))))));
    bufp->fullBit(oldp+5103,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                              [0x34U])));
    bufp->fullBit(oldp+5104,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                                    [0x34U] >> 1U))));
    bufp->fullBit(oldp+5105,((1U & (~ (IData)((0xfffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x1cU)))))));
    bufp->fullBit(oldp+5106,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0xfffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x1cU))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__x) 
                                   & (IData)((0xfffULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x1cU))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                                     [0x34U] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                                 [0x34U]))));
    bufp->fullBit(oldp+5107,((1U & (IData)((0x7ffULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               >> 0x1dU))))));
    bufp->fullBit(oldp+5108,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                              [0x35U])));
    bufp->fullBit(oldp+5109,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                                    [0x35U] >> 1U))));
    bufp->fullBit(oldp+5110,((1U & (~ (IData)((0x7ffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x1dU)))))));
    bufp->fullBit(oldp+5111,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x7ffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x1dU))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x7ffULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x1dU))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                                     [0x35U] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                                 [0x35U]))));
    bufp->fullBit(oldp+5112,((1U & (IData)((0x3ffULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               >> 0x1eU))))));
    bufp->fullBit(oldp+5113,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                              [0x36U])));
    bufp->fullBit(oldp+5114,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                                    [0x36U] >> 1U))));
    bufp->fullBit(oldp+5115,((1U & (~ (IData)((0x3ffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x1eU)))))));
    bufp->fullBit(oldp+5116,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x3ffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x1eU))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x3ffULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x1eU))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                                     [0x36U] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                                 [0x36U]))));
    bufp->fullBit(oldp+5117,((1U & (IData)((0x1ffULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               >> 0x1fU))))));
    bufp->fullBit(oldp+5118,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                              [0x37U])));
    bufp->fullBit(oldp+5119,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                                    [0x37U] >> 1U))));
    bufp->fullBit(oldp+5120,((1U & (~ (IData)((0x1ffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x1fU)))))));
    bufp->fullBit(oldp+5121,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x1ffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x1fU))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x1ffULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x1fU))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                                     [0x37U] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                                 [0x37U]))));
    bufp->fullBit(oldp+5122,((1U & (IData)((0xffULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               >> 0x20U))))));
    bufp->fullBit(oldp+5123,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                              [0x38U])));
    bufp->fullBit(oldp+5124,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                                    [0x38U] >> 1U))));
    bufp->fullBit(oldp+5125,((1U & (~ (IData)((0xffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x20U)))))));
    bufp->fullBit(oldp+5126,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0xffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x20U))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__x) 
                                   & (IData)((0xffULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x20U))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                                     [0x38U] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                                 [0x38U]))));
    bufp->fullBit(oldp+5127,((1U & (IData)((0x7fULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               >> 0x21U))))));
    bufp->fullBit(oldp+5128,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                              [0x39U])));
    bufp->fullBit(oldp+5129,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                                    [0x39U] >> 1U))));
    bufp->fullBit(oldp+5130,((1U & (~ (IData)((0x7fULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x21U)))))));
    bufp->fullBit(oldp+5131,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x7fULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x21U))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x7fULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x21U))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                                     [0x39U] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                                 [0x39U]))));
    bufp->fullBit(oldp+5132,((1U & (IData)((0x3fULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               >> 0x22U))))));
    bufp->fullBit(oldp+5133,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                              [0x3aU])));
    bufp->fullBit(oldp+5134,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                                    [0x3aU] >> 1U))));
    bufp->fullBit(oldp+5135,((1U & (~ (IData)((0x3fULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x22U)))))));
    bufp->fullBit(oldp+5136,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x3fULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x22U))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x3fULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x22U))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                                     [0x3aU] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                                 [0x3aU]))));
    bufp->fullBit(oldp+5137,((1U & (IData)((0x1fULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               >> 0x23U))))));
    bufp->fullBit(oldp+5138,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                              [0x3bU])));
    bufp->fullBit(oldp+5139,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                                    [0x3bU] >> 1U))));
    bufp->fullBit(oldp+5140,((1U & (~ (IData)((0x1fULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x23U)))))));
    bufp->fullBit(oldp+5141,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x1fULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x23U))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x1fULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x23U))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                                     [0x3bU] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                                 [0x3bU]))));
    bufp->fullBit(oldp+5142,((1U & (IData)((0x7fffffffff80000ULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               << 0x13U))))));
    bufp->fullBit(oldp+5143,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                              [5U])));
    bufp->fullBit(oldp+5144,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                                    [5U] >> 1U))));
    bufp->fullBit(oldp+5145,((1U & (~ (IData)((0x7fffffffff80000ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 0x13U)))))));
    bufp->fullBit(oldp+5146,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x7fffffffff80000ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 0x13U))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x7fffffffff80000ULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 0x13U))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                                     [5U] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                                 [5U]))));
    bufp->fullBit(oldp+5147,((1U & (IData)((0xfULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               >> 0x24U))))));
    bufp->fullBit(oldp+5148,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                              [0x3cU])));
    bufp->fullBit(oldp+5149,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                                    [0x3cU] >> 1U))));
    bufp->fullBit(oldp+5150,((1U & (~ (IData)((0xfULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x24U)))))));
    bufp->fullBit(oldp+5151,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0xfULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x24U))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__x) 
                                   & (IData)((0xfULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x24U))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                                     [0x3cU] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                                 [0x3cU]))));
    bufp->fullBit(oldp+5152,((1U & (IData)((7ULL & 
                                            (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                             >> 0x25U))))));
    bufp->fullBit(oldp+5153,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                              [0x3dU])));
    bufp->fullBit(oldp+5154,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                                    [0x3dU] >> 1U))));
    bufp->fullBit(oldp+5155,((1U & (~ (IData)((7ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x25U)))))));
    bufp->fullBit(oldp+5156,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((7ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x25U))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__x) 
                                   & (IData)((7ULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x25U))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                                     [0x3dU] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                                 [0x3dU]))));
    bufp->fullBit(oldp+5157,((1U & (IData)((3ULL & 
                                            (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                             >> 0x26U))))));
    bufp->fullBit(oldp+5158,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                              [0x3eU])));
    bufp->fullBit(oldp+5159,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                                    [0x3eU] >> 1U))));
    bufp->fullBit(oldp+5160,((1U & (~ (IData)((3ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x26U)))))));
    bufp->fullBit(oldp+5161,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((3ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x26U))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__x) 
                                   & (IData)((3ULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x26U))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                                     [0x3eU] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                                 [0x3eU]))));
    bufp->fullBit(oldp+5162,((1U & (IData)((1ULL & 
                                            (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                             >> 0x27U))))));
    bufp->fullBit(oldp+5163,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                              [0x3fU])));
    bufp->fullBit(oldp+5164,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                                    [0x3fU] >> 1U))));
    bufp->fullBit(oldp+5165,((1U & (~ (IData)((1ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x27U)))))));
    bufp->fullBit(oldp+5166,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((1ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x27U))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__x) 
                                   & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                      >> 0x27U))) | 
                               ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__neg2x) 
                                & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                                   [0x3fU] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                                 [0x3fU]))));
    bufp->fullBit(oldp+5167,((1U & (IData)((0x3fffffffffc0000ULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               << 0x12U))))));
    bufp->fullBit(oldp+5168,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                              [6U])));
    bufp->fullBit(oldp+5169,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                                    [6U] >> 1U))));
    bufp->fullBit(oldp+5170,((1U & (~ (IData)((0x3fffffffffc0000ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 0x12U)))))));
    bufp->fullBit(oldp+5171,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x3fffffffffc0000ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 0x12U))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x3fffffffffc0000ULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 0x12U))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                                     [6U] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                                 [6U]))));
    bufp->fullBit(oldp+5172,((1U & (IData)((0x1fffffffffe0000ULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               << 0x11U))))));
    bufp->fullBit(oldp+5173,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                              [7U])));
    bufp->fullBit(oldp+5174,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                                    [7U] >> 1U))));
    bufp->fullBit(oldp+5175,((1U & (~ (IData)((0x1fffffffffe0000ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 0x11U)))))));
    bufp->fullBit(oldp+5176,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x1fffffffffe0000ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 0x11U))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x1fffffffffe0000ULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 0x11U))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                                     [7U] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                                 [7U]))));
    bufp->fullBit(oldp+5177,((1U & (IData)((0xffffffffff0000ULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               << 0x10U))))));
    bufp->fullBit(oldp+5178,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                              [8U])));
    bufp->fullBit(oldp+5179,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                                    [8U] >> 1U))));
    bufp->fullBit(oldp+5180,((1U & (~ (IData)((0xffffffffff0000ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 0x10U)))))));
    bufp->fullBit(oldp+5181,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0xffffffffff0000ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 0x10U))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__x) 
                                   & (IData)((0xffffffffff0000ULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 0x10U))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                                     [8U] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                                 [8U]))));
    bufp->fullBit(oldp+5182,((1U & (IData)((0x7fffffffff8000ULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               << 0xfU))))));
    bufp->fullBit(oldp+5183,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                              [9U])));
    bufp->fullBit(oldp+5184,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                                    [9U] >> 1U))));
    bufp->fullBit(oldp+5185,((1U & (~ (IData)((0x7fffffffff8000ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 0xfU)))))));
    bufp->fullBit(oldp+5186,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x7fffffffff8000ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 0xfU))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x7fffffffff8000ULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 0xfU))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                                     [9U] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__24__KET____DOT__ai__DOT__CarrySig
                                 [9U]))));
    bufp->fullBit(oldp+5187,((1U & (IData)((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalY 
                                            >> 0x19U)))));
    bufp->fullBit(oldp+5188,((1U & (IData)((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalY 
                                            >> 0x18U)))));
    bufp->fullCData(oldp+5189,((7U & (IData)((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalY 
                                              >> 0x19U)))),3);
    bufp->fullQData(oldp+5190,((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                << 0x1aU)),64);
    bufp->fullQData(oldp+5192,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellout__boothfor__BRA__26__KET____DOT__ai__OutX),64);
    bufp->fullBit(oldp+5194,(((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__negx) 
                              | (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__neg2x))));
    bufp->fullBit(oldp+5195,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__negx));
    bufp->fullBit(oldp+5196,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__x));
    bufp->fullBit(oldp+5197,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__neg2x));
    bufp->fullBit(oldp+5198,((1U & (IData)((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                            << 0x1aU)))));
    bufp->fullBit(oldp+5199,((1U & (~ (IData)((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               << 0x1aU))))));
    bufp->fullBit(oldp+5200,(((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__negx) 
                                & (~ (IData)((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                              << 0x1aU)))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__x) 
                                  & (IData)((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                             << 0x1aU)))) 
                              | (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__neg2x))));
    bufp->fullBit(oldp+5201,((1U & (IData)((0x3fffffffff0000ULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               << 0x10U))))));
    bufp->fullBit(oldp+5202,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                              [0xaU])));
    bufp->fullBit(oldp+5203,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                                    [0xaU] >> 1U))));
    bufp->fullBit(oldp+5204,((1U & (~ (IData)((0x3fffffffff0000ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 0x10U)))))));
    bufp->fullBit(oldp+5205,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x3fffffffff0000ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 0x10U))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x3fffffffff0000ULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 0x10U))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                                     [0xaU] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                                 [0xaU]))));
    bufp->fullBit(oldp+5206,((1U & (IData)((0x1fffffffff8000ULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               << 0xfU))))));
    bufp->fullBit(oldp+5207,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                              [0xbU])));
    bufp->fullBit(oldp+5208,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                                    [0xbU] >> 1U))));
    bufp->fullBit(oldp+5209,((1U & (~ (IData)((0x1fffffffff8000ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 0xfU)))))));
    bufp->fullBit(oldp+5210,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x1fffffffff8000ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 0xfU))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x1fffffffff8000ULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 0xfU))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                                     [0xbU] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                                 [0xbU]))));
    bufp->fullBit(oldp+5211,((1U & (IData)((0xfffffffffc000ULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               << 0xeU))))));
    bufp->fullBit(oldp+5212,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                              [0xcU])));
    bufp->fullBit(oldp+5213,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                                    [0xcU] >> 1U))));
    bufp->fullBit(oldp+5214,((1U & (~ (IData)((0xfffffffffc000ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 0xeU)))))));
    bufp->fullBit(oldp+5215,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0xfffffffffc000ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 0xeU))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__x) 
                                   & (IData)((0xfffffffffc000ULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 0xeU))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                                     [0xcU] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                                 [0xcU]))));
    bufp->fullBit(oldp+5216,((1U & (IData)((0x7ffffffffe000ULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               << 0xdU))))));
    bufp->fullBit(oldp+5217,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                              [0xdU])));
    bufp->fullBit(oldp+5218,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                                    [0xdU] >> 1U))));
    bufp->fullBit(oldp+5219,((1U & (~ (IData)((0x7ffffffffe000ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 0xdU)))))));
    bufp->fullBit(oldp+5220,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x7ffffffffe000ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 0xdU))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x7ffffffffe000ULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 0xdU))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                                     [0xdU] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                                 [0xdU]))));
    bufp->fullBit(oldp+5221,((1U & (IData)((0x3fffffffff000ULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               << 0xcU))))));
    bufp->fullBit(oldp+5222,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                              [0xeU])));
    bufp->fullBit(oldp+5223,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                                    [0xeU] >> 1U))));
    bufp->fullBit(oldp+5224,((1U & (~ (IData)((0x3fffffffff000ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 0xcU)))))));
    bufp->fullBit(oldp+5225,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x3fffffffff000ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 0xcU))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x3fffffffff000ULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 0xcU))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                                     [0xeU] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                                 [0xeU]))));
    bufp->fullBit(oldp+5226,((1U & (IData)((0x1fffffffff800ULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               << 0xbU))))));
    bufp->fullBit(oldp+5227,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                              [0xfU])));
    bufp->fullBit(oldp+5228,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                                    [0xfU] >> 1U))));
    bufp->fullBit(oldp+5229,((1U & (~ (IData)((0x1fffffffff800ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 0xbU)))))));
    bufp->fullBit(oldp+5230,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x1fffffffff800ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 0xbU))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x1fffffffff800ULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 0xbU))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                                     [0xfU] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                                 [0xfU]))));
    bufp->fullBit(oldp+5231,((1U & (IData)((0xfffffffffc00ULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               << 0xaU))))));
    bufp->fullBit(oldp+5232,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                              [0x10U])));
    bufp->fullBit(oldp+5233,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                                    [0x10U] >> 1U))));
    bufp->fullBit(oldp+5234,((1U & (~ (IData)((0xfffffffffc00ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 0xaU)))))));
    bufp->fullBit(oldp+5235,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0xfffffffffc00ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 0xaU))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__x) 
                                   & (IData)((0xfffffffffc00ULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 0xaU))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                                     [0x10U] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                                 [0x10U]))));
    bufp->fullBit(oldp+5236,((1U & (IData)((0x7ffffffffe00ULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               << 9U))))));
    bufp->fullBit(oldp+5237,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                              [0x11U])));
    bufp->fullBit(oldp+5238,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                                    [0x11U] >> 1U))));
    bufp->fullBit(oldp+5239,((1U & (~ (IData)((0x7ffffffffe00ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 9U)))))));
    bufp->fullBit(oldp+5240,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x7ffffffffe00ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 9U))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x7ffffffffe00ULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 9U))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                                     [0x11U] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                                 [0x11U]))));
    bufp->fullBit(oldp+5241,((1U & (IData)((0x3fffffffff00ULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               << 8U))))));
    bufp->fullBit(oldp+5242,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                              [0x12U])));
    bufp->fullBit(oldp+5243,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                                    [0x12U] >> 1U))));
    bufp->fullBit(oldp+5244,((1U & (~ (IData)((0x3fffffffff00ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 8U)))))));
    bufp->fullBit(oldp+5245,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x3fffffffff00ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 8U))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x3fffffffff00ULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 8U))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                                     [0x12U] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                                 [0x12U]))));
    bufp->fullBit(oldp+5246,((1U & (IData)((0x1fffffffff80ULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               << 7U))))));
    bufp->fullBit(oldp+5247,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                              [0x13U])));
    bufp->fullBit(oldp+5248,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                                    [0x13U] >> 1U))));
    bufp->fullBit(oldp+5249,((1U & (~ (IData)((0x1fffffffff80ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 7U)))))));
    bufp->fullBit(oldp+5250,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x1fffffffff80ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 7U))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x1fffffffff80ULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 7U))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                                     [0x13U] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                                 [0x13U]))));
    bufp->fullBit(oldp+5251,((1U & (IData)((0x7ffffffffe000000ULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               << 0x19U))))));
    bufp->fullBit(oldp+5252,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                              [1U])));
    bufp->fullBit(oldp+5253,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                                    [1U] >> 1U))));
    bufp->fullBit(oldp+5254,((1U & (~ (IData)((0x7ffffffffe000000ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 0x19U)))))));
    bufp->fullBit(oldp+5255,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x7ffffffffe000000ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 0x19U))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x7ffffffffe000000ULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 0x19U))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                                     [1U] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                                 [1U]))));
    bufp->fullBit(oldp+5256,((1U & (IData)((0xfffffffffc0ULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               << 6U))))));
    bufp->fullBit(oldp+5257,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                              [0x14U])));
    bufp->fullBit(oldp+5258,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                                    [0x14U] >> 1U))));
    bufp->fullBit(oldp+5259,((1U & (~ (IData)((0xfffffffffc0ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 6U)))))));
    bufp->fullBit(oldp+5260,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0xfffffffffc0ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 6U))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__x) 
                                   & (IData)((0xfffffffffc0ULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 6U))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                                     [0x14U] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                                 [0x14U]))));
    bufp->fullBit(oldp+5261,((1U & (IData)((0x7ffffffffe0ULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               << 5U))))));
    bufp->fullBit(oldp+5262,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                              [0x15U])));
    bufp->fullBit(oldp+5263,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                                    [0x15U] >> 1U))));
    bufp->fullBit(oldp+5264,((1U & (~ (IData)((0x7ffffffffe0ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 5U)))))));
    bufp->fullBit(oldp+5265,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x7ffffffffe0ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 5U))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x7ffffffffe0ULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 5U))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                                     [0x15U] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                                 [0x15U]))));
    bufp->fullBit(oldp+5266,((1U & (IData)((0x3fffffffff0ULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               << 4U))))));
    bufp->fullBit(oldp+5267,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                              [0x16U])));
    bufp->fullBit(oldp+5268,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                                    [0x16U] >> 1U))));
    bufp->fullBit(oldp+5269,((1U & (~ (IData)((0x3fffffffff0ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 4U)))))));
    bufp->fullBit(oldp+5270,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x3fffffffff0ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 4U))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x3fffffffff0ULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 4U))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                                     [0x16U] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                                 [0x16U]))));
    bufp->fullBit(oldp+5271,((1U & (IData)((0x1fffffffff8ULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               << 3U))))));
    bufp->fullBit(oldp+5272,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                              [0x17U])));
    bufp->fullBit(oldp+5273,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                                    [0x17U] >> 1U))));
    bufp->fullBit(oldp+5274,((1U & (~ (IData)((0x1fffffffff8ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 3U)))))));
    bufp->fullBit(oldp+5275,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x1fffffffff8ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 3U))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x1fffffffff8ULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 3U))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                                     [0x17U] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                                 [0x17U]))));
    bufp->fullBit(oldp+5276,((1U & (IData)((0xfffffffffcULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               << 2U))))));
    bufp->fullBit(oldp+5277,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                              [0x18U])));
    bufp->fullBit(oldp+5278,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                                    [0x18U] >> 1U))));
    bufp->fullBit(oldp+5279,((1U & (~ (IData)((0xfffffffffcULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 2U)))))));
    bufp->fullBit(oldp+5280,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0xfffffffffcULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 2U))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__x) 
                                   & (IData)((0xfffffffffcULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 2U))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                                     [0x18U] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                                 [0x18U]))));
    bufp->fullBit(oldp+5281,((1U & (IData)((0x7ffffffffeULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               << 1U))))));
    bufp->fullBit(oldp+5282,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                              [0x19U])));
    bufp->fullBit(oldp+5283,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                                    [0x19U] >> 1U))));
    bufp->fullBit(oldp+5284,((1U & (~ (IData)((0x7ffffffffeULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 1U)))))));
    bufp->fullBit(oldp+5285,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x7ffffffffeULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 1U))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x7ffffffffeULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 1U))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                                     [0x19U] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                                 [0x19U]))));
    bufp->fullBit(oldp+5286,((1U & (IData)((0x3fffffffffULL 
                                            & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX)))));
    bufp->fullBit(oldp+5287,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                              [0x1aU])));
    bufp->fullBit(oldp+5288,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                                    [0x1aU] >> 1U))));
    bufp->fullBit(oldp+5289,((1U & (~ (IData)((0x3fffffffffULL 
                                               & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX))))));
    bufp->fullBit(oldp+5290,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x3fffffffffULL 
                                               & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX)))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x3fffffffffULL 
                                              & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX)))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                                     [0x1aU] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                                 [0x1aU]))));
    bufp->fullBit(oldp+5291,((1U & (IData)((0x1fffffffffULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               >> 1U))))));
    bufp->fullBit(oldp+5292,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                              [0x1bU])));
    bufp->fullBit(oldp+5293,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                                    [0x1bU] >> 1U))));
    bufp->fullBit(oldp+5294,((1U & (~ (IData)((0x1fffffffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 1U)))))));
    bufp->fullBit(oldp+5295,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x1fffffffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 1U))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x1fffffffffULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 1U))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                                     [0x1bU] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                                 [0x1bU]))));
    bufp->fullBit(oldp+5296,((1U & (IData)((0xfffffffffULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               >> 2U))))));
    bufp->fullBit(oldp+5297,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                              [0x1cU])));
    bufp->fullBit(oldp+5298,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                                    [0x1cU] >> 1U))));
    bufp->fullBit(oldp+5299,((1U & (~ (IData)((0xfffffffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 2U)))))));
    bufp->fullBit(oldp+5300,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0xfffffffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 2U))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__x) 
                                   & (IData)((0xfffffffffULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 2U))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                                     [0x1cU] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                                 [0x1cU]))));
    bufp->fullBit(oldp+5301,((1U & (IData)((0x7ffffffffULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               >> 3U))))));
    bufp->fullBit(oldp+5302,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                              [0x1dU])));
    bufp->fullBit(oldp+5303,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                                    [0x1dU] >> 1U))));
    bufp->fullBit(oldp+5304,((1U & (~ (IData)((0x7ffffffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 3U)))))));
    bufp->fullBit(oldp+5305,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x7ffffffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 3U))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x7ffffffffULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 3U))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                                     [0x1dU] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                                 [0x1dU]))));
    bufp->fullBit(oldp+5306,((1U & (IData)((0x3fffffffff000000ULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               << 0x18U))))));
    bufp->fullBit(oldp+5307,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                              [2U])));
    bufp->fullBit(oldp+5308,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                                    [2U] >> 1U))));
    bufp->fullBit(oldp+5309,((1U & (~ (IData)((0x3fffffffff000000ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 0x18U)))))));
    bufp->fullBit(oldp+5310,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x3fffffffff000000ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 0x18U))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x3fffffffff000000ULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 0x18U))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                                     [2U] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                                 [2U]))));
    bufp->fullBit(oldp+5311,((1U & (IData)((0x3ffffffffULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               >> 4U))))));
    bufp->fullBit(oldp+5312,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                              [0x1eU])));
    bufp->fullBit(oldp+5313,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                                    [0x1eU] >> 1U))));
    bufp->fullBit(oldp+5314,((1U & (~ (IData)((0x3ffffffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 4U)))))));
    bufp->fullBit(oldp+5315,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x3ffffffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 4U))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x3ffffffffULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 4U))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                                     [0x1eU] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                                 [0x1eU]))));
    bufp->fullBit(oldp+5316,((1U & (IData)((0x1ffffffffULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               >> 5U))))));
    bufp->fullBit(oldp+5317,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                              [0x1fU])));
    bufp->fullBit(oldp+5318,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                                    [0x1fU] >> 1U))));
    bufp->fullBit(oldp+5319,((1U & (~ (IData)((0x1ffffffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 5U)))))));
    bufp->fullBit(oldp+5320,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x1ffffffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 5U))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x1ffffffffULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 5U))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                                     [0x1fU] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                                 [0x1fU]))));
    bufp->fullBit(oldp+5321,((1U & (IData)((0xffffffffULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               >> 6U))))));
    bufp->fullBit(oldp+5322,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                              [0x20U])));
    bufp->fullBit(oldp+5323,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                                    [0x20U] >> 1U))));
    bufp->fullBit(oldp+5324,((1U & (~ (IData)((0xffffffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 6U)))))));
    bufp->fullBit(oldp+5325,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0xffffffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 6U))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__x) 
                                   & (IData)((0xffffffffULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 6U))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                                     [0x20U] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                                 [0x20U]))));
    bufp->fullBit(oldp+5326,((1U & (IData)((0x7fffffffULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               >> 7U))))));
    bufp->fullBit(oldp+5327,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                              [0x21U])));
    bufp->fullBit(oldp+5328,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                                    [0x21U] >> 1U))));
    bufp->fullBit(oldp+5329,((1U & (~ (IData)((0x7fffffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 7U)))))));
    bufp->fullBit(oldp+5330,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x7fffffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 7U))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x7fffffffULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 7U))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                                     [0x21U] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                                 [0x21U]))));
    bufp->fullBit(oldp+5331,((1U & (IData)((0x3fffffffULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               >> 8U))))));
    bufp->fullBit(oldp+5332,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                              [0x22U])));
    bufp->fullBit(oldp+5333,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                                    [0x22U] >> 1U))));
    bufp->fullBit(oldp+5334,((1U & (~ (IData)((0x3fffffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 8U)))))));
    bufp->fullBit(oldp+5335,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x3fffffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 8U))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x3fffffffULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 8U))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                                     [0x22U] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                                 [0x22U]))));
    bufp->fullBit(oldp+5336,((1U & (IData)((0x1fffffffULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               >> 9U))))));
    bufp->fullBit(oldp+5337,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                              [0x23U])));
    bufp->fullBit(oldp+5338,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                                    [0x23U] >> 1U))));
    bufp->fullBit(oldp+5339,((1U & (~ (IData)((0x1fffffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 9U)))))));
    bufp->fullBit(oldp+5340,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x1fffffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 9U))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x1fffffffULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 9U))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                                     [0x23U] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                                 [0x23U]))));
    bufp->fullBit(oldp+5341,((1U & (IData)((0xfffffffULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               >> 0xaU))))));
    bufp->fullBit(oldp+5342,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                              [0x24U])));
    bufp->fullBit(oldp+5343,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                                    [0x24U] >> 1U))));
    bufp->fullBit(oldp+5344,((1U & (~ (IData)((0xfffffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0xaU)))))));
    bufp->fullBit(oldp+5345,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0xfffffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0xaU))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__x) 
                                   & (IData)((0xfffffffULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0xaU))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                                     [0x24U] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                                 [0x24U]))));
    bufp->fullBit(oldp+5346,((1U & (IData)((0x7ffffffULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               >> 0xbU))))));
    bufp->fullBit(oldp+5347,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                              [0x25U])));
    bufp->fullBit(oldp+5348,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                                    [0x25U] >> 1U))));
    bufp->fullBit(oldp+5349,((1U & (~ (IData)((0x7ffffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0xbU)))))));
    bufp->fullBit(oldp+5350,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x7ffffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0xbU))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x7ffffffULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0xbU))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                                     [0x25U] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                                 [0x25U]))));
    bufp->fullBit(oldp+5351,((1U & (IData)((0x3ffffffULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               >> 0xcU))))));
    bufp->fullBit(oldp+5352,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                              [0x26U])));
    bufp->fullBit(oldp+5353,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                                    [0x26U] >> 1U))));
    bufp->fullBit(oldp+5354,((1U & (~ (IData)((0x3ffffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0xcU)))))));
    bufp->fullBit(oldp+5355,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x3ffffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0xcU))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x3ffffffULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0xcU))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                                     [0x26U] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                                 [0x26U]))));
    bufp->fullBit(oldp+5356,((1U & (IData)((0x1ffffffULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               >> 0xdU))))));
    bufp->fullBit(oldp+5357,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                              [0x27U])));
    bufp->fullBit(oldp+5358,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                                    [0x27U] >> 1U))));
    bufp->fullBit(oldp+5359,((1U & (~ (IData)((0x1ffffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0xdU)))))));
    bufp->fullBit(oldp+5360,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x1ffffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0xdU))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x1ffffffULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0xdU))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                                     [0x27U] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                                 [0x27U]))));
    bufp->fullBit(oldp+5361,((1U & (IData)((0x1fffffffff800000ULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               << 0x17U))))));
    bufp->fullBit(oldp+5362,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                              [3U])));
    bufp->fullBit(oldp+5363,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                                    [3U] >> 1U))));
    bufp->fullBit(oldp+5364,((1U & (~ (IData)((0x1fffffffff800000ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 0x17U)))))));
    bufp->fullBit(oldp+5365,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x1fffffffff800000ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 0x17U))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x1fffffffff800000ULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 0x17U))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                                     [3U] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                                 [3U]))));
    bufp->fullBit(oldp+5366,((1U & (IData)((0xffffffULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               >> 0xeU))))));
    bufp->fullBit(oldp+5367,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                              [0x28U])));
    bufp->fullBit(oldp+5368,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                                    [0x28U] >> 1U))));
    bufp->fullBit(oldp+5369,((1U & (~ (IData)((0xffffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0xeU)))))));
    bufp->fullBit(oldp+5370,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0xffffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0xeU))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__x) 
                                   & (IData)((0xffffffULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0xeU))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                                     [0x28U] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                                 [0x28U]))));
    bufp->fullBit(oldp+5371,((1U & (IData)((0x7fffffULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               >> 0xfU))))));
    bufp->fullBit(oldp+5372,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                              [0x29U])));
    bufp->fullBit(oldp+5373,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                                    [0x29U] >> 1U))));
    bufp->fullBit(oldp+5374,((1U & (~ (IData)((0x7fffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0xfU)))))));
    bufp->fullBit(oldp+5375,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x7fffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0xfU))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x7fffffULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0xfU))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                                     [0x29U] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                                 [0x29U]))));
    bufp->fullBit(oldp+5376,((1U & (IData)((0x3fffffULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               >> 0x10U))))));
    bufp->fullBit(oldp+5377,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                              [0x2aU])));
    bufp->fullBit(oldp+5378,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                                    [0x2aU] >> 1U))));
    bufp->fullBit(oldp+5379,((1U & (~ (IData)((0x3fffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x10U)))))));
    bufp->fullBit(oldp+5380,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x3fffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x10U))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x3fffffULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x10U))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                                     [0x2aU] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                                 [0x2aU]))));
    bufp->fullBit(oldp+5381,((1U & (IData)((0x1fffffULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               >> 0x11U))))));
    bufp->fullBit(oldp+5382,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                              [0x2bU])));
    bufp->fullBit(oldp+5383,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                                    [0x2bU] >> 1U))));
    bufp->fullBit(oldp+5384,((1U & (~ (IData)((0x1fffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x11U)))))));
    bufp->fullBit(oldp+5385,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x1fffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x11U))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x1fffffULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x11U))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                                     [0x2bU] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                                 [0x2bU]))));
    bufp->fullBit(oldp+5386,((1U & (IData)((0xfffffULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               >> 0x12U))))));
    bufp->fullBit(oldp+5387,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                              [0x2cU])));
    bufp->fullBit(oldp+5388,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                                    [0x2cU] >> 1U))));
    bufp->fullBit(oldp+5389,((1U & (~ (IData)((0xfffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x12U)))))));
    bufp->fullBit(oldp+5390,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0xfffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x12U))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__x) 
                                   & (IData)((0xfffffULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x12U))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                                     [0x2cU] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                                 [0x2cU]))));
    bufp->fullBit(oldp+5391,((1U & (IData)((0x7ffffULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               >> 0x13U))))));
    bufp->fullBit(oldp+5392,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                              [0x2dU])));
    bufp->fullBit(oldp+5393,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                                    [0x2dU] >> 1U))));
    bufp->fullBit(oldp+5394,((1U & (~ (IData)((0x7ffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x13U)))))));
    bufp->fullBit(oldp+5395,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x7ffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x13U))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x7ffffULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x13U))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                                     [0x2dU] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                                 [0x2dU]))));
    bufp->fullBit(oldp+5396,((1U & (IData)((0x3ffffULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               >> 0x14U))))));
    bufp->fullBit(oldp+5397,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                              [0x2eU])));
    bufp->fullBit(oldp+5398,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                                    [0x2eU] >> 1U))));
    bufp->fullBit(oldp+5399,((1U & (~ (IData)((0x3ffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x14U)))))));
    bufp->fullBit(oldp+5400,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x3ffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x14U))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x3ffffULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x14U))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                                     [0x2eU] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                                 [0x2eU]))));
    bufp->fullBit(oldp+5401,((1U & (IData)((0x1ffffULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               >> 0x15U))))));
    bufp->fullBit(oldp+5402,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                              [0x2fU])));
    bufp->fullBit(oldp+5403,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                                    [0x2fU] >> 1U))));
    bufp->fullBit(oldp+5404,((1U & (~ (IData)((0x1ffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x15U)))))));
    bufp->fullBit(oldp+5405,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x1ffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x15U))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x1ffffULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x15U))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                                     [0x2fU] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                                 [0x2fU]))));
    bufp->fullBit(oldp+5406,((1U & (IData)((0xffffULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               >> 0x16U))))));
    bufp->fullBit(oldp+5407,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                              [0x30U])));
    bufp->fullBit(oldp+5408,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                                    [0x30U] >> 1U))));
    bufp->fullBit(oldp+5409,((1U & (~ (IData)((0xffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x16U)))))));
    bufp->fullBit(oldp+5410,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0xffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x16U))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__x) 
                                   & (IData)((0xffffULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x16U))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                                     [0x30U] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                                 [0x30U]))));
    bufp->fullBit(oldp+5411,((1U & (IData)((0x7fffULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               >> 0x17U))))));
    bufp->fullBit(oldp+5412,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                              [0x31U])));
    bufp->fullBit(oldp+5413,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                                    [0x31U] >> 1U))));
    bufp->fullBit(oldp+5414,((1U & (~ (IData)((0x7fffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x17U)))))));
    bufp->fullBit(oldp+5415,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x7fffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x17U))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x7fffULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x17U))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                                     [0x31U] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                                 [0x31U]))));
    bufp->fullBit(oldp+5416,((1U & (IData)((0xfffffffffc00000ULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               << 0x16U))))));
    bufp->fullBit(oldp+5417,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                              [4U])));
    bufp->fullBit(oldp+5418,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                                    [4U] >> 1U))));
    bufp->fullBit(oldp+5419,((1U & (~ (IData)((0xfffffffffc00000ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 0x16U)))))));
    bufp->fullBit(oldp+5420,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0xfffffffffc00000ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 0x16U))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__x) 
                                   & (IData)((0xfffffffffc00000ULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 0x16U))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                                     [4U] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                                 [4U]))));
    bufp->fullBit(oldp+5421,((1U & (IData)((0x3fffULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               >> 0x18U))))));
    bufp->fullBit(oldp+5422,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                              [0x32U])));
    bufp->fullBit(oldp+5423,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                                    [0x32U] >> 1U))));
    bufp->fullBit(oldp+5424,((1U & (~ (IData)((0x3fffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x18U)))))));
    bufp->fullBit(oldp+5425,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x3fffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x18U))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x3fffULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x18U))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                                     [0x32U] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                                 [0x32U]))));
    bufp->fullBit(oldp+5426,((1U & (IData)((0x1fffULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               >> 0x19U))))));
    bufp->fullBit(oldp+5427,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                              [0x33U])));
    bufp->fullBit(oldp+5428,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                                    [0x33U] >> 1U))));
    bufp->fullBit(oldp+5429,((1U & (~ (IData)((0x1fffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x19U)))))));
    bufp->fullBit(oldp+5430,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x1fffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x19U))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x1fffULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x19U))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                                     [0x33U] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                                 [0x33U]))));
    bufp->fullBit(oldp+5431,((1U & (IData)((0xfffULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               >> 0x1aU))))));
    bufp->fullBit(oldp+5432,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                              [0x34U])));
    bufp->fullBit(oldp+5433,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                                    [0x34U] >> 1U))));
    bufp->fullBit(oldp+5434,((1U & (~ (IData)((0xfffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x1aU)))))));
    bufp->fullBit(oldp+5435,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0xfffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x1aU))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__x) 
                                   & (IData)((0xfffULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x1aU))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                                     [0x34U] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                                 [0x34U]))));
    bufp->fullBit(oldp+5436,((1U & (IData)((0x7ffULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               >> 0x1bU))))));
    bufp->fullBit(oldp+5437,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                              [0x35U])));
    bufp->fullBit(oldp+5438,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                                    [0x35U] >> 1U))));
    bufp->fullBit(oldp+5439,((1U & (~ (IData)((0x7ffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x1bU)))))));
    bufp->fullBit(oldp+5440,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x7ffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x1bU))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x7ffULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x1bU))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                                     [0x35U] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                                 [0x35U]))));
    bufp->fullBit(oldp+5441,((1U & (IData)((0x3ffULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               >> 0x1cU))))));
    bufp->fullBit(oldp+5442,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                              [0x36U])));
    bufp->fullBit(oldp+5443,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                                    [0x36U] >> 1U))));
    bufp->fullBit(oldp+5444,((1U & (~ (IData)((0x3ffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x1cU)))))));
    bufp->fullBit(oldp+5445,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x3ffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x1cU))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x3ffULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x1cU))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                                     [0x36U] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                                 [0x36U]))));
    bufp->fullBit(oldp+5446,((1U & (IData)((0x1ffULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               >> 0x1dU))))));
    bufp->fullBit(oldp+5447,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                              [0x37U])));
    bufp->fullBit(oldp+5448,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                                    [0x37U] >> 1U))));
    bufp->fullBit(oldp+5449,((1U & (~ (IData)((0x1ffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x1dU)))))));
    bufp->fullBit(oldp+5450,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x1ffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x1dU))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x1ffULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x1dU))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                                     [0x37U] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                                 [0x37U]))));
    bufp->fullBit(oldp+5451,((1U & (IData)((0xffULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               >> 0x1eU))))));
    bufp->fullBit(oldp+5452,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                              [0x38U])));
    bufp->fullBit(oldp+5453,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                                    [0x38U] >> 1U))));
    bufp->fullBit(oldp+5454,((1U & (~ (IData)((0xffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x1eU)))))));
    bufp->fullBit(oldp+5455,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0xffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x1eU))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__x) 
                                   & (IData)((0xffULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x1eU))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                                     [0x38U] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                                 [0x38U]))));
    bufp->fullBit(oldp+5456,((1U & (IData)((0x7fULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               >> 0x1fU))))));
    bufp->fullBit(oldp+5457,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                              [0x39U])));
    bufp->fullBit(oldp+5458,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                                    [0x39U] >> 1U))));
    bufp->fullBit(oldp+5459,((1U & (~ (IData)((0x7fULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x1fU)))))));
    bufp->fullBit(oldp+5460,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x7fULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x1fU))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x7fULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x1fU))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                                     [0x39U] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                                 [0x39U]))));
    bufp->fullBit(oldp+5461,((1U & (IData)((0x3fULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               >> 0x20U))))));
    bufp->fullBit(oldp+5462,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                              [0x3aU])));
    bufp->fullBit(oldp+5463,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                                    [0x3aU] >> 1U))));
    bufp->fullBit(oldp+5464,((1U & (~ (IData)((0x3fULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x20U)))))));
    bufp->fullBit(oldp+5465,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x3fULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x20U))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x3fULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x20U))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                                     [0x3aU] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                                 [0x3aU]))));
    bufp->fullBit(oldp+5466,((1U & (IData)((0x1fULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               >> 0x21U))))));
    bufp->fullBit(oldp+5467,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                              [0x3bU])));
    bufp->fullBit(oldp+5468,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                                    [0x3bU] >> 1U))));
    bufp->fullBit(oldp+5469,((1U & (~ (IData)((0x1fULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x21U)))))));
    bufp->fullBit(oldp+5470,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x1fULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x21U))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x1fULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x21U))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                                     [0x3bU] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                                 [0x3bU]))));
    bufp->fullBit(oldp+5471,((1U & (IData)((0x7ffffffffe00000ULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               << 0x15U))))));
    bufp->fullBit(oldp+5472,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                              [5U])));
    bufp->fullBit(oldp+5473,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                                    [5U] >> 1U))));
    bufp->fullBit(oldp+5474,((1U & (~ (IData)((0x7ffffffffe00000ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 0x15U)))))));
    bufp->fullBit(oldp+5475,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x7ffffffffe00000ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 0x15U))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x7ffffffffe00000ULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 0x15U))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                                     [5U] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                                 [5U]))));
    bufp->fullBit(oldp+5476,((1U & (IData)((0xfULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               >> 0x22U))))));
    bufp->fullBit(oldp+5477,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                              [0x3cU])));
    bufp->fullBit(oldp+5478,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                                    [0x3cU] >> 1U))));
    bufp->fullBit(oldp+5479,((1U & (~ (IData)((0xfULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x22U)))))));
    bufp->fullBit(oldp+5480,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0xfULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x22U))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__x) 
                                   & (IData)((0xfULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x22U))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                                     [0x3cU] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                                 [0x3cU]))));
    bufp->fullBit(oldp+5481,((1U & (IData)((7ULL & 
                                            (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                             >> 0x23U))))));
    bufp->fullBit(oldp+5482,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                              [0x3dU])));
    bufp->fullBit(oldp+5483,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                                    [0x3dU] >> 1U))));
    bufp->fullBit(oldp+5484,((1U & (~ (IData)((7ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x23U)))))));
    bufp->fullBit(oldp+5485,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((7ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x23U))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__x) 
                                   & (IData)((7ULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x23U))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                                     [0x3dU] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                                 [0x3dU]))));
    bufp->fullBit(oldp+5486,((1U & (IData)((3ULL & 
                                            (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                             >> 0x24U))))));
    bufp->fullBit(oldp+5487,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                              [0x3eU])));
    bufp->fullBit(oldp+5488,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                                    [0x3eU] >> 1U))));
    bufp->fullBit(oldp+5489,((1U & (~ (IData)((3ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x24U)))))));
    bufp->fullBit(oldp+5490,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((3ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x24U))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__x) 
                                   & (IData)((3ULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x24U))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                                     [0x3eU] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                                 [0x3eU]))));
    bufp->fullBit(oldp+5491,((1U & (IData)((1ULL & 
                                            (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                             >> 0x25U))))));
    bufp->fullBit(oldp+5492,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                              [0x3fU])));
    bufp->fullBit(oldp+5493,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                                    [0x3fU] >> 1U))));
    bufp->fullBit(oldp+5494,((1U & (~ (IData)((1ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x25U)))))));
    bufp->fullBit(oldp+5495,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((1ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x25U))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__x) 
                                   & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                      >> 0x25U))) | 
                               ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__neg2x) 
                                & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                                   [0x3fU] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                                 [0x3fU]))));
    bufp->fullBit(oldp+5496,((1U & (IData)((0x3fffffffff00000ULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               << 0x14U))))));
    bufp->fullBit(oldp+5497,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                              [6U])));
    bufp->fullBit(oldp+5498,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                                    [6U] >> 1U))));
    bufp->fullBit(oldp+5499,((1U & (~ (IData)((0x3fffffffff00000ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 0x14U)))))));
    bufp->fullBit(oldp+5500,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x3fffffffff00000ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 0x14U))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x3fffffffff00000ULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 0x14U))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                                     [6U] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                                 [6U]))));
    bufp->fullBit(oldp+5501,((1U & (IData)((0x1fffffffff80000ULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               << 0x13U))))));
    bufp->fullBit(oldp+5502,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                              [7U])));
    bufp->fullBit(oldp+5503,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                                    [7U] >> 1U))));
    bufp->fullBit(oldp+5504,((1U & (~ (IData)((0x1fffffffff80000ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 0x13U)))))));
    bufp->fullBit(oldp+5505,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x1fffffffff80000ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 0x13U))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x1fffffffff80000ULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 0x13U))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                                     [7U] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                                 [7U]))));
    bufp->fullBit(oldp+5506,((1U & (IData)((0xfffffffffc0000ULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               << 0x12U))))));
    bufp->fullBit(oldp+5507,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                              [8U])));
    bufp->fullBit(oldp+5508,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                                    [8U] >> 1U))));
    bufp->fullBit(oldp+5509,((1U & (~ (IData)((0xfffffffffc0000ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 0x12U)))))));
    bufp->fullBit(oldp+5510,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0xfffffffffc0000ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 0x12U))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__x) 
                                   & (IData)((0xfffffffffc0000ULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 0x12U))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                                     [8U] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                                 [8U]))));
    bufp->fullBit(oldp+5511,((1U & (IData)((0x7ffffffffe0000ULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               << 0x11U))))));
    bufp->fullBit(oldp+5512,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                              [9U])));
    bufp->fullBit(oldp+5513,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                                    [9U] >> 1U))));
    bufp->fullBit(oldp+5514,((1U & (~ (IData)((0x7ffffffffe0000ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 0x11U)))))));
    bufp->fullBit(oldp+5515,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x7ffffffffe0000ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 0x11U))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x7ffffffffe0000ULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 0x11U))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                                     [9U] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__26__KET____DOT__ai__DOT__CarrySig
                                 [9U]))));
    bufp->fullBit(oldp+5516,((1U & (IData)((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalY 
                                            >> 0x1bU)))));
    bufp->fullBit(oldp+5517,((1U & (IData)((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalY 
                                            >> 0x1aU)))));
    bufp->fullCData(oldp+5518,((7U & (IData)((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalY 
                                              >> 0x1bU)))),3);
    bufp->fullQData(oldp+5519,((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                << 0x1cU)),64);
    bufp->fullQData(oldp+5521,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellout__boothfor__BRA__28__KET____DOT__ai__OutX),64);
    bufp->fullBit(oldp+5523,(((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__negx) 
                              | (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__neg2x))));
    bufp->fullBit(oldp+5524,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__negx));
    bufp->fullBit(oldp+5525,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__x));
    bufp->fullBit(oldp+5526,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__neg2x));
    bufp->fullBit(oldp+5527,((1U & (IData)((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                            << 0x1cU)))));
    bufp->fullBit(oldp+5528,((1U & (~ (IData)((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               << 0x1cU))))));
    bufp->fullBit(oldp+5529,(((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__negx) 
                                & (~ (IData)((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                              << 0x1cU)))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__x) 
                                  & (IData)((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                             << 0x1cU)))) 
                              | (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__neg2x))));
    bufp->fullBit(oldp+5530,((1U & (IData)((0x3ffffffffc0000ULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               << 0x12U))))));
    bufp->fullBit(oldp+5531,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                              [0xaU])));
    bufp->fullBit(oldp+5532,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                                    [0xaU] >> 1U))));
    bufp->fullBit(oldp+5533,((1U & (~ (IData)((0x3ffffffffc0000ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 0x12U)))))));
    bufp->fullBit(oldp+5534,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x3ffffffffc0000ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 0x12U))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x3ffffffffc0000ULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 0x12U))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                                     [0xaU] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                                 [0xaU]))));
    bufp->fullBit(oldp+5535,((1U & (IData)((0x1ffffffffe0000ULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               << 0x11U))))));
    bufp->fullBit(oldp+5536,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                              [0xbU])));
    bufp->fullBit(oldp+5537,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                                    [0xbU] >> 1U))));
    bufp->fullBit(oldp+5538,((1U & (~ (IData)((0x1ffffffffe0000ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 0x11U)))))));
    bufp->fullBit(oldp+5539,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x1ffffffffe0000ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 0x11U))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x1ffffffffe0000ULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 0x11U))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                                     [0xbU] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                                 [0xbU]))));
    bufp->fullBit(oldp+5540,((1U & (IData)((0xfffffffff0000ULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               << 0x10U))))));
    bufp->fullBit(oldp+5541,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                              [0xcU])));
    bufp->fullBit(oldp+5542,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                                    [0xcU] >> 1U))));
    bufp->fullBit(oldp+5543,((1U & (~ (IData)((0xfffffffff0000ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 0x10U)))))));
    bufp->fullBit(oldp+5544,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0xfffffffff0000ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 0x10U))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__x) 
                                   & (IData)((0xfffffffff0000ULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 0x10U))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                                     [0xcU] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                                 [0xcU]))));
    bufp->fullBit(oldp+5545,((1U & (IData)((0x7ffffffff8000ULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               << 0xfU))))));
    bufp->fullBit(oldp+5546,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                              [0xdU])));
    bufp->fullBit(oldp+5547,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                                    [0xdU] >> 1U))));
    bufp->fullBit(oldp+5548,((1U & (~ (IData)((0x7ffffffff8000ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 0xfU)))))));
    bufp->fullBit(oldp+5549,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x7ffffffff8000ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 0xfU))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x7ffffffff8000ULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 0xfU))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                                     [0xdU] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                                 [0xdU]))));
    bufp->fullBit(oldp+5550,((1U & (IData)((0x3ffffffffc000ULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               << 0xeU))))));
    bufp->fullBit(oldp+5551,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                              [0xeU])));
    bufp->fullBit(oldp+5552,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                                    [0xeU] >> 1U))));
    bufp->fullBit(oldp+5553,((1U & (~ (IData)((0x3ffffffffc000ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 0xeU)))))));
    bufp->fullBit(oldp+5554,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x3ffffffffc000ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 0xeU))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x3ffffffffc000ULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 0xeU))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                                     [0xeU] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                                 [0xeU]))));
    bufp->fullBit(oldp+5555,((1U & (IData)((0x1ffffffffe000ULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               << 0xdU))))));
    bufp->fullBit(oldp+5556,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                              [0xfU])));
    bufp->fullBit(oldp+5557,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                                    [0xfU] >> 1U))));
    bufp->fullBit(oldp+5558,((1U & (~ (IData)((0x1ffffffffe000ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 0xdU)))))));
    bufp->fullBit(oldp+5559,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x1ffffffffe000ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 0xdU))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x1ffffffffe000ULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 0xdU))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                                     [0xfU] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                                 [0xfU]))));
    bufp->fullBit(oldp+5560,((1U & (IData)((0xfffffffff000ULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               << 0xcU))))));
    bufp->fullBit(oldp+5561,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                              [0x10U])));
    bufp->fullBit(oldp+5562,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                                    [0x10U] >> 1U))));
    bufp->fullBit(oldp+5563,((1U & (~ (IData)((0xfffffffff000ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 0xcU)))))));
    bufp->fullBit(oldp+5564,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0xfffffffff000ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 0xcU))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__x) 
                                   & (IData)((0xfffffffff000ULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 0xcU))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                                     [0x10U] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                                 [0x10U]))));
    bufp->fullBit(oldp+5565,((1U & (IData)((0x7ffffffff800ULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               << 0xbU))))));
    bufp->fullBit(oldp+5566,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                              [0x11U])));
    bufp->fullBit(oldp+5567,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                                    [0x11U] >> 1U))));
    bufp->fullBit(oldp+5568,((1U & (~ (IData)((0x7ffffffff800ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 0xbU)))))));
    bufp->fullBit(oldp+5569,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x7ffffffff800ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 0xbU))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x7ffffffff800ULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 0xbU))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                                     [0x11U] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                                 [0x11U]))));
    bufp->fullBit(oldp+5570,((1U & (IData)((0x3ffffffffc00ULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               << 0xaU))))));
    bufp->fullBit(oldp+5571,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                              [0x12U])));
    bufp->fullBit(oldp+5572,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                                    [0x12U] >> 1U))));
    bufp->fullBit(oldp+5573,((1U & (~ (IData)((0x3ffffffffc00ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 0xaU)))))));
    bufp->fullBit(oldp+5574,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x3ffffffffc00ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 0xaU))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x3ffffffffc00ULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 0xaU))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                                     [0x12U] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                                 [0x12U]))));
    bufp->fullBit(oldp+5575,((1U & (IData)((0x1ffffffffe00ULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               << 9U))))));
    bufp->fullBit(oldp+5576,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                              [0x13U])));
    bufp->fullBit(oldp+5577,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                                    [0x13U] >> 1U))));
    bufp->fullBit(oldp+5578,((1U & (~ (IData)((0x1ffffffffe00ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 9U)))))));
    bufp->fullBit(oldp+5579,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x1ffffffffe00ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 9U))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x1ffffffffe00ULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 9U))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                                     [0x13U] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                                 [0x13U]))));
    bufp->fullBit(oldp+5580,((1U & (IData)((0x7ffffffff8000000ULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               << 0x1bU))))));
    bufp->fullBit(oldp+5581,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                              [1U])));
    bufp->fullBit(oldp+5582,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                                    [1U] >> 1U))));
    bufp->fullBit(oldp+5583,((1U & (~ (IData)((0x7ffffffff8000000ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 0x1bU)))))));
    bufp->fullBit(oldp+5584,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x7ffffffff8000000ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 0x1bU))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x7ffffffff8000000ULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 0x1bU))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                                     [1U] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                                 [1U]))));
    bufp->fullBit(oldp+5585,((1U & (IData)((0xfffffffff00ULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               << 8U))))));
    bufp->fullBit(oldp+5586,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                              [0x14U])));
    bufp->fullBit(oldp+5587,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                                    [0x14U] >> 1U))));
    bufp->fullBit(oldp+5588,((1U & (~ (IData)((0xfffffffff00ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 8U)))))));
    bufp->fullBit(oldp+5589,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0xfffffffff00ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 8U))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__x) 
                                   & (IData)((0xfffffffff00ULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 8U))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                                     [0x14U] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                                 [0x14U]))));
    bufp->fullBit(oldp+5590,((1U & (IData)((0x7ffffffff80ULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               << 7U))))));
    bufp->fullBit(oldp+5591,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                              [0x15U])));
    bufp->fullBit(oldp+5592,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                                    [0x15U] >> 1U))));
    bufp->fullBit(oldp+5593,((1U & (~ (IData)((0x7ffffffff80ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 7U)))))));
    bufp->fullBit(oldp+5594,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x7ffffffff80ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 7U))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x7ffffffff80ULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 7U))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                                     [0x15U] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                                 [0x15U]))));
    bufp->fullBit(oldp+5595,((1U & (IData)((0x3ffffffffc0ULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               << 6U))))));
    bufp->fullBit(oldp+5596,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                              [0x16U])));
    bufp->fullBit(oldp+5597,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                                    [0x16U] >> 1U))));
    bufp->fullBit(oldp+5598,((1U & (~ (IData)((0x3ffffffffc0ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 6U)))))));
    bufp->fullBit(oldp+5599,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x3ffffffffc0ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 6U))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x3ffffffffc0ULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 6U))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                                     [0x16U] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                                 [0x16U]))));
    bufp->fullBit(oldp+5600,((1U & (IData)((0x1ffffffffe0ULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               << 5U))))));
    bufp->fullBit(oldp+5601,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                              [0x17U])));
    bufp->fullBit(oldp+5602,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                                    [0x17U] >> 1U))));
    bufp->fullBit(oldp+5603,((1U & (~ (IData)((0x1ffffffffe0ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 5U)))))));
    bufp->fullBit(oldp+5604,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x1ffffffffe0ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 5U))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x1ffffffffe0ULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 5U))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                                     [0x17U] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                                 [0x17U]))));
    bufp->fullBit(oldp+5605,((1U & (IData)((0xfffffffff0ULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               << 4U))))));
    bufp->fullBit(oldp+5606,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                              [0x18U])));
    bufp->fullBit(oldp+5607,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                                    [0x18U] >> 1U))));
    bufp->fullBit(oldp+5608,((1U & (~ (IData)((0xfffffffff0ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 4U)))))));
    bufp->fullBit(oldp+5609,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0xfffffffff0ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 4U))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__x) 
                                   & (IData)((0xfffffffff0ULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 4U))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                                     [0x18U] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                                 [0x18U]))));
    bufp->fullBit(oldp+5610,((1U & (IData)((0x7ffffffff8ULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               << 3U))))));
    bufp->fullBit(oldp+5611,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                              [0x19U])));
    bufp->fullBit(oldp+5612,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                                    [0x19U] >> 1U))));
    bufp->fullBit(oldp+5613,((1U & (~ (IData)((0x7ffffffff8ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 3U)))))));
    bufp->fullBit(oldp+5614,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x7ffffffff8ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 3U))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x7ffffffff8ULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 3U))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                                     [0x19U] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                                 [0x19U]))));
    bufp->fullBit(oldp+5615,((1U & (IData)((0x3ffffffffcULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               << 2U))))));
    bufp->fullBit(oldp+5616,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                              [0x1aU])));
    bufp->fullBit(oldp+5617,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                                    [0x1aU] >> 1U))));
    bufp->fullBit(oldp+5618,((1U & (~ (IData)((0x3ffffffffcULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 2U)))))));
    bufp->fullBit(oldp+5619,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x3ffffffffcULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 2U))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x3ffffffffcULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 2U))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                                     [0x1aU] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                                 [0x1aU]))));
    bufp->fullBit(oldp+5620,((1U & (IData)((0x1ffffffffeULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               << 1U))))));
    bufp->fullBit(oldp+5621,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                              [0x1bU])));
    bufp->fullBit(oldp+5622,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                                    [0x1bU] >> 1U))));
    bufp->fullBit(oldp+5623,((1U & (~ (IData)((0x1ffffffffeULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 1U)))))));
    bufp->fullBit(oldp+5624,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x1ffffffffeULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 1U))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x1ffffffffeULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 1U))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                                     [0x1bU] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                                 [0x1bU]))));
    bufp->fullBit(oldp+5625,((1U & (IData)((0xfffffffffULL 
                                            & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX)))));
    bufp->fullBit(oldp+5626,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                              [0x1cU])));
    bufp->fullBit(oldp+5627,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                                    [0x1cU] >> 1U))));
    bufp->fullBit(oldp+5628,((1U & (~ (IData)((0xfffffffffULL 
                                               & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX))))));
    bufp->fullBit(oldp+5629,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0xfffffffffULL 
                                               & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX)))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__x) 
                                   & (IData)((0xfffffffffULL 
                                              & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX)))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                                     [0x1cU] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                                 [0x1cU]))));
    bufp->fullBit(oldp+5630,((1U & (IData)((0x7ffffffffULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               >> 1U))))));
    bufp->fullBit(oldp+5631,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                              [0x1dU])));
    bufp->fullBit(oldp+5632,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                                    [0x1dU] >> 1U))));
    bufp->fullBit(oldp+5633,((1U & (~ (IData)((0x7ffffffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 1U)))))));
    bufp->fullBit(oldp+5634,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x7ffffffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 1U))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x7ffffffffULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 1U))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                                     [0x1dU] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                                 [0x1dU]))));
    bufp->fullBit(oldp+5635,((1U & (IData)((0x3ffffffffc000000ULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               << 0x1aU))))));
    bufp->fullBit(oldp+5636,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                              [2U])));
    bufp->fullBit(oldp+5637,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                                    [2U] >> 1U))));
    bufp->fullBit(oldp+5638,((1U & (~ (IData)((0x3ffffffffc000000ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 0x1aU)))))));
    bufp->fullBit(oldp+5639,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x3ffffffffc000000ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 0x1aU))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x3ffffffffc000000ULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 0x1aU))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                                     [2U] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                                 [2U]))));
    bufp->fullBit(oldp+5640,((1U & (IData)((0x3ffffffffULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               >> 2U))))));
    bufp->fullBit(oldp+5641,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                              [0x1eU])));
    bufp->fullBit(oldp+5642,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                                    [0x1eU] >> 1U))));
    bufp->fullBit(oldp+5643,((1U & (~ (IData)((0x3ffffffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 2U)))))));
    bufp->fullBit(oldp+5644,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x3ffffffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 2U))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x3ffffffffULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 2U))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                                     [0x1eU] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                                 [0x1eU]))));
    bufp->fullBit(oldp+5645,((1U & (IData)((0x1ffffffffULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               >> 3U))))));
    bufp->fullBit(oldp+5646,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                              [0x1fU])));
    bufp->fullBit(oldp+5647,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                                    [0x1fU] >> 1U))));
    bufp->fullBit(oldp+5648,((1U & (~ (IData)((0x1ffffffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 3U)))))));
    bufp->fullBit(oldp+5649,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x1ffffffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 3U))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x1ffffffffULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 3U))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                                     [0x1fU] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                                 [0x1fU]))));
    bufp->fullBit(oldp+5650,((1U & (IData)((0xffffffffULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               >> 4U))))));
    bufp->fullBit(oldp+5651,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                              [0x20U])));
    bufp->fullBit(oldp+5652,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                                    [0x20U] >> 1U))));
    bufp->fullBit(oldp+5653,((1U & (~ (IData)((0xffffffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 4U)))))));
    bufp->fullBit(oldp+5654,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0xffffffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 4U))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__x) 
                                   & (IData)((0xffffffffULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 4U))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                                     [0x20U] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                                 [0x20U]))));
    bufp->fullBit(oldp+5655,((1U & (IData)((0x7fffffffULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               >> 5U))))));
    bufp->fullBit(oldp+5656,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                              [0x21U])));
    bufp->fullBit(oldp+5657,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                                    [0x21U] >> 1U))));
    bufp->fullBit(oldp+5658,((1U & (~ (IData)((0x7fffffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 5U)))))));
    bufp->fullBit(oldp+5659,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x7fffffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 5U))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x7fffffffULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 5U))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                                     [0x21U] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                                 [0x21U]))));
    bufp->fullBit(oldp+5660,((1U & (IData)((0x3fffffffULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               >> 6U))))));
    bufp->fullBit(oldp+5661,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                              [0x22U])));
    bufp->fullBit(oldp+5662,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                                    [0x22U] >> 1U))));
    bufp->fullBit(oldp+5663,((1U & (~ (IData)((0x3fffffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 6U)))))));
    bufp->fullBit(oldp+5664,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x3fffffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 6U))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x3fffffffULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 6U))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                                     [0x22U] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                                 [0x22U]))));
    bufp->fullBit(oldp+5665,((1U & (IData)((0x1fffffffULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               >> 7U))))));
    bufp->fullBit(oldp+5666,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                              [0x23U])));
    bufp->fullBit(oldp+5667,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                                    [0x23U] >> 1U))));
    bufp->fullBit(oldp+5668,((1U & (~ (IData)((0x1fffffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 7U)))))));
    bufp->fullBit(oldp+5669,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x1fffffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 7U))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x1fffffffULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 7U))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                                     [0x23U] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                                 [0x23U]))));
    bufp->fullBit(oldp+5670,((1U & (IData)((0xfffffffULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               >> 8U))))));
    bufp->fullBit(oldp+5671,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                              [0x24U])));
    bufp->fullBit(oldp+5672,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                                    [0x24U] >> 1U))));
    bufp->fullBit(oldp+5673,((1U & (~ (IData)((0xfffffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 8U)))))));
    bufp->fullBit(oldp+5674,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0xfffffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 8U))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__x) 
                                   & (IData)((0xfffffffULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 8U))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                                     [0x24U] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                                 [0x24U]))));
    bufp->fullBit(oldp+5675,((1U & (IData)((0x7ffffffULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               >> 9U))))));
    bufp->fullBit(oldp+5676,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                              [0x25U])));
    bufp->fullBit(oldp+5677,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                                    [0x25U] >> 1U))));
    bufp->fullBit(oldp+5678,((1U & (~ (IData)((0x7ffffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 9U)))))));
    bufp->fullBit(oldp+5679,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x7ffffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 9U))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x7ffffffULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 9U))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                                     [0x25U] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                                 [0x25U]))));
    bufp->fullBit(oldp+5680,((1U & (IData)((0x3ffffffULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               >> 0xaU))))));
    bufp->fullBit(oldp+5681,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                              [0x26U])));
    bufp->fullBit(oldp+5682,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                                    [0x26U] >> 1U))));
    bufp->fullBit(oldp+5683,((1U & (~ (IData)((0x3ffffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0xaU)))))));
    bufp->fullBit(oldp+5684,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x3ffffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0xaU))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x3ffffffULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0xaU))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                                     [0x26U] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                                 [0x26U]))));
    bufp->fullBit(oldp+5685,((1U & (IData)((0x1ffffffULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               >> 0xbU))))));
    bufp->fullBit(oldp+5686,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                              [0x27U])));
    bufp->fullBit(oldp+5687,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                                    [0x27U] >> 1U))));
    bufp->fullBit(oldp+5688,((1U & (~ (IData)((0x1ffffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0xbU)))))));
    bufp->fullBit(oldp+5689,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x1ffffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0xbU))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x1ffffffULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0xbU))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                                     [0x27U] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                                 [0x27U]))));
    bufp->fullBit(oldp+5690,((1U & (IData)((0x1ffffffffe000000ULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               << 0x19U))))));
    bufp->fullBit(oldp+5691,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                              [3U])));
    bufp->fullBit(oldp+5692,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                                    [3U] >> 1U))));
    bufp->fullBit(oldp+5693,((1U & (~ (IData)((0x1ffffffffe000000ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 0x19U)))))));
    bufp->fullBit(oldp+5694,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x1ffffffffe000000ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 0x19U))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x1ffffffffe000000ULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 0x19U))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                                     [3U] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                                 [3U]))));
    bufp->fullBit(oldp+5695,((1U & (IData)((0xffffffULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               >> 0xcU))))));
    bufp->fullBit(oldp+5696,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                              [0x28U])));
    bufp->fullBit(oldp+5697,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                                    [0x28U] >> 1U))));
    bufp->fullBit(oldp+5698,((1U & (~ (IData)((0xffffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0xcU)))))));
    bufp->fullBit(oldp+5699,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0xffffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0xcU))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__x) 
                                   & (IData)((0xffffffULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0xcU))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                                     [0x28U] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                                 [0x28U]))));
    bufp->fullBit(oldp+5700,((1U & (IData)((0x7fffffULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               >> 0xdU))))));
    bufp->fullBit(oldp+5701,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                              [0x29U])));
    bufp->fullBit(oldp+5702,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                                    [0x29U] >> 1U))));
    bufp->fullBit(oldp+5703,((1U & (~ (IData)((0x7fffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0xdU)))))));
    bufp->fullBit(oldp+5704,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x7fffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0xdU))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x7fffffULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0xdU))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                                     [0x29U] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                                 [0x29U]))));
    bufp->fullBit(oldp+5705,((1U & (IData)((0x3fffffULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               >> 0xeU))))));
    bufp->fullBit(oldp+5706,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                              [0x2aU])));
    bufp->fullBit(oldp+5707,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                                    [0x2aU] >> 1U))));
    bufp->fullBit(oldp+5708,((1U & (~ (IData)((0x3fffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0xeU)))))));
    bufp->fullBit(oldp+5709,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x3fffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0xeU))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x3fffffULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0xeU))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                                     [0x2aU] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                                 [0x2aU]))));
    bufp->fullBit(oldp+5710,((1U & (IData)((0x1fffffULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               >> 0xfU))))));
    bufp->fullBit(oldp+5711,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                              [0x2bU])));
    bufp->fullBit(oldp+5712,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                                    [0x2bU] >> 1U))));
    bufp->fullBit(oldp+5713,((1U & (~ (IData)((0x1fffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0xfU)))))));
    bufp->fullBit(oldp+5714,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x1fffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0xfU))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x1fffffULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0xfU))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                                     [0x2bU] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                                 [0x2bU]))));
    bufp->fullBit(oldp+5715,((1U & (IData)((0xfffffULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               >> 0x10U))))));
    bufp->fullBit(oldp+5716,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                              [0x2cU])));
    bufp->fullBit(oldp+5717,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                                    [0x2cU] >> 1U))));
    bufp->fullBit(oldp+5718,((1U & (~ (IData)((0xfffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x10U)))))));
    bufp->fullBit(oldp+5719,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0xfffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x10U))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__x) 
                                   & (IData)((0xfffffULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x10U))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                                     [0x2cU] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                                 [0x2cU]))));
    bufp->fullBit(oldp+5720,((1U & (IData)((0x7ffffULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               >> 0x11U))))));
    bufp->fullBit(oldp+5721,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                              [0x2dU])));
    bufp->fullBit(oldp+5722,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                                    [0x2dU] >> 1U))));
    bufp->fullBit(oldp+5723,((1U & (~ (IData)((0x7ffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x11U)))))));
    bufp->fullBit(oldp+5724,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x7ffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x11U))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x7ffffULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x11U))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                                     [0x2dU] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                                 [0x2dU]))));
    bufp->fullBit(oldp+5725,((1U & (IData)((0x3ffffULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               >> 0x12U))))));
    bufp->fullBit(oldp+5726,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                              [0x2eU])));
    bufp->fullBit(oldp+5727,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                                    [0x2eU] >> 1U))));
    bufp->fullBit(oldp+5728,((1U & (~ (IData)((0x3ffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x12U)))))));
    bufp->fullBit(oldp+5729,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x3ffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x12U))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x3ffffULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x12U))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                                     [0x2eU] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                                 [0x2eU]))));
    bufp->fullBit(oldp+5730,((1U & (IData)((0x1ffffULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               >> 0x13U))))));
    bufp->fullBit(oldp+5731,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                              [0x2fU])));
    bufp->fullBit(oldp+5732,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                                    [0x2fU] >> 1U))));
    bufp->fullBit(oldp+5733,((1U & (~ (IData)((0x1ffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x13U)))))));
    bufp->fullBit(oldp+5734,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x1ffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x13U))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x1ffffULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x13U))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                                     [0x2fU] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                                 [0x2fU]))));
    bufp->fullBit(oldp+5735,((1U & (IData)((0xffffULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               >> 0x14U))))));
    bufp->fullBit(oldp+5736,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                              [0x30U])));
    bufp->fullBit(oldp+5737,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                                    [0x30U] >> 1U))));
    bufp->fullBit(oldp+5738,((1U & (~ (IData)((0xffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x14U)))))));
    bufp->fullBit(oldp+5739,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0xffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x14U))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__x) 
                                   & (IData)((0xffffULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x14U))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                                     [0x30U] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                                 [0x30U]))));
    bufp->fullBit(oldp+5740,((1U & (IData)((0x7fffULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               >> 0x15U))))));
    bufp->fullBit(oldp+5741,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                              [0x31U])));
    bufp->fullBit(oldp+5742,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                                    [0x31U] >> 1U))));
    bufp->fullBit(oldp+5743,((1U & (~ (IData)((0x7fffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x15U)))))));
    bufp->fullBit(oldp+5744,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x7fffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x15U))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x7fffULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x15U))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                                     [0x31U] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                                 [0x31U]))));
    bufp->fullBit(oldp+5745,((1U & (IData)((0xfffffffff000000ULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               << 0x18U))))));
    bufp->fullBit(oldp+5746,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                              [4U])));
    bufp->fullBit(oldp+5747,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                                    [4U] >> 1U))));
    bufp->fullBit(oldp+5748,((1U & (~ (IData)((0xfffffffff000000ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 0x18U)))))));
    bufp->fullBit(oldp+5749,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0xfffffffff000000ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 0x18U))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__x) 
                                   & (IData)((0xfffffffff000000ULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 0x18U))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                                     [4U] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                                 [4U]))));
    bufp->fullBit(oldp+5750,((1U & (IData)((0x3fffULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               >> 0x16U))))));
    bufp->fullBit(oldp+5751,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                              [0x32U])));
    bufp->fullBit(oldp+5752,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                                    [0x32U] >> 1U))));
    bufp->fullBit(oldp+5753,((1U & (~ (IData)((0x3fffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x16U)))))));
    bufp->fullBit(oldp+5754,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x3fffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x16U))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x3fffULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x16U))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                                     [0x32U] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                                 [0x32U]))));
    bufp->fullBit(oldp+5755,((1U & (IData)((0x1fffULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               >> 0x17U))))));
    bufp->fullBit(oldp+5756,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                              [0x33U])));
    bufp->fullBit(oldp+5757,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                                    [0x33U] >> 1U))));
    bufp->fullBit(oldp+5758,((1U & (~ (IData)((0x1fffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x17U)))))));
    bufp->fullBit(oldp+5759,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x1fffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x17U))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x1fffULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x17U))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                                     [0x33U] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                                 [0x33U]))));
    bufp->fullBit(oldp+5760,((1U & (IData)((0xfffULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               >> 0x18U))))));
    bufp->fullBit(oldp+5761,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                              [0x34U])));
    bufp->fullBit(oldp+5762,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                                    [0x34U] >> 1U))));
    bufp->fullBit(oldp+5763,((1U & (~ (IData)((0xfffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x18U)))))));
    bufp->fullBit(oldp+5764,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0xfffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x18U))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__x) 
                                   & (IData)((0xfffULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x18U))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                                     [0x34U] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                                 [0x34U]))));
    bufp->fullBit(oldp+5765,((1U & (IData)((0x7ffULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               >> 0x19U))))));
    bufp->fullBit(oldp+5766,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                              [0x35U])));
    bufp->fullBit(oldp+5767,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                                    [0x35U] >> 1U))));
    bufp->fullBit(oldp+5768,((1U & (~ (IData)((0x7ffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x19U)))))));
    bufp->fullBit(oldp+5769,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x7ffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x19U))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x7ffULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x19U))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                                     [0x35U] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                                 [0x35U]))));
    bufp->fullBit(oldp+5770,((1U & (IData)((0x3ffULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               >> 0x1aU))))));
    bufp->fullBit(oldp+5771,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                              [0x36U])));
    bufp->fullBit(oldp+5772,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                                    [0x36U] >> 1U))));
    bufp->fullBit(oldp+5773,((1U & (~ (IData)((0x3ffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x1aU)))))));
    bufp->fullBit(oldp+5774,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x3ffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x1aU))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x3ffULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x1aU))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                                     [0x36U] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                                 [0x36U]))));
    bufp->fullBit(oldp+5775,((1U & (IData)((0x1ffULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               >> 0x1bU))))));
    bufp->fullBit(oldp+5776,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                              [0x37U])));
    bufp->fullBit(oldp+5777,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                                    [0x37U] >> 1U))));
    bufp->fullBit(oldp+5778,((1U & (~ (IData)((0x1ffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x1bU)))))));
    bufp->fullBit(oldp+5779,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x1ffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x1bU))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x1ffULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x1bU))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                                     [0x37U] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                                 [0x37U]))));
    bufp->fullBit(oldp+5780,((1U & (IData)((0xffULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               >> 0x1cU))))));
    bufp->fullBit(oldp+5781,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                              [0x38U])));
    bufp->fullBit(oldp+5782,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                                    [0x38U] >> 1U))));
    bufp->fullBit(oldp+5783,((1U & (~ (IData)((0xffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x1cU)))))));
    bufp->fullBit(oldp+5784,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0xffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x1cU))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__x) 
                                   & (IData)((0xffULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x1cU))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                                     [0x38U] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                                 [0x38U]))));
    bufp->fullBit(oldp+5785,((1U & (IData)((0x7fULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               >> 0x1dU))))));
    bufp->fullBit(oldp+5786,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                              [0x39U])));
    bufp->fullBit(oldp+5787,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                                    [0x39U] >> 1U))));
    bufp->fullBit(oldp+5788,((1U & (~ (IData)((0x7fULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x1dU)))))));
    bufp->fullBit(oldp+5789,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x7fULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x1dU))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x7fULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x1dU))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                                     [0x39U] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                                 [0x39U]))));
    bufp->fullBit(oldp+5790,((1U & (IData)((0x3fULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               >> 0x1eU))))));
    bufp->fullBit(oldp+5791,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                              [0x3aU])));
    bufp->fullBit(oldp+5792,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                                    [0x3aU] >> 1U))));
    bufp->fullBit(oldp+5793,((1U & (~ (IData)((0x3fULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x1eU)))))));
    bufp->fullBit(oldp+5794,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x3fULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x1eU))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x3fULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x1eU))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                                     [0x3aU] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                                 [0x3aU]))));
    bufp->fullBit(oldp+5795,((1U & (IData)((0x1fULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               >> 0x1fU))))));
    bufp->fullBit(oldp+5796,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                              [0x3bU])));
    bufp->fullBit(oldp+5797,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                                    [0x3bU] >> 1U))));
    bufp->fullBit(oldp+5798,((1U & (~ (IData)((0x1fULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x1fU)))))));
    bufp->fullBit(oldp+5799,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x1fULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x1fU))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x1fULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x1fU))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                                     [0x3bU] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                                 [0x3bU]))));
    bufp->fullBit(oldp+5800,((1U & (IData)((0x7ffffffff800000ULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               << 0x17U))))));
    bufp->fullBit(oldp+5801,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                              [5U])));
    bufp->fullBit(oldp+5802,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                                    [5U] >> 1U))));
    bufp->fullBit(oldp+5803,((1U & (~ (IData)((0x7ffffffff800000ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 0x17U)))))));
    bufp->fullBit(oldp+5804,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x7ffffffff800000ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 0x17U))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x7ffffffff800000ULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 0x17U))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                                     [5U] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                                 [5U]))));
    bufp->fullBit(oldp+5805,((1U & (IData)((0xfULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               >> 0x20U))))));
    bufp->fullBit(oldp+5806,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                              [0x3cU])));
    bufp->fullBit(oldp+5807,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                                    [0x3cU] >> 1U))));
    bufp->fullBit(oldp+5808,((1U & (~ (IData)((0xfULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x20U)))))));
    bufp->fullBit(oldp+5809,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0xfULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x20U))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__x) 
                                   & (IData)((0xfULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x20U))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                                     [0x3cU] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                                 [0x3cU]))));
    bufp->fullBit(oldp+5810,((1U & (IData)((7ULL & 
                                            (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                             >> 0x21U))))));
    bufp->fullBit(oldp+5811,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                              [0x3dU])));
    bufp->fullBit(oldp+5812,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                                    [0x3dU] >> 1U))));
    bufp->fullBit(oldp+5813,((1U & (~ (IData)((7ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x21U)))))));
    bufp->fullBit(oldp+5814,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((7ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x21U))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__x) 
                                   & (IData)((7ULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x21U))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                                     [0x3dU] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                                 [0x3dU]))));
    bufp->fullBit(oldp+5815,((1U & (IData)((3ULL & 
                                            (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                             >> 0x22U))))));
    bufp->fullBit(oldp+5816,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                              [0x3eU])));
    bufp->fullBit(oldp+5817,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                                    [0x3eU] >> 1U))));
    bufp->fullBit(oldp+5818,((1U & (~ (IData)((3ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x22U)))))));
    bufp->fullBit(oldp+5819,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((3ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x22U))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__x) 
                                   & (IData)((3ULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x22U))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                                     [0x3eU] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                                 [0x3eU]))));
    bufp->fullBit(oldp+5820,((1U & (IData)((1ULL & 
                                            (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                             >> 0x23U))))));
    bufp->fullBit(oldp+5821,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                              [0x3fU])));
    bufp->fullBit(oldp+5822,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                                    [0x3fU] >> 1U))));
    bufp->fullBit(oldp+5823,((1U & (~ (IData)((1ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x23U)))))));
    bufp->fullBit(oldp+5824,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((1ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x23U))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__x) 
                                   & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                      >> 0x23U))) | 
                               ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__neg2x) 
                                & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                                   [0x3fU] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                                 [0x3fU]))));
    bufp->fullBit(oldp+5825,((1U & (IData)((0x3ffffffffc00000ULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               << 0x16U))))));
    bufp->fullBit(oldp+5826,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                              [6U])));
    bufp->fullBit(oldp+5827,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                                    [6U] >> 1U))));
    bufp->fullBit(oldp+5828,((1U & (~ (IData)((0x3ffffffffc00000ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 0x16U)))))));
    bufp->fullBit(oldp+5829,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x3ffffffffc00000ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 0x16U))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x3ffffffffc00000ULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 0x16U))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                                     [6U] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                                 [6U]))));
    bufp->fullBit(oldp+5830,((1U & (IData)((0x1ffffffffe00000ULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               << 0x15U))))));
    bufp->fullBit(oldp+5831,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                              [7U])));
    bufp->fullBit(oldp+5832,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                                    [7U] >> 1U))));
    bufp->fullBit(oldp+5833,((1U & (~ (IData)((0x1ffffffffe00000ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 0x15U)))))));
    bufp->fullBit(oldp+5834,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x1ffffffffe00000ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 0x15U))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x1ffffffffe00000ULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 0x15U))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                                     [7U] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                                 [7U]))));
    bufp->fullBit(oldp+5835,((1U & (IData)((0xfffffffff00000ULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               << 0x14U))))));
    bufp->fullBit(oldp+5836,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                              [8U])));
    bufp->fullBit(oldp+5837,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                                    [8U] >> 1U))));
    bufp->fullBit(oldp+5838,((1U & (~ (IData)((0xfffffffff00000ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 0x14U)))))));
    bufp->fullBit(oldp+5839,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0xfffffffff00000ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 0x14U))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__x) 
                                   & (IData)((0xfffffffff00000ULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 0x14U))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                                     [8U] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                                 [8U]))));
    bufp->fullBit(oldp+5840,((1U & (IData)((0x7ffffffff80000ULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               << 0x13U))))));
    bufp->fullBit(oldp+5841,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                              [9U])));
    bufp->fullBit(oldp+5842,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                                    [9U] >> 1U))));
    bufp->fullBit(oldp+5843,((1U & (~ (IData)((0x7ffffffff80000ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 0x13U)))))));
    bufp->fullBit(oldp+5844,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x7ffffffff80000ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 0x13U))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x7ffffffff80000ULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 0x13U))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                                     [9U] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__28__KET____DOT__ai__DOT__CarrySig
                                 [9U]))));
    bufp->fullBit(oldp+5845,((1U & (IData)((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalY 
                                            >> 0x1dU)))));
    bufp->fullBit(oldp+5846,((1U & (IData)((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalY 
                                            >> 0x1cU)))));
    bufp->fullCData(oldp+5847,((7U & (IData)((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalY 
                                              >> 1U)))),3);
    bufp->fullQData(oldp+5848,((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                << 2U)),64);
    bufp->fullQData(oldp+5850,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellout__boothfor__BRA__2__KET____DOT__ai__OutX),64);
    bufp->fullBit(oldp+5852,(((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__negx) 
                              | (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__neg2x))));
    bufp->fullBit(oldp+5853,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__negx));
    bufp->fullBit(oldp+5854,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__x));
    bufp->fullBit(oldp+5855,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__neg2x));
    bufp->fullBit(oldp+5856,((1U & (IData)((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                            << 2U)))));
    bufp->fullBit(oldp+5857,((1U & (~ (IData)((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               << 2U))))));
    bufp->fullBit(oldp+5858,(((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__negx) 
                                & (~ (IData)((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                              << 2U)))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__x) 
                                  & (IData)((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                             << 2U)))) 
                              | (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__neg2x))));
    bufp->fullBit(oldp+5859,((1U & (IData)((0x3fffffffffffffULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               >> 8U))))));
    bufp->fullBit(oldp+5860,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                              [0xaU])));
    bufp->fullBit(oldp+5861,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                                    [0xaU] >> 1U))));
    bufp->fullBit(oldp+5862,((1U & (~ (IData)((0x3fffffffffffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 8U)))))));
    bufp->fullBit(oldp+5863,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x3fffffffffffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 8U))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x3fffffffffffffULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 8U))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                                     [0xaU] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                                 [0xaU]))));
    bufp->fullBit(oldp+5864,((1U & (IData)((0x1fffffffffffffULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               >> 9U))))));
    bufp->fullBit(oldp+5865,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                              [0xbU])));
    bufp->fullBit(oldp+5866,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                                    [0xbU] >> 1U))));
    bufp->fullBit(oldp+5867,((1U & (~ (IData)((0x1fffffffffffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 9U)))))));
    bufp->fullBit(oldp+5868,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x1fffffffffffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 9U))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x1fffffffffffffULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 9U))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                                     [0xbU] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                                 [0xbU]))));
    bufp->fullBit(oldp+5869,((1U & (IData)((0xfffffffffffffULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               >> 0xaU))))));
    bufp->fullBit(oldp+5870,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                              [0xcU])));
    bufp->fullBit(oldp+5871,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                                    [0xcU] >> 1U))));
    bufp->fullBit(oldp+5872,((1U & (~ (IData)((0xfffffffffffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0xaU)))))));
    bufp->fullBit(oldp+5873,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0xfffffffffffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0xaU))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__x) 
                                   & (IData)((0xfffffffffffffULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0xaU))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                                     [0xcU] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                                 [0xcU]))));
    bufp->fullBit(oldp+5874,((1U & (IData)((0x7ffffffffffffULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               >> 0xbU))))));
    bufp->fullBit(oldp+5875,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                              [0xdU])));
    bufp->fullBit(oldp+5876,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                                    [0xdU] >> 1U))));
    bufp->fullBit(oldp+5877,((1U & (~ (IData)((0x7ffffffffffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0xbU)))))));
    bufp->fullBit(oldp+5878,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x7ffffffffffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0xbU))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x7ffffffffffffULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0xbU))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                                     [0xdU] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                                 [0xdU]))));
    bufp->fullBit(oldp+5879,((1U & (IData)((0x3ffffffffffffULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               >> 0xcU))))));
    bufp->fullBit(oldp+5880,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                              [0xeU])));
    bufp->fullBit(oldp+5881,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                                    [0xeU] >> 1U))));
    bufp->fullBit(oldp+5882,((1U & (~ (IData)((0x3ffffffffffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0xcU)))))));
    bufp->fullBit(oldp+5883,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x3ffffffffffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0xcU))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x3ffffffffffffULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0xcU))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                                     [0xeU] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                                 [0xeU]))));
    bufp->fullBit(oldp+5884,((1U & (IData)((0x1ffffffffffffULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               >> 0xdU))))));
    bufp->fullBit(oldp+5885,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                              [0xfU])));
    bufp->fullBit(oldp+5886,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                                    [0xfU] >> 1U))));
    bufp->fullBit(oldp+5887,((1U & (~ (IData)((0x1ffffffffffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0xdU)))))));
    bufp->fullBit(oldp+5888,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x1ffffffffffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0xdU))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x1ffffffffffffULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0xdU))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                                     [0xfU] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                                 [0xfU]))));
    bufp->fullBit(oldp+5889,((1U & (IData)((0xffffffffffffULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               >> 0xeU))))));
    bufp->fullBit(oldp+5890,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                              [0x10U])));
    bufp->fullBit(oldp+5891,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                                    [0x10U] >> 1U))));
    bufp->fullBit(oldp+5892,((1U & (~ (IData)((0xffffffffffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0xeU)))))));
    bufp->fullBit(oldp+5893,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0xffffffffffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0xeU))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__x) 
                                   & (IData)((0xffffffffffffULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0xeU))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                                     [0x10U] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                                 [0x10U]))));
    bufp->fullBit(oldp+5894,((1U & (IData)((0x7fffffffffffULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               >> 0xfU))))));
    bufp->fullBit(oldp+5895,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                              [0x11U])));
    bufp->fullBit(oldp+5896,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                                    [0x11U] >> 1U))));
    bufp->fullBit(oldp+5897,((1U & (~ (IData)((0x7fffffffffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0xfU)))))));
    bufp->fullBit(oldp+5898,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x7fffffffffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0xfU))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x7fffffffffffULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0xfU))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                                     [0x11U] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                                 [0x11U]))));
    bufp->fullBit(oldp+5899,((1U & (IData)((0x3fffffffffffULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               >> 0x10U))))));
    bufp->fullBit(oldp+5900,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                              [0x12U])));
    bufp->fullBit(oldp+5901,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                                    [0x12U] >> 1U))));
    bufp->fullBit(oldp+5902,((1U & (~ (IData)((0x3fffffffffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x10U)))))));
    bufp->fullBit(oldp+5903,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x3fffffffffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x10U))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x3fffffffffffULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x10U))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                                     [0x12U] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                                 [0x12U]))));
    bufp->fullBit(oldp+5904,((1U & (IData)((0x1fffffffffffULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               >> 0x11U))))));
    bufp->fullBit(oldp+5905,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                              [0x13U])));
    bufp->fullBit(oldp+5906,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                                    [0x13U] >> 1U))));
    bufp->fullBit(oldp+5907,((1U & (~ (IData)((0x1fffffffffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x11U)))))));
    bufp->fullBit(oldp+5908,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x1fffffffffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x11U))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x1fffffffffffULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x11U))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                                     [0x13U] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                                 [0x13U]))));
    bufp->fullBit(oldp+5909,((1U & (IData)((0x7ffffffffffffffeULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               << 1U))))));
    bufp->fullBit(oldp+5910,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                              [1U])));
    bufp->fullBit(oldp+5911,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                                    [1U] >> 1U))));
    bufp->fullBit(oldp+5912,((1U & (~ (IData)((0x7ffffffffffffffeULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 1U)))))));
    bufp->fullBit(oldp+5913,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x7ffffffffffffffeULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 1U))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x7ffffffffffffffeULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 1U))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                                     [1U] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                                 [1U]))));
    bufp->fullBit(oldp+5914,((1U & (IData)((0xfffffffffffULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               >> 0x12U))))));
    bufp->fullBit(oldp+5915,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                              [0x14U])));
    bufp->fullBit(oldp+5916,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                                    [0x14U] >> 1U))));
    bufp->fullBit(oldp+5917,((1U & (~ (IData)((0xfffffffffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x12U)))))));
    bufp->fullBit(oldp+5918,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0xfffffffffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x12U))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__x) 
                                   & (IData)((0xfffffffffffULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x12U))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                                     [0x14U] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                                 [0x14U]))));
    bufp->fullBit(oldp+5919,((1U & (IData)((0x7ffffffffffULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               >> 0x13U))))));
    bufp->fullBit(oldp+5920,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                              [0x15U])));
    bufp->fullBit(oldp+5921,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                                    [0x15U] >> 1U))));
    bufp->fullBit(oldp+5922,((1U & (~ (IData)((0x7ffffffffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x13U)))))));
    bufp->fullBit(oldp+5923,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x7ffffffffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x13U))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x7ffffffffffULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x13U))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                                     [0x15U] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                                 [0x15U]))));
    bufp->fullBit(oldp+5924,((1U & (IData)((0x3ffffffffffULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               >> 0x14U))))));
    bufp->fullBit(oldp+5925,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                              [0x16U])));
    bufp->fullBit(oldp+5926,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                                    [0x16U] >> 1U))));
    bufp->fullBit(oldp+5927,((1U & (~ (IData)((0x3ffffffffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x14U)))))));
    bufp->fullBit(oldp+5928,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x3ffffffffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x14U))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x3ffffffffffULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x14U))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                                     [0x16U] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                                 [0x16U]))));
    bufp->fullBit(oldp+5929,((1U & (IData)((0x1ffffffffffULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               >> 0x15U))))));
    bufp->fullBit(oldp+5930,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                              [0x17U])));
    bufp->fullBit(oldp+5931,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                                    [0x17U] >> 1U))));
    bufp->fullBit(oldp+5932,((1U & (~ (IData)((0x1ffffffffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x15U)))))));
    bufp->fullBit(oldp+5933,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x1ffffffffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x15U))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x1ffffffffffULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x15U))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                                     [0x17U] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                                 [0x17U]))));
    bufp->fullBit(oldp+5934,((1U & (IData)((0xffffffffffULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               >> 0x16U))))));
    bufp->fullBit(oldp+5935,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                              [0x18U])));
    bufp->fullBit(oldp+5936,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                                    [0x18U] >> 1U))));
    bufp->fullBit(oldp+5937,((1U & (~ (IData)((0xffffffffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x16U)))))));
    bufp->fullBit(oldp+5938,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0xffffffffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x16U))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__x) 
                                   & (IData)((0xffffffffffULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x16U))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                                     [0x18U] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                                 [0x18U]))));
    bufp->fullBit(oldp+5939,((1U & (IData)((0x7fffffffffULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               >> 0x17U))))));
    bufp->fullBit(oldp+5940,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                              [0x19U])));
    bufp->fullBit(oldp+5941,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                                    [0x19U] >> 1U))));
    bufp->fullBit(oldp+5942,((1U & (~ (IData)((0x7fffffffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x17U)))))));
    bufp->fullBit(oldp+5943,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x7fffffffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x17U))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x7fffffffffULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x17U))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                                     [0x19U] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                                 [0x19U]))));
    bufp->fullBit(oldp+5944,((1U & (IData)((0x3fffffffffULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               >> 0x18U))))));
    bufp->fullBit(oldp+5945,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                              [0x1aU])));
    bufp->fullBit(oldp+5946,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                                    [0x1aU] >> 1U))));
    bufp->fullBit(oldp+5947,((1U & (~ (IData)((0x3fffffffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x18U)))))));
    bufp->fullBit(oldp+5948,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x3fffffffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x18U))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x3fffffffffULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x18U))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                                     [0x1aU] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                                 [0x1aU]))));
    bufp->fullBit(oldp+5949,((1U & (IData)((0x1fffffffffULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               >> 0x19U))))));
    bufp->fullBit(oldp+5950,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                              [0x1bU])));
    bufp->fullBit(oldp+5951,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                                    [0x1bU] >> 1U))));
    bufp->fullBit(oldp+5952,((1U & (~ (IData)((0x1fffffffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x19U)))))));
    bufp->fullBit(oldp+5953,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x1fffffffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x19U))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x1fffffffffULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x19U))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                                     [0x1bU] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                                 [0x1bU]))));
    bufp->fullBit(oldp+5954,((1U & (IData)((0xfffffffffULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               >> 0x1aU))))));
    bufp->fullBit(oldp+5955,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                              [0x1cU])));
    bufp->fullBit(oldp+5956,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                                    [0x1cU] >> 1U))));
    bufp->fullBit(oldp+5957,((1U & (~ (IData)((0xfffffffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x1aU)))))));
    bufp->fullBit(oldp+5958,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0xfffffffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x1aU))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__x) 
                                   & (IData)((0xfffffffffULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x1aU))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                                     [0x1cU] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                                 [0x1cU]))));
    bufp->fullBit(oldp+5959,((1U & (IData)((0x7ffffffffULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               >> 0x1bU))))));
    bufp->fullBit(oldp+5960,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                              [0x1dU])));
    bufp->fullBit(oldp+5961,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                                    [0x1dU] >> 1U))));
    bufp->fullBit(oldp+5962,((1U & (~ (IData)((0x7ffffffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x1bU)))))));
    bufp->fullBit(oldp+5963,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x7ffffffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x1bU))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x7ffffffffULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x1bU))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                                     [0x1dU] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                                 [0x1dU]))));
    bufp->fullBit(oldp+5964,((1U & (IData)((0x3fffffffffffffffULL 
                                            & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX)))));
    bufp->fullBit(oldp+5965,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                              [2U])));
    bufp->fullBit(oldp+5966,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                                    [2U] >> 1U))));
    bufp->fullBit(oldp+5967,((1U & (~ (IData)((0x3fffffffffffffffULL 
                                               & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX))))));
    bufp->fullBit(oldp+5968,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x3fffffffffffffffULL 
                                               & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX)))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x3fffffffffffffffULL 
                                              & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX)))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                                     [2U] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                                 [2U]))));
    bufp->fullBit(oldp+5969,((1U & (IData)((0x3ffffffffULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               >> 0x1cU))))));
    bufp->fullBit(oldp+5970,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                              [0x1eU])));
    bufp->fullBit(oldp+5971,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                                    [0x1eU] >> 1U))));
    bufp->fullBit(oldp+5972,((1U & (~ (IData)((0x3ffffffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x1cU)))))));
    bufp->fullBit(oldp+5973,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x3ffffffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x1cU))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x3ffffffffULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x1cU))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                                     [0x1eU] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                                 [0x1eU]))));
    bufp->fullBit(oldp+5974,((1U & (IData)((0x1ffffffffULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               >> 0x1dU))))));
    bufp->fullBit(oldp+5975,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                              [0x1fU])));
    bufp->fullBit(oldp+5976,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                                    [0x1fU] >> 1U))));
    bufp->fullBit(oldp+5977,((1U & (~ (IData)((0x1ffffffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x1dU)))))));
    bufp->fullBit(oldp+5978,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x1ffffffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x1dU))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x1ffffffffULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x1dU))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                                     [0x1fU] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                                 [0x1fU]))));
    bufp->fullBit(oldp+5979,((1U & (IData)((0xffffffffULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               >> 0x1eU))))));
    bufp->fullBit(oldp+5980,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                              [0x20U])));
    bufp->fullBit(oldp+5981,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                                    [0x20U] >> 1U))));
    bufp->fullBit(oldp+5982,((1U & (~ (IData)((0xffffffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x1eU)))))));
    bufp->fullBit(oldp+5983,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0xffffffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x1eU))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__x) 
                                   & (IData)((0xffffffffULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x1eU))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                                     [0x20U] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                                 [0x20U]))));
    bufp->fullBit(oldp+5984,((1U & (IData)((0x7fffffffULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               >> 0x1fU))))));
    bufp->fullBit(oldp+5985,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                              [0x21U])));
    bufp->fullBit(oldp+5986,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                                    [0x21U] >> 1U))));
    bufp->fullBit(oldp+5987,((1U & (~ (IData)((0x7fffffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x1fU)))))));
    bufp->fullBit(oldp+5988,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x7fffffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x1fU))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x7fffffffULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x1fU))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                                     [0x21U] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                                 [0x21U]))));
    bufp->fullBit(oldp+5989,((1U & (IData)((0x3fffffffULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               >> 0x20U))))));
    bufp->fullBit(oldp+5990,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                              [0x22U])));
    bufp->fullBit(oldp+5991,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                                    [0x22U] >> 1U))));
    bufp->fullBit(oldp+5992,((1U & (~ (IData)((0x3fffffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x20U)))))));
    bufp->fullBit(oldp+5993,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x3fffffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x20U))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x3fffffffULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x20U))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                                     [0x22U] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                                 [0x22U]))));
    bufp->fullBit(oldp+5994,((1U & (IData)((0x1fffffffULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               >> 0x21U))))));
    bufp->fullBit(oldp+5995,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                              [0x23U])));
    bufp->fullBit(oldp+5996,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                                    [0x23U] >> 1U))));
    bufp->fullBit(oldp+5997,((1U & (~ (IData)((0x1fffffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x21U)))))));
    bufp->fullBit(oldp+5998,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x1fffffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x21U))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x1fffffffULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x21U))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                                     [0x23U] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                                 [0x23U]))));
    bufp->fullBit(oldp+5999,((1U & (IData)((0xfffffffULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               >> 0x22U))))));
    bufp->fullBit(oldp+6000,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                              [0x24U])));
    bufp->fullBit(oldp+6001,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                                    [0x24U] >> 1U))));
    bufp->fullBit(oldp+6002,((1U & (~ (IData)((0xfffffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x22U)))))));
    bufp->fullBit(oldp+6003,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0xfffffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x22U))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__x) 
                                   & (IData)((0xfffffffULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x22U))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                                     [0x24U] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                                 [0x24U]))));
    bufp->fullBit(oldp+6004,((1U & (IData)((0x7ffffffULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               >> 0x23U))))));
    bufp->fullBit(oldp+6005,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                              [0x25U])));
    bufp->fullBit(oldp+6006,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                                    [0x25U] >> 1U))));
    bufp->fullBit(oldp+6007,((1U & (~ (IData)((0x7ffffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x23U)))))));
    bufp->fullBit(oldp+6008,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x7ffffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x23U))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x7ffffffULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x23U))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                                     [0x25U] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                                 [0x25U]))));
    bufp->fullBit(oldp+6009,((1U & (IData)((0x3ffffffULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               >> 0x24U))))));
    bufp->fullBit(oldp+6010,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                              [0x26U])));
    bufp->fullBit(oldp+6011,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                                    [0x26U] >> 1U))));
    bufp->fullBit(oldp+6012,((1U & (~ (IData)((0x3ffffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x24U)))))));
    bufp->fullBit(oldp+6013,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x3ffffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x24U))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x3ffffffULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x24U))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                                     [0x26U] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                                 [0x26U]))));
    bufp->fullBit(oldp+6014,((1U & (IData)((0x1ffffffULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               >> 0x25U))))));
    bufp->fullBit(oldp+6015,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                              [0x27U])));
    bufp->fullBit(oldp+6016,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                                    [0x27U] >> 1U))));
    bufp->fullBit(oldp+6017,((1U & (~ (IData)((0x1ffffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x25U)))))));
    bufp->fullBit(oldp+6018,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x1ffffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x25U))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x1ffffffULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x25U))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                                     [0x27U] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                                 [0x27U]))));
    bufp->fullBit(oldp+6019,((1U & (IData)((0x1fffffffffffffffULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               >> 1U))))));
    bufp->fullBit(oldp+6020,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                              [3U])));
    bufp->fullBit(oldp+6021,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                                    [3U] >> 1U))));
    bufp->fullBit(oldp+6022,((1U & (~ (IData)((0x1fffffffffffffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 1U)))))));
    bufp->fullBit(oldp+6023,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x1fffffffffffffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 1U))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x1fffffffffffffffULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 1U))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                                     [3U] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                                 [3U]))));
    bufp->fullBit(oldp+6024,((1U & (IData)((0xffffffULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               >> 0x26U))))));
    bufp->fullBit(oldp+6025,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                              [0x28U])));
    bufp->fullBit(oldp+6026,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                                    [0x28U] >> 1U))));
    bufp->fullBit(oldp+6027,((1U & (~ (IData)((0xffffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x26U)))))));
    bufp->fullBit(oldp+6028,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0xffffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x26U))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__x) 
                                   & (IData)((0xffffffULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x26U))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                                     [0x28U] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                                 [0x28U]))));
    bufp->fullBit(oldp+6029,((1U & (IData)((0x7fffffULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               >> 0x27U))))));
    bufp->fullBit(oldp+6030,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                              [0x29U])));
    bufp->fullBit(oldp+6031,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                                    [0x29U] >> 1U))));
    bufp->fullBit(oldp+6032,((1U & (~ (IData)((0x7fffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x27U)))))));
    bufp->fullBit(oldp+6033,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x7fffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x27U))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x7fffffULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x27U))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                                     [0x29U] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                                 [0x29U]))));
    bufp->fullBit(oldp+6034,((1U & (IData)((0x3fffffULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               >> 0x28U))))));
    bufp->fullBit(oldp+6035,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                              [0x2aU])));
    bufp->fullBit(oldp+6036,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                                    [0x2aU] >> 1U))));
    bufp->fullBit(oldp+6037,((1U & (~ (IData)((0x3fffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x28U)))))));
    bufp->fullBit(oldp+6038,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x3fffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x28U))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x3fffffULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x28U))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                                     [0x2aU] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                                 [0x2aU]))));
    bufp->fullBit(oldp+6039,((1U & (IData)((0x1fffffULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               >> 0x29U))))));
    bufp->fullBit(oldp+6040,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                              [0x2bU])));
    bufp->fullBit(oldp+6041,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                                    [0x2bU] >> 1U))));
    bufp->fullBit(oldp+6042,((1U & (~ (IData)((0x1fffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x29U)))))));
    bufp->fullBit(oldp+6043,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x1fffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x29U))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x1fffffULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x29U))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                                     [0x2bU] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                                 [0x2bU]))));
    bufp->fullBit(oldp+6044,((1U & (IData)((0xfffffULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               >> 0x2aU))))));
    bufp->fullBit(oldp+6045,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                              [0x2cU])));
    bufp->fullBit(oldp+6046,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                                    [0x2cU] >> 1U))));
    bufp->fullBit(oldp+6047,((1U & (~ (IData)((0xfffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x2aU)))))));
    bufp->fullBit(oldp+6048,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0xfffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x2aU))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__x) 
                                   & (IData)((0xfffffULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x2aU))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                                     [0x2cU] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                                 [0x2cU]))));
    bufp->fullBit(oldp+6049,((1U & (IData)((0x7ffffULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               >> 0x2bU))))));
    bufp->fullBit(oldp+6050,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                              [0x2dU])));
    bufp->fullBit(oldp+6051,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                                    [0x2dU] >> 1U))));
    bufp->fullBit(oldp+6052,((1U & (~ (IData)((0x7ffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x2bU)))))));
    bufp->fullBit(oldp+6053,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x7ffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x2bU))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x7ffffULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x2bU))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                                     [0x2dU] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                                 [0x2dU]))));
    bufp->fullBit(oldp+6054,((1U & (IData)((0x3ffffULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               >> 0x2cU))))));
    bufp->fullBit(oldp+6055,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                              [0x2eU])));
    bufp->fullBit(oldp+6056,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                                    [0x2eU] >> 1U))));
    bufp->fullBit(oldp+6057,((1U & (~ (IData)((0x3ffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x2cU)))))));
    bufp->fullBit(oldp+6058,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x3ffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x2cU))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x3ffffULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x2cU))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                                     [0x2eU] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                                 [0x2eU]))));
    bufp->fullBit(oldp+6059,((1U & (IData)((0x1ffffULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               >> 0x2dU))))));
    bufp->fullBit(oldp+6060,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                              [0x2fU])));
    bufp->fullBit(oldp+6061,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                                    [0x2fU] >> 1U))));
    bufp->fullBit(oldp+6062,((1U & (~ (IData)((0x1ffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x2dU)))))));
    bufp->fullBit(oldp+6063,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x1ffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x2dU))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x1ffffULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x2dU))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                                     [0x2fU] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                                 [0x2fU]))));
    bufp->fullBit(oldp+6064,((1U & (IData)((0xffffULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               >> 0x2eU))))));
    bufp->fullBit(oldp+6065,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                              [0x30U])));
    bufp->fullBit(oldp+6066,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                                    [0x30U] >> 1U))));
    bufp->fullBit(oldp+6067,((1U & (~ (IData)((0xffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x2eU)))))));
    bufp->fullBit(oldp+6068,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0xffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x2eU))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__x) 
                                   & (IData)((0xffffULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x2eU))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                                     [0x30U] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                                 [0x30U]))));
    bufp->fullBit(oldp+6069,((1U & (IData)((0x7fffULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               >> 0x2fU))))));
    bufp->fullBit(oldp+6070,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                              [0x31U])));
    bufp->fullBit(oldp+6071,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                                    [0x31U] >> 1U))));
    bufp->fullBit(oldp+6072,((1U & (~ (IData)((0x7fffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x2fU)))))));
    bufp->fullBit(oldp+6073,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x7fffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x2fU))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x7fffULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x2fU))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                                     [0x31U] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                                 [0x31U]))));
    bufp->fullBit(oldp+6074,((1U & (IData)((0xfffffffffffffffULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               >> 2U))))));
    bufp->fullBit(oldp+6075,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                              [4U])));
    bufp->fullBit(oldp+6076,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                                    [4U] >> 1U))));
    bufp->fullBit(oldp+6077,((1U & (~ (IData)((0xfffffffffffffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 2U)))))));
    bufp->fullBit(oldp+6078,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0xfffffffffffffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 2U))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__x) 
                                   & (IData)((0xfffffffffffffffULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 2U))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                                     [4U] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                                 [4U]))));
    bufp->fullBit(oldp+6079,((1U & (IData)((0x3fffULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               >> 0x30U))))));
    bufp->fullBit(oldp+6080,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                              [0x32U])));
    bufp->fullBit(oldp+6081,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                                    [0x32U] >> 1U))));
    bufp->fullBit(oldp+6082,((1U & (~ (IData)((0x3fffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x30U)))))));
    bufp->fullBit(oldp+6083,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x3fffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x30U))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x3fffULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x30U))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                                     [0x32U] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                                 [0x32U]))));
    bufp->fullBit(oldp+6084,((1U & (IData)((0x1fffULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               >> 0x31U))))));
    bufp->fullBit(oldp+6085,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                              [0x33U])));
    bufp->fullBit(oldp+6086,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                                    [0x33U] >> 1U))));
    bufp->fullBit(oldp+6087,((1U & (~ (IData)((0x1fffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x31U)))))));
    bufp->fullBit(oldp+6088,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x1fffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x31U))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x1fffULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x31U))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                                     [0x33U] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                                 [0x33U]))));
    bufp->fullBit(oldp+6089,((1U & (IData)((0xfffULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               >> 0x32U))))));
    bufp->fullBit(oldp+6090,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                              [0x34U])));
    bufp->fullBit(oldp+6091,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                                    [0x34U] >> 1U))));
    bufp->fullBit(oldp+6092,((1U & (~ (IData)((0xfffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x32U)))))));
    bufp->fullBit(oldp+6093,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0xfffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x32U))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__x) 
                                   & (IData)((0xfffULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x32U))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                                     [0x34U] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                                 [0x34U]))));
    bufp->fullBit(oldp+6094,((1U & (IData)((0x7ffULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               >> 0x33U))))));
    bufp->fullBit(oldp+6095,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                              [0x35U])));
    bufp->fullBit(oldp+6096,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                                    [0x35U] >> 1U))));
    bufp->fullBit(oldp+6097,((1U & (~ (IData)((0x7ffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x33U)))))));
    bufp->fullBit(oldp+6098,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x7ffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x33U))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x7ffULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x33U))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                                     [0x35U] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                                 [0x35U]))));
    bufp->fullBit(oldp+6099,((1U & (IData)((0x3ffULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               >> 0x34U))))));
    bufp->fullBit(oldp+6100,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                              [0x36U])));
    bufp->fullBit(oldp+6101,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                                    [0x36U] >> 1U))));
    bufp->fullBit(oldp+6102,((1U & (~ (IData)((0x3ffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x34U)))))));
    bufp->fullBit(oldp+6103,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x3ffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x34U))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x3ffULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x34U))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                                     [0x36U] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                                 [0x36U]))));
    bufp->fullBit(oldp+6104,((1U & (IData)((0x1ffULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               >> 0x35U))))));
    bufp->fullBit(oldp+6105,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                              [0x37U])));
    bufp->fullBit(oldp+6106,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                                    [0x37U] >> 1U))));
    bufp->fullBit(oldp+6107,((1U & (~ (IData)((0x1ffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x35U)))))));
    bufp->fullBit(oldp+6108,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x1ffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x35U))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x1ffULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x35U))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                                     [0x37U] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                                 [0x37U]))));
    bufp->fullBit(oldp+6109,((1U & (IData)((0xffULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               >> 0x36U))))));
    bufp->fullBit(oldp+6110,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                              [0x38U])));
    bufp->fullBit(oldp+6111,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                                    [0x38U] >> 1U))));
    bufp->fullBit(oldp+6112,((1U & (~ (IData)((0xffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x36U)))))));
    bufp->fullBit(oldp+6113,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0xffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x36U))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__x) 
                                   & (IData)((0xffULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x36U))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                                     [0x38U] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                                 [0x38U]))));
    bufp->fullBit(oldp+6114,((1U & (IData)((0x7fULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               >> 0x37U))))));
    bufp->fullBit(oldp+6115,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                              [0x39U])));
    bufp->fullBit(oldp+6116,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                                    [0x39U] >> 1U))));
    bufp->fullBit(oldp+6117,((1U & (~ (IData)((0x7fULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x37U)))))));
    bufp->fullBit(oldp+6118,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x7fULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x37U))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x7fULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x37U))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                                     [0x39U] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                                 [0x39U]))));
    bufp->fullBit(oldp+6119,((1U & (IData)((0x3fULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               >> 0x38U))))));
    bufp->fullBit(oldp+6120,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                              [0x3aU])));
    bufp->fullBit(oldp+6121,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                                    [0x3aU] >> 1U))));
    bufp->fullBit(oldp+6122,((1U & (~ (IData)((0x3fULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x38U)))))));
    bufp->fullBit(oldp+6123,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x3fULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x38U))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x3fULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x38U))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                                     [0x3aU] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                                 [0x3aU]))));
    bufp->fullBit(oldp+6124,((1U & (IData)((0x1fULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               >> 0x39U))))));
    bufp->fullBit(oldp+6125,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                              [0x3bU])));
    bufp->fullBit(oldp+6126,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                                    [0x3bU] >> 1U))));
    bufp->fullBit(oldp+6127,((1U & (~ (IData)((0x1fULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x39U)))))));
    bufp->fullBit(oldp+6128,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x1fULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x39U))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x1fULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x39U))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                                     [0x3bU] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                                 [0x3bU]))));
    bufp->fullBit(oldp+6129,((1U & (IData)((0x7ffffffffffffffULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               >> 3U))))));
    bufp->fullBit(oldp+6130,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                              [5U])));
    bufp->fullBit(oldp+6131,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                                    [5U] >> 1U))));
    bufp->fullBit(oldp+6132,((1U & (~ (IData)((0x7ffffffffffffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 3U)))))));
    bufp->fullBit(oldp+6133,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x7ffffffffffffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 3U))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x7ffffffffffffffULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 3U))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                                     [5U] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                                 [5U]))));
    bufp->fullBit(oldp+6134,((1U & (IData)((0xfULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               >> 0x3aU))))));
    bufp->fullBit(oldp+6135,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                              [0x3cU])));
    bufp->fullBit(oldp+6136,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                                    [0x3cU] >> 1U))));
    bufp->fullBit(oldp+6137,((1U & (~ (IData)((0xfULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x3aU)))))));
    bufp->fullBit(oldp+6138,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0xfULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x3aU))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__x) 
                                   & (IData)((0xfULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x3aU))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                                     [0x3cU] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                                 [0x3cU]))));
    bufp->fullBit(oldp+6139,((1U & (IData)((7ULL & 
                                            (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                             >> 0x3bU))))));
    bufp->fullBit(oldp+6140,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                              [0x3dU])));
    bufp->fullBit(oldp+6141,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                                    [0x3dU] >> 1U))));
    bufp->fullBit(oldp+6142,((1U & (~ (IData)((7ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x3bU)))))));
    bufp->fullBit(oldp+6143,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((7ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x3bU))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__x) 
                                   & (IData)((7ULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x3bU))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                                     [0x3dU] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                                 [0x3dU]))));
    bufp->fullBit(oldp+6144,((1U & (IData)((3ULL & 
                                            (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                             >> 0x3cU))))));
    bufp->fullBit(oldp+6145,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                              [0x3eU])));
    bufp->fullBit(oldp+6146,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                                    [0x3eU] >> 1U))));
    bufp->fullBit(oldp+6147,((1U & (~ (IData)((3ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x3cU)))))));
    bufp->fullBit(oldp+6148,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((3ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x3cU))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__x) 
                                   & (IData)((3ULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x3cU))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                                     [0x3eU] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                                 [0x3eU]))));
    bufp->fullBit(oldp+6149,((1U & (IData)((1ULL & 
                                            (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                             >> 0x3dU))))));
    bufp->fullBit(oldp+6150,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                              [0x3fU])));
    bufp->fullBit(oldp+6151,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                                    [0x3fU] >> 1U))));
    bufp->fullBit(oldp+6152,((1U & (~ (IData)((1ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x3dU)))))));
    bufp->fullBit(oldp+6153,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((1ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x3dU))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__x) 
                                   & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                      >> 0x3dU))) | 
                               ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__neg2x) 
                                & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                                   [0x3fU] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                                 [0x3fU]))));
    bufp->fullBit(oldp+6154,((1U & (IData)((0x3ffffffffffffffULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               >> 4U))))));
    bufp->fullBit(oldp+6155,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                              [6U])));
    bufp->fullBit(oldp+6156,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                                    [6U] >> 1U))));
    bufp->fullBit(oldp+6157,((1U & (~ (IData)((0x3ffffffffffffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 4U)))))));
    bufp->fullBit(oldp+6158,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x3ffffffffffffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 4U))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x3ffffffffffffffULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 4U))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                                     [6U] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                                 [6U]))));
    bufp->fullBit(oldp+6159,((1U & (IData)((0x1ffffffffffffffULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               >> 5U))))));
    bufp->fullBit(oldp+6160,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                              [7U])));
    bufp->fullBit(oldp+6161,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                                    [7U] >> 1U))));
    bufp->fullBit(oldp+6162,((1U & (~ (IData)((0x1ffffffffffffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 5U)))))));
    bufp->fullBit(oldp+6163,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x1ffffffffffffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 5U))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x1ffffffffffffffULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 5U))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                                     [7U] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                                 [7U]))));
    bufp->fullBit(oldp+6164,((1U & (IData)((0xffffffffffffffULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               >> 6U))))));
    bufp->fullBit(oldp+6165,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                              [8U])));
    bufp->fullBit(oldp+6166,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                                    [8U] >> 1U))));
    bufp->fullBit(oldp+6167,((1U & (~ (IData)((0xffffffffffffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 6U)))))));
    bufp->fullBit(oldp+6168,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0xffffffffffffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 6U))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__x) 
                                   & (IData)((0xffffffffffffffULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 6U))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                                     [8U] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                                 [8U]))));
    bufp->fullBit(oldp+6169,((1U & (IData)((0x7fffffffffffffULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               >> 7U))))));
    bufp->fullBit(oldp+6170,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                              [9U])));
    bufp->fullBit(oldp+6171,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                                    [9U] >> 1U))));
    bufp->fullBit(oldp+6172,((1U & (~ (IData)((0x7fffffffffffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 7U)))))));
    bufp->fullBit(oldp+6173,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x7fffffffffffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 7U))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x7fffffffffffffULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 7U))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                                     [9U] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__2__KET____DOT__ai__DOT__CarrySig
                                 [9U]))));
    bufp->fullBit(oldp+6174,((1U & (IData)((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalY 
                                            >> 3U)))));
    bufp->fullBit(oldp+6175,((1U & (IData)((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalY 
                                            >> 2U)))));
    bufp->fullBit(oldp+6176,((1U & (IData)((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalY 
                                            >> 1U)))));
    bufp->fullCData(oldp+6177,((7U & (IData)((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalY 
                                              >> 0x1dU)))),3);
    bufp->fullQData(oldp+6178,((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                << 0x1eU)),64);
    bufp->fullQData(oldp+6180,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT____Vcellout__boothfor__BRA__30__KET____DOT__ai__OutX),64);
    bufp->fullBit(oldp+6182,(((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__negx) 
                              | (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__neg2x))));
    bufp->fullBit(oldp+6183,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__negx));
    bufp->fullBit(oldp+6184,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__x));
    bufp->fullBit(oldp+6185,(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__neg2x));
    bufp->fullBit(oldp+6186,((1U & (IData)((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                            << 0x1eU)))));
    bufp->fullBit(oldp+6187,((1U & (~ (IData)((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               << 0x1eU))))));
    bufp->fullBit(oldp+6188,(((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__negx) 
                                & (~ (IData)((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                              << 0x1eU)))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__x) 
                                  & (IData)((vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                             << 0x1eU)))) 
                              | (IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__neg2x))));
    bufp->fullBit(oldp+6189,((1U & (IData)((0x3ffffffff00000ULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               << 0x14U))))));
    bufp->fullBit(oldp+6190,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__CarrySig
                              [0xaU])));
    bufp->fullBit(oldp+6191,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__CarrySig
                                    [0xaU] >> 1U))));
    bufp->fullBit(oldp+6192,((1U & (~ (IData)((0x3ffffffff00000ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 0x14U)))))));
    bufp->fullBit(oldp+6193,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x3ffffffff00000ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 0x14U))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x3ffffffff00000ULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 0x14U))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__CarrySig
                                     [0xaU] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__CarrySig
                                 [0xaU]))));
    bufp->fullBit(oldp+6194,((1U & (IData)((0x1ffffffff80000ULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               << 0x13U))))));
    bufp->fullBit(oldp+6195,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__CarrySig
                              [0xbU])));
    bufp->fullBit(oldp+6196,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__CarrySig
                                    [0xbU] >> 1U))));
    bufp->fullBit(oldp+6197,((1U & (~ (IData)((0x1ffffffff80000ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 0x13U)))))));
    bufp->fullBit(oldp+6198,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x1ffffffff80000ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 0x13U))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x1ffffffff80000ULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 0x13U))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__CarrySig
                                     [0xbU] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__CarrySig
                                 [0xbU]))));
    bufp->fullBit(oldp+6199,((1U & (IData)((0xffffffffc0000ULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               << 0x12U))))));
    bufp->fullBit(oldp+6200,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__CarrySig
                              [0xcU])));
    bufp->fullBit(oldp+6201,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__CarrySig
                                    [0xcU] >> 1U))));
    bufp->fullBit(oldp+6202,((1U & (~ (IData)((0xffffffffc0000ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 0x12U)))))));
    bufp->fullBit(oldp+6203,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0xffffffffc0000ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 0x12U))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__x) 
                                   & (IData)((0xffffffffc0000ULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 0x12U))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__CarrySig
                                     [0xcU] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__CarrySig
                                 [0xcU]))));
    bufp->fullBit(oldp+6204,((1U & (IData)((0x7fffffffe0000ULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               << 0x11U))))));
    bufp->fullBit(oldp+6205,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__CarrySig
                              [0xdU])));
    bufp->fullBit(oldp+6206,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__CarrySig
                                    [0xdU] >> 1U))));
    bufp->fullBit(oldp+6207,((1U & (~ (IData)((0x7fffffffe0000ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 0x11U)))))));
    bufp->fullBit(oldp+6208,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x7fffffffe0000ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 0x11U))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x7fffffffe0000ULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 0x11U))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__CarrySig
                                     [0xdU] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__CarrySig
                                 [0xdU]))));
    bufp->fullBit(oldp+6209,((1U & (IData)((0x3ffffffff0000ULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               << 0x10U))))));
    bufp->fullBit(oldp+6210,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__CarrySig
                              [0xeU])));
    bufp->fullBit(oldp+6211,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__CarrySig
                                    [0xeU] >> 1U))));
    bufp->fullBit(oldp+6212,((1U & (~ (IData)((0x3ffffffff0000ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 0x10U)))))));
    bufp->fullBit(oldp+6213,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x3ffffffff0000ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 0x10U))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x3ffffffff0000ULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 0x10U))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__CarrySig
                                     [0xeU] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__CarrySig
                                 [0xeU]))));
    bufp->fullBit(oldp+6214,((1U & (IData)((0x1ffffffff8000ULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               << 0xfU))))));
    bufp->fullBit(oldp+6215,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__CarrySig
                              [0xfU])));
    bufp->fullBit(oldp+6216,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__CarrySig
                                    [0xfU] >> 1U))));
    bufp->fullBit(oldp+6217,((1U & (~ (IData)((0x1ffffffff8000ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 0xfU)))))));
    bufp->fullBit(oldp+6218,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x1ffffffff8000ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 0xfU))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x1ffffffff8000ULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 0xfU))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__CarrySig
                                     [0xfU] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__CarrySig
                                 [0xfU]))));
    bufp->fullBit(oldp+6219,((1U & (IData)((0xffffffffc000ULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               << 0xeU))))));
    bufp->fullBit(oldp+6220,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__CarrySig
                              [0x10U])));
    bufp->fullBit(oldp+6221,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__CarrySig
                                    [0x10U] >> 1U))));
    bufp->fullBit(oldp+6222,((1U & (~ (IData)((0xffffffffc000ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 0xeU)))))));
    bufp->fullBit(oldp+6223,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0xffffffffc000ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 0xeU))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__x) 
                                   & (IData)((0xffffffffc000ULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 0xeU))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__CarrySig
                                     [0x10U] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__CarrySig
                                 [0x10U]))));
    bufp->fullBit(oldp+6224,((1U & (IData)((0x7fffffffe000ULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               << 0xdU))))));
    bufp->fullBit(oldp+6225,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__CarrySig
                              [0x11U])));
    bufp->fullBit(oldp+6226,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__CarrySig
                                    [0x11U] >> 1U))));
    bufp->fullBit(oldp+6227,((1U & (~ (IData)((0x7fffffffe000ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 0xdU)))))));
    bufp->fullBit(oldp+6228,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x7fffffffe000ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 0xdU))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x7fffffffe000ULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 0xdU))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__CarrySig
                                     [0x11U] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__CarrySig
                                 [0x11U]))));
    bufp->fullBit(oldp+6229,((1U & (IData)((0x3ffffffff000ULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               << 0xcU))))));
    bufp->fullBit(oldp+6230,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__CarrySig
                              [0x12U])));
    bufp->fullBit(oldp+6231,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__CarrySig
                                    [0x12U] >> 1U))));
    bufp->fullBit(oldp+6232,((1U & (~ (IData)((0x3ffffffff000ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 0xcU)))))));
    bufp->fullBit(oldp+6233,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x3ffffffff000ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 0xcU))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x3ffffffff000ULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 0xcU))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__CarrySig
                                     [0x12U] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__CarrySig
                                 [0x12U]))));
    bufp->fullBit(oldp+6234,((1U & (IData)((0x1ffffffff800ULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               << 0xbU))))));
    bufp->fullBit(oldp+6235,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__CarrySig
                              [0x13U])));
    bufp->fullBit(oldp+6236,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__CarrySig
                                    [0x13U] >> 1U))));
    bufp->fullBit(oldp+6237,((1U & (~ (IData)((0x1ffffffff800ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 0xbU)))))));
    bufp->fullBit(oldp+6238,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x1ffffffff800ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 0xbU))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x1ffffffff800ULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 0xbU))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__CarrySig
                                     [0x13U] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__CarrySig
                                 [0x13U]))));
    bufp->fullBit(oldp+6239,((1U & (IData)((0x7fffffffe0000000ULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               << 0x1dU))))));
    bufp->fullBit(oldp+6240,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__CarrySig
                              [1U])));
    bufp->fullBit(oldp+6241,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__CarrySig
                                    [1U] >> 1U))));
    bufp->fullBit(oldp+6242,((1U & (~ (IData)((0x7fffffffe0000000ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 0x1dU)))))));
    bufp->fullBit(oldp+6243,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x7fffffffe0000000ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 0x1dU))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x7fffffffe0000000ULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 0x1dU))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__CarrySig
                                     [1U] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__CarrySig
                                 [1U]))));
    bufp->fullBit(oldp+6244,((1U & (IData)((0xffffffffc00ULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               << 0xaU))))));
    bufp->fullBit(oldp+6245,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__CarrySig
                              [0x14U])));
    bufp->fullBit(oldp+6246,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__CarrySig
                                    [0x14U] >> 1U))));
    bufp->fullBit(oldp+6247,((1U & (~ (IData)((0xffffffffc00ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 0xaU)))))));
    bufp->fullBit(oldp+6248,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0xffffffffc00ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 0xaU))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__x) 
                                   & (IData)((0xffffffffc00ULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 0xaU))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__CarrySig
                                     [0x14U] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__CarrySig
                                 [0x14U]))));
    bufp->fullBit(oldp+6249,((1U & (IData)((0x7fffffffe00ULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               << 9U))))));
    bufp->fullBit(oldp+6250,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__CarrySig
                              [0x15U])));
    bufp->fullBit(oldp+6251,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__CarrySig
                                    [0x15U] >> 1U))));
    bufp->fullBit(oldp+6252,((1U & (~ (IData)((0x7fffffffe00ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 9U)))))));
    bufp->fullBit(oldp+6253,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x7fffffffe00ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 9U))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x7fffffffe00ULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 9U))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__CarrySig
                                     [0x15U] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__CarrySig
                                 [0x15U]))));
    bufp->fullBit(oldp+6254,((1U & (IData)((0x3ffffffff00ULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               << 8U))))));
    bufp->fullBit(oldp+6255,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__CarrySig
                              [0x16U])));
    bufp->fullBit(oldp+6256,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__CarrySig
                                    [0x16U] >> 1U))));
    bufp->fullBit(oldp+6257,((1U & (~ (IData)((0x3ffffffff00ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 8U)))))));
    bufp->fullBit(oldp+6258,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x3ffffffff00ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 8U))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x3ffffffff00ULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 8U))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__CarrySig
                                     [0x16U] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__CarrySig
                                 [0x16U]))));
    bufp->fullBit(oldp+6259,((1U & (IData)((0x1ffffffff80ULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               << 7U))))));
    bufp->fullBit(oldp+6260,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__CarrySig
                              [0x17U])));
    bufp->fullBit(oldp+6261,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__CarrySig
                                    [0x17U] >> 1U))));
    bufp->fullBit(oldp+6262,((1U & (~ (IData)((0x1ffffffff80ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 7U)))))));
    bufp->fullBit(oldp+6263,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x1ffffffff80ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 7U))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x1ffffffff80ULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 7U))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__CarrySig
                                     [0x17U] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__CarrySig
                                 [0x17U]))));
    bufp->fullBit(oldp+6264,((1U & (IData)((0xffffffffc0ULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               << 6U))))));
    bufp->fullBit(oldp+6265,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__CarrySig
                              [0x18U])));
    bufp->fullBit(oldp+6266,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__CarrySig
                                    [0x18U] >> 1U))));
    bufp->fullBit(oldp+6267,((1U & (~ (IData)((0xffffffffc0ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 6U)))))));
    bufp->fullBit(oldp+6268,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0xffffffffc0ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 6U))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__x) 
                                   & (IData)((0xffffffffc0ULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 6U))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__CarrySig
                                     [0x18U] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__CarrySig
                                 [0x18U]))));
    bufp->fullBit(oldp+6269,((1U & (IData)((0x7fffffffe0ULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               << 5U))))));
    bufp->fullBit(oldp+6270,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__CarrySig
                              [0x19U])));
    bufp->fullBit(oldp+6271,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__CarrySig
                                    [0x19U] >> 1U))));
    bufp->fullBit(oldp+6272,((1U & (~ (IData)((0x7fffffffe0ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 5U)))))));
    bufp->fullBit(oldp+6273,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x7fffffffe0ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 5U))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x7fffffffe0ULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 5U))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__CarrySig
                                     [0x19U] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__CarrySig
                                 [0x19U]))));
    bufp->fullBit(oldp+6274,((1U & (IData)((0x3ffffffff0ULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               << 4U))))));
    bufp->fullBit(oldp+6275,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__CarrySig
                              [0x1aU])));
    bufp->fullBit(oldp+6276,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__CarrySig
                                    [0x1aU] >> 1U))));
    bufp->fullBit(oldp+6277,((1U & (~ (IData)((0x3ffffffff0ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 4U)))))));
    bufp->fullBit(oldp+6278,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x3ffffffff0ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 4U))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x3ffffffff0ULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 4U))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__CarrySig
                                     [0x1aU] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__CarrySig
                                 [0x1aU]))));
    bufp->fullBit(oldp+6279,((1U & (IData)((0x1ffffffff8ULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               << 3U))))));
    bufp->fullBit(oldp+6280,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__CarrySig
                              [0x1bU])));
    bufp->fullBit(oldp+6281,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__CarrySig
                                    [0x1bU] >> 1U))));
    bufp->fullBit(oldp+6282,((1U & (~ (IData)((0x1ffffffff8ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 3U)))))));
    bufp->fullBit(oldp+6283,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x1ffffffff8ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 3U))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x1ffffffff8ULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 3U))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__CarrySig
                                     [0x1bU] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__CarrySig
                                 [0x1bU]))));
    bufp->fullBit(oldp+6284,((1U & (IData)((0xffffffffcULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               << 2U))))));
    bufp->fullBit(oldp+6285,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__CarrySig
                              [0x1cU])));
    bufp->fullBit(oldp+6286,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__CarrySig
                                    [0x1cU] >> 1U))));
    bufp->fullBit(oldp+6287,((1U & (~ (IData)((0xffffffffcULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 2U)))))));
    bufp->fullBit(oldp+6288,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0xffffffffcULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 2U))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__x) 
                                   & (IData)((0xffffffffcULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 2U))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__CarrySig
                                     [0x1cU] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__CarrySig
                                 [0x1cU]))));
    bufp->fullBit(oldp+6289,((1U & (IData)((0x7fffffffeULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               << 1U))))));
    bufp->fullBit(oldp+6290,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__CarrySig
                              [0x1dU])));
    bufp->fullBit(oldp+6291,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__CarrySig
                                    [0x1dU] >> 1U))));
    bufp->fullBit(oldp+6292,((1U & (~ (IData)((0x7fffffffeULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 1U)))))));
    bufp->fullBit(oldp+6293,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x7fffffffeULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 1U))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x7fffffffeULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 1U))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__CarrySig
                                     [0x1dU] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__CarrySig
                                 [0x1dU]))));
    bufp->fullBit(oldp+6294,((1U & (IData)((0x3ffffffff0000000ULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               << 0x1cU))))));
    bufp->fullBit(oldp+6295,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__CarrySig
                              [2U])));
    bufp->fullBit(oldp+6296,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__CarrySig
                                    [2U] >> 1U))));
    bufp->fullBit(oldp+6297,((1U & (~ (IData)((0x3ffffffff0000000ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 0x1cU)))))));
    bufp->fullBit(oldp+6298,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x3ffffffff0000000ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 0x1cU))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x3ffffffff0000000ULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 0x1cU))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__CarrySig
                                     [2U] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__CarrySig
                                 [2U]))));
    bufp->fullBit(oldp+6299,((1U & (IData)((0x3ffffffffULL 
                                            & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX)))));
    bufp->fullBit(oldp+6300,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__CarrySig
                              [0x1eU])));
    bufp->fullBit(oldp+6301,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__CarrySig
                                    [0x1eU] >> 1U))));
    bufp->fullBit(oldp+6302,((1U & (~ (IData)((0x3ffffffffULL 
                                               & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX))))));
    bufp->fullBit(oldp+6303,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x3ffffffffULL 
                                               & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX)))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x3ffffffffULL 
                                              & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX)))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__CarrySig
                                     [0x1eU] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__CarrySig
                                 [0x1eU]))));
    bufp->fullBit(oldp+6304,((1U & (IData)((0x1ffffffffULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               >> 1U))))));
    bufp->fullBit(oldp+6305,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__CarrySig
                              [0x1fU])));
    bufp->fullBit(oldp+6306,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__CarrySig
                                    [0x1fU] >> 1U))));
    bufp->fullBit(oldp+6307,((1U & (~ (IData)((0x1ffffffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 1U)))))));
    bufp->fullBit(oldp+6308,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x1ffffffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 1U))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x1ffffffffULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 1U))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__CarrySig
                                     [0x1fU] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__CarrySig
                                 [0x1fU]))));
    bufp->fullBit(oldp+6309,((1U & (IData)((0xffffffffULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               >> 2U))))));
    bufp->fullBit(oldp+6310,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__CarrySig
                              [0x20U])));
    bufp->fullBit(oldp+6311,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__CarrySig
                                    [0x20U] >> 1U))));
    bufp->fullBit(oldp+6312,((1U & (~ (IData)((0xffffffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 2U)))))));
    bufp->fullBit(oldp+6313,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0xffffffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 2U))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__x) 
                                   & (IData)((0xffffffffULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 2U))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__CarrySig
                                     [0x20U] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__CarrySig
                                 [0x20U]))));
    bufp->fullBit(oldp+6314,((1U & (IData)((0x7fffffffULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               >> 3U))))));
    bufp->fullBit(oldp+6315,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__CarrySig
                              [0x21U])));
    bufp->fullBit(oldp+6316,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__CarrySig
                                    [0x21U] >> 1U))));
    bufp->fullBit(oldp+6317,((1U & (~ (IData)((0x7fffffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 3U)))))));
    bufp->fullBit(oldp+6318,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x7fffffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 3U))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x7fffffffULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 3U))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__CarrySig
                                     [0x21U] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__CarrySig
                                 [0x21U]))));
    bufp->fullBit(oldp+6319,((1U & (IData)((0x3fffffffULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               >> 4U))))));
    bufp->fullBit(oldp+6320,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__CarrySig
                              [0x22U])));
    bufp->fullBit(oldp+6321,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__CarrySig
                                    [0x22U] >> 1U))));
    bufp->fullBit(oldp+6322,((1U & (~ (IData)((0x3fffffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 4U)))))));
    bufp->fullBit(oldp+6323,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x3fffffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 4U))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x3fffffffULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 4U))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__CarrySig
                                     [0x22U] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__CarrySig
                                 [0x22U]))));
    bufp->fullBit(oldp+6324,((1U & (IData)((0x1fffffffULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               >> 5U))))));
    bufp->fullBit(oldp+6325,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__CarrySig
                              [0x23U])));
    bufp->fullBit(oldp+6326,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__CarrySig
                                    [0x23U] >> 1U))));
    bufp->fullBit(oldp+6327,((1U & (~ (IData)((0x1fffffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 5U)))))));
    bufp->fullBit(oldp+6328,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x1fffffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 5U))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x1fffffffULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 5U))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__CarrySig
                                     [0x23U] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__CarrySig
                                 [0x23U]))));
    bufp->fullBit(oldp+6329,((1U & (IData)((0xfffffffULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               >> 6U))))));
    bufp->fullBit(oldp+6330,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__CarrySig
                              [0x24U])));
    bufp->fullBit(oldp+6331,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__CarrySig
                                    [0x24U] >> 1U))));
    bufp->fullBit(oldp+6332,((1U & (~ (IData)((0xfffffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 6U)))))));
    bufp->fullBit(oldp+6333,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0xfffffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 6U))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__x) 
                                   & (IData)((0xfffffffULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 6U))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__CarrySig
                                     [0x24U] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__CarrySig
                                 [0x24U]))));
    bufp->fullBit(oldp+6334,((1U & (IData)((0x7ffffffULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               >> 7U))))));
    bufp->fullBit(oldp+6335,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__CarrySig
                              [0x25U])));
    bufp->fullBit(oldp+6336,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__CarrySig
                                    [0x25U] >> 1U))));
    bufp->fullBit(oldp+6337,((1U & (~ (IData)((0x7ffffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 7U)))))));
    bufp->fullBit(oldp+6338,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x7ffffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 7U))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x7ffffffULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 7U))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__CarrySig
                                     [0x25U] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__CarrySig
                                 [0x25U]))));
    bufp->fullBit(oldp+6339,((1U & (IData)((0x3ffffffULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               >> 8U))))));
    bufp->fullBit(oldp+6340,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__CarrySig
                              [0x26U])));
    bufp->fullBit(oldp+6341,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__CarrySig
                                    [0x26U] >> 1U))));
    bufp->fullBit(oldp+6342,((1U & (~ (IData)((0x3ffffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 8U)))))));
    bufp->fullBit(oldp+6343,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x3ffffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 8U))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x3ffffffULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 8U))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__CarrySig
                                     [0x26U] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__CarrySig
                                 [0x26U]))));
    bufp->fullBit(oldp+6344,((1U & (IData)((0x1ffffffULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               >> 9U))))));
    bufp->fullBit(oldp+6345,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__CarrySig
                              [0x27U])));
    bufp->fullBit(oldp+6346,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__CarrySig
                                    [0x27U] >> 1U))));
    bufp->fullBit(oldp+6347,((1U & (~ (IData)((0x1ffffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 9U)))))));
    bufp->fullBit(oldp+6348,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x1ffffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 9U))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x1ffffffULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 9U))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__CarrySig
                                     [0x27U] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__CarrySig
                                 [0x27U]))));
    bufp->fullBit(oldp+6349,((1U & (IData)((0x1ffffffff8000000ULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               << 0x1bU))))));
    bufp->fullBit(oldp+6350,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__CarrySig
                              [3U])));
    bufp->fullBit(oldp+6351,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__CarrySig
                                    [3U] >> 1U))));
    bufp->fullBit(oldp+6352,((1U & (~ (IData)((0x1ffffffff8000000ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 0x1bU)))))));
    bufp->fullBit(oldp+6353,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x1ffffffff8000000ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 0x1bU))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x1ffffffff8000000ULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 0x1bU))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__CarrySig
                                     [3U] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__CarrySig
                                 [3U]))));
    bufp->fullBit(oldp+6354,((1U & (IData)((0xffffffULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               >> 0xaU))))));
    bufp->fullBit(oldp+6355,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__CarrySig
                              [0x28U])));
    bufp->fullBit(oldp+6356,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__CarrySig
                                    [0x28U] >> 1U))));
    bufp->fullBit(oldp+6357,((1U & (~ (IData)((0xffffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0xaU)))))));
    bufp->fullBit(oldp+6358,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0xffffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0xaU))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__x) 
                                   & (IData)((0xffffffULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0xaU))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__CarrySig
                                     [0x28U] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__CarrySig
                                 [0x28U]))));
    bufp->fullBit(oldp+6359,((1U & (IData)((0x7fffffULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               >> 0xbU))))));
    bufp->fullBit(oldp+6360,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__CarrySig
                              [0x29U])));
    bufp->fullBit(oldp+6361,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__CarrySig
                                    [0x29U] >> 1U))));
    bufp->fullBit(oldp+6362,((1U & (~ (IData)((0x7fffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0xbU)))))));
    bufp->fullBit(oldp+6363,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x7fffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0xbU))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x7fffffULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0xbU))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__CarrySig
                                     [0x29U] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__CarrySig
                                 [0x29U]))));
    bufp->fullBit(oldp+6364,((1U & (IData)((0x3fffffULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               >> 0xcU))))));
    bufp->fullBit(oldp+6365,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__CarrySig
                              [0x2aU])));
    bufp->fullBit(oldp+6366,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__CarrySig
                                    [0x2aU] >> 1U))));
    bufp->fullBit(oldp+6367,((1U & (~ (IData)((0x3fffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0xcU)))))));
    bufp->fullBit(oldp+6368,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x3fffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0xcU))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x3fffffULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0xcU))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__CarrySig
                                     [0x2aU] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__CarrySig
                                 [0x2aU]))));
    bufp->fullBit(oldp+6369,((1U & (IData)((0x1fffffULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               >> 0xdU))))));
    bufp->fullBit(oldp+6370,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__CarrySig
                              [0x2bU])));
    bufp->fullBit(oldp+6371,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__CarrySig
                                    [0x2bU] >> 1U))));
    bufp->fullBit(oldp+6372,((1U & (~ (IData)((0x1fffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0xdU)))))));
    bufp->fullBit(oldp+6373,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x1fffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0xdU))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x1fffffULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0xdU))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__CarrySig
                                     [0x2bU] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__CarrySig
                                 [0x2bU]))));
    bufp->fullBit(oldp+6374,((1U & (IData)((0xfffffULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               >> 0xeU))))));
    bufp->fullBit(oldp+6375,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__CarrySig
                              [0x2cU])));
    bufp->fullBit(oldp+6376,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__CarrySig
                                    [0x2cU] >> 1U))));
    bufp->fullBit(oldp+6377,((1U & (~ (IData)((0xfffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0xeU)))))));
    bufp->fullBit(oldp+6378,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0xfffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0xeU))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__x) 
                                   & (IData)((0xfffffULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0xeU))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__CarrySig
                                     [0x2cU] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__CarrySig
                                 [0x2cU]))));
    bufp->fullBit(oldp+6379,((1U & (IData)((0x7ffffULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               >> 0xfU))))));
    bufp->fullBit(oldp+6380,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__CarrySig
                              [0x2dU])));
    bufp->fullBit(oldp+6381,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__CarrySig
                                    [0x2dU] >> 1U))));
    bufp->fullBit(oldp+6382,((1U & (~ (IData)((0x7ffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0xfU)))))));
    bufp->fullBit(oldp+6383,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x7ffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0xfU))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x7ffffULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0xfU))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__CarrySig
                                     [0x2dU] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__CarrySig
                                 [0x2dU]))));
    bufp->fullBit(oldp+6384,((1U & (IData)((0x3ffffULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               >> 0x10U))))));
    bufp->fullBit(oldp+6385,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__CarrySig
                              [0x2eU])));
    bufp->fullBit(oldp+6386,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__CarrySig
                                    [0x2eU] >> 1U))));
    bufp->fullBit(oldp+6387,((1U & (~ (IData)((0x3ffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x10U)))))));
    bufp->fullBit(oldp+6388,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x3ffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x10U))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x3ffffULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x10U))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__CarrySig
                                     [0x2eU] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__CarrySig
                                 [0x2eU]))));
    bufp->fullBit(oldp+6389,((1U & (IData)((0x1ffffULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               >> 0x11U))))));
    bufp->fullBit(oldp+6390,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__CarrySig
                              [0x2fU])));
    bufp->fullBit(oldp+6391,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__CarrySig
                                    [0x2fU] >> 1U))));
    bufp->fullBit(oldp+6392,((1U & (~ (IData)((0x1ffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x11U)))))));
    bufp->fullBit(oldp+6393,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x1ffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x11U))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x1ffffULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x11U))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__CarrySig
                                     [0x2fU] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__CarrySig
                                 [0x2fU]))));
    bufp->fullBit(oldp+6394,((1U & (IData)((0xffffULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               >> 0x12U))))));
    bufp->fullBit(oldp+6395,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__CarrySig
                              [0x30U])));
    bufp->fullBit(oldp+6396,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__CarrySig
                                    [0x30U] >> 1U))));
    bufp->fullBit(oldp+6397,((1U & (~ (IData)((0xffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x12U)))))));
    bufp->fullBit(oldp+6398,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0xffffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x12U))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__x) 
                                   & (IData)((0xffffULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x12U))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__CarrySig
                                     [0x30U] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__CarrySig
                                 [0x30U]))));
    bufp->fullBit(oldp+6399,((1U & (IData)((0x7fffULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               >> 0x13U))))));
    bufp->fullBit(oldp+6400,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__CarrySig
                              [0x31U])));
    bufp->fullBit(oldp+6401,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__CarrySig
                                    [0x31U] >> 1U))));
    bufp->fullBit(oldp+6402,((1U & (~ (IData)((0x7fffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x13U)))))));
    bufp->fullBit(oldp+6403,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x7fffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x13U))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x7fffULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x13U))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__CarrySig
                                     [0x31U] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__CarrySig
                                 [0x31U]))));
    bufp->fullBit(oldp+6404,((1U & (IData)((0xffffffffc000000ULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               << 0x1aU))))));
    bufp->fullBit(oldp+6405,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__CarrySig
                              [4U])));
    bufp->fullBit(oldp+6406,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__CarrySig
                                    [4U] >> 1U))));
    bufp->fullBit(oldp+6407,((1U & (~ (IData)((0xffffffffc000000ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 0x1aU)))))));
    bufp->fullBit(oldp+6408,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0xffffffffc000000ULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  << 0x1aU))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__x) 
                                   & (IData)((0xffffffffc000000ULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 << 0x1aU))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__CarrySig
                                     [4U] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__CarrySig
                                 [4U]))));
    bufp->fullBit(oldp+6409,((1U & (IData)((0x3fffULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               >> 0x14U))))));
    bufp->fullBit(oldp+6410,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__CarrySig
                              [0x32U])));
    bufp->fullBit(oldp+6411,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__CarrySig
                                    [0x32U] >> 1U))));
    bufp->fullBit(oldp+6412,((1U & (~ (IData)((0x3fffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x14U)))))));
    bufp->fullBit(oldp+6413,((((((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__negx) 
                                 & (~ (IData)((0x3fffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x14U))))) 
                                | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__x) 
                                   & (IData)((0x3fffULL 
                                              & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                 >> 0x14U))))) 
                               | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__neg2x) 
                                  & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__CarrySig
                                     [0x32U] >> 1U))) 
                              | ((IData)(vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT___2x) 
                                 & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__CarrySig
                                 [0x32U]))));
    bufp->fullBit(oldp+6414,((1U & (IData)((0x1fffULL 
                                            & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                               >> 0x15U))))));
    bufp->fullBit(oldp+6415,((1U & vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__CarrySig
                              [0x33U])));
    bufp->fullBit(oldp+6416,((1U & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__boothfor__BRA__30__KET____DOT__ai__DOT__CarrySig
                                    [0x33U] >> 1U))));
    bufp->fullBit(oldp+6417,((1U & (~ (IData)((0x1fffULL 
                                               & (vlSelf->simu_top__DOT__soc__DOT__cpu__DOT__u_mul__DOT__CalX 
                                                  >> 0x15U)))))));
}
