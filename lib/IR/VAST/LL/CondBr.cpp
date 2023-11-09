// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/IR/VAST/LL/CondBr.h>
#include <multiplier/IR/Attribute.h>
#include <multiplier/IR/Block.h>
#include <multiplier/IR/Region.h>
#include <multiplier/IR/Type.h>

#include <mlir/Dialect/SCF/IR/SCF.h>
#include <vast/Dialect/Dialects.hpp>
#include <vast/Dialect/HighLevel/HighLevelOps.hpp>
#include <vast/Dialect/LowLevel/LowLevelOps.hpp>

namespace mx::ir::ll {
std::optional<CondBr> CondBr::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LL_COND_BR) {
    return reinterpret_cast<const CondBr &>(that);
  }
  return std::nullopt;
}

std::optional<CondBr> CondBr::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::vast::ll::CondBr CondBr::underlying_op(void) const noexcept {
  return ::vast::ll::CondBr(this->Operation::op_);
}

::mx::ir::Value CondBr::cond(void) const {
  auto val = underlying_op().getCond();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

gap::generator<::mx::ir::Operand> CondBr::true_operands(void) const {
  auto range = underlying_op().getTrueOperands();
  for (auto val : range) {
    co_yield ::mx::ir::Operand(module_, val.getAsOpaquePointer());
  }
}

gap::generator<::mx::ir::Operand> CondBr::false_operands(void) const {
  auto range = underlying_op().getFalseOperands();
  for (auto val : range) {
    co_yield ::mx::ir::Operand(module_, val.getAsOpaquePointer());
  }
}

}  // namespace mx::ir::ll
