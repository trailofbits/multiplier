// Copyright (c) 2023-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/IR/LowLevel/Operation.h>

#include <multiplier/IR/Attribute.h>
#include <multiplier/IR/Block.h>
#include <multiplier/IR/Region.h>
#include <multiplier/IR/Type.h>

#include <ios>
#include <string>

#include <mlir/Dialect/LLVMIR/LLVMDialect.h>
#include <vast/Dialect/Dialects.hpp>
#include <vast/Dialect/ABI/ABIOps.hpp>
#include <vast/Dialect/HighLevel/HighLevelOps.hpp>
#include <vast/Dialect/LowLevel/LowLevelOps.hpp>

namespace mx::ir::ll {
std::optional<Operation> Operation::from(const ::mx::ir::Operation &that) {
  if (IsLowLevelOperationKind(that.kind())) {
    return reinterpret_cast<const Operation &>(that);
  }
  return std::nullopt;
}

std::optional<AllocaOp> AllocaOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LL_ALLOCA) {
    return reinterpret_cast<const AllocaOp &>(that);
  }
  return std::nullopt;
}

std::optional<AllocaOp> AllocaOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::vast::ll::Alloca AllocaOp::underlying_repr(void) const noexcept {
  return ::vast::ll::Alloca(this->::mx::ir::Operation::op_);
}

::mx::ir::Value AllocaOp::result(void) const {
  auto val = underlying_repr().getResult();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<ArgAllocaOp> ArgAllocaOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LL_ARG_ALLOCA) {
    return reinterpret_cast<const ArgAllocaOp &>(that);
  }
  return std::nullopt;
}

std::optional<ArgAllocaOp> ArgAllocaOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::vast::ll::ArgAlloca ArgAllocaOp::underlying_repr(void) const noexcept {
  return ::vast::ll::ArgAlloca(this->::mx::ir::Operation::op_);
}

::mx::ir::Value ArgAllocaOp::fn_arg(void) const {
  auto val = underlying_repr().getFnArg();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value ArgAllocaOp::result(void) const {
  auto val = underlying_repr().getResult();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<BrOp> BrOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LL_BR) {
    return reinterpret_cast<const BrOp &>(that);
  }
  return std::nullopt;
}

std::optional<BrOp> BrOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::vast::ll::Br BrOp::underlying_repr(void) const noexcept {
  return ::vast::ll::Br(this->::mx::ir::Operation::op_);
}

gap::generator<::mx::ir::Operand> BrOp::operands(void) const & {
  auto range = underlying_repr().getOperands();
  for (auto val : range) {
    co_yield ::mx::ir::Operand(module_, val.getAsOpaquePointer());
  }
}

std::optional<ConcatOp> ConcatOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LL_CONCAT) {
    return reinterpret_cast<const ConcatOp &>(that);
  }
  return std::nullopt;
}

std::optional<ConcatOp> ConcatOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::vast::ll::Concat ConcatOp::underlying_repr(void) const noexcept {
  return ::vast::ll::Concat(this->::mx::ir::Operation::op_);
}

gap::generator<::mx::ir::Operand> ConcatOp::arguments(void) const & {
  auto range = underlying_repr().getArgs();
  for (auto val : range) {
    co_yield ::mx::ir::Operand(module_, val.getAsOpaquePointer());
  }
}

::mx::ir::Value ConcatOp::result(void) const {
  auto val = underlying_repr().getResult();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<CondBrOp> CondBrOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LL_COND_BR) {
    return reinterpret_cast<const CondBrOp &>(that);
  }
  return std::nullopt;
}

std::optional<CondBrOp> CondBrOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::vast::ll::CondBr CondBrOp::underlying_repr(void) const noexcept {
  return ::vast::ll::CondBr(this->::mx::ir::Operation::op_);
}

