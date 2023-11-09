// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/IR/MLIR/SCF/YieldOp.h>
#include <multiplier/IR/Attribute.h>
#include <multiplier/IR/Block.h>
#include <multiplier/IR/Region.h>
#include <multiplier/IR/Type.h>

#include <mlir/Dialect/SCF/IR/SCF.h>

namespace mx::ir::scf {
std::optional<YieldOp> YieldOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::SCF_YIELD) {
    return reinterpret_cast<const YieldOp &>(that);
  }
  return std::nullopt;
}

std::optional<YieldOp> YieldOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::scf::YieldOp YieldOp::underlying_op(void) const noexcept {
  return ::mlir::scf::YieldOp(this->Operation::op_);
}

gap::generator<::mx::ir::Operand> YieldOp::results(void) const {
  auto range = underlying_op().getResults();
  for (auto val : range) {
    co_yield ::mx::ir::Operand(module_, val.getAsOpaquePointer());
  }
}

}  // namespace mx::ir::scf
