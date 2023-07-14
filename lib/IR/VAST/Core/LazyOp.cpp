// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/IR/VAST/Core/LazyOp.h>
#include <multiplier/IR/Attribute.h>
#include <multiplier/IR/Block.h>
#include <multiplier/IR/Region.h>
#include <multiplier/IR/Type.h>

#include <vast/Dialect/Dialects.hpp>
#include <mlir/Dialect/SCF/IR/SCF.h>
#include <mlir/Dialect/LLVMIR/LLVMDialect.h>
#include <vast/Dialect/Core/CoreOps.hpp>

namespace mx::ir::core {
std::optional<LazyOp> LazyOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::CORE_LAZY_OP) {
    return reinterpret_cast<const LazyOp &>(that);
  }
  return std::nullopt;
}

std::optional<LazyOp> LazyOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::vast::core::LazyOp LazyOp::underlying_op(void) const noexcept {
  return ::vast::core::LazyOp(this->Operation::op_);
}

::mx::ir::Value LazyOp::result(void) const {
  auto val = underlying_op().getResult();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Region LazyOp::lazy(void) const {
  auto &val = underlying_op().getLazy();
  return ::mx::ir::Region(module_, val);
}

}  // namespace mx::ir::core
