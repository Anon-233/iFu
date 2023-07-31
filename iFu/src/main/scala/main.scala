package iFu

import circt.stage.ChiselStage
import chisel3.stage.ChiselGeneratorAnnotation
import firrtl_interpreter.TargetDirAnnotation

object Main extends App {
    val targetDirectory = args.head
    
    new ChiselStage().execute(
        Array(
            "-X", "sverilog", 
            "-e", "verilog",
        ),
        Seq(
            ChiselGeneratorAnnotation(() => new iFuCore),
            TargetDirAnnotation(targetDirectory)
        )
    )
}