// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/IR/VAST/HL/BinOrAssignOp.h>
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
std::optional<BinOrAssignOp> BinOrAssignOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::HL_ASSIGN_BIN_OR) {
    return reinterpret_cast<const BinOrAssignOp &>(that);
  }
  return std::nullopt;
}

std::optional<BinOrAssignOp> BinOrAssignOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::vast::hl::BinOrAssignOp BinOrAssignOp::underlying_op(void) const noexcept {
  return ::vast::hl::BinOrAssignOp(this->Operation::op_);
}

::mx::ir::Value BinOrAssignOp::src(void) const {
  auto val = underlying_op().getSrc();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value BinOrAssignOp::dst(void) const {
  auto val = underlying_op().getDst();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value BinOrAssignOp::result(void) const {
  auto val = underlying_op().getResult();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

}  // namespace mx::ir::hl
