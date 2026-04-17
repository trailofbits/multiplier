// Copyright (c) 2024-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include "Value.h"
#include <multiplier/IR/Block.h>
#include <multiplier/IR/Function.h>
#include <multiplier/IR/Instruction.h>
#include <multiplier/Types.h>
#include <variant>
#include <vector>

namespace mx::ir::interpret {

// ---------------------------------------------------------------------------
// Suspensions — what the interpreter needs before it can continue
// ---------------------------------------------------------------------------

// The interpreter can't resolve a branch condition.
// The driver must decide which path(s) to take.
struct NeedBranchDecision {
  Value condition;
  IRBlock true_block;
  IRBlock false_block;
};

// The interpreter encountered a CALL but doesn't have the callee's IR.
// The driver must provide the IRFunction (inline), a modeled return value,
// or indicate the call should be skipped.
struct NeedCallResolution {
  IRInstruction call_inst;
  RawEntityId target_eid{kInvalidEntityId};
  RawEntityId indirect_target_eid{kInvalidEntityId};
  std::vector<Value> arguments;
  bool is_indirect{false};
};

// The interpreter encountered a GLOBAL_PTR for an unresolved global.
// The driver must provide the global's size, alignment, and optional
// initializer function.
struct NeedGlobalResolution {
  RawEntityId entity_id{kInvalidEntityId};
};

// A pointer operand needed to be concrete but wasn't.
// The driver must concretize or provide the concrete address.
struct NeedConcretePointer {
  IRInstruction inst;
  Value symbolic_pointer;
};

// ---------------------------------------------------------------------------
// Resolutions — what the driver provides to resume
// ---------------------------------------------------------------------------

struct BranchDecision {
  bool take_true{true};
  bool take_false{false};  // true = fork both paths.
};

enum class CallAction {
  INLINE,
  SKIP,
  MODEL,
};

struct CallResolution {
  CallAction action{CallAction::SKIP};
  Value return_value;
  IRFunction callee_ir;  // For INLINE.
};

// Info about a global variable needed for lazy initialization.
struct GlobalInfo {
  RawEntityId canonical_eid{kInvalidEntityId};
  uint32_t size{0};
  uint32_t align{8};
  std::optional<IRFunction> initializer;
};

struct GlobalResolution {
  GlobalInfo info;
};

struct ConcretePointerResolution {
  uint64_t address{0};
};

// ---------------------------------------------------------------------------
// Variant unions
// ---------------------------------------------------------------------------

using Suspension = std::variant<
    NeedBranchDecision,
    NeedCallResolution,
    NeedGlobalResolution,
    NeedConcretePointer
>;

using Resolution = std::variant<
    BranchDecision,
    CallResolution,
    GlobalResolution,
    ConcretePointerResolution
>;

}  // namespace mx::ir::interpret
