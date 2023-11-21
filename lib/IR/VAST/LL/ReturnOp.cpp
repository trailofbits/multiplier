// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/IR/VAST/LL/ReturnOp.h>
#include <multiplier/IR/Attribute.h>
#include <multiplier/IR/Block.h>
#include <multiplier/IR/Region.h>
#include <multiplier/IR/Type.h>

#include <mlir/Dialect/SCF/IR/SCF.h>
#include <vast/Dialect/Dialects.hpp>
#include <vast/Dialect/ABI/ABIOps.hpp>
#include <vast/Dialect/LowLevel/LowLevelOps.hpp>

namespace mx::ir::ll {
std::optional<ReturnOp> ReturnOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LL_RETURN) {
    return reinterpret_cast<const ReturnOp &>(that);
  }
  return std::nullopt;
}

std::optional<ReturnOp> ReturnOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::vast::ll::ReturnOp ReturnOp::underlying_op(void) const noexcept {
  return ::vast::ll::ReturnOp(this->Operation::op_);
}

gap::generator<::mx::ir::Operand> ReturnOp::result(void) const {
  auto range = underlying_op().getResult();
  for (auto val : range) {
    co_yield ::mx::ir::Operand(module_, val.getAsOpaquePointer());
  }
}

}  // namespace mx::ir::ll
