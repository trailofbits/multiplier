// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/IR/Core/Operation.h>

#include <multiplier/IR/Attribute.h>
#include <multiplier/IR/Block.h>
#include <multiplier/IR/Region.h>
#include <multiplier/IR/Type.h>

#include <ios>
#include <string>

#include <mlir/Dialect/LLVMIR/LLVMDialect.h>
#include <vast/Dialect/Core/CoreOps.hpp>

namespace mx::ir::core {
std::optional<Operation> Operation::from(const ::mx::ir::Operation &that) {
  switch (that.kind()) {
    default: return std::nullopt;
    case mx::ir::OperationKind::CORE_BIN_LAND:
    case mx::ir::OperationKind::CORE_BIN_LOR:
    case mx::ir::OperationKind::CORE_IMPLICIT_RETURN:
    case mx::ir::OperationKind::CORE_LAZY_OP:
    case mx::ir::OperationKind::CORE_SCOPE:
    case mx::ir::OperationKind::CORE_SELECT:
      return reinterpret_cast<const Operation &>(that);
  }
}

std::optional<BinLAndOp> BinLAndOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::CORE_BIN_LAND) {
    return reinterpret_cast<const BinLAndOp &>(that);
  }
  return std::nullopt;
}

std::optional<BinLAndOp> BinLAndOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::vast::core::BinLAndOp BinLAndOp::underlying_repr(void) const noexcept {
  return ::vast::core::BinLAndOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value BinLAndOp::lhs(void) const {
  auto val = underlying_repr().getLhs();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value BinLAndOp::rhs(void) const {
  auto val = underlying_repr().getRhs();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value BinLAndOp::result(void) const {
  auto val = underlying_repr().getResult();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<BinLOrOp> BinLOrOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::CORE_BIN_LOR) {
    return reinterpret_cast<const BinLOrOp &>(that);
  }
  return std::nullopt;
}

std::optional<BinLOrOp> BinLOrOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::vast::core::BinLOrOp BinLOrOp::underlying_repr(void) const noexcept {
  return ::vast::core::BinLOrOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value BinLOrOp::lhs(void) const {
  auto val = underlying_repr().getLhs();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value BinLOrOp::rhs(void) const {
  auto val = underlying_repr().getRhs();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value BinLOrOp::result(void) const {
  auto val = underlying_repr().getResult();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<ImplicitReturnOp> ImplicitReturnOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::CORE_IMPLICIT_RETURN) {
    return reinterpret_cast<const ImplicitReturnOp &>(that);
  }
  return std::nullopt;
}

std::optional<ImplicitReturnOp> ImplicitReturnOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::vast::core::ImplicitReturnOp ImplicitReturnOp::underlying_repr(void) const noexcept {
  return ::vast::core::ImplicitReturnOp(this->::mx::ir::Operation::op_);
}

gap::generator<::mx::ir::Operand> ImplicitReturnOp::result(void) const {
  auto range = underlying_repr().getResult();
  for (auto val : range) {
    co_yield ::mx::ir::Operand(module_, val.getAsOpaquePointer());
  }
}

std::optional<LazyOp> LazyOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::CORE_LAZY_OP) {
    return reinterpret_cast<const LazyOp &>(that);
  }
  return std::nullopt;
}

std::optional<LazyOp> LazyOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::vast::core::LazyOp LazyOp::underlying_repr(void) const noexcept {
  return ::vast::core::LazyOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value LazyOp::result(void) const {
  auto val = underlying_repr().getResult();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Region LazyOp::lazy(void) const {
  auto &val = underlying_repr().getLazy();
  return ::mx::ir::Region(module_, val);
}

std::optional<ScopeOp> ScopeOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::CORE_SCOPE) {
    return reinterpret_cast<const ScopeOp &>(that);
  }
  return std::nullopt;
}

std::optional<ScopeOp> ScopeOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::vast::core::ScopeOp ScopeOp::underlying_repr(void) const noexcept {
  return ::vast::core::ScopeOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Region ScopeOp::body(void) const {
  auto &val = underlying_repr().getBody();
  return ::mx::ir::Region(module_, val);
}

std::optional<SelectOp> SelectOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::CORE_SELECT) {
    return reinterpret_cast<const SelectOp &>(that);
  }
  return std::nullopt;
}

std::optional<SelectOp> SelectOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::vast::core::SelectOp SelectOp::underlying_repr(void) const noexcept {
  return ::vast::core::SelectOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value SelectOp::cond(void) const {
  auto val = underlying_repr().getCond();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value SelectOp::then_region(void) const {
  auto val = underlying_repr().getThenRegion();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value SelectOp::else_region(void) const {
  auto val = underlying_repr().getElseRegion();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

gap::generator<::mx::ir::Result> SelectOp::results(void) const {
  auto range = underlying_repr().getResults();
  for (auto val : range) {
    co_yield ::mx::ir::Result(module_, val.getAsOpaquePointer());
  }
}

}  // namespace mx::ir::core
