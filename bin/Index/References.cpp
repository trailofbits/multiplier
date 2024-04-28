// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "References.h"

#include <cassert>
#include <multiplier/Frontend/MacroKind.h>
#include <multiplier/Reference.h>
#include <multiplier/Types.h>

#include "EntityMapper.h"

#include <glog/logging.h>

namespace indexer {
namespace {

static std::optional<pasta::Expr> CalleeExpr(const pasta::Stmt &stmt) {
  if (auto call = pasta::CallExpr::From(stmt)) {
    return call->Callee();
  }

  return std::nullopt;
}

static std::optional<pasta::Expr> ConditionExpr(const pasta::Stmt &t) {
  switch (t.Kind()) {
    case pasta::StmtKind::kSwitchStmt:
      return reinterpret_cast<const pasta::SwitchStmt &>(t).Condition();
    case pasta::StmtKind::kDoStmt:
      return reinterpret_cast<const pasta::DoStmt &>(t).Condition();
    case pasta::StmtKind::kWhileStmt:
      return reinterpret_cast<const pasta::WhileStmt &>(t).Condition();
    case pasta::StmtKind::kForStmt:
      return reinterpret_cast<const pasta::ForStmt &>(t).Condition();
    case pasta::StmtKind::kIfStmt:
      return reinterpret_cast<const pasta::IfStmt &>(t).Condition();
    case pasta::StmtKind::kConditionalOperator:
      return reinterpret_cast<const pasta::ConditionalOperator &>(t).Condition();
    default:
      return std::nullopt;
  }
}

// Assuming `parent` is something like a `CallExpr`, and `child` is some child
// statement nested directly inside of `parent`, and `decl` is transitively
// referenced by `child`, then classify the usage of `decl` within the context
// of `parent`.
static mx::BuiltinReferenceKind ClassifyCall(const pasta::Stmt &parent,
                                             const pasta::Stmt &child,
                                             const pasta::Decl &decl) {
  // This function is used as a callee.
  if (CalleeExpr(parent) == child || ReferencedDecl(parent) == decl) {
    return mx::BuiltinReferenceKind::CALLS;
  
  // This declaration is used as an argument.
  } else {
    if (pasta::FunctionDecl::From(decl)) {
      return mx::BuiltinReferenceKind::TAKES_ADDRESS;
    } else if (pasta::TypeDecl::From(decl)) {
      return mx::BuiltinReferenceKind::USES_TYPE;
    } else {
      return mx::BuiltinReferenceKind::TAKES_VALUE;
    }
  }
}

// Assuming `parent` is an `ArraySubscriptExpr`, and `child` is either the base
// or `index` of that array subscript, go and classify the access of `child`
// within `parent`.
//
// NOTE(pag): We don't check `parent.base() == child`, but instead look at the
//            type of `child`, as C has a rather dumb idiom where you can do
//            `index[base]` or `base[index]`.
static mx::BuiltinReferenceKind ClassifyArraySubscript(
    const pasta::Stmt & /* parent */, const pasta::Stmt &child_) {
  auto child = pasta::Expr::From(child_);
  if (!child) {
    return mx::BuiltinReferenceKind::TAKES_VALUE;
  }

  auto child_type = child->Type();
  if (!child_type) {
    return mx::BuiltinReferenceKind::TAKES_VALUE;
  }

  if (child_type->DesugaredType().IsAnyPointerType()) {
    return mx::BuiltinReferenceKind::ACCESSES_VALUE;
  }
  
  return mx::BuiltinReferenceKind::TAKES_VALUE;
}

// Given that `parent` is an assignment, and `child` is either the destination
// or source, classify the use of a declaration transitively reachable from
// `child` inside of `parent`.
static mx::BuiltinReferenceKind ClassifyAssignmentOperator(
    const pasta::BinaryOperator &parent, const pasta::Stmt &child) {
  if (parent.LHS() == child) {
    if (parent.Kind() == pasta::StmtKind::kCompoundAssignOperator) {
      return mx::BuiltinReferenceKind::UPDATES_VALUE;
    } else {
      return mx::BuiltinReferenceKind::WRITES_VALUE;
    }
  } else {
    assert(parent.RHS() == child);
    return mx::BuiltinReferenceKind::COPIES_VALUE;
  }
}

// Given that `member_pointer` is on the right-hand side of something like
// `base.*member_pointer` or `base->*member_pointer`, check to see if the
// type of `member_pointer` is a member function pointer type.
static bool MemberPointerIsMethodPointer(pasta::Expr member_pointer) {
  auto t = member_pointer.Type();
  if (!t) {
    return false;
  }

  auto mpt = pasta::MemberPointerType::From(t->DesugaredType());
  if (!mpt) {
    return false;
  }

  return mpt->IsMemberFunctionPointer();
}

enum class ContinuationAction {
  kKeepAscending,
  kDoneClassifying,
};

using ClassificationAction = std::pair<std::optional<mx::BuiltinReferenceKind>,
                                       ContinuationAction>;

// Assuming `parent` is a statement and `child` is an immediate descendent of
// `parent`, and `decl` is transitively reference by `child`, try to use the
// kind of `parent` to classify how `child` uses `decl`.
//
// Sometimes we can't make a classification, and so we signal to the caller
// via `keep_ascending = true;` to go up to the grandparent. Sometimes we can
// make a classification, in which case we `return true`. Finally, sometimes
// we do both: make a classification and signal that we want to potentially make
// more classifications.
static ClassificationAction ClassifyParentChild(
    const pasta::Stmt &parent, const pasta::Stmt &child,
    const pasta::Decl &decl) {

  switch (auto pk = parent.Kind()) {
    // Treat sources of casts kind of like taints from the perspective of
    // trying to find assignments to things, as well as call arguments to
    // things.
    case pasta::StmtKind::kBuiltinBitCastExpr:
    case pasta::StmtKind::kCStyleCastExpr:
    case pasta::StmtKind::kCXXFunctionalCastExpr:
    case pasta::StmtKind::kCXXAddrspaceCastExpr:
    case pasta::StmtKind::kCXXConstCastExpr:
    case pasta::StmtKind::kCXXDynamicCastExpr:
    case pasta::StmtKind::kCXXReinterpretCastExpr:
    case pasta::StmtKind::kCXXStaticCastExpr:
    case pasta::StmtKind::kObjCBridgedCastExpr:
    case pasta::StmtKind::kImplicitCastExpr:
      if (auto cast = pasta::CastExpr::From(parent)) {
        if (pasta::TypeDecl::From(decl)) {
          return {mx::BuiltinReferenceKind::CASTS_WITH_TYPE,
                  ContinuationAction::kDoneClassifying};

        } else if (auto conversion_func = cast->ConversionFunction();
                   conversion_func && conversion_func.value() == decl) {
          return {mx::BuiltinReferenceKind::CALLS,
                  ContinuationAction::kDoneClassifying};
        }
      }
      [[fallthrough]];

    case pasta::StmtKind::kParenExpr:
      return {std::nullopt, ContinuationAction::kKeepAscending};

    case pasta::StmtKind::kSwitchStmt:
    case pasta::StmtKind::kDoStmt:
    case pasta::StmtKind::kWhileStmt:
    case pasta::StmtKind::kForStmt:
    case pasta::StmtKind::kIfStmt:
    case pasta::StmtKind::kConditionalOperator:
      if (auto cond_expr = ConditionExpr(parent)) {
        if (cond_expr.value() == child) {
          return {mx::BuiltinReferenceKind::TESTS_VALUE,
                  ContinuationAction::kDoneClassifying};
        }
      } else if (parent.Kind() == pasta::StmtKind::kForStmt) {
        // if parent is not a conditional expr, the reference kind
        // will be a updating the ValueDecl
        // e.g:
        //      int j, j;
        //      for(i=0, j=0;;) {}
        return {mx::BuiltinReferenceKind::UPDATES_VALUE,
                ContinuationAction::kDoneClassifying};
      } else {
        assert(false);
      }
      [[fallthrough]];

    case pasta::StmtKind::kCaseStmt:
    case pasta::StmtKind::kDefaultStmt:
    case pasta::StmtKind::kLabelStmt:
    case pasta::StmtKind::kCompoundStmt:
    case pasta::StmtKind::kCXXTryStmt:
    case pasta::StmtKind::kCXXForRangeStmt:
    case pasta::StmtKind::kCXXCatchStmt:
    case pasta::StmtKind::kCoroutineBodyStmt:
      break;

    case pasta::StmtKind::kUnaryOperator:
      switch (auto uop = pasta::UnaryOperator::From(parent); uop->Opcode()) {
        case pasta::UnaryOperatorKind::kPostIncrement:
        case pasta::UnaryOperatorKind::kPostDecrement:
          return {mx::BuiltinReferenceKind::UPDATES_VALUE,
                  ContinuationAction::kDoneClassifying};

        case pasta::UnaryOperatorKind::kPreIncrement:
        case pasta::UnaryOperatorKind::kPreDecrement:
          return {mx::BuiltinReferenceKind::UPDATES_VALUE,
                  ContinuationAction::kKeepAscending};

        case pasta::UnaryOperatorKind::kPlus:
        case pasta::UnaryOperatorKind::kMinus:
        case pasta::UnaryOperatorKind::kNot:
        case pasta::UnaryOperatorKind::kReal:
        case pasta::UnaryOperatorKind::kImag:
          return {std::nullopt, ContinuationAction::kKeepAscending};

        case pasta::UnaryOperatorKind::kAddressOf:
          return {mx::BuiltinReferenceKind::TAKES_ADDRESS,
                  ContinuationAction::kDoneClassifying};

        case pasta::UnaryOperatorKind::kDeref:
          return {mx::BuiltinReferenceKind::ACCESSES_VALUE,
                  ContinuationAction::kDoneClassifying};

        case pasta::UnaryOperatorKind::kLNot:
          return {mx::BuiltinReferenceKind::TESTS_VALUE,
                  ContinuationAction::kDoneClassifying};

        default:
          break;
      }
      break;

    case pasta::StmtKind::kCompoundAssignOperator:
    case pasta::StmtKind::kBinaryOperator:
      switch (auto bin = pasta::BinaryOperator::From(parent); bin->Opcode()) {

        // `base.*member` and `base->*member`.
        case pasta::BinaryOperatorKind::kPointerMemoryD:
        case pasta::BinaryOperatorKind::kPointerMemoryI:

          // This could be a call, e.g. `base->*member()`, and so we want
          // it to look like a `CALLS` of `member`. But that has to be done
          // by the next iteration, so we'll update the default.
          return {mx::BuiltinReferenceKind::ACCESSES_VALUE,
                  ((bin->RHS() == child &&
                    MemberPointerIsMethodPointer(bin->RHS())) ?
                   ContinuationAction::kKeepAscending :
                   ContinuationAction::kDoneClassifying)};

        // `lhs = rhs`, or `lhs <op>= *`.
        case pasta::BinaryOperatorKind::kAssign:
        case pasta::BinaryOperatorKind::kMulAssign:
        case pasta::BinaryOperatorKind::kDivAssign:
        case pasta::BinaryOperatorKind::kRemAssign:
        case pasta::BinaryOperatorKind::kAddAssign:
        case pasta::BinaryOperatorKind::kSubAssign:
        case pasta::BinaryOperatorKind::kShlAssign:
        case pasta::BinaryOperatorKind::kShrAssign:
        case pasta::BinaryOperatorKind::kAndAssign:
        case pasta::BinaryOperatorKind::kXorAssign:
        case pasta::BinaryOperatorKind::kOrAssign:
          // Keep ascending. This assignment might be, for example, a
          // function argument, and so the source/dest is also passed as an
          // argument. Similarly, it might be inside of a larger assignment,
          // e.g. `a = b = c`, or inside of a comma operator, e.g.
          // `..., a = b`.
          return {ClassifyAssignmentOperator(*bin, child),
                  ContinuationAction::kKeepAscending};

        // The right-hand side of a comma operator propagates up.
        case pasta::BinaryOperatorKind::kComma:
          return {std::nullopt, (bin->RHS() == child ?
                                 ContinuationAction::kKeepAscending :
                                 ContinuationAction::kDoneClassifying)};

        case pasta::BinaryOperatorKind::kCmp:
        case pasta::BinaryOperatorKind::kLT:
        case pasta::BinaryOperatorKind::kGT:
        case pasta::BinaryOperatorKind::kLE:
        case pasta::BinaryOperatorKind::kGE:
        case pasta::BinaryOperatorKind::kEQ:
        case pasta::BinaryOperatorKind::kNE:
        case pasta::BinaryOperatorKind::kLAnd:
        case pasta::BinaryOperatorKind::kLOr:
          return {mx::BuiltinReferenceKind::TESTS_VALUE,
                  ContinuationAction::kDoneClassifying};

        default:
          break;
      }
      break;

    case pasta::StmtKind::kDeclRefExpr:
      // Seeing an instance where the child stmt is referering to a VarDecl
      // and parent of it is DeclRefExpr
      return {mx::BuiltinReferenceKind::USES_VALUE,
              ContinuationAction::kKeepAscending};
      //assert(false);
      //break;

    case pasta::StmtKind::kMemberExpr:
      if (auto member = pasta::MemberExpr::From(parent)) {
        //assert(member->Base() == child);
        if (pasta::CXXMethodDecl::From(member->MemberDeclaration())) {
          return {std::nullopt, ContinuationAction::kKeepAscending};

        } else {
          return {mx::BuiltinReferenceKind::ACCESSES_VALUE,
                  ContinuationAction::kDoneClassifying};
        }
      }

      assert(false);
      break;

    case pasta::StmtKind::kArraySubscriptExpr:
      return {ClassifyArraySubscript(parent, child),
              ContinuationAction::kDoneClassifying};

    case pasta::StmtKind::kCallExpr:
    case pasta::StmtKind::kCXXConstructExpr:
    case pasta::StmtKind::kCXXNewExpr:
    case pasta::StmtKind::kCXXDeleteExpr:
    case pasta::StmtKind::kCXXMemberCallExpr:
    case pasta::StmtKind::kCXXOperatorCallExpr:
      return {ClassifyCall(parent, child, decl),
              ContinuationAction::kDoneClassifying};

    case pasta::StmtKind::kTypeTraitExpr:
    case pasta::StmtKind::kUnaryExprOrTypeTraitExpr:
      return {(pasta::TypeDecl::From(decl) ?
               mx::BuiltinReferenceKind::USES_TYPE :
               mx::BuiltinReferenceKind::TAKES_VALUE),
              ContinuationAction::kDoneClassifying};

    case pasta::StmtKind::kDeclStmt:
    case pasta::StmtKind::kDesignatedInitExpr:
    case pasta::StmtKind::kDesignatedInitUpdateExpr:
      for (auto init : parent.Children()) {
        if (init == child) {
          return {mx::BuiltinReferenceKind::COPIES_VALUE,
                  ContinuationAction::kDoneClassifying};
        }
      }
      break;

    default:
      break;
  }

  return {std::nullopt, ContinuationAction::kDoneClassifying};
}

}  // namespace

// Generate reference records to functions, variables, fields, enumerators, etc.
//
// This function works by starting at `stmt`, which is something like a
// `DeclRefExpr` which references `to_decl`, and then ascends up through the
// parent links.
gap::generator<mx::ReferenceRecord> EnumerateStmtToDeclReferences(
    pasta::AST ast, const EntityMapper *em,
    pasta::Stmt /* from_ */ stmt, pasta::Decl to_decl) {

  auto from_id = em->EntityId(stmt);
  mx::ReferenceRecord record{
      from_id,
      em->EntityId(to_decl),
      from_id  /* context_entity_id */,
      mx::BuiltinReferenceKind::USES_VALUE
  };

  if (pasta::FunctionDecl::From(to_decl).has_value()) {
    record.kind = mx::BuiltinReferenceKind::TAKES_ADDRESS;
  }

  std::optional<pasta::Stmt> maybe_parent;

  // If we're referencing a type, then we're probably referencing it from
  // a `CastExpr` or something like that.
  if (pasta::TypeDecl::From(to_decl).has_value()) {
    record.kind = mx::BuiltinReferenceKind::USES_TYPE;
    maybe_parent = stmt;
  } else {
    maybe_parent = em->ParentStmt(ast, stmt);
  }

  std::optional<mx::ReferenceRecord> prev_record;

  while (maybe_parent) {
    auto [classified_kind, continuation_action] = ClassifyParentChild(
        maybe_parent.value(), stmt, to_decl);

    if (classified_kind) {
      record.context_entity_id = em->EntityId(maybe_parent.value());
      record.kind = classified_kind.value();
      co_yield record;
      prev_record = record;
    }

    switch (continuation_action) {
      case ContinuationAction::kDoneClassifying:
        maybe_parent.reset();
        break;
      case ContinuationAction::kKeepAscending:
        stmt = std::move(maybe_parent.value());
        maybe_parent = em->ParentStmt(ast, stmt);
        break;
    }
  }

  // Try to prevent redundant records. It's not entirely necessary, as the
  // database will skip them too.
  if (prev_record && prev_record.value() == record) {
    co_return;
  }

  // If we got down here, then we didn't emit anything, so fall back on the
  // default.
  co_yield record;
  co_return;
}

// Get the reference kind for types referenced by a declaration.
gap::generator<mx::ReferenceRecord> EnumerateDeclToTypeReferences(
    pasta::AST ast, const EntityMapper *em,
    pasta::Decl from_decl, pasta::Decl to_decl) {

  auto from_id = em->EntityId(from_decl);
  co_yield mx::ReferenceRecord{
      from_id,
      em->EntityId(to_decl),
      from_id  /* context_entity_id */,
      mx::BuiltinReferenceKind::USES_TYPE
  };
}

// Get the references for fields referenced by a designator.
gap::generator<mx::ReferenceRecord> EnumerateDesignatorToDeclReferences(
    pasta::AST ast, const EntityMapper *em,
    pasta::Designator from_designator, pasta::Decl to_decl) {

  auto from_id = em->EntityId(from_designator);
  mx::ReferenceRecord record{
      from_id,
      em->EntityId(to_decl),
      from_id  /* context_entity_id */,
      mx::BuiltinReferenceKind::WRITES_VALUE
  };

  if (auto parent_stmt_id = em->ParentStmtId(from_designator);
      parent_stmt_id != mx::kInvalidEntityId) {
    record.context_entity_id = parent_stmt_id;
  }

  co_yield record;
}

// Try to find the `Decl` referenced by a particular `decl`.
gap::generator<pasta::Decl> DeclReferencesFrom(pasta::Decl decl) {

  // NOTE(pag): We'll get the parameter type references through visiting the
  //            `ParmVarDecl`s.
  if (auto func = pasta::FunctionDecl::From(decl)) {
    for (auto ref : DeclReferencesFrom(func->ReturnType())) {
      co_yield ref;
    }
  } else if (auto field = pasta::FieldDecl::From(decl)) {
    for (auto ref : DeclReferencesFrom(field->Type())) {
      co_yield ref;
    }
  } else if (auto var = pasta::VarDecl::From(decl)) {
    for (auto ref : DeclReferencesFrom(var->Type())) {
      co_yield ref;
    }
  } else if (auto enum_ = pasta::EnumDecl::From(decl)) {
    if (auto base_type = enum_->IntegerType()) {
      for (auto ref : DeclReferencesFrom(base_type.value())) {
        co_yield ref;
      }
    }
  } else if (auto td_ = pasta::TypedefNameDecl::From(decl)) {
    for (auto ref : DeclReferencesFrom(td_->UnderlyingType())) {
      co_yield ref;
    }
  } else if (auto dd = pasta::DecompositionDecl::From(decl)) {
    for (auto binding : dd->Bindings()) {
      co_yield binding;
    }
  }
}

// Try to find the `Decl` referenced by a particular `stmt`.
gap::generator<pasta::Decl> DeclReferencesFrom(pasta::Stmt stmt) {
  // E.g. `a` or `a()` where `a` is a `Decl`. This also covers things like
  // `a + b` where `+` is a `T::operator+`.
  if (auto dre = pasta::DeclRefExpr::From(stmt)) {
    co_yield dre->Declaration();

  // `foo->bar`, mark `bar` as being referenced. `foo` will be handled as
  // a `DeclRefExpr`.
  } else if (auto me = pasta::MemberExpr::From(stmt)) {
    co_yield me->MemberDeclaration();

  // If we have `a = X()` for class name `X`, then mark the constructor as
  // used in this fragment.
  } else if (auto ce = pasta::CXXConstructExpr::From(stmt)) {
    co_yield ce->Constructor();

  // If we have `new T`, then mark `T` as being referenced in this fragment.
  } else if (auto cxx_new = pasta::CXXNewExpr::From(stmt)) {
    for (auto ref : DeclReferencesFrom(cxx_new->AllocatedType())) {
      co_yield ref;
    }
    auto cxx_new_op = cxx_new->OperatorNew();
    if (cxx_new_op.has_value()) {
      co_yield cxx_new_op.value();
    }

  // If we have `delete x`, then mark `` as being referenced in this fragment.
  } else if (auto cxx_del = pasta::CXXDeleteExpr::From(stmt)) {
    auto cxx_del_op = cxx_del->OperatorDelete();
    if (cxx_del_op.has_value()) {
      co_yield cxx_del_op.value();
    }

    //co_yield cxx_del->OperatorDelete();

  // If we have `(T *) b` then mark `T` as being referenced in this fragment.
  } else if (auto cast = pasta::CastExpr::From(stmt)) {

    if (auto conversion_func = cast->ConversionFunction()) {
      co_yield conversion_func.value();
    }

    // TODO(pag): If we want to allow implicit casts, then update
    //            `ReferenceIterator::Advance`.
    if (stmt.Kind() != pasta::StmtKind::kImplicitCastExpr) {
      if (auto tt = cast->Type()) {
        for (auto ref : DeclReferencesFrom(tt.value())) {
          co_yield ref;
        }
      }
    }

  // If we have `sizeof(T)` or `alignof(T)` or something like these then
  // mark `T` as being referenced in this fragment.
  } else if (auto unary = pasta::UnaryExprOrTypeTraitExpr::From(stmt)) {
    if (auto arg_type = unary->ArgumentType()) {
      for (auto ref : DeclReferencesFrom(arg_type.value())) {
        co_yield ref;
      }
    }

  // XREF(pag): Issue #185. Make sure we record references to labels.
  } else if (auto goto_ = pasta::GotoStmt::From(stmt)) {
    co_yield goto_->Label();

  } else if (auto addr_label = pasta::AddrLabelExpr::From(stmt)) {
    co_yield addr_label->Label();
  }
}

#define GEN(x) for (auto ref : DeclReferencesFrom(x)) { co_yield ref; }

// Try to find the `Decl` referenced by a particular `type`.
gap::generator<pasta::Decl> DeclReferencesFrom(pasta::Type type) {
  switch (type.Kind()) {
    case pasta::TypeKind::kAdjusted:
    case pasta::TypeKind::kDecayed: {
      auto &tt = reinterpret_cast<const pasta::AdjustedType &>(type);
      GEN(tt.OriginalType());
      break;
    }
    case pasta::TypeKind::kConstantArray: {
      auto &tt = reinterpret_cast<const pasta::ConstantArrayType &>(type);
      if (auto expr = tt.SizeExpression()) {
        GEN(expr.value());
      }
      GEN(tt.ElementType());
      break;
    }
    case pasta::TypeKind::kDependentSizedArray: {
      auto &tt = reinterpret_cast<const pasta::DependentSizedArrayType &>(type);
      if (auto sz_expr = tt.SizeExpression()) {
        GEN(sz_expr.value());
      }
      GEN(tt.ElementType());
      break;
    }
    case pasta::TypeKind::kIncompleteArray:
    case pasta::TypeKind::kVariableArray: {
      auto &tt = reinterpret_cast<const pasta::ArrayType &>(type);
      GEN(tt.ElementType());
      break;
    }
    case pasta::TypeKind::kAtomic: {
      auto &tt = reinterpret_cast<const pasta::AtomicType &>(type);
      GEN(tt.ValueType());
      break;
    }
    case pasta::TypeKind::kAttributed: {
      auto &tt = reinterpret_cast<const pasta::AttributedType &>(type);
      GEN(tt.EquivalentType());
      break;
    }
    case pasta::TypeKind::kBTFTagAttributed: {
      auto &tt = reinterpret_cast<const pasta::BTFTagAttributedType &>(type);
      GEN(tt.WrappedType());
      break;
    }
    case pasta::TypeKind::kBitInt: {
      break;
    }
    case pasta::TypeKind::kBlockPointer: {
      auto &tt = reinterpret_cast<const pasta::BlockPointerType &>(type);
      GEN(tt.PointeeType());
      break;
    }
    case pasta::TypeKind::kBuiltin: {
      break;
    }
    case pasta::TypeKind::kComplex: {
      auto &tt = reinterpret_cast<const pasta::ComplexType &>(type);
      GEN(tt.ElementType());
      break;
    }
    case pasta::TypeKind::kDecltype: {
      auto &tt = reinterpret_cast<const pasta::DecltypeType &>(type);
      GEN(tt.UnderlyingType());
      GEN(tt.UnderlyingExpression());
      break;
    }
    case pasta::TypeKind::kAuto:
    case pasta::TypeKind::kDeducedTemplateSpecialization: {
      auto &tt = reinterpret_cast<const pasta::DeducedType &>(type);
      if (auto dt = tt.ResolvedType()) {
        GEN(dt.value());
      }
      break;
    }
    case pasta::TypeKind::kDependentAddressSpace: {
      auto &tt = reinterpret_cast<const pasta::DependentAddressSpaceType &>(type);
      GEN(tt.AddressSpaceExpression());
      GEN(tt.PointeeType());
      break;
    }
    case pasta::TypeKind::kDependentBitInt: {
      auto &tt = reinterpret_cast<const pasta::DependentBitIntType &>(type);
      GEN(tt.NumBitsExpression());
      break;
    }
    case pasta::TypeKind::kDependentName: {
      break;
    }
    case pasta::TypeKind::kDependentSizedExtVector: {
      auto &tt = reinterpret_cast<const pasta::DependentSizedExtVectorType &>(type);
      GEN(tt.SizeExpression());
      GEN(tt.ElementType());
      break;
    }

    // TODO(pag): Reference template arguments?
    case pasta::TypeKind::kDependentTemplateSpecialization: {
      break;
    }
    case pasta::TypeKind::kDependentVector: {
      auto &tt = reinterpret_cast<const pasta::DependentVectorType &>(type);
      GEN(tt.SizeExpression());
      GEN(tt.ElementType());
      break;
    }
    case pasta::TypeKind::kElaborated: {
      auto &tt = reinterpret_cast<const pasta::ElaboratedType &>(type);
      GEN(tt.NamedType());
      break;
    }
    case pasta::TypeKind::kFunctionNoProto: {
      auto &tt = reinterpret_cast<const pasta::FunctionNoProtoType &>(type);
      GEN(tt.ReturnType());
      break;
    }
    case pasta::TypeKind::kFunctionProto: {
      auto &tt = reinterpret_cast<const pasta::FunctionProtoType &>(type);
      GEN(tt.ReturnType());
      if (auto esd = tt.ExceptionSpecDeclaration()) {
        co_yield esd.value();
      }
      if (auto est = tt.ExceptionSpecTemplate()) {
        co_yield est.value();
      }
      if (auto nee = tt.NoexceptExpression()) {
        GEN(nee.value());
      }
      for (auto pt : tt.ParameterTypes()) {
        GEN(pt);
      }
      for (auto et : tt.ExceptionTypes()) {
        GEN(et);
      }
      break;
    }
    // TODO(pag): Think more about these.
    case pasta::TypeKind::kInjectedClassName: {
      auto &tt = reinterpret_cast<const pasta::InjectedClassNameType &>(type);
      co_yield tt.Declaration();
      break;
    }
    case pasta::TypeKind::kMacroQualified: {
      auto &tt = reinterpret_cast<const pasta::MacroQualifiedType &>(type);
      GEN(tt.UnderlyingType());
      break;
    }
    case pasta::TypeKind::kConstantMatrix: {
      break;
    }
    case pasta::TypeKind::kDependentSizedMatrix: {
      auto &tt = reinterpret_cast<const pasta::DependentSizedMatrixType &>(type);
      GEN(tt.ColumnExpression());
      GEN(tt.RowExpression());
      break;
    }
    case pasta::TypeKind::kMemberPointer: {
      auto &tt = reinterpret_cast<const pasta::MemberPointerType &>(type);
      GEN(tt.Class());
      GEN(tt.PointeeType());
      break;
    }
    case pasta::TypeKind::kObjCObjectPointer: {
      auto &tt = reinterpret_cast<const pasta::ObjCObjectPointerType &>(type);
      GEN(tt.ObjectType());
      GEN(tt.PointeeType());
      for (auto arg : tt.TypeArgumentsAsWritten()) {
        GEN(arg);
      }

      // TODO(pag): Include these?
      for (auto arg : tt.Qualifiers()) {
        GEN(arg);
      }
      for (auto arg : tt.Protocols()) {
        GEN(arg);
      }
      break;
    }
    case pasta::TypeKind::kObjCObject: {
      auto &tt = reinterpret_cast<const pasta::ObjCObjectType &>(type);
      co_yield tt.Interface();
      if (auto sct = tt.SuperClassType()) {
        GEN(sct.value());  // TODO(pag): Include this?
      }
      for (auto arg : tt.TypeArgumentsAsWritten()) {
        GEN(arg);
      }
      // TODO(pag): Other methods?
      break;
    }
    case pasta::TypeKind::kObjCInterface: {
      auto &tt = reinterpret_cast<const pasta::ObjCInterfaceType &>(type);
      co_yield tt.Declaration();
      break;
    }
    case pasta::TypeKind::kObjCTypeParam: {
      auto &tt = reinterpret_cast<const pasta::ObjCTypeParamType &>(type);
      co_yield tt.Declaration();
      break;
    }
    case pasta::TypeKind::kPackExpansion: {
      // TODO(pag): Investigate this.
      break;
    }
    case pasta::TypeKind::kParen: {
      auto &tt = reinterpret_cast<const pasta::ParenType &>(type);
      GEN(tt.InnerType());
      break;
    }
    case pasta::TypeKind::kPipe: {
      auto &tt = reinterpret_cast<const pasta::PipeType &>(type);
      GEN(tt.ElementType());
      break;
    }
    case pasta::TypeKind::kPointer: {
      auto &tt = reinterpret_cast<const pasta::PointerType &>(type);
      GEN(tt.PointeeType());
      break;
    }
    case pasta::TypeKind::kLValueReference:
    case pasta::TypeKind::kRValueReference: {
      auto &tt = reinterpret_cast<const pasta::ReferenceType &>(type);
      GEN(tt.PointeeTypeAsWritten());
      break;
    }
    case pasta::TypeKind::kSubstTemplateTypeParmPack: {
      // TODO(pag): Investigate this.
      break;
    }
    case pasta::TypeKind::kSubstTemplateTypeParm: {
      // TODO(pag): Investigate this.
      break;
    }
    case pasta::TypeKind::kEnum: {
      auto &tt = reinterpret_cast<const pasta::EnumType &>(type);
      co_yield tt.Declaration();
      break;
    }
    case pasta::TypeKind::kRecord: {
      auto &tt = reinterpret_cast<const pasta::RecordType &>(type);
      co_yield tt.Declaration();
      break;
    }
    case pasta::TypeKind::kTemplateSpecialization: {
      // TODO(pag): Investigate this.
      break;
    }
    case pasta::TypeKind::kTemplateTypeParm: {
      auto &tt = reinterpret_cast<const pasta::TemplateTypeParmType &>(type);
      if (auto d = tt.Declaration()) {
        co_yield d.value();
      }
      break;
    }
    case pasta::TypeKind::kTypeOfExpr: {
      auto &tt = reinterpret_cast<const pasta::TypeOfExprType &>(type);
      GEN(tt.UnderlyingExpression());
      break;
    }
    case pasta::TypeKind::kTypeOf: {
      auto &tt = reinterpret_cast<const pasta::TypeOfType &>(type);
      GEN(tt.UnmodifiedType());
      break;
    }
    case pasta::TypeKind::kTypedef: {
      auto &tt = reinterpret_cast<const pasta::TypedefType &>(type);
      co_yield tt.Declaration();
      break;
    }
    case pasta::TypeKind::kUnaryTransform: {
      auto &tt = reinterpret_cast<const pasta::UnaryTransformType &>(type);
      if (tt.UnderlyingType().has_value()) {
        GEN(tt.UnderlyingType().value());
      }
      break;
    }
    case pasta::TypeKind::kUnresolvedUsing: {
      auto &tt = reinterpret_cast<const pasta::UnresolvedUsingType &>(type);
      co_yield tt.Declaration();
      break;
    }
    case pasta::TypeKind::kUsing: {
      auto &tt = reinterpret_cast<const pasta::UsingType &>(type);
      GEN(tt.UnderlyingType());
      co_yield tt.FoundDeclaration();
      break;
    }
    case pasta::TypeKind::kVector: {
      auto &tt = reinterpret_cast<const pasta::VectorType &>(type);
      GEN(tt.ElementType());
      break;
    }
    case pasta::TypeKind::kExtVector: {
      auto &tt = reinterpret_cast<const pasta::ExtVectorType &>(type);
      GEN(tt.ElementType());
      break;
    }
    case pasta::TypeKind::kQualified: {
      auto &tt = reinterpret_cast<const pasta::QualifiedType &>(type);
      GEN(tt.UnqualifiedType());
      break;
    }
  }
}

// Try to find the `Decl` referenced by a particular `designator`.
gap::generator<pasta::Decl> DeclReferencesFrom(pasta::Designator designator) {
  if (auto to_field = designator.Field()) {
    co_yield std::move(to_field.value());
  }
}

// Try to find the `Decl` referenced by a particular `type`.
std::optional<pasta::Decl> ReferencedDecl(const pasta::Type &type) {
  for (auto decl : DeclReferencesFrom(type)) {
    return decl;
  }
  return std::nullopt;
}

// Try to identify the declaration referenced by a statement.
std::optional<pasta::Decl> ReferencedDecl(const pasta::Stmt &stmt) {
  for (auto decl : DeclReferencesFrom(stmt)) {
    return decl;
  }

  return std::nullopt;
}

} // namespace indexer
