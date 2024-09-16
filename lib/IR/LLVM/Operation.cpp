// Copyright (c) 2023-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/IR/LLVM/Operation.h>

#include <multiplier/IR/Attribute.h>
#include <multiplier/IR/Block.h>
#include <multiplier/IR/Region.h>
#include <multiplier/IR/Type.h>

#include <ios>
#include <string>

#include <mlir/Dialect/LLVMIR/LLVMDialect.h>

namespace mx::ir::llvm {
std::optional<Operation> Operation::from(const ::mx::ir::Operation &that) {
  if (IsLLVMIROperationKind(that.kind())) {
    return reinterpret_cast<const Operation &>(that);
  }
  return std::nullopt;
}

std::optional<AShrOp> AShrOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_ASHR) {
    return reinterpret_cast<const AShrOp &>(that);
  }
  return std::nullopt;
}

std::optional<AShrOp> AShrOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::AShrOp AShrOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::AShrOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value AShrOp::left(void) const {
  auto val = underlying_repr().getLhs();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value AShrOp::right(void) const {
  auto val = underlying_repr().getRhs();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value AShrOp::result(void) const {
  auto val = underlying_repr().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<AddOp> AddOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_ADD) {
    return reinterpret_cast<const AddOp &>(that);
  }
  return std::nullopt;
}

std::optional<AddOp> AddOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::AddOp AddOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::AddOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value AddOp::left(void) const {
  auto val = underlying_repr().getLhs();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value AddOp::right(void) const {
  auto val = underlying_repr().getRhs();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value AddOp::result(void) const {
  auto val = underlying_repr().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<AddrSpaceCastOp> AddrSpaceCastOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_ADDRSPACECAST) {
    return reinterpret_cast<const AddrSpaceCastOp &>(that);
  }
  return std::nullopt;
}

std::optional<AddrSpaceCastOp> AddrSpaceCastOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::AddrSpaceCastOp AddrSpaceCastOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::AddrSpaceCastOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value AddrSpaceCastOp::argument(void) const {
  auto val = underlying_repr().getArg();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value AddrSpaceCastOp::result(void) const {
  auto val = underlying_repr().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<AddressOfOp> AddressOfOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_MLIR_ADDRESSOF) {
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

::mlir::LLVM::AddressOfOp AddressOfOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::AddressOfOp(this->::mx::ir::Operation::op_);
}

std::string_view AddressOfOp::global_name(void) const {
  auto val = underlying_repr().getGlobalName();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return {};
  }
}

std::optional<AllocaOp> AllocaOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_ALLOCA) {
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

::mlir::LLVM::AllocaOp AllocaOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::AllocaOp(this->::mx::ir::Operation::op_);
}

std::optional<unsigned long long> AllocaOp::alignment(void) const {
  auto opt_val = underlying_repr().getAlignment();
  if (!opt_val) {
    return std::nullopt;
  }
  auto &val = opt_val.value();
  return val;
}

::mx::ir::Type AllocaOp::elem_type(void) const {
  auto mlir_type = underlying_repr().getElemType();
  return ::mx::ir::Type(
      mlir_type.getContext(),
      reinterpret_cast<const mlir::TypeStorage *>(
          mlir_type.getAsOpaquePointer()));
}

bool AllocaOp::inalloca(void) const {
  auto val = underlying_repr().getInalloca();
  return val;
}

std::optional<AndOp> AndOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_AND) {
    return reinterpret_cast<const AndOp &>(that);
  }
  return std::nullopt;
}

std::optional<AndOp> AndOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::AndOp AndOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::AndOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value AndOp::left(void) const {
  auto val = underlying_repr().getLhs();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value AndOp::right(void) const {
  auto val = underlying_repr().getRhs();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value AndOp::result(void) const {
  auto val = underlying_repr().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<AtomicCmpXchgOp> AtomicCmpXchgOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_CMPXCHG) {
    return reinterpret_cast<const AtomicCmpXchgOp &>(that);
  }
  return std::nullopt;
}

std::optional<AtomicCmpXchgOp> AtomicCmpXchgOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::AtomicCmpXchgOp AtomicCmpXchgOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::AtomicCmpXchgOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value AtomicCmpXchgOp::cmp(void) const {
  auto val = underlying_repr().getCmp();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value AtomicCmpXchgOp::value(void) const {
  auto val = underlying_repr().getVal();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value AtomicCmpXchgOp::result(void) const {
  auto val = underlying_repr().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<std::string_view> AtomicCmpXchgOp::syncscope(void) const {
  auto opt_val = underlying_repr().getSyncscope();
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

std::optional<unsigned long long> AtomicCmpXchgOp::alignment(void) const {
  auto opt_val = underlying_repr().getAlignment();
  if (!opt_val) {
    return std::nullopt;
  }
  auto &val = opt_val.value();
  return val;
}

bool AtomicCmpXchgOp::weak(void) const {
  auto val = underlying_repr().getWeak();
  return val;
}

bool AtomicCmpXchgOp::volatile__(void) const {
  auto val = underlying_repr().getVolatile_();
  return val;
}

std::optional<AtomicRMWOp> AtomicRMWOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_ATOMICRMW) {
    return reinterpret_cast<const AtomicRMWOp &>(that);
  }
  return std::nullopt;
}

std::optional<AtomicRMWOp> AtomicRMWOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::AtomicRMWOp AtomicRMWOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::AtomicRMWOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value AtomicRMWOp::value(void) const {
  auto val = underlying_repr().getVal();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value AtomicRMWOp::result(void) const {
  auto val = underlying_repr().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<std::string_view> AtomicRMWOp::syncscope(void) const {
  auto opt_val = underlying_repr().getSyncscope();
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

std::optional<unsigned long long> AtomicRMWOp::alignment(void) const {
  auto opt_val = underlying_repr().getAlignment();
  if (!opt_val) {
    return std::nullopt;
  }
  auto &val = opt_val.value();
  return val;
}

bool AtomicRMWOp::volatile__(void) const {
  auto val = underlying_repr().getVolatile_();
  return val;
}

std::optional<BitcastOp> BitcastOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_BITCAST) {
    return reinterpret_cast<const BitcastOp &>(that);
  }
  return std::nullopt;
}

std::optional<BitcastOp> BitcastOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::BitcastOp BitcastOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::BitcastOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value BitcastOp::argument(void) const {
  auto val = underlying_repr().getArg();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value BitcastOp::result(void) const {
  auto val = underlying_repr().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<BrOp> BrOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_BR) {
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

::mlir::LLVM::BrOp BrOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::BrOp(this->::mx::ir::Operation::op_);
}

gap::generator<::mx::ir::Operand> BrOp::dest_operands(void) const & {
  auto range = underlying_repr().getDestOperands();
  for (auto val : range) {
    co_yield ::mx::ir::Operand(module_, val.getAsOpaquePointer());
  }
}

std::optional<CallIntrinsicOp> CallIntrinsicOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_CALL_INTRINSIC) {
    return reinterpret_cast<const CallIntrinsicOp &>(that);
  }
  return std::nullopt;
}

std::optional<CallIntrinsicOp> CallIntrinsicOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::CallIntrinsicOp CallIntrinsicOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::CallIntrinsicOp(this->::mx::ir::Operation::op_);
}

gap::generator<::mx::ir::Operand> CallIntrinsicOp::arguments(void) const & {
  auto range = underlying_repr().getArgs();
  for (auto val : range) {
    co_yield ::mx::ir::Operand(module_, val.getAsOpaquePointer());
  }
}

::mx::ir::Value CallIntrinsicOp::results(void) const {
  auto val = underlying_repr().getResults();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::string_view CallIntrinsicOp::intrin(void) const {
  auto val = underlying_repr().getIntrin();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return {};
  }
}

std::optional<CallOp> CallOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_CALL) {
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

::mlir::LLVM::CallOp CallOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::CallOp(this->::mx::ir::Operation::op_);
}

gap::generator<::mx::ir::Operand> CallOp::callee_operands(void) const & {
  auto range = underlying_repr().getCalleeOperands();
  for (auto val : range) {
    co_yield ::mx::ir::Operand(module_, val.getAsOpaquePointer());
  }
}

::mx::ir::Value CallOp::result(void) const {
  auto val = underlying_repr().getResult();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<std::string_view> CallOp::callee(void) const {
  auto opt_val = underlying_repr().getCallee();
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

gap::generator<::mx::ir::Operand> CallOp::arg_operands(void) const & {
  auto range = underlying_repr().getArgOperands();
  for (auto val : range) {
    co_yield ::mx::ir::Operand(module_, val.getAsOpaquePointer());
  }
}

std::optional<ComdatOp> ComdatOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_COMDAT) {
    return reinterpret_cast<const ComdatOp &>(that);
  }
  return std::nullopt;
}

std::optional<ComdatOp> ComdatOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::ComdatOp ComdatOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::ComdatOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Region ComdatOp::body(void) const {
  auto &val = underlying_repr().getBody();
  return ::mx::ir::Region(module_, val);
}

std::string_view ComdatOp::name(void) const {
  auto val = underlying_repr().getSymName();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return {};
  }
}

std::optional<ComdatSelectorOp> ComdatSelectorOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_COMDAT_SELECTOR) {
    return reinterpret_cast<const ComdatSelectorOp &>(that);
  }
  return std::nullopt;
}

std::optional<ComdatSelectorOp> ComdatSelectorOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::ComdatSelectorOp ComdatSelectorOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::ComdatSelectorOp(this->::mx::ir::Operation::op_);
}

std::string_view ComdatSelectorOp::name(void) const {
  auto val = underlying_repr().getSymName();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return {};
  }
}

std::optional<CondBrOp> CondBrOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_COND_BR) {
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

::mlir::LLVM::CondBrOp CondBrOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::CondBrOp(this->::mx::ir::Operation::op_);
}

gap::generator<::mx::ir::Operand> CondBrOp::true_dest_operands(void) const & {
  auto range = underlying_repr().getTrueDestOperands();
  for (auto val : range) {
    co_yield ::mx::ir::Operand(module_, val.getAsOpaquePointer());
  }
}

gap::generator<::mx::ir::Operand> CondBrOp::false_dest_operands(void) const & {
  auto range = underlying_repr().getFalseDestOperands();
  for (auto val : range) {
    co_yield ::mx::ir::Operand(module_, val.getAsOpaquePointer());
  }
}

std::optional<ConstantOp> ConstantOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_MLIR_CONSTANT) {
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

::mlir::LLVM::ConstantOp ConstantOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::ConstantOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value ConstantOp::result(void) const {
  auto val = underlying_repr().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<ExtractElementOp> ExtractElementOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_EXTRACTELEMENT) {
    return reinterpret_cast<const ExtractElementOp &>(that);
  }
  return std::nullopt;
}

std::optional<ExtractElementOp> ExtractElementOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::ExtractElementOp ExtractElementOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::ExtractElementOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value ExtractElementOp::vector(void) const {
  auto val = underlying_repr().getVector();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value ExtractElementOp::result(void) const {
  auto val = underlying_repr().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<ExtractValueOp> ExtractValueOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_EXTRACTVALUE) {
    return reinterpret_cast<const ExtractValueOp &>(that);
  }
  return std::nullopt;
}

std::optional<ExtractValueOp> ExtractValueOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::ExtractValueOp ExtractValueOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::ExtractValueOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value ExtractValueOp::container(void) const {
  auto val = underlying_repr().getContainer();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value ExtractValueOp::result(void) const {
  auto val = underlying_repr().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<FAddOp> FAddOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_FADD) {
    return reinterpret_cast<const FAddOp &>(that);
  }
  return std::nullopt;
}

std::optional<FAddOp> FAddOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::FAddOp FAddOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::FAddOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value FAddOp::left(void) const {
  auto val = underlying_repr().getLhs();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value FAddOp::right(void) const {
  auto val = underlying_repr().getRhs();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value FAddOp::result(void) const {
  auto val = underlying_repr().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<FCmpOp> FCmpOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_FCMP) {
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

::mlir::LLVM::FCmpOp FCmpOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::FCmpOp(this->::mx::ir::Operation::op_);
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
  auto val = underlying_repr().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<FDivOp> FDivOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_FDIV) {
    return reinterpret_cast<const FDivOp &>(that);
  }
  return std::nullopt;
}

std::optional<FDivOp> FDivOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::FDivOp FDivOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::FDivOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value FDivOp::left(void) const {
  auto val = underlying_repr().getLhs();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value FDivOp::right(void) const {
  auto val = underlying_repr().getRhs();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value FDivOp::result(void) const {
  auto val = underlying_repr().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<FMulOp> FMulOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_FMUL) {
    return reinterpret_cast<const FMulOp &>(that);
  }
  return std::nullopt;
}

std::optional<FMulOp> FMulOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::FMulOp FMulOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::FMulOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value FMulOp::left(void) const {
  auto val = underlying_repr().getLhs();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value FMulOp::right(void) const {
  auto val = underlying_repr().getRhs();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value FMulOp::result(void) const {
  auto val = underlying_repr().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<FNegOp> FNegOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_FNEG) {
    return reinterpret_cast<const FNegOp &>(that);
  }
  return std::nullopt;
}

std::optional<FNegOp> FNegOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::FNegOp FNegOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::FNegOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value FNegOp::operand(void) const {
  auto val = underlying_repr().getOperand();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value FNegOp::result(void) const {
  auto val = underlying_repr().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<FPExtOp> FPExtOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_FPEXT) {
    return reinterpret_cast<const FPExtOp &>(that);
  }
  return std::nullopt;
}

std::optional<FPExtOp> FPExtOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::FPExtOp FPExtOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::FPExtOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value FPExtOp::argument(void) const {
  auto val = underlying_repr().getArg();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value FPExtOp::result(void) const {
  auto val = underlying_repr().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<FPToSIOp> FPToSIOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_FPTOSI) {
    return reinterpret_cast<const FPToSIOp &>(that);
  }
  return std::nullopt;
}

std::optional<FPToSIOp> FPToSIOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::FPToSIOp FPToSIOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::FPToSIOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value FPToSIOp::argument(void) const {
  auto val = underlying_repr().getArg();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value FPToSIOp::result(void) const {
  auto val = underlying_repr().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<FPToUIOp> FPToUIOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_FPTOUI) {
    return reinterpret_cast<const FPToUIOp &>(that);
  }
  return std::nullopt;
}

std::optional<FPToUIOp> FPToUIOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::FPToUIOp FPToUIOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::FPToUIOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value FPToUIOp::argument(void) const {
  auto val = underlying_repr().getArg();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value FPToUIOp::result(void) const {
  auto val = underlying_repr().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<FPTruncOp> FPTruncOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_FPTRUNC) {
    return reinterpret_cast<const FPTruncOp &>(that);
  }
  return std::nullopt;
}

std::optional<FPTruncOp> FPTruncOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::FPTruncOp FPTruncOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::FPTruncOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value FPTruncOp::argument(void) const {
  auto val = underlying_repr().getArg();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value FPTruncOp::result(void) const {
  auto val = underlying_repr().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<FRemOp> FRemOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_FREM) {
    return reinterpret_cast<const FRemOp &>(that);
  }
  return std::nullopt;
}

std::optional<FRemOp> FRemOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::FRemOp FRemOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::FRemOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value FRemOp::left(void) const {
  auto val = underlying_repr().getLhs();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value FRemOp::right(void) const {
  auto val = underlying_repr().getRhs();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value FRemOp::result(void) const {
  auto val = underlying_repr().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<FSubOp> FSubOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_FSUB) {
    return reinterpret_cast<const FSubOp &>(that);
  }
  return std::nullopt;
}

std::optional<FSubOp> FSubOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::FSubOp FSubOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::FSubOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value FSubOp::left(void) const {
  auto val = underlying_repr().getLhs();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value FSubOp::right(void) const {
  auto val = underlying_repr().getRhs();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value FSubOp::result(void) const {
  auto val = underlying_repr().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<FenceOp> FenceOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_FENCE) {
    return reinterpret_cast<const FenceOp &>(that);
  }
  return std::nullopt;
}

std::optional<FenceOp> FenceOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::FenceOp FenceOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::FenceOp(this->::mx::ir::Operation::op_);
}

std::optional<std::string_view> FenceOp::syncscope(void) const {
  auto opt_val = underlying_repr().getSyncscope();
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

std::optional<FreezeOp> FreezeOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_FREEZE) {
    return reinterpret_cast<const FreezeOp &>(that);
  }
  return std::nullopt;
}

std::optional<FreezeOp> FreezeOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::FreezeOp FreezeOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::FreezeOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value FreezeOp::value(void) const {
  auto val = underlying_repr().getVal();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value FreezeOp::result(void) const {
  auto val = underlying_repr().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<GetElementPtrOp> GetElementPtrOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_GETELEMENTPTR) {
    return reinterpret_cast<const GetElementPtrOp &>(that);
  }
  return std::nullopt;
}

std::optional<GetElementPtrOp> GetElementPtrOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::GEPOp GetElementPtrOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::GEPOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value GetElementPtrOp::base(void) const {
  auto val = underlying_repr().getBase();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

gap::generator<::mx::ir::Operand> GetElementPtrOp::dynamic_indices(void) const & {
  auto range = underlying_repr().getDynamicIndices();
  for (auto val : range) {
    co_yield ::mx::ir::Operand(module_, val.getAsOpaquePointer());
  }
}

::mx::ir::Value GetElementPtrOp::result(void) const {
  auto val = underlying_repr().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Type GetElementPtrOp::elem_type(void) const {
  auto mlir_type = underlying_repr().getElemType();
  return ::mx::ir::Type(
      mlir_type.getContext(),
      reinterpret_cast<const mlir::TypeStorage *>(
          mlir_type.getAsOpaquePointer()));
}

bool GetElementPtrOp::inbounds(void) const {
  auto val = underlying_repr().getInbounds();
  return val;
}

std::optional<GlobalCtorsOp> GlobalCtorsOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_MLIR_GLOBAL_CTORS) {
    return reinterpret_cast<const GlobalCtorsOp &>(that);
  }
  return std::nullopt;
}

std::optional<GlobalCtorsOp> GlobalCtorsOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::GlobalCtorsOp GlobalCtorsOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::GlobalCtorsOp(this->::mx::ir::Operation::op_);
}

std::optional<GlobalDtorsOp> GlobalDtorsOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_MLIR_GLOBAL_DTORS) {
    return reinterpret_cast<const GlobalDtorsOp &>(that);
  }
  return std::nullopt;
}

