// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/IR/MLIR/LLVM/SelectOp.h>
#include <multiplier/IR/Attribute.h>
#include <multiplier/IR/Block.h>
#include <multiplier/IR/Region.h>
#include <multiplier/IR/Type.h>

#include <vast/Dialect/HighLevel/HighLevelOps.hpp>
#include <vast/Dialect/Dialects.hpp>
#include <mlir/Dialect/SCF/IR/SCF.h>
#include <mlir/Dialect/LLVMIR/LLVMDialect.h>

namespace mx::ir::llvm {
std::optional<SelectOp> SelectOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_SELECT) {
    return reinterpret_cast<const SelectOp &>(that);
  }
  return std::nullopt;
}

std::optional<SelectOp> SelectOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::SelectOp SelectOp::underlying_op(void) const noexcept {
  return ::mlir::LLVM::SelectOp(this->Operation::op_);
}

::mx::ir::Value SelectOp::condition(void) const {
  auto val = underlying_op().getCondition();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value SelectOp::true_value(void) const {
  auto val = underlying_op().getTrueValue();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value SelectOp::false_value(void) const {
  auto val = underlying_op().getFalseValue();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value SelectOp::res(void) const {
  auto val = underlying_op().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

}  // namespace mx::ir::llvm
