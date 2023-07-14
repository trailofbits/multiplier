// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/IR/VAST/HL/FuncRefOp.h>
#include <multiplier/IR/Attribute.h>
#include <multiplier/IR/Block.h>
#include <multiplier/IR/Region.h>
#include <multiplier/IR/Type.h>

#include <vast/Dialect/Dialects.hpp>
#include <mlir/Dialect/SCF/IR/SCF.h>
#include <mlir/Dialect/LLVMIR/LLVMDialect.h>
#include <vast/Dialect/HighLevel/HighLevelOps.hpp>

namespace mx::ir::hl {
std::optional<FuncRefOp> FuncRefOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::HL_FUNCREF) {
    return reinterpret_cast<const FuncRefOp &>(that);
  }
  return std::nullopt;
}

std::optional<FuncRefOp> FuncRefOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::vast::hl::FuncRefOp FuncRefOp::underlying_op(void) const noexcept {
  return ::vast::hl::FuncRefOp(this->Operation::op_);
}

::mx::ir::Value FuncRefOp::result(void) const {
  auto val = underlying_op().getResult();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::string_view FuncRefOp::function(void) const {
  auto val = underlying_op().getFunction();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return {};
  }
}

}  // namespace mx::ir::hl
