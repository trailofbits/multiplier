// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/IR/VAST/LL/Br.h>
#include <multiplier/IR/Attribute.h>
#include <multiplier/IR/Block.h>
#include <multiplier/IR/Region.h>
#include <multiplier/IR/Type.h>

#include <mlir/Dialect/SCF/IR/SCF.h>
#include <vast/Dialect/Dialects.hpp>
#include <vast/Dialect/HighLevel/HighLevelOps.hpp>
#include <vast/Dialect/LowLevel/LowLevelOps.hpp>

namespace mx::ir::ll {
std::optional<Br> Br::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LL_BR) {
    return reinterpret_cast<const Br &>(that);
  }
  return std::nullopt;
}

std::optional<Br> Br::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::vast::ll::Br Br::underlying_op(void) const noexcept {
  return ::vast::ll::Br(this->Operation::op_);
}

gap::generator<::mx::ir::Operand> Br::operands(void) const {
  auto range = underlying_op().getOperands();
  for (auto val : range) {
    co_yield ::mx::ir::Operand(module_, val.getAsOpaquePointer());
  }
}

}  // namespace mx::ir::ll
