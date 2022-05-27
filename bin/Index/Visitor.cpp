// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "Visitor.h"

#include <cassert>

namespace indexer {

void EntityVisitor::VisitDeclContext(const pasta::DeclContext &dc) {
  for (const pasta::Decl &decl : dc.AlreadyLoadedDeclarations()) {
    Accept(decl);
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

bool EntityVisitor::EnterVarDecl(const pasta::VarDecl &decl) {
  if (EnterDeclaratorDecl(decl)) {
    if (auto init_expr = decl.Initializer()) {
      Accept(*init_expr);
    }
    return true;
  } else {
    return false;
  }
}

void EntityVisitor::VisitFriendDecl(const pasta::FriendDecl &decl) {
  if (Enter(decl)) {
    for (pasta::TemplateParameterList ls :
             decl.FriendTypeTemplateParameterLists()) {
      for (const pasta::NamedDecl &param_decl : ls.Parameters()) {
        Accept(param_decl);
      }
    }
  }
}

void EntityVisitor::VisitVarDecl(const pasta::VarDecl &decl) {
  EnterVarDecl(decl);
}

void EntityVisitor::VisitParmVarDecl(const pasta::ParmVarDecl &decl) {
  if (EnterVarDecl(decl)) {
    if (!decl.HasUninstantiatedDefaultArgument() &&
        !decl.HasUnparsedDefaultArgument()) {
      if (auto init_expr = decl.DefaultArgument()) {
        Accept(*init_expr);
      }
    }
  }
}

void EntityVisitor::VisitFunctionDecl(const pasta::FunctionDecl &decl) {
  if (EnterDeclaratorDecl(decl)) {
    VisitDeclContext(decl);
    for (const pasta::ParmVarDecl &param : decl.Parameters()) {
      Accept(param);
    }
    if (auto body = decl.Body()) {
      Accept(body.value());
    }
  }
}

void EntityVisitor::VisitFieldDecl(const pasta::FieldDecl &decl) {
  if (EnterDeclaratorDecl(decl)) {
    if (auto bit_width = decl.BitWidth()) {
      Accept(*bit_width);
    }
    if (auto init = decl.InClassInitializer()) {
      Accept(*init);
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
      Accept(*init);
    }
  }
}

// Enumerators.
void EntityVisitor::VisitEnumDecl(const pasta::EnumDecl &decl) {
  if (EnterTagDecl(decl)) {
    for (const pasta::EnumConstantDecl &enumerator : decl.Enumerators()) {
      Accept(enumerator);
    }
  }
}

void EntityVisitor::VisitTypedefNameDecl(const pasta::TypedefNameDecl &decl) {
  if (Enter(decl)) {
    if (auto tag = decl.AnonymousDeclarationWithTypedefName()) {
      Accept(*tag);
    }
  }
}

void EntityVisitor::VisitDeclStmt(const pasta::DeclStmt &stmt) {
  if (EnterStmt(stmt)) {
    for (const pasta::Decl &child : stmt.Declarations()) {
      Accept(child);
    }
  }
}

void EntityVisitor::VisitConceptSpecializationExpr(
    const pasta::ConceptSpecializationExpr &stmt) {
  if (EnterStmt(stmt)) {
    for (const pasta::TemplateArgument &arg : stmt.TemplateArguments()) {
      if (auto arg_decl = arg.AsDeclaration()) {
        Accept(*arg_decl);
      }
    }
  }
}

void EntityVisitor::VisitSizeOfPackExpr(const pasta::SizeOfPackExpr &stmt) {
  if (EnterStmt(stmt)) {
    if (auto args = stmt.PartialArguments()) {
      for (const pasta::TemplateArgument &arg : *args) {
        if (auto arg_decl = arg.AsDeclaration()) {
          Accept(*arg_decl);
        }
      }
    }
  }
}

void EntityVisitor::VisitVarTemplateSpecializationDecl(
    const pasta::VarTemplateSpecializationDecl &decl) {
  if (EnterVarDecl(decl)) {
    // TODO(pag): Are these lexically enclosed in the fragment?
    for (const pasta::TemplateArgument &arg : decl.TemplateArguments()) {
      if (auto arg_decl = arg.AsDeclaration()) {
        Accept(*arg_decl);
      }
    }

    for (const pasta::TemplateArgument &arg :
             decl.TemplateInstantiationArguments()) {
      if (auto arg_decl = arg.AsDeclaration()) {
        Accept(*arg_decl);
      }
    }
  }
}

void EntityVisitor::VisitCXXRecordDecl(const pasta::CXXRecordDecl &decl) {
  EnterCXXRecordDecl(decl);
}

bool EntityVisitor::EnterTagDecl(const pasta::TagDecl &decl) {
  if (EnterDecl(decl)) {
    for (const pasta::TemplateParameterList &ls :
             decl.TemplateParameterLists()) {
      for (const pasta::NamedDecl &param_decl : ls.Parameters()) {
        Accept(param_decl);
      }
    }
    VisitDeclContext(decl);
    return true;
  } else {
    return false;
  }
}

bool EntityVisitor::EnterRecordDecl(const pasta::RecordDecl &decl) {
  if (EnterTagDecl(decl)) {
    for (const pasta::FieldDecl &field : decl.Fields()) {
      Accept(field);
    }
    return true;
  } else {
    return false;
  }
}

bool EntityVisitor::EnterCXXRecordDecl(const pasta::CXXRecordDecl &decl) {
  if (EnterRecordDecl(decl)) {
    // NOTE(pag): Don't need to enter the bases; they're likely top-level
    //            declarations.
//    if (auto bases = decl.Bases()) {
//      for (pasta::CXXBaseSpecifier spec : *bases) {
//
//      }
//    }
//    if (auto vbases = decl.VirtualBases()) {
//      for (pasta::CXXBaseSpecifier spec : *bases) {
//
//      }
//    }
    if (auto ls = decl.GenericLambdaTemplateParameterList()) {
      for (const pasta::NamedDecl &param_decl : ls->Parameters()) {
        Accept(param_decl);
      }
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

    // TODO(pag): Are these lexically enclosed in the fragment?
    for (const pasta::TemplateArgument &arg : decl.TemplateArguments()) {
      if (auto arg_decl = arg.AsDeclaration()) {
        Accept(*arg_decl);
      }
    }

    for (const pasta::TemplateArgument &arg :
             decl.TemplateInstantiationArguments()) {
      if (auto arg_decl = arg.AsDeclaration()) {
        Accept(*arg_decl);
      }
    }
  }
}

bool EntityVisitor::EnterDeclaratorDecl(const pasta::DeclaratorDecl &decl) {
  if (EnterDecl(decl)) {
    for (const pasta::TemplateParameterList &ls : decl.TemplateParameterLists()) {
      for (const pasta::NamedDecl &param_decl : ls.Parameters()) {
        Accept(param_decl);
      }
    }
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
      for (const pasta::NamedDecl &param_decl : ls->Parameters()) {
        Accept(param_decl);
      }
    }
  }
}

void EntityVisitor::VisitInitListExpr(const pasta::InitListExpr &stmt) {
  if (EnterStmt(stmt)) {
    if (auto sf = stmt.SyntacticForm()) {
      Accept(sf.value());
    }
    if (auto filler = stmt.ArrayFiller()) {
      Accept(filler.value());
    }
  }
}

void EntityVisitor::VisitGCCAsmStmt(const pasta::GCCAsmStmt &stmt) {
  if (EnterStmt(stmt)) {
    Accept(stmt.AssemblyString());
    for (auto input : stmt.InputConstraintLiterals()) {
      Accept(input);
    }
    for (auto output : stmt.OutputConstraintLiterals()) {
      Accept(output);
    }
    for (auto clobber : stmt.ClobberStringLiterals()) {
      Accept(clobber);
    }
    for (auto label : stmt.LabelExpressions()) {
      Accept(label);
    }
  }
}

bool EntityVisitor::EnterDecl(const pasta::Decl &decl) {
  if (Enter(decl)) {
    if (auto ls = decl.DescribedTemplateParameters()) {
      for (const pasta::NamedDecl &param_decl : ls->Parameters()) {
        Accept(param_decl);
      }
    }
    return true;
  } else {
    return false;
  }
}

bool EntityVisitor::EnterStmt(const pasta::Stmt &stmt) {
  if (Enter(stmt)) {
    for (const pasta::Stmt &child : stmt.Children()) {
      Accept(child);
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

void EntityVisitor::Accept(const pasta::Decl &entity) {
  this->DeclVisitor::Accept(entity);
}

void EntityVisitor::Accept(const pasta::Stmt &entity) {
  this->StmtVisitor::Accept(entity);
}

EntityVisitor::~EntityVisitor(void) {}

}  // namespace indexer
