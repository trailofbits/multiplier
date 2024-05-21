# Why Multiplier?

**What analysis challenges does Multiplier solve?**

Most program analyses operate on at most one representation, e.g. a program's
AST, [LLVM IR](https://llvm.org/docs/LangRef.html), or machine code. These
analyses use approximate source location information embedded to report their
results back to users. Then, it's up to the user to open their code editor of
choice, find the relevant lines of code, and stare hard at them until the
results make sense. This process fails on two key fronts.

First, focusing on a single abstract program representation limits the scope of
what can be achieved with program analysis. There is no one-size-fits-all
program abstraction. High-level representations are dense and rely on implicit
behaviors. Low-level representations are more efficiently analyzable but also
harder to relate to source (e.g., inlined and optimized data structure
operations). Exploits cross the semantic gap, from logic bugs that are apparent
only in high-level source, to byte locations that are knowable only in low-level
representations. What is needed are multiple representations that can span this
semantic gap, enabling analyses to operate at the best-fit level, without losing
the connection back to source.

Second, code locations are approximate, and even when precise, they may point
the user to "unhelpful" locations, such as macro definitions, or generic methods
within C++ templates that, only through specialization, take on concrete
meaning. Having a user navigate to these locations is only slightly burdensome.
The true loss in capability is the inability for users to create workflows that
leverage results produced by one analysis and use them in another analysis. How
is a second analysis supposed to do anything meaningful when a first analysis
tells us about a polymorphic source location like a line of code inside of a
macro definition or C++ class template?

The crux of the problem is that the source of truth for typical code indexers,
language servers, code editors, and even debugging formats is the
`file:line:column` source location triple. Source locations cannot express that
some code is part of a macro expansion or template specialization. In fact, the
most reliable way to follow code references while maintaining the proper
context-sensitivity is to browse the compiled machine code in an interactive
disassembler like Ghidra. This is because machine code has already been
monomorphized: macro expansions and template specializations produce different
machine code located at different addresses. When you click on a call to
`std::vector<char>::push_back`, it brings you to a different address than
  clicking on a call to `std::vector<double>::push_back`.

Multiplier provides precise, and comprehensive code understanding capabilities
by storing a compressed representation of build artifacts, called entities, in
an index database. Entities in Multiplier's index include files, tokens, macro
expansions, abstract syntax tree (AST) nodes, and compilations (represented with
[MLIR](https://github.com/trailofbits/vast)). Each entity is uniquely identified
by a 64 bit integer, and is available through scripting in C++ or
[Python](https://www.python.org/) as a fully formed object with methods. For
example, the AST entities (declarations, statements, types, templates, etc.) are
persistent forms of AST nodes found in [Clang](https://clang.llvm.org), and the
methods available on these entities mirror those that can be called on those
objects in-memory in Clang. Although Multiplier is based on Clang, it breaks
from it in how it represents and relates entities to source code. Whereas Clang
stores source locations, Mutliplier stores token entity IDs. Token entities can
belong to files, macro expansions, or template specializations. In the latter
two cases, macro and template tokens can relate back to file tokens. This allows
polymorphic code, e.g. a template specialization declaration AST node, to have
its own version of the source code. This mirrors a compiler's normal process of
monomorphization during code generation, and provides a
"[Ghidra](https://ghidra-sre.org/), but for source code" capability.