std::optional<GlobalDtorsOp> GlobalDtorsOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::GlobalDtorsOp GlobalDtorsOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::GlobalDtorsOp(this->::mx::ir::Operation::op_);
}

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

::mlir::LLVM::GlobalOp GlobalOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::GlobalOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Region GlobalOp::initializer(void) const {
  auto &val = underlying_repr().getInitializer();
  return ::mx::ir::Region(module_, val);
}

::mx::ir::Type GlobalOp::global_type(void) const {
  auto mlir_type = underlying_repr().getGlobalType();
  return ::mx::ir::Type(
      mlir_type.getContext(),
      reinterpret_cast<const mlir::TypeStorage *>(
          mlir_type.getAsOpaquePointer()));
}

bool GlobalOp::constant(void) const {
  auto val = underlying_repr().getConstant();
  return val;
}

std::string_view GlobalOp::name(void) const {
  auto val = underlying_repr().getSymName();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return {};
  }
}

bool GlobalOp::dso_local(void) const {
  auto val = underlying_repr().getDsoLocal();
  return val;
}

bool GlobalOp::thread_local__(void) const {
  auto val = underlying_repr().getThreadLocal_();
  return val;
}

std::optional<unsigned long long> GlobalOp::alignment(void) const {
  auto opt_val = underlying_repr().getAlignment();
  if (!opt_val) {
    return std::nullopt;
  }
  auto &val = opt_val.value();
  return val;
}

uint32_t GlobalOp::addr_space(void) const {
  auto val = underlying_repr().getAddrSpace();
  return val;
}

std::optional<std::string_view> GlobalOp::section(void) const {
  auto opt_val = underlying_repr().getSection();
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

std::optional<ICmpOp> ICmpOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_ICMP) {
    return reinterpret_cast<const ICmpOp &>(that);
  }
  return std::nullopt;
}

std::optional<ICmpOp> ICmpOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::ICmpOp ICmpOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::ICmpOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value ICmpOp::left(void) const {
  auto val = underlying_repr().getLhs();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value ICmpOp::right(void) const {
  auto val = underlying_repr().getRhs();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value ICmpOp::result(void) const {
  auto val = underlying_repr().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

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

::mlir::LLVM::InlineAsmOp InlineAsmOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::InlineAsmOp(this->::mx::ir::Operation::op_);
}

gap::generator<::mx::ir::Operand> InlineAsmOp::operands(void) const & {
  auto range = underlying_repr().getOperands();
  for (auto val : range) {
    co_yield ::mx::ir::Operand(module_, val.getAsOpaquePointer());
  }
}

::mx::ir::Value InlineAsmOp::result(void) const {
  auto val = underlying_repr().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::string_view InlineAsmOp::assembly(void) const {
  auto val = underlying_repr().getAsmString();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return {};
  }
}

std::string_view InlineAsmOp::constraints(void) const {
  auto val = underlying_repr().getConstraints();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return {};
  }
}

bool InlineAsmOp::has_side_effects(void) const {
  auto val = underlying_repr().getHasSideEffects();
  return val;
}

bool InlineAsmOp::is_align_stack(void) const {
  auto val = underlying_repr().getIsAlignStack();
  return val;
}

std::optional<InsertElementOp> InsertElementOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INSERTELEMENT) {
    return reinterpret_cast<const InsertElementOp &>(that);
  }
  return std::nullopt;
}

