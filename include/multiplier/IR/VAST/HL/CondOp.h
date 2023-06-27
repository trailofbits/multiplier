// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Operation.h"

namespace vast::hl {
class CondOp;
}  // namespace vast::hl
namespace mx::ir::hl {
class CondOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::HL_COND;
  }

  static std::optional<CondOp> from(const ::mx::ir::Operation &that);
  static std::optional<CondOp> producing(const ::mx::ir::Value &val);

  vast::hl::CondOp underlying_op(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value result(void) const;
  ::mx::ir::Region cond_region(void) const;
  ::mx::ir::Region then_region(void) const;
  ::mx::ir::Region else_region(void) const;
};
static_assert(sizeof(CondOp) == sizeof(Operation));

}  // namespace mx::ir::hl
