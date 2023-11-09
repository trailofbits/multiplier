// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/IR/MLIR/SCF/InParallelOp.h>
#include <multiplier/IR/Attribute.h>
#include <multiplier/IR/Block.h>
#include <multiplier/IR/Region.h>
#include <multiplier/IR/Type.h>

#include <mlir/Dialect/SCF/IR/SCF.h>

namespace mx::ir::scf {
std::optional<InParallelOp> InParallelOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::SCF_FORALL_IN_PARALLEL) {
    return reinterpret_cast<const InParallelOp &>(that);
  }
  return std::nullopt;
}

std::optional<InParallelOp> InParallelOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::scf::InParallelOp InParallelOp::underlying_op(void) const noexcept {
  return ::mlir::scf::InParallelOp(this->Operation::op_);
}

::mx::ir::Region InParallelOp::region(void) const {
  auto &val = underlying_op().getRegion();
  return ::mx::ir::Region(module_, val);
}

}  // namespace mx::ir::scf
