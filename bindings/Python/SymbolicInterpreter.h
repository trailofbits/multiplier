// Copyright (c) 2024-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <multiplier/IR/Interpret/Policy.h>
#include <multiplier/IR/Interpret/ConcreteOps.h>
#include <multiplier/IR/Interpret/ConcreteMemory.h>
#include <multiplier/IR/Interpret/ConcretePolicy.h>
#include <multiplier/IR/OpCode.h>

#include <Python.h>
#include <optional>
#include <vector>

#include "SharedPyPtr.h"
#include "Binding.h"

namespace mx {

using namespace ir;
using namespace ir::interpret;

// ===========================================================================
// PythonScheduler — collects forks and terminal results for exploration.
//
// Uses Value as the value type. The scheduler stores forked state snapshots
// so the Python explorer can resume them.
// ===========================================================================

struct PythonScheduler : Scheduler<PythonScheduler, Value> {
  struct Fork {
    std::shared_ptr<InterpreterState<Value>> snapshot;
    Transition transition;
  };

  std::vector<Fork> forks;
  std::optional<Continuation> result;

  void emit_fork(const InterpreterState<Value> &state,
                 Transition transition) {
    forks.push_back({std::make_shared<InterpreterState<Value>>(state),
                     std::move(transition)});
  }

  void emit_error(const InterpreterState<Value> &, std::string_view) {}

  void add(Continuation cont) { result = std::move(cont); }
};

// ===========================================================================
// PythonPolicy — delegates value ops to a Python object.
//
// The py_policy_ Python object can implement any of:
//   binary_op(op, lhs, rhs) -> value
//   unary_op(op, operand) -> value
//   compare(op, lhs, rhs) -> value
//   cast(op, operand) -> value
//   is_true(val) -> bool / None
//   resolve_branch(condition, true_block_id, false_block_id) -> True/False/None
//
// For methods not implemented in Python, falls back to concrete computation.
// Memory operations use ConcreteMemory directly (address space is always
// concrete, even when values are symbolic).
// ===========================================================================

class PythonPolicy
    : public Policy<PythonPolicy, PythonScheduler, Value> {
 public:
  PythonPolicy(PyObject *py_policy, ConcreteMemory &memory,
               FunctionResolver func_resolver = {},
               GlobalResolver global_resolver = {});
  ~PythonPolicy();

  ConcreteMemory &memory(void) { return memory_; }
  const ConcreteMemory &memory(void) const { return memory_; }

  // 1. Value construction — always concrete.
  Value make_const(ConstOp op, int64_t signed_val, uint64_t unsigned_val);
  Value make_null_ptr(void);

  // 2. Arithmetic / logic — delegates to Python if available.
  Value binary_op(OpCode op, const Value &lhs, const Value &rhs);
  Value unary_op(OpCode op, const Value &operand);
  Value compare(OpCode op, const Value &lhs, const Value &rhs);
  Value cast(CastOp op, const Value &operand);
  Value ptr_add(const Value &base, const Value &index, int64_t element_size);
  Value ptr_diff(const Value &lhs, const Value &rhs, int64_t element_size);
  Value ptr_offset(const Value &base, int64_t byte_offset);
  Value select(const Value &cond, const Value &if_true, const Value &if_false);
  Value bitwise_intrinsic(OpCode width_op, BitwiseOp sub,
                          const Value &val, const Value &val2);
  Value float_intrinsic(FloatOp sub, const std::vector<Value> &operands);

  // 3. Truth test — delegates to Python if available.
  std::optional<bool> is_true(const Value &val);

  // 4. Memory — concrete implementation.
  Value mem_allocate(PythonScheduler &sched, uint64_t size_bytes,
                     uint64_t align_bytes);
  void mem_free(PythonScheduler &sched, const Value &address);
  bool mem_read(PythonScheduler &sched, const Value &addr,
                const MemAccessHint &hint, Value &result);
  bool mem_write(PythonScheduler &sched, const Value &addr,
                 const Value &val, const MemAccessHint &hint);
  bool mem_bulk_op(PythonScheduler &sched, MemOp sub,
                   const std::vector<Value> &ops,
                   const MemoryInst &mi, Value &result);
  void mem_poison(const Value &addr);
  void mem_unpoison(const Value &addr);
  bool is_undefined(const Value &val);

  // 5. Resolution — delegates to Python if available.
  bool resolve_branch(PythonScheduler &sched, const Value &condition,
                      IRBlock true_block, IRBlock false_block,
                      IRBlock &chosen_block);
  bool resolve_call(PythonScheduler &sched,
                    const IRInstruction &call_inst,
                    RawEntityId target_eid,
                    RawEntityId indirect_target_eid,
                    const std::vector<Value> &arguments,
                    bool is_indirect,
                    CallResolution &resolution);
  bool resolve_global(PythonScheduler &sched, RawEntityId entity_id,
                      GlobalResolution &resolution);

 private:
  SharedPyPtr py_policy_;
  ConcreteMemory &memory_;
  FunctionResolver func_resolver_;
  GlobalResolver global_resolver_;

  // Cached Python method lookups.  nullptr means "not yet looked up",
  // Py_None means "looked up but doesn't exist on the policy".
  PyObject *cached_binary_op_{nullptr};
  PyObject *cached_unary_op_{nullptr};
  PyObject *cached_compare_{nullptr};
  PyObject *cached_cast_{nullptr};
  PyObject *cached_is_true_{nullptr};
  PyObject *cached_resolve_branch_{nullptr};

  // Look up a method on the policy, caching the result.  Returns the
  // bound method (borrowed ref) or nullptr if the method doesn't exist.
  PyObject *lookup_method(PyObject *&cache, const char *name);

  // Concrete helpers for memory operations.
  static uint64_t extract_address(const Value &val);
  static bool has_concrete_address(const Value &val);
  void write_value_to_mem(uint64_t address, const Value &val, size_t size);
  Value read_value_from_mem(uint64_t address, size_t size, bool is_float);
};

// Symbolic dispatch helpers called from unified init_state/step.
PyObject *SymbolicInitState(PyObject *state_obj, PyObject *memory_obj,
                            PyObject *py_policy, PyObject *func_obj,
                            PyObject *args_list,
                            PyObject *func_resolver_obj,
                            PyObject *global_resolver_obj);
PyObject *SymbolicStep(PyObject *state_obj, PyObject *memory_obj,
                       PyObject *py_policy, uint64_t max_steps,
                       PyObject *func_resolver_obj,
                       PyObject *global_resolver_obj);

}  // namespace mx
