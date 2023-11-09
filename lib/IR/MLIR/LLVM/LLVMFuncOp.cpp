// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/IR/MLIR/LLVM/LLVMFuncOp.h>
#include <multiplier/IR/Attribute.h>
#include <multiplier/IR/Block.h>
#include <multiplier/IR/Region.h>
#include <multiplier/IR/Type.h>

#include <mlir/Dialect/SCF/IR/SCF.h>
#include <mlir/Dialect/LLVMIR/LLVMDialect.h>

namespace mx::ir::llvm {
std::optional<LLVMFuncOp> LLVMFuncOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_FUNC) {
    return reinterpret_cast<const LLVMFuncOp &>(that);
  }
  return std::nullopt;
}

std::optional<LLVMFuncOp> LLVMFuncOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::LLVMFuncOp LLVMFuncOp::underlying_op(void) const noexcept {
  return ::mlir::LLVM::LLVMFuncOp(this->Operation::op_);
}

::mx::ir::Region LLVMFuncOp::body(void) const {
  auto &val = underlying_op().getBody();
  return ::mx::ir::Region(module_, val);
}

std::string_view LLVMFuncOp::sym_name(void) const {
  auto val = underlying_op().getSymName();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return {};
  }
}

bool LLVMFuncOp::dso_local(void) const {
  auto val = underlying_op().getDsoLocal();
  return val;
}

std::optional<std::string_view> LLVMFuncOp::personality(void) const {
  auto opt_val = underlying_op().getPersonality();
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

std::optional<std::string_view> LLVMFuncOp::garbage_collector(void) const {
  auto opt_val = underlying_op().getGarbageCollector();
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

std::optional<std::string_view> LLVMFuncOp::section(void) const {
  auto opt_val = underlying_op().getSection();
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

bool LLVMFuncOp::is_var_arg(void) const {
  auto val = underlying_op().isVarArg();
  return val;
}

}  // namespace mx::ir::llvm
