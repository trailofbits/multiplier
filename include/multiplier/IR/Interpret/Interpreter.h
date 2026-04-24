// Copyright (c) 2024-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include "../../Compiler.h"
#include "Value.h"
#include "Suspension.h"
#include <multiplier/IR/Block.h>
#include <multiplier/IR/Function.h>
#include <multiplier/IR/Instruction.h>
#include <multiplier/Types.h>
#include <memory>
#include <optional>
#include <unordered_map>
#include <variant>
#include <vector>

namespace mx {
class IRObject;
class MemoryInst;
}  // namespace mx

namespace mx::ir::interpret {

class ConcretePolicy;

// ---------------------------------------------------------------------------
// ErrorKind — non-sticky error descriptor (lives in Continuation, not state)
// ---------------------------------------------------------------------------

enum class ErrorKind : uint8_t {
  UNREACHABLE,
  EMPTY_STACK,
  NO_TERMINATOR,
};

// ---------------------------------------------------------------------------
// WorkKind — the explicit instruction pointer is a stack of these
//
// Dispatch happens at PUSH time (ENTER_BLOCK, ANALYZE).
// Pop-time handlers (COMPUTE_*, EXEC_*, DECIDE_*) are specific and
// dispatch-free — operands are guaranteed cached.
// ---------------------------------------------------------------------------

enum class WorkKind : uint8_t {
  // Push-time dispatch:
  ENTER_BLOCK,
  ANALYZE,

  // Value computation:
  COMPUTE_CONST,
  COMPUTE_ALLOCA,
  COMPUTE_BINARY,
  COMPUTE_COMPARE,
  COMPUTE_UNARY,
  COMPUTE_CAST,
  COMPUTE_GEP_FIELD,
  COMPUTE_PTR_ADD,
  COMPUTE_PTR_DIFF,
  COMPUTE_SELECT,
  COMPUTE_LAST_VALUE,
  COMPUTE_PARAM_PTR,
  COMPUTE_BITWISE,
  COMPUTE_FLOAT_OP,
  COMPUTE_GLOBAL_PTR,
  COMPUTE_FUNC_PTR,
  COMPUTE_RETURN_PTR,
  COMPUTE_STRING_PTR,
  COMPUTE_UNDEFINED,

  // Side effects:
  EXEC_STORE,
  EXEC_LOAD,
  EXEC_BULK_MEM,
  EXEC_RMW,
  EXEC_CALL,
  EXEC_ENTER_SCOPE,
  EXEC_EXIT_SCOPE,
  EXEC_VA_START,
  EXEC_VA_END,
  EXEC_VA_COPY,
  EXEC_CONSUME_VA_PARAM,

  // Control flow (terminators):
  DECIDE_COND_BRANCH,
  DECIDE_SWITCH,
  EXEC_RET,
  EXEC_GOTO,
  EXEC_UNREACHABLE,
};

struct WorkItem {
  WorkKind kind;
  IRInstruction inst;
  IRBlock block;  // Only meaningful for ENTER_BLOCK.
};

// ---------------------------------------------------------------------------
// CallFrame<ValueT> — per-function-invocation state
// ---------------------------------------------------------------------------

template <typename ValueT>
struct CallFrame {
  IRFunction func;
  std::vector<ValueT> params;
  std::vector<ValueT> param_ptrs;
  ValueT return_ptr{};
  uint32_t variadic_start_index{0};

  // Instruction result cache (transient — cleared per block).
  std::unordered_map<RawEntityId, ValueT> values;

  // CALL return values (persistent — survives across blocks).
  // Keyed by the CALL instruction's entity ID.
  std::unordered_map<RawEntityId, ValueT> call_results;

  // Local variable addresses (per-invocation).
  std::unordered_map<RawEntityId, uint64_t> locals;

  // The CALL instruction EID that this frame was pushed for.
  RawEntityId call_site{kInvalidEntityId};
};

// ---------------------------------------------------------------------------
// CallStack<ValueT> — COW via shared_ptr segments
// ---------------------------------------------------------------------------

template <typename ValueT>
struct CallStackSegment {
  std::vector<CallFrame<ValueT>> frames;
};

template <typename ValueT>
class CallStack {
 public:
  CallStack(void) {
    segments_.push_back(std::make_shared<CallStackSegment<ValueT>>());
  }

