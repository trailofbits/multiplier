// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/IR/MLIR/MemRef/DmaStartOp.h>
#include <multiplier/IR/Attribute.h>
#include <multiplier/IR/Block.h>
#include <multiplier/IR/Region.h>
#include <multiplier/IR/Type.h>

#include <vast/Dialect/HighLevel/HighLevelOps.hpp>
#include <vast/Dialect/Dialects.hpp>
#include <mlir/Dialect/SCF/IR/SCF.h>
#include <mlir/Dialect/LLVMIR/LLVMDialect.h>
#include <mlir/Dialect/MemRef/IR/MemRef.h>

namespace mx::ir::memref {
std::optional<DmaStartOp> DmaStartOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::MEMREF_DMA_START) {
    return reinterpret_cast<const DmaStartOp &>(that);
  }
  return std::nullopt;
}

std::optional<DmaStartOp> DmaStartOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::memref::DmaStartOp DmaStartOp::underlying_op(void) const noexcept {
  return ::mlir::memref::DmaStartOp(this->Operation::op_);
}

gap::generator<::mx::ir::Operand> DmaStartOp::operands(void) const {
  auto range = underlying_op().getOperands();
  for (auto val : range) {
    co_yield ::mx::ir::Operand(module_, val.getAsOpaquePointer());
  }
}

bool DmaStartOp::is_dest_memory_space_faster(void) const {
  auto val = underlying_op().isDestMemorySpaceFaster();
  return val;
}

bool DmaStartOp::is_src_memory_space_faster(void) const {
  auto val = underlying_op().isSrcMemorySpaceFaster();
  return val;
}

bool DmaStartOp::is_strided(void) const {
  auto val = underlying_op().isStrided();
  return val;
}

}  // namespace mx::ir::memref
