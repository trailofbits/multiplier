// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/IR/MLIR/Builtin/UnrealizedConversionCastOp.h>
#include <multiplier/IR/Value.h>

#include <vast/Dialect/HighLevel/HighLevelOps.hpp>
#include <vast/Dialect/Dialects.hpp>
#include <mlir/Dialect/SCF/IR/SCF.h>
#include <mlir/Dialect/LLVMIR/LLVMDialect.h>

namespace mx::ir::builtin {
std::optional<UnrealizedConversionCastOp> UnrealizedConversionCastOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::BUILTIN_UNREALIZED_CONVERSION_CAST) {
    return reinterpret_cast<const UnrealizedConversionCastOp &>(that);
  }
  return std::nullopt;
}

std::optional<UnrealizedConversionCastOp> UnrealizedConversionCastOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::UnrealizedConversionCastOp UnrealizedConversionCastOp::underlying_op(void) const noexcept {
  return ::mlir::UnrealizedConversionCastOp(this->Operation::op_);
}

}  // namespace mx::ir::builtin
