# Interpreter Library Plan

## Goal

Move the concrete interpreter from `bin/InterpretIR/` into a reusable library at `lib/IR/Interpret/` with headers at `include/multiplier/IR/Interpret/`. The library exposes policy-based extension points for memory, value computation, call resolution, and checking — enabling concrete interpretation, taint analysis, symbolic execution, and Valgrind-style memcheck as composable layers.

## Architecture

### Core Interfaces (already stubbed in headers)

```
ValueFactory     — pluggable ALU (concrete, symbolic, taint-wrapped)
Memory           — pluggable address space (flat bytes, COW, shadow)
Driver           — resolves suspensions (branches, calls, loads, stores)
Checker          — fires on memory access, pointer arithmetic, calls
```

### Interpreter Class

```cpp
class Interpreter {
  ValueFactory &factory_;
  Memory &memory_;
  Driver &driver_;
  std::vector<Checker *> checkers_;

  // Execution state.
  struct CallFrame { ... };
  std::vector<CallFrame> call_stack_;
  std::unordered_map<uint32_t, Value> inst_values_;  // instruction index → value

  // The interpreter handles:
  //   - Instruction dispatch (opcode → handler)
  //   - Endianness mechanics (LOAD_LE_32 → read 4 bytes, reinterpret)
  //   - Expression tree evaluation (post-order traversal)
  //   - Scope enter/exit (delegate alloc/free to Memory)
  //   - Call frame push/pop
  //   - Terminator dispatch (branch, switch, return)

  // It does NOT handle:
  //   - What value arithmetic produces (→ ValueFactory)
  //   - Where bytes live (→ Memory)
  //   - Whether to inline a call (→ Driver)
  //   - Whether an access is safe (→ Checkers)
};
```

### Suspension/Resolution Flow

The interpreter is driven by an external loop:

```cpp
// Option A: coroutine-based (gap::generator)
gap::generator<Suspension> Interpreter::Run(IRFunction func);

// Option B: step-based (simpler, no coroutine dependency)
enum class StepResult { CONTINUE, SUSPENDED, COMPLETED, ERROR };
StepResult Interpreter::Step();
Suspension Interpreter::GetSuspension();
void Interpreter::Resume(Resolution resolution);
```

Option B is better for the library because:
- No coroutine overhead
- Caller controls the loop
- Easy to serialize/resume state
- Works with async agent decision-making

### Composable Value Factories

```
ConcreteValueFactory           — direct int/float/ptr arithmetic
SymbolicValueFactory(inner)    — wraps inner, builds sym trees for unknowns
TaintValueFactory(inner, prov) — wraps inner, tracks provenance
```

Each factory's `BinaryOp`, `Cast`, etc. can:
1. Unwrap its layer
2. Delegate to inner factory
3. Wrap the result with its metadata

### Memory Layers

```
ConcreteMemory                 — flat byte arrays, object table
ShadowMemory(inner)            — wraps inner, adds per-byte metadata
COWMemory(inner)               — wraps inner, O(1) fork
```

Shadow metadata per byte: `{ initialized: bool, tainted: bool, freed: bool }`

### Checker Plugins

```
NullDerefChecker               — check for null pointer access
BoundsChecker                  — check offset vs object size
UseAfterFreeChecker            — check for access to freed objects
InitializationChecker          — check for read-before-write
```

Checkers fire via the interpreter, not the driver. They can record findings into a collector.

## File Layout

```
include/multiplier/IR/Interpret/
  Value.h              — ScalarValue, Pointer, Undefined, NullPtr, Value variant
  ValueFactory.h       — ValueFactory ABC
  Memory.h             — Memory ABC
  Suspension.h         — Suspension/Resolution types
  Driver.h             — Driver ABC, Checker ABC
  Interpreter.h        — Interpreter class (the engine)

lib/IR/Interpret/
  ConcreteValueFactory.cpp
  ConcreteMemory.cpp
  Interpreter.cpp         — instruction dispatch, endianness, tree eval
  Checkers.cpp            — built-in checker implementations

bin/InterpretIR/
  InterpretIR.cpp         — thin CLI: parse args, open index, create
                            ConcreteValueFactory + ConcreteMemory +
                            ConcreteDriver, run interpreter, print results
```

## Migration Steps

1. **Extract Value types** — move Value, ScalarValue, Pointer from InterpretIR.cpp into Value.h. ✅ Done.

2. **Extract ValueFactory** — pull arithmetic dispatch out of the interpreter's big switch into ConcreteValueFactory. The switch cases for ADD, SUB, MUL, etc. become factory methods.

3. **Extract Memory** — pull the byte-array memory model into ConcreteMemory. The interpreter's `Allocate`, `Read`, `Write`, `Memset`, `Memcpy` become Memory methods. Endianness conversion stays in the interpreter (it's the mechanical layer between opcodes and raw bytes).

4. **Extract Driver** — the current interpreter makes concrete decisions everywhere. Pull those into a ConcreteDriver that always takes true branches, always inlines available functions, aborts on symbolic.

5. **Wire up Interpreter class** — the main dispatch loop calls factory/memory/driver instead of doing everything inline. The current ~1500-line switch becomes the Interpreter::Step() method.

6. **Add Checkers** — extract the bounds/null checks that the current interpreter does ad-hoc into Checker subclasses.

7. **Slim down bin/InterpretIR** — becomes ~100 lines: parse args, create components, run loop, print.

## Key Design Decisions

- **Endianness in the interpreter, not the memory**: Memory reads/writes raw bytes. The interpreter knows `LOAD_LE_32` means "read 4 bytes, interpret as little-endian uint32". This keeps the memory model simple and endianness-agnostic.

- **Step-based, not coroutine-based**: The interpreter exposes `Step()` / `GetSuspension()` / `Resume()`. This is more flexible than coroutines for serialization, agent integration, and multi-path exploration.

- **Checkers are synchronous**: They fire during the step, not asynchronously. A checker that wants to abort execution returns an error from its hook. Findings are collected into a vector.

- **No multiplier types in Value**: Values are raw bits + pointers. Type interpretation comes from the opcodes, not the values. This matches the IR's "types are in opcodes" philosophy.

- **Memory objects are numbered, not addressed**: Pointer = (object_id, offset). No flat address space. This enables bounds checking without spatial memory safety hardware.

## Timeline Estimate

This is a mechanical refactoring — the logic already exists in InterpretIR.cpp. The main work is:
- Defining clean interfaces (done in headers)
- Extracting code into the right classes
- Wiring the components together
- Making the bin/ driver thin

Not blocked on any IR design decisions. Can proceed after the SQLite issue is resolved.
