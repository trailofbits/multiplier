# Multiplier IR

## Overview

Multiplier generates a per-function intermediate representation (IR) at index time. The IR is a statement-level control flow graph where expressions are nested instruction trees within basic blocks. Every function with a body gets an IR. Global variables and thread-local variables with initializers get synthetic initializer functions.

The IR is designed for concrete and symbolic interpretation. Types are explicit in opcodes (no need to query the type system), control flow is well-formed (every block ends with a terminator), and the structural nesting of scopes and control flow is fully represented.

## Worked Example

```c
int sum(int n) {
    int total = 0;
    for (int i = 0; i < n; i++) {
        total += i;
    }
    return total;
}
```

```
FRAME block:
  ALLOCA %0 : int          // 'n'
  ALLOCA %1 : int          // 'total'
  ALLOCA %2 : int          // 'i'
  IMPLICIT_GOTO → entry

ENTRY block:
  ENTER_SCOPE (FUNCTION_SCOPE)
  PARAM_READ 0
  MEMORY(STORE_LE_32) %0, ^    // n = param0
  CONST(INT32) 0
  MEMORY(STORE_LE_32) %1, ^    // total = 0
  IMPLICIT_GOTO → scope_entry

scope_entry block:
  ENTER_SCOPE (SCOPE)           // implicit scope for 'int i'
  IMPLICIT_GOTO → preheader

LOOP_PREHEADER block:
  CONST(INT32) 0
  MEMORY(STORE_LE_32) %2, ^    // i = 0
  IMPLICIT_GOTO → loop_cond

LOOP_CONDITION block:
  MEMORY(LOAD_LE_32) %2        // i
  MEMORY(LOAD_LE_32) %0        // n
  CMP_LT ^, ^
  COND_BRANCH ^, loop_body, loop_exit

LOOP_BODY block:
  ENTER_SCOPE (SCOPE)
  RMW(ADD) %1, MEMORY(LOAD_LE_32 %2)   // total += i
  EXIT_SCOPE
  IMPLICIT_GOTO → loop_inc

LOOP_INCREMENT block:
  RMW(ADD) %2, CONST(INT32) 1          // i++
  IMPLICIT_GOTO → loop_cond

LOOP_EXIT block:
  EXIT_SCOPE                    // for-init scope
  MEMORY(LOAD_LE_32) %1        // total
  EXIT_SCOPE (FUNCTION_SCOPE)
  RET ^
```

Key points:
- ALLOCAs in the FRAME block are the pointers to local storage. No separate "address-of" instruction — `&x` IS the ALLOCA result.
- MEMORY instructions carry exact size and endianness in their sub-opcode (e.g., `STORE_LE_32` = little-endian 32-bit store).
- `PARAM_READ` reads function parameters explicitly. The value is stored into the parameter's ALLOCA.
- `RMW(ADD)` is a read-modify-write: reads from address, adds the operand, writes back.
- `ENTER_SCOPE` / `EXIT_SCOPE` bracket object lifetimes. The for-init `int i` gets an implicit wrapping scope.

## Functions

**`FunctionKind`**: `NORMAL`, `GLOBAL_INITIALIZER`, `THREAD_LOCAL_INITIALIZER`

- **`NORMAL`**: Generated from a `FunctionDecl` with a body.
- **`GLOBAL_INITIALIZER`**: Synthetic function for a global or static local variable's initialization. Receives a pointer to the variable as parameter 0.
- **`THREAD_LOCAL_INITIALIZER`**: Same as GLOBAL_INITIALIZER but for `_Thread_local` variables. An interpreter knows the init runs per-thread.

```
// Global: int g = 42;
FRAME block: (empty)
ENTRY block:
  ENTER_SCOPE (FUNCTION_SCOPE)
  PARAM_READ 0                         // pointer to g
  MEMORY(MEMSET) ^, CONST(INT8) 0, CONST(INT64) 4   // zero-fill
  PARAM_READ 0
  CONST(INT32) 42
  MEMORY(STORE_LE_32) ^, ^             // *g_ptr = 42
  EXIT_SCOPE
  RET
```

Key methods: `kind()`, `declaration()`, `source_declaration()`, `entry_block()`, `blocks()` (RPO), `objects()`, `body_scope()`.

Navigation: `IRFunction::from(FunctionDecl)` (follows redeclarations), `IRFunction::containing(Decl|Stmt|IRBlock|IRInstruction)`.

## Blocks

Every block ends with exactly one terminator.

**`BlockKind`** (17 kinds):

