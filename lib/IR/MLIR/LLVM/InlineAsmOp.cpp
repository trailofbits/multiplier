// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/IR/MLIR/LLVM/InlineAsmOp.h>
#include <multiplier/IR/Attribute.h>
#include <multiplier/IR/Block.h>
#include <multiplier/IR/Region.h>
#include <multiplier/IR/Type.h>

#include <vast/Dialect/HighLevel/HighLevelOps.hpp>
#include <vast/Dialect/Dialects.hpp>
#include <mlir/Dialect/SCF/IR/SCF.h>
#include <mlir/Dialect/LLVMIR/LLVMDialect.h>

namespace mx::ir::llvm {
std::optional<InlineAsmOp> InlineAsmOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INLINE_ASM) {
    return reinterpret_cast<const InlineAsmOp &>(that);
  }
  return std::nullopt;
}

std::optional<InlineAsmOp> InlineAsmOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::InlineAsmOp InlineAsmOp::underlying_op(void) const noexcept {
  return ::mlir::LLVM::InlineAsmOp(this->Operation::op_);
}

gap::generator<::mx::ir::Operand> InlineAsmOp::operands(void) const {
  auto range = underlying_op().getOperands();
  for (auto val : range) {
    co_yield ::mx::ir::Operand(module_, val.getAsOpaquePointer());
  }
}

::mx::ir::Value InlineAsmOp::res(void) const {
  auto val = underlying_op().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::string_view InlineAsmOp::asm_string(void) const {
  auto val = underlying_op().getAsmString();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return {};
  }
}

std::string_view InlineAsmOp::constraints(void) const {
  auto val = underlying_op().getConstraints();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return {};
  }
}

bool InlineAsmOp::has_side_effects(void) const {
  auto val = underlying_op().getHasSideEffects();
  return val;
}

bool InlineAsmOp::is_align_stack(void) const {
  auto val = underlying_op().getIsAlignStack();
  return val;
}

}  // namespace mx::ir::llvm
