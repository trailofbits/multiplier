// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>

namespace pasta {
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
class Type;
class TypeOfExprType;
class TypeOfType;
class TypedefType;
class UnaryTransformType;
class UnresolvedUsingType;
class VectorType;
class AdjustedType;
class ArrayType;
class AtomicType;
class AttributedType;
class BlockPointerType;
class BuiltinType;
class ComplexType;
class ConstantArrayType;
class DecayedType;
class DecltypeType;
class DeducedType;
class DependentAddressSpaceType;
class DependentExtIntType;
class DependentNameType;
class DependentSizedArrayType;
class DependentSizedExtVectorType;
class DependentTemplateSpecializationType;
class DependentVectorType;
class ElaboratedType;
class ExtIntType;
class ExtVectorType;
class FunctionType;
class IncompleteArrayType;
class InjectedClassNameType;
class MacroQualifiedType;
class MatrixType;
class MemberPointerType;
class ObjCObjectPointerType;
class ObjCObjectType;
class ObjCTypeParamType;
class PackExpansionType;
class ParenType;
class PipeType;
class PointerType;
class ReferenceType;
class SubstTemplateTypeParmPackType;
class SubstTemplateTypeParmType;
class TagType;
class TemplateSpecializationType;
class TemplateTypeParmType;
class VariableArrayType;
class AutoType;
class ConstantMatrixType;
class DeducedTemplateSpecializationType;
class DependentSizedMatrixType;
class EnumType;
class FunctionNoProtoType;
class FunctionProtoType;
class LValueReferenceType;
class ObjCInterfaceType;
class RValueReferenceType;
class RecordType;
class Token;
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
enum class SanitizerOrdinal : uint64_t;
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

enum class ArrayTypeArraySizeModifier : unsigned short {
  NORMAL,
  STATIC,
  STAR,
  NUM_ENUMERATORS
};

ArrayTypeArraySizeModifier FromPasta(pasta::ArrayTypeArraySizeModifier pasta_val);

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

enum class CXXConstructExprConstructionKind : unsigned short {
  COMPLETE,
  NON_VIRTUAL_BASE,
  VIRTUAL_BASE,
  DELEGATING,
  NUM_ENUMERATORS
};

CXXConstructExprConstructionKind FromPasta(pasta::CXXConstructExprConstructionKind pasta_val);

enum class CXXNewExprInitializationStyle : unsigned short {
  NO_INITIALIZER,
  CALL_INITIALIZER,
  LIST_INITIALIZER,
  NUM_ENUMERATORS
};

CXXNewExprInitializationStyle FromPasta(pasta::CXXNewExprInitializationStyle pasta_val);

enum class CallExprADLCallKind : unsigned short {
  NOT_ADL,
  USES_ADL,
  NUM_ENUMERATORS
};

CallExprADLCallKind FromPasta(pasta::CallExprADLCallKind pasta_val);

enum class CapturedStmtVariableCaptureKind : unsigned short {
  THIS,
  BY_REFERENCE,
  BY_COPY,
  VLA_TYPE,
  NUM_ENUMERATORS
};

CapturedStmtVariableCaptureKind FromPasta(pasta::CapturedStmtVariableCaptureKind pasta_val);

enum class CharacterLiteralCharacterKind : unsigned short {
  ASCII,
  WIDE,
  UT_F8,
  UT_F16,
  UT_F32,
  NUM_ENUMERATORS
};

CharacterLiteralCharacterKind FromPasta(pasta::CharacterLiteralCharacterKind pasta_val);

enum class ConstantExprResultStorageKind : unsigned short {
  NONE,
  INT64,
  AP_VALUE,
  NUM_ENUMERATORS
};

ConstantExprResultStorageKind FromPasta(pasta::ConstantExprResultStorageKind pasta_val);

enum class DeclFriendObjectKind : unsigned short {
  NONE,
  DECLARED,
  UNDECLARED,
  NUM_ENUMERATORS
};

DeclFriendObjectKind FromPasta(pasta::DeclFriendObjectKind pasta_val);

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

enum class DeclModuleOwnershipKind : unsigned short {
  UNOWNED,
  VISIBLE,
  VISIBLE_WHEN_IMPORTED,
  MODULE_PRIVATE,
  NUM_ENUMERATORS
};

DeclModuleOwnershipKind FromPasta(pasta::DeclModuleOwnershipKind pasta_val);

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

enum class ExprConstantExprKind : unsigned short {
  NORMAL,
  NON_CLASS_TEMPLATE_ARGUMENT,
  CLASS_TEMPLATE_ARGUMENT,
  IMMEDIATE_INVOCATION,
  NUM_ENUMERATORS
};

ExprConstantExprKind FromPasta(pasta::ExprConstantExprKind pasta_val);

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

enum class ExprNullPointerConstantKind : unsigned short {
  NOT_NULL,
  ZERO_EXPRESSION,
  ZERO_LITERAL,
  CX_X11_NULLPTR,
  GNU_NULL,
  NUM_ENUMERATORS
};

ExprNullPointerConstantKind FromPasta(pasta::ExprNullPointerConstantKind pasta_val);

enum class ExprNullPointerConstantValueDependence : unsigned short {
  NEVER_VALUE_DEPENDENT,
  VALUE_DEPENDENT_IS_NULL,
  VALUE_DEPENDENT_IS_NOT_NULL,
  NUM_ENUMERATORS
};

ExprNullPointerConstantValueDependence FromPasta(pasta::ExprNullPointerConstantValueDependence pasta_val);

enum class ExprSideEffectsKind : unsigned short {
  NO_SIDE_EFFECTS,
  ALLOW_UNDEFINED_BEHAVIOR,
  ALLOW_SIDE_EFFECTS,
  NUM_ENUMERATORS
};

ExprSideEffectsKind FromPasta(pasta::ExprSideEffectsKind pasta_val);

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

enum class FunctionDeclTemplatedKind : unsigned short {
  NON_TEMPLATE,
  FUNCTION_TEMPLATE,
  MEMBER_SPECIALIZATION,
  FUNCTION_TEMPLATE_SPECIALIZATION,
  DEPENDENT_FUNCTION_TEMPLATE_SPECIALIZATION,
  NUM_ENUMERATORS
};

FunctionDeclTemplatedKind FromPasta(pasta::FunctionDeclTemplatedKind pasta_val);

enum class ImplicitCastExprOnStack : unsigned short {
  ON_STACK,
  NUM_ENUMERATORS
};

ImplicitCastExprOnStack FromPasta(pasta::ImplicitCastExprOnStack pasta_val);

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

enum class LinkageSpecDeclLanguageIDs : unsigned short {
  C,
  CXX,
  NUM_ENUMERATORS
};

LinkageSpecDeclLanguageIDs FromPasta(pasta::LinkageSpecDeclLanguageIDs pasta_val);

enum class NamedDeclExplicitVisibilityKind : unsigned short {
  VISIBILITY_FOR_TYPE,
  VISIBILITY_FOR_VALUE,
  NUM_ENUMERATORS
};

NamedDeclExplicitVisibilityKind FromPasta(pasta::NamedDeclExplicitVisibilityKind pasta_val);

enum class OMPDeclareReductionDeclInitKind : unsigned short {
  CALL_INITIALIZER,
  DIRECT_INITIALIZER,
  COPY_INITIALIZER,
  NUM_ENUMERATORS
};

OMPDeclareReductionDeclInitKind FromPasta(pasta::OMPDeclareReductionDeclInitKind pasta_val);

enum class ObjCIvarDeclAccessControl : unsigned short {
  NONE,
  PRIVATE,
  PROTECTED,
  PUBLIC,
  PACKAGE,
  NUM_ENUMERATORS
};

ObjCIvarDeclAccessControl FromPasta(pasta::ObjCIvarDeclAccessControl pasta_val);

enum class ObjCMessageExprReceiverKind : unsigned short {
  CLASS,
  INSTANCE,
  SUPER_CLASS,
  SUPER_INSTANCE,
  NUM_ENUMERATORS
};

ObjCMessageExprReceiverKind FromPasta(pasta::ObjCMessageExprReceiverKind pasta_val);

enum class ObjCMethodDeclImplementationControl : unsigned short {
  NONE,
  REQUIRED,
  OPTIONAL,
  NUM_ENUMERATORS
};

ObjCMethodDeclImplementationControl FromPasta(pasta::ObjCMethodDeclImplementationControl pasta_val);

enum class ObjCPropertyDeclPropertyControl : unsigned short {
  NONE,
  REQUIRED,
  OPTIONAL,
  NUM_ENUMERATORS
};

ObjCPropertyDeclPropertyControl FromPasta(pasta::ObjCPropertyDeclPropertyControl pasta_val);

enum class ObjCPropertyDeclSetterKind : unsigned short {
  ASSIGN,
  RETAIN,
  COPY,
  WEAK,
  NUM_ENUMERATORS
};

ObjCPropertyDeclSetterKind FromPasta(pasta::ObjCPropertyDeclSetterKind pasta_val);

enum class ObjCPropertyImplDeclKind : unsigned short {
  SYNTHESIZE,
  DYNAMIC,
  NUM_ENUMERATORS
};

ObjCPropertyImplDeclKind FromPasta(pasta::ObjCPropertyImplDeclKind pasta_val);

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

enum class QualTypeDestructionKind : unsigned short {
  NONE,
  CXX_DESTRUCTOR,
  OBJC_STRONG_LIFETIME,
  OBJC_WEAK_LIFETIME,
  NONTRIVIAL_C_STRUCT,
  NUM_ENUMERATORS
};

QualTypeDestructionKind FromPasta(pasta::QualTypeDestructionKind pasta_val);

enum class QualTypePrimitiveCopyKind : unsigned short {
  TRIVIAL,
  VOLATILE_TRIVIAL,
  ARC_STRONG,
  ARC_WEAK,
  STRUCT,
  NUM_ENUMERATORS
};

QualTypePrimitiveCopyKind FromPasta(pasta::QualTypePrimitiveCopyKind pasta_val);

enum class QualTypePrimitiveDefaultInitializeKind : unsigned short {
  TRIVIAL,
  ARC_STRONG,
  ARC_WEAK,
  STRUCT,
  NUM_ENUMERATORS
};

QualTypePrimitiveDefaultInitializeKind FromPasta(pasta::QualTypePrimitiveDefaultInitializeKind pasta_val);

enum class RecordDeclArgPassingKind : unsigned short {
  CAN_PASS_IN_REGS,
  CANNOT_PASS_IN_REGS,
  CAN_NEVER_PASS_IN_REGS,
  NUM_ENUMERATORS
};

RecordDeclArgPassingKind FromPasta(pasta::RecordDeclArgPassingKind pasta_val);

enum class SourceLocExprIdentKind : unsigned short {
  FUNCTION,
  FILE,
  LINE,
  COLUMN,
  NUM_ENUMERATORS
};

SourceLocExprIdentKind FromPasta(pasta::SourceLocExprIdentKind pasta_val);

enum class StmtLikelihood : unsigned short {
  UNLIKELY,
  NONE,
  LIKELY,
  NUM_ENUMERATORS
};

StmtLikelihood FromPasta(pasta::StmtLikelihood pasta_val);

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

enum class StringLiteralStringKind : unsigned short {
  ASCII,
  WIDE,
  UT_F8,
  UT_F16,
  UT_F32,
  NUM_ENUMERATORS
};

StringLiteralStringKind FromPasta(pasta::StringLiteralStringKind pasta_val);

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

enum class UnaryTransformTypeUTTKind : unsigned short {
  ENUM_UNDERLYING_TYPE,
  NUM_ENUMERATORS
};

UnaryTransformTypeUTTKind FromPasta(pasta::UnaryTransformTypeUTTKind pasta_val);

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

enum class VarDeclDefinitionKind : unsigned short {
  DECLARATION_ONLY,
  TENTATIVE_DEFINITION,
  DEFINITION,
  NUM_ENUMERATORS
};

VarDeclDefinitionKind FromPasta(pasta::VarDeclDefinitionKind pasta_val);

enum class VarDeclInitializationStyle : unsigned short {
  C_INIT,
  CALL_INITIALIZER,
  LIST_INITIALIZER,
  NUM_ENUMERATORS
};

VarDeclInitializationStyle FromPasta(pasta::VarDeclInitializationStyle pasta_val);

enum class VarDeclTLSKind : unsigned short {
  NONE,
  STATIC,
  DYNAMIC,
  NUM_ENUMERATORS
};

VarDeclTLSKind FromPasta(pasta::VarDeclTLSKind pasta_val);

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

enum class ASTDumpOutputFormat : unsigned short {
  DEFAULT,
  JSON,
  NUM_ENUMERATORS
};

ASTDumpOutputFormat FromPasta(pasta::ASTDumpOutputFormat pasta_val);

enum class AccessSpecifier : unsigned short {
  PUBLIC,
  PROTECTED,
  PRIVATE,
  NONE,
  NUM_ENUMERATORS
};

AccessSpecifier FromPasta(pasta::AccessSpecifier pasta_val);

enum class AddrSpaceMapMangling : unsigned short {
  TARGET,
  ON,
  OFF,
  NUM_ENUMERATORS
};

AddrSpaceMapMangling FromPasta(pasta::AddrSpaceMapMangling pasta_val);

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

enum class AltivecSrcCompatKind : unsigned short {
  MIXED,
  GCC,
  XL,
  // Skipped repeat pasta::kDefault
  NUM_ENUMERATORS
};

AltivecSrcCompatKind FromPasta(pasta::AltivecSrcCompatKind pasta_val);

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

enum class ArrayTypeTrait : unsigned short {
  ARRAY_RANK,
  ARRAY_EXTENT,
  NUM_ENUMERATORS
};

ArrayTypeTrait FromPasta(pasta::ArrayTypeTrait pasta_val);

enum class AtomicScopeModelKind : unsigned short {
  NONE,
  OPEN_CL,
  NUM_ENUMERATORS
};

AtomicScopeModelKind FromPasta(pasta::AtomicScopeModelKind pasta_val);

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
  CX_X11_NO_RETURN,
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
  MS_P430_INTERRUPT,
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
  PARAM_TYPESTATE,
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

enum class AutoTypeKeyword : unsigned short {
  AUTO,
  DECLTYPE_AUTO,
  GNU_AUTO_TYPE,
  NUM_ENUMERATORS
};

AutoTypeKeyword FromPasta(pasta::AutoTypeKeyword pasta_val);

enum class AvailabilityResult : unsigned short {
  AVAILABLE,
  NOT_YET_INTRODUCED,
  DEPRECATED,
  UNAVAILABLE,
  NUM_ENUMERATORS
};

AvailabilityResult FromPasta(pasta::AvailabilityResult pasta_val);

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

enum class BlockType : unsigned short {
  BY_REFERENCE,
  NUM_ENUMERATORS
};

BlockType FromPasta(pasta::BlockType pasta_val);

enum class BranchStateTy : unsigned short {
  UNDEFINED,
  INBRANCH,
  NOTINBRANCH,
  NUM_ENUMERATORS
};

BranchStateTy FromPasta(pasta::BranchStateTy pasta_val);

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

enum class CanThrowResult : unsigned short {
  CANNOT,
  DEPENDENT,
  CAN,
  NUM_ENUMERATORS
};

CanThrowResult FromPasta(pasta::CanThrowResult pasta_val);

enum class CapturedRegionKind : unsigned short {
  DEFAULT,
  OBJ_C_AT_FINALLY,
  OPEN_MP,
  NUM_ENUMERATORS
};

CapturedRegionKind FromPasta(pasta::CapturedRegionKind pasta_val);

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

enum class ComparisonCategoryResult : unsigned short {
  EQUAL,
  EQUIVALENT,
  LESS,
  GREATER,
  UNORDERED,
  NUM_ENUMERATORS
};

ComparisonCategoryResult FromPasta(pasta::ComparisonCategoryResult pasta_val);

enum class ComparisonCategoryType : unsigned short {
  PARTIAL_ORDERING,
  WEAK_ORDERING,
  STRONG_ORDERING,
  NUM_ENUMERATORS
};

ComparisonCategoryType FromPasta(pasta::ComparisonCategoryType pasta_val);

enum class CompilingModuleKind : unsigned short {
  NONE,
  MODULE_MAP,
  HEADER_MODULE,
  MODULE_INTERFACE,
  NUM_ENUMERATORS
};

CompilingModuleKind FromPasta(pasta::CompilingModuleKind pasta_val);

enum class ConstexprSpecKind : unsigned short {
  UNSPECIFIED,
  CONSTEXPR,
  CONSTEVAL,
  CONSTINIT,
  NUM_ENUMERATORS
};

ConstexprSpecKind FromPasta(pasta::ConstexprSpecKind pasta_val);

enum class ConsumedState : unsigned short {
  UNKNOWN,
  CONSUMED,
  UNCONSUMED,
  NUM_ENUMERATORS
};

ConsumedState FromPasta(pasta::ConsumedState pasta_val);

enum class ConventionKind : unsigned short {
  NONE,
  NON_NULL_ERROR,
  ZERO_ARGUMENT,
  NON_ZERO_ARGUMENT,
  NUM_ENUMERATORS
};

ConventionKind FromPasta(pasta::ConventionKind pasta_val);

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

enum class DefaultArgKind : unsigned short {
  NONE,
  UNPARSED,
  UNINSTANTIATED,
  NORMAL,
  NUM_ENUMERATORS
};

DefaultArgKind FromPasta(pasta::DefaultArgKind pasta_val);

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

enum class DevTypeTy : unsigned short {
  HOST,
  NO_HOST,
  ANY,
  NUM_ENUMERATORS
};

DevTypeTy FromPasta(pasta::DevTypeTy pasta_val);

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

enum class DiagnosticType : unsigned short {
  ERROR,
  WARNING,
  NUM_ENUMERATORS
};

DiagnosticType FromPasta(pasta::DiagnosticType pasta_val);

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

enum class EmbedBitcodeKind : unsigned short {
  EMBED_OFF,
  EMBED_ALL,
  EMBED_BITCODE,
  EMBED_MARKER,
  NUM_ENUMERATORS
};

EmbedBitcodeKind FromPasta(pasta::EmbedBitcodeKind pasta_val);

enum class ExceptionHandlingKind : unsigned short {
  NONE,
  SJ_LJ,
  WIN_EH,
  DWARF_CFI,
  WASM,
  NUM_ENUMERATORS
};

ExceptionHandlingKind FromPasta(pasta::ExceptionHandlingKind pasta_val);

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

enum class ExplicitSpecKind : unsigned short {
  RESOLVED_FALSE,
  RESOLVED_TRUE,
  UNRESOLVED,
  NUM_ENUMERATORS
};

ExplicitSpecKind FromPasta(pasta::ExplicitSpecKind pasta_val);

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

enum class ExprOffsets : unsigned short {
  ALLOCATOR,
  ALLOCATOR_TRAITS,
  TOTAL,
  NUM_ENUMERATORS
};

ExprOffsets FromPasta(pasta::ExprOffsets pasta_val);

enum class ExprValueKind : unsigned short {
  PR_VALUE,
  L_VALUE,
  X_VALUE,
  NUM_ENUMERATORS
};

ExprValueKind FromPasta(pasta::ExprValueKind pasta_val);

enum class ExpressionTrait : unsigned short {
  IS_L_VALUE_EXPRESSION,
  IS_R_VALUE_EXPRESSION,
  NUM_ENUMERATORS
};

ExpressionTrait FromPasta(pasta::ExpressionTrait pasta_val);

enum class ExtKind : unsigned short {
  ALWAYS,
  NEVER,
  REPLY_HAZY,
  NUM_ENUMERATORS
};

ExtKind FromPasta(pasta::ExtKind pasta_val);

enum class ExtendArgsKind : unsigned short {
  EXTEND_TO32,
  EXTEND_TO64,
  NUM_ENUMERATORS
};

ExtendArgsKind FromPasta(pasta::ExtendArgsKind pasta_val);

enum class FPExceptionModeKind : unsigned short {
  IGNORE,
  MAY_TRAP,
  STRICT,
  NUM_ENUMERATORS
};

FPExceptionModeKind FromPasta(pasta::FPExceptionModeKind pasta_val);

enum class FPModeKind : unsigned short {
  OFF,
  ON,
  FAST,
  FAST_HONOR_PRAGMAS,
  NUM_ENUMERATORS
};

FPModeKind FromPasta(pasta::FPModeKind pasta_val);

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

enum class FiniteLoopsKind : unsigned short {
  LANGUAGE,
  ALWAYS,
  NEVER,
  NUM_ENUMERATORS
};

FiniteLoopsKind FromPasta(pasta::FiniteLoopsKind pasta_val);

enum class FramePointerKind : unsigned short {
  NONE,
  NON_LEAF,
  ALL,
  NUM_ENUMERATORS
};

FramePointerKind FromPasta(pasta::FramePointerKind pasta_val);

enum class GC : unsigned short {
  GC_NONE,
  WEAK,
  STRONG,
  NUM_ENUMERATORS
};

GC FromPasta(pasta::GC pasta_val);

enum class GCMode : unsigned short {
  NON_GC,
  GC_ONLY,
  HYBRID_GC,
  NUM_ENUMERATORS
};

GCMode FromPasta(pasta::GCMode pasta_val);

enum class GVALinkage : unsigned short {
  INTERNAL,
  AVAILABLE_EXTERNALLY,
  DISCARDABLE_ODR,
  STRONG_EXTERNAL,
  STRONG_ODR,
  NUM_ENUMERATORS
};

GVALinkage FromPasta(pasta::GVALinkage pasta_val);

enum class GetBuiltinTypeError : unsigned short {
  NONE,
  MISSING_TYPE,
  MISSING_STDIO,
  MISSING,
  MISSING_UCONTEXT,
  NUM_ENUMERATORS
};

GetBuiltinTypeError FromPasta(pasta::GetBuiltinTypeError pasta_val);

enum class GuardArg : unsigned short {
  NOCF,
  NUM_ENUMERATORS
};

GuardArg FromPasta(pasta::GuardArg pasta_val);

enum class ID : unsigned short {
  WORK_GROUP,
  DEVICE,
  ALL_SVM_DEVICES,
  SUB_GROUP,
  NUM_ENUMERATORS
};

ID FromPasta(pasta::ID pasta_val);

enum class IdentifierInfoFlag : unsigned short {
  ZERO_ARGUMENT,
  ONE_ARGUMENT,
  MULTI_ARGUMENT,
  // Skipped repeat pasta::kArgumentFlags
  NUM_ENUMERATORS
};

IdentifierInfoFlag FromPasta(pasta::IdentifierInfoFlag pasta_val);

enum class ImbueAttribute : unsigned short {
  NONE,
  ALWAYS,
  NEVER,
  ALWAYSAR_G1,
  NUM_ENUMERATORS
};

ImbueAttribute FromPasta(pasta::ImbueAttribute pasta_val);

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

enum class InClassInitStyle : unsigned short {
  NO_INITIALIZER,
  COPY_INITIALIZER,
  LIST_INITIALIZER,
  NUM_ENUMERATORS
};

InClassInitStyle FromPasta(pasta::InClassInitStyle pasta_val);

enum class InheritedDesignatedInitializersState : unsigned short {
  UNKNOWN,
  INHERITED,
  NOT_INHERITED,
  NUM_ENUMERATORS
};

InheritedDesignatedInitializersState FromPasta(pasta::InheritedDesignatedInitializersState pasta_val);

enum class InitStorageKind : unsigned short {
  NO_INITIALIZER,
  IN_CLASS_COPY_INITIALIZER,
  IN_CLASS_LIST_INITIALIZER,
  CAPTURED_VLA_TYPE,
  NUM_ENUMERATORS
};

InitStorageKind FromPasta(pasta::InitStorageKind pasta_val);

enum class InlineVariableDefinitionKind : unsigned short {
  NONE,
  WEAK,
  WEAK_UNKNOWN,
  STRONG,
  NUM_ENUMERATORS
};

InlineVariableDefinitionKind FromPasta(pasta::InlineVariableDefinitionKind pasta_val);

enum class InliningMethod : unsigned short {
  NORMAL_INLINING,
  ONLY_HINT_INLINING,
  ONLY_ALWAYS_INLINING,
  NUM_ENUMERATORS
};

InliningMethod FromPasta(pasta::InliningMethod pasta_val);

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

enum class LambdaCaptureDefault : unsigned short {
  NONE,
  BY_COPY,
  BY_REFERENCE,
  NUM_ENUMERATORS
};

LambdaCaptureDefault FromPasta(pasta::LambdaCaptureDefault pasta_val);

enum class LambdaCaptureKind : unsigned short {
  THIS,
  STAR_THIS,
  BY_COPY,
  BY_REFERENCE,
  VLA_TYPE,
  NUM_ENUMERATORS
};

LambdaCaptureKind FromPasta(pasta::LambdaCaptureKind pasta_val);

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

enum class LanguageLinkage : unsigned short {
  C_LANGUAGE_LINKAGE,
  CXX_LANGUAGE_LINKAGE,
  NO_LANGUAGE_LINKAGE,
  NUM_ENUMERATORS
};

LanguageLinkage FromPasta(pasta::LanguageLinkage pasta_val);

enum class LaxVectorConversionKind : unsigned short {
  NONE,
  INTEGER,
  ALL,
  NUM_ENUMERATORS
};

LaxVectorConversionKind FromPasta(pasta::LaxVectorConversionKind pasta_val);

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

enum class MSInheritanceModel : unsigned short {
  SINGLE,
  MULTIPLE,
  VIRTUAL,
  UNSPECIFIED,
  NUM_ENUMERATORS
};

MSInheritanceModel FromPasta(pasta::MSInheritanceModel pasta_val);

enum class MSVCMajorVersion : unsigned short {
  MSV_C2010,
  MSV_C2012,
  MSV_C2013,
  MSV_C2015,
  MSV_C2017,
  MSV_C20175,
  MSV_C20177,
  MSV_C2019,
  MSV_C20198,
  NUM_ENUMERATORS
};

MSVCMajorVersion FromPasta(pasta::MSVCMajorVersion pasta_val);

enum class MSVtorDispMode : unsigned short {
  NEVER,
  FOR_VIRTUAL_BASE_OVERRIDE,
  FOR_VF_TABLE,
  NUM_ENUMERATORS
};

MSVtorDispMode FromPasta(pasta::MSVtorDispMode pasta_val);

enum class MapTypeTy : unsigned short {
  TO,
  LINK,
  NUM_ENUMERATORS
};

MapTypeTy FromPasta(pasta::MapTypeTy pasta_val);

enum class MethodRefFlags : unsigned short {
  METHOD_REFERENCE_NONE,
  METHOD_REFERENCE_GETTER,
  METHOD_REFERENCE_SETTER,
  NUM_ENUMERATORS
};

MethodRefFlags FromPasta(pasta::MethodRefFlags pasta_val);

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

enum class MultiVersionKind : unsigned short {
  NONE,
  TARGET,
  CPU_SPECIFIC,
  CPU_DISPATCH,
  NUM_ENUMERATORS
};

MultiVersionKind FromPasta(pasta::MultiVersionKind pasta_val);

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

enum class NeedExtraManglingDecl : unsigned short {
  NEED_EXTRA_MANGLING_DECLARATION,
  NUM_ENUMERATORS
};

NeedExtraManglingDecl FromPasta(pasta::NeedExtraManglingDecl pasta_val);

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

enum class NewtypeKind : unsigned short {
  STRUCT,
  ENUM,
  NUM_ENUMERATORS
};

NewtypeKind FromPasta(pasta::NewtypeKind pasta_val);

enum class NonOdrUseReason : unsigned short {
  NONE,
  UNEVALUATED,
  CONSTANT,
  DISCARDED,
  NUM_ENUMERATORS
};

NonOdrUseReason FromPasta(pasta::NonOdrUseReason pasta_val);

enum class NonceObjCInterface : unsigned short {
  OBJ_C_INTERFACE,
  NUM_ENUMERATORS
};

NonceObjCInterface FromPasta(pasta::NonceObjCInterface pasta_val);

enum class NullabilityKind : unsigned short {
  NON_NULL,
  NULLABLE,
  UNSPECIFIED,
  NULLABLE_RESULT,
  NUM_ENUMERATORS
};

NullabilityKind FromPasta(pasta::NullabilityKind pasta_val);

enum class ObjCBridgeCastKind : unsigned short {
  BRIDGE,
  BRIDGE_TRANSFER,
  BRIDGE_RETAINED,
  NUM_ENUMERATORS
};

ObjCBridgeCastKind FromPasta(pasta::ObjCBridgeCastKind pasta_val);

enum class ObjCDispatchMethodKind : unsigned short {
  LEGACY,
  NON_LEGACY,
  MIXED,
  NUM_ENUMERATORS
};

ObjCDispatchMethodKind FromPasta(pasta::ObjCDispatchMethodKind pasta_val);

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

enum class ObjCLifetime : unsigned short {
  NONE,
  EXPLICIT_NONE,
  STRONG,
  WEAK,
  AUTORELEASING,
  NUM_ENUMERATORS
};

ObjCLifetime FromPasta(pasta::ObjCLifetime pasta_val);

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

enum class ObjCPropertyQueryKind : unsigned short {
  QUERY_UNKNOWN,
  QUERY_INSTANCE,
  QUERY_CLASS,
  NUM_ENUMERATORS
};

ObjCPropertyQueryKind FromPasta(pasta::ObjCPropertyQueryKind pasta_val);

enum class ObjCStringFormatFamily : unsigned short {
  NONE,
  NS_STRING,
  CF_STRING,
  NUM_ENUMERATORS
};

ObjCStringFormatFamily FromPasta(pasta::ObjCStringFormatFamily pasta_val);

enum class ObjCSubstitutionContext : unsigned short {
  ORDINARY,
  RESULT,
  PARAMETER,
  PROPERTY,
  SUPERCLASS,
  NUM_ENUMERATORS
};

ObjCSubstitutionContext FromPasta(pasta::ObjCSubstitutionContext pasta_val);

enum class ObjCTypeParamVariance : unsigned short {
  INVARIANT,
  COVARIANT,
  CONTRAVARIANT,
  NUM_ENUMERATORS
};

ObjCTypeParamVariance FromPasta(pasta::ObjCTypeParamVariance pasta_val);

enum class OnOffSwitch : unsigned short {
  ON,
  OFF,
  DEFAULT,
  NUM_ENUMERATORS
};

OnOffSwitch FromPasta(pasta::OnOffSwitch pasta_val);

enum class OnStackType : unsigned short {
  ON_STACK,
  NUM_ENUMERATORS
};

OnStackType FromPasta(pasta::OnStackType pasta_val);

enum class OpenMPAtomicDefaultMemOrderClauseKind : unsigned short {
  SEQ_CST,
  ACQ_REL,
  RELAXED,
  UNKNOWN,
  NUM_ENUMERATORS
};

OpenMPAtomicDefaultMemOrderClauseKind FromPasta(pasta::OpenMPAtomicDefaultMemOrderClauseKind pasta_val);

enum class OpenMPDefaultmapClauseKind : unsigned short {
  SCALAR,
  AGGREGATE,
  POINTER,
  UNKNOWN,
  NUM_ENUMERATORS
};

OpenMPDefaultmapClauseKind FromPasta(pasta::OpenMPDefaultmapClauseKind pasta_val);

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

enum class OpenMPDeviceClauseModifier : unsigned short {
  ANCESTOR,
  DEVICE_NUM,
  UNKNOWN,
  NUM_ENUMERATORS
};

OpenMPDeviceClauseModifier FromPasta(pasta::OpenMPDeviceClauseModifier pasta_val);

enum class OpenMPDeviceType : unsigned short {
  HOST,
  NOHOST,
  ANY,
  UNKNOWN,
  NUM_ENUMERATORS
};

OpenMPDeviceType FromPasta(pasta::OpenMPDeviceType pasta_val);

enum class OpenMPDistScheduleClauseKind : unsigned short {
  STATIC,
  UNKNOWN,
  NUM_ENUMERATORS
};

OpenMPDistScheduleClauseKind FromPasta(pasta::OpenMPDistScheduleClauseKind pasta_val);

enum class OpenMPLastprivateModifier : unsigned short {
  CONDITIONAL,
  UNKNOWN,
  NUM_ENUMERATORS
};

OpenMPLastprivateModifier FromPasta(pasta::OpenMPLastprivateModifier pasta_val);

enum class OpenMPLinearClauseKind : unsigned short {
  VAL,
  REFERENCE,
  UVAL,
  UNKNOWN,
  NUM_ENUMERATORS
};

OpenMPLinearClauseKind FromPasta(pasta::OpenMPLinearClauseKind pasta_val);

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

enum class OpenMPMapModifierKind : unsigned short {
  UNKNOWN,
  ALWAYS,
  CLOSE,
  MAPPER,
  PRESENT,
  NUM_ENUMERATORS
};

OpenMPMapModifierKind FromPasta(pasta::OpenMPMapModifierKind pasta_val);

enum class OpenMPMotionModifierKind : unsigned short {
  MOTIONMODIFIER_MAPPER,
  MOTIONMODIFIER_PRESENT,
  MOTIONMODIFIER_UNKNOWN,
  NUM_ENUMERATORS
};

OpenMPMotionModifierKind FromPasta(pasta::OpenMPMotionModifierKind pasta_val);

enum class OpenMPOrderClauseKind : unsigned short {
  CONCURRENT,
  UNKNOWN,
  NUM_ENUMERATORS
};

OpenMPOrderClauseKind FromPasta(pasta::OpenMPOrderClauseKind pasta_val);

enum class OpenMPReductionClauseModifier : unsigned short {
  DEFAULT,
  INSCAN,
  TASK,
  UNKNOWN,
  NUM_ENUMERATORS
};

OpenMPReductionClauseModifier FromPasta(pasta::OpenMPReductionClauseModifier pasta_val);

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

enum class OpenMPScheduleClauseModifier : unsigned short {
  UNKNOWN,
  MONOTONIC,
  NONMONOTONIC,
  SIMD,
  NUM_ENUMERATORS
};

OpenMPScheduleClauseModifier FromPasta(pasta::OpenMPScheduleClauseModifier pasta_val);

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

enum class OverloadsShown : unsigned short {
  ALL,
  BEST,
  NUM_ENUMERATORS
};

OverloadsShown FromPasta(pasta::OverloadsShown pasta_val);

enum class OwnershipKind : unsigned short {
  HOLDS,
  RETURNS,
  TAKES,
  NUM_ENUMERATORS
};

OwnershipKind FromPasta(pasta::OwnershipKind pasta_val);

enum class PCSType : unsigned short {
  AAPCS,
  VFP,
  NUM_ENUMERATORS
};

PCSType FromPasta(pasta::PCSType pasta_val);

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

enum class ParameterABI : unsigned short {
  ORDINARY,
  SWIFT_INDIRECT_RESULT,
  SWIFT_ERROR_RESULT,
  SWIFT_CONTEXT,
  SWIFT_ASYNC_CONTEXT,
  NUM_ENUMERATORS
};

ParameterABI FromPasta(pasta::ParameterABI pasta_val);

enum class ParenLocsOffsets : unsigned short {
  L_PAREN,
  R_PAREN,
  TOTAL,
  NUM_ENUMERATORS
};

ParenLocsOffsets FromPasta(pasta::ParenLocsOffsets pasta_val);

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

enum class PragmaMSPointersToMembersKind : unsigned short {
  BEST_CASE,
  FULL_GENERALITY_SINGLE_INHERITANCE,
  FULL_GENERALITY_MULTIPLE_INHERITANCE,
  FULL_GENERALITY_VIRTUAL_INHERITANCE,
  NUM_ENUMERATORS
};

PragmaMSPointersToMembersKind FromPasta(pasta::PragmaMSPointersToMembersKind pasta_val);

enum class PragmaMSStructKind : unsigned short {
  OFF,
  ON,
  NUM_ENUMERATORS
};

PragmaMSStructKind FromPasta(pasta::PragmaMSStructKind pasta_val);

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

enum class ProfileInstrKind : unsigned short {
  PROFILE_NONE,
  PROFILE_CLANG_INSTR,
  PROFILE_IR_INSTR,
  PROFILE_CSIR_INSTR,
  NUM_ENUMERATORS
};

ProfileInstrKind FromPasta(pasta::ProfileInstrKind pasta_val);

enum class RangeExprOffset : unsigned short {
  BEGIN,
  END,
  STEP,
  TOTAL,
  NUM_ENUMERATORS
};

RangeExprOffset FromPasta(pasta::RangeExprOffset pasta_val);

enum class RangeLocOffset : unsigned short {
  ASSIGN_TOKEN,
  SECOND_COLON_TOKEN,
  TOTAL,
  NUM_ENUMERATORS
};

RangeLocOffset FromPasta(pasta::RangeLocOffset pasta_val);

enum class RefQualifierKind : unsigned short {
  NONE,
  L_VALUE,
  R_VALUE,
  NUM_ENUMERATORS
};

RefQualifierKind FromPasta(pasta::RefQualifierKind pasta_val);

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

enum class ReservedIdentifierStatus : unsigned short {
  NOT_RESERVED,
  STARTS_WITH_UNDERSCORE_AT_GLOBAL_SCOPE,
  STARTS_WITH_DOUBLE_UNDERSCORE,
  STARTS_WITH_UNDERSCORE_FOLLOWED_BY_CAPITAL_LETTER,
  CONTAINS_DOUBLE_UNDERSCORE,
  NUM_ENUMERATORS
};

ReservedIdentifierStatus FromPasta(pasta::ReservedIdentifierStatus pasta_val);

enum class SFINAEResponse : unsigned short {
  SUBSTITUTION_FAILURE,
  SUPPRESS,
  REPORT,
  ACCESS_CONTROL,
  NUM_ENUMERATORS
};

SFINAEResponse FromPasta(pasta::SFINAEResponse pasta_val);

enum class SYCLMajorVersion : unsigned short {
  VERSION_NONE,
  VERSION2017,
  VERSION2020,
  // Skipped repeat pasta::kDefault
  NUM_ENUMERATORS
};

SYCLMajorVersion FromPasta(pasta::SYCLMajorVersion pasta_val);

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

enum class SelectorLocationsKind : unsigned short {
  NON_STANDARD,
  STANDARD_NO_SPACE,
  STANDARD_WITH_SPACE,
  NUM_ENUMERATORS
};

SelectorLocationsKind FromPasta(pasta::SelectorLocationsKind pasta_val);

enum class SignReturnAddressKeyKind : unsigned short {
  A_KEY,
  B_KEY,
  NUM_ENUMERATORS
};

SignReturnAddressKeyKind FromPasta(pasta::SignReturnAddressKeyKind pasta_val);

enum class SignReturnAddressScopeKind : unsigned short {
  NONE,
  NON_LEAF,
  ALL,
  NUM_ENUMERATORS
};

SignReturnAddressScopeKind FromPasta(pasta::SignReturnAddressScopeKind pasta_val);

enum class SignedOverflowBehaviorTy : unsigned short {
  UNDEFINED,
  DEFINED,
  TRAPPING,
  NUM_ENUMERATORS
};

SignedOverflowBehaviorTy FromPasta(pasta::SignedOverflowBehaviorTy pasta_val);

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

enum class Spelling : unsigned short {
  GNU_AARCH64_VECTOR_PCS,
  CX_X11_CLANG_AARCH64_VECTOR_PCS,
  C2_XCLANG_AARCH64_VECTOR_PCS,
  SPELLING_NOT_CALCULATED,
  NUM_ENUMERATORS
};

Spelling FromPasta(pasta::Spelling pasta_val);

enum class StackProtectorMode : unsigned short {
  OFF,
  ON,
  STRONG,
  REQ,
  NUM_ENUMERATORS
};

StackProtectorMode FromPasta(pasta::StackProtectorMode pasta_val);

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

enum class StorageDuration : unsigned short {
  FULL_EXPRESSION,
  AUTOMATIC,
  THREAD,
  STATIC,
  DYNAMIC,
  NUM_ENUMERATORS
};

StorageDuration FromPasta(pasta::StorageDuration pasta_val);

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

enum class StoredSpecifierKind : unsigned short {
  STORED_IDENTIFIER,
  STORED_DECLARATION,
  STORED_TYPE_SPEC,
  STORED_TYPE_SPEC_WITH_TEMPLATE,
  NUM_ENUMERATORS
};

StoredSpecifierKind FromPasta(pasta::StoredSpecifierKind pasta_val);

enum class StructReturnConventionKind : unsigned short {
  DEFAULT,
  ON_STACK,
  IN_REGS,
  NUM_ENUMERATORS
};

StructReturnConventionKind FromPasta(pasta::StructReturnConventionKind pasta_val);

enum class SubExpr : unsigned short {
  CALLEE,
  LHS,
  RHS,
  COUNT,
  NUM_ENUMERATORS
};

SubExpr FromPasta(pasta::SubExpr pasta_val);

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

enum class SyncScope : unsigned short {
  OPEN_CL_WORK_GROUP,
  OPEN_CL_DEVICE,
  OPEN_CL_ALL_SVM_DEVICES,
  OPEN_CL_SUB_GROUP,
  NUM_ENUMERATORS
};

SyncScope FromPasta(pasta::SyncScope pasta_val);

enum class Syntax : unsigned short {
  GNU,
  CX_X11,
  C2_X,
  DECLSPEC,
  MICROSOFT,
  KEYWORD,
  PRAGMA,
  CONTEXT_SENSITIVE_KEYWORD,
  NUM_ENUMERATORS
};

Syntax FromPasta(pasta::Syntax pasta_val);

enum class TLSModel : unsigned short {
  GENERAL_DYNAMIC_TLS_MODEL,
  LOCAL_DYNAMIC_TLS_MODEL,
  INITIAL_EXEC_TLS_MODEL,
  LOCAL_EXEC_TLS_MODEL,
  NUM_ENUMERATORS
};

TLSModel FromPasta(pasta::TLSModel pasta_val);

enum class TQ : unsigned short {
  CONST,
  RESTRICT,
  VOLATILE,
  CVR_MASK,
  NUM_ENUMERATORS
};

TQ FromPasta(pasta::TQ pasta_val);

enum class TagTypeKind : unsigned short {
  STRUCT,
  INTERFACE,
  UNION,
  CLASS,
  ENUM,
  NUM_ENUMERATORS
};

TagTypeKind FromPasta(pasta::TagTypeKind pasta_val);

enum class TailPaddingUseRules : unsigned short {
  ALWAYS_USE_TAIL_PADDING,
  USE_TAIL_PADDING_UNLESS_PO_D03,
  USE_TAIL_PADDING_UNLESS_PO_D11,
  NUM_ENUMERATORS
};

TailPaddingUseRules FromPasta(pasta::TailPaddingUseRules pasta_val);

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

enum class TemplateSpecializationKind : unsigned short {
  UNDECLARED,
  IMPLICIT_INSTANTIATION,
  EXPLICIT_SPECIALIZATION,
  EXPLICIT_INSTANTIATION_DECLARATION,
  EXPLICIT_INSTANTIATION_DEFINITION,
  NUM_ENUMERATORS
};

TemplateSpecializationKind FromPasta(pasta::TemplateSpecializationKind pasta_val);

enum class TextDiagnosticFormat : unsigned short {
  CLANG,
  MSVC,
  VI,
  NUM_ENUMERATORS
};

TextDiagnosticFormat FromPasta(pasta::TextDiagnosticFormat pasta_val);

enum class ThreadModelKind : unsigned short {
  POSIX,
  SINGLE,
  NUM_ENUMERATORS
};

ThreadModelKind FromPasta(pasta::ThreadModelKind pasta_val);

enum class ThreadStorageClassSpecifier : unsigned short {
  UNSPECIFIED,
  __THREAD,
  THREAD_LOCAL,
  _THREAD_LOCAL,
  NUM_ENUMERATORS
};

ThreadStorageClassSpecifier FromPasta(pasta::ThreadStorageClassSpecifier pasta_val);

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
  NUM_ENUMERATORS
};

