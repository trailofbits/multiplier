// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/IR/MLIR/LLVM/LifetimeEndOp.h>
#include <multiplier/IR/Attribute.h>
#include <multiplier/IR/Block.h>
#include <multiplier/IR/Region.h>
#include <multiplier/IR/Type.h>

#include <vast/Dialect/HighLevel/HighLevelOps.hpp>
#include <vast/Dialect/Dialects.hpp>
#include <mlir/Dialect/SCF/IR/SCF.h>
#include <mlir/Dialect/LLVMIR/LLVMDialect.h>

namespace mx::ir::llvm {
std::optional<LifetimeEndOp> LifetimeEndOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_LIFETIME_END) {
    return reinterpret_cast<const LifetimeEndOp &>(that);
  }
  return std::nullopt;
}

std::optional<LifetimeEndOp> LifetimeEndOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::LifetimeEndOp LifetimeEndOp::underlying_op(void) const noexcept {
  return ::mlir::LLVM::LifetimeEndOp(this->Operation::op_);
}

uint64_t LifetimeEndOp::size(void) const {
  auto val = underlying_op().getSize();
  return val;
}

}  // namespace mx::ir::llvm
