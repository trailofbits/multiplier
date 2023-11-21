// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/IR/VAST/HL/IfOp.h>
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
std::optional<IfOp> IfOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::HL_IF) {
    return reinterpret_cast<const IfOp &>(that);
  }
  return std::nullopt;
}

std::optional<IfOp> IfOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::vast::hl::IfOp IfOp::underlying_op(void) const noexcept {
  return ::vast::hl::IfOp(this->Operation::op_);
}

::mx::ir::Region IfOp::cond_region(void) const {
  auto &val = underlying_op().getCondRegion();
  return ::mx::ir::Region(module_, val);
}

::mx::ir::Region IfOp::then_region(void) const {
  auto &val = underlying_op().getThenRegion();
  return ::mx::ir::Region(module_, val);
}

::mx::ir::Region IfOp::else_region(void) const {
  auto &val = underlying_op().getElseRegion();
  return ::mx::ir::Region(module_, val);
}

bool IfOp::has_else(void) const {
  auto val = underlying_op().hasElse();
  return val;
}

}  // namespace mx::ir::hl
