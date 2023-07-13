// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/IR/MLIR/MemRef/DeallocOp.h>
#include <multiplier/IR/Value.h>

#include <vast/Dialect/HighLevel/HighLevelOps.hpp>
#include <vast/Dialect/Dialects.hpp>
#include <mlir/Dialect/SCF/IR/SCF.h>
#include <mlir/Dialect/LLVMIR/LLVMDialect.h>
#include <mlir/Dialect/MemRef/IR/MemRef.h>

namespace mx::ir::memref {
std::optional<DeallocOp> DeallocOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::MEMREF_DEALLOC) {
    return reinterpret_cast<const DeallocOp &>(that);
  }
  return std::nullopt;
}

std::optional<DeallocOp> DeallocOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::memref::DeallocOp DeallocOp::underlying_op(void) const noexcept {
  return ::mlir::memref::DeallocOp(this->Operation::op_);
}

}  // namespace mx::ir::memref
