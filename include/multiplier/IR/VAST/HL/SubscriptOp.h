// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Operation.h"

namespace vast::hl {
class SubscriptOp;
}  // namespace vast::hl
namespace mx::ir::hl {
class SubscriptOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::HL_SUBSCRIPT;
  }

  static std::optional<SubscriptOp> from(const ::mx::ir::Operation &that);
  static std::optional<SubscriptOp> producing(const ::mx::ir::Value &val);

  vast::hl::SubscriptOp underlying_op(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value array(void) const;
  ::mx::ir::Value index(void) const;
  ::mx::ir::Value result(void) const;
};
static_assert(sizeof(SubscriptOp) == sizeof(Operation));

}  // namespace mx::ir::hl
