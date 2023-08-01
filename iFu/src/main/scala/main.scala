package iFu

import chisel3.stage.ChiselGeneratorAnnotation
import firrtl.TargetDirAnnotation

object Main extends App {
    val targetDirectory = args.head
    val buildArgs = if (args(1).toBoolean) {
        Array(
            "-X", "sverilog", 
        )
    } else {
        Array(
            "-X", "sverilog", 
            "-e", "verilog",
        )
    }
    
    new chisel3.stage.ChiselStage().execute(
        buildArgs,
        Seq(
            ChiselGeneratorAnnotation(() => new iFuCore),
            TargetDirAnnotation(targetDirectory)
        )
    )
}