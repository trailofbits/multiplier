// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/IR/MLIR/MemRef/AllocaScopeOp.h>
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
std::optional<AllocaScopeOp> AllocaScopeOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::MEMREF_ALLOCA_SCOPE) {
    return reinterpret_cast<const AllocaScopeOp &>(that);
  }
  return std::nullopt;
}

std::optional<AllocaScopeOp> AllocaScopeOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::memref::AllocaScopeOp AllocaScopeOp::underlying_op(void) const noexcept {
  return ::mlir::memref::AllocaScopeOp(this->Operation::op_);
}

gap::generator<::mx::ir::Result> AllocaScopeOp::results(void) const {
  auto range = underlying_op().getResults();
  for (auto val : range) {
    co_yield ::mx::ir::Result(module_, val.getAsOpaquePointer());
  }
}

::mx::ir::Region AllocaScopeOp::body_region(void) const {
  auto &val = underlying_op().getBodyRegion();
  return ::mx::ir::Region(module_, val);
}

}  // namespace mx::ir::memref
