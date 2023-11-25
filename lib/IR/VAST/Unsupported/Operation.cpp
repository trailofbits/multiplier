// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/IR/VAST/Unsupported/Operation.h>

#include <multiplier/IR/Attribute.h>
#include <multiplier/IR/Block.h>
#include <multiplier/IR/Region.h>
#include <multiplier/IR/Type.h>

#include <ios>
#include <string>

#include <mlir/Dialect/LLVMIR/LLVMDialect.h>
#include <vast/Dialect/Dialects.hpp>
#include <vast/Dialect/Unsupported/UnsupportedOps.hpp>

namespace mx::ir::unsup {
std::optional<Operation> Operation::from(const ::mx::ir::Operation &that) {
  switch (that.kind()) {
    default: return std::nullopt;
    case mx::ir::OperationKind::UNSUP_DECL:
    case mx::ir::OperationKind::UNSUP_STMT:
      return reinterpret_cast<const Operation &>(that);
  }
}

std::optional<UnsupportedDeclOp> UnsupportedDeclOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::UNSUP_DECL) {
    return reinterpret_cast<const UnsupportedDeclOp &>(that);
  }
  return std::nullopt;
}

std::optional<UnsupportedDeclOp> UnsupportedDeclOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::vast::unsup::UnsupportedDecl UnsupportedDeclOp::underlying_repr(void) const noexcept {
  return ::vast::unsup::UnsupportedDecl(this->::mx::ir::Operation::op_);
}

::mx::ir::Region UnsupportedDeclOp::body(void) const {
  auto &val = underlying_repr().getBody();
  return ::mx::ir::Region(module_, val);
}

std::string_view UnsupportedDeclOp::name(void) const {
  auto val = underlying_repr().getName();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return {};
  }
}

std::optional<UnsupportedStmtOp> UnsupportedStmtOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::UNSUP_STMT) {
    return reinterpret_cast<const UnsupportedStmtOp &>(that);
  }
  return std::nullopt;
}

std::optional<UnsupportedStmtOp> UnsupportedStmtOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::vast::unsup::UnsupportedStmt UnsupportedStmtOp::underlying_repr(void) const noexcept {
  return ::vast::unsup::UnsupportedStmt(this->::mx::ir::Operation::op_);
}

::mx::ir::Value UnsupportedStmtOp::result(void) const {
  auto val = underlying_repr().getResult();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::string_view UnsupportedStmtOp::name(void) const {
  auto val = underlying_repr().getName();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return {};
  }
}

}  // namespace mx::ir::unsup
