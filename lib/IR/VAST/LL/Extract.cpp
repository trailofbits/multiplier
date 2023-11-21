// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/IR/VAST/LL/Extract.h>
#include <multiplier/IR/Attribute.h>
#include <multiplier/IR/Block.h>
#include <multiplier/IR/Region.h>
#include <multiplier/IR/Type.h>

#include <mlir/Dialect/SCF/IR/SCF.h>
#include <vast/Dialect/Dialects.hpp>
#include <vast/Dialect/ABI/ABIOps.hpp>
#include <vast/Dialect/LowLevel/LowLevelOps.hpp>

namespace mx::ir::ll {
std::optional<Extract> Extract::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LL_EXTRACT) {
    return reinterpret_cast<const Extract &>(that);
  }
  return std::nullopt;
}

std::optional<Extract> Extract::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::vast::ll::Extract Extract::underlying_op(void) const noexcept {
  return ::vast::ll::Extract(this->Operation::op_);
}

::mx::ir::Value Extract::arg(void) const {
  auto val = underlying_op().getArg();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value Extract::result(void) const {
  auto val = underlying_op().getResult();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

}  // namespace mx::ir::ll
