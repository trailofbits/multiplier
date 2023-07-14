// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/IR/MLIR/LLVM/VaCopyOp.h>
#include <multiplier/IR/Attribute.h>
#include <multiplier/IR/Block.h>
#include <multiplier/IR/Region.h>
#include <multiplier/IR/Type.h>

#include <vast/Dialect/HighLevel/HighLevelOps.hpp>
#include <vast/Dialect/Dialects.hpp>
#include <mlir/Dialect/SCF/IR/SCF.h>
#include <mlir/Dialect/LLVMIR/LLVMDialect.h>

namespace mx::ir::llvm {
std::optional<VaCopyOp> VaCopyOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_VACOPY) {
    return reinterpret_cast<const VaCopyOp &>(that);
  }
  return std::nullopt;
}

std::optional<VaCopyOp> VaCopyOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::VaCopyOp VaCopyOp::underlying_op(void) const noexcept {
  return ::mlir::LLVM::VaCopyOp(this->Operation::op_);
}

::mx::ir::Value VaCopyOp::dest_list(void) const {
  auto val = underlying_op().getDestList();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value VaCopyOp::src_list(void) const {
  auto val = underlying_op().getSrcList();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

}  // namespace mx::ir::llvm
