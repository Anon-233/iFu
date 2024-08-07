package common

import chisel3.{Bundle, Data}

object BulkConnect {
    def apply(left: Bundle, right: Bundle, asType: Bundle): Unit = {
        asType.elements.foreach { case (name, _) => left.elements(name) <> right.elements(name) }
    }
}
