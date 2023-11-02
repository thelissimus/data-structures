import Lake
open Lake DSL

package «lean» {
}

lean_lib «Lean» {
}

@[default_target]
lean_exe «lean» {
  root := `src.Main
}
