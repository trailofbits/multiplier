// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/IR/MLIR/LLVM/GlobalOp.h>
#include <multiplier/IR/Attribute.h>
#include <multiplier/IR/Block.h>
#include <multiplier/IR/Region.h>
#include <multiplier/IR/Type.h>

#include <vast/Dialect/HighLevel/HighLevelOps.hpp>
#include <vast/Dialect/Dialects.hpp>
#include <mlir/Dialect/SCF/IR/SCF.h>
#include <mlir/Dialect/LLVMIR/LLVMDialect.h>

namespace mx::ir::llvm {
std::optional<GlobalOp> GlobalOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_MLIR_GLOBAL) {
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

::mlir::LLVM::GlobalOp GlobalOp::underlying_op(void) const noexcept {
  return ::mlir::LLVM::GlobalOp(this->Operation::op_);
}

::mx::ir::Region GlobalOp::initializer(void) const {
  auto &val = underlying_op().getInitializer();
  return ::mx::ir::Region(module_, val);
}

bool GlobalOp::constant(void) const {
  auto val = underlying_op().getConstant();
  return val;
}

std::string_view GlobalOp::sym_name(void) const {
  auto val = underlying_op().getSymName();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return {};
  }
}

bool GlobalOp::dso_local(void) const {
  auto val = underlying_op().getDsoLocal();
  return val;
}

bool GlobalOp::thread_local__(void) const {
  auto val = underlying_op().getThreadLocal_();
  return val;
}

uint32_t GlobalOp::addr_space(void) const {
  auto val = underlying_op().getAddrSpace();
  return val;
}

std::optional<std::string_view> GlobalOp::section(void) const {
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

}  // namespace mx::ir::llvm
