// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/IR/MLIR/LLVM/AtomicCmpXchgOp.h>
#include <multiplier/IR/Attribute.h>
#include <multiplier/IR/Block.h>
#include <multiplier/IR/Region.h>
#include <multiplier/IR/Type.h>

#include <mlir/Dialect/SCF/IR/SCF.h>
#include <mlir/Dialect/LLVMIR/LLVMDialect.h>

namespace mx::ir::llvm {
std::optional<AtomicCmpXchgOp> AtomicCmpXchgOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_CMPXCHG) {
    return reinterpret_cast<const AtomicCmpXchgOp &>(that);
  }
  return std::nullopt;
}

std::optional<AtomicCmpXchgOp> AtomicCmpXchgOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::AtomicCmpXchgOp AtomicCmpXchgOp::underlying_op(void) const noexcept {
  return ::mlir::LLVM::AtomicCmpXchgOp(this->Operation::op_);
}

::mx::ir::Value AtomicCmpXchgOp::cmp(void) const {
  auto val = underlying_op().getCmp();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value AtomicCmpXchgOp::val(void) const {
  auto val = underlying_op().getVal();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value AtomicCmpXchgOp::res(void) const {
  auto val = underlying_op().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<std::string_view> AtomicCmpXchgOp::syncscope(void) const {
  auto opt_val = underlying_op().getSyncscope();
  if (!opt_val) {
    return std::nullopt;
  }
  auto &val = opt_val.value();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return {};
  }
}

bool AtomicCmpXchgOp::weak(void) const {
  auto val = underlying_op().getWeak();
  return val;
}

bool AtomicCmpXchgOp::volatile__(void) const {
  auto val = underlying_op().getVolatile_();
  return val;
}

}  // namespace mx::ir::llvm
