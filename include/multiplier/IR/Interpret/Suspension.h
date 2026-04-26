// Copyright (c) 2024-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.
//
// Resolution payload types used by Policy::resolve_call / resolve_global.
// (The variant-based suspension/resolution shapes have been replaced by
// the polymorphic Continuation hierarchy in Continuation.h.)

#pragma once

#include "Value.h"

#include <multiplier/IR/Function.h>
#include <multiplier/Types.h>

#include <cstdint>
#include <optional>

namespace mx::ir::interpret {

enum class CallAction : uint8_t {
  INLINE,
  SKIP,
  MODEL,
};

template <typename ValueT = Value>
struct CallResolution {
  CallAction action{CallAction::SKIP};
  ValueT return_value;
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

}  // namespace mx::ir::interpret
