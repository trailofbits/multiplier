// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/IR/MLIR/MemRef/GlobalOp.h>
#include <multiplier/IR/Attribute.h>
#include <multiplier/IR/Block.h>
#include <multiplier/IR/Region.h>
#include <multiplier/IR/Type.h>

#include <mlir/Dialect/SCF/IR/SCF.h>
#include <mlir/Dialect/LLVMIR/LLVMDialect.h>
#include <mlir/Dialect/MemRef/IR/MemRef.h>

namespace mx::ir::memref {
std::optional<GlobalOp> GlobalOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::MEMREF_GLOBAL) {
    return reinterpret_cast<const GlobalOp &>(that);
  }
  return std::nullopt;
}

std::optional<GlobalOp> GlobalOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::memref::GlobalOp GlobalOp::underlying_op(void) const noexcept {
  return ::mlir::memref::GlobalOp(this->Operation::op_);
}

std::string_view GlobalOp::sym_name(void) const {
  auto val = underlying_op().getSymName();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return {};
  }
}

std::optional<std::string_view> GlobalOp::sym_visibility(void) const {
  auto opt_val = underlying_op().getSymVisibility();
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

bool GlobalOp::constant(void) const {
  auto val = underlying_op().getConstant();
  return val;
}

bool GlobalOp::is_external(void) const {
  auto val = underlying_op().isExternal();
  return val;
}

bool GlobalOp::is_uninitialized(void) const {
  auto val = underlying_op().isUninitialized();
  return val;
}

}  // namespace mx::ir::memref
