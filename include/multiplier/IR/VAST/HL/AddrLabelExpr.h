// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Operation.h"

namespace vast::hl {
class AddrLabelExpr;
}  // namespace vast::hl
namespace mx::ir::hl {
class AddrLabelExpr final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::HL_LABELADDR;
  }

  static std::optional<AddrLabelExpr> from(const ::mx::ir::Operation &that);
  static std::optional<AddrLabelExpr> producing(const ::mx::ir::Value &val);

  vast::hl::AddrLabelExpr underlying_op(void) const noexcept;

  // Imported methods:
  //::mlir::TypedValue<::vast::hl::LabelType> label(void) const;
  ::mx::ir::Value result(void) const;
};
static_assert(sizeof(AddrLabelExpr) == sizeof(Operation));

}  // namespace mx::ir::hl
