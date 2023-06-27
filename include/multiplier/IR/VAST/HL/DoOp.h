// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Operation.h"

namespace vast::hl {
class DoOp;
}  // namespace vast::hl
namespace mx::ir::hl {
class DoOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::HL_DO;
  }

  static std::optional<DoOp> from(const ::mx::ir::Operation &that);
  static std::optional<DoOp> producing(const ::mx::ir::Value &val);

  vast::hl::DoOp underlying_op(void) const noexcept;

  // Imported methods:
  ::mx::ir::Region body_region(void) const;
  ::mx::ir::Region cond_region(void) const;
};
static_assert(sizeof(DoOp) == sizeof(Operation));

}  // namespace mx::ir::hl
