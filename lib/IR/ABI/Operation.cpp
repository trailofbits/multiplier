// Copyright (c) 2023-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/IR/ABI/Operation.h>

#include <multiplier/IR/Attribute.h>
#include <multiplier/IR/Block.h>
#include <multiplier/IR/Region.h>
#include <multiplier/IR/Type.h>

#include <ios>
#include <string>

#include <mlir/Dialect/LLVMIR/LLVMDialect.h>
#include <vast/Dialect/Dialects.hpp>
#include <vast/Dialect/ABI/ABIOps.hpp>

namespace mx::ir::abi {
std::optional<Operation> Operation::from(const ::mx::ir::Operation &that) {
  if (IsABIOperationKind(that.kind())) {
    return reinterpret_cast<const Operation &>(that);
  }
  return std::nullopt;
}

std::optional<CallArgsOp> CallArgsOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::ABI_CALL_ARGS) {
    return reinterpret_cast<const CallArgsOp &>(that);
  }
  return std::nullopt;
}

std::optional<CallArgsOp> CallArgsOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::vast::abi::CallArgsOp CallArgsOp::underlying_repr(void) const noexcept {
  return ::vast::abi::CallArgsOp(this->::mx::ir::Operation::op_);
}

gap::generator<::mx::ir::Result> CallArgsOp::results(void) const & {
  auto range = underlying_repr().getResults();
  for (auto val : range) {
    co_yield ::mx::ir::Result(module_, val.getAsOpaquePointer());
  }
}

::mx::ir::Region CallArgsOp::body(void) const {
  auto &val = underlying_repr().getBody();
  return ::mx::ir::Region(module_, val);
}

std::optional<CallExecutionOp> CallExecutionOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::ABI_CALL_EXEC) {
    return reinterpret_cast<const CallExecutionOp &>(that);
  }
  return std::nullopt;
}

std::optional<CallExecutionOp> CallExecutionOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::vast::abi::CallExecutionOp CallExecutionOp::underlying_repr(void) const noexcept {
  return ::vast::abi::CallExecutionOp(this->::mx::ir::Operation::op_);
}

gap::generator<::mx::ir::Operand> CallExecutionOp::arguments(void) const & {
  auto range = underlying_repr().getArgs();
  for (auto val : range) {
    co_yield ::mx::ir::Operand(module_, val.getAsOpaquePointer());
  }
}

::mx::ir::Value CallExecutionOp::result(void) const {
  auto val = underlying_repr().getResult();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Region CallExecutionOp::body(void) const {
  auto &val = underlying_repr().getBody();
  return ::mx::ir::Region(module_, val);
}

gap::generator<::mx::ir::Operand> CallExecutionOp::arg_operands(void) const & {
  auto range = underlying_repr().getArgOperands();
  for (auto val : range) {
    co_yield ::mx::ir::Operand(module_, val.getAsOpaquePointer());
  }
}

std::optional<CallOp> CallOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::ABI_CALL) {
    return reinterpret_cast<const CallOp &>(that);
  }
  return std::nullopt;
}

std::optional<CallOp> CallOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::vast::abi::CallOp CallOp::underlying_repr(void) const noexcept {
  return ::vast::abi::CallOp(this->::mx::ir::Operation::op_);
}

gap::generator<::mx::ir::Operand> CallOp::arguments(void) const & {
  auto range = underlying_repr().getArgs();
  for (auto val : range) {
    co_yield ::mx::ir::Operand(module_, val.getAsOpaquePointer());
  }
}

gap::generator<::mx::ir::Result> CallOp::results(void) const & {
  auto range = underlying_repr().getResults();
  for (auto val : range) {
    co_yield ::mx::ir::Result(module_, val.getAsOpaquePointer());
  }
}

std::string_view CallOp::callee(void) const {
  auto val = underlying_repr().getCallee();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return {};
  }
}

gap::generator<::mx::ir::Operand> CallOp::arg_operands(void) const & {
  auto range = underlying_repr().getArgOperands();
  for (auto val : range) {
    co_yield ::mx::ir::Operand(module_, val.getAsOpaquePointer());
  }
}

