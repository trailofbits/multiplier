// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include <cassert>
#include <multiplier/Database.h>
#include <multiplier/Entities/MacroKind.h>
#include <multiplier/Reference.h>
#include <multiplier/Types.h>
#include <pasta/AST/Macro.h>
#include <pasta/AST/Stmt.h>
#include <pasta/Util/File.h>
#include <unordered_set>

#include "EntityMapper.h"

#define UNUSED(var) do { (void)(var); } while (0)

namespace indexer {
namespace {

class ReferenceGenerator {
  const pasta::AST &ast;
  const EntityMapper &em;
  pasta::Stmt stmt;
  const pasta::Decl &decl;

  mx::ReferenceRecord record;

  ReferenceGenerator(const pasta::AST &ast_,
                     const EntityMapper &em_,
                     const pasta::Stmt &stmt_,
                     const pasta::Decl &decl_)
      : ast(ast_),
        em(em_),
        stmt(stmt_),
        decl(decl_) {
    record.kind = mx::BuiltinReferenceKind::USES;
    record.from_entity_id = em.EntityId(stmt);
    record.to_entity_id = em.EntityId(decl);
    record.context_entity_id = record.from_entity_id;
  }

  gap::generator<mx::ReferenceRecord> FunctionReferences(void) &;
  gap::generator<mx::ReferenceRecord> VariableReferences(void) &;
};

namespace {

static std::optional<pasta::Expr> CalleeExpr(const pasta::Stmt &caller) {
  if (auto call = pasta::CallExpr::From(parent)) {
    return call->Callee();
  }

  return std::nullopt;
}

static std::optional<pasta::FunctionDecl> CalleeDecl(const pasta::Stmt &caller) {
  if (auto call = pasta::CallExpr::From(parent)) {
    return call->DirectCallee();
  }

  if (auto construct = pasta::CXXConstructExpr::From(parent)) {
    return construct->Constructor();
  }

  return std::nullopt;
}

}  // namespace

// Generate reference records to functions.
gap::generator<mx::ReferenceRecord>
ReferenceGenerator::FunctionReferences(void) & {
  auto parent = stmt;

  // NOTE(pag): Functions are typically either called, or implicitly casted, or
  //            both. Thus, `3` is a reasonable fudge factor to stop our
  //            classification procedure.
  for (int i = 0; i < 3; ++i) {

    switch (parent.Kind()) {
      // TODO(pag): Handle `kCXXNewExpr`.
      case pasta::StmtKind::kCallExpr:
      case pasta::StmtKind::kCXXConstructExpr:
        record.context_id = em.EntityId(parent);

        if (auto callee = CalleeDecl(parent)) {

          // This function is called.
          if (callee.value() == func) {
            record.kind = mx::BuiltinReferenceKind::CALLS;
            co_yield record;
            co_return;
          }
        }

        // This function's address is taken.
        record.kind = mx::BuiltinReferenceKind::TAKES_ADDRESS_OF;
        co_yield record;

        // This function is used as an argument.
        if (CalleeExpr(parent) != stmt) {
          record.kind = mx::BuiltinReferenceKind::TAKES_VALUE;
          co_yield record;
        }

        co_return;
        break;

        // It's either the call or an argument to the call.

      default:
        break;
    }

    auto maybe_parent = em.ParentStmt(ast, parent);
    if (!maybe_parent) {
      break;
    }

    stmt = std::move(parent);
    parent = std::move(maybe_parent.value());
  }

  // If we're down here, then we didn't find a call expression, so the function
  // wasn't called, nor was it the argument to a call. We'll yield out that its
  // address was taken, then we'll keep looking to see if it was actually
  // assigned to anything.
  record.kind = mx::BuiltinReferenceKind::TAKES_ADDRESS_OF;
  co_yield record;

  for (auto sub_record : VariableReferences()) {
    if (sub_record != record) {
      co_yield sub_record;
    }
    break;
  }
}

// Generate reference records to variables, fields, enumerators, etc.
gap::generator<mx::ReferenceRecord>
ReferenceGenerator::VariableReferences(void) & {

  auto maybe_parent = em.ParentStmt(ast, stmt);
  if (!maybe_parent) {
    co_yield record;
    co_return;
  }

  auto child = stmt;
  auto parent = std::move(maybe_parent.value());
  auto done = false;

  auto is_tested = +[] (const auto &tester, const auto &child) {
    return tester && tester->Condition() == child;
  };

  for (; !done; ) {

    switch (parent.Kind()) {
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
          if (cast->SubExpression() == stmt) {
            assert(stmt == child);
            stmt = std::move(parent);  // Propagate.
          } else {
            assert(stmt != child);
          }
        }
        break;

      case pasta::StmtKind::kParenExpr:
        if (auto cast = pasta::CastExpr::From(parent)) {
          if (cast->SubExpression() == child) {
            assert(stmt == child);
            child = parent;  // Propagate.
          } else {
            assert(stmt != child);
          }
        }
        break;

      case pasta::StmtKind::kSwitchStmt:
        if (is_tested(pasta::SwitchStmt::From(parent), child)) {
          record.context_id = em.EntityId(parent);
          record.kind = mx::BuiltinReferenceKind::TESTS_VALUE;
          co_yield record;
        }
        co_return;
  
      case pasta::StmtKind::kDoStmt:
        if (is_tested(pasta::DoStmt::From(parent), child)) {
          record.context_id = em.EntityId(parent);
          record.kind = mx::BuiltinReferenceKind::TESTS_VALUE;
          co_yield record;
        }
        co_return;
  
      case pasta::StmtKind::kWhileStmt:
        if (is_tested(pasta::WhileStmt::From(parent), child)) {
          record.context_id = em.EntityId(parent);
          record.kind = mx::BuiltinReferenceKind::TESTS_VALUE;
          co_yield record;
        }
        co_return;
  
      case pasta::StmtKind::kForStmt:
        if (is_tested(pasta::ForStmt::From(parent), child)) {
          record.context_id = em.EntityId(parent);
          record.kind = mx::BuiltinReferenceKind::TESTS_VALUE;
          co_yield record;
        }
        co_return;

      case pasta::StmtKind::kIfStmt:
        if (is_tested(pasta::IfStmt::From(parent), child)) {
          record.context_id = em.EntityId(parent);
          record.kind = mx::BuiltinReferenceKind::TESTS_VALUE;
          co_yield record;
        }
        co_return;

      case pasta::StmtKind::kConditionalOperator:
        if (auto cond = pasta::ConditionalOperator::From(parent)) {
          if (is_tested(cond)) {
            record.context_id = em.EntityId(parent);
            record.kind = mx::BuiltinReferenceKind::TESTS_VALUE;
            co_yield record;
          }
        }
        co_return;

        if (is_tested())
        if (
            cond && cond->Condition() == child) {
          record.context_id = em.EntityId(child);
          record.kind = mx::BuiltinReferenceKind::CONDITIONAL_TEST;
          return;
        }
        break;

      case pasta::StmtKind::kCaseStmt:
      case pasta::StmtKind::kDefaultStmt:
      case pasta::StmtKind::kLabelStmt:
      case pasta::StmtKind::kCompoundStmt:
      case pasta::StmtKind::kCXXTryStmt:
      case pasta::StmtKind::kCXXForRangeStmt:
      case pasta::StmtKind::kCXXCatchStmt:
      case pasta::StmtKind::kCoroutineBodyStmt:
        record.context_id = em.EntityId(child);
        record.kind = mx::BuiltinReferenceKind::USE;
        return;

      case pasta::StmtKind::kUnaryOperator:
        if (auto uop = pasta::UnaryOperator::From(parent)) {
          switch (uop->Opcode()) {
            case pasta::UnaryOperatorKind::kAddressOf:
              record.context_id = em.EntityId(parent);
              record.kind = mx::BuiltinReferenceKind::ADDRESS_OF;
              return;
            case pasta::UnaryOperatorKind::kDeref:
              record.context_id = em.EntityId(parent);
              record.kind = mx::BuiltinReferenceKind::DEREFERENCE;
              return;
            default: break;
          }
        }
        break;

      case pasta::StmtKind::kCompoundAssignOperator:
      case pasta::StmtKind::kBinaryOperator:
        if (auto bin = pasta::BinaryOperator::From(parent)) {
          if (bin->IsAssignmentOperation()) {
            if (bin->LHS() == child) {
              record.context_id = em.EntityId(parent);
              record.kind = mx::BuiltinReferenceKind::ASSIGNED_TO;
              std::swap(record.to_entity_id, record.from_entity_id);
              return;

            } else if (bin->RHS() == child) {
              record.context_id = em.EntityId(parent);
              record.kind = mx::BuiltinReferenceKind::ASSIGNED_TO;
              // Note: Identify the reference kind but does not swap
              //       reference entity id with the referer id. Info
              //       browser will take care of this.
              return;
            }
          } else if (bin->Opcode() == pasta::BinaryOperatorKind::kComma) {
            if (bin->LHS() == child) {
              record.context_id = em.EntityId(child);
              record.kind = mx::BuiltinReferenceKind::USE;
              return;
            }
          }
        }
        break;

      case pasta::StmtKind::kMemberExpr:
        if (auto member = pasta::MemberExpr::From(parent)) {
          if (member->Base() == child) {
            if (member->IsArrow() ) {

            }
          } else if (member->MemberDeclaration() == decl) {

          }
        }
        //     member &&  == child && member->IsArrow()) {
        //   record.context_id = em.EntityId(parent);
        //   record.kind = mx::BuiltinReferenceKind::DEREFERENCE;
        //   return;
        // }
        if (stmt.Kind() == pasta::StmtKind::kMemberExpr) {
          record.context_id = em.EntityId(child);
          record.kind = mx::BuiltinReferenceKind::USE;
          return;
        }
        break;

      case pasta::StmtKind::kArraySubscriptExpr:
        if (auto arr = pasta::ArraySubscriptExpr::From(parent)) {
          record.context_id = em.EntityId(parent);
          record.kind = mx::BuiltinReferenceKind::DEREFERENCE;
          return;
        }
        break;

      case pasta::StmtKind::kCallExpr:
        if (auto call = pasta::CallExpr::From(parent)) {
          if (call->Callee() == child) {
            record.context_id = em.EntityId(parent);
            record.kind = mx::BuiltinReferenceKind::DEREFERENCE;
            return;
          } else {
            if (auto dc = call->DirectCallee();
                !dc || !dc->BuiltinID()) {
              record.context_id = em.EntityId(parent);
              record.kind = mx::BuiltinReferenceKind::CALL_ARGUMENT;
              return;
            }
          }
        }
        break;

      case pasta::StmtKind::kDeclStmt:
      case pasta::StmtKind::kDesignatedInitExpr:
      case pasta::StmtKind::kDesignatedInitUpdateExpr:
        record.context_id = em.EntityId(parent);
        for (auto init : parent.Children()) {
          if (init == child) {
            // initialized by the expression
            record.kind = mx::BuiltinReferenceKind::ASSIGNED_TO;
            return;
          }
        }
        record.kind = mx::BuiltinReferenceKind::USED_IN;
        return;

      default:
        break;
    }
  }
}

// `stmt` references the variable/field/enumerator `decl` somehow; try to
// classify how.
static void VariableReferences(const pasta::AST &ast,
                               const EntityMapper &em,
                               const pasta::Stmt &stmt,
                               const pasta::Decl &decl,
                               mx::ReferenceRecord &record) {
  auto child = stmt;
  auto parent = stmt;
  auto valid_parent = false;

  bool is_field = stmt.Kind() == pasta::StmtKind::kMemberExpr;
  (void) is_field;

  assert((is_field || stmt.Kind() == pasta::StmtKind::kDeclRefExpr)
         && "Unexpected statement");
  assert(record.kind == mx::BuiltinReferenceKind::USE
         && "Reference record kind incorrectly assigned!");


  record.kind = mx::BuiltinReferenceKind::USES;
  record.context_id = em.EntityId(stmt);

  auto maybe_parent = em.ParentStmt(ast, child);
  if (!maybe_parent) {
    return;
  }

  while (valid_parent) {
    switch (parent.Kind()) {
      case pasta::StmtKind::kSwitchStmt:
        record.context_id = em.EntityId(parent);
        if (auto switch_ = pasta::SwitchStmt::From(parent);
            switch_ && switch_->Condition() == child) {
          record.kind = mx::BuiltinReferenceKind::INFLUENCES_CONTROL_FLOW;
        }
        return;
  
      case pasta::StmtKind::kDoStmt:
        record.context_id = em.EntityId(child);
        if (auto do_ = pasta::DoStmt::From(parent);
        do_ && do_->Condition() == child) {
          record.kind = mx::BuiltinReferenceKind::CONDITIONAL_TEST;
        }
        return;
  
      case pasta::StmtKind::kWhileStmt:
        record.context_id = em.EntityId(child);
        if (auto while_ = pasta::WhileStmt::From(parent);
        while_ && while_->Condition() == child) {
          record.kind = mx::BuiltinReferenceKind::CONDITIONAL_TEST;
        }
        return;
  
      case pasta::StmtKind::kForStmt:
        record.context_id = em.EntityId(child);
        if (auto for_ = pasta::ForStmt::From(parent);
        for_ && for_->Condition() == child) {
          record.kind = mx::BuiltinReferenceKind::CONDITIONAL_TEST;
        }
        return;

      case pasta::StmtKind::kIfStmt:
        record.context_id = em.EntityId(child);
        if (auto if_ = pasta::IfStmt::From(parent);
        if_ && if_->Condition() == child) {
          record.kind = mx::BuiltinReferenceKind::CONDITIONAL_TEST;
        }
        return;

      case pasta::StmtKind::kCaseStmt:
      case pasta::StmtKind::kDefaultStmt:
      case pasta::StmtKind::kLabelStmt:
      case pasta::StmtKind::kCompoundStmt:
      case pasta::StmtKind::kCXXTryStmt:
      case pasta::StmtKind::kCXXForRangeStmt:
      case pasta::StmtKind::kCXXCatchStmt:
      case pasta::StmtKind::kCoroutineBodyStmt:
        record.context_id = em.EntityId(child);
        record.kind = mx::BuiltinReferenceKind::USE;
        return;

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
          if (cast->SubExpression() == child) {
            child = parent;
            continue;
          }
        }
        break;

      case pasta::StmtKind::kParenExpr:
        if (auto cast = pasta::CastExpr::From(parent)) {
          if (cast->SubExpression() == child) {
            child = parent;
            continue;
          }
        }
        break;

      case pasta::StmtKind::kUnaryOperator:
        if (auto uop = pasta::UnaryOperator::From(parent)) {
          switch (uop->Opcode()) {
            case pasta::UnaryOperatorKind::kAddressOf:
              record.context_id = em.EntityId(parent);
              record.kind = mx::BuiltinReferenceKind::ADDRESS_OF;
              return;
            case pasta::UnaryOperatorKind::kDeref:
              record.context_id = em.EntityId(parent);
              record.kind = mx::BuiltinReferenceKind::DEREFERENCE;
              return;
            default: break;
          }
        }
        break;

      case pasta::StmtKind::kCompoundAssignOperator:
      case pasta::StmtKind::kBinaryOperator:
        if (auto bin = pasta::BinaryOperator::From(parent)) {
          if (bin->IsAssignmentOperation()) {
            if (bin->LHS() == child) {
              record.context_id = em.EntityId(parent);
              record.kind = mx::BuiltinReferenceKind::ASSIGNED_TO;
              std::swap(record.to_entity_id, record.from_entity_id);
              return;

            } else if (bin->RHS() == child) {
              record.context_id = em.EntityId(parent);
              record.kind = mx::BuiltinReferenceKind::ASSIGNED_TO;
              // Note: Identify the reference kind but does not swap
              //       reference entity id with the referer id. Info
              //       browser will take care of this.
              return;
            }
          } else if (bin->Opcode() == pasta::BinaryOperatorKind::kComma) {
            if (bin->LHS() == child) {
              record.context_id = em.EntityId(child);
              record.kind = mx::BuiltinReferenceKind::USE;
              return;
            }
          }
        }
        break;

      case pasta::StmtKind::kConditionalOperator:
        if (auto cond = pasta::ConditionalOperator::From(parent);
            cond && cond->Condition() == child) {
          record.context_id = em.EntityId(child);
          record.kind = mx::BuiltinReferenceKind::CONDITIONAL_TEST;
          return;
        }
        break;

      case pasta::StmtKind::kMemberExpr:
        if (auto member = pasta::MemberExpr::From(parent)) {
          if (member->Base() == child) {
            if (member->IsArrow() ) {

            }
          } else if (member->MemberDeclaration() == decl) {

          }
        }
        //     member &&  == child && member->IsArrow()) {
        //   record.context_id = em.EntityId(parent);
        //   record.kind = mx::BuiltinReferenceKind::DEREFERENCE;
        //   return;
        // }
        if (stmt.Kind() == pasta::StmtKind::kMemberExpr) {
          record.context_id = em.EntityId(child);
          record.kind = mx::BuiltinReferenceKind::USE;
          return;
        }
        break;

      case pasta::StmtKind::kArraySubscriptExpr:
        if (auto arr = pasta::ArraySubscriptExpr::From(parent)) {
          record.context_id = em.EntityId(parent);
          record.kind = mx::BuiltinReferenceKind::DEREFERENCE;
          return;
        }
        break;

      case pasta::StmtKind::kCallExpr:
        if (auto call = pasta::CallExpr::From(parent)) {
          if (call->Callee() == child) {
            record.context_id = em.EntityId(parent);
            record.kind = mx::BuiltinReferenceKind::DEREFERENCE;
            return;
          } else {
            if (auto dc = call->DirectCallee();
                !dc || !dc->BuiltinID()) {
              record.context_id = em.EntityId(parent);
              record.kind = mx::BuiltinReferenceKind::CALL_ARGUMENT;
              return;
            }
          }
        }
        break;

      case pasta::StmtKind::kDeclStmt:
      case pasta::StmtKind::kDesignatedInitExpr:
      case pasta::StmtKind::kDesignatedInitUpdateExpr:
        record.context_id = em.EntityId(parent);
        for (auto init : parent.Children()) {
          if (init == child) {
            // initialized by the expression
            record.kind = mx::BuiltinReferenceKind::ASSIGNED_TO;
            return;
          }
        }
        record.kind = mx::BuiltinReferenceKind::USED_IN;
        return;

      default:
        break;
    }

    if (auto maybe_parent = em.ParentStmt(ast, parent)) {
      child = parent;
      parent = maybe_parent.value();
      continue;
    }
    valid_parent = false;
  }

