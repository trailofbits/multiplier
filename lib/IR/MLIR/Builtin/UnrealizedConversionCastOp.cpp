// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/IR/MLIR/Builtin/UnrealizedConversionCastOp.h>
#include <multiplier/IR/Attribute.h>
#include <multiplier/IR/Block.h>
#include <multiplier/IR/Region.h>
#include <multiplier/IR/Type.h>

#include <mlir/Dialect/SCF/IR/SCF.h>

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

gap::generator<::mx::ir::Operand> UnrealizedConversionCastOp::inputs(void) const {
  auto range = underlying_op().getInputs();
  for (auto val : range) {
    co_yield ::mx::ir::Operand(module_, val.getAsOpaquePointer());
  }
}

gap::generator<::mx::ir::Result> UnrealizedConversionCastOp::outputs(void) const {
  auto range = underlying_op().getOutputs();
  for (auto val : range) {
    co_yield ::mx::ir::Result(module_, val.getAsOpaquePointer());
  }
}

}  // namespace mx::ir::builtin
