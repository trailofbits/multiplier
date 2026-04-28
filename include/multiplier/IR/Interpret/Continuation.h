// Copyright (c) 2024-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.
//
// Polymorphic continuations + terminal results for the IR interpreter.
//
// A `Continuation<ValueT>` represents a single suspension point: the
// interpreter could not complete an instruction without a decision from
// outside. The scheduler holds opaque continuations; each continuation
// knows its own decision space (via `enumerate`) and how to apply a
// resumption (via subclass-specific resume helpers).
//
// Branches, calls, global resolution, memory address concretization, and
// (later) symbolic value materialization all share this shape.
//
// `TerminalResult<ValueT>` is the orthogonal axis: the run finished
// (COMPLETED / ERRORED). Stored as a separate optional on the scheduler
// because it is at most one per step.

#pragma once

#include "Interpreter.h"

#include <multiplier/IR/Block.h>

#include <cstdint>
#include <memory>
#include <optional>
#include <string>
#include <utility>
#include <vector>

namespace mx::ir::interpret {

// `StatePolicy` selects the ref-count system for the snapshot held by a
// continuation. Defaults to `StdShared` so existing CLI / concrete code
// keeps using `std::shared_ptr<InterpreterState<...>>`. PyObjectRC
// instantiations (used by the symbolic Python bindings) propagate the
// policy through `ref_t<InterpreterState<ValueT, PyObjectRC>>` =
// `PyRef<...>`.

template <typename ValueT, typename StatePolicy = StdShared>
struct Resumption;

// ===========================================================================
// Continuation<ValueT> — polymorphic suspension base.
//
// A suspension says: "instruction I paused because operand %X had no
// usable value; resumption fills %X's slot in the snapshot's value cache
// and re-pushes I so re-execution finds %X concrete." Subclasses add a
// typed `resume(...)` that wraps the driver's primitive (bool, uint64_t,
// IRFunction, GlobalInfo) into a ValueT and delegates to `bind_and_clone`.
// ===========================================================================

template <typename ValueT, typename StatePolicy = StdShared>
class Continuation {
 public:
  using state_type = InterpreterState<ValueT, StatePolicy>;
  using state_ref = ref_t<state_type>;

  virtual ~Continuation(void) = default;

  // Snapshot to resume from. Shared so the same snapshot may serve
  // multiple resumptions (e.g. a branch -> two forks share the
  // pre-branch state).
  virtual state_ref snapshot(void) const = 0;

  // Human-readable description (for drivers / logging).
  virtual std::string describe(void) const = 0;

  // The operand-eid whose value slot the resumption fills.
  virtual RawEntityId operand_eid(void) const = 0;

  // For drivers that want to walk a finite enumeration (Branch yields
  // {false, true} then nullopt). Default: nullopt — driver-fed only.
  // Stateful: each call may consume internal state and is one-shot.
  virtual std::optional<Resumption<ValueT, StatePolicy>> next(void) {
    return std::nullopt;
  }

