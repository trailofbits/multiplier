// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/IR/MLIR/LLVM/vector_insert.h>
#include <multiplier/IR/Attribute.h>
#include <multiplier/IR/Block.h>
#include <multiplier/IR/Region.h>
#include <multiplier/IR/Type.h>

#include <vast/Dialect/HighLevel/HighLevelOps.hpp>
#include <vast/Dialect/Dialects.hpp>
#include <mlir/Dialect/SCF/IR/SCF.h>
#include <mlir/Dialect/LLVMIR/LLVMDialect.h>

namespace mx::ir::llvm {
std::optional<vector_insert> vector_insert::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_VECTOR_INSERT) {
    return reinterpret_cast<const vector_insert &>(that);
  }
  return std::nullopt;
}

std::optional<vector_insert> vector_insert::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::vector_insert vector_insert::underlying_op(void) const noexcept {
  return ::mlir::LLVM::vector_insert(this->Operation::op_);
}

::mx::ir::Value vector_insert::srcvec(void) const {
  auto val = underlying_op().getSrcvec();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value vector_insert::dstvec(void) const {
  auto val = underlying_op().getDstvec();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value vector_insert::res(void) const {
  auto val = underlying_op().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

uint64_t vector_insert::pos(void) const {
  auto val = underlying_op().getPos();
  return val;
}

uint64_t vector_insert::src_vector_bit_width(void) const {
  auto val = underlying_op().getSrcVectorBitWidth();
  return val;
}

uint64_t vector_insert::dst_vector_bit_width(void) const {
  auto val = underlying_op().getDstVectorBitWidth();
  return val;
}

}  // namespace mx::ir::llvm
