// Copyright (c) 2023-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/IR/HighLevel/Operation.h>

#include <multiplier/IR/Attribute.h>
#include <multiplier/IR/Block.h>
#include <multiplier/IR/Region.h>
#include <multiplier/IR/Type.h>

#include <ios>
#include <string>

#include <mlir/Dialect/LLVMIR/LLVMDialect.h>
#include <mlir/Dialect/MemRef/IR/MemRef.h>
#include <vast/Dialect/Dialects.hpp>
#include <vast/Dialect/ABI/ABIOps.hpp>
#include <vast/Dialect/HighLevel/HighLevelOps.hpp>

namespace mx::ir::hl {
std::optional<Operation> Operation::from(const ::mx::ir::Operation &that) {
  if (IsHighLevelOperationKind(that.kind())) {
    return reinterpret_cast<const Operation &>(that);
  }
  return std::nullopt;
}

std::optional<AccessSpecifierOp> AccessSpecifierOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::HL_ACCESS) {
    return reinterpret_cast<const AccessSpecifierOp &>(that);
  }
  return std::nullopt;
}

std::optional<AccessSpecifierOp> AccessSpecifierOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::vast::hl::AccessSpecifierOp AccessSpecifierOp::underlying_repr(void) const noexcept {
  return ::vast::hl::AccessSpecifierOp(this->::mx::ir::Operation::op_);
}

std::optional<AddFAssignOp> AddFAssignOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::HL_ASSIGN_FADD) {
    return reinterpret_cast<const AddFAssignOp &>(that);
  }
  return std::nullopt;
}

