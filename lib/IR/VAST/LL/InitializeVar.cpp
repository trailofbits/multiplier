// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/IR/VAST/LL/InitializeVar.h>
#include <multiplier/IR/Value.h>

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

}  // namespace mx::ir::ll
