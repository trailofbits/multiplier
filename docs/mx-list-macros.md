# `mx-list-macros`

This tool lists all macros in the indexed codebase.

```shell
% mx-list-macros --db /tmp/test.db 
1152921504606847012 2305843009213693953 17926578318895742976  EnumAttrInt
1152921504606846997 2305843009214742980 13314892298794827776  _GLIBCXX_NOEXCEPT_IF
1152921504606847010 2305843009214743153 13314892298976231424  ABSL_CORD_INTERNAL_NO_SANITIZE
1152921504606847010 2305843009214743154 13314892298977280000  assert
...
```

The format of the output is:

```
<file_id> <fragment_id> <macro_id> <name>
```

Adding `--show_locations` shows source locations for everything.
