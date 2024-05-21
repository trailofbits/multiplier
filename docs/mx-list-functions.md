# `mx-list-functions`

This tool is one of the easiest to understand, and it has some immediate value.
Its purpose is to list out functions in the indexed codebase.

```shell
% mx-list-functions --db /tmp/test.db 
1152921504606847018 2305843009213764380 9480077215935496192 memchr  decl
1152921504606847018 2305843009213764381 9480077215935561728 memcmp  decl
1152921504606847018 2305843009213764382 9480077215935627264 memcpy  decl
...
```

The format of the output is:

```
<file_id> <fragment_id> <decl_id> <name> <decl|def>
```

With the following interpretations:

* `file_id`: This is the entity ID of the file containing this function definition or declaration.
* `fragment_id`: This is the entity ID of the fragment containing this function definition or declaration. A fragment is a syntactically freestanding unit of code, and represents the unit of deduplication in Multiplier.
* `decl_id`: This is the entity ID of the `Decl` entity for this function. In general, this will be a `FunctionDecl`, but if C++ code is indexed then it could be a `CXXMethodDecl` or one of its derived classes, e.g. `CXXConstructor`.
* `name`: The name of the function. For C++ code, this will show fully qualified names.
* `decl|def`: If `decl` is printed, then this is a function declaration. If `def` is printed, then this function is a definition, i.e. it has a body.

If the `--list_variables` option is passed then all variables of each function,
including parameter variables, are listed. Adding `--show_locations` shows
source locations for everything.
