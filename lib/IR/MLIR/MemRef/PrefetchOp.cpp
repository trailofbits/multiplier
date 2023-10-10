// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/IR/MLIR/MemRef/PrefetchOp.h>
#include <multiplier/IR/Attribute.h>
#include <multiplier/IR/Block.h>
#include <multiplier/IR/Region.h>
#include <multiplier/IR/Type.h>

#include <mlir/Dialect/SCF/IR/SCF.h>
#include <mlir/Dialect/LLVMIR/LLVMDialect.h>
#include <mlir/Dialect/MemRef/IR/MemRef.h>

namespace mx::ir::memref {
std::optional<PrefetchOp> PrefetchOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::MEMREF_PREFETCH) {
    return reinterpret_cast<const PrefetchOp &>(that);
  }
  return std::nullopt;
}

std::optional<PrefetchOp> PrefetchOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::memref::PrefetchOp PrefetchOp::underlying_op(void) const noexcept {
  return ::mlir::memref::PrefetchOp(this->Operation::op_);
}

gap::generator<::mx::ir::Operand> PrefetchOp::indices(void) const {
  auto range = underlying_op().getIndices();
  for (auto val : range) {
    co_yield ::mx::ir::Operand(module_, val.getAsOpaquePointer());
  }
}

bool PrefetchOp::is_write(void) const {
  auto val = underlying_op().getIsWrite();
  return val;
}

uint32_t PrefetchOp::locality_hint(void) const {
  auto val = underlying_op().getLocalityHint();
  return val;
}

bool PrefetchOp::is_data_cache(void) const {
  auto val = underlying_op().getIsDataCache();
  return val;
}

}  // namespace mx::ir::memref
