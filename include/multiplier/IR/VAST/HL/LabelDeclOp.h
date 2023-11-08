// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Operation.h"

namespace vast::hl {
class LabelDeclOp;
}  // namespace vast::hl
namespace mx::ir::hl {
class LabelDeclOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::HL_LABEL_DECL;
  }

  static std::optional<LabelDeclOp> from(const ::mx::ir::Operation &that);
  static std::optional<LabelDeclOp> producing(const ::mx::ir::Value &val);

  ::vast::hl::LabelDeclOp underlying_op(void) const noexcept;

  // Imported methods:
  //::mlir::TypedValue<::vast::hl::LabelType> result(void) const;
  std::string_view name(void) const;
};
static_assert(sizeof(LabelDeclOp) == sizeof(Operation));

}  // namespace mx::ir::hl