  CallFrame<ValueT> &top(void) { return ensure_mutable().frames.back(); }
  const CallFrame<ValueT> &top(void) const {
    return segments_.back()->frames.back();
  }

  void push(CallFrame<ValueT> frame) {
    ensure_mutable().frames.push_back(std::move(frame));
  }

  void pop(void) {
    auto &seg = ensure_mutable();
    seg.frames.pop_back();
    if (seg.frames.empty() && segments_.size() > 1) {
      segments_.pop_back();
    }
  }

  bool empty(void) const {
    for (auto &seg : segments_) {
      if (!seg->frames.empty()) return false;
    }
    return true;
  }

  size_t depth(void) const {
    size_t d = 0;
    for (auto &seg : segments_) d += seg->frames.size();
    return d;
  }

  CallStack fork(void) const { return *this; }

 private:
  std::vector<std::shared_ptr<CallStackSegment<ValueT>>> segments_;

  CallStackSegment<ValueT> &ensure_mutable(void) {
    auto &last = segments_.back();
    if (last.use_count() > 1) {
      last = std::make_shared<CallStackSegment<ValueT>>(*last);
    }
    return *last;
  }
};

// ---------------------------------------------------------------------------
// InterpreterState<ValueT> — pure process state
// ---------------------------------------------------------------------------

template <typename ValueT>
struct InterpreterState {
  CallStack<ValueT> call_stack;
  std::unordered_map<RawEntityId, uint64_t> global_addresses;
  uint64_t steps{0};
  std::vector<WorkItem> work_stack;
};

// ---------------------------------------------------------------------------
// Continuation — a decision point produced by step(), pumped by scheduler
//
// Concrete-only: uses InterpreterState<Value>.
// ---------------------------------------------------------------------------

class MX_EXPORT Continuation {
 public:
  enum Kind : uint8_t { BRANCH, CALL, GLOBAL, COMPLETED, ERRORED };

  static Continuation branch(
      std::shared_ptr<InterpreterState<Value>> snapshot,
      NeedBranchDecision info);
  static Continuation call(
      std::shared_ptr<InterpreterState<Value>> snapshot,
      NeedCallResolution info,
      RawEntityId instruction_id);
  static Continuation global(
      std::shared_ptr<InterpreterState<Value>> snapshot,
      NeedGlobalResolution info,
      RawEntityId instruction_id);
  static Continuation completed(
      Value return_value,
      std::shared_ptr<InterpreterState<Value>> snapshot = {});
  static Continuation errored(
      ErrorKind kind,
      std::shared_ptr<InterpreterState<Value>> snapshot = {});

  Kind kind(void) const { return kind_; }
  bool is_terminal(void) const {
    return kind_ == COMPLETED || kind_ == ERRORED;
  }

  const NeedBranchDecision &as_branch(void) const;
  const NeedCallResolution &as_call(void) const;
  const NeedGlobalResolution &as_global(void) const;
  const Value &return_value(void) const;
  ErrorKind error(void) const;

  const std::shared_ptr<InterpreterState<Value>> &snapshot(void) const {
    return snapshot_;
  }

  InterpreterState<Value> pump(ConcretePolicy &policy,
                               const Resolution &resolution) const;

 private:
  struct BranchData { NeedBranchDecision info; };
  struct CallData { NeedCallResolution info; RawEntityId instruction_id; };
  struct GlobalData { NeedGlobalResolution info; RawEntityId instruction_id; };
  struct CompletedData { Value return_value; };
  struct ErroredData { ErrorKind kind; };

  Kind kind_;
  std::shared_ptr<InterpreterState<Value>> snapshot_;
  std::variant<BranchData, CallData, GlobalData,
               CompletedData, ErroredData> data_;

  Continuation(Kind k, std::shared_ptr<InterpreterState<Value>> snap)
      : kind_(k), snapshot_(std::move(snap)) {}
};

}  // namespace mx::ir::interpret
