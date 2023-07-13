// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/IR/VAST/HL/ConstantOp.h>
#include <multiplier/IR/Value.h>

#include <vast/Dialect/Dialects.hpp>
#include <mlir/Dialect/SCF/IR/SCF.h>
#include <mlir/Dialect/LLVMIR/LLVMDialect.h>
#include <vast/Dialect/HighLevel/HighLevelOps.hpp>

namespace mx::ir::hl {
std::optional<ConstantOp> ConstantOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::HL_CONST) {
    return reinterpret_cast<const ConstantOp &>(that);
  }
  return std::nullopt;
}

std::optional<ConstantOp> ConstantOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::vast::hl::ConstantOp ConstantOp::underlying_op(void) const noexcept {
  return ::vast::hl::ConstantOp(this->Operation::op_);
}

}  // namespace mx::ir::hl
