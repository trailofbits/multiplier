// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/IR/MLIR/SCF/ForOp.h>
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
std::optional<ForOp> ForOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::SCF_FOR) {
    return reinterpret_cast<const ForOp &>(that);
  }
  return std::nullopt;
}

std::optional<ForOp> ForOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::scf::ForOp ForOp::underlying_op(void) const noexcept {
  return ::mlir::scf::ForOp(this->Operation::op_);
}

gap::generator<::mx::ir::Operand> ForOp::init_args(void) const {
  auto range = underlying_op().getInitArgs();
  for (auto val : range) {
    co_yield ::mx::ir::Operand(module_, val.getAsOpaquePointer());
  }
}

gap::generator<::mx::ir::Result> ForOp::results(void) const {
  auto range = underlying_op().getResults();
  for (auto val : range) {
    co_yield ::mx::ir::Result(module_, val.getAsOpaquePointer());
  }
}

::mx::ir::Region ForOp::region(void) const {
  auto &val = underlying_op().getRegion();
  return ::mx::ir::Region(module_, val);
}

::mx::ir::Region ForOp::loop_body(void) const {
  auto &val = underlying_op().getLoopBody();
  return ::mx::ir::Region(module_, val);
}

bool ForOp::has_iter_operands(void) const {
  auto val = underlying_op().hasIterOperands();
  return val;
}

}  // namespace mx::ir::scf
