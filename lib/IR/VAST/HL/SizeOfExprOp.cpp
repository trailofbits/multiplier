// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/IR/VAST/HL/SizeOfExprOp.h>
#include <multiplier/IR/Attribute.h>
#include <multiplier/IR/Block.h>
#include <multiplier/IR/Region.h>
#include <multiplier/IR/Type.h>

#include <mlir/Dialect/SCF/IR/SCF.h>
#include <mlir/Dialect/LLVMIR/LLVMDialect.h>
#include <vast/Dialect/Dialects.hpp>
#include <vast/Dialect/HighLevel/HighLevelOps.hpp>

namespace mx::ir::hl {
std::optional<SizeOfExprOp> SizeOfExprOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::HL_SIZEOF_EXPR) {
    return reinterpret_cast<const SizeOfExprOp &>(that);
  }
  return std::nullopt;
}

std::optional<SizeOfExprOp> SizeOfExprOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::vast::hl::SizeOfExprOp SizeOfExprOp::underlying_op(void) const noexcept {
  return ::vast::hl::SizeOfExprOp(this->Operation::op_);
}

::mx::ir::Value SizeOfExprOp::result(void) const {
  auto val = underlying_op().getResult();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Region SizeOfExprOp::expr(void) const {
  auto &val = underlying_op().getExpr();
  return ::mx::ir::Region(module_, val);
}

}  // namespace mx::ir::hl