TokenKind FromPasta(pasta::TokenKind pasta_val);

enum class TrailingAllocKind : unsigned short {
  TAK_INHERITS_CONSTRUCTOR,
  TAK_HAS_TAIL_EXPLICIT,
  NUM_ENUMERATORS
};

TrailingAllocKind FromPasta(pasta::TrailingAllocKind pasta_val);

enum class TranslationUnitKind : unsigned short {
  COMPLETE,
  PREFIX,
  MODULE,
  INCREMENTAL,
  NUM_ENUMERATORS
};

TranslationUnitKind FromPasta(pasta::TranslationUnitKind pasta_val);

enum class TrivialAutoVarInitKind : unsigned short {
  UNINITIALIZED,
  ZERO,
  PATTERN,
  NUM_ENUMERATORS
};

TrivialAutoVarInitKind FromPasta(pasta::TrivialAutoVarInitKind pasta_val);

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
  OBJ_C_TYPE_PARAM,
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

enum class TypeSpecifierSign : unsigned short {
  UNSPECIFIED,
  SIGNED,
  UNSIGNED,
  NUM_ENUMERATORS
};

TypeSpecifierSign FromPasta(pasta::TypeSpecifierSign pasta_val);

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

enum class TypeSpecifierWidth : unsigned short {
  UNSPECIFIED,
  SHORT,
  LONG,
  LONG_LONG,
  NUM_ENUMERATORS
};

