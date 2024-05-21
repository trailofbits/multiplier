# Multiplier: Find more bugs faster

Multiplier provides precise, and comprehensive code understanding capabilities
by storing a compressed representation of build artifacts, called entities, in
an index database. Entities in Multiplier’s index include files, tokens, macro
expansions, abstract syntax tree (AST) nodes, and compilations (represented with
MLIR). Each entity is uniquely identified by a 64 bit integer, and is available
through scripting in C++ or Python as a fully formed object with methods. For
example, the AST entities (declarations, statements, types, templates, etc.) are
persistent forms of AST nodes found in Clang, and the methods available on these
entities mirror those that can be called on those objects in-memory in Clang.
With Multiplier's API, you can get everywhere from anywhere.

* [Getting and building the code](docs/BUILD.md)
* About:
  * [How do other indexers work](docs/other-indexers.md), and why the normal way of indexing code is insufficient for C/C++ 
  * [What analysis challenges Multiplier solves](docs/why-multiplier.md)
* Included tools:
  * [Finds function calls that are inside of the argument list of macros](docs/mx-find-calls-in-macro-expansions.md)
  * [Find possible divergent representations](docs/mx-find-divergent-candidates.md)
  * [Find uses of `copy_to_user` in the Linux kernel that overwrite flexible array members](docs/mx-find-flexible-user-copies.md)
  * [Find data structures containing self-referential pointers, such as linked lists and trees](docs/mx-find-linked-structures.md)
  * [Generic finder for "sketchy" casts flowing to function arguments and to return sites](docs/mx-find-sketchy-casts.md)
  * [Extract an entity, e.g. a function, and all of its dependencies into a file](docs/mx-harness.md)
  * [Highlight a specific entity within its surrounding code](docs/mx-highlight-entity.md)
  * [Print a call graph](docs/mx-print-call-graph.md)
  * [Print the reference graph](docs/mx-print-reference-graph.md)
  * [Print a graph relating source code, macros, parsed tokens, and AST nodes](docs/mx-print-token-graph.md)
  * [Print the taint graph given a taint source, and treating memory dereferences as taint sinks](docs/mx-taint-entity.md)
- Included utilities:
  - [Find entities in the database given a symbol name](docs/mx-find-symbol.md)
  - [List all indexed files](docs/mx-list-files.md)
  - [List all indexed functions](docs/mx-list-functions.md)
  - [List all indexed macros](docs/mx-list-macros.md)
  - [List all redeclarations of a given entity](docs/mx-list-redeclarations.md)
  - [List all indexed structures/unions/classes/enums](docs/mx-list-structures.md)
  - [List all indexed variables](docs/mx-list-variables.md)
  - [Search the code with regular expressions](docs/mx-regex-query.md)
- Writeups
  - [PHP variant analysis](docs/php-variant-analysis.md)

# License

This research was developed with funding from the Defense Advanced Research
Projects Agency (DARPA). The views, opinions and/or findings expressed are those
of the author and should not be interpreted as representing the official views
or policies of the Department of Defense or the U.S. Government.
