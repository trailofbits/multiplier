// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/ValueStmt.h>

#include <multiplier/Entities/AddrLabelExpr.h>
#include <multiplier/Entities/ArrayInitIndexExpr.h>
#include <multiplier/Entities/ArrayInitLoopExpr.h>
#include <multiplier/Entities/ArraySubscriptExpr.h>
#include <multiplier/Entities/ArrayTypeTraitExpr.h>
#include <multiplier/Entities/AsTypeExpr.h>
#include <multiplier/Entities/AtomicExpr.h>
#include <multiplier/Entities/AttributedStmt.h>
#include <multiplier/Entities/BinaryConditionalOperator.h>
#include <multiplier/Entities/BinaryOperator.h>
#include <multiplier/Entities/BlockExpr.h>
#include <multiplier/Entities/BuiltinBitCastExpr.h>
#include <multiplier/Entities/CStyleCastExpr.h>
#include <multiplier/Entities/CUDAKernelCallExpr.h>
#include <multiplier/Entities/CXXAddrspaceCastExpr.h>
#include <multiplier/Entities/CXXBindTemporaryExpr.h>
#include <multiplier/Entities/CXXBoolLiteralExpr.h>
#include <multiplier/Entities/CXXConstCastExpr.h>
#include <multiplier/Entities/CXXConstructExpr.h>
#include <multiplier/Entities/CXXDefaultArgExpr.h>
#include <multiplier/Entities/CXXDefaultInitExpr.h>
#include <multiplier/Entities/CXXDeleteExpr.h>
#include <multiplier/Entities/CXXDependentScopeMemberExpr.h>
#include <multiplier/Entities/CXXDynamicCastExpr.h>
#include <multiplier/Entities/CXXFoldExpr.h>
#include <multiplier/Entities/CXXFunctionalCastExpr.h>
#include <multiplier/Entities/CXXInheritedCtorInitExpr.h>
#include <multiplier/Entities/CXXMemberCallExpr.h>
#include <multiplier/Entities/CXXNewExpr.h>
#include <multiplier/Entities/CXXNoexceptExpr.h>
#include <multiplier/Entities/CXXNullPtrLiteralExpr.h>
#include <multiplier/Entities/CXXOperatorCallExpr.h>
#include <multiplier/Entities/CXXParenListInitExpr.h>
#include <multiplier/Entities/CXXPseudoDestructorExpr.h>
#include <multiplier/Entities/CXXReinterpretCastExpr.h>
#include <multiplier/Entities/CXXRewrittenBinaryOperator.h>
#include <multiplier/Entities/CXXScalarValueInitExpr.h>
#include <multiplier/Entities/CXXStaticCastExpr.h>
#include <multiplier/Entities/CXXStdInitializerListExpr.h>
#include <multiplier/Entities/CXXTemporaryObjectExpr.h>
#include <multiplier/Entities/CXXThisExpr.h>
#include <multiplier/Entities/CXXThrowExpr.h>
#include <multiplier/Entities/CXXTypeidExpr.h>
#include <multiplier/Entities/CXXUnresolvedConstructExpr.h>
#include <multiplier/Entities/CXXUuidofExpr.h>
#include <multiplier/Entities/CallExpr.h>
#include <multiplier/Entities/CharacterLiteral.h>
#include <multiplier/Entities/ChooseExpr.h>
#include <multiplier/Entities/CoawaitExpr.h>
#include <multiplier/Entities/CompoundAssignOperator.h>
#include <multiplier/Entities/CompoundLiteralExpr.h>
#include <multiplier/Entities/ConceptSpecializationExpr.h>
#include <multiplier/Entities/ConditionalOperator.h>
#include <multiplier/Entities/ConstantExpr.h>
#include <multiplier/Entities/ConvertVectorExpr.h>
#include <multiplier/Entities/CoyieldExpr.h>
#include <multiplier/Entities/Decl.h>
#include <multiplier/Entities/DeclRefExpr.h>
#include <multiplier/Entities/DependentCoawaitExpr.h>
#include <multiplier/Entities/DependentScopeDeclRefExpr.h>
#include <multiplier/Entities/DesignatedInitExpr.h>
#include <multiplier/Entities/DesignatedInitUpdateExpr.h>
#include <multiplier/Entities/Expr.h>
#include <multiplier/Entities/ExprWithCleanups.h>
#include <multiplier/Entities/ExpressionTraitExpr.h>
#include <multiplier/Entities/ExtVectorElementExpr.h>
#include <multiplier/Entities/FixedPointLiteral.h>
#include <multiplier/Entities/FloatingLiteral.h>
#include <multiplier/Entities/FunctionParmPackExpr.h>
#include <multiplier/Entities/GNUNullExpr.h>
#include <multiplier/Entities/GenericSelectionExpr.h>
#include <multiplier/Entities/ImaginaryLiteral.h>
#include <multiplier/Entities/ImplicitCastExpr.h>
#include <multiplier/Entities/ImplicitValueInitExpr.h>
#include <multiplier/Entities/InitListExpr.h>
#include <multiplier/Entities/IntegerLiteral.h>
#include <multiplier/Entities/LabelStmt.h>
#include <multiplier/Entities/LambdaExpr.h>
#include <multiplier/Entities/MSPropertyRefExpr.h>
#include <multiplier/Entities/MSPropertySubscriptExpr.h>
#include <multiplier/Entities/MaterializeTemporaryExpr.h>
#include <multiplier/Entities/MatrixSubscriptExpr.h>
#include <multiplier/Entities/MemberExpr.h>
#include <multiplier/Entities/NoInitExpr.h>
#include <multiplier/Entities/OMPArraySectionExpr.h>
#include <multiplier/Entities/OMPArrayShapingExpr.h>
#include <multiplier/Entities/OMPIteratorExpr.h>
#include <multiplier/Entities/ObjCArrayLiteral.h>
#include <multiplier/Entities/ObjCAvailabilityCheckExpr.h>
#include <multiplier/Entities/ObjCBoolLiteralExpr.h>
#include <multiplier/Entities/ObjCBoxedExpr.h>
#include <multiplier/Entities/ObjCBridgedCastExpr.h>
#include <multiplier/Entities/ObjCDictionaryLiteral.h>
#include <multiplier/Entities/ObjCEncodeExpr.h>
#include <multiplier/Entities/ObjCIndirectCopyRestoreExpr.h>
#include <multiplier/Entities/ObjCIsaExpr.h>
#include <multiplier/Entities/ObjCIvarRefExpr.h>
#include <multiplier/Entities/ObjCMessageExpr.h>
#include <multiplier/Entities/ObjCPropertyRefExpr.h>
#include <multiplier/Entities/ObjCProtocolExpr.h>
#include <multiplier/Entities/ObjCSelectorExpr.h>
#include <multiplier/Entities/ObjCStringLiteral.h>
#include <multiplier/Entities/ObjCSubscriptRefExpr.h>
#include <multiplier/Entities/OffsetOfExpr.h>
#include <multiplier/Entities/OpaqueValueExpr.h>
#include <multiplier/Entities/PackExpansionExpr.h>
#include <multiplier/Entities/ParenExpr.h>
#include <multiplier/Entities/ParenListExpr.h>
#include <multiplier/Entities/PredefinedExpr.h>
#include <multiplier/Entities/PseudoObjectExpr.h>
#include <multiplier/Entities/RecoveryExpr.h>
#include <multiplier/Entities/RequiresExpr.h>
#include <multiplier/Entities/SYCLUniqueStableNameExpr.h>
#include <multiplier/Entities/ShuffleVectorExpr.h>
#include <multiplier/Entities/SizeOfPackExpr.h>
#include <multiplier/Entities/SourceLocExpr.h>
#include <multiplier/Entities/Stmt.h>
#include <multiplier/Entities/StmtExpr.h>
#include <multiplier/Entities/StringLiteral.h>
#include <multiplier/Entities/SubstNonTypeTemplateParmExpr.h>
#include <multiplier/Entities/SubstNonTypeTemplateParmPackExpr.h>
#include <multiplier/Entities/Token.h>
#include <multiplier/Entities/TypeTraitExpr.h>
#include <multiplier/Entities/TypoExpr.h>
#include <multiplier/Entities/UnaryExprOrTypeTraitExpr.h>
#include <multiplier/Entities/UnaryOperator.h>
#include <multiplier/Entities/UnresolvedLookupExpr.h>
#include <multiplier/Entities/UnresolvedMemberExpr.h>
#include <multiplier/Entities/UserDefinedLiteral.h>
#include <multiplier/Entities/VAArgExpr.h>

