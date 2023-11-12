// See README.md for license details.
import sbt.project

ThisBuild / scalaVersion     := "2.13.10"
ThisBuild / version          := "3.0"
ThisBuild / organization     := "fdu"

val chiselVersion = "3.6.0"

lazy val root = (project in file("."))
  .settings(
    name := "iFu",
    libraryDependencies ++= Seq(
      "edu.berkeley.cs" %% "chisel3" % chiselVersion,
      "edu.berkeley.cs" %% "chiseltest" % "0.6.0" % "test"  // ???
    ),
    scalacOptions ++= Seq(
      "-language:reflectiveCalls",
      "-deprecation",
      "-feature",
      "-Xcheckinit",
    ),
    addCompilerPlugin("edu.berkeley.cs" % "chisel3-plugin" % chiselVersion cross CrossVersion.full),
  )

