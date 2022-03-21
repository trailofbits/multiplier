// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include "Serialize.h"

#include <pasta/AST/Decl.h>
#include <pasta/AST/Stmt.h>
#include <pasta/AST/Type.h>
#include <pasta/Compile/Command.h>
#include <pasta/Compile/Compiler.h>
#include <pasta/Compile/Job.h>
#include <pasta/Util/ArgumentVector.h>

#include "Serializer.h"

namespace indexer {

void EntitySerializer::SerializeCodeEntities(
    CodeChunk code, mx::ast::EntityList::Builder builder) {
  serialized_entities.clear();
  code_id = code.fragment_id;
  auto tokens_builder = builder.initToken(
      static_cast<unsigned>(code.end_index - code.begin_index + 1u));
  for (auto i = code.begin_index; i <= code.end_index; ++i) {
    Serialize(tokens_builder[static_cast<unsigned>(i - code.begin_index)], range[i]);
  }
  EmptyDecl_builder = builder.initEmptyDecl(code.num_decls_of_kind[pasta::DeclKind::kEmpty]);
  ExportDecl_builder = builder.initExportDecl(code.num_decls_of_kind[pasta::DeclKind::kExport]);
  ExternCContextDecl_builder = builder.initExternCContextDecl(code.num_decls_of_kind[pasta::DeclKind::kExternCContext]);
  FileScopeAsmDecl_builder = builder.initFileScopeAsmDecl(code.num_decls_of_kind[pasta::DeclKind::kFileScopeAsm]);
  FriendDecl_builder = builder.initFriendDecl(code.num_decls_of_kind[pasta::DeclKind::kFriend]);
  FriendTemplateDecl_builder = builder.initFriendTemplateDecl(code.num_decls_of_kind[pasta::DeclKind::kFriendTemplate]);
  ImportDecl_builder = builder.initImportDecl(code.num_decls_of_kind[pasta::DeclKind::kImport]);
  LifetimeExtendedTemporaryDecl_builder = builder.initLifetimeExtendedTemporaryDecl(code.num_decls_of_kind[pasta::DeclKind::kLifetimeExtendedTemporary]);
  LinkageSpecDecl_builder = builder.initLinkageSpecDecl(code.num_decls_of_kind[pasta::DeclKind::kLinkageSpec]);
  NamedDecl_builder = builder.initNamedDecl(code.num_decls_of_kind[pasta::DeclKind::kNamed]);
  NamespaceAliasDecl_builder = builder.initNamespaceAliasDecl(code.num_decls_of_kind[pasta::DeclKind::kNamespaceAlias]);
  NamespaceDecl_builder = builder.initNamespaceDecl(code.num_decls_of_kind[pasta::DeclKind::kNamespace]);
  ObjCCompatibleAliasDecl_builder = builder.initObjCCompatibleAliasDecl(code.num_decls_of_kind[pasta::DeclKind::kObjCCompatibleAlias]);
  ObjCContainerDecl_builder = builder.initObjCContainerDecl(code.num_decls_of_kind[pasta::DeclKind::kObjCContainer]);
  ObjCImplDecl_builder = builder.initObjCImplDecl(code.num_decls_of_kind[pasta::DeclKind::kObjCImpl]);
  ObjCImplementationDecl_builder = builder.initObjCImplementationDecl(code.num_decls_of_kind[pasta::DeclKind::kObjCImplementation]);
  ObjCInterfaceDecl_builder = builder.initObjCInterfaceDecl(code.num_decls_of_kind[pasta::DeclKind::kObjCInterface]);
  ObjCMethodDecl_builder = builder.initObjCMethodDecl(code.num_decls_of_kind[pasta::DeclKind::kObjCMethod]);
  ObjCPropertyDecl_builder = builder.initObjCPropertyDecl(code.num_decls_of_kind[pasta::DeclKind::kObjCProperty]);
  ObjCPropertyImplDecl_builder = builder.initObjCPropertyImplDecl(code.num_decls_of_kind[pasta::DeclKind::kObjCPropertyImpl]);
  ObjCProtocolDecl_builder = builder.initObjCProtocolDecl(code.num_decls_of_kind[pasta::DeclKind::kObjCProtocol]);
  PragmaCommentDecl_builder = builder.initPragmaCommentDecl(code.num_decls_of_kind[pasta::DeclKind::kPragmaComment]);
  PragmaDetectMismatchDecl_builder = builder.initPragmaDetectMismatchDecl(code.num_decls_of_kind[pasta::DeclKind::kPragmaDetectMismatch]);
  RequiresExprBodyDecl_builder = builder.initRequiresExprBodyDecl(code.num_decls_of_kind[pasta::DeclKind::kRequiresExprBody]);
  StaticAssertDecl_builder = builder.initStaticAssertDecl(code.num_decls_of_kind[pasta::DeclKind::kStaticAssert]);
  TemplateDecl_builder = builder.initTemplateDecl(code.num_decls_of_kind[pasta::DeclKind::kTemplate]);
  TemplateTemplateParmDecl_builder = builder.initTemplateTemplateParmDecl(code.num_decls_of_kind[pasta::DeclKind::kTemplateTemplateParm]);
  TranslationUnitDecl_builder = builder.initTranslationUnitDecl(code.num_decls_of_kind[pasta::DeclKind::kTranslationUnit]);
  TypeDecl_builder = builder.initTypeDecl(code.num_decls_of_kind[pasta::DeclKind::kType]);
  TypedefNameDecl_builder = builder.initTypedefNameDecl(code.num_decls_of_kind[pasta::DeclKind::kTypedefName]);
  UnresolvedUsingIfExistsDecl_builder = builder.initUnresolvedUsingIfExistsDecl(code.num_decls_of_kind[pasta::DeclKind::kUnresolvedUsingIfExists]);
  UnresolvedUsingTypenameDecl_builder = builder.initUnresolvedUsingTypenameDecl(code.num_decls_of_kind[pasta::DeclKind::kUnresolvedUsingTypename]);
  UsingDirectiveDecl_builder = builder.initUsingDirectiveDecl(code.num_decls_of_kind[pasta::DeclKind::kUsingDirective]);
  UsingPackDecl_builder = builder.initUsingPackDecl(code.num_decls_of_kind[pasta::DeclKind::kUsingPack]);
  UsingShadowDecl_builder = builder.initUsingShadowDecl(code.num_decls_of_kind[pasta::DeclKind::kUsingShadow]);
  ValueDecl_builder = builder.initValueDecl(code.num_decls_of_kind[pasta::DeclKind::kValue]);
  AccessSpecDecl_builder = builder.initAccessSpecDecl(code.num_decls_of_kind[pasta::DeclKind::kAccessSpec]);
  BaseUsingDecl_builder = builder.initBaseUsingDecl(code.num_decls_of_kind[pasta::DeclKind::kBaseUsing]);
  BindingDecl_builder = builder.initBindingDecl(code.num_decls_of_kind[pasta::DeclKind::kBinding]);
  BlockDecl_builder = builder.initBlockDecl(code.num_decls_of_kind[pasta::DeclKind::kBlock]);
  BuiltinTemplateDecl_builder = builder.initBuiltinTemplateDecl(code.num_decls_of_kind[pasta::DeclKind::kBuiltinTemplate]);
  CapturedDecl_builder = builder.initCapturedDecl(code.num_decls_of_kind[pasta::DeclKind::kCaptured]);
  ClassScopeFunctionSpecializationDecl_builder = builder.initClassScopeFunctionSpecializationDecl(code.num_decls_of_kind[pasta::DeclKind::kClassScopeFunctionSpecialization]);
  ConceptDecl_builder = builder.initConceptDecl(code.num_decls_of_kind[pasta::DeclKind::kConcept]);
  ConstructorUsingShadowDecl_builder = builder.initConstructorUsingShadowDecl(code.num_decls_of_kind[pasta::DeclKind::kConstructorUsingShadow]);
  DeclaratorDecl_builder = builder.initDeclaratorDecl(code.num_decls_of_kind[pasta::DeclKind::kDeclarator]);
  EnumConstantDecl_builder = builder.initEnumConstantDecl(code.num_decls_of_kind[pasta::DeclKind::kEnumConstant]);
  FieldDecl_builder = builder.initFieldDecl(code.num_decls_of_kind[pasta::DeclKind::kField]);
  FunctionDecl_builder = builder.initFunctionDecl(code.num_decls_of_kind[pasta::DeclKind::kFunction]);
  IndirectFieldDecl_builder = builder.initIndirectFieldDecl(code.num_decls_of_kind[pasta::DeclKind::kIndirectField]);
  LabelDecl_builder = builder.initLabelDecl(code.num_decls_of_kind[pasta::DeclKind::kLabel]);
  MSGuidDecl_builder = builder.initMsGuidDecl(code.num_decls_of_kind[pasta::DeclKind::kMSGuid]);
  MSPropertyDecl_builder = builder.initMsPropertyDecl(code.num_decls_of_kind[pasta::DeclKind::kMSProperty]);
  NonTypeTemplateParmDecl_builder = builder.initNonTypeTemplateParmDecl(code.num_decls_of_kind[pasta::DeclKind::kNonTypeTemplateParm]);
  OMPAllocateDecl_builder = builder.initOmpAllocateDecl(code.num_decls_of_kind[pasta::DeclKind::kOMPAllocate]);
  OMPDeclareMapperDecl_builder = builder.initOmpDeclareMapperDecl(code.num_decls_of_kind[pasta::DeclKind::kOMPDeclareMapper]);
  OMPDeclareReductionDecl_builder = builder.initOmpDeclareReductionDecl(code.num_decls_of_kind[pasta::DeclKind::kOMPDeclareReduction]);
  OMPRequiresDecl_builder = builder.initOmpRequiresDecl(code.num_decls_of_kind[pasta::DeclKind::kOMPRequires]);
  OMPThreadPrivateDecl_builder = builder.initOmpThreadPrivateDecl(code.num_decls_of_kind[pasta::DeclKind::kOMPThreadPrivate]);
  ObjCAtDefsFieldDecl_builder = builder.initObjCAtDefsFieldDecl(code.num_decls_of_kind[pasta::DeclKind::kObjCAtDefsField]);
  ObjCCategoryDecl_builder = builder.initObjCCategoryDecl(code.num_decls_of_kind[pasta::DeclKind::kObjCCategory]);
  ObjCCategoryImplDecl_builder = builder.initObjCCategoryImplDecl(code.num_decls_of_kind[pasta::DeclKind::kObjCCategoryImpl]);
  ObjCIvarDecl_builder = builder.initObjCIvarDecl(code.num_decls_of_kind[pasta::DeclKind::kObjCIvar]);
  ObjCTypeParamDecl_builder = builder.initObjCTypeParamDecl(code.num_decls_of_kind[pasta::DeclKind::kObjCTypeParam]);
  RedeclarableTemplateDecl_builder = builder.initRedeclarableTemplateDecl(code.num_decls_of_kind[pasta::DeclKind::kRedeclarableTemplate]);
  TagDecl_builder = builder.initTagDecl(code.num_decls_of_kind[pasta::DeclKind::kTag]);
  TemplateParamObjectDecl_builder = builder.initTemplateParamObjectDecl(code.num_decls_of_kind[pasta::DeclKind::kTemplateParamObject]);
  TemplateTypeParmDecl_builder = builder.initTemplateTypeParmDecl(code.num_decls_of_kind[pasta::DeclKind::kTemplateTypeParm]);
  TypeAliasDecl_builder = builder.initTypeAliasDecl(code.num_decls_of_kind[pasta::DeclKind::kTypeAlias]);
  TypeAliasTemplateDecl_builder = builder.initTypeAliasTemplateDecl(code.num_decls_of_kind[pasta::DeclKind::kTypeAliasTemplate]);
  TypedefDecl_builder = builder.initTypedefDecl(code.num_decls_of_kind[pasta::DeclKind::kTypedef]);
  UnresolvedUsingValueDecl_builder = builder.initUnresolvedUsingValueDecl(code.num_decls_of_kind[pasta::DeclKind::kUnresolvedUsingValue]);
  UsingDecl_builder = builder.initUsingDecl(code.num_decls_of_kind[pasta::DeclKind::kUsing]);
  UsingEnumDecl_builder = builder.initUsingEnumDecl(code.num_decls_of_kind[pasta::DeclKind::kUsingEnum]);
  VarDecl_builder = builder.initVarDecl(code.num_decls_of_kind[pasta::DeclKind::kVar]);
  VarTemplateDecl_builder = builder.initVarTemplateDecl(code.num_decls_of_kind[pasta::DeclKind::kVarTemplate]);
  VarTemplateSpecializationDecl_builder = builder.initVarTemplateSpecializationDecl(code.num_decls_of_kind[pasta::DeclKind::kVarTemplateSpecialization]);
  CXXDeductionGuideDecl_builder = builder.initCxxDeductionGuideDecl(code.num_decls_of_kind[pasta::DeclKind::kCXXDeductionGuide]);
  CXXMethodDecl_builder = builder.initCxxMethodDecl(code.num_decls_of_kind[pasta::DeclKind::kCXXMethod]);
  ClassTemplateDecl_builder = builder.initClassTemplateDecl(code.num_decls_of_kind[pasta::DeclKind::kClassTemplate]);
  DecompositionDecl_builder = builder.initDecompositionDecl(code.num_decls_of_kind[pasta::DeclKind::kDecomposition]);
  EnumDecl_builder = builder.initEnumDecl(code.num_decls_of_kind[pasta::DeclKind::kEnum]);
  FunctionTemplateDecl_builder = builder.initFunctionTemplateDecl(code.num_decls_of_kind[pasta::DeclKind::kFunctionTemplate]);
  ImplicitParamDecl_builder = builder.initImplicitParamDecl(code.num_decls_of_kind[pasta::DeclKind::kImplicitParam]);
  OMPCapturedExprDecl_builder = builder.initOmpCapturedExprDecl(code.num_decls_of_kind[pasta::DeclKind::kOMPCapturedExpr]);
  ParmVarDecl_builder = builder.initParmVarDecl(code.num_decls_of_kind[pasta::DeclKind::kParmVar]);
  RecordDecl_builder = builder.initRecordDecl(code.num_decls_of_kind[pasta::DeclKind::kRecord]);
  VarTemplatePartialSpecializationDecl_builder = builder.initVarTemplatePartialSpecializationDecl(code.num_decls_of_kind[pasta::DeclKind::kVarTemplatePartialSpecialization]);
  CXXConstructorDecl_builder = builder.initCxxConstructorDecl(code.num_decls_of_kind[pasta::DeclKind::kCXXConstructor]);
  CXXConversionDecl_builder = builder.initCxxConversionDecl(code.num_decls_of_kind[pasta::DeclKind::kCXXConversion]);
  CXXDestructorDecl_builder = builder.initCxxDestructorDecl(code.num_decls_of_kind[pasta::DeclKind::kCXXDestructor]);
  CXXRecordDecl_builder = builder.initCxxRecordDecl(code.num_decls_of_kind[pasta::DeclKind::kCXXRecord]);
  ClassTemplateSpecializationDecl_builder = builder.initClassTemplateSpecializationDecl(code.num_decls_of_kind[pasta::DeclKind::kClassTemplateSpecialization]);
  ClassTemplatePartialSpecializationDecl_builder = builder.initClassTemplatePartialSpecializationDecl(code.num_decls_of_kind[pasta::DeclKind::kClassTemplatePartialSpecialization]);
  SwitchStmt_builder = builder.initSwitchStmt(code.num_stmts_of_kind[pasta::StmtKind::kSwitchStmt]);
  WhileStmt_builder = builder.initWhileStmt(code.num_stmts_of_kind[pasta::StmtKind::kWhileStmt]);
  AttributedStmt_builder = builder.initAttributedStmt(code.num_stmts_of_kind[pasta::StmtKind::kAttributedStmt]);
  BreakStmt_builder = builder.initBreakStmt(code.num_stmts_of_kind[pasta::StmtKind::kBreakStmt]);
  CXXCatchStmt_builder = builder.initCxxCatchStmt(code.num_stmts_of_kind[pasta::StmtKind::kCXXCatchStmt]);
  CXXForRangeStmt_builder = builder.initCxxForRangeStmt(code.num_stmts_of_kind[pasta::StmtKind::kCXXForRangeStmt]);
  CXXTryStmt_builder = builder.initCxxTryStmt(code.num_stmts_of_kind[pasta::StmtKind::kCXXTryStmt]);
  CapturedStmt_builder = builder.initCapturedStmt(code.num_stmts_of_kind[pasta::StmtKind::kCapturedStmt]);
  CaseStmt_builder = builder.initCaseStmt(code.num_stmts_of_kind[pasta::StmtKind::kCaseStmt]);
  CompoundStmt_builder = builder.initCompoundStmt(code.num_stmts_of_kind[pasta::StmtKind::kCompoundStmt]);
  ContinueStmt_builder = builder.initContinueStmt(code.num_stmts_of_kind[pasta::StmtKind::kContinueStmt]);
  CoreturnStmt_builder = builder.initCoreturnStmt(code.num_stmts_of_kind[pasta::StmtKind::kCoreturnStmt]);
  CoroutineBodyStmt_builder = builder.initCoroutineBodyStmt(code.num_stmts_of_kind[pasta::StmtKind::kCoroutineBodyStmt]);
  DeclStmt_builder = builder.initDeclStmt(code.num_stmts_of_kind[pasta::StmtKind::kDeclStmt]);
  DefaultStmt_builder = builder.initDefaultStmt(code.num_stmts_of_kind[pasta::StmtKind::kDefaultStmt]);
  DoStmt_builder = builder.initDoStmt(code.num_stmts_of_kind[pasta::StmtKind::kDoStmt]);
  ExpressionTraitExpr_builder = builder.initExpressionTraitExpr(code.num_stmts_of_kind[pasta::StmtKind::kExpressionTraitExpr]);
  ExtVectorElementExpr_builder = builder.initExtVectorElementExpr(code.num_stmts_of_kind[pasta::StmtKind::kExtVectorElementExpr]);
  FixedPointLiteral_builder = builder.initFixedPointLiteral(code.num_stmts_of_kind[pasta::StmtKind::kFixedPointLiteral]);
  FloatingLiteral_builder = builder.initFloatingLiteral(code.num_stmts_of_kind[pasta::StmtKind::kFloatingLiteral]);
  ForStmt_builder = builder.initForStmt(code.num_stmts_of_kind[pasta::StmtKind::kForStmt]);
  FunctionParmPackExpr_builder = builder.initFunctionParmPackExpr(code.num_stmts_of_kind[pasta::StmtKind::kFunctionParmPackExpr]);
  GCCAsmStmt_builder = builder.initGccAsmStmt(code.num_stmts_of_kind[pasta::StmtKind::kGCCAsmStmt]);
  GNUNullExpr_builder = builder.initGnuNullExpr(code.num_stmts_of_kind[pasta::StmtKind::kGNUNullExpr]);
  GenericSelectionExpr_builder = builder.initGenericSelectionExpr(code.num_stmts_of_kind[pasta::StmtKind::kGenericSelectionExpr]);
  GotoStmt_builder = builder.initGotoStmt(code.num_stmts_of_kind[pasta::StmtKind::kGotoStmt]);
  IfStmt_builder = builder.initIfStmt(code.num_stmts_of_kind[pasta::StmtKind::kIfStmt]);
  ImaginaryLiteral_builder = builder.initImaginaryLiteral(code.num_stmts_of_kind[pasta::StmtKind::kImaginaryLiteral]);
  ImplicitValueInitExpr_builder = builder.initImplicitValueInitExpr(code.num_stmts_of_kind[pasta::StmtKind::kImplicitValueInitExpr]);
  IndirectGotoStmt_builder = builder.initIndirectGotoStmt(code.num_stmts_of_kind[pasta::StmtKind::kIndirectGotoStmt]);
  InitListExpr_builder = builder.initInitListExpr(code.num_stmts_of_kind[pasta::StmtKind::kInitListExpr]);
  IntegerLiteral_builder = builder.initIntegerLiteral(code.num_stmts_of_kind[pasta::StmtKind::kIntegerLiteral]);
  LabelStmt_builder = builder.initLabelStmt(code.num_stmts_of_kind[pasta::StmtKind::kLabelStmt]);
  LambdaExpr_builder = builder.initLambdaExpr(code.num_stmts_of_kind[pasta::StmtKind::kLambdaExpr]);
  MSAsmStmt_builder = builder.initMsAsmStmt(code.num_stmts_of_kind[pasta::StmtKind::kMSAsmStmt]);
  MSDependentExistsStmt_builder = builder.initMsDependentExistsStmt(code.num_stmts_of_kind[pasta::StmtKind::kMSDependentExistsStmt]);
  MSPropertyRefExpr_builder = builder.initMsPropertyRefExpr(code.num_stmts_of_kind[pasta::StmtKind::kMSPropertyRefExpr]);
  MSPropertySubscriptExpr_builder = builder.initMsPropertySubscriptExpr(code.num_stmts_of_kind[pasta::StmtKind::kMSPropertySubscriptExpr]);
  MaterializeTemporaryExpr_builder = builder.initMaterializeTemporaryExpr(code.num_stmts_of_kind[pasta::StmtKind::kMaterializeTemporaryExpr]);
  MatrixSubscriptExpr_builder = builder.initMatrixSubscriptExpr(code.num_stmts_of_kind[pasta::StmtKind::kMatrixSubscriptExpr]);
  MemberExpr_builder = builder.initMemberExpr(code.num_stmts_of_kind[pasta::StmtKind::kMemberExpr]);
  NoInitExpr_builder = builder.initNoInitExpr(code.num_stmts_of_kind[pasta::StmtKind::kNoInitExpr]);
  NullStmt_builder = builder.initNullStmt(code.num_stmts_of_kind[pasta::StmtKind::kNullStmt]);
  OMPArraySectionExpr_builder = builder.initOmpArraySectionExpr(code.num_stmts_of_kind[pasta::StmtKind::kOMPArraySectionExpr]);
  OMPArrayShapingExpr_builder = builder.initOmpArrayShapingExpr(code.num_stmts_of_kind[pasta::StmtKind::kOMPArrayShapingExpr]);
  OMPCanonicalLoop_builder = builder.initOmpCanonicalLoop(code.num_stmts_of_kind[pasta::StmtKind::kOMPCanonicalLoop]);
  OMPFlushDirective_builder = builder.initOmpFlushDirective(code.num_stmts_of_kind[pasta::StmtKind::kOMPFlushDirective]);
  OMPInteropDirective_builder = builder.initOmpInteropDirective(code.num_stmts_of_kind[pasta::StmtKind::kOMPInteropDirective]);
  OMPIteratorExpr_builder = builder.initOmpIteratorExpr(code.num_stmts_of_kind[pasta::StmtKind::kOMPIteratorExpr]);
  OMPMaskedDirective_builder = builder.initOmpMaskedDirective(code.num_stmts_of_kind[pasta::StmtKind::kOMPMaskedDirective]);
  OMPMasterDirective_builder = builder.initOmpMasterDirective(code.num_stmts_of_kind[pasta::StmtKind::kOMPMasterDirective]);
  OMPMasterTaskLoopDirective_builder = builder.initOmpMasterTaskLoopDirective(code.num_stmts_of_kind[pasta::StmtKind::kOMPMasterTaskLoopDirective]);
  OMPMasterTaskLoopSimdDirective_builder = builder.initOmpMasterTaskLoopSimdDirective(code.num_stmts_of_kind[pasta::StmtKind::kOMPMasterTaskLoopSimdDirective]);
  OMPOrderedDirective_builder = builder.initOmpOrderedDirective(code.num_stmts_of_kind[pasta::StmtKind::kOMPOrderedDirective]);
  OMPParallelDirective_builder = builder.initOmpParallelDirective(code.num_stmts_of_kind[pasta::StmtKind::kOMPParallelDirective]);
  OMPParallelForDirective_builder = builder.initOmpParallelForDirective(code.num_stmts_of_kind[pasta::StmtKind::kOMPParallelForDirective]);
  OMPParallelForSimdDirective_builder = builder.initOmpParallelForSimdDirective(code.num_stmts_of_kind[pasta::StmtKind::kOMPParallelForSimdDirective]);
  OMPParallelMasterDirective_builder = builder.initOmpParallelMasterDirective(code.num_stmts_of_kind[pasta::StmtKind::kOMPParallelMasterDirective]);
  OMPParallelMasterTaskLoopDirective_builder = builder.initOmpParallelMasterTaskLoopDirective(code.num_stmts_of_kind[pasta::StmtKind::kOMPParallelMasterTaskLoopDirective]);
  OMPParallelMasterTaskLoopSimdDirective_builder = builder.initOmpParallelMasterTaskLoopSimdDirective(code.num_stmts_of_kind[pasta::StmtKind::kOMPParallelMasterTaskLoopSimdDirective]);
  OMPParallelSectionsDirective_builder = builder.initOmpParallelSectionsDirective(code.num_stmts_of_kind[pasta::StmtKind::kOMPParallelSectionsDirective]);
  OMPScanDirective_builder = builder.initOmpScanDirective(code.num_stmts_of_kind[pasta::StmtKind::kOMPScanDirective]);
  OMPSectionDirective_builder = builder.initOmpSectionDirective(code.num_stmts_of_kind[pasta::StmtKind::kOMPSectionDirective]);
  OMPSectionsDirective_builder = builder.initOmpSectionsDirective(code.num_stmts_of_kind[pasta::StmtKind::kOMPSectionsDirective]);
  OMPSimdDirective_builder = builder.initOmpSimdDirective(code.num_stmts_of_kind[pasta::StmtKind::kOMPSimdDirective]);
  OMPSingleDirective_builder = builder.initOmpSingleDirective(code.num_stmts_of_kind[pasta::StmtKind::kOMPSingleDirective]);
  OMPTargetDataDirective_builder = builder.initOmpTargetDataDirective(code.num_stmts_of_kind[pasta::StmtKind::kOMPTargetDataDirective]);
  OMPTargetDirective_builder = builder.initOmpTargetDirective(code.num_stmts_of_kind[pasta::StmtKind::kOMPTargetDirective]);
  OMPTargetEnterDataDirective_builder = builder.initOmpTargetEnterDataDirective(code.num_stmts_of_kind[pasta::StmtKind::kOMPTargetEnterDataDirective]);
  OMPTargetExitDataDirective_builder = builder.initOmpTargetExitDataDirective(code.num_stmts_of_kind[pasta::StmtKind::kOMPTargetExitDataDirective]);
  OMPTargetParallelDirective_builder = builder.initOmpTargetParallelDirective(code.num_stmts_of_kind[pasta::StmtKind::kOMPTargetParallelDirective]);
  OMPTargetParallelForDirective_builder = builder.initOmpTargetParallelForDirective(code.num_stmts_of_kind[pasta::StmtKind::kOMPTargetParallelForDirective]);
  OMPTargetParallelForSimdDirective_builder = builder.initOmpTargetParallelForSimdDirective(code.num_stmts_of_kind[pasta::StmtKind::kOMPTargetParallelForSimdDirective]);
  OMPTargetSimdDirective_builder = builder.initOmpTargetSimdDirective(code.num_stmts_of_kind[pasta::StmtKind::kOMPTargetSimdDirective]);
  OMPTargetTeamsDirective_builder = builder.initOmpTargetTeamsDirective(code.num_stmts_of_kind[pasta::StmtKind::kOMPTargetTeamsDirective]);
  OMPTargetTeamsDistributeDirective_builder = builder.initOmpTargetTeamsDistributeDirective(code.num_stmts_of_kind[pasta::StmtKind::kOMPTargetTeamsDistributeDirective]);
  OMPTargetTeamsDistributeParallelForDirective_builder = builder.initOmpTargetTeamsDistributeParallelForDirective(code.num_stmts_of_kind[pasta::StmtKind::kOMPTargetTeamsDistributeParallelForDirective]);
  OMPTargetTeamsDistributeParallelForSimdDirective_builder = builder.initOmpTargetTeamsDistributeParallelForSimdDirective(code.num_stmts_of_kind[pasta::StmtKind::kOMPTargetTeamsDistributeParallelForSimdDirective]);
  OMPTargetTeamsDistributeSimdDirective_builder = builder.initOmpTargetTeamsDistributeSimdDirective(code.num_stmts_of_kind[pasta::StmtKind::kOMPTargetTeamsDistributeSimdDirective]);
  OMPTargetUpdateDirective_builder = builder.initOmpTargetUpdateDirective(code.num_stmts_of_kind[pasta::StmtKind::kOMPTargetUpdateDirective]);
  OMPTaskDirective_builder = builder.initOmpTaskDirective(code.num_stmts_of_kind[pasta::StmtKind::kOMPTaskDirective]);
  OMPTaskLoopDirective_builder = builder.initOmpTaskLoopDirective(code.num_stmts_of_kind[pasta::StmtKind::kOMPTaskLoopDirective]);
  OMPTaskLoopSimdDirective_builder = builder.initOmpTaskLoopSimdDirective(code.num_stmts_of_kind[pasta::StmtKind::kOMPTaskLoopSimdDirective]);
  OMPTaskgroupDirective_builder = builder.initOmpTaskgroupDirective(code.num_stmts_of_kind[pasta::StmtKind::kOMPTaskgroupDirective]);
  OMPTaskwaitDirective_builder = builder.initOmpTaskwaitDirective(code.num_stmts_of_kind[pasta::StmtKind::kOMPTaskwaitDirective]);
  OMPTaskyieldDirective_builder = builder.initOmpTaskyieldDirective(code.num_stmts_of_kind[pasta::StmtKind::kOMPTaskyieldDirective]);
  OMPTeamsDirective_builder = builder.initOmpTeamsDirective(code.num_stmts_of_kind[pasta::StmtKind::kOMPTeamsDirective]);
  OMPTeamsDistributeDirective_builder = builder.initOmpTeamsDistributeDirective(code.num_stmts_of_kind[pasta::StmtKind::kOMPTeamsDistributeDirective]);
  OMPTeamsDistributeParallelForDirective_builder = builder.initOmpTeamsDistributeParallelForDirective(code.num_stmts_of_kind[pasta::StmtKind::kOMPTeamsDistributeParallelForDirective]);
  OMPTeamsDistributeParallelForSimdDirective_builder = builder.initOmpTeamsDistributeParallelForSimdDirective(code.num_stmts_of_kind[pasta::StmtKind::kOMPTeamsDistributeParallelForSimdDirective]);
  OMPTeamsDistributeSimdDirective_builder = builder.initOmpTeamsDistributeSimdDirective(code.num_stmts_of_kind[pasta::StmtKind::kOMPTeamsDistributeSimdDirective]);
  OMPTileDirective_builder = builder.initOmpTileDirective(code.num_stmts_of_kind[pasta::StmtKind::kOMPTileDirective]);
  OMPUnrollDirective_builder = builder.initOmpUnrollDirective(code.num_stmts_of_kind[pasta::StmtKind::kOMPUnrollDirective]);
  ObjCArrayLiteral_builder = builder.initObjCArrayLiteral(code.num_stmts_of_kind[pasta::StmtKind::kObjCArrayLiteral]);
  ObjCAtCatchStmt_builder = builder.initObjCAtCatchStmt(code.num_stmts_of_kind[pasta::StmtKind::kObjCAtCatchStmt]);
  ObjCAtFinallyStmt_builder = builder.initObjCAtFinallyStmt(code.num_stmts_of_kind[pasta::StmtKind::kObjCAtFinallyStmt]);
  ObjCAtSynchronizedStmt_builder = builder.initObjCAtSynchronizedStmt(code.num_stmts_of_kind[pasta::StmtKind::kObjCAtSynchronizedStmt]);
  ObjCAtThrowStmt_builder = builder.initObjCAtThrowStmt(code.num_stmts_of_kind[pasta::StmtKind::kObjCAtThrowStmt]);
  ObjCAtTryStmt_builder = builder.initObjCAtTryStmt(code.num_stmts_of_kind[pasta::StmtKind::kObjCAtTryStmt]);
  ObjCAutoreleasePoolStmt_builder = builder.initObjCAutoreleasePoolStmt(code.num_stmts_of_kind[pasta::StmtKind::kObjCAutoreleasePoolStmt]);
  ObjCAvailabilityCheckExpr_builder = builder.initObjCAvailabilityCheckExpr(code.num_stmts_of_kind[pasta::StmtKind::kObjCAvailabilityCheckExpr]);
  ObjCBoolLiteralExpr_builder = builder.initObjCBoolLiteralExpr(code.num_stmts_of_kind[pasta::StmtKind::kObjCBoolLiteralExpr]);
  ObjCBoxedExpr_builder = builder.initObjCBoxedExpr(code.num_stmts_of_kind[pasta::StmtKind::kObjCBoxedExpr]);
  ObjCDictionaryLiteral_builder = builder.initObjCDictionaryLiteral(code.num_stmts_of_kind[pasta::StmtKind::kObjCDictionaryLiteral]);
  ObjCEncodeExpr_builder = builder.initObjCEncodeExpr(code.num_stmts_of_kind[pasta::StmtKind::kObjCEncodeExpr]);
  ObjCForCollectionStmt_builder = builder.initObjCForCollectionStmt(code.num_stmts_of_kind[pasta::StmtKind::kObjCForCollectionStmt]);
  ObjCIndirectCopyRestoreExpr_builder = builder.initObjCIndirectCopyRestoreExpr(code.num_stmts_of_kind[pasta::StmtKind::kObjCIndirectCopyRestoreExpr]);
  ObjCIsaExpr_builder = builder.initObjCIsaExpr(code.num_stmts_of_kind[pasta::StmtKind::kObjCIsaExpr]);
  ObjCIvarRefExpr_builder = builder.initObjCIvarRefExpr(code.num_stmts_of_kind[pasta::StmtKind::kObjCIvarRefExpr]);
  ObjCMessageExpr_builder = builder.initObjCMessageExpr(code.num_stmts_of_kind[pasta::StmtKind::kObjCMessageExpr]);
  ObjCPropertyRefExpr_builder = builder.initObjCPropertyRefExpr(code.num_stmts_of_kind[pasta::StmtKind::kObjCPropertyRefExpr]);
  ObjCProtocolExpr_builder = builder.initObjCProtocolExpr(code.num_stmts_of_kind[pasta::StmtKind::kObjCProtocolExpr]);
  ObjCSelectorExpr_builder = builder.initObjCSelectorExpr(code.num_stmts_of_kind[pasta::StmtKind::kObjCSelectorExpr]);
  ObjCStringLiteral_builder = builder.initObjCStringLiteral(code.num_stmts_of_kind[pasta::StmtKind::kObjCStringLiteral]);
  ObjCSubscriptRefExpr_builder = builder.initObjCSubscriptRefExpr(code.num_stmts_of_kind[pasta::StmtKind::kObjCSubscriptRefExpr]);
  OffsetOfExpr_builder = builder.initOffsetOfExpr(code.num_stmts_of_kind[pasta::StmtKind::kOffsetOfExpr]);
  OpaqueValueExpr_builder = builder.initOpaqueValueExpr(code.num_stmts_of_kind[pasta::StmtKind::kOpaqueValueExpr]);
  PackExpansionExpr_builder = builder.initPackExpansionExpr(code.num_stmts_of_kind[pasta::StmtKind::kPackExpansionExpr]);
  ParenExpr_builder = builder.initParenExpr(code.num_stmts_of_kind[pasta::StmtKind::kParenExpr]);
  ParenListExpr_builder = builder.initParenListExpr(code.num_stmts_of_kind[pasta::StmtKind::kParenListExpr]);
  PredefinedExpr_builder = builder.initPredefinedExpr(code.num_stmts_of_kind[pasta::StmtKind::kPredefinedExpr]);
  PseudoObjectExpr_builder = builder.initPseudoObjectExpr(code.num_stmts_of_kind[pasta::StmtKind::kPseudoObjectExpr]);
  RecoveryExpr_builder = builder.initRecoveryExpr(code.num_stmts_of_kind[pasta::StmtKind::kRecoveryExpr]);
  RequiresExpr_builder = builder.initRequiresExpr(code.num_stmts_of_kind[pasta::StmtKind::kRequiresExpr]);
  ReturnStmt_builder = builder.initReturnStmt(code.num_stmts_of_kind[pasta::StmtKind::kReturnStmt]);
  SEHExceptStmt_builder = builder.initSehExceptStmt(code.num_stmts_of_kind[pasta::StmtKind::kSEHExceptStmt]);
  SEHFinallyStmt_builder = builder.initSehFinallyStmt(code.num_stmts_of_kind[pasta::StmtKind::kSEHFinallyStmt]);
  SEHLeaveStmt_builder = builder.initSehLeaveStmt(code.num_stmts_of_kind[pasta::StmtKind::kSEHLeaveStmt]);
  SEHTryStmt_builder = builder.initSehTryStmt(code.num_stmts_of_kind[pasta::StmtKind::kSEHTryStmt]);
  SYCLUniqueStableNameExpr_builder = builder.initSyclUniqueStableNameExpr(code.num_stmts_of_kind[pasta::StmtKind::kSYCLUniqueStableNameExpr]);
  ShuffleVectorExpr_builder = builder.initShuffleVectorExpr(code.num_stmts_of_kind[pasta::StmtKind::kShuffleVectorExpr]);
  SizeOfPackExpr_builder = builder.initSizeOfPackExpr(code.num_stmts_of_kind[pasta::StmtKind::kSizeOfPackExpr]);
  SourceLocExpr_builder = builder.initSourceLocExpr(code.num_stmts_of_kind[pasta::StmtKind::kSourceLocExpr]);
  StmtExpr_builder = builder.initStmtExpr(code.num_stmts_of_kind[pasta::StmtKind::kStmtExpr]);
  StringLiteral_builder = builder.initStringLiteral(code.num_stmts_of_kind[pasta::StmtKind::kStringLiteral]);
  SubstNonTypeTemplateParmExpr_builder = builder.initSubstNonTypeTemplateParmExpr(code.num_stmts_of_kind[pasta::StmtKind::kSubstNonTypeTemplateParmExpr]);
  SubstNonTypeTemplateParmPackExpr_builder = builder.initSubstNonTypeTemplateParmPackExpr(code.num_stmts_of_kind[pasta::StmtKind::kSubstNonTypeTemplateParmPackExpr]);
  TypeTraitExpr_builder = builder.initTypeTraitExpr(code.num_stmts_of_kind[pasta::StmtKind::kTypeTraitExpr]);
  TypoExpr_builder = builder.initTypoExpr(code.num_stmts_of_kind[pasta::StmtKind::kTypoExpr]);
  UnaryExprOrTypeTraitExpr_builder = builder.initUnaryExprOrTypeTraitExpr(code.num_stmts_of_kind[pasta::StmtKind::kUnaryExprOrTypeTraitExpr]);
  UnaryOperator_builder = builder.initUnaryOperator(code.num_stmts_of_kind[pasta::StmtKind::kUnaryOperator]);
  UnresolvedLookupExpr_builder = builder.initUnresolvedLookupExpr(code.num_stmts_of_kind[pasta::StmtKind::kUnresolvedLookupExpr]);
  UnresolvedMemberExpr_builder = builder.initUnresolvedMemberExpr(code.num_stmts_of_kind[pasta::StmtKind::kUnresolvedMemberExpr]);
  VAArgExpr_builder = builder.initVaArgExpr(code.num_stmts_of_kind[pasta::StmtKind::kVAArgExpr]);
  AddrLabelExpr_builder = builder.initAddrLabelExpr(code.num_stmts_of_kind[pasta::StmtKind::kAddrLabelExpr]);
  ArrayInitIndexExpr_builder = builder.initArrayInitIndexExpr(code.num_stmts_of_kind[pasta::StmtKind::kArrayInitIndexExpr]);
  ArrayInitLoopExpr_builder = builder.initArrayInitLoopExpr(code.num_stmts_of_kind[pasta::StmtKind::kArrayInitLoopExpr]);
  ArraySubscriptExpr_builder = builder.initArraySubscriptExpr(code.num_stmts_of_kind[pasta::StmtKind::kArraySubscriptExpr]);
  ArrayTypeTraitExpr_builder = builder.initArrayTypeTraitExpr(code.num_stmts_of_kind[pasta::StmtKind::kArrayTypeTraitExpr]);
  AsTypeExpr_builder = builder.initAsTypeExpr(code.num_stmts_of_kind[pasta::StmtKind::kAsTypeExpr]);
  AtomicExpr_builder = builder.initAtomicExpr(code.num_stmts_of_kind[pasta::StmtKind::kAtomicExpr]);
  BinaryConditionalOperator_builder = builder.initBinaryConditionalOperator(code.num_stmts_of_kind[pasta::StmtKind::kBinaryConditionalOperator]);
  BinaryOperator_builder = builder.initBinaryOperator(code.num_stmts_of_kind[pasta::StmtKind::kBinaryOperator]);
  BlockExpr_builder = builder.initBlockExpr(code.num_stmts_of_kind[pasta::StmtKind::kBlockExpr]);
  CXXBindTemporaryExpr_builder = builder.initCxxBindTemporaryExpr(code.num_stmts_of_kind[pasta::StmtKind::kCXXBindTemporaryExpr]);
  CXXBoolLiteralExpr_builder = builder.initCxxBoolLiteralExpr(code.num_stmts_of_kind[pasta::StmtKind::kCXXBoolLiteralExpr]);
  CXXConstructExpr_builder = builder.initCxxConstructExpr(code.num_stmts_of_kind[pasta::StmtKind::kCXXConstructExpr]);
  CXXDefaultArgExpr_builder = builder.initCxxDefaultArgExpr(code.num_stmts_of_kind[pasta::StmtKind::kCXXDefaultArgExpr]);
  CXXDefaultInitExpr_builder = builder.initCxxDefaultInitExpr(code.num_stmts_of_kind[pasta::StmtKind::kCXXDefaultInitExpr]);
  CXXDeleteExpr_builder = builder.initCxxDeleteExpr(code.num_stmts_of_kind[pasta::StmtKind::kCXXDeleteExpr]);
  CXXDependentScopeMemberExpr_builder = builder.initCxxDependentScopeMemberExpr(code.num_stmts_of_kind[pasta::StmtKind::kCXXDependentScopeMemberExpr]);
  CXXFoldExpr_builder = builder.initCxxFoldExpr(code.num_stmts_of_kind[pasta::StmtKind::kCXXFoldExpr]);
  CXXInheritedCtorInitExpr_builder = builder.initCxxInheritedCtorInitExpr(code.num_stmts_of_kind[pasta::StmtKind::kCXXInheritedCtorInitExpr]);
  CXXNewExpr_builder = builder.initCxxNewExpr(code.num_stmts_of_kind[pasta::StmtKind::kCXXNewExpr]);
  CXXNoexceptExpr_builder = builder.initCxxNoexceptExpr(code.num_stmts_of_kind[pasta::StmtKind::kCXXNoexceptExpr]);
  CXXNullPtrLiteralExpr_builder = builder.initCxxNullPtrLiteralExpr(code.num_stmts_of_kind[pasta::StmtKind::kCXXNullPtrLiteralExpr]);
  CXXPseudoDestructorExpr_builder = builder.initCxxPseudoDestructorExpr(code.num_stmts_of_kind[pasta::StmtKind::kCXXPseudoDestructorExpr]);
  CXXRewrittenBinaryOperator_builder = builder.initCxxRewrittenBinaryOperator(code.num_stmts_of_kind[pasta::StmtKind::kCXXRewrittenBinaryOperator]);
  CXXScalarValueInitExpr_builder = builder.initCxxScalarValueInitExpr(code.num_stmts_of_kind[pasta::StmtKind::kCXXScalarValueInitExpr]);
  CXXStdInitializerListExpr_builder = builder.initCxxStdInitializerListExpr(code.num_stmts_of_kind[pasta::StmtKind::kCXXStdInitializerListExpr]);
  CXXTemporaryObjectExpr_builder = builder.initCxxTemporaryObjectExpr(code.num_stmts_of_kind[pasta::StmtKind::kCXXTemporaryObjectExpr]);
  CXXThisExpr_builder = builder.initCxxThisExpr(code.num_stmts_of_kind[pasta::StmtKind::kCXXThisExpr]);
  CXXThrowExpr_builder = builder.initCxxThrowExpr(code.num_stmts_of_kind[pasta::StmtKind::kCXXThrowExpr]);
  CXXTypeidExpr_builder = builder.initCxxTypeidExpr(code.num_stmts_of_kind[pasta::StmtKind::kCXXTypeidExpr]);
  CXXUnresolvedConstructExpr_builder = builder.initCxxUnresolvedConstructExpr(code.num_stmts_of_kind[pasta::StmtKind::kCXXUnresolvedConstructExpr]);
  CXXUuidofExpr_builder = builder.initCxxUuidofExpr(code.num_stmts_of_kind[pasta::StmtKind::kCXXUuidofExpr]);
  CallExpr_builder = builder.initCallExpr(code.num_stmts_of_kind[pasta::StmtKind::kCallExpr]);
  CharacterLiteral_builder = builder.initCharacterLiteral(code.num_stmts_of_kind[pasta::StmtKind::kCharacterLiteral]);
  ChooseExpr_builder = builder.initChooseExpr(code.num_stmts_of_kind[pasta::StmtKind::kChooseExpr]);
  CompoundAssignOperator_builder = builder.initCompoundAssignOperator(code.num_stmts_of_kind[pasta::StmtKind::kCompoundAssignOperator]);
  CompoundLiteralExpr_builder = builder.initCompoundLiteralExpr(code.num_stmts_of_kind[pasta::StmtKind::kCompoundLiteralExpr]);
  ConceptSpecializationExpr_builder = builder.initConceptSpecializationExpr(code.num_stmts_of_kind[pasta::StmtKind::kConceptSpecializationExpr]);
  ConditionalOperator_builder = builder.initConditionalOperator(code.num_stmts_of_kind[pasta::StmtKind::kConditionalOperator]);
  ConstantExpr_builder = builder.initConstantExpr(code.num_stmts_of_kind[pasta::StmtKind::kConstantExpr]);
  ConvertVectorExpr_builder = builder.initConvertVectorExpr(code.num_stmts_of_kind[pasta::StmtKind::kConvertVectorExpr]);
  CoyieldExpr_builder = builder.initCoyieldExpr(code.num_stmts_of_kind[pasta::StmtKind::kCoyieldExpr]);
  DeclRefExpr_builder = builder.initDeclRefExpr(code.num_stmts_of_kind[pasta::StmtKind::kDeclRefExpr]);
  DependentCoawaitExpr_builder = builder.initDependentCoawaitExpr(code.num_stmts_of_kind[pasta::StmtKind::kDependentCoawaitExpr]);
  DependentScopeDeclRefExpr_builder = builder.initDependentScopeDeclRefExpr(code.num_stmts_of_kind[pasta::StmtKind::kDependentScopeDeclRefExpr]);
  DesignatedInitExpr_builder = builder.initDesignatedInitExpr(code.num_stmts_of_kind[pasta::StmtKind::kDesignatedInitExpr]);
  DesignatedInitUpdateExpr_builder = builder.initDesignatedInitUpdateExpr(code.num_stmts_of_kind[pasta::StmtKind::kDesignatedInitUpdateExpr]);
  ExprWithCleanups_builder = builder.initExprWithCleanups(code.num_stmts_of_kind[pasta::StmtKind::kExprWithCleanups]);
  ImplicitCastExpr_builder = builder.initImplicitCastExpr(code.num_stmts_of_kind[pasta::StmtKind::kImplicitCastExpr]);
  OMPAtomicDirective_builder = builder.initOmpAtomicDirective(code.num_stmts_of_kind[pasta::StmtKind::kOMPAtomicDirective]);
  OMPBarrierDirective_builder = builder.initOmpBarrierDirective(code.num_stmts_of_kind[pasta::StmtKind::kOMPBarrierDirective]);
  OMPCancelDirective_builder = builder.initOmpCancelDirective(code.num_stmts_of_kind[pasta::StmtKind::kOMPCancelDirective]);
  OMPCancellationPointDirective_builder = builder.initOmpCancellationPointDirective(code.num_stmts_of_kind[pasta::StmtKind::kOMPCancellationPointDirective]);
  OMPCriticalDirective_builder = builder.initOmpCriticalDirective(code.num_stmts_of_kind[pasta::StmtKind::kOMPCriticalDirective]);
  OMPDepobjDirective_builder = builder.initOmpDepobjDirective(code.num_stmts_of_kind[pasta::StmtKind::kOMPDepobjDirective]);
  OMPDispatchDirective_builder = builder.initOmpDispatchDirective(code.num_stmts_of_kind[pasta::StmtKind::kOMPDispatchDirective]);
  OMPDistributeDirective_builder = builder.initOmpDistributeDirective(code.num_stmts_of_kind[pasta::StmtKind::kOMPDistributeDirective]);
  OMPDistributeParallelForDirective_builder = builder.initOmpDistributeParallelForDirective(code.num_stmts_of_kind[pasta::StmtKind::kOMPDistributeParallelForDirective]);
  OMPDistributeParallelForSimdDirective_builder = builder.initOmpDistributeParallelForSimdDirective(code.num_stmts_of_kind[pasta::StmtKind::kOMPDistributeParallelForSimdDirective]);
  OMPDistributeSimdDirective_builder = builder.initOmpDistributeSimdDirective(code.num_stmts_of_kind[pasta::StmtKind::kOMPDistributeSimdDirective]);
  OMPForDirective_builder = builder.initOmpForDirective(code.num_stmts_of_kind[pasta::StmtKind::kOMPForDirective]);
  OMPForSimdDirective_builder = builder.initOmpForSimdDirective(code.num_stmts_of_kind[pasta::StmtKind::kOMPForSimdDirective]);
  ObjCBridgedCastExpr_builder = builder.initObjCBridgedCastExpr(code.num_stmts_of_kind[pasta::StmtKind::kObjCBridgedCastExpr]);
  UserDefinedLiteral_builder = builder.initUserDefinedLiteral(code.num_stmts_of_kind[pasta::StmtKind::kUserDefinedLiteral]);
  BuiltinBitCastExpr_builder = builder.initBuiltinBitCastExpr(code.num_stmts_of_kind[pasta::StmtKind::kBuiltinBitCastExpr]);
  CStyleCastExpr_builder = builder.initCStyleCastExpr(code.num_stmts_of_kind[pasta::StmtKind::kCStyleCastExpr]);
  CUDAKernelCallExpr_builder = builder.initCudaKernelCallExpr(code.num_stmts_of_kind[pasta::StmtKind::kCUDAKernelCallExpr]);
  CXXFunctionalCastExpr_builder = builder.initCxxFunctionalCastExpr(code.num_stmts_of_kind[pasta::StmtKind::kCXXFunctionalCastExpr]);
  CXXMemberCallExpr_builder = builder.initCxxMemberCallExpr(code.num_stmts_of_kind[pasta::StmtKind::kCXXMemberCallExpr]);
  CXXOperatorCallExpr_builder = builder.initCxxOperatorCallExpr(code.num_stmts_of_kind[pasta::StmtKind::kCXXOperatorCallExpr]);
  CXXReinterpretCastExpr_builder = builder.initCxxReinterpretCastExpr(code.num_stmts_of_kind[pasta::StmtKind::kCXXReinterpretCastExpr]);
  CXXStaticCastExpr_builder = builder.initCxxStaticCastExpr(code.num_stmts_of_kind[pasta::StmtKind::kCXXStaticCastExpr]);
  CoawaitExpr_builder = builder.initCoawaitExpr(code.num_stmts_of_kind[pasta::StmtKind::kCoawaitExpr]);
  CXXAddrspaceCastExpr_builder = builder.initCxxAddrspaceCastExpr(code.num_stmts_of_kind[pasta::StmtKind::kCXXAddrspaceCastExpr]);
  CXXConstCastExpr_builder = builder.initCxxConstCastExpr(code.num_stmts_of_kind[pasta::StmtKind::kCXXConstCastExpr]);
  CXXDynamicCastExpr_builder = builder.initCxxDynamicCastExpr(code.num_stmts_of_kind[pasta::StmtKind::kCXXDynamicCastExpr]);
  for (const pasta::Decl &decl : code.decls) {
    this->DeclVisitor::Accept(decl);
  }
}

void SerializeCompiler(EntitySerializer &es, mx::ast::Compiler::Builder b, const pasta::Compiler &e) {
  b.setName(static_cast<mx::ast::CompilerName>(mx::FromPasta(e.Name())));
  b.setTargetLanguage(static_cast<mx::ast::TargetLanguage>(mx::FromPasta(e.TargetLanguage())));
  b.setHostTargetTriple(e.HostTargetTriple());
  b.setTargetTriple(e.TargetTriple());
  b.setExecutablePath(e.ExecutablePath().lexically_normal().generic_string());
  b.setResourceDirectory(e.ResourceDirectory().lexically_normal().generic_string());
  b.setSystemRootDirectory(e.SystemRootDirectory().lexically_normal().generic_string());
  b.setSystemRootIncludeDirectory(e.SystemRootIncludeDirectory().lexically_normal().generic_string());
  b.setInstallationDirectory(e.InstallationDirectory().lexically_normal().generic_string());
  auto v9 = e.SystemIncludeDirectories();
  auto sv9 = b.initSystemIncludeDirectories(static_cast<unsigned>(v9.size()));
  auto i9 = 0u;
  for (const auto &e9 : v9) {
    SerializeIncludePath(es, sv9[i9], e9);
    ++i9;
  }
  auto v10 = e.UserIncludeDirectories();
  auto sv10 = b.initUserIncludeDirectories(static_cast<unsigned>(v10.size()));
  auto i10 = 0u;
  for (const auto &e10 : v10) {
    SerializeIncludePath(es, sv10[i10], e10);
    ++i10;
  }
  auto v11 = e.FrameworkDirectories();
  auto sv11 = b.initFrameworkDirectories(static_cast<unsigned>(v11.size()));
  auto i11 = 0u;
  for (const auto &e11 : v11) {
    SerializeIncludePath(es, sv11[i11], e11);
    ++i11;
  }
}

void SerializeIncludePath(EntitySerializer &es, mx::ast::IncludePath::Builder b, const pasta::IncludePath &e) {
  b.setPath(e.Path().lexically_normal().generic_string());
  b.setLocation(static_cast<mx::ast::IncludePathLocation>(mx::FromPasta(e.Location())));
}

void SerializeCompileCommand(EntitySerializer &es, mx::ast::CompileCommand::Builder b, const pasta::CompileCommand &e) {
  const auto &v0 = e.Arguments();
  auto b0 = b.initArguments(static_cast<unsigned>(v0.Size()));
  auto i0 = 0u;
  for (const auto &arg : v0) {
    b0.set(i0++, arg);
  }
  b.setWorkingDirectory(e.WorkingDirectory().lexically_normal().generic_string());
}

void SerializeCompileJob(EntitySerializer &es, mx::ast::CompileJob::Builder b, const pasta::CompileJob &e) {
  const auto &v0 = e.Arguments();
  auto b0 = b.initArguments(static_cast<unsigned>(v0.Size()));
  auto i0 = 0u;
  for (const auto &arg : v0) {
    b0.set(i0++, arg);
  }
  b.setWorkingDirectory(e.WorkingDirectory().lexically_normal().generic_string());
  b.setResourceDirectory(e.ResourceDirectory().lexically_normal().generic_string());
  b.setSystemRootDirectory(e.SystemRootDirectory().lexically_normal().generic_string());
  b.setSystemRootIncludeDirectory(e.SystemRootIncludeDirectory().lexically_normal().generic_string());
  auto v5 = e.TargetTriple();
  std::string s5(v5.data(), v5.size());
  b.setTargetTriple(s5);
  auto v6 = e.AuxiliaryTargetTriple();
  std::string s6(v6.data(), v6.size());
  b.setAuxiliaryTargetTriple(s6);
}

void SerializeTemplateParameterList(EntitySerializer &es, mx::ast::TemplateParameterList::Builder b, const pasta::TemplateParameterList &e) {
  b.setNumParameters(e.NumParameters());
  b.setNumRequiredParameters(e.NumRequiredParameters());
  b.setDepth(e.Depth());
  b.setHasUnexpandedParameterPack(e.HasUnexpandedParameterPack());
  b.setHasParameterPack(e.HasParameterPack());
  b.setTemplateKeywordToken(es.EntityId(e.TemplateKeywordToken()));
  b.setLeftAngleToken(es.EntityId(e.LeftAngleToken()));
  b.setRightAngleToken(es.EntityId(e.RightAngleToken()));
  auto sr8 = b.initTokenRange();
  if (auto r8 = e.TokenRange(); auto rs8 = r8.Size()) {
    sr8.setBeginId(es.EntityId(r8[0]));
    sr8.setEndId(es.EntityId(r8[rs8 - 1u]));
  } else {
    sr8.setBeginId(0);
    sr8.setEndId(0);
  }
  auto v9 = e.Parameters();
  auto sv9 = b.initParameters(static_cast<unsigned>(v9.size()));
  auto i9 = 0u;
  for (const auto &e9 : v9) {
    sv9.set(i9, es.EntityId(e9));
    ++i9;
  }
}

void SerializeTemplateArgument(EntitySerializer &es, mx::ast::TemplateArgument::Builder b, const pasta::TemplateArgument &e) {
  b.setKind(static_cast<mx::ast::TemplateArgumentKind>(mx::FromPasta(e.Kind())));
  b.setIsNull(e.IsNull());
  b.setIsDependent(e.IsDependent());
  b.setIsInstantiationDependent(e.IsInstantiationDependent());
  b.setContainsUnexpandedParameterPack(e.ContainsUnexpandedParameterPack());
  b.setIsPackExpansion(e.IsPackExpansion());
  auto v6 = e.AsDeclaration();
  if (v6) {
    if (auto id6 = es.EntityId(v6.value())) {
      b.setAsDeclaration(id6);
      b.setAsDeclarationIsPresent(true);
    } else {
      b.setAsDeclaration(0);
      b.setAsDeclarationIsPresent(false);
    }
  } else {
    b.setAsDeclaration(0);
    b.setAsDeclarationIsPresent(false);
  }
}

void SerializeCXXBaseSpecifier(EntitySerializer &es, mx::ast::CXXBaseSpecifier::Builder b, const pasta::CXXBaseSpecifier &e) {
  auto sr0 = b.initTokenRange();
  if (auto r0 = e.TokenRange(); auto rs0 = r0.Size()) {
    sr0.setBeginId(es.EntityId(r0[0]));
    sr0.setEndId(es.EntityId(r0[rs0 - 1u]));
  } else {
    sr0.setBeginId(0);
    sr0.setEndId(0);
  }
  b.setBaseTypeToken(es.EntityId(e.BaseTypeToken()));
  b.setIsVirtual(e.IsVirtual());
  b.setBaseKind(static_cast<mx::ast::TagTypeKind>(mx::FromPasta(e.BaseKind())));
  b.setIsPackExpansion(e.IsPackExpansion());
  b.setConstructorsAreInherited(e.ConstructorsAreInherited());
  auto v6 = e.Ellipsis();
  if (v6) {
    if (auto id6 = es.EntityId(v6.value())) {
      b.setEllipsis(id6);
      b.setEllipsisIsPresent(true);
    } else {
      b.setEllipsis(0);
      b.setEllipsisIsPresent(false);
    }
  } else {
    b.setEllipsis(0);
    b.setEllipsisIsPresent(false);
  }
  b.setSemanticAccessSpecifier(static_cast<mx::ast::AccessSpecifier>(mx::FromPasta(e.SemanticAccessSpecifier())));
  b.setLexicalAccessSpecifier(static_cast<mx::ast::AccessSpecifier>(mx::FromPasta(e.LexicalAccessSpecifier())));
}

void SerializeStmt(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::Stmt &e) {
  b.setBeginToken(es.EntityId(e.BeginToken()));
  b.setEndToken(es.EntityId(e.EndToken()));
  auto sr2 = b.initTokenRange();
  if (auto r2 = e.TokenRange(); auto rs2 = r2.Size()) {
    sr2.setBeginId(es.EntityId(r2[0]));
    sr2.setEndId(es.EntityId(r2[rs2 - 1u]));
  } else {
    sr2.setBeginId(0);
    sr2.setEndId(0);
  }
  b.setKind(static_cast<mx::ast::StmtKind>(mx::FromPasta(e.Kind())));
}

void SerializeSEHTryStmt(EntitySerializer &es, mx::ast::SEHTryStmt::Builder b, const pasta::SEHTryStmt &e) {
  SerializeStmt(es, b.initStmt(), e);
  b.setExceptHandler(es.EntityId(e.ExceptHandler()));
  b.setFinallyHandler(es.EntityId(e.FinallyHandler()));
  b.setIsCxxTry(e.IsCXXTry());
  b.setTryBlock(es.EntityId(e.TryBlock()));
  b.setTryToken(es.EntityId(e.TryToken()));
}

void SerializeSEHLeaveStmt(EntitySerializer &es, mx::ast::SEHLeaveStmt::Builder b, const pasta::SEHLeaveStmt &e) {
  SerializeStmt(es, b.initStmt(), e);
  b.setLeaveToken(es.EntityId(e.LeaveToken()));
}

void SerializeSEHFinallyStmt(EntitySerializer &es, mx::ast::SEHFinallyStmt::Builder b, const pasta::SEHFinallyStmt &e) {
  SerializeStmt(es, b.initStmt(), e);
  b.setBlock(es.EntityId(e.Block()));
  b.setFinallyToken(es.EntityId(e.FinallyToken()));
}

void SerializeSEHExceptStmt(EntitySerializer &es, mx::ast::SEHExceptStmt::Builder b, const pasta::SEHExceptStmt &e) {
  SerializeStmt(es, b.initStmt(), e);
  b.setBlock(es.EntityId(e.Block()));
  b.setExceptToken(es.EntityId(e.ExceptToken()));
}

void SerializeReturnStmt(EntitySerializer &es, mx::ast::ReturnStmt::Builder b, const pasta::ReturnStmt &e) {
  SerializeStmt(es, b.initStmt(), e);
  auto v1 = e.NRVOCandidate();
  if (v1) {
    if (auto id1 = es.EntityId(v1.value())) {
      b.setNrvoCandidate(id1);
      b.setNrvoCandidateIsPresent(true);
    } else {
      b.setNrvoCandidate(0);
      b.setNrvoCandidateIsPresent(false);
    }
  } else {
    b.setNrvoCandidate(0);
    b.setNrvoCandidateIsPresent(false);
  }
  b.setReturnToken(es.EntityId(e.ReturnToken()));
}

void SerializeObjCForCollectionStmt(EntitySerializer &es, mx::ast::ObjCForCollectionStmt::Builder b, const pasta::ObjCForCollectionStmt &e) {
  SerializeStmt(es, b.initStmt(), e);
  b.setForToken(es.EntityId(e.ForToken()));
  b.setRParenToken(es.EntityId(e.RParenToken()));
}

void SerializeObjCAutoreleasePoolStmt(EntitySerializer &es, mx::ast::ObjCAutoreleasePoolStmt::Builder b, const pasta::ObjCAutoreleasePoolStmt &e) {
  SerializeStmt(es, b.initStmt(), e);
  b.setAtToken(es.EntityId(e.AtToken()));
}

void SerializeObjCAtTryStmt(EntitySerializer &es, mx::ast::ObjCAtTryStmt::Builder b, const pasta::ObjCAtTryStmt &e) {
  SerializeStmt(es, b.initStmt(), e);
  b.setAtTryToken(es.EntityId(e.AtTryToken()));
  b.setFinallyStatement(es.EntityId(e.FinallyStatement()));
  auto v3 = e.CatchStatements();
  auto sv3 = b.initCatchStatements(static_cast<unsigned>(v3.size()));
  auto i3 = 0u;
  for (const auto &e3 : v3) {
    sv3.set(i3, es.EntityId(e3));
    ++i3;
  }
}

void SerializeObjCAtThrowStmt(EntitySerializer &es, mx::ast::ObjCAtThrowStmt::Builder b, const pasta::ObjCAtThrowStmt &e) {
  SerializeStmt(es, b.initStmt(), e);
  b.setThrowToken(es.EntityId(e.ThrowToken()));
}

void SerializeObjCAtSynchronizedStmt(EntitySerializer &es, mx::ast::ObjCAtSynchronizedStmt::Builder b, const pasta::ObjCAtSynchronizedStmt &e) {
  SerializeStmt(es, b.initStmt(), e);
  b.setAtSynchronizedToken(es.EntityId(e.AtSynchronizedToken()));
  b.setSynchBody(es.EntityId(e.SynchBody()));
}

void SerializeObjCAtFinallyStmt(EntitySerializer &es, mx::ast::ObjCAtFinallyStmt::Builder b, const pasta::ObjCAtFinallyStmt &e) {
  SerializeStmt(es, b.initStmt(), e);
  b.setAtFinallyToken(es.EntityId(e.AtFinallyToken()));
}

void SerializeObjCAtCatchStmt(EntitySerializer &es, mx::ast::ObjCAtCatchStmt::Builder b, const pasta::ObjCAtCatchStmt &e) {
  SerializeStmt(es, b.initStmt(), e);
  b.setAtCatchToken(es.EntityId(e.AtCatchToken()));
  b.setCatchParameterDeclaration(es.EntityId(e.CatchParameterDeclaration()));
  b.setRParenToken(es.EntityId(e.RParenToken()));
  b.setHasEllipsis(e.HasEllipsis());
}

void SerializeOMPExecutableDirective(EntitySerializer &es, mx::ast::OMPExecutableDirective::Builder b, const pasta::OMPExecutableDirective &e) {
  SerializeStmt(es, b.initStmt(), e);
  b.setInnermostCapturedStatement(es.EntityId(e.InnermostCapturedStatement()));
  b.setHasAssociatedStatement(e.HasAssociatedStatement());
  b.setIsStandaloneDirective(e.IsStandaloneDirective());
}

void SerializeOMPDispatchDirective(EntitySerializer &es, mx::ast::OMPDispatchDirective::Builder b, const pasta::OMPDispatchDirective &e) {
  SerializeOMPExecutableDirective(es, b.initOmpExecutableDirective(), e);
  b.setTargetCallToken(es.EntityId(e.TargetCallToken()));
}

void SerializeOMPDepobjDirective(EntitySerializer &es, mx::ast::OMPDepobjDirective::Builder b, const pasta::OMPDepobjDirective &e) {
  SerializeOMPExecutableDirective(es, b.initOmpExecutableDirective(), e);
}

void SerializeOMPCriticalDirective(EntitySerializer &es, mx::ast::OMPCriticalDirective::Builder b, const pasta::OMPCriticalDirective &e) {
  SerializeOMPExecutableDirective(es, b.initOmpExecutableDirective(), e);
}

void SerializeOMPCancellationPointDirective(EntitySerializer &es, mx::ast::OMPCancellationPointDirective::Builder b, const pasta::OMPCancellationPointDirective &e) {
  SerializeOMPExecutableDirective(es, b.initOmpExecutableDirective(), e);
}

void SerializeOMPCancelDirective(EntitySerializer &es, mx::ast::OMPCancelDirective::Builder b, const pasta::OMPCancelDirective &e) {
  SerializeOMPExecutableDirective(es, b.initOmpExecutableDirective(), e);
}

void SerializeOMPBarrierDirective(EntitySerializer &es, mx::ast::OMPBarrierDirective::Builder b, const pasta::OMPBarrierDirective &e) {
  SerializeOMPExecutableDirective(es, b.initOmpExecutableDirective(), e);
}

void SerializeOMPAtomicDirective(EntitySerializer &es, mx::ast::OMPAtomicDirective::Builder b, const pasta::OMPAtomicDirective &e) {
  SerializeOMPExecutableDirective(es, b.initOmpExecutableDirective(), e);
  b.setIsPostfixUpdate(e.IsPostfixUpdate());
  b.setIsXlhsInRhsPart(e.IsXLHSInRHSPart());
}

void SerializeOMPTeamsDirective(EntitySerializer &es, mx::ast::OMPTeamsDirective::Builder b, const pasta::OMPTeamsDirective &e) {
  SerializeOMPExecutableDirective(es, b.initOmpExecutableDirective(), e);
}

void SerializeOMPTaskyieldDirective(EntitySerializer &es, mx::ast::OMPTaskyieldDirective::Builder b, const pasta::OMPTaskyieldDirective &e) {
  SerializeOMPExecutableDirective(es, b.initOmpExecutableDirective(), e);
}

void SerializeOMPTaskwaitDirective(EntitySerializer &es, mx::ast::OMPTaskwaitDirective::Builder b, const pasta::OMPTaskwaitDirective &e) {
  SerializeOMPExecutableDirective(es, b.initOmpExecutableDirective(), e);
}

void SerializeOMPTaskgroupDirective(EntitySerializer &es, mx::ast::OMPTaskgroupDirective::Builder b, const pasta::OMPTaskgroupDirective &e) {
  SerializeOMPExecutableDirective(es, b.initOmpExecutableDirective(), e);
}

void SerializeOMPTaskDirective(EntitySerializer &es, mx::ast::OMPTaskDirective::Builder b, const pasta::OMPTaskDirective &e) {
  SerializeOMPExecutableDirective(es, b.initOmpExecutableDirective(), e);
  b.setHasCancel(e.HasCancel());
}

void SerializeOMPTargetUpdateDirective(EntitySerializer &es, mx::ast::OMPTargetUpdateDirective::Builder b, const pasta::OMPTargetUpdateDirective &e) {
  SerializeOMPExecutableDirective(es, b.initOmpExecutableDirective(), e);
}

void SerializeOMPTargetTeamsDirective(EntitySerializer &es, mx::ast::OMPTargetTeamsDirective::Builder b, const pasta::OMPTargetTeamsDirective &e) {
  SerializeOMPExecutableDirective(es, b.initOmpExecutableDirective(), e);
}

void SerializeOMPTargetParallelDirective(EntitySerializer &es, mx::ast::OMPTargetParallelDirective::Builder b, const pasta::OMPTargetParallelDirective &e) {
  SerializeOMPExecutableDirective(es, b.initOmpExecutableDirective(), e);
  b.setHasCancel(e.HasCancel());
}

void SerializeOMPTargetExitDataDirective(EntitySerializer &es, mx::ast::OMPTargetExitDataDirective::Builder b, const pasta::OMPTargetExitDataDirective &e) {
  SerializeOMPExecutableDirective(es, b.initOmpExecutableDirective(), e);
}

void SerializeOMPTargetEnterDataDirective(EntitySerializer &es, mx::ast::OMPTargetEnterDataDirective::Builder b, const pasta::OMPTargetEnterDataDirective &e) {
  SerializeOMPExecutableDirective(es, b.initOmpExecutableDirective(), e);
}

void SerializeOMPTargetDirective(EntitySerializer &es, mx::ast::OMPTargetDirective::Builder b, const pasta::OMPTargetDirective &e) {
  SerializeOMPExecutableDirective(es, b.initOmpExecutableDirective(), e);
}

void SerializeOMPTargetDataDirective(EntitySerializer &es, mx::ast::OMPTargetDataDirective::Builder b, const pasta::OMPTargetDataDirective &e) {
  SerializeOMPExecutableDirective(es, b.initOmpExecutableDirective(), e);
}

void SerializeOMPSingleDirective(EntitySerializer &es, mx::ast::OMPSingleDirective::Builder b, const pasta::OMPSingleDirective &e) {
  SerializeOMPExecutableDirective(es, b.initOmpExecutableDirective(), e);
}

void SerializeOMPSectionsDirective(EntitySerializer &es, mx::ast::OMPSectionsDirective::Builder b, const pasta::OMPSectionsDirective &e) {
  SerializeOMPExecutableDirective(es, b.initOmpExecutableDirective(), e);
  b.setHasCancel(e.HasCancel());
}

void SerializeOMPSectionDirective(EntitySerializer &es, mx::ast::OMPSectionDirective::Builder b, const pasta::OMPSectionDirective &e) {
  SerializeOMPExecutableDirective(es, b.initOmpExecutableDirective(), e);
  b.setHasCancel(e.HasCancel());
}

void SerializeOMPScanDirective(EntitySerializer &es, mx::ast::OMPScanDirective::Builder b, const pasta::OMPScanDirective &e) {
  SerializeOMPExecutableDirective(es, b.initOmpExecutableDirective(), e);
}

void SerializeOMPParallelSectionsDirective(EntitySerializer &es, mx::ast::OMPParallelSectionsDirective::Builder b, const pasta::OMPParallelSectionsDirective &e) {
  SerializeOMPExecutableDirective(es, b.initOmpExecutableDirective(), e);
  b.setHasCancel(e.HasCancel());
}

void SerializeOMPParallelMasterDirective(EntitySerializer &es, mx::ast::OMPParallelMasterDirective::Builder b, const pasta::OMPParallelMasterDirective &e) {
  SerializeOMPExecutableDirective(es, b.initOmpExecutableDirective(), e);
}

void SerializeOMPParallelDirective(EntitySerializer &es, mx::ast::OMPParallelDirective::Builder b, const pasta::OMPParallelDirective &e) {
  SerializeOMPExecutableDirective(es, b.initOmpExecutableDirective(), e);
  b.setHasCancel(e.HasCancel());
}

void SerializeOMPOrderedDirective(EntitySerializer &es, mx::ast::OMPOrderedDirective::Builder b, const pasta::OMPOrderedDirective &e) {
  SerializeOMPExecutableDirective(es, b.initOmpExecutableDirective(), e);
}

void SerializeOMPMasterDirective(EntitySerializer &es, mx::ast::OMPMasterDirective::Builder b, const pasta::OMPMasterDirective &e) {
  SerializeOMPExecutableDirective(es, b.initOmpExecutableDirective(), e);
}

void SerializeOMPMaskedDirective(EntitySerializer &es, mx::ast::OMPMaskedDirective::Builder b, const pasta::OMPMaskedDirective &e) {
  SerializeOMPExecutableDirective(es, b.initOmpExecutableDirective(), e);
}

void SerializeOMPLoopBasedDirective(EntitySerializer &es, mx::ast::OMPLoopBasedDirective::Builder b, const pasta::OMPLoopBasedDirective &e) {
  SerializeOMPExecutableDirective(es, b.initOmpExecutableDirective(), e);
}

void SerializeOMPUnrollDirective(EntitySerializer &es, mx::ast::OMPUnrollDirective::Builder b, const pasta::OMPUnrollDirective &e) {
  SerializeOMPLoopBasedDirective(es, b.initOmpLoopBasedDirective(), e);
}

void SerializeOMPTileDirective(EntitySerializer &es, mx::ast::OMPTileDirective::Builder b, const pasta::OMPTileDirective &e) {
  SerializeOMPLoopBasedDirective(es, b.initOmpLoopBasedDirective(), e);
}

void SerializeOMPLoopDirective(EntitySerializer &es, mx::ast::OMPLoopDirective::Builder b, const pasta::OMPLoopDirective &e) {
  SerializeOMPLoopBasedDirective(es, b.initOmpLoopBasedDirective(), e);
}

void SerializeOMPForSimdDirective(EntitySerializer &es, mx::ast::OMPForSimdDirective::Builder b, const pasta::OMPForSimdDirective &e) {
  SerializeOMPLoopDirective(es, b.initOmpLoopDirective(), e);
}

void SerializeOMPForDirective(EntitySerializer &es, mx::ast::OMPForDirective::Builder b, const pasta::OMPForDirective &e) {
  SerializeOMPLoopDirective(es, b.initOmpLoopDirective(), e);
  b.setHasCancel(e.HasCancel());
}

void SerializeOMPDistributeSimdDirective(EntitySerializer &es, mx::ast::OMPDistributeSimdDirective::Builder b, const pasta::OMPDistributeSimdDirective &e) {
  SerializeOMPLoopDirective(es, b.initOmpLoopDirective(), e);
}

void SerializeOMPDistributeParallelForSimdDirective(EntitySerializer &es, mx::ast::OMPDistributeParallelForSimdDirective::Builder b, const pasta::OMPDistributeParallelForSimdDirective &e) {
  SerializeOMPLoopDirective(es, b.initOmpLoopDirective(), e);
}

void SerializeOMPDistributeParallelForDirective(EntitySerializer &es, mx::ast::OMPDistributeParallelForDirective::Builder b, const pasta::OMPDistributeParallelForDirective &e) {
  SerializeOMPLoopDirective(es, b.initOmpLoopDirective(), e);
  b.setHasCancel(e.HasCancel());
}

void SerializeOMPDistributeDirective(EntitySerializer &es, mx::ast::OMPDistributeDirective::Builder b, const pasta::OMPDistributeDirective &e) {
  SerializeOMPLoopDirective(es, b.initOmpLoopDirective(), e);
}

void SerializeOMPTeamsDistributeSimdDirective(EntitySerializer &es, mx::ast::OMPTeamsDistributeSimdDirective::Builder b, const pasta::OMPTeamsDistributeSimdDirective &e) {
  SerializeOMPLoopDirective(es, b.initOmpLoopDirective(), e);
}

void SerializeOMPTeamsDistributeParallelForSimdDirective(EntitySerializer &es, mx::ast::OMPTeamsDistributeParallelForSimdDirective::Builder b, const pasta::OMPTeamsDistributeParallelForSimdDirective &e) {
  SerializeOMPLoopDirective(es, b.initOmpLoopDirective(), e);
}

void SerializeOMPTeamsDistributeParallelForDirective(EntitySerializer &es, mx::ast::OMPTeamsDistributeParallelForDirective::Builder b, const pasta::OMPTeamsDistributeParallelForDirective &e) {
  SerializeOMPLoopDirective(es, b.initOmpLoopDirective(), e);
  b.setHasCancel(e.HasCancel());
}

void SerializeOMPTeamsDistributeDirective(EntitySerializer &es, mx::ast::OMPTeamsDistributeDirective::Builder b, const pasta::OMPTeamsDistributeDirective &e) {
  SerializeOMPLoopDirective(es, b.initOmpLoopDirective(), e);
}

void SerializeOMPTaskLoopSimdDirective(EntitySerializer &es, mx::ast::OMPTaskLoopSimdDirective::Builder b, const pasta::OMPTaskLoopSimdDirective &e) {
  SerializeOMPLoopDirective(es, b.initOmpLoopDirective(), e);
}

void SerializeOMPTaskLoopDirective(EntitySerializer &es, mx::ast::OMPTaskLoopDirective::Builder b, const pasta::OMPTaskLoopDirective &e) {
  SerializeOMPLoopDirective(es, b.initOmpLoopDirective(), e);
  b.setHasCancel(e.HasCancel());
}

void SerializeOMPTargetTeamsDistributeSimdDirective(EntitySerializer &es, mx::ast::OMPTargetTeamsDistributeSimdDirective::Builder b, const pasta::OMPTargetTeamsDistributeSimdDirective &e) {
  SerializeOMPLoopDirective(es, b.initOmpLoopDirective(), e);
}

void SerializeOMPTargetTeamsDistributeParallelForSimdDirective(EntitySerializer &es, mx::ast::OMPTargetTeamsDistributeParallelForSimdDirective::Builder b, const pasta::OMPTargetTeamsDistributeParallelForSimdDirective &e) {
  SerializeOMPLoopDirective(es, b.initOmpLoopDirective(), e);
}

void SerializeOMPTargetTeamsDistributeParallelForDirective(EntitySerializer &es, mx::ast::OMPTargetTeamsDistributeParallelForDirective::Builder b, const pasta::OMPTargetTeamsDistributeParallelForDirective &e) {
  SerializeOMPLoopDirective(es, b.initOmpLoopDirective(), e);
  b.setHasCancel(e.HasCancel());
}

void SerializeOMPTargetTeamsDistributeDirective(EntitySerializer &es, mx::ast::OMPTargetTeamsDistributeDirective::Builder b, const pasta::OMPTargetTeamsDistributeDirective &e) {
  SerializeOMPLoopDirective(es, b.initOmpLoopDirective(), e);
}

void SerializeOMPTargetSimdDirective(EntitySerializer &es, mx::ast::OMPTargetSimdDirective::Builder b, const pasta::OMPTargetSimdDirective &e) {
  SerializeOMPLoopDirective(es, b.initOmpLoopDirective(), e);
}

void SerializeOMPTargetParallelForSimdDirective(EntitySerializer &es, mx::ast::OMPTargetParallelForSimdDirective::Builder b, const pasta::OMPTargetParallelForSimdDirective &e) {
  SerializeOMPLoopDirective(es, b.initOmpLoopDirective(), e);
}

void SerializeOMPTargetParallelForDirective(EntitySerializer &es, mx::ast::OMPTargetParallelForDirective::Builder b, const pasta::OMPTargetParallelForDirective &e) {
  SerializeOMPLoopDirective(es, b.initOmpLoopDirective(), e);
  b.setHasCancel(e.HasCancel());
}

void SerializeOMPSimdDirective(EntitySerializer &es, mx::ast::OMPSimdDirective::Builder b, const pasta::OMPSimdDirective &e) {
  SerializeOMPLoopDirective(es, b.initOmpLoopDirective(), e);
}

void SerializeOMPParallelMasterTaskLoopSimdDirective(EntitySerializer &es, mx::ast::OMPParallelMasterTaskLoopSimdDirective::Builder b, const pasta::OMPParallelMasterTaskLoopSimdDirective &e) {
  SerializeOMPLoopDirective(es, b.initOmpLoopDirective(), e);
}

void SerializeOMPParallelMasterTaskLoopDirective(EntitySerializer &es, mx::ast::OMPParallelMasterTaskLoopDirective::Builder b, const pasta::OMPParallelMasterTaskLoopDirective &e) {
  SerializeOMPLoopDirective(es, b.initOmpLoopDirective(), e);
  b.setHasCancel(e.HasCancel());
}

void SerializeOMPParallelForSimdDirective(EntitySerializer &es, mx::ast::OMPParallelForSimdDirective::Builder b, const pasta::OMPParallelForSimdDirective &e) {
  SerializeOMPLoopDirective(es, b.initOmpLoopDirective(), e);
}

void SerializeOMPParallelForDirective(EntitySerializer &es, mx::ast::OMPParallelForDirective::Builder b, const pasta::OMPParallelForDirective &e) {
  SerializeOMPLoopDirective(es, b.initOmpLoopDirective(), e);
  b.setHasCancel(e.HasCancel());
}

void SerializeOMPMasterTaskLoopSimdDirective(EntitySerializer &es, mx::ast::OMPMasterTaskLoopSimdDirective::Builder b, const pasta::OMPMasterTaskLoopSimdDirective &e) {
  SerializeOMPLoopDirective(es, b.initOmpLoopDirective(), e);
}

void SerializeOMPMasterTaskLoopDirective(EntitySerializer &es, mx::ast::OMPMasterTaskLoopDirective::Builder b, const pasta::OMPMasterTaskLoopDirective &e) {
  SerializeOMPLoopDirective(es, b.initOmpLoopDirective(), e);
  b.setHasCancel(e.HasCancel());
}

void SerializeOMPInteropDirective(EntitySerializer &es, mx::ast::OMPInteropDirective::Builder b, const pasta::OMPInteropDirective &e) {
  SerializeOMPExecutableDirective(es, b.initOmpExecutableDirective(), e);
}

void SerializeOMPFlushDirective(EntitySerializer &es, mx::ast::OMPFlushDirective::Builder b, const pasta::OMPFlushDirective &e) {
  SerializeOMPExecutableDirective(es, b.initOmpExecutableDirective(), e);
}

void SerializeOMPCanonicalLoop(EntitySerializer &es, mx::ast::OMPCanonicalLoop::Builder b, const pasta::OMPCanonicalLoop &e) {
  SerializeStmt(es, b.initStmt(), e);
  b.setDistanceFunc(es.EntityId(e.DistanceFunc()));
  b.setLoopVariableFunc(es.EntityId(e.LoopVariableFunc()));
  b.setLoopVariableReference(es.EntityId(e.LoopVariableReference()));
}

void SerializeNullStmt(EntitySerializer &es, mx::ast::NullStmt::Builder b, const pasta::NullStmt &e) {
  SerializeStmt(es, b.initStmt(), e);
  b.setSemiToken(es.EntityId(e.SemiToken()));
  b.setHasLeadingEmptyMacro(e.HasLeadingEmptyMacro());
}

void SerializeMSDependentExistsStmt(EntitySerializer &es, mx::ast::MSDependentExistsStmt::Builder b, const pasta::MSDependentExistsStmt &e) {
  SerializeStmt(es, b.initStmt(), e);
  b.setKeywordToken(es.EntityId(e.KeywordToken()));
  b.setSubStatement(es.EntityId(e.SubStatement()));
  b.setIsIfExists(e.IsIfExists());
  b.setIsIfNotExists(e.IsIfNotExists());
}

void SerializeIndirectGotoStmt(EntitySerializer &es, mx::ast::IndirectGotoStmt::Builder b, const pasta::IndirectGotoStmt &e) {
  SerializeStmt(es, b.initStmt(), e);
  b.setConstantTarget(es.EntityId(e.ConstantTarget()));
  b.setGotoToken(es.EntityId(e.GotoToken()));
  b.setStarToken(es.EntityId(e.StarToken()));
}

void SerializeIfStmt(EntitySerializer &es, mx::ast::IfStmt::Builder b, const pasta::IfStmt &e) {
  SerializeStmt(es, b.initStmt(), e);
  auto v1 = e.ConditionVariable();
  if (v1) {
    if (auto id1 = es.EntityId(v1.value())) {
      b.setConditionVariable(id1);
      b.setConditionVariableIsPresent(true);
    } else {
      b.setConditionVariable(0);
      b.setConditionVariableIsPresent(false);
    }
  } else {
    b.setConditionVariable(0);
    b.setConditionVariableIsPresent(false);
  }
  auto v3 = e.ConditionVariableDeclarationStatement();
  if (v3) {
    if (auto id3 = es.EntityId(v3.value())) {
      b.setConditionVariableDeclarationStatement(id3);
      b.setConditionVariableDeclarationStatementIsPresent(true);
    } else {
      b.setConditionVariableDeclarationStatement(0);
      b.setConditionVariableDeclarationStatementIsPresent(false);
    }
  } else {
    b.setConditionVariableDeclarationStatement(0);
    b.setConditionVariableDeclarationStatementIsPresent(false);
  }
  b.setElseToken(es.EntityId(e.ElseToken()));
  b.setIfToken(es.EntityId(e.IfToken()));
  b.setLParenToken(es.EntityId(e.LParenToken()));
  b.setRParenToken(es.EntityId(e.RParenToken()));
  b.setHasElseStorage(e.HasElseStorage());
  b.setHasInitializerStorage(e.HasInitializerStorage());
  b.setHasVariableStorage(e.HasVariableStorage());
  b.setIsConstexpr(e.IsConstexpr());
  b.setIsObjCAvailabilityCheck(e.IsObjCAvailabilityCheck());
}

void SerializeGotoStmt(EntitySerializer &es, mx::ast::GotoStmt::Builder b, const pasta::GotoStmt &e) {
  SerializeStmt(es, b.initStmt(), e);
  b.setGotoToken(es.EntityId(e.GotoToken()));
  b.setLabel(es.EntityId(e.Label()));
  b.setLabelToken(es.EntityId(e.LabelToken()));
}

void SerializeForStmt(EntitySerializer &es, mx::ast::ForStmt::Builder b, const pasta::ForStmt &e) {
  SerializeStmt(es, b.initStmt(), e);
  auto v1 = e.ConditionVariable();
  if (v1) {
    if (auto id1 = es.EntityId(v1.value())) {
      b.setConditionVariable(id1);
      b.setConditionVariableIsPresent(true);
    } else {
      b.setConditionVariable(0);
      b.setConditionVariableIsPresent(false);
    }
  } else {
    b.setConditionVariable(0);
    b.setConditionVariableIsPresent(false);
  }
  auto v3 = e.ConditionVariableDeclarationStatement();
  if (v3) {
    if (auto id3 = es.EntityId(v3.value())) {
      b.setConditionVariableDeclarationStatement(id3);
      b.setConditionVariableDeclarationStatementIsPresent(true);
    } else {
      b.setConditionVariableDeclarationStatement(0);
      b.setConditionVariableDeclarationStatementIsPresent(false);
    }
  } else {
    b.setConditionVariableDeclarationStatement(0);
    b.setConditionVariableDeclarationStatementIsPresent(false);
  }
  b.setForToken(es.EntityId(e.ForToken()));
  b.setLParenToken(es.EntityId(e.LParenToken()));
  b.setRParenToken(es.EntityId(e.RParenToken()));
}

void SerializeDoStmt(EntitySerializer &es, mx::ast::DoStmt::Builder b, const pasta::DoStmt &e) {
  SerializeStmt(es, b.initStmt(), e);
  b.setDoToken(es.EntityId(e.DoToken()));
  b.setRParenToken(es.EntityId(e.RParenToken()));
  b.setWhileToken(es.EntityId(e.WhileToken()));
}

void SerializeDeclStmt(EntitySerializer &es, mx::ast::DeclStmt::Builder b, const pasta::DeclStmt &e) {
  SerializeStmt(es, b.initStmt(), e);
  b.setIsSingleDeclaration(e.IsSingleDeclaration());
}

void SerializeCoroutineBodyStmt(EntitySerializer &es, mx::ast::CoroutineBodyStmt::Builder b, const pasta::CoroutineBodyStmt &e) {
  SerializeStmt(es, b.initStmt(), e);
  b.setPromiseDeclaration(es.EntityId(e.PromiseDeclaration()));
  b.setHasDependentPromiseType(e.HasDependentPromiseType());
}

void SerializeCoreturnStmt(EntitySerializer &es, mx::ast::CoreturnStmt::Builder b, const pasta::CoreturnStmt &e) {
  SerializeStmt(es, b.initStmt(), e);
  b.setKeywordToken(es.EntityId(e.KeywordToken()));
  b.setIsImplicit(e.IsImplicit());
}

void SerializeContinueStmt(EntitySerializer &es, mx::ast::ContinueStmt::Builder b, const pasta::ContinueStmt &e) {
  SerializeStmt(es, b.initStmt(), e);
  b.setContinueToken(es.EntityId(e.ContinueToken()));
}

void SerializeCompoundStmt(EntitySerializer &es, mx::ast::CompoundStmt::Builder b, const pasta::CompoundStmt &e) {
  SerializeStmt(es, b.initStmt(), e);
  b.setLBracToken(es.EntityId(e.LBracToken()));
  b.setRBracToken(es.EntityId(e.RBracToken()));
}

void SerializeCapturedStmt(EntitySerializer &es, mx::ast::CapturedStmt::Builder b, const pasta::CapturedStmt &e) {
  SerializeStmt(es, b.initStmt(), e);
  b.setCapturedDeclaration(es.EntityId(e.CapturedDeclaration()));
  b.setCapturedRecordDeclaration(es.EntityId(e.CapturedRecordDeclaration()));
  b.setCapturedRegionKind(static_cast<mx::ast::CapturedRegionKind>(mx::FromPasta(e.CapturedRegionKind())));
}

void SerializeCXXTryStmt(EntitySerializer &es, mx::ast::CXXTryStmt::Builder b, const pasta::CXXTryStmt &e) {
  SerializeStmt(es, b.initStmt(), e);
  b.setTryBlock(es.EntityId(e.TryBlock()));
  b.setTryToken(es.EntityId(e.TryToken()));
  auto v3 = e.Handlers();
  auto sv3 = b.initHandlers(static_cast<unsigned>(v3.size()));
  auto i3 = 0u;
  for (const auto &e3 : v3) {
    sv3.set(i3, es.EntityId(e3));
    ++i3;
  }
}

void SerializeCXXForRangeStmt(EntitySerializer &es, mx::ast::CXXForRangeStmt::Builder b, const pasta::CXXForRangeStmt &e) {
  SerializeStmt(es, b.initStmt(), e);
  b.setBeginStatement(es.EntityId(e.BeginStatement()));
  b.setCoawaitToken(es.EntityId(e.CoawaitToken()));
  b.setColonToken(es.EntityId(e.ColonToken()));
  b.setEndStatement(es.EntityId(e.EndStatement()));
  b.setForToken(es.EntityId(e.ForToken()));
  b.setLoopVariableStatement(es.EntityId(e.LoopVariableStatement()));
  b.setLoopVariable(es.EntityId(e.LoopVariable()));
  b.setRParenToken(es.EntityId(e.RParenToken()));
  b.setRangeStatement(es.EntityId(e.RangeStatement()));
}

void SerializeCXXCatchStmt(EntitySerializer &es, mx::ast::CXXCatchStmt::Builder b, const pasta::CXXCatchStmt &e) {
  SerializeStmt(es, b.initStmt(), e);
  b.setCatchToken(es.EntityId(e.CatchToken()));
  b.setExceptionDeclaration(es.EntityId(e.ExceptionDeclaration()));
}

void SerializeBreakStmt(EntitySerializer &es, mx::ast::BreakStmt::Builder b, const pasta::BreakStmt &e) {
  SerializeStmt(es, b.initStmt(), e);
  b.setBreakToken(es.EntityId(e.BreakToken()));
}

void SerializeAsmStmt(EntitySerializer &es, mx::ast::AsmStmt::Builder b, const pasta::AsmStmt &e) {
  SerializeStmt(es, b.initStmt(), e);
  b.setGenerateAssemblyString(e.GenerateAssemblyString());
  b.setAssemblyToken(es.EntityId(e.AssemblyToken()));
  b.setIsSimple(e.IsSimple());
  b.setIsVolatile(e.IsVolatile());
  auto v5 = e.OutputConstraints();
  auto sv5 = b.initOutputConstraints(static_cast<unsigned>(v5.size()));
  auto i5 = 0u;
  for (const auto &e5 : v5) {
    std::string se5(e5.data(), e5.size());
    sv5.set(i5, se5);
    ++i5;
  }
  auto v6 = e.InputConstraints();
  auto sv6 = b.initInputConstraints(static_cast<unsigned>(v6.size()));
  auto i6 = 0u;
  for (const auto &e6 : v6) {
    std::string se6(e6.data(), e6.size());
    sv6.set(i6, se6);
    ++i6;
  }
  auto v7 = e.Clobbers();
  auto sv7 = b.initClobbers(static_cast<unsigned>(v7.size()));
  auto i7 = 0u;
  for (const auto &e7 : v7) {
    std::string se7(e7.data(), e7.size());
    sv7.set(i7, se7);
    ++i7;
  }
}

void SerializeMSAsmStmt(EntitySerializer &es, mx::ast::MSAsmStmt::Builder b, const pasta::MSAsmStmt &e) {
  SerializeAsmStmt(es, b.initAsmStmt(), e);
  auto v1 = e.AllConstraints();
  auto sv1 = b.initAllConstraints(static_cast<unsigned>(v1.size()));
  auto i1 = 0u;
  for (const auto &e1 : v1) {
    std::string se1(e1.data(), e1.size());
    sv1.set(i1, se1);
    ++i1;
  }
  auto v2 = e.AssemblyString();
  std::string s2(v2.data(), v2.size());
  b.setAssemblyString(s2);
  b.setLBraceToken(es.EntityId(e.LBraceToken()));
  b.setHasBraces(e.HasBraces());
}

void SerializeGCCAsmStmt(EntitySerializer &es, mx::ast::GCCAsmStmt::Builder b, const pasta::GCCAsmStmt &e) {
  SerializeAsmStmt(es, b.initAsmStmt(), e);
  b.setAssemblyString(es.EntityId(e.AssemblyString()));
  b.setRParenToken(es.EntityId(e.RParenToken()));
  b.setIsAssemblyGoto(e.IsAssemblyGoto());
  auto v4 = e.Labels();
  auto sv4 = b.initLabels(static_cast<unsigned>(v4.size()));
  auto i4 = 0u;
  for (const auto &e4 : v4) {
    sv4.set(i4, es.EntityId(e4));
    ++i4;
  }
  auto v5 = e.OutputConstraintLiterals();
  auto sv5 = b.initOutputConstraintLiterals(static_cast<unsigned>(v5.size()));
  auto i5 = 0u;
  for (const auto &e5 : v5) {
    sv5.set(i5, es.EntityId(e5));
    ++i5;
  }
  auto v6 = e.OutputNames();
  auto sv6 = b.initOutputNames(static_cast<unsigned>(v6.size()));
  auto i6 = 0u;
  for (const auto &e6 : v6) {
    std::string se6(e6.data(), e6.size());
    sv6.set(i6, se6);
    ++i6;
  }
  auto v7 = e.InputConstraintLiterals();
  auto sv7 = b.initInputConstraintLiterals(static_cast<unsigned>(v7.size()));
  auto i7 = 0u;
  for (const auto &e7 : v7) {
    sv7.set(i7, es.EntityId(e7));
    ++i7;
  }
  auto v8 = e.InputNames();
  auto sv8 = b.initInputNames(static_cast<unsigned>(v8.size()));
  auto i8 = 0u;
  for (const auto &e8 : v8) {
    std::string se8(e8.data(), e8.size());
    sv8.set(i8, se8);
    ++i8;
  }
  auto v9 = e.ClobberStringLiterals();
  auto sv9 = b.initClobberStringLiterals(static_cast<unsigned>(v9.size()));
  auto i9 = 0u;
  for (const auto &e9 : v9) {
    sv9.set(i9, es.EntityId(e9));
    ++i9;
  }
  auto v10 = e.LabelExpressions();
  auto sv10 = b.initLabelExpressions(static_cast<unsigned>(v10.size()));
  auto i10 = 0u;
  for (const auto &e10 : v10) {
    sv10.set(i10, es.EntityId(e10));
    ++i10;
  }
  auto v11 = e.LabelNames();
  auto sv11 = b.initLabelNames(static_cast<unsigned>(v11.size()));
  auto i11 = 0u;
  for (const auto &e11 : v11) {
    std::string se11(e11.data(), e11.size());
    sv11.set(i11, se11);
    ++i11;
  }
}

void SerializeWhileStmt(EntitySerializer &es, mx::ast::WhileStmt::Builder b, const pasta::WhileStmt &e) {
  SerializeStmt(es, b.initStmt(), e);
  auto v1 = e.ConditionVariable();
  if (v1) {
    if (auto id1 = es.EntityId(v1.value())) {
      b.setConditionVariable(id1);
      b.setConditionVariableIsPresent(true);
    } else {
      b.setConditionVariable(0);
      b.setConditionVariableIsPresent(false);
    }
  } else {
    b.setConditionVariable(0);
    b.setConditionVariableIsPresent(false);
  }
  auto v3 = e.ConditionVariableDeclarationStatement();
  if (v3) {
    if (auto id3 = es.EntityId(v3.value())) {
      b.setConditionVariableDeclarationStatement(id3);
      b.setConditionVariableDeclarationStatementIsPresent(true);
    } else {
      b.setConditionVariableDeclarationStatement(0);
      b.setConditionVariableDeclarationStatementIsPresent(false);
    }
  } else {
    b.setConditionVariableDeclarationStatement(0);
    b.setConditionVariableDeclarationStatementIsPresent(false);
  }
  b.setLParenToken(es.EntityId(e.LParenToken()));
  b.setRParenToken(es.EntityId(e.RParenToken()));
  b.setWhileToken(es.EntityId(e.WhileToken()));
  b.setHasVariableStorage(e.HasVariableStorage());
}

void SerializeValueStmt(EntitySerializer &es, mx::ast::ValueStmt::Builder b, const pasta::ValueStmt &e) {
  SerializeStmt(es, b.initStmt(), e);
}

void SerializeLabelStmt(EntitySerializer &es, mx::ast::LabelStmt::Builder b, const pasta::LabelStmt &e) {
  SerializeValueStmt(es, b.initValueStmt(), e);
  b.setDeclaration(es.EntityId(e.Declaration()));
  b.setIdentifierToken(es.EntityId(e.IdentifierToken()));
  auto v3 = e.Name();
  std::string s3(v3.data(), v3.size());
  b.setName(s3);
  b.setIsSideEntry(e.IsSideEntry());
}

void SerializeExpr(EntitySerializer &es, mx::ast::Expr::Builder b, const pasta::Expr &e) {
  SerializeValueStmt(es, b.initValueStmt(), e);
  b.setHasSideEffects(e.HasSideEffects());
  b.setContainsErrors(e.ContainsErrors());
  b.setContainsUnexpandedParameterPack(e.ContainsUnexpandedParameterPack());
  b.setExpressionToken(es.EntityId(e.ExpressionToken()));
  auto v5 = e.ObjCProperty();
  if (v5) {
    if (auto id5 = es.EntityId(v5.value())) {
      b.setObjCProperty(id5);
      b.setObjCPropertyIsPresent(true);
    } else {
      b.setObjCProperty(0);
      b.setObjCPropertyIsPresent(false);
    }
  } else {
    b.setObjCProperty(0);
    b.setObjCPropertyIsPresent(false);
  }
  b.setObjectKind(static_cast<mx::ast::ExprObjectKind>(mx::FromPasta(e.ObjectKind())));
  auto v8 = e.SourceBitField();
  if (v8) {
    if (auto id8 = es.EntityId(v8.value())) {
      b.setSourceBitField(id8);
      b.setSourceBitFieldIsPresent(true);
    } else {
      b.setSourceBitField(0);
      b.setSourceBitFieldIsPresent(false);
    }
  } else {
    b.setSourceBitField(0);
    b.setSourceBitFieldIsPresent(false);
  }
  b.setValueKind(static_cast<mx::ast::ExprValueKind>(mx::FromPasta(e.ValueKind())));
  b.setHasNonTrivialCall(e.HasNonTrivialCall());
  b.setIsDefaultArgument(e.IsDefaultArgument());
  b.setIsGlValue(e.IsGLValue());
  b.setIsImplicitCxxThis(e.IsImplicitCXXThis());
  b.setIsInstantiationDependent(e.IsInstantiationDependent());
  b.setIsKnownToHaveBooleanValue(e.IsKnownToHaveBooleanValue());
  b.setIsLValue(e.IsLValue());
  b.setIsObjcgcCandidate(e.IsOBJCGCCandidate());
  b.setIsObjCSelfExpression(e.IsObjCSelfExpression());
  b.setIsOrdinaryOrBitFieldObject(e.IsOrdinaryOrBitFieldObject());
  b.setIsPrValue(e.IsPRValue());
  b.setIsReadIfDiscardedInCPlusPlus11(e.IsReadIfDiscardedInCPlusPlus11());
  b.setIsTypeDependent(e.IsTypeDependent());
  b.setIsValueDependent(e.IsValueDependent());
  b.setIsXValue(e.IsXValue());
  b.setRefersToBitField(e.RefersToBitField());
  b.setRefersToGlobalRegisterVariable(e.RefersToGlobalRegisterVariable());
  b.setRefersToMatrixElement(e.RefersToMatrixElement());
  b.setRefersToVectorElement(e.RefersToVectorElement());
}

void SerializeDesignatedInitUpdateExpr(EntitySerializer &es, mx::ast::DesignatedInitUpdateExpr::Builder b, const pasta::DesignatedInitUpdateExpr &e) {
  SerializeExpr(es, b.initExpr(), e);
  b.setUpdater(es.EntityId(e.Updater()));
}

void SerializeDesignatedInitExpr(EntitySerializer &es, mx::ast::DesignatedInitExpr::Builder b, const pasta::DesignatedInitExpr &e) {
  SerializeExpr(es, b.initExpr(), e);
  auto sr1 = b.initDesignatorsSourceRange();
  if (auto r1 = e.DesignatorsSourceRange(); auto rs1 = r1.Size()) {
    sr1.setBeginId(es.EntityId(r1[0]));
    sr1.setEndId(es.EntityId(r1[rs1 - 1u]));
  } else {
    sr1.setBeginId(0);
    sr1.setEndId(0);
  }
  b.setEqualOrColonToken(es.EntityId(e.EqualOrColonToken()));
  b.setIsDirectInitializer(e.IsDirectInitializer());
  b.setUsesGnuSyntax(e.UsesGNUSyntax());
}

void SerializeDependentScopeDeclRefExpr(EntitySerializer &es, mx::ast::DependentScopeDeclRefExpr::Builder b, const pasta::DependentScopeDeclRefExpr &e) {
  SerializeExpr(es, b.initExpr(), e);
  b.setLAngleToken(es.EntityId(e.LAngleToken()));
  b.setRAngleToken(es.EntityId(e.RAngleToken()));
  b.setTemplateKeywordToken(es.EntityId(e.TemplateKeywordToken()));
  b.setHasExplicitTemplateArguments(e.HasExplicitTemplateArguments());
  b.setHasTemplateKeyword(e.HasTemplateKeyword());
}

void SerializeDependentCoawaitExpr(EntitySerializer &es, mx::ast::DependentCoawaitExpr::Builder b, const pasta::DependentCoawaitExpr &e) {
  SerializeExpr(es, b.initExpr(), e);
  b.setKeywordToken(es.EntityId(e.KeywordToken()));
  b.setOperatorCoawaitLookup(es.EntityId(e.OperatorCoawaitLookup()));
}

void SerializeDeclRefExpr(EntitySerializer &es, mx::ast::DeclRefExpr::Builder b, const pasta::DeclRefExpr &e) {
  SerializeExpr(es, b.initExpr(), e);
  b.setDeclaration(es.EntityId(e.Declaration()));
  b.setFoundDeclaration(es.EntityId(e.FoundDeclaration()));
  b.setLAngleToken(es.EntityId(e.LAngleToken()));
  b.setRAngleToken(es.EntityId(e.RAngleToken()));
  b.setTemplateKeywordToken(es.EntityId(e.TemplateKeywordToken()));
  b.setHadMultipleCandidates(e.HadMultipleCandidates());
  b.setHasExplicitTemplateArguments(e.HasExplicitTemplateArguments());
  b.setHasQualifier(e.HasQualifier());
  b.setHasTemplateKwAndArgumentsInfo(e.HasTemplateKWAndArgumentsInfo());
  b.setHasTemplateKeyword(e.HasTemplateKeyword());
  b.setIsNonOdrUse(static_cast<mx::ast::NonOdrUseReason>(mx::FromPasta(e.IsNonOdrUse())));
  b.setRefersToEnclosingVariableOrCapture(e.RefersToEnclosingVariableOrCapture());
}

void SerializeCoroutineSuspendExpr(EntitySerializer &es, mx::ast::CoroutineSuspendExpr::Builder b, const pasta::CoroutineSuspendExpr &e) {
  SerializeExpr(es, b.initExpr(), e);
  b.setKeywordToken(es.EntityId(e.KeywordToken()));
  b.setOpaqueValue(es.EntityId(e.OpaqueValue()));
}

void SerializeCoawaitExpr(EntitySerializer &es, mx::ast::CoawaitExpr::Builder b, const pasta::CoawaitExpr &e) {
  SerializeCoroutineSuspendExpr(es, b.initCoroutineSuspendExpr(), e);
  b.setIsImplicit(e.IsImplicit());
}

void SerializeCoyieldExpr(EntitySerializer &es, mx::ast::CoyieldExpr::Builder b, const pasta::CoyieldExpr &e) {
  SerializeCoroutineSuspendExpr(es, b.initCoroutineSuspendExpr(), e);
}

void SerializeConvertVectorExpr(EntitySerializer &es, mx::ast::ConvertVectorExpr::Builder b, const pasta::ConvertVectorExpr &e) {
  SerializeExpr(es, b.initExpr(), e);
  b.setBuiltinToken(es.EntityId(e.BuiltinToken()));
  b.setRParenToken(es.EntityId(e.RParenToken()));
}

void SerializeConceptSpecializationExpr(EntitySerializer &es, mx::ast::ConceptSpecializationExpr::Builder b, const pasta::ConceptSpecializationExpr &e) {
  SerializeExpr(es, b.initExpr(), e);
  auto v1 = e.TemplateArguments();
  auto sv1 = b.initTemplateArguments(static_cast<unsigned>(v1.size()));
  auto i1 = 0u;
  for (const auto &e1 : v1) {
    SerializeTemplateArgument(es, sv1[i1], e1);
    ++i1;
  }
  b.setIsSatisfied(e.IsSatisfied());
}

void SerializeCompoundLiteralExpr(EntitySerializer &es, mx::ast::CompoundLiteralExpr::Builder b, const pasta::CompoundLiteralExpr &e) {
  SerializeExpr(es, b.initExpr(), e);
  b.setLParenToken(es.EntityId(e.LParenToken()));
  b.setIsFileScope(e.IsFileScope());
}

void SerializeChooseExpr(EntitySerializer &es, mx::ast::ChooseExpr::Builder b, const pasta::ChooseExpr &e) {
  SerializeExpr(es, b.initExpr(), e);
  b.setBuiltinToken(es.EntityId(e.BuiltinToken()));
  b.setRParenToken(es.EntityId(e.RParenToken()));
  b.setIsConditionDependent(e.IsConditionDependent());
  b.setIsConditionTrue(e.IsConditionTrue());
}

void SerializeCharacterLiteral(EntitySerializer &es, mx::ast::CharacterLiteral::Builder b, const pasta::CharacterLiteral &e) {
  SerializeExpr(es, b.initExpr(), e);
  b.setToken(es.EntityId(e.Token()));
}

void SerializeCastExpr(EntitySerializer &es, mx::ast::CastExpr::Builder b, const pasta::CastExpr &e) {
  SerializeExpr(es, b.initExpr(), e);
  b.setCastKind(static_cast<mx::ast::CastKind>(mx::FromPasta(e.CastKind())));
  auto v2 = e.CastKindName();
  std::string s2(v2.data(), v2.size());
  b.setCastKindName(s2);
  auto v3 = e.ConversionFunction();
  if (v3) {
    if (auto id3 = es.EntityId(v3.value())) {
      b.setConversionFunction(id3);
      b.setConversionFunctionIsPresent(true);
    } else {
      b.setConversionFunction(0);
      b.setConversionFunctionIsPresent(false);
    }
  } else {
    b.setConversionFunction(0);
    b.setConversionFunctionIsPresent(false);
  }
  auto v5 = e.TargetUnionField();
  if (v5) {
    if (auto id5 = es.EntityId(v5.value())) {
      b.setTargetUnionField(id5);
      b.setTargetUnionFieldIsPresent(true);
    } else {
      b.setTargetUnionField(0);
      b.setTargetUnionFieldIsPresent(false);
    }
  } else {
    b.setTargetUnionField(0);
    b.setTargetUnionFieldIsPresent(false);
  }
  b.setHasStoredFpFeatures(e.HasStoredFPFeatures());
}

void SerializeImplicitCastExpr(EntitySerializer &es, mx::ast::ImplicitCastExpr::Builder b, const pasta::ImplicitCastExpr &e) {
  SerializeCastExpr(es, b.initCastExpr(), e);
  b.setIsPartOfExplicitCast(e.IsPartOfExplicitCast());
}

void SerializeExplicitCastExpr(EntitySerializer &es, mx::ast::ExplicitCastExpr::Builder b, const pasta::ExplicitCastExpr &e) {
  SerializeCastExpr(es, b.initCastExpr(), e);
}

void SerializeCXXNamedCastExpr(EntitySerializer &es, mx::ast::CXXNamedCastExpr::Builder b, const pasta::CXXNamedCastExpr &e) {
  SerializeExplicitCastExpr(es, b.initExplicitCastExpr(), e);
  auto sr1 = b.initAngleBrackets();
  if (auto r1 = e.AngleBrackets(); auto rs1 = r1.Size()) {
    sr1.setBeginId(es.EntityId(r1[0]));
    sr1.setEndId(es.EntityId(r1[rs1 - 1u]));
  } else {
    sr1.setBeginId(0);
    sr1.setEndId(0);
  }
  auto v2 = e.CastName();
  std::string s2(v2.data(), v2.size());
  b.setCastName(s2);
  b.setOperatorToken(es.EntityId(e.OperatorToken()));
  b.setRParenToken(es.EntityId(e.RParenToken()));
}

void SerializeCXXDynamicCastExpr(EntitySerializer &es, mx::ast::CXXDynamicCastExpr::Builder b, const pasta::CXXDynamicCastExpr &e) {
  SerializeCXXNamedCastExpr(es, b.initCxxNamedCastExpr(), e);
  b.setIsAlwaysNull(e.IsAlwaysNull());
}

void SerializeCXXConstCastExpr(EntitySerializer &es, mx::ast::CXXConstCastExpr::Builder b, const pasta::CXXConstCastExpr &e) {
  SerializeCXXNamedCastExpr(es, b.initCxxNamedCastExpr(), e);
}

void SerializeCXXAddrspaceCastExpr(EntitySerializer &es, mx::ast::CXXAddrspaceCastExpr::Builder b, const pasta::CXXAddrspaceCastExpr &e) {
  SerializeCXXNamedCastExpr(es, b.initCxxNamedCastExpr(), e);
}

void SerializeCXXStaticCastExpr(EntitySerializer &es, mx::ast::CXXStaticCastExpr::Builder b, const pasta::CXXStaticCastExpr &e) {
  SerializeCXXNamedCastExpr(es, b.initCxxNamedCastExpr(), e);
}

void SerializeCXXReinterpretCastExpr(EntitySerializer &es, mx::ast::CXXReinterpretCastExpr::Builder b, const pasta::CXXReinterpretCastExpr &e) {
  SerializeCXXNamedCastExpr(es, b.initCxxNamedCastExpr(), e);
}

void SerializeCXXFunctionalCastExpr(EntitySerializer &es, mx::ast::CXXFunctionalCastExpr::Builder b, const pasta::CXXFunctionalCastExpr &e) {
  SerializeExplicitCastExpr(es, b.initExplicitCastExpr(), e);
  b.setLParenToken(es.EntityId(e.LParenToken()));
  b.setRParenToken(es.EntityId(e.RParenToken()));
  b.setIsListInitialization(e.IsListInitialization());
}

void SerializeCStyleCastExpr(EntitySerializer &es, mx::ast::CStyleCastExpr::Builder b, const pasta::CStyleCastExpr &e) {
  SerializeExplicitCastExpr(es, b.initExplicitCastExpr(), e);
  b.setLParenToken(es.EntityId(e.LParenToken()));
  b.setRParenToken(es.EntityId(e.RParenToken()));
}

void SerializeBuiltinBitCastExpr(EntitySerializer &es, mx::ast::BuiltinBitCastExpr::Builder b, const pasta::BuiltinBitCastExpr &e) {
  SerializeExplicitCastExpr(es, b.initExplicitCastExpr(), e);
}

void SerializeObjCBridgedCastExpr(EntitySerializer &es, mx::ast::ObjCBridgedCastExpr::Builder b, const pasta::ObjCBridgedCastExpr &e) {
  SerializeExplicitCastExpr(es, b.initExplicitCastExpr(), e);
  b.setBridgeKeywordToken(es.EntityId(e.BridgeKeywordToken()));
  b.setBridgeKind(static_cast<mx::ast::ObjCBridgeCastKind>(mx::FromPasta(e.BridgeKind())));
  auto v3 = e.BridgeKindName();
  std::string s3(v3.data(), v3.size());
  b.setBridgeKindName(s3);
  b.setLParenToken(es.EntityId(e.LParenToken()));
}

void SerializeCallExpr(EntitySerializer &es, mx::ast::CallExpr::Builder b, const pasta::CallExpr &e) {
  SerializeExpr(es, b.initExpr(), e);
  b.setAdlCallKind(static_cast<mx::ast::CallExprADLCallKind>(mx::FromPasta(e.ADLCallKind())));
  auto v2 = e.DirectCallee();
  if (v2) {
    if (auto id2 = es.EntityId(v2.value())) {
      b.setDirectCallee(id2);
      b.setDirectCalleeIsPresent(true);
    } else {
      b.setDirectCallee(0);
      b.setDirectCalleeIsPresent(false);
    }
  } else {
    b.setDirectCallee(0);
    b.setDirectCalleeIsPresent(false);
  }
  b.setRParenToken(es.EntityId(e.RParenToken()));
  b.setHasStoredFpFeatures(e.HasStoredFPFeatures());
  b.setHasUnusedResultAttribute(e.HasUnusedResultAttribute());
  b.setIsBuiltinAssumeFalse(e.IsBuiltinAssumeFalse());
  b.setIsCallToStdMove(e.IsCallToStdMove());
  b.setIsUnevaluatedBuiltinCall(e.IsUnevaluatedBuiltinCall());
  b.setUsesAdl(e.UsesADL());
}

void SerializeCXXOperatorCallExpr(EntitySerializer &es, mx::ast::CXXOperatorCallExpr::Builder b, const pasta::CXXOperatorCallExpr &e) {
  SerializeCallExpr(es, b.initCallExpr(), e);
  b.setOperator(static_cast<mx::ast::OverloadedOperatorKind>(mx::FromPasta(e.Operator())));
  b.setOperatorToken(es.EntityId(e.OperatorToken()));
  b.setIsAssignmentOperation(e.IsAssignmentOperation());
  b.setIsComparisonOperation(e.IsComparisonOperation());
  b.setIsInfixBinaryOperation(e.IsInfixBinaryOperation());
}

void SerializeCXXMemberCallExpr(EntitySerializer &es, mx::ast::CXXMemberCallExpr::Builder b, const pasta::CXXMemberCallExpr &e) {
  SerializeCallExpr(es, b.initCallExpr(), e);
  b.setMethodDeclaration(es.EntityId(e.MethodDeclaration()));
  b.setRecordDeclaration(es.EntityId(e.RecordDeclaration()));
}

void SerializeCUDAKernelCallExpr(EntitySerializer &es, mx::ast::CUDAKernelCallExpr::Builder b, const pasta::CUDAKernelCallExpr &e) {
  SerializeCallExpr(es, b.initCallExpr(), e);
  b.setConfig(es.EntityId(e.Config()));
}

void SerializeUserDefinedLiteral(EntitySerializer &es, mx::ast::UserDefinedLiteral::Builder b, const pasta::UserDefinedLiteral &e) {
  SerializeCallExpr(es, b.initCallExpr(), e);
  b.setLiteralOperatorKind(static_cast<mx::ast::UserDefinedLiteralLiteralOperatorKind>(mx::FromPasta(e.LiteralOperatorKind())));
  b.setUdSuffixToken(es.EntityId(e.UDSuffixToken()));
}

void SerializeCXXUuidofExpr(EntitySerializer &es, mx::ast::CXXUuidofExpr::Builder b, const pasta::CXXUuidofExpr &e) {
  SerializeExpr(es, b.initExpr(), e);
  b.setGuidDeclaration(es.EntityId(e.GuidDeclaration()));
  b.setIsTypeOperand(e.IsTypeOperand());
}

void SerializeCXXUnresolvedConstructExpr(EntitySerializer &es, mx::ast::CXXUnresolvedConstructExpr::Builder b, const pasta::CXXUnresolvedConstructExpr &e) {
  SerializeExpr(es, b.initExpr(), e);
  b.setLParenToken(es.EntityId(e.LParenToken()));
  b.setRParenToken(es.EntityId(e.RParenToken()));
  b.setIsListInitialization(e.IsListInitialization());
}

void SerializeCXXTypeidExpr(EntitySerializer &es, mx::ast::CXXTypeidExpr::Builder b, const pasta::CXXTypeidExpr &e) {
  SerializeExpr(es, b.initExpr(), e);
  b.setIsMostDerived(e.IsMostDerived());
  b.setIsPotentiallyEvaluated(e.IsPotentiallyEvaluated());
  b.setIsTypeOperand(e.IsTypeOperand());
}

void SerializeCXXThrowExpr(EntitySerializer &es, mx::ast::CXXThrowExpr::Builder b, const pasta::CXXThrowExpr &e) {
  SerializeExpr(es, b.initExpr(), e);
  b.setThrowToken(es.EntityId(e.ThrowToken()));
  b.setIsThrownVariableInScope(e.IsThrownVariableInScope());
}

void SerializeCXXThisExpr(EntitySerializer &es, mx::ast::CXXThisExpr::Builder b, const pasta::CXXThisExpr &e) {
  SerializeExpr(es, b.initExpr(), e);
  b.setToken(es.EntityId(e.Token()));
  b.setIsImplicit(e.IsImplicit());
}

void SerializeCXXStdInitializerListExpr(EntitySerializer &es, mx::ast::CXXStdInitializerListExpr::Builder b, const pasta::CXXStdInitializerListExpr &e) {
  SerializeExpr(es, b.initExpr(), e);
}

void SerializeCXXScalarValueInitExpr(EntitySerializer &es, mx::ast::CXXScalarValueInitExpr::Builder b, const pasta::CXXScalarValueInitExpr &e) {
  SerializeExpr(es, b.initExpr(), e);
  b.setRParenToken(es.EntityId(e.RParenToken()));
}

void SerializeCXXRewrittenBinaryOperator(EntitySerializer &es, mx::ast::CXXRewrittenBinaryOperator::Builder b, const pasta::CXXRewrittenBinaryOperator &e) {
  SerializeExpr(es, b.initExpr(), e);
  b.setOpcode(static_cast<mx::ast::BinaryOperatorKind>(mx::FromPasta(e.Opcode())));
  auto v2 = e.OpcodeString();
  std::string s2(v2.data(), v2.size());
  b.setOpcodeString(s2);
  b.setOperator(static_cast<mx::ast::BinaryOperatorKind>(mx::FromPasta(e.Operator())));
  b.setOperatorToken(es.EntityId(e.OperatorToken()));
  b.setIsAssignmentOperation(e.IsAssignmentOperation());
  b.setIsComparisonOperation(e.IsComparisonOperation());
  b.setIsReversed(e.IsReversed());
}

void SerializeCXXPseudoDestructorExpr(EntitySerializer &es, mx::ast::CXXPseudoDestructorExpr::Builder b, const pasta::CXXPseudoDestructorExpr &e) {
  SerializeExpr(es, b.initExpr(), e);
  b.setColonColonToken(es.EntityId(e.ColonColonToken()));
  b.setDestroyedTypeToken(es.EntityId(e.DestroyedTypeToken()));
  b.setOperatorToken(es.EntityId(e.OperatorToken()));
  b.setTildeToken(es.EntityId(e.TildeToken()));
  b.setHasQualifier(e.HasQualifier());
  b.setIsArrow(e.IsArrow());
}

void SerializeCXXNullPtrLiteralExpr(EntitySerializer &es, mx::ast::CXXNullPtrLiteralExpr::Builder b, const pasta::CXXNullPtrLiteralExpr &e) {
  SerializeExpr(es, b.initExpr(), e);
  b.setToken(es.EntityId(e.Token()));
}

void SerializeCXXNoexceptExpr(EntitySerializer &es, mx::ast::CXXNoexceptExpr::Builder b, const pasta::CXXNoexceptExpr &e) {
  SerializeExpr(es, b.initExpr(), e);
  b.setValue(e.Value());
}

void SerializeCXXNewExpr(EntitySerializer &es, mx::ast::CXXNewExpr::Builder b, const pasta::CXXNewExpr &e) {
  SerializeExpr(es, b.initExpr(), e);
  b.setDoesUsualArrayDeleteWantSize(e.DoesUsualArrayDeleteWantSize());
  b.setConstructExpression(es.EntityId(e.ConstructExpression()));
  auto sr3 = b.initDirectInitializerRange();
  if (auto r3 = e.DirectInitializerRange(); auto rs3 = r3.Size()) {
    sr3.setBeginId(es.EntityId(r3[0]));
    sr3.setEndId(es.EntityId(r3[rs3 - 1u]));
  } else {
    sr3.setBeginId(0);
    sr3.setEndId(0);
  }
  b.setInitializationStyle(static_cast<mx::ast::CXXNewExprInitializationStyle>(mx::FromPasta(e.InitializationStyle())));
  b.setOperatorDelete(es.EntityId(e.OperatorDelete()));
  b.setOperatorNew(es.EntityId(e.OperatorNew()));
  auto sr7 = b.initTypeIdParentheses();
  if (auto r7 = e.TypeIdParentheses(); auto rs7 = r7.Size()) {
    sr7.setBeginId(es.EntityId(r7[0]));
    sr7.setEndId(es.EntityId(r7[rs7 - 1u]));
  } else {
    sr7.setBeginId(0);
    sr7.setEndId(0);
  }
  b.setHasInitializer(e.HasInitializer());
  b.setIsArray(e.IsArray());
  b.setIsGlobalNew(e.IsGlobalNew());
  b.setIsParenthesisTypeId(e.IsParenthesisTypeId());
  b.setPassAlignment(e.PassAlignment());
  b.setShouldNullCheckAllocation(e.ShouldNullCheckAllocation());
}

void SerializeCXXInheritedCtorInitExpr(EntitySerializer &es, mx::ast::CXXInheritedCtorInitExpr::Builder b, const pasta::CXXInheritedCtorInitExpr &e) {
  SerializeExpr(es, b.initExpr(), e);
  b.setConstructsVirtualBase(e.ConstructsVirtualBase());
  b.setConstructionKind(static_cast<mx::ast::CXXConstructExprConstructionKind>(mx::FromPasta(e.ConstructionKind())));
  b.setConstructor(es.EntityId(e.Constructor()));
  b.setToken(es.EntityId(e.Token()));
  b.setInheritedFromVirtualBase(e.InheritedFromVirtualBase());
}

void SerializeCXXFoldExpr(EntitySerializer &es, mx::ast::CXXFoldExpr::Builder b, const pasta::CXXFoldExpr &e) {
  SerializeExpr(es, b.initExpr(), e);
  b.setCallee(es.EntityId(e.Callee()));
  b.setEllipsisToken(es.EntityId(e.EllipsisToken()));
  b.setLParenToken(es.EntityId(e.LParenToken()));
  b.setOperator(static_cast<mx::ast::BinaryOperatorKind>(mx::FromPasta(e.Operator())));
  b.setRParenToken(es.EntityId(e.RParenToken()));
  b.setIsLeftFold(e.IsLeftFold());
  b.setIsRightFold(e.IsRightFold());
}

void SerializeCXXDependentScopeMemberExpr(EntitySerializer &es, mx::ast::CXXDependentScopeMemberExpr::Builder b, const pasta::CXXDependentScopeMemberExpr &e) {
  SerializeExpr(es, b.initExpr(), e);
  b.setFirstQualifierFoundInScope(es.EntityId(e.FirstQualifierFoundInScope()));
  b.setLAngleToken(es.EntityId(e.LAngleToken()));
  b.setMemberToken(es.EntityId(e.MemberToken()));
  b.setOperatorToken(es.EntityId(e.OperatorToken()));
  b.setRAngleToken(es.EntityId(e.RAngleToken()));
  b.setTemplateKeywordToken(es.EntityId(e.TemplateKeywordToken()));
  b.setHasExplicitTemplateArguments(e.HasExplicitTemplateArguments());
  b.setHasTemplateKeyword(e.HasTemplateKeyword());
  b.setIsArrow(e.IsArrow());
  b.setIsImplicitAccess(e.IsImplicitAccess());
}

void SerializeCXXDeleteExpr(EntitySerializer &es, mx::ast::CXXDeleteExpr::Builder b, const pasta::CXXDeleteExpr &e) {
  SerializeExpr(es, b.initExpr(), e);
  b.setDoesUsualArrayDeleteWantSize(e.DoesUsualArrayDeleteWantSize());
  b.setOperatorDelete(es.EntityId(e.OperatorDelete()));
  b.setIsArrayForm(e.IsArrayForm());
  b.setIsArrayFormAsWritten(e.IsArrayFormAsWritten());
  b.setIsGlobalDelete(e.IsGlobalDelete());
}

void SerializeCXXDefaultInitExpr(EntitySerializer &es, mx::ast::CXXDefaultInitExpr::Builder b, const pasta::CXXDefaultInitExpr &e) {
  SerializeExpr(es, b.initExpr(), e);
  b.setField(es.EntityId(e.Field()));
  b.setUsedToken(es.EntityId(e.UsedToken()));
}

void SerializeCXXDefaultArgExpr(EntitySerializer &es, mx::ast::CXXDefaultArgExpr::Builder b, const pasta::CXXDefaultArgExpr &e) {
  SerializeExpr(es, b.initExpr(), e);
  b.setParameter(es.EntityId(e.Parameter()));
  b.setUsedToken(es.EntityId(e.UsedToken()));
}

void SerializeCXXConstructExpr(EntitySerializer &es, mx::ast::CXXConstructExpr::Builder b, const pasta::CXXConstructExpr &e) {
  SerializeExpr(es, b.initExpr(), e);
  b.setConstructionKind(static_cast<mx::ast::CXXConstructExprConstructionKind>(mx::FromPasta(e.ConstructionKind())));
  b.setConstructor(es.EntityId(e.Constructor()));
  b.setToken(es.EntityId(e.Token()));
  auto sr4 = b.initParenthesisOrBraceRange();
  if (auto r4 = e.ParenthesisOrBraceRange(); auto rs4 = r4.Size()) {
    sr4.setBeginId(es.EntityId(r4[0]));
    sr4.setEndId(es.EntityId(r4[rs4 - 1u]));
  } else {
    sr4.setBeginId(0);
    sr4.setEndId(0);
  }
  b.setHadMultipleCandidates(e.HadMultipleCandidates());
  b.setIsElidable(e.IsElidable());
  b.setIsListInitialization(e.IsListInitialization());
  b.setIsStdInitializerListInitialization(e.IsStdInitializerListInitialization());
  b.setRequiresZeroInitialization(e.RequiresZeroInitialization());
}

void SerializeCXXTemporaryObjectExpr(EntitySerializer &es, mx::ast::CXXTemporaryObjectExpr::Builder b, const pasta::CXXTemporaryObjectExpr &e) {
  SerializeCXXConstructExpr(es, b.initCxxConstructExpr(), e);
}

void SerializeCXXBoolLiteralExpr(EntitySerializer &es, mx::ast::CXXBoolLiteralExpr::Builder b, const pasta::CXXBoolLiteralExpr &e) {
  SerializeExpr(es, b.initExpr(), e);
  b.setToken(es.EntityId(e.Token()));
  b.setValue(e.Value());
}

void SerializeCXXBindTemporaryExpr(EntitySerializer &es, mx::ast::CXXBindTemporaryExpr::Builder b, const pasta::CXXBindTemporaryExpr &e) {
  SerializeExpr(es, b.initExpr(), e);
}

void SerializeBlockExpr(EntitySerializer &es, mx::ast::BlockExpr::Builder b, const pasta::BlockExpr &e) {
  SerializeExpr(es, b.initExpr(), e);
  b.setBlockDeclaration(es.EntityId(e.BlockDeclaration()));
  b.setCaretToken(es.EntityId(e.CaretToken()));
}

void SerializeBinaryOperator(EntitySerializer &es, mx::ast::BinaryOperator::Builder b, const pasta::BinaryOperator &e) {
  SerializeExpr(es, b.initExpr(), e);
  b.setOpcode(static_cast<mx::ast::BinaryOperatorKind>(mx::FromPasta(e.Opcode())));
  auto v2 = e.OpcodeString();
  std::string s2(v2.data(), v2.size());
  b.setOpcodeString(s2);
  b.setOperatorToken(es.EntityId(e.OperatorToken()));
  b.setHasStoredFpFeatures(e.HasStoredFPFeatures());
  b.setIsAdditiveOperation(e.IsAdditiveOperation());
  b.setIsAssignmentOperation(e.IsAssignmentOperation());
  b.setIsBitwiseOperation(e.IsBitwiseOperation());
  b.setIsCommaOperation(e.IsCommaOperation());
  b.setIsComparisonOperation(e.IsComparisonOperation());
  b.setIsCompoundAssignmentOperation(e.IsCompoundAssignmentOperation());
  b.setIsEqualityOperation(e.IsEqualityOperation());
  b.setIsLogicalOperation(e.IsLogicalOperation());
  b.setIsMultiplicativeOperation(e.IsMultiplicativeOperation());
  b.setIsPointerMemoryOperation(e.IsPointerMemoryOperation());
  b.setIsRelationalOperation(e.IsRelationalOperation());
  b.setIsShiftAssignOperation(e.IsShiftAssignOperation());
  b.setIsShiftOperation(e.IsShiftOperation());
}

void SerializeCompoundAssignOperator(EntitySerializer &es, mx::ast::CompoundAssignOperator::Builder b, const pasta::CompoundAssignOperator &e) {
  SerializeBinaryOperator(es, b.initBinaryOperator(), e);
}

void SerializeAtomicExpr(EntitySerializer &es, mx::ast::AtomicExpr::Builder b, const pasta::AtomicExpr &e) {
  SerializeExpr(es, b.initExpr(), e);
  b.setBuiltinToken(es.EntityId(e.BuiltinToken()));
  b.setOperation(static_cast<mx::ast::AtomicExprAtomicOp>(mx::FromPasta(e.Operation())));
  b.setRParenToken(es.EntityId(e.RParenToken()));
  b.setIsCmpXChg(e.IsCmpXChg());
  b.setIsOpenCl(e.IsOpenCL());
  b.setIsVolatile(e.IsVolatile());
}

void SerializeAsTypeExpr(EntitySerializer &es, mx::ast::AsTypeExpr::Builder b, const pasta::AsTypeExpr &e) {
  SerializeExpr(es, b.initExpr(), e);
  b.setBuiltinToken(es.EntityId(e.BuiltinToken()));
  b.setRParenToken(es.EntityId(e.RParenToken()));
}

void SerializeArrayTypeTraitExpr(EntitySerializer &es, mx::ast::ArrayTypeTraitExpr::Builder b, const pasta::ArrayTypeTraitExpr &e) {
  SerializeExpr(es, b.initExpr(), e);
  b.setTrait(static_cast<mx::ast::ArrayTypeTrait>(mx::FromPasta(e.Trait())));
}

void SerializeArraySubscriptExpr(EntitySerializer &es, mx::ast::ArraySubscriptExpr::Builder b, const pasta::ArraySubscriptExpr &e) {
  SerializeExpr(es, b.initExpr(), e);
  b.setRBracketToken(es.EntityId(e.RBracketToken()));
}

void SerializeArrayInitLoopExpr(EntitySerializer &es, mx::ast::ArrayInitLoopExpr::Builder b, const pasta::ArrayInitLoopExpr &e) {
  SerializeExpr(es, b.initExpr(), e);
  b.setCommonExpression(es.EntityId(e.CommonExpression()));
}

void SerializeArrayInitIndexExpr(EntitySerializer &es, mx::ast::ArrayInitIndexExpr::Builder b, const pasta::ArrayInitIndexExpr &e) {
  SerializeExpr(es, b.initExpr(), e);
}

void SerializeAddrLabelExpr(EntitySerializer &es, mx::ast::AddrLabelExpr::Builder b, const pasta::AddrLabelExpr &e) {
  SerializeExpr(es, b.initExpr(), e);
  b.setAmpAmpToken(es.EntityId(e.AmpAmpToken()));
  b.setLabel(es.EntityId(e.Label()));
  b.setLabelToken(es.EntityId(e.LabelToken()));
}

void SerializeAbstractConditionalOperator(EntitySerializer &es, mx::ast::AbstractConditionalOperator::Builder b, const pasta::AbstractConditionalOperator &e) {
  SerializeExpr(es, b.initExpr(), e);
  b.setColonToken(es.EntityId(e.ColonToken()));
  b.setQuestionToken(es.EntityId(e.QuestionToken()));
}

void SerializeConditionalOperator(EntitySerializer &es, mx::ast::ConditionalOperator::Builder b, const pasta::ConditionalOperator &e) {
  SerializeAbstractConditionalOperator(es, b.initAbstractConditionalOperator(), e);
}

void SerializeBinaryConditionalOperator(EntitySerializer &es, mx::ast::BinaryConditionalOperator::Builder b, const pasta::BinaryConditionalOperator &e) {
  SerializeAbstractConditionalOperator(es, b.initAbstractConditionalOperator(), e);
  b.setOpaqueValue(es.EntityId(e.OpaqueValue()));
}

void SerializeVAArgExpr(EntitySerializer &es, mx::ast::VAArgExpr::Builder b, const pasta::VAArgExpr &e) {
  SerializeExpr(es, b.initExpr(), e);
  b.setBuiltinToken(es.EntityId(e.BuiltinToken()));
  b.setRParenToken(es.EntityId(e.RParenToken()));
  b.setIsMicrosoftAbi(e.IsMicrosoftABI());
}

void SerializeUnaryOperator(EntitySerializer &es, mx::ast::UnaryOperator::Builder b, const pasta::UnaryOperator &e) {
  SerializeExpr(es, b.initExpr(), e);
  b.setCanOverflow(e.CanOverflow());
  b.setOpcode(static_cast<mx::ast::UnaryOperatorKind>(mx::FromPasta(e.Opcode())));
  b.setOperatorToken(es.EntityId(e.OperatorToken()));
  b.setHasStoredFpFeatures(e.HasStoredFPFeatures());
  b.setIsArithmeticOperation(e.IsArithmeticOperation());
  b.setIsDecrementOperation(e.IsDecrementOperation());
  b.setIsIncrementDecrementOperation(e.IsIncrementDecrementOperation());
  b.setIsIncrementOperation(e.IsIncrementOperation());
  b.setIsPostfix(e.IsPostfix());
  b.setIsPrefix(e.IsPrefix());
}

void SerializeUnaryExprOrTypeTraitExpr(EntitySerializer &es, mx::ast::UnaryExprOrTypeTraitExpr::Builder b, const pasta::UnaryExprOrTypeTraitExpr &e) {
  SerializeExpr(es, b.initExpr(), e);
  b.setOperatorToken(es.EntityId(e.OperatorToken()));
  b.setRParenToken(es.EntityId(e.RParenToken()));
  b.setIsArgumentType(e.IsArgumentType());
}

void SerializeTypoExpr(EntitySerializer &es, mx::ast::TypoExpr::Builder b, const pasta::TypoExpr &e) {
  SerializeExpr(es, b.initExpr(), e);
}

void SerializeTypeTraitExpr(EntitySerializer &es, mx::ast::TypeTraitExpr::Builder b, const pasta::TypeTraitExpr &e) {
  SerializeExpr(es, b.initExpr(), e);
  b.setTrait(static_cast<mx::ast::TypeTrait>(mx::FromPasta(e.Trait())));
  b.setValue(e.Value());
}

void SerializeSubstNonTypeTemplateParmPackExpr(EntitySerializer &es, mx::ast::SubstNonTypeTemplateParmPackExpr::Builder b, const pasta::SubstNonTypeTemplateParmPackExpr &e) {
  SerializeExpr(es, b.initExpr(), e);
  b.setParameterPack(es.EntityId(e.ParameterPack()));
  b.setParameterPackToken(es.EntityId(e.ParameterPackToken()));
}

void SerializeSubstNonTypeTemplateParmExpr(EntitySerializer &es, mx::ast::SubstNonTypeTemplateParmExpr::Builder b, const pasta::SubstNonTypeTemplateParmExpr &e) {
  SerializeExpr(es, b.initExpr(), e);
  b.setNameToken(es.EntityId(e.NameToken()));
  b.setParameter(es.EntityId(e.Parameter()));
  b.setIsReferenceParameter(e.IsReferenceParameter());
}

void SerializeStringLiteral(EntitySerializer &es, mx::ast::StringLiteral::Builder b, const pasta::StringLiteral &e) {
  SerializeExpr(es, b.initExpr(), e);
  b.setContainsNonAscii(e.ContainsNonAscii());
  b.setContainsNonAsciiOrNull(e.ContainsNonAsciiOrNull());
  auto v3 = e.Bytes();
  std::string s3(v3.data(), v3.size());
  b.setBytes(s3);
  auto v4 = e.String();
  std::string s4(v4.data(), v4.size());
  b.setString(s4);
  b.setIsAscii(e.IsAscii());
  b.setIsPascal(e.IsPascal());
  b.setIsUtf16(e.IsUTF16());
  b.setIsUtf32(e.IsUTF32());
  b.setIsUtf8(e.IsUTF8());
  b.setIsWide(e.IsWide());
}

void SerializeStmtExpr(EntitySerializer &es, mx::ast::StmtExpr::Builder b, const pasta::StmtExpr &e) {
  SerializeExpr(es, b.initExpr(), e);
  b.setLParenToken(es.EntityId(e.LParenToken()));
  b.setRParenToken(es.EntityId(e.RParenToken()));
  b.setSubStatement(es.EntityId(e.SubStatement()));
}

void SerializeSourceLocExpr(EntitySerializer &es, mx::ast::SourceLocExpr::Builder b, const pasta::SourceLocExpr &e) {
  SerializeExpr(es, b.initExpr(), e);
  auto v1 = e.BuiltinString();
  std::string s1(v1.data(), v1.size());
  b.setBuiltinString(s1);
  b.setIdentifierKind(static_cast<mx::ast::SourceLocExprIdentKind>(mx::FromPasta(e.IdentifierKind())));
  b.setToken(es.EntityId(e.Token()));
  b.setIsIntType(e.IsIntType());
  b.setIsStringType(e.IsStringType());
}

void SerializeSizeOfPackExpr(EntitySerializer &es, mx::ast::SizeOfPackExpr::Builder b, const pasta::SizeOfPackExpr &e) {
  SerializeExpr(es, b.initExpr(), e);
  b.setOperatorToken(es.EntityId(e.OperatorToken()));
  b.setPack(es.EntityId(e.Pack()));
  b.setPackToken(es.EntityId(e.PackToken()));
  auto v4 = e.PartialArguments();
  auto sv4 = b.initPartialArguments(static_cast<unsigned>(v4.size()));
  auto i4 = 0u;
  for (const auto &e4 : v4) {
    SerializeTemplateArgument(es, sv4[i4], e4);
    ++i4;
  }
  b.setRParenToken(es.EntityId(e.RParenToken()));
  b.setIsPartiallySubstituted(e.IsPartiallySubstituted());
}

void SerializeShuffleVectorExpr(EntitySerializer &es, mx::ast::ShuffleVectorExpr::Builder b, const pasta::ShuffleVectorExpr &e) {
  SerializeExpr(es, b.initExpr(), e);
  b.setBuiltinToken(es.EntityId(e.BuiltinToken()));
  b.setRParenToken(es.EntityId(e.RParenToken()));
}

void SerializeSYCLUniqueStableNameExpr(EntitySerializer &es, mx::ast::SYCLUniqueStableNameExpr::Builder b, const pasta::SYCLUniqueStableNameExpr &e) {
  SerializeExpr(es, b.initExpr(), e);
  b.setComputeName(e.ComputeName());
  b.setLParenToken(es.EntityId(e.LParenToken()));
  b.setToken(es.EntityId(e.Token()));
  b.setRParenToken(es.EntityId(e.RParenToken()));
}

void SerializeRequiresExpr(EntitySerializer &es, mx::ast::RequiresExpr::Builder b, const pasta::RequiresExpr &e) {
  SerializeExpr(es, b.initExpr(), e);
  b.setBody(es.EntityId(e.Body()));
  auto v2 = e.LocalParameters();
  auto sv2 = b.initLocalParameters(static_cast<unsigned>(v2.size()));
  auto i2 = 0u;
  for (const auto &e2 : v2) {
    sv2.set(i2, es.EntityId(e2));
    ++i2;
  }
  b.setRBraceToken(es.EntityId(e.RBraceToken()));
  b.setRequiresKwToken(es.EntityId(e.RequiresKWToken()));
  b.setIsSatisfied(e.IsSatisfied());
}

void SerializeRecoveryExpr(EntitySerializer &es, mx::ast::RecoveryExpr::Builder b, const pasta::RecoveryExpr &e) {
  SerializeExpr(es, b.initExpr(), e);
}

void SerializePseudoObjectExpr(EntitySerializer &es, mx::ast::PseudoObjectExpr::Builder b, const pasta::PseudoObjectExpr &e) {
  SerializeExpr(es, b.initExpr(), e);
}

void SerializePredefinedExpr(EntitySerializer &es, mx::ast::PredefinedExpr::Builder b, const pasta::PredefinedExpr &e) {
  SerializeExpr(es, b.initExpr(), e);
  b.setFunctionName(es.EntityId(e.FunctionName()));
  b.setIdentifierKind(static_cast<mx::ast::PredefinedExprIdentKind>(mx::FromPasta(e.IdentifierKind())));
  auto v3 = e.IdentifierKindName();
  std::string s3(v3.data(), v3.size());
  b.setIdentifierKindName(s3);
  b.setToken(es.EntityId(e.Token()));
}

void SerializeParenListExpr(EntitySerializer &es, mx::ast::ParenListExpr::Builder b, const pasta::ParenListExpr &e) {
  SerializeExpr(es, b.initExpr(), e);
  b.setLParenToken(es.EntityId(e.LParenToken()));
  b.setRParenToken(es.EntityId(e.RParenToken()));
}

void SerializeParenExpr(EntitySerializer &es, mx::ast::ParenExpr::Builder b, const pasta::ParenExpr &e) {
  SerializeExpr(es, b.initExpr(), e);
  b.setLParen(es.EntityId(e.LParen()));
  b.setRParen(es.EntityId(e.RParen()));
}

void SerializePackExpansionExpr(EntitySerializer &es, mx::ast::PackExpansionExpr::Builder b, const pasta::PackExpansionExpr &e) {
  SerializeExpr(es, b.initExpr(), e);
  b.setEllipsisToken(es.EntityId(e.EllipsisToken()));
}

void SerializeOverloadExpr(EntitySerializer &es, mx::ast::OverloadExpr::Builder b, const pasta::OverloadExpr &e) {
  SerializeExpr(es, b.initExpr(), e);
  b.setLAngleToken(es.EntityId(e.LAngleToken()));
  b.setNameToken(es.EntityId(e.NameToken()));
  b.setNamingClass(es.EntityId(e.NamingClass()));
  b.setRAngleToken(es.EntityId(e.RAngleToken()));
  b.setTemplateKeywordToken(es.EntityId(e.TemplateKeywordToken()));
  b.setHasExplicitTemplateArguments(e.HasExplicitTemplateArguments());
  b.setHasTemplateKeyword(e.HasTemplateKeyword());
}

void SerializeUnresolvedMemberExpr(EntitySerializer &es, mx::ast::UnresolvedMemberExpr::Builder b, const pasta::UnresolvedMemberExpr &e) {
  SerializeOverloadExpr(es, b.initOverloadExpr(), e);
  b.setMemberToken(es.EntityId(e.MemberToken()));
  b.setOperatorToken(es.EntityId(e.OperatorToken()));
  b.setHasUnresolvedUsing(e.HasUnresolvedUsing());
  b.setIsArrow(e.IsArrow());
  b.setIsImplicitAccess(e.IsImplicitAccess());
}

void SerializeUnresolvedLookupExpr(EntitySerializer &es, mx::ast::UnresolvedLookupExpr::Builder b, const pasta::UnresolvedLookupExpr &e) {
  SerializeOverloadExpr(es, b.initOverloadExpr(), e);
  b.setIsOverloaded(e.IsOverloaded());
  b.setRequiresAdl(e.RequiresADL());
}

void SerializeOpaqueValueExpr(EntitySerializer &es, mx::ast::OpaqueValueExpr::Builder b, const pasta::OpaqueValueExpr &e) {
  SerializeExpr(es, b.initExpr(), e);
  b.setToken(es.EntityId(e.Token()));
  b.setIsUnique(e.IsUnique());
}

void SerializeOffsetOfExpr(EntitySerializer &es, mx::ast::OffsetOfExpr::Builder b, const pasta::OffsetOfExpr &e) {
  SerializeExpr(es, b.initExpr(), e);
  b.setOperatorToken(es.EntityId(e.OperatorToken()));
  b.setRParenToken(es.EntityId(e.RParenToken()));
}

void SerializeObjCSubscriptRefExpr(EntitySerializer &es, mx::ast::ObjCSubscriptRefExpr::Builder b, const pasta::ObjCSubscriptRefExpr &e) {
  SerializeExpr(es, b.initExpr(), e);
  b.setAtIndexMethodDeclaration(es.EntityId(e.AtIndexMethodDeclaration()));
  b.setRBracket(es.EntityId(e.RBracket()));
  b.setIsArraySubscriptReferenceExpression(e.IsArraySubscriptReferenceExpression());
}

void SerializeObjCStringLiteral(EntitySerializer &es, mx::ast::ObjCStringLiteral::Builder b, const pasta::ObjCStringLiteral &e) {
  SerializeExpr(es, b.initExpr(), e);
  b.setAtToken(es.EntityId(e.AtToken()));
  b.setString(es.EntityId(e.String()));
}

void SerializeObjCSelectorExpr(EntitySerializer &es, mx::ast::ObjCSelectorExpr::Builder b, const pasta::ObjCSelectorExpr &e) {
  SerializeExpr(es, b.initExpr(), e);
  b.setAtToken(es.EntityId(e.AtToken()));
  b.setRParenToken(es.EntityId(e.RParenToken()));
}

void SerializeObjCProtocolExpr(EntitySerializer &es, mx::ast::ObjCProtocolExpr::Builder b, const pasta::ObjCProtocolExpr &e) {
  SerializeExpr(es, b.initExpr(), e);
  b.setAtToken(es.EntityId(e.AtToken()));
  b.setProtocol(es.EntityId(e.Protocol()));
  b.setProtocolIdToken(es.EntityId(e.ProtocolIdToken()));
  b.setRParenToken(es.EntityId(e.RParenToken()));
}

void SerializeObjCPropertyRefExpr(EntitySerializer &es, mx::ast::ObjCPropertyRefExpr::Builder b, const pasta::ObjCPropertyRefExpr &e) {
  SerializeExpr(es, b.initExpr(), e);
  b.setClassReceiver(es.EntityId(e.ClassReceiver()));
  b.setExplicitProperty(es.EntityId(e.ExplicitProperty()));
  b.setImplicitPropertyGetter(es.EntityId(e.ImplicitPropertyGetter()));
  b.setImplicitPropertySetter(es.EntityId(e.ImplicitPropertySetter()));
  b.setToken(es.EntityId(e.Token()));
  b.setReceiverToken(es.EntityId(e.ReceiverToken()));
  b.setIsClassReceiver(e.IsClassReceiver());
  b.setIsExplicitProperty(e.IsExplicitProperty());
  b.setIsImplicitProperty(e.IsImplicitProperty());
  b.setIsMessagingGetter(e.IsMessagingGetter());
  b.setIsMessagingSetter(e.IsMessagingSetter());
  b.setIsObjectReceiver(e.IsObjectReceiver());
  b.setIsSuperReceiver(e.IsSuperReceiver());
}

void SerializeObjCMessageExpr(EntitySerializer &es, mx::ast::ObjCMessageExpr::Builder b, const pasta::ObjCMessageExpr &e) {
  SerializeExpr(es, b.initExpr(), e);
  b.setLeftToken(es.EntityId(e.LeftToken()));
  b.setMethodDeclaration(es.EntityId(e.MethodDeclaration()));
  b.setMethodFamily(static_cast<mx::ast::ObjCMethodFamily>(mx::FromPasta(e.MethodFamily())));
  b.setReceiverInterface(es.EntityId(e.ReceiverInterface()));
  b.setReceiverKind(static_cast<mx::ast::ObjCMessageExprReceiverKind>(mx::FromPasta(e.ReceiverKind())));
  auto sr6 = b.initReceiverRange();
  if (auto r6 = e.ReceiverRange(); auto rs6 = r6.Size()) {
    sr6.setBeginId(es.EntityId(r6[0]));
    sr6.setEndId(es.EntityId(r6[rs6 - 1u]));
  } else {
    sr6.setBeginId(0);
    sr6.setEndId(0);
  }
  b.setRightToken(es.EntityId(e.RightToken()));
  b.setSelectorStartToken(es.EntityId(e.SelectorStartToken()));
  b.setSuperToken(es.EntityId(e.SuperToken()));
  b.setIsClassMessage(e.IsClassMessage());
  b.setIsDelegateInitializerCall(e.IsDelegateInitializerCall());
  b.setIsImplicit(e.IsImplicit());
  b.setIsInstanceMessage(e.IsInstanceMessage());
  auto v14 = e.SelectorTokens();
  auto sv14 = b.initSelectorTokens(static_cast<unsigned>(v14.size()));
  auto i14 = 0u;
  for (const auto &e14 : v14) {
    sv14.set(i14, es.EntityId(e14));
    ++i14;
  }
}

void SerializeObjCIvarRefExpr(EntitySerializer &es, mx::ast::ObjCIvarRefExpr::Builder b, const pasta::ObjCIvarRefExpr &e) {
  SerializeExpr(es, b.initExpr(), e);
  b.setDeclaration(es.EntityId(e.Declaration()));
  b.setToken(es.EntityId(e.Token()));
  b.setOperationToken(es.EntityId(e.OperationToken()));
  b.setIsArrow(e.IsArrow());
  b.setIsFreeInstanceVariable(e.IsFreeInstanceVariable());
}

void SerializeObjCIsaExpr(EntitySerializer &es, mx::ast::ObjCIsaExpr::Builder b, const pasta::ObjCIsaExpr &e) {
  SerializeExpr(es, b.initExpr(), e);
  b.setBaseTokenEnd(es.EntityId(e.BaseTokenEnd()));
  b.setIsaMemberToken(es.EntityId(e.IsaMemberToken()));
  b.setOperationToken(es.EntityId(e.OperationToken()));
  b.setIsArrow(e.IsArrow());
}

void SerializeObjCIndirectCopyRestoreExpr(EntitySerializer &es, mx::ast::ObjCIndirectCopyRestoreExpr::Builder b, const pasta::ObjCIndirectCopyRestoreExpr &e) {
  SerializeExpr(es, b.initExpr(), e);
  b.setShouldCopy(e.ShouldCopy());
}

void SerializeObjCEncodeExpr(EntitySerializer &es, mx::ast::ObjCEncodeExpr::Builder b, const pasta::ObjCEncodeExpr &e) {
  SerializeExpr(es, b.initExpr(), e);
  b.setAtToken(es.EntityId(e.AtToken()));
  b.setRParenToken(es.EntityId(e.RParenToken()));
}

void SerializeObjCDictionaryLiteral(EntitySerializer &es, mx::ast::ObjCDictionaryLiteral::Builder b, const pasta::ObjCDictionaryLiteral &e) {
  SerializeExpr(es, b.initExpr(), e);
  b.setDictionaryWithObjectsMethod(es.EntityId(e.DictionaryWithObjectsMethod()));
}

void SerializeObjCBoxedExpr(EntitySerializer &es, mx::ast::ObjCBoxedExpr::Builder b, const pasta::ObjCBoxedExpr &e) {
  SerializeExpr(es, b.initExpr(), e);
  b.setAtToken(es.EntityId(e.AtToken()));
  b.setBoxingMethod(es.EntityId(e.BoxingMethod()));
  b.setIsExpressibleAsConstantInitializer(e.IsExpressibleAsConstantInitializer());
}

void SerializeObjCBoolLiteralExpr(EntitySerializer &es, mx::ast::ObjCBoolLiteralExpr::Builder b, const pasta::ObjCBoolLiteralExpr &e) {
  SerializeExpr(es, b.initExpr(), e);
  b.setToken(es.EntityId(e.Token()));
  b.setValue(e.Value());
}

void SerializeObjCAvailabilityCheckExpr(EntitySerializer &es, mx::ast::ObjCAvailabilityCheckExpr::Builder b, const pasta::ObjCAvailabilityCheckExpr &e) {
  SerializeExpr(es, b.initExpr(), e);
  b.setHasVersion(e.HasVersion());
}

void SerializeObjCArrayLiteral(EntitySerializer &es, mx::ast::ObjCArrayLiteral::Builder b, const pasta::ObjCArrayLiteral &e) {
  SerializeExpr(es, b.initExpr(), e);
  b.setArrayWithObjectsMethod(es.EntityId(e.ArrayWithObjectsMethod()));
}

void SerializeOMPIteratorExpr(EntitySerializer &es, mx::ast::OMPIteratorExpr::Builder b, const pasta::OMPIteratorExpr &e) {
  SerializeExpr(es, b.initExpr(), e);
  b.setIteratorKwToken(es.EntityId(e.IteratorKwToken()));
  b.setLParenToken(es.EntityId(e.LParenToken()));
  b.setRParenToken(es.EntityId(e.RParenToken()));
}

void SerializeOMPArrayShapingExpr(EntitySerializer &es, mx::ast::OMPArrayShapingExpr::Builder b, const pasta::OMPArrayShapingExpr &e) {
  SerializeExpr(es, b.initExpr(), e);
  b.setLParenToken(es.EntityId(e.LParenToken()));
  b.setRParenToken(es.EntityId(e.RParenToken()));
}

void SerializeOMPArraySectionExpr(EntitySerializer &es, mx::ast::OMPArraySectionExpr::Builder b, const pasta::OMPArraySectionExpr &e) {
  SerializeExpr(es, b.initExpr(), e);
  b.setColonTokenFirst(es.EntityId(e.ColonTokenFirst()));
  b.setColonTokenSecond(es.EntityId(e.ColonTokenSecond()));
  b.setRBracketToken(es.EntityId(e.RBracketToken()));
}

void SerializeNoInitExpr(EntitySerializer &es, mx::ast::NoInitExpr::Builder b, const pasta::NoInitExpr &e) {
  SerializeExpr(es, b.initExpr(), e);
}

void SerializeMemberExpr(EntitySerializer &es, mx::ast::MemberExpr::Builder b, const pasta::MemberExpr &e) {
  SerializeExpr(es, b.initExpr(), e);
  b.setLAngleToken(es.EntityId(e.LAngleToken()));
  b.setMemberDeclaration(es.EntityId(e.MemberDeclaration()));
  b.setMemberToken(es.EntityId(e.MemberToken()));
  b.setOperatorToken(es.EntityId(e.OperatorToken()));
  b.setRAngleToken(es.EntityId(e.RAngleToken()));
  b.setTemplateKeywordToken(es.EntityId(e.TemplateKeywordToken()));
  b.setHadMultipleCandidates(e.HadMultipleCandidates());
  b.setHasExplicitTemplateArguments(e.HasExplicitTemplateArguments());
  b.setHasQualifier(e.HasQualifier());
  b.setHasTemplateKeyword(e.HasTemplateKeyword());
  b.setIsArrow(e.IsArrow());
  b.setIsImplicitAccess(e.IsImplicitAccess());
  b.setIsNonOdrUse(static_cast<mx::ast::NonOdrUseReason>(mx::FromPasta(e.IsNonOdrUse())));
}

void SerializeMatrixSubscriptExpr(EntitySerializer &es, mx::ast::MatrixSubscriptExpr::Builder b, const pasta::MatrixSubscriptExpr &e) {
  SerializeExpr(es, b.initExpr(), e);
  b.setRBracketToken(es.EntityId(e.RBracketToken()));
  b.setIsIncomplete(e.IsIncomplete());
}

void SerializeMaterializeTemporaryExpr(EntitySerializer &es, mx::ast::MaterializeTemporaryExpr::Builder b, const pasta::MaterializeTemporaryExpr &e) {
  SerializeExpr(es, b.initExpr(), e);
  b.setExtendingDeclaration(es.EntityId(e.ExtendingDeclaration()));
  b.setLifetimeExtendedTemporaryDeclaration(es.EntityId(e.LifetimeExtendedTemporaryDeclaration()));
  b.setStorageDuration(static_cast<mx::ast::StorageDuration>(mx::FromPasta(e.StorageDuration())));
  b.setIsBoundToLvalueReference(e.IsBoundToLvalueReference());
  b.setIsUsableInConstantExpressions(e.IsUsableInConstantExpressions());
}

void SerializeMSPropertySubscriptExpr(EntitySerializer &es, mx::ast::MSPropertySubscriptExpr::Builder b, const pasta::MSPropertySubscriptExpr &e) {
  SerializeExpr(es, b.initExpr(), e);
  b.setRBracketToken(es.EntityId(e.RBracketToken()));
}

void SerializeMSPropertyRefExpr(EntitySerializer &es, mx::ast::MSPropertyRefExpr::Builder b, const pasta::MSPropertyRefExpr &e) {
  SerializeExpr(es, b.initExpr(), e);
  b.setMemberToken(es.EntityId(e.MemberToken()));
  b.setPropertyDeclaration(es.EntityId(e.PropertyDeclaration()));
  b.setIsArrow(e.IsArrow());
  b.setIsImplicitAccess(e.IsImplicitAccess());
}

void SerializeLambdaExpr(EntitySerializer &es, mx::ast::LambdaExpr::Builder b, const pasta::LambdaExpr &e) {
  SerializeExpr(es, b.initExpr(), e);
  b.setCallOperator(es.EntityId(e.CallOperator()));
  b.setCaptureDefault(static_cast<mx::ast::LambdaCaptureDefault>(mx::FromPasta(e.CaptureDefault())));
  b.setCaptureDefaultToken(es.EntityId(e.CaptureDefaultToken()));
  b.setCompoundStatementBody(es.EntityId(e.CompoundStatementBody()));
  b.setDependentCallOperator(es.EntityId(e.DependentCallOperator()));
  auto v6 = e.ExplicitTemplateParameters();
  auto sv6 = b.initExplicitTemplateParameters(static_cast<unsigned>(v6.size()));
  auto i6 = 0u;
  for (const auto &e6 : v6) {
    sv6.set(i6, es.EntityId(e6));
    ++i6;
  }
  auto sr7 = b.initIntroducerRange();
  if (auto r7 = e.IntroducerRange(); auto rs7 = r7.Size()) {
    sr7.setBeginId(es.EntityId(r7[0]));
    sr7.setEndId(es.EntityId(r7[rs7 - 1u]));
  } else {
    sr7.setBeginId(0);
    sr7.setEndId(0);
  }
  b.setLambdaClass(es.EntityId(e.LambdaClass()));
  SerializeTemplateParameterList(es, b.initTemplateParameterList(), e.TemplateParameterList());
  b.setHasExplicitParameters(e.HasExplicitParameters());
  b.setHasExplicitResultType(e.HasExplicitResultType());
  b.setIsGenericLambda(e.IsGenericLambda());
  b.setIsMutable(e.IsMutable());
}

void SerializeIntegerLiteral(EntitySerializer &es, mx::ast::IntegerLiteral::Builder b, const pasta::IntegerLiteral &e) {
  SerializeExpr(es, b.initExpr(), e);
  b.setToken(es.EntityId(e.Token()));
}

void SerializeInitListExpr(EntitySerializer &es, mx::ast::InitListExpr::Builder b, const pasta::InitListExpr &e) {
  SerializeExpr(es, b.initExpr(), e);
  auto v1 = e.InitializedFieldInUnion();
  if (v1) {
    if (auto id1 = es.EntityId(v1.value())) {
      b.setInitializedFieldInUnion(id1);
      b.setInitializedFieldInUnionIsPresent(true);
    } else {
      b.setInitializedFieldInUnion(0);
      b.setInitializedFieldInUnionIsPresent(false);
    }
  } else {
    b.setInitializedFieldInUnion(0);
    b.setInitializedFieldInUnionIsPresent(false);
  }
  b.setLBraceToken(es.EntityId(e.LBraceToken()));
  b.setRBraceToken(es.EntityId(e.RBraceToken()));
  auto v5 = e.SemanticForm();
  if (v5) {
    if (auto id5 = es.EntityId(v5.value())) {
      b.setSemanticForm(id5);
      b.setSemanticFormIsPresent(true);
    } else {
      b.setSemanticForm(0);
      b.setSemanticFormIsPresent(false);
    }
  } else {
    b.setSemanticForm(0);
    b.setSemanticFormIsPresent(false);
  }
  auto v7 = e.SyntacticForm();
  if (v7) {
    if (auto id7 = es.EntityId(v7.value())) {
      b.setSyntacticForm(id7);
      b.setSyntacticFormIsPresent(true);
    } else {
      b.setSyntacticForm(0);
      b.setSyntacticFormIsPresent(false);
    }
  } else {
    b.setSyntacticForm(0);
    b.setSyntacticFormIsPresent(false);
  }
  b.setHadArrayRangeDesignator(e.HadArrayRangeDesignator());
  b.setHasArrayFiller(e.HasArrayFiller());
  b.setIsExplicit(e.IsExplicit());
  b.setIsSemanticForm(e.IsSemanticForm());
  b.setIsStringLiteralInitializer(e.IsStringLiteralInitializer());
  b.setIsSyntacticForm(e.IsSyntacticForm());
  b.setIsTransparent(e.IsTransparent());
}

void SerializeImplicitValueInitExpr(EntitySerializer &es, mx::ast::ImplicitValueInitExpr::Builder b, const pasta::ImplicitValueInitExpr &e) {
  SerializeExpr(es, b.initExpr(), e);
}

void SerializeImaginaryLiteral(EntitySerializer &es, mx::ast::ImaginaryLiteral::Builder b, const pasta::ImaginaryLiteral &e) {
  SerializeExpr(es, b.initExpr(), e);
}

void SerializeGenericSelectionExpr(EntitySerializer &es, mx::ast::GenericSelectionExpr::Builder b, const pasta::GenericSelectionExpr &e) {
  SerializeExpr(es, b.initExpr(), e);
  b.setDefaultToken(es.EntityId(e.DefaultToken()));
  b.setGenericToken(es.EntityId(e.GenericToken()));
  b.setRParenToken(es.EntityId(e.RParenToken()));
  b.setIsResultDependent(e.IsResultDependent());
}

void SerializeGNUNullExpr(EntitySerializer &es, mx::ast::GNUNullExpr::Builder b, const pasta::GNUNullExpr &e) {
  SerializeExpr(es, b.initExpr(), e);
  b.setTokenToken(es.EntityId(e.TokenToken()));
}

void SerializeFunctionParmPackExpr(EntitySerializer &es, mx::ast::FunctionParmPackExpr::Builder b, const pasta::FunctionParmPackExpr &e) {
  SerializeExpr(es, b.initExpr(), e);
  b.setParameterPack(es.EntityId(e.ParameterPack()));
  b.setParameterPackToken(es.EntityId(e.ParameterPackToken()));
  auto v3 = e.Expansions();
  auto sv3 = b.initExpansions(static_cast<unsigned>(v3.size()));
  auto i3 = 0u;
  for (const auto &e3 : v3) {
    sv3.set(i3, es.EntityId(e3));
    ++i3;
  }
}

void SerializeFullExpr(EntitySerializer &es, mx::ast::FullExpr::Builder b, const pasta::FullExpr &e) {
  SerializeExpr(es, b.initExpr(), e);
}

void SerializeExprWithCleanups(EntitySerializer &es, mx::ast::ExprWithCleanups::Builder b, const pasta::ExprWithCleanups &e) {
  SerializeFullExpr(es, b.initFullExpr(), e);
  b.setCleanupsHaveSideEffects(e.CleanupsHaveSideEffects());
}

void SerializeConstantExpr(EntitySerializer &es, mx::ast::ConstantExpr::Builder b, const pasta::ConstantExpr &e) {
  SerializeFullExpr(es, b.initFullExpr(), e);
  b.setResultStorageKind(static_cast<mx::ast::ConstantExprResultStorageKind>(mx::FromPasta(e.ResultStorageKind())));
  b.setHasApValueResult(e.HasAPValueResult());
  b.setIsImmediateInvocation(e.IsImmediateInvocation());
}

void SerializeFloatingLiteral(EntitySerializer &es, mx::ast::FloatingLiteral::Builder b, const pasta::FloatingLiteral &e) {
  SerializeExpr(es, b.initExpr(), e);
  b.setToken(es.EntityId(e.Token()));
  b.setIsExact(e.IsExact());
}

void SerializeFixedPointLiteral(EntitySerializer &es, mx::ast::FixedPointLiteral::Builder b, const pasta::FixedPointLiteral &e) {
  SerializeExpr(es, b.initExpr(), e);
  b.setToken(es.EntityId(e.Token()));
}

void SerializeExtVectorElementExpr(EntitySerializer &es, mx::ast::ExtVectorElementExpr::Builder b, const pasta::ExtVectorElementExpr &e) {
  SerializeExpr(es, b.initExpr(), e);
  b.setContainsDuplicateElements(e.ContainsDuplicateElements());
  b.setAccessorToken(es.EntityId(e.AccessorToken()));
  b.setIsArrow(e.IsArrow());
}

void SerializeExpressionTraitExpr(EntitySerializer &es, mx::ast::ExpressionTraitExpr::Builder b, const pasta::ExpressionTraitExpr &e) {
  SerializeExpr(es, b.initExpr(), e);
  b.setTrait(static_cast<mx::ast::ExpressionTrait>(mx::FromPasta(e.Trait())));
  b.setValue(e.Value());
}

void SerializeAttributedStmt(EntitySerializer &es, mx::ast::AttributedStmt::Builder b, const pasta::AttributedStmt &e) {
  SerializeValueStmt(es, b.initValueStmt(), e);
  b.setAttributeToken(es.EntityId(e.AttributeToken()));
}

void SerializeSwitchStmt(EntitySerializer &es, mx::ast::SwitchStmt::Builder b, const pasta::SwitchStmt &e) {
  SerializeStmt(es, b.initStmt(), e);
  auto v1 = e.ConditionVariable();
  if (v1) {
    if (auto id1 = es.EntityId(v1.value())) {
      b.setConditionVariable(id1);
      b.setConditionVariableIsPresent(true);
    } else {
      b.setConditionVariable(0);
      b.setConditionVariableIsPresent(false);
    }
  } else {
    b.setConditionVariable(0);
    b.setConditionVariableIsPresent(false);
  }
  auto v3 = e.ConditionVariableDeclarationStatement();
  if (v3) {
    if (auto id3 = es.EntityId(v3.value())) {
      b.setConditionVariableDeclarationStatement(id3);
      b.setConditionVariableDeclarationStatementIsPresent(true);
    } else {
      b.setConditionVariableDeclarationStatement(0);
      b.setConditionVariableDeclarationStatementIsPresent(false);
    }
  } else {
    b.setConditionVariableDeclarationStatement(0);
    b.setConditionVariableDeclarationStatementIsPresent(false);
  }
  b.setLParenToken(es.EntityId(e.LParenToken()));
  b.setRParenToken(es.EntityId(e.RParenToken()));
  b.setSwitchToken(es.EntityId(e.SwitchToken()));
  b.setHasInitializerStorage(e.HasInitializerStorage());
  b.setHasVariableStorage(e.HasVariableStorage());
  b.setIsAllEnumCasesCovered(e.IsAllEnumCasesCovered());
}

void SerializeSwitchCase(EntitySerializer &es, mx::ast::SwitchCase::Builder b, const pasta::SwitchCase &e) {
  SerializeStmt(es, b.initStmt(), e);
  b.setColonToken(es.EntityId(e.ColonToken()));
  b.setKeywordToken(es.EntityId(e.KeywordToken()));
}

void SerializeDefaultStmt(EntitySerializer &es, mx::ast::DefaultStmt::Builder b, const pasta::DefaultStmt &e) {
  SerializeSwitchCase(es, b.initSwitchCase(), e);
  b.setDefaultToken(es.EntityId(e.DefaultToken()));
}

void SerializeCaseStmt(EntitySerializer &es, mx::ast::CaseStmt::Builder b, const pasta::CaseStmt &e) {
  SerializeSwitchCase(es, b.initSwitchCase(), e);
  b.setCaseStatementIsGnuRange(e.CaseStatementIsGNURange());
  b.setCaseToken(es.EntityId(e.CaseToken()));
  b.setEllipsisToken(es.EntityId(e.EllipsisToken()));
}

void SerializeDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::Decl &e) {
  b.setAccess(static_cast<mx::ast::AccessSpecifier>(mx::FromPasta(e.Access())));
  b.setAccessUnsafe(static_cast<mx::ast::AccessSpecifier>(mx::FromPasta(e.AccessUnsafe())));
  b.setAvailability(static_cast<mx::ast::AvailabilityResult>(mx::FromPasta(e.Availability())));
  b.setBeginToken(es.EntityId(e.BeginToken()));
  b.setBodyRBrace(es.EntityId(e.BodyRBrace()));
  auto v5 = e.DescribedTemplate();
  if (v5) {
    if (auto id5 = es.EntityId(v5.value())) {
      b.setDescribedTemplate(id5);
      b.setDescribedTemplateIsPresent(true);
    } else {
      b.setDescribedTemplate(0);
      b.setDescribedTemplateIsPresent(false);
    }
  } else {
    b.setDescribedTemplate(0);
    b.setDescribedTemplateIsPresent(false);
  }
  b.setEndToken(es.EntityId(e.EndToken()));
  b.setFriendObjectKind(static_cast<mx::ast::DeclFriendObjectKind>(mx::FromPasta(e.FriendObjectKind())));
  b.setModuleOwnershipKind(static_cast<mx::ast::DeclModuleOwnershipKind>(mx::FromPasta(e.ModuleOwnershipKind())));
  b.setHasAttributes(e.HasAttributes());
  b.setHasDefiningAttribute(e.HasDefiningAttribute());
  b.setHasOwningModule(e.HasOwningModule());
  b.setHasTagIdentifierNamespace(e.HasTagIdentifierNamespace());
  b.setIsCanonicalDeclaration(e.IsCanonicalDeclaration());
  b.setIsDefinedOutsideFunctionOrMethod(e.IsDefinedOutsideFunctionOrMethod());
  b.setIsDeprecated(e.IsDeprecated());
  b.setIsFirstDeclaration(e.IsFirstDeclaration());
  b.setIsFunctionOrFunctionTemplate(e.IsFunctionOrFunctionTemplate());
  b.setIsImplicit(e.IsImplicit());
  b.setIsInAnonymousNamespace(e.IsInAnonymousNamespace());
  b.setIsInLocalScopeForInstantiation(e.IsInLocalScopeForInstantiation());
  b.setIsInStdNamespace(e.IsInStdNamespace());
  b.setIsInvalidDeclaration(e.IsInvalidDeclaration());
  b.setIsModulePrivate(e.IsModulePrivate());
  b.setIsOutOfLine(e.IsOutOfLine());
  b.setIsParameterPack(e.IsParameterPack());
  b.setIsReferenced(e.IsReferenced());
  b.setIsTemplateDeclaration(e.IsTemplateDeclaration());
  b.setIsTemplateParameter(e.IsTemplateParameter());
  b.setIsTemplateParameterPack(e.IsTemplateParameterPack());
  b.setIsTemplated(e.IsTemplated());
  b.setIsThisDeclarationReferenced(e.IsThisDeclarationReferenced());
  b.setIsTopLevelDeclarationInObjCContainer(e.IsTopLevelDeclarationInObjCContainer());
  b.setIsUnavailable(e.IsUnavailable());
  b.setIsUnconditionallyVisible(e.IsUnconditionallyVisible());
  b.setIsUsed(e.IsUsed());
  b.setIsWeakImported(e.IsWeakImported());
  b.setKind(static_cast<mx::ast::DeclKind>(mx::FromPasta(e.Kind())));
  b.setToken(es.EntityId(e.Token()));
  auto sr40 = b.initTokenRange();
  if (auto r40 = e.TokenRange(); auto rs40 = r40.Size()) {
    sr40.setBeginId(es.EntityId(r40[0]));
    sr40.setEndId(es.EntityId(r40[rs40 - 1u]));
  } else {
    sr40.setBeginId(0);
    sr40.setEndId(0);
  }
}

