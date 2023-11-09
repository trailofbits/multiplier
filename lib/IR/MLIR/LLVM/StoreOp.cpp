// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/IR/MLIR/LLVM/StoreOp.h>
#include <multiplier/IR/Attribute.h>
#include <multiplier/IR/Block.h>
#include <multiplier/IR/Region.h>
#include <multiplier/IR/Type.h>

#include <mlir/Dialect/SCF/IR/SCF.h>
#include <mlir/Dialect/LLVMIR/LLVMDialect.h>

namespace mx::ir::llvm {
std::optional<StoreOp> StoreOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_STORE) {
    return reinterpret_cast<const StoreOp &>(that);
  }
  return std::nullopt;
}

std::optional<StoreOp> StoreOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::StoreOp StoreOp::underlying_op(void) const noexcept {
  return ::mlir::LLVM::StoreOp(this->Operation::op_);
}

::mx::ir::Value StoreOp::value(void) const {
  auto val = underlying_op().getValue();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

bool StoreOp::volatile__(void) const {
  auto val = underlying_op().getVolatile_();
  return val;
}

bool StoreOp::nontemporal(void) const {
  auto val = underlying_op().getNontemporal();
  return val;
}

std::optional<std::string_view> StoreOp::syncscope(void) const {
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

}  // namespace mx::ir::llvm