std::optional<InsertElementOp> InsertElementOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::InsertElementOp InsertElementOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::InsertElementOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value InsertElementOp::vector(void) const {
  auto val = underlying_repr().getVector();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value InsertElementOp::value(void) const {
  auto val = underlying_repr().getValue();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value InsertElementOp::result(void) const {
  auto val = underlying_repr().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<InsertValueOp> InsertValueOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INSERTVALUE) {
    return reinterpret_cast<const InsertValueOp &>(that);
  }
  return std::nullopt;
}

std::optional<InsertValueOp> InsertValueOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::InsertValueOp InsertValueOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::InsertValueOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value InsertValueOp::container(void) const {
  auto val = underlying_repr().getContainer();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value InsertValueOp::value(void) const {
  auto val = underlying_repr().getValue();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value InsertValueOp::result(void) const {
  auto val = underlying_repr().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<IntToPtrOp> IntToPtrOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTTOPTR) {
    return reinterpret_cast<const IntToPtrOp &>(that);
  }
  return std::nullopt;
}

std::optional<IntToPtrOp> IntToPtrOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::IntToPtrOp IntToPtrOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::IntToPtrOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value IntToPtrOp::argument(void) const {
  auto val = underlying_repr().getArg();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value IntToPtrOp::result(void) const {
  auto val = underlying_repr().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<InvokeOp> InvokeOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INVOKE) {
    return reinterpret_cast<const InvokeOp &>(that);
  }
  return std::nullopt;
}

std::optional<InvokeOp> InvokeOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::InvokeOp InvokeOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::InvokeOp(this->::mx::ir::Operation::op_);
}

gap::generator<::mx::ir::Operand> InvokeOp::callee_operands(void) const & {
  auto range = underlying_repr().getCalleeOperands();
  for (auto val : range) {
    co_yield ::mx::ir::Operand(module_, val.getAsOpaquePointer());
  }
}

gap::generator<::mx::ir::Operand> InvokeOp::normal_dest_operands(void) const & {
  auto range = underlying_repr().getNormalDestOperands();
  for (auto val : range) {
    co_yield ::mx::ir::Operand(module_, val.getAsOpaquePointer());
  }
}

gap::generator<::mx::ir::Operand> InvokeOp::unwind_dest_operands(void) const & {
  auto range = underlying_repr().getUnwindDestOperands();
  for (auto val : range) {
    co_yield ::mx::ir::Operand(module_, val.getAsOpaquePointer());
  }
}

std::optional<std::string_view> InvokeOp::callee(void) const {
  auto opt_val = underlying_repr().getCallee();
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

gap::generator<::mx::ir::Operand> InvokeOp::arg_operands(void) const & {
  auto range = underlying_repr().getArgOperands();
  for (auto val : range) {
    co_yield ::mx::ir::Operand(module_, val.getAsOpaquePointer());
  }
}

std::optional<FuncOp> FuncOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_FUNC) {
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

::mlir::LLVM::LLVMFuncOp FuncOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::LLVMFuncOp(this->::mx::ir::Operation::op_);
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

bool FuncOp::dso_local(void) const {
  auto val = underlying_repr().getDsoLocal();
  return val;
}

std::optional<std::string_view> FuncOp::personality(void) const {
  auto opt_val = underlying_repr().getPersonality();
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

std::optional<std::string_view> FuncOp::garbage_collector(void) const {
  auto opt_val = underlying_repr().getGarbageCollector();
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

std::optional<unsigned long long> FuncOp::function_entry_count(void) const {
  auto opt_val = underlying_repr().getFunctionEntryCount();
  if (!opt_val) {
    return std::nullopt;
  }
  auto &val = opt_val.value();
  return val;
}

std::optional<bool> FuncOp::arm_streaming(void) const {
  auto opt_val = underlying_repr().getArmStreaming();
  if (!opt_val) {
    return std::nullopt;
  }
  auto &val = opt_val.value();
  return val;
}

std::optional<bool> FuncOp::arm_locally_streaming(void) const {
  auto opt_val = underlying_repr().getArmLocallyStreaming();
  if (!opt_val) {
    return std::nullopt;
  }
  auto &val = opt_val.value();
  return val;
}

std::optional<bool> FuncOp::arm_streaming_compatible(void) const {
  auto opt_val = underlying_repr().getArmStreamingCompatible();
  if (!opt_val) {
    return std::nullopt;
  }
  auto &val = opt_val.value();
  return val;
}

std::optional<bool> FuncOp::arm_new_za(void) const {
  auto opt_val = underlying_repr().getArmNewZa();
  if (!opt_val) {
    return std::nullopt;
  }
  auto &val = opt_val.value();
  return val;
}

std::optional<bool> FuncOp::arm_preserves_za(void) const {
  auto opt_val = underlying_repr().getArmPreservesZa();
  if (!opt_val) {
    return std::nullopt;
  }
  auto &val = opt_val.value();
  return val;
}

std::optional<bool> FuncOp::arm_shared_za(void) const {
  auto opt_val = underlying_repr().getArmSharedZa();
  if (!opt_val) {
    return std::nullopt;
  }
  auto &val = opt_val.value();
  return val;
}

std::optional<std::string_view> FuncOp::section(void) const {
  auto opt_val = underlying_repr().getSection();
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

std::optional<unsigned long long> FuncOp::alignment(void) const {
  auto opt_val = underlying_repr().getAlignment();
  if (!opt_val) {
    return std::nullopt;
  }
  auto &val = opt_val.value();
  return val;
}

std::optional<std::string_view> FuncOp::target_cpu(void) const {
  auto opt_val = underlying_repr().getTargetCpu();
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

std::optional<LShrOp> LShrOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_LSHR) {
    return reinterpret_cast<const LShrOp &>(that);
  }
  return std::nullopt;
}

std::optional<LShrOp> LShrOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::LShrOp LShrOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::LShrOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value LShrOp::left(void) const {
  auto val = underlying_repr().getLhs();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value LShrOp::right(void) const {
  auto val = underlying_repr().getRhs();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value LShrOp::result(void) const {
  auto val = underlying_repr().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<LandingpadOp> LandingpadOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_LANDINGPAD) {
    return reinterpret_cast<const LandingpadOp &>(that);
  }
  return std::nullopt;
}

std::optional<LandingpadOp> LandingpadOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::LandingpadOp LandingpadOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::LandingpadOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value LandingpadOp::result(void) const {
  auto val = underlying_repr().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

bool LandingpadOp::cleanup(void) const {
  auto val = underlying_repr().getCleanup();
  return val;
}

std::optional<LinkerOptionsOp> LinkerOptionsOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_LINKER_OPTIONS) {
    return reinterpret_cast<const LinkerOptionsOp &>(that);
  }
  return std::nullopt;
}

std::optional<LinkerOptionsOp> LinkerOptionsOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::LinkerOptionsOp LinkerOptionsOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::LinkerOptionsOp(this->::mx::ir::Operation::op_);
}

std::optional<LoadOp> LoadOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_LOAD) {
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

::mlir::LLVM::LoadOp LoadOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::LoadOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value LoadOp::result(void) const {
  auto val = underlying_repr().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<unsigned long long> LoadOp::alignment(void) const {
  auto opt_val = underlying_repr().getAlignment();
  if (!opt_val) {
    return std::nullopt;
  }
  auto &val = opt_val.value();
  return val;
}

bool LoadOp::volatile__(void) const {
  auto val = underlying_repr().getVolatile_();
  return val;
}

bool LoadOp::nontemporal(void) const {
  auto val = underlying_repr().getNontemporal();
  return val;
}

bool LoadOp::invariant(void) const {
  auto val = underlying_repr().getInvariant();
  return val;
}

std::optional<std::string_view> LoadOp::syncscope(void) const {
  auto opt_val = underlying_repr().getSyncscope();
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

std::optional<MulOp> MulOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_MUL) {
    return reinterpret_cast<const MulOp &>(that);
  }
  return std::nullopt;
}

std::optional<MulOp> MulOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::MulOp MulOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::MulOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value MulOp::left(void) const {
  auto val = underlying_repr().getLhs();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value MulOp::right(void) const {
  auto val = underlying_repr().getRhs();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value MulOp::result(void) const {
  auto val = underlying_repr().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<NoneTokenOp> NoneTokenOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_MLIR_NONE) {
    return reinterpret_cast<const NoneTokenOp &>(that);
  }
  return std::nullopt;
}

std::optional<NoneTokenOp> NoneTokenOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::NoneTokenOp NoneTokenOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::NoneTokenOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value NoneTokenOp::result(void) const {
  auto val = underlying_repr().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<OrOp> OrOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_OR) {
    return reinterpret_cast<const OrOp &>(that);
  }
  return std::nullopt;
}

std::optional<OrOp> OrOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::OrOp OrOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::OrOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value OrOp::left(void) const {
  auto val = underlying_repr().getLhs();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value OrOp::right(void) const {
  auto val = underlying_repr().getRhs();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value OrOp::result(void) const {
  auto val = underlying_repr().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<PoisonOp> PoisonOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_MLIR_POISON) {
    return reinterpret_cast<const PoisonOp &>(that);
  }
  return std::nullopt;
}

std::optional<PoisonOp> PoisonOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::PoisonOp PoisonOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::PoisonOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value PoisonOp::result(void) const {
  auto val = underlying_repr().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<PtrToIntOp> PtrToIntOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_PTRTOINT) {
    return reinterpret_cast<const PtrToIntOp &>(that);
  }
  return std::nullopt;
}

std::optional<PtrToIntOp> PtrToIntOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::PtrToIntOp PtrToIntOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::PtrToIntOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value PtrToIntOp::argument(void) const {
  auto val = underlying_repr().getArg();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value PtrToIntOp::result(void) const {
  auto val = underlying_repr().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<ResumeOp> ResumeOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_RESUME) {
    return reinterpret_cast<const ResumeOp &>(that);
  }
  return std::nullopt;
}

std::optional<ResumeOp> ResumeOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::ResumeOp ResumeOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::ResumeOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value ResumeOp::value(void) const {
  auto val = underlying_repr().getValue();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<ReturnOp> ReturnOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_RETURN) {
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

::mlir::LLVM::ReturnOp ReturnOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::ReturnOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value ReturnOp::argument(void) const {
  auto val = underlying_repr().getArg();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<SDivOp> SDivOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_SDIV) {
    return reinterpret_cast<const SDivOp &>(that);
  }
  return std::nullopt;
}

std::optional<SDivOp> SDivOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::SDivOp SDivOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::SDivOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value SDivOp::left(void) const {
  auto val = underlying_repr().getLhs();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value SDivOp::right(void) const {
  auto val = underlying_repr().getRhs();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value SDivOp::result(void) const {
  auto val = underlying_repr().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<SExtOp> SExtOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_SEXT) {
    return reinterpret_cast<const SExtOp &>(that);
  }
  return std::nullopt;
}

std::optional<SExtOp> SExtOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::SExtOp SExtOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::SExtOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value SExtOp::argument(void) const {
  auto val = underlying_repr().getArg();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value SExtOp::result(void) const {
  auto val = underlying_repr().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<SIToFPOp> SIToFPOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_SITOFP) {
    return reinterpret_cast<const SIToFPOp &>(that);
  }
  return std::nullopt;
}

std::optional<SIToFPOp> SIToFPOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::SIToFPOp SIToFPOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::SIToFPOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value SIToFPOp::argument(void) const {
  auto val = underlying_repr().getArg();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value SIToFPOp::result(void) const {
  auto val = underlying_repr().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<SRemOp> SRemOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_SREM) {
    return reinterpret_cast<const SRemOp &>(that);
  }
  return std::nullopt;
}

std::optional<SRemOp> SRemOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::SRemOp SRemOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::SRemOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value SRemOp::left(void) const {
  auto val = underlying_repr().getLhs();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value SRemOp::right(void) const {
  auto val = underlying_repr().getRhs();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value SRemOp::result(void) const {
  auto val = underlying_repr().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<SelectOp> SelectOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_SELECT) {
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

::mlir::LLVM::SelectOp SelectOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::SelectOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value SelectOp::condition(void) const {
  auto val = underlying_repr().getCondition();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value SelectOp::true_value(void) const {
  auto val = underlying_repr().getTrueValue();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value SelectOp::false_value(void) const {
  auto val = underlying_repr().getFalseValue();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value SelectOp::result(void) const {
  auto val = underlying_repr().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<ShlOp> ShlOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_SHL) {
    return reinterpret_cast<const ShlOp &>(that);
  }
  return std::nullopt;
}

std::optional<ShlOp> ShlOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::ShlOp ShlOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::ShlOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value ShlOp::left(void) const {
  auto val = underlying_repr().getLhs();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value ShlOp::right(void) const {
  auto val = underlying_repr().getRhs();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value ShlOp::result(void) const {
  auto val = underlying_repr().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<ShuffleVectorOp> ShuffleVectorOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_SHUFFLEVECTOR) {
    return reinterpret_cast<const ShuffleVectorOp &>(that);
  }
  return std::nullopt;
}

std::optional<ShuffleVectorOp> ShuffleVectorOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::ShuffleVectorOp ShuffleVectorOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::ShuffleVectorOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value ShuffleVectorOp::v1(void) const {
  auto val = underlying_repr().getV1();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value ShuffleVectorOp::v2(void) const {
  auto val = underlying_repr().getV2();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value ShuffleVectorOp::result(void) const {
  auto val = underlying_repr().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<StoreOp> StoreOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_STORE) {
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

::mlir::LLVM::StoreOp StoreOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::StoreOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value StoreOp::value(void) const {
  auto val = underlying_repr().getValue();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<unsigned long long> StoreOp::alignment(void) const {
  auto opt_val = underlying_repr().getAlignment();
  if (!opt_val) {
    return std::nullopt;
  }
  auto &val = opt_val.value();
  return val;
}

bool StoreOp::volatile__(void) const {
  auto val = underlying_repr().getVolatile_();
  return val;
}

bool StoreOp::nontemporal(void) const {
  auto val = underlying_repr().getNontemporal();
  return val;
}

std::optional<std::string_view> StoreOp::syncscope(void) const {
  auto opt_val = underlying_repr().getSyncscope();
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

std::optional<SubOp> SubOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_SUB) {
    return reinterpret_cast<const SubOp &>(that);
  }
  return std::nullopt;
}

std::optional<SubOp> SubOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::SubOp SubOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::SubOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value SubOp::left(void) const {
  auto val = underlying_repr().getLhs();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value SubOp::right(void) const {
  auto val = underlying_repr().getRhs();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value SubOp::result(void) const {
  auto val = underlying_repr().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<SwitchOp> SwitchOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_SWITCH) {
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

::mlir::LLVM::SwitchOp SwitchOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::SwitchOp(this->::mx::ir::Operation::op_);
}

gap::generator<::mx::ir::Operand> SwitchOp::default_operands(void) const & {
  auto range = underlying_repr().getDefaultOperands();
  for (auto val : range) {
    co_yield ::mx::ir::Operand(module_, val.getAsOpaquePointer());
  }
}

std::optional<TruncOp> TruncOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_TRUNC) {
    return reinterpret_cast<const TruncOp &>(that);
  }
  return std::nullopt;
}

std::optional<TruncOp> TruncOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::TruncOp TruncOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::TruncOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value TruncOp::argument(void) const {
  auto val = underlying_repr().getArg();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value TruncOp::result(void) const {
  auto val = underlying_repr().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<UDivOp> UDivOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_UDIV) {
    return reinterpret_cast<const UDivOp &>(that);
  }
  return std::nullopt;
}

std::optional<UDivOp> UDivOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::UDivOp UDivOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::UDivOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value UDivOp::left(void) const {
  auto val = underlying_repr().getLhs();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value UDivOp::right(void) const {
  auto val = underlying_repr().getRhs();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value UDivOp::result(void) const {
  auto val = underlying_repr().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<UIToFPOp> UIToFPOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_UITOFP) {
    return reinterpret_cast<const UIToFPOp &>(that);
  }
  return std::nullopt;
}

std::optional<UIToFPOp> UIToFPOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::UIToFPOp UIToFPOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::UIToFPOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value UIToFPOp::argument(void) const {
  auto val = underlying_repr().getArg();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value UIToFPOp::result(void) const {
  auto val = underlying_repr().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<URemOp> URemOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_UREM) {
    return reinterpret_cast<const URemOp &>(that);
  }
  return std::nullopt;
}

std::optional<URemOp> URemOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::URemOp URemOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::URemOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value URemOp::left(void) const {
  auto val = underlying_repr().getLhs();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value URemOp::right(void) const {
  auto val = underlying_repr().getRhs();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value URemOp::result(void) const {
  auto val = underlying_repr().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<UndefOp> UndefOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_MLIR_UNDEF) {
    return reinterpret_cast<const UndefOp &>(that);
  }
  return std::nullopt;
}

std::optional<UndefOp> UndefOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::UndefOp UndefOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::UndefOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value UndefOp::result(void) const {
  auto val = underlying_repr().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<UnreachableOp> UnreachableOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_UNREACHABLE) {
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

::mlir::LLVM::UnreachableOp UnreachableOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::UnreachableOp(this->::mx::ir::Operation::op_);
}

std::optional<XOrOp> XOrOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_XOR) {
    return reinterpret_cast<const XOrOp &>(that);
  }
  return std::nullopt;
}

std::optional<XOrOp> XOrOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::XOrOp XOrOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::XOrOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value XOrOp::left(void) const {
  auto val = underlying_repr().getLhs();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value XOrOp::right(void) const {
  auto val = underlying_repr().getRhs();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value XOrOp::result(void) const {
  auto val = underlying_repr().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<ZExtOp> ZExtOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_ZEXT) {
    return reinterpret_cast<const ZExtOp &>(that);
  }
  return std::nullopt;
}

std::optional<ZExtOp> ZExtOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::ZExtOp ZExtOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::ZExtOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value ZExtOp::argument(void) const {
  auto val = underlying_repr().getArg();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value ZExtOp::result(void) const {
  auto val = underlying_repr().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<ZeroOp> ZeroOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_MLIR_ZERO) {
    return reinterpret_cast<const ZeroOp &>(that);
  }
  return std::nullopt;
}

std::optional<ZeroOp> ZeroOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::ZeroOp ZeroOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::ZeroOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value ZeroOp::result(void) const {
  auto val = underlying_repr().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<AbsOp> AbsOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_ABS) {
    return reinterpret_cast<const AbsOp &>(that);
  }
  return std::nullopt;
}

std::optional<AbsOp> AbsOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::AbsOp AbsOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::AbsOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value AbsOp::in(void) const {
  auto val = underlying_repr().getIn();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value AbsOp::result(void) const {
  auto val = underlying_repr().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

bool AbsOp::is_int_min_poison(void) const {
  auto val = underlying_repr().getIsIntMinPoison();
  return val;
}

std::optional<AnnotationOp> AnnotationOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_ANNOTATION) {
    return reinterpret_cast<const AnnotationOp &>(that);
  }
  return std::nullopt;
}

std::optional<AnnotationOp> AnnotationOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::Annotation AnnotationOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::Annotation(this->::mx::ir::Operation::op_);
}

std::optional<AssumeOp> AssumeOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_ASSUME) {
    return reinterpret_cast<const AssumeOp &>(that);
  }
  return std::nullopt;
}

std::optional<AssumeOp> AssumeOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::AssumeOp AssumeOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::AssumeOp(this->::mx::ir::Operation::op_);
}

std::optional<BitReverseOp> BitReverseOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_BITREVERSE) {
    return reinterpret_cast<const BitReverseOp &>(that);
  }
  return std::nullopt;
}

std::optional<BitReverseOp> BitReverseOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::BitReverseOp BitReverseOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::BitReverseOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value BitReverseOp::in(void) const {
  auto val = underlying_repr().getIn();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value BitReverseOp::result(void) const {
  auto val = underlying_repr().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<ByteSwapOp> ByteSwapOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_BSWAP) {
    return reinterpret_cast<const ByteSwapOp &>(that);
  }
  return std::nullopt;
}

std::optional<ByteSwapOp> ByteSwapOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::ByteSwapOp ByteSwapOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::ByteSwapOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value ByteSwapOp::in(void) const {
  auto val = underlying_repr().getIn();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value ByteSwapOp::result(void) const {
  auto val = underlying_repr().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<CopySignOp> CopySignOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_COPYSIGN) {
    return reinterpret_cast<const CopySignOp &>(that);
  }
  return std::nullopt;
}

std::optional<CopySignOp> CopySignOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::CopySignOp CopySignOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::CopySignOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value CopySignOp::a(void) const {
  auto val = underlying_repr().getA();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value CopySignOp::b(void) const {
  auto val = underlying_repr().getB();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value CopySignOp::result(void) const {
  auto val = underlying_repr().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<CoroAlignOp> CoroAlignOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_CORO_ALIGN) {
    return reinterpret_cast<const CoroAlignOp &>(that);
  }
  return std::nullopt;
}

std::optional<CoroAlignOp> CoroAlignOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::CoroAlignOp CoroAlignOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::CoroAlignOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value CoroAlignOp::result(void) const {
  auto val = underlying_repr().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<CoroBeginOp> CoroBeginOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_CORO_BEGIN) {
    return reinterpret_cast<const CoroBeginOp &>(that);
  }
  return std::nullopt;
}

std::optional<CoroBeginOp> CoroBeginOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::CoroBeginOp CoroBeginOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::CoroBeginOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value CoroBeginOp::token(void) const {
  auto val = underlying_repr().getToken();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value CoroBeginOp::result(void) const {
  auto val = underlying_repr().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<CoroEndOp> CoroEndOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_CORO_END) {
    return reinterpret_cast<const CoroEndOp &>(that);
  }
  return std::nullopt;
}

std::optional<CoroEndOp> CoroEndOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::CoroEndOp CoroEndOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::CoroEndOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value CoroEndOp::retvals(void) const {
  auto val = underlying_repr().getRetvals();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value CoroEndOp::result(void) const {
  auto val = underlying_repr().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<CoroFreeOp> CoroFreeOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_CORO_FREE) {
    return reinterpret_cast<const CoroFreeOp &>(that);
  }
  return std::nullopt;
}

std::optional<CoroFreeOp> CoroFreeOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::CoroFreeOp CoroFreeOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::CoroFreeOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value CoroFreeOp::id(void) const {
  auto val = underlying_repr().getId();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value CoroFreeOp::result(void) const {
  auto val = underlying_repr().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<CoroIdOp> CoroIdOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_CORO_ID) {
    return reinterpret_cast<const CoroIdOp &>(that);
  }
  return std::nullopt;
}

std::optional<CoroIdOp> CoroIdOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::CoroIdOp CoroIdOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::CoroIdOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value CoroIdOp::result(void) const {
  auto val = underlying_repr().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<CoroPromiseOp> CoroPromiseOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_CORO_PROMISE) {
    return reinterpret_cast<const CoroPromiseOp &>(that);
  }
  return std::nullopt;
}

std::optional<CoroPromiseOp> CoroPromiseOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::CoroPromiseOp CoroPromiseOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::CoroPromiseOp(this->::mx::ir::Operation::op_);
}

std::optional<CoroResumeOp> CoroResumeOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_CORO_RESUME) {
    return reinterpret_cast<const CoroResumeOp &>(that);
  }
  return std::nullopt;
}

std::optional<CoroResumeOp> CoroResumeOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::CoroResumeOp CoroResumeOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::CoroResumeOp(this->::mx::ir::Operation::op_);
}

std::optional<CoroSaveOp> CoroSaveOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_CORO_SAVE) {
    return reinterpret_cast<const CoroSaveOp &>(that);
  }
  return std::nullopt;
}

std::optional<CoroSaveOp> CoroSaveOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::CoroSaveOp CoroSaveOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::CoroSaveOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value CoroSaveOp::result(void) const {
  auto val = underlying_repr().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<CoroSizeOp> CoroSizeOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_CORO_SIZE) {
    return reinterpret_cast<const CoroSizeOp &>(that);
  }
  return std::nullopt;
}

std::optional<CoroSizeOp> CoroSizeOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::CoroSizeOp CoroSizeOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::CoroSizeOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value CoroSizeOp::result(void) const {
  auto val = underlying_repr().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<CoroSuspendOp> CoroSuspendOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_CORO_SUSPEND) {
    return reinterpret_cast<const CoroSuspendOp &>(that);
  }
  return std::nullopt;
}

std::optional<CoroSuspendOp> CoroSuspendOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::CoroSuspendOp CoroSuspendOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::CoroSuspendOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value CoroSuspendOp::save(void) const {
  auto val = underlying_repr().getSave();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value CoroSuspendOp::result(void) const {
  auto val = underlying_repr().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<CosOp> CosOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_COS) {
    return reinterpret_cast<const CosOp &>(that);
  }
  return std::nullopt;
}

std::optional<CosOp> CosOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::CosOp CosOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::CosOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value CosOp::in(void) const {
  auto val = underlying_repr().getIn();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value CosOp::result(void) const {
  auto val = underlying_repr().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<CountLeadingZerosOp> CountLeadingZerosOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_CTLZ) {
    return reinterpret_cast<const CountLeadingZerosOp &>(that);
  }
  return std::nullopt;
}

std::optional<CountLeadingZerosOp> CountLeadingZerosOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::CountLeadingZerosOp CountLeadingZerosOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::CountLeadingZerosOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value CountLeadingZerosOp::in(void) const {
  auto val = underlying_repr().getIn();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value CountLeadingZerosOp::result(void) const {
  auto val = underlying_repr().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

bool CountLeadingZerosOp::is_zero_poison(void) const {
  auto val = underlying_repr().getIsZeroPoison();
  return val;
}

std::optional<CountTrailingZerosOp> CountTrailingZerosOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_CTTZ) {
    return reinterpret_cast<const CountTrailingZerosOp &>(that);
  }
  return std::nullopt;
}

std::optional<CountTrailingZerosOp> CountTrailingZerosOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::CountTrailingZerosOp CountTrailingZerosOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::CountTrailingZerosOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value CountTrailingZerosOp::in(void) const {
  auto val = underlying_repr().getIn();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value CountTrailingZerosOp::result(void) const {
  auto val = underlying_repr().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

bool CountTrailingZerosOp::is_zero_poison(void) const {
  auto val = underlying_repr().getIsZeroPoison();
  return val;
}

std::optional<CtPopOp> CtPopOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_CTPOP) {
    return reinterpret_cast<const CtPopOp &>(that);
  }
  return std::nullopt;
}

std::optional<CtPopOp> CtPopOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::CtPopOp CtPopOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::CtPopOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value CtPopOp::in(void) const {
  auto val = underlying_repr().getIn();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value CtPopOp::result(void) const {
  auto val = underlying_repr().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<DbgDeclareOp> DbgDeclareOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_DBG_DECLARE) {
    return reinterpret_cast<const DbgDeclareOp &>(that);
  }
  return std::nullopt;
}

std::optional<DbgDeclareOp> DbgDeclareOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::DbgDeclareOp DbgDeclareOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::DbgDeclareOp(this->::mx::ir::Operation::op_);
}

std::optional<DbgLabelOp> DbgLabelOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_DBG_LABEL) {
    return reinterpret_cast<const DbgLabelOp &>(that);
  }
  return std::nullopt;
}

std::optional<DbgLabelOp> DbgLabelOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::DbgLabelOp DbgLabelOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::DbgLabelOp(this->::mx::ir::Operation::op_);
}

std::optional<DbgValueOp> DbgValueOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_DBG_VALUE) {
    return reinterpret_cast<const DbgValueOp &>(that);
  }
  return std::nullopt;
}

