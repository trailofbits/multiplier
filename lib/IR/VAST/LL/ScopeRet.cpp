// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/IR/VAST/LL/ScopeRet.h>
#include <multiplier/IR/Attribute.h>
#include <multiplier/IR/Block.h>
#include <multiplier/IR/Region.h>
#include <multiplier/IR/Type.h>

#include <mlir/Dialect/SCF/IR/SCF.h>
#include <vast/Dialect/Dialects.hpp>
#include <vast/Dialect/ABI/ABIOps.hpp>
#include <vast/Dialect/LowLevel/LowLevelOps.hpp>

namespace mx::ir::ll {
std::optional<ScopeRet> ScopeRet::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LL_SCOPE_RET) {
    return reinterpret_cast<const ScopeRet &>(that);
  }
  return std::nullopt;
}

std::optional<ScopeRet> ScopeRet::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::vast::ll::ScopeRet ScopeRet::underlying_op(void) const noexcept {
  return ::vast::ll::ScopeRet(this->Operation::op_);
}

}  // namespace mx::ir::ll
