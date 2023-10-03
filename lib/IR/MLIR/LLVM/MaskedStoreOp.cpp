// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/IR/MLIR/LLVM/MaskedStoreOp.h>
#include <multiplier/IR/Attribute.h>
#include <multiplier/IR/Block.h>
#include <multiplier/IR/Region.h>
#include <multiplier/IR/Type.h>

#include <mlir/Dialect/SCF/IR/SCF.h>
#include <mlir/Dialect/LLVMIR/LLVMDialect.h>

namespace mx::ir::llvm {
std::optional<MaskedStoreOp> MaskedStoreOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_MASKED_STORE) {
    return reinterpret_cast<const MaskedStoreOp &>(that);
  }
  return std::nullopt;
}

std::optional<MaskedStoreOp> MaskedStoreOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::MaskedStoreOp MaskedStoreOp::underlying_op(void) const noexcept {
  return ::mlir::LLVM::MaskedStoreOp(this->Operation::op_);
}

::mx::ir::Value MaskedStoreOp::value(void) const {
  auto val = underlying_op().getValue();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value MaskedStoreOp::mask(void) const {
  auto val = underlying_op().getMask();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

uint32_t MaskedStoreOp::alignment(void) const {
  auto val = underlying_op().getAlignment();
  return val;
}

}  // namespace mx::ir::llvm
