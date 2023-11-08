// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Operation.h"

namespace vast::hl {
class AlignOfExprOp;
}  // namespace vast::hl
namespace mx::ir::hl {
class AlignOfExprOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::HL_ALIGNOF_EXPR;
  }

  static std::optional<AlignOfExprOp> from(const ::mx::ir::Operation &that);
  static std::optional<AlignOfExprOp> producing(const ::mx::ir::Value &val);

  ::vast::hl::AlignOfExprOp underlying_op(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value result(void) const;
  ::mx::ir::Region expr(void) const;
};
static_assert(sizeof(AlignOfExprOp) == sizeof(Operation));

}  // namespace mx::ir::hl
