// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>

namespace pasta {
class File;
enum class TokenRole : unsigned char;
enum class DeclKind : unsigned int;
enum class AttrKind : unsigned int;
enum class AArch64SVEPcsAttrSpelling : unsigned int;
enum class AArch64VectorPcsAttrSpelling : unsigned int;
enum class AMDGPUFlatWorkGroupSizeAttrSpelling : unsigned int;
enum class AMDGPUKernelCallAttrSpelling : unsigned int;
enum class AMDGPUNumSGPRAttrSpelling : unsigned int;
enum class AMDGPUNumVGPRAttrSpelling : unsigned int;
enum class AMDGPUWavesPerEUAttrSpelling : unsigned int;
enum class ARMInterruptAttrInterruptType : unsigned int;
enum class ARMInterruptAttrSpelling : unsigned int;
enum class AVRInterruptAttrSpelling : unsigned int;
enum class AVRSignalAttrSpelling : unsigned int;
enum class AbiTagAttrSpelling : unsigned int;
enum class AcquireCapabilityAttrSpelling : unsigned int;
enum class AcquireHandleAttrSpelling : unsigned int;
enum class AddressSpaceAttrSpelling : unsigned int;
enum class AliasAttrSpelling : unsigned int;
enum class AlignedAttrSpelling : unsigned int;
enum class AllocAlignAttrSpelling : unsigned int;
enum class AllocSizeAttrSpelling : unsigned int;
enum class AlwaysDestroyAttrSpelling : unsigned int;
enum class AlwaysInlineAttrSpelling : unsigned int;
enum class AnnotateAttrSpelling : unsigned int;
enum class AnnotateTypeAttrSpelling : unsigned int;
enum class AnyX86InterruptAttrSpelling : unsigned int;
enum class AnyX86NoCallerSavedRegistersAttrSpelling : unsigned int;
enum class AnyX86NoCfCheckAttrSpelling : unsigned int;
enum class ArcWeakrefUnavailableAttrSpelling : unsigned int;
enum class ArgumentWithTypeTagAttrSpelling : unsigned int;
enum class ArmBuiltinAliasAttrSpelling : unsigned int;
enum class ArmMveStrictPolymorphismAttrSpelling : unsigned int;
enum class ArrayTypeArraySizeModifier : unsigned int;
enum class ArtificialAttrSpelling : unsigned int;
enum class AsmLabelAttrSpelling : unsigned int;
enum class AssertCapabilityAttrSpelling : unsigned int;
enum class AssumeAlignedAttrSpelling : unsigned int;
enum class AssumptionAttrSpelling : unsigned int;
enum class AtomicExprAtomicOp : unsigned int;
enum class AvailabilityAttrSpelling : unsigned int;
enum class AvailableOnlyInDefaultEvalMethodAttrSpelling : unsigned int;
enum class BPFPreserveAccessIndexAttrSpelling : unsigned int;
enum class BTFDeclTagAttrSpelling : unsigned int;
enum class BTFTypeTagAttrSpelling : unsigned int;
enum class BlocksAttrBlockType : unsigned int;
enum class BlocksAttrSpelling : unsigned int;
enum class BuiltinAliasAttrSpelling : unsigned int;
enum class BuiltinTypeKind : unsigned int;
enum class CDeclAttrSpelling : unsigned int;
enum class CFAuditedTransferAttrSpelling : unsigned int;
enum class CFConsumedAttrSpelling : unsigned int;
enum class CFGuardAttrGuardArg : unsigned int;
enum class CFGuardAttrSpelling : unsigned int;
enum class CFICanonicalJumpTableAttrSpelling : unsigned int;
enum class CFReturnsNotRetainedAttrSpelling : unsigned int;
enum class CFReturnsRetainedAttrSpelling : unsigned int;
enum class CFUnknownTransferAttrSpelling : unsigned int;
enum class CPUDispatchAttrSpelling : unsigned int;
enum class CPUSpecificAttrSpelling : unsigned int;
enum class CUDAConstantAttrSpelling : unsigned int;
enum class CUDADeviceAttrSpelling : unsigned int;
enum class CUDADeviceBuiltinSurfaceTypeAttrSpelling : unsigned int;
enum class CUDADeviceBuiltinTextureTypeAttrSpelling : unsigned int;
enum class CUDAGlobalAttrSpelling : unsigned int;
enum class CUDAHostAttrSpelling : unsigned int;
enum class CUDALaunchBoundsAttrSpelling : unsigned int;
enum class CUDASharedAttrSpelling : unsigned int;
enum class CXX11NoReturnAttrSpelling : unsigned int;
enum class CXXConstructExprConstructionKind : unsigned int;
enum class CXXNewExprInitializationStyle : unsigned int;
enum class CXXRecordDeclLambdaDependencyKind : unsigned int;
enum class CallExprADLCallKind : bool;
enum class CallableWhenAttrConsumedState : unsigned int;
enum class CallableWhenAttrSpelling : unsigned int;
enum class CallbackAttrSpelling : unsigned int;
enum class CalledOnceAttrSpelling : unsigned int;
enum class CapabilityAttrSpelling : unsigned int;
enum class CapturedStmtVariableCaptureKind : unsigned int;
enum class CarriesDependencyAttrSpelling : unsigned int;
enum class CharacterLiteralCharacterKind : unsigned int;
enum class CleanupAttrSpelling : unsigned int;
enum class ColdAttrSpelling : unsigned int;
enum class CommonAttrSpelling : unsigned int;
enum class ConstAttrSpelling : unsigned int;
enum class ConstInitAttrSpelling : unsigned int;
enum class ConstantExprResultStorageKind : unsigned int;
enum class ConstructorAttrSpelling : unsigned int;
enum class ConsumableAttrConsumedState : unsigned int;
enum class ConsumableAttrSpelling : unsigned int;
enum class ConsumableAutoCastAttrSpelling : unsigned int;
enum class ConsumableSetOnReadAttrSpelling : unsigned int;
enum class ConvergentAttrSpelling : unsigned int;
enum class DLLExportAttrSpelling : unsigned int;
enum class DLLImportAttrSpelling : unsigned int;
enum class DeclFriendObjectKind : unsigned int;
enum class DeclIdentifierNamespace : unsigned int;
enum class DeclModuleOwnershipKind : unsigned int;
enum class DeclObjCDeclQualifier : unsigned int;
enum class DeprecatedAttrSpelling : unsigned int;
enum class DestructorAttrSpelling : unsigned int;
enum class DiagnoseAsBuiltinAttrSpelling : unsigned int;
enum class DiagnoseIfAttrDiagnosticType : unsigned int;
enum class DisableSanitizerInstrumentationAttrSpelling : unsigned int;
enum class DisableTailCallsAttrSpelling : unsigned int;
enum class EnforceTCBAttrSpelling : unsigned int;
enum class EnforceTCBLeafAttrSpelling : unsigned int;
enum class EnumExtensibilityAttrKind : unsigned int;
enum class EnumExtensibilityAttrSpelling : unsigned int;
enum class ErrorAttrSpelling : unsigned int;
enum class ExcludeFromExplicitInstantiationAttrSpelling : unsigned int;
enum class ExprConstantExprKind : int;
enum class ExprLValueClassification : unsigned int;
enum class ExprNullPointerConstantKind : unsigned int;
enum class ExprNullPointerConstantValueDependence : unsigned int;
enum class ExprSideEffectsKind : unsigned int;
enum class ExprisModifiableLvalueResult : unsigned int;
enum class ExternalSourceSymbolAttrSpelling : unsigned int;
enum class FallThroughAttrSpelling : unsigned int;
enum class FastCallAttrSpelling : unsigned int;
enum class FinalAttrSpelling : unsigned int;
enum class FlagEnumAttrSpelling : unsigned int;
enum class FlattenAttrSpelling : unsigned int;
enum class FormatArgAttrSpelling : unsigned int;
enum class FormatAttrSpelling : unsigned int;
enum class FunctionDeclTemplatedKind : unsigned int;
enum class FunctionReturnThunksAttrKind : unsigned int;
enum class FunctionReturnThunksAttrSpelling : unsigned int;
enum class GNUInlineAttrSpelling : unsigned int;
enum class GuardedVarAttrSpelling : unsigned int;
enum class HIPManagedAttrSpelling : unsigned int;
enum class HLSLResourceAttrResourceClass : unsigned int;
enum class HLSLResourceAttrResourceKind : unsigned int;
enum class HLSLShaderAttrShaderType : unsigned int;
enum class HotAttrSpelling : unsigned int;
enum class IBActionAttrSpelling : unsigned int;
enum class IBOutletAttrSpelling : unsigned int;
enum class IBOutletCollectionAttrSpelling : unsigned int;
enum class IFuncAttrSpelling : unsigned int;
enum class ImplicitCastExprOnStack : unsigned int;
enum class ImplicitParamDeclImplicitParamKind : unsigned int;
enum class InitPriorityAttrSpelling : unsigned int;
enum class IntelOclBiccAttrSpelling : unsigned int;
enum class InternalLinkageAttrSpelling : unsigned int;
enum class LTOVisibilityPublicAttrSpelling : unsigned int;
enum class LeafAttrSpelling : unsigned int;
enum class LifetimeBoundAttrSpelling : unsigned int;
enum class LikelyAttrSpelling : unsigned int;
enum class LinkageSpecDeclLanguageIDs : unsigned int;
enum class LoaderUninitializedAttrSpelling : unsigned int;
enum class LoopHintAttrLoopHintState : unsigned int;
enum class LoopHintAttrOptionType : unsigned int;
enum class LoopHintAttrSpelling : unsigned int;
enum class MIGServerRoutineAttrSpelling : unsigned int;
enum class MSABIAttrSpelling : unsigned int;
enum class MSInheritanceAttrSpelling : unsigned int;
enum class MSP430InterruptAttrSpelling : unsigned int;
enum class MSStructAttrSpelling : unsigned int;
enum class MayAliasAttrSpelling : unsigned int;
enum class MaybeUndefAttrSpelling : unsigned int;
enum class MicroMipsAttrSpelling : unsigned int;
enum class MinSizeAttrSpelling : unsigned int;
enum class MinVectorWidthAttrSpelling : unsigned int;
enum class Mips16AttrSpelling : unsigned int;
enum class MipsInterruptAttrInterruptType : unsigned int;
enum class MipsInterruptAttrSpelling : unsigned int;
enum class MipsLongCallAttrSpelling : unsigned int;
enum class MipsShortCallAttrSpelling : unsigned int;
enum class ModeAttrSpelling : unsigned int;
enum class MustTailAttrSpelling : unsigned int;
enum class NSConsumedAttrSpelling : unsigned int;
enum class NSConsumesSelfAttrSpelling : unsigned int;
enum class NSReturnsAutoreleasedAttrSpelling : unsigned int;
enum class NSReturnsNotRetainedAttrSpelling : unsigned int;
enum class NSReturnsRetainedAttrSpelling : unsigned int;
enum class NVPTXKernelAttrSpelling : unsigned int;
enum class NakedAttrSpelling : unsigned int;
enum class NamedDeclExplicitVisibilityKind : unsigned int;
enum class NoBuiltinAttrSpelling : unsigned int;
enum class NoCommonAttrSpelling : unsigned int;
enum class NoDebugAttrSpelling : unsigned int;
enum class NoDerefAttrSpelling : unsigned int;
enum class NoDestroyAttrSpelling : unsigned int;
enum class NoDuplicateAttrSpelling : unsigned int;
enum class NoEscapeAttrSpelling : unsigned int;
enum class NoInlineAttrSpelling : unsigned int;
enum class NoInstrumentFunctionAttrSpelling : unsigned int;
enum class NoMergeAttrSpelling : unsigned int;
enum class NoMicroMipsAttrSpelling : unsigned int;
enum class NoMips16AttrSpelling : unsigned int;
enum class NoProfileFunctionAttrSpelling : unsigned int;
enum class NoRandomizeLayoutAttrSpelling : unsigned int;
enum class NoReturnAttrSpelling : unsigned int;
enum class NoSanitizeAttrSpelling : unsigned int;
enum class NoSpeculativeLoadHardeningAttrSpelling : unsigned int;
enum class NoSplitStackAttrSpelling : unsigned int;
enum class NoStackProtectorAttrSpelling : unsigned int;
enum class NoThreadSafetyAnalysisAttrSpelling : unsigned int;
enum class NoThrowAttrSpelling : unsigned int;
enum class NoUwtableAttrSpelling : unsigned int;
enum class NonNullAttrSpelling : unsigned int;
enum class NotTailCalledAttrSpelling : unsigned int;
enum class OMPAllocateDeclAttrAllocatorTypeTy : unsigned int;
enum class OMPDeclareReductionDeclInitKind : unsigned int;
enum class OMPDeclareSimdDeclAttrBranchStateTy : unsigned int;
enum class OMPDeclareTargetDeclAttrDevTypeTy : unsigned int;
enum class OMPDeclareTargetDeclAttrMapTypeTy : unsigned int;
enum class OSConsumedAttrSpelling : unsigned int;
enum class OSConsumesThisAttrSpelling : unsigned int;
enum class OSReturnsNotRetainedAttrSpelling : unsigned int;
enum class OSReturnsRetainedAttrSpelling : unsigned int;
enum class OSReturnsRetainedOnNonZeroAttrSpelling : unsigned int;
enum class OSReturnsRetainedOnZeroAttrSpelling : unsigned int;
enum class ObjCBoxableAttrSpelling : unsigned int;
enum class ObjCBridgeAttrSpelling : unsigned int;
enum class ObjCBridgeMutableAttrSpelling : unsigned int;
enum class ObjCBridgeRelatedAttrSpelling : unsigned int;
enum class ObjCClassStubAttrSpelling : unsigned int;
enum class ObjCDesignatedInitializerAttrSpelling : unsigned int;
enum class ObjCDirectAttrSpelling : unsigned int;
enum class ObjCDirectMembersAttrSpelling : unsigned int;
enum class ObjCExceptionAttrSpelling : unsigned int;
enum class ObjCExplicitProtocolImplAttrSpelling : unsigned int;
enum class ObjCExternallyRetainedAttrSpelling : unsigned int;
enum class ObjCGCAttrSpelling : unsigned int;
enum class ObjCIndependentClassAttrSpelling : unsigned int;
enum class ObjCIvarDeclAccessControl : unsigned int;
enum class ObjCMessageExprReceiverKind : unsigned int;
enum class ObjCMethodDeclImplementationControl : unsigned int;
enum class ObjCMethodFamilyAttrFamilyKind : unsigned int;
enum class ObjCMethodFamilyAttrSpelling : unsigned int;
enum class ObjCNSObjectAttrSpelling : unsigned int;
enum class ObjCNonLazyClassAttrSpelling : unsigned int;
enum class ObjCNonRuntimeProtocolAttrSpelling : unsigned int;
enum class ObjCOwnershipAttrSpelling : unsigned int;
enum class ObjCPreciseLifetimeAttrSpelling : unsigned int;
enum class ObjCPropertyDeclPropertyControl : unsigned int;
enum class ObjCPropertyDeclSetterKind : unsigned int;
enum class ObjCPropertyImplDeclKind : unsigned int;
enum class ObjCRequiresPropertyDefsAttrSpelling : unsigned int;
enum class ObjCRequiresSuperAttrSpelling : unsigned int;
enum class ObjCReturnsInnerPointerAttrSpelling : unsigned int;
enum class ObjCRootClassAttrSpelling : unsigned int;
enum class ObjCRuntimeNameAttrSpelling : unsigned int;
enum class ObjCRuntimeVisibleAttrSpelling : unsigned int;
enum class ObjCSubclassingRestrictedAttrSpelling : unsigned int;
enum class OpenCLAccessAttrSpelling : unsigned int;
enum class OpenCLConstantAddressSpaceAttrSpelling : unsigned int;
enum class OpenCLGenericAddressSpaceAttrSpelling : unsigned int;
enum class OpenCLGlobalAddressSpaceAttrSpelling : unsigned int;
enum class OpenCLGlobalDeviceAddressSpaceAttrSpelling : unsigned int;
enum class OpenCLGlobalHostAddressSpaceAttrSpelling : unsigned int;
enum class OpenCLKernelAttrSpelling : unsigned int;
enum class OpenCLLocalAddressSpaceAttrSpelling : unsigned int;
enum class OpenCLPrivateAddressSpaceAttrSpelling : unsigned int;
enum class OptimizeNoneAttrSpelling : unsigned int;
enum class OverloadableAttrSpelling : unsigned int;
enum class OwnershipAttrOwnershipKind : unsigned int;
enum class OwnershipAttrSpelling : unsigned int;
enum class PackedAttrSpelling : unsigned int;
enum class ParamTypestateAttrConsumedState : unsigned int;
enum class ParamTypestateAttrSpelling : unsigned int;
enum class PascalAttrSpelling : unsigned int;
enum class PassObjectSizeAttrSpelling : unsigned int;
enum class PatchableFunctionEntryAttrSpelling : unsigned int;
enum class PcsAttrPCSType : unsigned int;
enum class PcsAttrSpelling : unsigned int;
enum class PredefinedExprIdentKind : unsigned int;
enum class PreferredNameAttrSpelling : unsigned int;
enum class PreserveAllAttrSpelling : unsigned int;
enum class PreserveMostAttrSpelling : unsigned int;
enum class PtGuardedVarAttrSpelling : unsigned int;
enum class PureAttrSpelling : unsigned int;
enum class QualifiedTypeDestructionKind : unsigned int;
enum class QualifiedTypePrimitiveCopyKind : unsigned int;
enum class QualifiedTypePrimitiveDefaultInitializeKind : unsigned int;
enum class RISCVInterruptAttrInterruptType : unsigned int;
enum class RISCVInterruptAttrSpelling : unsigned int;
enum class RandomizeLayoutAttrSpelling : unsigned int;
enum class ReadOnlyPlacementAttrSpelling : unsigned int;
enum class RecordDeclArgPassingKind : unsigned int;
enum class RegCallAttrSpelling : unsigned int;
enum class ReinitializesAttrSpelling : unsigned int;
enum class ReleaseCapabilityAttrSpelling : unsigned int;
enum class ReleaseHandleAttrSpelling : unsigned int;
enum class RequiresCapabilityAttrSpelling : unsigned int;
enum class RestrictAttrSpelling : unsigned int;
enum class RetainAttrSpelling : unsigned int;
enum class ReturnTypestateAttrConsumedState : unsigned int;
enum class ReturnTypestateAttrSpelling : unsigned int;
enum class ReturnsNonNullAttrSpelling : unsigned int;
enum class ReturnsTwiceAttrSpelling : unsigned int;
enum class SYCLKernelAttrSpelling : unsigned int;
enum class SYCLSpecialClassAttrSpelling : unsigned int;
enum class ScopedLockableAttrSpelling : unsigned int;
enum class SectionAttrSpelling : unsigned int;
enum class SelectAnyAttrSpelling : unsigned int;
enum class SentinelAttrSpelling : unsigned int;
enum class SetTypestateAttrConsumedState : unsigned int;
enum class SetTypestateAttrSpelling : unsigned int;
enum class SourceLocExprIdentKind : unsigned int;
enum class SpeculativeLoadHardeningAttrSpelling : unsigned int;
enum class StandaloneDebugAttrSpelling : unsigned int;
enum class StdCallAttrSpelling : unsigned int;
enum class StmtLikelihood : int;
enum class StmtKind : unsigned int;
enum class StringLiteralStringKind : unsigned int;
enum class SwiftAsyncAttrKind : unsigned int;
enum class SwiftAsyncAttrSpelling : unsigned int;
enum class SwiftAsyncCallAttrSpelling : unsigned int;
enum class SwiftAsyncContextAttrSpelling : unsigned int;
enum class SwiftAsyncErrorAttrConventionKind : unsigned int;
enum class SwiftAsyncErrorAttrSpelling : unsigned int;
enum class SwiftCallAttrSpelling : unsigned int;
enum class SwiftContextAttrSpelling : unsigned int;
enum class SwiftErrorAttrConventionKind : unsigned int;
enum class SwiftErrorResultAttrSpelling : unsigned int;
enum class SwiftIndirectResultAttrSpelling : unsigned int;
enum class SwiftNewTypeAttrNewtypeKind : unsigned int;
enum class SwiftNewTypeAttrSpelling : unsigned int;
enum class SysVABIAttrSpelling : unsigned int;
enum class TLSModelAttrSpelling : unsigned int;
enum class TargetAttrSpelling : unsigned int;
enum class TargetClonesAttrSpelling : unsigned int;
enum class TargetVersionAttrSpelling : unsigned int;
enum class TemplateArgumentKind : unsigned int;
enum class TestTypestateAttrConsumedState : unsigned int;
enum class TestTypestateAttrSpelling : unsigned int;
enum class ThisCallAttrSpelling : unsigned int;
enum class TransparentUnionAttrSpelling : unsigned int;
enum class TrivialABIAttrSpelling : unsigned int;
enum class TryAcquireCapabilityAttrSpelling : unsigned int;
enum class TypeScalarTypeKind : unsigned int;
enum class TypeKind : unsigned int;
enum class TypeTagForDatatypeAttrSpelling : unsigned int;
enum class TypeVisibilityAttrSpelling : unsigned int;
enum class TypeVisibilityAttrVisibilityType : unsigned int;
enum class UnaryTransformTypeUTTKind : unsigned int;
enum class UnavailableAttrImplicitReason : unsigned int;
enum class UnavailableAttrSpelling : unsigned int;
enum class UninitializedAttrSpelling : unsigned int;
enum class UnlikelyAttrSpelling : unsigned int;
enum class UnsafeBufferUsageAttrSpelling : unsigned int;
enum class UnusedAttrSpelling : unsigned int;
enum class UseHandleAttrSpelling : unsigned int;
enum class UsedAttrSpelling : unsigned int;
enum class UserDefinedLiteralLiteralOperatorKind : unsigned int;
enum class UsingIfExistsAttrSpelling : unsigned int;
enum class UuidAttrSpelling : unsigned int;
enum class VarDeclDefinitionKind : unsigned int;
enum class VarDeclInitializationStyle : unsigned int;
enum class VarDeclTLSKind : unsigned int;
enum class VecReturnAttrSpelling : unsigned int;
enum class VectorCallAttrSpelling : unsigned int;
enum class VectorTypeVectorKind : unsigned int;
enum class VisibilityAttrSpelling : unsigned int;
enum class VisibilityAttrVisibilityType : unsigned int;
enum class WarnUnusedAttrSpelling : unsigned int;
enum class WarnUnusedResultAttrSpelling : unsigned int;
enum class WeakAttrSpelling : unsigned int;
enum class WeakImportAttrSpelling : unsigned int;
enum class WeakRefAttrSpelling : unsigned int;
enum class WebAssemblyExportNameAttrSpelling : unsigned int;
enum class WebAssemblyImportModuleAttrSpelling : unsigned int;
enum class WebAssemblyImportNameAttrSpelling : unsigned int;
enum class X86ForceAlignArgPointerAttrSpelling : unsigned int;
enum class XRayInstrumentAttrSpelling : unsigned int;
enum class XRayLogArgsAttrSpelling : unsigned int;
enum class ZeroCallUsedRegsAttrSpelling : unsigned int;
enum class ZeroCallUsedRegsAttrZeroCallUsedRegsKind : unsigned int;
enum class ASTDumpOutputFormat : unsigned int;
enum class AccessSpecifier : unsigned int;
enum class AddrSpaceMapMangling : unsigned int;
enum class AlignRequirementKind : int;
enum class AltivecSrcCompatKind : int;
enum class ArgumentKind : unsigned int;
enum class ArrayTypeTrait : unsigned int;
enum class AssignmentTrackingOpts : unsigned int;
enum class AtomicScopeModelKind : int;
enum class AutoTypeKeyword : int;
enum class AvailabilityResult : unsigned int;
enum class BinaryOperatorKind : unsigned int;
enum class Bits : unsigned char;
enum class CallingConv : unsigned int;
enum class CanThrowResult : unsigned int;
enum class CapturedRegionKind : unsigned int;
enum class CastKind : unsigned int;
enum class ClangABI : int;
enum class CommentKind : unsigned int;
enum class ComparisonCategoryResult : unsigned char;
enum class ComparisonCategoryType : unsigned char;
enum class CompilingModuleKind : unsigned int;
enum class ConstexprSpecKind : int;
enum class CoreFoundationABI : int;
enum class DataPositionTy : unsigned long;
enum class DebugSrcHashKind : unsigned int;
enum class DeductionCandidate : unsigned char;
enum class DefaultArgKind : unsigned int;
enum class DefaultCallingConvention : unsigned int;
enum class DefaultVisiblityExportMapping : int;
enum class DesignatorKind : unsigned int;
enum class DiagnosticLevelMask : unsigned int;
enum class ElaboratedTypeKeyword : unsigned int;
enum class EmbedBitcodeKind : unsigned int;
enum class EscapeChar : int;
enum class ExceptionHandlingKind : int;
enum class ExceptionSpecificationType : unsigned int;
enum class ExcessPrecisionKind : unsigned int;
enum class ExclusionType : unsigned int;
enum class ExplicitSpecKind : unsigned int;
enum class ExprDependence : unsigned char;
enum class ExprObjectKind : unsigned int;
enum class ExprOffsets : int;
enum class ExprValueKind : unsigned int;
enum class ExpressionTrait : unsigned int;
enum class ExtKind : unsigned int;
enum class ExtendArgsKind : int;
enum class FPEvalMethodKind : int;
enum class FPExceptionModeKind : unsigned int;
enum class FPModeKind : unsigned int;
enum class FiniteLoopsKind : unsigned int;
enum class Flags : unsigned int;
enum class FramePointerKind : int;
enum class GC : unsigned int;
enum class GCMode : unsigned int;
enum class GPUDefaultStreamKind : int;
enum class GVALinkage : unsigned int;
enum class GetBuiltinTypeError : unsigned int;
enum class HLSLLangStd : unsigned int;
enum class ID : unsigned int;
enum class IdentifierInfoFlag : unsigned int;
enum class IfStatementKind : unsigned int;
enum class ImbueAttribute : int;
enum class InClassInitStyle : unsigned int;
enum class InheritedDesignatedInitializersState : unsigned int;
enum class InitStorageKind : unsigned int;
enum class InlineAsmDialectKind : unsigned int;
enum class InlineVariableDefinitionKind : int;
enum class InliningMethod : unsigned int;
enum class InterestingIdentifierKind : unsigned int;
enum class Kinds : unsigned int;
enum class LambdaCaptureDefault : unsigned int;
enum class LambdaCaptureKind : unsigned int;
enum class LangAS : unsigned int;
enum class LangFeatures : unsigned int;
enum class Language : unsigned char;
enum class LanguageLinkage : unsigned int;
enum class LaxVectorConversionKind : int;
enum class Level : unsigned int;
enum class Linkage : unsigned char;
enum class MSInheritanceModel : int;
enum class MSVCMajorVersion : unsigned int;
enum class MSVtorDispMode : int;
enum class MethodRefFlags : unsigned int;
enum class ModifiableType : unsigned int;
enum class MultiVersionKind : int;
enum class NameKind : unsigned int;
enum class NeedExtraManglingDecl : unsigned int;
enum class NestedNameSpecifierDependence : unsigned char;
enum class NonOdrUseReason : unsigned int;
enum class NonceObjCInterface : unsigned int;
enum class NullabilityKind : unsigned char;
enum class ObjCBridgeCastKind : unsigned int;
enum class ObjCDispatchMethodKind : unsigned int;
enum class ObjCInstanceTypeFamily : unsigned int;
enum class ObjCKeywordKind : unsigned int;
enum class ObjCLifetime : unsigned int;
enum class ObjCMethodFamily : unsigned int;
enum class ObjCPropertyQueryKind : unsigned char;
enum class ObjCStringFormatFamily : unsigned int;
enum class ObjCSubstitutionContext : int;
enum class ObjCTypeParamVariance : unsigned char;
enum class OnOffSwitch : unsigned int;
enum class OnStackType : unsigned int;
enum class OpenMPAdjustArgsOpKind : unsigned int;
enum class OpenMPAtClauseKind : unsigned int;
enum class OpenMPAtomicDefaultMemOrderClauseKind : unsigned int;
enum class OpenMPBindClauseKind : unsigned int;
enum class OpenMPDefaultmapClauseKind : unsigned int;
enum class OpenMPDefaultmapClauseModifier : unsigned int;
enum class OpenMPDependClauseKind : unsigned int;
enum class OpenMPDeviceClauseModifier : unsigned int;
enum class OpenMPDeviceType : unsigned int;
enum class OpenMPDistScheduleClauseKind : unsigned int;
enum class OpenMPDoacrossClauseModifier : unsigned int;
enum class OpenMPGrainsizeClauseModifier : unsigned int;
enum class OpenMPLastprivateModifier : unsigned int;
enum class OpenMPLinearClauseKind : unsigned int;
enum class OpenMPMapClauseKind : unsigned int;
enum class OpenMPMapModifierKind : unsigned int;
enum class OpenMPMotionModifierKind : unsigned int;
enum class OpenMPNumTasksClauseModifier : unsigned int;
enum class OpenMPOrderClauseKind : unsigned int;
enum class OpenMPOrderClauseModifier : unsigned int;
enum class OpenMPReductionClauseModifier : unsigned int;
enum class OpenMPScheduleClauseKind : unsigned int;
enum class OpenMPScheduleClauseModifier : unsigned int;
enum class OpenMPSeverityClauseKind : unsigned int;
enum class OverloadedOperatorKind : int;
enum class OverloadsShown : unsigned int;
enum class PPKeywordKind : unsigned int;
enum class ParameterABI : int;
enum class ParenLocsOffsets : int;
enum class PragmaFloatControlKind : unsigned int;
enum class PragmaMSCommentKind : unsigned int;
enum class PragmaMSPointersToMembersKind : unsigned int;
enum class PragmaMSStructKind : unsigned int;
enum class PragmaSectionFlag : unsigned int;
enum class ProfileInstrKind : unsigned int;
enum class Qualified : int;
enum class RangeExprOffset : int;
enum class RangeLocOffset : int;
enum class RefQualifierKind : unsigned int;
enum class RemarkKind : unsigned int;
enum class ReservedIdentifierStatus : int;
enum class ReservedLiteralSuffixIdStatus : int;
enum class SFINAEResponse : unsigned int;
enum class SYCLMajorVersion : unsigned int;
enum class SanitizerOrdinal : unsigned long long;
enum class SelectorLocationsKind : unsigned int;
enum class ShaderStage : int;
enum class SignReturnAddressKeyKind : int;
enum class SignReturnAddressScopeKind : int;
enum class SignedOverflowBehaviorTy : unsigned int;
enum class SpecialMemberFlags : unsigned int;
enum class SpecifierKind : unsigned int;
enum class StackProtectorMode : unsigned int;
enum class StorageClass : unsigned int;
enum class StorageDuration : unsigned int;
enum class StoredNameKind : unsigned int;
enum class StoredSpecifierKind : unsigned int;
enum class StrictFlexArraysLevelKind : int;
enum class StructReturnConventionKind : unsigned int;
enum class SubExpr : unsigned int;
enum class SubStmt : unsigned int;
enum class SwiftAsyncFramePointerKind : int;
enum class SyncScope : int;
enum class Syntax : unsigned int;
enum class TLSModel : unsigned int;
enum class TQ : unsigned int;
enum class TagTypeKind : unsigned int;
enum class TailPaddingUseRules : unsigned int;
enum class TemplateArgumentDependence : unsigned char;
enum class TemplateNameDependence : unsigned char;
enum class TemplateSpecializationKind : unsigned int;
enum class TextDiagnosticFormat : unsigned int;
enum class ThreadModelKind : int;
enum class ThreadStorageClassSpecifier : unsigned int;
enum class TokenKind : unsigned short;
enum class TrailingAllocKind : unsigned int;
enum class TranslationUnitKind : unsigned int;
enum class TrivialAutoVarInitKind : int;
enum class TypeDependence : unsigned char;
enum class TypeLocClass : unsigned int;
enum class TypeOfKind : unsigned char;
enum class TypeSpecifierSign : int;
enum class TypeSpecifierType : unsigned int;
enum class TypeSpecifierWidth : int;
enum class TypeSpecifiersPipe : int;
enum class TypeTrait : unsigned int;
enum class UnaryExprOrTypeTrait : unsigned int;
enum class UnaryOperatorKind : unsigned int;
enum class APValueKind : unsigned int;
enum class VectorLibrary : unsigned int;
enum class Visibility : unsigned int;
enum class AttributeSyntax : unsigned int;
enum class DeclCategory : unsigned int;
enum class MacroKind : unsigned char;
enum class PathKind : signed char;
enum class FileType : signed char;
enum class CompilerName : unsigned int;
enum class IncludePathLocation : unsigned int;
enum class TargetLanguage : unsigned int;
enum class PseudoKind : unsigned char;
enum class TokenCategory : unsigned char;
}  // namespace pasta
namespace mx {
enum class DeclKind : unsigned char;
DeclKind FromPasta(pasta::DeclKind pasta_val);

enum class AttrKind : unsigned short;
AttrKind FromPasta(pasta::AttrKind pasta_val);

enum class AArch64SVEPcsAttrSpelling : unsigned char;
AArch64SVEPcsAttrSpelling FromPasta(pasta::AArch64SVEPcsAttrSpelling pasta_val);

enum class AArch64VectorPcsAttrSpelling : unsigned char;
AArch64VectorPcsAttrSpelling FromPasta(pasta::AArch64VectorPcsAttrSpelling pasta_val);

enum class AMDGPUFlatWorkGroupSizeAttrSpelling : unsigned char;
AMDGPUFlatWorkGroupSizeAttrSpelling FromPasta(pasta::AMDGPUFlatWorkGroupSizeAttrSpelling pasta_val);

enum class AMDGPUKernelCallAttrSpelling : unsigned char;
AMDGPUKernelCallAttrSpelling FromPasta(pasta::AMDGPUKernelCallAttrSpelling pasta_val);

enum class AMDGPUNumSGPRAttrSpelling : unsigned char;
AMDGPUNumSGPRAttrSpelling FromPasta(pasta::AMDGPUNumSGPRAttrSpelling pasta_val);

enum class AMDGPUNumVGPRAttrSpelling : unsigned char;
AMDGPUNumVGPRAttrSpelling FromPasta(pasta::AMDGPUNumVGPRAttrSpelling pasta_val);

enum class AMDGPUWavesPerEUAttrSpelling : unsigned char;
AMDGPUWavesPerEUAttrSpelling FromPasta(pasta::AMDGPUWavesPerEUAttrSpelling pasta_val);

enum class ARMInterruptAttrInterruptType : unsigned char;
ARMInterruptAttrInterruptType FromPasta(pasta::ARMInterruptAttrInterruptType pasta_val);

enum class ARMInterruptAttrSpelling : unsigned char;
ARMInterruptAttrSpelling FromPasta(pasta::ARMInterruptAttrSpelling pasta_val);

enum class AVRInterruptAttrSpelling : unsigned char;
AVRInterruptAttrSpelling FromPasta(pasta::AVRInterruptAttrSpelling pasta_val);

enum class AVRSignalAttrSpelling : unsigned char;
AVRSignalAttrSpelling FromPasta(pasta::AVRSignalAttrSpelling pasta_val);

enum class AbiTagAttrSpelling : unsigned char;
AbiTagAttrSpelling FromPasta(pasta::AbiTagAttrSpelling pasta_val);

enum class AcquireCapabilityAttrSpelling : unsigned char;
AcquireCapabilityAttrSpelling FromPasta(pasta::AcquireCapabilityAttrSpelling pasta_val);

enum class AcquireHandleAttrSpelling : unsigned char;
AcquireHandleAttrSpelling FromPasta(pasta::AcquireHandleAttrSpelling pasta_val);

enum class AddressSpaceAttrSpelling : unsigned char;
AddressSpaceAttrSpelling FromPasta(pasta::AddressSpaceAttrSpelling pasta_val);

enum class AliasAttrSpelling : unsigned char;
AliasAttrSpelling FromPasta(pasta::AliasAttrSpelling pasta_val);

enum class AlignedAttrSpelling : unsigned char;
AlignedAttrSpelling FromPasta(pasta::AlignedAttrSpelling pasta_val);

enum class AllocAlignAttrSpelling : unsigned char;
AllocAlignAttrSpelling FromPasta(pasta::AllocAlignAttrSpelling pasta_val);

enum class AllocSizeAttrSpelling : unsigned char;
AllocSizeAttrSpelling FromPasta(pasta::AllocSizeAttrSpelling pasta_val);

enum class AlwaysDestroyAttrSpelling : unsigned char;
AlwaysDestroyAttrSpelling FromPasta(pasta::AlwaysDestroyAttrSpelling pasta_val);

enum class AlwaysInlineAttrSpelling : unsigned char;
AlwaysInlineAttrSpelling FromPasta(pasta::AlwaysInlineAttrSpelling pasta_val);

enum class AnnotateAttrSpelling : unsigned char;
AnnotateAttrSpelling FromPasta(pasta::AnnotateAttrSpelling pasta_val);

enum class AnnotateTypeAttrSpelling : unsigned char;
AnnotateTypeAttrSpelling FromPasta(pasta::AnnotateTypeAttrSpelling pasta_val);

enum class AnyX86InterruptAttrSpelling : unsigned char;
AnyX86InterruptAttrSpelling FromPasta(pasta::AnyX86InterruptAttrSpelling pasta_val);

enum class AnyX86NoCallerSavedRegistersAttrSpelling : unsigned char;
AnyX86NoCallerSavedRegistersAttrSpelling FromPasta(pasta::AnyX86NoCallerSavedRegistersAttrSpelling pasta_val);

enum class AnyX86NoCfCheckAttrSpelling : unsigned char;
AnyX86NoCfCheckAttrSpelling FromPasta(pasta::AnyX86NoCfCheckAttrSpelling pasta_val);

enum class ArcWeakrefUnavailableAttrSpelling : unsigned char;
ArcWeakrefUnavailableAttrSpelling FromPasta(pasta::ArcWeakrefUnavailableAttrSpelling pasta_val);

enum class ArgumentWithTypeTagAttrSpelling : unsigned char;
ArgumentWithTypeTagAttrSpelling FromPasta(pasta::ArgumentWithTypeTagAttrSpelling pasta_val);

enum class ArmBuiltinAliasAttrSpelling : unsigned char;
ArmBuiltinAliasAttrSpelling FromPasta(pasta::ArmBuiltinAliasAttrSpelling pasta_val);

enum class ArmMveStrictPolymorphismAttrSpelling : unsigned char;
ArmMveStrictPolymorphismAttrSpelling FromPasta(pasta::ArmMveStrictPolymorphismAttrSpelling pasta_val);

enum class ArrayTypeArraySizeModifier : unsigned char;
ArrayTypeArraySizeModifier FromPasta(pasta::ArrayTypeArraySizeModifier pasta_val);

enum class ArtificialAttrSpelling : unsigned char;
ArtificialAttrSpelling FromPasta(pasta::ArtificialAttrSpelling pasta_val);

enum class AsmLabelAttrSpelling : unsigned char;
AsmLabelAttrSpelling FromPasta(pasta::AsmLabelAttrSpelling pasta_val);

enum class AssertCapabilityAttrSpelling : unsigned char;
AssertCapabilityAttrSpelling FromPasta(pasta::AssertCapabilityAttrSpelling pasta_val);

enum class AssumeAlignedAttrSpelling : unsigned char;
AssumeAlignedAttrSpelling FromPasta(pasta::AssumeAlignedAttrSpelling pasta_val);

enum class AssumptionAttrSpelling : unsigned char;
AssumptionAttrSpelling FromPasta(pasta::AssumptionAttrSpelling pasta_val);

enum class AtomicExprAtomicOp : unsigned char;
AtomicExprAtomicOp FromPasta(pasta::AtomicExprAtomicOp pasta_val);

enum class AvailabilityAttrSpelling : unsigned char;
AvailabilityAttrSpelling FromPasta(pasta::AvailabilityAttrSpelling pasta_val);

enum class AvailableOnlyInDefaultEvalMethodAttrSpelling : unsigned char;
AvailableOnlyInDefaultEvalMethodAttrSpelling FromPasta(pasta::AvailableOnlyInDefaultEvalMethodAttrSpelling pasta_val);

enum class BPFPreserveAccessIndexAttrSpelling : unsigned char;
BPFPreserveAccessIndexAttrSpelling FromPasta(pasta::BPFPreserveAccessIndexAttrSpelling pasta_val);

enum class BTFDeclTagAttrSpelling : unsigned char;
BTFDeclTagAttrSpelling FromPasta(pasta::BTFDeclTagAttrSpelling pasta_val);

enum class BTFTypeTagAttrSpelling : unsigned char;
BTFTypeTagAttrSpelling FromPasta(pasta::BTFTypeTagAttrSpelling pasta_val);

enum class BlocksAttrBlockType : unsigned char;
BlocksAttrBlockType FromPasta(pasta::BlocksAttrBlockType pasta_val);

enum class BlocksAttrSpelling : unsigned char;
BlocksAttrSpelling FromPasta(pasta::BlocksAttrSpelling pasta_val);

enum class BuiltinAliasAttrSpelling : unsigned char;
BuiltinAliasAttrSpelling FromPasta(pasta::BuiltinAliasAttrSpelling pasta_val);

enum class BuiltinTypeKind : unsigned short;
BuiltinTypeKind FromPasta(pasta::BuiltinTypeKind pasta_val);

enum class CDeclAttrSpelling : unsigned char;
CDeclAttrSpelling FromPasta(pasta::CDeclAttrSpelling pasta_val);

enum class CFAuditedTransferAttrSpelling : unsigned char;
CFAuditedTransferAttrSpelling FromPasta(pasta::CFAuditedTransferAttrSpelling pasta_val);

enum class CFConsumedAttrSpelling : unsigned char;
CFConsumedAttrSpelling FromPasta(pasta::CFConsumedAttrSpelling pasta_val);

enum class CFGuardAttrGuardArg : unsigned char;
CFGuardAttrGuardArg FromPasta(pasta::CFGuardAttrGuardArg pasta_val);

enum class CFGuardAttrSpelling : unsigned char;
CFGuardAttrSpelling FromPasta(pasta::CFGuardAttrSpelling pasta_val);

enum class CFICanonicalJumpTableAttrSpelling : unsigned char;
CFICanonicalJumpTableAttrSpelling FromPasta(pasta::CFICanonicalJumpTableAttrSpelling pasta_val);

enum class CFReturnsNotRetainedAttrSpelling : unsigned char;
CFReturnsNotRetainedAttrSpelling FromPasta(pasta::CFReturnsNotRetainedAttrSpelling pasta_val);

enum class CFReturnsRetainedAttrSpelling : unsigned char;
CFReturnsRetainedAttrSpelling FromPasta(pasta::CFReturnsRetainedAttrSpelling pasta_val);

enum class CFUnknownTransferAttrSpelling : unsigned char;
CFUnknownTransferAttrSpelling FromPasta(pasta::CFUnknownTransferAttrSpelling pasta_val);

enum class CPUDispatchAttrSpelling : unsigned char;
CPUDispatchAttrSpelling FromPasta(pasta::CPUDispatchAttrSpelling pasta_val);

enum class CPUSpecificAttrSpelling : unsigned char;
CPUSpecificAttrSpelling FromPasta(pasta::CPUSpecificAttrSpelling pasta_val);

enum class CUDAConstantAttrSpelling : unsigned char;
CUDAConstantAttrSpelling FromPasta(pasta::CUDAConstantAttrSpelling pasta_val);

enum class CUDADeviceAttrSpelling : unsigned char;
CUDADeviceAttrSpelling FromPasta(pasta::CUDADeviceAttrSpelling pasta_val);

enum class CUDADeviceBuiltinSurfaceTypeAttrSpelling : unsigned char;
CUDADeviceBuiltinSurfaceTypeAttrSpelling FromPasta(pasta::CUDADeviceBuiltinSurfaceTypeAttrSpelling pasta_val);

enum class CUDADeviceBuiltinTextureTypeAttrSpelling : unsigned char;
CUDADeviceBuiltinTextureTypeAttrSpelling FromPasta(pasta::CUDADeviceBuiltinTextureTypeAttrSpelling pasta_val);

enum class CUDAGlobalAttrSpelling : unsigned char;
CUDAGlobalAttrSpelling FromPasta(pasta::CUDAGlobalAttrSpelling pasta_val);

enum class CUDAHostAttrSpelling : unsigned char;
CUDAHostAttrSpelling FromPasta(pasta::CUDAHostAttrSpelling pasta_val);

enum class CUDALaunchBoundsAttrSpelling : unsigned char;
CUDALaunchBoundsAttrSpelling FromPasta(pasta::CUDALaunchBoundsAttrSpelling pasta_val);

enum class CUDASharedAttrSpelling : unsigned char;
CUDASharedAttrSpelling FromPasta(pasta::CUDASharedAttrSpelling pasta_val);

enum class CXX11NoReturnAttrSpelling : unsigned char;
CXX11NoReturnAttrSpelling FromPasta(pasta::CXX11NoReturnAttrSpelling pasta_val);

enum class CXXConstructExprConstructionKind : unsigned char;
CXXConstructExprConstructionKind FromPasta(pasta::CXXConstructExprConstructionKind pasta_val);

enum class CXXNewExprInitializationStyle : unsigned char;
CXXNewExprInitializationStyle FromPasta(pasta::CXXNewExprInitializationStyle pasta_val);

enum class CXXRecordDeclLambdaDependencyKind : unsigned char;
CXXRecordDeclLambdaDependencyKind FromPasta(pasta::CXXRecordDeclLambdaDependencyKind pasta_val);

enum class CallExprADLCallKind : unsigned char;
CallExprADLCallKind FromPasta(pasta::CallExprADLCallKind pasta_val);

enum class CallableWhenAttrConsumedState : unsigned char;
CallableWhenAttrConsumedState FromPasta(pasta::CallableWhenAttrConsumedState pasta_val);

enum class CallableWhenAttrSpelling : unsigned char;
CallableWhenAttrSpelling FromPasta(pasta::CallableWhenAttrSpelling pasta_val);

enum class CallbackAttrSpelling : unsigned char;
CallbackAttrSpelling FromPasta(pasta::CallbackAttrSpelling pasta_val);

enum class CalledOnceAttrSpelling : unsigned char;
CalledOnceAttrSpelling FromPasta(pasta::CalledOnceAttrSpelling pasta_val);

enum class CapabilityAttrSpelling : unsigned char;
CapabilityAttrSpelling FromPasta(pasta::CapabilityAttrSpelling pasta_val);

enum class CapturedStmtVariableCaptureKind : unsigned char;
CapturedStmtVariableCaptureKind FromPasta(pasta::CapturedStmtVariableCaptureKind pasta_val);

enum class CarriesDependencyAttrSpelling : unsigned char;
CarriesDependencyAttrSpelling FromPasta(pasta::CarriesDependencyAttrSpelling pasta_val);

enum class CharacterLiteralCharacterKind : unsigned char;
CharacterLiteralCharacterKind FromPasta(pasta::CharacterLiteralCharacterKind pasta_val);

enum class CleanupAttrSpelling : unsigned char;
CleanupAttrSpelling FromPasta(pasta::CleanupAttrSpelling pasta_val);

enum class ColdAttrSpelling : unsigned char;
ColdAttrSpelling FromPasta(pasta::ColdAttrSpelling pasta_val);

enum class CommonAttrSpelling : unsigned char;
CommonAttrSpelling FromPasta(pasta::CommonAttrSpelling pasta_val);

enum class ConstAttrSpelling : unsigned char;
ConstAttrSpelling FromPasta(pasta::ConstAttrSpelling pasta_val);

enum class ConstInitAttrSpelling : unsigned char;
ConstInitAttrSpelling FromPasta(pasta::ConstInitAttrSpelling pasta_val);

enum class ConstantExprResultStorageKind : unsigned char;
ConstantExprResultStorageKind FromPasta(pasta::ConstantExprResultStorageKind pasta_val);

enum class ConstructorAttrSpelling : unsigned char;
ConstructorAttrSpelling FromPasta(pasta::ConstructorAttrSpelling pasta_val);

enum class ConsumableAttrConsumedState : unsigned char;
ConsumableAttrConsumedState FromPasta(pasta::ConsumableAttrConsumedState pasta_val);

enum class ConsumableAttrSpelling : unsigned char;
ConsumableAttrSpelling FromPasta(pasta::ConsumableAttrSpelling pasta_val);

enum class ConsumableAutoCastAttrSpelling : unsigned char;
ConsumableAutoCastAttrSpelling FromPasta(pasta::ConsumableAutoCastAttrSpelling pasta_val);

enum class ConsumableSetOnReadAttrSpelling : unsigned char;
ConsumableSetOnReadAttrSpelling FromPasta(pasta::ConsumableSetOnReadAttrSpelling pasta_val);

enum class ConvergentAttrSpelling : unsigned char;
ConvergentAttrSpelling FromPasta(pasta::ConvergentAttrSpelling pasta_val);

enum class DLLExportAttrSpelling : unsigned char;
DLLExportAttrSpelling FromPasta(pasta::DLLExportAttrSpelling pasta_val);

enum class DLLImportAttrSpelling : unsigned char;
DLLImportAttrSpelling FromPasta(pasta::DLLImportAttrSpelling pasta_val);

enum class DeclFriendObjectKind : unsigned char;
DeclFriendObjectKind FromPasta(pasta::DeclFriendObjectKind pasta_val);

enum class DeclIdentifierNamespace : unsigned char;
DeclIdentifierNamespace FromPasta(pasta::DeclIdentifierNamespace pasta_val);

enum class DeclModuleOwnershipKind : unsigned char;
DeclModuleOwnershipKind FromPasta(pasta::DeclModuleOwnershipKind pasta_val);

enum class DeclObjCDeclQualifier : unsigned char;
DeclObjCDeclQualifier FromPasta(pasta::DeclObjCDeclQualifier pasta_val);

enum class DeprecatedAttrSpelling : unsigned char;
DeprecatedAttrSpelling FromPasta(pasta::DeprecatedAttrSpelling pasta_val);

enum class DestructorAttrSpelling : unsigned char;
DestructorAttrSpelling FromPasta(pasta::DestructorAttrSpelling pasta_val);

enum class DiagnoseAsBuiltinAttrSpelling : unsigned char;
DiagnoseAsBuiltinAttrSpelling FromPasta(pasta::DiagnoseAsBuiltinAttrSpelling pasta_val);

enum class DiagnoseIfAttrDiagnosticType : unsigned char;
DiagnoseIfAttrDiagnosticType FromPasta(pasta::DiagnoseIfAttrDiagnosticType pasta_val);

enum class DisableSanitizerInstrumentationAttrSpelling : unsigned char;
DisableSanitizerInstrumentationAttrSpelling FromPasta(pasta::DisableSanitizerInstrumentationAttrSpelling pasta_val);

enum class DisableTailCallsAttrSpelling : unsigned char;
DisableTailCallsAttrSpelling FromPasta(pasta::DisableTailCallsAttrSpelling pasta_val);

enum class EnforceTCBAttrSpelling : unsigned char;
EnforceTCBAttrSpelling FromPasta(pasta::EnforceTCBAttrSpelling pasta_val);

enum class EnforceTCBLeafAttrSpelling : unsigned char;
EnforceTCBLeafAttrSpelling FromPasta(pasta::EnforceTCBLeafAttrSpelling pasta_val);

enum class EnumExtensibilityAttrKind : unsigned char;
EnumExtensibilityAttrKind FromPasta(pasta::EnumExtensibilityAttrKind pasta_val);

enum class EnumExtensibilityAttrSpelling : unsigned char;
EnumExtensibilityAttrSpelling FromPasta(pasta::EnumExtensibilityAttrSpelling pasta_val);

enum class ErrorAttrSpelling : unsigned char;
ErrorAttrSpelling FromPasta(pasta::ErrorAttrSpelling pasta_val);

enum class ExcludeFromExplicitInstantiationAttrSpelling : unsigned char;
ExcludeFromExplicitInstantiationAttrSpelling FromPasta(pasta::ExcludeFromExplicitInstantiationAttrSpelling pasta_val);

enum class ExprConstantExprKind : unsigned char;
ExprConstantExprKind FromPasta(pasta::ExprConstantExprKind pasta_val);

enum class ExprLValueClassification : unsigned char;
ExprLValueClassification FromPasta(pasta::ExprLValueClassification pasta_val);

enum class ExprNullPointerConstantKind : unsigned char;
ExprNullPointerConstantKind FromPasta(pasta::ExprNullPointerConstantKind pasta_val);

enum class ExprNullPointerConstantValueDependence : unsigned char;
ExprNullPointerConstantValueDependence FromPasta(pasta::ExprNullPointerConstantValueDependence pasta_val);

enum class ExprSideEffectsKind : unsigned char;
ExprSideEffectsKind FromPasta(pasta::ExprSideEffectsKind pasta_val);

enum class ExprisModifiableLvalueResult : unsigned char;
ExprisModifiableLvalueResult FromPasta(pasta::ExprisModifiableLvalueResult pasta_val);

enum class ExternalSourceSymbolAttrSpelling : unsigned char;
ExternalSourceSymbolAttrSpelling FromPasta(pasta::ExternalSourceSymbolAttrSpelling pasta_val);

enum class FallThroughAttrSpelling : unsigned char;
FallThroughAttrSpelling FromPasta(pasta::FallThroughAttrSpelling pasta_val);

enum class FastCallAttrSpelling : unsigned char;
FastCallAttrSpelling FromPasta(pasta::FastCallAttrSpelling pasta_val);

enum class FinalAttrSpelling : unsigned char;
FinalAttrSpelling FromPasta(pasta::FinalAttrSpelling pasta_val);

enum class FlagEnumAttrSpelling : unsigned char;
FlagEnumAttrSpelling FromPasta(pasta::FlagEnumAttrSpelling pasta_val);

enum class FlattenAttrSpelling : unsigned char;
FlattenAttrSpelling FromPasta(pasta::FlattenAttrSpelling pasta_val);

enum class FormatArgAttrSpelling : unsigned char;
FormatArgAttrSpelling FromPasta(pasta::FormatArgAttrSpelling pasta_val);

enum class FormatAttrSpelling : unsigned char;
FormatAttrSpelling FromPasta(pasta::FormatAttrSpelling pasta_val);

enum class FunctionDeclTemplatedKind : unsigned char;
FunctionDeclTemplatedKind FromPasta(pasta::FunctionDeclTemplatedKind pasta_val);

enum class FunctionReturnThunksAttrKind : unsigned char;
FunctionReturnThunksAttrKind FromPasta(pasta::FunctionReturnThunksAttrKind pasta_val);

enum class FunctionReturnThunksAttrSpelling : unsigned char;
FunctionReturnThunksAttrSpelling FromPasta(pasta::FunctionReturnThunksAttrSpelling pasta_val);

enum class GNUInlineAttrSpelling : unsigned char;
GNUInlineAttrSpelling FromPasta(pasta::GNUInlineAttrSpelling pasta_val);

enum class GuardedVarAttrSpelling : unsigned char;
GuardedVarAttrSpelling FromPasta(pasta::GuardedVarAttrSpelling pasta_val);

enum class HIPManagedAttrSpelling : unsigned char;
HIPManagedAttrSpelling FromPasta(pasta::HIPManagedAttrSpelling pasta_val);

enum class HLSLResourceAttrResourceClass : unsigned char;
HLSLResourceAttrResourceClass FromPasta(pasta::HLSLResourceAttrResourceClass pasta_val);

enum class HLSLResourceAttrResourceKind : unsigned char;
HLSLResourceAttrResourceKind FromPasta(pasta::HLSLResourceAttrResourceKind pasta_val);

enum class HLSLShaderAttrShaderType : unsigned char;
HLSLShaderAttrShaderType FromPasta(pasta::HLSLShaderAttrShaderType pasta_val);

enum class HotAttrSpelling : unsigned char;
HotAttrSpelling FromPasta(pasta::HotAttrSpelling pasta_val);

enum class IBActionAttrSpelling : unsigned char;
IBActionAttrSpelling FromPasta(pasta::IBActionAttrSpelling pasta_val);

enum class IBOutletAttrSpelling : unsigned char;
IBOutletAttrSpelling FromPasta(pasta::IBOutletAttrSpelling pasta_val);

enum class IBOutletCollectionAttrSpelling : unsigned char;
IBOutletCollectionAttrSpelling FromPasta(pasta::IBOutletCollectionAttrSpelling pasta_val);

enum class IFuncAttrSpelling : unsigned char;
IFuncAttrSpelling FromPasta(pasta::IFuncAttrSpelling pasta_val);

enum class ImplicitCastExprOnStack : unsigned char;
ImplicitCastExprOnStack FromPasta(pasta::ImplicitCastExprOnStack pasta_val);

enum class ImplicitParamDeclImplicitParamKind : unsigned char;
ImplicitParamDeclImplicitParamKind FromPasta(pasta::ImplicitParamDeclImplicitParamKind pasta_val);

enum class InitPriorityAttrSpelling : unsigned char;
InitPriorityAttrSpelling FromPasta(pasta::InitPriorityAttrSpelling pasta_val);

enum class IntelOclBiccAttrSpelling : unsigned char;
IntelOclBiccAttrSpelling FromPasta(pasta::IntelOclBiccAttrSpelling pasta_val);

enum class InternalLinkageAttrSpelling : unsigned char;
InternalLinkageAttrSpelling FromPasta(pasta::InternalLinkageAttrSpelling pasta_val);

enum class LTOVisibilityPublicAttrSpelling : unsigned char;
LTOVisibilityPublicAttrSpelling FromPasta(pasta::LTOVisibilityPublicAttrSpelling pasta_val);

enum class LeafAttrSpelling : unsigned char;
LeafAttrSpelling FromPasta(pasta::LeafAttrSpelling pasta_val);

enum class LifetimeBoundAttrSpelling : unsigned char;
LifetimeBoundAttrSpelling FromPasta(pasta::LifetimeBoundAttrSpelling pasta_val);

enum class LikelyAttrSpelling : unsigned char;
LikelyAttrSpelling FromPasta(pasta::LikelyAttrSpelling pasta_val);

enum class LinkageSpecDeclLanguageIDs : unsigned char;
LinkageSpecDeclLanguageIDs FromPasta(pasta::LinkageSpecDeclLanguageIDs pasta_val);

enum class LoaderUninitializedAttrSpelling : unsigned char;
LoaderUninitializedAttrSpelling FromPasta(pasta::LoaderUninitializedAttrSpelling pasta_val);

enum class LoopHintAttrLoopHintState : unsigned char;
LoopHintAttrLoopHintState FromPasta(pasta::LoopHintAttrLoopHintState pasta_val);

enum class LoopHintAttrOptionType : unsigned char;
LoopHintAttrOptionType FromPasta(pasta::LoopHintAttrOptionType pasta_val);

enum class LoopHintAttrSpelling : unsigned char;
LoopHintAttrSpelling FromPasta(pasta::LoopHintAttrSpelling pasta_val);

enum class MIGServerRoutineAttrSpelling : unsigned char;
MIGServerRoutineAttrSpelling FromPasta(pasta::MIGServerRoutineAttrSpelling pasta_val);

enum class MSABIAttrSpelling : unsigned char;
MSABIAttrSpelling FromPasta(pasta::MSABIAttrSpelling pasta_val);

enum class MSInheritanceAttrSpelling : unsigned char;
MSInheritanceAttrSpelling FromPasta(pasta::MSInheritanceAttrSpelling pasta_val);

enum class MSP430InterruptAttrSpelling : unsigned char;
MSP430InterruptAttrSpelling FromPasta(pasta::MSP430InterruptAttrSpelling pasta_val);

enum class MSStructAttrSpelling : unsigned char;
MSStructAttrSpelling FromPasta(pasta::MSStructAttrSpelling pasta_val);

enum class MayAliasAttrSpelling : unsigned char;
MayAliasAttrSpelling FromPasta(pasta::MayAliasAttrSpelling pasta_val);

enum class MaybeUndefAttrSpelling : unsigned char;
MaybeUndefAttrSpelling FromPasta(pasta::MaybeUndefAttrSpelling pasta_val);

enum class MicroMipsAttrSpelling : unsigned char;
MicroMipsAttrSpelling FromPasta(pasta::MicroMipsAttrSpelling pasta_val);

enum class MinSizeAttrSpelling : unsigned char;
MinSizeAttrSpelling FromPasta(pasta::MinSizeAttrSpelling pasta_val);

enum class MinVectorWidthAttrSpelling : unsigned char;
MinVectorWidthAttrSpelling FromPasta(pasta::MinVectorWidthAttrSpelling pasta_val);

enum class Mips16AttrSpelling : unsigned char;
Mips16AttrSpelling FromPasta(pasta::Mips16AttrSpelling pasta_val);

enum class MipsInterruptAttrInterruptType : unsigned char;
MipsInterruptAttrInterruptType FromPasta(pasta::MipsInterruptAttrInterruptType pasta_val);

enum class MipsInterruptAttrSpelling : unsigned char;
MipsInterruptAttrSpelling FromPasta(pasta::MipsInterruptAttrSpelling pasta_val);

enum class MipsLongCallAttrSpelling : unsigned char;
MipsLongCallAttrSpelling FromPasta(pasta::MipsLongCallAttrSpelling pasta_val);

enum class MipsShortCallAttrSpelling : unsigned char;
MipsShortCallAttrSpelling FromPasta(pasta::MipsShortCallAttrSpelling pasta_val);

enum class ModeAttrSpelling : unsigned char;
ModeAttrSpelling FromPasta(pasta::ModeAttrSpelling pasta_val);

enum class MustTailAttrSpelling : unsigned char;
MustTailAttrSpelling FromPasta(pasta::MustTailAttrSpelling pasta_val);

enum class NSConsumedAttrSpelling : unsigned char;
NSConsumedAttrSpelling FromPasta(pasta::NSConsumedAttrSpelling pasta_val);

enum class NSConsumesSelfAttrSpelling : unsigned char;
NSConsumesSelfAttrSpelling FromPasta(pasta::NSConsumesSelfAttrSpelling pasta_val);

enum class NSReturnsAutoreleasedAttrSpelling : unsigned char;
NSReturnsAutoreleasedAttrSpelling FromPasta(pasta::NSReturnsAutoreleasedAttrSpelling pasta_val);

enum class NSReturnsNotRetainedAttrSpelling : unsigned char;
NSReturnsNotRetainedAttrSpelling FromPasta(pasta::NSReturnsNotRetainedAttrSpelling pasta_val);

enum class NSReturnsRetainedAttrSpelling : unsigned char;
NSReturnsRetainedAttrSpelling FromPasta(pasta::NSReturnsRetainedAttrSpelling pasta_val);

enum class NVPTXKernelAttrSpelling : unsigned char;
NVPTXKernelAttrSpelling FromPasta(pasta::NVPTXKernelAttrSpelling pasta_val);

enum class NakedAttrSpelling : unsigned char;
NakedAttrSpelling FromPasta(pasta::NakedAttrSpelling pasta_val);

enum class NamedDeclExplicitVisibilityKind : unsigned char;
NamedDeclExplicitVisibilityKind FromPasta(pasta::NamedDeclExplicitVisibilityKind pasta_val);

enum class NoBuiltinAttrSpelling : unsigned char;
NoBuiltinAttrSpelling FromPasta(pasta::NoBuiltinAttrSpelling pasta_val);

enum class NoCommonAttrSpelling : unsigned char;
NoCommonAttrSpelling FromPasta(pasta::NoCommonAttrSpelling pasta_val);

enum class NoDebugAttrSpelling : unsigned char;
NoDebugAttrSpelling FromPasta(pasta::NoDebugAttrSpelling pasta_val);

enum class NoDerefAttrSpelling : unsigned char;
NoDerefAttrSpelling FromPasta(pasta::NoDerefAttrSpelling pasta_val);

enum class NoDestroyAttrSpelling : unsigned char;
NoDestroyAttrSpelling FromPasta(pasta::NoDestroyAttrSpelling pasta_val);

enum class NoDuplicateAttrSpelling : unsigned char;
NoDuplicateAttrSpelling FromPasta(pasta::NoDuplicateAttrSpelling pasta_val);

enum class NoEscapeAttrSpelling : unsigned char;
NoEscapeAttrSpelling FromPasta(pasta::NoEscapeAttrSpelling pasta_val);

enum class NoInlineAttrSpelling : unsigned char;
NoInlineAttrSpelling FromPasta(pasta::NoInlineAttrSpelling pasta_val);

enum class NoInstrumentFunctionAttrSpelling : unsigned char;
NoInstrumentFunctionAttrSpelling FromPasta(pasta::NoInstrumentFunctionAttrSpelling pasta_val);

enum class NoMergeAttrSpelling : unsigned char;
NoMergeAttrSpelling FromPasta(pasta::NoMergeAttrSpelling pasta_val);

enum class NoMicroMipsAttrSpelling : unsigned char;
NoMicroMipsAttrSpelling FromPasta(pasta::NoMicroMipsAttrSpelling pasta_val);

enum class NoMips16AttrSpelling : unsigned char;
NoMips16AttrSpelling FromPasta(pasta::NoMips16AttrSpelling pasta_val);

enum class NoProfileFunctionAttrSpelling : unsigned char;
NoProfileFunctionAttrSpelling FromPasta(pasta::NoProfileFunctionAttrSpelling pasta_val);

enum class NoRandomizeLayoutAttrSpelling : unsigned char;
NoRandomizeLayoutAttrSpelling FromPasta(pasta::NoRandomizeLayoutAttrSpelling pasta_val);

enum class NoReturnAttrSpelling : unsigned char;
NoReturnAttrSpelling FromPasta(pasta::NoReturnAttrSpelling pasta_val);

enum class NoSanitizeAttrSpelling : unsigned char;
NoSanitizeAttrSpelling FromPasta(pasta::NoSanitizeAttrSpelling pasta_val);

enum class NoSpeculativeLoadHardeningAttrSpelling : unsigned char;
NoSpeculativeLoadHardeningAttrSpelling FromPasta(pasta::NoSpeculativeLoadHardeningAttrSpelling pasta_val);

enum class NoSplitStackAttrSpelling : unsigned char;
NoSplitStackAttrSpelling FromPasta(pasta::NoSplitStackAttrSpelling pasta_val);

enum class NoStackProtectorAttrSpelling : unsigned char;
NoStackProtectorAttrSpelling FromPasta(pasta::NoStackProtectorAttrSpelling pasta_val);

enum class NoThreadSafetyAnalysisAttrSpelling : unsigned char;
NoThreadSafetyAnalysisAttrSpelling FromPasta(pasta::NoThreadSafetyAnalysisAttrSpelling pasta_val);

enum class NoThrowAttrSpelling : unsigned char;
NoThrowAttrSpelling FromPasta(pasta::NoThrowAttrSpelling pasta_val);

enum class NoUwtableAttrSpelling : unsigned char;
NoUwtableAttrSpelling FromPasta(pasta::NoUwtableAttrSpelling pasta_val);

enum class NonNullAttrSpelling : unsigned char;
NonNullAttrSpelling FromPasta(pasta::NonNullAttrSpelling pasta_val);

enum class NotTailCalledAttrSpelling : unsigned char;
NotTailCalledAttrSpelling FromPasta(pasta::NotTailCalledAttrSpelling pasta_val);

enum class OMPAllocateDeclAttrAllocatorTypeTy : unsigned char;
OMPAllocateDeclAttrAllocatorTypeTy FromPasta(pasta::OMPAllocateDeclAttrAllocatorTypeTy pasta_val);

enum class OMPDeclareReductionDeclInitKind : unsigned char;
OMPDeclareReductionDeclInitKind FromPasta(pasta::OMPDeclareReductionDeclInitKind pasta_val);

enum class OMPDeclareSimdDeclAttrBranchStateTy : unsigned char;
OMPDeclareSimdDeclAttrBranchStateTy FromPasta(pasta::OMPDeclareSimdDeclAttrBranchStateTy pasta_val);

enum class OMPDeclareTargetDeclAttrDevTypeTy : unsigned char;
OMPDeclareTargetDeclAttrDevTypeTy FromPasta(pasta::OMPDeclareTargetDeclAttrDevTypeTy pasta_val);

enum class OMPDeclareTargetDeclAttrMapTypeTy : unsigned char;
OMPDeclareTargetDeclAttrMapTypeTy FromPasta(pasta::OMPDeclareTargetDeclAttrMapTypeTy pasta_val);

enum class OSConsumedAttrSpelling : unsigned char;
OSConsumedAttrSpelling FromPasta(pasta::OSConsumedAttrSpelling pasta_val);

enum class OSConsumesThisAttrSpelling : unsigned char;
OSConsumesThisAttrSpelling FromPasta(pasta::OSConsumesThisAttrSpelling pasta_val);

enum class OSReturnsNotRetainedAttrSpelling : unsigned char;
OSReturnsNotRetainedAttrSpelling FromPasta(pasta::OSReturnsNotRetainedAttrSpelling pasta_val);

enum class OSReturnsRetainedAttrSpelling : unsigned char;
OSReturnsRetainedAttrSpelling FromPasta(pasta::OSReturnsRetainedAttrSpelling pasta_val);

enum class OSReturnsRetainedOnNonZeroAttrSpelling : unsigned char;
OSReturnsRetainedOnNonZeroAttrSpelling FromPasta(pasta::OSReturnsRetainedOnNonZeroAttrSpelling pasta_val);

enum class OSReturnsRetainedOnZeroAttrSpelling : unsigned char;
OSReturnsRetainedOnZeroAttrSpelling FromPasta(pasta::OSReturnsRetainedOnZeroAttrSpelling pasta_val);

enum class ObjCBoxableAttrSpelling : unsigned char;
ObjCBoxableAttrSpelling FromPasta(pasta::ObjCBoxableAttrSpelling pasta_val);

enum class ObjCBridgeAttrSpelling : unsigned char;
ObjCBridgeAttrSpelling FromPasta(pasta::ObjCBridgeAttrSpelling pasta_val);

enum class ObjCBridgeMutableAttrSpelling : unsigned char;
ObjCBridgeMutableAttrSpelling FromPasta(pasta::ObjCBridgeMutableAttrSpelling pasta_val);

enum class ObjCBridgeRelatedAttrSpelling : unsigned char;
ObjCBridgeRelatedAttrSpelling FromPasta(pasta::ObjCBridgeRelatedAttrSpelling pasta_val);

enum class ObjCClassStubAttrSpelling : unsigned char;
ObjCClassStubAttrSpelling FromPasta(pasta::ObjCClassStubAttrSpelling pasta_val);

enum class ObjCDesignatedInitializerAttrSpelling : unsigned char;
ObjCDesignatedInitializerAttrSpelling FromPasta(pasta::ObjCDesignatedInitializerAttrSpelling pasta_val);

enum class ObjCDirectAttrSpelling : unsigned char;
ObjCDirectAttrSpelling FromPasta(pasta::ObjCDirectAttrSpelling pasta_val);

enum class ObjCDirectMembersAttrSpelling : unsigned char;
ObjCDirectMembersAttrSpelling FromPasta(pasta::ObjCDirectMembersAttrSpelling pasta_val);

enum class ObjCExceptionAttrSpelling : unsigned char;
ObjCExceptionAttrSpelling FromPasta(pasta::ObjCExceptionAttrSpelling pasta_val);

enum class ObjCExplicitProtocolImplAttrSpelling : unsigned char;
ObjCExplicitProtocolImplAttrSpelling FromPasta(pasta::ObjCExplicitProtocolImplAttrSpelling pasta_val);

enum class ObjCExternallyRetainedAttrSpelling : unsigned char;
ObjCExternallyRetainedAttrSpelling FromPasta(pasta::ObjCExternallyRetainedAttrSpelling pasta_val);

enum class ObjCGCAttrSpelling : unsigned char;
ObjCGCAttrSpelling FromPasta(pasta::ObjCGCAttrSpelling pasta_val);

enum class ObjCIndependentClassAttrSpelling : unsigned char;
ObjCIndependentClassAttrSpelling FromPasta(pasta::ObjCIndependentClassAttrSpelling pasta_val);

enum class ObjCIvarDeclAccessControl : unsigned char;
ObjCIvarDeclAccessControl FromPasta(pasta::ObjCIvarDeclAccessControl pasta_val);

enum class ObjCMessageExprReceiverKind : unsigned char;
ObjCMessageExprReceiverKind FromPasta(pasta::ObjCMessageExprReceiverKind pasta_val);

enum class ObjCMethodDeclImplementationControl : unsigned char;
ObjCMethodDeclImplementationControl FromPasta(pasta::ObjCMethodDeclImplementationControl pasta_val);

enum class ObjCMethodFamilyAttrFamilyKind : unsigned char;
ObjCMethodFamilyAttrFamilyKind FromPasta(pasta::ObjCMethodFamilyAttrFamilyKind pasta_val);

enum class ObjCMethodFamilyAttrSpelling : unsigned char;
ObjCMethodFamilyAttrSpelling FromPasta(pasta::ObjCMethodFamilyAttrSpelling pasta_val);

enum class ObjCNSObjectAttrSpelling : unsigned char;
ObjCNSObjectAttrSpelling FromPasta(pasta::ObjCNSObjectAttrSpelling pasta_val);

enum class ObjCNonLazyClassAttrSpelling : unsigned char;
ObjCNonLazyClassAttrSpelling FromPasta(pasta::ObjCNonLazyClassAttrSpelling pasta_val);

enum class ObjCNonRuntimeProtocolAttrSpelling : unsigned char;
ObjCNonRuntimeProtocolAttrSpelling FromPasta(pasta::ObjCNonRuntimeProtocolAttrSpelling pasta_val);

enum class ObjCOwnershipAttrSpelling : unsigned char;
ObjCOwnershipAttrSpelling FromPasta(pasta::ObjCOwnershipAttrSpelling pasta_val);

enum class ObjCPreciseLifetimeAttrSpelling : unsigned char;
ObjCPreciseLifetimeAttrSpelling FromPasta(pasta::ObjCPreciseLifetimeAttrSpelling pasta_val);

enum class ObjCPropertyDeclPropertyControl : unsigned char;
ObjCPropertyDeclPropertyControl FromPasta(pasta::ObjCPropertyDeclPropertyControl pasta_val);

enum class ObjCPropertyDeclSetterKind : unsigned char;
ObjCPropertyDeclSetterKind FromPasta(pasta::ObjCPropertyDeclSetterKind pasta_val);

enum class ObjCPropertyImplDeclKind : unsigned char;
ObjCPropertyImplDeclKind FromPasta(pasta::ObjCPropertyImplDeclKind pasta_val);

enum class ObjCRequiresPropertyDefsAttrSpelling : unsigned char;
ObjCRequiresPropertyDefsAttrSpelling FromPasta(pasta::ObjCRequiresPropertyDefsAttrSpelling pasta_val);

enum class ObjCRequiresSuperAttrSpelling : unsigned char;
ObjCRequiresSuperAttrSpelling FromPasta(pasta::ObjCRequiresSuperAttrSpelling pasta_val);

enum class ObjCReturnsInnerPointerAttrSpelling : unsigned char;
ObjCReturnsInnerPointerAttrSpelling FromPasta(pasta::ObjCReturnsInnerPointerAttrSpelling pasta_val);

enum class ObjCRootClassAttrSpelling : unsigned char;
ObjCRootClassAttrSpelling FromPasta(pasta::ObjCRootClassAttrSpelling pasta_val);

enum class ObjCRuntimeNameAttrSpelling : unsigned char;
ObjCRuntimeNameAttrSpelling FromPasta(pasta::ObjCRuntimeNameAttrSpelling pasta_val);

enum class ObjCRuntimeVisibleAttrSpelling : unsigned char;
ObjCRuntimeVisibleAttrSpelling FromPasta(pasta::ObjCRuntimeVisibleAttrSpelling pasta_val);

enum class ObjCSubclassingRestrictedAttrSpelling : unsigned char;
ObjCSubclassingRestrictedAttrSpelling FromPasta(pasta::ObjCSubclassingRestrictedAttrSpelling pasta_val);

enum class OpenCLAccessAttrSpelling : unsigned char;
OpenCLAccessAttrSpelling FromPasta(pasta::OpenCLAccessAttrSpelling pasta_val);

enum class OpenCLConstantAddressSpaceAttrSpelling : unsigned char;
OpenCLConstantAddressSpaceAttrSpelling FromPasta(pasta::OpenCLConstantAddressSpaceAttrSpelling pasta_val);

enum class OpenCLGenericAddressSpaceAttrSpelling : unsigned char;
OpenCLGenericAddressSpaceAttrSpelling FromPasta(pasta::OpenCLGenericAddressSpaceAttrSpelling pasta_val);

enum class OpenCLGlobalAddressSpaceAttrSpelling : unsigned char;
OpenCLGlobalAddressSpaceAttrSpelling FromPasta(pasta::OpenCLGlobalAddressSpaceAttrSpelling pasta_val);

enum class OpenCLGlobalDeviceAddressSpaceAttrSpelling : unsigned char;
OpenCLGlobalDeviceAddressSpaceAttrSpelling FromPasta(pasta::OpenCLGlobalDeviceAddressSpaceAttrSpelling pasta_val);

enum class OpenCLGlobalHostAddressSpaceAttrSpelling : unsigned char;
OpenCLGlobalHostAddressSpaceAttrSpelling FromPasta(pasta::OpenCLGlobalHostAddressSpaceAttrSpelling pasta_val);

enum class OpenCLKernelAttrSpelling : unsigned char;
OpenCLKernelAttrSpelling FromPasta(pasta::OpenCLKernelAttrSpelling pasta_val);

enum class OpenCLLocalAddressSpaceAttrSpelling : unsigned char;
OpenCLLocalAddressSpaceAttrSpelling FromPasta(pasta::OpenCLLocalAddressSpaceAttrSpelling pasta_val);

enum class OpenCLPrivateAddressSpaceAttrSpelling : unsigned char;
OpenCLPrivateAddressSpaceAttrSpelling FromPasta(pasta::OpenCLPrivateAddressSpaceAttrSpelling pasta_val);

enum class OptimizeNoneAttrSpelling : unsigned char;
OptimizeNoneAttrSpelling FromPasta(pasta::OptimizeNoneAttrSpelling pasta_val);

enum class OverloadableAttrSpelling : unsigned char;
OverloadableAttrSpelling FromPasta(pasta::OverloadableAttrSpelling pasta_val);

enum class OwnershipAttrOwnershipKind : unsigned char;
OwnershipAttrOwnershipKind FromPasta(pasta::OwnershipAttrOwnershipKind pasta_val);

enum class OwnershipAttrSpelling : unsigned char;
OwnershipAttrSpelling FromPasta(pasta::OwnershipAttrSpelling pasta_val);

enum class PackedAttrSpelling : unsigned char;
PackedAttrSpelling FromPasta(pasta::PackedAttrSpelling pasta_val);

enum class ParamTypestateAttrConsumedState : unsigned char;
ParamTypestateAttrConsumedState FromPasta(pasta::ParamTypestateAttrConsumedState pasta_val);

enum class ParamTypestateAttrSpelling : unsigned char;
ParamTypestateAttrSpelling FromPasta(pasta::ParamTypestateAttrSpelling pasta_val);

enum class PascalAttrSpelling : unsigned char;
PascalAttrSpelling FromPasta(pasta::PascalAttrSpelling pasta_val);

enum class PassObjectSizeAttrSpelling : unsigned char;
PassObjectSizeAttrSpelling FromPasta(pasta::PassObjectSizeAttrSpelling pasta_val);

enum class PatchableFunctionEntryAttrSpelling : unsigned char;
PatchableFunctionEntryAttrSpelling FromPasta(pasta::PatchableFunctionEntryAttrSpelling pasta_val);

enum class PcsAttrPCSType : unsigned char;
PcsAttrPCSType FromPasta(pasta::PcsAttrPCSType pasta_val);

enum class PcsAttrSpelling : unsigned char;
PcsAttrSpelling FromPasta(pasta::PcsAttrSpelling pasta_val);

enum class PredefinedExprIdentKind : unsigned char;
PredefinedExprIdentKind FromPasta(pasta::PredefinedExprIdentKind pasta_val);

enum class PreferredNameAttrSpelling : unsigned char;
PreferredNameAttrSpelling FromPasta(pasta::PreferredNameAttrSpelling pasta_val);

enum class PreserveAllAttrSpelling : unsigned char;
PreserveAllAttrSpelling FromPasta(pasta::PreserveAllAttrSpelling pasta_val);

enum class PreserveMostAttrSpelling : unsigned char;
PreserveMostAttrSpelling FromPasta(pasta::PreserveMostAttrSpelling pasta_val);

enum class PtGuardedVarAttrSpelling : unsigned char;
PtGuardedVarAttrSpelling FromPasta(pasta::PtGuardedVarAttrSpelling pasta_val);

enum class PureAttrSpelling : unsigned char;
PureAttrSpelling FromPasta(pasta::PureAttrSpelling pasta_val);

enum class QualifiedTypeDestructionKind : unsigned char;
QualifiedTypeDestructionKind FromPasta(pasta::QualifiedTypeDestructionKind pasta_val);

enum class QualifiedTypePrimitiveCopyKind : unsigned char;
QualifiedTypePrimitiveCopyKind FromPasta(pasta::QualifiedTypePrimitiveCopyKind pasta_val);

enum class QualifiedTypePrimitiveDefaultInitializeKind : unsigned char;
QualifiedTypePrimitiveDefaultInitializeKind FromPasta(pasta::QualifiedTypePrimitiveDefaultInitializeKind pasta_val);

enum class RISCVInterruptAttrInterruptType : unsigned char;
RISCVInterruptAttrInterruptType FromPasta(pasta::RISCVInterruptAttrInterruptType pasta_val);

enum class RISCVInterruptAttrSpelling : unsigned char;
RISCVInterruptAttrSpelling FromPasta(pasta::RISCVInterruptAttrSpelling pasta_val);

enum class RandomizeLayoutAttrSpelling : unsigned char;
RandomizeLayoutAttrSpelling FromPasta(pasta::RandomizeLayoutAttrSpelling pasta_val);

enum class ReadOnlyPlacementAttrSpelling : unsigned char;
ReadOnlyPlacementAttrSpelling FromPasta(pasta::ReadOnlyPlacementAttrSpelling pasta_val);

enum class RecordDeclArgPassingKind : unsigned char;
RecordDeclArgPassingKind FromPasta(pasta::RecordDeclArgPassingKind pasta_val);

enum class RegCallAttrSpelling : unsigned char;
RegCallAttrSpelling FromPasta(pasta::RegCallAttrSpelling pasta_val);

enum class ReinitializesAttrSpelling : unsigned char;
ReinitializesAttrSpelling FromPasta(pasta::ReinitializesAttrSpelling pasta_val);

enum class ReleaseCapabilityAttrSpelling : unsigned char;
ReleaseCapabilityAttrSpelling FromPasta(pasta::ReleaseCapabilityAttrSpelling pasta_val);

enum class ReleaseHandleAttrSpelling : unsigned char;
ReleaseHandleAttrSpelling FromPasta(pasta::ReleaseHandleAttrSpelling pasta_val);

enum class RequiresCapabilityAttrSpelling : unsigned char;
RequiresCapabilityAttrSpelling FromPasta(pasta::RequiresCapabilityAttrSpelling pasta_val);

enum class RestrictAttrSpelling : unsigned char;
RestrictAttrSpelling FromPasta(pasta::RestrictAttrSpelling pasta_val);

enum class RetainAttrSpelling : unsigned char;
RetainAttrSpelling FromPasta(pasta::RetainAttrSpelling pasta_val);

enum class ReturnTypestateAttrConsumedState : unsigned char;
ReturnTypestateAttrConsumedState FromPasta(pasta::ReturnTypestateAttrConsumedState pasta_val);

enum class ReturnTypestateAttrSpelling : unsigned char;
ReturnTypestateAttrSpelling FromPasta(pasta::ReturnTypestateAttrSpelling pasta_val);

enum class ReturnsNonNullAttrSpelling : unsigned char;
ReturnsNonNullAttrSpelling FromPasta(pasta::ReturnsNonNullAttrSpelling pasta_val);

enum class ReturnsTwiceAttrSpelling : unsigned char;
ReturnsTwiceAttrSpelling FromPasta(pasta::ReturnsTwiceAttrSpelling pasta_val);

enum class SYCLKernelAttrSpelling : unsigned char;
SYCLKernelAttrSpelling FromPasta(pasta::SYCLKernelAttrSpelling pasta_val);

enum class SYCLSpecialClassAttrSpelling : unsigned char;
SYCLSpecialClassAttrSpelling FromPasta(pasta::SYCLSpecialClassAttrSpelling pasta_val);

enum class ScopedLockableAttrSpelling : unsigned char;
ScopedLockableAttrSpelling FromPasta(pasta::ScopedLockableAttrSpelling pasta_val);

enum class SectionAttrSpelling : unsigned char;
SectionAttrSpelling FromPasta(pasta::SectionAttrSpelling pasta_val);

enum class SelectAnyAttrSpelling : unsigned char;
SelectAnyAttrSpelling FromPasta(pasta::SelectAnyAttrSpelling pasta_val);

enum class SentinelAttrSpelling : unsigned char;
SentinelAttrSpelling FromPasta(pasta::SentinelAttrSpelling pasta_val);

enum class SetTypestateAttrConsumedState : unsigned char;
SetTypestateAttrConsumedState FromPasta(pasta::SetTypestateAttrConsumedState pasta_val);

enum class SetTypestateAttrSpelling : unsigned char;
SetTypestateAttrSpelling FromPasta(pasta::SetTypestateAttrSpelling pasta_val);

enum class SourceLocExprIdentKind : unsigned char;
SourceLocExprIdentKind FromPasta(pasta::SourceLocExprIdentKind pasta_val);

enum class SpeculativeLoadHardeningAttrSpelling : unsigned char;
SpeculativeLoadHardeningAttrSpelling FromPasta(pasta::SpeculativeLoadHardeningAttrSpelling pasta_val);

enum class StandaloneDebugAttrSpelling : unsigned char;
StandaloneDebugAttrSpelling FromPasta(pasta::StandaloneDebugAttrSpelling pasta_val);

enum class StdCallAttrSpelling : unsigned char;
StdCallAttrSpelling FromPasta(pasta::StdCallAttrSpelling pasta_val);

enum class StmtLikelihood : unsigned char;
StmtLikelihood FromPasta(pasta::StmtLikelihood pasta_val);

enum class StmtKind : unsigned char;
StmtKind FromPasta(pasta::StmtKind pasta_val);

enum class StringLiteralStringKind : unsigned char;
StringLiteralStringKind FromPasta(pasta::StringLiteralStringKind pasta_val);

enum class SwiftAsyncAttrKind : unsigned char;
SwiftAsyncAttrKind FromPasta(pasta::SwiftAsyncAttrKind pasta_val);

enum class SwiftAsyncAttrSpelling : unsigned char;
SwiftAsyncAttrSpelling FromPasta(pasta::SwiftAsyncAttrSpelling pasta_val);

enum class SwiftAsyncCallAttrSpelling : unsigned char;
SwiftAsyncCallAttrSpelling FromPasta(pasta::SwiftAsyncCallAttrSpelling pasta_val);

enum class SwiftAsyncContextAttrSpelling : unsigned char;
SwiftAsyncContextAttrSpelling FromPasta(pasta::SwiftAsyncContextAttrSpelling pasta_val);

enum class SwiftAsyncErrorAttrConventionKind : unsigned char;
SwiftAsyncErrorAttrConventionKind FromPasta(pasta::SwiftAsyncErrorAttrConventionKind pasta_val);

enum class SwiftAsyncErrorAttrSpelling : unsigned char;
SwiftAsyncErrorAttrSpelling FromPasta(pasta::SwiftAsyncErrorAttrSpelling pasta_val);

enum class SwiftCallAttrSpelling : unsigned char;
SwiftCallAttrSpelling FromPasta(pasta::SwiftCallAttrSpelling pasta_val);

enum class SwiftContextAttrSpelling : unsigned char;
SwiftContextAttrSpelling FromPasta(pasta::SwiftContextAttrSpelling pasta_val);

enum class SwiftErrorAttrConventionKind : unsigned char;
SwiftErrorAttrConventionKind FromPasta(pasta::SwiftErrorAttrConventionKind pasta_val);

enum class SwiftErrorResultAttrSpelling : unsigned char;
SwiftErrorResultAttrSpelling FromPasta(pasta::SwiftErrorResultAttrSpelling pasta_val);

enum class SwiftIndirectResultAttrSpelling : unsigned char;
SwiftIndirectResultAttrSpelling FromPasta(pasta::SwiftIndirectResultAttrSpelling pasta_val);

enum class SwiftNewTypeAttrNewtypeKind : unsigned char;
SwiftNewTypeAttrNewtypeKind FromPasta(pasta::SwiftNewTypeAttrNewtypeKind pasta_val);

enum class SwiftNewTypeAttrSpelling : unsigned char;
SwiftNewTypeAttrSpelling FromPasta(pasta::SwiftNewTypeAttrSpelling pasta_val);

enum class SysVABIAttrSpelling : unsigned char;
SysVABIAttrSpelling FromPasta(pasta::SysVABIAttrSpelling pasta_val);

enum class TLSModelAttrSpelling : unsigned char;
TLSModelAttrSpelling FromPasta(pasta::TLSModelAttrSpelling pasta_val);

enum class TargetAttrSpelling : unsigned char;
TargetAttrSpelling FromPasta(pasta::TargetAttrSpelling pasta_val);

enum class TargetClonesAttrSpelling : unsigned char;
TargetClonesAttrSpelling FromPasta(pasta::TargetClonesAttrSpelling pasta_val);

enum class TargetVersionAttrSpelling : unsigned char;
TargetVersionAttrSpelling FromPasta(pasta::TargetVersionAttrSpelling pasta_val);

enum class TemplateArgumentKind : unsigned char;
TemplateArgumentKind FromPasta(pasta::TemplateArgumentKind pasta_val);

enum class TestTypestateAttrConsumedState : unsigned char;
TestTypestateAttrConsumedState FromPasta(pasta::TestTypestateAttrConsumedState pasta_val);

enum class TestTypestateAttrSpelling : unsigned char;
TestTypestateAttrSpelling FromPasta(pasta::TestTypestateAttrSpelling pasta_val);

enum class ThisCallAttrSpelling : unsigned char;
ThisCallAttrSpelling FromPasta(pasta::ThisCallAttrSpelling pasta_val);

enum class TransparentUnionAttrSpelling : unsigned char;
TransparentUnionAttrSpelling FromPasta(pasta::TransparentUnionAttrSpelling pasta_val);

enum class TrivialABIAttrSpelling : unsigned char;
TrivialABIAttrSpelling FromPasta(pasta::TrivialABIAttrSpelling pasta_val);

enum class TryAcquireCapabilityAttrSpelling : unsigned char;
TryAcquireCapabilityAttrSpelling FromPasta(pasta::TryAcquireCapabilityAttrSpelling pasta_val);

enum class TypeScalarTypeKind : unsigned char;
TypeScalarTypeKind FromPasta(pasta::TypeScalarTypeKind pasta_val);

enum class TypeKind : unsigned char;
TypeKind FromPasta(pasta::TypeKind pasta_val);

enum class TypeTagForDatatypeAttrSpelling : unsigned char;
TypeTagForDatatypeAttrSpelling FromPasta(pasta::TypeTagForDatatypeAttrSpelling pasta_val);

enum class TypeVisibilityAttrSpelling : unsigned char;
TypeVisibilityAttrSpelling FromPasta(pasta::TypeVisibilityAttrSpelling pasta_val);

enum class TypeVisibilityAttrVisibilityType : unsigned char;
TypeVisibilityAttrVisibilityType FromPasta(pasta::TypeVisibilityAttrVisibilityType pasta_val);

enum class UnaryTransformTypeUTTKind : unsigned char;
UnaryTransformTypeUTTKind FromPasta(pasta::UnaryTransformTypeUTTKind pasta_val);

enum class UnavailableAttrImplicitReason : unsigned char;
UnavailableAttrImplicitReason FromPasta(pasta::UnavailableAttrImplicitReason pasta_val);

enum class UnavailableAttrSpelling : unsigned char;
UnavailableAttrSpelling FromPasta(pasta::UnavailableAttrSpelling pasta_val);

enum class UninitializedAttrSpelling : unsigned char;
UninitializedAttrSpelling FromPasta(pasta::UninitializedAttrSpelling pasta_val);

enum class UnlikelyAttrSpelling : unsigned char;
UnlikelyAttrSpelling FromPasta(pasta::UnlikelyAttrSpelling pasta_val);

enum class UnsafeBufferUsageAttrSpelling : unsigned char;
UnsafeBufferUsageAttrSpelling FromPasta(pasta::UnsafeBufferUsageAttrSpelling pasta_val);

enum class UnusedAttrSpelling : unsigned char;
UnusedAttrSpelling FromPasta(pasta::UnusedAttrSpelling pasta_val);

enum class UseHandleAttrSpelling : unsigned char;
UseHandleAttrSpelling FromPasta(pasta::UseHandleAttrSpelling pasta_val);

enum class UsedAttrSpelling : unsigned char;
UsedAttrSpelling FromPasta(pasta::UsedAttrSpelling pasta_val);

enum class UserDefinedLiteralLiteralOperatorKind : unsigned char;
UserDefinedLiteralLiteralOperatorKind FromPasta(pasta::UserDefinedLiteralLiteralOperatorKind pasta_val);

enum class UsingIfExistsAttrSpelling : unsigned char;
UsingIfExistsAttrSpelling FromPasta(pasta::UsingIfExistsAttrSpelling pasta_val);

enum class UuidAttrSpelling : unsigned char;
UuidAttrSpelling FromPasta(pasta::UuidAttrSpelling pasta_val);

enum class VarDeclDefinitionKind : unsigned char;
VarDeclDefinitionKind FromPasta(pasta::VarDeclDefinitionKind pasta_val);

enum class VarDeclInitializationStyle : unsigned char;
VarDeclInitializationStyle FromPasta(pasta::VarDeclInitializationStyle pasta_val);

enum class VarDeclTLSKind : unsigned char;
VarDeclTLSKind FromPasta(pasta::VarDeclTLSKind pasta_val);

enum class VecReturnAttrSpelling : unsigned char;
VecReturnAttrSpelling FromPasta(pasta::VecReturnAttrSpelling pasta_val);

enum class VectorCallAttrSpelling : unsigned char;
VectorCallAttrSpelling FromPasta(pasta::VectorCallAttrSpelling pasta_val);

enum class VectorTypeVectorKind : unsigned char;
VectorTypeVectorKind FromPasta(pasta::VectorTypeVectorKind pasta_val);

enum class VisibilityAttrSpelling : unsigned char;
VisibilityAttrSpelling FromPasta(pasta::VisibilityAttrSpelling pasta_val);

enum class VisibilityAttrVisibilityType : unsigned char;
VisibilityAttrVisibilityType FromPasta(pasta::VisibilityAttrVisibilityType pasta_val);

enum class WarnUnusedAttrSpelling : unsigned char;
WarnUnusedAttrSpelling FromPasta(pasta::WarnUnusedAttrSpelling pasta_val);

enum class WarnUnusedResultAttrSpelling : unsigned char;
WarnUnusedResultAttrSpelling FromPasta(pasta::WarnUnusedResultAttrSpelling pasta_val);

enum class WeakAttrSpelling : unsigned char;
WeakAttrSpelling FromPasta(pasta::WeakAttrSpelling pasta_val);

enum class WeakImportAttrSpelling : unsigned char;
WeakImportAttrSpelling FromPasta(pasta::WeakImportAttrSpelling pasta_val);

enum class WeakRefAttrSpelling : unsigned char;
WeakRefAttrSpelling FromPasta(pasta::WeakRefAttrSpelling pasta_val);

enum class WebAssemblyExportNameAttrSpelling : unsigned char;
WebAssemblyExportNameAttrSpelling FromPasta(pasta::WebAssemblyExportNameAttrSpelling pasta_val);

enum class WebAssemblyImportModuleAttrSpelling : unsigned char;
WebAssemblyImportModuleAttrSpelling FromPasta(pasta::WebAssemblyImportModuleAttrSpelling pasta_val);

enum class WebAssemblyImportNameAttrSpelling : unsigned char;
WebAssemblyImportNameAttrSpelling FromPasta(pasta::WebAssemblyImportNameAttrSpelling pasta_val);

enum class X86ForceAlignArgPointerAttrSpelling : unsigned char;
X86ForceAlignArgPointerAttrSpelling FromPasta(pasta::X86ForceAlignArgPointerAttrSpelling pasta_val);

enum class XRayInstrumentAttrSpelling : unsigned char;
XRayInstrumentAttrSpelling FromPasta(pasta::XRayInstrumentAttrSpelling pasta_val);

enum class XRayLogArgsAttrSpelling : unsigned char;
XRayLogArgsAttrSpelling FromPasta(pasta::XRayLogArgsAttrSpelling pasta_val);

enum class ZeroCallUsedRegsAttrSpelling : unsigned char;
ZeroCallUsedRegsAttrSpelling FromPasta(pasta::ZeroCallUsedRegsAttrSpelling pasta_val);

enum class ZeroCallUsedRegsAttrZeroCallUsedRegsKind : unsigned char;
ZeroCallUsedRegsAttrZeroCallUsedRegsKind FromPasta(pasta::ZeroCallUsedRegsAttrZeroCallUsedRegsKind pasta_val);

enum class ASTDumpOutputFormat : unsigned char;
ASTDumpOutputFormat FromPasta(pasta::ASTDumpOutputFormat pasta_val);

enum class AccessSpecifier : unsigned char;
AccessSpecifier FromPasta(pasta::AccessSpecifier pasta_val);

enum class AddrSpaceMapMangling : unsigned char;
AddrSpaceMapMangling FromPasta(pasta::AddrSpaceMapMangling pasta_val);

enum class AlignRequirementKind : unsigned char;
AlignRequirementKind FromPasta(pasta::AlignRequirementKind pasta_val);

enum class AltivecSrcCompatKind : unsigned char;
AltivecSrcCompatKind FromPasta(pasta::AltivecSrcCompatKind pasta_val);

enum class ArgumentKind : unsigned char;
ArgumentKind FromPasta(pasta::ArgumentKind pasta_val);

enum class ArrayTypeTrait : unsigned char;
ArrayTypeTrait FromPasta(pasta::ArrayTypeTrait pasta_val);

enum class AssignmentTrackingOpts : unsigned char;
AssignmentTrackingOpts FromPasta(pasta::AssignmentTrackingOpts pasta_val);

enum class AtomicScopeModelKind : unsigned char;
AtomicScopeModelKind FromPasta(pasta::AtomicScopeModelKind pasta_val);

enum class AutoTypeKeyword : unsigned char;
AutoTypeKeyword FromPasta(pasta::AutoTypeKeyword pasta_val);

enum class AvailabilityResult : unsigned char;
AvailabilityResult FromPasta(pasta::AvailabilityResult pasta_val);

enum class BinaryOperatorKind : unsigned char;
BinaryOperatorKind FromPasta(pasta::BinaryOperatorKind pasta_val);

enum class Bits : unsigned char;
Bits FromPasta(pasta::Bits pasta_val);

enum class CallingConv : unsigned char;
CallingConv FromPasta(pasta::CallingConv pasta_val);

enum class CanThrowResult : unsigned char;
CanThrowResult FromPasta(pasta::CanThrowResult pasta_val);

enum class CapturedRegionKind : unsigned char;
CapturedRegionKind FromPasta(pasta::CapturedRegionKind pasta_val);

enum class CastKind : unsigned char;
CastKind FromPasta(pasta::CastKind pasta_val);

enum class ClangABI : unsigned char;
ClangABI FromPasta(pasta::ClangABI pasta_val);

enum class CommentKind : unsigned char;
CommentKind FromPasta(pasta::CommentKind pasta_val);

enum class ComparisonCategoryResult : unsigned char;
ComparisonCategoryResult FromPasta(pasta::ComparisonCategoryResult pasta_val);

enum class ComparisonCategoryType : unsigned char;
ComparisonCategoryType FromPasta(pasta::ComparisonCategoryType pasta_val);

enum class CompilingModuleKind : unsigned char;
CompilingModuleKind FromPasta(pasta::CompilingModuleKind pasta_val);

enum class ConstexprSpecKind : unsigned char;
ConstexprSpecKind FromPasta(pasta::ConstexprSpecKind pasta_val);

enum class CoreFoundationABI : unsigned char;
CoreFoundationABI FromPasta(pasta::CoreFoundationABI pasta_val);

enum class DataPositionTy : unsigned char;
DataPositionTy FromPasta(pasta::DataPositionTy pasta_val);

enum class DebugSrcHashKind : unsigned char;
DebugSrcHashKind FromPasta(pasta::DebugSrcHashKind pasta_val);

enum class DeductionCandidate : unsigned char;
DeductionCandidate FromPasta(pasta::DeductionCandidate pasta_val);

enum class DefaultArgKind : unsigned char;
DefaultArgKind FromPasta(pasta::DefaultArgKind pasta_val);

enum class DefaultCallingConvention : unsigned char;
DefaultCallingConvention FromPasta(pasta::DefaultCallingConvention pasta_val);

enum class DefaultVisiblityExportMapping : unsigned char;
DefaultVisiblityExportMapping FromPasta(pasta::DefaultVisiblityExportMapping pasta_val);

enum class DesignatorKind : unsigned char;
DesignatorKind FromPasta(pasta::DesignatorKind pasta_val);

enum class DiagnosticLevelMask : unsigned char;
DiagnosticLevelMask FromPasta(pasta::DiagnosticLevelMask pasta_val);

enum class ElaboratedTypeKeyword : unsigned char;
ElaboratedTypeKeyword FromPasta(pasta::ElaboratedTypeKeyword pasta_val);

enum class EmbedBitcodeKind : unsigned char;
EmbedBitcodeKind FromPasta(pasta::EmbedBitcodeKind pasta_val);

enum class EscapeChar : unsigned char;
EscapeChar FromPasta(pasta::EscapeChar pasta_val);

enum class ExceptionHandlingKind : unsigned char;
ExceptionHandlingKind FromPasta(pasta::ExceptionHandlingKind pasta_val);

enum class ExceptionSpecificationType : unsigned char;
ExceptionSpecificationType FromPasta(pasta::ExceptionSpecificationType pasta_val);

enum class ExcessPrecisionKind : unsigned char;
ExcessPrecisionKind FromPasta(pasta::ExcessPrecisionKind pasta_val);

enum class ExclusionType : unsigned char;
ExclusionType FromPasta(pasta::ExclusionType pasta_val);

enum class ExplicitSpecKind : unsigned char;
ExplicitSpecKind FromPasta(pasta::ExplicitSpecKind pasta_val);

enum class ExprDependence : unsigned char;
ExprDependence FromPasta(pasta::ExprDependence pasta_val);

enum class ExprObjectKind : unsigned char;
ExprObjectKind FromPasta(pasta::ExprObjectKind pasta_val);

enum class ExprOffsets : unsigned char;
ExprOffsets FromPasta(pasta::ExprOffsets pasta_val);

enum class ExprValueKind : unsigned char;
ExprValueKind FromPasta(pasta::ExprValueKind pasta_val);

enum class ExpressionTrait : unsigned char;
ExpressionTrait FromPasta(pasta::ExpressionTrait pasta_val);

enum class ExtKind : unsigned char;
ExtKind FromPasta(pasta::ExtKind pasta_val);

enum class ExtendArgsKind : unsigned char;
ExtendArgsKind FromPasta(pasta::ExtendArgsKind pasta_val);

enum class FPEvalMethodKind : unsigned char;
FPEvalMethodKind FromPasta(pasta::FPEvalMethodKind pasta_val);

enum class FPExceptionModeKind : unsigned char;
FPExceptionModeKind FromPasta(pasta::FPExceptionModeKind pasta_val);

enum class FPModeKind : unsigned char;
FPModeKind FromPasta(pasta::FPModeKind pasta_val);

enum class FiniteLoopsKind : unsigned char;
FiniteLoopsKind FromPasta(pasta::FiniteLoopsKind pasta_val);

enum class Flags : unsigned char;
Flags FromPasta(pasta::Flags pasta_val);

enum class FramePointerKind : unsigned char;
FramePointerKind FromPasta(pasta::FramePointerKind pasta_val);

enum class GC : unsigned char;
GC FromPasta(pasta::GC pasta_val);

enum class GCMode : unsigned char;
GCMode FromPasta(pasta::GCMode pasta_val);

enum class GPUDefaultStreamKind : unsigned char;
GPUDefaultStreamKind FromPasta(pasta::GPUDefaultStreamKind pasta_val);

enum class GVALinkage : unsigned char;
GVALinkage FromPasta(pasta::GVALinkage pasta_val);

enum class GetBuiltinTypeError : unsigned char;
GetBuiltinTypeError FromPasta(pasta::GetBuiltinTypeError pasta_val);

enum class HLSLLangStd : unsigned char;
HLSLLangStd FromPasta(pasta::HLSLLangStd pasta_val);

enum class ID : unsigned char;
ID FromPasta(pasta::ID pasta_val);

enum class IdentifierInfoFlag : unsigned char;
IdentifierInfoFlag FromPasta(pasta::IdentifierInfoFlag pasta_val);

enum class IfStatementKind : unsigned char;
IfStatementKind FromPasta(pasta::IfStatementKind pasta_val);

enum class ImbueAttribute : unsigned char;
ImbueAttribute FromPasta(pasta::ImbueAttribute pasta_val);

enum class InClassInitStyle : unsigned char;
InClassInitStyle FromPasta(pasta::InClassInitStyle pasta_val);

enum class InheritedDesignatedInitializersState : unsigned char;
InheritedDesignatedInitializersState FromPasta(pasta::InheritedDesignatedInitializersState pasta_val);

enum class InitStorageKind : unsigned char;
InitStorageKind FromPasta(pasta::InitStorageKind pasta_val);

enum class InlineAsmDialectKind : unsigned char;
InlineAsmDialectKind FromPasta(pasta::InlineAsmDialectKind pasta_val);

enum class InlineVariableDefinitionKind : unsigned char;
InlineVariableDefinitionKind FromPasta(pasta::InlineVariableDefinitionKind pasta_val);

enum class InliningMethod : unsigned char;
InliningMethod FromPasta(pasta::InliningMethod pasta_val);

enum class InterestingIdentifierKind : unsigned char;
InterestingIdentifierKind FromPasta(pasta::InterestingIdentifierKind pasta_val);

enum class Kinds : unsigned char;
Kinds FromPasta(pasta::Kinds pasta_val);

enum class LambdaCaptureDefault : unsigned char;
LambdaCaptureDefault FromPasta(pasta::LambdaCaptureDefault pasta_val);

enum class LambdaCaptureKind : unsigned char;
LambdaCaptureKind FromPasta(pasta::LambdaCaptureKind pasta_val);

enum class LangAS : unsigned char;
LangAS FromPasta(pasta::LangAS pasta_val);

enum class LangFeatures : unsigned char;
LangFeatures FromPasta(pasta::LangFeatures pasta_val);

enum class Language : unsigned char;
Language FromPasta(pasta::Language pasta_val);

enum class LanguageLinkage : unsigned char;
LanguageLinkage FromPasta(pasta::LanguageLinkage pasta_val);

enum class LaxVectorConversionKind : unsigned char;
LaxVectorConversionKind FromPasta(pasta::LaxVectorConversionKind pasta_val);

enum class Level : unsigned char;
Level FromPasta(pasta::Level pasta_val);

enum class Linkage : unsigned char;
Linkage FromPasta(pasta::Linkage pasta_val);

enum class MSInheritanceModel : unsigned char;
MSInheritanceModel FromPasta(pasta::MSInheritanceModel pasta_val);

enum class MSVCMajorVersion : unsigned char;
MSVCMajorVersion FromPasta(pasta::MSVCMajorVersion pasta_val);

enum class MSVtorDispMode : unsigned char;
MSVtorDispMode FromPasta(pasta::MSVtorDispMode pasta_val);

enum class MethodRefFlags : unsigned char;
MethodRefFlags FromPasta(pasta::MethodRefFlags pasta_val);

enum class ModifiableType : unsigned char;
ModifiableType FromPasta(pasta::ModifiableType pasta_val);

enum class MultiVersionKind : unsigned char;
MultiVersionKind FromPasta(pasta::MultiVersionKind pasta_val);

enum class NameKind : unsigned char;
NameKind FromPasta(pasta::NameKind pasta_val);

enum class NeedExtraManglingDecl : unsigned char;
NeedExtraManglingDecl FromPasta(pasta::NeedExtraManglingDecl pasta_val);

enum class NestedNameSpecifierDependence : unsigned char;
NestedNameSpecifierDependence FromPasta(pasta::NestedNameSpecifierDependence pasta_val);

enum class NonOdrUseReason : unsigned char;
NonOdrUseReason FromPasta(pasta::NonOdrUseReason pasta_val);

enum class NonceObjCInterface : unsigned char;
NonceObjCInterface FromPasta(pasta::NonceObjCInterface pasta_val);

enum class NullabilityKind : unsigned char;
NullabilityKind FromPasta(pasta::NullabilityKind pasta_val);

enum class ObjCBridgeCastKind : unsigned char;
ObjCBridgeCastKind FromPasta(pasta::ObjCBridgeCastKind pasta_val);

enum class ObjCDispatchMethodKind : unsigned char;
ObjCDispatchMethodKind FromPasta(pasta::ObjCDispatchMethodKind pasta_val);

enum class ObjCInstanceTypeFamily : unsigned char;
ObjCInstanceTypeFamily FromPasta(pasta::ObjCInstanceTypeFamily pasta_val);

enum class ObjCLifetime : unsigned char;
ObjCLifetime FromPasta(pasta::ObjCLifetime pasta_val);

enum class ObjCMethodFamily : unsigned char;
ObjCMethodFamily FromPasta(pasta::ObjCMethodFamily pasta_val);

enum class ObjCPropertyQueryKind : unsigned char;
ObjCPropertyQueryKind FromPasta(pasta::ObjCPropertyQueryKind pasta_val);

enum class ObjCStringFormatFamily : unsigned char;
ObjCStringFormatFamily FromPasta(pasta::ObjCStringFormatFamily pasta_val);

enum class ObjCSubstitutionContext : unsigned char;
ObjCSubstitutionContext FromPasta(pasta::ObjCSubstitutionContext pasta_val);

enum class ObjCTypeParamVariance : unsigned char;
ObjCTypeParamVariance FromPasta(pasta::ObjCTypeParamVariance pasta_val);

enum class OnOffSwitch : unsigned char;
OnOffSwitch FromPasta(pasta::OnOffSwitch pasta_val);

enum class OnStackType : unsigned char;
OnStackType FromPasta(pasta::OnStackType pasta_val);

enum class OpenMPAdjustArgsOpKind : unsigned char;
OpenMPAdjustArgsOpKind FromPasta(pasta::OpenMPAdjustArgsOpKind pasta_val);

enum class OpenMPAtClauseKind : unsigned char;
OpenMPAtClauseKind FromPasta(pasta::OpenMPAtClauseKind pasta_val);

enum class OpenMPAtomicDefaultMemOrderClauseKind : unsigned char;
OpenMPAtomicDefaultMemOrderClauseKind FromPasta(pasta::OpenMPAtomicDefaultMemOrderClauseKind pasta_val);

enum class OpenMPBindClauseKind : unsigned char;
OpenMPBindClauseKind FromPasta(pasta::OpenMPBindClauseKind pasta_val);

enum class OpenMPDefaultmapClauseKind : unsigned char;
OpenMPDefaultmapClauseKind FromPasta(pasta::OpenMPDefaultmapClauseKind pasta_val);

enum class OpenMPDefaultmapClauseModifier : unsigned char;
OpenMPDefaultmapClauseModifier FromPasta(pasta::OpenMPDefaultmapClauseModifier pasta_val);

enum class OpenMPDependClauseKind : unsigned char;
OpenMPDependClauseKind FromPasta(pasta::OpenMPDependClauseKind pasta_val);

enum class OpenMPDeviceClauseModifier : unsigned char;
OpenMPDeviceClauseModifier FromPasta(pasta::OpenMPDeviceClauseModifier pasta_val);

enum class OpenMPDeviceType : unsigned char;
OpenMPDeviceType FromPasta(pasta::OpenMPDeviceType pasta_val);

enum class OpenMPDistScheduleClauseKind : unsigned char;
OpenMPDistScheduleClauseKind FromPasta(pasta::OpenMPDistScheduleClauseKind pasta_val);

enum class OpenMPDoacrossClauseModifier : unsigned char;
OpenMPDoacrossClauseModifier FromPasta(pasta::OpenMPDoacrossClauseModifier pasta_val);

enum class OpenMPGrainsizeClauseModifier : unsigned char;
OpenMPGrainsizeClauseModifier FromPasta(pasta::OpenMPGrainsizeClauseModifier pasta_val);

enum class OpenMPLastprivateModifier : unsigned char;
OpenMPLastprivateModifier FromPasta(pasta::OpenMPLastprivateModifier pasta_val);

enum class OpenMPLinearClauseKind : unsigned char;
OpenMPLinearClauseKind FromPasta(pasta::OpenMPLinearClauseKind pasta_val);

enum class OpenMPMapClauseKind : unsigned char;
OpenMPMapClauseKind FromPasta(pasta::OpenMPMapClauseKind pasta_val);

enum class OpenMPMapModifierKind : unsigned char;
OpenMPMapModifierKind FromPasta(pasta::OpenMPMapModifierKind pasta_val);

enum class OpenMPMotionModifierKind : unsigned char;
OpenMPMotionModifierKind FromPasta(pasta::OpenMPMotionModifierKind pasta_val);

enum class OpenMPNumTasksClauseModifier : unsigned char;
OpenMPNumTasksClauseModifier FromPasta(pasta::OpenMPNumTasksClauseModifier pasta_val);

enum class OpenMPOrderClauseKind : unsigned char;
OpenMPOrderClauseKind FromPasta(pasta::OpenMPOrderClauseKind pasta_val);

enum class OpenMPOrderClauseModifier : unsigned char;
OpenMPOrderClauseModifier FromPasta(pasta::OpenMPOrderClauseModifier pasta_val);

enum class OpenMPReductionClauseModifier : unsigned char;
OpenMPReductionClauseModifier FromPasta(pasta::OpenMPReductionClauseModifier pasta_val);

enum class OpenMPScheduleClauseKind : unsigned char;
OpenMPScheduleClauseKind FromPasta(pasta::OpenMPScheduleClauseKind pasta_val);

enum class OpenMPScheduleClauseModifier : unsigned char;
OpenMPScheduleClauseModifier FromPasta(pasta::OpenMPScheduleClauseModifier pasta_val);

enum class OpenMPSeverityClauseKind : unsigned char;
OpenMPSeverityClauseKind FromPasta(pasta::OpenMPSeverityClauseKind pasta_val);

enum class OverloadedOperatorKind : unsigned char;
OverloadedOperatorKind FromPasta(pasta::OverloadedOperatorKind pasta_val);

enum class OverloadsShown : unsigned char;
OverloadsShown FromPasta(pasta::OverloadsShown pasta_val);

enum class ParameterABI : unsigned char;
ParameterABI FromPasta(pasta::ParameterABI pasta_val);

enum class ParenLocsOffsets : unsigned char;
ParenLocsOffsets FromPasta(pasta::ParenLocsOffsets pasta_val);

enum class PragmaFloatControlKind : unsigned char;
PragmaFloatControlKind FromPasta(pasta::PragmaFloatControlKind pasta_val);

enum class PragmaMSCommentKind : unsigned char;
PragmaMSCommentKind FromPasta(pasta::PragmaMSCommentKind pasta_val);

enum class PragmaMSPointersToMembersKind : unsigned char;
PragmaMSPointersToMembersKind FromPasta(pasta::PragmaMSPointersToMembersKind pasta_val);

enum class PragmaMSStructKind : unsigned char;
PragmaMSStructKind FromPasta(pasta::PragmaMSStructKind pasta_val);

enum class PragmaSectionFlag : unsigned char;
PragmaSectionFlag FromPasta(pasta::PragmaSectionFlag pasta_val);

enum class ProfileInstrKind : unsigned char;
ProfileInstrKind FromPasta(pasta::ProfileInstrKind pasta_val);

enum class Qualified : unsigned char;
Qualified FromPasta(pasta::Qualified pasta_val);

enum class RangeExprOffset : unsigned char;
RangeExprOffset FromPasta(pasta::RangeExprOffset pasta_val);

enum class RangeLocOffset : unsigned char;
RangeLocOffset FromPasta(pasta::RangeLocOffset pasta_val);

enum class RefQualifierKind : unsigned char;
RefQualifierKind FromPasta(pasta::RefQualifierKind pasta_val);

enum class RemarkKind : unsigned char;
RemarkKind FromPasta(pasta::RemarkKind pasta_val);

enum class ReservedIdentifierStatus : unsigned char;
ReservedIdentifierStatus FromPasta(pasta::ReservedIdentifierStatus pasta_val);

enum class ReservedLiteralSuffixIdStatus : unsigned char;
ReservedLiteralSuffixIdStatus FromPasta(pasta::ReservedLiteralSuffixIdStatus pasta_val);

enum class SFINAEResponse : unsigned char;
SFINAEResponse FromPasta(pasta::SFINAEResponse pasta_val);

enum class SYCLMajorVersion : unsigned char;
SYCLMajorVersion FromPasta(pasta::SYCLMajorVersion pasta_val);

enum class SanitizerOrdinal : unsigned char;
SanitizerOrdinal FromPasta(pasta::SanitizerOrdinal pasta_val);

enum class SelectorLocationsKind : unsigned char;
SelectorLocationsKind FromPasta(pasta::SelectorLocationsKind pasta_val);

enum class ShaderStage : unsigned char;
ShaderStage FromPasta(pasta::ShaderStage pasta_val);

enum class SignReturnAddressKeyKind : unsigned char;
SignReturnAddressKeyKind FromPasta(pasta::SignReturnAddressKeyKind pasta_val);

enum class SignReturnAddressScopeKind : unsigned char;
SignReturnAddressScopeKind FromPasta(pasta::SignReturnAddressScopeKind pasta_val);

enum class SignedOverflowBehaviorTy : unsigned char;
SignedOverflowBehaviorTy FromPasta(pasta::SignedOverflowBehaviorTy pasta_val);

enum class SpecialMemberFlags : unsigned char;
SpecialMemberFlags FromPasta(pasta::SpecialMemberFlags pasta_val);

enum class SpecifierKind : unsigned char;
SpecifierKind FromPasta(pasta::SpecifierKind pasta_val);

enum class StackProtectorMode : unsigned char;
StackProtectorMode FromPasta(pasta::StackProtectorMode pasta_val);

enum class StorageClass : unsigned char;
StorageClass FromPasta(pasta::StorageClass pasta_val);

enum class StorageDuration : unsigned char;
StorageDuration FromPasta(pasta::StorageDuration pasta_val);

enum class StoredNameKind : unsigned char;
StoredNameKind FromPasta(pasta::StoredNameKind pasta_val);

enum class StoredSpecifierKind : unsigned char;
StoredSpecifierKind FromPasta(pasta::StoredSpecifierKind pasta_val);

enum class StrictFlexArraysLevelKind : unsigned char;
StrictFlexArraysLevelKind FromPasta(pasta::StrictFlexArraysLevelKind pasta_val);

enum class StructReturnConventionKind : unsigned char;
StructReturnConventionKind FromPasta(pasta::StructReturnConventionKind pasta_val);

enum class SubExpr : unsigned char;
SubExpr FromPasta(pasta::SubExpr pasta_val);

enum class SubStmt : unsigned char;
SubStmt FromPasta(pasta::SubStmt pasta_val);

enum class SwiftAsyncFramePointerKind : unsigned char;
SwiftAsyncFramePointerKind FromPasta(pasta::SwiftAsyncFramePointerKind pasta_val);

enum class SyncScope : unsigned char;
SyncScope FromPasta(pasta::SyncScope pasta_val);

enum class Syntax : unsigned char;
Syntax FromPasta(pasta::Syntax pasta_val);

enum class TLSModel : unsigned char;
TLSModel FromPasta(pasta::TLSModel pasta_val);

enum class TQ : unsigned char;
TQ FromPasta(pasta::TQ pasta_val);

enum class TagTypeKind : unsigned char;
TagTypeKind FromPasta(pasta::TagTypeKind pasta_val);

enum class TailPaddingUseRules : unsigned char;
TailPaddingUseRules FromPasta(pasta::TailPaddingUseRules pasta_val);

enum class TemplateArgumentDependence : unsigned char;
TemplateArgumentDependence FromPasta(pasta::TemplateArgumentDependence pasta_val);

enum class TemplateNameDependence : unsigned char;
TemplateNameDependence FromPasta(pasta::TemplateNameDependence pasta_val);

enum class TemplateSpecializationKind : unsigned char;
TemplateSpecializationKind FromPasta(pasta::TemplateSpecializationKind pasta_val);

enum class TextDiagnosticFormat : unsigned char;
TextDiagnosticFormat FromPasta(pasta::TextDiagnosticFormat pasta_val);

enum class ThreadModelKind : unsigned char;
ThreadModelKind FromPasta(pasta::ThreadModelKind pasta_val);

enum class ThreadStorageClassSpecifier : unsigned char;
ThreadStorageClassSpecifier FromPasta(pasta::ThreadStorageClassSpecifier pasta_val);

enum class TokenKind : unsigned short;
TokenKind FromPasta(pasta::TokenKind pasta_val);

enum class TrailingAllocKind : unsigned char;
TrailingAllocKind FromPasta(pasta::TrailingAllocKind pasta_val);

enum class TranslationUnitKind : unsigned char;
TranslationUnitKind FromPasta(pasta::TranslationUnitKind pasta_val);

enum class TrivialAutoVarInitKind : unsigned char;
TrivialAutoVarInitKind FromPasta(pasta::TrivialAutoVarInitKind pasta_val);

enum class TypeDependence : unsigned char;
TypeDependence FromPasta(pasta::TypeDependence pasta_val);

enum class TypeLocClass : unsigned char;
TypeLocClass FromPasta(pasta::TypeLocClass pasta_val);

enum class TypeOfKind : unsigned char;
TypeOfKind FromPasta(pasta::TypeOfKind pasta_val);

enum class TypeSpecifierSign : unsigned char;
TypeSpecifierSign FromPasta(pasta::TypeSpecifierSign pasta_val);

enum class TypeSpecifierType : unsigned char;
TypeSpecifierType FromPasta(pasta::TypeSpecifierType pasta_val);

enum class TypeSpecifierWidth : unsigned char;
TypeSpecifierWidth FromPasta(pasta::TypeSpecifierWidth pasta_val);

enum class TypeSpecifiersPipe : unsigned char;
TypeSpecifiersPipe FromPasta(pasta::TypeSpecifiersPipe pasta_val);

enum class TypeTrait : unsigned char;
TypeTrait FromPasta(pasta::TypeTrait pasta_val);

enum class UnaryExprOrTypeTrait : unsigned char;
UnaryExprOrTypeTrait FromPasta(pasta::UnaryExprOrTypeTrait pasta_val);

enum class UnaryOperatorKind : unsigned char;
UnaryOperatorKind FromPasta(pasta::UnaryOperatorKind pasta_val);

enum class APValueKind : unsigned char;
APValueKind FromPasta(pasta::APValueKind pasta_val);

enum class VectorLibrary : unsigned char;
VectorLibrary FromPasta(pasta::VectorLibrary pasta_val);

enum class Visibility : unsigned char;
Visibility FromPasta(pasta::Visibility pasta_val);

enum class AttributeSyntax : unsigned char;
AttributeSyntax FromPasta(pasta::AttributeSyntax pasta_val);

enum class DeclCategory : unsigned char;
DeclCategory FromPasta(pasta::DeclCategory pasta_val);

enum class MacroKind : unsigned char;
MacroKind FromPasta(pasta::MacroKind pasta_val);

enum class PathKind : unsigned char;
PathKind FromPasta(pasta::PathKind pasta_val);

enum class FileType : unsigned char;
FileType FromPasta(pasta::FileType pasta_val);

enum class CompilerName : unsigned char;
CompilerName FromPasta(pasta::CompilerName pasta_val);

enum class IncludePathLocation : unsigned char;
IncludePathLocation FromPasta(pasta::IncludePathLocation pasta_val);

enum class TargetLanguage : unsigned char;
TargetLanguage FromPasta(pasta::TargetLanguage pasta_val);

enum class PseudoKind : unsigned char;
PseudoKind FromPasta(pasta::PseudoKind pasta_val);

enum class TokenCategory : unsigned char;
TokenCategory FromPasta(pasta::TokenCategory pasta_val);

}  // namespace mx
