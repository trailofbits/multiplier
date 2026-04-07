# Multiplier IR

## Overview

Multiplier generates a per-function intermediate representation (IR) at index time. The IR is a statement-level control flow graph where expressions are nested instruction trees within basic blocks. Every function with a body gets an IR, and every global variable with an initializer gets a synthetic initializer function.

The IR is designed for concrete and symbolic interpretation. Every piece of data an interpreter needs is immediately accessible: types are explicit in opcodes (no need to query the type system), control flow is well-formed (every block ends with a terminator), and the structural nesting of scopes and control flow is fully represented.

## Worked Example

Given this C function:

```c
int sum(int n) {
    int total = 0;
    for (int i = 0; i < n; i++) {
        total += i;
    }
    return total;
}
```

The IR looks like:

```
FRAME block (BlockKind::FRAME):
  ALLOCA %0 : int        // parameter 'n'
  ALLOCA %1 : int        // local 'total'
  ALLOCA %2 : int        // local 'i'
  IMPLICIT_GOTO → entry

ENTRY block (BlockKind::ENTRY):
  ENTER_SCOPE (FUNCTION_SCOPE)
  PARAM_READ 0            // read parameter 'n'
  STORE %0, ^             // store into n's alloca
  CONST(INT32) 0
  STORE %1, ^             // total = 0
  IMPLICIT_GOTO → scope_entry

scope_entry block:
  ENTER_SCOPE (SCOPE)     // implicit scope for for-init decl
  IMPLICIT_GOTO → preheader

LOOP_PREHEADER block (BlockKind::LOOP_PREHEADER):
  CONST(INT32) 0
  STORE %2, ^             // i = 0  (for-init lives in preheader)
  IMPLICIT_GOTO → loop_cond

LOOP_CONDITION block:
  LOAD %2                 // i
  LOAD %0                 // n
  CMP_LT ^, ^
  COND_BRANCH ^, loop_body, loop_exit

LOOP_BODY block:
  ENTER_SCOPE (SCOPE)     // for-body scope
  RMW %1, ADD, LOAD(%2)   // total += i
  EXIT_SCOPE
  IMPLICIT_GOTO → loop_inc

LOOP_INCREMENT block:
  RMW %2, ADD, CONST(INT32) 1   // i++
  IMPLICIT_GOTO → loop_cond

LOOP_EXIT block:
  EXIT_SCOPE              // for-init scope
  LOAD %1                 // total
  EXIT_SCOPE (FUNCTION_SCOPE)
  RET ^
```

Key observations:
- All ALLOCAs are in the FRAME block. The ALLOCA instruction IS the pointer to that variable — there is no separate ADDRESS_OF instruction.
- `PARAM_READ` explicitly reads the Nth parameter value and `STORE`s it into the parameter's alloca.
- `ENTER_SCOPE` / `EXIT_SCOPE` bracket the lifetimes of objects. The for-loop's init-declaration (`int i`) gets an implicit scope wrapping the entire loop.
- `RMW` (read-modify-write) handles `+=` and `++` — it reads from the address, applies the operation, writes back.
- Expressions are nested trees under their root instruction. `LOAD`, `CONST`, and other sub-expressions are operands of their parent.

## Functions

**`FunctionKind`**: `NORMAL`, `GLOBAL_INITIALIZER`

- **`NORMAL`**: Generated from a `FunctionDecl` with a body.
- **`GLOBAL_INITIALIZER`**: Synthetic function for a global or static local variable's initialization. Receives a pointer to the global as its single parameter (`PARAM_READ 0`). The body stores the initial value through that pointer.

```
// Global: int g = 42;
FRAME block:
  (empty — address comes via parameter)

ENTRY block:
  ENTER_SCOPE (FUNCTION_SCOPE)
  PARAM_READ 0             // pointer to g
  CONST(INT32) 42
  STORE ^, ^               // *g_ptr = 42
  EXIT_SCOPE
  RET
```

Key methods: `kind()`, `declaration()`, `source_declaration()`, `entry_block()`, `blocks()` (RPO order), `objects()`, `body_scope()`.

## Blocks

Each block ends with exactly one terminator instruction.

**`BlockKind`** (17 kinds):

