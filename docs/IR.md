# Multiplier IR Design

## Overview

Multiplier generates a per-function intermediate representation (IR) at index time by walking the PASTA AST. The IR is serialized as flat lists inside each fragment's Cap'n Proto message and can be queried through entity IDs. Global variables with initializers also get synthetic IR functions.

## Entity Types

The IR consists of six entity types, each with its own entity ID scheme:

| Entity | ID Type | Sub-kind | Description |
|--------|---------|----------|-------------|
| `IRFunction` | `IRFunctionId` | 1 slot | A function body or global initializer |
| `IRBlock` | `IRBlockId` | `BlockKind` (14) | A basic block in the CFG |
| `IRInstruction` | `IRInstructionId` | `OpCode` (71) | A single instruction |
| `IRObject` | `IRObjectId` | 1 slot | A memory object (local, param, global, etc.) |
| `IRSwitchCase` | `IRSwitchCaseId` | 1 slot | A case/default in a switch |
| `IRStructure` | `IRStructureId` | `StructureKind` (18) | A structural nesting entity (scope, control flow) |

All entity IDs embed the entity's kind in the sub_kind field, enabling type discrimination without loading the entity.

## Functions

Each `IRFunction` represents either a normal function body or a global variable initializer.

**`FunctionKind`**: `NORMAL`, `GLOBAL_INITIALIZER`

- `NORMAL`: generated from a `FunctionDecl` with a body. `declaration()` returns the `FunctionDecl`.
- `GLOBAL_INITIALIZER`: synthetic function for a global variable's initialization. `source_declaration()` returns the `VarDecl`. The body contains `ADDRESS_OF` + initializer + `STORE` + `RET`.

Key accessors: `kind()`, `declaration()`, `source_declaration()`, `entry_block()`, `blocks()` (RPO order), `objects()`, `body_scope()`.

## Blocks

Each `IRBlock` is a basic block in the CFG. The last instruction is always a terminator.

**`BlockKind`** (14 kinds): `ENTRY`, `IF_THEN`, `IF_ELSE`, `IF_MERGE`, `LOOP_CONDITION`, `LOOP_BODY`, `LOOP_EXIT`, `LOOP_INCREMENT`, `SWITCH_CASE`, `SWITCH_DEFAULT`, `SWITCH_EXIT`, `LABEL`, `UNREACHABLE`, `GENERIC`.

Key accessors: `kind()`, `parent_structure()`, `instructions()` (top-level roots), `all_instructions()` (post-order including sub-expressions), `successors()`, `predecessors()`, `immediate_dominator()`, `immediate_post_dominator()`, `dominators()`, `post_dominators()`, `dominates()`.

## Instructions

Instructions use a single `OpCode` enum (71 values). They are laid out in children-before-parents order within each block. Each instruction carries a `sourceEntityId` linking to the originating AST node.

### Instruction Categories

**Constants**: `CONST_INT`, `CONST_FLOAT`, `CONST_NULL`

**Memory**: `ALLOCA`, `LOAD`, `STORE`, `ADDRESS_OF`, `GEP_FIELD`, `PTR_ADD`

**Arithmetic**: `ADD`, `SUB`, `MUL`, `DIV`, `REM`, `BIT_AND`, `BIT_OR`, `BIT_XOR`, `SHL`, `SHR`, `LOGICAL_AND`, `LOGICAL_OR`, `PTR_DIFF`

**Comparison**: `CMP_EQ`, `CMP_NE`, `CMP_LT`, `CMP_LE`, `CMP_GT`, `CMP_GE`

**Unary**: `NEG`, `BIT_NOT`, `LOGICAL_NOT`

**Casts**: `CAST_SEXT`, `CAST_ZEXT`, `CAST_TRUNC`, `CAST_BITCAST`, `CAST_PTR_TO_INT`, `CAST_INT_TO_PTR`, `CAST_FP_TO_SI`, `CAST_SI_TO_FP`, `CAST_FP_TRUNC`, `CAST_FP_EXT`, `CAST_INT_CAST`, `CAST_FP_CAST`

**Call/Compound**: `CALL`, `SIZE_OF`, `INC_DEC`, `COMPOUND_ASSIGN`, `SELECT`, `COPY`, `INIT_LIST`

**Memory intrinsics**: `MEMSET` (dest, byte_value, size), `MEMCPY` (dest, src, size). Calls to `memset`, `memcpy`, `memmove`, and their `__builtin_` variants are lowered to these opcodes instead of generic `CALL`.

