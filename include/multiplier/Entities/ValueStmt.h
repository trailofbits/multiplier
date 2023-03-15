// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Stmt.h"

namespace mx {
class EntityProvider;
class Index;
class AddrLabelExpr;
class ArrayInitIndexExpr;
class ArrayInitLoopExpr;
class ArraySubscriptExpr;
class ArrayTypeTraitExpr;
class AsTypeExpr;
class AtomicExpr;
class AttributedStmt;
class BinaryConditionalOperator;
class BinaryOperator;
class BlockExpr;
class BuiltinBitCastExpr;
class CStyleCastExpr;
class CUDAKernelCallExpr;
class CXXAddrspaceCastExpr;
class CXXBindTemporaryExpr;
class CXXBoolLiteralExpr;
class CXXConstCastExpr;
class CXXConstructExpr;
class CXXDefaultArgExpr;
class CXXDefaultInitExpr;
class CXXDeleteExpr;
class CXXDependentScopeMemberExpr;
class CXXDynamicCastExpr;
class CXXFoldExpr;
class CXXFunctionalCastExpr;
class CXXInheritedCtorInitExpr;
class CXXMemberCallExpr;
class CXXNewExpr;
class CXXNoexceptExpr;
class CXXNullPtrLiteralExpr;
class CXXOperatorCallExpr;
class CXXPseudoDestructorExpr;
class CXXReinterpretCastExpr;
class CXXRewrittenBinaryOperator;
class CXXScalarValueInitExpr;
class CXXStaticCastExpr;
class CXXStdInitializerListExpr;
class CXXTemporaryObjectExpr;
class CXXThisExpr;
class CXXThrowExpr;
class CXXTypeidExpr;
class CXXUnresolvedConstructExpr;
class CXXUuidofExpr;
class CallExpr;
class CharacterLiteral;
class ChooseExpr;
class CoawaitExpr;
class CompoundAssignOperator;
class CompoundLiteralExpr;
class ConceptSpecializationExpr;
class ConditionalOperator;
class ConstantExpr;
class ConvertVectorExpr;
class CoyieldExpr;
class Decl;
class DeclRefExpr;
class DependentCoawaitExpr;
class DependentScopeDeclRefExpr;
class DesignatedInitExpr;
class DesignatedInitUpdateExpr;
class Expr;
class ExprWithCleanups;
class ExpressionTraitExpr;
class ExtVectorElementExpr;
class FixedPointLiteral;
class FloatingLiteral;
class FunctionParmPackExpr;
class GNUNullExpr;
class GenericSelectionExpr;
class ImaginaryLiteral;
class ImplicitCastExpr;
class ImplicitValueInitExpr;
class InitListExpr;
class IntegerLiteral;
class LabelStmt;
class LambdaExpr;
class MSPropertyRefExpr;
class MSPropertySubscriptExpr;
class MaterializeTemporaryExpr;
class MatrixSubscriptExpr;
class MemberExpr;
class NoInitExpr;
class OMPArraySectionExpr;
class OMPArrayShapingExpr;
class OMPIteratorExpr;
class ObjCArrayLiteral;
class ObjCAvailabilityCheckExpr;
class ObjCBoolLiteralExpr;
class ObjCBoxedExpr;
class ObjCBridgedCastExpr;
class ObjCDictionaryLiteral;
class ObjCEncodeExpr;
class ObjCIndirectCopyRestoreExpr;
class ObjCIsaExpr;
class ObjCIvarRefExpr;
class ObjCMessageExpr;
class ObjCPropertyRefExpr;
class ObjCProtocolExpr;
class ObjCSelectorExpr;
class ObjCStringLiteral;
class ObjCSubscriptRefExpr;
class OffsetOfExpr;
class OpaqueValueExpr;
class PackExpansionExpr;
class ParenExpr;
class ParenListExpr;
class PredefinedExpr;
class PseudoObjectExpr;
class RecoveryExpr;
class RequiresExpr;
class SYCLUniqueStableNameExpr;
class ShuffleVectorExpr;
class SizeOfPackExpr;
class SourceLocExpr;
class Stmt;
class StmtExpr;
class StringLiteral;
class SubstNonTypeTemplateParmExpr;
class SubstNonTypeTemplateParmPackExpr;
class Token;
class TypeTraitExpr;
class TypoExpr;
class UnaryExprOrTypeTraitExpr;
class UnaryOperator;
class UnresolvedLookupExpr;
class UnresolvedMemberExpr;
class UserDefinedLiteral;
class VAArgExpr;
class ValueStmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class ValueStmt : public Stmt {
 private:
  friend class FragmentImpl;
  friend class Stmt;
 public:
  static gap::generator<ValueStmt> in(const Fragment &frag);
  static gap::generator<ValueStmt> in(const File &file);
  static gap::generator<ValueStmt> in(const Index &index);
  static gap::generator<ValueStmt> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<ValueStmt> by_id(const Index &, EntityId);

  static gap::generator<ValueStmt> containing(const Decl &decl);
  static gap::generator<ValueStmt> containing(const std::optional<Decl> &decl);

  static gap::generator<ValueStmt> containing(const Stmt &stmt);
  static gap::generator<ValueStmt> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<ValueStmt> from(const Stmt &parent);

  inline static std::optional<ValueStmt> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return ValueStmt::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ValueStmt> from(const Reference &r);
  static std::optional<ValueStmt> from(const TokenContext &t);

  std::optional<Expr> expression_statement(void) const;
};

static_assert(sizeof(ValueStmt) == sizeof(Stmt));

#endif
} // namespace mx
