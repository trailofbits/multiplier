// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/IR/MLIR/LLVM/TBAATagOp.h>
#include <multiplier/IR/Attribute.h>
#include <multiplier/IR/Block.h>
#include <multiplier/IR/Region.h>
#include <multiplier/IR/Type.h>

#include <vast/Dialect/HighLevel/HighLevelOps.hpp>
#include <vast/Dialect/Dialects.hpp>
#include <mlir/Dialect/SCF/IR/SCF.h>
#include <mlir/Dialect/LLVMIR/LLVMDialect.h>

namespace mx::ir::llvm {
std::optional<TBAATagOp> TBAATagOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_TBAA_TAG) {
    return reinterpret_cast<const TBAATagOp &>(that);
  }
  return std::nullopt;
}

std::optional<TBAATagOp> TBAATagOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::TBAATagOp TBAATagOp::underlying_op(void) const noexcept {
  return ::mlir::LLVM::TBAATagOp(this->Operation::op_);
}

std::string_view TBAATagOp::sym_name(void) const {
  auto val = underlying_op().getSymName();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return {};
  }
}

std::string_view TBAATagOp::base_type(void) const {
  auto val = underlying_op().getBaseType();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return {};
  }
}

std::string_view TBAATagOp::access_type(void) const {
  auto val = underlying_op().getAccessType();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return {};
  }
}

uint64_t TBAATagOp::offset(void) const {
  auto val = underlying_op().getOffset();
  return val;
}

bool TBAATagOp::constant(void) const {
  auto val = underlying_op().getConstant();
  return val;
}

}  // namespace mx::ir::llvm