  record.kind = mx::BuiltinReferenceKind::USE;
  record.context_id = em.EntityId(stmt);
}

// Get the reference kind for types if referenced by a statement.
static void TypeReferences(const pasta::AST &ast,
                           const EntityMapper &em,
                           const pasta::Stmt &stmt,
                           mx::ReferenceRecord &record) {

  std::optional<pasta::Stmt> parent = stmt;
  record.kind = mx::BuiltinReferenceKind::USE;
  record.context_id = em.EntityId(stmt);
  
  for (; parent; parent = em.ParentStmt(ast, parent)) {
    if (pasta::CastExpr::From(parent.value())) {
      record.kind = mx::BuiltinReferenceKind::CAST;
      record.context_id = em.EntityId(parent);
      break;
    
    } else if (pasta::TypeTraitExpr::From(parent) ||
        pasta::UnaryExprOrTypeTraitExpr::From(parent)) {
      record.kind = mx::BuiltinReferenceKind::TYPE_TRAIT_USES;
      record.context_id = em.EntityId(parent);
      break;
    }
  }
}

} // namespace

void DeclReferenceKind(const pasta::AST &ast,
                       const EntityMapper &em,
                       const pasta::Decl &decl,
                       const pasta::Decl &ref,
                       mx::ReferenceRecord &record) {
  // Note: We don't identify the reference kind here for all ref
  //       types and uses the default value. The info browser will
  //       identify such cases and find out the reference kind.
  UNUSED(ast);
  if (auto td = pasta::TypeDecl::From(ref)) {
    record.context_id = em.EntityId(decl);
    record.kind = mx::BuiltinReferenceKind::USED_BY;
  }
}

