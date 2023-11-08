// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/IR/MLIR/MemRef/CopyOp.h>
#include <multiplier/IR/Attribute.h>
#include <multiplier/IR/Block.h>
#include <multiplier/IR/Region.h>
#include <multiplier/IR/Type.h>

#include <mlir/Dialect/SCF/IR/SCF.h>
#include <mlir/Dialect/LLVMIR/LLVMDialect.h>
#include <mlir/Dialect/MemRef/IR/MemRef.h>

namespace mx::ir::memref {
std::optional<CopyOp> CopyOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::MEMREF_COPY) {
    return reinterpret_cast<const CopyOp &>(that);
  }
  return std::nullopt;
}

std::optional<CopyOp> CopyOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::memref::CopyOp CopyOp::underlying_op(void) const noexcept {
  return ::mlir::memref::CopyOp(this->Operation::op_);
}

::mx::ir::Value CopyOp::source(void) const {
  auto val = underlying_op().getSource();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value CopyOp::target(void) const {
  auto val = underlying_op().getTarget();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

}  // namespace mx::ir::memref
