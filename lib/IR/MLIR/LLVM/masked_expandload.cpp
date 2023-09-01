// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/IR/MLIR/LLVM/masked_expandload.h>
#include <multiplier/IR/Attribute.h>
#include <multiplier/IR/Block.h>
#include <multiplier/IR/Region.h>
#include <multiplier/IR/Type.h>

#include <mlir/Dialect/SCF/IR/SCF.h>
#include <mlir/Dialect/LLVMIR/LLVMDialect.h>

namespace mx::ir::llvm {
std::optional<masked_expandload> masked_expandload::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_MASKED_EXPANDLOAD) {
    return reinterpret_cast<const masked_expandload &>(that);
  }
  return std::nullopt;
}

std::optional<masked_expandload> masked_expandload::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::masked_expandload masked_expandload::underlying_op(void) const noexcept {
  return ::mlir::LLVM::masked_expandload(this->Operation::op_);
}

::mx::ir::Value masked_expandload::res(void) const {
  auto val = underlying_op().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

}  // namespace mx::ir::llvm
