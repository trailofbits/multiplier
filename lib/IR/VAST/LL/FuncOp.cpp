// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/IR/VAST/LL/FuncOp.h>
#include <multiplier/IR/Attribute.h>
#include <multiplier/IR/Block.h>
#include <multiplier/IR/Region.h>
#include <multiplier/IR/Type.h>

#include <mlir/Dialect/SCF/IR/SCF.h>
#include <mlir/Dialect/LLVMIR/LLVMDialect.h>
#include <vast/Dialect/Dialects.hpp>
#include <vast/Dialect/LowLevel/LowLevelOps.hpp>

namespace mx::ir::ll {
std::optional<FuncOp> FuncOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LL_FUNC) {
    return reinterpret_cast<const FuncOp &>(that);
  }
  return std::nullopt;
}

std::optional<FuncOp> FuncOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::vast::ll::FuncOp FuncOp::underlying_op(void) const noexcept {
  return ::vast::ll::FuncOp(this->Operation::op_);
}

::mx::ir::Region FuncOp::body(void) const {
  auto &val = underlying_op().getBody();
  return ::mx::ir::Region(module_, val);
}

std::string_view FuncOp::sym_name(void) const {
  auto val = underlying_op().getSymName();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return {};
  }
}

std::optional<std::string_view> FuncOp::sym_visibility(void) const {
  auto opt_val = underlying_op().getSymVisibility();
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

bool FuncOp::is_declaration(void) const {
  auto val = underlying_op().isDeclaration();
  return val;
}

}  // namespace mx::ir::ll
