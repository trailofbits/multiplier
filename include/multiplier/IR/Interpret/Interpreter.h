// Copyright (c) 2024-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include "../../Compiler.h"
#include "Sharable.h"
#include "Value.h"
#include <multiplier/IR/Block.h>
#include <multiplier/IR/Function.h>
#include <multiplier/IR/Instruction.h>
#include <multiplier/Types.h>
#include <memory>
#include <unordered_map>
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
  COMPUTE_LOGICAL,
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
struct CallStackSegment
    : public Sharable<CallStackSegment<ValueT>, StdShared> {
  std::vector<CallFrame<ValueT>> frames;
};

template <typename ValueT>
class CallStack {
 public:
  CallStack(void) {
    segments_.push_back(make_sharable<CallStackSegment<ValueT>>());
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
      last = make_sharable<CallStackSegment<ValueT>>(*last);
    }
    return *last;
  }
};

// ---------------------------------------------------------------------------
// InterpreterState<ValueT, Policy> — pure process state.
//
// `Policy` selects the ref-count system: `StdShared` (default) keeps the
// state behind `std::shared_ptr`; `PyObjectRC` wraps it in a PyObject so
// Python can hold references with normal refcount semantics.
// ---------------------------------------------------------------------------

template <typename ValueT, typename Policy = StdShared>
struct InterpreterState
    : public Sharable<InterpreterState<ValueT, Policy>, Policy> {
  using value_type = ValueT;
  using policy_type = Policy;

  CallStack<ValueT> call_stack;
  std::unordered_map<RawEntityId, uint64_t> global_addresses;
  // Phase 9: state-level cache for function pointer addresses. Mirrors
  // `global_addresses` in role: once a function eid is bound to an
  // address, subsequent FUNC_PTR references reuse it across frames.
  std::unordered_map<RawEntityId, uint64_t> function_addresses;
  uint64_t steps{0};
  std::vector<WorkItem> work_stack;

  // The work item currently being dispatched. Set by interp_step before
  // each `dispatch(item)`. Suspension-capable policy hooks (e.g.
  // `with_address`) read this to re-push the in-flight work item onto
  // a snapshot's work_stack so resumption retries the same op.
  WorkItem current_item{};

  // Allocate a fresh ref-counted clone, using the same Policy.
  ref_t<InterpreterState<ValueT, Policy>> clone(void) const {
    return make_sharable<InterpreterState<ValueT, Policy>>(*this);
  }
};

}  // namespace mx::ir::interpret
