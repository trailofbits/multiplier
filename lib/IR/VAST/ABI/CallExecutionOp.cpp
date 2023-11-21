// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/IR/VAST/ABI/CallExecutionOp.h>
#include <multiplier/IR/Attribute.h>
#include <multiplier/IR/Block.h>
#include <multiplier/IR/Region.h>
#include <multiplier/IR/Type.h>

#include <mlir/Dialect/SCF/IR/SCF.h>
#include <mlir/Dialect/LLVMIR/LLVMDialect.h>
#include <vast/Dialect/Dialects.hpp>
#include <vast/Dialect/ABI/ABIOps.hpp>

namespace mx::ir::abi {
std::optional<CallExecutionOp> CallExecutionOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::ABI_CALL_EXEC) {
    return reinterpret_cast<const CallExecutionOp &>(that);
  }
  return std::nullopt;
}

std::optional<CallExecutionOp> CallExecutionOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::vast::abi::CallExecutionOp CallExecutionOp::underlying_op(void) const noexcept {
  return ::vast::abi::CallExecutionOp(this->Operation::op_);
}

gap::generator<::mx::ir::Operand> CallExecutionOp::args(void) const {
  auto range = underlying_op().getArgs();
  for (auto val : range) {
    co_yield ::mx::ir::Operand(module_, val.getAsOpaquePointer());
  }
}

::mx::ir::Value CallExecutionOp::result(void) const {
  auto val = underlying_op().getResult();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Region CallExecutionOp::body(void) const {
  auto &val = underlying_op().getBody();
  return ::mx::ir::Region(module_, val);
}

std::string_view CallExecutionOp::callee(void) const {
  auto val = underlying_op().getCallee();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return {};
  }
}

gap::generator<::mx::ir::Operand> CallExecutionOp::arg_operands(void) const {
  auto range = underlying_op().getArgOperands();
  for (auto val : range) {
    co_yield ::mx::ir::Operand(module_, val.getAsOpaquePointer());
  }
}

}  // namespace mx::ir::abi
