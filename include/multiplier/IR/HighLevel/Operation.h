// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "../Operation.h"

namespace vast::hl {
class AccessSpecifierOp;
class AddFAssignOp;
class AddFOp;
class AddIAssignOp;
class AddIOp;
class AddrLabelExpr;
class AddressOf;
class AlignOfExprOp;
class AlignOfTypeOp;
class AssignOp;
class BinAShrAssignOp;
class BinAShrOp;
class BinAndAssignOp;
class BinAndOp;
class BinComma;
class BinLAndOp;
class BinLOrOp;
class BinLShrAssignOp;
class BinLShrOp;
class BinOrAssignOp;
class BinOrOp;
class BinShlAssignOp;
class BinShlOp;
class BinXorAssignOp;
class BinXorOp;
class BuiltinBitCastOp;
class CStyleCastOp;
class CallOp;
class ClassDeclOp;
class CmpOp;
class ConstantOp;
class CxxBaseSpecifierOp;
class CxxStructDeclOp;
class DeclRefOp;
class Deref;
class DivFAssignOp;
class DivFOp;
class DivSAssignOp;
class DivSOp;
class DivUAssignOp;
class DivUOp;
class EnumConstantOp;
class EnumDeclOp;
class EnumRefOp;
class ExprOp;
class ExtensionOp;
class FCmpOp;
class FieldDeclOp;
class FuncRefOp;
class GlobalRefOp;
class BreakOp;
class CaseOp;
class CondOp;
class CondYieldOp;
class ContinueOp;
class DefaultOp;
class DoOp;
class EmptyDeclOp;
class ForOp;
class FuncOp;
class GotoStmt;
class IfOp;
class LabelDeclOp;
class LabelStmt;
class SkipStmt;
class SwitchOp;
class TypeYieldOp;
class ValueYieldOp;
class VarDeclOp;
class WhileOp;
class ImplicitCastOp;
class IndirectCallOp;
class InitListExpr;
class LNotOp;
class MinusOp;
class MulFAssignOp;
class MulFOp;
class MulIAssignOp;
class MulIOp;
class NotOp;
class PlusOp;
class PostDecOp;
class PostIncOp;
class PreDecOp;
class PreIncOp;
class PredefinedExpr;
class RecordMemberOp;
class RemFAssignOp;
class RemFOp;
class RemSAssignOp;
class RemSOp;
class RemUAssignOp;
class RemUOp;
class ReturnOp;
class SizeOfExprOp;
class SizeOfTypeOp;
class StmtExprOp;
class StructDeclOp;
class SubFAssignOp;
class SubFOp;
class SubIAssignOp;
class SubIOp;
class SubscriptOp;
class ThisOp;
class TranslationUnitOp;
class TypeDeclOp;
class TypeDefOp;
class TypeOfExprOp;
class TypeOfTypeOp;
class UnionDeclOp;
class UnreachableOp;
}  // namespace vast::hl
namespace mx::ir::hl {

class Operation : public ::mx::ir::Operation {
 public:
  static std::optional<Operation> from(const ::mx::ir::Operation &);
};
static_assert(sizeof(Operation) == sizeof(::mx::ir::Operation));

class AccessSpecifierOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::HL_ACCESS;
  }

  static std::optional<AccessSpecifierOp> from(const ::mx::ir::Operation &that);
  static std::optional<AccessSpecifierOp> producing(const ::mx::ir::Value &val);

  ::vast::hl::AccessSpecifierOp underlying_repr(void) const noexcept;

  // Imported methods:
  //::vast::hl::AccessSpecifier spec(void) const;
};
static_assert(sizeof(AccessSpecifierOp) == sizeof(Operation));

class AddFAssignOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::HL_ASSIGN_FADD;
  }

  static std::optional<AddFAssignOp> from(const ::mx::ir::Operation &that);
  static std::optional<AddFAssignOp> producing(const ::mx::ir::Value &val);

  ::vast::hl::AddFAssignOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value src(void) const;
  ::mx::ir::Value dst(void) const;
  ::mx::ir::Value result(void) const;
};
static_assert(sizeof(AddFAssignOp) == sizeof(Operation));

class AddFOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::HL_FADD;
  }

  static std::optional<AddFOp> from(const ::mx::ir::Operation &that);
  static std::optional<AddFOp> producing(const ::mx::ir::Value &val);

  ::vast::hl::AddFOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value lhs(void) const;
  ::mx::ir::Value rhs(void) const;
  ::mx::ir::Value result(void) const;
};
static_assert(sizeof(AddFOp) == sizeof(Operation));

class AddIAssignOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::HL_ASSIGN_ADD;
  }

  static std::optional<AddIAssignOp> from(const ::mx::ir::Operation &that);
  static std::optional<AddIAssignOp> producing(const ::mx::ir::Value &val);

  ::vast::hl::AddIAssignOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value src(void) const;
  ::mx::ir::Value dst(void) const;
  ::mx::ir::Value result(void) const;
};
static_assert(sizeof(AddIAssignOp) == sizeof(Operation));

class AddIOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::HL_ADD;
  }

  static std::optional<AddIOp> from(const ::mx::ir::Operation &that);
  static std::optional<AddIOp> producing(const ::mx::ir::Value &val);

  ::vast::hl::AddIOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value lhs(void) const;
  ::mx::ir::Value rhs(void) const;
  ::mx::ir::Value result(void) const;
};
static_assert(sizeof(AddIOp) == sizeof(Operation));

class AddrLabelExprOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::HL_LABELADDR;
  }

  static std::optional<AddrLabelExprOp> from(const ::mx::ir::Operation &that);
  static std::optional<AddrLabelExprOp> producing(const ::mx::ir::Value &val);

  ::vast::hl::AddrLabelExpr underlying_repr(void) const noexcept;

  // Imported methods:
  //::mlir::TypedValue<::vast::hl::LabelType> label(void) const;
  ::mx::ir::Value result(void) const;
};
static_assert(sizeof(AddrLabelExprOp) == sizeof(Operation));

class AddressOfOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::HL_ADDRESSOF;
  }

  static std::optional<AddressOfOp> from(const ::mx::ir::Operation &that);
  static std::optional<AddressOfOp> producing(const ::mx::ir::Value &val);

  ::vast::hl::AddressOf underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value value(void) const;
  ::mx::ir::Value result(void) const;
};
static_assert(sizeof(AddressOfOp) == sizeof(Operation));

class AlignOfExprOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::HL_ALIGNOF_EXPR;
  }

  static std::optional<AlignOfExprOp> from(const ::mx::ir::Operation &that);
  static std::optional<AlignOfExprOp> producing(const ::mx::ir::Value &val);

  ::vast::hl::AlignOfExprOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value result(void) const;
  ::mx::ir::Region expr(void) const;
};
static_assert(sizeof(AlignOfExprOp) == sizeof(Operation));

class AlignOfTypeOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::HL_ALIGNOF_TYPE;
  }

  static std::optional<AlignOfTypeOp> from(const ::mx::ir::Operation &that);
  static std::optional<AlignOfTypeOp> producing(const ::mx::ir::Value &val);

  ::vast::hl::AlignOfTypeOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value result(void) const;
  //::mlir::Type arg(void) const;
};
static_assert(sizeof(AlignOfTypeOp) == sizeof(Operation));

class AssignOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::HL_ASSIGN;
  }

  static std::optional<AssignOp> from(const ::mx::ir::Operation &that);
  static std::optional<AssignOp> producing(const ::mx::ir::Value &val);

  ::vast::hl::AssignOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value src(void) const;
  ::mx::ir::Value dst(void) const;
  ::mx::ir::Value result(void) const;
};
static_assert(sizeof(AssignOp) == sizeof(Operation));

class BinAShrAssignOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::HL_ASSIGN_BIN_ASHR;
  }

  static std::optional<BinAShrAssignOp> from(const ::mx::ir::Operation &that);
  static std::optional<BinAShrAssignOp> producing(const ::mx::ir::Value &val);

  ::vast::hl::BinAShrAssignOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value src(void) const;
  ::mx::ir::Value dst(void) const;
  ::mx::ir::Value result(void) const;
};
static_assert(sizeof(BinAShrAssignOp) == sizeof(Operation));

class BinAShrOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::HL_BIN_ASHR;
  }

  static std::optional<BinAShrOp> from(const ::mx::ir::Operation &that);
  static std::optional<BinAShrOp> producing(const ::mx::ir::Value &val);

  ::vast::hl::BinAShrOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value lhs(void) const;
  ::mx::ir::Value rhs(void) const;
  ::mx::ir::Value result(void) const;
};
static_assert(sizeof(BinAShrOp) == sizeof(Operation));

class BinAndAssignOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::HL_ASSIGN_BIN_AND;
  }

  static std::optional<BinAndAssignOp> from(const ::mx::ir::Operation &that);
  static std::optional<BinAndAssignOp> producing(const ::mx::ir::Value &val);

  ::vast::hl::BinAndAssignOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value src(void) const;
  ::mx::ir::Value dst(void) const;
  ::mx::ir::Value result(void) const;
};
static_assert(sizeof(BinAndAssignOp) == sizeof(Operation));

class BinAndOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::HL_BIN_AND;
  }

  static std::optional<BinAndOp> from(const ::mx::ir::Operation &that);
  static std::optional<BinAndOp> producing(const ::mx::ir::Value &val);

  ::vast::hl::BinAndOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value lhs(void) const;
  ::mx::ir::Value rhs(void) const;
  ::mx::ir::Value result(void) const;
};
static_assert(sizeof(BinAndOp) == sizeof(Operation));

class BinCommaOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::HL_BIN_COMMA;
  }

  static std::optional<BinCommaOp> from(const ::mx::ir::Operation &that);
  static std::optional<BinCommaOp> producing(const ::mx::ir::Value &val);

  ::vast::hl::BinComma underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value lhs(void) const;
  ::mx::ir::Value rhs(void) const;
  ::mx::ir::Value result(void) const;
};
static_assert(sizeof(BinCommaOp) == sizeof(Operation));

class BinLAndOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::HL_BIN_LAND;
  }

  static std::optional<BinLAndOp> from(const ::mx::ir::Operation &that);
  static std::optional<BinLAndOp> producing(const ::mx::ir::Value &val);

  ::vast::hl::BinLAndOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value result(void) const;
  ::mx::ir::Region lhs(void) const;
  ::mx::ir::Region rhs(void) const;
};
static_assert(sizeof(BinLAndOp) == sizeof(Operation));

class BinLOrOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::HL_BIN_LOR;
  }

  static std::optional<BinLOrOp> from(const ::mx::ir::Operation &that);
  static std::optional<BinLOrOp> producing(const ::mx::ir::Value &val);

  ::vast::hl::BinLOrOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value result(void) const;
  ::mx::ir::Region lhs(void) const;
  ::mx::ir::Region rhs(void) const;
};
static_assert(sizeof(BinLOrOp) == sizeof(Operation));

class BinLShrAssignOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::HL_ASSIGN_BIN_LSHR;
  }

  static std::optional<BinLShrAssignOp> from(const ::mx::ir::Operation &that);
  static std::optional<BinLShrAssignOp> producing(const ::mx::ir::Value &val);

  ::vast::hl::BinLShrAssignOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value src(void) const;
  ::mx::ir::Value dst(void) const;
  ::mx::ir::Value result(void) const;
};
static_assert(sizeof(BinLShrAssignOp) == sizeof(Operation));

class BinLShrOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::HL_BIN_LSHR;
  }

  static std::optional<BinLShrOp> from(const ::mx::ir::Operation &that);
  static std::optional<BinLShrOp> producing(const ::mx::ir::Value &val);

  ::vast::hl::BinLShrOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value lhs(void) const;
  ::mx::ir::Value rhs(void) const;
  ::mx::ir::Value result(void) const;
};
static_assert(sizeof(BinLShrOp) == sizeof(Operation));

class BinOrAssignOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::HL_ASSIGN_BIN_OR;
  }

  static std::optional<BinOrAssignOp> from(const ::mx::ir::Operation &that);
  static std::optional<BinOrAssignOp> producing(const ::mx::ir::Value &val);

  ::vast::hl::BinOrAssignOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value src(void) const;
  ::mx::ir::Value dst(void) const;
  ::mx::ir::Value result(void) const;
};
static_assert(sizeof(BinOrAssignOp) == sizeof(Operation));

class BinOrOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::HL_BIN_OR;
  }

  static std::optional<BinOrOp> from(const ::mx::ir::Operation &that);
  static std::optional<BinOrOp> producing(const ::mx::ir::Value &val);

  ::vast::hl::BinOrOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value lhs(void) const;
  ::mx::ir::Value rhs(void) const;
  ::mx::ir::Value result(void) const;
};
static_assert(sizeof(BinOrOp) == sizeof(Operation));

class BinShlAssignOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::HL_ASSIGN_BIN_SHL;
  }

  static std::optional<BinShlAssignOp> from(const ::mx::ir::Operation &that);
  static std::optional<BinShlAssignOp> producing(const ::mx::ir::Value &val);

  ::vast::hl::BinShlAssignOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value src(void) const;
  ::mx::ir::Value dst(void) const;
  ::mx::ir::Value result(void) const;
};
static_assert(sizeof(BinShlAssignOp) == sizeof(Operation));

class BinShlOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::HL_BIN_SHL;
  }

  static std::optional<BinShlOp> from(const ::mx::ir::Operation &that);
  static std::optional<BinShlOp> producing(const ::mx::ir::Value &val);

  ::vast::hl::BinShlOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value lhs(void) const;
  ::mx::ir::Value rhs(void) const;
  ::mx::ir::Value result(void) const;
};
static_assert(sizeof(BinShlOp) == sizeof(Operation));

class BinXorAssignOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::HL_ASSIGN_BIN_XOR;
  }

  static std::optional<BinXorAssignOp> from(const ::mx::ir::Operation &that);
  static std::optional<BinXorAssignOp> producing(const ::mx::ir::Value &val);

  ::vast::hl::BinXorAssignOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value src(void) const;
  ::mx::ir::Value dst(void) const;
  ::mx::ir::Value result(void) const;
};
static_assert(sizeof(BinXorAssignOp) == sizeof(Operation));

class BinXorOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::HL_BIN_XOR;
  }

  static std::optional<BinXorOp> from(const ::mx::ir::Operation &that);
  static std::optional<BinXorOp> producing(const ::mx::ir::Value &val);

  ::vast::hl::BinXorOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value lhs(void) const;
  ::mx::ir::Value rhs(void) const;
  ::mx::ir::Value result(void) const;
};
static_assert(sizeof(BinXorOp) == sizeof(Operation));

class BuiltinBitCastOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::HL_BUILTIN_BITCAST;
  }

  static std::optional<BuiltinBitCastOp> from(const ::mx::ir::Operation &that);
  static std::optional<BuiltinBitCastOp> producing(const ::mx::ir::Value &val);

  ::vast::hl::BuiltinBitCastOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value value(void) const;
  ::mx::ir::Value result(void) const;
  //::vast::hl::CastKind kind(void) const;
};
static_assert(sizeof(BuiltinBitCastOp) == sizeof(Operation));

class CStyleCastOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::HL_CSTYLE_CAST;
  }

  static std::optional<CStyleCastOp> from(const ::mx::ir::Operation &that);
  static std::optional<CStyleCastOp> producing(const ::mx::ir::Value &val);

  ::vast::hl::CStyleCastOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value value(void) const;
  ::mx::ir::Value result(void) const;
  //::vast::hl::CastKind kind(void) const;
};
static_assert(sizeof(CStyleCastOp) == sizeof(Operation));

class CallOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::HL_CALL;
  }

  static std::optional<CallOp> from(const ::mx::ir::Operation &that);
  static std::optional<CallOp> producing(const ::mx::ir::Value &val);

  ::vast::hl::CallOp underlying_repr(void) const noexcept;

  // Imported methods:
  gap::generator<::mx::ir::Operand> arg_operands(void) const;
  gap::generator<::mx::ir::Result> results(void) const;
  std::string_view callee(void) const;
  //::mlir::CallInterfaceCallable callable_for_callee(void) const;
};
static_assert(sizeof(CallOp) == sizeof(Operation));

class ClassDeclOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::HL_CLASS;
  }

  static std::optional<ClassDeclOp> from(const ::mx::ir::Operation &that);
  static std::optional<ClassDeclOp> producing(const ::mx::ir::Value &val);

  ::vast::hl::ClassDeclOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Region bases(void) const;
  ::mx::ir::Region fields(void) const;
  std::string_view name(void) const;
};
static_assert(sizeof(ClassDeclOp) == sizeof(Operation));

class CmpOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::HL_CMP;
  }

  static std::optional<CmpOp> from(const ::mx::ir::Operation &that);
  static std::optional<CmpOp> producing(const ::mx::ir::Value &val);

  ::vast::hl::CmpOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value lhs(void) const;
  ::mx::ir::Value rhs(void) const;
  ::mx::ir::Value result(void) const;
  //::vast::hl::Predicate predicate(void) const;
};
static_assert(sizeof(CmpOp) == sizeof(Operation));

class ConstantOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::HL_CONST;
  }

  static std::optional<ConstantOp> from(const ::mx::ir::Operation &that);
  static std::optional<ConstantOp> producing(const ::mx::ir::Value &val);

  ::vast::hl::ConstantOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value result(void) const;
  //::mlir::TypedAttr value(void) const;
};
static_assert(sizeof(ConstantOp) == sizeof(Operation));

class CxxBaseSpecifierOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::HL_BASE;
  }

  static std::optional<CxxBaseSpecifierOp> from(const ::mx::ir::Operation &that);
  static std::optional<CxxBaseSpecifierOp> producing(const ::mx::ir::Value &val);

  ::vast::hl::CxxBaseSpecifierOp underlying_repr(void) const noexcept;

  // Imported methods:
  //::mlir::Type type(void) const;
  //::vast::hl::AccessSpecifier access(void) const;
  bool is_virtual(void) const;
};
static_assert(sizeof(CxxBaseSpecifierOp) == sizeof(Operation));

class CxxStructDeclOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::HL_CXXSTRUCT;
  }

  static std::optional<CxxStructDeclOp> from(const ::mx::ir::Operation &that);
  static std::optional<CxxStructDeclOp> producing(const ::mx::ir::Value &val);

  ::vast::hl::CxxStructDeclOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Region bases(void) const;
  ::mx::ir::Region fields(void) const;
  std::string_view name(void) const;
};
static_assert(sizeof(CxxStructDeclOp) == sizeof(Operation));

class DeclRefOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::HL_REF;
  }

  static std::optional<DeclRefOp> from(const ::mx::ir::Operation &that);
  static std::optional<DeclRefOp> producing(const ::mx::ir::Value &val);

  ::vast::hl::DeclRefOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value decl(void) const;
  ::mx::ir::Value result(void) const;
};
static_assert(sizeof(DeclRefOp) == sizeof(Operation));

class DerefOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::HL_DEREF;
  }

  static std::optional<DerefOp> from(const ::mx::ir::Operation &that);
  static std::optional<DerefOp> producing(const ::mx::ir::Value &val);

  ::vast::hl::Deref underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value addr(void) const;
  ::mx::ir::Value result(void) const;
};
static_assert(sizeof(DerefOp) == sizeof(Operation));

class DivFAssignOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::HL_ASSIGN_FDIV;
  }

  static std::optional<DivFAssignOp> from(const ::mx::ir::Operation &that);
  static std::optional<DivFAssignOp> producing(const ::mx::ir::Value &val);

  ::vast::hl::DivFAssignOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value src(void) const;
  ::mx::ir::Value dst(void) const;
  ::mx::ir::Value result(void) const;
};
static_assert(sizeof(DivFAssignOp) == sizeof(Operation));

class DivFOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::HL_FDIV;
  }

  static std::optional<DivFOp> from(const ::mx::ir::Operation &that);
  static std::optional<DivFOp> producing(const ::mx::ir::Value &val);

  ::vast::hl::DivFOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value lhs(void) const;
  ::mx::ir::Value rhs(void) const;
  ::mx::ir::Value result(void) const;
};
static_assert(sizeof(DivFOp) == sizeof(Operation));

class DivSAssignOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::HL_ASSIGN_SDIV;
  }

  static std::optional<DivSAssignOp> from(const ::mx::ir::Operation &that);
  static std::optional<DivSAssignOp> producing(const ::mx::ir::Value &val);

  ::vast::hl::DivSAssignOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value src(void) const;
  ::mx::ir::Value dst(void) const;
  ::mx::ir::Value result(void) const;
};
static_assert(sizeof(DivSAssignOp) == sizeof(Operation));

class DivSOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::HL_SDIV;
  }

  static std::optional<DivSOp> from(const ::mx::ir::Operation &that);
  static std::optional<DivSOp> producing(const ::mx::ir::Value &val);

  ::vast::hl::DivSOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value lhs(void) const;
  ::mx::ir::Value rhs(void) const;
  ::mx::ir::Value result(void) const;
};
static_assert(sizeof(DivSOp) == sizeof(Operation));

class DivUAssignOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::HL_ASSIGN_UDIV;
  }

  static std::optional<DivUAssignOp> from(const ::mx::ir::Operation &that);
  static std::optional<DivUAssignOp> producing(const ::mx::ir::Value &val);

  ::vast::hl::DivUAssignOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value src(void) const;
  ::mx::ir::Value dst(void) const;
  ::mx::ir::Value result(void) const;
};
static_assert(sizeof(DivUAssignOp) == sizeof(Operation));

class DivUOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::HL_UDIV;
  }

  static std::optional<DivUOp> from(const ::mx::ir::Operation &that);
  static std::optional<DivUOp> producing(const ::mx::ir::Value &val);

  ::vast::hl::DivUOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value lhs(void) const;
  ::mx::ir::Value rhs(void) const;
  ::mx::ir::Value result(void) const;
};
static_assert(sizeof(DivUOp) == sizeof(Operation));

class EnumConstantOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::HL_ENUM_CONST;
  }

  static std::optional<EnumConstantOp> from(const ::mx::ir::Operation &that);
  static std::optional<EnumConstantOp> producing(const ::mx::ir::Value &val);

  ::vast::hl::EnumConstantOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Region init(void) const;
  std::string_view name(void) const;
  //::mlir::TypedAttr value(void) const;
};
static_assert(sizeof(EnumConstantOp) == sizeof(Operation));

class EnumDeclOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::HL_ENUM;
  }

  static std::optional<EnumDeclOp> from(const ::mx::ir::Operation &that);
  static std::optional<EnumDeclOp> producing(const ::mx::ir::Value &val);

  ::vast::hl::EnumDeclOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Region constants(void) const;
  std::string_view name(void) const;
  //::std::optional<::mlir::Type> type(void) const;
};
static_assert(sizeof(EnumDeclOp) == sizeof(Operation));

class EnumRefOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::HL_ENUMREF;
  }

  static std::optional<EnumRefOp> from(const ::mx::ir::Operation &that);
  static std::optional<EnumRefOp> producing(const ::mx::ir::Value &val);

  ::vast::hl::EnumRefOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value result(void) const;
  std::string_view value(void) const;
};
static_assert(sizeof(EnumRefOp) == sizeof(Operation));

class ExprOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::HL_EXPR;
  }

  static std::optional<ExprOp> from(const ::mx::ir::Operation &that);
  static std::optional<ExprOp> producing(const ::mx::ir::Value &val);

  ::vast::hl::ExprOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value result(void) const;
  ::mx::ir::Region subexpr(void) const;
};
static_assert(sizeof(ExprOp) == sizeof(Operation));

class ExtensionOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::HL_GNU_EXTENSION;
  }

  static std::optional<ExtensionOp> from(const ::mx::ir::Operation &that);
  static std::optional<ExtensionOp> producing(const ::mx::ir::Value &val);

  ::vast::hl::ExtensionOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value value(void) const;
  ::mx::ir::Value result(void) const;
};
static_assert(sizeof(ExtensionOp) == sizeof(Operation));

class FCmpOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::HL_FCMP;
  }

  static std::optional<FCmpOp> from(const ::mx::ir::Operation &that);
  static std::optional<FCmpOp> producing(const ::mx::ir::Value &val);

  ::vast::hl::FCmpOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value lhs(void) const;
  ::mx::ir::Value rhs(void) const;
  ::mx::ir::Value result(void) const;
  //::vast::hl::FPredicate predicate(void) const;
};
static_assert(sizeof(FCmpOp) == sizeof(Operation));

class FieldDeclOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::HL_FIELD;
  }

  static std::optional<FieldDeclOp> from(const ::mx::ir::Operation &that);
  static std::optional<FieldDeclOp> producing(const ::mx::ir::Value &val);

  ::vast::hl::FieldDeclOp underlying_repr(void) const noexcept;

  // Imported methods:
  std::string_view name(void) const;
  //::mlir::Type type(void) const;
  //::std::optional<uint32_t> bits(void) const;
};
static_assert(sizeof(FieldDeclOp) == sizeof(Operation));

class FuncRefOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::HL_FUNCREF;
  }

  static std::optional<FuncRefOp> from(const ::mx::ir::Operation &that);
  static std::optional<FuncRefOp> producing(const ::mx::ir::Value &val);

  ::vast::hl::FuncRefOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value result(void) const;
  std::string_view function(void) const;
};
static_assert(sizeof(FuncRefOp) == sizeof(Operation));

class GlobalRefOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::HL_GLOBREF;
  }

  static std::optional<GlobalRefOp> from(const ::mx::ir::Operation &that);
  static std::optional<GlobalRefOp> producing(const ::mx::ir::Value &val);

  ::vast::hl::GlobalRefOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value result(void) const;
  std::string_view global(void) const;
};
static_assert(sizeof(GlobalRefOp) == sizeof(Operation));

class BreakOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::HL_BREAK;
  }

  static std::optional<BreakOp> from(const ::mx::ir::Operation &that);
  static std::optional<BreakOp> producing(const ::mx::ir::Value &val);

  ::vast::hl::BreakOp underlying_repr(void) const noexcept;

  // Imported methods:
};
static_assert(sizeof(BreakOp) == sizeof(Operation));

class CaseOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::HL_CASE;
  }

  static std::optional<CaseOp> from(const ::mx::ir::Operation &that);
  static std::optional<CaseOp> producing(const ::mx::ir::Value &val);

  ::vast::hl::CaseOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Region lhs(void) const;
  ::mx::ir::Region body(void) const;
};
static_assert(sizeof(CaseOp) == sizeof(Operation));

class CondOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::HL_COND;
  }

  static std::optional<CondOp> from(const ::mx::ir::Operation &that);
  static std::optional<CondOp> producing(const ::mx::ir::Value &val);

  ::vast::hl::CondOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value result(void) const;
  ::mx::ir::Region cond_region(void) const;
  ::mx::ir::Region then_region(void) const;
  ::mx::ir::Region else_region(void) const;
};
static_assert(sizeof(CondOp) == sizeof(Operation));

class CondYieldOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::HL_COND_YIELD;
  }

  static std::optional<CondYieldOp> from(const ::mx::ir::Operation &that);
  static std::optional<CondYieldOp> producing(const ::mx::ir::Value &val);

  ::vast::hl::CondYieldOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value result(void) const;
};
static_assert(sizeof(CondYieldOp) == sizeof(Operation));

class ContinueOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::HL_CONTINUE;
  }

  static std::optional<ContinueOp> from(const ::mx::ir::Operation &that);
  static std::optional<ContinueOp> producing(const ::mx::ir::Value &val);

  ::vast::hl::ContinueOp underlying_repr(void) const noexcept;

  // Imported methods:
};
static_assert(sizeof(ContinueOp) == sizeof(Operation));

class DefaultOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::HL_DEFAULT;
  }

  static std::optional<DefaultOp> from(const ::mx::ir::Operation &that);
  static std::optional<DefaultOp> producing(const ::mx::ir::Value &val);

  ::vast::hl::DefaultOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Region body(void) const;
};
static_assert(sizeof(DefaultOp) == sizeof(Operation));

class DoOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::HL_DO;
  }

  static std::optional<DoOp> from(const ::mx::ir::Operation &that);
  static std::optional<DoOp> producing(const ::mx::ir::Value &val);

  ::vast::hl::DoOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Region body_region(void) const;
  ::mx::ir::Region cond_region(void) const;
};
static_assert(sizeof(DoOp) == sizeof(Operation));

class EmptyDeclOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::HL_EMPTY_DECL;
  }

  static std::optional<EmptyDeclOp> from(const ::mx::ir::Operation &that);
  static std::optional<EmptyDeclOp> producing(const ::mx::ir::Value &val);

  ::vast::hl::EmptyDeclOp underlying_repr(void) const noexcept;

  // Imported methods:
};
static_assert(sizeof(EmptyDeclOp) == sizeof(Operation));

class ForOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::HL_FOR;
  }

  static std::optional<ForOp> from(const ::mx::ir::Operation &that);
  static std::optional<ForOp> producing(const ::mx::ir::Value &val);

  ::vast::hl::ForOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Region cond_region(void) const;
  ::mx::ir::Region incr_region(void) const;
  ::mx::ir::Region body_region(void) const;
};
static_assert(sizeof(ForOp) == sizeof(Operation));

class FuncOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::HL_FUNC;
  }

  static std::optional<FuncOp> from(const ::mx::ir::Operation &that);
  static std::optional<FuncOp> producing(const ::mx::ir::Value &val);

  ::vast::hl::FuncOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Region body(void) const;
  std::string_view sym_name(void) const;
  //::vast::core::FunctionType function_type(void) const;
  //::vast::core::GlobalLinkageKind linkage(void) const;
  std::optional<std::string_view> sym_visibility(void) const;
  //::std::optional<::mlir::ArrayAttr> arg_attrs(void) const;
  //::std::optional<::mlir::ArrayAttr> res_attrs(void) const;
  bool is_var_arg(void) const;
  //::mlir::Region* callable_region(void) const;
  //llvm::ArrayRef<Type> callable_results(void) const;
  //::mlir::ArrayAttr callable_arg_attrs(void) const;
  //::mlir::ArrayAttr callable_res_attrs(void) const;
  //llvm::ArrayRef<Type> argument_types(void) const;
  //llvm::ArrayRef<Type> result_types(void) const;
  bool is_declaration(void) const;
};
static_assert(sizeof(FuncOp) == sizeof(Operation));

class GotoStmtOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::HL_GOTO;
  }

  static std::optional<GotoStmtOp> from(const ::mx::ir::Operation &that);
  static std::optional<GotoStmtOp> producing(const ::mx::ir::Value &val);

  ::vast::hl::GotoStmt underlying_repr(void) const noexcept;

  // Imported methods:
  //::mlir::TypedValue<::vast::hl::LabelType> label(void) const;
};
static_assert(sizeof(GotoStmtOp) == sizeof(Operation));

class IfOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::HL_IF;
  }

  static std::optional<IfOp> from(const ::mx::ir::Operation &that);
  static std::optional<IfOp> producing(const ::mx::ir::Value &val);

  ::vast::hl::IfOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Region cond_region(void) const;
  ::mx::ir::Region then_region(void) const;
  ::mx::ir::Region else_region(void) const;
  bool has_else(void) const;
};
static_assert(sizeof(IfOp) == sizeof(Operation));

class LabelDeclOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::HL_LABEL_DECL;
  }

  static std::optional<LabelDeclOp> from(const ::mx::ir::Operation &that);
  static std::optional<LabelDeclOp> producing(const ::mx::ir::Value &val);

  ::vast::hl::LabelDeclOp underlying_repr(void) const noexcept;

  // Imported methods:
  //::mlir::TypedValue<::vast::hl::LabelType> result(void) const;
  std::string_view name(void) const;
};
static_assert(sizeof(LabelDeclOp) == sizeof(Operation));

class LabelStmtOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::HL_LABEL;
  }

  static std::optional<LabelStmtOp> from(const ::mx::ir::Operation &that);
  static std::optional<LabelStmtOp> producing(const ::mx::ir::Value &val);

  ::vast::hl::LabelStmt underlying_repr(void) const noexcept;

  // Imported methods:
  //::mlir::TypedValue<::vast::hl::LabelType> label(void) const;
  ::mx::ir::Region body(void) const;
};
static_assert(sizeof(LabelStmtOp) == sizeof(Operation));

class SkipStmtOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::HL_SKIP;
  }

  static std::optional<SkipStmtOp> from(const ::mx::ir::Operation &that);
  static std::optional<SkipStmtOp> producing(const ::mx::ir::Value &val);

  ::vast::hl::SkipStmt underlying_repr(void) const noexcept;

  // Imported methods:
};
static_assert(sizeof(SkipStmtOp) == sizeof(Operation));

class SwitchOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::HL_SWITCH;
  }

  static std::optional<SwitchOp> from(const ::mx::ir::Operation &that);
  static std::optional<SwitchOp> producing(const ::mx::ir::Value &val);

  ::vast::hl::SwitchOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Region cond_region(void) const;
  //::mlir::MutableArrayRef<::mlir::Region> cases(void) const;
};
static_assert(sizeof(SwitchOp) == sizeof(Operation));

class TypeYieldOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::HL_TYPE_YIELD;
  }

  static std::optional<TypeYieldOp> from(const ::mx::ir::Operation &that);
  static std::optional<TypeYieldOp> producing(const ::mx::ir::Value &val);

  ::vast::hl::TypeYieldOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value result(void) const;
  //mlir::Type yielded(void) const;
};
static_assert(sizeof(TypeYieldOp) == sizeof(Operation));

class ValueYieldOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::HL_VALUE_YIELD;
  }

  static std::optional<ValueYieldOp> from(const ::mx::ir::Operation &that);
  static std::optional<ValueYieldOp> producing(const ::mx::ir::Value &val);

  ::vast::hl::ValueYieldOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value result(void) const;
};
static_assert(sizeof(ValueYieldOp) == sizeof(Operation));

class VarDeclOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::HL_VAR;
  }

  static std::optional<VarDeclOp> from(const ::mx::ir::Operation &that);
  static std::optional<VarDeclOp> producing(const ::mx::ir::Value &val);

  ::vast::hl::VarDeclOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value result(void) const;
  ::mx::ir::Region initializer(void) const;
  ::mx::ir::Region allocation_size(void) const;
  std::string_view name(void) const;
  //::std::optional<::vast::hl::StorageClass> storage_class(void) const;
  //::std::optional<::vast::hl::TSClass> thread_storage_class(void) const;
  bool has_local_storage(void) const;
  bool is_local_var_decl(void) const;
  bool is_static_local(void) const;
  bool has_external_storage(void) const;
  bool has_global_storage(void) const;
  //StorageDuration storage_duration(void) const;
  //DeclContextKind decl_context_kind(void) const;
  bool is_static_data_member(void) const;
  bool is_in_file_context(void) const;
  bool is_in_function_or_method_context(void) const;
  bool is_in_record_context(void) const;
  bool is_file_var_decl(void) const;
};
static_assert(sizeof(VarDeclOp) == sizeof(Operation));

class WhileOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::HL_WHILE;
  }

  static std::optional<WhileOp> from(const ::mx::ir::Operation &that);
  static std::optional<WhileOp> producing(const ::mx::ir::Value &val);

  ::vast::hl::WhileOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Region cond_region(void) const;
  ::mx::ir::Region body_region(void) const;
};
static_assert(sizeof(WhileOp) == sizeof(Operation));

class ImplicitCastOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::HL_IMPLICIT_CAST;
  }

  static std::optional<ImplicitCastOp> from(const ::mx::ir::Operation &that);
  static std::optional<ImplicitCastOp> producing(const ::mx::ir::Value &val);

  ::vast::hl::ImplicitCastOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value value(void) const;
  ::mx::ir::Value result(void) const;
  //::vast::hl::CastKind kind(void) const;
};
static_assert(sizeof(ImplicitCastOp) == sizeof(Operation));

class IndirectCallOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::HL_INDIRECT_CALL;
  }

  static std::optional<IndirectCallOp> from(const ::mx::ir::Operation &that);
  static std::optional<IndirectCallOp> producing(const ::mx::ir::Value &val);

  ::vast::hl::IndirectCallOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value callee(void) const;
  gap::generator<::mx::ir::Operand> arg_operands(void) const;
  gap::generator<::mx::ir::Result> results(void) const;
  //::mlir::CallInterfaceCallable callable_for_callee(void) const;
};
static_assert(sizeof(IndirectCallOp) == sizeof(Operation));

class InitListExprOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::HL_INITLIST;
  }

  static std::optional<InitListExprOp> from(const ::mx::ir::Operation &that);
  static std::optional<InitListExprOp> producing(const ::mx::ir::Value &val);

  ::vast::hl::InitListExpr underlying_repr(void) const noexcept;

  // Imported methods:
  gap::generator<::mx::ir::Operand> elements(void) const;
};
static_assert(sizeof(InitListExprOp) == sizeof(Operation));

class LNotOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::HL_LNOT;
  }

  static std::optional<LNotOp> from(const ::mx::ir::Operation &that);
  static std::optional<LNotOp> producing(const ::mx::ir::Value &val);

  ::vast::hl::LNotOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value arg(void) const;
  ::mx::ir::Value res(void) const;
};
static_assert(sizeof(LNotOp) == sizeof(Operation));

class MinusOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::HL_MINUS;
  }

  static std::optional<MinusOp> from(const ::mx::ir::Operation &that);
  static std::optional<MinusOp> producing(const ::mx::ir::Value &val);

  ::vast::hl::MinusOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value arg(void) const;
  ::mx::ir::Value result(void) const;
};
static_assert(sizeof(MinusOp) == sizeof(Operation));

class MulFAssignOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::HL_ASSIGN_FMUL;
  }

  static std::optional<MulFAssignOp> from(const ::mx::ir::Operation &that);
  static std::optional<MulFAssignOp> producing(const ::mx::ir::Value &val);

  ::vast::hl::MulFAssignOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value src(void) const;
  ::mx::ir::Value dst(void) const;
  ::mx::ir::Value result(void) const;
};
static_assert(sizeof(MulFAssignOp) == sizeof(Operation));

class MulFOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::HL_FMUL;
  }

  static std::optional<MulFOp> from(const ::mx::ir::Operation &that);
  static std::optional<MulFOp> producing(const ::mx::ir::Value &val);

  ::vast::hl::MulFOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value lhs(void) const;
  ::mx::ir::Value rhs(void) const;
  ::mx::ir::Value result(void) const;
};
static_assert(sizeof(MulFOp) == sizeof(Operation));

class MulIAssignOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::HL_ASSIGN_MUL;
  }

  static std::optional<MulIAssignOp> from(const ::mx::ir::Operation &that);
  static std::optional<MulIAssignOp> producing(const ::mx::ir::Value &val);

  ::vast::hl::MulIAssignOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value src(void) const;
  ::mx::ir::Value dst(void) const;
  ::mx::ir::Value result(void) const;
};
static_assert(sizeof(MulIAssignOp) == sizeof(Operation));

class MulIOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::HL_MUL;
  }

  static std::optional<MulIOp> from(const ::mx::ir::Operation &that);
  static std::optional<MulIOp> producing(const ::mx::ir::Value &val);

  ::vast::hl::MulIOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value lhs(void) const;
  ::mx::ir::Value rhs(void) const;
  ::mx::ir::Value result(void) const;
};
static_assert(sizeof(MulIOp) == sizeof(Operation));

class NotOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::HL_NOT;
  }

  static std::optional<NotOp> from(const ::mx::ir::Operation &that);
  static std::optional<NotOp> producing(const ::mx::ir::Value &val);

  ::vast::hl::NotOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value arg(void) const;
  ::mx::ir::Value result(void) const;
};
static_assert(sizeof(NotOp) == sizeof(Operation));

class PlusOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::HL_PLUS;
  }

  static std::optional<PlusOp> from(const ::mx::ir::Operation &that);
  static std::optional<PlusOp> producing(const ::mx::ir::Value &val);

  ::vast::hl::PlusOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value arg(void) const;
  ::mx::ir::Value result(void) const;
};
static_assert(sizeof(PlusOp) == sizeof(Operation));

class PostDecOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::HL_POST_DEC;
  }

  static std::optional<PostDecOp> from(const ::mx::ir::Operation &that);
  static std::optional<PostDecOp> producing(const ::mx::ir::Value &val);

  ::vast::hl::PostDecOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value arg(void) const;
  ::mx::ir::Value result(void) const;
};
static_assert(sizeof(PostDecOp) == sizeof(Operation));

class PostIncOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::HL_POST_INC;
  }

  static std::optional<PostIncOp> from(const ::mx::ir::Operation &that);
  static std::optional<PostIncOp> producing(const ::mx::ir::Value &val);

  ::vast::hl::PostIncOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value arg(void) const;
  ::mx::ir::Value result(void) const;
};
static_assert(sizeof(PostIncOp) == sizeof(Operation));

class PreDecOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::HL_PRE_DEC;
  }

  static std::optional<PreDecOp> from(const ::mx::ir::Operation &that);
  static std::optional<PreDecOp> producing(const ::mx::ir::Value &val);

  ::vast::hl::PreDecOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value arg(void) const;
  ::mx::ir::Value result(void) const;
};
static_assert(sizeof(PreDecOp) == sizeof(Operation));

class PreIncOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::HL_PRE_INC;
  }

  static std::optional<PreIncOp> from(const ::mx::ir::Operation &that);
  static std::optional<PreIncOp> producing(const ::mx::ir::Value &val);

  ::vast::hl::PreIncOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value arg(void) const;
  ::mx::ir::Value result(void) const;
};
static_assert(sizeof(PreIncOp) == sizeof(Operation));

class PredefinedExprOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::HL_PREDEFINED_EXPR;
  }

  static std::optional<PredefinedExprOp> from(const ::mx::ir::Operation &that);
  static std::optional<PredefinedExprOp> producing(const ::mx::ir::Value &val);

  ::vast::hl::PredefinedExpr underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value value(void) const;
  ::mx::ir::Value result(void) const;
  //::vast::hl::IdentKind kind(void) const;
};
static_assert(sizeof(PredefinedExprOp) == sizeof(Operation));

class RecordMemberOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::HL_MEMBER;
  }

  static std::optional<RecordMemberOp> from(const ::mx::ir::Operation &that);
  static std::optional<RecordMemberOp> producing(const ::mx::ir::Value &val);

  ::vast::hl::RecordMemberOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value record(void) const;
  ::mx::ir::Value element(void) const;
  std::string_view name(void) const;
};
static_assert(sizeof(RecordMemberOp) == sizeof(Operation));

class RemFAssignOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::HL_ASSIGN_FREM;
  }

  static std::optional<RemFAssignOp> from(const ::mx::ir::Operation &that);
  static std::optional<RemFAssignOp> producing(const ::mx::ir::Value &val);

  ::vast::hl::RemFAssignOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value src(void) const;
  ::mx::ir::Value dst(void) const;
  ::mx::ir::Value result(void) const;
};
static_assert(sizeof(RemFAssignOp) == sizeof(Operation));

class RemFOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::HL_FREM;
  }

  static std::optional<RemFOp> from(const ::mx::ir::Operation &that);
  static std::optional<RemFOp> producing(const ::mx::ir::Value &val);

  ::vast::hl::RemFOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value lhs(void) const;
  ::mx::ir::Value rhs(void) const;
  ::mx::ir::Value result(void) const;
};
static_assert(sizeof(RemFOp) == sizeof(Operation));

class RemSAssignOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::HL_ASSIGN_SREM;
  }

  static std::optional<RemSAssignOp> from(const ::mx::ir::Operation &that);
  static std::optional<RemSAssignOp> producing(const ::mx::ir::Value &val);

  ::vast::hl::RemSAssignOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value src(void) const;
  ::mx::ir::Value dst(void) const;
  ::mx::ir::Value result(void) const;
};
static_assert(sizeof(RemSAssignOp) == sizeof(Operation));

class RemSOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::HL_SREM;
  }

  static std::optional<RemSOp> from(const ::mx::ir::Operation &that);
  static std::optional<RemSOp> producing(const ::mx::ir::Value &val);

  ::vast::hl::RemSOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value lhs(void) const;
  ::mx::ir::Value rhs(void) const;
  ::mx::ir::Value result(void) const;
};
static_assert(sizeof(RemSOp) == sizeof(Operation));

class RemUAssignOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::HL_ASSIGN_UREM;
  }

  static std::optional<RemUAssignOp> from(const ::mx::ir::Operation &that);
  static std::optional<RemUAssignOp> producing(const ::mx::ir::Value &val);

  ::vast::hl::RemUAssignOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value src(void) const;
  ::mx::ir::Value dst(void) const;
  ::mx::ir::Value result(void) const;
};
static_assert(sizeof(RemUAssignOp) == sizeof(Operation));

class RemUOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::HL_UREM;
  }

  static std::optional<RemUOp> from(const ::mx::ir::Operation &that);
  static std::optional<RemUOp> producing(const ::mx::ir::Value &val);

  ::vast::hl::RemUOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value lhs(void) const;
  ::mx::ir::Value rhs(void) const;
  ::mx::ir::Value result(void) const;
};
static_assert(sizeof(RemUOp) == sizeof(Operation));

class ReturnOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::HL_RETURN;
  }

  static std::optional<ReturnOp> from(const ::mx::ir::Operation &that);
  static std::optional<ReturnOp> producing(const ::mx::ir::Value &val);

  ::vast::hl::ReturnOp underlying_repr(void) const noexcept;

  // Imported methods:
  gap::generator<::mx::ir::Operand> result(void) const;
};
static_assert(sizeof(ReturnOp) == sizeof(Operation));

class SizeOfExprOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::HL_SIZEOF_EXPR;
  }

  static std::optional<SizeOfExprOp> from(const ::mx::ir::Operation &that);
  static std::optional<SizeOfExprOp> producing(const ::mx::ir::Value &val);

  ::vast::hl::SizeOfExprOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value result(void) const;
  ::mx::ir::Region expr(void) const;
};
static_assert(sizeof(SizeOfExprOp) == sizeof(Operation));

class SizeOfTypeOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::HL_SIZEOF_TYPE;
  }

  static std::optional<SizeOfTypeOp> from(const ::mx::ir::Operation &that);
  static std::optional<SizeOfTypeOp> producing(const ::mx::ir::Value &val);

  ::vast::hl::SizeOfTypeOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value result(void) const;
  //::mlir::Type arg(void) const;
};
static_assert(sizeof(SizeOfTypeOp) == sizeof(Operation));

class StmtExprOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::HL_STMT_EXPR;
  }

  static std::optional<StmtExprOp> from(const ::mx::ir::Operation &that);
  static std::optional<StmtExprOp> producing(const ::mx::ir::Value &val);

  ::vast::hl::StmtExprOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value result(void) const;
  ::mx::ir::Region substmt(void) const;
};
static_assert(sizeof(StmtExprOp) == sizeof(Operation));

class StructDeclOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::HL_STRUCT;
  }

  static std::optional<StructDeclOp> from(const ::mx::ir::Operation &that);
  static std::optional<StructDeclOp> producing(const ::mx::ir::Value &val);

  ::vast::hl::StructDeclOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Region fields(void) const;
  std::string_view name(void) const;
};
static_assert(sizeof(StructDeclOp) == sizeof(Operation));

class SubFAssignOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::HL_ASSIGN_FSUB;
  }

  static std::optional<SubFAssignOp> from(const ::mx::ir::Operation &that);
  static std::optional<SubFAssignOp> producing(const ::mx::ir::Value &val);

  ::vast::hl::SubFAssignOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value src(void) const;
  ::mx::ir::Value dst(void) const;
  ::mx::ir::Value result(void) const;
};
static_assert(sizeof(SubFAssignOp) == sizeof(Operation));

class SubFOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::HL_FSUB;
  }

  static std::optional<SubFOp> from(const ::mx::ir::Operation &that);
  static std::optional<SubFOp> producing(const ::mx::ir::Value &val);

  ::vast::hl::SubFOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value lhs(void) const;
  ::mx::ir::Value rhs(void) const;
  ::mx::ir::Value result(void) const;
};
static_assert(sizeof(SubFOp) == sizeof(Operation));

class SubIAssignOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::HL_ASSIGN_SUB;
  }

  static std::optional<SubIAssignOp> from(const ::mx::ir::Operation &that);
  static std::optional<SubIAssignOp> producing(const ::mx::ir::Value &val);

  ::vast::hl::SubIAssignOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value src(void) const;
  ::mx::ir::Value dst(void) const;
  ::mx::ir::Value result(void) const;
};
static_assert(sizeof(SubIAssignOp) == sizeof(Operation));

class SubIOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::HL_SUB;
  }

  static std::optional<SubIOp> from(const ::mx::ir::Operation &that);
  static std::optional<SubIOp> producing(const ::mx::ir::Value &val);

  ::vast::hl::SubIOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value lhs(void) const;
  ::mx::ir::Value rhs(void) const;
  ::mx::ir::Value result(void) const;
};
static_assert(sizeof(SubIOp) == sizeof(Operation));

class SubscriptOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::HL_SUBSCRIPT;
  }

  static std::optional<SubscriptOp> from(const ::mx::ir::Operation &that);
  static std::optional<SubscriptOp> producing(const ::mx::ir::Value &val);

  ::vast::hl::SubscriptOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value array(void) const;
  ::mx::ir::Value index(void) const;
  ::mx::ir::Value result(void) const;
};
static_assert(sizeof(SubscriptOp) == sizeof(Operation));

class ThisOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::HL_THIS;
  }

  static std::optional<ThisOp> from(const ::mx::ir::Operation &that);
  static std::optional<ThisOp> producing(const ::mx::ir::Value &val);

  ::vast::hl::ThisOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value result(void) const;
};
static_assert(sizeof(ThisOp) == sizeof(Operation));

class TranslationUnitOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::HL_TRANSLATION_UNIT;
  }

  static std::optional<TranslationUnitOp> from(const ::mx::ir::Operation &that);
  static std::optional<TranslationUnitOp> producing(const ::mx::ir::Value &val);

  ::vast::hl::TranslationUnitOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Region body(void) const;
};
static_assert(sizeof(TranslationUnitOp) == sizeof(Operation));

class TypeDeclOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::HL_TYPE;
  }

  static std::optional<TypeDeclOp> from(const ::mx::ir::Operation &that);
  static std::optional<TypeDeclOp> producing(const ::mx::ir::Value &val);

  ::vast::hl::TypeDeclOp underlying_repr(void) const noexcept;

  // Imported methods:
  std::string_view name(void) const;
};
static_assert(sizeof(TypeDeclOp) == sizeof(Operation));

class TypeDefOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::HL_TYPEDEF;
  }

  static std::optional<TypeDefOp> from(const ::mx::ir::Operation &that);
  static std::optional<TypeDefOp> producing(const ::mx::ir::Value &val);

  ::vast::hl::TypeDefOp underlying_repr(void) const noexcept;

  // Imported methods:
  std::string_view name(void) const;
  //::mlir::Type type(void) const;
};
static_assert(sizeof(TypeDefOp) == sizeof(Operation));

class TypeOfExprOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::HL_TYPEOF_EXPR;
  }

  static std::optional<TypeOfExprOp> from(const ::mx::ir::Operation &that);
  static std::optional<TypeOfExprOp> producing(const ::mx::ir::Value &val);

  ::vast::hl::TypeOfExprOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Region expr(void) const;
  std::string_view name(void) const;
  //::mlir::Type type(void) const;
};
static_assert(sizeof(TypeOfExprOp) == sizeof(Operation));

class TypeOfTypeOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::HL_TYPEOF_TYPE;
  }

  static std::optional<TypeOfTypeOp> from(const ::mx::ir::Operation &that);
  static std::optional<TypeOfTypeOp> producing(const ::mx::ir::Value &val);

  ::vast::hl::TypeOfTypeOp underlying_repr(void) const noexcept;

  // Imported methods:
  //::mlir::Type type(void) const;
};
static_assert(sizeof(TypeOfTypeOp) == sizeof(Operation));

class UnionDeclOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::HL_UNION;
  }

  static std::optional<UnionDeclOp> from(const ::mx::ir::Operation &that);
  static std::optional<UnionDeclOp> producing(const ::mx::ir::Value &val);

  ::vast::hl::UnionDeclOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Region fields(void) const;
  std::string_view name(void) const;
};
static_assert(sizeof(UnionDeclOp) == sizeof(Operation));

class UnreachableOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::HL_UNREACHABLE;
  }

  static std::optional<UnreachableOp> from(const ::mx::ir::Operation &that);
  static std::optional<UnreachableOp> producing(const ::mx::ir::Value &val);

  ::vast::hl::UnreachableOp underlying_repr(void) const noexcept;

  // Imported methods:
};
static_assert(sizeof(UnreachableOp) == sizeof(Operation));

}  // namespace mx::ir::hl
