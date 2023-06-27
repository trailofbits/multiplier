// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/IR/VAST/HL/MulIAssignOp.h>
#include <multiplier/IR/Value.h>

namespace mx::ir::hl {
std::optional<MulIAssignOp> MulIAssignOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::HL_ASSIGN_MUL) {
    return reinterpret_cast<const MulIAssignOp &>(that);
  }
  return std::nullopt;
}

std::optional<MulIAssignOp> MulIAssignOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

}  // namespace mx::ir::hl
