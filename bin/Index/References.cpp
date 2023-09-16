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

static void FunctionReferences(const pasta::AST &ast,
                               const EntityMapper &em,
                               const pasta::Stmt &stmt,
                               const pasta::FunctionDecl &func,
                               mx::ReferenceRecord &record) {
  auto valid_parent = true;
  auto parent = stmt;
  record.kind = mx::BuiltinReferenceKind::TAKES_ADDRESS_OF;
  while (valid_parent) {
    switch (parent.Kind()) {
      case pasta::StmtKind::kCallExpr:
        if (auto call = pasta::CallExpr::From(parent)) {
          if (call->DirectCallee() == func) {
            record.kind = mx::BuiltinReferenceKind::CALLS;
            record.context_id = em.EntityId(parent);
            return;
          }
        }
        break;
      default: break;
    }

    if (auto maybe_next = em.ParentStmt(ast, parent)) {
      parent = maybe_next.value();
      continue;
    }
    valid_parent = false;
  }
}

static void VariableReferences(const pasta::AST &ast,
                               const EntityMapper &em,
                               const pasta::Stmt &stmt,
                               const pasta::Decl &decl,
                               mx::ReferenceRecord &record) {
  UNUSED(decl);
  auto child = stmt;
  auto parent = stmt;
  auto valid_parent = false;

  bool is_field = stmt.Kind() == pasta::StmtKind::kMemberExpr;
  assert((is_field || stmt.Kind() == pasta::StmtKind::kDeclRefExpr)
         && "Unexpected statement");
  assert(record.kind == mx::BuiltinReferenceKind::USES
         && "Reference record kind incorrectly assigned!");

  if (auto maybe_parent = em.ParentStmt(ast, child)) {
    parent = maybe_parent.value();
    valid_parent = true;
  }

  while (valid_parent){
    switch (parent.Kind()) {
      case pasta::StmtKind::kSwitchStmt:
        record.context_id = em.EntityId(parent);
        if (auto switch_ = pasta::SwitchStmt::From(parent);
        switch_ && switch_->Condition() == child) {
          record.kind = mx::BuiltinReferenceKind::CONDITIONS;
        }
        return;
      case pasta::StmtKind::kDoStmt:
        record.context_id = em.EntityId(child);
        if (auto do_ = pasta::DoStmt::From(parent);
        do_ && do_->Condition() == child) {
          record.kind = mx::BuiltinReferenceKind::CONDITIONS;
        }
        return;
      case pasta::StmtKind::kWhileStmt:
        record.context_id = em.EntityId(child);
        if (auto while_ = pasta::WhileStmt::From(parent);
        while_ && while_->Condition() == child) {
          record.kind = mx::BuiltinReferenceKind::CONDITIONS;
        }
        return;
      case pasta::StmtKind::kForStmt:
        record.context_id = em.EntityId(child);
        if (auto for_ = pasta::ForStmt::From(parent);
        for_ && for_->Condition() == child) {
          record.kind = mx::BuiltinReferenceKind::CONDITIONS;
        }
        return;
      case pasta::StmtKind::kIfStmt:
        record.context_id = em.EntityId(child);
        if (auto if_ = pasta::IfStmt::From(parent);
        if_ && if_->Condition() == child) {
          record.kind = mx::BuiltinReferenceKind::CONDITIONS;
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
        record.kind = mx::BuiltinReferenceKind::USES;
        return;

      case pasta::StmtKind::kUnaryOperator:
        if (auto uop = pasta::UnaryOperator::From(parent)) {
          switch (uop->Opcode()) {
            case pasta::UnaryOperatorKind::kAddressOf:
              record.context_id = em.EntityId(parent);
              record.kind = mx::BuiltinReferenceKind::TAKES_ADDRESS_OF;
              return;
            case pasta::UnaryOperatorKind::kDeref:
              record.context_id = em.EntityId(parent);
              record.kind = mx::BuiltinReferenceKind::DEREFERENCES;
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
              record.kind = mx::BuiltinReferenceKind::USES;
              return;
            }
          }
        }
        break;
      case pasta::StmtKind::kConditionalOperator:
        if (auto cond = pasta::ConditionalOperator::From(parent);
            cond && cond->Condition() == child) {
          record.context_id = em.EntityId(child);
          record.kind = mx::BuiltinReferenceKind::CONDITIONS;
          return;
        }
        break;
      case pasta::StmtKind::kMemberExpr:
        if (auto member = pasta::MemberExpr::From(parent);
            member && member->Base() == child && member->IsArrow()) {
          record.context_id = em.EntityId(parent);
          record.kind = mx::BuiltinReferenceKind::DEREFERENCES;
          return;
        }
        if (stmt.Kind() == pasta::StmtKind::kMemberExpr) {
          record.context_id = em.EntityId(child);
          record.kind = mx::BuiltinReferenceKind::USES;
          return;
        }
        break;
      case pasta::StmtKind::kArraySubscriptExpr:
        if (auto arr = pasta::ArraySubscriptExpr::From(parent)) {
          record.context_id = em.EntityId(parent);
          record.kind = mx::BuiltinReferenceKind::DEREFERENCES;
          return;
        }
        break;
      case pasta::StmtKind::kCallExpr:
        if (auto call = pasta::CallExpr::From(parent)) {
          if (call->Callee() == child) {
            record.context_id = em.EntityId(parent);
            record.kind = mx::BuiltinReferenceKind::DEREFERENCES;
            return;
          } else {
            if (auto dc = call->DirectCallee();
                !dc || !dc->Name().starts_with("__builtin_")) {
              record.context_id = em.EntityId(parent);
              record.kind = mx::BuiltinReferenceKind::CALL_ARGUMENTS;
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
            record.kind = mx::BuiltinReferenceKind::ASSIGNED_TO;
            // Note: Identify the reference kind but does not swap
            //       reference entity id with the referer id. Info
            //       browser will take care of this.
            return;
          }
        }
        record.kind = mx::BuiltinReferenceKind::ASSIGNED_TO;
        return;
      default: break;
    }

    if (auto maybe_parent = em.ParentStmt(ast, parent)) {
      child = parent;
      parent = maybe_parent.value();
      continue;
    }
    valid_parent = false;
  }

  record.kind = mx::BuiltinReferenceKind::USES;
  record.context_id = em.EntityId(stmt);
}

// Get the reference kind for types if referenced by a statement
static void TypeReferences(const pasta::AST &ast,
                           const EntityMapper &em,
                           const pasta::Stmt &stmt,
                           mx::ReferenceRecord &record) {
  auto valid_parent = true;
  auto parent = stmt;
  record.kind = mx::BuiltinReferenceKind::STATEMENT_USES;
  record.context_id = em.EntityId(parent);
  while (valid_parent) {
    if (pasta::CastExpr::From(parent)) {
      record.kind = mx::BuiltinReferenceKind::TYPE_CASTS;
      record.context_id = em.EntityId(parent);
    } else if (pasta::TypeTraitExpr::From(parent) ||
        pasta::UnaryExprOrTypeTraitExpr::From(parent)) {
      record.kind = mx::BuiltinReferenceKind::TYPE_TRAIT_USES;
      record.context_id = em.EntityId(parent);
    }

    if (auto maybe_next = em.ParentStmt(ast, parent)) {
      parent = maybe_next.value();
      continue;
    }
    valid_parent = false;
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
    record.kind = mx::BuiltinReferenceKind::USES;
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
