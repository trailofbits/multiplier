// Copyright (c) 2024-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <multiplier/IR/Interpret/Policy.h>
#include <multiplier/IR/Interpret/ConcreteOps.h>
#include <multiplier/IR/Interpret/ConcreteMemory.h>
#include <multiplier/IR/Interpret/ConcretePolicy.h>
#include <multiplier/IR/Interpret/Continuation.h>
#include <multiplier/IR/Interpret/SharablePy.h>
#include <multiplier/IR/OpCode.h>

#include <Python.h>
#include <memory>
#include <optional>
#include <vector>

#include "SharedPyPtr.h"
#include "Binding.h"

namespace mx {

using namespace ir;
using namespace ir::interpret;

// PyObjectRC instantiation of the symbolic interpreter state. The Python
// type registered for this struct IS the storage — no separate wrapper
// indirection.
using SymbolicState = InterpreterState<SharedPyPtr, PyObjectRC>;

// ===========================================================================
// ValueTraits<SharedPyPtr> — Py_None as default value.
// ===========================================================================

template <>
struct ValueTraits<SharedPyPtr> {
  static SharedPyPtr default_value() { return SharedPyPtr(Py_None); }
};

// ===========================================================================
// PythonScheduler — drains a single StepOutcome.
//
// Each suspension produced by the interpreter loop becomes a
// `Continuation<SharedPyPtr>` pushed onto `outcome.continuations`.
// Terminal outcomes (completed / errored) populate `outcome.terminal`
// instead. SymbolicStep reads `outcome` to build the Python result dict.
// ===========================================================================

struct PythonScheduler : Scheduler<PythonScheduler, SharedPyPtr> {
  StepOutcome<SharedPyPtr, PyObjectRC> outcome;

  void emit_fork(const SymbolicState &,
                 std::function<void(SymbolicState &, void *)>) {}

  void emit_error(const SymbolicState &, std::string_view) {}

  void on_completed(SharedPyPtr val,
                    ref_t<SymbolicState> snap) {
    outcome.terminal = TerminalResult<SharedPyPtr, PyObjectRC>{
        TerminalKind::COMPLETED, std::move(val), {}, std::move(snap)};
  }

  void on_errored(ErrorKind kind,
                  ref_t<SymbolicState> snap) {
    outcome.terminal = TerminalResult<SharedPyPtr, PyObjectRC>{
        TerminalKind::ERRORED, {}, kind, std::move(snap)};
  }

