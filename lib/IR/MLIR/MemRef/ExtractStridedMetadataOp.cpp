// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/IR/MLIR/MemRef/ExtractStridedMetadataOp.h>
#include <multiplier/IR/Attribute.h>
#include <multiplier/IR/Block.h>
#include <multiplier/IR/Region.h>
#include <multiplier/IR/Type.h>

#include <mlir/Dialect/SCF/IR/SCF.h>
#include <mlir/Dialect/LLVMIR/LLVMDialect.h>
#include <mlir/Dialect/MemRef/IR/MemRef.h>

namespace mx::ir::memref {
std::optional<ExtractStridedMetadataOp> ExtractStridedMetadataOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::MEMREF_EXTRACT_STRIDED_METADATA) {
    return reinterpret_cast<const ExtractStridedMetadataOp &>(that);
  }
  return std::nullopt;
}

std::optional<ExtractStridedMetadataOp> ExtractStridedMetadataOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::memref::ExtractStridedMetadataOp ExtractStridedMetadataOp::underlying_op(void) const noexcept {
  return ::mlir::memref::ExtractStridedMetadataOp(this->Operation::op_);
}

::mx::ir::Value ExtractStridedMetadataOp::base_buffer(void) const {
  auto val = underlying_op().getBaseBuffer();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

gap::generator<::mx::ir::Result> ExtractStridedMetadataOp::sizes(void) const {
  auto range = underlying_op().getSizes();
  for (auto val : range) {
    co_yield ::mx::ir::Result(module_, val.getAsOpaquePointer());
  }
}

gap::generator<::mx::ir::Result> ExtractStridedMetadataOp::strides(void) const {
  auto range = underlying_op().getStrides();
  for (auto val : range) {
    co_yield ::mx::ir::Result(module_, val.getAsOpaquePointer());
  }
}

::mx::ir::Value ExtractStridedMetadataOp::view_source(void) const {
  auto val = underlying_op().getViewSource();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

}  // namespace mx::ir::memref
