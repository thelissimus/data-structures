lazy val root = project
  .in(file("."))
  .settings(
    name              := "datastructures",
    version           := "0.0.0",
    scalaVersion      := "3.3.0",
    semanticdbEnabled := true,
    semanticdbVersion := scalafixSemanticdb.revision,
    libraryDependencies ++= Seq(
      "org.typelevel" %% "cats-core" % "2.10.0",
    ),
  )
