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
  if (EnterDecl(decl)) {
    for (pasta::TemplateParameterList ls :
             decl.FriendTypeTemplateParameterLists()) {
      Accept(ls);
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
        Accept(init_expr.value());
      }
      if (auto tpl_init_expr = decl.UninstantiatedDefaultArgument()) {
        Accept(tpl_init_expr.value());
      }
    }
  }
}

void EntityVisitor::VisitNonTypeTemplateParmDecl(
    const pasta::NonTypeTemplateParmDecl &decl) {
  if (EnterDeclaratorDecl(decl)) {
    if (auto init_expr = decl.DefaultArgument()) {
      Accept(init_expr.value());
    }
    if (auto type_constraint = decl.PlaceholderTypeConstraint()) {
      Accept(type_constraint.value());
    }
  }
}

bool EntityVisitor::EnterFunctionDecl(const pasta::FunctionDecl &decl) {
  if (EnterDeclaratorDecl(decl)) {
    Accept(decl.Type());
    VisitDeclContext(decl);
    for (const pasta::ParmVarDecl &param : decl.Parameters()) {
      Accept(param);
    }
    if (auto body = decl.Body()) {
      Accept(body.value());
    }
    return true;
  } else {
    return false;
  }
}

void EntityVisitor::VisitFunctionDecl(const pasta::FunctionDecl &decl) {
  (void) EnterFunctionDecl(decl);
}

void EntityVisitor::VisitFieldDecl(const pasta::FieldDecl &decl) {
  if (EnterDeclaratorDecl(decl)) {
    if (auto bit_width = decl.BitWidth()) {
      Accept(bit_width.value());
    }
    if (auto init = decl.InClassInitializer()) {
      Accept(init.value());
    }
  }
}

// Structs, unions, etc.
void EntityVisitor::VisitRecordDecl(const pasta::RecordDecl &decl) {
  EnterRecordDecl(decl);
}

