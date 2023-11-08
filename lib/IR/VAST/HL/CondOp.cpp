// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/IR/VAST/HL/CondOp.h>
#include <multiplier/IR/Attribute.h>
#include <multiplier/IR/Block.h>
#include <multiplier/IR/Region.h>
#include <multiplier/IR/Type.h>

#include <vast/Dialect/Dialects.hpp>
#include <mlir/Dialect/SCF/IR/SCF.h>
#include <mlir/Dialect/LLVMIR/LLVMDialect.h>
#include <vast/Dialect/HighLevel/HighLevelOps.hpp>

namespace mx::ir::hl {
std::optional<CondOp> CondOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::HL_COND) {
    return reinterpret_cast<const CondOp &>(that);
  }
  return std::nullopt;
}

std::optional<CondOp> CondOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::vast::hl::CondOp CondOp::underlying_op(void) const noexcept {
  return ::vast::hl::CondOp(this->Operation::op_);
}

::mx::ir::Value CondOp::result(void) const {
  auto val = underlying_op().getResult();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Region CondOp::cond_region(void) const {
  auto &val = underlying_op().getCondRegion();
  return ::mx::ir::Region(module_, val);
}

::mx::ir::Region CondOp::then_region(void) const {
  auto &val = underlying_op().getThenRegion();
  return ::mx::ir::Region(module_, val);
}

::mx::ir::Region CondOp::else_region(void) const {
  auto &val = underlying_op().getElseRegion();
  return ::mx::ir::Region(module_, val);
}

}  // namespace mx::ir::hl