std::optional<CallRetsOp> CallRetsOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::ABI_CALL_RETS) {
    return reinterpret_cast<const CallRetsOp &>(that);
  }
  return std::nullopt;
}

std::optional<CallRetsOp> CallRetsOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::vast::abi::CallRetsOp CallRetsOp::underlying_repr(void) const noexcept {
  return ::vast::abi::CallRetsOp(this->::mx::ir::Operation::op_);
}

gap::generator<::mx::ir::Result> CallRetsOp::results(void) const & {
  auto range = underlying_repr().getResults();
  for (auto val : range) {
    co_yield ::mx::ir::Result(module_, val.getAsOpaquePointer());
  }
}

::mx::ir::Region CallRetsOp::body(void) const {
  auto &val = underlying_repr().getBody();
  return ::mx::ir::Region(module_, val);
}

std::optional<DirectOp> DirectOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::ABI_DIRECT) {
    return reinterpret_cast<const DirectOp &>(that);
  }
  return std::nullopt;
}

std::optional<DirectOp> DirectOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::vast::abi::DirectOp DirectOp::underlying_repr(void) const noexcept {
  return ::vast::abi::DirectOp(this->::mx::ir::Operation::op_);
}

gap::generator<::mx::ir::Operand> DirectOp::value(void) const & {
  auto range = underlying_repr().getValue();
  for (auto val : range) {
    co_yield ::mx::ir::Operand(module_, val.getAsOpaquePointer());
  }
}

gap::generator<::mx::ir::Result> DirectOp::result(void) const & {
  auto range = underlying_repr().getResult();
  for (auto val : range) {
    co_yield ::mx::ir::Result(module_, val.getAsOpaquePointer());
  }
}

std::optional<EpilogueOp> EpilogueOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::ABI_EPILOGUE) {
    return reinterpret_cast<const EpilogueOp &>(that);
  }
  return std::nullopt;
}

std::optional<EpilogueOp> EpilogueOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::vast::abi::EpilogueOp EpilogueOp::underlying_repr(void) const noexcept {
  return ::vast::abi::EpilogueOp(this->::mx::ir::Operation::op_);
}

gap::generator<::mx::ir::Result> EpilogueOp::results(void) const & {
  auto range = underlying_repr().getResults();
  for (auto val : range) {
    co_yield ::mx::ir::Result(module_, val.getAsOpaquePointer());
  }
}

::mx::ir::Region EpilogueOp::body(void) const {
  auto &val = underlying_repr().getBody();
  return ::mx::ir::Region(module_, val);
}

std::optional<FuncOp> FuncOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::ABI_FUNC) {
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

::vast::abi::FuncOp FuncOp::underlying_repr(void) const noexcept {
  return ::vast::abi::FuncOp(this->::mx::ir::Operation::op_);
}

std::optional<::mx::ir::Region> FuncOp::body(void) const {
  decltype(auto) opt_val = underlying_repr().getBody();
  if (opt_val.empty()) {
    return std::nullopt;
  }
  auto &val = opt_val;
  return ::mx::ir::Region(module_, val);
}

std::string_view FuncOp::name(void) const {
  auto val = underlying_repr().getSymName();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return {};
  }
}

::mx::ir::Type FuncOp::function_type(void) const {
  auto mlir_type = underlying_repr().getFunctionType();
  return ::mx::ir::Type(
      mlir_type.getContext(),
      reinterpret_cast<const mlir::TypeStorage *>(
          mlir_type.getAsOpaquePointer()));
}

