// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <map>
#include <multiplier/AST.capnp.h>
#include <multiplier/Types.h>
#include <pasta/AST/Decl.h>
#include <pasta/AST/Forward.h>
#include <pasta/AST/Stmt.h>
#include <pasta/AST/Token.h>
#include <unordered_map>
#include <unordered_set>

namespace indexer {

class EntityVisitor : protected pasta::DeclVisitor,
                      protected pasta::StmtVisitor {
 private:
  bool EnterDecl(const pasta::Decl &decl);
  bool EnterStmt(const pasta::Stmt &stmt);
  bool EnterTagDecl(const pasta::TagDecl &decl);
  bool EnterRecordDecl(const pasta::RecordDecl &decl);
  bool EnterCXXRecordDecl(const pasta::CXXRecordDecl &decl);
  bool EnterDeclaratorDecl(const pasta::DeclaratorDecl &decl);
  bool EnterVarDecl(const pasta::VarDecl &decl);


 private:
  void VisitDeclContext(const pasta::DeclContext &dc);
  void VisitTranslationUnitDecl(const pasta::TranslationUnitDecl &decl) final;
  void VisitNamespaceDecl(const pasta::NamespaceDecl &decl) final;
  void VisitExternCContextDecl(const pasta::ExternCContextDecl &decl) final;
  void VisitLinkageSpecDecl(const pasta::LinkageSpecDecl &decl) final;
  void VisitClassTemplatePartialSpecializationDecl(
      const pasta::ClassTemplatePartialSpecializationDecl &) final;
  void VisitVarTemplatePartialSpecializationDecl(
      const pasta::VarTemplatePartialSpecializationDecl &) final;
  void VisitTemplateDecl(const pasta::TemplateDecl &) final;
  void VisitFriendTemplateDecl(const pasta::FriendTemplateDecl &) final;
  void VisitClassTemplateDecl(const pasta::ClassTemplateDecl &) final;
  void VisitVarTemplateDecl(const pasta::VarTemplateDecl &) final;
  void VisitFunctionTemplateDecl(const pasta::FunctionTemplateDecl &) final;
  void VisitFriendDecl(const pasta::FriendDecl &decl) final;
  void VisitVarDecl(const pasta::VarDecl &decl) final;
  void VisitParmVarDecl(const pasta::ParmVarDecl &decl) final;
  void VisitFunctionDecl(const pasta::FunctionDecl &decl) final;
  void VisitFieldDecl(const pasta::FieldDecl &decl) final;
  void VisitRecordDecl(const pasta::RecordDecl &decl) final;
  void VisitEnumConstantDecl(const pasta::EnumConstantDecl &decl) final;
  void VisitEnumDecl(const pasta::EnumDecl &decl) final;
  void VisitGCCAsmStmt(const pasta::GCCAsmStmt &stmt) final;
  void VisitMSAsmStmt(const pasta::MSAsmStmt &stmt) final;
  void VisitBreakStmt(const pasta::BreakStmt &stmt) final;
  void VisitCompoundStmt(const pasta::CompoundStmt &stmt) final;
  void VisitTypedefNameDecl(const pasta::TypedefNameDecl &decl) final;
  void VisitDeclStmt(const pasta::DeclStmt &stmt) final;
  void VisitConceptSpecializationExpr(const pasta::ConceptSpecializationExpr &stmt) final;
  void VisitSizeOfPackExpr(const pasta::SizeOfPackExpr &stmt) final;
  void VisitVarTemplateSpecializationDecl(const pasta::VarTemplateSpecializationDecl &decl) final;
  void VisitCXXRecordDecl(const pasta::CXXRecordDecl &decl) final;
  void VisitTagDecl(const pasta::TagDecl &decl) final;
  void VisitClassTemplateSpecializationDecl(const pasta::ClassTemplateSpecializationDecl &decl) final;
  void VisitDeclaratorDecl(const pasta::DeclaratorDecl &decl) final;
  void VisitLambdaExpr(const pasta::LambdaExpr &stmt) final;
  void VisitDecl(const pasta::Decl &decl) final;
  void VisitStmt(const pasta::Stmt &stmt) final;

 protected:
  using pasta::DeclVisitor::Accept;
  using pasta::StmtVisitor::Accept;

 public:
  virtual ~EntityVisitor(void);
  virtual bool Enter(const pasta::Decl &entity) = 0;
  virtual bool Enter(const pasta::Stmt &entity) = 0;
  virtual void Enter(const pasta::Decl &entity,
                     std::vector<pasta::TemplateArgument>) = 0;
  virtual void Enter(const pasta::Stmt &entity,
                     std::vector<pasta::TemplateArgument>) = 0;
  virtual void Enter(const pasta::Decl &entity,
                     std::vector<pasta::CXXBaseSpecifier>) = 0;
  virtual void Enter(const pasta::Decl &entity,
                     std::vector<pasta::TemplateParameterList>) = 0;
  virtual void Enter(const pasta::Decl &entity,
                     const pasta::TemplateParameterList &) = 0;
  virtual void Enter(const pasta::Stmt &entity,
                     const pasta::TemplateParameterList &) = 0;
};

}  // namespace indexer
