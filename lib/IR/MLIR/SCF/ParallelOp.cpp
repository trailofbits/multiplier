// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/IR/MLIR/SCF/ParallelOp.h>
#include <multiplier/IR/Attribute.h>
#include <multiplier/IR/Block.h>
#include <multiplier/IR/Region.h>
#include <multiplier/IR/Type.h>

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

gap::generator<::mx::ir::Operand> ParallelOp::lower_bound(void) const {
  auto range = underlying_op().getLowerBound();
  for (auto val : range) {
    co_yield ::mx::ir::Operand(module_, val.getAsOpaquePointer());
  }
}

gap::generator<::mx::ir::Operand> ParallelOp::upper_bound(void) const {
  auto range = underlying_op().getUpperBound();
  for (auto val : range) {
    co_yield ::mx::ir::Operand(module_, val.getAsOpaquePointer());
  }
}

gap::generator<::mx::ir::Operand> ParallelOp::step(void) const {
  auto range = underlying_op().getStep();
  for (auto val : range) {
    co_yield ::mx::ir::Operand(module_, val.getAsOpaquePointer());
  }
}

gap::generator<::mx::ir::Operand> ParallelOp::init_vals(void) const {
  auto range = underlying_op().getInitVals();
  for (auto val : range) {
    co_yield ::mx::ir::Operand(module_, val.getAsOpaquePointer());
  }
}

gap::generator<::mx::ir::Result> ParallelOp::results(void) const {
  auto range = underlying_op().getResults();
  for (auto val : range) {
    co_yield ::mx::ir::Result(module_, val.getAsOpaquePointer());
  }
}

::mx::ir::Region ParallelOp::region(void) const {
  auto &val = underlying_op().getRegion();
  return ::mx::ir::Region(module_, val);
}

::mx::ir::Region ParallelOp::loop_body(void) const {
  auto &val = underlying_op().getLoopBody();
  return ::mx::ir::Region(module_, val);
}

}  // namespace mx::ir::scf