| Kind | Description |
|------|-------------|
| `FRAME` | All ALLOCAs. Physical entry point. |
| `ENTRY` | Logical entry: ENTER_SCOPE, PARAM_READs, body start. |
| `IF_THEN`, `IF_ELSE`, `IF_MERGE` | If-statement parts. |
| `LOOP_PREHEADER` | Single-entry before loop condition. For-init code lives here. |
| `LOOP_CONDITION` | Condition evaluation. |
| `LOOP_BODY` | Loop body. |
| `LOOP_EXIT` | Exit point. |
| `LOOP_INCREMENT` | For-loop increment. |
| `SWITCH_CASE`, `SWITCH_DEFAULT`, `SWITCH_EXIT` | Switch parts. |
| `LABEL` | Goto target. |
| `COMPENSATION` | Scope transitions on goto edges. |
| `UNREACHABLE` | Dead code after terminator. |
| `GENERIC` | Unclassified. |

Key methods: `kind()`, `parent_structure()`, `parent_function()`, `instructions()`, `all_instructions()`, `successors()`, `predecessors()`, `dominates()`.

## Instructions

72 opcodes. Grouped opcodes use a sub-opcode enum in the int pool.

Instructions are stored in post-order (children before parents). `block.instructions()` yields top-level roots; `block.all_instructions()` yields everything in evaluation order.

### Pointer Acquisition

| Opcode | Description |
|--------|-------------|
| `ALLOCA` | Pointer to a static local allocation. `allocated_type()`, `object()`, `size_bytes()`, `align_bytes()`. |
| `DYNAMIC_ALLOCA` | Pointer to runtime stack allocation. `size()` (operand), `object()` (scope-tracked). |
| `GLOBAL_PTR` | Pointer to a global/static variable. `variable()` → VarDecl. |
| `THREAD_LOCAL_PTR` | Pointer to a thread-local variable. `variable()` → VarDecl. |
| `FUNC_PTR` | Pointer to a function. `function()` → FunctionDecl. |
| `GEP_FIELD` | Struct field pointer. `base()`, `field()` → FieldDecl, `byte_offset()`. |
| `PTR_ADD` | Pointer arithmetic. `base()`, `index()`, `element_type()`, `element_size()`. |

### Memory Access (MEMORY opcode)

Single `MEMORY` opcode with `MemOp` sub-opcode encoding direction, endianness, size, atomicity, and bulk/string operations.

**Direct loads/stores** (sub-opcodes 0-31):

| Pattern | Variants |
|---------|----------|
| `LOAD_{LE,BE}_{8,16,32,64}` | Non-atomic loads |
| `STORE_{LE,BE}_{8,16,32,64}` | Non-atomic stores |
| `ATOMIC_LOAD_{LE,BE}_{8,16,32,64}` | Atomic loads |
| `ATOMIC_STORE_{LE,BE}_{8,16,32,64}` | Atomic stores |

For non-power-of-2 or >8 byte accesses, `MEMORY(MEMCPY)` is used instead.

Helpers: `IsLoad()`, `IsStore()`, `IsAtomic()`, `IsBigEndian()`, `AccessSize()`.

**Bulk memory** (sub-opcodes 32-37): `MEMSET`, `MEMCPY`, `MEMMOVE`, `MEMCMP`, `MEMCHR`, `BZERO`

**String operations** (sub-opcodes 38-50): `STRLEN`, `STRNLEN`, `STRCMP`, `STRNCMP`, `STRCHR`, `STRRCHR`, `STRSTR`, `STRCPY`, `STRNCPY`, `STRCAT`, `STRNCAT`, `STPCPY`, `STPNCPY`

**String-to-number** (sub-opcodes 51-56): `STRTOI32`, `STRTOI64`, `STRTOU32`, `STRTOU64`, `STRTOF32`, `STRTOF64` — size-specific to avoid platform ambiguity.

Both library calls and `__builtin_` variants are recognized.

`MemoryInst` class: `sub_opcode()`, `address()`, `stored_value()`, `result_type()`.

### Constants (CONST opcode)

`ConstOp` sub-opcode encodes exact type: `INT8`-`INT64`, `UINT8`-`UINT64`, `FLOAT16`/`FLOAT32`/`FLOAT64`, `NULL_PTR`, `INF32`/`INF64`, `NAN32`/`NAN64`, `WCHAR16`/`WCHAR32`, `BOOL`.

`ConstInst` class: `sub_opcode()`, `signed_value()`, `unsigned_value()`, `float_value()`, `type()`.

### Casts (CAST opcode)

`CastOp` sub-opcode encodes explicit source/destination sizes (~60 variants):

