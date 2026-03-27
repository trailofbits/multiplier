# Multiplier IR Design

## Overview

Multiplier generates a per-function intermediate representation (IR) at index time by walking the PASTA AST. The IR is serialized as flat lists inside each fragment's Cap'n Proto message and can be queried through entity IDs.

## Design Decisions

### Statement-Level CFG, Not Clang CFG

The IR builds its own statement-level control flow graph rather than using Clang's `clang::CFG`. Clang's CFG splits short-circuit operators (`&&`, `||`) and ternary (`?:`) into separate basic blocks, destroying expression tree structure. Our IR keeps expressions as nested instruction trees within blocks, splitting only at statement-level control flow (`if`, `while`, `for`, `switch`, `goto`, `break`, `continue`, `return`).

For `if ((x + y) && z)`, Clang's CFG creates 4+ blocks. Our IR keeps it as one block with a nested `logical_and(add(load(x), load(y)), load(z))` instruction tree.

### Single Unified OpCode Enum

All instruction types share a single `OpCode` enum rather than separate enums for binary ops, comparisons, casts, etc. This drives the C++ class hierarchy on the read side and is embedded in entity IDs.

### Flat Layout in Fragment

IR entities (functions, blocks, instructions, objects) are stored as four flat lists in the fragment proto, mirroring how declarations and statements are stored. Each entity has its own sub_kind in the entity ID scheme. This means:
- No separate database table for IR
- IR loads with the fragment (zero extra I/O for AST↔IR navigation)
- Entity IDs follow the standard `(fragment_id, sub_kind, offset)` pattern

### Entity IDs Encode Kind

`IRBlockId` embeds `BlockKind` and `IRInstructionId` embeds `OpCode` in the entity ID's sub_kind field. You can determine what kind of block or instruction an entity is without loading it.

### Children-Before-Parents Instruction Ordering

Instructions within a block are laid out in post-order: children (sub-expressions) appear before their parents. Each instruction has a `parentOffset` field (distance to parent in the flat list, 0 = top-level root). This enables:
- Bottom-up traversal by scanning forward
- Top-down traversal by following operand indices
- Identifying statement-level roots by `parentOffset == 0`

### Maximum Entity ID Provenance

Every instruction carries `sourceEntityId` linking back to the originating AST `Stmt`/`Expr`. Calls carry `targetEntityId` for the callee `FunctionDecl`. GEP fields carry `targetEntityId` for the `FieldDecl`. Objects carry `sourceDeclId` for the `VarDecl`. No names are stored -- the user resolves entity IDs through the Multiplier API.

### Address-Taken Classification

Objects are classified at generation time:
- `LOCAL` / `PARAMETER`: address-taken, needs alloca/load/store
- `LOCAL_VALUE` / `PARAMETER_VALUE`: non-address-taken, pure value (candidate for future SSA promotion)

### Explicit vs Implicit Control Flow

The IR distinguishes user-written control flow from structural CFG edges:
- `GOTO` vs `IMPLICIT_GOTO`: user `goto` vs structural edge (e.g., end of if-then → merge)
- `FALLTHROUGH` vs `IMPLICIT_FALLTHROUGH`: `[[fallthrough]]` attribute vs missing `break`
- `BREAK`, `CONTINUE`: separate opcodes with source entity IDs

### Block Kinds

Each block has a `BlockKind` identifying its structural role: `ENTRY`, `IF_THEN`, `IF_ELSE`, `IF_MERGE`, `LOOP_CONDITION`, `LOOP_BODY`, `LOOP_EXIT`, `LOOP_INCREMENT`, `SWITCH_CASE`, `SWITCH_DEFAULT`, `SWITCH_EXIT`, `LABEL`, `UNREACHABLE`, `GENERIC`.

### Conditionally-Executed Flag

Instructions under short-circuit operators or ternary branches are marked with `isConditionallyExecuted` (bit 2 in flags). For `A || B`, everything reachable from `B` is conditionally executed. For `a ? b : c`, both `b` and `c` subtrees are marked.

### Variadic Argument Handling

Variadic function calls emit a `VA_PACK` instruction grouping the variadic arguments, placed where the `...` parameter would be. The receiving side uses `VA_START`, `VA_ARG`, `VA_COPY`, `VA_END` opcodes.

### Dominator Trees

Dominator and post-dominator trees are computed at index time (Cooper-Harvey-Kennedy algorithm) and stored directly on each block as entity ID lists. Immediate dominator/post-dominator are also stored.

## What's Not Implemented Yet

- Pointer arithmetic lowering (ptr + int → GEP_INDEX)
- C++ specific: constructors, destructors, new/delete, lambdas, exceptions
- `mem2reg` pass to promote `LOCAL_VALUE`/`PARAMETER_VALUE` to SSA with block arguments
- Use-def chains
- String literal content storage
- Read-side C++ API (Value/BlockArgument/Instruction class hierarchy)
