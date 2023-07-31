package iFu

import circt.stage.ChiselStage
import chisel3.stage.ChiselGeneratorAnnotation

object Main extends App {
    val targetDirectory = args.head
    
    (new ChiselStage).execute(
        Array(
            "-X", "sverilog", 
            "-e", "iFu.iFuCore",
            "-td", targetDirectory
        ),
        Seq(ChiselGeneratorAnnotation(() => new iFuCore))
    )
}