void SerializeClassScopeFunctionSpecializationDecl(EntitySerializer &es, mx::ast::ClassScopeFunctionSpecializationDecl::Builder b, const pasta::ClassScopeFunctionSpecializationDecl &e) {
  SerializeDecl(es, b.initDecl(), e);
  b.setSpecialization(es.EntityId(e.Specialization()));
  b.setHasExplicitTemplateArguments(e.HasExplicitTemplateArguments());
}

void SerializeCapturedDecl(EntitySerializer &es, mx::ast::CapturedDecl::Builder b, const pasta::CapturedDecl &e) {
  SerializeDecl(es, b.initDecl(), e);
  b.setContextParameter(es.EntityId(e.ContextParameter()));
  b.setIsNothrow(e.IsNothrow());
  auto v3 = e.Parameters();
  auto sv3 = b.initParameters(static_cast<unsigned>(v3.size()));
  auto i3 = 0u;
  for (const auto &e3 : v3) {
    sv3.set(i3, es.EntityId(e3));
    ++i3;
  }
  pasta::DeclContext dc4(e);
  auto v4 = dc4.AlreadyLoadedDeclarations();
  auto sv4 = b.initDeclarationsInContext(static_cast<unsigned>(v4.size()));
  auto i4 = 0u;
  for (const pasta::Decl &e4 : v4) {
    sv4.set(i4, es.EntityId(e4));
    ++i4;
  }
}

