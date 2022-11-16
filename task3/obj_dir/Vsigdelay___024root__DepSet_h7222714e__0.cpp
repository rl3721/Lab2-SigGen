// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsigdelay.h for the primary calling header

#include "verilated.h"

#include "Vsigdelay___024root.h"

VL_INLINE_OPT void Vsigdelay___024root___sequent__TOP__0(Vsigdelay___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsigdelay__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsigdelay___024root___sequent__TOP__0\n"); );
    // Init
    CData/*7:0*/ __Vdly__top__DOT__address;
    CData/*7:0*/ __Vdlyvdim0__top__DOT__sigdelayRom__DOT__ram_array__v0;
    CData/*7:0*/ __Vdlyvval__top__DOT__sigdelayRom__DOT__ram_array__v0;
    CData/*0:0*/ __Vdlyvset__top__DOT__sigdelayRom__DOT__ram_array__v0;
    // Body
    __Vdly__top__DOT__address = vlSelf->top__DOT__address;
    __Vdlyvset__top__DOT__sigdelayRom__DOT__ram_array__v0 = 0U;
    __Vdly__top__DOT__address = ((IData)(vlSelf->rst)
                                  ? 0U : (0xffU & ((IData)(vlSelf->top__DOT__address) 
                                                   + (IData)(vlSelf->counter_en))));
    if (vlSelf->rden) {
        vlSelf->delayed_signal = vlSelf->top__DOT__sigdelayRom__DOT__ram_array
            [(0xffU & ((IData)(vlSelf->top__DOT__address) 
                       - (IData)(vlSelf->offset)))];
    }
    if (vlSelf->wren) {
        __Vdlyvval__top__DOT__sigdelayRom__DOT__ram_array__v0 
            = vlSelf->mic_signal;
        __Vdlyvset__top__DOT__sigdelayRom__DOT__ram_array__v0 = 1U;
        __Vdlyvdim0__top__DOT__sigdelayRom__DOT__ram_array__v0 
            = vlSelf->top__DOT__address;
    }
    vlSelf->top__DOT__address = __Vdly__top__DOT__address;
    if (__Vdlyvset__top__DOT__sigdelayRom__DOT__ram_array__v0) {
        vlSelf->top__DOT__sigdelayRom__DOT__ram_array[__Vdlyvdim0__top__DOT__sigdelayRom__DOT__ram_array__v0] 
            = __Vdlyvval__top__DOT__sigdelayRom__DOT__ram_array__v0;
    }
}

void Vsigdelay___024root___eval(Vsigdelay___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsigdelay__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsigdelay___024root___eval\n"); );
    // Body
    if (((IData)(vlSelf->clk) & (~ (IData)(vlSelf->__Vclklast__TOP__clk)))) {
        Vsigdelay___024root___sequent__TOP__0(vlSelf);
    }
    // Final
    vlSelf->__Vclklast__TOP__clk = vlSelf->clk;
}

#ifdef VL_DEBUG
void Vsigdelay___024root___eval_debug_assertions(Vsigdelay___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsigdelay__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsigdelay___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->rst & 0xfeU))) {
        Verilated::overWidthError("rst");}
    if (VL_UNLIKELY((vlSelf->wren & 0xfeU))) {
        Verilated::overWidthError("wren");}
    if (VL_UNLIKELY((vlSelf->rden & 0xfeU))) {
        Verilated::overWidthError("rden");}
    if (VL_UNLIKELY((vlSelf->counter_en & 0xfeU))) {
        Verilated::overWidthError("counter_en");}
}
#endif  // VL_DEBUG
