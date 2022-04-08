// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "Visitor.h"

#include <cassert>

namespace indexer {

void EntityVisitor::VisitDeclContext(const pasta::DeclContext &dc) {
  for (const auto &decl : dc.AlreadyLoadedDeclarations()) {
    this->DeclVisitor::Accept(decl);
  }
}

void EntityVisitor::VisitTranslationUnitDecl(
    const pasta::TranslationUnitDecl &decl) {
  assert(false);
  VisitDeclContext(decl);
}

void EntityVisitor::VisitNamespaceDecl(
    const pasta::NamespaceDecl &decl) {
  assert(false);
  VisitDeclContext(decl);
}

void EntityVisitor::VisitExternCContextDecl(
    const pasta::ExternCContextDecl &decl) {
  assert(false);
  VisitDeclContext(decl);
}

void EntityVisitor::VisitLinkageSpecDecl(
    const pasta::LinkageSpecDecl &decl) {
  if (!decl.HasBraces()) {
    VisitDeclContext(decl);
  }
}

void EntityVisitor::VisitClassTemplatePartialSpecializationDecl(
    const pasta::ClassTemplatePartialSpecializationDecl &) {}

void EntityVisitor::VisitVarTemplatePartialSpecializationDecl(
    const pasta::VarTemplatePartialSpecializationDecl &) {}

void EntityVisitor::VisitTemplateDecl(const pasta::TemplateDecl &) {}

void EntityVisitor::VisitFriendTemplateDecl(
    const pasta::FriendTemplateDecl &) {}

void EntityVisitor::VisitClassTemplateDecl(
    const pasta::ClassTemplateDecl &) {}

void EntityVisitor::VisitVarTemplateDecl(const pasta::VarTemplateDecl &) {}

void EntityVisitor::VisitFunctionTemplateDecl(
    const pasta::FunctionTemplateDecl &) {}

void EntityVisitor::VisitFriendDecl(const pasta::FriendDecl &decl) {
  if (Enter(decl)) {
    Enter(decl, decl.FriendTypeTemplateParameterLists());
  }
}

bool EntityVisitor::EnterVarDecl(const pasta::VarDecl &decl) {
  if (EnterDeclaratorDecl(decl)) {
//    Enter(decl, decl.TemplateParameterLists());  // TODO(pag): Double counted.
    if (auto init_expr = decl.Initializer()) {
      this->StmtVisitor::Accept(*init_expr);
    }
    return true;
  } else {
    return false;
  }
}

void EntityVisitor::VisitVarDecl(const pasta::VarDecl &decl) {
  EnterVarDecl(decl);
}

void EntityVisitor::VisitParmVarDecl(const pasta::ParmVarDecl &decl) {
  if (EnterVarDecl(decl)) {
//    Enter(decl, decl.TemplateParameterLists());  // TODO(pag): Double counted.
    if (!decl.HasUninstantiatedDefaultArgument() &&
        !decl.HasUnparsedDefaultArgument()) {
      if (auto init_expr = decl.DefaultArgument()) {
        this->StmtVisitor::Accept(*init_expr);
      }
    }
  }
}

void EntityVisitor::VisitFunctionDecl(const pasta::FunctionDecl &decl) {
  if (EnterDeclaratorDecl(decl)) {
//    Enter(decl, decl.TemplateParameterLists());  // TODO(pag): Double counted.
    VisitDeclContext(decl);
    for (pasta::ParmVarDecl param : decl.Parameters()) {
      this->DeclVisitor::Accept(param);
    }
    if (auto body = decl.Body()) {
      this->StmtVisitor::Accept(body.value());
    }
  }
}

void EntityVisitor::VisitFieldDecl(const pasta::FieldDecl &decl) {
  if (EnterDeclaratorDecl(decl)) {
//    Enter(decl, decl.TemplateParameterLists());  // TODO(pag): Double counted.
    if (auto bit_width = decl.BitWidth()) {
      this->StmtVisitor::Accept(*bit_width);
    }
    if (auto init = decl.InClassInitializer()) {
      this->StmtVisitor::Accept(*init);
    }
  }
}

// Structs, unions, etc.
void EntityVisitor::VisitRecordDecl(const pasta::RecordDecl &decl) {
  EnterRecordDecl(decl);
}

void EntityVisitor::VisitEnumConstantDecl(const pasta::EnumConstantDecl &decl) {
  if (Enter(decl)) {
    if (auto init = decl.InitializerExpression()) {
      this->StmtVisitor::Accept(*init);
    }
  }
}

// Enumerators.
void EntityVisitor::VisitEnumDecl(const pasta::EnumDecl &decl) {
  if (EnterTagDecl(decl)) {
    for (pasta::EnumConstantDecl enumerator : decl.Enumerators()) {
      this->DeclVisitor::Accept(enumerator);
    }
  }
}

void EntityVisitor::VisitGCCAsmStmt(const pasta::GCCAsmStmt &stmt) {
  if (EnterStmt(stmt)) {
    for (auto child : stmt.InputConstraintLiterals()) {
      this->StmtVisitor::Accept(child);
    }
    for (auto child : stmt.InputExpressions()) {
      this->StmtVisitor::Accept(child);
    }
    for (auto child : stmt.OutputConstraintLiterals()) {
      this->StmtVisitor::Accept(child);
    }
    for (auto child : stmt.OutputExpressions()) {
      this->StmtVisitor::Accept(child);
    }
  }
}

void EntityVisitor::VisitMSAsmStmt(const pasta::MSAsmStmt &stmt) {
  if (EnterStmt(stmt)) {
    for (auto child : stmt.AllExpressions()) {
      this->StmtVisitor::Accept(child);
    }
    for (auto child : stmt.InputExpressions()) {
      this->StmtVisitor::Accept(child);
    }
  }
}

void EntityVisitor::VisitBreakStmt(const pasta::BreakStmt &stmt) {
  EnterStmt(stmt);
}

void EntityVisitor::VisitCompoundStmt(const pasta::CompoundStmt &stmt) {
  EnterStmt(stmt);
}

void EntityVisitor::VisitTypedefNameDecl(const pasta::TypedefNameDecl &decl) {
  if (Enter(decl)) {
    if (auto tag = decl.AnonymousDeclarationWithTypedefName()) {
      this->DeclVisitor::Accept(*tag);
    }
  }
}

void EntityVisitor::VisitDeclStmt(const pasta::DeclStmt &stmt) {
  if (EnterStmt(stmt)) {
    for (auto child : stmt.Declarations()) {
      this->DeclVisitor::Accept(child);
    }
  }
}

void EntityVisitor::VisitConceptSpecializationExpr(
    const pasta::ConceptSpecializationExpr &stmt) {
  if (EnterStmt(stmt)) {
    Enter(stmt, stmt.TemplateArguments());
  }
}

void EntityVisitor::VisitSizeOfPackExpr(const pasta::SizeOfPackExpr &stmt) {
  if (EnterStmt(stmt)) {
    if (auto args = stmt.PartialArguments()) {
      Enter(stmt, std::move(*args));
    }
  }
}

void EntityVisitor::VisitVarTemplateSpecializationDecl(
    const pasta::VarTemplateSpecializationDecl &decl) {
  if (EnterVarDecl(decl)) {
    //    Enter(decl, decl.TemplateParameterLists());  // TODO(pag): Double counted.
    Enter(decl, decl.TemplateArguments());
    Enter(decl, decl.TemplateInstantiationArguments());
  }
}

void EntityVisitor::VisitCXXRecordDecl(const pasta::CXXRecordDecl &decl) {
  EnterCXXRecordDecl(decl);
}

bool EntityVisitor::EnterTagDecl(const pasta::TagDecl &decl) {
  if (EnterDecl(decl)) {
    Enter(decl, decl.TemplateParameterLists());
    VisitDeclContext(decl);
    return true;
  } else {
    return false;
  }
}

bool EntityVisitor::EnterRecordDecl(const pasta::RecordDecl &decl) {
  if (EnterTagDecl(decl)) {
    for (pasta::FieldDecl field : decl.Fields()) {
      this->DeclVisitor::Accept(field);
    }
    return true;
  } else {
    return false;
  }
}

bool EntityVisitor::EnterCXXRecordDecl(const pasta::CXXRecordDecl &decl) {
  if (EnterRecordDecl(decl)) {
    if (auto bases = decl.Bases()) {
      Enter(decl, std::move(bases.value()));
    }
    if (auto vbases = decl.VirtualBases()) {
      Enter(decl, std::move(vbases.value()));
    }
    if (auto ls = decl.GenericLambdaTemplateParameterList()) {
      Enter(decl, std::move(*ls));
    }
    return true;
  } else {
    return false;
  }
}

void EntityVisitor::VisitTagDecl(const pasta::TagDecl &decl) {
  EnterTagDecl(decl);
}

void EntityVisitor::VisitClassTemplateSpecializationDecl(
    const pasta::ClassTemplateSpecializationDecl &decl) {
  if (EnterCXXRecordDecl(decl)) {
    Enter(decl, decl.TemplateArguments());
    Enter(decl, decl.TemplateInstantiationArguments());
  }
}

bool EntityVisitor::EnterDeclaratorDecl(const pasta::DeclaratorDecl &decl) {
  if (EnterDecl(decl)) {
    Enter(decl, decl.TemplateParameterLists());
    return true;
  } else {
    return false;
  }
}

void EntityVisitor::VisitDeclaratorDecl(const pasta::DeclaratorDecl &decl) {
  EnterDeclaratorDecl(decl);
}

void EntityVisitor::VisitLambdaExpr(const pasta::LambdaExpr &stmt) {
  if (EnterStmt(stmt)) {
    if (auto ls = stmt.TemplateParameterList()) {
      Enter(stmt, std::move(ls.value()));
    }
  }
}

bool EntityVisitor::EnterDecl(const pasta::Decl &decl) {
  if (Enter(decl)) {
    if (auto ls = decl.DescribedTemplateParameters()) {
      Enter(decl, std::move(ls.value()));
    }
    return true;
  } else {
    return false;
  }
}
bool EntityVisitor::EnterStmt(const pasta::Stmt &stmt) {
  if (Enter(stmt)) {
    for (auto child : stmt.Children()) {
      this->StmtVisitor::Accept(child);
    }
    return true;
  } else {
    return false;
  }
}

// Backups.
void EntityVisitor::VisitDecl(const pasta::Decl &decl) {
  EnterDecl(decl);
}

void EntityVisitor::VisitStmt(const pasta::Stmt &stmt) {
  EnterStmt(stmt);
}

EntityVisitor::~EntityVisitor(void) {}

}  // namespace indexer
