// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/IR/MLIR/MemRef/SubViewOp.h>
#include <multiplier/IR/Attribute.h>
#include <multiplier/IR/Block.h>
#include <multiplier/IR/Region.h>
#include <multiplier/IR/Type.h>

#include <mlir/Dialect/SCF/IR/SCF.h>
#include <mlir/Dialect/LLVMIR/LLVMDialect.h>
#include <mlir/Dialect/MemRef/IR/MemRef.h>

namespace mx::ir::memref {
std::optional<SubViewOp> SubViewOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::MEMREF_SUBVIEW) {
    return reinterpret_cast<const SubViewOp &>(that);
  }
  return std::nullopt;
}

std::optional<SubViewOp> SubViewOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::memref::SubViewOp SubViewOp::underlying_op(void) const noexcept {
  return ::mlir::memref::SubViewOp(this->Operation::op_);
}

gap::generator<::mx::ir::Operand> SubViewOp::offsets(void) const {
  auto range = underlying_op().getOffsets();
  for (auto val : range) {
    co_yield ::mx::ir::Operand(module_, val.getAsOpaquePointer());
  }
}

gap::generator<::mx::ir::Operand> SubViewOp::sizes(void) const {
  auto range = underlying_op().getSizes();
  for (auto val : range) {
    co_yield ::mx::ir::Operand(module_, val.getAsOpaquePointer());
  }
}

gap::generator<::mx::ir::Operand> SubViewOp::strides(void) const {
  auto range = underlying_op().getStrides();
  for (auto val : range) {
    co_yield ::mx::ir::Operand(module_, val.getAsOpaquePointer());
  }
}

::mx::ir::Value SubViewOp::view_source(void) const {
  auto val = underlying_op().getViewSource();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

gap::generator<::mx::ir::Operand> SubViewOp::dynamic_sizes(void) const {
  auto range = underlying_op().getDynamicSizes();
  for (auto val : range) {
    co_yield ::mx::ir::Operand(module_, val.getAsOpaquePointer());
  }
}

}  // namespace mx::ir::memref