| Kind | Description |
|------|-------------|
| `FRAME` | Contains all ALLOCAs (parameters + locals). Physical entry point. |
| `ENTRY` | Logical entry: ENTER_SCOPE, PARAM_READs, then function body. |
| `IF_THEN` | Then branch of if-statement. |
| `IF_ELSE` | Else branch. |
| `IF_MERGE` | Merge point after if. |
| `LOOP_PREHEADER` | Single-entry block before loop condition. For-init code lives here. |
| `LOOP_CONDITION` | While/for condition evaluation. |
| `LOOP_BODY` | Loop body. |
| `LOOP_EXIT` | Loop exit point. |
| `LOOP_INCREMENT` | For-loop increment. |
| `SWITCH_CASE` | Case body in switch. |
| `SWITCH_DEFAULT` | Default case body. |
| `SWITCH_EXIT` | Switch exit point. |
| `LABEL` | User-defined goto label target. |
| `COMPENSATION` | Scope transition block inserted on goto edges. |
| `UNREACHABLE` | Dead code after a terminator. |
| `GENERIC` | Unclassified. |

Key methods: `kind()`, `parent_structure()`, `instructions()` (top-level roots), `all_instructions()` (post-order including sub-expressions), `successors()`, `predecessors()`, `immediate_dominator()`, `dominates()`.

## Instructions

Instructions use a unified `OpCode` enum (74 values). Grouped opcodes carry a sub-opcode in the int pool for the specific operation.

### Layout Within Blocks

Instructions are stored in post-order (children before parents). Each instruction has a parent: either another instruction (sub-expression) or the block (top-level root). `block.instructions()` yields roots only; `block.all_instructions()` yields everything in evaluation order.

### Opcode Reference

**`CONST`** — Constant value. Sub-opcode (`ConstOp`) specifies exact type and width.

| Sub-opcode | Description |
|-----------|-------------|
| `INT8`, `INT16`, `INT32`, `INT64` | Signed integer constant. |
| `UINT8`, `UINT16`, `UINT32`, `UINT64` | Unsigned integer constant. |
| `FLOAT16`, `FLOAT32`, `FLOAT64` | Floating-point constant. |
| `NULL_PTR` | Null pointer. |
| `INF32`, `INF64` | Positive infinity. |
| `NAN32`, `NAN64` | NaN. |
| `WCHAR16`, `WCHAR32` | Wide character constant. |
| `BOOL` | Boolean constant. |

**`ALLOCA`** — Allocates stack memory for a variable. The instruction's value IS the pointer to the allocation. There is no separate "address-of" instruction — references to `&local_var` or `&param` use the ALLOCA result directly.

**`LOAD`** — Reads a value from a pointer. `op[0]` = address.

**`STORE`** — Writes a value to a pointer. `op[0]` = address, `op[1]` = value. No result.

**`GEP_FIELD`** — Struct field pointer. `op[0]` = base struct pointer. Carries the `FieldDecl` entity ID and byte offset.

**`PTR_ADD`** — Pointer arithmetic. `op[0]` = base pointer, `op[1]` = index. Carries element type and element size.

**`ADD`, `SUB`, `MUL`, `DIV`, `REM`** — Binary arithmetic. `op[0]` = lhs, `op[1]` = rhs.

**`BIT_AND`, `BIT_OR`, `BIT_XOR`, `SHL`, `SHR`** — Bitwise operations.

**`LOGICAL_AND`, `LOGICAL_OR`** — Short-circuit logical operators. Both operands are evaluated (the RHS is marked `is_conditionally_executed`). Not split into control flow.

**`PTR_DIFF`** — Pointer subtraction. Returns the difference in elements.

**`CMP_EQ`, `CMP_NE`, `CMP_LT`, `CMP_LE`, `CMP_GT`, `CMP_GE`** — Comparisons. Return integer 0 or 1.

**`NEG`, `BIT_NOT`, `LOGICAL_NOT`** — Unary operators.

**`CAST`** — Type conversion. Sub-opcode (`CastOp`) specifies exact source and destination types.

| Category | Examples |
|----------|---------|
| Sign-extend | `SEXT_I8_I16`, `SEXT_I16_I32`, `SEXT_I32_I64` |
| Zero-extend | `ZEXT_I8_I16`, `ZEXT_I16_I32`, `ZEXT_I32_I64` |
| Truncate | `TRUNC_I32_I16`, `TRUNC_I64_I32` |
| Int↔Float | `SI32_TO_F64`, `F64_TO_SI32`, `UI32_TO_F32`, ... |
| Float↔Float | `F32_TO_F64`, `F64_TO_F32` |
| Pointer | `PTR_TO_I64`, `I64_TO_PTR` |
| Other | `BITCAST`, `IDENTITY` |