void SerializeBlockDecl(EntitySerializer &es, mx::ast::BlockDecl::Builder b, const pasta::BlockDecl &e) {
  SerializeDecl(es, b.initDecl(), e);
  b.setBlockMissingReturnType(e.BlockMissingReturnType());
  b.setCanAvoidCopyToHeap(e.CanAvoidCopyToHeap());
  b.setCapturesCxxThis(e.CapturesCXXThis());
  b.setDoesNotEscape(e.DoesNotEscape());
  b.setCaretToken(es.EntityId(e.CaretToken()));
  b.setCompoundBody(es.EntityId(e.CompoundBody()));
  b.setHasCaptures(e.HasCaptures());
  b.setIsConversionFromLambda(e.IsConversionFromLambda());
  b.setIsVariadic(e.IsVariadic());
  auto v10 = e.Parameters();
  auto sv10 = b.initParameters(static_cast<unsigned>(v10.size()));
  auto i10 = 0u;
  for (const auto &e10 : v10) {
    sv10.set(i10, es.EntityId(e10));
    ++i10;
  }
  auto v11 = e.ParameterDeclarations();
  auto sv11 = b.initParameterDeclarations(static_cast<unsigned>(v11.size()));
  auto i11 = 0u;
  for (const auto &e11 : v11) {
    sv11.set(i11, es.EntityId(e11));
    ++i11;
  }
  pasta::DeclContext dc12(e);
  auto v12 = dc12.AlreadyLoadedDeclarations();
  auto sv12 = b.initDeclarationsInContext(static_cast<unsigned>(v12.size()));
  auto i12 = 0u;
  for (const pasta::Decl &e12 : v12) {
    sv12.set(i12, es.EntityId(e12));
    ++i12;
  }
}

