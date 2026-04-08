# IR Gap-Fixing Loop Prompt

You are running autonomously in a loop. Never ask questions. Never propose plans for approval. Just do the work. If you face a decision, make it, document why in a commit message, and move on.

## Goal

Fix the gaps documented in `IR_GAPS.md`, working through them in priority order. Each cycle should pick the next unfinished item, implement it, build, test, commit, and mark it done.

## Priority Order

### Phase A: MEM opcode (replaces LOAD/STORE/ATOMIC_LOAD/ATOMIC_STORE)

Replace LOAD, STORE, ATOMIC_LOAD, ATOMIC_STORE with a single `MEM` opcode. Sub-opcodes (`MemAccessOp`) encode direction, endianness, size, and atomicity:

```
LOAD_LE_8, LOAD_LE_16, LOAD_LE_32, LOAD_LE_64,
LOAD_BE_8, LOAD_BE_16, LOAD_BE_32, LOAD_BE_64,
STORE_LE_8, STORE_LE_16, STORE_LE_32, STORE_LE_64,
STORE_BE_8, STORE_BE_16, STORE_BE_32, STORE_BE_64,
ATOMIC_LOAD_LE_8, ATOMIC_LOAD_LE_16, ATOMIC_LOAD_LE_32, ATOMIC_LOAD_LE_64,
ATOMIC_LOAD_BE_8, ATOMIC_LOAD_BE_16, ATOMIC_LOAD_BE_32, ATOMIC_LOAD_BE_64,
ATOMIC_STORE_LE_8, ATOMIC_STORE_LE_16, ATOMIC_STORE_LE_32, ATOMIC_STORE_LE_64,
ATOMIC_STORE_BE_8, ATOMIC_STORE_BE_16, ATOMIC_STORE_BE_32, ATOMIC_STORE_BE_64,
```

Add helpers: `IsLoad(MemAccessOp)`, `IsStore(MemAccessOp)`, `IsAtomic(MemAccessOp)`, `IsBigEndian(MemAccessOp)`, `AccessSize(MemAccessOp) -> unsigned`.

Determine endianness at codegen time from `ctx_.getTargetInfo().isBigEndian()`.
Determine size from the type being loaded/stored.

Files to modify: OpCode.h, InstructionKinds.h/.cpp, IRGen.cpp, SerializeIR.cpp, InterpretIR.cpp, Enums.cpp, Types.cpp.

Replace `MemInst` (or `LoadInst`/`StoreInst`/`AtomicLoadInst`/`AtomicStoreInst`) with a single `MemInst` class: `sub_opcode()`, `address()`, `stored_value()` (for stores), `result_type()` (for loads).

### Phase B: LAST_VALUE instruction

Add `LAST_VALUE` opcode for comma operator and other "evaluate both, return last" patterns. `op[0..N-1]` = expressions to evaluate in order. Result = last operand's value.

Update EmitRValue for BinaryOperator::kComma to emit LAST_VALUE instead of orphaning the LHS.

### Phase C: Fix pointer decrement bug

In EmitRValue for pre/post decrement of pointers, the RMW underlying op is PTR_ADD for both increment AND decrement. For decrement, the RHS should be -1 (negated), or use SUB. Fix the codegen.

### Phase D: Fix IRObject::source_declaration() and type()

Implement the declared-but-unimplemented methods in lib/IR/Object.cpp. The source VarDecl entity ID is stored in the Object capnp struct's `sourceDeclId` field. The type entity ID is in `typeEntityId`.

### Phase E: Add EnterScopeInst / ExitScopeInst classes

Add instruction classes for ENTER_SCOPE and EXIT_SCOPE. They should expose `scope() -> IRStructure` by reading the IRStructureId from the entity pool extra.

### Phase F: Add IRBlock::parent_function() and IRFunction::containing(IRInstruction)

Convenience methods. Block walks parent_structure chain to root, calls parent_function(). Instruction goes through parent_block().

### Phase G: DesignatedInitExpr handling

In EmitInitializer, handle DesignatedInitExpr by looking at the designators (field designators for structs, array designators for arrays) and computing the correct destination address via GEP_FIELD or PTR_ADD.

### Phase H: Missing float builtins

Add sin, cos, tan, asin, acos, atan, atan2, exp, exp2, log, log2, log10, pow, fmod, remainder, fma, hypot, erf, erfc, tgamma, lgamma to the FloatOp enum and recognition table.

### Phase I: Fix bit-field initialization

In EmitInitializer, check `field.IsBitField()`. For bit-fields, emit a read-modify-write sequence: LOAD the containing byte(s), mask/shift the field value, OR it in, STORE back.

### Phase J: Interpreter improvements

- Make LOAD/STORE size-aware (from MEM sub-opcode after Phase A)
- Implement SCOPE tracking (set poisoned flag on EXIT_SCOPE)
- Implement remaining MULTIMEM sub-opcodes
- Add LAST_VALUE to interpreter

## Coding Style

- **Naming**: `snake_case` for methods/variables, `PascalCase` for types, `SCREAMING_SNAKE` for enums.
- **No glog in lib/**: Use `assert()`. `bin/` can use glog.
- **Commit identity**: `--author="Peter Goodman <peter.goodman@gmail.com>"` with `GIT_COMMITTER_NAME="Peter Goodman" GIT_COMMITTER_EMAIL="peter.goodman@gmail.com"`.
- **Build**: `cmake --build ~/Build/multiplier/Release/multiplier -j$(sysctl -n hw.ncpu)`
- **Build target for quick iteration**: `cmake --build ~/Build/multiplier/Release/multiplier --target mx-index mx-interpret-ir -j$(sysctl -n hw.ncpu)`

## Rules

- Build after every significant change. Fix build errors immediately.
- Commit frequently. Don't accumulate large uncommitted deltas.
- Update `IR_GAPS.md` after each phase: mark items as DONE.
- Update `docs/IR.md` when opcodes change.
- When all phases are complete, output "IR GAPS FIXED" and stop.
