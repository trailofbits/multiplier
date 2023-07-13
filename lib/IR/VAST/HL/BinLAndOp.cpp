// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/IR/VAST/HL/BinLAndOp.h>
#include <multiplier/IR/Value.h>

#include <vast/Dialect/Dialects.hpp>
#include <mlir/Dialect/SCF/IR/SCF.h>
#include <mlir/Dialect/LLVMIR/LLVMDialect.h>
#include <vast/Dialect/HighLevel/HighLevelOps.hpp>

namespace mx::ir::hl {
std::optional<BinLAndOp> BinLAndOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::HL_BIN_LAND) {
    return reinterpret_cast<const BinLAndOp &>(that);
  }
  return std::nullopt;
}

std::optional<BinLAndOp> BinLAndOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::vast::hl::BinLAndOp BinLAndOp::underlying_op(void) const noexcept {
  return ::vast::hl::BinLAndOp(this->Operation::op_);
}

}  // namespace mx::ir::hl
