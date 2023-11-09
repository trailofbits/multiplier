// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/IR/VAST/HL/InitListExpr.h>
#include <multiplier/IR/Attribute.h>
#include <multiplier/IR/Block.h>
#include <multiplier/IR/Region.h>
#include <multiplier/IR/Type.h>

#include <mlir/Dialect/SCF/IR/SCF.h>
#include <mlir/Dialect/LLVMIR/LLVMDialect.h>
#include <vast/Dialect/Dialects.hpp>
#include <vast/Dialect/HighLevel/HighLevelOps.hpp>

namespace mx::ir::hl {
std::optional<InitListExpr> InitListExpr::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::HL_INITLIST) {
    return reinterpret_cast<const InitListExpr &>(that);
  }
  return std::nullopt;
}

std::optional<InitListExpr> InitListExpr::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::vast::hl::InitListExpr InitListExpr::underlying_op(void) const noexcept {
  return ::vast::hl::InitListExpr(this->Operation::op_);
}

gap::generator<::mx::ir::Operand> InitListExpr::elements(void) const {
  auto range = underlying_op().getElements();
  for (auto val : range) {
    co_yield ::mx::ir::Operand(module_, val.getAsOpaquePointer());
  }
}

}  // namespace mx::ir::hl
