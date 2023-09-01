// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/IR/MLIR/MemRef/DmaWaitOp.h>
#include <multiplier/IR/Attribute.h>
#include <multiplier/IR/Block.h>
#include <multiplier/IR/Region.h>
#include <multiplier/IR/Type.h>

#include <mlir/Dialect/SCF/IR/SCF.h>
#include <mlir/Dialect/LLVMIR/LLVMDialect.h>
#include <mlir/Dialect/MemRef/IR/MemRef.h>

namespace mx::ir::memref {
std::optional<DmaWaitOp> DmaWaitOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::MEMREF_DMA_WAIT) {
    return reinterpret_cast<const DmaWaitOp &>(that);
  }
  return std::nullopt;
}

std::optional<DmaWaitOp> DmaWaitOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::memref::DmaWaitOp DmaWaitOp::underlying_op(void) const noexcept {
  return ::mlir::memref::DmaWaitOp(this->Operation::op_);
}

gap::generator<::mx::ir::Operand> DmaWaitOp::tag_indices(void) const {
  auto range = underlying_op().getTagIndices();
  for (auto val : range) {
    co_yield ::mx::ir::Operand(module_, val.getAsOpaquePointer());
  }
}

}  // namespace mx::ir::memref
