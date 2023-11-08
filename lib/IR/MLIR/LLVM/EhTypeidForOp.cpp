// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/IR/MLIR/LLVM/EhTypeidForOp.h>
#include <multiplier/IR/Attribute.h>
#include <multiplier/IR/Block.h>
#include <multiplier/IR/Region.h>
#include <multiplier/IR/Type.h>

#include <mlir/Dialect/SCF/IR/SCF.h>
#include <mlir/Dialect/LLVMIR/LLVMDialect.h>

namespace mx::ir::llvm {
std::optional<EhTypeidForOp> EhTypeidForOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_EH_TYPEID_FOR) {
    return reinterpret_cast<const EhTypeidForOp &>(that);
  }
  return std::nullopt;
}

std::optional<EhTypeidForOp> EhTypeidForOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::EhTypeidForOp EhTypeidForOp::underlying_op(void) const noexcept {
  return ::mlir::LLVM::EhTypeidForOp(this->Operation::op_);
}

::mx::ir::Value EhTypeidForOp::type_info(void) const {
  auto val = underlying_op().getTypeInfo();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value EhTypeidForOp::res(void) const {
  auto val = underlying_op().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

}  // namespace mx::ir::llvm
