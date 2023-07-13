// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/IR/MLIR/SCF/ParallelOp.h>
#include <multiplier/IR/Value.h>

#include <vast/Dialect/HighLevel/HighLevelOps.hpp>
#include <vast/Dialect/Dialects.hpp>
#include <mlir/Dialect/MemRef/IR/MemRef.h>
#include <mlir/Dialect/LLVMIR/LLVMDialect.h>
#include <mlir/Dialect/SCF/IR/SCF.h>

namespace mx::ir::scf {
std::optional<ParallelOp> ParallelOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::SCF_PARALLEL) {
    return reinterpret_cast<const ParallelOp &>(that);
  }
  return std::nullopt;
}

std::optional<ParallelOp> ParallelOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::scf::ParallelOp ParallelOp::underlying_op(void) const noexcept {
  return ::mlir::scf::ParallelOp(this->Operation::op_);
}

}  // namespace mx::ir::scf
