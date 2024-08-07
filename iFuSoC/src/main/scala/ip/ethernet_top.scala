package ip

import chisel3.{BlackBox, Bool, Bundle, Flipped, Input, Output}
import common.{AXI, MAC}

//class EthernetIO extends MAC {
//    val hclk = Input(Bool())
//    val hrst_ = Input(Bool())
//    val m = Flipped(new AXI)
//    val s = new AXI
//}

class ethernet_top extends BlackBox {
    val io = IO(new Bundle {
        val hclk = Input(Bool())
        val hrst_ = Input(Bool())
        val m = Flipped(new AXI)
        val s = new AXI
        val interrupt0 = Output(Bool())
        val mac = new MAC
    })
}
