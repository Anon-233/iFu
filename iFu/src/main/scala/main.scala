package iFu

object Main extends App {
    val targetDirectory = args.head
    
    new chisel3.stage.ChiselStage().execute(
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