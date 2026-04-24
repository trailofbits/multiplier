// Copyright (c) 2024-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include "../../Compiler.h"
#include "Policy.h"
#include "ConcreteMemory.h"

#include <multiplier/IR/Function.h>
#include <multiplier/Types.h>

#include <functional>
#include <optional>

namespace mx::ir::interpret {

// Function resolver: given an entity ID, return its IRFunction.
using FunctionResolver =
    std::function<std::optional<IRFunction>(RawEntityId)>;

// Global resolver: given a global variable's entity ID, return its info.
using GlobalResolver =
    std::function<std::optional<GlobalInfo>(RawEntityId)>;

// Concrete policy: all operations are direct computation, no symbolic
// reasoning, no forking. Uses NoOpScheduler (compiles to nothing).
//
// Takes a ConcreteMemory by reference (not owned). The memory is separate
// because it has forkable state and is reusable across policies.
//
// Value factory methods (arithmetic, casts, comparisons, intrinsics)
// are implemented directly here — they are stateless pure functions
// and don't need a separate class.
class MX_EXPORT ConcretePolicy
    : public Policy<ConcretePolicy, NoOpScheduler> {
 public:
  explicit ConcretePolicy(ConcreteMemory &memory,
                          FunctionResolver func_resolver = {},
                          GlobalResolver global_resolver = {});

  ConcreteMemory &memory(void) { return memory_; }
  const ConcreteMemory &memory(void) const { return memory_; }

  // --- 1. Value construction ---
  Value make_const(ConstOp op, int64_t signed_val, uint64_t unsigned_val);
  Value make_null_ptr(void);

  // --- 2. Arithmetic / logic ---
  Value binary_op(OpCode op, const Value &lhs, const Value &rhs);
  Value unary_op(OpCode op, const Value &operand);
  Value compare(OpCode op, const Value &lhs, const Value &rhs);
  Value cast(CastOp op, const Value &operand);
  Value ptr_add(const Value &base, const Value &index,
                int64_t element_size);
  Value ptr_diff(const Value &lhs, const Value &rhs,
                 int64_t element_size);
  Value ptr_offset(const Value &base, int64_t byte_offset);
  Value select(const Value &cond, const Value &if_true,
               const Value &if_false);
  Value bitwise_intrinsic(OpCode width_op, BitwiseOp sub,
                          const Value &val, const Value &val2);
  Value float_intrinsic(FloatOp sub,
                        const std::vector<Value> &operands);

  // --- 3. Truth test ---
  std::optional<bool> is_true(const Value &val);

  // --- 4. Memory ---
  Value mem_allocate(NoOpScheduler &sched, uint64_t size_bytes,
                     uint64_t align_bytes);
  void mem_free(NoOpScheduler &sched, const Value &address);
  bool mem_read(NoOpScheduler &sched, const Value &addr,
                const MemAccessHint &hint, Value &result);
  bool mem_write(NoOpScheduler &sched, const Value &addr,
                 const Value &val, const MemAccessHint &hint);
  bool mem_bulk_op(NoOpScheduler &sched, MemOp sub,
                   const std::vector<Value> &ops,
                   const MemoryInst &mi, Value &result);
  void mem_poison(const Value &addr);
  void mem_unpoison(const Value &addr);
  bool is_undefined(const Value &val);

  // --- 5. Resolution ---
  bool resolve_branch(NoOpScheduler &sched, const Value &condition,
                      IRBlock true_block, IRBlock false_block,
                      IRBlock &chosen_block);
  bool resolve_call(NoOpScheduler &sched,
                    const IRInstruction &call_inst,
                    RawEntityId target_eid,
                    RawEntityId indirect_target_eid,
                    const std::vector<Value> &arguments,
                    bool is_indirect,
                    CallResolution &resolution);
  bool resolve_global(NoOpScheduler &sched, RawEntityId entity_id,
                      GlobalResolution &resolution);

  // --- Interpreter control ---

  // Initialize state for executing a function with the given arguments.
  MX_EXPORT void init_state(InterpreterState<Value> &state,
                            const IRFunction &func,
                            const std::vector<Value> &args);

  // Greedy step: runs up to max_steps instructions. Pushes continuations
  // into the scheduler. Returns true if budget hit (state still runnable),
  // false if state was consumed into continuation(s).
  MX_EXPORT bool step(InterpreterState<Value> &state, NoOpScheduler &sched,
                      uint64_t max_steps);

 private:
  ConcreteMemory &memory_;
  FunctionResolver func_resolver_;
  GlobalResolver global_resolver_;

  // Concrete-only helpers. Never called by the interpreter.
  static uint64_t extract_address(const Value &val);
  static bool has_concrete_address(const Value &val);
  void write_value_to_mem(uint64_t address, const Value &val, size_t size);
  Value read_value_from_mem(uint64_t address, size_t size, bool is_float);
};

}  // namespace mx::ir::interpret
