// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Operation.h"

namespace vast::hl {
class LabelStmt;
}  // namespace vast::hl
namespace mx::ir::hl {
class LabelStmt final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::HL_LABEL;
  }

  static std::optional<LabelStmt> from(const ::mx::ir::Operation &that);
  static std::optional<LabelStmt> producing(const ::mx::ir::Value &val);

  ::vast::hl::LabelStmt underlying_op(void) const noexcept;

  // Imported methods:
  //::mlir::TypedValue<::vast::hl::LabelType> label(void) const;
  ::mx::ir::Region body(void) const;
};
static_assert(sizeof(LabelStmt) == sizeof(Operation));

}  // namespace mx::ir::hl
