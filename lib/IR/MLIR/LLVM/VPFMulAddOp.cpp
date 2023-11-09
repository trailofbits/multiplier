// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/IR/MLIR/LLVM/VPFMulAddOp.h>
#include <multiplier/IR/Attribute.h>
#include <multiplier/IR/Block.h>
#include <multiplier/IR/Region.h>
#include <multiplier/IR/Type.h>

#include <mlir/Dialect/SCF/IR/SCF.h>
#include <mlir/Dialect/LLVMIR/LLVMDialect.h>

namespace mx::ir::llvm {
std::optional<VPFMulAddOp> VPFMulAddOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_VP_FMULADD) {
    return reinterpret_cast<const VPFMulAddOp &>(that);
  }
  return std::nullopt;
}

std::optional<VPFMulAddOp> VPFMulAddOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::VPFMulAddOp VPFMulAddOp::underlying_op(void) const noexcept {
  return ::mlir::LLVM::VPFMulAddOp(this->Operation::op_);
}

::mx::ir::Value VPFMulAddOp::op1(void) const {
  auto val = underlying_op().getOp1();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value VPFMulAddOp::op2(void) const {
  auto val = underlying_op().getOp2();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value VPFMulAddOp::op3(void) const {
  auto val = underlying_op().getOp3();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value VPFMulAddOp::mask(void) const {
  auto val = underlying_op().getMask();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value VPFMulAddOp::res(void) const {
  auto val = underlying_op().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

}  // namespace mx::ir::llvm
