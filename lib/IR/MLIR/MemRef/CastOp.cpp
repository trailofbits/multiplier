// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/IR/MLIR/MemRef/CastOp.h>
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
std::optional<CastOp> CastOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::MEMREF_CAST) {
    return reinterpret_cast<const CastOp &>(that);
  }
  return std::nullopt;
}

std::optional<CastOp> CastOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::memref::CastOp CastOp::underlying_op(void) const noexcept {
  return ::mlir::memref::CastOp(this->Operation::op_);
}

::mx::ir::Value CastOp::source(void) const {
  auto val = underlying_op().getSource();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value CastOp::dest(void) const {
  auto val = underlying_op().getDest();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

}  // namespace mx::ir::memref
