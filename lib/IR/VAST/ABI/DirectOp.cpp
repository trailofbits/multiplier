// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/IR/VAST/ABI/DirectOp.h>
#include <multiplier/IR/Attribute.h>
#include <multiplier/IR/Block.h>
#include <multiplier/IR/Region.h>
#include <multiplier/IR/Type.h>

#include <mlir/Dialect/SCF/IR/SCF.h>
#include <mlir/Dialect/LLVMIR/LLVMDialect.h>
#include <vast/Dialect/Dialects.hpp>
#include <vast/Dialect/ABI/ABIOps.hpp>

namespace mx::ir::abi {
std::optional<DirectOp> DirectOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::ABI_DIRECT) {
    return reinterpret_cast<const DirectOp &>(that);
  }
  return std::nullopt;
}

std::optional<DirectOp> DirectOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::vast::abi::DirectOp DirectOp::underlying_op(void) const noexcept {
  return ::vast::abi::DirectOp(this->Operation::op_);
}

gap::generator<::mx::ir::Operand> DirectOp::value(void) const {
  auto range = underlying_op().getValue();
  for (auto val : range) {
    co_yield ::mx::ir::Operand(module_, val.getAsOpaquePointer());
  }
}

gap::generator<::mx::ir::Result> DirectOp::result(void) const {
  auto range = underlying_op().getResult();
  for (auto val : range) {
    co_yield ::mx::ir::Result(module_, val.getAsOpaquePointer());
  }
}

}  // namespace mx::ir::abi
