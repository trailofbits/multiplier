// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/IR/MLIR/LLVM/DebugTrap.h>
#include <multiplier/IR/Attribute.h>
#include <multiplier/IR/Block.h>
#include <multiplier/IR/Region.h>
#include <multiplier/IR/Type.h>

#include <mlir/Dialect/SCF/IR/SCF.h>
#include <mlir/Dialect/LLVMIR/LLVMDialect.h>

namespace mx::ir::llvm {
std::optional<DebugTrap> DebugTrap::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_DEBUGTRAP) {
    return reinterpret_cast<const DebugTrap &>(that);
  }
  return std::nullopt;
}

std::optional<DebugTrap> DebugTrap::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::DebugTrap DebugTrap::underlying_op(void) const noexcept {
  return ::mlir::LLVM::DebugTrap(this->Operation::op_);
}

}  // namespace mx::ir::llvm
