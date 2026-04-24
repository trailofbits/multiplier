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
//
// The policy uses this to make informed decisions about symbolic resolution:
// address concretization depends on whether it's a read or write, how wide
// the access is, and whether pointer provenance matters.
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
// Scheduler<Derived> — CRTP base for path exploration.
//
// The policy emits forks and errors into the scheduler during execution.
// The interpreter never inspects what was emitted — it only checks whether
// the current path is still alive (via policy method return values).
//
// A fork is: (frozen state, frozen memory, transition functor).
// The functor knows how to mutate thawed copies to produce the forked path.
// This avoids materializing states that the scheduler may never explore.
//
// Instantiations:
//   NoOpScheduler  — concrete execution, all methods compile away.
//   VirtualScheduler — Python-subclassable, holds fork/error queues.
// ===========================================================================

// The transition functor: given thawed (state, memory) copies, apply the
// fork's specific mutation (e.g., "this address resolved to 0x4000").
using Transition = std::function<void(InterpreterState<Value> &, void *policy)>;

template <typename Derived, typename ValueT = Value>
struct Scheduler {
 protected:
  Derived &self() { return static_cast<Derived &>(*this); }

 public:
  void emit_fork(const InterpreterState<ValueT> &state,
                 Transition transition) {
    self().emit_fork(state, std::move(transition));
  }

  void emit_error(const InterpreterState<ValueT> &state,
                  std::string_view message) {
    self().emit_error(state, message);
  }

  // Continuation-based interface: step() pushes decision points here.
  void add(Continuation cont) {
    self().add(std::move(cont));
  }
};

// Concrete execution: no forking, no error collection.
// Stores only the final continuation (COMPLETED or ERRORED).
struct NoOpScheduler : Scheduler<NoOpScheduler, Value> {
  std::optional<Continuation> result;

  void emit_fork(const InterpreterState<Value> &, Transition) {}
  void emit_error(const InterpreterState<Value> &, std::string_view) {}
  void add(Continuation cont) { result = std::move(cont); }
};

// ===========================================================================
// Policy<Derived, Sched> — CRTP base for all value-domain operations.
//
// The interpreter handles ONLY IR structure: block walking, opcode dispatch,
// call-stack frames. Everything that touches the value domain goes through
// the policy. Every method that might trigger a symbolic decision takes a
// Scheduler reference for emitting forks.
//
// Method return convention:
//   bool → "is this path still alive?" (true = keep going, false = dead)
//   Results are written to out-parameters.
//
// Completion and fork emission are orthogonal:
//   - A method can return true AND emit forks (e.g., fault injection).
//   - A method can return false AND emit an error.
//   - A method can return true with no emissions (pure concrete).
// ===========================================================================

template <typename Derived, typename Sched, typename ValueT = Value>
struct Policy {
  using value_type = ValueT;
 protected:
  Derived &self() { return static_cast<Derived &>(*this); }
  const Derived &self() const { return static_cast<const Derived &>(*this); }

 public:

  // =========================================================================
  // 1. VALUE CONSTRUCTION
  // =========================================================================

  // Construct a constant from the IR's CONST instruction.
  Value make_const(ConstOp op, int64_t signed_val, uint64_t unsigned_val) {
    return self().make_const(op, signed_val, unsigned_val);
  }

  Value make_null_ptr(void) {
    return self().make_null_ptr();
  }

  // =========================================================================
  // 2. ARITHMETIC / LOGIC
  //
  // None of these take a scheduler because pure arithmetic doesn't fork.
  // If a policy wants to inject faults on arithmetic (e.g., overflow
  // detection), it can hold a scheduler reference internally.
  // =========================================================================

  Value binary_op(OpCode op, const Value &lhs, const Value &rhs) {
    return self().binary_op(op, lhs, rhs);
  }

  Value unary_op(OpCode op, const Value &operand) {
    return self().unary_op(op, operand);
  }

  Value compare(OpCode op, const Value &lhs, const Value &rhs) {
    return self().compare(op, lhs, rhs);
  }

  Value cast(CastOp op, const Value &operand) {
    return self().cast(op, operand);
  }

  Value ptr_add(const Value &base, const Value &index,
                int64_t element_size) {
    return self().ptr_add(base, index, element_size);
  }

  Value ptr_diff(const Value &lhs, const Value &rhs,
                 int64_t element_size) {
    return self().ptr_diff(lhs, rhs, element_size);
  }

  // Pointer + constant byte offset (GEP_FIELD).
  // The offset is a compile-time constant from the IR.
  Value ptr_offset(const Value &base, int64_t byte_offset) {
    return self().ptr_offset(base, byte_offset);
  }

  Value select(const Value &cond, const Value &if_true,
               const Value &if_false) {
    return self().select(cond, if_true, if_false);
  }

  Value bitwise_intrinsic(OpCode width_op, BitwiseOp sub,
                          const Value &val, const Value &val2) {
    return self().bitwise_intrinsic(width_op, sub, val, val2);
  }

