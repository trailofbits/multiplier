// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/IR/MLIR/LLVM/UAddSat.h>
#include <multiplier/IR/Attribute.h>
#include <multiplier/IR/Block.h>
#include <multiplier/IR/Region.h>
#include <multiplier/IR/Type.h>

#include <mlir/Dialect/SCF/IR/SCF.h>
#include <mlir/Dialect/LLVMIR/LLVMDialect.h>

namespace mx::ir::llvm {
std::optional<UAddSat> UAddSat::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_UADD_SAT) {
    return reinterpret_cast<const UAddSat &>(that);
  }
  return std::nullopt;
}

std::optional<UAddSat> UAddSat::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::UAddSat UAddSat::underlying_op(void) const noexcept {
  return ::mlir::LLVM::UAddSat(this->Operation::op_);
}

::mx::ir::Value UAddSat::a(void) const {
  auto val = underlying_op().getA();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value UAddSat::b(void) const {
  auto val = underlying_op().getB();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value UAddSat::res(void) const {
  auto val = underlying_op().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

}  // namespace mx::ir::llvm