#include "../API.h"
#include "../Stmt.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

gap::generator<ValueStmt> ValueStmt::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = ValueStmt::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool ValueStmt::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : ValueStmt::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

gap::generator<ValueStmt> ValueStmt::containing(const Decl &decl) {
  for (auto ancestor = decl.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = ValueStmt::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<ValueStmt> ValueStmt::containing(const std::optional<Decl> &decl) {
  if (decl.has_value()) {
    for (auto res : containing(decl.value())) {
      co_yield res;
    }
  }
}

gap::generator<ValueStmt> ValueStmt::containing(const Stmt &stmt) {
  for (auto ancestor = stmt.parent_statement(); ancestor.has_value();
       ancestor = ancestor->parent_statement()) {
    if (auto d = ValueStmt::from(*ancestor)) {
      co_yield *d;
    }
  }
}

gap::generator<ValueStmt> ValueStmt::containing(const std::optional<Stmt> &stmt) {
  if (stmt.has_value()) {
    for (auto res : containing(stmt.value())) {
      co_yield res;
    }
  }
}

bool ValueStmt::contains(const Decl &decl) {
  for (auto &parent : ValueStmt::containing(decl)) {
    if (*this == parent) { return true; }
  }
  return false;
}

bool ValueStmt::contains(const Stmt &stmt) {
  for (auto &parent : ValueStmt::containing(stmt)) {
    if (*this == parent) { return true; }
  }
  return false;
}

std::optional<ValueStmt> ValueStmt::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<StmtId>(vid)) {
    return ValueStmt::from(index.statement(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

static const StmtKind kValueStmtDerivedKinds[] = {
    AttributedStmt::static_kind(),
    LabelStmt::static_kind(),
    ExpressionTraitExpr::static_kind(),
    ExtVectorElementExpr::static_kind(),
    FixedPointLiteral::static_kind(),
    FloatingLiteral::static_kind(),
    FunctionParmPackExpr::static_kind(),
    GNUNullExpr::static_kind(),
    GenericSelectionExpr::static_kind(),
    ImaginaryLiteral::static_kind(),
    ImplicitValueInitExpr::static_kind(),
    InitListExpr::static_kind(),
    IntegerLiteral::static_kind(),
    LambdaExpr::static_kind(),
    MSPropertyRefExpr::static_kind(),
    MSPropertySubscriptExpr::static_kind(),
    MaterializeTemporaryExpr::static_kind(),
    MatrixSubscriptExpr::static_kind(),
    MemberExpr::static_kind(),
    NoInitExpr::static_kind(),
    OMPArraySectionExpr::static_kind(),
    OMPArrayShapingExpr::static_kind(),
    OMPIteratorExpr::static_kind(),
    ObjCArrayLiteral::static_kind(),
    ObjCAvailabilityCheckExpr::static_kind(),
    ObjCBoolLiteralExpr::static_kind(),
    ObjCBoxedExpr::static_kind(),
    ObjCDictionaryLiteral::static_kind(),
    ObjCEncodeExpr::static_kind(),
    ObjCIndirectCopyRestoreExpr::static_kind(),
    ObjCIsaExpr::static_kind(),
    ObjCIvarRefExpr::static_kind(),
    ObjCMessageExpr::static_kind(),
    ObjCPropertyRefExpr::static_kind(),
    ObjCProtocolExpr::static_kind(),
    ObjCSelectorExpr::static_kind(),
    ObjCStringLiteral::static_kind(),
    ObjCSubscriptRefExpr::static_kind(),
    OffsetOfExpr::static_kind(),
    OpaqueValueExpr::static_kind(),
    PackExpansionExpr::static_kind(),
    ParenExpr::static_kind(),
    ParenListExpr::static_kind(),
    PredefinedExpr::static_kind(),
    PseudoObjectExpr::static_kind(),
    RecoveryExpr::static_kind(),
    RequiresExpr::static_kind(),
    SYCLUniqueStableNameExpr::static_kind(),
    ShuffleVectorExpr::static_kind(),
    SizeOfPackExpr::static_kind(),
    SourceLocExpr::static_kind(),
    StmtExpr::static_kind(),
    StringLiteral::static_kind(),
    SubstNonTypeTemplateParmExpr::static_kind(),
    SubstNonTypeTemplateParmPackExpr::static_kind(),
    TypeTraitExpr::static_kind(),
    TypoExpr::static_kind(),
    UnaryExprOrTypeTraitExpr::static_kind(),
    UnaryOperator::static_kind(),
    VAArgExpr::static_kind(),
    AddrLabelExpr::static_kind(),
    ArrayInitIndexExpr::static_kind(),
    ArrayInitLoopExpr::static_kind(),
    ArraySubscriptExpr::static_kind(),
    ArrayTypeTraitExpr::static_kind(),
    AsTypeExpr::static_kind(),
    AtomicExpr::static_kind(),
    BinaryOperator::static_kind(),
    BlockExpr::static_kind(),
    CXXBindTemporaryExpr::static_kind(),
    CXXBoolLiteralExpr::static_kind(),
    CXXConstructExpr::static_kind(),
    CXXDefaultArgExpr::static_kind(),
    CXXDefaultInitExpr::static_kind(),
    CXXDeleteExpr::static_kind(),
    CXXDependentScopeMemberExpr::static_kind(),
    CXXFoldExpr::static_kind(),
    CXXInheritedCtorInitExpr::static_kind(),
    CXXNewExpr::static_kind(),
    CXXNoexceptExpr::static_kind(),
    CXXNullPtrLiteralExpr::static_kind(),
    CXXParenListInitExpr::static_kind(),
    CXXPseudoDestructorExpr::static_kind(),
    CXXRewrittenBinaryOperator::static_kind(),
    CXXScalarValueInitExpr::static_kind(),
    CXXStdInitializerListExpr::static_kind(),
    CXXThisExpr::static_kind(),
    CXXThrowExpr::static_kind(),
    CXXTypeidExpr::static_kind(),
    CXXUnresolvedConstructExpr::static_kind(),
    CXXUuidofExpr::static_kind(),
    CallExpr::static_kind(),
    CharacterLiteral::static_kind(),
    ChooseExpr::static_kind(),
    CompoundLiteralExpr::static_kind(),
    ConceptSpecializationExpr::static_kind(),
    ConvertVectorExpr::static_kind(),
    DeclRefExpr::static_kind(),
    DependentCoawaitExpr::static_kind(),
    DependentScopeDeclRefExpr::static_kind(),
    DesignatedInitExpr::static_kind(),
    DesignatedInitUpdateExpr::static_kind(),
    ConstantExpr::static_kind(),
    ExprWithCleanups::static_kind(),
    UnresolvedLookupExpr::static_kind(),
    UnresolvedMemberExpr::static_kind(),
    BinaryConditionalOperator::static_kind(),
    ConditionalOperator::static_kind(),
    CompoundAssignOperator::static_kind(),
    CXXTemporaryObjectExpr::static_kind(),
    UserDefinedLiteral::static_kind(),
    CUDAKernelCallExpr::static_kind(),
    CXXMemberCallExpr::static_kind(),
    CXXOperatorCallExpr::static_kind(),
    ImplicitCastExpr::static_kind(),
    CoyieldExpr::static_kind(),
    CoawaitExpr::static_kind(),
    ObjCBridgedCastExpr::static_kind(),
    BuiltinBitCastExpr::static_kind(),
    CStyleCastExpr::static_kind(),
    CXXFunctionalCastExpr::static_kind(),
    CXXReinterpretCastExpr::static_kind(),
    CXXStaticCastExpr::static_kind(),
    CXXAddrspaceCastExpr::static_kind(),
    CXXConstCastExpr::static_kind(),
    CXXDynamicCastExpr::static_kind(),
};

std::optional<ValueStmt> ValueStmt::from(const Stmt &parent) {
  switch (parent.kind()) {
    case AttributedStmt::static_kind():
    case LabelStmt::static_kind():
    case ExpressionTraitExpr::static_kind():
    case ExtVectorElementExpr::static_kind():
    case FixedPointLiteral::static_kind():
    case FloatingLiteral::static_kind():
    case FunctionParmPackExpr::static_kind():
    case GNUNullExpr::static_kind():
    case GenericSelectionExpr::static_kind():
    case ImaginaryLiteral::static_kind():
    case ImplicitValueInitExpr::static_kind():
    case InitListExpr::static_kind():
    case IntegerLiteral::static_kind():
    case LambdaExpr::static_kind():
    case MSPropertyRefExpr::static_kind():
    case MSPropertySubscriptExpr::static_kind():
    case MaterializeTemporaryExpr::static_kind():
    case MatrixSubscriptExpr::static_kind():
    case MemberExpr::static_kind():
    case NoInitExpr::static_kind():
    case OMPArraySectionExpr::static_kind():
    case OMPArrayShapingExpr::static_kind():
    case OMPIteratorExpr::static_kind():
    case ObjCArrayLiteral::static_kind():
    case ObjCAvailabilityCheckExpr::static_kind():
    case ObjCBoolLiteralExpr::static_kind():
    case ObjCBoxedExpr::static_kind():
    case ObjCDictionaryLiteral::static_kind():
    case ObjCEncodeExpr::static_kind():
    case ObjCIndirectCopyRestoreExpr::static_kind():
    case ObjCIsaExpr::static_kind():
    case ObjCIvarRefExpr::static_kind():
    case ObjCMessageExpr::static_kind():
    case ObjCPropertyRefExpr::static_kind():
    case ObjCProtocolExpr::static_kind():
    case ObjCSelectorExpr::static_kind():
    case ObjCStringLiteral::static_kind():
    case ObjCSubscriptRefExpr::static_kind():
    case OffsetOfExpr::static_kind():
    case OpaqueValueExpr::static_kind():
    case PackExpansionExpr::static_kind():
    case ParenExpr::static_kind():
    case ParenListExpr::static_kind():
    case PredefinedExpr::static_kind():
    case PseudoObjectExpr::static_kind():
    case RecoveryExpr::static_kind():
    case RequiresExpr::static_kind():
    case SYCLUniqueStableNameExpr::static_kind():
    case ShuffleVectorExpr::static_kind():
    case SizeOfPackExpr::static_kind():
    case SourceLocExpr::static_kind():
    case StmtExpr::static_kind():
    case StringLiteral::static_kind():
    case SubstNonTypeTemplateParmExpr::static_kind():
    case SubstNonTypeTemplateParmPackExpr::static_kind():
    case TypeTraitExpr::static_kind():
    case TypoExpr::static_kind():
    case UnaryExprOrTypeTraitExpr::static_kind():
    case UnaryOperator::static_kind():
    case VAArgExpr::static_kind():
    case AddrLabelExpr::static_kind():
    case ArrayInitIndexExpr::static_kind():
    case ArrayInitLoopExpr::static_kind():
    case ArraySubscriptExpr::static_kind():
    case ArrayTypeTraitExpr::static_kind():
    case AsTypeExpr::static_kind():
    case AtomicExpr::static_kind():
    case BinaryOperator::static_kind():
    case BlockExpr::static_kind():
    case CXXBindTemporaryExpr::static_kind():
    case CXXBoolLiteralExpr::static_kind():
    case CXXConstructExpr::static_kind():
    case CXXDefaultArgExpr::static_kind():
    case CXXDefaultInitExpr::static_kind():
    case CXXDeleteExpr::static_kind():
    case CXXDependentScopeMemberExpr::static_kind():
    case CXXFoldExpr::static_kind():
    case CXXInheritedCtorInitExpr::static_kind():
    case CXXNewExpr::static_kind():
    case CXXNoexceptExpr::static_kind():
    case CXXNullPtrLiteralExpr::static_kind():
    case CXXParenListInitExpr::static_kind():
    case CXXPseudoDestructorExpr::static_kind():
    case CXXRewrittenBinaryOperator::static_kind():
    case CXXScalarValueInitExpr::static_kind():
    case CXXStdInitializerListExpr::static_kind():
    case CXXThisExpr::static_kind():
    case CXXThrowExpr::static_kind():
    case CXXTypeidExpr::static_kind():
    case CXXUnresolvedConstructExpr::static_kind():
    case CXXUuidofExpr::static_kind():
    case CallExpr::static_kind():
    case CharacterLiteral::static_kind():
    case ChooseExpr::static_kind():
    case CompoundLiteralExpr::static_kind():
    case ConceptSpecializationExpr::static_kind():
    case ConvertVectorExpr::static_kind():
    case DeclRefExpr::static_kind():
    case DependentCoawaitExpr::static_kind():
    case DependentScopeDeclRefExpr::static_kind():
    case DesignatedInitExpr::static_kind():
    case DesignatedInitUpdateExpr::static_kind():
    case ConstantExpr::static_kind():
    case ExprWithCleanups::static_kind():
    case UnresolvedLookupExpr::static_kind():
    case UnresolvedMemberExpr::static_kind():
    case BinaryConditionalOperator::static_kind():
    case ConditionalOperator::static_kind():
    case CompoundAssignOperator::static_kind():
    case CXXTemporaryObjectExpr::static_kind():
    case UserDefinedLiteral::static_kind():
    case CUDAKernelCallExpr::static_kind():
    case CXXMemberCallExpr::static_kind():
    case CXXOperatorCallExpr::static_kind():
    case ImplicitCastExpr::static_kind():
    case CoyieldExpr::static_kind():
    case CoawaitExpr::static_kind():
    case ObjCBridgedCastExpr::static_kind():
    case BuiltinBitCastExpr::static_kind():
    case CStyleCastExpr::static_kind():
    case CXXFunctionalCastExpr::static_kind():
    case CXXReinterpretCastExpr::static_kind():
    case CXXStaticCastExpr::static_kind():
    case CXXAddrspaceCastExpr::static_kind():
    case CXXConstCastExpr::static_kind():
    case CXXDynamicCastExpr::static_kind():
      return reinterpret_cast<const ValueStmt &>(parent);
    default:
      return std::nullopt;
  }
}

gap::generator<ValueStmt> ValueStmt::in(const Index &index) {
  const EntityProvider::Ptr ep = entity_provider_of(index);
  for (StmtKind k : kValueStmtDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k)) {
      if (std::optional<ValueStmt> e = ValueStmt::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<ValueStmt> ValueStmt::in(const Fragment &frag) {
  const EntityProvider::Ptr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (StmtKind k : kValueStmtDerivedKinds) {
    for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
      if (std::optional<ValueStmt> e = ValueStmt::from(Stmt(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<ValueStmt> ValueStmt::in(const File &file) {
  const EntityProvider::Ptr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (StmtKind k : kValueStmtDerivedKinds) {
      for (StmtImplPtr eptr : ep->StmtsFor(ep, k, frag_id)) {
        if (std::optional<ValueStmt> e = ValueStmt::from(Stmt(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<ValueStmt> ValueStmt::from(const Reference &r) {
  return ValueStmt::from(r.as_statement());
}

std::optional<ValueStmt> ValueStmt::from(const TokenContext &t) {
  return ValueStmt::from(t.as_statement());
}

std::optional<Expr> ValueStmt::expression_statement(void) const {
  if (true) {
    RawEntityId eid = impl->reader.getVal9();
    if (eid == kInvalidEntityId) {
      return std::nullopt;
    }
    if (auto eptr = impl->ep->StmtFor(impl->ep, eid)) {
      return Expr::from(Stmt(std::move(eptr)));
    }
  }
  return std::nullopt;
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
