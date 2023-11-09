// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/IR/MLIR/LLVM/ComdatSelectorOp.h>
#include <multiplier/IR/Attribute.h>
#include <multiplier/IR/Block.h>
#include <multiplier/IR/Region.h>
#include <multiplier/IR/Type.h>

#include <mlir/Dialect/SCF/IR/SCF.h>
#include <mlir/Dialect/LLVMIR/LLVMDialect.h>

namespace mx::ir::llvm {
std::optional<ComdatSelectorOp> ComdatSelectorOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_COMDAT_SELECTOR) {
    return reinterpret_cast<const ComdatSelectorOp &>(that);
  }
  return std::nullopt;
}

std::optional<ComdatSelectorOp> ComdatSelectorOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::ComdatSelectorOp ComdatSelectorOp::underlying_op(void) const noexcept {
  return ::mlir::LLVM::ComdatSelectorOp(this->Operation::op_);
}

std::string_view ComdatSelectorOp::sym_name(void) const {
  auto val = underlying_op().getSymName();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return {};
  }
}

}  // namespace mx::ir::llvm
