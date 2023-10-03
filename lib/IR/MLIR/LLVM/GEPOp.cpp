// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/IR/MLIR/LLVM/GEPOp.h>
#include <multiplier/IR/Attribute.h>
#include <multiplier/IR/Block.h>
#include <multiplier/IR/Region.h>
#include <multiplier/IR/Type.h>

#include <mlir/Dialect/SCF/IR/SCF.h>
#include <mlir/Dialect/LLVMIR/LLVMDialect.h>

namespace mx::ir::llvm {
std::optional<GEPOp> GEPOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_GETELEMENTPTR) {
    return reinterpret_cast<const GEPOp &>(that);
  }
  return std::nullopt;
}

std::optional<GEPOp> GEPOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::GEPOp GEPOp::underlying_op(void) const noexcept {
  return ::mlir::LLVM::GEPOp(this->Operation::op_);
}

::mx::ir::Value GEPOp::base(void) const {
  auto val = underlying_op().getBase();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

gap::generator<::mx::ir::Operand> GEPOp::dynamic_indices(void) const {
  auto range = underlying_op().getDynamicIndices();
  for (auto val : range) {
    co_yield ::mx::ir::Operand(module_, val.getAsOpaquePointer());
  }
}

::mx::ir::Value GEPOp::res(void) const {
  auto val = underlying_op().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

bool GEPOp::inbounds(void) const {
  auto val = underlying_op().getInbounds();
  return val;
}

}  // namespace mx::ir::llvm