void SerializeAccessSpecDecl(EntitySerializer &es, mx::ast::AccessSpecDecl::Builder b, const pasta::AccessSpecDecl &e) {
  SerializeDecl(es, b.initDecl(), e);
  b.setAccessSpecifierToken(es.EntityId(e.AccessSpecifierToken()));
  b.setColonToken(es.EntityId(e.ColonToken()));
}

void SerializeOMPDeclarativeDirectiveDecl(EntitySerializer &es, mx::ast::OMPDeclarativeDirectiveDecl::Builder b, const pasta::OMPDeclarativeDirectiveDecl &e) {
  SerializeDecl(es, b.initDecl(), e);
}

void SerializeOMPThreadPrivateDecl(EntitySerializer &es, mx::ast::OMPThreadPrivateDecl::Builder b, const pasta::OMPThreadPrivateDecl &e) {
  SerializeOMPDeclarativeDirectiveDecl(es, b.initOmpDeclarativeDirectiveDecl(), e);
}

void SerializeOMPRequiresDecl(EntitySerializer &es, mx::ast::OMPRequiresDecl::Builder b, const pasta::OMPRequiresDecl &e) {
  SerializeOMPDeclarativeDirectiveDecl(es, b.initOmpDeclarativeDirectiveDecl(), e);
}

