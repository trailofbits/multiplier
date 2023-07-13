// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/IR/MLIR/SCF/ExecuteRegionOp.h>
#include <multiplier/IR/Value.h>

#include <vast/Dialect/HighLevel/HighLevelOps.hpp>
#include <vast/Dialect/Dialects.hpp>
#include <mlir/Dialect/MemRef/IR/MemRef.h>
#include <mlir/Dialect/LLVMIR/LLVMDialect.h>
#include <mlir/Dialect/SCF/IR/SCF.h>

namespace mx::ir::scf {
std::optional<ExecuteRegionOp> ExecuteRegionOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::SCF_EXECUTE_REGION) {
    return reinterpret_cast<const ExecuteRegionOp &>(that);
  }
  return std::nullopt;
}

std::optional<ExecuteRegionOp> ExecuteRegionOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::scf::ExecuteRegionOp ExecuteRegionOp::underlying_op(void) const noexcept {
  return ::mlir::scf::ExecuteRegionOp(this->Operation::op_);
}

}  // namespace mx::ir::scf
