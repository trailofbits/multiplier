// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/IR/MLIR/MemRef/AssumeAlignmentOp.h>
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
std::optional<AssumeAlignmentOp> AssumeAlignmentOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::MEMREF_ASSUME_ALIGNMENT) {
    return reinterpret_cast<const AssumeAlignmentOp &>(that);
  }
  return std::nullopt;
}

std::optional<AssumeAlignmentOp> AssumeAlignmentOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::memref::AssumeAlignmentOp AssumeAlignmentOp::underlying_op(void) const noexcept {
  return ::mlir::memref::AssumeAlignmentOp(this->Operation::op_);
}

uint32_t AssumeAlignmentOp::alignment(void) const {
  auto val = underlying_op().getAlignment();
  return val;
}

}  // namespace mx::ir::memref