void SerializeOMPAllocateDecl(EntitySerializer &es, mx::ast::OMPAllocateDecl::Builder b, const pasta::OMPAllocateDecl &e) {
  SerializeOMPDeclarativeDirectiveDecl(es, b.initOmpDeclarativeDirectiveDecl(), e);
}

void SerializeTranslationUnitDecl(EntitySerializer &es, mx::ast::TranslationUnitDecl::Builder b, const pasta::TranslationUnitDecl &e) {
  SerializeDecl(es, b.initDecl(), e);
  b.setAnonymousNamespace(es.EntityId(e.AnonymousNamespace()));
  pasta::DeclContext dc2(e);
  auto v2 = dc2.AlreadyLoadedDeclarations();
  auto sv2 = b.initDeclarationsInContext(static_cast<unsigned>(v2.size()));
  auto i2 = 0u;
  for (const pasta::Decl &e2 : v2) {
    sv2.set(i2, es.EntityId(e2));
    ++i2;
  }
}

void SerializeStaticAssertDecl(EntitySerializer &es, mx::ast::StaticAssertDecl::Builder b, const pasta::StaticAssertDecl &e) {
  SerializeDecl(es, b.initDecl(), e);
  b.setMessage(es.EntityId(e.Message()));
  b.setRParenToken(es.EntityId(e.RParenToken()));
  b.setIsFailed(e.IsFailed());
}

