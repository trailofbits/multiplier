# IR Implementation Loop Prompt

You are running autonomously in a loop. Never ask questions. Never propose plans for approval. Never say "should I" or "would you like". Just do the work. If you face a decision, make it, document why in a commit message, and move on. If you're wrong, a future cycle will catch and fix it.

## Goal

Build the Multiplier IR into a system capable of supporting concrete and symbolic interpretation. This means: every piece of data an interpreter needs must be immediately accessible, correctly typed, non-optional when it can't actually be absent, and organized so that walking the IR doesn't require cross-entity-type joins for common operations.

## Design Plan

Follow the plan in `~/.claude/plans/robust-plotting-rocket.md`. Phase 1 (FunctionKind discriminator) is already complete. Continue with Phases 2-4 in order. Adapt the plan to reality as you go — the plan is a design document, not copy-pasteable code.

## Multiplier Coding Style and Conventions

- **Naming**: `snake_case` for methods and variables. `PascalCase` for types/classes. `SCREAMING_SNAKE` for enum values. `kCamelCase` for constants.
- **Methods**: All public methods take `(void)` for no-arg, return by value. Use `const &` for generators.
- **Optionality**: If something cannot actually be absent at runtime, do NOT make it optional. Use `assert` to validate in debug. Return the value directly. An `IRBlock` always has a kind. An `IRInstruction` always has an opcode. A `ConstIntInst` always has a type. Only use `std::optional` when the value is genuinely sometimes absent (e.g., `CallInst::result_type()` for void calls).
- **String views**: Return `std::string_view`, not `std::optional<std::string_view>`. Empty string view (from `""`) if no data.
- **Entity references**: Return the entity itself (`IRBlock`, `IRInstruction`), not the entity ID, unless the caller specifically needs the ID. IDs are for serialization and cross-fragment lookups. Within a fragment, return entities.
- **No glog in mx library**: The `lib/` directory (mx-api) must NOT link glog/gflags. Use `assert()` for invariant checks. The `bin/Index/` code (mx-index) can use glog (`LOG`, `DCHECK`, `CHECK`).
- **Pool encoding**: Instructions use `irEntityPool` (entity IDs) and `irIntPool` (constants). Position 0 = parentBlockOrInstruction, position 1 = sourceEntityId, position 2 = resultType (if value-producing), then operands, then extras.
- **Entity IDs encode kinds**: `IRBlockId` embeds `BlockKind`, `IRInstructionId` embeds `OpCode`, `IRStructureId` should embed `StructureKind`. This enables type discrimination without loading the entity.
- **capnp changes cause full recompiles**: Minimize changes to `IR.capnp` and `RPC.capnp`. Get the schema right, then stop touching it.
- **MX_FOR_EACH_ENTITY_CATEGORY**: Has 8 callback slots. The `ir_` callback handles all IR entity types. Adding a new IR entity type means adding a line to this macro, updating ~60 call sites, adding entity provider stubs, Python bindings, etc.
- **Bootstrap**: If you change the bootstrap (`bin/Bootstrap/PASTA.cpp`), rebuild in `~/Build/multiplier/Release/multiplier-bootstrap/` which auto-runs `mx-bootstrap-pasta` as a post-build step. Then rebuild the main project.
- **Python bindings**: Generated files in `bindings/Python/Generated/` are picked up by `file(GLOB_RECURSE)`. New IR entity bindings follow the `IRObject.cpp` pattern (gTypes array slot, PythonBinding template specializations). Update `Forward.h`, `Module.cpp`, `PythonBindings.py`, `Python.cpp`.
- **Commit identity**: Always use `--author="Peter Goodman <peter.goodman@gmail.com>"` and set `GIT_COMMITTER_NAME="Peter Goodman" GIT_COMMITTER_EMAIL="peter.goodman@gmail.com"`.

## What the System is Currently Lying About

Fix these as you encounter them:

