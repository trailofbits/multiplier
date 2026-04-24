// Copyright (c) 2024-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include "Value.h"
#include "Suspension.h"
#include "Interpreter.h"

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
  void emit_fork(const InterpreterState<ValueT> &state,
                 std::function<void(InterpreterState<ValueT> &, void *)> transition) {
    self().emit_fork(state, std::move(transition));
  }

  void emit_error(const InterpreterState<ValueT> &state,
                  std::string_view message) {
    self().emit_error(state, message);
  }

  // Result methods — called by the interpreter loop for terminal/suspension states.
  void on_completed(ValueT return_value,
                    std::shared_ptr<InterpreterState<ValueT>> state) {
    self().on_completed(std::move(return_value), std::move(state));
  }

  void on_errored(ErrorKind kind,
                  std::shared_ptr<InterpreterState<ValueT>> state) {
    self().on_errored(kind, std::move(state));
  }

  void on_branch(ValueT condition, IRBlock true_block, IRBlock false_block,
                 std::shared_ptr<InterpreterState<ValueT>> state) {
    self().on_branch(std::move(condition), true_block, false_block,
                     std::move(state));
  }
};

// Concrete execution: no forking, no error collection.
// Stores only the final continuation (COMPLETED or ERRORED).
struct NoOpScheduler : Scheduler<NoOpScheduler, Value> {
  std::optional<Continuation> result;

  void emit_fork(const InterpreterState<Value> &,
                 std::function<void(InterpreterState<Value> &, void *)>) {}
  void emit_error(const InterpreterState<Value> &, std::string_view) {}

  void on_completed(Value return_value,
                    std::shared_ptr<InterpreterState<Value>> state);
  void on_errored(ErrorKind kind,
                  std::shared_ptr<InterpreterState<Value>> state);
  void on_branch(Value condition, IRBlock true_block, IRBlock false_block,
                 std::shared_ptr<InterpreterState<Value>> state);
};

// ===========================================================================
// Policy<Derived, Sched, ValueT> — CRTP base for all value-domain operations.
//
// All methods use ValueT so the same template works for both concrete
// (ValueT = Value) and Python (ValueT = SharedPyPtr) paths.
// ===========================================================================

template <typename Derived, typename Sched, typename ValueT = Value>
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

  ValueT mem_allocate(Sched &sched, uint64_t size_bytes,
                      uint64_t align_bytes) {
    return self().mem_allocate(sched, size_bytes, align_bytes);
  }

  void mem_free(Sched &sched, const ValueT &address) {
    self().mem_free(sched, address);
  }

  bool mem_read(Sched &sched, const ValueT &addr,
                const MemAccessHint &hint, ValueT &result) {
    return self().mem_read(sched, addr, hint, result);
  }

  bool mem_write(Sched &sched, const ValueT &addr, const ValueT &val,
                 const MemAccessHint &hint) {
    return self().mem_write(sched, addr, val, hint);
  }

  bool mem_bulk_op(Sched &sched, MemOp sub,
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

  // =========================================================================
  // 5. RESOLUTION
  // =========================================================================

  bool resolve_branch(Sched &sched, const ValueT &condition,
                      IRBlock true_block, IRBlock false_block,
                      IRBlock &chosen_block) {
    return self().resolve_branch(
        sched, condition, true_block, false_block, chosen_block);
  }

  bool resolve_call(Sched &sched,
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

  bool resolve_global(Sched &sched, RawEntityId entity_id,
                      GlobalResolution &resolution) {
    return self().resolve_global(
        sched, entity_id, resolution);
  }
};

// ===========================================================================
// VirtualPolicy — base class for Python-subclassable policies (Value-typed).
// ===========================================================================

struct VirtualScheduler : Scheduler<VirtualScheduler> {
  virtual ~VirtualScheduler(void) = default;

  virtual void emit_fork(const InterpreterState<Value> &state,
                         std::function<void(InterpreterState<Value> &, void *)> transition) = 0;
  virtual void emit_error(const InterpreterState<Value> &state,
                          std::string_view message) = 0;
};

class VirtualPolicy : public Policy<VirtualPolicy, VirtualScheduler> {
 public:
  virtual ~VirtualPolicy(void) = default;

  // 0. Value extraction / construction.
  virtual std::optional<uint64_t> extract_address(const Value &val) = 0;
  virtual int64_t extract_int(const Value &val) = 0;
  virtual uint64_t extract_uint(const Value &val) = 0;
  virtual Value make_literal_int(int64_t v, uint8_t width = 8) = 0;
  virtual Value make_literal_ptr(uint64_t addr) = 0;
  virtual Value make_default() = 0;
  virtual bool has_address(const Value &val) = 0;

  // 1. Value construction.
  virtual Value make_const(ConstOp op, int64_t signed_val,
                           uint64_t unsigned_val) = 0;
  virtual Value make_null_ptr(void) = 0;

  // 2. Arithmetic / logic.
  virtual Value binary_op(OpCode op, const Value &lhs,
                          const Value &rhs) = 0;
  virtual Value unary_op(OpCode op, const Value &operand) = 0;
  virtual Value compare(OpCode op, const Value &lhs,
                        const Value &rhs) = 0;
  virtual Value cast(CastOp op, const Value &operand) = 0;
  virtual Value ptr_add(const Value &base, const Value &index,
                        int64_t element_size) = 0;
  virtual Value ptr_diff(const Value &lhs, const Value &rhs,
                         int64_t element_size) = 0;
  virtual Value ptr_offset(const Value &base, int64_t byte_offset) = 0;
  virtual Value select(const Value &cond, const Value &if_true,
                       const Value &if_false) = 0;
  virtual Value bitwise_intrinsic(OpCode width_op, BitwiseOp sub,
                                  const Value &val,
                                  const Value &val2) = 0;
  virtual Value float_intrinsic(FloatOp sub,
                                const std::vector<Value> &operands) = 0;

  // 3. Truth test.
  virtual std::optional<bool> is_true(const Value &val) = 0;

  // 4. Memory.
  virtual Value mem_allocate(VirtualScheduler &sched,
                             uint64_t size_bytes,
                             uint64_t align_bytes) = 0;
  virtual void mem_free(VirtualScheduler &sched,
                        const Value &address) = 0;
  virtual bool mem_read(VirtualScheduler &sched, const Value &addr,
                        const MemAccessHint &hint, Value &result) = 0;
  virtual bool mem_write(VirtualScheduler &sched, const Value &addr,
                         const Value &val,
                         const MemAccessHint &hint) = 0;
  virtual bool mem_bulk_op(VirtualScheduler &sched, MemOp sub,
                           const std::vector<Value> &ops,
                           const MemoryInst &mi, Value &result) = 0;
  virtual void mem_poison(const Value &addr) = 0;
  virtual void mem_unpoison(const Value &addr) = 0;
  virtual bool is_undefined(const Value &val) = 0;

  // 5. Resolution.
  virtual bool resolve_branch(VirtualScheduler &sched,
                              const Value &condition,
                              IRBlock true_block, IRBlock false_block,
                              IRBlock &chosen_block) = 0;
  virtual bool resolve_call(VirtualScheduler &sched,
                            const IRInstruction &call_inst,
                            RawEntityId target_eid,
                            RawEntityId indirect_target_eid,
                            const std::vector<Value> &arguments,
                            bool is_indirect,
                            CallResolution<Value> &resolution) = 0;
  virtual bool resolve_global(VirtualScheduler &sched,
                              RawEntityId entity_id,
                              GlobalResolution &resolution) = 0;
};

}  // namespace mx::ir::interpret
