// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Operation.h"

namespace vast::ll {
class ScopeRecurse;
}  // namespace vast::ll
namespace mx::ir::ll {
class ScopeRecurse final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LL_SCOPE_RECURSE;
  }

  static std::optional<ScopeRecurse> from(const ::mx::ir::Operation &that);
  static std::optional<ScopeRecurse> producing(const ::mx::ir::Value &val);

  vast::ll::ScopeRecurse underlying_op(void) const noexcept;

  // Imported methods:
};
static_assert(sizeof(ScopeRecurse) == sizeof(Operation));

}  // namespace mx::ir::ll