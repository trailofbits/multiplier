// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/IR/VAST/HL/SkipStmt.h>
#include <multiplier/IR/Attribute.h>
#include <multiplier/IR/Block.h>
#include <multiplier/IR/Region.h>
#include <multiplier/IR/Type.h>

#include <mlir/Dialect/SCF/IR/SCF.h>
#include <mlir/Dialect/LLVMIR/LLVMDialect.h>
#include <vast/Dialect/Dialects.hpp>
#include <vast/Dialect/HighLevel/HighLevelOps.hpp>

namespace mx::ir::hl {
std::optional<SkipStmt> SkipStmt::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::HL_SKIP) {
    return reinterpret_cast<const SkipStmt &>(that);
  }
  return std::nullopt;
}

std::optional<SkipStmt> SkipStmt::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::vast::hl::SkipStmt SkipStmt::underlying_op(void) const noexcept {
  return ::vast::hl::SkipStmt(this->Operation::op_);
}

}  // namespace mx::ir::hl
