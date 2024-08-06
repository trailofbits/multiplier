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
   _builtin(DenseStringElementsAttr, AttributeKind::BUILTIN_DENSE_STRING_ELEMENTS, mlir::DenseStringElementsAttr) \
   _builtin(DenseResourceElementsAttr, AttributeKind::BUILTIN_DENSE_RESOURCE_ELEMENTS, mlir::DenseResourceElementsAttr) \
   _builtin(DictionaryAttr, AttributeKind::BUILTIN_DICTIONARY, mlir::DictionaryAttr) \
   _builtin(FloatAttr, AttributeKind::BUILTIN_FLOAT, mlir::FloatAttr) \
   _builtin(IntegerAttr, AttributeKind::BUILTIN_INTEGER, mlir::IntegerAttr) \
   _builtin(IntegerSetAttr, AttributeKind::BUILTIN_INTEGER_SET, mlir::IntegerSetAttr) \
   _builtin(OpaqueAttr, AttributeKind::BUILTIN_OPAQUE, mlir::OpaqueAttr) \
   _builtin(SparseElementsAttr, AttributeKind::BUILTIN_SPARSE_ELEMENTS, mlir::SparseElementsAttr) \
   _builtin(StridedLayoutAttr, AttributeKind::BUILTIN_STRIDED_LAYOUT, mlir::StridedLayoutAttr) \
   _builtin(StringAttr, AttributeKind::BUILTIN_STRING, mlir::StringAttr) \
   _builtin(SymbolRefAttr, AttributeKind::BUILTIN_SYMBOL_REF, mlir::SymbolRefAttr) \
   _builtin(TypeAttr, AttributeKind::BUILTIN_TYPE, mlir::TypeAttr) \
   _builtin(UnitAttr, AttributeKind::BUILTIN_UNIT, mlir::UnitAttr) \
   _builtin(BoolAttr, AttributeKind::BUILTIN_BOOL, mlir::BoolAttr) \
   _builtin(FlatSymbolRefAttr, AttributeKind::BUILTIN_FLAT_SYMBOL_REF, mlir::FlatSymbolRefAttr) \
   _builtin(DenseIntElementsAttr, AttributeKind::BUILTIN_DENSE_INT_ELEMENTS, mlir::DenseIntElementsAttr) \
   _llvm(CConvAttr, AttributeKind::LLVM_C_CONV, mlir::LLVM::CConvAttr) \
   _llvm(ComdatAttr, AttributeKind::LLVM_COMDAT, mlir::LLVM::ComdatAttr) \
   _llvm(LinkageAttr, AttributeKind::LLVM_LINKAGE, mlir::LLVM::LinkageAttr) \
   _llvm(FramePointerKindAttr, AttributeKind::LLVM_FRAME_POINTER_KIND, mlir::LLVM::FramePointerKindAttr) \
   _llvm(LoopVectorizeAttr, AttributeKind::LLVM_LOOP_VECTORIZE, mlir::LLVM::LoopVectorizeAttr) \
   _llvm(LoopInterleaveAttr, AttributeKind::LLVM_LOOP_INTERLEAVE, mlir::LLVM::LoopInterleaveAttr) \
   _llvm(LoopUnrollAttr, AttributeKind::LLVM_LOOP_UNROLL, mlir::LLVM::LoopUnrollAttr) \
   _llvm(LoopUnrollAndJamAttr, AttributeKind::LLVM_LOOP_UNROLL_AND_JAM, mlir::LLVM::LoopUnrollAndJamAttr) \
   _llvm(LoopLICMAttr, AttributeKind::LLVM_LOOP_LICM, mlir::LLVM::LoopLICMAttr) \
   _llvm(LoopDistributeAttr, AttributeKind::LLVM_LOOP_DISTRIBUTE, mlir::LLVM::LoopDistributeAttr) \
   _llvm(LoopPipelineAttr, AttributeKind::LLVM_LOOP_PIPELINE, mlir::LLVM::LoopPipelineAttr) \
   _llvm(LoopPeeledAttr, AttributeKind::LLVM_LOOP_PEELED, mlir::LLVM::LoopPeeledAttr) \
   _llvm(LoopUnswitchAttr, AttributeKind::LLVM_LOOP_UNSWITCH, mlir::LLVM::LoopUnswitchAttr) \
   _llvm(LoopAnnotationAttr, AttributeKind::LLVM_LOOP_ANNOTATION, mlir::LLVM::LoopAnnotationAttr) \
   _llvm(DIExpressionElemAttr, AttributeKind::LLVM_DI_EXPRESSION_ELEM, mlir::LLVM::DIExpressionElemAttr) \
   _llvm(DIExpressionAttr, AttributeKind::LLVM_DI_EXPRESSION, mlir::LLVM::DIExpressionAttr) \
   _llvm(DINullTypeAttr, AttributeKind::LLVM_DI_NULL_TYPE, mlir::LLVM::DINullTypeAttr) \
   _llvm(DIBasicTypeAttr, AttributeKind::LLVM_DI_BASIC_TYPE, mlir::LLVM::DIBasicTypeAttr) \
   _llvm(DICompileUnitAttr, AttributeKind::LLVM_DI_COMPILE_UNIT, mlir::LLVM::DICompileUnitAttr) \
   _llvm(DICompositeTypeAttr, AttributeKind::LLVM_DI_COMPOSITE_TYPE, mlir::LLVM::DICompositeTypeAttr) \
   _llvm(DIDerivedTypeAttr, AttributeKind::LLVM_DI_DERIVED_TYPE, mlir::LLVM::DIDerivedTypeAttr) \
   _llvm(DIFileAttr, AttributeKind::LLVM_DI_FILE, mlir::LLVM::DIFileAttr) \
   _llvm(DIGlobalVariableExpressionAttr, AttributeKind::LLVM_DI_GLOBAL_VARIABLE_EXPRESSION, mlir::LLVM::DIGlobalVariableExpressionAttr) \
   _llvm(DIGlobalVariableAttr, AttributeKind::LLVM_DI_GLOBAL_VARIABLE, mlir::LLVM::DIGlobalVariableAttr) \
   _llvm(DILexicalBlockAttr, AttributeKind::LLVM_DI_LEXICAL_BLOCK, mlir::LLVM::DILexicalBlockAttr) \
   _llvm(DILexicalBlockFileAttr, AttributeKind::LLVM_DI_LEXICAL_BLOCK_FILE, mlir::LLVM::DILexicalBlockFileAttr) \
   _llvm(DILocalVariableAttr, AttributeKind::LLVM_DI_LOCAL_VARIABLE, mlir::LLVM::DILocalVariableAttr) \
   _llvm(DISubprogramAttr, AttributeKind::LLVM_DI_SUBPROGRAM, mlir::LLVM::DISubprogramAttr) \
   _llvm(DIModuleAttr, AttributeKind::LLVM_DI_MODULE, mlir::LLVM::DIModuleAttr) \
   _llvm(DINamespaceAttr, AttributeKind::LLVM_DI_NAMESPACE, mlir::LLVM::DINamespaceAttr) \
   _llvm(DISubrangeAttr, AttributeKind::LLVM_DI_SUBRANGE, mlir::LLVM::DISubrangeAttr) \
   _llvm(DISubroutineTypeAttr, AttributeKind::LLVM_DI_SUBROUTINE_TYPE, mlir::LLVM::DISubroutineTypeAttr) \
   _llvm(DILabelAttr, AttributeKind::LLVM_DI_LABEL, mlir::LLVM::DILabelAttr) \
   _llvm(MemoryEffectsAttr, AttributeKind::LLVM_MEMORY_EFFECTS, mlir::LLVM::MemoryEffectsAttr) \
   _llvm(AliasScopeDomainAttr, AttributeKind::LLVM_ALIAS_SCOPE_DOMAIN, mlir::LLVM::AliasScopeDomainAttr) \
   _llvm(AliasScopeAttr, AttributeKind::LLVM_ALIAS_SCOPE, mlir::LLVM::AliasScopeAttr) \
   _llvm(AccessGroupAttr, AttributeKind::LLVM_ACCESS_GROUP, mlir::LLVM::AccessGroupAttr) \
   _llvm(TBAARootAttr, AttributeKind::LLVM_TBAA_ROOT, mlir::LLVM::TBAARootAttr) \
   _llvm(TBAAMemberAttr, AttributeKind::LLVM_TBAA_MEMBER, mlir::LLVM::TBAAMemberAttr) \
   _llvm(TBAATypeDescriptorAttr, AttributeKind::LLVM_TBAA_TYPE_DESCRIPTOR, mlir::LLVM::TBAATypeDescriptorAttr) \
   _llvm(TBAATagAttr, AttributeKind::LLVM_TBAA_TAG, mlir::LLVM::TBAATagAttr) \
   _llvm(VScaleRangeAttr, AttributeKind::LLVM_V_SCALE_RANGE, mlir::LLVM::VScaleRangeAttr) \
   _llvm(TargetFeaturesAttr, AttributeKind::LLVM_TARGET_FEATURES, mlir::LLVM::TargetFeaturesAttr) \
   _llvm(IntegerOverflowFlagsAttr, AttributeKind::LLVM_INTEGER_OVERFLOW_FLAGS, mlir::LLVM::IntegerOverflowFlagsAttr) \
   _llvm(FastmathFlagsAttr, AttributeKind::LLVM_FASTMATH_FLAGS, mlir::LLVM::FastmathFlagsAttr) \
   _hl(AnnotationAttr, AttributeKind::HL_ANNOTATION, vast::hl::AnnotationAttr) \
   _hl(FormatAttr, AttributeKind::HL_FORMAT, vast::hl::FormatAttr) \
   _hl(SectionAttr, AttributeKind::HL_SECTION, vast::hl::SectionAttr) \
   _hl(AliasAttr, AttributeKind::HL_ALIAS, vast::hl::AliasAttr) \
   _hl(AlignedAttr, AttributeKind::HL_ALIGNED, vast::hl::AlignedAttr) \
   _hl(AlwaysInlineAttr, AttributeKind::HL_ALWAYS_INLINE, vast::hl::AlwaysInlineAttr) \
   _hl(NoInlineAttr, AttributeKind::HL_NO_INLINE, vast::hl::NoInlineAttr) \
   _hl(ConstAttr, AttributeKind::HL_CONST, vast::hl::ConstAttr) \
   _hl(LoaderUninitializedAttr, AttributeKind::HL_LOADER_UNINITIALIZED, vast::hl::LoaderUninitializedAttr) \
   _hl(NoInstrumentFunctionAttr, AttributeKind::HL_NO_INSTRUMENT_FUNCTION, vast::hl::NoInstrumentFunctionAttr) \
   _hl(PackedAttr, AttributeKind::HL_PACKED, vast::hl::PackedAttr) \
   _hl(PureAttr, AttributeKind::HL_PURE, vast::hl::PureAttr) \
   _hl(WarnUnusedResultAttr, AttributeKind::HL_WARN_UNUSED_RESULT, vast::hl::WarnUnusedResultAttr) \
   _hl(RestrictAttr, AttributeKind::HL_RESTRICT, vast::hl::RestrictAttr) \
   _hl(NoThrowAttr, AttributeKind::HL_NO_THROW, vast::hl::NoThrowAttr) \
   _hl(NonNullAttr, AttributeKind::HL_NON_NULL, vast::hl::NonNullAttr) \
   _hl(LeafAttr, AttributeKind::HL_LEAF, vast::hl::LeafAttr) \
   _hl(ColdAttr, AttributeKind::HL_COLD, vast::hl::ColdAttr) \
   _hl(TransparentUnionAttr, AttributeKind::HL_TRANSPARENT_UNION, vast::hl::TransparentUnionAttr) \
   _hl(ReturnsTwiceAttr, AttributeKind::HL_RETURNS_TWICE, vast::hl::ReturnsTwiceAttr) \
   _hl(MayAliasAttr, AttributeKind::HL_MAY_ALIAS, vast::hl::MayAliasAttr) \
   _hl(UnusedAttr, AttributeKind::HL_UNUSED, vast::hl::UnusedAttr) \
   _hl(UsedAttr, AttributeKind::HL_USED, vast::hl::UsedAttr) \
   _hl(GNUInlineAttr, AttributeKind::HL_GNU_INLINE, vast::hl::GNUInlineAttr) \
   _hl(NoCfCheckAttr, AttributeKind::HL_NO_CF_CHECK, vast::hl::NoCfCheckAttr) \
   _hl(AvailableOnlyInDefaultEvalMethodAttr, AttributeKind::HL_AVAILABLE_ONLY_IN_DEFAULT_EVAL_METHOD, vast::hl::AvailableOnlyInDefaultEvalMethodAttr) \
   _hl(AvailabilityAttrAttr, AttributeKind::HL_AVAILABILITY_ATTR, vast::hl::AvailabilityAttrAttr) \
   _hl(AsmLabelAttr, AttributeKind::HL_ASM_LABEL, vast::hl::AsmLabelAttr) \
   _hl(ModeAttr, AttributeKind::HL_MODE, vast::hl::ModeAttr) \
   _hl(BuiltinAttr, AttributeKind::HL_BUILTIN, vast::hl::BuiltinAttr) \
   _hl(AllocAlignAttr, AttributeKind::HL_ALLOC_ALIGN, vast::hl::AllocAlignAttr) \
   _hl(AllocSizeAttr, AttributeKind::HL_ALLOC_SIZE, vast::hl::AllocSizeAttr) \
   _hl(DeprecatedAttr, AttributeKind::HL_DEPRECATED, vast::hl::DeprecatedAttr) \
   _hl(MaxFieldAlignmentAttr, AttributeKind::HL_MAX_FIELD_ALIGNMENT, vast::hl::MaxFieldAlignmentAttr) \
   _hl(CVQualifiersAttr, AttributeKind::HL_CV_QUALIFIERS, vast::hl::CVQualifiersAttr) \
   _hl(UCVQualifiersAttr, AttributeKind::HL_UCV_QUALIFIERS, vast::hl::UCVQualifiersAttr) \
   _hl(CVRQualifiersAttr, AttributeKind::HL_CVR_QUALIFIERS, vast::hl::CVRQualifiersAttr) \
   _hl(OffsetOfNodeAttr, AttributeKind::HL_OFFSET_OF_NODE, vast::hl::OffsetOfNodeAttr) \
   _core(BooleanAttr, AttributeKind::CORE_BOOLEAN, vast::core::BooleanAttr) \
   _core(IntegerAttr, AttributeKind::CORE_INTEGER, vast::core::IntegerAttr) \
   _core(FloatAttr, AttributeKind::CORE_FLOAT, vast::core::FloatAttr) \
   _core(VoidAttr, AttributeKind::CORE_VOID, vast::core::VoidAttr) \
   _core(SourceLanguageAttr, AttributeKind::CORE_SOURCE_LANGUAGE, vast::core::SourceLanguageAttr) \
   _core(GlobalLinkageKindAttr, AttributeKind::CORE_GLOBAL_LINKAGE_KIND, vast::core::GlobalLinkageKindAttr) \
   _meta(IdentifierAttr, AttributeKind::META_IDENTIFIER, vast::meta::IdentifierAttr)

#define MX_IR_NUM_MLIR_ATTRIBUTES 112

