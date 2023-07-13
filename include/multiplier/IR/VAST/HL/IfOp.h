// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Operation.h"

namespace vast::hl {
class IfOp;
}  // namespace vast::hl
namespace mx::ir::hl {
class IfOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::HL_IF;
  }

  static std::optional<IfOp> from(const ::mx::ir::Operation &that);
  static std::optional<IfOp> producing(const ::mx::ir::Value &val);

  ::vast::hl::IfOp underlying_op(void) const noexcept;

  // Imported methods:
  ::mx::ir::Region cond_region(void) const;
  ::mx::ir::Region then_region(void) const;
  ::mx::ir::Region else_region(void) const;
  bool has_else(void) const;
};
static_assert(sizeof(IfOp) == sizeof(Operation));

}  // namespace mx::ir::hl