 protected:
  // Deep-copy the snapshot, write `bound` into the operand-eid slot of
  // the cloned call-frame's value cache, and return a Resumption. Used
  // by every subclass `resume(...)` override.
  Resumption<ValueT, StatePolicy> bind_and_clone(
      ValueT bound, std::string label) const {
    auto cloned = snapshot()->clone();
    cloned->call_stack.top().values[operand_eid()] = std::move(bound);
    return Resumption<ValueT, StatePolicy>{
        std::move(cloned), std::move(label)};
  }
};

// ===========================================================================
// Resumption<ValueT> — a structural choice produced by `next()` / `resume()`.
//
// Carries the already-prepared next state. The driver picks one (or more)
// resumptions to enqueue.
// ===========================================================================

template <typename ValueT, typename StatePolicy>
struct Resumption {
  ref_t<InterpreterState<ValueT, StatePolicy>> state;
  std::string label;  // e.g. "true", "false"
};

// ===========================================================================
// BranchContinuation<ValueT> — driver must pick the target block.
// ===========================================================================

template <typename ValueT, typename StatePolicy = StdShared>
class BranchContinuation final
    : public Continuation<ValueT, StatePolicy> {
 public:
  using state_ref = typename Continuation<ValueT, StatePolicy>::state_ref;

  // `false_val` / `true_val` are pre-built `make_literal_int(0|1, 1)`
  // results from the suspending policy. Storing them lets `next()` walk
  // the {false, true} enumeration without needing a policy reference.
  BranchContinuation(state_ref snap, ValueT condition, RawEntityId cond_eid,
                     IRBlock true_block, IRBlock false_block,
                     ValueT false_val, ValueT true_val)
      : snapshot_(std::move(snap)),
        condition_(std::move(condition)),
        cond_eid_(cond_eid),
        true_block_(true_block),
        false_block_(false_block),
        false_val_(std::move(false_val)),
        true_val_(std::move(true_val)) {}

  state_ref snapshot(void) const override { return snapshot_; }

  std::string describe(void) const override { return "branch"; }

  RawEntityId operand_eid(void) const override { return cond_eid_; }

  // Bind the chosen direction as a 1-bit int into the condition slot.
  template <typename PolicyT>
  Resumption<ValueT, StatePolicy> resume(PolicyT &policy, bool taken) {
    return this->bind_and_clone(
        policy.make_literal_int(taken ? 1 : 0, 1),
        taken ? "true" : "false");
  }

  // Yield {false, true} then nullopt. Stateful — one-shot per direction.
  std::optional<Resumption<ValueT, StatePolicy>> next(void) override {
    if (step_ == 0) {
      ++step_;
      return this->bind_and_clone(false_val_, "false");
    }
    if (step_ == 1) {
      ++step_;
      return this->bind_and_clone(true_val_, "true");
    }
    return std::nullopt;
  }

  const ValueT &condition(void) const { return condition_; }
  IRBlock true_block(void) const { return true_block_; }
  IRBlock false_block(void) const { return false_block_; }

 private:
  state_ref snapshot_;
  ValueT condition_;
  RawEntityId cond_eid_{kInvalidEntityId};
  IRBlock true_block_;
  IRBlock false_block_;
  ValueT false_val_;
  ValueT true_val_;
  uint8_t step_{0};
};

// ===========================================================================
// CallContinuation<ValueT> — driver must resolve an unresolved CALL.
//
// Emitted when the interpreter encounters a CALL site whose target IR is
// unknown to the policy. The driver supplies a CallResolution payload via
// a side-channel API (today: by setting return_value into the call_site
// slot before resuming), or asks the scheduler to enumerate.
// ===========================================================================
//
// CallContinuation/GlobalContinuation are emitted today only when policies
// explicitly opt out of inline resolution. The default Python and concrete
// policies still resolve everything inline, so these continuations don't
// fire under the existing test suite — they reserve the shape.
// ===========================================================================

template <typename ValueT, typename StatePolicy = StdShared>
class CallContinuation final : public Continuation<ValueT, StatePolicy> {
 public:
  using state_ref = typename Continuation<ValueT, StatePolicy>::state_ref;

  CallContinuation(state_ref snap, IRInstruction call_inst,
                   std::vector<ValueT> arguments,
                   RawEntityId target_eid, RawEntityId indirect_target_eid,
                   bool is_indirect)
      : snapshot_(std::move(snap)),
        call_inst_(std::move(call_inst)),
        arguments_(std::move(arguments)),
        target_eid_(target_eid),
        indirect_target_eid_(indirect_target_eid),
        is_indirect_(is_indirect) {}

  state_ref snapshot(void) const override { return snapshot_; }

  std::string describe(void) const override { return "call"; }

  // The CALL instruction's eid — the result slot resumption fills.
  RawEntityId operand_eid(void) const override {
    return EntityId(call_inst_.id()).Pack();
  }

  // Bind a modeled / skipped return value as the CALL result.
  template <typename PolicyT>
  Resumption<ValueT, StatePolicy> resume(PolicyT & /*policy*/,
                                         ValueT return_value) {
    return this->bind_and_clone(std::move(return_value), "call");
  }

  const IRInstruction &call_inst(void) const { return call_inst_; }
  const std::vector<ValueT> &arguments(void) const { return arguments_; }
  RawEntityId target_eid(void) const { return target_eid_; }
  RawEntityId indirect_target_eid(void) const { return indirect_target_eid_; }
  bool is_indirect(void) const { return is_indirect_; }

 private:
  state_ref snapshot_;
  IRInstruction call_inst_;
  std::vector<ValueT> arguments_;
  RawEntityId target_eid_{kInvalidEntityId};
  RawEntityId indirect_target_eid_{kInvalidEntityId};
  bool is_indirect_{false};
};

// ===========================================================================
// GlobalContinuation<ValueT> — driver must resolve an unresolved global.
// ===========================================================================

template <typename ValueT, typename StatePolicy = StdShared>
class GlobalContinuation final : public Continuation<ValueT, StatePolicy> {
 public:
  using state_ref = typename Continuation<ValueT, StatePolicy>::state_ref;

