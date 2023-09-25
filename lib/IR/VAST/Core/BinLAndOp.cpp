// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/IR/VAST/Core/BinLAndOp.h>
#include <multiplier/IR/Attribute.h>
#include <multiplier/IR/Block.h>
#include <multiplier/IR/Region.h>
#include <multiplier/IR/Type.h>

#include <mlir/Dialect/SCF/IR/SCF.h>
#include <mlir/Dialect/LLVMIR/LLVMDialect.h>
#include <vast/Dialect/Core/CoreOps.hpp>

namespace mx::ir::core {
std::optional<BinLAndOp> BinLAndOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::CORE_BIN_LAND) {
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

::vast::core::BinLAndOp BinLAndOp::underlying_op(void) const noexcept {
  return ::vast::core::BinLAndOp(this->Operation::op_);
}

::mx::ir::Value BinLAndOp::lhs(void) const {
  auto val = underlying_op().getLhs();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value BinLAndOp::rhs(void) const {
  auto val = underlying_op().getRhs();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value BinLAndOp::result(void) const {
  auto val = underlying_op().getResult();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

}  // namespace mx::ir::core
