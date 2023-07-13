// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/IR/VAST/Core/BinLOrOp.h>
#include <multiplier/IR/Value.h>

#include <vast/Dialect/Dialects.hpp>
#include <mlir/Dialect/SCF/IR/SCF.h>
#include <mlir/Dialect/LLVMIR/LLVMDialect.h>
#include <vast/Dialect/Core/CoreOps.hpp>

namespace mx::ir::core {
std::optional<BinLOrOp> BinLOrOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::CORE_BIN_LOR) {
    return reinterpret_cast<const BinLOrOp &>(that);
  }
  return std::nullopt;
}

std::optional<BinLOrOp> BinLOrOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::vast::core::BinLOrOp BinLOrOp::underlying_op(void) const noexcept {
  return ::vast::core::BinLOrOp(this->Operation::op_);
}

}  // namespace mx::ir::core
