// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include "AST.h"

namespace mx {
DeclKind FromPasta(pasta::DeclKind e) {
  switch (e) {
    case pasta::DeclKind::kAccessSpec: return DeclKind::ACCESS_SPEC;
    case pasta::DeclKind::kBaseUsing: return DeclKind::BASE_USING;
    case pasta::DeclKind::kBinding: return DeclKind::BINDING;
    case pasta::DeclKind::kBlock: return DeclKind::BLOCK;
    case pasta::DeclKind::kBuiltinTemplate: return DeclKind::BUILTIN_TEMPLATE;
    case pasta::DeclKind::kCXXConstructor: return DeclKind::CXX_CONSTRUCTOR;
    case pasta::DeclKind::kCXXConversion: return DeclKind::CXX_CONVERSION;
    case pasta::DeclKind::kCXXDeductionGuide: return DeclKind::CXX_DEDUCTION_GUIDE;
    case pasta::DeclKind::kCXXDestructor: return DeclKind::CXX_DESTRUCTOR;
    case pasta::DeclKind::kCXXMethod: return DeclKind::CXX_METHOD;
    case pasta::DeclKind::kCXXRecord: return DeclKind::CXX_RECORD;
    case pasta::DeclKind::kCaptured: return DeclKind::CAPTURED;
    case pasta::DeclKind::kClassScopeFunctionSpecialization: return DeclKind::CLASS_SCOPE_FUNCTION_SPECIALIZATION;
    case pasta::DeclKind::kClassTemplate: return DeclKind::CLASS_TEMPLATE;
    case pasta::DeclKind::kClassTemplatePartialSpecialization: return DeclKind::CLASS_TEMPLATE_PARTIAL_SPECIALIZATION;
    case pasta::DeclKind::kClassTemplateSpecialization: return DeclKind::CLASS_TEMPLATE_SPECIALIZATION;
    case pasta::DeclKind::kConcept: return DeclKind::CONCEPT;
    case pasta::DeclKind::kConstructorUsingShadow: return DeclKind::CONSTRUCTOR_USING_SHADOW;
    case pasta::DeclKind::kDeclarator: return DeclKind::DECLARATOR;
    case pasta::DeclKind::kDecomposition: return DeclKind::DECOMPOSITION;
    case pasta::DeclKind::kEmpty: return DeclKind::EMPTY;
    case pasta::DeclKind::kEnumConstant: return DeclKind::ENUM_CONSTANT;
    case pasta::DeclKind::kEnum: return DeclKind::ENUM;
    case pasta::DeclKind::kExport: return DeclKind::EXPORT;
    case pasta::DeclKind::kExternCContext: return DeclKind::EXTERN_C_CONTEXT;
    case pasta::DeclKind::kField: return DeclKind::FIELD;
    case pasta::DeclKind::kFileScopeAsm: return DeclKind::FILE_SCOPE_ASM;
    case pasta::DeclKind::kFriend: return DeclKind::FRIEND;
    case pasta::DeclKind::kFriendTemplate: return DeclKind::FRIEND_TEMPLATE;
    case pasta::DeclKind::kFunction: return DeclKind::FUNCTION;
    case pasta::DeclKind::kFunctionTemplate: return DeclKind::FUNCTION_TEMPLATE;
    case pasta::DeclKind::kImplicitParam: return DeclKind::IMPLICIT_PARAM;
    case pasta::DeclKind::kImport: return DeclKind::IMPORT;
    case pasta::DeclKind::kIndirectField: return DeclKind::INDIRECT_FIELD;
    case pasta::DeclKind::kLabel: return DeclKind::LABEL;
    case pasta::DeclKind::kLifetimeExtendedTemporary: return DeclKind::LIFETIME_EXTENDED_TEMPORARY;
    case pasta::DeclKind::kLinkageSpec: return DeclKind::LINKAGE_SPEC;
    case pasta::DeclKind::kMSGuid: return DeclKind::MS_GUID;
    case pasta::DeclKind::kMSProperty: return DeclKind::MS_PROPERTY;
    case pasta::DeclKind::kNamed: return DeclKind::NAMED;
    case pasta::DeclKind::kNamespaceAlias: return DeclKind::NAMESPACE_ALIAS;
    case pasta::DeclKind::kNamespace: return DeclKind::NAMESPACE;
    case pasta::DeclKind::kNonTypeTemplateParm: return DeclKind::NON_TYPE_TEMPLATE_PARM;
    case pasta::DeclKind::kOMPAllocate: return DeclKind::OMP_ALLOCATE;
    case pasta::DeclKind::kOMPCapturedExpr: return DeclKind::OMP_CAPTURED_EXPR;
    case pasta::DeclKind::kOMPDeclareMapper: return DeclKind::OMP_DECLARE_MAPPER;
    case pasta::DeclKind::kOMPDeclareReduction: return DeclKind::OMP_DECLARE_REDUCTION;
    case pasta::DeclKind::kOMPRequires: return DeclKind::OMP_REQUIRES;
    case pasta::DeclKind::kOMPThreadPrivate: return DeclKind::OMP_THREAD_PRIVATE;
    case pasta::DeclKind::kObjCAtDefsField: return DeclKind::OBJ_C_AT_DEFS_FIELD;
    case pasta::DeclKind::kObjCCategory: return DeclKind::OBJ_C_CATEGORY;
    case pasta::DeclKind::kObjCCategoryImpl: return DeclKind::OBJ_C_CATEGORY_IMPL;
    case pasta::DeclKind::kObjCCompatibleAlias: return DeclKind::OBJ_C_COMPATIBLE_ALIAS;
    case pasta::DeclKind::kObjCContainer: return DeclKind::OBJ_C_CONTAINER;
    case pasta::DeclKind::kObjCImpl: return DeclKind::OBJ_C_IMPL;
    case pasta::DeclKind::kObjCImplementation: return DeclKind::OBJ_C_IMPLEMENTATION;
    case pasta::DeclKind::kObjCInterface: return DeclKind::OBJ_C_INTERFACE;
    case pasta::DeclKind::kObjCIvar: return DeclKind::OBJ_C_IVAR;
    case pasta::DeclKind::kObjCMethod: return DeclKind::OBJ_C_METHOD;
    case pasta::DeclKind::kObjCProperty: return DeclKind::OBJ_C_PROPERTY;
    case pasta::DeclKind::kObjCPropertyImpl: return DeclKind::OBJ_C_PROPERTY_IMPL;
    case pasta::DeclKind::kObjCProtocol: return DeclKind::OBJ_C_PROTOCOL;
    case pasta::DeclKind::kObjCTypeParam: return DeclKind::OBJ_C_TYPE_PARAM;
    case pasta::DeclKind::kParmVar: return DeclKind::PARM_VAR;
    case pasta::DeclKind::kPragmaComment: return DeclKind::PRAGMA_COMMENT;
    case pasta::DeclKind::kPragmaDetectMismatch: return DeclKind::PRAGMA_DETECT_MISMATCH;
    case pasta::DeclKind::kRecord: return DeclKind::RECORD;
    case pasta::DeclKind::kRedeclarableTemplate: return DeclKind::REDECLARABLE_TEMPLATE;
    case pasta::DeclKind::kRequiresExprBody: return DeclKind::REQUIRES_EXPR_BODY;
    case pasta::DeclKind::kStaticAssert: return DeclKind::STATIC_ASSERT;
    case pasta::DeclKind::kTag: return DeclKind::TAG;
    case pasta::DeclKind::kTemplate: return DeclKind::TEMPLATE;
    case pasta::DeclKind::kTemplateParamObject: return DeclKind::TEMPLATE_PARAM_OBJECT;
    case pasta::DeclKind::kTemplateTemplateParm: return DeclKind::TEMPLATE_TEMPLATE_PARM;
    case pasta::DeclKind::kTemplateTypeParm: return DeclKind::TEMPLATE_TYPE_PARM;
    case pasta::DeclKind::kTranslationUnit: return DeclKind::TRANSLATION_UNIT;
    case pasta::DeclKind::kTypeAlias: return DeclKind::TYPE_ALIAS;
    case pasta::DeclKind::kTypeAliasTemplate: return DeclKind::TYPE_ALIAS_TEMPLATE;
    case pasta::DeclKind::kType: return DeclKind::TYPE;
    case pasta::DeclKind::kTypedef: return DeclKind::TYPEDEF;
    case pasta::DeclKind::kTypedefName: return DeclKind::TYPEDEF_NAME;
    case pasta::DeclKind::kUnresolvedUsingIfExists: return DeclKind::UNRESOLVED_USING_IF_EXISTS;
    case pasta::DeclKind::kUnresolvedUsingTypename: return DeclKind::UNRESOLVED_USING_TYPENAME;
    case pasta::DeclKind::kUnresolvedUsingValue: return DeclKind::UNRESOLVED_USING_VALUE;
    case pasta::DeclKind::kUsing: return DeclKind::USING;
    case pasta::DeclKind::kUsingDirective: return DeclKind::USING_DIRECTIVE;
    case pasta::DeclKind::kUsingEnum: return DeclKind::USING_ENUM;
    case pasta::DeclKind::kUsingPack: return DeclKind::USING_PACK;
    case pasta::DeclKind::kUsingShadow: return DeclKind::USING_SHADOW;
    case pasta::DeclKind::kValue: return DeclKind::VALUE;
    case pasta::DeclKind::kVar: return DeclKind::VAR;
    case pasta::DeclKind::kVarTemplate: return DeclKind::VAR_TEMPLATE;
    case pasta::DeclKind::kVarTemplatePartialSpecialization: return DeclKind::VAR_TEMPLATE_PARTIAL_SPECIALIZATION;
    case pasta::DeclKind::kVarTemplateSpecialization: return DeclKind::VAR_TEMPLATE_SPECIALIZATION;
  }
}

ArrayTypeArraySizeModifier FromPasta(pasta::ArrayTypeArraySizeModifier e) {
  switch (e) {
    case pasta::ArrayTypeArraySizeModifier::kNormal: return ArrayTypeArraySizeModifier::NORMAL;
    case pasta::ArrayTypeArraySizeModifier::kStatic: return ArrayTypeArraySizeModifier::STATIC;
    case pasta::ArrayTypeArraySizeModifier::kStar: return ArrayTypeArraySizeModifier::STAR;
  }
}

AtomicExprAtomicOp FromPasta(pasta::AtomicExprAtomicOp e) {
  switch (e) {
    case pasta::AtomicExprAtomicOp::kC11AtomicInitializer: return AtomicExprAtomicOp::C11_ATOMIC_INITIALIZER;
    case pasta::AtomicExprAtomicOp::kC11AtomicLoad: return AtomicExprAtomicOp::C11_ATOMIC_LOAD;
    case pasta::AtomicExprAtomicOp::kC11AtomicStore: return AtomicExprAtomicOp::C11_ATOMIC_STORE;
    case pasta::AtomicExprAtomicOp::kC11AtomicExchange: return AtomicExprAtomicOp::C11_ATOMIC_EXCHANGE;
    case pasta::AtomicExprAtomicOp::kC11AtomicCompareExchangeStrong: return AtomicExprAtomicOp::C11_ATOMIC_COMPARE_EXCHANGE_STRONG;
    case pasta::AtomicExprAtomicOp::kC11AtomicCompareExchangeWeak: return AtomicExprAtomicOp::C11_ATOMIC_COMPARE_EXCHANGE_WEAK;
    case pasta::AtomicExprAtomicOp::kC11AtomicFetchAdd: return AtomicExprAtomicOp::C11_ATOMIC_FETCH_ADD;
    case pasta::AtomicExprAtomicOp::kC11AtomicFetchSub: return AtomicExprAtomicOp::C11_ATOMIC_FETCH_SUB;
    case pasta::AtomicExprAtomicOp::kC11AtomicFetchAnd: return AtomicExprAtomicOp::C11_ATOMIC_FETCH_AND;
    case pasta::AtomicExprAtomicOp::kC11AtomicFetchOr: return AtomicExprAtomicOp::C11_ATOMIC_FETCH_OR;
    case pasta::AtomicExprAtomicOp::kC11AtomicFetchXor: return AtomicExprAtomicOp::C11_ATOMIC_FETCH_XOR;
    case pasta::AtomicExprAtomicOp::kC11AtomicFetchMax: return AtomicExprAtomicOp::C11_ATOMIC_FETCH_MAX;
    case pasta::AtomicExprAtomicOp::kC11AtomicFetchMin: return AtomicExprAtomicOp::C11_ATOMIC_FETCH_MIN;
    case pasta::AtomicExprAtomicOp::kAtomicLoad: return AtomicExprAtomicOp::ATOMIC_LOAD;
    case pasta::AtomicExprAtomicOp::kAtomicLoadN: return AtomicExprAtomicOp::ATOMIC_LOAD_N;
    case pasta::AtomicExprAtomicOp::kAtomicStore: return AtomicExprAtomicOp::ATOMIC_STORE;
    case pasta::AtomicExprAtomicOp::kAtomicStoreN: return AtomicExprAtomicOp::ATOMIC_STORE_N;
    case pasta::AtomicExprAtomicOp::kAtomicExchange: return AtomicExprAtomicOp::ATOMIC_EXCHANGE;
    case pasta::AtomicExprAtomicOp::kAtomicExchangeN: return AtomicExprAtomicOp::ATOMIC_EXCHANGE_N;
    case pasta::AtomicExprAtomicOp::kAtomicCompareExchange: return AtomicExprAtomicOp::ATOMIC_COMPARE_EXCHANGE;
    case pasta::AtomicExprAtomicOp::kAtomicCompareExchangeN: return AtomicExprAtomicOp::ATOMIC_COMPARE_EXCHANGE_N;
    case pasta::AtomicExprAtomicOp::kAtomicFetchAdd: return AtomicExprAtomicOp::ATOMIC_FETCH_ADD;
    case pasta::AtomicExprAtomicOp::kAtomicFetchSub: return AtomicExprAtomicOp::ATOMIC_FETCH_SUB;
    case pasta::AtomicExprAtomicOp::kAtomicFetchAnd: return AtomicExprAtomicOp::ATOMIC_FETCH_AND;
    case pasta::AtomicExprAtomicOp::kAtomicFetchOr: return AtomicExprAtomicOp::ATOMIC_FETCH_OR;
    case pasta::AtomicExprAtomicOp::kAtomicFetchXor: return AtomicExprAtomicOp::ATOMIC_FETCH_XOR;
    case pasta::AtomicExprAtomicOp::kAtomicFetchNand: return AtomicExprAtomicOp::ATOMIC_FETCH_NAND;
    case pasta::AtomicExprAtomicOp::kAtomicAddFetch: return AtomicExprAtomicOp::ATOMIC_ADD_FETCH;
    case pasta::AtomicExprAtomicOp::kAtomicSubFetch: return AtomicExprAtomicOp::ATOMIC_SUB_FETCH;
    case pasta::AtomicExprAtomicOp::kAtomicAndFetch: return AtomicExprAtomicOp::ATOMIC_AND_FETCH;
    case pasta::AtomicExprAtomicOp::kAtomicOrFetch: return AtomicExprAtomicOp::ATOMIC_OR_FETCH;
    case pasta::AtomicExprAtomicOp::kAtomicXorFetch: return AtomicExprAtomicOp::ATOMIC_XOR_FETCH;
    case pasta::AtomicExprAtomicOp::kAtomicMaxFetch: return AtomicExprAtomicOp::ATOMIC_MAX_FETCH;
    case pasta::AtomicExprAtomicOp::kAtomicMinFetch: return AtomicExprAtomicOp::ATOMIC_MIN_FETCH;
    case pasta::AtomicExprAtomicOp::kAtomicNandFetch: return AtomicExprAtomicOp::ATOMIC_NAND_FETCH;
    case pasta::AtomicExprAtomicOp::kOpenclAtomicInitializer: return AtomicExprAtomicOp::OPENCL_ATOMIC_INITIALIZER;
    case pasta::AtomicExprAtomicOp::kOpenclAtomicLoad: return AtomicExprAtomicOp::OPENCL_ATOMIC_LOAD;
    case pasta::AtomicExprAtomicOp::kOpenclAtomicStore: return AtomicExprAtomicOp::OPENCL_ATOMIC_STORE;
    case pasta::AtomicExprAtomicOp::kOpenclAtomicExchange: return AtomicExprAtomicOp::OPENCL_ATOMIC_EXCHANGE;
    case pasta::AtomicExprAtomicOp::kOpenclAtomicCompareExchangeStrong: return AtomicExprAtomicOp::OPENCL_ATOMIC_COMPARE_EXCHANGE_STRONG;
    case pasta::AtomicExprAtomicOp::kOpenclAtomicCompareExchangeWeak: return AtomicExprAtomicOp::OPENCL_ATOMIC_COMPARE_EXCHANGE_WEAK;
    case pasta::AtomicExprAtomicOp::kOpenclAtomicFetchAdd: return AtomicExprAtomicOp::OPENCL_ATOMIC_FETCH_ADD;
    case pasta::AtomicExprAtomicOp::kOpenclAtomicFetchSub: return AtomicExprAtomicOp::OPENCL_ATOMIC_FETCH_SUB;
    case pasta::AtomicExprAtomicOp::kOpenclAtomicFetchAnd: return AtomicExprAtomicOp::OPENCL_ATOMIC_FETCH_AND;
    case pasta::AtomicExprAtomicOp::kOpenclAtomicFetchOr: return AtomicExprAtomicOp::OPENCL_ATOMIC_FETCH_OR;
    case pasta::AtomicExprAtomicOp::kOpenclAtomicFetchXor: return AtomicExprAtomicOp::OPENCL_ATOMIC_FETCH_XOR;
    case pasta::AtomicExprAtomicOp::kOpenclAtomicFetchMin: return AtomicExprAtomicOp::OPENCL_ATOMIC_FETCH_MIN;
    case pasta::AtomicExprAtomicOp::kOpenclAtomicFetchMax: return AtomicExprAtomicOp::OPENCL_ATOMIC_FETCH_MAX;
    case pasta::AtomicExprAtomicOp::kAtomicFetchMin: return AtomicExprAtomicOp::ATOMIC_FETCH_MIN;
    case pasta::AtomicExprAtomicOp::kAtomicFetchMax: return AtomicExprAtomicOp::ATOMIC_FETCH_MAX;
  }
}

BuiltinTypeKind FromPasta(pasta::BuiltinTypeKind e) {
  switch (e) {
    case pasta::BuiltinTypeKind::kOCLImage1dRO: return BuiltinTypeKind::OCL_IMAGE1_DRO;
    case pasta::BuiltinTypeKind::kOCLImage1dArrayRO: return BuiltinTypeKind::OCL_IMAGE1_DARRAY_RO;
    case pasta::BuiltinTypeKind::kOCLImage1dBufferRO: return BuiltinTypeKind::OCL_IMAGE1_DBUFFER_RO;
    case pasta::BuiltinTypeKind::kOCLImage2dRO: return BuiltinTypeKind::OCL_IMAGE2_DRO;
    case pasta::BuiltinTypeKind::kOCLImage2dArrayRO: return BuiltinTypeKind::OCL_IMAGE2_DARRAY_RO;
    case pasta::BuiltinTypeKind::kOCLImage2dDepthRO: return BuiltinTypeKind::OCL_IMAGE2_DDEPTH_RO;
    case pasta::BuiltinTypeKind::kOCLImage2dArrayDepthRO: return BuiltinTypeKind::OCL_IMAGE2_DARRAY_DEPTH_RO;
    case pasta::BuiltinTypeKind::kOCLImage2dMSAARO: return BuiltinTypeKind::OCL_IMAGE2_DMSAARO;
    case pasta::BuiltinTypeKind::kOCLImage2dArrayMSAARO: return BuiltinTypeKind::OCL_IMAGE2_DARRAY_MSAARO;
    case pasta::BuiltinTypeKind::kOCLImage2dMSAADepthRO: return BuiltinTypeKind::OCL_IMAGE2_DMSAA_DEPTH_RO;
    case pasta::BuiltinTypeKind::kOCLImage2dArrayMSAADepthRO: return BuiltinTypeKind::OCL_IMAGE2_DARRAY_MSAA_DEPTH_RO;
    case pasta::BuiltinTypeKind::kOCLImage3dRO: return BuiltinTypeKind::OCL_IMAGE3_DRO;
    case pasta::BuiltinTypeKind::kOCLImage1dWO: return BuiltinTypeKind::OCL_IMAGE1_DWO;
    case pasta::BuiltinTypeKind::kOCLImage1dArrayWO: return BuiltinTypeKind::OCL_IMAGE1_DARRAY_WO;
    case pasta::BuiltinTypeKind::kOCLImage1dBufferWO: return BuiltinTypeKind::OCL_IMAGE1_DBUFFER_WO;
    case pasta::BuiltinTypeKind::kOCLImage2dWO: return BuiltinTypeKind::OCL_IMAGE2_DWO;
    case pasta::BuiltinTypeKind::kOCLImage2dArrayWO: return BuiltinTypeKind::OCL_IMAGE2_DARRAY_WO;
    case pasta::BuiltinTypeKind::kOCLImage2dDepthWO: return BuiltinTypeKind::OCL_IMAGE2_DDEPTH_WO;
    case pasta::BuiltinTypeKind::kOCLImage2dArrayDepthWO: return BuiltinTypeKind::OCL_IMAGE2_DARRAY_DEPTH_WO;
    case pasta::BuiltinTypeKind::kOCLImage2dMSAAWO: return BuiltinTypeKind::OCL_IMAGE2_DMSAAWO;
    case pasta::BuiltinTypeKind::kOCLImage2dArrayMSAAWO: return BuiltinTypeKind::OCL_IMAGE2_DARRAY_MSAAWO;
    case pasta::BuiltinTypeKind::kOCLImage2dMSAADepthWO: return BuiltinTypeKind::OCL_IMAGE2_DMSAA_DEPTH_WO;
    case pasta::BuiltinTypeKind::kOCLImage2dArrayMSAADepthWO: return BuiltinTypeKind::OCL_IMAGE2_DARRAY_MSAA_DEPTH_WO;
    case pasta::BuiltinTypeKind::kOCLImage3dWO: return BuiltinTypeKind::OCL_IMAGE3_DWO;
    case pasta::BuiltinTypeKind::kOCLImage1dRW: return BuiltinTypeKind::OCL_IMAGE1_DRW;
    case pasta::BuiltinTypeKind::kOCLImage1dArrayRW: return BuiltinTypeKind::OCL_IMAGE1_DARRAY_RW;
    case pasta::BuiltinTypeKind::kOCLImage1dBufferRW: return BuiltinTypeKind::OCL_IMAGE1_DBUFFER_RW;
    case pasta::BuiltinTypeKind::kOCLImage2dRW: return BuiltinTypeKind::OCL_IMAGE2_DRW;
    case pasta::BuiltinTypeKind::kOCLImage2dArrayRW: return BuiltinTypeKind::OCL_IMAGE2_DARRAY_RW;
    case pasta::BuiltinTypeKind::kOCLImage2dDepthRW: return BuiltinTypeKind::OCL_IMAGE2_DDEPTH_RW;
    case pasta::BuiltinTypeKind::kOCLImage2dArrayDepthRW: return BuiltinTypeKind::OCL_IMAGE2_DARRAY_DEPTH_RW;
    case pasta::BuiltinTypeKind::kOCLImage2dMSAARW: return BuiltinTypeKind::OCL_IMAGE2_DMSAARW;
    case pasta::BuiltinTypeKind::kOCLImage2dArrayMSAARW: return BuiltinTypeKind::OCL_IMAGE2_DARRAY_MSAARW;
    case pasta::BuiltinTypeKind::kOCLImage2dMSAADepthRW: return BuiltinTypeKind::OCL_IMAGE2_DMSAA_DEPTH_RW;
    case pasta::BuiltinTypeKind::kOCLImage2dArrayMSAADepthRW: return BuiltinTypeKind::OCL_IMAGE2_DARRAY_MSAA_DEPTH_RW;
    case pasta::BuiltinTypeKind::kOCLImage3dRW: return BuiltinTypeKind::OCL_IMAGE3_DRW;
    case pasta::BuiltinTypeKind::kOCLIntelSubgroupAVCMcePayload: return BuiltinTypeKind::OCL_INTEL_SUBGROUP_AVC_MCE_PAYLOAD;
    case pasta::BuiltinTypeKind::kOCLIntelSubgroupAVCImePayload: return BuiltinTypeKind::OCL_INTEL_SUBGROUP_AVC_IME_PAYLOAD;
    case pasta::BuiltinTypeKind::kOCLIntelSubgroupAVCRefPayload: return BuiltinTypeKind::OCL_INTEL_SUBGROUP_AVC_REF_PAYLOAD;
    case pasta::BuiltinTypeKind::kOCLIntelSubgroupAVCSicPayload: return BuiltinTypeKind::OCL_INTEL_SUBGROUP_AVC_SIC_PAYLOAD;
    case pasta::BuiltinTypeKind::kOCLIntelSubgroupAVCMceResult: return BuiltinTypeKind::OCL_INTEL_SUBGROUP_AVC_MCE_RESULT;
    case pasta::BuiltinTypeKind::kOCLIntelSubgroupAVCImeResult: return BuiltinTypeKind::OCL_INTEL_SUBGROUP_AVC_IME_RESULT;
    case pasta::BuiltinTypeKind::kOCLIntelSubgroupAVCRefResult: return BuiltinTypeKind::OCL_INTEL_SUBGROUP_AVC_REF_RESULT;
    case pasta::BuiltinTypeKind::kOCLIntelSubgroupAVCSicResult: return BuiltinTypeKind::OCL_INTEL_SUBGROUP_AVC_SIC_RESULT;
    case pasta::BuiltinTypeKind::kOCLIntelSubgroupAVCImeResultSingleReferenceStreamout: return BuiltinTypeKind::OCL_INTEL_SUBGROUP_AVC_IME_RESULT_SINGLE_REFERENCE_STREAMOUT;
    case pasta::BuiltinTypeKind::kOCLIntelSubgroupAVCImeResultDualReferenceStreamout: return BuiltinTypeKind::OCL_INTEL_SUBGROUP_AVC_IME_RESULT_DUAL_REFERENCE_STREAMOUT;
    case pasta::BuiltinTypeKind::kOCLIntelSubgroupAVCImeSingleReferenceStreamin: return BuiltinTypeKind::OCL_INTEL_SUBGROUP_AVC_IME_SINGLE_REFERENCE_STREAMIN;
    case pasta::BuiltinTypeKind::kOCLIntelSubgroupAVCImeDualReferenceStreamin: return BuiltinTypeKind::OCL_INTEL_SUBGROUP_AVC_IME_DUAL_REFERENCE_STREAMIN;
    case pasta::BuiltinTypeKind::kSveInt8: return BuiltinTypeKind::SVE_INT8;
    case pasta::BuiltinTypeKind::kSveInt16: return BuiltinTypeKind::SVE_INT16;
    case pasta::BuiltinTypeKind::kSveInt32: return BuiltinTypeKind::SVE_INT32;
    case pasta::BuiltinTypeKind::kSveInt64: return BuiltinTypeKind::SVE_INT64;
    case pasta::BuiltinTypeKind::kSveUint8: return BuiltinTypeKind::SVE_UINT8;
    case pasta::BuiltinTypeKind::kSveUint16: return BuiltinTypeKind::SVE_UINT16;
    case pasta::BuiltinTypeKind::kSveUint32: return BuiltinTypeKind::SVE_UINT32;
    case pasta::BuiltinTypeKind::kSveUint64: return BuiltinTypeKind::SVE_UINT64;
    case pasta::BuiltinTypeKind::kSveFloat16: return BuiltinTypeKind::SVE_FLOAT16;
    case pasta::BuiltinTypeKind::kSveFloat32: return BuiltinTypeKind::SVE_FLOAT32;
    case pasta::BuiltinTypeKind::kSveFloat64: return BuiltinTypeKind::SVE_FLOAT64;
    case pasta::BuiltinTypeKind::kSveBFloat16: return BuiltinTypeKind::SVE_B_FLOAT16;
    case pasta::BuiltinTypeKind::kSveInt8x2: return BuiltinTypeKind::SVE_INT8_X2;
    case pasta::BuiltinTypeKind::kSveInt16x2: return BuiltinTypeKind::SVE_INT16_X2;
    case pasta::BuiltinTypeKind::kSveInt32x2: return BuiltinTypeKind::SVE_INT32_X2;
    case pasta::BuiltinTypeKind::kSveInt64x2: return BuiltinTypeKind::SVE_INT64_X2;
    case pasta::BuiltinTypeKind::kSveUint8x2: return BuiltinTypeKind::SVE_UINT8_X2;
    case pasta::BuiltinTypeKind::kSveUint16x2: return BuiltinTypeKind::SVE_UINT16_X2;
    case pasta::BuiltinTypeKind::kSveUint32x2: return BuiltinTypeKind::SVE_UINT32_X2;
    case pasta::BuiltinTypeKind::kSveUint64x2: return BuiltinTypeKind::SVE_UINT64_X2;
    case pasta::BuiltinTypeKind::kSveFloat16x2: return BuiltinTypeKind::SVE_FLOAT16_X2;
    case pasta::BuiltinTypeKind::kSveFloat32x2: return BuiltinTypeKind::SVE_FLOAT32_X2;
    case pasta::BuiltinTypeKind::kSveFloat64x2: return BuiltinTypeKind::SVE_FLOAT64_X2;
    case pasta::BuiltinTypeKind::kSveBFloat16x2: return BuiltinTypeKind::SVE_B_FLOAT16_X2;
    case pasta::BuiltinTypeKind::kSveInt8x3: return BuiltinTypeKind::SVE_INT8_X3;
    case pasta::BuiltinTypeKind::kSveInt16x3: return BuiltinTypeKind::SVE_INT16_X3;
    case pasta::BuiltinTypeKind::kSveInt32x3: return BuiltinTypeKind::SVE_INT32_X3;
    case pasta::BuiltinTypeKind::kSveInt64x3: return BuiltinTypeKind::SVE_INT64_X3;
    case pasta::BuiltinTypeKind::kSveUint8x3: return BuiltinTypeKind::SVE_UINT8_X3;
    case pasta::BuiltinTypeKind::kSveUint16x3: return BuiltinTypeKind::SVE_UINT16_X3;
    case pasta::BuiltinTypeKind::kSveUint32x3: return BuiltinTypeKind::SVE_UINT32_X3;
    case pasta::BuiltinTypeKind::kSveUint64x3: return BuiltinTypeKind::SVE_UINT64_X3;
    case pasta::BuiltinTypeKind::kSveFloat16x3: return BuiltinTypeKind::SVE_FLOAT16_X3;
    case pasta::BuiltinTypeKind::kSveFloat32x3: return BuiltinTypeKind::SVE_FLOAT32_X3;
    case pasta::BuiltinTypeKind::kSveFloat64x3: return BuiltinTypeKind::SVE_FLOAT64_X3;
    case pasta::BuiltinTypeKind::kSveBFloat16x3: return BuiltinTypeKind::SVE_B_FLOAT16_X3;
    case pasta::BuiltinTypeKind::kSveInt8x4: return BuiltinTypeKind::SVE_INT8_X4;
    case pasta::BuiltinTypeKind::kSveInt16x4: return BuiltinTypeKind::SVE_INT16_X4;
    case pasta::BuiltinTypeKind::kSveInt32x4: return BuiltinTypeKind::SVE_INT32_X4;
    case pasta::BuiltinTypeKind::kSveInt64x4: return BuiltinTypeKind::SVE_INT64_X4;
    case pasta::BuiltinTypeKind::kSveUint8x4: return BuiltinTypeKind::SVE_UINT8_X4;
    case pasta::BuiltinTypeKind::kSveUint16x4: return BuiltinTypeKind::SVE_UINT16_X4;
    case pasta::BuiltinTypeKind::kSveUint32x4: return BuiltinTypeKind::SVE_UINT32_X4;
    case pasta::BuiltinTypeKind::kSveUint64x4: return BuiltinTypeKind::SVE_UINT64_X4;
    case pasta::BuiltinTypeKind::kSveFloat16x4: return BuiltinTypeKind::SVE_FLOAT16_X4;
    case pasta::BuiltinTypeKind::kSveFloat32x4: return BuiltinTypeKind::SVE_FLOAT32_X4;
    case pasta::BuiltinTypeKind::kSveFloat64x4: return BuiltinTypeKind::SVE_FLOAT64_X4;
    case pasta::BuiltinTypeKind::kSveBFloat16x4: return BuiltinTypeKind::SVE_B_FLOAT16_X4;
    case pasta::BuiltinTypeKind::kSveBoolean: return BuiltinTypeKind::SVE_BOOLEAN;
    case pasta::BuiltinTypeKind::kVectorQuad: return BuiltinTypeKind::VECTOR_QUAD;
    case pasta::BuiltinTypeKind::kVectorPair: return BuiltinTypeKind::VECTOR_PAIR;
    case pasta::BuiltinTypeKind::kRvvInt8mf8: return BuiltinTypeKind::RVV_INT8_MF8;
    case pasta::BuiltinTypeKind::kRvvInt8mf4: return BuiltinTypeKind::RVV_INT8_MF4;
    case pasta::BuiltinTypeKind::kRvvInt8mf2: return BuiltinTypeKind::RVV_INT8_MF2;
    case pasta::BuiltinTypeKind::kRvvInt8m1: return BuiltinTypeKind::RVV_INT8_M1;
    case pasta::BuiltinTypeKind::kRvvInt8m2: return BuiltinTypeKind::RVV_INT8_M2;
    case pasta::BuiltinTypeKind::kRvvInt8m4: return BuiltinTypeKind::RVV_INT8_M4;
    case pasta::BuiltinTypeKind::kRvvInt8m8: return BuiltinTypeKind::RVV_INT8_M8;
    case pasta::BuiltinTypeKind::kRvvUint8mf8: return BuiltinTypeKind::RVV_UINT8_MF8;
    case pasta::BuiltinTypeKind::kRvvUint8mf4: return BuiltinTypeKind::RVV_UINT8_MF4;
    case pasta::BuiltinTypeKind::kRvvUint8mf2: return BuiltinTypeKind::RVV_UINT8_MF2;
    case pasta::BuiltinTypeKind::kRvvUint8m1: return BuiltinTypeKind::RVV_UINT8_M1;
    case pasta::BuiltinTypeKind::kRvvUint8m2: return BuiltinTypeKind::RVV_UINT8_M2;
    case pasta::BuiltinTypeKind::kRvvUint8m4: return BuiltinTypeKind::RVV_UINT8_M4;
    case pasta::BuiltinTypeKind::kRvvUint8m8: return BuiltinTypeKind::RVV_UINT8_M8;
    case pasta::BuiltinTypeKind::kRvvInt16mf4: return BuiltinTypeKind::RVV_INT16_MF4;
    case pasta::BuiltinTypeKind::kRvvInt16mf2: return BuiltinTypeKind::RVV_INT16_MF2;
    case pasta::BuiltinTypeKind::kRvvInt16m1: return BuiltinTypeKind::RVV_INT16_M1;
    case pasta::BuiltinTypeKind::kRvvInt16m2: return BuiltinTypeKind::RVV_INT16_M2;
    case pasta::BuiltinTypeKind::kRvvInt16m4: return BuiltinTypeKind::RVV_INT16_M4;
    case pasta::BuiltinTypeKind::kRvvInt16m8: return BuiltinTypeKind::RVV_INT16_M8;
    case pasta::BuiltinTypeKind::kRvvUint16mf4: return BuiltinTypeKind::RVV_UINT16_MF4;
    case pasta::BuiltinTypeKind::kRvvUint16mf2: return BuiltinTypeKind::RVV_UINT16_MF2;
    case pasta::BuiltinTypeKind::kRvvUint16m1: return BuiltinTypeKind::RVV_UINT16_M1;
    case pasta::BuiltinTypeKind::kRvvUint16m2: return BuiltinTypeKind::RVV_UINT16_M2;
    case pasta::BuiltinTypeKind::kRvvUint16m4: return BuiltinTypeKind::RVV_UINT16_M4;
    case pasta::BuiltinTypeKind::kRvvUint16m8: return BuiltinTypeKind::RVV_UINT16_M8;
    case pasta::BuiltinTypeKind::kRvvInt32mf2: return BuiltinTypeKind::RVV_INT32_MF2;
    case pasta::BuiltinTypeKind::kRvvInt32m1: return BuiltinTypeKind::RVV_INT32_M1;
    case pasta::BuiltinTypeKind::kRvvInt32m2: return BuiltinTypeKind::RVV_INT32_M2;
    case pasta::BuiltinTypeKind::kRvvInt32m4: return BuiltinTypeKind::RVV_INT32_M4;
    case pasta::BuiltinTypeKind::kRvvInt32m8: return BuiltinTypeKind::RVV_INT32_M8;
    case pasta::BuiltinTypeKind::kRvvUint32mf2: return BuiltinTypeKind::RVV_UINT32_MF2;
    case pasta::BuiltinTypeKind::kRvvUint32m1: return BuiltinTypeKind::RVV_UINT32_M1;
    case pasta::BuiltinTypeKind::kRvvUint32m2: return BuiltinTypeKind::RVV_UINT32_M2;
    case pasta::BuiltinTypeKind::kRvvUint32m4: return BuiltinTypeKind::RVV_UINT32_M4;
    case pasta::BuiltinTypeKind::kRvvUint32m8: return BuiltinTypeKind::RVV_UINT32_M8;
    case pasta::BuiltinTypeKind::kRvvInt64m1: return BuiltinTypeKind::RVV_INT64_M1;
    case pasta::BuiltinTypeKind::kRvvInt64m2: return BuiltinTypeKind::RVV_INT64_M2;
    case pasta::BuiltinTypeKind::kRvvInt64m4: return BuiltinTypeKind::RVV_INT64_M4;
    case pasta::BuiltinTypeKind::kRvvInt64m8: return BuiltinTypeKind::RVV_INT64_M8;
    case pasta::BuiltinTypeKind::kRvvUint64m1: return BuiltinTypeKind::RVV_UINT64_M1;
    case pasta::BuiltinTypeKind::kRvvUint64m2: return BuiltinTypeKind::RVV_UINT64_M2;
    case pasta::BuiltinTypeKind::kRvvUint64m4: return BuiltinTypeKind::RVV_UINT64_M4;
    case pasta::BuiltinTypeKind::kRvvUint64m8: return BuiltinTypeKind::RVV_UINT64_M8;
    case pasta::BuiltinTypeKind::kRvvFloat16mf4: return BuiltinTypeKind::RVV_FLOAT16_MF4;
    case pasta::BuiltinTypeKind::kRvvFloat16mf2: return BuiltinTypeKind::RVV_FLOAT16_MF2;
    case pasta::BuiltinTypeKind::kRvvFloat16m1: return BuiltinTypeKind::RVV_FLOAT16_M1;
    case pasta::BuiltinTypeKind::kRvvFloat16m2: return BuiltinTypeKind::RVV_FLOAT16_M2;
    case pasta::BuiltinTypeKind::kRvvFloat16m4: return BuiltinTypeKind::RVV_FLOAT16_M4;
    case pasta::BuiltinTypeKind::kRvvFloat16m8: return BuiltinTypeKind::RVV_FLOAT16_M8;
    case pasta::BuiltinTypeKind::kRvvFloat32mf2: return BuiltinTypeKind::RVV_FLOAT32_MF2;
    case pasta::BuiltinTypeKind::kRvvFloat32m1: return BuiltinTypeKind::RVV_FLOAT32_M1;
    case pasta::BuiltinTypeKind::kRvvFloat32m2: return BuiltinTypeKind::RVV_FLOAT32_M2;
    case pasta::BuiltinTypeKind::kRvvFloat32m4: return BuiltinTypeKind::RVV_FLOAT32_M4;
    case pasta::BuiltinTypeKind::kRvvFloat32m8: return BuiltinTypeKind::RVV_FLOAT32_M8;
    case pasta::BuiltinTypeKind::kRvvFloat64m1: return BuiltinTypeKind::RVV_FLOAT64_M1;
    case pasta::BuiltinTypeKind::kRvvFloat64m2: return BuiltinTypeKind::RVV_FLOAT64_M2;
    case pasta::BuiltinTypeKind::kRvvFloat64m4: return BuiltinTypeKind::RVV_FLOAT64_M4;
    case pasta::BuiltinTypeKind::kRvvFloat64m8: return BuiltinTypeKind::RVV_FLOAT64_M8;
    case pasta::BuiltinTypeKind::kRvvBool1: return BuiltinTypeKind::RVV_BOOL1;
    case pasta::BuiltinTypeKind::kRvvBool2: return BuiltinTypeKind::RVV_BOOL2;
    case pasta::BuiltinTypeKind::kRvvBool4: return BuiltinTypeKind::RVV_BOOL4;
    case pasta::BuiltinTypeKind::kRvvBool8: return BuiltinTypeKind::RVV_BOOL8;
    case pasta::BuiltinTypeKind::kRvvBool16: return BuiltinTypeKind::RVV_BOOL16;
    case pasta::BuiltinTypeKind::kRvvBool32: return BuiltinTypeKind::RVV_BOOL32;
    case pasta::BuiltinTypeKind::kRvvBool64: return BuiltinTypeKind::RVV_BOOL64;
    case pasta::BuiltinTypeKind::kVoid: return BuiltinTypeKind::VOID;
    case pasta::BuiltinTypeKind::kBoolean: return BuiltinTypeKind::BOOLEAN;
    case pasta::BuiltinTypeKind::kCharacterU: return BuiltinTypeKind::CHARACTER_U;
    case pasta::BuiltinTypeKind::kUChar: return BuiltinTypeKind::U_CHAR;
    case pasta::BuiltinTypeKind::kWCharU: return BuiltinTypeKind::W_CHAR_U;
    case pasta::BuiltinTypeKind::kChar8: return BuiltinTypeKind::CHAR8;
    case pasta::BuiltinTypeKind::kChar16: return BuiltinTypeKind::CHAR16;
    case pasta::BuiltinTypeKind::kChar32: return BuiltinTypeKind::CHAR32;
    case pasta::BuiltinTypeKind::kUShort: return BuiltinTypeKind::U_SHORT;
    case pasta::BuiltinTypeKind::kUInt: return BuiltinTypeKind::U_INT;
    case pasta::BuiltinTypeKind::kULong: return BuiltinTypeKind::U_LONG;
    case pasta::BuiltinTypeKind::kULongLong: return BuiltinTypeKind::U_LONG_LONG;
    case pasta::BuiltinTypeKind::kUInt128: return BuiltinTypeKind::U_INT128;
    case pasta::BuiltinTypeKind::kCharacterS: return BuiltinTypeKind::CHARACTER_S;
    case pasta::BuiltinTypeKind::kSChar: return BuiltinTypeKind::S_CHAR;
    case pasta::BuiltinTypeKind::kWCharS: return BuiltinTypeKind::W_CHAR_S;
    case pasta::BuiltinTypeKind::kShort: return BuiltinTypeKind::SHORT;
    case pasta::BuiltinTypeKind::kInt: return BuiltinTypeKind::INT;
    case pasta::BuiltinTypeKind::kLong: return BuiltinTypeKind::LONG;
    case pasta::BuiltinTypeKind::kLongLong: return BuiltinTypeKind::LONG_LONG;
    case pasta::BuiltinTypeKind::kInt128: return BuiltinTypeKind::INT128;
    case pasta::BuiltinTypeKind::kShortAccum: return BuiltinTypeKind::SHORT_ACCUM;
    case pasta::BuiltinTypeKind::kAccum: return BuiltinTypeKind::ACCUM;
    case pasta::BuiltinTypeKind::kLongAccum: return BuiltinTypeKind::LONG_ACCUM;
    case pasta::BuiltinTypeKind::kUShortAccum: return BuiltinTypeKind::U_SHORT_ACCUM;
    case pasta::BuiltinTypeKind::kUAccum: return BuiltinTypeKind::U_ACCUM;
    case pasta::BuiltinTypeKind::kULongAccum: return BuiltinTypeKind::U_LONG_ACCUM;
    case pasta::BuiltinTypeKind::kShortFract: return BuiltinTypeKind::SHORT_FRACT;
    case pasta::BuiltinTypeKind::kFract: return BuiltinTypeKind::FRACT;
    case pasta::BuiltinTypeKind::kLongFract: return BuiltinTypeKind::LONG_FRACT;
    case pasta::BuiltinTypeKind::kUShortFract: return BuiltinTypeKind::U_SHORT_FRACT;
    case pasta::BuiltinTypeKind::kUFract: return BuiltinTypeKind::U_FRACT;
    case pasta::BuiltinTypeKind::kULongFract: return BuiltinTypeKind::U_LONG_FRACT;
    case pasta::BuiltinTypeKind::kSatShortAccum: return BuiltinTypeKind::SAT_SHORT_ACCUM;
    case pasta::BuiltinTypeKind::kSatAccum: return BuiltinTypeKind::SAT_ACCUM;
    case pasta::BuiltinTypeKind::kSatLongAccum: return BuiltinTypeKind::SAT_LONG_ACCUM;
    case pasta::BuiltinTypeKind::kSatUShortAccum: return BuiltinTypeKind::SAT_U_SHORT_ACCUM;
    case pasta::BuiltinTypeKind::kSatUAccum: return BuiltinTypeKind::SAT_U_ACCUM;
    case pasta::BuiltinTypeKind::kSatULongAccum: return BuiltinTypeKind::SAT_U_LONG_ACCUM;
    case pasta::BuiltinTypeKind::kSatShortFract: return BuiltinTypeKind::SAT_SHORT_FRACT;
    case pasta::BuiltinTypeKind::kSatFract: return BuiltinTypeKind::SAT_FRACT;
    case pasta::BuiltinTypeKind::kSatLongFract: return BuiltinTypeKind::SAT_LONG_FRACT;
    case pasta::BuiltinTypeKind::kSatUShortFract: return BuiltinTypeKind::SAT_U_SHORT_FRACT;
    case pasta::BuiltinTypeKind::kSatUFract: return BuiltinTypeKind::SAT_U_FRACT;
    case pasta::BuiltinTypeKind::kSatULongFract: return BuiltinTypeKind::SAT_U_LONG_FRACT;
    case pasta::BuiltinTypeKind::kHalf: return BuiltinTypeKind::HALF;
    case pasta::BuiltinTypeKind::kFloat: return BuiltinTypeKind::FLOAT;
    case pasta::BuiltinTypeKind::kDouble: return BuiltinTypeKind::DOUBLE;
    case pasta::BuiltinTypeKind::kLongDouble: return BuiltinTypeKind::LONG_DOUBLE;
    case pasta::BuiltinTypeKind::kFloat16: return BuiltinTypeKind::FLOAT16;
    case pasta::BuiltinTypeKind::kBFloat16: return BuiltinTypeKind::B_FLOAT16;
    case pasta::BuiltinTypeKind::kFloat128: return BuiltinTypeKind::FLOAT128;
    case pasta::BuiltinTypeKind::kNullPointer: return BuiltinTypeKind::NULL_POINTER;
    case pasta::BuiltinTypeKind::kObjCId: return BuiltinTypeKind::OBJ_C_ID;
    case pasta::BuiltinTypeKind::kObjCClass: return BuiltinTypeKind::OBJ_C_CLASS;
    case pasta::BuiltinTypeKind::kObjCSel: return BuiltinTypeKind::OBJ_C_SEL;
    case pasta::BuiltinTypeKind::kOCLSampler: return BuiltinTypeKind::OCL_SAMPLER;
    case pasta::BuiltinTypeKind::kOCLEvent: return BuiltinTypeKind::OCL_EVENT;
    case pasta::BuiltinTypeKind::kOCLClkEvent: return BuiltinTypeKind::OCL_CLK_EVENT;
    case pasta::BuiltinTypeKind::kOCLQueue: return BuiltinTypeKind::OCL_QUEUE;
    case pasta::BuiltinTypeKind::kOCLReserveID: return BuiltinTypeKind::OCL_RESERVE_ID;
    case pasta::BuiltinTypeKind::kDependent: return BuiltinTypeKind::DEPENDENT;
    case pasta::BuiltinTypeKind::kOverload: return BuiltinTypeKind::OVERLOAD;
    case pasta::BuiltinTypeKind::kBoundMember: return BuiltinTypeKind::BOUND_MEMBER;
    case pasta::BuiltinTypeKind::kPseudoObject: return BuiltinTypeKind::PSEUDO_OBJECT;
    case pasta::BuiltinTypeKind::kUnknownAny: return BuiltinTypeKind::UNKNOWN_ANY;
    case pasta::BuiltinTypeKind::kBuiltinFn: return BuiltinTypeKind::BUILTIN_FN;
    case pasta::BuiltinTypeKind::kARCUnbridgedCast: return BuiltinTypeKind::ARC_UNBRIDGED_CAST;
    case pasta::BuiltinTypeKind::kIncompleteMatrixIndex: return BuiltinTypeKind::INCOMPLETE_MATRIX_INDEX;
    case pasta::BuiltinTypeKind::kOMPArraySection: return BuiltinTypeKind::OMP_ARRAY_SECTION;
    case pasta::BuiltinTypeKind::kOMPArrayShaping: return BuiltinTypeKind::OMP_ARRAY_SHAPING;
    case pasta::BuiltinTypeKind::kOMPIterator: return BuiltinTypeKind::OMP_ITERATOR;
  }
}

CXXConstructExprConstructionKind FromPasta(pasta::CXXConstructExprConstructionKind e) {
  switch (e) {
    case pasta::CXXConstructExprConstructionKind::kComplete: return CXXConstructExprConstructionKind::COMPLETE;
    case pasta::CXXConstructExprConstructionKind::kNonVirtualBase: return CXXConstructExprConstructionKind::NON_VIRTUAL_BASE;
    case pasta::CXXConstructExprConstructionKind::kVirtualBase: return CXXConstructExprConstructionKind::VIRTUAL_BASE;
    case pasta::CXXConstructExprConstructionKind::kDelegating: return CXXConstructExprConstructionKind::DELEGATING;
  }
}

CXXNewExprInitializationStyle FromPasta(pasta::CXXNewExprInitializationStyle e) {
  switch (e) {
    case pasta::CXXNewExprInitializationStyle::kNoInitializer: return CXXNewExprInitializationStyle::NO_INITIALIZER;
    case pasta::CXXNewExprInitializationStyle::kCallInitializer: return CXXNewExprInitializationStyle::CALL_INITIALIZER;
    case pasta::CXXNewExprInitializationStyle::kListInitializer: return CXXNewExprInitializationStyle::LIST_INITIALIZER;
  }
}

CallExprADLCallKind FromPasta(pasta::CallExprADLCallKind e) {
  switch (e) {
    case pasta::CallExprADLCallKind::kNotADL: return CallExprADLCallKind::NOT_ADL;
    case pasta::CallExprADLCallKind::kUsesADL: return CallExprADLCallKind::USES_ADL;
  }
}

CapturedStmtVariableCaptureKind FromPasta(pasta::CapturedStmtVariableCaptureKind e) {
  switch (e) {
    case pasta::CapturedStmtVariableCaptureKind::kThis: return CapturedStmtVariableCaptureKind::THIS;
    case pasta::CapturedStmtVariableCaptureKind::kByReference: return CapturedStmtVariableCaptureKind::BY_REFERENCE;
    case pasta::CapturedStmtVariableCaptureKind::kByCopy: return CapturedStmtVariableCaptureKind::BY_COPY;
    case pasta::CapturedStmtVariableCaptureKind::kVLAType: return CapturedStmtVariableCaptureKind::VLA_TYPE;
  }
}

CharacterLiteralCharacterKind FromPasta(pasta::CharacterLiteralCharacterKind e) {
  switch (e) {
    case pasta::CharacterLiteralCharacterKind::kAscii: return CharacterLiteralCharacterKind::ASCII;
    case pasta::CharacterLiteralCharacterKind::kWide: return CharacterLiteralCharacterKind::WIDE;
    case pasta::CharacterLiteralCharacterKind::kUTF8: return CharacterLiteralCharacterKind::UT_F8;
    case pasta::CharacterLiteralCharacterKind::kUTF16: return CharacterLiteralCharacterKind::UT_F16;
    case pasta::CharacterLiteralCharacterKind::kUTF32: return CharacterLiteralCharacterKind::UT_F32;
  }
}

ConstantExprResultStorageKind FromPasta(pasta::ConstantExprResultStorageKind e) {
  switch (e) {
    case pasta::ConstantExprResultStorageKind::kNone: return ConstantExprResultStorageKind::NONE;
    case pasta::ConstantExprResultStorageKind::kInt64: return ConstantExprResultStorageKind::INT64;
    case pasta::ConstantExprResultStorageKind::kAPValue: return ConstantExprResultStorageKind::AP_VALUE;
  }
}

DeclFriendObjectKind FromPasta(pasta::DeclFriendObjectKind e) {
  switch (e) {
    case pasta::DeclFriendObjectKind::kNone: return DeclFriendObjectKind::NONE;
    case pasta::DeclFriendObjectKind::kDeclared: return DeclFriendObjectKind::DECLARED;
    case pasta::DeclFriendObjectKind::kUndeclared: return DeclFriendObjectKind::UNDECLARED;
  }
}

DeclIdentifierNamespace FromPasta(pasta::DeclIdentifierNamespace e) {
  switch (e) {
    case pasta::DeclIdentifierNamespace::kLabel: return DeclIdentifierNamespace::LABEL;
    case pasta::DeclIdentifierNamespace::kTag: return DeclIdentifierNamespace::TAG;
    case pasta::DeclIdentifierNamespace::kType: return DeclIdentifierNamespace::TYPE;
    case pasta::DeclIdentifierNamespace::kMember: return DeclIdentifierNamespace::MEMBER;
    case pasta::DeclIdentifierNamespace::kNamespace: return DeclIdentifierNamespace::NAMESPACE;
    case pasta::DeclIdentifierNamespace::kOrdinary: return DeclIdentifierNamespace::ORDINARY;
    case pasta::DeclIdentifierNamespace::kObjCProtocol: return DeclIdentifierNamespace::OBJ_C_PROTOCOL;
    case pasta::DeclIdentifierNamespace::kOrdinaryFriend: return DeclIdentifierNamespace::ORDINARY_FRIEND;
    case pasta::DeclIdentifierNamespace::kTagFriend: return DeclIdentifierNamespace::TAG_FRIEND;
    case pasta::DeclIdentifierNamespace::kUsing: return DeclIdentifierNamespace::USING;
    case pasta::DeclIdentifierNamespace::kNonMemberOperator: return DeclIdentifierNamespace::NON_MEMBER_OPERATOR;
    case pasta::DeclIdentifierNamespace::kLocalExtern: return DeclIdentifierNamespace::LOCAL_EXTERN;
    case pasta::DeclIdentifierNamespace::kOMPReduction: return DeclIdentifierNamespace::OMP_REDUCTION;
    case pasta::DeclIdentifierNamespace::kOMPMapper: return DeclIdentifierNamespace::OMP_MAPPER;
  }
}

DeclModuleOwnershipKind FromPasta(pasta::DeclModuleOwnershipKind e) {
  switch (e) {
    case pasta::DeclModuleOwnershipKind::kUnowned: return DeclModuleOwnershipKind::UNOWNED;
    case pasta::DeclModuleOwnershipKind::kVisible: return DeclModuleOwnershipKind::VISIBLE;
    case pasta::DeclModuleOwnershipKind::kVisibleWhenImported: return DeclModuleOwnershipKind::VISIBLE_WHEN_IMPORTED;
    case pasta::DeclModuleOwnershipKind::kModulePrivate: return DeclModuleOwnershipKind::MODULE_PRIVATE;
  }
}

DeclObjCDeclQualifier FromPasta(pasta::DeclObjCDeclQualifier e) {
  switch (e) {
    case pasta::DeclObjCDeclQualifier::kNone: return DeclObjCDeclQualifier::NONE;
    case pasta::DeclObjCDeclQualifier::kIn: return DeclObjCDeclQualifier::IN;
    case pasta::DeclObjCDeclQualifier::kInout: return DeclObjCDeclQualifier::INOUT;
    case pasta::DeclObjCDeclQualifier::kOut: return DeclObjCDeclQualifier::OUT;
    case pasta::DeclObjCDeclQualifier::kBycopy: return DeclObjCDeclQualifier::BYCOPY;
    case pasta::DeclObjCDeclQualifier::kByref: return DeclObjCDeclQualifier::BYREF;
    case pasta::DeclObjCDeclQualifier::kOneway: return DeclObjCDeclQualifier::ONEWAY;
    case pasta::DeclObjCDeclQualifier::kCSNullability: return DeclObjCDeclQualifier::CS_NULLABILITY;
  }
}

ExprConstantExprKind FromPasta(pasta::ExprConstantExprKind e) {
  switch (e) {
    case pasta::ExprConstantExprKind::kNormal: return ExprConstantExprKind::NORMAL;
    case pasta::ExprConstantExprKind::kNonClassTemplateArgument: return ExprConstantExprKind::NON_CLASS_TEMPLATE_ARGUMENT;
    case pasta::ExprConstantExprKind::kClassTemplateArgument: return ExprConstantExprKind::CLASS_TEMPLATE_ARGUMENT;
    case pasta::ExprConstantExprKind::kImmediateInvocation: return ExprConstantExprKind::IMMEDIATE_INVOCATION;
  }
}

ExprLValueClassification FromPasta(pasta::ExprLValueClassification e) {
  switch (e) {
    case pasta::ExprLValueClassification::kValid: return ExprLValueClassification::VALID;
    case pasta::ExprLValueClassification::kNotObjectType: return ExprLValueClassification::NOT_OBJECT_TYPE;
    case pasta::ExprLValueClassification::kIncompleteVoidType: return ExprLValueClassification::INCOMPLETE_VOID_TYPE;
    case pasta::ExprLValueClassification::kDuplicateVectorComponents: return ExprLValueClassification::DUPLICATE_VECTOR_COMPONENTS;
    case pasta::ExprLValueClassification::kInvalidExpression: return ExprLValueClassification::INVALID_EXPRESSION;
    case pasta::ExprLValueClassification::kInvalidMessageExpression: return ExprLValueClassification::INVALID_MESSAGE_EXPRESSION;
    case pasta::ExprLValueClassification::kMemberFunction: return ExprLValueClassification::MEMBER_FUNCTION;
    case pasta::ExprLValueClassification::kSubObjCPropertySetting: return ExprLValueClassification::SUB_OBJ_C_PROPERTY_SETTING;
    case pasta::ExprLValueClassification::kClassTemporary: return ExprLValueClassification::CLASS_TEMPORARY;
    case pasta::ExprLValueClassification::kArrayTemporary: return ExprLValueClassification::ARRAY_TEMPORARY;
  }
}

ExprNullPointerConstantKind FromPasta(pasta::ExprNullPointerConstantKind e) {
  switch (e) {
    case pasta::ExprNullPointerConstantKind::kNotNull: return ExprNullPointerConstantKind::NOT_NULL;
    case pasta::ExprNullPointerConstantKind::kZeroExpression: return ExprNullPointerConstantKind::ZERO_EXPRESSION;
    case pasta::ExprNullPointerConstantKind::kZeroLiteral: return ExprNullPointerConstantKind::ZERO_LITERAL;
    case pasta::ExprNullPointerConstantKind::kCXX11Nullptr: return ExprNullPointerConstantKind::CX_X11_NULLPTR;
    case pasta::ExprNullPointerConstantKind::kGNUNull: return ExprNullPointerConstantKind::GNU_NULL;
  }
}

ExprNullPointerConstantValueDependence FromPasta(pasta::ExprNullPointerConstantValueDependence e) {
  switch (e) {
    case pasta::ExprNullPointerConstantValueDependence::kNeverValueDependent: return ExprNullPointerConstantValueDependence::NEVER_VALUE_DEPENDENT;
    case pasta::ExprNullPointerConstantValueDependence::kValueDependentIsNull: return ExprNullPointerConstantValueDependence::VALUE_DEPENDENT_IS_NULL;
    case pasta::ExprNullPointerConstantValueDependence::kValueDependentIsNotNull: return ExprNullPointerConstantValueDependence::VALUE_DEPENDENT_IS_NOT_NULL;
  }
}

ExprSideEffectsKind FromPasta(pasta::ExprSideEffectsKind e) {
  switch (e) {
    case pasta::ExprSideEffectsKind::kNoSideEffects: return ExprSideEffectsKind::NO_SIDE_EFFECTS;
    case pasta::ExprSideEffectsKind::kAllowUndefinedBehavior: return ExprSideEffectsKind::ALLOW_UNDEFINED_BEHAVIOR;
    case pasta::ExprSideEffectsKind::kAllowSideEffects: return ExprSideEffectsKind::ALLOW_SIDE_EFFECTS;
  }
}

ExprisModifiableLvalueResult FromPasta(pasta::ExprisModifiableLvalueResult e) {
  switch (e) {
    case pasta::ExprisModifiableLvalueResult::kValid: return ExprisModifiableLvalueResult::VALID;
    case pasta::ExprisModifiableLvalueResult::kNotObjectType: return ExprisModifiableLvalueResult::NOT_OBJECT_TYPE;
    case pasta::ExprisModifiableLvalueResult::kIncompleteVoidType: return ExprisModifiableLvalueResult::INCOMPLETE_VOID_TYPE;
    case pasta::ExprisModifiableLvalueResult::kDuplicateVectorComponents: return ExprisModifiableLvalueResult::DUPLICATE_VECTOR_COMPONENTS;
    case pasta::ExprisModifiableLvalueResult::kInvalidExpression: return ExprisModifiableLvalueResult::INVALID_EXPRESSION;
    case pasta::ExprisModifiableLvalueResult::kLValueCast: return ExprisModifiableLvalueResult::L_VALUE_CAST;
    case pasta::ExprisModifiableLvalueResult::kIncompleteType: return ExprisModifiableLvalueResult::INCOMPLETE_TYPE;
    case pasta::ExprisModifiableLvalueResult::kConstQualified: return ExprisModifiableLvalueResult::CONST_QUALIFIED;
    case pasta::ExprisModifiableLvalueResult::kConstQualifiedField: return ExprisModifiableLvalueResult::CONST_QUALIFIED_FIELD;
    case pasta::ExprisModifiableLvalueResult::kConstAddrSpace: return ExprisModifiableLvalueResult::CONST_ADDR_SPACE;
    case pasta::ExprisModifiableLvalueResult::kArrayType: return ExprisModifiableLvalueResult::ARRAY_TYPE;
    case pasta::ExprisModifiableLvalueResult::kNoSetterProperty: return ExprisModifiableLvalueResult::NO_SETTER_PROPERTY;
    case pasta::ExprisModifiableLvalueResult::kMemberFunction: return ExprisModifiableLvalueResult::MEMBER_FUNCTION;
    case pasta::ExprisModifiableLvalueResult::kSubObjCPropertySetting: return ExprisModifiableLvalueResult::SUB_OBJ_C_PROPERTY_SETTING;
    case pasta::ExprisModifiableLvalueResult::kInvalidMessageExpression: return ExprisModifiableLvalueResult::INVALID_MESSAGE_EXPRESSION;
    case pasta::ExprisModifiableLvalueResult::kClassTemporary: return ExprisModifiableLvalueResult::CLASS_TEMPORARY;
    case pasta::ExprisModifiableLvalueResult::kArrayTemporary: return ExprisModifiableLvalueResult::ARRAY_TEMPORARY;
  }
}

FunctionDeclTemplatedKind FromPasta(pasta::FunctionDeclTemplatedKind e) {
  switch (e) {
    case pasta::FunctionDeclTemplatedKind::kNonTemplate: return FunctionDeclTemplatedKind::NON_TEMPLATE;
    case pasta::FunctionDeclTemplatedKind::kFunctionTemplate: return FunctionDeclTemplatedKind::FUNCTION_TEMPLATE;
    case pasta::FunctionDeclTemplatedKind::kMemberSpecialization: return FunctionDeclTemplatedKind::MEMBER_SPECIALIZATION;
    case pasta::FunctionDeclTemplatedKind::kFunctionTemplateSpecialization: return FunctionDeclTemplatedKind::FUNCTION_TEMPLATE_SPECIALIZATION;
    case pasta::FunctionDeclTemplatedKind::kDependentFunctionTemplateSpecialization: return FunctionDeclTemplatedKind::DEPENDENT_FUNCTION_TEMPLATE_SPECIALIZATION;
  }
}

ImplicitCastExprOnStack FromPasta(pasta::ImplicitCastExprOnStack e) {
  switch (e) {
    case pasta::ImplicitCastExprOnStack::kOnStack: return ImplicitCastExprOnStack::ON_STACK;
  }
}

ImplicitParamDeclImplicitParamKind FromPasta(pasta::ImplicitParamDeclImplicitParamKind e) {
  switch (e) {
    case pasta::ImplicitParamDeclImplicitParamKind::kObjCSelf: return ImplicitParamDeclImplicitParamKind::OBJ_C_SELF;
    case pasta::ImplicitParamDeclImplicitParamKind::kObjCCmd: return ImplicitParamDeclImplicitParamKind::OBJ_C_CMD;
    case pasta::ImplicitParamDeclImplicitParamKind::kCXXThis: return ImplicitParamDeclImplicitParamKind::CXX_THIS;
    case pasta::ImplicitParamDeclImplicitParamKind::kCXXVTT: return ImplicitParamDeclImplicitParamKind::CXXVTT;
    case pasta::ImplicitParamDeclImplicitParamKind::kCapturedContext: return ImplicitParamDeclImplicitParamKind::CAPTURED_CONTEXT;
    case pasta::ImplicitParamDeclImplicitParamKind::kOther: return ImplicitParamDeclImplicitParamKind::OTHER;
  }
}

LinkageSpecDeclLanguageIDs FromPasta(pasta::LinkageSpecDeclLanguageIDs e) {
  switch (e) {
    case pasta::LinkageSpecDeclLanguageIDs::kC: return LinkageSpecDeclLanguageIDs::C;
    case pasta::LinkageSpecDeclLanguageIDs::kCxx: return LinkageSpecDeclLanguageIDs::CXX;
  }
}

NamedDeclExplicitVisibilityKind FromPasta(pasta::NamedDeclExplicitVisibilityKind e) {
  switch (e) {
    case pasta::NamedDeclExplicitVisibilityKind::kVisibilityForType: return NamedDeclExplicitVisibilityKind::VISIBILITY_FOR_TYPE;
    case pasta::NamedDeclExplicitVisibilityKind::kVisibilityForValue: return NamedDeclExplicitVisibilityKind::VISIBILITY_FOR_VALUE;
  }
}

OMPDeclareReductionDeclInitKind FromPasta(pasta::OMPDeclareReductionDeclInitKind e) {
  switch (e) {
    case pasta::OMPDeclareReductionDeclInitKind::kCallInitializer: return OMPDeclareReductionDeclInitKind::CALL_INITIALIZER;
    case pasta::OMPDeclareReductionDeclInitKind::kDirectInitializer: return OMPDeclareReductionDeclInitKind::DIRECT_INITIALIZER;
    case pasta::OMPDeclareReductionDeclInitKind::kCopyInitializer: return OMPDeclareReductionDeclInitKind::COPY_INITIALIZER;
  }
}

ObjCIvarDeclAccessControl FromPasta(pasta::ObjCIvarDeclAccessControl e) {
  switch (e) {
    case pasta::ObjCIvarDeclAccessControl::kNone: return ObjCIvarDeclAccessControl::NONE;
    case pasta::ObjCIvarDeclAccessControl::kPrivate: return ObjCIvarDeclAccessControl::PRIVATE;
    case pasta::ObjCIvarDeclAccessControl::kProtected: return ObjCIvarDeclAccessControl::PROTECTED;
    case pasta::ObjCIvarDeclAccessControl::kPublic: return ObjCIvarDeclAccessControl::PUBLIC;
    case pasta::ObjCIvarDeclAccessControl::kPackage: return ObjCIvarDeclAccessControl::PACKAGE;
  }
}

ObjCMessageExprReceiverKind FromPasta(pasta::ObjCMessageExprReceiverKind e) {
  switch (e) {
    case pasta::ObjCMessageExprReceiverKind::kClass: return ObjCMessageExprReceiverKind::CLASS;
    case pasta::ObjCMessageExprReceiverKind::kInstance: return ObjCMessageExprReceiverKind::INSTANCE;
    case pasta::ObjCMessageExprReceiverKind::kSuperClass: return ObjCMessageExprReceiverKind::SUPER_CLASS;
    case pasta::ObjCMessageExprReceiverKind::kSuperInstance: return ObjCMessageExprReceiverKind::SUPER_INSTANCE;
  }
}

ObjCMethodDeclImplementationControl FromPasta(pasta::ObjCMethodDeclImplementationControl e) {
  switch (e) {
    case pasta::ObjCMethodDeclImplementationControl::kNone: return ObjCMethodDeclImplementationControl::NONE;
    case pasta::ObjCMethodDeclImplementationControl::kRequired: return ObjCMethodDeclImplementationControl::REQUIRED;
    case pasta::ObjCMethodDeclImplementationControl::kOptional: return ObjCMethodDeclImplementationControl::OPTIONAL;
  }
}

ObjCPropertyDeclPropertyControl FromPasta(pasta::ObjCPropertyDeclPropertyControl e) {
  switch (e) {
    case pasta::ObjCPropertyDeclPropertyControl::kNone: return ObjCPropertyDeclPropertyControl::NONE;
    case pasta::ObjCPropertyDeclPropertyControl::kRequired: return ObjCPropertyDeclPropertyControl::REQUIRED;
    case pasta::ObjCPropertyDeclPropertyControl::kOptional: return ObjCPropertyDeclPropertyControl::OPTIONAL;
  }
}

ObjCPropertyDeclSetterKind FromPasta(pasta::ObjCPropertyDeclSetterKind e) {
  switch (e) {
    case pasta::ObjCPropertyDeclSetterKind::kAssign: return ObjCPropertyDeclSetterKind::ASSIGN;
    case pasta::ObjCPropertyDeclSetterKind::kRetain: return ObjCPropertyDeclSetterKind::RETAIN;
    case pasta::ObjCPropertyDeclSetterKind::kCopy: return ObjCPropertyDeclSetterKind::COPY;
    case pasta::ObjCPropertyDeclSetterKind::kWeak: return ObjCPropertyDeclSetterKind::WEAK;
  }
}

ObjCPropertyImplDeclKind FromPasta(pasta::ObjCPropertyImplDeclKind e) {
  switch (e) {
    case pasta::ObjCPropertyImplDeclKind::kSynthesize: return ObjCPropertyImplDeclKind::SYNTHESIZE;
    case pasta::ObjCPropertyImplDeclKind::kDynamic: return ObjCPropertyImplDeclKind::DYNAMIC;
  }
}

PredefinedExprIdentKind FromPasta(pasta::PredefinedExprIdentKind e) {
  switch (e) {
    case pasta::PredefinedExprIdentKind::kFunc: return PredefinedExprIdentKind::FUNC;
    case pasta::PredefinedExprIdentKind::kFunction: return PredefinedExprIdentKind::FUNCTION;
    case pasta::PredefinedExprIdentKind::kLFunction: return PredefinedExprIdentKind::L_FUNCTION;
    case pasta::PredefinedExprIdentKind::kFuncDName: return PredefinedExprIdentKind::FUNC_D_NAME;
    case pasta::PredefinedExprIdentKind::kFuncSig: return PredefinedExprIdentKind::FUNC_SIG;
    case pasta::PredefinedExprIdentKind::kLFuncSig: return PredefinedExprIdentKind::L_FUNC_SIG;
    case pasta::PredefinedExprIdentKind::kPrettyFunction: return PredefinedExprIdentKind::PRETTY_FUNCTION;
    case pasta::PredefinedExprIdentKind::kPrettyFunctionNoVirtual: return PredefinedExprIdentKind::PRETTY_FUNCTION_NO_VIRTUAL;
  }
}

QualTypeDestructionKind FromPasta(pasta::QualTypeDestructionKind e) {
  switch (e) {
    case pasta::QualTypeDestructionKind::kNone: return QualTypeDestructionKind::NONE;
    case pasta::QualTypeDestructionKind::kCxxDestructor: return QualTypeDestructionKind::CXX_DESTRUCTOR;
    case pasta::QualTypeDestructionKind::kObjcStrongLifetime: return QualTypeDestructionKind::OBJC_STRONG_LIFETIME;
    case pasta::QualTypeDestructionKind::kObjcWeakLifetime: return QualTypeDestructionKind::OBJC_WEAK_LIFETIME;
    case pasta::QualTypeDestructionKind::kNontrivialCStruct: return QualTypeDestructionKind::NONTRIVIAL_C_STRUCT;
  }
}

QualTypePrimitiveCopyKind FromPasta(pasta::QualTypePrimitiveCopyKind e) {
  switch (e) {
    case pasta::QualTypePrimitiveCopyKind::kTrivial: return QualTypePrimitiveCopyKind::TRIVIAL;
    case pasta::QualTypePrimitiveCopyKind::kVolatileTrivial: return QualTypePrimitiveCopyKind::VOLATILE_TRIVIAL;
    case pasta::QualTypePrimitiveCopyKind::kARCStrong: return QualTypePrimitiveCopyKind::ARC_STRONG;
    case pasta::QualTypePrimitiveCopyKind::kARCWeak: return QualTypePrimitiveCopyKind::ARC_WEAK;
    case pasta::QualTypePrimitiveCopyKind::kStruct: return QualTypePrimitiveCopyKind::STRUCT;
  }
}

QualTypePrimitiveDefaultInitializeKind FromPasta(pasta::QualTypePrimitiveDefaultInitializeKind e) {
  switch (e) {
    case pasta::QualTypePrimitiveDefaultInitializeKind::kTrivial: return QualTypePrimitiveDefaultInitializeKind::TRIVIAL;
    case pasta::QualTypePrimitiveDefaultInitializeKind::kARCStrong: return QualTypePrimitiveDefaultInitializeKind::ARC_STRONG;
    case pasta::QualTypePrimitiveDefaultInitializeKind::kARCWeak: return QualTypePrimitiveDefaultInitializeKind::ARC_WEAK;
    case pasta::QualTypePrimitiveDefaultInitializeKind::kStruct: return QualTypePrimitiveDefaultInitializeKind::STRUCT;
  }
}

RecordDeclArgPassingKind FromPasta(pasta::RecordDeclArgPassingKind e) {
  switch (e) {
    case pasta::RecordDeclArgPassingKind::kCanPassInRegs: return RecordDeclArgPassingKind::CAN_PASS_IN_REGS;
    case pasta::RecordDeclArgPassingKind::kCannotPassInRegs: return RecordDeclArgPassingKind::CANNOT_PASS_IN_REGS;
    case pasta::RecordDeclArgPassingKind::kCanNeverPassInRegs: return RecordDeclArgPassingKind::CAN_NEVER_PASS_IN_REGS;
  }
}

SourceLocExprIdentKind FromPasta(pasta::SourceLocExprIdentKind e) {
  switch (e) {
    case pasta::SourceLocExprIdentKind::kFunction: return SourceLocExprIdentKind::FUNCTION;
    case pasta::SourceLocExprIdentKind::kFile: return SourceLocExprIdentKind::FILE;
    case pasta::SourceLocExprIdentKind::kLine: return SourceLocExprIdentKind::LINE;
    case pasta::SourceLocExprIdentKind::kColumn: return SourceLocExprIdentKind::COLUMN;
  }
}

StmtLikelihood FromPasta(pasta::StmtLikelihood e) {
  switch (e) {
    case pasta::StmtLikelihood::kUnlikely: return StmtLikelihood::UNLIKELY;
    case pasta::StmtLikelihood::kNone: return StmtLikelihood::NONE;
    case pasta::StmtLikelihood::kLikely: return StmtLikelihood::LIKELY;
  }
}

StmtKind FromPasta(pasta::StmtKind e) {
  switch (e) {
    case pasta::StmtKind::kGCCAsmStmt: return StmtKind::GCC_ASM_STMT;
    case pasta::StmtKind::kMSAsmStmt: return StmtKind::MS_ASM_STMT;
    case pasta::StmtKind::kBreakStmt: return StmtKind::BREAK_STMT;
    case pasta::StmtKind::kCXXCatchStmt: return StmtKind::CXX_CATCH_STMT;
    case pasta::StmtKind::kCXXForRangeStmt: return StmtKind::CXX_FOR_RANGE_STMT;
    case pasta::StmtKind::kCXXTryStmt: return StmtKind::CXX_TRY_STMT;
    case pasta::StmtKind::kCapturedStmt: return StmtKind::CAPTURED_STMT;
    case pasta::StmtKind::kCompoundStmt: return StmtKind::COMPOUND_STMT;
    case pasta::StmtKind::kContinueStmt: return StmtKind::CONTINUE_STMT;
    case pasta::StmtKind::kCoreturnStmt: return StmtKind::CORETURN_STMT;
    case pasta::StmtKind::kCoroutineBodyStmt: return StmtKind::COROUTINE_BODY_STMT;
    case pasta::StmtKind::kDeclStmt: return StmtKind::DECL_STMT;
    case pasta::StmtKind::kDoStmt: return StmtKind::DO_STMT;
    case pasta::StmtKind::kForStmt: return StmtKind::FOR_STMT;
    case pasta::StmtKind::kGotoStmt: return StmtKind::GOTO_STMT;
    case pasta::StmtKind::kIfStmt: return StmtKind::IF_STMT;
    case pasta::StmtKind::kIndirectGotoStmt: return StmtKind::INDIRECT_GOTO_STMT;
    case pasta::StmtKind::kMSDependentExistsStmt: return StmtKind::MS_DEPENDENT_EXISTS_STMT;
    case pasta::StmtKind::kNullStmt: return StmtKind::NULL_STMT;
    case pasta::StmtKind::kOMPCanonicalLoop: return StmtKind::OMP_CANONICAL_LOOP;
    case pasta::StmtKind::kOMPAtomicDirective: return StmtKind::OMP_ATOMIC_DIRECTIVE;
    case pasta::StmtKind::kOMPBarrierDirective: return StmtKind::OMP_BARRIER_DIRECTIVE;
    case pasta::StmtKind::kOMPCancelDirective: return StmtKind::OMP_CANCEL_DIRECTIVE;
    case pasta::StmtKind::kOMPCancellationPointDirective: return StmtKind::OMP_CANCELLATION_POINT_DIRECTIVE;
    case pasta::StmtKind::kOMPCriticalDirective: return StmtKind::OMP_CRITICAL_DIRECTIVE;
    case pasta::StmtKind::kOMPDepobjDirective: return StmtKind::OMP_DEPOBJ_DIRECTIVE;
    case pasta::StmtKind::kOMPDispatchDirective: return StmtKind::OMP_DISPATCH_DIRECTIVE;
    case pasta::StmtKind::kOMPFlushDirective: return StmtKind::OMP_FLUSH_DIRECTIVE;
    case pasta::StmtKind::kOMPInteropDirective: return StmtKind::OMP_INTEROP_DIRECTIVE;
    case pasta::StmtKind::kOMPDistributeDirective: return StmtKind::OMP_DISTRIBUTE_DIRECTIVE;
    case pasta::StmtKind::kOMPDistributeParallelForDirective: return StmtKind::OMP_DISTRIBUTE_PARALLEL_FOR_DIRECTIVE;
    case pasta::StmtKind::kOMPDistributeParallelForSimdDirective: return StmtKind::OMP_DISTRIBUTE_PARALLEL_FOR_SIMD_DIRECTIVE;
    case pasta::StmtKind::kOMPDistributeSimdDirective: return StmtKind::OMP_DISTRIBUTE_SIMD_DIRECTIVE;
    case pasta::StmtKind::kOMPForDirective: return StmtKind::OMP_FOR_DIRECTIVE;
    case pasta::StmtKind::kOMPForSimdDirective: return StmtKind::OMP_FOR_SIMD_DIRECTIVE;
    case pasta::StmtKind::kOMPMasterTaskLoopDirective: return StmtKind::OMP_MASTER_TASK_LOOP_DIRECTIVE;
    case pasta::StmtKind::kOMPMasterTaskLoopSimdDirective: return StmtKind::OMP_MASTER_TASK_LOOP_SIMD_DIRECTIVE;
    case pasta::StmtKind::kOMPParallelForDirective: return StmtKind::OMP_PARALLEL_FOR_DIRECTIVE;
    case pasta::StmtKind::kOMPParallelForSimdDirective: return StmtKind::OMP_PARALLEL_FOR_SIMD_DIRECTIVE;
    case pasta::StmtKind::kOMPParallelMasterTaskLoopDirective: return StmtKind::OMP_PARALLEL_MASTER_TASK_LOOP_DIRECTIVE;
    case pasta::StmtKind::kOMPParallelMasterTaskLoopSimdDirective: return StmtKind::OMP_PARALLEL_MASTER_TASK_LOOP_SIMD_DIRECTIVE;
    case pasta::StmtKind::kOMPSimdDirective: return StmtKind::OMP_SIMD_DIRECTIVE;
    case pasta::StmtKind::kOMPTargetParallelForSimdDirective: return StmtKind::OMP_TARGET_PARALLEL_FOR_SIMD_DIRECTIVE;
    case pasta::StmtKind::kOMPTargetSimdDirective: return StmtKind::OMP_TARGET_SIMD_DIRECTIVE;
    case pasta::StmtKind::kOMPTargetTeamsDistributeDirective: return StmtKind::OMP_TARGET_TEAMS_DISTRIBUTE_DIRECTIVE;
    case pasta::StmtKind::kOMPTargetTeamsDistributeParallelForDirective: return StmtKind::OMP_TARGET_TEAMS_DISTRIBUTE_PARALLEL_FOR_DIRECTIVE;
    case pasta::StmtKind::kOMPTargetTeamsDistributeParallelForSimdDirective: return StmtKind::OMP_TARGET_TEAMS_DISTRIBUTE_PARALLEL_FOR_SIMD_DIRECTIVE;
    case pasta::StmtKind::kOMPTargetTeamsDistributeSimdDirective: return StmtKind::OMP_TARGET_TEAMS_DISTRIBUTE_SIMD_DIRECTIVE;
    case pasta::StmtKind::kOMPTaskLoopDirective: return StmtKind::OMP_TASK_LOOP_DIRECTIVE;
    case pasta::StmtKind::kOMPTaskLoopSimdDirective: return StmtKind::OMP_TASK_LOOP_SIMD_DIRECTIVE;
    case pasta::StmtKind::kOMPTeamsDistributeDirective: return StmtKind::OMP_TEAMS_DISTRIBUTE_DIRECTIVE;
    case pasta::StmtKind::kOMPTeamsDistributeParallelForDirective: return StmtKind::OMP_TEAMS_DISTRIBUTE_PARALLEL_FOR_DIRECTIVE;
    case pasta::StmtKind::kOMPTeamsDistributeParallelForSimdDirective: return StmtKind::OMP_TEAMS_DISTRIBUTE_PARALLEL_FOR_SIMD_DIRECTIVE;
    case pasta::StmtKind::kOMPTeamsDistributeSimdDirective: return StmtKind::OMP_TEAMS_DISTRIBUTE_SIMD_DIRECTIVE;
    case pasta::StmtKind::kOMPTileDirective: return StmtKind::OMP_TILE_DIRECTIVE;
    case pasta::StmtKind::kOMPUnrollDirective: return StmtKind::OMP_UNROLL_DIRECTIVE;
    case pasta::StmtKind::kOMPMaskedDirective: return StmtKind::OMP_MASKED_DIRECTIVE;
    case pasta::StmtKind::kOMPMasterDirective: return StmtKind::OMP_MASTER_DIRECTIVE;
    case pasta::StmtKind::kOMPOrderedDirective: return StmtKind::OMP_ORDERED_DIRECTIVE;
    case pasta::StmtKind::kOMPParallelDirective: return StmtKind::OMP_PARALLEL_DIRECTIVE;
    case pasta::StmtKind::kOMPParallelMasterDirective: return StmtKind::OMP_PARALLEL_MASTER_DIRECTIVE;
    case pasta::StmtKind::kOMPParallelSectionsDirective: return StmtKind::OMP_PARALLEL_SECTIONS_DIRECTIVE;
    case pasta::StmtKind::kOMPScanDirective: return StmtKind::OMP_SCAN_DIRECTIVE;
    case pasta::StmtKind::kOMPSectionDirective: return StmtKind::OMP_SECTION_DIRECTIVE;
    case pasta::StmtKind::kOMPSectionsDirective: return StmtKind::OMP_SECTIONS_DIRECTIVE;
    case pasta::StmtKind::kOMPSingleDirective: return StmtKind::OMP_SINGLE_DIRECTIVE;
    case pasta::StmtKind::kOMPTargetDataDirective: return StmtKind::OMP_TARGET_DATA_DIRECTIVE;
    case pasta::StmtKind::kOMPTargetDirective: return StmtKind::OMP_TARGET_DIRECTIVE;
    case pasta::StmtKind::kOMPTargetEnterDataDirective: return StmtKind::OMP_TARGET_ENTER_DATA_DIRECTIVE;
    case pasta::StmtKind::kOMPTargetExitDataDirective: return StmtKind::OMP_TARGET_EXIT_DATA_DIRECTIVE;
    case pasta::StmtKind::kOMPTargetParallelDirective: return StmtKind::OMP_TARGET_PARALLEL_DIRECTIVE;
    case pasta::StmtKind::kOMPTargetParallelForDirective: return StmtKind::OMP_TARGET_PARALLEL_FOR_DIRECTIVE;
    case pasta::StmtKind::kOMPTargetTeamsDirective: return StmtKind::OMP_TARGET_TEAMS_DIRECTIVE;
    case pasta::StmtKind::kOMPTargetUpdateDirective: return StmtKind::OMP_TARGET_UPDATE_DIRECTIVE;
    case pasta::StmtKind::kOMPTaskDirective: return StmtKind::OMP_TASK_DIRECTIVE;
    case pasta::StmtKind::kOMPTaskgroupDirective: return StmtKind::OMP_TASKGROUP_DIRECTIVE;
    case pasta::StmtKind::kOMPTaskwaitDirective: return StmtKind::OMP_TASKWAIT_DIRECTIVE;
    case pasta::StmtKind::kOMPTaskyieldDirective: return StmtKind::OMP_TASKYIELD_DIRECTIVE;
    case pasta::StmtKind::kOMPTeamsDirective: return StmtKind::OMP_TEAMS_DIRECTIVE;
    case pasta::StmtKind::kObjCAtCatchStmt: return StmtKind::OBJ_C_AT_CATCH_STMT;
    case pasta::StmtKind::kObjCAtFinallyStmt: return StmtKind::OBJ_C_AT_FINALLY_STMT;
    case pasta::StmtKind::kObjCAtSynchronizedStmt: return StmtKind::OBJ_C_AT_SYNCHRONIZED_STMT;
    case pasta::StmtKind::kObjCAtThrowStmt: return StmtKind::OBJ_C_AT_THROW_STMT;
    case pasta::StmtKind::kObjCAtTryStmt: return StmtKind::OBJ_C_AT_TRY_STMT;
    case pasta::StmtKind::kObjCAutoreleasePoolStmt: return StmtKind::OBJ_C_AUTORELEASE_POOL_STMT;
    case pasta::StmtKind::kObjCForCollectionStmt: return StmtKind::OBJ_C_FOR_COLLECTION_STMT;
    case pasta::StmtKind::kReturnStmt: return StmtKind::RETURN_STMT;
    case pasta::StmtKind::kSEHExceptStmt: return StmtKind::SEH_EXCEPT_STMT;
    case pasta::StmtKind::kSEHFinallyStmt: return StmtKind::SEH_FINALLY_STMT;
    case pasta::StmtKind::kSEHLeaveStmt: return StmtKind::SEH_LEAVE_STMT;
    case pasta::StmtKind::kSEHTryStmt: return StmtKind::SEH_TRY_STMT;
    case pasta::StmtKind::kCaseStmt: return StmtKind::CASE_STMT;
    case pasta::StmtKind::kDefaultStmt: return StmtKind::DEFAULT_STMT;
    case pasta::StmtKind::kSwitchStmt: return StmtKind::SWITCH_STMT;
    case pasta::StmtKind::kAttributedStmt: return StmtKind::ATTRIBUTED_STMT;
    case pasta::StmtKind::kBinaryConditionalOperator: return StmtKind::BINARY_CONDITIONAL_OPERATOR;
    case pasta::StmtKind::kConditionalOperator: return StmtKind::CONDITIONAL_OPERATOR;
    case pasta::StmtKind::kAddrLabelExpr: return StmtKind::ADDR_LABEL_EXPR;
    case pasta::StmtKind::kArrayInitIndexExpr: return StmtKind::ARRAY_INIT_INDEX_EXPR;
    case pasta::StmtKind::kArrayInitLoopExpr: return StmtKind::ARRAY_INIT_LOOP_EXPR;
    case pasta::StmtKind::kArraySubscriptExpr: return StmtKind::ARRAY_SUBSCRIPT_EXPR;
    case pasta::StmtKind::kArrayTypeTraitExpr: return StmtKind::ARRAY_TYPE_TRAIT_EXPR;
    case pasta::StmtKind::kAsTypeExpr: return StmtKind::AS_TYPE_EXPR;
    case pasta::StmtKind::kAtomicExpr: return StmtKind::ATOMIC_EXPR;
    case pasta::StmtKind::kBinaryOperator: return StmtKind::BINARY_OPERATOR;
    case pasta::StmtKind::kCompoundAssignOperator: return StmtKind::COMPOUND_ASSIGN_OPERATOR;
    case pasta::StmtKind::kBlockExpr: return StmtKind::BLOCK_EXPR;
    case pasta::StmtKind::kCXXBindTemporaryExpr: return StmtKind::CXX_BIND_TEMPORARY_EXPR;
    case pasta::StmtKind::kCXXBoolLiteralExpr: return StmtKind::CXX_BOOL_LITERAL_EXPR;
    case pasta::StmtKind::kCXXConstructExpr: return StmtKind::CXX_CONSTRUCT_EXPR;
    case pasta::StmtKind::kCXXTemporaryObjectExpr: return StmtKind::CXX_TEMPORARY_OBJECT_EXPR;
    case pasta::StmtKind::kCXXDefaultArgExpr: return StmtKind::CXX_DEFAULT_ARG_EXPR;
    case pasta::StmtKind::kCXXDefaultInitExpr: return StmtKind::CXX_DEFAULT_INIT_EXPR;
    case pasta::StmtKind::kCXXDeleteExpr: return StmtKind::CXX_DELETE_EXPR;
    case pasta::StmtKind::kCXXDependentScopeMemberExpr: return StmtKind::CXX_DEPENDENT_SCOPE_MEMBER_EXPR;
    case pasta::StmtKind::kCXXFoldExpr: return StmtKind::CXX_FOLD_EXPR;
    case pasta::StmtKind::kCXXInheritedCtorInitExpr: return StmtKind::CXX_INHERITED_CTOR_INIT_EXPR;
    case pasta::StmtKind::kCXXNewExpr: return StmtKind::CXX_NEW_EXPR;
    case pasta::StmtKind::kCXXNoexceptExpr: return StmtKind::CXX_NOEXCEPT_EXPR;
    case pasta::StmtKind::kCXXNullPtrLiteralExpr: return StmtKind::CXX_NULL_PTR_LITERAL_EXPR;
    case pasta::StmtKind::kCXXPseudoDestructorExpr: return StmtKind::CXX_PSEUDO_DESTRUCTOR_EXPR;
    case pasta::StmtKind::kCXXRewrittenBinaryOperator: return StmtKind::CXX_REWRITTEN_BINARY_OPERATOR;
    case pasta::StmtKind::kCXXScalarValueInitExpr: return StmtKind::CXX_SCALAR_VALUE_INIT_EXPR;
    case pasta::StmtKind::kCXXStdInitializerListExpr: return StmtKind::CXX_STD_INITIALIZER_LIST_EXPR;
    case pasta::StmtKind::kCXXThisExpr: return StmtKind::CXX_THIS_EXPR;
    case pasta::StmtKind::kCXXThrowExpr: return StmtKind::CXX_THROW_EXPR;
    case pasta::StmtKind::kCXXTypeidExpr: return StmtKind::CXX_TYPEID_EXPR;
    case pasta::StmtKind::kCXXUnresolvedConstructExpr: return StmtKind::CXX_UNRESOLVED_CONSTRUCT_EXPR;
    case pasta::StmtKind::kCXXUuidofExpr: return StmtKind::CXX_UUIDOF_EXPR;
    case pasta::StmtKind::kCallExpr: return StmtKind::CALL_EXPR;
    case pasta::StmtKind::kCUDAKernelCallExpr: return StmtKind::CUDA_KERNEL_CALL_EXPR;
    case pasta::StmtKind::kCXXMemberCallExpr: return StmtKind::CXX_MEMBER_CALL_EXPR;
    case pasta::StmtKind::kCXXOperatorCallExpr: return StmtKind::CXX_OPERATOR_CALL_EXPR;
    case pasta::StmtKind::kUserDefinedLiteral: return StmtKind::USER_DEFINED_LITERAL;
    case pasta::StmtKind::kBuiltinBitCastExpr: return StmtKind::BUILTIN_BIT_CAST_EXPR;
    case pasta::StmtKind::kCStyleCastExpr: return StmtKind::C_STYLE_CAST_EXPR;
    case pasta::StmtKind::kCXXFunctionalCastExpr: return StmtKind::CXX_FUNCTIONAL_CAST_EXPR;
    case pasta::StmtKind::kCXXAddrspaceCastExpr: return StmtKind::CXX_ADDRSPACE_CAST_EXPR;
    case pasta::StmtKind::kCXXConstCastExpr: return StmtKind::CXX_CONST_CAST_EXPR;
    case pasta::StmtKind::kCXXDynamicCastExpr: return StmtKind::CXX_DYNAMIC_CAST_EXPR;
    case pasta::StmtKind::kCXXReinterpretCastExpr: return StmtKind::CXX_REINTERPRET_CAST_EXPR;
    case pasta::StmtKind::kCXXStaticCastExpr: return StmtKind::CXX_STATIC_CAST_EXPR;
    case pasta::StmtKind::kObjCBridgedCastExpr: return StmtKind::OBJ_C_BRIDGED_CAST_EXPR;
    case pasta::StmtKind::kImplicitCastExpr: return StmtKind::IMPLICIT_CAST_EXPR;
    case pasta::StmtKind::kCharacterLiteral: return StmtKind::CHARACTER_LITERAL;
    case pasta::StmtKind::kChooseExpr: return StmtKind::CHOOSE_EXPR;
    case pasta::StmtKind::kCompoundLiteralExpr: return StmtKind::COMPOUND_LITERAL_EXPR;
    case pasta::StmtKind::kConceptSpecializationExpr: return StmtKind::CONCEPT_SPECIALIZATION_EXPR;
    case pasta::StmtKind::kConvertVectorExpr: return StmtKind::CONVERT_VECTOR_EXPR;
    case pasta::StmtKind::kCoawaitExpr: return StmtKind::COAWAIT_EXPR;
    case pasta::StmtKind::kCoyieldExpr: return StmtKind::COYIELD_EXPR;
    case pasta::StmtKind::kDeclRefExpr: return StmtKind::DECL_REF_EXPR;
    case pasta::StmtKind::kDependentCoawaitExpr: return StmtKind::DEPENDENT_COAWAIT_EXPR;
    case pasta::StmtKind::kDependentScopeDeclRefExpr: return StmtKind::DEPENDENT_SCOPE_DECL_REF_EXPR;
    case pasta::StmtKind::kDesignatedInitExpr: return StmtKind::DESIGNATED_INIT_EXPR;
    case pasta::StmtKind::kDesignatedInitUpdateExpr: return StmtKind::DESIGNATED_INIT_UPDATE_EXPR;
    case pasta::StmtKind::kExpressionTraitExpr: return StmtKind::EXPRESSION_TRAIT_EXPR;
    case pasta::StmtKind::kExtVectorElementExpr: return StmtKind::EXT_VECTOR_ELEMENT_EXPR;
    case pasta::StmtKind::kFixedPointLiteral: return StmtKind::FIXED_POINT_LITERAL;
    case pasta::StmtKind::kFloatingLiteral: return StmtKind::FLOATING_LITERAL;
    case pasta::StmtKind::kConstantExpr: return StmtKind::CONSTANT_EXPR;
    case pasta::StmtKind::kExprWithCleanups: return StmtKind::EXPR_WITH_CLEANUPS;
    case pasta::StmtKind::kFunctionParmPackExpr: return StmtKind::FUNCTION_PARM_PACK_EXPR;
    case pasta::StmtKind::kGNUNullExpr: return StmtKind::GNU_NULL_EXPR;
    case pasta::StmtKind::kGenericSelectionExpr: return StmtKind::GENERIC_SELECTION_EXPR;
    case pasta::StmtKind::kImaginaryLiteral: return StmtKind::IMAGINARY_LITERAL;
    case pasta::StmtKind::kImplicitValueInitExpr: return StmtKind::IMPLICIT_VALUE_INIT_EXPR;
    case pasta::StmtKind::kInitListExpr: return StmtKind::INIT_LIST_EXPR;
    case pasta::StmtKind::kIntegerLiteral: return StmtKind::INTEGER_LITERAL;
    case pasta::StmtKind::kLambdaExpr: return StmtKind::LAMBDA_EXPR;
    case pasta::StmtKind::kMSPropertyRefExpr: return StmtKind::MS_PROPERTY_REF_EXPR;
    case pasta::StmtKind::kMSPropertySubscriptExpr: return StmtKind::MS_PROPERTY_SUBSCRIPT_EXPR;
    case pasta::StmtKind::kMaterializeTemporaryExpr: return StmtKind::MATERIALIZE_TEMPORARY_EXPR;
    case pasta::StmtKind::kMatrixSubscriptExpr: return StmtKind::MATRIX_SUBSCRIPT_EXPR;
    case pasta::StmtKind::kMemberExpr: return StmtKind::MEMBER_EXPR;
    case pasta::StmtKind::kNoInitExpr: return StmtKind::NO_INIT_EXPR;
    case pasta::StmtKind::kOMPArraySectionExpr: return StmtKind::OMP_ARRAY_SECTION_EXPR;
    case pasta::StmtKind::kOMPArrayShapingExpr: return StmtKind::OMP_ARRAY_SHAPING_EXPR;
    case pasta::StmtKind::kOMPIteratorExpr: return StmtKind::OMP_ITERATOR_EXPR;
    case pasta::StmtKind::kObjCArrayLiteral: return StmtKind::OBJ_C_ARRAY_LITERAL;
    case pasta::StmtKind::kObjCAvailabilityCheckExpr: return StmtKind::OBJ_C_AVAILABILITY_CHECK_EXPR;
    case pasta::StmtKind::kObjCBoolLiteralExpr: return StmtKind::OBJ_C_BOOL_LITERAL_EXPR;
    case pasta::StmtKind::kObjCBoxedExpr: return StmtKind::OBJ_C_BOXED_EXPR;
    case pasta::StmtKind::kObjCDictionaryLiteral: return StmtKind::OBJ_C_DICTIONARY_LITERAL;
    case pasta::StmtKind::kObjCEncodeExpr: return StmtKind::OBJ_C_ENCODE_EXPR;
    case pasta::StmtKind::kObjCIndirectCopyRestoreExpr: return StmtKind::OBJ_C_INDIRECT_COPY_RESTORE_EXPR;
    case pasta::StmtKind::kObjCIsaExpr: return StmtKind::OBJ_C_ISA_EXPR;
    case pasta::StmtKind::kObjCIvarRefExpr: return StmtKind::OBJ_C_IVAR_REF_EXPR;
    case pasta::StmtKind::kObjCMessageExpr: return StmtKind::OBJ_C_MESSAGE_EXPR;
    case pasta::StmtKind::kObjCPropertyRefExpr: return StmtKind::OBJ_C_PROPERTY_REF_EXPR;
    case pasta::StmtKind::kObjCProtocolExpr: return StmtKind::OBJ_C_PROTOCOL_EXPR;
    case pasta::StmtKind::kObjCSelectorExpr: return StmtKind::OBJ_C_SELECTOR_EXPR;
    case pasta::StmtKind::kObjCStringLiteral: return StmtKind::OBJ_C_STRING_LITERAL;
    case pasta::StmtKind::kObjCSubscriptRefExpr: return StmtKind::OBJ_C_SUBSCRIPT_REF_EXPR;
    case pasta::StmtKind::kOffsetOfExpr: return StmtKind::OFFSET_OF_EXPR;
    case pasta::StmtKind::kOpaqueValueExpr: return StmtKind::OPAQUE_VALUE_EXPR;
    case pasta::StmtKind::kUnresolvedLookupExpr: return StmtKind::UNRESOLVED_LOOKUP_EXPR;
    case pasta::StmtKind::kUnresolvedMemberExpr: return StmtKind::UNRESOLVED_MEMBER_EXPR;
    case pasta::StmtKind::kPackExpansionExpr: return StmtKind::PACK_EXPANSION_EXPR;
    case pasta::StmtKind::kParenExpr: return StmtKind::PAREN_EXPR;
    case pasta::StmtKind::kParenListExpr: return StmtKind::PAREN_LIST_EXPR;
    case pasta::StmtKind::kPredefinedExpr: return StmtKind::PREDEFINED_EXPR;
    case pasta::StmtKind::kPseudoObjectExpr: return StmtKind::PSEUDO_OBJECT_EXPR;
    case pasta::StmtKind::kRecoveryExpr: return StmtKind::RECOVERY_EXPR;
    case pasta::StmtKind::kRequiresExpr: return StmtKind::REQUIRES_EXPR;
    case pasta::StmtKind::kSYCLUniqueStableNameExpr: return StmtKind::SYCL_UNIQUE_STABLE_NAME_EXPR;
    case pasta::StmtKind::kShuffleVectorExpr: return StmtKind::SHUFFLE_VECTOR_EXPR;
    case pasta::StmtKind::kSizeOfPackExpr: return StmtKind::SIZE_OF_PACK_EXPR;
    case pasta::StmtKind::kSourceLocExpr: return StmtKind::SOURCE_LOC_EXPR;
    case pasta::StmtKind::kStmtExpr: return StmtKind::STMT_EXPR;
    case pasta::StmtKind::kStringLiteral: return StmtKind::STRING_LITERAL;
    case pasta::StmtKind::kSubstNonTypeTemplateParmExpr: return StmtKind::SUBST_NON_TYPE_TEMPLATE_PARM_EXPR;
    case pasta::StmtKind::kSubstNonTypeTemplateParmPackExpr: return StmtKind::SUBST_NON_TYPE_TEMPLATE_PARM_PACK_EXPR;
    case pasta::StmtKind::kTypeTraitExpr: return StmtKind::TYPE_TRAIT_EXPR;
    case pasta::StmtKind::kTypoExpr: return StmtKind::TYPO_EXPR;
    case pasta::StmtKind::kUnaryExprOrTypeTraitExpr: return StmtKind::UNARY_EXPR_OR_TYPE_TRAIT_EXPR;
    case pasta::StmtKind::kUnaryOperator: return StmtKind::UNARY_OPERATOR;
    case pasta::StmtKind::kVAArgExpr: return StmtKind::VA_ARG_EXPR;
    case pasta::StmtKind::kLabelStmt: return StmtKind::LABEL_STMT;
    case pasta::StmtKind::kWhileStmt: return StmtKind::WHILE_STMT;
  }
}

StringLiteralStringKind FromPasta(pasta::StringLiteralStringKind e) {
  switch (e) {
    case pasta::StringLiteralStringKind::kAscii: return StringLiteralStringKind::ASCII;
    case pasta::StringLiteralStringKind::kWide: return StringLiteralStringKind::WIDE;
    case pasta::StringLiteralStringKind::kUTF8: return StringLiteralStringKind::UT_F8;
    case pasta::StringLiteralStringKind::kUTF16: return StringLiteralStringKind::UT_F16;
    case pasta::StringLiteralStringKind::kUTF32: return StringLiteralStringKind::UT_F32;
  }
}

TemplateArgumentKind FromPasta(pasta::TemplateArgumentKind e) {
  switch (e) {
    case pasta::TemplateArgumentKind::kEmpty: return TemplateArgumentKind::EMPTY;
    case pasta::TemplateArgumentKind::kType: return TemplateArgumentKind::TYPE;
    case pasta::TemplateArgumentKind::kDeclaration: return TemplateArgumentKind::DECLARATION;
    case pasta::TemplateArgumentKind::kNullPointer: return TemplateArgumentKind::NULL_POINTER;
    case pasta::TemplateArgumentKind::kIntegral: return TemplateArgumentKind::INTEGRAL;
    case pasta::TemplateArgumentKind::kTemplate: return TemplateArgumentKind::TEMPLATE;
    case pasta::TemplateArgumentKind::kTemplateExpansion: return TemplateArgumentKind::TEMPLATE_EXPANSION;
    case pasta::TemplateArgumentKind::kExpression: return TemplateArgumentKind::EXPRESSION;
    case pasta::TemplateArgumentKind::kPack: return TemplateArgumentKind::PACK;
  }
}

TypeScalarTypeKind FromPasta(pasta::TypeScalarTypeKind e) {
  switch (e) {
    case pasta::TypeScalarTypeKind::kCPointer: return TypeScalarTypeKind::C_POINTER;
    case pasta::TypeScalarTypeKind::kBlockPointer: return TypeScalarTypeKind::BLOCK_POINTER;
    case pasta::TypeScalarTypeKind::kObjCObjectPointer: return TypeScalarTypeKind::OBJ_C_OBJECT_POINTER;
    case pasta::TypeScalarTypeKind::kMemberPointer: return TypeScalarTypeKind::MEMBER_POINTER;
    case pasta::TypeScalarTypeKind::kBoolean: return TypeScalarTypeKind::BOOLEAN;
    case pasta::TypeScalarTypeKind::kIntegral: return TypeScalarTypeKind::INTEGRAL;
    case pasta::TypeScalarTypeKind::kFloating: return TypeScalarTypeKind::FLOATING;
    case pasta::TypeScalarTypeKind::kIntegralComplex: return TypeScalarTypeKind::INTEGRAL_COMPLEX;
    case pasta::TypeScalarTypeKind::kFloatingComplex: return TypeScalarTypeKind::FLOATING_COMPLEX;
    case pasta::TypeScalarTypeKind::kFixedPoint: return TypeScalarTypeKind::FIXED_POINT;
  }
}

TypeKind FromPasta(pasta::TypeKind e) {
  switch (e) {
    case pasta::TypeKind::kAdjusted: return TypeKind::ADJUSTED;
    case pasta::TypeKind::kDecayed: return TypeKind::DECAYED;
    case pasta::TypeKind::kConstantArray: return TypeKind::CONSTANT_ARRAY;
    case pasta::TypeKind::kDependentSizedArray: return TypeKind::DEPENDENT_SIZED_ARRAY;
    case pasta::TypeKind::kIncompleteArray: return TypeKind::INCOMPLETE_ARRAY;
    case pasta::TypeKind::kVariableArray: return TypeKind::VARIABLE_ARRAY;
    case pasta::TypeKind::kAtomic: return TypeKind::ATOMIC;
    case pasta::TypeKind::kAttributed: return TypeKind::ATTRIBUTED;
    case pasta::TypeKind::kBlockPointer: return TypeKind::BLOCK_POINTER;
    case pasta::TypeKind::kBuiltin: return TypeKind::BUILTIN;
    case pasta::TypeKind::kComplex: return TypeKind::COMPLEX;
    case pasta::TypeKind::kDecltype: return TypeKind::DECLTYPE;
    case pasta::TypeKind::kAuto: return TypeKind::AUTO;
    case pasta::TypeKind::kDeducedTemplateSpecialization: return TypeKind::DEDUCED_TEMPLATE_SPECIALIZATION;
    case pasta::TypeKind::kDependentAddressSpace: return TypeKind::DEPENDENT_ADDRESS_SPACE;
    case pasta::TypeKind::kDependentExtInt: return TypeKind::DEPENDENT_EXT_INT;
    case pasta::TypeKind::kDependentName: return TypeKind::DEPENDENT_NAME;
    case pasta::TypeKind::kDependentSizedExtVector: return TypeKind::DEPENDENT_SIZED_EXT_VECTOR;
    case pasta::TypeKind::kDependentTemplateSpecialization: return TypeKind::DEPENDENT_TEMPLATE_SPECIALIZATION;
    case pasta::TypeKind::kDependentVector: return TypeKind::DEPENDENT_VECTOR;
    case pasta::TypeKind::kElaborated: return TypeKind::ELABORATED;
    case pasta::TypeKind::kExtInt: return TypeKind::EXT_INT;
    case pasta::TypeKind::kFunctionNoProto: return TypeKind::FUNCTION_NO_PROTO;
    case pasta::TypeKind::kFunctionProto: return TypeKind::FUNCTION_PROTO;
    case pasta::TypeKind::kInjectedClassName: return TypeKind::INJECTED_CLASS_NAME;
    case pasta::TypeKind::kMacroQualified: return TypeKind::MACRO_QUALIFIED;
    case pasta::TypeKind::kConstantMatrix: return TypeKind::CONSTANT_MATRIX;
    case pasta::TypeKind::kDependentSizedMatrix: return TypeKind::DEPENDENT_SIZED_MATRIX;
    case pasta::TypeKind::kMemberPointer: return TypeKind::MEMBER_POINTER;
    case pasta::TypeKind::kObjCObjectPointer: return TypeKind::OBJ_C_OBJECT_POINTER;
    case pasta::TypeKind::kObjCObject: return TypeKind::OBJ_C_OBJECT;
    case pasta::TypeKind::kObjCInterface: return TypeKind::OBJ_C_INTERFACE;
    case pasta::TypeKind::kObjCTypeParam: return TypeKind::OBJ_C_TYPE_PARAM;
    case pasta::TypeKind::kPackExpansion: return TypeKind::PACK_EXPANSION;
    case pasta::TypeKind::kParen: return TypeKind::PAREN;
    case pasta::TypeKind::kPipe: return TypeKind::PIPE;
    case pasta::TypeKind::kPointer: return TypeKind::POINTER;
    case pasta::TypeKind::kLValueReference: return TypeKind::L_VALUE_REFERENCE;
    case pasta::TypeKind::kRValueReference: return TypeKind::R_VALUE_REFERENCE;
    case pasta::TypeKind::kSubstTemplateTypeParmPack: return TypeKind::SUBST_TEMPLATE_TYPE_PARM_PACK;
    case pasta::TypeKind::kSubstTemplateTypeParm: return TypeKind::SUBST_TEMPLATE_TYPE_PARM;
    case pasta::TypeKind::kEnum: return TypeKind::ENUM;
    case pasta::TypeKind::kRecord: return TypeKind::RECORD;
    case pasta::TypeKind::kTemplateSpecialization: return TypeKind::TEMPLATE_SPECIALIZATION;
    case pasta::TypeKind::kTemplateTypeParm: return TypeKind::TEMPLATE_TYPE_PARM;
    case pasta::TypeKind::kTypeOfExpr: return TypeKind::TYPE_OF_EXPR;
    case pasta::TypeKind::kTypeOf: return TypeKind::TYPE_OF;
    case pasta::TypeKind::kTypedef: return TypeKind::TYPEDEF;
    case pasta::TypeKind::kUnaryTransform: return TypeKind::UNARY_TRANSFORM;
    case pasta::TypeKind::kUnresolvedUsing: return TypeKind::UNRESOLVED_USING;
    case pasta::TypeKind::kVector: return TypeKind::VECTOR;
    case pasta::TypeKind::kExtVector: return TypeKind::EXT_VECTOR;
  }
}

UnaryTransformTypeUTTKind FromPasta(pasta::UnaryTransformTypeUTTKind e) {
  switch (e) {
    case pasta::UnaryTransformTypeUTTKind::kEnumUnderlyingType: return UnaryTransformTypeUTTKind::ENUM_UNDERLYING_TYPE;
  }
}

UserDefinedLiteralLiteralOperatorKind FromPasta(pasta::UserDefinedLiteralLiteralOperatorKind e) {
  switch (e) {
    case pasta::UserDefinedLiteralLiteralOperatorKind::kRaw: return UserDefinedLiteralLiteralOperatorKind::RAW;
    case pasta::UserDefinedLiteralLiteralOperatorKind::kTemplate: return UserDefinedLiteralLiteralOperatorKind::TEMPLATE;
    case pasta::UserDefinedLiteralLiteralOperatorKind::kInteger: return UserDefinedLiteralLiteralOperatorKind::INTEGER;
    case pasta::UserDefinedLiteralLiteralOperatorKind::kFloating: return UserDefinedLiteralLiteralOperatorKind::FLOATING;
    case pasta::UserDefinedLiteralLiteralOperatorKind::kString: return UserDefinedLiteralLiteralOperatorKind::STRING;
    case pasta::UserDefinedLiteralLiteralOperatorKind::kCharacter: return UserDefinedLiteralLiteralOperatorKind::CHARACTER;
  }
}

VarDeclDefinitionKind FromPasta(pasta::VarDeclDefinitionKind e) {
  switch (e) {
    case pasta::VarDeclDefinitionKind::kDeclarationOnly: return VarDeclDefinitionKind::DECLARATION_ONLY;
    case pasta::VarDeclDefinitionKind::kTentativeDefinition: return VarDeclDefinitionKind::TENTATIVE_DEFINITION;
    case pasta::VarDeclDefinitionKind::kDefinition: return VarDeclDefinitionKind::DEFINITION;
  }
}

VarDeclInitializationStyle FromPasta(pasta::VarDeclInitializationStyle e) {
  switch (e) {
    case pasta::VarDeclInitializationStyle::kCInit: return VarDeclInitializationStyle::C_INIT;
    case pasta::VarDeclInitializationStyle::kCallInitializer: return VarDeclInitializationStyle::CALL_INITIALIZER;
    case pasta::VarDeclInitializationStyle::kListInitializer: return VarDeclInitializationStyle::LIST_INITIALIZER;
  }
}

VarDeclTLSKind FromPasta(pasta::VarDeclTLSKind e) {
  switch (e) {
    case pasta::VarDeclTLSKind::kNone: return VarDeclTLSKind::NONE;
    case pasta::VarDeclTLSKind::kStatic: return VarDeclTLSKind::STATIC;
    case pasta::VarDeclTLSKind::kDynamic: return VarDeclTLSKind::DYNAMIC;
  }
}

VectorTypeVectorKind FromPasta(pasta::VectorTypeVectorKind e) {
  switch (e) {
    case pasta::VectorTypeVectorKind::kGenericVector: return VectorTypeVectorKind::GENERIC_VECTOR;
    case pasta::VectorTypeVectorKind::kAltiVecVector: return VectorTypeVectorKind::ALTI_VEC_VECTOR;
    case pasta::VectorTypeVectorKind::kAltiVecPixel: return VectorTypeVectorKind::ALTI_VEC_PIXEL;
    case pasta::VectorTypeVectorKind::kAltiVecBoolean: return VectorTypeVectorKind::ALTI_VEC_BOOLEAN;
    case pasta::VectorTypeVectorKind::kNeonVector: return VectorTypeVectorKind::NEON_VECTOR;
    case pasta::VectorTypeVectorKind::kNeonPolyVector: return VectorTypeVectorKind::NEON_POLY_VECTOR;
    case pasta::VectorTypeVectorKind::kSveFixedLengthDataVector: return VectorTypeVectorKind::SVE_FIXED_LENGTH_DATA_VECTOR;
    case pasta::VectorTypeVectorKind::kSveFixedLengthPredicateVector: return VectorTypeVectorKind::SVE_FIXED_LENGTH_PREDICATE_VECTOR;
  }
}

ASTDumpOutputFormat FromPasta(pasta::ASTDumpOutputFormat e) {
  switch (e) {
    case pasta::ASTDumpOutputFormat::kDefault: return ASTDumpOutputFormat::DEFAULT;
    case pasta::ASTDumpOutputFormat::kJSON: return ASTDumpOutputFormat::JSON;
  }
}

AccessSpecifier FromPasta(pasta::AccessSpecifier e) {
  switch (e) {
    case pasta::AccessSpecifier::kPublic: return AccessSpecifier::PUBLIC;
    case pasta::AccessSpecifier::kProtected: return AccessSpecifier::PROTECTED;
    case pasta::AccessSpecifier::kPrivate: return AccessSpecifier::PRIVATE;
    case pasta::AccessSpecifier::kNone: return AccessSpecifier::NONE;
  }
}

AddrSpaceMapMangling FromPasta(pasta::AddrSpaceMapMangling e) {
  switch (e) {
    case pasta::AddrSpaceMapMangling::kTarget: return AddrSpaceMapMangling::TARGET;
    case pasta::AddrSpaceMapMangling::kOn: return AddrSpaceMapMangling::ON;
    case pasta::AddrSpaceMapMangling::kOff: return AddrSpaceMapMangling::OFF;
  }
}

AllocatorTypeTy FromPasta(pasta::AllocatorTypeTy e) {
  switch (e) {
    case pasta::AllocatorTypeTy::kOMPNullMemoryAlloc: return AllocatorTypeTy::OMP_NULL_MEMORY_ALLOC;
    case pasta::AllocatorTypeTy::kOMPDefaultMemoryAlloc: return AllocatorTypeTy::OMP_DEFAULT_MEMORY_ALLOC;
    case pasta::AllocatorTypeTy::kOMPLargeCapMemoryAlloc: return AllocatorTypeTy::OMP_LARGE_CAP_MEMORY_ALLOC;
    case pasta::AllocatorTypeTy::kOMPConstMemoryAlloc: return AllocatorTypeTy::OMP_CONST_MEMORY_ALLOC;
    case pasta::AllocatorTypeTy::kOMPHighBWMemoryAlloc: return AllocatorTypeTy::OMP_HIGH_BW_MEMORY_ALLOC;
    case pasta::AllocatorTypeTy::kOMPLowLatMemoryAlloc: return AllocatorTypeTy::OMP_LOW_LAT_MEMORY_ALLOC;
    case pasta::AllocatorTypeTy::kOMPCGroupMemoryAlloc: return AllocatorTypeTy::OMPC_GROUP_MEMORY_ALLOC;
    case pasta::AllocatorTypeTy::kOMPPTeamMemoryAlloc: return AllocatorTypeTy::OMPP_TEAM_MEMORY_ALLOC;
    case pasta::AllocatorTypeTy::kOMPThreadMemoryAlloc: return AllocatorTypeTy::OMP_THREAD_MEMORY_ALLOC;
    case pasta::AllocatorTypeTy::kOMPUserDefinedMemoryAlloc: return AllocatorTypeTy::OMP_USER_DEFINED_MEMORY_ALLOC;
  }
}

AltivecSrcCompatKind FromPasta(pasta::AltivecSrcCompatKind e) {
  switch (e) {
    case pasta::AltivecSrcCompatKind::kMixed: return AltivecSrcCompatKind::MIXED;
    case pasta::AltivecSrcCompatKind::kGCC: return AltivecSrcCompatKind::GCC;
    case pasta::AltivecSrcCompatKind::kXL: return AltivecSrcCompatKind::XL;
  }
}

ArgumentKind FromPasta(pasta::ArgumentKind e) {
  switch (e) {
    case pasta::ArgumentKind::kStdString: return ArgumentKind::STD_STRING;
    case pasta::ArgumentKind::kCString: return ArgumentKind::C_STRING;
    case pasta::ArgumentKind::kSint: return ArgumentKind::SINT;
    case pasta::ArgumentKind::kUint: return ArgumentKind::UINT;
    case pasta::ArgumentKind::kTokenkind: return ArgumentKind::TOKENKIND;
    case pasta::ArgumentKind::kIdentifierinfo: return ArgumentKind::IDENTIFIERINFO;
    case pasta::ArgumentKind::kAddrspace: return ArgumentKind::ADDRSPACE;
    case pasta::ArgumentKind::kQualified: return ArgumentKind::QUALIFIED;
    case pasta::ArgumentKind::kQualtype: return ArgumentKind::QUALTYPE;
    case pasta::ArgumentKind::kDeclarationname: return ArgumentKind::DECLARATIONNAME;
    case pasta::ArgumentKind::kNameddecl: return ArgumentKind::NAMEDDECL;
    case pasta::ArgumentKind::kNestednamespec: return ArgumentKind::NESTEDNAMESPEC;
    case pasta::ArgumentKind::kDeclcontext: return ArgumentKind::DECLCONTEXT;
    case pasta::ArgumentKind::kQualtypePair: return ArgumentKind::QUALTYPE_PAIR;
    case pasta::ArgumentKind::kAttribute: return ArgumentKind::ATTRIBUTE;
  }
}

ArrayTypeTrait FromPasta(pasta::ArrayTypeTrait e) {
  switch (e) {
    case pasta::ArrayTypeTrait::kArrayRank: return ArrayTypeTrait::ARRAY_RANK;
    case pasta::ArrayTypeTrait::kArrayExtent: return ArrayTypeTrait::ARRAY_EXTENT;
  }
}

AtomicScopeModelKind FromPasta(pasta::AtomicScopeModelKind e) {
  switch (e) {
    case pasta::AtomicScopeModelKind::kNone: return AtomicScopeModelKind::NONE;
    case pasta::AtomicScopeModelKind::kOpenCL: return AtomicScopeModelKind::OPEN_CL;
  }
}

AttributeKind FromPasta(pasta::AttributeKind e) {
  switch (e) {
    case pasta::AttributeKind::kAddressSpace: return AttributeKind::ADDRESS_SPACE;
    case pasta::AttributeKind::kArmMveStrictPolymorphism: return AttributeKind::ARM_MVE_STRICT_POLYMORPHISM;
    case pasta::AttributeKind::kCmseNSCall: return AttributeKind::CMSE_NS_CALL;
    case pasta::AttributeKind::kNoDeref: return AttributeKind::NO_DEREF;
    case pasta::AttributeKind::kObjCGC: return AttributeKind::OBJ_CGC;
    case pasta::AttributeKind::kObjCInertUnsafeUnretained: return AttributeKind::OBJ_C_INERT_UNSAFE_UNRETAINED;
    case pasta::AttributeKind::kObjCKindOf: return AttributeKind::OBJ_C_KIND_OF;
    case pasta::AttributeKind::kOpenCLConstantAddressSpace: return AttributeKind::OPEN_CL_CONSTANT_ADDRESS_SPACE;
    case pasta::AttributeKind::kOpenCLGenericAddressSpace: return AttributeKind::OPEN_CL_GENERIC_ADDRESS_SPACE;
    case pasta::AttributeKind::kOpenCLGlobalAddressSpace: return AttributeKind::OPEN_CL_GLOBAL_ADDRESS_SPACE;
    case pasta::AttributeKind::kOpenCLGlobalDeviceAddressSpace: return AttributeKind::OPEN_CL_GLOBAL_DEVICE_ADDRESS_SPACE;
    case pasta::AttributeKind::kOpenCLGlobalHostAddressSpace: return AttributeKind::OPEN_CL_GLOBAL_HOST_ADDRESS_SPACE;
    case pasta::AttributeKind::kOpenCLLocalAddressSpace: return AttributeKind::OPEN_CL_LOCAL_ADDRESS_SPACE;
    case pasta::AttributeKind::kOpenCLPrivateAddressSpace: return AttributeKind::OPEN_CL_PRIVATE_ADDRESS_SPACE;
    case pasta::AttributeKind::kPtr32: return AttributeKind::PTR32;
    case pasta::AttributeKind::kPtr64: return AttributeKind::PTR64;
    case pasta::AttributeKind::kSPtr: return AttributeKind::S_PTR;
    case pasta::AttributeKind::kTypeNonNull: return AttributeKind::TYPE_NON_NULL;
    case pasta::AttributeKind::kTypeNullUnspecified: return AttributeKind::TYPE_NULL_UNSPECIFIED;
    case pasta::AttributeKind::kTypeNullable: return AttributeKind::TYPE_NULLABLE;
    case pasta::AttributeKind::kTypeNullableResult: return AttributeKind::TYPE_NULLABLE_RESULT;
    case pasta::AttributeKind::kUPtr: return AttributeKind::U_PTR;
    case pasta::AttributeKind::kFallThrough: return AttributeKind::FALL_THROUGH;
    case pasta::AttributeKind::kLikely: return AttributeKind::LIKELY;
    case pasta::AttributeKind::kMustTail: return AttributeKind::MUST_TAIL;
    case pasta::AttributeKind::kOpenCLUnrollHint: return AttributeKind::OPEN_CL_UNROLL_HINT;
    case pasta::AttributeKind::kSuppress: return AttributeKind::SUPPRESS;
    case pasta::AttributeKind::kUnlikely: return AttributeKind::UNLIKELY;
    case pasta::AttributeKind::kNoMerge: return AttributeKind::NO_MERGE;
    case pasta::AttributeKind::kAArch64VectorPcs: return AttributeKind::A_ARCH64_VECTOR_PCS;
    case pasta::AttributeKind::kAcquireHandle: return AttributeKind::ACQUIRE_HANDLE;
    case pasta::AttributeKind::kAnyX86NoCfCheck: return AttributeKind::ANY_X86_NO_CF_CHECK;
    case pasta::AttributeKind::kCDecl: return AttributeKind::C_DECL;
    case pasta::AttributeKind::kFastCall: return AttributeKind::FAST_CALL;
    case pasta::AttributeKind::kIntelOclBicc: return AttributeKind::INTEL_OCL_BICC;
    case pasta::AttributeKind::kLifetimeBound: return AttributeKind::LIFETIME_BOUND;
    case pasta::AttributeKind::kMSABI: return AttributeKind::MSABI;
    case pasta::AttributeKind::kNSReturnsRetained: return AttributeKind::NS_RETURNS_RETAINED;
    case pasta::AttributeKind::kObjCOwnership: return AttributeKind::OBJ_C_OWNERSHIP;
    case pasta::AttributeKind::kPascal: return AttributeKind::PASCAL;
    case pasta::AttributeKind::kPcs: return AttributeKind::PCS;
    case pasta::AttributeKind::kPreserveAll: return AttributeKind::PRESERVE_ALL;
    case pasta::AttributeKind::kPreserveMost: return AttributeKind::PRESERVE_MOST;
    case pasta::AttributeKind::kRegCall: return AttributeKind::REG_CALL;
    case pasta::AttributeKind::kStdCall: return AttributeKind::STD_CALL;
    case pasta::AttributeKind::kSwiftAsyncCall: return AttributeKind::SWIFT_ASYNC_CALL;
    case pasta::AttributeKind::kSwiftCall: return AttributeKind::SWIFT_CALL;
    case pasta::AttributeKind::kSysVABI: return AttributeKind::SYS_VABI;
    case pasta::AttributeKind::kThisCall: return AttributeKind::THIS_CALL;
    case pasta::AttributeKind::kVectorCall: return AttributeKind::VECTOR_CALL;
    case pasta::AttributeKind::kSwiftAsyncContext: return AttributeKind::SWIFT_ASYNC_CONTEXT;
    case pasta::AttributeKind::kSwiftContext: return AttributeKind::SWIFT_CONTEXT;
    case pasta::AttributeKind::kSwiftErrorResult: return AttributeKind::SWIFT_ERROR_RESULT;
    case pasta::AttributeKind::kSwiftIndirectResult: return AttributeKind::SWIFT_INDIRECT_RESULT;
    case pasta::AttributeKind::kAnnotate: return AttributeKind::ANNOTATE;
    case pasta::AttributeKind::kCFConsumed: return AttributeKind::CF_CONSUMED;
    case pasta::AttributeKind::kCarriesDependency: return AttributeKind::CARRIES_DEPENDENCY;
    case pasta::AttributeKind::kNSConsumed: return AttributeKind::NS_CONSUMED;
    case pasta::AttributeKind::kNonNull: return AttributeKind::NON_NULL;
    case pasta::AttributeKind::kOSConsumed: return AttributeKind::OS_CONSUMED;
    case pasta::AttributeKind::kPassObjectSize: return AttributeKind::PASS_OBJECT_SIZE;
    case pasta::AttributeKind::kReleaseHandle: return AttributeKind::RELEASE_HANDLE;
    case pasta::AttributeKind::kUseHandle: return AttributeKind::USE_HANDLE;
    case pasta::AttributeKind::kAMDGPUFlatWorkGroupSize: return AttributeKind::AMDGPU_FLAT_WORK_GROUP_SIZE;
    case pasta::AttributeKind::kAMDGPUNumSGPR: return AttributeKind::AMDGPU_NUM_SGPR;
    case pasta::AttributeKind::kAMDGPUNumVGPR: return AttributeKind::AMDGPU_NUM_VGPR;
    case pasta::AttributeKind::kAMDGPUWavesPerEU: return AttributeKind::AMDGPU_WAVES_PER_EU;
    case pasta::AttributeKind::kARMInterrupt: return AttributeKind::ARM_INTERRUPT;
    case pasta::AttributeKind::kAVRInterrupt: return AttributeKind::AVR_INTERRUPT;
    case pasta::AttributeKind::kAVRSignal: return AttributeKind::AVR_SIGNAL;
    case pasta::AttributeKind::kAcquireCapability: return AttributeKind::ACQUIRE_CAPABILITY;
    case pasta::AttributeKind::kAcquiredAfter: return AttributeKind::ACQUIRED_AFTER;
    case pasta::AttributeKind::kAcquiredBefore: return AttributeKind::ACQUIRED_BEFORE;
    case pasta::AttributeKind::kAlignMac68k: return AttributeKind::ALIGN_MAC68_K;
    case pasta::AttributeKind::kAlignNatural: return AttributeKind::ALIGN_NATURAL;
    case pasta::AttributeKind::kAligned: return AttributeKind::ALIGNED;
    case pasta::AttributeKind::kAllocAlign: return AttributeKind::ALLOC_ALIGN;
    case pasta::AttributeKind::kAllocSize: return AttributeKind::ALLOC_SIZE;
    case pasta::AttributeKind::kAlwaysDestroy: return AttributeKind::ALWAYS_DESTROY;
    case pasta::AttributeKind::kAlwaysInline: return AttributeKind::ALWAYS_INLINE;
    case pasta::AttributeKind::kAnalyzerNoReturn: return AttributeKind::ANALYZER_NO_RETURN;
    case pasta::AttributeKind::kAnyX86Interrupt: return AttributeKind::ANY_X86_INTERRUPT;
    case pasta::AttributeKind::kAnyX86NoCallerSavedRegisters: return AttributeKind::ANY_X86_NO_CALLER_SAVED_REGISTERS;
    case pasta::AttributeKind::kArcWeakrefUnavailable: return AttributeKind::ARC_WEAKREF_UNAVAILABLE;
    case pasta::AttributeKind::kArgumentWithTypeTag: return AttributeKind::ARGUMENT_WITH_TYPE_TAG;
    case pasta::AttributeKind::kArmBuiltinAlias: return AttributeKind::ARM_BUILTIN_ALIAS;
    case pasta::AttributeKind::kArtificial: return AttributeKind::ARTIFICIAL;
    case pasta::AttributeKind::kAssemblyLabel: return AttributeKind::ASSEMBLY_LABEL;
    case pasta::AttributeKind::kAssertCapability: return AttributeKind::ASSERT_CAPABILITY;
    case pasta::AttributeKind::kAssertExclusiveLock: return AttributeKind::ASSERT_EXCLUSIVE_LOCK;
    case pasta::AttributeKind::kAssertSharedLock: return AttributeKind::ASSERT_SHARED_LOCK;
    case pasta::AttributeKind::kAssumeAligned: return AttributeKind::ASSUME_ALIGNED;
    case pasta::AttributeKind::kAssumption: return AttributeKind::ASSUMPTION;
    case pasta::AttributeKind::kAvailability: return AttributeKind::AVAILABILITY;
    case pasta::AttributeKind::kBPFPreserveAccessIndex: return AttributeKind::BPF_PRESERVE_ACCESS_INDEX;
    case pasta::AttributeKind::kBlocks: return AttributeKind::BLOCKS;
    case pasta::AttributeKind::kBuiltin: return AttributeKind::BUILTIN;
    case pasta::AttributeKind::kC11NoReturn: return AttributeKind::C11_NO_RETURN;
    case pasta::AttributeKind::kCFAuditedTransfer: return AttributeKind::CF_AUDITED_TRANSFER;
    case pasta::AttributeKind::kCFGuard: return AttributeKind::CF_GUARD;
    case pasta::AttributeKind::kCFICanonicalJumpTable: return AttributeKind::CFI_CANONICAL_JUMP_TABLE;
    case pasta::AttributeKind::kCFReturnsNotRetained: return AttributeKind::CF_RETURNS_NOT_RETAINED;
    case pasta::AttributeKind::kCFReturnsRetained: return AttributeKind::CF_RETURNS_RETAINED;
    case pasta::AttributeKind::kCFUnknownTransfer: return AttributeKind::CF_UNKNOWN_TRANSFER;
    case pasta::AttributeKind::kCPUDispatch: return AttributeKind::CPU_DISPATCH;
    case pasta::AttributeKind::kCPUSpecific: return AttributeKind::CPU_SPECIFIC;
    case pasta::AttributeKind::kCUDAConstant: return AttributeKind::CUDA_CONSTANT;
    case pasta::AttributeKind::kCUDADevice: return AttributeKind::CUDA_DEVICE;
    case pasta::AttributeKind::kCUDADeviceBuiltinSurfaceType: return AttributeKind::CUDA_DEVICE_BUILTIN_SURFACE_TYPE;
    case pasta::AttributeKind::kCUDADeviceBuiltinTextureType: return AttributeKind::CUDA_DEVICE_BUILTIN_TEXTURE_TYPE;
    case pasta::AttributeKind::kCUDAGlobal: return AttributeKind::CUDA_GLOBAL;
    case pasta::AttributeKind::kCUDAHost: return AttributeKind::CUDA_HOST;
    case pasta::AttributeKind::kCUDAInvalidTarget: return AttributeKind::CUDA_INVALID_TARGET;
    case pasta::AttributeKind::kCUDALaunchBounds: return AttributeKind::CUDA_LAUNCH_BOUNDS;
    case pasta::AttributeKind::kCUDAShared: return AttributeKind::CUDA_SHARED;
    case pasta::AttributeKind::kCXX11NoReturn: return AttributeKind::CX_X11_NO_RETURN;
    case pasta::AttributeKind::kCallableWhen: return AttributeKind::CALLABLE_WHEN;
    case pasta::AttributeKind::kCallback: return AttributeKind::CALLBACK;
    case pasta::AttributeKind::kCapability: return AttributeKind::CAPABILITY;
    case pasta::AttributeKind::kCapturedRecord: return AttributeKind::CAPTURED_RECORD;
    case pasta::AttributeKind::kCleanup: return AttributeKind::CLEANUP;
    case pasta::AttributeKind::kCmseNSEntry: return AttributeKind::CMSE_NS_ENTRY;
    case pasta::AttributeKind::kCodeSeg: return AttributeKind::CODE_SEG;
    case pasta::AttributeKind::kCold: return AttributeKind::COLD;
    case pasta::AttributeKind::kCommon: return AttributeKind::COMMON;
    case pasta::AttributeKind::kConst: return AttributeKind::CONST;
    case pasta::AttributeKind::kConstInitializer: return AttributeKind::CONST_INITIALIZER;
    case pasta::AttributeKind::kConstructor: return AttributeKind::CONSTRUCTOR;
    case pasta::AttributeKind::kConsumable: return AttributeKind::CONSUMABLE;
    case pasta::AttributeKind::kConsumableAutoCast: return AttributeKind::CONSUMABLE_AUTO_CAST;
    case pasta::AttributeKind::kConsumableSetOnRead: return AttributeKind::CONSUMABLE_SET_ON_READ;
    case pasta::AttributeKind::kConvergent: return AttributeKind::CONVERGENT;
    case pasta::AttributeKind::kDLLExport: return AttributeKind::DLL_EXPORT;
    case pasta::AttributeKind::kDLLExportStaticLocal: return AttributeKind::DLL_EXPORT_STATIC_LOCAL;
    case pasta::AttributeKind::kDLLImport: return AttributeKind::DLL_IMPORT;
    case pasta::AttributeKind::kDLLImportStaticLocal: return AttributeKind::DLL_IMPORT_STATIC_LOCAL;
    case pasta::AttributeKind::kDeprecated: return AttributeKind::DEPRECATED;
    case pasta::AttributeKind::kDestructor: return AttributeKind::DESTRUCTOR;
    case pasta::AttributeKind::kDiagnoseIf: return AttributeKind::DIAGNOSE_IF;
    case pasta::AttributeKind::kDisableTailCalls: return AttributeKind::DISABLE_TAIL_CALLS;
    case pasta::AttributeKind::kEmptyBases: return AttributeKind::EMPTY_BASES;
    case pasta::AttributeKind::kEnableIf: return AttributeKind::ENABLE_IF;
    case pasta::AttributeKind::kEnforceTCB: return AttributeKind::ENFORCE_TCB;
    case pasta::AttributeKind::kEnforceTCBLeaf: return AttributeKind::ENFORCE_TCB_LEAF;
    case pasta::AttributeKind::kEnumExtensibility: return AttributeKind::ENUM_EXTENSIBILITY;
    case pasta::AttributeKind::kExcludeFromExplicitInstantiation: return AttributeKind::EXCLUDE_FROM_EXPLICIT_INSTANTIATION;
    case pasta::AttributeKind::kExclusiveTrylockFunction: return AttributeKind::EXCLUSIVE_TRYLOCK_FUNCTION;
    case pasta::AttributeKind::kExternalSourceSymbol: return AttributeKind::EXTERNAL_SOURCE_SYMBOL;
    case pasta::AttributeKind::kFinal: return AttributeKind::FINAL;
    case pasta::AttributeKind::kFlagEnum: return AttributeKind::FLAG_ENUM;
    case pasta::AttributeKind::kFlatten: return AttributeKind::FLATTEN;
    case pasta::AttributeKind::kFormat: return AttributeKind::FORMAT;
    case pasta::AttributeKind::kFormatArgument: return AttributeKind::FORMAT_ARGUMENT;
    case pasta::AttributeKind::kGNUInline: return AttributeKind::GNU_INLINE;
    case pasta::AttributeKind::kGuardedBy: return AttributeKind::GUARDED_BY;
    case pasta::AttributeKind::kGuardedVariable: return AttributeKind::GUARDED_VARIABLE;
    case pasta::AttributeKind::kHIPManaged: return AttributeKind::HIP_MANAGED;
    case pasta::AttributeKind::kHot: return AttributeKind::HOT;
    case pasta::AttributeKind::kIBAction: return AttributeKind::IB_ACTION;
    case pasta::AttributeKind::kIBOutlet: return AttributeKind::IB_OUTLET;
    case pasta::AttributeKind::kIBOutletCollection: return AttributeKind::IB_OUTLET_COLLECTION;
    case pasta::AttributeKind::kInitializerPriority: return AttributeKind::INITIALIZER_PRIORITY;
    case pasta::AttributeKind::kInternalLinkage: return AttributeKind::INTERNAL_LINKAGE;
    case pasta::AttributeKind::kLTOVisibilityPublic: return AttributeKind::LTO_VISIBILITY_PUBLIC;
    case pasta::AttributeKind::kLayoutVersion: return AttributeKind::LAYOUT_VERSION;
    case pasta::AttributeKind::kLeaf: return AttributeKind::LEAF;
    case pasta::AttributeKind::kLockReturned: return AttributeKind::LOCK_RETURNED;
    case pasta::AttributeKind::kLocksExcluded: return AttributeKind::LOCKS_EXCLUDED;
    case pasta::AttributeKind::kM68kInterrupt: return AttributeKind::M68_KINTERRUPT;
    case pasta::AttributeKind::kMIGServerRoutine: return AttributeKind::MIG_SERVER_ROUTINE;
    case pasta::AttributeKind::kMSAllocator: return AttributeKind::MS_ALLOCATOR;
    case pasta::AttributeKind::kMSInheritance: return AttributeKind::MS_INHERITANCE;
    case pasta::AttributeKind::kMSNoVTable: return AttributeKind::MS_NO_V_TABLE;
    case pasta::AttributeKind::kMSP430Interrupt: return AttributeKind::MS_P430_INTERRUPT;
    case pasta::AttributeKind::kMSStruct: return AttributeKind::MS_STRUCT;
    case pasta::AttributeKind::kMSVtorDisp: return AttributeKind::MS_VTOR_DISP;
    case pasta::AttributeKind::kMaxFieldAlignment: return AttributeKind::MAX_FIELD_ALIGNMENT;
    case pasta::AttributeKind::kMayAlias: return AttributeKind::MAY_ALIAS;
    case pasta::AttributeKind::kMicroMips: return AttributeKind::MICRO_MIPS;
    case pasta::AttributeKind::kMinSize: return AttributeKind::MIN_SIZE;
    case pasta::AttributeKind::kMinVectorWidth: return AttributeKind::MIN_VECTOR_WIDTH;
    case pasta::AttributeKind::kMips16: return AttributeKind::MIPS16;
    case pasta::AttributeKind::kMipsInterrupt: return AttributeKind::MIPS_INTERRUPT;
    case pasta::AttributeKind::kMipsLongCall: return AttributeKind::MIPS_LONG_CALL;
    case pasta::AttributeKind::kMipsShortCall: return AttributeKind::MIPS_SHORT_CALL;
    case pasta::AttributeKind::kNSConsumesSelf: return AttributeKind::NS_CONSUMES_SELF;
    case pasta::AttributeKind::kNSErrorDomain: return AttributeKind::NS_ERROR_DOMAIN;
    case pasta::AttributeKind::kNSReturnsAutoreleased: return AttributeKind::NS_RETURNS_AUTORELEASED;
    case pasta::AttributeKind::kNSReturnsNotRetained: return AttributeKind::NS_RETURNS_NOT_RETAINED;
    case pasta::AttributeKind::kNaked: return AttributeKind::NAKED;
    case pasta::AttributeKind::kNoAlias: return AttributeKind::NO_ALIAS;
    case pasta::AttributeKind::kNoCommon: return AttributeKind::NO_COMMON;
    case pasta::AttributeKind::kNoDebug: return AttributeKind::NO_DEBUG;
    case pasta::AttributeKind::kNoDestroy: return AttributeKind::NO_DESTROY;
    case pasta::AttributeKind::kNoDuplicate: return AttributeKind::NO_DUPLICATE;
    case pasta::AttributeKind::kNoInline: return AttributeKind::NO_INLINE;
    case pasta::AttributeKind::kNoInstrumentFunction: return AttributeKind::NO_INSTRUMENT_FUNCTION;
    case pasta::AttributeKind::kNoMicroMips: return AttributeKind::NO_MICRO_MIPS;
    case pasta::AttributeKind::kNoMips16: return AttributeKind::NO_MIPS16;
    case pasta::AttributeKind::kNoProfileFunction: return AttributeKind::NO_PROFILE_FUNCTION;
    case pasta::AttributeKind::kNoReturn: return AttributeKind::NO_RETURN;
    case pasta::AttributeKind::kNoSanitize: return AttributeKind::NO_SANITIZE;
    case pasta::AttributeKind::kNoSpeculativeLoadHardening: return AttributeKind::NO_SPECULATIVE_LOAD_HARDENING;
    case pasta::AttributeKind::kNoSplitStack: return AttributeKind::NO_SPLIT_STACK;
    case pasta::AttributeKind::kNoStackProtector: return AttributeKind::NO_STACK_PROTECTOR;
    case pasta::AttributeKind::kNoThreadSafetyAnalysis: return AttributeKind::NO_THREAD_SAFETY_ANALYSIS;
    case pasta::AttributeKind::kNoThrow: return AttributeKind::NO_THROW;
    case pasta::AttributeKind::kNoUniqueAddress: return AttributeKind::NO_UNIQUE_ADDRESS;
    case pasta::AttributeKind::kNotTailCalled: return AttributeKind::NOT_TAIL_CALLED;
    case pasta::AttributeKind::kOMPAllocateDeclaration: return AttributeKind::OMP_ALLOCATE_DECLARATION;
    case pasta::AttributeKind::kOMPCaptureNoInitializer: return AttributeKind::OMP_CAPTURE_NO_INITIALIZER;
    case pasta::AttributeKind::kOMPDeclareTargetDeclaration: return AttributeKind::OMP_DECLARE_TARGET_DECLARATION;
    case pasta::AttributeKind::kOMPDeclareVariant: return AttributeKind::OMP_DECLARE_VARIANT;
    case pasta::AttributeKind::kOMPThreadPrivateDeclaration: return AttributeKind::OMP_THREAD_PRIVATE_DECLARATION;
    case pasta::AttributeKind::kOSConsumesThis: return AttributeKind::OS_CONSUMES_THIS;
    case pasta::AttributeKind::kOSReturnsNotRetained: return AttributeKind::OS_RETURNS_NOT_RETAINED;
    case pasta::AttributeKind::kOSReturnsRetained: return AttributeKind::OS_RETURNS_RETAINED;
    case pasta::AttributeKind::kOSReturnsRetainedOnNonZero: return AttributeKind::OS_RETURNS_RETAINED_ON_NON_ZERO;
    case pasta::AttributeKind::kOSReturnsRetainedOnZero: return AttributeKind::OS_RETURNS_RETAINED_ON_ZERO;
    case pasta::AttributeKind::kObjCBridge: return AttributeKind::OBJ_C_BRIDGE;
    case pasta::AttributeKind::kObjCBridgeMutable: return AttributeKind::OBJ_C_BRIDGE_MUTABLE;
    case pasta::AttributeKind::kObjCBridgeRelated: return AttributeKind::OBJ_C_BRIDGE_RELATED;
    case pasta::AttributeKind::kObjCException: return AttributeKind::OBJ_C_EXCEPTION;
    case pasta::AttributeKind::kObjCExplicitProtocolImplementation: return AttributeKind::OBJ_C_EXPLICIT_PROTOCOL_IMPLEMENTATION;
    case pasta::AttributeKind::kObjCExternallyRetained: return AttributeKind::OBJ_C_EXTERNALLY_RETAINED;
    case pasta::AttributeKind::kObjCIndependentClass: return AttributeKind::OBJ_C_INDEPENDENT_CLASS;
    case pasta::AttributeKind::kObjCMethodFamily: return AttributeKind::OBJ_C_METHOD_FAMILY;
    case pasta::AttributeKind::kObjCNSObject: return AttributeKind::OBJ_CNS_OBJECT;
    case pasta::AttributeKind::kObjCPreciseLifetime: return AttributeKind::OBJ_C_PRECISE_LIFETIME;
    case pasta::AttributeKind::kObjCRequiresPropertyDefinitions: return AttributeKind::OBJ_C_REQUIRES_PROPERTY_DEFINITIONS;
    case pasta::AttributeKind::kObjCRequiresSuper: return AttributeKind::OBJ_C_REQUIRES_SUPER;
    case pasta::AttributeKind::kObjCReturnsInnerPointer: return AttributeKind::OBJ_C_RETURNS_INNER_POINTER;
    case pasta::AttributeKind::kObjCRootClass: return AttributeKind::OBJ_C_ROOT_CLASS;
    case pasta::AttributeKind::kObjCSubclassingRestricted: return AttributeKind::OBJ_C_SUBCLASSING_RESTRICTED;
    case pasta::AttributeKind::kOpenCLIntelReqdSubGroupSize: return AttributeKind::OPEN_CL_INTEL_REQD_SUB_GROUP_SIZE;
    case pasta::AttributeKind::kOpenCLKernel: return AttributeKind::OPEN_CL_KERNEL;
    case pasta::AttributeKind::kOptimizeNone: return AttributeKind::OPTIMIZE_NONE;
    case pasta::AttributeKind::kOverride: return AttributeKind::OVERRIDE;
    case pasta::AttributeKind::kOwner: return AttributeKind::OWNER;
    case pasta::AttributeKind::kOwnership: return AttributeKind::OWNERSHIP;
    case pasta::AttributeKind::kPacked: return AttributeKind::PACKED;
    case pasta::AttributeKind::kParamTypestate: return AttributeKind::PARAM_TYPESTATE;
    case pasta::AttributeKind::kPatchableFunctionEntry: return AttributeKind::PATCHABLE_FUNCTION_ENTRY;
    case pasta::AttributeKind::kPointer: return AttributeKind::POINTER;
    case pasta::AttributeKind::kPragmaClangBSSSection: return AttributeKind::PRAGMA_CLANG_BSS_SECTION;
    case pasta::AttributeKind::kPragmaClangDataSection: return AttributeKind::PRAGMA_CLANG_DATA_SECTION;
    case pasta::AttributeKind::kPragmaClangRelroSection: return AttributeKind::PRAGMA_CLANG_RELRO_SECTION;
    case pasta::AttributeKind::kPragmaClangRodataSection: return AttributeKind::PRAGMA_CLANG_RODATA_SECTION;
    case pasta::AttributeKind::kPragmaClangTextSection: return AttributeKind::PRAGMA_CLANG_TEXT_SECTION;
    case pasta::AttributeKind::kPreferredName: return AttributeKind::PREFERRED_NAME;
    case pasta::AttributeKind::kPtGuardedBy: return AttributeKind::PT_GUARDED_BY;
    case pasta::AttributeKind::kPtGuardedVariable: return AttributeKind::PT_GUARDED_VARIABLE;
    case pasta::AttributeKind::kPure: return AttributeKind::PURE;
    case pasta::AttributeKind::kRISCVInterrupt: return AttributeKind::RISCV_INTERRUPT;
    case pasta::AttributeKind::kReinitializes: return AttributeKind::REINITIALIZES;
    case pasta::AttributeKind::kReleaseCapability: return AttributeKind::RELEASE_CAPABILITY;
    case pasta::AttributeKind::kReqdWorkGroupSize: return AttributeKind::REQD_WORK_GROUP_SIZE;
    case pasta::AttributeKind::kRequiresCapability: return AttributeKind::REQUIRES_CAPABILITY;
    case pasta::AttributeKind::kRestrict: return AttributeKind::RESTRICT;
    case pasta::AttributeKind::kRetain: return AttributeKind::RETAIN;
    case pasta::AttributeKind::kReturnTypestate: return AttributeKind::RETURN_TYPESTATE;
    case pasta::AttributeKind::kReturnsNonNull: return AttributeKind::RETURNS_NON_NULL;
    case pasta::AttributeKind::kReturnsTwice: return AttributeKind::RETURNS_TWICE;
    case pasta::AttributeKind::kSYCLKernel: return AttributeKind::SYCL_KERNEL;
    case pasta::AttributeKind::kScopedLockable: return AttributeKind::SCOPED_LOCKABLE;
    case pasta::AttributeKind::kSection: return AttributeKind::SECTION;
    case pasta::AttributeKind::kSelectAny: return AttributeKind::SELECT_ANY;
    case pasta::AttributeKind::kSentinel: return AttributeKind::SENTINEL;
    case pasta::AttributeKind::kSetTypestate: return AttributeKind::SET_TYPESTATE;
    case pasta::AttributeKind::kSharedTrylockFunction: return AttributeKind::SHARED_TRYLOCK_FUNCTION;
    case pasta::AttributeKind::kSpeculativeLoadHardening: return AttributeKind::SPECULATIVE_LOAD_HARDENING;
    case pasta::AttributeKind::kStandaloneDebug: return AttributeKind::STANDALONE_DEBUG;
    case pasta::AttributeKind::kStrictFP: return AttributeKind::STRICT_FP;
    case pasta::AttributeKind::kSwiftAsync: return AttributeKind::SWIFT_ASYNC;
    case pasta::AttributeKind::kSwiftAsyncError: return AttributeKind::SWIFT_ASYNC_ERROR;
    case pasta::AttributeKind::kSwiftAsyncName: return AttributeKind::SWIFT_ASYNC_NAME;
    case pasta::AttributeKind::kSwiftAttribute: return AttributeKind::SWIFT_ATTRIBUTE;
    case pasta::AttributeKind::kSwiftBridge: return AttributeKind::SWIFT_BRIDGE;
    case pasta::AttributeKind::kSwiftBridgedTypedef: return AttributeKind::SWIFT_BRIDGED_TYPEDEF;
    case pasta::AttributeKind::kSwiftError: return AttributeKind::SWIFT_ERROR;
    case pasta::AttributeKind::kSwiftName: return AttributeKind::SWIFT_NAME;
    case pasta::AttributeKind::kSwiftNewType: return AttributeKind::SWIFT_NEW_TYPE;
    case pasta::AttributeKind::kSwiftPrivate: return AttributeKind::SWIFT_PRIVATE;
    case pasta::AttributeKind::kTLSModel: return AttributeKind::TLS_MODEL;
    case pasta::AttributeKind::kTarget: return AttributeKind::TARGET;
    case pasta::AttributeKind::kTestTypestate: return AttributeKind::TEST_TYPESTATE;
    case pasta::AttributeKind::kTransparentUnion: return AttributeKind::TRANSPARENT_UNION;
    case pasta::AttributeKind::kTrivialABI: return AttributeKind::TRIVIAL_ABI;
    case pasta::AttributeKind::kTryAcquireCapability: return AttributeKind::TRY_ACQUIRE_CAPABILITY;
    case pasta::AttributeKind::kTypeTagForDatatype: return AttributeKind::TYPE_TAG_FOR_DATATYPE;
    case pasta::AttributeKind::kTypeVisibility: return AttributeKind::TYPE_VISIBILITY;
    case pasta::AttributeKind::kUnavailable: return AttributeKind::UNAVAILABLE;
    case pasta::AttributeKind::kUninitialized: return AttributeKind::UNINITIALIZED;
    case pasta::AttributeKind::kUnused: return AttributeKind::UNUSED;
    case pasta::AttributeKind::kUsed: return AttributeKind::USED;
    case pasta::AttributeKind::kUsingIfExists: return AttributeKind::USING_IF_EXISTS;
    case pasta::AttributeKind::kUuid: return AttributeKind::UUID;
    case pasta::AttributeKind::kVecReturn: return AttributeKind::VEC_RETURN;
    case pasta::AttributeKind::kVecTypeHint: return AttributeKind::VEC_TYPE_HINT;
    case pasta::AttributeKind::kVisibility: return AttributeKind::VISIBILITY;
    case pasta::AttributeKind::kWarnUnused: return AttributeKind::WARN_UNUSED;
    case pasta::AttributeKind::kWarnUnusedResult: return AttributeKind::WARN_UNUSED_RESULT;
    case pasta::AttributeKind::kWeak: return AttributeKind::WEAK;
    case pasta::AttributeKind::kWeakImport: return AttributeKind::WEAK_IMPORT;
    case pasta::AttributeKind::kWeakReference: return AttributeKind::WEAK_REFERENCE;
    case pasta::AttributeKind::kWebAssemblyExportName: return AttributeKind::WEB_ASSEMBLY_EXPORT_NAME;
    case pasta::AttributeKind::kWebAssemblyImportModule: return AttributeKind::WEB_ASSEMBLY_IMPORT_MODULE;
    case pasta::AttributeKind::kWebAssemblyImportName: return AttributeKind::WEB_ASSEMBLY_IMPORT_NAME;
    case pasta::AttributeKind::kWorkGroupSizeHint: return AttributeKind::WORK_GROUP_SIZE_HINT;
    case pasta::AttributeKind::kX86ForceAlignArgumentPointer: return AttributeKind::X86_FORCE_ALIGN_ARGUMENT_POINTER;
    case pasta::AttributeKind::kXRayInstrument: return AttributeKind::X_RAY_INSTRUMENT;
    case pasta::AttributeKind::kXRayLogArguments: return AttributeKind::X_RAY_LOG_ARGUMENTS;
    case pasta::AttributeKind::kAbiTag: return AttributeKind::ABI_TAG;
    case pasta::AttributeKind::kAlias: return AttributeKind::ALIAS;
    case pasta::AttributeKind::kAlignValue: return AttributeKind::ALIGN_VALUE;
    case pasta::AttributeKind::kBuiltinAlias: return AttributeKind::BUILTIN_ALIAS;
    case pasta::AttributeKind::kCalledOnce: return AttributeKind::CALLED_ONCE;
    case pasta::AttributeKind::kIFunc: return AttributeKind::I_FUNC;
    case pasta::AttributeKind::kInitializerSeg: return AttributeKind::INITIALIZER_SEG;
    case pasta::AttributeKind::kLoaderUninitialized: return AttributeKind::LOADER_UNINITIALIZED;
    case pasta::AttributeKind::kLoopHint: return AttributeKind::LOOP_HINT;
    case pasta::AttributeKind::kMode: return AttributeKind::MODE;
    case pasta::AttributeKind::kNoBuiltin: return AttributeKind::NO_BUILTIN;
    case pasta::AttributeKind::kNoEscape: return AttributeKind::NO_ESCAPE;
    case pasta::AttributeKind::kOMPCaptureKind: return AttributeKind::OMP_CAPTURE_KIND;
    case pasta::AttributeKind::kOMPDeclareSimdDeclaration: return AttributeKind::OMP_DECLARE_SIMD_DECLARATION;
    case pasta::AttributeKind::kOMPReferencedVariable: return AttributeKind::OMP_REFERENCED_VARIABLE;
    case pasta::AttributeKind::kObjCBoxable: return AttributeKind::OBJ_C_BOXABLE;
    case pasta::AttributeKind::kObjCClassStub: return AttributeKind::OBJ_C_CLASS_STUB;
    case pasta::AttributeKind::kObjCDesignatedInitializer: return AttributeKind::OBJ_C_DESIGNATED_INITIALIZER;
    case pasta::AttributeKind::kObjCDirect: return AttributeKind::OBJ_C_DIRECT;
    case pasta::AttributeKind::kObjCDirectMembers: return AttributeKind::OBJ_C_DIRECT_MEMBERS;
    case pasta::AttributeKind::kObjCNonLazyClass: return AttributeKind::OBJ_C_NON_LAZY_CLASS;
    case pasta::AttributeKind::kObjCNonRuntimeProtocol: return AttributeKind::OBJ_C_NON_RUNTIME_PROTOCOL;
    case pasta::AttributeKind::kObjCRuntimeName: return AttributeKind::OBJ_C_RUNTIME_NAME;
    case pasta::AttributeKind::kObjCRuntimeVisible: return AttributeKind::OBJ_C_RUNTIME_VISIBLE;
    case pasta::AttributeKind::kOpenCLAccess: return AttributeKind::OPEN_CL_ACCESS;
    case pasta::AttributeKind::kOverloadable: return AttributeKind::OVERLOADABLE;
    case pasta::AttributeKind::kRenderScriptKernel: return AttributeKind::RENDER_SCRIPT_KERNEL;
    case pasta::AttributeKind::kSwiftObjCMembers: return AttributeKind::SWIFT_OBJ_C_MEMBERS;
    case pasta::AttributeKind::kThread: return AttributeKind::THREAD;
  }
}

AutoTypeKeyword FromPasta(pasta::AutoTypeKeyword e) {
  switch (e) {
    case pasta::AutoTypeKeyword::kAuto: return AutoTypeKeyword::AUTO;
    case pasta::AutoTypeKeyword::kDecltypeAuto: return AutoTypeKeyword::DECLTYPE_AUTO;
    case pasta::AutoTypeKeyword::kGNUAutoType: return AutoTypeKeyword::GNU_AUTO_TYPE;
  }
}

AvailabilityResult FromPasta(pasta::AvailabilityResult e) {
  switch (e) {
    case pasta::AvailabilityResult::kAvailable: return AvailabilityResult::AVAILABLE;
    case pasta::AvailabilityResult::kNotYetIntroduced: return AvailabilityResult::NOT_YET_INTRODUCED;
    case pasta::AvailabilityResult::kDeprecated: return AvailabilityResult::DEPRECATED;
    case pasta::AvailabilityResult::kUnavailable: return AvailabilityResult::UNAVAILABLE;
  }
}

BinaryOperatorKind FromPasta(pasta::BinaryOperatorKind e) {
  switch (e) {
    case pasta::BinaryOperatorKind::kPointerMemoryD: return BinaryOperatorKind::POINTER_MEMORY_D;
    case pasta::BinaryOperatorKind::kPointerMemoryI: return BinaryOperatorKind::POINTER_MEMORY_I;
    case pasta::BinaryOperatorKind::kMul: return BinaryOperatorKind::MUL;
    case pasta::BinaryOperatorKind::kDiv: return BinaryOperatorKind::DIV;
    case pasta::BinaryOperatorKind::kRem: return BinaryOperatorKind::REM;
    case pasta::BinaryOperatorKind::kAdd: return BinaryOperatorKind::ADD;
    case pasta::BinaryOperatorKind::kSub: return BinaryOperatorKind::SUB;
    case pasta::BinaryOperatorKind::kShl: return BinaryOperatorKind::SHL;
    case pasta::BinaryOperatorKind::kShr: return BinaryOperatorKind::SHR;
    case pasta::BinaryOperatorKind::kCmp: return BinaryOperatorKind::CMP;
    case pasta::BinaryOperatorKind::kLT: return BinaryOperatorKind::LT;
    case pasta::BinaryOperatorKind::kGT: return BinaryOperatorKind::GT;
    case pasta::BinaryOperatorKind::kLE: return BinaryOperatorKind::LE;
    case pasta::BinaryOperatorKind::kGE: return BinaryOperatorKind::GE;
    case pasta::BinaryOperatorKind::kEQ: return BinaryOperatorKind::EQ;
    case pasta::BinaryOperatorKind::kNE: return BinaryOperatorKind::NE;
    case pasta::BinaryOperatorKind::kAnd: return BinaryOperatorKind::AND;
    case pasta::BinaryOperatorKind::kXor: return BinaryOperatorKind::XOR;
    case pasta::BinaryOperatorKind::kOr: return BinaryOperatorKind::OR;
    case pasta::BinaryOperatorKind::kLAnd: return BinaryOperatorKind::L_AND;
    case pasta::BinaryOperatorKind::kLOr: return BinaryOperatorKind::L_OR;
    case pasta::BinaryOperatorKind::kAssign: return BinaryOperatorKind::ASSIGN;
    case pasta::BinaryOperatorKind::kMulAssign: return BinaryOperatorKind::MUL_ASSIGN;
    case pasta::BinaryOperatorKind::kDivAssign: return BinaryOperatorKind::DIV_ASSIGN;
    case pasta::BinaryOperatorKind::kRemAssign: return BinaryOperatorKind::REM_ASSIGN;
    case pasta::BinaryOperatorKind::kAddAssign: return BinaryOperatorKind::ADD_ASSIGN;
    case pasta::BinaryOperatorKind::kSubAssign: return BinaryOperatorKind::SUB_ASSIGN;
    case pasta::BinaryOperatorKind::kShlAssign: return BinaryOperatorKind::SHL_ASSIGN;
    case pasta::BinaryOperatorKind::kShrAssign: return BinaryOperatorKind::SHR_ASSIGN;
    case pasta::BinaryOperatorKind::kAndAssign: return BinaryOperatorKind::AND_ASSIGN;
    case pasta::BinaryOperatorKind::kXorAssign: return BinaryOperatorKind::XOR_ASSIGN;
    case pasta::BinaryOperatorKind::kOrAssign: return BinaryOperatorKind::OR_ASSIGN;
    case pasta::BinaryOperatorKind::kComma: return BinaryOperatorKind::COMMA;
  }
}

Bits FromPasta(pasta::Bits e) {
  switch (e) {
    case pasta::Bits::kNone: return Bits::NONE;
    case pasta::Bits::kUnexpandedPack: return Bits::UNEXPANDED_PACK;
    case pasta::Bits::kInstantiation: return Bits::INSTANTIATION;
    case pasta::Bits::kType: return Bits::TYPE;
    case pasta::Bits::kValue: return Bits::VALUE;
    case pasta::Bits::kDependent: return Bits::DEPENDENT;
    case pasta::Bits::kError: return Bits::ERROR;
    case pasta::Bits::kVariablyModified: return Bits::VARIABLY_MODIFIED;
    case pasta::Bits::kSyntactic: return Bits::SYNTACTIC;
  }
}

BlockType FromPasta(pasta::BlockType e) {
  switch (e) {
    case pasta::BlockType::kByReference: return BlockType::BY_REFERENCE;
  }
}

BranchStateTy FromPasta(pasta::BranchStateTy e) {
  switch (e) {
    case pasta::BranchStateTy::kUndefined: return BranchStateTy::UNDEFINED;
    case pasta::BranchStateTy::kInbranch: return BranchStateTy::INBRANCH;
    case pasta::BranchStateTy::kNotinbranch: return BranchStateTy::NOTINBRANCH;
  }
}

CallingConv FromPasta(pasta::CallingConv e) {
  switch (e) {
    case pasta::CallingConv::kC: return CallingConv::C;
    case pasta::CallingConv::kX86StdCall: return CallingConv::X86_STD_CALL;
    case pasta::CallingConv::kX86FastCall: return CallingConv::X86_FAST_CALL;
    case pasta::CallingConv::kX86ThisCall: return CallingConv::X86_THIS_CALL;
    case pasta::CallingConv::kX86VectorCall: return CallingConv::X86_VECTOR_CALL;
    case pasta::CallingConv::kX86Pascal: return CallingConv::X86_PASCAL;
    case pasta::CallingConv::kWin64: return CallingConv::WIN64;
    case pasta::CallingConv::kX8664SysV: return CallingConv::X8664_SYS_V;
    case pasta::CallingConv::kX86RegCall: return CallingConv::X86_REG_CALL;
    case pasta::CallingConv::kAAPCS: return CallingConv::AAPCS;
    case pasta::CallingConv::kAAPCSVFP: return CallingConv::AAPCSVFP;
    case pasta::CallingConv::kIntelOclBicc: return CallingConv::INTEL_OCL_BICC;
    case pasta::CallingConv::kSpirFunction: return CallingConv::SPIR_FUNCTION;
    case pasta::CallingConv::kOpenCLKernel: return CallingConv::OPEN_CL_KERNEL;
    case pasta::CallingConv::kSwift: return CallingConv::SWIFT;
    case pasta::CallingConv::kSwiftAsync: return CallingConv::SWIFT_ASYNC;
    case pasta::CallingConv::kPreserveMost: return CallingConv::PRESERVE_MOST;
    case pasta::CallingConv::kPreserveAll: return CallingConv::PRESERVE_ALL;
    case pasta::CallingConv::kAArch64VectorCall: return CallingConv::A_ARCH64_VECTOR_CALL;
  }
}

CanThrowResult FromPasta(pasta::CanThrowResult e) {
  switch (e) {
    case pasta::CanThrowResult::kCannot: return CanThrowResult::CANNOT;
    case pasta::CanThrowResult::kDependent: return CanThrowResult::DEPENDENT;
    case pasta::CanThrowResult::kCan: return CanThrowResult::CAN;
  }
}

CapturedRegionKind FromPasta(pasta::CapturedRegionKind e) {
  switch (e) {
    case pasta::CapturedRegionKind::kDefault: return CapturedRegionKind::DEFAULT;
    case pasta::CapturedRegionKind::kObjCAtFinally: return CapturedRegionKind::OBJ_C_AT_FINALLY;
    case pasta::CapturedRegionKind::kOpenMP: return CapturedRegionKind::OPEN_MP;
  }
}

CastKind FromPasta(pasta::CastKind e) {
  switch (e) {
    case pasta::CastKind::kDependent: return CastKind::DEPENDENT;
    case pasta::CastKind::kBitCast: return CastKind::BIT_CAST;
    case pasta::CastKind::kLValueBitCast: return CastKind::L_VALUE_BIT_CAST;
    case pasta::CastKind::kLValueToRValueBitCast: return CastKind::L_VALUE_TO_R_VALUE_BIT_CAST;
    case pasta::CastKind::kLValueToRValue: return CastKind::L_VALUE_TO_R_VALUE;
    case pasta::CastKind::kNoOperation: return CastKind::NO_OPERATION;
    case pasta::CastKind::kBaseToDerived: return CastKind::BASE_TO_DERIVED;
    case pasta::CastKind::kDerivedToBase: return CastKind::DERIVED_TO_BASE;
    case pasta::CastKind::kUncheckedDerivedToBase: return CastKind::UNCHECKED_DERIVED_TO_BASE;
    case pasta::CastKind::kDynamic: return CastKind::DYNAMIC;
    case pasta::CastKind::kToUnion: return CastKind::TO_UNION;
    case pasta::CastKind::kArrayToPointerDecay: return CastKind::ARRAY_TO_POINTER_DECAY;
    case pasta::CastKind::kFunctionToPointerDecay: return CastKind::FUNCTION_TO_POINTER_DECAY;
    case pasta::CastKind::kNullToPointer: return CastKind::NULL_TO_POINTER;
    case pasta::CastKind::kNullToMemberPointer: return CastKind::NULL_TO_MEMBER_POINTER;
    case pasta::CastKind::kBaseToDerivedMemberPointer: return CastKind::BASE_TO_DERIVED_MEMBER_POINTER;
    case pasta::CastKind::kDerivedToBaseMemberPointer: return CastKind::DERIVED_TO_BASE_MEMBER_POINTER;
    case pasta::CastKind::kMemberPointerToBoolean: return CastKind::MEMBER_POINTER_TO_BOOLEAN;
    case pasta::CastKind::kReinterpretMemberPointer: return CastKind::REINTERPRET_MEMBER_POINTER;
    case pasta::CastKind::kUserDefinedConversion: return CastKind::USER_DEFINED_CONVERSION;
    case pasta::CastKind::kConstructorConversion: return CastKind::CONSTRUCTOR_CONVERSION;
    case pasta::CastKind::kIntegralToPointer: return CastKind::INTEGRAL_TO_POINTER;
    case pasta::CastKind::kPointerToIntegral: return CastKind::POINTER_TO_INTEGRAL;
    case pasta::CastKind::kPointerToBoolean: return CastKind::POINTER_TO_BOOLEAN;
    case pasta::CastKind::kToVoid: return CastKind::TO_VOID;
    case pasta::CastKind::kMatrixCast: return CastKind::MATRIX_CAST;
    case pasta::CastKind::kVectorSplat: return CastKind::VECTOR_SPLAT;
    case pasta::CastKind::kIntegralCast: return CastKind::INTEGRAL_CAST;
    case pasta::CastKind::kIntegralToBoolean: return CastKind::INTEGRAL_TO_BOOLEAN;
    case pasta::CastKind::kIntegralToFloating: return CastKind::INTEGRAL_TO_FLOATING;
    case pasta::CastKind::kFloatingToFixedPoint: return CastKind::FLOATING_TO_FIXED_POINT;
    case pasta::CastKind::kFixedPointToFloating: return CastKind::FIXED_POINT_TO_FLOATING;
    case pasta::CastKind::kFixedPointCast: return CastKind::FIXED_POINT_CAST;
    case pasta::CastKind::kFixedPointToIntegral: return CastKind::FIXED_POINT_TO_INTEGRAL;
    case pasta::CastKind::kIntegralToFixedPoint: return CastKind::INTEGRAL_TO_FIXED_POINT;
    case pasta::CastKind::kFixedPointToBoolean: return CastKind::FIXED_POINT_TO_BOOLEAN;
    case pasta::CastKind::kFloatingToIntegral: return CastKind::FLOATING_TO_INTEGRAL;
    case pasta::CastKind::kFloatingToBoolean: return CastKind::FLOATING_TO_BOOLEAN;
    case pasta::CastKind::kBooleanToSignedIntegral: return CastKind::BOOLEAN_TO_SIGNED_INTEGRAL;
    case pasta::CastKind::kFloatingCast: return CastKind::FLOATING_CAST;
    case pasta::CastKind::kCPointerToObjCPointerCast: return CastKind::C_POINTER_TO_OBJ_C_POINTER_CAST;
    case pasta::CastKind::kBlockPointerToObjCPointerCast: return CastKind::BLOCK_POINTER_TO_OBJ_C_POINTER_CAST;
    case pasta::CastKind::kAnyPointerToBlockPointerCast: return CastKind::ANY_POINTER_TO_BLOCK_POINTER_CAST;
    case pasta::CastKind::kObjCObjectLValueCast: return CastKind::OBJ_C_OBJECT_L_VALUE_CAST;
    case pasta::CastKind::kFloatingRealToComplex: return CastKind::FLOATING_REAL_TO_COMPLEX;
    case pasta::CastKind::kFloatingComplexToReal: return CastKind::FLOATING_COMPLEX_TO_REAL;
    case pasta::CastKind::kFloatingComplexToBoolean: return CastKind::FLOATING_COMPLEX_TO_BOOLEAN;
    case pasta::CastKind::kFloatingComplexCast: return CastKind::FLOATING_COMPLEX_CAST;
    case pasta::CastKind::kFloatingComplexToIntegralComplex: return CastKind::FLOATING_COMPLEX_TO_INTEGRAL_COMPLEX;
    case pasta::CastKind::kIntegralRealToComplex: return CastKind::INTEGRAL_REAL_TO_COMPLEX;
    case pasta::CastKind::kIntegralComplexToReal: return CastKind::INTEGRAL_COMPLEX_TO_REAL;
    case pasta::CastKind::kIntegralComplexToBoolean: return CastKind::INTEGRAL_COMPLEX_TO_BOOLEAN;
    case pasta::CastKind::kIntegralComplexCast: return CastKind::INTEGRAL_COMPLEX_CAST;
    case pasta::CastKind::kIntegralComplexToFloatingComplex: return CastKind::INTEGRAL_COMPLEX_TO_FLOATING_COMPLEX;
    case pasta::CastKind::kARCProduceObject: return CastKind::ARC_PRODUCE_OBJECT;
    case pasta::CastKind::kARCConsumeObject: return CastKind::ARC_CONSUME_OBJECT;
    case pasta::CastKind::kARCReclaimReturnedObject: return CastKind::ARC_RECLAIM_RETURNED_OBJECT;
    case pasta::CastKind::kARCExtendBlockObject: return CastKind::ARC_EXTEND_BLOCK_OBJECT;
    case pasta::CastKind::kAtomicToNonAtomic: return CastKind::ATOMIC_TO_NON_ATOMIC;
    case pasta::CastKind::kNonAtomicToAtomic: return CastKind::NON_ATOMIC_TO_ATOMIC;
    case pasta::CastKind::kCopyAndAutoreleaseBlockObject: return CastKind::COPY_AND_AUTORELEASE_BLOCK_OBJECT;
    case pasta::CastKind::kBuiltinFnToFnPointer: return CastKind::BUILTIN_FN_TO_FN_POINTER;
    case pasta::CastKind::kZeroToOCLOpaqueType: return CastKind::ZERO_TO_OCL_OPAQUE_TYPE;
    case pasta::CastKind::kAddressSpaceConversion: return CastKind::ADDRESS_SPACE_CONVERSION;
    case pasta::CastKind::kIntToOCLSampler: return CastKind::INT_TO_OCL_SAMPLER;
  }
}

ClangABI FromPasta(pasta::ClangABI e) {
  switch (e) {
    case pasta::ClangABI::kVer38: return ClangABI::VER38;
    case pasta::ClangABI::kVer4: return ClangABI::VER4;
    case pasta::ClangABI::kVer6: return ClangABI::VER6;
    case pasta::ClangABI::kVer7: return ClangABI::VER7;
    case pasta::ClangABI::kVer9: return ClangABI::VER9;
    case pasta::ClangABI::kVer11: return ClangABI::VER11;
    case pasta::ClangABI::kVer12: return ClangABI::VER12;
    case pasta::ClangABI::kLatest: return ClangABI::LATEST;
  }
}

CommentKind FromPasta(pasta::CommentKind e) {
  switch (e) {
    case pasta::CommentKind::kInvalid: return CommentKind::INVALID;
    case pasta::CommentKind::kOrdinaryBCPL: return CommentKind::ORDINARY_BCPL;
    case pasta::CommentKind::kOrdinaryC: return CommentKind::ORDINARY_C;
    case pasta::CommentKind::kBCPLSlash: return CommentKind::BCPL_SLASH;
    case pasta::CommentKind::kBCPLExcl: return CommentKind::BCPL_EXCL;
    case pasta::CommentKind::kJavaDoc: return CommentKind::JAVA_DOC;
    case pasta::CommentKind::kQt: return CommentKind::QT;
    case pasta::CommentKind::kMerged: return CommentKind::MERGED;
  }
}

ComparisonCategoryResult FromPasta(pasta::ComparisonCategoryResult e) {
  switch (e) {
    case pasta::ComparisonCategoryResult::kEqual: return ComparisonCategoryResult::EQUAL;
    case pasta::ComparisonCategoryResult::kEquivalent: return ComparisonCategoryResult::EQUIVALENT;
    case pasta::ComparisonCategoryResult::kLess: return ComparisonCategoryResult::LESS;
    case pasta::ComparisonCategoryResult::kGreater: return ComparisonCategoryResult::GREATER;
    case pasta::ComparisonCategoryResult::kUnordered: return ComparisonCategoryResult::UNORDERED;
  }
}

ComparisonCategoryType FromPasta(pasta::ComparisonCategoryType e) {
  switch (e) {
    case pasta::ComparisonCategoryType::kPartialOrdering: return ComparisonCategoryType::PARTIAL_ORDERING;
    case pasta::ComparisonCategoryType::kWeakOrdering: return ComparisonCategoryType::WEAK_ORDERING;
    case pasta::ComparisonCategoryType::kStrongOrdering: return ComparisonCategoryType::STRONG_ORDERING;
  }
}

CompilingModuleKind FromPasta(pasta::CompilingModuleKind e) {
  switch (e) {
    case pasta::CompilingModuleKind::kNone: return CompilingModuleKind::NONE;
    case pasta::CompilingModuleKind::kModuleMap: return CompilingModuleKind::MODULE_MAP;
    case pasta::CompilingModuleKind::kHeaderModule: return CompilingModuleKind::HEADER_MODULE;
    case pasta::CompilingModuleKind::kModuleInterface: return CompilingModuleKind::MODULE_INTERFACE;
  }
}

ConstexprSpecKind FromPasta(pasta::ConstexprSpecKind e) {
  switch (e) {
    case pasta::ConstexprSpecKind::kUnspecified: return ConstexprSpecKind::UNSPECIFIED;
    case pasta::ConstexprSpecKind::kConstexpr: return ConstexprSpecKind::CONSTEXPR;
    case pasta::ConstexprSpecKind::kConsteval: return ConstexprSpecKind::CONSTEVAL;
    case pasta::ConstexprSpecKind::kConstinit: return ConstexprSpecKind::CONSTINIT;
  }
}

ConsumedState FromPasta(pasta::ConsumedState e) {
  switch (e) {
    case pasta::ConsumedState::kUnknown: return ConsumedState::UNKNOWN;
    case pasta::ConsumedState::kConsumed: return ConsumedState::CONSUMED;
    case pasta::ConsumedState::kUnconsumed: return ConsumedState::UNCONSUMED;
  }
}

ConventionKind FromPasta(pasta::ConventionKind e) {
  switch (e) {
    case pasta::ConventionKind::kNone: return ConventionKind::NONE;
    case pasta::ConventionKind::kNonNullError: return ConventionKind::NON_NULL_ERROR;
    case pasta::ConventionKind::kZeroArgument: return ConventionKind::ZERO_ARGUMENT;
    case pasta::ConventionKind::kNonZeroArgument: return ConventionKind::NON_ZERO_ARGUMENT;
  }
}

CoreFoundationABI FromPasta(pasta::CoreFoundationABI e) {
  switch (e) {
    case pasta::CoreFoundationABI::kUnspecified: return CoreFoundationABI::UNSPECIFIED;
    case pasta::CoreFoundationABI::kStandalone: return CoreFoundationABI::STANDALONE;
    case pasta::CoreFoundationABI::kObjectiveC: return CoreFoundationABI::OBJECTIVE_C;
    case pasta::CoreFoundationABI::kSwift: return CoreFoundationABI::SWIFT;
    case pasta::CoreFoundationABI::kSwift50: return CoreFoundationABI::SWIFT50;
    case pasta::CoreFoundationABI::kSwift42: return CoreFoundationABI::SWIFT42;
    case pasta::CoreFoundationABI::kSwift41: return CoreFoundationABI::SWIFT41;
  }
}

DefaultArgKind FromPasta(pasta::DefaultArgKind e) {
  switch (e) {
    case pasta::DefaultArgKind::kNone: return DefaultArgKind::NONE;
    case pasta::DefaultArgKind::kUnparsed: return DefaultArgKind::UNPARSED;
    case pasta::DefaultArgKind::kUninstantiated: return DefaultArgKind::UNINSTANTIATED;
    case pasta::DefaultArgKind::kNormal: return DefaultArgKind::NORMAL;
  }
}

DefaultCallingConvention FromPasta(pasta::DefaultCallingConvention e) {
  switch (e) {
    case pasta::DefaultCallingConvention::kNone: return DefaultCallingConvention::NONE;
    case pasta::DefaultCallingConvention::kCDecl: return DefaultCallingConvention::C_DECL;
    case pasta::DefaultCallingConvention::kFastCall: return DefaultCallingConvention::FAST_CALL;
    case pasta::DefaultCallingConvention::kStdCall: return DefaultCallingConvention::STD_CALL;
    case pasta::DefaultCallingConvention::kVectorCall: return DefaultCallingConvention::VECTOR_CALL;
    case pasta::DefaultCallingConvention::kRegCall: return DefaultCallingConvention::REG_CALL;
  }
}

DevTypeTy FromPasta(pasta::DevTypeTy e) {
  switch (e) {
    case pasta::DevTypeTy::kHost: return DevTypeTy::HOST;
    case pasta::DevTypeTy::kNoHost: return DevTypeTy::NO_HOST;
    case pasta::DevTypeTy::kAny: return DevTypeTy::ANY;
  }
}

DiagnosticLevelMask FromPasta(pasta::DiagnosticLevelMask e) {
  switch (e) {
    case pasta::DiagnosticLevelMask::kNone: return DiagnosticLevelMask::NONE;
    case pasta::DiagnosticLevelMask::kNote: return DiagnosticLevelMask::NOTE;
    case pasta::DiagnosticLevelMask::kRemark: return DiagnosticLevelMask::REMARK;
    case pasta::DiagnosticLevelMask::kWarning: return DiagnosticLevelMask::WARNING;
    case pasta::DiagnosticLevelMask::kError: return DiagnosticLevelMask::ERROR;
    case pasta::DiagnosticLevelMask::kAll: return DiagnosticLevelMask::ALL;
  }
}

DiagnosticType FromPasta(pasta::DiagnosticType e) {
  switch (e) {
    case pasta::DiagnosticType::kError: return DiagnosticType::ERROR;
    case pasta::DiagnosticType::kWarning: return DiagnosticType::WARNING;
  }
}

ElaboratedTypeKeyword FromPasta(pasta::ElaboratedTypeKeyword e) {
  switch (e) {
    case pasta::ElaboratedTypeKeyword::kStruct: return ElaboratedTypeKeyword::STRUCT;
    case pasta::ElaboratedTypeKeyword::kInterface: return ElaboratedTypeKeyword::INTERFACE;
    case pasta::ElaboratedTypeKeyword::kUnion: return ElaboratedTypeKeyword::UNION;
    case pasta::ElaboratedTypeKeyword::kClass: return ElaboratedTypeKeyword::CLASS;
    case pasta::ElaboratedTypeKeyword::kEnum: return ElaboratedTypeKeyword::ENUM;
    case pasta::ElaboratedTypeKeyword::kTypename: return ElaboratedTypeKeyword::TYPENAME;
    case pasta::ElaboratedTypeKeyword::kNone: return ElaboratedTypeKeyword::NONE;
  }
}

EmbedBitcodeKind FromPasta(pasta::EmbedBitcodeKind e) {
  switch (e) {
    case pasta::EmbedBitcodeKind::kEmbedOff: return EmbedBitcodeKind::EMBED_OFF;
    case pasta::EmbedBitcodeKind::kEmbedAll: return EmbedBitcodeKind::EMBED_ALL;
    case pasta::EmbedBitcodeKind::kEmbedBitcode: return EmbedBitcodeKind::EMBED_BITCODE;
    case pasta::EmbedBitcodeKind::kEmbedMarker: return EmbedBitcodeKind::EMBED_MARKER;
  }
}

ExceptionHandlingKind FromPasta(pasta::ExceptionHandlingKind e) {
  switch (e) {
    case pasta::ExceptionHandlingKind::kNone: return ExceptionHandlingKind::NONE;
    case pasta::ExceptionHandlingKind::kSjLj: return ExceptionHandlingKind::SJ_LJ;
    case pasta::ExceptionHandlingKind::kWinEH: return ExceptionHandlingKind::WIN_EH;
    case pasta::ExceptionHandlingKind::kDwarfCFI: return ExceptionHandlingKind::DWARF_CFI;
    case pasta::ExceptionHandlingKind::kWasm: return ExceptionHandlingKind::WASM;
  }
}

ExceptionSpecificationType FromPasta(pasta::ExceptionSpecificationType e) {
  switch (e) {
    case pasta::ExceptionSpecificationType::kNone: return ExceptionSpecificationType::NONE;
    case pasta::ExceptionSpecificationType::kDynamicNone: return ExceptionSpecificationType::DYNAMIC_NONE;
    case pasta::ExceptionSpecificationType::kDynamic: return ExceptionSpecificationType::DYNAMIC;
    case pasta::ExceptionSpecificationType::kMSAny: return ExceptionSpecificationType::MS_ANY;
    case pasta::ExceptionSpecificationType::kNoThrow: return ExceptionSpecificationType::NO_THROW;
    case pasta::ExceptionSpecificationType::kBasicNoexcept: return ExceptionSpecificationType::BASIC_NOEXCEPT;
    case pasta::ExceptionSpecificationType::kDependentNoexcept: return ExceptionSpecificationType::DEPENDENT_NOEXCEPT;
    case pasta::ExceptionSpecificationType::kNoexceptFalse: return ExceptionSpecificationType::NOEXCEPT_FALSE;
    case pasta::ExceptionSpecificationType::kNoexceptTrue: return ExceptionSpecificationType::NOEXCEPT_TRUE;
    case pasta::ExceptionSpecificationType::kUnevaluated: return ExceptionSpecificationType::UNEVALUATED;
    case pasta::ExceptionSpecificationType::kUninstantiated: return ExceptionSpecificationType::UNINSTANTIATED;
    case pasta::ExceptionSpecificationType::kUnparsed: return ExceptionSpecificationType::UNPARSED;
  }
}

ExplicitSpecKind FromPasta(pasta::ExplicitSpecKind e) {
  switch (e) {
    case pasta::ExplicitSpecKind::kResolvedFalse: return ExplicitSpecKind::RESOLVED_FALSE;
    case pasta::ExplicitSpecKind::kResolvedTrue: return ExplicitSpecKind::RESOLVED_TRUE;
    case pasta::ExplicitSpecKind::kUnresolved: return ExplicitSpecKind::UNRESOLVED;
  }
}

ExprDependence FromPasta(pasta::ExprDependence e) {
  switch (e) {
    case pasta::ExprDependence::kUnexpandedPack: return ExprDependence::UNEXPANDED_PACK;
    case pasta::ExprDependence::kInstantiation: return ExprDependence::INSTANTIATION;
    case pasta::ExprDependence::kType: return ExprDependence::TYPE;
    case pasta::ExprDependence::kValue: return ExprDependence::VALUE;
    case pasta::ExprDependence::kError: return ExprDependence::ERROR;
    case pasta::ExprDependence::kNone: return ExprDependence::NONE;
    case pasta::ExprDependence::kAll: return ExprDependence::ALL;
    case pasta::ExprDependence::kTypeValue: return ExprDependence::TYPE_VALUE;
    case pasta::ExprDependence::kTypeInstantiation: return ExprDependence::TYPE_INSTANTIATION;
    case pasta::ExprDependence::kValueInstantiation: return ExprDependence::VALUE_INSTANTIATION;
    case pasta::ExprDependence::kTypeValueInstantiation: return ExprDependence::TYPE_VALUE_INSTANTIATION;
    case pasta::ExprDependence::kErrorDependent: return ExprDependence::ERROR_DEPENDENT;
  }
}

ExprObjectKind FromPasta(pasta::ExprObjectKind e) {
  switch (e) {
    case pasta::ExprObjectKind::kOrdinary: return ExprObjectKind::ORDINARY;
    case pasta::ExprObjectKind::kBitField: return ExprObjectKind::BIT_FIELD;
    case pasta::ExprObjectKind::kVectorComponent: return ExprObjectKind::VECTOR_COMPONENT;
    case pasta::ExprObjectKind::kObjCProperty: return ExprObjectKind::OBJ_C_PROPERTY;
    case pasta::ExprObjectKind::kObjCSubscript: return ExprObjectKind::OBJ_C_SUBSCRIPT;
    case pasta::ExprObjectKind::kMatrixComponent: return ExprObjectKind::MATRIX_COMPONENT;
  }
}

ExprOffsets FromPasta(pasta::ExprOffsets e) {
  switch (e) {
    case pasta::ExprOffsets::kAllocator: return ExprOffsets::ALLOCATOR;
    case pasta::ExprOffsets::kAllocatorTraits: return ExprOffsets::ALLOCATOR_TRAITS;
    case pasta::ExprOffsets::kTotal: return ExprOffsets::TOTAL;
  }
}

ExprValueKind FromPasta(pasta::ExprValueKind e) {
  switch (e) {
    case pasta::ExprValueKind::kPRValue: return ExprValueKind::PR_VALUE;
    case pasta::ExprValueKind::kLValue: return ExprValueKind::L_VALUE;
    case pasta::ExprValueKind::kXValue: return ExprValueKind::X_VALUE;
  }
}

ExpressionTrait FromPasta(pasta::ExpressionTrait e) {
  switch (e) {
    case pasta::ExpressionTrait::kIsLValueExpression: return ExpressionTrait::IS_L_VALUE_EXPRESSION;
    case pasta::ExpressionTrait::kIsRValueExpression: return ExpressionTrait::IS_R_VALUE_EXPRESSION;
  }
}

ExtKind FromPasta(pasta::ExtKind e) {
  switch (e) {
    case pasta::ExtKind::kAlways: return ExtKind::ALWAYS;
    case pasta::ExtKind::kNever: return ExtKind::NEVER;
    case pasta::ExtKind::kReplyHazy: return ExtKind::REPLY_HAZY;
  }
}

ExtendArgsKind FromPasta(pasta::ExtendArgsKind e) {
  switch (e) {
    case pasta::ExtendArgsKind::kExtendTo32: return ExtendArgsKind::EXTEND_TO32;
    case pasta::ExtendArgsKind::kExtendTo64: return ExtendArgsKind::EXTEND_TO64;
  }
}

FPExceptionModeKind FromPasta(pasta::FPExceptionModeKind e) {
  switch (e) {
    case pasta::FPExceptionModeKind::kIgnore: return FPExceptionModeKind::IGNORE;
    case pasta::FPExceptionModeKind::kMayTrap: return FPExceptionModeKind::MAY_TRAP;
    case pasta::FPExceptionModeKind::kStrict: return FPExceptionModeKind::STRICT;
  }
}

FPModeKind FromPasta(pasta::FPModeKind e) {
  switch (e) {
    case pasta::FPModeKind::kOff: return FPModeKind::OFF;
    case pasta::FPModeKind::kOn: return FPModeKind::ON;
    case pasta::FPModeKind::kFast: return FPModeKind::FAST;
    case pasta::FPModeKind::kFastHonorPragmas: return FPModeKind::FAST_HONOR_PRAGMAS;
  }
}

FamilyKind FromPasta(pasta::FamilyKind e) {
  switch (e) {
    case pasta::FamilyKind::kNone: return FamilyKind::NONE;
    case pasta::FamilyKind::kAlloc: return FamilyKind::ALLOC;
    case pasta::FamilyKind::kCopy: return FamilyKind::COPY;
    case pasta::FamilyKind::kInitializer: return FamilyKind::INITIALIZER;
    case pasta::FamilyKind::kMutableCopy: return FamilyKind::MUTABLE_COPY;
    case pasta::FamilyKind::kNew: return FamilyKind::NEW;
  }
}

FiniteLoopsKind FromPasta(pasta::FiniteLoopsKind e) {
  switch (e) {
    case pasta::FiniteLoopsKind::kLanguage: return FiniteLoopsKind::LANGUAGE;
    case pasta::FiniteLoopsKind::kAlways: return FiniteLoopsKind::ALWAYS;
    case pasta::FiniteLoopsKind::kNever: return FiniteLoopsKind::NEVER;
  }
}

FramePointerKind FromPasta(pasta::FramePointerKind e) {
  switch (e) {
    case pasta::FramePointerKind::kNone: return FramePointerKind::NONE;
    case pasta::FramePointerKind::kNonLeaf: return FramePointerKind::NON_LEAF;
    case pasta::FramePointerKind::kAll: return FramePointerKind::ALL;
  }
}

GC FromPasta(pasta::GC e) {
  switch (e) {
    case pasta::GC::kGCNone: return GC::GC_NONE;
    case pasta::GC::kWeak: return GC::WEAK;
    case pasta::GC::kStrong: return GC::STRONG;
  }
}

GCMode FromPasta(pasta::GCMode e) {
  switch (e) {
    case pasta::GCMode::kNonGC: return GCMode::NON_GC;
    case pasta::GCMode::kGCOnly: return GCMode::GC_ONLY;
    case pasta::GCMode::kHybridGC: return GCMode::HYBRID_GC;
  }
}

GVALinkage FromPasta(pasta::GVALinkage e) {
  switch (e) {
    case pasta::GVALinkage::kInternal: return GVALinkage::INTERNAL;
    case pasta::GVALinkage::kAvailableExternally: return GVALinkage::AVAILABLE_EXTERNALLY;
    case pasta::GVALinkage::kDiscardableODR: return GVALinkage::DISCARDABLE_ODR;
    case pasta::GVALinkage::kStrongExternal: return GVALinkage::STRONG_EXTERNAL;
    case pasta::GVALinkage::kStrongODR: return GVALinkage::STRONG_ODR;
  }
}

GetBuiltinTypeError FromPasta(pasta::GetBuiltinTypeError e) {
  switch (e) {
    case pasta::GetBuiltinTypeError::kNone: return GetBuiltinTypeError::NONE;
    case pasta::GetBuiltinTypeError::kMissingType: return GetBuiltinTypeError::MISSING_TYPE;
    case pasta::GetBuiltinTypeError::kMissingStdio: return GetBuiltinTypeError::MISSING_STDIO;
    case pasta::GetBuiltinTypeError::kMissing: return GetBuiltinTypeError::MISSING;
    case pasta::GetBuiltinTypeError::kMissingUcontext: return GetBuiltinTypeError::MISSING_UCONTEXT;
  }
}

GuardArg FromPasta(pasta::GuardArg e) {
  switch (e) {
    case pasta::GuardArg::kNocf: return GuardArg::NOCF;
  }
}

ID FromPasta(pasta::ID e) {
  switch (e) {
    case pasta::ID::kWorkGroup: return ID::WORK_GROUP;
    case pasta::ID::kDevice: return ID::DEVICE;
    case pasta::ID::kAllSVMDevices: return ID::ALL_SVM_DEVICES;
    case pasta::ID::kSubGroup: return ID::SUB_GROUP;
  }
}

IdentifierInfoFlag FromPasta(pasta::IdentifierInfoFlag e) {
  switch (e) {
    case pasta::IdentifierInfoFlag::kZeroArgument: return IdentifierInfoFlag::ZERO_ARGUMENT;
    case pasta::IdentifierInfoFlag::kOneArgument: return IdentifierInfoFlag::ONE_ARGUMENT;
    case pasta::IdentifierInfoFlag::kMultiArgument: return IdentifierInfoFlag::MULTI_ARGUMENT;
  }
}

ImbueAttribute FromPasta(pasta::ImbueAttribute e) {
  switch (e) {
    case pasta::ImbueAttribute::kNONE: return ImbueAttribute::NONE;
    case pasta::ImbueAttribute::kALWAYS: return ImbueAttribute::ALWAYS;
    case pasta::ImbueAttribute::kNEVER: return ImbueAttribute::NEVER;
    case pasta::ImbueAttribute::kALWAYSARG1: return ImbueAttribute::ALWAYSAR_G1;
  }
}

ImplicitReason FromPasta(pasta::ImplicitReason e) {
  switch (e) {
    case pasta::ImplicitReason::kNone: return ImplicitReason::NONE;
    case pasta::ImplicitReason::kARCForbiddenType: return ImplicitReason::ARC_FORBIDDEN_TYPE;
    case pasta::ImplicitReason::kForbiddenWeak: return ImplicitReason::FORBIDDEN_WEAK;
    case pasta::ImplicitReason::kARCForbiddenConversion: return ImplicitReason::ARC_FORBIDDEN_CONVERSION;
    case pasta::ImplicitReason::kARCInitReturnsUnrelated: return ImplicitReason::ARC_INIT_RETURNS_UNRELATED;
    case pasta::ImplicitReason::kARCFieldWithOwnership: return ImplicitReason::ARC_FIELD_WITH_OWNERSHIP;
  }
}

InClassInitStyle FromPasta(pasta::InClassInitStyle e) {
  switch (e) {
    case pasta::InClassInitStyle::kNoInitializer: return InClassInitStyle::NO_INITIALIZER;
    case pasta::InClassInitStyle::kCopyInitializer: return InClassInitStyle::COPY_INITIALIZER;
    case pasta::InClassInitStyle::kListInitializer: return InClassInitStyle::LIST_INITIALIZER;
  }
}

InheritedDesignatedInitializersState FromPasta(pasta::InheritedDesignatedInitializersState e) {
  switch (e) {
    case pasta::InheritedDesignatedInitializersState::kUnknown: return InheritedDesignatedInitializersState::UNKNOWN;
    case pasta::InheritedDesignatedInitializersState::kInherited: return InheritedDesignatedInitializersState::INHERITED;
    case pasta::InheritedDesignatedInitializersState::kNotInherited: return InheritedDesignatedInitializersState::NOT_INHERITED;
  }
}

InitStorageKind FromPasta(pasta::InitStorageKind e) {
  switch (e) {
    case pasta::InitStorageKind::kNoInitializer: return InitStorageKind::NO_INITIALIZER;
    case pasta::InitStorageKind::kInClassCopyInitializer: return InitStorageKind::IN_CLASS_COPY_INITIALIZER;
    case pasta::InitStorageKind::kInClassListInitializer: return InitStorageKind::IN_CLASS_LIST_INITIALIZER;
    case pasta::InitStorageKind::kCapturedVLAType: return InitStorageKind::CAPTURED_VLA_TYPE;
  }
}

InlineVariableDefinitionKind FromPasta(pasta::InlineVariableDefinitionKind e) {
  switch (e) {
    case pasta::InlineVariableDefinitionKind::kNone: return InlineVariableDefinitionKind::NONE;
    case pasta::InlineVariableDefinitionKind::kWeak: return InlineVariableDefinitionKind::WEAK;
    case pasta::InlineVariableDefinitionKind::kWeakUnknown: return InlineVariableDefinitionKind::WEAK_UNKNOWN;
    case pasta::InlineVariableDefinitionKind::kStrong: return InlineVariableDefinitionKind::STRONG;
  }
}

InliningMethod FromPasta(pasta::InliningMethod e) {
  switch (e) {
    case pasta::InliningMethod::kNormalInlining: return InliningMethod::NORMAL_INLINING;
    case pasta::InliningMethod::kOnlyHintInlining: return InliningMethod::ONLY_HINT_INLINING;
    case pasta::InliningMethod::kOnlyAlwaysInlining: return InliningMethod::ONLY_ALWAYS_INLINING;
  }
}

InterruptType FromPasta(pasta::InterruptType e) {
  switch (e) {
    case pasta::InterruptType::kIRQ: return InterruptType::IRQ;
    case pasta::InterruptType::kFIQ: return InterruptType::FIQ;
    case pasta::InterruptType::kSWI: return InterruptType::SWI;
    case pasta::InterruptType::kABORT: return InterruptType::ABORT;
    case pasta::InterruptType::kUNDEF: return InterruptType::UNDEF;
    case pasta::InterruptType::kGeneric: return InterruptType::GENERIC;
  }
}

Kinds FromPasta(pasta::Kinds e) {
  switch (e) {
    case pasta::Kinds::kLValue: return Kinds::L_VALUE;
    case pasta::Kinds::kXValue: return Kinds::X_VALUE;
    case pasta::Kinds::kFunction: return Kinds::FUNCTION;
    case pasta::Kinds::kVoid: return Kinds::VOID;
    case pasta::Kinds::kAddressableVoid: return Kinds::ADDRESSABLE_VOID;
    case pasta::Kinds::kDuplicateVectorComponents: return Kinds::DUPLICATE_VECTOR_COMPONENTS;
    case pasta::Kinds::kMemberFunction: return Kinds::MEMBER_FUNCTION;
    case pasta::Kinds::kSubObjCPropertySetting: return Kinds::SUB_OBJ_C_PROPERTY_SETTING;
    case pasta::Kinds::kClassTemporary: return Kinds::CLASS_TEMPORARY;
    case pasta::Kinds::kArrayTemporary: return Kinds::ARRAY_TEMPORARY;
    case pasta::Kinds::kObjCMessageRValue: return Kinds::OBJ_C_MESSAGE_R_VALUE;
    case pasta::Kinds::kPRValue: return Kinds::PR_VALUE;
  }
}

LambdaCaptureDefault FromPasta(pasta::LambdaCaptureDefault e) {
  switch (e) {
    case pasta::LambdaCaptureDefault::kNone: return LambdaCaptureDefault::NONE;
    case pasta::LambdaCaptureDefault::kByCopy: return LambdaCaptureDefault::BY_COPY;
    case pasta::LambdaCaptureDefault::kByReference: return LambdaCaptureDefault::BY_REFERENCE;
  }
}

LambdaCaptureKind FromPasta(pasta::LambdaCaptureKind e) {
  switch (e) {
    case pasta::LambdaCaptureKind::kThis: return LambdaCaptureKind::THIS;
    case pasta::LambdaCaptureKind::kStarThis: return LambdaCaptureKind::STAR_THIS;
    case pasta::LambdaCaptureKind::kByCopy: return LambdaCaptureKind::BY_COPY;
    case pasta::LambdaCaptureKind::kByReference: return LambdaCaptureKind::BY_REFERENCE;
    case pasta::LambdaCaptureKind::kVLAType: return LambdaCaptureKind::VLA_TYPE;
  }
}

LangAS FromPasta(pasta::LangAS e) {
  switch (e) {
    case pasta::LangAS::kDefault: return LangAS::DEFAULT;
    case pasta::LangAS::kOpenclGlobal: return LangAS::OPENCL_GLOBAL;
    case pasta::LangAS::kOpenclLocal: return LangAS::OPENCL_LOCAL;
    case pasta::LangAS::kOpenclConstant: return LangAS::OPENCL_CONSTANT;
    case pasta::LangAS::kOpenclPrivate: return LangAS::OPENCL_PRIVATE;
    case pasta::LangAS::kOpenclGeneric: return LangAS::OPENCL_GENERIC;
    case pasta::LangAS::kOpenclGlobalDevice: return LangAS::OPENCL_GLOBAL_DEVICE;
    case pasta::LangAS::kOpenclGlobalHost: return LangAS::OPENCL_GLOBAL_HOST;
    case pasta::LangAS::kCudaDevice: return LangAS::CUDA_DEVICE;
    case pasta::LangAS::kCudaConstant: return LangAS::CUDA_CONSTANT;
    case pasta::LangAS::kCudaShared: return LangAS::CUDA_SHARED;
    case pasta::LangAS::kSyclGlobal: return LangAS::SYCL_GLOBAL;
    case pasta::LangAS::kSyclGlobalDevice: return LangAS::SYCL_GLOBAL_DEVICE;
    case pasta::LangAS::kSyclGlobalHost: return LangAS::SYCL_GLOBAL_HOST;
    case pasta::LangAS::kSyclLocal: return LangAS::SYCL_LOCAL;
    case pasta::LangAS::kSyclPrivate: return LangAS::SYCL_PRIVATE;
    case pasta::LangAS::kPtr32Sptr: return LangAS::PTR32_SPTR;
    case pasta::LangAS::kPtr32Uptr: return LangAS::PTR32_UPTR;
    case pasta::LangAS::kPtr64: return LangAS::PTR64;
  }
}

LangFeatures FromPasta(pasta::LangFeatures e) {
  switch (e) {
    case pasta::LangFeatures::kLineComment: return LangFeatures::LINE_COMMENT;
    case pasta::LangFeatures::kC99: return LangFeatures::C99;
    case pasta::LangFeatures::kC11: return LangFeatures::C11;
    case pasta::LangFeatures::kC17: return LangFeatures::C17;
    case pasta::LangFeatures::kC2x: return LangFeatures::C2_X;
    case pasta::LangFeatures::kCPlusPlus: return LangFeatures::C_PLUS_PLUS;
    case pasta::LangFeatures::kCPlusPlus11: return LangFeatures::C_PLUS_PLUS11;
    case pasta::LangFeatures::kCPlusPlus14: return LangFeatures::C_PLUS_PLUS14;
    case pasta::LangFeatures::kCPlusPlus17: return LangFeatures::C_PLUS_PLUS17;
    case pasta::LangFeatures::kCPlusPlus20: return LangFeatures::C_PLUS_PLUS20;
    case pasta::LangFeatures::kCPlusPlus2b: return LangFeatures::C_PLUS_PLUS2_B;
    case pasta::LangFeatures::kDigraphs: return LangFeatures::DIGRAPHS;
    case pasta::LangFeatures::kGNUMode: return LangFeatures::GNU_MODE;
    case pasta::LangFeatures::kHexFloat: return LangFeatures::HEX_FLOAT;
    case pasta::LangFeatures::kImplicitInt: return LangFeatures::IMPLICIT_INT;
    case pasta::LangFeatures::kOpenCL: return LangFeatures::OPEN_CL;
  }
}

Language FromPasta(pasta::Language e) {
  switch (e) {
    case pasta::Language::kUnknown: return Language::UNKNOWN;
    case pasta::Language::kAssembly: return Language::ASSEMBLY;
    case pasta::Language::kLLVMIR: return Language::LLVMIR;
    case pasta::Language::kC: return Language::C;
    case pasta::Language::kCXX: return Language::CXX;
    case pasta::Language::kObjC: return Language::OBJ_C;
    case pasta::Language::kObjCXX: return Language::OBJ_CXX;
    case pasta::Language::kOpenCL: return Language::OPEN_CL;
    case pasta::Language::kOpenCLCXX: return Language::OPEN_CLCXX;
    case pasta::Language::kCUDA: return Language::CUDA;
    case pasta::Language::kRenderScript: return Language::RENDER_SCRIPT;
    case pasta::Language::kHIP: return Language::HIP;
  }
}

LanguageLinkage FromPasta(pasta::LanguageLinkage e) {
  switch (e) {
    case pasta::LanguageLinkage::kCLanguageLinkage: return LanguageLinkage::C_LANGUAGE_LINKAGE;
    case pasta::LanguageLinkage::kCXXLanguageLinkage: return LanguageLinkage::CXX_LANGUAGE_LINKAGE;
    case pasta::LanguageLinkage::kNoLanguageLinkage: return LanguageLinkage::NO_LANGUAGE_LINKAGE;
  }
}

LaxVectorConversionKind FromPasta(pasta::LaxVectorConversionKind e) {
  switch (e) {
    case pasta::LaxVectorConversionKind::kNone: return LaxVectorConversionKind::NONE;
    case pasta::LaxVectorConversionKind::kInteger: return LaxVectorConversionKind::INTEGER;
    case pasta::LaxVectorConversionKind::kAll: return LaxVectorConversionKind::ALL;
  }
}

Level FromPasta(pasta::Level e) {
  switch (e) {
    case pasta::Level::kIgnored: return Level::IGNORED;
    case pasta::Level::kNote: return Level::NOTE;
    case pasta::Level::kRemark: return Level::REMARK;
    case pasta::Level::kWarning: return Level::WARNING;
    case pasta::Level::kError: return Level::ERROR;
    case pasta::Level::kFatal: return Level::FATAL;
  }
}

Linkage FromPasta(pasta::Linkage e) {
  switch (e) {
    case pasta::Linkage::kNoLinkage: return Linkage::NO_LINKAGE;
    case pasta::Linkage::kInternalLinkage: return Linkage::INTERNAL_LINKAGE;
    case pasta::Linkage::kUniqueExternalLinkage: return Linkage::UNIQUE_EXTERNAL_LINKAGE;
    case pasta::Linkage::kVisibleNoLinkage: return Linkage::VISIBLE_NO_LINKAGE;
    case pasta::Linkage::kModuleInternalLinkage: return Linkage::MODULE_INTERNAL_LINKAGE;
    case pasta::Linkage::kModuleLinkage: return Linkage::MODULE_LINKAGE;
    case pasta::Linkage::kExternalLinkage: return Linkage::EXTERNAL_LINKAGE;
  }
}

LoopHintState FromPasta(pasta::LoopHintState e) {
  switch (e) {
    case pasta::LoopHintState::kEnable: return LoopHintState::ENABLE;
    case pasta::LoopHintState::kDisable: return LoopHintState::DISABLE;
    case pasta::LoopHintState::kNumeric: return LoopHintState::NUMERIC;
    case pasta::LoopHintState::kFixedWidth: return LoopHintState::FIXED_WIDTH;
    case pasta::LoopHintState::kScalableWidth: return LoopHintState::SCALABLE_WIDTH;
    case pasta::LoopHintState::kAssumeSafety: return LoopHintState::ASSUME_SAFETY;
    case pasta::LoopHintState::kFull: return LoopHintState::FULL;
  }
}

MSInheritanceModel FromPasta(pasta::MSInheritanceModel e) {
  switch (e) {
    case pasta::MSInheritanceModel::kSingle: return MSInheritanceModel::SINGLE;
    case pasta::MSInheritanceModel::kMultiple: return MSInheritanceModel::MULTIPLE;
    case pasta::MSInheritanceModel::kVirtual: return MSInheritanceModel::VIRTUAL;
    case pasta::MSInheritanceModel::kUnspecified: return MSInheritanceModel::UNSPECIFIED;
  }
}

MSVCMajorVersion FromPasta(pasta::MSVCMajorVersion e) {
  switch (e) {
    case pasta::MSVCMajorVersion::kMSVC2010: return MSVCMajorVersion::MSV_C2010;
    case pasta::MSVCMajorVersion::kMSVC2012: return MSVCMajorVersion::MSV_C2012;
    case pasta::MSVCMajorVersion::kMSVC2013: return MSVCMajorVersion::MSV_C2013;
    case pasta::MSVCMajorVersion::kMSVC2015: return MSVCMajorVersion::MSV_C2015;
    case pasta::MSVCMajorVersion::kMSVC2017: return MSVCMajorVersion::MSV_C2017;
    case pasta::MSVCMajorVersion::kMSVC20175: return MSVCMajorVersion::MSV_C20175;
    case pasta::MSVCMajorVersion::kMSVC20177: return MSVCMajorVersion::MSV_C20177;
    case pasta::MSVCMajorVersion::kMSVC2019: return MSVCMajorVersion::MSV_C2019;
    case pasta::MSVCMajorVersion::kMSVC20198: return MSVCMajorVersion::MSV_C20198;
  }
}

MSVtorDispMode FromPasta(pasta::MSVtorDispMode e) {
  switch (e) {
    case pasta::MSVtorDispMode::kNever: return MSVtorDispMode::NEVER;
    case pasta::MSVtorDispMode::kForVirtualBaseOverride: return MSVtorDispMode::FOR_VIRTUAL_BASE_OVERRIDE;
    case pasta::MSVtorDispMode::kForVFTable: return MSVtorDispMode::FOR_VF_TABLE;
  }
}

MapTypeTy FromPasta(pasta::MapTypeTy e) {
  switch (e) {
    case pasta::MapTypeTy::kTo: return MapTypeTy::TO;
    case pasta::MapTypeTy::kLink: return MapTypeTy::LINK;
  }
}

MethodRefFlags FromPasta(pasta::MethodRefFlags e) {
  switch (e) {
    case pasta::MethodRefFlags::kMethodReferenceNone: return MethodRefFlags::METHOD_REFERENCE_NONE;
    case pasta::MethodRefFlags::kMethodReferenceGetter: return MethodRefFlags::METHOD_REFERENCE_GETTER;
    case pasta::MethodRefFlags::kMethodReferenceSetter: return MethodRefFlags::METHOD_REFERENCE_SETTER;
  }
}

ModifiableType FromPasta(pasta::ModifiableType e) {
  switch (e) {
    case pasta::ModifiableType::kUntested: return ModifiableType::UNTESTED;
    case pasta::ModifiableType::kModifiable: return ModifiableType::MODIFIABLE;
    case pasta::ModifiableType::kRValue: return ModifiableType::R_VALUE;
    case pasta::ModifiableType::kFunction: return ModifiableType::FUNCTION;
    case pasta::ModifiableType::kLValueCast: return ModifiableType::L_VALUE_CAST;
    case pasta::ModifiableType::kNoSetterProperty: return ModifiableType::NO_SETTER_PROPERTY;
    case pasta::ModifiableType::kConstQualified: return ModifiableType::CONST_QUALIFIED;
    case pasta::ModifiableType::kConstQualifiedField: return ModifiableType::CONST_QUALIFIED_FIELD;
    case pasta::ModifiableType::kConstAddrSpace: return ModifiableType::CONST_ADDR_SPACE;
    case pasta::ModifiableType::kArrayType: return ModifiableType::ARRAY_TYPE;
    case pasta::ModifiableType::kIncompleteType: return ModifiableType::INCOMPLETE_TYPE;
  }
}

MultiVersionKind FromPasta(pasta::MultiVersionKind e) {
  switch (e) {
    case pasta::MultiVersionKind::kNone: return MultiVersionKind::NONE;
    case pasta::MultiVersionKind::kTarget: return MultiVersionKind::TARGET;
    case pasta::MultiVersionKind::kCPUSpecific: return MultiVersionKind::CPU_SPECIFIC;
    case pasta::MultiVersionKind::kCPUDispatch: return MultiVersionKind::CPU_DISPATCH;
  }
}

NameKind FromPasta(pasta::NameKind e) {
  switch (e) {
    case pasta::NameKind::kTemplate: return NameKind::TEMPLATE;
    case pasta::NameKind::kOverloadedTemplate: return NameKind::OVERLOADED_TEMPLATE;
    case pasta::NameKind::kAssumedTemplate: return NameKind::ASSUMED_TEMPLATE;
    case pasta::NameKind::kQualifiedTemplate: return NameKind::QUALIFIED_TEMPLATE;
    case pasta::NameKind::kDependentTemplate: return NameKind::DEPENDENT_TEMPLATE;
    case pasta::NameKind::kSubstTemplateTemplateParm: return NameKind::SUBST_TEMPLATE_TEMPLATE_PARM;
    case pasta::NameKind::kSubstTemplateTemplateParmPack: return NameKind::SUBST_TEMPLATE_TEMPLATE_PARM_PACK;
  }
}

NeedExtraManglingDecl FromPasta(pasta::NeedExtraManglingDecl e) {
  switch (e) {
    case pasta::NeedExtraManglingDecl::kNeedExtraManglingDeclaration: return NeedExtraManglingDecl::NEED_EXTRA_MANGLING_DECLARATION;
  }
}

NestedNameSpecifierDependence FromPasta(pasta::NestedNameSpecifierDependence e) {
  switch (e) {
    case pasta::NestedNameSpecifierDependence::kUnexpandedPack: return NestedNameSpecifierDependence::UNEXPANDED_PACK;
    case pasta::NestedNameSpecifierDependence::kInstantiation: return NestedNameSpecifierDependence::INSTANTIATION;
    case pasta::NestedNameSpecifierDependence::kDependent: return NestedNameSpecifierDependence::DEPENDENT;
    case pasta::NestedNameSpecifierDependence::kError: return NestedNameSpecifierDependence::ERROR;
    case pasta::NestedNameSpecifierDependence::kNone: return NestedNameSpecifierDependence::NONE;
    case pasta::NestedNameSpecifierDependence::kDependentInstantiation: return NestedNameSpecifierDependence::DEPENDENT_INSTANTIATION;
    case pasta::NestedNameSpecifierDependence::kAll: return NestedNameSpecifierDependence::ALL;
  }
}

NewtypeKind FromPasta(pasta::NewtypeKind e) {
  switch (e) {
    case pasta::NewtypeKind::kStruct: return NewtypeKind::STRUCT;
    case pasta::NewtypeKind::kEnum: return NewtypeKind::ENUM;
  }
}

NonOdrUseReason FromPasta(pasta::NonOdrUseReason e) {
  switch (e) {
    case pasta::NonOdrUseReason::kNone: return NonOdrUseReason::NONE;
    case pasta::NonOdrUseReason::kUnevaluated: return NonOdrUseReason::UNEVALUATED;
    case pasta::NonOdrUseReason::kConstant: return NonOdrUseReason::CONSTANT;
    case pasta::NonOdrUseReason::kDiscarded: return NonOdrUseReason::DISCARDED;
  }
}

NonceObjCInterface FromPasta(pasta::NonceObjCInterface e) {
  switch (e) {
    case pasta::NonceObjCInterface::kObjCInterface: return NonceObjCInterface::OBJ_C_INTERFACE;
  }
}

NullabilityKind FromPasta(pasta::NullabilityKind e) {
  switch (e) {
    case pasta::NullabilityKind::kNonNull: return NullabilityKind::NON_NULL;
    case pasta::NullabilityKind::kNullable: return NullabilityKind::NULLABLE;
    case pasta::NullabilityKind::kUnspecified: return NullabilityKind::UNSPECIFIED;
    case pasta::NullabilityKind::kNullableResult: return NullabilityKind::NULLABLE_RESULT;
  }
}

ObjCBridgeCastKind FromPasta(pasta::ObjCBridgeCastKind e) {
  switch (e) {
    case pasta::ObjCBridgeCastKind::kBridge: return ObjCBridgeCastKind::BRIDGE;
    case pasta::ObjCBridgeCastKind::kBridgeTransfer: return ObjCBridgeCastKind::BRIDGE_TRANSFER;
    case pasta::ObjCBridgeCastKind::kBridgeRetained: return ObjCBridgeCastKind::BRIDGE_RETAINED;
  }
}

ObjCDispatchMethodKind FromPasta(pasta::ObjCDispatchMethodKind e) {
  switch (e) {
    case pasta::ObjCDispatchMethodKind::kLegacy: return ObjCDispatchMethodKind::LEGACY;
    case pasta::ObjCDispatchMethodKind::kNonLegacy: return ObjCDispatchMethodKind::NON_LEGACY;
    case pasta::ObjCDispatchMethodKind::kMixed: return ObjCDispatchMethodKind::MIXED;
  }
}

ObjCInstanceTypeFamily FromPasta(pasta::ObjCInstanceTypeFamily e) {
  switch (e) {
    case pasta::ObjCInstanceTypeFamily::kNone: return ObjCInstanceTypeFamily::NONE;
    case pasta::ObjCInstanceTypeFamily::kArray: return ObjCInstanceTypeFamily::ARRAY;
    case pasta::ObjCInstanceTypeFamily::kDictionary: return ObjCInstanceTypeFamily::DICTIONARY;
    case pasta::ObjCInstanceTypeFamily::kSingleton: return ObjCInstanceTypeFamily::SINGLETON;
    case pasta::ObjCInstanceTypeFamily::kInitializer: return ObjCInstanceTypeFamily::INITIALIZER;
    case pasta::ObjCInstanceTypeFamily::kReturnsSelf: return ObjCInstanceTypeFamily::RETURNS_SELF;
  }
}

ObjCKeywordKind FromPasta(pasta::ObjCKeywordKind e) {
  switch (e) {
    case pasta::ObjCKeywordKind::kNotKeyword: return ObjCKeywordKind::NOT_KEYWORD;
    case pasta::ObjCKeywordKind::kClass: return ObjCKeywordKind::CLASS;
    case pasta::ObjCKeywordKind::kCompatibilityAlias: return ObjCKeywordKind::COMPATIBILITY_ALIAS;
    case pasta::ObjCKeywordKind::kDefinitions: return ObjCKeywordKind::DEFINITIONS;
    case pasta::ObjCKeywordKind::kEncode: return ObjCKeywordKind::ENCODE;
    case pasta::ObjCKeywordKind::kObjcEnd: return ObjCKeywordKind::OBJC_END;
    case pasta::ObjCKeywordKind::kImplementation: return ObjCKeywordKind::IMPLEMENTATION;
    case pasta::ObjCKeywordKind::kInterface: return ObjCKeywordKind::INTERFACE;
    case pasta::ObjCKeywordKind::kPrivate: return ObjCKeywordKind::PRIVATE;
    case pasta::ObjCKeywordKind::kProtected: return ObjCKeywordKind::PROTECTED;
    case pasta::ObjCKeywordKind::kProtocol: return ObjCKeywordKind::PROTOCOL;
    case pasta::ObjCKeywordKind::kPublic: return ObjCKeywordKind::PUBLIC;
    case pasta::ObjCKeywordKind::kSelector: return ObjCKeywordKind::SELECTOR;
    case pasta::ObjCKeywordKind::kThrow: return ObjCKeywordKind::THROW;
    case pasta::ObjCKeywordKind::kTry: return ObjCKeywordKind::TRY;
    case pasta::ObjCKeywordKind::kCatch: return ObjCKeywordKind::CATCH;
    case pasta::ObjCKeywordKind::kFinally: return ObjCKeywordKind::FINALLY;
    case pasta::ObjCKeywordKind::kSynchronized: return ObjCKeywordKind::SYNCHRONIZED;
    case pasta::ObjCKeywordKind::kAutoreleasepool: return ObjCKeywordKind::AUTORELEASEPOOL;
    case pasta::ObjCKeywordKind::kProperty: return ObjCKeywordKind::PROPERTY;
    case pasta::ObjCKeywordKind::kPackage: return ObjCKeywordKind::PACKAGE;
    case pasta::ObjCKeywordKind::kRequired: return ObjCKeywordKind::REQUIRED;
    case pasta::ObjCKeywordKind::kOptional: return ObjCKeywordKind::OPTIONAL;
    case pasta::ObjCKeywordKind::kSynthesize: return ObjCKeywordKind::SYNTHESIZE;
    case pasta::ObjCKeywordKind::kDynamic: return ObjCKeywordKind::DYNAMIC;
    case pasta::ObjCKeywordKind::kImport: return ObjCKeywordKind::IMPORT;
    case pasta::ObjCKeywordKind::kAvailable: return ObjCKeywordKind::AVAILABLE;
  }
}

ObjCLifetime FromPasta(pasta::ObjCLifetime e) {
  switch (e) {
    case pasta::ObjCLifetime::kNone: return ObjCLifetime::NONE;
    case pasta::ObjCLifetime::kExplicitNone: return ObjCLifetime::EXPLICIT_NONE;
    case pasta::ObjCLifetime::kStrong: return ObjCLifetime::STRONG;
    case pasta::ObjCLifetime::kWeak: return ObjCLifetime::WEAK;
    case pasta::ObjCLifetime::kAutoreleasing: return ObjCLifetime::AUTORELEASING;
  }
}

ObjCMethodFamily FromPasta(pasta::ObjCMethodFamily e) {
  switch (e) {
    case pasta::ObjCMethodFamily::kNone: return ObjCMethodFamily::NONE;
    case pasta::ObjCMethodFamily::kAlloc: return ObjCMethodFamily::ALLOC;
    case pasta::ObjCMethodFamily::kCopy: return ObjCMethodFamily::COPY;
    case pasta::ObjCMethodFamily::kInitializer: return ObjCMethodFamily::INITIALIZER;
    case pasta::ObjCMethodFamily::kMutableCopy: return ObjCMethodFamily::MUTABLE_COPY;
    case pasta::ObjCMethodFamily::kNew: return ObjCMethodFamily::NEW;
    case pasta::ObjCMethodFamily::kAutorelease: return ObjCMethodFamily::AUTORELEASE;
    case pasta::ObjCMethodFamily::kDealloc: return ObjCMethodFamily::DEALLOC;
    case pasta::ObjCMethodFamily::kFinalize: return ObjCMethodFamily::FINALIZE;
    case pasta::ObjCMethodFamily::kRelease: return ObjCMethodFamily::RELEASE;
    case pasta::ObjCMethodFamily::kRetain: return ObjCMethodFamily::RETAIN;
    case pasta::ObjCMethodFamily::kRetainCount: return ObjCMethodFamily::RETAIN_COUNT;
    case pasta::ObjCMethodFamily::kSelf: return ObjCMethodFamily::SELF;
    case pasta::ObjCMethodFamily::kInitialize: return ObjCMethodFamily::INITIALIZE;
    case pasta::ObjCMethodFamily::kPerformSelector: return ObjCMethodFamily::PERFORM_SELECTOR;
  }
}

ObjCPropertyQueryKind FromPasta(pasta::ObjCPropertyQueryKind e) {
  switch (e) {
    case pasta::ObjCPropertyQueryKind::kQueryUnknown: return ObjCPropertyQueryKind::QUERY_UNKNOWN;
    case pasta::ObjCPropertyQueryKind::kQueryInstance: return ObjCPropertyQueryKind::QUERY_INSTANCE;
    case pasta::ObjCPropertyQueryKind::kQueryClass: return ObjCPropertyQueryKind::QUERY_CLASS;
  }
}

ObjCStringFormatFamily FromPasta(pasta::ObjCStringFormatFamily e) {
  switch (e) {
    case pasta::ObjCStringFormatFamily::kNone: return ObjCStringFormatFamily::NONE;
    case pasta::ObjCStringFormatFamily::kNSString: return ObjCStringFormatFamily::NS_STRING;
    case pasta::ObjCStringFormatFamily::kCFString: return ObjCStringFormatFamily::CF_STRING;
  }
}

ObjCSubstitutionContext FromPasta(pasta::ObjCSubstitutionContext e) {
  switch (e) {
    case pasta::ObjCSubstitutionContext::kOrdinary: return ObjCSubstitutionContext::ORDINARY;
    case pasta::ObjCSubstitutionContext::kResult: return ObjCSubstitutionContext::RESULT;
    case pasta::ObjCSubstitutionContext::kParameter: return ObjCSubstitutionContext::PARAMETER;
    case pasta::ObjCSubstitutionContext::kProperty: return ObjCSubstitutionContext::PROPERTY;
    case pasta::ObjCSubstitutionContext::kSuperclass: return ObjCSubstitutionContext::SUPERCLASS;
  }
}

ObjCTypeParamVariance FromPasta(pasta::ObjCTypeParamVariance e) {
  switch (e) {
    case pasta::ObjCTypeParamVariance::kInvariant: return ObjCTypeParamVariance::INVARIANT;
    case pasta::ObjCTypeParamVariance::kCovariant: return ObjCTypeParamVariance::COVARIANT;
    case pasta::ObjCTypeParamVariance::kContravariant: return ObjCTypeParamVariance::CONTRAVARIANT;
  }
}

OnOffSwitch FromPasta(pasta::OnOffSwitch e) {
  switch (e) {
    case pasta::OnOffSwitch::kON: return OnOffSwitch::ON;
    case pasta::OnOffSwitch::kOFF: return OnOffSwitch::OFF;
    case pasta::OnOffSwitch::kDEFAULT: return OnOffSwitch::DEFAULT;
  }
}

OnStackType FromPasta(pasta::OnStackType e) {
  switch (e) {
    case pasta::OnStackType::kOnStack: return OnStackType::ON_STACK;
  }
}

OpenMPAtomicDefaultMemOrderClauseKind FromPasta(pasta::OpenMPAtomicDefaultMemOrderClauseKind e) {
  switch (e) {
    case pasta::OpenMPAtomicDefaultMemOrderClauseKind::kSeqCst: return OpenMPAtomicDefaultMemOrderClauseKind::SEQ_CST;
    case pasta::OpenMPAtomicDefaultMemOrderClauseKind::kAcqRel: return OpenMPAtomicDefaultMemOrderClauseKind::ACQ_REL;
    case pasta::OpenMPAtomicDefaultMemOrderClauseKind::kRelaxed: return OpenMPAtomicDefaultMemOrderClauseKind::RELAXED;
    case pasta::OpenMPAtomicDefaultMemOrderClauseKind::kUnknown: return OpenMPAtomicDefaultMemOrderClauseKind::UNKNOWN;
  }
}

OpenMPDefaultmapClauseKind FromPasta(pasta::OpenMPDefaultmapClauseKind e) {
  switch (e) {
    case pasta::OpenMPDefaultmapClauseKind::kScalar: return OpenMPDefaultmapClauseKind::SCALAR;
    case pasta::OpenMPDefaultmapClauseKind::kAggregate: return OpenMPDefaultmapClauseKind::AGGREGATE;
    case pasta::OpenMPDefaultmapClauseKind::kPointer: return OpenMPDefaultmapClauseKind::POINTER;
    case pasta::OpenMPDefaultmapClauseKind::kUnknown: return OpenMPDefaultmapClauseKind::UNKNOWN;
  }
}

OpenMPDefaultmapClauseModifier FromPasta(pasta::OpenMPDefaultmapClauseModifier e) {
  switch (e) {
    case pasta::OpenMPDefaultmapClauseModifier::kUnknown: return OpenMPDefaultmapClauseModifier::UNKNOWN;
    case pasta::OpenMPDefaultmapClauseModifier::kAlloc: return OpenMPDefaultmapClauseModifier::ALLOC;
    case pasta::OpenMPDefaultmapClauseModifier::kTo: return OpenMPDefaultmapClauseModifier::TO;
    case pasta::OpenMPDefaultmapClauseModifier::kFrom: return OpenMPDefaultmapClauseModifier::FROM;
    case pasta::OpenMPDefaultmapClauseModifier::kTofrom: return OpenMPDefaultmapClauseModifier::TOFROM;
    case pasta::OpenMPDefaultmapClauseModifier::kNone: return OpenMPDefaultmapClauseModifier::NONE;
    case pasta::OpenMPDefaultmapClauseModifier::kDefault: return OpenMPDefaultmapClauseModifier::DEFAULT;
    case pasta::OpenMPDefaultmapClauseModifier::kPresent: return OpenMPDefaultmapClauseModifier::PRESENT;
  }
}

OpenMPDependClauseKind FromPasta(pasta::OpenMPDependClauseKind e) {
  switch (e) {
    case pasta::OpenMPDependClauseKind::kIn: return OpenMPDependClauseKind::IN;
    case pasta::OpenMPDependClauseKind::kOut: return OpenMPDependClauseKind::OUT;
    case pasta::OpenMPDependClauseKind::kInout: return OpenMPDependClauseKind::INOUT;
    case pasta::OpenMPDependClauseKind::kMutexinoutset: return OpenMPDependClauseKind::MUTEXINOUTSET;
    case pasta::OpenMPDependClauseKind::kDepobj: return OpenMPDependClauseKind::DEPOBJ;
    case pasta::OpenMPDependClauseKind::kSource: return OpenMPDependClauseKind::SOURCE;
    case pasta::OpenMPDependClauseKind::kSink: return OpenMPDependClauseKind::SINK;
    case pasta::OpenMPDependClauseKind::kUnknown: return OpenMPDependClauseKind::UNKNOWN;
  }
}

OpenMPDeviceClauseModifier FromPasta(pasta::OpenMPDeviceClauseModifier e) {
  switch (e) {
    case pasta::OpenMPDeviceClauseModifier::kAncestor: return OpenMPDeviceClauseModifier::ANCESTOR;
    case pasta::OpenMPDeviceClauseModifier::kDeviceNum: return OpenMPDeviceClauseModifier::DEVICE_NUM;
    case pasta::OpenMPDeviceClauseModifier::kUnknown: return OpenMPDeviceClauseModifier::UNKNOWN;
  }
}

OpenMPDeviceType FromPasta(pasta::OpenMPDeviceType e) {
  switch (e) {
    case pasta::OpenMPDeviceType::kHost: return OpenMPDeviceType::HOST;
    case pasta::OpenMPDeviceType::kNohost: return OpenMPDeviceType::NOHOST;
    case pasta::OpenMPDeviceType::kAny: return OpenMPDeviceType::ANY;
    case pasta::OpenMPDeviceType::kUnknown: return OpenMPDeviceType::UNKNOWN;
  }
}

OpenMPDistScheduleClauseKind FromPasta(pasta::OpenMPDistScheduleClauseKind e) {
  switch (e) {
    case pasta::OpenMPDistScheduleClauseKind::kStatic: return OpenMPDistScheduleClauseKind::STATIC;
    case pasta::OpenMPDistScheduleClauseKind::kUnknown: return OpenMPDistScheduleClauseKind::UNKNOWN;
  }
}

OpenMPLastprivateModifier FromPasta(pasta::OpenMPLastprivateModifier e) {
  switch (e) {
    case pasta::OpenMPLastprivateModifier::kConditional: return OpenMPLastprivateModifier::CONDITIONAL;
    case pasta::OpenMPLastprivateModifier::kUnknown: return OpenMPLastprivateModifier::UNKNOWN;
  }
}

OpenMPLinearClauseKind FromPasta(pasta::OpenMPLinearClauseKind e) {
  switch (e) {
    case pasta::OpenMPLinearClauseKind::kVal: return OpenMPLinearClauseKind::VAL;
    case pasta::OpenMPLinearClauseKind::kReference: return OpenMPLinearClauseKind::REFERENCE;
    case pasta::OpenMPLinearClauseKind::kUval: return OpenMPLinearClauseKind::UVAL;
    case pasta::OpenMPLinearClauseKind::kUnknown: return OpenMPLinearClauseKind::UNKNOWN;
  }
}

OpenMPMapClauseKind FromPasta(pasta::OpenMPMapClauseKind e) {
  switch (e) {
    case pasta::OpenMPMapClauseKind::kAlloc: return OpenMPMapClauseKind::ALLOC;
    case pasta::OpenMPMapClauseKind::kTo: return OpenMPMapClauseKind::TO;
    case pasta::OpenMPMapClauseKind::kFrom: return OpenMPMapClauseKind::FROM;
    case pasta::OpenMPMapClauseKind::kTofrom: return OpenMPMapClauseKind::TOFROM;
    case pasta::OpenMPMapClauseKind::kDelete: return OpenMPMapClauseKind::DELETE;
    case pasta::OpenMPMapClauseKind::kRelease: return OpenMPMapClauseKind::RELEASE;
    case pasta::OpenMPMapClauseKind::kUnknown: return OpenMPMapClauseKind::UNKNOWN;
  }
}

OpenMPMapModifierKind FromPasta(pasta::OpenMPMapModifierKind e) {
  switch (e) {
    case pasta::OpenMPMapModifierKind::kUnknown: return OpenMPMapModifierKind::UNKNOWN;
    case pasta::OpenMPMapModifierKind::kAlways: return OpenMPMapModifierKind::ALWAYS;
    case pasta::OpenMPMapModifierKind::kClose: return OpenMPMapModifierKind::CLOSE;
    case pasta::OpenMPMapModifierKind::kMapper: return OpenMPMapModifierKind::MAPPER;
    case pasta::OpenMPMapModifierKind::kPresent: return OpenMPMapModifierKind::PRESENT;
  }
}

OpenMPMotionModifierKind FromPasta(pasta::OpenMPMotionModifierKind e) {
  switch (e) {
    case pasta::OpenMPMotionModifierKind::kMOTIONMODIFIERMapper: return OpenMPMotionModifierKind::MOTIONMODIFIER_MAPPER;
    case pasta::OpenMPMotionModifierKind::kMOTIONMODIFIERPresent: return OpenMPMotionModifierKind::MOTIONMODIFIER_PRESENT;
    case pasta::OpenMPMotionModifierKind::kMOTIONMODIFIERUnknown: return OpenMPMotionModifierKind::MOTIONMODIFIER_UNKNOWN;
  }
}

OpenMPOrderClauseKind FromPasta(pasta::OpenMPOrderClauseKind e) {
  switch (e) {
    case pasta::OpenMPOrderClauseKind::kConcurrent: return OpenMPOrderClauseKind::CONCURRENT;
    case pasta::OpenMPOrderClauseKind::kUnknown: return OpenMPOrderClauseKind::UNKNOWN;
  }
}

OpenMPReductionClauseModifier FromPasta(pasta::OpenMPReductionClauseModifier e) {
  switch (e) {
    case pasta::OpenMPReductionClauseModifier::kDefault: return OpenMPReductionClauseModifier::DEFAULT;
    case pasta::OpenMPReductionClauseModifier::kInscan: return OpenMPReductionClauseModifier::INSCAN;
    case pasta::OpenMPReductionClauseModifier::kTask: return OpenMPReductionClauseModifier::TASK;
    case pasta::OpenMPReductionClauseModifier::kUnknown: return OpenMPReductionClauseModifier::UNKNOWN;
  }
}

OpenMPScheduleClauseKind FromPasta(pasta::OpenMPScheduleClauseKind e) {
  switch (e) {
    case pasta::OpenMPScheduleClauseKind::kStatic: return OpenMPScheduleClauseKind::STATIC;
    case pasta::OpenMPScheduleClauseKind::kDynamic: return OpenMPScheduleClauseKind::DYNAMIC;
    case pasta::OpenMPScheduleClauseKind::kGuided: return OpenMPScheduleClauseKind::GUIDED;
    case pasta::OpenMPScheduleClauseKind::kAuto: return OpenMPScheduleClauseKind::AUTO;
    case pasta::OpenMPScheduleClauseKind::kRuntime: return OpenMPScheduleClauseKind::RUNTIME;
    case pasta::OpenMPScheduleClauseKind::kUnknown: return OpenMPScheduleClauseKind::UNKNOWN;
  }
}

OpenMPScheduleClauseModifier FromPasta(pasta::OpenMPScheduleClauseModifier e) {
  switch (e) {
    case pasta::OpenMPScheduleClauseModifier::kUnknown: return OpenMPScheduleClauseModifier::UNKNOWN;
    case pasta::OpenMPScheduleClauseModifier::kMonotonic: return OpenMPScheduleClauseModifier::MONOTONIC;
    case pasta::OpenMPScheduleClauseModifier::kNonmonotonic: return OpenMPScheduleClauseModifier::NONMONOTONIC;
    case pasta::OpenMPScheduleClauseModifier::kSimd: return OpenMPScheduleClauseModifier::SIMD;
  }
}

OptionType FromPasta(pasta::OptionType e) {
  switch (e) {
    case pasta::OptionType::kVectorize: return OptionType::VECTORIZE;
    case pasta::OptionType::kVectorizeWidth: return OptionType::VECTORIZE_WIDTH;
    case pasta::OptionType::kInterleave: return OptionType::INTERLEAVE;
    case pasta::OptionType::kInterleaveCount: return OptionType::INTERLEAVE_COUNT;
    case pasta::OptionType::kUnroll: return OptionType::UNROLL;
    case pasta::OptionType::kUnrollCount: return OptionType::UNROLL_COUNT;
    case pasta::OptionType::kUnrollAndJam: return OptionType::UNROLL_AND_JAM;
    case pasta::OptionType::kUnrollAndJamCount: return OptionType::UNROLL_AND_JAM_COUNT;
    case pasta::OptionType::kPipelineDisabled: return OptionType::PIPELINE_DISABLED;
    case pasta::OptionType::kPipelineInitiationInterval: return OptionType::PIPELINE_INITIATION_INTERVAL;
    case pasta::OptionType::kDistribute: return OptionType::DISTRIBUTE;
    case pasta::OptionType::kVectorizePredicate: return OptionType::VECTORIZE_PREDICATE;
  }
}

OverloadedOperatorKind FromPasta(pasta::OverloadedOperatorKind e) {
  switch (e) {
    case pasta::OverloadedOperatorKind::kNone: return OverloadedOperatorKind::NONE;
    case pasta::OverloadedOperatorKind::kNew: return OverloadedOperatorKind::NEW;
    case pasta::OverloadedOperatorKind::kDelete: return OverloadedOperatorKind::DELETE;
    case pasta::OverloadedOperatorKind::kArrayNew: return OverloadedOperatorKind::ARRAY_NEW;
    case pasta::OverloadedOperatorKind::kArrayDelete: return OverloadedOperatorKind::ARRAY_DELETE;
    case pasta::OverloadedOperatorKind::kPlus: return OverloadedOperatorKind::PLUS;
    case pasta::OverloadedOperatorKind::kMinus: return OverloadedOperatorKind::MINUS;
    case pasta::OverloadedOperatorKind::kStar: return OverloadedOperatorKind::STAR;
    case pasta::OverloadedOperatorKind::kSlash: return OverloadedOperatorKind::SLASH;
    case pasta::OverloadedOperatorKind::kPercent: return OverloadedOperatorKind::PERCENT;
    case pasta::OverloadedOperatorKind::kCaret: return OverloadedOperatorKind::CARET;
    case pasta::OverloadedOperatorKind::kAmp: return OverloadedOperatorKind::AMP;
    case pasta::OverloadedOperatorKind::kPipe: return OverloadedOperatorKind::PIPE;
    case pasta::OverloadedOperatorKind::kTilde: return OverloadedOperatorKind::TILDE;
    case pasta::OverloadedOperatorKind::kExclaim: return OverloadedOperatorKind::EXCLAIM;
    case pasta::OverloadedOperatorKind::kEqual: return OverloadedOperatorKind::EQUAL;
    case pasta::OverloadedOperatorKind::kLess: return OverloadedOperatorKind::LESS;
    case pasta::OverloadedOperatorKind::kGreater: return OverloadedOperatorKind::GREATER;
    case pasta::OverloadedOperatorKind::kPlusEqual: return OverloadedOperatorKind::PLUS_EQUAL;
    case pasta::OverloadedOperatorKind::kMinusEqual: return OverloadedOperatorKind::MINUS_EQUAL;
    case pasta::OverloadedOperatorKind::kStarEqual: return OverloadedOperatorKind::STAR_EQUAL;
    case pasta::OverloadedOperatorKind::kSlashEqual: return OverloadedOperatorKind::SLASH_EQUAL;
    case pasta::OverloadedOperatorKind::kPercentEqual: return OverloadedOperatorKind::PERCENT_EQUAL;
    case pasta::OverloadedOperatorKind::kCaretEqual: return OverloadedOperatorKind::CARET_EQUAL;
    case pasta::OverloadedOperatorKind::kAmpEqual: return OverloadedOperatorKind::AMP_EQUAL;
    case pasta::OverloadedOperatorKind::kPipeEqual: return OverloadedOperatorKind::PIPE_EQUAL;
    case pasta::OverloadedOperatorKind::kLessLess: return OverloadedOperatorKind::LESS_LESS;
    case pasta::OverloadedOperatorKind::kGreaterGreater: return OverloadedOperatorKind::GREATER_GREATER;
    case pasta::OverloadedOperatorKind::kLessLessEqual: return OverloadedOperatorKind::LESS_LESS_EQUAL;
    case pasta::OverloadedOperatorKind::kGreaterGreaterEqual: return OverloadedOperatorKind::GREATER_GREATER_EQUAL;
    case pasta::OverloadedOperatorKind::kEqualEqual: return OverloadedOperatorKind::EQUAL_EQUAL;
    case pasta::OverloadedOperatorKind::kExclaimEqual: return OverloadedOperatorKind::EXCLAIM_EQUAL;
    case pasta::OverloadedOperatorKind::kLessEqual: return OverloadedOperatorKind::LESS_EQUAL;
    case pasta::OverloadedOperatorKind::kGreaterEqual: return OverloadedOperatorKind::GREATER_EQUAL;
    case pasta::OverloadedOperatorKind::kSpaceship: return OverloadedOperatorKind::SPACESHIP;
    case pasta::OverloadedOperatorKind::kAmpAmp: return OverloadedOperatorKind::AMP_AMP;
    case pasta::OverloadedOperatorKind::kPipePipe: return OverloadedOperatorKind::PIPE_PIPE;
    case pasta::OverloadedOperatorKind::kPlusPlus: return OverloadedOperatorKind::PLUS_PLUS;
    case pasta::OverloadedOperatorKind::kMinusMinus: return OverloadedOperatorKind::MINUS_MINUS;
    case pasta::OverloadedOperatorKind::kComma: return OverloadedOperatorKind::COMMA;
    case pasta::OverloadedOperatorKind::kArrowStar: return OverloadedOperatorKind::ARROW_STAR;
    case pasta::OverloadedOperatorKind::kArrow: return OverloadedOperatorKind::ARROW;
    case pasta::OverloadedOperatorKind::kCall: return OverloadedOperatorKind::CALL;
    case pasta::OverloadedOperatorKind::kSubscript: return OverloadedOperatorKind::SUBSCRIPT;
    case pasta::OverloadedOperatorKind::kConditional: return OverloadedOperatorKind::CONDITIONAL;
    case pasta::OverloadedOperatorKind::kCoawait: return OverloadedOperatorKind::COAWAIT;
  }
}

OverloadsShown FromPasta(pasta::OverloadsShown e) {
  switch (e) {
    case pasta::OverloadsShown::kAll: return OverloadsShown::ALL;
    case pasta::OverloadsShown::kBest: return OverloadsShown::BEST;
  }
}

OwnershipKind FromPasta(pasta::OwnershipKind e) {
  switch (e) {
    case pasta::OwnershipKind::kHolds: return OwnershipKind::HOLDS;
    case pasta::OwnershipKind::kReturns: return OwnershipKind::RETURNS;
    case pasta::OwnershipKind::kTakes: return OwnershipKind::TAKES;
  }
}

PCSType FromPasta(pasta::PCSType e) {
  switch (e) {
    case pasta::PCSType::kAAPCS: return PCSType::AAPCS;
    case pasta::PCSType::kVFP: return PCSType::VFP;
  }
}

PPKeywordKind FromPasta(pasta::PPKeywordKind e) {
  switch (e) {
    case pasta::PPKeywordKind::kNotKeyword: return PPKeywordKind::NOT_KEYWORD;
    case pasta::PPKeywordKind::kIf: return PPKeywordKind::IF;
    case pasta::PPKeywordKind::kIfdef: return PPKeywordKind::IFDEF;
    case pasta::PPKeywordKind::kIfndef: return PPKeywordKind::IFNDEF;
    case pasta::PPKeywordKind::kElif: return PPKeywordKind::ELIF;
    case pasta::PPKeywordKind::kElifdef: return PPKeywordKind::ELIFDEF;
    case pasta::PPKeywordKind::kElifndef: return PPKeywordKind::ELIFNDEF;
    case pasta::PPKeywordKind::kElse: return PPKeywordKind::ELSE;
    case pasta::PPKeywordKind::kEndif: return PPKeywordKind::ENDIF;
    case pasta::PPKeywordKind::kDefined: return PPKeywordKind::DEFINED;
    case pasta::PPKeywordKind::kInclude: return PPKeywordKind::INCLUDE;
    case pasta::PPKeywordKind::k__IncludeMacros: return PPKeywordKind::__INCLUDE_MACROS;
    case pasta::PPKeywordKind::kDefine: return PPKeywordKind::DEFINE;
    case pasta::PPKeywordKind::kUndef: return PPKeywordKind::UNDEF;
    case pasta::PPKeywordKind::kLine: return PPKeywordKind::LINE;
    case pasta::PPKeywordKind::kError: return PPKeywordKind::ERROR;
    case pasta::PPKeywordKind::kPragma: return PPKeywordKind::PRAGMA;
    case pasta::PPKeywordKind::kImport: return PPKeywordKind::IMPORT;
    case pasta::PPKeywordKind::kIncludeNext: return PPKeywordKind::INCLUDE_NEXT;
    case pasta::PPKeywordKind::kWarning: return PPKeywordKind::WARNING;
    case pasta::PPKeywordKind::kIdentifier: return PPKeywordKind::IDENTIFIER;
    case pasta::PPKeywordKind::kSccs: return PPKeywordKind::SCCS;
    case pasta::PPKeywordKind::kAssert: return PPKeywordKind::ASSERT;
    case pasta::PPKeywordKind::kUnassert: return PPKeywordKind::UNASSERT;
    case pasta::PPKeywordKind::k__PublicMacro: return PPKeywordKind::__PUBLIC_MACRO;
    case pasta::PPKeywordKind::k__PrivateMacro: return PPKeywordKind::__PRIVATE_MACRO;
  }
}

ParameterABI FromPasta(pasta::ParameterABI e) {
  switch (e) {
    case pasta::ParameterABI::kOrdinary: return ParameterABI::ORDINARY;
    case pasta::ParameterABI::kSwiftIndirectResult: return ParameterABI::SWIFT_INDIRECT_RESULT;
    case pasta::ParameterABI::kSwiftErrorResult: return ParameterABI::SWIFT_ERROR_RESULT;
    case pasta::ParameterABI::kSwiftContext: return ParameterABI::SWIFT_CONTEXT;
    case pasta::ParameterABI::kSwiftAsyncContext: return ParameterABI::SWIFT_ASYNC_CONTEXT;
  }
}

ParenLocsOffsets FromPasta(pasta::ParenLocsOffsets e) {
  switch (e) {
    case pasta::ParenLocsOffsets::kLParen: return ParenLocsOffsets::L_PAREN;
    case pasta::ParenLocsOffsets::kRParen: return ParenLocsOffsets::R_PAREN;
    case pasta::ParenLocsOffsets::kTotal: return ParenLocsOffsets::TOTAL;
  }
}

PragmaFloatControlKind FromPasta(pasta::PragmaFloatControlKind e) {
  switch (e) {
    case pasta::PragmaFloatControlKind::kUnknown: return PragmaFloatControlKind::UNKNOWN;
    case pasta::PragmaFloatControlKind::kPrecise: return PragmaFloatControlKind::PRECISE;
    case pasta::PragmaFloatControlKind::kNoPrecise: return PragmaFloatControlKind::NO_PRECISE;
    case pasta::PragmaFloatControlKind::kExcept: return PragmaFloatControlKind::EXCEPT;
    case pasta::PragmaFloatControlKind::kNoExcept: return PragmaFloatControlKind::NO_EXCEPT;
    case pasta::PragmaFloatControlKind::kPush: return PragmaFloatControlKind::PUSH;
    case pasta::PragmaFloatControlKind::kPop: return PragmaFloatControlKind::POP;
  }
}

PragmaMSCommentKind FromPasta(pasta::PragmaMSCommentKind e) {
  switch (e) {
    case pasta::PragmaMSCommentKind::kUnknown: return PragmaMSCommentKind::UNKNOWN;
    case pasta::PragmaMSCommentKind::kLinker: return PragmaMSCommentKind::LINKER;
    case pasta::PragmaMSCommentKind::kLib: return PragmaMSCommentKind::LIB;
    case pasta::PragmaMSCommentKind::kCompiler: return PragmaMSCommentKind::COMPILER;
    case pasta::PragmaMSCommentKind::kExeString: return PragmaMSCommentKind::EXE_STRING;
    case pasta::PragmaMSCommentKind::kUser: return PragmaMSCommentKind::USER;
  }
}

PragmaMSPointersToMembersKind FromPasta(pasta::PragmaMSPointersToMembersKind e) {
  switch (e) {
    case pasta::PragmaMSPointersToMembersKind::kBestCase: return PragmaMSPointersToMembersKind::BEST_CASE;
    case pasta::PragmaMSPointersToMembersKind::kFullGeneralitySingleInheritance: return PragmaMSPointersToMembersKind::FULL_GENERALITY_SINGLE_INHERITANCE;
    case pasta::PragmaMSPointersToMembersKind::kFullGeneralityMultipleInheritance: return PragmaMSPointersToMembersKind::FULL_GENERALITY_MULTIPLE_INHERITANCE;
    case pasta::PragmaMSPointersToMembersKind::kFullGeneralityVirtualInheritance: return PragmaMSPointersToMembersKind::FULL_GENERALITY_VIRTUAL_INHERITANCE;
  }
}

PragmaMSStructKind FromPasta(pasta::PragmaMSStructKind e) {
  switch (e) {
    case pasta::PragmaMSStructKind::kOFF: return PragmaMSStructKind::OFF;
    case pasta::PragmaMSStructKind::kON: return PragmaMSStructKind::ON;
  }
}

PragmaSectionFlag FromPasta(pasta::PragmaSectionFlag e) {
  switch (e) {
    case pasta::PragmaSectionFlag::kNone: return PragmaSectionFlag::NONE;
    case pasta::PragmaSectionFlag::kRead: return PragmaSectionFlag::READ;
    case pasta::PragmaSectionFlag::kWrite: return PragmaSectionFlag::WRITE;
    case pasta::PragmaSectionFlag::kExecute: return PragmaSectionFlag::EXECUTE;
    case pasta::PragmaSectionFlag::kImplicit: return PragmaSectionFlag::IMPLICIT;
    case pasta::PragmaSectionFlag::kZeroInitializer: return PragmaSectionFlag::ZERO_INITIALIZER;
    case pasta::PragmaSectionFlag::kInvalid: return PragmaSectionFlag::INVALID;
  }
}

ProfileInstrKind FromPasta(pasta::ProfileInstrKind e) {
  switch (e) {
    case pasta::ProfileInstrKind::kProfileNone: return ProfileInstrKind::PROFILE_NONE;
    case pasta::ProfileInstrKind::kProfileClangInstr: return ProfileInstrKind::PROFILE_CLANG_INSTR;
    case pasta::ProfileInstrKind::kProfileIRInstr: return ProfileInstrKind::PROFILE_IR_INSTR;
    case pasta::ProfileInstrKind::kProfileCSIRInstr: return ProfileInstrKind::PROFILE_CSIR_INSTR;
  }
}

RangeExprOffset FromPasta(pasta::RangeExprOffset e) {
  switch (e) {
    case pasta::RangeExprOffset::kBegin: return RangeExprOffset::BEGIN;
    case pasta::RangeExprOffset::kEnd: return RangeExprOffset::END;
    case pasta::RangeExprOffset::kStep: return RangeExprOffset::STEP;
    case pasta::RangeExprOffset::kTotal: return RangeExprOffset::TOTAL;
  }
}

RangeLocOffset FromPasta(pasta::RangeLocOffset e) {
  switch (e) {
    case pasta::RangeLocOffset::kAssignToken: return RangeLocOffset::ASSIGN_TOKEN;
    case pasta::RangeLocOffset::kSecondColonToken: return RangeLocOffset::SECOND_COLON_TOKEN;
    case pasta::RangeLocOffset::kTotal: return RangeLocOffset::TOTAL;
  }
}

RefQualifierKind FromPasta(pasta::RefQualifierKind e) {
  switch (e) {
    case pasta::RefQualifierKind::kNone: return RefQualifierKind::NONE;
    case pasta::RefQualifierKind::kLValue: return RefQualifierKind::L_VALUE;
    case pasta::RefQualifierKind::kRValue: return RefQualifierKind::R_VALUE;
  }
}

RemarkKind FromPasta(pasta::RemarkKind e) {
  switch (e) {
    case pasta::RemarkKind::kMissing: return RemarkKind::MISSING;
    case pasta::RemarkKind::kEnabled: return RemarkKind::ENABLED;
    case pasta::RemarkKind::kEnabledEverything: return RemarkKind::ENABLED_EVERYTHING;
    case pasta::RemarkKind::kDisabled: return RemarkKind::DISABLED;
    case pasta::RemarkKind::kDisabledEverything: return RemarkKind::DISABLED_EVERYTHING;
    case pasta::RemarkKind::kWithPattern: return RemarkKind::WITH_PATTERN;
  }
}

ReservedIdentifierStatus FromPasta(pasta::ReservedIdentifierStatus e) {
  switch (e) {
    case pasta::ReservedIdentifierStatus::kNotReserved: return ReservedIdentifierStatus::NOT_RESERVED;
    case pasta::ReservedIdentifierStatus::kStartsWithUnderscoreAtGlobalScope: return ReservedIdentifierStatus::STARTS_WITH_UNDERSCORE_AT_GLOBAL_SCOPE;
    case pasta::ReservedIdentifierStatus::kStartsWithDoubleUnderscore: return ReservedIdentifierStatus::STARTS_WITH_DOUBLE_UNDERSCORE;
    case pasta::ReservedIdentifierStatus::kStartsWithUnderscoreFollowedByCapitalLetter: return ReservedIdentifierStatus::STARTS_WITH_UNDERSCORE_FOLLOWED_BY_CAPITAL_LETTER;
    case pasta::ReservedIdentifierStatus::kContainsDoubleUnderscore: return ReservedIdentifierStatus::CONTAINS_DOUBLE_UNDERSCORE;
  }
}

SFINAEResponse FromPasta(pasta::SFINAEResponse e) {
  switch (e) {
    case pasta::SFINAEResponse::kSubstitutionFailure: return SFINAEResponse::SUBSTITUTION_FAILURE;
    case pasta::SFINAEResponse::kSuppress: return SFINAEResponse::SUPPRESS;
    case pasta::SFINAEResponse::kReport: return SFINAEResponse::REPORT;
    case pasta::SFINAEResponse::kAccessControl: return SFINAEResponse::ACCESS_CONTROL;
  }
}

SYCLMajorVersion FromPasta(pasta::SYCLMajorVersion e) {
  switch (e) {
    case pasta::SYCLMajorVersion::kNone: return SYCLMajorVersion::VERSION_NONE;
    case pasta::SYCLMajorVersion::k2017: return SYCLMajorVersion::VERSION2017;
    case pasta::SYCLMajorVersion::k2020: return SYCLMajorVersion::VERSION2020;
  }
}

SanitizerOrdinal FromPasta(pasta::SanitizerOrdinal e) {
  switch (e) {
    case pasta::SanitizerOrdinal::kAddress: return SanitizerOrdinal::ADDRESS;
    case pasta::SanitizerOrdinal::kPointerCompare: return SanitizerOrdinal::POINTER_COMPARE;
    case pasta::SanitizerOrdinal::kPointerSubtract: return SanitizerOrdinal::POINTER_SUBTRACT;
    case pasta::SanitizerOrdinal::kKernelAddress: return SanitizerOrdinal::KERNEL_ADDRESS;
    case pasta::SanitizerOrdinal::kHWAddress: return SanitizerOrdinal::HW_ADDRESS;
    case pasta::SanitizerOrdinal::kKernelHWAddress: return SanitizerOrdinal::KERNEL_HW_ADDRESS;
    case pasta::SanitizerOrdinal::kMemoryTag: return SanitizerOrdinal::MEMORY_TAG;
    case pasta::SanitizerOrdinal::kMemory: return SanitizerOrdinal::MEMORY;
    case pasta::SanitizerOrdinal::kKernelMemory: return SanitizerOrdinal::KERNEL_MEMORY;
    case pasta::SanitizerOrdinal::kFuzzer: return SanitizerOrdinal::FUZZER;
    case pasta::SanitizerOrdinal::kFuzzerNoLink: return SanitizerOrdinal::FUZZER_NO_LINK;
    case pasta::SanitizerOrdinal::kThread: return SanitizerOrdinal::THREAD;
    case pasta::SanitizerOrdinal::kLeak: return SanitizerOrdinal::LEAK;
    case pasta::SanitizerOrdinal::kAlignment: return SanitizerOrdinal::ALIGNMENT;
    case pasta::SanitizerOrdinal::kArrayBounds: return SanitizerOrdinal::ARRAY_BOUNDS;
    case pasta::SanitizerOrdinal::kBoolean: return SanitizerOrdinal::BOOLEAN;
    case pasta::SanitizerOrdinal::kBuiltin: return SanitizerOrdinal::BUILTIN;
    case pasta::SanitizerOrdinal::kEnum: return SanitizerOrdinal::ENUM;
    case pasta::SanitizerOrdinal::kFloatCastOverflow: return SanitizerOrdinal::FLOAT_CAST_OVERFLOW;
    case pasta::SanitizerOrdinal::kFloatDivideByZero: return SanitizerOrdinal::FLOAT_DIVIDE_BY_ZERO;
    case pasta::SanitizerOrdinal::kFunction: return SanitizerOrdinal::FUNCTION;
    case pasta::SanitizerOrdinal::kIntegerDivideByZero: return SanitizerOrdinal::INTEGER_DIVIDE_BY_ZERO;
    case pasta::SanitizerOrdinal::kNonnullAttribute: return SanitizerOrdinal::NONNULL_ATTRIBUTE;
    case pasta::SanitizerOrdinal::kNull: return SanitizerOrdinal::NULL__;
    case pasta::SanitizerOrdinal::kNullabilityArgument: return SanitizerOrdinal::NULLABILITY_ARGUMENT;
    case pasta::SanitizerOrdinal::kNullabilityAssign: return SanitizerOrdinal::NULLABILITY_ASSIGN;
    case pasta::SanitizerOrdinal::kNullabilityReturn: return SanitizerOrdinal::NULLABILITY_RETURN;
    case pasta::SanitizerOrdinal::kNullabilityGroup: return SanitizerOrdinal::NULLABILITY_GROUP;
    case pasta::SanitizerOrdinal::kObjectSize: return SanitizerOrdinal::OBJECT_SIZE;
    case pasta::SanitizerOrdinal::kPointerOverflow: return SanitizerOrdinal::POINTER_OVERFLOW;
    case pasta::SanitizerOrdinal::kReturn: return SanitizerOrdinal::RETURN;
    case pasta::SanitizerOrdinal::kReturnsNonnullAttribute: return SanitizerOrdinal::RETURNS_NONNULL_ATTRIBUTE;
    case pasta::SanitizerOrdinal::kShiftBase: return SanitizerOrdinal::SHIFT_BASE;
    case pasta::SanitizerOrdinal::kShiftExponent: return SanitizerOrdinal::SHIFT_EXPONENT;
    case pasta::SanitizerOrdinal::kShiftGroup: return SanitizerOrdinal::SHIFT_GROUP;
    case pasta::SanitizerOrdinal::kSignedIntegerOverflow: return SanitizerOrdinal::SIGNED_INTEGER_OVERFLOW;
    case pasta::SanitizerOrdinal::kUnreachable: return SanitizerOrdinal::UNREACHABLE;
    case pasta::SanitizerOrdinal::kVLABound: return SanitizerOrdinal::VLA_BOUND;
    case pasta::SanitizerOrdinal::kVptr: return SanitizerOrdinal::VPTR;
    case pasta::SanitizerOrdinal::kUnsignedIntegerOverflow: return SanitizerOrdinal::UNSIGNED_INTEGER_OVERFLOW;
    case pasta::SanitizerOrdinal::kUnsignedShiftBase: return SanitizerOrdinal::UNSIGNED_SHIFT_BASE;
    case pasta::SanitizerOrdinal::kDataFlow: return SanitizerOrdinal::DATA_FLOW;
    case pasta::SanitizerOrdinal::kCFICastStrict: return SanitizerOrdinal::CFI_CAST_STRICT;
    case pasta::SanitizerOrdinal::kCFIDerivedCast: return SanitizerOrdinal::CFI_DERIVED_CAST;
    case pasta::SanitizerOrdinal::kCFIICall: return SanitizerOrdinal::CFII_CALL;
    case pasta::SanitizerOrdinal::kCFIMFCall: return SanitizerOrdinal::CFIMF_CALL;
    case pasta::SanitizerOrdinal::kCFIUnrelatedCast: return SanitizerOrdinal::CFI_UNRELATED_CAST;
    case pasta::SanitizerOrdinal::kCFINVCall: return SanitizerOrdinal::CFINV_CALL;
    case pasta::SanitizerOrdinal::kCFIVCall: return SanitizerOrdinal::CFIV_CALL;
    case pasta::SanitizerOrdinal::kCFIGroup: return SanitizerOrdinal::CFI_GROUP;
    case pasta::SanitizerOrdinal::kSafeStack: return SanitizerOrdinal::SAFE_STACK;
    case pasta::SanitizerOrdinal::kShadowCallStack: return SanitizerOrdinal::SHADOW_CALL_STACK;
    case pasta::SanitizerOrdinal::kUndefinedGroup: return SanitizerOrdinal::UNDEFINED_GROUP;
    case pasta::SanitizerOrdinal::kUndefinedTrapGroup: return SanitizerOrdinal::UNDEFINED_TRAP_GROUP;
    case pasta::SanitizerOrdinal::kImplicitUnsignedIntegerTruncation: return SanitizerOrdinal::IMPLICIT_UNSIGNED_INTEGER_TRUNCATION;
    case pasta::SanitizerOrdinal::kImplicitSignedIntegerTruncation: return SanitizerOrdinal::IMPLICIT_SIGNED_INTEGER_TRUNCATION;
    case pasta::SanitizerOrdinal::kImplicitIntegerTruncationGroup: return SanitizerOrdinal::IMPLICIT_INTEGER_TRUNCATION_GROUP;
    case pasta::SanitizerOrdinal::kImplicitIntegerSignChange: return SanitizerOrdinal::IMPLICIT_INTEGER_SIGN_CHANGE;
    case pasta::SanitizerOrdinal::kImplicitIntegerArithmeticValueChangeGroup: return SanitizerOrdinal::IMPLICIT_INTEGER_ARITHMETIC_VALUE_CHANGE_GROUP;
    case pasta::SanitizerOrdinal::kObjCCast: return SanitizerOrdinal::OBJ_C_CAST;
    case pasta::SanitizerOrdinal::kImplicitConversionGroup: return SanitizerOrdinal::IMPLICIT_CONVERSION_GROUP;
    case pasta::SanitizerOrdinal::kIntegerGroup: return SanitizerOrdinal::INTEGER_GROUP;
    case pasta::SanitizerOrdinal::kLocalBounds: return SanitizerOrdinal::LOCAL_BOUNDS;
    case pasta::SanitizerOrdinal::kBoundsGroup: return SanitizerOrdinal::BOUNDS_GROUP;
    case pasta::SanitizerOrdinal::kScudo: return SanitizerOrdinal::SCUDO;
    case pasta::SanitizerOrdinal::kAllGroup: return SanitizerOrdinal::ALL_GROUP;
    case pasta::SanitizerOrdinal::kCount: return SanitizerOrdinal::COUNT;
  }
}

SelectorLocationsKind FromPasta(pasta::SelectorLocationsKind e) {
  switch (e) {
    case pasta::SelectorLocationsKind::kNonStandard: return SelectorLocationsKind::NON_STANDARD;
    case pasta::SelectorLocationsKind::kStandardNoSpace: return SelectorLocationsKind::STANDARD_NO_SPACE;
    case pasta::SelectorLocationsKind::kStandardWithSpace: return SelectorLocationsKind::STANDARD_WITH_SPACE;
  }
}

SignReturnAddressKeyKind FromPasta(pasta::SignReturnAddressKeyKind e) {
  switch (e) {
    case pasta::SignReturnAddressKeyKind::kAKey: return SignReturnAddressKeyKind::A_KEY;
    case pasta::SignReturnAddressKeyKind::kBKey: return SignReturnAddressKeyKind::B_KEY;
  }
}

SignReturnAddressScopeKind FromPasta(pasta::SignReturnAddressScopeKind e) {
  switch (e) {
    case pasta::SignReturnAddressScopeKind::kNone: return SignReturnAddressScopeKind::NONE;
    case pasta::SignReturnAddressScopeKind::kNonLeaf: return SignReturnAddressScopeKind::NON_LEAF;
    case pasta::SignReturnAddressScopeKind::kAll: return SignReturnAddressScopeKind::ALL;
  }
}

SignedOverflowBehaviorTy FromPasta(pasta::SignedOverflowBehaviorTy e) {
  switch (e) {
    case pasta::SignedOverflowBehaviorTy::kUndefined: return SignedOverflowBehaviorTy::UNDEFINED;
    case pasta::SignedOverflowBehaviorTy::kDefined: return SignedOverflowBehaviorTy::DEFINED;
    case pasta::SignedOverflowBehaviorTy::kTrapping: return SignedOverflowBehaviorTy::TRAPPING;
  }
}

SpecialMemberFlags FromPasta(pasta::SpecialMemberFlags e) {
  switch (e) {
    case pasta::SpecialMemberFlags::kDefaultConstructor: return SpecialMemberFlags::DEFAULT_CONSTRUCTOR;
    case pasta::SpecialMemberFlags::kCopyConstructor: return SpecialMemberFlags::COPY_CONSTRUCTOR;
    case pasta::SpecialMemberFlags::kMoveConstructor: return SpecialMemberFlags::MOVE_CONSTRUCTOR;
    case pasta::SpecialMemberFlags::kCopyAssignment: return SpecialMemberFlags::COPY_ASSIGNMENT;
    case pasta::SpecialMemberFlags::kMoveAssignment: return SpecialMemberFlags::MOVE_ASSIGNMENT;
    case pasta::SpecialMemberFlags::kDestructor: return SpecialMemberFlags::DESTRUCTOR;
    case pasta::SpecialMemberFlags::kAll: return SpecialMemberFlags::ALL;
  }
}

SpecifierKind FromPasta(pasta::SpecifierKind e) {
  switch (e) {
    case pasta::SpecifierKind::kIdentifier: return SpecifierKind::IDENTIFIER;
    case pasta::SpecifierKind::kNamespace: return SpecifierKind::NAMESPACE;
    case pasta::SpecifierKind::kNamespaceAlias: return SpecifierKind::NAMESPACE_ALIAS;
    case pasta::SpecifierKind::kTypeSpec: return SpecifierKind::TYPE_SPEC;
    case pasta::SpecifierKind::kTypeSpecWithTemplate: return SpecifierKind::TYPE_SPEC_WITH_TEMPLATE;
    case pasta::SpecifierKind::kGlobal: return SpecifierKind::GLOBAL;
    case pasta::SpecifierKind::kSuper: return SpecifierKind::SUPER;
  }
}

Spelling FromPasta(pasta::Spelling e) {
  switch (e) {
    case pasta::Spelling::kGNUAarch64VectorPcs: return Spelling::GNU_AARCH64_VECTOR_PCS;
    case pasta::Spelling::kCXX11ClangAarch64VectorPcs: return Spelling::CX_X11_CLANG_AARCH64_VECTOR_PCS;
    case pasta::Spelling::kC2xClangAarch64VectorPcs: return Spelling::C2_XCLANG_AARCH64_VECTOR_PCS;
    case pasta::Spelling::kSpellingNotCalculated: return Spelling::SPELLING_NOT_CALCULATED;
  }
}

StackProtectorMode FromPasta(pasta::StackProtectorMode e) {
  switch (e) {
    case pasta::StackProtectorMode::kOff: return StackProtectorMode::OFF;
    case pasta::StackProtectorMode::kOn: return StackProtectorMode::ON;
    case pasta::StackProtectorMode::kStrong: return StackProtectorMode::STRONG;
    case pasta::StackProtectorMode::kReq: return StackProtectorMode::REQ;
  }
}

StorageClass FromPasta(pasta::StorageClass e) {
  switch (e) {
    case pasta::StorageClass::kNone: return StorageClass::NONE;
    case pasta::StorageClass::kExtern: return StorageClass::EXTERN;
    case pasta::StorageClass::kStatic: return StorageClass::STATIC;
    case pasta::StorageClass::kPrivateExtern: return StorageClass::PRIVATE_EXTERN;
    case pasta::StorageClass::kAuto: return StorageClass::AUTO;
    case pasta::StorageClass::kRegister: return StorageClass::REGISTER;
  }
}

StorageDuration FromPasta(pasta::StorageDuration e) {
  switch (e) {
    case pasta::StorageDuration::kFullExpression: return StorageDuration::FULL_EXPRESSION;
    case pasta::StorageDuration::kAutomatic: return StorageDuration::AUTOMATIC;
    case pasta::StorageDuration::kThread: return StorageDuration::THREAD;
    case pasta::StorageDuration::kStatic: return StorageDuration::STATIC;
    case pasta::StorageDuration::kDynamic: return StorageDuration::DYNAMIC;
  }
}

StoredNameKind FromPasta(pasta::StoredNameKind e) {
  switch (e) {
    case pasta::StoredNameKind::kStoredIdentifier: return StoredNameKind::STORED_IDENTIFIER;
    case pasta::StoredNameKind::kStoredObjCZeroArgumentSelector: return StoredNameKind::STORED_OBJ_C_ZERO_ARGUMENT_SELECTOR;
    case pasta::StoredNameKind::kStoredObjCOneArgumentSelector: return StoredNameKind::STORED_OBJ_C_ONE_ARGUMENT_SELECTOR;
    case pasta::StoredNameKind::kStoredCXXConstructorName: return StoredNameKind::STORED_CXX_CONSTRUCTOR_NAME;
    case pasta::StoredNameKind::kStoredCXXDestructorName: return StoredNameKind::STORED_CXX_DESTRUCTOR_NAME;
    case pasta::StoredNameKind::kStoredCXXConversionFunctionName: return StoredNameKind::STORED_CXX_CONVERSION_FUNCTION_NAME;
    case pasta::StoredNameKind::kStoredCXXOperatorName: return StoredNameKind::STORED_CXX_OPERATOR_NAME;
    case pasta::StoredNameKind::kStoredDeclarationNameExtra: return StoredNameKind::STORED_DECLARATION_NAME_EXTRA;
    case pasta::StoredNameKind::kUncommonNameKindOffset: return StoredNameKind::UNCOMMON_NAME_KIND_OFFSET;
  }
}

StoredSpecifierKind FromPasta(pasta::StoredSpecifierKind e) {
  switch (e) {
    case pasta::StoredSpecifierKind::kStoredIdentifier: return StoredSpecifierKind::STORED_IDENTIFIER;
    case pasta::StoredSpecifierKind::kStoredDeclaration: return StoredSpecifierKind::STORED_DECLARATION;
    case pasta::StoredSpecifierKind::kStoredTypeSpec: return StoredSpecifierKind::STORED_TYPE_SPEC;
    case pasta::StoredSpecifierKind::kStoredTypeSpecWithTemplate: return StoredSpecifierKind::STORED_TYPE_SPEC_WITH_TEMPLATE;
  }
}

StructReturnConventionKind FromPasta(pasta::StructReturnConventionKind e) {
  switch (e) {
    case pasta::StructReturnConventionKind::kDefault: return StructReturnConventionKind::DEFAULT;
    case pasta::StructReturnConventionKind::kOnStack: return StructReturnConventionKind::ON_STACK;
    case pasta::StructReturnConventionKind::kInRegs: return StructReturnConventionKind::IN_REGS;
  }
}

SubExpr FromPasta(pasta::SubExpr e) {
  switch (e) {
    case pasta::SubExpr::kCallee: return SubExpr::CALLEE;
    case pasta::SubExpr::kLHS: return SubExpr::LHS;
    case pasta::SubExpr::kRHS: return SubExpr::RHS;
    case pasta::SubExpr::kCount: return SubExpr::COUNT;
  }
}

SubStmt FromPasta(pasta::SubStmt e) {
  switch (e) {
    case pasta::SubStmt::kBody: return SubStmt::BODY;
    case pasta::SubStmt::kPromise: return SubStmt::PROMISE;
    case pasta::SubStmt::kInitializerSuspend: return SubStmt::INITIALIZER_SUSPEND;
    case pasta::SubStmt::kFinalSuspend: return SubStmt::FINAL_SUSPEND;
    case pasta::SubStmt::kOnException: return SubStmt::ON_EXCEPTION;
    case pasta::SubStmt::kOnFallthrough: return SubStmt::ON_FALLTHROUGH;
    case pasta::SubStmt::kAllocate: return SubStmt::ALLOCATE;
    case pasta::SubStmt::kDeallocate: return SubStmt::DEALLOCATE;
    case pasta::SubStmt::kReturnValue: return SubStmt::RETURN_VALUE;
    case pasta::SubStmt::kResultDeclaration: return SubStmt::RESULT_DECLARATION;
    case pasta::SubStmt::kReturnStatement: return SubStmt::RETURN_STATEMENT;
    case pasta::SubStmt::kReturnStatementOnAllocFailure: return SubStmt::RETURN_STATEMENT_ON_ALLOC_FAILURE;
  }
}

SyncScope FromPasta(pasta::SyncScope e) {
  switch (e) {
    case pasta::SyncScope::kOpenCLWorkGroup: return SyncScope::OPEN_CL_WORK_GROUP;
    case pasta::SyncScope::kOpenCLDevice: return SyncScope::OPEN_CL_DEVICE;
    case pasta::SyncScope::kOpenCLAllSVMDevices: return SyncScope::OPEN_CL_ALL_SVM_DEVICES;
    case pasta::SyncScope::kOpenCLSubGroup: return SyncScope::OPEN_CL_SUB_GROUP;
  }
}

Syntax FromPasta(pasta::Syntax e) {
  switch (e) {
    case pasta::Syntax::kGNU: return Syntax::GNU;
    case pasta::Syntax::kCXX11: return Syntax::CX_X11;
    case pasta::Syntax::kC2x: return Syntax::C2_X;
    case pasta::Syntax::kDeclspec: return Syntax::DECLSPEC;
    case pasta::Syntax::kMicrosoft: return Syntax::MICROSOFT;
    case pasta::Syntax::kKeyword: return Syntax::KEYWORD;
    case pasta::Syntax::kPragma: return Syntax::PRAGMA;
    case pasta::Syntax::kContextSensitiveKeyword: return Syntax::CONTEXT_SENSITIVE_KEYWORD;
  }
}

TLSModel FromPasta(pasta::TLSModel e) {
  switch (e) {
    case pasta::TLSModel::kGeneralDynamicTLSModel: return TLSModel::GENERAL_DYNAMIC_TLS_MODEL;
    case pasta::TLSModel::kLocalDynamicTLSModel: return TLSModel::LOCAL_DYNAMIC_TLS_MODEL;
    case pasta::TLSModel::kInitialExecTLSModel: return TLSModel::INITIAL_EXEC_TLS_MODEL;
    case pasta::TLSModel::kLocalExecTLSModel: return TLSModel::LOCAL_EXEC_TLS_MODEL;
  }
}

TQ FromPasta(pasta::TQ e) {
  switch (e) {
    case pasta::TQ::kConst: return TQ::CONST;
    case pasta::TQ::kRestrict: return TQ::RESTRICT;
    case pasta::TQ::kVolatile: return TQ::VOLATILE;
    case pasta::TQ::kCVRMask: return TQ::CVR_MASK;
  }
}

TagTypeKind FromPasta(pasta::TagTypeKind e) {
  switch (e) {
    case pasta::TagTypeKind::kStruct: return TagTypeKind::STRUCT;
    case pasta::TagTypeKind::kInterface: return TagTypeKind::INTERFACE;
    case pasta::TagTypeKind::kUnion: return TagTypeKind::UNION;
    case pasta::TagTypeKind::kClass: return TagTypeKind::CLASS;
    case pasta::TagTypeKind::kEnum: return TagTypeKind::ENUM;
  }
}

TailPaddingUseRules FromPasta(pasta::TailPaddingUseRules e) {
  switch (e) {
    case pasta::TailPaddingUseRules::kAlwaysUseTailPadding: return TailPaddingUseRules::ALWAYS_USE_TAIL_PADDING;
    case pasta::TailPaddingUseRules::kUseTailPaddingUnlessPOD03: return TailPaddingUseRules::USE_TAIL_PADDING_UNLESS_PO_D03;
    case pasta::TailPaddingUseRules::kUseTailPaddingUnlessPOD11: return TailPaddingUseRules::USE_TAIL_PADDING_UNLESS_PO_D11;
  }
}

TemplateArgumentDependence FromPasta(pasta::TemplateArgumentDependence e) {
  switch (e) {
    case pasta::TemplateArgumentDependence::kUnexpandedPack: return TemplateArgumentDependence::UNEXPANDED_PACK;
    case pasta::TemplateArgumentDependence::kInstantiation: return TemplateArgumentDependence::INSTANTIATION;
    case pasta::TemplateArgumentDependence::kDependent: return TemplateArgumentDependence::DEPENDENT;
    case pasta::TemplateArgumentDependence::kError: return TemplateArgumentDependence::ERROR;
    case pasta::TemplateArgumentDependence::kNone: return TemplateArgumentDependence::NONE;
    case pasta::TemplateArgumentDependence::kDependentInstantiation: return TemplateArgumentDependence::DEPENDENT_INSTANTIATION;
    case pasta::TemplateArgumentDependence::kAll: return TemplateArgumentDependence::ALL;
  }
}

TemplateNameDependence FromPasta(pasta::TemplateNameDependence e) {
  switch (e) {
    case pasta::TemplateNameDependence::kUnexpandedPack: return TemplateNameDependence::UNEXPANDED_PACK;
    case pasta::TemplateNameDependence::kInstantiation: return TemplateNameDependence::INSTANTIATION;
    case pasta::TemplateNameDependence::kDependent: return TemplateNameDependence::DEPENDENT;
    case pasta::TemplateNameDependence::kError: return TemplateNameDependence::ERROR;
    case pasta::TemplateNameDependence::kNone: return TemplateNameDependence::NONE;
    case pasta::TemplateNameDependence::kDependentInstantiation: return TemplateNameDependence::DEPENDENT_INSTANTIATION;
    case pasta::TemplateNameDependence::kAll: return TemplateNameDependence::ALL;
  }
}

TemplateSpecializationKind FromPasta(pasta::TemplateSpecializationKind e) {
  switch (e) {
    case pasta::TemplateSpecializationKind::kUndeclared: return TemplateSpecializationKind::UNDECLARED;
    case pasta::TemplateSpecializationKind::kImplicitInstantiation: return TemplateSpecializationKind::IMPLICIT_INSTANTIATION;
    case pasta::TemplateSpecializationKind::kExplicitSpecialization: return TemplateSpecializationKind::EXPLICIT_SPECIALIZATION;
    case pasta::TemplateSpecializationKind::kExplicitInstantiationDeclaration: return TemplateSpecializationKind::EXPLICIT_INSTANTIATION_DECLARATION;
    case pasta::TemplateSpecializationKind::kExplicitInstantiationDefinition: return TemplateSpecializationKind::EXPLICIT_INSTANTIATION_DEFINITION;
  }
}

TextDiagnosticFormat FromPasta(pasta::TextDiagnosticFormat e) {
  switch (e) {
    case pasta::TextDiagnosticFormat::kClang: return TextDiagnosticFormat::CLANG;
    case pasta::TextDiagnosticFormat::kMSVC: return TextDiagnosticFormat::MSVC;
    case pasta::TextDiagnosticFormat::kVi: return TextDiagnosticFormat::VI;
  }
}

ThreadModelKind FromPasta(pasta::ThreadModelKind e) {
  switch (e) {
    case pasta::ThreadModelKind::kPOSIX: return ThreadModelKind::POSIX;
    case pasta::ThreadModelKind::kSingle: return ThreadModelKind::SINGLE;
  }
}

ThreadStorageClassSpecifier FromPasta(pasta::ThreadStorageClassSpecifier e) {
  switch (e) {
    case pasta::ThreadStorageClassSpecifier::kUnspecified: return ThreadStorageClassSpecifier::UNSPECIFIED;
    case pasta::ThreadStorageClassSpecifier::k__Thread: return ThreadStorageClassSpecifier::__THREAD;
    case pasta::ThreadStorageClassSpecifier::kThreadLocal: return ThreadStorageClassSpecifier::THREAD_LOCAL;
    case pasta::ThreadStorageClassSpecifier::k_ThreadLocal: return ThreadStorageClassSpecifier::_THREAD_LOCAL;
  }
}

TokenKind FromPasta(pasta::TokenKind e) {
  switch (e) {
    case pasta::TokenKind::kUnknown: return TokenKind::UNKNOWN;
    case pasta::TokenKind::kEndOfFile: return TokenKind::END_OF_FILE;
    case pasta::TokenKind::kEndOfDirective: return TokenKind::END_OF_DIRECTIVE;
    case pasta::TokenKind::kCodeCompletion: return TokenKind::CODE_COMPLETION;
    case pasta::TokenKind::kComment: return TokenKind::COMMENT;
    case pasta::TokenKind::kIdentifier: return TokenKind::IDENTIFIER;
    case pasta::TokenKind::kRawIdentifier: return TokenKind::IDENTIFIER;
    case pasta::TokenKind::kNumericConstant: return TokenKind::NUMERIC_CONSTANT;
    case pasta::TokenKind::kCharacterConstant: return TokenKind::CHARACTER_CONSTANT;
    case pasta::TokenKind::kWideCharacterConstant: return TokenKind::WIDE_CHARACTER_CONSTANT;
    case pasta::TokenKind::kUtf8CharacterConstant: return TokenKind::UTF8_CHARACTER_CONSTANT;
    case pasta::TokenKind::kUtf16CharacterConstant: return TokenKind::UTF16_CHARACTER_CONSTANT;
    case pasta::TokenKind::kUtf32CharacterConstant: return TokenKind::UTF32_CHARACTER_CONSTANT;
    case pasta::TokenKind::kStringLiteral: return TokenKind::STRING_LITERAL;
    case pasta::TokenKind::kWideStringLiteral: return TokenKind::WIDE_STRING_LITERAL;
    case pasta::TokenKind::kHeaderName: return TokenKind::HEADER_NAME;
    case pasta::TokenKind::kUtf8StringLiteral: return TokenKind::UTF8_STRING_LITERAL;
    case pasta::TokenKind::kUtf16StringLiteral: return TokenKind::UTF16_STRING_LITERAL;
    case pasta::TokenKind::kUtf32StringLiteral: return TokenKind::UTF32_STRING_LITERAL;
    case pasta::TokenKind::kLSquare: return TokenKind::L_SQUARE;
    case pasta::TokenKind::kRSquare: return TokenKind::R_SQUARE;
    case pasta::TokenKind::kLParenthesis: return TokenKind::L_PARENTHESIS;
    case pasta::TokenKind::kRParenthesis: return TokenKind::R_PARENTHESIS;
    case pasta::TokenKind::kLBrace: return TokenKind::L_BRACE;
    case pasta::TokenKind::kRBrace: return TokenKind::R_BRACE;
    case pasta::TokenKind::kPeriod: return TokenKind::PERIOD;
    case pasta::TokenKind::kEllipsis: return TokenKind::ELLIPSIS;
    case pasta::TokenKind::kAmp: return TokenKind::AMP;
    case pasta::TokenKind::kAmpAmp: return TokenKind::AMP_AMP;
    case pasta::TokenKind::kAmpEqual: return TokenKind::AMP_EQUAL;
    case pasta::TokenKind::kStar: return TokenKind::STAR;
    case pasta::TokenKind::kStarEqual: return TokenKind::STAR_EQUAL;
    case pasta::TokenKind::kPlus: return TokenKind::PLUS;
    case pasta::TokenKind::kPlusPlus: return TokenKind::PLUS_PLUS;
    case pasta::TokenKind::kPlusEqual: return TokenKind::PLUS_EQUAL;
    case pasta::TokenKind::kMinus: return TokenKind::MINUS;
    case pasta::TokenKind::kArrow: return TokenKind::ARROW;
    case pasta::TokenKind::kMinusMinus: return TokenKind::MINUS_MINUS;
    case pasta::TokenKind::kMinusEqual: return TokenKind::MINUS_EQUAL;
    case pasta::TokenKind::kTilde: return TokenKind::TILDE;
    case pasta::TokenKind::kExclaim: return TokenKind::EXCLAIM;
    case pasta::TokenKind::kExclaimEqual: return TokenKind::EXCLAIM_EQUAL;
    case pasta::TokenKind::kSlash: return TokenKind::SLASH;
    case pasta::TokenKind::kSlashEqual: return TokenKind::SLASH_EQUAL;
    case pasta::TokenKind::kPercent: return TokenKind::PERCENT;
    case pasta::TokenKind::kPercentEqual: return TokenKind::PERCENT_EQUAL;
    case pasta::TokenKind::kLess: return TokenKind::LESS;
    case pasta::TokenKind::kLessLess: return TokenKind::LESS_LESS;
    case pasta::TokenKind::kLessEqual: return TokenKind::LESS_EQUAL;
    case pasta::TokenKind::kLessLessEqual: return TokenKind::LESS_LESS_EQUAL;
    case pasta::TokenKind::kSpaceship: return TokenKind::SPACESHIP;
    case pasta::TokenKind::kGreater: return TokenKind::GREATER;
    case pasta::TokenKind::kGreaterGreater: return TokenKind::GREATER_GREATER;
    case pasta::TokenKind::kGreaterEqual: return TokenKind::GREATER_EQUAL;
    case pasta::TokenKind::kGreaterGreaterEqual: return TokenKind::GREATER_GREATER_EQUAL;
    case pasta::TokenKind::kCaret: return TokenKind::CARET;
    case pasta::TokenKind::kCaretEqual: return TokenKind::CARET_EQUAL;
    case pasta::TokenKind::kPipe: return TokenKind::PIPE;
    case pasta::TokenKind::kPipePipe: return TokenKind::PIPE_PIPE;
    case pasta::TokenKind::kPipeEqual: return TokenKind::PIPE_EQUAL;
    case pasta::TokenKind::kQuestion: return TokenKind::QUESTION;
    case pasta::TokenKind::kColon: return TokenKind::COLON;
    case pasta::TokenKind::kSemi: return TokenKind::SEMI;
    case pasta::TokenKind::kEqual: return TokenKind::EQUAL;
    case pasta::TokenKind::kEqualEqual: return TokenKind::EQUAL_EQUAL;
    case pasta::TokenKind::kComma: return TokenKind::COMMA;
    case pasta::TokenKind::kHash: return TokenKind::HASH;
    case pasta::TokenKind::kHashHash: return TokenKind::HASH_HASH;
    case pasta::TokenKind::kHashat: return TokenKind::HASHAT;
    case pasta::TokenKind::kPeriodStar: return TokenKind::PERIOD_STAR;
    case pasta::TokenKind::kArrowStar: return TokenKind::ARROW_STAR;
    case pasta::TokenKind::kColonColon: return TokenKind::COLON_COLON;
    case pasta::TokenKind::kAt: return TokenKind::AT;
    case pasta::TokenKind::kLessLessLess: return TokenKind::LESS_LESS_LESS;
    case pasta::TokenKind::kGreaterGreaterGreater: return TokenKind::GREATER_GREATER_GREATER;
    case pasta::TokenKind::kCaretcaret: return TokenKind::CARETCARET;
    case pasta::TokenKind::kKeywordAuto: return TokenKind::KEYWORD_AUTO;
    case pasta::TokenKind::kKeywordBreak: return TokenKind::KEYWORD_BREAK;
    case pasta::TokenKind::kKeywordCase: return TokenKind::KEYWORD_CASE;
    case pasta::TokenKind::kKeywordCharacter: return TokenKind::KEYWORD_CHARACTER;
    case pasta::TokenKind::kKeywordConst: return TokenKind::KEYWORD_CONST;
    case pasta::TokenKind::kKeywordContinue: return TokenKind::KEYWORD_CONTINUE;
    case pasta::TokenKind::kKeywordDefault: return TokenKind::KEYWORD_DEFAULT;
    case pasta::TokenKind::kKeywordDo: return TokenKind::KEYWORD_DO;
    case pasta::TokenKind::kKeywordDouble: return TokenKind::KEYWORD_DOUBLE;
    case pasta::TokenKind::kKeywordElse: return TokenKind::KEYWORD_ELSE;
    case pasta::TokenKind::kKeywordEnum: return TokenKind::KEYWORD_ENUM;
    case pasta::TokenKind::kKeywordExtern: return TokenKind::KEYWORD_EXTERN;
    case pasta::TokenKind::kKeywordFloat: return TokenKind::KEYWORD_FLOAT;
    case pasta::TokenKind::kKeywordFor: return TokenKind::KEYWORD_FOR;
    case pasta::TokenKind::kKeywordGoto: return TokenKind::KEYWORD_GOTO;
    case pasta::TokenKind::kKeywordIf: return TokenKind::KEYWORD_IF;
    case pasta::TokenKind::kKeywordInline: return TokenKind::KEYWORD_INLINE;
    case pasta::TokenKind::kKeywordInt: return TokenKind::KEYWORD_INT;
    case pasta::TokenKind::kKeyword_ExtInt: return TokenKind::KEYWORD__EXT_INT;
    case pasta::TokenKind::kKeywordLong: return TokenKind::KEYWORD_LONG;
    case pasta::TokenKind::kKeywordRegister: return TokenKind::KEYWORD_REGISTER;
    case pasta::TokenKind::kKeywordRestrict: return TokenKind::KEYWORD_RESTRICT;
    case pasta::TokenKind::kKeywordReturn: return TokenKind::KEYWORD_RETURN;
    case pasta::TokenKind::kKeywordShort: return TokenKind::KEYWORD_SHORT;
    case pasta::TokenKind::kKeywordSigned: return TokenKind::KEYWORD_SIGNED;
    case pasta::TokenKind::kKeywordSizeof: return TokenKind::KEYWORD_SIZEOF;
    case pasta::TokenKind::kKeywordStatic: return TokenKind::KEYWORD_STATIC;
    case pasta::TokenKind::kKeywordStruct: return TokenKind::KEYWORD_STRUCT;
    case pasta::TokenKind::kKeywordSwitch: return TokenKind::KEYWORD_SWITCH;
    case pasta::TokenKind::kKeywordTypedef: return TokenKind::KEYWORD_TYPEDEF;
    case pasta::TokenKind::kKeywordUnion: return TokenKind::KEYWORD_UNION;
    case pasta::TokenKind::kKeywordUnsigned: return TokenKind::KEYWORD_UNSIGNED;
    case pasta::TokenKind::kKeywordVoid: return TokenKind::KEYWORD_VOID;
    case pasta::TokenKind::kKeywordVolatile: return TokenKind::KEYWORD_VOLATILE;
    case pasta::TokenKind::kKeywordWhile: return TokenKind::KEYWORD_WHILE;
    case pasta::TokenKind::kKeyword_Alignas: return TokenKind::KEYWORD__ALIGNAS;
    case pasta::TokenKind::kKeyword_Alignof: return TokenKind::KEYWORD__ALIGNOF;
    case pasta::TokenKind::kKeyword_Atomic: return TokenKind::KEYWORD__ATOMIC;
    case pasta::TokenKind::kKeyword_Boolean: return TokenKind::KEYWORD__BOOLEAN;
    case pasta::TokenKind::kKeyword_Complex: return TokenKind::KEYWORD__COMPLEX;
    case pasta::TokenKind::kKeyword_Generic: return TokenKind::KEYWORD__GENERIC;
    case pasta::TokenKind::kKeyword_Imaginary: return TokenKind::KEYWORD__IMAGINARY;
    case pasta::TokenKind::kKeyword_Noreturn: return TokenKind::KEYWORD__NORETURN;
    case pasta::TokenKind::kKeyword_StaticAssert: return TokenKind::KEYWORD__STATIC_ASSERT;
    case pasta::TokenKind::kKeyword_ThreadLocal: return TokenKind::KEYWORD__THREAD_LOCAL;
    case pasta::TokenKind::kKeyword__Func__: return TokenKind::KEYWORD___FUNC__;
    case pasta::TokenKind::kKeyword__ObjcYes: return TokenKind::KEYWORD___OBJC_YES;
    case pasta::TokenKind::kKeyword__ObjcNo: return TokenKind::KEYWORD___OBJC_NO;
    case pasta::TokenKind::kKeywordAssembly: return TokenKind::KEYWORD_ASSEMBLY;
    case pasta::TokenKind::kKeywordBoolean: return TokenKind::KEYWORD_BOOLEAN;
    case pasta::TokenKind::kKeywordCatch: return TokenKind::KEYWORD_CATCH;
    case pasta::TokenKind::kKeywordClass: return TokenKind::KEYWORD_CLASS;
    case pasta::TokenKind::kKeywordConstCast: return TokenKind::KEYWORD_CONST_CAST;
    case pasta::TokenKind::kKeywordDelete: return TokenKind::KEYWORD_DELETE;
    case pasta::TokenKind::kKeywordDynamicCast: return TokenKind::KEYWORD_DYNAMIC_CAST;
    case pasta::TokenKind::kKeywordExplicit: return TokenKind::KEYWORD_EXPLICIT;
    case pasta::TokenKind::kKeywordExport: return TokenKind::KEYWORD_EXPORT;
    case pasta::TokenKind::kKeywordFalse: return TokenKind::KEYWORD_FALSE;
    case pasta::TokenKind::kKeywordFriend: return TokenKind::KEYWORD_FRIEND;
    case pasta::TokenKind::kKeywordMutable: return TokenKind::KEYWORD_MUTABLE;
    case pasta::TokenKind::kKeywordNamespace: return TokenKind::KEYWORD_NAMESPACE;
    case pasta::TokenKind::kKeywordNew: return TokenKind::KEYWORD_NEW;
    case pasta::TokenKind::kKeywordOperator: return TokenKind::KEYWORD_OPERATOR;
    case pasta::TokenKind::kKeywordPrivate: return TokenKind::KEYWORD_PRIVATE;
    case pasta::TokenKind::kKeywordProtected: return TokenKind::KEYWORD_PROTECTED;
    case pasta::TokenKind::kKeywordPublic: return TokenKind::KEYWORD_PUBLIC;
    case pasta::TokenKind::kKeywordReinterpretCast: return TokenKind::KEYWORD_REINTERPRET_CAST;
    case pasta::TokenKind::kKeywordStaticCast: return TokenKind::KEYWORD_STATIC_CAST;
    case pasta::TokenKind::kKeywordTemplate: return TokenKind::KEYWORD_TEMPLATE;
    case pasta::TokenKind::kKeywordThis: return TokenKind::KEYWORD_THIS;
    case pasta::TokenKind::kKeywordThrow: return TokenKind::KEYWORD_THROW;
    case pasta::TokenKind::kKeywordTrue: return TokenKind::KEYWORD_TRUE;
    case pasta::TokenKind::kKeywordTry: return TokenKind::KEYWORD_TRY;
    case pasta::TokenKind::kKeywordTypename: return TokenKind::KEYWORD_TYPENAME;
    case pasta::TokenKind::kKeywordTypeid: return TokenKind::KEYWORD_TYPEID;
    case pasta::TokenKind::kKeywordUsing: return TokenKind::KEYWORD_USING;
    case pasta::TokenKind::kKeywordVirtual: return TokenKind::KEYWORD_VIRTUAL;
    case pasta::TokenKind::kKeywordWcharT: return TokenKind::KEYWORD_WCHAR_T;
    case pasta::TokenKind::kKeywordAlignas: return TokenKind::KEYWORD_ALIGNAS;
    case pasta::TokenKind::kKeywordAlignof: return TokenKind::KEYWORD_ALIGNOF;
    case pasta::TokenKind::kKeywordChar16T: return TokenKind::KEYWORD_CHAR16_T;
    case pasta::TokenKind::kKeywordChar32T: return TokenKind::KEYWORD_CHAR32_T;
    case pasta::TokenKind::kKeywordConstexpr: return TokenKind::KEYWORD_CONSTEXPR;
    case pasta::TokenKind::kKeywordDecltype: return TokenKind::KEYWORD_DECLTYPE;
    case pasta::TokenKind::kKeywordNoexcept: return TokenKind::KEYWORD_NOEXCEPT;
    case pasta::TokenKind::kKeywordNullptr: return TokenKind::KEYWORD_NULLPTR;
    case pasta::TokenKind::kKeywordStaticAssert: return TokenKind::KEYWORD_STATIC_ASSERT;
    case pasta::TokenKind::kKeywordThreadLocal: return TokenKind::KEYWORD_THREAD_LOCAL;
    case pasta::TokenKind::kKeywordConcept: return TokenKind::KEYWORD_CONCEPT;
    case pasta::TokenKind::kKeywordRequires: return TokenKind::KEYWORD_REQUIRES;
    case pasta::TokenKind::kKeywordCoAwait: return TokenKind::KEYWORD_CO_AWAIT;
    case pasta::TokenKind::kKeywordCoReturn: return TokenKind::KEYWORD_CO_RETURN;
    case pasta::TokenKind::kKeywordCoYield: return TokenKind::KEYWORD_CO_YIELD;
    case pasta::TokenKind::kKeywordModule: return TokenKind::KEYWORD_MODULE;
    case pasta::TokenKind::kKeywordImport: return TokenKind::KEYWORD_IMPORT;
    case pasta::TokenKind::kKeywordConsteval: return TokenKind::KEYWORD_CONSTEVAL;
    case pasta::TokenKind::kKeywordConstinit: return TokenKind::KEYWORD_CONSTINIT;
    case pasta::TokenKind::kKeywordChar8T: return TokenKind::KEYWORD_CHAR8_T;
    case pasta::TokenKind::kKeyword_Float16: return TokenKind::KEYWORD__FLOAT16;
    case pasta::TokenKind::kKeyword_Accum: return TokenKind::KEYWORD__ACCUM;
    case pasta::TokenKind::kKeyword_Fract: return TokenKind::KEYWORD__FRACT;
    case pasta::TokenKind::kKeyword_Sat: return TokenKind::KEYWORD__SAT;
    case pasta::TokenKind::kKeyword_Decimal32: return TokenKind::KEYWORD__DECIMAL32;
    case pasta::TokenKind::kKeyword_Decimal64: return TokenKind::KEYWORD__DECIMAL64;
    case pasta::TokenKind::kKeyword_Decimal128: return TokenKind::KEYWORD__DECIMAL128;
    case pasta::TokenKind::kKeyword__Null: return TokenKind::KEYWORD___NULL;
    case pasta::TokenKind::kKeyword__Alignof: return TokenKind::KEYWORD___ALIGNOF;
    case pasta::TokenKind::kKeyword__Attribute: return TokenKind::KEYWORD___ATTRIBUTE;
    case pasta::TokenKind::kKeyword__BuiltinChooseExpression: return TokenKind::KEYWORD___BUILTIN_CHOOSE_EXPRESSION;
    case pasta::TokenKind::kKeyword__BuiltinOffsetof: return TokenKind::KEYWORD___BUILTIN_OFFSETOF;
    case pasta::TokenKind::kKeyword__BuiltinFILE: return TokenKind::KEYWORD___BUILTIN_FILE;
    case pasta::TokenKind::kKeyword__BuiltinFUNCTION: return TokenKind::KEYWORD___BUILTIN_FUNCTION;
    case pasta::TokenKind::kKeyword__BuiltinLINE: return TokenKind::KEYWORD___BUILTIN_LINE;
    case pasta::TokenKind::kKeyword__BuiltinCOLUMN: return TokenKind::KEYWORD___BUILTIN_COLUMN;
    case pasta::TokenKind::kKeyword__BuiltinTypesCompatibleP: return TokenKind::KEYWORD___BUILTIN_TYPES_COMPATIBLE_P;
    case pasta::TokenKind::kKeyword__BuiltinVaArgument: return TokenKind::KEYWORD___BUILTIN_VA_ARGUMENT;
    case pasta::TokenKind::kKeyword__Extension__: return TokenKind::KEYWORD___EXTENSION__;
    case pasta::TokenKind::kKeyword__Float128: return TokenKind::KEYWORD___FLOAT128;
    case pasta::TokenKind::kKeyword__Imag: return TokenKind::KEYWORD___IMAG;
    case pasta::TokenKind::kKeyword__Int128: return TokenKind::KEYWORD___INT128;
    case pasta::TokenKind::kKeyword__Label__: return TokenKind::KEYWORD___LABEL__;
    case pasta::TokenKind::kKeyword__Real: return TokenKind::KEYWORD___REAL;
    case pasta::TokenKind::kKeyword__Thread: return TokenKind::KEYWORD___THREAD;
    case pasta::TokenKind::kKeyword__FUNCTION__: return TokenKind::KEYWORD___FUNCTION__;
    case pasta::TokenKind::kKeyword__PRETTYFUNCTION__: return TokenKind::KEYWORD___PRETTYFUNCTION__;
    case pasta::TokenKind::kKeyword__AutoType: return TokenKind::KEYWORD___AUTO_TYPE;
    case pasta::TokenKind::kKeywordTypeof: return TokenKind::KEYWORD_TYPEOF;
    case pasta::TokenKind::kKeyword__FUNCDNAME__: return TokenKind::KEYWORD___FUNCDNAME__;
    case pasta::TokenKind::kKeyword__FUNCSIG__: return TokenKind::KEYWORD___FUNCSIG__;
    case pasta::TokenKind::kKeywordLFUNCTION__: return TokenKind::KEYWORD_LFUNCTION__;
    case pasta::TokenKind::kKeywordLFUNCSIG__: return TokenKind::KEYWORD_LFUNCSIG__;
    case pasta::TokenKind::kKeyword__IsInterfaceClass: return TokenKind::KEYWORD___IS_INTERFACE_CLASS;
    case pasta::TokenKind::kKeyword__IsSealed: return TokenKind::KEYWORD___IS_SEALED;
    case pasta::TokenKind::kKeyword__IsDestructible: return TokenKind::KEYWORD___IS_DESTRUCTIBLE;
    case pasta::TokenKind::kKeyword__IsTriviallyDestructible: return TokenKind::KEYWORD___IS_TRIVIALLY_DESTRUCTIBLE;
    case pasta::TokenKind::kKeyword__IsNothrowDestructible: return TokenKind::KEYWORD___IS_NOTHROW_DESTRUCTIBLE;
    case pasta::TokenKind::kKeyword__IsNothrowAssignable: return TokenKind::KEYWORD___IS_NOTHROW_ASSIGNABLE;
    case pasta::TokenKind::kKeyword__IsConstructible: return TokenKind::KEYWORD___IS_CONSTRUCTIBLE;
    case pasta::TokenKind::kKeyword__IsNothrowConstructible: return TokenKind::KEYWORD___IS_NOTHROW_CONSTRUCTIBLE;
    case pasta::TokenKind::kKeyword__IsAssignable: return TokenKind::KEYWORD___IS_ASSIGNABLE;
    case pasta::TokenKind::kKeyword__HasNothrowMoveAssign: return TokenKind::KEYWORD___HAS_NOTHROW_MOVE_ASSIGN;
    case pasta::TokenKind::kKeyword__HasTrivialMoveAssign: return TokenKind::KEYWORD___HAS_TRIVIAL_MOVE_ASSIGN;
    case pasta::TokenKind::kKeyword__HasTrivialMoveConstructor: return TokenKind::KEYWORD___HAS_TRIVIAL_MOVE_CONSTRUCTOR;
    case pasta::TokenKind::kKeyword__HasNothrowAssign: return TokenKind::KEYWORD___HAS_NOTHROW_ASSIGN;
    case pasta::TokenKind::kKeyword__HasNothrowCopy: return TokenKind::KEYWORD___HAS_NOTHROW_COPY;
    case pasta::TokenKind::kKeyword__HasNothrowConstructor: return TokenKind::KEYWORD___HAS_NOTHROW_CONSTRUCTOR;
    case pasta::TokenKind::kKeyword__HasTrivialAssign: return TokenKind::KEYWORD___HAS_TRIVIAL_ASSIGN;
    case pasta::TokenKind::kKeyword__HasTrivialCopy: return TokenKind::KEYWORD___HAS_TRIVIAL_COPY;
    case pasta::TokenKind::kKeyword__HasTrivialConstructor: return TokenKind::KEYWORD___HAS_TRIVIAL_CONSTRUCTOR;
    case pasta::TokenKind::kKeyword__HasTrivialDestructor: return TokenKind::KEYWORD___HAS_TRIVIAL_DESTRUCTOR;
    case pasta::TokenKind::kKeyword__HasVirtualDestructor: return TokenKind::KEYWORD___HAS_VIRTUAL_DESTRUCTOR;
    case pasta::TokenKind::kKeyword__IsAbstract: return TokenKind::KEYWORD___IS_ABSTRACT;
    case pasta::TokenKind::kKeyword__IsAggregate: return TokenKind::KEYWORD___IS_AGGREGATE;
    case pasta::TokenKind::kKeyword__IsBaseOf: return TokenKind::KEYWORD___IS_BASE_OF;
    case pasta::TokenKind::kKeyword__IsClass: return TokenKind::KEYWORD___IS_CLASS;
    case pasta::TokenKind::kKeyword__IsConvertibleTo: return TokenKind::KEYWORD___IS_CONVERTIBLE_TO;
    case pasta::TokenKind::kKeyword__IsEmpty: return TokenKind::KEYWORD___IS_EMPTY;
    case pasta::TokenKind::kKeyword__IsEnum: return TokenKind::KEYWORD___IS_ENUM;
    case pasta::TokenKind::kKeyword__IsFinal: return TokenKind::KEYWORD___IS_FINAL;
    case pasta::TokenKind::kKeyword__IsLiteral: return TokenKind::KEYWORD___IS_LITERAL;
    case pasta::TokenKind::kKeyword__IsPod: return TokenKind::KEYWORD___IS_POD;
    case pasta::TokenKind::kKeyword__IsPolymorphic: return TokenKind::KEYWORD___IS_POLYMORPHIC;
    case pasta::TokenKind::kKeyword__IsStandardLayout: return TokenKind::KEYWORD___IS_STANDARD_LAYOUT;
    case pasta::TokenKind::kKeyword__IsTrivial: return TokenKind::KEYWORD___IS_TRIVIAL;
    case pasta::TokenKind::kKeyword__IsTriviallyAssignable: return TokenKind::KEYWORD___IS_TRIVIALLY_ASSIGNABLE;
    case pasta::TokenKind::kKeyword__IsTriviallyConstructible: return TokenKind::KEYWORD___IS_TRIVIALLY_CONSTRUCTIBLE;
    case pasta::TokenKind::kKeyword__IsTriviallyCopyable: return TokenKind::KEYWORD___IS_TRIVIALLY_COPYABLE;
    case pasta::TokenKind::kKeyword__IsUnion: return TokenKind::KEYWORD___IS_UNION;
    case pasta::TokenKind::kKeyword__HasUniqueObjectRepresentations: return TokenKind::KEYWORD___HAS_UNIQUE_OBJECT_REPRESENTATIONS;
    case pasta::TokenKind::kKeyword__UnderlyingType: return TokenKind::KEYWORD___UNDERLYING_TYPE;
    case pasta::TokenKind::kKeyword__ReferenceBindsToTemporary: return TokenKind::KEYWORD___REFERENCE_BINDS_TO_TEMPORARY;
    case pasta::TokenKind::kKeyword__IsLvalueExpression: return TokenKind::KEYWORD___IS_LVALUE_EXPRESSION;
    case pasta::TokenKind::kKeyword__IsRvalueExpression: return TokenKind::KEYWORD___IS_RVALUE_EXPRESSION;
    case pasta::TokenKind::kKeyword__IsArithmetic: return TokenKind::KEYWORD___IS_ARITHMETIC;
    case pasta::TokenKind::kKeyword__IsFloatingPoint: return TokenKind::KEYWORD___IS_FLOATING_POINT;
    case pasta::TokenKind::kKeyword__IsIntegral: return TokenKind::KEYWORD___IS_INTEGRAL;
    case pasta::TokenKind::kKeyword__IsCompleteType: return TokenKind::KEYWORD___IS_COMPLETE_TYPE;
    case pasta::TokenKind::kKeyword__IsVoid: return TokenKind::KEYWORD___IS_VOID;
    case pasta::TokenKind::kKeyword__IsArray: return TokenKind::KEYWORD___IS_ARRAY;
    case pasta::TokenKind::kKeyword__IsFunction: return TokenKind::KEYWORD___IS_FUNCTION;
    case pasta::TokenKind::kKeyword__IsReference: return TokenKind::KEYWORD___IS_REFERENCE;
    case pasta::TokenKind::kKeyword__IsLvalueReference: return TokenKind::KEYWORD___IS_LVALUE_REFERENCE;
    case pasta::TokenKind::kKeyword__IsRvalueReference: return TokenKind::KEYWORD___IS_RVALUE_REFERENCE;
    case pasta::TokenKind::kKeyword__IsFundamental: return TokenKind::KEYWORD___IS_FUNDAMENTAL;
    case pasta::TokenKind::kKeyword__IsObject: return TokenKind::KEYWORD___IS_OBJECT;
    case pasta::TokenKind::kKeyword__IsScalar: return TokenKind::KEYWORD___IS_SCALAR;
    case pasta::TokenKind::kKeyword__IsCompound: return TokenKind::KEYWORD___IS_COMPOUND;
    case pasta::TokenKind::kKeyword__IsPointer: return TokenKind::KEYWORD___IS_POINTER;
    case pasta::TokenKind::kKeyword__IsMemberObjectPointer: return TokenKind::KEYWORD___IS_MEMBER_OBJECT_POINTER;
    case pasta::TokenKind::kKeyword__IsMemberFunctionPointer: return TokenKind::KEYWORD___IS_MEMBER_FUNCTION_POINTER;
    case pasta::TokenKind::kKeyword__IsMemberPointer: return TokenKind::KEYWORD___IS_MEMBER_POINTER;
    case pasta::TokenKind::kKeyword__IsConst: return TokenKind::KEYWORD___IS_CONST;
    case pasta::TokenKind::kKeyword__IsVolatile: return TokenKind::KEYWORD___IS_VOLATILE;
    case pasta::TokenKind::kKeyword__IsSigned: return TokenKind::KEYWORD___IS_SIGNED;
    case pasta::TokenKind::kKeyword__IsUnsigned: return TokenKind::KEYWORD___IS_UNSIGNED;
    case pasta::TokenKind::kKeyword__IsSame: return TokenKind::KEYWORD___IS_SAME;
    case pasta::TokenKind::kKeyword__IsConvertible: return TokenKind::KEYWORD___IS_CONVERTIBLE;
    case pasta::TokenKind::kKeyword__ArrayRank: return TokenKind::KEYWORD___ARRAY_RANK;
    case pasta::TokenKind::kKeyword__ArrayExtent: return TokenKind::KEYWORD___ARRAY_EXTENT;
    case pasta::TokenKind::kKeyword__PrivateExtern__: return TokenKind::KEYWORD___PRIVATE_EXTERN__;
    case pasta::TokenKind::kKeyword__ModulePrivate__: return TokenKind::KEYWORD___MODULE_PRIVATE__;
    case pasta::TokenKind::kKeyword__Declspec: return TokenKind::KEYWORD___DECLSPEC;
    case pasta::TokenKind::kKeyword__Cdecl: return TokenKind::KEYWORD___CDECL;
    case pasta::TokenKind::kKeyword__Stdcall: return TokenKind::KEYWORD___STDCALL;
    case pasta::TokenKind::kKeyword__Fastcall: return TokenKind::KEYWORD___FASTCALL;
    case pasta::TokenKind::kKeyword__Thiscall: return TokenKind::KEYWORD___THISCALL;
    case pasta::TokenKind::kKeyword__Regcall: return TokenKind::KEYWORD___REGCALL;
    case pasta::TokenKind::kKeyword__Vectorcall: return TokenKind::KEYWORD___VECTORCALL;
    case pasta::TokenKind::kKeyword__Forceinline: return TokenKind::KEYWORD___FORCEINLINE;
    case pasta::TokenKind::kKeyword__Unaligned: return TokenKind::KEYWORD___UNALIGNED;
    case pasta::TokenKind::kKeyword__Super: return TokenKind::KEYWORD___SUPER;
    case pasta::TokenKind::kKeyword__Global: return TokenKind::KEYWORD___GLOBAL;
    case pasta::TokenKind::kKeyword__Local: return TokenKind::KEYWORD___LOCAL;
    case pasta::TokenKind::kKeyword__Constant: return TokenKind::KEYWORD___CONSTANT;
    case pasta::TokenKind::kKeyword__Private: return TokenKind::KEYWORD___PRIVATE;
    case pasta::TokenKind::kKeyword__Generic: return TokenKind::KEYWORD___GENERIC;
    case pasta::TokenKind::kKeyword__Kernel: return TokenKind::KEYWORD___KERNEL;
    case pasta::TokenKind::kKeyword__ReadOnly: return TokenKind::KEYWORD___READ_ONLY;
    case pasta::TokenKind::kKeyword__WriteOnly: return TokenKind::KEYWORD___WRITE_ONLY;
    case pasta::TokenKind::kKeyword__ReadWrite: return TokenKind::KEYWORD___READ_WRITE;
    case pasta::TokenKind::kKeyword__BuiltinAstype: return TokenKind::KEYWORD___BUILTIN_ASTYPE;
    case pasta::TokenKind::kKeywordVecStep: return TokenKind::KEYWORD_VEC_STEP;
    case pasta::TokenKind::kKeywordImage1dT: return TokenKind::KEYWORD_IMAGE1_DT;
    case pasta::TokenKind::kKeywordImage1dArrayT: return TokenKind::KEYWORD_IMAGE1_DARRAY_T;
    case pasta::TokenKind::kKeywordImage1dBufferT: return TokenKind::KEYWORD_IMAGE1_DBUFFER_T;
    case pasta::TokenKind::kKeywordImage2dT: return TokenKind::KEYWORD_IMAGE2_DT;
    case pasta::TokenKind::kKeywordImage2dArrayT: return TokenKind::KEYWORD_IMAGE2_DARRAY_T;
    case pasta::TokenKind::kKeywordImage2dDepthT: return TokenKind::KEYWORD_IMAGE2_DDEPTH_T;
    case pasta::TokenKind::kKeywordImage2dArrayDepthT: return TokenKind::KEYWORD_IMAGE2_DARRAY_DEPTH_T;
    case pasta::TokenKind::kKeywordImage2dMsaaT: return TokenKind::KEYWORD_IMAGE2_DMSAA_T;
    case pasta::TokenKind::kKeywordImage2dArrayMsaaT: return TokenKind::KEYWORD_IMAGE2_DARRAY_MSAA_T;
    case pasta::TokenKind::kKeywordImage2dMsaaDepthT: return TokenKind::KEYWORD_IMAGE2_DMSAA_DEPTH_T;
    case pasta::TokenKind::kKeywordImage2dArrayMsaaDepthT: return TokenKind::KEYWORD_IMAGE2_DARRAY_MSAA_DEPTH_T;
    case pasta::TokenKind::kKeywordImage3dT: return TokenKind::KEYWORD_IMAGE3_DT;
    case pasta::TokenKind::kKeywordPipe: return TokenKind::KEYWORD_PIPE;
    case pasta::TokenKind::kKeywordAddrspaceCast: return TokenKind::KEYWORD_ADDRSPACE_CAST;
    case pasta::TokenKind::kKeyword__BuiltinOmpRequiredSimdAlign: return TokenKind::KEYWORD___BUILTIN_OMP_REQUIRED_SIMD_ALIGN;
    case pasta::TokenKind::kKeyword__Pascal: return TokenKind::KEYWORD___PASCAL;
    case pasta::TokenKind::kKeyword__Vector: return TokenKind::KEYWORD___VECTOR;
    case pasta::TokenKind::kKeyword__Pixel: return TokenKind::KEYWORD___PIXEL;
    case pasta::TokenKind::kKeyword__Boolean: return TokenKind::KEYWORD___BOOLEAN;
    case pasta::TokenKind::kKeyword__Bf16: return TokenKind::KEYWORD___BF16;
    case pasta::TokenKind::kKeywordHalf: return TokenKind::KEYWORD_HALF;
    case pasta::TokenKind::kKeyword__Bridge: return TokenKind::KEYWORD___BRIDGE;
    case pasta::TokenKind::kKeyword__BridgeTransfer: return TokenKind::KEYWORD___BRIDGE_TRANSFER;
    case pasta::TokenKind::kKeyword__BridgeRetained: return TokenKind::KEYWORD___BRIDGE_RETAINED;
    case pasta::TokenKind::kKeyword__BridgeRetain: return TokenKind::KEYWORD___BRIDGE_RETAIN;
    case pasta::TokenKind::kKeyword__Covariant: return TokenKind::KEYWORD___COVARIANT;
    case pasta::TokenKind::kKeyword__Contravariant: return TokenKind::KEYWORD___CONTRAVARIANT;
    case pasta::TokenKind::kKeyword__Kindof: return TokenKind::KEYWORD___KINDOF;
    case pasta::TokenKind::kKeyword_Nonnull: return TokenKind::KEYWORD__NONNULL;
    case pasta::TokenKind::kKeyword_Nullable: return TokenKind::KEYWORD__NULLABLE;
    case pasta::TokenKind::kKeyword_NullableResult: return TokenKind::KEYWORD__NULLABLE_RESULT;
    case pasta::TokenKind::kKeyword_NullUnspecified: return TokenKind::KEYWORD__NULL_UNSPECIFIED;
    case pasta::TokenKind::kKeyword__Ptr64: return TokenKind::KEYWORD___PTR64;
    case pasta::TokenKind::kKeyword__Ptr32: return TokenKind::KEYWORD___PTR32;
    case pasta::TokenKind::kKeyword__Sptr: return TokenKind::KEYWORD___SPTR;
    case pasta::TokenKind::kKeyword__Uptr: return TokenKind::KEYWORD___UPTR;
    case pasta::TokenKind::kKeyword__W64: return TokenKind::KEYWORD___W64;
    case pasta::TokenKind::kKeyword__Uuidof: return TokenKind::KEYWORD___UUIDOF;
    case pasta::TokenKind::kKeyword__Try: return TokenKind::KEYWORD___TRY;
    case pasta::TokenKind::kKeyword__Finally: return TokenKind::KEYWORD___FINALLY;
    case pasta::TokenKind::kKeyword__Leave: return TokenKind::KEYWORD___LEAVE;
    case pasta::TokenKind::kKeyword__Int64: return TokenKind::KEYWORD___INT64;
    case pasta::TokenKind::kKeyword__IfExists: return TokenKind::KEYWORD___IF_EXISTS;
    case pasta::TokenKind::kKeyword__IfNotExists: return TokenKind::KEYWORD___IF_NOT_EXISTS;
    case pasta::TokenKind::kKeyword__SingleInheritance: return TokenKind::KEYWORD___SINGLE_INHERITANCE;
    case pasta::TokenKind::kKeyword__MultipleInheritance: return TokenKind::KEYWORD___MULTIPLE_INHERITANCE;
    case pasta::TokenKind::kKeyword__VirtualInheritance: return TokenKind::KEYWORD___VIRTUAL_INHERITANCE;
    case pasta::TokenKind::kKeyword__Interface: return TokenKind::KEYWORD___INTERFACE;
    case pasta::TokenKind::kKeyword__BuiltinConvertvector: return TokenKind::KEYWORD___BUILTIN_CONVERTVECTOR;
    case pasta::TokenKind::kKeyword__BuiltinBitCast: return TokenKind::KEYWORD___BUILTIN_BIT_CAST;
    case pasta::TokenKind::kKeyword__BuiltinAvailable: return TokenKind::KEYWORD___BUILTIN_AVAILABLE;
    case pasta::TokenKind::kKeyword__BuiltinSyclUniqueStableName: return TokenKind::KEYWORD___BUILTIN_SYCL_UNIQUE_STABLE_NAME;
    case pasta::TokenKind::kKeyword__UnknownAnytype: return TokenKind::KEYWORD___UNKNOWN_ANYTYPE;
    case pasta::TokenKind::kAnnotCxxscope: return TokenKind::ANNOT_CXXSCOPE;
    case pasta::TokenKind::kAnnotTypename: return TokenKind::ANNOT_TYPENAME;
    case pasta::TokenKind::kAnnotTemplateId: return TokenKind::ANNOT_TEMPLATE_ID;
    case pasta::TokenKind::kAnnotNonType: return TokenKind::ANNOT_NON_TYPE;
    case pasta::TokenKind::kAnnotNonTypeUndeclared: return TokenKind::ANNOT_NON_TYPE_UNDECLARED;
    case pasta::TokenKind::kAnnotNonTypeDependent: return TokenKind::ANNOT_NON_TYPE_DEPENDENT;
    case pasta::TokenKind::kAnnotOverload: return TokenKind::ANNOT_OVERLOAD;
    case pasta::TokenKind::kAnnotPrimaryExpression: return TokenKind::ANNOT_PRIMARY_EXPRESSION;
    case pasta::TokenKind::kAnnotDecltype: return TokenKind::ANNOT_DECLTYPE;
    case pasta::TokenKind::kAnnotPragmaUnused: return TokenKind::ANNOT_PRAGMA_UNUSED;
    case pasta::TokenKind::kAnnotPragmaVis: return TokenKind::ANNOT_PRAGMA_VIS;
    case pasta::TokenKind::kAnnotPragmaPack: return TokenKind::ANNOT_PRAGMA_PACK;
    case pasta::TokenKind::kAnnotPragmaParserCrash: return TokenKind::ANNOT_PRAGMA_PARSER_CRASH;
    case pasta::TokenKind::kAnnotPragmaCaptured: return TokenKind::ANNOT_PRAGMA_CAPTURED;
    case pasta::TokenKind::kAnnotPragmaDump: return TokenKind::ANNOT_PRAGMA_DUMP;
    case pasta::TokenKind::kAnnotPragmaMsstruct: return TokenKind::ANNOT_PRAGMA_MSSTRUCT;
    case pasta::TokenKind::kAnnotPragmaAlign: return TokenKind::ANNOT_PRAGMA_ALIGN;
    case pasta::TokenKind::kAnnotPragmaWeak: return TokenKind::ANNOT_PRAGMA_WEAK;
    case pasta::TokenKind::kAnnotPragmaWeakalias: return TokenKind::ANNOT_PRAGMA_WEAKALIAS;
    case pasta::TokenKind::kAnnotPragmaRedefineExtname: return TokenKind::ANNOT_PRAGMA_REDEFINE_EXTNAME;
    case pasta::TokenKind::kAnnotPragmaFpContract: return TokenKind::ANNOT_PRAGMA_FP_CONTRACT;
    case pasta::TokenKind::kAnnotPragmaFenvAccess: return TokenKind::ANNOT_PRAGMA_FENV_ACCESS;
    case pasta::TokenKind::kAnnotPragmaFenvRound: return TokenKind::ANNOT_PRAGMA_FENV_ROUND;
    case pasta::TokenKind::kAnnotPragmaFloatControl: return TokenKind::ANNOT_PRAGMA_FLOAT_CONTROL;
    case pasta::TokenKind::kAnnotPragmaMsPointersToMembers: return TokenKind::ANNOT_PRAGMA_MS_POINTERS_TO_MEMBERS;
    case pasta::TokenKind::kAnnotPragmaMsVtordisp: return TokenKind::ANNOT_PRAGMA_MS_VTORDISP;
    case pasta::TokenKind::kAnnotPragmaMsPragma: return TokenKind::ANNOT_PRAGMA_MS_PRAGMA;
    case pasta::TokenKind::kAnnotPragmaOpenclExtension: return TokenKind::ANNOT_PRAGMA_OPENCL_EXTENSION;
    case pasta::TokenKind::kAnnotAttributeOpenmp: return TokenKind::ANNOT_ATTRIBUTE_OPENMP;
    case pasta::TokenKind::kAnnotPragmaOpenmp: return TokenKind::ANNOT_PRAGMA_OPENMP;
    case pasta::TokenKind::kAnnotPragmaOpenmpEnd: return TokenKind::ANNOT_PRAGMA_OPENMP_END;
    case pasta::TokenKind::kAnnotPragmaLoopHint: return TokenKind::ANNOT_PRAGMA_LOOP_HINT;
    case pasta::TokenKind::kAnnotPragmaFp: return TokenKind::ANNOT_PRAGMA_FP;
    case pasta::TokenKind::kAnnotPragmaAttribute: return TokenKind::ANNOT_PRAGMA_ATTRIBUTE;
    case pasta::TokenKind::kAnnotModuleInclude: return TokenKind::ANNOT_MODULE_INCLUDE;
    case pasta::TokenKind::kAnnotModuleBegin: return TokenKind::ANNOT_MODULE_BEGIN;
    case pasta::TokenKind::kAnnotModuleEnd: return TokenKind::ANNOT_MODULE_END;
    case pasta::TokenKind::kAnnotHeaderUnit: return TokenKind::ANNOT_HEADER_UNIT;
  }
}

TrailingAllocKind FromPasta(pasta::TrailingAllocKind e) {
  switch (e) {
    case pasta::TrailingAllocKind::kTAKInheritsConstructor: return TrailingAllocKind::TAK_INHERITS_CONSTRUCTOR;
    case pasta::TrailingAllocKind::kTAKHasTailExplicit: return TrailingAllocKind::TAK_HAS_TAIL_EXPLICIT;
  }
}

TranslationUnitKind FromPasta(pasta::TranslationUnitKind e) {
  switch (e) {
    case pasta::TranslationUnitKind::kComplete: return TranslationUnitKind::COMPLETE;
    case pasta::TranslationUnitKind::kPrefix: return TranslationUnitKind::PREFIX;
    case pasta::TranslationUnitKind::kModule: return TranslationUnitKind::MODULE;
    case pasta::TranslationUnitKind::kIncremental: return TranslationUnitKind::INCREMENTAL;
  }
}

TrivialAutoVarInitKind FromPasta(pasta::TrivialAutoVarInitKind e) {
  switch (e) {
    case pasta::TrivialAutoVarInitKind::kUninitialized: return TrivialAutoVarInitKind::UNINITIALIZED;
    case pasta::TrivialAutoVarInitKind::kZero: return TrivialAutoVarInitKind::ZERO;
    case pasta::TrivialAutoVarInitKind::kPattern: return TrivialAutoVarInitKind::PATTERN;
  }
}

TypeDependence FromPasta(pasta::TypeDependence e) {
  switch (e) {
    case pasta::TypeDependence::kUnexpandedPack: return TypeDependence::UNEXPANDED_PACK;
    case pasta::TypeDependence::kInstantiation: return TypeDependence::INSTANTIATION;
    case pasta::TypeDependence::kDependent: return TypeDependence::DEPENDENT;
    case pasta::TypeDependence::kVariablyModified: return TypeDependence::VARIABLY_MODIFIED;
    case pasta::TypeDependence::kError: return TypeDependence::ERROR;
    case pasta::TypeDependence::kNone: return TypeDependence::NONE;
    case pasta::TypeDependence::kAll: return TypeDependence::ALL;
    case pasta::TypeDependence::kDependentInstantiation: return TypeDependence::DEPENDENT_INSTANTIATION;
  }
}

TypeLocClass FromPasta(pasta::TypeLocClass e) {
  switch (e) {
    case pasta::TypeLocClass::kAdjusted: return TypeLocClass::ADJUSTED;
    case pasta::TypeLocClass::kDecayed: return TypeLocClass::DECAYED;
    case pasta::TypeLocClass::kConstantArray: return TypeLocClass::CONSTANT_ARRAY;
    case pasta::TypeLocClass::kDependentSizedArray: return TypeLocClass::DEPENDENT_SIZED_ARRAY;
    case pasta::TypeLocClass::kIncompleteArray: return TypeLocClass::INCOMPLETE_ARRAY;
    case pasta::TypeLocClass::kVariableArray: return TypeLocClass::VARIABLE_ARRAY;
    case pasta::TypeLocClass::kAtomic: return TypeLocClass::ATOMIC;
    case pasta::TypeLocClass::kAttributed: return TypeLocClass::ATTRIBUTED;
    case pasta::TypeLocClass::kBlockPointer: return TypeLocClass::BLOCK_POINTER;
    case pasta::TypeLocClass::kBuiltin: return TypeLocClass::BUILTIN;
    case pasta::TypeLocClass::kComplex: return TypeLocClass::COMPLEX;
    case pasta::TypeLocClass::kDecltype: return TypeLocClass::DECLTYPE;
    case pasta::TypeLocClass::kAuto: return TypeLocClass::AUTO;
    case pasta::TypeLocClass::kDeducedTemplateSpecialization: return TypeLocClass::DEDUCED_TEMPLATE_SPECIALIZATION;
    case pasta::TypeLocClass::kDependentAddressSpace: return TypeLocClass::DEPENDENT_ADDRESS_SPACE;
    case pasta::TypeLocClass::kDependentExtInt: return TypeLocClass::DEPENDENT_EXT_INT;
    case pasta::TypeLocClass::kDependentName: return TypeLocClass::DEPENDENT_NAME;
    case pasta::TypeLocClass::kDependentSizedExtVector: return TypeLocClass::DEPENDENT_SIZED_EXT_VECTOR;
    case pasta::TypeLocClass::kDependentTemplateSpecialization: return TypeLocClass::DEPENDENT_TEMPLATE_SPECIALIZATION;
    case pasta::TypeLocClass::kDependentVector: return TypeLocClass::DEPENDENT_VECTOR;
    case pasta::TypeLocClass::kElaborated: return TypeLocClass::ELABORATED;
    case pasta::TypeLocClass::kExtInt: return TypeLocClass::EXT_INT;
    case pasta::TypeLocClass::kFunctionNoProto: return TypeLocClass::FUNCTION_NO_PROTO;
    case pasta::TypeLocClass::kFunctionProto: return TypeLocClass::FUNCTION_PROTO;
    case pasta::TypeLocClass::kInjectedClassName: return TypeLocClass::INJECTED_CLASS_NAME;
    case pasta::TypeLocClass::kMacroQualified: return TypeLocClass::MACRO_QUALIFIED;
    case pasta::TypeLocClass::kConstantMatrix: return TypeLocClass::CONSTANT_MATRIX;
    case pasta::TypeLocClass::kDependentSizedMatrix: return TypeLocClass::DEPENDENT_SIZED_MATRIX;
    case pasta::TypeLocClass::kMemberPointer: return TypeLocClass::MEMBER_POINTER;
    case pasta::TypeLocClass::kObjCObjectPointer: return TypeLocClass::OBJ_C_OBJECT_POINTER;
    case pasta::TypeLocClass::kObjCObject: return TypeLocClass::OBJ_C_OBJECT;
    case pasta::TypeLocClass::kObjCInterface: return TypeLocClass::OBJ_C_INTERFACE;
    case pasta::TypeLocClass::kObjCTypeParam: return TypeLocClass::OBJ_C_TYPE_PARAM;
    case pasta::TypeLocClass::kPackExpansion: return TypeLocClass::PACK_EXPANSION;
    case pasta::TypeLocClass::kParenthesis: return TypeLocClass::PARENTHESIS;
    case pasta::TypeLocClass::kPipe: return TypeLocClass::PIPE;
    case pasta::TypeLocClass::kPointer: return TypeLocClass::POINTER;
    case pasta::TypeLocClass::kLValueReference: return TypeLocClass::L_VALUE_REFERENCE;
    case pasta::TypeLocClass::kRValueReference: return TypeLocClass::R_VALUE_REFERENCE;
    case pasta::TypeLocClass::kSubstTemplateTypeParmPack: return TypeLocClass::SUBST_TEMPLATE_TYPE_PARM_PACK;
    case pasta::TypeLocClass::kSubstTemplateTypeParm: return TypeLocClass::SUBST_TEMPLATE_TYPE_PARM;
    case pasta::TypeLocClass::kEnum: return TypeLocClass::ENUM;
    case pasta::TypeLocClass::kRecord: return TypeLocClass::RECORD;
    case pasta::TypeLocClass::kTemplateSpecialization: return TypeLocClass::TEMPLATE_SPECIALIZATION;
    case pasta::TypeLocClass::kTemplateTypeParm: return TypeLocClass::TEMPLATE_TYPE_PARM;
    case pasta::TypeLocClass::kTypeOfExpression: return TypeLocClass::TYPE_OF_EXPRESSION;
    case pasta::TypeLocClass::kTypeOf: return TypeLocClass::TYPE_OF;
    case pasta::TypeLocClass::kTypedef: return TypeLocClass::TYPEDEF;
    case pasta::TypeLocClass::kUnaryTransform: return TypeLocClass::UNARY_TRANSFORM;
    case pasta::TypeLocClass::kUnresolvedUsing: return TypeLocClass::UNRESOLVED_USING;
    case pasta::TypeLocClass::kVector: return TypeLocClass::VECTOR;
    case pasta::TypeLocClass::kExtVector: return TypeLocClass::EXT_VECTOR;
    case pasta::TypeLocClass::kQualified: return TypeLocClass::QUALIFIED;
  }
}

TypeSpecifierSign FromPasta(pasta::TypeSpecifierSign e) {
  switch (e) {
    case pasta::TypeSpecifierSign::kUnspecified: return TypeSpecifierSign::UNSPECIFIED;
    case pasta::TypeSpecifierSign::kSigned: return TypeSpecifierSign::SIGNED;
    case pasta::TypeSpecifierSign::kUnsigned: return TypeSpecifierSign::UNSIGNED;
  }
}

TypeSpecifierType FromPasta(pasta::TypeSpecifierType e) {
  switch (e) {
    case pasta::TypeSpecifierType::kUnspecified: return TypeSpecifierType::UNSPECIFIED;
    case pasta::TypeSpecifierType::kVoid: return TypeSpecifierType::VOID;
    case pasta::TypeSpecifierType::kCharacter: return TypeSpecifierType::CHARACTER;
    case pasta::TypeSpecifierType::kWchar: return TypeSpecifierType::WCHAR;
    case pasta::TypeSpecifierType::kChar8: return TypeSpecifierType::CHAR8;
    case pasta::TypeSpecifierType::kChar16: return TypeSpecifierType::CHAR16;
    case pasta::TypeSpecifierType::kChar32: return TypeSpecifierType::CHAR32;
    case pasta::TypeSpecifierType::kInt: return TypeSpecifierType::INT;
    case pasta::TypeSpecifierType::kInt128: return TypeSpecifierType::INT128;
    case pasta::TypeSpecifierType::kExtint: return TypeSpecifierType::EXTINT;
    case pasta::TypeSpecifierType::kHalf: return TypeSpecifierType::HALF;
    case pasta::TypeSpecifierType::kFloat16: return TypeSpecifierType::FLOAT16;
    case pasta::TypeSpecifierType::kAccum: return TypeSpecifierType::ACCUM;
    case pasta::TypeSpecifierType::kFract: return TypeSpecifierType::FRACT;
    case pasta::TypeSpecifierType::kBFloat16: return TypeSpecifierType::B_FLOAT16;
    case pasta::TypeSpecifierType::kFloat: return TypeSpecifierType::FLOAT;
    case pasta::TypeSpecifierType::kDouble: return TypeSpecifierType::DOUBLE;
    case pasta::TypeSpecifierType::kFloat128: return TypeSpecifierType::FLOAT128;
    case pasta::TypeSpecifierType::kBoolean: return TypeSpecifierType::BOOLEAN;
    case pasta::TypeSpecifierType::kDecimal32: return TypeSpecifierType::DECIMAL32;
    case pasta::TypeSpecifierType::kDecimal64: return TypeSpecifierType::DECIMAL64;
    case pasta::TypeSpecifierType::kDecimal128: return TypeSpecifierType::DECIMAL128;
    case pasta::TypeSpecifierType::kEnum: return TypeSpecifierType::ENUM;
    case pasta::TypeSpecifierType::kUnion: return TypeSpecifierType::UNION;
    case pasta::TypeSpecifierType::kStruct: return TypeSpecifierType::STRUCT;
    case pasta::TypeSpecifierType::kClass: return TypeSpecifierType::CLASS;
    case pasta::TypeSpecifierType::kInterface: return TypeSpecifierType::INTERFACE;
    case pasta::TypeSpecifierType::kTypename: return TypeSpecifierType::TYPENAME;
    case pasta::TypeSpecifierType::kTypeofType: return TypeSpecifierType::TYPEOF_TYPE;
    case pasta::TypeSpecifierType::kTypeofExpression: return TypeSpecifierType::TYPEOF_EXPRESSION;
    case pasta::TypeSpecifierType::kDecltype: return TypeSpecifierType::DECLTYPE;
    case pasta::TypeSpecifierType::kUnderlyingType: return TypeSpecifierType::UNDERLYING_TYPE;
    case pasta::TypeSpecifierType::kAuto: return TypeSpecifierType::AUTO;
    case pasta::TypeSpecifierType::kDecltypeAuto: return TypeSpecifierType::DECLTYPE_AUTO;
    case pasta::TypeSpecifierType::kAutoType: return TypeSpecifierType::AUTO_TYPE;
    case pasta::TypeSpecifierType::kUnknownAnytype: return TypeSpecifierType::UNKNOWN_ANYTYPE;
    case pasta::TypeSpecifierType::kAtomic: return TypeSpecifierType::ATOMIC;
    case pasta::TypeSpecifierType::kImage1dT: return TypeSpecifierType::IMAGE1_DT;
    case pasta::TypeSpecifierType::kImage1dArrayT: return TypeSpecifierType::IMAGE1_DARRAY_T;
    case pasta::TypeSpecifierType::kImage1dBufferT: return TypeSpecifierType::IMAGE1_DBUFFER_T;
    case pasta::TypeSpecifierType::kImage2dT: return TypeSpecifierType::IMAGE2_DT;
    case pasta::TypeSpecifierType::kImage2dArrayT: return TypeSpecifierType::IMAGE2_DARRAY_T;
    case pasta::TypeSpecifierType::kImage2dDepthT: return TypeSpecifierType::IMAGE2_DDEPTH_T;
    case pasta::TypeSpecifierType::kImage2dArrayDepthT: return TypeSpecifierType::IMAGE2_DARRAY_DEPTH_T;
    case pasta::TypeSpecifierType::kImage2dMsaaT: return TypeSpecifierType::IMAGE2_DMSAA_T;
    case pasta::TypeSpecifierType::kImage2dArrayMsaaT: return TypeSpecifierType::IMAGE2_DARRAY_MSAA_T;
    case pasta::TypeSpecifierType::kImage2dMsaaDepthT: return TypeSpecifierType::IMAGE2_DMSAA_DEPTH_T;
    case pasta::TypeSpecifierType::kImage2dArrayMsaaDepthT: return TypeSpecifierType::IMAGE2_DARRAY_MSAA_DEPTH_T;
    case pasta::TypeSpecifierType::kImage3dT: return TypeSpecifierType::IMAGE3_DT;
    case pasta::TypeSpecifierType::kError: return TypeSpecifierType::ERROR;
  }
}

TypeSpecifierWidth FromPasta(pasta::TypeSpecifierWidth e) {
  switch (e) {
    case pasta::TypeSpecifierWidth::kUnspecified: return TypeSpecifierWidth::UNSPECIFIED;
    case pasta::TypeSpecifierWidth::kShort: return TypeSpecifierWidth::SHORT;
    case pasta::TypeSpecifierWidth::kLong: return TypeSpecifierWidth::LONG;
    case pasta::TypeSpecifierWidth::kLongLong: return TypeSpecifierWidth::LONG_LONG;
  }
}

TypeSpecifiersPipe FromPasta(pasta::TypeSpecifiersPipe e) {
  switch (e) {
    case pasta::TypeSpecifiersPipe::kUnspecified: return TypeSpecifiersPipe::UNSPECIFIED;
    case pasta::TypeSpecifiersPipe::kPipe: return TypeSpecifiersPipe::PIPE;
  }
}

TypeTrait FromPasta(pasta::TypeTrait e) {
  switch (e) {
    case pasta::TypeTrait::kIsInterfaceClass: return TypeTrait::IS_INTERFACE_CLASS;
    case pasta::TypeTrait::kIsSealed: return TypeTrait::IS_SEALED;
    case pasta::TypeTrait::kIsDestructible: return TypeTrait::IS_DESTRUCTIBLE;
    case pasta::TypeTrait::kIsTriviallyDestructible: return TypeTrait::IS_TRIVIALLY_DESTRUCTIBLE;
    case pasta::TypeTrait::kIsNothrowDestructible: return TypeTrait::IS_NOTHROW_DESTRUCTIBLE;
    case pasta::TypeTrait::kHasNothrowMoveAssign: return TypeTrait::HAS_NOTHROW_MOVE_ASSIGN;
    case pasta::TypeTrait::kHasTrivialMoveAssign: return TypeTrait::HAS_TRIVIAL_MOVE_ASSIGN;
    case pasta::TypeTrait::kHasTrivialMoveConstructor: return TypeTrait::HAS_TRIVIAL_MOVE_CONSTRUCTOR;
    case pasta::TypeTrait::kHasNothrowAssign: return TypeTrait::HAS_NOTHROW_ASSIGN;
    case pasta::TypeTrait::kHasNothrowCopy: return TypeTrait::HAS_NOTHROW_COPY;
    case pasta::TypeTrait::kHasNothrowConstructor: return TypeTrait::HAS_NOTHROW_CONSTRUCTOR;
    case pasta::TypeTrait::kHasTrivialAssign: return TypeTrait::HAS_TRIVIAL_ASSIGN;
    case pasta::TypeTrait::kHasTrivialCopy: return TypeTrait::HAS_TRIVIAL_COPY;
    case pasta::TypeTrait::kHasTrivialDefaultConstructor: return TypeTrait::HAS_TRIVIAL_DEFAULT_CONSTRUCTOR;
    case pasta::TypeTrait::kHasTrivialDestructor: return TypeTrait::HAS_TRIVIAL_DESTRUCTOR;
    case pasta::TypeTrait::kHasVirtualDestructor: return TypeTrait::HAS_VIRTUAL_DESTRUCTOR;
    case pasta::TypeTrait::kIsAbstract: return TypeTrait::IS_ABSTRACT;
    case pasta::TypeTrait::kIsAggregate: return TypeTrait::IS_AGGREGATE;
    case pasta::TypeTrait::kIsClass: return TypeTrait::IS_CLASS;
    case pasta::TypeTrait::kIsEmpty: return TypeTrait::IS_EMPTY;
    case pasta::TypeTrait::kIsEnum: return TypeTrait::IS_ENUM;
    case pasta::TypeTrait::kIsFinal: return TypeTrait::IS_FINAL;
    case pasta::TypeTrait::kIsLiteral: return TypeTrait::IS_LITERAL;
    case pasta::TypeTrait::kIsPOD: return TypeTrait::IS_POD;
    case pasta::TypeTrait::kIsPolymorphic: return TypeTrait::IS_POLYMORPHIC;
    case pasta::TypeTrait::kIsStandardLayout: return TypeTrait::IS_STANDARD_LAYOUT;
    case pasta::TypeTrait::kIsTrivial: return TypeTrait::IS_TRIVIAL;
    case pasta::TypeTrait::kIsTriviallyCopyable: return TypeTrait::IS_TRIVIALLY_COPYABLE;
    case pasta::TypeTrait::kIsUnion: return TypeTrait::IS_UNION;
    case pasta::TypeTrait::kHasUniqueObjectRepresentations: return TypeTrait::HAS_UNIQUE_OBJECT_REPRESENTATIONS;
    case pasta::TypeTrait::kIsArithmetic: return TypeTrait::IS_ARITHMETIC;
    case pasta::TypeTrait::kIsFloatingPoint: return TypeTrait::IS_FLOATING_POINT;
    case pasta::TypeTrait::kIsIntegral: return TypeTrait::IS_INTEGRAL;
    case pasta::TypeTrait::kIsCompleteType: return TypeTrait::IS_COMPLETE_TYPE;
    case pasta::TypeTrait::kIsVoid: return TypeTrait::IS_VOID;
    case pasta::TypeTrait::kIsArray: return TypeTrait::IS_ARRAY;
    case pasta::TypeTrait::kIsFunction: return TypeTrait::IS_FUNCTION;
    case pasta::TypeTrait::kIsReference: return TypeTrait::IS_REFERENCE;
    case pasta::TypeTrait::kIsLvalueReference: return TypeTrait::IS_LVALUE_REFERENCE;
    case pasta::TypeTrait::kIsRvalueReference: return TypeTrait::IS_RVALUE_REFERENCE;
    case pasta::TypeTrait::kIsFundamental: return TypeTrait::IS_FUNDAMENTAL;
    case pasta::TypeTrait::kIsObject: return TypeTrait::IS_OBJECT;
    case pasta::TypeTrait::kIsScalar: return TypeTrait::IS_SCALAR;
    case pasta::TypeTrait::kIsCompound: return TypeTrait::IS_COMPOUND;
    case pasta::TypeTrait::kIsPointer: return TypeTrait::IS_POINTER;
    case pasta::TypeTrait::kIsMemberObjectPointer: return TypeTrait::IS_MEMBER_OBJECT_POINTER;
    case pasta::TypeTrait::kIsMemberFunctionPointer: return TypeTrait::IS_MEMBER_FUNCTION_POINTER;
    case pasta::TypeTrait::kIsMemberPointer: return TypeTrait::IS_MEMBER_POINTER;
    case pasta::TypeTrait::kIsConst: return TypeTrait::IS_CONST;
    case pasta::TypeTrait::kIsVolatile: return TypeTrait::IS_VOLATILE;
    case pasta::TypeTrait::kIsSigned: return TypeTrait::IS_SIGNED;
    case pasta::TypeTrait::kIsUnsigned: return TypeTrait::IS_UNSIGNED;
    case pasta::TypeTrait::kTypeCompatible: return TypeTrait::TYPE_COMPATIBLE;
    case pasta::TypeTrait::kIsNothrowAssignable: return TypeTrait::IS_NOTHROW_ASSIGNABLE;
    case pasta::TypeTrait::kIsAssignable: return TypeTrait::IS_ASSIGNABLE;
    case pasta::TypeTrait::kIsBaseOf: return TypeTrait::IS_BASE_OF;
    case pasta::TypeTrait::kIsConvertibleTo: return TypeTrait::IS_CONVERTIBLE_TO;
    case pasta::TypeTrait::kIsTriviallyAssignable: return TypeTrait::IS_TRIVIALLY_ASSIGNABLE;
    case pasta::TypeTrait::kReferenceBindsToTemporary: return TypeTrait::REFERENCE_BINDS_TO_TEMPORARY;
    case pasta::TypeTrait::kIsSame: return TypeTrait::IS_SAME;
    case pasta::TypeTrait::kIsConvertible: return TypeTrait::IS_CONVERTIBLE;
    case pasta::TypeTrait::kIsConstructible: return TypeTrait::IS_CONSTRUCTIBLE;
    case pasta::TypeTrait::kIsNothrowConstructible: return TypeTrait::IS_NOTHROW_CONSTRUCTIBLE;
    case pasta::TypeTrait::kIsTriviallyConstructible: return TypeTrait::IS_TRIVIALLY_CONSTRUCTIBLE;
  }
}

UnaryExprOrTypeTrait FromPasta(pasta::UnaryExprOrTypeTrait e) {
  switch (e) {
    case pasta::UnaryExprOrTypeTrait::kSizeOf: return UnaryExprOrTypeTrait::SIZE_OF;
    case pasta::UnaryExprOrTypeTrait::kAlignOf: return UnaryExprOrTypeTrait::ALIGN_OF;
    case pasta::UnaryExprOrTypeTrait::kPreferredAlignOf: return UnaryExprOrTypeTrait::PREFERRED_ALIGN_OF;
    case pasta::UnaryExprOrTypeTrait::kVecStep: return UnaryExprOrTypeTrait::VEC_STEP;
    case pasta::UnaryExprOrTypeTrait::kOpenMPRequiredSimdAlign: return UnaryExprOrTypeTrait::OPEN_MP_REQUIRED_SIMD_ALIGN;
  }
}

UnaryOperatorKind FromPasta(pasta::UnaryOperatorKind e) {
  switch (e) {
    case pasta::UnaryOperatorKind::kPostIncrement: return UnaryOperatorKind::POST_INCREMENT;
    case pasta::UnaryOperatorKind::kPostDec: return UnaryOperatorKind::POST_DEC;
    case pasta::UnaryOperatorKind::kPreIncrement: return UnaryOperatorKind::PRE_INCREMENT;
    case pasta::UnaryOperatorKind::kPreDec: return UnaryOperatorKind::PRE_DEC;
    case pasta::UnaryOperatorKind::kAddrOf: return UnaryOperatorKind::ADDR_OF;
    case pasta::UnaryOperatorKind::kDeref: return UnaryOperatorKind::DEREF;
    case pasta::UnaryOperatorKind::kPlus: return UnaryOperatorKind::PLUS;
    case pasta::UnaryOperatorKind::kMinus: return UnaryOperatorKind::MINUS;
    case pasta::UnaryOperatorKind::kNot: return UnaryOperatorKind::NOT;
    case pasta::UnaryOperatorKind::kLNot: return UnaryOperatorKind::L_NOT;
    case pasta::UnaryOperatorKind::kReal: return UnaryOperatorKind::REAL;
    case pasta::UnaryOperatorKind::kImag: return UnaryOperatorKind::IMAG;
    case pasta::UnaryOperatorKind::kExtension: return UnaryOperatorKind::EXTENSION;
    case pasta::UnaryOperatorKind::kCoawait: return UnaryOperatorKind::COAWAIT;
  }
}

APValueKind FromPasta(pasta::APValueKind e) {
  switch (e) {
    case pasta::APValueKind::kNone: return APValueKind::NONE;
    case pasta::APValueKind::kIndeterminate: return APValueKind::INDETERMINATE;
    case pasta::APValueKind::kInt: return APValueKind::INT;
    case pasta::APValueKind::kFloat: return APValueKind::FLOAT;
    case pasta::APValueKind::kFixedPoint: return APValueKind::FIXED_POINT;
    case pasta::APValueKind::kComplexInt: return APValueKind::COMPLEX_INT;
    case pasta::APValueKind::kComplexFloat: return APValueKind::COMPLEX_FLOAT;
    case pasta::APValueKind::kLValue: return APValueKind::L_VALUE;
    case pasta::APValueKind::kVector: return APValueKind::VECTOR;
    case pasta::APValueKind::kArray: return APValueKind::ARRAY;
    case pasta::APValueKind::kStruct: return APValueKind::STRUCT;
    case pasta::APValueKind::kUnion: return APValueKind::UNION;
    case pasta::APValueKind::kMemberPointer: return APValueKind::MEMBER_POINTER;
    case pasta::APValueKind::kAddrLabelDiff: return APValueKind::ADDR_LABEL_DIFF;
  }
}

VectorLibrary FromPasta(pasta::VectorLibrary e) {
  switch (e) {
    case pasta::VectorLibrary::kNoLibrary: return VectorLibrary::NO_LIBRARY;
    case pasta::VectorLibrary::kAccelerate: return VectorLibrary::ACCELERATE;
    case pasta::VectorLibrary::kLIBMVEC: return VectorLibrary::LIBMVEC;
    case pasta::VectorLibrary::kMASSV: return VectorLibrary::MASSV;
    case pasta::VectorLibrary::kSVML: return VectorLibrary::SVML;
    case pasta::VectorLibrary::kDarwinLibsystemM: return VectorLibrary::DARWIN_LIBSYSTEM_M;
  }
}

Visibility FromPasta(pasta::Visibility e) {
  switch (e) {
    case pasta::Visibility::kHiddenVisibility: return Visibility::HIDDEN_VISIBILITY;
    case pasta::Visibility::kProtectedVisibility: return Visibility::PROTECTED_VISIBILITY;
    case pasta::Visibility::kDefaultVisibility: return Visibility::DEFAULT_VISIBILITY;
  }
}

VisibilityType FromPasta(pasta::VisibilityType e) {
  switch (e) {
    case pasta::VisibilityType::kDefault: return VisibilityType::DEFAULT;
    case pasta::VisibilityType::kHidden: return VisibilityType::HIDDEN;
    case pasta::VisibilityType::kProtected: return VisibilityType::PROTECTED;
  }
}

PathKind FromPasta(pasta::PathKind e) {
  switch (e) {
    case pasta::PathKind::kUnix: return PathKind::UNIX;
    case pasta::PathKind::kWindows: return PathKind::WINDOWS;
  }
}

FileType FromPasta(pasta::FileType e) {
  switch (e) {
    case pasta::FileType::kNone: return FileType::NONE;
    case pasta::FileType::kNotFound: return FileType::NOT_FOUND;
    case pasta::FileType::kRegular: return FileType::REGULAR;
    case pasta::FileType::kDirectory: return FileType::DIRECTORY;
    case pasta::FileType::kSymbolicLink: return FileType::SYMBOLIC_LINK;
    case pasta::FileType::kBlock: return FileType::BLOCK;
    case pasta::FileType::kCharacter: return FileType::CHARACTER;
    case pasta::FileType::kFirstInFirstOut: return FileType::FIRST_IN_FIRST_OUT;
    case pasta::FileType::kSocket: return FileType::SOCKET;
    case pasta::FileType::kKnknown: return FileType::KNKNOWN;
  }
}

CompilerName FromPasta(pasta::CompilerName e) {
  switch (e) {
    case pasta::CompilerName::kUnknown: return CompilerName::UNKNOWN;
    case pasta::CompilerName::kClang: return CompilerName::CLANG;
    case pasta::CompilerName::kAppleClang: return CompilerName::APPLE_CLANG;
    case pasta::CompilerName::kClangCL: return CompilerName::CLANG_CL;
    case pasta::CompilerName::kCL: return CompilerName::CL;
    case pasta::CompilerName::kGNU: return CompilerName::GNU;
  }
}

IncludePathLocation FromPasta(pasta::IncludePathLocation e) {
  switch (e) {
    case pasta::IncludePathLocation::kAbsolute: return IncludePathLocation::ABSOLUTE;
    case pasta::IncludePathLocation::kSysrootRelative: return IncludePathLocation::SYSROOT_RELATIVE;
  }
}

TargetLanguage FromPasta(pasta::TargetLanguage e) {
  switch (e) {
    case pasta::TargetLanguage::kC: return TargetLanguage::C;
    case pasta::TargetLanguage::kCXX: return TargetLanguage::CXX;
  }
}

}  // namespace mx
