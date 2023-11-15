// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <map>
#include <multiplier/AST.capnp.h>
#include <multiplier/Types.h>
#include <pasta/AST/Attr.h>
#include <pasta/AST/Decl.h>
#include <pasta/AST/Forward.h>
#include <pasta/AST/Stmt.h>
#include <pasta/AST/Token.h>
#include <pasta/AST/Type.h>
#include <unordered_map>
#include <unordered_set>

namespace indexer {

// Recursively descends an AST, visiting declarations and statements. We focus
// one declarations and statements here because they support inter-fragment
// referencing.
class EntityVisitor : protected pasta::DeclVisitor,
                      protected pasta::StmtVisitor,
                      protected pasta::TypeVisitor,
                      protected pasta::AttrVisitor {
 public:
  bool EnterDecl(const pasta::Decl &decl);
  bool EnterStmt(const pasta::Stmt &stmt);
  bool EnterType(const pasta::Type &type);
  bool EnterAttr(const pasta::Attr &attr);
 
  bool EnterTagDecl(const pasta::TagDecl &decl);
  bool EnterRecordDecl(const pasta::RecordDecl &decl);
  bool EnterCXXRecordDecl(const pasta::CXXRecordDecl &decl);
  bool EnterValueDecl(const pasta::ValueDecl &decl);
  bool EnterDeclaratorDecl(const pasta::DeclaratorDecl &decl);
  bool EnterVarDecl(const pasta::VarDecl &decl);
  bool EnterFunctionDecl(const pasta::FunctionDecl &decl);

 protected:
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
  void VisitNonTypeTemplateParmDecl(const pasta::NonTypeTemplateParmDecl &decl) final;
  void VisitFunctionDecl(const pasta::FunctionDecl &decl) final;
  void VisitFieldDecl(const pasta::FieldDecl &decl) final;
  void VisitRecordDecl(const pasta::RecordDecl &decl) final;
  void VisitEnumConstantDecl(const pasta::EnumConstantDecl &decl) final;
  void VisitEnumDecl(const pasta::EnumDecl &decl) final;
  void VisitTypedefNameDecl(const pasta::TypedefNameDecl &decl) final;
  void VisitDeclStmt(const pasta::DeclStmt &stmt) final;
  void VisitConceptSpecializationExpr(const pasta::ConceptSpecializationExpr &stmt) final;
  void VisitSizeOfPackExpr(const pasta::SizeOfPackExpr &stmt) final;
  void VisitVarTemplateSpecializationDecl(const pasta::VarTemplateSpecializationDecl &decl) final;
  void VisitCXXRecordDecl(const pasta::CXXRecordDecl &decl) final;
  void VisitCXXDestructorDecl(const pasta::CXXDestructorDecl &decl) final;
  void VisitTagDecl(const pasta::TagDecl &decl) final;
  void VisitClassTemplateSpecializationDecl(const pasta::ClassTemplateSpecializationDecl &decl) final;
  void VisitDeclaratorDecl(const pasta::DeclaratorDecl &decl) final;
  void VisitStaticAssertDecl(const pasta::StaticAssertDecl &decl) final;
  void VisitFileScopeAsmDecl(const pasta::FileScopeAsmDecl &decl) final;
  void VisitLambdaExpr(const pasta::LambdaExpr &stmt) final;
  void VisitInitListExpr(const pasta::InitListExpr &stmt) override;
  void VisitGCCAsmStmt(const pasta::GCCAsmStmt &stmt) final;
  void VisitDesignatedInitExpr(const pasta::DesignatedInitExpr &stmt) final;
  void VisitTypeOfExprType(const pasta::TypeOfExprType &type) final;
  void VisitDecltypeType(const pasta::DecltypeType &type) final;
  void VisitTypeOfType(const pasta::TypeOfType &type) final;
  void VisitDependentAddressSpaceType(const pasta::DependentAddressSpaceType &type) final;
  void VisitDependentBitIntType(const pasta::DependentBitIntType &type) final;
  void VisitDependentSizedArrayType(const pasta::DependentSizedArrayType &type) final;
  void VisitDependentSizedExtVectorType(const pasta::DependentSizedExtVectorType &type) final;
  void VisitDependentSizedMatrixType(const pasta::DependentSizedMatrixType &type) final;
  void VisitDependentVectorType(const pasta::DependentVectorType &type) final;
  void VisitVariableArrayType(const pasta::VariableArrayType &type) final;
  void VisitFunctionProtoType(const pasta::FunctionProtoType &type) final;
  void VisitCXXNewExpr(const pasta::CXXNewExpr &expr) final;
  void VisitCXXTypeidExpr(const pasta::CXXTypeidExpr &expr) final;
  void VisitCXXUuidofExpr(const pasta::CXXUuidofExpr &expr) final;
  void VisitAlignedAttr(const pasta::AlignedAttr &attr) final;
  void VisitDecl(const pasta::Decl &decl) final;
  void VisitStmt(const pasta::Stmt &stmt) final;
  void VisitType(const pasta::Type &type) final;
  void VisitAttr(const pasta::Attr &attr) final;

 protected:
  virtual bool Enter(const pasta::Attr &entity) = 0;
  virtual bool Enter(const pasta::Decl &entity) = 0;
  virtual bool Enter(const pasta::Stmt &entity) = 0;
  virtual bool Enter(const pasta::Type &entity) = 0;

 public:
  virtual ~EntityVisitor(void);
  virtual void Accept(const pasta::Attr &entity);
  virtual void Accept(const pasta::Decl &entity);
  virtual void Accept(const pasta::Stmt &entity);
  virtual void Accept(const pasta::Type &entity);
  virtual void Accept(const pasta::TemplateParameterList &entity);
  virtual void Accept(const pasta::TemplateArgument &entity);
  virtual void Accept(const pasta::Designator &entity);
  virtual void Accept(const pasta::CXXBaseSpecifier &entity);
};

}  // namespace indexer
