// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/IR/MLIR/LLVM/masked_scatter.h>
#include <multiplier/IR/Attribute.h>
#include <multiplier/IR/Block.h>
#include <multiplier/IR/Region.h>
#include <multiplier/IR/Type.h>

#include <mlir/Dialect/SCF/IR/SCF.h>
#include <mlir/Dialect/LLVMIR/LLVMDialect.h>

namespace mx::ir::llvm {
std::optional<masked_scatter> masked_scatter::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_MASKED_SCATTER) {
    return reinterpret_cast<const masked_scatter &>(that);
  }
  return std::nullopt;
}

std::optional<masked_scatter> masked_scatter::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::masked_scatter masked_scatter::underlying_op(void) const noexcept {
  return ::mlir::LLVM::masked_scatter(this->Operation::op_);
}

::mx::ir::Value masked_scatter::value(void) const {
  auto val = underlying_op().getValue();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value masked_scatter::ptrs(void) const {
  auto val = underlying_op().getPtrs();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value masked_scatter::mask(void) const {
  auto val = underlying_op().getMask();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

uint32_t masked_scatter::alignment(void) const {
  auto val = underlying_op().getAlignment();
  return val;
}

}  // namespace mx::ir::llvm
