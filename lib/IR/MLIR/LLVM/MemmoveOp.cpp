// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/IR/MLIR/LLVM/MemmoveOp.h>
#include <multiplier/IR/Attribute.h>
#include <multiplier/IR/Block.h>
#include <multiplier/IR/Region.h>
#include <multiplier/IR/Type.h>

#include <mlir/Dialect/SCF/IR/SCF.h>
#include <mlir/Dialect/LLVMIR/LLVMDialect.h>

namespace mx::ir::llvm {
std::optional<MemmoveOp> MemmoveOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_MEMMOVE) {
    return reinterpret_cast<const MemmoveOp &>(that);
  }
  return std::nullopt;
}

std::optional<MemmoveOp> MemmoveOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::MemmoveOp MemmoveOp::underlying_op(void) const noexcept {
  return ::mlir::LLVM::MemmoveOp(this->Operation::op_);
}

bool MemmoveOp::is_volatile(void) const {
  auto val = underlying_op().getIsVolatile();
  return val;
}

}  // namespace mx::ir::llvm
