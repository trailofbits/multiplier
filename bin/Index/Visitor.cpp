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
  assert(false);
  VisitDeclContext(decl);
}

void EntityVisitor::VisitClassTemplatePartialSpecializationDecl(
    const pasta::ClassTemplatePartialSpecializationDecl &) {}

void EntityVisitor::VisitVarTemplatePartialSpecializationDecl(
    const pasta::VarTemplatePartialSpecializationDecl &) {}

void EntityVisitor::VisitClassTemplateDecl(
    const pasta::ClassTemplateDecl &) {}

void EntityVisitor::VisitVarTemplateDecl(const pasta::VarTemplateDecl &) {}

void EntityVisitor::VisitFunctionTemplateDecl(
    const pasta::FunctionTemplateDecl &) {}

void EntityVisitor::VisitVarDecl(const pasta::VarDecl &decl) {
  if (Enter(decl)) {
    if (auto init_expr = decl.Initializer()) {
      this->StmtVisitor::Accept(*init_expr);
    }
  }
}

void EntityVisitor::VisitParmVarDecl(const pasta::ParmVarDecl &decl) {
  if (Enter(decl)) {
    if (!decl.HasUninstantiatedDefaultArgument() &&
        !decl.HasUnparsedDefaultArgument()) {
      if (auto init_expr = decl.DefaultArgument()) {
        this->StmtVisitor::Accept(*init_expr);
      }
    }
  }
}

void EntityVisitor::VisitFunctionDecl(const pasta::FunctionDecl &decl) {
  if (Enter(decl)) {
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
  if (Enter(decl)) {
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
  if (Enter(decl)) {
    VisitDeclContext(decl);
    for (pasta::FieldDecl field : decl.Fields()) {
      this->DeclVisitor::Accept(field);
    }
  }
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
  if (Enter(decl)) {
    VisitDeclContext(decl);
    for (pasta::EnumConstantDecl enumerator : decl.Enumerators()) {
      this->DeclVisitor::Accept(enumerator);
    }
  }
}

void EntityVisitor::VisitGCCAsmStmt(const pasta::GCCAsmStmt &stmt) {
  if (Enter(stmt)) {
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
    for (auto child : stmt.Children()) {
      this->StmtVisitor::Accept(child);
    }
  }
}

void EntityVisitor::VisitMSAsmStmt(const pasta::MSAsmStmt &stmt) {
  if (Enter(stmt)) {
    for (auto child : stmt.AllExpressions()) {
      this->StmtVisitor::Accept(child);
    }
    for (auto child : stmt.InputExpressions()) {
      this->StmtVisitor::Accept(child);
    }
  }
}

void EntityVisitor::VisitBreakStmt(const pasta::BreakStmt &stmt) {
  if (Enter(stmt)) {
    for (auto child : stmt.Children()) {
      this->StmtVisitor::Accept(child);
    }
  }
}

void EntityVisitor::VisitCompoundStmt(const pasta::CompoundStmt &stmt) {
  if (Enter(stmt)) {
    for (pasta::Stmt child : stmt.Children()) {
      this->StmtVisitor::Accept(child);
    }
  }
}

void EntityVisitor::VisitTypedefNameDecl(const pasta::TypedefNameDecl &decl) {
  if (Enter(decl)) {
    if (auto tag = decl.AnonymousDeclarationWithTypedefName()) {
      this->DeclVisitor::Accept(*tag);
    }
  }
}


void EntityVisitor::VisitDeclStmt(const pasta::DeclStmt &stmt) {
  if (Enter(stmt)) {
    for (auto child : stmt.Children()) {
      this->StmtVisitor::Accept(child);
    }
    for (auto child : stmt.Declarations()) {
      this->DeclVisitor::Accept(child);
    }
  }
}

// Backups.
void EntityVisitor::VisitDecl(const pasta::Decl &decl) {
  (void) Enter(decl);
}

void EntityVisitor::VisitStmt(const pasta::Stmt &stmt) {
  if (Enter(stmt)) {
    for (auto child : stmt.Children()) {
      this->StmtVisitor::Accept(child);
    }
  }
}

EntityVisitor::~EntityVisitor(void) {}

}  // namespace indexer
