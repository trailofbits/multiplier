// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/IR/MLIR/MemRef/AllocaScopeReturnOp.h>
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
std::optional<AllocaScopeReturnOp> AllocaScopeReturnOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::MEMREF_ALLOCA_SCOPE_RETURN) {
    return reinterpret_cast<const AllocaScopeReturnOp &>(that);
  }
  return std::nullopt;
}

std::optional<AllocaScopeReturnOp> AllocaScopeReturnOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::memref::AllocaScopeReturnOp AllocaScopeReturnOp::underlying_op(void) const noexcept {
  return ::mlir::memref::AllocaScopeReturnOp(this->Operation::op_);
}

gap::generator<::mx::ir::Operand> AllocaScopeReturnOp::results(void) const {
  auto range = underlying_op().getResults();
  for (auto val : range) {
    co_yield ::mx::ir::Operand(module_, val.getAsOpaquePointer());
  }
}

}  // namespace mx::ir::memref
