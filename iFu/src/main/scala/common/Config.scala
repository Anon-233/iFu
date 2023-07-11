package iFu.config

import chisel3._

final case class FrontendConfig(
    fetchWidth: Int = 8
)

final case class iFuConfig(
    frontend: FrontendConfig = FrontendConfig()
)

object iFuConfig {
    def normal = iFuConfig()
}