1. **No structural nesting.** Blocks are flat within a function. An emulator can't ask "what scope am I in?" or "what variables go dead when I leave this block?" The plan fixes this with IRStructure.
2. **No scope lifetime tracking.** ALLOCAs are all in the entry block with no association to their declaring scope. An emulator can't mark memory as uninitialized on scope entry or dead on scope exit.
3. **IRSwitchCase is a separate entity type when it should be a structural entity.** It will be migrated to `IRStructure(SWITCH_CASE)`.
4. **No global initializer functions.** Global variables with initializers have no IR representation of their initialization logic.
5. **`IRObject::string_bytes()` doesn't exist.** String literal objects don't expose their raw bytes — an emulator would need to hop through AST provenance to get them.
6. **Some instructions have orphaned sub-expressions.** `EmitInstruction()` creates instructions not reachable from any block root. Fixed by `parent_block_index` field, but watch for new cases.

## Thinking Like an Interpreter Author

When you add or modify IR:

- **Dense iteration**: An interpreter walks instructions sequentially within a block. The data it needs (operand values, types, object references) must be immediately accessible from the instruction, not requiring lookups into other entity types.
- **Sparse navigation**: A symbolic executor needs to jump to a specific call target, find all uses of a value, or check what variables are live at a program point. Entity IDs and use-def chains serve this.
- **Scope awareness**: When the interpreter enters a scope, it needs the list of objects (ALLOCAs) declared in that scope to initialize their memory. When it exits, it needs to poison/free them. ENTER_SCOPE/EXIT_SCOPE + `IRStructure::objects()` provides this.
- **Type fidelity**: Every value-producing instruction carries its result type. Casts are explicit. Pointer arithmetic knows the element type and size. The interpreter never has to guess.
- **Control flow correctness**: Every block ends with a terminator. Unreachable blocks have `IMPLICIT_UNREACHABLE`. Unterminated function bodies get an implicit `RET`. The CFG is always well-formed.

## Verification

After each significant change:
1. Build: `cmake --build ~/Build/multiplier/Release/multiplier -j$(sysctl -n hw.ncpu) 2>&1 | tail -30`
2. If only indexer changed: `cmake --build ~/Build/multiplier/Release/multiplier --target mx-index -j$(sysctl -n hw.ncpu)`
3. Index a test project and check for crashes/assertion failures
4. Verify entity ID round-trips: pack → unpack → repack should be identity
5. Verify parent chains: every block has a parent structure, every structure has a parent structure or function
6. Verify scope objects: every ALLOCA in a scope's object list actually has its VarDecl declared in that scope's CompoundStmt
7. Check Python bindings build: full build includes `multiplier.cpython-313-darwin.so`

## Known Extensions (implement alongside or after the plan)

These are concrete features that are needed for a working interpreter. Implement them when the right infrastructure is in place.

### MEMSET / MEMCPY Instructions

Add `MEMSET` and `MEMCPY` opcodes. These are first-class IR instructions, not calls.

**Why:** Global initializers need to zero-fill structs (`memset`), copy aggregate initializers (`memcpy`), etc. Local variable initialization (alloca init) uses them too. An interpreter must understand these as primitive memory operations, not opaque function calls.

**Operands:**
- `MEMSET`: op[0] = dest address, op[1] = byte value, op[2] = size. Result type = void.
- `MEMCPY`: op[0] = dest address, op[1] = src address, op[2] = size. Result type = void.

**Generation:** Recognize calls to `memset`, `memcpy`, `memmove`, `__builtin_memset`, `__builtin_memcpy`, `__builtin_memcpy_chk`, `__builtin_memmove`, `__builtin_memset_chk`, etc. in `EmitRValue` when processing `CallExpr`. Lower them to the IR instruction instead of a generic `CALL`. Maintain AST provenance to the original `CallExpr` via `source_entity_id`.

Also emit these directly during initialization codegen (global initializers, alloca zero-init) even when there's no source-level call — the IR creates them synthetically.

### VAR_INIT Block Kind

Add `VAR_INIT` to the `BlockKind` enum. Initialization code for variables — whether from global initializer functions or local alloca initializers — goes in `VAR_INIT` blocks.

**Why:** An interpreter needs to distinguish "this code initializes a variable" from "this code is regular program logic." When symbolically executing, the interpreter may want to skip or summarize initialization, or verify that an initializer is well-formed. The `VAR_INIT` block's provenance traces back to the initializer `Expr` (init-list, aggregate, constructor call, etc.).

