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
};

template <typename ValueT = Value>
struct CallResolution {
  CallAction action{CallAction::SKIP};
  ValueT return_value;
  IRFunction callee_ir;  // For INLINE.
};

// Phase 9: address-resolution kinds. A Phase-9 address-for callback
// surfaces the kind so the analyst can filter (e.g. only fire on TLS
// placements, only fire on functions). The substrate itself sees only
// GLOBAL / FUNCTION; the Python layer maps a thread-local global to
// THREAD_LOCAL based on the entity's declaration before consulting
// the intercept chain.
enum class AddressKind : uint8_t {
  GLOBAL = 0,
  FUNCTION = 1,
  THREAD_LOCAL = 2,
};

// Info about a global variable needed for lazy initialization.
//
// `address_hint`: Phase 9 — when set, the interpreter uses this address
// instead of `mem_allocate`. The address is reserved via
// `ConcreteMemory::place_at(...)` on first reference and cached in
// `state.global_addresses`.
struct GlobalInfo {
  RawEntityId canonical_eid{kInvalidEntityId};
  uint32_t size{0};
  uint32_t align{8};
  std::optional<IRFunction> initializer;
  std::optional<uint64_t> address_hint;
};

struct GlobalResolution {
  GlobalInfo info;
};

}  // namespace mx::ir::interpret
