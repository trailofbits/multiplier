// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/IR/VAST/HL/CondYieldOp.h>
#include <multiplier/IR/Value.h>

#include <vast/Dialect/Dialects.hpp>
#include <mlir/Dialect/SCF/IR/SCF.h>
#include <mlir/Dialect/LLVMIR/LLVMDialect.h>
#include <vast/Dialect/HighLevel/HighLevelOps.hpp>

namespace mx::ir::hl {
std::optional<CondYieldOp> CondYieldOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::HL_COND_YIELD) {
    return reinterpret_cast<const CondYieldOp &>(that);
  }
  return std::nullopt;
}

std::optional<CondYieldOp> CondYieldOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::vast::hl::CondYieldOp CondYieldOp::underlying_op(void) const noexcept {
  return ::vast::hl::CondYieldOp(this->Operation::op_);
}

}  // namespace mx::ir::hl
