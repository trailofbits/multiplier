// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#define MX_IR_FOR_EACH_MLIR_ATTRIBUTE(_builtin, _llvm, _memref, _abi, _ll, _hl, _core, _meta, _unsup) \
   _builtin(TypedAttr, AttributeKind::BUILTIN_TYPED, mlir::TypedAttr) \
   _builtin(ElementsAttr, AttributeKind::BUILTIN_ELEMENTS, mlir::ElementsAttr) \
   _builtin(AffineMapAttr, AttributeKind::BUILTIN_AFFINE_MAP, mlir::AffineMapAttr) \
   _builtin(ArrayAttr, AttributeKind::BUILTIN_ARRAY, mlir::ArrayAttr) \
   _builtin(DenseArrayAttr, AttributeKind::BUILTIN_DENSE_ARRAY, mlir::DenseArrayAttr) \
   _builtin(DenseIntOrFPElementsAttr, AttributeKind::BUILTIN_DENSE_INT_OR_FP_ELEMENTS, mlir::DenseIntOrFPElementsAttr) \
   _builtin(DenseResourceElementsAttr, AttributeKind::BUILTIN_DENSE_RESOURCE_ELEMENTS, mlir::DenseResourceElementsAttr) \
   _builtin(DenseStringElementsAttr, AttributeKind::BUILTIN_DENSE_STRING_ELEMENTS, mlir::DenseStringElementsAttr) \
   _builtin(DictionaryAttr, AttributeKind::BUILTIN_DICTIONARY, mlir::DictionaryAttr) \
   _builtin(FloatAttr, AttributeKind::BUILTIN_FLOAT, mlir::FloatAttr) \
   _builtin(IntegerAttr, AttributeKind::BUILTIN_INTEGER, mlir::IntegerAttr) \
   _builtin(IntegerSetAttr, AttributeKind::BUILTIN_INTEGER_SET, mlir::IntegerSetAttr) \
   _builtin(OpaqueAttr, AttributeKind::BUILTIN_OPAQUE, mlir::OpaqueAttr) \
   _builtin(SparseElementsAttr, AttributeKind::BUILTIN_SPARSE_ELEMENTS, mlir::SparseElementsAttr) \
   _builtin(StringAttr, AttributeKind::BUILTIN_STRING, mlir::StringAttr) \
   _builtin(SymbolRefAttr, AttributeKind::BUILTIN_SYMBOL_REF, mlir::SymbolRefAttr) \
   _builtin(TypeAttr, AttributeKind::BUILTIN_TYPE, mlir::TypeAttr) \
   _builtin(UnitAttr, AttributeKind::BUILTIN_UNIT, mlir::UnitAttr) \
   _builtin(StridedLayoutAttr, AttributeKind::BUILTIN_STRIDED_LAYOUT, mlir::StridedLayoutAttr) \
   _builtin(BoolAttr, AttributeKind::BUILTIN_BOOL, mlir::BoolAttr) \
   _builtin(FlatSymbolRefAttr, AttributeKind::BUILTIN_FLAT_SYMBOL_REF, mlir::FlatSymbolRefAttr) \
   _builtin(DenseIntElementsAttr, AttributeKind::BUILTIN_DENSE_INT_ELEMENTS, mlir::DenseIntElementsAttr) \
   _llvm(CConvAttr, AttributeKind::LLVM_C_CONV, mlir::LLVM::CConvAttr) \
   _llvm(ComdatAttr, AttributeKind::LLVM_COMDAT, mlir::LLVM::ComdatAttr) \
   _llvm(AccessGroupAttr, AttributeKind::LLVM_ACCESS_GROUP, mlir::LLVM::AccessGroupAttr) \
   _llvm(AliasScopeAttr, AttributeKind::LLVM_ALIAS_SCOPE, mlir::LLVM::AliasScopeAttr) \
   _llvm(AliasScopeDomainAttr, AttributeKind::LLVM_ALIAS_SCOPE_DOMAIN, mlir::LLVM::AliasScopeDomainAttr) \
   _llvm(DIBasicTypeAttr, AttributeKind::LLVM_DI_BASIC_TYPE, mlir::LLVM::DIBasicTypeAttr) \
   _llvm(DICompileUnitAttr, AttributeKind::LLVM_DI_COMPILE_UNIT, mlir::LLVM::DICompileUnitAttr) \
   _llvm(DICompositeTypeAttr, AttributeKind::LLVM_DI_COMPOSITE_TYPE, mlir::LLVM::DICompositeTypeAttr) \
   _llvm(DIDerivedTypeAttr, AttributeKind::LLVM_DI_DERIVED_TYPE, mlir::LLVM::DIDerivedTypeAttr) \
   _llvm(DIFileAttr, AttributeKind::LLVM_DI_FILE, mlir::LLVM::DIFileAttr) \
   _llvm(DILabelAttr, AttributeKind::LLVM_DI_LABEL, mlir::LLVM::DILabelAttr) \
   _llvm(DILexicalBlockAttr, AttributeKind::LLVM_DI_LEXICAL_BLOCK, mlir::LLVM::DILexicalBlockAttr) \
   _llvm(DILexicalBlockFileAttr, AttributeKind::LLVM_DI_LEXICAL_BLOCK_FILE, mlir::LLVM::DILexicalBlockFileAttr) \
   _llvm(DILocalVariableAttr, AttributeKind::LLVM_DI_LOCAL_VARIABLE, mlir::LLVM::DILocalVariableAttr) \
   _llvm(DINamespaceAttr, AttributeKind::LLVM_DI_NAMESPACE, mlir::LLVM::DINamespaceAttr) \
   _llvm(DINullTypeAttr, AttributeKind::LLVM_DI_NULL_TYPE, mlir::LLVM::DINullTypeAttr) \
   _llvm(DISubprogramAttr, AttributeKind::LLVM_DI_SUBPROGRAM, mlir::LLVM::DISubprogramAttr) \
   _llvm(DISubrangeAttr, AttributeKind::LLVM_DI_SUBRANGE, mlir::LLVM::DISubrangeAttr) \
   _llvm(DISubroutineTypeAttr, AttributeKind::LLVM_DI_SUBROUTINE_TYPE, mlir::LLVM::DISubroutineTypeAttr) \
   _llvm(FastmathFlagsAttr, AttributeKind::LLVM_FASTMATH_FLAGS, mlir::LLVM::FastmathFlagsAttr) \
   _llvm(MemoryEffectsAttr, AttributeKind::LLVM_MEMORY_EFFECTS, mlir::LLVM::MemoryEffectsAttr) \
   _llvm(TBAAMemberAttr, AttributeKind::LLVM_TBAA_MEMBER, mlir::LLVM::TBAAMemberAttr) \
   _llvm(TBAARootAttr, AttributeKind::LLVM_TBAA_ROOT, mlir::LLVM::TBAARootAttr) \
   _llvm(TBAATagAttr, AttributeKind::LLVM_TBAA_TAG, mlir::LLVM::TBAATagAttr) \
   _llvm(TBAATypeDescriptorAttr, AttributeKind::LLVM_TBAA_TYPE_DESCRIPTOR, mlir::LLVM::TBAATypeDescriptorAttr) \
   _llvm(LinkageAttr, AttributeKind::LLVM_LINKAGE, mlir::LLVM::LinkageAttr) \
   _llvm(LoopAnnotationAttr, AttributeKind::LLVM_LOOP_ANNOTATION, mlir::LLVM::LoopAnnotationAttr) \
   _llvm(LoopDistributeAttr, AttributeKind::LLVM_LOOP_DISTRIBUTE, mlir::LLVM::LoopDistributeAttr) \
   _llvm(LoopInterleaveAttr, AttributeKind::LLVM_LOOP_INTERLEAVE, mlir::LLVM::LoopInterleaveAttr) \
   _llvm(LoopLICMAttr, AttributeKind::LLVM_LOOP_LICM, mlir::LLVM::LoopLICMAttr) \
   _llvm(LoopPeeledAttr, AttributeKind::LLVM_LOOP_PEELED, mlir::LLVM::LoopPeeledAttr) \
   _llvm(LoopPipelineAttr, AttributeKind::LLVM_LOOP_PIPELINE, mlir::LLVM::LoopPipelineAttr) \
   _llvm(LoopUnrollAndJamAttr, AttributeKind::LLVM_LOOP_UNROLL_AND_JAM, mlir::LLVM::LoopUnrollAndJamAttr) \
   _llvm(LoopUnrollAttr, AttributeKind::LLVM_LOOP_UNROLL, mlir::LLVM::LoopUnrollAttr) \
   _llvm(LoopUnswitchAttr, AttributeKind::LLVM_LOOP_UNSWITCH, mlir::LLVM::LoopUnswitchAttr) \
   _llvm(LoopVectorizeAttr, AttributeKind::LLVM_LOOP_VECTORIZE, mlir::LLVM::LoopVectorizeAttr) \
   _hl(AllocAlignAttr, AttributeKind::HL_ALLOC_ALIGN, vast::hl::AllocAlignAttr) \
   _hl(AllocSizeAttr, AttributeKind::HL_ALLOC_SIZE, vast::hl::AllocSizeAttr) \
   _hl(AnnotationAttr, AttributeKind::HL_ANNOTATION, vast::hl::AnnotationAttr) \
   _hl(AsmLabelAttr, AttributeKind::HL_ASM_LABEL, vast::hl::AsmLabelAttr) \
   _hl(BuiltinAttr, AttributeKind::HL_BUILTIN, vast::hl::BuiltinAttr) \
   _hl(CVQualifiersAttr, AttributeKind::HL_CV_QUALIFIERS, vast::hl::CVQualifiersAttr) \
   _hl(CVRQualifiersAttr, AttributeKind::HL_CVR_QUALIFIERS, vast::hl::CVRQualifiersAttr) \
   _hl(ConstAttr, AttributeKind::HL_CONST, vast::hl::ConstAttr) \
   _hl(FormatAttr, AttributeKind::HL_FORMAT, vast::hl::FormatAttr) \
   _hl(LoaderUninitializedAttr, AttributeKind::HL_LOADER_UNINITIALIZED, vast::hl::LoaderUninitializedAttr) \
   _hl(ModeAttr, AttributeKind::HL_MODE, vast::hl::ModeAttr) \
   _hl(NoInstrumentFunctionAttr, AttributeKind::HL_NO_INSTRUMENT_FUNCTION, vast::hl::NoInstrumentFunctionAttr) \
   _hl(NoThrowAttr, AttributeKind::HL_NO_THROW, vast::hl::NoThrowAttr) \
   _hl(NonNullAttr, AttributeKind::HL_NON_NULL, vast::hl::NonNullAttr) \
   _hl(PackedAttr, AttributeKind::HL_PACKED, vast::hl::PackedAttr) \
   _hl(PureAttr, AttributeKind::HL_PURE, vast::hl::PureAttr) \
   _hl(RestrictAttr, AttributeKind::HL_RESTRICT, vast::hl::RestrictAttr) \
   _hl(SectionAttr, AttributeKind::HL_SECTION, vast::hl::SectionAttr) \
   _hl(UCVQualifiersAttr, AttributeKind::HL_UCV_QUALIFIERS, vast::hl::UCVQualifiersAttr) \
   _hl(WarnUnusedResultAttr, AttributeKind::HL_WARN_UNUSED_RESULT, vast::hl::WarnUnusedResultAttr) \
   _core(BooleanAttr, AttributeKind::CORE_BOOLEAN, vast::core::BooleanAttr) \
   _core(FloatAttr, AttributeKind::CORE_FLOAT, vast::core::FloatAttr) \
   _core(IntegerAttr, AttributeKind::CORE_INTEGER, vast::core::IntegerAttr) \
   _core(SourceLanguageAttr, AttributeKind::CORE_SOURCE_LANGUAGE, vast::core::SourceLanguageAttr) \
   _core(StringLiteralAttr, AttributeKind::CORE_STRING_LITERAL, vast::core::StringLiteralAttr) \
   _core(VoidAttr, AttributeKind::CORE_VOID, vast::core::VoidAttr) \
   _meta(IdentifierAttr, AttributeKind::META_IDENTIFIER, vast::meta::IdentifierAttr)

#define MX_IR_NUM_MLIR_ATTRIBUTES 85

