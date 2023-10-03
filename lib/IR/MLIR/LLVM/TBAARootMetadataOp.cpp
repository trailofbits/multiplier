// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/IR/MLIR/LLVM/TBAARootMetadataOp.h>
#include <multiplier/IR/Attribute.h>
#include <multiplier/IR/Block.h>
#include <multiplier/IR/Region.h>
#include <multiplier/IR/Type.h>

#include <mlir/Dialect/SCF/IR/SCF.h>
#include <mlir/Dialect/LLVMIR/LLVMDialect.h>

namespace mx::ir::llvm {
std::optional<TBAARootMetadataOp> TBAARootMetadataOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_TBAA_ROOT) {
    return reinterpret_cast<const TBAARootMetadataOp &>(that);
  }
  return std::nullopt;
}

std::optional<TBAARootMetadataOp> TBAARootMetadataOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::TBAARootMetadataOp TBAARootMetadataOp::underlying_op(void) const noexcept {
  return ::mlir::LLVM::TBAARootMetadataOp(this->Operation::op_);
}

std::string_view TBAARootMetadataOp::sym_name(void) const {
  auto val = underlying_op().getSymName();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return {};
  }
}

std::string_view TBAARootMetadataOp::identity(void) const {
  auto val = underlying_op().getIdentity();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return {};
  }
}

}  // namespace mx::ir::llvm
