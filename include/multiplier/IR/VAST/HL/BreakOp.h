// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Operation.h"

namespace vast::hl {
class BreakOp;
}  // namespace vast::hl
namespace mx::ir::hl {
class BreakOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::HL_BREAK;
  }

  static std::optional<BreakOp> from(const ::mx::ir::Operation &that);
  static std::optional<BreakOp> producing(const ::mx::ir::Value &val);

  ::vast::hl::BreakOp underlying_op(void) const noexcept;

  // Imported methods:
};
static_assert(sizeof(BreakOp) == sizeof(Operation));

}  // namespace mx::ir::hl
