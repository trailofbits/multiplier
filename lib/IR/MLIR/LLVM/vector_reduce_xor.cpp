// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/IR/MLIR/LLVM/vector_reduce_xor.h>
#include <multiplier/IR/Attribute.h>
#include <multiplier/IR/Block.h>
#include <multiplier/IR/Region.h>
#include <multiplier/IR/Type.h>

#include <mlir/Dialect/SCF/IR/SCF.h>
#include <mlir/Dialect/LLVMIR/LLVMDialect.h>

namespace mx::ir::llvm {
std::optional<vector_reduce_xor> vector_reduce_xor::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_VECTOR_REDUCE_XOR) {
    return reinterpret_cast<const vector_reduce_xor &>(that);
  }
  return std::nullopt;
}

std::optional<vector_reduce_xor> vector_reduce_xor::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::vector_reduce_xor vector_reduce_xor::underlying_op(void) const noexcept {
  return ::mlir::LLVM::vector_reduce_xor(this->Operation::op_);
}

::mx::ir::Value vector_reduce_xor::in(void) const {
  auto val = underlying_op().getIn();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value vector_reduce_xor::res(void) const {
  auto val = underlying_op().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

}  // namespace mx::ir::llvm