std::optional<DbgValueOp> DbgValueOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::DbgValueOp DbgValueOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::DbgValueOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value DbgValueOp::value(void) const {
  auto val = underlying_repr().getValue();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<DebugTrapOp> DebugTrapOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_DEBUGTRAP) {
    return reinterpret_cast<const DebugTrapOp &>(that);
  }
  return std::nullopt;
}

std::optional<DebugTrapOp> DebugTrapOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::DebugTrap DebugTrapOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::DebugTrap(this->::mx::ir::Operation::op_);
}

std::optional<EhTypeidForOp> EhTypeidForOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_EH_TYPEID_FOR) {
    return reinterpret_cast<const EhTypeidForOp &>(that);
  }
  return std::nullopt;
}

std::optional<EhTypeidForOp> EhTypeidForOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::EhTypeidForOp EhTypeidForOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::EhTypeidForOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value EhTypeidForOp::result(void) const {
  auto val = underlying_repr().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<Exp2Op> Exp2Op::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_EXP2) {
    return reinterpret_cast<const Exp2Op &>(that);
  }
  return std::nullopt;
}

std::optional<Exp2Op> Exp2Op::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::Exp2Op Exp2Op::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::Exp2Op(this->::mx::ir::Operation::op_);
}

::mx::ir::Value Exp2Op::in(void) const {
  auto val = underlying_repr().getIn();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value Exp2Op::result(void) const {
  auto val = underlying_repr().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<ExpOp> ExpOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_EXP) {
    return reinterpret_cast<const ExpOp &>(that);
  }
  return std::nullopt;
}

std::optional<ExpOp> ExpOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::ExpOp ExpOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::ExpOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value ExpOp::in(void) const {
  auto val = underlying_repr().getIn();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value ExpOp::result(void) const {
  auto val = underlying_repr().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<ExpectOp> ExpectOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_EXPECT) {
    return reinterpret_cast<const ExpectOp &>(that);
  }
  return std::nullopt;
}

std::optional<ExpectOp> ExpectOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::ExpectOp ExpectOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::ExpectOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value ExpectOp::result(void) const {
  auto val = underlying_repr().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<ExpectWithProbabilityOp> ExpectWithProbabilityOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_EXPECT_WITH_PROBABILITY) {
    return reinterpret_cast<const ExpectWithProbabilityOp &>(that);
  }
  return std::nullopt;
}

std::optional<ExpectWithProbabilityOp> ExpectWithProbabilityOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::ExpectWithProbabilityOp ExpectWithProbabilityOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::ExpectWithProbabilityOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value ExpectWithProbabilityOp::result(void) const {
  auto val = underlying_repr().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<FAbsOp> FAbsOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_FABS) {
    return reinterpret_cast<const FAbsOp &>(that);
  }
  return std::nullopt;
}

std::optional<FAbsOp> FAbsOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::FAbsOp FAbsOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::FAbsOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value FAbsOp::in(void) const {
  auto val = underlying_repr().getIn();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value FAbsOp::result(void) const {
  auto val = underlying_repr().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<FCeilOp> FCeilOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_CEIL) {
    return reinterpret_cast<const FCeilOp &>(that);
  }
  return std::nullopt;
}

std::optional<FCeilOp> FCeilOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::FCeilOp FCeilOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::FCeilOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value FCeilOp::in(void) const {
  auto val = underlying_repr().getIn();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value FCeilOp::result(void) const {
  auto val = underlying_repr().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<FFloorOp> FFloorOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_FLOOR) {
    return reinterpret_cast<const FFloorOp &>(that);
  }
  return std::nullopt;
}

std::optional<FFloorOp> FFloorOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::FFloorOp FFloorOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::FFloorOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value FFloorOp::in(void) const {
  auto val = underlying_repr().getIn();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value FFloorOp::result(void) const {
  auto val = underlying_repr().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<FMAOp> FMAOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_FMA) {
    return reinterpret_cast<const FMAOp &>(that);
  }
  return std::nullopt;
}

std::optional<FMAOp> FMAOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::FMAOp FMAOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::FMAOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value FMAOp::a(void) const {
  auto val = underlying_repr().getA();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value FMAOp::b(void) const {
  auto val = underlying_repr().getB();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value FMAOp::c(void) const {
  auto val = underlying_repr().getC();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value FMAOp::result(void) const {
  auto val = underlying_repr().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<FMulAddOp> FMulAddOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_FMULADD) {
    return reinterpret_cast<const FMulAddOp &>(that);
  }
  return std::nullopt;
}

std::optional<FMulAddOp> FMulAddOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::FMulAddOp FMulAddOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::FMulAddOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value FMulAddOp::a(void) const {
  auto val = underlying_repr().getA();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value FMulAddOp::b(void) const {
  auto val = underlying_repr().getB();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value FMulAddOp::c(void) const {
  auto val = underlying_repr().getC();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value FMulAddOp::result(void) const {
  auto val = underlying_repr().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<FTruncOp> FTruncOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_TRUNC) {
    return reinterpret_cast<const FTruncOp &>(that);
  }
  return std::nullopt;
}

std::optional<FTruncOp> FTruncOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::FTruncOp FTruncOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::FTruncOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value FTruncOp::in(void) const {
  auto val = underlying_repr().getIn();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value FTruncOp::result(void) const {
  auto val = underlying_repr().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<FShlOp> FShlOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_FSHL) {
    return reinterpret_cast<const FShlOp &>(that);
  }
  return std::nullopt;
}

std::optional<FShlOp> FShlOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::FshlOp FShlOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::FshlOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value FShlOp::a(void) const {
  auto val = underlying_repr().getA();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value FShlOp::b(void) const {
  auto val = underlying_repr().getB();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value FShlOp::c(void) const {
  auto val = underlying_repr().getC();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value FShlOp::result(void) const {
  auto val = underlying_repr().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<FShrOp> FShrOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_FSHR) {
    return reinterpret_cast<const FShrOp &>(that);
  }
  return std::nullopt;
}

std::optional<FShrOp> FShrOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::FshrOp FShrOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::FshrOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value FShrOp::a(void) const {
  auto val = underlying_repr().getA();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value FShrOp::b(void) const {
  auto val = underlying_repr().getB();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value FShrOp::c(void) const {
  auto val = underlying_repr().getC();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value FShrOp::result(void) const {
  auto val = underlying_repr().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<GetActiveLaneMaskOp> GetActiveLaneMaskOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_GET_ACTIVE_LANE_MASK) {
    return reinterpret_cast<const GetActiveLaneMaskOp &>(that);
  }
  return std::nullopt;
}

std::optional<GetActiveLaneMaskOp> GetActiveLaneMaskOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::GetActiveLaneMaskOp GetActiveLaneMaskOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::GetActiveLaneMaskOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value GetActiveLaneMaskOp::result(void) const {
  auto val = underlying_repr().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<InvariantEndOp> InvariantEndOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_INVARIANT_END) {
    return reinterpret_cast<const InvariantEndOp &>(that);
  }
  return std::nullopt;
}

std::optional<InvariantEndOp> InvariantEndOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::InvariantEndOp InvariantEndOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::InvariantEndOp(this->::mx::ir::Operation::op_);
}

uint64_t InvariantEndOp::size(void) const {
  auto val = underlying_repr().getSize();
  return val;
}

std::optional<InvariantStartOp> InvariantStartOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_INVARIANT_START) {
    return reinterpret_cast<const InvariantStartOp &>(that);
  }
  return std::nullopt;
}

std::optional<InvariantStartOp> InvariantStartOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::InvariantStartOp InvariantStartOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::InvariantStartOp(this->::mx::ir::Operation::op_);
}

uint64_t InvariantStartOp::size(void) const {
  auto val = underlying_repr().getSize();
  return val;
}

std::optional<IsConstantOp> IsConstantOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_IS_CONSTANT) {
    return reinterpret_cast<const IsConstantOp &>(that);
  }
  return std::nullopt;
}

std::optional<IsConstantOp> IsConstantOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::IsConstantOp IsConstantOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::IsConstantOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value IsConstantOp::value(void) const {
  auto val = underlying_repr().getVal();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<IsFPClassOp> IsFPClassOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_IS_FPCLASS) {
    return reinterpret_cast<const IsFPClassOp &>(that);
  }
  return std::nullopt;
}

std::optional<IsFPClassOp> IsFPClassOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::IsFPClass IsFPClassOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::IsFPClass(this->::mx::ir::Operation::op_);
}

::mx::ir::Value IsFPClassOp::in(void) const {
  auto val = underlying_repr().getIn();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value IsFPClassOp::result(void) const {
  auto val = underlying_repr().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

uint32_t IsFPClassOp::bit(void) const {
  auto val = underlying_repr().getBit();
  return val;
}

std::optional<LifetimeEndOp> LifetimeEndOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_LIFETIME_END) {
    return reinterpret_cast<const LifetimeEndOp &>(that);
  }
  return std::nullopt;
}

std::optional<LifetimeEndOp> LifetimeEndOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::LifetimeEndOp LifetimeEndOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::LifetimeEndOp(this->::mx::ir::Operation::op_);
}

uint64_t LifetimeEndOp::size(void) const {
  auto val = underlying_repr().getSize();
  return val;
}

std::optional<LifetimeStartOp> LifetimeStartOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_LIFETIME_START) {
    return reinterpret_cast<const LifetimeStartOp &>(that);
  }
  return std::nullopt;
}

std::optional<LifetimeStartOp> LifetimeStartOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::LifetimeStartOp LifetimeStartOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::LifetimeStartOp(this->::mx::ir::Operation::op_);
}

uint64_t LifetimeStartOp::size(void) const {
  auto val = underlying_repr().getSize();
  return val;
}

std::optional<RoundAndCastToLongLongOp> RoundAndCastToLongLongOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_LLRINT) {
    return reinterpret_cast<const RoundAndCastToLongLongOp &>(that);
  }
  return std::nullopt;
}

std::optional<RoundAndCastToLongLongOp> RoundAndCastToLongLongOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::LlrintOp RoundAndCastToLongLongOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::LlrintOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value RoundAndCastToLongLongOp::value(void) const {
  auto val = underlying_repr().getVal();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value RoundAndCastToLongLongOp::result(void) const {
  auto val = underlying_repr().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<RoundAndCastToNearestLongLongOp> RoundAndCastToNearestLongLongOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_LLROUND) {
    return reinterpret_cast<const RoundAndCastToNearestLongLongOp &>(that);
  }
  return std::nullopt;
}

std::optional<RoundAndCastToNearestLongLongOp> RoundAndCastToNearestLongLongOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::LlroundOp RoundAndCastToNearestLongLongOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::LlroundOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value RoundAndCastToNearestLongLongOp::value(void) const {
  auto val = underlying_repr().getVal();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value RoundAndCastToNearestLongLongOp::result(void) const {
  auto val = underlying_repr().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<Log10Op> Log10Op::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_LOG10) {
    return reinterpret_cast<const Log10Op &>(that);
  }
  return std::nullopt;
}

std::optional<Log10Op> Log10Op::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::Log10Op Log10Op::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::Log10Op(this->::mx::ir::Operation::op_);
}

::mx::ir::Value Log10Op::in(void) const {
  auto val = underlying_repr().getIn();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value Log10Op::result(void) const {
  auto val = underlying_repr().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<Log2Op> Log2Op::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_LOG2) {
    return reinterpret_cast<const Log2Op &>(that);
  }
  return std::nullopt;
}

std::optional<Log2Op> Log2Op::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::Log2Op Log2Op::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::Log2Op(this->::mx::ir::Operation::op_);
}

::mx::ir::Value Log2Op::in(void) const {
  auto val = underlying_repr().getIn();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value Log2Op::result(void) const {
  auto val = underlying_repr().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<LogOp> LogOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_LOG) {
    return reinterpret_cast<const LogOp &>(that);
  }
  return std::nullopt;
}

std::optional<LogOp> LogOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::LogOp LogOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::LogOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value LogOp::in(void) const {
  auto val = underlying_repr().getIn();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value LogOp::result(void) const {
  auto val = underlying_repr().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<RoundAndCastToLongOp> RoundAndCastToLongOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_LRINT) {
    return reinterpret_cast<const RoundAndCastToLongOp &>(that);
  }
  return std::nullopt;
}

std::optional<RoundAndCastToLongOp> RoundAndCastToLongOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::LrintOp RoundAndCastToLongOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::LrintOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value RoundAndCastToLongOp::value(void) const {
  auto val = underlying_repr().getVal();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value RoundAndCastToLongOp::result(void) const {
  auto val = underlying_repr().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<RoundAndCastToNearestLongOp> RoundAndCastToNearestLongOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_LROUND) {
    return reinterpret_cast<const RoundAndCastToNearestLongOp &>(that);
  }
  return std::nullopt;
}

std::optional<RoundAndCastToNearestLongOp> RoundAndCastToNearestLongOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::LroundOp RoundAndCastToNearestLongOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::LroundOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value RoundAndCastToNearestLongOp::value(void) const {
  auto val = underlying_repr().getVal();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value RoundAndCastToNearestLongOp::result(void) const {
  auto val = underlying_repr().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<MaskedLoadOp> MaskedLoadOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_MASKED_LOAD) {
    return reinterpret_cast<const MaskedLoadOp &>(that);
  }
  return std::nullopt;
}

std::optional<MaskedLoadOp> MaskedLoadOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::MaskedLoadOp MaskedLoadOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::MaskedLoadOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value MaskedLoadOp::mask(void) const {
  auto val = underlying_repr().getMask();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

gap::generator<::mx::ir::Operand> MaskedLoadOp::pass_thru(void) const & {
  auto range = underlying_repr().getPassThru();
  for (auto val : range) {
    co_yield ::mx::ir::Operand(module_, val.getAsOpaquePointer());
  }
}

::mx::ir::Value MaskedLoadOp::result(void) const {
  auto val = underlying_repr().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

uint32_t MaskedLoadOp::alignment(void) const {
  auto val = underlying_repr().getAlignment();
  return val;
}

std::optional<MaskedStoreOp> MaskedStoreOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_MASKED_STORE) {
    return reinterpret_cast<const MaskedStoreOp &>(that);
  }
  return std::nullopt;
}

std::optional<MaskedStoreOp> MaskedStoreOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::MaskedStoreOp MaskedStoreOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::MaskedStoreOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value MaskedStoreOp::value(void) const {
  auto val = underlying_repr().getValue();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value MaskedStoreOp::mask(void) const {
  auto val = underlying_repr().getMask();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

uint32_t MaskedStoreOp::alignment(void) const {
  auto val = underlying_repr().getAlignment();
  return val;
}

std::optional<MatrixColumnMajorLoadOp> MatrixColumnMajorLoadOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_MATRIX_COLUMN_MAJOR_LOAD) {
    return reinterpret_cast<const MatrixColumnMajorLoadOp &>(that);
  }
  return std::nullopt;
}

std::optional<MatrixColumnMajorLoadOp> MatrixColumnMajorLoadOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::MatrixColumnMajorLoadOp MatrixColumnMajorLoadOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::MatrixColumnMajorLoadOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value MatrixColumnMajorLoadOp::result(void) const {
  auto val = underlying_repr().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

bool MatrixColumnMajorLoadOp::is_volatile(void) const {
  auto val = underlying_repr().getIsVolatile();
  return val;
}

uint32_t MatrixColumnMajorLoadOp::rows(void) const {
  auto val = underlying_repr().getRows();
  return val;
}

uint32_t MatrixColumnMajorLoadOp::columns(void) const {
  auto val = underlying_repr().getColumns();
  return val;
}

std::optional<MatrixColumnMajorStoreOp> MatrixColumnMajorStoreOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_MATRIX_COLUMN_MAJOR_STORE) {
    return reinterpret_cast<const MatrixColumnMajorStoreOp &>(that);
  }
  return std::nullopt;
}

std::optional<MatrixColumnMajorStoreOp> MatrixColumnMajorStoreOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::MatrixColumnMajorStoreOp MatrixColumnMajorStoreOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::MatrixColumnMajorStoreOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value MatrixColumnMajorStoreOp::matrix(void) const {
  auto val = underlying_repr().getMatrix();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

bool MatrixColumnMajorStoreOp::is_volatile(void) const {
  auto val = underlying_repr().getIsVolatile();
  return val;
}

uint32_t MatrixColumnMajorStoreOp::rows(void) const {
  auto val = underlying_repr().getRows();
  return val;
}

uint32_t MatrixColumnMajorStoreOp::columns(void) const {
  auto val = underlying_repr().getColumns();
  return val;
}

std::optional<MatrixMultiplyOp> MatrixMultiplyOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_MATRIX_MULTIPLY) {
    return reinterpret_cast<const MatrixMultiplyOp &>(that);
  }
  return std::nullopt;
}

