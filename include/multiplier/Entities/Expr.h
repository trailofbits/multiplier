// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "ExprObjectKind.h"
#include "ExprValueKind.h"
#include "ValueStmt.h"

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
class FieldDecl;
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
class Type;
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
class Expr : public ValueStmt {
 private:
  friend class FragmentImpl;
  friend class ValueStmt;
  friend class Stmt;
 public:
  static gap::generator<Expr> in(const Fragment &frag);
  static gap::generator<Expr> in(const File &file);
  static gap::generator<Expr> in(const Index &index);
  static gap::generator<Expr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<Expr> by_id(const Index &, EntityId);

  static gap::generator<Expr> containing(const Decl &decl);
  static gap::generator<Expr> containing(const std::optional<Decl> &decl);

  static gap::generator<Expr> containing(const Stmt &stmt);
  static gap::generator<Expr> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<Expr> from(const Stmt &parent);

  inline static std::optional<Expr> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return Expr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<Expr> from(const Reference &r);
  static std::optional<Expr> from(const TokenContext &t);

  bool has_side_effects(void) const;
  Expr ignore_casts(void) const;
  Expr ignore_conversion_operator_single_step(void) const;
  Expr ignore_implicit_casts(void) const;
  Expr ignore_implicit(void) const;
  Expr ignore_implicit_as_written(void) const;
  Expr ignore_parenthesis_base_casts(void) const;
  Expr ignore_parenthesis_casts(void) const;
  Expr ignore_parenthesis_implicit_casts(void) const;
  Expr ignore_parenthesis_l_value_casts(void) const;
  Expr ignore_parenthesis_noop_casts(void) const;
  Expr ignore_parentheses(void) const;
  Expr ignore_unless_spelled_in_source(void) const;
  bool contains_errors(void) const;
  bool contains_unexpanded_parameter_pack(void) const;
  Expr best_dynamic_class_type_expression(void) const;
  Token expression_token(void) const;
  std::optional<ObjCPropertyRefExpr> obj_c_property(void) const;
  ExprObjectKind object_kind(void) const;
  std::optional<Decl> referenced_declaration_of_callee(void) const;
  std::optional<FieldDecl> source_bit_field(void) const;
  std::optional<Type> type(void) const;
  ExprValueKind value_kind(void) const;
  bool has_non_trivial_call(void) const;
  std::optional<bool> is_cxx98_integral_constant_expression(void) const;
  bool is_default_argument(void) const;
  bool is_gl_value(void) const;
  bool is_implicit_cxx_this(void) const;
  bool is_instantiation_dependent(void) const;
  std::optional<bool> is_integer_constant_expression(void) const;
  bool is_known_to_have_boolean_value(void) const;
  bool is_l_value(void) const;
  bool is_objcgc_candidate(void) const;
  bool is_obj_c_self_expression(void) const;
  bool is_ordinary_or_bit_field_object(void) const;
  bool is_pr_value(void) const;
  bool is_read_if_discarded_in_c_plus_plus11(void) const;
  bool is_type_dependent(void) const;
  bool is_value_dependent(void) const;
  bool is_x_value(void) const;
  bool refers_to_bit_field(void) const;
  bool refers_to_global_register_variable(void) const;
  bool refers_to_matrix_element(void) const;
  bool refers_to_vector_element(void) const;
};

static_assert(sizeof(Expr) == sizeof(ValueStmt));

#endif
} // namespace mx
