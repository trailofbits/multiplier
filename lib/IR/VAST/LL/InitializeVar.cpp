// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/IR/VAST/LL/InitializeVar.h>
#include <multiplier/IR/Attribute.h>
#include <multiplier/IR/Block.h>
#include <multiplier/IR/Region.h>
#include <multiplier/IR/Type.h>

#include <vast/Dialect/Dialects.hpp>
#include <mlir/Dialect/SCF/IR/SCF.h>
#include <mlir/Dialect/LLVMIR/LLVMDialect.h>
#include <vast/Dialect/LowLevel/LowLevelOps.hpp>

namespace mx::ir::ll {
std::optional<InitializeVar> InitializeVar::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LL_INITIALIZE) {
    return reinterpret_cast<const InitializeVar &>(that);
  }
  return std::nullopt;
}

std::optional<InitializeVar> InitializeVar::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::vast::ll::InitializeVar InitializeVar::underlying_op(void) const noexcept {
  return ::vast::ll::InitializeVar(this->Operation::op_);
}

::mx::ir::Value InitializeVar::var(void) const {
  auto val = underlying_op().getVar();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

gap::generator<::mx::ir::Operand> InitializeVar::elements(void) const {
  auto range = underlying_op().getElements();
  for (auto val : range) {
    co_yield ::mx::ir::Operand(module_, val.getAsOpaquePointer());
  }
}

::mx::ir::Value InitializeVar::result(void) const {
  auto val = underlying_op().getResult();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

}  // namespace mx::ir::ll
