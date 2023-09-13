// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include <cassert>
#include <multiplier/Database.h>
#include <multiplier/Entities/MacroKind.h>
#include <multiplier/Types.h>
#include <pasta/AST/Macro.h>
#include <pasta/AST/Stmt.h>
#include <pasta/Util/File.h>
#include <unordered_set>

#include "EntityMapper.h"

namespace indexer {
namespace {

static mx::ReferenceRecord::Kind FunctionReferences(
    const pasta::AST &ast, EntityMapper &em, const pasta::Stmt &stmt,
    const pasta::FunctionDecl &func) {
  auto valid_parent = true;
  auto parent = stmt;
  while (valid_parent) {
    switch (parent.Kind()) {
      case pasta::StmtKind::kCallExpr:
        if (auto call = pasta::CallExpr::From(parent)) {
          if (call->DirectCallee() == func) {
            return mx::ReferenceRecord::Kind::Caller;
          }
        }
      default: break;
    }

    if (auto maybe_next = em.ParentStmt(ast, parent)) {
      parent = maybe_next.value();
      continue;
    }
    valid_parent = false;
  }

  return mx::ReferenceRecord::Kind::AddressOf;
}

static mx::ReferenceRecord::Kind VariableReferences(
    const pasta::AST&, EntityMapper&, const pasta::Decl&,
    const pasta::Decl &var) {

  if(auto vd = pasta::VarDecl::From(var)) {
    if (vd->Kind() == pasta::DeclKind::kParmVar) {
      return mx::ReferenceRecord::Kind::ParameterVariables;
    } else {
      if (vd->TSCSpec() != pasta::ThreadStorageClassSpecifier::kUnspecified) {
        return mx::ReferenceRecord::Kind::ThreadLocalVariables;
      } else if (vd->StorageDuration() == pasta::StorageDuration::kStatic) {
        return mx::ReferenceRecord::Kind::StaticLocalVariables;
      }
    }
  }
  return mx::ReferenceRecord::Kind::NoReferenceKind;
}

static mx::ReferenceRecord::Kind VariableReferences(
    const pasta::AST &ast, EntityMapper &em, const pasta::Stmt &stmt,
    const pasta::Decl&) {
  auto valid_parent = true;
  auto parent = stmt;
  while (valid_parent) {
    switch (parent.Kind()) {
      case pasta::StmtKind::kSwitchStmt:
        if (auto switch_ = pasta::SwitchStmt::From(parent);
        switch_ && switch_->Condition() == stmt) {
          return mx::ReferenceRecord::Kind::InfluencingCondition;
        }
        break;
      case pasta::StmtKind::kDoStmt:
        if (auto do_ = pasta::DoStmt::From(stmt);
        do_ && do_->Condition() == stmt) {
          return mx::ReferenceRecord::Kind::InfluencingCondition;
        }
        break;
      case pasta::StmtKind::kWhileStmt:
        if (auto while_ = pasta::WhileStmt::From(stmt);
        while_ && while_->Condition() == stmt) {
          return mx::ReferenceRecord::Kind::InfluencingCondition;
        }
        break;
      case pasta::StmtKind::kForStmt:
        if (auto for_ = pasta::ForStmt::From(stmt);
        for_ && for_->Condition() == stmt) {
          return mx::ReferenceRecord::Kind::InfluencingCondition;
        }
        break;
      case pasta::StmtKind::kIfStmt:
        if (auto if_ = pasta::IfStmt::From(stmt);
        if_ && if_->Condition() == stmt) {
          return mx::ReferenceRecord::Kind::InfluencingCondition;
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
        return mx::ReferenceRecord::Kind::GenericUses;

      case pasta::StmtKind::kUnaryOperator:
        if (auto uop = pasta::UnaryOperator::From(parent)) {
          switch (uop->Opcode()) {
            case pasta::UnaryOperatorKind::kAddressOf:
              return mx::ReferenceRecord::Kind::AddressOf;
            case pasta::UnaryOperatorKind::kDeref:
              return mx::ReferenceRecord::Kind::Dereferences;
            default: break;
          }
        }
        break;
      case pasta::StmtKind::kCompoundAssignOperator:
      case pasta::StmtKind::kBinaryOperator:
        if (auto bin = pasta::BinaryOperator::From(parent)) {
          if (bin->IsAssignmentOperation()) {
            if (bin->LHS() == stmt) {
              return mx::ReferenceRecord::Kind::AssignedTos;
            } else if (bin->RHS() == stmt) {
              return mx::ReferenceRecord::Kind::Assignments;
            }
          }
        }
        break;
      case pasta::StmtKind::kConditionalOperator:
        if (auto cond = pasta::ConditionalOperator::From(parent);
            cond && cond->Condition() == stmt) {
          return mx::ReferenceRecord::Kind::InfluencingCondition;
        }
        break;
      case pasta::StmtKind::kMemberExpr:
        if (auto member = pasta::MemberExpr::From(parent);
            member && member->Base() == stmt && member->IsArrow()) {
          return mx::ReferenceRecord::Kind::Dereferences;
        }
        break;
      case pasta::StmtKind::kArraySubscriptExpr:
        if (auto arr = pasta::ArraySubscriptExpr::From(parent)) {
          return mx::ReferenceRecord::Kind::Dereferences;
        }
        break;
      case pasta::StmtKind::kCallExpr:
        if (auto call = pasta::CallExpr::From(parent)) {
          if (call->Callee() == stmt) {
            return mx::ReferenceRecord::Kind::Dereferences;
          } else {
            if (auto dc = call->DirectCallee();
                !dc || !dc->Name().starts_with("__builtin_")) {
              return mx::ReferenceRecord::Kind::CallArguments;
            }
          }
        }
        break;
      case pasta::StmtKind::kDeclStmt:
      case pasta::StmtKind::kDesignatedInitExpr:
      case pasta::StmtKind::kDesignatedInitUpdateExpr:
        for (auto init : parent.Children()) {
          if (init == stmt) {
            return mx::ReferenceRecord::Kind::Assignments;
          }
        }
        return mx::ReferenceRecord::Kind::AssignedTos;
      default: break;
    }

    if (auto maybe_next = em.ParentStmt(ast, parent)) {
      parent = maybe_next.value();
      continue;
    }
    valid_parent = false;
  }

  return mx::ReferenceRecord::Kind::GenericUses;
}

// Get the reference kind for types if referenced by a statement
static mx::ReferenceRecord::Kind TypeReferences(
    const pasta::AST &ast, EntityMapper &em, const pasta::Stmt &stmt) {
  auto valid_parent = true;
  auto parent = stmt;
  while (valid_parent) {
    if (pasta::CastExpr::From(parent)) {
      return mx::ReferenceRecord::Kind::TypeCasts;
    } else if (pasta::TypeTraitExpr::From(parent) ||
        pasta::UnaryExprOrTypeTraitExpr::From(parent)) {
      return mx::ReferenceRecord::Kind::TypeTraitUses;
    }

    if (auto maybe_next = em.ParentStmt(ast, parent)) {
      parent = maybe_next.value();
      continue;
    }
    valid_parent = false;
  }

  return mx::ReferenceRecord::Kind::StatementUses;
}

} // namespace

mx::ReferenceRecord::Kind DeclReferenceKind(
    const pasta::AST &ast, EntityMapper &em,
    const pasta::Decl &decl, const pasta::Decl &ref) {
  if (auto vd = pasta::VarDecl::From(ref)) {
    return VariableReferences(ast, em, decl, ref);
  } else if (auto fd = pasta::FunctionDecl::From(ref)) {
    return mx::ReferenceRecord::Kind::Functions;
  } else if (auto td = pasta::TypeDecl::From(ref)) {
    return mx::ReferenceRecord::Kind::DeclarationUses;
  }
  return mx::ReferenceRecord::Kind::NoReferenceKind;
}

mx::ReferenceRecord::Kind DeclReferenceKind(
    const pasta::AST &ast, EntityMapper &em,
    const pasta::Stmt &stmt, const pasta::Decl &ref) {
  if (auto func = pasta::FunctionDecl::From(ref)) {
    return FunctionReferences(ast, em, stmt, func.value());
  } else if (auto var = pasta::VarDecl::From(ref)) {
    return VariableReferences(ast, em, stmt, ref);
  } else if (auto field = pasta::FieldDecl::From(ref)) {
    return VariableReferences(ast, em, stmt, ref);
  } else if (auto enumerator = pasta::EnumConstantDecl::From(ref)) {
    return VariableReferences(ast, em, stmt, ref);
  } else if (auto enum_ = pasta::EnumDecl::From(ref)) {
    return mx::ReferenceRecord::Kind::Enumerations;
  }

  if (auto type = pasta::TypeDecl::From(ref)) {
    return TypeReferences(ast, em, stmt);
  }

  return mx::ReferenceRecord::Kind::NoReferenceKind;
}

mx::ReferenceRecord::Kind DeclReferenceKind(
    const pasta::AST&, EntityMapper&, const pasta::Designator&,
    const pasta::Decl&) {
  return mx::ReferenceRecord::Kind::AddressOf;
}

} // namespace indexer
