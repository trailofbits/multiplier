// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Operation.h"

namespace vast::core {
class ScopeOp;
}  // namespace vast::core
namespace mx::ir::core {
class ScopeOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::CORE_SCOPE;
  }

  static std::optional<ScopeOp> from(const ::mx::ir::Operation &that);
  static std::optional<ScopeOp> producing(const ::mx::ir::Value &val);

  ::vast::core::ScopeOp underlying_op(void) const noexcept;

  // Imported methods:
  ::mx::ir::Region body(void) const;
};
static_assert(sizeof(ScopeOp) == sizeof(Operation));

}  // namespace mx::ir::core
