// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Operation.h"

namespace vast::hl {
class SkipStmt;
}  // namespace vast::hl
namespace mx::ir::hl {
class SkipStmt final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::HL_SKIP;
  }

  static std::optional<SkipStmt> from(const ::mx::ir::Operation &that);
  static std::optional<SkipStmt> producing(const ::mx::ir::Value &val);

  vast::hl::SkipStmt underlying_op(void) const noexcept;

  // Imported methods:
};
static_assert(sizeof(SkipStmt) == sizeof(Operation));

}  // namespace mx::ir::hl