Helpers: `IsSignExtend(CastOp)`, `IsZeroExtend(CastOp)`, `IsTruncate(CastOp)`, `IsIntToFloat(CastOp)`, `IsFloatToInt(CastOp)`.

**`CALL`** — Function call. For direct calls, carries the target `FunctionDecl` entity ID. For indirect calls (function pointers), `op[0]` is the callee expression. Variadic arguments are grouped under a `VA_PACK` sub-instruction.

**`READ_MODIFY_WRITE`** — Atomic read-modify-write pattern. `op[0]` = address, remaining operands are RHS values. Reads the value at the address, applies the underlying operation (stored in int pool as an `OpCode`), writes back. Flags bit 0: 1 = returns new value, 0 = returns old value.

Used for: `++i` (underlying=ADD), `i += 5` (underlying=ADD), `++ptr` (underlying=PTR_ADD with element size), `__builtin_add_overflow(a, b, &result)` (underlying=ADD_OVERFLOW, returns overflow flag).

**`SELECT`** — Ternary operator (`a ? b : c`). `op[0]` = condition, `op[1]` = true value, `op[2]` = false value. Both branches are marked `is_conditionally_executed`.

**Terminators**:

| Opcode | Description |
|--------|-------------|
| `COND_BRANCH` | `op[0]` = condition, branches to true/false blocks. |
| `SWITCH` | `op[0]` = selector. Cases are `IRSwitchCase` entities. |
| `RET` | `op[0]` = return value (optional for void). |
| `UNREACHABLE` | Explicit `__builtin_unreachable()`. |
| `BREAK`, `CONTINUE` | Loop/switch control flow with source provenance. |
| `GOTO` | Explicit `goto label`. May go through a COMPENSATION block. |
| `IMPLICIT_GOTO` | Structural CFG edge (e.g., end of if-then → merge). |
| `FALLTHROUGH` | Explicit `[[fallthrough]]` attribute. |
| `IMPLICIT_FALLTHROUGH` | Missing `break` at end of switch case. |
| `IMPLICIT_UNREACHABLE` | Patched empty block (structurally unreachable). |

**Scope markers** (non-terminators):

| Opcode | Description |
|--------|-------------|
| `ENTER_SCOPE` | Marks scope entry. Objects in the scope become live (but uninitialized). |
| `EXIT_SCOPE` | Marks scope exit. Objects become invalid (use-after-scope = UB). |

Both carry the `IRStructureId` of the scope in the entity pool.

**`MULTIMEM`** — Unified memory and string operations. Sub-opcode (`MemoryOp`) selects the operation.

| Category | Sub-opcodes |
|----------|-------------|
| Memory | `MEMSET`, `MEMCPY` (UB on overlap), `MEMMOVE` (safe), `MEMCMP`, `MEMCHR`, `BZERO` |
| String | `STRLEN`, `STRNLEN`, `STRCMP`, `STRNCMP`, `STRCHR`, `STRRCHR`, `STRSTR`, `STRCPY`, `STRNCPY`, `STRCAT`, `STRNCAT`, `STPCPY`, `STPNCPY` |
| String→Number | `STRTOI32`, `STRTOI64`, `STRTOU32`, `STRTOU64`, `STRTOF32`, `STRTOF64` |

String-to-number sub-opcodes are size-specific to avoid platform ambiguity. `atoi` → `STRTOI32`, `atol` → `STRTOI32` or `STRTOI64` depending on `sizeof(long)`.

Helpers: `IsStringToNumber(MemoryOp)`, `IsMemoryWrite(MemoryOp)`, `IsStringOp(MemoryOp)`.

Both library calls (`memcpy`, `strlen`, `atoi`) and `__builtin_` variants are recognized and lowered.

**`BITWISE`** — Bit manipulation intrinsics. Sub-opcode (`BitwiseOp`):

| Sub-opcode | Builtin | Defined for zero? |
|-----------|---------|-------------------|
| `BSWAP16`, `BSWAP32`, `BSWAP64` | `__builtin_bswap*` | Yes |
| `POPCOUNT` | `__builtin_popcount` | Yes |
| `CLZ` | `__builtin_clz` | **No** (undefined) |
| `CTZ` | `__builtin_ctz` | **No** (undefined) |
| `FFS` | `__builtin_ffs` | Yes (returns 0) |
| `PARITY` | `__builtin_parity` | Yes |
| `ABS` | `__builtin_abs` | **Undefined for INT_MIN** |
| `EXPECT` | `__builtin_expect` | Identity (hint) |
| `ASSUME` | `__builtin_assume` | No-op |