void SerializeRequiresExprBodyDecl(EntitySerializer &es, mx::ast::RequiresExprBodyDecl::Builder b, const pasta::RequiresExprBodyDecl &e) {
  SerializeDecl(es, b.initDecl(), e);
  pasta::DeclContext dc1(e);
  auto v1 = dc1.AlreadyLoadedDeclarations();
  auto sv1 = b.initDeclarationsInContext(static_cast<unsigned>(v1.size()));
  auto i1 = 0u;
  for (const pasta::Decl &e1 : v1) {
    sv1.set(i1, es.EntityId(e1));
    ++i1;
  }
}

void SerializePragmaDetectMismatchDecl(EntitySerializer &es, mx::ast::PragmaDetectMismatchDecl::Builder b, const pasta::PragmaDetectMismatchDecl &e) {
  SerializeDecl(es, b.initDecl(), e);
  auto v1 = e.Name();
  std::string s1(v1.data(), v1.size());
  b.setName(s1);
  auto v2 = e.Value();
  std::string s2(v2.data(), v2.size());
  b.setValue(s2);
}

void SerializePragmaCommentDecl(EntitySerializer &es, mx::ast::PragmaCommentDecl::Builder b, const pasta::PragmaCommentDecl &e) {
  SerializeDecl(es, b.initDecl(), e);
  auto v1 = e.Argument();
  std::string s1(v1.data(), v1.size());
  b.setArgument(s1);
  b.setCommentKind(static_cast<mx::ast::PragmaMSCommentKind>(mx::FromPasta(e.CommentKind())));
}

void SerializeObjCPropertyImplDecl(EntitySerializer &es, mx::ast::ObjCPropertyImplDecl::Builder b, const pasta::ObjCPropertyImplDecl &e) {
  SerializeDecl(es, b.initDecl(), e);
  b.setGetterMethodDeclaration(es.EntityId(e.GetterMethodDeclaration()));
  b.setPropertyDeclaration(es.EntityId(e.PropertyDeclaration()));
  b.setPropertyImplementation(static_cast<mx::ast::ObjCPropertyImplDeclKind>(mx::FromPasta(e.PropertyImplementation())));
  b.setPropertyInstanceVariableDeclaration(es.EntityId(e.PropertyInstanceVariableDeclaration()));
  b.setPropertyInstanceVariableDeclarationToken(es.EntityId(e.PropertyInstanceVariableDeclarationToken()));
  b.setSetterMethodDeclaration(es.EntityId(e.SetterMethodDeclaration()));
  b.setIsInstanceVariableNameSpecified(e.IsInstanceVariableNameSpecified());
}

void SerializeNamedDecl(EntitySerializer &es, mx::ast::NamedDecl::Builder b, const pasta::NamedDecl &e) {
  SerializeDecl(es, b.initDecl(), e);
  b.setFormalLinkage(static_cast<mx::ast::Linkage>(mx::FromPasta(e.FormalLinkage())));
  b.setLinkageInternal(static_cast<mx::ast::Linkage>(mx::FromPasta(e.LinkageInternal())));
  b.setName(e.Name());
  b.setObjCfStringFormattingFamily(static_cast<mx::ast::ObjCStringFormatFamily>(mx::FromPasta(e.ObjCFStringFormattingFamily())));
  b.setQualifiedNameAsString(e.QualifiedNameAsString());
  b.setUnderlyingDeclaration(es.EntityId(e.UnderlyingDeclaration()));
  b.setVisibility(static_cast<mx::ast::Visibility>(mx::FromPasta(e.Visibility())));
  b.setHasExternalFormalLinkage(e.HasExternalFormalLinkage());
  b.setHasLinkage(e.HasLinkage());
  b.setHasLinkageBeenComputed(e.HasLinkageBeenComputed());
  b.setIsCxxClassMember(e.IsCXXClassMember());
  b.setIsCxxInstanceMember(e.IsCXXInstanceMember());
  b.setIsExternallyDeclarable(e.IsExternallyDeclarable());
  b.setIsExternallyVisible(e.IsExternallyVisible());
  b.setIsLinkageValid(e.IsLinkageValid());
}

void SerializeLabelDecl(EntitySerializer &es, mx::ast::LabelDecl::Builder b, const pasta::LabelDecl &e) {
  SerializeNamedDecl(es, b.initNamedDecl(), e);
  auto v1 = e.MSAssemblyLabel();
  std::string s1(v1.data(), v1.size());
  b.setMsAssemblyLabel(s1);
  b.setStatement(es.EntityId(e.Statement()));
  b.setIsGnuLocal(e.IsGnuLocal());
  b.setIsMsAssemblyLabel(e.IsMSAssemblyLabel());
  b.setIsResolvedMsAssemblyLabel(e.IsResolvedMSAssemblyLabel());
}

void SerializeBaseUsingDecl(EntitySerializer &es, mx::ast::BaseUsingDecl::Builder b, const pasta::BaseUsingDecl &e) {
  SerializeNamedDecl(es, b.initNamedDecl(), e);
  auto v1 = e.Shadows();
  auto sv1 = b.initShadows(static_cast<unsigned>(v1.size()));
  auto i1 = 0u;
  for (const auto &e1 : v1) {
    sv1.set(i1, es.EntityId(e1));
    ++i1;
  }
}

void SerializeUsingEnumDecl(EntitySerializer &es, mx::ast::UsingEnumDecl::Builder b, const pasta::UsingEnumDecl &e) {
  SerializeBaseUsingDecl(es, b.initBaseUsingDecl(), e);
  b.setEnumDeclaration(es.EntityId(e.EnumDeclaration()));
  b.setEnumToken(es.EntityId(e.EnumToken()));
  b.setUsingToken(es.EntityId(e.UsingToken()));
}

void SerializeUsingDecl(EntitySerializer &es, mx::ast::UsingDecl::Builder b, const pasta::UsingDecl &e) {
  SerializeBaseUsingDecl(es, b.initBaseUsingDecl(), e);
  b.setUsingToken(es.EntityId(e.UsingToken()));
  b.setHasTypename(e.HasTypename());
  b.setIsAccessDeclaration(e.IsAccessDeclaration());
}

void SerializeValueDecl(EntitySerializer &es, mx::ast::ValueDecl::Builder b, const pasta::ValueDecl &e) {
  SerializeNamedDecl(es, b.initNamedDecl(), e);
  b.setIsWeak(e.IsWeak());
}

void SerializeUnresolvedUsingValueDecl(EntitySerializer &es, mx::ast::UnresolvedUsingValueDecl::Builder b, const pasta::UnresolvedUsingValueDecl &e) {
  SerializeValueDecl(es, b.initValueDecl(), e);
  b.setEllipsisToken(es.EntityId(e.EllipsisToken()));
  b.setUsingToken(es.EntityId(e.UsingToken()));
  b.setIsAccessDeclaration(e.IsAccessDeclaration());
  b.setIsPackExpansion(e.IsPackExpansion());
}

void SerializeTemplateParamObjectDecl(EntitySerializer &es, mx::ast::TemplateParamObjectDecl::Builder b, const pasta::TemplateParamObjectDecl &e) {
  SerializeValueDecl(es, b.initValueDecl(), e);
}

void SerializeOMPDeclareReductionDecl(EntitySerializer &es, mx::ast::OMPDeclareReductionDecl::Builder b, const pasta::OMPDeclareReductionDecl &e) {
  SerializeValueDecl(es, b.initValueDecl(), e);
  b.setInitializerKind(static_cast<mx::ast::OMPDeclareReductionDeclInitKind>(mx::FromPasta(e.InitializerKind())));
  b.setPrevDeclarationInScope(es.EntityId(e.PrevDeclarationInScope()));
  pasta::DeclContext dc3(e);
  auto v3 = dc3.AlreadyLoadedDeclarations();
  auto sv3 = b.initDeclarationsInContext(static_cast<unsigned>(v3.size()));
  auto i3 = 0u;
  for (const pasta::Decl &e3 : v3) {
    sv3.set(i3, es.EntityId(e3));
    ++i3;
  }
}

void SerializeMSGuidDecl(EntitySerializer &es, mx::ast::MSGuidDecl::Builder b, const pasta::MSGuidDecl &e) {
  SerializeValueDecl(es, b.initValueDecl(), e);
}

void SerializeIndirectFieldDecl(EntitySerializer &es, mx::ast::IndirectFieldDecl::Builder b, const pasta::IndirectFieldDecl &e) {
  SerializeValueDecl(es, b.initValueDecl(), e);
  auto v1 = e.Chain();
  auto sv1 = b.initChain(static_cast<unsigned>(v1.size()));
  auto i1 = 0u;
  for (const auto &e1 : v1) {
    sv1.set(i1, es.EntityId(e1));
    ++i1;
  }
  auto v2 = e.AnonymousField();
  if (v2) {
    if (auto id2 = es.EntityId(v2.value())) {
      b.setAnonymousField(id2);
      b.setAnonymousFieldIsPresent(true);
    } else {
      b.setAnonymousField(0);
      b.setAnonymousFieldIsPresent(false);
    }
  } else {
    b.setAnonymousField(0);
    b.setAnonymousFieldIsPresent(false);
  }
  auto v4 = e.VariableDeclaration();
  if (v4) {
    if (auto id4 = es.EntityId(v4.value())) {
      b.setVariableDeclaration(id4);
      b.setVariableDeclarationIsPresent(true);
    } else {
      b.setVariableDeclaration(0);
      b.setVariableDeclarationIsPresent(false);
    }
  } else {
    b.setVariableDeclaration(0);
    b.setVariableDeclarationIsPresent(false);
  }
}

void SerializeEnumConstantDecl(EntitySerializer &es, mx::ast::EnumConstantDecl::Builder b, const pasta::EnumConstantDecl &e) {
  SerializeValueDecl(es, b.initValueDecl(), e);
}

void SerializeDeclaratorDecl(EntitySerializer &es, mx::ast::DeclaratorDecl::Builder b, const pasta::DeclaratorDecl &e) {
  SerializeValueDecl(es, b.initValueDecl(), e);
  b.setInnerTokenStart(es.EntityId(e.InnerTokenStart()));
  b.setOuterTokenStart(es.EntityId(e.OuterTokenStart()));
  b.setTypeSpecEndToken(es.EntityId(e.TypeSpecEndToken()));
  b.setTypeSpecStartToken(es.EntityId(e.TypeSpecStartToken()));
  auto v5 = e.TemplateParameterLists();
  auto sv5 = b.initTemplateParameterLists(static_cast<unsigned>(v5.size()));
  auto i5 = 0u;
  for (const auto &e5 : v5) {
    SerializeTemplateParameterList(es, sv5[i5], e5);
    ++i5;
  }
}

void SerializeVarDecl(EntitySerializer &es, mx::ast::VarDecl::Builder b, const pasta::VarDecl &e) {
  SerializeDeclaratorDecl(es, b.initDeclaratorDecl(), e);
  auto v1 = e.ActingDefinition();
  if (v1) {
    if (auto id1 = es.EntityId(v1.value())) {
      b.setActingDefinition(id1);
      b.setActingDefinitionIsPresent(true);
    } else {
      b.setActingDefinition(0);
      b.setActingDefinitionIsPresent(false);
    }
  } else {
    b.setActingDefinition(0);
    b.setActingDefinitionIsPresent(false);
  }
  auto v3 = e.DescribedVariableTemplate();
  if (v3) {
    if (auto id3 = es.EntityId(v3.value())) {
      b.setDescribedVariableTemplate(id3);
      b.setDescribedVariableTemplateIsPresent(true);
    } else {
      b.setDescribedVariableTemplate(0);
      b.setDescribedVariableTemplateIsPresent(false);
    }
  } else {
    b.setDescribedVariableTemplate(0);
    b.setDescribedVariableTemplateIsPresent(false);
  }
  b.setInitializerStyle(static_cast<mx::ast::VarDeclInitializationStyle>(mx::FromPasta(e.InitializerStyle())));
  auto v6 = e.InitializingDeclaration();
  if (v6) {
    if (auto id6 = es.EntityId(v6.value())) {
      b.setInitializingDeclaration(id6);
      b.setInitializingDeclarationIsPresent(true);
    } else {
      b.setInitializingDeclaration(0);
      b.setInitializingDeclarationIsPresent(false);
    }
  } else {
    b.setInitializingDeclaration(0);
    b.setInitializingDeclarationIsPresent(false);
  }
  auto v8 = e.InstantiatedFromStaticDataMember();
  if (v8) {
    if (auto id8 = es.EntityId(v8.value())) {
      b.setInstantiatedFromStaticDataMember(id8);
      b.setInstantiatedFromStaticDataMemberIsPresent(true);
    } else {
      b.setInstantiatedFromStaticDataMember(0);
      b.setInstantiatedFromStaticDataMemberIsPresent(false);
    }
  } else {
    b.setInstantiatedFromStaticDataMember(0);
    b.setInstantiatedFromStaticDataMemberIsPresent(false);
  }
  b.setLanguageLinkage(static_cast<mx::ast::LanguageLinkage>(mx::FromPasta(e.LanguageLinkage())));
  b.setPointOfInstantiation(es.EntityId(e.PointOfInstantiation()));
  b.setStorageClass(static_cast<mx::ast::StorageClass>(mx::FromPasta(e.StorageClass())));
  b.setStorageDuration(static_cast<mx::ast::StorageDuration>(mx::FromPasta(e.StorageDuration())));
  b.setTlsKind(static_cast<mx::ast::VarDeclTLSKind>(mx::FromPasta(e.TLSKind())));
  b.setTscSpec(static_cast<mx::ast::ThreadStorageClassSpecifier>(mx::FromPasta(e.TSCSpec())));
  auto v16 = e.TemplateInstantiationPattern();
  if (v16) {
    if (auto id16 = es.EntityId(v16.value())) {
      b.setTemplateInstantiationPattern(id16);
      b.setTemplateInstantiationPatternIsPresent(true);
    } else {
      b.setTemplateInstantiationPattern(0);
      b.setTemplateInstantiationPatternIsPresent(false);
    }
  } else {
    b.setTemplateInstantiationPattern(0);
    b.setTemplateInstantiationPatternIsPresent(false);
  }
  b.setTemplateSpecializationKind(static_cast<mx::ast::TemplateSpecializationKind>(mx::FromPasta(e.TemplateSpecializationKind())));
  b.setTemplateSpecializationKindForInstantiation(static_cast<mx::ast::TemplateSpecializationKind>(mx::FromPasta(e.TemplateSpecializationKindForInstantiation())));
  b.setHasConstantInitialization(e.HasConstantInitialization());
  b.setHasDependentAlignment(e.HasDependentAlignment());
  b.setHasExternalStorage(e.HasExternalStorage());
  b.setHasGlobalStorage(e.HasGlobalStorage());
  b.setHasInitializer(e.HasInitializer());
  b.setHasLocalStorage(e.HasLocalStorage());
  b.setIsArcPseudoStrong(e.IsARCPseudoStrong());
  b.setIsCxxForRangeDeclaration(e.IsCXXForRangeDeclaration());
  b.setIsConstexpr(e.IsConstexpr());
  b.setIsDirectInitializer(e.IsDirectInitializer());
  b.setIsEscapingByref(e.IsEscapingByref());
  b.setIsExceptionVariable(e.IsExceptionVariable());
  b.setIsExternUcC(e.IsExternC());
  b.setIsFileVariableDeclaration(e.IsFileVariableDeclaration());
  b.setIsFunctionOrMethodVariableDeclaration(e.IsFunctionOrMethodVariableDeclaration());
  b.setIsInExternCContext(e.IsInExternCContext());
  b.setIsInExternCxxContext(e.IsInExternCXXContext());
  b.setIsInitializerCapture(e.IsInitializerCapture());
  b.setIsInline(e.IsInline());
  b.setIsInlineSpecified(e.IsInlineSpecified());
  b.setIsKnownToBeDefined(e.IsKnownToBeDefined());
  b.setIsLocalVariableDeclaration(e.IsLocalVariableDeclaration());
  b.setIsLocalVariableDeclarationOrParm(e.IsLocalVariableDeclarationOrParm());
  b.setIsNrvoVariable(e.IsNRVOVariable());
  b.setIsNoDestroy(e.IsNoDestroy());
  b.setIsNonEscapingByref(e.IsNonEscapingByref());
  b.setIsObjCForDeclaration(e.IsObjCForDeclaration());
  b.setIsPreviousDeclarationInSameBlockScope(e.IsPreviousDeclarationInSameBlockScope());
  b.setIsStaticDataMember(e.IsStaticDataMember());
  b.setIsStaticLocal(e.IsStaticLocal());
  b.setIsThisDeclarationADemotedDefinition(e.IsThisDeclarationADemotedDefinition());
  b.setIsUsableInConstantExpressions(e.IsUsableInConstantExpressions());
  b.setMightBeUsableInConstantExpressions(e.MightBeUsableInConstantExpressions());
  b.setNeedsDestruction(static_cast<mx::ast::QualTypeDestructionKind>(mx::FromPasta(e.NeedsDestruction())));
}

void SerializeParmVarDecl(EntitySerializer &es, mx::ast::ParmVarDecl::Builder b, const pasta::ParmVarDecl &e) {
  SerializeVarDecl(es, b.initVarDecl(), e);
  auto sr1 = b.initDefaultArgumentRange();
  if (auto r1 = e.DefaultArgumentRange(); auto rs1 = r1.Size()) {
    sr1.setBeginId(es.EntityId(r1[0]));
    sr1.setEndId(es.EntityId(r1[rs1 - 1u]));
  } else {
    sr1.setBeginId(0);
    sr1.setEndId(0);
  }
  b.setObjCDeclQualifier(static_cast<mx::ast::DeclObjCDeclQualifier>(mx::FromPasta(e.ObjCDeclQualifier())));
  b.setHasDefaultArgument(e.HasDefaultArgument());
  b.setHasInheritedDefaultArgument(e.HasInheritedDefaultArgument());
  b.setHasUninstantiatedDefaultArgument(e.HasUninstantiatedDefaultArgument());
  b.setHasUnparsedDefaultArgument(e.HasUnparsedDefaultArgument());
  b.setIsDestroyedInCallee(e.IsDestroyedInCallee());
  b.setIsKnrPromoted(e.IsKNRPromoted());
  b.setIsObjCMethodParameter(e.IsObjCMethodParameter());
}

void SerializeOMPCapturedExprDecl(EntitySerializer &es, mx::ast::OMPCapturedExprDecl::Builder b, const pasta::OMPCapturedExprDecl &e) {
  SerializeVarDecl(es, b.initVarDecl(), e);
}

void SerializeImplicitParamDecl(EntitySerializer &es, mx::ast::ImplicitParamDecl::Builder b, const pasta::ImplicitParamDecl &e) {
  SerializeVarDecl(es, b.initVarDecl(), e);
  b.setParameterKind(static_cast<mx::ast::ImplicitParamDeclImplicitParamKind>(mx::FromPasta(e.ParameterKind())));
}

void SerializeDecompositionDecl(EntitySerializer &es, mx::ast::DecompositionDecl::Builder b, const pasta::DecompositionDecl &e) {
  SerializeVarDecl(es, b.initVarDecl(), e);
  auto v1 = e.Bindings();
  auto sv1 = b.initBindings(static_cast<unsigned>(v1.size()));
  auto i1 = 0u;
  for (const auto &e1 : v1) {
    sv1.set(i1, es.EntityId(e1));
    ++i1;
  }
}

void SerializeVarTemplateSpecializationDecl(EntitySerializer &es, mx::ast::VarTemplateSpecializationDecl::Builder b, const pasta::VarTemplateSpecializationDecl &e) {
  SerializeVarDecl(es, b.initVarDecl(), e);
  b.setExternToken(es.EntityId(e.ExternToken()));
  b.setSpecializationKind(static_cast<mx::ast::TemplateSpecializationKind>(mx::FromPasta(e.SpecializationKind())));
  b.setSpecializedTemplate(es.EntityId(e.SpecializedTemplate()));
  auto v4 = e.TemplateArguments();
  auto sv4 = b.initTemplateArguments(static_cast<unsigned>(v4.size()));
  auto i4 = 0u;
  for (const auto &e4 : v4) {
    SerializeTemplateArgument(es, sv4[i4], e4);
    ++i4;
  }
  auto v5 = e.TemplateInstantiationArguments();
  auto sv5 = b.initTemplateInstantiationArguments(static_cast<unsigned>(v5.size()));
  auto i5 = 0u;
  for (const auto &e5 : v5) {
    SerializeTemplateArgument(es, sv5[i5], e5);
    ++i5;
  }
  b.setTemplateKeywordToken(es.EntityId(e.TemplateKeywordToken()));
  b.setIsClassScopeExplicitSpecialization(e.IsClassScopeExplicitSpecialization());
  b.setIsExplicitInstantiationOrSpecialization(e.IsExplicitInstantiationOrSpecialization());
  b.setIsExplicitSpecialization(e.IsExplicitSpecialization());
}

void SerializeVarTemplatePartialSpecializationDecl(EntitySerializer &es, mx::ast::VarTemplatePartialSpecializationDecl::Builder b, const pasta::VarTemplatePartialSpecializationDecl &e) {
  SerializeVarTemplateSpecializationDecl(es, b.initVarTemplateSpecializationDecl(), e);
  b.setInstantiatedFromMember(es.EntityId(e.InstantiatedFromMember()));
  SerializeTemplateParameterList(es, b.initTemplateParameters(), e.TemplateParameters());
  b.setHasAssociatedConstraints(e.HasAssociatedConstraints());
}

void SerializeNonTypeTemplateParmDecl(EntitySerializer &es, mx::ast::NonTypeTemplateParmDecl::Builder b, const pasta::NonTypeTemplateParmDecl &e) {
  SerializeDeclaratorDecl(es, b.initDeclaratorDecl(), e);
  b.setDefaultArgumentWasInherited(e.DefaultArgumentWasInherited());
  b.setDefaultArgumentToken(es.EntityId(e.DefaultArgumentToken()));
  b.setHasDefaultArgument(e.HasDefaultArgument());
  b.setHasPlaceholderTypeConstraint(e.HasPlaceholderTypeConstraint());
  b.setIsExpandedParameterPack(e.IsExpandedParameterPack());
  b.setIsPackExpansion(e.IsPackExpansion());
}

void SerializeMSPropertyDecl(EntitySerializer &es, mx::ast::MSPropertyDecl::Builder b, const pasta::MSPropertyDecl &e) {
  SerializeDeclaratorDecl(es, b.initDeclaratorDecl(), e);
  b.setHasGetter(e.HasGetter());
  b.setHasSetter(e.HasSetter());
}

void SerializeFunctionDecl(EntitySerializer &es, mx::ast::FunctionDecl::Builder b, const pasta::FunctionDecl &e) {
  SerializeDeclaratorDecl(es, b.initDeclaratorDecl(), e);
  b.setDoesThisDeclarationHaveABody(e.DoesThisDeclarationHaveABody());
  b.setConstexprKind(static_cast<mx::ast::ConstexprSpecKind>(mx::FromPasta(e.ConstexprKind())));
  auto v3 = e.Definition();
  if (v3) {
    if (auto id3 = es.EntityId(v3.value())) {
      b.setDefinition(id3);
      b.setDefinitionIsPresent(true);
    } else {
      b.setDefinition(0);
      b.setDefinitionIsPresent(false);
    }
  } else {
    b.setDefinition(0);
    b.setDefinitionIsPresent(false);
  }
  auto v5 = e.DescribedFunctionTemplate();
  if (v5) {
    if (auto id5 = es.EntityId(v5.value())) {
      b.setDescribedFunctionTemplate(id5);
      b.setDescribedFunctionTemplateIsPresent(true);
    } else {
      b.setDescribedFunctionTemplate(0);
      b.setDescribedFunctionTemplateIsPresent(false);
    }
  } else {
    b.setDescribedFunctionTemplate(0);
    b.setDescribedFunctionTemplateIsPresent(false);
  }
  b.setEllipsisToken(es.EntityId(e.EllipsisToken()));
  auto sr8 = b.initExceptionSpecSourceRange();
  if (auto r8 = e.ExceptionSpecSourceRange(); auto rs8 = r8.Size()) {
    sr8.setBeginId(es.EntityId(r8[0]));
    sr8.setEndId(es.EntityId(r8[rs8 - 1u]));
  } else {
    sr8.setBeginId(0);
    sr8.setEndId(0);
  }
  b.setExceptionSpecType(static_cast<mx::ast::ExceptionSpecificationType>(mx::FromPasta(e.ExceptionSpecType())));
  auto v10 = e.InstantiatedFromMemberFunction();
  if (v10) {
    if (auto id10 = es.EntityId(v10.value())) {
      b.setInstantiatedFromMemberFunction(id10);
      b.setInstantiatedFromMemberFunctionIsPresent(true);
    } else {
      b.setInstantiatedFromMemberFunction(0);
      b.setInstantiatedFromMemberFunctionIsPresent(false);
    }
  } else {
    b.setInstantiatedFromMemberFunction(0);
    b.setInstantiatedFromMemberFunctionIsPresent(false);
  }
  b.setLanguageLinkage(static_cast<mx::ast::LanguageLinkage>(mx::FromPasta(e.LanguageLinkage())));
  b.setMultiVersionKind(static_cast<mx::ast::MultiVersionKind>(mx::FromPasta(e.MultiVersionKind())));
  b.setOverloadedOperator(static_cast<mx::ast::OverloadedOperatorKind>(mx::FromPasta(e.OverloadedOperator())));
  auto sr15 = b.initParametersSourceRange();
  if (auto r15 = e.ParametersSourceRange(); auto rs15 = r15.Size()) {
    sr15.setBeginId(es.EntityId(r15[0]));
    sr15.setEndId(es.EntityId(r15[rs15 - 1u]));
  } else {
    sr15.setBeginId(0);
    sr15.setEndId(0);
  }
  b.setPointOfInstantiation(es.EntityId(e.PointOfInstantiation()));
  auto v17 = e.PrimaryTemplate();
  if (v17) {
    if (auto id17 = es.EntityId(v17.value())) {
      b.setPrimaryTemplate(id17);
      b.setPrimaryTemplateIsPresent(true);
    } else {
      b.setPrimaryTemplate(0);
      b.setPrimaryTemplateIsPresent(false);
    }
  } else {
    b.setPrimaryTemplate(0);
    b.setPrimaryTemplateIsPresent(false);
  }
  auto sr19 = b.initReturnTypeSourceRange();
  if (auto r19 = e.ReturnTypeSourceRange(); auto rs19 = r19.Size()) {
    sr19.setBeginId(es.EntityId(r19[0]));
    sr19.setEndId(es.EntityId(r19[rs19 - 1u]));
  } else {
    sr19.setBeginId(0);
    sr19.setEndId(0);
  }
  b.setStorageClass(static_cast<mx::ast::StorageClass>(mx::FromPasta(e.StorageClass())));
  auto v21 = e.TemplateInstantiationPattern();
  if (v21) {
    if (auto id21 = es.EntityId(v21.value())) {
      b.setTemplateInstantiationPattern(id21);
      b.setTemplateInstantiationPatternIsPresent(true);
    } else {
      b.setTemplateInstantiationPattern(0);
      b.setTemplateInstantiationPatternIsPresent(false);
    }
  } else {
    b.setTemplateInstantiationPattern(0);
    b.setTemplateInstantiationPatternIsPresent(false);
  }
  b.setTemplateSpecializationKind(static_cast<mx::ast::TemplateSpecializationKind>(mx::FromPasta(e.TemplateSpecializationKind())));
  b.setTemplateSpecializationKindForInstantiation(static_cast<mx::ast::TemplateSpecializationKind>(mx::FromPasta(e.TemplateSpecializationKindForInstantiation())));
  b.setTemplatedKind(static_cast<mx::ast::FunctionDeclTemplatedKind>(mx::FromPasta(e.TemplatedKind())));
  b.setHasImplicitReturnZero(e.HasImplicitReturnZero());
  b.setHasInheritedPrototype(e.HasInheritedPrototype());
  b.setHasOneParameterOrDefaultArguments(e.HasOneParameterOrDefaultArguments());
  b.setHasPrototype(e.HasPrototype());
  b.setHasSkippedBody(e.HasSkippedBody());
  b.setHasTrivialBody(e.HasTrivialBody());
  b.setHasWrittenPrototype(e.HasWrittenPrototype());
  b.setInstantiationIsPending(e.InstantiationIsPending());
  b.setIsCpuDispatchMultiVersion(e.IsCPUDispatchMultiVersion());
  b.setIsCpuSpecificMultiVersion(e.IsCPUSpecificMultiVersion());
  b.setIsConsteval(e.IsConsteval());
  b.setIsConstexpr(e.IsConstexpr());
  b.setIsConstexprSpecified(e.IsConstexprSpecified());
  b.setIsDefaulted(e.IsDefaulted());
  b.setIsDeleted(e.IsDeleted());
  b.setIsDeletedAsWritten(e.IsDeletedAsWritten());
  b.setIsDestroyingOperatorDelete(e.IsDestroyingOperatorDelete());
  b.setIsExplicitlyDefaulted(e.IsExplicitlyDefaulted());
  b.setIsExternUcC(e.IsExternC());
  b.setIsFunctionTemplateSpecialization(e.IsFunctionTemplateSpecialization());
  b.setIsGlobal(e.IsGlobal());
  b.setIsImplicitlyInstantiable(e.IsImplicitlyInstantiable());
  b.setIsInExternCContext(e.IsInExternCContext());
  b.setIsInExternCxxContext(e.IsInExternCXXContext());
  b.setIsInlineBuiltinDeclaration(e.IsInlineBuiltinDeclaration());
  b.setIsInlineSpecified(e.IsInlineSpecified());
  b.setIsInlined(e.IsInlined());
  b.setIsLateTemplateParsed(e.IsLateTemplateParsed());
  b.setIsMsvcrtEntryPoint(e.IsMSVCRTEntryPoint());
  b.setIsMain(e.IsMain());
  b.setIsMultiVersion(e.IsMultiVersion());
  b.setIsNoReturn(e.IsNoReturn());
  b.setIsOverloadedOperator(e.IsOverloadedOperator());
  b.setIsPure(e.IsPure());
  b.setIsReplaceableGlobalAllocationFunction(e.IsReplaceableGlobalAllocationFunction());
  b.setIsStatic(e.IsStatic());
  b.setIsTargetMultiVersion(e.IsTargetMultiVersion());
  b.setIsTemplateInstantiation(e.IsTemplateInstantiation());
  b.setIsThisDeclarationADefinition(e.IsThisDeclarationADefinition());
  b.setIsThisDeclarationInstantiatedFromAFriendDefinition(e.IsThisDeclarationInstantiatedFromAFriendDefinition());
  b.setIsTrivial(e.IsTrivial());
  b.setIsTrivialForCall(e.IsTrivialForCall());
  b.setIsUserProvided(e.IsUserProvided());
  b.setIsVariadic(e.IsVariadic());
  b.setIsVirtualAsWritten(e.IsVirtualAsWritten());
  auto v71 = e.Parameters();
  auto sv71 = b.initParameters(static_cast<unsigned>(v71.size()));
  auto i71 = 0u;
  for (const auto &e71 : v71) {
    sv71.set(i71, es.EntityId(e71));
    ++i71;
  }
  b.setUsesSehTry(e.UsesSEHTry());
  b.setWillHaveBody(e.WillHaveBody());
  pasta::DeclContext dc74(e);
  auto v74 = dc74.AlreadyLoadedDeclarations();
  auto sv74 = b.initDeclarationsInContext(static_cast<unsigned>(v74.size()));
  auto i74 = 0u;
  for (const pasta::Decl &e74 : v74) {
    sv74.set(i74, es.EntityId(e74));
    ++i74;
  }
}

