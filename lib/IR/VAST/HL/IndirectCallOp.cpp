// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/IR/VAST/HL/IndirectCallOp.h>
#include <multiplier/IR/Attribute.h>
#include <multiplier/IR/Block.h>
#include <multiplier/IR/Region.h>
#include <multiplier/IR/Type.h>

#include <vast/Dialect/Dialects.hpp>
#include <mlir/Dialect/SCF/IR/SCF.h>
#include <mlir/Dialect/LLVMIR/LLVMDialect.h>
#include <vast/Dialect/HighLevel/HighLevelOps.hpp>

namespace mx::ir::hl {
std::optional<IndirectCallOp> IndirectCallOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::HL_INDIRECT_CALL) {
    return reinterpret_cast<const IndirectCallOp &>(that);
  }
  return std::nullopt;
}

std::optional<IndirectCallOp> IndirectCallOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::vast::hl::IndirectCallOp IndirectCallOp::underlying_op(void) const noexcept {
  return ::vast::hl::IndirectCallOp(this->Operation::op_);
}

::mx::ir::Value IndirectCallOp::callee(void) const {
  auto val = underlying_op().getCallee();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

gap::generator<::mx::ir::Operand> IndirectCallOp::arg_operands(void) const {
  auto range = underlying_op().getArgOperands();
  for (auto val : range) {
    co_yield ::mx::ir::Operand(module_, val.getAsOpaquePointer());
  }
}

gap::generator<::mx::ir::Result> IndirectCallOp::results(void) const {
  auto range = underlying_op().getResults();
  for (auto val : range) {
    co_yield ::mx::ir::Result(module_, val.getAsOpaquePointer());
  }
}

}  // namespace mx::ir::hl