**Generation:** When emitting initialization code for a `VarDecl` (in `EmitDeclStmt` for locals, or in the global initializer function), create a `VAR_INIT` block for the initialization instructions. The block's source entity ID is the initializer expression. The ALLOCA stays in the entry block; the init code goes in the VAR_INIT block, which flows into the next regular block.

### VAR_INIT Structural Entity

Add `VAR_INIT` to the `StructureKind` enum as well, so the structural tree can represent "this region initializes variable X." The `VAR_INIT` structure's source entity is the `VarDecl`, its child block is the `VAR_INIT` block, and its parent is the enclosing scope.

## Going Beyond the Plan

After completing the planned phases and known extensions, you may identify and implement additional features. But you must follow this process:

### 1. Identify what's missing
Ask: "If I were writing a concrete interpreter or symbolic executor for vulnerability research right now, what would I reach for that isn't there?" Think about:
- Taint analysis (tracking which values derive from attacker-controlled input)
- Buffer overflow detection (bounds of allocations, pointer arithmetic validation)
- Use-after-free detection (scope lifetimes, heap object lifetimes)
- Integer overflow/underflow (type widths, signedness at every operation)
- Null pointer dereference (tracking nullability through control flow)
- Format string vulnerabilities (identifying format strings, matching args to specifiers)
- Uninitialized memory reads (scope entry/exit, which stores have happened)
- Double-free detection (tracking allocation/deallocation pairs)
- Inter-procedural analysis (call graph edges, parameter passing, return values)

### 2. Write a user/agent story
Every feature beyond the original plan MUST have a corresponding story in `IR_TODOS.md` before implementation. Format:

```
### Feature: <name>
**Story:** A vulnerability researcher (or automated agent) using the Multiplier Python API wants to <specific goal>.
Without <feature>, they must <painful workaround or impossibility>.
With <feature>, they can <concrete capability>.

**Example:** To detect use-after-free in function `foo`, the agent iterates blocks in RPO,
tracks ENTER_SCOPE/EXIT_SCOPE to know which objects are live, and checks that every LOAD
targets a live object. Without scope tracking, the agent cannot determine object liveness.
```

### 3. Scrutinize your own justification
Before implementing, challenge yourself:
- "Is this actually needed, or am I gold-plating?" — If the use case is speculative or the workaround is tolerable, skip it.
- "Can the user already do this with existing APIs?" — Check if the information is reachable through AST provenance, entity IDs, or existing IR accessors before adding new ones.
- "Does this belong in the IR, or in a separate analysis pass?" — The IR should store *facts* (types, control flow, data flow). Derived information (taint labels, reachability, alias sets) belongs in analysis passes built on top of the IR.
- "Would Chris Lattner or Peter Goodman look at this and say 'why is this here?'" — If the answer is yes, don't add it.

### 4. Implement incrementally
If the feature passes scrutiny: plan it, implement it, build, test, commit. One feature at a time. Don't batch speculative features.

## Tracking

Create `IR_TODOS.md` in the repo root to track progress. Update it each cycle with:
- What was completed
- What's next
- Any decisions made and why
- Known issues / lies remaining
- Any beyond-plan features with their user/agent stories and justification status

## Rules

- Build after every significant change. Fix build errors immediately.
- Commit frequently. Don't accumulate large uncommitted deltas.
- The build directory is: `~/Build/multiplier/Release/multiplier`
- The bootstrap build directory is: `~/Build/multiplier/Release/multiplier-bootstrap`
- Read existing code before writing new code. Understand the patterns first.
- When `IR_TODOS.md` shows all phases complete with no remaining items, output "IR IMPLEMENTATION COMPLETE" and stop.
- If you encounter a crash during indexing, fix it before moving on. Don't leave broken state.
- Prefer fixing the root cause over adding workarounds. If something is architecturally wrong, fix the architecture.
- Don't add features beyond what the plan calls for. Stay focused.
- capnp field renames are binary-compatible (same ordinal). New fields get new ordinals. Never reuse ordinals.
- Test with: `~/Build/multiplier/Release/multiplier/bin/mx-index --db /tmp/test.db --target /path/to/test.c` (or whatever test project is convenient).
