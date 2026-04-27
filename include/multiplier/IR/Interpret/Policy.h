// Copyright (c) 2024-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include "Value.h"
#include "Suspension.h"
#include "Interpreter.h"
#include "Continuation.h"

#include <multiplier/IR/OpCode.h>
#include <multiplier/IR/Block.h>
#include <multiplier/IR/Function.h>
#include <multiplier/IR/Instruction.h>
#include <multiplier/IR/InstructionKinds.h>
#include <multiplier/Types.h>

#include <functional>
#include <optional>
#include <vector>

namespace mx::ir::interpret {

class ConcreteMemory;

// ===========================================================================
// MemAccessHint — context passed to memory operations.
// ===========================================================================

struct MemAccessHint {
  uint32_t size_bytes{0};
  bool is_float{false};
  bool is_write{false};
  bool is_atomic{false};
  bool is_pointer{false};
  MemOp sub_op{};
};

// ===========================================================================
// Scheduler<Derived, ValueT> — CRTP base for path exploration.
//
// Result methods (on_completed, on_errored, on_branch) replace the old
// sched.add(Continuation) interface. Each scheduler type decides how to
// store results: NoOpScheduler creates Continuation objects, PythonScheduler
// stores SharedPyPtr results directly.
// ===========================================================================

template <typename Derived, typename ValueT = Value>
struct Scheduler {
 protected:
  Derived &self() { return static_cast<Derived &>(*this); }

 public:
  // `state` parameters use `auto` so each scheduler's snapshot type
  // (StdShared shared_ptr or PyObjectRC PyRef) flows through unchanged.
  void emit_fork(const auto &state, auto transition) {
    self().emit_fork(state, std::move(transition));
  }

  void emit_error(const auto &state, std::string_view message) {
    self().emit_error(state, message);
  }

  // Result methods — called by the interpreter loop for terminal/suspension states.
  void on_completed(ValueT return_value, auto &&state) {
    self().on_completed(std::move(return_value),
                        std::forward<decltype(state)>(state));
  }

  void on_errored(ErrorKind kind, auto &&state) {
    self().on_errored(kind, std::forward<decltype(state)>(state));
  }

  void on_branch(ValueT condition, RawEntityId cond_eid,
                 IRBlock true_block, IRBlock false_block,
                 ValueT false_val, ValueT true_val,
                 auto &&state) {
    self().on_branch(std::move(condition), cond_eid, true_block, false_block,
                     std::move(false_val), std::move(true_val),
                     std::forward<decltype(state)>(state));
  }
};

// Concrete execution: no forking, no error collection.
// Drains a single StepOutcome — the loop's terminal/continuation slots.
struct NoOpScheduler : Scheduler<NoOpScheduler, Value> {
  StepOutcome<Value> outcome;

  void emit_fork(const InterpreterState<Value> &,
                 std::function<void(InterpreterState<Value> &, void *)>) {}
  void emit_error(const InterpreterState<Value> &, std::string_view) {}

  void on_completed(Value return_value,
                    ref_t<InterpreterState<Value>> state) {
    outcome.terminal = TerminalResult<Value>{
        TerminalKind::COMPLETED, std::move(return_value), {},
        std::move(state)};
  }

  void on_errored(ErrorKind kind,
                  ref_t<InterpreterState<Value>> state) {
    outcome.terminal = TerminalResult<Value>{
        TerminalKind::ERRORED, {}, kind, std::move(state)};
  }

  void on_branch(Value condition, RawEntityId cond_eid,
                 IRBlock true_block, IRBlock false_block,
                 Value false_val, Value true_val,
                 ref_t<InterpreterState<Value>> state) {
    outcome.continuations.emplace_back(
        std::make_unique<BranchContinuation<Value>>(
            std::move(state), std::move(condition), cond_eid,
            true_block, false_block,
            std::move(false_val), std::move(true_val)));
  }
};

// ===========================================================================
// Policy<Derived, ValueT> — CRTP base for all value-domain operations.
//
// All methods use ValueT so the same template works for both concrete
// (ValueT = Value) and Python (ValueT = SharedPyPtr) paths.
//
// The scheduler isn't part of the policy's identity — each scheduler-using
// method is templated on its own `auto &sched`, so a single policy can run
// under any scheduler whose interface the derived class accepts.
// ===========================================================================

template <typename Derived, typename ValueT = Value>
struct Policy {
  using value_type = ValueT;
 protected:
  Derived &self() { return static_cast<Derived &>(*this); }
  const Derived &self() const { return static_cast<const Derived &>(*this); }

