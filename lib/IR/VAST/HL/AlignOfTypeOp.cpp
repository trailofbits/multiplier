// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/IR/VAST/HL/AlignOfTypeOp.h>
#include <multiplier/IR/Value.h>

#include <vast/Dialect/Dialects.hpp>
#include <mlir/Dialect/SCF/IR/SCF.h>
#include <mlir/Dialect/LLVMIR/LLVMDialect.h>
#include <vast/Dialect/HighLevel/HighLevelOps.hpp>

namespace mx::ir::hl {
std::optional<AlignOfTypeOp> AlignOfTypeOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::HL_ALIGNOF_TYPE) {
    return reinterpret_cast<const AlignOfTypeOp &>(that);
  }
  return std::nullopt;
}

std::optional<AlignOfTypeOp> AlignOfTypeOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::vast::hl::AlignOfTypeOp AlignOfTypeOp::underlying_op(void) const noexcept {
  return ::vast::hl::AlignOfTypeOp(this->Operation::op_);
}

}  // namespace mx::ir::hl
