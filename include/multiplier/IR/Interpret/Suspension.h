// Copyright (c) 2024-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include "Value.h"
#include <multiplier/IR/Block.h>
#include <multiplier/IR/Instruction.h>
#include <variant>
#include <vector>

namespace mx {
class FunctionDecl;
}

namespace mx::ir::interpret {

// The interpreter yields Suspensions at decision points.
// A Driver returns Resolutions to continue execution.

// Branch with unknown (symbolic) condition.
struct BranchSuspension {
  Value condition;
  IRBlock true_block;
  IRBlock false_block;
};

struct BranchResolution {
  bool take_true{true};
  bool take_false{false};  // true = fork both paths
};

// Function call — driver decides: inline, skip, or model.
struct CallSuspension {
  IRInstruction call_inst;
  std::optional<FunctionDecl> target;
  std::vector<Value> arguments;
  bool is_indirect{false};
};

enum class CallAction {
  INLINE,    // Step into the callee's IR.
  SKIP,      // Return a default/symbolic value.
  MODEL,     // Driver provides the return value.
};

struct CallResolution {
  CallAction action{CallAction::SKIP};
  Value return_value;  // For SKIP/MODEL.
};

// Load from a symbolic or unknown address.
struct LoadSuspension {
  Value address;
  uint32_t size_bytes{0};
};

struct LoadResolution {
  Value value;
};

// Store to a symbolic or unknown address.
struct StoreSuspension {
  Value address;
  Value value;
  uint32_t size_bytes{0};
};

struct StoreResolution {
  bool proceed{true};
};

// Need to concretize a symbolic value.
struct ConcretizeSuspension {
  Value symbolic_value;
};

struct ConcretizeResolution {
  Value concrete_value;
};

// Union of all suspension types.
using Suspension = std::variant<
    BranchSuspension,
    CallSuspension,
    LoadSuspension,
    StoreSuspension,
    ConcretizeSuspension
>;

// Union of all resolution types.
using Resolution = std::variant<
    BranchResolution,
    CallResolution,
    LoadResolution,
    StoreResolution,
    ConcretizeResolution
>;

}  // namespace mx::ir::interpret