For CLZ/CTZ, the codegen emits `SELECT(x == 0, UNDEFINED, BITWISE(CLZ, x))`.

**`FLOAT`** — Floating-point intrinsics. Sub-opcode (`FloatOp`): `ISNAN`, `ISINF`, `ISFINITE`, `FABS`, `COPYSIGN`, `FMIN`, `FMAX`, `CEIL`, `FLOOR`, `ROUND`, `TRUNC`, `SQRT`, `INF`, `NAN_VAL`, `FLOAT_HUGE`.

**`PARAM_READ`** — Reads the Nth function parameter. Emitted in the ENTRY block. The parameter index is in the int pool. Result is the parameter value, which is then `STORE`d into the parameter's ALLOCA.

**`GLOBAL_PTR`** — Pointer to a global or static variable. Carries the `VarDecl` entity ID. No local alloca is involved.

**`FUNC_PTR`** — Pointer to a function. Carries the `FunctionDecl` entity ID.

**`UNDEFINED`** — Poison value. Represents architecturally undefined data. Any use should be flagged by an analyzer.

**`DYNAMIC_ALLOCA`** — Runtime stack allocation (`alloca(n)`). `op[0]` = size.

**`FRAME_PTR`** — `__builtin_frame_address(level)`. `op[0]` = level.

**`RETURN_PTR`** — `__builtin_return_address(level)`. `op[0]` = level.

**Atomics**:

| Opcode | Description |
|--------|-------------|
| `ATOMIC_LOAD` | `op[0]` = address. Atomic read. |
| `ATOMIC_STORE` | `op[0]` = address, `op[1]` = value. Atomic write. |
| `ATOMIC_CMPXCHG` | `op[0]` = target, `op[1]` = expected_ptr, `op[2]` = desired. Returns bool. |

Atomic fetch-and-modify operations use `READ_MODIFY_WRITE` with underlying opcodes: `ATOMIC_ADD`, `ATOMIC_SUB`, `ATOMIC_AND`, `ATOMIC_OR`, `ATOMIC_XOR`, `ATOMIC_NAND`, `ATOMIC_EXCHANGE`.

Overflow-checked arithmetic uses `READ_MODIFY_WRITE` with underlying opcodes: `ADD_OVERFLOW`, `SUB_OVERFLOW`, `MUL_OVERFLOW`. The RMW stores the arithmetic result and returns the overflow flag (bool).

**`UNKNOWN`** — Unhandled expression. Carries `source_entity_id` for AST inspection.

## Objects

`IRObject` represents a memory location. All locals use alloca/load/store.

**`ObjectKind`** (11 kinds):

| Kind | Description |
|------|-------------|
| `LOCAL` | Address-taken local variable. |
| `LOCAL_VALUE` | Non-address-taken local (candidate for SSA promotion). |
| `PARAMETER` | Address-taken parameter. |
| `PARAMETER_VALUE` | Non-address-taken parameter. |
| `GLOBAL` | Global variable. |
| `THREAD_LOCAL` | Thread-local variable. |
| `STRING_LITERAL` | String literal storage. |
| `COMPOUND_LITERAL` | Compound literal or aggregate temporary. |
| `RETURN_SLOT` | Implicit return value storage. |
| `ALLOCA` | Dynamic alloca (VLA). |
| `HEAP` | Heap-allocated (malloc). |

Key methods: `kind()`, `source_declaration()`, `type()`, `size_bytes()`, `align_bytes()`, `needs_memory()`.

## Structural Hierarchy

`IRStructure` represents the nesting structure of the program. Every block has a parent structure. Structures form a tree rooted at `FUNCTION_SCOPE`.

**`StructureKind`** (18 kinds):

