// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Operation.h"

namespace vast::hl {
class TypeOfTypeOp;
}  // namespace vast::hl
namespace mx::ir::hl {
class TypeOfTypeOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::HL_TYPEOF_TYPE;
  }

  static std::optional<TypeOfTypeOp> from(const ::mx::ir::Operation &that);
  static std::optional<TypeOfTypeOp> producing(const ::mx::ir::Value &val);

  ::vast::hl::TypeOfTypeOp underlying_op(void) const noexcept;

  // Imported methods:
  //::mlir::Type type(void) const;
};
static_assert(sizeof(TypeOfTypeOp) == sizeof(Operation));

}  // namespace mx::ir::hl