void SerializeCXXMethodDecl(EntitySerializer &es, mx::ast::CXXMethodDecl::Builder b, const pasta::CXXMethodDecl &e) {
  SerializeFunctionDecl(es, b.initFunctionDecl(), e);
  b.setParent(es.EntityId(e.Parent()));
  b.setReferenceQualifier(static_cast<mx::ast::RefQualifierKind>(mx::FromPasta(e.ReferenceQualifier())));
  b.setHasInlineBody(e.HasInlineBody());
  b.setIsConst(e.IsConst());
  b.setIsCopyAssignmentOperator(e.IsCopyAssignmentOperator());
  b.setIsInstance(e.IsInstance());
  b.setIsLambdaStaticInvoker(e.IsLambdaStaticInvoker());
  b.setIsMoveAssignmentOperator(e.IsMoveAssignmentOperator());
  b.setIsVirtual(e.IsVirtual());
  b.setIsVolatile(e.IsVolatile());
  auto v11 = e.OverriddenMethods();
  auto sv11 = b.initOverriddenMethods(static_cast<unsigned>(v11.size()));
  auto i11 = 0u;
  for (const auto &e11 : v11) {
    sv11.set(i11, es.EntityId(e11));
    ++i11;
  }
}

void SerializeCXXDestructorDecl(EntitySerializer &es, mx::ast::CXXDestructorDecl::Builder b, const pasta::CXXDestructorDecl &e) {
  SerializeCXXMethodDecl(es, b.initCxxMethodDecl(), e);
  b.setOperatorDelete(es.EntityId(e.OperatorDelete()));
}

void SerializeCXXConversionDecl(EntitySerializer &es, mx::ast::CXXConversionDecl::Builder b, const pasta::CXXConversionDecl &e) {
  SerializeCXXMethodDecl(es, b.initCxxMethodDecl(), e);
  b.setIsExplicit(e.IsExplicit());
  b.setIsLambdaToBlockPointerConversion(e.IsLambdaToBlockPointerConversion());
}

void SerializeCXXConstructorDecl(EntitySerializer &es, mx::ast::CXXConstructorDecl::Builder b, const pasta::CXXConstructorDecl &e) {
  SerializeCXXMethodDecl(es, b.initCxxMethodDecl(), e);
  b.setTargetConstructor(es.EntityId(e.TargetConstructor()));
  b.setIsDefaultConstructor(e.IsDefaultConstructor());
  b.setIsDelegatingConstructor(e.IsDelegatingConstructor());
  b.setIsExplicit(e.IsExplicit());
  b.setIsInheritingConstructor(e.IsInheritingConstructor());
  b.setIsSpecializationCopyingObject(e.IsSpecializationCopyingObject());
}

void SerializeCXXDeductionGuideDecl(EntitySerializer &es, mx::ast::CXXDeductionGuideDecl::Builder b, const pasta::CXXDeductionGuideDecl &e) {
  SerializeFunctionDecl(es, b.initFunctionDecl(), e);
  b.setCorrespondingConstructor(es.EntityId(e.CorrespondingConstructor()));
  b.setDeducedTemplate(es.EntityId(e.DeducedTemplate()));
  b.setIsCopyDeductionCandidate(e.IsCopyDeductionCandidate());
  b.setIsExplicit(e.IsExplicit());
}

void SerializeFieldDecl(EntitySerializer &es, mx::ast::FieldDecl::Builder b, const pasta::FieldDecl &e) {
  SerializeDeclaratorDecl(es, b.initDeclaratorDecl(), e);
  b.setInClassInitializerStyle(static_cast<mx::ast::InClassInitStyle>(mx::FromPasta(e.InClassInitializerStyle())));
  b.setParent(es.EntityId(e.Parent()));
  b.setHasCapturedVlaType(e.HasCapturedVLAType());
  b.setHasInClassInitializer(e.HasInClassInitializer());
  b.setIsAnonymousStructOrUnion(e.IsAnonymousStructOrUnion());
  b.setIsBitField(e.IsBitField());
  b.setIsMutable(e.IsMutable());
  b.setIsUnnamedBitfield(e.IsUnnamedBitfield());
  b.setIsZeroLengthBitField(e.IsZeroLengthBitField());
  b.setIsZeroSize(e.IsZeroSize());
}

void SerializeObjCIvarDecl(EntitySerializer &es, mx::ast::ObjCIvarDecl::Builder b, const pasta::ObjCIvarDecl &e) {
  SerializeFieldDecl(es, b.initFieldDecl(), e);
  b.setAccessControl(static_cast<mx::ast::ObjCIvarDeclAccessControl>(mx::FromPasta(e.AccessControl())));
  b.setCanonicalAccessControl(static_cast<mx::ast::ObjCIvarDeclAccessControl>(mx::FromPasta(e.CanonicalAccessControl())));
  b.setContainingInterface(es.EntityId(e.ContainingInterface()));
  b.setNextInstanceVariable(es.EntityId(e.NextInstanceVariable()));
  b.setSynthesize(e.Synthesize());
}

void SerializeObjCAtDefsFieldDecl(EntitySerializer &es, mx::ast::ObjCAtDefsFieldDecl::Builder b, const pasta::ObjCAtDefsFieldDecl &e) {
  SerializeFieldDecl(es, b.initFieldDecl(), e);
}

void SerializeBindingDecl(EntitySerializer &es, mx::ast::BindingDecl::Builder b, const pasta::BindingDecl &e) {
  SerializeValueDecl(es, b.initValueDecl(), e);
  b.setDecomposedDeclaration(es.EntityId(e.DecomposedDeclaration()));
  b.setHoldingVariable(es.EntityId(e.HoldingVariable()));
}

void SerializeOMPDeclarativeDirectiveValueDecl(EntitySerializer &es, mx::ast::OMPDeclarativeDirectiveValueDecl::Builder b, const pasta::OMPDeclarativeDirectiveValueDecl &e) {
  SerializeValueDecl(es, b.initValueDecl(), e);
}

void SerializeOMPDeclareMapperDecl(EntitySerializer &es, mx::ast::OMPDeclareMapperDecl::Builder b, const pasta::OMPDeclareMapperDecl &e) {
  SerializeOMPDeclarativeDirectiveValueDecl(es, b.initOmpDeclarativeDirectiveValueDecl(), e);
  b.setPrevDeclarationInScope(es.EntityId(e.PrevDeclarationInScope()));
  pasta::DeclContext dc2(e);
  auto v2 = dc2.AlreadyLoadedDeclarations();
  auto sv2 = b.initDeclarationsInContext(static_cast<unsigned>(v2.size()));
  auto i2 = 0u;
  for (const pasta::Decl &e2 : v2) {
    sv2.set(i2, es.EntityId(e2));
    ++i2;
  }
}

void SerializeUsingShadowDecl(EntitySerializer &es, mx::ast::UsingShadowDecl::Builder b, const pasta::UsingShadowDecl &e) {
  SerializeNamedDecl(es, b.initNamedDecl(), e);
  b.setIntroducer(es.EntityId(e.Introducer()));
  b.setNextUsingShadowDeclaration(es.EntityId(e.NextUsingShadowDeclaration()));
  b.setTargetDeclaration(es.EntityId(e.TargetDeclaration()));
}

void SerializeConstructorUsingShadowDecl(EntitySerializer &es, mx::ast::ConstructorUsingShadowDecl::Builder b, const pasta::ConstructorUsingShadowDecl &e) {
  SerializeUsingShadowDecl(es, b.initUsingShadowDecl(), e);
  b.setConstructsVirtualBase(e.ConstructsVirtualBase());
  b.setConstructedBaseClass(es.EntityId(e.ConstructedBaseClass()));
  auto v3 = e.ConstructedBaseClassShadowDeclaration();
  if (v3) {
    if (auto id3 = es.EntityId(v3.value())) {
      b.setConstructedBaseClassShadowDeclaration(id3);
      b.setConstructedBaseClassShadowDeclarationIsPresent(true);
    } else {
      b.setConstructedBaseClassShadowDeclaration(0);
      b.setConstructedBaseClassShadowDeclarationIsPresent(false);
    }
  } else {
    b.setConstructedBaseClassShadowDeclaration(0);
    b.setConstructedBaseClassShadowDeclarationIsPresent(false);
  }
  b.setNominatedBaseClass(es.EntityId(e.NominatedBaseClass()));
  auto v6 = e.NominatedBaseClassShadowDeclaration();
  if (v6) {
    if (auto id6 = es.EntityId(v6.value())) {
      b.setNominatedBaseClassShadowDeclaration(id6);
      b.setNominatedBaseClassShadowDeclarationIsPresent(true);
    } else {
      b.setNominatedBaseClassShadowDeclaration(0);
      b.setNominatedBaseClassShadowDeclarationIsPresent(false);
    }
  } else {
    b.setNominatedBaseClassShadowDeclaration(0);
    b.setNominatedBaseClassShadowDeclarationIsPresent(false);
  }
  b.setParent(es.EntityId(e.Parent()));
}

void SerializeUsingPackDecl(EntitySerializer &es, mx::ast::UsingPackDecl::Builder b, const pasta::UsingPackDecl &e) {
  SerializeNamedDecl(es, b.initNamedDecl(), e);
  auto v1 = e.Expansions();
  auto sv1 = b.initExpansions(static_cast<unsigned>(v1.size()));
  auto i1 = 0u;
  for (const auto &e1 : v1) {
    sv1.set(i1, es.EntityId(e1));
    ++i1;
  }
  b.setInstantiatedFromUsingDeclaration(es.EntityId(e.InstantiatedFromUsingDeclaration()));
}

void SerializeUsingDirectiveDecl(EntitySerializer &es, mx::ast::UsingDirectiveDecl::Builder b, const pasta::UsingDirectiveDecl &e) {
  SerializeNamedDecl(es, b.initNamedDecl(), e);
  b.setIdentifierToken(es.EntityId(e.IdentifierToken()));
  b.setNamespaceKeyToken(es.EntityId(e.NamespaceKeyToken()));
  b.setNominatedNamespace(es.EntityId(e.NominatedNamespace()));
  b.setNominatedNamespaceAsWritten(es.EntityId(e.NominatedNamespaceAsWritten()));
  b.setUsingToken(es.EntityId(e.UsingToken()));
}

void SerializeUnresolvedUsingIfExistsDecl(EntitySerializer &es, mx::ast::UnresolvedUsingIfExistsDecl::Builder b, const pasta::UnresolvedUsingIfExistsDecl &e) {
  SerializeNamedDecl(es, b.initNamedDecl(), e);
}

void SerializeTypeDecl(EntitySerializer &es, mx::ast::TypeDecl::Builder b, const pasta::TypeDecl &e) {
  SerializeNamedDecl(es, b.initNamedDecl(), e);
}

void SerializeTemplateTypeParmDecl(EntitySerializer &es, mx::ast::TemplateTypeParmDecl::Builder b, const pasta::TemplateTypeParmDecl &e) {
  SerializeTypeDecl(es, b.initTypeDecl(), e);
  b.setDefaultArgumentWasInherited(e.DefaultArgumentWasInherited());
  b.setDefaultArgumentToken(es.EntityId(e.DefaultArgumentToken()));
  b.setHasDefaultArgument(e.HasDefaultArgument());
  b.setHasTypeConstraint(e.HasTypeConstraint());
  b.setIsExpandedParameterPack(e.IsExpandedParameterPack());
  b.setIsPackExpansion(e.IsPackExpansion());
  b.setWasDeclaredWithTypename(e.WasDeclaredWithTypename());
}

void SerializeTagDecl(EntitySerializer &es, mx::ast::TagDecl::Builder b, const pasta::TagDecl &e) {
  SerializeTypeDecl(es, b.initTypeDecl(), e);
  auto sr1 = b.initBraceRange();
  if (auto r1 = e.BraceRange(); auto rs1 = r1.Size()) {
    sr1.setBeginId(es.EntityId(r1[0]));
    sr1.setEndId(es.EntityId(r1[rs1 - 1u]));
  } else {
    sr1.setBeginId(0);
    sr1.setEndId(0);
  }
  auto v2 = e.Definition();
  if (v2) {
    if (auto id2 = es.EntityId(v2.value())) {
      b.setDefinition(id2);
      b.setDefinitionIsPresent(true);
    } else {
      b.setDefinition(0);
      b.setDefinitionIsPresent(false);
    }
  } else {
    b.setDefinition(0);
    b.setDefinitionIsPresent(false);
  }
  b.setInnerTokenStart(es.EntityId(e.InnerTokenStart()));
  b.setOuterTokenStart(es.EntityId(e.OuterTokenStart()));
  b.setTagKind(static_cast<mx::ast::TagTypeKind>(mx::FromPasta(e.TagKind())));
  auto v7 = e.TypedefNameForAnonymousDeclaration();
  if (v7) {
    if (auto id7 = es.EntityId(v7.value())) {
      b.setTypedefNameForAnonymousDeclaration(id7);
      b.setTypedefNameForAnonymousDeclarationIsPresent(true);
    } else {
      b.setTypedefNameForAnonymousDeclaration(0);
      b.setTypedefNameForAnonymousDeclarationIsPresent(false);
    }
  } else {
    b.setTypedefNameForAnonymousDeclaration(0);
    b.setTypedefNameForAnonymousDeclarationIsPresent(false);
  }
  b.setHasNameForLinkage(e.HasNameForLinkage());
  b.setIsBeingDefined(e.IsBeingDefined());
  b.setIsClass(e.IsClass());
  b.setIsCompleteDefinition(e.IsCompleteDefinition());
  b.setIsCompleteDefinitionRequired(e.IsCompleteDefinitionRequired());
  b.setIsDependentType(e.IsDependentType());
  b.setIsEmbeddedInDeclarator(e.IsEmbeddedInDeclarator());
  b.setIsEnum(e.IsEnum());
  b.setIsFreeStanding(e.IsFreeStanding());
  b.setIsInterface(e.IsInterface());
  b.setIsStruct(e.IsStruct());
  b.setIsThisDeclarationADefinition(e.IsThisDeclarationADefinition());
  b.setIsUnion(e.IsUnion());
  b.setMayHaveOutOfDateDefinition(e.MayHaveOutOfDateDefinition());
  auto v23 = e.TemplateParameterLists();
  auto sv23 = b.initTemplateParameterLists(static_cast<unsigned>(v23.size()));
  auto i23 = 0u;
  for (const auto &e23 : v23) {
    SerializeTemplateParameterList(es, sv23[i23], e23);
    ++i23;
  }
  pasta::DeclContext dc24(e);
  auto v24 = dc24.AlreadyLoadedDeclarations();
  auto sv24 = b.initDeclarationsInContext(static_cast<unsigned>(v24.size()));
  auto i24 = 0u;
  for (const pasta::Decl &e24 : v24) {
    sv24.set(i24, es.EntityId(e24));
    ++i24;
  }
}

void SerializeRecordDecl(EntitySerializer &es, mx::ast::RecordDecl::Builder b, const pasta::RecordDecl &e) {
  SerializeTagDecl(es, b.initTagDecl(), e);
  b.setCanPassInRegisters(e.CanPassInRegisters());
  auto v2 = e.Fields();
  auto sv2 = b.initFields(static_cast<unsigned>(v2.size()));
  auto i2 = 0u;
  for (const auto &e2 : v2) {
    sv2.set(i2, es.EntityId(e2));
    ++i2;
  }
  auto v3 = e.FindFirstNamedDataMember();
  if (v3) {
    if (auto id3 = es.EntityId(v3.value())) {
      b.setFindFirstNamedDataMember(id3);
      b.setFindFirstNamedDataMemberIsPresent(true);
    } else {
      b.setFindFirstNamedDataMember(0);
      b.setFindFirstNamedDataMemberIsPresent(false);
    }
  } else {
    b.setFindFirstNamedDataMember(0);
    b.setFindFirstNamedDataMemberIsPresent(false);
  }
  b.setArgumentPassingRestrictions(static_cast<mx::ast::RecordDeclArgPassingKind>(mx::FromPasta(e.ArgumentPassingRestrictions())));
  b.setHasFlexibleArrayMember(e.HasFlexibleArrayMember());
  b.setHasLoadedFieldsFromExternalStorage(e.HasLoadedFieldsFromExternalStorage());
  b.setHasNonTrivialToPrimitiveCopyCUnion(e.HasNonTrivialToPrimitiveCopyCUnion());
  b.setHasNonTrivialToPrimitiveDefaultInitializeCUnion(e.HasNonTrivialToPrimitiveDefaultInitializeCUnion());
  b.setHasNonTrivialToPrimitiveDestructCUnion(e.HasNonTrivialToPrimitiveDestructCUnion());
  b.setHasObjectMember(e.HasObjectMember());
  b.setHasVolatileMember(e.HasVolatileMember());
  b.setIsAnonymousStructOrUnion(e.IsAnonymousStructOrUnion());
  b.setIsCapturedRecord(e.IsCapturedRecord());
  b.setIsInjectedClassName(e.IsInjectedClassName());
  b.setIsLambda(e.IsLambda());
  b.setIsMsStruct(e.IsMsStruct());
  b.setIsNonTrivialToPrimitiveCopy(e.IsNonTrivialToPrimitiveCopy());
  b.setIsNonTrivialToPrimitiveDefaultInitialize(e.IsNonTrivialToPrimitiveDefaultInitialize());
  b.setIsNonTrivialToPrimitiveDestroy(e.IsNonTrivialToPrimitiveDestroy());
  b.setIsOrContainsUnion(e.IsOrContainsUnion());
  b.setIsParameterDestroyedInCallee(e.IsParameterDestroyedInCallee());
  b.setMayInsertExtraPadding(e.MayInsertExtraPadding());
}

void SerializeCXXRecordDecl(EntitySerializer &es, mx::ast::CXXRecordDecl::Builder b, const pasta::CXXRecordDecl &e) {
  SerializeRecordDecl(es, b.initRecordDecl(), e);
  b.setAllowConstDefaultInitializer(e.AllowConstDefaultInitializer());
  auto v2 = e.Bases();
  auto sv2 = b.initBases(static_cast<unsigned>(v2.size()));
  auto i2 = 0u;
  for (const auto &e2 : v2) {
    SerializeCXXBaseSpecifier(es, sv2[i2], e2);
    ++i2;
  }
  b.setCalculateInheritanceModel(static_cast<mx::ast::MSInheritanceModel>(mx::FromPasta(e.CalculateInheritanceModel())));
  auto v4 = e.Constructors();
  auto sv4 = b.initConstructors(static_cast<unsigned>(v4.size()));
  auto i4 = 0u;
  for (const auto &e4 : v4) {
    sv4.set(i4, es.EntityId(e4));
    ++i4;
  }
  b.setDefaultedCopyConstructorIsDeleted(e.DefaultedCopyConstructorIsDeleted());
  b.setDefaultedDefaultConstructorIsConstexpr(e.DefaultedDefaultConstructorIsConstexpr());
  b.setDefaultedDestructorIsConstexpr(e.DefaultedDestructorIsConstexpr());
  b.setDefaultedDestructorIsDeleted(e.DefaultedDestructorIsDeleted());
  b.setDefaultedMoveConstructorIsDeleted(e.DefaultedMoveConstructorIsDeleted());
  auto v10 = e.Friends();
  auto sv10 = b.initFriends(static_cast<unsigned>(v10.size()));
  auto i10 = 0u;
  for (const auto &e10 : v10) {
    sv10.set(i10, es.EntityId(e10));
    ++i10;
  }
  b.setDependentLambdaCallOperator(es.EntityId(e.DependentLambdaCallOperator()));
  b.setDescribedClassTemplate(es.EntityId(e.DescribedClassTemplate()));
  b.setDestructor(es.EntityId(e.Destructor()));
  SerializeTemplateParameterList(es, b.initGenericLambdaTemplateParameterList(), e.GenericLambdaTemplateParameterList());
  b.setInstantiatedFromMemberClass(es.EntityId(e.InstantiatedFromMemberClass()));
  b.setLambdaCallOperator(es.EntityId(e.LambdaCallOperator()));
  b.setLambdaCaptureDefault(static_cast<mx::ast::LambdaCaptureDefault>(mx::FromPasta(e.LambdaCaptureDefault())));
  auto v18 = e.LambdaExplicitTemplateParameters();
  auto sv18 = b.initLambdaExplicitTemplateParameters(static_cast<unsigned>(v18.size()));
  auto i18 = 0u;
  for (const auto &e18 : v18) {
    sv18.set(i18, es.EntityId(e18));
    ++i18;
  }
  b.setMsInheritanceModel(static_cast<mx::ast::MSInheritanceModel>(mx::FromPasta(e.MSInheritanceModel())));
  b.setMsVtorDispMode(static_cast<mx::ast::MSVtorDispMode>(mx::FromPasta(e.MSVtorDispMode())));
  b.setMostRecentNonInjectedDeclaration(es.EntityId(e.MostRecentNonInjectedDeclaration()));
  b.setTemplateInstantiationPattern(es.EntityId(e.TemplateInstantiationPattern()));
  b.setTemplateSpecializationKind(static_cast<mx::ast::TemplateSpecializationKind>(mx::FromPasta(e.TemplateSpecializationKind())));
  b.setHasAnyDependentBases(e.HasAnyDependentBases());
  b.setHasConstexprDefaultConstructor(e.HasConstexprDefaultConstructor());
  b.setHasConstexprDestructor(e.HasConstexprDestructor());
  b.setHasConstexprNonCopyMoveConstructor(e.HasConstexprNonCopyMoveConstructor());
  b.setHasCopyAssignmentWithConstParameter(e.HasCopyAssignmentWithConstParameter());
  b.setHasCopyConstructorWithConstParameter(e.HasCopyConstructorWithConstParameter());
  b.setHasDefaultConstructor(e.HasDefaultConstructor());
  b.setHasDefinition(e.HasDefinition());
  b.setHasDirectFields(e.HasDirectFields());
  b.setHasFriends(e.HasFriends());
  b.setHasInClassInitializer(e.HasInClassInitializer());
  b.setHasInheritedAssignment(e.HasInheritedAssignment());
  b.setHasInheritedConstructor(e.HasInheritedConstructor());
  b.setHasIrrelevantDestructor(e.HasIrrelevantDestructor());
  b.setHasKnownLambdaInternalLinkage(e.HasKnownLambdaInternalLinkage());
  b.setHasMoveAssignment(e.HasMoveAssignment());
  b.setHasMoveConstructor(e.HasMoveConstructor());
  b.setHasMutableFields(e.HasMutableFields());
  b.setHasNonLiteralTypeFieldsOrBases(e.HasNonLiteralTypeFieldsOrBases());
  b.setHasNonTrivialCopyAssignment(e.HasNonTrivialCopyAssignment());
  b.setHasNonTrivialCopyConstructor(e.HasNonTrivialCopyConstructor());
  b.setHasNonTrivialCopyConstructorForCall(e.HasNonTrivialCopyConstructorForCall());
  b.setHasNonTrivialDefaultConstructor(e.HasNonTrivialDefaultConstructor());
  b.setHasNonTrivialDestructor(e.HasNonTrivialDestructor());
  b.setHasNonTrivialDestructorForCall(e.HasNonTrivialDestructorForCall());
  b.setHasNonTrivialMoveAssignment(e.HasNonTrivialMoveAssignment());
  b.setHasNonTrivialMoveConstructor(e.HasNonTrivialMoveConstructor());
  b.setHasNonTrivialMoveConstructorForCall(e.HasNonTrivialMoveConstructorForCall());
  b.setHasPrivateFields(e.HasPrivateFields());
  b.setHasProtectedFields(e.HasProtectedFields());
  b.setHasSimpleCopyAssignment(e.HasSimpleCopyAssignment());
  b.setHasSimpleCopyConstructor(e.HasSimpleCopyConstructor());
  b.setHasSimpleDestructor(e.HasSimpleDestructor());
  b.setHasSimpleMoveAssignment(e.HasSimpleMoveAssignment());
  b.setHasSimpleMoveConstructor(e.HasSimpleMoveConstructor());
  b.setHasTrivialCopyAssignment(e.HasTrivialCopyAssignment());
  b.setHasTrivialCopyConstructor(e.HasTrivialCopyConstructor());
  b.setHasTrivialCopyConstructorForCall(e.HasTrivialCopyConstructorForCall());
  b.setHasTrivialDefaultConstructor(e.HasTrivialDefaultConstructor());
  b.setHasTrivialDestructor(e.HasTrivialDestructor());
  b.setHasTrivialDestructorForCall(e.HasTrivialDestructorForCall());
  b.setHasTrivialMoveAssignment(e.HasTrivialMoveAssignment());
  b.setHasTrivialMoveConstructor(e.HasTrivialMoveConstructor());
  b.setHasTrivialMoveConstructorForCall(e.HasTrivialMoveConstructorForCall());
  b.setHasUninitializedReferenceMember(e.HasUninitializedReferenceMember());
  b.setHasUserDeclaredConstructor(e.HasUserDeclaredConstructor());
  b.setHasUserDeclaredCopyAssignment(e.HasUserDeclaredCopyAssignment());
  b.setHasUserDeclaredCopyConstructor(e.HasUserDeclaredCopyConstructor());
  b.setHasUserDeclaredDestructor(e.HasUserDeclaredDestructor());
  b.setHasUserDeclaredMoveAssignment(e.HasUserDeclaredMoveAssignment());
  b.setHasUserDeclaredMoveConstructor(e.HasUserDeclaredMoveConstructor());
  b.setHasUserDeclaredMoveOperation(e.HasUserDeclaredMoveOperation());
  b.setHasUserProvidedDefaultConstructor(e.HasUserProvidedDefaultConstructor());
  b.setHasVariantMembers(e.HasVariantMembers());
  b.setImplicitCopyAssignmentHasConstParameter(e.ImplicitCopyAssignmentHasConstParameter());
  b.setImplicitCopyConstructorHasConstParameter(e.ImplicitCopyConstructorHasConstParameter());
  b.setIsAbstract(e.IsAbstract());
  b.setIsAggregate(e.IsAggregate());
  b.setIsAnyDestructorNoReturn(e.IsAnyDestructorNoReturn());
  b.setIsCLike(e.IsCLike());
  b.setIsCxx11StandardLayout(e.IsCXX11StandardLayout());
  b.setIsDependentLambda(e.IsDependentLambda());
  b.setIsDynamicClass(e.IsDynamicClass());
  b.setIsEffectivelyFinal(e.IsEffectivelyFinal());
  b.setIsEmpty(e.IsEmpty());
  b.setIsGenericLambda(e.IsGenericLambda());
  b.setIsInterfaceLike(e.IsInterfaceLike());
  b.setIsLiteral(e.IsLiteral());
  b.setIsLocalClass(es.EntityId(e.IsLocalClass()));
  b.setIsPod(e.IsPOD());
  b.setIsParsingBaseSpecifiers(e.IsParsingBaseSpecifiers());
  b.setIsPolymorphic(e.IsPolymorphic());
  b.setIsStandardLayout(e.IsStandardLayout());
  b.setIsStructural(e.IsStructural());
  b.setIsTrivial(e.IsTrivial());
  b.setIsTriviallyCopyable(e.IsTriviallyCopyable());
  b.setLambdaIsDefaultConstructibleAndAssignable(e.LambdaIsDefaultConstructibleAndAssignable());
  b.setMayBeAbstract(e.MayBeAbstract());
  b.setMayBeDynamicClass(e.MayBeDynamicClass());
  b.setMayBeNonDynamicClass(e.MayBeNonDynamicClass());
  auto v104 = e.Methods();
  auto sv104 = b.initMethods(static_cast<unsigned>(v104.size()));
  auto i104 = 0u;
  for (const auto &e104 : v104) {
    sv104.set(i104, es.EntityId(e104));
    ++i104;
  }
  b.setNeedsImplicitCopyAssignment(e.NeedsImplicitCopyAssignment());
  b.setNeedsImplicitCopyConstructor(e.NeedsImplicitCopyConstructor());
  b.setNeedsImplicitDefaultConstructor(e.NeedsImplicitDefaultConstructor());
  b.setNeedsImplicitDestructor(e.NeedsImplicitDestructor());
  b.setNeedsImplicitMoveAssignment(e.NeedsImplicitMoveAssignment());
  b.setNeedsImplicitMoveConstructor(e.NeedsImplicitMoveConstructor());
  b.setNeedsOverloadResolutionForCopyAssignment(e.NeedsOverloadResolutionForCopyAssignment());
  b.setNeedsOverloadResolutionForCopyConstructor(e.NeedsOverloadResolutionForCopyConstructor());
  b.setNeedsOverloadResolutionForDestructor(e.NeedsOverloadResolutionForDestructor());
  b.setNeedsOverloadResolutionForMoveAssignment(e.NeedsOverloadResolutionForMoveAssignment());
  b.setNeedsOverloadResolutionForMoveConstructor(e.NeedsOverloadResolutionForMoveConstructor());
  b.setNullFieldOffsetIsZero(e.NullFieldOffsetIsZero());
  auto v117 = e.VirtualBases();
  auto sv117 = b.initVirtualBases(static_cast<unsigned>(v117.size()));
  auto i117 = 0u;
  for (const auto &e117 : v117) {
    SerializeCXXBaseSpecifier(es, sv117[i117], e117);
    ++i117;
  }
}

void SerializeClassTemplateSpecializationDecl(EntitySerializer &es, mx::ast::ClassTemplateSpecializationDecl::Builder b, const pasta::ClassTemplateSpecializationDecl &e) {
  SerializeCXXRecordDecl(es, b.initCxxRecordDecl(), e);
  b.setExternToken(es.EntityId(e.ExternToken()));
  b.setPointOfInstantiation(es.EntityId(e.PointOfInstantiation()));
  b.setSpecializationKind(static_cast<mx::ast::TemplateSpecializationKind>(mx::FromPasta(e.SpecializationKind())));
  b.setSpecializedTemplate(es.EntityId(e.SpecializedTemplate()));
  auto v5 = e.TemplateArguments();
  auto sv5 = b.initTemplateArguments(static_cast<unsigned>(v5.size()));
  auto i5 = 0u;
  for (const auto &e5 : v5) {
    SerializeTemplateArgument(es, sv5[i5], e5);
    ++i5;
  }
  auto v6 = e.TemplateInstantiationArguments();
  auto sv6 = b.initTemplateInstantiationArguments(static_cast<unsigned>(v6.size()));
  auto i6 = 0u;
  for (const auto &e6 : v6) {
    SerializeTemplateArgument(es, sv6[i6], e6);
    ++i6;
  }
  b.setTemplateKeywordToken(es.EntityId(e.TemplateKeywordToken()));
  b.setIsClassScopeExplicitSpecialization(e.IsClassScopeExplicitSpecialization());
  b.setIsExplicitInstantiationOrSpecialization(e.IsExplicitInstantiationOrSpecialization());
  b.setIsExplicitSpecialization(e.IsExplicitSpecialization());
}

