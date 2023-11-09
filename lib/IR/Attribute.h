// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#define MX_IR_FOR_EACH_MLIR_ATTRIBUTE(_builtin, _llvm, _scf, _memref, _ll, _hl, _core, _meta, _unsup) \
   _llvm(CConvAttr, AttributeKind::CCONVATTR, mlir::LLVM::CConvAttr) \
   _llvm(ComdatAttr, AttributeKind::COMDATATTR, mlir::LLVM::ComdatAttr) \
   _llvm(AccessGroupAttr, AttributeKind::ACCESSGROUPATTR, mlir::LLVM::AccessGroupAttr) \
   _llvm(AliasScopeAttr, AttributeKind::ALIASSCOPEATTR, mlir::LLVM::AliasScopeAttr) \
   _llvm(AliasScopeDomainAttr, AttributeKind::ALIASSCOPEDOMAINATTR, mlir::LLVM::AliasScopeDomainAttr) \
   _llvm(DIBasicTypeAttr, AttributeKind::DIBASICTYPEATTR, mlir::LLVM::DIBasicTypeAttr) \
   _llvm(DICompileUnitAttr, AttributeKind::DICOMPILEUNITATTR, mlir::LLVM::DICompileUnitAttr) \
   _llvm(DICompositeTypeAttr, AttributeKind::DICOMPOSITETYPEATTR, mlir::LLVM::DICompositeTypeAttr) \
   _llvm(DIDerivedTypeAttr, AttributeKind::DIDERIVEDTYPEATTR, mlir::LLVM::DIDerivedTypeAttr) \
   _llvm(DIFileAttr, AttributeKind::DIFILEATTR, mlir::LLVM::DIFileAttr) \
   _llvm(DILabelAttr, AttributeKind::DILABELATTR, mlir::LLVM::DILabelAttr) \
   _llvm(DILexicalBlockAttr, AttributeKind::DILEXICALBLOCKATTR, mlir::LLVM::DILexicalBlockAttr) \
   _llvm(DILexicalBlockFileAttr, AttributeKind::DILEXICALBLOCKFILEATTR, mlir::LLVM::DILexicalBlockFileAttr) \
   _llvm(DILocalVariableAttr, AttributeKind::DILOCALVARIABLEATTR, mlir::LLVM::DILocalVariableAttr) \
   _llvm(DINamespaceAttr, AttributeKind::DINAMESPACEATTR, mlir::LLVM::DINamespaceAttr) \
   _llvm(DINullTypeAttr, AttributeKind::DINULLTYPEATTR, mlir::LLVM::DINullTypeAttr) \
   _llvm(DISubprogramAttr, AttributeKind::DISUBPROGRAMATTR, mlir::LLVM::DISubprogramAttr) \
   _llvm(DISubrangeAttr, AttributeKind::DISUBRANGEATTR, mlir::LLVM::DISubrangeAttr) \
   _llvm(DISubroutineTypeAttr, AttributeKind::DISUBROUTINETYPEATTR, mlir::LLVM::DISubroutineTypeAttr) \
   _llvm(FastmathFlagsAttr, AttributeKind::FASTMATHFLAGSATTR, mlir::LLVM::FastmathFlagsAttr) \
   _llvm(MemoryEffectsAttr, AttributeKind::MEMORYEFFECTSATTR, mlir::LLVM::MemoryEffectsAttr) \
   _llvm(TBAAMemberAttr, AttributeKind::TBAAMEMBERATTR, mlir::LLVM::TBAAMemberAttr) \
   _llvm(TBAARootAttr, AttributeKind::TBAAROOTATTR, mlir::LLVM::TBAARootAttr) \
   _llvm(TBAATagAttr, AttributeKind::TBAATAGATTR, mlir::LLVM::TBAATagAttr) \
   _llvm(TBAATypeDescriptorAttr, AttributeKind::TBAATYPEDESCRIPTORATTR, mlir::LLVM::TBAATypeDescriptorAttr) \
   _llvm(LinkageAttr, AttributeKind::LINKAGEATTR, mlir::LLVM::LinkageAttr) \
   _llvm(LoopAnnotationAttr, AttributeKind::LOOPANNOTATIONATTR, mlir::LLVM::LoopAnnotationAttr) \
   _llvm(LoopDistributeAttr, AttributeKind::LOOPDISTRIBUTEATTR, mlir::LLVM::LoopDistributeAttr) \
   _llvm(LoopInterleaveAttr, AttributeKind::LOOPINTERLEAVEATTR, mlir::LLVM::LoopInterleaveAttr) \
   _llvm(LoopLICMAttr, AttributeKind::LOOPLICMATTR, mlir::LLVM::LoopLICMAttr) \
   _llvm(LoopPeeledAttr, AttributeKind::LOOPPEELEDATTR, mlir::LLVM::LoopPeeledAttr) \
   _llvm(LoopPipelineAttr, AttributeKind::LOOPPIPELINEATTR, mlir::LLVM::LoopPipelineAttr) \
   _llvm(LoopUnrollAndJamAttr, AttributeKind::LOOPUNROLLANDJAMATTR, mlir::LLVM::LoopUnrollAndJamAttr) \
   _llvm(LoopUnrollAttr, AttributeKind::LOOPUNROLLATTR, mlir::LLVM::LoopUnrollAttr) \
   _llvm(LoopUnswitchAttr, AttributeKind::LOOPUNSWITCHATTR, mlir::LLVM::LoopUnswitchAttr) \
   _llvm(LoopVectorizeAttr, AttributeKind::LOOPVECTORIZEATTR, mlir::LLVM::LoopVectorizeAttr) \
   _hl(AllocAlignAttr, AttributeKind::ALLOCALIGNATTR, vast::hl::AllocAlignAttr) \
   _hl(AllocSizeAttr, AttributeKind::ALLOCSIZEATTR, vast::hl::AllocSizeAttr) \
   _hl(AnnotationAttr, AttributeKind::ANNOTATIONATTR, vast::hl::AnnotationAttr) \
   _hl(AsmLabelAttr, AttributeKind::ASMLABELATTR, vast::hl::AsmLabelAttr) \
   _hl(BuiltinAttr, AttributeKind::BUILTINATTR, vast::hl::BuiltinAttr) \
   _hl(CVQualifiersAttr, AttributeKind::CVQUALIFIERSATTR, vast::hl::CVQualifiersAttr) \
   _hl(CVRQualifiersAttr, AttributeKind::CVRQUALIFIERSATTR, vast::hl::CVRQualifiersAttr) \
   _hl(ConstAttr, AttributeKind::CONSTATTR, vast::hl::ConstAttr) \
   _hl(FormatAttr, AttributeKind::FORMATATTR, vast::hl::FormatAttr) \
   _hl(LoaderUninitializedAttr, AttributeKind::LOADERUNINITIALIZEDATTR, vast::hl::LoaderUninitializedAttr) \
   _hl(ModeAttr, AttributeKind::MODEATTR, vast::hl::ModeAttr) \
   _hl(NoInstrumentFunctionAttr, AttributeKind::NOINSTRUMENTFUNCTIONATTR, vast::hl::NoInstrumentFunctionAttr) \
   _hl(NoThrowAttr, AttributeKind::NOTHROWATTR, vast::hl::NoThrowAttr) \
   _hl(NonNullAttr, AttributeKind::NONNULLATTR, vast::hl::NonNullAttr) \
   _hl(PackedAttr, AttributeKind::PACKEDATTR, vast::hl::PackedAttr) \
   _hl(PureAttr, AttributeKind::PUREATTR, vast::hl::PureAttr) \
   _hl(RestrictAttr, AttributeKind::RESTRICTATTR, vast::hl::RestrictAttr) \
   _hl(SectionAttr, AttributeKind::SECTIONATTR, vast::hl::SectionAttr) \
   _hl(UCVQualifiersAttr, AttributeKind::UCVQUALIFIERSATTR, vast::hl::UCVQualifiersAttr) \
   _hl(WarnUnusedResultAttr, AttributeKind::WARNUNUSEDRESULTATTR, vast::hl::WarnUnusedResultAttr) \
   _meta(IdentifierAttr, AttributeKind::IDENTIFIERATTR, vast::meta::IdentifierAttr)

#define MX_IR_NUM_MLIR_ATTRIBUTES 57

