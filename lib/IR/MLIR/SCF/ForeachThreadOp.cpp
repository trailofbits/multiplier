// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/IR/MLIR/SCF/ForeachThreadOp.h>
#include <multiplier/IR/Attribute.h>
#include <multiplier/IR/Block.h>
#include <multiplier/IR/Region.h>
#include <multiplier/IR/Type.h>

#include <vast/Dialect/HighLevel/HighLevelOps.hpp>
#include <vast/Dialect/Dialects.hpp>
#include <mlir/Dialect/MemRef/IR/MemRef.h>
#include <mlir/Dialect/LLVMIR/LLVMDialect.h>
#include <mlir/Dialect/SCF/IR/SCF.h>

namespace mx::ir::scf {
std::optional<ForeachThreadOp> ForeachThreadOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::SCF_FOREACH_THREAD) {
    return reinterpret_cast<const ForeachThreadOp &>(that);
  }
  return std::nullopt;
}

std::optional<ForeachThreadOp> ForeachThreadOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::scf::ForeachThreadOp ForeachThreadOp::underlying_op(void) const noexcept {
  return ::mlir::scf::ForeachThreadOp(this->Operation::op_);
}

gap::generator<::mx::ir::Operand> ForeachThreadOp::num_threads(void) const {
  auto range = underlying_op().getNumThreads();
  for (auto val : range) {
    co_yield ::mx::ir::Operand(module_, val.getAsOpaquePointer());
  }
}

gap::generator<::mx::ir::Operand> ForeachThreadOp::outputs(void) const {
  auto range = underlying_op().getOutputs();
  for (auto val : range) {
    co_yield ::mx::ir::Operand(module_, val.getAsOpaquePointer());
  }
}

gap::generator<::mx::ir::Result> ForeachThreadOp::results(void) const {
  auto range = underlying_op().getResults();
  for (auto val : range) {
    co_yield ::mx::ir::Result(module_, val.getAsOpaquePointer());
  }
}

::mx::ir::Region ForeachThreadOp::region(void) const {
  auto &val = underlying_op().getRegion();
  return ::mx::ir::Region(module_, val);
}

int64_t ForeachThreadOp::rank(void) const {
  auto val = underlying_op().getRank();
  return val;
}

}  // namespace mx::ir::scf