void EntityVisitor::VisitEnumConstantDecl(const pasta::EnumConstantDecl &decl) {
  if (EnterDecl(decl)) {
    if (auto init = decl.InitializerExpression()) {
      Accept(init.value());
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
  if (EnterDecl(decl)) {
    if (auto tag = decl.AnonymousDeclarationWithTypedefName()) {
      Accept(*tag);
    }
  }
}

void EntityVisitor::VisitStaticAssertDecl(const pasta::StaticAssertDecl &decl) {
  if (EnterDecl(decl)) {
    Accept(decl.AssertExpression());
    if (auto message = decl.Message()) {
      Accept(message.value());
    }
  }
}

void EntityVisitor::VisitFileScopeAsmDecl(const pasta::FileScopeAsmDecl &decl) {
  if (EnterDecl(decl)) {
    Accept(decl.AssemblyString());
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
      Accept(arg);
    }
  }
}

void EntityVisitor::VisitSizeOfPackExpr(const pasta::SizeOfPackExpr &stmt) {
  if (EnterStmt(stmt)) {
    if (auto args = stmt.PartialArguments()) {
      for (const pasta::TemplateArgument &arg : *args) {
        Accept(arg);
      }
    }
  }
}

void EntityVisitor::VisitCXXNewExpr(const pasta::CXXNewExpr &expr) {
  if (EnterStmt(expr)) {
    if (auto size = expr.ArraySize()) {
      Accept(size.value());
    }
    if (auto cons = expr.ConstructExpression()) {
      Accept(cons.value());
    }
    if (auto init = expr.Initializer()) {
      Accept(init.value());
    }
  }
}

void EntityVisitor::VisitCXXTypeidExpr(const pasta::CXXTypeidExpr &expr) {
  if (EnterStmt(expr)) {
    if (auto op = expr.ExpressionOperand()) {
      Accept(op.value());
    }
  }
}

void EntityVisitor::VisitCXXUuidofExpr(const pasta::CXXUuidofExpr &expr) {
  if (EnterStmt(expr)) {
    if (auto op = expr.ExpressionOperand()) {
      Accept(op.value());
    }
  }
}

void EntityVisitor::VisitVarTemplateSpecializationDecl(
    const pasta::VarTemplateSpecializationDecl &decl) {
  if (EnterVarDecl(decl)) {
    // TODO(pag): Are these lexically enclosed in the fragment?
    for (const pasta::TemplateArgument &arg : decl.TemplateArguments()) {
      Accept(arg);
    }

    for (const pasta::TemplateArgument &arg :
             decl.TemplateInstantiationArguments()) {
      Accept(arg);
    }
  }
}

void EntityVisitor::VisitCXXDestructorDecl(
    const pasta::CXXDestructorDecl &decl) {
  if (EnterFunctionDecl(decl)) {
    if (auto this_expr = decl.OperatorDeleteThisArgument()) {
      Accept(this_expr.value());
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
      Accept(ls);
    }
    VisitDeclContext(decl);
    return true;
  } else {
    return false;
  }
}

bool EntityVisitor::EnterRecordDecl(const pasta::RecordDecl &decl) {
  if (EnterTagDecl(decl)) {
    if (decl.IsThisDeclarationADefinition()) {
      for (const pasta::FieldDecl &field : decl.Fields()) {
        Accept(field);
      }
    }
    return true;
  } else {
    return false;
  }
}

bool EntityVisitor::EnterCXXRecordDecl(const pasta::CXXRecordDecl &decl) {
  if (EnterRecordDecl(decl)) {
    
    if (auto bases = decl.Bases()) {
      for (pasta::CXXBaseSpecifier spec : *bases) {
        Accept(spec);
      }
    }
    if (auto vbases = decl.VirtualBases()) {
      for (pasta::CXXBaseSpecifier spec : *vbases) {
        Accept(spec);
      }
    }
    if (auto ls = decl.GenericLambdaTemplateParameterList()) {
      Accept(ls.value());
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
      Accept(arg);
    }

    for (const pasta::TemplateArgument &arg :
             decl.TemplateInstantiationArguments()) {
      Accept(arg);
    }
  }
}

bool EntityVisitor::EnterValueDecl(const pasta::ValueDecl &decl) {
  if (EnterDecl(decl)) {
    Accept(decl.Type());
    return true;
  } else {
    return false;
  }
}

bool EntityVisitor::EnterDeclaratorDecl(const pasta::DeclaratorDecl &decl) {
  if (EnterValueDecl(decl)) {
    for (const pasta::TemplateParameterList &ls : decl.TemplateParameterLists()) {
      Accept(ls);
    }
    return true;
  } else {
    return false;
  }
}

void EntityVisitor::VisitDeclaratorDecl(const pasta::DeclaratorDecl &decl) {
  if (EnterDeclaratorDecl(decl)) {
    if (auto req = decl.TrailingRequiresClause()) {
      Accept(req.value());
    }
  }
}

void EntityVisitor::VisitLambdaExpr(const pasta::LambdaExpr &stmt) {
  if (EnterStmt(stmt)) {
    if (auto ls = stmt.TemplateParameterList()) {
      Accept(ls.value());
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

void EntityVisitor::VisitDesignatedInitExpr(
    const pasta::DesignatedInitExpr &stmt) {
  if (EnterStmt(stmt)) {
    for (auto designator : stmt.Designators()) {
      Accept(designator);
    }
    for (auto sub_expr : stmt.SubExpressions()) {
      Accept(sub_expr);
    }
    Accept(stmt.Initializer());
  }
}

void EntityVisitor::VisitTypeOfExprType(const pasta::TypeOfExprType &type) {
  if (EnterType(type)) {
    Accept(type.UnderlyingExpression());
  }
}

void EntityVisitor::VisitDecltypeType(const pasta::DecltypeType &type) {
  if (EnterType(type)) {
    Accept(type.UnderlyingExpression());
  }
}

void EntityVisitor::VisitDependentAddressSpaceType(
    const pasta::DependentAddressSpaceType &type) {
  if (EnterType(type)) {
    Accept(type.AddressSpaceExpression());
  }
}

void EntityVisitor::VisitDependentBitIntType(
    const pasta::DependentBitIntType &type) {
  if (EnterType(type)) {
    Accept(type.NumBitsExpression());
  } 
}

void EntityVisitor::VisitDependentSizedArrayType(
    const pasta::DependentSizedArrayType &type) {
  if (EnterType(type)) {
    Accept(type.SizeExpression());
  }
}

void EntityVisitor::VisitDependentSizedExtVectorType(
    const pasta::DependentSizedExtVectorType &type) {
  if (EnterType(type)) {
    Accept(type.SizeExpression());
  }
}

void EntityVisitor::VisitDependentSizedMatrixType(
    const pasta::DependentSizedMatrixType &type) {
  if (EnterType(type)) {
    Accept(type.ColumnExpression());
    Accept(type.RowExpression());
  }
}

void EntityVisitor::VisitDependentVectorType(
    const pasta::DependentVectorType &type) {
  if (EnterType(type)) {
    Accept(type.SizeExpression());
  }
}

void EntityVisitor::VisitVariableArrayType(
    const pasta::VariableArrayType &type) {
  if (EnterType(type)) {
    Accept(type.SizeExpression());
  }
}

void EntityVisitor::VisitTypeOfType(const pasta::TypeOfType &type) {
  if (EnterType(type)) {
    Accept(type.UnmodifiedType());
  }
}

void EntityVisitor::VisitFunctionProtoType(
    const pasta::FunctionProtoType &type) {
  if (EnterType(type)) {
    for (const pasta::Type &param_type : type.ParameterTypes()) {
      Accept(param_type);
    }
    for (const pasta::Type &exc_type : type.Exceptions()) {
      Accept(exc_type);
    }
    if (auto noexcept_expr = type.NoexceptExpression()) {
      Accept(noexcept_expr.value());
    }
    
    // NOTE(pag): `ExceptionSpecDeclaration` and `ExceptionSpecTemplate`
    //            are *not* visited because they are not children.
  }
}

void EntityVisitor::VisitAlignedAttr(const pasta::AlignedAttr &attr) {
  if (auto aligned_expr = attr.AlignmentExpression()) {
    Accept(aligned_expr.value());
  }
}

bool EntityVisitor::EnterDecl(const pasta::Decl &decl) {
  if (!Enter(decl)) {
    return false;
  }
  for (const pasta::Attr &attr : decl.Attributes()) {
    Accept(attr);
  }
  if (auto ls = decl.DescribedTemplateParameters()) {
    Accept(ls.value());
  }
  return true;
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

bool EntityVisitor::EnterType(const pasta::Type &type) {
  return Enter(type);
}

bool EntityVisitor::EnterAttr(const pasta::Attr &attr) {
  return Enter(attr);
}

// Backups.
void EntityVisitor::VisitDecl(const pasta::Decl &decl) {
  EnterDecl(decl);
}

void EntityVisitor::VisitStmt(const pasta::Stmt &stmt) {
  EnterStmt(stmt);
}

void EntityVisitor::VisitType(const pasta::Type &stmt) {
  EnterType(stmt);
}

void EntityVisitor::VisitAttr(const pasta::Attr &attr) {
  EnterAttr(attr);
}

void EntityVisitor::Accept(const pasta::Attr &entity) {
  this->AttrVisitor::Accept(entity);
}

void EntityVisitor::Accept(const pasta::Decl &entity) {
  this->DeclVisitor::Accept(entity);
}

void EntityVisitor::Accept(const pasta::Stmt &entity) {
  this->StmtVisitor::Accept(entity);
}

void EntityVisitor::Accept(const pasta::Type &entity) {
  this->TypeVisitor::Accept(entity);
}

void EntityVisitor::Accept(const pasta::TemplateParameterList &entity) {
  for (const pasta::NamedDecl &param_decl : entity.Parameters()) {
    Accept(param_decl);
  }
}

void EntityVisitor::Accept(const pasta::TemplateArgument &entity) {
  if (auto arg_decl = entity.AsDeclaration()) {
    Accept(arg_decl.value());
  }
}

void EntityVisitor::Accept(const pasta::Designator &) {
  // NOTE(pag): Don't need to enter the fields of the designators; they're
  //            likely defined elsewhere.
}

void EntityVisitor::Accept(const pasta::CXXBaseSpecifier &) {
  // NOTE(pag): Don't need to enter the bases; they're likely top-level
  //            declarations.
}

EntityVisitor::~EntityVisitor(void) {}

}  // namespace indexer