std::optional<AddFAssignOp> AddFAssignOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::vast::hl::AddFAssignOp AddFAssignOp::underlying_repr(void) const noexcept {
  return ::vast::hl::AddFAssignOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value AddFAssignOp::source(void) const {
  auto val = underlying_repr().getSrc();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value AddFAssignOp::destination(void) const {
  auto val = underlying_repr().getDst();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value AddFAssignOp::result(void) const {
  auto val = underlying_repr().getResult();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<AddFOp> AddFOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::HL_FADD) {
    return reinterpret_cast<const AddFOp &>(that);
  }
  return std::nullopt;
}

std::optional<AddFOp> AddFOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::vast::hl::AddFOp AddFOp::underlying_repr(void) const noexcept {
  return ::vast::hl::AddFOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value AddFOp::left(void) const {
  auto val = underlying_repr().getLhs();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value AddFOp::right(void) const {
  auto val = underlying_repr().getRhs();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value AddFOp::result(void) const {
  auto val = underlying_repr().getResult();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<AddIAssignOp> AddIAssignOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::HL_ASSIGN_ADD) {
    return reinterpret_cast<const AddIAssignOp &>(that);
  }
  return std::nullopt;
}

std::optional<AddIAssignOp> AddIAssignOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::vast::hl::AddIAssignOp AddIAssignOp::underlying_repr(void) const noexcept {
  return ::vast::hl::AddIAssignOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value AddIAssignOp::source(void) const {
  auto val = underlying_repr().getSrc();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value AddIAssignOp::destination(void) const {
  auto val = underlying_repr().getDst();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value AddIAssignOp::result(void) const {
  auto val = underlying_repr().getResult();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<AddIOp> AddIOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::HL_ADD) {
    return reinterpret_cast<const AddIOp &>(that);
  }
  return std::nullopt;
}

std::optional<AddIOp> AddIOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::vast::hl::AddIOp AddIOp::underlying_repr(void) const noexcept {
  return ::vast::hl::AddIOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value AddIOp::left(void) const {
  auto val = underlying_repr().getLhs();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value AddIOp::right(void) const {
  auto val = underlying_repr().getRhs();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value AddIOp::result(void) const {
  auto val = underlying_repr().getResult();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<AddrLabelExprOp> AddrLabelExprOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::HL_LABELADDR) {
    return reinterpret_cast<const AddrLabelExprOp &>(that);
  }
  return std::nullopt;
}

std::optional<AddrLabelExprOp> AddrLabelExprOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::vast::hl::AddrLabelExpr AddrLabelExprOp::underlying_repr(void) const noexcept {
  return ::vast::hl::AddrLabelExpr(this->::mx::ir::Operation::op_);
}

::mx::ir::Value AddrLabelExprOp::label(void) const {
  auto val = underlying_repr().getLabel();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value AddrLabelExprOp::result(void) const {
  auto val = underlying_repr().getResult();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<AddressOfOp> AddressOfOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::HL_ADDRESSOF) {
    return reinterpret_cast<const AddressOfOp &>(that);
  }
  return std::nullopt;
}

std::optional<AddressOfOp> AddressOfOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::vast::hl::AddressOf AddressOfOp::underlying_repr(void) const noexcept {
  return ::vast::hl::AddressOf(this->::mx::ir::Operation::op_);
}

::mx::ir::Value AddressOfOp::value(void) const {
  auto val = underlying_repr().getValue();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value AddressOfOp::result(void) const {
  auto val = underlying_repr().getResult();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<AlignOfExprOp> AlignOfExprOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::HL_ALIGNOF_EXPR) {
    return reinterpret_cast<const AlignOfExprOp &>(that);
  }
  return std::nullopt;
}

std::optional<AlignOfExprOp> AlignOfExprOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::vast::hl::AlignOfExprOp AlignOfExprOp::underlying_repr(void) const noexcept {
  return ::vast::hl::AlignOfExprOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value AlignOfExprOp::result(void) const {
  auto val = underlying_repr().getResult();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Region AlignOfExprOp::expression(void) const {
  auto &val = underlying_repr().getExpr();
  return ::mx::ir::Region(module_, val);
}

std::optional<AlignOfTypeOp> AlignOfTypeOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::HL_ALIGNOF_TYPE) {
    return reinterpret_cast<const AlignOfTypeOp &>(that);
  }
  return std::nullopt;
}

std::optional<AlignOfTypeOp> AlignOfTypeOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::vast::hl::AlignOfTypeOp AlignOfTypeOp::underlying_repr(void) const noexcept {
  return ::vast::hl::AlignOfTypeOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value AlignOfTypeOp::result(void) const {
  auto val = underlying_repr().getResult();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Type AlignOfTypeOp::argument(void) const {
  auto mlir_type = underlying_repr().getArg();
  return ::mx::ir::Type(
      mlir_type.getContext(),
      reinterpret_cast<const mlir::TypeStorage *>(
          mlir_type.getAsOpaquePointer()));
}

std::optional<AsmOp> AsmOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::HL_ASM) {
    return reinterpret_cast<const AsmOp &>(that);
  }
  return std::nullopt;
}

std::optional<AsmOp> AsmOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::vast::hl::AsmOp AsmOp::underlying_repr(void) const noexcept {
  return ::vast::hl::AsmOp(this->::mx::ir::Operation::op_);
}

gap::generator<::mx::ir::Operand> AsmOp::asm_outputs(void) const & {
  auto range = underlying_repr().getAsmOutputs();
  for (auto val : range) {
    co_yield ::mx::ir::Operand(module_, val.getAsOpaquePointer());
  }
}

gap::generator<::mx::ir::Operand> AsmOp::asm_inputs(void) const & {
  auto range = underlying_repr().getAsmInputs();
  for (auto val : range) {
    co_yield ::mx::ir::Operand(module_, val.getAsOpaquePointer());
  }
}

gap::generator<::mx::ir::Operand> AsmOp::labels(void) const & {
  auto range = underlying_repr().getLabels();
  for (auto val : range) {
    co_yield ::mx::ir::Operand(module_, val.getAsOpaquePointer());
  }
}

std::string_view AsmOp::asm_template(void) const {
  auto val = underlying_repr().getAsmTemplate();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return {};
  }
}

bool AsmOp::is_volatile(void) const {
  auto val = underlying_repr().getIsVolatile();
  return val;
}

bool AsmOp::has_goto(void) const {
  auto val = underlying_repr().getHasGoto();
  return val;
}

std::optional<AssignOp> AssignOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::HL_ASSIGN) {
    return reinterpret_cast<const AssignOp &>(that);
  }
  return std::nullopt;
}

std::optional<AssignOp> AssignOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::vast::hl::AssignOp AssignOp::underlying_repr(void) const noexcept {
  return ::vast::hl::AssignOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value AssignOp::source(void) const {
  auto val = underlying_repr().getSrc();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value AssignOp::destination(void) const {
  auto val = underlying_repr().getDst();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value AssignOp::result(void) const {
  auto val = underlying_repr().getResult();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<AttributedStmtOp> AttributedStmtOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::HL_ATTRIBUTED_STMT) {
    return reinterpret_cast<const AttributedStmtOp &>(that);
  }
  return std::nullopt;
}

std::optional<AttributedStmtOp> AttributedStmtOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::vast::hl::AttributedStmt AttributedStmtOp::underlying_repr(void) const noexcept {
  return ::vast::hl::AttributedStmt(this->::mx::ir::Operation::op_);
}

::mx::ir::Region AttributedStmtOp::body(void) const {
  auto &val = underlying_repr().getBody();
  return ::mx::ir::Region(module_, val);
}

std::optional<BinAShrAssignOp> BinAShrAssignOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::HL_ASSIGN_BIN_ASHR) {
    return reinterpret_cast<const BinAShrAssignOp &>(that);
  }
  return std::nullopt;
}

std::optional<BinAShrAssignOp> BinAShrAssignOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::vast::hl::BinAShrAssignOp BinAShrAssignOp::underlying_repr(void) const noexcept {
  return ::vast::hl::BinAShrAssignOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value BinAShrAssignOp::source(void) const {
  auto val = underlying_repr().getSrc();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value BinAShrAssignOp::destination(void) const {
  auto val = underlying_repr().getDst();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value BinAShrAssignOp::result(void) const {
  auto val = underlying_repr().getResult();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<BinAShrOp> BinAShrOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::HL_BIN_ASHR) {
    return reinterpret_cast<const BinAShrOp &>(that);
  }
  return std::nullopt;
}

std::optional<BinAShrOp> BinAShrOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::vast::hl::BinAShrOp BinAShrOp::underlying_repr(void) const noexcept {
  return ::vast::hl::BinAShrOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value BinAShrOp::left(void) const {
  auto val = underlying_repr().getLhs();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value BinAShrOp::right(void) const {
  auto val = underlying_repr().getRhs();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value BinAShrOp::result(void) const {
  auto val = underlying_repr().getResult();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<BinAndAssignOp> BinAndAssignOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::HL_ASSIGN_BIN_AND) {
    return reinterpret_cast<const BinAndAssignOp &>(that);
  }
  return std::nullopt;
}

std::optional<BinAndAssignOp> BinAndAssignOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::vast::hl::BinAndAssignOp BinAndAssignOp::underlying_repr(void) const noexcept {
  return ::vast::hl::BinAndAssignOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value BinAndAssignOp::source(void) const {
  auto val = underlying_repr().getSrc();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value BinAndAssignOp::destination(void) const {
  auto val = underlying_repr().getDst();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value BinAndAssignOp::result(void) const {
  auto val = underlying_repr().getResult();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<BinAndOp> BinAndOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::HL_BIN_AND) {
    return reinterpret_cast<const BinAndOp &>(that);
  }
  return std::nullopt;
}

std::optional<BinAndOp> BinAndOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::vast::hl::BinAndOp BinAndOp::underlying_repr(void) const noexcept {
  return ::vast::hl::BinAndOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value BinAndOp::left(void) const {
  auto val = underlying_repr().getLhs();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value BinAndOp::right(void) const {
  auto val = underlying_repr().getRhs();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value BinAndOp::result(void) const {
  auto val = underlying_repr().getResult();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<BinCommaOp> BinCommaOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::HL_BIN_COMMA) {
    return reinterpret_cast<const BinCommaOp &>(that);
  }
  return std::nullopt;
}

std::optional<BinCommaOp> BinCommaOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::vast::hl::BinComma BinCommaOp::underlying_repr(void) const noexcept {
  return ::vast::hl::BinComma(this->::mx::ir::Operation::op_);
}

::mx::ir::Value BinCommaOp::left(void) const {
  auto val = underlying_repr().getLhs();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value BinCommaOp::right(void) const {
  auto val = underlying_repr().getRhs();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value BinCommaOp::result(void) const {
  auto val = underlying_repr().getResult();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<BinLAndOp> BinLAndOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::HL_BIN_LAND) {
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

::vast::hl::BinLAndOp BinLAndOp::underlying_repr(void) const noexcept {
  return ::vast::hl::BinLAndOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value BinLAndOp::result(void) const {
  auto val = underlying_repr().getResult();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Region BinLAndOp::left(void) const {
  auto &val = underlying_repr().getLhs();
  return ::mx::ir::Region(module_, val);
}

::mx::ir::Region BinLAndOp::right(void) const {
  auto &val = underlying_repr().getRhs();
  return ::mx::ir::Region(module_, val);
}

std::optional<BinLOrOp> BinLOrOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::HL_BIN_LOR) {
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

::vast::hl::BinLOrOp BinLOrOp::underlying_repr(void) const noexcept {
  return ::vast::hl::BinLOrOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value BinLOrOp::result(void) const {
  auto val = underlying_repr().getResult();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Region BinLOrOp::left(void) const {
  auto &val = underlying_repr().getLhs();
  return ::mx::ir::Region(module_, val);
}

::mx::ir::Region BinLOrOp::right(void) const {
  auto &val = underlying_repr().getRhs();
  return ::mx::ir::Region(module_, val);
}

std::optional<BinLShrAssignOp> BinLShrAssignOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::HL_ASSIGN_BIN_LSHR) {
    return reinterpret_cast<const BinLShrAssignOp &>(that);
  }
  return std::nullopt;
}

std::optional<BinLShrAssignOp> BinLShrAssignOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::vast::hl::BinLShrAssignOp BinLShrAssignOp::underlying_repr(void) const noexcept {
  return ::vast::hl::BinLShrAssignOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value BinLShrAssignOp::source(void) const {
  auto val = underlying_repr().getSrc();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value BinLShrAssignOp::destination(void) const {
  auto val = underlying_repr().getDst();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value BinLShrAssignOp::result(void) const {
  auto val = underlying_repr().getResult();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<BinLShrOp> BinLShrOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::HL_BIN_LSHR) {
    return reinterpret_cast<const BinLShrOp &>(that);
  }
  return std::nullopt;
}

std::optional<BinLShrOp> BinLShrOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::vast::hl::BinLShrOp BinLShrOp::underlying_repr(void) const noexcept {
  return ::vast::hl::BinLShrOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value BinLShrOp::left(void) const {
  auto val = underlying_repr().getLhs();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value BinLShrOp::right(void) const {
  auto val = underlying_repr().getRhs();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value BinLShrOp::result(void) const {
  auto val = underlying_repr().getResult();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<BinOrAssignOp> BinOrAssignOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::HL_ASSIGN_BIN_OR) {
    return reinterpret_cast<const BinOrAssignOp &>(that);
  }
  return std::nullopt;
}

std::optional<BinOrAssignOp> BinOrAssignOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::vast::hl::BinOrAssignOp BinOrAssignOp::underlying_repr(void) const noexcept {
  return ::vast::hl::BinOrAssignOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value BinOrAssignOp::source(void) const {
  auto val = underlying_repr().getSrc();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value BinOrAssignOp::destination(void) const {
  auto val = underlying_repr().getDst();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value BinOrAssignOp::result(void) const {
  auto val = underlying_repr().getResult();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<BinOrOp> BinOrOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::HL_BIN_OR) {
    return reinterpret_cast<const BinOrOp &>(that);
  }
  return std::nullopt;
}

std::optional<BinOrOp> BinOrOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::vast::hl::BinOrOp BinOrOp::underlying_repr(void) const noexcept {
  return ::vast::hl::BinOrOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value BinOrOp::left(void) const {
  auto val = underlying_repr().getLhs();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value BinOrOp::right(void) const {
  auto val = underlying_repr().getRhs();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value BinOrOp::result(void) const {
  auto val = underlying_repr().getResult();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<BinShlAssignOp> BinShlAssignOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::HL_ASSIGN_BIN_SHL) {
    return reinterpret_cast<const BinShlAssignOp &>(that);
  }
  return std::nullopt;
}

std::optional<BinShlAssignOp> BinShlAssignOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::vast::hl::BinShlAssignOp BinShlAssignOp::underlying_repr(void) const noexcept {
  return ::vast::hl::BinShlAssignOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value BinShlAssignOp::source(void) const {
  auto val = underlying_repr().getSrc();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value BinShlAssignOp::destination(void) const {
  auto val = underlying_repr().getDst();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value BinShlAssignOp::result(void) const {
  auto val = underlying_repr().getResult();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<BinShlOp> BinShlOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::HL_BIN_SHL) {
    return reinterpret_cast<const BinShlOp &>(that);
  }
  return std::nullopt;
}

std::optional<BinShlOp> BinShlOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::vast::hl::BinShlOp BinShlOp::underlying_repr(void) const noexcept {
  return ::vast::hl::BinShlOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value BinShlOp::left(void) const {
  auto val = underlying_repr().getLhs();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value BinShlOp::right(void) const {
  auto val = underlying_repr().getRhs();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value BinShlOp::result(void) const {
  auto val = underlying_repr().getResult();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<BinXorAssignOp> BinXorAssignOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::HL_ASSIGN_BIN_XOR) {
    return reinterpret_cast<const BinXorAssignOp &>(that);
  }
  return std::nullopt;
}

std::optional<BinXorAssignOp> BinXorAssignOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::vast::hl::BinXorAssignOp BinXorAssignOp::underlying_repr(void) const noexcept {
  return ::vast::hl::BinXorAssignOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value BinXorAssignOp::source(void) const {
  auto val = underlying_repr().getSrc();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value BinXorAssignOp::destination(void) const {
  auto val = underlying_repr().getDst();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value BinXorAssignOp::result(void) const {
  auto val = underlying_repr().getResult();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<BinXorOp> BinXorOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::HL_BIN_XOR) {
    return reinterpret_cast<const BinXorOp &>(that);
  }
  return std::nullopt;
}

std::optional<BinXorOp> BinXorOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::vast::hl::BinXorOp BinXorOp::underlying_repr(void) const noexcept {
  return ::vast::hl::BinXorOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value BinXorOp::left(void) const {
  auto val = underlying_repr().getLhs();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value BinXorOp::right(void) const {
  auto val = underlying_repr().getRhs();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value BinXorOp::result(void) const {
  auto val = underlying_repr().getResult();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<BinaryCondOp> BinaryCondOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::HL_BINARY_COND) {
    return reinterpret_cast<const BinaryCondOp &>(that);
  }
  return std::nullopt;
}

std::optional<BinaryCondOp> BinaryCondOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::vast::hl::BinaryCondOp BinaryCondOp::underlying_repr(void) const noexcept {
  return ::vast::hl::BinaryCondOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value BinaryCondOp::result(void) const {
  auto val = underlying_repr().getResult();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<::mx::ir::Region> BinaryCondOp::common_region(void) const {
  decltype(auto) opt_val = underlying_repr().getCommonRegion();
  if (opt_val.empty()) {
    return std::nullopt;
  }
  auto &val = opt_val;
  return ::mx::ir::Region(module_, val);
}

::mx::ir::Region BinaryCondOp::condition_region(void) const {
  auto &val = underlying_repr().getCondRegion();
  return ::mx::ir::Region(module_, val);
}

::mx::ir::Region BinaryCondOp::then_region(void) const {
  auto &val = underlying_repr().getThenRegion();
  return ::mx::ir::Region(module_, val);
}

::mx::ir::Region BinaryCondOp::else_region(void) const {
  auto &val = underlying_repr().getElseRegion();
  return ::mx::ir::Region(module_, val);
}

std::optional<BreakOp> BreakOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::HL_BREAK) {
    return reinterpret_cast<const BreakOp &>(that);
  }
  return std::nullopt;
}

std::optional<BreakOp> BreakOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::vast::hl::BreakOp BreakOp::underlying_repr(void) const noexcept {
  return ::vast::hl::BreakOp(this->::mx::ir::Operation::op_);
}

std::optional<BuiltinBitCastOp> BuiltinBitCastOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::HL_BUILTIN_BITCAST) {
    return reinterpret_cast<const BuiltinBitCastOp &>(that);
  }
  return std::nullopt;
}

std::optional<BuiltinBitCastOp> BuiltinBitCastOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::vast::hl::BuiltinBitCastOp BuiltinBitCastOp::underlying_repr(void) const noexcept {
  return ::vast::hl::BuiltinBitCastOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value BuiltinBitCastOp::value(void) const {
  auto val = underlying_repr().getValue();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value BuiltinBitCastOp::result(void) const {
  auto val = underlying_repr().getResult();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<BuiltinTypesCompatiblePOp> BuiltinTypesCompatiblePOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::HL_BUILTIN_TYPES_COMPATIBLE_P_TYPE) {
    return reinterpret_cast<const BuiltinTypesCompatiblePOp &>(that);
  }
  return std::nullopt;
}

std::optional<BuiltinTypesCompatiblePOp> BuiltinTypesCompatiblePOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::vast::hl::BuiltinTypesCompatiblePOp BuiltinTypesCompatiblePOp::underlying_repr(void) const noexcept {
  return ::vast::hl::BuiltinTypesCompatiblePOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value BuiltinTypesCompatiblePOp::result(void) const {
  auto val = underlying_repr().getResult();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Type BuiltinTypesCompatiblePOp::type1(void) const {
  auto mlir_type = underlying_repr().getType1();
  return ::mx::ir::Type(
      mlir_type.getContext(),
      reinterpret_cast<const mlir::TypeStorage *>(
          mlir_type.getAsOpaquePointer()));
}

::mx::ir::Type BuiltinTypesCompatiblePOp::type2(void) const {
  auto mlir_type = underlying_repr().getType2();
  return ::mx::ir::Type(
      mlir_type.getContext(),
      reinterpret_cast<const mlir::TypeStorage *>(
          mlir_type.getAsOpaquePointer()));
}

bool BuiltinTypesCompatiblePOp::compatible(void) const {
  auto val = underlying_repr().getCompatible();
  return val;
}

gap::generator<::mx::ir::Type> BuiltinTypesCompatiblePOp::arguments(void) const & {
  auto range = underlying_repr().getArgs();
  for (auto el_ty : range) {
    co_yield ::mx::ir::Type(
        el_ty.getContext(),
        reinterpret_cast<const mlir::TypeStorage *>(
            el_ty.getAsOpaquePointer()));
  }
}

std::optional<bool> BuiltinTypesCompatiblePOp::value(void) const {
  auto opt_val = underlying_repr().getValue();
  if (!opt_val) {
    return std::nullopt;
  }
  auto &val = opt_val.value();
  return val;
}

std::optional<CStyleCastOp> CStyleCastOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::HL_CSTYLE_CAST) {
    return reinterpret_cast<const CStyleCastOp &>(that);
  }
  return std::nullopt;
}

std::optional<CStyleCastOp> CStyleCastOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::vast::hl::CStyleCastOp CStyleCastOp::underlying_repr(void) const noexcept {
  return ::vast::hl::CStyleCastOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value CStyleCastOp::value(void) const {
  auto val = underlying_repr().getValue();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value CStyleCastOp::result(void) const {
  auto val = underlying_repr().getResult();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<CallOp> CallOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::HL_CALL) {
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

::vast::hl::CallOp CallOp::underlying_repr(void) const noexcept {
  return ::vast::hl::CallOp(this->::mx::ir::Operation::op_);
}

gap::generator<::mx::ir::Operand> CallOp::arg_operands(void) const & {
  auto range = underlying_repr().getArgOperands();
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

std::optional<CaseOp> CaseOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::HL_CASE) {
    return reinterpret_cast<const CaseOp &>(that);
  }
  return std::nullopt;
}

std::optional<CaseOp> CaseOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::vast::hl::CaseOp CaseOp::underlying_repr(void) const noexcept {
  return ::vast::hl::CaseOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Region CaseOp::left(void) const {
  auto &val = underlying_repr().getLhs();
  return ::mx::ir::Region(module_, val);
}

std::optional<::mx::ir::Region> CaseOp::body(void) const {
  decltype(auto) opt_val = underlying_repr().getBody();
  if (opt_val.empty()) {
    return std::nullopt;
  }
  auto &val = opt_val;
  return ::mx::ir::Region(module_, val);
}

std::optional<ChooseExprOp> ChooseExprOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::HL_CHOOSE_EXPR) {
    return reinterpret_cast<const ChooseExprOp &>(that);
  }
  return std::nullopt;
}

std::optional<ChooseExprOp> ChooseExprOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::vast::hl::ChooseExprOp ChooseExprOp::underlying_repr(void) const noexcept {
  return ::vast::hl::ChooseExprOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value ChooseExprOp::result(void) const {
  auto val = underlying_repr().getResult();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Region ChooseExprOp::condition_region(void) const {
  auto &val = underlying_repr().getCondRegion();
  return ::mx::ir::Region(module_, val);
}

::mx::ir::Region ChooseExprOp::then_region(void) const {
  auto &val = underlying_repr().getThenRegion();
  return ::mx::ir::Region(module_, val);
}

::mx::ir::Region ChooseExprOp::else_region(void) const {
  auto &val = underlying_repr().getElseRegion();
  return ::mx::ir::Region(module_, val);
}

std::optional<bool> ChooseExprOp::cond_true(void) const {
  auto opt_val = underlying_repr().getCondTrue();
  if (!opt_val) {
    return std::nullopt;
  }
  auto &val = opt_val.value();
  return val;
}

std::optional<bool> ChooseExprOp::is_condition_true(void) const {
  auto opt_val = underlying_repr().isConditionTrue();
  if (!opt_val) {
    return std::nullopt;
  }
  auto &val = opt_val.value();
  return val;
}

bool ChooseExprOp::is_condition_dependent(void) const {
  auto val = underlying_repr().isConditionDependent();
  return val;
}

std::optional<ClassDeclOp> ClassDeclOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::HL_CLASS) {
    return reinterpret_cast<const ClassDeclOp &>(that);
  }
  return std::nullopt;
}

std::optional<ClassDeclOp> ClassDeclOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::vast::hl::ClassDeclOp ClassDeclOp::underlying_repr(void) const noexcept {
  return ::vast::hl::ClassDeclOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Region ClassDeclOp::bases(void) const {
  auto &val = underlying_repr().getBases();
  return ::mx::ir::Region(module_, val);
}

::mx::ir::Region ClassDeclOp::fields(void) const {
  auto &val = underlying_repr().getFields();
  return ::mx::ir::Region(module_, val);
}

std::string_view ClassDeclOp::name(void) const {
  auto val = underlying_repr().getName();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return {};
  }
}

std::optional<CmpOp> CmpOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::HL_CMP) {
    return reinterpret_cast<const CmpOp &>(that);
  }
  return std::nullopt;
}

std::optional<CmpOp> CmpOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::vast::hl::CmpOp CmpOp::underlying_repr(void) const noexcept {
  return ::vast::hl::CmpOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value CmpOp::left(void) const {
  auto val = underlying_repr().getLhs();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value CmpOp::right(void) const {
  auto val = underlying_repr().getRhs();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value CmpOp::result(void) const {
  auto val = underlying_repr().getResult();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<CompoundLiteralOp> CompoundLiteralOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::HL_COMPOUND_LITERAL) {
    return reinterpret_cast<const CompoundLiteralOp &>(that);
  }
  return std::nullopt;
}

std::optional<CompoundLiteralOp> CompoundLiteralOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::vast::hl::CompoundLiteralOp CompoundLiteralOp::underlying_repr(void) const noexcept {
  return ::vast::hl::CompoundLiteralOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value CompoundLiteralOp::result(void) const {
  auto val = underlying_repr().getResult();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Region CompoundLiteralOp::initializer(void) const {
  auto &val = underlying_repr().getInit();
  return ::mx::ir::Region(module_, val);
}

std::optional<CondOp> CondOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::HL_COND) {
    return reinterpret_cast<const CondOp &>(that);
  }
  return std::nullopt;
}

std::optional<CondOp> CondOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::vast::hl::CondOp CondOp::underlying_repr(void) const noexcept {
  return ::vast::hl::CondOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value CondOp::result(void) const {
  auto val = underlying_repr().getResult();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Region CondOp::condition_region(void) const {
  auto &val = underlying_repr().getCondRegion();
  return ::mx::ir::Region(module_, val);
}

::mx::ir::Region CondOp::then_region(void) const {
  auto &val = underlying_repr().getThenRegion();
  return ::mx::ir::Region(module_, val);
}

::mx::ir::Region CondOp::else_region(void) const {
  auto &val = underlying_repr().getElseRegion();
  return ::mx::ir::Region(module_, val);
}

std::optional<CondYieldOp> CondYieldOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::HL_COND_YIELD) {
    return reinterpret_cast<const CondYieldOp &>(that);
  }
  return std::nullopt;
}

std::optional<CondYieldOp> CondYieldOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::vast::hl::CondYieldOp CondYieldOp::underlying_repr(void) const noexcept {
  return ::vast::hl::CondYieldOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value CondYieldOp::result(void) const {
  auto val = underlying_repr().getResult();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<ConstantOp> ConstantOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::HL_CONST) {
    return reinterpret_cast<const ConstantOp &>(that);
  }
  return std::nullopt;
}

std::optional<ConstantOp> ConstantOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::vast::hl::ConstantOp ConstantOp::underlying_repr(void) const noexcept {
  return ::vast::hl::ConstantOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value ConstantOp::result(void) const {
  auto val = underlying_repr().getResult();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<ContinueOp> ContinueOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::HL_CONTINUE) {
    return reinterpret_cast<const ContinueOp &>(that);
  }
  return std::nullopt;
}

std::optional<ContinueOp> ContinueOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::vast::hl::ContinueOp ContinueOp::underlying_repr(void) const noexcept {
  return ::vast::hl::ContinueOp(this->::mx::ir::Operation::op_);
}

std::optional<CxxBaseSpecifierOp> CxxBaseSpecifierOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::HL_BASE) {
    return reinterpret_cast<const CxxBaseSpecifierOp &>(that);
  }
  return std::nullopt;
}

std::optional<CxxBaseSpecifierOp> CxxBaseSpecifierOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::vast::hl::CxxBaseSpecifierOp CxxBaseSpecifierOp::underlying_repr(void) const noexcept {
  return ::vast::hl::CxxBaseSpecifierOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Type CxxBaseSpecifierOp::type(void) const {
  auto mlir_type = underlying_repr().getType();
  return ::mx::ir::Type(
      mlir_type.getContext(),
      reinterpret_cast<const mlir::TypeStorage *>(
          mlir_type.getAsOpaquePointer()));
}

bool CxxBaseSpecifierOp::is_virtual(void) const {
  auto val = underlying_repr().getIsVirtual();
  return val;
}

std::optional<CxxStructDeclOp> CxxStructDeclOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::HL_CXXSTRUCT) {
    return reinterpret_cast<const CxxStructDeclOp &>(that);
  }
  return std::nullopt;
}

std::optional<CxxStructDeclOp> CxxStructDeclOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::vast::hl::CxxStructDeclOp CxxStructDeclOp::underlying_repr(void) const noexcept {
  return ::vast::hl::CxxStructDeclOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Region CxxStructDeclOp::bases(void) const {
  auto &val = underlying_repr().getBases();
  return ::mx::ir::Region(module_, val);
}

::mx::ir::Region CxxStructDeclOp::fields(void) const {
  auto &val = underlying_repr().getFields();
  return ::mx::ir::Region(module_, val);
}

std::string_view CxxStructDeclOp::name(void) const {
  auto val = underlying_repr().getName();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return {};
  }
}

std::optional<DeclRefOp> DeclRefOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::HL_REF) {
    return reinterpret_cast<const DeclRefOp &>(that);
  }
  return std::nullopt;
}

std::optional<DeclRefOp> DeclRefOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::vast::hl::DeclRefOp DeclRefOp::underlying_repr(void) const noexcept {
  return ::vast::hl::DeclRefOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value DeclRefOp::declaration(void) const {
  auto val = underlying_repr().getDecl();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value DeclRefOp::result(void) const {
  auto val = underlying_repr().getResult();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<DefaultOp> DefaultOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::HL_DEFAULT) {
    return reinterpret_cast<const DefaultOp &>(that);
  }
  return std::nullopt;
}

std::optional<DefaultOp> DefaultOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::vast::hl::DefaultOp DefaultOp::underlying_repr(void) const noexcept {
  return ::vast::hl::DefaultOp(this->::mx::ir::Operation::op_);
}

std::optional<::mx::ir::Region> DefaultOp::body(void) const {
  decltype(auto) opt_val = underlying_repr().getBody();
  if (opt_val.empty()) {
    return std::nullopt;
  }
  auto &val = opt_val;
  return ::mx::ir::Region(module_, val);
}

std::optional<DerefOp> DerefOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::HL_DEREF) {
    return reinterpret_cast<const DerefOp &>(that);
  }
  return std::nullopt;
}

std::optional<DerefOp> DerefOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::vast::hl::Deref DerefOp::underlying_repr(void) const noexcept {
  return ::vast::hl::Deref(this->::mx::ir::Operation::op_);
}

::mx::ir::Value DerefOp::addr(void) const {
  auto val = underlying_repr().getAddr();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value DerefOp::result(void) const {
  auto val = underlying_repr().getResult();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<DivFAssignOp> DivFAssignOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::HL_ASSIGN_FDIV) {
    return reinterpret_cast<const DivFAssignOp &>(that);
  }
  return std::nullopt;
}

std::optional<DivFAssignOp> DivFAssignOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::vast::hl::DivFAssignOp DivFAssignOp::underlying_repr(void) const noexcept {
  return ::vast::hl::DivFAssignOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value DivFAssignOp::source(void) const {
  auto val = underlying_repr().getSrc();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value DivFAssignOp::destination(void) const {
  auto val = underlying_repr().getDst();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value DivFAssignOp::result(void) const {
  auto val = underlying_repr().getResult();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<DivFOp> DivFOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::HL_FDIV) {
    return reinterpret_cast<const DivFOp &>(that);
  }
  return std::nullopt;
}

std::optional<DivFOp> DivFOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::vast::hl::DivFOp DivFOp::underlying_repr(void) const noexcept {
  return ::vast::hl::DivFOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value DivFOp::left(void) const {
  auto val = underlying_repr().getLhs();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value DivFOp::right(void) const {
  auto val = underlying_repr().getRhs();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value DivFOp::result(void) const {
  auto val = underlying_repr().getResult();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<DivSAssignOp> DivSAssignOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::HL_ASSIGN_SDIV) {
    return reinterpret_cast<const DivSAssignOp &>(that);
  }
  return std::nullopt;
}

std::optional<DivSAssignOp> DivSAssignOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::vast::hl::DivSAssignOp DivSAssignOp::underlying_repr(void) const noexcept {
  return ::vast::hl::DivSAssignOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value DivSAssignOp::source(void) const {
  auto val = underlying_repr().getSrc();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value DivSAssignOp::destination(void) const {
  auto val = underlying_repr().getDst();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value DivSAssignOp::result(void) const {
  auto val = underlying_repr().getResult();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<DivSOp> DivSOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::HL_SDIV) {
    return reinterpret_cast<const DivSOp &>(that);
  }
  return std::nullopt;
}

std::optional<DivSOp> DivSOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::vast::hl::DivSOp DivSOp::underlying_repr(void) const noexcept {
  return ::vast::hl::DivSOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value DivSOp::left(void) const {
  auto val = underlying_repr().getLhs();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value DivSOp::right(void) const {
  auto val = underlying_repr().getRhs();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value DivSOp::result(void) const {
  auto val = underlying_repr().getResult();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<DivUAssignOp> DivUAssignOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::HL_ASSIGN_UDIV) {
    return reinterpret_cast<const DivUAssignOp &>(that);
  }
  return std::nullopt;
}

std::optional<DivUAssignOp> DivUAssignOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::vast::hl::DivUAssignOp DivUAssignOp::underlying_repr(void) const noexcept {
  return ::vast::hl::DivUAssignOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value DivUAssignOp::source(void) const {
  auto val = underlying_repr().getSrc();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value DivUAssignOp::destination(void) const {
  auto val = underlying_repr().getDst();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value DivUAssignOp::result(void) const {
  auto val = underlying_repr().getResult();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<DivUOp> DivUOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::HL_UDIV) {
    return reinterpret_cast<const DivUOp &>(that);
  }
  return std::nullopt;
}

std::optional<DivUOp> DivUOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::vast::hl::DivUOp DivUOp::underlying_repr(void) const noexcept {
  return ::vast::hl::DivUOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value DivUOp::left(void) const {
  auto val = underlying_repr().getLhs();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value DivUOp::right(void) const {
  auto val = underlying_repr().getRhs();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value DivUOp::result(void) const {
  auto val = underlying_repr().getResult();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<DoOp> DoOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::HL_DO) {
    return reinterpret_cast<const DoOp &>(that);
  }
  return std::nullopt;
}

std::optional<DoOp> DoOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::vast::hl::DoOp DoOp::underlying_repr(void) const noexcept {
  return ::vast::hl::DoOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Region DoOp::body_region(void) const {
  auto &val = underlying_repr().getBodyRegion();
  return ::mx::ir::Region(module_, val);
}

::mx::ir::Region DoOp::condition_region(void) const {
  auto &val = underlying_repr().getCondRegion();
  return ::mx::ir::Region(module_, val);
}

std::optional<EmptyDeclOp> EmptyDeclOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::HL_EMPTY_DECL) {
    return reinterpret_cast<const EmptyDeclOp &>(that);
  }
  return std::nullopt;
}

std::optional<EmptyDeclOp> EmptyDeclOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::vast::hl::EmptyDeclOp EmptyDeclOp::underlying_repr(void) const noexcept {
  return ::vast::hl::EmptyDeclOp(this->::mx::ir::Operation::op_);
}

std::optional<EnumConstantOp> EnumConstantOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::HL_ENUM_CONST) {
    return reinterpret_cast<const EnumConstantOp &>(that);
  }
  return std::nullopt;
}

std::optional<EnumConstantOp> EnumConstantOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::vast::hl::EnumConstantOp EnumConstantOp::underlying_repr(void) const noexcept {
  return ::vast::hl::EnumConstantOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Region EnumConstantOp::initializer(void) const {
  auto &val = underlying_repr().getInit();
  return ::mx::ir::Region(module_, val);
}

std::string_view EnumConstantOp::name(void) const {
  auto val = underlying_repr().getSymName();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return {};
  }
}

std::optional<EnumDeclOp> EnumDeclOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::HL_ENUM) {
    return reinterpret_cast<const EnumDeclOp &>(that);
  }
  return std::nullopt;
}

std::optional<EnumDeclOp> EnumDeclOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::vast::hl::EnumDeclOp EnumDeclOp::underlying_repr(void) const noexcept {
  return ::vast::hl::EnumDeclOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Region EnumDeclOp::constants(void) const {
  auto &val = underlying_repr().getConstants();
  return ::mx::ir::Region(module_, val);
}

std::string_view EnumDeclOp::name(void) const {
  auto val = underlying_repr().getSymName();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return {};
  }
}

std::optional<::mx::ir::Type> EnumDeclOp::type(void) const {
  auto opt_val = underlying_repr().getType();
  if (!opt_val) {
    return std::nullopt;
  }
  auto &val = opt_val.value();
  return ::mx::ir::Type(
      val.getContext(),
      reinterpret_cast<const mlir::TypeStorage *>(
          val.getAsOpaquePointer()));
}

bool EnumDeclOp::is_complete(void) const {
  auto val = underlying_repr().isComplete();
  return val;
}

::mx::ir::Block EnumDeclOp::constants_block(void) const {
  auto &val = underlying_repr().getConstantsBlock();
  return ::mx::ir::Block(module_, val);
}

std::optional<EnumRefOp> EnumRefOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::HL_ENUMREF) {
    return reinterpret_cast<const EnumRefOp &>(that);
  }
  return std::nullopt;
}

std::optional<EnumRefOp> EnumRefOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::vast::hl::EnumRefOp EnumRefOp::underlying_repr(void) const noexcept {
  return ::vast::hl::EnumRefOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value EnumRefOp::result(void) const {
  auto val = underlying_repr().getResult();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::string_view EnumRefOp::value(void) const {
  auto val = underlying_repr().getValue();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return {};
  }
}

std::optional<ExprOp> ExprOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::HL_EXPR) {
    return reinterpret_cast<const ExprOp &>(that);
  }
  return std::nullopt;
}

std::optional<ExprOp> ExprOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::vast::hl::ExprOp ExprOp::underlying_repr(void) const noexcept {
  return ::vast::hl::ExprOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value ExprOp::result(void) const {
  auto val = underlying_repr().getResult();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Region ExprOp::nested_expression(void) const {
  auto &val = underlying_repr().getSubexpr();
  return ::mx::ir::Region(module_, val);
}

std::optional<ExtensionOp> ExtensionOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::HL_GNU_EXTENSION) {
    return reinterpret_cast<const ExtensionOp &>(that);
  }
  return std::nullopt;
}

std::optional<ExtensionOp> ExtensionOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::vast::hl::ExtensionOp ExtensionOp::underlying_repr(void) const noexcept {
  return ::vast::hl::ExtensionOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value ExtensionOp::value(void) const {
  auto val = underlying_repr().getValue();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value ExtensionOp::result(void) const {
  auto val = underlying_repr().getResult();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<FCmpOp> FCmpOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::HL_FCMP) {
    return reinterpret_cast<const FCmpOp &>(that);
  }
  return std::nullopt;
}

std::optional<FCmpOp> FCmpOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::vast::hl::FCmpOp FCmpOp::underlying_repr(void) const noexcept {
  return ::vast::hl::FCmpOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value FCmpOp::left(void) const {
  auto val = underlying_repr().getLhs();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value FCmpOp::right(void) const {
  auto val = underlying_repr().getRhs();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value FCmpOp::result(void) const {
  auto val = underlying_repr().getResult();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<FieldDeclOp> FieldDeclOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::HL_FIELD) {
    return reinterpret_cast<const FieldDeclOp &>(that);
  }
  return std::nullopt;
}

std::optional<FieldDeclOp> FieldDeclOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::vast::hl::FieldDeclOp FieldDeclOp::underlying_repr(void) const noexcept {
  return ::vast::hl::FieldDeclOp(this->::mx::ir::Operation::op_);
}

std::string_view FieldDeclOp::name(void) const {
  auto val = underlying_repr().getSymName();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return {};
  }
}

::mx::ir::Type FieldDeclOp::type(void) const {
  auto mlir_type = underlying_repr().getType();
  return ::mx::ir::Type(
      mlir_type.getContext(),
      reinterpret_cast<const mlir::TypeStorage *>(
          mlir_type.getAsOpaquePointer()));
}

std::optional<unsigned int> FieldDeclOp::bits(void) const {
  auto opt_val = underlying_repr().getBits();
  if (!opt_val) {
    return std::nullopt;
  }
  auto &val = opt_val.value();
  return val;
}

std::optional<FileScopeAsmOp> FileScopeAsmOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::HL_FILE_SCOPE_ASM) {
    return reinterpret_cast<const FileScopeAsmOp &>(that);
  }
  return std::nullopt;
}

std::optional<FileScopeAsmOp> FileScopeAsmOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::vast::hl::FileScopeAsmOp FileScopeAsmOp::underlying_repr(void) const noexcept {
  return ::vast::hl::FileScopeAsmOp(this->::mx::ir::Operation::op_);
}

std::string_view FileScopeAsmOp::assembly(void) const {
  auto val = underlying_repr().getAsmString();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return {};
  }
}

std::optional<ForOp> ForOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::HL_FOR) {
    return reinterpret_cast<const ForOp &>(that);
  }
  return std::nullopt;
}

std::optional<ForOp> ForOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::vast::hl::ForOp ForOp::underlying_repr(void) const noexcept {
  return ::vast::hl::ForOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Region ForOp::condition_region(void) const {
  auto &val = underlying_repr().getCondRegion();
  return ::mx::ir::Region(module_, val);
}

std::optional<::mx::ir::Region> ForOp::incr_region(void) const {
  decltype(auto) opt_val = underlying_repr().getIncrRegion();
  if (opt_val.empty()) {
    return std::nullopt;
  }
  auto &val = opt_val;
  return ::mx::ir::Region(module_, val);
}

std::optional<::mx::ir::Region> ForOp::body_region(void) const {
  decltype(auto) opt_val = underlying_repr().getBodyRegion();
  if (opt_val.empty()) {
    return std::nullopt;
  }
  auto &val = opt_val;
  return ::mx::ir::Region(module_, val);
}

std::optional<FuncOp> FuncOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::HL_FUNC) {
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

::vast::hl::FuncOp FuncOp::underlying_repr(void) const noexcept {
  return ::vast::hl::FuncOp(this->::mx::ir::Operation::op_);
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

std::optional<FuncRefOp> FuncRefOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::HL_FUNCREF) {
    return reinterpret_cast<const FuncRefOp &>(that);
  }
  return std::nullopt;
}

std::optional<FuncRefOp> FuncRefOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::vast::hl::FuncRefOp FuncRefOp::underlying_repr(void) const noexcept {
  return ::vast::hl::FuncRefOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value FuncRefOp::result(void) const {
  auto val = underlying_repr().getResult();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::string_view FuncRefOp::function(void) const {
  auto val = underlying_repr().getFunction();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return {};
  }
}

std::optional<GenericAssocExprOp> GenericAssocExprOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::HL_GENERIC_ASOC) {
    return reinterpret_cast<const GenericAssocExprOp &>(that);
  }
  return std::nullopt;
}

std::optional<GenericAssocExprOp> GenericAssocExprOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::vast::hl::GenericAssocExpr GenericAssocExprOp::underlying_repr(void) const noexcept {
  return ::vast::hl::GenericAssocExpr(this->::mx::ir::Operation::op_);
}

::mx::ir::Value GenericAssocExprOp::result(void) const {
  auto val = underlying_repr().getResult();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Region GenericAssocExprOp::body(void) const {
  auto &val = underlying_repr().getBody();
  return ::mx::ir::Region(module_, val);
}

std::optional<::mx::ir::Type> GenericAssocExprOp::match_type(void) const {
  auto opt_val = underlying_repr().getMatchType();
  if (!opt_val) {
    return std::nullopt;
  }
  auto &val = opt_val.value();
  return ::mx::ir::Type(
      val.getContext(),
      reinterpret_cast<const mlir::TypeStorage *>(
          val.getAsOpaquePointer()));
}

std::optional<GenericSelectionExprOp> GenericSelectionExprOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::HL_GENERIC_EXPR) {
    return reinterpret_cast<const GenericSelectionExprOp &>(that);
  }
  return std::nullopt;
}

std::optional<GenericSelectionExprOp> GenericSelectionExprOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::vast::hl::GenericSelectionExpr GenericSelectionExprOp::underlying_repr(void) const noexcept {
  return ::vast::hl::GenericSelectionExpr(this->::mx::ir::Operation::op_);
}

::mx::ir::Value GenericSelectionExprOp::result(void) const {
  auto val = underlying_repr().getResult();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Region GenericSelectionExprOp::control(void) const {
  auto &val = underlying_repr().getControl();
  return ::mx::ir::Region(module_, val);
}

::mx::ir::Region GenericSelectionExprOp::body(void) const {
  auto &val = underlying_repr().getBody();
  return ::mx::ir::Region(module_, val);
}

std::optional<::mx::ir::Type> GenericSelectionExprOp::control_type(void) const {
  auto opt_val = underlying_repr().getControlType();
  if (!opt_val) {
    return std::nullopt;
  }
  auto &val = opt_val.value();
  return ::mx::ir::Type(
      val.getContext(),
      reinterpret_cast<const mlir::TypeStorage *>(
          val.getAsOpaquePointer()));
}

bool GenericSelectionExprOp::is_expression_predicate(void) const {
  auto val = underlying_repr().isExprPredicate();
  return val;
}

bool GenericSelectionExprOp::is_type_predicate(void) const {
  auto val = underlying_repr().isTypePredicate();
  return val;
}

std::optional<GlobalRefOp> GlobalRefOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::HL_GLOBREF) {
    return reinterpret_cast<const GlobalRefOp &>(that);
  }
  return std::nullopt;
}

std::optional<GlobalRefOp> GlobalRefOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::vast::hl::GlobalRefOp GlobalRefOp::underlying_repr(void) const noexcept {
  return ::vast::hl::GlobalRefOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value GlobalRefOp::result(void) const {
  auto val = underlying_repr().getResult();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::string_view GlobalRefOp::global(void) const {
  auto val = underlying_repr().getGlobal();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return {};
  }
}

std::optional<GotoStmtOp> GotoStmtOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::HL_GOTO) {
    return reinterpret_cast<const GotoStmtOp &>(that);
  }
  return std::nullopt;
}

std::optional<GotoStmtOp> GotoStmtOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::vast::hl::GotoStmt GotoStmtOp::underlying_repr(void) const noexcept {
  return ::vast::hl::GotoStmt(this->::mx::ir::Operation::op_);
}

::mx::ir::Value GotoStmtOp::label(void) const {
  auto val = underlying_repr().getLabel();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<IfOp> IfOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::HL_IF) {
    return reinterpret_cast<const IfOp &>(that);
  }
  return std::nullopt;
}

std::optional<IfOp> IfOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::vast::hl::IfOp IfOp::underlying_repr(void) const noexcept {
  return ::vast::hl::IfOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Region IfOp::condition_region(void) const {
  auto &val = underlying_repr().getCondRegion();
  return ::mx::ir::Region(module_, val);
}

::mx::ir::Region IfOp::then_region(void) const {
  auto &val = underlying_repr().getThenRegion();
  return ::mx::ir::Region(module_, val);
}

std::optional<::mx::ir::Region> IfOp::else_region(void) const {
  decltype(auto) opt_val = underlying_repr().getElseRegion();
  if (opt_val.empty()) {
    return std::nullopt;
  }
  auto &val = opt_val;
  return ::mx::ir::Region(module_, val);
}

bool IfOp::has_else(void) const {
  auto val = underlying_repr().hasElse();
  return val;
}

std::optional<ImagOp> ImagOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::HL_IMAG) {
    return reinterpret_cast<const ImagOp &>(that);
  }
  return std::nullopt;
}

std::optional<ImagOp> ImagOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::vast::hl::ImagOp ImagOp::underlying_repr(void) const noexcept {
  return ::vast::hl::ImagOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value ImagOp::argument(void) const {
  auto val = underlying_repr().getArg();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value ImagOp::result(void) const {
  auto val = underlying_repr().getResult();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<ImplicitCastOp> ImplicitCastOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::HL_IMPLICIT_CAST) {
    return reinterpret_cast<const ImplicitCastOp &>(that);
  }
  return std::nullopt;
}

std::optional<ImplicitCastOp> ImplicitCastOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::vast::hl::ImplicitCastOp ImplicitCastOp::underlying_repr(void) const noexcept {
  return ::vast::hl::ImplicitCastOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value ImplicitCastOp::value(void) const {
  auto val = underlying_repr().getValue();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value ImplicitCastOp::result(void) const {
  auto val = underlying_repr().getResult();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<IndirectCallOp> IndirectCallOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::HL_INDIRECT_CALL) {
    return reinterpret_cast<const IndirectCallOp &>(that);
  }
  return std::nullopt;
}

std::optional<IndirectCallOp> IndirectCallOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::vast::hl::IndirectCallOp IndirectCallOp::underlying_repr(void) const noexcept {
  return ::vast::hl::IndirectCallOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value IndirectCallOp::callee(void) const {
  auto val = underlying_repr().getCallee();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

gap::generator<::mx::ir::Operand> IndirectCallOp::arg_operands(void) const & {
  auto range = underlying_repr().getArgOperands();
  for (auto val : range) {
    co_yield ::mx::ir::Operand(module_, val.getAsOpaquePointer());
  }
}

gap::generator<::mx::ir::Result> IndirectCallOp::results(void) const & {
  auto range = underlying_repr().getResults();
  for (auto val : range) {
    co_yield ::mx::ir::Result(module_, val.getAsOpaquePointer());
  }
}

std::optional<IndirectGotoStmtOp> IndirectGotoStmtOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::HL_INDIRECT_GOTO) {
    return reinterpret_cast<const IndirectGotoStmtOp &>(that);
  }
  return std::nullopt;
}

std::optional<IndirectGotoStmtOp> IndirectGotoStmtOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::vast::hl::IndirectGotoStmt IndirectGotoStmtOp::underlying_repr(void) const noexcept {
  return ::vast::hl::IndirectGotoStmt(this->::mx::ir::Operation::op_);
}

::mx::ir::Region IndirectGotoStmtOp::target(void) const {
  auto &val = underlying_repr().getTarget();
  return ::mx::ir::Region(module_, val);
}

std::optional<InitListExprOp> InitListExprOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::HL_INITLIST) {
    return reinterpret_cast<const InitListExprOp &>(that);
  }
  return std::nullopt;
}

std::optional<InitListExprOp> InitListExprOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::vast::hl::InitListExpr InitListExprOp::underlying_repr(void) const noexcept {
  return ::vast::hl::InitListExpr(this->::mx::ir::Operation::op_);
}

gap::generator<::mx::ir::Operand> InitListExprOp::elements(void) const & {
  auto range = underlying_repr().getElements();
  for (auto val : range) {
    co_yield ::mx::ir::Operand(module_, val.getAsOpaquePointer());
  }
}

std::optional<InitializedConstantOp> InitializedConstantOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::HL_CONST_INIT) {
    return reinterpret_cast<const InitializedConstantOp &>(that);
  }
  return std::nullopt;
}

std::optional<InitializedConstantOp> InitializedConstantOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::vast::hl::InitializedConstantOp InitializedConstantOp::underlying_repr(void) const noexcept {
  return ::vast::hl::InitializedConstantOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value InitializedConstantOp::result(void) const {
  auto val = underlying_repr().getResult();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Region InitializedConstantOp::initializer(void) const {
  auto &val = underlying_repr().getInit();
  return ::mx::ir::Region(module_, val);
}

std::optional<LNotOp> LNotOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::HL_LNOT) {
    return reinterpret_cast<const LNotOp &>(that);
  }
  return std::nullopt;
}

std::optional<LNotOp> LNotOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::vast::hl::LNotOp LNotOp::underlying_repr(void) const noexcept {
  return ::vast::hl::LNotOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value LNotOp::argument(void) const {
  auto val = underlying_repr().getArg();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value LNotOp::result(void) const {
  auto val = underlying_repr().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<LabelDeclOp> LabelDeclOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::HL_LABEL_DECL) {
    return reinterpret_cast<const LabelDeclOp &>(that);
  }
  return std::nullopt;
}

std::optional<LabelDeclOp> LabelDeclOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::vast::hl::LabelDeclOp LabelDeclOp::underlying_repr(void) const noexcept {
  return ::vast::hl::LabelDeclOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value LabelDeclOp::result(void) const {
  auto val = underlying_repr().getResult();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::string_view LabelDeclOp::name(void) const {
  auto val = underlying_repr().getSymName();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return {};
  }
}

std::optional<LabelStmtOp> LabelStmtOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::HL_LABEL) {
    return reinterpret_cast<const LabelStmtOp &>(that);
  }
  return std::nullopt;
}

std::optional<LabelStmtOp> LabelStmtOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::vast::hl::LabelStmt LabelStmtOp::underlying_repr(void) const noexcept {
  return ::vast::hl::LabelStmt(this->::mx::ir::Operation::op_);
}

::mx::ir::Value LabelStmtOp::label(void) const {
  auto val = underlying_repr().getLabel();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Region LabelStmtOp::body(void) const {
  auto &val = underlying_repr().getBody();
  return ::mx::ir::Region(module_, val);
}

std::optional<MinusOp> MinusOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::HL_MINUS) {
    return reinterpret_cast<const MinusOp &>(that);
  }
  return std::nullopt;
}

std::optional<MinusOp> MinusOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::vast::hl::MinusOp MinusOp::underlying_repr(void) const noexcept {
  return ::vast::hl::MinusOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value MinusOp::argument(void) const {
  auto val = underlying_repr().getArg();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value MinusOp::result(void) const {
  auto val = underlying_repr().getResult();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<MulFAssignOp> MulFAssignOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::HL_ASSIGN_FMUL) {
    return reinterpret_cast<const MulFAssignOp &>(that);
  }
  return std::nullopt;
}

std::optional<MulFAssignOp> MulFAssignOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::vast::hl::MulFAssignOp MulFAssignOp::underlying_repr(void) const noexcept {
  return ::vast::hl::MulFAssignOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value MulFAssignOp::source(void) const {
  auto val = underlying_repr().getSrc();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value MulFAssignOp::destination(void) const {
  auto val = underlying_repr().getDst();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value MulFAssignOp::result(void) const {
  auto val = underlying_repr().getResult();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<MulFOp> MulFOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::HL_FMUL) {
    return reinterpret_cast<const MulFOp &>(that);
  }
  return std::nullopt;
}

std::optional<MulFOp> MulFOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::vast::hl::MulFOp MulFOp::underlying_repr(void) const noexcept {
  return ::vast::hl::MulFOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value MulFOp::left(void) const {
  auto val = underlying_repr().getLhs();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value MulFOp::right(void) const {
  auto val = underlying_repr().getRhs();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value MulFOp::result(void) const {
  auto val = underlying_repr().getResult();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<MulIAssignOp> MulIAssignOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::HL_ASSIGN_MUL) {
    return reinterpret_cast<const MulIAssignOp &>(that);
  }
  return std::nullopt;
}

std::optional<MulIAssignOp> MulIAssignOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::vast::hl::MulIAssignOp MulIAssignOp::underlying_repr(void) const noexcept {
  return ::vast::hl::MulIAssignOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value MulIAssignOp::source(void) const {
  auto val = underlying_repr().getSrc();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value MulIAssignOp::destination(void) const {
  auto val = underlying_repr().getDst();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value MulIAssignOp::result(void) const {
  auto val = underlying_repr().getResult();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<MulIOp> MulIOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::HL_MUL) {
    return reinterpret_cast<const MulIOp &>(that);
  }
  return std::nullopt;
}

std::optional<MulIOp> MulIOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::vast::hl::MulIOp MulIOp::underlying_repr(void) const noexcept {
  return ::vast::hl::MulIOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value MulIOp::left(void) const {
  auto val = underlying_repr().getLhs();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value MulIOp::right(void) const {
  auto val = underlying_repr().getRhs();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value MulIOp::result(void) const {
  auto val = underlying_repr().getResult();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<NotOp> NotOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::HL_NOT) {
    return reinterpret_cast<const NotOp &>(that);
  }
  return std::nullopt;
}

std::optional<NotOp> NotOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::vast::hl::NotOp NotOp::underlying_repr(void) const noexcept {
  return ::vast::hl::NotOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value NotOp::argument(void) const {
  auto val = underlying_repr().getArg();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value NotOp::result(void) const {
  auto val = underlying_repr().getResult();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<NullStmtOp> NullStmtOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::HL_NULL) {
    return reinterpret_cast<const NullStmtOp &>(that);
  }
  return std::nullopt;
}

std::optional<NullStmtOp> NullStmtOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::vast::hl::NullStmt NullStmtOp::underlying_repr(void) const noexcept {
  return ::vast::hl::NullStmt(this->::mx::ir::Operation::op_);
}

std::optional<OffsetOfExprOp> OffsetOfExprOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::HL_OFFSETOF_EXPR) {
    return reinterpret_cast<const OffsetOfExprOp &>(that);
  }
  return std::nullopt;
}

std::optional<OffsetOfExprOp> OffsetOfExprOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::vast::hl::OffsetOfExprOp OffsetOfExprOp::underlying_repr(void) const noexcept {
  return ::vast::hl::OffsetOfExprOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value OffsetOfExprOp::result(void) const {
  auto val = underlying_repr().getResult();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

gap::generator<::mx::ir::Region> OffsetOfExprOp::array_index_exprs(void) const & {
  decltype(auto) regions = underlying_repr().getArrayIndexExprs();
  for (auto &region : regions) {
    co_yield ::mx::ir::Region(module_, &region);
  }
}

::mx::ir::Type OffsetOfExprOp::source(void) const {
  auto mlir_type = underlying_repr().getSource();
  return ::mx::ir::Type(
      mlir_type.getContext(),
      reinterpret_cast<const mlir::TypeStorage *>(
          mlir_type.getAsOpaquePointer()));
}

std::optional<OpaqueValueExprOp> OpaqueValueExprOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::HL_OPAQUE_EXPR) {
    return reinterpret_cast<const OpaqueValueExprOp &>(that);
  }
  return std::nullopt;
}

std::optional<OpaqueValueExprOp> OpaqueValueExprOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::vast::hl::OpaqueValueExpr OpaqueValueExprOp::underlying_repr(void) const noexcept {
  return ::vast::hl::OpaqueValueExpr(this->::mx::ir::Operation::op_);
}

gap::generator<::mx::ir::Operand> OpaqueValueExprOp::argument(void) const & {
  auto range = underlying_repr().getArg();
  for (auto val : range) {
    co_yield ::mx::ir::Operand(module_, val.getAsOpaquePointer());
  }
}

::mx::ir::Value OpaqueValueExprOp::result(void) const {
  auto val = underlying_repr().getResult();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<PlusOp> PlusOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::HL_PLUS) {
    return reinterpret_cast<const PlusOp &>(that);
  }
  return std::nullopt;
}

std::optional<PlusOp> PlusOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::vast::hl::PlusOp PlusOp::underlying_repr(void) const noexcept {
  return ::vast::hl::PlusOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value PlusOp::argument(void) const {
  auto val = underlying_repr().getArg();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value PlusOp::result(void) const {
  auto val = underlying_repr().getResult();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<PostDecOp> PostDecOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::HL_POST_DEC) {
    return reinterpret_cast<const PostDecOp &>(that);
  }
  return std::nullopt;
}

std::optional<PostDecOp> PostDecOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::vast::hl::PostDecOp PostDecOp::underlying_repr(void) const noexcept {
  return ::vast::hl::PostDecOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value PostDecOp::argument(void) const {
  auto val = underlying_repr().getArg();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value PostDecOp::result(void) const {
  auto val = underlying_repr().getResult();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<PostIncOp> PostIncOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::HL_POST_INC) {
    return reinterpret_cast<const PostIncOp &>(that);
  }
  return std::nullopt;
}

std::optional<PostIncOp> PostIncOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::vast::hl::PostIncOp PostIncOp::underlying_repr(void) const noexcept {
  return ::vast::hl::PostIncOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value PostIncOp::argument(void) const {
  auto val = underlying_repr().getArg();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value PostIncOp::result(void) const {
  auto val = underlying_repr().getResult();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<PreDecOp> PreDecOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::HL_PRE_DEC) {
    return reinterpret_cast<const PreDecOp &>(that);
  }
  return std::nullopt;
}

std::optional<PreDecOp> PreDecOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::vast::hl::PreDecOp PreDecOp::underlying_repr(void) const noexcept {
  return ::vast::hl::PreDecOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value PreDecOp::argument(void) const {
  auto val = underlying_repr().getArg();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value PreDecOp::result(void) const {
  auto val = underlying_repr().getResult();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<PreIncOp> PreIncOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::HL_PRE_INC) {
    return reinterpret_cast<const PreIncOp &>(that);
  }
  return std::nullopt;
}

std::optional<PreIncOp> PreIncOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::vast::hl::PreIncOp PreIncOp::underlying_repr(void) const noexcept {
  return ::vast::hl::PreIncOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value PreIncOp::argument(void) const {
  auto val = underlying_repr().getArg();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value PreIncOp::result(void) const {
  auto val = underlying_repr().getResult();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<PredefinedExprOp> PredefinedExprOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::HL_PREDEFINED_EXPR) {
    return reinterpret_cast<const PredefinedExprOp &>(that);
  }
  return std::nullopt;
}

std::optional<PredefinedExprOp> PredefinedExprOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::vast::hl::PredefinedExpr PredefinedExprOp::underlying_repr(void) const noexcept {
  return ::vast::hl::PredefinedExpr(this->::mx::ir::Operation::op_);
}

::mx::ir::Value PredefinedExprOp::value(void) const {
  auto val = underlying_repr().getValue();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value PredefinedExprOp::result(void) const {
  auto val = underlying_repr().getResult();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<PreferredAlignOfExprOp> PreferredAlignOfExprOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::HL_PREFERRED_ALIGNOF_EXPR) {
    return reinterpret_cast<const PreferredAlignOfExprOp &>(that);
  }
  return std::nullopt;
}

std::optional<PreferredAlignOfExprOp> PreferredAlignOfExprOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::vast::hl::PreferredAlignOfExprOp PreferredAlignOfExprOp::underlying_repr(void) const noexcept {
  return ::vast::hl::PreferredAlignOfExprOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value PreferredAlignOfExprOp::result(void) const {
  auto val = underlying_repr().getResult();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Region PreferredAlignOfExprOp::expression(void) const {
  auto &val = underlying_repr().getExpr();
  return ::mx::ir::Region(module_, val);
}

std::optional<PreferredAlignOfTypeOp> PreferredAlignOfTypeOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::HL_PREFERRED_ALIGNOF_TYPE) {
    return reinterpret_cast<const PreferredAlignOfTypeOp &>(that);
  }
  return std::nullopt;
}

std::optional<PreferredAlignOfTypeOp> PreferredAlignOfTypeOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::vast::hl::PreferredAlignOfTypeOp PreferredAlignOfTypeOp::underlying_repr(void) const noexcept {
  return ::vast::hl::PreferredAlignOfTypeOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value PreferredAlignOfTypeOp::result(void) const {
  auto val = underlying_repr().getResult();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Type PreferredAlignOfTypeOp::argument(void) const {
  auto mlir_type = underlying_repr().getArg();
  return ::mx::ir::Type(
      mlir_type.getContext(),
      reinterpret_cast<const mlir::TypeStorage *>(
          mlir_type.getAsOpaquePointer()));
}

std::optional<RealOp> RealOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::HL_REAL) {
    return reinterpret_cast<const RealOp &>(that);
  }
  return std::nullopt;
}

std::optional<RealOp> RealOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::vast::hl::RealOp RealOp::underlying_repr(void) const noexcept {
  return ::vast::hl::RealOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value RealOp::argument(void) const {
  auto val = underlying_repr().getArg();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value RealOp::result(void) const {
  auto val = underlying_repr().getResult();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<RecordMemberOp> RecordMemberOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::HL_MEMBER) {
    return reinterpret_cast<const RecordMemberOp &>(that);
  }
  return std::nullopt;
}

std::optional<RecordMemberOp> RecordMemberOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::vast::hl::RecordMemberOp RecordMemberOp::underlying_repr(void) const noexcept {
  return ::vast::hl::RecordMemberOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value RecordMemberOp::record(void) const {
  auto val = underlying_repr().getRecord();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value RecordMemberOp::element(void) const {
  auto val = underlying_repr().getElement();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::string_view RecordMemberOp::field(void) const {
  auto val = underlying_repr().getField();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return {};
  }
}

std::optional<RemFAssignOp> RemFAssignOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::HL_ASSIGN_FREM) {
    return reinterpret_cast<const RemFAssignOp &>(that);
  }
  return std::nullopt;
}

std::optional<RemFAssignOp> RemFAssignOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::vast::hl::RemFAssignOp RemFAssignOp::underlying_repr(void) const noexcept {
  return ::vast::hl::RemFAssignOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value RemFAssignOp::source(void) const {
  auto val = underlying_repr().getSrc();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value RemFAssignOp::destination(void) const {
  auto val = underlying_repr().getDst();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value RemFAssignOp::result(void) const {
  auto val = underlying_repr().getResult();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<RemFOp> RemFOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::HL_FREM) {
    return reinterpret_cast<const RemFOp &>(that);
  }
  return std::nullopt;
}

std::optional<RemFOp> RemFOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::vast::hl::RemFOp RemFOp::underlying_repr(void) const noexcept {
  return ::vast::hl::RemFOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value RemFOp::left(void) const {
  auto val = underlying_repr().getLhs();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value RemFOp::right(void) const {
  auto val = underlying_repr().getRhs();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value RemFOp::result(void) const {
  auto val = underlying_repr().getResult();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<RemSAssignOp> RemSAssignOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::HL_ASSIGN_SREM) {
    return reinterpret_cast<const RemSAssignOp &>(that);
  }
  return std::nullopt;
}

std::optional<RemSAssignOp> RemSAssignOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::vast::hl::RemSAssignOp RemSAssignOp::underlying_repr(void) const noexcept {
  return ::vast::hl::RemSAssignOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value RemSAssignOp::source(void) const {
  auto val = underlying_repr().getSrc();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value RemSAssignOp::destination(void) const {
  auto val = underlying_repr().getDst();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value RemSAssignOp::result(void) const {
  auto val = underlying_repr().getResult();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<RemSOp> RemSOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::HL_SREM) {
    return reinterpret_cast<const RemSOp &>(that);
  }
  return std::nullopt;
}

std::optional<RemSOp> RemSOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::vast::hl::RemSOp RemSOp::underlying_repr(void) const noexcept {
  return ::vast::hl::RemSOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value RemSOp::left(void) const {
  auto val = underlying_repr().getLhs();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value RemSOp::right(void) const {
  auto val = underlying_repr().getRhs();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value RemSOp::result(void) const {
  auto val = underlying_repr().getResult();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<RemUAssignOp> RemUAssignOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::HL_ASSIGN_UREM) {
    return reinterpret_cast<const RemUAssignOp &>(that);
  }
  return std::nullopt;
}

std::optional<RemUAssignOp> RemUAssignOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::vast::hl::RemUAssignOp RemUAssignOp::underlying_repr(void) const noexcept {
  return ::vast::hl::RemUAssignOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value RemUAssignOp::source(void) const {
  auto val = underlying_repr().getSrc();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value RemUAssignOp::destination(void) const {
  auto val = underlying_repr().getDst();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value RemUAssignOp::result(void) const {
  auto val = underlying_repr().getResult();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<RemUOp> RemUOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::HL_UREM) {
    return reinterpret_cast<const RemUOp &>(that);
  }
  return std::nullopt;
}

std::optional<RemUOp> RemUOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::vast::hl::RemUOp RemUOp::underlying_repr(void) const noexcept {
  return ::vast::hl::RemUOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value RemUOp::left(void) const {
  auto val = underlying_repr().getLhs();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value RemUOp::right(void) const {
  auto val = underlying_repr().getRhs();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value RemUOp::result(void) const {
  auto val = underlying_repr().getResult();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<ReturnOp> ReturnOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::HL_RETURN) {
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

::vast::hl::ReturnOp ReturnOp::underlying_repr(void) const noexcept {
  return ::vast::hl::ReturnOp(this->::mx::ir::Operation::op_);
}

gap::generator<::mx::ir::Operand> ReturnOp::result(void) const & {
  auto range = underlying_repr().getResult();
  for (auto val : range) {
    co_yield ::mx::ir::Operand(module_, val.getAsOpaquePointer());
  }
}

std::optional<SizeOfExprOp> SizeOfExprOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::HL_SIZEOF_EXPR) {
    return reinterpret_cast<const SizeOfExprOp &>(that);
  }
  return std::nullopt;
}

std::optional<SizeOfExprOp> SizeOfExprOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::vast::hl::SizeOfExprOp SizeOfExprOp::underlying_repr(void) const noexcept {
  return ::vast::hl::SizeOfExprOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value SizeOfExprOp::result(void) const {
  auto val = underlying_repr().getResult();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Region SizeOfExprOp::expression(void) const {
  auto &val = underlying_repr().getExpr();
  return ::mx::ir::Region(module_, val);
}

std::size_t SizeOfExprOp::value(void) const {
  auto val = underlying_repr().getValue();
  return val;
}

std::optional<SizeOfTypeOp> SizeOfTypeOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::HL_SIZEOF_TYPE) {
    return reinterpret_cast<const SizeOfTypeOp &>(that);
  }
  return std::nullopt;
}

std::optional<SizeOfTypeOp> SizeOfTypeOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::vast::hl::SizeOfTypeOp SizeOfTypeOp::underlying_repr(void) const noexcept {
  return ::vast::hl::SizeOfTypeOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value SizeOfTypeOp::result(void) const {
  auto val = underlying_repr().getResult();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Type SizeOfTypeOp::argument(void) const {
  auto mlir_type = underlying_repr().getArg();
  return ::mx::ir::Type(
      mlir_type.getContext(),
      reinterpret_cast<const mlir::TypeStorage *>(
          mlir_type.getAsOpaquePointer()));
}

std::size_t SizeOfTypeOp::value(void) const {
  auto val = underlying_repr().getValue();
  return val;
}

std::optional<StaticAssertDeclOp> StaticAssertDeclOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::HL_STATIC_ASSERT) {
    return reinterpret_cast<const StaticAssertDeclOp &>(that);
  }
  return std::nullopt;
}

std::optional<StaticAssertDeclOp> StaticAssertDeclOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::vast::hl::StaticAssertDecl StaticAssertDeclOp::underlying_repr(void) const noexcept {
  return ::vast::hl::StaticAssertDecl(this->::mx::ir::Operation::op_);
}

::mx::ir::Region StaticAssertDeclOp::assertion(void) const {
  auto &val = underlying_repr().getAssert();
  return ::mx::ir::Region(module_, val);
}

::mx::ir::Region StaticAssertDeclOp::message(void) const {
  auto &val = underlying_repr().getMessage();
  return ::mx::ir::Region(module_, val);
}

bool StaticAssertDeclOp::failed(void) const {
  auto val = underlying_repr().getFailed();
  return val;
}

std::optional<StmtExprOp> StmtExprOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::HL_STMT_EXPR) {
    return reinterpret_cast<const StmtExprOp &>(that);
  }
  return std::nullopt;
}

std::optional<StmtExprOp> StmtExprOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::vast::hl::StmtExprOp StmtExprOp::underlying_repr(void) const noexcept {
  return ::vast::hl::StmtExprOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value StmtExprOp::result(void) const {
  auto val = underlying_repr().getResult();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Region StmtExprOp::nested_statement(void) const {
  auto &val = underlying_repr().getSubstmt();
  return ::mx::ir::Region(module_, val);
}

std::optional<StructDeclOp> StructDeclOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::HL_STRUCT) {
    return reinterpret_cast<const StructDeclOp &>(that);
  }
  return std::nullopt;
}

std::optional<StructDeclOp> StructDeclOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::vast::hl::StructDeclOp StructDeclOp::underlying_repr(void) const noexcept {
  return ::vast::hl::StructDeclOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Region StructDeclOp::fields(void) const {
  auto &val = underlying_repr().getFields();
  return ::mx::ir::Region(module_, val);
}

std::string_view StructDeclOp::name(void) const {
  auto val = underlying_repr().getSymName();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return {};
  }
}

gap::generator<::mx::ir::Type> StructDeclOp::field_types(void) const & {
  auto range = underlying_repr().getFieldTypes();
  for (auto el_ty : range) {
    co_yield ::mx::ir::Type(
        el_ty.getContext(),
        reinterpret_cast<const mlir::TypeStorage *>(
            el_ty.getAsOpaquePointer()));
  }
}

::mx::ir::Type StructDeclOp::defined_type(void) const {
  auto mlir_type = underlying_repr().getDefinedType();
  return ::mx::ir::Type(
      mlir_type.getContext(),
      reinterpret_cast<const mlir::TypeStorage *>(
          mlir_type.getAsOpaquePointer()));
}

bool StructDeclOp::is_complete_definition(void) const {
  auto val = underlying_repr().isCompleteDefinition();
  return val;
}

::mx::ir::Block StructDeclOp::fields_block(void) const {
  auto &val = underlying_repr().getFieldsBlock();
  return ::mx::ir::Block(module_, val);
}

std::optional<SubFAssignOp> SubFAssignOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::HL_ASSIGN_FSUB) {
    return reinterpret_cast<const SubFAssignOp &>(that);
  }
  return std::nullopt;
}

std::optional<SubFAssignOp> SubFAssignOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::vast::hl::SubFAssignOp SubFAssignOp::underlying_repr(void) const noexcept {
  return ::vast::hl::SubFAssignOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value SubFAssignOp::source(void) const {
  auto val = underlying_repr().getSrc();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value SubFAssignOp::destination(void) const {
  auto val = underlying_repr().getDst();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value SubFAssignOp::result(void) const {
  auto val = underlying_repr().getResult();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<SubFOp> SubFOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::HL_FSUB) {
    return reinterpret_cast<const SubFOp &>(that);
  }
  return std::nullopt;
}

std::optional<SubFOp> SubFOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::vast::hl::SubFOp SubFOp::underlying_repr(void) const noexcept {
  return ::vast::hl::SubFOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value SubFOp::left(void) const {
  auto val = underlying_repr().getLhs();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value SubFOp::right(void) const {
  auto val = underlying_repr().getRhs();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value SubFOp::result(void) const {
  auto val = underlying_repr().getResult();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<SubIAssignOp> SubIAssignOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::HL_ASSIGN_SUB) {
    return reinterpret_cast<const SubIAssignOp &>(that);
  }
  return std::nullopt;
}

std::optional<SubIAssignOp> SubIAssignOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::vast::hl::SubIAssignOp SubIAssignOp::underlying_repr(void) const noexcept {
  return ::vast::hl::SubIAssignOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value SubIAssignOp::source(void) const {
  auto val = underlying_repr().getSrc();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value SubIAssignOp::destination(void) const {
  auto val = underlying_repr().getDst();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value SubIAssignOp::result(void) const {
  auto val = underlying_repr().getResult();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<SubIOp> SubIOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::HL_SUB) {
    return reinterpret_cast<const SubIOp &>(that);
  }
  return std::nullopt;
}

std::optional<SubIOp> SubIOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::vast::hl::SubIOp SubIOp::underlying_repr(void) const noexcept {
  return ::vast::hl::SubIOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value SubIOp::left(void) const {
  auto val = underlying_repr().getLhs();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value SubIOp::right(void) const {
  auto val = underlying_repr().getRhs();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value SubIOp::result(void) const {
  auto val = underlying_repr().getResult();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<SubscriptOp> SubscriptOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::HL_SUBSCRIPT) {
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

::vast::hl::SubscriptOp SubscriptOp::underlying_repr(void) const noexcept {
  return ::vast::hl::SubscriptOp(this->::mx::ir::Operation::op_);
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

std::optional<SwitchOp> SwitchOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::HL_SWITCH) {
    return reinterpret_cast<const SwitchOp &>(that);
  }
  return std::nullopt;
}

std::optional<SwitchOp> SwitchOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::vast::hl::SwitchOp SwitchOp::underlying_repr(void) const noexcept {
  return ::vast::hl::SwitchOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Region SwitchOp::condition_region(void) const {
  auto &val = underlying_repr().getCondRegion();
  return ::mx::ir::Region(module_, val);
}

gap::generator<::mx::ir::Region> SwitchOp::cases(void) const & {
  decltype(auto) regions = underlying_repr().getCases();
  for (auto &region : regions) {
    co_yield ::mx::ir::Region(module_, &region);
  }
}

std::optional<ThisOp> ThisOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::HL_THIS) {
    return reinterpret_cast<const ThisOp &>(that);
  }
  return std::nullopt;
}

std::optional<ThisOp> ThisOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::vast::hl::ThisOp ThisOp::underlying_repr(void) const noexcept {
  return ::vast::hl::ThisOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value ThisOp::result(void) const {
  auto val = underlying_repr().getResult();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<TranslationUnitOp> TranslationUnitOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::HL_TRANSLATION_UNIT) {
    return reinterpret_cast<const TranslationUnitOp &>(that);
  }
  return std::nullopt;
}

std::optional<TranslationUnitOp> TranslationUnitOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::vast::hl::TranslationUnitOp TranslationUnitOp::underlying_repr(void) const noexcept {
  return ::vast::hl::TranslationUnitOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Region TranslationUnitOp::body(void) const {
  auto &val = underlying_repr().getBody();
  return ::mx::ir::Region(module_, val);
}

std::optional<TypeAliasOp> TypeAliasOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::HL_ALIAS) {
    return reinterpret_cast<const TypeAliasOp &>(that);
  }
  return std::nullopt;
}

std::optional<TypeAliasOp> TypeAliasOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::vast::hl::TypeAliasOp TypeAliasOp::underlying_repr(void) const noexcept {
  return ::vast::hl::TypeAliasOp(this->::mx::ir::Operation::op_);
}

std::string_view TypeAliasOp::name(void) const {
  auto val = underlying_repr().getSymName();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return {};
  }
}

::mx::ir::Type TypeAliasOp::type(void) const {
  auto mlir_type = underlying_repr().getType();
  return ::mx::ir::Type(
      mlir_type.getContext(),
      reinterpret_cast<const mlir::TypeStorage *>(
          mlir_type.getAsOpaquePointer()));
}

std::optional<TypeDeclOp> TypeDeclOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::HL_TYPE) {
    return reinterpret_cast<const TypeDeclOp &>(that);
  }
  return std::nullopt;
}

std::optional<TypeDeclOp> TypeDeclOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::vast::hl::TypeDeclOp TypeDeclOp::underlying_repr(void) const noexcept {
  return ::vast::hl::TypeDeclOp(this->::mx::ir::Operation::op_);
}

std::string_view TypeDeclOp::name(void) const {
  auto val = underlying_repr().getSymName();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return {};
  }
}

::mx::ir::Type TypeDeclOp::type(void) const {
  auto mlir_type = underlying_repr().getType();
  return ::mx::ir::Type(
      mlir_type.getContext(),
      reinterpret_cast<const mlir::TypeStorage *>(
          mlir_type.getAsOpaquePointer()));
}

::mx::ir::Type TypeDeclOp::defined_type(void) const {
  auto mlir_type = underlying_repr().getDefinedType();
  return ::mx::ir::Type(
      mlir_type.getContext(),
      reinterpret_cast<const mlir::TypeStorage *>(
          mlir_type.getAsOpaquePointer()));
}

std::optional<TypeDefOp> TypeDefOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::HL_TYPEDEF) {
    return reinterpret_cast<const TypeDefOp &>(that);
  }
  return std::nullopt;
}

std::optional<TypeDefOp> TypeDefOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::vast::hl::TypeDefOp TypeDefOp::underlying_repr(void) const noexcept {
  return ::vast::hl::TypeDefOp(this->::mx::ir::Operation::op_);
}

std::string_view TypeDefOp::name(void) const {
  auto val = underlying_repr().getSymName();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return {};
  }
}

::mx::ir::Type TypeDefOp::type(void) const {
  auto mlir_type = underlying_repr().getType();
  return ::mx::ir::Type(
      mlir_type.getContext(),
      reinterpret_cast<const mlir::TypeStorage *>(
          mlir_type.getAsOpaquePointer()));
}

::mx::ir::Type TypeDefOp::defined_type(void) const {
  auto mlir_type = underlying_repr().getDefinedType();
  return ::mx::ir::Type(
      mlir_type.getContext(),
      reinterpret_cast<const mlir::TypeStorage *>(
          mlir_type.getAsOpaquePointer()));
}

std::optional<TypeOfExprOp> TypeOfExprOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::HL_TYPEOF_EXPR) {
    return reinterpret_cast<const TypeOfExprOp &>(that);
  }
  return std::nullopt;
}

std::optional<TypeOfExprOp> TypeOfExprOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::vast::hl::TypeOfExprOp TypeOfExprOp::underlying_repr(void) const noexcept {
  return ::vast::hl::TypeOfExprOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Region TypeOfExprOp::expression(void) const {
  auto &val = underlying_repr().getExpr();
  return ::mx::ir::Region(module_, val);
}

std::string_view TypeOfExprOp::name(void) const {
  auto val = underlying_repr().getName();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return {};
  }
}

::mx::ir::Type TypeOfExprOp::type(void) const {
  auto mlir_type = underlying_repr().getType();
  return ::mx::ir::Type(
      mlir_type.getContext(),
      reinterpret_cast<const mlir::TypeStorage *>(
          mlir_type.getAsOpaquePointer()));
}

std::optional<TypeYieldOp> TypeYieldOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::HL_TYPE_YIELD) {
    return reinterpret_cast<const TypeYieldOp &>(that);
  }
  return std::nullopt;
}

std::optional<TypeYieldOp> TypeYieldOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::vast::hl::TypeYieldOp TypeYieldOp::underlying_repr(void) const noexcept {
  return ::vast::hl::TypeYieldOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value TypeYieldOp::result(void) const {
  auto val = underlying_repr().getResult();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Type TypeYieldOp::yielded(void) const {
  auto mlir_type = underlying_repr().getYielded();
  return ::mx::ir::Type(
      mlir_type.getContext(),
      reinterpret_cast<const mlir::TypeStorage *>(
          mlir_type.getAsOpaquePointer()));
}

std::optional<UnionDeclOp> UnionDeclOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::HL_UNION) {
    return reinterpret_cast<const UnionDeclOp &>(that);
  }
  return std::nullopt;
}

std::optional<UnionDeclOp> UnionDeclOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::vast::hl::UnionDeclOp UnionDeclOp::underlying_repr(void) const noexcept {
  return ::vast::hl::UnionDeclOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Region UnionDeclOp::fields(void) const {
  auto &val = underlying_repr().getFields();
  return ::mx::ir::Region(module_, val);
}

std::string_view UnionDeclOp::name(void) const {
  auto val = underlying_repr().getSymName();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return {};
  }
}

gap::generator<::mx::ir::Type> UnionDeclOp::field_types(void) const & {
  auto range = underlying_repr().getFieldTypes();
  for (auto el_ty : range) {
    co_yield ::mx::ir::Type(
        el_ty.getContext(),
        reinterpret_cast<const mlir::TypeStorage *>(
            el_ty.getAsOpaquePointer()));
  }
}

::mx::ir::Type UnionDeclOp::defined_type(void) const {
  auto mlir_type = underlying_repr().getDefinedType();
  return ::mx::ir::Type(
      mlir_type.getContext(),
      reinterpret_cast<const mlir::TypeStorage *>(
          mlir_type.getAsOpaquePointer()));
}

bool UnionDeclOp::is_complete_definition(void) const {
  auto val = underlying_repr().isCompleteDefinition();
  return val;
}

::mx::ir::Block UnionDeclOp::fields_block(void) const {
  auto &val = underlying_repr().getFieldsBlock();
  return ::mx::ir::Block(module_, val);
}

std::optional<UnreachableOp> UnreachableOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::HL_UNREACHABLE) {
    return reinterpret_cast<const UnreachableOp &>(that);
  }
  return std::nullopt;
}

std::optional<UnreachableOp> UnreachableOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::vast::hl::UnreachableOp UnreachableOp::underlying_repr(void) const noexcept {
  return ::vast::hl::UnreachableOp(this->::mx::ir::Operation::op_);
}

std::optional<VAArgExprOp> VAArgExprOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::HL_VA_ARG_EXPR) {
    return reinterpret_cast<const VAArgExprOp &>(that);
  }
  return std::nullopt;
}

std::optional<VAArgExprOp> VAArgExprOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::vast::hl::VAArgExpr VAArgExprOp::underlying_repr(void) const noexcept {
  return ::vast::hl::VAArgExpr(this->::mx::ir::Operation::op_);
}

::mx::ir::Value VAArgExprOp::argument_list(void) const {
  auto val = underlying_repr().getArgList();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value VAArgExprOp::result(void) const {
  auto val = underlying_repr().getResult();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<ValueYieldOp> ValueYieldOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::HL_VALUE_YIELD) {
    return reinterpret_cast<const ValueYieldOp &>(that);
  }
  return std::nullopt;
}

std::optional<ValueYieldOp> ValueYieldOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::vast::hl::ValueYieldOp ValueYieldOp::underlying_repr(void) const noexcept {
  return ::vast::hl::ValueYieldOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value ValueYieldOp::result(void) const {
  auto val = underlying_repr().getResult();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<VarDeclOp> VarDeclOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::HL_VAR) {
    return reinterpret_cast<const VarDeclOp &>(that);
  }
  return std::nullopt;
}

std::optional<VarDeclOp> VarDeclOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::vast::hl::VarDeclOp VarDeclOp::underlying_repr(void) const noexcept {
  return ::vast::hl::VarDeclOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value VarDeclOp::result(void) const {
  auto val = underlying_repr().getResult();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<::mx::ir::Region> VarDeclOp::initializer(void) const {
  decltype(auto) opt_val = underlying_repr().getInitializer();
  if (opt_val.empty()) {
    return std::nullopt;
  }
  auto &val = opt_val;
  return ::mx::ir::Region(module_, val);
}

std::optional<::mx::ir::Region> VarDeclOp::allocation_size(void) const {
  decltype(auto) opt_val = underlying_repr().getAllocationSize();
  if (opt_val.empty()) {
    return std::nullopt;
  }
  auto &val = opt_val;
  return ::mx::ir::Region(module_, val);
}

std::string_view VarDeclOp::name(void) const {
  auto val = underlying_repr().getSymName();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return {};
  }
}

bool VarDeclOp::has_local_storage(void) const {
  auto val = underlying_repr().hasLocalStorage();
  return val;
}

bool VarDeclOp::is_local_variable_declaration(void) const {
  auto val = underlying_repr().isLocalVarDecl();
  return val;
}

bool VarDeclOp::is_static_local_variable_declaration(void) const {
  auto val = underlying_repr().isStaticLocal();
  return val;
}

bool VarDeclOp::has_external_storage(void) const {
  auto val = underlying_repr().hasExternalStorage();
  return val;
}

bool VarDeclOp::has_global_storage(void) const {
  auto val = underlying_repr().hasGlobalStorage();
  return val;
}

bool VarDeclOp::is_static_data_member(void) const {
  auto val = underlying_repr().isStaticDataMember();
  return val;
}

bool VarDeclOp::is_in_file_context(void) const {
  auto val = underlying_repr().isInFileContext();
  return val;
}

bool VarDeclOp::is_in_function_or_method_context(void) const {
  auto val = underlying_repr().isInFunctionOrMethodContext();
  return val;
}

bool VarDeclOp::is_in_record_context(void) const {
  auto val = underlying_repr().isInRecordContext();
  return val;
}

bool VarDeclOp::is_file_variable_declaration(void) const {
  auto val = underlying_repr().isFileVarDecl();
  return val;
}

std::optional<WhileOp> WhileOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::HL_WHILE) {
    return reinterpret_cast<const WhileOp &>(that);
  }
  return std::nullopt;
}

std::optional<WhileOp> WhileOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::vast::hl::WhileOp WhileOp::underlying_repr(void) const noexcept {
  return ::vast::hl::WhileOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Region WhileOp::condition_region(void) const {
  auto &val = underlying_repr().getCondRegion();
  return ::mx::ir::Region(module_, val);
}

::mx::ir::Region WhileOp::body_region(void) const {
  auto &val = underlying_repr().getBodyRegion();
  return ::mx::ir::Region(module_, val);
}

}  // namespace mx::ir::hl