 public:

  // =========================================================================
  // 0. VALUE EXTRACTION / CONSTRUCTION (interpreter bookkeeping)
  // =========================================================================

  std::optional<uint64_t> extract_address(const ValueT &val) {
    return self().extract_address(val);
  }

  int64_t extract_int(const ValueT &val) {
    return self().extract_int(val);
  }

  uint64_t extract_uint(const ValueT &val) {
    return self().extract_uint(val);
  }

  ValueT make_literal_int(int64_t v, uint8_t width = 8) {
    return self().make_literal_int(v, width);
  }

  ValueT make_literal_ptr(uint64_t addr) {
    return self().make_literal_ptr(addr);
  }

  ValueT make_default() {
    return self().make_default();
  }

  bool has_address(const ValueT &val) {
    return self().has_address(val);
  }

  // =========================================================================
  // 1. VALUE CONSTRUCTION
  // =========================================================================

  ValueT make_const(ConstOp op, int64_t signed_val, uint64_t unsigned_val) {
    return self().make_const(op, signed_val, unsigned_val);
  }

  ValueT make_null_ptr(void) {
    return self().make_null_ptr();
  }

  // =========================================================================
  // 2. ARITHMETIC / LOGIC
  // =========================================================================

  ValueT binary_op(OpCode op, const ValueT &lhs, const ValueT &rhs) {
    return self().binary_op(op, lhs, rhs);
  }

  ValueT unary_op(OpCode op, const ValueT &operand) {
    return self().unary_op(op, operand);
  }

  ValueT compare(OpCode op, const ValueT &lhs, const ValueT &rhs) {
    return self().compare(op, lhs, rhs);
  }

  ValueT cast(CastOp op, const ValueT &operand) {
    return self().cast(op, operand);
  }

  ValueT ptr_add(const ValueT &base, const ValueT &index,
                 int64_t element_size) {
    return self().ptr_add(base, index, element_size);
  }

  ValueT ptr_diff(const ValueT &lhs, const ValueT &rhs,
                  int64_t element_size) {
    return self().ptr_diff(lhs, rhs, element_size);
  }

  ValueT ptr_offset(const ValueT &base, int64_t byte_offset) {
    return self().ptr_offset(base, byte_offset);
  }

  ValueT select(const ValueT &cond, const ValueT &if_true,
                const ValueT &if_false) {
    return self().select(cond, if_true, if_false);
  }

  ValueT bitwise_intrinsic(OpCode width_op, BitwiseOp sub,
                            const ValueT &val, const ValueT &val2) {
    return self().bitwise_intrinsic(width_op, sub, val, val2);
  }

  ValueT float_intrinsic(FloatOp sub,
                          const std::vector<ValueT> &operands) {
    return self().float_intrinsic(sub, operands);
  }

  // =========================================================================
  // 3. TRUTH TEST
  // =========================================================================

  std::optional<bool> is_true(const ValueT &val) {
    return self().is_true(val);
  }

  // =========================================================================
  // 4. MEMORY
  // =========================================================================

  ValueT mem_allocate(auto &sched, uint64_t size_bytes,
                      uint64_t align_bytes) {
    return self().mem_allocate(sched, size_bytes, align_bytes);
  }

  void mem_free(auto &sched, const ValueT &address) {
    self().mem_free(sched, address);
  }

  bool mem_read(auto &sched, const ValueT &addr,
                const MemAccessHint &hint, ValueT &result) {
    return self().mem_read(sched, addr, hint, result);
  }

  bool mem_write(auto &sched, const ValueT &addr, const ValueT &val,
                 const MemAccessHint &hint) {
    return self().mem_write(sched, addr, val, hint);
  }

  bool mem_bulk_op(auto &sched, MemOp sub,
                   const std::vector<ValueT> &ops,
                   const MemoryInst &mi, ValueT &result) {
    return self().mem_bulk_op(sched, sub, ops, mi, result);
  }

