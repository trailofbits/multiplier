# __Multiplier__ finds more bugs faster

Multiplier provides precise and comprehensive code understanding capabilities.
It does so by persisting build artifacts into a database, and then making them
persistently accessible using a C++ or Python API.

Multiplier emphasizes the ability to unique identify *all* entities in a build
process, including individual tokens, AST nodes, and intermediate
representations. With Multiplier, an analyst can identify code patterns of
interest over one of the representations, and then accurately relay results back
to humans in a readable form, or to follow-on scripts via entity IDs.

Multiplier's APIs are extensive, and often provide as-good or better-than
compiler-level quality information, but linked at a whole-program level. We like
to say that with its APIs, *you can get everywhere from anywhere*.

* About
  * [How do other indexers work](docs/other-indexers.md), and why the normal way of indexing code is insufficient for C/C++ 
  * [Why Multiplier?](docs/why-multiplier.md) What analysis challenges does Multiplier solve?
* Usage
  * [Getting and building the code](docs/BUILD.md)
  * [Installing a pre-built release](docs/INSTALLING.md)
  * [How to index a codebase](docs/INDEXING.md)
* Included tools
  * [Find function calls inside macro argument lists](docs/mx-find-calls-in-macro-expansions.md)
  * [Find possible divergent representations](docs/mx-find-divergent-candidates.md)
  * [Find uses of `copy_to_user` in the Linux kernel that overwrite flexible array members](docs/mx-find-flexible-user-copies.md)
  * [Find data structures containing self-referential pointers, such as linked lists and trees](docs/mx-find-linked-structures.md)
  * [Find "sketchy" casts flowing to function arguments and to return sites](docs/mx-find-sketchy-casts.md)
  * [Extract an entity, e.g. a function, and all of its dependencies into a file](docs/mx-harness.md)
  * [Highlight a specific entity within its surrounding code](docs/mx-highlight-entity.md)
  * [Print a call graph](docs/mx-print-call-graph.md)
  * [Print the reference graph](docs/mx-print-reference-graph.md)
  * [Print a graph relating source code, macros, parsed tokens, and AST nodes](docs/mx-print-token-graph.md)
  * [Print the taint graph given a taint source, and treating memory dereferences as taint sinks](docs/mx-taint-entity.md)
* Included utilities
  * [Find entities in the database given a symbol name](docs/mx-find-symbol.md)
  * [List all indexed files](docs/mx-list-files.md)
  * [List all indexed functions](docs/mx-list-functions.md)
  * [List all indexed macros](docs/mx-list-macros.md)
  * [List all redeclarations of a given entity](docs/mx-list-redeclarations.md)
  * [List all indexed structures/unions/classes/enums](docs/mx-list-structures.md)
  * [List all indexed variables](docs/mx-list-variables.md)
  * [Search the code with regular expressions](docs/mx-regex-query.md)
* Writeups
  * [PHP variant analysis](docs/php-variant-analysis.md)

# License

This research was developed with funding from the Defense Advanced Research
Projects Agency (DARPA). The views, opinions and/or findings expressed are those
of the author and should not be interpreted as representing the official views
or policies of the Department of Defense or the U.S. Government.