::mx::ir::Value CondBrOp::cond(void) const {
  auto val = underlying_repr().getCond();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

gap::generator<::mx::ir::Operand> CondBrOp::true_operands(void) const & {
  auto range = underlying_repr().getTrueOperands();
  for (auto val : range) {
    co_yield ::mx::ir::Operand(module_, val.getAsOpaquePointer());
  }
}

gap::generator<::mx::ir::Operand> CondBrOp::false_operands(void) const & {
  auto range = underlying_repr().getFalseOperands();
  for (auto val : range) {
    co_yield ::mx::ir::Operand(module_, val.getAsOpaquePointer());
  }
}

std::optional<CondScopeRetOp> CondScopeRetOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LL_COND_SCOPE_RET) {
    return reinterpret_cast<const CondScopeRetOp &>(that);
  }
  return std::nullopt;
}

std::optional<CondScopeRetOp> CondScopeRetOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::vast::ll::CondScopeRet CondScopeRetOp::underlying_repr(void) const noexcept {
  return ::vast::ll::CondScopeRet(this->::mx::ir::Operation::op_);
}

::mx::ir::Value CondScopeRetOp::cond(void) const {
  auto val = underlying_repr().getCond();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

gap::generator<::mx::ir::Operand> CondScopeRetOp::dest_operands(void) const & {
  auto range = underlying_repr().getDestOperands();
  for (auto val : range) {
    co_yield ::mx::ir::Operand(module_, val.getAsOpaquePointer());
  }
}

std::optional<ExtractOp> ExtractOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LL_EXTRACT) {
    return reinterpret_cast<const ExtractOp &>(that);
  }
  return std::nullopt;
}

std::optional<ExtractOp> ExtractOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::vast::ll::Extract ExtractOp::underlying_repr(void) const noexcept {
  return ::vast::ll::Extract(this->::mx::ir::Operation::op_);
}

::mx::ir::Value ExtractOp::argument(void) const {
  auto val = underlying_repr().getArg();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value ExtractOp::result(void) const {
  auto val = underlying_repr().getResult();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::size_t ExtractOp::size(void) const {
  auto val = underlying_repr().size();
  return val;
}

std::optional<InitializeVarOp> InitializeVarOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LL_INITIALIZE) {
    return reinterpret_cast<const InitializeVarOp &>(that);
  }
  return std::nullopt;
}

std::optional<InitializeVarOp> InitializeVarOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::vast::ll::InitializeVar InitializeVarOp::underlying_repr(void) const noexcept {
  return ::vast::ll::InitializeVar(this->::mx::ir::Operation::op_);
}

::mx::ir::Value InitializeVarOp::var(void) const {
  auto val = underlying_repr().getVar();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

gap::generator<::mx::ir::Operand> InitializeVarOp::elements(void) const & {
  auto range = underlying_repr().getElements();
  for (auto val : range) {
    co_yield ::mx::ir::Operand(module_, val.getAsOpaquePointer());
  }
}

::mx::ir::Value InitializeVarOp::result(void) const {
  auto val = underlying_repr().getResult();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<InlineScopeOp> InlineScopeOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LL_INLINE_SCOPE) {
    return reinterpret_cast<const InlineScopeOp &>(that);
  }
  return std::nullopt;
}

std::optional<InlineScopeOp> InlineScopeOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::vast::ll::InlineScope InlineScopeOp::underlying_repr(void) const noexcept {
  return ::vast::ll::InlineScope(this->::mx::ir::Operation::op_);
}

::mx::ir::Region InlineScopeOp::body(void) const {
  auto &val = underlying_repr().getBody();
  return ::mx::ir::Region(module_, val);
}

std::optional<LoadOp> LoadOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LL_LOAD) {
    return reinterpret_cast<const LoadOp &>(that);
  }
  return std::nullopt;
}

std::optional<LoadOp> LoadOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::vast::ll::Load LoadOp::underlying_repr(void) const noexcept {
  return ::vast::ll::Load(this->::mx::ir::Operation::op_);
}

::mx::ir::Value LoadOp::result(void) const {
  auto val = underlying_repr().getResult();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

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

::vast::ll::FuncOp FuncOp::underlying_repr(void) const noexcept {
  return ::vast::ll::FuncOp(this->::mx::ir::Operation::op_);
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

std::optional<StructGEPOp> StructGEPOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LL_GEP) {
    return reinterpret_cast<const StructGEPOp &>(that);
  }
  return std::nullopt;
}

