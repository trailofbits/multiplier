// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/IR/VAST/Core/ImplicitReturnOp.h>
#include <multiplier/IR/Attribute.h>
#include <multiplier/IR/Block.h>
#include <multiplier/IR/Region.h>
#include <multiplier/IR/Type.h>

#include <mlir/Dialect/SCF/IR/SCF.h>
#include <vast/Dialect/Core/CoreOps.hpp>

namespace mx::ir::core {
std::optional<ImplicitReturnOp> ImplicitReturnOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::CORE_IMPLICIT_RETURN) {
    return reinterpret_cast<const ImplicitReturnOp &>(that);
  }
  return std::nullopt;
}

std::optional<ImplicitReturnOp> ImplicitReturnOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::vast::core::ImplicitReturnOp ImplicitReturnOp::underlying_op(void) const noexcept {
  return ::vast::core::ImplicitReturnOp(this->Operation::op_);
}

gap::generator<::mx::ir::Operand> ImplicitReturnOp::result(void) const {
  auto range = underlying_op().getResult();
  for (auto val : range) {
    co_yield ::mx::ir::Operand(module_, val.getAsOpaquePointer());
  }
}

}  // namespace mx::ir::core