  Value float_intrinsic(FloatOp sub,
                        const std::vector<Value> &operands) {
    return self().float_intrinsic(sub, operands);
  }

  // =========================================================================
  // 3. TRUTH TEST
  //
  // Returns concrete truth value, or nullopt. When nullopt, the interpreter
  // calls resolve_branch (which takes the scheduler and can fork).
  // =========================================================================

  std::optional<bool> is_true(const Value &val) {
    return self().is_true(val);
  }

  // =========================================================================
  // 4. MEMORY
  //
  // Addresses are Value, not uint64_t. The policy resolves them.
  // Every method takes the scheduler — memory operations are the primary
  // fork points in symbolic execution (symbolic addresses, fault injection).
  //
  // Returns bool: true = path alive, false = path dead.
  // Results written to out-parameters.
  // =========================================================================

  // Allocate a memory region. Returns a pointer-valued Value.
  Value mem_allocate(Sched &sched, uint64_t size_bytes,
                     uint64_t align_bytes) {
    return self().mem_allocate(sched, size_bytes, align_bytes);
  }

  void mem_free(Sched &sched, const Value &address) {
    self().mem_free(sched, address);
  }

  // Read a typed value from memory.
  // addr: Value-domain address (may be symbolic).
  // hint: access context (size, float, read/write, sub-op).
  // result: receives the loaded value.
  // Returns: is this path alive?
  bool mem_read(Sched &sched, const Value &addr,
                const MemAccessHint &hint, Value &result) {
    return self().mem_read(sched, addr, hint, result);
  }

  // Write a typed value to memory.
  bool mem_write(Sched &sched, const Value &addr, const Value &val,
                 const MemAccessHint &hint) {
    return self().mem_write(sched, addr, val, hint);
  }

  // Bulk memory/string operation (memset, memcpy, strlen, strcmp, ...).
  // All 36 MemOp cases. The policy dispatches internally.
  bool mem_bulk_op(Sched &sched, MemOp sub,
                   const std::vector<Value> &ops,
                   const MemoryInst &mi, Value &result) {
    return self().mem_bulk_op(sched, sub, ops, mi, result);
  }

  void mem_poison(const Value &addr) {
    self().mem_poison(addr);
  }

  void mem_unpoison(const Value &addr) {
    self().mem_unpoison(addr);
  }

  // Check if an address is undefined/poison.
  bool is_undefined(const Value &val) {
    return self().is_undefined(val);
  }

  // =========================================================================
  // 5. RESOLUTION
  //
  // Called when the interpreter needs external decisions. The scheduler is
  // the primary recipient of forks. These methods return bool (path alive)
  // and write results to out-parameters.
  // =========================================================================

  // Branch resolution. Called when is_true() returns nullopt.
  // The policy can: pick one path and emit a fork for the other,
  // emit forks for both and return false (this path dies, scheduler
  // has two new paths), or pick one and not fork.
  bool resolve_branch(Sched &sched, const Value &condition,
                      IRBlock true_block, IRBlock false_block,
                      IRBlock &chosen_block) {
    return self().resolve_branch(
        sched, condition, true_block, false_block, chosen_block);
  }

  // Call resolution. Called for CALL instructions where the callee IR
  // isn't directly available from the target declaration.
  bool resolve_call(Sched &sched,
                    const IRInstruction &call_inst,
                    RawEntityId target_eid,
                    RawEntityId indirect_target_eid,
                    const std::vector<Value> &arguments,
                    bool is_indirect,
                    CallResolution &resolution) {
    return self().resolve_call(
        sched, call_inst, target_eid, indirect_target_eid,
        arguments, is_indirect, resolution);
  }

  // Global variable resolution.
  bool resolve_global(Sched &sched, RawEntityId entity_id,
                      GlobalResolution &resolution) {
    return self().resolve_global(
        sched, entity_id, resolution);
  }
};

// ===========================================================================
// VirtualPolicy — base class for Python-subclassable policies.
//
// Every method is virtual. A VirtualScheduler is used (also virtual).
// The Python proxy subclass overrides methods and forwards to Python.
//
// Default implementations delegate to a ConcretePolicy internally,
// so a Python subclass only needs to override the methods it cares about.
// ===========================================================================

struct VirtualScheduler : Scheduler<VirtualScheduler> {
  virtual ~VirtualScheduler(void) = default;

  virtual void emit_fork(const InterpreterState<Value> &state,
                         Transition transition) = 0;
  virtual void emit_error(const InterpreterState<Value> &state,
                          std::string_view message) = 0;
};

class VirtualPolicy : public Policy<VirtualPolicy, VirtualScheduler> {
 public:
  virtual ~VirtualPolicy(void) = default;

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
                            CallResolution &resolution) = 0;
  virtual bool resolve_global(VirtualScheduler &sched,
                              RawEntityId entity_id,
                              GlobalResolution &resolution) = 0;
};

}  // namespace mx::ir::interpret
