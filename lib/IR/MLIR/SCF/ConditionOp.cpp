// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/IR/MLIR/SCF/ConditionOp.h>
#include <multiplier/IR/Attribute.h>
#include <multiplier/IR/Block.h>
#include <multiplier/IR/Region.h>
#include <multiplier/IR/Type.h>

#include <mlir/Dialect/MemRef/IR/MemRef.h>
#include <mlir/Dialect/LLVMIR/LLVMDialect.h>
#include <mlir/Dialect/SCF/IR/SCF.h>

namespace mx::ir::scf {
std::optional<ConditionOp> ConditionOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::SCF_CONDITION) {
    return reinterpret_cast<const ConditionOp &>(that);
  }
  return std::nullopt;
}

std::optional<ConditionOp> ConditionOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::scf::ConditionOp ConditionOp::underlying_op(void) const noexcept {
  return ::mlir::scf::ConditionOp(this->Operation::op_);
}

gap::generator<::mx::ir::Operand> ConditionOp::args(void) const {
  auto range = underlying_op().getArgs();
  for (auto val : range) {
    co_yield ::mx::ir::Operand(module_, val.getAsOpaquePointer());
  }
}

}  // namespace mx::ir::scf
