// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Operation.h"

namespace vast::hl {
class GotoStmt;
}  // namespace vast::hl
namespace mx::ir::hl {
class GotoStmt final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::HL_GOTO;
  }

  static std::optional<GotoStmt> from(const ::mx::ir::Operation &that);
  static std::optional<GotoStmt> producing(const ::mx::ir::Value &val);

  vast::hl::GotoStmt underlying_op(void) const noexcept;

  // Imported methods:
  //::mlir::TypedValue<::vast::hl::LabelType> label(void) const;
};
static_assert(sizeof(GotoStmt) == sizeof(Operation));

}  // namespace mx::ir::hl
