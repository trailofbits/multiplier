// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Operation.h"

namespace vast::hl {
class InitListExpr;
}  // namespace vast::hl
namespace mx::ir::hl {
class InitListExpr final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::HL_INITLIST;
  }

  static std::optional<InitListExpr> from(const ::mx::ir::Operation &that);
  static std::optional<InitListExpr> producing(const ::mx::ir::Value &val);

  vast::hl::InitListExpr underlying_op(void) const noexcept;

  // Imported methods:
  //::mlir::Operation::operand_range elements(void) const;
};
static_assert(sizeof(InitListExpr) == sizeof(Operation));

}  // namespace mx::ir::hl
