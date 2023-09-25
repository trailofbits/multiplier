// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/IR/MLIR/SCF/WhileOp.h>
#include <multiplier/IR/Attribute.h>
#include <multiplier/IR/Block.h>
#include <multiplier/IR/Region.h>
#include <multiplier/IR/Type.h>

#include <mlir/Dialect/MemRef/IR/MemRef.h>
#include <mlir/Dialect/LLVMIR/LLVMDialect.h>
#include <mlir/Dialect/SCF/IR/SCF.h>

namespace mx::ir::scf {
std::optional<WhileOp> WhileOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::SCF_WHILE) {
    return reinterpret_cast<const WhileOp &>(that);
  }
  return std::nullopt;
}

std::optional<WhileOp> WhileOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::scf::WhileOp WhileOp::underlying_op(void) const noexcept {
  return ::mlir::scf::WhileOp(this->Operation::op_);
}

gap::generator<::mx::ir::Operand> WhileOp::inits(void) const {
  auto range = underlying_op().getInits();
  for (auto val : range) {
    co_yield ::mx::ir::Operand(module_, val.getAsOpaquePointer());
  }
}

gap::generator<::mx::ir::Result> WhileOp::results(void) const {
  auto range = underlying_op().getResults();
  for (auto val : range) {
    co_yield ::mx::ir::Result(module_, val.getAsOpaquePointer());
  }
}

::mx::ir::Region WhileOp::before(void) const {
  auto &val = underlying_op().getBefore();
  return ::mx::ir::Region(module_, val);
}

::mx::ir::Region WhileOp::after(void) const {
  auto &val = underlying_op().getAfter();
  return ::mx::ir::Region(module_, val);
}

}  // namespace mx::ir::scf