| Kind | Derived Class | Description |
|------|--------------|-------------|
| `FUNCTION_SCOPE` | `IRScopeStructure` | Function body. Objects = parameters + top-level locals. |
| `SCOPE` | `IRScopeStructure` | Nested `{ }` block. Objects = locals declared in this block. |
| `IF` | `IRIfStructure` | Entire if-statement. `then_branch()`, `else_branch()`. |
| `IF_THEN` | `IRIfThenStructure` | Then branch. |
| `IF_ELSE` | `IRIfElseStructure` | Else branch. |
| `FOR` | `IRForStructure` | Entire for-loop. `init()`, `condition()`, `body()`, `increment()`. |
| `FOR_INIT` | — | For-init statement. |
| `FOR_CONDITION` | — | For condition. |
| `FOR_BODY` | — | For body. |
| `FOR_INCREMENT` | — | For increment. |
| `WHILE` | `IRWhileStructure` | Entire while-loop. `condition()`, `body()`. |
| `WHILE_CONDITION` | — | While condition. |
| `WHILE_BODY` | — | While body. |
| `DO_WHILE` | `IRDoWhileStructure` | Entire do-while. `body()`, `condition()`. |
| `DO_WHILE_BODY` | — | Do-while body. |
| `DO_WHILE_CONDITION` | — | Do-while condition. |
| `SWITCH` | `IRSwitchStructure` | Entire switch. `cases()`, `default_case()`. |
| `SWITCH_CASE` | `IRSwitchCaseStructure` | Individual case/default. `low()`, `high()`, `is_default()`. |

### Scope Lifetime Model

- **`ENTER_SCOPE`**: Objects in the scope become live but **uninitialized**. Reading them before a store is undefined behavior.
- **`EXIT_SCOPE`**: Objects become **invalid**. Reading them after exit is use-after-scope.
- Aggregate initialization emits `MULTIMEM(MEMSET, dest, 0, size)` to zero-fill before element-wise stores. This is what the compiler would emit.
- For-loops with init-declarations (`for (int i = 0; ...)`) get an implicit `SCOPE` wrapping the entire loop, so `i`'s lifetime is correct.

### Goto Compensation

When a `goto` jumps across scope boundaries, the IR inserts a **compensation block** (`BlockKind::COMPENSATION`) on the goto edge. The compensation block emits:
1. `EXIT_SCOPE` for each scope being left (innermost first)
2. `ENTER_SCOPE` for each scope being entered (outermost first)

This ensures the interpreter sees correct scope transitions regardless of control flow path.

```
// goto middle; { int x; middle: use(x); }

block_a:
  GOTO → compensation

compensation (COMPENSATION):
  ENTER_SCOPE (x's scope)
  IMPLICIT_GOTO → label_block

label_block (LABEL):
  ... use(x) ...
```

## Entity IDs

All IR entities embed their kind in the entity ID's sub_kind field:
- `IRBlockId` embeds `BlockKind`
- `IRInstructionId` embeds `OpCode`
- `IRStructureId` embeds `StructureKind`

This enables type discrimination without loading the entity.

## Serialization

IR is stored in each fragment's Cap'n Proto message as flat lists:

```
Fragment {
  irFunctions:    List(Function)
  irBlocks:       List(Block)
  irInstructions: List(Instruction)
  irObjects:      List(Object)
  irSwitchCases:  List(SwitchCase)
  irStructures:   List(Structure)
  irEntityPool:   List(UInt64)   // shared entity ID pool
  irIntPool:      List(Int64)    // shared constant pool
}
```

Instructions reference the pools via `entityOffset` and `constOffset`. The entity pool stores: `[parent, sourceEntityId, resultType, operand0..N, extras...]`. The int pool stores constants, sub-opcodes, and widths.

## Design Rationale

**Statement-level CFG**: Unlike Clang's CFG, which splits short-circuit operators into separate blocks, our IR keeps expressions as nested trees. `if ((x + y) && z)` stays as one block with a nested `LOGICAL_AND(ADD(LOAD(x), LOAD(y)), LOAD(z))` tree.

**No SSA**: All locals go through alloca/load/store. `LOCAL_VALUE`/`PARAMETER_VALUE` kinds mark variables that could be promoted to SSA by a future `mem2reg` pass.

**Explicit widths**: Constants carry exact width in `ConstOp` (INT32, FLOAT64, etc.). Casts carry explicit source/destination sizes in `CastOp` (SEXT_I32_I64, F64_TO_SI32, etc.). An interpreter never needs to query the type system.

**Grouped opcodes**: Memory/string ops (`MULTIMEM`), bitwise intrinsics (`BITWISE`), float intrinsics (`FLOAT`), constants (`CONST`), and casts (`CAST`) each use a single opcode with a sub-opcode enum. This keeps the main opcode count manageable while supporting many operations.

**Provenance**: Every instruction carries `sourceEntityId` linking to the AST node. Calls carry target `FunctionDecl` IDs. GEP fields carry `FieldDecl` IDs. An analyzer navigates to the AST for names, source locations, and detailed type information.