std::optional<std::string_view> FuncOp::visibility(void) const {
  auto opt_val = underlying_repr().getSymVisibility();
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

bool FuncOp::is_var_arg(void) const {
  auto val = underlying_repr().isVarArg();
  return val;
}

gap::generator<::mx::ir::Type> FuncOp::callable_results(void) const & {
  auto range = underlying_repr().getCallableResults();
  for (auto el_ty : range) {
    co_yield ::mx::ir::Type(
        el_ty.getContext(),
        reinterpret_cast<const mlir::TypeStorage *>(
            el_ty.getAsOpaquePointer()));
  }
}

gap::generator<::mx::ir::Type> FuncOp::argument_types(void) const & {
  auto range = underlying_repr().getArgumentTypes();
  for (auto el_ty : range) {
    co_yield ::mx::ir::Type(
        el_ty.getContext(),
        reinterpret_cast<const mlir::TypeStorage *>(
            el_ty.getAsOpaquePointer()));
  }
}

gap::generator<::mx::ir::Type> FuncOp::result_types(void) const & {
  auto range = underlying_repr().getResultTypes();
  for (auto el_ty : range) {
    co_yield ::mx::ir::Type(
        el_ty.getContext(),
        reinterpret_cast<const mlir::TypeStorage *>(
            el_ty.getAsOpaquePointer()));
  }
}

bool FuncOp::is_declaration(void) const {
  auto val = underlying_repr().isDeclaration();
  return val;
}

std::optional<IndirectOp> IndirectOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::ABI_INDIRECT) {
    return reinterpret_cast<const IndirectOp &>(that);
  }
  return std::nullopt;
}

std::optional<IndirectOp> IndirectOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::vast::abi::IndirectOp IndirectOp::underlying_repr(void) const noexcept {
  return ::vast::abi::IndirectOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value IndirectOp::value(void) const {
  auto val = underlying_repr().getValue();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value IndirectOp::result(void) const {
  auto val = underlying_repr().getResult();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<PrologueOp> PrologueOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::ABI_PROLOGUE) {
    return reinterpret_cast<const PrologueOp &>(that);
  }
  return std::nullopt;
}

std::optional<PrologueOp> PrologueOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::vast::abi::PrologueOp PrologueOp::underlying_repr(void) const noexcept {
  return ::vast::abi::PrologueOp(this->::mx::ir::Operation::op_);
}

gap::generator<::mx::ir::Result> PrologueOp::results(void) const & {
  auto range = underlying_repr().getResults();
  for (auto val : range) {
    co_yield ::mx::ir::Result(module_, val.getAsOpaquePointer());
  }
}

::mx::ir::Region PrologueOp::body(void) const {
  auto &val = underlying_repr().getBody();
  return ::mx::ir::Region(module_, val);
}

std::optional<RetDirectOp> RetDirectOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::ABI_RET_DIRECT) {
    return reinterpret_cast<const RetDirectOp &>(that);
  }
  return std::nullopt;
}

std::optional<RetDirectOp> RetDirectOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::vast::abi::RetDirectOp RetDirectOp::underlying_repr(void) const noexcept {
  return ::vast::abi::RetDirectOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value RetDirectOp::value(void) const {
  auto val = underlying_repr().getValue();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

gap::generator<::mx::ir::Result> RetDirectOp::result(void) const & {
  auto range = underlying_repr().getResult();
  for (auto val : range) {
    co_yield ::mx::ir::Result(module_, val.getAsOpaquePointer());
  }
}

std::optional<YieldOp> YieldOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::ABI_YIELD) {
    return reinterpret_cast<const YieldOp &>(that);
  }
  return std::nullopt;
}

std::optional<YieldOp> YieldOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::vast::abi::YieldOp YieldOp::underlying_repr(void) const noexcept {
  return ::vast::abi::YieldOp(this->::mx::ir::Operation::op_);
}

gap::generator<::mx::ir::Operand> YieldOp::values(void) const & {
  auto range = underlying_repr().getValues();
  for (auto val : range) {
    co_yield ::mx::ir::Operand(module_, val.getAsOpaquePointer());
  }
}

gap::generator<::mx::ir::Result> YieldOp::result(void) const & {
  auto range = underlying_repr().getResult();
  for (auto val : range) {
    co_yield ::mx::ir::Result(module_, val.getAsOpaquePointer());
  }
}

}  // namespace mx::ir::abi
