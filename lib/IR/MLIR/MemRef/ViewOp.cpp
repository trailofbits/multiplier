// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/IR/MLIR/MemRef/ViewOp.h>
#include <multiplier/IR/Attribute.h>
#include <multiplier/IR/Block.h>
#include <multiplier/IR/Region.h>
#include <multiplier/IR/Type.h>

#include <vast/Dialect/HighLevel/HighLevelOps.hpp>
#include <vast/Dialect/Dialects.hpp>
#include <mlir/Dialect/SCF/IR/SCF.h>
#include <mlir/Dialect/LLVMIR/LLVMDialect.h>
#include <mlir/Dialect/MemRef/IR/MemRef.h>

namespace mx::ir::memref {
std::optional<ViewOp> ViewOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::MEMREF_VIEW) {
    return reinterpret_cast<const ViewOp &>(that);
  }
  return std::nullopt;
}

std::optional<ViewOp> ViewOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::memref::ViewOp ViewOp::underlying_op(void) const noexcept {
  return ::mlir::memref::ViewOp(this->Operation::op_);
}

gap::generator<::mx::ir::Operand> ViewOp::sizes(void) const {
  auto range = underlying_op().getSizes();
  for (auto val : range) {
    co_yield ::mx::ir::Operand(module_, val.getAsOpaquePointer());
  }
}

::mx::ir::Value ViewOp::view_source(void) const {
  auto val = underlying_op().getViewSource();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

}  // namespace mx::ir::memref
