// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/IR/MLIR/LLVM/masked_gather.h>
#include <multiplier/IR/Attribute.h>
#include <multiplier/IR/Block.h>
#include <multiplier/IR/Region.h>
#include <multiplier/IR/Type.h>

#include <mlir/Dialect/SCF/IR/SCF.h>
#include <mlir/Dialect/LLVMIR/LLVMDialect.h>

namespace mx::ir::llvm {
std::optional<masked_gather> masked_gather::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_MASKED_GATHER) {
    return reinterpret_cast<const masked_gather &>(that);
  }
  return std::nullopt;
}

std::optional<masked_gather> masked_gather::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::masked_gather masked_gather::underlying_op(void) const noexcept {
  return ::mlir::LLVM::masked_gather(this->Operation::op_);
}

::mx::ir::Value masked_gather::ptrs(void) const {
  auto val = underlying_op().getPtrs();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value masked_gather::mask(void) const {
  auto val = underlying_op().getMask();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

gap::generator<::mx::ir::Operand> masked_gather::pass_thru(void) const {
  auto range = underlying_op().getPassThru();
  for (auto val : range) {
    co_yield ::mx::ir::Operand(module_, val.getAsOpaquePointer());
  }
}

::mx::ir::Value masked_gather::res(void) const {
  auto val = underlying_op().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

uint32_t masked_gather::alignment(void) const {
  auto val = underlying_op().getAlignment();
  return val;
}

}  // namespace mx::ir::llvm