  void mem_poison(const ValueT &addr) {
    self().mem_poison(addr);
  }

  void mem_unpoison(const ValueT &addr) {
    self().mem_unpoison(addr);
  }

  bool is_undefined(const ValueT &val) {
    return self().is_undefined(val);
  }

  // Continuation-passing memory access. The body receives the policy, a
  // mutable memory reference, and a resolved 64-bit concrete address.
  // Returns true iff the body ran (address could be resolved inline, or
  // the override resolved it through a custom path). Returns false when
  // the policy could not produce a concrete address; symbolic policies
  // additionally emit a `MemAddrContinuation` describing the suspension.
  //
  // `addr_eid` is the operand entity-id whose value slot the driver will
  // write into when resuming with a concrete address. Pass
  // `kInvalidEntityId` from callsites that cannot meaningfully resume
  // (e.g. init-time bulk copies). Suspension-capable overrides treat
  // invalid eids as "do not suspend, just skip".
  template <typename Body>
  bool with_address(const ValueT &addr, ConcreteMemory &mem,
                    const MemAccessHint &hint, RawEntityId addr_eid,
                    auto &state, auto &sched, Body &&body) {
    return self().with_address_impl(
        addr, mem, hint, addr_eid, state, sched,
        std::forward<Body>(body));
  }

  // Phase 8a: symbolic-address dispatch for LOAD / STORE. Policies that
  // can resolve a non-extractable address through their own machinery
  // (e.g. a per-region z3 Array overlay) override `_impl` and return
  // true after populating `result` (load) or claiming the write
  // (store). The default returns false, leaving the caller to fall
  // through to `with_address` and the existing concrete / suspension
  // path. Concrete policies inherit the default verbatim.
  bool exec_symbolic_load(auto &sched, const ValueT &addr,
                          const MemAccessHint &hint, ValueT &result) {
    return self().exec_symbolic_load_impl(sched, addr, hint, result);
  }

  bool exec_symbolic_store(auto &sched, const ValueT &addr,
                           const ValueT &val, const MemAccessHint &hint) {
    return self().exec_symbolic_store_impl(sched, addr, val, hint);
  }

  bool exec_symbolic_load_impl(auto & /*sched*/, const ValueT & /*addr*/,
                               const MemAccessHint & /*hint*/,
                               ValueT & /*result*/) {
    return false;
  }

  bool exec_symbolic_store_impl(auto & /*sched*/, const ValueT & /*addr*/,
                                const ValueT & /*val*/,
                                const MemAccessHint & /*hint*/) {
    return false;
  }

  // Default override target for `with_address`. Concrete policies inherit
  // this verbatim — `extract_address` always succeeds for concrete values,
  // so the body runs inline and the function returns true.
  template <typename Body>
  bool with_address_impl(const ValueT &addr, ConcreteMemory &mem,
                         const MemAccessHint & /*hint*/,
                         RawEntityId /*addr_eid*/,
                         auto & /*state*/, auto & /*sched*/,
                         Body &&body) {
    if (auto a = self().extract_address(addr)) {
      body(self(), mem, *a);
      return true;
    }
    return false;
  }

  // =========================================================================
  // 5. RESOLUTION
  // =========================================================================

  bool resolve_branch(auto &sched, const ValueT &condition,
                      IRBlock true_block, IRBlock false_block,
                      IRBlock &chosen_block) {
    return self().resolve_branch(
        sched, condition, true_block, false_block, chosen_block);
  }

  bool resolve_call(auto &sched,
                    const IRInstruction &call_inst,
                    RawEntityId target_eid,
                    RawEntityId indirect_target_eid,
                    const std::vector<ValueT> &arguments,
                    bool is_indirect,
                    CallResolution<ValueT> &resolution) {
    return self().resolve_call(
        sched, call_inst, target_eid, indirect_target_eid,
        arguments, is_indirect, resolution);
  }

  bool resolve_global(auto &sched, RawEntityId entity_id,
                      GlobalResolution &resolution) {
    return self().resolve_global(
        sched, entity_id, resolution);
  }
};

}  // namespace mx::ir::interpret
