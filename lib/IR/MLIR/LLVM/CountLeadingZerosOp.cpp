// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/IR/MLIR/LLVM/CountLeadingZerosOp.h>
#include <multiplier/IR/Attribute.h>
#include <multiplier/IR/Block.h>
#include <multiplier/IR/Region.h>
#include <multiplier/IR/Type.h>

#include <mlir/Dialect/SCF/IR/SCF.h>
#include <mlir/Dialect/LLVMIR/LLVMDialect.h>

namespace mx::ir::llvm {
std::optional<CountLeadingZerosOp> CountLeadingZerosOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_CTLZ) {
    return reinterpret_cast<const CountLeadingZerosOp &>(that);
  }
  return std::nullopt;
}

std::optional<CountLeadingZerosOp> CountLeadingZerosOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::CountLeadingZerosOp CountLeadingZerosOp::underlying_op(void) const noexcept {
  return ::mlir::LLVM::CountLeadingZerosOp(this->Operation::op_);
}

::mx::ir::Value CountLeadingZerosOp::in(void) const {
  auto val = underlying_op().getIn();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value CountLeadingZerosOp::res(void) const {
  auto val = underlying_op().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

bool CountLeadingZerosOp::is_zero_poison(void) const {
  auto val = underlying_op().getIsZeroPoison();
  return val;
}

}  // namespace mx::ir::llvm