**Variadic**: `VA_PACK`, `VA_START`, `VA_ARG`, `VA_COPY`, `VA_END`

**Scope markers**: `ENTER_SCOPE`, `EXIT_SCOPE`. Non-terminator instructions that mark scope boundaries. Each carries the `IRStructureId` of the scope being entered/exited in the entity pool.

**Terminators**: `COND_BRANCH`, `SWITCH`, `RET`, `UNREACHABLE`, `BREAK`, `CONTINUE`, `GOTO`, `IMPLICIT_GOTO`, `FALLTHROUGH`, `IMPLICIT_FALLTHROUGH`, `IMPLICIT_UNREACHABLE`

**Other**: `UNKNOWN` (unhandled expression)

### Typed Instruction Classes

The read-side API provides typed wrappers with a `from(const IRInstruction &)` static method:

| Class | Opcodes | Key Accessors |
|-------|---------|---------------|
| `ConstIntInst` | `CONST_INT` | `signed_value()`, `unsigned_value()`, `width()`, `type()` |
| `ConstFloatInst` | `CONST_FLOAT` | `value()`, `width()`, `type()` |
| `ConstNullInst` | `CONST_NULL` | `type()` |
| `AllocaInst` | `ALLOCA` | `allocated_type()`, `object()` |
| `LoadInst` | `LOAD` | `address()`, `loaded_type()` |
| `StoreInst` | `STORE` | `address()`, `stored_value()` |
| `AddressOfInst` | `ADDRESS_OF` | `type()`, `object()` |
| `GEPFieldInst` | `GEP_FIELD` | `base()`, `result_type()`, `field()`, `byte_offset()` |
| `PtrAddInst` | `PTR_ADD` | `base()`, `index()`, `result_type()`, `element_type()`, `element_size()` |
| `BinaryInst` | `ADD`..`PTR_DIFF` | `lhs()`, `rhs()`, `result_type()` |
| `ComparisonInst` | `CMP_EQ`..`CMP_GE` | `lhs()`, `rhs()`, `result_type()` |
| `UnaryInst` | `NEG`, `BIT_NOT`, `LOGICAL_NOT` | `operand()`, `result_type()` |
| `CastInst` | `CAST_*` | `operand()`, `result_type()` |
| `SizeOfInst` | `SIZE_OF` | `measured_type()`, `result_type()`, `static_size()` |
| `CallInst` | `CALL` | `target()`, `is_indirect()`, `arguments()`, `result_type()` |
| `IncDecInst` | `INC_DEC` | `address()`, `is_increment()`, `is_prefix()`, `result_type()` |
| `CompoundAssignInst` | `COMPOUND_ASSIGN` | `address()`, `value()`, `underlying_op()`, `result_type()` |
| `SelectInst` | `SELECT` | `condition()`, `true_value()`, `false_value()`, `result_type()` |
| `CopyInst` | `COPY` | `source()`, `result_type()` |
| `InitListInst` | `INIT_LIST` | `elements()`, `result_type()` |
| `MemsetInst` | `MEMSET` | `dest()`, `byte_value()`, `size()` |
| `MemcpyInst` | `MEMCPY` | `dest()`, `src()`, `size()` |
| `VAStartInst` | `VA_START` | `va_list_operand()` |
| `VAEndInst` | `VA_END` | `va_list_operand()` |
| `VACopyInst` | `VA_COPY` | `dest()`, `src()` |
| `VAArgInst` | `VA_ARG` | `va_list_operand()`, `result_type()` |
| `VAPackInst` | `VA_PACK` | `arguments()` |
| `RetInst` | `RET` | `return_value()` |
| `BranchInst` | `GOTO`, `IMPLICIT_GOTO`, `BREAK`, `CONTINUE`, `FALLTHROUGH`, `IMPLICIT_FALLTHROUGH` | `target_block()` |
| `CondBranchInst` | `COND_BRANCH` | `condition()`, `true_block()`, `false_block()` |
| `SwitchInst` | `SWITCH` | `selector()`, `case_type()`, `cases()`, `num_cases()` |
| `UnreachableInst` | `UNREACHABLE`, `IMPLICIT_UNREACHABLE` | -- |
| `UnknownInst` | `UNKNOWN` | -- |

## Objects

