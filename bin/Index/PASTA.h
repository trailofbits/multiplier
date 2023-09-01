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
enum class TokenRole : uint8_t;
enum class DeclKind : uint32_t;
enum class AttrKind : uint32_t;
enum class AArch64SVEPcsAttrSpelling : uint32_t;
enum class AArch64VectorPcsAttrSpelling : uint32_t;
enum class AMDGPUFlatWorkGroupSizeAttrSpelling : uint32_t;
enum class AMDGPUKernelCallAttrSpelling : uint32_t;
enum class AMDGPUNumSGPRAttrSpelling : uint32_t;
enum class AMDGPUNumVGPRAttrSpelling : uint32_t;
enum class AMDGPUWavesPerEUAttrSpelling : uint32_t;
enum class ARMInterruptAttrInterruptType : uint32_t;
enum class ARMInterruptAttrSpelling : uint32_t;
enum class AVRInterruptAttrSpelling : uint32_t;
enum class AVRSignalAttrSpelling : uint32_t;
enum class AbiTagAttrSpelling : uint32_t;
enum class AcquireCapabilityAttrSpelling : uint32_t;
enum class AcquireHandleAttrSpelling : uint32_t;
enum class AddressSpaceAttrSpelling : uint32_t;
enum class AliasAttrSpelling : uint32_t;
enum class AlignedAttrSpelling : uint32_t;
enum class AllocAlignAttrSpelling : uint32_t;
enum class AllocSizeAttrSpelling : uint32_t;
enum class AlwaysDestroyAttrSpelling : uint32_t;
enum class AlwaysInlineAttrSpelling : uint32_t;
enum class AnnotateAttrSpelling : uint32_t;
enum class AnnotateTypeAttrSpelling : uint32_t;
enum class AnyX86InterruptAttrSpelling : uint32_t;
enum class AnyX86NoCallerSavedRegistersAttrSpelling : uint32_t;
enum class AnyX86NoCfCheckAttrSpelling : uint32_t;
enum class ArcWeakrefUnavailableAttrSpelling : uint32_t;
enum class ArgumentWithTypeTagAttrSpelling : uint32_t;
enum class ArmBuiltinAliasAttrSpelling : uint32_t;
enum class ArmMveStrictPolymorphismAttrSpelling : uint32_t;
enum class ArrayTypeArraySizeModifier : uint32_t;
enum class ArtificialAttrSpelling : uint32_t;
enum class AsmLabelAttrSpelling : uint32_t;
enum class AssertCapabilityAttrSpelling : uint32_t;
enum class AssumeAlignedAttrSpelling : uint32_t;
enum class AssumptionAttrSpelling : uint32_t;
enum class AtomicExprAtomicOp : uint32_t;
enum class AvailabilityAttrSpelling : uint32_t;
enum class BPFPreserveAccessIndexAttrSpelling : uint32_t;
enum class BTFDeclTagAttrSpelling : uint32_t;
enum class BTFTypeTagAttrSpelling : uint32_t;
enum class BlocksAttrBlockType : uint32_t;
enum class BlocksAttrSpelling : uint32_t;
enum class BuiltinAliasAttrSpelling : uint32_t;
enum class BuiltinTypeKind : uint32_t;
enum class CDeclAttrSpelling : uint32_t;
enum class CFAuditedTransferAttrSpelling : uint32_t;
enum class CFConsumedAttrSpelling : uint32_t;
enum class CFGuardAttrGuardArg : uint32_t;
enum class CFGuardAttrSpelling : uint32_t;
enum class CFICanonicalJumpTableAttrSpelling : uint32_t;
enum class CFReturnsNotRetainedAttrSpelling : uint32_t;
enum class CFReturnsRetainedAttrSpelling : uint32_t;
enum class CFUnknownTransferAttrSpelling : uint32_t;
enum class CPUDispatchAttrSpelling : uint32_t;
enum class CPUSpecificAttrSpelling : uint32_t;
enum class CUDAConstantAttrSpelling : uint32_t;
enum class CUDADeviceAttrSpelling : uint32_t;
enum class CUDADeviceBuiltinSurfaceTypeAttrSpelling : uint32_t;
enum class CUDADeviceBuiltinTextureTypeAttrSpelling : uint32_t;
enum class CUDAGlobalAttrSpelling : uint32_t;
enum class CUDAHostAttrSpelling : uint32_t;
enum class CUDALaunchBoundsAttrSpelling : uint32_t;
enum class CUDASharedAttrSpelling : uint32_t;
enum class CXX11NoReturnAttrSpelling : uint32_t;
enum class CXXConstructExprConstructionKind : uint32_t;
enum class CXXNewExprInitializationStyle : uint32_t;
enum class CXXRecordDeclLambdaDependencyKind : uint32_t;
enum class CallExprADLCallKind : bool;
enum class CallableWhenAttrConsumedState : uint32_t;
enum class CallableWhenAttrSpelling : uint32_t;
enum class CallbackAttrSpelling : uint32_t;
enum class CalledOnceAttrSpelling : uint32_t;
enum class CapabilityAttrSpelling : uint32_t;
enum class CapturedStmtVariableCaptureKind : uint32_t;
enum class CarriesDependencyAttrSpelling : uint32_t;
enum class CharacterLiteralCharacterKind : uint32_t;
enum class CleanupAttrSpelling : uint32_t;
enum class ColdAttrSpelling : uint32_t;
enum class CommonAttrSpelling : uint32_t;
enum class ConstAttrSpelling : uint32_t;
enum class ConstInitAttrSpelling : uint32_t;
enum class ConstantExprResultStorageKind : uint32_t;
enum class ConstructorAttrSpelling : uint32_t;
enum class ConsumableAttrConsumedState : uint32_t;
enum class ConsumableAttrSpelling : uint32_t;
enum class ConsumableAutoCastAttrSpelling : uint32_t;
enum class ConsumableSetOnReadAttrSpelling : uint32_t;
enum class ConvergentAttrSpelling : uint32_t;
enum class DLLExportAttrSpelling : uint32_t;
enum class DLLImportAttrSpelling : uint32_t;
enum class DeclFriendObjectKind : uint32_t;
enum class DeclIdentifierNamespace : uint32_t;
enum class DeclModuleOwnershipKind : uint32_t;
enum class DeclObjCDeclQualifier : uint32_t;
enum class DeprecatedAttrSpelling : uint32_t;
enum class DestructorAttrSpelling : uint32_t;
enum class DiagnoseAsBuiltinAttrSpelling : uint32_t;
enum class DiagnoseIfAttrDiagnosticType : uint32_t;
enum class DisableSanitizerInstrumentationAttrSpelling : uint32_t;
enum class DisableTailCallsAttrSpelling : uint32_t;
enum class EnforceTCBAttrSpelling : uint32_t;
enum class EnforceTCBLeafAttrSpelling : uint32_t;
enum class EnumExtensibilityAttrKind : uint32_t;
enum class EnumExtensibilityAttrSpelling : uint32_t;
enum class ErrorAttrSpelling : uint32_t;
enum class ExcludeFromExplicitInstantiationAttrSpelling : uint32_t;
enum class ExprConstantExprKind : int32_t;
enum class ExprLValueClassification : uint32_t;
enum class ExprNullPointerConstantKind : uint32_t;
enum class ExprNullPointerConstantValueDependence : uint32_t;
enum class ExprSideEffectsKind : uint32_t;
enum class ExprisModifiableLvalueResult : uint32_t;
enum class ExternalSourceSymbolAttrSpelling : uint32_t;
enum class FallThroughAttrSpelling : uint32_t;
enum class FastCallAttrSpelling : uint32_t;
enum class FinalAttrSpelling : uint32_t;
enum class FlagEnumAttrSpelling : uint32_t;
enum class FlattenAttrSpelling : uint32_t;
enum class FormatArgAttrSpelling : uint32_t;
enum class FormatAttrSpelling : uint32_t;
enum class FunctionDeclTemplatedKind : uint32_t;
enum class FunctionReturnThunksAttrKind : uint32_t;
enum class FunctionReturnThunksAttrSpelling : uint32_t;
enum class GNUInlineAttrSpelling : uint32_t;
enum class GuardedVarAttrSpelling : uint32_t;
enum class HIPManagedAttrSpelling : uint32_t;
enum class HLSLResourceAttrResourceClass : uint32_t;
enum class HLSLResourceAttrResourceKind : uint32_t;
enum class HLSLShaderAttrShaderType : uint32_t;
enum class HotAttrSpelling : uint32_t;
enum class IBActionAttrSpelling : uint32_t;
enum class IBOutletAttrSpelling : uint32_t;
enum class IBOutletCollectionAttrSpelling : uint32_t;
enum class IFuncAttrSpelling : uint32_t;
enum class ImplicitCastExprOnStack : uint32_t;
enum class ImplicitParamDeclImplicitParamKind : uint32_t;
enum class InitPriorityAttrSpelling : uint32_t;
enum class IntelOclBiccAttrSpelling : uint32_t;
enum class InternalLinkageAttrSpelling : uint32_t;
enum class LTOVisibilityPublicAttrSpelling : uint32_t;
enum class LeafAttrSpelling : uint32_t;
enum class LifetimeBoundAttrSpelling : uint32_t;
enum class LikelyAttrSpelling : uint32_t;
enum class LinkageSpecDeclLanguageIDs : uint32_t;
enum class LoaderUninitializedAttrSpelling : uint32_t;
enum class LoopHintAttrLoopHintState : uint32_t;
enum class LoopHintAttrOptionType : uint32_t;
enum class LoopHintAttrSpelling : uint32_t;
enum class MIGServerRoutineAttrSpelling : uint32_t;
enum class MSABIAttrSpelling : uint32_t;
enum class MSInheritanceAttrSpelling : uint32_t;
enum class MSP430InterruptAttrSpelling : uint32_t;
enum class MSStructAttrSpelling : uint32_t;
enum class MayAliasAttrSpelling : uint32_t;
enum class MaybeUndefAttrSpelling : uint32_t;
enum class MicroMipsAttrSpelling : uint32_t;
enum class MinSizeAttrSpelling : uint32_t;
enum class MinVectorWidthAttrSpelling : uint32_t;
enum class Mips16AttrSpelling : uint32_t;
enum class MipsInterruptAttrInterruptType : uint32_t;
enum class MipsInterruptAttrSpelling : uint32_t;
enum class MipsLongCallAttrSpelling : uint32_t;
enum class MipsShortCallAttrSpelling : uint32_t;
enum class ModeAttrSpelling : uint32_t;
enum class MustTailAttrSpelling : uint32_t;
enum class NSConsumedAttrSpelling : uint32_t;
enum class NSConsumesSelfAttrSpelling : uint32_t;
enum class NSReturnsAutoreleasedAttrSpelling : uint32_t;
enum class NSReturnsNotRetainedAttrSpelling : uint32_t;
enum class NSReturnsRetainedAttrSpelling : uint32_t;
enum class NakedAttrSpelling : uint32_t;
enum class NamedDeclExplicitVisibilityKind : uint32_t;
enum class NoBuiltinAttrSpelling : uint32_t;
enum class NoCommonAttrSpelling : uint32_t;
enum class NoDebugAttrSpelling : uint32_t;
enum class NoDerefAttrSpelling : uint32_t;
enum class NoDestroyAttrSpelling : uint32_t;
enum class NoDuplicateAttrSpelling : uint32_t;
enum class NoEscapeAttrSpelling : uint32_t;
enum class NoInlineAttrSpelling : uint32_t;
enum class NoInstrumentFunctionAttrSpelling : uint32_t;
enum class NoMergeAttrSpelling : uint32_t;
enum class NoMicroMipsAttrSpelling : uint32_t;
enum class NoMips16AttrSpelling : uint32_t;
enum class NoProfileFunctionAttrSpelling : uint32_t;
enum class NoRandomizeLayoutAttrSpelling : uint32_t;
enum class NoReturnAttrSpelling : uint32_t;
enum class NoSanitizeAttrSpelling : uint32_t;
enum class NoSpeculativeLoadHardeningAttrSpelling : uint32_t;
enum class NoSplitStackAttrSpelling : uint32_t;
enum class NoStackProtectorAttrSpelling : uint32_t;
enum class NoThreadSafetyAnalysisAttrSpelling : uint32_t;
enum class NoThrowAttrSpelling : uint32_t;
enum class NoUwtableAttrSpelling : uint32_t;
enum class NonNullAttrSpelling : uint32_t;
enum class NotTailCalledAttrSpelling : uint32_t;
enum class OMPAllocateDeclAttrAllocatorTypeTy : uint32_t;
enum class OMPDeclareReductionDeclInitKind : uint32_t;
enum class OMPDeclareSimdDeclAttrBranchStateTy : uint32_t;
enum class OMPDeclareTargetDeclAttrDevTypeTy : uint32_t;
enum class OMPDeclareTargetDeclAttrMapTypeTy : uint32_t;
enum class OSConsumedAttrSpelling : uint32_t;
enum class OSConsumesThisAttrSpelling : uint32_t;
enum class OSReturnsNotRetainedAttrSpelling : uint32_t;
enum class OSReturnsRetainedAttrSpelling : uint32_t;
enum class OSReturnsRetainedOnNonZeroAttrSpelling : uint32_t;
enum class OSReturnsRetainedOnZeroAttrSpelling : uint32_t;
enum class ObjCBoxableAttrSpelling : uint32_t;
enum class ObjCBridgeAttrSpelling : uint32_t;
enum class ObjCBridgeMutableAttrSpelling : uint32_t;
enum class ObjCBridgeRelatedAttrSpelling : uint32_t;
enum class ObjCClassStubAttrSpelling : uint32_t;
enum class ObjCDesignatedInitializerAttrSpelling : uint32_t;
enum class ObjCDirectAttrSpelling : uint32_t;
enum class ObjCDirectMembersAttrSpelling : uint32_t;
enum class ObjCExceptionAttrSpelling : uint32_t;
enum class ObjCExplicitProtocolImplAttrSpelling : uint32_t;
enum class ObjCExternallyRetainedAttrSpelling : uint32_t;
enum class ObjCGCAttrSpelling : uint32_t;
enum class ObjCIndependentClassAttrSpelling : uint32_t;
enum class ObjCIvarDeclAccessControl : uint32_t;
enum class ObjCMessageExprReceiverKind : uint32_t;
enum class ObjCMethodDeclImplementationControl : uint32_t;
enum class ObjCMethodFamilyAttrFamilyKind : uint32_t;
enum class ObjCMethodFamilyAttrSpelling : uint32_t;
enum class ObjCNSObjectAttrSpelling : uint32_t;
enum class ObjCNonLazyClassAttrSpelling : uint32_t;
enum class ObjCNonRuntimeProtocolAttrSpelling : uint32_t;
enum class ObjCOwnershipAttrSpelling : uint32_t;
enum class ObjCPreciseLifetimeAttrSpelling : uint32_t;
enum class ObjCPropertyDeclPropertyControl : uint32_t;
enum class ObjCPropertyDeclSetterKind : uint32_t;
enum class ObjCPropertyImplDeclKind : uint32_t;
enum class ObjCRequiresPropertyDefsAttrSpelling : uint32_t;
enum class ObjCRequiresSuperAttrSpelling : uint32_t;
enum class ObjCReturnsInnerPointerAttrSpelling : uint32_t;
enum class ObjCRootClassAttrSpelling : uint32_t;
enum class ObjCRuntimeNameAttrSpelling : uint32_t;
enum class ObjCRuntimeVisibleAttrSpelling : uint32_t;
enum class ObjCSubclassingRestrictedAttrSpelling : uint32_t;
enum class OpenCLAccessAttrSpelling : uint32_t;
enum class OpenCLConstantAddressSpaceAttrSpelling : uint32_t;
enum class OpenCLGenericAddressSpaceAttrSpelling : uint32_t;
enum class OpenCLGlobalAddressSpaceAttrSpelling : uint32_t;
enum class OpenCLGlobalDeviceAddressSpaceAttrSpelling : uint32_t;
enum class OpenCLGlobalHostAddressSpaceAttrSpelling : uint32_t;
enum class OpenCLKernelAttrSpelling : uint32_t;
enum class OpenCLLocalAddressSpaceAttrSpelling : uint32_t;
enum class OpenCLPrivateAddressSpaceAttrSpelling : uint32_t;
enum class OptimizeNoneAttrSpelling : uint32_t;
enum class OverloadableAttrSpelling : uint32_t;
enum class OwnershipAttrOwnershipKind : uint32_t;
enum class OwnershipAttrSpelling : uint32_t;
enum class PackedAttrSpelling : uint32_t;
enum class ParamTypestateAttrConsumedState : uint32_t;
enum class ParamTypestateAttrSpelling : uint32_t;
enum class PascalAttrSpelling : uint32_t;
enum class PassObjectSizeAttrSpelling : uint32_t;
enum class PatchableFunctionEntryAttrSpelling : uint32_t;
enum class PcsAttrPCSType : uint32_t;
enum class PcsAttrSpelling : uint32_t;
enum class PredefinedExprIdentKind : uint32_t;
enum class PreferredNameAttrSpelling : uint32_t;
enum class PreserveAllAttrSpelling : uint32_t;
enum class PreserveMostAttrSpelling : uint32_t;
enum class PtGuardedVarAttrSpelling : uint32_t;
enum class PureAttrSpelling : uint32_t;
enum class QualifiedTypeDestructionKind : uint32_t;
enum class QualifiedTypePrimitiveCopyKind : uint32_t;
enum class QualifiedTypePrimitiveDefaultInitializeKind : uint32_t;
enum class RISCVInterruptAttrInterruptType : uint32_t;
enum class RISCVInterruptAttrSpelling : uint32_t;
enum class RandomizeLayoutAttrSpelling : uint32_t;
enum class ReadOnlyPlacementAttrSpelling : uint32_t;
enum class RecordDeclArgPassingKind : uint32_t;
enum class RegCallAttrSpelling : uint32_t;
enum class ReinitializesAttrSpelling : uint32_t;
enum class ReleaseCapabilityAttrSpelling : uint32_t;
enum class ReleaseHandleAttrSpelling : uint32_t;
enum class RequiresCapabilityAttrSpelling : uint32_t;
enum class RestrictAttrSpelling : uint32_t;
enum class RetainAttrSpelling : uint32_t;
enum class ReturnTypestateAttrConsumedState : uint32_t;
enum class ReturnTypestateAttrSpelling : uint32_t;
enum class ReturnsNonNullAttrSpelling : uint32_t;
enum class ReturnsTwiceAttrSpelling : uint32_t;
enum class SYCLKernelAttrSpelling : uint32_t;
enum class SYCLSpecialClassAttrSpelling : uint32_t;
enum class ScopedLockableAttrSpelling : uint32_t;
enum class SectionAttrSpelling : uint32_t;
enum class SelectAnyAttrSpelling : uint32_t;
enum class SentinelAttrSpelling : uint32_t;
enum class SetTypestateAttrConsumedState : uint32_t;
enum class SetTypestateAttrSpelling : uint32_t;
enum class SourceLocExprIdentKind : uint32_t;
enum class SpeculativeLoadHardeningAttrSpelling : uint32_t;
enum class StandaloneDebugAttrSpelling : uint32_t;
enum class StdCallAttrSpelling : uint32_t;
enum class StmtLikelihood : int32_t;
enum class StmtKind : uint32_t;
enum class StringLiteralStringKind : uint32_t;
enum class SwiftAsyncAttrKind : uint32_t;
enum class SwiftAsyncAttrSpelling : uint32_t;
enum class SwiftAsyncCallAttrSpelling : uint32_t;
enum class SwiftAsyncContextAttrSpelling : uint32_t;
enum class SwiftAsyncErrorAttrConventionKind : uint32_t;
enum class SwiftAsyncErrorAttrSpelling : uint32_t;
enum class SwiftCallAttrSpelling : uint32_t;
enum class SwiftContextAttrSpelling : uint32_t;
enum class SwiftErrorAttrConventionKind : uint32_t;
enum class SwiftErrorResultAttrSpelling : uint32_t;
enum class SwiftIndirectResultAttrSpelling : uint32_t;
enum class SwiftNewTypeAttrNewtypeKind : uint32_t;
enum class SwiftNewTypeAttrSpelling : uint32_t;
enum class SysVABIAttrSpelling : uint32_t;
enum class TLSModelAttrSpelling : uint32_t;
enum class TargetAttrSpelling : uint32_t;
enum class TargetClonesAttrSpelling : uint32_t;
enum class TargetVersionAttrSpelling : uint32_t;
enum class TemplateArgumentKind : uint32_t;
enum class TestTypestateAttrConsumedState : uint32_t;
enum class TestTypestateAttrSpelling : uint32_t;
enum class ThisCallAttrSpelling : uint32_t;
enum class TransparentUnionAttrSpelling : uint32_t;
enum class TrivialABIAttrSpelling : uint32_t;
enum class TryAcquireCapabilityAttrSpelling : uint32_t;
enum class TypeScalarTypeKind : uint32_t;
enum class TypeKind : uint32_t;
enum class TypeTagForDatatypeAttrSpelling : uint32_t;
enum class TypeVisibilityAttrSpelling : uint32_t;
enum class TypeVisibilityAttrVisibilityType : uint32_t;
enum class UnaryTransformTypeUTTKind : uint32_t;
enum class UnavailableAttrImplicitReason : uint32_t;
enum class UnavailableAttrSpelling : uint32_t;
enum class UninitializedAttrSpelling : uint32_t;
enum class UnlikelyAttrSpelling : uint32_t;
enum class UnusedAttrSpelling : uint32_t;
enum class UseHandleAttrSpelling : uint32_t;
enum class UsedAttrSpelling : uint32_t;
enum class UserDefinedLiteralLiteralOperatorKind : uint32_t;
enum class UsingIfExistsAttrSpelling : uint32_t;
enum class UuidAttrSpelling : uint32_t;
enum class VarDeclDefinitionKind : uint32_t;
enum class VarDeclInitializationStyle : uint32_t;
enum class VarDeclTLSKind : uint32_t;
enum class VecReturnAttrSpelling : uint32_t;
enum class VectorCallAttrSpelling : uint32_t;
enum class VectorTypeVectorKind : uint32_t;
enum class VisibilityAttrSpelling : uint32_t;
enum class VisibilityAttrVisibilityType : uint32_t;
enum class WarnUnusedAttrSpelling : uint32_t;
enum class WarnUnusedResultAttrSpelling : uint32_t;
enum class WeakAttrSpelling : uint32_t;
enum class WeakImportAttrSpelling : uint32_t;
enum class WeakRefAttrSpelling : uint32_t;
enum class WebAssemblyExportNameAttrSpelling : uint32_t;
enum class WebAssemblyImportModuleAttrSpelling : uint32_t;
enum class WebAssemblyImportNameAttrSpelling : uint32_t;
enum class X86ForceAlignArgPointerAttrSpelling : uint32_t;
enum class XRayInstrumentAttrSpelling : uint32_t;
enum class XRayLogArgsAttrSpelling : uint32_t;
enum class ZeroCallUsedRegsAttrSpelling : uint32_t;
enum class ZeroCallUsedRegsAttrZeroCallUsedRegsKind : uint32_t;
enum class ASTDumpOutputFormat : uint32_t;
enum class AccessSpecifier : uint32_t;
enum class AddrSpaceMapMangling : uint32_t;
enum class AlignRequirementKind : int32_t;
enum class AltivecSrcCompatKind : int32_t;
enum class ArgumentKind : uint32_t;
enum class ArrayTypeTrait : uint32_t;
enum class AtomicScopeModelKind : int32_t;
enum class AutoTypeKeyword : int32_t;
enum class AvailabilityResult : uint32_t;
enum class BinaryOperatorKind : uint32_t;
enum class Bits : uint8_t;
enum class CallingConv : uint32_t;
enum class CanThrowResult : uint32_t;
enum class CapturedRegionKind : uint32_t;
enum class CastKind : uint32_t;
enum class ClangABI : int32_t;
enum class CommentKind : uint32_t;
enum class ComparisonCategoryResult : uint8_t;
enum class ComparisonCategoryType : uint8_t;
enum class CompilingModuleKind : uint32_t;
enum class ConstexprSpecKind : int32_t;
enum class CoreFoundationABI : int32_t;
enum class DataPositionTy : uint64_t;
enum class DebugSrcHashKind : uint32_t;
enum class DefaultArgKind : uint32_t;
enum class DefaultCallingConvention : uint32_t;
enum class DefaultVisiblityExportMapping : int32_t;
enum class DiagnosticLevelMask : uint32_t;
enum class ElaboratedTypeKeyword : uint32_t;
enum class EmbedBitcodeKind : uint32_t;
enum class EscapeChar : int32_t;
enum class ExceptionHandlingKind : int32_t;
enum class ExceptionSpecificationType : uint32_t;
enum class ExcessPrecisionKind : uint32_t;
enum class ExclusionType : uint32_t;
enum class ExplicitSpecKind : uint32_t;
enum class ExprDependence : uint8_t;
enum class ExprObjectKind : uint32_t;
enum class ExprOffsets : int32_t;
enum class ExprValueKind : uint32_t;
enum class ExpressionTrait : uint32_t;
enum class ExtKind : uint32_t;
enum class ExtendArgsKind : int32_t;
enum class FPEvalMethodKind : int32_t;
enum class FPExceptionModeKind : uint32_t;
enum class FPModeKind : uint32_t;
enum class FiniteLoopsKind : uint32_t;
enum class Flags : uint32_t;
enum class FramePointerKind : int32_t;
enum class GC : uint32_t;
enum class GCMode : uint32_t;
enum class GPUDefaultStreamKind : int32_t;
enum class GVALinkage : uint32_t;
enum class GetBuiltinTypeError : uint32_t;
enum class HLSLLangStd : uint32_t;
enum class ID : uint32_t;
enum class IdentifierInfoFlag : uint32_t;
enum class IfStatementKind : uint32_t;
enum class ImbueAttribute : int32_t;
enum class InClassInitStyle : uint32_t;
enum class InheritedDesignatedInitializersState : uint32_t;
enum class InitStorageKind : uint32_t;
enum class InlineAsmDialectKind : uint32_t;
enum class InlineVariableDefinitionKind : int32_t;
enum class InliningMethod : uint32_t;
enum class Kinds : uint32_t;
enum class LambdaCaptureDefault : uint32_t;
enum class LambdaCaptureKind : uint32_t;
enum class LangAS : uint32_t;
enum class LangFeatures : uint32_t;
enum class Language : uint8_t;
enum class LanguageLinkage : uint32_t;
enum class LaxVectorConversionKind : int32_t;
enum class Level : uint32_t;
enum class Linkage : uint8_t;
enum class MSInheritanceModel : int32_t;
enum class MSVCMajorVersion : uint32_t;
enum class MSVtorDispMode : int32_t;
enum class MethodRefFlags : uint32_t;
enum class ModifiableType : uint32_t;
enum class MultiVersionKind : int32_t;
enum class NameKind : uint32_t;
enum class NeedExtraManglingDecl : uint32_t;
enum class NestedNameSpecifierDependence : uint8_t;
enum class NonOdrUseReason : uint32_t;
enum class NonceObjCInterface : uint32_t;
enum class NullabilityKind : uint8_t;
enum class ObjCBridgeCastKind : uint32_t;
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
enum class OpenMPAdjustArgsOpKind : uint32_t;
enum class OpenMPAtClauseKind : uint32_t;
enum class OpenMPAtomicDefaultMemOrderClauseKind : uint32_t;
enum class OpenMPBindClauseKind : uint32_t;
enum class OpenMPDefaultmapClauseKind : uint32_t;
enum class OpenMPDefaultmapClauseModifier : uint32_t;
enum class OpenMPDependClauseKind : uint32_t;
enum class OpenMPDeviceClauseModifier : uint32_t;
enum class OpenMPDeviceType : uint32_t;
enum class OpenMPDistScheduleClauseKind : uint32_t;
enum class OpenMPGrainsizeClauseModifier : uint32_t;
enum class OpenMPLastprivateModifier : uint32_t;
enum class OpenMPLinearClauseKind : uint32_t;
enum class OpenMPMapClauseKind : uint32_t;
enum class OpenMPMapModifierKind : uint32_t;
enum class OpenMPMotionModifierKind : uint32_t;
enum class OpenMPNumTasksClauseModifier : uint32_t;
enum class OpenMPOrderClauseKind : uint32_t;
enum class OpenMPOrderClauseModifier : uint32_t;
enum class OpenMPReductionClauseModifier : uint32_t;
enum class OpenMPScheduleClauseKind : uint32_t;
enum class OpenMPScheduleClauseModifier : uint32_t;
enum class OpenMPSeverityClauseKind : uint32_t;
enum class OverloadedOperatorKind : int32_t;
enum class OverloadsShown : uint32_t;
enum class PPKeywordKind : uint32_t;
enum class ParameterABI : int32_t;
enum class ParenLocsOffsets : int32_t;
enum class PragmaFloatControlKind : uint32_t;
enum class PragmaMSCommentKind : uint32_t;
enum class PragmaMSPointersToMembersKind : uint32_t;
enum class PragmaMSStructKind : uint32_t;
enum class PragmaSectionFlag : uint32_t;
enum class ProfileInstrKind : uint32_t;
enum class Qualified : int32_t;
enum class RangeExprOffset : int32_t;
enum class RangeLocOffset : int32_t;
enum class RefQualifierKind : uint32_t;
enum class RemarkKind : uint32_t;
enum class ReservedIdentifierStatus : int32_t;
enum class SFINAEResponse : uint32_t;
enum class SYCLMajorVersion : uint32_t;
enum class SanitizerOrdinal : uint64_t;
enum class SelectorLocationsKind : uint32_t;
enum class ShaderStage : int32_t;
enum class SignReturnAddressKeyKind : int32_t;
enum class SignReturnAddressScopeKind : int32_t;
enum class SignedOverflowBehaviorTy : uint32_t;
enum class SpecialMemberFlags : uint32_t;
enum class SpecifierKind : uint32_t;
enum class StackProtectorMode : uint32_t;
enum class StorageClass : uint32_t;
enum class StorageDuration : uint32_t;
enum class StoredNameKind : uint32_t;
enum class StoredSpecifierKind : uint32_t;
enum class StrictFlexArraysLevelKind : int32_t;
enum class StructReturnConventionKind : uint32_t;
enum class SubExpr : uint32_t;
enum class SubStmt : uint32_t;
enum class SwiftAsyncFramePointerKind : int32_t;
enum class SyncScope : int32_t;
enum class Syntax : uint32_t;
enum class TLSModel : uint32_t;
enum class TQ : uint32_t;
enum class TagTypeKind : uint32_t;
enum class TailPaddingUseRules : uint32_t;
enum class TemplateArgumentDependence : uint8_t;
enum class TemplateNameDependence : uint8_t;
enum class TemplateSpecializationKind : uint32_t;
enum class TextDiagnosticFormat : uint32_t;
enum class ThreadModelKind : int32_t;
enum class ThreadStorageClassSpecifier : uint32_t;
enum class TokenKind : uint16_t;
enum class TrailingAllocKind : uint32_t;
enum class TranslationUnitKind : uint32_t;
enum class TrivialAutoVarInitKind : int32_t;
enum class TypeDependence : uint8_t;
enum class TypeLocClass : uint32_t;
enum class TypeOfKind : uint8_t;
enum class TypeSpecifierSign : int32_t;
enum class TypeSpecifierType : uint32_t;
enum class TypeSpecifierWidth : int32_t;
enum class TypeSpecifiersPipe : int32_t;
enum class TypeTrait : uint32_t;
enum class UnaryExprOrTypeTrait : uint32_t;
enum class UnaryOperatorKind : uint32_t;
enum class APValueKind : uint32_t;
enum class VectorLibrary : uint32_t;
enum class Visibility : uint32_t;
enum class AttributeSyntax : uint32_t;
enum class DeclCategory : uint32_t;
enum class MacroKind : uint8_t;
enum class PathKind : int8_t;
enum class FileType : int8_t;
enum class CompilerName : uint32_t;
enum class IncludePathLocation : uint32_t;
enum class TargetLanguage : uint32_t;
enum class PseudoKind : uint8_t;
enum class TokenCategory : uint8_t;
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

enum class BuiltinTypeKind : unsigned char;
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

enum class DefaultArgKind : unsigned char;
DefaultArgKind FromPasta(pasta::DefaultArgKind pasta_val);

enum class DefaultCallingConvention : unsigned char;
DefaultCallingConvention FromPasta(pasta::DefaultCallingConvention pasta_val);

enum class DefaultVisiblityExportMapping : unsigned char;
DefaultVisiblityExportMapping FromPasta(pasta::DefaultVisiblityExportMapping pasta_val);

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
