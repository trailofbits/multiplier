// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/IR/VAST/HL/BinLShrAssignOp.h>
#include <multiplier/IR/Attribute.h>
#include <multiplier/IR/Block.h>
#include <multiplier/IR/Region.h>
#include <multiplier/IR/Type.h>

#include <mlir/Dialect/SCF/IR/SCF.h>
#include <mlir/Dialect/LLVMIR/LLVMDialect.h>
#include <vast/Dialect/Dialects.hpp>
#include <vast/Dialect/HighLevel/HighLevelOps.hpp>

namespace mx::ir::hl {
std::optional<BinLShrAssignOp> BinLShrAssignOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::HL_ASSIGN_BIN_LSHR) {
    return reinterpret_cast<const BinLShrAssignOp &>(that);
  }
  return std::nullopt;
}

std::optional<BinLShrAssignOp> BinLShrAssignOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::vast::hl::BinLShrAssignOp BinLShrAssignOp::underlying_op(void) const noexcept {
  return ::vast::hl::BinLShrAssignOp(this->Operation::op_);
}

::mx::ir::Value BinLShrAssignOp::src(void) const {
  auto val = underlying_op().getSrc();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value BinLShrAssignOp::dst(void) const {
  auto val = underlying_op().getDst();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value BinLShrAssignOp::result(void) const {
  auto val = underlying_op().getResult();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

}  // namespace mx::ir::hl