std::optional<StructGEPOp> StructGEPOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::vast::ll::StructGEPOp StructGEPOp::underlying_repr(void) const noexcept {
  return ::vast::ll::StructGEPOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value StructGEPOp::record(void) const {
  auto val = underlying_repr().getRecord();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value StructGEPOp::element(void) const {
  auto val = underlying_repr().getElement();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

uint32_t StructGEPOp::idx(void) const {
  auto val = underlying_repr().getIdx();
  return val;
}

std::string_view StructGEPOp::field(void) const {
  auto val = underlying_repr().getField();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return {};
  }
}

std::optional<ReturnOp> ReturnOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LL_RETURN) {
    return reinterpret_cast<const ReturnOp &>(that);
  }
  return std::nullopt;
}

std::optional<ReturnOp> ReturnOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::vast::ll::ReturnOp ReturnOp::underlying_repr(void) const noexcept {
  return ::vast::ll::ReturnOp(this->::mx::ir::Operation::op_);
}

gap::generator<::mx::ir::Operand> ReturnOp::result(void) const & {
  auto range = underlying_repr().getResult();
  for (auto val : range) {
    co_yield ::mx::ir::Operand(module_, val.getAsOpaquePointer());
  }
}

std::optional<ScopeOp> ScopeOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LL_SCOPE) {
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

::vast::ll::Scope ScopeOp::underlying_repr(void) const noexcept {
  return ::vast::ll::Scope(this->::mx::ir::Operation::op_);
}

::mx::ir::Region ScopeOp::body(void) const {
  auto &val = underlying_repr().getBody();
  return ::mx::ir::Region(module_, val);
}

std::optional<ScopeRecurseOp> ScopeRecurseOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LL_SCOPE_RECURSE) {
    return reinterpret_cast<const ScopeRecurseOp &>(that);
  }
  return std::nullopt;
}

std::optional<ScopeRecurseOp> ScopeRecurseOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::vast::ll::ScopeRecurse ScopeRecurseOp::underlying_repr(void) const noexcept {
  return ::vast::ll::ScopeRecurse(this->::mx::ir::Operation::op_);
}

std::optional<ScopeRetOp> ScopeRetOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LL_SCOPE_RET) {
    return reinterpret_cast<const ScopeRetOp &>(that);
  }
  return std::nullopt;
}

std::optional<ScopeRetOp> ScopeRetOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::vast::ll::ScopeRet ScopeRetOp::underlying_repr(void) const noexcept {
  return ::vast::ll::ScopeRet(this->::mx::ir::Operation::op_);
}

std::optional<StoreOp> StoreOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LL_STORE) {
    return reinterpret_cast<const StoreOp &>(that);
  }
  return std::nullopt;
}

std::optional<StoreOp> StoreOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::vast::ll::Store StoreOp::underlying_repr(void) const noexcept {
  return ::vast::ll::Store(this->::mx::ir::Operation::op_);
}

::mx::ir::Value StoreOp::value(void) const {
  auto val = underlying_repr().getVal();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<SubscriptOp> SubscriptOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LL_SUBSCRIPT) {
    return reinterpret_cast<const SubscriptOp &>(that);
  }
  return std::nullopt;
}

std::optional<SubscriptOp> SubscriptOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::vast::ll::Subscript SubscriptOp::underlying_repr(void) const noexcept {
  return ::vast::ll::Subscript(this->::mx::ir::Operation::op_);
}

::mx::ir::Value SubscriptOp::array(void) const {
  auto val = underlying_repr().getArray();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value SubscriptOp::index(void) const {
  auto val = underlying_repr().getIndex();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value SubscriptOp::result(void) const {
  auto val = underlying_repr().getResult();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<UninitializedVarOp> UninitializedVarOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LL_UNINITIALIZED_VAR) {
    return reinterpret_cast<const UninitializedVarOp &>(that);
  }
  return std::nullopt;
}

std::optional<UninitializedVarOp> UninitializedVarOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::vast::ll::UninitializedVar UninitializedVarOp::underlying_repr(void) const noexcept {
  return ::vast::ll::UninitializedVar(this->::mx::ir::Operation::op_);
}

::mx::ir::Value UninitializedVarOp::result(void) const {
  auto val = underlying_repr().getResult();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

}  // namespace mx::ir::ll
