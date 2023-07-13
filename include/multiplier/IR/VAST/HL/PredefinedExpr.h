// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Operation.h"

namespace vast::hl {
class PredefinedExpr;
}  // namespace vast::hl
namespace mx::ir::hl {
class PredefinedExpr final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::HL_PREDEFINED_EXPR;
  }

  static std::optional<PredefinedExpr> from(const ::mx::ir::Operation &that);
  static std::optional<PredefinedExpr> producing(const ::mx::ir::Value &val);

  ::vast::hl::PredefinedExpr underlying_op(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value value(void) const;
  ::mx::ir::Value result(void) const;
  //::vast::hl::IdentKind kind(void) const;
};
static_assert(sizeof(PredefinedExpr) == sizeof(Operation));

}  // namespace mx::ir::hl
