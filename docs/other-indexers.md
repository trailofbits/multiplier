# Other Indexers

Why are typical code indexers, such as [clangd](https://clangd.llvm.org/), [ccls](https://github.com/MaskRay/ccls), [kythe](https://kythe.io/), [SourceGraph](https://sourcegraph.com/), etc., insufficient for C / C++ code?

### How does a typical code indexer work?

Most indexers store subject-predicate-object triples:
 * Subject: Qualified name, mangled name, [USR](https://clang.llvm.org/doxygen/group__CINDEX__CURSOR__XREF.html), etc.
 * Predicate: called-from, read-by, written-by, member-of, etc.
 * Object: `file:line:column` source location, or a subject

Indexers then provide the appearance of understanding the semantics of code by using the triple format above to implement verb-specific queries, e.g. find me all derived classes of this thing, and "clickable" code, i.e. by matching source locations to subjects/objects during code rendering / visualization.

### Why is the typical code indexing approach insufficient for C / C++?

First, **the semantic depth is fundamentally limited by the predicate space**. If you want more information, then you need to modify the indexer to record triples containing new predicates. We suffered this problem in [Multiplier v1](https://github.com/trailofbits/multiplier-old) and don't want to repeat it. In general, Multiplier strives to minimize the need for users to ask for API extensions by maximizing the amount of information is available by default. That is a key motivation for why PASTA tries to comprehensively cover the Clang API, and why Multiplier tries to persist the API surface of PASTA.

Second, **C/C++ code is fundamentally polymorphic, and source locations cannot convey the semantic depth needed to enable *context-sensitive* source navigation**. A user that is browsing code should be able to ask for the callers of a class `MyClass`'s constructor, and discover that `std::vector<MyClass>::push_back` invokes `MyClass::MyClass`. Then, the user should be able to ask for callers of `std::vector<MyClass>::push_back`, and find *only* those calls to `push_back` that are specific to that overload of the `push_back` method of the `std::vector<MyClass>` template specialization.

Thus, typical code indexers are 1-context-sensitive, but not n-context-sensitive. That is, from a given point, they can follow a triple to the relevant location, but once there, further navigation uses file locations as the source of truth, and thus loses sensitivity. Perhaps a quad format, e.g. `subject-verb-context-object` could ameliorate this situation, but this is not how typical code indexers work.