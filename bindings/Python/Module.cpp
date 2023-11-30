// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <cstdint>

#include "Binding.h"

namespace mx {
enum class DeclKind : uint8_t;
enum class AttrKind : uint16_t;
enum class AArch64SVEPcsAttrSpelling : uint8_t;
enum class AArch64VectorPcsAttrSpelling : uint8_t;
enum class AMDGPUFlatWorkGroupSizeAttrSpelling : uint8_t;
enum class AMDGPUKernelCallAttrSpelling : uint8_t;
enum class AMDGPUNumSGPRAttrSpelling : uint8_t;
enum class AMDGPUNumVGPRAttrSpelling : uint8_t;
enum class AMDGPUWavesPerEUAttrSpelling : uint8_t;
enum class ARMInterruptAttrInterruptType : uint8_t;
enum class ARMInterruptAttrSpelling : uint8_t;
enum class AVRInterruptAttrSpelling : uint8_t;
enum class AVRSignalAttrSpelling : uint8_t;
enum class AbiTagAttrSpelling : uint8_t;
enum class AcquireCapabilityAttrSpelling : uint8_t;
enum class AcquireHandleAttrSpelling : uint8_t;
enum class AddressSpaceAttrSpelling : uint8_t;
enum class AliasAttrSpelling : uint8_t;
enum class AlignedAttrSpelling : uint8_t;
enum class AllocAlignAttrSpelling : uint8_t;
enum class AllocSizeAttrSpelling : uint8_t;
enum class AlwaysDestroyAttrSpelling : uint8_t;
enum class AlwaysInlineAttrSpelling : uint8_t;
enum class AnnotateAttrSpelling : uint8_t;
enum class AnnotateTypeAttrSpelling : uint8_t;
enum class AnyX86InterruptAttrSpelling : uint8_t;
enum class AnyX86NoCallerSavedRegistersAttrSpelling : uint8_t;
enum class AnyX86NoCfCheckAttrSpelling : uint8_t;
enum class ArcWeakrefUnavailableAttrSpelling : uint8_t;
enum class ArgumentWithTypeTagAttrSpelling : uint8_t;
enum class ArmBuiltinAliasAttrSpelling : uint8_t;
enum class ArmMveStrictPolymorphismAttrSpelling : uint8_t;
enum class ArrayTypeArraySizeModifier : uint8_t;
enum class ArtificialAttrSpelling : uint8_t;
enum class AsmLabelAttrSpelling : uint8_t;
enum class AssertCapabilityAttrSpelling : uint8_t;
enum class AssumeAlignedAttrSpelling : uint8_t;
enum class AssumptionAttrSpelling : uint8_t;
enum class AtomicExprAtomicOp : uint8_t;
enum class AvailabilityAttrSpelling : uint8_t;
enum class AvailableOnlyInDefaultEvalMethodAttrSpelling : uint8_t;
enum class BPFPreserveAccessIndexAttrSpelling : uint8_t;
enum class BTFDeclTagAttrSpelling : uint8_t;
enum class BTFTypeTagAttrSpelling : uint8_t;
enum class BlocksAttrBlockType : uint8_t;
enum class BlocksAttrSpelling : uint8_t;
enum class BuiltinAliasAttrSpelling : uint8_t;
enum class BuiltinTypeKind : uint16_t;
enum class CDeclAttrSpelling : uint8_t;
enum class CFAuditedTransferAttrSpelling : uint8_t;
enum class CFConsumedAttrSpelling : uint8_t;
enum class CFGuardAttrGuardArg : uint8_t;
enum class CFGuardAttrSpelling : uint8_t;
enum class CFICanonicalJumpTableAttrSpelling : uint8_t;
enum class CFReturnsNotRetainedAttrSpelling : uint8_t;
enum class CFReturnsRetainedAttrSpelling : uint8_t;
enum class CFUnknownTransferAttrSpelling : uint8_t;
enum class CPUDispatchAttrSpelling : uint8_t;
enum class CPUSpecificAttrSpelling : uint8_t;
enum class CUDAConstantAttrSpelling : uint8_t;
enum class CUDADeviceAttrSpelling : uint8_t;
enum class CUDADeviceBuiltinSurfaceTypeAttrSpelling : uint8_t;
enum class CUDADeviceBuiltinTextureTypeAttrSpelling : uint8_t;
enum class CUDAGlobalAttrSpelling : uint8_t;
enum class CUDAHostAttrSpelling : uint8_t;
enum class CUDALaunchBoundsAttrSpelling : uint8_t;
enum class CUDASharedAttrSpelling : uint8_t;
enum class CXX11NoReturnAttrSpelling : uint8_t;
enum class CXXConstructExprConstructionKind : uint8_t;
enum class CXXNewExprInitializationStyle : uint8_t;
enum class CXXRecordDeclLambdaDependencyKind : uint8_t;
enum class CallExprADLCallKind : uint8_t;
enum class CallableWhenAttrConsumedState : uint8_t;
enum class CallableWhenAttrSpelling : uint8_t;
enum class CallbackAttrSpelling : uint8_t;
enum class CalledOnceAttrSpelling : uint8_t;
enum class CapabilityAttrSpelling : uint8_t;
enum class CapturedStmtVariableCaptureKind : uint8_t;
enum class CarriesDependencyAttrSpelling : uint8_t;
enum class CharacterLiteralCharacterKind : uint8_t;
enum class CleanupAttrSpelling : uint8_t;
enum class ColdAttrSpelling : uint8_t;
enum class CommonAttrSpelling : uint8_t;
enum class ConstAttrSpelling : uint8_t;
enum class ConstInitAttrSpelling : uint8_t;
enum class ConstantExprResultStorageKind : uint8_t;
enum class ConstructorAttrSpelling : uint8_t;
enum class ConsumableAttrConsumedState : uint8_t;
enum class ConsumableAttrSpelling : uint8_t;
enum class ConsumableAutoCastAttrSpelling : uint8_t;
enum class ConsumableSetOnReadAttrSpelling : uint8_t;
enum class ConvergentAttrSpelling : uint8_t;
enum class DLLExportAttrSpelling : uint8_t;
enum class DLLImportAttrSpelling : uint8_t;
enum class DeclFriendObjectKind : uint8_t;
enum class DeclIdentifierNamespace : uint8_t;
enum class DeclModuleOwnershipKind : uint8_t;
enum class DeclObjCDeclQualifier : uint8_t;
enum class DeprecatedAttrSpelling : uint8_t;
enum class DestructorAttrSpelling : uint8_t;
enum class DiagnoseAsBuiltinAttrSpelling : uint8_t;
enum class DiagnoseIfAttrDiagnosticType : uint8_t;
enum class DisableSanitizerInstrumentationAttrSpelling : uint8_t;
enum class DisableTailCallsAttrSpelling : uint8_t;
enum class EnforceTCBAttrSpelling : uint8_t;
enum class EnforceTCBLeafAttrSpelling : uint8_t;
enum class EnumExtensibilityAttrKind : uint8_t;
enum class EnumExtensibilityAttrSpelling : uint8_t;
enum class ErrorAttrSpelling : uint8_t;
enum class ExcludeFromExplicitInstantiationAttrSpelling : uint8_t;
enum class ExprConstantExprKind : uint8_t;
enum class ExprLValueClassification : uint8_t;
enum class ExprNullPointerConstantKind : uint8_t;
enum class ExprNullPointerConstantValueDependence : uint8_t;
enum class ExprSideEffectsKind : uint8_t;
enum class ExprisModifiableLvalueResult : uint8_t;
enum class ExternalSourceSymbolAttrSpelling : uint8_t;
enum class FallThroughAttrSpelling : uint8_t;
enum class FastCallAttrSpelling : uint8_t;
enum class FinalAttrSpelling : uint8_t;
enum class FlagEnumAttrSpelling : uint8_t;
enum class FlattenAttrSpelling : uint8_t;
enum class FormatArgAttrSpelling : uint8_t;
enum class FormatAttrSpelling : uint8_t;
enum class FunctionDeclTemplatedKind : uint8_t;
enum class FunctionReturnThunksAttrKind : uint8_t;
enum class FunctionReturnThunksAttrSpelling : uint8_t;
enum class GNUInlineAttrSpelling : uint8_t;
enum class GuardedVarAttrSpelling : uint8_t;
enum class HIPManagedAttrSpelling : uint8_t;
enum class HLSLResourceAttrResourceClass : uint8_t;
enum class HLSLResourceAttrResourceKind : uint8_t;
enum class HLSLShaderAttrShaderType : uint8_t;
enum class HotAttrSpelling : uint8_t;
enum class IBActionAttrSpelling : uint8_t;
enum class IBOutletAttrSpelling : uint8_t;
enum class IBOutletCollectionAttrSpelling : uint8_t;
enum class IFuncAttrSpelling : uint8_t;
enum class ImplicitCastExprOnStack : uint8_t;
enum class ImplicitParamDeclImplicitParamKind : uint8_t;
enum class InitPriorityAttrSpelling : uint8_t;
enum class IntelOclBiccAttrSpelling : uint8_t;
enum class InternalLinkageAttrSpelling : uint8_t;
enum class LTOVisibilityPublicAttrSpelling : uint8_t;
enum class LeafAttrSpelling : uint8_t;
enum class LifetimeBoundAttrSpelling : uint8_t;
enum class LikelyAttrSpelling : uint8_t;
enum class LinkageSpecDeclLanguageIDs : uint8_t;
enum class LoaderUninitializedAttrSpelling : uint8_t;
enum class LoopHintAttrLoopHintState : uint8_t;
enum class LoopHintAttrOptionType : uint8_t;
enum class LoopHintAttrSpelling : uint8_t;
enum class MIGServerRoutineAttrSpelling : uint8_t;
enum class MSABIAttrSpelling : uint8_t;
enum class MSInheritanceAttrSpelling : uint8_t;
enum class MSP430InterruptAttrSpelling : uint8_t;
enum class MSStructAttrSpelling : uint8_t;
enum class MayAliasAttrSpelling : uint8_t;
enum class MaybeUndefAttrSpelling : uint8_t;
enum class MicroMipsAttrSpelling : uint8_t;
enum class MinSizeAttrSpelling : uint8_t;
enum class MinVectorWidthAttrSpelling : uint8_t;
enum class Mips16AttrSpelling : uint8_t;
enum class MipsInterruptAttrInterruptType : uint8_t;
enum class MipsInterruptAttrSpelling : uint8_t;
enum class MipsLongCallAttrSpelling : uint8_t;
enum class MipsShortCallAttrSpelling : uint8_t;
enum class ModeAttrSpelling : uint8_t;
enum class MustTailAttrSpelling : uint8_t;
enum class NSConsumedAttrSpelling : uint8_t;
enum class NSConsumesSelfAttrSpelling : uint8_t;
enum class NSReturnsAutoreleasedAttrSpelling : uint8_t;
enum class NSReturnsNotRetainedAttrSpelling : uint8_t;
enum class NSReturnsRetainedAttrSpelling : uint8_t;
enum class NVPTXKernelAttrSpelling : uint8_t;
enum class NakedAttrSpelling : uint8_t;
enum class NamedDeclExplicitVisibilityKind : uint8_t;
enum class NoBuiltinAttrSpelling : uint8_t;
enum class NoCommonAttrSpelling : uint8_t;
enum class NoDebugAttrSpelling : uint8_t;
enum class NoDerefAttrSpelling : uint8_t;
enum class NoDestroyAttrSpelling : uint8_t;
enum class NoDuplicateAttrSpelling : uint8_t;
enum class NoEscapeAttrSpelling : uint8_t;
enum class NoInlineAttrSpelling : uint8_t;
enum class NoInstrumentFunctionAttrSpelling : uint8_t;
enum class NoMergeAttrSpelling : uint8_t;
enum class NoMicroMipsAttrSpelling : uint8_t;
enum class NoMips16AttrSpelling : uint8_t;
enum class NoProfileFunctionAttrSpelling : uint8_t;
enum class NoRandomizeLayoutAttrSpelling : uint8_t;
enum class NoReturnAttrSpelling : uint8_t;
enum class NoSanitizeAttrSpelling : uint8_t;
enum class NoSpeculativeLoadHardeningAttrSpelling : uint8_t;
enum class NoSplitStackAttrSpelling : uint8_t;
enum class NoStackProtectorAttrSpelling : uint8_t;
enum class NoThreadSafetyAnalysisAttrSpelling : uint8_t;
enum class NoThrowAttrSpelling : uint8_t;
enum class NoUwtableAttrSpelling : uint8_t;
enum class NonNullAttrSpelling : uint8_t;
enum class NotTailCalledAttrSpelling : uint8_t;
enum class OMPAllocateDeclAttrAllocatorTypeTy : uint8_t;
enum class OMPDeclareReductionDeclInitKind : uint8_t;
enum class OMPDeclareSimdDeclAttrBranchStateTy : uint8_t;
enum class OMPDeclareTargetDeclAttrDevTypeTy : uint8_t;
enum class OMPDeclareTargetDeclAttrMapTypeTy : uint8_t;
enum class OSConsumedAttrSpelling : uint8_t;
enum class OSConsumesThisAttrSpelling : uint8_t;
enum class OSReturnsNotRetainedAttrSpelling : uint8_t;
enum class OSReturnsRetainedAttrSpelling : uint8_t;
enum class OSReturnsRetainedOnNonZeroAttrSpelling : uint8_t;
enum class OSReturnsRetainedOnZeroAttrSpelling : uint8_t;
enum class ObjCBoxableAttrSpelling : uint8_t;
enum class ObjCBridgeAttrSpelling : uint8_t;
enum class ObjCBridgeMutableAttrSpelling : uint8_t;
enum class ObjCBridgeRelatedAttrSpelling : uint8_t;
enum class ObjCClassStubAttrSpelling : uint8_t;
enum class ObjCDesignatedInitializerAttrSpelling : uint8_t;
enum class ObjCDirectAttrSpelling : uint8_t;
enum class ObjCDirectMembersAttrSpelling : uint8_t;
enum class ObjCExceptionAttrSpelling : uint8_t;
enum class ObjCExplicitProtocolImplAttrSpelling : uint8_t;
enum class ObjCExternallyRetainedAttrSpelling : uint8_t;
enum class ObjCGCAttrSpelling : uint8_t;
enum class ObjCIndependentClassAttrSpelling : uint8_t;
enum class ObjCIvarDeclAccessControl : uint8_t;
enum class ObjCMessageExprReceiverKind : uint8_t;
enum class ObjCMethodDeclImplementationControl : uint8_t;
enum class ObjCMethodFamilyAttrFamilyKind : uint8_t;
enum class ObjCMethodFamilyAttrSpelling : uint8_t;
enum class ObjCNSObjectAttrSpelling : uint8_t;
enum class ObjCNonLazyClassAttrSpelling : uint8_t;
enum class ObjCNonRuntimeProtocolAttrSpelling : uint8_t;
enum class ObjCOwnershipAttrSpelling : uint8_t;
enum class ObjCPreciseLifetimeAttrSpelling : uint8_t;
enum class ObjCPropertyDeclPropertyControl : uint8_t;
enum class ObjCPropertyDeclSetterKind : uint8_t;
enum class ObjCPropertyImplDeclKind : uint8_t;
enum class ObjCRequiresPropertyDefsAttrSpelling : uint8_t;
enum class ObjCRequiresSuperAttrSpelling : uint8_t;
enum class ObjCReturnsInnerPointerAttrSpelling : uint8_t;
enum class ObjCRootClassAttrSpelling : uint8_t;
enum class ObjCRuntimeNameAttrSpelling : uint8_t;
enum class ObjCRuntimeVisibleAttrSpelling : uint8_t;
enum class ObjCSubclassingRestrictedAttrSpelling : uint8_t;
enum class OpenCLAccessAttrSpelling : uint8_t;
enum class OpenCLConstantAddressSpaceAttrSpelling : uint8_t;
enum class OpenCLGenericAddressSpaceAttrSpelling : uint8_t;
enum class OpenCLGlobalAddressSpaceAttrSpelling : uint8_t;
enum class OpenCLGlobalDeviceAddressSpaceAttrSpelling : uint8_t;
enum class OpenCLGlobalHostAddressSpaceAttrSpelling : uint8_t;
enum class OpenCLKernelAttrSpelling : uint8_t;
enum class OpenCLLocalAddressSpaceAttrSpelling : uint8_t;
enum class OpenCLPrivateAddressSpaceAttrSpelling : uint8_t;
enum class OptimizeNoneAttrSpelling : uint8_t;
enum class OverloadableAttrSpelling : uint8_t;
enum class OwnershipAttrOwnershipKind : uint8_t;
enum class OwnershipAttrSpelling : uint8_t;
enum class PackedAttrSpelling : uint8_t;
enum class ParamTypestateAttrConsumedState : uint8_t;
enum class ParamTypestateAttrSpelling : uint8_t;
enum class PascalAttrSpelling : uint8_t;
enum class PassObjectSizeAttrSpelling : uint8_t;
enum class PatchableFunctionEntryAttrSpelling : uint8_t;
enum class PcsAttrPCSType : uint8_t;
enum class PcsAttrSpelling : uint8_t;
enum class PredefinedExprIdentKind : uint8_t;
enum class PreferredNameAttrSpelling : uint8_t;
enum class PreserveAllAttrSpelling : uint8_t;
enum class PreserveMostAttrSpelling : uint8_t;
enum class PtGuardedVarAttrSpelling : uint8_t;
enum class PureAttrSpelling : uint8_t;
enum class QualifiedTypeDestructionKind : uint8_t;
enum class QualifiedTypePrimitiveCopyKind : uint8_t;
enum class QualifiedTypePrimitiveDefaultInitializeKind : uint8_t;
enum class RISCVInterruptAttrInterruptType : uint8_t;
enum class RISCVInterruptAttrSpelling : uint8_t;
enum class RandomizeLayoutAttrSpelling : uint8_t;
enum class ReadOnlyPlacementAttrSpelling : uint8_t;
enum class RecordDeclArgPassingKind : uint8_t;
enum class RegCallAttrSpelling : uint8_t;
enum class ReinitializesAttrSpelling : uint8_t;
enum class ReleaseCapabilityAttrSpelling : uint8_t;
enum class ReleaseHandleAttrSpelling : uint8_t;
enum class RequiresCapabilityAttrSpelling : uint8_t;
enum class RestrictAttrSpelling : uint8_t;
enum class RetainAttrSpelling : uint8_t;
enum class ReturnTypestateAttrConsumedState : uint8_t;
enum class ReturnTypestateAttrSpelling : uint8_t;
enum class ReturnsNonNullAttrSpelling : uint8_t;
enum class ReturnsTwiceAttrSpelling : uint8_t;
enum class SYCLKernelAttrSpelling : uint8_t;
enum class SYCLSpecialClassAttrSpelling : uint8_t;
enum class ScopedLockableAttrSpelling : uint8_t;
enum class SectionAttrSpelling : uint8_t;
enum class SelectAnyAttrSpelling : uint8_t;
enum class SentinelAttrSpelling : uint8_t;
enum class SetTypestateAttrConsumedState : uint8_t;
enum class SetTypestateAttrSpelling : uint8_t;
enum class SourceLocExprIdentKind : uint8_t;
enum class SpeculativeLoadHardeningAttrSpelling : uint8_t;
enum class StandaloneDebugAttrSpelling : uint8_t;
enum class StdCallAttrSpelling : uint8_t;
enum class StmtLikelihood : uint8_t;
enum class StmtKind : uint8_t;
enum class StringLiteralStringKind : uint8_t;
enum class SwiftAsyncAttrKind : uint8_t;
enum class SwiftAsyncAttrSpelling : uint8_t;
enum class SwiftAsyncCallAttrSpelling : uint8_t;
enum class SwiftAsyncContextAttrSpelling : uint8_t;
enum class SwiftAsyncErrorAttrConventionKind : uint8_t;
enum class SwiftAsyncErrorAttrSpelling : uint8_t;
enum class SwiftCallAttrSpelling : uint8_t;
enum class SwiftContextAttrSpelling : uint8_t;
enum class SwiftErrorAttrConventionKind : uint8_t;
enum class SwiftErrorResultAttrSpelling : uint8_t;
enum class SwiftIndirectResultAttrSpelling : uint8_t;
enum class SwiftNewTypeAttrNewtypeKind : uint8_t;
enum class SwiftNewTypeAttrSpelling : uint8_t;
enum class SysVABIAttrSpelling : uint8_t;
enum class TLSModelAttrSpelling : uint8_t;
enum class TargetAttrSpelling : uint8_t;
enum class TargetClonesAttrSpelling : uint8_t;
enum class TargetVersionAttrSpelling : uint8_t;
enum class TemplateArgumentKind : uint8_t;
enum class TestTypestateAttrConsumedState : uint8_t;
enum class TestTypestateAttrSpelling : uint8_t;
enum class ThisCallAttrSpelling : uint8_t;
enum class TransparentUnionAttrSpelling : uint8_t;
enum class TrivialABIAttrSpelling : uint8_t;
enum class TryAcquireCapabilityAttrSpelling : uint8_t;
enum class TypeScalarTypeKind : uint8_t;
enum class TypeKind : uint8_t;
enum class TypeTagForDatatypeAttrSpelling : uint8_t;
enum class TypeVisibilityAttrSpelling : uint8_t;
enum class TypeVisibilityAttrVisibilityType : uint8_t;
enum class UnaryTransformTypeUTTKind : uint8_t;
enum class UnavailableAttrImplicitReason : uint8_t;
enum class UnavailableAttrSpelling : uint8_t;
enum class UninitializedAttrSpelling : uint8_t;
enum class UnlikelyAttrSpelling : uint8_t;
enum class UnsafeBufferUsageAttrSpelling : uint8_t;
enum class UnusedAttrSpelling : uint8_t;
enum class UseHandleAttrSpelling : uint8_t;
enum class UsedAttrSpelling : uint8_t;
enum class UserDefinedLiteralLiteralOperatorKind : uint8_t;
enum class UsingIfExistsAttrSpelling : uint8_t;
enum class UuidAttrSpelling : uint8_t;
enum class VarDeclDefinitionKind : uint8_t;
enum class VarDeclInitializationStyle : uint8_t;
enum class VarDeclTLSKind : uint8_t;
enum class VecReturnAttrSpelling : uint8_t;
enum class VectorCallAttrSpelling : uint8_t;
enum class VectorTypeVectorKind : uint8_t;
enum class VisibilityAttrSpelling : uint8_t;
enum class VisibilityAttrVisibilityType : uint8_t;
enum class WarnUnusedAttrSpelling : uint8_t;
enum class WarnUnusedResultAttrSpelling : uint8_t;
enum class WeakAttrSpelling : uint8_t;
enum class WeakImportAttrSpelling : uint8_t;
enum class WeakRefAttrSpelling : uint8_t;
enum class WebAssemblyExportNameAttrSpelling : uint8_t;
enum class WebAssemblyImportModuleAttrSpelling : uint8_t;
enum class WebAssemblyImportNameAttrSpelling : uint8_t;
enum class X86ForceAlignArgPointerAttrSpelling : uint8_t;
enum class XRayInstrumentAttrSpelling : uint8_t;
enum class XRayLogArgsAttrSpelling : uint8_t;
enum class ZeroCallUsedRegsAttrSpelling : uint8_t;
enum class ZeroCallUsedRegsAttrZeroCallUsedRegsKind : uint8_t;
enum class ASTDumpOutputFormat : uint8_t;
enum class AccessSpecifier : uint8_t;
enum class AddrSpaceMapMangling : uint8_t;
enum class AlignRequirementKind : uint8_t;
enum class AltivecSrcCompatKind : uint8_t;
enum class ArgumentKind : uint8_t;
enum class ArrayTypeTrait : uint8_t;
enum class AssignmentTrackingOpts : uint8_t;
enum class AtomicScopeModelKind : uint8_t;
enum class AutoTypeKeyword : uint8_t;
enum class AvailabilityResult : uint8_t;
enum class BinaryOperatorKind : uint8_t;
enum class Bits : uint8_t;
enum class CallingConv : uint8_t;
enum class CanThrowResult : uint8_t;
enum class CapturedRegionKind : uint8_t;
enum class CastKind : uint8_t;
enum class ClangABI : uint8_t;
enum class CommentKind : uint8_t;
enum class ComparisonCategoryResult : uint8_t;
enum class ComparisonCategoryType : uint8_t;
enum class CompilingModuleKind : uint8_t;
enum class ConstexprSpecKind : uint8_t;
enum class CoreFoundationABI : uint8_t;
enum class DataPositionTy : uint8_t;
enum class DebugSrcHashKind : uint8_t;
enum class DeductionCandidate : uint8_t;
enum class DefaultArgKind : uint8_t;
enum class DefaultCallingConvention : uint8_t;
enum class DefaultVisiblityExportMapping : uint8_t;
enum class DesignatorKind : uint8_t;
enum class DiagnosticLevelMask : uint8_t;
enum class ElaboratedTypeKeyword : uint8_t;
enum class EmbedBitcodeKind : uint8_t;
enum class EscapeChar : uint8_t;
enum class ExceptionHandlingKind : uint8_t;
enum class ExceptionSpecificationType : uint8_t;
enum class ExcessPrecisionKind : uint8_t;
enum class ExclusionType : uint8_t;
enum class ExplicitSpecKind : uint8_t;
enum class ExprDependence : uint8_t;
enum class ExprObjectKind : uint8_t;
enum class ExprOffsets : uint8_t;
enum class ExprValueKind : uint8_t;
enum class ExpressionTrait : uint8_t;
enum class ExtKind : uint8_t;
enum class ExtendArgsKind : uint8_t;
enum class FPEvalMethodKind : uint8_t;
enum class FPExceptionModeKind : uint8_t;
enum class FPModeKind : uint8_t;
enum class FiniteLoopsKind : uint8_t;
enum class Flags : uint8_t;
enum class FramePointerKind : uint8_t;
enum class GC : uint8_t;
enum class GCMode : uint8_t;
enum class GPUDefaultStreamKind : uint8_t;
enum class GVALinkage : uint8_t;
enum class GetBuiltinTypeError : uint8_t;
enum class HLSLLangStd : uint8_t;
enum class ID : uint8_t;
enum class IdentifierInfoFlag : uint8_t;
enum class IfStatementKind : uint8_t;
enum class ImbueAttribute : uint8_t;
enum class InClassInitStyle : uint8_t;
enum class InheritedDesignatedInitializersState : uint8_t;
enum class InitStorageKind : uint8_t;
enum class InlineAsmDialectKind : uint8_t;
enum class InlineVariableDefinitionKind : uint8_t;
enum class InliningMethod : uint8_t;
enum class InterestingIdentifierKind : uint8_t;
enum class Kinds : uint8_t;
enum class LambdaCaptureDefault : uint8_t;
enum class LambdaCaptureKind : uint8_t;
enum class LangAS : uint8_t;
enum class LangFeatures : uint8_t;
enum class Language : uint8_t;
enum class LanguageLinkage : uint8_t;
enum class LaxVectorConversionKind : uint8_t;
enum class Level : uint8_t;
enum class Linkage : uint8_t;
enum class MSInheritanceModel : uint8_t;
enum class MSVCMajorVersion : uint8_t;
enum class MSVtorDispMode : uint8_t;
enum class MethodRefFlags : uint8_t;
enum class ModifiableType : uint8_t;
enum class MultiVersionKind : uint8_t;
enum class NameKind : uint8_t;
enum class NeedExtraManglingDecl : uint8_t;
enum class NestedNameSpecifierDependence : uint8_t;
enum class NonOdrUseReason : uint8_t;
enum class NonceObjCInterface : uint8_t;
enum class NullabilityKind : uint8_t;
enum class ObjCBridgeCastKind : uint8_t;
enum class ObjCDispatchMethodKind : uint8_t;
enum class ObjCInstanceTypeFamily : uint8_t;
enum class ObjCLifetime : uint8_t;
enum class ObjCMethodFamily : uint8_t;
enum class ObjCPropertyQueryKind : uint8_t;
enum class ObjCStringFormatFamily : uint8_t;
enum class ObjCSubstitutionContext : uint8_t;
enum class ObjCTypeParamVariance : uint8_t;
enum class OnOffSwitch : uint8_t;
enum class OnStackType : uint8_t;
enum class OpenMPAdjustArgsOpKind : uint8_t;
enum class OpenMPAtClauseKind : uint8_t;
enum class OpenMPAtomicDefaultMemOrderClauseKind : uint8_t;
enum class OpenMPBindClauseKind : uint8_t;
enum class OpenMPDefaultmapClauseKind : uint8_t;
enum class OpenMPDefaultmapClauseModifier : uint8_t;
enum class OpenMPDependClauseKind : uint8_t;
enum class OpenMPDeviceClauseModifier : uint8_t;
enum class OpenMPDeviceType : uint8_t;
enum class OpenMPDistScheduleClauseKind : uint8_t;
enum class OpenMPDoacrossClauseModifier : uint8_t;
enum class OpenMPGrainsizeClauseModifier : uint8_t;
enum class OpenMPLastprivateModifier : uint8_t;
enum class OpenMPLinearClauseKind : uint8_t;
enum class OpenMPMapClauseKind : uint8_t;
enum class OpenMPMapModifierKind : uint8_t;
enum class OpenMPMotionModifierKind : uint8_t;
enum class OpenMPNumTasksClauseModifier : uint8_t;
enum class OpenMPOrderClauseKind : uint8_t;
enum class OpenMPOrderClauseModifier : uint8_t;
enum class OpenMPReductionClauseModifier : uint8_t;
enum class OpenMPScheduleClauseKind : uint8_t;
enum class OpenMPScheduleClauseModifier : uint8_t;
enum class OpenMPSeverityClauseKind : uint8_t;
enum class OverloadedOperatorKind : uint8_t;
enum class OverloadsShown : uint8_t;
enum class ParameterABI : uint8_t;
enum class ParenLocsOffsets : uint8_t;
enum class PragmaFloatControlKind : uint8_t;
enum class PragmaMSCommentKind : uint8_t;
enum class PragmaMSPointersToMembersKind : uint8_t;
enum class PragmaMSStructKind : uint8_t;
enum class PragmaSectionFlag : uint8_t;
enum class ProfileInstrKind : uint8_t;
enum class Qualified : uint8_t;
enum class RangeExprOffset : uint8_t;
enum class RangeLocOffset : uint8_t;
enum class RefQualifierKind : uint8_t;
enum class RemarkKind : uint8_t;
enum class ReservedIdentifierStatus : uint8_t;
enum class ReservedLiteralSuffixIdStatus : uint8_t;
enum class SFINAEResponse : uint8_t;
enum class SYCLMajorVersion : uint8_t;
enum class SanitizerOrdinal : uint8_t;
enum class SelectorLocationsKind : uint8_t;
enum class ShaderStage : uint8_t;
enum class SignReturnAddressKeyKind : uint8_t;
enum class SignReturnAddressScopeKind : uint8_t;
enum class SignedOverflowBehaviorTy : uint8_t;
enum class SpecialMemberFlags : uint8_t;
enum class SpecifierKind : uint8_t;
enum class StackProtectorMode : uint8_t;
enum class StorageClass : uint8_t;
enum class StorageDuration : uint8_t;
enum class StoredNameKind : uint8_t;
enum class StoredSpecifierKind : uint8_t;
enum class StrictFlexArraysLevelKind : uint8_t;
enum class StructReturnConventionKind : uint8_t;
enum class SubExpr : uint8_t;
enum class SubStmt : uint8_t;
enum class SwiftAsyncFramePointerKind : uint8_t;
enum class SyncScope : uint8_t;
enum class Syntax : uint8_t;
enum class TLSModel : uint8_t;
enum class TQ : uint8_t;
enum class TagTypeKind : uint8_t;
enum class TailPaddingUseRules : uint8_t;
enum class TemplateArgumentDependence : uint8_t;
enum class TemplateNameDependence : uint8_t;
enum class TemplateSpecializationKind : uint8_t;
enum class TextDiagnosticFormat : uint8_t;
enum class ThreadModelKind : uint8_t;
enum class ThreadStorageClassSpecifier : uint8_t;
enum class TrailingAllocKind : uint8_t;
enum class TranslationUnitKind : uint8_t;
enum class TrivialAutoVarInitKind : uint8_t;
enum class TypeDependence : uint8_t;
enum class TypeLocClass : uint8_t;
enum class TypeOfKind : uint8_t;
enum class TypeSpecifierSign : uint8_t;
enum class TypeSpecifierType : uint8_t;
enum class TypeSpecifierWidth : uint8_t;
enum class TypeSpecifiersPipe : uint8_t;
enum class TypeTrait : uint8_t;
enum class UnaryExprOrTypeTrait : uint8_t;
enum class UnaryOperatorKind : uint8_t;
enum class APValueKind : uint8_t;
enum class VectorLibrary : uint8_t;
enum class Visibility : uint8_t;
enum class AttributeSyntax : uint8_t;
enum class DeclCategory : uint8_t;
enum class PseudoKind : uint8_t;
enum class EntityCategory : int32_t;
class TokenContext;
class Designator;
class CXXBaseSpecifier;
class TemplateParameterList;
class TemplateArgument;
class Attr;
class AlignValueAttr;
class AliasAttr;
class AbiTagAttr;
class TypeAttr;
class SPtrAttr;
class Ptr64Attr;
class Ptr32Attr;
class OpenCLPrivateAddressSpaceAttr;
class OpenCLLocalAddressSpaceAttr;
class OpenCLGlobalHostAddressSpaceAttr;
class OpenCLGlobalDeviceAddressSpaceAttr;
class OpenCLGlobalAddressSpaceAttr;
class OpenCLGenericAddressSpaceAttr;
class OpenCLConstantAddressSpaceAttr;
class ObjCKindOfAttr;
class ObjCInertUnsafeUnretainedAttr;
class ObjCGCAttr;
class NoDerefAttr;
class HLSLGroupSharedAddressSpaceAttr;
class CmseNSCallAttr;
class BTFTypeTagAttr;
class ArmStreamingAttr;
class ArmMveStrictPolymorphismAttr;
class AnnotateTypeAttr;
class AddressSpaceAttr;
class WebAssemblyFuncrefAttr;
class UPtrAttr;
class TypeNullableResultAttr;
class TypeNullableAttr;
class TypeNullUnspecifiedAttr;
class TypeNonNullAttr;
class ThreadAttr;
class SwiftObjCMembersAttr;
class StmtAttr;
class OpenCLUnrollHintAttr;
class MustTailAttr;
class LikelyAttr;
class FallThroughAttr;
class UnlikelyAttr;
class SuppressAttr;
class RenderScriptKernelAttr;
class OverloadableAttr;
class OpenCLAccessAttr;
class ObjCRuntimeVisibleAttr;
class ObjCRuntimeNameAttr;
class ObjCNonRuntimeProtocolAttr;
class ObjCNonLazyClassAttr;
class ObjCDirectMembersAttr;
class ObjCDirectAttr;
class ObjCDesignatedInitializerAttr;
class ObjCClassStubAttr;
class ObjCBoxableAttr;
class OMPReferencedVarAttr;
class OMPDeclareSimdDeclAttr;
class OMPCaptureKindAttr;
class NoEscapeAttr;
class NoBuiltinAttr;
class ModeAttr;
class LoopHintAttr;
class LoaderUninitializedAttr;
class InitSegAttr;
class InheritableAttr;
class IBOutletCollectionAttr;
class IBOutletAttr;
class IBActionAttr;
class HotAttr;
class HLSLShaderAttr;
class HLSLResourceBindingAttr;
class HLSLResourceAttr;
class HLSLNumThreadsAttr;
class HLSLAnnotationAttr;
class HLSLSV_GroupIndexAttr;
class HLSLSV_DispatchThreadIDAttr;
class HIPManagedAttr;
class GuardedVarAttr;
class GuardedByAttr;
class GNUInlineAttr;
class FunctionReturnThunksAttr;
class FormatAttr;
class FormatArgAttr;
class FlattenAttr;
class FlagEnumAttr;
class FinalAttr;
class FastCallAttr;
class ExternalSourceSymbolAttr;
class ExclusiveTrylockFunctionAttr;
class ExcludeFromExplicitInstantiationAttr;
class ErrorAttr;
class EnumExtensibilityAttr;
class EnforceTCBLeafAttr;
class EnforceTCBAttr;
class EnableIfAttr;
class EmptyBasesAttr;
class DisableTailCallsAttr;
class DisableSanitizerInstrumentationAttr;
class DiagnoseIfAttr;
class DiagnoseAsBuiltinAttr;
class DestructorAttr;
class DeprecatedAttr;
class DeclOrStmtAttr;
class AlwaysInlineAttr;
class NoMergeAttr;
class NoInlineAttr;
class DLLImportStaticLocalAttr;
class DLLImportAttr;
class DLLExportStaticLocalAttr;
class DLLExportAttr;
class ConvergentAttr;
class ConsumableSetOnReadAttr;
class ConsumableAutoCastAttr;
class ConsumableAttr;
class ConstructorAttr;
class ConstInitAttr;
class ConstAttr;
class CommonAttr;
class ColdAttr;
class CodeSegAttr;
class CmseNSEntryAttr;
class CleanupAttr;
class CapturedRecordAttr;
class CapabilityAttr;
class CallbackAttr;
class CallableWhenAttr;
class CXX11NoReturnAttr;
class CUDASharedAttr;
class CUDALaunchBoundsAttr;
class CUDAInvalidTargetAttr;
class CUDAHostAttr;
class CUDAGlobalAttr;
class CUDADeviceBuiltinTextureTypeAttr;
class CUDADeviceBuiltinSurfaceTypeAttr;
class CUDADeviceAttr;
class CUDAConstantAttr;
class CPUSpecificAttr;
class CPUDispatchAttr;
class CFUnknownTransferAttr;
class CFReturnsRetainedAttr;
class CFReturnsNotRetainedAttr;
class CFICanonicalJumpTableAttr;
class CFGuardAttr;
class CFAuditedTransferAttr;
class CDeclAttr;
class C11NoReturnAttr;
class BuiltinAttr;
class BlocksAttr;
class BTFDeclTagAttr;
class BPFPreserveAccessIndexAttr;
class AvailableOnlyInDefaultEvalMethodAttr;
class AvailabilityAttr;
class AssumptionAttr;
class AssumeAlignedAttr;
class AssertSharedLockAttr;
class AssertExclusiveLockAttr;
class AssertCapabilityAttr;
class AsmLabelAttr;
class ArtificialAttr;
class ArmBuiltinAliasAttr;
class ArgumentWithTypeTagAttr;
class ArcWeakrefUnavailableAttr;
class AnyX86NoCfCheckAttr;
class AnyX86NoCallerSavedRegistersAttr;
class AnyX86InterruptAttr;
class AnalyzerNoReturnAttr;
class AlwaysDestroyAttr;
class AllocSizeAttr;
class AllocAlignAttr;
class AlignedAttr;
class AlignNaturalAttr;
class AlignMac68kAttr;
class AcquiredBeforeAttr;
class AcquiredAfterAttr;
class AcquireHandleAttr;
class AcquireCapabilityAttr;
class AVRSignalAttr;
class AVRInterruptAttr;
class ARMInterruptAttr;
class AMDGPUWavesPerEUAttr;
class AMDGPUNumVGPRAttr;
class AMDGPUNumSGPRAttr;
class AMDGPUKernelCallAttr;
class AMDGPUFlatWorkGroupSizeAttr;
class AArch64VectorPcsAttr;
class AArch64SVEPcsAttr;
class ZeroCallUsedRegsAttr;
class XRayLogArgsAttr;
class XRayInstrumentAttr;
class X86ForceAlignArgPointerAttr;
class WorkGroupSizeHintAttr;
class WebAssemblyImportNameAttr;
class WebAssemblyImportModuleAttr;
class WebAssemblyExportNameAttr;
class WeakRefAttr;
class WeakImportAttr;
class WeakAttr;
class WarnUnusedResultAttr;
class WarnUnusedAttr;
class VisibilityAttr;
class VectorCallAttr;
class VecTypeHintAttr;
class VecReturnAttr;
class UuidAttr;
class UsingIfExistsAttr;
class UsedAttr;
class UnusedAttr;
class UnsafeBufferUsageAttr;
class UninitializedAttr;
class UnavailableAttr;
class TypeVisibilityAttr;
class TypeTagForDatatypeAttr;
class TryAcquireCapabilityAttr;
class TrivialABIAttr;
class TransparentUnionAttr;
class ThisCallAttr;
class TestTypestateAttr;
class TargetVersionAttr;
class TargetClonesAttr;
class TargetAttr;
class TLSModelAttr;
class SysVABIAttr;
class SwiftPrivateAttr;
class SwiftNewTypeAttr;
class SwiftNameAttr;
class SwiftErrorAttr;
class SwiftCallAttr;
class SwiftBridgedTypedefAttr;
class SwiftBridgeAttr;
class SwiftAttrAttr;
class SwiftAsyncNameAttr;
class SwiftAsyncErrorAttr;
class SwiftAsyncCallAttr;
class SwiftAsyncAttr;
class StrictGuardStackCheckAttr;
class StrictFPAttr;
class StdCallAttr;
class StandaloneDebugAttr;
class SpeculativeLoadHardeningAttr;
class SharedTrylockFunctionAttr;
class SetTypestateAttr;
class SentinelAttr;
class SelectAnyAttr;
class SectionAttr;
class ScopedLockableAttr;
class SYCLSpecialClassAttr;
class SYCLKernelAttr;
class ReturnsTwiceAttr;
class ReturnsNonNullAttr;
class ReturnTypestateAttr;
class RetainAttr;
class RestrictAttr;
class RequiresCapabilityAttr;
class ReqdWorkGroupSizeAttr;
class ReleaseCapabilityAttr;
class ReinitializesAttr;
class RegCallAttr;
class ReadOnlyPlacementAttr;
class RandomizeLayoutAttr;
class RISCVInterruptAttr;
class PureAttr;
class PtGuardedVarAttr;
class PtGuardedByAttr;
class PreserveMostAttr;
class PreserveAllAttr;
class PreferredNameAttr;
class PragmaClangTextSectionAttr;
class PragmaClangRodataSectionAttr;
class PragmaClangRelroSectionAttr;
class PragmaClangDataSectionAttr;
class PragmaClangBSSSectionAttr;
class PointerAttr;
class PcsAttr;
class PatchableFunctionEntryAttr;
class PascalAttr;
class ParamTypestateAttr;
class PackedAttr;
class OwnershipAttr;
class OwnerAttr;
class OverrideAttr;
class OptimizeNoneAttr;
class OpenCLKernelAttr;
class OpenCLIntelReqdSubGroupSizeAttr;
class ObjCSubclassingRestrictedAttr;
class ObjCRootClassAttr;
class ObjCReturnsInnerPointerAttr;
class ObjCRequiresSuperAttr;
class ObjCRequiresPropertyDefsAttr;
class ObjCPreciseLifetimeAttr;
class ObjCOwnershipAttr;
class ObjCNSObjectAttr;
class ObjCMethodFamilyAttr;
class ObjCIndependentClassAttr;
class ObjCExternallyRetainedAttr;
class ObjCExplicitProtocolImplAttr;
class ObjCExceptionAttr;
class ObjCBridgeRelatedAttr;
class ObjCBridgeMutableAttr;
class ObjCBridgeAttr;
class OSReturnsRetainedOnZeroAttr;
class OSReturnsRetainedOnNonZeroAttr;
class OSReturnsRetainedAttr;
class OSReturnsNotRetainedAttr;
class OSConsumesThisAttr;
class OMPThreadPrivateDeclAttr;
class OMPDeclareVariantAttr;
class OMPDeclareTargetDeclAttr;
class OMPCaptureNoInitAttr;
class OMPAllocateDeclAttr;
class NotTailCalledAttr;
class NoUwtableAttr;
class NoUniqueAddressAttr;
class NoThrowAttr;
class NoThreadSafetyAnalysisAttr;
class NoStackProtectorAttr;
class NoSplitStackAttr;
class NoSpeculativeLoadHardeningAttr;
class NoSanitizeAttr;
class NoReturnAttr;
class NoRandomizeLayoutAttr;
class NoProfileFunctionAttr;
class NoMips16Attr;
class NoMicroMipsAttr;
class NoInstrumentFunctionAttr;
class NoDuplicateAttr;
class NoDestroyAttr;
class NoDebugAttr;
class NoCommonAttr;
class NoAliasAttr;
class NakedAttr;
class NVPTXKernelAttr;
class NSReturnsRetainedAttr;
class NSReturnsNotRetainedAttr;
class NSReturnsAutoreleasedAttr;
class NSErrorDomainAttr;
class NSConsumesSelfAttr;
class MipsShortCallAttr;
class MipsLongCallAttr;
class MipsInterruptAttr;
class Mips16Attr;
class MinVectorWidthAttr;
class MinSizeAttr;
class MicroMipsAttr;
class MaybeUndefAttr;
class MayAliasAttr;
class MaxFieldAlignmentAttr;
class MSVtorDispAttr;
class MSStructAttr;
class MSP430InterruptAttr;
class MSNoVTableAttr;
class MSInheritanceAttr;
class MSAllocatorAttr;
class MSABIAttr;
class MIGServerRoutineAttr;
class M68kInterruptAttr;
class LocksExcludedAttr;
class LockReturnedAttr;
class LifetimeBoundAttr;
class LeafAttr;
class LayoutVersionAttr;
class LTOVisibilityPublicAttr;
class InternalLinkageAttr;
class IntelOclBiccAttr;
class InitPriorityAttr;
class InheritableParamAttr;
class CarriesDependencyAttr;
class CFConsumedAttr;
class AnnotateAttr;
class UseHandleAttr;
class ReleaseHandleAttr;
class PassObjectSizeAttr;
class ParameterABIAttr;
class SwiftIndirectResultAttr;
class SwiftErrorResultAttr;
class SwiftContextAttr;
class SwiftAsyncContextAttr;
class OSConsumedAttr;
class NonNullAttr;
class NSConsumedAttr;
class IFuncAttr;
class CalledOnceAttr;
class BuiltinAliasAttr;
class Type;
class TemplateTypeParmType;
class TemplateSpecializationType;
class TagType;
class RecordType;
class EnumType;
class SubstTemplateTypeParmType;
class SubstTemplateTypeParmPackType;
class ReferenceType;
class RValueReferenceType;
class LValueReferenceType;
class QualifiedType;
class PointerType;
class PipeType;
class ParenType;
class PackExpansionType;
class ObjCTypeParamType;
class ObjCObjectType;
class ObjCInterfaceType;
class ObjCObjectPointerType;
class MemberPointerType;
class MatrixType;
class DependentSizedMatrixType;
class ConstantMatrixType;
class MacroQualifiedType;
class InjectedClassNameType;
class FunctionType;
class FunctionProtoType;
class FunctionNoProtoType;
class DependentVectorType;
class DependentSizedExtVectorType;
class DependentBitIntType;
class DependentAddressSpaceType;
class DeducedType;
class DeducedTemplateSpecializationType;
class AutoType;
class DecltypeType;
class ComplexType;
class BuiltinType;
class BlockPointerType;
class BitIntType;
class BTFTagAttributedType;
class AttributedType;
class AtomicType;
class ArrayType;
class VariableArrayType;
class IncompleteArrayType;
class DependentSizedArrayType;
class ConstantArrayType;
class AdjustedType;
class DecayedType;
class TypeWithKeyword;
class ElaboratedType;
class DependentTemplateSpecializationType;
class DependentNameType;
class VectorType;
class ExtVectorType;
class UsingType;
class UnresolvedUsingType;
class UnaryTransformType;
class TypedefType;
class TypeOfType;
class TypeOfExprType;
class Stmt;
class SEHTryStmt;
class SEHLeaveStmt;
class SEHFinallyStmt;
class SEHExceptStmt;
class ReturnStmt;
class ObjCForCollectionStmt;
class ObjCAutoreleasePoolStmt;
class ObjCAtTryStmt;
class ObjCAtThrowStmt;
class ObjCAtSynchronizedStmt;
class ObjCAtFinallyStmt;
class ObjCAtCatchStmt;
class OMPExecutableDirective;
class OMPErrorDirective;
class OMPDispatchDirective;
class OMPDepobjDirective;
class OMPCriticalDirective;
class OMPCancellationPointDirective;
class OMPCancelDirective;
class OMPBarrierDirective;
class OMPAtomicDirective;
class OMPTeamsDirective;
class OMPTaskyieldDirective;
class OMPTaskwaitDirective;
class OMPTaskgroupDirective;
class OMPTaskDirective;
class OMPTargetUpdateDirective;
class OMPTargetTeamsDirective;
class OMPTargetParallelDirective;
class OMPTargetExitDataDirective;
class OMPTargetEnterDataDirective;
class OMPTargetDirective;
class OMPTargetDataDirective;
class OMPSingleDirective;
class OMPSectionsDirective;
class OMPSectionDirective;
class OMPScanDirective;
class OMPParallelSectionsDirective;
class OMPParallelMasterDirective;
class OMPParallelMaskedDirective;
class OMPParallelDirective;
class OMPOrderedDirective;
class OMPMetaDirective;
class OMPMasterDirective;
class OMPMaskedDirective;
class OMPLoopBasedDirective;
class OMPLoopTransformationDirective;
class OMPUnrollDirective;
class OMPTileDirective;
class OMPLoopDirective;
class OMPGenericLoopDirective;
class OMPForSimdDirective;
class OMPForDirective;
class OMPDistributeSimdDirective;
class OMPDistributeParallelForSimdDirective;
class OMPDistributeParallelForDirective;
class OMPDistributeDirective;
class OMPTeamsGenericLoopDirective;
class OMPTeamsDistributeSimdDirective;
class OMPTeamsDistributeParallelForSimdDirective;
class OMPTeamsDistributeParallelForDirective;
class OMPTeamsDistributeDirective;
class OMPTaskLoopSimdDirective;
class OMPTaskLoopDirective;
class OMPTargetTeamsGenericLoopDirective;
class OMPTargetTeamsDistributeSimdDirective;
class OMPTargetTeamsDistributeParallelForSimdDirective;
class OMPTargetTeamsDistributeParallelForDirective;
class OMPTargetTeamsDistributeDirective;
class OMPTargetSimdDirective;
class OMPTargetParallelGenericLoopDirective;
class OMPTargetParallelForSimdDirective;
class OMPTargetParallelForDirective;
class OMPSimdDirective;
class OMPParallelMasterTaskLoopSimdDirective;
class OMPParallelMasterTaskLoopDirective;
class OMPParallelMaskedTaskLoopSimdDirective;
class OMPParallelMaskedTaskLoopDirective;
class OMPParallelGenericLoopDirective;
class OMPParallelForSimdDirective;
class OMPParallelForDirective;
class OMPMasterTaskLoopSimdDirective;
class OMPMasterTaskLoopDirective;
class OMPMaskedTaskLoopSimdDirective;
class OMPMaskedTaskLoopDirective;
class OMPInteropDirective;
class OMPFlushDirective;
class OMPCanonicalLoop;
class NullStmt;
class MSDependentExistsStmt;
class IndirectGotoStmt;
class IfStmt;
class GotoStmt;
class ForStmt;
class DoStmt;
class DeclStmt;
class CoroutineBodyStmt;
class CoreturnStmt;
class ContinueStmt;
class CompoundStmt;
class CapturedStmt;
class CXXTryStmt;
class CXXForRangeStmt;
class CXXCatchStmt;
class BreakStmt;
class AsmStmt;
class MSAsmStmt;
class GCCAsmStmt;
class WhileStmt;
class ValueStmt;
class LabelStmt;
class Expr;
class DesignatedInitUpdateExpr;
class DesignatedInitExpr;
class DependentScopeDeclRefExpr;
class DependentCoawaitExpr;
class DeclRefExpr;
class CoroutineSuspendExpr;
class CoawaitExpr;
class CoyieldExpr;
class ConvertVectorExpr;
class ConceptSpecializationExpr;
class CompoundLiteralExpr;
class ChooseExpr;
class CharacterLiteral;
class CastExpr;
class ImplicitCastExpr;
class ExplicitCastExpr;
class CXXNamedCastExpr;
class CXXDynamicCastExpr;
class CXXConstCastExpr;
class CXXAddrspaceCastExpr;
class CXXStaticCastExpr;
class CXXReinterpretCastExpr;
class CXXFunctionalCastExpr;
class CStyleCastExpr;
class BuiltinBitCastExpr;
class ObjCBridgedCastExpr;
class CallExpr;
class CXXOperatorCallExpr;
class CXXMemberCallExpr;
class CUDAKernelCallExpr;
class UserDefinedLiteral;
class CXXUuidofExpr;
class CXXUnresolvedConstructExpr;
class CXXTypeidExpr;
class CXXThrowExpr;
class CXXThisExpr;
class CXXStdInitializerListExpr;
class CXXScalarValueInitExpr;
class CXXRewrittenBinaryOperator;
class CXXPseudoDestructorExpr;
class CXXParenListInitExpr;
class CXXNullPtrLiteralExpr;
class CXXNoexceptExpr;
class CXXNewExpr;
class CXXInheritedCtorInitExpr;
class CXXFoldExpr;
class CXXDependentScopeMemberExpr;
class CXXDeleteExpr;
class CXXDefaultInitExpr;
class CXXDefaultArgExpr;
class CXXConstructExpr;
class CXXTemporaryObjectExpr;
class CXXBoolLiteralExpr;
class CXXBindTemporaryExpr;
class BlockExpr;
class BinaryOperator;
class CompoundAssignOperator;
class AtomicExpr;
class AsTypeExpr;
class ArrayTypeTraitExpr;
class ArraySubscriptExpr;
class ArrayInitLoopExpr;
class ArrayInitIndexExpr;
class AddrLabelExpr;
class AbstractConditionalOperator;
class ConditionalOperator;
class BinaryConditionalOperator;
class VAArgExpr;
class UnaryOperator;
class UnaryExprOrTypeTraitExpr;
class TypoExpr;
class TypeTraitExpr;
class SubstNonTypeTemplateParmPackExpr;
class SubstNonTypeTemplateParmExpr;
class StringLiteral;
class StmtExpr;
class SourceLocExpr;
class SizeOfPackExpr;
class ShuffleVectorExpr;
class SYCLUniqueStableNameExpr;
class RequiresExpr;
class RecoveryExpr;
class PseudoObjectExpr;
class PredefinedExpr;
class ParenListExpr;
class ParenExpr;
class PackExpansionExpr;
class OverloadExpr;
class UnresolvedMemberExpr;
class UnresolvedLookupExpr;
class OpaqueValueExpr;
class OffsetOfExpr;
class ObjCSubscriptRefExpr;
class ObjCStringLiteral;
class ObjCSelectorExpr;
class ObjCProtocolExpr;
class ObjCPropertyRefExpr;
class ObjCMessageExpr;
class ObjCIvarRefExpr;
class ObjCIsaExpr;
class ObjCIndirectCopyRestoreExpr;
class ObjCEncodeExpr;
class ObjCDictionaryLiteral;
class ObjCBoxedExpr;
class ObjCBoolLiteralExpr;
class ObjCAvailabilityCheckExpr;
class ObjCArrayLiteral;
class OMPIteratorExpr;
class OMPArrayShapingExpr;
class OMPArraySectionExpr;
class NoInitExpr;
class MemberExpr;
class MatrixSubscriptExpr;
class MaterializeTemporaryExpr;
class MSPropertySubscriptExpr;
class MSPropertyRefExpr;
class LambdaExpr;
class IntegerLiteral;
class InitListExpr;
class ImplicitValueInitExpr;
class ImaginaryLiteral;
class GenericSelectionExpr;
class GNUNullExpr;
class FunctionParmPackExpr;
class FullExpr;
class ExprWithCleanups;
class ConstantExpr;
class FloatingLiteral;
class FixedPointLiteral;
class ExtVectorElementExpr;
class ExpressionTraitExpr;
class AttributedStmt;
class SwitchStmt;
class SwitchCase;
class DefaultStmt;
class CaseStmt;
class Decl;
class ClassScopeFunctionSpecializationDecl;
class CapturedDecl;
class BlockDecl;
class AccessSpecDecl;
class OMPDeclarativeDirectiveDecl;
class OMPThreadPrivateDecl;
class OMPRequiresDecl;
class OMPAllocateDecl;
class TranslationUnitDecl;
class TopLevelStmtDecl;
class StaticAssertDecl;
class RequiresExprBodyDecl;
class PragmaDetectMismatchDecl;
class PragmaCommentDecl;
class ObjCPropertyImplDecl;
class NamedDecl;
class LabelDecl;
class HLSLBufferDecl;
class BaseUsingDecl;
class UsingEnumDecl;
class UsingDecl;
class ValueDecl;
class UnresolvedUsingValueDecl;
class UnnamedGlobalConstantDecl;
class TemplateParamObjectDecl;
class OMPDeclareReductionDecl;
class MSGuidDecl;
class IndirectFieldDecl;
class EnumConstantDecl;
class DeclaratorDecl;
class VarDecl;
class ParmVarDecl;
class OMPCapturedExprDecl;
class ImplicitParamDecl;
class DecompositionDecl;
class VarTemplateSpecializationDecl;
class VarTemplatePartialSpecializationDecl;
class NonTypeTemplateParmDecl;
class MSPropertyDecl;
class FunctionDecl;
class CXXMethodDecl;
class CXXDestructorDecl;
class CXXConversionDecl;
class CXXConstructorDecl;
class CXXDeductionGuideDecl;
class FieldDecl;
class ObjCIvarDecl;
class ObjCAtDefsFieldDecl;
class BindingDecl;
class OMPDeclarativeDirectiveValueDecl;
class OMPDeclareMapperDecl;
class UsingShadowDecl;
class ConstructorUsingShadowDecl;
class UsingPackDecl;
class UsingDirectiveDecl;
class UnresolvedUsingIfExistsDecl;
class TypeDecl;
class TemplateTypeParmDecl;
class TagDecl;
class RecordDecl;
class CXXRecordDecl;
class ClassTemplateSpecializationDecl;
class ClassTemplatePartialSpecializationDecl;
class EnumDecl;
class UnresolvedUsingTypenameDecl;
class TypedefNameDecl;
class TypedefDecl;
class TypeAliasDecl;
class ObjCTypeParamDecl;
class TemplateDecl;
class RedeclarableTemplateDecl;
class FunctionTemplateDecl;
class ClassTemplateDecl;
class VarTemplateDecl;
class TypeAliasTemplateDecl;
class ConceptDecl;
class BuiltinTemplateDecl;
class TemplateTemplateParmDecl;
class ObjCPropertyDecl;
class ObjCMethodDecl;
class ObjCContainerDecl;
class ObjCCategoryDecl;
class ObjCProtocolDecl;
class ObjCInterfaceDecl;
class ObjCImplDecl;
class ObjCCategoryImplDecl;
class ObjCImplementationDecl;
class ObjCCompatibleAliasDecl;
class NamespaceDecl;
class NamespaceAliasDecl;
class LinkageSpecDecl;
class LifetimeExtendedTemporaryDecl;
class ImportDecl;
class ImplicitConceptSpecializationDecl;
class FriendTemplateDecl;
class FriendDecl;
class FileScopeAsmDecl;
class ExternCContextDecl;
class ExportDecl;
class EmptyDecl;
class Compilation;
enum class BuiltinReferenceKind : int32_t;
class ReferenceKind;
class Reference;
class Token;
class TokenRange;
class File;
class TokenTreeVisitor;
class TokenTree;
enum class TokenKind : uint16_t;
enum class MacroKind : uint8_t;
enum class PathKind : uint8_t;
enum class FileType : uint8_t;
enum class CompilerName : uint8_t;
enum class IncludePathLocation : uint8_t;
enum class TargetLanguage : uint8_t;
enum class TokenCategory : uint8_t;
class Macro;
class MacroVAOptArgument;
class MacroVAOpt;
class MacroSubstitution;
class MacroConcatenate;
class MacroStringify;
class MacroExpansion;
class MacroParameterSubstitution;
class MacroArgument;
class MacroParameter;
class MacroDirective;
class DefineMacroDirective;
class PragmaMacroDirective;
class UndefineMacroDirective;
class OtherMacroDirective;
class ConditionalMacroDirective;
class EndIfMacroDirective;
class ElseMacroDirective;
class ElseIfNotDefinedMacroDirective;
class ElseIfDefinedMacroDirective;
class ElseIfMacroDirective;
class IfNotDefinedMacroDirective;
class IfDefinedMacroDirective;
class IfMacroDirective;
class IncludeLikeMacroDirective;
class ImportMacroDirective;
class IncludeMacrosMacroDirective;
class IncludeNextMacroDirective;
class IncludeMacroDirective;
class Fragment;
class RegexQueryMatch;
enum class IndexStatus : uint32_t;
class Index;
namespace ir {
enum class AttributeKind : uint32_t;
class Attribute;
class Value;
class Block;
class Argument;
class Label;
enum class OperationKind : uint32_t;
class Operation;
class Result;
class Operand;
enum BasicBlockOrder : int32_t;
class Region;
enum class TypeKind : uint32_t;
class Type;
}  // namespace ir
namespace ir::builtin {
class ElementsAttr;
class ArrayAttr;
class DenseArrayAttr;
class DictionaryAttr;
class FloatAttr;
class IntegerAttr;
class OpaqueAttr;
class StringAttr;
class StridedLayoutAttr;
class BoolAttr;
class ShapedType;
class IntegerType;
class OpaqueType;
class VectorType;
class ModuleOp;
class UnrealizedConversionCastOp;
}  // namespace ir::builtin
namespace ir::llvm {
class DIBasicTypeAttr;
class DICompileUnitAttr;
class DICompositeTypeAttr;
class DIDerivedTypeAttr;
class DINamespaceAttr;
class MemoryEffectsAttr;
class TBAAMemberAttr;
class TBAATagAttr;
class TBAATypeDescriptorAttr;
class FunctionType;
class PointerType;
class TargetExtType;
class AShrOp;
class AddOp;
class AddrSpaceCastOp;
class AddressOfOp;
class AllocaOp;
class AndOp;
class AtomicCmpXchgOp;
class AtomicRMWOp;
class BitcastOp;
class BrOp;
class CallOp;
class ComdatOp;
class ComdatSelectorOp;
class CondBrOp;
class ConstantOp;
class ExtractElementOp;
class ExtractValueOp;
class FAddOp;
class FCmpOp;
class FDivOp;
class FMulOp;
class FNegOp;
class FPExtOp;
class FPToSIOp;
class FPToUIOp;
class FPTruncOp;
class FRemOp;
class FSubOp;
class FenceOp;
class FreezeOp;
class GetElementPtrOp;
class GlobalOp;
class ICmpOp;
class InlineAsmOp;
class InsertElementOp;
class InsertValueOp;
class IntToPtrOp;
class InvokeOp;
class FuncOp;
class LShrOp;
class LandingpadOp;
class LoadOp;
class MetadataOp;
class MulOp;
class OrOp;
class PoisonOp;
class PtrToIntOp;
class ResumeOp;
class ReturnOp;
class SDivOp;
class SExtOp;
class SIToFPOp;
class SRemOp;
class SelectOp;
class ShlOp;
class ShuffleVectorOp;
class StoreOp;
class SubOp;
class SwitchOp;
class TruncOp;
class UDivOp;
class UIToFPOp;
class URemOp;
class UndefOp;
class XOrOp;
class ZExtOp;
class AbsOp;
class BitReverseOp;
class ByteSwapOp;
class CallIntrinsicOp;
class CopySignOp;
class CoroAlignOp;
class CoroBeginOp;
class CoroEndOp;
class CoroFreeOp;
class CoroIdOp;
class CoroResumeOp;
class CoroSaveOp;
class CoroSizeOp;
class CoroSuspendOp;
class CosOp;
class CountLeadingZerosOp;
class CountTrailingZerosOp;
class CtPopOp;
class DbgValueOp;
class EhTypeidForOp;
class Exp2Op;
class ExpOp;
class ExpectOp;
class ExpectWithProbabilityOp;
class FAbsOp;
class FCeilOp;
class FFloorOp;
class FMAOp;
class FMulAddOp;
class FTruncOp;
class FShlOp;
class FShrOp;
class GetActiveLaneMaskOp;
class IsConstantOp;
class IsFPClassOp;
class LifetimeEndOp;
class LifetimeStartOp;
class RoundAndCastToLongLongOp;
class RoundAndCastToNearestLongLongOp;
class Log10Op;
class Log2Op;
class LogOp;
class RoundAndCastToLongOp;
class RoundAndCastToNearestLongOp;
class MaskedLoadOp;
class MaskedStoreOp;
class MatrixColumnMajorLoadOp;
class MatrixColumnMajorStoreOp;
class MatrixMultiplyOp;
class MatrixTransposeOp;
class MaxNumOp;
class MaximumOp;
class MemcpyInlineOp;
class MemcpyOp;
class MemmoveOp;
class MemsetOp;
class MinNumOp;
class MinimumOp;
class RoundToNearbyIntOp;
class PowIOp;
class FPowOp;
class PrefetchOp;
class RoundToIntOp;
class RoundToNearestEvenOp;
class RoundToNearestOp;
class SAddSatOp;
class SAddWithOverflowOp;
class SMaxOp;
class SMinOp;
class SMulWithOverflowOp;
class SSACopyOp;
class SShlSatOp;
class SSubSatOp;
class SSubWithOverflowOp;
class SinOp;
class SqrtOp;
class StackRestoreOp;
class StackSaveOp;
class StepVectorOp;
class ThreadLocalAddressOp;
class UAddSatOp;
class UAddWithOverflowOp;
class UBSanTrapOp;
class UMaxOp;
class UMinOp;
class UMulWithOverflowOp;
class UShlSatOp;
class USubSatOp;
class USubWithOverflowOp;
class VPAShrOp;
class VPAddOp;
class VPAndOp;
class VPFAddOp;
class VPFDivOp;
class VPFMulAddOp;
class VPFMulOp;
class VPFNegOp;
class VPFPExtOp;
class VPFPToSIOp;
class VPFPToUIOp;
class VPFPTruncOp;
class VPFRemOp;
class VPFSubOp;
class VPFmaOp;
class VPIntToPtrOp;
class VPLShrOp;
class VPLoadOp;
class VPMergeMinOp;
class VPMulOp;
class VPOrOp;
class VPPtrToIntOp;
class VPReduceAddOp;
class VPReduceAndOp;
class VPReduceFAddOp;
class VPReduceFMaxOp;
class VPReduceFMinOp;
class VPReduceFMulOp;
class VPReduceMulOp;
class VPReduceOrOp;
class VPReduceSMaxOp;
class VPReduceSMinOp;
class VPReduceUMaxOp;
class VPReduceUMinOp;
class VPReduceXorOp;
class VPSDivOp;
class VPSExtOp;
class VPSIToFPOp;
class VPSRemOp;
class VPSelectMinOp;
class VPShlOp;
class VPStoreOp;
class VPStridedLoadOp;
class VPStridedStoreOp;
class VPSubOp;
class VPTruncOp;
class VPUDivOp;
class VPUIToFPOp;
class VPURemOp;
class VPXorOp;
class VPZExtOp;
class VaCopyOp;
class VaEndOp;
class VaStartOp;
class MaskedExpandLoadOp;
class MaskedGatherOp;
class MaskedScatterOp;
class VectorExtractOp;
class VectorInsertOp;
class VectorReduceAddOp;
class VectorReduceAndOp;
class VectorReduceFAddOp;
class VectorReduceFMaxOp;
class VectorReduceFMaximumOp;
class VectorReduceFMinOp;
class VectorReduceFMinimumOp;
class VectorReduceFMulOp;
class VectorReduceMulOp;
class VectorReduceOrOp;
class VectorReduceSMaxOp;
class VectorReduceSMinOp;
class VectorReduceUMaxOp;
class VectorReduceUMinOp;
class VectorReduceXorOp;
class VScaleOp;
}  // namespace ir::llvm
namespace ir::memref {
class AssumeAlignmentOp;
class AtomicRMWOp;
class AtomicYieldOp;
class GenericAtomicRMWOp;
class LoadOp;
class AllocOp;
class AllocaOp;
class AllocaScopeOp;
class AllocaScopeReturnOp;
class DimOp;
class DMAStartOp;
class DMAWaitOp;
class ExtractStridedMetadataOp;
class GetGlobalOp;
class GlobalOp;
class PrefetchOp;
class ReinterpretCastOp;
class StoreOp;
class ViewOp;
class SubViewOp;
}  // namespace ir::memref
namespace ir::abi {
class CallArgsOp;
class CallExecutionOp;
class CallOp;
class CallRetsOp;
class DirectOp;
class EpilogueOp;
class FuncOp;
class PrologueOp;
class RetDirectOp;
class TodoOp;
class WrapFuncOp;
class YieldOp;
}  // namespace ir::abi
namespace ir::ll {
class BrOp;
class ConcatOp;
class CondBrOp;
class CondScopeRetOp;
class ExtractOp;
class InitializeVarOp;
class InlineScopeOp;
class FuncOp;
class StructGEPOp;
class ReturnOp;
class ScopeOp;
class UninitializedVarOp;
}  // namespace ir::ll
namespace ir::hl {
class AllocAlignAttr;
class AllocSizeAttr;
class AsmLabelAttr;
class CVQualifiersAttr;
class CVRQualifiersAttr;
class UCVQualifiersAttr;
class EnumType;
class RecordType;
class TypeOfExprType;
class TypedefType;
class AddFAssignOp;
class AddFOp;
class AddIAssignOp;
class AddIOp;
class AddrLabelExprOp;
class AddressOfOp;
class AlignOfExprOp;
class AlignOfTypeOp;
class AssignOp;
class BinAShrAssignOp;
class BinAShrOp;
class BinAndAssignOp;
class BinAndOp;
class BinCommaOp;
class BinLAndOp;
class BinLOrOp;
class BinLShrAssignOp;
class BinLShrOp;
class BinOrAssignOp;
class BinOrOp;
class BinShlAssignOp;
class BinShlOp;
class BinXorAssignOp;
class BinXorOp;
class BuiltinBitCastOp;
class CStyleCastOp;
class CallOp;
class ClassDeclOp;
class CmpOp;
class ConstantOp;
class CxxBaseSpecifierOp;
class CxxStructDeclOp;
class DeclRefOp;
class DerefOp;
class DivFAssignOp;
class DivFOp;
class DivSAssignOp;
class DivSOp;
class DivUAssignOp;
class DivUOp;
class EnumConstantOp;
class EnumDeclOp;
class EnumRefOp;
class ExprOp;
class ExtensionOp;
class FCmpOp;
class FieldDeclOp;
class FuncRefOp;
class GlobalRefOp;
class CaseOp;
class CondOp;
class CondYieldOp;
class DefaultOp;
class DoOp;
class ForOp;
class FuncOp;
class IfOp;
class LabelDeclOp;
class LabelStmtOp;
class SwitchOp;
class TypeYieldOp;
class ValueYieldOp;
class VarDeclOp;
class WhileOp;
class ImplicitCastOp;
class IndirectCallOp;
class InitListExprOp;
class LNotOp;
class MinusOp;
class MulFAssignOp;
class MulFOp;
class MulIAssignOp;
class MulIOp;
class NotOp;
class PlusOp;
class PostDecOp;
class PostIncOp;
class PreDecOp;
class PreIncOp;
class PredefinedExprOp;
class RecordMemberOp;
class RemFAssignOp;
class RemFOp;
class RemSAssignOp;
class RemSOp;
class RemUAssignOp;
class RemUOp;
class ReturnOp;
class SizeOfExprOp;
class SizeOfTypeOp;
class StmtExprOp;
class StructDeclOp;
class SubFAssignOp;
class SubFOp;
class SubIAssignOp;
class SubIOp;
class SubscriptOp;
class ThisOp;
class TranslationUnitOp;
class TypeDeclOp;
class TypeDefOp;
class TypeOfExprOp;
class UnionDeclOp;
}  // namespace ir::hl
namespace ir::core {
class BooleanAttr;
class StringLiteralAttr;
class FunctionType;
class BinLAndOp;
class BinLOrOp;
class ImplicitReturnOp;
class LazyOp;
class ScopeOp;
class SelectOp;
}  // namespace ir::core
namespace ir::unsup {
class UnsupportedType;
class UnsupportedDeclOp;
class UnsupportedStmtOp;
}  // namespace ir::unsup

namespace {

using LoaderFunc = bool (BorrowedPyObject *);

static PyMethodDef gEmptyMethods[] = {
  {}   // Sentinel.
};


// multiplier
static PyModuleDef gModule = {
  PyModuleDef_HEAD_INIT,
  .m_name = "",
  .m_doc = PyDoc_STR("Multiplier source code auditing API"),
  .m_size = 0,
  .m_methods = gEmptyMethods,
  .m_slots = {},
  .m_traverse = {},
  .m_clear = {},
  .m_free = {},
};

static LoaderFunc * const gLoaders[] = {
  PythonBinding<mx::EntityCategory>::load,
  PythonBinding<mx::BuiltinReferenceKind>::load,
  PythonBinding<mx::ReferenceKind>::load,
  PythonBinding<mx::Reference>::load,
  PythonBinding<mx::Fragment>::load,
  PythonBinding<mx::RegexQueryMatch>::load,
  PythonBinding<mx::IndexStatus>::load,
  PythonBinding<mx::Index>::load,
};

// multiplier.ir
static PyModuleDef gIRModule = {
  PyModuleDef_HEAD_INIT,
  .m_name = "ir",
  .m_doc = PyDoc_STR("Wrapper of IR"),
  .m_size = 0,
  .m_methods = gEmptyMethods,
  .m_slots = {},
  .m_traverse = {},
  .m_clear = {},
  .m_free = {},
};

static LoaderFunc * const gIRLoaders[] = {
  PythonBinding<mx::ir::AttributeKind>::load,
  PythonBinding<mx::ir::Attribute>::load,
  PythonBinding<mx::ir::Value>::load,
  PythonBinding<mx::ir::Block>::load,
  PythonBinding<mx::ir::Argument>::load,
  PythonBinding<mx::ir::Label>::load,
  PythonBinding<mx::ir::OperationKind>::load,
  PythonBinding<mx::ir::Operation>::load,
  PythonBinding<mx::ir::Result>::load,
  PythonBinding<mx::ir::Operand>::load,
  PythonBinding<mx::ir::BasicBlockOrder>::load,
  PythonBinding<mx::ir::Region>::load,
  PythonBinding<mx::ir::TypeKind>::load,
  PythonBinding<mx::ir::Type>::load,
};

// multiplier.ast
static PyModuleDef gASTModule = {
  PyModuleDef_HEAD_INIT,
  .m_name = "ast",
  .m_doc = PyDoc_STR("Wrapper of AST"),
  .m_size = 0,
  .m_methods = gEmptyMethods,
  .m_slots = {},
  .m_traverse = {},
  .m_clear = {},
  .m_free = {},
};

static LoaderFunc * const gASTLoaders[] = {
  PythonBinding<mx::DeclKind>::load,
  PythonBinding<mx::AttrKind>::load,
  PythonBinding<mx::AArch64SVEPcsAttrSpelling>::load,
  PythonBinding<mx::AArch64VectorPcsAttrSpelling>::load,
  PythonBinding<mx::AMDGPUFlatWorkGroupSizeAttrSpelling>::load,
  PythonBinding<mx::AMDGPUKernelCallAttrSpelling>::load,
  PythonBinding<mx::AMDGPUNumSGPRAttrSpelling>::load,
  PythonBinding<mx::AMDGPUNumVGPRAttrSpelling>::load,
  PythonBinding<mx::AMDGPUWavesPerEUAttrSpelling>::load,
  PythonBinding<mx::ARMInterruptAttrInterruptType>::load,
  PythonBinding<mx::ARMInterruptAttrSpelling>::load,
  PythonBinding<mx::AVRInterruptAttrSpelling>::load,
  PythonBinding<mx::AVRSignalAttrSpelling>::load,
  PythonBinding<mx::AbiTagAttrSpelling>::load,
  PythonBinding<mx::AcquireCapabilityAttrSpelling>::load,
  PythonBinding<mx::AcquireHandleAttrSpelling>::load,
  PythonBinding<mx::AddressSpaceAttrSpelling>::load,
  PythonBinding<mx::AliasAttrSpelling>::load,
  PythonBinding<mx::AlignedAttrSpelling>::load,
  PythonBinding<mx::AllocAlignAttrSpelling>::load,
  PythonBinding<mx::AllocSizeAttrSpelling>::load,
  PythonBinding<mx::AlwaysDestroyAttrSpelling>::load,
  PythonBinding<mx::AlwaysInlineAttrSpelling>::load,
  PythonBinding<mx::AnnotateAttrSpelling>::load,
  PythonBinding<mx::AnnotateTypeAttrSpelling>::load,
  PythonBinding<mx::AnyX86InterruptAttrSpelling>::load,
  PythonBinding<mx::AnyX86NoCallerSavedRegistersAttrSpelling>::load,
  PythonBinding<mx::AnyX86NoCfCheckAttrSpelling>::load,
  PythonBinding<mx::ArcWeakrefUnavailableAttrSpelling>::load,
  PythonBinding<mx::ArgumentWithTypeTagAttrSpelling>::load,
  PythonBinding<mx::ArmBuiltinAliasAttrSpelling>::load,
  PythonBinding<mx::ArmMveStrictPolymorphismAttrSpelling>::load,
  PythonBinding<mx::ArrayTypeArraySizeModifier>::load,
  PythonBinding<mx::ArtificialAttrSpelling>::load,
  PythonBinding<mx::AsmLabelAttrSpelling>::load,
  PythonBinding<mx::AssertCapabilityAttrSpelling>::load,
  PythonBinding<mx::AssumeAlignedAttrSpelling>::load,
  PythonBinding<mx::AssumptionAttrSpelling>::load,
  PythonBinding<mx::AtomicExprAtomicOp>::load,
  PythonBinding<mx::AvailabilityAttrSpelling>::load,
  PythonBinding<mx::AvailableOnlyInDefaultEvalMethodAttrSpelling>::load,
  PythonBinding<mx::BPFPreserveAccessIndexAttrSpelling>::load,
  PythonBinding<mx::BTFDeclTagAttrSpelling>::load,
  PythonBinding<mx::BTFTypeTagAttrSpelling>::load,
  PythonBinding<mx::BlocksAttrBlockType>::load,
  PythonBinding<mx::BlocksAttrSpelling>::load,
  PythonBinding<mx::BuiltinAliasAttrSpelling>::load,
  PythonBinding<mx::BuiltinTypeKind>::load,
  PythonBinding<mx::CDeclAttrSpelling>::load,
  PythonBinding<mx::CFAuditedTransferAttrSpelling>::load,
  PythonBinding<mx::CFConsumedAttrSpelling>::load,
  PythonBinding<mx::CFGuardAttrGuardArg>::load,
  PythonBinding<mx::CFGuardAttrSpelling>::load,
  PythonBinding<mx::CFICanonicalJumpTableAttrSpelling>::load,
  PythonBinding<mx::CFReturnsNotRetainedAttrSpelling>::load,
  PythonBinding<mx::CFReturnsRetainedAttrSpelling>::load,
  PythonBinding<mx::CFUnknownTransferAttrSpelling>::load,
  PythonBinding<mx::CPUDispatchAttrSpelling>::load,
  PythonBinding<mx::CPUSpecificAttrSpelling>::load,
  PythonBinding<mx::CUDAConstantAttrSpelling>::load,
  PythonBinding<mx::CUDADeviceAttrSpelling>::load,
  PythonBinding<mx::CUDADeviceBuiltinSurfaceTypeAttrSpelling>::load,
  PythonBinding<mx::CUDADeviceBuiltinTextureTypeAttrSpelling>::load,
  PythonBinding<mx::CUDAGlobalAttrSpelling>::load,
  PythonBinding<mx::CUDAHostAttrSpelling>::load,
  PythonBinding<mx::CUDALaunchBoundsAttrSpelling>::load,
  PythonBinding<mx::CUDASharedAttrSpelling>::load,
  PythonBinding<mx::CXX11NoReturnAttrSpelling>::load,
  PythonBinding<mx::CXXConstructExprConstructionKind>::load,
  PythonBinding<mx::CXXNewExprInitializationStyle>::load,
  PythonBinding<mx::CXXRecordDeclLambdaDependencyKind>::load,
  PythonBinding<mx::CallExprADLCallKind>::load,
  PythonBinding<mx::CallableWhenAttrConsumedState>::load,
  PythonBinding<mx::CallableWhenAttrSpelling>::load,
  PythonBinding<mx::CallbackAttrSpelling>::load,
  PythonBinding<mx::CalledOnceAttrSpelling>::load,
  PythonBinding<mx::CapabilityAttrSpelling>::load,
  PythonBinding<mx::CapturedStmtVariableCaptureKind>::load,
  PythonBinding<mx::CarriesDependencyAttrSpelling>::load,
  PythonBinding<mx::CharacterLiteralCharacterKind>::load,
  PythonBinding<mx::CleanupAttrSpelling>::load,
  PythonBinding<mx::ColdAttrSpelling>::load,
  PythonBinding<mx::CommonAttrSpelling>::load,
  PythonBinding<mx::ConstAttrSpelling>::load,
  PythonBinding<mx::ConstInitAttrSpelling>::load,
  PythonBinding<mx::ConstantExprResultStorageKind>::load,
  PythonBinding<mx::ConstructorAttrSpelling>::load,
  PythonBinding<mx::ConsumableAttrConsumedState>::load,
  PythonBinding<mx::ConsumableAttrSpelling>::load,
  PythonBinding<mx::ConsumableAutoCastAttrSpelling>::load,
  PythonBinding<mx::ConsumableSetOnReadAttrSpelling>::load,
  PythonBinding<mx::ConvergentAttrSpelling>::load,
  PythonBinding<mx::DLLExportAttrSpelling>::load,
  PythonBinding<mx::DLLImportAttrSpelling>::load,
  PythonBinding<mx::DeclFriendObjectKind>::load,
  PythonBinding<mx::DeclIdentifierNamespace>::load,
  PythonBinding<mx::DeclModuleOwnershipKind>::load,
  PythonBinding<mx::DeclObjCDeclQualifier>::load,
  PythonBinding<mx::DeprecatedAttrSpelling>::load,
  PythonBinding<mx::DestructorAttrSpelling>::load,
  PythonBinding<mx::DiagnoseAsBuiltinAttrSpelling>::load,
  PythonBinding<mx::DiagnoseIfAttrDiagnosticType>::load,
  PythonBinding<mx::DisableSanitizerInstrumentationAttrSpelling>::load,
  PythonBinding<mx::DisableTailCallsAttrSpelling>::load,
  PythonBinding<mx::EnforceTCBAttrSpelling>::load,
  PythonBinding<mx::EnforceTCBLeafAttrSpelling>::load,
  PythonBinding<mx::EnumExtensibilityAttrKind>::load,
  PythonBinding<mx::EnumExtensibilityAttrSpelling>::load,
  PythonBinding<mx::ErrorAttrSpelling>::load,
  PythonBinding<mx::ExcludeFromExplicitInstantiationAttrSpelling>::load,
  PythonBinding<mx::ExprConstantExprKind>::load,
  PythonBinding<mx::ExprLValueClassification>::load,
  PythonBinding<mx::ExprNullPointerConstantKind>::load,
  PythonBinding<mx::ExprNullPointerConstantValueDependence>::load,
  PythonBinding<mx::ExprSideEffectsKind>::load,
  PythonBinding<mx::ExprisModifiableLvalueResult>::load,
  PythonBinding<mx::ExternalSourceSymbolAttrSpelling>::load,
  PythonBinding<mx::FallThroughAttrSpelling>::load,
  PythonBinding<mx::FastCallAttrSpelling>::load,
  PythonBinding<mx::FinalAttrSpelling>::load,
  PythonBinding<mx::FlagEnumAttrSpelling>::load,
  PythonBinding<mx::FlattenAttrSpelling>::load,
  PythonBinding<mx::FormatArgAttrSpelling>::load,
  PythonBinding<mx::FormatAttrSpelling>::load,
  PythonBinding<mx::FunctionDeclTemplatedKind>::load,
  PythonBinding<mx::FunctionReturnThunksAttrKind>::load,
  PythonBinding<mx::FunctionReturnThunksAttrSpelling>::load,
  PythonBinding<mx::GNUInlineAttrSpelling>::load,
  PythonBinding<mx::GuardedVarAttrSpelling>::load,
  PythonBinding<mx::HIPManagedAttrSpelling>::load,
  PythonBinding<mx::HLSLResourceAttrResourceClass>::load,
  PythonBinding<mx::HLSLResourceAttrResourceKind>::load,
  PythonBinding<mx::HLSLShaderAttrShaderType>::load,
  PythonBinding<mx::HotAttrSpelling>::load,
  PythonBinding<mx::IBActionAttrSpelling>::load,
  PythonBinding<mx::IBOutletAttrSpelling>::load,
  PythonBinding<mx::IBOutletCollectionAttrSpelling>::load,
  PythonBinding<mx::IFuncAttrSpelling>::load,
  PythonBinding<mx::ImplicitCastExprOnStack>::load,
  PythonBinding<mx::ImplicitParamDeclImplicitParamKind>::load,
  PythonBinding<mx::InitPriorityAttrSpelling>::load,
  PythonBinding<mx::IntelOclBiccAttrSpelling>::load,
  PythonBinding<mx::InternalLinkageAttrSpelling>::load,
  PythonBinding<mx::LTOVisibilityPublicAttrSpelling>::load,
  PythonBinding<mx::LeafAttrSpelling>::load,
  PythonBinding<mx::LifetimeBoundAttrSpelling>::load,
  PythonBinding<mx::LikelyAttrSpelling>::load,
  PythonBinding<mx::LinkageSpecDeclLanguageIDs>::load,
  PythonBinding<mx::LoaderUninitializedAttrSpelling>::load,
  PythonBinding<mx::LoopHintAttrLoopHintState>::load,
  PythonBinding<mx::LoopHintAttrOptionType>::load,
  PythonBinding<mx::LoopHintAttrSpelling>::load,
  PythonBinding<mx::MIGServerRoutineAttrSpelling>::load,
  PythonBinding<mx::MSABIAttrSpelling>::load,
  PythonBinding<mx::MSInheritanceAttrSpelling>::load,
  PythonBinding<mx::MSP430InterruptAttrSpelling>::load,
  PythonBinding<mx::MSStructAttrSpelling>::load,
  PythonBinding<mx::MayAliasAttrSpelling>::load,
  PythonBinding<mx::MaybeUndefAttrSpelling>::load,
  PythonBinding<mx::MicroMipsAttrSpelling>::load,
  PythonBinding<mx::MinSizeAttrSpelling>::load,
  PythonBinding<mx::MinVectorWidthAttrSpelling>::load,
  PythonBinding<mx::Mips16AttrSpelling>::load,
  PythonBinding<mx::MipsInterruptAttrInterruptType>::load,
  PythonBinding<mx::MipsInterruptAttrSpelling>::load,
  PythonBinding<mx::MipsLongCallAttrSpelling>::load,
  PythonBinding<mx::MipsShortCallAttrSpelling>::load,
  PythonBinding<mx::ModeAttrSpelling>::load,
  PythonBinding<mx::MustTailAttrSpelling>::load,
  PythonBinding<mx::NSConsumedAttrSpelling>::load,
  PythonBinding<mx::NSConsumesSelfAttrSpelling>::load,
  PythonBinding<mx::NSReturnsAutoreleasedAttrSpelling>::load,
  PythonBinding<mx::NSReturnsNotRetainedAttrSpelling>::load,
  PythonBinding<mx::NSReturnsRetainedAttrSpelling>::load,
  PythonBinding<mx::NVPTXKernelAttrSpelling>::load,
  PythonBinding<mx::NakedAttrSpelling>::load,
  PythonBinding<mx::NamedDeclExplicitVisibilityKind>::load,
  PythonBinding<mx::NoBuiltinAttrSpelling>::load,
  PythonBinding<mx::NoCommonAttrSpelling>::load,
  PythonBinding<mx::NoDebugAttrSpelling>::load,
  PythonBinding<mx::NoDerefAttrSpelling>::load,
  PythonBinding<mx::NoDestroyAttrSpelling>::load,
  PythonBinding<mx::NoDuplicateAttrSpelling>::load,
  PythonBinding<mx::NoEscapeAttrSpelling>::load,
  PythonBinding<mx::NoInlineAttrSpelling>::load,
  PythonBinding<mx::NoInstrumentFunctionAttrSpelling>::load,
  PythonBinding<mx::NoMergeAttrSpelling>::load,
  PythonBinding<mx::NoMicroMipsAttrSpelling>::load,
  PythonBinding<mx::NoMips16AttrSpelling>::load,
  PythonBinding<mx::NoProfileFunctionAttrSpelling>::load,
  PythonBinding<mx::NoRandomizeLayoutAttrSpelling>::load,
  PythonBinding<mx::NoReturnAttrSpelling>::load,
  PythonBinding<mx::NoSanitizeAttrSpelling>::load,
  PythonBinding<mx::NoSpeculativeLoadHardeningAttrSpelling>::load,
  PythonBinding<mx::NoSplitStackAttrSpelling>::load,
  PythonBinding<mx::NoStackProtectorAttrSpelling>::load,
  PythonBinding<mx::NoThreadSafetyAnalysisAttrSpelling>::load,
  PythonBinding<mx::NoThrowAttrSpelling>::load,
  PythonBinding<mx::NoUwtableAttrSpelling>::load,
  PythonBinding<mx::NonNullAttrSpelling>::load,
  PythonBinding<mx::NotTailCalledAttrSpelling>::load,
  PythonBinding<mx::OMPAllocateDeclAttrAllocatorTypeTy>::load,
  PythonBinding<mx::OMPDeclareReductionDeclInitKind>::load,
  PythonBinding<mx::OMPDeclareSimdDeclAttrBranchStateTy>::load,
  PythonBinding<mx::OMPDeclareTargetDeclAttrDevTypeTy>::load,
  PythonBinding<mx::OMPDeclareTargetDeclAttrMapTypeTy>::load,
  PythonBinding<mx::OSConsumedAttrSpelling>::load,
  PythonBinding<mx::OSConsumesThisAttrSpelling>::load,
  PythonBinding<mx::OSReturnsNotRetainedAttrSpelling>::load,
  PythonBinding<mx::OSReturnsRetainedAttrSpelling>::load,
  PythonBinding<mx::OSReturnsRetainedOnNonZeroAttrSpelling>::load,
  PythonBinding<mx::OSReturnsRetainedOnZeroAttrSpelling>::load,
  PythonBinding<mx::ObjCBoxableAttrSpelling>::load,
  PythonBinding<mx::ObjCBridgeAttrSpelling>::load,
  PythonBinding<mx::ObjCBridgeMutableAttrSpelling>::load,
  PythonBinding<mx::ObjCBridgeRelatedAttrSpelling>::load,
  PythonBinding<mx::ObjCClassStubAttrSpelling>::load,
  PythonBinding<mx::ObjCDesignatedInitializerAttrSpelling>::load,
  PythonBinding<mx::ObjCDirectAttrSpelling>::load,
  PythonBinding<mx::ObjCDirectMembersAttrSpelling>::load,
  PythonBinding<mx::ObjCExceptionAttrSpelling>::load,
  PythonBinding<mx::ObjCExplicitProtocolImplAttrSpelling>::load,
  PythonBinding<mx::ObjCExternallyRetainedAttrSpelling>::load,
  PythonBinding<mx::ObjCGCAttrSpelling>::load,
  PythonBinding<mx::ObjCIndependentClassAttrSpelling>::load,
  PythonBinding<mx::ObjCIvarDeclAccessControl>::load,
  PythonBinding<mx::ObjCMessageExprReceiverKind>::load,
  PythonBinding<mx::ObjCMethodDeclImplementationControl>::load,
  PythonBinding<mx::ObjCMethodFamilyAttrFamilyKind>::load,
  PythonBinding<mx::ObjCMethodFamilyAttrSpelling>::load,
  PythonBinding<mx::ObjCNSObjectAttrSpelling>::load,
  PythonBinding<mx::ObjCNonLazyClassAttrSpelling>::load,
  PythonBinding<mx::ObjCNonRuntimeProtocolAttrSpelling>::load,
  PythonBinding<mx::ObjCOwnershipAttrSpelling>::load,
  PythonBinding<mx::ObjCPreciseLifetimeAttrSpelling>::load,
  PythonBinding<mx::ObjCPropertyDeclPropertyControl>::load,
  PythonBinding<mx::ObjCPropertyDeclSetterKind>::load,
  PythonBinding<mx::ObjCPropertyImplDeclKind>::load,
  PythonBinding<mx::ObjCRequiresPropertyDefsAttrSpelling>::load,
  PythonBinding<mx::ObjCRequiresSuperAttrSpelling>::load,
  PythonBinding<mx::ObjCReturnsInnerPointerAttrSpelling>::load,
  PythonBinding<mx::ObjCRootClassAttrSpelling>::load,
  PythonBinding<mx::ObjCRuntimeNameAttrSpelling>::load,
  PythonBinding<mx::ObjCRuntimeVisibleAttrSpelling>::load,
  PythonBinding<mx::ObjCSubclassingRestrictedAttrSpelling>::load,
  PythonBinding<mx::OpenCLAccessAttrSpelling>::load,
  PythonBinding<mx::OpenCLConstantAddressSpaceAttrSpelling>::load,
  PythonBinding<mx::OpenCLGenericAddressSpaceAttrSpelling>::load,
  PythonBinding<mx::OpenCLGlobalAddressSpaceAttrSpelling>::load,
  PythonBinding<mx::OpenCLGlobalDeviceAddressSpaceAttrSpelling>::load,
  PythonBinding<mx::OpenCLGlobalHostAddressSpaceAttrSpelling>::load,
  PythonBinding<mx::OpenCLKernelAttrSpelling>::load,
  PythonBinding<mx::OpenCLLocalAddressSpaceAttrSpelling>::load,
  PythonBinding<mx::OpenCLPrivateAddressSpaceAttrSpelling>::load,
  PythonBinding<mx::OptimizeNoneAttrSpelling>::load,
  PythonBinding<mx::OverloadableAttrSpelling>::load,
  PythonBinding<mx::OwnershipAttrOwnershipKind>::load,
  PythonBinding<mx::OwnershipAttrSpelling>::load,
  PythonBinding<mx::PackedAttrSpelling>::load,
  PythonBinding<mx::ParamTypestateAttrConsumedState>::load,
  PythonBinding<mx::ParamTypestateAttrSpelling>::load,
  PythonBinding<mx::PascalAttrSpelling>::load,
  PythonBinding<mx::PassObjectSizeAttrSpelling>::load,
  PythonBinding<mx::PatchableFunctionEntryAttrSpelling>::load,
  PythonBinding<mx::PcsAttrPCSType>::load,
  PythonBinding<mx::PcsAttrSpelling>::load,
  PythonBinding<mx::PredefinedExprIdentKind>::load,
  PythonBinding<mx::PreferredNameAttrSpelling>::load,
  PythonBinding<mx::PreserveAllAttrSpelling>::load,
  PythonBinding<mx::PreserveMostAttrSpelling>::load,
  PythonBinding<mx::PtGuardedVarAttrSpelling>::load,
  PythonBinding<mx::PureAttrSpelling>::load,
  PythonBinding<mx::QualifiedTypeDestructionKind>::load,
  PythonBinding<mx::QualifiedTypePrimitiveCopyKind>::load,
  PythonBinding<mx::QualifiedTypePrimitiveDefaultInitializeKind>::load,
  PythonBinding<mx::RISCVInterruptAttrInterruptType>::load,
  PythonBinding<mx::RISCVInterruptAttrSpelling>::load,
  PythonBinding<mx::RandomizeLayoutAttrSpelling>::load,
  PythonBinding<mx::ReadOnlyPlacementAttrSpelling>::load,
  PythonBinding<mx::RecordDeclArgPassingKind>::load,
  PythonBinding<mx::RegCallAttrSpelling>::load,
  PythonBinding<mx::ReinitializesAttrSpelling>::load,
  PythonBinding<mx::ReleaseCapabilityAttrSpelling>::load,
  PythonBinding<mx::ReleaseHandleAttrSpelling>::load,
  PythonBinding<mx::RequiresCapabilityAttrSpelling>::load,
  PythonBinding<mx::RestrictAttrSpelling>::load,
  PythonBinding<mx::RetainAttrSpelling>::load,
  PythonBinding<mx::ReturnTypestateAttrConsumedState>::load,
  PythonBinding<mx::ReturnTypestateAttrSpelling>::load,
  PythonBinding<mx::ReturnsNonNullAttrSpelling>::load,
  PythonBinding<mx::ReturnsTwiceAttrSpelling>::load,
  PythonBinding<mx::SYCLKernelAttrSpelling>::load,
  PythonBinding<mx::SYCLSpecialClassAttrSpelling>::load,
  PythonBinding<mx::ScopedLockableAttrSpelling>::load,
  PythonBinding<mx::SectionAttrSpelling>::load,
  PythonBinding<mx::SelectAnyAttrSpelling>::load,
  PythonBinding<mx::SentinelAttrSpelling>::load,
  PythonBinding<mx::SetTypestateAttrConsumedState>::load,
  PythonBinding<mx::SetTypestateAttrSpelling>::load,
  PythonBinding<mx::SourceLocExprIdentKind>::load,
  PythonBinding<mx::SpeculativeLoadHardeningAttrSpelling>::load,
  PythonBinding<mx::StandaloneDebugAttrSpelling>::load,
  PythonBinding<mx::StdCallAttrSpelling>::load,
  PythonBinding<mx::StmtLikelihood>::load,
  PythonBinding<mx::StmtKind>::load,
  PythonBinding<mx::StringLiteralStringKind>::load,
  PythonBinding<mx::SwiftAsyncAttrKind>::load,
  PythonBinding<mx::SwiftAsyncAttrSpelling>::load,
  PythonBinding<mx::SwiftAsyncCallAttrSpelling>::load,
  PythonBinding<mx::SwiftAsyncContextAttrSpelling>::load,
  PythonBinding<mx::SwiftAsyncErrorAttrConventionKind>::load,
  PythonBinding<mx::SwiftAsyncErrorAttrSpelling>::load,
  PythonBinding<mx::SwiftCallAttrSpelling>::load,
  PythonBinding<mx::SwiftContextAttrSpelling>::load,
  PythonBinding<mx::SwiftErrorAttrConventionKind>::load,
  PythonBinding<mx::SwiftErrorResultAttrSpelling>::load,
  PythonBinding<mx::SwiftIndirectResultAttrSpelling>::load,
  PythonBinding<mx::SwiftNewTypeAttrNewtypeKind>::load,
  PythonBinding<mx::SwiftNewTypeAttrSpelling>::load,
  PythonBinding<mx::SysVABIAttrSpelling>::load,
  PythonBinding<mx::TLSModelAttrSpelling>::load,
  PythonBinding<mx::TargetAttrSpelling>::load,
  PythonBinding<mx::TargetClonesAttrSpelling>::load,
  PythonBinding<mx::TargetVersionAttrSpelling>::load,
  PythonBinding<mx::TemplateArgumentKind>::load,
  PythonBinding<mx::TestTypestateAttrConsumedState>::load,
  PythonBinding<mx::TestTypestateAttrSpelling>::load,
  PythonBinding<mx::ThisCallAttrSpelling>::load,
  PythonBinding<mx::TransparentUnionAttrSpelling>::load,
  PythonBinding<mx::TrivialABIAttrSpelling>::load,
  PythonBinding<mx::TryAcquireCapabilityAttrSpelling>::load,
  PythonBinding<mx::TypeScalarTypeKind>::load,
  PythonBinding<mx::TypeKind>::load,
  PythonBinding<mx::TypeTagForDatatypeAttrSpelling>::load,
  PythonBinding<mx::TypeVisibilityAttrSpelling>::load,
  PythonBinding<mx::TypeVisibilityAttrVisibilityType>::load,
  PythonBinding<mx::UnaryTransformTypeUTTKind>::load,
  PythonBinding<mx::UnavailableAttrImplicitReason>::load,
  PythonBinding<mx::UnavailableAttrSpelling>::load,
  PythonBinding<mx::UninitializedAttrSpelling>::load,
  PythonBinding<mx::UnlikelyAttrSpelling>::load,
  PythonBinding<mx::UnsafeBufferUsageAttrSpelling>::load,
  PythonBinding<mx::UnusedAttrSpelling>::load,
  PythonBinding<mx::UseHandleAttrSpelling>::load,
  PythonBinding<mx::UsedAttrSpelling>::load,
  PythonBinding<mx::UserDefinedLiteralLiteralOperatorKind>::load,
  PythonBinding<mx::UsingIfExistsAttrSpelling>::load,
  PythonBinding<mx::UuidAttrSpelling>::load,
  PythonBinding<mx::VarDeclDefinitionKind>::load,
  PythonBinding<mx::VarDeclInitializationStyle>::load,
  PythonBinding<mx::VarDeclTLSKind>::load,
  PythonBinding<mx::VecReturnAttrSpelling>::load,
  PythonBinding<mx::VectorCallAttrSpelling>::load,
  PythonBinding<mx::VectorTypeVectorKind>::load,
  PythonBinding<mx::VisibilityAttrSpelling>::load,
  PythonBinding<mx::VisibilityAttrVisibilityType>::load,
  PythonBinding<mx::WarnUnusedAttrSpelling>::load,
  PythonBinding<mx::WarnUnusedResultAttrSpelling>::load,
  PythonBinding<mx::WeakAttrSpelling>::load,
  PythonBinding<mx::WeakImportAttrSpelling>::load,
  PythonBinding<mx::WeakRefAttrSpelling>::load,
  PythonBinding<mx::WebAssemblyExportNameAttrSpelling>::load,
  PythonBinding<mx::WebAssemblyImportModuleAttrSpelling>::load,
  PythonBinding<mx::WebAssemblyImportNameAttrSpelling>::load,
  PythonBinding<mx::X86ForceAlignArgPointerAttrSpelling>::load,
  PythonBinding<mx::XRayInstrumentAttrSpelling>::load,
  PythonBinding<mx::XRayLogArgsAttrSpelling>::load,
  PythonBinding<mx::ZeroCallUsedRegsAttrSpelling>::load,
  PythonBinding<mx::ZeroCallUsedRegsAttrZeroCallUsedRegsKind>::load,
  PythonBinding<mx::ASTDumpOutputFormat>::load,
  PythonBinding<mx::AccessSpecifier>::load,
  PythonBinding<mx::AddrSpaceMapMangling>::load,
  PythonBinding<mx::AlignRequirementKind>::load,
  PythonBinding<mx::AltivecSrcCompatKind>::load,
  PythonBinding<mx::ArgumentKind>::load,
  PythonBinding<mx::ArrayTypeTrait>::load,
  PythonBinding<mx::AssignmentTrackingOpts>::load,
  PythonBinding<mx::AtomicScopeModelKind>::load,
  PythonBinding<mx::AutoTypeKeyword>::load,
  PythonBinding<mx::AvailabilityResult>::load,
  PythonBinding<mx::BinaryOperatorKind>::load,
  PythonBinding<mx::Bits>::load,
  PythonBinding<mx::CallingConv>::load,
  PythonBinding<mx::CanThrowResult>::load,
  PythonBinding<mx::CapturedRegionKind>::load,
  PythonBinding<mx::CastKind>::load,
  PythonBinding<mx::ClangABI>::load,
  PythonBinding<mx::CommentKind>::load,
  PythonBinding<mx::ComparisonCategoryResult>::load,
  PythonBinding<mx::ComparisonCategoryType>::load,
  PythonBinding<mx::CompilingModuleKind>::load,
  PythonBinding<mx::ConstexprSpecKind>::load,
  PythonBinding<mx::CoreFoundationABI>::load,
  PythonBinding<mx::DataPositionTy>::load,
  PythonBinding<mx::DebugSrcHashKind>::load,
  PythonBinding<mx::DeductionCandidate>::load,
  PythonBinding<mx::DefaultArgKind>::load,
  PythonBinding<mx::DefaultCallingConvention>::load,
  PythonBinding<mx::DefaultVisiblityExportMapping>::load,
  PythonBinding<mx::DesignatorKind>::load,
  PythonBinding<mx::DiagnosticLevelMask>::load,
  PythonBinding<mx::ElaboratedTypeKeyword>::load,
  PythonBinding<mx::EmbedBitcodeKind>::load,
  PythonBinding<mx::EscapeChar>::load,
  PythonBinding<mx::ExceptionHandlingKind>::load,
  PythonBinding<mx::ExceptionSpecificationType>::load,
  PythonBinding<mx::ExcessPrecisionKind>::load,
  PythonBinding<mx::ExclusionType>::load,
  PythonBinding<mx::ExplicitSpecKind>::load,
  PythonBinding<mx::ExprDependence>::load,
  PythonBinding<mx::ExprObjectKind>::load,
  PythonBinding<mx::ExprOffsets>::load,
  PythonBinding<mx::ExprValueKind>::load,
  PythonBinding<mx::ExpressionTrait>::load,
  PythonBinding<mx::ExtKind>::load,
  PythonBinding<mx::ExtendArgsKind>::load,
  PythonBinding<mx::FPEvalMethodKind>::load,
  PythonBinding<mx::FPExceptionModeKind>::load,
  PythonBinding<mx::FPModeKind>::load,
  PythonBinding<mx::FiniteLoopsKind>::load,
  PythonBinding<mx::Flags>::load,
  PythonBinding<mx::FramePointerKind>::load,
  PythonBinding<mx::GC>::load,
  PythonBinding<mx::GCMode>::load,
  PythonBinding<mx::GPUDefaultStreamKind>::load,
  PythonBinding<mx::GVALinkage>::load,
  PythonBinding<mx::GetBuiltinTypeError>::load,
  PythonBinding<mx::HLSLLangStd>::load,
  PythonBinding<mx::ID>::load,
  PythonBinding<mx::IdentifierInfoFlag>::load,
  PythonBinding<mx::IfStatementKind>::load,
  PythonBinding<mx::ImbueAttribute>::load,
  PythonBinding<mx::InClassInitStyle>::load,
  PythonBinding<mx::InheritedDesignatedInitializersState>::load,
  PythonBinding<mx::InitStorageKind>::load,
  PythonBinding<mx::InlineAsmDialectKind>::load,
  PythonBinding<mx::InlineVariableDefinitionKind>::load,
  PythonBinding<mx::InliningMethod>::load,
  PythonBinding<mx::InterestingIdentifierKind>::load,
  PythonBinding<mx::Kinds>::load,
  PythonBinding<mx::LambdaCaptureDefault>::load,
  PythonBinding<mx::LambdaCaptureKind>::load,
  PythonBinding<mx::LangAS>::load,
  PythonBinding<mx::LangFeatures>::load,
  PythonBinding<mx::Language>::load,
  PythonBinding<mx::LanguageLinkage>::load,
  PythonBinding<mx::LaxVectorConversionKind>::load,
  PythonBinding<mx::Level>::load,
  PythonBinding<mx::Linkage>::load,
  PythonBinding<mx::MSInheritanceModel>::load,
  PythonBinding<mx::MSVCMajorVersion>::load,
  PythonBinding<mx::MSVtorDispMode>::load,
  PythonBinding<mx::MethodRefFlags>::load,
  PythonBinding<mx::ModifiableType>::load,
  PythonBinding<mx::MultiVersionKind>::load,
  PythonBinding<mx::NameKind>::load,
  PythonBinding<mx::NeedExtraManglingDecl>::load,
  PythonBinding<mx::NestedNameSpecifierDependence>::load,
  PythonBinding<mx::NonOdrUseReason>::load,
  PythonBinding<mx::NonceObjCInterface>::load,
  PythonBinding<mx::NullabilityKind>::load,
  PythonBinding<mx::ObjCBridgeCastKind>::load,
  PythonBinding<mx::ObjCDispatchMethodKind>::load,
  PythonBinding<mx::ObjCInstanceTypeFamily>::load,
  PythonBinding<mx::ObjCLifetime>::load,
  PythonBinding<mx::ObjCMethodFamily>::load,
  PythonBinding<mx::ObjCPropertyQueryKind>::load,
  PythonBinding<mx::ObjCStringFormatFamily>::load,
  PythonBinding<mx::ObjCSubstitutionContext>::load,
  PythonBinding<mx::ObjCTypeParamVariance>::load,
  PythonBinding<mx::OnOffSwitch>::load,
  PythonBinding<mx::OnStackType>::load,
  PythonBinding<mx::OpenMPAdjustArgsOpKind>::load,
  PythonBinding<mx::OpenMPAtClauseKind>::load,
  PythonBinding<mx::OpenMPAtomicDefaultMemOrderClauseKind>::load,
  PythonBinding<mx::OpenMPBindClauseKind>::load,
  PythonBinding<mx::OpenMPDefaultmapClauseKind>::load,
  PythonBinding<mx::OpenMPDefaultmapClauseModifier>::load,
  PythonBinding<mx::OpenMPDependClauseKind>::load,
  PythonBinding<mx::OpenMPDeviceClauseModifier>::load,
  PythonBinding<mx::OpenMPDeviceType>::load,
  PythonBinding<mx::OpenMPDistScheduleClauseKind>::load,
  PythonBinding<mx::OpenMPDoacrossClauseModifier>::load,
  PythonBinding<mx::OpenMPGrainsizeClauseModifier>::load,
  PythonBinding<mx::OpenMPLastprivateModifier>::load,
  PythonBinding<mx::OpenMPLinearClauseKind>::load,
  PythonBinding<mx::OpenMPMapClauseKind>::load,
  PythonBinding<mx::OpenMPMapModifierKind>::load,
  PythonBinding<mx::OpenMPMotionModifierKind>::load,
  PythonBinding<mx::OpenMPNumTasksClauseModifier>::load,
  PythonBinding<mx::OpenMPOrderClauseKind>::load,
  PythonBinding<mx::OpenMPOrderClauseModifier>::load,
  PythonBinding<mx::OpenMPReductionClauseModifier>::load,
  PythonBinding<mx::OpenMPScheduleClauseKind>::load,
  PythonBinding<mx::OpenMPScheduleClauseModifier>::load,
  PythonBinding<mx::OpenMPSeverityClauseKind>::load,
  PythonBinding<mx::OverloadedOperatorKind>::load,
  PythonBinding<mx::OverloadsShown>::load,
  PythonBinding<mx::ParameterABI>::load,
  PythonBinding<mx::ParenLocsOffsets>::load,
  PythonBinding<mx::PragmaFloatControlKind>::load,
  PythonBinding<mx::PragmaMSCommentKind>::load,
  PythonBinding<mx::PragmaMSPointersToMembersKind>::load,
  PythonBinding<mx::PragmaMSStructKind>::load,
  PythonBinding<mx::PragmaSectionFlag>::load,
  PythonBinding<mx::ProfileInstrKind>::load,
  PythonBinding<mx::Qualified>::load,
  PythonBinding<mx::RangeExprOffset>::load,
  PythonBinding<mx::RangeLocOffset>::load,
  PythonBinding<mx::RefQualifierKind>::load,
  PythonBinding<mx::RemarkKind>::load,
  PythonBinding<mx::ReservedIdentifierStatus>::load,
  PythonBinding<mx::ReservedLiteralSuffixIdStatus>::load,
  PythonBinding<mx::SFINAEResponse>::load,
  PythonBinding<mx::SYCLMajorVersion>::load,
  PythonBinding<mx::SanitizerOrdinal>::load,
  PythonBinding<mx::SelectorLocationsKind>::load,
  PythonBinding<mx::ShaderStage>::load,
  PythonBinding<mx::SignReturnAddressKeyKind>::load,
  PythonBinding<mx::SignReturnAddressScopeKind>::load,
  PythonBinding<mx::SignedOverflowBehaviorTy>::load,
  PythonBinding<mx::SpecialMemberFlags>::load,
  PythonBinding<mx::SpecifierKind>::load,
  PythonBinding<mx::StackProtectorMode>::load,
  PythonBinding<mx::StorageClass>::load,
  PythonBinding<mx::StorageDuration>::load,
  PythonBinding<mx::StoredNameKind>::load,
  PythonBinding<mx::StoredSpecifierKind>::load,
  PythonBinding<mx::StrictFlexArraysLevelKind>::load,
  PythonBinding<mx::StructReturnConventionKind>::load,
  PythonBinding<mx::SubExpr>::load,
  PythonBinding<mx::SubStmt>::load,
  PythonBinding<mx::SwiftAsyncFramePointerKind>::load,
  PythonBinding<mx::SyncScope>::load,
  PythonBinding<mx::Syntax>::load,
  PythonBinding<mx::TLSModel>::load,
  PythonBinding<mx::TQ>::load,
  PythonBinding<mx::TagTypeKind>::load,
  PythonBinding<mx::TailPaddingUseRules>::load,
  PythonBinding<mx::TemplateArgumentDependence>::load,
  PythonBinding<mx::TemplateNameDependence>::load,
  PythonBinding<mx::TemplateSpecializationKind>::load,
  PythonBinding<mx::TextDiagnosticFormat>::load,
  PythonBinding<mx::ThreadModelKind>::load,
  PythonBinding<mx::ThreadStorageClassSpecifier>::load,
  PythonBinding<mx::TrailingAllocKind>::load,
  PythonBinding<mx::TranslationUnitKind>::load,
  PythonBinding<mx::TrivialAutoVarInitKind>::load,
  PythonBinding<mx::TypeDependence>::load,
  PythonBinding<mx::TypeLocClass>::load,
  PythonBinding<mx::TypeOfKind>::load,
  PythonBinding<mx::TypeSpecifierSign>::load,
  PythonBinding<mx::TypeSpecifierType>::load,
  PythonBinding<mx::TypeSpecifierWidth>::load,
  PythonBinding<mx::TypeSpecifiersPipe>::load,
  PythonBinding<mx::TypeTrait>::load,
  PythonBinding<mx::UnaryExprOrTypeTrait>::load,
  PythonBinding<mx::UnaryOperatorKind>::load,
  PythonBinding<mx::APValueKind>::load,
  PythonBinding<mx::VectorLibrary>::load,
  PythonBinding<mx::Visibility>::load,
  PythonBinding<mx::AttributeSyntax>::load,
  PythonBinding<mx::DeclCategory>::load,
  PythonBinding<mx::PseudoKind>::load,
  PythonBinding<mx::Designator>::load,
  PythonBinding<mx::CXXBaseSpecifier>::load,
  PythonBinding<mx::TemplateParameterList>::load,
  PythonBinding<mx::TemplateArgument>::load,
  PythonBinding<mx::Attr>::load,
  PythonBinding<mx::AlignValueAttr>::load,
  PythonBinding<mx::AliasAttr>::load,
  PythonBinding<mx::AbiTagAttr>::load,
  PythonBinding<mx::TypeAttr>::load,
  PythonBinding<mx::SPtrAttr>::load,
  PythonBinding<mx::Ptr64Attr>::load,
  PythonBinding<mx::Ptr32Attr>::load,
  PythonBinding<mx::OpenCLPrivateAddressSpaceAttr>::load,
  PythonBinding<mx::OpenCLLocalAddressSpaceAttr>::load,
  PythonBinding<mx::OpenCLGlobalHostAddressSpaceAttr>::load,
  PythonBinding<mx::OpenCLGlobalDeviceAddressSpaceAttr>::load,
  PythonBinding<mx::OpenCLGlobalAddressSpaceAttr>::load,
  PythonBinding<mx::OpenCLGenericAddressSpaceAttr>::load,
  PythonBinding<mx::OpenCLConstantAddressSpaceAttr>::load,
  PythonBinding<mx::ObjCKindOfAttr>::load,
  PythonBinding<mx::ObjCInertUnsafeUnretainedAttr>::load,
  PythonBinding<mx::ObjCGCAttr>::load,
  PythonBinding<mx::NoDerefAttr>::load,
  PythonBinding<mx::HLSLGroupSharedAddressSpaceAttr>::load,
  PythonBinding<mx::CmseNSCallAttr>::load,
  PythonBinding<mx::BTFTypeTagAttr>::load,
  PythonBinding<mx::ArmStreamingAttr>::load,
  PythonBinding<mx::ArmMveStrictPolymorphismAttr>::load,
  PythonBinding<mx::AnnotateTypeAttr>::load,
  PythonBinding<mx::AddressSpaceAttr>::load,
  PythonBinding<mx::WebAssemblyFuncrefAttr>::load,
  PythonBinding<mx::UPtrAttr>::load,
  PythonBinding<mx::TypeNullableResultAttr>::load,
  PythonBinding<mx::TypeNullableAttr>::load,
  PythonBinding<mx::TypeNullUnspecifiedAttr>::load,
  PythonBinding<mx::TypeNonNullAttr>::load,
  PythonBinding<mx::ThreadAttr>::load,
  PythonBinding<mx::SwiftObjCMembersAttr>::load,
  PythonBinding<mx::StmtAttr>::load,
  PythonBinding<mx::OpenCLUnrollHintAttr>::load,
  PythonBinding<mx::MustTailAttr>::load,
  PythonBinding<mx::LikelyAttr>::load,
  PythonBinding<mx::FallThroughAttr>::load,
  PythonBinding<mx::UnlikelyAttr>::load,
  PythonBinding<mx::SuppressAttr>::load,
  PythonBinding<mx::RenderScriptKernelAttr>::load,
  PythonBinding<mx::OverloadableAttr>::load,
  PythonBinding<mx::OpenCLAccessAttr>::load,
  PythonBinding<mx::ObjCRuntimeVisibleAttr>::load,
  PythonBinding<mx::ObjCRuntimeNameAttr>::load,
  PythonBinding<mx::ObjCNonRuntimeProtocolAttr>::load,
  PythonBinding<mx::ObjCNonLazyClassAttr>::load,
  PythonBinding<mx::ObjCDirectMembersAttr>::load,
  PythonBinding<mx::ObjCDirectAttr>::load,
  PythonBinding<mx::ObjCDesignatedInitializerAttr>::load,
  PythonBinding<mx::ObjCClassStubAttr>::load,
  PythonBinding<mx::ObjCBoxableAttr>::load,
  PythonBinding<mx::OMPReferencedVarAttr>::load,
  PythonBinding<mx::OMPDeclareSimdDeclAttr>::load,
  PythonBinding<mx::OMPCaptureKindAttr>::load,
  PythonBinding<mx::NoEscapeAttr>::load,
  PythonBinding<mx::NoBuiltinAttr>::load,
  PythonBinding<mx::ModeAttr>::load,
  PythonBinding<mx::LoopHintAttr>::load,
  PythonBinding<mx::LoaderUninitializedAttr>::load,
  PythonBinding<mx::InitSegAttr>::load,
  PythonBinding<mx::InheritableAttr>::load,
  PythonBinding<mx::IBOutletCollectionAttr>::load,
  PythonBinding<mx::IBOutletAttr>::load,
  PythonBinding<mx::IBActionAttr>::load,
  PythonBinding<mx::HotAttr>::load,
  PythonBinding<mx::HLSLShaderAttr>::load,
  PythonBinding<mx::HLSLResourceBindingAttr>::load,
  PythonBinding<mx::HLSLResourceAttr>::load,
  PythonBinding<mx::HLSLNumThreadsAttr>::load,
  PythonBinding<mx::HLSLAnnotationAttr>::load,
  PythonBinding<mx::HLSLSV_GroupIndexAttr>::load,
  PythonBinding<mx::HLSLSV_DispatchThreadIDAttr>::load,
  PythonBinding<mx::HIPManagedAttr>::load,
  PythonBinding<mx::GuardedVarAttr>::load,
  PythonBinding<mx::GuardedByAttr>::load,
  PythonBinding<mx::GNUInlineAttr>::load,
  PythonBinding<mx::FunctionReturnThunksAttr>::load,
  PythonBinding<mx::FormatAttr>::load,
  PythonBinding<mx::FormatArgAttr>::load,
  PythonBinding<mx::FlattenAttr>::load,
  PythonBinding<mx::FlagEnumAttr>::load,
  PythonBinding<mx::FinalAttr>::load,
  PythonBinding<mx::FastCallAttr>::load,
  PythonBinding<mx::ExternalSourceSymbolAttr>::load,
  PythonBinding<mx::ExclusiveTrylockFunctionAttr>::load,
  PythonBinding<mx::ExcludeFromExplicitInstantiationAttr>::load,
  PythonBinding<mx::ErrorAttr>::load,
  PythonBinding<mx::EnumExtensibilityAttr>::load,
  PythonBinding<mx::EnforceTCBLeafAttr>::load,
  PythonBinding<mx::EnforceTCBAttr>::load,
  PythonBinding<mx::EnableIfAttr>::load,
  PythonBinding<mx::EmptyBasesAttr>::load,
  PythonBinding<mx::DisableTailCallsAttr>::load,
  PythonBinding<mx::DisableSanitizerInstrumentationAttr>::load,
  PythonBinding<mx::DiagnoseIfAttr>::load,
  PythonBinding<mx::DiagnoseAsBuiltinAttr>::load,
  PythonBinding<mx::DestructorAttr>::load,
  PythonBinding<mx::DeprecatedAttr>::load,
  PythonBinding<mx::DeclOrStmtAttr>::load,
  PythonBinding<mx::AlwaysInlineAttr>::load,
  PythonBinding<mx::NoMergeAttr>::load,
  PythonBinding<mx::NoInlineAttr>::load,
  PythonBinding<mx::DLLImportStaticLocalAttr>::load,
  PythonBinding<mx::DLLImportAttr>::load,
  PythonBinding<mx::DLLExportStaticLocalAttr>::load,
  PythonBinding<mx::DLLExportAttr>::load,
  PythonBinding<mx::ConvergentAttr>::load,
  PythonBinding<mx::ConsumableSetOnReadAttr>::load,
  PythonBinding<mx::ConsumableAutoCastAttr>::load,
  PythonBinding<mx::ConsumableAttr>::load,
  PythonBinding<mx::ConstructorAttr>::load,
  PythonBinding<mx::ConstInitAttr>::load,
  PythonBinding<mx::ConstAttr>::load,
  PythonBinding<mx::CommonAttr>::load,
  PythonBinding<mx::ColdAttr>::load,
  PythonBinding<mx::CodeSegAttr>::load,
  PythonBinding<mx::CmseNSEntryAttr>::load,
  PythonBinding<mx::CleanupAttr>::load,
  PythonBinding<mx::CapturedRecordAttr>::load,
  PythonBinding<mx::CapabilityAttr>::load,
  PythonBinding<mx::CallbackAttr>::load,
  PythonBinding<mx::CallableWhenAttr>::load,
  PythonBinding<mx::CXX11NoReturnAttr>::load,
  PythonBinding<mx::CUDASharedAttr>::load,
  PythonBinding<mx::CUDALaunchBoundsAttr>::load,
  PythonBinding<mx::CUDAInvalidTargetAttr>::load,
  PythonBinding<mx::CUDAHostAttr>::load,
  PythonBinding<mx::CUDAGlobalAttr>::load,
  PythonBinding<mx::CUDADeviceBuiltinTextureTypeAttr>::load,
  PythonBinding<mx::CUDADeviceBuiltinSurfaceTypeAttr>::load,
  PythonBinding<mx::CUDADeviceAttr>::load,
  PythonBinding<mx::CUDAConstantAttr>::load,
  PythonBinding<mx::CPUSpecificAttr>::load,
  PythonBinding<mx::CPUDispatchAttr>::load,
  PythonBinding<mx::CFUnknownTransferAttr>::load,
  PythonBinding<mx::CFReturnsRetainedAttr>::load,
  PythonBinding<mx::CFReturnsNotRetainedAttr>::load,
  PythonBinding<mx::CFICanonicalJumpTableAttr>::load,
  PythonBinding<mx::CFGuardAttr>::load,
  PythonBinding<mx::CFAuditedTransferAttr>::load,
  PythonBinding<mx::CDeclAttr>::load,
  PythonBinding<mx::C11NoReturnAttr>::load,
  PythonBinding<mx::BuiltinAttr>::load,
  PythonBinding<mx::BlocksAttr>::load,
  PythonBinding<mx::BTFDeclTagAttr>::load,
  PythonBinding<mx::BPFPreserveAccessIndexAttr>::load,
  PythonBinding<mx::AvailableOnlyInDefaultEvalMethodAttr>::load,
  PythonBinding<mx::AvailabilityAttr>::load,
  PythonBinding<mx::AssumptionAttr>::load,
  PythonBinding<mx::AssumeAlignedAttr>::load,
  PythonBinding<mx::AssertSharedLockAttr>::load,
  PythonBinding<mx::AssertExclusiveLockAttr>::load,
  PythonBinding<mx::AssertCapabilityAttr>::load,
  PythonBinding<mx::AsmLabelAttr>::load,
  PythonBinding<mx::ArtificialAttr>::load,
  PythonBinding<mx::ArmBuiltinAliasAttr>::load,
  PythonBinding<mx::ArgumentWithTypeTagAttr>::load,
  PythonBinding<mx::ArcWeakrefUnavailableAttr>::load,
  PythonBinding<mx::AnyX86NoCfCheckAttr>::load,
  PythonBinding<mx::AnyX86NoCallerSavedRegistersAttr>::load,
  PythonBinding<mx::AnyX86InterruptAttr>::load,
  PythonBinding<mx::AnalyzerNoReturnAttr>::load,
  PythonBinding<mx::AlwaysDestroyAttr>::load,
  PythonBinding<mx::AllocSizeAttr>::load,
  PythonBinding<mx::AllocAlignAttr>::load,
  PythonBinding<mx::AlignedAttr>::load,
  PythonBinding<mx::AlignNaturalAttr>::load,
  PythonBinding<mx::AlignMac68kAttr>::load,
  PythonBinding<mx::AcquiredBeforeAttr>::load,
  PythonBinding<mx::AcquiredAfterAttr>::load,
  PythonBinding<mx::AcquireHandleAttr>::load,
  PythonBinding<mx::AcquireCapabilityAttr>::load,
  PythonBinding<mx::AVRSignalAttr>::load,
  PythonBinding<mx::AVRInterruptAttr>::load,
  PythonBinding<mx::ARMInterruptAttr>::load,
  PythonBinding<mx::AMDGPUWavesPerEUAttr>::load,
  PythonBinding<mx::AMDGPUNumVGPRAttr>::load,
  PythonBinding<mx::AMDGPUNumSGPRAttr>::load,
  PythonBinding<mx::AMDGPUKernelCallAttr>::load,
  PythonBinding<mx::AMDGPUFlatWorkGroupSizeAttr>::load,
  PythonBinding<mx::AArch64VectorPcsAttr>::load,
  PythonBinding<mx::AArch64SVEPcsAttr>::load,
  PythonBinding<mx::ZeroCallUsedRegsAttr>::load,
  PythonBinding<mx::XRayLogArgsAttr>::load,
  PythonBinding<mx::XRayInstrumentAttr>::load,
  PythonBinding<mx::X86ForceAlignArgPointerAttr>::load,
  PythonBinding<mx::WorkGroupSizeHintAttr>::load,
  PythonBinding<mx::WebAssemblyImportNameAttr>::load,
  PythonBinding<mx::WebAssemblyImportModuleAttr>::load,
  PythonBinding<mx::WebAssemblyExportNameAttr>::load,
  PythonBinding<mx::WeakRefAttr>::load,
  PythonBinding<mx::WeakImportAttr>::load,
  PythonBinding<mx::WeakAttr>::load,
  PythonBinding<mx::WarnUnusedResultAttr>::load,
  PythonBinding<mx::WarnUnusedAttr>::load,
  PythonBinding<mx::VisibilityAttr>::load,
  PythonBinding<mx::VectorCallAttr>::load,
  PythonBinding<mx::VecTypeHintAttr>::load,
  PythonBinding<mx::VecReturnAttr>::load,
  PythonBinding<mx::UuidAttr>::load,
  PythonBinding<mx::UsingIfExistsAttr>::load,
  PythonBinding<mx::UsedAttr>::load,
  PythonBinding<mx::UnusedAttr>::load,
  PythonBinding<mx::UnsafeBufferUsageAttr>::load,
  PythonBinding<mx::UninitializedAttr>::load,
  PythonBinding<mx::UnavailableAttr>::load,
  PythonBinding<mx::TypeVisibilityAttr>::load,
  PythonBinding<mx::TypeTagForDatatypeAttr>::load,
  PythonBinding<mx::TryAcquireCapabilityAttr>::load,
  PythonBinding<mx::TrivialABIAttr>::load,
  PythonBinding<mx::TransparentUnionAttr>::load,
  PythonBinding<mx::ThisCallAttr>::load,
  PythonBinding<mx::TestTypestateAttr>::load,
  PythonBinding<mx::TargetVersionAttr>::load,
  PythonBinding<mx::TargetClonesAttr>::load,
  PythonBinding<mx::TargetAttr>::load,
  PythonBinding<mx::TLSModelAttr>::load,
  PythonBinding<mx::SysVABIAttr>::load,
  PythonBinding<mx::SwiftPrivateAttr>::load,
  PythonBinding<mx::SwiftNewTypeAttr>::load,
  PythonBinding<mx::SwiftNameAttr>::load,
  PythonBinding<mx::SwiftErrorAttr>::load,
  PythonBinding<mx::SwiftCallAttr>::load,
  PythonBinding<mx::SwiftBridgedTypedefAttr>::load,
  PythonBinding<mx::SwiftBridgeAttr>::load,
  PythonBinding<mx::SwiftAttrAttr>::load,
  PythonBinding<mx::SwiftAsyncNameAttr>::load,
  PythonBinding<mx::SwiftAsyncErrorAttr>::load,
  PythonBinding<mx::SwiftAsyncCallAttr>::load,
  PythonBinding<mx::SwiftAsyncAttr>::load,
  PythonBinding<mx::StrictGuardStackCheckAttr>::load,
  PythonBinding<mx::StrictFPAttr>::load,
  PythonBinding<mx::StdCallAttr>::load,
  PythonBinding<mx::StandaloneDebugAttr>::load,
  PythonBinding<mx::SpeculativeLoadHardeningAttr>::load,
  PythonBinding<mx::SharedTrylockFunctionAttr>::load,
  PythonBinding<mx::SetTypestateAttr>::load,
  PythonBinding<mx::SentinelAttr>::load,
  PythonBinding<mx::SelectAnyAttr>::load,
  PythonBinding<mx::SectionAttr>::load,
  PythonBinding<mx::ScopedLockableAttr>::load,
  PythonBinding<mx::SYCLSpecialClassAttr>::load,
  PythonBinding<mx::SYCLKernelAttr>::load,
  PythonBinding<mx::ReturnsTwiceAttr>::load,
  PythonBinding<mx::ReturnsNonNullAttr>::load,
  PythonBinding<mx::ReturnTypestateAttr>::load,
  PythonBinding<mx::RetainAttr>::load,
  PythonBinding<mx::RestrictAttr>::load,
  PythonBinding<mx::RequiresCapabilityAttr>::load,
  PythonBinding<mx::ReqdWorkGroupSizeAttr>::load,
  PythonBinding<mx::ReleaseCapabilityAttr>::load,
  PythonBinding<mx::ReinitializesAttr>::load,
  PythonBinding<mx::RegCallAttr>::load,
  PythonBinding<mx::ReadOnlyPlacementAttr>::load,
  PythonBinding<mx::RandomizeLayoutAttr>::load,
  PythonBinding<mx::RISCVInterruptAttr>::load,
  PythonBinding<mx::PureAttr>::load,
  PythonBinding<mx::PtGuardedVarAttr>::load,
  PythonBinding<mx::PtGuardedByAttr>::load,
  PythonBinding<mx::PreserveMostAttr>::load,
  PythonBinding<mx::PreserveAllAttr>::load,
  PythonBinding<mx::PreferredNameAttr>::load,
  PythonBinding<mx::PragmaClangTextSectionAttr>::load,
  PythonBinding<mx::PragmaClangRodataSectionAttr>::load,
  PythonBinding<mx::PragmaClangRelroSectionAttr>::load,
  PythonBinding<mx::PragmaClangDataSectionAttr>::load,
  PythonBinding<mx::PragmaClangBSSSectionAttr>::load,
  PythonBinding<mx::PointerAttr>::load,
  PythonBinding<mx::PcsAttr>::load,
  PythonBinding<mx::PatchableFunctionEntryAttr>::load,
  PythonBinding<mx::PascalAttr>::load,
  PythonBinding<mx::ParamTypestateAttr>::load,
  PythonBinding<mx::PackedAttr>::load,
  PythonBinding<mx::OwnershipAttr>::load,
  PythonBinding<mx::OwnerAttr>::load,
  PythonBinding<mx::OverrideAttr>::load,
  PythonBinding<mx::OptimizeNoneAttr>::load,
  PythonBinding<mx::OpenCLKernelAttr>::load,
  PythonBinding<mx::OpenCLIntelReqdSubGroupSizeAttr>::load,
  PythonBinding<mx::ObjCSubclassingRestrictedAttr>::load,
  PythonBinding<mx::ObjCRootClassAttr>::load,
  PythonBinding<mx::ObjCReturnsInnerPointerAttr>::load,
  PythonBinding<mx::ObjCRequiresSuperAttr>::load,
  PythonBinding<mx::ObjCRequiresPropertyDefsAttr>::load,
  PythonBinding<mx::ObjCPreciseLifetimeAttr>::load,
  PythonBinding<mx::ObjCOwnershipAttr>::load,
  PythonBinding<mx::ObjCNSObjectAttr>::load,
  PythonBinding<mx::ObjCMethodFamilyAttr>::load,
  PythonBinding<mx::ObjCIndependentClassAttr>::load,
  PythonBinding<mx::ObjCExternallyRetainedAttr>::load,
  PythonBinding<mx::ObjCExplicitProtocolImplAttr>::load,
  PythonBinding<mx::ObjCExceptionAttr>::load,
  PythonBinding<mx::ObjCBridgeRelatedAttr>::load,
  PythonBinding<mx::ObjCBridgeMutableAttr>::load,
  PythonBinding<mx::ObjCBridgeAttr>::load,
  PythonBinding<mx::OSReturnsRetainedOnZeroAttr>::load,
  PythonBinding<mx::OSReturnsRetainedOnNonZeroAttr>::load,
  PythonBinding<mx::OSReturnsRetainedAttr>::load,
  PythonBinding<mx::OSReturnsNotRetainedAttr>::load,
  PythonBinding<mx::OSConsumesThisAttr>::load,
  PythonBinding<mx::OMPThreadPrivateDeclAttr>::load,
  PythonBinding<mx::OMPDeclareVariantAttr>::load,
  PythonBinding<mx::OMPDeclareTargetDeclAttr>::load,
  PythonBinding<mx::OMPCaptureNoInitAttr>::load,
  PythonBinding<mx::OMPAllocateDeclAttr>::load,
  PythonBinding<mx::NotTailCalledAttr>::load,
  PythonBinding<mx::NoUwtableAttr>::load,
  PythonBinding<mx::NoUniqueAddressAttr>::load,
  PythonBinding<mx::NoThrowAttr>::load,
  PythonBinding<mx::NoThreadSafetyAnalysisAttr>::load,
  PythonBinding<mx::NoStackProtectorAttr>::load,
  PythonBinding<mx::NoSplitStackAttr>::load,
  PythonBinding<mx::NoSpeculativeLoadHardeningAttr>::load,
  PythonBinding<mx::NoSanitizeAttr>::load,
  PythonBinding<mx::NoReturnAttr>::load,
  PythonBinding<mx::NoRandomizeLayoutAttr>::load,
  PythonBinding<mx::NoProfileFunctionAttr>::load,
  PythonBinding<mx::NoMips16Attr>::load,
  PythonBinding<mx::NoMicroMipsAttr>::load,
  PythonBinding<mx::NoInstrumentFunctionAttr>::load,
  PythonBinding<mx::NoDuplicateAttr>::load,
  PythonBinding<mx::NoDestroyAttr>::load,
  PythonBinding<mx::NoDebugAttr>::load,
  PythonBinding<mx::NoCommonAttr>::load,
  PythonBinding<mx::NoAliasAttr>::load,
  PythonBinding<mx::NakedAttr>::load,
  PythonBinding<mx::NVPTXKernelAttr>::load,
  PythonBinding<mx::NSReturnsRetainedAttr>::load,
  PythonBinding<mx::NSReturnsNotRetainedAttr>::load,
  PythonBinding<mx::NSReturnsAutoreleasedAttr>::load,
  PythonBinding<mx::NSErrorDomainAttr>::load,
  PythonBinding<mx::NSConsumesSelfAttr>::load,
  PythonBinding<mx::MipsShortCallAttr>::load,
  PythonBinding<mx::MipsLongCallAttr>::load,
  PythonBinding<mx::MipsInterruptAttr>::load,
  PythonBinding<mx::Mips16Attr>::load,
  PythonBinding<mx::MinVectorWidthAttr>::load,
  PythonBinding<mx::MinSizeAttr>::load,
  PythonBinding<mx::MicroMipsAttr>::load,
  PythonBinding<mx::MaybeUndefAttr>::load,
  PythonBinding<mx::MayAliasAttr>::load,
  PythonBinding<mx::MaxFieldAlignmentAttr>::load,
  PythonBinding<mx::MSVtorDispAttr>::load,
  PythonBinding<mx::MSStructAttr>::load,
  PythonBinding<mx::MSP430InterruptAttr>::load,
  PythonBinding<mx::MSNoVTableAttr>::load,
  PythonBinding<mx::MSInheritanceAttr>::load,
  PythonBinding<mx::MSAllocatorAttr>::load,
  PythonBinding<mx::MSABIAttr>::load,
  PythonBinding<mx::MIGServerRoutineAttr>::load,
  PythonBinding<mx::M68kInterruptAttr>::load,
  PythonBinding<mx::LocksExcludedAttr>::load,
  PythonBinding<mx::LockReturnedAttr>::load,
  PythonBinding<mx::LifetimeBoundAttr>::load,
  PythonBinding<mx::LeafAttr>::load,
  PythonBinding<mx::LayoutVersionAttr>::load,
  PythonBinding<mx::LTOVisibilityPublicAttr>::load,
  PythonBinding<mx::InternalLinkageAttr>::load,
  PythonBinding<mx::IntelOclBiccAttr>::load,
  PythonBinding<mx::InitPriorityAttr>::load,
  PythonBinding<mx::InheritableParamAttr>::load,
  PythonBinding<mx::CarriesDependencyAttr>::load,
  PythonBinding<mx::CFConsumedAttr>::load,
  PythonBinding<mx::AnnotateAttr>::load,
  PythonBinding<mx::UseHandleAttr>::load,
  PythonBinding<mx::ReleaseHandleAttr>::load,
  PythonBinding<mx::PassObjectSizeAttr>::load,
  PythonBinding<mx::ParameterABIAttr>::load,
  PythonBinding<mx::SwiftIndirectResultAttr>::load,
  PythonBinding<mx::SwiftErrorResultAttr>::load,
  PythonBinding<mx::SwiftContextAttr>::load,
  PythonBinding<mx::SwiftAsyncContextAttr>::load,
  PythonBinding<mx::OSConsumedAttr>::load,
  PythonBinding<mx::NonNullAttr>::load,
  PythonBinding<mx::NSConsumedAttr>::load,
  PythonBinding<mx::IFuncAttr>::load,
  PythonBinding<mx::CalledOnceAttr>::load,
  PythonBinding<mx::BuiltinAliasAttr>::load,
  PythonBinding<mx::Type>::load,
  PythonBinding<mx::TemplateTypeParmType>::load,
  PythonBinding<mx::TemplateSpecializationType>::load,
  PythonBinding<mx::TagType>::load,
  PythonBinding<mx::RecordType>::load,
  PythonBinding<mx::EnumType>::load,
  PythonBinding<mx::SubstTemplateTypeParmType>::load,
  PythonBinding<mx::SubstTemplateTypeParmPackType>::load,
  PythonBinding<mx::ReferenceType>::load,
  PythonBinding<mx::RValueReferenceType>::load,
  PythonBinding<mx::LValueReferenceType>::load,
  PythonBinding<mx::QualifiedType>::load,
  PythonBinding<mx::PointerType>::load,
  PythonBinding<mx::PipeType>::load,
  PythonBinding<mx::ParenType>::load,
  PythonBinding<mx::PackExpansionType>::load,
  PythonBinding<mx::ObjCTypeParamType>::load,
  PythonBinding<mx::ObjCObjectType>::load,
  PythonBinding<mx::ObjCInterfaceType>::load,
  PythonBinding<mx::ObjCObjectPointerType>::load,
  PythonBinding<mx::MemberPointerType>::load,
  PythonBinding<mx::MatrixType>::load,
  PythonBinding<mx::DependentSizedMatrixType>::load,
  PythonBinding<mx::ConstantMatrixType>::load,
  PythonBinding<mx::MacroQualifiedType>::load,
  PythonBinding<mx::InjectedClassNameType>::load,
  PythonBinding<mx::FunctionType>::load,
  PythonBinding<mx::FunctionProtoType>::load,
  PythonBinding<mx::FunctionNoProtoType>::load,
  PythonBinding<mx::DependentVectorType>::load,
  PythonBinding<mx::DependentSizedExtVectorType>::load,
  PythonBinding<mx::DependentBitIntType>::load,
  PythonBinding<mx::DependentAddressSpaceType>::load,
  PythonBinding<mx::DeducedType>::load,
  PythonBinding<mx::DeducedTemplateSpecializationType>::load,
  PythonBinding<mx::AutoType>::load,
  PythonBinding<mx::DecltypeType>::load,
  PythonBinding<mx::ComplexType>::load,
  PythonBinding<mx::BuiltinType>::load,
  PythonBinding<mx::BlockPointerType>::load,
  PythonBinding<mx::BitIntType>::load,
  PythonBinding<mx::BTFTagAttributedType>::load,
  PythonBinding<mx::AttributedType>::load,
  PythonBinding<mx::AtomicType>::load,
  PythonBinding<mx::ArrayType>::load,
  PythonBinding<mx::VariableArrayType>::load,
  PythonBinding<mx::IncompleteArrayType>::load,
  PythonBinding<mx::DependentSizedArrayType>::load,
  PythonBinding<mx::ConstantArrayType>::load,
  PythonBinding<mx::AdjustedType>::load,
  PythonBinding<mx::DecayedType>::load,
  PythonBinding<mx::TypeWithKeyword>::load,
  PythonBinding<mx::ElaboratedType>::load,
  PythonBinding<mx::DependentTemplateSpecializationType>::load,
  PythonBinding<mx::DependentNameType>::load,
  PythonBinding<mx::VectorType>::load,
  PythonBinding<mx::ExtVectorType>::load,
  PythonBinding<mx::UsingType>::load,
  PythonBinding<mx::UnresolvedUsingType>::load,
  PythonBinding<mx::UnaryTransformType>::load,
  PythonBinding<mx::TypedefType>::load,
  PythonBinding<mx::TypeOfType>::load,
  PythonBinding<mx::TypeOfExprType>::load,
  PythonBinding<mx::Stmt>::load,
  PythonBinding<mx::SEHTryStmt>::load,
  PythonBinding<mx::SEHLeaveStmt>::load,
  PythonBinding<mx::SEHFinallyStmt>::load,
  PythonBinding<mx::SEHExceptStmt>::load,
  PythonBinding<mx::ReturnStmt>::load,
  PythonBinding<mx::ObjCForCollectionStmt>::load,
  PythonBinding<mx::ObjCAutoreleasePoolStmt>::load,
  PythonBinding<mx::ObjCAtTryStmt>::load,
  PythonBinding<mx::ObjCAtThrowStmt>::load,
  PythonBinding<mx::ObjCAtSynchronizedStmt>::load,
  PythonBinding<mx::ObjCAtFinallyStmt>::load,
  PythonBinding<mx::ObjCAtCatchStmt>::load,
  PythonBinding<mx::OMPExecutableDirective>::load,
  PythonBinding<mx::OMPErrorDirective>::load,
  PythonBinding<mx::OMPDispatchDirective>::load,
  PythonBinding<mx::OMPDepobjDirective>::load,
  PythonBinding<mx::OMPCriticalDirective>::load,
  PythonBinding<mx::OMPCancellationPointDirective>::load,
  PythonBinding<mx::OMPCancelDirective>::load,
  PythonBinding<mx::OMPBarrierDirective>::load,
  PythonBinding<mx::OMPAtomicDirective>::load,
  PythonBinding<mx::OMPTeamsDirective>::load,
  PythonBinding<mx::OMPTaskyieldDirective>::load,
  PythonBinding<mx::OMPTaskwaitDirective>::load,
  PythonBinding<mx::OMPTaskgroupDirective>::load,
  PythonBinding<mx::OMPTaskDirective>::load,
  PythonBinding<mx::OMPTargetUpdateDirective>::load,
  PythonBinding<mx::OMPTargetTeamsDirective>::load,
  PythonBinding<mx::OMPTargetParallelDirective>::load,
  PythonBinding<mx::OMPTargetExitDataDirective>::load,
  PythonBinding<mx::OMPTargetEnterDataDirective>::load,
  PythonBinding<mx::OMPTargetDirective>::load,
  PythonBinding<mx::OMPTargetDataDirective>::load,
  PythonBinding<mx::OMPSingleDirective>::load,
  PythonBinding<mx::OMPSectionsDirective>::load,
  PythonBinding<mx::OMPSectionDirective>::load,
  PythonBinding<mx::OMPScanDirective>::load,
  PythonBinding<mx::OMPParallelSectionsDirective>::load,
  PythonBinding<mx::OMPParallelMasterDirective>::load,
  PythonBinding<mx::OMPParallelMaskedDirective>::load,
  PythonBinding<mx::OMPParallelDirective>::load,
  PythonBinding<mx::OMPOrderedDirective>::load,
  PythonBinding<mx::OMPMetaDirective>::load,
  PythonBinding<mx::OMPMasterDirective>::load,
  PythonBinding<mx::OMPMaskedDirective>::load,
  PythonBinding<mx::OMPLoopBasedDirective>::load,
  PythonBinding<mx::OMPLoopTransformationDirective>::load,
  PythonBinding<mx::OMPUnrollDirective>::load,
  PythonBinding<mx::OMPTileDirective>::load,
  PythonBinding<mx::OMPLoopDirective>::load,
  PythonBinding<mx::OMPGenericLoopDirective>::load,
  PythonBinding<mx::OMPForSimdDirective>::load,
  PythonBinding<mx::OMPForDirective>::load,
  PythonBinding<mx::OMPDistributeSimdDirective>::load,
  PythonBinding<mx::OMPDistributeParallelForSimdDirective>::load,
  PythonBinding<mx::OMPDistributeParallelForDirective>::load,
  PythonBinding<mx::OMPDistributeDirective>::load,
  PythonBinding<mx::OMPTeamsGenericLoopDirective>::load,
  PythonBinding<mx::OMPTeamsDistributeSimdDirective>::load,
  PythonBinding<mx::OMPTeamsDistributeParallelForSimdDirective>::load,
  PythonBinding<mx::OMPTeamsDistributeParallelForDirective>::load,
  PythonBinding<mx::OMPTeamsDistributeDirective>::load,
  PythonBinding<mx::OMPTaskLoopSimdDirective>::load,
  PythonBinding<mx::OMPTaskLoopDirective>::load,
  PythonBinding<mx::OMPTargetTeamsGenericLoopDirective>::load,
  PythonBinding<mx::OMPTargetTeamsDistributeSimdDirective>::load,
  PythonBinding<mx::OMPTargetTeamsDistributeParallelForSimdDirective>::load,
  PythonBinding<mx::OMPTargetTeamsDistributeParallelForDirective>::load,
  PythonBinding<mx::OMPTargetTeamsDistributeDirective>::load,
  PythonBinding<mx::OMPTargetSimdDirective>::load,
  PythonBinding<mx::OMPTargetParallelGenericLoopDirective>::load,
  PythonBinding<mx::OMPTargetParallelForSimdDirective>::load,
  PythonBinding<mx::OMPTargetParallelForDirective>::load,
  PythonBinding<mx::OMPSimdDirective>::load,
  PythonBinding<mx::OMPParallelMasterTaskLoopSimdDirective>::load,
  PythonBinding<mx::OMPParallelMasterTaskLoopDirective>::load,
  PythonBinding<mx::OMPParallelMaskedTaskLoopSimdDirective>::load,
  PythonBinding<mx::OMPParallelMaskedTaskLoopDirective>::load,
  PythonBinding<mx::OMPParallelGenericLoopDirective>::load,
  PythonBinding<mx::OMPParallelForSimdDirective>::load,
  PythonBinding<mx::OMPParallelForDirective>::load,
  PythonBinding<mx::OMPMasterTaskLoopSimdDirective>::load,
  PythonBinding<mx::OMPMasterTaskLoopDirective>::load,
  PythonBinding<mx::OMPMaskedTaskLoopSimdDirective>::load,
  PythonBinding<mx::OMPMaskedTaskLoopDirective>::load,
  PythonBinding<mx::OMPInteropDirective>::load,
  PythonBinding<mx::OMPFlushDirective>::load,
  PythonBinding<mx::OMPCanonicalLoop>::load,
  PythonBinding<mx::NullStmt>::load,
  PythonBinding<mx::MSDependentExistsStmt>::load,
  PythonBinding<mx::IndirectGotoStmt>::load,
  PythonBinding<mx::IfStmt>::load,
  PythonBinding<mx::GotoStmt>::load,
  PythonBinding<mx::ForStmt>::load,
  PythonBinding<mx::DoStmt>::load,
  PythonBinding<mx::DeclStmt>::load,
  PythonBinding<mx::CoroutineBodyStmt>::load,
  PythonBinding<mx::CoreturnStmt>::load,
  PythonBinding<mx::ContinueStmt>::load,
  PythonBinding<mx::CompoundStmt>::load,
  PythonBinding<mx::CapturedStmt>::load,
  PythonBinding<mx::CXXTryStmt>::load,
  PythonBinding<mx::CXXForRangeStmt>::load,
  PythonBinding<mx::CXXCatchStmt>::load,
  PythonBinding<mx::BreakStmt>::load,
  PythonBinding<mx::AsmStmt>::load,
  PythonBinding<mx::MSAsmStmt>::load,
  PythonBinding<mx::GCCAsmStmt>::load,
  PythonBinding<mx::WhileStmt>::load,
  PythonBinding<mx::ValueStmt>::load,
  PythonBinding<mx::LabelStmt>::load,
  PythonBinding<mx::Expr>::load,
  PythonBinding<mx::DesignatedInitUpdateExpr>::load,
  PythonBinding<mx::DesignatedInitExpr>::load,
  PythonBinding<mx::DependentScopeDeclRefExpr>::load,
  PythonBinding<mx::DependentCoawaitExpr>::load,
  PythonBinding<mx::DeclRefExpr>::load,
  PythonBinding<mx::CoroutineSuspendExpr>::load,
  PythonBinding<mx::CoawaitExpr>::load,
  PythonBinding<mx::CoyieldExpr>::load,
  PythonBinding<mx::ConvertVectorExpr>::load,
  PythonBinding<mx::ConceptSpecializationExpr>::load,
  PythonBinding<mx::CompoundLiteralExpr>::load,
  PythonBinding<mx::ChooseExpr>::load,
  PythonBinding<mx::CharacterLiteral>::load,
  PythonBinding<mx::CastExpr>::load,
  PythonBinding<mx::ImplicitCastExpr>::load,
  PythonBinding<mx::ExplicitCastExpr>::load,
  PythonBinding<mx::CXXNamedCastExpr>::load,
  PythonBinding<mx::CXXDynamicCastExpr>::load,
  PythonBinding<mx::CXXConstCastExpr>::load,
  PythonBinding<mx::CXXAddrspaceCastExpr>::load,
  PythonBinding<mx::CXXStaticCastExpr>::load,
  PythonBinding<mx::CXXReinterpretCastExpr>::load,
  PythonBinding<mx::CXXFunctionalCastExpr>::load,
  PythonBinding<mx::CStyleCastExpr>::load,
  PythonBinding<mx::BuiltinBitCastExpr>::load,
  PythonBinding<mx::ObjCBridgedCastExpr>::load,
  PythonBinding<mx::CallExpr>::load,
  PythonBinding<mx::CXXOperatorCallExpr>::load,
  PythonBinding<mx::CXXMemberCallExpr>::load,
  PythonBinding<mx::CUDAKernelCallExpr>::load,
  PythonBinding<mx::UserDefinedLiteral>::load,
  PythonBinding<mx::CXXUuidofExpr>::load,
  PythonBinding<mx::CXXUnresolvedConstructExpr>::load,
  PythonBinding<mx::CXXTypeidExpr>::load,
  PythonBinding<mx::CXXThrowExpr>::load,
  PythonBinding<mx::CXXThisExpr>::load,
  PythonBinding<mx::CXXStdInitializerListExpr>::load,
  PythonBinding<mx::CXXScalarValueInitExpr>::load,
  PythonBinding<mx::CXXRewrittenBinaryOperator>::load,
  PythonBinding<mx::CXXPseudoDestructorExpr>::load,
  PythonBinding<mx::CXXParenListInitExpr>::load,
  PythonBinding<mx::CXXNullPtrLiteralExpr>::load,
  PythonBinding<mx::CXXNoexceptExpr>::load,
  PythonBinding<mx::CXXNewExpr>::load,
  PythonBinding<mx::CXXInheritedCtorInitExpr>::load,
  PythonBinding<mx::CXXFoldExpr>::load,
  PythonBinding<mx::CXXDependentScopeMemberExpr>::load,
  PythonBinding<mx::CXXDeleteExpr>::load,
  PythonBinding<mx::CXXDefaultInitExpr>::load,
  PythonBinding<mx::CXXDefaultArgExpr>::load,
  PythonBinding<mx::CXXConstructExpr>::load,
  PythonBinding<mx::CXXTemporaryObjectExpr>::load,
  PythonBinding<mx::CXXBoolLiteralExpr>::load,
  PythonBinding<mx::CXXBindTemporaryExpr>::load,
  PythonBinding<mx::BlockExpr>::load,
  PythonBinding<mx::BinaryOperator>::load,
  PythonBinding<mx::CompoundAssignOperator>::load,
  PythonBinding<mx::AtomicExpr>::load,
  PythonBinding<mx::AsTypeExpr>::load,
  PythonBinding<mx::ArrayTypeTraitExpr>::load,
  PythonBinding<mx::ArraySubscriptExpr>::load,
  PythonBinding<mx::ArrayInitLoopExpr>::load,
  PythonBinding<mx::ArrayInitIndexExpr>::load,
  PythonBinding<mx::AddrLabelExpr>::load,
  PythonBinding<mx::AbstractConditionalOperator>::load,
  PythonBinding<mx::ConditionalOperator>::load,
  PythonBinding<mx::BinaryConditionalOperator>::load,
  PythonBinding<mx::VAArgExpr>::load,
  PythonBinding<mx::UnaryOperator>::load,
  PythonBinding<mx::UnaryExprOrTypeTraitExpr>::load,
  PythonBinding<mx::TypoExpr>::load,
  PythonBinding<mx::TypeTraitExpr>::load,
  PythonBinding<mx::SubstNonTypeTemplateParmPackExpr>::load,
  PythonBinding<mx::SubstNonTypeTemplateParmExpr>::load,
  PythonBinding<mx::StringLiteral>::load,
  PythonBinding<mx::StmtExpr>::load,
  PythonBinding<mx::SourceLocExpr>::load,
  PythonBinding<mx::SizeOfPackExpr>::load,
  PythonBinding<mx::ShuffleVectorExpr>::load,
  PythonBinding<mx::SYCLUniqueStableNameExpr>::load,
  PythonBinding<mx::RequiresExpr>::load,
  PythonBinding<mx::RecoveryExpr>::load,
  PythonBinding<mx::PseudoObjectExpr>::load,
  PythonBinding<mx::PredefinedExpr>::load,
  PythonBinding<mx::ParenListExpr>::load,
  PythonBinding<mx::ParenExpr>::load,
  PythonBinding<mx::PackExpansionExpr>::load,
  PythonBinding<mx::OverloadExpr>::load,
  PythonBinding<mx::UnresolvedMemberExpr>::load,
  PythonBinding<mx::UnresolvedLookupExpr>::load,
  PythonBinding<mx::OpaqueValueExpr>::load,
  PythonBinding<mx::OffsetOfExpr>::load,
  PythonBinding<mx::ObjCSubscriptRefExpr>::load,
  PythonBinding<mx::ObjCStringLiteral>::load,
  PythonBinding<mx::ObjCSelectorExpr>::load,
  PythonBinding<mx::ObjCProtocolExpr>::load,
  PythonBinding<mx::ObjCPropertyRefExpr>::load,
  PythonBinding<mx::ObjCMessageExpr>::load,
  PythonBinding<mx::ObjCIvarRefExpr>::load,
  PythonBinding<mx::ObjCIsaExpr>::load,
  PythonBinding<mx::ObjCIndirectCopyRestoreExpr>::load,
  PythonBinding<mx::ObjCEncodeExpr>::load,
  PythonBinding<mx::ObjCDictionaryLiteral>::load,
  PythonBinding<mx::ObjCBoxedExpr>::load,
  PythonBinding<mx::ObjCBoolLiteralExpr>::load,
  PythonBinding<mx::ObjCAvailabilityCheckExpr>::load,
  PythonBinding<mx::ObjCArrayLiteral>::load,
  PythonBinding<mx::OMPIteratorExpr>::load,
  PythonBinding<mx::OMPArrayShapingExpr>::load,
  PythonBinding<mx::OMPArraySectionExpr>::load,
  PythonBinding<mx::NoInitExpr>::load,
  PythonBinding<mx::MemberExpr>::load,
  PythonBinding<mx::MatrixSubscriptExpr>::load,
  PythonBinding<mx::MaterializeTemporaryExpr>::load,
  PythonBinding<mx::MSPropertySubscriptExpr>::load,
  PythonBinding<mx::MSPropertyRefExpr>::load,
  PythonBinding<mx::LambdaExpr>::load,
  PythonBinding<mx::IntegerLiteral>::load,
  PythonBinding<mx::InitListExpr>::load,
  PythonBinding<mx::ImplicitValueInitExpr>::load,
  PythonBinding<mx::ImaginaryLiteral>::load,
  PythonBinding<mx::GenericSelectionExpr>::load,
  PythonBinding<mx::GNUNullExpr>::load,
  PythonBinding<mx::FunctionParmPackExpr>::load,
  PythonBinding<mx::FullExpr>::load,
  PythonBinding<mx::ExprWithCleanups>::load,
  PythonBinding<mx::ConstantExpr>::load,
  PythonBinding<mx::FloatingLiteral>::load,
  PythonBinding<mx::FixedPointLiteral>::load,
  PythonBinding<mx::ExtVectorElementExpr>::load,
  PythonBinding<mx::ExpressionTraitExpr>::load,
  PythonBinding<mx::AttributedStmt>::load,
  PythonBinding<mx::SwitchStmt>::load,
  PythonBinding<mx::SwitchCase>::load,
  PythonBinding<mx::DefaultStmt>::load,
  PythonBinding<mx::CaseStmt>::load,
  PythonBinding<mx::Decl>::load,
  PythonBinding<mx::ClassScopeFunctionSpecializationDecl>::load,
  PythonBinding<mx::CapturedDecl>::load,
  PythonBinding<mx::BlockDecl>::load,
  PythonBinding<mx::AccessSpecDecl>::load,
  PythonBinding<mx::OMPDeclarativeDirectiveDecl>::load,
  PythonBinding<mx::OMPThreadPrivateDecl>::load,
  PythonBinding<mx::OMPRequiresDecl>::load,
  PythonBinding<mx::OMPAllocateDecl>::load,
  PythonBinding<mx::TranslationUnitDecl>::load,
  PythonBinding<mx::TopLevelStmtDecl>::load,
  PythonBinding<mx::StaticAssertDecl>::load,
  PythonBinding<mx::RequiresExprBodyDecl>::load,
  PythonBinding<mx::PragmaDetectMismatchDecl>::load,
  PythonBinding<mx::PragmaCommentDecl>::load,
  PythonBinding<mx::ObjCPropertyImplDecl>::load,
  PythonBinding<mx::NamedDecl>::load,
  PythonBinding<mx::LabelDecl>::load,
  PythonBinding<mx::HLSLBufferDecl>::load,
  PythonBinding<mx::BaseUsingDecl>::load,
  PythonBinding<mx::UsingEnumDecl>::load,
  PythonBinding<mx::UsingDecl>::load,
  PythonBinding<mx::ValueDecl>::load,
  PythonBinding<mx::UnresolvedUsingValueDecl>::load,
  PythonBinding<mx::UnnamedGlobalConstantDecl>::load,
  PythonBinding<mx::TemplateParamObjectDecl>::load,
  PythonBinding<mx::OMPDeclareReductionDecl>::load,
  PythonBinding<mx::MSGuidDecl>::load,
  PythonBinding<mx::IndirectFieldDecl>::load,
  PythonBinding<mx::EnumConstantDecl>::load,
  PythonBinding<mx::DeclaratorDecl>::load,
  PythonBinding<mx::VarDecl>::load,
  PythonBinding<mx::ParmVarDecl>::load,
  PythonBinding<mx::OMPCapturedExprDecl>::load,
  PythonBinding<mx::ImplicitParamDecl>::load,
  PythonBinding<mx::DecompositionDecl>::load,
  PythonBinding<mx::VarTemplateSpecializationDecl>::load,
  PythonBinding<mx::VarTemplatePartialSpecializationDecl>::load,
  PythonBinding<mx::NonTypeTemplateParmDecl>::load,
  PythonBinding<mx::MSPropertyDecl>::load,
  PythonBinding<mx::FunctionDecl>::load,
  PythonBinding<mx::CXXMethodDecl>::load,
  PythonBinding<mx::CXXDestructorDecl>::load,
  PythonBinding<mx::CXXConversionDecl>::load,
  PythonBinding<mx::CXXConstructorDecl>::load,
  PythonBinding<mx::CXXDeductionGuideDecl>::load,
  PythonBinding<mx::FieldDecl>::load,
  PythonBinding<mx::ObjCIvarDecl>::load,
  PythonBinding<mx::ObjCAtDefsFieldDecl>::load,
  PythonBinding<mx::BindingDecl>::load,
  PythonBinding<mx::OMPDeclarativeDirectiveValueDecl>::load,
  PythonBinding<mx::OMPDeclareMapperDecl>::load,
  PythonBinding<mx::UsingShadowDecl>::load,
  PythonBinding<mx::ConstructorUsingShadowDecl>::load,
  PythonBinding<mx::UsingPackDecl>::load,
  PythonBinding<mx::UsingDirectiveDecl>::load,
  PythonBinding<mx::UnresolvedUsingIfExistsDecl>::load,
  PythonBinding<mx::TypeDecl>::load,
  PythonBinding<mx::TemplateTypeParmDecl>::load,
  PythonBinding<mx::TagDecl>::load,
  PythonBinding<mx::RecordDecl>::load,
  PythonBinding<mx::CXXRecordDecl>::load,
  PythonBinding<mx::ClassTemplateSpecializationDecl>::load,
  PythonBinding<mx::ClassTemplatePartialSpecializationDecl>::load,
  PythonBinding<mx::EnumDecl>::load,
  PythonBinding<mx::UnresolvedUsingTypenameDecl>::load,
  PythonBinding<mx::TypedefNameDecl>::load,
  PythonBinding<mx::TypedefDecl>::load,
  PythonBinding<mx::TypeAliasDecl>::load,
  PythonBinding<mx::ObjCTypeParamDecl>::load,
  PythonBinding<mx::TemplateDecl>::load,
  PythonBinding<mx::RedeclarableTemplateDecl>::load,
  PythonBinding<mx::FunctionTemplateDecl>::load,
  PythonBinding<mx::ClassTemplateDecl>::load,
  PythonBinding<mx::VarTemplateDecl>::load,
  PythonBinding<mx::TypeAliasTemplateDecl>::load,
  PythonBinding<mx::ConceptDecl>::load,
  PythonBinding<mx::BuiltinTemplateDecl>::load,
  PythonBinding<mx::TemplateTemplateParmDecl>::load,
  PythonBinding<mx::ObjCPropertyDecl>::load,
  PythonBinding<mx::ObjCMethodDecl>::load,
  PythonBinding<mx::ObjCContainerDecl>::load,
  PythonBinding<mx::ObjCCategoryDecl>::load,
  PythonBinding<mx::ObjCProtocolDecl>::load,
  PythonBinding<mx::ObjCInterfaceDecl>::load,
  PythonBinding<mx::ObjCImplDecl>::load,
  PythonBinding<mx::ObjCCategoryImplDecl>::load,
  PythonBinding<mx::ObjCImplementationDecl>::load,
  PythonBinding<mx::ObjCCompatibleAliasDecl>::load,
  PythonBinding<mx::NamespaceDecl>::load,
  PythonBinding<mx::NamespaceAliasDecl>::load,
  PythonBinding<mx::LinkageSpecDecl>::load,
  PythonBinding<mx::LifetimeExtendedTemporaryDecl>::load,
  PythonBinding<mx::ImportDecl>::load,
  PythonBinding<mx::ImplicitConceptSpecializationDecl>::load,
  PythonBinding<mx::FriendTemplateDecl>::load,
  PythonBinding<mx::FriendDecl>::load,
  PythonBinding<mx::FileScopeAsmDecl>::load,
  PythonBinding<mx::ExternCContextDecl>::load,
  PythonBinding<mx::ExportDecl>::load,
  PythonBinding<mx::EmptyDecl>::load,
};

// multiplier.ir.abi
static PyModuleDef gABIModule = {
  PyModuleDef_HEAD_INIT,
  .m_name = "abi",
  .m_doc = PyDoc_STR("Wrapper of IR/ABI"),
  .m_size = 0,
  .m_methods = gEmptyMethods,
  .m_slots = {},
  .m_traverse = {},
  .m_clear = {},
  .m_free = {},
};

static LoaderFunc * const gABILoaders[] = {
  PythonBinding<mx::ir::abi::CallArgsOp>::load,
  PythonBinding<mx::ir::abi::CallExecutionOp>::load,
  PythonBinding<mx::ir::abi::CallOp>::load,
  PythonBinding<mx::ir::abi::CallRetsOp>::load,
  PythonBinding<mx::ir::abi::DirectOp>::load,
  PythonBinding<mx::ir::abi::EpilogueOp>::load,
  PythonBinding<mx::ir::abi::FuncOp>::load,
  PythonBinding<mx::ir::abi::PrologueOp>::load,
  PythonBinding<mx::ir::abi::RetDirectOp>::load,
  PythonBinding<mx::ir::abi::TodoOp>::load,
  PythonBinding<mx::ir::abi::WrapFuncOp>::load,
  PythonBinding<mx::ir::abi::YieldOp>::load,
};

// multiplier.ir.llvm
static PyModuleDef gLLVMModule = {
  PyModuleDef_HEAD_INIT,
  .m_name = "llvm",
  .m_doc = PyDoc_STR("Wrapper of IR/LLVM"),
  .m_size = 0,
  .m_methods = gEmptyMethods,
  .m_slots = {},
  .m_traverse = {},
  .m_clear = {},
  .m_free = {},
};

static LoaderFunc * const gLLVMLoaders[] = {
  PythonBinding<mx::ir::llvm::DIBasicTypeAttr>::load,
  PythonBinding<mx::ir::llvm::DICompileUnitAttr>::load,
  PythonBinding<mx::ir::llvm::DICompositeTypeAttr>::load,
  PythonBinding<mx::ir::llvm::DIDerivedTypeAttr>::load,
  PythonBinding<mx::ir::llvm::DINamespaceAttr>::load,
  PythonBinding<mx::ir::llvm::MemoryEffectsAttr>::load,
  PythonBinding<mx::ir::llvm::TBAAMemberAttr>::load,
  PythonBinding<mx::ir::llvm::TBAATagAttr>::load,
  PythonBinding<mx::ir::llvm::TBAATypeDescriptorAttr>::load,
  PythonBinding<mx::ir::llvm::FunctionType>::load,
  PythonBinding<mx::ir::llvm::PointerType>::load,
  PythonBinding<mx::ir::llvm::TargetExtType>::load,
  PythonBinding<mx::ir::llvm::AShrOp>::load,
  PythonBinding<mx::ir::llvm::AddOp>::load,
  PythonBinding<mx::ir::llvm::AddrSpaceCastOp>::load,
  PythonBinding<mx::ir::llvm::AddressOfOp>::load,
  PythonBinding<mx::ir::llvm::AllocaOp>::load,
  PythonBinding<mx::ir::llvm::AndOp>::load,
  PythonBinding<mx::ir::llvm::AtomicCmpXchgOp>::load,
  PythonBinding<mx::ir::llvm::AtomicRMWOp>::load,
  PythonBinding<mx::ir::llvm::BitcastOp>::load,
  PythonBinding<mx::ir::llvm::BrOp>::load,
  PythonBinding<mx::ir::llvm::CallOp>::load,
  PythonBinding<mx::ir::llvm::ComdatOp>::load,
  PythonBinding<mx::ir::llvm::ComdatSelectorOp>::load,
  PythonBinding<mx::ir::llvm::CondBrOp>::load,
  PythonBinding<mx::ir::llvm::ConstantOp>::load,
  PythonBinding<mx::ir::llvm::ExtractElementOp>::load,
  PythonBinding<mx::ir::llvm::ExtractValueOp>::load,
  PythonBinding<mx::ir::llvm::FAddOp>::load,
  PythonBinding<mx::ir::llvm::FCmpOp>::load,
  PythonBinding<mx::ir::llvm::FDivOp>::load,
  PythonBinding<mx::ir::llvm::FMulOp>::load,
  PythonBinding<mx::ir::llvm::FNegOp>::load,
  PythonBinding<mx::ir::llvm::FPExtOp>::load,
  PythonBinding<mx::ir::llvm::FPToSIOp>::load,
  PythonBinding<mx::ir::llvm::FPToUIOp>::load,
  PythonBinding<mx::ir::llvm::FPTruncOp>::load,
  PythonBinding<mx::ir::llvm::FRemOp>::load,
  PythonBinding<mx::ir::llvm::FSubOp>::load,
  PythonBinding<mx::ir::llvm::FenceOp>::load,
  PythonBinding<mx::ir::llvm::FreezeOp>::load,
  PythonBinding<mx::ir::llvm::GetElementPtrOp>::load,
  PythonBinding<mx::ir::llvm::GlobalOp>::load,
  PythonBinding<mx::ir::llvm::ICmpOp>::load,
  PythonBinding<mx::ir::llvm::InlineAsmOp>::load,
  PythonBinding<mx::ir::llvm::InsertElementOp>::load,
  PythonBinding<mx::ir::llvm::InsertValueOp>::load,
  PythonBinding<mx::ir::llvm::IntToPtrOp>::load,
  PythonBinding<mx::ir::llvm::InvokeOp>::load,
  PythonBinding<mx::ir::llvm::FuncOp>::load,
  PythonBinding<mx::ir::llvm::LShrOp>::load,
  PythonBinding<mx::ir::llvm::LandingpadOp>::load,
  PythonBinding<mx::ir::llvm::LoadOp>::load,
  PythonBinding<mx::ir::llvm::MetadataOp>::load,
  PythonBinding<mx::ir::llvm::MulOp>::load,
  PythonBinding<mx::ir::llvm::OrOp>::load,
  PythonBinding<mx::ir::llvm::PoisonOp>::load,
  PythonBinding<mx::ir::llvm::PtrToIntOp>::load,
  PythonBinding<mx::ir::llvm::ResumeOp>::load,
  PythonBinding<mx::ir::llvm::ReturnOp>::load,
  PythonBinding<mx::ir::llvm::SDivOp>::load,
  PythonBinding<mx::ir::llvm::SExtOp>::load,
  PythonBinding<mx::ir::llvm::SIToFPOp>::load,
  PythonBinding<mx::ir::llvm::SRemOp>::load,
  PythonBinding<mx::ir::llvm::SelectOp>::load,
  PythonBinding<mx::ir::llvm::ShlOp>::load,
  PythonBinding<mx::ir::llvm::ShuffleVectorOp>::load,
  PythonBinding<mx::ir::llvm::StoreOp>::load,
  PythonBinding<mx::ir::llvm::SubOp>::load,
  PythonBinding<mx::ir::llvm::SwitchOp>::load,
  PythonBinding<mx::ir::llvm::TruncOp>::load,
  PythonBinding<mx::ir::llvm::UDivOp>::load,
  PythonBinding<mx::ir::llvm::UIToFPOp>::load,
  PythonBinding<mx::ir::llvm::URemOp>::load,
  PythonBinding<mx::ir::llvm::UndefOp>::load,
  PythonBinding<mx::ir::llvm::XOrOp>::load,
  PythonBinding<mx::ir::llvm::ZExtOp>::load,
  PythonBinding<mx::ir::llvm::AbsOp>::load,
  PythonBinding<mx::ir::llvm::BitReverseOp>::load,
  PythonBinding<mx::ir::llvm::ByteSwapOp>::load,
  PythonBinding<mx::ir::llvm::CallIntrinsicOp>::load,
  PythonBinding<mx::ir::llvm::CopySignOp>::load,
  PythonBinding<mx::ir::llvm::CoroAlignOp>::load,
  PythonBinding<mx::ir::llvm::CoroBeginOp>::load,
  PythonBinding<mx::ir::llvm::CoroEndOp>::load,
  PythonBinding<mx::ir::llvm::CoroFreeOp>::load,
  PythonBinding<mx::ir::llvm::CoroIdOp>::load,
  PythonBinding<mx::ir::llvm::CoroResumeOp>::load,
  PythonBinding<mx::ir::llvm::CoroSaveOp>::load,
  PythonBinding<mx::ir::llvm::CoroSizeOp>::load,
  PythonBinding<mx::ir::llvm::CoroSuspendOp>::load,
  PythonBinding<mx::ir::llvm::CosOp>::load,
  PythonBinding<mx::ir::llvm::CountLeadingZerosOp>::load,
  PythonBinding<mx::ir::llvm::CountTrailingZerosOp>::load,
  PythonBinding<mx::ir::llvm::CtPopOp>::load,
  PythonBinding<mx::ir::llvm::DbgValueOp>::load,
  PythonBinding<mx::ir::llvm::EhTypeidForOp>::load,
  PythonBinding<mx::ir::llvm::Exp2Op>::load,
  PythonBinding<mx::ir::llvm::ExpOp>::load,
  PythonBinding<mx::ir::llvm::ExpectOp>::load,
  PythonBinding<mx::ir::llvm::ExpectWithProbabilityOp>::load,
  PythonBinding<mx::ir::llvm::FAbsOp>::load,
  PythonBinding<mx::ir::llvm::FCeilOp>::load,
  PythonBinding<mx::ir::llvm::FFloorOp>::load,
  PythonBinding<mx::ir::llvm::FMAOp>::load,
  PythonBinding<mx::ir::llvm::FMulAddOp>::load,
  PythonBinding<mx::ir::llvm::FTruncOp>::load,
  PythonBinding<mx::ir::llvm::FShlOp>::load,
  PythonBinding<mx::ir::llvm::FShrOp>::load,
  PythonBinding<mx::ir::llvm::GetActiveLaneMaskOp>::load,
  PythonBinding<mx::ir::llvm::IsConstantOp>::load,
  PythonBinding<mx::ir::llvm::IsFPClassOp>::load,
  PythonBinding<mx::ir::llvm::LifetimeEndOp>::load,
  PythonBinding<mx::ir::llvm::LifetimeStartOp>::load,
  PythonBinding<mx::ir::llvm::RoundAndCastToLongLongOp>::load,
  PythonBinding<mx::ir::llvm::RoundAndCastToNearestLongLongOp>::load,
  PythonBinding<mx::ir::llvm::Log10Op>::load,
  PythonBinding<mx::ir::llvm::Log2Op>::load,
  PythonBinding<mx::ir::llvm::LogOp>::load,
  PythonBinding<mx::ir::llvm::RoundAndCastToLongOp>::load,
  PythonBinding<mx::ir::llvm::RoundAndCastToNearestLongOp>::load,
  PythonBinding<mx::ir::llvm::MaskedLoadOp>::load,
  PythonBinding<mx::ir::llvm::MaskedStoreOp>::load,
  PythonBinding<mx::ir::llvm::MatrixColumnMajorLoadOp>::load,
  PythonBinding<mx::ir::llvm::MatrixColumnMajorStoreOp>::load,
  PythonBinding<mx::ir::llvm::MatrixMultiplyOp>::load,
  PythonBinding<mx::ir::llvm::MatrixTransposeOp>::load,
  PythonBinding<mx::ir::llvm::MaxNumOp>::load,
  PythonBinding<mx::ir::llvm::MaximumOp>::load,
  PythonBinding<mx::ir::llvm::MemcpyInlineOp>::load,
  PythonBinding<mx::ir::llvm::MemcpyOp>::load,
  PythonBinding<mx::ir::llvm::MemmoveOp>::load,
  PythonBinding<mx::ir::llvm::MemsetOp>::load,
  PythonBinding<mx::ir::llvm::MinNumOp>::load,
  PythonBinding<mx::ir::llvm::MinimumOp>::load,
  PythonBinding<mx::ir::llvm::RoundToNearbyIntOp>::load,
  PythonBinding<mx::ir::llvm::PowIOp>::load,
  PythonBinding<mx::ir::llvm::FPowOp>::load,
  PythonBinding<mx::ir::llvm::PrefetchOp>::load,
  PythonBinding<mx::ir::llvm::RoundToIntOp>::load,
  PythonBinding<mx::ir::llvm::RoundToNearestEvenOp>::load,
  PythonBinding<mx::ir::llvm::RoundToNearestOp>::load,
  PythonBinding<mx::ir::llvm::SAddSatOp>::load,
  PythonBinding<mx::ir::llvm::SAddWithOverflowOp>::load,
  PythonBinding<mx::ir::llvm::SMaxOp>::load,
  PythonBinding<mx::ir::llvm::SMinOp>::load,
  PythonBinding<mx::ir::llvm::SMulWithOverflowOp>::load,
  PythonBinding<mx::ir::llvm::SSACopyOp>::load,
  PythonBinding<mx::ir::llvm::SShlSatOp>::load,
  PythonBinding<mx::ir::llvm::SSubSatOp>::load,
  PythonBinding<mx::ir::llvm::SSubWithOverflowOp>::load,
  PythonBinding<mx::ir::llvm::SinOp>::load,
  PythonBinding<mx::ir::llvm::SqrtOp>::load,
  PythonBinding<mx::ir::llvm::StackRestoreOp>::load,
  PythonBinding<mx::ir::llvm::StackSaveOp>::load,
  PythonBinding<mx::ir::llvm::StepVectorOp>::load,
  PythonBinding<mx::ir::llvm::ThreadLocalAddressOp>::load,
  PythonBinding<mx::ir::llvm::UAddSatOp>::load,
  PythonBinding<mx::ir::llvm::UAddWithOverflowOp>::load,
  PythonBinding<mx::ir::llvm::UBSanTrapOp>::load,
  PythonBinding<mx::ir::llvm::UMaxOp>::load,
  PythonBinding<mx::ir::llvm::UMinOp>::load,
  PythonBinding<mx::ir::llvm::UMulWithOverflowOp>::load,
  PythonBinding<mx::ir::llvm::UShlSatOp>::load,
  PythonBinding<mx::ir::llvm::USubSatOp>::load,
  PythonBinding<mx::ir::llvm::USubWithOverflowOp>::load,
  PythonBinding<mx::ir::llvm::VPAShrOp>::load,
  PythonBinding<mx::ir::llvm::VPAddOp>::load,
  PythonBinding<mx::ir::llvm::VPAndOp>::load,
  PythonBinding<mx::ir::llvm::VPFAddOp>::load,
  PythonBinding<mx::ir::llvm::VPFDivOp>::load,
  PythonBinding<mx::ir::llvm::VPFMulAddOp>::load,
  PythonBinding<mx::ir::llvm::VPFMulOp>::load,
  PythonBinding<mx::ir::llvm::VPFNegOp>::load,
  PythonBinding<mx::ir::llvm::VPFPExtOp>::load,
  PythonBinding<mx::ir::llvm::VPFPToSIOp>::load,
  PythonBinding<mx::ir::llvm::VPFPToUIOp>::load,
  PythonBinding<mx::ir::llvm::VPFPTruncOp>::load,
  PythonBinding<mx::ir::llvm::VPFRemOp>::load,
  PythonBinding<mx::ir::llvm::VPFSubOp>::load,
  PythonBinding<mx::ir::llvm::VPFmaOp>::load,
  PythonBinding<mx::ir::llvm::VPIntToPtrOp>::load,
  PythonBinding<mx::ir::llvm::VPLShrOp>::load,
  PythonBinding<mx::ir::llvm::VPLoadOp>::load,
  PythonBinding<mx::ir::llvm::VPMergeMinOp>::load,
  PythonBinding<mx::ir::llvm::VPMulOp>::load,
  PythonBinding<mx::ir::llvm::VPOrOp>::load,
  PythonBinding<mx::ir::llvm::VPPtrToIntOp>::load,
  PythonBinding<mx::ir::llvm::VPReduceAddOp>::load,
  PythonBinding<mx::ir::llvm::VPReduceAndOp>::load,
  PythonBinding<mx::ir::llvm::VPReduceFAddOp>::load,
  PythonBinding<mx::ir::llvm::VPReduceFMaxOp>::load,
  PythonBinding<mx::ir::llvm::VPReduceFMinOp>::load,
  PythonBinding<mx::ir::llvm::VPReduceFMulOp>::load,
  PythonBinding<mx::ir::llvm::VPReduceMulOp>::load,
  PythonBinding<mx::ir::llvm::VPReduceOrOp>::load,
  PythonBinding<mx::ir::llvm::VPReduceSMaxOp>::load,
  PythonBinding<mx::ir::llvm::VPReduceSMinOp>::load,
  PythonBinding<mx::ir::llvm::VPReduceUMaxOp>::load,
  PythonBinding<mx::ir::llvm::VPReduceUMinOp>::load,
  PythonBinding<mx::ir::llvm::VPReduceXorOp>::load,
  PythonBinding<mx::ir::llvm::VPSDivOp>::load,
  PythonBinding<mx::ir::llvm::VPSExtOp>::load,
  PythonBinding<mx::ir::llvm::VPSIToFPOp>::load,
  PythonBinding<mx::ir::llvm::VPSRemOp>::load,
  PythonBinding<mx::ir::llvm::VPSelectMinOp>::load,
  PythonBinding<mx::ir::llvm::VPShlOp>::load,
  PythonBinding<mx::ir::llvm::VPStoreOp>::load,
  PythonBinding<mx::ir::llvm::VPStridedLoadOp>::load,
  PythonBinding<mx::ir::llvm::VPStridedStoreOp>::load,
  PythonBinding<mx::ir::llvm::VPSubOp>::load,
  PythonBinding<mx::ir::llvm::VPTruncOp>::load,
  PythonBinding<mx::ir::llvm::VPUDivOp>::load,
  PythonBinding<mx::ir::llvm::VPUIToFPOp>::load,
  PythonBinding<mx::ir::llvm::VPURemOp>::load,
  PythonBinding<mx::ir::llvm::VPXorOp>::load,
  PythonBinding<mx::ir::llvm::VPZExtOp>::load,
  PythonBinding<mx::ir::llvm::VaCopyOp>::load,
  PythonBinding<mx::ir::llvm::VaEndOp>::load,
  PythonBinding<mx::ir::llvm::VaStartOp>::load,
  PythonBinding<mx::ir::llvm::MaskedExpandLoadOp>::load,
  PythonBinding<mx::ir::llvm::MaskedGatherOp>::load,
  PythonBinding<mx::ir::llvm::MaskedScatterOp>::load,
  PythonBinding<mx::ir::llvm::VectorExtractOp>::load,
  PythonBinding<mx::ir::llvm::VectorInsertOp>::load,
  PythonBinding<mx::ir::llvm::VectorReduceAddOp>::load,
  PythonBinding<mx::ir::llvm::VectorReduceAndOp>::load,
  PythonBinding<mx::ir::llvm::VectorReduceFAddOp>::load,
  PythonBinding<mx::ir::llvm::VectorReduceFMaxOp>::load,
  PythonBinding<mx::ir::llvm::VectorReduceFMaximumOp>::load,
  PythonBinding<mx::ir::llvm::VectorReduceFMinOp>::load,
  PythonBinding<mx::ir::llvm::VectorReduceFMinimumOp>::load,
  PythonBinding<mx::ir::llvm::VectorReduceFMulOp>::load,
  PythonBinding<mx::ir::llvm::VectorReduceMulOp>::load,
  PythonBinding<mx::ir::llvm::VectorReduceOrOp>::load,
  PythonBinding<mx::ir::llvm::VectorReduceSMaxOp>::load,
  PythonBinding<mx::ir::llvm::VectorReduceSMinOp>::load,
  PythonBinding<mx::ir::llvm::VectorReduceUMaxOp>::load,
  PythonBinding<mx::ir::llvm::VectorReduceUMinOp>::load,
  PythonBinding<mx::ir::llvm::VectorReduceXorOp>::load,
  PythonBinding<mx::ir::llvm::VScaleOp>::load,
};

// multiplier.ir.core
static PyModuleDef gCoreModule = {
  PyModuleDef_HEAD_INIT,
  .m_name = "core",
  .m_doc = PyDoc_STR("Wrapper of IR/Core"),
  .m_size = 0,
  .m_methods = gEmptyMethods,
  .m_slots = {},
  .m_traverse = {},
  .m_clear = {},
  .m_free = {},
};

static LoaderFunc * const gCoreLoaders[] = {
  PythonBinding<mx::ir::core::BooleanAttr>::load,
  PythonBinding<mx::ir::core::StringLiteralAttr>::load,
  PythonBinding<mx::ir::core::FunctionType>::load,
  PythonBinding<mx::ir::core::BinLAndOp>::load,
  PythonBinding<mx::ir::core::BinLOrOp>::load,
  PythonBinding<mx::ir::core::ImplicitReturnOp>::load,
  PythonBinding<mx::ir::core::LazyOp>::load,
  PythonBinding<mx::ir::core::ScopeOp>::load,
  PythonBinding<mx::ir::core::SelectOp>::load,
};

// multiplier.frontend
static PyModuleDef gFrontendModule = {
  PyModuleDef_HEAD_INIT,
  .m_name = "frontend",
  .m_doc = PyDoc_STR("Wrapper of Frontend"),
  .m_size = 0,
  .m_methods = gEmptyMethods,
  .m_slots = {},
  .m_traverse = {},
  .m_clear = {},
  .m_free = {},
};

static LoaderFunc * const gFrontendLoaders[] = {
  PythonBinding<mx::TokenContext>::load,
  PythonBinding<mx::Compilation>::load,
  PythonBinding<mx::Token>::load,
  PythonBinding<mx::TokenRange>::load,
  PythonBinding<mx::File>::load,
  PythonBinding<mx::TokenTreeVisitor>::load,
  PythonBinding<mx::TokenTree>::load,
  PythonBinding<mx::TokenKind>::load,
  PythonBinding<mx::MacroKind>::load,
  PythonBinding<mx::PathKind>::load,
  PythonBinding<mx::FileType>::load,
  PythonBinding<mx::CompilerName>::load,
  PythonBinding<mx::IncludePathLocation>::load,
  PythonBinding<mx::TargetLanguage>::load,
  PythonBinding<mx::TokenCategory>::load,
  PythonBinding<mx::Macro>::load,
  PythonBinding<mx::MacroVAOptArgument>::load,
  PythonBinding<mx::MacroVAOpt>::load,
  PythonBinding<mx::MacroSubstitution>::load,
  PythonBinding<mx::MacroConcatenate>::load,
  PythonBinding<mx::MacroStringify>::load,
  PythonBinding<mx::MacroExpansion>::load,
  PythonBinding<mx::MacroParameterSubstitution>::load,
  PythonBinding<mx::MacroArgument>::load,
  PythonBinding<mx::MacroParameter>::load,
  PythonBinding<mx::MacroDirective>::load,
  PythonBinding<mx::DefineMacroDirective>::load,
  PythonBinding<mx::PragmaMacroDirective>::load,
  PythonBinding<mx::UndefineMacroDirective>::load,
  PythonBinding<mx::OtherMacroDirective>::load,
  PythonBinding<mx::ConditionalMacroDirective>::load,
  PythonBinding<mx::EndIfMacroDirective>::load,
  PythonBinding<mx::ElseMacroDirective>::load,
  PythonBinding<mx::ElseIfNotDefinedMacroDirective>::load,
  PythonBinding<mx::ElseIfDefinedMacroDirective>::load,
  PythonBinding<mx::ElseIfMacroDirective>::load,
  PythonBinding<mx::IfNotDefinedMacroDirective>::load,
  PythonBinding<mx::IfDefinedMacroDirective>::load,
  PythonBinding<mx::IfMacroDirective>::load,
  PythonBinding<mx::IncludeLikeMacroDirective>::load,
  PythonBinding<mx::ImportMacroDirective>::load,
  PythonBinding<mx::IncludeMacrosMacroDirective>::load,
  PythonBinding<mx::IncludeNextMacroDirective>::load,
  PythonBinding<mx::IncludeMacroDirective>::load,
};

// multiplier.ir.memref
static PyModuleDef gMemRefModule = {
  PyModuleDef_HEAD_INIT,
  .m_name = "memref",
  .m_doc = PyDoc_STR("Wrapper of IR/MemRef"),
  .m_size = 0,
  .m_methods = gEmptyMethods,
  .m_slots = {},
  .m_traverse = {},
  .m_clear = {},
  .m_free = {},
};

static LoaderFunc * const gMemRefLoaders[] = {
  PythonBinding<mx::ir::memref::AssumeAlignmentOp>::load,
  PythonBinding<mx::ir::memref::AtomicRMWOp>::load,
  PythonBinding<mx::ir::memref::AtomicYieldOp>::load,
  PythonBinding<mx::ir::memref::GenericAtomicRMWOp>::load,
  PythonBinding<mx::ir::memref::LoadOp>::load,
  PythonBinding<mx::ir::memref::AllocOp>::load,
  PythonBinding<mx::ir::memref::AllocaOp>::load,
  PythonBinding<mx::ir::memref::AllocaScopeOp>::load,
  PythonBinding<mx::ir::memref::AllocaScopeReturnOp>::load,
  PythonBinding<mx::ir::memref::DimOp>::load,
  PythonBinding<mx::ir::memref::DMAStartOp>::load,
  PythonBinding<mx::ir::memref::DMAWaitOp>::load,
  PythonBinding<mx::ir::memref::ExtractStridedMetadataOp>::load,
  PythonBinding<mx::ir::memref::GetGlobalOp>::load,
  PythonBinding<mx::ir::memref::GlobalOp>::load,
  PythonBinding<mx::ir::memref::PrefetchOp>::load,
  PythonBinding<mx::ir::memref::ReinterpretCastOp>::load,
  PythonBinding<mx::ir::memref::StoreOp>::load,
  PythonBinding<mx::ir::memref::ViewOp>::load,
  PythonBinding<mx::ir::memref::SubViewOp>::load,
};

// multiplier.ir.builtin
static PyModuleDef gBuiltinModule = {
  PyModuleDef_HEAD_INIT,
  .m_name = "builtin",
  .m_doc = PyDoc_STR("Wrapper of IR/Builtin"),
  .m_size = 0,
  .m_methods = gEmptyMethods,
  .m_slots = {},
  .m_traverse = {},
  .m_clear = {},
  .m_free = {},
};

static LoaderFunc * const gBuiltinLoaders[] = {
  PythonBinding<mx::ir::builtin::ElementsAttr>::load,
  PythonBinding<mx::ir::builtin::ArrayAttr>::load,
  PythonBinding<mx::ir::builtin::DenseArrayAttr>::load,
  PythonBinding<mx::ir::builtin::DictionaryAttr>::load,
  PythonBinding<mx::ir::builtin::FloatAttr>::load,
  PythonBinding<mx::ir::builtin::IntegerAttr>::load,
  PythonBinding<mx::ir::builtin::OpaqueAttr>::load,
  PythonBinding<mx::ir::builtin::StringAttr>::load,
  PythonBinding<mx::ir::builtin::StridedLayoutAttr>::load,
  PythonBinding<mx::ir::builtin::BoolAttr>::load,
  PythonBinding<mx::ir::builtin::ShapedType>::load,
  PythonBinding<mx::ir::builtin::IntegerType>::load,
  PythonBinding<mx::ir::builtin::OpaqueType>::load,
  PythonBinding<mx::ir::builtin::VectorType>::load,
  PythonBinding<mx::ir::builtin::ModuleOp>::load,
  PythonBinding<mx::ir::builtin::UnrealizedConversionCastOp>::load,
};

// multiplier.ir.lowlevel
static PyModuleDef gLowLevelModule = {
  PyModuleDef_HEAD_INIT,
  .m_name = "lowlevel",
  .m_doc = PyDoc_STR("Wrapper of IR/LowLevel"),
  .m_size = 0,
  .m_methods = gEmptyMethods,
  .m_slots = {},
  .m_traverse = {},
  .m_clear = {},
  .m_free = {},
};

static LoaderFunc * const gLowLevelLoaders[] = {
  PythonBinding<mx::ir::ll::BrOp>::load,
  PythonBinding<mx::ir::ll::ConcatOp>::load,
  PythonBinding<mx::ir::ll::CondBrOp>::load,
  PythonBinding<mx::ir::ll::CondScopeRetOp>::load,
  PythonBinding<mx::ir::ll::ExtractOp>::load,
  PythonBinding<mx::ir::ll::InitializeVarOp>::load,
  PythonBinding<mx::ir::ll::InlineScopeOp>::load,
  PythonBinding<mx::ir::ll::FuncOp>::load,
  PythonBinding<mx::ir::ll::StructGEPOp>::load,
  PythonBinding<mx::ir::ll::ReturnOp>::load,
  PythonBinding<mx::ir::ll::ScopeOp>::load,
  PythonBinding<mx::ir::ll::UninitializedVarOp>::load,
};

// multiplier.ir.highlevel
static PyModuleDef gHighLevelModule = {
  PyModuleDef_HEAD_INIT,
  .m_name = "highlevel",
  .m_doc = PyDoc_STR("Wrapper of IR/HighLevel"),
  .m_size = 0,
  .m_methods = gEmptyMethods,
  .m_slots = {},
  .m_traverse = {},
  .m_clear = {},
  .m_free = {},
};

static LoaderFunc * const gHighLevelLoaders[] = {
  PythonBinding<mx::ir::hl::AllocAlignAttr>::load,
  PythonBinding<mx::ir::hl::AllocSizeAttr>::load,
  PythonBinding<mx::ir::hl::AsmLabelAttr>::load,
  PythonBinding<mx::ir::hl::CVQualifiersAttr>::load,
  PythonBinding<mx::ir::hl::CVRQualifiersAttr>::load,
  PythonBinding<mx::ir::hl::UCVQualifiersAttr>::load,
  PythonBinding<mx::ir::hl::EnumType>::load,
  PythonBinding<mx::ir::hl::RecordType>::load,
  PythonBinding<mx::ir::hl::TypeOfExprType>::load,
  PythonBinding<mx::ir::hl::TypedefType>::load,
  PythonBinding<mx::ir::hl::AddFAssignOp>::load,
  PythonBinding<mx::ir::hl::AddFOp>::load,
  PythonBinding<mx::ir::hl::AddIAssignOp>::load,
  PythonBinding<mx::ir::hl::AddIOp>::load,
  PythonBinding<mx::ir::hl::AddrLabelExprOp>::load,
  PythonBinding<mx::ir::hl::AddressOfOp>::load,
  PythonBinding<mx::ir::hl::AlignOfExprOp>::load,
  PythonBinding<mx::ir::hl::AlignOfTypeOp>::load,
  PythonBinding<mx::ir::hl::AssignOp>::load,
  PythonBinding<mx::ir::hl::BinAShrAssignOp>::load,
  PythonBinding<mx::ir::hl::BinAShrOp>::load,
  PythonBinding<mx::ir::hl::BinAndAssignOp>::load,
  PythonBinding<mx::ir::hl::BinAndOp>::load,
  PythonBinding<mx::ir::hl::BinCommaOp>::load,
  PythonBinding<mx::ir::hl::BinLAndOp>::load,
  PythonBinding<mx::ir::hl::BinLOrOp>::load,
  PythonBinding<mx::ir::hl::BinLShrAssignOp>::load,
  PythonBinding<mx::ir::hl::BinLShrOp>::load,
  PythonBinding<mx::ir::hl::BinOrAssignOp>::load,
  PythonBinding<mx::ir::hl::BinOrOp>::load,
  PythonBinding<mx::ir::hl::BinShlAssignOp>::load,
  PythonBinding<mx::ir::hl::BinShlOp>::load,
  PythonBinding<mx::ir::hl::BinXorAssignOp>::load,
  PythonBinding<mx::ir::hl::BinXorOp>::load,
  PythonBinding<mx::ir::hl::BuiltinBitCastOp>::load,
  PythonBinding<mx::ir::hl::CStyleCastOp>::load,
  PythonBinding<mx::ir::hl::CallOp>::load,
  PythonBinding<mx::ir::hl::ClassDeclOp>::load,
  PythonBinding<mx::ir::hl::CmpOp>::load,
  PythonBinding<mx::ir::hl::ConstantOp>::load,
  PythonBinding<mx::ir::hl::CxxBaseSpecifierOp>::load,
  PythonBinding<mx::ir::hl::CxxStructDeclOp>::load,
  PythonBinding<mx::ir::hl::DeclRefOp>::load,
  PythonBinding<mx::ir::hl::DerefOp>::load,
  PythonBinding<mx::ir::hl::DivFAssignOp>::load,
  PythonBinding<mx::ir::hl::DivFOp>::load,
  PythonBinding<mx::ir::hl::DivSAssignOp>::load,
  PythonBinding<mx::ir::hl::DivSOp>::load,
  PythonBinding<mx::ir::hl::DivUAssignOp>::load,
  PythonBinding<mx::ir::hl::DivUOp>::load,
  PythonBinding<mx::ir::hl::EnumConstantOp>::load,
  PythonBinding<mx::ir::hl::EnumDeclOp>::load,
  PythonBinding<mx::ir::hl::EnumRefOp>::load,
  PythonBinding<mx::ir::hl::ExprOp>::load,
  PythonBinding<mx::ir::hl::ExtensionOp>::load,
  PythonBinding<mx::ir::hl::FCmpOp>::load,
  PythonBinding<mx::ir::hl::FieldDeclOp>::load,
  PythonBinding<mx::ir::hl::FuncRefOp>::load,
  PythonBinding<mx::ir::hl::GlobalRefOp>::load,
  PythonBinding<mx::ir::hl::CaseOp>::load,
  PythonBinding<mx::ir::hl::CondOp>::load,
  PythonBinding<mx::ir::hl::CondYieldOp>::load,
  PythonBinding<mx::ir::hl::DefaultOp>::load,
  PythonBinding<mx::ir::hl::DoOp>::load,
  PythonBinding<mx::ir::hl::ForOp>::load,
  PythonBinding<mx::ir::hl::FuncOp>::load,
  PythonBinding<mx::ir::hl::IfOp>::load,
  PythonBinding<mx::ir::hl::LabelDeclOp>::load,
  PythonBinding<mx::ir::hl::LabelStmtOp>::load,
  PythonBinding<mx::ir::hl::SwitchOp>::load,
  PythonBinding<mx::ir::hl::TypeYieldOp>::load,
  PythonBinding<mx::ir::hl::ValueYieldOp>::load,
  PythonBinding<mx::ir::hl::VarDeclOp>::load,
  PythonBinding<mx::ir::hl::WhileOp>::load,
  PythonBinding<mx::ir::hl::ImplicitCastOp>::load,
  PythonBinding<mx::ir::hl::IndirectCallOp>::load,
  PythonBinding<mx::ir::hl::InitListExprOp>::load,
  PythonBinding<mx::ir::hl::LNotOp>::load,
  PythonBinding<mx::ir::hl::MinusOp>::load,
  PythonBinding<mx::ir::hl::MulFAssignOp>::load,
  PythonBinding<mx::ir::hl::MulFOp>::load,
  PythonBinding<mx::ir::hl::MulIAssignOp>::load,
  PythonBinding<mx::ir::hl::MulIOp>::load,
  PythonBinding<mx::ir::hl::NotOp>::load,
  PythonBinding<mx::ir::hl::PlusOp>::load,
  PythonBinding<mx::ir::hl::PostDecOp>::load,
  PythonBinding<mx::ir::hl::PostIncOp>::load,
  PythonBinding<mx::ir::hl::PreDecOp>::load,
  PythonBinding<mx::ir::hl::PreIncOp>::load,
  PythonBinding<mx::ir::hl::PredefinedExprOp>::load,
  PythonBinding<mx::ir::hl::RecordMemberOp>::load,
  PythonBinding<mx::ir::hl::RemFAssignOp>::load,
  PythonBinding<mx::ir::hl::RemFOp>::load,
  PythonBinding<mx::ir::hl::RemSAssignOp>::load,
  PythonBinding<mx::ir::hl::RemSOp>::load,
  PythonBinding<mx::ir::hl::RemUAssignOp>::load,
  PythonBinding<mx::ir::hl::RemUOp>::load,
  PythonBinding<mx::ir::hl::ReturnOp>::load,
  PythonBinding<mx::ir::hl::SizeOfExprOp>::load,
  PythonBinding<mx::ir::hl::SizeOfTypeOp>::load,
  PythonBinding<mx::ir::hl::StmtExprOp>::load,
  PythonBinding<mx::ir::hl::StructDeclOp>::load,
  PythonBinding<mx::ir::hl::SubFAssignOp>::load,
  PythonBinding<mx::ir::hl::SubFOp>::load,
  PythonBinding<mx::ir::hl::SubIAssignOp>::load,
  PythonBinding<mx::ir::hl::SubIOp>::load,
  PythonBinding<mx::ir::hl::SubscriptOp>::load,
  PythonBinding<mx::ir::hl::ThisOp>::load,
  PythonBinding<mx::ir::hl::TranslationUnitOp>::load,
  PythonBinding<mx::ir::hl::TypeDeclOp>::load,
  PythonBinding<mx::ir::hl::TypeDefOp>::load,
  PythonBinding<mx::ir::hl::TypeOfExprOp>::load,
  PythonBinding<mx::ir::hl::UnionDeclOp>::load,
};

// multiplier.ir.unsupported
static PyModuleDef gUnsupportedModule = {
  PyModuleDef_HEAD_INIT,
  .m_name = "unsupported",
  .m_doc = PyDoc_STR("Wrapper of IR/Unsupported"),
  .m_size = 0,
  .m_methods = gEmptyMethods,
  .m_slots = {},
  .m_traverse = {},
  .m_clear = {},
  .m_free = {},
};

static LoaderFunc * const gUnsupportedLoaders[] = {
  PythonBinding<mx::ir::unsup::UnsupportedType>::load,
  PythonBinding<mx::ir::unsup::UnsupportedDeclOp>::load,
  PythonBinding<mx::ir::unsup::UnsupportedStmtOp>::load,
};

}  // namespace
}  // namespace mx

PyMODINIT_FUNC PyInit_multiplier(void) {
  auto m = PyModule_Create(&mx::gModule);
  if (!m) {
    return nullptr;
  }

  for (auto loader : mx::gLoaders) {
    if (!loader(m)) {
      Py_DECREF(m);
      return nullptr;
    }
  }

  return m;
}
