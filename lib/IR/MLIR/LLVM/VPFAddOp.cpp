// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/IR/MLIR/LLVM/VPFAddOp.h>
#include <multiplier/IR/Attribute.h>
#include <multiplier/IR/Block.h>
#include <multiplier/IR/Region.h>
#include <multiplier/IR/Type.h>

#include <mlir/Dialect/SCF/IR/SCF.h>
#include <mlir/Dialect/LLVMIR/LLVMDialect.h>

namespace mx::ir::llvm {
std::optional<VPFAddOp> VPFAddOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_VP_FADD) {
    return reinterpret_cast<const VPFAddOp &>(that);
  }
  return std::nullopt;
}

std::optional<VPFAddOp> VPFAddOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::VPFAddOp VPFAddOp::underlying_op(void) const noexcept {
  return ::mlir::LLVM::VPFAddOp(this->Operation::op_);
}

::mx::ir::Value VPFAddOp::lhs(void) const {
  auto val = underlying_op().getLhs();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value VPFAddOp::rhs(void) const {
  auto val = underlying_op().getRhs();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value VPFAddOp::mask(void) const {
  auto val = underlying_op().getMask();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value VPFAddOp::res(void) const {
  auto val = underlying_op().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

}  // namespace mx::ir::llvm
