// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/IR/VAST/HL/SubscriptOp.h>
#include <multiplier/IR/Attribute.h>
#include <multiplier/IR/Block.h>
#include <multiplier/IR/Region.h>
#include <multiplier/IR/Type.h>

#include <mlir/Dialect/SCF/IR/SCF.h>
#include <mlir/Dialect/LLVMIR/LLVMDialect.h>
#include <vast/Dialect/Dialects.hpp>
#include <vast/Dialect/ABI/ABIOps.hpp>
#include <vast/Dialect/HighLevel/HighLevelOps.hpp>

namespace mx::ir::hl {
std::optional<SubscriptOp> SubscriptOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::HL_SUBSCRIPT) {
    return reinterpret_cast<const SubscriptOp &>(that);
  }
  return std::nullopt;
}

std::optional<SubscriptOp> SubscriptOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::vast::hl::SubscriptOp SubscriptOp::underlying_op(void) const noexcept {
  return ::vast::hl::SubscriptOp(this->Operation::op_);
}

::mx::ir::Value SubscriptOp::array(void) const {
  auto val = underlying_op().getArray();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value SubscriptOp::index(void) const {
  auto val = underlying_op().getIndex();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value SubscriptOp::result(void) const {
  auto val = underlying_op().getResult();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

}  // namespace mx::ir::hl
