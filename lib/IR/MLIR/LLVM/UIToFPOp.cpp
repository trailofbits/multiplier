// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/IR/MLIR/LLVM/UIToFPOp.h>
#include <multiplier/IR/Value.h>

#include <vast/Dialect/HighLevel/HighLevelOps.hpp>
#include <vast/Dialect/Dialects.hpp>
#include <mlir/Dialect/SCF/IR/SCF.h>
#include <mlir/Dialect/LLVMIR/LLVMDialect.h>

namespace mx::ir::llvm {
std::optional<UIToFPOp> UIToFPOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_UITOFP) {
    return reinterpret_cast<const UIToFPOp &>(that);
  }
  return std::nullopt;
}

std::optional<UIToFPOp> UIToFPOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::UIToFPOp UIToFPOp::underlying_op(void) const noexcept {
  return ::mlir::LLVM::UIToFPOp(this->Operation::op_);
}

}  // namespace mx::ir::llvm