std::optional<MatrixMultiplyOp> MatrixMultiplyOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::MatrixMultiplyOp MatrixMultiplyOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::MatrixMultiplyOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value MatrixMultiplyOp::left(void) const {
  auto val = underlying_repr().getLhs();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value MatrixMultiplyOp::right(void) const {
  auto val = underlying_repr().getRhs();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value MatrixMultiplyOp::result(void) const {
  auto val = underlying_repr().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

uint32_t MatrixMultiplyOp::lhs_rows(void) const {
  auto val = underlying_repr().getLhsRows();
  return val;
}

uint32_t MatrixMultiplyOp::lhs_columns(void) const {
  auto val = underlying_repr().getLhsColumns();
  return val;
}

uint32_t MatrixMultiplyOp::rhs_columns(void) const {
  auto val = underlying_repr().getRhsColumns();
  return val;
}

std::optional<MatrixTransposeOp> MatrixTransposeOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_MATRIX_TRANSPOSE) {
    return reinterpret_cast<const MatrixTransposeOp &>(that);
  }
  return std::nullopt;
}

std::optional<MatrixTransposeOp> MatrixTransposeOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::MatrixTransposeOp MatrixTransposeOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::MatrixTransposeOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value MatrixTransposeOp::matrix(void) const {
  auto val = underlying_repr().getMatrix();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value MatrixTransposeOp::result(void) const {
  auto val = underlying_repr().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

uint32_t MatrixTransposeOp::rows(void) const {
  auto val = underlying_repr().getRows();
  return val;
}

uint32_t MatrixTransposeOp::columns(void) const {
  auto val = underlying_repr().getColumns();
  return val;
}

std::optional<MaxNumOp> MaxNumOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_MAXNUM) {
    return reinterpret_cast<const MaxNumOp &>(that);
  }
  return std::nullopt;
}

std::optional<MaxNumOp> MaxNumOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::MaxNumOp MaxNumOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::MaxNumOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value MaxNumOp::a(void) const {
  auto val = underlying_repr().getA();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value MaxNumOp::b(void) const {
  auto val = underlying_repr().getB();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value MaxNumOp::result(void) const {
  auto val = underlying_repr().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<MaximumOp> MaximumOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_MAXIMUM) {
    return reinterpret_cast<const MaximumOp &>(that);
  }
  return std::nullopt;
}

std::optional<MaximumOp> MaximumOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::MaximumOp MaximumOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::MaximumOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value MaximumOp::a(void) const {
  auto val = underlying_repr().getA();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value MaximumOp::b(void) const {
  auto val = underlying_repr().getB();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value MaximumOp::result(void) const {
  auto val = underlying_repr().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<MemcpyInlineOp> MemcpyInlineOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_MEMCPY_INLINE) {
    return reinterpret_cast<const MemcpyInlineOp &>(that);
  }
  return std::nullopt;
}

std::optional<MemcpyInlineOp> MemcpyInlineOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::MemcpyInlineOp MemcpyInlineOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::MemcpyInlineOp(this->::mx::ir::Operation::op_);
}

bool MemcpyInlineOp::is_volatile(void) const {
  auto val = underlying_repr().getIsVolatile();
  return val;
}

std::optional<MemcpyOp> MemcpyOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_MEMCPY) {
    return reinterpret_cast<const MemcpyOp &>(that);
  }
  return std::nullopt;
}

std::optional<MemcpyOp> MemcpyOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::MemcpyOp MemcpyOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::MemcpyOp(this->::mx::ir::Operation::op_);
}

bool MemcpyOp::is_volatile(void) const {
  auto val = underlying_repr().getIsVolatile();
  return val;
}

std::optional<MemmoveOp> MemmoveOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_MEMMOVE) {
    return reinterpret_cast<const MemmoveOp &>(that);
  }
  return std::nullopt;
}

std::optional<MemmoveOp> MemmoveOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::MemmoveOp MemmoveOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::MemmoveOp(this->::mx::ir::Operation::op_);
}

bool MemmoveOp::is_volatile(void) const {
  auto val = underlying_repr().getIsVolatile();
  return val;
}

std::optional<MemsetOp> MemsetOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_MEMSET) {
    return reinterpret_cast<const MemsetOp &>(that);
  }
  return std::nullopt;
}

std::optional<MemsetOp> MemsetOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::MemsetOp MemsetOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::MemsetOp(this->::mx::ir::Operation::op_);
}

bool MemsetOp::is_volatile(void) const {
  auto val = underlying_repr().getIsVolatile();
  return val;
}

std::optional<MinNumOp> MinNumOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_MINNUM) {
    return reinterpret_cast<const MinNumOp &>(that);
  }
  return std::nullopt;
}

std::optional<MinNumOp> MinNumOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::MinNumOp MinNumOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::MinNumOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value MinNumOp::a(void) const {
  auto val = underlying_repr().getA();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value MinNumOp::b(void) const {
  auto val = underlying_repr().getB();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value MinNumOp::result(void) const {
  auto val = underlying_repr().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<MinimumOp> MinimumOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_MINIMUM) {
    return reinterpret_cast<const MinimumOp &>(that);
  }
  return std::nullopt;
}

std::optional<MinimumOp> MinimumOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::MinimumOp MinimumOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::MinimumOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value MinimumOp::a(void) const {
  auto val = underlying_repr().getA();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value MinimumOp::b(void) const {
  auto val = underlying_repr().getB();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value MinimumOp::result(void) const {
  auto val = underlying_repr().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<RoundToNearbyIntOp> RoundToNearbyIntOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_NEARBYINT) {
    return reinterpret_cast<const RoundToNearbyIntOp &>(that);
  }
  return std::nullopt;
}

std::optional<RoundToNearbyIntOp> RoundToNearbyIntOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::NearbyintOp RoundToNearbyIntOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::NearbyintOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value RoundToNearbyIntOp::in(void) const {
  auto val = underlying_repr().getIn();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value RoundToNearbyIntOp::result(void) const {
  auto val = underlying_repr().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<NoAliasScopeDeclOp> NoAliasScopeDeclOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_EXPERIMENTAL_NOALIAS_SCOPE_DECL) {
    return reinterpret_cast<const NoAliasScopeDeclOp &>(that);
  }
  return std::nullopt;
}

std::optional<NoAliasScopeDeclOp> NoAliasScopeDeclOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::NoAliasScopeDeclOp NoAliasScopeDeclOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::NoAliasScopeDeclOp(this->::mx::ir::Operation::op_);
}

std::optional<PowIOp> PowIOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_POWI) {
    return reinterpret_cast<const PowIOp &>(that);
  }
  return std::nullopt;
}

std::optional<PowIOp> PowIOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::PowIOp PowIOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::PowIOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value PowIOp::value(void) const {
  auto val = underlying_repr().getVal();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value PowIOp::result(void) const {
  auto val = underlying_repr().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<FPowOp> FPowOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_POW) {
    return reinterpret_cast<const FPowOp &>(that);
  }
  return std::nullopt;
}

std::optional<FPowOp> FPowOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::PowOp FPowOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::PowOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value FPowOp::a(void) const {
  auto val = underlying_repr().getA();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value FPowOp::b(void) const {
  auto val = underlying_repr().getB();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value FPowOp::result(void) const {
  auto val = underlying_repr().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<PrefetchOp> PrefetchOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_PREFETCH) {
    return reinterpret_cast<const PrefetchOp &>(that);
  }
  return std::nullopt;
}

std::optional<PrefetchOp> PrefetchOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::Prefetch PrefetchOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::Prefetch(this->::mx::ir::Operation::op_);
}

uint32_t PrefetchOp::rw(void) const {
  auto val = underlying_repr().getRw();
  return val;
}

uint32_t PrefetchOp::hint(void) const {
  auto val = underlying_repr().getHint();
  return val;
}

uint32_t PrefetchOp::cache(void) const {
  auto val = underlying_repr().getCache();
  return val;
}

std::optional<PtrAnnotationOp> PtrAnnotationOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_PTR_ANNOTATION) {
    return reinterpret_cast<const PtrAnnotationOp &>(that);
  }
  return std::nullopt;
}

std::optional<PtrAnnotationOp> PtrAnnotationOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::PtrAnnotation PtrAnnotationOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::PtrAnnotation(this->::mx::ir::Operation::op_);
}

std::optional<RoundToIntOp> RoundToIntOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_RINT) {
    return reinterpret_cast<const RoundToIntOp &>(that);
  }
  return std::nullopt;
}

std::optional<RoundToIntOp> RoundToIntOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::RintOp RoundToIntOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::RintOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value RoundToIntOp::in(void) const {
  auto val = underlying_repr().getIn();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value RoundToIntOp::result(void) const {
  auto val = underlying_repr().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<RoundToNearestEvenOp> RoundToNearestEvenOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_ROUNDEVEN) {
    return reinterpret_cast<const RoundToNearestEvenOp &>(that);
  }
  return std::nullopt;
}

std::optional<RoundToNearestEvenOp> RoundToNearestEvenOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::RoundEvenOp RoundToNearestEvenOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::RoundEvenOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value RoundToNearestEvenOp::in(void) const {
  auto val = underlying_repr().getIn();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value RoundToNearestEvenOp::result(void) const {
  auto val = underlying_repr().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<RoundToNearestOp> RoundToNearestOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_ROUND) {
    return reinterpret_cast<const RoundToNearestOp &>(that);
  }
  return std::nullopt;
}

std::optional<RoundToNearestOp> RoundToNearestOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::RoundOp RoundToNearestOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::RoundOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value RoundToNearestOp::in(void) const {
  auto val = underlying_repr().getIn();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value RoundToNearestOp::result(void) const {
  auto val = underlying_repr().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<SAddSatOp> SAddSatOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_SADD_SAT) {
    return reinterpret_cast<const SAddSatOp &>(that);
  }
  return std::nullopt;
}

std::optional<SAddSatOp> SAddSatOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::SAddSat SAddSatOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::SAddSat(this->::mx::ir::Operation::op_);
}

::mx::ir::Value SAddSatOp::a(void) const {
  auto val = underlying_repr().getA();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value SAddSatOp::b(void) const {
  auto val = underlying_repr().getB();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value SAddSatOp::result(void) const {
  auto val = underlying_repr().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<SAddWithOverflowOp> SAddWithOverflowOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_SADD_WITH_OVERFLOW) {
    return reinterpret_cast<const SAddWithOverflowOp &>(that);
  }
  return std::nullopt;
}

std::optional<SAddWithOverflowOp> SAddWithOverflowOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::SAddWithOverflowOp SAddWithOverflowOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::SAddWithOverflowOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value SAddWithOverflowOp::result(void) const {
  auto val = underlying_repr().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<SMaxOp> SMaxOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_SMAX) {
    return reinterpret_cast<const SMaxOp &>(that);
  }
  return std::nullopt;
}

std::optional<SMaxOp> SMaxOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::SMaxOp SMaxOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::SMaxOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value SMaxOp::a(void) const {
  auto val = underlying_repr().getA();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value SMaxOp::b(void) const {
  auto val = underlying_repr().getB();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value SMaxOp::result(void) const {
  auto val = underlying_repr().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<SMinOp> SMinOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_SMIN) {
    return reinterpret_cast<const SMinOp &>(that);
  }
  return std::nullopt;
}

std::optional<SMinOp> SMinOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::SMinOp SMinOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::SMinOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value SMinOp::a(void) const {
  auto val = underlying_repr().getA();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value SMinOp::b(void) const {
  auto val = underlying_repr().getB();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value SMinOp::result(void) const {
  auto val = underlying_repr().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<SMulWithOverflowOp> SMulWithOverflowOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_SMUL_WITH_OVERFLOW) {
    return reinterpret_cast<const SMulWithOverflowOp &>(that);
  }
  return std::nullopt;
}

std::optional<SMulWithOverflowOp> SMulWithOverflowOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::SMulWithOverflowOp SMulWithOverflowOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::SMulWithOverflowOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value SMulWithOverflowOp::result(void) const {
  auto val = underlying_repr().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<SSACopyOp> SSACopyOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_SSA_COPY) {
    return reinterpret_cast<const SSACopyOp &>(that);
  }
  return std::nullopt;
}

std::optional<SSACopyOp> SSACopyOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::SSACopyOp SSACopyOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::SSACopyOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value SSACopyOp::operand(void) const {
  auto val = underlying_repr().getOperand();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value SSACopyOp::result(void) const {
  auto val = underlying_repr().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<SShlSatOp> SShlSatOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_SSHL_SAT) {
    return reinterpret_cast<const SShlSatOp &>(that);
  }
  return std::nullopt;
}

std::optional<SShlSatOp> SShlSatOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::SSHLSat SShlSatOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::SSHLSat(this->::mx::ir::Operation::op_);
}

::mx::ir::Value SShlSatOp::a(void) const {
  auto val = underlying_repr().getA();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value SShlSatOp::b(void) const {
  auto val = underlying_repr().getB();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value SShlSatOp::result(void) const {
  auto val = underlying_repr().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<SSubSatOp> SSubSatOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_SSUB_SAT) {
    return reinterpret_cast<const SSubSatOp &>(that);
  }
  return std::nullopt;
}

std::optional<SSubSatOp> SSubSatOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::SSubSat SSubSatOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::SSubSat(this->::mx::ir::Operation::op_);
}

::mx::ir::Value SSubSatOp::a(void) const {
  auto val = underlying_repr().getA();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value SSubSatOp::b(void) const {
  auto val = underlying_repr().getB();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value SSubSatOp::result(void) const {
  auto val = underlying_repr().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<SSubWithOverflowOp> SSubWithOverflowOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_SSUB_WITH_OVERFLOW) {
    return reinterpret_cast<const SSubWithOverflowOp &>(that);
  }
  return std::nullopt;
}

std::optional<SSubWithOverflowOp> SSubWithOverflowOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::SSubWithOverflowOp SSubWithOverflowOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::SSubWithOverflowOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value SSubWithOverflowOp::result(void) const {
  auto val = underlying_repr().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<SinOp> SinOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_SIN) {
    return reinterpret_cast<const SinOp &>(that);
  }
  return std::nullopt;
}

std::optional<SinOp> SinOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::SinOp SinOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::SinOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value SinOp::in(void) const {
  auto val = underlying_repr().getIn();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value SinOp::result(void) const {
  auto val = underlying_repr().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<SqrtOp> SqrtOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_SQRT) {
    return reinterpret_cast<const SqrtOp &>(that);
  }
  return std::nullopt;
}

std::optional<SqrtOp> SqrtOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::SqrtOp SqrtOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::SqrtOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value SqrtOp::in(void) const {
  auto val = underlying_repr().getIn();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value SqrtOp::result(void) const {
  auto val = underlying_repr().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<StackRestoreOp> StackRestoreOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_STACKRESTORE) {
    return reinterpret_cast<const StackRestoreOp &>(that);
  }
  return std::nullopt;
}

std::optional<StackRestoreOp> StackRestoreOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::StackRestoreOp StackRestoreOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::StackRestoreOp(this->::mx::ir::Operation::op_);
}

std::optional<StackSaveOp> StackSaveOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_STACKSAVE) {
    return reinterpret_cast<const StackSaveOp &>(that);
  }
  return std::nullopt;
}

std::optional<StackSaveOp> StackSaveOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::StackSaveOp StackSaveOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::StackSaveOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value StackSaveOp::result(void) const {
  auto val = underlying_repr().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<StepVectorOp> StepVectorOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_EXPERIMENTAL_STEPVECTOR) {
    return reinterpret_cast<const StepVectorOp &>(that);
  }
  return std::nullopt;
}

std::optional<StepVectorOp> StepVectorOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::StepVectorOp StepVectorOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::StepVectorOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value StepVectorOp::result(void) const {
  auto val = underlying_repr().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<ThreadLocalAddressOp> ThreadLocalAddressOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_THREADLOCAL_ADDRESS) {
    return reinterpret_cast<const ThreadLocalAddressOp &>(that);
  }
  return std::nullopt;
}

std::optional<ThreadLocalAddressOp> ThreadLocalAddressOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::ThreadlocalAddressOp ThreadLocalAddressOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::ThreadlocalAddressOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value ThreadLocalAddressOp::result(void) const {
  auto val = underlying_repr().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<TrapOp> TrapOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_TRAP) {
    return reinterpret_cast<const TrapOp &>(that);
  }
  return std::nullopt;
}