  void on_branch(SharedPyPtr cond, RawEntityId cond_eid,
                 IRBlock tb, IRBlock fb,
                 SharedPyPtr false_val, SharedPyPtr true_val,
                 ref_t<SymbolicState> snapshot) {
    outcome.continuations.emplace_back(
        std::make_unique<BranchContinuation<SharedPyPtr, PyObjectRC>>(
            std::move(snapshot), std::move(cond), cond_eid, tb, fb,
            std::move(false_val), std::move(true_val)));
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

// Phase 9: function-address resolver. Returns nullopt to fall through
// to the bump allocator. A Some-result is reserved via place_at and
// becomes the per-engine slot address for the function.
using FunctionAddressResolver =
    std::function<std::optional<uint64_t>(RawEntityId)>;

class PythonPolicy
    : public Policy<PythonPolicy, SharedPyPtr> {
 public:
  PythonPolicy(PyObject *py_policy, ConcreteMemory &memory,
               FunctionResolver func_resolver = {},
               GlobalResolver global_resolver = {},
               FunctionAddressResolver func_addr_resolver = {});
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

  // Phase 8d: per-block-enter event. Fires `engine.observe.block_enter`
  // observers and appends a structured entry to `path.events`.
  template <typename StateT>
  void on_enter_block(StateT &, const IRBlock &block) {
    on_enter_block_impl(block);
  }
  // Implementation is non-templated so it can use lookup_method without
  // bloating each StateT instantiation.
  void on_enter_block_impl(const IRBlock &block);

  // Phase 8a: symbolic-address dispatch. Consults the Python policy's
  // `symbolic_load` / `symbolic_store` methods before the substrate
  // suspends; when Python claims the access (e.g. via a region-overlay
  // read), the substrate uses the returned value and skips suspension.
  bool exec_symbolic_load_impl(PythonScheduler &sched,
                               const SharedPyPtr &addr,
                               const MemAccessHint &hint,
                               SharedPyPtr &result);
  bool exec_symbolic_store_impl(PythonScheduler &sched,
                                const SharedPyPtr &addr,
                                const SharedPyPtr &val,
                                const MemAccessHint &hint);

  // Symbolic-address suspension. Inline-resolve concrete addresses;
  // when extract_address fails AND the callsite supplies a real
  // `addr_eid`, snapshot the state, re-push the current work item, and
  // emit a MemAddrContinuation. The current run halts (work_stack
  // cleared) so the driver can resume after picking an address.
  template <typename Body>
  bool with_address_impl(const SharedPyPtr &addr, ConcreteMemory &mem,
                         const MemAccessHint &hint, RawEntityId addr_eid,
                         SymbolicState &state,
                         PythonScheduler &sched, Body &&body) {
    if (auto a = extract_address(addr)) {
      next_is_call_target_ = false;  // consume (address resolved, no suspension)
      body(*this, mem, *a);
      return true;
    }
    if (addr_eid == kInvalidEntityId) {
      next_is_call_target_ = false;
      return false;
    }
    bool mark_call = next_is_call_target_;
    next_is_call_target_ = false;
    auto snap = make_sharable<SymbolicState>(state);
    snap->work_stack.push_back(state.current_item);
    auto cont = std::make_unique<MemAddrContinuation<SharedPyPtr, PyObjectRC>>(
        std::move(snap), addr, addr_eid,
        hint.size_bytes, hint.is_write);
    if (mark_call) {
      cont->set_call_target(true);
    }
    sched.outcome.continuations.emplace_back(std::move(cont));
    state.work_stack.clear();
    return false;
  }

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

  // Phase 9: per-function address invention. Falls back to nullopt
  // (substrate auto-allocates) when no resolver is wired in.
  std::optional<uint64_t> address_for_function_impl(PythonScheduler &,
                                                       RawEntityId eid) {
    if (func_addr_resolver_) {
      return func_addr_resolver_(eid);
    }
    return std::nullopt;
  }

  // Phase 9: marks the next with_address suspension as a call-target.
  // Consumed (and cleared) inside with_address_impl.
  void mark_next_suspension_as_call_target_impl() {
    next_is_call_target_ = true;
  }

 private:
  SharedPyPtr py_policy_;
  ConcreteMemory &memory_;
  FunctionResolver func_resolver_;
  GlobalResolver global_resolver_;
  FunctionAddressResolver func_addr_resolver_;

  PyObject *cached_make_const_{nullptr};
  PyObject *cached_binary_op_{nullptr};
  PyObject *cached_unary_op_{nullptr};
  PyObject *cached_compare_{nullptr};
  PyObject *cached_cast_{nullptr};
  PyObject *cached_is_true_{nullptr};
  PyObject *cached_resolve_branch_{nullptr};
  PyObject *cached_resolve_call_{nullptr};
  PyObject *cached_mem_read_{nullptr};
  PyObject *cached_mem_write_{nullptr};
  PyObject *cached_ptr_add_{nullptr};
  PyObject *cached_ptr_diff_{nullptr};
  PyObject *cached_ptr_offset_{nullptr};
  PyObject *cached_symbolic_load_{nullptr};
  PyObject *cached_symbolic_store_{nullptr};
  PyObject *cached_on_enter_block_{nullptr};

  // Phase 9: set by mark_next_suspension_as_call_target_impl; consumed
  // and cleared in with_address_impl when it emits a MemAddrContinuation.
  bool next_is_call_target_{false};

  PyObject *lookup_method(PyObject *&cache, const char *name);
};

// Symbolic dispatch helpers called from unified init_state/step.
PyObject *SymbolicInitState(PyObject *state_obj, PyObject *memory_obj,
                            PyObject *py_policy, PyObject *func_obj,
                            PyObject *args_list,
                            PyObject *func_resolver_obj,
                            PyObject *global_resolver_obj,
                            PyObject *func_addr_resolver_obj);
PyObject *SymbolicInitStateFrame(PyObject *state_obj, PyObject *memory_obj,
                                 PyObject *py_policy, PyObject *func_obj,
                                 PyObject *param_addrs_list,
                                 PyObject *return_addr_obj,
                                 PyObject *func_resolver_obj,
                                 PyObject *global_resolver_obj,
                                 PyObject *func_addr_resolver_obj);
// Mid-block entry: start at a chosen IRBlock with a caller-supplied seed
// of live-in values (dict mapping eid -> Python value). Symex driver uses
// this for under-constrained execution that begins partway through a
// function.
PyObject *SymbolicInitStateAt(PyObject *state_obj, PyObject *memory_obj,
                              PyObject *py_policy, PyObject *func_obj,
                              PyObject *block_obj,
                              PyObject *param_addrs_list,
                              PyObject *return_addr_obj,
                              PyObject *value_seed_dict,
                              PyObject *func_resolver_obj,
                              PyObject *global_resolver_obj,
                              PyObject *func_addr_resolver_obj);
PyObject *SymbolicStep(PyObject *state_obj, PyObject *memory_obj,
                       PyObject *py_policy, uint64_t max_steps,
                       PyObject *func_resolver_obj,
                       PyObject *global_resolver_obj,
                       PyObject *func_addr_resolver_obj);

// Register the private `_SymbolicState` PyTypeObject into the
// interpreter submodule. Called once during module init.
bool LoadSymbolicStateType(::PyObject *interp_module);

}  // namespace mx
