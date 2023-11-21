// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/IR/VAST/ABI/CallRetsOp.h>
#include <multiplier/IR/Attribute.h>
#include <multiplier/IR/Block.h>
#include <multiplier/IR/Region.h>
#include <multiplier/IR/Type.h>

#include <mlir/Dialect/SCF/IR/SCF.h>
#include <mlir/Dialect/LLVMIR/LLVMDialect.h>
#include <vast/Dialect/Dialects.hpp>
#include <vast/Dialect/ABI/ABIOps.hpp>

namespace mx::ir::abi {
std::optional<CallRetsOp> CallRetsOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::ABI_CALL_RETS) {
    return reinterpret_cast<const CallRetsOp &>(that);
  }
  return std::nullopt;
}

std::optional<CallRetsOp> CallRetsOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::vast::abi::CallRetsOp CallRetsOp::underlying_op(void) const noexcept {
  return ::vast::abi::CallRetsOp(this->Operation::op_);
}

gap::generator<::mx::ir::Result> CallRetsOp::results(void) const {
  auto range = underlying_op().getResults();
  for (auto val : range) {
    co_yield ::mx::ir::Result(module_, val.getAsOpaquePointer());
  }
}

::mx::ir::Region CallRetsOp::body(void) const {
  auto &val = underlying_op().getBody();
  return ::mx::ir::Region(module_, val);
}

}  // namespace mx::ir::abi