`IRObject` represents a memory location. All locals use alloca/load/store (no SSA).

**`ObjectKind`** (11 kinds): `LOCAL`, `LOCAL_VALUE`, `PARAMETER`, `PARAMETER_VALUE`, `GLOBAL`, `THREAD_LOCAL`, `STRING_LITERAL`, `COMPOUND_LITERAL`, `RETURN_SLOT`, `ALLOCA`, `HEAP`.

- `LOCAL` / `PARAMETER`: address-taken, requires alloca/load/store.
- `LOCAL_VALUE` / `PARAMETER_VALUE`: not address-taken, pure value (candidate for future `mem2reg` promotion).
- `RETURN_SLOT`: created for non-void functions.

Key accessors: `kind()`, `source_declaration()`, `type()`, `size_bytes()`, `align_bytes()`, `needs_memory()`.

## Structural Hierarchy

`IRStructure` represents the nesting structure of a program. Every block has a parent structure, and structures form a tree rooted at `FUNCTION_SCOPE`.

**`StructureKind`** (18 kinds):

| Kind | Description |
|------|-------------|
| `FUNCTION_SCOPE` | Function body (root of structure tree) |
| `SCOPE` | Nested CompoundStmt, or implicit scope for for-init declarations |
| `IF` | Entire if statement |
| `IF_THEN` | Then branch |
| `IF_ELSE` | Else branch |
| `FOR` | Entire for loop |
| `FOR_INIT` | `for(init; ...)` |
| `FOR_CONDITION` | `for(...; cond; ...)` |
| `FOR_BODY` | Loop body |
| `FOR_INCREMENT` | `for(...; ...; inc)` |
| `WHILE` | Entire while loop |
| `WHILE_CONDITION` | While condition |
| `WHILE_BODY` | While body |
| `DO_WHILE` | Entire do-while loop |
| `DO_WHILE_BODY` | Do-while body |
| `DO_WHILE_CONDITION` | Do-while condition |
| `SWITCH` | Entire switch statement |
| `SWITCH_CASE` | Individual case/default |

Key accessors: `kind()`, `source_statement()`, `parent_structure()`, `parent_function()`, `child_structures()`, `child_blocks()`, `objects()` (ALLOCAs declared in scope), `is_scope()`.

### Scope Tracking

`ENTER_SCOPE` and `EXIT_SCOPE` instructions are emitted at scope boundaries:
- **Normal flow**: `ENTER_SCOPE` at CompoundStmt entry, `EXIT_SCOPE` at exit.
- **Non-local exits**: `break`, `continue`, `return`, and `goto` emit `EXIT_SCOPE` for every scope they exit through, innermost first.
- **For-init scopes**: `for (int i = 0; ...)` wraps the entire loop in an implicit `SCOPE` so `i` has correct lifetime.

Scope structures track which objects (ALLOCAs) are declared in them via `objects()`. An emulator can use this to initialize memory on scope entry and poison/free it on scope exit.

### Example Structure Tree

```
IRFunction (NORMAL)
  FUNCTION_SCOPE
    [ENTRY block]
    IF
      [condition in current block]
      IF_THEN
        SCOPE
          [IF_THEN block] -> ENTER_SCOPE, instructions, EXIT_SCOPE
      IF_ELSE
        SCOPE
          [IF_ELSE block] -> ENTER_SCOPE, instructions, EXIT_SCOPE
      [IF_MERGE block]
    SCOPE (implicit, for-init)
      FOR
        FOR_INIT
        FOR_CONDITION -> [LOOP_CONDITION block]
        FOR_BODY
          SCOPE -> [LOOP_BODY block]
        FOR_INCREMENT -> [LOOP_INCREMENT block]
      [LOOP_EXIT block]
```

## Design Decisions

### Statement-Level CFG, Not Clang CFG

The IR builds its own statement-level control flow graph rather than using Clang's `clang::CFG`. Clang's CFG splits short-circuit operators (`&&`, `||`) and ternary (`?:`) into separate basic blocks, destroying expression tree structure. Our IR keeps expressions as nested instruction trees within blocks, splitting only at statement-level control flow (`if`, `while`, `for`, `switch`, `goto`, `break`, `continue`, `return`).

For `if ((x + y) && z)`, Clang's CFG creates 4+ blocks. Our IR keeps it as one block with a nested `logical_and(add(load(x), load(y)), load(z))` instruction tree.

### Single Unified OpCode Enum

