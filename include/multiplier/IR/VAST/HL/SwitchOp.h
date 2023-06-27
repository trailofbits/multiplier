// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Operation.h"

namespace vast::hl {
class SwitchOp;
}  // namespace vast::hl
namespace mx::ir::hl {
class SwitchOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::HL_SWITCH;
  }

  static std::optional<SwitchOp> from(const ::mx::ir::Operation &that);
  static std::optional<SwitchOp> producing(const ::mx::ir::Value &val);

  vast::hl::SwitchOp underlying_op(void) const noexcept;

  // Imported methods:
  ::mx::ir::Region cond_region(void) const;
  //::mlir::MutableArrayRef<::mlir::Region> cases(void) const;
};
static_assert(sizeof(SwitchOp) == sizeof(Operation));

}  // namespace mx::ir::hl
