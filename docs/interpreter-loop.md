# Interpreter Loop: From Unit Tests to Real Programs

## Mission

Make `mx-interpret-ir` execute a real, indexed C program starting from `main()`,
producing the same observable output (exit code, stdout, file output) as the
natively compiled binary. This is differential testing: interpretation must be
indistinguishable from native execution for the chosen program.

## Current State

- **31/34 unit tests pass** (up from 25/34 baseline).

- **Newly passing**: test_function_calls (all 5 subtests including variadics),
  test_globals, test_struct_assign, test_string_literals, test_array_decay,
  test_byvalue.

- **34/34 tests pass** (with re-indexed DB).

## Active Restructure (in progress)

Architecture is being converted from class-based Interpreter to a state
transition function. Partially complete — headers are written, codegen
has frame layout computation, but Interpreter.cpp needs full rewrite.

### What's done:
- `Interpreter.h`: new API — `InterpreterState` struct + free `InitState()`/`Step()` functions
- `Suspension.h`: suspension types renamed to describe what's needed (`NeedCallResolution`, `NeedGlobalResolution`, `NeedBranchDecision`, `NeedConcretePointer`)
- `Driver.h`: simplified to single `Resolve(Suspension) → Resolution` method
- `ConcreteDriver.h/.cpp`: updated to new suspension/resolution types
- `Memory.h`: added `WritePointer()`/`ReadPointer()` for provenance tracking
- `IR.capnp`: added `frameOffset` to Object, `frameSizeBytes`/`hasDynamicAllocas` to Function
- `IRGen.h/.cpp`: `ObjectIR` has `frame_offset`, `FunctionIR` has `frame_size_bytes`/`has_dynamic_allocas`, `ComputeFrameLayout()` assigns aligned offsets
- `SerializeIR.cpp`: serializes the new fields
- `Object.h/.cpp`, `Function.h/.cpp`: read-side API for new fields
- `Enums.cpp`: `EnumeratorName()` returns `nullptr` for gap values (fixes Python binding crash)
- Python bindings: skip null enum names

### What's NOT done:
- `Interpreter.cpp`: still has old class-based code, won't compile against new headers
- `InterpretIR.cpp` (CLI): needs updating for new Step API
- pointer_shadow removal from MemWriteValue/MemReadValue
- CALL handling: needs to push/pop frames instead of recursive child interpreters
  - CallFrame needs `resume_after_inst` (RawEntityId, kInvalidEntityId = no pending call)
  - After callee RETs, store return value in values[resume_after_inst], clear resume_after_inst
  - Actually: callee writes to return_ptr in memory, caller reads from return slot — no special plumbing
- Memory: frame allocation (`AllocateFrame`/`FreeFrame`) instead of per-object Allocate
  - ALLOCA resolves to `frame_base + obj.frame_offset()` — no runtime allocation

### Key design decisions:
- Step is a free function, not a method
- State owns call stack + globals map (memory is a separate parameter)
- CALL pushes a callee frame, RET pops it — no recursive child interpreters
- `resume_after_inst` in CallFrame tracks where to continue after a callee returns
- Instructions are failure-atomic: suspend on unresolved operands, don't silently skip
- pointer_shadow is removed — Memory stores real bytes, WritePointer/ReadPointer for provenance
- Stack frames are single allocations with pre-computed offsets, not per-object mallocs

### Codegen changes also in this branch:
- Duff's device: collect_cases recurses into case sub-statements
- Duff's device: emit_case_bodies handles DoStmt with loop back-edge
- Implicit default for switches without explicit default
- Guard against inner switch case leakage in collect_cases
- emit_case_bodies handles nested SwitchStmt as sub-statement
- CompoundStmts processed after terminators (for goto-into-scope)
- ENTER_SCOPE skipped when block is already terminated
- CONSUME_VA_PARAM wrapped in LOAD by codegen
- va_copy implemented
- New test cases for goto-after-return patterns