  GlobalContinuation(state_ref snap, RawEntityId entity_id,
                     RawEntityId instruction_id)
      : snapshot_(std::move(snap)),
        entity_id_(entity_id),
        instruction_id_(instruction_id) {}

  state_ref snapshot(void) const override { return snapshot_; }

  std::string describe(void) const override { return "global"; }

  // The COMPUTE_GLOBAL_PTR instruction's eid — the result slot resumption fills.
  RawEntityId operand_eid(void) const override { return instruction_id_; }

  // Bind a chosen concrete address as the GLOBAL_PTR instruction result.
  template <typename PolicyT>
  Resumption<ValueT, StatePolicy> resume(PolicyT &policy, uint64_t address) {
    return this->bind_and_clone(policy.make_literal_ptr(address), "global");
  }

  RawEntityId entity_id(void) const { return entity_id_; }
  RawEntityId instruction_id(void) const { return instruction_id_; }

 private:
  state_ref snapshot_;
  RawEntityId entity_id_{kInvalidEntityId};
  RawEntityId instruction_id_{kInvalidEntityId};
};

// ===========================================================================
// MemAddrContinuation<ValueT> — driver must concretize a symbolic address.
//
// Emitted by `Policy::with_address` when the symbolic address cannot be
// resolved to a single concrete pointer. Resumption restores the snapshot
// after recording the chosen address into the cache for the address-eid.
// ===========================================================================

template <typename ValueT, typename StatePolicy = StdShared>
class MemAddrContinuation final : public Continuation<ValueT, StatePolicy> {
 public:
  using state_ref = typename Continuation<ValueT, StatePolicy>::state_ref;

  MemAddrContinuation(state_ref snap, ValueT symbolic_address,
                      RawEntityId address_eid, uint32_t size_bytes,
                      bool is_write)
      : snapshot_(std::move(snap)),
        symbolic_address_(std::move(symbolic_address)),
        address_eid_(address_eid),
        size_bytes_(size_bytes),
        is_write_(is_write) {}

  state_ref snapshot(void) const override { return snapshot_; }

  std::string describe(void) const override {
    return is_write_ ? "store-addr" : "load-addr";
  }

  RawEntityId operand_eid(void) const override { return address_eid_; }

  // Bind the chosen concrete pointer as the address-operand value.
  template <typename PolicyT>
  Resumption<ValueT, StatePolicy> resume(PolicyT &policy,
                                         uint64_t chosen_addr) {
    return this->bind_and_clone(
        policy.make_literal_ptr(chosen_addr),
        "addr");
  }

  const ValueT &symbolic_address(void) const { return symbolic_address_; }
  RawEntityId address_eid(void) const { return address_eid_; }
  uint32_t size_bytes(void) const { return size_bytes_; }
  bool is_write(void) const { return is_write_; }

  // Phase 9: marks suspensions emitted from an indirect-call callee load.
  // Python driver uses this to distinguish function-pointer suspensions from
  // ordinary load suspensions and route them through intercept.indirect_call.
  bool is_call_target(void) const { return is_call_target_; }
  void set_call_target(bool v) { is_call_target_ = v; }

 private:
  state_ref snapshot_;
  ValueT symbolic_address_;
  RawEntityId address_eid_{kInvalidEntityId};
  uint32_t size_bytes_{0};
  bool is_write_{false};
  bool is_call_target_{false};
};

// ===========================================================================
// TerminalResult<ValueT> — the run completed or errored.
// ===========================================================================

enum class TerminalKind : uint8_t {
  COMPLETED,
  ERRORED,
};

template <typename ValueT, typename StatePolicy = StdShared>
struct TerminalResult {
  TerminalKind kind;
  ValueT return_value{};
  ErrorKind error_kind{};
  ref_t<InterpreterState<ValueT, StatePolicy>> snapshot;
};

// ===========================================================================
// StepOutcome<ValueT> — single struct returned by a step.
//
// Replaces the per-scheduler ad-hoc result fields. A scheduler populates
// `continuations` (suspension forks) and at most one `terminal`
// (completed / errored). The loop fills `budget_exhausted` and `steps`
// before returning so callers can read everything from one place.
// ===========================================================================

template <typename ValueT, typename StatePolicy = StdShared>
struct StepOutcome {
  std::vector<std::unique_ptr<Continuation<ValueT, StatePolicy>>> continuations;
  std::optional<TerminalResult<ValueT, StatePolicy>> terminal;
  bool budget_exhausted{false};
  uint64_t steps{0};
};

}  // namespace mx::ir::interpret
