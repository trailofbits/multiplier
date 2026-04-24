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
// ValueTraits<SharedPyPtr> — Py_None as default value.
// ===========================================================================

template <>
struct ValueTraits<SharedPyPtr> {
  static SharedPyPtr default_value() { return SharedPyPtr(Py_None); }
};

// ===========================================================================
// PythonScheduler — stores results directly as SharedPyPtr.
//
// Does not use Continuation (which is Value-typed). Results are read
// directly by SymbolicStep to build the Python result dict.
// ===========================================================================

struct PythonScheduler : Scheduler<PythonScheduler, SharedPyPtr> {
  enum ResultKind { NONE, COMPLETED, ERRORED, BRANCH };

  ResultKind result_kind{NONE};
  SharedPyPtr return_value;
  ErrorKind error_kind{};
  SharedPyPtr branch_condition;
  uint64_t true_block_eid{0};
  uint64_t false_block_eid{0};

  struct Fork {
    std::shared_ptr<InterpreterState<SharedPyPtr>> snapshot;
    std::function<void(InterpreterState<SharedPyPtr> &, void *)> transition;
  };

  std::vector<Fork> forks;

  void emit_fork(const InterpreterState<SharedPyPtr> &state,
                 std::function<void(InterpreterState<SharedPyPtr> &, void *)> transition) {
    forks.push_back({std::make_shared<InterpreterState<SharedPyPtr>>(state),
                     std::move(transition)});
  }

  void emit_error(const InterpreterState<SharedPyPtr> &, std::string_view) {}

  void on_completed(SharedPyPtr val,
                    std::shared_ptr<InterpreterState<SharedPyPtr>>) {
    result_kind = COMPLETED;
    return_value = std::move(val);
  }

  void on_errored(ErrorKind kind,
                  std::shared_ptr<InterpreterState<SharedPyPtr>>) {
    result_kind = ERRORED;
    error_kind = kind;
  }

  void on_branch(SharedPyPtr cond, IRBlock tb, IRBlock fb,
                 std::shared_ptr<InterpreterState<SharedPyPtr>>) {
    result_kind = BRANCH;
    branch_condition = std::move(cond);
    true_block_eid = EntityId(tb.id()).Pack();
    false_block_eid = EntityId(fb.id()).Pack();
  }
};

// ===========================================================================
// PythonPolicy — operates on SharedPyPtr (PyObject* with refcounting).
//
// Every value in the interpreter state is a SharedPyPtr. Policy methods
// take and return SharedPyPtr natively. Python policy methods receive
// the PyObject* directly — no conversion needed. Concrete fallback
// converts at the boundary via value_to_python / python_to_value.
// ===========================================================================

class PythonPolicy
    : public Policy<PythonPolicy, PythonScheduler, SharedPyPtr> {
 public:
  PythonPolicy(PyObject *py_policy, ConcreteMemory &memory,
               FunctionResolver func_resolver = {},
               GlobalResolver global_resolver = {});
  ~PythonPolicy();

  ConcreteMemory &memory(void) { return memory_; }
  const ConcreteMemory &memory(void) const { return memory_; }

  // 0. Value extraction / construction.
  std::optional<uint64_t> extract_address(const SharedPyPtr &val);
  int64_t extract_int(const SharedPyPtr &val);
  uint64_t extract_uint(const SharedPyPtr &val);
  SharedPyPtr make_literal_int(int64_t v, uint8_t width = 8);
  SharedPyPtr make_literal_ptr(uint64_t addr);
  SharedPyPtr make_default();
  bool has_address(const SharedPyPtr &val);

  // 1. Value construction.
  SharedPyPtr make_const(ConstOp op, int64_t signed_val, uint64_t unsigned_val);
  SharedPyPtr make_null_ptr(void);

  // 2. Arithmetic / logic.
  SharedPyPtr binary_op(OpCode op, const SharedPyPtr &lhs,
                        const SharedPyPtr &rhs);
  SharedPyPtr unary_op(OpCode op, const SharedPyPtr &operand);
  SharedPyPtr compare(OpCode op, const SharedPyPtr &lhs,
                      const SharedPyPtr &rhs);
  SharedPyPtr cast(CastOp op, const SharedPyPtr &operand);
  SharedPyPtr ptr_add(const SharedPyPtr &base, const SharedPyPtr &index,
                      int64_t element_size);
  SharedPyPtr ptr_diff(const SharedPyPtr &lhs, const SharedPyPtr &rhs,
                       int64_t element_size);
  SharedPyPtr ptr_offset(const SharedPyPtr &base, int64_t byte_offset);
  SharedPyPtr select(const SharedPyPtr &cond, const SharedPyPtr &if_true,
                     const SharedPyPtr &if_false);
  SharedPyPtr bitwise_intrinsic(OpCode width_op, BitwiseOp sub,
                                const SharedPyPtr &val,
                                const SharedPyPtr &val2);
  SharedPyPtr float_intrinsic(FloatOp sub,
                              const std::vector<SharedPyPtr> &operands);

  // 3. Truth test.
  std::optional<bool> is_true(const SharedPyPtr &val);

  // 4. Memory.
  SharedPyPtr mem_allocate(PythonScheduler &sched, uint64_t size_bytes,
                           uint64_t align_bytes);
  void mem_free(PythonScheduler &sched, const SharedPyPtr &address);
  bool mem_read(PythonScheduler &sched, const SharedPyPtr &addr,
                const MemAccessHint &hint, SharedPyPtr &result);
  bool mem_write(PythonScheduler &sched, const SharedPyPtr &addr,
                 const SharedPyPtr &val, const MemAccessHint &hint);
  bool mem_bulk_op(PythonScheduler &sched, MemOp sub,
                   const std::vector<SharedPyPtr> &ops,
                   const MemoryInst &mi, SharedPyPtr &result);
  void mem_poison(const SharedPyPtr &addr);
  void mem_unpoison(const SharedPyPtr &addr);
  bool is_undefined(const SharedPyPtr &val);

  // 5. Resolution.
  bool resolve_branch(PythonScheduler &sched, const SharedPyPtr &condition,
                      IRBlock true_block, IRBlock false_block,
                      IRBlock &chosen_block);
  bool resolve_call(PythonScheduler &sched,
                    const IRInstruction &call_inst,
                    RawEntityId target_eid,
                    RawEntityId indirect_target_eid,
                    const std::vector<SharedPyPtr> &arguments,
                    bool is_indirect,
                    CallResolution<SharedPyPtr> &resolution);
  bool resolve_global(PythonScheduler &sched, RawEntityId entity_id,
                      GlobalResolution &resolution);

 private:
  SharedPyPtr py_policy_;
  ConcreteMemory &memory_;
  FunctionResolver func_resolver_;
  GlobalResolver global_resolver_;

  PyObject *cached_make_const_{nullptr};
  PyObject *cached_binary_op_{nullptr};
  PyObject *cached_unary_op_{nullptr};
  PyObject *cached_compare_{nullptr};
  PyObject *cached_cast_{nullptr};
  PyObject *cached_is_true_{nullptr};
  PyObject *cached_resolve_branch_{nullptr};

  PyObject *lookup_method(PyObject *&cache, const char *name);
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
