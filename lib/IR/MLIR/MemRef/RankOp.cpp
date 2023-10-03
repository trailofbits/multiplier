// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/IR/MLIR/MemRef/RankOp.h>
#include <multiplier/IR/Attribute.h>
#include <multiplier/IR/Block.h>
#include <multiplier/IR/Region.h>
#include <multiplier/IR/Type.h>

#include <mlir/Dialect/SCF/IR/SCF.h>
#include <mlir/Dialect/LLVMIR/LLVMDialect.h>
#include <mlir/Dialect/MemRef/IR/MemRef.h>

namespace mx::ir::memref {
std::optional<RankOp> RankOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::MEMREF_RANK) {
    return reinterpret_cast<const RankOp &>(that);
  }
  return std::nullopt;
}

std::optional<RankOp> RankOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::memref::RankOp RankOp::underlying_op(void) const noexcept {
  return ::mlir::memref::RankOp(this->Operation::op_);
}

::mx::ir::Value RankOp::memref(void) const {
  auto val = underlying_op().getMemref();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

}  // namespace mx::ir::memref