TypeSpecifierWidth FromPasta(pasta::TypeSpecifierWidth pasta_val);

enum class TypeSpecifiersPipe : unsigned short {
  UNSPECIFIED,
  PIPE,
  NUM_ENUMERATORS
};

TypeSpecifiersPipe FromPasta(pasta::TypeSpecifiersPipe pasta_val);

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

enum class UnaryExprOrTypeTrait : unsigned short {
  SIZE_OF,
  ALIGN_OF,
  PREFERRED_ALIGN_OF,
  VEC_STEP,
  OPEN_MP_REQUIRED_SIMD_ALIGN,
  NUM_ENUMERATORS
};

UnaryExprOrTypeTrait FromPasta(pasta::UnaryExprOrTypeTrait pasta_val);

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

enum class Visibility : unsigned short {
  HIDDEN_VISIBILITY,
  PROTECTED_VISIBILITY,
  DEFAULT_VISIBILITY,
  NUM_ENUMERATORS
};

Visibility FromPasta(pasta::Visibility pasta_val);

enum class VisibilityType : unsigned short {
  DEFAULT,
  HIDDEN,
  PROTECTED,
  NUM_ENUMERATORS
};

VisibilityType FromPasta(pasta::VisibilityType pasta_val);

enum class PathKind : unsigned short {
  UNIX,
  WINDOWS,
  NUM_ENUMERATORS
};

PathKind FromPasta(pasta::PathKind pasta_val);

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

enum class IncludePathLocation : unsigned short {
  ABSOLUTE,
  SYSROOT_RELATIVE,
  NUM_ENUMERATORS
};

IncludePathLocation FromPasta(pasta::IncludePathLocation pasta_val);

enum class TargetLanguage : unsigned short {
  C,
  CXX,
  NUM_ENUMERATORS
};

TargetLanguage FromPasta(pasta::TargetLanguage pasta_val);

}  // namespace mx