// TODO(pag): Should we do anything special for label declarations?
void DeclReferenceKind(const pasta::AST &ast,
                       const EntityMapper &em,
                       const pasta::Stmt &stmt,
                       const pasta::Decl &ref,
                       mx::ReferenceRecord &record) {
  if (auto func = pasta::FunctionDecl::From(ref)) {
    FunctionReferences(ast, em, stmt, func.value(), record);

  } else if (auto var = pasta::VarDecl::From(ref)) {
    VariableReferences(ast, em, stmt, ref, record);

  } else if (auto field = pasta::FieldDecl::From(ref)) {
    VariableReferences(ast, em, stmt, ref, record);

  } else if (auto enumerator = pasta::EnumConstantDecl::From(ref)) {
    VariableReferences(ast, em, stmt, ref, record);

  } else if (auto enum_ = pasta::EnumDecl::From(ref)) {
    record.kind = mx::BuiltinReferenceKind::ENUMERATIONS;

  } else if (auto type = pasta::TypeDecl::From(ref)) {
    TypeReferences(ast, em, stmt, record);

  } else {
    record.kind = mx::BuiltinReferenceKind::USE;
  }
}

void DeclReferenceKind(const pasta::AST &ast,
                       const EntityMapper &em,
                       const pasta::Designator &designator,
                       const pasta::Decl &decl,
                       mx::ReferenceRecord &record) {
  UNUSED(ast);
  UNUSED(em);
  UNUSED(designator);
  UNUSED(decl);
  record.kind = mx::BuiltinReferenceKind::ASSIGNED_TO;
}

} // namespace indexer