- Sign-extend: `SEXT_I8_I16`, ..., `SEXT_I32_I64`
- Zero-extend: `ZEXT_I8_I16`, ..., `ZEXT_I32_I64`
- Truncate: `TRUNC_I64_I32`, ..., `TRUNC_I16_I8`
- Int↔Float: `SI32_TO_F64`, `F64_TO_SI32`, `UI32_TO_F32`, ...
- Float↔Float: `F32_TO_F64`, `F64_TO_F32`
- Pointer: `PTR_TO_I64`, `I64_TO_PTR`
- `BITCAST`, `IDENTITY`

Helpers: `IsSignExtend()`, `IsZeroExtend()`, `IsTruncate()`, `IsIntToFloat()`, `IsFloatToInt()`.

### Arithmetic and Logic

| Opcodes | Class |
|---------|-------|
| `ADD`, `SUB`, `MUL`, `DIV`, `REM`, `BIT_AND`, `BIT_OR`, `BIT_XOR`, `SHL`, `SHR`, `LOGICAL_AND`, `LOGICAL_OR`, `PTR_DIFF` | `BinaryInst` |
| `CMP_EQ`, `CMP_NE`, `CMP_LT`, `CMP_LE`, `CMP_GT`, `CMP_GE` | `ComparisonInst` |
| `NEG`, `BIT_NOT`, `LOGICAL_NOT` | `UnaryInst` |

### Calls

`CALL` — `CallInst`: `target()` (FunctionDecl for direct), `is_indirect()`, `arguments()`, `result_type()`. Variadic args grouped under `VA_PACK`.

### Read-Modify-Write

`READ_MODIFY_WRITE` — reads from address, applies an operation, writes back. `ReadModifyWriteInst`: `address()`, `underlying_op()`, `element_size()`, `returns_new_value()`, `rhs_operands()`.

Used for: `++i` (ADD), `i += 5` (ADD), `++ptr` (PTR_ADD), `--ptr` (PTR_ADD with -1), `ptr += n` (PTR_ADD), `__builtin_add_overflow` (ADD_OVERFLOW, returns bool), `__atomic_fetch_add` (ATOMIC_ADD).

### Misc

| Opcode | Description |
|--------|-------------|
| `SELECT` | Ternary `a ? b : c`. Both branches marked conditionally executed. |
| `LAST_VALUE` | Comma operator `a, b`. Evaluates all operands, returns last. |
| `PARAM_READ` | Reads Nth function parameter. `parameter_index()`, `parameter_type()`, `object()`. |
| `UNDEFINED` | Poison value. Any use is UB. |

### Terminators

| Opcode | Description |
|--------|-------------|
| `COND_BRANCH` | Conditional branch. `condition()`, `true_block()`, `false_block()`. |
| `SWITCH` | Switch statement. `selector()`, `cases()`, `num_cases()`. |
| `RET` | Return. `return_value()` (optional). |
| `UNREACHABLE` | Explicit `__builtin_unreachable()`. |
| `BREAK`, `CONTINUE` | Loop/switch control with source provenance. |
| `GOTO` | Explicit goto. May route through COMPENSATION block. |
| `IMPLICIT_GOTO` | Structural CFG edge. |
| `FALLTHROUGH`, `IMPLICIT_FALLTHROUGH` | Switch case fallthrough (explicit vs missing break). |
| `IMPLICIT_UNREACHABLE` | Patched empty block. |

### Scope Markers

| Opcode | Class | Description |
|--------|-------|-------------|
| `ENTER_SCOPE` | `EnterScopeInst` | Scope entry. Objects become allocated but uninitialized. `scope()` → IRStructure. |
| `EXIT_SCOPE` | `ExitScopeInst` | Scope exit. Objects become invalid. `scope()` → IRStructure. |

### Intrinsics

**`BITWISE`** — `BitwiseOpInst` with sub-opcodes: `BSWAP16`/`32`/`64`, `POPCOUNT`, `CLZ` (undefined for 0), `CTZ` (undefined for 0), `FFS`, `PARITY`, `ABS`, `EXPECT`, `ASSUME`, `ROTL`, `ROTR`.

**`FLOAT`** — `FloatOpInst` with 41 sub-opcodes: `SIN`, `COS`, `TAN`, `ASIN`, `ACOS`, `ATAN`, `ATAN2`, `EXP`, `EXP2`, `LOG`, `LOG2`, `LOG10`, `POW`, `FMOD`, `REMAINDER`, `FMA`, `SINH`, `COSH`, `TANH`, `HYPOT`, `ERF`, `ERFC`, `TGAMMA`, `LGAMMA`, `FDIM`, `SIGNBIT`, `ISNAN`, `ISINF`, `ISFINITE`, `FABS`, `COPYSIGN`, `FMIN`, `FMAX`, `CEIL`, `FLOOR`, `ROUND`, `TRUNC`, `SQRT`, `INF`, `NAN_VAL`, `FLOAT_HUGE`.

### Atomics

