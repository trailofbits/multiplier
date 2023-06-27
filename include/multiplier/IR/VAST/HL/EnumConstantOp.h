// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Operation.h"

namespace vast::hl {
class EnumConstantOp;
}  // namespace vast::hl
namespace mx::ir::hl {
class EnumConstantOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::HL_ENUM_CONST;
  }

  static std::optional<EnumConstantOp> from(const ::mx::ir::Operation &that);
  static std::optional<EnumConstantOp> producing(const ::mx::ir::Value &val);

  vast::hl::EnumConstantOp underlying_op(void) const noexcept;

  // Imported methods:
  ::mx::ir::Region init(void) const;
  std::string_view name(void) const;
  //::mlir::TypedAttr value(void) const;
};
static_assert(sizeof(EnumConstantOp) == sizeof(Operation));

}  // namespace mx::ir::hl
