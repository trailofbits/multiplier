// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>
#include <filesystem>
#include <memory>
#include <optional>
#include <vector>

#include "Iterator.h"
#include "Types.h"

namespace pasta {
enum class DeclKind : unsigned;
enum class ArrayTypeArraySizeModifier : unsigned;
enum class AtomicExprAtomicOp : unsigned;
enum class BuiltinTypeKind : unsigned;
enum class CXXConstructExprConstructionKind : unsigned;
enum class CXXNewExprInitializationStyle : unsigned;
enum class CallExprADLCallKind : bool;
enum class CapturedStmtVariableCaptureKind : unsigned;
enum class CharacterLiteralCharacterKind : unsigned;
enum class ConstantExprResultStorageKind : unsigned;
enum class DeclFriendObjectKind : unsigned;
enum class DeclIdentifierNamespace : unsigned;
enum class DeclModuleOwnershipKind : unsigned;
enum class DeclObjCDeclQualifier : unsigned;
enum class ExprConstantExprKind : int;
enum class ExprLValueClassification : unsigned;
enum class ExprNullPointerConstantKind : unsigned;
enum class ExprNullPointerConstantValueDependence : unsigned;
enum class ExprSideEffectsKind : unsigned;
enum class ExprisModifiableLvalueResult : unsigned;
enum class FunctionDeclTemplatedKind : unsigned;
enum class ImplicitCastExprOnStack : unsigned;
enum class ImplicitParamDeclImplicitParamKind : unsigned;
enum class LinkageSpecDeclLanguageIDs : unsigned;
enum class NamedDeclExplicitVisibilityKind : unsigned;
enum class OMPDeclareReductionDeclInitKind : unsigned;
enum class ObjCIvarDeclAccessControl : unsigned;
enum class ObjCMessageExprReceiverKind : unsigned;
enum class ObjCMethodDeclImplementationControl : unsigned;
enum class ObjCPropertyDeclPropertyControl : unsigned;
enum class ObjCPropertyDeclSetterKind : unsigned;
enum class ObjCPropertyImplDeclKind : unsigned;
enum class PredefinedExprIdentKind : unsigned;
enum class QualTypeDestructionKind : unsigned;
enum class QualTypePrimitiveCopyKind : unsigned;
enum class QualTypePrimitiveDefaultInitializeKind : unsigned;
enum class RecordDeclArgPassingKind : unsigned;
enum class SourceLocExprIdentKind : unsigned;
enum class StmtLikelihood : int;
enum class StmtKind : unsigned;
enum class StringLiteralStringKind : unsigned;
enum class TemplateArgumentKind : unsigned;
enum class TypeScalarTypeKind : unsigned;
enum class TypeKind : unsigned;
enum class UnaryTransformTypeUTTKind : unsigned;
enum class UserDefinedLiteralLiteralOperatorKind : unsigned;
enum class VarDeclDefinitionKind : unsigned;
enum class VarDeclInitializationStyle : unsigned;
enum class VarDeclTLSKind : unsigned;
enum class VectorTypeVectorKind : unsigned;
enum class ASTDumpOutputFormat : unsigned;
enum class AccessSpecifier : unsigned;
enum class AddrSpaceMapMangling : unsigned;
enum class AllocatorTypeTy : unsigned;
enum class AltivecSrcCompatKind : int;
enum class ArgumentKind : unsigned;
enum class ArrayTypeTrait : unsigned;
enum class AtomicScopeModelKind : int;
enum class AttributeKind : unsigned;
enum class AutoTypeKeyword : int;
enum class AvailabilityResult : unsigned;
enum class BinaryOperatorKind : unsigned;
enum class Bits : unsigned char;
enum class BlockType : unsigned;
enum class BranchStateTy : unsigned;
enum class CallingConv : unsigned;
enum class CanThrowResult : unsigned;
enum class CapturedRegionKind : unsigned;
enum class CastKind : unsigned;
enum class ClangABI : int;
enum class CommentKind : unsigned;
enum class ComparisonCategoryResult : unsigned char;
enum class ComparisonCategoryType : unsigned char;
enum class CompilingModuleKind : unsigned;
enum class ConstexprSpecKind : int;
enum class ConsumedState : unsigned;
enum class ConventionKind : unsigned;
enum class CoreFoundationABI : int;
enum class DefaultArgKind : unsigned;
enum class DefaultCallingConvention : unsigned;
enum class DevTypeTy : unsigned;
enum class DiagnosticLevelMask : unsigned;
enum class DiagnosticType : unsigned;
enum class ElaboratedTypeKeyword : unsigned;
enum class EmbedBitcodeKind : unsigned;
enum class ExceptionHandlingKind : int;
enum class ExceptionSpecificationType : unsigned;
enum class ExplicitSpecKind : unsigned;
enum class ExprDependence : unsigned char;
enum class ExprObjectKind : unsigned;
enum class ExprOffsets : int;
enum class ExprValueKind : unsigned;
enum class ExpressionTrait : unsigned;
enum class ExtKind : unsigned;
enum class ExtendArgsKind : int;
enum class FPExceptionModeKind : unsigned;
enum class FPModeKind : unsigned;
enum class FamilyKind : unsigned;
enum class FiniteLoopsKind : unsigned;
enum class FramePointerKind : int;
enum class GC : unsigned;
enum class GCMode : unsigned;
enum class GVALinkage : unsigned;
enum class GetBuiltinTypeError : unsigned;
enum class GuardArg : unsigned;
enum class ID : unsigned;
enum class IdentifierInfoFlag : unsigned;
enum class ImbueAttribute : int;
enum class ImplicitReason : unsigned;
enum class InClassInitStyle : unsigned;
enum class InheritedDesignatedInitializersState : unsigned;
enum class InitStorageKind : unsigned;
enum class InlineVariableDefinitionKind : int;
enum class InliningMethod : unsigned;
enum class InterruptType : unsigned;
enum class Kinds : unsigned;
enum class LambdaCaptureDefault : unsigned;
enum class LambdaCaptureKind : unsigned;
enum class LangAS : unsigned;
enum class LangFeatures : unsigned;
enum class Language : unsigned char;
enum class LanguageLinkage : unsigned;
enum class LaxVectorConversionKind : int;
enum class Level : unsigned;
enum class Linkage : unsigned char;
enum class LoopHintState : unsigned;
enum class MSInheritanceModel : int;
enum class MSVCMajorVersion : unsigned;
enum class MSVtorDispMode : int;
enum class MapTypeTy : unsigned;
enum class MethodRefFlags : unsigned;
enum class ModifiableType : unsigned;
enum class MultiVersionKind : int;
enum class NameKind : unsigned;
enum class NeedExtraManglingDecl : unsigned;
enum class NestedNameSpecifierDependence : unsigned char;
enum class NewtypeKind : unsigned;
enum class NonOdrUseReason : unsigned;
enum class NonceObjCInterface : unsigned;
enum class NullabilityKind : unsigned char;
enum class ObjCBridgeCastKind : unsigned;
enum class ObjCDispatchMethodKind : unsigned;
enum class ObjCInstanceTypeFamily : unsigned;
enum class ObjCKeywordKind : unsigned;
enum class ObjCLifetime : unsigned;
enum class ObjCMethodFamily : unsigned;
enum class ObjCPropertyQueryKind : unsigned char;
enum class ObjCStringFormatFamily : unsigned;
enum class ObjCSubstitutionContext : int;
enum class ObjCTypeParamVariance : unsigned char;
enum class OnOffSwitch : unsigned;
enum class OnStackType : unsigned;
enum class OpenMPAtomicDefaultMemOrderClauseKind : unsigned;
enum class OpenMPDefaultmapClauseKind : unsigned;
enum class OpenMPDefaultmapClauseModifier : unsigned;
enum class OpenMPDependClauseKind : unsigned;
enum class OpenMPDeviceClauseModifier : unsigned;
enum class OpenMPDeviceType : unsigned;
enum class OpenMPDistScheduleClauseKind : unsigned;
enum class OpenMPLastprivateModifier : unsigned;
enum class OpenMPLinearClauseKind : unsigned;
enum class OpenMPMapClauseKind : unsigned;
enum class OpenMPMapModifierKind : unsigned;
enum class OpenMPMotionModifierKind : unsigned;
enum class OpenMPOrderClauseKind : unsigned;
enum class OpenMPReductionClauseModifier : unsigned;
enum class OpenMPScheduleClauseKind : unsigned;
enum class OpenMPScheduleClauseModifier : unsigned;
enum class OptionType : unsigned;
enum class OverloadedOperatorKind : int;
enum class OverloadsShown : unsigned;
enum class OwnershipKind : unsigned;
enum class PCSType : unsigned;
enum class PPKeywordKind : unsigned;
enum class ParameterABI : int;
enum class ParenLocsOffsets : int;
enum class PragmaFloatControlKind : unsigned;
enum class PragmaMSCommentKind : unsigned;
enum class PragmaMSPointersToMembersKind : unsigned;
enum class PragmaMSStructKind : unsigned;
enum class PragmaSectionFlag : unsigned;
enum class ProfileInstrKind : unsigned;
enum class RangeExprOffset : int;
enum class RangeLocOffset : int;
enum class RefQualifierKind : unsigned;
enum class RemarkKind : unsigned;
enum class ReservedIdentifierStatus : int;
enum class SFINAEResponse : unsigned;
enum class SYCLMajorVersion : unsigned;
enum class SanitizerOrdinal : unsigned long long;
enum class SelectorLocationsKind : unsigned;
enum class SignReturnAddressKeyKind : int;
enum class SignReturnAddressScopeKind : int;
enum class SignedOverflowBehaviorTy : unsigned;
enum class SpecialMemberFlags : unsigned;
enum class SpecifierKind : unsigned;
enum class Spelling : unsigned;
enum class StackProtectorMode : unsigned;
enum class StorageClass : unsigned;
enum class StorageDuration : unsigned;
enum class StoredNameKind : unsigned;
enum class StoredSpecifierKind : unsigned;
enum class StructReturnConventionKind : unsigned;
enum class SubExpr : unsigned;
enum class SubStmt : unsigned;
enum class SyncScope : int;
enum class Syntax : unsigned;
enum class TLSModel : unsigned;
enum class TQ : unsigned;
enum class TagTypeKind : unsigned;
enum class TailPaddingUseRules : unsigned;
enum class TemplateArgumentDependence : unsigned char;
enum class TemplateNameDependence : unsigned char;
enum class TemplateSpecializationKind : unsigned;
enum class TextDiagnosticFormat : unsigned;
enum class ThreadModelKind : int;
enum class ThreadStorageClassSpecifier : unsigned;
enum class TokenKind : unsigned short;
enum class TrailingAllocKind : unsigned;
enum class TranslationUnitKind : unsigned;
enum class TrivialAutoVarInitKind : int;
enum class TypeDependence : unsigned char;
enum class TypeLocClass : unsigned;
enum class TypeSpecifierSign : int;
enum class TypeSpecifierType : unsigned;
enum class TypeSpecifierWidth : int;
enum class TypeSpecifiersPipe : int;
enum class TypeTrait : unsigned;
enum class UnaryExprOrTypeTrait : unsigned;
enum class UnaryOperatorKind : unsigned;
enum class APValueKind : unsigned;
enum class VectorLibrary : unsigned;
enum class Visibility : unsigned;
enum class VisibilityType : unsigned;
enum class PathKind : signed char;
enum class FileType : signed char;
enum class CompilerName : unsigned;
enum class IncludePathLocation : unsigned;
enum class TargetLanguage : unsigned;
}  // namespace pasta
namespace mx {

class DeclIterator;
class FragmentImpl;
class FileImpl;
class StmtIterator;
class Token;
class TokenContext;class TokenContextIterator;
class TokenRange;

enum class DeclKind : unsigned short {
  ACCESS_SPEC,
  BASE_USING,
  BINDING,
  BLOCK,
  BUILTIN_TEMPLATE,
  CXX_CONSTRUCTOR,
  CXX_CONVERSION,
  CXX_DEDUCTION_GUIDE,
  CXX_DESTRUCTOR,
  CXX_METHOD,
  CXX_RECORD,
  CAPTURED,
  CLASS_SCOPE_FUNCTION_SPECIALIZATION,
  CLASS_TEMPLATE,
  CLASS_TEMPLATE_PARTIAL_SPECIALIZATION,
  CLASS_TEMPLATE_SPECIALIZATION,
  CONCEPT,
  CONSTRUCTOR_USING_SHADOW,
  DECLARATOR,
  DECOMPOSITION,
  EMPTY,
  ENUM_CONSTANT,
  ENUM,
  EXPORT,
  EXTERN_C_CONTEXT,
  FIELD,
  FILE_SCOPE_ASM,
  FRIEND,
  FRIEND_TEMPLATE,
  FUNCTION,
  FUNCTION_TEMPLATE,
  IMPLICIT_PARAM,
  IMPORT,
  INDIRECT_FIELD,
  LABEL,
  LIFETIME_EXTENDED_TEMPORARY,
  LINKAGE_SPEC,
  MS_GUID,
  MS_PROPERTY,
  NAMED,
  NAMESPACE_ALIAS,
  NAMESPACE,
  NON_TYPE_TEMPLATE_PARM,
  OMP_ALLOCATE,
  OMP_CAPTURED_EXPR,
  OMP_DECLARE_MAPPER,
  OMP_DECLARE_REDUCTION,
  OMP_REQUIRES,
  OMP_THREAD_PRIVATE,
  OBJ_C_AT_DEFS_FIELD,
  OBJ_C_CATEGORY,
  OBJ_C_CATEGORY_IMPL,
  OBJ_C_COMPATIBLE_ALIAS,
  OBJ_C_CONTAINER,
  OBJ_C_IMPL,
  OBJ_C_IMPLEMENTATION,
  OBJ_C_INTERFACE,
  OBJ_C_IVAR,
  OBJ_C_METHOD,
  OBJ_C_PROPERTY,
  OBJ_C_PROPERTY_IMPL,
  OBJ_C_PROTOCOL,
  OBJ_C_TYPE_PARAM,
  PARM_VAR,
  PRAGMA_COMMENT,
  PRAGMA_DETECT_MISMATCH,
  RECORD,
  REDECLARABLE_TEMPLATE,
  REQUIRES_EXPR_BODY,
  STATIC_ASSERT,
  TAG,
  TEMPLATE,
  TEMPLATE_PARAM_OBJECT,
  TEMPLATE_TEMPLATE_PARM,
  TEMPLATE_TYPE_PARM,
  TRANSLATION_UNIT,
  TYPE_ALIAS,
  TYPE_ALIAS_TEMPLATE,
  TYPE,
  TYPEDEF,
  TYPEDEF_NAME,
  UNRESOLVED_USING_IF_EXISTS,
  UNRESOLVED_USING_TYPENAME,
  UNRESOLVED_USING_VALUE,
  USING,
  USING_DIRECTIVE,
  USING_ENUM,
  USING_PACK,
  USING_SHADOW,
  VALUE,
  VAR,
  VAR_TEMPLATE,
  VAR_TEMPLATE_PARTIAL_SPECIALIZATION,
  VAR_TEMPLATE_SPECIALIZATION,
  NUM_ENUMERATORS
};

DeclKind FromPasta(pasta::DeclKind pasta_val);

inline static const char *EnumerationName(DeclKind) {
  return "DeclKind";
}

const char *EnumeratorName(DeclKind);

enum class ArrayTypeArraySizeModifier : unsigned short {
  NORMAL,
  STATIC,
  STAR,
  NUM_ENUMERATORS
};

ArrayTypeArraySizeModifier FromPasta(pasta::ArrayTypeArraySizeModifier pasta_val);

inline static const char *EnumerationName(ArrayTypeArraySizeModifier) {
  return "ArrayTypeArraySizeModifier";
}

const char *EnumeratorName(ArrayTypeArraySizeModifier);

enum class AtomicExprAtomicOp : unsigned short {
  C11_ATOMIC_INITIALIZER,
  C11_ATOMIC_LOAD,
  C11_ATOMIC_STORE,
  C11_ATOMIC_EXCHANGE,
  C11_ATOMIC_COMPARE_EXCHANGE_STRONG,
  C11_ATOMIC_COMPARE_EXCHANGE_WEAK,
  C11_ATOMIC_FETCH_ADD,
  C11_ATOMIC_FETCH_SUB,
  C11_ATOMIC_FETCH_AND,
  C11_ATOMIC_FETCH_OR,
  C11_ATOMIC_FETCH_XOR,
  C11_ATOMIC_FETCH_MAX,
  C11_ATOMIC_FETCH_MIN,
  ATOMIC_LOAD,
  ATOMIC_LOAD_N,
  ATOMIC_STORE,
  ATOMIC_STORE_N,
  ATOMIC_EXCHANGE,
  ATOMIC_EXCHANGE_N,
  ATOMIC_COMPARE_EXCHANGE,
  ATOMIC_COMPARE_EXCHANGE_N,
  ATOMIC_FETCH_ADD,
  ATOMIC_FETCH_SUB,
  ATOMIC_FETCH_AND,
  ATOMIC_FETCH_OR,
  ATOMIC_FETCH_XOR,
  ATOMIC_FETCH_NAND,
  ATOMIC_ADD_FETCH,
  ATOMIC_SUB_FETCH,
  ATOMIC_AND_FETCH,
  ATOMIC_OR_FETCH,
  ATOMIC_XOR_FETCH,
  ATOMIC_MAX_FETCH,
  ATOMIC_MIN_FETCH,
  ATOMIC_NAND_FETCH,
  OPENCL_ATOMIC_INITIALIZER,
  OPENCL_ATOMIC_LOAD,
  OPENCL_ATOMIC_STORE,
  OPENCL_ATOMIC_EXCHANGE,
  OPENCL_ATOMIC_COMPARE_EXCHANGE_STRONG,
  OPENCL_ATOMIC_COMPARE_EXCHANGE_WEAK,
  OPENCL_ATOMIC_FETCH_ADD,
  OPENCL_ATOMIC_FETCH_SUB,
  OPENCL_ATOMIC_FETCH_AND,
  OPENCL_ATOMIC_FETCH_OR,
  OPENCL_ATOMIC_FETCH_XOR,
  OPENCL_ATOMIC_FETCH_MIN,
  OPENCL_ATOMIC_FETCH_MAX,
  ATOMIC_FETCH_MIN,
  ATOMIC_FETCH_MAX,
  NUM_ENUMERATORS
};

AtomicExprAtomicOp FromPasta(pasta::AtomicExprAtomicOp pasta_val);

inline static const char *EnumerationName(AtomicExprAtomicOp) {
  return "AtomicExprAtomicOp";
}

const char *EnumeratorName(AtomicExprAtomicOp);

enum class BuiltinTypeKind : unsigned short {
  OCL_IMAGE1_DRO,
  OCL_IMAGE1_DARRAY_RO,
  OCL_IMAGE1_DBUFFER_RO,
  OCL_IMAGE2_DRO,
  OCL_IMAGE2_DARRAY_RO,
  OCL_IMAGE2_DDEPTH_RO,
  OCL_IMAGE2_DARRAY_DEPTH_RO,
  OCL_IMAGE2_DMSAARO,
  OCL_IMAGE2_DARRAY_MSAARO,
  OCL_IMAGE2_DMSAA_DEPTH_RO,
  OCL_IMAGE2_DARRAY_MSAA_DEPTH_RO,
  OCL_IMAGE3_DRO,
  OCL_IMAGE1_DWO,
  OCL_IMAGE1_DARRAY_WO,
  OCL_IMAGE1_DBUFFER_WO,
  OCL_IMAGE2_DWO,
  OCL_IMAGE2_DARRAY_WO,
  OCL_IMAGE2_DDEPTH_WO,
  OCL_IMAGE2_DARRAY_DEPTH_WO,
  OCL_IMAGE2_DMSAAWO,
  OCL_IMAGE2_DARRAY_MSAAWO,
  OCL_IMAGE2_DMSAA_DEPTH_WO,
  OCL_IMAGE2_DARRAY_MSAA_DEPTH_WO,
  OCL_IMAGE3_DWO,
  OCL_IMAGE1_DRW,
  OCL_IMAGE1_DARRAY_RW,
  OCL_IMAGE1_DBUFFER_RW,
  OCL_IMAGE2_DRW,
  OCL_IMAGE2_DARRAY_RW,
  OCL_IMAGE2_DDEPTH_RW,
  OCL_IMAGE2_DARRAY_DEPTH_RW,
  OCL_IMAGE2_DMSAARW,
  OCL_IMAGE2_DARRAY_MSAARW,
  OCL_IMAGE2_DMSAA_DEPTH_RW,
  OCL_IMAGE2_DARRAY_MSAA_DEPTH_RW,
  OCL_IMAGE3_DRW,
  OCL_INTEL_SUBGROUP_AVC_MCE_PAYLOAD,
  OCL_INTEL_SUBGROUP_AVC_IME_PAYLOAD,
  OCL_INTEL_SUBGROUP_AVC_REF_PAYLOAD,
  OCL_INTEL_SUBGROUP_AVC_SIC_PAYLOAD,
  OCL_INTEL_SUBGROUP_AVC_MCE_RESULT,
  OCL_INTEL_SUBGROUP_AVC_IME_RESULT,
  OCL_INTEL_SUBGROUP_AVC_REF_RESULT,
  OCL_INTEL_SUBGROUP_AVC_SIC_RESULT,
  OCL_INTEL_SUBGROUP_AVC_IME_RESULT_SINGLE_REFERENCE_STREAMOUT,
  OCL_INTEL_SUBGROUP_AVC_IME_RESULT_DUAL_REFERENCE_STREAMOUT,
  OCL_INTEL_SUBGROUP_AVC_IME_SINGLE_REFERENCE_STREAMIN,
  OCL_INTEL_SUBGROUP_AVC_IME_DUAL_REFERENCE_STREAMIN,
  SVE_INT8,
  SVE_INT16,
  SVE_INT32,
  SVE_INT64,
  SVE_UINT8,
  SVE_UINT16,
  SVE_UINT32,
  SVE_UINT64,
  SVE_FLOAT16,
  SVE_FLOAT32,
  SVE_FLOAT64,
  SVE_B_FLOAT16,
  SVE_INT8_X2,
  SVE_INT16_X2,
  SVE_INT32_X2,
  SVE_INT64_X2,
  SVE_UINT8_X2,
  SVE_UINT16_X2,
  SVE_UINT32_X2,
  SVE_UINT64_X2,
  SVE_FLOAT16_X2,
  SVE_FLOAT32_X2,
  SVE_FLOAT64_X2,
  SVE_B_FLOAT16_X2,
  SVE_INT8_X3,
  SVE_INT16_X3,
  SVE_INT32_X3,
  SVE_INT64_X3,
  SVE_UINT8_X3,
  SVE_UINT16_X3,
  SVE_UINT32_X3,
  SVE_UINT64_X3,
  SVE_FLOAT16_X3,
  SVE_FLOAT32_X3,
  SVE_FLOAT64_X3,
  SVE_B_FLOAT16_X3,
  SVE_INT8_X4,
  SVE_INT16_X4,
  SVE_INT32_X4,
  SVE_INT64_X4,
  SVE_UINT8_X4,
  SVE_UINT16_X4,
  SVE_UINT32_X4,
  SVE_UINT64_X4,
  SVE_FLOAT16_X4,
  SVE_FLOAT32_X4,
  SVE_FLOAT64_X4,
  SVE_B_FLOAT16_X4,
  SVE_BOOLEAN,
  VECTOR_QUAD,
  VECTOR_PAIR,
  RVV_INT8_MF8,
  RVV_INT8_MF4,
  RVV_INT8_MF2,
  RVV_INT8_M1,
  RVV_INT8_M2,
  RVV_INT8_M4,
  RVV_INT8_M8,
  RVV_UINT8_MF8,
  RVV_UINT8_MF4,
  RVV_UINT8_MF2,
  RVV_UINT8_M1,
  RVV_UINT8_M2,
  RVV_UINT8_M4,
  RVV_UINT8_M8,
  RVV_INT16_MF4,
  RVV_INT16_MF2,
  RVV_INT16_M1,
  RVV_INT16_M2,
  RVV_INT16_M4,
  RVV_INT16_M8,
  RVV_UINT16_MF4,
  RVV_UINT16_MF2,
  RVV_UINT16_M1,
  RVV_UINT16_M2,
  RVV_UINT16_M4,
  RVV_UINT16_M8,
  RVV_INT32_MF2,
  RVV_INT32_M1,
  RVV_INT32_M2,
  RVV_INT32_M4,
  RVV_INT32_M8,
  RVV_UINT32_MF2,
  RVV_UINT32_M1,
  RVV_UINT32_M2,
  RVV_UINT32_M4,
  RVV_UINT32_M8,
  RVV_INT64_M1,
  RVV_INT64_M2,
  RVV_INT64_M4,
  RVV_INT64_M8,
  RVV_UINT64_M1,
  RVV_UINT64_M2,
  RVV_UINT64_M4,
  RVV_UINT64_M8,
  RVV_FLOAT16_MF4,
  RVV_FLOAT16_MF2,
  RVV_FLOAT16_M1,
  RVV_FLOAT16_M2,
  RVV_FLOAT16_M4,
  RVV_FLOAT16_M8,
  RVV_FLOAT32_MF2,
  RVV_FLOAT32_M1,
  RVV_FLOAT32_M2,
  RVV_FLOAT32_M4,
  RVV_FLOAT32_M8,
  RVV_FLOAT64_M1,
  RVV_FLOAT64_M2,
  RVV_FLOAT64_M4,
  RVV_FLOAT64_M8,
  RVV_BOOL1,
  RVV_BOOL2,
  RVV_BOOL4,
  RVV_BOOL8,
  RVV_BOOL16,
  RVV_BOOL32,
  RVV_BOOL64,
  VOID,
  BOOLEAN,
  CHARACTER_U,
  U_CHAR,
  W_CHAR_U,
  CHAR8,
  CHAR16,
  CHAR32,
  U_SHORT,
  U_INT,
  U_LONG,
  U_LONG_LONG,
  U_INT128,
  CHARACTER_S,
  S_CHAR,
  W_CHAR_S,
  SHORT,
  INT,
  LONG,
  LONG_LONG,
  INT128,
  SHORT_ACCUM,
  ACCUM,
  LONG_ACCUM,
  U_SHORT_ACCUM,
  U_ACCUM,
  U_LONG_ACCUM,
  SHORT_FRACT,
  FRACT,
  LONG_FRACT,
  U_SHORT_FRACT,
  U_FRACT,
  U_LONG_FRACT,
  SAT_SHORT_ACCUM,
  SAT_ACCUM,
  SAT_LONG_ACCUM,
  SAT_U_SHORT_ACCUM,
  SAT_U_ACCUM,
  SAT_U_LONG_ACCUM,
  SAT_SHORT_FRACT,
  SAT_FRACT,
  SAT_LONG_FRACT,
  SAT_U_SHORT_FRACT,
  SAT_U_FRACT,
  SAT_U_LONG_FRACT,
  HALF,
  FLOAT,
  DOUBLE,
  LONG_DOUBLE,
  FLOAT16,
  B_FLOAT16,
  FLOAT128,
  NULL_POINTER,
  OBJ_C_ID,
  OBJ_C_CLASS,
  OBJ_C_SEL,
  OCL_SAMPLER,
  OCL_EVENT,
  OCL_CLK_EVENT,
  OCL_QUEUE,
  OCL_RESERVE_ID,
  DEPENDENT,
  OVERLOAD,
  BOUND_MEMBER,
  PSEUDO_OBJECT,
  UNKNOWN_ANY,
  BUILTIN_FN,
  ARC_UNBRIDGED_CAST,
  INCOMPLETE_MATRIX_INDEX,
  OMP_ARRAY_SECTION,
  OMP_ARRAY_SHAPING,
  OMP_ITERATOR,
  NUM_ENUMERATORS
};

BuiltinTypeKind FromPasta(pasta::BuiltinTypeKind pasta_val);

inline static const char *EnumerationName(BuiltinTypeKind) {
  return "BuiltinTypeKind";
}

const char *EnumeratorName(BuiltinTypeKind);

enum class CXXConstructExprConstructionKind : unsigned short {
  COMPLETE,
  NON_VIRTUAL_BASE,
  VIRTUAL_BASE,
  DELEGATING,
  NUM_ENUMERATORS
};

CXXConstructExprConstructionKind FromPasta(pasta::CXXConstructExprConstructionKind pasta_val);

inline static const char *EnumerationName(CXXConstructExprConstructionKind) {
  return "CXXConstructExprConstructionKind";
}

const char *EnumeratorName(CXXConstructExprConstructionKind);

enum class CXXNewExprInitializationStyle : unsigned short {
  NO_INITIALIZER,
  CALL_INITIALIZER,
  LIST_INITIALIZER,
  NUM_ENUMERATORS
};

CXXNewExprInitializationStyle FromPasta(pasta::CXXNewExprInitializationStyle pasta_val);

inline static const char *EnumerationName(CXXNewExprInitializationStyle) {
  return "CXXNewExprInitializationStyle";
}

const char *EnumeratorName(CXXNewExprInitializationStyle);

enum class CallExprADLCallKind : unsigned short {
  NOT_ADL,
  USES_ADL,
  NUM_ENUMERATORS
};

CallExprADLCallKind FromPasta(pasta::CallExprADLCallKind pasta_val);

inline static const char *EnumerationName(CallExprADLCallKind) {
  return "CallExprADLCallKind";
}

const char *EnumeratorName(CallExprADLCallKind);

enum class CapturedStmtVariableCaptureKind : unsigned short {
  THIS,
  BY_REFERENCE,
  BY_COPY,
  VLA_TYPE,
  NUM_ENUMERATORS
};

CapturedStmtVariableCaptureKind FromPasta(pasta::CapturedStmtVariableCaptureKind pasta_val);

inline static const char *EnumerationName(CapturedStmtVariableCaptureKind) {
  return "CapturedStmtVariableCaptureKind";
}

const char *EnumeratorName(CapturedStmtVariableCaptureKind);

enum class CharacterLiteralCharacterKind : unsigned short {
  ASCII,
  WIDE,
  UTF8,
  UTF16,
  UTF32,
  NUM_ENUMERATORS
};

CharacterLiteralCharacterKind FromPasta(pasta::CharacterLiteralCharacterKind pasta_val);

inline static const char *EnumerationName(CharacterLiteralCharacterKind) {
  return "CharacterLiteralCharacterKind";
}

const char *EnumeratorName(CharacterLiteralCharacterKind);

enum class ConstantExprResultStorageKind : unsigned short {
  NONE,
  INT64,
  AP_VALUE,
  NUM_ENUMERATORS
};

ConstantExprResultStorageKind FromPasta(pasta::ConstantExprResultStorageKind pasta_val);

inline static const char *EnumerationName(ConstantExprResultStorageKind) {
  return "ConstantExprResultStorageKind";
}

const char *EnumeratorName(ConstantExprResultStorageKind);

enum class DeclFriendObjectKind : unsigned short {
  NONE,
  DECLARED,
  UNDECLARED,
  NUM_ENUMERATORS
};

DeclFriendObjectKind FromPasta(pasta::DeclFriendObjectKind pasta_val);

inline static const char *EnumerationName(DeclFriendObjectKind) {
  return "DeclFriendObjectKind";
}

const char *EnumeratorName(DeclFriendObjectKind);

enum class DeclIdentifierNamespace : unsigned short {
  LABEL,
  TAG,
  TYPE,
  MEMBER,
  NAMESPACE,
  ORDINARY,
  OBJ_C_PROTOCOL,
  ORDINARY_FRIEND,
  TAG_FRIEND,
  USING,
  NON_MEMBER_OPERATOR,
  LOCAL_EXTERN,
  OMP_REDUCTION,
  OMP_MAPPER,
  NUM_ENUMERATORS
};

DeclIdentifierNamespace FromPasta(pasta::DeclIdentifierNamespace pasta_val);

inline static const char *EnumerationName(DeclIdentifierNamespace) {
  return "DeclIdentifierNamespace";
}

const char *EnumeratorName(DeclIdentifierNamespace);

enum class DeclModuleOwnershipKind : unsigned short {
  UNOWNED,
  VISIBLE,
  VISIBLE_WHEN_IMPORTED,
  MODULE_PRIVATE,
  NUM_ENUMERATORS
};

DeclModuleOwnershipKind FromPasta(pasta::DeclModuleOwnershipKind pasta_val);

inline static const char *EnumerationName(DeclModuleOwnershipKind) {
  return "DeclModuleOwnershipKind";
}

const char *EnumeratorName(DeclModuleOwnershipKind);

enum class DeclObjCDeclQualifier : unsigned short {
  NONE,
  IN,
  INOUT,
  OUT,
  BYCOPY,
  BYREF,
  ONEWAY,
  CS_NULLABILITY,
  NUM_ENUMERATORS
};

DeclObjCDeclQualifier FromPasta(pasta::DeclObjCDeclQualifier pasta_val);

inline static const char *EnumerationName(DeclObjCDeclQualifier) {
  return "DeclObjCDeclQualifier";
}

const char *EnumeratorName(DeclObjCDeclQualifier);

enum class ExprConstantExprKind : unsigned short {
  NORMAL,
  NON_CLASS_TEMPLATE_ARGUMENT,
  CLASS_TEMPLATE_ARGUMENT,
  IMMEDIATE_INVOCATION,
  NUM_ENUMERATORS
};

ExprConstantExprKind FromPasta(pasta::ExprConstantExprKind pasta_val);

inline static const char *EnumerationName(ExprConstantExprKind) {
  return "ExprConstantExprKind";
}

const char *EnumeratorName(ExprConstantExprKind);

enum class ExprLValueClassification : unsigned short {
  VALID,
  NOT_OBJECT_TYPE,
  INCOMPLETE_VOID_TYPE,
  DUPLICATE_VECTOR_COMPONENTS,
  INVALID_EXPRESSION,
  INVALID_MESSAGE_EXPRESSION,
  MEMBER_FUNCTION,
  SUB_OBJ_C_PROPERTY_SETTING,
  CLASS_TEMPORARY,
  ARRAY_TEMPORARY,
  NUM_ENUMERATORS
};

ExprLValueClassification FromPasta(pasta::ExprLValueClassification pasta_val);

inline static const char *EnumerationName(ExprLValueClassification) {
  return "ExprLValueClassification";
}

const char *EnumeratorName(ExprLValueClassification);

enum class ExprNullPointerConstantKind : unsigned short {
  NOT_NULL,
  ZERO_EXPRESSION,
  ZERO_LITERAL,
  CXX11_NULLPTR,
  GNU_NULL,
  NUM_ENUMERATORS
};

ExprNullPointerConstantKind FromPasta(pasta::ExprNullPointerConstantKind pasta_val);

inline static const char *EnumerationName(ExprNullPointerConstantKind) {
  return "ExprNullPointerConstantKind";
}

const char *EnumeratorName(ExprNullPointerConstantKind);

enum class ExprNullPointerConstantValueDependence : unsigned short {
  NEVER_VALUE_DEPENDENT,
  VALUE_DEPENDENT_IS_NULL,
  VALUE_DEPENDENT_IS_NOT_NULL,
  NUM_ENUMERATORS
};

ExprNullPointerConstantValueDependence FromPasta(pasta::ExprNullPointerConstantValueDependence pasta_val);

inline static const char *EnumerationName(ExprNullPointerConstantValueDependence) {
  return "ExprNullPointerConstantValueDependence";
}

const char *EnumeratorName(ExprNullPointerConstantValueDependence);

enum class ExprSideEffectsKind : unsigned short {
  NO_SIDE_EFFECTS,
  ALLOW_UNDEFINED_BEHAVIOR,
  ALLOW_SIDE_EFFECTS,
  NUM_ENUMERATORS
};

ExprSideEffectsKind FromPasta(pasta::ExprSideEffectsKind pasta_val);

inline static const char *EnumerationName(ExprSideEffectsKind) {
  return "ExprSideEffectsKind";
}

const char *EnumeratorName(ExprSideEffectsKind);

enum class ExprisModifiableLvalueResult : unsigned short {
  VALID,
  NOT_OBJECT_TYPE,
  INCOMPLETE_VOID_TYPE,
  DUPLICATE_VECTOR_COMPONENTS,
  INVALID_EXPRESSION,
  L_VALUE_CAST,
  INCOMPLETE_TYPE,
  CONST_QUALIFIED,
  CONST_QUALIFIED_FIELD,
  CONST_ADDR_SPACE,
  ARRAY_TYPE,
  NO_SETTER_PROPERTY,
  MEMBER_FUNCTION,
  SUB_OBJ_C_PROPERTY_SETTING,
  INVALID_MESSAGE_EXPRESSION,
  CLASS_TEMPORARY,
  ARRAY_TEMPORARY,
  NUM_ENUMERATORS
};

ExprisModifiableLvalueResult FromPasta(pasta::ExprisModifiableLvalueResult pasta_val);

inline static const char *EnumerationName(ExprisModifiableLvalueResult) {
  return "ExprisModifiableLvalueResult";
}

const char *EnumeratorName(ExprisModifiableLvalueResult);

enum class FunctionDeclTemplatedKind : unsigned short {
  NON_TEMPLATE,
  FUNCTION_TEMPLATE,
  MEMBER_SPECIALIZATION,
  FUNCTION_TEMPLATE_SPECIALIZATION,
  DEPENDENT_FUNCTION_TEMPLATE_SPECIALIZATION,
  NUM_ENUMERATORS
};

FunctionDeclTemplatedKind FromPasta(pasta::FunctionDeclTemplatedKind pasta_val);

inline static const char *EnumerationName(FunctionDeclTemplatedKind) {
  return "FunctionDeclTemplatedKind";
}

const char *EnumeratorName(FunctionDeclTemplatedKind);

enum class ImplicitCastExprOnStack : unsigned short {
  ON_STACK,
  NUM_ENUMERATORS
};

ImplicitCastExprOnStack FromPasta(pasta::ImplicitCastExprOnStack pasta_val);

inline static const char *EnumerationName(ImplicitCastExprOnStack) {
  return "ImplicitCastExprOnStack";
}

const char *EnumeratorName(ImplicitCastExprOnStack);

enum class ImplicitParamDeclImplicitParamKind : unsigned short {
  OBJ_C_SELF,
  OBJ_C_CMD,
  CXX_THIS,
  CXXVTT,
  CAPTURED_CONTEXT,
  OTHER,
  NUM_ENUMERATORS
};

ImplicitParamDeclImplicitParamKind FromPasta(pasta::ImplicitParamDeclImplicitParamKind pasta_val);

inline static const char *EnumerationName(ImplicitParamDeclImplicitParamKind) {
  return "ImplicitParamDeclImplicitParamKind";
}

const char *EnumeratorName(ImplicitParamDeclImplicitParamKind);

enum class LinkageSpecDeclLanguageIDs : unsigned short {
  C,
  CXX,
  NUM_ENUMERATORS
};

LinkageSpecDeclLanguageIDs FromPasta(pasta::LinkageSpecDeclLanguageIDs pasta_val);

inline static const char *EnumerationName(LinkageSpecDeclLanguageIDs) {
  return "LinkageSpecDeclLanguageIDs";
}

const char *EnumeratorName(LinkageSpecDeclLanguageIDs);

enum class NamedDeclExplicitVisibilityKind : unsigned short {
  VISIBILITY_FOR_TYPE,
  VISIBILITY_FOR_VALUE,
  NUM_ENUMERATORS
};

NamedDeclExplicitVisibilityKind FromPasta(pasta::NamedDeclExplicitVisibilityKind pasta_val);

inline static const char *EnumerationName(NamedDeclExplicitVisibilityKind) {
  return "NamedDeclExplicitVisibilityKind";
}

const char *EnumeratorName(NamedDeclExplicitVisibilityKind);

enum class OMPDeclareReductionDeclInitKind : unsigned short {
  CALL_INITIALIZER,
  DIRECT_INITIALIZER,
  COPY_INITIALIZER,
  NUM_ENUMERATORS
};

OMPDeclareReductionDeclInitKind FromPasta(pasta::OMPDeclareReductionDeclInitKind pasta_val);

inline static const char *EnumerationName(OMPDeclareReductionDeclInitKind) {
  return "OMPDeclareReductionDeclInitKind";
}

const char *EnumeratorName(OMPDeclareReductionDeclInitKind);

enum class ObjCIvarDeclAccessControl : unsigned short {
  NONE,
  PRIVATE,
  PROTECTED,
  PUBLIC,
  PACKAGE,
  NUM_ENUMERATORS
};

ObjCIvarDeclAccessControl FromPasta(pasta::ObjCIvarDeclAccessControl pasta_val);

inline static const char *EnumerationName(ObjCIvarDeclAccessControl) {
  return "ObjCIvarDeclAccessControl";
}

const char *EnumeratorName(ObjCIvarDeclAccessControl);

enum class ObjCMessageExprReceiverKind : unsigned short {
  CLASS,
  INSTANCE,
  SUPER_CLASS,
  SUPER_INSTANCE,
  NUM_ENUMERATORS
};

ObjCMessageExprReceiverKind FromPasta(pasta::ObjCMessageExprReceiverKind pasta_val);

inline static const char *EnumerationName(ObjCMessageExprReceiverKind) {
  return "ObjCMessageExprReceiverKind";
}

const char *EnumeratorName(ObjCMessageExprReceiverKind);

enum class ObjCMethodDeclImplementationControl : unsigned short {
  NONE,
  REQUIRED,
  OPTIONAL,
  NUM_ENUMERATORS
};

ObjCMethodDeclImplementationControl FromPasta(pasta::ObjCMethodDeclImplementationControl pasta_val);

inline static const char *EnumerationName(ObjCMethodDeclImplementationControl) {
  return "ObjCMethodDeclImplementationControl";
}

const char *EnumeratorName(ObjCMethodDeclImplementationControl);

enum class ObjCPropertyDeclPropertyControl : unsigned short {
  NONE,
  REQUIRED,
  OPTIONAL,
  NUM_ENUMERATORS
};

ObjCPropertyDeclPropertyControl FromPasta(pasta::ObjCPropertyDeclPropertyControl pasta_val);

inline static const char *EnumerationName(ObjCPropertyDeclPropertyControl) {
  return "ObjCPropertyDeclPropertyControl";
}

const char *EnumeratorName(ObjCPropertyDeclPropertyControl);

enum class ObjCPropertyDeclSetterKind : unsigned short {
  ASSIGN,
  RETAIN,
  COPY,
  WEAK,
  NUM_ENUMERATORS
};

ObjCPropertyDeclSetterKind FromPasta(pasta::ObjCPropertyDeclSetterKind pasta_val);

inline static const char *EnumerationName(ObjCPropertyDeclSetterKind) {
  return "ObjCPropertyDeclSetterKind";
}

const char *EnumeratorName(ObjCPropertyDeclSetterKind);

enum class ObjCPropertyImplDeclKind : unsigned short {
  SYNTHESIZE,
  DYNAMIC,
  NUM_ENUMERATORS
};

ObjCPropertyImplDeclKind FromPasta(pasta::ObjCPropertyImplDeclKind pasta_val);

inline static const char *EnumerationName(ObjCPropertyImplDeclKind) {
  return "ObjCPropertyImplDeclKind";
}

const char *EnumeratorName(ObjCPropertyImplDeclKind);

enum class PredefinedExprIdentKind : unsigned short {
  FUNC,
  FUNCTION,
  L_FUNCTION,
  FUNC_D_NAME,
  FUNC_SIG,
  L_FUNC_SIG,
  PRETTY_FUNCTION,
  PRETTY_FUNCTION_NO_VIRTUAL,
  NUM_ENUMERATORS
};

PredefinedExprIdentKind FromPasta(pasta::PredefinedExprIdentKind pasta_val);

inline static const char *EnumerationName(PredefinedExprIdentKind) {
  return "PredefinedExprIdentKind";
}

const char *EnumeratorName(PredefinedExprIdentKind);

enum class QualTypeDestructionKind : unsigned short {
  NONE,
  CXX_DESTRUCTOR,
  OBJC_STRONG_LIFETIME,
  OBJC_WEAK_LIFETIME,
  NONTRIVIAL_C_STRUCT,
  NUM_ENUMERATORS
};

QualTypeDestructionKind FromPasta(pasta::QualTypeDestructionKind pasta_val);

inline static const char *EnumerationName(QualTypeDestructionKind) {
  return "QualTypeDestructionKind";
}

const char *EnumeratorName(QualTypeDestructionKind);

enum class QualTypePrimitiveCopyKind : unsigned short {
  TRIVIAL,
  VOLATILE_TRIVIAL,
  ARC_STRONG,
  ARC_WEAK,
  STRUCT,
  NUM_ENUMERATORS
};

QualTypePrimitiveCopyKind FromPasta(pasta::QualTypePrimitiveCopyKind pasta_val);

inline static const char *EnumerationName(QualTypePrimitiveCopyKind) {
  return "QualTypePrimitiveCopyKind";
}

const char *EnumeratorName(QualTypePrimitiveCopyKind);

enum class QualTypePrimitiveDefaultInitializeKind : unsigned short {
  TRIVIAL,
  ARC_STRONG,
  ARC_WEAK,
  STRUCT,
  NUM_ENUMERATORS
};

QualTypePrimitiveDefaultInitializeKind FromPasta(pasta::QualTypePrimitiveDefaultInitializeKind pasta_val);

inline static const char *EnumerationName(QualTypePrimitiveDefaultInitializeKind) {
  return "QualTypePrimitiveDefaultInitializeKind";
}

const char *EnumeratorName(QualTypePrimitiveDefaultInitializeKind);

enum class RecordDeclArgPassingKind : unsigned short {
  CAN_PASS_IN_REGS,
  CANNOT_PASS_IN_REGS,
  CAN_NEVER_PASS_IN_REGS,
  NUM_ENUMERATORS
};

RecordDeclArgPassingKind FromPasta(pasta::RecordDeclArgPassingKind pasta_val);

inline static const char *EnumerationName(RecordDeclArgPassingKind) {
  return "RecordDeclArgPassingKind";
}

const char *EnumeratorName(RecordDeclArgPassingKind);

enum class SourceLocExprIdentKind : unsigned short {
  FUNCTION,
  FILE,
  LINE,
  COLUMN,
  NUM_ENUMERATORS
};

SourceLocExprIdentKind FromPasta(pasta::SourceLocExprIdentKind pasta_val);

inline static const char *EnumerationName(SourceLocExprIdentKind) {
  return "SourceLocExprIdentKind";
}

const char *EnumeratorName(SourceLocExprIdentKind);

enum class StmtLikelihood : unsigned short {
  UNLIKELY,
  NONE,
  LIKELY,
  NUM_ENUMERATORS
};

StmtLikelihood FromPasta(pasta::StmtLikelihood pasta_val);

inline static const char *EnumerationName(StmtLikelihood) {
  return "StmtLikelihood";
}

const char *EnumeratorName(StmtLikelihood);

enum class StmtKind : unsigned short {
  GCC_ASM_STMT,
  MS_ASM_STMT,
  BREAK_STMT,
  CXX_CATCH_STMT,
  CXX_FOR_RANGE_STMT,
  CXX_TRY_STMT,
  CAPTURED_STMT,
  COMPOUND_STMT,
  CONTINUE_STMT,
  CORETURN_STMT,
  COROUTINE_BODY_STMT,
  DECL_STMT,
  DO_STMT,
  FOR_STMT,
  GOTO_STMT,
  IF_STMT,
  INDIRECT_GOTO_STMT,
  MS_DEPENDENT_EXISTS_STMT,
  NULL_STMT,
  OMP_CANONICAL_LOOP,
  OMP_ATOMIC_DIRECTIVE,
  OMP_BARRIER_DIRECTIVE,
  OMP_CANCEL_DIRECTIVE,
  OMP_CANCELLATION_POINT_DIRECTIVE,
  OMP_CRITICAL_DIRECTIVE,
  OMP_DEPOBJ_DIRECTIVE,
  OMP_DISPATCH_DIRECTIVE,
  OMP_FLUSH_DIRECTIVE,
  OMP_INTEROP_DIRECTIVE,
  OMP_DISTRIBUTE_DIRECTIVE,
  OMP_DISTRIBUTE_PARALLEL_FOR_DIRECTIVE,
  OMP_DISTRIBUTE_PARALLEL_FOR_SIMD_DIRECTIVE,
  OMP_DISTRIBUTE_SIMD_DIRECTIVE,
  OMP_FOR_DIRECTIVE,
  OMP_FOR_SIMD_DIRECTIVE,
  OMP_MASTER_TASK_LOOP_DIRECTIVE,
  OMP_MASTER_TASK_LOOP_SIMD_DIRECTIVE,
  OMP_PARALLEL_FOR_DIRECTIVE,
  OMP_PARALLEL_FOR_SIMD_DIRECTIVE,
  OMP_PARALLEL_MASTER_TASK_LOOP_DIRECTIVE,
  OMP_PARALLEL_MASTER_TASK_LOOP_SIMD_DIRECTIVE,
  OMP_SIMD_DIRECTIVE,
  OMP_TARGET_PARALLEL_FOR_SIMD_DIRECTIVE,
  OMP_TARGET_SIMD_DIRECTIVE,
  OMP_TARGET_TEAMS_DISTRIBUTE_DIRECTIVE,
  OMP_TARGET_TEAMS_DISTRIBUTE_PARALLEL_FOR_DIRECTIVE,
  OMP_TARGET_TEAMS_DISTRIBUTE_PARALLEL_FOR_SIMD_DIRECTIVE,
  OMP_TARGET_TEAMS_DISTRIBUTE_SIMD_DIRECTIVE,
  OMP_TASK_LOOP_DIRECTIVE,
  OMP_TASK_LOOP_SIMD_DIRECTIVE,
  OMP_TEAMS_DISTRIBUTE_DIRECTIVE,
  OMP_TEAMS_DISTRIBUTE_PARALLEL_FOR_DIRECTIVE,
  OMP_TEAMS_DISTRIBUTE_PARALLEL_FOR_SIMD_DIRECTIVE,
  OMP_TEAMS_DISTRIBUTE_SIMD_DIRECTIVE,
  OMP_TILE_DIRECTIVE,
  OMP_UNROLL_DIRECTIVE,
  OMP_MASKED_DIRECTIVE,
  OMP_MASTER_DIRECTIVE,
  OMP_ORDERED_DIRECTIVE,
  OMP_PARALLEL_DIRECTIVE,
  OMP_PARALLEL_MASTER_DIRECTIVE,
  OMP_PARALLEL_SECTIONS_DIRECTIVE,
  OMP_SCAN_DIRECTIVE,
  OMP_SECTION_DIRECTIVE,
  OMP_SECTIONS_DIRECTIVE,
  OMP_SINGLE_DIRECTIVE,
  OMP_TARGET_DATA_DIRECTIVE,
  OMP_TARGET_DIRECTIVE,
  OMP_TARGET_ENTER_DATA_DIRECTIVE,
  OMP_TARGET_EXIT_DATA_DIRECTIVE,
  OMP_TARGET_PARALLEL_DIRECTIVE,
  OMP_TARGET_PARALLEL_FOR_DIRECTIVE,
  OMP_TARGET_TEAMS_DIRECTIVE,
  OMP_TARGET_UPDATE_DIRECTIVE,
  OMP_TASK_DIRECTIVE,
  OMP_TASKGROUP_DIRECTIVE,
  OMP_TASKWAIT_DIRECTIVE,
  OMP_TASKYIELD_DIRECTIVE,
  OMP_TEAMS_DIRECTIVE,
  OBJ_C_AT_CATCH_STMT,
  OBJ_C_AT_FINALLY_STMT,
  OBJ_C_AT_SYNCHRONIZED_STMT,
  OBJ_C_AT_THROW_STMT,
  OBJ_C_AT_TRY_STMT,
  OBJ_C_AUTORELEASE_POOL_STMT,
  OBJ_C_FOR_COLLECTION_STMT,
  RETURN_STMT,
  SEH_EXCEPT_STMT,
  SEH_FINALLY_STMT,
  SEH_LEAVE_STMT,
  SEH_TRY_STMT,
  CASE_STMT,
  DEFAULT_STMT,
  SWITCH_STMT,
  ATTRIBUTED_STMT,
  BINARY_CONDITIONAL_OPERATOR,
  CONDITIONAL_OPERATOR,
  ADDR_LABEL_EXPR,
  ARRAY_INIT_INDEX_EXPR,
  ARRAY_INIT_LOOP_EXPR,
  ARRAY_SUBSCRIPT_EXPR,
  ARRAY_TYPE_TRAIT_EXPR,
  AS_TYPE_EXPR,
  ATOMIC_EXPR,
  BINARY_OPERATOR,
  COMPOUND_ASSIGN_OPERATOR,
  BLOCK_EXPR,
  CXX_BIND_TEMPORARY_EXPR,
  CXX_BOOL_LITERAL_EXPR,
  CXX_CONSTRUCT_EXPR,
  CXX_TEMPORARY_OBJECT_EXPR,
  CXX_DEFAULT_ARG_EXPR,
  CXX_DEFAULT_INIT_EXPR,
  CXX_DELETE_EXPR,
  CXX_DEPENDENT_SCOPE_MEMBER_EXPR,
  CXX_FOLD_EXPR,
  CXX_INHERITED_CTOR_INIT_EXPR,
  CXX_NEW_EXPR,
  CXX_NOEXCEPT_EXPR,
  CXX_NULL_PTR_LITERAL_EXPR,
  CXX_PSEUDO_DESTRUCTOR_EXPR,
  CXX_REWRITTEN_BINARY_OPERATOR,
  CXX_SCALAR_VALUE_INIT_EXPR,
  CXX_STD_INITIALIZER_LIST_EXPR,
  CXX_THIS_EXPR,
  CXX_THROW_EXPR,
  CXX_TYPEID_EXPR,
  CXX_UNRESOLVED_CONSTRUCT_EXPR,
  CXX_UUIDOF_EXPR,
  CALL_EXPR,
  CUDA_KERNEL_CALL_EXPR,
  CXX_MEMBER_CALL_EXPR,
  CXX_OPERATOR_CALL_EXPR,
  USER_DEFINED_LITERAL,
  BUILTIN_BIT_CAST_EXPR,
  C_STYLE_CAST_EXPR,
  CXX_FUNCTIONAL_CAST_EXPR,
  CXX_ADDRSPACE_CAST_EXPR,
  CXX_CONST_CAST_EXPR,
  CXX_DYNAMIC_CAST_EXPR,
  CXX_REINTERPRET_CAST_EXPR,
  CXX_STATIC_CAST_EXPR,
  OBJ_C_BRIDGED_CAST_EXPR,
  IMPLICIT_CAST_EXPR,
  CHARACTER_LITERAL,
  CHOOSE_EXPR,
  COMPOUND_LITERAL_EXPR,
  CONCEPT_SPECIALIZATION_EXPR,
  CONVERT_VECTOR_EXPR,
  COAWAIT_EXPR,
  COYIELD_EXPR,
  DECL_REF_EXPR,
  DEPENDENT_COAWAIT_EXPR,
  DEPENDENT_SCOPE_DECL_REF_EXPR,
  DESIGNATED_INIT_EXPR,
  DESIGNATED_INIT_UPDATE_EXPR,
  EXPRESSION_TRAIT_EXPR,
  EXT_VECTOR_ELEMENT_EXPR,
  FIXED_POINT_LITERAL,
  FLOATING_LITERAL,
  CONSTANT_EXPR,
  EXPR_WITH_CLEANUPS,
  FUNCTION_PARM_PACK_EXPR,
  GNU_NULL_EXPR,
  GENERIC_SELECTION_EXPR,
  IMAGINARY_LITERAL,
  IMPLICIT_VALUE_INIT_EXPR,
  INIT_LIST_EXPR,
  INTEGER_LITERAL,
  LAMBDA_EXPR,
  MS_PROPERTY_REF_EXPR,
  MS_PROPERTY_SUBSCRIPT_EXPR,
  MATERIALIZE_TEMPORARY_EXPR,
  MATRIX_SUBSCRIPT_EXPR,
  MEMBER_EXPR,
  NO_INIT_EXPR,
  OMP_ARRAY_SECTION_EXPR,
  OMP_ARRAY_SHAPING_EXPR,
  OMP_ITERATOR_EXPR,
  OBJ_C_ARRAY_LITERAL,
  OBJ_C_AVAILABILITY_CHECK_EXPR,
  OBJ_C_BOOL_LITERAL_EXPR,
  OBJ_C_BOXED_EXPR,
  OBJ_C_DICTIONARY_LITERAL,
  OBJ_C_ENCODE_EXPR,
  OBJ_C_INDIRECT_COPY_RESTORE_EXPR,
  OBJ_C_ISA_EXPR,
  OBJ_C_IVAR_REF_EXPR,
  OBJ_C_MESSAGE_EXPR,
  OBJ_C_PROPERTY_REF_EXPR,
  OBJ_C_PROTOCOL_EXPR,
  OBJ_C_SELECTOR_EXPR,
  OBJ_C_STRING_LITERAL,
  OBJ_C_SUBSCRIPT_REF_EXPR,
  OFFSET_OF_EXPR,
  OPAQUE_VALUE_EXPR,
  UNRESOLVED_LOOKUP_EXPR,
  UNRESOLVED_MEMBER_EXPR,
  PACK_EXPANSION_EXPR,
  PAREN_EXPR,
  PAREN_LIST_EXPR,
  PREDEFINED_EXPR,
  PSEUDO_OBJECT_EXPR,
  RECOVERY_EXPR,
  REQUIRES_EXPR,
  SYCL_UNIQUE_STABLE_NAME_EXPR,
  SHUFFLE_VECTOR_EXPR,
  SIZE_OF_PACK_EXPR,
  SOURCE_LOC_EXPR,
  STMT_EXPR,
  STRING_LITERAL,
  SUBST_NON_TYPE_TEMPLATE_PARM_EXPR,
  SUBST_NON_TYPE_TEMPLATE_PARM_PACK_EXPR,
  TYPE_TRAIT_EXPR,
  TYPO_EXPR,
  UNARY_EXPR_OR_TYPE_TRAIT_EXPR,
  UNARY_OPERATOR,
  VA_ARG_EXPR,
  LABEL_STMT,
  WHILE_STMT,
  NUM_ENUMERATORS
};

StmtKind FromPasta(pasta::StmtKind pasta_val);

inline static const char *EnumerationName(StmtKind) {
  return "StmtKind";
}

const char *EnumeratorName(StmtKind);

enum class StringLiteralStringKind : unsigned short {
  ASCII,
  WIDE,
  UTF8,
  UTF16,
  UTF32,
  NUM_ENUMERATORS
};

StringLiteralStringKind FromPasta(pasta::StringLiteralStringKind pasta_val);

inline static const char *EnumerationName(StringLiteralStringKind) {
  return "StringLiteralStringKind";
}

const char *EnumeratorName(StringLiteralStringKind);

enum class TemplateArgumentKind : unsigned short {
  EMPTY,
  TYPE,
  DECLARATION,
  NULL_POINTER,
  INTEGRAL,
  TEMPLATE,
  TEMPLATE_EXPANSION,
  EXPRESSION,
  PACK,
  NUM_ENUMERATORS
};

TemplateArgumentKind FromPasta(pasta::TemplateArgumentKind pasta_val);

inline static const char *EnumerationName(TemplateArgumentKind) {
  return "TemplateArgumentKind";
}

const char *EnumeratorName(TemplateArgumentKind);

enum class TypeScalarTypeKind : unsigned short {
  C_POINTER,
  BLOCK_POINTER,
  OBJ_C_OBJECT_POINTER,
  MEMBER_POINTER,
  BOOLEAN,
  INTEGRAL,
  FLOATING,
  INTEGRAL_COMPLEX,
  FLOATING_COMPLEX,
  FIXED_POINT,
  NUM_ENUMERATORS
};

TypeScalarTypeKind FromPasta(pasta::TypeScalarTypeKind pasta_val);

inline static const char *EnumerationName(TypeScalarTypeKind) {
  return "TypeScalarTypeKind";
}

const char *EnumeratorName(TypeScalarTypeKind);

enum class TypeKind : unsigned short {
  ADJUSTED,
  DECAYED,
  CONSTANT_ARRAY,
  DEPENDENT_SIZED_ARRAY,
  INCOMPLETE_ARRAY,
  VARIABLE_ARRAY,
  ATOMIC,
  ATTRIBUTED,
  BLOCK_POINTER,
  BUILTIN,
  COMPLEX,
  DECLTYPE,
  AUTO,
  DEDUCED_TEMPLATE_SPECIALIZATION,
  DEPENDENT_ADDRESS_SPACE,
  DEPENDENT_EXT_INT,
  DEPENDENT_NAME,
  DEPENDENT_SIZED_EXT_VECTOR,
  DEPENDENT_TEMPLATE_SPECIALIZATION,
  DEPENDENT_VECTOR,
  ELABORATED,
  EXT_INT,
  FUNCTION_NO_PROTO,
  FUNCTION_PROTO,
  INJECTED_CLASS_NAME,
  MACRO_QUALIFIED,
  CONSTANT_MATRIX,
  DEPENDENT_SIZED_MATRIX,
  MEMBER_POINTER,
  OBJ_C_OBJECT_POINTER,
  OBJ_C_OBJECT,
  OBJ_C_INTERFACE,
  OBJ_C_TYPE_PARAM,
  PACK_EXPANSION,
  PAREN,
  PIPE,
  POINTER,
  L_VALUE_REFERENCE,
  R_VALUE_REFERENCE,
  SUBST_TEMPLATE_TYPE_PARM_PACK,
  SUBST_TEMPLATE_TYPE_PARM,
  ENUM,
  RECORD,
  TEMPLATE_SPECIALIZATION,
  TEMPLATE_TYPE_PARM,
  TYPE_OF_EXPR,
  TYPE_OF,
  TYPEDEF,
  UNARY_TRANSFORM,
  UNRESOLVED_USING,
  VECTOR,
  EXT_VECTOR,
  NUM_ENUMERATORS
};

TypeKind FromPasta(pasta::TypeKind pasta_val);

inline static const char *EnumerationName(TypeKind) {
  return "TypeKind";
}

const char *EnumeratorName(TypeKind);

enum class UnaryTransformTypeUTTKind : unsigned short {
  ENUM_UNDERLYING_TYPE,
  NUM_ENUMERATORS
};

UnaryTransformTypeUTTKind FromPasta(pasta::UnaryTransformTypeUTTKind pasta_val);

inline static const char *EnumerationName(UnaryTransformTypeUTTKind) {
  return "UnaryTransformTypeUTTKind";
}

const char *EnumeratorName(UnaryTransformTypeUTTKind);

enum class UserDefinedLiteralLiteralOperatorKind : unsigned short {
  RAW,
  TEMPLATE,
  INTEGER,
  FLOATING,
  STRING,
  CHARACTER,
  NUM_ENUMERATORS
};

UserDefinedLiteralLiteralOperatorKind FromPasta(pasta::UserDefinedLiteralLiteralOperatorKind pasta_val);

inline static const char *EnumerationName(UserDefinedLiteralLiteralOperatorKind) {
  return "UserDefinedLiteralLiteralOperatorKind";
}

const char *EnumeratorName(UserDefinedLiteralLiteralOperatorKind);

enum class VarDeclDefinitionKind : unsigned short {
  DECLARATION_ONLY,
  TENTATIVE_DEFINITION,
  DEFINITION,
  NUM_ENUMERATORS
};

VarDeclDefinitionKind FromPasta(pasta::VarDeclDefinitionKind pasta_val);

inline static const char *EnumerationName(VarDeclDefinitionKind) {
  return "VarDeclDefinitionKind";
}

const char *EnumeratorName(VarDeclDefinitionKind);

enum class VarDeclInitializationStyle : unsigned short {
  C_INIT,
  CALL_INITIALIZER,
  LIST_INITIALIZER,
  NUM_ENUMERATORS
};

VarDeclInitializationStyle FromPasta(pasta::VarDeclInitializationStyle pasta_val);

inline static const char *EnumerationName(VarDeclInitializationStyle) {
  return "VarDeclInitializationStyle";
}

const char *EnumeratorName(VarDeclInitializationStyle);

enum class VarDeclTLSKind : unsigned short {
  NONE,
  STATIC,
  DYNAMIC,
  NUM_ENUMERATORS
};

VarDeclTLSKind FromPasta(pasta::VarDeclTLSKind pasta_val);

inline static const char *EnumerationName(VarDeclTLSKind) {
  return "VarDeclTLSKind";
}

const char *EnumeratorName(VarDeclTLSKind);

enum class VectorTypeVectorKind : unsigned short {
  GENERIC_VECTOR,
  ALTI_VEC_VECTOR,
  ALTI_VEC_PIXEL,
  ALTI_VEC_BOOLEAN,
  NEON_VECTOR,
  NEON_POLY_VECTOR,
  SVE_FIXED_LENGTH_DATA_VECTOR,
  SVE_FIXED_LENGTH_PREDICATE_VECTOR,
  NUM_ENUMERATORS
};

VectorTypeVectorKind FromPasta(pasta::VectorTypeVectorKind pasta_val);

inline static const char *EnumerationName(VectorTypeVectorKind) {
  return "VectorTypeVectorKind";
}

const char *EnumeratorName(VectorTypeVectorKind);

enum class ASTDumpOutputFormat : unsigned short {
  DEFAULT,
  JSON,
  NUM_ENUMERATORS
};

ASTDumpOutputFormat FromPasta(pasta::ASTDumpOutputFormat pasta_val);

inline static const char *EnumerationName(ASTDumpOutputFormat) {
  return "ASTDumpOutputFormat";
}

const char *EnumeratorName(ASTDumpOutputFormat);

enum class AccessSpecifier : unsigned short {
  PUBLIC,
  PROTECTED,
  PRIVATE,
  NONE,
  NUM_ENUMERATORS
};

AccessSpecifier FromPasta(pasta::AccessSpecifier pasta_val);

inline static const char *EnumerationName(AccessSpecifier) {
  return "AccessSpecifier";
}

const char *EnumeratorName(AccessSpecifier);

enum class AddrSpaceMapMangling : unsigned short {
  TARGET,
  ON,
  OFF,
  NUM_ENUMERATORS
};

AddrSpaceMapMangling FromPasta(pasta::AddrSpaceMapMangling pasta_val);

inline static const char *EnumerationName(AddrSpaceMapMangling) {
  return "AddrSpaceMapMangling";
}

const char *EnumeratorName(AddrSpaceMapMangling);

enum class AllocatorTypeTy : unsigned short {
  OMP_NULL_MEMORY_ALLOC,
  OMP_DEFAULT_MEMORY_ALLOC,
  OMP_LARGE_CAP_MEMORY_ALLOC,
  OMP_CONST_MEMORY_ALLOC,
  OMP_HIGH_BW_MEMORY_ALLOC,
  OMP_LOW_LAT_MEMORY_ALLOC,
  OMPC_GROUP_MEMORY_ALLOC,
  OMPP_TEAM_MEMORY_ALLOC,
  OMP_THREAD_MEMORY_ALLOC,
  OMP_USER_DEFINED_MEMORY_ALLOC,
  NUM_ENUMERATORS
};

AllocatorTypeTy FromPasta(pasta::AllocatorTypeTy pasta_val);

inline static const char *EnumerationName(AllocatorTypeTy) {
  return "AllocatorTypeTy";
}

const char *EnumeratorName(AllocatorTypeTy);

enum class AltivecSrcCompatKind : unsigned short {
  MIXED,
  GCC,
  XL,
  // Skipped repeat pasta::kDefault
  NUM_ENUMERATORS
};

AltivecSrcCompatKind FromPasta(pasta::AltivecSrcCompatKind pasta_val);

inline static const char *EnumerationName(AltivecSrcCompatKind) {
  return "AltivecSrcCompatKind";
}

const char *EnumeratorName(AltivecSrcCompatKind);

enum class ArgumentKind : unsigned short {
  STD_STRING,
  C_STRING,
  SINT,
  UINT,
  TOKENKIND,
  IDENTIFIERINFO,
  ADDRSPACE,
  QUALIFIED,
  QUALTYPE,
  DECLARATIONNAME,
  NAMEDDECL,
  NESTEDNAMESPEC,
  DECLCONTEXT,
  QUALTYPE_PAIR,
  ATTRIBUTE,
  NUM_ENUMERATORS
};

ArgumentKind FromPasta(pasta::ArgumentKind pasta_val);

inline static const char *EnumerationName(ArgumentKind) {
  return "ArgumentKind";
}

const char *EnumeratorName(ArgumentKind);

enum class ArrayTypeTrait : unsigned short {
  ARRAY_RANK,
  ARRAY_EXTENT,
  NUM_ENUMERATORS
};

ArrayTypeTrait FromPasta(pasta::ArrayTypeTrait pasta_val);

inline static const char *EnumerationName(ArrayTypeTrait) {
  return "ArrayTypeTrait";
}

const char *EnumeratorName(ArrayTypeTrait);

enum class AtomicScopeModelKind : unsigned short {
  NONE,
  OPEN_CL,
  NUM_ENUMERATORS
};

AtomicScopeModelKind FromPasta(pasta::AtomicScopeModelKind pasta_val);

inline static const char *EnumerationName(AtomicScopeModelKind) {
  return "AtomicScopeModelKind";
}

const char *EnumeratorName(AtomicScopeModelKind);

enum class AttributeKind : unsigned short {
  ADDRESS_SPACE,
  ARM_MVE_STRICT_POLYMORPHISM,
  CMSE_NS_CALL,
  NO_DEREF,
  OBJ_CGC,
  OBJ_C_INERT_UNSAFE_UNRETAINED,
  OBJ_C_KIND_OF,
  OPEN_CL_CONSTANT_ADDRESS_SPACE,
  OPEN_CL_GENERIC_ADDRESS_SPACE,
  OPEN_CL_GLOBAL_ADDRESS_SPACE,
  OPEN_CL_GLOBAL_DEVICE_ADDRESS_SPACE,
  OPEN_CL_GLOBAL_HOST_ADDRESS_SPACE,
  OPEN_CL_LOCAL_ADDRESS_SPACE,
  OPEN_CL_PRIVATE_ADDRESS_SPACE,
  PTR32,
  PTR64,
  S_PTR,
  TYPE_NON_NULL,
  TYPE_NULL_UNSPECIFIED,
  TYPE_NULLABLE,
  TYPE_NULLABLE_RESULT,
  U_PTR,
  FALL_THROUGH,
  LIKELY,
  MUST_TAIL,
  OPEN_CL_UNROLL_HINT,
  SUPPRESS,
  UNLIKELY,
  NO_MERGE,
  A_ARCH64_VECTOR_PCS,
  ACQUIRE_HANDLE,
  ANY_X86_NO_CF_CHECK,
  C_DECL,
  FAST_CALL,
  INTEL_OCL_BICC,
  LIFETIME_BOUND,
  MSABI,
  NS_RETURNS_RETAINED,
  OBJ_C_OWNERSHIP,
  PASCAL,
  PCS,
  PRESERVE_ALL,
  PRESERVE_MOST,
  REG_CALL,
  STD_CALL,
  SWIFT_ASYNC_CALL,
  SWIFT_CALL,
  SYS_VABI,
  THIS_CALL,
  VECTOR_CALL,
  SWIFT_ASYNC_CONTEXT,
  SWIFT_CONTEXT,
  SWIFT_ERROR_RESULT,
  SWIFT_INDIRECT_RESULT,
  ANNOTATE,
  CF_CONSUMED,
  CARRIES_DEPENDENCY,
  NS_CONSUMED,
  NON_NULL,
  OS_CONSUMED,
  PASS_OBJECT_SIZE,
  RELEASE_HANDLE,
  USE_HANDLE,
  AMDGPU_FLAT_WORK_GROUP_SIZE,
  AMDGPU_NUM_SGPR,
  AMDGPU_NUM_VGPR,
  AMDGPU_WAVES_PER_EU,
  ARM_INTERRUPT,
  AVR_INTERRUPT,
  AVR_SIGNAL,
  ACQUIRE_CAPABILITY,
  ACQUIRED_AFTER,
  ACQUIRED_BEFORE,
  ALIGN_MAC68_K,
  ALIGN_NATURAL,
  ALIGNED,
  ALLOC_ALIGN,
  ALLOC_SIZE,
  ALWAYS_DESTROY,
  ALWAYS_INLINE,
  ANALYZER_NO_RETURN,
  ANY_X86_INTERRUPT,
  ANY_X86_NO_CALLER_SAVED_REGISTERS,
  ARC_WEAKREF_UNAVAILABLE,
  ARGUMENT_WITH_TYPE_TAG,
  ARM_BUILTIN_ALIAS,
  ARTIFICIAL,
  ASSEMBLY_LABEL,
  ASSERT_CAPABILITY,
  ASSERT_EXCLUSIVE_LOCK,
  ASSERT_SHARED_LOCK,
  ASSUME_ALIGNED,
  ASSUMPTION,
  AVAILABILITY,
  BPF_PRESERVE_ACCESS_INDEX,
  BLOCKS,
  BUILTIN,
  C11_NO_RETURN,
  CF_AUDITED_TRANSFER,
  CF_GUARD,
  CFI_CANONICAL_JUMP_TABLE,
  CF_RETURNS_NOT_RETAINED,
  CF_RETURNS_RETAINED,
  CF_UNKNOWN_TRANSFER,
  CPU_DISPATCH,
  CPU_SPECIFIC,
  CUDA_CONSTANT,
  CUDA_DEVICE,
  CUDA_DEVICE_BUILTIN_SURFACE_TYPE,
  CUDA_DEVICE_BUILTIN_TEXTURE_TYPE,
  CUDA_GLOBAL,
  CUDA_HOST,
  CUDA_INVALID_TARGET,
  CUDA_LAUNCH_BOUNDS,
  CUDA_SHARED,
  CXX11_NO_RETURN,
  CALLABLE_WHEN,
  CALLBACK,
  CAPABILITY,
  CAPTURED_RECORD,
  CLEANUP,
  CMSE_NS_ENTRY,
  CODE_SEG,
  COLD,
  COMMON,
  CONST,
  CONST_INITIALIZER,
  CONSTRUCTOR,
  CONSUMABLE,
  CONSUMABLE_AUTO_CAST,
  CONSUMABLE_SET_ON_READ,
  CONVERGENT,
  DLL_EXPORT,
  DLL_EXPORT_STATIC_LOCAL,
  DLL_IMPORT,
  DLL_IMPORT_STATIC_LOCAL,
  DEPRECATED,
  DESTRUCTOR,
  DIAGNOSE_IF,
  DISABLE_TAIL_CALLS,
  EMPTY_BASES,
  ENABLE_IF,
  ENFORCE_TCB,
  ENFORCE_TCB_LEAF,
  ENUM_EXTENSIBILITY,
  EXCLUDE_FROM_EXPLICIT_INSTANTIATION,
  EXCLUSIVE_TRYLOCK_FUNCTION,
  EXTERNAL_SOURCE_SYMBOL,
  FINAL,
  FLAG_ENUM,
  FLATTEN,
  FORMAT,
  FORMAT_ARGUMENT,
  GNU_INLINE,
  GUARDED_BY,
  GUARDED_VARIABLE,
  HIP_MANAGED,
  HOT,
  IB_ACTION,
  IB_OUTLET,
  IB_OUTLET_COLLECTION,
  INITIALIZER_PRIORITY,
  INTERNAL_LINKAGE,
  LTO_VISIBILITY_PUBLIC,
  LAYOUT_VERSION,
  LEAF,
  LOCK_RETURNED,
  LOCKS_EXCLUDED,
  M68_KINTERRUPT,
  MIG_SERVER_ROUTINE,
  MS_ALLOCATOR,
  MS_INHERITANCE,
  MS_NO_V_TABLE,
  MSP430_INTERRUPT,
  MS_STRUCT,
  MS_VTOR_DISP,
  MAX_FIELD_ALIGNMENT,
  MAY_ALIAS,
  MICRO_MIPS,
  MIN_SIZE,
  MIN_VECTOR_WIDTH,
  MIPS16,
  MIPS_INTERRUPT,
  MIPS_LONG_CALL,
  MIPS_SHORT_CALL,
  NS_CONSUMES_SELF,
  NS_ERROR_DOMAIN,
  NS_RETURNS_AUTORELEASED,
  NS_RETURNS_NOT_RETAINED,
  NAKED,
  NO_ALIAS,
  NO_COMMON,
  NO_DEBUG,
  NO_DESTROY,
  NO_DUPLICATE,
  NO_INLINE,
  NO_INSTRUMENT_FUNCTION,
  NO_MICRO_MIPS,
  NO_MIPS16,
  NO_PROFILE_FUNCTION,
  NO_RETURN,
  NO_SANITIZE,
  NO_SPECULATIVE_LOAD_HARDENING,
  NO_SPLIT_STACK,
  NO_STACK_PROTECTOR,
  NO_THREAD_SAFETY_ANALYSIS,
  NO_THROW,
  NO_UNIQUE_ADDRESS,
  NOT_TAIL_CALLED,
  OMP_ALLOCATE_DECLARATION,
  OMP_CAPTURE_NO_INITIALIZER,
  OMP_DECLARE_TARGET_DECLARATION,
  OMP_DECLARE_VARIANT,
  OMP_THREAD_PRIVATE_DECLARATION,
  OS_CONSUMES_THIS,
  OS_RETURNS_NOT_RETAINED,
  OS_RETURNS_RETAINED,
  OS_RETURNS_RETAINED_ON_NON_ZERO,
  OS_RETURNS_RETAINED_ON_ZERO,
  OBJ_C_BRIDGE,
  OBJ_C_BRIDGE_MUTABLE,
  OBJ_C_BRIDGE_RELATED,
  OBJ_C_EXCEPTION,
  OBJ_C_EXPLICIT_PROTOCOL_IMPLEMENTATION,
  OBJ_C_EXTERNALLY_RETAINED,
  OBJ_C_INDEPENDENT_CLASS,
  OBJ_C_METHOD_FAMILY,
  OBJ_CNS_OBJECT,
  OBJ_C_PRECISE_LIFETIME,
  OBJ_C_REQUIRES_PROPERTY_DEFINITIONS,
  OBJ_C_REQUIRES_SUPER,
  OBJ_C_RETURNS_INNER_POINTER,
  OBJ_C_ROOT_CLASS,
  OBJ_C_SUBCLASSING_RESTRICTED,
  OPEN_CL_INTEL_REQD_SUB_GROUP_SIZE,
  OPEN_CL_KERNEL,
  OPTIMIZE_NONE,
  OVERRIDE,
  OWNER,
  OWNERSHIP,
  PACKED,
  PARAMETER_TYPESTATE,
  PATCHABLE_FUNCTION_ENTRY,
  POINTER,
  PRAGMA_CLANG_BSS_SECTION,
  PRAGMA_CLANG_DATA_SECTION,
  PRAGMA_CLANG_RELRO_SECTION,
  PRAGMA_CLANG_RODATA_SECTION,
  PRAGMA_CLANG_TEXT_SECTION,
  PREFERRED_NAME,
  PT_GUARDED_BY,
  PT_GUARDED_VARIABLE,
  PURE,
  RISCV_INTERRUPT,
  REINITIALIZES,
  RELEASE_CAPABILITY,
  REQD_WORK_GROUP_SIZE,
  REQUIRES_CAPABILITY,
  RESTRICT,
  RETAIN,
  RETURN_TYPESTATE,
  RETURNS_NON_NULL,
  RETURNS_TWICE,
  SYCL_KERNEL,
  SCOPED_LOCKABLE,
  SECTION,
  SELECT_ANY,
  SENTINEL,
  SET_TYPESTATE,
  SHARED_TRYLOCK_FUNCTION,
  SPECULATIVE_LOAD_HARDENING,
  STANDALONE_DEBUG,
  STRICT_FP,
  SWIFT_ASYNC,
  SWIFT_ASYNC_ERROR,
  SWIFT_ASYNC_NAME,
  SWIFT_ATTRIBUTE,
  SWIFT_BRIDGE,
  SWIFT_BRIDGED_TYPEDEF,
  SWIFT_ERROR,
  SWIFT_NAME,
  SWIFT_NEW_TYPE,
  SWIFT_PRIVATE,
  TLS_MODEL,
  TARGET,
  TEST_TYPESTATE,
  TRANSPARENT_UNION,
  TRIVIAL_ABI,
  TRY_ACQUIRE_CAPABILITY,
  TYPE_TAG_FOR_DATATYPE,
  TYPE_VISIBILITY,
  UNAVAILABLE,
  UNINITIALIZED,
  UNUSED,
  USED,
  USING_IF_EXISTS,
  UUID,
  VEC_RETURN,
  VEC_TYPE_HINT,
  VISIBILITY,
  WARN_UNUSED,
  WARN_UNUSED_RESULT,
  WEAK,
  WEAK_IMPORT,
  WEAK_REFERENCE,
  WEB_ASSEMBLY_EXPORT_NAME,
  WEB_ASSEMBLY_IMPORT_MODULE,
  WEB_ASSEMBLY_IMPORT_NAME,
  WORK_GROUP_SIZE_HINT,
  X86_FORCE_ALIGN_ARGUMENT_POINTER,
  X_RAY_INSTRUMENT,
  X_RAY_LOG_ARGUMENTS,
  ABI_TAG,
  ALIAS,
  ALIGN_VALUE,
  BUILTIN_ALIAS,
  CALLED_ONCE,
  I_FUNC,
  INITIALIZER_SEG,
  LOADER_UNINITIALIZED,
  LOOP_HINT,
  MODE,
  NO_BUILTIN,
  NO_ESCAPE,
  OMP_CAPTURE_KIND,
  OMP_DECLARE_SIMD_DECLARATION,
  OMP_REFERENCED_VARIABLE,
  OBJ_C_BOXABLE,
  OBJ_C_CLASS_STUB,
  OBJ_C_DESIGNATED_INITIALIZER,
  OBJ_C_DIRECT,
  OBJ_C_DIRECT_MEMBERS,
  OBJ_C_NON_LAZY_CLASS,
  OBJ_C_NON_RUNTIME_PROTOCOL,
  OBJ_C_RUNTIME_NAME,
  OBJ_C_RUNTIME_VISIBLE,
  OPEN_CL_ACCESS,
  OVERLOADABLE,
  RENDER_SCRIPT_KERNEL,
  SWIFT_OBJ_C_MEMBERS,
  THREAD,
  NUM_ENUMERATORS
};

AttributeKind FromPasta(pasta::AttributeKind pasta_val);

inline static const char *EnumerationName(AttributeKind) {
  return "AttributeKind";
}

const char *EnumeratorName(AttributeKind);

enum class AutoTypeKeyword : unsigned short {
  AUTO,
  DECLTYPE_AUTO,
  GNU_AUTO_TYPE,
  NUM_ENUMERATORS
};

AutoTypeKeyword FromPasta(pasta::AutoTypeKeyword pasta_val);

inline static const char *EnumerationName(AutoTypeKeyword) {
  return "AutoTypeKeyword";
}

const char *EnumeratorName(AutoTypeKeyword);

enum class AvailabilityResult : unsigned short {
  AVAILABLE,
  NOT_YET_INTRODUCED,
  DEPRECATED,
  UNAVAILABLE,
  NUM_ENUMERATORS
};

AvailabilityResult FromPasta(pasta::AvailabilityResult pasta_val);

inline static const char *EnumerationName(AvailabilityResult) {
  return "AvailabilityResult";
}

const char *EnumeratorName(AvailabilityResult);

enum class BinaryOperatorKind : unsigned short {
  POINTER_MEMORY_D,
  POINTER_MEMORY_I,
  MUL,
  DIV,
  REM,
  ADD,
  SUB,
  SHL,
  SHR,
  CMP,
  LT,
  GT,
  LE,
  GE,
  EQ,
  NE,
  AND,
  XOR,
  OR,
  L_AND,
  L_OR,
  ASSIGN,
  MUL_ASSIGN,
  DIV_ASSIGN,
  REM_ASSIGN,
  ADD_ASSIGN,
  SUB_ASSIGN,
  SHL_ASSIGN,
  SHR_ASSIGN,
  AND_ASSIGN,
  XOR_ASSIGN,
  OR_ASSIGN,
  COMMA,
  NUM_ENUMERATORS
};

BinaryOperatorKind FromPasta(pasta::BinaryOperatorKind pasta_val);

inline static const char *EnumerationName(BinaryOperatorKind) {
  return "BinaryOperatorKind";
}

const char *EnumeratorName(BinaryOperatorKind);

enum class Bits : unsigned short {
  NONE,
  UNEXPANDED_PACK,
  INSTANTIATION,
  TYPE,
  VALUE,
  DEPENDENT,
  ERROR,
  VARIABLY_MODIFIED,
  SYNTACTIC,
  NUM_ENUMERATORS
};

Bits FromPasta(pasta::Bits pasta_val);

inline static const char *EnumerationName(Bits) {
  return "Bits";
}

const char *EnumeratorName(Bits);

enum class BlockType : unsigned short {
  BY_REFERENCE,
  NUM_ENUMERATORS
};

BlockType FromPasta(pasta::BlockType pasta_val);

inline static const char *EnumerationName(BlockType) {
  return "BlockType";
}

const char *EnumeratorName(BlockType);

enum class BranchStateTy : unsigned short {
  UNDEFINED,
  INBRANCH,
  NOTINBRANCH,
  NUM_ENUMERATORS
};

BranchStateTy FromPasta(pasta::BranchStateTy pasta_val);

inline static const char *EnumerationName(BranchStateTy) {
  return "BranchStateTy";
}

const char *EnumeratorName(BranchStateTy);

enum class CallingConv : unsigned short {
  C,
  X86_STD_CALL,
  X86_FAST_CALL,
  X86_THIS_CALL,
  X86_VECTOR_CALL,
  X86_PASCAL,
  WIN64,
  X8664_SYS_V,
  X86_REG_CALL,
  AAPCS,
  AAPCSVFP,
  INTEL_OCL_BICC,
  SPIR_FUNCTION,
  OPEN_CL_KERNEL,
  SWIFT,
  SWIFT_ASYNC,
  PRESERVE_MOST,
  PRESERVE_ALL,
  A_ARCH64_VECTOR_CALL,
  NUM_ENUMERATORS
};

CallingConv FromPasta(pasta::CallingConv pasta_val);

inline static const char *EnumerationName(CallingConv) {
  return "CallingConv";
}

const char *EnumeratorName(CallingConv);

enum class CanThrowResult : unsigned short {
  CANNOT,
  DEPENDENT,
  CAN,
  NUM_ENUMERATORS
};

CanThrowResult FromPasta(pasta::CanThrowResult pasta_val);

inline static const char *EnumerationName(CanThrowResult) {
  return "CanThrowResult";
}

const char *EnumeratorName(CanThrowResult);

enum class CapturedRegionKind : unsigned short {
  DEFAULT,
  OBJ_C_AT_FINALLY,
  OPEN_MP,
  NUM_ENUMERATORS
};

CapturedRegionKind FromPasta(pasta::CapturedRegionKind pasta_val);

inline static const char *EnumerationName(CapturedRegionKind) {
  return "CapturedRegionKind";
}

const char *EnumeratorName(CapturedRegionKind);

enum class CastKind : unsigned short {
  DEPENDENT,
  BIT_CAST,
  L_VALUE_BIT_CAST,
  L_VALUE_TO_R_VALUE_BIT_CAST,
  L_VALUE_TO_R_VALUE,
  NO_OPERATION,
  BASE_TO_DERIVED,
  DERIVED_TO_BASE,
  UNCHECKED_DERIVED_TO_BASE,
  DYNAMIC,
  TO_UNION,
  ARRAY_TO_POINTER_DECAY,
  FUNCTION_TO_POINTER_DECAY,
  NULL_TO_POINTER,
  NULL_TO_MEMBER_POINTER,
  BASE_TO_DERIVED_MEMBER_POINTER,
  DERIVED_TO_BASE_MEMBER_POINTER,
  MEMBER_POINTER_TO_BOOLEAN,
  REINTERPRET_MEMBER_POINTER,
  USER_DEFINED_CONVERSION,
  CONSTRUCTOR_CONVERSION,
  INTEGRAL_TO_POINTER,
  POINTER_TO_INTEGRAL,
  POINTER_TO_BOOLEAN,
  TO_VOID,
  MATRIX_CAST,
  VECTOR_SPLAT,
  INTEGRAL_CAST,
  INTEGRAL_TO_BOOLEAN,
  INTEGRAL_TO_FLOATING,
  FLOATING_TO_FIXED_POINT,
  FIXED_POINT_TO_FLOATING,
  FIXED_POINT_CAST,
  FIXED_POINT_TO_INTEGRAL,
  INTEGRAL_TO_FIXED_POINT,
  FIXED_POINT_TO_BOOLEAN,
  FLOATING_TO_INTEGRAL,
  FLOATING_TO_BOOLEAN,
  BOOLEAN_TO_SIGNED_INTEGRAL,
  FLOATING_CAST,
  C_POINTER_TO_OBJ_C_POINTER_CAST,
  BLOCK_POINTER_TO_OBJ_C_POINTER_CAST,
  ANY_POINTER_TO_BLOCK_POINTER_CAST,
  OBJ_C_OBJECT_L_VALUE_CAST,
  FLOATING_REAL_TO_COMPLEX,
  FLOATING_COMPLEX_TO_REAL,
  FLOATING_COMPLEX_TO_BOOLEAN,
  FLOATING_COMPLEX_CAST,
  FLOATING_COMPLEX_TO_INTEGRAL_COMPLEX,
  INTEGRAL_REAL_TO_COMPLEX,
  INTEGRAL_COMPLEX_TO_REAL,
  INTEGRAL_COMPLEX_TO_BOOLEAN,
  INTEGRAL_COMPLEX_CAST,
  INTEGRAL_COMPLEX_TO_FLOATING_COMPLEX,
  ARC_PRODUCE_OBJECT,
  ARC_CONSUME_OBJECT,
  ARC_RECLAIM_RETURNED_OBJECT,
  ARC_EXTEND_BLOCK_OBJECT,
  ATOMIC_TO_NON_ATOMIC,
  NON_ATOMIC_TO_ATOMIC,
  COPY_AND_AUTORELEASE_BLOCK_OBJECT,
  BUILTIN_FN_TO_FN_POINTER,
  ZERO_TO_OCL_OPAQUE_TYPE,
  ADDRESS_SPACE_CONVERSION,
  INT_TO_OCL_SAMPLER,
  NUM_ENUMERATORS
};

CastKind FromPasta(pasta::CastKind pasta_val);

inline static const char *EnumerationName(CastKind) {
  return "CastKind";
}

const char *EnumeratorName(CastKind);

enum class ClangABI : unsigned short {
  VER38,
  VER4,
  VER6,
  VER7,
  VER9,
  VER11,
  VER12,
  LATEST,
  NUM_ENUMERATORS
};

ClangABI FromPasta(pasta::ClangABI pasta_val);

inline static const char *EnumerationName(ClangABI) {
  return "ClangABI";
}

const char *EnumeratorName(ClangABI);

enum class CommentKind : unsigned short {
  INVALID,
  ORDINARY_BCPL,
  ORDINARY_C,
  BCPL_SLASH,
  BCPL_EXCL,
  JAVA_DOC,
  QT,
  MERGED,
  NUM_ENUMERATORS
};

CommentKind FromPasta(pasta::CommentKind pasta_val);

inline static const char *EnumerationName(CommentKind) {
  return "CommentKind";
}

const char *EnumeratorName(CommentKind);

enum class ComparisonCategoryResult : unsigned short {
  EQUAL,
  EQUIVALENT,
  LESS,
  GREATER,
  UNORDERED,
  NUM_ENUMERATORS
};

ComparisonCategoryResult FromPasta(pasta::ComparisonCategoryResult pasta_val);

inline static const char *EnumerationName(ComparisonCategoryResult) {
  return "ComparisonCategoryResult";
}

const char *EnumeratorName(ComparisonCategoryResult);

enum class ComparisonCategoryType : unsigned short {
  PARTIAL_ORDERING,
  WEAK_ORDERING,
  STRONG_ORDERING,
  NUM_ENUMERATORS
};

ComparisonCategoryType FromPasta(pasta::ComparisonCategoryType pasta_val);

inline static const char *EnumerationName(ComparisonCategoryType) {
  return "ComparisonCategoryType";
}

const char *EnumeratorName(ComparisonCategoryType);

enum class CompilingModuleKind : unsigned short {
  NONE,
  MODULE_MAP,
  HEADER_MODULE,
  MODULE_INTERFACE,
  NUM_ENUMERATORS
};

CompilingModuleKind FromPasta(pasta::CompilingModuleKind pasta_val);

inline static const char *EnumerationName(CompilingModuleKind) {
  return "CompilingModuleKind";
}

const char *EnumeratorName(CompilingModuleKind);

enum class ConstexprSpecKind : unsigned short {
  UNSPECIFIED,
  CONSTEXPR,
  CONSTEVAL,
  CONSTINIT,
  NUM_ENUMERATORS
};

ConstexprSpecKind FromPasta(pasta::ConstexprSpecKind pasta_val);

inline static const char *EnumerationName(ConstexprSpecKind) {
  return "ConstexprSpecKind";
}

const char *EnumeratorName(ConstexprSpecKind);

enum class ConsumedState : unsigned short {
  UNKNOWN,
  CONSUMED,
  UNCONSUMED,
  NUM_ENUMERATORS
};

ConsumedState FromPasta(pasta::ConsumedState pasta_val);

inline static const char *EnumerationName(ConsumedState) {
  return "ConsumedState";
}

const char *EnumeratorName(ConsumedState);

enum class ConventionKind : unsigned short {
  NONE,
  NON_NULL_ERROR,
  ZERO_ARGUMENT,
  NON_ZERO_ARGUMENT,
  NUM_ENUMERATORS
};

ConventionKind FromPasta(pasta::ConventionKind pasta_val);

inline static const char *EnumerationName(ConventionKind) {
  return "ConventionKind";
}

const char *EnumeratorName(ConventionKind);

enum class CoreFoundationABI : unsigned short {
  UNSPECIFIED,
  STANDALONE,
  OBJECTIVE_C,
  SWIFT,
  SWIFT50,
  SWIFT42,
  SWIFT41,
  NUM_ENUMERATORS
};

CoreFoundationABI FromPasta(pasta::CoreFoundationABI pasta_val);

inline static const char *EnumerationName(CoreFoundationABI) {
  return "CoreFoundationABI";
}

const char *EnumeratorName(CoreFoundationABI);

enum class DefaultArgKind : unsigned short {
  NONE,
  UNPARSED,
  UNINSTANTIATED,
  NORMAL,
  NUM_ENUMERATORS
};

DefaultArgKind FromPasta(pasta::DefaultArgKind pasta_val);

inline static const char *EnumerationName(DefaultArgKind) {
  return "DefaultArgKind";
}

const char *EnumeratorName(DefaultArgKind);

enum class DefaultCallingConvention : unsigned short {
  NONE,
  C_DECL,
  FAST_CALL,
  STD_CALL,
  VECTOR_CALL,
  REG_CALL,
  NUM_ENUMERATORS
};

DefaultCallingConvention FromPasta(pasta::DefaultCallingConvention pasta_val);

inline static const char *EnumerationName(DefaultCallingConvention) {
  return "DefaultCallingConvention";
}

const char *EnumeratorName(DefaultCallingConvention);

enum class DevTypeTy : unsigned short {
  HOST,
  NO_HOST,
  ANY,
  NUM_ENUMERATORS
};

DevTypeTy FromPasta(pasta::DevTypeTy pasta_val);

inline static const char *EnumerationName(DevTypeTy) {
  return "DevTypeTy";
}

const char *EnumeratorName(DevTypeTy);

enum class DiagnosticLevelMask : unsigned short {
  NONE,
  NOTE,
  REMARK,
  WARNING,
  ERROR,
  ALL,
  NUM_ENUMERATORS
};

DiagnosticLevelMask FromPasta(pasta::DiagnosticLevelMask pasta_val);

inline static const char *EnumerationName(DiagnosticLevelMask) {
  return "DiagnosticLevelMask";
}

const char *EnumeratorName(DiagnosticLevelMask);

enum class DiagnosticType : unsigned short {
  ERROR,
  WARNING,
  NUM_ENUMERATORS
};

DiagnosticType FromPasta(pasta::DiagnosticType pasta_val);

inline static const char *EnumerationName(DiagnosticType) {
  return "DiagnosticType";
}

const char *EnumeratorName(DiagnosticType);

enum class ElaboratedTypeKeyword : unsigned short {
  STRUCT,
  INTERFACE,
  UNION,
  CLASS,
  ENUM,
  TYPENAME,
  NONE,
  NUM_ENUMERATORS
};

ElaboratedTypeKeyword FromPasta(pasta::ElaboratedTypeKeyword pasta_val);

inline static const char *EnumerationName(ElaboratedTypeKeyword) {
  return "ElaboratedTypeKeyword";
}

const char *EnumeratorName(ElaboratedTypeKeyword);

enum class EmbedBitcodeKind : unsigned short {
  EMBED_OFF,
  EMBED_ALL,
  EMBED_BITCODE,
  EMBED_MARKER,
  NUM_ENUMERATORS
};

EmbedBitcodeKind FromPasta(pasta::EmbedBitcodeKind pasta_val);

inline static const char *EnumerationName(EmbedBitcodeKind) {
  return "EmbedBitcodeKind";
}

const char *EnumeratorName(EmbedBitcodeKind);

enum class ExceptionHandlingKind : unsigned short {
  NONE,
  SJ_LJ,
  WIN_EH,
  DWARF_CFI,
  WASM,
  NUM_ENUMERATORS
};

ExceptionHandlingKind FromPasta(pasta::ExceptionHandlingKind pasta_val);

inline static const char *EnumerationName(ExceptionHandlingKind) {
  return "ExceptionHandlingKind";
}

const char *EnumeratorName(ExceptionHandlingKind);

enum class ExceptionSpecificationType : unsigned short {
  NONE,
  DYNAMIC_NONE,
  DYNAMIC,
  MS_ANY,
  NO_THROW,
  BASIC_NOEXCEPT,
  DEPENDENT_NOEXCEPT,
  NOEXCEPT_FALSE,
  NOEXCEPT_TRUE,
  UNEVALUATED,
  UNINSTANTIATED,
  UNPARSED,
  NUM_ENUMERATORS
};

ExceptionSpecificationType FromPasta(pasta::ExceptionSpecificationType pasta_val);

inline static const char *EnumerationName(ExceptionSpecificationType) {
  return "ExceptionSpecificationType";
}

const char *EnumeratorName(ExceptionSpecificationType);

enum class ExplicitSpecKind : unsigned short {
  RESOLVED_FALSE,
  RESOLVED_TRUE,
  UNRESOLVED,
  NUM_ENUMERATORS
};

ExplicitSpecKind FromPasta(pasta::ExplicitSpecKind pasta_val);

inline static const char *EnumerationName(ExplicitSpecKind) {
  return "ExplicitSpecKind";
}

const char *EnumeratorName(ExplicitSpecKind);

enum class ExprDependence : unsigned short {
  UNEXPANDED_PACK,
  INSTANTIATION,
  TYPE,
  VALUE,
  ERROR,
  NONE,
  ALL,
  TYPE_VALUE,
  TYPE_INSTANTIATION,
  VALUE_INSTANTIATION,
  TYPE_VALUE_INSTANTIATION,
  ERROR_DEPENDENT,
  NUM_ENUMERATORS
};

ExprDependence FromPasta(pasta::ExprDependence pasta_val);

inline static const char *EnumerationName(ExprDependence) {
  return "ExprDependence";
}

const char *EnumeratorName(ExprDependence);

enum class ExprObjectKind : unsigned short {
  ORDINARY,
  BIT_FIELD,
  VECTOR_COMPONENT,
  OBJ_C_PROPERTY,
  OBJ_C_SUBSCRIPT,
  MATRIX_COMPONENT,
  NUM_ENUMERATORS
};

ExprObjectKind FromPasta(pasta::ExprObjectKind pasta_val);

inline static const char *EnumerationName(ExprObjectKind) {
  return "ExprObjectKind";
}

const char *EnumeratorName(ExprObjectKind);

enum class ExprOffsets : unsigned short {
  ALLOCATOR,
  ALLOCATOR_TRAITS,
  TOTAL,
  NUM_ENUMERATORS
};

ExprOffsets FromPasta(pasta::ExprOffsets pasta_val);

inline static const char *EnumerationName(ExprOffsets) {
  return "ExprOffsets";
}

const char *EnumeratorName(ExprOffsets);

enum class ExprValueKind : unsigned short {
  PR_VALUE,
  L_VALUE,
  X_VALUE,
  NUM_ENUMERATORS
};

ExprValueKind FromPasta(pasta::ExprValueKind pasta_val);

inline static const char *EnumerationName(ExprValueKind) {
  return "ExprValueKind";
}

const char *EnumeratorName(ExprValueKind);

enum class ExpressionTrait : unsigned short {
  IS_L_VALUE_EXPRESSION,
  IS_R_VALUE_EXPRESSION,
  NUM_ENUMERATORS
};

ExpressionTrait FromPasta(pasta::ExpressionTrait pasta_val);

inline static const char *EnumerationName(ExpressionTrait) {
  return "ExpressionTrait";
}

const char *EnumeratorName(ExpressionTrait);

enum class ExtKind : unsigned short {
  ALWAYS,
  NEVER,
  REPLY_HAZY,
  NUM_ENUMERATORS
};

ExtKind FromPasta(pasta::ExtKind pasta_val);

inline static const char *EnumerationName(ExtKind) {
  return "ExtKind";
}

const char *EnumeratorName(ExtKind);

enum class ExtendArgsKind : unsigned short {
  EXTEND_TO32,
  EXTEND_TO64,
  NUM_ENUMERATORS
};

ExtendArgsKind FromPasta(pasta::ExtendArgsKind pasta_val);

inline static const char *EnumerationName(ExtendArgsKind) {
  return "ExtendArgsKind";
}

const char *EnumeratorName(ExtendArgsKind);

enum class FPExceptionModeKind : unsigned short {
  IGNORE,
  MAY_TRAP,
  STRICT,
  NUM_ENUMERATORS
};

FPExceptionModeKind FromPasta(pasta::FPExceptionModeKind pasta_val);

inline static const char *EnumerationName(FPExceptionModeKind) {
  return "FPExceptionModeKind";
}

const char *EnumeratorName(FPExceptionModeKind);

enum class FPModeKind : unsigned short {
  OFF,
  ON,
  FAST,
  FAST_HONOR_PRAGMAS,
  NUM_ENUMERATORS
};

FPModeKind FromPasta(pasta::FPModeKind pasta_val);

inline static const char *EnumerationName(FPModeKind) {
  return "FPModeKind";
}

const char *EnumeratorName(FPModeKind);

enum class FamilyKind : unsigned short {
  NONE,
  ALLOC,
  COPY,
  INITIALIZER,
  MUTABLE_COPY,
  NEW,
  NUM_ENUMERATORS
};

FamilyKind FromPasta(pasta::FamilyKind pasta_val);

inline static const char *EnumerationName(FamilyKind) {
  return "FamilyKind";
}

const char *EnumeratorName(FamilyKind);

enum class FiniteLoopsKind : unsigned short {
  LANGUAGE,
  ALWAYS,
  NEVER,
  NUM_ENUMERATORS
};

FiniteLoopsKind FromPasta(pasta::FiniteLoopsKind pasta_val);

inline static const char *EnumerationName(FiniteLoopsKind) {
  return "FiniteLoopsKind";
}

const char *EnumeratorName(FiniteLoopsKind);

enum class FramePointerKind : unsigned short {
  NONE,
  NON_LEAF,
  ALL,
  NUM_ENUMERATORS
};

FramePointerKind FromPasta(pasta::FramePointerKind pasta_val);

inline static const char *EnumerationName(FramePointerKind) {
  return "FramePointerKind";
}

const char *EnumeratorName(FramePointerKind);

enum class GC : unsigned short {
  GC_NONE,
  WEAK,
  STRONG,
  NUM_ENUMERATORS
};

GC FromPasta(pasta::GC pasta_val);

inline static const char *EnumerationName(GC) {
  return "GC";
}

const char *EnumeratorName(GC);

enum class GCMode : unsigned short {
  NON_GC,
  GC_ONLY,
  HYBRID_GC,
  NUM_ENUMERATORS
};

GCMode FromPasta(pasta::GCMode pasta_val);

inline static const char *EnumerationName(GCMode) {
  return "GCMode";
}

const char *EnumeratorName(GCMode);

enum class GVALinkage : unsigned short {
  INTERNAL,
  AVAILABLE_EXTERNALLY,
  DISCARDABLE_ODR,
  STRONG_EXTERNAL,
  STRONG_ODR,
  NUM_ENUMERATORS
};

GVALinkage FromPasta(pasta::GVALinkage pasta_val);

inline static const char *EnumerationName(GVALinkage) {
  return "GVALinkage";
}

const char *EnumeratorName(GVALinkage);

enum class GetBuiltinTypeError : unsigned short {
  NONE,
  MISSING_TYPE,
  MISSING_STDIO,
  MISSING,
  MISSING_UCONTEXT,
  NUM_ENUMERATORS
};

GetBuiltinTypeError FromPasta(pasta::GetBuiltinTypeError pasta_val);

inline static const char *EnumerationName(GetBuiltinTypeError) {
  return "GetBuiltinTypeError";
}

const char *EnumeratorName(GetBuiltinTypeError);

enum class GuardArg : unsigned short {
  NOCF,
  NUM_ENUMERATORS
};

GuardArg FromPasta(pasta::GuardArg pasta_val);

inline static const char *EnumerationName(GuardArg) {
  return "GuardArg";
}

const char *EnumeratorName(GuardArg);

enum class ID : unsigned short {
  WORK_GROUP,
  DEVICE,
  ALL_SVM_DEVICES,
  SUB_GROUP,
  NUM_ENUMERATORS
};

ID FromPasta(pasta::ID pasta_val);

inline static const char *EnumerationName(ID) {
  return "ID";
}

const char *EnumeratorName(ID);

enum class IdentifierInfoFlag : unsigned short {
  ZERO_ARGUMENT,
  ONE_ARGUMENT,
  MULTI_ARGUMENT,
  // Skipped repeat pasta::kArgumentFlags
  NUM_ENUMERATORS
};

IdentifierInfoFlag FromPasta(pasta::IdentifierInfoFlag pasta_val);

inline static const char *EnumerationName(IdentifierInfoFlag) {
  return "IdentifierInfoFlag";
}

const char *EnumeratorName(IdentifierInfoFlag);

enum class ImbueAttribute : unsigned short {
  NONE,
  ALWAYS,
  NEVER,
  ALWAYSARG1,
  NUM_ENUMERATORS
};

ImbueAttribute FromPasta(pasta::ImbueAttribute pasta_val);

inline static const char *EnumerationName(ImbueAttribute) {
  return "ImbueAttribute";
}

const char *EnumeratorName(ImbueAttribute);

enum class ImplicitReason : unsigned short {
  NONE,
  ARC_FORBIDDEN_TYPE,
  FORBIDDEN_WEAK,
  ARC_FORBIDDEN_CONVERSION,
  ARC_INIT_RETURNS_UNRELATED,
  ARC_FIELD_WITH_OWNERSHIP,
  NUM_ENUMERATORS
};

ImplicitReason FromPasta(pasta::ImplicitReason pasta_val);

inline static const char *EnumerationName(ImplicitReason) {
  return "ImplicitReason";
}

const char *EnumeratorName(ImplicitReason);

enum class InClassInitStyle : unsigned short {
  NO_INITIALIZER,
  COPY_INITIALIZER,
  LIST_INITIALIZER,
  NUM_ENUMERATORS
};

InClassInitStyle FromPasta(pasta::InClassInitStyle pasta_val);

inline static const char *EnumerationName(InClassInitStyle) {
  return "InClassInitStyle";
}

const char *EnumeratorName(InClassInitStyle);

enum class InheritedDesignatedInitializersState : unsigned short {
  UNKNOWN,
  INHERITED,
  NOT_INHERITED,
  NUM_ENUMERATORS
};

InheritedDesignatedInitializersState FromPasta(pasta::InheritedDesignatedInitializersState pasta_val);

inline static const char *EnumerationName(InheritedDesignatedInitializersState) {
  return "InheritedDesignatedInitializersState";
}

const char *EnumeratorName(InheritedDesignatedInitializersState);

enum class InitStorageKind : unsigned short {
  NO_INITIALIZER,
  IN_CLASS_COPY_INITIALIZER,
  IN_CLASS_LIST_INITIALIZER,
  CAPTURED_VLA_TYPE,
  NUM_ENUMERATORS
};

InitStorageKind FromPasta(pasta::InitStorageKind pasta_val);

inline static const char *EnumerationName(InitStorageKind) {
  return "InitStorageKind";
}

const char *EnumeratorName(InitStorageKind);

enum class InlineVariableDefinitionKind : unsigned short {
  NONE,
  WEAK,
  WEAK_UNKNOWN,
  STRONG,
  NUM_ENUMERATORS
};

InlineVariableDefinitionKind FromPasta(pasta::InlineVariableDefinitionKind pasta_val);

inline static const char *EnumerationName(InlineVariableDefinitionKind) {
  return "InlineVariableDefinitionKind";
}

const char *EnumeratorName(InlineVariableDefinitionKind);

enum class InliningMethod : unsigned short {
  NORMAL_INLINING,
  ONLY_HINT_INLINING,
  ONLY_ALWAYS_INLINING,
  NUM_ENUMERATORS
};

InliningMethod FromPasta(pasta::InliningMethod pasta_val);

inline static const char *EnumerationName(InliningMethod) {
  return "InliningMethod";
}

const char *EnumeratorName(InliningMethod);

enum class InterruptType : unsigned short {
  IRQ,
  FIQ,
  SWI,
  ABORT,
  UNDEF,
  GENERIC,
  NUM_ENUMERATORS
};

InterruptType FromPasta(pasta::InterruptType pasta_val);

inline static const char *EnumerationName(InterruptType) {
  return "InterruptType";
}

const char *EnumeratorName(InterruptType);

enum class Kinds : unsigned short {
  L_VALUE,
  X_VALUE,
  FUNCTION,
  VOID,
  ADDRESSABLE_VOID,
  DUPLICATE_VECTOR_COMPONENTS,
  MEMBER_FUNCTION,
  SUB_OBJ_C_PROPERTY_SETTING,
  CLASS_TEMPORARY,
  ARRAY_TEMPORARY,
  OBJ_C_MESSAGE_R_VALUE,
  PR_VALUE,
  NUM_ENUMERATORS
};

Kinds FromPasta(pasta::Kinds pasta_val);

inline static const char *EnumerationName(Kinds) {
  return "Kinds";
}

const char *EnumeratorName(Kinds);

enum class LambdaCaptureDefault : unsigned short {
  NONE,
  BY_COPY,
  BY_REFERENCE,
  NUM_ENUMERATORS
};

LambdaCaptureDefault FromPasta(pasta::LambdaCaptureDefault pasta_val);

inline static const char *EnumerationName(LambdaCaptureDefault) {
  return "LambdaCaptureDefault";
}

const char *EnumeratorName(LambdaCaptureDefault);

enum class LambdaCaptureKind : unsigned short {
  THIS,
  STAR_THIS,
  BY_COPY,
  BY_REFERENCE,
  VLA_TYPE,
  NUM_ENUMERATORS
};

LambdaCaptureKind FromPasta(pasta::LambdaCaptureKind pasta_val);

inline static const char *EnumerationName(LambdaCaptureKind) {
  return "LambdaCaptureKind";
}

const char *EnumeratorName(LambdaCaptureKind);

enum class LangAS : unsigned short {
  DEFAULT,
  OPENCL_GLOBAL,
  OPENCL_LOCAL,
  OPENCL_CONSTANT,
  OPENCL_PRIVATE,
  OPENCL_GENERIC,
  OPENCL_GLOBAL_DEVICE,
  OPENCL_GLOBAL_HOST,
  CUDA_DEVICE,
  CUDA_CONSTANT,
  CUDA_SHARED,
  SYCL_GLOBAL,
  SYCL_GLOBAL_DEVICE,
  SYCL_GLOBAL_HOST,
  SYCL_LOCAL,
  SYCL_PRIVATE,
  PTR32_SPTR,
  PTR32_UPTR,
  PTR64,
  NUM_ENUMERATORS
};

LangAS FromPasta(pasta::LangAS pasta_val);

inline static const char *EnumerationName(LangAS) {
  return "LangAS";
}

const char *EnumeratorName(LangAS);

enum class LangFeatures : unsigned short {
  LINE_COMMENT,
  C99,
  C11,
  C17,
  C2_X,
  C_PLUS_PLUS,
  C_PLUS_PLUS11,
  C_PLUS_PLUS14,
  C_PLUS_PLUS17,
  C_PLUS_PLUS20,
  C_PLUS_PLUS2_B,
  DIGRAPHS,
  GNU_MODE,
  HEX_FLOAT,
  IMPLICIT_INT,
  OPEN_CL,
  NUM_ENUMERATORS
};

LangFeatures FromPasta(pasta::LangFeatures pasta_val);

inline static const char *EnumerationName(LangFeatures) {
  return "LangFeatures";
}

const char *EnumeratorName(LangFeatures);

enum class Language : unsigned short {
  UNKNOWN,
  ASSEMBLY,
  LLVMIR,
  C,
  CXX,
  OBJ_C,
  OBJ_CXX,
  OPEN_CL,
  OPEN_CLCXX,
  CUDA,
  RENDER_SCRIPT,
  HIP,
  NUM_ENUMERATORS
};

Language FromPasta(pasta::Language pasta_val);

inline static const char *EnumerationName(Language) {
  return "Language";
}

const char *EnumeratorName(Language);

enum class LanguageLinkage : unsigned short {
  C_LANGUAGE_LINKAGE,
  CXX_LANGUAGE_LINKAGE,
  NO_LANGUAGE_LINKAGE,
  NUM_ENUMERATORS
};

LanguageLinkage FromPasta(pasta::LanguageLinkage pasta_val);

inline static const char *EnumerationName(LanguageLinkage) {
  return "LanguageLinkage";
}

const char *EnumeratorName(LanguageLinkage);

enum class LaxVectorConversionKind : unsigned short {
  NONE,
  INTEGER,
  ALL,
  NUM_ENUMERATORS
};

LaxVectorConversionKind FromPasta(pasta::LaxVectorConversionKind pasta_val);

inline static const char *EnumerationName(LaxVectorConversionKind) {
  return "LaxVectorConversionKind";
}

const char *EnumeratorName(LaxVectorConversionKind);

enum class Level : unsigned short {
  IGNORED,
  NOTE,
  REMARK,
  WARNING,
  ERROR,
  FATAL,
  NUM_ENUMERATORS
};

Level FromPasta(pasta::Level pasta_val);

inline static const char *EnumerationName(Level) {
  return "Level";
}

const char *EnumeratorName(Level);

enum class Linkage : unsigned short {
  NO_LINKAGE,
  INTERNAL_LINKAGE,
  UNIQUE_EXTERNAL_LINKAGE,
  VISIBLE_NO_LINKAGE,
  MODULE_INTERNAL_LINKAGE,
  MODULE_LINKAGE,
  EXTERNAL_LINKAGE,
  NUM_ENUMERATORS
};

Linkage FromPasta(pasta::Linkage pasta_val);

inline static const char *EnumerationName(Linkage) {
  return "Linkage";
}

const char *EnumeratorName(Linkage);

enum class LoopHintState : unsigned short {
  ENABLE,
  DISABLE,
  NUMERIC,
  FIXED_WIDTH,
  SCALABLE_WIDTH,
  ASSUME_SAFETY,
  FULL,
  NUM_ENUMERATORS
};

LoopHintState FromPasta(pasta::LoopHintState pasta_val);

inline static const char *EnumerationName(LoopHintState) {
  return "LoopHintState";
}

const char *EnumeratorName(LoopHintState);

enum class MSInheritanceModel : unsigned short {
  SINGLE,
  MULTIPLE,
  VIRTUAL,
  UNSPECIFIED,
  NUM_ENUMERATORS
};

MSInheritanceModel FromPasta(pasta::MSInheritanceModel pasta_val);

inline static const char *EnumerationName(MSInheritanceModel) {
  return "MSInheritanceModel";
}

const char *EnumeratorName(MSInheritanceModel);

enum class MSVCMajorVersion : unsigned short {
  MSVC2010,
  MSVC2012,
  MSVC2013,
  MSVC2015,
  MSVC2017,
  MSVC20175,
  MSVC20177,
  MSVC2019,
  MSVC20198,
  NUM_ENUMERATORS
};

MSVCMajorVersion FromPasta(pasta::MSVCMajorVersion pasta_val);

inline static const char *EnumerationName(MSVCMajorVersion) {
  return "MSVCMajorVersion";
}

const char *EnumeratorName(MSVCMajorVersion);

enum class MSVtorDispMode : unsigned short {
  NEVER,
  FOR_VIRTUAL_BASE_OVERRIDE,
  FOR_VF_TABLE,
  NUM_ENUMERATORS
};

MSVtorDispMode FromPasta(pasta::MSVtorDispMode pasta_val);

inline static const char *EnumerationName(MSVtorDispMode) {
  return "MSVtorDispMode";
}

const char *EnumeratorName(MSVtorDispMode);

enum class MapTypeTy : unsigned short {
  TO,
  LINK,
  NUM_ENUMERATORS
};

MapTypeTy FromPasta(pasta::MapTypeTy pasta_val);

inline static const char *EnumerationName(MapTypeTy) {
  return "MapTypeTy";
}

const char *EnumeratorName(MapTypeTy);

enum class MethodRefFlags : unsigned short {
  METHOD_REFERENCE_NONE,
  METHOD_REFERENCE_GETTER,
  METHOD_REFERENCE_SETTER,
  NUM_ENUMERATORS
};

MethodRefFlags FromPasta(pasta::MethodRefFlags pasta_val);

inline static const char *EnumerationName(MethodRefFlags) {
  return "MethodRefFlags";
}

const char *EnumeratorName(MethodRefFlags);

enum class ModifiableType : unsigned short {
  UNTESTED,
  MODIFIABLE,
  R_VALUE,
  FUNCTION,
  L_VALUE_CAST,
  NO_SETTER_PROPERTY,
  CONST_QUALIFIED,
  CONST_QUALIFIED_FIELD,
  CONST_ADDR_SPACE,
  ARRAY_TYPE,
  INCOMPLETE_TYPE,
  NUM_ENUMERATORS
};

ModifiableType FromPasta(pasta::ModifiableType pasta_val);

inline static const char *EnumerationName(ModifiableType) {
  return "ModifiableType";
}

const char *EnumeratorName(ModifiableType);

enum class MultiVersionKind : unsigned short {
  NONE,
  TARGET,
  CPU_SPECIFIC,
  CPU_DISPATCH,
  NUM_ENUMERATORS
};

MultiVersionKind FromPasta(pasta::MultiVersionKind pasta_val);

inline static const char *EnumerationName(MultiVersionKind) {
  return "MultiVersionKind";
}

const char *EnumeratorName(MultiVersionKind);

enum class NameKind : unsigned short {
  TEMPLATE,
  OVERLOADED_TEMPLATE,
  ASSUMED_TEMPLATE,
  QUALIFIED_TEMPLATE,
  DEPENDENT_TEMPLATE,
  SUBST_TEMPLATE_TEMPLATE_PARM,
  SUBST_TEMPLATE_TEMPLATE_PARM_PACK,
  NUM_ENUMERATORS
};

NameKind FromPasta(pasta::NameKind pasta_val);

inline static const char *EnumerationName(NameKind) {
  return "NameKind";
}

const char *EnumeratorName(NameKind);

enum class NeedExtraManglingDecl : unsigned short {
  NEED_EXTRA_MANGLING_DECLARATION,
  NUM_ENUMERATORS
};

NeedExtraManglingDecl FromPasta(pasta::NeedExtraManglingDecl pasta_val);

inline static const char *EnumerationName(NeedExtraManglingDecl) {
  return "NeedExtraManglingDecl";
}

const char *EnumeratorName(NeedExtraManglingDecl);

enum class NestedNameSpecifierDependence : unsigned short {
  UNEXPANDED_PACK,
  INSTANTIATION,
  DEPENDENT,
  ERROR,
  NONE,
  DEPENDENT_INSTANTIATION,
  ALL,
  NUM_ENUMERATORS
};

NestedNameSpecifierDependence FromPasta(pasta::NestedNameSpecifierDependence pasta_val);

inline static const char *EnumerationName(NestedNameSpecifierDependence) {
  return "NestedNameSpecifierDependence";
}

const char *EnumeratorName(NestedNameSpecifierDependence);

enum class NewtypeKind : unsigned short {
  STRUCT,
  ENUM,
  NUM_ENUMERATORS
};

NewtypeKind FromPasta(pasta::NewtypeKind pasta_val);

inline static const char *EnumerationName(NewtypeKind) {
  return "NewtypeKind";
}

const char *EnumeratorName(NewtypeKind);

enum class NonOdrUseReason : unsigned short {
  NONE,
  UNEVALUATED,
  CONSTANT,
  DISCARDED,
  NUM_ENUMERATORS
};

NonOdrUseReason FromPasta(pasta::NonOdrUseReason pasta_val);

inline static const char *EnumerationName(NonOdrUseReason) {
  return "NonOdrUseReason";
}

const char *EnumeratorName(NonOdrUseReason);

enum class NonceObjCInterface : unsigned short {
  OBJ_C_INTERFACE,
  NUM_ENUMERATORS
};

NonceObjCInterface FromPasta(pasta::NonceObjCInterface pasta_val);

inline static const char *EnumerationName(NonceObjCInterface) {
  return "NonceObjCInterface";
}

const char *EnumeratorName(NonceObjCInterface);

enum class NullabilityKind : unsigned short {
  NON_NULL,
  NULLABLE,
  UNSPECIFIED,
  NULLABLE_RESULT,
  NUM_ENUMERATORS
};

NullabilityKind FromPasta(pasta::NullabilityKind pasta_val);

inline static const char *EnumerationName(NullabilityKind) {
  return "NullabilityKind";
}

const char *EnumeratorName(NullabilityKind);

enum class ObjCBridgeCastKind : unsigned short {
  BRIDGE,
  BRIDGE_TRANSFER,
  BRIDGE_RETAINED,
  NUM_ENUMERATORS
};

ObjCBridgeCastKind FromPasta(pasta::ObjCBridgeCastKind pasta_val);

inline static const char *EnumerationName(ObjCBridgeCastKind) {
  return "ObjCBridgeCastKind";
}

const char *EnumeratorName(ObjCBridgeCastKind);

enum class ObjCDispatchMethodKind : unsigned short {
  LEGACY,
  NON_LEGACY,
  MIXED,
  NUM_ENUMERATORS
};

ObjCDispatchMethodKind FromPasta(pasta::ObjCDispatchMethodKind pasta_val);

inline static const char *EnumerationName(ObjCDispatchMethodKind) {
  return "ObjCDispatchMethodKind";
}

const char *EnumeratorName(ObjCDispatchMethodKind);

enum class ObjCInstanceTypeFamily : unsigned short {
  NONE,
  ARRAY,
  DICTIONARY,
  SINGLETON,
  INITIALIZER,
  RETURNS_SELF,
  NUM_ENUMERATORS
};

ObjCInstanceTypeFamily FromPasta(pasta::ObjCInstanceTypeFamily pasta_val);

inline static const char *EnumerationName(ObjCInstanceTypeFamily) {
  return "ObjCInstanceTypeFamily";
}

const char *EnumeratorName(ObjCInstanceTypeFamily);

enum class ObjCKeywordKind : unsigned short {
  NOT_KEYWORD,
  CLASS,
  COMPATIBILITY_ALIAS,
  DEFINITIONS,
  ENCODE,
  OBJC_END,
  IMPLEMENTATION,
  INTERFACE,
  PRIVATE,
  PROTECTED,
  PROTOCOL,
  PUBLIC,
  SELECTOR,
  THROW,
  TRY,
  CATCH,
  FINALLY,
  SYNCHRONIZED,
  AUTORELEASEPOOL,
  PROPERTY,
  PACKAGE,
  REQUIRED,
  OPTIONAL,
  SYNTHESIZE,
  DYNAMIC,
  IMPORT,
  AVAILABLE,
  NUM_ENUMERATORS
};

ObjCKeywordKind FromPasta(pasta::ObjCKeywordKind pasta_val);

inline static const char *EnumerationName(ObjCKeywordKind) {
  return "ObjCKeywordKind";
}

const char *EnumeratorName(ObjCKeywordKind);

enum class ObjCLifetime : unsigned short {
  NONE,
  EXPLICIT_NONE,
  STRONG,
  WEAK,
  AUTORELEASING,
  NUM_ENUMERATORS
};

ObjCLifetime FromPasta(pasta::ObjCLifetime pasta_val);

inline static const char *EnumerationName(ObjCLifetime) {
  return "ObjCLifetime";
}

const char *EnumeratorName(ObjCLifetime);

enum class ObjCMethodFamily : unsigned short {
  NONE,
  ALLOC,
  COPY,
  INITIALIZER,
  MUTABLE_COPY,
  NEW,
  AUTORELEASE,
  DEALLOC,
  FINALIZE,
  RELEASE,
  RETAIN,
  RETAIN_COUNT,
  SELF,
  INITIALIZE,
  PERFORM_SELECTOR,
  NUM_ENUMERATORS
};

ObjCMethodFamily FromPasta(pasta::ObjCMethodFamily pasta_val);

inline static const char *EnumerationName(ObjCMethodFamily) {
  return "ObjCMethodFamily";
}

const char *EnumeratorName(ObjCMethodFamily);

enum class ObjCPropertyQueryKind : unsigned short {
  QUERY_UNKNOWN,
  QUERY_INSTANCE,
  QUERY_CLASS,
  NUM_ENUMERATORS
};

ObjCPropertyQueryKind FromPasta(pasta::ObjCPropertyQueryKind pasta_val);

inline static const char *EnumerationName(ObjCPropertyQueryKind) {
  return "ObjCPropertyQueryKind";
}

const char *EnumeratorName(ObjCPropertyQueryKind);

enum class ObjCStringFormatFamily : unsigned short {
  NONE,
  NS_STRING,
  CF_STRING,
  NUM_ENUMERATORS
};

ObjCStringFormatFamily FromPasta(pasta::ObjCStringFormatFamily pasta_val);

inline static const char *EnumerationName(ObjCStringFormatFamily) {
  return "ObjCStringFormatFamily";
}

const char *EnumeratorName(ObjCStringFormatFamily);

enum class ObjCSubstitutionContext : unsigned short {
  ORDINARY,
  RESULT,
  PARAMETER,
  PROPERTY,
  SUPERCLASS,
  NUM_ENUMERATORS
};

ObjCSubstitutionContext FromPasta(pasta::ObjCSubstitutionContext pasta_val);

inline static const char *EnumerationName(ObjCSubstitutionContext) {
  return "ObjCSubstitutionContext";
}

const char *EnumeratorName(ObjCSubstitutionContext);

enum class ObjCTypeParamVariance : unsigned short {
  INVARIANT,
  COVARIANT,
  CONTRAVARIANT,
  NUM_ENUMERATORS
};

ObjCTypeParamVariance FromPasta(pasta::ObjCTypeParamVariance pasta_val);

inline static const char *EnumerationName(ObjCTypeParamVariance) {
  return "ObjCTypeParamVariance";
}

const char *EnumeratorName(ObjCTypeParamVariance);

enum class OnOffSwitch : unsigned short {
  ON,
  OFF,
  DEFAULT,
  NUM_ENUMERATORS
};

OnOffSwitch FromPasta(pasta::OnOffSwitch pasta_val);

inline static const char *EnumerationName(OnOffSwitch) {
  return "OnOffSwitch";
}

const char *EnumeratorName(OnOffSwitch);

enum class OnStackType : unsigned short {
  ON_STACK,
  NUM_ENUMERATORS
};

OnStackType FromPasta(pasta::OnStackType pasta_val);

inline static const char *EnumerationName(OnStackType) {
  return "OnStackType";
}

const char *EnumeratorName(OnStackType);

enum class OpenMPAtomicDefaultMemOrderClauseKind : unsigned short {
  SEQ_CST,
  ACQ_REL,
  RELAXED,
  UNKNOWN,
  NUM_ENUMERATORS
};

OpenMPAtomicDefaultMemOrderClauseKind FromPasta(pasta::OpenMPAtomicDefaultMemOrderClauseKind pasta_val);

inline static const char *EnumerationName(OpenMPAtomicDefaultMemOrderClauseKind) {
  return "OpenMPAtomicDefaultMemOrderClauseKind";
}

const char *EnumeratorName(OpenMPAtomicDefaultMemOrderClauseKind);

enum class OpenMPDefaultmapClauseKind : unsigned short {
  SCALAR,
  AGGREGATE,
  POINTER,
  UNKNOWN,
  NUM_ENUMERATORS
};

OpenMPDefaultmapClauseKind FromPasta(pasta::OpenMPDefaultmapClauseKind pasta_val);

inline static const char *EnumerationName(OpenMPDefaultmapClauseKind) {
  return "OpenMPDefaultmapClauseKind";
}

const char *EnumeratorName(OpenMPDefaultmapClauseKind);

enum class OpenMPDefaultmapClauseModifier : unsigned short {
  UNKNOWN,
  ALLOC,
  TO,
  FROM,
  TOFROM,
  NONE,
  DEFAULT,
  PRESENT,
  NUM_ENUMERATORS
};

OpenMPDefaultmapClauseModifier FromPasta(pasta::OpenMPDefaultmapClauseModifier pasta_val);

inline static const char *EnumerationName(OpenMPDefaultmapClauseModifier) {
  return "OpenMPDefaultmapClauseModifier";
}

const char *EnumeratorName(OpenMPDefaultmapClauseModifier);

enum class OpenMPDependClauseKind : unsigned short {
  IN,
  OUT,
  INOUT,
  MUTEXINOUTSET,
  DEPOBJ,
  SOURCE,
  SINK,
  UNKNOWN,
  NUM_ENUMERATORS
};

OpenMPDependClauseKind FromPasta(pasta::OpenMPDependClauseKind pasta_val);

inline static const char *EnumerationName(OpenMPDependClauseKind) {
  return "OpenMPDependClauseKind";
}

const char *EnumeratorName(OpenMPDependClauseKind);

enum class OpenMPDeviceClauseModifier : unsigned short {
  ANCESTOR,
  DEVICE_NUM,
  UNKNOWN,
  NUM_ENUMERATORS
};

OpenMPDeviceClauseModifier FromPasta(pasta::OpenMPDeviceClauseModifier pasta_val);

inline static const char *EnumerationName(OpenMPDeviceClauseModifier) {
  return "OpenMPDeviceClauseModifier";
}

const char *EnumeratorName(OpenMPDeviceClauseModifier);

enum class OpenMPDeviceType : unsigned short {
  HOST,
  NOHOST,
  ANY,
  UNKNOWN,
  NUM_ENUMERATORS
};

OpenMPDeviceType FromPasta(pasta::OpenMPDeviceType pasta_val);

inline static const char *EnumerationName(OpenMPDeviceType) {
  return "OpenMPDeviceType";
}

const char *EnumeratorName(OpenMPDeviceType);

enum class OpenMPDistScheduleClauseKind : unsigned short {
  STATIC,
  UNKNOWN,
  NUM_ENUMERATORS
};

OpenMPDistScheduleClauseKind FromPasta(pasta::OpenMPDistScheduleClauseKind pasta_val);

inline static const char *EnumerationName(OpenMPDistScheduleClauseKind) {
  return "OpenMPDistScheduleClauseKind";
}

const char *EnumeratorName(OpenMPDistScheduleClauseKind);

enum class OpenMPLastprivateModifier : unsigned short {
  CONDITIONAL,
  UNKNOWN,
  NUM_ENUMERATORS
};

OpenMPLastprivateModifier FromPasta(pasta::OpenMPLastprivateModifier pasta_val);

inline static const char *EnumerationName(OpenMPLastprivateModifier) {
  return "OpenMPLastprivateModifier";
}

const char *EnumeratorName(OpenMPLastprivateModifier);

enum class OpenMPLinearClauseKind : unsigned short {
  VALUE,
  REFERENCE,
  UVAL,
  UNKNOWN,
  NUM_ENUMERATORS
};

OpenMPLinearClauseKind FromPasta(pasta::OpenMPLinearClauseKind pasta_val);

inline static const char *EnumerationName(OpenMPLinearClauseKind) {
  return "OpenMPLinearClauseKind";
}

const char *EnumeratorName(OpenMPLinearClauseKind);

enum class OpenMPMapClauseKind : unsigned short {
  ALLOC,
  TO,
  FROM,
  TOFROM,
  DELETE,
  RELEASE,
  UNKNOWN,
  NUM_ENUMERATORS
};

OpenMPMapClauseKind FromPasta(pasta::OpenMPMapClauseKind pasta_val);

inline static const char *EnumerationName(OpenMPMapClauseKind) {
  return "OpenMPMapClauseKind";
}

const char *EnumeratorName(OpenMPMapClauseKind);

enum class OpenMPMapModifierKind : unsigned short {
  UNKNOWN,
  ALWAYS,
  CLOSE,
  MAPPER,
  PRESENT,
  NUM_ENUMERATORS
};

OpenMPMapModifierKind FromPasta(pasta::OpenMPMapModifierKind pasta_val);

inline static const char *EnumerationName(OpenMPMapModifierKind) {
  return "OpenMPMapModifierKind";
}

const char *EnumeratorName(OpenMPMapModifierKind);

enum class OpenMPMotionModifierKind : unsigned short {
  MOTIONMODIFIER_MAPPER,
  MOTIONMODIFIER_PRESENT,
  MOTIONMODIFIER_UNKNOWN,
  NUM_ENUMERATORS
};

OpenMPMotionModifierKind FromPasta(pasta::OpenMPMotionModifierKind pasta_val);

inline static const char *EnumerationName(OpenMPMotionModifierKind) {
  return "OpenMPMotionModifierKind";
}

const char *EnumeratorName(OpenMPMotionModifierKind);

enum class OpenMPOrderClauseKind : unsigned short {
  CONCURRENT,
  UNKNOWN,
  NUM_ENUMERATORS
};

OpenMPOrderClauseKind FromPasta(pasta::OpenMPOrderClauseKind pasta_val);

inline static const char *EnumerationName(OpenMPOrderClauseKind) {
  return "OpenMPOrderClauseKind";
}

const char *EnumeratorName(OpenMPOrderClauseKind);

enum class OpenMPReductionClauseModifier : unsigned short {
  DEFAULT,
  INSCAN,
  TASK,
  UNKNOWN,
  NUM_ENUMERATORS
};

OpenMPReductionClauseModifier FromPasta(pasta::OpenMPReductionClauseModifier pasta_val);

inline static const char *EnumerationName(OpenMPReductionClauseModifier) {
  return "OpenMPReductionClauseModifier";
}

const char *EnumeratorName(OpenMPReductionClauseModifier);

enum class OpenMPScheduleClauseKind : unsigned short {
  STATIC,
  DYNAMIC,
  GUIDED,
  AUTO,
  RUNTIME,
  UNKNOWN,
  NUM_ENUMERATORS
};

OpenMPScheduleClauseKind FromPasta(pasta::OpenMPScheduleClauseKind pasta_val);

inline static const char *EnumerationName(OpenMPScheduleClauseKind) {
  return "OpenMPScheduleClauseKind";
}

const char *EnumeratorName(OpenMPScheduleClauseKind);

enum class OpenMPScheduleClauseModifier : unsigned short {
  UNKNOWN,
  MONOTONIC,
  NONMONOTONIC,
  SIMD,
  NUM_ENUMERATORS
};

OpenMPScheduleClauseModifier FromPasta(pasta::OpenMPScheduleClauseModifier pasta_val);

inline static const char *EnumerationName(OpenMPScheduleClauseModifier) {
  return "OpenMPScheduleClauseModifier";
}

const char *EnumeratorName(OpenMPScheduleClauseModifier);

enum class OptionType : unsigned short {
  VECTORIZE,
  VECTORIZE_WIDTH,
  INTERLEAVE,
  INTERLEAVE_COUNT,
  UNROLL,
  UNROLL_COUNT,
  UNROLL_AND_JAM,
  UNROLL_AND_JAM_COUNT,
  PIPELINE_DISABLED,
  PIPELINE_INITIATION_INTERVAL,
  DISTRIBUTE,
  VECTORIZE_PREDICATE,
  NUM_ENUMERATORS
};

OptionType FromPasta(pasta::OptionType pasta_val);

inline static const char *EnumerationName(OptionType) {
  return "OptionType";
}

const char *EnumeratorName(OptionType);

enum class OverloadedOperatorKind : unsigned short {
  NONE,
  NEW,
  DELETE,
  ARRAY_NEW,
  ARRAY_DELETE,
  PLUS,
  MINUS,
  STAR,
  SLASH,
  PERCENT,
  CARET,
  AMP,
  PIPE,
  TILDE,
  EXCLAIM,
  EQUAL,
  LESS,
  GREATER,
  PLUS_EQUAL,
  MINUS_EQUAL,
  STAR_EQUAL,
  SLASH_EQUAL,
  PERCENT_EQUAL,
  CARET_EQUAL,
  AMP_EQUAL,
  PIPE_EQUAL,
  LESS_LESS,
  GREATER_GREATER,
  LESS_LESS_EQUAL,
  GREATER_GREATER_EQUAL,
  EQUAL_EQUAL,
  EXCLAIM_EQUAL,
  LESS_EQUAL,
  GREATER_EQUAL,
  SPACESHIP,
  AMP_AMP,
  PIPE_PIPE,
  PLUS_PLUS,
  MINUS_MINUS,
  COMMA,
  ARROW_STAR,
  ARROW,
  CALL,
  SUBSCRIPT,
  CONDITIONAL,
  COAWAIT,
  NUM_ENUMERATORS
};

OverloadedOperatorKind FromPasta(pasta::OverloadedOperatorKind pasta_val);

inline static const char *EnumerationName(OverloadedOperatorKind) {
  return "OverloadedOperatorKind";
}

const char *EnumeratorName(OverloadedOperatorKind);

enum class OverloadsShown : unsigned short {
  ALL,
  BEST,
  NUM_ENUMERATORS
};

OverloadsShown FromPasta(pasta::OverloadsShown pasta_val);

inline static const char *EnumerationName(OverloadsShown) {
  return "OverloadsShown";
}

const char *EnumeratorName(OverloadsShown);

enum class OwnershipKind : unsigned short {
  HOLDS,
  RETURNS,
  TAKES,
  NUM_ENUMERATORS
};

OwnershipKind FromPasta(pasta::OwnershipKind pasta_val);

inline static const char *EnumerationName(OwnershipKind) {
  return "OwnershipKind";
}

const char *EnumeratorName(OwnershipKind);

enum class PCSType : unsigned short {
  AAPCS,
  VFP,
  NUM_ENUMERATORS
};

PCSType FromPasta(pasta::PCSType pasta_val);

inline static const char *EnumerationName(PCSType) {
  return "PCSType";
}

const char *EnumeratorName(PCSType);

enum class PPKeywordKind : unsigned short {
  NOT_KEYWORD,
  IF,
  IFDEF,
  IFNDEF,
  ELIF,
  ELIFDEF,
  ELIFNDEF,
  ELSE,
  ENDIF,
  DEFINED,
  INCLUDE,
  __INCLUDE_MACROS,
  DEFINE,
  UNDEF,
  LINE,
  ERROR,
  PRAGMA,
  IMPORT,
  INCLUDE_NEXT,
  WARNING,
  IDENTIFIER,
  SCCS,
  ASSERT,
  UNASSERT,
  __PUBLIC_MACRO,
  __PRIVATE_MACRO,
  NUM_ENUMERATORS
};

PPKeywordKind FromPasta(pasta::PPKeywordKind pasta_val);

inline static const char *EnumerationName(PPKeywordKind) {
  return "PPKeywordKind";
}

const char *EnumeratorName(PPKeywordKind);

enum class ParameterABI : unsigned short {
  ORDINARY,
  SWIFT_INDIRECT_RESULT,
  SWIFT_ERROR_RESULT,
  SWIFT_CONTEXT,
  SWIFT_ASYNC_CONTEXT,
  NUM_ENUMERATORS
};

ParameterABI FromPasta(pasta::ParameterABI pasta_val);

inline static const char *EnumerationName(ParameterABI) {
  return "ParameterABI";
}

const char *EnumeratorName(ParameterABI);

enum class ParenLocsOffsets : unsigned short {
  L_PAREN,
  R_PAREN,
  TOTAL,
  NUM_ENUMERATORS
};

ParenLocsOffsets FromPasta(pasta::ParenLocsOffsets pasta_val);

inline static const char *EnumerationName(ParenLocsOffsets) {
  return "ParenLocsOffsets";
}

const char *EnumeratorName(ParenLocsOffsets);

enum class PragmaFloatControlKind : unsigned short {
  UNKNOWN,
  PRECISE,
  NO_PRECISE,
  EXCEPT,
  NO_EXCEPT,
  PUSH,
  POP,
  NUM_ENUMERATORS
};

PragmaFloatControlKind FromPasta(pasta::PragmaFloatControlKind pasta_val);

inline static const char *EnumerationName(PragmaFloatControlKind) {
  return "PragmaFloatControlKind";
}

const char *EnumeratorName(PragmaFloatControlKind);

enum class PragmaMSCommentKind : unsigned short {
  UNKNOWN,
  LINKER,
  LIB,
  COMPILER,
  EXE_STRING,
  USER,
  NUM_ENUMERATORS
};

PragmaMSCommentKind FromPasta(pasta::PragmaMSCommentKind pasta_val);

inline static const char *EnumerationName(PragmaMSCommentKind) {
  return "PragmaMSCommentKind";
}

const char *EnumeratorName(PragmaMSCommentKind);

enum class PragmaMSPointersToMembersKind : unsigned short {
  BEST_CASE,
  FULL_GENERALITY_SINGLE_INHERITANCE,
  FULL_GENERALITY_MULTIPLE_INHERITANCE,
  FULL_GENERALITY_VIRTUAL_INHERITANCE,
  NUM_ENUMERATORS
};

PragmaMSPointersToMembersKind FromPasta(pasta::PragmaMSPointersToMembersKind pasta_val);

inline static const char *EnumerationName(PragmaMSPointersToMembersKind) {
  return "PragmaMSPointersToMembersKind";
}

const char *EnumeratorName(PragmaMSPointersToMembersKind);

enum class PragmaMSStructKind : unsigned short {
  OFF,
  ON,
  NUM_ENUMERATORS
};

PragmaMSStructKind FromPasta(pasta::PragmaMSStructKind pasta_val);

inline static const char *EnumerationName(PragmaMSStructKind) {
  return "PragmaMSStructKind";
}

const char *EnumeratorName(PragmaMSStructKind);

enum class PragmaSectionFlag : unsigned short {
  NONE,
  READ,
  WRITE,
  EXECUTE,
  IMPLICIT,
  ZERO_INITIALIZER,
  INVALID,
  NUM_ENUMERATORS
};

PragmaSectionFlag FromPasta(pasta::PragmaSectionFlag pasta_val);

inline static const char *EnumerationName(PragmaSectionFlag) {
  return "PragmaSectionFlag";
}

const char *EnumeratorName(PragmaSectionFlag);

enum class ProfileInstrKind : unsigned short {
  PROFILE_NONE,
  PROFILE_CLANG_INSTR,
  PROFILE_IR_INSTR,
  PROFILE_CSIR_INSTR,
  NUM_ENUMERATORS
};

ProfileInstrKind FromPasta(pasta::ProfileInstrKind pasta_val);

inline static const char *EnumerationName(ProfileInstrKind) {
  return "ProfileInstrKind";
}

const char *EnumeratorName(ProfileInstrKind);

enum class RangeExprOffset : unsigned short {
  BEGIN,
  END,
  STEP,
  TOTAL,
  NUM_ENUMERATORS
};

RangeExprOffset FromPasta(pasta::RangeExprOffset pasta_val);

inline static const char *EnumerationName(RangeExprOffset) {
  return "RangeExprOffset";
}

const char *EnumeratorName(RangeExprOffset);

enum class RangeLocOffset : unsigned short {
  ASSIGN_TOKEN,
  SECOND_COLON_TOKEN,
  TOTAL,
  NUM_ENUMERATORS
};

RangeLocOffset FromPasta(pasta::RangeLocOffset pasta_val);

inline static const char *EnumerationName(RangeLocOffset) {
  return "RangeLocOffset";
}

const char *EnumeratorName(RangeLocOffset);

enum class RefQualifierKind : unsigned short {
  NONE,
  L_VALUE,
  R_VALUE,
  NUM_ENUMERATORS
};

RefQualifierKind FromPasta(pasta::RefQualifierKind pasta_val);

inline static const char *EnumerationName(RefQualifierKind) {
  return "RefQualifierKind";
}

const char *EnumeratorName(RefQualifierKind);

enum class RemarkKind : unsigned short {
  MISSING,
  ENABLED,
  ENABLED_EVERYTHING,
  DISABLED,
  DISABLED_EVERYTHING,
  WITH_PATTERN,
  NUM_ENUMERATORS
};

RemarkKind FromPasta(pasta::RemarkKind pasta_val);

inline static const char *EnumerationName(RemarkKind) {
  return "RemarkKind";
}

const char *EnumeratorName(RemarkKind);

enum class ReservedIdentifierStatus : unsigned short {
  NOT_RESERVED,
  STARTS_WITH_UNDERSCORE_AT_GLOBAL_SCOPE,
  STARTS_WITH_DOUBLE_UNDERSCORE,
  STARTS_WITH_UNDERSCORE_FOLLOWED_BY_CAPITAL_LETTER,
  CONTAINS_DOUBLE_UNDERSCORE,
  NUM_ENUMERATORS
};

ReservedIdentifierStatus FromPasta(pasta::ReservedIdentifierStatus pasta_val);

inline static const char *EnumerationName(ReservedIdentifierStatus) {
  return "ReservedIdentifierStatus";
}

const char *EnumeratorName(ReservedIdentifierStatus);

enum class SFINAEResponse : unsigned short {
  SUBSTITUTION_FAILURE,
  SUPPRESS,
  REPORT,
  ACCESS_CONTROL,
  NUM_ENUMERATORS
};

SFINAEResponse FromPasta(pasta::SFINAEResponse pasta_val);

inline static const char *EnumerationName(SFINAEResponse) {
  return "SFINAEResponse";
}

const char *EnumeratorName(SFINAEResponse);

enum class SYCLMajorVersion : unsigned short {
  VERSION_NONE,
  VERSION2017,
  VERSION2020,
  // Skipped repeat pasta::kDefault
  NUM_ENUMERATORS
};

SYCLMajorVersion FromPasta(pasta::SYCLMajorVersion pasta_val);

inline static const char *EnumerationName(SYCLMajorVersion) {
  return "SYCLMajorVersion";
}

const char *EnumeratorName(SYCLMajorVersion);

enum class SanitizerOrdinal : unsigned short {
  ADDRESS,
  POINTER_COMPARE,
  POINTER_SUBTRACT,
  KERNEL_ADDRESS,
  HW_ADDRESS,
  KERNEL_HW_ADDRESS,
  MEMORY_TAG,
  MEMORY,
  KERNEL_MEMORY,
  FUZZER,
  FUZZER_NO_LINK,
  THREAD,
  LEAK,
  ALIGNMENT,
  ARRAY_BOUNDS,
  BOOLEAN,
  BUILTIN,
  ENUM,
  FLOAT_CAST_OVERFLOW,
  FLOAT_DIVIDE_BY_ZERO,
  FUNCTION,
  INTEGER_DIVIDE_BY_ZERO,
  NONNULL_ATTRIBUTE,
  NULL__,
  NULLABILITY_ARGUMENT,
  NULLABILITY_ASSIGN,
  NULLABILITY_RETURN,
  NULLABILITY_GROUP,
  OBJECT_SIZE,
  POINTER_OVERFLOW,
  RETURN,
  RETURNS_NONNULL_ATTRIBUTE,
  SHIFT_BASE,
  SHIFT_EXPONENT,
  SHIFT_GROUP,
  SIGNED_INTEGER_OVERFLOW,
  UNREACHABLE,
  VLA_BOUND,
  VPTR,
  UNSIGNED_INTEGER_OVERFLOW,
  UNSIGNED_SHIFT_BASE,
  DATA_FLOW,
  CFI_CAST_STRICT,
  CFI_DERIVED_CAST,
  CFII_CALL,
  CFIMF_CALL,
  CFI_UNRELATED_CAST,
  CFINV_CALL,
  CFIV_CALL,
  CFI_GROUP,
  SAFE_STACK,
  SHADOW_CALL_STACK,
  UNDEFINED_GROUP,
  UNDEFINED_TRAP_GROUP,
  IMPLICIT_UNSIGNED_INTEGER_TRUNCATION,
  IMPLICIT_SIGNED_INTEGER_TRUNCATION,
  IMPLICIT_INTEGER_TRUNCATION_GROUP,
  IMPLICIT_INTEGER_SIGN_CHANGE,
  IMPLICIT_INTEGER_ARITHMETIC_VALUE_CHANGE_GROUP,
  OBJ_C_CAST,
  IMPLICIT_CONVERSION_GROUP,
  INTEGER_GROUP,
  LOCAL_BOUNDS,
  BOUNDS_GROUP,
  SCUDO,
  ALL_GROUP,
  COUNT,
  NUM_ENUMERATORS
};

SanitizerOrdinal FromPasta(pasta::SanitizerOrdinal pasta_val);

inline static const char *EnumerationName(SanitizerOrdinal) {
  return "SanitizerOrdinal";
}

const char *EnumeratorName(SanitizerOrdinal);

enum class SelectorLocationsKind : unsigned short {
  NON_STANDARD,
  STANDARD_NO_SPACE,
  STANDARD_WITH_SPACE,
  NUM_ENUMERATORS
};

SelectorLocationsKind FromPasta(pasta::SelectorLocationsKind pasta_val);

inline static const char *EnumerationName(SelectorLocationsKind) {
  return "SelectorLocationsKind";
}

const char *EnumeratorName(SelectorLocationsKind);

enum class SignReturnAddressKeyKind : unsigned short {
  A_KEY,
  B_KEY,
  NUM_ENUMERATORS
};

SignReturnAddressKeyKind FromPasta(pasta::SignReturnAddressKeyKind pasta_val);

inline static const char *EnumerationName(SignReturnAddressKeyKind) {
  return "SignReturnAddressKeyKind";
}

const char *EnumeratorName(SignReturnAddressKeyKind);

enum class SignReturnAddressScopeKind : unsigned short {
  NONE,
  NON_LEAF,
  ALL,
  NUM_ENUMERATORS
};

SignReturnAddressScopeKind FromPasta(pasta::SignReturnAddressScopeKind pasta_val);

inline static const char *EnumerationName(SignReturnAddressScopeKind) {
  return "SignReturnAddressScopeKind";
}

const char *EnumeratorName(SignReturnAddressScopeKind);

enum class SignedOverflowBehaviorTy : unsigned short {
  UNDEFINED,
  DEFINED,
  TRAPPING,
  NUM_ENUMERATORS
};

SignedOverflowBehaviorTy FromPasta(pasta::SignedOverflowBehaviorTy pasta_val);

inline static const char *EnumerationName(SignedOverflowBehaviorTy) {
  return "SignedOverflowBehaviorTy";
}

const char *EnumeratorName(SignedOverflowBehaviorTy);

enum class SpecialMemberFlags : unsigned short {
  DEFAULT_CONSTRUCTOR,
  COPY_CONSTRUCTOR,
  MOVE_CONSTRUCTOR,
  COPY_ASSIGNMENT,
  MOVE_ASSIGNMENT,
  DESTRUCTOR,
  ALL,
  NUM_ENUMERATORS
};

SpecialMemberFlags FromPasta(pasta::SpecialMemberFlags pasta_val);

inline static const char *EnumerationName(SpecialMemberFlags) {
  return "SpecialMemberFlags";
}

const char *EnumeratorName(SpecialMemberFlags);

enum class SpecifierKind : unsigned short {
  IDENTIFIER,
  NAMESPACE,
  NAMESPACE_ALIAS,
  TYPE_SPEC,
  TYPE_SPEC_WITH_TEMPLATE,
  GLOBAL,
  SUPER,
  NUM_ENUMERATORS
};

SpecifierKind FromPasta(pasta::SpecifierKind pasta_val);

inline static const char *EnumerationName(SpecifierKind) {
  return "SpecifierKind";
}

const char *EnumeratorName(SpecifierKind);

enum class Spelling : unsigned short {
  GNU_AARCH64_VECTOR_PCS,
  CXX11_CLANG_AARCH64_VECTOR_PCS,
  C2_XCLANG_AARCH64_VECTOR_PCS,
  SPELLING_NOT_CALCULATED,
  NUM_ENUMERATORS
};

Spelling FromPasta(pasta::Spelling pasta_val);

inline static const char *EnumerationName(Spelling) {
  return "Spelling";
}

const char *EnumeratorName(Spelling);

enum class StackProtectorMode : unsigned short {
  OFF,
  ON,
  STRONG,
  REQ,
  NUM_ENUMERATORS
};

StackProtectorMode FromPasta(pasta::StackProtectorMode pasta_val);

inline static const char *EnumerationName(StackProtectorMode) {
  return "StackProtectorMode";
}

const char *EnumeratorName(StackProtectorMode);

enum class StorageClass : unsigned short {
  NONE,
  EXTERN,
  STATIC,
  PRIVATE_EXTERN,
  AUTO,
  REGISTER,
  NUM_ENUMERATORS
};

StorageClass FromPasta(pasta::StorageClass pasta_val);

inline static const char *EnumerationName(StorageClass) {
  return "StorageClass";
}

const char *EnumeratorName(StorageClass);

enum class StorageDuration : unsigned short {
  FULL_EXPRESSION,
  AUTOMATIC,
  THREAD,
  STATIC,
  DYNAMIC,
  NUM_ENUMERATORS
};

StorageDuration FromPasta(pasta::StorageDuration pasta_val);

inline static const char *EnumerationName(StorageDuration) {
  return "StorageDuration";
}

const char *EnumeratorName(StorageDuration);

enum class StoredNameKind : unsigned short {
  STORED_IDENTIFIER,
  STORED_OBJ_C_ZERO_ARGUMENT_SELECTOR,
  STORED_OBJ_C_ONE_ARGUMENT_SELECTOR,
  STORED_CXX_CONSTRUCTOR_NAME,
  STORED_CXX_DESTRUCTOR_NAME,
  STORED_CXX_CONVERSION_FUNCTION_NAME,
  STORED_CXX_OPERATOR_NAME,
  STORED_DECLARATION_NAME_EXTRA,
  // Skipped repeat pasta::kPointerMask
  UNCOMMON_NAME_KIND_OFFSET,
  NUM_ENUMERATORS
};

StoredNameKind FromPasta(pasta::StoredNameKind pasta_val);

inline static const char *EnumerationName(StoredNameKind) {
  return "StoredNameKind";
}

const char *EnumeratorName(StoredNameKind);

enum class StoredSpecifierKind : unsigned short {
  STORED_IDENTIFIER,
  STORED_DECLARATION,
  STORED_TYPE_SPEC,
  STORED_TYPE_SPEC_WITH_TEMPLATE,
  NUM_ENUMERATORS
};

StoredSpecifierKind FromPasta(pasta::StoredSpecifierKind pasta_val);

inline static const char *EnumerationName(StoredSpecifierKind) {
  return "StoredSpecifierKind";
}

const char *EnumeratorName(StoredSpecifierKind);

enum class StructReturnConventionKind : unsigned short {
  DEFAULT,
  ON_STACK,
  IN_REGS,
  NUM_ENUMERATORS
};

StructReturnConventionKind FromPasta(pasta::StructReturnConventionKind pasta_val);

inline static const char *EnumerationName(StructReturnConventionKind) {
  return "StructReturnConventionKind";
}

const char *EnumeratorName(StructReturnConventionKind);

enum class SubExpr : unsigned short {
  CALLEE,
  LHS,
  RHS,
  COUNT,
  NUM_ENUMERATORS
};

SubExpr FromPasta(pasta::SubExpr pasta_val);

inline static const char *EnumerationName(SubExpr) {
  return "SubExpr";
}

const char *EnumeratorName(SubExpr);

enum class SubStmt : unsigned short {
  BODY,
  PROMISE,
  INITIALIZER_SUSPEND,
  FINAL_SUSPEND,
  ON_EXCEPTION,
  ON_FALLTHROUGH,
  ALLOCATE,
  DEALLOCATE,
  RETURN_VALUE,
  RESULT_DECLARATION,
  RETURN_STATEMENT,
  RETURN_STATEMENT_ON_ALLOC_FAILURE,
  NUM_ENUMERATORS
};

SubStmt FromPasta(pasta::SubStmt pasta_val);

inline static const char *EnumerationName(SubStmt) {
  return "SubStmt";
}

const char *EnumeratorName(SubStmt);

enum class SyncScope : unsigned short {
  OPEN_CL_WORK_GROUP,
  OPEN_CL_DEVICE,
  OPEN_CL_ALL_SVM_DEVICES,
  OPEN_CL_SUB_GROUP,
  NUM_ENUMERATORS
};

SyncScope FromPasta(pasta::SyncScope pasta_val);

inline static const char *EnumerationName(SyncScope) {
  return "SyncScope";
}

const char *EnumeratorName(SyncScope);

enum class Syntax : unsigned short {
  GNU,
  CXX11,
  C2_X,
  DECLSPEC,
  MICROSOFT,
  KEYWORD,
  PRAGMA,
  CONTEXT_SENSITIVE_KEYWORD,
  NUM_ENUMERATORS
};

Syntax FromPasta(pasta::Syntax pasta_val);

inline static const char *EnumerationName(Syntax) {
  return "Syntax";
}

const char *EnumeratorName(Syntax);

enum class TLSModel : unsigned short {
  GENERAL_DYNAMIC_TLS_MODEL,
  LOCAL_DYNAMIC_TLS_MODEL,
  INITIAL_EXEC_TLS_MODEL,
  LOCAL_EXEC_TLS_MODEL,
  NUM_ENUMERATORS
};

TLSModel FromPasta(pasta::TLSModel pasta_val);

inline static const char *EnumerationName(TLSModel) {
  return "TLSModel";
}

const char *EnumeratorName(TLSModel);

enum class TQ : unsigned short {
  CONST,
  RESTRICT,
  VOLATILE,
  CVR_MASK,
  NUM_ENUMERATORS
};

TQ FromPasta(pasta::TQ pasta_val);

inline static const char *EnumerationName(TQ) {
  return "TQ";
}

const char *EnumeratorName(TQ);

enum class TagTypeKind : unsigned short {
  STRUCT,
  INTERFACE,
  UNION,
  CLASS,
  ENUM,
  NUM_ENUMERATORS
};

TagTypeKind FromPasta(pasta::TagTypeKind pasta_val);

inline static const char *EnumerationName(TagTypeKind) {
  return "TagTypeKind";
}

const char *EnumeratorName(TagTypeKind);

enum class TailPaddingUseRules : unsigned short {
  ALWAYS_USE_TAIL_PADDING,
  USE_TAIL_PADDING_UNLESS_POD03,
  USE_TAIL_PADDING_UNLESS_POD11,
  NUM_ENUMERATORS
};

TailPaddingUseRules FromPasta(pasta::TailPaddingUseRules pasta_val);

inline static const char *EnumerationName(TailPaddingUseRules) {
  return "TailPaddingUseRules";
}

const char *EnumeratorName(TailPaddingUseRules);

enum class TemplateArgumentDependence : unsigned short {
  UNEXPANDED_PACK,
  INSTANTIATION,
  DEPENDENT,
  ERROR,
  NONE,
  DEPENDENT_INSTANTIATION,
  ALL,
  NUM_ENUMERATORS
};

TemplateArgumentDependence FromPasta(pasta::TemplateArgumentDependence pasta_val);

inline static const char *EnumerationName(TemplateArgumentDependence) {
  return "TemplateArgumentDependence";
}

const char *EnumeratorName(TemplateArgumentDependence);

enum class TemplateNameDependence : unsigned short {
  UNEXPANDED_PACK,
  INSTANTIATION,
  DEPENDENT,
  ERROR,
  NONE,
  DEPENDENT_INSTANTIATION,
  ALL,
  NUM_ENUMERATORS
};

TemplateNameDependence FromPasta(pasta::TemplateNameDependence pasta_val);

inline static const char *EnumerationName(TemplateNameDependence) {
  return "TemplateNameDependence";
}

const char *EnumeratorName(TemplateNameDependence);

enum class TemplateSpecializationKind : unsigned short {
  UNDECLARED,
  IMPLICIT_INSTANTIATION,
  EXPLICIT_SPECIALIZATION,
  EXPLICIT_INSTANTIATION_DECLARATION,
  EXPLICIT_INSTANTIATION_DEFINITION,
  NUM_ENUMERATORS
};

TemplateSpecializationKind FromPasta(pasta::TemplateSpecializationKind pasta_val);

inline static const char *EnumerationName(TemplateSpecializationKind) {
  return "TemplateSpecializationKind";
}

const char *EnumeratorName(TemplateSpecializationKind);

enum class TextDiagnosticFormat : unsigned short {
  CLANG,
  MSVC,
  VI,
  NUM_ENUMERATORS
};

TextDiagnosticFormat FromPasta(pasta::TextDiagnosticFormat pasta_val);

inline static const char *EnumerationName(TextDiagnosticFormat) {
  return "TextDiagnosticFormat";
}

const char *EnumeratorName(TextDiagnosticFormat);

enum class ThreadModelKind : unsigned short {
  POSIX,
  SINGLE,
  NUM_ENUMERATORS
};

ThreadModelKind FromPasta(pasta::ThreadModelKind pasta_val);

inline static const char *EnumerationName(ThreadModelKind) {
  return "ThreadModelKind";
}

const char *EnumeratorName(ThreadModelKind);

enum class ThreadStorageClassSpecifier : unsigned short {
  UNSPECIFIED,
  __THREAD,
  THREAD_LOCAL,
  _THREAD_LOCAL,
  NUM_ENUMERATORS
};

ThreadStorageClassSpecifier FromPasta(pasta::ThreadStorageClassSpecifier pasta_val);

inline static const char *EnumerationName(ThreadStorageClassSpecifier) {
  return "ThreadStorageClassSpecifier";
}

const char *EnumeratorName(ThreadStorageClassSpecifier);

enum class TokenKind : unsigned short {
  UNKNOWN,
  END_OF_FILE,
  END_OF_DIRECTIVE,
  CODE_COMPLETION,
  COMMENT,
  IDENTIFIER,
  WHITESPACE,
  NUMERIC_CONSTANT,
  CHARACTER_CONSTANT,
  WIDE_CHARACTER_CONSTANT,
  UTF8_CHARACTER_CONSTANT,
  UTF16_CHARACTER_CONSTANT,
  UTF32_CHARACTER_CONSTANT,
  STRING_LITERAL,
  WIDE_STRING_LITERAL,
  HEADER_NAME,
  UTF8_STRING_LITERAL,
  UTF16_STRING_LITERAL,
  UTF32_STRING_LITERAL,
  L_SQUARE,
  R_SQUARE,
  L_PARENTHESIS,
  R_PARENTHESIS,
  L_BRACE,
  R_BRACE,
  PERIOD,
  ELLIPSIS,
  AMP,
  AMP_AMP,
  AMP_EQUAL,
  STAR,
  STAR_EQUAL,
  PLUS,
  PLUS_PLUS,
  PLUS_EQUAL,
  MINUS,
  ARROW,
  MINUS_MINUS,
  MINUS_EQUAL,
  TILDE,
  EXCLAIM,
  EXCLAIM_EQUAL,
  SLASH,
  SLASH_EQUAL,
  PERCENT,
  PERCENT_EQUAL,
  LESS,
  LESS_LESS,
  LESS_EQUAL,
  LESS_LESS_EQUAL,
  SPACESHIP,
  GREATER,
  GREATER_GREATER,
  GREATER_EQUAL,
  GREATER_GREATER_EQUAL,
  CARET,
  CARET_EQUAL,
  PIPE,
  PIPE_PIPE,
  PIPE_EQUAL,
  QUESTION,
  COLON,
  SEMI,
  EQUAL,
  EQUAL_EQUAL,
  COMMA,
  HASH,
  HASH_HASH,
  HASHAT,
  PERIOD_STAR,
  ARROW_STAR,
  COLON_COLON,
  AT,
  LESS_LESS_LESS,
  GREATER_GREATER_GREATER,
  CARETCARET,
  KEYWORD_AUTO,
  KEYWORD_BREAK,
  KEYWORD_CASE,
  KEYWORD_CHARACTER,
  KEYWORD_CONST,
  KEYWORD_CONTINUE,
  KEYWORD_DEFAULT,
  KEYWORD_DO,
  KEYWORD_DOUBLE,
  KEYWORD_ELSE,
  KEYWORD_ENUM,
  KEYWORD_EXTERN,
  KEYWORD_FLOAT,
  KEYWORD_FOR,
  KEYWORD_GOTO,
  KEYWORD_IF,
  KEYWORD_INLINE,
  KEYWORD_INT,
  KEYWORD__EXT_INT,
  KEYWORD_LONG,
  KEYWORD_REGISTER,
  KEYWORD_RESTRICT,
  KEYWORD_RETURN,
  KEYWORD_SHORT,
  KEYWORD_SIGNED,
  KEYWORD_SIZEOF,
  KEYWORD_STATIC,
  KEYWORD_STRUCT,
  KEYWORD_SWITCH,
  KEYWORD_TYPEDEF,
  KEYWORD_UNION,
  KEYWORD_UNSIGNED,
  KEYWORD_VOID,
  KEYWORD_VOLATILE,
  KEYWORD_WHILE,
  KEYWORD__ALIGNAS,
  KEYWORD__ALIGNOF,
  KEYWORD__ATOMIC,
  KEYWORD__BOOLEAN,
  KEYWORD__COMPLEX,
  KEYWORD__GENERIC,
  KEYWORD__IMAGINARY,
  KEYWORD__NORETURN,
  KEYWORD__STATIC_ASSERT,
  KEYWORD__THREAD_LOCAL,
  KEYWORD___FUNC__,
  KEYWORD___OBJC_YES,
  KEYWORD___OBJC_NO,
  KEYWORD_ASSEMBLY,
  KEYWORD_BOOLEAN,
  KEYWORD_CATCH,
  KEYWORD_CLASS,
  KEYWORD_CONST_CAST,
  KEYWORD_DELETE,
  KEYWORD_DYNAMIC_CAST,
  KEYWORD_EXPLICIT,
  KEYWORD_EXPORT,
  KEYWORD_FALSE,
  KEYWORD_FRIEND,
  KEYWORD_MUTABLE,
  KEYWORD_NAMESPACE,
  KEYWORD_NEW,
  KEYWORD_OPERATOR,
  KEYWORD_PRIVATE,
  KEYWORD_PROTECTED,
  KEYWORD_PUBLIC,
  KEYWORD_REINTERPRET_CAST,
  KEYWORD_STATIC_CAST,
  KEYWORD_TEMPLATE,
  KEYWORD_THIS,
  KEYWORD_THROW,
  KEYWORD_TRUE,
  KEYWORD_TRY,
  KEYWORD_TYPENAME,
  KEYWORD_TYPEID,
  KEYWORD_USING,
  KEYWORD_VIRTUAL,
  KEYWORD_WCHAR_T,
  KEYWORD_ALIGNAS,
  KEYWORD_ALIGNOF,
  KEYWORD_CHAR16_T,
  KEYWORD_CHAR32_T,
  KEYWORD_CONSTEXPR,
  KEYWORD_DECLTYPE,
  KEYWORD_NOEXCEPT,
  KEYWORD_NULLPTR,
  KEYWORD_STATIC_ASSERT,
  KEYWORD_THREAD_LOCAL,
  KEYWORD_CONCEPT,
  KEYWORD_REQUIRES,
  KEYWORD_CO_AWAIT,
  KEYWORD_CO_RETURN,
  KEYWORD_CO_YIELD,
  KEYWORD_MODULE,
  KEYWORD_IMPORT,
  KEYWORD_CONSTEVAL,
  KEYWORD_CONSTINIT,
  KEYWORD_CHAR8_T,
  KEYWORD__FLOAT16,
  KEYWORD__ACCUM,
  KEYWORD__FRACT,
  KEYWORD__SAT,
  KEYWORD__DECIMAL32,
  KEYWORD__DECIMAL64,
  KEYWORD__DECIMAL128,
  KEYWORD___NULL,
  KEYWORD___ALIGNOF,
  KEYWORD___ATTRIBUTE,
  KEYWORD___BUILTIN_CHOOSE_EXPRESSION,
  KEYWORD___BUILTIN_OFFSETOF,
  KEYWORD___BUILTIN_FILE,
  KEYWORD___BUILTIN_FUNCTION,
  KEYWORD___BUILTIN_LINE,
  KEYWORD___BUILTIN_COLUMN,
  KEYWORD___BUILTIN_TYPES_COMPATIBLE_P,
  KEYWORD___BUILTIN_VA_ARGUMENT,
  KEYWORD___EXTENSION__,
  KEYWORD___FLOAT128,
  KEYWORD___IMAG,
  KEYWORD___INT128,
  KEYWORD___LABEL__,
  KEYWORD___REAL,
  KEYWORD___THREAD,
  KEYWORD___FUNCTION__,
  KEYWORD___PRETTYFUNCTION__,
  KEYWORD___AUTO_TYPE,
  KEYWORD_TYPEOF,
  KEYWORD___FUNCDNAME__,
  KEYWORD___FUNCSIG__,
  KEYWORD_LFUNCTION__,
  KEYWORD_LFUNCSIG__,
  KEYWORD___IS_INTERFACE_CLASS,
  KEYWORD___IS_SEALED,
  KEYWORD___IS_DESTRUCTIBLE,
  KEYWORD___IS_TRIVIALLY_DESTRUCTIBLE,
  KEYWORD___IS_NOTHROW_DESTRUCTIBLE,
  KEYWORD___IS_NOTHROW_ASSIGNABLE,
  KEYWORD___IS_CONSTRUCTIBLE,
  KEYWORD___IS_NOTHROW_CONSTRUCTIBLE,
  KEYWORD___IS_ASSIGNABLE,
  KEYWORD___HAS_NOTHROW_MOVE_ASSIGN,
  KEYWORD___HAS_TRIVIAL_MOVE_ASSIGN,
  KEYWORD___HAS_TRIVIAL_MOVE_CONSTRUCTOR,
  KEYWORD___HAS_NOTHROW_ASSIGN,
  KEYWORD___HAS_NOTHROW_COPY,
  KEYWORD___HAS_NOTHROW_CONSTRUCTOR,
  KEYWORD___HAS_TRIVIAL_ASSIGN,
  KEYWORD___HAS_TRIVIAL_COPY,
  KEYWORD___HAS_TRIVIAL_CONSTRUCTOR,
  KEYWORD___HAS_TRIVIAL_DESTRUCTOR,
  KEYWORD___HAS_VIRTUAL_DESTRUCTOR,
  KEYWORD___IS_ABSTRACT,
  KEYWORD___IS_AGGREGATE,
  KEYWORD___IS_BASE_OF,
  KEYWORD___IS_CLASS,
  KEYWORD___IS_CONVERTIBLE_TO,
  KEYWORD___IS_EMPTY,
  KEYWORD___IS_ENUM,
  KEYWORD___IS_FINAL,
  KEYWORD___IS_LITERAL,
  KEYWORD___IS_POD,
  KEYWORD___IS_POLYMORPHIC,
  KEYWORD___IS_STANDARD_LAYOUT,
  KEYWORD___IS_TRIVIAL,
  KEYWORD___IS_TRIVIALLY_ASSIGNABLE,
  KEYWORD___IS_TRIVIALLY_CONSTRUCTIBLE,
  KEYWORD___IS_TRIVIALLY_COPYABLE,
  KEYWORD___IS_UNION,
  KEYWORD___HAS_UNIQUE_OBJECT_REPRESENTATIONS,
  KEYWORD___UNDERLYING_TYPE,
  KEYWORD___REFERENCE_BINDS_TO_TEMPORARY,
  KEYWORD___IS_LVALUE_EXPRESSION,
  KEYWORD___IS_RVALUE_EXPRESSION,
  KEYWORD___IS_ARITHMETIC,
  KEYWORD___IS_FLOATING_POINT,
  KEYWORD___IS_INTEGRAL,
  KEYWORD___IS_COMPLETE_TYPE,
  KEYWORD___IS_VOID,
  KEYWORD___IS_ARRAY,
  KEYWORD___IS_FUNCTION,
  KEYWORD___IS_REFERENCE,
  KEYWORD___IS_LVALUE_REFERENCE,
  KEYWORD___IS_RVALUE_REFERENCE,
  KEYWORD___IS_FUNDAMENTAL,
  KEYWORD___IS_OBJECT,
  KEYWORD___IS_SCALAR,
  KEYWORD___IS_COMPOUND,
  KEYWORD___IS_POINTER,
  KEYWORD___IS_MEMBER_OBJECT_POINTER,
  KEYWORD___IS_MEMBER_FUNCTION_POINTER,
  KEYWORD___IS_MEMBER_POINTER,
  KEYWORD___IS_CONST,
  KEYWORD___IS_VOLATILE,
  KEYWORD___IS_SIGNED,
  KEYWORD___IS_UNSIGNED,
  KEYWORD___IS_SAME,
  KEYWORD___IS_CONVERTIBLE,
  KEYWORD___ARRAY_RANK,
  KEYWORD___ARRAY_EXTENT,
  KEYWORD___PRIVATE_EXTERN__,
  KEYWORD___MODULE_PRIVATE__,
  KEYWORD___DECLSPEC,
  KEYWORD___CDECL,
  KEYWORD___STDCALL,
  KEYWORD___FASTCALL,
  KEYWORD___THISCALL,
  KEYWORD___REGCALL,
  KEYWORD___VECTORCALL,
  KEYWORD___FORCEINLINE,
  KEYWORD___UNALIGNED,
  KEYWORD___SUPER,
  KEYWORD___GLOBAL,
  KEYWORD___LOCAL,
  KEYWORD___CONSTANT,
  KEYWORD___PRIVATE,
  KEYWORD___GENERIC,
  KEYWORD___KERNEL,
  KEYWORD___READ_ONLY,
  KEYWORD___WRITE_ONLY,
  KEYWORD___READ_WRITE,
  KEYWORD___BUILTIN_ASTYPE,
  KEYWORD_VEC_STEP,
  KEYWORD_IMAGE1_DT,
  KEYWORD_IMAGE1_DARRAY_T,
  KEYWORD_IMAGE1_DBUFFER_T,
  KEYWORD_IMAGE2_DT,
  KEYWORD_IMAGE2_DARRAY_T,
  KEYWORD_IMAGE2_DDEPTH_T,
  KEYWORD_IMAGE2_DARRAY_DEPTH_T,
  KEYWORD_IMAGE2_DMSAA_T,
  KEYWORD_IMAGE2_DARRAY_MSAA_T,
  KEYWORD_IMAGE2_DMSAA_DEPTH_T,
  KEYWORD_IMAGE2_DARRAY_MSAA_DEPTH_T,
  KEYWORD_IMAGE3_DT,
  KEYWORD_PIPE,
  KEYWORD_ADDRSPACE_CAST,
  KEYWORD___BUILTIN_OMP_REQUIRED_SIMD_ALIGN,
  KEYWORD___PASCAL,
  KEYWORD___VECTOR,
  KEYWORD___PIXEL,
  KEYWORD___BOOLEAN,
  KEYWORD___BF16,
  KEYWORD_HALF,
  KEYWORD___BRIDGE,
  KEYWORD___BRIDGE_TRANSFER,
  KEYWORD___BRIDGE_RETAINED,
  KEYWORD___BRIDGE_RETAIN,
  KEYWORD___COVARIANT,
  KEYWORD___CONTRAVARIANT,
  KEYWORD___KINDOF,
  KEYWORD__NONNULL,
  KEYWORD__NULLABLE,
  KEYWORD__NULLABLE_RESULT,
  KEYWORD__NULL_UNSPECIFIED,
  KEYWORD___PTR64,
  KEYWORD___PTR32,
  KEYWORD___SPTR,
  KEYWORD___UPTR,
  KEYWORD___W64,
  KEYWORD___UUIDOF,
  KEYWORD___TRY,
  KEYWORD___FINALLY,
  KEYWORD___LEAVE,
  KEYWORD___INT64,
  KEYWORD___IF_EXISTS,
  KEYWORD___IF_NOT_EXISTS,
  KEYWORD___SINGLE_INHERITANCE,
  KEYWORD___MULTIPLE_INHERITANCE,
  KEYWORD___VIRTUAL_INHERITANCE,
  KEYWORD___INTERFACE,
  KEYWORD___BUILTIN_CONVERTVECTOR,
  KEYWORD___BUILTIN_BIT_CAST,
  KEYWORD___BUILTIN_AVAILABLE,
  KEYWORD___BUILTIN_SYCL_UNIQUE_STABLE_NAME,
  KEYWORD___UNKNOWN_ANYTYPE,
  ANNOT_CXXSCOPE,
  ANNOT_TYPENAME,
  ANNOT_TEMPLATE_ID,
  ANNOT_NON_TYPE,
  ANNOT_NON_TYPE_UNDECLARED,
  ANNOT_NON_TYPE_DEPENDENT,
  ANNOT_OVERLOAD,
  ANNOT_PRIMARY_EXPRESSION,
  ANNOT_DECLTYPE,
  ANNOT_PRAGMA_UNUSED,
  ANNOT_PRAGMA_VIS,
  ANNOT_PRAGMA_PACK,
  ANNOT_PRAGMA_PARSER_CRASH,
  ANNOT_PRAGMA_CAPTURED,
  ANNOT_PRAGMA_DUMP,
  ANNOT_PRAGMA_MSSTRUCT,
  ANNOT_PRAGMA_ALIGN,
  ANNOT_PRAGMA_WEAK,
  ANNOT_PRAGMA_WEAKALIAS,
  ANNOT_PRAGMA_REDEFINE_EXTNAME,
  ANNOT_PRAGMA_FP_CONTRACT,
  ANNOT_PRAGMA_FENV_ACCESS,
  ANNOT_PRAGMA_FENV_ROUND,
  ANNOT_PRAGMA_FLOAT_CONTROL,
  ANNOT_PRAGMA_MS_POINTERS_TO_MEMBERS,
  ANNOT_PRAGMA_MS_VTORDISP,
  ANNOT_PRAGMA_MS_PRAGMA,
  ANNOT_PRAGMA_OPENCL_EXTENSION,
  ANNOT_ATTRIBUTE_OPENMP,
  ANNOT_PRAGMA_OPENMP,
  ANNOT_PRAGMA_OPENMP_END,
  ANNOT_PRAGMA_LOOP_HINT,
  ANNOT_PRAGMA_FP,
  ANNOT_PRAGMA_ATTRIBUTE,
  ANNOT_MODULE_INCLUDE,
  ANNOT_MODULE_BEGIN,
  ANNOT_MODULE_END,
  ANNOT_HEADER_UNIT,
  PP_IF,
  PP_IFDEF,
  PP_IFNDEF,
  PP_ELIF,
  PP_ELIFDEF,
  PP_ELIFNDEF,
  PP_ELSE,
  PP_ENDIF,
  PP_DEFINED,
  PP_INCLUDE,
  PP___INCLUDE_MACROS,
  PP_DEFINE,
  PP_UNDEF,
  PP_LINE,
  PP_ERROR,
  PP_PRAGMA,
  PP_IMPORT,
  PP_INCLUDE_NEXT,
  PP_WARNING,
  PP_IDENTIFIER,
  PP_SCCS,
  PP_ASSERT,
  PP_UNASSERT,
  PP___PUBLIC_MACRO,
  PP___PRIVATE_MACRO,
  OBJC_AT_CLASS,
  OBJC_AT_COMPATIBILITY_ALIAS,
  OBJC_AT_DEFINITIONS,
  OBJC_AT_ENCODE,
  OBJC_AT_OBJC_END,
  OBJC_AT_IMPLEMENTATION,
  OBJC_AT_INTERFACE,
  OBJC_AT_PRIVATE,
  OBJC_AT_PROTECTED,
  OBJC_AT_PROTOCOL,
  OBJC_AT_PUBLIC,
  OBJC_AT_SELECTOR,
  OBJC_AT_THROW,
  OBJC_AT_TRY,
  OBJC_AT_CATCH,
  OBJC_AT_FINALLY,
  OBJC_AT_SYNCHRONIZED,
  OBJC_AT_AUTORELEASEPOOL,
  OBJC_AT_PROPERTY,
  OBJC_AT_PACKAGE,
  OBJC_AT_REQUIRED,
  OBJC_AT_OPTIONAL,
  OBJC_AT_SYNTHESIZE,
  OBJC_AT_DYNAMIC,
  OBJC_AT_IMPORT,
  OBJC_AT_AVAILABLE,
  NUM_ENUMERATORS
};

TokenKind FromPasta(pasta::TokenKind pasta_val);

inline static const char *EnumerationName(TokenKind) {
  return "TokenKind";
}

const char *EnumeratorName(TokenKind);

enum class TrailingAllocKind : unsigned short {
  TAK_INHERITS_CONSTRUCTOR,
  TAK_HAS_TAIL_EXPLICIT,
  NUM_ENUMERATORS
};

TrailingAllocKind FromPasta(pasta::TrailingAllocKind pasta_val);

inline static const char *EnumerationName(TrailingAllocKind) {
  return "TrailingAllocKind";
}

const char *EnumeratorName(TrailingAllocKind);

enum class TranslationUnitKind : unsigned short {
  COMPLETE,
  PREFIX,
  MODULE,
  INCREMENTAL,
  NUM_ENUMERATORS
};

TranslationUnitKind FromPasta(pasta::TranslationUnitKind pasta_val);

inline static const char *EnumerationName(TranslationUnitKind) {
  return "TranslationUnitKind";
}

const char *EnumeratorName(TranslationUnitKind);

enum class TrivialAutoVarInitKind : unsigned short {
  UNINITIALIZED,
  ZERO,
  PATTERN,
  NUM_ENUMERATORS
};

TrivialAutoVarInitKind FromPasta(pasta::TrivialAutoVarInitKind pasta_val);

inline static const char *EnumerationName(TrivialAutoVarInitKind) {
  return "TrivialAutoVarInitKind";
}

const char *EnumeratorName(TrivialAutoVarInitKind);

enum class TypeDependence : unsigned short {
  UNEXPANDED_PACK,
  INSTANTIATION,
  DEPENDENT,
  VARIABLY_MODIFIED,
  ERROR,
  NONE,
  ALL,
  DEPENDENT_INSTANTIATION,
  NUM_ENUMERATORS
};

TypeDependence FromPasta(pasta::TypeDependence pasta_val);

inline static const char *EnumerationName(TypeDependence) {
  return "TypeDependence";
}

const char *EnumeratorName(TypeDependence);

enum class TypeLocClass : unsigned short {
  ADJUSTED,
  DECAYED,
  CONSTANT_ARRAY,
  DEPENDENT_SIZED_ARRAY,
  INCOMPLETE_ARRAY,
  VARIABLE_ARRAY,
  ATOMIC,
  ATTRIBUTED,
  BLOCK_POINTER,
  BUILTIN,
  COMPLEX,
  DECLTYPE,
  AUTO,
  DEDUCED_TEMPLATE_SPECIALIZATION,
  DEPENDENT_ADDRESS_SPACE,
  DEPENDENT_EXT_INT,
  DEPENDENT_NAME,
  DEPENDENT_SIZED_EXT_VECTOR,
  DEPENDENT_TEMPLATE_SPECIALIZATION,
  DEPENDENT_VECTOR,
  ELABORATED,
  EXT_INT,
  FUNCTION_NO_PROTO,
  FUNCTION_PROTO,
  INJECTED_CLASS_NAME,
  MACRO_QUALIFIED,
  CONSTANT_MATRIX,
  DEPENDENT_SIZED_MATRIX,
  MEMBER_POINTER,
  OBJ_C_OBJECT_POINTER,
  OBJ_C_OBJECT,
  OBJ_C_INTERFACE,
  OBJ_C_TYPE_PARAMETER,
  PACK_EXPANSION,
  PARENTHESIS,
  PIPE,
  POINTER,
  L_VALUE_REFERENCE,
  R_VALUE_REFERENCE,
  SUBST_TEMPLATE_TYPE_PARM_PACK,
  SUBST_TEMPLATE_TYPE_PARM,
  ENUM,
  RECORD,
  TEMPLATE_SPECIALIZATION,
  TEMPLATE_TYPE_PARM,
  TYPE_OF_EXPRESSION,
  TYPE_OF,
  TYPEDEF,
  UNARY_TRANSFORM,
  UNRESOLVED_USING,
  VECTOR,
  EXT_VECTOR,
  QUALIFIED,
  NUM_ENUMERATORS
};

TypeLocClass FromPasta(pasta::TypeLocClass pasta_val);

inline static const char *EnumerationName(TypeLocClass) {
  return "TypeLocClass";
}

const char *EnumeratorName(TypeLocClass);

enum class TypeSpecifierSign : unsigned short {
  UNSPECIFIED,
  SIGNED,
  UNSIGNED,
  NUM_ENUMERATORS
};

TypeSpecifierSign FromPasta(pasta::TypeSpecifierSign pasta_val);

inline static const char *EnumerationName(TypeSpecifierSign) {
  return "TypeSpecifierSign";
}

const char *EnumeratorName(TypeSpecifierSign);

enum class TypeSpecifierType : unsigned short {
  UNSPECIFIED,
  VOID,
  CHARACTER,
  WCHAR,
  CHAR8,
  CHAR16,
  CHAR32,
  INT,
  INT128,
  EXTINT,
  HALF,
  FLOAT16,
  ACCUM,
  FRACT,
  B_FLOAT16,
  FLOAT,
  DOUBLE,
  FLOAT128,
  BOOLEAN,
  DECIMAL32,
  DECIMAL64,
  DECIMAL128,
  ENUM,
  UNION,
  STRUCT,
  CLASS,
  INTERFACE,
  TYPENAME,
  TYPEOF_TYPE,
  TYPEOF_EXPRESSION,
  DECLTYPE,
  UNDERLYING_TYPE,
  AUTO,
  DECLTYPE_AUTO,
  AUTO_TYPE,
  UNKNOWN_ANYTYPE,
  ATOMIC,
  IMAGE1_DT,
  IMAGE1_DARRAY_T,
  IMAGE1_DBUFFER_T,
  IMAGE2_DT,
  IMAGE2_DARRAY_T,
  IMAGE2_DDEPTH_T,
  IMAGE2_DARRAY_DEPTH_T,
  IMAGE2_DMSAA_T,
  IMAGE2_DARRAY_MSAA_T,
  IMAGE2_DMSAA_DEPTH_T,
  IMAGE2_DARRAY_MSAA_DEPTH_T,
  IMAGE3_DT,
  ERROR,
  NUM_ENUMERATORS
};

TypeSpecifierType FromPasta(pasta::TypeSpecifierType pasta_val);

inline static const char *EnumerationName(TypeSpecifierType) {
  return "TypeSpecifierType";
}

const char *EnumeratorName(TypeSpecifierType);

enum class TypeSpecifierWidth : unsigned short {
  UNSPECIFIED,
  SHORT,
  LONG,
  LONG_LONG,
  NUM_ENUMERATORS
};

TypeSpecifierWidth FromPasta(pasta::TypeSpecifierWidth pasta_val);

inline static const char *EnumerationName(TypeSpecifierWidth) {
  return "TypeSpecifierWidth";
}

const char *EnumeratorName(TypeSpecifierWidth);

enum class TypeSpecifiersPipe : unsigned short {
  UNSPECIFIED,
  PIPE,
  NUM_ENUMERATORS
};

TypeSpecifiersPipe FromPasta(pasta::TypeSpecifiersPipe pasta_val);

inline static const char *EnumerationName(TypeSpecifiersPipe) {
  return "TypeSpecifiersPipe";
}

const char *EnumeratorName(TypeSpecifiersPipe);

enum class TypeTrait : unsigned short {
  IS_INTERFACE_CLASS,
  IS_SEALED,
  IS_DESTRUCTIBLE,
  IS_TRIVIALLY_DESTRUCTIBLE,
  IS_NOTHROW_DESTRUCTIBLE,
  HAS_NOTHROW_MOVE_ASSIGN,
  HAS_TRIVIAL_MOVE_ASSIGN,
  HAS_TRIVIAL_MOVE_CONSTRUCTOR,
  HAS_NOTHROW_ASSIGN,
  HAS_NOTHROW_COPY,
  HAS_NOTHROW_CONSTRUCTOR,
  HAS_TRIVIAL_ASSIGN,
  HAS_TRIVIAL_COPY,
  HAS_TRIVIAL_DEFAULT_CONSTRUCTOR,
  HAS_TRIVIAL_DESTRUCTOR,
  HAS_VIRTUAL_DESTRUCTOR,
  IS_ABSTRACT,
  IS_AGGREGATE,
  IS_CLASS,
  IS_EMPTY,
  IS_ENUM,
  IS_FINAL,
  IS_LITERAL,
  IS_POD,
  IS_POLYMORPHIC,
  IS_STANDARD_LAYOUT,
  IS_TRIVIAL,
  IS_TRIVIALLY_COPYABLE,
  IS_UNION,
  HAS_UNIQUE_OBJECT_REPRESENTATIONS,
  IS_ARITHMETIC,
  IS_FLOATING_POINT,
  IS_INTEGRAL,
  IS_COMPLETE_TYPE,
  IS_VOID,
  IS_ARRAY,
  IS_FUNCTION,
  IS_REFERENCE,
  IS_LVALUE_REFERENCE,
  IS_RVALUE_REFERENCE,
  IS_FUNDAMENTAL,
  IS_OBJECT,
  IS_SCALAR,
  IS_COMPOUND,
  IS_POINTER,
  IS_MEMBER_OBJECT_POINTER,
  IS_MEMBER_FUNCTION_POINTER,
  IS_MEMBER_POINTER,
  IS_CONST,
  IS_VOLATILE,
  IS_SIGNED,
  IS_UNSIGNED,
  TYPE_COMPATIBLE,
  IS_NOTHROW_ASSIGNABLE,
  IS_ASSIGNABLE,
  IS_BASE_OF,
  IS_CONVERTIBLE_TO,
  IS_TRIVIALLY_ASSIGNABLE,
  REFERENCE_BINDS_TO_TEMPORARY,
  IS_SAME,
  IS_CONVERTIBLE,
  IS_CONSTRUCTIBLE,
  IS_NOTHROW_CONSTRUCTIBLE,
  IS_TRIVIALLY_CONSTRUCTIBLE,
  NUM_ENUMERATORS
};

TypeTrait FromPasta(pasta::TypeTrait pasta_val);

inline static const char *EnumerationName(TypeTrait) {
  return "TypeTrait";
}

const char *EnumeratorName(TypeTrait);

enum class UnaryExprOrTypeTrait : unsigned short {
  SIZE_OF,
  ALIGN_OF,
  PREFERRED_ALIGN_OF,
  VEC_STEP,
  OPEN_MP_REQUIRED_SIMD_ALIGN,
  NUM_ENUMERATORS
};

UnaryExprOrTypeTrait FromPasta(pasta::UnaryExprOrTypeTrait pasta_val);

inline static const char *EnumerationName(UnaryExprOrTypeTrait) {
  return "UnaryExprOrTypeTrait";
}

const char *EnumeratorName(UnaryExprOrTypeTrait);

enum class UnaryOperatorKind : unsigned short {
  POST_INCREMENT,
  POST_DEC,
  PRE_INCREMENT,
  PRE_DEC,
  ADDR_OF,
  DEREF,
  PLUS,
  MINUS,
  NOT,
  L_NOT,
  REAL,
  IMAG,
  EXTENSION,
  COAWAIT,
  NUM_ENUMERATORS
};

UnaryOperatorKind FromPasta(pasta::UnaryOperatorKind pasta_val);

inline static const char *EnumerationName(UnaryOperatorKind) {
  return "UnaryOperatorKind";
}

const char *EnumeratorName(UnaryOperatorKind);

enum class APValueKind : unsigned short {
  NONE,
  INDETERMINATE,
  INT,
  FLOAT,
  FIXED_POINT,
  COMPLEX_INT,
  COMPLEX_FLOAT,
  L_VALUE,
  VECTOR,
  ARRAY,
  STRUCT,
  UNION,
  MEMBER_POINTER,
  ADDR_LABEL_DIFF,
  NUM_ENUMERATORS
};

APValueKind FromPasta(pasta::APValueKind pasta_val);

inline static const char *EnumerationName(APValueKind) {
  return "APValueKind";
}

const char *EnumeratorName(APValueKind);

enum class VectorLibrary : unsigned short {
  NO_LIBRARY,
  ACCELERATE,
  LIBMVEC,
  MASSV,
  SVML,
  DARWIN_LIBSYSTEM_M,
  NUM_ENUMERATORS
};

VectorLibrary FromPasta(pasta::VectorLibrary pasta_val);

inline static const char *EnumerationName(VectorLibrary) {
  return "VectorLibrary";
}

const char *EnumeratorName(VectorLibrary);

enum class Visibility : unsigned short {
  HIDDEN_VISIBILITY,
  PROTECTED_VISIBILITY,
  DEFAULT_VISIBILITY,
  NUM_ENUMERATORS
};

Visibility FromPasta(pasta::Visibility pasta_val);

inline static const char *EnumerationName(Visibility) {
  return "Visibility";
}

const char *EnumeratorName(Visibility);

enum class VisibilityType : unsigned short {
  DEFAULT,
  HIDDEN,
  PROTECTED,
  NUM_ENUMERATORS
};

VisibilityType FromPasta(pasta::VisibilityType pasta_val);

inline static const char *EnumerationName(VisibilityType) {
  return "VisibilityType";
}

const char *EnumeratorName(VisibilityType);

enum class PathKind : unsigned short {
  UNIX,
  WINDOWS,
  NUM_ENUMERATORS
};

PathKind FromPasta(pasta::PathKind pasta_val);

inline static const char *EnumerationName(PathKind) {
  return "PathKind";
}

const char *EnumeratorName(PathKind);

enum class FileType : unsigned short {
  NONE,
  NOT_FOUND,
  REGULAR,
  DIRECTORY,
  SYMBOLIC_LINK,
  BLOCK,
  CHARACTER,
  FIRST_IN_FIRST_OUT,
  SOCKET,
  KNKNOWN,
  NUM_ENUMERATORS
};

FileType FromPasta(pasta::FileType pasta_val);

inline static const char *EnumerationName(FileType) {
  return "FileType";
}

const char *EnumeratorName(FileType);

enum class CompilerName : unsigned short {
  UNKNOWN,
  CLANG,
  APPLE_CLANG,
  CLANG_CL,
  CL,
  GNU,
  NUM_ENUMERATORS
};

CompilerName FromPasta(pasta::CompilerName pasta_val);

inline static const char *EnumerationName(CompilerName) {
  return "CompilerName";
}

const char *EnumeratorName(CompilerName);

enum class IncludePathLocation : unsigned short {
  ABSOLUTE,
  SYSROOT_RELATIVE,
  NUM_ENUMERATORS
};

IncludePathLocation FromPasta(pasta::IncludePathLocation pasta_val);

inline static const char *EnumerationName(IncludePathLocation) {
  return "IncludePathLocation";
}

const char *EnumeratorName(IncludePathLocation);

enum class TargetLanguage : unsigned short {
  C,
  CXX,
  NUM_ENUMERATORS
};

TargetLanguage FromPasta(pasta::TargetLanguage pasta_val);

inline static const char *EnumerationName(TargetLanguage) {
  return "TargetLanguage";
}

const char *EnumeratorName(TargetLanguage);

class Token;
class TokenRange;
class CXXBaseSpecifier;
class TemplateArgument;
class TemplateParameterList;
class FileToken;
class Decl;
class EmptyDecl;
class ExportDecl;
class ExternCContextDecl;
class FileScopeAsmDecl;
class FriendDecl;
class FriendTemplateDecl;
class ImportDecl;
class LifetimeExtendedTemporaryDecl;
class LinkageSpecDecl;
class NamedDecl;
class NamespaceAliasDecl;
class NamespaceDecl;
class ObjCCompatibleAliasDecl;
class ObjCContainerDecl;
class ObjCImplDecl;
class ObjCImplementationDecl;
class ObjCInterfaceDecl;
class ObjCMethodDecl;
class ObjCPropertyDecl;
class ObjCPropertyImplDecl;
class ObjCProtocolDecl;
class PragmaCommentDecl;
class PragmaDetectMismatchDecl;
class RequiresExprBodyDecl;
class StaticAssertDecl;
class TemplateDecl;
class TemplateTemplateParmDecl;
class TranslationUnitDecl;
class TypeDecl;
class TypedefNameDecl;
class UnresolvedUsingIfExistsDecl;
class UnresolvedUsingTypenameDecl;
class UsingDirectiveDecl;
class UsingPackDecl;
class UsingShadowDecl;
class ValueDecl;
class OMPDeclarativeDirectiveDecl;
class OMPDeclarativeDirectiveValueDecl;
class AccessSpecDecl;
class BaseUsingDecl;
class BindingDecl;
class BlockDecl;
class BuiltinTemplateDecl;
class CapturedDecl;
class ClassScopeFunctionSpecializationDecl;
class ConceptDecl;
class ConstructorUsingShadowDecl;
class DeclaratorDecl;
class EnumConstantDecl;
class FieldDecl;
class FunctionDecl;
class IndirectFieldDecl;
class LabelDecl;
class MSGuidDecl;
class MSPropertyDecl;
class NonTypeTemplateParmDecl;
class OMPAllocateDecl;
class OMPDeclareMapperDecl;
class OMPDeclareReductionDecl;
class OMPRequiresDecl;
class OMPThreadPrivateDecl;
class ObjCAtDefsFieldDecl;
class ObjCCategoryDecl;
class ObjCCategoryImplDecl;
class ObjCIvarDecl;
class ObjCTypeParamDecl;
class RedeclarableTemplateDecl;
class TagDecl;
class TemplateParamObjectDecl;
class TemplateTypeParmDecl;
class TypeAliasDecl;
class TypeAliasTemplateDecl;
class TypedefDecl;
class UnresolvedUsingValueDecl;
class UsingDecl;
class UsingEnumDecl;
class VarDecl;
class VarTemplateDecl;
class VarTemplateSpecializationDecl;
class CXXDeductionGuideDecl;
class CXXMethodDecl;
class ClassTemplateDecl;
class DecompositionDecl;
class EnumDecl;
class FunctionTemplateDecl;
class ImplicitParamDecl;
class OMPCapturedExprDecl;
class ParmVarDecl;
class RecordDecl;
class VarTemplatePartialSpecializationDecl;
class CXXConstructorDecl;
class CXXConversionDecl;
class CXXDestructorDecl;
class CXXRecordDecl;
class ClassTemplateSpecializationDecl;
class ClassTemplatePartialSpecializationDecl;
class Stmt;
class SwitchCase;
class SwitchStmt;
class ValueStmt;
class WhileStmt;
class AsmStmt;
class AttributedStmt;
class BreakStmt;
class CXXCatchStmt;
class CXXForRangeStmt;
class CXXTryStmt;
class CapturedStmt;
class CaseStmt;
class CompoundStmt;
class ContinueStmt;
class CoreturnStmt;
class CoroutineBodyStmt;
class DeclStmt;
class DefaultStmt;
class DoStmt;
class Expr;
class ExpressionTraitExpr;
class ExtVectorElementExpr;
class FixedPointLiteral;
class FloatingLiteral;
class ForStmt;
class FullExpr;
class FunctionParmPackExpr;
class GCCAsmStmt;
class GNUNullExpr;
class GenericSelectionExpr;
class GotoStmt;
class IfStmt;
class ImaginaryLiteral;
class ImplicitValueInitExpr;
class IndirectGotoStmt;
class InitListExpr;
class IntegerLiteral;
class LabelStmt;
class LambdaExpr;
class MSAsmStmt;
class MSDependentExistsStmt;
class MSPropertyRefExpr;
class MSPropertySubscriptExpr;
class MaterializeTemporaryExpr;
class MatrixSubscriptExpr;
class MemberExpr;
class NoInitExpr;
class NullStmt;
class OMPArraySectionExpr;
class OMPArrayShapingExpr;
class OMPCanonicalLoop;
class OMPExecutableDirective;
class OMPFlushDirective;
class OMPInteropDirective;
class OMPIteratorExpr;
class OMPLoopBasedDirective;
class OMPLoopDirective;
class OMPMaskedDirective;
class OMPMasterDirective;
class OMPMasterTaskLoopDirective;
class OMPMasterTaskLoopSimdDirective;
class OMPOrderedDirective;
class OMPParallelDirective;
class OMPParallelForDirective;
class OMPParallelForSimdDirective;
class OMPParallelMasterDirective;
class OMPParallelMasterTaskLoopDirective;
class OMPParallelMasterTaskLoopSimdDirective;
class OMPParallelSectionsDirective;
class OMPScanDirective;
class OMPSectionDirective;
class OMPSectionsDirective;
class OMPSimdDirective;
class OMPSingleDirective;
class OMPTargetDataDirective;
class OMPTargetDirective;
class OMPTargetEnterDataDirective;
class OMPTargetExitDataDirective;
class OMPTargetParallelDirective;
class OMPTargetParallelForDirective;
class OMPTargetParallelForSimdDirective;
class OMPTargetSimdDirective;
class OMPTargetTeamsDirective;
class OMPTargetTeamsDistributeDirective;
class OMPTargetTeamsDistributeParallelForDirective;
class OMPTargetTeamsDistributeParallelForSimdDirective;
class OMPTargetTeamsDistributeSimdDirective;
class OMPTargetUpdateDirective;
class OMPTaskDirective;
class OMPTaskLoopDirective;
class OMPTaskLoopSimdDirective;
class OMPTaskgroupDirective;
class OMPTaskwaitDirective;
class OMPTaskyieldDirective;
class OMPTeamsDirective;
class OMPTeamsDistributeDirective;
class OMPTeamsDistributeParallelForDirective;
class OMPTeamsDistributeParallelForSimdDirective;
class OMPTeamsDistributeSimdDirective;
class OMPTileDirective;
class OMPUnrollDirective;
class ObjCArrayLiteral;
class ObjCAtCatchStmt;
class ObjCAtFinallyStmt;
class ObjCAtSynchronizedStmt;
class ObjCAtThrowStmt;
class ObjCAtTryStmt;
class ObjCAutoreleasePoolStmt;
class ObjCAvailabilityCheckExpr;
class ObjCBoolLiteralExpr;
class ObjCBoxedExpr;
class ObjCDictionaryLiteral;
class ObjCEncodeExpr;
class ObjCForCollectionStmt;
class ObjCIndirectCopyRestoreExpr;
class ObjCIsaExpr;
class ObjCIvarRefExpr;
class ObjCMessageExpr;
class ObjCPropertyRefExpr;
class ObjCProtocolExpr;
class ObjCSelectorExpr;
class ObjCStringLiteral;
class ObjCSubscriptRefExpr;
class OffsetOfExpr;
class OpaqueValueExpr;
class OverloadExpr;
class PackExpansionExpr;
class ParenExpr;
class ParenListExpr;
class PredefinedExpr;
class PseudoObjectExpr;
class RecoveryExpr;
class RequiresExpr;
class ReturnStmt;
class SEHExceptStmt;
class SEHFinallyStmt;
class SEHLeaveStmt;
class SEHTryStmt;
class SYCLUniqueStableNameExpr;
class ShuffleVectorExpr;
class SizeOfPackExpr;
class SourceLocExpr;
class StmtExpr;
class StringLiteral;
class SubstNonTypeTemplateParmExpr;
class SubstNonTypeTemplateParmPackExpr;
class TypeTraitExpr;
class TypoExpr;
class UnaryExprOrTypeTraitExpr;
class UnaryOperator;
class UnresolvedLookupExpr;
class UnresolvedMemberExpr;
class VAArgExpr;
class AbstractConditionalOperator;
class AddrLabelExpr;
class ArrayInitIndexExpr;
class ArrayInitLoopExpr;
class ArraySubscriptExpr;
class ArrayTypeTraitExpr;
class AsTypeExpr;
class AtomicExpr;
class BinaryConditionalOperator;
class BinaryOperator;
class BlockExpr;
class CXXBindTemporaryExpr;
class CXXBoolLiteralExpr;
class CXXConstructExpr;
class CXXDefaultArgExpr;
class CXXDefaultInitExpr;
class CXXDeleteExpr;
class CXXDependentScopeMemberExpr;
class CXXFoldExpr;
class CXXInheritedCtorInitExpr;
class CXXNewExpr;
class CXXNoexceptExpr;
class CXXNullPtrLiteralExpr;
class CXXPseudoDestructorExpr;
class CXXRewrittenBinaryOperator;
class CXXScalarValueInitExpr;
class CXXStdInitializerListExpr;
class CXXTemporaryObjectExpr;
class CXXThisExpr;
class CXXThrowExpr;
class CXXTypeidExpr;
class CXXUnresolvedConstructExpr;
class CXXUuidofExpr;
class CallExpr;
class CastExpr;
class CharacterLiteral;
class ChooseExpr;
class CompoundAssignOperator;
class CompoundLiteralExpr;
class ConceptSpecializationExpr;
class ConditionalOperator;
class ConstantExpr;
class ConvertVectorExpr;
class CoroutineSuspendExpr;
class CoyieldExpr;
class DeclRefExpr;
class DependentCoawaitExpr;
class DependentScopeDeclRefExpr;
class DesignatedInitExpr;
class DesignatedInitUpdateExpr;
class ExplicitCastExpr;
class ExprWithCleanups;
class ImplicitCastExpr;
class OMPAtomicDirective;
class OMPBarrierDirective;
class OMPCancelDirective;
class OMPCancellationPointDirective;
class OMPCriticalDirective;
class OMPDepobjDirective;
class OMPDispatchDirective;
class OMPDistributeDirective;
class OMPDistributeParallelForDirective;
class OMPDistributeParallelForSimdDirective;
class OMPDistributeSimdDirective;
class OMPForDirective;
class OMPForSimdDirective;
class ObjCBridgedCastExpr;
class UserDefinedLiteral;
class BuiltinBitCastExpr;
class CStyleCastExpr;
class CUDAKernelCallExpr;
class CXXFunctionalCastExpr;
class CXXMemberCallExpr;
class CXXNamedCastExpr;
class CXXOperatorCallExpr;
class CXXReinterpretCastExpr;
class CXXStaticCastExpr;
class CoawaitExpr;
class CXXAddrspaceCastExpr;
class CXXConstCastExpr;
class CXXDynamicCastExpr;
#ifndef MX_DISABLE_API
class TemplateParameterList {
 protected:
  friend class Decl;
  friend class DeclIterator;
  friend class FragmentImpl;
  friend class Stmt;
  friend class StmtIterator;
  friend class TokenContext;
  std::shared_ptr<const FragmentImpl> fragment;
  unsigned offset;

 public:
  inline TemplateParameterList(std::shared_ptr<const FragmentImpl> fragment_, unsigned offset_)
      : fragment(std::move(fragment_)),
        offset(offset_) {}

  unsigned num_parameters(void) const;
  unsigned num_required_parameters(void) const;
  unsigned depth(void) const;
  bool has_unexpanded_parameter_pack(void) const;
  bool has_parameter_pack(void) const;
  std::optional<Expr> requires_clause(void) const;
  Token template_keyword_token(void) const;
  Token left_angle_token(void) const;
  Token right_angle_token(void) const;
  TokenRange token_range(void) const;
  std::vector<NamedDecl> parameters(void) const;
};

class TemplateArgument {
 protected:
  friend class Decl;
  friend class DeclIterator;
  friend class FragmentImpl;
  friend class Stmt;
  friend class StmtIterator;
  friend class TokenContext;
  std::shared_ptr<const FragmentImpl> fragment;
  unsigned offset;

 public:
  inline TemplateArgument(std::shared_ptr<const FragmentImpl> fragment_, unsigned offset_)
      : fragment(std::move(fragment_)),
        offset(offset_) {}

  TemplateArgumentKind kind(void) const;
  bool is_null(void) const;
  bool is_dependent(void) const;
  bool is_instantiation_dependent(void) const;
  bool contains_unexpanded_parameter_pack(void) const;
  bool is_pack_expansion(void) const;
  std::optional<ValueDecl> as_declaration(void) const;
};

class CXXBaseSpecifier {
 protected:
  friend class Decl;
  friend class DeclIterator;
  friend class FragmentImpl;
  friend class Stmt;
  friend class StmtIterator;
  friend class TokenContext;
  std::shared_ptr<const FragmentImpl> fragment;
  unsigned offset;

 public:
  inline CXXBaseSpecifier(std::shared_ptr<const FragmentImpl> fragment_, unsigned offset_)
      : fragment(std::move(fragment_)),
        offset(offset_) {}

  TokenRange token_range(void) const;
  Token base_type_token(void) const;
  bool is_virtual(void) const;
  TagTypeKind base_kind(void) const;
  bool is_pack_expansion(void) const;
  bool constructors_are_inherited(void) const;
  std::optional<Token> ellipsis(void) const;
  AccessSpecifier semantic_access_specifier(void) const;
  AccessSpecifier lexical_access_specifier(void) const;
};

using StmtRange = DerivedEntityRange<StmtIterator, Stmt>;
using StmtContainingTokenRange = DerivedEntityRange<TokenContextIterator, Stmt>;
using StmtContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, Stmt>;

class Stmt {
 protected:
  friend class Decl;
  friend class DeclIterator;
  friend class FragmentImpl;
  friend class Stmt;
  friend class StmtIterator;
  friend class TokenContext;
  std::shared_ptr<const FragmentImpl> fragment;
  unsigned offset;

 public:
  inline Stmt(std::shared_ptr<const FragmentImpl> fragment_, unsigned offset_)
      : fragment(std::move(fragment_)),
        offset(offset_) {}

  inline static std::optional<Stmt> from(const Stmt &self) {
    return self;
  }

  inline static std::optional<Stmt> from(const TokenContext &c) {
    return c.as_stmt();
  }

  std::optional<Decl> parent_declaration(void) const;
  std::optional<Stmt> parent_statement(void) const;

 protected:
  static StmtIterator in_internal(const Fragment &fragment);

 public:
  inline static StmtRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static StmtContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static StmtContainingStmtRange containing(const Decl &decl);
  static StmtContainingStmtRange containing(const Stmt &stmt);

  Stmt ignore_containers(void) const;
  std::vector<Stmt> children(void) const;
  Token begin_token(void) const;
  Token end_token(void) const;
  TokenRange token_range(void) const;
  StmtKind kind(void) const;
  Stmt strip_label_like_statements(void) const;
};

using SEHTryStmtRange = DerivedEntityRange<StmtIterator, SEHTryStmt>;
using SEHTryStmtContainingTokenRange = DerivedEntityRange<TokenContextIterator, SEHTryStmt>;
using SEHTryStmtContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, SEHTryStmt>;

class SEHTryStmt : public Stmt {
 private:
  friend class FragmentImpl;
  friend class Stmt;
 public:
  inline static SEHTryStmtRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static SEHTryStmtContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static SEHTryStmtContainingStmtRange containing(const Decl &decl);
  static SEHTryStmtContainingStmtRange containing(const Stmt &stmt);

  static std::optional<SEHTryStmt> from(const TokenContext &c);
  static std::optional<SEHTryStmt> from(const Stmt &parent);
  SEHExceptStmt except_handler(void) const;
  SEHFinallyStmt finally_handler(void) const;
  Stmt handler(void) const;
  bool is_cxx_try(void) const;
  CompoundStmt try_block(void) const;
  Token try_token(void) const;
};

using SEHLeaveStmtRange = DerivedEntityRange<StmtIterator, SEHLeaveStmt>;
using SEHLeaveStmtContainingTokenRange = DerivedEntityRange<TokenContextIterator, SEHLeaveStmt>;
using SEHLeaveStmtContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, SEHLeaveStmt>;

class SEHLeaveStmt : public Stmt {
 private:
  friend class FragmentImpl;
  friend class Stmt;
 public:
  inline static SEHLeaveStmtRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static SEHLeaveStmtContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static SEHLeaveStmtContainingStmtRange containing(const Decl &decl);
  static SEHLeaveStmtContainingStmtRange containing(const Stmt &stmt);

  static std::optional<SEHLeaveStmt> from(const TokenContext &c);
  static std::optional<SEHLeaveStmt> from(const Stmt &parent);
  Token leave_token(void) const;
};

using SEHFinallyStmtRange = DerivedEntityRange<StmtIterator, SEHFinallyStmt>;
using SEHFinallyStmtContainingTokenRange = DerivedEntityRange<TokenContextIterator, SEHFinallyStmt>;
using SEHFinallyStmtContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, SEHFinallyStmt>;

class SEHFinallyStmt : public Stmt {
 private:
  friend class FragmentImpl;
  friend class Stmt;
 public:
  inline static SEHFinallyStmtRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static SEHFinallyStmtContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static SEHFinallyStmtContainingStmtRange containing(const Decl &decl);
  static SEHFinallyStmtContainingStmtRange containing(const Stmt &stmt);

  static std::optional<SEHFinallyStmt> from(const TokenContext &c);
  static std::optional<SEHFinallyStmt> from(const Stmt &parent);
  CompoundStmt block(void) const;
  Token finally_token(void) const;
};

using SEHExceptStmtRange = DerivedEntityRange<StmtIterator, SEHExceptStmt>;
using SEHExceptStmtContainingTokenRange = DerivedEntityRange<TokenContextIterator, SEHExceptStmt>;
using SEHExceptStmtContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, SEHExceptStmt>;

class SEHExceptStmt : public Stmt {
 private:
  friend class FragmentImpl;
  friend class Stmt;
 public:
  inline static SEHExceptStmtRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static SEHExceptStmtContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static SEHExceptStmtContainingStmtRange containing(const Decl &decl);
  static SEHExceptStmtContainingStmtRange containing(const Stmt &stmt);

  static std::optional<SEHExceptStmt> from(const TokenContext &c);
  static std::optional<SEHExceptStmt> from(const Stmt &parent);
  CompoundStmt block(void) const;
  Token except_token(void) const;
  Expr filter_expression(void) const;
};

using ReturnStmtRange = DerivedEntityRange<StmtIterator, ReturnStmt>;
using ReturnStmtContainingTokenRange = DerivedEntityRange<TokenContextIterator, ReturnStmt>;
using ReturnStmtContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, ReturnStmt>;

class ReturnStmt : public Stmt {
 private:
  friend class FragmentImpl;
  friend class Stmt;
 public:
  inline static ReturnStmtRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static ReturnStmtContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static ReturnStmtContainingStmtRange containing(const Decl &decl);
  static ReturnStmtContainingStmtRange containing(const Stmt &stmt);

  static std::optional<ReturnStmt> from(const TokenContext &c);
  static std::optional<ReturnStmt> from(const Stmt &parent);
  std::optional<VarDecl> nrvo_candidate(void) const;
  std::optional<Expr> return_value(void) const;
  Token return_token(void) const;
};

using ObjCForCollectionStmtRange = DerivedEntityRange<StmtIterator, ObjCForCollectionStmt>;
using ObjCForCollectionStmtContainingTokenRange = DerivedEntityRange<TokenContextIterator, ObjCForCollectionStmt>;
using ObjCForCollectionStmtContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, ObjCForCollectionStmt>;

class ObjCForCollectionStmt : public Stmt {
 private:
  friend class FragmentImpl;
  friend class Stmt;
 public:
  inline static ObjCForCollectionStmtRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static ObjCForCollectionStmtContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static ObjCForCollectionStmtContainingStmtRange containing(const Decl &decl);
  static ObjCForCollectionStmtContainingStmtRange containing(const Stmt &stmt);

  static std::optional<ObjCForCollectionStmt> from(const TokenContext &c);
  static std::optional<ObjCForCollectionStmt> from(const Stmt &parent);
  Stmt body(void) const;
  Expr collection(void) const;
  Stmt element(void) const;
  Token for_token(void) const;
  Token r_paren_token(void) const;
};

using ObjCAutoreleasePoolStmtRange = DerivedEntityRange<StmtIterator, ObjCAutoreleasePoolStmt>;
using ObjCAutoreleasePoolStmtContainingTokenRange = DerivedEntityRange<TokenContextIterator, ObjCAutoreleasePoolStmt>;
using ObjCAutoreleasePoolStmtContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, ObjCAutoreleasePoolStmt>;

class ObjCAutoreleasePoolStmt : public Stmt {
 private:
  friend class FragmentImpl;
  friend class Stmt;
 public:
  inline static ObjCAutoreleasePoolStmtRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static ObjCAutoreleasePoolStmtContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static ObjCAutoreleasePoolStmtContainingStmtRange containing(const Decl &decl);
  static ObjCAutoreleasePoolStmtContainingStmtRange containing(const Stmt &stmt);

  static std::optional<ObjCAutoreleasePoolStmt> from(const TokenContext &c);
  static std::optional<ObjCAutoreleasePoolStmt> from(const Stmt &parent);
  Token at_token(void) const;
  Stmt sub_statement(void) const;
};

using ObjCAtTryStmtRange = DerivedEntityRange<StmtIterator, ObjCAtTryStmt>;
using ObjCAtTryStmtContainingTokenRange = DerivedEntityRange<TokenContextIterator, ObjCAtTryStmt>;
using ObjCAtTryStmtContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, ObjCAtTryStmt>;

class ObjCAtTryStmt : public Stmt {
 private:
  friend class FragmentImpl;
  friend class Stmt;
 public:
  inline static ObjCAtTryStmtRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static ObjCAtTryStmtContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static ObjCAtTryStmtContainingStmtRange containing(const Decl &decl);
  static ObjCAtTryStmtContainingStmtRange containing(const Stmt &stmt);

  static std::optional<ObjCAtTryStmt> from(const TokenContext &c);
  static std::optional<ObjCAtTryStmt> from(const Stmt &parent);
  Token at_try_token(void) const;
  ObjCAtFinallyStmt finally_statement(void) const;
  Stmt try_body(void) const;
  std::vector<ObjCAtCatchStmt> catch_statements(void) const;
};

using ObjCAtThrowStmtRange = DerivedEntityRange<StmtIterator, ObjCAtThrowStmt>;
using ObjCAtThrowStmtContainingTokenRange = DerivedEntityRange<TokenContextIterator, ObjCAtThrowStmt>;
using ObjCAtThrowStmtContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, ObjCAtThrowStmt>;

class ObjCAtThrowStmt : public Stmt {
 private:
  friend class FragmentImpl;
  friend class Stmt;
 public:
  inline static ObjCAtThrowStmtRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static ObjCAtThrowStmtContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static ObjCAtThrowStmtContainingStmtRange containing(const Decl &decl);
  static ObjCAtThrowStmtContainingStmtRange containing(const Stmt &stmt);

  static std::optional<ObjCAtThrowStmt> from(const TokenContext &c);
  static std::optional<ObjCAtThrowStmt> from(const Stmt &parent);
  Expr throw_expression(void) const;
  Token throw_token(void) const;
};

using ObjCAtSynchronizedStmtRange = DerivedEntityRange<StmtIterator, ObjCAtSynchronizedStmt>;
using ObjCAtSynchronizedStmtContainingTokenRange = DerivedEntityRange<TokenContextIterator, ObjCAtSynchronizedStmt>;
using ObjCAtSynchronizedStmtContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, ObjCAtSynchronizedStmt>;

class ObjCAtSynchronizedStmt : public Stmt {
 private:
  friend class FragmentImpl;
  friend class Stmt;
 public:
  inline static ObjCAtSynchronizedStmtRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static ObjCAtSynchronizedStmtContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static ObjCAtSynchronizedStmtContainingStmtRange containing(const Decl &decl);
  static ObjCAtSynchronizedStmtContainingStmtRange containing(const Stmt &stmt);

  static std::optional<ObjCAtSynchronizedStmt> from(const TokenContext &c);
  static std::optional<ObjCAtSynchronizedStmt> from(const Stmt &parent);
  Token at_synchronized_token(void) const;
  CompoundStmt synch_body(void) const;
  Expr synch_expression(void) const;
};

using ObjCAtFinallyStmtRange = DerivedEntityRange<StmtIterator, ObjCAtFinallyStmt>;
using ObjCAtFinallyStmtContainingTokenRange = DerivedEntityRange<TokenContextIterator, ObjCAtFinallyStmt>;
using ObjCAtFinallyStmtContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, ObjCAtFinallyStmt>;

class ObjCAtFinallyStmt : public Stmt {
 private:
  friend class FragmentImpl;
  friend class Stmt;
 public:
  inline static ObjCAtFinallyStmtRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static ObjCAtFinallyStmtContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static ObjCAtFinallyStmtContainingStmtRange containing(const Decl &decl);
  static ObjCAtFinallyStmtContainingStmtRange containing(const Stmt &stmt);

  static std::optional<ObjCAtFinallyStmt> from(const TokenContext &c);
  static std::optional<ObjCAtFinallyStmt> from(const Stmt &parent);
  Token at_finally_token(void) const;
  Stmt finally_body(void) const;
};

using ObjCAtCatchStmtRange = DerivedEntityRange<StmtIterator, ObjCAtCatchStmt>;
using ObjCAtCatchStmtContainingTokenRange = DerivedEntityRange<TokenContextIterator, ObjCAtCatchStmt>;
using ObjCAtCatchStmtContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, ObjCAtCatchStmt>;

class ObjCAtCatchStmt : public Stmt {
 private:
  friend class FragmentImpl;
  friend class Stmt;
 public:
  inline static ObjCAtCatchStmtRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static ObjCAtCatchStmtContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static ObjCAtCatchStmtContainingStmtRange containing(const Decl &decl);
  static ObjCAtCatchStmtContainingStmtRange containing(const Stmt &stmt);

  static std::optional<ObjCAtCatchStmt> from(const TokenContext &c);
  static std::optional<ObjCAtCatchStmt> from(const Stmt &parent);
  Token at_catch_token(void) const;
  Stmt catch_body(void) const;
  VarDecl catch_parameter_declaration(void) const;
  Token r_paren_token(void) const;
  bool has_ellipsis(void) const;
};

using OMPExecutableDirectiveRange = DerivedEntityRange<StmtIterator, OMPExecutableDirective>;
using OMPExecutableDirectiveContainingTokenRange = DerivedEntityRange<TokenContextIterator, OMPExecutableDirective>;
using OMPExecutableDirectiveContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, OMPExecutableDirective>;

class OMPExecutableDirective : public Stmt {
 private:
  friend class FragmentImpl;
  friend class Stmt;
 public:
  inline static OMPExecutableDirectiveRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static OMPExecutableDirectiveContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static OMPExecutableDirectiveContainingStmtRange containing(const Decl &decl);
  static OMPExecutableDirectiveContainingStmtRange containing(const Stmt &stmt);

  static std::optional<OMPExecutableDirective> from(const TokenContext &c);
  static std::optional<OMPExecutableDirective> from(const Stmt &parent);
  Stmt associated_statement(void) const;
  CapturedStmt innermost_captured_statement(void) const;
  Stmt raw_statement(void) const;
  Stmt structured_block(void) const;
  bool has_associated_statement(void) const;
  bool is_standalone_directive(void) const;
};

using OMPDispatchDirectiveRange = DerivedEntityRange<StmtIterator, OMPDispatchDirective>;
using OMPDispatchDirectiveContainingTokenRange = DerivedEntityRange<TokenContextIterator, OMPDispatchDirective>;
using OMPDispatchDirectiveContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, OMPDispatchDirective>;

class OMPDispatchDirective : public OMPExecutableDirective {
 private:
  friend class FragmentImpl;
  friend class OMPExecutableDirective;
  friend class Stmt;
 public:
  inline static OMPDispatchDirectiveRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static OMPDispatchDirectiveContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static OMPDispatchDirectiveContainingStmtRange containing(const Decl &decl);
  static OMPDispatchDirectiveContainingStmtRange containing(const Stmt &stmt);

  static std::optional<OMPDispatchDirective> from(const TokenContext &c);
  static std::optional<OMPDispatchDirective> from(const OMPExecutableDirective &parent);
  static std::optional<OMPDispatchDirective> from(const Stmt &parent);
  Token target_call_token(void) const;
};

using OMPDepobjDirectiveRange = DerivedEntityRange<StmtIterator, OMPDepobjDirective>;
using OMPDepobjDirectiveContainingTokenRange = DerivedEntityRange<TokenContextIterator, OMPDepobjDirective>;
using OMPDepobjDirectiveContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, OMPDepobjDirective>;

class OMPDepobjDirective : public OMPExecutableDirective {
 private:
  friend class FragmentImpl;
  friend class OMPExecutableDirective;
  friend class Stmt;
 public:
  inline static OMPDepobjDirectiveRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static OMPDepobjDirectiveContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static OMPDepobjDirectiveContainingStmtRange containing(const Decl &decl);
  static OMPDepobjDirectiveContainingStmtRange containing(const Stmt &stmt);

  static std::optional<OMPDepobjDirective> from(const TokenContext &c);
  static std::optional<OMPDepobjDirective> from(const OMPExecutableDirective &parent);
  static std::optional<OMPDepobjDirective> from(const Stmt &parent);
};

using OMPCriticalDirectiveRange = DerivedEntityRange<StmtIterator, OMPCriticalDirective>;
using OMPCriticalDirectiveContainingTokenRange = DerivedEntityRange<TokenContextIterator, OMPCriticalDirective>;
using OMPCriticalDirectiveContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, OMPCriticalDirective>;

class OMPCriticalDirective : public OMPExecutableDirective {
 private:
  friend class FragmentImpl;
  friend class OMPExecutableDirective;
  friend class Stmt;
 public:
  inline static OMPCriticalDirectiveRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static OMPCriticalDirectiveContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static OMPCriticalDirectiveContainingStmtRange containing(const Decl &decl);
  static OMPCriticalDirectiveContainingStmtRange containing(const Stmt &stmt);

  static std::optional<OMPCriticalDirective> from(const TokenContext &c);
  static std::optional<OMPCriticalDirective> from(const OMPExecutableDirective &parent);
  static std::optional<OMPCriticalDirective> from(const Stmt &parent);
};

using OMPCancellationPointDirectiveRange = DerivedEntityRange<StmtIterator, OMPCancellationPointDirective>;
using OMPCancellationPointDirectiveContainingTokenRange = DerivedEntityRange<TokenContextIterator, OMPCancellationPointDirective>;
using OMPCancellationPointDirectiveContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, OMPCancellationPointDirective>;

class OMPCancellationPointDirective : public OMPExecutableDirective {
 private:
  friend class FragmentImpl;
  friend class OMPExecutableDirective;
  friend class Stmt;
 public:
  inline static OMPCancellationPointDirectiveRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static OMPCancellationPointDirectiveContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static OMPCancellationPointDirectiveContainingStmtRange containing(const Decl &decl);
  static OMPCancellationPointDirectiveContainingStmtRange containing(const Stmt &stmt);

  static std::optional<OMPCancellationPointDirective> from(const TokenContext &c);
  static std::optional<OMPCancellationPointDirective> from(const OMPExecutableDirective &parent);
  static std::optional<OMPCancellationPointDirective> from(const Stmt &parent);
};

using OMPCancelDirectiveRange = DerivedEntityRange<StmtIterator, OMPCancelDirective>;
using OMPCancelDirectiveContainingTokenRange = DerivedEntityRange<TokenContextIterator, OMPCancelDirective>;
using OMPCancelDirectiveContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, OMPCancelDirective>;

class OMPCancelDirective : public OMPExecutableDirective {
 private:
  friend class FragmentImpl;
  friend class OMPExecutableDirective;
  friend class Stmt;
 public:
  inline static OMPCancelDirectiveRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static OMPCancelDirectiveContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static OMPCancelDirectiveContainingStmtRange containing(const Decl &decl);
  static OMPCancelDirectiveContainingStmtRange containing(const Stmt &stmt);

  static std::optional<OMPCancelDirective> from(const TokenContext &c);
  static std::optional<OMPCancelDirective> from(const OMPExecutableDirective &parent);
  static std::optional<OMPCancelDirective> from(const Stmt &parent);
};

using OMPBarrierDirectiveRange = DerivedEntityRange<StmtIterator, OMPBarrierDirective>;
using OMPBarrierDirectiveContainingTokenRange = DerivedEntityRange<TokenContextIterator, OMPBarrierDirective>;
using OMPBarrierDirectiveContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, OMPBarrierDirective>;

class OMPBarrierDirective : public OMPExecutableDirective {
 private:
  friend class FragmentImpl;
  friend class OMPExecutableDirective;
  friend class Stmt;
 public:
  inline static OMPBarrierDirectiveRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static OMPBarrierDirectiveContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static OMPBarrierDirectiveContainingStmtRange containing(const Decl &decl);
  static OMPBarrierDirectiveContainingStmtRange containing(const Stmt &stmt);

  static std::optional<OMPBarrierDirective> from(const TokenContext &c);
  static std::optional<OMPBarrierDirective> from(const OMPExecutableDirective &parent);
  static std::optional<OMPBarrierDirective> from(const Stmt &parent);
};

using OMPAtomicDirectiveRange = DerivedEntityRange<StmtIterator, OMPAtomicDirective>;
using OMPAtomicDirectiveContainingTokenRange = DerivedEntityRange<TokenContextIterator, OMPAtomicDirective>;
using OMPAtomicDirectiveContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, OMPAtomicDirective>;

class OMPAtomicDirective : public OMPExecutableDirective {
 private:
  friend class FragmentImpl;
  friend class OMPExecutableDirective;
  friend class Stmt;
 public:
  inline static OMPAtomicDirectiveRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static OMPAtomicDirectiveContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static OMPAtomicDirectiveContainingStmtRange containing(const Decl &decl);
  static OMPAtomicDirectiveContainingStmtRange containing(const Stmt &stmt);

  static std::optional<OMPAtomicDirective> from(const TokenContext &c);
  static std::optional<OMPAtomicDirective> from(const OMPExecutableDirective &parent);
  static std::optional<OMPAtomicDirective> from(const Stmt &parent);
  Expr expression(void) const;
  Expr update_expression(void) const;
  Expr v(void) const;
  Expr x(void) const;
  bool is_postfix_update(void) const;
  bool is_xlhs_in_rhs_part(void) const;
};

using OMPTeamsDirectiveRange = DerivedEntityRange<StmtIterator, OMPTeamsDirective>;
using OMPTeamsDirectiveContainingTokenRange = DerivedEntityRange<TokenContextIterator, OMPTeamsDirective>;
using OMPTeamsDirectiveContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, OMPTeamsDirective>;

class OMPTeamsDirective : public OMPExecutableDirective {
 private:
  friend class FragmentImpl;
  friend class OMPExecutableDirective;
  friend class Stmt;
 public:
  inline static OMPTeamsDirectiveRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static OMPTeamsDirectiveContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static OMPTeamsDirectiveContainingStmtRange containing(const Decl &decl);
  static OMPTeamsDirectiveContainingStmtRange containing(const Stmt &stmt);

  static std::optional<OMPTeamsDirective> from(const TokenContext &c);
  static std::optional<OMPTeamsDirective> from(const OMPExecutableDirective &parent);
  static std::optional<OMPTeamsDirective> from(const Stmt &parent);
};

using OMPTaskyieldDirectiveRange = DerivedEntityRange<StmtIterator, OMPTaskyieldDirective>;
using OMPTaskyieldDirectiveContainingTokenRange = DerivedEntityRange<TokenContextIterator, OMPTaskyieldDirective>;
using OMPTaskyieldDirectiveContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, OMPTaskyieldDirective>;

class OMPTaskyieldDirective : public OMPExecutableDirective {
 private:
  friend class FragmentImpl;
  friend class OMPExecutableDirective;
  friend class Stmt;
 public:
  inline static OMPTaskyieldDirectiveRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static OMPTaskyieldDirectiveContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static OMPTaskyieldDirectiveContainingStmtRange containing(const Decl &decl);
  static OMPTaskyieldDirectiveContainingStmtRange containing(const Stmt &stmt);

  static std::optional<OMPTaskyieldDirective> from(const TokenContext &c);
  static std::optional<OMPTaskyieldDirective> from(const OMPExecutableDirective &parent);
  static std::optional<OMPTaskyieldDirective> from(const Stmt &parent);
};

using OMPTaskwaitDirectiveRange = DerivedEntityRange<StmtIterator, OMPTaskwaitDirective>;
using OMPTaskwaitDirectiveContainingTokenRange = DerivedEntityRange<TokenContextIterator, OMPTaskwaitDirective>;
using OMPTaskwaitDirectiveContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, OMPTaskwaitDirective>;

class OMPTaskwaitDirective : public OMPExecutableDirective {
 private:
  friend class FragmentImpl;
  friend class OMPExecutableDirective;
  friend class Stmt;
 public:
  inline static OMPTaskwaitDirectiveRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static OMPTaskwaitDirectiveContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static OMPTaskwaitDirectiveContainingStmtRange containing(const Decl &decl);
  static OMPTaskwaitDirectiveContainingStmtRange containing(const Stmt &stmt);

  static std::optional<OMPTaskwaitDirective> from(const TokenContext &c);
  static std::optional<OMPTaskwaitDirective> from(const OMPExecutableDirective &parent);
  static std::optional<OMPTaskwaitDirective> from(const Stmt &parent);
};

using OMPTaskgroupDirectiveRange = DerivedEntityRange<StmtIterator, OMPTaskgroupDirective>;
using OMPTaskgroupDirectiveContainingTokenRange = DerivedEntityRange<TokenContextIterator, OMPTaskgroupDirective>;
using OMPTaskgroupDirectiveContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, OMPTaskgroupDirective>;

class OMPTaskgroupDirective : public OMPExecutableDirective {
 private:
  friend class FragmentImpl;
  friend class OMPExecutableDirective;
  friend class Stmt;
 public:
  inline static OMPTaskgroupDirectiveRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static OMPTaskgroupDirectiveContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static OMPTaskgroupDirectiveContainingStmtRange containing(const Decl &decl);
  static OMPTaskgroupDirectiveContainingStmtRange containing(const Stmt &stmt);

  static std::optional<OMPTaskgroupDirective> from(const TokenContext &c);
  static std::optional<OMPTaskgroupDirective> from(const OMPExecutableDirective &parent);
  static std::optional<OMPTaskgroupDirective> from(const Stmt &parent);
  Expr reduction_reference(void) const;
};

using OMPTaskDirectiveRange = DerivedEntityRange<StmtIterator, OMPTaskDirective>;
using OMPTaskDirectiveContainingTokenRange = DerivedEntityRange<TokenContextIterator, OMPTaskDirective>;
using OMPTaskDirectiveContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, OMPTaskDirective>;

class OMPTaskDirective : public OMPExecutableDirective {
 private:
  friend class FragmentImpl;
  friend class OMPExecutableDirective;
  friend class Stmt;
 public:
  inline static OMPTaskDirectiveRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static OMPTaskDirectiveContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static OMPTaskDirectiveContainingStmtRange containing(const Decl &decl);
  static OMPTaskDirectiveContainingStmtRange containing(const Stmt &stmt);

  static std::optional<OMPTaskDirective> from(const TokenContext &c);
  static std::optional<OMPTaskDirective> from(const OMPExecutableDirective &parent);
  static std::optional<OMPTaskDirective> from(const Stmt &parent);
  bool has_cancel(void) const;
};

using OMPTargetUpdateDirectiveRange = DerivedEntityRange<StmtIterator, OMPTargetUpdateDirective>;
using OMPTargetUpdateDirectiveContainingTokenRange = DerivedEntityRange<TokenContextIterator, OMPTargetUpdateDirective>;
using OMPTargetUpdateDirectiveContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, OMPTargetUpdateDirective>;

class OMPTargetUpdateDirective : public OMPExecutableDirective {
 private:
  friend class FragmentImpl;
  friend class OMPExecutableDirective;
  friend class Stmt;
 public:
  inline static OMPTargetUpdateDirectiveRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static OMPTargetUpdateDirectiveContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static OMPTargetUpdateDirectiveContainingStmtRange containing(const Decl &decl);
  static OMPTargetUpdateDirectiveContainingStmtRange containing(const Stmt &stmt);

  static std::optional<OMPTargetUpdateDirective> from(const TokenContext &c);
  static std::optional<OMPTargetUpdateDirective> from(const OMPExecutableDirective &parent);
  static std::optional<OMPTargetUpdateDirective> from(const Stmt &parent);
};

using OMPTargetTeamsDirectiveRange = DerivedEntityRange<StmtIterator, OMPTargetTeamsDirective>;
using OMPTargetTeamsDirectiveContainingTokenRange = DerivedEntityRange<TokenContextIterator, OMPTargetTeamsDirective>;
using OMPTargetTeamsDirectiveContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, OMPTargetTeamsDirective>;

class OMPTargetTeamsDirective : public OMPExecutableDirective {
 private:
  friend class FragmentImpl;
  friend class OMPExecutableDirective;
  friend class Stmt;
 public:
  inline static OMPTargetTeamsDirectiveRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static OMPTargetTeamsDirectiveContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static OMPTargetTeamsDirectiveContainingStmtRange containing(const Decl &decl);
  static OMPTargetTeamsDirectiveContainingStmtRange containing(const Stmt &stmt);

  static std::optional<OMPTargetTeamsDirective> from(const TokenContext &c);
  static std::optional<OMPTargetTeamsDirective> from(const OMPExecutableDirective &parent);
  static std::optional<OMPTargetTeamsDirective> from(const Stmt &parent);
};

using OMPTargetParallelDirectiveRange = DerivedEntityRange<StmtIterator, OMPTargetParallelDirective>;
using OMPTargetParallelDirectiveContainingTokenRange = DerivedEntityRange<TokenContextIterator, OMPTargetParallelDirective>;
using OMPTargetParallelDirectiveContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, OMPTargetParallelDirective>;

class OMPTargetParallelDirective : public OMPExecutableDirective {
 private:
  friend class FragmentImpl;
  friend class OMPExecutableDirective;
  friend class Stmt;
 public:
  inline static OMPTargetParallelDirectiveRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static OMPTargetParallelDirectiveContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static OMPTargetParallelDirectiveContainingStmtRange containing(const Decl &decl);
  static OMPTargetParallelDirectiveContainingStmtRange containing(const Stmt &stmt);

  static std::optional<OMPTargetParallelDirective> from(const TokenContext &c);
  static std::optional<OMPTargetParallelDirective> from(const OMPExecutableDirective &parent);
  static std::optional<OMPTargetParallelDirective> from(const Stmt &parent);
  Expr task_reduction_reference_expression(void) const;
  bool has_cancel(void) const;
};

using OMPTargetExitDataDirectiveRange = DerivedEntityRange<StmtIterator, OMPTargetExitDataDirective>;
using OMPTargetExitDataDirectiveContainingTokenRange = DerivedEntityRange<TokenContextIterator, OMPTargetExitDataDirective>;
using OMPTargetExitDataDirectiveContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, OMPTargetExitDataDirective>;

class OMPTargetExitDataDirective : public OMPExecutableDirective {
 private:
  friend class FragmentImpl;
  friend class OMPExecutableDirective;
  friend class Stmt;
 public:
  inline static OMPTargetExitDataDirectiveRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static OMPTargetExitDataDirectiveContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static OMPTargetExitDataDirectiveContainingStmtRange containing(const Decl &decl);
  static OMPTargetExitDataDirectiveContainingStmtRange containing(const Stmt &stmt);

  static std::optional<OMPTargetExitDataDirective> from(const TokenContext &c);
  static std::optional<OMPTargetExitDataDirective> from(const OMPExecutableDirective &parent);
  static std::optional<OMPTargetExitDataDirective> from(const Stmt &parent);
};

using OMPTargetEnterDataDirectiveRange = DerivedEntityRange<StmtIterator, OMPTargetEnterDataDirective>;
using OMPTargetEnterDataDirectiveContainingTokenRange = DerivedEntityRange<TokenContextIterator, OMPTargetEnterDataDirective>;
using OMPTargetEnterDataDirectiveContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, OMPTargetEnterDataDirective>;

class OMPTargetEnterDataDirective : public OMPExecutableDirective {
 private:
  friend class FragmentImpl;
  friend class OMPExecutableDirective;
  friend class Stmt;
 public:
  inline static OMPTargetEnterDataDirectiveRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static OMPTargetEnterDataDirectiveContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static OMPTargetEnterDataDirectiveContainingStmtRange containing(const Decl &decl);
  static OMPTargetEnterDataDirectiveContainingStmtRange containing(const Stmt &stmt);

  static std::optional<OMPTargetEnterDataDirective> from(const TokenContext &c);
  static std::optional<OMPTargetEnterDataDirective> from(const OMPExecutableDirective &parent);
  static std::optional<OMPTargetEnterDataDirective> from(const Stmt &parent);
};

using OMPTargetDirectiveRange = DerivedEntityRange<StmtIterator, OMPTargetDirective>;
using OMPTargetDirectiveContainingTokenRange = DerivedEntityRange<TokenContextIterator, OMPTargetDirective>;
using OMPTargetDirectiveContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, OMPTargetDirective>;

class OMPTargetDirective : public OMPExecutableDirective {
 private:
  friend class FragmentImpl;
  friend class OMPExecutableDirective;
  friend class Stmt;
 public:
  inline static OMPTargetDirectiveRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static OMPTargetDirectiveContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static OMPTargetDirectiveContainingStmtRange containing(const Decl &decl);
  static OMPTargetDirectiveContainingStmtRange containing(const Stmt &stmt);

  static std::optional<OMPTargetDirective> from(const TokenContext &c);
  static std::optional<OMPTargetDirective> from(const OMPExecutableDirective &parent);
  static std::optional<OMPTargetDirective> from(const Stmt &parent);
};

using OMPTargetDataDirectiveRange = DerivedEntityRange<StmtIterator, OMPTargetDataDirective>;
using OMPTargetDataDirectiveContainingTokenRange = DerivedEntityRange<TokenContextIterator, OMPTargetDataDirective>;
using OMPTargetDataDirectiveContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, OMPTargetDataDirective>;

class OMPTargetDataDirective : public OMPExecutableDirective {
 private:
  friend class FragmentImpl;
  friend class OMPExecutableDirective;
  friend class Stmt;
 public:
  inline static OMPTargetDataDirectiveRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static OMPTargetDataDirectiveContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static OMPTargetDataDirectiveContainingStmtRange containing(const Decl &decl);
  static OMPTargetDataDirectiveContainingStmtRange containing(const Stmt &stmt);

  static std::optional<OMPTargetDataDirective> from(const TokenContext &c);
  static std::optional<OMPTargetDataDirective> from(const OMPExecutableDirective &parent);
  static std::optional<OMPTargetDataDirective> from(const Stmt &parent);
};

using OMPSingleDirectiveRange = DerivedEntityRange<StmtIterator, OMPSingleDirective>;
using OMPSingleDirectiveContainingTokenRange = DerivedEntityRange<TokenContextIterator, OMPSingleDirective>;
using OMPSingleDirectiveContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, OMPSingleDirective>;

class OMPSingleDirective : public OMPExecutableDirective {
 private:
  friend class FragmentImpl;
  friend class OMPExecutableDirective;
  friend class Stmt;
 public:
  inline static OMPSingleDirectiveRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static OMPSingleDirectiveContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static OMPSingleDirectiveContainingStmtRange containing(const Decl &decl);
  static OMPSingleDirectiveContainingStmtRange containing(const Stmt &stmt);

  static std::optional<OMPSingleDirective> from(const TokenContext &c);
  static std::optional<OMPSingleDirective> from(const OMPExecutableDirective &parent);
  static std::optional<OMPSingleDirective> from(const Stmt &parent);
};

using OMPSectionsDirectiveRange = DerivedEntityRange<StmtIterator, OMPSectionsDirective>;
using OMPSectionsDirectiveContainingTokenRange = DerivedEntityRange<TokenContextIterator, OMPSectionsDirective>;
using OMPSectionsDirectiveContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, OMPSectionsDirective>;

class OMPSectionsDirective : public OMPExecutableDirective {
 private:
  friend class FragmentImpl;
  friend class OMPExecutableDirective;
  friend class Stmt;
 public:
  inline static OMPSectionsDirectiveRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static OMPSectionsDirectiveContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static OMPSectionsDirectiveContainingStmtRange containing(const Decl &decl);
  static OMPSectionsDirectiveContainingStmtRange containing(const Stmt &stmt);

  static std::optional<OMPSectionsDirective> from(const TokenContext &c);
  static std::optional<OMPSectionsDirective> from(const OMPExecutableDirective &parent);
  static std::optional<OMPSectionsDirective> from(const Stmt &parent);
  Expr task_reduction_reference_expression(void) const;
  bool has_cancel(void) const;
};

using OMPSectionDirectiveRange = DerivedEntityRange<StmtIterator, OMPSectionDirective>;
using OMPSectionDirectiveContainingTokenRange = DerivedEntityRange<TokenContextIterator, OMPSectionDirective>;
using OMPSectionDirectiveContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, OMPSectionDirective>;

class OMPSectionDirective : public OMPExecutableDirective {
 private:
  friend class FragmentImpl;
  friend class OMPExecutableDirective;
  friend class Stmt;
 public:
  inline static OMPSectionDirectiveRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static OMPSectionDirectiveContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static OMPSectionDirectiveContainingStmtRange containing(const Decl &decl);
  static OMPSectionDirectiveContainingStmtRange containing(const Stmt &stmt);

  static std::optional<OMPSectionDirective> from(const TokenContext &c);
  static std::optional<OMPSectionDirective> from(const OMPExecutableDirective &parent);
  static std::optional<OMPSectionDirective> from(const Stmt &parent);
  bool has_cancel(void) const;
};

using OMPScanDirectiveRange = DerivedEntityRange<StmtIterator, OMPScanDirective>;
using OMPScanDirectiveContainingTokenRange = DerivedEntityRange<TokenContextIterator, OMPScanDirective>;
using OMPScanDirectiveContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, OMPScanDirective>;

class OMPScanDirective : public OMPExecutableDirective {
 private:
  friend class FragmentImpl;
  friend class OMPExecutableDirective;
  friend class Stmt;
 public:
  inline static OMPScanDirectiveRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static OMPScanDirectiveContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static OMPScanDirectiveContainingStmtRange containing(const Decl &decl);
  static OMPScanDirectiveContainingStmtRange containing(const Stmt &stmt);

  static std::optional<OMPScanDirective> from(const TokenContext &c);
  static std::optional<OMPScanDirective> from(const OMPExecutableDirective &parent);
  static std::optional<OMPScanDirective> from(const Stmt &parent);
};

using OMPParallelSectionsDirectiveRange = DerivedEntityRange<StmtIterator, OMPParallelSectionsDirective>;
using OMPParallelSectionsDirectiveContainingTokenRange = DerivedEntityRange<TokenContextIterator, OMPParallelSectionsDirective>;
using OMPParallelSectionsDirectiveContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, OMPParallelSectionsDirective>;

class OMPParallelSectionsDirective : public OMPExecutableDirective {
 private:
  friend class FragmentImpl;
  friend class OMPExecutableDirective;
  friend class Stmt;
 public:
  inline static OMPParallelSectionsDirectiveRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static OMPParallelSectionsDirectiveContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static OMPParallelSectionsDirectiveContainingStmtRange containing(const Decl &decl);
  static OMPParallelSectionsDirectiveContainingStmtRange containing(const Stmt &stmt);

  static std::optional<OMPParallelSectionsDirective> from(const TokenContext &c);
  static std::optional<OMPParallelSectionsDirective> from(const OMPExecutableDirective &parent);
  static std::optional<OMPParallelSectionsDirective> from(const Stmt &parent);
  Expr task_reduction_reference_expression(void) const;
  bool has_cancel(void) const;
};

using OMPParallelMasterDirectiveRange = DerivedEntityRange<StmtIterator, OMPParallelMasterDirective>;
using OMPParallelMasterDirectiveContainingTokenRange = DerivedEntityRange<TokenContextIterator, OMPParallelMasterDirective>;
using OMPParallelMasterDirectiveContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, OMPParallelMasterDirective>;

class OMPParallelMasterDirective : public OMPExecutableDirective {
 private:
  friend class FragmentImpl;
  friend class OMPExecutableDirective;
  friend class Stmt;
 public:
  inline static OMPParallelMasterDirectiveRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static OMPParallelMasterDirectiveContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static OMPParallelMasterDirectiveContainingStmtRange containing(const Decl &decl);
  static OMPParallelMasterDirectiveContainingStmtRange containing(const Stmt &stmt);

  static std::optional<OMPParallelMasterDirective> from(const TokenContext &c);
  static std::optional<OMPParallelMasterDirective> from(const OMPExecutableDirective &parent);
  static std::optional<OMPParallelMasterDirective> from(const Stmt &parent);
  Expr task_reduction_reference_expression(void) const;
};

using OMPParallelDirectiveRange = DerivedEntityRange<StmtIterator, OMPParallelDirective>;
using OMPParallelDirectiveContainingTokenRange = DerivedEntityRange<TokenContextIterator, OMPParallelDirective>;
using OMPParallelDirectiveContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, OMPParallelDirective>;

class OMPParallelDirective : public OMPExecutableDirective {
 private:
  friend class FragmentImpl;
  friend class OMPExecutableDirective;
  friend class Stmt;
 public:
  inline static OMPParallelDirectiveRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static OMPParallelDirectiveContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static OMPParallelDirectiveContainingStmtRange containing(const Decl &decl);
  static OMPParallelDirectiveContainingStmtRange containing(const Stmt &stmt);

  static std::optional<OMPParallelDirective> from(const TokenContext &c);
  static std::optional<OMPParallelDirective> from(const OMPExecutableDirective &parent);
  static std::optional<OMPParallelDirective> from(const Stmt &parent);
  Expr task_reduction_reference_expression(void) const;
  bool has_cancel(void) const;
};

using OMPOrderedDirectiveRange = DerivedEntityRange<StmtIterator, OMPOrderedDirective>;
using OMPOrderedDirectiveContainingTokenRange = DerivedEntityRange<TokenContextIterator, OMPOrderedDirective>;
using OMPOrderedDirectiveContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, OMPOrderedDirective>;

class OMPOrderedDirective : public OMPExecutableDirective {
 private:
  friend class FragmentImpl;
  friend class OMPExecutableDirective;
  friend class Stmt;
 public:
  inline static OMPOrderedDirectiveRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static OMPOrderedDirectiveContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static OMPOrderedDirectiveContainingStmtRange containing(const Decl &decl);
  static OMPOrderedDirectiveContainingStmtRange containing(const Stmt &stmt);

  static std::optional<OMPOrderedDirective> from(const TokenContext &c);
  static std::optional<OMPOrderedDirective> from(const OMPExecutableDirective &parent);
  static std::optional<OMPOrderedDirective> from(const Stmt &parent);
};

using OMPMasterDirectiveRange = DerivedEntityRange<StmtIterator, OMPMasterDirective>;
using OMPMasterDirectiveContainingTokenRange = DerivedEntityRange<TokenContextIterator, OMPMasterDirective>;
using OMPMasterDirectiveContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, OMPMasterDirective>;

class OMPMasterDirective : public OMPExecutableDirective {
 private:
  friend class FragmentImpl;
  friend class OMPExecutableDirective;
  friend class Stmt;
 public:
  inline static OMPMasterDirectiveRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static OMPMasterDirectiveContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static OMPMasterDirectiveContainingStmtRange containing(const Decl &decl);
  static OMPMasterDirectiveContainingStmtRange containing(const Stmt &stmt);

  static std::optional<OMPMasterDirective> from(const TokenContext &c);
  static std::optional<OMPMasterDirective> from(const OMPExecutableDirective &parent);
  static std::optional<OMPMasterDirective> from(const Stmt &parent);
};

using OMPMaskedDirectiveRange = DerivedEntityRange<StmtIterator, OMPMaskedDirective>;
using OMPMaskedDirectiveContainingTokenRange = DerivedEntityRange<TokenContextIterator, OMPMaskedDirective>;
using OMPMaskedDirectiveContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, OMPMaskedDirective>;

class OMPMaskedDirective : public OMPExecutableDirective {
 private:
  friend class FragmentImpl;
  friend class OMPExecutableDirective;
  friend class Stmt;
 public:
  inline static OMPMaskedDirectiveRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static OMPMaskedDirectiveContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static OMPMaskedDirectiveContainingStmtRange containing(const Decl &decl);
  static OMPMaskedDirectiveContainingStmtRange containing(const Stmt &stmt);

  static std::optional<OMPMaskedDirective> from(const TokenContext &c);
  static std::optional<OMPMaskedDirective> from(const OMPExecutableDirective &parent);
  static std::optional<OMPMaskedDirective> from(const Stmt &parent);
};

using OMPLoopBasedDirectiveRange = DerivedEntityRange<StmtIterator, OMPLoopBasedDirective>;
using OMPLoopBasedDirectiveContainingTokenRange = DerivedEntityRange<TokenContextIterator, OMPLoopBasedDirective>;
using OMPLoopBasedDirectiveContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, OMPLoopBasedDirective>;

class OMPLoopBasedDirective : public OMPExecutableDirective {
 private:
  friend class FragmentImpl;
  friend class OMPExecutableDirective;
  friend class Stmt;
 public:
  inline static OMPLoopBasedDirectiveRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static OMPLoopBasedDirectiveContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static OMPLoopBasedDirectiveContainingStmtRange containing(const Decl &decl);
  static OMPLoopBasedDirectiveContainingStmtRange containing(const Stmt &stmt);

  static std::optional<OMPLoopBasedDirective> from(const TokenContext &c);
  static std::optional<OMPLoopBasedDirective> from(const OMPExecutableDirective &parent);
  static std::optional<OMPLoopBasedDirective> from(const Stmt &parent);
};

using OMPUnrollDirectiveRange = DerivedEntityRange<StmtIterator, OMPUnrollDirective>;
using OMPUnrollDirectiveContainingTokenRange = DerivedEntityRange<TokenContextIterator, OMPUnrollDirective>;
using OMPUnrollDirectiveContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, OMPUnrollDirective>;

class OMPUnrollDirective : public OMPLoopBasedDirective {
 private:
  friend class FragmentImpl;
  friend class OMPLoopBasedDirective;
  friend class OMPExecutableDirective;
  friend class Stmt;
 public:
  inline static OMPUnrollDirectiveRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static OMPUnrollDirectiveContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static OMPUnrollDirectiveContainingStmtRange containing(const Decl &decl);
  static OMPUnrollDirectiveContainingStmtRange containing(const Stmt &stmt);

  static std::optional<OMPUnrollDirective> from(const TokenContext &c);
  static std::optional<OMPUnrollDirective> from(const OMPLoopBasedDirective &parent);
  static std::optional<OMPUnrollDirective> from(const OMPExecutableDirective &parent);
  static std::optional<OMPUnrollDirective> from(const Stmt &parent);
  Stmt pre_initializers(void) const;
  Stmt transformed_statement(void) const;
};

using OMPTileDirectiveRange = DerivedEntityRange<StmtIterator, OMPTileDirective>;
using OMPTileDirectiveContainingTokenRange = DerivedEntityRange<TokenContextIterator, OMPTileDirective>;
using OMPTileDirectiveContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, OMPTileDirective>;

class OMPTileDirective : public OMPLoopBasedDirective {
 private:
  friend class FragmentImpl;
  friend class OMPLoopBasedDirective;
  friend class OMPExecutableDirective;
  friend class Stmt;
 public:
  inline static OMPTileDirectiveRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static OMPTileDirectiveContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static OMPTileDirectiveContainingStmtRange containing(const Decl &decl);
  static OMPTileDirectiveContainingStmtRange containing(const Stmt &stmt);

  static std::optional<OMPTileDirective> from(const TokenContext &c);
  static std::optional<OMPTileDirective> from(const OMPLoopBasedDirective &parent);
  static std::optional<OMPTileDirective> from(const OMPExecutableDirective &parent);
  static std::optional<OMPTileDirective> from(const Stmt &parent);
  Stmt pre_initializers(void) const;
  Stmt transformed_statement(void) const;
};

using OMPLoopDirectiveRange = DerivedEntityRange<StmtIterator, OMPLoopDirective>;
using OMPLoopDirectiveContainingTokenRange = DerivedEntityRange<TokenContextIterator, OMPLoopDirective>;
using OMPLoopDirectiveContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, OMPLoopDirective>;

class OMPLoopDirective : public OMPLoopBasedDirective {
 private:
  friend class FragmentImpl;
  friend class OMPLoopBasedDirective;
  friend class OMPExecutableDirective;
  friend class Stmt;
 public:
  inline static OMPLoopDirectiveRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static OMPLoopDirectiveContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static OMPLoopDirectiveContainingStmtRange containing(const Decl &decl);
  static OMPLoopDirectiveContainingStmtRange containing(const Stmt &stmt);

  static std::optional<OMPLoopDirective> from(const TokenContext &c);
  static std::optional<OMPLoopDirective> from(const OMPLoopBasedDirective &parent);
  static std::optional<OMPLoopDirective> from(const OMPExecutableDirective &parent);
  static std::optional<OMPLoopDirective> from(const Stmt &parent);
  std::vector<Expr> counters(void) const;
  std::vector<Expr> dependent_counters(void) const;
  std::vector<Expr> dependent_initializers(void) const;
  std::vector<Expr> finals(void) const;
  std::vector<Expr> finals_conditions(void) const;
  Stmt body(void) const;
  Expr calculate_last_iteration(void) const;
  Expr combined_condition(void) const;
  Expr combined_distance_condition(void) const;
  Expr combined_ensure_upper_bound(void) const;
  Expr combined_initializer(void) const;
  Expr combined_lower_bound_variable(void) const;
  Expr combined_next_lower_bound(void) const;
  Expr combined_next_upper_bound(void) const;
  Expr combined_parallel_for_in_distance_condition(void) const;
  Expr combined_upper_bound_variable(void) const;
  Expr condition(void) const;
  Expr distance_increment(void) const;
  Expr ensure_upper_bound(void) const;
  Expr increment(void) const;
  Expr initializer(void) const;
  Expr is_last_iteration_variable(void) const;
  Expr iteration_variable(void) const;
  Expr last_iteration(void) const;
  Expr lower_bound_variable(void) const;
  Expr next_lower_bound(void) const;
  Expr next_upper_bound(void) const;
  Expr num_iterations(void) const;
  Expr pre_condition(void) const;
  Stmt pre_initializers(void) const;
  Expr prev_ensure_upper_bound(void) const;
  Expr prev_lower_bound_variable(void) const;
  Expr prev_upper_bound_variable(void) const;
  Expr stride_variable(void) const;
  Expr upper_bound_variable(void) const;
  std::vector<Expr> initializers(void) const;
  std::vector<Expr> private_counters(void) const;
  std::vector<Expr> updates(void) const;
};

using OMPForSimdDirectiveRange = DerivedEntityRange<StmtIterator, OMPForSimdDirective>;
using OMPForSimdDirectiveContainingTokenRange = DerivedEntityRange<TokenContextIterator, OMPForSimdDirective>;
using OMPForSimdDirectiveContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, OMPForSimdDirective>;

class OMPForSimdDirective : public OMPLoopDirective {
 private:
  friend class FragmentImpl;
  friend class OMPLoopDirective;
  friend class OMPLoopBasedDirective;
  friend class OMPExecutableDirective;
  friend class Stmt;
 public:
  inline static OMPForSimdDirectiveRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static OMPForSimdDirectiveContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static OMPForSimdDirectiveContainingStmtRange containing(const Decl &decl);
  static OMPForSimdDirectiveContainingStmtRange containing(const Stmt &stmt);

  static std::optional<OMPForSimdDirective> from(const TokenContext &c);
  static std::optional<OMPForSimdDirective> from(const OMPLoopDirective &parent);
  static std::optional<OMPForSimdDirective> from(const OMPLoopBasedDirective &parent);
  static std::optional<OMPForSimdDirective> from(const OMPExecutableDirective &parent);
  static std::optional<OMPForSimdDirective> from(const Stmt &parent);
};

using OMPForDirectiveRange = DerivedEntityRange<StmtIterator, OMPForDirective>;
using OMPForDirectiveContainingTokenRange = DerivedEntityRange<TokenContextIterator, OMPForDirective>;
using OMPForDirectiveContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, OMPForDirective>;

class OMPForDirective : public OMPLoopDirective {
 private:
  friend class FragmentImpl;
  friend class OMPLoopDirective;
  friend class OMPLoopBasedDirective;
  friend class OMPExecutableDirective;
  friend class Stmt;
 public:
  inline static OMPForDirectiveRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static OMPForDirectiveContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static OMPForDirectiveContainingStmtRange containing(const Decl &decl);
  static OMPForDirectiveContainingStmtRange containing(const Stmt &stmt);

  static std::optional<OMPForDirective> from(const TokenContext &c);
  static std::optional<OMPForDirective> from(const OMPLoopDirective &parent);
  static std::optional<OMPForDirective> from(const OMPLoopBasedDirective &parent);
  static std::optional<OMPForDirective> from(const OMPExecutableDirective &parent);
  static std::optional<OMPForDirective> from(const Stmt &parent);
  Expr task_reduction_reference_expression(void) const;
  bool has_cancel(void) const;
};

using OMPDistributeSimdDirectiveRange = DerivedEntityRange<StmtIterator, OMPDistributeSimdDirective>;
using OMPDistributeSimdDirectiveContainingTokenRange = DerivedEntityRange<TokenContextIterator, OMPDistributeSimdDirective>;
using OMPDistributeSimdDirectiveContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, OMPDistributeSimdDirective>;

class OMPDistributeSimdDirective : public OMPLoopDirective {
 private:
  friend class FragmentImpl;
  friend class OMPLoopDirective;
  friend class OMPLoopBasedDirective;
  friend class OMPExecutableDirective;
  friend class Stmt;
 public:
  inline static OMPDistributeSimdDirectiveRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static OMPDistributeSimdDirectiveContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static OMPDistributeSimdDirectiveContainingStmtRange containing(const Decl &decl);
  static OMPDistributeSimdDirectiveContainingStmtRange containing(const Stmt &stmt);

  static std::optional<OMPDistributeSimdDirective> from(const TokenContext &c);
  static std::optional<OMPDistributeSimdDirective> from(const OMPLoopDirective &parent);
  static std::optional<OMPDistributeSimdDirective> from(const OMPLoopBasedDirective &parent);
  static std::optional<OMPDistributeSimdDirective> from(const OMPExecutableDirective &parent);
  static std::optional<OMPDistributeSimdDirective> from(const Stmt &parent);
};

using OMPDistributeParallelForSimdDirectiveRange = DerivedEntityRange<StmtIterator, OMPDistributeParallelForSimdDirective>;
using OMPDistributeParallelForSimdDirectiveContainingTokenRange = DerivedEntityRange<TokenContextIterator, OMPDistributeParallelForSimdDirective>;
using OMPDistributeParallelForSimdDirectiveContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, OMPDistributeParallelForSimdDirective>;

class OMPDistributeParallelForSimdDirective : public OMPLoopDirective {
 private:
  friend class FragmentImpl;
  friend class OMPLoopDirective;
  friend class OMPLoopBasedDirective;
  friend class OMPExecutableDirective;
  friend class Stmt;
 public:
  inline static OMPDistributeParallelForSimdDirectiveRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static OMPDistributeParallelForSimdDirectiveContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static OMPDistributeParallelForSimdDirectiveContainingStmtRange containing(const Decl &decl);
  static OMPDistributeParallelForSimdDirectiveContainingStmtRange containing(const Stmt &stmt);

  static std::optional<OMPDistributeParallelForSimdDirective> from(const TokenContext &c);
  static std::optional<OMPDistributeParallelForSimdDirective> from(const OMPLoopDirective &parent);
  static std::optional<OMPDistributeParallelForSimdDirective> from(const OMPLoopBasedDirective &parent);
  static std::optional<OMPDistributeParallelForSimdDirective> from(const OMPExecutableDirective &parent);
  static std::optional<OMPDistributeParallelForSimdDirective> from(const Stmt &parent);
};

using OMPDistributeParallelForDirectiveRange = DerivedEntityRange<StmtIterator, OMPDistributeParallelForDirective>;
using OMPDistributeParallelForDirectiveContainingTokenRange = DerivedEntityRange<TokenContextIterator, OMPDistributeParallelForDirective>;
using OMPDistributeParallelForDirectiveContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, OMPDistributeParallelForDirective>;

class OMPDistributeParallelForDirective : public OMPLoopDirective {
 private:
  friend class FragmentImpl;
  friend class OMPLoopDirective;
  friend class OMPLoopBasedDirective;
  friend class OMPExecutableDirective;
  friend class Stmt;
 public:
  inline static OMPDistributeParallelForDirectiveRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static OMPDistributeParallelForDirectiveContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static OMPDistributeParallelForDirectiveContainingStmtRange containing(const Decl &decl);
  static OMPDistributeParallelForDirectiveContainingStmtRange containing(const Stmt &stmt);

  static std::optional<OMPDistributeParallelForDirective> from(const TokenContext &c);
  static std::optional<OMPDistributeParallelForDirective> from(const OMPLoopDirective &parent);
  static std::optional<OMPDistributeParallelForDirective> from(const OMPLoopBasedDirective &parent);
  static std::optional<OMPDistributeParallelForDirective> from(const OMPExecutableDirective &parent);
  static std::optional<OMPDistributeParallelForDirective> from(const Stmt &parent);
  Expr task_reduction_reference_expression(void) const;
  bool has_cancel(void) const;
};

using OMPDistributeDirectiveRange = DerivedEntityRange<StmtIterator, OMPDistributeDirective>;
using OMPDistributeDirectiveContainingTokenRange = DerivedEntityRange<TokenContextIterator, OMPDistributeDirective>;
using OMPDistributeDirectiveContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, OMPDistributeDirective>;

class OMPDistributeDirective : public OMPLoopDirective {
 private:
  friend class FragmentImpl;
  friend class OMPLoopDirective;
  friend class OMPLoopBasedDirective;
  friend class OMPExecutableDirective;
  friend class Stmt;
 public:
  inline static OMPDistributeDirectiveRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static OMPDistributeDirectiveContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static OMPDistributeDirectiveContainingStmtRange containing(const Decl &decl);
  static OMPDistributeDirectiveContainingStmtRange containing(const Stmt &stmt);

  static std::optional<OMPDistributeDirective> from(const TokenContext &c);
  static std::optional<OMPDistributeDirective> from(const OMPLoopDirective &parent);
  static std::optional<OMPDistributeDirective> from(const OMPLoopBasedDirective &parent);
  static std::optional<OMPDistributeDirective> from(const OMPExecutableDirective &parent);
  static std::optional<OMPDistributeDirective> from(const Stmt &parent);
};

using OMPTeamsDistributeSimdDirectiveRange = DerivedEntityRange<StmtIterator, OMPTeamsDistributeSimdDirective>;
using OMPTeamsDistributeSimdDirectiveContainingTokenRange = DerivedEntityRange<TokenContextIterator, OMPTeamsDistributeSimdDirective>;
using OMPTeamsDistributeSimdDirectiveContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, OMPTeamsDistributeSimdDirective>;

class OMPTeamsDistributeSimdDirective : public OMPLoopDirective {
 private:
  friend class FragmentImpl;
  friend class OMPLoopDirective;
  friend class OMPLoopBasedDirective;
  friend class OMPExecutableDirective;
  friend class Stmt;
 public:
  inline static OMPTeamsDistributeSimdDirectiveRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static OMPTeamsDistributeSimdDirectiveContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static OMPTeamsDistributeSimdDirectiveContainingStmtRange containing(const Decl &decl);
  static OMPTeamsDistributeSimdDirectiveContainingStmtRange containing(const Stmt &stmt);

  static std::optional<OMPTeamsDistributeSimdDirective> from(const TokenContext &c);
  static std::optional<OMPTeamsDistributeSimdDirective> from(const OMPLoopDirective &parent);
  static std::optional<OMPTeamsDistributeSimdDirective> from(const OMPLoopBasedDirective &parent);
  static std::optional<OMPTeamsDistributeSimdDirective> from(const OMPExecutableDirective &parent);
  static std::optional<OMPTeamsDistributeSimdDirective> from(const Stmt &parent);
};

using OMPTeamsDistributeParallelForSimdDirectiveRange = DerivedEntityRange<StmtIterator, OMPTeamsDistributeParallelForSimdDirective>;
using OMPTeamsDistributeParallelForSimdDirectiveContainingTokenRange = DerivedEntityRange<TokenContextIterator, OMPTeamsDistributeParallelForSimdDirective>;
using OMPTeamsDistributeParallelForSimdDirectiveContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, OMPTeamsDistributeParallelForSimdDirective>;

class OMPTeamsDistributeParallelForSimdDirective : public OMPLoopDirective {
 private:
  friend class FragmentImpl;
  friend class OMPLoopDirective;
  friend class OMPLoopBasedDirective;
  friend class OMPExecutableDirective;
  friend class Stmt;
 public:
  inline static OMPTeamsDistributeParallelForSimdDirectiveRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static OMPTeamsDistributeParallelForSimdDirectiveContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static OMPTeamsDistributeParallelForSimdDirectiveContainingStmtRange containing(const Decl &decl);
  static OMPTeamsDistributeParallelForSimdDirectiveContainingStmtRange containing(const Stmt &stmt);

  static std::optional<OMPTeamsDistributeParallelForSimdDirective> from(const TokenContext &c);
  static std::optional<OMPTeamsDistributeParallelForSimdDirective> from(const OMPLoopDirective &parent);
  static std::optional<OMPTeamsDistributeParallelForSimdDirective> from(const OMPLoopBasedDirective &parent);
  static std::optional<OMPTeamsDistributeParallelForSimdDirective> from(const OMPExecutableDirective &parent);
  static std::optional<OMPTeamsDistributeParallelForSimdDirective> from(const Stmt &parent);
};

using OMPTeamsDistributeParallelForDirectiveRange = DerivedEntityRange<StmtIterator, OMPTeamsDistributeParallelForDirective>;
using OMPTeamsDistributeParallelForDirectiveContainingTokenRange = DerivedEntityRange<TokenContextIterator, OMPTeamsDistributeParallelForDirective>;
using OMPTeamsDistributeParallelForDirectiveContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, OMPTeamsDistributeParallelForDirective>;

class OMPTeamsDistributeParallelForDirective : public OMPLoopDirective {
 private:
  friend class FragmentImpl;
  friend class OMPLoopDirective;
  friend class OMPLoopBasedDirective;
  friend class OMPExecutableDirective;
  friend class Stmt;
 public:
  inline static OMPTeamsDistributeParallelForDirectiveRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static OMPTeamsDistributeParallelForDirectiveContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static OMPTeamsDistributeParallelForDirectiveContainingStmtRange containing(const Decl &decl);
  static OMPTeamsDistributeParallelForDirectiveContainingStmtRange containing(const Stmt &stmt);

  static std::optional<OMPTeamsDistributeParallelForDirective> from(const TokenContext &c);
  static std::optional<OMPTeamsDistributeParallelForDirective> from(const OMPLoopDirective &parent);
  static std::optional<OMPTeamsDistributeParallelForDirective> from(const OMPLoopBasedDirective &parent);
  static std::optional<OMPTeamsDistributeParallelForDirective> from(const OMPExecutableDirective &parent);
  static std::optional<OMPTeamsDistributeParallelForDirective> from(const Stmt &parent);
  Expr task_reduction_reference_expression(void) const;
  bool has_cancel(void) const;
};

using OMPTeamsDistributeDirectiveRange = DerivedEntityRange<StmtIterator, OMPTeamsDistributeDirective>;
using OMPTeamsDistributeDirectiveContainingTokenRange = DerivedEntityRange<TokenContextIterator, OMPTeamsDistributeDirective>;
using OMPTeamsDistributeDirectiveContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, OMPTeamsDistributeDirective>;

class OMPTeamsDistributeDirective : public OMPLoopDirective {
 private:
  friend class FragmentImpl;
  friend class OMPLoopDirective;
  friend class OMPLoopBasedDirective;
  friend class OMPExecutableDirective;
  friend class Stmt;
 public:
  inline static OMPTeamsDistributeDirectiveRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static OMPTeamsDistributeDirectiveContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static OMPTeamsDistributeDirectiveContainingStmtRange containing(const Decl &decl);
  static OMPTeamsDistributeDirectiveContainingStmtRange containing(const Stmt &stmt);

  static std::optional<OMPTeamsDistributeDirective> from(const TokenContext &c);
  static std::optional<OMPTeamsDistributeDirective> from(const OMPLoopDirective &parent);
  static std::optional<OMPTeamsDistributeDirective> from(const OMPLoopBasedDirective &parent);
  static std::optional<OMPTeamsDistributeDirective> from(const OMPExecutableDirective &parent);
  static std::optional<OMPTeamsDistributeDirective> from(const Stmt &parent);
};

using OMPTaskLoopSimdDirectiveRange = DerivedEntityRange<StmtIterator, OMPTaskLoopSimdDirective>;
using OMPTaskLoopSimdDirectiveContainingTokenRange = DerivedEntityRange<TokenContextIterator, OMPTaskLoopSimdDirective>;
using OMPTaskLoopSimdDirectiveContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, OMPTaskLoopSimdDirective>;

class OMPTaskLoopSimdDirective : public OMPLoopDirective {
 private:
  friend class FragmentImpl;
  friend class OMPLoopDirective;
  friend class OMPLoopBasedDirective;
  friend class OMPExecutableDirective;
  friend class Stmt;
 public:
  inline static OMPTaskLoopSimdDirectiveRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static OMPTaskLoopSimdDirectiveContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static OMPTaskLoopSimdDirectiveContainingStmtRange containing(const Decl &decl);
  static OMPTaskLoopSimdDirectiveContainingStmtRange containing(const Stmt &stmt);

  static std::optional<OMPTaskLoopSimdDirective> from(const TokenContext &c);
  static std::optional<OMPTaskLoopSimdDirective> from(const OMPLoopDirective &parent);
  static std::optional<OMPTaskLoopSimdDirective> from(const OMPLoopBasedDirective &parent);
  static std::optional<OMPTaskLoopSimdDirective> from(const OMPExecutableDirective &parent);
  static std::optional<OMPTaskLoopSimdDirective> from(const Stmt &parent);
};

using OMPTaskLoopDirectiveRange = DerivedEntityRange<StmtIterator, OMPTaskLoopDirective>;
using OMPTaskLoopDirectiveContainingTokenRange = DerivedEntityRange<TokenContextIterator, OMPTaskLoopDirective>;
using OMPTaskLoopDirectiveContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, OMPTaskLoopDirective>;

class OMPTaskLoopDirective : public OMPLoopDirective {
 private:
  friend class FragmentImpl;
  friend class OMPLoopDirective;
  friend class OMPLoopBasedDirective;
  friend class OMPExecutableDirective;
  friend class Stmt;
 public:
  inline static OMPTaskLoopDirectiveRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static OMPTaskLoopDirectiveContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static OMPTaskLoopDirectiveContainingStmtRange containing(const Decl &decl);
  static OMPTaskLoopDirectiveContainingStmtRange containing(const Stmt &stmt);

  static std::optional<OMPTaskLoopDirective> from(const TokenContext &c);
  static std::optional<OMPTaskLoopDirective> from(const OMPLoopDirective &parent);
  static std::optional<OMPTaskLoopDirective> from(const OMPLoopBasedDirective &parent);
  static std::optional<OMPTaskLoopDirective> from(const OMPExecutableDirective &parent);
  static std::optional<OMPTaskLoopDirective> from(const Stmt &parent);
  bool has_cancel(void) const;
};

using OMPTargetTeamsDistributeSimdDirectiveRange = DerivedEntityRange<StmtIterator, OMPTargetTeamsDistributeSimdDirective>;
using OMPTargetTeamsDistributeSimdDirectiveContainingTokenRange = DerivedEntityRange<TokenContextIterator, OMPTargetTeamsDistributeSimdDirective>;
using OMPTargetTeamsDistributeSimdDirectiveContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, OMPTargetTeamsDistributeSimdDirective>;

class OMPTargetTeamsDistributeSimdDirective : public OMPLoopDirective {
 private:
  friend class FragmentImpl;
  friend class OMPLoopDirective;
  friend class OMPLoopBasedDirective;
  friend class OMPExecutableDirective;
  friend class Stmt;
 public:
  inline static OMPTargetTeamsDistributeSimdDirectiveRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static OMPTargetTeamsDistributeSimdDirectiveContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static OMPTargetTeamsDistributeSimdDirectiveContainingStmtRange containing(const Decl &decl);
  static OMPTargetTeamsDistributeSimdDirectiveContainingStmtRange containing(const Stmt &stmt);

  static std::optional<OMPTargetTeamsDistributeSimdDirective> from(const TokenContext &c);
  static std::optional<OMPTargetTeamsDistributeSimdDirective> from(const OMPLoopDirective &parent);
  static std::optional<OMPTargetTeamsDistributeSimdDirective> from(const OMPLoopBasedDirective &parent);
  static std::optional<OMPTargetTeamsDistributeSimdDirective> from(const OMPExecutableDirective &parent);
  static std::optional<OMPTargetTeamsDistributeSimdDirective> from(const Stmt &parent);
};

using OMPTargetTeamsDistributeParallelForSimdDirectiveRange = DerivedEntityRange<StmtIterator, OMPTargetTeamsDistributeParallelForSimdDirective>;
using OMPTargetTeamsDistributeParallelForSimdDirectiveContainingTokenRange = DerivedEntityRange<TokenContextIterator, OMPTargetTeamsDistributeParallelForSimdDirective>;
using OMPTargetTeamsDistributeParallelForSimdDirectiveContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, OMPTargetTeamsDistributeParallelForSimdDirective>;

class OMPTargetTeamsDistributeParallelForSimdDirective : public OMPLoopDirective {
 private:
  friend class FragmentImpl;
  friend class OMPLoopDirective;
  friend class OMPLoopBasedDirective;
  friend class OMPExecutableDirective;
  friend class Stmt;
 public:
  inline static OMPTargetTeamsDistributeParallelForSimdDirectiveRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static OMPTargetTeamsDistributeParallelForSimdDirectiveContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static OMPTargetTeamsDistributeParallelForSimdDirectiveContainingStmtRange containing(const Decl &decl);
  static OMPTargetTeamsDistributeParallelForSimdDirectiveContainingStmtRange containing(const Stmt &stmt);

  static std::optional<OMPTargetTeamsDistributeParallelForSimdDirective> from(const TokenContext &c);
  static std::optional<OMPTargetTeamsDistributeParallelForSimdDirective> from(const OMPLoopDirective &parent);
  static std::optional<OMPTargetTeamsDistributeParallelForSimdDirective> from(const OMPLoopBasedDirective &parent);
  static std::optional<OMPTargetTeamsDistributeParallelForSimdDirective> from(const OMPExecutableDirective &parent);
  static std::optional<OMPTargetTeamsDistributeParallelForSimdDirective> from(const Stmt &parent);
};

using OMPTargetTeamsDistributeParallelForDirectiveRange = DerivedEntityRange<StmtIterator, OMPTargetTeamsDistributeParallelForDirective>;
using OMPTargetTeamsDistributeParallelForDirectiveContainingTokenRange = DerivedEntityRange<TokenContextIterator, OMPTargetTeamsDistributeParallelForDirective>;
using OMPTargetTeamsDistributeParallelForDirectiveContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, OMPTargetTeamsDistributeParallelForDirective>;

class OMPTargetTeamsDistributeParallelForDirective : public OMPLoopDirective {
 private:
  friend class FragmentImpl;
  friend class OMPLoopDirective;
  friend class OMPLoopBasedDirective;
  friend class OMPExecutableDirective;
  friend class Stmt;
 public:
  inline static OMPTargetTeamsDistributeParallelForDirectiveRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static OMPTargetTeamsDistributeParallelForDirectiveContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static OMPTargetTeamsDistributeParallelForDirectiveContainingStmtRange containing(const Decl &decl);
  static OMPTargetTeamsDistributeParallelForDirectiveContainingStmtRange containing(const Stmt &stmt);

  static std::optional<OMPTargetTeamsDistributeParallelForDirective> from(const TokenContext &c);
  static std::optional<OMPTargetTeamsDistributeParallelForDirective> from(const OMPLoopDirective &parent);
  static std::optional<OMPTargetTeamsDistributeParallelForDirective> from(const OMPLoopBasedDirective &parent);
  static std::optional<OMPTargetTeamsDistributeParallelForDirective> from(const OMPExecutableDirective &parent);
  static std::optional<OMPTargetTeamsDistributeParallelForDirective> from(const Stmt &parent);
  Expr task_reduction_reference_expression(void) const;
  bool has_cancel(void) const;
};

using OMPTargetTeamsDistributeDirectiveRange = DerivedEntityRange<StmtIterator, OMPTargetTeamsDistributeDirective>;
using OMPTargetTeamsDistributeDirectiveContainingTokenRange = DerivedEntityRange<TokenContextIterator, OMPTargetTeamsDistributeDirective>;
using OMPTargetTeamsDistributeDirectiveContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, OMPTargetTeamsDistributeDirective>;

class OMPTargetTeamsDistributeDirective : public OMPLoopDirective {
 private:
  friend class FragmentImpl;
  friend class OMPLoopDirective;
  friend class OMPLoopBasedDirective;
  friend class OMPExecutableDirective;
  friend class Stmt;
 public:
  inline static OMPTargetTeamsDistributeDirectiveRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static OMPTargetTeamsDistributeDirectiveContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static OMPTargetTeamsDistributeDirectiveContainingStmtRange containing(const Decl &decl);
  static OMPTargetTeamsDistributeDirectiveContainingStmtRange containing(const Stmt &stmt);

  static std::optional<OMPTargetTeamsDistributeDirective> from(const TokenContext &c);
  static std::optional<OMPTargetTeamsDistributeDirective> from(const OMPLoopDirective &parent);
  static std::optional<OMPTargetTeamsDistributeDirective> from(const OMPLoopBasedDirective &parent);
  static std::optional<OMPTargetTeamsDistributeDirective> from(const OMPExecutableDirective &parent);
  static std::optional<OMPTargetTeamsDistributeDirective> from(const Stmt &parent);
};

using OMPTargetSimdDirectiveRange = DerivedEntityRange<StmtIterator, OMPTargetSimdDirective>;
using OMPTargetSimdDirectiveContainingTokenRange = DerivedEntityRange<TokenContextIterator, OMPTargetSimdDirective>;
using OMPTargetSimdDirectiveContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, OMPTargetSimdDirective>;

class OMPTargetSimdDirective : public OMPLoopDirective {
 private:
  friend class FragmentImpl;
  friend class OMPLoopDirective;
  friend class OMPLoopBasedDirective;
  friend class OMPExecutableDirective;
  friend class Stmt;
 public:
  inline static OMPTargetSimdDirectiveRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static OMPTargetSimdDirectiveContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static OMPTargetSimdDirectiveContainingStmtRange containing(const Decl &decl);
  static OMPTargetSimdDirectiveContainingStmtRange containing(const Stmt &stmt);

  static std::optional<OMPTargetSimdDirective> from(const TokenContext &c);
  static std::optional<OMPTargetSimdDirective> from(const OMPLoopDirective &parent);
  static std::optional<OMPTargetSimdDirective> from(const OMPLoopBasedDirective &parent);
  static std::optional<OMPTargetSimdDirective> from(const OMPExecutableDirective &parent);
  static std::optional<OMPTargetSimdDirective> from(const Stmt &parent);
};

using OMPTargetParallelForSimdDirectiveRange = DerivedEntityRange<StmtIterator, OMPTargetParallelForSimdDirective>;
using OMPTargetParallelForSimdDirectiveContainingTokenRange = DerivedEntityRange<TokenContextIterator, OMPTargetParallelForSimdDirective>;
using OMPTargetParallelForSimdDirectiveContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, OMPTargetParallelForSimdDirective>;

class OMPTargetParallelForSimdDirective : public OMPLoopDirective {
 private:
  friend class FragmentImpl;
  friend class OMPLoopDirective;
  friend class OMPLoopBasedDirective;
  friend class OMPExecutableDirective;
  friend class Stmt;
 public:
  inline static OMPTargetParallelForSimdDirectiveRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static OMPTargetParallelForSimdDirectiveContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static OMPTargetParallelForSimdDirectiveContainingStmtRange containing(const Decl &decl);
  static OMPTargetParallelForSimdDirectiveContainingStmtRange containing(const Stmt &stmt);

  static std::optional<OMPTargetParallelForSimdDirective> from(const TokenContext &c);
  static std::optional<OMPTargetParallelForSimdDirective> from(const OMPLoopDirective &parent);
  static std::optional<OMPTargetParallelForSimdDirective> from(const OMPLoopBasedDirective &parent);
  static std::optional<OMPTargetParallelForSimdDirective> from(const OMPExecutableDirective &parent);
  static std::optional<OMPTargetParallelForSimdDirective> from(const Stmt &parent);
};

using OMPTargetParallelForDirectiveRange = DerivedEntityRange<StmtIterator, OMPTargetParallelForDirective>;
using OMPTargetParallelForDirectiveContainingTokenRange = DerivedEntityRange<TokenContextIterator, OMPTargetParallelForDirective>;
using OMPTargetParallelForDirectiveContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, OMPTargetParallelForDirective>;

class OMPTargetParallelForDirective : public OMPLoopDirective {
 private:
  friend class FragmentImpl;
  friend class OMPLoopDirective;
  friend class OMPLoopBasedDirective;
  friend class OMPExecutableDirective;
  friend class Stmt;
 public:
  inline static OMPTargetParallelForDirectiveRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static OMPTargetParallelForDirectiveContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static OMPTargetParallelForDirectiveContainingStmtRange containing(const Decl &decl);
  static OMPTargetParallelForDirectiveContainingStmtRange containing(const Stmt &stmt);

  static std::optional<OMPTargetParallelForDirective> from(const TokenContext &c);
  static std::optional<OMPTargetParallelForDirective> from(const OMPLoopDirective &parent);
  static std::optional<OMPTargetParallelForDirective> from(const OMPLoopBasedDirective &parent);
  static std::optional<OMPTargetParallelForDirective> from(const OMPExecutableDirective &parent);
  static std::optional<OMPTargetParallelForDirective> from(const Stmt &parent);
  Expr task_reduction_reference_expression(void) const;
  bool has_cancel(void) const;
};

using OMPSimdDirectiveRange = DerivedEntityRange<StmtIterator, OMPSimdDirective>;
using OMPSimdDirectiveContainingTokenRange = DerivedEntityRange<TokenContextIterator, OMPSimdDirective>;
using OMPSimdDirectiveContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, OMPSimdDirective>;

class OMPSimdDirective : public OMPLoopDirective {
 private:
  friend class FragmentImpl;
  friend class OMPLoopDirective;
  friend class OMPLoopBasedDirective;
  friend class OMPExecutableDirective;
  friend class Stmt;
 public:
  inline static OMPSimdDirectiveRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static OMPSimdDirectiveContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static OMPSimdDirectiveContainingStmtRange containing(const Decl &decl);
  static OMPSimdDirectiveContainingStmtRange containing(const Stmt &stmt);

  static std::optional<OMPSimdDirective> from(const TokenContext &c);
  static std::optional<OMPSimdDirective> from(const OMPLoopDirective &parent);
  static std::optional<OMPSimdDirective> from(const OMPLoopBasedDirective &parent);
  static std::optional<OMPSimdDirective> from(const OMPExecutableDirective &parent);
  static std::optional<OMPSimdDirective> from(const Stmt &parent);
};

using OMPParallelMasterTaskLoopSimdDirectiveRange = DerivedEntityRange<StmtIterator, OMPParallelMasterTaskLoopSimdDirective>;
using OMPParallelMasterTaskLoopSimdDirectiveContainingTokenRange = DerivedEntityRange<TokenContextIterator, OMPParallelMasterTaskLoopSimdDirective>;
using OMPParallelMasterTaskLoopSimdDirectiveContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, OMPParallelMasterTaskLoopSimdDirective>;

class OMPParallelMasterTaskLoopSimdDirective : public OMPLoopDirective {
 private:
  friend class FragmentImpl;
  friend class OMPLoopDirective;
  friend class OMPLoopBasedDirective;
  friend class OMPExecutableDirective;
  friend class Stmt;
 public:
  inline static OMPParallelMasterTaskLoopSimdDirectiveRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static OMPParallelMasterTaskLoopSimdDirectiveContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static OMPParallelMasterTaskLoopSimdDirectiveContainingStmtRange containing(const Decl &decl);
  static OMPParallelMasterTaskLoopSimdDirectiveContainingStmtRange containing(const Stmt &stmt);

  static std::optional<OMPParallelMasterTaskLoopSimdDirective> from(const TokenContext &c);
  static std::optional<OMPParallelMasterTaskLoopSimdDirective> from(const OMPLoopDirective &parent);
  static std::optional<OMPParallelMasterTaskLoopSimdDirective> from(const OMPLoopBasedDirective &parent);
  static std::optional<OMPParallelMasterTaskLoopSimdDirective> from(const OMPExecutableDirective &parent);
  static std::optional<OMPParallelMasterTaskLoopSimdDirective> from(const Stmt &parent);
};

using OMPParallelMasterTaskLoopDirectiveRange = DerivedEntityRange<StmtIterator, OMPParallelMasterTaskLoopDirective>;
using OMPParallelMasterTaskLoopDirectiveContainingTokenRange = DerivedEntityRange<TokenContextIterator, OMPParallelMasterTaskLoopDirective>;
using OMPParallelMasterTaskLoopDirectiveContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, OMPParallelMasterTaskLoopDirective>;

class OMPParallelMasterTaskLoopDirective : public OMPLoopDirective {
 private:
  friend class FragmentImpl;
  friend class OMPLoopDirective;
  friend class OMPLoopBasedDirective;
  friend class OMPExecutableDirective;
  friend class Stmt;
 public:
  inline static OMPParallelMasterTaskLoopDirectiveRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static OMPParallelMasterTaskLoopDirectiveContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static OMPParallelMasterTaskLoopDirectiveContainingStmtRange containing(const Decl &decl);
  static OMPParallelMasterTaskLoopDirectiveContainingStmtRange containing(const Stmt &stmt);

  static std::optional<OMPParallelMasterTaskLoopDirective> from(const TokenContext &c);
  static std::optional<OMPParallelMasterTaskLoopDirective> from(const OMPLoopDirective &parent);
  static std::optional<OMPParallelMasterTaskLoopDirective> from(const OMPLoopBasedDirective &parent);
  static std::optional<OMPParallelMasterTaskLoopDirective> from(const OMPExecutableDirective &parent);
  static std::optional<OMPParallelMasterTaskLoopDirective> from(const Stmt &parent);
  bool has_cancel(void) const;
};

using OMPParallelForSimdDirectiveRange = DerivedEntityRange<StmtIterator, OMPParallelForSimdDirective>;
using OMPParallelForSimdDirectiveContainingTokenRange = DerivedEntityRange<TokenContextIterator, OMPParallelForSimdDirective>;
using OMPParallelForSimdDirectiveContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, OMPParallelForSimdDirective>;

class OMPParallelForSimdDirective : public OMPLoopDirective {
 private:
  friend class FragmentImpl;
  friend class OMPLoopDirective;
  friend class OMPLoopBasedDirective;
  friend class OMPExecutableDirective;
  friend class Stmt;
 public:
  inline static OMPParallelForSimdDirectiveRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static OMPParallelForSimdDirectiveContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static OMPParallelForSimdDirectiveContainingStmtRange containing(const Decl &decl);
  static OMPParallelForSimdDirectiveContainingStmtRange containing(const Stmt &stmt);

  static std::optional<OMPParallelForSimdDirective> from(const TokenContext &c);
  static std::optional<OMPParallelForSimdDirective> from(const OMPLoopDirective &parent);
  static std::optional<OMPParallelForSimdDirective> from(const OMPLoopBasedDirective &parent);
  static std::optional<OMPParallelForSimdDirective> from(const OMPExecutableDirective &parent);
  static std::optional<OMPParallelForSimdDirective> from(const Stmt &parent);
};

using OMPParallelForDirectiveRange = DerivedEntityRange<StmtIterator, OMPParallelForDirective>;
using OMPParallelForDirectiveContainingTokenRange = DerivedEntityRange<TokenContextIterator, OMPParallelForDirective>;
using OMPParallelForDirectiveContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, OMPParallelForDirective>;

class OMPParallelForDirective : public OMPLoopDirective {
 private:
  friend class FragmentImpl;
  friend class OMPLoopDirective;
  friend class OMPLoopBasedDirective;
  friend class OMPExecutableDirective;
  friend class Stmt;
 public:
  inline static OMPParallelForDirectiveRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static OMPParallelForDirectiveContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static OMPParallelForDirectiveContainingStmtRange containing(const Decl &decl);
  static OMPParallelForDirectiveContainingStmtRange containing(const Stmt &stmt);

  static std::optional<OMPParallelForDirective> from(const TokenContext &c);
  static std::optional<OMPParallelForDirective> from(const OMPLoopDirective &parent);
  static std::optional<OMPParallelForDirective> from(const OMPLoopBasedDirective &parent);
  static std::optional<OMPParallelForDirective> from(const OMPExecutableDirective &parent);
  static std::optional<OMPParallelForDirective> from(const Stmt &parent);
  Expr task_reduction_reference_expression(void) const;
  bool has_cancel(void) const;
};

using OMPMasterTaskLoopSimdDirectiveRange = DerivedEntityRange<StmtIterator, OMPMasterTaskLoopSimdDirective>;
using OMPMasterTaskLoopSimdDirectiveContainingTokenRange = DerivedEntityRange<TokenContextIterator, OMPMasterTaskLoopSimdDirective>;
using OMPMasterTaskLoopSimdDirectiveContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, OMPMasterTaskLoopSimdDirective>;

class OMPMasterTaskLoopSimdDirective : public OMPLoopDirective {
 private:
  friend class FragmentImpl;
  friend class OMPLoopDirective;
  friend class OMPLoopBasedDirective;
  friend class OMPExecutableDirective;
  friend class Stmt;
 public:
  inline static OMPMasterTaskLoopSimdDirectiveRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static OMPMasterTaskLoopSimdDirectiveContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static OMPMasterTaskLoopSimdDirectiveContainingStmtRange containing(const Decl &decl);
  static OMPMasterTaskLoopSimdDirectiveContainingStmtRange containing(const Stmt &stmt);

  static std::optional<OMPMasterTaskLoopSimdDirective> from(const TokenContext &c);
  static std::optional<OMPMasterTaskLoopSimdDirective> from(const OMPLoopDirective &parent);
  static std::optional<OMPMasterTaskLoopSimdDirective> from(const OMPLoopBasedDirective &parent);
  static std::optional<OMPMasterTaskLoopSimdDirective> from(const OMPExecutableDirective &parent);
  static std::optional<OMPMasterTaskLoopSimdDirective> from(const Stmt &parent);
};

using OMPMasterTaskLoopDirectiveRange = DerivedEntityRange<StmtIterator, OMPMasterTaskLoopDirective>;
using OMPMasterTaskLoopDirectiveContainingTokenRange = DerivedEntityRange<TokenContextIterator, OMPMasterTaskLoopDirective>;
using OMPMasterTaskLoopDirectiveContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, OMPMasterTaskLoopDirective>;

class OMPMasterTaskLoopDirective : public OMPLoopDirective {
 private:
  friend class FragmentImpl;
  friend class OMPLoopDirective;
  friend class OMPLoopBasedDirective;
  friend class OMPExecutableDirective;
  friend class Stmt;
 public:
  inline static OMPMasterTaskLoopDirectiveRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static OMPMasterTaskLoopDirectiveContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static OMPMasterTaskLoopDirectiveContainingStmtRange containing(const Decl &decl);
  static OMPMasterTaskLoopDirectiveContainingStmtRange containing(const Stmt &stmt);

  static std::optional<OMPMasterTaskLoopDirective> from(const TokenContext &c);
  static std::optional<OMPMasterTaskLoopDirective> from(const OMPLoopDirective &parent);
  static std::optional<OMPMasterTaskLoopDirective> from(const OMPLoopBasedDirective &parent);
  static std::optional<OMPMasterTaskLoopDirective> from(const OMPExecutableDirective &parent);
  static std::optional<OMPMasterTaskLoopDirective> from(const Stmt &parent);
  bool has_cancel(void) const;
};

using OMPInteropDirectiveRange = DerivedEntityRange<StmtIterator, OMPInteropDirective>;
using OMPInteropDirectiveContainingTokenRange = DerivedEntityRange<TokenContextIterator, OMPInteropDirective>;
using OMPInteropDirectiveContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, OMPInteropDirective>;

class OMPInteropDirective : public OMPExecutableDirective {
 private:
  friend class FragmentImpl;
  friend class OMPExecutableDirective;
  friend class Stmt;
 public:
  inline static OMPInteropDirectiveRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static OMPInteropDirectiveContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static OMPInteropDirectiveContainingStmtRange containing(const Decl &decl);
  static OMPInteropDirectiveContainingStmtRange containing(const Stmt &stmt);

  static std::optional<OMPInteropDirective> from(const TokenContext &c);
  static std::optional<OMPInteropDirective> from(const OMPExecutableDirective &parent);
  static std::optional<OMPInteropDirective> from(const Stmt &parent);
};

using OMPFlushDirectiveRange = DerivedEntityRange<StmtIterator, OMPFlushDirective>;
using OMPFlushDirectiveContainingTokenRange = DerivedEntityRange<TokenContextIterator, OMPFlushDirective>;
using OMPFlushDirectiveContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, OMPFlushDirective>;

class OMPFlushDirective : public OMPExecutableDirective {
 private:
  friend class FragmentImpl;
  friend class OMPExecutableDirective;
  friend class Stmt;
 public:
  inline static OMPFlushDirectiveRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static OMPFlushDirectiveContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static OMPFlushDirectiveContainingStmtRange containing(const Decl &decl);
  static OMPFlushDirectiveContainingStmtRange containing(const Stmt &stmt);

  static std::optional<OMPFlushDirective> from(const TokenContext &c);
  static std::optional<OMPFlushDirective> from(const OMPExecutableDirective &parent);
  static std::optional<OMPFlushDirective> from(const Stmt &parent);
};

using OMPCanonicalLoopRange = DerivedEntityRange<StmtIterator, OMPCanonicalLoop>;
using OMPCanonicalLoopContainingTokenRange = DerivedEntityRange<TokenContextIterator, OMPCanonicalLoop>;
using OMPCanonicalLoopContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, OMPCanonicalLoop>;

class OMPCanonicalLoop : public Stmt {
 private:
  friend class FragmentImpl;
  friend class Stmt;
 public:
  inline static OMPCanonicalLoopRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static OMPCanonicalLoopContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static OMPCanonicalLoopContainingStmtRange containing(const Decl &decl);
  static OMPCanonicalLoopContainingStmtRange containing(const Stmt &stmt);

  static std::optional<OMPCanonicalLoop> from(const TokenContext &c);
  static std::optional<OMPCanonicalLoop> from(const Stmt &parent);
  CapturedStmt distance_func(void) const;
  Stmt loop_statement(void) const;
  CapturedStmt loop_variable_func(void) const;
  DeclRefExpr loop_variable_reference(void) const;
};

using NullStmtRange = DerivedEntityRange<StmtIterator, NullStmt>;
using NullStmtContainingTokenRange = DerivedEntityRange<TokenContextIterator, NullStmt>;
using NullStmtContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, NullStmt>;

class NullStmt : public Stmt {
 private:
  friend class FragmentImpl;
  friend class Stmt;
 public:
  inline static NullStmtRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static NullStmtContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static NullStmtContainingStmtRange containing(const Decl &decl);
  static NullStmtContainingStmtRange containing(const Stmt &stmt);

  static std::optional<NullStmt> from(const TokenContext &c);
  static std::optional<NullStmt> from(const Stmt &parent);
  Token semi_token(void) const;
  bool has_leading_empty_macro(void) const;
};

using MSDependentExistsStmtRange = DerivedEntityRange<StmtIterator, MSDependentExistsStmt>;
using MSDependentExistsStmtContainingTokenRange = DerivedEntityRange<TokenContextIterator, MSDependentExistsStmt>;
using MSDependentExistsStmtContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, MSDependentExistsStmt>;

class MSDependentExistsStmt : public Stmt {
 private:
  friend class FragmentImpl;
  friend class Stmt;
 public:
  inline static MSDependentExistsStmtRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static MSDependentExistsStmtContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static MSDependentExistsStmtContainingStmtRange containing(const Decl &decl);
  static MSDependentExistsStmtContainingStmtRange containing(const Stmt &stmt);

  static std::optional<MSDependentExistsStmt> from(const TokenContext &c);
  static std::optional<MSDependentExistsStmt> from(const Stmt &parent);
  Token keyword_token(void) const;
  CompoundStmt sub_statement(void) const;
  bool is_if_exists(void) const;
  bool is_if_not_exists(void) const;
};

using IndirectGotoStmtRange = DerivedEntityRange<StmtIterator, IndirectGotoStmt>;
using IndirectGotoStmtContainingTokenRange = DerivedEntityRange<TokenContextIterator, IndirectGotoStmt>;
using IndirectGotoStmtContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, IndirectGotoStmt>;

class IndirectGotoStmt : public Stmt {
 private:
  friend class FragmentImpl;
  friend class Stmt;
 public:
  inline static IndirectGotoStmtRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static IndirectGotoStmtContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static IndirectGotoStmtContainingStmtRange containing(const Decl &decl);
  static IndirectGotoStmtContainingStmtRange containing(const Stmt &stmt);

  static std::optional<IndirectGotoStmt> from(const TokenContext &c);
  static std::optional<IndirectGotoStmt> from(const Stmt &parent);
  LabelDecl constant_target(void) const;
  Token goto_token(void) const;
  Token star_token(void) const;
  Expr target(void) const;
};

using IfStmtRange = DerivedEntityRange<StmtIterator, IfStmt>;
using IfStmtContainingTokenRange = DerivedEntityRange<TokenContextIterator, IfStmt>;
using IfStmtContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, IfStmt>;

class IfStmt : public Stmt {
 private:
  friend class FragmentImpl;
  friend class Stmt;
 public:
  inline static IfStmtRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static IfStmtContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static IfStmtContainingStmtRange containing(const Decl &decl);
  static IfStmtContainingStmtRange containing(const Stmt &stmt);

  static std::optional<IfStmt> from(const TokenContext &c);
  static std::optional<IfStmt> from(const Stmt &parent);
  Expr condition(void) const;
  std::optional<VarDecl> condition_variable(void) const;
  std::optional<DeclStmt> condition_variable_declaration_statement(void) const;
  std::optional<Stmt> else_(void) const;
  Token else_token(void) const;
  Token if_token(void) const;
  std::optional<Stmt> initializer(void) const;
  Token l_paren_token(void) const;
  Token r_paren_token(void) const;
  Stmt then(void) const;
  bool has_else_storage(void) const;
  bool has_initializer_storage(void) const;
  bool has_variable_storage(void) const;
  bool is_constexpr(void) const;
  bool is_obj_c_availability_check(void) const;
};

using GotoStmtRange = DerivedEntityRange<StmtIterator, GotoStmt>;
using GotoStmtContainingTokenRange = DerivedEntityRange<TokenContextIterator, GotoStmt>;
using GotoStmtContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, GotoStmt>;

class GotoStmt : public Stmt {
 private:
  friend class FragmentImpl;
  friend class Stmt;
 public:
  inline static GotoStmtRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static GotoStmtContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static GotoStmtContainingStmtRange containing(const Decl &decl);
  static GotoStmtContainingStmtRange containing(const Stmt &stmt);

  static std::optional<GotoStmt> from(const TokenContext &c);
  static std::optional<GotoStmt> from(const Stmt &parent);
  Token goto_token(void) const;
  LabelDecl label(void) const;
  Token label_token(void) const;
};

using ForStmtRange = DerivedEntityRange<StmtIterator, ForStmt>;
using ForStmtContainingTokenRange = DerivedEntityRange<TokenContextIterator, ForStmt>;
using ForStmtContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, ForStmt>;

class ForStmt : public Stmt {
 private:
  friend class FragmentImpl;
  friend class Stmt;
 public:
  inline static ForStmtRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static ForStmtContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static ForStmtContainingStmtRange containing(const Decl &decl);
  static ForStmtContainingStmtRange containing(const Stmt &stmt);

  static std::optional<ForStmt> from(const TokenContext &c);
  static std::optional<ForStmt> from(const Stmt &parent);
  Stmt body(void) const;
  std::optional<Expr> condition(void) const;
  std::optional<VarDecl> condition_variable(void) const;
  std::optional<DeclStmt> condition_variable_declaration_statement(void) const;
  Token for_token(void) const;
  std::optional<Expr> increment(void) const;
  std::optional<Stmt> initializer(void) const;
  Token l_paren_token(void) const;
  Token r_paren_token(void) const;
};

using DoStmtRange = DerivedEntityRange<StmtIterator, DoStmt>;
using DoStmtContainingTokenRange = DerivedEntityRange<TokenContextIterator, DoStmt>;
using DoStmtContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, DoStmt>;

class DoStmt : public Stmt {
 private:
  friend class FragmentImpl;
  friend class Stmt;
 public:
  inline static DoStmtRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static DoStmtContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static DoStmtContainingStmtRange containing(const Decl &decl);
  static DoStmtContainingStmtRange containing(const Stmt &stmt);

  static std::optional<DoStmt> from(const TokenContext &c);
  static std::optional<DoStmt> from(const Stmt &parent);
  Stmt body(void) const;
  Expr condition(void) const;
  Token do_token(void) const;
  Token r_paren_token(void) const;
  Token while_token(void) const;
};

using DeclStmtRange = DerivedEntityRange<StmtIterator, DeclStmt>;
using DeclStmtContainingTokenRange = DerivedEntityRange<TokenContextIterator, DeclStmt>;
using DeclStmtContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, DeclStmt>;

class DeclStmt : public Stmt {
 private:
  friend class FragmentImpl;
  friend class Stmt;
 public:
  inline static DeclStmtRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static DeclStmtContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static DeclStmtContainingStmtRange containing(const Decl &decl);
  static DeclStmtContainingStmtRange containing(const Stmt &stmt);

  static std::optional<DeclStmt> from(const TokenContext &c);
  static std::optional<DeclStmt> from(const Stmt &parent);
  std::vector<Decl> declarations(void) const;
  std::optional<Decl> single_declaration(void) const;
  bool is_single_declaration(void) const;
};

using CoroutineBodyStmtRange = DerivedEntityRange<StmtIterator, CoroutineBodyStmt>;
using CoroutineBodyStmtContainingTokenRange = DerivedEntityRange<TokenContextIterator, CoroutineBodyStmt>;
using CoroutineBodyStmtContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, CoroutineBodyStmt>;

class CoroutineBodyStmt : public Stmt {
 private:
  friend class FragmentImpl;
  friend class Stmt;
 public:
  inline static CoroutineBodyStmtRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static CoroutineBodyStmtContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static CoroutineBodyStmtContainingStmtRange containing(const Decl &decl);
  static CoroutineBodyStmtContainingStmtRange containing(const Stmt &stmt);

  static std::optional<CoroutineBodyStmt> from(const TokenContext &c);
  static std::optional<CoroutineBodyStmt> from(const Stmt &parent);
  Expr allocate(void) const;
  Stmt body(void) const;
  Expr deallocate(void) const;
  Stmt exception_handler(void) const;
  Stmt fallthrough_handler(void) const;
  Stmt final_suspend_statement(void) const;
  Stmt initializer_suspend_statement(void) const;
  std::vector<Stmt> parameter_moves(void) const;
  VarDecl promise_declaration(void) const;
  Stmt promise_declaration_statement(void) const;
  Stmt result_declaration(void) const;
  Stmt return_statement(void) const;
  Stmt return_statement_on_alloc_failure(void) const;
  Expr return_value_initializer(void) const;
  bool has_dependent_promise_type(void) const;
};

using CoreturnStmtRange = DerivedEntityRange<StmtIterator, CoreturnStmt>;
using CoreturnStmtContainingTokenRange = DerivedEntityRange<TokenContextIterator, CoreturnStmt>;
using CoreturnStmtContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, CoreturnStmt>;

class CoreturnStmt : public Stmt {
 private:
  friend class FragmentImpl;
  friend class Stmt;
 public:
  inline static CoreturnStmtRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static CoreturnStmtContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static CoreturnStmtContainingStmtRange containing(const Decl &decl);
  static CoreturnStmtContainingStmtRange containing(const Stmt &stmt);

  static std::optional<CoreturnStmt> from(const TokenContext &c);
  static std::optional<CoreturnStmt> from(const Stmt &parent);
  Token keyword_token(void) const;
  Expr operand(void) const;
  Expr promise_call(void) const;
  bool is_implicit(void) const;
};

using ContinueStmtRange = DerivedEntityRange<StmtIterator, ContinueStmt>;
using ContinueStmtContainingTokenRange = DerivedEntityRange<TokenContextIterator, ContinueStmt>;
using ContinueStmtContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, ContinueStmt>;

class ContinueStmt : public Stmt {
 private:
  friend class FragmentImpl;
  friend class Stmt;
 public:
  inline static ContinueStmtRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static ContinueStmtContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static ContinueStmtContainingStmtRange containing(const Decl &decl);
  static ContinueStmtContainingStmtRange containing(const Stmt &stmt);

  static std::optional<ContinueStmt> from(const TokenContext &c);
  static std::optional<ContinueStmt> from(const Stmt &parent);
  Token continue_token(void) const;
};

using CompoundStmtRange = DerivedEntityRange<StmtIterator, CompoundStmt>;
using CompoundStmtContainingTokenRange = DerivedEntityRange<TokenContextIterator, CompoundStmt>;
using CompoundStmtContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, CompoundStmt>;

class CompoundStmt : public Stmt {
 private:
  friend class FragmentImpl;
  friend class Stmt;
 public:
  inline static CompoundStmtRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static CompoundStmtContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static CompoundStmtContainingStmtRange containing(const Decl &decl);
  static CompoundStmtContainingStmtRange containing(const Stmt &stmt);

  static std::optional<CompoundStmt> from(const TokenContext &c);
  static std::optional<CompoundStmt> from(const Stmt &parent);
  Token left_brace_token(void) const;
  Token right_brace_token(void) const;
  std::optional<Stmt> statement_expression_result(void) const;
};

using CapturedStmtRange = DerivedEntityRange<StmtIterator, CapturedStmt>;
using CapturedStmtContainingTokenRange = DerivedEntityRange<TokenContextIterator, CapturedStmt>;
using CapturedStmtContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, CapturedStmt>;

class CapturedStmt : public Stmt {
 private:
  friend class FragmentImpl;
  friend class Stmt;
 public:
  inline static CapturedStmtRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static CapturedStmtContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static CapturedStmtContainingStmtRange containing(const Decl &decl);
  static CapturedStmtContainingStmtRange containing(const Stmt &stmt);

  static std::optional<CapturedStmt> from(const TokenContext &c);
  static std::optional<CapturedStmt> from(const Stmt &parent);
  CapturedDecl captured_declaration(void) const;
  RecordDecl captured_record_declaration(void) const;
  CapturedRegionKind captured_region_kind(void) const;
  Stmt captured_statement(void) const;
};

using CXXTryStmtRange = DerivedEntityRange<StmtIterator, CXXTryStmt>;
using CXXTryStmtContainingTokenRange = DerivedEntityRange<TokenContextIterator, CXXTryStmt>;
using CXXTryStmtContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, CXXTryStmt>;

class CXXTryStmt : public Stmt {
 private:
  friend class FragmentImpl;
  friend class Stmt;
 public:
  inline static CXXTryStmtRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static CXXTryStmtContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static CXXTryStmtContainingStmtRange containing(const Decl &decl);
  static CXXTryStmtContainingStmtRange containing(const Stmt &stmt);

  static std::optional<CXXTryStmt> from(const TokenContext &c);
  static std::optional<CXXTryStmt> from(const Stmt &parent);
  CompoundStmt try_block(void) const;
  Token try_token(void) const;
  std::vector<CXXCatchStmt> handlers(void) const;
};

using CXXForRangeStmtRange = DerivedEntityRange<StmtIterator, CXXForRangeStmt>;
using CXXForRangeStmtContainingTokenRange = DerivedEntityRange<TokenContextIterator, CXXForRangeStmt>;
using CXXForRangeStmtContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, CXXForRangeStmt>;

class CXXForRangeStmt : public Stmt {
 private:
  friend class FragmentImpl;
  friend class Stmt;
 public:
  inline static CXXForRangeStmtRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static CXXForRangeStmtContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static CXXForRangeStmtContainingStmtRange containing(const Decl &decl);
  static CXXForRangeStmtContainingStmtRange containing(const Stmt &stmt);

  static std::optional<CXXForRangeStmt> from(const TokenContext &c);
  static std::optional<CXXForRangeStmt> from(const Stmt &parent);
  DeclStmt begin_statement(void) const;
  Stmt body(void) const;
  Token coawait_token(void) const;
  Token colon_token(void) const;
  Expr condition(void) const;
  DeclStmt end_statement(void) const;
  Token for_token(void) const;
  Expr increment(void) const;
  Stmt initializer(void) const;
  DeclStmt loop_variable_statement(void) const;
  VarDecl loop_variable(void) const;
  Token r_paren_token(void) const;
  Expr range_initializer(void) const;
  DeclStmt range_statement(void) const;
};

using CXXCatchStmtRange = DerivedEntityRange<StmtIterator, CXXCatchStmt>;
using CXXCatchStmtContainingTokenRange = DerivedEntityRange<TokenContextIterator, CXXCatchStmt>;
using CXXCatchStmtContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, CXXCatchStmt>;

class CXXCatchStmt : public Stmt {
 private:
  friend class FragmentImpl;
  friend class Stmt;
 public:
  inline static CXXCatchStmtRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static CXXCatchStmtContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static CXXCatchStmtContainingStmtRange containing(const Decl &decl);
  static CXXCatchStmtContainingStmtRange containing(const Stmt &stmt);

  static std::optional<CXXCatchStmt> from(const TokenContext &c);
  static std::optional<CXXCatchStmt> from(const Stmt &parent);
  Token catch_token(void) const;
  VarDecl exception_declaration(void) const;
  Stmt handler_block(void) const;
};

using BreakStmtRange = DerivedEntityRange<StmtIterator, BreakStmt>;
using BreakStmtContainingTokenRange = DerivedEntityRange<TokenContextIterator, BreakStmt>;
using BreakStmtContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, BreakStmt>;

class BreakStmt : public Stmt {
 private:
  friend class FragmentImpl;
  friend class Stmt;
 public:
  inline static BreakStmtRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static BreakStmtContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static BreakStmtContainingStmtRange containing(const Decl &decl);
  static BreakStmtContainingStmtRange containing(const Stmt &stmt);

  static std::optional<BreakStmt> from(const TokenContext &c);
  static std::optional<BreakStmt> from(const Stmt &parent);
  Token break_token(void) const;
};

using AsmStmtRange = DerivedEntityRange<StmtIterator, AsmStmt>;
using AsmStmtContainingTokenRange = DerivedEntityRange<TokenContextIterator, AsmStmt>;
using AsmStmtContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, AsmStmt>;

class AsmStmt : public Stmt {
 private:
  friend class FragmentImpl;
  friend class Stmt;
 public:
  inline static AsmStmtRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static AsmStmtContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static AsmStmtContainingStmtRange containing(const Decl &decl);
  static AsmStmtContainingStmtRange containing(const Stmt &stmt);

  static std::optional<AsmStmt> from(const TokenContext &c);
  static std::optional<AsmStmt> from(const Stmt &parent);
  std::string_view generate_assembly_string(void) const;
  Token assembly_token(void) const;
  std::vector<Expr> inputs(void) const;
  bool is_simple(void) const;
  bool is_volatile(void) const;
  std::vector<Expr> outputs(void) const;
  std::vector<std::string_view> output_constraints(void) const;
  std::vector<Expr> output_expressions(void) const;
  std::vector<std::string_view> input_constraints(void) const;
  std::vector<Expr> input_expressions(void) const;
  std::vector<std::string_view> clobbers(void) const;
};

using MSAsmStmtRange = DerivedEntityRange<StmtIterator, MSAsmStmt>;
using MSAsmStmtContainingTokenRange = DerivedEntityRange<TokenContextIterator, MSAsmStmt>;
using MSAsmStmtContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, MSAsmStmt>;

class MSAsmStmt : public AsmStmt {
 private:
  friend class FragmentImpl;
  friend class AsmStmt;
  friend class Stmt;
 public:
  inline static MSAsmStmtRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static MSAsmStmtContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static MSAsmStmtContainingStmtRange containing(const Decl &decl);
  static MSAsmStmtContainingStmtRange containing(const Stmt &stmt);

  static std::optional<MSAsmStmt> from(const TokenContext &c);
  static std::optional<MSAsmStmt> from(const AsmStmt &parent);
  static std::optional<MSAsmStmt> from(const Stmt &parent);
  std::vector<std::string_view> all_constraints(void) const;
  std::vector<Expr> all_expressions(void) const;
  std::string_view assembly_string(void) const;
  Token l_brace_token(void) const;
  bool has_braces(void) const;
};

using GCCAsmStmtRange = DerivedEntityRange<StmtIterator, GCCAsmStmt>;
using GCCAsmStmtContainingTokenRange = DerivedEntityRange<TokenContextIterator, GCCAsmStmt>;
using GCCAsmStmtContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, GCCAsmStmt>;

class GCCAsmStmt : public AsmStmt {
 private:
  friend class FragmentImpl;
  friend class AsmStmt;
  friend class Stmt;
 public:
  inline static GCCAsmStmtRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static GCCAsmStmtContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static GCCAsmStmtContainingStmtRange containing(const Decl &decl);
  static GCCAsmStmtContainingStmtRange containing(const Stmt &stmt);

  static std::optional<GCCAsmStmt> from(const TokenContext &c);
  static std::optional<GCCAsmStmt> from(const AsmStmt &parent);
  static std::optional<GCCAsmStmt> from(const Stmt &parent);
  StringLiteral assembly_string(void) const;
  Token r_paren_token(void) const;
  bool is_assembly_goto(void) const;
  std::vector<AddrLabelExpr> labels(void) const;
  std::vector<StringLiteral> output_constraint_literals(void) const;
  std::vector<std::string_view> output_names(void) const;
  std::vector<StringLiteral> input_constraint_literals(void) const;
  std::vector<std::string_view> input_names(void) const;
  std::vector<StringLiteral> clobber_string_literals(void) const;
  std::vector<AddrLabelExpr> label_expressions(void) const;
  std::vector<std::string_view> label_names(void) const;
};

using WhileStmtRange = DerivedEntityRange<StmtIterator, WhileStmt>;
using WhileStmtContainingTokenRange = DerivedEntityRange<TokenContextIterator, WhileStmt>;
using WhileStmtContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, WhileStmt>;

class WhileStmt : public Stmt {
 private:
  friend class FragmentImpl;
  friend class Stmt;
 public:
  inline static WhileStmtRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static WhileStmtContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static WhileStmtContainingStmtRange containing(const Decl &decl);
  static WhileStmtContainingStmtRange containing(const Stmt &stmt);

  static std::optional<WhileStmt> from(const TokenContext &c);
  static std::optional<WhileStmt> from(const Stmt &parent);
  Stmt body(void) const;
  Expr condition(void) const;
  std::optional<VarDecl> condition_variable(void) const;
  std::optional<DeclStmt> condition_variable_declaration_statement(void) const;
  Token l_paren_token(void) const;
  Token r_paren_token(void) const;
  Token while_token(void) const;
  bool has_variable_storage(void) const;
};

using ValueStmtRange = DerivedEntityRange<StmtIterator, ValueStmt>;
using ValueStmtContainingTokenRange = DerivedEntityRange<TokenContextIterator, ValueStmt>;
using ValueStmtContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, ValueStmt>;

class ValueStmt : public Stmt {
 private:
  friend class FragmentImpl;
  friend class Stmt;
 public:
  inline static ValueStmtRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static ValueStmtContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static ValueStmtContainingStmtRange containing(const Decl &decl);
  static ValueStmtContainingStmtRange containing(const Stmt &stmt);

  static std::optional<ValueStmt> from(const TokenContext &c);
  static std::optional<ValueStmt> from(const Stmt &parent);
  std::optional<Expr> expression_statement(void) const;
};

using LabelStmtRange = DerivedEntityRange<StmtIterator, LabelStmt>;
using LabelStmtContainingTokenRange = DerivedEntityRange<TokenContextIterator, LabelStmt>;
using LabelStmtContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, LabelStmt>;

class LabelStmt : public ValueStmt {
 private:
  friend class FragmentImpl;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static LabelStmtRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static LabelStmtContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static LabelStmtContainingStmtRange containing(const Decl &decl);
  static LabelStmtContainingStmtRange containing(const Stmt &stmt);

  static std::optional<LabelStmt> from(const TokenContext &c);
  static std::optional<LabelStmt> from(const ValueStmt &parent);
  static std::optional<LabelStmt> from(const Stmt &parent);
  LabelDecl declaration(void) const;
  Token identifier_token(void) const;
  std::string_view name(void) const;
  Stmt sub_statement(void) const;
  bool is_side_entry(void) const;
};

using ExprRange = DerivedEntityRange<StmtIterator, Expr>;
using ExprContainingTokenRange = DerivedEntityRange<TokenContextIterator, Expr>;
using ExprContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, Expr>;

class Expr : public ValueStmt {
 private:
  friend class FragmentImpl;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static ExprRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static ExprContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static ExprContainingStmtRange containing(const Decl &decl);
  static ExprContainingStmtRange containing(const Stmt &stmt);

  static std::optional<Expr> from(const TokenContext &c);
  static std::optional<Expr> from(const ValueStmt &parent);
  static std::optional<Expr> from(const Stmt &parent);
  bool has_side_effects(void) const;
  Expr ignore_casts(void) const;
  Expr ignore_conversion_operator_single_step(void) const;
  Expr ignore_imp_casts(void) const;
  Expr ignore_implicit(void) const;
  Expr ignore_implicit_as_written(void) const;
  Expr ignore_parenthesis_base_casts(void) const;
  Expr ignore_parenthesis_casts(void) const;
  Expr ignore_parenthesis_imp_casts(void) const;
  Expr ignore_parenthesis_l_value_casts(void) const;
  Expr ignore_parenthesis_noop_casts(void) const;
  Expr ignore_parentheses(void) const;
  Expr ignore_unless_spelled_in_source(void) const;
  bool contains_errors(void) const;
  bool contains_unexpanded_parameter_pack(void) const;
  Expr best_dynamic_class_type_expression(void) const;
  Token expression_token(void) const;
  std::optional<ObjCPropertyRefExpr> obj_c_property(void) const;
  ExprObjectKind object_kind(void) const;
  std::optional<Decl> referenced_declaration_of_callee(void) const;
  std::optional<FieldDecl> source_bit_field(void) const;
  ExprValueKind value_kind(void) const;
  bool has_non_trivial_call(void) const;
  bool is_default_argument(void) const;
  bool is_gl_value(void) const;
  bool is_implicit_cxx_this(void) const;
  bool is_instantiation_dependent(void) const;
  bool is_known_to_have_boolean_value(void) const;
  bool is_l_value(void) const;
  bool is_objcgc_candidate(void) const;
  bool is_obj_c_self_expression(void) const;
  bool is_ordinary_or_bit_field_object(void) const;
  bool is_pr_value(void) const;
  bool is_read_if_discarded_in_c_plus_plus11(void) const;
  bool is_type_dependent(void) const;
  bool is_value_dependent(void) const;
  bool is_x_value(void) const;
  bool refers_to_bit_field(void) const;
  bool refers_to_global_register_variable(void) const;
  bool refers_to_matrix_element(void) const;
  bool refers_to_vector_element(void) const;
};

using DesignatedInitUpdateExprRange = DerivedEntityRange<StmtIterator, DesignatedInitUpdateExpr>;
using DesignatedInitUpdateExprContainingTokenRange = DerivedEntityRange<TokenContextIterator, DesignatedInitUpdateExpr>;
using DesignatedInitUpdateExprContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, DesignatedInitUpdateExpr>;

class DesignatedInitUpdateExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static DesignatedInitUpdateExprRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static DesignatedInitUpdateExprContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static DesignatedInitUpdateExprContainingStmtRange containing(const Decl &decl);
  static DesignatedInitUpdateExprContainingStmtRange containing(const Stmt &stmt);

  static std::optional<DesignatedInitUpdateExpr> from(const TokenContext &c);
  static std::optional<DesignatedInitUpdateExpr> from(const Expr &parent);
  static std::optional<DesignatedInitUpdateExpr> from(const ValueStmt &parent);
  static std::optional<DesignatedInitUpdateExpr> from(const Stmt &parent);
  Expr base(void) const;
  InitListExpr updater(void) const;
};

using DesignatedInitExprRange = DerivedEntityRange<StmtIterator, DesignatedInitExpr>;
using DesignatedInitExprContainingTokenRange = DerivedEntityRange<TokenContextIterator, DesignatedInitExpr>;
using DesignatedInitExprContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, DesignatedInitExpr>;

class DesignatedInitExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static DesignatedInitExprRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static DesignatedInitExprContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static DesignatedInitExprContainingStmtRange containing(const Decl &decl);
  static DesignatedInitExprContainingStmtRange containing(const Stmt &stmt);

  static std::optional<DesignatedInitExpr> from(const TokenContext &c);
  static std::optional<DesignatedInitExpr> from(const Expr &parent);
  static std::optional<DesignatedInitExpr> from(const ValueStmt &parent);
  static std::optional<DesignatedInitExpr> from(const Stmt &parent);
  TokenRange designators_source_range(void) const;
  Token equal_or_colon_token(void) const;
  Expr initializer(void) const;
  bool is_direct_initializer(void) const;
  bool uses_gnu_syntax(void) const;
  std::vector<Expr> sub_expressions(void) const;
};

using DependentScopeDeclRefExprRange = DerivedEntityRange<StmtIterator, DependentScopeDeclRefExpr>;
using DependentScopeDeclRefExprContainingTokenRange = DerivedEntityRange<TokenContextIterator, DependentScopeDeclRefExpr>;
using DependentScopeDeclRefExprContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, DependentScopeDeclRefExpr>;

class DependentScopeDeclRefExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static DependentScopeDeclRefExprRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static DependentScopeDeclRefExprContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static DependentScopeDeclRefExprContainingStmtRange containing(const Decl &decl);
  static DependentScopeDeclRefExprContainingStmtRange containing(const Stmt &stmt);

  static std::optional<DependentScopeDeclRefExpr> from(const TokenContext &c);
  static std::optional<DependentScopeDeclRefExpr> from(const Expr &parent);
  static std::optional<DependentScopeDeclRefExpr> from(const ValueStmt &parent);
  static std::optional<DependentScopeDeclRefExpr> from(const Stmt &parent);
  Token l_angle_token(void) const;
  Token r_angle_token(void) const;
  Token template_keyword_token(void) const;
  bool has_explicit_template_arguments(void) const;
  bool has_template_keyword(void) const;
};

using DependentCoawaitExprRange = DerivedEntityRange<StmtIterator, DependentCoawaitExpr>;
using DependentCoawaitExprContainingTokenRange = DerivedEntityRange<TokenContextIterator, DependentCoawaitExpr>;
using DependentCoawaitExprContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, DependentCoawaitExpr>;

class DependentCoawaitExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static DependentCoawaitExprRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static DependentCoawaitExprContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static DependentCoawaitExprContainingStmtRange containing(const Decl &decl);
  static DependentCoawaitExprContainingStmtRange containing(const Stmt &stmt);

  static std::optional<DependentCoawaitExpr> from(const TokenContext &c);
  static std::optional<DependentCoawaitExpr> from(const Expr &parent);
  static std::optional<DependentCoawaitExpr> from(const ValueStmt &parent);
  static std::optional<DependentCoawaitExpr> from(const Stmt &parent);
  Token keyword_token(void) const;
  Expr operand(void) const;
  UnresolvedLookupExpr operator_coawait_lookup(void) const;
};

using DeclRefExprRange = DerivedEntityRange<StmtIterator, DeclRefExpr>;
using DeclRefExprContainingTokenRange = DerivedEntityRange<TokenContextIterator, DeclRefExpr>;
using DeclRefExprContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, DeclRefExpr>;

class DeclRefExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static DeclRefExprRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static DeclRefExprContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static DeclRefExprContainingStmtRange containing(const Decl &decl);
  static DeclRefExprContainingStmtRange containing(const Stmt &stmt);

  static std::optional<DeclRefExpr> from(const TokenContext &c);
  static std::optional<DeclRefExpr> from(const Expr &parent);
  static std::optional<DeclRefExpr> from(const ValueStmt &parent);
  static std::optional<DeclRefExpr> from(const Stmt &parent);
  ValueDecl declaration(void) const;
  NamedDecl found_declaration(void) const;
  Token l_angle_token(void) const;
  Token r_angle_token(void) const;
  Token template_keyword_token(void) const;
  bool had_multiple_candidates(void) const;
  bool has_explicit_template_arguments(void) const;
  bool has_qualifier(void) const;
  bool has_template_kw_and_arguments_info(void) const;
  bool has_template_keyword(void) const;
  NonOdrUseReason is_non_odr_use(void) const;
  bool refers_to_enclosing_variable_or_capture(void) const;
};

using CoroutineSuspendExprRange = DerivedEntityRange<StmtIterator, CoroutineSuspendExpr>;
using CoroutineSuspendExprContainingTokenRange = DerivedEntityRange<TokenContextIterator, CoroutineSuspendExpr>;
using CoroutineSuspendExprContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, CoroutineSuspendExpr>;

class CoroutineSuspendExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static CoroutineSuspendExprRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static CoroutineSuspendExprContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static CoroutineSuspendExprContainingStmtRange containing(const Decl &decl);
  static CoroutineSuspendExprContainingStmtRange containing(const Stmt &stmt);

  static std::optional<CoroutineSuspendExpr> from(const TokenContext &c);
  static std::optional<CoroutineSuspendExpr> from(const Expr &parent);
  static std::optional<CoroutineSuspendExpr> from(const ValueStmt &parent);
  static std::optional<CoroutineSuspendExpr> from(const Stmt &parent);
  Expr common_expression(void) const;
  Token keyword_token(void) const;
  OpaqueValueExpr opaque_value(void) const;
  Expr ready_expression(void) const;
  Expr resume_expression(void) const;
  Expr suspend_expression(void) const;
};

using CoawaitExprRange = DerivedEntityRange<StmtIterator, CoawaitExpr>;
using CoawaitExprContainingTokenRange = DerivedEntityRange<TokenContextIterator, CoawaitExpr>;
using CoawaitExprContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, CoawaitExpr>;

class CoawaitExpr : public CoroutineSuspendExpr {
 private:
  friend class FragmentImpl;
  friend class CoroutineSuspendExpr;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static CoawaitExprRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static CoawaitExprContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static CoawaitExprContainingStmtRange containing(const Decl &decl);
  static CoawaitExprContainingStmtRange containing(const Stmt &stmt);

  static std::optional<CoawaitExpr> from(const TokenContext &c);
  static std::optional<CoawaitExpr> from(const CoroutineSuspendExpr &parent);
  static std::optional<CoawaitExpr> from(const Expr &parent);
  static std::optional<CoawaitExpr> from(const ValueStmt &parent);
  static std::optional<CoawaitExpr> from(const Stmt &parent);
  Expr operand(void) const;
  bool is_implicit(void) const;
};

using CoyieldExprRange = DerivedEntityRange<StmtIterator, CoyieldExpr>;
using CoyieldExprContainingTokenRange = DerivedEntityRange<TokenContextIterator, CoyieldExpr>;
using CoyieldExprContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, CoyieldExpr>;

class CoyieldExpr : public CoroutineSuspendExpr {
 private:
  friend class FragmentImpl;
  friend class CoroutineSuspendExpr;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static CoyieldExprRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static CoyieldExprContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static CoyieldExprContainingStmtRange containing(const Decl &decl);
  static CoyieldExprContainingStmtRange containing(const Stmt &stmt);

  static std::optional<CoyieldExpr> from(const TokenContext &c);
  static std::optional<CoyieldExpr> from(const CoroutineSuspendExpr &parent);
  static std::optional<CoyieldExpr> from(const Expr &parent);
  static std::optional<CoyieldExpr> from(const ValueStmt &parent);
  static std::optional<CoyieldExpr> from(const Stmt &parent);
  Expr operand(void) const;
};

using ConvertVectorExprRange = DerivedEntityRange<StmtIterator, ConvertVectorExpr>;
using ConvertVectorExprContainingTokenRange = DerivedEntityRange<TokenContextIterator, ConvertVectorExpr>;
using ConvertVectorExprContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, ConvertVectorExpr>;

class ConvertVectorExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static ConvertVectorExprRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static ConvertVectorExprContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static ConvertVectorExprContainingStmtRange containing(const Decl &decl);
  static ConvertVectorExprContainingStmtRange containing(const Stmt &stmt);

  static std::optional<ConvertVectorExpr> from(const TokenContext &c);
  static std::optional<ConvertVectorExpr> from(const Expr &parent);
  static std::optional<ConvertVectorExpr> from(const ValueStmt &parent);
  static std::optional<ConvertVectorExpr> from(const Stmt &parent);
  Token builtin_token(void) const;
  Token r_paren_token(void) const;
  Expr src_expression(void) const;
};

using ConceptSpecializationExprRange = DerivedEntityRange<StmtIterator, ConceptSpecializationExpr>;
using ConceptSpecializationExprContainingTokenRange = DerivedEntityRange<TokenContextIterator, ConceptSpecializationExpr>;
using ConceptSpecializationExprContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, ConceptSpecializationExpr>;

class ConceptSpecializationExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static ConceptSpecializationExprRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static ConceptSpecializationExprContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static ConceptSpecializationExprContainingStmtRange containing(const Decl &decl);
  static ConceptSpecializationExprContainingStmtRange containing(const Stmt &stmt);

  static std::optional<ConceptSpecializationExpr> from(const TokenContext &c);
  static std::optional<ConceptSpecializationExpr> from(const Expr &parent);
  static std::optional<ConceptSpecializationExpr> from(const ValueStmt &parent);
  static std::optional<ConceptSpecializationExpr> from(const Stmt &parent);
  std::vector<TemplateArgument> template_arguments(void) const;
  bool is_satisfied(void) const;
};

using CompoundLiteralExprRange = DerivedEntityRange<StmtIterator, CompoundLiteralExpr>;
using CompoundLiteralExprContainingTokenRange = DerivedEntityRange<TokenContextIterator, CompoundLiteralExpr>;
using CompoundLiteralExprContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, CompoundLiteralExpr>;

class CompoundLiteralExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static CompoundLiteralExprRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static CompoundLiteralExprContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static CompoundLiteralExprContainingStmtRange containing(const Decl &decl);
  static CompoundLiteralExprContainingStmtRange containing(const Stmt &stmt);

  static std::optional<CompoundLiteralExpr> from(const TokenContext &c);
  static std::optional<CompoundLiteralExpr> from(const Expr &parent);
  static std::optional<CompoundLiteralExpr> from(const ValueStmt &parent);
  static std::optional<CompoundLiteralExpr> from(const Stmt &parent);
  Expr initializer(void) const;
  Token l_paren_token(void) const;
  bool is_file_scope(void) const;
};

using ChooseExprRange = DerivedEntityRange<StmtIterator, ChooseExpr>;
using ChooseExprContainingTokenRange = DerivedEntityRange<TokenContextIterator, ChooseExpr>;
using ChooseExprContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, ChooseExpr>;

class ChooseExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static ChooseExprRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static ChooseExprContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static ChooseExprContainingStmtRange containing(const Decl &decl);
  static ChooseExprContainingStmtRange containing(const Stmt &stmt);

  static std::optional<ChooseExpr> from(const TokenContext &c);
  static std::optional<ChooseExpr> from(const Expr &parent);
  static std::optional<ChooseExpr> from(const ValueStmt &parent);
  static std::optional<ChooseExpr> from(const Stmt &parent);
  Token builtin_token(void) const;
  Expr chosen_sub_expression(void) const;
  Expr condition(void) const;
  Expr lhs(void) const;
  Expr rhs(void) const;
  Token r_paren_token(void) const;
  bool is_condition_dependent(void) const;
  bool is_condition_true(void) const;
};

using CharacterLiteralRange = DerivedEntityRange<StmtIterator, CharacterLiteral>;
using CharacterLiteralContainingTokenRange = DerivedEntityRange<TokenContextIterator, CharacterLiteral>;
using CharacterLiteralContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, CharacterLiteral>;

class CharacterLiteral : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static CharacterLiteralRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static CharacterLiteralContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static CharacterLiteralContainingStmtRange containing(const Decl &decl);
  static CharacterLiteralContainingStmtRange containing(const Stmt &stmt);

  static std::optional<CharacterLiteral> from(const TokenContext &c);
  static std::optional<CharacterLiteral> from(const Expr &parent);
  static std::optional<CharacterLiteral> from(const ValueStmt &parent);
  static std::optional<CharacterLiteral> from(const Stmt &parent);
  Token token(void) const;
};

using CastExprRange = DerivedEntityRange<StmtIterator, CastExpr>;
using CastExprContainingTokenRange = DerivedEntityRange<TokenContextIterator, CastExpr>;
using CastExprContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, CastExpr>;

class CastExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static CastExprRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static CastExprContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static CastExprContainingStmtRange containing(const Decl &decl);
  static CastExprContainingStmtRange containing(const Stmt &stmt);

  static std::optional<CastExpr> from(const TokenContext &c);
  static std::optional<CastExpr> from(const Expr &parent);
  static std::optional<CastExpr> from(const ValueStmt &parent);
  static std::optional<CastExpr> from(const Stmt &parent);
  CastKind cast_kind(void) const;
  std::string_view cast_kind_name(void) const;
  std::optional<NamedDecl> conversion_function(void) const;
  Expr sub_expression(void) const;
  Expr sub_expression_as_written(void) const;
  std::optional<FieldDecl> target_union_field(void) const;
  bool has_stored_fp_features(void) const;
};

using ImplicitCastExprRange = DerivedEntityRange<StmtIterator, ImplicitCastExpr>;
using ImplicitCastExprContainingTokenRange = DerivedEntityRange<TokenContextIterator, ImplicitCastExpr>;
using ImplicitCastExprContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, ImplicitCastExpr>;

class ImplicitCastExpr : public CastExpr {
 private:
  friend class FragmentImpl;
  friend class CastExpr;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static ImplicitCastExprRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static ImplicitCastExprContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static ImplicitCastExprContainingStmtRange containing(const Decl &decl);
  static ImplicitCastExprContainingStmtRange containing(const Stmt &stmt);

  static std::optional<ImplicitCastExpr> from(const TokenContext &c);
  static std::optional<ImplicitCastExpr> from(const CastExpr &parent);
  static std::optional<ImplicitCastExpr> from(const Expr &parent);
  static std::optional<ImplicitCastExpr> from(const ValueStmt &parent);
  static std::optional<ImplicitCastExpr> from(const Stmt &parent);
  bool is_part_of_explicit_cast(void) const;
};

using ExplicitCastExprRange = DerivedEntityRange<StmtIterator, ExplicitCastExpr>;
using ExplicitCastExprContainingTokenRange = DerivedEntityRange<TokenContextIterator, ExplicitCastExpr>;
using ExplicitCastExprContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, ExplicitCastExpr>;

class ExplicitCastExpr : public CastExpr {
 private:
  friend class FragmentImpl;
  friend class CastExpr;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static ExplicitCastExprRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static ExplicitCastExprContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static ExplicitCastExprContainingStmtRange containing(const Decl &decl);
  static ExplicitCastExprContainingStmtRange containing(const Stmt &stmt);

  static std::optional<ExplicitCastExpr> from(const TokenContext &c);
  static std::optional<ExplicitCastExpr> from(const CastExpr &parent);
  static std::optional<ExplicitCastExpr> from(const Expr &parent);
  static std::optional<ExplicitCastExpr> from(const ValueStmt &parent);
  static std::optional<ExplicitCastExpr> from(const Stmt &parent);
};

using CXXNamedCastExprRange = DerivedEntityRange<StmtIterator, CXXNamedCastExpr>;
using CXXNamedCastExprContainingTokenRange = DerivedEntityRange<TokenContextIterator, CXXNamedCastExpr>;
using CXXNamedCastExprContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, CXXNamedCastExpr>;

class CXXNamedCastExpr : public ExplicitCastExpr {
 private:
  friend class FragmentImpl;
  friend class ExplicitCastExpr;
  friend class CastExpr;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static CXXNamedCastExprRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static CXXNamedCastExprContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static CXXNamedCastExprContainingStmtRange containing(const Decl &decl);
  static CXXNamedCastExprContainingStmtRange containing(const Stmt &stmt);

  static std::optional<CXXNamedCastExpr> from(const TokenContext &c);
  static std::optional<CXXNamedCastExpr> from(const ExplicitCastExpr &parent);
  static std::optional<CXXNamedCastExpr> from(const CastExpr &parent);
  static std::optional<CXXNamedCastExpr> from(const Expr &parent);
  static std::optional<CXXNamedCastExpr> from(const ValueStmt &parent);
  static std::optional<CXXNamedCastExpr> from(const Stmt &parent);
  TokenRange angle_brackets(void) const;
  std::string_view cast_name(void) const;
  Token operator_token(void) const;
  Token r_paren_token(void) const;
};

using CXXDynamicCastExprRange = DerivedEntityRange<StmtIterator, CXXDynamicCastExpr>;
using CXXDynamicCastExprContainingTokenRange = DerivedEntityRange<TokenContextIterator, CXXDynamicCastExpr>;
using CXXDynamicCastExprContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, CXXDynamicCastExpr>;

class CXXDynamicCastExpr : public CXXNamedCastExpr {
 private:
  friend class FragmentImpl;
  friend class CXXNamedCastExpr;
  friend class ExplicitCastExpr;
  friend class CastExpr;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static CXXDynamicCastExprRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static CXXDynamicCastExprContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static CXXDynamicCastExprContainingStmtRange containing(const Decl &decl);
  static CXXDynamicCastExprContainingStmtRange containing(const Stmt &stmt);

  static std::optional<CXXDynamicCastExpr> from(const TokenContext &c);
  static std::optional<CXXDynamicCastExpr> from(const CXXNamedCastExpr &parent);
  static std::optional<CXXDynamicCastExpr> from(const ExplicitCastExpr &parent);
  static std::optional<CXXDynamicCastExpr> from(const CastExpr &parent);
  static std::optional<CXXDynamicCastExpr> from(const Expr &parent);
  static std::optional<CXXDynamicCastExpr> from(const ValueStmt &parent);
  static std::optional<CXXDynamicCastExpr> from(const Stmt &parent);
  bool is_always_null(void) const;
};

using CXXConstCastExprRange = DerivedEntityRange<StmtIterator, CXXConstCastExpr>;
using CXXConstCastExprContainingTokenRange = DerivedEntityRange<TokenContextIterator, CXXConstCastExpr>;
using CXXConstCastExprContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, CXXConstCastExpr>;

class CXXConstCastExpr : public CXXNamedCastExpr {
 private:
  friend class FragmentImpl;
  friend class CXXNamedCastExpr;
  friend class ExplicitCastExpr;
  friend class CastExpr;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static CXXConstCastExprRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static CXXConstCastExprContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static CXXConstCastExprContainingStmtRange containing(const Decl &decl);
  static CXXConstCastExprContainingStmtRange containing(const Stmt &stmt);

  static std::optional<CXXConstCastExpr> from(const TokenContext &c);
  static std::optional<CXXConstCastExpr> from(const CXXNamedCastExpr &parent);
  static std::optional<CXXConstCastExpr> from(const ExplicitCastExpr &parent);
  static std::optional<CXXConstCastExpr> from(const CastExpr &parent);
  static std::optional<CXXConstCastExpr> from(const Expr &parent);
  static std::optional<CXXConstCastExpr> from(const ValueStmt &parent);
  static std::optional<CXXConstCastExpr> from(const Stmt &parent);
};

using CXXAddrspaceCastExprRange = DerivedEntityRange<StmtIterator, CXXAddrspaceCastExpr>;
using CXXAddrspaceCastExprContainingTokenRange = DerivedEntityRange<TokenContextIterator, CXXAddrspaceCastExpr>;
using CXXAddrspaceCastExprContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, CXXAddrspaceCastExpr>;

class CXXAddrspaceCastExpr : public CXXNamedCastExpr {
 private:
  friend class FragmentImpl;
  friend class CXXNamedCastExpr;
  friend class ExplicitCastExpr;
  friend class CastExpr;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static CXXAddrspaceCastExprRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static CXXAddrspaceCastExprContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static CXXAddrspaceCastExprContainingStmtRange containing(const Decl &decl);
  static CXXAddrspaceCastExprContainingStmtRange containing(const Stmt &stmt);

  static std::optional<CXXAddrspaceCastExpr> from(const TokenContext &c);
  static std::optional<CXXAddrspaceCastExpr> from(const CXXNamedCastExpr &parent);
  static std::optional<CXXAddrspaceCastExpr> from(const ExplicitCastExpr &parent);
  static std::optional<CXXAddrspaceCastExpr> from(const CastExpr &parent);
  static std::optional<CXXAddrspaceCastExpr> from(const Expr &parent);
  static std::optional<CXXAddrspaceCastExpr> from(const ValueStmt &parent);
  static std::optional<CXXAddrspaceCastExpr> from(const Stmt &parent);
};

using CXXStaticCastExprRange = DerivedEntityRange<StmtIterator, CXXStaticCastExpr>;
using CXXStaticCastExprContainingTokenRange = DerivedEntityRange<TokenContextIterator, CXXStaticCastExpr>;
using CXXStaticCastExprContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, CXXStaticCastExpr>;

class CXXStaticCastExpr : public CXXNamedCastExpr {
 private:
  friend class FragmentImpl;
  friend class CXXNamedCastExpr;
  friend class ExplicitCastExpr;
  friend class CastExpr;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static CXXStaticCastExprRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static CXXStaticCastExprContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static CXXStaticCastExprContainingStmtRange containing(const Decl &decl);
  static CXXStaticCastExprContainingStmtRange containing(const Stmt &stmt);

  static std::optional<CXXStaticCastExpr> from(const TokenContext &c);
  static std::optional<CXXStaticCastExpr> from(const CXXNamedCastExpr &parent);
  static std::optional<CXXStaticCastExpr> from(const ExplicitCastExpr &parent);
  static std::optional<CXXStaticCastExpr> from(const CastExpr &parent);
  static std::optional<CXXStaticCastExpr> from(const Expr &parent);
  static std::optional<CXXStaticCastExpr> from(const ValueStmt &parent);
  static std::optional<CXXStaticCastExpr> from(const Stmt &parent);
};

using CXXReinterpretCastExprRange = DerivedEntityRange<StmtIterator, CXXReinterpretCastExpr>;
using CXXReinterpretCastExprContainingTokenRange = DerivedEntityRange<TokenContextIterator, CXXReinterpretCastExpr>;
using CXXReinterpretCastExprContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, CXXReinterpretCastExpr>;

class CXXReinterpretCastExpr : public CXXNamedCastExpr {
 private:
  friend class FragmentImpl;
  friend class CXXNamedCastExpr;
  friend class ExplicitCastExpr;
  friend class CastExpr;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static CXXReinterpretCastExprRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static CXXReinterpretCastExprContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static CXXReinterpretCastExprContainingStmtRange containing(const Decl &decl);
  static CXXReinterpretCastExprContainingStmtRange containing(const Stmt &stmt);

  static std::optional<CXXReinterpretCastExpr> from(const TokenContext &c);
  static std::optional<CXXReinterpretCastExpr> from(const CXXNamedCastExpr &parent);
  static std::optional<CXXReinterpretCastExpr> from(const ExplicitCastExpr &parent);
  static std::optional<CXXReinterpretCastExpr> from(const CastExpr &parent);
  static std::optional<CXXReinterpretCastExpr> from(const Expr &parent);
  static std::optional<CXXReinterpretCastExpr> from(const ValueStmt &parent);
  static std::optional<CXXReinterpretCastExpr> from(const Stmt &parent);
};

using CXXFunctionalCastExprRange = DerivedEntityRange<StmtIterator, CXXFunctionalCastExpr>;
using CXXFunctionalCastExprContainingTokenRange = DerivedEntityRange<TokenContextIterator, CXXFunctionalCastExpr>;
using CXXFunctionalCastExprContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, CXXFunctionalCastExpr>;

class CXXFunctionalCastExpr : public ExplicitCastExpr {
 private:
  friend class FragmentImpl;
  friend class ExplicitCastExpr;
  friend class CastExpr;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static CXXFunctionalCastExprRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static CXXFunctionalCastExprContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static CXXFunctionalCastExprContainingStmtRange containing(const Decl &decl);
  static CXXFunctionalCastExprContainingStmtRange containing(const Stmt &stmt);

  static std::optional<CXXFunctionalCastExpr> from(const TokenContext &c);
  static std::optional<CXXFunctionalCastExpr> from(const ExplicitCastExpr &parent);
  static std::optional<CXXFunctionalCastExpr> from(const CastExpr &parent);
  static std::optional<CXXFunctionalCastExpr> from(const Expr &parent);
  static std::optional<CXXFunctionalCastExpr> from(const ValueStmt &parent);
  static std::optional<CXXFunctionalCastExpr> from(const Stmt &parent);
  Token l_paren_token(void) const;
  Token r_paren_token(void) const;
  bool is_list_initialization(void) const;
};

using CStyleCastExprRange = DerivedEntityRange<StmtIterator, CStyleCastExpr>;
using CStyleCastExprContainingTokenRange = DerivedEntityRange<TokenContextIterator, CStyleCastExpr>;
using CStyleCastExprContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, CStyleCastExpr>;

class CStyleCastExpr : public ExplicitCastExpr {
 private:
  friend class FragmentImpl;
  friend class ExplicitCastExpr;
  friend class CastExpr;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static CStyleCastExprRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static CStyleCastExprContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static CStyleCastExprContainingStmtRange containing(const Decl &decl);
  static CStyleCastExprContainingStmtRange containing(const Stmt &stmt);

  static std::optional<CStyleCastExpr> from(const TokenContext &c);
  static std::optional<CStyleCastExpr> from(const ExplicitCastExpr &parent);
  static std::optional<CStyleCastExpr> from(const CastExpr &parent);
  static std::optional<CStyleCastExpr> from(const Expr &parent);
  static std::optional<CStyleCastExpr> from(const ValueStmt &parent);
  static std::optional<CStyleCastExpr> from(const Stmt &parent);
  Token l_paren_token(void) const;
  Token r_paren_token(void) const;
};

using BuiltinBitCastExprRange = DerivedEntityRange<StmtIterator, BuiltinBitCastExpr>;
using BuiltinBitCastExprContainingTokenRange = DerivedEntityRange<TokenContextIterator, BuiltinBitCastExpr>;
using BuiltinBitCastExprContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, BuiltinBitCastExpr>;

class BuiltinBitCastExpr : public ExplicitCastExpr {
 private:
  friend class FragmentImpl;
  friend class ExplicitCastExpr;
  friend class CastExpr;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static BuiltinBitCastExprRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static BuiltinBitCastExprContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static BuiltinBitCastExprContainingStmtRange containing(const Decl &decl);
  static BuiltinBitCastExprContainingStmtRange containing(const Stmt &stmt);

  static std::optional<BuiltinBitCastExpr> from(const TokenContext &c);
  static std::optional<BuiltinBitCastExpr> from(const ExplicitCastExpr &parent);
  static std::optional<BuiltinBitCastExpr> from(const CastExpr &parent);
  static std::optional<BuiltinBitCastExpr> from(const Expr &parent);
  static std::optional<BuiltinBitCastExpr> from(const ValueStmt &parent);
  static std::optional<BuiltinBitCastExpr> from(const Stmt &parent);
};

using ObjCBridgedCastExprRange = DerivedEntityRange<StmtIterator, ObjCBridgedCastExpr>;
using ObjCBridgedCastExprContainingTokenRange = DerivedEntityRange<TokenContextIterator, ObjCBridgedCastExpr>;
using ObjCBridgedCastExprContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, ObjCBridgedCastExpr>;

class ObjCBridgedCastExpr : public ExplicitCastExpr {
 private:
  friend class FragmentImpl;
  friend class ExplicitCastExpr;
  friend class CastExpr;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static ObjCBridgedCastExprRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static ObjCBridgedCastExprContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static ObjCBridgedCastExprContainingStmtRange containing(const Decl &decl);
  static ObjCBridgedCastExprContainingStmtRange containing(const Stmt &stmt);

  static std::optional<ObjCBridgedCastExpr> from(const TokenContext &c);
  static std::optional<ObjCBridgedCastExpr> from(const ExplicitCastExpr &parent);
  static std::optional<ObjCBridgedCastExpr> from(const CastExpr &parent);
  static std::optional<ObjCBridgedCastExpr> from(const Expr &parent);
  static std::optional<ObjCBridgedCastExpr> from(const ValueStmt &parent);
  static std::optional<ObjCBridgedCastExpr> from(const Stmt &parent);
  Token bridge_keyword_token(void) const;
  ObjCBridgeCastKind bridge_kind(void) const;
  std::string_view bridge_kind_name(void) const;
  Token l_paren_token(void) const;
};

using CallExprRange = DerivedEntityRange<StmtIterator, CallExpr>;
using CallExprContainingTokenRange = DerivedEntityRange<TokenContextIterator, CallExpr>;
using CallExprContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, CallExpr>;

class CallExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static CallExprRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static CallExprContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static CallExprContainingStmtRange containing(const Decl &decl);
  static CallExprContainingStmtRange containing(const Stmt &stmt);

  static std::optional<CallExpr> from(const TokenContext &c);
  static std::optional<CallExpr> from(const Expr &parent);
  static std::optional<CallExpr> from(const ValueStmt &parent);
  static std::optional<CallExpr> from(const Stmt &parent);
  std::vector<Expr> arguments(void) const;
  CallExprADLCallKind adl_call_kind(void) const;
  Expr callee(void) const;
  std::optional<Decl> callee_declaration(void) const;
  std::optional<FunctionDecl> direct_callee(void) const;
  Token r_paren_token(void) const;
  bool has_stored_fp_features(void) const;
  bool has_unused_result_attribute(void) const;
  bool is_builtin_assume_false(void) const;
  bool is_call_to_std_move(void) const;
  bool is_unevaluated_builtin_call(void) const;
  bool uses_adl(void) const;
};

using CXXOperatorCallExprRange = DerivedEntityRange<StmtIterator, CXXOperatorCallExpr>;
using CXXOperatorCallExprContainingTokenRange = DerivedEntityRange<TokenContextIterator, CXXOperatorCallExpr>;
using CXXOperatorCallExprContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, CXXOperatorCallExpr>;

class CXXOperatorCallExpr : public CallExpr {
 private:
  friend class FragmentImpl;
  friend class CallExpr;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static CXXOperatorCallExprRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static CXXOperatorCallExprContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static CXXOperatorCallExprContainingStmtRange containing(const Decl &decl);
  static CXXOperatorCallExprContainingStmtRange containing(const Stmt &stmt);

  static std::optional<CXXOperatorCallExpr> from(const TokenContext &c);
  static std::optional<CXXOperatorCallExpr> from(const CallExpr &parent);
  static std::optional<CXXOperatorCallExpr> from(const Expr &parent);
  static std::optional<CXXOperatorCallExpr> from(const ValueStmt &parent);
  static std::optional<CXXOperatorCallExpr> from(const Stmt &parent);
  OverloadedOperatorKind operator_(void) const;
  Token operator_token(void) const;
  bool is_assignment_operation(void) const;
  bool is_comparison_operation(void) const;
  bool is_infix_binary_operation(void) const;
};

using CXXMemberCallExprRange = DerivedEntityRange<StmtIterator, CXXMemberCallExpr>;
using CXXMemberCallExprContainingTokenRange = DerivedEntityRange<TokenContextIterator, CXXMemberCallExpr>;
using CXXMemberCallExprContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, CXXMemberCallExpr>;

class CXXMemberCallExpr : public CallExpr {
 private:
  friend class FragmentImpl;
  friend class CallExpr;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static CXXMemberCallExprRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static CXXMemberCallExprContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static CXXMemberCallExprContainingStmtRange containing(const Decl &decl);
  static CXXMemberCallExprContainingStmtRange containing(const Stmt &stmt);

  static std::optional<CXXMemberCallExpr> from(const TokenContext &c);
  static std::optional<CXXMemberCallExpr> from(const CallExpr &parent);
  static std::optional<CXXMemberCallExpr> from(const Expr &parent);
  static std::optional<CXXMemberCallExpr> from(const ValueStmt &parent);
  static std::optional<CXXMemberCallExpr> from(const Stmt &parent);
  Expr implicit_object_argument(void) const;
  CXXMethodDecl method_declaration(void) const;
  CXXRecordDecl record_declaration(void) const;
};

using CUDAKernelCallExprRange = DerivedEntityRange<StmtIterator, CUDAKernelCallExpr>;
using CUDAKernelCallExprContainingTokenRange = DerivedEntityRange<TokenContextIterator, CUDAKernelCallExpr>;
using CUDAKernelCallExprContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, CUDAKernelCallExpr>;

class CUDAKernelCallExpr : public CallExpr {
 private:
  friend class FragmentImpl;
  friend class CallExpr;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static CUDAKernelCallExprRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static CUDAKernelCallExprContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static CUDAKernelCallExprContainingStmtRange containing(const Decl &decl);
  static CUDAKernelCallExprContainingStmtRange containing(const Stmt &stmt);

  static std::optional<CUDAKernelCallExpr> from(const TokenContext &c);
  static std::optional<CUDAKernelCallExpr> from(const CallExpr &parent);
  static std::optional<CUDAKernelCallExpr> from(const Expr &parent);
  static std::optional<CUDAKernelCallExpr> from(const ValueStmt &parent);
  static std::optional<CUDAKernelCallExpr> from(const Stmt &parent);
  CallExpr config(void) const;
};

using UserDefinedLiteralRange = DerivedEntityRange<StmtIterator, UserDefinedLiteral>;
using UserDefinedLiteralContainingTokenRange = DerivedEntityRange<TokenContextIterator, UserDefinedLiteral>;
using UserDefinedLiteralContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, UserDefinedLiteral>;

class UserDefinedLiteral : public CallExpr {
 private:
  friend class FragmentImpl;
  friend class CallExpr;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static UserDefinedLiteralRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static UserDefinedLiteralContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static UserDefinedLiteralContainingStmtRange containing(const Decl &decl);
  static UserDefinedLiteralContainingStmtRange containing(const Stmt &stmt);

  static std::optional<UserDefinedLiteral> from(const TokenContext &c);
  static std::optional<UserDefinedLiteral> from(const CallExpr &parent);
  static std::optional<UserDefinedLiteral> from(const Expr &parent);
  static std::optional<UserDefinedLiteral> from(const ValueStmt &parent);
  static std::optional<UserDefinedLiteral> from(const Stmt &parent);
  Expr cooked_literal(void) const;
  UserDefinedLiteralLiteralOperatorKind literal_operator_kind(void) const;
  Token ud_suffix_token(void) const;
};

using CXXUuidofExprRange = DerivedEntityRange<StmtIterator, CXXUuidofExpr>;
using CXXUuidofExprContainingTokenRange = DerivedEntityRange<TokenContextIterator, CXXUuidofExpr>;
using CXXUuidofExprContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, CXXUuidofExpr>;

class CXXUuidofExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static CXXUuidofExprRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static CXXUuidofExprContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static CXXUuidofExprContainingStmtRange containing(const Decl &decl);
  static CXXUuidofExprContainingStmtRange containing(const Stmt &stmt);

  static std::optional<CXXUuidofExpr> from(const TokenContext &c);
  static std::optional<CXXUuidofExpr> from(const Expr &parent);
  static std::optional<CXXUuidofExpr> from(const ValueStmt &parent);
  static std::optional<CXXUuidofExpr> from(const Stmt &parent);
  Expr expression_operand(void) const;
  MSGuidDecl guid_declaration(void) const;
  bool is_type_operand(void) const;
};

using CXXUnresolvedConstructExprRange = DerivedEntityRange<StmtIterator, CXXUnresolvedConstructExpr>;
using CXXUnresolvedConstructExprContainingTokenRange = DerivedEntityRange<TokenContextIterator, CXXUnresolvedConstructExpr>;
using CXXUnresolvedConstructExprContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, CXXUnresolvedConstructExpr>;

class CXXUnresolvedConstructExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static CXXUnresolvedConstructExprRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static CXXUnresolvedConstructExprContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static CXXUnresolvedConstructExprContainingStmtRange containing(const Decl &decl);
  static CXXUnresolvedConstructExprContainingStmtRange containing(const Stmt &stmt);

  static std::optional<CXXUnresolvedConstructExpr> from(const TokenContext &c);
  static std::optional<CXXUnresolvedConstructExpr> from(const Expr &parent);
  static std::optional<CXXUnresolvedConstructExpr> from(const ValueStmt &parent);
  static std::optional<CXXUnresolvedConstructExpr> from(const Stmt &parent);
  std::vector<Expr> arguments(void) const;
  Token l_paren_token(void) const;
  Token r_paren_token(void) const;
  bool is_list_initialization(void) const;
};

using CXXTypeidExprRange = DerivedEntityRange<StmtIterator, CXXTypeidExpr>;
using CXXTypeidExprContainingTokenRange = DerivedEntityRange<TokenContextIterator, CXXTypeidExpr>;
using CXXTypeidExprContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, CXXTypeidExpr>;

class CXXTypeidExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static CXXTypeidExprRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static CXXTypeidExprContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static CXXTypeidExprContainingStmtRange containing(const Decl &decl);
  static CXXTypeidExprContainingStmtRange containing(const Stmt &stmt);

  static std::optional<CXXTypeidExpr> from(const TokenContext &c);
  static std::optional<CXXTypeidExpr> from(const Expr &parent);
  static std::optional<CXXTypeidExpr> from(const ValueStmt &parent);
  static std::optional<CXXTypeidExpr> from(const Stmt &parent);
  Expr expression_operand(void) const;
  bool is_most_derived(void) const;
  bool is_potentially_evaluated(void) const;
  bool is_type_operand(void) const;
};

using CXXThrowExprRange = DerivedEntityRange<StmtIterator, CXXThrowExpr>;
using CXXThrowExprContainingTokenRange = DerivedEntityRange<TokenContextIterator, CXXThrowExpr>;
using CXXThrowExprContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, CXXThrowExpr>;

class CXXThrowExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static CXXThrowExprRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static CXXThrowExprContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static CXXThrowExprContainingStmtRange containing(const Decl &decl);
  static CXXThrowExprContainingStmtRange containing(const Stmt &stmt);

  static std::optional<CXXThrowExpr> from(const TokenContext &c);
  static std::optional<CXXThrowExpr> from(const Expr &parent);
  static std::optional<CXXThrowExpr> from(const ValueStmt &parent);
  static std::optional<CXXThrowExpr> from(const Stmt &parent);
  Expr sub_expression(void) const;
  Token throw_token(void) const;
  bool is_thrown_variable_in_scope(void) const;
};

using CXXThisExprRange = DerivedEntityRange<StmtIterator, CXXThisExpr>;
using CXXThisExprContainingTokenRange = DerivedEntityRange<TokenContextIterator, CXXThisExpr>;
using CXXThisExprContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, CXXThisExpr>;

class CXXThisExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static CXXThisExprRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static CXXThisExprContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static CXXThisExprContainingStmtRange containing(const Decl &decl);
  static CXXThisExprContainingStmtRange containing(const Stmt &stmt);

  static std::optional<CXXThisExpr> from(const TokenContext &c);
  static std::optional<CXXThisExpr> from(const Expr &parent);
  static std::optional<CXXThisExpr> from(const ValueStmt &parent);
  static std::optional<CXXThisExpr> from(const Stmt &parent);
  Token token(void) const;
  bool is_implicit(void) const;
};

using CXXStdInitializerListExprRange = DerivedEntityRange<StmtIterator, CXXStdInitializerListExpr>;
using CXXStdInitializerListExprContainingTokenRange = DerivedEntityRange<TokenContextIterator, CXXStdInitializerListExpr>;
using CXXStdInitializerListExprContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, CXXStdInitializerListExpr>;

class CXXStdInitializerListExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static CXXStdInitializerListExprRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static CXXStdInitializerListExprContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static CXXStdInitializerListExprContainingStmtRange containing(const Decl &decl);
  static CXXStdInitializerListExprContainingStmtRange containing(const Stmt &stmt);

  static std::optional<CXXStdInitializerListExpr> from(const TokenContext &c);
  static std::optional<CXXStdInitializerListExpr> from(const Expr &parent);
  static std::optional<CXXStdInitializerListExpr> from(const ValueStmt &parent);
  static std::optional<CXXStdInitializerListExpr> from(const Stmt &parent);
  Expr sub_expression(void) const;
};

using CXXScalarValueInitExprRange = DerivedEntityRange<StmtIterator, CXXScalarValueInitExpr>;
using CXXScalarValueInitExprContainingTokenRange = DerivedEntityRange<TokenContextIterator, CXXScalarValueInitExpr>;
using CXXScalarValueInitExprContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, CXXScalarValueInitExpr>;

class CXXScalarValueInitExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static CXXScalarValueInitExprRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static CXXScalarValueInitExprContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static CXXScalarValueInitExprContainingStmtRange containing(const Decl &decl);
  static CXXScalarValueInitExprContainingStmtRange containing(const Stmt &stmt);

  static std::optional<CXXScalarValueInitExpr> from(const TokenContext &c);
  static std::optional<CXXScalarValueInitExpr> from(const Expr &parent);
  static std::optional<CXXScalarValueInitExpr> from(const ValueStmt &parent);
  static std::optional<CXXScalarValueInitExpr> from(const Stmt &parent);
  Token r_paren_token(void) const;
};

using CXXRewrittenBinaryOperatorRange = DerivedEntityRange<StmtIterator, CXXRewrittenBinaryOperator>;
using CXXRewrittenBinaryOperatorContainingTokenRange = DerivedEntityRange<TokenContextIterator, CXXRewrittenBinaryOperator>;
using CXXRewrittenBinaryOperatorContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, CXXRewrittenBinaryOperator>;

class CXXRewrittenBinaryOperator : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static CXXRewrittenBinaryOperatorRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static CXXRewrittenBinaryOperatorContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static CXXRewrittenBinaryOperatorContainingStmtRange containing(const Decl &decl);
  static CXXRewrittenBinaryOperatorContainingStmtRange containing(const Stmt &stmt);

  static std::optional<CXXRewrittenBinaryOperator> from(const TokenContext &c);
  static std::optional<CXXRewrittenBinaryOperator> from(const Expr &parent);
  static std::optional<CXXRewrittenBinaryOperator> from(const ValueStmt &parent);
  static std::optional<CXXRewrittenBinaryOperator> from(const Stmt &parent);
  Expr lhs(void) const;
  BinaryOperatorKind opcode(void) const;
  std::string_view opcode_string(void) const;
  BinaryOperatorKind operator_(void) const;
  Token operator_token(void) const;
  Expr rhs(void) const;
  Expr semantic_form(void) const;
  bool is_assignment_operation(void) const;
  bool is_comparison_operation(void) const;
  bool is_reversed(void) const;
};

using CXXPseudoDestructorExprRange = DerivedEntityRange<StmtIterator, CXXPseudoDestructorExpr>;
using CXXPseudoDestructorExprContainingTokenRange = DerivedEntityRange<TokenContextIterator, CXXPseudoDestructorExpr>;
using CXXPseudoDestructorExprContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, CXXPseudoDestructorExpr>;

class CXXPseudoDestructorExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static CXXPseudoDestructorExprRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static CXXPseudoDestructorExprContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static CXXPseudoDestructorExprContainingStmtRange containing(const Decl &decl);
  static CXXPseudoDestructorExprContainingStmtRange containing(const Stmt &stmt);

  static std::optional<CXXPseudoDestructorExpr> from(const TokenContext &c);
  static std::optional<CXXPseudoDestructorExpr> from(const Expr &parent);
  static std::optional<CXXPseudoDestructorExpr> from(const ValueStmt &parent);
  static std::optional<CXXPseudoDestructorExpr> from(const Stmt &parent);
  Expr base(void) const;
  Token colon_colon_token(void) const;
  Token destroyed_type_token(void) const;
  Token operator_token(void) const;
  Token tilde_token(void) const;
  bool has_qualifier(void) const;
  bool is_arrow(void) const;
};

using CXXNullPtrLiteralExprRange = DerivedEntityRange<StmtIterator, CXXNullPtrLiteralExpr>;
using CXXNullPtrLiteralExprContainingTokenRange = DerivedEntityRange<TokenContextIterator, CXXNullPtrLiteralExpr>;
using CXXNullPtrLiteralExprContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, CXXNullPtrLiteralExpr>;

class CXXNullPtrLiteralExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static CXXNullPtrLiteralExprRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static CXXNullPtrLiteralExprContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static CXXNullPtrLiteralExprContainingStmtRange containing(const Decl &decl);
  static CXXNullPtrLiteralExprContainingStmtRange containing(const Stmt &stmt);

  static std::optional<CXXNullPtrLiteralExpr> from(const TokenContext &c);
  static std::optional<CXXNullPtrLiteralExpr> from(const Expr &parent);
  static std::optional<CXXNullPtrLiteralExpr> from(const ValueStmt &parent);
  static std::optional<CXXNullPtrLiteralExpr> from(const Stmt &parent);
  Token token(void) const;
};

using CXXNoexceptExprRange = DerivedEntityRange<StmtIterator, CXXNoexceptExpr>;
using CXXNoexceptExprContainingTokenRange = DerivedEntityRange<TokenContextIterator, CXXNoexceptExpr>;
using CXXNoexceptExprContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, CXXNoexceptExpr>;

class CXXNoexceptExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static CXXNoexceptExprRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static CXXNoexceptExprContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static CXXNoexceptExprContainingStmtRange containing(const Decl &decl);
  static CXXNoexceptExprContainingStmtRange containing(const Stmt &stmt);

  static std::optional<CXXNoexceptExpr> from(const TokenContext &c);
  static std::optional<CXXNoexceptExpr> from(const Expr &parent);
  static std::optional<CXXNoexceptExpr> from(const ValueStmt &parent);
  static std::optional<CXXNoexceptExpr> from(const Stmt &parent);
  Expr operand(void) const;
  bool value(void) const;
};

using CXXNewExprRange = DerivedEntityRange<StmtIterator, CXXNewExpr>;
using CXXNewExprContainingTokenRange = DerivedEntityRange<TokenContextIterator, CXXNewExpr>;
using CXXNewExprContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, CXXNewExpr>;

class CXXNewExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static CXXNewExprRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static CXXNewExprContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static CXXNewExprContainingStmtRange containing(const Decl &decl);
  static CXXNewExprContainingStmtRange containing(const Stmt &stmt);

  static std::optional<CXXNewExpr> from(const TokenContext &c);
  static std::optional<CXXNewExpr> from(const Expr &parent);
  static std::optional<CXXNewExpr> from(const ValueStmt &parent);
  static std::optional<CXXNewExpr> from(const Stmt &parent);
  bool does_usual_array_delete_want_size(void) const;
  std::optional<Expr> array_size(void) const;
  CXXConstructExpr construct_expression(void) const;
  TokenRange direct_initializer_range(void) const;
  CXXNewExprInitializationStyle initialization_style(void) const;
  Expr initializer(void) const;
  FunctionDecl operator_delete(void) const;
  FunctionDecl operator_new(void) const;
  TokenRange type_id_parentheses(void) const;
  bool has_initializer(void) const;
  bool is_array(void) const;
  bool is_global_new(void) const;
  bool is_parenthesis_type_id(void) const;
  bool pass_alignment(void) const;
  std::vector<Expr> placement_arguments(void) const;
  bool should_null_check_allocation(void) const;
};

using CXXInheritedCtorInitExprRange = DerivedEntityRange<StmtIterator, CXXInheritedCtorInitExpr>;
using CXXInheritedCtorInitExprContainingTokenRange = DerivedEntityRange<TokenContextIterator, CXXInheritedCtorInitExpr>;
using CXXInheritedCtorInitExprContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, CXXInheritedCtorInitExpr>;

class CXXInheritedCtorInitExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static CXXInheritedCtorInitExprRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static CXXInheritedCtorInitExprContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static CXXInheritedCtorInitExprContainingStmtRange containing(const Decl &decl);
  static CXXInheritedCtorInitExprContainingStmtRange containing(const Stmt &stmt);

  static std::optional<CXXInheritedCtorInitExpr> from(const TokenContext &c);
  static std::optional<CXXInheritedCtorInitExpr> from(const Expr &parent);
  static std::optional<CXXInheritedCtorInitExpr> from(const ValueStmt &parent);
  static std::optional<CXXInheritedCtorInitExpr> from(const Stmt &parent);
  bool constructs_virtual_base(void) const;
  CXXConstructExprConstructionKind construction_kind(void) const;
  CXXConstructorDecl constructor(void) const;
  Token token(void) const;
  bool inherited_from_virtual_base(void) const;
};

using CXXFoldExprRange = DerivedEntityRange<StmtIterator, CXXFoldExpr>;
using CXXFoldExprContainingTokenRange = DerivedEntityRange<TokenContextIterator, CXXFoldExpr>;
using CXXFoldExprContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, CXXFoldExpr>;

class CXXFoldExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static CXXFoldExprRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static CXXFoldExprContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static CXXFoldExprContainingStmtRange containing(const Decl &decl);
  static CXXFoldExprContainingStmtRange containing(const Stmt &stmt);

  static std::optional<CXXFoldExpr> from(const TokenContext &c);
  static std::optional<CXXFoldExpr> from(const Expr &parent);
  static std::optional<CXXFoldExpr> from(const ValueStmt &parent);
  static std::optional<CXXFoldExpr> from(const Stmt &parent);
  UnresolvedLookupExpr callee(void) const;
  Token ellipsis_token(void) const;
  Expr initializer(void) const;
  Expr lhs(void) const;
  Token l_paren_token(void) const;
  BinaryOperatorKind operator_(void) const;
  Expr pattern(void) const;
  Expr rhs(void) const;
  Token r_paren_token(void) const;
  bool is_left_fold(void) const;
  bool is_right_fold(void) const;
};

using CXXDependentScopeMemberExprRange = DerivedEntityRange<StmtIterator, CXXDependentScopeMemberExpr>;
using CXXDependentScopeMemberExprContainingTokenRange = DerivedEntityRange<TokenContextIterator, CXXDependentScopeMemberExpr>;
using CXXDependentScopeMemberExprContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, CXXDependentScopeMemberExpr>;

class CXXDependentScopeMemberExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static CXXDependentScopeMemberExprRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static CXXDependentScopeMemberExprContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static CXXDependentScopeMemberExprContainingStmtRange containing(const Decl &decl);
  static CXXDependentScopeMemberExprContainingStmtRange containing(const Stmt &stmt);

  static std::optional<CXXDependentScopeMemberExpr> from(const TokenContext &c);
  static std::optional<CXXDependentScopeMemberExpr> from(const Expr &parent);
  static std::optional<CXXDependentScopeMemberExpr> from(const ValueStmt &parent);
  static std::optional<CXXDependentScopeMemberExpr> from(const Stmt &parent);
  Expr base(void) const;
  NamedDecl first_qualifier_found_in_scope(void) const;
  Token l_angle_token(void) const;
  Token member_token(void) const;
  Token operator_token(void) const;
  Token r_angle_token(void) const;
  Token template_keyword_token(void) const;
  bool has_explicit_template_arguments(void) const;
  bool has_template_keyword(void) const;
  bool is_arrow(void) const;
  bool is_implicit_access(void) const;
};

using CXXDeleteExprRange = DerivedEntityRange<StmtIterator, CXXDeleteExpr>;
using CXXDeleteExprContainingTokenRange = DerivedEntityRange<TokenContextIterator, CXXDeleteExpr>;
using CXXDeleteExprContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, CXXDeleteExpr>;

class CXXDeleteExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static CXXDeleteExprRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static CXXDeleteExprContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static CXXDeleteExprContainingStmtRange containing(const Decl &decl);
  static CXXDeleteExprContainingStmtRange containing(const Stmt &stmt);

  static std::optional<CXXDeleteExpr> from(const TokenContext &c);
  static std::optional<CXXDeleteExpr> from(const Expr &parent);
  static std::optional<CXXDeleteExpr> from(const ValueStmt &parent);
  static std::optional<CXXDeleteExpr> from(const Stmt &parent);
  bool does_usual_array_delete_want_size(void) const;
  Expr argument(void) const;
  FunctionDecl operator_delete(void) const;
  bool is_array_form(void) const;
  bool is_array_form_as_written(void) const;
  bool is_global_delete(void) const;
};

using CXXDefaultInitExprRange = DerivedEntityRange<StmtIterator, CXXDefaultInitExpr>;
using CXXDefaultInitExprContainingTokenRange = DerivedEntityRange<TokenContextIterator, CXXDefaultInitExpr>;
using CXXDefaultInitExprContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, CXXDefaultInitExpr>;

class CXXDefaultInitExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static CXXDefaultInitExprRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static CXXDefaultInitExprContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static CXXDefaultInitExprContainingStmtRange containing(const Decl &decl);
  static CXXDefaultInitExprContainingStmtRange containing(const Stmt &stmt);

  static std::optional<CXXDefaultInitExpr> from(const TokenContext &c);
  static std::optional<CXXDefaultInitExpr> from(const Expr &parent);
  static std::optional<CXXDefaultInitExpr> from(const ValueStmt &parent);
  static std::optional<CXXDefaultInitExpr> from(const Stmt &parent);
  Expr expression(void) const;
  FieldDecl field(void) const;
  Token used_token(void) const;
};

using CXXDefaultArgExprRange = DerivedEntityRange<StmtIterator, CXXDefaultArgExpr>;
using CXXDefaultArgExprContainingTokenRange = DerivedEntityRange<TokenContextIterator, CXXDefaultArgExpr>;
using CXXDefaultArgExprContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, CXXDefaultArgExpr>;

class CXXDefaultArgExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static CXXDefaultArgExprRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static CXXDefaultArgExprContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static CXXDefaultArgExprContainingStmtRange containing(const Decl &decl);
  static CXXDefaultArgExprContainingStmtRange containing(const Stmt &stmt);

  static std::optional<CXXDefaultArgExpr> from(const TokenContext &c);
  static std::optional<CXXDefaultArgExpr> from(const Expr &parent);
  static std::optional<CXXDefaultArgExpr> from(const ValueStmt &parent);
  static std::optional<CXXDefaultArgExpr> from(const Stmt &parent);
  Expr expression(void) const;
  ParmVarDecl parameter(void) const;
  Token used_token(void) const;
};

using CXXConstructExprRange = DerivedEntityRange<StmtIterator, CXXConstructExpr>;
using CXXConstructExprContainingTokenRange = DerivedEntityRange<TokenContextIterator, CXXConstructExpr>;
using CXXConstructExprContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, CXXConstructExpr>;

class CXXConstructExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static CXXConstructExprRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static CXXConstructExprContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static CXXConstructExprContainingStmtRange containing(const Decl &decl);
  static CXXConstructExprContainingStmtRange containing(const Stmt &stmt);

  static std::optional<CXXConstructExpr> from(const TokenContext &c);
  static std::optional<CXXConstructExpr> from(const Expr &parent);
  static std::optional<CXXConstructExpr> from(const ValueStmt &parent);
  static std::optional<CXXConstructExpr> from(const Stmt &parent);
  std::vector<Expr> arguments(void) const;
  CXXConstructExprConstructionKind construction_kind(void) const;
  CXXConstructorDecl constructor(void) const;
  Token token(void) const;
  TokenRange parenthesis_or_brace_range(void) const;
  bool had_multiple_candidates(void) const;
  bool is_elidable(void) const;
  bool is_list_initialization(void) const;
  bool is_std_initializer_list_initialization(void) const;
  bool requires_zero_initialization(void) const;
};

using CXXTemporaryObjectExprRange = DerivedEntityRange<StmtIterator, CXXTemporaryObjectExpr>;
using CXXTemporaryObjectExprContainingTokenRange = DerivedEntityRange<TokenContextIterator, CXXTemporaryObjectExpr>;
using CXXTemporaryObjectExprContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, CXXTemporaryObjectExpr>;

class CXXTemporaryObjectExpr : public CXXConstructExpr {
 private:
  friend class FragmentImpl;
  friend class CXXConstructExpr;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static CXXTemporaryObjectExprRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static CXXTemporaryObjectExprContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static CXXTemporaryObjectExprContainingStmtRange containing(const Decl &decl);
  static CXXTemporaryObjectExprContainingStmtRange containing(const Stmt &stmt);

  static std::optional<CXXTemporaryObjectExpr> from(const TokenContext &c);
  static std::optional<CXXTemporaryObjectExpr> from(const CXXConstructExpr &parent);
  static std::optional<CXXTemporaryObjectExpr> from(const Expr &parent);
  static std::optional<CXXTemporaryObjectExpr> from(const ValueStmt &parent);
  static std::optional<CXXTemporaryObjectExpr> from(const Stmt &parent);
};

using CXXBoolLiteralExprRange = DerivedEntityRange<StmtIterator, CXXBoolLiteralExpr>;
using CXXBoolLiteralExprContainingTokenRange = DerivedEntityRange<TokenContextIterator, CXXBoolLiteralExpr>;
using CXXBoolLiteralExprContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, CXXBoolLiteralExpr>;

class CXXBoolLiteralExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static CXXBoolLiteralExprRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static CXXBoolLiteralExprContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static CXXBoolLiteralExprContainingStmtRange containing(const Decl &decl);
  static CXXBoolLiteralExprContainingStmtRange containing(const Stmt &stmt);

  static std::optional<CXXBoolLiteralExpr> from(const TokenContext &c);
  static std::optional<CXXBoolLiteralExpr> from(const Expr &parent);
  static std::optional<CXXBoolLiteralExpr> from(const ValueStmt &parent);
  static std::optional<CXXBoolLiteralExpr> from(const Stmt &parent);
  Token token(void) const;
  bool value(void) const;
};

using CXXBindTemporaryExprRange = DerivedEntityRange<StmtIterator, CXXBindTemporaryExpr>;
using CXXBindTemporaryExprContainingTokenRange = DerivedEntityRange<TokenContextIterator, CXXBindTemporaryExpr>;
using CXXBindTemporaryExprContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, CXXBindTemporaryExpr>;

class CXXBindTemporaryExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static CXXBindTemporaryExprRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static CXXBindTemporaryExprContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static CXXBindTemporaryExprContainingStmtRange containing(const Decl &decl);
  static CXXBindTemporaryExprContainingStmtRange containing(const Stmt &stmt);

  static std::optional<CXXBindTemporaryExpr> from(const TokenContext &c);
  static std::optional<CXXBindTemporaryExpr> from(const Expr &parent);
  static std::optional<CXXBindTemporaryExpr> from(const ValueStmt &parent);
  static std::optional<CXXBindTemporaryExpr> from(const Stmt &parent);
  Expr sub_expression(void) const;
};

using BlockExprRange = DerivedEntityRange<StmtIterator, BlockExpr>;
using BlockExprContainingTokenRange = DerivedEntityRange<TokenContextIterator, BlockExpr>;
using BlockExprContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, BlockExpr>;

class BlockExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static BlockExprRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static BlockExprContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static BlockExprContainingStmtRange containing(const Decl &decl);
  static BlockExprContainingStmtRange containing(const Stmt &stmt);

  static std::optional<BlockExpr> from(const TokenContext &c);
  static std::optional<BlockExpr> from(const Expr &parent);
  static std::optional<BlockExpr> from(const ValueStmt &parent);
  static std::optional<BlockExpr> from(const Stmt &parent);
  BlockDecl block_declaration(void) const;
  Stmt body(void) const;
  Token caret_token(void) const;
};

using BinaryOperatorRange = DerivedEntityRange<StmtIterator, BinaryOperator>;
using BinaryOperatorContainingTokenRange = DerivedEntityRange<TokenContextIterator, BinaryOperator>;
using BinaryOperatorContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, BinaryOperator>;

class BinaryOperator : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static BinaryOperatorRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static BinaryOperatorContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static BinaryOperatorContainingStmtRange containing(const Decl &decl);
  static BinaryOperatorContainingStmtRange containing(const Stmt &stmt);

  static std::optional<BinaryOperator> from(const TokenContext &c);
  static std::optional<BinaryOperator> from(const Expr &parent);
  static std::optional<BinaryOperator> from(const ValueStmt &parent);
  static std::optional<BinaryOperator> from(const Stmt &parent);
  Expr lhs(void) const;
  BinaryOperatorKind opcode(void) const;
  std::string_view opcode_string(void) const;
  Token operator_token(void) const;
  Expr rhs(void) const;
  bool has_stored_fp_features(void) const;
  bool is_additive_operation(void) const;
  bool is_assignment_operation(void) const;
  bool is_bitwise_operation(void) const;
  bool is_comma_operation(void) const;
  bool is_comparison_operation(void) const;
  bool is_compound_assignment_operation(void) const;
  bool is_equality_operation(void) const;
  bool is_logical_operation(void) const;
  bool is_multiplicative_operation(void) const;
  bool is_pointer_memory_operation(void) const;
  bool is_relational_operation(void) const;
  bool is_shift_assign_operation(void) const;
  bool is_shift_operation(void) const;
};

using CompoundAssignOperatorRange = DerivedEntityRange<StmtIterator, CompoundAssignOperator>;
using CompoundAssignOperatorContainingTokenRange = DerivedEntityRange<TokenContextIterator, CompoundAssignOperator>;
using CompoundAssignOperatorContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, CompoundAssignOperator>;

class CompoundAssignOperator : public BinaryOperator {
 private:
  friend class FragmentImpl;
  friend class BinaryOperator;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static CompoundAssignOperatorRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static CompoundAssignOperatorContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static CompoundAssignOperatorContainingStmtRange containing(const Decl &decl);
  static CompoundAssignOperatorContainingStmtRange containing(const Stmt &stmt);

  static std::optional<CompoundAssignOperator> from(const TokenContext &c);
  static std::optional<CompoundAssignOperator> from(const BinaryOperator &parent);
  static std::optional<CompoundAssignOperator> from(const Expr &parent);
  static std::optional<CompoundAssignOperator> from(const ValueStmt &parent);
  static std::optional<CompoundAssignOperator> from(const Stmt &parent);
};

using AtomicExprRange = DerivedEntityRange<StmtIterator, AtomicExpr>;
using AtomicExprContainingTokenRange = DerivedEntityRange<TokenContextIterator, AtomicExpr>;
using AtomicExprContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, AtomicExpr>;

class AtomicExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static AtomicExprRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static AtomicExprContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static AtomicExprContainingStmtRange containing(const Decl &decl);
  static AtomicExprContainingStmtRange containing(const Stmt &stmt);

  static std::optional<AtomicExpr> from(const TokenContext &c);
  static std::optional<AtomicExpr> from(const Expr &parent);
  static std::optional<AtomicExpr> from(const ValueStmt &parent);
  static std::optional<AtomicExpr> from(const Stmt &parent);
  Token builtin_token(void) const;
  AtomicExprAtomicOp operation(void) const;
  Expr order(void) const;
  std::optional<Expr> order_fail(void) const;
  Expr pointer(void) const;
  Token r_paren_token(void) const;
  std::optional<Expr> scope(void) const;
  std::optional<Expr> value1(void) const;
  std::optional<Expr> value2(void) const;
  std::optional<Expr> weak(void) const;
  bool is_cmp_x_chg(void) const;
  bool is_open_cl(void) const;
  bool is_volatile(void) const;
  std::vector<Expr> sub_expressions(void) const;
};

using AsTypeExprRange = DerivedEntityRange<StmtIterator, AsTypeExpr>;
using AsTypeExprContainingTokenRange = DerivedEntityRange<TokenContextIterator, AsTypeExpr>;
using AsTypeExprContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, AsTypeExpr>;

class AsTypeExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static AsTypeExprRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static AsTypeExprContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static AsTypeExprContainingStmtRange containing(const Decl &decl);
  static AsTypeExprContainingStmtRange containing(const Stmt &stmt);

  static std::optional<AsTypeExpr> from(const TokenContext &c);
  static std::optional<AsTypeExpr> from(const Expr &parent);
  static std::optional<AsTypeExpr> from(const ValueStmt &parent);
  static std::optional<AsTypeExpr> from(const Stmt &parent);
  Token builtin_token(void) const;
  Token r_paren_token(void) const;
  Expr src_expression(void) const;
};

using ArrayTypeTraitExprRange = DerivedEntityRange<StmtIterator, ArrayTypeTraitExpr>;
using ArrayTypeTraitExprContainingTokenRange = DerivedEntityRange<TokenContextIterator, ArrayTypeTraitExpr>;
using ArrayTypeTraitExprContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, ArrayTypeTraitExpr>;

class ArrayTypeTraitExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static ArrayTypeTraitExprRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static ArrayTypeTraitExprContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static ArrayTypeTraitExprContainingStmtRange containing(const Decl &decl);
  static ArrayTypeTraitExprContainingStmtRange containing(const Stmt &stmt);

  static std::optional<ArrayTypeTraitExpr> from(const TokenContext &c);
  static std::optional<ArrayTypeTraitExpr> from(const Expr &parent);
  static std::optional<ArrayTypeTraitExpr> from(const ValueStmt &parent);
  static std::optional<ArrayTypeTraitExpr> from(const Stmt &parent);
  Expr dimension_expression(void) const;
  ArrayTypeTrait trait(void) const;
};

using ArraySubscriptExprRange = DerivedEntityRange<StmtIterator, ArraySubscriptExpr>;
using ArraySubscriptExprContainingTokenRange = DerivedEntityRange<TokenContextIterator, ArraySubscriptExpr>;
using ArraySubscriptExprContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, ArraySubscriptExpr>;

class ArraySubscriptExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static ArraySubscriptExprRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static ArraySubscriptExprContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static ArraySubscriptExprContainingStmtRange containing(const Decl &decl);
  static ArraySubscriptExprContainingStmtRange containing(const Stmt &stmt);

  static std::optional<ArraySubscriptExpr> from(const TokenContext &c);
  static std::optional<ArraySubscriptExpr> from(const Expr &parent);
  static std::optional<ArraySubscriptExpr> from(const ValueStmt &parent);
  static std::optional<ArraySubscriptExpr> from(const Stmt &parent);
  Expr base(void) const;
  Expr index(void) const;
  Expr lhs(void) const;
  Token r_bracket_token(void) const;
  Expr rhs(void) const;
};

using ArrayInitLoopExprRange = DerivedEntityRange<StmtIterator, ArrayInitLoopExpr>;
using ArrayInitLoopExprContainingTokenRange = DerivedEntityRange<TokenContextIterator, ArrayInitLoopExpr>;
using ArrayInitLoopExprContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, ArrayInitLoopExpr>;

class ArrayInitLoopExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static ArrayInitLoopExprRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static ArrayInitLoopExprContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static ArrayInitLoopExprContainingStmtRange containing(const Decl &decl);
  static ArrayInitLoopExprContainingStmtRange containing(const Stmt &stmt);

  static std::optional<ArrayInitLoopExpr> from(const TokenContext &c);
  static std::optional<ArrayInitLoopExpr> from(const Expr &parent);
  static std::optional<ArrayInitLoopExpr> from(const ValueStmt &parent);
  static std::optional<ArrayInitLoopExpr> from(const Stmt &parent);
  OpaqueValueExpr common_expression(void) const;
  Expr sub_expression(void) const;
};

using ArrayInitIndexExprRange = DerivedEntityRange<StmtIterator, ArrayInitIndexExpr>;
using ArrayInitIndexExprContainingTokenRange = DerivedEntityRange<TokenContextIterator, ArrayInitIndexExpr>;
using ArrayInitIndexExprContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, ArrayInitIndexExpr>;

class ArrayInitIndexExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static ArrayInitIndexExprRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static ArrayInitIndexExprContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static ArrayInitIndexExprContainingStmtRange containing(const Decl &decl);
  static ArrayInitIndexExprContainingStmtRange containing(const Stmt &stmt);

  static std::optional<ArrayInitIndexExpr> from(const TokenContext &c);
  static std::optional<ArrayInitIndexExpr> from(const Expr &parent);
  static std::optional<ArrayInitIndexExpr> from(const ValueStmt &parent);
  static std::optional<ArrayInitIndexExpr> from(const Stmt &parent);
};

using AddrLabelExprRange = DerivedEntityRange<StmtIterator, AddrLabelExpr>;
using AddrLabelExprContainingTokenRange = DerivedEntityRange<TokenContextIterator, AddrLabelExpr>;
using AddrLabelExprContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, AddrLabelExpr>;

class AddrLabelExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static AddrLabelExprRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static AddrLabelExprContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static AddrLabelExprContainingStmtRange containing(const Decl &decl);
  static AddrLabelExprContainingStmtRange containing(const Stmt &stmt);

  static std::optional<AddrLabelExpr> from(const TokenContext &c);
  static std::optional<AddrLabelExpr> from(const Expr &parent);
  static std::optional<AddrLabelExpr> from(const ValueStmt &parent);
  static std::optional<AddrLabelExpr> from(const Stmt &parent);
  Token amp_amp_token(void) const;
  LabelDecl label(void) const;
  Token label_token(void) const;
};

using AbstractConditionalOperatorRange = DerivedEntityRange<StmtIterator, AbstractConditionalOperator>;
using AbstractConditionalOperatorContainingTokenRange = DerivedEntityRange<TokenContextIterator, AbstractConditionalOperator>;
using AbstractConditionalOperatorContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, AbstractConditionalOperator>;

class AbstractConditionalOperator : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static AbstractConditionalOperatorRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static AbstractConditionalOperatorContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static AbstractConditionalOperatorContainingStmtRange containing(const Decl &decl);
  static AbstractConditionalOperatorContainingStmtRange containing(const Stmt &stmt);

  static std::optional<AbstractConditionalOperator> from(const TokenContext &c);
  static std::optional<AbstractConditionalOperator> from(const Expr &parent);
  static std::optional<AbstractConditionalOperator> from(const ValueStmt &parent);
  static std::optional<AbstractConditionalOperator> from(const Stmt &parent);
  Token colon_token(void) const;
  Expr condition(void) const;
  Expr false_expression(void) const;
  Token question_token(void) const;
  Expr true_expression(void) const;
};

using ConditionalOperatorRange = DerivedEntityRange<StmtIterator, ConditionalOperator>;
using ConditionalOperatorContainingTokenRange = DerivedEntityRange<TokenContextIterator, ConditionalOperator>;
using ConditionalOperatorContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, ConditionalOperator>;

class ConditionalOperator : public AbstractConditionalOperator {
 private:
  friend class FragmentImpl;
  friend class AbstractConditionalOperator;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static ConditionalOperatorRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static ConditionalOperatorContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static ConditionalOperatorContainingStmtRange containing(const Decl &decl);
  static ConditionalOperatorContainingStmtRange containing(const Stmt &stmt);

  static std::optional<ConditionalOperator> from(const TokenContext &c);
  static std::optional<ConditionalOperator> from(const AbstractConditionalOperator &parent);
  static std::optional<ConditionalOperator> from(const Expr &parent);
  static std::optional<ConditionalOperator> from(const ValueStmt &parent);
  static std::optional<ConditionalOperator> from(const Stmt &parent);
  Expr lhs(void) const;
  Expr rhs(void) const;
};

using BinaryConditionalOperatorRange = DerivedEntityRange<StmtIterator, BinaryConditionalOperator>;
using BinaryConditionalOperatorContainingTokenRange = DerivedEntityRange<TokenContextIterator, BinaryConditionalOperator>;
using BinaryConditionalOperatorContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, BinaryConditionalOperator>;

class BinaryConditionalOperator : public AbstractConditionalOperator {
 private:
  friend class FragmentImpl;
  friend class AbstractConditionalOperator;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static BinaryConditionalOperatorRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static BinaryConditionalOperatorContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static BinaryConditionalOperatorContainingStmtRange containing(const Decl &decl);
  static BinaryConditionalOperatorContainingStmtRange containing(const Stmt &stmt);

  static std::optional<BinaryConditionalOperator> from(const TokenContext &c);
  static std::optional<BinaryConditionalOperator> from(const AbstractConditionalOperator &parent);
  static std::optional<BinaryConditionalOperator> from(const Expr &parent);
  static std::optional<BinaryConditionalOperator> from(const ValueStmt &parent);
  static std::optional<BinaryConditionalOperator> from(const Stmt &parent);
  Expr common(void) const;
  OpaqueValueExpr opaque_value(void) const;
};

using VAArgExprRange = DerivedEntityRange<StmtIterator, VAArgExpr>;
using VAArgExprContainingTokenRange = DerivedEntityRange<TokenContextIterator, VAArgExpr>;
using VAArgExprContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, VAArgExpr>;

class VAArgExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static VAArgExprRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static VAArgExprContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static VAArgExprContainingStmtRange containing(const Decl &decl);
  static VAArgExprContainingStmtRange containing(const Stmt &stmt);

  static std::optional<VAArgExpr> from(const TokenContext &c);
  static std::optional<VAArgExpr> from(const Expr &parent);
  static std::optional<VAArgExpr> from(const ValueStmt &parent);
  static std::optional<VAArgExpr> from(const Stmt &parent);
  Token builtin_token(void) const;
  Token r_paren_token(void) const;
  Expr sub_expression(void) const;
  bool is_microsoft_abi(void) const;
};

using UnaryOperatorRange = DerivedEntityRange<StmtIterator, UnaryOperator>;
using UnaryOperatorContainingTokenRange = DerivedEntityRange<TokenContextIterator, UnaryOperator>;
using UnaryOperatorContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, UnaryOperator>;

class UnaryOperator : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static UnaryOperatorRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static UnaryOperatorContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static UnaryOperatorContainingStmtRange containing(const Decl &decl);
  static UnaryOperatorContainingStmtRange containing(const Stmt &stmt);

  static std::optional<UnaryOperator> from(const TokenContext &c);
  static std::optional<UnaryOperator> from(const Expr &parent);
  static std::optional<UnaryOperator> from(const ValueStmt &parent);
  static std::optional<UnaryOperator> from(const Stmt &parent);
  bool can_overflow(void) const;
  UnaryOperatorKind opcode(void) const;
  Token operator_token(void) const;
  Expr sub_expression(void) const;
  bool has_stored_fp_features(void) const;
  bool is_arithmetic_operation(void) const;
  bool is_decrement_operation(void) const;
  bool is_increment_decrement_operation(void) const;
  bool is_increment_operation(void) const;
  bool is_postfix(void) const;
  bool is_prefix(void) const;
};

using UnaryExprOrTypeTraitExprRange = DerivedEntityRange<StmtIterator, UnaryExprOrTypeTraitExpr>;
using UnaryExprOrTypeTraitExprContainingTokenRange = DerivedEntityRange<TokenContextIterator, UnaryExprOrTypeTraitExpr>;
using UnaryExprOrTypeTraitExprContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, UnaryExprOrTypeTraitExpr>;

class UnaryExprOrTypeTraitExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static UnaryExprOrTypeTraitExprRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static UnaryExprOrTypeTraitExprContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static UnaryExprOrTypeTraitExprContainingStmtRange containing(const Decl &decl);
  static UnaryExprOrTypeTraitExprContainingStmtRange containing(const Stmt &stmt);

  static std::optional<UnaryExprOrTypeTraitExpr> from(const TokenContext &c);
  static std::optional<UnaryExprOrTypeTraitExpr> from(const Expr &parent);
  static std::optional<UnaryExprOrTypeTraitExpr> from(const ValueStmt &parent);
  static std::optional<UnaryExprOrTypeTraitExpr> from(const Stmt &parent);
  std::optional<Expr> argument_expression(void) const;
  Token operator_token(void) const;
  Token r_paren_token(void) const;
  bool is_argument_type(void) const;
};

using TypoExprRange = DerivedEntityRange<StmtIterator, TypoExpr>;
using TypoExprContainingTokenRange = DerivedEntityRange<TokenContextIterator, TypoExpr>;
using TypoExprContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, TypoExpr>;

class TypoExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static TypoExprRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static TypoExprContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static TypoExprContainingStmtRange containing(const Decl &decl);
  static TypoExprContainingStmtRange containing(const Stmt &stmt);

  static std::optional<TypoExpr> from(const TokenContext &c);
  static std::optional<TypoExpr> from(const Expr &parent);
  static std::optional<TypoExpr> from(const ValueStmt &parent);
  static std::optional<TypoExpr> from(const Stmt &parent);
};

using TypeTraitExprRange = DerivedEntityRange<StmtIterator, TypeTraitExpr>;
using TypeTraitExprContainingTokenRange = DerivedEntityRange<TokenContextIterator, TypeTraitExpr>;
using TypeTraitExprContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, TypeTraitExpr>;

class TypeTraitExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static TypeTraitExprRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static TypeTraitExprContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static TypeTraitExprContainingStmtRange containing(const Decl &decl);
  static TypeTraitExprContainingStmtRange containing(const Stmt &stmt);

  static std::optional<TypeTraitExpr> from(const TokenContext &c);
  static std::optional<TypeTraitExpr> from(const Expr &parent);
  static std::optional<TypeTraitExpr> from(const ValueStmt &parent);
  static std::optional<TypeTraitExpr> from(const Stmt &parent);
  TypeTrait trait(void) const;
  bool value(void) const;
};

using SubstNonTypeTemplateParmPackExprRange = DerivedEntityRange<StmtIterator, SubstNonTypeTemplateParmPackExpr>;
using SubstNonTypeTemplateParmPackExprContainingTokenRange = DerivedEntityRange<TokenContextIterator, SubstNonTypeTemplateParmPackExpr>;
using SubstNonTypeTemplateParmPackExprContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, SubstNonTypeTemplateParmPackExpr>;

class SubstNonTypeTemplateParmPackExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static SubstNonTypeTemplateParmPackExprRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static SubstNonTypeTemplateParmPackExprContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static SubstNonTypeTemplateParmPackExprContainingStmtRange containing(const Decl &decl);
  static SubstNonTypeTemplateParmPackExprContainingStmtRange containing(const Stmt &stmt);

  static std::optional<SubstNonTypeTemplateParmPackExpr> from(const TokenContext &c);
  static std::optional<SubstNonTypeTemplateParmPackExpr> from(const Expr &parent);
  static std::optional<SubstNonTypeTemplateParmPackExpr> from(const ValueStmt &parent);
  static std::optional<SubstNonTypeTemplateParmPackExpr> from(const Stmt &parent);
  NonTypeTemplateParmDecl parameter_pack(void) const;
  Token parameter_pack_token(void) const;
};

using SubstNonTypeTemplateParmExprRange = DerivedEntityRange<StmtIterator, SubstNonTypeTemplateParmExpr>;
using SubstNonTypeTemplateParmExprContainingTokenRange = DerivedEntityRange<TokenContextIterator, SubstNonTypeTemplateParmExpr>;
using SubstNonTypeTemplateParmExprContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, SubstNonTypeTemplateParmExpr>;

class SubstNonTypeTemplateParmExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static SubstNonTypeTemplateParmExprRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static SubstNonTypeTemplateParmExprContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static SubstNonTypeTemplateParmExprContainingStmtRange containing(const Decl &decl);
  static SubstNonTypeTemplateParmExprContainingStmtRange containing(const Stmt &stmt);

  static std::optional<SubstNonTypeTemplateParmExpr> from(const TokenContext &c);
  static std::optional<SubstNonTypeTemplateParmExpr> from(const Expr &parent);
  static std::optional<SubstNonTypeTemplateParmExpr> from(const ValueStmt &parent);
  static std::optional<SubstNonTypeTemplateParmExpr> from(const Stmt &parent);
  Token name_token(void) const;
  NonTypeTemplateParmDecl parameter(void) const;
  Expr replacement(void) const;
  bool is_reference_parameter(void) const;
};

using StringLiteralRange = DerivedEntityRange<StmtIterator, StringLiteral>;
using StringLiteralContainingTokenRange = DerivedEntityRange<TokenContextIterator, StringLiteral>;
using StringLiteralContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, StringLiteral>;

class StringLiteral : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static StringLiteralRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static StringLiteralContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static StringLiteralContainingStmtRange containing(const Decl &decl);
  static StringLiteralContainingStmtRange containing(const Stmt &stmt);

  static std::optional<StringLiteral> from(const TokenContext &c);
  static std::optional<StringLiteral> from(const Expr &parent);
  static std::optional<StringLiteral> from(const ValueStmt &parent);
  static std::optional<StringLiteral> from(const Stmt &parent);
  bool contains_non_ascii(void) const;
  bool contains_non_ascii_or_null(void) const;
  std::string_view bytes(void) const;
  std::string_view string(void) const;
  bool is_ascii(void) const;
  bool is_pascal(void) const;
  bool is_utf16(void) const;
  bool is_utf32(void) const;
  bool is_utf8(void) const;
  bool is_wide(void) const;
};

using StmtExprRange = DerivedEntityRange<StmtIterator, StmtExpr>;
using StmtExprContainingTokenRange = DerivedEntityRange<TokenContextIterator, StmtExpr>;
using StmtExprContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, StmtExpr>;

class StmtExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static StmtExprRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static StmtExprContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static StmtExprContainingStmtRange containing(const Decl &decl);
  static StmtExprContainingStmtRange containing(const Stmt &stmt);

  static std::optional<StmtExpr> from(const TokenContext &c);
  static std::optional<StmtExpr> from(const Expr &parent);
  static std::optional<StmtExpr> from(const ValueStmt &parent);
  static std::optional<StmtExpr> from(const Stmt &parent);
  Token l_paren_token(void) const;
  Token r_paren_token(void) const;
  CompoundStmt sub_statement(void) const;
};

using SourceLocExprRange = DerivedEntityRange<StmtIterator, SourceLocExpr>;
using SourceLocExprContainingTokenRange = DerivedEntityRange<TokenContextIterator, SourceLocExpr>;
using SourceLocExprContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, SourceLocExpr>;

class SourceLocExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static SourceLocExprRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static SourceLocExprContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static SourceLocExprContainingStmtRange containing(const Decl &decl);
  static SourceLocExprContainingStmtRange containing(const Stmt &stmt);

  static std::optional<SourceLocExpr> from(const TokenContext &c);
  static std::optional<SourceLocExpr> from(const Expr &parent);
  static std::optional<SourceLocExpr> from(const ValueStmt &parent);
  static std::optional<SourceLocExpr> from(const Stmt &parent);
  std::string_view builtin_string(void) const;
  SourceLocExprIdentKind identifier_kind(void) const;
  Token token(void) const;
  bool is_int_type(void) const;
  bool is_string_type(void) const;
};

using SizeOfPackExprRange = DerivedEntityRange<StmtIterator, SizeOfPackExpr>;
using SizeOfPackExprContainingTokenRange = DerivedEntityRange<TokenContextIterator, SizeOfPackExpr>;
using SizeOfPackExprContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, SizeOfPackExpr>;

class SizeOfPackExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static SizeOfPackExprRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static SizeOfPackExprContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static SizeOfPackExprContainingStmtRange containing(const Decl &decl);
  static SizeOfPackExprContainingStmtRange containing(const Stmt &stmt);

  static std::optional<SizeOfPackExpr> from(const TokenContext &c);
  static std::optional<SizeOfPackExpr> from(const Expr &parent);
  static std::optional<SizeOfPackExpr> from(const ValueStmt &parent);
  static std::optional<SizeOfPackExpr> from(const Stmt &parent);
  Token operator_token(void) const;
  NamedDecl pack(void) const;
  Token pack_token(void) const;
  std::vector<TemplateArgument> partial_arguments(void) const;
  Token r_paren_token(void) const;
  bool is_partially_substituted(void) const;
};

using ShuffleVectorExprRange = DerivedEntityRange<StmtIterator, ShuffleVectorExpr>;
using ShuffleVectorExprContainingTokenRange = DerivedEntityRange<TokenContextIterator, ShuffleVectorExpr>;
using ShuffleVectorExprContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, ShuffleVectorExpr>;

class ShuffleVectorExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static ShuffleVectorExprRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static ShuffleVectorExprContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static ShuffleVectorExprContainingStmtRange containing(const Decl &decl);
  static ShuffleVectorExprContainingStmtRange containing(const Stmt &stmt);

  static std::optional<ShuffleVectorExpr> from(const TokenContext &c);
  static std::optional<ShuffleVectorExpr> from(const Expr &parent);
  static std::optional<ShuffleVectorExpr> from(const ValueStmt &parent);
  static std::optional<ShuffleVectorExpr> from(const Stmt &parent);
  Token builtin_token(void) const;
  Token r_paren_token(void) const;
};

using SYCLUniqueStableNameExprRange = DerivedEntityRange<StmtIterator, SYCLUniqueStableNameExpr>;
using SYCLUniqueStableNameExprContainingTokenRange = DerivedEntityRange<TokenContextIterator, SYCLUniqueStableNameExpr>;
using SYCLUniqueStableNameExprContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, SYCLUniqueStableNameExpr>;

class SYCLUniqueStableNameExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static SYCLUniqueStableNameExprRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static SYCLUniqueStableNameExprContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static SYCLUniqueStableNameExprContainingStmtRange containing(const Decl &decl);
  static SYCLUniqueStableNameExprContainingStmtRange containing(const Stmt &stmt);

  static std::optional<SYCLUniqueStableNameExpr> from(const TokenContext &c);
  static std::optional<SYCLUniqueStableNameExpr> from(const Expr &parent);
  static std::optional<SYCLUniqueStableNameExpr> from(const ValueStmt &parent);
  static std::optional<SYCLUniqueStableNameExpr> from(const Stmt &parent);
  std::string_view compute_name(void) const;
  Token l_paren_token(void) const;
  Token token(void) const;
  Token r_paren_token(void) const;
};

using RequiresExprRange = DerivedEntityRange<StmtIterator, RequiresExpr>;
using RequiresExprContainingTokenRange = DerivedEntityRange<TokenContextIterator, RequiresExpr>;
using RequiresExprContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, RequiresExpr>;

class RequiresExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static RequiresExprRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static RequiresExprContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static RequiresExprContainingStmtRange containing(const Decl &decl);
  static RequiresExprContainingStmtRange containing(const Stmt &stmt);

  static std::optional<RequiresExpr> from(const TokenContext &c);
  static std::optional<RequiresExpr> from(const Expr &parent);
  static std::optional<RequiresExpr> from(const ValueStmt &parent);
  static std::optional<RequiresExpr> from(const Stmt &parent);
  RequiresExprBodyDecl body(void) const;
  std::vector<ParmVarDecl> local_parameters(void) const;
  Token r_brace_token(void) const;
  Token requires_kw_token(void) const;
  bool is_satisfied(void) const;
};

using RecoveryExprRange = DerivedEntityRange<StmtIterator, RecoveryExpr>;
using RecoveryExprContainingTokenRange = DerivedEntityRange<TokenContextIterator, RecoveryExpr>;
using RecoveryExprContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, RecoveryExpr>;

class RecoveryExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static RecoveryExprRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static RecoveryExprContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static RecoveryExprContainingStmtRange containing(const Decl &decl);
  static RecoveryExprContainingStmtRange containing(const Stmt &stmt);

  static std::optional<RecoveryExpr> from(const TokenContext &c);
  static std::optional<RecoveryExpr> from(const Expr &parent);
  static std::optional<RecoveryExpr> from(const ValueStmt &parent);
  static std::optional<RecoveryExpr> from(const Stmt &parent);
  std::vector<Expr> sub_expressions(void) const;
};

using PseudoObjectExprRange = DerivedEntityRange<StmtIterator, PseudoObjectExpr>;
using PseudoObjectExprContainingTokenRange = DerivedEntityRange<TokenContextIterator, PseudoObjectExpr>;
using PseudoObjectExprContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, PseudoObjectExpr>;

class PseudoObjectExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static PseudoObjectExprRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static PseudoObjectExprContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static PseudoObjectExprContainingStmtRange containing(const Decl &decl);
  static PseudoObjectExprContainingStmtRange containing(const Stmt &stmt);

  static std::optional<PseudoObjectExpr> from(const TokenContext &c);
  static std::optional<PseudoObjectExpr> from(const Expr &parent);
  static std::optional<PseudoObjectExpr> from(const ValueStmt &parent);
  static std::optional<PseudoObjectExpr> from(const Stmt &parent);
  Expr result_expression(void) const;
  Expr syntactic_form(void) const;
  std::vector<Expr> semantics(void) const;
  std::vector<Expr> semantic_expressions(void) const;
};

using PredefinedExprRange = DerivedEntityRange<StmtIterator, PredefinedExpr>;
using PredefinedExprContainingTokenRange = DerivedEntityRange<TokenContextIterator, PredefinedExpr>;
using PredefinedExprContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, PredefinedExpr>;

class PredefinedExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static PredefinedExprRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static PredefinedExprContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static PredefinedExprContainingStmtRange containing(const Decl &decl);
  static PredefinedExprContainingStmtRange containing(const Stmt &stmt);

  static std::optional<PredefinedExpr> from(const TokenContext &c);
  static std::optional<PredefinedExpr> from(const Expr &parent);
  static std::optional<PredefinedExpr> from(const ValueStmt &parent);
  static std::optional<PredefinedExpr> from(const Stmt &parent);
  StringLiteral function_name(void) const;
  PredefinedExprIdentKind identifier_kind(void) const;
  std::string_view identifier_kind_name(void) const;
  Token token(void) const;
};

using ParenListExprRange = DerivedEntityRange<StmtIterator, ParenListExpr>;
using ParenListExprContainingTokenRange = DerivedEntityRange<TokenContextIterator, ParenListExpr>;
using ParenListExprContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, ParenListExpr>;

class ParenListExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static ParenListExprRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static ParenListExprContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static ParenListExprContainingStmtRange containing(const Decl &decl);
  static ParenListExprContainingStmtRange containing(const Stmt &stmt);

  static std::optional<ParenListExpr> from(const TokenContext &c);
  static std::optional<ParenListExpr> from(const Expr &parent);
  static std::optional<ParenListExpr> from(const ValueStmt &parent);
  static std::optional<ParenListExpr> from(const Stmt &parent);
  Token l_paren_token(void) const;
  Token r_paren_token(void) const;
  std::vector<Expr> expressions(void) const;
};

using ParenExprRange = DerivedEntityRange<StmtIterator, ParenExpr>;
using ParenExprContainingTokenRange = DerivedEntityRange<TokenContextIterator, ParenExpr>;
using ParenExprContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, ParenExpr>;

class ParenExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static ParenExprRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static ParenExprContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static ParenExprContainingStmtRange containing(const Decl &decl);
  static ParenExprContainingStmtRange containing(const Stmt &stmt);

  static std::optional<ParenExpr> from(const TokenContext &c);
  static std::optional<ParenExpr> from(const Expr &parent);
  static std::optional<ParenExpr> from(const ValueStmt &parent);
  static std::optional<ParenExpr> from(const Stmt &parent);
  Token l_paren(void) const;
  Token r_paren(void) const;
  Expr sub_expression(void) const;
};

using PackExpansionExprRange = DerivedEntityRange<StmtIterator, PackExpansionExpr>;
using PackExpansionExprContainingTokenRange = DerivedEntityRange<TokenContextIterator, PackExpansionExpr>;
using PackExpansionExprContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, PackExpansionExpr>;

class PackExpansionExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static PackExpansionExprRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static PackExpansionExprContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static PackExpansionExprContainingStmtRange containing(const Decl &decl);
  static PackExpansionExprContainingStmtRange containing(const Stmt &stmt);

  static std::optional<PackExpansionExpr> from(const TokenContext &c);
  static std::optional<PackExpansionExpr> from(const Expr &parent);
  static std::optional<PackExpansionExpr> from(const ValueStmt &parent);
  static std::optional<PackExpansionExpr> from(const Stmt &parent);
  Token ellipsis_token(void) const;
  Expr pattern(void) const;
};

using OverloadExprRange = DerivedEntityRange<StmtIterator, OverloadExpr>;
using OverloadExprContainingTokenRange = DerivedEntityRange<TokenContextIterator, OverloadExpr>;
using OverloadExprContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, OverloadExpr>;

class OverloadExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static OverloadExprRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static OverloadExprContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static OverloadExprContainingStmtRange containing(const Decl &decl);
  static OverloadExprContainingStmtRange containing(const Stmt &stmt);

  static std::optional<OverloadExpr> from(const TokenContext &c);
  static std::optional<OverloadExpr> from(const Expr &parent);
  static std::optional<OverloadExpr> from(const ValueStmt &parent);
  static std::optional<OverloadExpr> from(const Stmt &parent);
  Token l_angle_token(void) const;
  Token name_token(void) const;
  CXXRecordDecl naming_class(void) const;
  Token r_angle_token(void) const;
  Token template_keyword_token(void) const;
  bool has_explicit_template_arguments(void) const;
  bool has_template_keyword(void) const;
};

using UnresolvedMemberExprRange = DerivedEntityRange<StmtIterator, UnresolvedMemberExpr>;
using UnresolvedMemberExprContainingTokenRange = DerivedEntityRange<TokenContextIterator, UnresolvedMemberExpr>;
using UnresolvedMemberExprContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, UnresolvedMemberExpr>;

class UnresolvedMemberExpr : public OverloadExpr {
 private:
  friend class FragmentImpl;
  friend class OverloadExpr;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static UnresolvedMemberExprRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static UnresolvedMemberExprContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static UnresolvedMemberExprContainingStmtRange containing(const Decl &decl);
  static UnresolvedMemberExprContainingStmtRange containing(const Stmt &stmt);

  static std::optional<UnresolvedMemberExpr> from(const TokenContext &c);
  static std::optional<UnresolvedMemberExpr> from(const OverloadExpr &parent);
  static std::optional<UnresolvedMemberExpr> from(const Expr &parent);
  static std::optional<UnresolvedMemberExpr> from(const ValueStmt &parent);
  static std::optional<UnresolvedMemberExpr> from(const Stmt &parent);
  Expr base(void) const;
  Token member_token(void) const;
  Token operator_token(void) const;
  bool has_unresolved_using(void) const;
  bool is_arrow(void) const;
  bool is_implicit_access(void) const;
};

using UnresolvedLookupExprRange = DerivedEntityRange<StmtIterator, UnresolvedLookupExpr>;
using UnresolvedLookupExprContainingTokenRange = DerivedEntityRange<TokenContextIterator, UnresolvedLookupExpr>;
using UnresolvedLookupExprContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, UnresolvedLookupExpr>;

class UnresolvedLookupExpr : public OverloadExpr {
 private:
  friend class FragmentImpl;
  friend class OverloadExpr;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static UnresolvedLookupExprRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static UnresolvedLookupExprContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static UnresolvedLookupExprContainingStmtRange containing(const Decl &decl);
  static UnresolvedLookupExprContainingStmtRange containing(const Stmt &stmt);

  static std::optional<UnresolvedLookupExpr> from(const TokenContext &c);
  static std::optional<UnresolvedLookupExpr> from(const OverloadExpr &parent);
  static std::optional<UnresolvedLookupExpr> from(const Expr &parent);
  static std::optional<UnresolvedLookupExpr> from(const ValueStmt &parent);
  static std::optional<UnresolvedLookupExpr> from(const Stmt &parent);
  bool is_overloaded(void) const;
  bool requires_adl(void) const;
};

using OpaqueValueExprRange = DerivedEntityRange<StmtIterator, OpaqueValueExpr>;
using OpaqueValueExprContainingTokenRange = DerivedEntityRange<TokenContextIterator, OpaqueValueExpr>;
using OpaqueValueExprContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, OpaqueValueExpr>;

class OpaqueValueExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static OpaqueValueExprRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static OpaqueValueExprContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static OpaqueValueExprContainingStmtRange containing(const Decl &decl);
  static OpaqueValueExprContainingStmtRange containing(const Stmt &stmt);

  static std::optional<OpaqueValueExpr> from(const TokenContext &c);
  static std::optional<OpaqueValueExpr> from(const Expr &parent);
  static std::optional<OpaqueValueExpr> from(const ValueStmt &parent);
  static std::optional<OpaqueValueExpr> from(const Stmt &parent);
  Token token(void) const;
  Expr source_expression(void) const;
  bool is_unique(void) const;
};

using OffsetOfExprRange = DerivedEntityRange<StmtIterator, OffsetOfExpr>;
using OffsetOfExprContainingTokenRange = DerivedEntityRange<TokenContextIterator, OffsetOfExpr>;
using OffsetOfExprContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, OffsetOfExpr>;

class OffsetOfExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static OffsetOfExprRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static OffsetOfExprContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static OffsetOfExprContainingStmtRange containing(const Decl &decl);
  static OffsetOfExprContainingStmtRange containing(const Stmt &stmt);

  static std::optional<OffsetOfExpr> from(const TokenContext &c);
  static std::optional<OffsetOfExpr> from(const Expr &parent);
  static std::optional<OffsetOfExpr> from(const ValueStmt &parent);
  static std::optional<OffsetOfExpr> from(const Stmt &parent);
  Token operator_token(void) const;
  Token r_paren_token(void) const;
};

using ObjCSubscriptRefExprRange = DerivedEntityRange<StmtIterator, ObjCSubscriptRefExpr>;
using ObjCSubscriptRefExprContainingTokenRange = DerivedEntityRange<TokenContextIterator, ObjCSubscriptRefExpr>;
using ObjCSubscriptRefExprContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, ObjCSubscriptRefExpr>;

class ObjCSubscriptRefExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static ObjCSubscriptRefExprRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static ObjCSubscriptRefExprContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static ObjCSubscriptRefExprContainingStmtRange containing(const Decl &decl);
  static ObjCSubscriptRefExprContainingStmtRange containing(const Stmt &stmt);

  static std::optional<ObjCSubscriptRefExpr> from(const TokenContext &c);
  static std::optional<ObjCSubscriptRefExpr> from(const Expr &parent);
  static std::optional<ObjCSubscriptRefExpr> from(const ValueStmt &parent);
  static std::optional<ObjCSubscriptRefExpr> from(const Stmt &parent);
  ObjCMethodDecl at_index_method_declaration(void) const;
  Expr base_expression(void) const;
  Expr key_expression(void) const;
  Token r_bracket(void) const;
  bool is_array_subscript_reference_expression(void) const;
};

using ObjCStringLiteralRange = DerivedEntityRange<StmtIterator, ObjCStringLiteral>;
using ObjCStringLiteralContainingTokenRange = DerivedEntityRange<TokenContextIterator, ObjCStringLiteral>;
using ObjCStringLiteralContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, ObjCStringLiteral>;

class ObjCStringLiteral : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static ObjCStringLiteralRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static ObjCStringLiteralContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static ObjCStringLiteralContainingStmtRange containing(const Decl &decl);
  static ObjCStringLiteralContainingStmtRange containing(const Stmt &stmt);

  static std::optional<ObjCStringLiteral> from(const TokenContext &c);
  static std::optional<ObjCStringLiteral> from(const Expr &parent);
  static std::optional<ObjCStringLiteral> from(const ValueStmt &parent);
  static std::optional<ObjCStringLiteral> from(const Stmt &parent);
  Token at_token(void) const;
  StringLiteral string(void) const;
};

using ObjCSelectorExprRange = DerivedEntityRange<StmtIterator, ObjCSelectorExpr>;
using ObjCSelectorExprContainingTokenRange = DerivedEntityRange<TokenContextIterator, ObjCSelectorExpr>;
using ObjCSelectorExprContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, ObjCSelectorExpr>;

class ObjCSelectorExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static ObjCSelectorExprRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static ObjCSelectorExprContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static ObjCSelectorExprContainingStmtRange containing(const Decl &decl);
  static ObjCSelectorExprContainingStmtRange containing(const Stmt &stmt);

  static std::optional<ObjCSelectorExpr> from(const TokenContext &c);
  static std::optional<ObjCSelectorExpr> from(const Expr &parent);
  static std::optional<ObjCSelectorExpr> from(const ValueStmt &parent);
  static std::optional<ObjCSelectorExpr> from(const Stmt &parent);
  Token at_token(void) const;
  Token r_paren_token(void) const;
};

using ObjCProtocolExprRange = DerivedEntityRange<StmtIterator, ObjCProtocolExpr>;
using ObjCProtocolExprContainingTokenRange = DerivedEntityRange<TokenContextIterator, ObjCProtocolExpr>;
using ObjCProtocolExprContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, ObjCProtocolExpr>;

class ObjCProtocolExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static ObjCProtocolExprRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static ObjCProtocolExprContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static ObjCProtocolExprContainingStmtRange containing(const Decl &decl);
  static ObjCProtocolExprContainingStmtRange containing(const Stmt &stmt);

  static std::optional<ObjCProtocolExpr> from(const TokenContext &c);
  static std::optional<ObjCProtocolExpr> from(const Expr &parent);
  static std::optional<ObjCProtocolExpr> from(const ValueStmt &parent);
  static std::optional<ObjCProtocolExpr> from(const Stmt &parent);
  Token at_token(void) const;
  ObjCProtocolDecl protocol(void) const;
  Token protocol_id_token(void) const;
  Token r_paren_token(void) const;
};

using ObjCPropertyRefExprRange = DerivedEntityRange<StmtIterator, ObjCPropertyRefExpr>;
using ObjCPropertyRefExprContainingTokenRange = DerivedEntityRange<TokenContextIterator, ObjCPropertyRefExpr>;
using ObjCPropertyRefExprContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, ObjCPropertyRefExpr>;

class ObjCPropertyRefExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static ObjCPropertyRefExprRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static ObjCPropertyRefExprContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static ObjCPropertyRefExprContainingStmtRange containing(const Decl &decl);
  static ObjCPropertyRefExprContainingStmtRange containing(const Stmt &stmt);

  static std::optional<ObjCPropertyRefExpr> from(const TokenContext &c);
  static std::optional<ObjCPropertyRefExpr> from(const Expr &parent);
  static std::optional<ObjCPropertyRefExpr> from(const ValueStmt &parent);
  static std::optional<ObjCPropertyRefExpr> from(const Stmt &parent);
  Expr base(void) const;
  ObjCInterfaceDecl class_receiver(void) const;
  ObjCPropertyDecl explicit_property(void) const;
  ObjCMethodDecl implicit_property_getter(void) const;
  ObjCMethodDecl implicit_property_setter(void) const;
  Token token(void) const;
  Token receiver_token(void) const;
  bool is_class_receiver(void) const;
  bool is_explicit_property(void) const;
  bool is_implicit_property(void) const;
  bool is_messaging_getter(void) const;
  bool is_messaging_setter(void) const;
  bool is_object_receiver(void) const;
  bool is_super_receiver(void) const;
};

using ObjCMessageExprRange = DerivedEntityRange<StmtIterator, ObjCMessageExpr>;
using ObjCMessageExprContainingTokenRange = DerivedEntityRange<TokenContextIterator, ObjCMessageExpr>;
using ObjCMessageExprContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, ObjCMessageExpr>;

class ObjCMessageExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static ObjCMessageExprRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static ObjCMessageExprContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static ObjCMessageExprContainingStmtRange containing(const Decl &decl);
  static ObjCMessageExprContainingStmtRange containing(const Stmt &stmt);

  static std::optional<ObjCMessageExpr> from(const TokenContext &c);
  static std::optional<ObjCMessageExpr> from(const Expr &parent);
  static std::optional<ObjCMessageExpr> from(const ValueStmt &parent);
  static std::optional<ObjCMessageExpr> from(const Stmt &parent);
  std::vector<Expr> arguments(void) const;
  Expr instance_receiver(void) const;
  Token left_token(void) const;
  ObjCMethodDecl method_declaration(void) const;
  ObjCMethodFamily method_family(void) const;
  ObjCInterfaceDecl receiver_interface(void) const;
  ObjCMessageExprReceiverKind receiver_kind(void) const;
  TokenRange receiver_range(void) const;
  Token right_token(void) const;
  Token selector_start_token(void) const;
  Token super_token(void) const;
  bool is_class_message(void) const;
  bool is_delegate_initializer_call(void) const;
  bool is_implicit(void) const;
  bool is_instance_message(void) const;
  std::vector<Token> selector_tokens(void) const;
};

using ObjCIvarRefExprRange = DerivedEntityRange<StmtIterator, ObjCIvarRefExpr>;
using ObjCIvarRefExprContainingTokenRange = DerivedEntityRange<TokenContextIterator, ObjCIvarRefExpr>;
using ObjCIvarRefExprContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, ObjCIvarRefExpr>;

class ObjCIvarRefExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static ObjCIvarRefExprRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static ObjCIvarRefExprContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static ObjCIvarRefExprContainingStmtRange containing(const Decl &decl);
  static ObjCIvarRefExprContainingStmtRange containing(const Stmt &stmt);

  static std::optional<ObjCIvarRefExpr> from(const TokenContext &c);
  static std::optional<ObjCIvarRefExpr> from(const Expr &parent);
  static std::optional<ObjCIvarRefExpr> from(const ValueStmt &parent);
  static std::optional<ObjCIvarRefExpr> from(const Stmt &parent);
  Expr base(void) const;
  ObjCIvarDecl declaration(void) const;
  Token token(void) const;
  Token operation_token(void) const;
  bool is_arrow(void) const;
  bool is_free_instance_variable(void) const;
};

using ObjCIsaExprRange = DerivedEntityRange<StmtIterator, ObjCIsaExpr>;
using ObjCIsaExprContainingTokenRange = DerivedEntityRange<TokenContextIterator, ObjCIsaExpr>;
using ObjCIsaExprContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, ObjCIsaExpr>;

class ObjCIsaExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static ObjCIsaExprRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static ObjCIsaExprContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static ObjCIsaExprContainingStmtRange containing(const Decl &decl);
  static ObjCIsaExprContainingStmtRange containing(const Stmt &stmt);

  static std::optional<ObjCIsaExpr> from(const TokenContext &c);
  static std::optional<ObjCIsaExpr> from(const Expr &parent);
  static std::optional<ObjCIsaExpr> from(const ValueStmt &parent);
  static std::optional<ObjCIsaExpr> from(const Stmt &parent);
  Expr base(void) const;
  Token base_token_end(void) const;
  Token isa_member_token(void) const;
  Token operation_token(void) const;
  bool is_arrow(void) const;
};

using ObjCIndirectCopyRestoreExprRange = DerivedEntityRange<StmtIterator, ObjCIndirectCopyRestoreExpr>;
using ObjCIndirectCopyRestoreExprContainingTokenRange = DerivedEntityRange<TokenContextIterator, ObjCIndirectCopyRestoreExpr>;
using ObjCIndirectCopyRestoreExprContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, ObjCIndirectCopyRestoreExpr>;

class ObjCIndirectCopyRestoreExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static ObjCIndirectCopyRestoreExprRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static ObjCIndirectCopyRestoreExprContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static ObjCIndirectCopyRestoreExprContainingStmtRange containing(const Decl &decl);
  static ObjCIndirectCopyRestoreExprContainingStmtRange containing(const Stmt &stmt);

  static std::optional<ObjCIndirectCopyRestoreExpr> from(const TokenContext &c);
  static std::optional<ObjCIndirectCopyRestoreExpr> from(const Expr &parent);
  static std::optional<ObjCIndirectCopyRestoreExpr> from(const ValueStmt &parent);
  static std::optional<ObjCIndirectCopyRestoreExpr> from(const Stmt &parent);
  Expr sub_expression(void) const;
  bool should_copy(void) const;
};

using ObjCEncodeExprRange = DerivedEntityRange<StmtIterator, ObjCEncodeExpr>;
using ObjCEncodeExprContainingTokenRange = DerivedEntityRange<TokenContextIterator, ObjCEncodeExpr>;
using ObjCEncodeExprContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, ObjCEncodeExpr>;

class ObjCEncodeExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static ObjCEncodeExprRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static ObjCEncodeExprContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static ObjCEncodeExprContainingStmtRange containing(const Decl &decl);
  static ObjCEncodeExprContainingStmtRange containing(const Stmt &stmt);

  static std::optional<ObjCEncodeExpr> from(const TokenContext &c);
  static std::optional<ObjCEncodeExpr> from(const Expr &parent);
  static std::optional<ObjCEncodeExpr> from(const ValueStmt &parent);
  static std::optional<ObjCEncodeExpr> from(const Stmt &parent);
  Token at_token(void) const;
  Token r_paren_token(void) const;
};

using ObjCDictionaryLiteralRange = DerivedEntityRange<StmtIterator, ObjCDictionaryLiteral>;
using ObjCDictionaryLiteralContainingTokenRange = DerivedEntityRange<TokenContextIterator, ObjCDictionaryLiteral>;
using ObjCDictionaryLiteralContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, ObjCDictionaryLiteral>;

class ObjCDictionaryLiteral : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static ObjCDictionaryLiteralRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static ObjCDictionaryLiteralContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static ObjCDictionaryLiteralContainingStmtRange containing(const Decl &decl);
  static ObjCDictionaryLiteralContainingStmtRange containing(const Stmt &stmt);

  static std::optional<ObjCDictionaryLiteral> from(const TokenContext &c);
  static std::optional<ObjCDictionaryLiteral> from(const Expr &parent);
  static std::optional<ObjCDictionaryLiteral> from(const ValueStmt &parent);
  static std::optional<ObjCDictionaryLiteral> from(const Stmt &parent);
  ObjCMethodDecl dictionary_with_objects_method(void) const;
};

using ObjCBoxedExprRange = DerivedEntityRange<StmtIterator, ObjCBoxedExpr>;
using ObjCBoxedExprContainingTokenRange = DerivedEntityRange<TokenContextIterator, ObjCBoxedExpr>;
using ObjCBoxedExprContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, ObjCBoxedExpr>;

class ObjCBoxedExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static ObjCBoxedExprRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static ObjCBoxedExprContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static ObjCBoxedExprContainingStmtRange containing(const Decl &decl);
  static ObjCBoxedExprContainingStmtRange containing(const Stmt &stmt);

  static std::optional<ObjCBoxedExpr> from(const TokenContext &c);
  static std::optional<ObjCBoxedExpr> from(const Expr &parent);
  static std::optional<ObjCBoxedExpr> from(const ValueStmt &parent);
  static std::optional<ObjCBoxedExpr> from(const Stmt &parent);
  Token at_token(void) const;
  ObjCMethodDecl boxing_method(void) const;
  Expr sub_expression(void) const;
  bool is_expressible_as_constant_initializer(void) const;
};

using ObjCBoolLiteralExprRange = DerivedEntityRange<StmtIterator, ObjCBoolLiteralExpr>;
using ObjCBoolLiteralExprContainingTokenRange = DerivedEntityRange<TokenContextIterator, ObjCBoolLiteralExpr>;
using ObjCBoolLiteralExprContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, ObjCBoolLiteralExpr>;

class ObjCBoolLiteralExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static ObjCBoolLiteralExprRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static ObjCBoolLiteralExprContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static ObjCBoolLiteralExprContainingStmtRange containing(const Decl &decl);
  static ObjCBoolLiteralExprContainingStmtRange containing(const Stmt &stmt);

  static std::optional<ObjCBoolLiteralExpr> from(const TokenContext &c);
  static std::optional<ObjCBoolLiteralExpr> from(const Expr &parent);
  static std::optional<ObjCBoolLiteralExpr> from(const ValueStmt &parent);
  static std::optional<ObjCBoolLiteralExpr> from(const Stmt &parent);
  Token token(void) const;
  bool value(void) const;
};

using ObjCAvailabilityCheckExprRange = DerivedEntityRange<StmtIterator, ObjCAvailabilityCheckExpr>;
using ObjCAvailabilityCheckExprContainingTokenRange = DerivedEntityRange<TokenContextIterator, ObjCAvailabilityCheckExpr>;
using ObjCAvailabilityCheckExprContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, ObjCAvailabilityCheckExpr>;

class ObjCAvailabilityCheckExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static ObjCAvailabilityCheckExprRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static ObjCAvailabilityCheckExprContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static ObjCAvailabilityCheckExprContainingStmtRange containing(const Decl &decl);
  static ObjCAvailabilityCheckExprContainingStmtRange containing(const Stmt &stmt);

  static std::optional<ObjCAvailabilityCheckExpr> from(const TokenContext &c);
  static std::optional<ObjCAvailabilityCheckExpr> from(const Expr &parent);
  static std::optional<ObjCAvailabilityCheckExpr> from(const ValueStmt &parent);
  static std::optional<ObjCAvailabilityCheckExpr> from(const Stmt &parent);
  bool has_version(void) const;
};

using ObjCArrayLiteralRange = DerivedEntityRange<StmtIterator, ObjCArrayLiteral>;
using ObjCArrayLiteralContainingTokenRange = DerivedEntityRange<TokenContextIterator, ObjCArrayLiteral>;
using ObjCArrayLiteralContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, ObjCArrayLiteral>;

class ObjCArrayLiteral : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static ObjCArrayLiteralRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static ObjCArrayLiteralContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static ObjCArrayLiteralContainingStmtRange containing(const Decl &decl);
  static ObjCArrayLiteralContainingStmtRange containing(const Stmt &stmt);

  static std::optional<ObjCArrayLiteral> from(const TokenContext &c);
  static std::optional<ObjCArrayLiteral> from(const Expr &parent);
  static std::optional<ObjCArrayLiteral> from(const ValueStmt &parent);
  static std::optional<ObjCArrayLiteral> from(const Stmt &parent);
  ObjCMethodDecl array_with_objects_method(void) const;
  std::vector<Expr> elements(void) const;
};

using OMPIteratorExprRange = DerivedEntityRange<StmtIterator, OMPIteratorExpr>;
using OMPIteratorExprContainingTokenRange = DerivedEntityRange<TokenContextIterator, OMPIteratorExpr>;
using OMPIteratorExprContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, OMPIteratorExpr>;

class OMPIteratorExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static OMPIteratorExprRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static OMPIteratorExprContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static OMPIteratorExprContainingStmtRange containing(const Decl &decl);
  static OMPIteratorExprContainingStmtRange containing(const Stmt &stmt);

  static std::optional<OMPIteratorExpr> from(const TokenContext &c);
  static std::optional<OMPIteratorExpr> from(const Expr &parent);
  static std::optional<OMPIteratorExpr> from(const ValueStmt &parent);
  static std::optional<OMPIteratorExpr> from(const Stmt &parent);
  Token iterator_kw_token(void) const;
  Token l_paren_token(void) const;
  Token r_paren_token(void) const;
};

using OMPArrayShapingExprRange = DerivedEntityRange<StmtIterator, OMPArrayShapingExpr>;
using OMPArrayShapingExprContainingTokenRange = DerivedEntityRange<TokenContextIterator, OMPArrayShapingExpr>;
using OMPArrayShapingExprContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, OMPArrayShapingExpr>;

class OMPArrayShapingExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static OMPArrayShapingExprRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static OMPArrayShapingExprContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static OMPArrayShapingExprContainingStmtRange containing(const Decl &decl);
  static OMPArrayShapingExprContainingStmtRange containing(const Stmt &stmt);

  static std::optional<OMPArrayShapingExpr> from(const TokenContext &c);
  static std::optional<OMPArrayShapingExpr> from(const Expr &parent);
  static std::optional<OMPArrayShapingExpr> from(const ValueStmt &parent);
  static std::optional<OMPArrayShapingExpr> from(const Stmt &parent);
  Expr base(void) const;
  std::vector<Expr> dimensions(void) const;
  Token l_paren_token(void) const;
  Token r_paren_token(void) const;
};

using OMPArraySectionExprRange = DerivedEntityRange<StmtIterator, OMPArraySectionExpr>;
using OMPArraySectionExprContainingTokenRange = DerivedEntityRange<TokenContextIterator, OMPArraySectionExpr>;
using OMPArraySectionExprContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, OMPArraySectionExpr>;

class OMPArraySectionExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static OMPArraySectionExprRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static OMPArraySectionExprContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static OMPArraySectionExprContainingStmtRange containing(const Decl &decl);
  static OMPArraySectionExprContainingStmtRange containing(const Stmt &stmt);

  static std::optional<OMPArraySectionExpr> from(const TokenContext &c);
  static std::optional<OMPArraySectionExpr> from(const Expr &parent);
  static std::optional<OMPArraySectionExpr> from(const ValueStmt &parent);
  static std::optional<OMPArraySectionExpr> from(const Stmt &parent);
  Expr base(void) const;
  Token colon_token_first(void) const;
  Token colon_token_second(void) const;
  Expr length(void) const;
  Expr lower_bound(void) const;
  Token r_bracket_token(void) const;
  Expr stride(void) const;
};

using NoInitExprRange = DerivedEntityRange<StmtIterator, NoInitExpr>;
using NoInitExprContainingTokenRange = DerivedEntityRange<TokenContextIterator, NoInitExpr>;
using NoInitExprContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, NoInitExpr>;

class NoInitExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static NoInitExprRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static NoInitExprContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static NoInitExprContainingStmtRange containing(const Decl &decl);
  static NoInitExprContainingStmtRange containing(const Stmt &stmt);

  static std::optional<NoInitExpr> from(const TokenContext &c);
  static std::optional<NoInitExpr> from(const Expr &parent);
  static std::optional<NoInitExpr> from(const ValueStmt &parent);
  static std::optional<NoInitExpr> from(const Stmt &parent);
};

using MemberExprRange = DerivedEntityRange<StmtIterator, MemberExpr>;
using MemberExprContainingTokenRange = DerivedEntityRange<TokenContextIterator, MemberExpr>;
using MemberExprContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, MemberExpr>;

class MemberExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static MemberExprRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static MemberExprContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static MemberExprContainingStmtRange containing(const Decl &decl);
  static MemberExprContainingStmtRange containing(const Stmt &stmt);

  static std::optional<MemberExpr> from(const TokenContext &c);
  static std::optional<MemberExpr> from(const Expr &parent);
  static std::optional<MemberExpr> from(const ValueStmt &parent);
  static std::optional<MemberExpr> from(const Stmt &parent);
  Expr base(void) const;
  Token l_angle_token(void) const;
  ValueDecl member_declaration(void) const;
  Token member_token(void) const;
  Token operator_token(void) const;
  Token r_angle_token(void) const;
  Token template_keyword_token(void) const;
  bool had_multiple_candidates(void) const;
  bool has_explicit_template_arguments(void) const;
  bool has_qualifier(void) const;
  bool has_template_keyword(void) const;
  bool is_arrow(void) const;
  bool is_implicit_access(void) const;
  NonOdrUseReason is_non_odr_use(void) const;
};

using MatrixSubscriptExprRange = DerivedEntityRange<StmtIterator, MatrixSubscriptExpr>;
using MatrixSubscriptExprContainingTokenRange = DerivedEntityRange<TokenContextIterator, MatrixSubscriptExpr>;
using MatrixSubscriptExprContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, MatrixSubscriptExpr>;

class MatrixSubscriptExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static MatrixSubscriptExprRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static MatrixSubscriptExprContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static MatrixSubscriptExprContainingStmtRange containing(const Decl &decl);
  static MatrixSubscriptExprContainingStmtRange containing(const Stmt &stmt);

  static std::optional<MatrixSubscriptExpr> from(const TokenContext &c);
  static std::optional<MatrixSubscriptExpr> from(const Expr &parent);
  static std::optional<MatrixSubscriptExpr> from(const ValueStmt &parent);
  static std::optional<MatrixSubscriptExpr> from(const Stmt &parent);
  Expr base(void) const;
  Expr column_index(void) const;
  Token r_bracket_token(void) const;
  Expr row_index(void) const;
  bool is_incomplete(void) const;
};

using MaterializeTemporaryExprRange = DerivedEntityRange<StmtIterator, MaterializeTemporaryExpr>;
using MaterializeTemporaryExprContainingTokenRange = DerivedEntityRange<TokenContextIterator, MaterializeTemporaryExpr>;
using MaterializeTemporaryExprContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, MaterializeTemporaryExpr>;

class MaterializeTemporaryExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static MaterializeTemporaryExprRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static MaterializeTemporaryExprContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static MaterializeTemporaryExprContainingStmtRange containing(const Decl &decl);
  static MaterializeTemporaryExprContainingStmtRange containing(const Stmt &stmt);

  static std::optional<MaterializeTemporaryExpr> from(const TokenContext &c);
  static std::optional<MaterializeTemporaryExpr> from(const Expr &parent);
  static std::optional<MaterializeTemporaryExpr> from(const ValueStmt &parent);
  static std::optional<MaterializeTemporaryExpr> from(const Stmt &parent);
  ValueDecl extending_declaration(void) const;
  LifetimeExtendedTemporaryDecl lifetime_extended_temporary_declaration(void) const;
  StorageDuration storage_duration(void) const;
  Expr sub_expression(void) const;
  bool is_bound_to_lvalue_reference(void) const;
  bool is_usable_in_constant_expressions(void) const;
};

using MSPropertySubscriptExprRange = DerivedEntityRange<StmtIterator, MSPropertySubscriptExpr>;
using MSPropertySubscriptExprContainingTokenRange = DerivedEntityRange<TokenContextIterator, MSPropertySubscriptExpr>;
using MSPropertySubscriptExprContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, MSPropertySubscriptExpr>;

class MSPropertySubscriptExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static MSPropertySubscriptExprRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static MSPropertySubscriptExprContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static MSPropertySubscriptExprContainingStmtRange containing(const Decl &decl);
  static MSPropertySubscriptExprContainingStmtRange containing(const Stmt &stmt);

  static std::optional<MSPropertySubscriptExpr> from(const TokenContext &c);
  static std::optional<MSPropertySubscriptExpr> from(const Expr &parent);
  static std::optional<MSPropertySubscriptExpr> from(const ValueStmt &parent);
  static std::optional<MSPropertySubscriptExpr> from(const Stmt &parent);
  Expr base(void) const;
  Expr index(void) const;
  Token r_bracket_token(void) const;
};

using MSPropertyRefExprRange = DerivedEntityRange<StmtIterator, MSPropertyRefExpr>;
using MSPropertyRefExprContainingTokenRange = DerivedEntityRange<TokenContextIterator, MSPropertyRefExpr>;
using MSPropertyRefExprContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, MSPropertyRefExpr>;

class MSPropertyRefExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static MSPropertyRefExprRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static MSPropertyRefExprContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static MSPropertyRefExprContainingStmtRange containing(const Decl &decl);
  static MSPropertyRefExprContainingStmtRange containing(const Stmt &stmt);

  static std::optional<MSPropertyRefExpr> from(const TokenContext &c);
  static std::optional<MSPropertyRefExpr> from(const Expr &parent);
  static std::optional<MSPropertyRefExpr> from(const ValueStmt &parent);
  static std::optional<MSPropertyRefExpr> from(const Stmt &parent);
  Expr base_expression(void) const;
  Token member_token(void) const;
  MSPropertyDecl property_declaration(void) const;
  bool is_arrow(void) const;
  bool is_implicit_access(void) const;
};

using LambdaExprRange = DerivedEntityRange<StmtIterator, LambdaExpr>;
using LambdaExprContainingTokenRange = DerivedEntityRange<TokenContextIterator, LambdaExpr>;
using LambdaExprContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, LambdaExpr>;

class LambdaExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static LambdaExprRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static LambdaExprContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static LambdaExprContainingStmtRange containing(const Decl &decl);
  static LambdaExprContainingStmtRange containing(const Stmt &stmt);

  static std::optional<LambdaExpr> from(const TokenContext &c);
  static std::optional<LambdaExpr> from(const Expr &parent);
  static std::optional<LambdaExpr> from(const ValueStmt &parent);
  static std::optional<LambdaExpr> from(const Stmt &parent);
  Stmt body(void) const;
  CXXMethodDecl call_operator(void) const;
  LambdaCaptureDefault capture_default(void) const;
  Token capture_default_token(void) const;
  CompoundStmt compound_statement_body(void) const;
  std::vector<NamedDecl> explicit_template_parameters(void) const;
  TokenRange introducer_range(void) const;
  CXXRecordDecl lambda_class(void) const;
  std::optional<TemplateParameterList> template_parameter_list(void) const;
  std::optional<Expr> trailing_requires_clause(void) const;
  bool has_explicit_parameters(void) const;
  bool has_explicit_result_type(void) const;
  bool is_generic_lambda(void) const;
  bool is_mutable(void) const;
};

using IntegerLiteralRange = DerivedEntityRange<StmtIterator, IntegerLiteral>;
using IntegerLiteralContainingTokenRange = DerivedEntityRange<TokenContextIterator, IntegerLiteral>;
using IntegerLiteralContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, IntegerLiteral>;

class IntegerLiteral : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static IntegerLiteralRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static IntegerLiteralContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static IntegerLiteralContainingStmtRange containing(const Decl &decl);
  static IntegerLiteralContainingStmtRange containing(const Stmt &stmt);

  static std::optional<IntegerLiteral> from(const TokenContext &c);
  static std::optional<IntegerLiteral> from(const Expr &parent);
  static std::optional<IntegerLiteral> from(const ValueStmt &parent);
  static std::optional<IntegerLiteral> from(const Stmt &parent);
  Token token(void) const;
};

using InitListExprRange = DerivedEntityRange<StmtIterator, InitListExpr>;
using InitListExprContainingTokenRange = DerivedEntityRange<TokenContextIterator, InitListExpr>;
using InitListExprContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, InitListExpr>;

class InitListExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static InitListExprRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static InitListExprContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static InitListExprContainingStmtRange containing(const Decl &decl);
  static InitListExprContainingStmtRange containing(const Stmt &stmt);

  static std::optional<InitListExpr> from(const TokenContext &c);
  static std::optional<InitListExpr> from(const Expr &parent);
  static std::optional<InitListExpr> from(const ValueStmt &parent);
  static std::optional<InitListExpr> from(const Stmt &parent);
  std::optional<Expr> array_filler(void) const;
  std::optional<FieldDecl> initialized_field_in_union(void) const;
  Token l_brace_token(void) const;
  Token r_brace_token(void) const;
  std::optional<InitListExpr> semantic_form(void) const;
  std::optional<InitListExpr> syntactic_form(void) const;
  bool had_array_range_designator(void) const;
  bool has_array_filler(void) const;
  std::vector<Expr> initializers(void) const;
  bool is_explicit(void) const;
  bool is_semantic_form(void) const;
  bool is_string_literal_initializer(void) const;
  bool is_syntactic_form(void) const;
  bool is_transparent(void) const;
};

using ImplicitValueInitExprRange = DerivedEntityRange<StmtIterator, ImplicitValueInitExpr>;
using ImplicitValueInitExprContainingTokenRange = DerivedEntityRange<TokenContextIterator, ImplicitValueInitExpr>;
using ImplicitValueInitExprContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, ImplicitValueInitExpr>;

class ImplicitValueInitExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static ImplicitValueInitExprRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static ImplicitValueInitExprContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static ImplicitValueInitExprContainingStmtRange containing(const Decl &decl);
  static ImplicitValueInitExprContainingStmtRange containing(const Stmt &stmt);

  static std::optional<ImplicitValueInitExpr> from(const TokenContext &c);
  static std::optional<ImplicitValueInitExpr> from(const Expr &parent);
  static std::optional<ImplicitValueInitExpr> from(const ValueStmt &parent);
  static std::optional<ImplicitValueInitExpr> from(const Stmt &parent);
};

using ImaginaryLiteralRange = DerivedEntityRange<StmtIterator, ImaginaryLiteral>;
using ImaginaryLiteralContainingTokenRange = DerivedEntityRange<TokenContextIterator, ImaginaryLiteral>;
using ImaginaryLiteralContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, ImaginaryLiteral>;

class ImaginaryLiteral : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static ImaginaryLiteralRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static ImaginaryLiteralContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static ImaginaryLiteralContainingStmtRange containing(const Decl &decl);
  static ImaginaryLiteralContainingStmtRange containing(const Stmt &stmt);

  static std::optional<ImaginaryLiteral> from(const TokenContext &c);
  static std::optional<ImaginaryLiteral> from(const Expr &parent);
  static std::optional<ImaginaryLiteral> from(const ValueStmt &parent);
  static std::optional<ImaginaryLiteral> from(const Stmt &parent);
  Expr sub_expression(void) const;
};

using GenericSelectionExprRange = DerivedEntityRange<StmtIterator, GenericSelectionExpr>;
using GenericSelectionExprContainingTokenRange = DerivedEntityRange<TokenContextIterator, GenericSelectionExpr>;
using GenericSelectionExprContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, GenericSelectionExpr>;

class GenericSelectionExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static GenericSelectionExprRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static GenericSelectionExprContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static GenericSelectionExprContainingStmtRange containing(const Decl &decl);
  static GenericSelectionExprContainingStmtRange containing(const Stmt &stmt);

  static std::optional<GenericSelectionExpr> from(const TokenContext &c);
  static std::optional<GenericSelectionExpr> from(const Expr &parent);
  static std::optional<GenericSelectionExpr> from(const ValueStmt &parent);
  static std::optional<GenericSelectionExpr> from(const Stmt &parent);
  std::vector<Expr> association_expressions(void) const;
  Expr controlling_expression(void) const;
  Token default_token(void) const;
  Token generic_token(void) const;
  Token r_paren_token(void) const;
  Expr result_expression(void) const;
  bool is_result_dependent(void) const;
};

using GNUNullExprRange = DerivedEntityRange<StmtIterator, GNUNullExpr>;
using GNUNullExprContainingTokenRange = DerivedEntityRange<TokenContextIterator, GNUNullExpr>;
using GNUNullExprContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, GNUNullExpr>;

class GNUNullExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static GNUNullExprRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static GNUNullExprContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static GNUNullExprContainingStmtRange containing(const Decl &decl);
  static GNUNullExprContainingStmtRange containing(const Stmt &stmt);

  static std::optional<GNUNullExpr> from(const TokenContext &c);
  static std::optional<GNUNullExpr> from(const Expr &parent);
  static std::optional<GNUNullExpr> from(const ValueStmt &parent);
  static std::optional<GNUNullExpr> from(const Stmt &parent);
  Token token_token(void) const;
};

using FunctionParmPackExprRange = DerivedEntityRange<StmtIterator, FunctionParmPackExpr>;
using FunctionParmPackExprContainingTokenRange = DerivedEntityRange<TokenContextIterator, FunctionParmPackExpr>;
using FunctionParmPackExprContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, FunctionParmPackExpr>;

class FunctionParmPackExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static FunctionParmPackExprRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static FunctionParmPackExprContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static FunctionParmPackExprContainingStmtRange containing(const Decl &decl);
  static FunctionParmPackExprContainingStmtRange containing(const Stmt &stmt);

  static std::optional<FunctionParmPackExpr> from(const TokenContext &c);
  static std::optional<FunctionParmPackExpr> from(const Expr &parent);
  static std::optional<FunctionParmPackExpr> from(const ValueStmt &parent);
  static std::optional<FunctionParmPackExpr> from(const Stmt &parent);
  VarDecl parameter_pack(void) const;
  Token parameter_pack_token(void) const;
  std::vector<VarDecl> expansions(void) const;
};

using FullExprRange = DerivedEntityRange<StmtIterator, FullExpr>;
using FullExprContainingTokenRange = DerivedEntityRange<TokenContextIterator, FullExpr>;
using FullExprContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, FullExpr>;

class FullExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static FullExprRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static FullExprContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static FullExprContainingStmtRange containing(const Decl &decl);
  static FullExprContainingStmtRange containing(const Stmt &stmt);

  static std::optional<FullExpr> from(const TokenContext &c);
  static std::optional<FullExpr> from(const Expr &parent);
  static std::optional<FullExpr> from(const ValueStmt &parent);
  static std::optional<FullExpr> from(const Stmt &parent);
  Expr sub_expression(void) const;
};

using ExprWithCleanupsRange = DerivedEntityRange<StmtIterator, ExprWithCleanups>;
using ExprWithCleanupsContainingTokenRange = DerivedEntityRange<TokenContextIterator, ExprWithCleanups>;
using ExprWithCleanupsContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, ExprWithCleanups>;

class ExprWithCleanups : public FullExpr {
 private:
  friend class FragmentImpl;
  friend class FullExpr;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static ExprWithCleanupsRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static ExprWithCleanupsContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static ExprWithCleanupsContainingStmtRange containing(const Decl &decl);
  static ExprWithCleanupsContainingStmtRange containing(const Stmt &stmt);

  static std::optional<ExprWithCleanups> from(const TokenContext &c);
  static std::optional<ExprWithCleanups> from(const FullExpr &parent);
  static std::optional<ExprWithCleanups> from(const Expr &parent);
  static std::optional<ExprWithCleanups> from(const ValueStmt &parent);
  static std::optional<ExprWithCleanups> from(const Stmt &parent);
  bool cleanups_have_side_effects(void) const;
};

using ConstantExprRange = DerivedEntityRange<StmtIterator, ConstantExpr>;
using ConstantExprContainingTokenRange = DerivedEntityRange<TokenContextIterator, ConstantExpr>;
using ConstantExprContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, ConstantExpr>;

class ConstantExpr : public FullExpr {
 private:
  friend class FragmentImpl;
  friend class FullExpr;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static ConstantExprRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static ConstantExprContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static ConstantExprContainingStmtRange containing(const Decl &decl);
  static ConstantExprContainingStmtRange containing(const Stmt &stmt);

  static std::optional<ConstantExpr> from(const TokenContext &c);
  static std::optional<ConstantExpr> from(const FullExpr &parent);
  static std::optional<ConstantExpr> from(const Expr &parent);
  static std::optional<ConstantExpr> from(const ValueStmt &parent);
  static std::optional<ConstantExpr> from(const Stmt &parent);
  ConstantExprResultStorageKind result_storage_kind(void) const;
  bool has_ap_value_result(void) const;
  bool is_immediate_invocation(void) const;
};

using FloatingLiteralRange = DerivedEntityRange<StmtIterator, FloatingLiteral>;
using FloatingLiteralContainingTokenRange = DerivedEntityRange<TokenContextIterator, FloatingLiteral>;
using FloatingLiteralContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, FloatingLiteral>;

class FloatingLiteral : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static FloatingLiteralRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static FloatingLiteralContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static FloatingLiteralContainingStmtRange containing(const Decl &decl);
  static FloatingLiteralContainingStmtRange containing(const Stmt &stmt);

  static std::optional<FloatingLiteral> from(const TokenContext &c);
  static std::optional<FloatingLiteral> from(const Expr &parent);
  static std::optional<FloatingLiteral> from(const ValueStmt &parent);
  static std::optional<FloatingLiteral> from(const Stmt &parent);
  Token token(void) const;
  bool is_exact(void) const;
};

using FixedPointLiteralRange = DerivedEntityRange<StmtIterator, FixedPointLiteral>;
using FixedPointLiteralContainingTokenRange = DerivedEntityRange<TokenContextIterator, FixedPointLiteral>;
using FixedPointLiteralContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, FixedPointLiteral>;

class FixedPointLiteral : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static FixedPointLiteralRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static FixedPointLiteralContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static FixedPointLiteralContainingStmtRange containing(const Decl &decl);
  static FixedPointLiteralContainingStmtRange containing(const Stmt &stmt);

  static std::optional<FixedPointLiteral> from(const TokenContext &c);
  static std::optional<FixedPointLiteral> from(const Expr &parent);
  static std::optional<FixedPointLiteral> from(const ValueStmt &parent);
  static std::optional<FixedPointLiteral> from(const Stmt &parent);
  Token token(void) const;
};

using ExtVectorElementExprRange = DerivedEntityRange<StmtIterator, ExtVectorElementExpr>;
using ExtVectorElementExprContainingTokenRange = DerivedEntityRange<TokenContextIterator, ExtVectorElementExpr>;
using ExtVectorElementExprContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, ExtVectorElementExpr>;

class ExtVectorElementExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static ExtVectorElementExprRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static ExtVectorElementExprContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static ExtVectorElementExprContainingStmtRange containing(const Decl &decl);
  static ExtVectorElementExprContainingStmtRange containing(const Stmt &stmt);

  static std::optional<ExtVectorElementExpr> from(const TokenContext &c);
  static std::optional<ExtVectorElementExpr> from(const Expr &parent);
  static std::optional<ExtVectorElementExpr> from(const ValueStmt &parent);
  static std::optional<ExtVectorElementExpr> from(const Stmt &parent);
  bool contains_duplicate_elements(void) const;
  Token accessor_token(void) const;
  Expr base(void) const;
  bool is_arrow(void) const;
};

using ExpressionTraitExprRange = DerivedEntityRange<StmtIterator, ExpressionTraitExpr>;
using ExpressionTraitExprContainingTokenRange = DerivedEntityRange<TokenContextIterator, ExpressionTraitExpr>;
using ExpressionTraitExprContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, ExpressionTraitExpr>;

class ExpressionTraitExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static ExpressionTraitExprRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static ExpressionTraitExprContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static ExpressionTraitExprContainingStmtRange containing(const Decl &decl);
  static ExpressionTraitExprContainingStmtRange containing(const Stmt &stmt);

  static std::optional<ExpressionTraitExpr> from(const TokenContext &c);
  static std::optional<ExpressionTraitExpr> from(const Expr &parent);
  static std::optional<ExpressionTraitExpr> from(const ValueStmt &parent);
  static std::optional<ExpressionTraitExpr> from(const Stmt &parent);
  Expr queried_expression(void) const;
  ExpressionTrait trait(void) const;
  bool value(void) const;
};

using AttributedStmtRange = DerivedEntityRange<StmtIterator, AttributedStmt>;
using AttributedStmtContainingTokenRange = DerivedEntityRange<TokenContextIterator, AttributedStmt>;
using AttributedStmtContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, AttributedStmt>;

class AttributedStmt : public ValueStmt {
 private:
  friend class FragmentImpl;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static AttributedStmtRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static AttributedStmtContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static AttributedStmtContainingStmtRange containing(const Decl &decl);
  static AttributedStmtContainingStmtRange containing(const Stmt &stmt);

  static std::optional<AttributedStmt> from(const TokenContext &c);
  static std::optional<AttributedStmt> from(const ValueStmt &parent);
  static std::optional<AttributedStmt> from(const Stmt &parent);
  Token attribute_token(void) const;
  Stmt sub_statement(void) const;
};

using SwitchStmtRange = DerivedEntityRange<StmtIterator, SwitchStmt>;
using SwitchStmtContainingTokenRange = DerivedEntityRange<TokenContextIterator, SwitchStmt>;
using SwitchStmtContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, SwitchStmt>;

class SwitchStmt : public Stmt {
 private:
  friend class FragmentImpl;
  friend class Stmt;
 public:
  inline static SwitchStmtRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static SwitchStmtContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static SwitchStmtContainingStmtRange containing(const Decl &decl);
  static SwitchStmtContainingStmtRange containing(const Stmt &stmt);

  static std::optional<SwitchStmt> from(const TokenContext &c);
  static std::optional<SwitchStmt> from(const Stmt &parent);
  Stmt body(void) const;
  Expr condition(void) const;
  std::optional<VarDecl> condition_variable(void) const;
  std::optional<DeclStmt> condition_variable_declaration_statement(void) const;
  std::optional<Stmt> initializer(void) const;
  Token l_paren_token(void) const;
  Token r_paren_token(void) const;
  std::optional<SwitchCase> first_switch_case(void) const;
  Token switch_token(void) const;
  bool has_initializer_storage(void) const;
  bool has_variable_storage(void) const;
  bool is_all_enum_cases_covered(void) const;
};

using SwitchCaseRange = DerivedEntityRange<StmtIterator, SwitchCase>;
using SwitchCaseContainingTokenRange = DerivedEntityRange<TokenContextIterator, SwitchCase>;
using SwitchCaseContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, SwitchCase>;

class SwitchCase : public Stmt {
 private:
  friend class FragmentImpl;
  friend class Stmt;
 public:
  inline static SwitchCaseRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static SwitchCaseContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static SwitchCaseContainingStmtRange containing(const Decl &decl);
  static SwitchCaseContainingStmtRange containing(const Stmt &stmt);

  static std::optional<SwitchCase> from(const TokenContext &c);
  static std::optional<SwitchCase> from(const Stmt &parent);
  Token colon_token(void) const;
  Token keyword_token(void) const;
  std::optional<SwitchCase> next_switch_case(void) const;
  Stmt sub_statement(void) const;
};

using DefaultStmtRange = DerivedEntityRange<StmtIterator, DefaultStmt>;
using DefaultStmtContainingTokenRange = DerivedEntityRange<TokenContextIterator, DefaultStmt>;
using DefaultStmtContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, DefaultStmt>;

class DefaultStmt : public SwitchCase {
 private:
  friend class FragmentImpl;
  friend class SwitchCase;
  friend class Stmt;
 public:
  inline static DefaultStmtRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static DefaultStmtContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static DefaultStmtContainingStmtRange containing(const Decl &decl);
  static DefaultStmtContainingStmtRange containing(const Stmt &stmt);

  static std::optional<DefaultStmt> from(const TokenContext &c);
  static std::optional<DefaultStmt> from(const SwitchCase &parent);
  static std::optional<DefaultStmt> from(const Stmt &parent);
  Token default_token(void) const;
};

using CaseStmtRange = DerivedEntityRange<StmtIterator, CaseStmt>;
using CaseStmtContainingTokenRange = DerivedEntityRange<TokenContextIterator, CaseStmt>;
using CaseStmtContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, CaseStmt>;

class CaseStmt : public SwitchCase {
 private:
  friend class FragmentImpl;
  friend class SwitchCase;
  friend class Stmt;
 public:
  inline static CaseStmtRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static CaseStmtContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static CaseStmtContainingStmtRange containing(const Decl &decl);
  static CaseStmtContainingStmtRange containing(const Stmt &stmt);

  static std::optional<CaseStmt> from(const TokenContext &c);
  static std::optional<CaseStmt> from(const SwitchCase &parent);
  static std::optional<CaseStmt> from(const Stmt &parent);
  bool case_statement_is_gnu_range(void) const;
  Token case_token(void) const;
  Token ellipsis_token(void) const;
  Expr lhs(void) const;
  std::optional<Expr> rhs(void) const;
};

using DeclRange = DerivedEntityRange<DeclIterator, Decl>;
using DeclContainingTokenRange = DerivedEntityRange<TokenContextIterator, Decl>;
using DeclContainingDeclRange = DerivedEntityRange<ParentDeclIteratorImpl<Decl>, Decl>;

class Decl {
 protected:
  friend class Decl;
  friend class DeclIterator;
  friend class FragmentImpl;
  friend class Stmt;
  friend class StmtIterator;
  friend class TokenContext;
  std::shared_ptr<const FragmentImpl> fragment;
  unsigned offset;

 public:
  inline Decl(std::shared_ptr<const FragmentImpl> fragment_, unsigned offset_)
      : fragment(std::move(fragment_)),
        offset(offset_) {}

  inline static std::optional<Decl> from(const Decl &self) {
    return self;
  }

  inline static std::optional<Decl> from(const TokenContext &c) {
    return c.as_decl();
  }

  std::optional<Decl> parent_declaration(void) const;
  std::optional<Stmt> parent_statement(void) const;

 protected:
  static DeclIterator in_internal(const Fragment &fragment);

 public:
  inline static DeclRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static DeclContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static DeclContainingDeclRange containing(const Decl &decl);
  static DeclContainingDeclRange containing(const Stmt &stmt);

  AccessSpecifier access(void) const;
  AccessSpecifier access_unsafe(void) const;
  AvailabilityResult availability(void) const;
  Token begin_token(void) const;
  Token body_r_brace(void) const;
  Decl canonical_declaration(void) const;
  std::optional<TemplateParameterList> described_template_parameters(void) const;
  Token end_token(void) const;
  DeclFriendObjectKind friend_object_kind(void) const;
  DeclModuleOwnershipKind module_ownership_kind(void) const;
  Decl most_recent_declaration(void) const;
  std::optional<Decl> next_declaration_in_context(void) const;
  std::optional<Decl> non_closure_context(void) const;
  std::optional<Decl> previous_declaration(void) const;
  bool has_attributes(void) const;
  bool has_defining_attribute(void) const;
  bool has_owning_module(void) const;
  bool has_tag_identifier_namespace(void) const;
  bool is_canonical_declaration(void) const;
  bool is_defined_outside_function_or_method(void) const;
  bool is_deprecated(void) const;
  bool is_first_declaration(void) const;
  bool is_function_or_function_template(void) const;
  bool is_implicit(void) const;
  bool is_in_anonymous_namespace(void) const;
  bool is_in_local_scope_for_instantiation(void) const;
  bool is_in_std_namespace(void) const;
  bool is_invalid_declaration(void) const;
  bool is_module_private(void) const;
  bool is_out_of_line(void) const;
  bool is_parameter_pack(void) const;
  bool is_referenced(void) const;
  bool is_template_declaration(void) const;
  bool is_template_parameter(void) const;
  bool is_template_parameter_pack(void) const;
  bool is_templated(void) const;
  bool is_this_declaration_referenced(void) const;
  bool is_top_level_declaration_in_obj_c_container(void) const;
  bool is_unavailable(void) const;
  bool is_unconditionally_visible(void) const;
  bool is_used(void) const;
  bool is_weak_imported(void) const;
  std::vector<Decl> redeclarations(void) const;
  DeclKind kind(void) const;
  Token token(void) const;
  TokenRange token_range(void) const;
};

using ClassScopeFunctionSpecializationDeclRange = DerivedEntityRange<DeclIterator, ClassScopeFunctionSpecializationDecl>;
using ClassScopeFunctionSpecializationDeclContainingTokenRange = DerivedEntityRange<TokenContextIterator, ClassScopeFunctionSpecializationDecl>;
using ClassScopeFunctionSpecializationDeclContainingDeclRange = DerivedEntityRange<ParentDeclIteratorImpl<Decl>, ClassScopeFunctionSpecializationDecl>;

class ClassScopeFunctionSpecializationDecl : public Decl {
 private:
  friend class FragmentImpl;
  friend class Decl;
 public:
  inline static ClassScopeFunctionSpecializationDeclRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static ClassScopeFunctionSpecializationDeclContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static ClassScopeFunctionSpecializationDeclContainingDeclRange containing(const Decl &decl);
  static ClassScopeFunctionSpecializationDeclContainingDeclRange containing(const Stmt &stmt);

  static std::optional<ClassScopeFunctionSpecializationDecl> from(const TokenContext &c);
  static std::optional<ClassScopeFunctionSpecializationDecl> from(const Decl &parent);
  CXXMethodDecl specialization(void) const;
  bool has_explicit_template_arguments(void) const;
};

using CapturedDeclRange = DerivedEntityRange<DeclIterator, CapturedDecl>;
using CapturedDeclContainingTokenRange = DerivedEntityRange<TokenContextIterator, CapturedDecl>;
using CapturedDeclContainingDeclRange = DerivedEntityRange<ParentDeclIteratorImpl<Decl>, CapturedDecl>;

class CapturedDecl : public Decl {
 private:
  friend class FragmentImpl;
  friend class Decl;
 public:
  inline static CapturedDeclRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static CapturedDeclContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static CapturedDeclContainingDeclRange containing(const Decl &decl);
  static CapturedDeclContainingDeclRange containing(const Stmt &stmt);

  static std::optional<CapturedDecl> from(const TokenContext &c);
  static std::optional<CapturedDecl> from(const Decl &parent);
  ImplicitParamDecl context_parameter(void) const;
  bool is_nothrow(void) const;
  std::vector<ImplicitParamDecl> parameters(void) const;
  std::vector<Decl> declarations_in_context(void) const;
};

using BlockDeclRange = DerivedEntityRange<DeclIterator, BlockDecl>;
using BlockDeclContainingTokenRange = DerivedEntityRange<TokenContextIterator, BlockDecl>;
using BlockDeclContainingDeclRange = DerivedEntityRange<ParentDeclIteratorImpl<Decl>, BlockDecl>;

class BlockDecl : public Decl {
 private:
  friend class FragmentImpl;
  friend class Decl;
 public:
  inline static BlockDeclRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static BlockDeclContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static BlockDeclContainingDeclRange containing(const Decl &decl);
  static BlockDeclContainingDeclRange containing(const Stmt &stmt);

  static std::optional<BlockDecl> from(const TokenContext &c);
  static std::optional<BlockDecl> from(const Decl &parent);
  bool block_missing_return_type(void) const;
  bool can_avoid_copy_to_heap(void) const;
  bool captures_cxx_this(void) const;
  bool does_not_escape(void) const;
  Decl block_mangling_context_declaration(void) const;
  Token caret_token(void) const;
  CompoundStmt compound_body(void) const;
  bool has_captures(void) const;
  bool is_conversion_from_lambda(void) const;
  bool is_variadic(void) const;
  std::vector<ParmVarDecl> parameters(void) const;
  std::vector<ParmVarDecl> parameter_declarations(void) const;
  std::vector<Decl> declarations_in_context(void) const;
};

using AccessSpecDeclRange = DerivedEntityRange<DeclIterator, AccessSpecDecl>;
using AccessSpecDeclContainingTokenRange = DerivedEntityRange<TokenContextIterator, AccessSpecDecl>;
using AccessSpecDeclContainingDeclRange = DerivedEntityRange<ParentDeclIteratorImpl<Decl>, AccessSpecDecl>;

class AccessSpecDecl : public Decl {
 private:
  friend class FragmentImpl;
  friend class Decl;
 public:
  inline static AccessSpecDeclRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static AccessSpecDeclContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static AccessSpecDeclContainingDeclRange containing(const Decl &decl);
  static AccessSpecDeclContainingDeclRange containing(const Stmt &stmt);

  static std::optional<AccessSpecDecl> from(const TokenContext &c);
  static std::optional<AccessSpecDecl> from(const Decl &parent);
  Token access_specifier_token(void) const;
  Token colon_token(void) const;
};

using OMPDeclarativeDirectiveDeclRange = DerivedEntityRange<DeclIterator, OMPDeclarativeDirectiveDecl>;
using OMPDeclarativeDirectiveDeclContainingTokenRange = DerivedEntityRange<TokenContextIterator, OMPDeclarativeDirectiveDecl>;
using OMPDeclarativeDirectiveDeclContainingDeclRange = DerivedEntityRange<ParentDeclIteratorImpl<Decl>, OMPDeclarativeDirectiveDecl>;

class OMPDeclarativeDirectiveDecl : public Decl {
 private:
  friend class FragmentImpl;
  friend class Decl;
 public:
  inline static OMPDeclarativeDirectiveDeclRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static OMPDeclarativeDirectiveDeclContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static OMPDeclarativeDirectiveDeclContainingDeclRange containing(const Decl &decl);
  static OMPDeclarativeDirectiveDeclContainingDeclRange containing(const Stmt &stmt);

  static std::optional<OMPDeclarativeDirectiveDecl> from(const TokenContext &c);
  static std::optional<OMPDeclarativeDirectiveDecl> from(const Decl &parent);
};

using OMPThreadPrivateDeclRange = DerivedEntityRange<DeclIterator, OMPThreadPrivateDecl>;
using OMPThreadPrivateDeclContainingTokenRange = DerivedEntityRange<TokenContextIterator, OMPThreadPrivateDecl>;
using OMPThreadPrivateDeclContainingDeclRange = DerivedEntityRange<ParentDeclIteratorImpl<Decl>, OMPThreadPrivateDecl>;

class OMPThreadPrivateDecl : public OMPDeclarativeDirectiveDecl {
 private:
  friend class FragmentImpl;
  friend class OMPDeclarativeDirectiveDecl;
  friend class Decl;
 public:
  inline static OMPThreadPrivateDeclRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static OMPThreadPrivateDeclContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static OMPThreadPrivateDeclContainingDeclRange containing(const Decl &decl);
  static OMPThreadPrivateDeclContainingDeclRange containing(const Stmt &stmt);

  static std::optional<OMPThreadPrivateDecl> from(const TokenContext &c);
  static std::optional<OMPThreadPrivateDecl> from(const OMPDeclarativeDirectiveDecl &parent);
  static std::optional<OMPThreadPrivateDecl> from(const Decl &parent);
  std::vector<Expr> varlists(void) const;
};

using OMPRequiresDeclRange = DerivedEntityRange<DeclIterator, OMPRequiresDecl>;
using OMPRequiresDeclContainingTokenRange = DerivedEntityRange<TokenContextIterator, OMPRequiresDecl>;
using OMPRequiresDeclContainingDeclRange = DerivedEntityRange<ParentDeclIteratorImpl<Decl>, OMPRequiresDecl>;

class OMPRequiresDecl : public OMPDeclarativeDirectiveDecl {
 private:
  friend class FragmentImpl;
  friend class OMPDeclarativeDirectiveDecl;
  friend class Decl;
 public:
  inline static OMPRequiresDeclRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static OMPRequiresDeclContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static OMPRequiresDeclContainingDeclRange containing(const Decl &decl);
  static OMPRequiresDeclContainingDeclRange containing(const Stmt &stmt);

  static std::optional<OMPRequiresDecl> from(const TokenContext &c);
  static std::optional<OMPRequiresDecl> from(const OMPDeclarativeDirectiveDecl &parent);
  static std::optional<OMPRequiresDecl> from(const Decl &parent);
};

using OMPAllocateDeclRange = DerivedEntityRange<DeclIterator, OMPAllocateDecl>;
using OMPAllocateDeclContainingTokenRange = DerivedEntityRange<TokenContextIterator, OMPAllocateDecl>;
using OMPAllocateDeclContainingDeclRange = DerivedEntityRange<ParentDeclIteratorImpl<Decl>, OMPAllocateDecl>;

class OMPAllocateDecl : public OMPDeclarativeDirectiveDecl {
 private:
  friend class FragmentImpl;
  friend class OMPDeclarativeDirectiveDecl;
  friend class Decl;
 public:
  inline static OMPAllocateDeclRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static OMPAllocateDeclContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static OMPAllocateDeclContainingDeclRange containing(const Decl &decl);
  static OMPAllocateDeclContainingDeclRange containing(const Stmt &stmt);

  static std::optional<OMPAllocateDecl> from(const TokenContext &c);
  static std::optional<OMPAllocateDecl> from(const OMPDeclarativeDirectiveDecl &parent);
  static std::optional<OMPAllocateDecl> from(const Decl &parent);
  std::vector<Expr> varlists(void) const;
};

using TranslationUnitDeclRange = DerivedEntityRange<DeclIterator, TranslationUnitDecl>;
using TranslationUnitDeclContainingTokenRange = DerivedEntityRange<TokenContextIterator, TranslationUnitDecl>;
using TranslationUnitDeclContainingDeclRange = DerivedEntityRange<ParentDeclIteratorImpl<Decl>, TranslationUnitDecl>;

class TranslationUnitDecl : public Decl {
 private:
  friend class FragmentImpl;
  friend class Decl;
 public:
  inline static TranslationUnitDeclRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static TranslationUnitDeclContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static TranslationUnitDeclContainingDeclRange containing(const Decl &decl);
  static TranslationUnitDeclContainingDeclRange containing(const Stmt &stmt);

  static std::optional<TranslationUnitDecl> from(const TokenContext &c);
  static std::optional<TranslationUnitDecl> from(const Decl &parent);
  std::vector<Decl> declarations_in_context(void) const;
};

using StaticAssertDeclRange = DerivedEntityRange<DeclIterator, StaticAssertDecl>;
using StaticAssertDeclContainingTokenRange = DerivedEntityRange<TokenContextIterator, StaticAssertDecl>;
using StaticAssertDeclContainingDeclRange = DerivedEntityRange<ParentDeclIteratorImpl<Decl>, StaticAssertDecl>;

class StaticAssertDecl : public Decl {
 private:
  friend class FragmentImpl;
  friend class Decl;
 public:
  inline static StaticAssertDeclRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static StaticAssertDeclContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static StaticAssertDeclContainingDeclRange containing(const Decl &decl);
  static StaticAssertDeclContainingDeclRange containing(const Stmt &stmt);

  static std::optional<StaticAssertDecl> from(const TokenContext &c);
  static std::optional<StaticAssertDecl> from(const Decl &parent);
  Expr assert_expression(void) const;
  StringLiteral message(void) const;
  Token r_paren_token(void) const;
  bool is_failed(void) const;
};

using RequiresExprBodyDeclRange = DerivedEntityRange<DeclIterator, RequiresExprBodyDecl>;
using RequiresExprBodyDeclContainingTokenRange = DerivedEntityRange<TokenContextIterator, RequiresExprBodyDecl>;
using RequiresExprBodyDeclContainingDeclRange = DerivedEntityRange<ParentDeclIteratorImpl<Decl>, RequiresExprBodyDecl>;

class RequiresExprBodyDecl : public Decl {
 private:
  friend class FragmentImpl;
  friend class Decl;
 public:
  inline static RequiresExprBodyDeclRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static RequiresExprBodyDeclContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static RequiresExprBodyDeclContainingDeclRange containing(const Decl &decl);
  static RequiresExprBodyDeclContainingDeclRange containing(const Stmt &stmt);

  static std::optional<RequiresExprBodyDecl> from(const TokenContext &c);
  static std::optional<RequiresExprBodyDecl> from(const Decl &parent);
  std::vector<Decl> declarations_in_context(void) const;
};

using PragmaDetectMismatchDeclRange = DerivedEntityRange<DeclIterator, PragmaDetectMismatchDecl>;
using PragmaDetectMismatchDeclContainingTokenRange = DerivedEntityRange<TokenContextIterator, PragmaDetectMismatchDecl>;
using PragmaDetectMismatchDeclContainingDeclRange = DerivedEntityRange<ParentDeclIteratorImpl<Decl>, PragmaDetectMismatchDecl>;

class PragmaDetectMismatchDecl : public Decl {
 private:
  friend class FragmentImpl;
  friend class Decl;
 public:
  inline static PragmaDetectMismatchDeclRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static PragmaDetectMismatchDeclContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static PragmaDetectMismatchDeclContainingDeclRange containing(const Decl &decl);
  static PragmaDetectMismatchDeclContainingDeclRange containing(const Stmt &stmt);

  static std::optional<PragmaDetectMismatchDecl> from(const TokenContext &c);
  static std::optional<PragmaDetectMismatchDecl> from(const Decl &parent);
  std::string_view name(void) const;
  std::string_view value(void) const;
};

using PragmaCommentDeclRange = DerivedEntityRange<DeclIterator, PragmaCommentDecl>;
using PragmaCommentDeclContainingTokenRange = DerivedEntityRange<TokenContextIterator, PragmaCommentDecl>;
using PragmaCommentDeclContainingDeclRange = DerivedEntityRange<ParentDeclIteratorImpl<Decl>, PragmaCommentDecl>;

class PragmaCommentDecl : public Decl {
 private:
  friend class FragmentImpl;
  friend class Decl;
 public:
  inline static PragmaCommentDeclRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static PragmaCommentDeclContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static PragmaCommentDeclContainingDeclRange containing(const Decl &decl);
  static PragmaCommentDeclContainingDeclRange containing(const Stmt &stmt);

  static std::optional<PragmaCommentDecl> from(const TokenContext &c);
  static std::optional<PragmaCommentDecl> from(const Decl &parent);
  std::string_view argument(void) const;
  PragmaMSCommentKind comment_kind(void) const;
};

using ObjCPropertyImplDeclRange = DerivedEntityRange<DeclIterator, ObjCPropertyImplDecl>;
using ObjCPropertyImplDeclContainingTokenRange = DerivedEntityRange<TokenContextIterator, ObjCPropertyImplDecl>;
using ObjCPropertyImplDeclContainingDeclRange = DerivedEntityRange<ParentDeclIteratorImpl<Decl>, ObjCPropertyImplDecl>;

class ObjCPropertyImplDecl : public Decl {
 private:
  friend class FragmentImpl;
  friend class Decl;
 public:
  inline static ObjCPropertyImplDeclRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static ObjCPropertyImplDeclContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static ObjCPropertyImplDeclContainingDeclRange containing(const Decl &decl);
  static ObjCPropertyImplDeclContainingDeclRange containing(const Stmt &stmt);

  static std::optional<ObjCPropertyImplDecl> from(const TokenContext &c);
  static std::optional<ObjCPropertyImplDecl> from(const Decl &parent);
  Expr getter_cxx_constructor(void) const;
  ObjCMethodDecl getter_method_declaration(void) const;
  ObjCPropertyDecl property_declaration(void) const;
  ObjCPropertyImplDeclKind property_implementation(void) const;
  ObjCIvarDecl property_instance_variable_declaration(void) const;
  Token property_instance_variable_declaration_token(void) const;
  Expr setter_cxx_assignment(void) const;
  ObjCMethodDecl setter_method_declaration(void) const;
  bool is_instance_variable_name_specified(void) const;
};

using NamedDeclRange = DerivedEntityRange<DeclIterator, NamedDecl>;
using NamedDeclContainingTokenRange = DerivedEntityRange<TokenContextIterator, NamedDecl>;
using NamedDeclContainingDeclRange = DerivedEntityRange<ParentDeclIteratorImpl<Decl>, NamedDecl>;

class NamedDecl : public Decl {
 private:
  friend class FragmentImpl;
  friend class Decl;
 public:
  inline static NamedDeclRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static NamedDeclContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static NamedDeclContainingDeclRange containing(const Decl &decl);
  static NamedDeclContainingDeclRange containing(const Stmt &stmt);

  static std::optional<NamedDecl> from(const TokenContext &c);
  static std::optional<NamedDecl> from(const Decl &parent);
  Linkage formal_linkage(void) const;
  Linkage linkage_internal(void) const;
  std::string_view name(void) const;
  ObjCStringFormatFamily obj_cf_string_formatting_family(void) const;
  std::string_view qualified_name_as_string(void) const;
  NamedDecl underlying_declaration(void) const;
  Visibility visibility(void) const;
  bool has_external_formal_linkage(void) const;
  bool has_linkage(void) const;
  bool has_linkage_been_computed(void) const;
  bool is_cxx_class_member(void) const;
  bool is_cxx_instance_member(void) const;
  bool is_externally_declarable(void) const;
  bool is_externally_visible(void) const;
  bool is_linkage_valid(void) const;
};

using LabelDeclRange = DerivedEntityRange<DeclIterator, LabelDecl>;
using LabelDeclContainingTokenRange = DerivedEntityRange<TokenContextIterator, LabelDecl>;
using LabelDeclContainingDeclRange = DerivedEntityRange<ParentDeclIteratorImpl<Decl>, LabelDecl>;

class LabelDecl : public NamedDecl {
 private:
  friend class FragmentImpl;
  friend class NamedDecl;
  friend class Decl;
 public:
  inline static LabelDeclRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static LabelDeclContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static LabelDeclContainingDeclRange containing(const Decl &decl);
  static LabelDeclContainingDeclRange containing(const Stmt &stmt);

  static std::optional<LabelDecl> from(const TokenContext &c);
  static std::optional<LabelDecl> from(const NamedDecl &parent);
  static std::optional<LabelDecl> from(const Decl &parent);
  std::string_view ms_assembly_label(void) const;
  LabelStmt statement(void) const;
  bool is_gnu_local(void) const;
  bool is_ms_assembly_label(void) const;
  bool is_resolved_ms_assembly_label(void) const;
};

using BaseUsingDeclRange = DerivedEntityRange<DeclIterator, BaseUsingDecl>;
using BaseUsingDeclContainingTokenRange = DerivedEntityRange<TokenContextIterator, BaseUsingDecl>;
using BaseUsingDeclContainingDeclRange = DerivedEntityRange<ParentDeclIteratorImpl<Decl>, BaseUsingDecl>;

class BaseUsingDecl : public NamedDecl {
 private:
  friend class FragmentImpl;
  friend class NamedDecl;
  friend class Decl;
 public:
  inline static BaseUsingDeclRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static BaseUsingDeclContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static BaseUsingDeclContainingDeclRange containing(const Decl &decl);
  static BaseUsingDeclContainingDeclRange containing(const Stmt &stmt);

  static std::optional<BaseUsingDecl> from(const TokenContext &c);
  static std::optional<BaseUsingDecl> from(const NamedDecl &parent);
  static std::optional<BaseUsingDecl> from(const Decl &parent);
  std::vector<UsingShadowDecl> shadows(void) const;
};

using UsingEnumDeclRange = DerivedEntityRange<DeclIterator, UsingEnumDecl>;
using UsingEnumDeclContainingTokenRange = DerivedEntityRange<TokenContextIterator, UsingEnumDecl>;
using UsingEnumDeclContainingDeclRange = DerivedEntityRange<ParentDeclIteratorImpl<Decl>, UsingEnumDecl>;

class UsingEnumDecl : public BaseUsingDecl {
 private:
  friend class FragmentImpl;
  friend class BaseUsingDecl;
  friend class NamedDecl;
  friend class Decl;
 public:
  inline static UsingEnumDeclRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static UsingEnumDeclContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static UsingEnumDeclContainingDeclRange containing(const Decl &decl);
  static UsingEnumDeclContainingDeclRange containing(const Stmt &stmt);

  static std::optional<UsingEnumDecl> from(const TokenContext &c);
  static std::optional<UsingEnumDecl> from(const BaseUsingDecl &parent);
  static std::optional<UsingEnumDecl> from(const NamedDecl &parent);
  static std::optional<UsingEnumDecl> from(const Decl &parent);
  EnumDecl enum_declaration(void) const;
  Token enum_token(void) const;
  Token using_token(void) const;
};

using UsingDeclRange = DerivedEntityRange<DeclIterator, UsingDecl>;
using UsingDeclContainingTokenRange = DerivedEntityRange<TokenContextIterator, UsingDecl>;
using UsingDeclContainingDeclRange = DerivedEntityRange<ParentDeclIteratorImpl<Decl>, UsingDecl>;

class UsingDecl : public BaseUsingDecl {
 private:
  friend class FragmentImpl;
  friend class BaseUsingDecl;
  friend class NamedDecl;
  friend class Decl;
 public:
  inline static UsingDeclRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static UsingDeclContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static UsingDeclContainingDeclRange containing(const Decl &decl);
  static UsingDeclContainingDeclRange containing(const Stmt &stmt);

  static std::optional<UsingDecl> from(const TokenContext &c);
  static std::optional<UsingDecl> from(const BaseUsingDecl &parent);
  static std::optional<UsingDecl> from(const NamedDecl &parent);
  static std::optional<UsingDecl> from(const Decl &parent);
  Token using_token(void) const;
  bool has_typename(void) const;
  bool is_access_declaration(void) const;
};

using ValueDeclRange = DerivedEntityRange<DeclIterator, ValueDecl>;
using ValueDeclContainingTokenRange = DerivedEntityRange<TokenContextIterator, ValueDecl>;
using ValueDeclContainingDeclRange = DerivedEntityRange<ParentDeclIteratorImpl<Decl>, ValueDecl>;

class ValueDecl : public NamedDecl {
 private:
  friend class FragmentImpl;
  friend class NamedDecl;
  friend class Decl;
 public:
  inline static ValueDeclRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static ValueDeclContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static ValueDeclContainingDeclRange containing(const Decl &decl);
  static ValueDeclContainingDeclRange containing(const Stmt &stmt);

  static std::optional<ValueDecl> from(const TokenContext &c);
  static std::optional<ValueDecl> from(const NamedDecl &parent);
  static std::optional<ValueDecl> from(const Decl &parent);
  bool is_weak(void) const;
};

using UnresolvedUsingValueDeclRange = DerivedEntityRange<DeclIterator, UnresolvedUsingValueDecl>;
using UnresolvedUsingValueDeclContainingTokenRange = DerivedEntityRange<TokenContextIterator, UnresolvedUsingValueDecl>;
using UnresolvedUsingValueDeclContainingDeclRange = DerivedEntityRange<ParentDeclIteratorImpl<Decl>, UnresolvedUsingValueDecl>;

class UnresolvedUsingValueDecl : public ValueDecl {
 private:
  friend class FragmentImpl;
  friend class ValueDecl;
  friend class NamedDecl;
  friend class Decl;
 public:
  inline static UnresolvedUsingValueDeclRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static UnresolvedUsingValueDeclContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static UnresolvedUsingValueDeclContainingDeclRange containing(const Decl &decl);
  static UnresolvedUsingValueDeclContainingDeclRange containing(const Stmt &stmt);

  static std::optional<UnresolvedUsingValueDecl> from(const TokenContext &c);
  static std::optional<UnresolvedUsingValueDecl> from(const ValueDecl &parent);
  static std::optional<UnresolvedUsingValueDecl> from(const NamedDecl &parent);
  static std::optional<UnresolvedUsingValueDecl> from(const Decl &parent);
  Token ellipsis_token(void) const;
  Token using_token(void) const;
  bool is_access_declaration(void) const;
  bool is_pack_expansion(void) const;
};

using TemplateParamObjectDeclRange = DerivedEntityRange<DeclIterator, TemplateParamObjectDecl>;
using TemplateParamObjectDeclContainingTokenRange = DerivedEntityRange<TokenContextIterator, TemplateParamObjectDecl>;
using TemplateParamObjectDeclContainingDeclRange = DerivedEntityRange<ParentDeclIteratorImpl<Decl>, TemplateParamObjectDecl>;

class TemplateParamObjectDecl : public ValueDecl {
 private:
  friend class FragmentImpl;
  friend class ValueDecl;
  friend class NamedDecl;
  friend class Decl;
 public:
  inline static TemplateParamObjectDeclRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static TemplateParamObjectDeclContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static TemplateParamObjectDeclContainingDeclRange containing(const Decl &decl);
  static TemplateParamObjectDeclContainingDeclRange containing(const Stmt &stmt);

  static std::optional<TemplateParamObjectDecl> from(const TokenContext &c);
  static std::optional<TemplateParamObjectDecl> from(const ValueDecl &parent);
  static std::optional<TemplateParamObjectDecl> from(const NamedDecl &parent);
  static std::optional<TemplateParamObjectDecl> from(const Decl &parent);
};

using OMPDeclareReductionDeclRange = DerivedEntityRange<DeclIterator, OMPDeclareReductionDecl>;
using OMPDeclareReductionDeclContainingTokenRange = DerivedEntityRange<TokenContextIterator, OMPDeclareReductionDecl>;
using OMPDeclareReductionDeclContainingDeclRange = DerivedEntityRange<ParentDeclIteratorImpl<Decl>, OMPDeclareReductionDecl>;

class OMPDeclareReductionDecl : public ValueDecl {
 private:
  friend class FragmentImpl;
  friend class ValueDecl;
  friend class NamedDecl;
  friend class Decl;
 public:
  inline static OMPDeclareReductionDeclRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static OMPDeclareReductionDeclContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static OMPDeclareReductionDeclContainingDeclRange containing(const Decl &decl);
  static OMPDeclareReductionDeclContainingDeclRange containing(const Stmt &stmt);

  static std::optional<OMPDeclareReductionDecl> from(const TokenContext &c);
  static std::optional<OMPDeclareReductionDecl> from(const ValueDecl &parent);
  static std::optional<OMPDeclareReductionDecl> from(const NamedDecl &parent);
  static std::optional<OMPDeclareReductionDecl> from(const Decl &parent);
  Expr combiner(void) const;
  Expr combiner_in(void) const;
  Expr combiner_out(void) const;
  Expr initializer_original(void) const;
  Expr initializer_private(void) const;
  Expr initializer(void) const;
  OMPDeclareReductionDeclInitKind initializer_kind(void) const;
  OMPDeclareReductionDecl prev_declaration_in_scope(void) const;
  std::vector<Decl> declarations_in_context(void) const;
};

using MSGuidDeclRange = DerivedEntityRange<DeclIterator, MSGuidDecl>;
using MSGuidDeclContainingTokenRange = DerivedEntityRange<TokenContextIterator, MSGuidDecl>;
using MSGuidDeclContainingDeclRange = DerivedEntityRange<ParentDeclIteratorImpl<Decl>, MSGuidDecl>;

class MSGuidDecl : public ValueDecl {
 private:
  friend class FragmentImpl;
  friend class ValueDecl;
  friend class NamedDecl;
  friend class Decl;
 public:
  inline static MSGuidDeclRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static MSGuidDeclContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static MSGuidDeclContainingDeclRange containing(const Decl &decl);
  static MSGuidDeclContainingDeclRange containing(const Stmt &stmt);

  static std::optional<MSGuidDecl> from(const TokenContext &c);
  static std::optional<MSGuidDecl> from(const ValueDecl &parent);
  static std::optional<MSGuidDecl> from(const NamedDecl &parent);
  static std::optional<MSGuidDecl> from(const Decl &parent);
};

using IndirectFieldDeclRange = DerivedEntityRange<DeclIterator, IndirectFieldDecl>;
using IndirectFieldDeclContainingTokenRange = DerivedEntityRange<TokenContextIterator, IndirectFieldDecl>;
using IndirectFieldDeclContainingDeclRange = DerivedEntityRange<ParentDeclIteratorImpl<Decl>, IndirectFieldDecl>;

class IndirectFieldDecl : public ValueDecl {
 private:
  friend class FragmentImpl;
  friend class ValueDecl;
  friend class NamedDecl;
  friend class Decl;
 public:
  inline static IndirectFieldDeclRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static IndirectFieldDeclContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static IndirectFieldDeclContainingDeclRange containing(const Decl &decl);
  static IndirectFieldDeclContainingDeclRange containing(const Stmt &stmt);

  static std::optional<IndirectFieldDecl> from(const TokenContext &c);
  static std::optional<IndirectFieldDecl> from(const ValueDecl &parent);
  static std::optional<IndirectFieldDecl> from(const NamedDecl &parent);
  static std::optional<IndirectFieldDecl> from(const Decl &parent);
  std::vector<NamedDecl> chain(void) const;
  std::optional<FieldDecl> anonymous_field(void) const;
  std::optional<VarDecl> variable_declaration(void) const;
};

using EnumConstantDeclRange = DerivedEntityRange<DeclIterator, EnumConstantDecl>;
using EnumConstantDeclContainingTokenRange = DerivedEntityRange<TokenContextIterator, EnumConstantDecl>;
using EnumConstantDeclContainingDeclRange = DerivedEntityRange<ParentDeclIteratorImpl<Decl>, EnumConstantDecl>;

class EnumConstantDecl : public ValueDecl {
 private:
  friend class FragmentImpl;
  friend class ValueDecl;
  friend class NamedDecl;
  friend class Decl;
 public:
  inline static EnumConstantDeclRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static EnumConstantDeclContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static EnumConstantDeclContainingDeclRange containing(const Decl &decl);
  static EnumConstantDeclContainingDeclRange containing(const Stmt &stmt);

  static std::optional<EnumConstantDecl> from(const TokenContext &c);
  static std::optional<EnumConstantDecl> from(const ValueDecl &parent);
  static std::optional<EnumConstantDecl> from(const NamedDecl &parent);
  static std::optional<EnumConstantDecl> from(const Decl &parent);
  std::optional<Expr> initializer_expression(void) const;
};

using DeclaratorDeclRange = DerivedEntityRange<DeclIterator, DeclaratorDecl>;
using DeclaratorDeclContainingTokenRange = DerivedEntityRange<TokenContextIterator, DeclaratorDecl>;
using DeclaratorDeclContainingDeclRange = DerivedEntityRange<ParentDeclIteratorImpl<Decl>, DeclaratorDecl>;

class DeclaratorDecl : public ValueDecl {
 private:
  friend class FragmentImpl;
  friend class ValueDecl;
  friend class NamedDecl;
  friend class Decl;
 public:
  inline static DeclaratorDeclRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static DeclaratorDeclContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static DeclaratorDeclContainingDeclRange containing(const Decl &decl);
  static DeclaratorDeclContainingDeclRange containing(const Stmt &stmt);

  static std::optional<DeclaratorDecl> from(const TokenContext &c);
  static std::optional<DeclaratorDecl> from(const ValueDecl &parent);
  static std::optional<DeclaratorDecl> from(const NamedDecl &parent);
  static std::optional<DeclaratorDecl> from(const Decl &parent);
  Token inner_token_start(void) const;
  Token outer_token_start(void) const;
  std::optional<Expr> trailing_requires_clause(void) const;
  Token type_spec_end_token(void) const;
  Token type_spec_start_token(void) const;
  std::vector<TemplateParameterList> template_parameter_lists(void) const;
};

using VarDeclRange = DerivedEntityRange<DeclIterator, VarDecl>;
using VarDeclContainingTokenRange = DerivedEntityRange<TokenContextIterator, VarDecl>;
using VarDeclContainingDeclRange = DerivedEntityRange<ParentDeclIteratorImpl<Decl>, VarDecl>;

class VarDecl : public DeclaratorDecl {
 private:
  friend class FragmentImpl;
  friend class DeclaratorDecl;
  friend class ValueDecl;
  friend class NamedDecl;
  friend class Decl;
 public:
  inline static VarDeclRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static VarDeclContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static VarDeclContainingDeclRange containing(const Decl &decl);
  static VarDeclContainingDeclRange containing(const Stmt &stmt);

  static std::optional<VarDecl> from(const TokenContext &c);
  static std::optional<VarDecl> from(const DeclaratorDecl &parent);
  static std::optional<VarDecl> from(const ValueDecl &parent);
  static std::optional<VarDecl> from(const NamedDecl &parent);
  static std::optional<VarDecl> from(const Decl &parent);
  std::optional<VarDecl> acting_definition(void) const;
  std::optional<Expr> initializer(void) const;
  VarDeclInitializationStyle initializer_style(void) const;
  std::optional<VarDecl> initializing_declaration(void) const;
  std::optional<VarDecl> instantiated_from_static_data_member(void) const;
  LanguageLinkage language_linkage(void) const;
  Token point_of_instantiation(void) const;
  StorageClass storage_class(void) const;
  StorageDuration storage_duration(void) const;
  VarDeclTLSKind tls_kind(void) const;
  ThreadStorageClassSpecifier tsc_spec(void) const;
  std::optional<VarDecl> template_instantiation_pattern(void) const;
  TemplateSpecializationKind template_specialization_kind(void) const;
  TemplateSpecializationKind template_specialization_kind_for_instantiation(void) const;
  bool has_constant_initialization(void) const;
  bool has_dependent_alignment(void) const;
  bool has_external_storage(void) const;
  bool has_global_storage(void) const;
  bool has_initializer(void) const;
  bool has_local_storage(void) const;
  bool is_arc_pseudo_strong(void) const;
  bool is_cxx_for_range_declaration(void) const;
  bool is_constexpr(void) const;
  bool is_direct_initializer(void) const;
  bool is_escaping_byref(void) const;
  bool is_exception_variable(void) const;
  bool is_extern_c(void) const;
  bool is_file_variable_declaration(void) const;
  bool is_function_or_method_variable_declaration(void) const;
  bool is_in_extern_c_context(void) const;
  bool is_in_extern_cxx_context(void) const;
  bool is_initializer_capture(void) const;
  bool is_inline(void) const;
  bool is_inline_specified(void) const;
  bool is_known_to_be_defined(void) const;
  bool is_local_variable_declaration(void) const;
  bool is_local_variable_declaration_or_parm(void) const;
  bool is_nrvo_variable(void) const;
  bool is_no_destroy(void) const;
  bool is_non_escaping_byref(void) const;
  bool is_obj_c_for_declaration(void) const;
  bool is_previous_declaration_in_same_block_scope(void) const;
  bool is_static_data_member(void) const;
  bool is_static_local(void) const;
  bool is_this_declaration_a_demoted_definition(void) const;
  bool is_usable_in_constant_expressions(void) const;
  bool might_be_usable_in_constant_expressions(void) const;
  QualTypeDestructionKind needs_destruction(void) const;
};

using ParmVarDeclRange = DerivedEntityRange<DeclIterator, ParmVarDecl>;
using ParmVarDeclContainingTokenRange = DerivedEntityRange<TokenContextIterator, ParmVarDecl>;
using ParmVarDeclContainingDeclRange = DerivedEntityRange<ParentDeclIteratorImpl<Decl>, ParmVarDecl>;

class ParmVarDecl : public VarDecl {
 private:
  friend class FragmentImpl;
  friend class VarDecl;
  friend class DeclaratorDecl;
  friend class ValueDecl;
  friend class NamedDecl;
  friend class Decl;
 public:
  inline static ParmVarDeclRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static ParmVarDeclContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static ParmVarDeclContainingDeclRange containing(const Decl &decl);
  static ParmVarDeclContainingDeclRange containing(const Stmt &stmt);

  static std::optional<ParmVarDecl> from(const TokenContext &c);
  static std::optional<ParmVarDecl> from(const VarDecl &parent);
  static std::optional<ParmVarDecl> from(const DeclaratorDecl &parent);
  static std::optional<ParmVarDecl> from(const ValueDecl &parent);
  static std::optional<ParmVarDecl> from(const NamedDecl &parent);
  static std::optional<ParmVarDecl> from(const Decl &parent);
  std::optional<Expr> default_argument(void) const;
  TokenRange default_argument_range(void) const;
  DeclObjCDeclQualifier obj_c_decl_qualifier(void) const;
  std::optional<Expr> uninstantiated_default_argument(void) const;
  bool has_default_argument(void) const;
  bool has_inherited_default_argument(void) const;
  bool has_uninstantiated_default_argument(void) const;
  bool has_unparsed_default_argument(void) const;
  bool is_destroyed_in_callee(void) const;
  bool is_knr_promoted(void) const;
  bool is_obj_c_method_parameter(void) const;
};

using OMPCapturedExprDeclRange = DerivedEntityRange<DeclIterator, OMPCapturedExprDecl>;
using OMPCapturedExprDeclContainingTokenRange = DerivedEntityRange<TokenContextIterator, OMPCapturedExprDecl>;
using OMPCapturedExprDeclContainingDeclRange = DerivedEntityRange<ParentDeclIteratorImpl<Decl>, OMPCapturedExprDecl>;

class OMPCapturedExprDecl : public VarDecl {
 private:
  friend class FragmentImpl;
  friend class VarDecl;
  friend class DeclaratorDecl;
  friend class ValueDecl;
  friend class NamedDecl;
  friend class Decl;
 public:
  inline static OMPCapturedExprDeclRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static OMPCapturedExprDeclContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static OMPCapturedExprDeclContainingDeclRange containing(const Decl &decl);
  static OMPCapturedExprDeclContainingDeclRange containing(const Stmt &stmt);

  static std::optional<OMPCapturedExprDecl> from(const TokenContext &c);
  static std::optional<OMPCapturedExprDecl> from(const VarDecl &parent);
  static std::optional<OMPCapturedExprDecl> from(const DeclaratorDecl &parent);
  static std::optional<OMPCapturedExprDecl> from(const ValueDecl &parent);
  static std::optional<OMPCapturedExprDecl> from(const NamedDecl &parent);
  static std::optional<OMPCapturedExprDecl> from(const Decl &parent);
};

using ImplicitParamDeclRange = DerivedEntityRange<DeclIterator, ImplicitParamDecl>;
using ImplicitParamDeclContainingTokenRange = DerivedEntityRange<TokenContextIterator, ImplicitParamDecl>;
using ImplicitParamDeclContainingDeclRange = DerivedEntityRange<ParentDeclIteratorImpl<Decl>, ImplicitParamDecl>;

class ImplicitParamDecl : public VarDecl {
 private:
  friend class FragmentImpl;
  friend class VarDecl;
  friend class DeclaratorDecl;
  friend class ValueDecl;
  friend class NamedDecl;
  friend class Decl;
 public:
  inline static ImplicitParamDeclRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static ImplicitParamDeclContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static ImplicitParamDeclContainingDeclRange containing(const Decl &decl);
  static ImplicitParamDeclContainingDeclRange containing(const Stmt &stmt);

  static std::optional<ImplicitParamDecl> from(const TokenContext &c);
  static std::optional<ImplicitParamDecl> from(const VarDecl &parent);
  static std::optional<ImplicitParamDecl> from(const DeclaratorDecl &parent);
  static std::optional<ImplicitParamDecl> from(const ValueDecl &parent);
  static std::optional<ImplicitParamDecl> from(const NamedDecl &parent);
  static std::optional<ImplicitParamDecl> from(const Decl &parent);
  ImplicitParamDeclImplicitParamKind parameter_kind(void) const;
};

using DecompositionDeclRange = DerivedEntityRange<DeclIterator, DecompositionDecl>;
using DecompositionDeclContainingTokenRange = DerivedEntityRange<TokenContextIterator, DecompositionDecl>;
using DecompositionDeclContainingDeclRange = DerivedEntityRange<ParentDeclIteratorImpl<Decl>, DecompositionDecl>;

class DecompositionDecl : public VarDecl {
 private:
  friend class FragmentImpl;
  friend class VarDecl;
  friend class DeclaratorDecl;
  friend class ValueDecl;
  friend class NamedDecl;
  friend class Decl;
 public:
  inline static DecompositionDeclRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static DecompositionDeclContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static DecompositionDeclContainingDeclRange containing(const Decl &decl);
  static DecompositionDeclContainingDeclRange containing(const Stmt &stmt);

  static std::optional<DecompositionDecl> from(const TokenContext &c);
  static std::optional<DecompositionDecl> from(const VarDecl &parent);
  static std::optional<DecompositionDecl> from(const DeclaratorDecl &parent);
  static std::optional<DecompositionDecl> from(const ValueDecl &parent);
  static std::optional<DecompositionDecl> from(const NamedDecl &parent);
  static std::optional<DecompositionDecl> from(const Decl &parent);
  std::vector<BindingDecl> bindings(void) const;
};

using VarTemplateSpecializationDeclRange = DerivedEntityRange<DeclIterator, VarTemplateSpecializationDecl>;
using VarTemplateSpecializationDeclContainingTokenRange = DerivedEntityRange<TokenContextIterator, VarTemplateSpecializationDecl>;
using VarTemplateSpecializationDeclContainingDeclRange = DerivedEntityRange<ParentDeclIteratorImpl<Decl>, VarTemplateSpecializationDecl>;

class VarTemplateSpecializationDecl : public VarDecl {
 private:
  friend class FragmentImpl;
  friend class VarDecl;
  friend class DeclaratorDecl;
  friend class ValueDecl;
  friend class NamedDecl;
  friend class Decl;
 public:
  inline static VarTemplateSpecializationDeclRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static VarTemplateSpecializationDeclContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static VarTemplateSpecializationDeclContainingDeclRange containing(const Decl &decl);
  static VarTemplateSpecializationDeclContainingDeclRange containing(const Stmt &stmt);

  static std::optional<VarTemplateSpecializationDecl> from(const TokenContext &c);
  static std::optional<VarTemplateSpecializationDecl> from(const VarDecl &parent);
  static std::optional<VarTemplateSpecializationDecl> from(const DeclaratorDecl &parent);
  static std::optional<VarTemplateSpecializationDecl> from(const ValueDecl &parent);
  static std::optional<VarTemplateSpecializationDecl> from(const NamedDecl &parent);
  static std::optional<VarTemplateSpecializationDecl> from(const Decl &parent);
  Token extern_token(void) const;
  TemplateSpecializationKind specialization_kind(void) const;
  std::vector<TemplateArgument> template_arguments(void) const;
  std::vector<TemplateArgument> template_instantiation_arguments(void) const;
  Token template_keyword_token(void) const;
  bool is_class_scope_explicit_specialization(void) const;
  bool is_explicit_instantiation_or_specialization(void) const;
  bool is_explicit_specialization(void) const;
};

using VarTemplatePartialSpecializationDeclRange = DerivedEntityRange<DeclIterator, VarTemplatePartialSpecializationDecl>;
using VarTemplatePartialSpecializationDeclContainingTokenRange = DerivedEntityRange<TokenContextIterator, VarTemplatePartialSpecializationDecl>;
using VarTemplatePartialSpecializationDeclContainingDeclRange = DerivedEntityRange<ParentDeclIteratorImpl<Decl>, VarTemplatePartialSpecializationDecl>;

class VarTemplatePartialSpecializationDecl : public VarTemplateSpecializationDecl {
 private:
  friend class FragmentImpl;
  friend class VarTemplateSpecializationDecl;
  friend class VarDecl;
  friend class DeclaratorDecl;
  friend class ValueDecl;
  friend class NamedDecl;
  friend class Decl;
 public:
  inline static VarTemplatePartialSpecializationDeclRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static VarTemplatePartialSpecializationDeclContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static VarTemplatePartialSpecializationDeclContainingDeclRange containing(const Decl &decl);
  static VarTemplatePartialSpecializationDeclContainingDeclRange containing(const Stmt &stmt);

  static std::optional<VarTemplatePartialSpecializationDecl> from(const TokenContext &c);
  static std::optional<VarTemplatePartialSpecializationDecl> from(const VarTemplateSpecializationDecl &parent);
  static std::optional<VarTemplatePartialSpecializationDecl> from(const VarDecl &parent);
  static std::optional<VarTemplatePartialSpecializationDecl> from(const DeclaratorDecl &parent);
  static std::optional<VarTemplatePartialSpecializationDecl> from(const ValueDecl &parent);
  static std::optional<VarTemplatePartialSpecializationDecl> from(const NamedDecl &parent);
  static std::optional<VarTemplatePartialSpecializationDecl> from(const Decl &parent);
};

using NonTypeTemplateParmDeclRange = DerivedEntityRange<DeclIterator, NonTypeTemplateParmDecl>;
using NonTypeTemplateParmDeclContainingTokenRange = DerivedEntityRange<TokenContextIterator, NonTypeTemplateParmDecl>;
using NonTypeTemplateParmDeclContainingDeclRange = DerivedEntityRange<ParentDeclIteratorImpl<Decl>, NonTypeTemplateParmDecl>;

class NonTypeTemplateParmDecl : public DeclaratorDecl {
 private:
  friend class FragmentImpl;
  friend class DeclaratorDecl;
  friend class ValueDecl;
  friend class NamedDecl;
  friend class Decl;
 public:
  inline static NonTypeTemplateParmDeclRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static NonTypeTemplateParmDeclContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static NonTypeTemplateParmDeclContainingDeclRange containing(const Decl &decl);
  static NonTypeTemplateParmDeclContainingDeclRange containing(const Stmt &stmt);

  static std::optional<NonTypeTemplateParmDecl> from(const TokenContext &c);
  static std::optional<NonTypeTemplateParmDecl> from(const DeclaratorDecl &parent);
  static std::optional<NonTypeTemplateParmDecl> from(const ValueDecl &parent);
  static std::optional<NonTypeTemplateParmDecl> from(const NamedDecl &parent);
  static std::optional<NonTypeTemplateParmDecl> from(const Decl &parent);
  bool default_argument_was_inherited(void) const;
  Expr default_argument(void) const;
  Token default_argument_token(void) const;
  Expr placeholder_type_constraint(void) const;
  bool has_default_argument(void) const;
  bool has_placeholder_type_constraint(void) const;
  bool is_expanded_parameter_pack(void) const;
  bool is_pack_expansion(void) const;
};

using MSPropertyDeclRange = DerivedEntityRange<DeclIterator, MSPropertyDecl>;
using MSPropertyDeclContainingTokenRange = DerivedEntityRange<TokenContextIterator, MSPropertyDecl>;
using MSPropertyDeclContainingDeclRange = DerivedEntityRange<ParentDeclIteratorImpl<Decl>, MSPropertyDecl>;

class MSPropertyDecl : public DeclaratorDecl {
 private:
  friend class FragmentImpl;
  friend class DeclaratorDecl;
  friend class ValueDecl;
  friend class NamedDecl;
  friend class Decl;
 public:
  inline static MSPropertyDeclRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static MSPropertyDeclContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static MSPropertyDeclContainingDeclRange containing(const Decl &decl);
  static MSPropertyDeclContainingDeclRange containing(const Stmt &stmt);

  static std::optional<MSPropertyDecl> from(const TokenContext &c);
  static std::optional<MSPropertyDecl> from(const DeclaratorDecl &parent);
  static std::optional<MSPropertyDecl> from(const ValueDecl &parent);
  static std::optional<MSPropertyDecl> from(const NamedDecl &parent);
  static std::optional<MSPropertyDecl> from(const Decl &parent);
  bool has_getter(void) const;
  bool has_setter(void) const;
};

using FunctionDeclRange = DerivedEntityRange<DeclIterator, FunctionDecl>;
using FunctionDeclContainingTokenRange = DerivedEntityRange<TokenContextIterator, FunctionDecl>;
using FunctionDeclContainingDeclRange = DerivedEntityRange<ParentDeclIteratorImpl<Decl>, FunctionDecl>;

class FunctionDecl : public DeclaratorDecl {
 private:
  friend class FragmentImpl;
  friend class DeclaratorDecl;
  friend class ValueDecl;
  friend class NamedDecl;
  friend class Decl;
 public:
  inline static FunctionDeclRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static FunctionDeclContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static FunctionDeclContainingDeclRange containing(const Decl &decl);
  static FunctionDeclContainingDeclRange containing(const Stmt &stmt);

  static std::optional<FunctionDecl> from(const TokenContext &c);
  static std::optional<FunctionDecl> from(const DeclaratorDecl &parent);
  static std::optional<FunctionDecl> from(const ValueDecl &parent);
  static std::optional<FunctionDecl> from(const NamedDecl &parent);
  static std::optional<FunctionDecl> from(const Decl &parent);
  bool does_this_declaration_have_a_body(void) const;
  ConstexprSpecKind constexpr_kind(void) const;
  std::optional<FunctionDecl> definition(void) const;
  Token ellipsis_token(void) const;
  TokenRange exception_spec_source_range(void) const;
  ExceptionSpecificationType exception_spec_type(void) const;
  std::optional<FunctionDecl> instantiated_from_member_function(void) const;
  LanguageLinkage language_linkage(void) const;
  MultiVersionKind multi_version_kind(void) const;
  OverloadedOperatorKind overloaded_operator(void) const;
  TokenRange parameters_source_range(void) const;
  Token point_of_instantiation(void) const;
  TokenRange return_type_source_range(void) const;
  StorageClass storage_class(void) const;
  std::optional<FunctionDecl> template_instantiation_pattern(void) const;
  TemplateSpecializationKind template_specialization_kind(void) const;
  TemplateSpecializationKind template_specialization_kind_for_instantiation(void) const;
  FunctionDeclTemplatedKind templated_kind(void) const;
  bool has_implicit_return_zero(void) const;
  bool has_inherited_prototype(void) const;
  bool has_one_parameter_or_default_arguments(void) const;
  bool has_prototype(void) const;
  bool has_skipped_body(void) const;
  bool has_trivial_body(void) const;
  bool has_written_prototype(void) const;
  bool instantiation_is_pending(void) const;
  bool is_cpu_dispatch_multi_version(void) const;
  bool is_cpu_specific_multi_version(void) const;
  bool is_consteval(void) const;
  bool is_constexpr(void) const;
  bool is_constexpr_specified(void) const;
  bool is_defaulted(void) const;
  bool is_deleted(void) const;
  bool is_deleted_as_written(void) const;
  bool is_destroying_operator_delete(void) const;
  bool is_explicitly_defaulted(void) const;
  bool is_extern_c(void) const;
  bool is_function_template_specialization(void) const;
  bool is_global(void) const;
  bool is_implicitly_instantiable(void) const;
  bool is_in_extern_c_context(void) const;
  bool is_in_extern_cxx_context(void) const;
  bool is_inline_builtin_declaration(void) const;
  bool is_inline_specified(void) const;
  bool is_inlined(void) const;
  bool is_late_template_parsed(void) const;
  bool is_msvcrt_entry_point(void) const;
  bool is_main(void) const;
  bool is_multi_version(void) const;
  bool is_no_return(void) const;
  bool is_overloaded_operator(void) const;
  bool is_pure(void) const;
  bool is_replaceable_global_allocation_function(void) const;
  bool is_static(void) const;
  bool is_target_multi_version(void) const;
  bool is_template_instantiation(void) const;
  bool is_this_declaration_a_definition(void) const;
  bool is_this_declaration_instantiated_from_a_friend_definition(void) const;
  bool is_trivial(void) const;
  bool is_trivial_for_call(void) const;
  bool is_user_provided(void) const;
  bool is_variadic(void) const;
  bool is_virtual_as_written(void) const;
  std::vector<ParmVarDecl> parameters(void) const;
  bool uses_seh_try(void) const;
  bool will_have_body(void) const;
  std::optional<Stmt> body(void) const;
  std::vector<Decl> declarations_in_context(void) const;
};

using CXXMethodDeclRange = DerivedEntityRange<DeclIterator, CXXMethodDecl>;
using CXXMethodDeclContainingTokenRange = DerivedEntityRange<TokenContextIterator, CXXMethodDecl>;
using CXXMethodDeclContainingDeclRange = DerivedEntityRange<ParentDeclIteratorImpl<Decl>, CXXMethodDecl>;

class CXXMethodDecl : public FunctionDecl {
 private:
  friend class FragmentImpl;
  friend class FunctionDecl;
  friend class DeclaratorDecl;
  friend class ValueDecl;
  friend class NamedDecl;
  friend class Decl;
 public:
  inline static CXXMethodDeclRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static CXXMethodDeclContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static CXXMethodDeclContainingDeclRange containing(const Decl &decl);
  static CXXMethodDeclContainingDeclRange containing(const Stmt &stmt);

  static std::optional<CXXMethodDecl> from(const TokenContext &c);
  static std::optional<CXXMethodDecl> from(const FunctionDecl &parent);
  static std::optional<CXXMethodDecl> from(const DeclaratorDecl &parent);
  static std::optional<CXXMethodDecl> from(const ValueDecl &parent);
  static std::optional<CXXMethodDecl> from(const NamedDecl &parent);
  static std::optional<CXXMethodDecl> from(const Decl &parent);
  CXXRecordDecl parent(void) const;
  RefQualifierKind reference_qualifier(void) const;
  bool has_inline_body(void) const;
  bool is_const(void) const;
  bool is_copy_assignment_operator(void) const;
  bool is_instance(void) const;
  bool is_lambda_static_invoker(void) const;
  bool is_move_assignment_operator(void) const;
  bool is_virtual(void) const;
  bool is_volatile(void) const;
  std::vector<CXXMethodDecl> overridden_methods(void) const;
};

using CXXDestructorDeclRange = DerivedEntityRange<DeclIterator, CXXDestructorDecl>;
using CXXDestructorDeclContainingTokenRange = DerivedEntityRange<TokenContextIterator, CXXDestructorDecl>;
using CXXDestructorDeclContainingDeclRange = DerivedEntityRange<ParentDeclIteratorImpl<Decl>, CXXDestructorDecl>;

class CXXDestructorDecl : public CXXMethodDecl {
 private:
  friend class FragmentImpl;
  friend class CXXMethodDecl;
  friend class FunctionDecl;
  friend class DeclaratorDecl;
  friend class ValueDecl;
  friend class NamedDecl;
  friend class Decl;
 public:
  inline static CXXDestructorDeclRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static CXXDestructorDeclContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static CXXDestructorDeclContainingDeclRange containing(const Decl &decl);
  static CXXDestructorDeclContainingDeclRange containing(const Stmt &stmt);

  static std::optional<CXXDestructorDecl> from(const TokenContext &c);
  static std::optional<CXXDestructorDecl> from(const CXXMethodDecl &parent);
  static std::optional<CXXDestructorDecl> from(const FunctionDecl &parent);
  static std::optional<CXXDestructorDecl> from(const DeclaratorDecl &parent);
  static std::optional<CXXDestructorDecl> from(const ValueDecl &parent);
  static std::optional<CXXDestructorDecl> from(const NamedDecl &parent);
  static std::optional<CXXDestructorDecl> from(const Decl &parent);
  FunctionDecl operator_delete(void) const;
  Expr operator_delete_this_argument(void) const;
};

using CXXConversionDeclRange = DerivedEntityRange<DeclIterator, CXXConversionDecl>;
using CXXConversionDeclContainingTokenRange = DerivedEntityRange<TokenContextIterator, CXXConversionDecl>;
using CXXConversionDeclContainingDeclRange = DerivedEntityRange<ParentDeclIteratorImpl<Decl>, CXXConversionDecl>;

class CXXConversionDecl : public CXXMethodDecl {
 private:
  friend class FragmentImpl;
  friend class CXXMethodDecl;
  friend class FunctionDecl;
  friend class DeclaratorDecl;
  friend class ValueDecl;
  friend class NamedDecl;
  friend class Decl;
 public:
  inline static CXXConversionDeclRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static CXXConversionDeclContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static CXXConversionDeclContainingDeclRange containing(const Decl &decl);
  static CXXConversionDeclContainingDeclRange containing(const Stmt &stmt);

  static std::optional<CXXConversionDecl> from(const TokenContext &c);
  static std::optional<CXXConversionDecl> from(const CXXMethodDecl &parent);
  static std::optional<CXXConversionDecl> from(const FunctionDecl &parent);
  static std::optional<CXXConversionDecl> from(const DeclaratorDecl &parent);
  static std::optional<CXXConversionDecl> from(const ValueDecl &parent);
  static std::optional<CXXConversionDecl> from(const NamedDecl &parent);
  static std::optional<CXXConversionDecl> from(const Decl &parent);
  bool is_explicit(void) const;
  bool is_lambda_to_block_pointer_conversion(void) const;
};

using CXXConstructorDeclRange = DerivedEntityRange<DeclIterator, CXXConstructorDecl>;
using CXXConstructorDeclContainingTokenRange = DerivedEntityRange<TokenContextIterator, CXXConstructorDecl>;
using CXXConstructorDeclContainingDeclRange = DerivedEntityRange<ParentDeclIteratorImpl<Decl>, CXXConstructorDecl>;

class CXXConstructorDecl : public CXXMethodDecl {
 private:
  friend class FragmentImpl;
  friend class CXXMethodDecl;
  friend class FunctionDecl;
  friend class DeclaratorDecl;
  friend class ValueDecl;
  friend class NamedDecl;
  friend class Decl;
 public:
  inline static CXXConstructorDeclRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static CXXConstructorDeclContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static CXXConstructorDeclContainingDeclRange containing(const Decl &decl);
  static CXXConstructorDeclContainingDeclRange containing(const Stmt &stmt);

  static std::optional<CXXConstructorDecl> from(const TokenContext &c);
  static std::optional<CXXConstructorDecl> from(const CXXMethodDecl &parent);
  static std::optional<CXXConstructorDecl> from(const FunctionDecl &parent);
  static std::optional<CXXConstructorDecl> from(const DeclaratorDecl &parent);
  static std::optional<CXXConstructorDecl> from(const ValueDecl &parent);
  static std::optional<CXXConstructorDecl> from(const NamedDecl &parent);
  static std::optional<CXXConstructorDecl> from(const Decl &parent);
  CXXConstructorDecl target_constructor(void) const;
  bool is_default_constructor(void) const;
  bool is_delegating_constructor(void) const;
  bool is_explicit(void) const;
  bool is_inheriting_constructor(void) const;
  bool is_specialization_copying_object(void) const;
};

using CXXDeductionGuideDeclRange = DerivedEntityRange<DeclIterator, CXXDeductionGuideDecl>;
using CXXDeductionGuideDeclContainingTokenRange = DerivedEntityRange<TokenContextIterator, CXXDeductionGuideDecl>;
using CXXDeductionGuideDeclContainingDeclRange = DerivedEntityRange<ParentDeclIteratorImpl<Decl>, CXXDeductionGuideDecl>;

class CXXDeductionGuideDecl : public FunctionDecl {
 private:
  friend class FragmentImpl;
  friend class FunctionDecl;
  friend class DeclaratorDecl;
  friend class ValueDecl;
  friend class NamedDecl;
  friend class Decl;
 public:
  inline static CXXDeductionGuideDeclRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static CXXDeductionGuideDeclContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static CXXDeductionGuideDeclContainingDeclRange containing(const Decl &decl);
  static CXXDeductionGuideDeclContainingDeclRange containing(const Stmt &stmt);

  static std::optional<CXXDeductionGuideDecl> from(const TokenContext &c);
  static std::optional<CXXDeductionGuideDecl> from(const FunctionDecl &parent);
  static std::optional<CXXDeductionGuideDecl> from(const DeclaratorDecl &parent);
  static std::optional<CXXDeductionGuideDecl> from(const ValueDecl &parent);
  static std::optional<CXXDeductionGuideDecl> from(const NamedDecl &parent);
  static std::optional<CXXDeductionGuideDecl> from(const Decl &parent);
  CXXConstructorDecl corresponding_constructor(void) const;
  bool is_copy_deduction_candidate(void) const;
  bool is_explicit(void) const;
};

using FieldDeclRange = DerivedEntityRange<DeclIterator, FieldDecl>;
using FieldDeclContainingTokenRange = DerivedEntityRange<TokenContextIterator, FieldDecl>;
using FieldDeclContainingDeclRange = DerivedEntityRange<ParentDeclIteratorImpl<Decl>, FieldDecl>;

class FieldDecl : public DeclaratorDecl {
 private:
  friend class FragmentImpl;
  friend class DeclaratorDecl;
  friend class ValueDecl;
  friend class NamedDecl;
  friend class Decl;
 public:
  inline static FieldDeclRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static FieldDeclContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static FieldDeclContainingDeclRange containing(const Decl &decl);
  static FieldDeclContainingDeclRange containing(const Stmt &stmt);

  static std::optional<FieldDecl> from(const TokenContext &c);
  static std::optional<FieldDecl> from(const DeclaratorDecl &parent);
  static std::optional<FieldDecl> from(const ValueDecl &parent);
  static std::optional<FieldDecl> from(const NamedDecl &parent);
  static std::optional<FieldDecl> from(const Decl &parent);
  std::optional<Expr> bit_width(void) const;
  InClassInitStyle in_class_initializer_style(void) const;
  std::optional<Expr> in_class_initializer(void) const;
  RecordDecl parent(void) const;
  bool has_captured_vla_type(void) const;
  bool has_in_class_initializer(void) const;
  bool is_anonymous_struct_or_union(void) const;
  bool is_bit_field(void) const;
  bool is_mutable(void) const;
  bool is_unnamed_bitfield(void) const;
  bool is_zero_length_bit_field(void) const;
  bool is_zero_size(void) const;
};

using ObjCIvarDeclRange = DerivedEntityRange<DeclIterator, ObjCIvarDecl>;
using ObjCIvarDeclContainingTokenRange = DerivedEntityRange<TokenContextIterator, ObjCIvarDecl>;
using ObjCIvarDeclContainingDeclRange = DerivedEntityRange<ParentDeclIteratorImpl<Decl>, ObjCIvarDecl>;

class ObjCIvarDecl : public FieldDecl {
 private:
  friend class FragmentImpl;
  friend class FieldDecl;
  friend class DeclaratorDecl;
  friend class ValueDecl;
  friend class NamedDecl;
  friend class Decl;
 public:
  inline static ObjCIvarDeclRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static ObjCIvarDeclContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static ObjCIvarDeclContainingDeclRange containing(const Decl &decl);
  static ObjCIvarDeclContainingDeclRange containing(const Stmt &stmt);

  static std::optional<ObjCIvarDecl> from(const TokenContext &c);
  static std::optional<ObjCIvarDecl> from(const FieldDecl &parent);
  static std::optional<ObjCIvarDecl> from(const DeclaratorDecl &parent);
  static std::optional<ObjCIvarDecl> from(const ValueDecl &parent);
  static std::optional<ObjCIvarDecl> from(const NamedDecl &parent);
  static std::optional<ObjCIvarDecl> from(const Decl &parent);
  ObjCIvarDeclAccessControl access_control(void) const;
  ObjCIvarDeclAccessControl canonical_access_control(void) const;
  ObjCInterfaceDecl containing_interface(void) const;
  ObjCIvarDecl next_instance_variable(void) const;
  bool synthesize(void) const;
};

using ObjCAtDefsFieldDeclRange = DerivedEntityRange<DeclIterator, ObjCAtDefsFieldDecl>;
using ObjCAtDefsFieldDeclContainingTokenRange = DerivedEntityRange<TokenContextIterator, ObjCAtDefsFieldDecl>;
using ObjCAtDefsFieldDeclContainingDeclRange = DerivedEntityRange<ParentDeclIteratorImpl<Decl>, ObjCAtDefsFieldDecl>;

class ObjCAtDefsFieldDecl : public FieldDecl {
 private:
  friend class FragmentImpl;
  friend class FieldDecl;
  friend class DeclaratorDecl;
  friend class ValueDecl;
  friend class NamedDecl;
  friend class Decl;
 public:
  inline static ObjCAtDefsFieldDeclRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static ObjCAtDefsFieldDeclContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static ObjCAtDefsFieldDeclContainingDeclRange containing(const Decl &decl);
  static ObjCAtDefsFieldDeclContainingDeclRange containing(const Stmt &stmt);

  static std::optional<ObjCAtDefsFieldDecl> from(const TokenContext &c);
  static std::optional<ObjCAtDefsFieldDecl> from(const FieldDecl &parent);
  static std::optional<ObjCAtDefsFieldDecl> from(const DeclaratorDecl &parent);
  static std::optional<ObjCAtDefsFieldDecl> from(const ValueDecl &parent);
  static std::optional<ObjCAtDefsFieldDecl> from(const NamedDecl &parent);
  static std::optional<ObjCAtDefsFieldDecl> from(const Decl &parent);
};

using BindingDeclRange = DerivedEntityRange<DeclIterator, BindingDecl>;
using BindingDeclContainingTokenRange = DerivedEntityRange<TokenContextIterator, BindingDecl>;
using BindingDeclContainingDeclRange = DerivedEntityRange<ParentDeclIteratorImpl<Decl>, BindingDecl>;

class BindingDecl : public ValueDecl {
 private:
  friend class FragmentImpl;
  friend class ValueDecl;
  friend class NamedDecl;
  friend class Decl;
 public:
  inline static BindingDeclRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static BindingDeclContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static BindingDeclContainingDeclRange containing(const Decl &decl);
  static BindingDeclContainingDeclRange containing(const Stmt &stmt);

  static std::optional<BindingDecl> from(const TokenContext &c);
  static std::optional<BindingDecl> from(const ValueDecl &parent);
  static std::optional<BindingDecl> from(const NamedDecl &parent);
  static std::optional<BindingDecl> from(const Decl &parent);
  Expr binding(void) const;
  ValueDecl decomposed_declaration(void) const;
  VarDecl holding_variable(void) const;
};

using OMPDeclarativeDirectiveValueDeclRange = DerivedEntityRange<DeclIterator, OMPDeclarativeDirectiveValueDecl>;
using OMPDeclarativeDirectiveValueDeclContainingTokenRange = DerivedEntityRange<TokenContextIterator, OMPDeclarativeDirectiveValueDecl>;
using OMPDeclarativeDirectiveValueDeclContainingDeclRange = DerivedEntityRange<ParentDeclIteratorImpl<Decl>, OMPDeclarativeDirectiveValueDecl>;

class OMPDeclarativeDirectiveValueDecl : public ValueDecl {
 private:
  friend class FragmentImpl;
  friend class ValueDecl;
  friend class NamedDecl;
  friend class Decl;
 public:
  inline static OMPDeclarativeDirectiveValueDeclRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static OMPDeclarativeDirectiveValueDeclContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static OMPDeclarativeDirectiveValueDeclContainingDeclRange containing(const Decl &decl);
  static OMPDeclarativeDirectiveValueDeclContainingDeclRange containing(const Stmt &stmt);

  static std::optional<OMPDeclarativeDirectiveValueDecl> from(const TokenContext &c);
  static std::optional<OMPDeclarativeDirectiveValueDecl> from(const ValueDecl &parent);
  static std::optional<OMPDeclarativeDirectiveValueDecl> from(const NamedDecl &parent);
  static std::optional<OMPDeclarativeDirectiveValueDecl> from(const Decl &parent);
};

using OMPDeclareMapperDeclRange = DerivedEntityRange<DeclIterator, OMPDeclareMapperDecl>;
using OMPDeclareMapperDeclContainingTokenRange = DerivedEntityRange<TokenContextIterator, OMPDeclareMapperDecl>;
using OMPDeclareMapperDeclContainingDeclRange = DerivedEntityRange<ParentDeclIteratorImpl<Decl>, OMPDeclareMapperDecl>;

class OMPDeclareMapperDecl : public OMPDeclarativeDirectiveValueDecl {
 private:
  friend class FragmentImpl;
  friend class OMPDeclarativeDirectiveValueDecl;
  friend class ValueDecl;
  friend class NamedDecl;
  friend class Decl;
 public:
  inline static OMPDeclareMapperDeclRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static OMPDeclareMapperDeclContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static OMPDeclareMapperDeclContainingDeclRange containing(const Decl &decl);
  static OMPDeclareMapperDeclContainingDeclRange containing(const Stmt &stmt);

  static std::optional<OMPDeclareMapperDecl> from(const TokenContext &c);
  static std::optional<OMPDeclareMapperDecl> from(const OMPDeclarativeDirectiveValueDecl &parent);
  static std::optional<OMPDeclareMapperDecl> from(const ValueDecl &parent);
  static std::optional<OMPDeclareMapperDecl> from(const NamedDecl &parent);
  static std::optional<OMPDeclareMapperDecl> from(const Decl &parent);
  Expr mapper_variable_reference(void) const;
  OMPDeclareMapperDecl prev_declaration_in_scope(void) const;
  std::vector<Decl> declarations_in_context(void) const;
};

using UsingShadowDeclRange = DerivedEntityRange<DeclIterator, UsingShadowDecl>;
using UsingShadowDeclContainingTokenRange = DerivedEntityRange<TokenContextIterator, UsingShadowDecl>;
using UsingShadowDeclContainingDeclRange = DerivedEntityRange<ParentDeclIteratorImpl<Decl>, UsingShadowDecl>;

class UsingShadowDecl : public NamedDecl {
 private:
  friend class FragmentImpl;
  friend class NamedDecl;
  friend class Decl;
 public:
  inline static UsingShadowDeclRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static UsingShadowDeclContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static UsingShadowDeclContainingDeclRange containing(const Decl &decl);
  static UsingShadowDeclContainingDeclRange containing(const Stmt &stmt);

  static std::optional<UsingShadowDecl> from(const TokenContext &c);
  static std::optional<UsingShadowDecl> from(const NamedDecl &parent);
  static std::optional<UsingShadowDecl> from(const Decl &parent);
  BaseUsingDecl introducer(void) const;
  UsingShadowDecl next_using_shadow_declaration(void) const;
  NamedDecl target_declaration(void) const;
};

using ConstructorUsingShadowDeclRange = DerivedEntityRange<DeclIterator, ConstructorUsingShadowDecl>;
using ConstructorUsingShadowDeclContainingTokenRange = DerivedEntityRange<TokenContextIterator, ConstructorUsingShadowDecl>;
using ConstructorUsingShadowDeclContainingDeclRange = DerivedEntityRange<ParentDeclIteratorImpl<Decl>, ConstructorUsingShadowDecl>;

class ConstructorUsingShadowDecl : public UsingShadowDecl {
 private:
  friend class FragmentImpl;
  friend class UsingShadowDecl;
  friend class NamedDecl;
  friend class Decl;
 public:
  inline static ConstructorUsingShadowDeclRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static ConstructorUsingShadowDeclContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static ConstructorUsingShadowDeclContainingDeclRange containing(const Decl &decl);
  static ConstructorUsingShadowDeclContainingDeclRange containing(const Stmt &stmt);

  static std::optional<ConstructorUsingShadowDecl> from(const TokenContext &c);
  static std::optional<ConstructorUsingShadowDecl> from(const UsingShadowDecl &parent);
  static std::optional<ConstructorUsingShadowDecl> from(const NamedDecl &parent);
  static std::optional<ConstructorUsingShadowDecl> from(const Decl &parent);
  bool constructs_virtual_base(void) const;
  CXXRecordDecl constructed_base_class(void) const;
  std::optional<ConstructorUsingShadowDecl> constructed_base_class_shadow_declaration(void) const;
  CXXRecordDecl nominated_base_class(void) const;
  std::optional<ConstructorUsingShadowDecl> nominated_base_class_shadow_declaration(void) const;
  CXXRecordDecl parent(void) const;
};

using UsingPackDeclRange = DerivedEntityRange<DeclIterator, UsingPackDecl>;
using UsingPackDeclContainingTokenRange = DerivedEntityRange<TokenContextIterator, UsingPackDecl>;
using UsingPackDeclContainingDeclRange = DerivedEntityRange<ParentDeclIteratorImpl<Decl>, UsingPackDecl>;

class UsingPackDecl : public NamedDecl {
 private:
  friend class FragmentImpl;
  friend class NamedDecl;
  friend class Decl;
 public:
  inline static UsingPackDeclRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static UsingPackDeclContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static UsingPackDeclContainingDeclRange containing(const Decl &decl);
  static UsingPackDeclContainingDeclRange containing(const Stmt &stmt);

  static std::optional<UsingPackDecl> from(const TokenContext &c);
  static std::optional<UsingPackDecl> from(const NamedDecl &parent);
  static std::optional<UsingPackDecl> from(const Decl &parent);
  std::vector<NamedDecl> expansions(void) const;
  NamedDecl instantiated_from_using_declaration(void) const;
};

using UsingDirectiveDeclRange = DerivedEntityRange<DeclIterator, UsingDirectiveDecl>;
using UsingDirectiveDeclContainingTokenRange = DerivedEntityRange<TokenContextIterator, UsingDirectiveDecl>;
using UsingDirectiveDeclContainingDeclRange = DerivedEntityRange<ParentDeclIteratorImpl<Decl>, UsingDirectiveDecl>;

class UsingDirectiveDecl : public NamedDecl {
 private:
  friend class FragmentImpl;
  friend class NamedDecl;
  friend class Decl;
 public:
  inline static UsingDirectiveDeclRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static UsingDirectiveDeclContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static UsingDirectiveDeclContainingDeclRange containing(const Decl &decl);
  static UsingDirectiveDeclContainingDeclRange containing(const Stmt &stmt);

  static std::optional<UsingDirectiveDecl> from(const TokenContext &c);
  static std::optional<UsingDirectiveDecl> from(const NamedDecl &parent);
  static std::optional<UsingDirectiveDecl> from(const Decl &parent);
  Token identifier_token(void) const;
  Token namespace_key_token(void) const;
  NamedDecl nominated_namespace_as_written(void) const;
  Token using_token(void) const;
};

using UnresolvedUsingIfExistsDeclRange = DerivedEntityRange<DeclIterator, UnresolvedUsingIfExistsDecl>;
using UnresolvedUsingIfExistsDeclContainingTokenRange = DerivedEntityRange<TokenContextIterator, UnresolvedUsingIfExistsDecl>;
using UnresolvedUsingIfExistsDeclContainingDeclRange = DerivedEntityRange<ParentDeclIteratorImpl<Decl>, UnresolvedUsingIfExistsDecl>;

class UnresolvedUsingIfExistsDecl : public NamedDecl {
 private:
  friend class FragmentImpl;
  friend class NamedDecl;
  friend class Decl;
 public:
  inline static UnresolvedUsingIfExistsDeclRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static UnresolvedUsingIfExistsDeclContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static UnresolvedUsingIfExistsDeclContainingDeclRange containing(const Decl &decl);
  static UnresolvedUsingIfExistsDeclContainingDeclRange containing(const Stmt &stmt);

  static std::optional<UnresolvedUsingIfExistsDecl> from(const TokenContext &c);
  static std::optional<UnresolvedUsingIfExistsDecl> from(const NamedDecl &parent);
  static std::optional<UnresolvedUsingIfExistsDecl> from(const Decl &parent);
};

using TypeDeclRange = DerivedEntityRange<DeclIterator, TypeDecl>;
using TypeDeclContainingTokenRange = DerivedEntityRange<TokenContextIterator, TypeDecl>;
using TypeDeclContainingDeclRange = DerivedEntityRange<ParentDeclIteratorImpl<Decl>, TypeDecl>;

class TypeDecl : public NamedDecl {
 private:
  friend class FragmentImpl;
  friend class NamedDecl;
  friend class Decl;
 public:
  inline static TypeDeclRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static TypeDeclContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static TypeDeclContainingDeclRange containing(const Decl &decl);
  static TypeDeclContainingDeclRange containing(const Stmt &stmt);

  static std::optional<TypeDecl> from(const TokenContext &c);
  static std::optional<TypeDecl> from(const NamedDecl &parent);
  static std::optional<TypeDecl> from(const Decl &parent);
};

using TemplateTypeParmDeclRange = DerivedEntityRange<DeclIterator, TemplateTypeParmDecl>;
using TemplateTypeParmDeclContainingTokenRange = DerivedEntityRange<TokenContextIterator, TemplateTypeParmDecl>;
using TemplateTypeParmDeclContainingDeclRange = DerivedEntityRange<ParentDeclIteratorImpl<Decl>, TemplateTypeParmDecl>;

class TemplateTypeParmDecl : public TypeDecl {
 private:
  friend class FragmentImpl;
  friend class TypeDecl;
  friend class NamedDecl;
  friend class Decl;
 public:
  inline static TemplateTypeParmDeclRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static TemplateTypeParmDeclContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static TemplateTypeParmDeclContainingDeclRange containing(const Decl &decl);
  static TemplateTypeParmDeclContainingDeclRange containing(const Stmt &stmt);

  static std::optional<TemplateTypeParmDecl> from(const TokenContext &c);
  static std::optional<TemplateTypeParmDecl> from(const TypeDecl &parent);
  static std::optional<TemplateTypeParmDecl> from(const NamedDecl &parent);
  static std::optional<TemplateTypeParmDecl> from(const Decl &parent);
  bool default_argument_was_inherited(void) const;
  Token default_argument_token(void) const;
  bool has_default_argument(void) const;
  bool has_type_constraint(void) const;
  bool is_expanded_parameter_pack(void) const;
  bool is_pack_expansion(void) const;
  bool was_declared_with_typename(void) const;
};

using TagDeclRange = DerivedEntityRange<DeclIterator, TagDecl>;
using TagDeclContainingTokenRange = DerivedEntityRange<TokenContextIterator, TagDecl>;
using TagDeclContainingDeclRange = DerivedEntityRange<ParentDeclIteratorImpl<Decl>, TagDecl>;

class TagDecl : public TypeDecl {
 private:
  friend class FragmentImpl;
  friend class TypeDecl;
  friend class NamedDecl;
  friend class Decl;
 public:
  inline static TagDeclRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static TagDeclContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static TagDeclContainingDeclRange containing(const Decl &decl);
  static TagDeclContainingDeclRange containing(const Stmt &stmt);

  static std::optional<TagDecl> from(const TokenContext &c);
  static std::optional<TagDecl> from(const TypeDecl &parent);
  static std::optional<TagDecl> from(const NamedDecl &parent);
  static std::optional<TagDecl> from(const Decl &parent);
  TokenRange brace_range(void) const;
  std::optional<TagDecl> definition(void) const;
  Token inner_token_start(void) const;
  Token outer_token_start(void) const;
  TagTypeKind tag_kind(void) const;
  std::optional<TypedefNameDecl> typedef_name_for_anonymous_declaration(void) const;
  bool has_name_for_linkage(void) const;
  bool is_being_defined(void) const;
  bool is_class(void) const;
  bool is_complete_definition(void) const;
  bool is_complete_definition_required(void) const;
  bool is_dependent_type(void) const;
  bool is_embedded_in_declarator(void) const;
  bool is_enum(void) const;
  bool is_free_standing(void) const;
  bool is_interface(void) const;
  bool is_struct(void) const;
  bool is_this_declaration_a_definition(void) const;
  bool is_union(void) const;
  bool may_have_out_of_date_definition(void) const;
  std::vector<TemplateParameterList> template_parameter_lists(void) const;
  std::vector<Decl> declarations_in_context(void) const;
};

using RecordDeclRange = DerivedEntityRange<DeclIterator, RecordDecl>;
using RecordDeclContainingTokenRange = DerivedEntityRange<TokenContextIterator, RecordDecl>;
using RecordDeclContainingDeclRange = DerivedEntityRange<ParentDeclIteratorImpl<Decl>, RecordDecl>;

class RecordDecl : public TagDecl {
 private:
  friend class FragmentImpl;
  friend class TagDecl;
  friend class TypeDecl;
  friend class NamedDecl;
  friend class Decl;
 public:
  inline static RecordDeclRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static RecordDeclContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static RecordDeclContainingDeclRange containing(const Decl &decl);
  static RecordDeclContainingDeclRange containing(const Stmt &stmt);

  static std::optional<RecordDecl> from(const TokenContext &c);
  static std::optional<RecordDecl> from(const TagDecl &parent);
  static std::optional<RecordDecl> from(const TypeDecl &parent);
  static std::optional<RecordDecl> from(const NamedDecl &parent);
  static std::optional<RecordDecl> from(const Decl &parent);
  bool can_pass_in_registers(void) const;
  std::vector<FieldDecl> fields(void) const;
  std::optional<FieldDecl> find_first_named_data_member(void) const;
  RecordDeclArgPassingKind argument_passing_restrictions(void) const;
  bool has_flexible_array_member(void) const;
  bool has_loaded_fields_from_external_storage(void) const;
  bool has_non_trivial_to_primitive_copy_c_union(void) const;
  bool has_non_trivial_to_primitive_default_initialize_c_union(void) const;
  bool has_non_trivial_to_primitive_destruct_c_union(void) const;
  bool has_object_member(void) const;
  bool has_volatile_member(void) const;
  bool is_anonymous_struct_or_union(void) const;
  bool is_captured_record(void) const;
  bool is_injected_class_name(void) const;
  bool is_lambda(void) const;
  bool is_ms_struct(void) const;
  bool is_non_trivial_to_primitive_copy(void) const;
  bool is_non_trivial_to_primitive_default_initialize(void) const;
  bool is_non_trivial_to_primitive_destroy(void) const;
  bool is_or_contains_union(void) const;
  bool is_parameter_destroyed_in_callee(void) const;
  bool may_insert_extra_padding(void) const;
};

using CXXRecordDeclRange = DerivedEntityRange<DeclIterator, CXXRecordDecl>;
using CXXRecordDeclContainingTokenRange = DerivedEntityRange<TokenContextIterator, CXXRecordDecl>;
using CXXRecordDeclContainingDeclRange = DerivedEntityRange<ParentDeclIteratorImpl<Decl>, CXXRecordDecl>;

class CXXRecordDecl : public RecordDecl {
 private:
  friend class FragmentImpl;
  friend class RecordDecl;
  friend class TagDecl;
  friend class TypeDecl;
  friend class NamedDecl;
  friend class Decl;
 public:
  inline static CXXRecordDeclRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static CXXRecordDeclContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static CXXRecordDeclContainingDeclRange containing(const Decl &decl);
  static CXXRecordDeclContainingDeclRange containing(const Stmt &stmt);

  static std::optional<CXXRecordDecl> from(const TokenContext &c);
  static std::optional<CXXRecordDecl> from(const RecordDecl &parent);
  static std::optional<CXXRecordDecl> from(const TagDecl &parent);
  static std::optional<CXXRecordDecl> from(const TypeDecl &parent);
  static std::optional<CXXRecordDecl> from(const NamedDecl &parent);
  static std::optional<CXXRecordDecl> from(const Decl &parent);
  bool allow_const_default_initializer(void) const;
  std::vector<CXXBaseSpecifier> bases(void) const;
  MSInheritanceModel calculate_inheritance_model(void) const;
  std::vector<CXXConstructorDecl> constructors(void) const;
  bool defaulted_copy_constructor_is_deleted(void) const;
  bool defaulted_default_constructor_is_constexpr(void) const;
  bool defaulted_destructor_is_constexpr(void) const;
  bool defaulted_destructor_is_deleted(void) const;
  bool defaulted_move_constructor_is_deleted(void) const;
  std::vector<FriendDecl> friends(void) const;
  std::optional<CXXDestructorDecl> destructor(void) const;
  std::optional<TemplateParameterList> generic_lambda_template_parameter_list(void) const;
  std::optional<CXXRecordDecl> instantiated_from_member_class(void) const;
  std::optional<CXXMethodDecl> lambda_call_operator(void) const;
  LambdaCaptureDefault lambda_capture_default(void) const;
  Decl lambda_context_declaration(void) const;
  std::vector<NamedDecl> lambda_explicit_template_parameters(void) const;
  MSInheritanceModel ms_inheritance_model(void) const;
  MSVtorDispMode ms_vtor_disp_mode(void) const;
  CXXRecordDecl most_recent_non_injected_declaration(void) const;
  std::optional<CXXRecordDecl> template_instantiation_pattern(void) const;
  TemplateSpecializationKind template_specialization_kind(void) const;
  bool has_any_dependent_bases(void) const;
  bool has_constexpr_default_constructor(void) const;
  bool has_constexpr_destructor(void) const;
  bool has_constexpr_non_copy_move_constructor(void) const;
  bool has_copy_assignment_with_const_parameter(void) const;
  bool has_copy_constructor_with_const_parameter(void) const;
  bool has_default_constructor(void) const;
  bool has_definition(void) const;
  bool has_direct_fields(void) const;
  bool has_friends(void) const;
  bool has_in_class_initializer(void) const;
  bool has_inherited_assignment(void) const;
  bool has_inherited_constructor(void) const;
  bool has_irrelevant_destructor(void) const;
  bool has_known_lambda_internal_linkage(void) const;
  bool has_move_assignment(void) const;
  bool has_move_constructor(void) const;
  bool has_mutable_fields(void) const;
  bool has_non_literal_type_fields_or_bases(void) const;
  bool has_non_trivial_copy_assignment(void) const;
  bool has_non_trivial_copy_constructor(void) const;
  bool has_non_trivial_copy_constructor_for_call(void) const;
  bool has_non_trivial_default_constructor(void) const;
  bool has_non_trivial_destructor(void) const;
  bool has_non_trivial_destructor_for_call(void) const;
  bool has_non_trivial_move_assignment(void) const;
  bool has_non_trivial_move_constructor(void) const;
  bool has_non_trivial_move_constructor_for_call(void) const;
  bool has_private_fields(void) const;
  bool has_protected_fields(void) const;
  bool has_simple_copy_assignment(void) const;
  bool has_simple_copy_constructor(void) const;
  bool has_simple_destructor(void) const;
  bool has_simple_move_assignment(void) const;
  bool has_simple_move_constructor(void) const;
  bool has_trivial_copy_assignment(void) const;
  bool has_trivial_copy_constructor(void) const;
  bool has_trivial_copy_constructor_for_call(void) const;
  bool has_trivial_default_constructor(void) const;
  bool has_trivial_destructor(void) const;
  bool has_trivial_destructor_for_call(void) const;
  bool has_trivial_move_assignment(void) const;
  bool has_trivial_move_constructor(void) const;
  bool has_trivial_move_constructor_for_call(void) const;
  bool has_uninitialized_reference_member(void) const;
  bool has_user_declared_constructor(void) const;
  bool has_user_declared_copy_assignment(void) const;
  bool has_user_declared_copy_constructor(void) const;
  bool has_user_declared_destructor(void) const;
  bool has_user_declared_move_assignment(void) const;
  bool has_user_declared_move_constructor(void) const;
  bool has_user_declared_move_operation(void) const;
  bool has_user_provided_default_constructor(void) const;
  bool has_variant_members(void) const;
  bool implicit_copy_assignment_has_const_parameter(void) const;
  bool implicit_copy_constructor_has_const_parameter(void) const;
  bool is_abstract(void) const;
  bool is_aggregate(void) const;
  bool is_any_destructor_no_return(void) const;
  bool is_c_like(void) const;
  bool is_cxx11_standard_layout(void) const;
  bool is_dependent_lambda(void) const;
  bool is_dynamic_class(void) const;
  bool is_effectively_final(void) const;
  bool is_empty(void) const;
  bool is_generic_lambda(void) const;
  bool is_interface_like(void) const;
  bool is_literal(void) const;
  std::optional<FunctionDecl> is_local_class(void) const;
  bool is_pod(void) const;
  bool is_parsing_base_specifiers(void) const;
  bool is_polymorphic(void) const;
  bool is_standard_layout(void) const;
  bool is_structural(void) const;
  bool is_trivial(void) const;
  bool is_trivially_copyable(void) const;
  bool lambda_is_default_constructible_and_assignable(void) const;
  bool may_be_abstract(void) const;
  bool may_be_dynamic_class(void) const;
  bool may_be_non_dynamic_class(void) const;
  std::vector<CXXMethodDecl> methods(void) const;
  bool needs_implicit_copy_assignment(void) const;
  bool needs_implicit_copy_constructor(void) const;
  bool needs_implicit_default_constructor(void) const;
  bool needs_implicit_destructor(void) const;
  bool needs_implicit_move_assignment(void) const;
  bool needs_implicit_move_constructor(void) const;
  bool needs_overload_resolution_for_copy_assignment(void) const;
  bool needs_overload_resolution_for_copy_constructor(void) const;
  bool needs_overload_resolution_for_destructor(void) const;
  bool needs_overload_resolution_for_move_assignment(void) const;
  bool needs_overload_resolution_for_move_constructor(void) const;
  bool null_field_offset_is_zero(void) const;
  std::vector<CXXBaseSpecifier> virtual_bases(void) const;
};

using ClassTemplateSpecializationDeclRange = DerivedEntityRange<DeclIterator, ClassTemplateSpecializationDecl>;
using ClassTemplateSpecializationDeclContainingTokenRange = DerivedEntityRange<TokenContextIterator, ClassTemplateSpecializationDecl>;
using ClassTemplateSpecializationDeclContainingDeclRange = DerivedEntityRange<ParentDeclIteratorImpl<Decl>, ClassTemplateSpecializationDecl>;

class ClassTemplateSpecializationDecl : public CXXRecordDecl {
 private:
  friend class FragmentImpl;
  friend class CXXRecordDecl;
  friend class RecordDecl;
  friend class TagDecl;
  friend class TypeDecl;
  friend class NamedDecl;
  friend class Decl;
 public:
  inline static ClassTemplateSpecializationDeclRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static ClassTemplateSpecializationDeclContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static ClassTemplateSpecializationDeclContainingDeclRange containing(const Decl &decl);
  static ClassTemplateSpecializationDeclContainingDeclRange containing(const Stmt &stmt);

  static std::optional<ClassTemplateSpecializationDecl> from(const TokenContext &c);
  static std::optional<ClassTemplateSpecializationDecl> from(const CXXRecordDecl &parent);
  static std::optional<ClassTemplateSpecializationDecl> from(const RecordDecl &parent);
  static std::optional<ClassTemplateSpecializationDecl> from(const TagDecl &parent);
  static std::optional<ClassTemplateSpecializationDecl> from(const TypeDecl &parent);
  static std::optional<ClassTemplateSpecializationDecl> from(const NamedDecl &parent);
  static std::optional<ClassTemplateSpecializationDecl> from(const Decl &parent);
  Token extern_token(void) const;
  Token point_of_instantiation(void) const;
  TemplateSpecializationKind specialization_kind(void) const;
  std::vector<TemplateArgument> template_arguments(void) const;
  std::vector<TemplateArgument> template_instantiation_arguments(void) const;
  Token template_keyword_token(void) const;
  bool is_class_scope_explicit_specialization(void) const;
  bool is_explicit_instantiation_or_specialization(void) const;
  bool is_explicit_specialization(void) const;
};

using ClassTemplatePartialSpecializationDeclRange = DerivedEntityRange<DeclIterator, ClassTemplatePartialSpecializationDecl>;
using ClassTemplatePartialSpecializationDeclContainingTokenRange = DerivedEntityRange<TokenContextIterator, ClassTemplatePartialSpecializationDecl>;
using ClassTemplatePartialSpecializationDeclContainingDeclRange = DerivedEntityRange<ParentDeclIteratorImpl<Decl>, ClassTemplatePartialSpecializationDecl>;

class ClassTemplatePartialSpecializationDecl : public ClassTemplateSpecializationDecl {
 private:
  friend class FragmentImpl;
  friend class ClassTemplateSpecializationDecl;
  friend class CXXRecordDecl;
  friend class RecordDecl;
  friend class TagDecl;
  friend class TypeDecl;
  friend class NamedDecl;
  friend class Decl;
 public:
  inline static ClassTemplatePartialSpecializationDeclRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static ClassTemplatePartialSpecializationDeclContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static ClassTemplatePartialSpecializationDeclContainingDeclRange containing(const Decl &decl);
  static ClassTemplatePartialSpecializationDeclContainingDeclRange containing(const Stmt &stmt);

  static std::optional<ClassTemplatePartialSpecializationDecl> from(const TokenContext &c);
  static std::optional<ClassTemplatePartialSpecializationDecl> from(const ClassTemplateSpecializationDecl &parent);
  static std::optional<ClassTemplatePartialSpecializationDecl> from(const CXXRecordDecl &parent);
  static std::optional<ClassTemplatePartialSpecializationDecl> from(const RecordDecl &parent);
  static std::optional<ClassTemplatePartialSpecializationDecl> from(const TagDecl &parent);
  static std::optional<ClassTemplatePartialSpecializationDecl> from(const TypeDecl &parent);
  static std::optional<ClassTemplatePartialSpecializationDecl> from(const NamedDecl &parent);
  static std::optional<ClassTemplatePartialSpecializationDecl> from(const Decl &parent);
};

using EnumDeclRange = DerivedEntityRange<DeclIterator, EnumDecl>;
using EnumDeclContainingTokenRange = DerivedEntityRange<TokenContextIterator, EnumDecl>;
using EnumDeclContainingDeclRange = DerivedEntityRange<ParentDeclIteratorImpl<Decl>, EnumDecl>;

class EnumDecl : public TagDecl {
 private:
  friend class FragmentImpl;
  friend class TagDecl;
  friend class TypeDecl;
  friend class NamedDecl;
  friend class Decl;
 public:
  inline static EnumDeclRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static EnumDeclContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static EnumDeclContainingDeclRange containing(const Decl &decl);
  static EnumDeclContainingDeclRange containing(const Stmt &stmt);

  static std::optional<EnumDecl> from(const TokenContext &c);
  static std::optional<EnumDecl> from(const TagDecl &parent);
  static std::optional<EnumDecl> from(const TypeDecl &parent);
  static std::optional<EnumDecl> from(const NamedDecl &parent);
  static std::optional<EnumDecl> from(const Decl &parent);
  std::vector<EnumConstantDecl> enumerators(void) const;
  std::optional<EnumDecl> instantiated_from_member_enum(void) const;
  TokenRange integer_type_range(void) const;
  std::optional<EnumDecl> template_instantiation_pattern(void) const;
  TemplateSpecializationKind template_specialization_kind(void) const;
  bool is_closed(void) const;
  bool is_closed_flag(void) const;
  bool is_closed_non_flag(void) const;
  bool is_complete(void) const;
  bool is_fixed(void) const;
  bool is_scoped(void) const;
  bool is_scoped_using_class_tag(void) const;
};

using UnresolvedUsingTypenameDeclRange = DerivedEntityRange<DeclIterator, UnresolvedUsingTypenameDecl>;
using UnresolvedUsingTypenameDeclContainingTokenRange = DerivedEntityRange<TokenContextIterator, UnresolvedUsingTypenameDecl>;
using UnresolvedUsingTypenameDeclContainingDeclRange = DerivedEntityRange<ParentDeclIteratorImpl<Decl>, UnresolvedUsingTypenameDecl>;

class UnresolvedUsingTypenameDecl : public TypeDecl {
 private:
  friend class FragmentImpl;
  friend class TypeDecl;
  friend class NamedDecl;
  friend class Decl;
 public:
  inline static UnresolvedUsingTypenameDeclRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static UnresolvedUsingTypenameDeclContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static UnresolvedUsingTypenameDeclContainingDeclRange containing(const Decl &decl);
  static UnresolvedUsingTypenameDeclContainingDeclRange containing(const Stmt &stmt);

  static std::optional<UnresolvedUsingTypenameDecl> from(const TokenContext &c);
  static std::optional<UnresolvedUsingTypenameDecl> from(const TypeDecl &parent);
  static std::optional<UnresolvedUsingTypenameDecl> from(const NamedDecl &parent);
  static std::optional<UnresolvedUsingTypenameDecl> from(const Decl &parent);
  Token ellipsis_token(void) const;
  Token typename_token(void) const;
  Token using_token(void) const;
  bool is_pack_expansion(void) const;
};

using TypedefNameDeclRange = DerivedEntityRange<DeclIterator, TypedefNameDecl>;
using TypedefNameDeclContainingTokenRange = DerivedEntityRange<TokenContextIterator, TypedefNameDecl>;
using TypedefNameDeclContainingDeclRange = DerivedEntityRange<ParentDeclIteratorImpl<Decl>, TypedefNameDecl>;

class TypedefNameDecl : public TypeDecl {
 private:
  friend class FragmentImpl;
  friend class TypeDecl;
  friend class NamedDecl;
  friend class Decl;
 public:
  inline static TypedefNameDeclRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static TypedefNameDeclContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static TypedefNameDeclContainingDeclRange containing(const Decl &decl);
  static TypedefNameDeclContainingDeclRange containing(const Stmt &stmt);

  static std::optional<TypedefNameDecl> from(const TokenContext &c);
  static std::optional<TypedefNameDecl> from(const TypeDecl &parent);
  static std::optional<TypedefNameDecl> from(const NamedDecl &parent);
  static std::optional<TypedefNameDecl> from(const Decl &parent);
  std::optional<TagDecl> anonymous_declaration_with_typedef_name(void) const;
  bool is_moded(void) const;
  bool is_transparent_tag(void) const;
};

using TypedefDeclRange = DerivedEntityRange<DeclIterator, TypedefDecl>;
using TypedefDeclContainingTokenRange = DerivedEntityRange<TokenContextIterator, TypedefDecl>;
using TypedefDeclContainingDeclRange = DerivedEntityRange<ParentDeclIteratorImpl<Decl>, TypedefDecl>;

class TypedefDecl : public TypedefNameDecl {
 private:
  friend class FragmentImpl;
  friend class TypedefNameDecl;
  friend class TypeDecl;
  friend class NamedDecl;
  friend class Decl;
 public:
  inline static TypedefDeclRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static TypedefDeclContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static TypedefDeclContainingDeclRange containing(const Decl &decl);
  static TypedefDeclContainingDeclRange containing(const Stmt &stmt);

  static std::optional<TypedefDecl> from(const TokenContext &c);
  static std::optional<TypedefDecl> from(const TypedefNameDecl &parent);
  static std::optional<TypedefDecl> from(const TypeDecl &parent);
  static std::optional<TypedefDecl> from(const NamedDecl &parent);
  static std::optional<TypedefDecl> from(const Decl &parent);
};

using TypeAliasDeclRange = DerivedEntityRange<DeclIterator, TypeAliasDecl>;
using TypeAliasDeclContainingTokenRange = DerivedEntityRange<TokenContextIterator, TypeAliasDecl>;
using TypeAliasDeclContainingDeclRange = DerivedEntityRange<ParentDeclIteratorImpl<Decl>, TypeAliasDecl>;

class TypeAliasDecl : public TypedefNameDecl {
 private:
  friend class FragmentImpl;
  friend class TypedefNameDecl;
  friend class TypeDecl;
  friend class NamedDecl;
  friend class Decl;
 public:
  inline static TypeAliasDeclRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static TypeAliasDeclContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static TypeAliasDeclContainingDeclRange containing(const Decl &decl);
  static TypeAliasDeclContainingDeclRange containing(const Stmt &stmt);

  static std::optional<TypeAliasDecl> from(const TokenContext &c);
  static std::optional<TypeAliasDecl> from(const TypedefNameDecl &parent);
  static std::optional<TypeAliasDecl> from(const TypeDecl &parent);
  static std::optional<TypeAliasDecl> from(const NamedDecl &parent);
  static std::optional<TypeAliasDecl> from(const Decl &parent);
  std::optional<TypeAliasTemplateDecl> described_alias_template(void) const;
};

using ObjCTypeParamDeclRange = DerivedEntityRange<DeclIterator, ObjCTypeParamDecl>;
using ObjCTypeParamDeclContainingTokenRange = DerivedEntityRange<TokenContextIterator, ObjCTypeParamDecl>;
using ObjCTypeParamDeclContainingDeclRange = DerivedEntityRange<ParentDeclIteratorImpl<Decl>, ObjCTypeParamDecl>;

class ObjCTypeParamDecl : public TypedefNameDecl {
 private:
  friend class FragmentImpl;
  friend class TypedefNameDecl;
  friend class TypeDecl;
  friend class NamedDecl;
  friend class Decl;
 public:
  inline static ObjCTypeParamDeclRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static ObjCTypeParamDeclContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static ObjCTypeParamDeclContainingDeclRange containing(const Decl &decl);
  static ObjCTypeParamDeclContainingDeclRange containing(const Stmt &stmt);

  static std::optional<ObjCTypeParamDecl> from(const TokenContext &c);
  static std::optional<ObjCTypeParamDecl> from(const TypedefNameDecl &parent);
  static std::optional<ObjCTypeParamDecl> from(const TypeDecl &parent);
  static std::optional<ObjCTypeParamDecl> from(const NamedDecl &parent);
  static std::optional<ObjCTypeParamDecl> from(const Decl &parent);
  Token colon_token(void) const;
  ObjCTypeParamVariance variance(void) const;
  Token variance_token(void) const;
  bool has_explicit_bound(void) const;
};

using TemplateDeclRange = DerivedEntityRange<DeclIterator, TemplateDecl>;
using TemplateDeclContainingTokenRange = DerivedEntityRange<TokenContextIterator, TemplateDecl>;
using TemplateDeclContainingDeclRange = DerivedEntityRange<ParentDeclIteratorImpl<Decl>, TemplateDecl>;

class TemplateDecl : public NamedDecl {
 private:
  friend class FragmentImpl;
  friend class NamedDecl;
  friend class Decl;
 public:
  inline static TemplateDeclRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static TemplateDeclContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static TemplateDeclContainingDeclRange containing(const Decl &decl);
  static TemplateDeclContainingDeclRange containing(const Stmt &stmt);

  static std::optional<TemplateDecl> from(const TokenContext &c);
  static std::optional<TemplateDecl> from(const NamedDecl &parent);
  static std::optional<TemplateDecl> from(const Decl &parent);
};

using RedeclarableTemplateDeclRange = DerivedEntityRange<DeclIterator, RedeclarableTemplateDecl>;
using RedeclarableTemplateDeclContainingTokenRange = DerivedEntityRange<TokenContextIterator, RedeclarableTemplateDecl>;
using RedeclarableTemplateDeclContainingDeclRange = DerivedEntityRange<ParentDeclIteratorImpl<Decl>, RedeclarableTemplateDecl>;

class RedeclarableTemplateDecl : public TemplateDecl {
 private:
  friend class FragmentImpl;
  friend class TemplateDecl;
  friend class NamedDecl;
  friend class Decl;
 public:
  inline static RedeclarableTemplateDeclRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static RedeclarableTemplateDeclContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static RedeclarableTemplateDeclContainingDeclRange containing(const Decl &decl);
  static RedeclarableTemplateDeclContainingDeclRange containing(const Stmt &stmt);

  static std::optional<RedeclarableTemplateDecl> from(const TokenContext &c);
  static std::optional<RedeclarableTemplateDecl> from(const TemplateDecl &parent);
  static std::optional<RedeclarableTemplateDecl> from(const NamedDecl &parent);
  static std::optional<RedeclarableTemplateDecl> from(const Decl &parent);
};

using FunctionTemplateDeclRange = DerivedEntityRange<DeclIterator, FunctionTemplateDecl>;
using FunctionTemplateDeclContainingTokenRange = DerivedEntityRange<TokenContextIterator, FunctionTemplateDecl>;
using FunctionTemplateDeclContainingDeclRange = DerivedEntityRange<ParentDeclIteratorImpl<Decl>, FunctionTemplateDecl>;

class FunctionTemplateDecl : public RedeclarableTemplateDecl {
 private:
  friend class FragmentImpl;
  friend class RedeclarableTemplateDecl;
  friend class TemplateDecl;
  friend class NamedDecl;
  friend class Decl;
 public:
  inline static FunctionTemplateDeclRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static FunctionTemplateDeclContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static FunctionTemplateDeclContainingDeclRange containing(const Decl &decl);
  static FunctionTemplateDeclContainingDeclRange containing(const Stmt &stmt);

  static std::optional<FunctionTemplateDecl> from(const TokenContext &c);
  static std::optional<FunctionTemplateDecl> from(const RedeclarableTemplateDecl &parent);
  static std::optional<FunctionTemplateDecl> from(const TemplateDecl &parent);
  static std::optional<FunctionTemplateDecl> from(const NamedDecl &parent);
  static std::optional<FunctionTemplateDecl> from(const Decl &parent);
};

using ClassTemplateDeclRange = DerivedEntityRange<DeclIterator, ClassTemplateDecl>;
using ClassTemplateDeclContainingTokenRange = DerivedEntityRange<TokenContextIterator, ClassTemplateDecl>;
using ClassTemplateDeclContainingDeclRange = DerivedEntityRange<ParentDeclIteratorImpl<Decl>, ClassTemplateDecl>;

class ClassTemplateDecl : public RedeclarableTemplateDecl {
 private:
  friend class FragmentImpl;
  friend class RedeclarableTemplateDecl;
  friend class TemplateDecl;
  friend class NamedDecl;
  friend class Decl;
 public:
  inline static ClassTemplateDeclRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static ClassTemplateDeclContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static ClassTemplateDeclContainingDeclRange containing(const Decl &decl);
  static ClassTemplateDeclContainingDeclRange containing(const Stmt &stmt);

  static std::optional<ClassTemplateDecl> from(const TokenContext &c);
  static std::optional<ClassTemplateDecl> from(const RedeclarableTemplateDecl &parent);
  static std::optional<ClassTemplateDecl> from(const TemplateDecl &parent);
  static std::optional<ClassTemplateDecl> from(const NamedDecl &parent);
  static std::optional<ClassTemplateDecl> from(const Decl &parent);
};

using VarTemplateDeclRange = DerivedEntityRange<DeclIterator, VarTemplateDecl>;
using VarTemplateDeclContainingTokenRange = DerivedEntityRange<TokenContextIterator, VarTemplateDecl>;
using VarTemplateDeclContainingDeclRange = DerivedEntityRange<ParentDeclIteratorImpl<Decl>, VarTemplateDecl>;

class VarTemplateDecl : public RedeclarableTemplateDecl {
 private:
  friend class FragmentImpl;
  friend class RedeclarableTemplateDecl;
  friend class TemplateDecl;
  friend class NamedDecl;
  friend class Decl;
 public:
  inline static VarTemplateDeclRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static VarTemplateDeclContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static VarTemplateDeclContainingDeclRange containing(const Decl &decl);
  static VarTemplateDeclContainingDeclRange containing(const Stmt &stmt);

  static std::optional<VarTemplateDecl> from(const TokenContext &c);
  static std::optional<VarTemplateDecl> from(const RedeclarableTemplateDecl &parent);
  static std::optional<VarTemplateDecl> from(const TemplateDecl &parent);
  static std::optional<VarTemplateDecl> from(const NamedDecl &parent);
  static std::optional<VarTemplateDecl> from(const Decl &parent);
};

using TypeAliasTemplateDeclRange = DerivedEntityRange<DeclIterator, TypeAliasTemplateDecl>;
using TypeAliasTemplateDeclContainingTokenRange = DerivedEntityRange<TokenContextIterator, TypeAliasTemplateDecl>;
using TypeAliasTemplateDeclContainingDeclRange = DerivedEntityRange<ParentDeclIteratorImpl<Decl>, TypeAliasTemplateDecl>;

class TypeAliasTemplateDecl : public RedeclarableTemplateDecl {
 private:
  friend class FragmentImpl;
  friend class RedeclarableTemplateDecl;
  friend class TemplateDecl;
  friend class NamedDecl;
  friend class Decl;
 public:
  inline static TypeAliasTemplateDeclRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static TypeAliasTemplateDeclContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static TypeAliasTemplateDeclContainingDeclRange containing(const Decl &decl);
  static TypeAliasTemplateDeclContainingDeclRange containing(const Stmt &stmt);

  static std::optional<TypeAliasTemplateDecl> from(const TokenContext &c);
  static std::optional<TypeAliasTemplateDecl> from(const RedeclarableTemplateDecl &parent);
  static std::optional<TypeAliasTemplateDecl> from(const TemplateDecl &parent);
  static std::optional<TypeAliasTemplateDecl> from(const NamedDecl &parent);
  static std::optional<TypeAliasTemplateDecl> from(const Decl &parent);
};

using ConceptDeclRange = DerivedEntityRange<DeclIterator, ConceptDecl>;
using ConceptDeclContainingTokenRange = DerivedEntityRange<TokenContextIterator, ConceptDecl>;
using ConceptDeclContainingDeclRange = DerivedEntityRange<ParentDeclIteratorImpl<Decl>, ConceptDecl>;

class ConceptDecl : public TemplateDecl {
 private:
  friend class FragmentImpl;
  friend class TemplateDecl;
  friend class NamedDecl;
  friend class Decl;
 public:
  inline static ConceptDeclRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static ConceptDeclContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static ConceptDeclContainingDeclRange containing(const Decl &decl);
  static ConceptDeclContainingDeclRange containing(const Stmt &stmt);

  static std::optional<ConceptDecl> from(const TokenContext &c);
  static std::optional<ConceptDecl> from(const TemplateDecl &parent);
  static std::optional<ConceptDecl> from(const NamedDecl &parent);
  static std::optional<ConceptDecl> from(const Decl &parent);
  Expr constraint_expression(void) const;
  bool is_type_concept(void) const;
};

using BuiltinTemplateDeclRange = DerivedEntityRange<DeclIterator, BuiltinTemplateDecl>;
using BuiltinTemplateDeclContainingTokenRange = DerivedEntityRange<TokenContextIterator, BuiltinTemplateDecl>;
using BuiltinTemplateDeclContainingDeclRange = DerivedEntityRange<ParentDeclIteratorImpl<Decl>, BuiltinTemplateDecl>;

class BuiltinTemplateDecl : public TemplateDecl {
 private:
  friend class FragmentImpl;
  friend class TemplateDecl;
  friend class NamedDecl;
  friend class Decl;
 public:
  inline static BuiltinTemplateDeclRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static BuiltinTemplateDeclContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static BuiltinTemplateDeclContainingDeclRange containing(const Decl &decl);
  static BuiltinTemplateDeclContainingDeclRange containing(const Stmt &stmt);

  static std::optional<BuiltinTemplateDecl> from(const TokenContext &c);
  static std::optional<BuiltinTemplateDecl> from(const TemplateDecl &parent);
  static std::optional<BuiltinTemplateDecl> from(const NamedDecl &parent);
  static std::optional<BuiltinTemplateDecl> from(const Decl &parent);
};

using TemplateTemplateParmDeclRange = DerivedEntityRange<DeclIterator, TemplateTemplateParmDecl>;
using TemplateTemplateParmDeclContainingTokenRange = DerivedEntityRange<TokenContextIterator, TemplateTemplateParmDecl>;
using TemplateTemplateParmDeclContainingDeclRange = DerivedEntityRange<ParentDeclIteratorImpl<Decl>, TemplateTemplateParmDecl>;

class TemplateTemplateParmDecl : public TemplateDecl {
 private:
  friend class FragmentImpl;
  friend class TemplateDecl;
  friend class NamedDecl;
  friend class Decl;
 public:
  inline static TemplateTemplateParmDeclRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static TemplateTemplateParmDeclContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static TemplateTemplateParmDeclContainingDeclRange containing(const Decl &decl);
  static TemplateTemplateParmDeclContainingDeclRange containing(const Stmt &stmt);

  static std::optional<TemplateTemplateParmDecl> from(const TokenContext &c);
  static std::optional<TemplateTemplateParmDecl> from(const TemplateDecl &parent);
  static std::optional<TemplateTemplateParmDecl> from(const NamedDecl &parent);
  static std::optional<TemplateTemplateParmDecl> from(const Decl &parent);
};

using ObjCPropertyDeclRange = DerivedEntityRange<DeclIterator, ObjCPropertyDecl>;
using ObjCPropertyDeclContainingTokenRange = DerivedEntityRange<TokenContextIterator, ObjCPropertyDecl>;
using ObjCPropertyDeclContainingDeclRange = DerivedEntityRange<ParentDeclIteratorImpl<Decl>, ObjCPropertyDecl>;

class ObjCPropertyDecl : public NamedDecl {
 private:
  friend class FragmentImpl;
  friend class NamedDecl;
  friend class Decl;
 public:
  inline static ObjCPropertyDeclRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static ObjCPropertyDeclContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static ObjCPropertyDeclContainingDeclRange containing(const Decl &decl);
  static ObjCPropertyDeclContainingDeclRange containing(const Stmt &stmt);

  static std::optional<ObjCPropertyDecl> from(const TokenContext &c);
  static std::optional<ObjCPropertyDecl> from(const NamedDecl &parent);
  static std::optional<ObjCPropertyDecl> from(const Decl &parent);
  Token at_token(void) const;
  ObjCMethodDecl getter_method_declaration(void) const;
  Token getter_name_token(void) const;
  Token l_paren_token(void) const;
  ObjCPropertyDeclPropertyControl property_implementation(void) const;
  ObjCIvarDecl property_instance_variable_declaration(void) const;
  ObjCPropertyQueryKind query_kind(void) const;
  ObjCPropertyDeclSetterKind setter_kind(void) const;
  ObjCMethodDecl setter_method_declaration(void) const;
  Token setter_name_token(void) const;
  bool is_atomic(void) const;
  bool is_class_property(void) const;
  bool is_direct_property(void) const;
  bool is_instance_property(void) const;
  bool is_optional(void) const;
  bool is_read_only(void) const;
  bool is_retaining(void) const;
};

using ObjCMethodDeclRange = DerivedEntityRange<DeclIterator, ObjCMethodDecl>;
using ObjCMethodDeclContainingTokenRange = DerivedEntityRange<TokenContextIterator, ObjCMethodDecl>;
using ObjCMethodDeclContainingDeclRange = DerivedEntityRange<ParentDeclIteratorImpl<Decl>, ObjCMethodDecl>;

class ObjCMethodDecl : public NamedDecl {
 private:
  friend class FragmentImpl;
  friend class NamedDecl;
  friend class Decl;
 public:
  inline static ObjCMethodDeclRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static ObjCMethodDeclContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static ObjCMethodDeclContainingDeclRange containing(const Decl &decl);
  static ObjCMethodDeclContainingDeclRange containing(const Stmt &stmt);

  static std::optional<ObjCMethodDecl> from(const TokenContext &c);
  static std::optional<ObjCMethodDecl> from(const NamedDecl &parent);
  static std::optional<ObjCMethodDecl> from(const Decl &parent);
  bool defined_in_ns_object(void) const;
  ObjCPropertyDecl find_property_declaration(void) const;
  ObjCCategoryDecl category(void) const;
  ObjCInterfaceDecl class_interface(void) const;
  ImplicitParamDecl cmd_declaration(void) const;
  Token declarator_end_token(void) const;
  ObjCMethodDeclImplementationControl implementation_control(void) const;
  ObjCMethodFamily method_family(void) const;
  DeclObjCDeclQualifier obj_c_decl_qualifier(void) const;
  TokenRange return_type_source_range(void) const;
  Token selector_start_token(void) const;
  ImplicitParamDecl self_declaration(void) const;
  bool has_redeclaration(void) const;
  bool has_related_result_type(void) const;
  bool has_skipped_body(void) const;
  bool is_class_method(void) const;
  bool is_defined(void) const;
  bool is_designated_initializer_for_the_interface(void) const;
  bool is_direct_method(void) const;
  bool is_instance_method(void) const;
  bool is_optional(void) const;
  bool is_overriding(void) const;
  bool is_property_accessor(void) const;
  bool is_redeclaration(void) const;
  bool is_synthesized_accessor_stub(void) const;
  bool is_this_declaration_a_definition(void) const;
  bool is_this_declaration_a_designated_initializer(void) const;
  bool is_variadic(void) const;
  std::vector<ParmVarDecl> parameters(void) const;
  std::vector<Token> selector_tokens(void) const;
  std::vector<Decl> declarations_in_context(void) const;
};

using ObjCContainerDeclRange = DerivedEntityRange<DeclIterator, ObjCContainerDecl>;
using ObjCContainerDeclContainingTokenRange = DerivedEntityRange<TokenContextIterator, ObjCContainerDecl>;
using ObjCContainerDeclContainingDeclRange = DerivedEntityRange<ParentDeclIteratorImpl<Decl>, ObjCContainerDecl>;

class ObjCContainerDecl : public NamedDecl {
 private:
  friend class FragmentImpl;
  friend class NamedDecl;
  friend class Decl;
 public:
  inline static ObjCContainerDeclRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static ObjCContainerDeclContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static ObjCContainerDeclContainingDeclRange containing(const Decl &decl);
  static ObjCContainerDeclContainingDeclRange containing(const Stmt &stmt);

  static std::optional<ObjCContainerDecl> from(const TokenContext &c);
  static std::optional<ObjCContainerDecl> from(const NamedDecl &parent);
  static std::optional<ObjCContainerDecl> from(const Decl &parent);
  std::vector<ObjCMethodDecl> class_methods(void) const;
  std::vector<ObjCPropertyDecl> class_properties(void) const;
  TokenRange at_end_range(void) const;
  Token at_start_token(void) const;
  std::vector<ObjCMethodDecl> instance_methods(void) const;
  std::vector<ObjCPropertyDecl> instance_properties(void) const;
  std::vector<ObjCMethodDecl> methods(void) const;
  std::vector<ObjCPropertyDecl> properties(void) const;
  std::vector<Decl> declarations_in_context(void) const;
};

using ObjCCategoryDeclRange = DerivedEntityRange<DeclIterator, ObjCCategoryDecl>;
using ObjCCategoryDeclContainingTokenRange = DerivedEntityRange<TokenContextIterator, ObjCCategoryDecl>;
using ObjCCategoryDeclContainingDeclRange = DerivedEntityRange<ParentDeclIteratorImpl<Decl>, ObjCCategoryDecl>;

class ObjCCategoryDecl : public ObjCContainerDecl {
 private:
  friend class FragmentImpl;
  friend class ObjCContainerDecl;
  friend class NamedDecl;
  friend class Decl;
 public:
  inline static ObjCCategoryDeclRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static ObjCCategoryDeclContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static ObjCCategoryDeclContainingDeclRange containing(const Decl &decl);
  static ObjCCategoryDeclContainingDeclRange containing(const Stmt &stmt);

  static std::optional<ObjCCategoryDecl> from(const TokenContext &c);
  static std::optional<ObjCCategoryDecl> from(const ObjCContainerDecl &parent);
  static std::optional<ObjCCategoryDecl> from(const NamedDecl &parent);
  static std::optional<ObjCCategoryDecl> from(const Decl &parent);
  bool is_class_extension(void) const;
  Token category_name_token(void) const;
  ObjCInterfaceDecl class_interface(void) const;
  ObjCCategoryImplDecl implementation(void) const;
  Token instance_variable_l_brace_token(void) const;
  Token instance_variable_r_brace_token(void) const;
  ObjCCategoryDecl next_class_category(void) const;
  ObjCCategoryDecl next_class_category_raw(void) const;
  std::vector<ObjCIvarDecl> instance_variables(void) const;
  std::vector<Token> protocol_tokens(void) const;
  std::vector<ObjCProtocolDecl> protocols(void) const;
};

using ObjCProtocolDeclRange = DerivedEntityRange<DeclIterator, ObjCProtocolDecl>;
using ObjCProtocolDeclContainingTokenRange = DerivedEntityRange<TokenContextIterator, ObjCProtocolDecl>;
using ObjCProtocolDeclContainingDeclRange = DerivedEntityRange<ParentDeclIteratorImpl<Decl>, ObjCProtocolDecl>;

class ObjCProtocolDecl : public ObjCContainerDecl {
 private:
  friend class FragmentImpl;
  friend class ObjCContainerDecl;
  friend class NamedDecl;
  friend class Decl;
 public:
  inline static ObjCProtocolDeclRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static ObjCProtocolDeclContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static ObjCProtocolDeclContainingDeclRange containing(const Decl &decl);
  static ObjCProtocolDeclContainingDeclRange containing(const Stmt &stmt);

  static std::optional<ObjCProtocolDecl> from(const TokenContext &c);
  static std::optional<ObjCProtocolDecl> from(const ObjCContainerDecl &parent);
  static std::optional<ObjCProtocolDecl> from(const NamedDecl &parent);
  static std::optional<ObjCProtocolDecl> from(const Decl &parent);
  ObjCProtocolDecl definition(void) const;
  std::string_view obj_c_runtime_name_as_string(void) const;
  bool has_definition(void) const;
  bool is_non_runtime_protocol(void) const;
  bool is_this_declaration_a_definition(void) const;
  std::vector<Token> protocol_tokens(void) const;
  std::vector<ObjCProtocolDecl> protocols(void) const;
};

using ObjCInterfaceDeclRange = DerivedEntityRange<DeclIterator, ObjCInterfaceDecl>;
using ObjCInterfaceDeclContainingTokenRange = DerivedEntityRange<TokenContextIterator, ObjCInterfaceDecl>;
using ObjCInterfaceDeclContainingDeclRange = DerivedEntityRange<ParentDeclIteratorImpl<Decl>, ObjCInterfaceDecl>;

class ObjCInterfaceDecl : public ObjCContainerDecl {
 private:
  friend class FragmentImpl;
  friend class ObjCContainerDecl;
  friend class NamedDecl;
  friend class Decl;
 public:
  inline static ObjCInterfaceDeclRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static ObjCInterfaceDeclContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static ObjCInterfaceDeclContainingDeclRange containing(const Decl &decl);
  static ObjCInterfaceDeclContainingDeclRange containing(const Stmt &stmt);

  static std::optional<ObjCInterfaceDecl> from(const TokenContext &c);
  static std::optional<ObjCInterfaceDecl> from(const ObjCContainerDecl &parent);
  static std::optional<ObjCInterfaceDecl> from(const NamedDecl &parent);
  static std::optional<ObjCInterfaceDecl> from(const Decl &parent);
  std::vector<ObjCProtocolDecl> all_referenced_protocols(void) const;
  bool declares_or_inherits_designated_initializers(void) const;
  ObjCCategoryDecl category_list_raw(void) const;
  ObjCInterfaceDecl definition(void) const;
  Token end_of_definition_token(void) const;
  ObjCImplementationDecl implementation(void) const;
  std::string_view obj_c_runtime_name_as_string(void) const;
  ObjCInterfaceDecl super_class(void) const;
  Token super_class_token(void) const;
  bool has_definition(void) const;
  bool has_designated_initializers(void) const;
  bool is_arc_weakref_unavailable(void) const;
  bool is_implicit_interface_declaration(void) const;
  ObjCInterfaceDecl is_obj_c_requires_property_definitions(void) const;
  bool is_this_declaration_a_definition(void) const;
  std::vector<ObjCIvarDecl> instance_variables(void) const;
  std::vector<ObjCCategoryDecl> known_categories(void) const;
  std::vector<ObjCCategoryDecl> known_extensions(void) const;
  std::vector<Token> protocol_tokens(void) const;
  std::vector<ObjCProtocolDecl> protocols(void) const;
  std::vector<ObjCCategoryDecl> visible_categories(void) const;
  std::vector<ObjCCategoryDecl> visible_extensions(void) const;
};

using ObjCImplDeclRange = DerivedEntityRange<DeclIterator, ObjCImplDecl>;
using ObjCImplDeclContainingTokenRange = DerivedEntityRange<TokenContextIterator, ObjCImplDecl>;
using ObjCImplDeclContainingDeclRange = DerivedEntityRange<ParentDeclIteratorImpl<Decl>, ObjCImplDecl>;

class ObjCImplDecl : public ObjCContainerDecl {
 private:
  friend class FragmentImpl;
  friend class ObjCContainerDecl;
  friend class NamedDecl;
  friend class Decl;
 public:
  inline static ObjCImplDeclRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static ObjCImplDeclContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static ObjCImplDeclContainingDeclRange containing(const Decl &decl);
  static ObjCImplDeclContainingDeclRange containing(const Stmt &stmt);

  static std::optional<ObjCImplDecl> from(const TokenContext &c);
  static std::optional<ObjCImplDecl> from(const ObjCContainerDecl &parent);
  static std::optional<ObjCImplDecl> from(const NamedDecl &parent);
  static std::optional<ObjCImplDecl> from(const Decl &parent);
  ObjCInterfaceDecl class_interface(void) const;
  std::vector<ObjCPropertyImplDecl> property_implementations(void) const;
};

using ObjCCategoryImplDeclRange = DerivedEntityRange<DeclIterator, ObjCCategoryImplDecl>;
using ObjCCategoryImplDeclContainingTokenRange = DerivedEntityRange<TokenContextIterator, ObjCCategoryImplDecl>;
using ObjCCategoryImplDeclContainingDeclRange = DerivedEntityRange<ParentDeclIteratorImpl<Decl>, ObjCCategoryImplDecl>;

class ObjCCategoryImplDecl : public ObjCImplDecl {
 private:
  friend class FragmentImpl;
  friend class ObjCImplDecl;
  friend class ObjCContainerDecl;
  friend class NamedDecl;
  friend class Decl;
 public:
  inline static ObjCCategoryImplDeclRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static ObjCCategoryImplDeclContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static ObjCCategoryImplDeclContainingDeclRange containing(const Decl &decl);
  static ObjCCategoryImplDeclContainingDeclRange containing(const Stmt &stmt);

  static std::optional<ObjCCategoryImplDecl> from(const TokenContext &c);
  static std::optional<ObjCCategoryImplDecl> from(const ObjCImplDecl &parent);
  static std::optional<ObjCCategoryImplDecl> from(const ObjCContainerDecl &parent);
  static std::optional<ObjCCategoryImplDecl> from(const NamedDecl &parent);
  static std::optional<ObjCCategoryImplDecl> from(const Decl &parent);
  ObjCCategoryDecl category_declaration(void) const;
  Token category_name_token(void) const;
};

using ObjCImplementationDeclRange = DerivedEntityRange<DeclIterator, ObjCImplementationDecl>;
using ObjCImplementationDeclContainingTokenRange = DerivedEntityRange<TokenContextIterator, ObjCImplementationDecl>;
using ObjCImplementationDeclContainingDeclRange = DerivedEntityRange<ParentDeclIteratorImpl<Decl>, ObjCImplementationDecl>;

class ObjCImplementationDecl : public ObjCImplDecl {
 private:
  friend class FragmentImpl;
  friend class ObjCImplDecl;
  friend class ObjCContainerDecl;
  friend class NamedDecl;
  friend class Decl;
 public:
  inline static ObjCImplementationDeclRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static ObjCImplementationDeclContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static ObjCImplementationDeclContainingDeclRange containing(const Decl &decl);
  static ObjCImplementationDeclContainingDeclRange containing(const Stmt &stmt);

  static std::optional<ObjCImplementationDecl> from(const TokenContext &c);
  static std::optional<ObjCImplementationDecl> from(const ObjCImplDecl &parent);
  static std::optional<ObjCImplementationDecl> from(const ObjCContainerDecl &parent);
  static std::optional<ObjCImplementationDecl> from(const NamedDecl &parent);
  static std::optional<ObjCImplementationDecl> from(const Decl &parent);
  Token instance_variable_l_brace_token(void) const;
  Token instance_variable_r_brace_token(void) const;
  std::string_view obj_c_runtime_name_as_string(void) const;
  ObjCInterfaceDecl super_class(void) const;
  Token super_class_token(void) const;
  bool has_destructors(void) const;
  bool has_non_zero_constructors(void) const;
  std::vector<ObjCIvarDecl> instance_variables(void) const;
};

using ObjCCompatibleAliasDeclRange = DerivedEntityRange<DeclIterator, ObjCCompatibleAliasDecl>;
using ObjCCompatibleAliasDeclContainingTokenRange = DerivedEntityRange<TokenContextIterator, ObjCCompatibleAliasDecl>;
using ObjCCompatibleAliasDeclContainingDeclRange = DerivedEntityRange<ParentDeclIteratorImpl<Decl>, ObjCCompatibleAliasDecl>;

class ObjCCompatibleAliasDecl : public NamedDecl {
 private:
  friend class FragmentImpl;
  friend class NamedDecl;
  friend class Decl;
 public:
  inline static ObjCCompatibleAliasDeclRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static ObjCCompatibleAliasDeclContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static ObjCCompatibleAliasDeclContainingDeclRange containing(const Decl &decl);
  static ObjCCompatibleAliasDeclContainingDeclRange containing(const Stmt &stmt);

  static std::optional<ObjCCompatibleAliasDecl> from(const TokenContext &c);
  static std::optional<ObjCCompatibleAliasDecl> from(const NamedDecl &parent);
  static std::optional<ObjCCompatibleAliasDecl> from(const Decl &parent);
  ObjCInterfaceDecl class_interface(void) const;
};

using NamespaceDeclRange = DerivedEntityRange<DeclIterator, NamespaceDecl>;
using NamespaceDeclContainingTokenRange = DerivedEntityRange<TokenContextIterator, NamespaceDecl>;
using NamespaceDeclContainingDeclRange = DerivedEntityRange<ParentDeclIteratorImpl<Decl>, NamespaceDecl>;

class NamespaceDecl : public NamedDecl {
 private:
  friend class FragmentImpl;
  friend class NamedDecl;
  friend class Decl;
 public:
  inline static NamespaceDeclRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static NamespaceDeclContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static NamespaceDeclContainingDeclRange containing(const Decl &decl);
  static NamespaceDeclContainingDeclRange containing(const Stmt &stmt);

  static std::optional<NamespaceDecl> from(const TokenContext &c);
  static std::optional<NamespaceDecl> from(const NamedDecl &parent);
  static std::optional<NamespaceDecl> from(const Decl &parent);
  std::vector<Decl> declarations_in_context(void) const;
};

using NamespaceAliasDeclRange = DerivedEntityRange<DeclIterator, NamespaceAliasDecl>;
using NamespaceAliasDeclContainingTokenRange = DerivedEntityRange<TokenContextIterator, NamespaceAliasDecl>;
using NamespaceAliasDeclContainingDeclRange = DerivedEntityRange<ParentDeclIteratorImpl<Decl>, NamespaceAliasDecl>;

class NamespaceAliasDecl : public NamedDecl {
 private:
  friend class FragmentImpl;
  friend class NamedDecl;
  friend class Decl;
 public:
  inline static NamespaceAliasDeclRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static NamespaceAliasDeclContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static NamespaceAliasDeclContainingDeclRange containing(const Decl &decl);
  static NamespaceAliasDeclContainingDeclRange containing(const Stmt &stmt);

  static std::optional<NamespaceAliasDecl> from(const TokenContext &c);
  static std::optional<NamespaceAliasDecl> from(const NamedDecl &parent);
  static std::optional<NamespaceAliasDecl> from(const Decl &parent);
  Token alias_token(void) const;
  NamedDecl aliased_namespace(void) const;
  Token namespace_token(void) const;
  Token target_name_token(void) const;
};

using LinkageSpecDeclRange = DerivedEntityRange<DeclIterator, LinkageSpecDecl>;
using LinkageSpecDeclContainingTokenRange = DerivedEntityRange<TokenContextIterator, LinkageSpecDecl>;
using LinkageSpecDeclContainingDeclRange = DerivedEntityRange<ParentDeclIteratorImpl<Decl>, LinkageSpecDecl>;

class LinkageSpecDecl : public Decl {
 private:
  friend class FragmentImpl;
  friend class Decl;
 public:
  inline static LinkageSpecDeclRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static LinkageSpecDeclContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static LinkageSpecDeclContainingDeclRange containing(const Decl &decl);
  static LinkageSpecDeclContainingDeclRange containing(const Stmt &stmt);

  static std::optional<LinkageSpecDecl> from(const TokenContext &c);
  static std::optional<LinkageSpecDecl> from(const Decl &parent);
  std::vector<Decl> declarations_in_context(void) const;
};

using LifetimeExtendedTemporaryDeclRange = DerivedEntityRange<DeclIterator, LifetimeExtendedTemporaryDecl>;
using LifetimeExtendedTemporaryDeclContainingTokenRange = DerivedEntityRange<TokenContextIterator, LifetimeExtendedTemporaryDecl>;
using LifetimeExtendedTemporaryDeclContainingDeclRange = DerivedEntityRange<ParentDeclIteratorImpl<Decl>, LifetimeExtendedTemporaryDecl>;

class LifetimeExtendedTemporaryDecl : public Decl {
 private:
  friend class FragmentImpl;
  friend class Decl;
 public:
  inline static LifetimeExtendedTemporaryDeclRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static LifetimeExtendedTemporaryDeclContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static LifetimeExtendedTemporaryDeclContainingDeclRange containing(const Decl &decl);
  static LifetimeExtendedTemporaryDeclContainingDeclRange containing(const Stmt &stmt);

  static std::optional<LifetimeExtendedTemporaryDecl> from(const TokenContext &c);
  static std::optional<LifetimeExtendedTemporaryDecl> from(const Decl &parent);
  std::vector<Stmt> children_expression(void) const;
  ValueDecl extending_declaration(void) const;
  StorageDuration storage_duration(void) const;
  Expr temporary_expression(void) const;
};

using ImportDeclRange = DerivedEntityRange<DeclIterator, ImportDecl>;
using ImportDeclContainingTokenRange = DerivedEntityRange<TokenContextIterator, ImportDecl>;
using ImportDeclContainingDeclRange = DerivedEntityRange<ParentDeclIteratorImpl<Decl>, ImportDecl>;

class ImportDecl : public Decl {
 private:
  friend class FragmentImpl;
  friend class Decl;
 public:
  inline static ImportDeclRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static ImportDeclContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static ImportDeclContainingDeclRange containing(const Decl &decl);
  static ImportDeclContainingDeclRange containing(const Stmt &stmt);

  static std::optional<ImportDecl> from(const TokenContext &c);
  static std::optional<ImportDecl> from(const Decl &parent);
  std::vector<Token> identifier_tokens(void) const;
};

using FriendTemplateDeclRange = DerivedEntityRange<DeclIterator, FriendTemplateDecl>;
using FriendTemplateDeclContainingTokenRange = DerivedEntityRange<TokenContextIterator, FriendTemplateDecl>;
using FriendTemplateDeclContainingDeclRange = DerivedEntityRange<ParentDeclIteratorImpl<Decl>, FriendTemplateDecl>;

class FriendTemplateDecl : public Decl {
 private:
  friend class FragmentImpl;
  friend class Decl;
 public:
  inline static FriendTemplateDeclRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static FriendTemplateDeclContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static FriendTemplateDeclContainingDeclRange containing(const Decl &decl);
  static FriendTemplateDeclContainingDeclRange containing(const Stmt &stmt);

  static std::optional<FriendTemplateDecl> from(const TokenContext &c);
  static std::optional<FriendTemplateDecl> from(const Decl &parent);
};

using FriendDeclRange = DerivedEntityRange<DeclIterator, FriendDecl>;
using FriendDeclContainingTokenRange = DerivedEntityRange<TokenContextIterator, FriendDecl>;
using FriendDeclContainingDeclRange = DerivedEntityRange<ParentDeclIteratorImpl<Decl>, FriendDecl>;

class FriendDecl : public Decl {
 private:
  friend class FragmentImpl;
  friend class Decl;
 public:
  inline static FriendDeclRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static FriendDeclContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static FriendDeclContainingDeclRange containing(const Decl &decl);
  static FriendDeclContainingDeclRange containing(const Stmt &stmt);

  static std::optional<FriendDecl> from(const TokenContext &c);
  static std::optional<FriendDecl> from(const Decl &parent);
  NamedDecl friend_declaration(void) const;
  Token friend_token(void) const;
  bool is_unsupported_friend(void) const;
  std::vector<TemplateParameterList> friend_type_template_parameter_lists(void) const;
};

using FileScopeAsmDeclRange = DerivedEntityRange<DeclIterator, FileScopeAsmDecl>;
using FileScopeAsmDeclContainingTokenRange = DerivedEntityRange<TokenContextIterator, FileScopeAsmDecl>;
using FileScopeAsmDeclContainingDeclRange = DerivedEntityRange<ParentDeclIteratorImpl<Decl>, FileScopeAsmDecl>;

class FileScopeAsmDecl : public Decl {
 private:
  friend class FragmentImpl;
  friend class Decl;
 public:
  inline static FileScopeAsmDeclRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static FileScopeAsmDeclContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static FileScopeAsmDeclContainingDeclRange containing(const Decl &decl);
  static FileScopeAsmDeclContainingDeclRange containing(const Stmt &stmt);

  static std::optional<FileScopeAsmDecl> from(const TokenContext &c);
  static std::optional<FileScopeAsmDecl> from(const Decl &parent);
  Token assembly_token(void) const;
  StringLiteral assembly_string(void) const;
  Token r_paren_token(void) const;
};

using ExternCContextDeclRange = DerivedEntityRange<DeclIterator, ExternCContextDecl>;
using ExternCContextDeclContainingTokenRange = DerivedEntityRange<TokenContextIterator, ExternCContextDecl>;
using ExternCContextDeclContainingDeclRange = DerivedEntityRange<ParentDeclIteratorImpl<Decl>, ExternCContextDecl>;

class ExternCContextDecl : public Decl {
 private:
  friend class FragmentImpl;
  friend class Decl;
 public:
  inline static ExternCContextDeclRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static ExternCContextDeclContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static ExternCContextDeclContainingDeclRange containing(const Decl &decl);
  static ExternCContextDeclContainingDeclRange containing(const Stmt &stmt);

  static std::optional<ExternCContextDecl> from(const TokenContext &c);
  static std::optional<ExternCContextDecl> from(const Decl &parent);
  std::vector<Decl> declarations_in_context(void) const;
};

using ExportDeclRange = DerivedEntityRange<DeclIterator, ExportDecl>;
using ExportDeclContainingTokenRange = DerivedEntityRange<TokenContextIterator, ExportDecl>;
using ExportDeclContainingDeclRange = DerivedEntityRange<ParentDeclIteratorImpl<Decl>, ExportDecl>;

class ExportDecl : public Decl {
 private:
  friend class FragmentImpl;
  friend class Decl;
 public:
  inline static ExportDeclRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static ExportDeclContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static ExportDeclContainingDeclRange containing(const Decl &decl);
  static ExportDeclContainingDeclRange containing(const Stmt &stmt);

  static std::optional<ExportDecl> from(const TokenContext &c);
  static std::optional<ExportDecl> from(const Decl &parent);
  Token export_token(void) const;
  Token r_brace_token(void) const;
  bool has_braces(void) const;
  std::vector<Decl> declarations_in_context(void) const;
};

using EmptyDeclRange = DerivedEntityRange<DeclIterator, EmptyDecl>;
using EmptyDeclContainingTokenRange = DerivedEntityRange<TokenContextIterator, EmptyDecl>;
using EmptyDeclContainingDeclRange = DerivedEntityRange<ParentDeclIteratorImpl<Decl>, EmptyDecl>;

class EmptyDecl : public Decl {
 private:
  friend class FragmentImpl;
  friend class Decl;
 public:
  inline static EmptyDeclRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static EmptyDeclContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  static EmptyDeclContainingDeclRange containing(const Decl &decl);
  static EmptyDeclContainingDeclRange containing(const Stmt &stmt);

  static std::optional<EmptyDecl> from(const TokenContext &c);
  static std::optional<EmptyDecl> from(const Decl &parent);
};

static_assert(sizeof(SEHTryStmt) == sizeof(Stmt));

static_assert(sizeof(SEHLeaveStmt) == sizeof(Stmt));

static_assert(sizeof(SEHFinallyStmt) == sizeof(Stmt));

static_assert(sizeof(SEHExceptStmt) == sizeof(Stmt));

static_assert(sizeof(ReturnStmt) == sizeof(Stmt));

static_assert(sizeof(ObjCForCollectionStmt) == sizeof(Stmt));

static_assert(sizeof(ObjCAutoreleasePoolStmt) == sizeof(Stmt));

static_assert(sizeof(ObjCAtTryStmt) == sizeof(Stmt));

static_assert(sizeof(ObjCAtThrowStmt) == sizeof(Stmt));

static_assert(sizeof(ObjCAtSynchronizedStmt) == sizeof(Stmt));

static_assert(sizeof(ObjCAtFinallyStmt) == sizeof(Stmt));

static_assert(sizeof(ObjCAtCatchStmt) == sizeof(Stmt));

static_assert(sizeof(OMPExecutableDirective) == sizeof(Stmt));

static_assert(sizeof(OMPDispatchDirective) == sizeof(OMPExecutableDirective));

static_assert(sizeof(OMPDepobjDirective) == sizeof(OMPExecutableDirective));

static_assert(sizeof(OMPCriticalDirective) == sizeof(OMPExecutableDirective));

static_assert(sizeof(OMPCancellationPointDirective) == sizeof(OMPExecutableDirective));

static_assert(sizeof(OMPCancelDirective) == sizeof(OMPExecutableDirective));

static_assert(sizeof(OMPBarrierDirective) == sizeof(OMPExecutableDirective));

static_assert(sizeof(OMPAtomicDirective) == sizeof(OMPExecutableDirective));

static_assert(sizeof(OMPTeamsDirective) == sizeof(OMPExecutableDirective));

static_assert(sizeof(OMPTaskyieldDirective) == sizeof(OMPExecutableDirective));

static_assert(sizeof(OMPTaskwaitDirective) == sizeof(OMPExecutableDirective));

static_assert(sizeof(OMPTaskgroupDirective) == sizeof(OMPExecutableDirective));

static_assert(sizeof(OMPTaskDirective) == sizeof(OMPExecutableDirective));

static_assert(sizeof(OMPTargetUpdateDirective) == sizeof(OMPExecutableDirective));

static_assert(sizeof(OMPTargetTeamsDirective) == sizeof(OMPExecutableDirective));

static_assert(sizeof(OMPTargetParallelDirective) == sizeof(OMPExecutableDirective));

static_assert(sizeof(OMPTargetExitDataDirective) == sizeof(OMPExecutableDirective));

static_assert(sizeof(OMPTargetEnterDataDirective) == sizeof(OMPExecutableDirective));

static_assert(sizeof(OMPTargetDirective) == sizeof(OMPExecutableDirective));

static_assert(sizeof(OMPTargetDataDirective) == sizeof(OMPExecutableDirective));

static_assert(sizeof(OMPSingleDirective) == sizeof(OMPExecutableDirective));

static_assert(sizeof(OMPSectionsDirective) == sizeof(OMPExecutableDirective));

static_assert(sizeof(OMPSectionDirective) == sizeof(OMPExecutableDirective));

static_assert(sizeof(OMPScanDirective) == sizeof(OMPExecutableDirective));

static_assert(sizeof(OMPParallelSectionsDirective) == sizeof(OMPExecutableDirective));

static_assert(sizeof(OMPParallelMasterDirective) == sizeof(OMPExecutableDirective));

static_assert(sizeof(OMPParallelDirective) == sizeof(OMPExecutableDirective));

static_assert(sizeof(OMPOrderedDirective) == sizeof(OMPExecutableDirective));

static_assert(sizeof(OMPMasterDirective) == sizeof(OMPExecutableDirective));

static_assert(sizeof(OMPMaskedDirective) == sizeof(OMPExecutableDirective));

static_assert(sizeof(OMPLoopBasedDirective) == sizeof(OMPExecutableDirective));

static_assert(sizeof(OMPUnrollDirective) == sizeof(OMPLoopBasedDirective));

static_assert(sizeof(OMPTileDirective) == sizeof(OMPLoopBasedDirective));

static_assert(sizeof(OMPLoopDirective) == sizeof(OMPLoopBasedDirective));

static_assert(sizeof(OMPForSimdDirective) == sizeof(OMPLoopDirective));

static_assert(sizeof(OMPForDirective) == sizeof(OMPLoopDirective));

static_assert(sizeof(OMPDistributeSimdDirective) == sizeof(OMPLoopDirective));

static_assert(sizeof(OMPDistributeParallelForSimdDirective) == sizeof(OMPLoopDirective));

static_assert(sizeof(OMPDistributeParallelForDirective) == sizeof(OMPLoopDirective));

static_assert(sizeof(OMPDistributeDirective) == sizeof(OMPLoopDirective));

static_assert(sizeof(OMPTeamsDistributeSimdDirective) == sizeof(OMPLoopDirective));

static_assert(sizeof(OMPTeamsDistributeParallelForSimdDirective) == sizeof(OMPLoopDirective));

static_assert(sizeof(OMPTeamsDistributeParallelForDirective) == sizeof(OMPLoopDirective));

static_assert(sizeof(OMPTeamsDistributeDirective) == sizeof(OMPLoopDirective));

static_assert(sizeof(OMPTaskLoopSimdDirective) == sizeof(OMPLoopDirective));

static_assert(sizeof(OMPTaskLoopDirective) == sizeof(OMPLoopDirective));

static_assert(sizeof(OMPTargetTeamsDistributeSimdDirective) == sizeof(OMPLoopDirective));

static_assert(sizeof(OMPTargetTeamsDistributeParallelForSimdDirective) == sizeof(OMPLoopDirective));

static_assert(sizeof(OMPTargetTeamsDistributeParallelForDirective) == sizeof(OMPLoopDirective));

static_assert(sizeof(OMPTargetTeamsDistributeDirective) == sizeof(OMPLoopDirective));

static_assert(sizeof(OMPTargetSimdDirective) == sizeof(OMPLoopDirective));

static_assert(sizeof(OMPTargetParallelForSimdDirective) == sizeof(OMPLoopDirective));

static_assert(sizeof(OMPTargetParallelForDirective) == sizeof(OMPLoopDirective));

static_assert(sizeof(OMPSimdDirective) == sizeof(OMPLoopDirective));

static_assert(sizeof(OMPParallelMasterTaskLoopSimdDirective) == sizeof(OMPLoopDirective));

static_assert(sizeof(OMPParallelMasterTaskLoopDirective) == sizeof(OMPLoopDirective));

static_assert(sizeof(OMPParallelForSimdDirective) == sizeof(OMPLoopDirective));

static_assert(sizeof(OMPParallelForDirective) == sizeof(OMPLoopDirective));

static_assert(sizeof(OMPMasterTaskLoopSimdDirective) == sizeof(OMPLoopDirective));

static_assert(sizeof(OMPMasterTaskLoopDirective) == sizeof(OMPLoopDirective));

static_assert(sizeof(OMPInteropDirective) == sizeof(OMPExecutableDirective));

static_assert(sizeof(OMPFlushDirective) == sizeof(OMPExecutableDirective));

static_assert(sizeof(OMPCanonicalLoop) == sizeof(Stmt));

static_assert(sizeof(NullStmt) == sizeof(Stmt));

static_assert(sizeof(MSDependentExistsStmt) == sizeof(Stmt));

static_assert(sizeof(IndirectGotoStmt) == sizeof(Stmt));

static_assert(sizeof(IfStmt) == sizeof(Stmt));

static_assert(sizeof(GotoStmt) == sizeof(Stmt));

static_assert(sizeof(ForStmt) == sizeof(Stmt));

static_assert(sizeof(DoStmt) == sizeof(Stmt));

static_assert(sizeof(DeclStmt) == sizeof(Stmt));

static_assert(sizeof(CoroutineBodyStmt) == sizeof(Stmt));

static_assert(sizeof(CoreturnStmt) == sizeof(Stmt));

static_assert(sizeof(ContinueStmt) == sizeof(Stmt));

static_assert(sizeof(CompoundStmt) == sizeof(Stmt));

static_assert(sizeof(CapturedStmt) == sizeof(Stmt));

static_assert(sizeof(CXXTryStmt) == sizeof(Stmt));

static_assert(sizeof(CXXForRangeStmt) == sizeof(Stmt));

static_assert(sizeof(CXXCatchStmt) == sizeof(Stmt));

static_assert(sizeof(BreakStmt) == sizeof(Stmt));

static_assert(sizeof(AsmStmt) == sizeof(Stmt));

static_assert(sizeof(MSAsmStmt) == sizeof(AsmStmt));

static_assert(sizeof(GCCAsmStmt) == sizeof(AsmStmt));

static_assert(sizeof(WhileStmt) == sizeof(Stmt));

static_assert(sizeof(ValueStmt) == sizeof(Stmt));

static_assert(sizeof(LabelStmt) == sizeof(ValueStmt));

static_assert(sizeof(Expr) == sizeof(ValueStmt));

static_assert(sizeof(DesignatedInitUpdateExpr) == sizeof(Expr));

static_assert(sizeof(DesignatedInitExpr) == sizeof(Expr));

static_assert(sizeof(DependentScopeDeclRefExpr) == sizeof(Expr));

static_assert(sizeof(DependentCoawaitExpr) == sizeof(Expr));

static_assert(sizeof(DeclRefExpr) == sizeof(Expr));

static_assert(sizeof(CoroutineSuspendExpr) == sizeof(Expr));

static_assert(sizeof(CoawaitExpr) == sizeof(CoroutineSuspendExpr));

static_assert(sizeof(CoyieldExpr) == sizeof(CoroutineSuspendExpr));

static_assert(sizeof(ConvertVectorExpr) == sizeof(Expr));

static_assert(sizeof(ConceptSpecializationExpr) == sizeof(Expr));

static_assert(sizeof(CompoundLiteralExpr) == sizeof(Expr));

static_assert(sizeof(ChooseExpr) == sizeof(Expr));

static_assert(sizeof(CharacterLiteral) == sizeof(Expr));

static_assert(sizeof(CastExpr) == sizeof(Expr));

static_assert(sizeof(ImplicitCastExpr) == sizeof(CastExpr));

static_assert(sizeof(ExplicitCastExpr) == sizeof(CastExpr));

static_assert(sizeof(CXXNamedCastExpr) == sizeof(ExplicitCastExpr));

static_assert(sizeof(CXXDynamicCastExpr) == sizeof(CXXNamedCastExpr));

static_assert(sizeof(CXXConstCastExpr) == sizeof(CXXNamedCastExpr));

static_assert(sizeof(CXXAddrspaceCastExpr) == sizeof(CXXNamedCastExpr));

static_assert(sizeof(CXXStaticCastExpr) == sizeof(CXXNamedCastExpr));

static_assert(sizeof(CXXReinterpretCastExpr) == sizeof(CXXNamedCastExpr));

static_assert(sizeof(CXXFunctionalCastExpr) == sizeof(ExplicitCastExpr));

static_assert(sizeof(CStyleCastExpr) == sizeof(ExplicitCastExpr));

static_assert(sizeof(BuiltinBitCastExpr) == sizeof(ExplicitCastExpr));

static_assert(sizeof(ObjCBridgedCastExpr) == sizeof(ExplicitCastExpr));

static_assert(sizeof(CallExpr) == sizeof(Expr));

static_assert(sizeof(CXXOperatorCallExpr) == sizeof(CallExpr));

static_assert(sizeof(CXXMemberCallExpr) == sizeof(CallExpr));

static_assert(sizeof(CUDAKernelCallExpr) == sizeof(CallExpr));

static_assert(sizeof(UserDefinedLiteral) == sizeof(CallExpr));

static_assert(sizeof(CXXUuidofExpr) == sizeof(Expr));

static_assert(sizeof(CXXUnresolvedConstructExpr) == sizeof(Expr));

static_assert(sizeof(CXXTypeidExpr) == sizeof(Expr));

static_assert(sizeof(CXXThrowExpr) == sizeof(Expr));

static_assert(sizeof(CXXThisExpr) == sizeof(Expr));

static_assert(sizeof(CXXStdInitializerListExpr) == sizeof(Expr));

static_assert(sizeof(CXXScalarValueInitExpr) == sizeof(Expr));

static_assert(sizeof(CXXRewrittenBinaryOperator) == sizeof(Expr));

static_assert(sizeof(CXXPseudoDestructorExpr) == sizeof(Expr));

static_assert(sizeof(CXXNullPtrLiteralExpr) == sizeof(Expr));

static_assert(sizeof(CXXNoexceptExpr) == sizeof(Expr));

static_assert(sizeof(CXXNewExpr) == sizeof(Expr));

static_assert(sizeof(CXXInheritedCtorInitExpr) == sizeof(Expr));

static_assert(sizeof(CXXFoldExpr) == sizeof(Expr));

static_assert(sizeof(CXXDependentScopeMemberExpr) == sizeof(Expr));

static_assert(sizeof(CXXDeleteExpr) == sizeof(Expr));

static_assert(sizeof(CXXDefaultInitExpr) == sizeof(Expr));

static_assert(sizeof(CXXDefaultArgExpr) == sizeof(Expr));

static_assert(sizeof(CXXConstructExpr) == sizeof(Expr));

static_assert(sizeof(CXXTemporaryObjectExpr) == sizeof(CXXConstructExpr));

static_assert(sizeof(CXXBoolLiteralExpr) == sizeof(Expr));

static_assert(sizeof(CXXBindTemporaryExpr) == sizeof(Expr));

static_assert(sizeof(BlockExpr) == sizeof(Expr));

static_assert(sizeof(BinaryOperator) == sizeof(Expr));

static_assert(sizeof(CompoundAssignOperator) == sizeof(BinaryOperator));

static_assert(sizeof(AtomicExpr) == sizeof(Expr));

static_assert(sizeof(AsTypeExpr) == sizeof(Expr));

static_assert(sizeof(ArrayTypeTraitExpr) == sizeof(Expr));

static_assert(sizeof(ArraySubscriptExpr) == sizeof(Expr));

static_assert(sizeof(ArrayInitLoopExpr) == sizeof(Expr));

static_assert(sizeof(ArrayInitIndexExpr) == sizeof(Expr));

static_assert(sizeof(AddrLabelExpr) == sizeof(Expr));

static_assert(sizeof(AbstractConditionalOperator) == sizeof(Expr));

static_assert(sizeof(ConditionalOperator) == sizeof(AbstractConditionalOperator));

static_assert(sizeof(BinaryConditionalOperator) == sizeof(AbstractConditionalOperator));

static_assert(sizeof(VAArgExpr) == sizeof(Expr));

static_assert(sizeof(UnaryOperator) == sizeof(Expr));

static_assert(sizeof(UnaryExprOrTypeTraitExpr) == sizeof(Expr));

static_assert(sizeof(TypoExpr) == sizeof(Expr));

static_assert(sizeof(TypeTraitExpr) == sizeof(Expr));

static_assert(sizeof(SubstNonTypeTemplateParmPackExpr) == sizeof(Expr));

static_assert(sizeof(SubstNonTypeTemplateParmExpr) == sizeof(Expr));

static_assert(sizeof(StringLiteral) == sizeof(Expr));

static_assert(sizeof(StmtExpr) == sizeof(Expr));

static_assert(sizeof(SourceLocExpr) == sizeof(Expr));

static_assert(sizeof(SizeOfPackExpr) == sizeof(Expr));

static_assert(sizeof(ShuffleVectorExpr) == sizeof(Expr));

static_assert(sizeof(SYCLUniqueStableNameExpr) == sizeof(Expr));

static_assert(sizeof(RequiresExpr) == sizeof(Expr));

static_assert(sizeof(RecoveryExpr) == sizeof(Expr));

static_assert(sizeof(PseudoObjectExpr) == sizeof(Expr));

static_assert(sizeof(PredefinedExpr) == sizeof(Expr));

static_assert(sizeof(ParenListExpr) == sizeof(Expr));

static_assert(sizeof(ParenExpr) == sizeof(Expr));

static_assert(sizeof(PackExpansionExpr) == sizeof(Expr));

static_assert(sizeof(OverloadExpr) == sizeof(Expr));

static_assert(sizeof(UnresolvedMemberExpr) == sizeof(OverloadExpr));

static_assert(sizeof(UnresolvedLookupExpr) == sizeof(OverloadExpr));

static_assert(sizeof(OpaqueValueExpr) == sizeof(Expr));

static_assert(sizeof(OffsetOfExpr) == sizeof(Expr));

static_assert(sizeof(ObjCSubscriptRefExpr) == sizeof(Expr));

static_assert(sizeof(ObjCStringLiteral) == sizeof(Expr));

static_assert(sizeof(ObjCSelectorExpr) == sizeof(Expr));

static_assert(sizeof(ObjCProtocolExpr) == sizeof(Expr));

static_assert(sizeof(ObjCPropertyRefExpr) == sizeof(Expr));

static_assert(sizeof(ObjCMessageExpr) == sizeof(Expr));

static_assert(sizeof(ObjCIvarRefExpr) == sizeof(Expr));

static_assert(sizeof(ObjCIsaExpr) == sizeof(Expr));

static_assert(sizeof(ObjCIndirectCopyRestoreExpr) == sizeof(Expr));

static_assert(sizeof(ObjCEncodeExpr) == sizeof(Expr));

static_assert(sizeof(ObjCDictionaryLiteral) == sizeof(Expr));

static_assert(sizeof(ObjCBoxedExpr) == sizeof(Expr));

static_assert(sizeof(ObjCBoolLiteralExpr) == sizeof(Expr));

static_assert(sizeof(ObjCAvailabilityCheckExpr) == sizeof(Expr));

static_assert(sizeof(ObjCArrayLiteral) == sizeof(Expr));

static_assert(sizeof(OMPIteratorExpr) == sizeof(Expr));

static_assert(sizeof(OMPArrayShapingExpr) == sizeof(Expr));

static_assert(sizeof(OMPArraySectionExpr) == sizeof(Expr));

static_assert(sizeof(NoInitExpr) == sizeof(Expr));

static_assert(sizeof(MemberExpr) == sizeof(Expr));

static_assert(sizeof(MatrixSubscriptExpr) == sizeof(Expr));

static_assert(sizeof(MaterializeTemporaryExpr) == sizeof(Expr));

static_assert(sizeof(MSPropertySubscriptExpr) == sizeof(Expr));

static_assert(sizeof(MSPropertyRefExpr) == sizeof(Expr));

static_assert(sizeof(LambdaExpr) == sizeof(Expr));

static_assert(sizeof(IntegerLiteral) == sizeof(Expr));

static_assert(sizeof(InitListExpr) == sizeof(Expr));

static_assert(sizeof(ImplicitValueInitExpr) == sizeof(Expr));

static_assert(sizeof(ImaginaryLiteral) == sizeof(Expr));

static_assert(sizeof(GenericSelectionExpr) == sizeof(Expr));

static_assert(sizeof(GNUNullExpr) == sizeof(Expr));

static_assert(sizeof(FunctionParmPackExpr) == sizeof(Expr));

static_assert(sizeof(FullExpr) == sizeof(Expr));

static_assert(sizeof(ExprWithCleanups) == sizeof(FullExpr));

static_assert(sizeof(ConstantExpr) == sizeof(FullExpr));

static_assert(sizeof(FloatingLiteral) == sizeof(Expr));

static_assert(sizeof(FixedPointLiteral) == sizeof(Expr));

static_assert(sizeof(ExtVectorElementExpr) == sizeof(Expr));

static_assert(sizeof(ExpressionTraitExpr) == sizeof(Expr));

static_assert(sizeof(AttributedStmt) == sizeof(ValueStmt));

static_assert(sizeof(SwitchStmt) == sizeof(Stmt));

static_assert(sizeof(SwitchCase) == sizeof(Stmt));

static_assert(sizeof(DefaultStmt) == sizeof(SwitchCase));

static_assert(sizeof(CaseStmt) == sizeof(SwitchCase));

static_assert(sizeof(ClassScopeFunctionSpecializationDecl) == sizeof(Decl));

static_assert(sizeof(CapturedDecl) == sizeof(Decl));

static_assert(sizeof(BlockDecl) == sizeof(Decl));

static_assert(sizeof(AccessSpecDecl) == sizeof(Decl));

static_assert(sizeof(OMPDeclarativeDirectiveDecl) == sizeof(Decl));

static_assert(sizeof(OMPThreadPrivateDecl) == sizeof(OMPDeclarativeDirectiveDecl));

static_assert(sizeof(OMPRequiresDecl) == sizeof(OMPDeclarativeDirectiveDecl));

static_assert(sizeof(OMPAllocateDecl) == sizeof(OMPDeclarativeDirectiveDecl));

static_assert(sizeof(TranslationUnitDecl) == sizeof(Decl));

static_assert(sizeof(StaticAssertDecl) == sizeof(Decl));

static_assert(sizeof(RequiresExprBodyDecl) == sizeof(Decl));

static_assert(sizeof(PragmaDetectMismatchDecl) == sizeof(Decl));

static_assert(sizeof(PragmaCommentDecl) == sizeof(Decl));

static_assert(sizeof(ObjCPropertyImplDecl) == sizeof(Decl));

static_assert(sizeof(NamedDecl) == sizeof(Decl));

static_assert(sizeof(LabelDecl) == sizeof(NamedDecl));

static_assert(sizeof(BaseUsingDecl) == sizeof(NamedDecl));

static_assert(sizeof(UsingEnumDecl) == sizeof(BaseUsingDecl));

static_assert(sizeof(UsingDecl) == sizeof(BaseUsingDecl));

static_assert(sizeof(ValueDecl) == sizeof(NamedDecl));

static_assert(sizeof(UnresolvedUsingValueDecl) == sizeof(ValueDecl));

static_assert(sizeof(TemplateParamObjectDecl) == sizeof(ValueDecl));

static_assert(sizeof(OMPDeclareReductionDecl) == sizeof(ValueDecl));

static_assert(sizeof(MSGuidDecl) == sizeof(ValueDecl));

static_assert(sizeof(IndirectFieldDecl) == sizeof(ValueDecl));

static_assert(sizeof(EnumConstantDecl) == sizeof(ValueDecl));

static_assert(sizeof(DeclaratorDecl) == sizeof(ValueDecl));

static_assert(sizeof(VarDecl) == sizeof(DeclaratorDecl));

static_assert(sizeof(ParmVarDecl) == sizeof(VarDecl));

static_assert(sizeof(OMPCapturedExprDecl) == sizeof(VarDecl));

static_assert(sizeof(ImplicitParamDecl) == sizeof(VarDecl));

static_assert(sizeof(DecompositionDecl) == sizeof(VarDecl));

static_assert(sizeof(VarTemplateSpecializationDecl) == sizeof(VarDecl));

static_assert(sizeof(VarTemplatePartialSpecializationDecl) == sizeof(VarTemplateSpecializationDecl));

static_assert(sizeof(NonTypeTemplateParmDecl) == sizeof(DeclaratorDecl));

static_assert(sizeof(MSPropertyDecl) == sizeof(DeclaratorDecl));

static_assert(sizeof(FunctionDecl) == sizeof(DeclaratorDecl));

static_assert(sizeof(CXXMethodDecl) == sizeof(FunctionDecl));

static_assert(sizeof(CXXDestructorDecl) == sizeof(CXXMethodDecl));

static_assert(sizeof(CXXConversionDecl) == sizeof(CXXMethodDecl));

static_assert(sizeof(CXXConstructorDecl) == sizeof(CXXMethodDecl));

static_assert(sizeof(CXXDeductionGuideDecl) == sizeof(FunctionDecl));

static_assert(sizeof(FieldDecl) == sizeof(DeclaratorDecl));

static_assert(sizeof(ObjCIvarDecl) == sizeof(FieldDecl));

static_assert(sizeof(ObjCAtDefsFieldDecl) == sizeof(FieldDecl));

static_assert(sizeof(BindingDecl) == sizeof(ValueDecl));

static_assert(sizeof(OMPDeclarativeDirectiveValueDecl) == sizeof(ValueDecl));

static_assert(sizeof(OMPDeclareMapperDecl) == sizeof(OMPDeclarativeDirectiveValueDecl));

static_assert(sizeof(UsingShadowDecl) == sizeof(NamedDecl));

static_assert(sizeof(ConstructorUsingShadowDecl) == sizeof(UsingShadowDecl));

static_assert(sizeof(UsingPackDecl) == sizeof(NamedDecl));

static_assert(sizeof(UsingDirectiveDecl) == sizeof(NamedDecl));

static_assert(sizeof(UnresolvedUsingIfExistsDecl) == sizeof(NamedDecl));

static_assert(sizeof(TypeDecl) == sizeof(NamedDecl));

static_assert(sizeof(TemplateTypeParmDecl) == sizeof(TypeDecl));

static_assert(sizeof(TagDecl) == sizeof(TypeDecl));

static_assert(sizeof(RecordDecl) == sizeof(TagDecl));

static_assert(sizeof(CXXRecordDecl) == sizeof(RecordDecl));

static_assert(sizeof(ClassTemplateSpecializationDecl) == sizeof(CXXRecordDecl));

static_assert(sizeof(ClassTemplatePartialSpecializationDecl) == sizeof(ClassTemplateSpecializationDecl));

static_assert(sizeof(EnumDecl) == sizeof(TagDecl));

static_assert(sizeof(UnresolvedUsingTypenameDecl) == sizeof(TypeDecl));

static_assert(sizeof(TypedefNameDecl) == sizeof(TypeDecl));

static_assert(sizeof(TypedefDecl) == sizeof(TypedefNameDecl));

static_assert(sizeof(TypeAliasDecl) == sizeof(TypedefNameDecl));

static_assert(sizeof(ObjCTypeParamDecl) == sizeof(TypedefNameDecl));

static_assert(sizeof(TemplateDecl) == sizeof(NamedDecl));

static_assert(sizeof(RedeclarableTemplateDecl) == sizeof(TemplateDecl));

static_assert(sizeof(FunctionTemplateDecl) == sizeof(RedeclarableTemplateDecl));

static_assert(sizeof(ClassTemplateDecl) == sizeof(RedeclarableTemplateDecl));

static_assert(sizeof(VarTemplateDecl) == sizeof(RedeclarableTemplateDecl));

static_assert(sizeof(TypeAliasTemplateDecl) == sizeof(RedeclarableTemplateDecl));

static_assert(sizeof(ConceptDecl) == sizeof(TemplateDecl));

static_assert(sizeof(BuiltinTemplateDecl) == sizeof(TemplateDecl));

static_assert(sizeof(TemplateTemplateParmDecl) == sizeof(TemplateDecl));

static_assert(sizeof(ObjCPropertyDecl) == sizeof(NamedDecl));

static_assert(sizeof(ObjCMethodDecl) == sizeof(NamedDecl));

static_assert(sizeof(ObjCContainerDecl) == sizeof(NamedDecl));

static_assert(sizeof(ObjCCategoryDecl) == sizeof(ObjCContainerDecl));

static_assert(sizeof(ObjCProtocolDecl) == sizeof(ObjCContainerDecl));

static_assert(sizeof(ObjCInterfaceDecl) == sizeof(ObjCContainerDecl));

static_assert(sizeof(ObjCImplDecl) == sizeof(ObjCContainerDecl));

static_assert(sizeof(ObjCCategoryImplDecl) == sizeof(ObjCImplDecl));

static_assert(sizeof(ObjCImplementationDecl) == sizeof(ObjCImplDecl));

static_assert(sizeof(ObjCCompatibleAliasDecl) == sizeof(NamedDecl));

static_assert(sizeof(NamespaceDecl) == sizeof(NamedDecl));

static_assert(sizeof(NamespaceAliasDecl) == sizeof(NamedDecl));

static_assert(sizeof(LinkageSpecDecl) == sizeof(Decl));

static_assert(sizeof(LifetimeExtendedTemporaryDecl) == sizeof(Decl));

static_assert(sizeof(ImportDecl) == sizeof(Decl));

static_assert(sizeof(FriendTemplateDecl) == sizeof(Decl));

static_assert(sizeof(FriendDecl) == sizeof(Decl));

static_assert(sizeof(FileScopeAsmDecl) == sizeof(Decl));

static_assert(sizeof(ExternCContextDecl) == sizeof(Decl));

static_assert(sizeof(ExportDecl) == sizeof(Decl));

static_assert(sizeof(EmptyDecl) == sizeof(Decl));

#endif  // MX_DISABLE_API
}  // namespace mx