| Opcode | Description |
|--------|-------------|
| `ATOMIC_CMPXCHG` | Compare-and-exchange. `target()`, `expected_ptr()`, `desired()`. Returns bool. |
| Atomic load/store | Use `MEMORY` with `ATOMIC_LOAD_*` / `ATOMIC_STORE_*` sub-opcodes. |
| Atomic fetch ops | Use `READ_MODIFY_WRITE` with `ATOMIC_ADD`..`ATOMIC_EXCHANGE` underlying. |
| Overflow ops | Use `READ_MODIFY_WRITE` with `ADD_OVERFLOW`/`SUB_OVERFLOW`/`MUL_OVERFLOW`. Returns bool (overflow flag), stores arithmetic result. |

## Objects

`IRObject` represents a memory location.

**`ObjectKind`**: `LOCAL`, `LOCAL_VALUE`, `PARAMETER`, `PARAMETER_VALUE`, `GLOBAL`, `THREAD_LOCAL`, `STRING_LITERAL`, `COMPOUND_LITERAL`, `RETURN_SLOT`, `ALLOCA` (dynamic), `HEAP`.

Key methods: `kind()`, `source_declaration()`, `type()`, `size_bytes()`, `align_bytes()`, `needs_memory()`.

## Structural Hierarchy

`IRStructure` forms a tree rooted at `FUNCTION_SCOPE`. Every block has a `parent_structure()`.

**`StructureKind`** (18 kinds):

| Kind | Derived Class | Key Methods |
|------|--------------|-------------|
| `FUNCTION_SCOPE`, `SCOPE` | `IRScopeStructure` | `objects()` — locals in this scope |
| `IF` | `IRIfStructure` | `then_branch()`, `else_branch()` |
| `FOR` | `IRForStructure` | `init()`, `condition()`, `body()`, `increment()` |
| `WHILE` | `IRWhileStructure` | `condition()`, `body()` |
| `DO_WHILE` | `IRDoWhileStructure` | `body()`, `condition()` |
| `SWITCH` | `IRSwitchStructure` | `cases()`, `default_case()` |
| `SWITCH_CASE` | `IRSwitchCaseStructure` | `low()`, `high()`, `is_default()` |
| Sub-parts | — | `IF_THEN`, `IF_ELSE`, `FOR_INIT`, `FOR_CONDITION`, `FOR_BODY`, `FOR_INCREMENT`, `WHILE_CONDITION`, `WHILE_BODY`, `DO_WHILE_BODY`, `DO_WHILE_CONDITION` |

### Scope Lifetime Model

- **`ENTER_SCOPE`**: Objects become allocated but **uninitialized**. Reading before a store is undefined.
- **`EXIT_SCOPE`**: Objects become **invalid**. Reading after is use-after-scope.
- Aggregate initialization emits `MEMORY(MEMSET)` to zero-fill, then element-wise stores.
- For-loops with init-declarations get an implicit `SCOPE`.
- Dynamic allocations (`DYNAMIC_ALLOCA`) create scope-tracked objects freed on scope exit.

### Goto Compensation

When `goto` crosses scope boundaries, a `COMPENSATION` block is inserted with the necessary `EXIT_SCOPE` / `ENTER_SCOPE` transitions.

### GNU Block Expressions

`({ int x = 1; x + 1; })` emits a scoped block with `ENTER_SCOPE`/`EXIT_SCOPE`. The last expression's value is the result.

## Entity IDs

Entity IDs embed kind in the sub_kind field: `IRBlockId` embeds `BlockKind`, `IRInstructionId` embeds `OpCode`, `IRStructureId` embeds `StructureKind`.

## Serialization

```
Fragment {
  irFunctions, irBlocks, irInstructions, irObjects,
  irSwitchCases, irStructures, irEntityPool, irIntPool
}
```

## Design Rationale

**Statement-level CFG**: Expressions stay as nested trees. `if ((x+y) && z)` is one block with `LOGICAL_AND(ADD(LOAD(x), LOAD(y)), LOAD(z))`.

**No SSA**: All locals go through alloca/load/store. `LOCAL_VALUE`/`PARAMETER_VALUE` mark SSA-promotable variables.

**Explicit widths**: Constants (`INT32`, `FLOAT64`), casts (`SEXT_I32_I64`), and loads/stores (`LOAD_LE_32`) carry exact sizes. No type system queries needed.

**Grouped opcodes**: `MEMORY` (57 sub-ops), `CONST` (19), `CAST` (~60), `BITWISE` (13), `FLOAT` (41) keep the main opcode count at 72.

**Provenance**: Every instruction has `source_entity_id`. Calls have `target()`. GEP fields have `field()`. Navigate to AST for names and source locations.