All instruction types share a single `OpCode` enum rather than separate enums for binary ops, comparisons, casts, etc. This drives the C++ class hierarchy on the read side and is embedded in entity IDs.

### Flat Layout in Fragment

IR entities are stored as flat lists in the fragment proto. No separate database table for IR -- it loads with the fragment (zero extra I/O for AST-to-IR navigation). Entity IDs follow the standard `(fragment_id, sub_kind, offset)` pattern.

### Children-Before-Parents Instruction Ordering

Instructions within a block are laid out in post-order: children (sub-expressions) appear before their parents. Each instruction has a `parentOffset` field (distance to parent in the flat list, 0 = top-level root). This enables bottom-up traversal by scanning forward, top-down traversal by following operand indices, and identifying statement-level roots by `parentOffset == 0`.

### Maximum Entity ID Provenance

Every instruction carries `sourceEntityId` linking back to the originating AST `Stmt`/`Expr`. Calls carry `targetEntityId` for the callee `FunctionDecl`. GEP fields carry `targetEntityId` for the `FieldDecl`. Objects carry `sourceDeclId` for the `VarDecl`. No names are stored -- resolve entity IDs through the Multiplier API.

### Address-Taken Classification

Objects are classified at generation time:
- `LOCAL` / `PARAMETER`: address-taken, needs alloca/load/store
- `LOCAL_VALUE` / `PARAMETER_VALUE`: non-address-taken, pure value (candidate for future SSA promotion)

### Explicit vs Implicit Control Flow

The IR distinguishes user-written control flow from structural CFG edges:
- `GOTO` vs `IMPLICIT_GOTO`: user `goto` vs structural edge (e.g., end of if-then to merge)
- `FALLTHROUGH` vs `IMPLICIT_FALLTHROUGH`: `[[fallthrough]]` attribute vs missing `break`
- `BREAK`, `CONTINUE`: separate opcodes with source entity IDs

### Conditionally-Executed Flag

Instructions under short-circuit operators or ternary branches are marked with `isConditionallyExecuted` (bit 2 in flags). For `A || B`, everything reachable from `B` is conditionally executed. For `a ? b : c`, both `b` and `c` subtrees are marked.

### Variadic Argument Handling

Variadic function calls emit a `VA_PACK` instruction grouping the variadic arguments, placed where the `...` parameter would be. The receiving side uses `VA_START`, `VA_ARG`, `VA_COPY`, `VA_END` opcodes.

### Alloca-Based Memory Model

All local variables use alloca/load/store, even non-address-taken ones. There are no SSA phi nodes or block arguments. The `LOCAL_VALUE`/`PARAMETER_VALUE` object kinds mark variables that *could* be promoted to SSA by a future `mem2reg` pass, but currently all variables go through memory.

### Use-Def Chains

Each instruction stores a `users` list: the entity IDs of instructions that consume this instruction's value as an operand. This enables forward data flow analysis without scanning all instructions.

### Dominator Trees

Dominator and post-dominator trees are computed at index time (Cooper-Harvey-Kennedy algorithm) and stored directly on each block as entity ID lists. Immediate dominator/post-dominator are also stored.

### Pool-Based Encoding

Instructions use two shared pools:
- **Entity pool** (`irEntityPool`): stores entity IDs for parent block, source entity, result type, operands, and opcode-specific extras.
- **Int pool** (`irIntPool`): stores constants (integer values, sizes, widths).

Each instruction's `entityOffset` and `constOffset` index into these pools. The layout per instruction is: `[parentBlockOrInstruction, sourceEntityId, resultType, operand0..N, extras...]`.

## Cap'n Proto Schema

```
Fragment {
  irFunctions:    List(Function)
  irBlocks:       List(Block)
  irInstructions: List(Instruction)
  irObjects:      List(Object)
  irSwitchCases:  List(SwitchCase)
  irStructures:   List(Structure)
  irEntityPool:   List(UInt64)
  irIntPool:      List(Int64)
}
```

## What's Not Implemented Yet

- `IRSwitchCase` migration to `IRStructure(SWITCH_CASE)` (currently coexists)
- C++ specific: constructors, destructors, new/delete, lambdas, exceptions
- `mem2reg` pass to promote `LOCAL_VALUE`/`PARAMETER_VALUE` to SSA
- String literal content storage on `IRObject`
- Full Python bindings for `IRStructure` (stub exists)
