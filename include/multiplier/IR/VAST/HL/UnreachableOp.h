// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Operation.h"

namespace vast::hl {
class UnreachableOp;
}  // namespace vast::hl
namespace mx::ir::hl {
class UnreachableOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::HL_UNREACHABLE;
  }

  static std::optional<UnreachableOp> from(const ::mx::ir::Operation &that);
  static std::optional<UnreachableOp> producing(const ::mx::ir::Value &val);

  vast::hl::UnreachableOp underlying_op(void) const noexcept;

  // Imported methods:
};
static_assert(sizeof(UnreachableOp) == sizeof(Operation));

}  // namespace mx::ir::hl
