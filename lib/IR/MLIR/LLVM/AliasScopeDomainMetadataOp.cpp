// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/IR/MLIR/LLVM/AliasScopeDomainMetadataOp.h>
#include <multiplier/IR/Attribute.h>
#include <multiplier/IR/Block.h>
#include <multiplier/IR/Region.h>
#include <multiplier/IR/Type.h>

#include <vast/Dialect/HighLevel/HighLevelOps.hpp>
#include <vast/Dialect/Dialects.hpp>
#include <mlir/Dialect/SCF/IR/SCF.h>
#include <mlir/Dialect/LLVMIR/LLVMDialect.h>

namespace mx::ir::llvm {
std::optional<AliasScopeDomainMetadataOp> AliasScopeDomainMetadataOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_ALIAS_SCOPE_DOMAIN) {
    return reinterpret_cast<const AliasScopeDomainMetadataOp &>(that);
  }
  return std::nullopt;
}

std::optional<AliasScopeDomainMetadataOp> AliasScopeDomainMetadataOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::AliasScopeDomainMetadataOp AliasScopeDomainMetadataOp::underlying_op(void) const noexcept {
  return ::mlir::LLVM::AliasScopeDomainMetadataOp(this->Operation::op_);
}

std::string_view AliasScopeDomainMetadataOp::sym_name(void) const {
  auto val = underlying_op().getSymName();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return {};
  }
}

std::optional<std::string_view> AliasScopeDomainMetadataOp::description(void) const {
  auto opt_val = underlying_op().getDescription();
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
