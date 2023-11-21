// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/IR/VAST/HL/DoOp.h>
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
std::optional<DoOp> DoOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::HL_DO) {
    return reinterpret_cast<const DoOp &>(that);
  }
  return std::nullopt;
}

std::optional<DoOp> DoOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::vast::hl::DoOp DoOp::underlying_op(void) const noexcept {
  return ::vast::hl::DoOp(this->Operation::op_);
}

::mx::ir::Region DoOp::body_region(void) const {
  auto &val = underlying_op().getBodyRegion();
  return ::mx::ir::Region(module_, val);
}

::mx::ir::Region DoOp::cond_region(void) const {
  auto &val = underlying_op().getCondRegion();
  return ::mx::ir::Region(module_, val);
}

}  // namespace mx::ir::hl