std::optional<TrapOp> TrapOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::Trap TrapOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::Trap(this->::mx::ir::Operation::op_);
}

std::optional<UAddSatOp> UAddSatOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_UADD_SAT) {
    return reinterpret_cast<const UAddSatOp &>(that);
  }
  return std::nullopt;
}

std::optional<UAddSatOp> UAddSatOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::UAddSat UAddSatOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::UAddSat(this->::mx::ir::Operation::op_);
}

::mx::ir::Value UAddSatOp::a(void) const {
  auto val = underlying_repr().getA();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value UAddSatOp::b(void) const {
  auto val = underlying_repr().getB();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value UAddSatOp::result(void) const {
  auto val = underlying_repr().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<UAddWithOverflowOp> UAddWithOverflowOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_UADD_WITH_OVERFLOW) {
    return reinterpret_cast<const UAddWithOverflowOp &>(that);
  }
  return std::nullopt;
}

std::optional<UAddWithOverflowOp> UAddWithOverflowOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::UAddWithOverflowOp UAddWithOverflowOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::UAddWithOverflowOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value UAddWithOverflowOp::result(void) const {
  auto val = underlying_repr().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<UBSanTrapOp> UBSanTrapOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_UBSANTRAP) {
    return reinterpret_cast<const UBSanTrapOp &>(that);
  }
  return std::nullopt;
}

std::optional<UBSanTrapOp> UBSanTrapOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::UBSanTrap UBSanTrapOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::UBSanTrap(this->::mx::ir::Operation::op_);
}

uint8_t UBSanTrapOp::failure_kind(void) const {
  auto val = underlying_repr().getFailureKind();
  return val;
}

std::optional<UMaxOp> UMaxOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_UMAX) {
    return reinterpret_cast<const UMaxOp &>(that);
  }
  return std::nullopt;
}

std::optional<UMaxOp> UMaxOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::UMaxOp UMaxOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::UMaxOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value UMaxOp::a(void) const {
  auto val = underlying_repr().getA();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value UMaxOp::b(void) const {
  auto val = underlying_repr().getB();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value UMaxOp::result(void) const {
  auto val = underlying_repr().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<UMinOp> UMinOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_UMIN) {
    return reinterpret_cast<const UMinOp &>(that);
  }
  return std::nullopt;
}

std::optional<UMinOp> UMinOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::UMinOp UMinOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::UMinOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value UMinOp::a(void) const {
  auto val = underlying_repr().getA();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value UMinOp::b(void) const {
  auto val = underlying_repr().getB();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value UMinOp::result(void) const {
  auto val = underlying_repr().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<UMulWithOverflowOp> UMulWithOverflowOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_UMUL_WITH_OVERFLOW) {
    return reinterpret_cast<const UMulWithOverflowOp &>(that);
  }
  return std::nullopt;
}

std::optional<UMulWithOverflowOp> UMulWithOverflowOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::UMulWithOverflowOp UMulWithOverflowOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::UMulWithOverflowOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value UMulWithOverflowOp::result(void) const {
  auto val = underlying_repr().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<UShlSatOp> UShlSatOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_USHL_SAT) {
    return reinterpret_cast<const UShlSatOp &>(that);
  }
  return std::nullopt;
}

std::optional<UShlSatOp> UShlSatOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::USHLSat UShlSatOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::USHLSat(this->::mx::ir::Operation::op_);
}

::mx::ir::Value UShlSatOp::a(void) const {
  auto val = underlying_repr().getA();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value UShlSatOp::b(void) const {
  auto val = underlying_repr().getB();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value UShlSatOp::result(void) const {
  auto val = underlying_repr().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<USubSatOp> USubSatOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_USUB_SAT) {
    return reinterpret_cast<const USubSatOp &>(that);
  }
  return std::nullopt;
}

std::optional<USubSatOp> USubSatOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::USubSat USubSatOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::USubSat(this->::mx::ir::Operation::op_);
}

::mx::ir::Value USubSatOp::a(void) const {
  auto val = underlying_repr().getA();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value USubSatOp::b(void) const {
  auto val = underlying_repr().getB();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value USubSatOp::result(void) const {
  auto val = underlying_repr().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<USubWithOverflowOp> USubWithOverflowOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_USUB_WITH_OVERFLOW) {
    return reinterpret_cast<const USubWithOverflowOp &>(that);
  }
  return std::nullopt;
}

std::optional<USubWithOverflowOp> USubWithOverflowOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::USubWithOverflowOp USubWithOverflowOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::USubWithOverflowOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value USubWithOverflowOp::result(void) const {
  auto val = underlying_repr().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<VPAShrOp> VPAShrOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_VP_ASHR) {
    return reinterpret_cast<const VPAShrOp &>(that);
  }
  return std::nullopt;
}

