// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

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
enum class TokenContextKind : uint8_t;
enum class DeclKind : uint32_t;
enum class ArrayTypeArraySizeModifier : uint32_t;
enum class AtomicExprAtomicOp : uint32_t;
enum class BuiltinTypeKind : uint32_t;
enum class CXXConstructExprConstructionKind : uint32_t;
enum class CXXNewExprInitializationStyle : uint32_t;
enum class CallExprADLCallKind : bool;
enum class CapturedStmtVariableCaptureKind : uint32_t;
enum class CharacterLiteralCharacterKind : uint32_t;
enum class ConstantExprResultStorageKind : uint32_t;
enum class DeclFriendObjectKind : uint32_t;
enum class DeclIdentifierNamespace : uint32_t;
enum class DeclModuleOwnershipKind : uint32_t;
enum class DeclObjCDeclQualifier : uint32_t;
enum class ExprConstantExprKind : int32_t;
enum class ExprLValueClassification : uint32_t;
enum class ExprNullPointerConstantKind : uint32_t;
enum class ExprNullPointerConstantValueDependence : uint32_t;
enum class ExprSideEffectsKind : uint32_t;
enum class ExprisModifiableLvalueResult : uint32_t;
enum class FunctionDeclTemplatedKind : uint32_t;
enum class ImplicitCastExprOnStack_t : uint32_t;
enum class ImplicitParamDeclImplicitParamKind : uint32_t;
enum class LinkageSpecDeclLanguageIDs : uint32_t;
enum class NamedDeclExplicitVisibilityKind : uint32_t;
enum class OMPDeclareReductionDeclInitKind : uint32_t;
enum class ObjCIvarDeclAccessControl : uint32_t;
enum class ObjCMessageExprReceiverKind : uint32_t;
enum class ObjCMethodDeclImplementationControl : uint32_t;
enum class ObjCPropertyDeclPropertyControl : uint32_t;
enum class ObjCPropertyDeclSetterKind : uint32_t;
enum class ObjCPropertyImplDeclKind : uint32_t;
enum class PredefinedExprIdentKind : uint32_t;
enum class QualTypeDestructionKind : uint32_t;
enum class QualTypePrimitiveCopyKind : uint32_t;
enum class QualTypePrimitiveDefaultInitializeKind : uint32_t;
enum class RecordDeclArgPassingKind : uint32_t;
enum class SourceLocExprIdentKind : uint32_t;
enum class StmtLikelihood : int32_t;
enum class StmtStmtClass : uint32_t;
enum class StringLiteralStringKind : uint32_t;
enum class TemplateArgumentArgKind : uint32_t;
enum class TypeScalarTypeKind : uint32_t;
enum class TypeTypeClass : uint32_t;
enum class UnaryTransformTypeUTTKind : uint32_t;
enum class UserDefinedLiteralLiteralOperatorKind : uint32_t;
enum class VarDeclDefinitionKind : uint32_t;
enum class VarDeclInitializationStyle : uint32_t;
enum class VarDeclTLSKind : uint32_t;
enum class VectorTypeVectorKind : uint32_t;
enum class ADLCallKind : bool;
enum class ASTDumpOutputFormat : uint32_t;
enum class AccessControl : uint32_t;
enum class AccessSpecifier : uint32_t;
enum class AddrSpaceMapMangling : uint32_t;
enum class AllocatorTypeTy : uint32_t;
enum class AltivecSrcCompatKind : int32_t;
enum class ArgKind : uint32_t;
enum class ArgPassingKind : uint32_t;
enum class ArgumentKind : uint32_t;
enum class ArraySizeModifier : uint32_t;
enum class ArrayTypeTrait : uint32_t;
enum class AtomicOp : uint32_t;
enum class AtomicScopeModelKind : int32_t;
enum class AttributeKind : uint32_t;
enum class AutoTypeKeyword : int32_t;
enum class AvailabilityResult : uint32_t;
enum class BinaryOperatorKind : uint32_t;
enum class Bits : uint8_t;
enum class BlockType : uint32_t;
enum class BranchStateTy : uint32_t;
enum class CallingConv : uint32_t;
enum class CanThrowResult : uint32_t;
enum class CapturedRegionKind : uint32_t;
enum class CastKind : uint32_t;
enum class CharacterKind : uint32_t;
enum class ClangABI : int32_t;
enum class CommentKind : uint32_t;
enum class ComparisonCategoryResult : uint8_t;
enum class ComparisonCategoryType : uint8_t;
enum class CompilingModuleKind : uint32_t;
enum class ConstantExprKind : int32_t;
enum class ConstexprSpecKind : int32_t;
enum class ConstructionKind : uint32_t;
enum class ConsumedState : uint32_t;
enum class ConventionKind : uint32_t;
enum class CoreFoundationABI : int32_t;
enum class DefaultArgKind : uint32_t;
enum class DefaultCallingConvention : uint32_t;
enum class DefinitionKind : uint32_t;
enum class DestructionKind : uint32_t;
enum class DevTypeTy : uint32_t;
enum class DiagnosticLevelMask : uint32_t;
enum class DiagnosticType : uint32_t;
enum class ElaboratedTypeKeyword : uint32_t;
enum class EmbedBitcodeKind : uint32_t;
enum class ExceptionHandlingKind : int32_t;
enum class ExceptionSpecificationType : uint32_t;
enum class ExplicitSpecKind : uint32_t;
enum class ExplicitVisibilityKind : uint32_t;
enum class ExprDependence : uint8_t;
enum class ExprObjectKind : uint32_t;
enum class ExprOffsets : int32_t;
enum class ExprValueKind : uint32_t;
enum class ExpressionTrait : uint32_t;
enum class ExtKind : uint32_t;
enum class ExtendArgsKind : int32_t;
enum class FPExceptionModeKind : uint32_t;
enum class FPModeKind : uint32_t;
enum class FamilyKind : uint32_t;
enum class FiniteLoopsKind : uint32_t;
enum class FramePointerKind : int32_t;
enum class FriendObjectKind : uint32_t;
enum class GC : uint32_t;
enum class GCMode : uint32_t;
enum class GVALinkage : uint32_t;
enum class GetBuiltinTypeError : uint32_t;
enum class GuardArg : uint32_t;
enum class ID : uint32_t;
enum class IdentKind : uint32_t;
enum class IdentifierInfoFlag : uint32_t;
enum class IdentifierNamespace : uint32_t;
enum class ImbueAttribute : int32_t;
enum class ImplementationControl : uint32_t;
enum class ImplicitParamKind : uint32_t;
enum class ImplicitReason : uint32_t;
enum class InClassInitStyle : uint32_t;
enum class InheritedDesignatedInitializersState : uint32_t;
enum class InitKind : uint32_t;
enum class InitStorageKind : uint32_t;
enum class InitializationStyle : uint32_t;
enum class InlineVariableDefinitionKind : int32_t;
enum class InliningMethod : uint32_t;
enum class InterruptType : uint32_t;
enum class Kinds : uint32_t;
enum class LValueClassification : uint32_t;
enum class LambdaCaptureDefault : uint32_t;
enum class LambdaCaptureKind : uint32_t;
enum class LangAS : uint32_t;
enum class LangFeatures : uint32_t;
enum class Language : uint8_t;
enum class LanguageIDs : uint32_t;
enum class LanguageLinkage : uint32_t;
enum class LaxVectorConversionKind : int32_t;
enum class Level : uint32_t;
enum class Likelihood : int32_t;
enum class Linkage : uint8_t;
enum class LiteralOperatorKind : uint32_t;
enum class LoopHintState : uint32_t;
enum class MSInheritanceModel : int32_t;
enum class MSVCMajorVersion : uint32_t;
enum class MSVtorDispMode : int32_t;
enum class MapTypeTy : uint32_t;
enum class MethodRefFlags : uint32_t;
enum class ModifiableType : uint32_t;
enum class ModuleOwnershipKind : uint32_t;
enum class MultiVersionKind : int32_t;
enum class NameKind : uint32_t;
enum class NeedExtraManglingDecl_t : uint32_t;
enum class NestedNameSpecifierDependence : uint8_t;
enum class NewtypeKind : uint32_t;
enum class NonOdrUseReason : uint32_t;
enum class Nonce_ObjCInterface : uint32_t;
enum class NullPointerConstantKind : uint32_t;
enum class NullPointerConstantValueDependence : uint32_t;
enum class NullabilityKind : uint8_t;
enum class ObjCBridgeCastKind : uint32_t;
enum class ObjCDeclQualifier : uint32_t;
enum class ObjCDispatchMethodKind : uint32_t;
enum class ObjCInstanceTypeFamily : uint32_t;
enum class ObjCKeywordKind : uint32_t;
enum class ObjCLifetime : uint32_t;
enum class ObjCMethodFamily : uint32_t;
enum class ObjCPropertyQueryKind : uint8_t;
enum class ObjCStringFormatFamily : uint32_t;
enum class ObjCSubstitutionContext : int32_t;
enum class ObjCTypeParamVariance : uint8_t;
enum class OnOffSwitch : uint32_t;
enum class OnStackType : uint32_t;
enum class OpenMPAtomicDefaultMemOrderClauseKind : uint32_t;
enum class OpenMPDefaultmapClauseKind : uint32_t;
enum class OpenMPDefaultmapClauseModifier : uint32_t;
enum class OpenMPDependClauseKind : uint32_t;
enum class OpenMPDeviceClauseModifier : uint32_t;
enum class OpenMPDeviceType : uint32_t;
enum class OpenMPDistScheduleClauseKind : uint32_t;
enum class OpenMPLastprivateModifier : uint32_t;
enum class OpenMPLinearClauseKind : uint32_t;
enum class OpenMPMapClauseKind : uint32_t;
enum class OpenMPMapModifierKind : uint32_t;
enum class OpenMPMotionModifierKind : uint32_t;
enum class OpenMPOrderClauseKind : uint32_t;
enum class OpenMPReductionClauseModifier : uint32_t;
enum class OpenMPScheduleClauseKind : uint32_t;
enum class OpenMPScheduleClauseModifier : uint32_t;
enum class OptionType : uint32_t;
enum class OverloadedOperatorKind : int32_t;
enum class OverloadsShown : uint32_t;
enum class OwnershipKind : uint32_t;
enum class PCSType : uint32_t;
enum class PPKeywordKind : uint32_t;
enum class ParameterABI : int32_t;
enum class ParenLocsOffsets : int32_t;
enum class PragmaFloatControlKind : uint32_t;
enum class PragmaMSCommentKind : uint32_t;
enum class PragmaMSPointersToMembersKind : uint32_t;
enum class PragmaMSStructKind : uint32_t;
enum class PragmaSectionFlag : uint32_t;
enum class PrimitiveCopyKind : uint32_t;
enum class PrimitiveDefaultInitializeKind : uint32_t;
enum class ProfileInstrKind : uint32_t;
enum class PropertyControl : uint32_t;
enum class RangeExprOffset : int32_t;
enum class RangeLocOffset : int32_t;
enum class ReceiverKind : uint32_t;
enum class RefQualifierKind : uint32_t;
enum class RemarkKind : uint32_t;
enum class ReservedIdentifierStatus : int32_t;
enum class ResultStorageKind : uint32_t;
enum class SFINAEResponse : uint32_t;
enum class SYCLMajorVersion : uint32_t;
enum class SanitizerOrdinal : uint64_t;
enum class ScalarTypeKind : uint32_t;
enum class SelectorLocationsKind : uint32_t;
enum class SetterKind : uint32_t;
enum class SideEffectsKind : uint32_t;
enum class SignReturnAddressKeyKind : int32_t;
enum class SignReturnAddressScopeKind : int32_t;
enum class SignedOverflowBehaviorTy : uint32_t;
enum class SpecialMemberFlags : uint32_t;
enum class SpecifierKind : uint32_t;
enum class Spelling : uint32_t;
enum class StackProtectorMode : uint32_t;
enum class StmtKind : uint32_t;
enum class StorageClass : uint32_t;
enum class StorageDuration : uint32_t;
enum class StoredNameKind : uint32_t;
enum class StoredSpecifierKind : uint32_t;
enum class StringKind : uint32_t;
enum class StructReturnConventionKind : uint32_t;
enum class SubExpr : uint32_t;
enum class SubStmt : uint32_t;
enum class SyncScope : int32_t;
enum class Syntax : uint32_t;
enum class TLSKind : uint32_t;
enum class TLSModel : uint32_t;
enum class TQ : uint32_t;
enum class TagTypeKind : uint32_t;
enum class TailPaddingUseRules : uint32_t;
enum class TemplateArgumentDependence : uint8_t;
enum class TemplateNameDependence : uint8_t;
enum class TemplateSpecializationKind : uint32_t;
enum class TemplatedKind : uint32_t;
enum class TextDiagnosticFormat : uint32_t;
enum class ThreadModelKind : int32_t;
enum class ThreadStorageClassSpecifier : uint32_t;
enum class TokenKind : uint16_t;
enum class TrailingAllocKind : uint32_t;
enum class TranslationUnitKind : uint32_t;
enum class TrivialAutoVarInitKind : int32_t;
enum class TypeKind : uint32_t;
enum class TypeDependence : uint8_t;
enum class TypeLocClass : uint32_t;
enum class TypeSpecifierSign : int32_t;
enum class TypeSpecifierType : uint32_t;
enum class TypeSpecifierWidth : int32_t;
enum class TypeSpecifiersPipe : int32_t;
enum class TypeTrait : uint32_t;
enum class UTTKind : uint32_t;
enum class UnaryExprOrTypeTrait : uint32_t;
enum class UnaryOperatorKind : uint32_t;
enum class APValueKind : uint32_t;
enum class VariableCaptureKind : uint32_t;
enum class VectorKind : uint32_t;
enum class VectorLibrary : uint32_t;
enum class Visibility : uint32_t;
enum class VisibilityType : uint32_t;
enum class IsModifiableLvalueResult : uint32_t;
enum class PathKind : int8_t;
enum class CompilerName : uint32_t;
enum class IncludePathLocation : uint32_t;
enum class TargetLanguage : uint32_t;
}  // namespace pasta
namespace mx {
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
  KEYWORD_IMAGE1D_T,
  KEYWORD_IMAGE1D_ARRAY_T,
  KEYWORD_IMAGE1D_BUFFER_T,
  KEYWORD_IMAGE2D_T,
  KEYWORD_IMAGE2D_ARRAY_T,
  KEYWORD_IMAGE2D_DEPTH_T,
  KEYWORD_IMAGE2D_ARRAY_DEPTH_T,
  KEYWORD_IMAGE2D_MSAA_T,
  KEYWORD_IMAGE2D_ARRAY_MSAA_T,
  KEYWORD_IMAGE2D_MSAA_DEPTH_T,
  KEYWORD_IMAGE2D_ARRAY_MSAA_DEPTH_T,
  KEYWORD_IMAGE3D_T,
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

enum class TokenRole : unsigned short {
  INVALID,
  BEGIN_OF_FILE_MARKER,
  FILE_TOKEN,
  END_OF_FILE_MARKER,
  BEGIN_OF_MACRO_EXPANSION_MARKER,
  MACRO_EXPANSION_TOKEN,
  END_OF_MACRO_EXPANSION_MARKER,
  PRINTED_TOKEN,
  NUM_ENUMERATORS
};

TokenRole FromPasta(pasta::TokenRole pasta_val);

enum class AccessSpecifier : unsigned short {
  PUBLIC,
  PROTECTED,
  PRIVATE,
  NONE,
  NUM_ENUMERATORS
};

AccessSpecifier FromPasta(pasta::AccessSpecifier pasta_val);

enum class AvailabilityResult : unsigned short {
  AVAILABLE,
  NOT_YET_INTRODUCED,
  DEPRECATED,
  UNAVAILABLE,
  NUM_ENUMERATORS
};

AvailabilityResult FromPasta(pasta::AvailabilityResult pasta_val);

enum class FriendObjectKind : unsigned short {
  NONE,
  DECLARED,
  UNDECLARED,
  NUM_ENUMERATORS
};

FriendObjectKind FromPasta(pasta::FriendObjectKind pasta_val);

enum class ModuleOwnershipKind : unsigned short {
  UNOWNED,
  VISIBLE,
  VISIBLE_WHEN_IMPORTED,
  MODULE_PRIVATE,
  NUM_ENUMERATORS
};

ModuleOwnershipKind FromPasta(pasta::ModuleOwnershipKind pasta_val);

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

enum class ObjCStringFormatFamily : unsigned short {
  NONE,
  NS_STRING,
  CF_STRING,
  NUM_ENUMERATORS
};

ObjCStringFormatFamily FromPasta(pasta::ObjCStringFormatFamily pasta_val);

enum class Visibility : unsigned short {
  HIDDEN_VISIBILITY,
  PROTECTED_VISIBILITY,
  DEFAULT_VISIBILITY,
  NUM_ENUMERATORS
};

Visibility FromPasta(pasta::Visibility pasta_val);

enum class LanguageLinkage : unsigned short {
  C_LANGUAGE_LINKAGE,
  CXX_LANGUAGE_LINKAGE,
  NO_LANGUAGE_LINKAGE,
  NUM_ENUMERATORS
};

LanguageLinkage FromPasta(pasta::LanguageLinkage pasta_val);

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

enum class ThreadStorageClassSpecifier : unsigned short {
  UNSPECIFIED,
  __THREAD,
  THREAD_LOCAL,
  _THREAD_LOCAL,
  NUM_ENUMERATORS
};

ThreadStorageClassSpecifier FromPasta(pasta::ThreadStorageClassSpecifier pasta_val);

enum class TemplateSpecializationKind : unsigned short {
  UNDECLARED,
  IMPLICIT_INSTANTIATION,
  EXPLICIT_SPECIALIZATION,
  EXPLICIT_INSTANTIATION_DECLARATION,
  EXPLICIT_INSTANTIATION_DEFINITION,
  NUM_ENUMERATORS
};

TemplateSpecializationKind FromPasta(pasta::TemplateSpecializationKind pasta_val);

enum class ImplicitParamKind : unsigned short {
  OBJ_C_SELF,
  OBJ_C_CMD,
  CXX_THIS,
  CXXVTT,
  CAPTURED_CONTEXT,
  OTHER,
  NUM_ENUMERATORS
};

ImplicitParamKind FromPasta(pasta::ImplicitParamKind pasta_val);

enum class ConstexprSpecKind : unsigned short {
  UNSPECIFIED,
  CONSTEXPR,
  CONSTEVAL,
  CONSTINIT,
  NUM_ENUMERATORS
};

ConstexprSpecKind FromPasta(pasta::ConstexprSpecKind pasta_val);

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

enum class MultiVersionKind : unsigned short {
  NONE,
  TARGET,
  CPU_SPECIFIC,
  CPU_DISPATCH,
  NUM_ENUMERATORS
};

MultiVersionKind FromPasta(pasta::MultiVersionKind pasta_val);

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

enum class RefQualifierKind : unsigned short {
  NONE,
  L_VALUE,
  R_VALUE,
  NUM_ENUMERATORS
};

RefQualifierKind FromPasta(pasta::RefQualifierKind pasta_val);

enum class InClassInitStyle : unsigned short {
  NO_INITIALIZER,
  COPY_INITIALIZER,
  LIST_INITIALIZER,
  NUM_ENUMERATORS
};

InClassInitStyle FromPasta(pasta::InClassInitStyle pasta_val);

enum class TagTypeKind : unsigned short {
  STRUCT,
  INTERFACE,
  UNION,
  CLASS,
  ENUM,
  NUM_ENUMERATORS
};

TagTypeKind FromPasta(pasta::TagTypeKind pasta_val);

enum class ArgPassingKind : unsigned short {
  CAN_PASS_IN_REGS,
  CANNOT_PASS_IN_REGS,
  CAN_NEVER_PASS_IN_REGS,
  NUM_ENUMERATORS
};

ArgPassingKind FromPasta(pasta::ArgPassingKind pasta_val);

enum class MSInheritanceModel : unsigned short {
  SINGLE,
  MULTIPLE,
  VIRTUAL,
  UNSPECIFIED,
  NUM_ENUMERATORS
};

MSInheritanceModel FromPasta(pasta::MSInheritanceModel pasta_val);

enum class LambdaCaptureDefault : unsigned short {
  NONE,
  BY_COPY,
  BY_REFERENCE,
  NUM_ENUMERATORS
};

LambdaCaptureDefault FromPasta(pasta::LambdaCaptureDefault pasta_val);

enum class MSVtorDispMode : unsigned short {
  NEVER,
  FOR_VIRTUAL_BASE_OVERRIDE,
  FOR_VF_TABLE,
  NUM_ENUMERATORS
};

MSVtorDispMode FromPasta(pasta::MSVtorDispMode pasta_val);

enum class ObjCTypeParamVariance : unsigned short {
  INVARIANT,
  COVARIANT,
  CONTRAVARIANT,
  NUM_ENUMERATORS
};

ObjCTypeParamVariance FromPasta(pasta::ObjCTypeParamVariance pasta_val);

enum class PropertyControl : unsigned short {
  NONE,
  REQUIRED,
  OPTIONAL,
  NUM_ENUMERATORS
};

PropertyControl FromPasta(pasta::PropertyControl pasta_val);

enum class ObjCPropertyQueryKind : unsigned short {
  QUERY_UNKNOWN,
  QUERY_INSTANCE,
  QUERY_CLASS,
  NUM_ENUMERATORS
};

ObjCPropertyQueryKind FromPasta(pasta::ObjCPropertyQueryKind pasta_val);

enum class SetterKind : unsigned short {
  ASSIGN,
  RETAIN,
  COPY,
  WEAK,
  NUM_ENUMERATORS
};

SetterKind FromPasta(pasta::SetterKind pasta_val);

enum class ImplementationControl : unsigned short {
  NONE,
  REQUIRED,
  OPTIONAL,
  NUM_ENUMERATORS
};

ImplementationControl FromPasta(pasta::ImplementationControl pasta_val);

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

enum class LanguageIDs : unsigned short {
  C,
  CXX,
  NUM_ENUMERATORS
};

LanguageIDs FromPasta(pasta::LanguageIDs pasta_val);

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

enum class CapturedRegionKind : unsigned short {
  DEFAULT,
  OBJ_C_AT_FINALLY,
  OPEN_MP,
  NUM_ENUMERATORS
};

CapturedRegionKind FromPasta(pasta::CapturedRegionKind pasta_val);

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

enum class ExprValueKind : unsigned short {
  PR_VALUE,
  L_VALUE,
  X_VALUE,
  NUM_ENUMERATORS
};

ExprValueKind FromPasta(pasta::ExprValueKind pasta_val);

enum class NonOdrUseReason : unsigned short {
  NONE,
  UNEVALUATED,
  CONSTANT,
  DISCARDED,
  NUM_ENUMERATORS
};

NonOdrUseReason FromPasta(pasta::NonOdrUseReason pasta_val);

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

enum class ObjCBridgeCastKind : unsigned short {
  BRIDGE,
  BRIDGE_TRANSFER,
  BRIDGE_RETAINED,
  NUM_ENUMERATORS
};

ObjCBridgeCastKind FromPasta(pasta::ObjCBridgeCastKind pasta_val);

enum class ADLCallKind : unsigned short {
  NOT_ADL,
  USES_ADL,
  NUM_ENUMERATORS
};

ADLCallKind FromPasta(pasta::ADLCallKind pasta_val);

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

enum class InitializationStyle : unsigned short {
  C_INIT,
  CALL_INITIALIZER,
  LIST_INITIALIZER,
  NUM_ENUMERATORS
};

InitializationStyle FromPasta(pasta::InitializationStyle pasta_val);

enum class ConstructionKind : unsigned short {
  COMPLETE,
  NON_VIRTUAL_BASE,
  VIRTUAL_BASE,
  DELEGATING,
  NUM_ENUMERATORS
};

ConstructionKind FromPasta(pasta::ConstructionKind pasta_val);

enum class ArrayTypeTrait : unsigned short {
  ARRAY_RANK,
  ARRAY_EXTENT,
  NUM_ENUMERATORS
};

ArrayTypeTrait FromPasta(pasta::ArrayTypeTrait pasta_val);

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

enum class ResultStorageKind : unsigned short {
  NONE,
  INT64,
  AP_VALUE,
  NUM_ENUMERATORS
};

ResultStorageKind FromPasta(pasta::ResultStorageKind pasta_val);

enum class ExpressionTrait : unsigned short {
  IS_L_VALUE_EXPRESSION,
  IS_R_VALUE_EXPRESSION,
  NUM_ENUMERATORS
};

ExpressionTrait FromPasta(pasta::ExpressionTrait pasta_val);

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

enum class ObjCLifetime : unsigned short {
  NONE,
  EXPLICIT_NONE,
  STRONG,
  WEAK,
  AUTORELEASING,
  NUM_ENUMERATORS
};

ObjCLifetime FromPasta(pasta::ObjCLifetime pasta_val);

enum class ScalarTypeKind : unsigned short {
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

ScalarTypeKind FromPasta(pasta::ScalarTypeKind pasta_val);

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

enum class PrimitiveCopyKind : unsigned short {
  TRIVIAL,
  VOLATILE_TRIVIAL,
  ARC_STRONG,
  ARC_WEAK,
  STRUCT,
  NUM_ENUMERATORS
};

PrimitiveCopyKind FromPasta(pasta::PrimitiveCopyKind pasta_val);

enum class PrimitiveDefaultInitializeKind : unsigned short {
  TRIVIAL,
  ARC_STRONG,
  ARC_WEAK,
  STRUCT,
  NUM_ENUMERATORS
};

PrimitiveDefaultInitializeKind FromPasta(pasta::PrimitiveDefaultInitializeKind pasta_val);

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

enum class VectorKind : unsigned short {
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

VectorKind FromPasta(pasta::VectorKind pasta_val);

enum class AutoTypeKeyword : unsigned short {
  AUTO,
  DECLTYPE_AUTO,
  GNU_AUTO_TYPE,
  NUM_ENUMERATORS
};

AutoTypeKeyword FromPasta(pasta::AutoTypeKeyword pasta_val);

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
  ALIGN_MAC68K,
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
  M68K_INTERRUPT,
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

enum class ArraySizeModifier : unsigned short {
  NORMAL,
  STATIC,
  STAR,
  NUM_ENUMERATORS
};

ArraySizeModifier FromPasta(pasta::ArraySizeModifier pasta_val);

enum class UTTKind : unsigned short {
  ENUM_UNDERLYING_TYPE,
  NUM_ENUMERATORS
};

UTTKind FromPasta(pasta::UTTKind pasta_val);

}  // namespace mx
