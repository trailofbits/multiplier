// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/IR/VAST/HL/AddIOp.h>
#include <multiplier/IR/Attribute.h>
#include <multiplier/IR/Block.h>
#include <multiplier/IR/Region.h>
#include <multiplier/IR/Type.h>

#include <mlir/Dialect/SCF/IR/SCF.h>
#include <mlir/Dialect/LLVMIR/LLVMDialect.h>
#include <vast/Dialect/Dialects.hpp>
#include <vast/Dialect/HighLevel/HighLevelOps.hpp>

namespace mx::ir::hl {
std::optional<AddIOp> AddIOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::HL_ADD) {
    return reinterpret_cast<const AddIOp &>(that);
  }
  return std::nullopt;
}

std::optional<AddIOp> AddIOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::vast::hl::AddIOp AddIOp::underlying_op(void) const noexcept {
  return ::vast::hl::AddIOp(this->Operation::op_);
}

::mx::ir::Value AddIOp::lhs(void) const {
  auto val = underlying_op().getLhs();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value AddIOp::rhs(void) const {
  auto val = underlying_op().getRhs();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value AddIOp::result(void) const {
  auto val = underlying_op().getResult();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

}  // namespace mx::ir::hl