- **2 remaining failures before restructure** (both now pass with re-indexed DB):
  - `test_variadics` (returns 5): wider variadic types (double, struct) not yet
    handled by CONSUME_VA_PARAM.
  - `test_evil_goto` (returns 1): codegen bug — `collect_cases` and
    `emit_case_bodies` in IRGen.cpp don't recurse deeply enough into Duff's
    device `DoStmt` to find nested case statements. `collect_cases` fix is in
    place; `emit_case_bodies` needs the same fix. Also added implicit default
    for switches without explicit `default`. Needs debug build to trace AST.

- **Architecture**: policy-based (ValueFactory, Memory, Driver). Interpreter
  delegates all computation. Cross-cutting concerns via composition/proxying.

- **Key files**:
  - `include/multiplier/IR/Interpret/*.h` (Value, Memory, ValueFactory, Driver,
    Suspension, Interpreter, Concrete{ValueFactory,Memory,Driver})
  - `lib/IR/Interpret/*.cpp` (implementations)
  - `bin/InterpretIR/InterpretIR.cpp` (CLI driver, ~140 lines)
  - `tests/InterpretIR/` (test suite, `run_tests.sh`)

## Candidate Program Selection

Pick a C program that:

1. **Is self-contained**: single file or a few files, no autoconf/cmake, no
   complex build system. Can be compiled with a single `clang` invocation.
2. **Avoids opaque libc types**: no `FILE*`, no `DIR*`, no `jmp_buf`. These
   require modeling internal libc layout which is not portable.
3. **Has verifiable output**: produces deterministic output that can be compared
   byte-for-byte (hash output, compression round-trip, encoded data).
4. **Exercises real patterns**: function calls, globals, structs, arrays, loops,
   pointers, string operations. Not just toy arithmetic.
5. **Is small enough to debug**: under 2000 lines. You need to be able to trace
   through the IR when things go wrong.

**Good candidates** (in order of preference):

- **A SHA-256 implementation** (~300 lines). Pure computation on byte arrays.
  Input is a fixed string, output is a hex digest. No IO beyond
  memcpy/memset/strlen. Easy to verify: compare hex output against `shasum`.
- **A CRC32 implementation** (~100 lines). Even simpler. Table-driven, pure
  computation.
- **A base64 encoder/decoder** (~200 lines). String in, string out.
- **xxHash** (~400 lines, single-file). Very portable, no deps.

**Avoid**: anything with `printf` (format string interpretation is a rabbit
hole), `fopen`/`fread` (opaque `FILE` type), `malloc` (heap management can be
stubbed but adds complexity early), signal handlers, threads.

**Indexing budget**: if indexing a candidate takes more than ~2 hours of
wall-clock debugging, abandon it and try the next one. The indexer may have
issues with certain code patterns; don't fight the tool.

## Phase 1: Fix Interprocedural Calls

**Goal**: `test_function_calls` passes (direct calls, recursion, function
pointers, higher-order functions).

The current CALL handler at `lib/IR/Interpret/Interpreter.cpp:1264` creates a
recursive `Interpreter` instance for each call. This works for intra-fragment
calls but likely fails for cross-fragment function resolution.

**Diagnosis steps**:
1. Run `test_function_calls` with a debug build under lldb. Break at the CALL
   handler. Check: does `IRFunction::from(*target)` return a valid function?
2. If not: the issue is that `target` is an `IRInstruction` referencing a
   declaration, and `IRFunction::from()` needs to look up the function's IR
   across fragments. The `Index` is needed but the interpreter doesn't have it.
3. The interpreter needs access to the index (or a function resolver) to look up
   callees by declaration.

**Design consideration**: the interpreter currently takes `(ValueFactory, Memory,
Driver)`. It doesn't know about the index. Function resolution is a Driver
concern. Extend `CallSuspension` or `Driver::ResolveCall` to return the callee's
`IRFunction` when the action is `INLINE`. Or: give the interpreter an
`std::function<std::optional<IRFunction>(const FunctionDecl &)>` resolver at
construction time. Think about which preserves IoC better.

**Do NOT**: hardcode index access into the interpreter. The interpreter should
not know about `mx::Index`. The resolver is injected.

## Phase 2: Fix Global Initialization

**Goal**: `test_globals` passes.

Globals in the IR use `GLOBAL_PTR` instructions that reference global variable
declarations. The interpreter needs to:

1. Allocate memory for each global on first access (lazy init).
2. Run the global's initializer (if it has one) to populate the memory.
3. Return a pointer to the allocated memory.

**Design**: global state lives in `Memory`, not per-`CallFrame`. The interpreter
(or a helper) maintains a `map<RawEntityId, uint64_t>` mapping global entity IDs
to their allocated addresses. On first `GLOBAL_PTR` encounter:
- Look up the global's `VarDecl` from the IR instruction's source.
- Allocate `VarDecl::size()` bytes in memory.
- If the global has a `GLOBAL_INITIALIZER` function in the IR, run it.
- Otherwise, zero-initialize.

**Watch out**: circular initialization, globals that reference other globals.
Keep a "currently initializing" set to detect cycles.

## Phase 3: Fix Remaining Unit Test Failures

Before moving to a real program, get as many unit tests passing as possible.
Each failure is a signal about a missing interpreter capability.

- `test_struct_assign`: likely needs proper aggregate copy (memcpy through
  struct assignment).
- `test_string_literals`: needs `STRING_PTR` to properly allocate and populate
  string literal data.
- `test_byvalue`: pass-by-value struct parameters.
- `test_evil_goto`: non-trivial control flow.

Fix these in order of difficulty (easiest first). Each fix likely generalizes to
patterns the real program will need.

## Phase 4: Index and Run a Real Program

1. Write or obtain the candidate C program.
2. Create `compile_commands.json` for it.
3. Run `mx-index` to create the database.
4. Verify the IR looks reasonable: run `mx-interpret-ir --db <db> --entity_name main`
   and see how far it gets before failing.
5. Iterate: each failure reveals a missing feature. Fix it, re-run, repeat.

**External function handling**: when the interpreter encounters a CALL to a
function with no IR (external/libc function), it needs to handle it. The current
code returns `undef`. Instead:

- The `Driver::ResolveCall` path should check the function name.
- For known functions (memcpy, memset, strlen, strcmp, etc.), implement them
  directly using the interpreter's `Memory` interface.
- Start with the functions the candidate program actually calls. Don't
  speculatively implement functions you don't need yet.
- Each external function implementation reads arguments from the call's argument
  list (which are pointers into interpreter memory) and operates on interpreter
  memory directly.

**Naming convention for external function handlers**: group by category (memory,
string, math) but keep the dispatch simple. A single `switch` or `map<string,
handler>` is fine. Don't over-abstract.

**If you need syscalls** (open, read, write, exit): these are stretch goals.
Start with function-name-based stubs. If a syscall layer becomes necessary:
- Add a `HYPERCALL` or `EXTERN_CALL` concept to the Driver interface.
- Sub-opcodes for each syscall (OPEN, READ, WRITE, CLOSE, EXIT, etc.).
- Implementations pass through to real host syscalls, translating addresses
  between interpreter memory and host memory.
- Be mindful: interpreter pointers are not host pointers. Any data passed to a
  real syscall must be copied from interpreter memory to a host buffer first,
  and results copied back.

## Self-Review Protocol

After every significant change (more than ~50 lines), pause and ask:

### 1. Am I maintaining inversion of control?

- Does the interpreter know about concrete types it shouldn't?
- Am I adding `#include <multiplier/Index.h>` to `Interpreter.cpp`? That's a
  red flag. The interpreter delegates to policies; it doesn't reach into the
  index directly.
- Could a different Driver implementation (symbolic, taint-tracking) still work
  with this interpreter? If my change assumes concrete execution, it's in the
  wrong place.

### 2. Is there a common theme?

- Am I adding three similar switch cases? Extract the pattern.
- Am I handling "external memcpy" differently from "external memset"? They're
  both "external function with known semantics operating on interpreter memory."
  The dispatch mechanism should be uniform.
- Look for the abstraction that's trying to emerge. Don't force it, but don't
  ignore it either.

### 3. Am I repeating myself?

- Copy-pasted code is a bug waiting to happen. If two code paths do similar
  things with minor variations, factor out the common part.
- But: three similar lines is better than a premature abstraction. Only
  generalize when the pattern is clear and stable.

