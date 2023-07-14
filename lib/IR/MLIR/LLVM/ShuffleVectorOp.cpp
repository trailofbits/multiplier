// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/IR/MLIR/LLVM/ShuffleVectorOp.h>
#include <multiplier/IR/Attribute.h>
#include <multiplier/IR/Block.h>
#include <multiplier/IR/Region.h>
#include <multiplier/IR/Type.h>

#include <vast/Dialect/HighLevel/HighLevelOps.hpp>
#include <vast/Dialect/Dialects.hpp>
#include <mlir/Dialect/SCF/IR/SCF.h>
#include <mlir/Dialect/LLVMIR/LLVMDialect.h>

namespace mx::ir::llvm {
std::optional<ShuffleVectorOp> ShuffleVectorOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_SHUFFLEVECTOR) {
    return reinterpret_cast<const ShuffleVectorOp &>(that);
  }
  return std::nullopt;
}

std::optional<ShuffleVectorOp> ShuffleVectorOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::ShuffleVectorOp ShuffleVectorOp::underlying_op(void) const noexcept {
  return ::mlir::LLVM::ShuffleVectorOp(this->Operation::op_);
}

::mx::ir::Value ShuffleVectorOp::v1(void) const {
  auto val = underlying_op().getV1();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value ShuffleVectorOp::v2(void) const {
  auto val = underlying_op().getV2();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value ShuffleVectorOp::res(void) const {
  auto val = underlying_op().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

}  // namespace mx::ir::llvm
