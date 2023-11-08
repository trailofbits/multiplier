// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Operation.h"

namespace vast::hl {
class TypeOfExprOp;
}  // namespace vast::hl
namespace mx::ir::hl {
class TypeOfExprOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::HL_TYPEOF_EXPR;
  }

  static std::optional<TypeOfExprOp> from(const ::mx::ir::Operation &that);
  static std::optional<TypeOfExprOp> producing(const ::mx::ir::Value &val);

  ::vast::hl::TypeOfExprOp underlying_op(void) const noexcept;

  // Imported methods:
  ::mx::ir::Region expr(void) const;
  std::string_view name(void) const;
  //::mlir::Type type(void) const;
};
static_assert(sizeof(TypeOfExprOp) == sizeof(Operation));

}  // namespace mx::ir::hl