std::optional<VPAShrOp> VPAShrOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::VPAShrOp VPAShrOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::VPAShrOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value VPAShrOp::left(void) const {
  auto val = underlying_repr().getLhs();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value VPAShrOp::right(void) const {
  auto val = underlying_repr().getRhs();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value VPAShrOp::mask(void) const {
  auto val = underlying_repr().getMask();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value VPAShrOp::result(void) const {
  auto val = underlying_repr().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<VPAddOp> VPAddOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_VP_ADD) {
    return reinterpret_cast<const VPAddOp &>(that);
  }
  return std::nullopt;
}

std::optional<VPAddOp> VPAddOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::VPAddOp VPAddOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::VPAddOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value VPAddOp::left(void) const {
  auto val = underlying_repr().getLhs();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value VPAddOp::right(void) const {
  auto val = underlying_repr().getRhs();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value VPAddOp::mask(void) const {
  auto val = underlying_repr().getMask();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value VPAddOp::result(void) const {
  auto val = underlying_repr().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<VPAndOp> VPAndOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_VP_AND) {
    return reinterpret_cast<const VPAndOp &>(that);
  }
  return std::nullopt;
}

std::optional<VPAndOp> VPAndOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::VPAndOp VPAndOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::VPAndOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value VPAndOp::left(void) const {
  auto val = underlying_repr().getLhs();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value VPAndOp::right(void) const {
  auto val = underlying_repr().getRhs();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value VPAndOp::mask(void) const {
  auto val = underlying_repr().getMask();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value VPAndOp::result(void) const {
  auto val = underlying_repr().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<VPFAddOp> VPFAddOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_VP_FADD) {
    return reinterpret_cast<const VPFAddOp &>(that);
  }
  return std::nullopt;
}

std::optional<VPFAddOp> VPFAddOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::VPFAddOp VPFAddOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::VPFAddOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value VPFAddOp::left(void) const {
  auto val = underlying_repr().getLhs();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value VPFAddOp::right(void) const {
  auto val = underlying_repr().getRhs();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value VPFAddOp::mask(void) const {
  auto val = underlying_repr().getMask();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value VPFAddOp::result(void) const {
  auto val = underlying_repr().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<VPFDivOp> VPFDivOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_VP_FDIV) {
    return reinterpret_cast<const VPFDivOp &>(that);
  }
  return std::nullopt;
}

std::optional<VPFDivOp> VPFDivOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::VPFDivOp VPFDivOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::VPFDivOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value VPFDivOp::left(void) const {
  auto val = underlying_repr().getLhs();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value VPFDivOp::right(void) const {
  auto val = underlying_repr().getRhs();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value VPFDivOp::mask(void) const {
  auto val = underlying_repr().getMask();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value VPFDivOp::result(void) const {
  auto val = underlying_repr().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<VPFMulAddOp> VPFMulAddOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_VP_FMULADD) {
    return reinterpret_cast<const VPFMulAddOp &>(that);
  }
  return std::nullopt;
}

std::optional<VPFMulAddOp> VPFMulAddOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::VPFMulAddOp VPFMulAddOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::VPFMulAddOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value VPFMulAddOp::op1(void) const {
  auto val = underlying_repr().getOp1();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value VPFMulAddOp::op2(void) const {
  auto val = underlying_repr().getOp2();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value VPFMulAddOp::op3(void) const {
  auto val = underlying_repr().getOp3();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value VPFMulAddOp::mask(void) const {
  auto val = underlying_repr().getMask();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value VPFMulAddOp::result(void) const {
  auto val = underlying_repr().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<VPFMulOp> VPFMulOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_VP_FMUL) {
    return reinterpret_cast<const VPFMulOp &>(that);
  }
  return std::nullopt;
}

std::optional<VPFMulOp> VPFMulOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::VPFMulOp VPFMulOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::VPFMulOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value VPFMulOp::left(void) const {
  auto val = underlying_repr().getLhs();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value VPFMulOp::right(void) const {
  auto val = underlying_repr().getRhs();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value VPFMulOp::mask(void) const {
  auto val = underlying_repr().getMask();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value VPFMulOp::result(void) const {
  auto val = underlying_repr().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<VPFNegOp> VPFNegOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_VP_FNEG) {
    return reinterpret_cast<const VPFNegOp &>(that);
  }
  return std::nullopt;
}

std::optional<VPFNegOp> VPFNegOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::VPFNegOp VPFNegOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::VPFNegOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value VPFNegOp::op(void) const {
  auto val = underlying_repr().getOp();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value VPFNegOp::mask(void) const {
  auto val = underlying_repr().getMask();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value VPFNegOp::result(void) const {
  auto val = underlying_repr().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<VPFPExtOp> VPFPExtOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_VP_FPEXT) {
    return reinterpret_cast<const VPFPExtOp &>(that);
  }
  return std::nullopt;
}

std::optional<VPFPExtOp> VPFPExtOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::VPFPExtOp VPFPExtOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::VPFPExtOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value VPFPExtOp::source(void) const {
  auto val = underlying_repr().getSrc();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value VPFPExtOp::mask(void) const {
  auto val = underlying_repr().getMask();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value VPFPExtOp::result(void) const {
  auto val = underlying_repr().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<VPFPToSIOp> VPFPToSIOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_VP_FPTOSI) {
    return reinterpret_cast<const VPFPToSIOp &>(that);
  }
  return std::nullopt;
}

std::optional<VPFPToSIOp> VPFPToSIOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::VPFPToSIOp VPFPToSIOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::VPFPToSIOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value VPFPToSIOp::source(void) const {
  auto val = underlying_repr().getSrc();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value VPFPToSIOp::mask(void) const {
  auto val = underlying_repr().getMask();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value VPFPToSIOp::result(void) const {
  auto val = underlying_repr().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<VPFPToUIOp> VPFPToUIOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_VP_FPTOUI) {
    return reinterpret_cast<const VPFPToUIOp &>(that);
  }
  return std::nullopt;
}

std::optional<VPFPToUIOp> VPFPToUIOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::VPFPToUIOp VPFPToUIOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::VPFPToUIOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value VPFPToUIOp::source(void) const {
  auto val = underlying_repr().getSrc();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value VPFPToUIOp::mask(void) const {
  auto val = underlying_repr().getMask();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value VPFPToUIOp::result(void) const {
  auto val = underlying_repr().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<VPFPTruncOp> VPFPTruncOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_VP_FPTRUNC) {
    return reinterpret_cast<const VPFPTruncOp &>(that);
  }
  return std::nullopt;
}

std::optional<VPFPTruncOp> VPFPTruncOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::VPFPTruncOp VPFPTruncOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::VPFPTruncOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value VPFPTruncOp::source(void) const {
  auto val = underlying_repr().getSrc();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value VPFPTruncOp::mask(void) const {
  auto val = underlying_repr().getMask();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value VPFPTruncOp::result(void) const {
  auto val = underlying_repr().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<VPFRemOp> VPFRemOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_VP_FREM) {
    return reinterpret_cast<const VPFRemOp &>(that);
  }
  return std::nullopt;
}

std::optional<VPFRemOp> VPFRemOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::VPFRemOp VPFRemOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::VPFRemOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value VPFRemOp::left(void) const {
  auto val = underlying_repr().getLhs();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value VPFRemOp::right(void) const {
  auto val = underlying_repr().getRhs();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value VPFRemOp::mask(void) const {
  auto val = underlying_repr().getMask();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value VPFRemOp::result(void) const {
  auto val = underlying_repr().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<VPFSubOp> VPFSubOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_VP_FSUB) {
    return reinterpret_cast<const VPFSubOp &>(that);
  }
  return std::nullopt;
}

std::optional<VPFSubOp> VPFSubOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::VPFSubOp VPFSubOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::VPFSubOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value VPFSubOp::left(void) const {
  auto val = underlying_repr().getLhs();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value VPFSubOp::right(void) const {
  auto val = underlying_repr().getRhs();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value VPFSubOp::mask(void) const {
  auto val = underlying_repr().getMask();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value VPFSubOp::result(void) const {
  auto val = underlying_repr().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<VPFmaOp> VPFmaOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_VP_FMA) {
    return reinterpret_cast<const VPFmaOp &>(that);
  }
  return std::nullopt;
}

std::optional<VPFmaOp> VPFmaOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::VPFmaOp VPFmaOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::VPFmaOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value VPFmaOp::op1(void) const {
  auto val = underlying_repr().getOp1();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value VPFmaOp::op2(void) const {
  auto val = underlying_repr().getOp2();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value VPFmaOp::op3(void) const {
  auto val = underlying_repr().getOp3();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value VPFmaOp::mask(void) const {
  auto val = underlying_repr().getMask();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value VPFmaOp::result(void) const {
  auto val = underlying_repr().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<VPIntToPtrOp> VPIntToPtrOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_VP_INTTOPTR) {
    return reinterpret_cast<const VPIntToPtrOp &>(that);
  }
  return std::nullopt;
}

std::optional<VPIntToPtrOp> VPIntToPtrOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::VPIntToPtrOp VPIntToPtrOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::VPIntToPtrOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value VPIntToPtrOp::source(void) const {
  auto val = underlying_repr().getSrc();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value VPIntToPtrOp::mask(void) const {
  auto val = underlying_repr().getMask();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value VPIntToPtrOp::result(void) const {
  auto val = underlying_repr().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<VPLShrOp> VPLShrOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_VP_LSHR) {
    return reinterpret_cast<const VPLShrOp &>(that);
  }
  return std::nullopt;
}

std::optional<VPLShrOp> VPLShrOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::VPLShrOp VPLShrOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::VPLShrOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value VPLShrOp::left(void) const {
  auto val = underlying_repr().getLhs();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value VPLShrOp::right(void) const {
  auto val = underlying_repr().getRhs();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value VPLShrOp::mask(void) const {
  auto val = underlying_repr().getMask();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value VPLShrOp::result(void) const {
  auto val = underlying_repr().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<VPLoadOp> VPLoadOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_VP_LOAD) {
    return reinterpret_cast<const VPLoadOp &>(that);
  }
  return std::nullopt;
}

std::optional<VPLoadOp> VPLoadOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::VPLoadOp VPLoadOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::VPLoadOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value VPLoadOp::mask(void) const {
  auto val = underlying_repr().getMask();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value VPLoadOp::result(void) const {
  auto val = underlying_repr().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<VPMergeMinOp> VPMergeMinOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_VP_MERGE) {
    return reinterpret_cast<const VPMergeMinOp &>(that);
  }
  return std::nullopt;
}

std::optional<VPMergeMinOp> VPMergeMinOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::VPMergeMinOp VPMergeMinOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::VPMergeMinOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value VPMergeMinOp::cond(void) const {
  auto val = underlying_repr().getCond();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value VPMergeMinOp::true_val(void) const {
  auto val = underlying_repr().getTrueVal();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value VPMergeMinOp::false_val(void) const {
  auto val = underlying_repr().getFalseVal();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value VPMergeMinOp::result(void) const {
  auto val = underlying_repr().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<VPMulOp> VPMulOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_VP_MUL) {
    return reinterpret_cast<const VPMulOp &>(that);
  }
  return std::nullopt;
}

std::optional<VPMulOp> VPMulOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::VPMulOp VPMulOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::VPMulOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value VPMulOp::left(void) const {
  auto val = underlying_repr().getLhs();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value VPMulOp::right(void) const {
  auto val = underlying_repr().getRhs();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value VPMulOp::mask(void) const {
  auto val = underlying_repr().getMask();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value VPMulOp::result(void) const {
  auto val = underlying_repr().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<VPOrOp> VPOrOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_VP_OR) {
    return reinterpret_cast<const VPOrOp &>(that);
  }
  return std::nullopt;
}

std::optional<VPOrOp> VPOrOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::VPOrOp VPOrOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::VPOrOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value VPOrOp::left(void) const {
  auto val = underlying_repr().getLhs();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value VPOrOp::right(void) const {
  auto val = underlying_repr().getRhs();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value VPOrOp::mask(void) const {
  auto val = underlying_repr().getMask();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value VPOrOp::result(void) const {
  auto val = underlying_repr().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<VPPtrToIntOp> VPPtrToIntOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_VP_PTRTOINT) {
    return reinterpret_cast<const VPPtrToIntOp &>(that);
  }
  return std::nullopt;
}

std::optional<VPPtrToIntOp> VPPtrToIntOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::VPPtrToIntOp VPPtrToIntOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::VPPtrToIntOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value VPPtrToIntOp::source(void) const {
  auto val = underlying_repr().getSrc();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value VPPtrToIntOp::mask(void) const {
  auto val = underlying_repr().getMask();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value VPPtrToIntOp::result(void) const {
  auto val = underlying_repr().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<VPReduceAddOp> VPReduceAddOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_VP_REDUCE_ADD) {
    return reinterpret_cast<const VPReduceAddOp &>(that);
  }
  return std::nullopt;
}

std::optional<VPReduceAddOp> VPReduceAddOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::VPReduceAddOp VPReduceAddOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::VPReduceAddOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value VPReduceAddOp::value(void) const {
  auto val = underlying_repr().getVal();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value VPReduceAddOp::mask(void) const {
  auto val = underlying_repr().getMask();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value VPReduceAddOp::result(void) const {
  auto val = underlying_repr().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<VPReduceAndOp> VPReduceAndOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_VP_REDUCE_AND) {
    return reinterpret_cast<const VPReduceAndOp &>(that);
  }
  return std::nullopt;
}

std::optional<VPReduceAndOp> VPReduceAndOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::VPReduceAndOp VPReduceAndOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::VPReduceAndOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value VPReduceAndOp::value(void) const {
  auto val = underlying_repr().getVal();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value VPReduceAndOp::mask(void) const {
  auto val = underlying_repr().getMask();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value VPReduceAndOp::result(void) const {
  auto val = underlying_repr().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<VPReduceFAddOp> VPReduceFAddOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_VP_REDUCE_FADD) {
    return reinterpret_cast<const VPReduceFAddOp &>(that);
  }
  return std::nullopt;
}

std::optional<VPReduceFAddOp> VPReduceFAddOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::VPReduceFAddOp VPReduceFAddOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::VPReduceFAddOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value VPReduceFAddOp::value(void) const {
  auto val = underlying_repr().getVal();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value VPReduceFAddOp::mask(void) const {
  auto val = underlying_repr().getMask();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value VPReduceFAddOp::result(void) const {
  auto val = underlying_repr().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<VPReduceFMaxOp> VPReduceFMaxOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_VP_REDUCE_FMAX) {
    return reinterpret_cast<const VPReduceFMaxOp &>(that);
  }
  return std::nullopt;
}

std::optional<VPReduceFMaxOp> VPReduceFMaxOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::VPReduceFMaxOp VPReduceFMaxOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::VPReduceFMaxOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value VPReduceFMaxOp::value(void) const {
  auto val = underlying_repr().getVal();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value VPReduceFMaxOp::mask(void) const {
  auto val = underlying_repr().getMask();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value VPReduceFMaxOp::result(void) const {
  auto val = underlying_repr().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<VPReduceFMinOp> VPReduceFMinOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_VP_REDUCE_FMIN) {
    return reinterpret_cast<const VPReduceFMinOp &>(that);
  }
  return std::nullopt;
}

std::optional<VPReduceFMinOp> VPReduceFMinOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::VPReduceFMinOp VPReduceFMinOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::VPReduceFMinOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value VPReduceFMinOp::value(void) const {
  auto val = underlying_repr().getVal();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value VPReduceFMinOp::mask(void) const {
  auto val = underlying_repr().getMask();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value VPReduceFMinOp::result(void) const {
  auto val = underlying_repr().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<VPReduceFMulOp> VPReduceFMulOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_VP_REDUCE_FMUL) {
    return reinterpret_cast<const VPReduceFMulOp &>(that);
  }
  return std::nullopt;
}

std::optional<VPReduceFMulOp> VPReduceFMulOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::VPReduceFMulOp VPReduceFMulOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::VPReduceFMulOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value VPReduceFMulOp::value(void) const {
  auto val = underlying_repr().getVal();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value VPReduceFMulOp::mask(void) const {
  auto val = underlying_repr().getMask();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value VPReduceFMulOp::result(void) const {
  auto val = underlying_repr().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<VPReduceMulOp> VPReduceMulOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_VP_REDUCE_MUL) {
    return reinterpret_cast<const VPReduceMulOp &>(that);
  }
  return std::nullopt;
}

std::optional<VPReduceMulOp> VPReduceMulOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::VPReduceMulOp VPReduceMulOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::VPReduceMulOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value VPReduceMulOp::value(void) const {
  auto val = underlying_repr().getVal();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value VPReduceMulOp::mask(void) const {
  auto val = underlying_repr().getMask();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value VPReduceMulOp::result(void) const {
  auto val = underlying_repr().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<VPReduceOrOp> VPReduceOrOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_VP_REDUCE_OR) {
    return reinterpret_cast<const VPReduceOrOp &>(that);
  }
  return std::nullopt;
}

std::optional<VPReduceOrOp> VPReduceOrOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::VPReduceOrOp VPReduceOrOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::VPReduceOrOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value VPReduceOrOp::value(void) const {
  auto val = underlying_repr().getVal();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value VPReduceOrOp::mask(void) const {
  auto val = underlying_repr().getMask();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value VPReduceOrOp::result(void) const {
  auto val = underlying_repr().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<VPReduceSMaxOp> VPReduceSMaxOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_VP_REDUCE_SMAX) {
    return reinterpret_cast<const VPReduceSMaxOp &>(that);
  }
  return std::nullopt;
}

std::optional<VPReduceSMaxOp> VPReduceSMaxOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::VPReduceSMaxOp VPReduceSMaxOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::VPReduceSMaxOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value VPReduceSMaxOp::value(void) const {
  auto val = underlying_repr().getVal();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value VPReduceSMaxOp::mask(void) const {
  auto val = underlying_repr().getMask();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value VPReduceSMaxOp::result(void) const {
  auto val = underlying_repr().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<VPReduceSMinOp> VPReduceSMinOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_VP_REDUCE_SMIN) {
    return reinterpret_cast<const VPReduceSMinOp &>(that);
  }
  return std::nullopt;
}

std::optional<VPReduceSMinOp> VPReduceSMinOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::VPReduceSMinOp VPReduceSMinOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::VPReduceSMinOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value VPReduceSMinOp::value(void) const {
  auto val = underlying_repr().getVal();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value VPReduceSMinOp::mask(void) const {
  auto val = underlying_repr().getMask();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value VPReduceSMinOp::result(void) const {
  auto val = underlying_repr().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<VPReduceUMaxOp> VPReduceUMaxOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_VP_REDUCE_UMAX) {
    return reinterpret_cast<const VPReduceUMaxOp &>(that);
  }
  return std::nullopt;
}

std::optional<VPReduceUMaxOp> VPReduceUMaxOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::VPReduceUMaxOp VPReduceUMaxOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::VPReduceUMaxOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value VPReduceUMaxOp::value(void) const {
  auto val = underlying_repr().getVal();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value VPReduceUMaxOp::mask(void) const {
  auto val = underlying_repr().getMask();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value VPReduceUMaxOp::result(void) const {
  auto val = underlying_repr().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<VPReduceUMinOp> VPReduceUMinOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_VP_REDUCE_UMIN) {
    return reinterpret_cast<const VPReduceUMinOp &>(that);
  }
  return std::nullopt;
}

std::optional<VPReduceUMinOp> VPReduceUMinOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::VPReduceUMinOp VPReduceUMinOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::VPReduceUMinOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value VPReduceUMinOp::value(void) const {
  auto val = underlying_repr().getVal();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value VPReduceUMinOp::mask(void) const {
  auto val = underlying_repr().getMask();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value VPReduceUMinOp::result(void) const {
  auto val = underlying_repr().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<VPReduceXorOp> VPReduceXorOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_VP_REDUCE_XOR) {
    return reinterpret_cast<const VPReduceXorOp &>(that);
  }
  return std::nullopt;
}

std::optional<VPReduceXorOp> VPReduceXorOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::VPReduceXorOp VPReduceXorOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::VPReduceXorOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value VPReduceXorOp::value(void) const {
  auto val = underlying_repr().getVal();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value VPReduceXorOp::mask(void) const {
  auto val = underlying_repr().getMask();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value VPReduceXorOp::result(void) const {
  auto val = underlying_repr().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<VPSDivOp> VPSDivOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_VP_SDIV) {
    return reinterpret_cast<const VPSDivOp &>(that);
  }
  return std::nullopt;
}

std::optional<VPSDivOp> VPSDivOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::VPSDivOp VPSDivOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::VPSDivOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value VPSDivOp::left(void) const {
  auto val = underlying_repr().getLhs();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value VPSDivOp::right(void) const {
  auto val = underlying_repr().getRhs();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value VPSDivOp::mask(void) const {
  auto val = underlying_repr().getMask();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value VPSDivOp::result(void) const {
  auto val = underlying_repr().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<VPSExtOp> VPSExtOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_VP_SEXT) {
    return reinterpret_cast<const VPSExtOp &>(that);
  }
  return std::nullopt;
}

std::optional<VPSExtOp> VPSExtOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::VPSExtOp VPSExtOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::VPSExtOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value VPSExtOp::source(void) const {
  auto val = underlying_repr().getSrc();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value VPSExtOp::mask(void) const {
  auto val = underlying_repr().getMask();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value VPSExtOp::result(void) const {
  auto val = underlying_repr().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<VPSIToFPOp> VPSIToFPOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_VP_SITOFP) {
    return reinterpret_cast<const VPSIToFPOp &>(that);
  }
  return std::nullopt;
}

std::optional<VPSIToFPOp> VPSIToFPOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::VPSIToFPOp VPSIToFPOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::VPSIToFPOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value VPSIToFPOp::source(void) const {
  auto val = underlying_repr().getSrc();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value VPSIToFPOp::mask(void) const {
  auto val = underlying_repr().getMask();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value VPSIToFPOp::result(void) const {
  auto val = underlying_repr().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<VPSRemOp> VPSRemOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_VP_SREM) {
    return reinterpret_cast<const VPSRemOp &>(that);
  }
  return std::nullopt;
}

std::optional<VPSRemOp> VPSRemOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::VPSRemOp VPSRemOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::VPSRemOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value VPSRemOp::left(void) const {
  auto val = underlying_repr().getLhs();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value VPSRemOp::right(void) const {
  auto val = underlying_repr().getRhs();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value VPSRemOp::mask(void) const {
  auto val = underlying_repr().getMask();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value VPSRemOp::result(void) const {
  auto val = underlying_repr().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<VPSelectMinOp> VPSelectMinOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_VP_SELECT) {
    return reinterpret_cast<const VPSelectMinOp &>(that);
  }
  return std::nullopt;
}

std::optional<VPSelectMinOp> VPSelectMinOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::VPSelectMinOp VPSelectMinOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::VPSelectMinOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value VPSelectMinOp::cond(void) const {
  auto val = underlying_repr().getCond();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value VPSelectMinOp::true_val(void) const {
  auto val = underlying_repr().getTrueVal();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value VPSelectMinOp::false_val(void) const {
  auto val = underlying_repr().getFalseVal();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value VPSelectMinOp::result(void) const {
  auto val = underlying_repr().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<VPShlOp> VPShlOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_VP_SHL) {
    return reinterpret_cast<const VPShlOp &>(that);
  }
  return std::nullopt;
}

std::optional<VPShlOp> VPShlOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::VPShlOp VPShlOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::VPShlOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value VPShlOp::left(void) const {
  auto val = underlying_repr().getLhs();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value VPShlOp::right(void) const {
  auto val = underlying_repr().getRhs();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value VPShlOp::mask(void) const {
  auto val = underlying_repr().getMask();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value VPShlOp::result(void) const {
  auto val = underlying_repr().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<VPStoreOp> VPStoreOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_VP_STORE) {
    return reinterpret_cast<const VPStoreOp &>(that);
  }
  return std::nullopt;
}

std::optional<VPStoreOp> VPStoreOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::VPStoreOp VPStoreOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::VPStoreOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value VPStoreOp::value(void) const {
  auto val = underlying_repr().getVal();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value VPStoreOp::mask(void) const {
  auto val = underlying_repr().getMask();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<VPStridedLoadOp> VPStridedLoadOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_EXPERIMENTAL_VP_STRIDED_LOAD) {
    return reinterpret_cast<const VPStridedLoadOp &>(that);
  }
  return std::nullopt;
}

std::optional<VPStridedLoadOp> VPStridedLoadOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::VPStridedLoadOp VPStridedLoadOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::VPStridedLoadOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value VPStridedLoadOp::mask(void) const {
  auto val = underlying_repr().getMask();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value VPStridedLoadOp::result(void) const {
  auto val = underlying_repr().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<VPStridedStoreOp> VPStridedStoreOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_EXPERIMENTAL_VP_STRIDED_STORE) {
    return reinterpret_cast<const VPStridedStoreOp &>(that);
  }
  return std::nullopt;
}

std::optional<VPStridedStoreOp> VPStridedStoreOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::VPStridedStoreOp VPStridedStoreOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::VPStridedStoreOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value VPStridedStoreOp::value(void) const {
  auto val = underlying_repr().getVal();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value VPStridedStoreOp::mask(void) const {
  auto val = underlying_repr().getMask();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<VPSubOp> VPSubOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_VP_SUB) {
    return reinterpret_cast<const VPSubOp &>(that);
  }
  return std::nullopt;
}

std::optional<VPSubOp> VPSubOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::VPSubOp VPSubOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::VPSubOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value VPSubOp::left(void) const {
  auto val = underlying_repr().getLhs();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value VPSubOp::right(void) const {
  auto val = underlying_repr().getRhs();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value VPSubOp::mask(void) const {
  auto val = underlying_repr().getMask();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value VPSubOp::result(void) const {
  auto val = underlying_repr().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<VPTruncOp> VPTruncOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_VP_TRUNC) {
    return reinterpret_cast<const VPTruncOp &>(that);
  }
  return std::nullopt;
}

std::optional<VPTruncOp> VPTruncOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::VPTruncOp VPTruncOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::VPTruncOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value VPTruncOp::source(void) const {
  auto val = underlying_repr().getSrc();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value VPTruncOp::mask(void) const {
  auto val = underlying_repr().getMask();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value VPTruncOp::result(void) const {
  auto val = underlying_repr().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<VPUDivOp> VPUDivOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_VP_UDIV) {
    return reinterpret_cast<const VPUDivOp &>(that);
  }
  return std::nullopt;
}

std::optional<VPUDivOp> VPUDivOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::VPUDivOp VPUDivOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::VPUDivOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value VPUDivOp::left(void) const {
  auto val = underlying_repr().getLhs();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value VPUDivOp::right(void) const {
  auto val = underlying_repr().getRhs();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value VPUDivOp::mask(void) const {
  auto val = underlying_repr().getMask();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value VPUDivOp::result(void) const {
  auto val = underlying_repr().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<VPUIToFPOp> VPUIToFPOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_VP_UITOFP) {
    return reinterpret_cast<const VPUIToFPOp &>(that);
  }
  return std::nullopt;
}

std::optional<VPUIToFPOp> VPUIToFPOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::VPUIToFPOp VPUIToFPOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::VPUIToFPOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value VPUIToFPOp::source(void) const {
  auto val = underlying_repr().getSrc();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value VPUIToFPOp::mask(void) const {
  auto val = underlying_repr().getMask();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value VPUIToFPOp::result(void) const {
  auto val = underlying_repr().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<VPURemOp> VPURemOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_VP_UREM) {
    return reinterpret_cast<const VPURemOp &>(that);
  }
  return std::nullopt;
}

std::optional<VPURemOp> VPURemOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::VPURemOp VPURemOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::VPURemOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value VPURemOp::left(void) const {
  auto val = underlying_repr().getLhs();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value VPURemOp::right(void) const {
  auto val = underlying_repr().getRhs();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value VPURemOp::mask(void) const {
  auto val = underlying_repr().getMask();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value VPURemOp::result(void) const {
  auto val = underlying_repr().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<VPXorOp> VPXorOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_VP_XOR) {
    return reinterpret_cast<const VPXorOp &>(that);
  }
  return std::nullopt;
}

std::optional<VPXorOp> VPXorOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::VPXorOp VPXorOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::VPXorOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value VPXorOp::left(void) const {
  auto val = underlying_repr().getLhs();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value VPXorOp::right(void) const {
  auto val = underlying_repr().getRhs();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value VPXorOp::mask(void) const {
  auto val = underlying_repr().getMask();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value VPXorOp::result(void) const {
  auto val = underlying_repr().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<VPZExtOp> VPZExtOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_VP_ZEXT) {
    return reinterpret_cast<const VPZExtOp &>(that);
  }
  return std::nullopt;
}

std::optional<VPZExtOp> VPZExtOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::VPZExtOp VPZExtOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::VPZExtOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value VPZExtOp::source(void) const {
  auto val = underlying_repr().getSrc();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value VPZExtOp::mask(void) const {
  auto val = underlying_repr().getMask();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value VPZExtOp::result(void) const {
  auto val = underlying_repr().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<VaCopyOp> VaCopyOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_VACOPY) {
    return reinterpret_cast<const VaCopyOp &>(that);
  }
  return std::nullopt;
}

std::optional<VaCopyOp> VaCopyOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::VaCopyOp VaCopyOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::VaCopyOp(this->::mx::ir::Operation::op_);
}

std::optional<VaEndOp> VaEndOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_VAEND) {
    return reinterpret_cast<const VaEndOp &>(that);
  }
  return std::nullopt;
}

std::optional<VaEndOp> VaEndOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::VaEndOp VaEndOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::VaEndOp(this->::mx::ir::Operation::op_);
}

std::optional<VaStartOp> VaStartOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_VASTART) {
    return reinterpret_cast<const VaStartOp &>(that);
  }
  return std::nullopt;
}

std::optional<VaStartOp> VaStartOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::VaStartOp VaStartOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::VaStartOp(this->::mx::ir::Operation::op_);
}

std::optional<VarAnnotationOp> VarAnnotationOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_VAR_ANNOTATION) {
    return reinterpret_cast<const VarAnnotationOp &>(that);
  }
  return std::nullopt;
}

std::optional<VarAnnotationOp> VarAnnotationOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::VarAnnotation VarAnnotationOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::VarAnnotation(this->::mx::ir::Operation::op_);
}

std::optional<MaskedCompressStoreOp> MaskedCompressStoreOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_MASKED_COMPRESSSTORE) {
    return reinterpret_cast<const MaskedCompressStoreOp &>(that);
  }
  return std::nullopt;
}

std::optional<MaskedCompressStoreOp> MaskedCompressStoreOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::masked_compressstore MaskedCompressStoreOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::masked_compressstore(this->::mx::ir::Operation::op_);
}

std::optional<MaskedExpandLoadOp> MaskedExpandLoadOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_MASKED_EXPANDLOAD) {
    return reinterpret_cast<const MaskedExpandLoadOp &>(that);
  }
  return std::nullopt;
}

std::optional<MaskedExpandLoadOp> MaskedExpandLoadOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::masked_expandload MaskedExpandLoadOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::masked_expandload(this->::mx::ir::Operation::op_);
}

::mx::ir::Value MaskedExpandLoadOp::result(void) const {
  auto val = underlying_repr().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<MaskedGatherOp> MaskedGatherOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_MASKED_GATHER) {
    return reinterpret_cast<const MaskedGatherOp &>(that);
  }
  return std::nullopt;
}

std::optional<MaskedGatherOp> MaskedGatherOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::masked_gather MaskedGatherOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::masked_gather(this->::mx::ir::Operation::op_);
}

::mx::ir::Value MaskedGatherOp::ptrs(void) const {
  auto val = underlying_repr().getPtrs();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value MaskedGatherOp::mask(void) const {
  auto val = underlying_repr().getMask();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

gap::generator<::mx::ir::Operand> MaskedGatherOp::pass_thru(void) const & {
  auto range = underlying_repr().getPassThru();
  for (auto val : range) {
    co_yield ::mx::ir::Operand(module_, val.getAsOpaquePointer());
  }
}

::mx::ir::Value MaskedGatherOp::result(void) const {
  auto val = underlying_repr().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

uint32_t MaskedGatherOp::alignment(void) const {
  auto val = underlying_repr().getAlignment();
  return val;
}

std::optional<MaskedScatterOp> MaskedScatterOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_MASKED_SCATTER) {
    return reinterpret_cast<const MaskedScatterOp &>(that);
  }
  return std::nullopt;
}

std::optional<MaskedScatterOp> MaskedScatterOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::masked_scatter MaskedScatterOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::masked_scatter(this->::mx::ir::Operation::op_);
}

::mx::ir::Value MaskedScatterOp::value(void) const {
  auto val = underlying_repr().getValue();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value MaskedScatterOp::ptrs(void) const {
  auto val = underlying_repr().getPtrs();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value MaskedScatterOp::mask(void) const {
  auto val = underlying_repr().getMask();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

uint32_t MaskedScatterOp::alignment(void) const {
  auto val = underlying_repr().getAlignment();
  return val;
}

std::optional<VectorExtractOp> VectorExtractOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_VECTOR_EXTRACT) {
    return reinterpret_cast<const VectorExtractOp &>(that);
  }
  return std::nullopt;
}

std::optional<VectorExtractOp> VectorExtractOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::vector_extract VectorExtractOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::vector_extract(this->::mx::ir::Operation::op_);
}

::mx::ir::Value VectorExtractOp::srcvec(void) const {
  auto val = underlying_repr().getSrcvec();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value VectorExtractOp::result(void) const {
  auto val = underlying_repr().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

uint64_t VectorExtractOp::pos(void) const {
  auto val = underlying_repr().getPos();
  return val;
}

uint64_t VectorExtractOp::src_vector_bit_width(void) const {
  auto val = underlying_repr().getSrcVectorBitWidth();
  return val;
}

uint64_t VectorExtractOp::res_vector_bit_width(void) const {
  auto val = underlying_repr().getResVectorBitWidth();
  return val;
}

std::optional<VectorInsertOp> VectorInsertOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_VECTOR_INSERT) {
    return reinterpret_cast<const VectorInsertOp &>(that);
  }
  return std::nullopt;
}

std::optional<VectorInsertOp> VectorInsertOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::vector_insert VectorInsertOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::vector_insert(this->::mx::ir::Operation::op_);
}

::mx::ir::Value VectorInsertOp::dstvec(void) const {
  auto val = underlying_repr().getDstvec();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value VectorInsertOp::srcvec(void) const {
  auto val = underlying_repr().getSrcvec();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value VectorInsertOp::result(void) const {
  auto val = underlying_repr().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

uint64_t VectorInsertOp::pos(void) const {
  auto val = underlying_repr().getPos();
  return val;
}

uint64_t VectorInsertOp::src_vector_bit_width(void) const {
  auto val = underlying_repr().getSrcVectorBitWidth();
  return val;
}

uint64_t VectorInsertOp::dst_vector_bit_width(void) const {
  auto val = underlying_repr().getDstVectorBitWidth();
  return val;
}

std::optional<VectorReduceAddOp> VectorReduceAddOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_VECTOR_REDUCE_ADD) {
    return reinterpret_cast<const VectorReduceAddOp &>(that);
  }
  return std::nullopt;
}

std::optional<VectorReduceAddOp> VectorReduceAddOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::vector_reduce_add VectorReduceAddOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::vector_reduce_add(this->::mx::ir::Operation::op_);
}

::mx::ir::Value VectorReduceAddOp::in(void) const {
  auto val = underlying_repr().getIn();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value VectorReduceAddOp::result(void) const {
  auto val = underlying_repr().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<VectorReduceAndOp> VectorReduceAndOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_VECTOR_REDUCE_AND) {
    return reinterpret_cast<const VectorReduceAndOp &>(that);
  }
  return std::nullopt;
}

std::optional<VectorReduceAndOp> VectorReduceAndOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::vector_reduce_and VectorReduceAndOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::vector_reduce_and(this->::mx::ir::Operation::op_);
}

::mx::ir::Value VectorReduceAndOp::in(void) const {
  auto val = underlying_repr().getIn();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value VectorReduceAndOp::result(void) const {
  auto val = underlying_repr().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<VectorReduceFAddOp> VectorReduceFAddOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_VECTOR_REDUCE_FADD) {
    return reinterpret_cast<const VectorReduceFAddOp &>(that);
  }
  return std::nullopt;
}

std::optional<VectorReduceFAddOp> VectorReduceFAddOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::vector_reduce_fadd VectorReduceFAddOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::vector_reduce_fadd(this->::mx::ir::Operation::op_);
}

::mx::ir::Value VectorReduceFAddOp::input(void) const {
  auto val = underlying_repr().getInput();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value VectorReduceFAddOp::result(void) const {
  auto val = underlying_repr().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<VectorReduceFMaxOp> VectorReduceFMaxOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_VECTOR_REDUCE_FMAX) {
    return reinterpret_cast<const VectorReduceFMaxOp &>(that);
  }
  return std::nullopt;
}

std::optional<VectorReduceFMaxOp> VectorReduceFMaxOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::vector_reduce_fmax VectorReduceFMaxOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::vector_reduce_fmax(this->::mx::ir::Operation::op_);
}

::mx::ir::Value VectorReduceFMaxOp::in(void) const {
  auto val = underlying_repr().getIn();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value VectorReduceFMaxOp::result(void) const {
  auto val = underlying_repr().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<VectorReduceFMaximumOp> VectorReduceFMaximumOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_VECTOR_REDUCE_FMAXIMUM) {
    return reinterpret_cast<const VectorReduceFMaximumOp &>(that);
  }
  return std::nullopt;
}

std::optional<VectorReduceFMaximumOp> VectorReduceFMaximumOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::vector_reduce_fmaximum VectorReduceFMaximumOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::vector_reduce_fmaximum(this->::mx::ir::Operation::op_);
}

::mx::ir::Value VectorReduceFMaximumOp::in(void) const {
  auto val = underlying_repr().getIn();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value VectorReduceFMaximumOp::result(void) const {
  auto val = underlying_repr().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<VectorReduceFMinOp> VectorReduceFMinOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_VECTOR_REDUCE_FMIN) {
    return reinterpret_cast<const VectorReduceFMinOp &>(that);
  }
  return std::nullopt;
}

std::optional<VectorReduceFMinOp> VectorReduceFMinOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::vector_reduce_fmin VectorReduceFMinOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::vector_reduce_fmin(this->::mx::ir::Operation::op_);
}

::mx::ir::Value VectorReduceFMinOp::in(void) const {
  auto val = underlying_repr().getIn();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value VectorReduceFMinOp::result(void) const {
  auto val = underlying_repr().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<VectorReduceFMinimumOp> VectorReduceFMinimumOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_VECTOR_REDUCE_FMINIMUM) {
    return reinterpret_cast<const VectorReduceFMinimumOp &>(that);
  }
  return std::nullopt;
}

std::optional<VectorReduceFMinimumOp> VectorReduceFMinimumOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::vector_reduce_fminimum VectorReduceFMinimumOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::vector_reduce_fminimum(this->::mx::ir::Operation::op_);
}

::mx::ir::Value VectorReduceFMinimumOp::in(void) const {
  auto val = underlying_repr().getIn();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value VectorReduceFMinimumOp::result(void) const {
  auto val = underlying_repr().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<VectorReduceFMulOp> VectorReduceFMulOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_VECTOR_REDUCE_FMUL) {
    return reinterpret_cast<const VectorReduceFMulOp &>(that);
  }
  return std::nullopt;
}

std::optional<VectorReduceFMulOp> VectorReduceFMulOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::vector_reduce_fmul VectorReduceFMulOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::vector_reduce_fmul(this->::mx::ir::Operation::op_);
}

::mx::ir::Value VectorReduceFMulOp::input(void) const {
  auto val = underlying_repr().getInput();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value VectorReduceFMulOp::result(void) const {
  auto val = underlying_repr().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<VectorReduceMulOp> VectorReduceMulOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_VECTOR_REDUCE_MUL) {
    return reinterpret_cast<const VectorReduceMulOp &>(that);
  }
  return std::nullopt;
}

std::optional<VectorReduceMulOp> VectorReduceMulOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::vector_reduce_mul VectorReduceMulOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::vector_reduce_mul(this->::mx::ir::Operation::op_);
}

::mx::ir::Value VectorReduceMulOp::in(void) const {
  auto val = underlying_repr().getIn();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value VectorReduceMulOp::result(void) const {
  auto val = underlying_repr().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<VectorReduceOrOp> VectorReduceOrOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_VECTOR_REDUCE_OR) {
    return reinterpret_cast<const VectorReduceOrOp &>(that);
  }
  return std::nullopt;
}

std::optional<VectorReduceOrOp> VectorReduceOrOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::vector_reduce_or VectorReduceOrOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::vector_reduce_or(this->::mx::ir::Operation::op_);
}

::mx::ir::Value VectorReduceOrOp::in(void) const {
  auto val = underlying_repr().getIn();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value VectorReduceOrOp::result(void) const {
  auto val = underlying_repr().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<VectorReduceSMaxOp> VectorReduceSMaxOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_VECTOR_REDUCE_SMAX) {
    return reinterpret_cast<const VectorReduceSMaxOp &>(that);
  }
  return std::nullopt;
}

std::optional<VectorReduceSMaxOp> VectorReduceSMaxOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::vector_reduce_smax VectorReduceSMaxOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::vector_reduce_smax(this->::mx::ir::Operation::op_);
}

::mx::ir::Value VectorReduceSMaxOp::in(void) const {
  auto val = underlying_repr().getIn();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value VectorReduceSMaxOp::result(void) const {
  auto val = underlying_repr().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<VectorReduceSMinOp> VectorReduceSMinOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_VECTOR_REDUCE_SMIN) {
    return reinterpret_cast<const VectorReduceSMinOp &>(that);
  }
  return std::nullopt;
}

std::optional<VectorReduceSMinOp> VectorReduceSMinOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::vector_reduce_smin VectorReduceSMinOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::vector_reduce_smin(this->::mx::ir::Operation::op_);
}

::mx::ir::Value VectorReduceSMinOp::in(void) const {
  auto val = underlying_repr().getIn();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value VectorReduceSMinOp::result(void) const {
  auto val = underlying_repr().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<VectorReduceUMaxOp> VectorReduceUMaxOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_VECTOR_REDUCE_UMAX) {
    return reinterpret_cast<const VectorReduceUMaxOp &>(that);
  }
  return std::nullopt;
}

std::optional<VectorReduceUMaxOp> VectorReduceUMaxOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::vector_reduce_umax VectorReduceUMaxOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::vector_reduce_umax(this->::mx::ir::Operation::op_);
}

::mx::ir::Value VectorReduceUMaxOp::in(void) const {
  auto val = underlying_repr().getIn();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value VectorReduceUMaxOp::result(void) const {
  auto val = underlying_repr().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<VectorReduceUMinOp> VectorReduceUMinOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_VECTOR_REDUCE_UMIN) {
    return reinterpret_cast<const VectorReduceUMinOp &>(that);
  }
  return std::nullopt;
}

std::optional<VectorReduceUMinOp> VectorReduceUMinOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::vector_reduce_umin VectorReduceUMinOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::vector_reduce_umin(this->::mx::ir::Operation::op_);
}

::mx::ir::Value VectorReduceUMinOp::in(void) const {
  auto val = underlying_repr().getIn();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value VectorReduceUMinOp::result(void) const {
  auto val = underlying_repr().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<VectorReduceXorOp> VectorReduceXorOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_VECTOR_REDUCE_XOR) {
    return reinterpret_cast<const VectorReduceXorOp &>(that);
  }
  return std::nullopt;
}

std::optional<VectorReduceXorOp> VectorReduceXorOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::vector_reduce_xor VectorReduceXorOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::vector_reduce_xor(this->::mx::ir::Operation::op_);
}

::mx::ir::Value VectorReduceXorOp::in(void) const {
  auto val = underlying_repr().getIn();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value VectorReduceXorOp::result(void) const {
  auto val = underlying_repr().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<VScaleOp> VScaleOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LLVM_INTR_VSCALE) {
    return reinterpret_cast<const VScaleOp &>(that);
  }
  return std::nullopt;
}

std::optional<VScaleOp> VScaleOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::LLVM::vscale VScaleOp::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::vscale(this->::mx::ir::Operation::op_);
}

::mx::ir::Value VScaleOp::result(void) const {
  auto val = underlying_repr().getRes();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

}  // namespace mx::ir::llvm
