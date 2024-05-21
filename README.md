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

- [Getting and building the code](docs/BUILD.md)
- Included utilities:
  - [mx-find-symbol](): Find entities in the database given a symbol name
  - [mx-list-files](): List all indexed files
  - [mx-list-functions](): List all indexed functions
  - [mx-list-macros](): List all indexed macros
  - [mx-list-redeclarations](): List all redeclarations of a given entity
  - [mx-list-structures](): List all indexed structures/unions/classes/enums
  - [mx-list-variables](): List all indexed variables
  - [mx-regex-query](): Peform a regular expression-based search through the code
- Included tools:
  - [mx-find-calls-in-macro-expansions](): Finds function calls that are inside
    of the argument list of macros
  - [mx-find-divergent-candidates](): Find potential variants of [divergent representations](https://blog.trailofbits.com/2022/11/10/divergent-representations-variable-overflows-c-compiler/) in source code.
  - [mx-find-flexible-user-copies](): Find uses of `copy_to_user` in the Linux kernel that overwrite [flexible array members](https://en.wikipedia.org/wiki/Flexible_array_member)
  - [mx-find-linked-structures](): Find data structures containing self-referential pointers (e.g. linked lists, trees), or that transitively contain such self-referential data structures
  - [mx-find-sketchy-casts](): Generic "sketchy" cast finder (e.g. implicit downcasts)
  - [mx-harness](): Extract an entity (e.g. function) and all of its dependencies, and save them into a file
  - [mx-highlight-entity](): Highlight a specific entity within its surrounding code
  - [mx-print-call-graph](): Print a call graph (DOT digraph format)
  - [mx-print-reference-graph](): Print the reference graph (DOT digraph format)
  - [mx-print-token-graph](): Print the graph (DOT digraph format) relating source code, macros, parsed tokens, and AST nodes for a given fragment
  - [mx-taint-entity](): Print the taint graph (DOT digraph format) given a taint source, and treating memory dereferences as taint sinks



- [PHP Variant Analysis Example](docs/php-variant-analysis.md)

# License

This research was developed with funding from the Defense Advanced Research
Projects Agency (DARPA). The views, opinions and/or findings expressed are those
of the author and should not be interpreted as representing the official views
or policies of the Department of Defense or the U.S. Government.
