// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/IR/MLIR/LLVM/vector_extract.h>
#include <multiplier/IR/Attribute.h>
#include <multiplier/IR/Block.h>
#include <multiplier/IR/Region.h>
#include <multiplier/IR/Type.h>

#include <vast/Dialect/HighLevel/HighLevelOps.hpp>
#include <vast/Dialect/Dialects.hpp>
#include <mlir/Dialect/SCF/IR/SCF.h>
#include <mlir/Dialect/LLVMIR/LLVMDialect.h>

namespace mx::ir::llvm {
std::optional<vector_extract> vector_extract::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_VECTOR_EXTRACT) {
    return reinterpret_cast<const vector_extract &>(that);
  }
  return std::nullopt;
}

std::optional<vector_extract> vector_extract::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::vector_extract vector_extract::underlying_op(void) const noexcept {
  return ::mlir::LLVM::vector_extract(this->Operation::op_);
}

::mx::ir::Value vector_extract::srcvec(void) const {
  auto val = underlying_op().getSrcvec();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value vector_extract::res(void) const {
  auto val = underlying_op().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

uint64_t vector_extract::pos(void) const {
  auto val = underlying_op().getPos();
  return val;
}

uint64_t vector_extract::src_vector_bit_width(void) const {
  auto val = underlying_op().getSrcVectorBitWidth();
  return val;
}

uint64_t vector_extract::res_vector_bit_width(void) const {
  auto val = underlying_op().getResVectorBitWidth();
  return val;
}

}  // namespace mx::ir::llvm
