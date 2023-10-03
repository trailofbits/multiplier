// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/IR/MLIR/LLVM/TBAATypeDescriptorOp.h>
#include <multiplier/IR/Attribute.h>
#include <multiplier/IR/Block.h>
#include <multiplier/IR/Region.h>
#include <multiplier/IR/Type.h>

#include <mlir/Dialect/SCF/IR/SCF.h>
#include <mlir/Dialect/LLVMIR/LLVMDialect.h>

namespace mx::ir::llvm {
std::optional<TBAATypeDescriptorOp> TBAATypeDescriptorOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_TBAA_TYPE_DESC) {
    return reinterpret_cast<const TBAATypeDescriptorOp &>(that);
  }
  return std::nullopt;
}

std::optional<TBAATypeDescriptorOp> TBAATypeDescriptorOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::TBAATypeDescriptorOp TBAATypeDescriptorOp::underlying_op(void) const noexcept {
  return ::mlir::LLVM::TBAATypeDescriptorOp(this->Operation::op_);
}

std::string_view TBAATypeDescriptorOp::sym_name(void) const {
  auto val = underlying_op().getSymName();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return {};
  }
}

std::optional<std::string_view> TBAATypeDescriptorOp::identity(void) const {
  auto opt_val = underlying_op().getIdentity();
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
