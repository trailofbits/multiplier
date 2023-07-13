// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/IR/MLIR/SCF/ReduceOp.h>
#include <multiplier/IR/Value.h>

#include <vast/Dialect/HighLevel/HighLevelOps.hpp>
#include <vast/Dialect/Dialects.hpp>
#include <mlir/Dialect/MemRef/IR/MemRef.h>
#include <mlir/Dialect/LLVMIR/LLVMDialect.h>
#include <mlir/Dialect/SCF/IR/SCF.h>

namespace mx::ir::scf {
std::optional<ReduceOp> ReduceOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::SCF_REDUCE) {
    return reinterpret_cast<const ReduceOp &>(that);
  }
  return std::nullopt;
}

std::optional<ReduceOp> ReduceOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::scf::ReduceOp ReduceOp::underlying_op(void) const noexcept {
  return ::mlir::scf::ReduceOp(this->Operation::op_);
}

}  // namespace mx::ir::scf