void SerializeClassTemplatePartialSpecializationDecl(EntitySerializer &es, mx::ast::ClassTemplatePartialSpecializationDecl::Builder b, const pasta::ClassTemplatePartialSpecializationDecl &e) {
  SerializeClassTemplateSpecializationDecl(es, b.initClassTemplateSpecializationDecl(), e);
  b.setInstantiatedFromMember(es.EntityId(e.InstantiatedFromMember()));
  b.setInstantiatedFromMemberTemplate(es.EntityId(e.InstantiatedFromMemberTemplate()));
  SerializeTemplateParameterList(es, b.initTemplateParameters(), e.TemplateParameters());
  b.setHasAssociatedConstraints(e.HasAssociatedConstraints());
}

void SerializeEnumDecl(EntitySerializer &es, mx::ast::EnumDecl::Builder b, const pasta::EnumDecl &e) {
  SerializeTagDecl(es, b.initTagDecl(), e);
  auto v1 = e.Enumerators();
  auto sv1 = b.initEnumerators(static_cast<unsigned>(v1.size()));
  auto i1 = 0u;
  for (const auto &e1 : v1) {
    sv1.set(i1, es.EntityId(e1));
    ++i1;
  }
  auto v2 = e.InstantiatedFromMemberEnum();
  if (v2) {
    if (auto id2 = es.EntityId(v2.value())) {
      b.setInstantiatedFromMemberEnum(id2);
      b.setInstantiatedFromMemberEnumIsPresent(true);
    } else {
      b.setInstantiatedFromMemberEnum(0);
      b.setInstantiatedFromMemberEnumIsPresent(false);
    }
  } else {
    b.setInstantiatedFromMemberEnum(0);
    b.setInstantiatedFromMemberEnumIsPresent(false);
  }
  auto sr4 = b.initIntegerTypeRange();
  if (auto r4 = e.IntegerTypeRange(); auto rs4 = r4.Size()) {
    sr4.setBeginId(es.EntityId(r4[0]));
    sr4.setEndId(es.EntityId(r4[rs4 - 1u]));
  } else {
    sr4.setBeginId(0);
    sr4.setEndId(0);
  }
  auto v5 = e.TemplateInstantiationPattern();
  if (v5) {
    if (auto id5 = es.EntityId(v5.value())) {
      b.setTemplateInstantiationPattern(id5);
      b.setTemplateInstantiationPatternIsPresent(true);
    } else {
      b.setTemplateInstantiationPattern(0);
      b.setTemplateInstantiationPatternIsPresent(false);
    }
  } else {
    b.setTemplateInstantiationPattern(0);
    b.setTemplateInstantiationPatternIsPresent(false);
  }
  b.setTemplateSpecializationKind(static_cast<mx::ast::TemplateSpecializationKind>(mx::FromPasta(e.TemplateSpecializationKind())));
  b.setIsClosed(e.IsClosed());
  b.setIsClosedFlag(e.IsClosedFlag());
  b.setIsClosedNonFlag(e.IsClosedNonFlag());
  b.setIsComplete(e.IsComplete());
  b.setIsFixed(e.IsFixed());
  b.setIsScoped(e.IsScoped());
  b.setIsScopedUsingClassTag(e.IsScopedUsingClassTag());
}

void SerializeUnresolvedUsingTypenameDecl(EntitySerializer &es, mx::ast::UnresolvedUsingTypenameDecl::Builder b, const pasta::UnresolvedUsingTypenameDecl &e) {
  SerializeTypeDecl(es, b.initTypeDecl(), e);
  b.setEllipsisToken(es.EntityId(e.EllipsisToken()));
  b.setTypenameToken(es.EntityId(e.TypenameToken()));
  b.setUsingToken(es.EntityId(e.UsingToken()));
  b.setIsPackExpansion(e.IsPackExpansion());
}

void SerializeTypedefNameDecl(EntitySerializer &es, mx::ast::TypedefNameDecl::Builder b, const pasta::TypedefNameDecl &e) {
  SerializeTypeDecl(es, b.initTypeDecl(), e);
  auto v1 = e.AnonymousDeclarationWithTypedefName();
  if (v1) {
    if (auto id1 = es.EntityId(v1.value())) {
      b.setAnonymousDeclarationWithTypedefName(id1);
      b.setAnonymousDeclarationWithTypedefNameIsPresent(true);
    } else {
      b.setAnonymousDeclarationWithTypedefName(0);
      b.setAnonymousDeclarationWithTypedefNameIsPresent(false);
    }
  } else {
    b.setAnonymousDeclarationWithTypedefName(0);
    b.setAnonymousDeclarationWithTypedefNameIsPresent(false);
  }
  b.setIsModed(e.IsModed());
  b.setIsTransparentTag(e.IsTransparentTag());
}

void SerializeTypedefDecl(EntitySerializer &es, mx::ast::TypedefDecl::Builder b, const pasta::TypedefDecl &e) {
  SerializeTypedefNameDecl(es, b.initTypedefNameDecl(), e);
}

void SerializeTypeAliasDecl(EntitySerializer &es, mx::ast::TypeAliasDecl::Builder b, const pasta::TypeAliasDecl &e) {
  SerializeTypedefNameDecl(es, b.initTypedefNameDecl(), e);
  auto v1 = e.DescribedAliasTemplate();
  if (v1) {
    if (auto id1 = es.EntityId(v1.value())) {
      b.setDescribedAliasTemplate(id1);
      b.setDescribedAliasTemplateIsPresent(true);
    } else {
      b.setDescribedAliasTemplate(0);
      b.setDescribedAliasTemplateIsPresent(false);
    }
  } else {
    b.setDescribedAliasTemplate(0);
    b.setDescribedAliasTemplateIsPresent(false);
  }
}

void SerializeObjCTypeParamDecl(EntitySerializer &es, mx::ast::ObjCTypeParamDecl::Builder b, const pasta::ObjCTypeParamDecl &e) {
  SerializeTypedefNameDecl(es, b.initTypedefNameDecl(), e);
  b.setColonToken(es.EntityId(e.ColonToken()));
  b.setVariance(static_cast<mx::ast::ObjCTypeParamVariance>(mx::FromPasta(e.Variance())));
  b.setVarianceToken(es.EntityId(e.VarianceToken()));
  b.setHasExplicitBound(e.HasExplicitBound());
}

void SerializeTemplateDecl(EntitySerializer &es, mx::ast::TemplateDecl::Builder b, const pasta::TemplateDecl &e) {
  SerializeNamedDecl(es, b.initNamedDecl(), e);
  SerializeTemplateParameterList(es, b.initTemplateParameters(), e.TemplateParameters());
  b.setTemplatedDeclaration(es.EntityId(e.TemplatedDeclaration()));
  b.setHasAssociatedConstraints(e.HasAssociatedConstraints());
}

void SerializeRedeclarableTemplateDecl(EntitySerializer &es, mx::ast::RedeclarableTemplateDecl::Builder b, const pasta::RedeclarableTemplateDecl &e) {
  SerializeTemplateDecl(es, b.initTemplateDecl(), e);
  b.setInstantiatedFromMemberTemplate(es.EntityId(e.InstantiatedFromMemberTemplate()));
  b.setIsMemberSpecialization(e.IsMemberSpecialization());
}

void SerializeFunctionTemplateDecl(EntitySerializer &es, mx::ast::FunctionTemplateDecl::Builder b, const pasta::FunctionTemplateDecl &e) {
  SerializeRedeclarableTemplateDecl(es, b.initRedeclarableTemplateDecl(), e);
  b.setIsAbbreviated(e.IsAbbreviated());
  b.setIsThisDeclarationADefinition(e.IsThisDeclarationADefinition());
  auto v3 = e.Specializations();
  auto sv3 = b.initSpecializations(static_cast<unsigned>(v3.size()));
  auto i3 = 0u;
  for (const auto &e3 : v3) {
    sv3.set(i3, es.EntityId(e3));
    ++i3;
  }
}

void SerializeClassTemplateDecl(EntitySerializer &es, mx::ast::ClassTemplateDecl::Builder b, const pasta::ClassTemplateDecl &e) {
  SerializeRedeclarableTemplateDecl(es, b.initRedeclarableTemplateDecl(), e);
  b.setIsThisDeclarationADefinition(e.IsThisDeclarationADefinition());
  auto v2 = e.Specializations();
  auto sv2 = b.initSpecializations(static_cast<unsigned>(v2.size()));
  auto i2 = 0u;
  for (const auto &e2 : v2) {
    sv2.set(i2, es.EntityId(e2));
    ++i2;
  }
}

void SerializeVarTemplateDecl(EntitySerializer &es, mx::ast::VarTemplateDecl::Builder b, const pasta::VarTemplateDecl &e) {
  SerializeRedeclarableTemplateDecl(es, b.initRedeclarableTemplateDecl(), e);
  b.setIsThisDeclarationADefinition(e.IsThisDeclarationADefinition());
  auto v2 = e.Specializations();
  auto sv2 = b.initSpecializations(static_cast<unsigned>(v2.size()));
  auto i2 = 0u;
  for (const auto &e2 : v2) {
    sv2.set(i2, es.EntityId(e2));
    ++i2;
  }
}

void SerializeTypeAliasTemplateDecl(EntitySerializer &es, mx::ast::TypeAliasTemplateDecl::Builder b, const pasta::TypeAliasTemplateDecl &e) {
  SerializeRedeclarableTemplateDecl(es, b.initRedeclarableTemplateDecl(), e);
}

void SerializeConceptDecl(EntitySerializer &es, mx::ast::ConceptDecl::Builder b, const pasta::ConceptDecl &e) {
  SerializeTemplateDecl(es, b.initTemplateDecl(), e);
  b.setIsTypeConcept(e.IsTypeConcept());
}

void SerializeBuiltinTemplateDecl(EntitySerializer &es, mx::ast::BuiltinTemplateDecl::Builder b, const pasta::BuiltinTemplateDecl &e) {
  SerializeTemplateDecl(es, b.initTemplateDecl(), e);
}

void SerializeTemplateTemplateParmDecl(EntitySerializer &es, mx::ast::TemplateTemplateParmDecl::Builder b, const pasta::TemplateTemplateParmDecl &e) {
  SerializeTemplateDecl(es, b.initTemplateDecl(), e);
  b.setDefaultArgumentWasInherited(e.DefaultArgumentWasInherited());
  b.setDefaultArgumentToken(es.EntityId(e.DefaultArgumentToken()));
  b.setHasDefaultArgument(e.HasDefaultArgument());
  b.setIsExpandedParameterPack(e.IsExpandedParameterPack());
  b.setIsPackExpansion(e.IsPackExpansion());
}

void SerializeObjCPropertyDecl(EntitySerializer &es, mx::ast::ObjCPropertyDecl::Builder b, const pasta::ObjCPropertyDecl &e) {
  SerializeNamedDecl(es, b.initNamedDecl(), e);
  b.setAtToken(es.EntityId(e.AtToken()));
  b.setGetterMethodDeclaration(es.EntityId(e.GetterMethodDeclaration()));
  b.setGetterNameToken(es.EntityId(e.GetterNameToken()));
  b.setLParenToken(es.EntityId(e.LParenToken()));
  b.setPropertyImplementation(static_cast<mx::ast::ObjCPropertyDeclPropertyControl>(mx::FromPasta(e.PropertyImplementation())));
  b.setPropertyInstanceVariableDeclaration(es.EntityId(e.PropertyInstanceVariableDeclaration()));
  b.setQueryKind(static_cast<mx::ast::ObjCPropertyQueryKind>(mx::FromPasta(e.QueryKind())));
  b.setSetterKind(static_cast<mx::ast::ObjCPropertyDeclSetterKind>(mx::FromPasta(e.SetterKind())));
  b.setSetterMethodDeclaration(es.EntityId(e.SetterMethodDeclaration()));
  b.setSetterNameToken(es.EntityId(e.SetterNameToken()));
  b.setIsAtomic(e.IsAtomic());
  b.setIsClassProperty(e.IsClassProperty());
  b.setIsDirectProperty(e.IsDirectProperty());
  b.setIsInstanceProperty(e.IsInstanceProperty());
  b.setIsOptional(e.IsOptional());
  b.setIsReadOnly(e.IsReadOnly());
  b.setIsRetaining(e.IsRetaining());
}

void SerializeObjCMethodDecl(EntitySerializer &es, mx::ast::ObjCMethodDecl::Builder b, const pasta::ObjCMethodDecl &e) {
  SerializeNamedDecl(es, b.initNamedDecl(), e);
  b.setDefinedInNsObject(e.DefinedInNSObject());
  b.setFindPropertyDeclaration(es.EntityId(e.FindPropertyDeclaration()));
  b.setCategory(es.EntityId(e.Category()));
  b.setClassInterface(es.EntityId(e.ClassInterface()));
  b.setCmdDeclaration(es.EntityId(e.CmdDeclaration()));
  b.setDeclaratorEndToken(es.EntityId(e.DeclaratorEndToken()));
  b.setImplementationControl(static_cast<mx::ast::ObjCMethodDeclImplementationControl>(mx::FromPasta(e.ImplementationControl())));
  b.setMethodFamily(static_cast<mx::ast::ObjCMethodFamily>(mx::FromPasta(e.MethodFamily())));
  b.setObjCDeclQualifier(static_cast<mx::ast::DeclObjCDeclQualifier>(mx::FromPasta(e.ObjCDeclQualifier())));
  auto sr10 = b.initReturnTypeSourceRange();
  if (auto r10 = e.ReturnTypeSourceRange(); auto rs10 = r10.Size()) {
    sr10.setBeginId(es.EntityId(r10[0]));
    sr10.setEndId(es.EntityId(r10[rs10 - 1u]));
  } else {
    sr10.setBeginId(0);
    sr10.setEndId(0);
  }
  b.setSelectorStartToken(es.EntityId(e.SelectorStartToken()));
  b.setSelfDeclaration(es.EntityId(e.SelfDeclaration()));
  b.setHasRedeclaration(e.HasRedeclaration());
  b.setHasRelatedResultType(e.HasRelatedResultType());
  b.setHasSkippedBody(e.HasSkippedBody());
  b.setIsClassMethod(e.IsClassMethod());
  b.setIsDefined(e.IsDefined());
  b.setIsDesignatedInitializerForTheInterface(e.IsDesignatedInitializerForTheInterface());
  b.setIsDirectMethod(e.IsDirectMethod());
  b.setIsInstanceMethod(e.IsInstanceMethod());
  b.setIsOptional(e.IsOptional());
  b.setIsOverriding(e.IsOverriding());
  b.setIsPropertyAccessor(e.IsPropertyAccessor());
  b.setIsRedeclaration(e.IsRedeclaration());
  b.setIsSynthesizedAccessorStub(e.IsSynthesizedAccessorStub());
  b.setIsThisDeclarationADefinition(e.IsThisDeclarationADefinition());
  b.setIsThisDeclarationADesignatedInitializer(e.IsThisDeclarationADesignatedInitializer());
  b.setIsVariadic(e.IsVariadic());
  auto v29 = e.Parameters();
  auto sv29 = b.initParameters(static_cast<unsigned>(v29.size()));
  auto i29 = 0u;
  for (const auto &e29 : v29) {
    sv29.set(i29, es.EntityId(e29));
    ++i29;
  }
  auto v30 = e.SelectorTokens();
  auto sv30 = b.initSelectorTokens(static_cast<unsigned>(v30.size()));
  auto i30 = 0u;
  for (const auto &e30 : v30) {
    sv30.set(i30, es.EntityId(e30));
    ++i30;
  }
  pasta::DeclContext dc31(e);
  auto v31 = dc31.AlreadyLoadedDeclarations();
  auto sv31 = b.initDeclarationsInContext(static_cast<unsigned>(v31.size()));
  auto i31 = 0u;
  for (const pasta::Decl &e31 : v31) {
    sv31.set(i31, es.EntityId(e31));
    ++i31;
  }
}

void SerializeObjCContainerDecl(EntitySerializer &es, mx::ast::ObjCContainerDecl::Builder b, const pasta::ObjCContainerDecl &e) {
  SerializeNamedDecl(es, b.initNamedDecl(), e);
  auto v1 = e.ClassMethods();
  auto sv1 = b.initClassMethods(static_cast<unsigned>(v1.size()));
  auto i1 = 0u;
  for (const auto &e1 : v1) {
    sv1.set(i1, es.EntityId(e1));
    ++i1;
  }
  auto v2 = e.ClassProperties();
  auto sv2 = b.initClassProperties(static_cast<unsigned>(v2.size()));
  auto i2 = 0u;
  for (const auto &e2 : v2) {
    sv2.set(i2, es.EntityId(e2));
    ++i2;
  }
  auto sr3 = b.initAtEndRange();
  if (auto r3 = e.AtEndRange(); auto rs3 = r3.Size()) {
    sr3.setBeginId(es.EntityId(r3[0]));
    sr3.setEndId(es.EntityId(r3[rs3 - 1u]));
  } else {
    sr3.setBeginId(0);
    sr3.setEndId(0);
  }
  b.setAtStartToken(es.EntityId(e.AtStartToken()));
  auto v5 = e.InstanceMethods();
  auto sv5 = b.initInstanceMethods(static_cast<unsigned>(v5.size()));
  auto i5 = 0u;
  for (const auto &e5 : v5) {
    sv5.set(i5, es.EntityId(e5));
    ++i5;
  }
  auto v6 = e.InstanceProperties();
  auto sv6 = b.initInstanceProperties(static_cast<unsigned>(v6.size()));
  auto i6 = 0u;
  for (const auto &e6 : v6) {
    sv6.set(i6, es.EntityId(e6));
    ++i6;
  }
  auto v7 = e.Methods();
  auto sv7 = b.initMethods(static_cast<unsigned>(v7.size()));
  auto i7 = 0u;
  for (const auto &e7 : v7) {
    sv7.set(i7, es.EntityId(e7));
    ++i7;
  }
  auto v8 = e.Properties();
  auto sv8 = b.initProperties(static_cast<unsigned>(v8.size()));
  auto i8 = 0u;
  for (const auto &e8 : v8) {
    sv8.set(i8, es.EntityId(e8));
    ++i8;
  }
  pasta::DeclContext dc9(e);
  auto v9 = dc9.AlreadyLoadedDeclarations();
  auto sv9 = b.initDeclarationsInContext(static_cast<unsigned>(v9.size()));
  auto i9 = 0u;
  for (const pasta::Decl &e9 : v9) {
    sv9.set(i9, es.EntityId(e9));
    ++i9;
  }
}

void SerializeObjCCategoryDecl(EntitySerializer &es, mx::ast::ObjCCategoryDecl::Builder b, const pasta::ObjCCategoryDecl &e) {
  SerializeObjCContainerDecl(es, b.initObjCContainerDecl(), e);
  b.setIsClassExtension(e.IsClassExtension());
  b.setCategoryNameToken(es.EntityId(e.CategoryNameToken()));
  b.setClassInterface(es.EntityId(e.ClassInterface()));
  b.setImplementation(es.EntityId(e.Implementation()));
  b.setInstanceVariableLBraceToken(es.EntityId(e.InstanceVariableLBraceToken()));
  b.setInstanceVariableRBraceToken(es.EntityId(e.InstanceVariableRBraceToken()));
  b.setNextClassCategory(es.EntityId(e.NextClassCategory()));
  b.setNextClassCategoryRaw(es.EntityId(e.NextClassCategoryRaw()));
  auto v9 = e.InstanceVariables();
  auto sv9 = b.initInstanceVariables(static_cast<unsigned>(v9.size()));
  auto i9 = 0u;
  for (const auto &e9 : v9) {
    sv9.set(i9, es.EntityId(e9));
    ++i9;
  }
  auto v10 = e.ProtocolTokens();
  auto sv10 = b.initProtocolTokens(static_cast<unsigned>(v10.size()));
  auto i10 = 0u;
  for (const auto &e10 : v10) {
    sv10.set(i10, es.EntityId(e10));
    ++i10;
  }
  auto v11 = e.Protocols();
  auto sv11 = b.initProtocols(static_cast<unsigned>(v11.size()));
  auto i11 = 0u;
  for (const auto &e11 : v11) {
    sv11.set(i11, es.EntityId(e11));
    ++i11;
  }
}

void SerializeObjCProtocolDecl(EntitySerializer &es, mx::ast::ObjCProtocolDecl::Builder b, const pasta::ObjCProtocolDecl &e) {
  SerializeObjCContainerDecl(es, b.initObjCContainerDecl(), e);
  b.setDefinition(es.EntityId(e.Definition()));
  auto v2 = e.ObjCRuntimeNameAsString();
  std::string s2(v2.data(), v2.size());
  b.setObjCRuntimeNameAsString(s2);
  b.setHasDefinition(e.HasDefinition());
  b.setIsNonRuntimeProtocol(e.IsNonRuntimeProtocol());
  b.setIsThisDeclarationADefinition(e.IsThisDeclarationADefinition());
  auto v6 = e.ProtocolTokens();
  auto sv6 = b.initProtocolTokens(static_cast<unsigned>(v6.size()));
  auto i6 = 0u;
  for (const auto &e6 : v6) {
    sv6.set(i6, es.EntityId(e6));
    ++i6;
  }
  auto v7 = e.Protocols();
  auto sv7 = b.initProtocols(static_cast<unsigned>(v7.size()));
  auto i7 = 0u;
  for (const auto &e7 : v7) {
    sv7.set(i7, es.EntityId(e7));
    ++i7;
  }
}

void SerializeObjCInterfaceDecl(EntitySerializer &es, mx::ast::ObjCInterfaceDecl::Builder b, const pasta::ObjCInterfaceDecl &e) {
  SerializeObjCContainerDecl(es, b.initObjCContainerDecl(), e);
  auto v1 = e.AllReferencedProtocols();
  auto sv1 = b.initAllReferencedProtocols(static_cast<unsigned>(v1.size()));
  auto i1 = 0u;
  for (const auto &e1 : v1) {
    sv1.set(i1, es.EntityId(e1));
    ++i1;
  }
  b.setDeclaresOrInheritsDesignatedInitializers(e.DeclaresOrInheritsDesignatedInitializers());
  b.setCategoryListRaw(es.EntityId(e.CategoryListRaw()));
  b.setDefinition(es.EntityId(e.Definition()));
  b.setEndOfDefinitionToken(es.EntityId(e.EndOfDefinitionToken()));
  b.setImplementation(es.EntityId(e.Implementation()));
  auto v7 = e.ObjCRuntimeNameAsString();
  std::string s7(v7.data(), v7.size());
  b.setObjCRuntimeNameAsString(s7);
  b.setSuperClass(es.EntityId(e.SuperClass()));
  b.setSuperClassToken(es.EntityId(e.SuperClassToken()));
  b.setHasDefinition(e.HasDefinition());
  b.setHasDesignatedInitializers(e.HasDesignatedInitializers());
  b.setIsArcWeakrefUnavailable(e.IsArcWeakrefUnavailable());
  b.setIsImplicitInterfaceDeclaration(e.IsImplicitInterfaceDeclaration());
  b.setIsObjCRequiresPropertyDefinitions(es.EntityId(e.IsObjCRequiresPropertyDefinitions()));
  b.setIsThisDeclarationADefinition(e.IsThisDeclarationADefinition());
  auto v16 = e.InstanceVariables();
  auto sv16 = b.initInstanceVariables(static_cast<unsigned>(v16.size()));
  auto i16 = 0u;
  for (const auto &e16 : v16) {
    sv16.set(i16, es.EntityId(e16));
    ++i16;
  }
  auto v17 = e.KnownCategories();
  auto sv17 = b.initKnownCategories(static_cast<unsigned>(v17.size()));
  auto i17 = 0u;
  for (const auto &e17 : v17) {
    sv17.set(i17, es.EntityId(e17));
    ++i17;
  }
  auto v18 = e.KnownExtensions();
  auto sv18 = b.initKnownExtensions(static_cast<unsigned>(v18.size()));
  auto i18 = 0u;
  for (const auto &e18 : v18) {
    sv18.set(i18, es.EntityId(e18));
    ++i18;
  }
  auto v19 = e.ProtocolTokens();
  auto sv19 = b.initProtocolTokens(static_cast<unsigned>(v19.size()));
  auto i19 = 0u;
  for (const auto &e19 : v19) {
    sv19.set(i19, es.EntityId(e19));
    ++i19;
  }
  auto v20 = e.Protocols();
  auto sv20 = b.initProtocols(static_cast<unsigned>(v20.size()));
  auto i20 = 0u;
  for (const auto &e20 : v20) {
    sv20.set(i20, es.EntityId(e20));
    ++i20;
  }
  auto v21 = e.VisibleCategories();
  auto sv21 = b.initVisibleCategories(static_cast<unsigned>(v21.size()));
  auto i21 = 0u;
  for (const auto &e21 : v21) {
    sv21.set(i21, es.EntityId(e21));
    ++i21;
  }
  auto v22 = e.VisibleExtensions();
  auto sv22 = b.initVisibleExtensions(static_cast<unsigned>(v22.size()));
  auto i22 = 0u;
  for (const auto &e22 : v22) {
    sv22.set(i22, es.EntityId(e22));
    ++i22;
  }
}

void SerializeObjCImplDecl(EntitySerializer &es, mx::ast::ObjCImplDecl::Builder b, const pasta::ObjCImplDecl &e) {
  SerializeObjCContainerDecl(es, b.initObjCContainerDecl(), e);
  b.setClassInterface(es.EntityId(e.ClassInterface()));
  auto v2 = e.PropertyImplementations();
  auto sv2 = b.initPropertyImplementations(static_cast<unsigned>(v2.size()));
  auto i2 = 0u;
  for (const auto &e2 : v2) {
    sv2.set(i2, es.EntityId(e2));
    ++i2;
  }
}

void SerializeObjCCategoryImplDecl(EntitySerializer &es, mx::ast::ObjCCategoryImplDecl::Builder b, const pasta::ObjCCategoryImplDecl &e) {
  SerializeObjCImplDecl(es, b.initObjCImplDecl(), e);
  b.setCategoryDeclaration(es.EntityId(e.CategoryDeclaration()));
  b.setCategoryNameToken(es.EntityId(e.CategoryNameToken()));
}

void SerializeObjCImplementationDecl(EntitySerializer &es, mx::ast::ObjCImplementationDecl::Builder b, const pasta::ObjCImplementationDecl &e) {
  SerializeObjCImplDecl(es, b.initObjCImplDecl(), e);
  b.setInstanceVariableLBraceToken(es.EntityId(e.InstanceVariableLBraceToken()));
  b.setInstanceVariableRBraceToken(es.EntityId(e.InstanceVariableRBraceToken()));
  auto v3 = e.ObjCRuntimeNameAsString();
  std::string s3(v3.data(), v3.size());
  b.setObjCRuntimeNameAsString(s3);
  b.setSuperClass(es.EntityId(e.SuperClass()));
  b.setSuperClassToken(es.EntityId(e.SuperClassToken()));
  b.setHasDestructors(e.HasDestructors());
  b.setHasNonZeroConstructors(e.HasNonZeroConstructors());
  auto v8 = e.InstanceVariables();
  auto sv8 = b.initInstanceVariables(static_cast<unsigned>(v8.size()));
  auto i8 = 0u;
  for (const auto &e8 : v8) {
    sv8.set(i8, es.EntityId(e8));
    ++i8;
  }
}

void SerializeObjCCompatibleAliasDecl(EntitySerializer &es, mx::ast::ObjCCompatibleAliasDecl::Builder b, const pasta::ObjCCompatibleAliasDecl &e) {
  SerializeNamedDecl(es, b.initNamedDecl(), e);
  b.setClassInterface(es.EntityId(e.ClassInterface()));
}

void SerializeNamespaceDecl(EntitySerializer &es, mx::ast::NamespaceDecl::Builder b, const pasta::NamespaceDecl &e) {
  SerializeNamedDecl(es, b.initNamedDecl(), e);
  b.setAnonymousNamespace(es.EntityId(e.AnonymousNamespace()));
  b.setOriginalNamespace(es.EntityId(e.OriginalNamespace()));
  b.setRBraceToken(es.EntityId(e.RBraceToken()));
  b.setIsAnonymousNamespace(e.IsAnonymousNamespace());
  b.setIsInline(e.IsInline());
  b.setIsOriginalNamespace(e.IsOriginalNamespace());
  pasta::DeclContext dc7(e);
  auto v7 = dc7.AlreadyLoadedDeclarations();
  auto sv7 = b.initDeclarationsInContext(static_cast<unsigned>(v7.size()));
  auto i7 = 0u;
  for (const pasta::Decl &e7 : v7) {
    sv7.set(i7, es.EntityId(e7));
    ++i7;
  }
}

void SerializeNamespaceAliasDecl(EntitySerializer &es, mx::ast::NamespaceAliasDecl::Builder b, const pasta::NamespaceAliasDecl &e) {
  SerializeNamedDecl(es, b.initNamedDecl(), e);
  b.setAliasToken(es.EntityId(e.AliasToken()));
  b.setAliasedNamespace(es.EntityId(e.AliasedNamespace()));
  b.setNamespace(es.EntityId(e.Namespace()));
  b.setNamespaceToken(es.EntityId(e.NamespaceToken()));
  b.setTargetNameToken(es.EntityId(e.TargetNameToken()));
}

void SerializeLinkageSpecDecl(EntitySerializer &es, mx::ast::LinkageSpecDecl::Builder b, const pasta::LinkageSpecDecl &e) {
  SerializeDecl(es, b.initDecl(), e);
  b.setExternToken(es.EntityId(e.ExternToken()));
  b.setLanguage(static_cast<mx::ast::LinkageSpecDeclLanguageIDs>(mx::FromPasta(e.Language())));
  b.setRBraceToken(es.EntityId(e.RBraceToken()));
  b.setHasBraces(e.HasBraces());
  pasta::DeclContext dc5(e);
  auto v5 = dc5.AlreadyLoadedDeclarations();
  auto sv5 = b.initDeclarationsInContext(static_cast<unsigned>(v5.size()));
  auto i5 = 0u;
  for (const pasta::Decl &e5 : v5) {
    sv5.set(i5, es.EntityId(e5));
    ++i5;
  }
}

void SerializeLifetimeExtendedTemporaryDecl(EntitySerializer &es, mx::ast::LifetimeExtendedTemporaryDecl::Builder b, const pasta::LifetimeExtendedTemporaryDecl &e) {
  SerializeDecl(es, b.initDecl(), e);
  b.setExtendingDeclaration(es.EntityId(e.ExtendingDeclaration()));
  b.setStorageDuration(static_cast<mx::ast::StorageDuration>(mx::FromPasta(e.StorageDuration())));
}

void SerializeImportDecl(EntitySerializer &es, mx::ast::ImportDecl::Builder b, const pasta::ImportDecl &e) {
  SerializeDecl(es, b.initDecl(), e);
  auto v1 = e.IdentifierTokens();
  auto sv1 = b.initIdentifierTokens(static_cast<unsigned>(v1.size()));
  auto i1 = 0u;
  for (const auto &e1 : v1) {
    sv1.set(i1, es.EntityId(e1));
    ++i1;
  }
}

void SerializeFriendTemplateDecl(EntitySerializer &es, mx::ast::FriendTemplateDecl::Builder b, const pasta::FriendTemplateDecl &e) {
  SerializeDecl(es, b.initDecl(), e);
  b.setFriendDeclaration(es.EntityId(e.FriendDeclaration()));
  b.setFriendToken(es.EntityId(e.FriendToken()));
  auto v3 = e.TemplateParameterLists();
  auto sv3 = b.initTemplateParameterLists(static_cast<unsigned>(v3.size()));
  auto i3 = 0u;
  for (const auto &e3 : v3) {
    SerializeTemplateParameterList(es, sv3[i3], e3);
    ++i3;
  }
}

void SerializeFriendDecl(EntitySerializer &es, mx::ast::FriendDecl::Builder b, const pasta::FriendDecl &e) {
  SerializeDecl(es, b.initDecl(), e);
  b.setFriendDeclaration(es.EntityId(e.FriendDeclaration()));
  b.setFriendToken(es.EntityId(e.FriendToken()));
  b.setIsUnsupportedFriend(e.IsUnsupportedFriend());
  auto v4 = e.FriendTypeTemplateParameterLists();
  auto sv4 = b.initFriendTypeTemplateParameterLists(static_cast<unsigned>(v4.size()));
  auto i4 = 0u;
  for (const auto &e4 : v4) {
    SerializeTemplateParameterList(es, sv4[i4], e4);
    ++i4;
  }
}

void SerializeFileScopeAsmDecl(EntitySerializer &es, mx::ast::FileScopeAsmDecl::Builder b, const pasta::FileScopeAsmDecl &e) {
  SerializeDecl(es, b.initDecl(), e);
  b.setAssemblyToken(es.EntityId(e.AssemblyToken()));
  b.setAssemblyString(es.EntityId(e.AssemblyString()));
  b.setRParenToken(es.EntityId(e.RParenToken()));
}

void SerializeExternCContextDecl(EntitySerializer &es, mx::ast::ExternCContextDecl::Builder b, const pasta::ExternCContextDecl &e) {
  SerializeDecl(es, b.initDecl(), e);
  pasta::DeclContext dc1(e);
  auto v1 = dc1.AlreadyLoadedDeclarations();
  auto sv1 = b.initDeclarationsInContext(static_cast<unsigned>(v1.size()));
  auto i1 = 0u;
  for (const pasta::Decl &e1 : v1) {
    sv1.set(i1, es.EntityId(e1));
    ++i1;
  }
}

void SerializeExportDecl(EntitySerializer &es, mx::ast::ExportDecl::Builder b, const pasta::ExportDecl &e) {
  SerializeDecl(es, b.initDecl(), e);
  b.setExportToken(es.EntityId(e.ExportToken()));
  b.setRBraceToken(es.EntityId(e.RBraceToken()));
  b.setHasBraces(e.HasBraces());
  pasta::DeclContext dc4(e);
  auto v4 = dc4.AlreadyLoadedDeclarations();
  auto sv4 = b.initDeclarationsInContext(static_cast<unsigned>(v4.size()));
  auto i4 = 0u;
  for (const pasta::Decl &e4 : v4) {
    sv4.set(i4, es.EntityId(e4));
    ++i4;
  }
}

void SerializeEmptyDecl(EntitySerializer &es, mx::ast::EmptyDecl::Builder b, const pasta::EmptyDecl &e) {
  SerializeDecl(es, b.initDecl(), e);
}

}  // namespace indexer
