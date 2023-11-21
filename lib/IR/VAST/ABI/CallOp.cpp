// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/IR/VAST/ABI/CallOp.h>
#include <multiplier/IR/Attribute.h>
#include <multiplier/IR/Block.h>
#include <multiplier/IR/Region.h>
#include <multiplier/IR/Type.h>

#include <mlir/Dialect/SCF/IR/SCF.h>
#include <mlir/Dialect/LLVMIR/LLVMDialect.h>
#include <vast/Dialect/Dialects.hpp>
#include <vast/Dialect/ABI/ABIOps.hpp>

namespace mx::ir::abi {
std::optional<CallOp> CallOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::ABI_CALL) {
    return reinterpret_cast<const CallOp &>(that);
  }
  return std::nullopt;
}

std::optional<CallOp> CallOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::vast::abi::CallOp CallOp::underlying_op(void) const noexcept {
  return ::vast::abi::CallOp(this->Operation::op_);
}

gap::generator<::mx::ir::Operand> CallOp::args(void) const {
  auto range = underlying_op().getArgs();
  for (auto val : range) {
    co_yield ::mx::ir::Operand(module_, val.getAsOpaquePointer());
  }
}

gap::generator<::mx::ir::Result> CallOp::results(void) const {
  auto range = underlying_op().getResults();
  for (auto val : range) {
    co_yield ::mx::ir::Result(module_, val.getAsOpaquePointer());
  }
}

std::string_view CallOp::callee(void) const {
  auto val = underlying_op().getCallee();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return {};
  }
}

gap::generator<::mx::ir::Operand> CallOp::arg_operands(void) const {
  auto range = underlying_op().getArgOperands();
  for (auto val : range) {
    co_yield ::mx::ir::Operand(module_, val.getAsOpaquePointer());
  }
}

}  // namespace mx::ir::abi
