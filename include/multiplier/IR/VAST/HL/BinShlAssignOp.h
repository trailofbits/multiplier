// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Operation.h"

namespace vast::hl {
class BinShlAssignOp;
}  // namespace vast::hl
namespace mx::ir::hl {
class BinShlAssignOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::HL_ASSIGN_BIN_SHL;
  }

  static std::optional<BinShlAssignOp> from(const ::mx::ir::Operation &that);
  static std::optional<BinShlAssignOp> producing(const ::mx::ir::Value &val);

  ::vast::hl::BinShlAssignOp underlying_op(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value src(void) const;
  ::mx::ir::Value dst(void) const;
  ::mx::ir::Value result(void) const;
};
static_assert(sizeof(BinShlAssignOp) == sizeof(Operation));

}  // namespace mx::ir::hl
