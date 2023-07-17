// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/IR/VAST/Core/SelectOp.h>
#include <multiplier/IR/Attribute.h>
#include <multiplier/IR/Block.h>
#include <multiplier/IR/Region.h>
#include <multiplier/IR/Type.h>

#include <vast/Dialect/Dialects.hpp>
#include <mlir/Dialect/SCF/IR/SCF.h>
#include <mlir/Dialect/LLVMIR/LLVMDialect.h>
#include <vast/Dialect/Core/CoreOps.hpp>

namespace mx::ir::core {
std::optional<SelectOp> SelectOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::CORE_SELECT) {
    return reinterpret_cast<const SelectOp &>(that);
  }
  return std::nullopt;
}

std::optional<SelectOp> SelectOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::vast::core::SelectOp SelectOp::underlying_op(void) const noexcept {
  return ::vast::core::SelectOp(this->Operation::op_);
}

::mx::ir::Value SelectOp::cond(void) const {
  auto val = underlying_op().getCond();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value SelectOp::then_region(void) const {
  auto val = underlying_op().getThenRegion();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value SelectOp::else_region(void) const {
  auto val = underlying_op().getElseRegion();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

gap::generator<::mx::ir::Result> SelectOp::results(void) const {
  auto range = underlying_op().getResults();
  for (auto val : range) {
    co_yield ::mx::ir::Result(module_, val.getAsOpaquePointer());
  }
}

}  // namespace mx::ir::core