### 4. Am I adding complexity that doesn't pay for itself?

- Every abstraction has a cost (indirection, cognitive load, maintenance).
- A 10-line inline handler for `strlen` is better than a 50-line generic
  "string function framework" that only handles `strlen`.
- Ask: "if I delete this abstraction and inline the code, is it clearer?" If
  yes, delete the abstraction.

### 5. Is my code testable?

- Can I write a unit test (a `.c` file + expected return value) for the feature
  I just added?
- If the feature is "globals work," write `test_globals.c` (already exists) and
  verify it passes.
- **Run the full test suite after every change.** Regressions are cheap to fix
  when caught immediately, expensive when caught later.

## Task Tracking

Use a simple checklist. After each session, update it:

```
## Checklist
- [x] test_function_calls passes (direct, recursive, indirect, higher-order, variadic)
- [x] test_globals passes (simple, array, struct, static local, file-scope static)
- [x] test_struct_assign passes
- [x] test_string_literals passes (was already passing after CALL arg fix)
- [x] test_byvalue passes (unified return: scalar ≤8B read from slot, aggregate >8B via pointer)
- [ ] test_evil_goto passes (returns 1 — duffs_copy; complex structured goto/switch patterns)
- [ ] Candidate program selected and indexed
- [ ] Candidate program's main() starts executing (reaches first call)
- [ ] All internal function calls in candidate work
- [ ] External function stubs implemented for candidate's needs
- [ ] Candidate produces correct output (differential test passes)
- [x] No unit test regressions (30/34 tests pass, up from 25/34 baseline)
```

## How to Self-Prompt

At the start of each work session:

1. **Read this document** to re-orient.
2. **Run the test suite**: `cd tests/InterpretIR && bash run_tests.sh mx-index.db ~/Build/multiplier/Release/multiplier/bin/mx-interpret-ir`
3. **Check the checklist**: what's the next unchecked item?
4. **Pick the highest-value, lowest-risk task**. Prefer tasks that unblock
   multiple downstream items (e.g., fixing calls unblocks everything that calls
   functions).
5. **After making changes**: rebuild, run tests, update checklist, self-review.

At the end of each work session:

1. **Run the full test suite** and record results.
2. **Update the checklist** above.
3. **Note any architectural decisions** made and why, so future sessions don't
   re-derive them.
4. **If stuck**: describe the problem clearly, what you've tried, and what you
   think the root cause is. This is your context for the next session.

## Build Commands

```bash
# Build (Release)
cd ~/Build/multiplier/Release/multiplier && ninja -j$(sysctl -n hw.ncpu) mx-interpret-ir

# Run single test
~/Build/multiplier/Release/multiplier/bin/mx-interpret-ir \
  --db tests/InterpretIR/mx-index.db --entity_name test_function_calls

# Run full suite
cd tests/InterpretIR && bash run_tests.sh mx-index.db \
  ~/Build/multiplier/Release/multiplier/bin/mx-interpret-ir

# Index a new program
~/Build/multiplier/Release/multiplier/bin/mx-index \
  --db <output.db> --workspace <workspace_dir> \
  --target compile_commands.json --fork_mode
```

## Architectural Invariants (do not violate)

1. **Interpreter never includes `<multiplier/Index.h>`**. Function and global
   resolution is delegated to policies/injected resolvers.
2. **No `LOG()` or `glog` in `lib/`**. Use `assert()` for invariant violations.
   Return error values for expected failures.
3. **`MX_EXPORT` on all public classes** in `include/multiplier/IR/Interpret/`.
4. **Float32 values use `MakeFloat32`, float64 use `MakeFloat`**. Never mix.
   Constants, loads, arithmetic results must all use the width-correct constructor.
5. **No hardcoded paths or usernames** in committed code.
6. **Policy interfaces are synchronous**. If you need async, build it inside a
   proxy. The interpreter never manages event loops or work lists.
7. **Values are opaque to the interpreter**. The interpreter passes values
   around but only inspects them through factory/memory calls. Direct access to
   `ScalarValue::bits` in `Interpreter.cpp` is a smell (except in
   `MemWriteValue`/`MemReadValue` which are the serialization boundary).
