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
  ALLOCA/LOCAL %0 : int      // 'n'
  ALLOCA/LOCAL %1 : int      // 'total'
  ALLOCA/LOCAL %2 : int      // 'i'
  IMPLICIT_GOTO → entry

ENTRY block:
  ENTER_SCOPE (FUNCTION_SCOPE)
  PARAM_PTR 0
  MEMORY(STORE_LE_32) %0, ^  // n = param0
  CONST(INT32) 0
  MEMORY(STORE_LE_32) %1, ^  // total = 0
  IMPLICIT_GOTO → scope_entry

scope_entry block:
  ENTER_SCOPE (SCOPE)         // implicit scope for 'int i'
  IMPLICIT_GOTO → preheader

LOOP_PREHEADER block:
  CONST(INT32) 0
  MEMORY(STORE_LE_32) %2, ^  // i = 0
  IMPLICIT_GOTO → loop_cond

LOOP_CONDITION block:
  MEMORY(LOAD_LE_32) %2      // i
  MEMORY(LOAD_LE_32) %0      // n
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
  EXIT_SCOPE                  // for-init scope
  MEMORY(LOAD_LE_32) %1      // total
  EXIT_SCOPE (FUNCTION_SCOPE)
  RET ^
```

Key points:
- ALLOCAs in the FRAME block are pointers to local storage. No separate "address-of" instruction — `&x` IS the ALLOCA result. Sub-opcode `AllocaKind` distinguishes `LOCAL`, `ARG`, `RETURN`, and `DYNAMIC`.
- MEMORY instructions carry exact size and endianness in their sub-opcode (e.g., `STORE_LE_32` = little-endian 32-bit store).
- `PARAM_PTR` returns a pointer to the Nth function parameter. Storage lives in the caller's EXPRESSION_SCOPE.
- `RMW(ADD)` is a read-modify-write: reads from address, adds the operand, writes back.
- `ENTER_SCOPE` / `EXIT_SCOPE` bracket object lifetimes. The for-init `int i` gets an implicit wrapping scope.
- Direct assignment `a = b` uses `MEMCPY(dest, src, size)` — no load/store pair. Scalar LOAD/STORE only for feeding values into arithmetic.

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
  PARAM_PTR 0                            // pointer to g
  MEMORY(MEMSET) ^, CONST(INT8) 0, CONST(INT64) 4   // zero-fill
  PARAM_PTR 0
  CONST(INT32) 42
  MEMORY(STORE_LE_32) ^, ^              // *g_ptr = 42
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
| `ENTRY` | Logical entry: ENTER_SCOPE, PARAM_PTRs, body start. |
| `IF_THEN`, `IF_ELSE`, `IF_MERGE` | If-statement parts. |
| `LOOP_PREHEADER` | Single-entry before loop condition. For-init code lives here. |
| `LOOP_CONDITION` | Condition evaluation. |
| `LOOP_BODY` | Loop body. |
| `LOOP_EXIT` | Exit point. |
| `LOOP_INCREMENT` | For-loop increment. |
| `SWITCH_CASE`, `SWITCH_DEFAULT`, `SWITCH_EXIT` | Switch parts. |
| `LABEL` | Goto target. |
| `COMPENSATION` | Scope transitions on goto/switch-case edges. |
| `UNREACHABLE` | Dead code after terminator. |
| `GENERIC` | Unclassified. |

Key methods: `kind()`, `parent_structure()`, `parent_function()`, `instructions()`, `all_instructions()`, `successors()`, `predecessors()`, `dominates()`.

## Instructions

~217 opcodes (uint8_t). Integer, pointer, and atomic opcodes are width-specific (e.g., `ADD_32`, `PTR_ADD_64`, `ATOMIC_ADD_32`). Grouped opcodes (MEMORY, CAST, BITWISE, FLOAT) use a sub-opcode enum in the int pool.

Instructions are stored in post-order (children before parents). `block.instructions()` yields top-level roots; `block.all_instructions()` yields everything in evaluation order.

### Pointer Acquisition

| Opcode | Description |
|--------|-------------|
| `ALLOCA` | Pointer to an allocation. Sub-opcode `AllocaKind` in int_pool[0]: `LOCAL` (regular local), `ARG` (call argument in EXPRESSION_SCOPE), `RETURN` (return value in EXPRESSION_SCOPE), `DYNAMIC` (VLA/alloca()). `allocated_type()`, `object()`, `size_bytes()`, `align_bytes()`. Derived classes: `LocalAllocaInst`, `ArgAllocaInst`, `ReturnAllocaInst`, `DynamicAllocaInst`. |
| `GLOBAL_PTR_32/64` | Pointer to a global/static variable. Width = pointer size. `variable()` → VarDecl. |
| `THREAD_LOCAL_PTR_32/64` | Pointer to a thread-local variable. `variable()` → VarDecl. |
| `FUNC_PTR_32/64` | Pointer to a function. `function()` → FunctionDecl. |
| `STRING_PTR_32/64` | Pointer to a string literal. `source_entity_id` → StringLiteral. |
| `GEP_FIELD_32/64` | Struct field pointer. `base()`, `field()` → FieldDecl, `byte_offset()`. |
| `PTR_ADD_32/64` | Pointer arithmetic. `base()`, `index()`, `element_type()`, `element_size()`. |
| `PTR_DIFF_32/64` | Pointer subtraction. Result is ptrdiff_t. `lhs()`, `rhs()`, `element_size()`. |
| `PARAM_PTR_32/64` | Pointer to Nth function parameter. `parameter_index()`. |
| `FRAME_PTR_32/64` | `__builtin_frame_address`. |
| `RETURN_PTR_32/64` | Callee-side pointer to caller's return storage. |
| `RETURN_ADDRESS_32/64` | `__builtin_return_address`. |

### Memory Access (MEMORY opcode)

Single `MEMORY` opcode with `MemOp` sub-opcode encoding direction, endianness, size, atomicity, and bulk/string operations.

**Size rules**: Only 1/2/4/8 byte scalar LOAD/STORE is allowed. For non-power-of-2 sizes or objects > 8 bytes, `MEMCPY` is used. Direct assignment `a = b` always uses `MEMCPY` when the RHS is an lvalue — no redundant LOAD+STORE pair.

**Direct loads/stores** (sub-opcodes 0-31):

| Pattern | Variants |
|---------|----------|
| `LOAD_{LE,BE}_{8,16,32,64}` | Non-atomic loads |
| `STORE_{LE,BE}_{8,16,32,64}` | Non-atomic stores |
| `ATOMIC_LOAD_{LE,BE}_{8,16,32,64}` | Atomic loads |
| `ATOMIC_STORE_{LE,BE}_{8,16,32,64}` | Atomic stores |

Helpers: `IsLoad()`, `IsStore()`, `IsAtomic()`, `IsBigEndian()`, `AccessSize()`.

**Bulk memory** (sub-opcodes 32-37): `MEMSET`, `MEMCPY`, `MEMMOVE`, `MEMCMP`, `MEMCHR`, `BZERO`

**String operations** (sub-opcodes 38-50): `STRLEN`, `STRNLEN`, `STRCMP`, `STRNCMP`, `STRCHR`, `STRRCHR`, `STRSTR`, `STRCPY`, `STRNCPY`, `STRCAT`, `STRNCAT`, `STPCPY`, `STPNCPY`

**String-to-number** (sub-opcodes 51-56): `STRTOI32`, `STRTOI64`, `STRTOU32`, `STRTOU64`, `STRTOF32`, `STRTOF64` — size-specific to avoid platform ambiguity.

**Bit-field access** (sub-opcodes 57-60): `BIT_READ_LE`, `BIT_WRITE_LE`, `BIT_READ_BE`, `BIT_WRITE_BE`. Bit offset and width stored in int pool (not as operands). Endianness determines bit numbering: LE bit 0 = LSB of byte 0; BE bit 0 = MSB of byte 0. Used for struct bit-field reads and writes.

**Atomic compare-and-exchange** (sub-opcodes 61-68): `CMPXCHG_{LE,BE}_{8,16,32,64}`. `op[0]=target`, `op[1]=expected_ptr`, `op[2]=desired`. Returns bool.

**Variadic argument consumption** (sub-opcode 69): `CONSUME_VA_PARAM`. `op[0]=va_list_ptr`. Reads the current va_list index, copies from the caller's variadic argument alloca, increments the index. `type_entity_id` specifies the consumed type.

Helpers: `IsLoad()`, `IsStore()`, `IsAtomic()`, `IsBigEndian()`, `AccessSize()`, `IsBitAccess()`, `IsBitRead()`, `IsBitWrite()`, `IsCmpxchg()`.

Both library calls and `__builtin_` variants are recognized. `_Atomic` types automatically use atomic load/store/RMW variants.

`MemoryInst` class: `sub_opcode()`, `address()`, `stored_value()`, `result_type()`, `bit_offset()`, `bit_width()`.

`ConsumeVAParamInst` class: `va_list_operand()`, `result_type()`.

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

All integer/bitwise/comparison opcodes are width-specific (`_8`, `_16`, `_32`, `_64`). The width suffix indicates the operand width in bits. Float opcodes have `_32` (float) and `_64` (double) variants.

| Opcodes | Class |
|---------|-------|
| `ADD_8/16/32/64`, `SUB_*`, `MUL_*`, `DIV_*`, `REM_*` | `BinaryInst` (signed arithmetic) |
| `UDIV_8/16/32/64`, `UREM_*`, `USHR_*` | `BinaryInst` (unsigned arithmetic) |
| `BIT_AND_8/16/32/64`, `BIT_OR_*`, `BIT_XOR_*`, `SHL_*`, `SHR_*` | `BinaryInst` (bitwise) |
| `FADD_32/64`, `FSUB_*`, `FMUL_*`, `FDIV_*`, `FREM_*` | `BinaryInst` (float arithmetic) |
| `CMP_EQ_8/16/32/64`, `CMP_NE_*`, `CMP_LT_*`, `CMP_LE_*`, `CMP_GT_*`, `CMP_GE_*` | `ComparisonInst` (signed) |
| `UCMP_LT_8/16/32/64`, `UCMP_LE_*`, `UCMP_GT_*`, `UCMP_GE_*` | `ComparisonInst` (unsigned) |
| `FCMP_EQ_32/64`, `FCMP_NE_*`, `FCMP_LT_*`, `FCMP_LE_*`, `FCMP_GT_*`, `FCMP_GE_*` | `ComparisonInst` (float) |
| `NEG_8/16/32/64`, `BIT_NOT_8/16/32/64`, `ABS_8/16/32/64` | `UnaryInst` (sized) |
| `FNEG_32/64` | `UnaryInst` (float) |
| `LOGICAL_AND`, `LOGICAL_OR`, `LOGICAL_NOT` | Unsized (produce 0 or 1) |

### Bitwise Intrinsics (BITWISE opcode)

`BITWISE_8/16/32/64` — width-specific bitwise intrinsics. `BitwiseOp` sub-opcode in int_pool[0]:

| Sub-opcode | Description |
|------------|-------------|
| `BSWAP_16/32/64` | Byte swap (width in sub-opcode name). |
| `POPCOUNT` | Number of set bits. |
| `CLZ` | Count leading zeros. UNDEFINED for 0. |
| `CTZ` | Count trailing zeros. UNDEFINED for 0. |
| `FFS` | Find first set bit (1-indexed). 0 for input 0. |
| `PARITY` | 1 if odd number of set bits. |
| `ROTL` | Rotate left. op[0]=value, op[1]=amount. |
| `ROTR` | Rotate right. op[0]=value, op[1]=amount. |

Width comes from the parent opcode. CLZ on `BITWISE_8` counts leading zeros in an 8-bit value.

### Float Intrinsics (FLOAT opcode)

`FLOAT` — float intrinsic operations. `FloatOp` sub-opcode in int_pool[0]. Every sub-opcode has `_32` (float) and `_64` (double) variants for precision-correct execution.

Categories: classification (`ISNAN`, `ISINF`, `ISFINITE`, `SIGNBIT`), arithmetic (`FABS`, `COPYSIGN`, `FMIN`, `FMAX`), rounding (`CEIL`, `FLOOR`, `ROUND`, `TRUNC`), roots (`SQRT`), trigonometric (`SIN`, `COS`, `TAN`, `ASIN`, `ACOS`, `ATAN`, `ATAN2`), exponential (`EXP`, `EXP2`, `LOG`, `LOG2`, `LOG10`), power (`POW`, `FMOD`, `REMAINDER`, `FMA`), hyperbolic (`SINH`, `COSH`, `TANH`), other (`HYPOT`, `ERF`, `ERFC`, `TGAMMA`, `LGAMMA`, `FDIM`), constants (`INF`, `NAN`, `HUGE`).

### Calls

`CALL` — `CallInst`: `target()` (FunctionDecl for direct), `is_indirect()`, `arguments()`, `result_type()`.

With the EXPRESSION_SCOPE model, function calls are wrapped in an `EXPRESSION_SCOPE` that holds `ALLOCA/ARG` for each argument and `ALLOCA/RETURN` for the return value. On the callee side, `PARAM_PTR(n)` gives a pointer to the caller's Nth argument alloca.

### Read-Modify-Write

`READ_MODIFY_WRITE` — reads from address, applies an operation, writes back. `ReadModifyWriteInst`: `address()`, `underlying_op()`, `element_size()`, `is_big_endian()`, `is_atomic()`, `returns_new_value()`, `rhs_operands()`.

int_pool layout: `[underlying_opcode, element_size, is_big_endian]`.

The underlying opcode is always a sized opcode:
- Integer: `ADD_32`, `SUB_64`, `UDIV_32`, `USHR_32`, etc.
- Float: `FADD_32`, `FSUB_64`, `FMUL_32`, `FDIV_64`, `FREM_32`
- Pointer: `PTR_ADD_32`, `PTR_ADD_64`
- Atomic: `ATOMIC_ADD_8/16/32/64`, `ATOMIC_SUB_*`, `ATOMIC_AND_*`, `ATOMIC_OR_*`, `ATOMIC_XOR_*`, `ATOMIC_NAND_*`, `ATOMIC_EXCHANGE_*`
- Overflow: `ADD_OVERFLOW_8/16/32/64`, `SUB_OVERFLOW_*`, `MUL_OVERFLOW_*` (returns bool)

Used for: `++i` (ADD_32), `i += 5` (ADD_32), `f += 1.0` (FADD_32), `++ptr` (PTR_ADD_64), `ptr += n` (PTR_ADD_64), `_Atomic int a; a += 1` (ATOMIC_ADD_32), `__builtin_add_overflow` (ADD_OVERFLOW_32), `__atomic_fetch_add` (ATOMIC_ADD_32).

### Misc

| Opcode | Description |
|--------|-------------|
| `SELECT` | Ternary `a ? b : c`. Both branches marked conditionally executed. |
| `LAST_VALUE` | Comma operator `a, b`. Evaluates all operands, returns last. |
| `PARAM_PTR_32/64` | Pointer to Nth function parameter. `parameter_index()`, `parameter_type()`. |
| `FRAME_PTR_32/64` | `__builtin_frame_address(level)`. |
| `RETURN_ADDRESS_32/64` | `__builtin_return_address(level)`. |
| `UNDEFINED` | Poison value. Any use is UB. |

### Variadic Argument Handling

| Opcode | Description |
|--------|-------------|
| `VA_START` | Binds va_list to function's variadic arguments. `va_list_operand()`. |
| `VA_COPY` | Copies va_list. `dest()`, `src()`. |
| `VA_END` | Releases va_list. `va_list_operand()`. |
| `MEMORY/CONSUME_VA_PARAM` | Reads next variadic arg from va_list, copies from caller's EXPRESSION_SCOPE, increments index. `va_list_operand()`, `result_type()`. |

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
| Atomic cmpxchg | Use `MEMORY` with `CMPXCHG_LE_*` / `CMPXCHG_BE_*` sub-opcodes. `op[0]=target`, `op[1]=expected_ptr`, `op[2]=desired`. Returns bool. |
| Atomic load/store | Use `MEMORY` with `ATOMIC_LOAD_*` / `ATOMIC_STORE_*` sub-opcodes. |
| Atomic fetch ops | Use `READ_MODIFY_WRITE` with `ATOMIC_ADD`..`ATOMIC_EXCHANGE` underlying. |
| Overflow ops | Use `READ_MODIFY_WRITE` with `ADD_OVERFLOW`/`SUB_OVERFLOW`/`MUL_OVERFLOW`. Returns bool (overflow flag), stores arithmetic result. |

## Objects

`IRObject` represents a memory location.

**`ObjectKind`**: `LOCAL`, `LOCAL_VALUE`, `PARAMETER`, `PARAMETER_VALUE`, `GLOBAL`, `THREAD_LOCAL`, `STRING_LITERAL`, `COMPOUND_LITERAL`, `RETURN_SLOT`, `ALLOCA` (dynamic), `HEAP`.

Key methods: `kind()`, `source_declaration()`, `type()`, `size_bytes()`, `align_bytes()`, `needs_memory()`.

### String Literal Objects

`STRING_LITERAL` objects hold the storage for string literals. The object's `size_bytes()` includes the null terminator (`ByteLength() + CharacterByteWidth()`). The actual string content is available from the AST via the `source_entity_id` → `StringLiteral::Bytes()`, which returns the raw bytes in **target byte order** and does **NOT** include the trailing null terminator. Consumers should zero-fill the object first, then copy `Bytes()` into it. For wide strings (`L"..."`, `u"..."`, `U"..."`), `CharacterByteWidth()` is 2 or 4, and `Bytes()` contains multi-byte characters in target byte order.

## Structural Hierarchy

`IRStructure` forms a tree rooted at `FUNCTION_SCOPE`. Every block has a `parent_structure()`.

**`StructureKind`** (19 kinds):

| Kind | Derived Class | Key Methods |
|------|--------------|-------------|
| `FUNCTION_SCOPE`, `SCOPE` | `IRScopeStructure` | `objects()` — locals in this scope |
| `EXPRESSION_SCOPE` | `IRExpressionScopeStructure` | `objects()` — arg/return allocas for calls in a full-expression |
| `IF` | `IRIfStructure` | `then_branch()`, `else_branch()` |
| `FOR` | `IRForStructure` | `init()`, `condition()`, `body()`, `increment()` |
| `WHILE` | `IRWhileStructure` | `condition()`, `body()` |
| `DO_WHILE` | `IRDoWhileStructure` | `body()`, `condition()` |
| `SWITCH` | `IRSwitchStructure` | `cases()`, `default_case()` |
| `SWITCH_CASE` | `IRSwitchCaseStructure` | `low()`, `high()`, `is_default()`, `target_block()` |
| Sub-parts | — | `IF_THEN`, `IF_ELSE`, `FOR_INIT`, `FOR_CONDITION`, `FOR_BODY`, `FOR_INCREMENT`, `WHILE_CONDITION`, `WHILE_BODY`, `DO_WHILE_BODY`, `DO_WHILE_CONDITION` |

### EXPRESSION_SCOPE and Calling Convention

Function calls are wrapped in an `EXPRESSION_SCOPE` that extends to the full-expression boundary (the `;`). The scope holds:
- One `ALLOCA/ARG` per argument (caller copies values into these)
- One `ALLOCA/RETURN` for the return value (callee writes result here)

On the callee side:
- `PARAM_PTR(n)` returns a pointer to the caller's Nth argument alloca
- The callee reads parameters by loading from `PARAM_PTR` pointers
- Parameters have no callee-side scope — their lifetime is the caller's EXPRESSION_SCOPE

For nested calls like `foo(bar(x), baz(y))`, all argument and return allocas for all calls in the expression share one EXPRESSION_SCOPE.

### Scope Lifetime Model

- **`ENTER_SCOPE`**: Objects become allocated but **uninitialized**. Reading before a store is undefined.
- **`EXIT_SCOPE`**: Objects become **invalid**. Reading after is use-after-scope.
- Aggregate initialization emits `MEMORY(MEMSET)` to zero-fill, then element-wise stores.
- For-loops with init-declarations get an implicit `SCOPE`.
- Dynamic allocations (`ALLOCA/DYNAMIC`) create scope-tracked objects freed on scope exit.

### Scope Compensation Blocks

When control flow crosses scope boundaries — via `goto` or switch-case edges (Duff's device) — a `COMPENSATION` block is inserted with the necessary `EXIT_SCOPE` / `ENTER_SCOPE` transitions. Each goto and each switch→case edge gets its own compensation block. Same-scope jumps need no compensation.

### Array-to-Pointer Decay

When an array is passed to a function, it decays to a pointer. The ALLOCA for the array IS the decayed pointer — no load is emitted. On the callee side, Clang adjusts `int arr[10]` parameters to `int *`, so the parameter type and size are correct (pointer-sized).

### GNU Block Expressions

`({ int x = 1; x + 1; })` emits a scoped block with `ENTER_SCOPE`/`EXIT_SCOPE`. The last expression's value is the result.

## Entity IDs

Entity IDs embed kind in the sub_kind field: `IRBlockId` embeds `BlockKind`, `IRInstructionId` embeds `OpCode`, `IRStructureId` embeds `StructureKind`.

## Serialization

```
Fragment {
  irFunctions, irBlocks, irInstructions, irObjects,
  irStructures, irEntityPool, irIntPool
}
```

**Byte order**: All numeric values in the int pool (constants, sizes, offsets) are stored in host byte order. The index is architecture-specific — type sizes, alignment, and ABI are all target-dependent. Databases indexed on a little-endian host are not portable to big-endian (and vice versa). This is inherent to the design; the entire index is tied to the target triple.

## Design Rationale

**Statement-level CFG**: Expressions stay as nested trees. `if ((x+y) && z)` is one block with `LOGICAL_AND(ADD(LOAD(x), LOAD(y)), LOAD(z))`.

**No SSA**: All locals go through alloca/load/store. `LOCAL_VALUE`/`PARAMETER_VALUE` mark SSA-promotable variables.

**Explicit widths**: Constants (`INT32`, `FLOAT64`), casts (`SEXT_I32_I64`), and loads/stores (`LOAD_LE_32`) carry exact sizes. No type system queries needed.

**Grouped opcodes**: `MEMORY` (70 sub-ops), `CONST` (19), `CAST` (~60), `ALLOCA` (4), `BITWISE` (13), `FLOAT` (41) keep the main opcode count at 71.

**Assignment model**: Direct assignment `a = b` always uses `MEMCPY(dest, src, size)`. Scalar `LOAD`/`STORE` only for feeding values into arithmetic and writing computed results back. This avoids endianness issues for direct copies and naturally handles all sizes.

**Provenance**: Every instruction has `source_entity_id`. Calls have `target()`. GEP fields have `field()`. Navigate to AST for names and source locations.

## Known Gaps and TODO

### Address Assignment for Globals, Strings, and Functions

`GLOBAL_PTR`, `THREAD_LOCAL_PTR`, `FUNC_PTR`, and `STRING_PTR` produce
pointers to entities that live outside the function's stack frame. The IR does
not prescribe what addresses these get — it is the interpreter's responsibility
to assign concrete addresses. The interpreter should give each entity a
consistent address for the duration of the program (e.g., via a flat virtual
address space with lazy allocation).

`STRING_PTR`'s `source_entity_id` points to the `StringLiteral` AST node.
The interpreter populates storage from `StringLiteral::bytes()`.

### `#embed`

C23 `#embed` is not yet handled.
