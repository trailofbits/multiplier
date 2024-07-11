// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/InheritableAttr.h>
#include <multiplier/AST/Attr.h>
#include <multiplier/Frontend/File.h>
#include <multiplier/Frontend/Token.h>
#include <multiplier/AST/AArch64SVEPcsAttr.h>
#include <multiplier/AST/AArch64VectorPcsAttr.h>
#include <multiplier/AST/AMDGPUFlatWorkGroupSizeAttr.h>
#include <multiplier/AST/AMDGPUKernelCallAttr.h>
#include <multiplier/AST/AMDGPUNumSGPRAttr.h>
#include <multiplier/AST/AMDGPUNumVGPRAttr.h>
#include <multiplier/AST/AMDGPUWavesPerEUAttr.h>
#include <multiplier/AST/ARMInterruptAttr.h>
#include <multiplier/AST/AVRInterruptAttr.h>
#include <multiplier/AST/AVRSignalAttr.h>
#include <multiplier/AST/AcquireCapabilityAttr.h>
#include <multiplier/AST/AcquireHandleAttr.h>
#include <multiplier/AST/AcquiredAfterAttr.h>
#include <multiplier/AST/AcquiredBeforeAttr.h>
#include <multiplier/AST/AlignMac68kAttr.h>
#include <multiplier/AST/AlignNaturalAttr.h>
#include <multiplier/AST/AlignedAttr.h>
#include <multiplier/AST/AllocAlignAttr.h>
#include <multiplier/AST/AllocSizeAttr.h>
#include <multiplier/AST/AlwaysDestroyAttr.h>
#include <multiplier/AST/AlwaysInlineAttr.h>
#include <multiplier/AST/AnalyzerNoReturnAttr.h>
#include <multiplier/AST/AnnotateAttr.h>
#include <multiplier/AST/AnyX86InterruptAttr.h>
#include <multiplier/AST/AnyX86NoCallerSavedRegistersAttr.h>
#include <multiplier/AST/AnyX86NoCfCheckAttr.h>
#include <multiplier/AST/ArcWeakrefUnavailableAttr.h>
#include <multiplier/AST/ArgumentWithTypeTagAttr.h>
#include <multiplier/AST/ArmBuiltinAliasAttr.h>
#include <multiplier/AST/ArmLocallyStreamingAttr.h>
#include <multiplier/AST/ArmNewAttr.h>
#include <multiplier/AST/ArtificialAttr.h>
#include <multiplier/AST/AsmLabelAttr.h>
#include <multiplier/AST/AssertCapabilityAttr.h>
#include <multiplier/AST/AssertExclusiveLockAttr.h>
#include <multiplier/AST/AssertSharedLockAttr.h>
#include <multiplier/AST/AssumeAlignedAttr.h>
#include <multiplier/AST/AssumptionAttr.h>
#include <multiplier/AST/AvailabilityAttr.h>
#include <multiplier/AST/AvailableOnlyInDefaultEvalMethodAttr.h>
#include <multiplier/AST/BPFPreserveAccessIndexAttr.h>
#include <multiplier/AST/BPFPreserveStaticOffsetAttr.h>
#include <multiplier/AST/BTFDeclTagAttr.h>
#include <multiplier/AST/BlocksAttr.h>
#include <multiplier/AST/BuiltinAttr.h>
#include <multiplier/AST/C11NoReturnAttr.h>
#include <multiplier/AST/CDeclAttr.h>
#include <multiplier/AST/CFAuditedTransferAttr.h>
#include <multiplier/AST/CFConsumedAttr.h>
#include <multiplier/AST/CFGuardAttr.h>
#include <multiplier/AST/CFICanonicalJumpTableAttr.h>
#include <multiplier/AST/CFReturnsNotRetainedAttr.h>
#include <multiplier/AST/CFReturnsRetainedAttr.h>
#include <multiplier/AST/CFUnknownTransferAttr.h>
#include <multiplier/AST/CPUDispatchAttr.h>
#include <multiplier/AST/CPUSpecificAttr.h>
#include <multiplier/AST/CUDAConstantAttr.h>
#include <multiplier/AST/CUDADeviceAttr.h>
#include <multiplier/AST/CUDADeviceBuiltinSurfaceTypeAttr.h>
#include <multiplier/AST/CUDADeviceBuiltinTextureTypeAttr.h>
#include <multiplier/AST/CUDAGlobalAttr.h>
#include <multiplier/AST/CUDAHostAttr.h>
#include <multiplier/AST/CUDAInvalidTargetAttr.h>
#include <multiplier/AST/CUDALaunchBoundsAttr.h>
#include <multiplier/AST/CUDASharedAttr.h>
#include <multiplier/AST/CXX11NoReturnAttr.h>
#include <multiplier/AST/CallableWhenAttr.h>
#include <multiplier/AST/CallbackAttr.h>
#include <multiplier/AST/CapabilityAttr.h>
#include <multiplier/AST/CapturedRecordAttr.h>
#include <multiplier/AST/CarriesDependencyAttr.h>
#include <multiplier/AST/CleanupAttr.h>
#include <multiplier/AST/CmseNSEntryAttr.h>
#include <multiplier/AST/CodeModelAttr.h>
#include <multiplier/AST/CodeSegAttr.h>
#include <multiplier/AST/ColdAttr.h>
#include <multiplier/AST/CommonAttr.h>
#include <multiplier/AST/ConstAttr.h>
#include <multiplier/AST/ConstInitAttr.h>
#include <multiplier/AST/ConstructorAttr.h>
#include <multiplier/AST/ConsumableAttr.h>
#include <multiplier/AST/ConsumableAutoCastAttr.h>
#include <multiplier/AST/ConsumableSetOnReadAttr.h>
#include <multiplier/AST/ConvergentAttr.h>
#include <multiplier/AST/CoroDisableLifetimeBoundAttr.h>
#include <multiplier/AST/CoroLifetimeBoundAttr.h>
#include <multiplier/AST/CoroOnlyDestroyWhenCompleteAttr.h>
#include <multiplier/AST/CoroReturnTypeAttr.h>
#include <multiplier/AST/CoroWrapperAttr.h>
#include <multiplier/AST/CountedByAttr.h>
#include <multiplier/AST/DLLExportAttr.h>
#include <multiplier/AST/DLLExportStaticLocalAttr.h>
#include <multiplier/AST/DLLImportAttr.h>
#include <multiplier/AST/DLLImportStaticLocalAttr.h>
#include <multiplier/AST/DeprecatedAttr.h>
#include <multiplier/AST/DestructorAttr.h>
#include <multiplier/AST/DiagnoseAsBuiltinAttr.h>
#include <multiplier/AST/DiagnoseIfAttr.h>
#include <multiplier/AST/DisableSanitizerInstrumentationAttr.h>
#include <multiplier/AST/DisableTailCallsAttr.h>
#include <multiplier/AST/EmptyBasesAttr.h>
#include <multiplier/AST/EnableIfAttr.h>
#include <multiplier/AST/EnforceTCBAttr.h>
#include <multiplier/AST/EnforceTCBLeafAttr.h>
#include <multiplier/AST/EnumExtensibilityAttr.h>
#include <multiplier/AST/ErrorAttr.h>
#include <multiplier/AST/ExcludeFromExplicitInstantiationAttr.h>
#include <multiplier/AST/ExclusiveTrylockFunctionAttr.h>
#include <multiplier/AST/ExternalSourceSymbolAttr.h>
#include <multiplier/AST/FastCallAttr.h>
#include <multiplier/AST/FinalAttr.h>
#include <multiplier/AST/FlagEnumAttr.h>
#include <multiplier/AST/FlattenAttr.h>
#include <multiplier/AST/FormatArgAttr.h>
#include <multiplier/AST/FormatAttr.h>
#include <multiplier/AST/FunctionReturnThunksAttr.h>
#include <multiplier/AST/GNUInlineAttr.h>
#include <multiplier/AST/GuardedByAttr.h>
#include <multiplier/AST/GuardedVarAttr.h>
#include <multiplier/AST/HIPManagedAttr.h>
#include <multiplier/AST/HLSLNumThreadsAttr.h>
#include <multiplier/AST/HLSLResourceAttr.h>
#include <multiplier/AST/HLSLResourceBindingAttr.h>
#include <multiplier/AST/HLSLSV_DispatchThreadIDAttr.h>
#include <multiplier/AST/HLSLSV_GroupIndexAttr.h>
#include <multiplier/AST/HLSLShaderAttr.h>
#include <multiplier/AST/HotAttr.h>
#include <multiplier/AST/IBActionAttr.h>
#include <multiplier/AST/IBOutletAttr.h>
#include <multiplier/AST/IBOutletCollectionAttr.h>
#include <multiplier/AST/InitPriorityAttr.h>
#include <multiplier/AST/IntelOclBiccAttr.h>
#include <multiplier/AST/InternalLinkageAttr.h>
#include <multiplier/AST/LTOVisibilityPublicAttr.h>
#include <multiplier/AST/LayoutVersionAttr.h>
#include <multiplier/AST/LeafAttr.h>
#include <multiplier/AST/LifetimeBoundAttr.h>
#include <multiplier/AST/LockReturnedAttr.h>
#include <multiplier/AST/LocksExcludedAttr.h>
#include <multiplier/AST/M68kInterruptAttr.h>
#include <multiplier/AST/M68kRTDAttr.h>
#include <multiplier/AST/MIGServerRoutineAttr.h>
#include <multiplier/AST/MSABIAttr.h>
#include <multiplier/AST/MSAllocatorAttr.h>
#include <multiplier/AST/MSConstexprAttr.h>
#include <multiplier/AST/MSInheritanceAttr.h>
#include <multiplier/AST/MSNoVTableAttr.h>
#include <multiplier/AST/MSP430InterruptAttr.h>
#include <multiplier/AST/MSStructAttr.h>
#include <multiplier/AST/MSVtorDispAttr.h>
#include <multiplier/AST/MaxFieldAlignmentAttr.h>
#include <multiplier/AST/MayAliasAttr.h>
#include <multiplier/AST/MaybeUndefAttr.h>
#include <multiplier/AST/MicroMipsAttr.h>
#include <multiplier/AST/MinSizeAttr.h>
#include <multiplier/AST/MinVectorWidthAttr.h>
#include <multiplier/AST/Mips16Attr.h>
#include <multiplier/AST/MipsInterruptAttr.h>
#include <multiplier/AST/MipsLongCallAttr.h>
#include <multiplier/AST/MipsShortCallAttr.h>
#include <multiplier/AST/NSConsumedAttr.h>
#include <multiplier/AST/NSConsumesSelfAttr.h>
#include <multiplier/AST/NSErrorDomainAttr.h>
#include <multiplier/AST/NSReturnsAutoreleasedAttr.h>
#include <multiplier/AST/NSReturnsNotRetainedAttr.h>
#include <multiplier/AST/NSReturnsRetainedAttr.h>
#include <multiplier/AST/NVPTXKernelAttr.h>
#include <multiplier/AST/NakedAttr.h>
#include <multiplier/AST/NoAliasAttr.h>
#include <multiplier/AST/NoCommonAttr.h>
#include <multiplier/AST/NoDebugAttr.h>
#include <multiplier/AST/NoDestroyAttr.h>
#include <multiplier/AST/NoDuplicateAttr.h>
#include <multiplier/AST/NoInlineAttr.h>
#include <multiplier/AST/NoInstrumentFunctionAttr.h>
#include <multiplier/AST/NoMergeAttr.h>
#include <multiplier/AST/NoMicroMipsAttr.h>
#include <multiplier/AST/NoMips16Attr.h>
#include <multiplier/AST/NoProfileFunctionAttr.h>
#include <multiplier/AST/NoRandomizeLayoutAttr.h>
#include <multiplier/AST/NoReturnAttr.h>
#include <multiplier/AST/NoSanitizeAttr.h>
#include <multiplier/AST/NoSpeculativeLoadHardeningAttr.h>
#include <multiplier/AST/NoSplitStackAttr.h>
#include <multiplier/AST/NoStackProtectorAttr.h>
#include <multiplier/AST/NoThreadSafetyAnalysisAttr.h>
#include <multiplier/AST/NoThrowAttr.h>
#include <multiplier/AST/NoUniqueAddressAttr.h>
#include <multiplier/AST/NoUwtableAttr.h>
#include <multiplier/AST/NonNullAttr.h>
#include <multiplier/AST/NotTailCalledAttr.h>
#include <multiplier/AST/OMPAllocateDeclAttr.h>
#include <multiplier/AST/OMPCaptureNoInitAttr.h>
#include <multiplier/AST/OMPDeclareTargetDeclAttr.h>
#include <multiplier/AST/OMPDeclareVariantAttr.h>
#include <multiplier/AST/OMPThreadPrivateDeclAttr.h>
#include <multiplier/AST/OSConsumedAttr.h>
#include <multiplier/AST/OSConsumesThisAttr.h>
#include <multiplier/AST/OSReturnsNotRetainedAttr.h>
#include <multiplier/AST/OSReturnsRetainedAttr.h>
#include <multiplier/AST/OSReturnsRetainedOnNonZeroAttr.h>
#include <multiplier/AST/OSReturnsRetainedOnZeroAttr.h>
#include <multiplier/AST/ObjCBridgeAttr.h>
#include <multiplier/AST/ObjCBridgeMutableAttr.h>
#include <multiplier/AST/ObjCBridgeRelatedAttr.h>
#include <multiplier/AST/ObjCExceptionAttr.h>
#include <multiplier/AST/ObjCExplicitProtocolImplAttr.h>
#include <multiplier/AST/ObjCExternallyRetainedAttr.h>
#include <multiplier/AST/ObjCIndependentClassAttr.h>
#include <multiplier/AST/ObjCMethodFamilyAttr.h>
#include <multiplier/AST/ObjCNSObjectAttr.h>
#include <multiplier/AST/ObjCOwnershipAttr.h>
#include <multiplier/AST/ObjCPreciseLifetimeAttr.h>
#include <multiplier/AST/ObjCRequiresPropertyDefsAttr.h>
#include <multiplier/AST/ObjCRequiresSuperAttr.h>
#include <multiplier/AST/ObjCReturnsInnerPointerAttr.h>
#include <multiplier/AST/ObjCRootClassAttr.h>
#include <multiplier/AST/ObjCSubclassingRestrictedAttr.h>
#include <multiplier/AST/OpenCLIntelReqdSubGroupSizeAttr.h>
#include <multiplier/AST/OpenCLKernelAttr.h>
#include <multiplier/AST/OptimizeNoneAttr.h>
#include <multiplier/AST/OverrideAttr.h>
#include <multiplier/AST/OwnerAttr.h>
#include <multiplier/AST/OwnershipAttr.h>
#include <multiplier/AST/PackedAttr.h>
#include <multiplier/AST/ParamTypestateAttr.h>
#include <multiplier/AST/PascalAttr.h>
#include <multiplier/AST/PassObjectSizeAttr.h>
#include <multiplier/AST/PatchableFunctionEntryAttr.h>
#include <multiplier/AST/PcsAttr.h>
#include <multiplier/AST/PointerAttr.h>
#include <multiplier/AST/PragmaClangBSSSectionAttr.h>
#include <multiplier/AST/PragmaClangDataSectionAttr.h>
#include <multiplier/AST/PragmaClangRelroSectionAttr.h>
#include <multiplier/AST/PragmaClangRodataSectionAttr.h>
#include <multiplier/AST/PragmaClangTextSectionAttr.h>
#include <multiplier/AST/PreferredNameAttr.h>
#include <multiplier/AST/PreferredTypeAttr.h>
#include <multiplier/AST/PreserveAllAttr.h>
#include <multiplier/AST/PreserveMostAttr.h>
#include <multiplier/AST/PtGuardedByAttr.h>
#include <multiplier/AST/PtGuardedVarAttr.h>
#include <multiplier/AST/PureAttr.h>
#include <multiplier/AST/RISCVInterruptAttr.h>
#include <multiplier/AST/RandomizeLayoutAttr.h>
#include <multiplier/AST/ReadOnlyPlacementAttr.h>
#include <multiplier/AST/RegCallAttr.h>
#include <multiplier/AST/ReinitializesAttr.h>
#include <multiplier/AST/ReleaseCapabilityAttr.h>
#include <multiplier/AST/ReleaseHandleAttr.h>
#include <multiplier/AST/ReqdWorkGroupSizeAttr.h>
#include <multiplier/AST/RequiresCapabilityAttr.h>
#include <multiplier/AST/RestrictAttr.h>
#include <multiplier/AST/RetainAttr.h>
#include <multiplier/AST/ReturnTypestateAttr.h>
#include <multiplier/AST/ReturnsNonNullAttr.h>
#include <multiplier/AST/ReturnsTwiceAttr.h>
#include <multiplier/AST/SYCLKernelAttr.h>
#include <multiplier/AST/SYCLSpecialClassAttr.h>
#include <multiplier/AST/ScopedLockableAttr.h>
#include <multiplier/AST/SectionAttr.h>
#include <multiplier/AST/SelectAnyAttr.h>
#include <multiplier/AST/SentinelAttr.h>
#include <multiplier/AST/SetTypestateAttr.h>
#include <multiplier/AST/SharedTrylockFunctionAttr.h>
#include <multiplier/AST/SpeculativeLoadHardeningAttr.h>
#include <multiplier/AST/StandaloneDebugAttr.h>
#include <multiplier/AST/StdCallAttr.h>
#include <multiplier/AST/StrictFPAttr.h>
#include <multiplier/AST/StrictGuardStackCheckAttr.h>
#include <multiplier/AST/SuppressAttr.h>
#include <multiplier/AST/SwiftAsyncAttr.h>
#include <multiplier/AST/SwiftAsyncCallAttr.h>
#include <multiplier/AST/SwiftAsyncContextAttr.h>
#include <multiplier/AST/SwiftAsyncErrorAttr.h>
#include <multiplier/AST/SwiftAsyncNameAttr.h>
#include <multiplier/AST/SwiftAttrAttr.h>
#include <multiplier/AST/SwiftBridgeAttr.h>
#include <multiplier/AST/SwiftBridgedTypedefAttr.h>
#include <multiplier/AST/SwiftCallAttr.h>
#include <multiplier/AST/SwiftContextAttr.h>
#include <multiplier/AST/SwiftErrorAttr.h>
#include <multiplier/AST/SwiftErrorResultAttr.h>
#include <multiplier/AST/SwiftImportAsNonGenericAttr.h>
#include <multiplier/AST/SwiftImportPropertyAsAccessorsAttr.h>
#include <multiplier/AST/SwiftIndirectResultAttr.h>
#include <multiplier/AST/SwiftNameAttr.h>
#include <multiplier/AST/SwiftNewTypeAttr.h>
#include <multiplier/AST/SwiftPrivateAttr.h>
#include <multiplier/AST/SysVABIAttr.h>
#include <multiplier/AST/TLSModelAttr.h>
#include <multiplier/AST/TargetAttr.h>
#include <multiplier/AST/TargetClonesAttr.h>
#include <multiplier/AST/TargetVersionAttr.h>
#include <multiplier/AST/TestTypestateAttr.h>
#include <multiplier/AST/ThisCallAttr.h>
#include <multiplier/AST/TransparentUnionAttr.h>
#include <multiplier/AST/TrivialABIAttr.h>
#include <multiplier/AST/TryAcquireCapabilityAttr.h>
#include <multiplier/AST/TypeTagForDatatypeAttr.h>
#include <multiplier/AST/TypeVisibilityAttr.h>
#include <multiplier/AST/UnavailableAttr.h>
#include <multiplier/AST/UninitializedAttr.h>
#include <multiplier/AST/UnsafeBufferUsageAttr.h>
#include <multiplier/AST/UnusedAttr.h>
#include <multiplier/AST/UseHandleAttr.h>
#include <multiplier/AST/UsedAttr.h>
#include <multiplier/AST/UsingIfExistsAttr.h>
#include <multiplier/AST/UuidAttr.h>
#include <multiplier/AST/VecReturnAttr.h>
#include <multiplier/AST/VecTypeHintAttr.h>
#include <multiplier/AST/VectorCallAttr.h>
#include <multiplier/AST/VisibilityAttr.h>
#include <multiplier/AST/WarnUnusedAttr.h>
#include <multiplier/AST/WarnUnusedResultAttr.h>
#include <multiplier/AST/WeakAttr.h>
#include <multiplier/AST/WeakImportAttr.h>
#include <multiplier/AST/WeakRefAttr.h>
#include <multiplier/AST/WebAssemblyExportNameAttr.h>
#include <multiplier/AST/WebAssemblyImportModuleAttr.h>
#include <multiplier/AST/WebAssemblyImportNameAttr.h>
#include <multiplier/AST/WorkGroupSizeHintAttr.h>
#include <multiplier/AST/X86ForceAlignArgPointerAttr.h>
#include <multiplier/AST/XRayInstrumentAttr.h>
#include <multiplier/AST/XRayLogArgsAttr.h>
#include <multiplier/AST/ZeroCallUsedRegsAttr.h>

#include "../EntityProvider.h"
#include "../Attr.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

namespace {
static const AttrKind kInheritableAttrDerivedKinds[] = {
    InitPriorityAttr::static_kind(),
    IntelOclBiccAttr::static_kind(),
    InternalLinkageAttr::static_kind(),
    LTOVisibilityPublicAttr::static_kind(),
    LayoutVersionAttr::static_kind(),
    LeafAttr::static_kind(),
    LifetimeBoundAttr::static_kind(),
    LockReturnedAttr::static_kind(),
    LocksExcludedAttr::static_kind(),
    M68kInterruptAttr::static_kind(),
    M68kRTDAttr::static_kind(),
    MIGServerRoutineAttr::static_kind(),
    MSABIAttr::static_kind(),
    MSAllocatorAttr::static_kind(),
    MSConstexprAttr::static_kind(),
    MSInheritanceAttr::static_kind(),
    MSNoVTableAttr::static_kind(),
    MSP430InterruptAttr::static_kind(),
    MSStructAttr::static_kind(),
    MSVtorDispAttr::static_kind(),
    MaxFieldAlignmentAttr::static_kind(),
    MayAliasAttr::static_kind(),
    MaybeUndefAttr::static_kind(),
    MicroMipsAttr::static_kind(),
    MinSizeAttr::static_kind(),
    MinVectorWidthAttr::static_kind(),
    Mips16Attr::static_kind(),
    MipsInterruptAttr::static_kind(),
    MipsLongCallAttr::static_kind(),
    MipsShortCallAttr::static_kind(),
    NSConsumesSelfAttr::static_kind(),
    NSErrorDomainAttr::static_kind(),
    NSReturnsAutoreleasedAttr::static_kind(),
    NSReturnsNotRetainedAttr::static_kind(),
    NSReturnsRetainedAttr::static_kind(),
    NVPTXKernelAttr::static_kind(),
    NakedAttr::static_kind(),
    NoAliasAttr::static_kind(),
    NoCommonAttr::static_kind(),
    NoDebugAttr::static_kind(),
    NoDestroyAttr::static_kind(),
    NoDuplicateAttr::static_kind(),
    NoInstrumentFunctionAttr::static_kind(),
    NoMicroMipsAttr::static_kind(),
    NoMips16Attr::static_kind(),
    NoProfileFunctionAttr::static_kind(),
    NoRandomizeLayoutAttr::static_kind(),
    NoReturnAttr::static_kind(),
    NoSanitizeAttr::static_kind(),
    NoSpeculativeLoadHardeningAttr::static_kind(),
    NoSplitStackAttr::static_kind(),
    NoStackProtectorAttr::static_kind(),
    NoThreadSafetyAnalysisAttr::static_kind(),
    NoThrowAttr::static_kind(),
    NoUniqueAddressAttr::static_kind(),
    NoUwtableAttr::static_kind(),
    NotTailCalledAttr::static_kind(),
    OMPAllocateDeclAttr::static_kind(),
    OMPCaptureNoInitAttr::static_kind(),
    OMPDeclareTargetDeclAttr::static_kind(),
    OMPDeclareVariantAttr::static_kind(),
    OMPThreadPrivateDeclAttr::static_kind(),
    OSConsumesThisAttr::static_kind(),
    OSReturnsNotRetainedAttr::static_kind(),
    OSReturnsRetainedAttr::static_kind(),
    OSReturnsRetainedOnNonZeroAttr::static_kind(),
    OSReturnsRetainedOnZeroAttr::static_kind(),
    ObjCBridgeAttr::static_kind(),
    ObjCBridgeMutableAttr::static_kind(),
    ObjCBridgeRelatedAttr::static_kind(),
    ObjCExceptionAttr::static_kind(),
    ObjCExplicitProtocolImplAttr::static_kind(),
    ObjCExternallyRetainedAttr::static_kind(),
    ObjCIndependentClassAttr::static_kind(),
    ObjCMethodFamilyAttr::static_kind(),
    ObjCNSObjectAttr::static_kind(),
    ObjCOwnershipAttr::static_kind(),
    ObjCPreciseLifetimeAttr::static_kind(),
    ObjCRequiresPropertyDefsAttr::static_kind(),
    ObjCRequiresSuperAttr::static_kind(),
    ObjCReturnsInnerPointerAttr::static_kind(),
    ObjCRootClassAttr::static_kind(),
    ObjCSubclassingRestrictedAttr::static_kind(),
    OpenCLIntelReqdSubGroupSizeAttr::static_kind(),
    OpenCLKernelAttr::static_kind(),
    OptimizeNoneAttr::static_kind(),
    OverrideAttr::static_kind(),
    OwnerAttr::static_kind(),
    OwnershipAttr::static_kind(),
    PackedAttr::static_kind(),
    ParamTypestateAttr::static_kind(),
    PascalAttr::static_kind(),
    PatchableFunctionEntryAttr::static_kind(),
    PcsAttr::static_kind(),
    PointerAttr::static_kind(),
    PragmaClangBSSSectionAttr::static_kind(),
    PragmaClangDataSectionAttr::static_kind(),
    PragmaClangRelroSectionAttr::static_kind(),
    PragmaClangRodataSectionAttr::static_kind(),
    PragmaClangTextSectionAttr::static_kind(),
    PreferredNameAttr::static_kind(),
    PreferredTypeAttr::static_kind(),
    PreserveAllAttr::static_kind(),
    PreserveMostAttr::static_kind(),
    PtGuardedByAttr::static_kind(),
    PtGuardedVarAttr::static_kind(),
    PureAttr::static_kind(),
    RISCVInterruptAttr::static_kind(),
    RandomizeLayoutAttr::static_kind(),
    ReadOnlyPlacementAttr::static_kind(),
    RegCallAttr::static_kind(),
    ReinitializesAttr::static_kind(),
    ReleaseCapabilityAttr::static_kind(),
    ReqdWorkGroupSizeAttr::static_kind(),
    RequiresCapabilityAttr::static_kind(),
    RestrictAttr::static_kind(),
    RetainAttr::static_kind(),
    ReturnTypestateAttr::static_kind(),
    ReturnsNonNullAttr::static_kind(),
    ReturnsTwiceAttr::static_kind(),
    SYCLKernelAttr::static_kind(),
    SYCLSpecialClassAttr::static_kind(),
    ScopedLockableAttr::static_kind(),
    SectionAttr::static_kind(),
    SelectAnyAttr::static_kind(),
    SentinelAttr::static_kind(),
    SetTypestateAttr::static_kind(),
    SharedTrylockFunctionAttr::static_kind(),
    SpeculativeLoadHardeningAttr::static_kind(),
    StandaloneDebugAttr::static_kind(),
    StdCallAttr::static_kind(),
    StrictFPAttr::static_kind(),
    StrictGuardStackCheckAttr::static_kind(),
    SwiftAsyncAttr::static_kind(),
    SwiftAsyncCallAttr::static_kind(),
    SwiftAsyncErrorAttr::static_kind(),
    SwiftAsyncNameAttr::static_kind(),
    SwiftAttrAttr::static_kind(),
    SwiftBridgeAttr::static_kind(),
    SwiftBridgedTypedefAttr::static_kind(),
    SwiftCallAttr::static_kind(),
    SwiftErrorAttr::static_kind(),
    SwiftImportAsNonGenericAttr::static_kind(),
    SwiftImportPropertyAsAccessorsAttr::static_kind(),
    SwiftNameAttr::static_kind(),
    SwiftNewTypeAttr::static_kind(),
    SwiftPrivateAttr::static_kind(),
    SysVABIAttr::static_kind(),
    TLSModelAttr::static_kind(),
    TargetAttr::static_kind(),
    TargetClonesAttr::static_kind(),
    TargetVersionAttr::static_kind(),
    TestTypestateAttr::static_kind(),
    ThisCallAttr::static_kind(),
    TransparentUnionAttr::static_kind(),
    TrivialABIAttr::static_kind(),
    TryAcquireCapabilityAttr::static_kind(),
    TypeTagForDatatypeAttr::static_kind(),
    TypeVisibilityAttr::static_kind(),
    UnavailableAttr::static_kind(),
    UninitializedAttr::static_kind(),
    UnsafeBufferUsageAttr::static_kind(),
    UnusedAttr::static_kind(),
    UsedAttr::static_kind(),
    UsingIfExistsAttr::static_kind(),
    UuidAttr::static_kind(),
    VecReturnAttr::static_kind(),
    VecTypeHintAttr::static_kind(),
    VectorCallAttr::static_kind(),
    VisibilityAttr::static_kind(),
    WarnUnusedAttr::static_kind(),
    WarnUnusedResultAttr::static_kind(),
    WeakAttr::static_kind(),
    WeakImportAttr::static_kind(),
    WeakRefAttr::static_kind(),
    WebAssemblyExportNameAttr::static_kind(),
    WebAssemblyImportModuleAttr::static_kind(),
    WebAssemblyImportNameAttr::static_kind(),
    WorkGroupSizeHintAttr::static_kind(),
    X86ForceAlignArgPointerAttr::static_kind(),
    XRayInstrumentAttr::static_kind(),
    XRayLogArgsAttr::static_kind(),
    ZeroCallUsedRegsAttr::static_kind(),
    AArch64SVEPcsAttr::static_kind(),
    AArch64VectorPcsAttr::static_kind(),
    AMDGPUFlatWorkGroupSizeAttr::static_kind(),
    AMDGPUKernelCallAttr::static_kind(),
    AMDGPUNumSGPRAttr::static_kind(),
    AMDGPUNumVGPRAttr::static_kind(),
    AMDGPUWavesPerEUAttr::static_kind(),
    ARMInterruptAttr::static_kind(),
    AVRInterruptAttr::static_kind(),
    AVRSignalAttr::static_kind(),
    AcquireCapabilityAttr::static_kind(),
    AcquireHandleAttr::static_kind(),
    AcquiredAfterAttr::static_kind(),
    AcquiredBeforeAttr::static_kind(),
    AlignMac68kAttr::static_kind(),
    AlignNaturalAttr::static_kind(),
    AlignedAttr::static_kind(),
    AllocAlignAttr::static_kind(),
    AllocSizeAttr::static_kind(),
    AlwaysDestroyAttr::static_kind(),
    AnalyzerNoReturnAttr::static_kind(),
    AnyX86InterruptAttr::static_kind(),
    AnyX86NoCallerSavedRegistersAttr::static_kind(),
    AnyX86NoCfCheckAttr::static_kind(),
    ArcWeakrefUnavailableAttr::static_kind(),
    ArgumentWithTypeTagAttr::static_kind(),
    ArmBuiltinAliasAttr::static_kind(),
    ArmLocallyStreamingAttr::static_kind(),
    ArmNewAttr::static_kind(),
    ArtificialAttr::static_kind(),
    AsmLabelAttr::static_kind(),
    AssertCapabilityAttr::static_kind(),
    AssertExclusiveLockAttr::static_kind(),
    AssertSharedLockAttr::static_kind(),
    AssumeAlignedAttr::static_kind(),
    AssumptionAttr::static_kind(),
    AvailabilityAttr::static_kind(),
    AvailableOnlyInDefaultEvalMethodAttr::static_kind(),
    BPFPreserveAccessIndexAttr::static_kind(),
    BPFPreserveStaticOffsetAttr::static_kind(),
    BTFDeclTagAttr::static_kind(),
    BlocksAttr::static_kind(),
    BuiltinAttr::static_kind(),
    C11NoReturnAttr::static_kind(),
    CDeclAttr::static_kind(),
    CFAuditedTransferAttr::static_kind(),
    CFGuardAttr::static_kind(),
    CFICanonicalJumpTableAttr::static_kind(),
    CFReturnsNotRetainedAttr::static_kind(),
    CFReturnsRetainedAttr::static_kind(),
    CFUnknownTransferAttr::static_kind(),
    CPUDispatchAttr::static_kind(),
    CPUSpecificAttr::static_kind(),
    CUDAConstantAttr::static_kind(),
    CUDADeviceAttr::static_kind(),
    CUDADeviceBuiltinSurfaceTypeAttr::static_kind(),
    CUDADeviceBuiltinTextureTypeAttr::static_kind(),
    CUDAGlobalAttr::static_kind(),
    CUDAHostAttr::static_kind(),
    CUDAInvalidTargetAttr::static_kind(),
    CUDALaunchBoundsAttr::static_kind(),
    CUDASharedAttr::static_kind(),
    CXX11NoReturnAttr::static_kind(),
    CallableWhenAttr::static_kind(),
    CallbackAttr::static_kind(),
    CapabilityAttr::static_kind(),
    CapturedRecordAttr::static_kind(),
    CleanupAttr::static_kind(),
    CmseNSEntryAttr::static_kind(),
    CodeModelAttr::static_kind(),
    CodeSegAttr::static_kind(),
    ColdAttr::static_kind(),
    CommonAttr::static_kind(),
    ConstAttr::static_kind(),
    ConstInitAttr::static_kind(),
    ConstructorAttr::static_kind(),
    ConsumableAttr::static_kind(),
    ConsumableAutoCastAttr::static_kind(),
    ConsumableSetOnReadAttr::static_kind(),
    ConvergentAttr::static_kind(),
    CoroDisableLifetimeBoundAttr::static_kind(),
    CoroLifetimeBoundAttr::static_kind(),
    CoroOnlyDestroyWhenCompleteAttr::static_kind(),
    CoroReturnTypeAttr::static_kind(),
    CoroWrapperAttr::static_kind(),
    CountedByAttr::static_kind(),
    DLLExportAttr::static_kind(),
    DLLExportStaticLocalAttr::static_kind(),
    DLLImportAttr::static_kind(),
    DLLImportStaticLocalAttr::static_kind(),
    DeprecatedAttr::static_kind(),
    DestructorAttr::static_kind(),
    DiagnoseAsBuiltinAttr::static_kind(),
    DiagnoseIfAttr::static_kind(),
    DisableSanitizerInstrumentationAttr::static_kind(),
    DisableTailCallsAttr::static_kind(),
    EmptyBasesAttr::static_kind(),
    EnableIfAttr::static_kind(),
    EnforceTCBAttr::static_kind(),
    EnforceTCBLeafAttr::static_kind(),
    EnumExtensibilityAttr::static_kind(),
    ErrorAttr::static_kind(),
    ExcludeFromExplicitInstantiationAttr::static_kind(),
    ExclusiveTrylockFunctionAttr::static_kind(),
    ExternalSourceSymbolAttr::static_kind(),
    FastCallAttr::static_kind(),
    FinalAttr::static_kind(),
    FlagEnumAttr::static_kind(),
    FlattenAttr::static_kind(),
    FormatArgAttr::static_kind(),
    FormatAttr::static_kind(),
    FunctionReturnThunksAttr::static_kind(),
    GNUInlineAttr::static_kind(),
    GuardedByAttr::static_kind(),
    GuardedVarAttr::static_kind(),
    HIPManagedAttr::static_kind(),
    HLSLNumThreadsAttr::static_kind(),
    HLSLResourceAttr::static_kind(),
    HLSLResourceBindingAttr::static_kind(),
    HLSLShaderAttr::static_kind(),
    HotAttr::static_kind(),
    IBActionAttr::static_kind(),
    IBOutletAttr::static_kind(),
    IBOutletCollectionAttr::static_kind(),
    NSConsumedAttr::static_kind(),
    NonNullAttr::static_kind(),
    OSConsumedAttr::static_kind(),
    PassObjectSizeAttr::static_kind(),
    ReleaseHandleAttr::static_kind(),
    UseHandleAttr::static_kind(),
    AnnotateAttr::static_kind(),
    CFConsumedAttr::static_kind(),
    CarriesDependencyAttr::static_kind(),
    NoInlineAttr::static_kind(),
    NoMergeAttr::static_kind(),
    SuppressAttr::static_kind(),
    AlwaysInlineAttr::static_kind(),
    HLSLSV_DispatchThreadIDAttr::static_kind(),
    HLSLSV_GroupIndexAttr::static_kind(),
    SwiftAsyncContextAttr::static_kind(),
    SwiftContextAttr::static_kind(),
    SwiftErrorResultAttr::static_kind(),
    SwiftIndirectResultAttr::static_kind(),
};
}  // namespace

gap::generator<InheritableAttr> InheritableAttr::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (AttrKind k : kInheritableAttrDerivedKinds) {
    for (AttrImplPtr eptr : ep->AttrsFor(ep, k)) {
      if (std::optional<InheritableAttr> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<InheritableAttr> InheritableAttr::in(const File &file) {
  const EntityProviderPtr ep = entity_provider_of(file);
  PackedFileId file_id = file.id();
  for (PackedFragmentId frag_id : ep->ListFragmentsInFile(ep, file_id)) {
    for (AttrKind k : kInheritableAttrDerivedKinds) {
      for (AttrImplPtr eptr : ep->AttrsFor(ep, k, frag_id)) {
        if (std::optional<InheritableAttr> e = from_base(std::move(eptr))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

gap::generator<InheritableAttr> InheritableAttr::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (AttrKind k : kInheritableAttrDerivedKinds) {
    for (AttrImplPtr eptr : ep->AttrsFor(ep, k, frag_id)) {
      if (std::optional<InheritableAttr> e = from_base(std::move(eptr))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<InheritableAttr> InheritableAttr::containing(const Token &tok) {
  for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
    if (auto d = InheritableAttr::from(*ctx)) {
      co_yield *d;
    }
  }
}

bool InheritableAttr::contains(const Token &tok) const {
  auto id_ = id();
  for (auto &parent : InheritableAttr::containing(tok)) {
    if (parent.id() == id_) { return true; }
  }
  return false;
}

std::optional<InheritableAttr> InheritableAttr::by_id(const Index &index, EntityId eid) {
  VariantId vid = eid.Unpack();
  if (std::holds_alternative<AttrId>(vid)) {
    if (auto base = index.attribute(eid.Pack())) {
      return from_base(base.value());
    }
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

std::optional<InheritableAttr> InheritableAttr::from(const std::optional<Attr> &parent) {
  if (parent) {
    return from_base(parent.value());
  }
  return std::nullopt;
}

std::optional<InheritableAttr> InheritableAttr::from_base(const Attr &parent) {
  switch (parent.kind()) {
    case InitPriorityAttr::static_kind():
    case IntelOclBiccAttr::static_kind():
    case InternalLinkageAttr::static_kind():
    case LTOVisibilityPublicAttr::static_kind():
    case LayoutVersionAttr::static_kind():
    case LeafAttr::static_kind():
    case LifetimeBoundAttr::static_kind():
    case LockReturnedAttr::static_kind():
    case LocksExcludedAttr::static_kind():
    case M68kInterruptAttr::static_kind():
    case M68kRTDAttr::static_kind():
    case MIGServerRoutineAttr::static_kind():
    case MSABIAttr::static_kind():
    case MSAllocatorAttr::static_kind():
    case MSConstexprAttr::static_kind():
    case MSInheritanceAttr::static_kind():
    case MSNoVTableAttr::static_kind():
    case MSP430InterruptAttr::static_kind():
    case MSStructAttr::static_kind():
    case MSVtorDispAttr::static_kind():
    case MaxFieldAlignmentAttr::static_kind():
    case MayAliasAttr::static_kind():
    case MaybeUndefAttr::static_kind():
    case MicroMipsAttr::static_kind():
    case MinSizeAttr::static_kind():
    case MinVectorWidthAttr::static_kind():
    case Mips16Attr::static_kind():
    case MipsInterruptAttr::static_kind():
    case MipsLongCallAttr::static_kind():
    case MipsShortCallAttr::static_kind():
    case NSConsumesSelfAttr::static_kind():
    case NSErrorDomainAttr::static_kind():
    case NSReturnsAutoreleasedAttr::static_kind():
    case NSReturnsNotRetainedAttr::static_kind():
    case NSReturnsRetainedAttr::static_kind():
    case NVPTXKernelAttr::static_kind():
    case NakedAttr::static_kind():
    case NoAliasAttr::static_kind():
    case NoCommonAttr::static_kind():
    case NoDebugAttr::static_kind():
    case NoDestroyAttr::static_kind():
    case NoDuplicateAttr::static_kind():
    case NoInstrumentFunctionAttr::static_kind():
    case NoMicroMipsAttr::static_kind():
    case NoMips16Attr::static_kind():
    case NoProfileFunctionAttr::static_kind():
    case NoRandomizeLayoutAttr::static_kind():
    case NoReturnAttr::static_kind():
    case NoSanitizeAttr::static_kind():
    case NoSpeculativeLoadHardeningAttr::static_kind():
    case NoSplitStackAttr::static_kind():
    case NoStackProtectorAttr::static_kind():
    case NoThreadSafetyAnalysisAttr::static_kind():
    case NoThrowAttr::static_kind():
    case NoUniqueAddressAttr::static_kind():
    case NoUwtableAttr::static_kind():
    case NotTailCalledAttr::static_kind():
    case OMPAllocateDeclAttr::static_kind():
    case OMPCaptureNoInitAttr::static_kind():
    case OMPDeclareTargetDeclAttr::static_kind():
    case OMPDeclareVariantAttr::static_kind():
    case OMPThreadPrivateDeclAttr::static_kind():
    case OSConsumesThisAttr::static_kind():
    case OSReturnsNotRetainedAttr::static_kind():
    case OSReturnsRetainedAttr::static_kind():
    case OSReturnsRetainedOnNonZeroAttr::static_kind():
    case OSReturnsRetainedOnZeroAttr::static_kind():
    case ObjCBridgeAttr::static_kind():
    case ObjCBridgeMutableAttr::static_kind():
    case ObjCBridgeRelatedAttr::static_kind():
    case ObjCExceptionAttr::static_kind():
    case ObjCExplicitProtocolImplAttr::static_kind():
    case ObjCExternallyRetainedAttr::static_kind():
    case ObjCIndependentClassAttr::static_kind():
    case ObjCMethodFamilyAttr::static_kind():
    case ObjCNSObjectAttr::static_kind():
    case ObjCOwnershipAttr::static_kind():
    case ObjCPreciseLifetimeAttr::static_kind():
    case ObjCRequiresPropertyDefsAttr::static_kind():
    case ObjCRequiresSuperAttr::static_kind():
    case ObjCReturnsInnerPointerAttr::static_kind():
    case ObjCRootClassAttr::static_kind():
    case ObjCSubclassingRestrictedAttr::static_kind():
    case OpenCLIntelReqdSubGroupSizeAttr::static_kind():
    case OpenCLKernelAttr::static_kind():
    case OptimizeNoneAttr::static_kind():
    case OverrideAttr::static_kind():
    case OwnerAttr::static_kind():
    case OwnershipAttr::static_kind():
    case PackedAttr::static_kind():
    case ParamTypestateAttr::static_kind():
    case PascalAttr::static_kind():
    case PatchableFunctionEntryAttr::static_kind():
    case PcsAttr::static_kind():
    case PointerAttr::static_kind():
    case PragmaClangBSSSectionAttr::static_kind():
    case PragmaClangDataSectionAttr::static_kind():
    case PragmaClangRelroSectionAttr::static_kind():
    case PragmaClangRodataSectionAttr::static_kind():
    case PragmaClangTextSectionAttr::static_kind():
    case PreferredNameAttr::static_kind():
    case PreferredTypeAttr::static_kind():
    case PreserveAllAttr::static_kind():
    case PreserveMostAttr::static_kind():
    case PtGuardedByAttr::static_kind():
    case PtGuardedVarAttr::static_kind():
    case PureAttr::static_kind():
    case RISCVInterruptAttr::static_kind():
    case RandomizeLayoutAttr::static_kind():
    case ReadOnlyPlacementAttr::static_kind():
    case RegCallAttr::static_kind():
    case ReinitializesAttr::static_kind():
    case ReleaseCapabilityAttr::static_kind():
    case ReqdWorkGroupSizeAttr::static_kind():
    case RequiresCapabilityAttr::static_kind():
    case RestrictAttr::static_kind():
    case RetainAttr::static_kind():
    case ReturnTypestateAttr::static_kind():
    case ReturnsNonNullAttr::static_kind():
    case ReturnsTwiceAttr::static_kind():
    case SYCLKernelAttr::static_kind():
    case SYCLSpecialClassAttr::static_kind():
    case ScopedLockableAttr::static_kind():
    case SectionAttr::static_kind():
    case SelectAnyAttr::static_kind():
    case SentinelAttr::static_kind():
    case SetTypestateAttr::static_kind():
    case SharedTrylockFunctionAttr::static_kind():
    case SpeculativeLoadHardeningAttr::static_kind():
    case StandaloneDebugAttr::static_kind():
    case StdCallAttr::static_kind():
    case StrictFPAttr::static_kind():
    case StrictGuardStackCheckAttr::static_kind():
    case SwiftAsyncAttr::static_kind():
    case SwiftAsyncCallAttr::static_kind():
    case SwiftAsyncErrorAttr::static_kind():
    case SwiftAsyncNameAttr::static_kind():
    case SwiftAttrAttr::static_kind():
    case SwiftBridgeAttr::static_kind():
    case SwiftBridgedTypedefAttr::static_kind():
    case SwiftCallAttr::static_kind():
    case SwiftErrorAttr::static_kind():
    case SwiftImportAsNonGenericAttr::static_kind():
    case SwiftImportPropertyAsAccessorsAttr::static_kind():
    case SwiftNameAttr::static_kind():
    case SwiftNewTypeAttr::static_kind():
    case SwiftPrivateAttr::static_kind():
    case SysVABIAttr::static_kind():
    case TLSModelAttr::static_kind():
    case TargetAttr::static_kind():
    case TargetClonesAttr::static_kind():
    case TargetVersionAttr::static_kind():
    case TestTypestateAttr::static_kind():
    case ThisCallAttr::static_kind():
    case TransparentUnionAttr::static_kind():
    case TrivialABIAttr::static_kind():
    case TryAcquireCapabilityAttr::static_kind():
    case TypeTagForDatatypeAttr::static_kind():
    case TypeVisibilityAttr::static_kind():
    case UnavailableAttr::static_kind():
    case UninitializedAttr::static_kind():
    case UnsafeBufferUsageAttr::static_kind():
    case UnusedAttr::static_kind():
    case UsedAttr::static_kind():
    case UsingIfExistsAttr::static_kind():
    case UuidAttr::static_kind():
    case VecReturnAttr::static_kind():
    case VecTypeHintAttr::static_kind():
    case VectorCallAttr::static_kind():
    case VisibilityAttr::static_kind():
    case WarnUnusedAttr::static_kind():
    case WarnUnusedResultAttr::static_kind():
    case WeakAttr::static_kind():
    case WeakImportAttr::static_kind():
    case WeakRefAttr::static_kind():
    case WebAssemblyExportNameAttr::static_kind():
    case WebAssemblyImportModuleAttr::static_kind():
    case WebAssemblyImportNameAttr::static_kind():
    case WorkGroupSizeHintAttr::static_kind():
    case X86ForceAlignArgPointerAttr::static_kind():
    case XRayInstrumentAttr::static_kind():
    case XRayLogArgsAttr::static_kind():
    case ZeroCallUsedRegsAttr::static_kind():
    case AArch64SVEPcsAttr::static_kind():
    case AArch64VectorPcsAttr::static_kind():
    case AMDGPUFlatWorkGroupSizeAttr::static_kind():
    case AMDGPUKernelCallAttr::static_kind():
    case AMDGPUNumSGPRAttr::static_kind():
    case AMDGPUNumVGPRAttr::static_kind():
    case AMDGPUWavesPerEUAttr::static_kind():
    case ARMInterruptAttr::static_kind():
    case AVRInterruptAttr::static_kind():
    case AVRSignalAttr::static_kind():
    case AcquireCapabilityAttr::static_kind():
    case AcquireHandleAttr::static_kind():
    case AcquiredAfterAttr::static_kind():
    case AcquiredBeforeAttr::static_kind():
    case AlignMac68kAttr::static_kind():
    case AlignNaturalAttr::static_kind():
    case AlignedAttr::static_kind():
    case AllocAlignAttr::static_kind():
    case AllocSizeAttr::static_kind():
    case AlwaysDestroyAttr::static_kind():
    case AnalyzerNoReturnAttr::static_kind():
    case AnyX86InterruptAttr::static_kind():
    case AnyX86NoCallerSavedRegistersAttr::static_kind():
    case AnyX86NoCfCheckAttr::static_kind():
    case ArcWeakrefUnavailableAttr::static_kind():
    case ArgumentWithTypeTagAttr::static_kind():
    case ArmBuiltinAliasAttr::static_kind():
    case ArmLocallyStreamingAttr::static_kind():
    case ArmNewAttr::static_kind():
    case ArtificialAttr::static_kind():
    case AsmLabelAttr::static_kind():
    case AssertCapabilityAttr::static_kind():
    case AssertExclusiveLockAttr::static_kind():
    case AssertSharedLockAttr::static_kind():
    case AssumeAlignedAttr::static_kind():
    case AssumptionAttr::static_kind():
    case AvailabilityAttr::static_kind():
    case AvailableOnlyInDefaultEvalMethodAttr::static_kind():
    case BPFPreserveAccessIndexAttr::static_kind():
    case BPFPreserveStaticOffsetAttr::static_kind():
    case BTFDeclTagAttr::static_kind():
    case BlocksAttr::static_kind():
    case BuiltinAttr::static_kind():
    case C11NoReturnAttr::static_kind():
    case CDeclAttr::static_kind():
    case CFAuditedTransferAttr::static_kind():
    case CFGuardAttr::static_kind():
    case CFICanonicalJumpTableAttr::static_kind():
    case CFReturnsNotRetainedAttr::static_kind():
    case CFReturnsRetainedAttr::static_kind():
    case CFUnknownTransferAttr::static_kind():
    case CPUDispatchAttr::static_kind():
    case CPUSpecificAttr::static_kind():
    case CUDAConstantAttr::static_kind():
    case CUDADeviceAttr::static_kind():
    case CUDADeviceBuiltinSurfaceTypeAttr::static_kind():
    case CUDADeviceBuiltinTextureTypeAttr::static_kind():
    case CUDAGlobalAttr::static_kind():
    case CUDAHostAttr::static_kind():
    case CUDAInvalidTargetAttr::static_kind():
    case CUDALaunchBoundsAttr::static_kind():
    case CUDASharedAttr::static_kind():
    case CXX11NoReturnAttr::static_kind():
    case CallableWhenAttr::static_kind():
    case CallbackAttr::static_kind():
    case CapabilityAttr::static_kind():
    case CapturedRecordAttr::static_kind():
    case CleanupAttr::static_kind():
    case CmseNSEntryAttr::static_kind():
    case CodeModelAttr::static_kind():
    case CodeSegAttr::static_kind():
    case ColdAttr::static_kind():
    case CommonAttr::static_kind():
    case ConstAttr::static_kind():
    case ConstInitAttr::static_kind():
    case ConstructorAttr::static_kind():
    case ConsumableAttr::static_kind():
    case ConsumableAutoCastAttr::static_kind():
    case ConsumableSetOnReadAttr::static_kind():
    case ConvergentAttr::static_kind():
    case CoroDisableLifetimeBoundAttr::static_kind():
    case CoroLifetimeBoundAttr::static_kind():
    case CoroOnlyDestroyWhenCompleteAttr::static_kind():
    case CoroReturnTypeAttr::static_kind():
    case CoroWrapperAttr::static_kind():
    case CountedByAttr::static_kind():
    case DLLExportAttr::static_kind():
    case DLLExportStaticLocalAttr::static_kind():
    case DLLImportAttr::static_kind():
    case DLLImportStaticLocalAttr::static_kind():
    case DeprecatedAttr::static_kind():
    case DestructorAttr::static_kind():
    case DiagnoseAsBuiltinAttr::static_kind():
    case DiagnoseIfAttr::static_kind():
    case DisableSanitizerInstrumentationAttr::static_kind():
    case DisableTailCallsAttr::static_kind():
    case EmptyBasesAttr::static_kind():
    case EnableIfAttr::static_kind():
    case EnforceTCBAttr::static_kind():
    case EnforceTCBLeafAttr::static_kind():
    case EnumExtensibilityAttr::static_kind():
    case ErrorAttr::static_kind():
    case ExcludeFromExplicitInstantiationAttr::static_kind():
    case ExclusiveTrylockFunctionAttr::static_kind():
    case ExternalSourceSymbolAttr::static_kind():
    case FastCallAttr::static_kind():
    case FinalAttr::static_kind():
    case FlagEnumAttr::static_kind():
    case FlattenAttr::static_kind():
    case FormatArgAttr::static_kind():
    case FormatAttr::static_kind():
    case FunctionReturnThunksAttr::static_kind():
    case GNUInlineAttr::static_kind():
    case GuardedByAttr::static_kind():
    case GuardedVarAttr::static_kind():
    case HIPManagedAttr::static_kind():
    case HLSLNumThreadsAttr::static_kind():
    case HLSLResourceAttr::static_kind():
    case HLSLResourceBindingAttr::static_kind():
    case HLSLShaderAttr::static_kind():
    case HotAttr::static_kind():
    case IBActionAttr::static_kind():
    case IBOutletAttr::static_kind():
    case IBOutletCollectionAttr::static_kind():
    case NSConsumedAttr::static_kind():
    case NonNullAttr::static_kind():
    case OSConsumedAttr::static_kind():
    case PassObjectSizeAttr::static_kind():
    case ReleaseHandleAttr::static_kind():
    case UseHandleAttr::static_kind():
    case AnnotateAttr::static_kind():
    case CFConsumedAttr::static_kind():
    case CarriesDependencyAttr::static_kind():
    case NoInlineAttr::static_kind():
    case NoMergeAttr::static_kind():
    case SuppressAttr::static_kind():
    case AlwaysInlineAttr::static_kind():
    case HLSLSV_DispatchThreadIDAttr::static_kind():
    case HLSLSV_GroupIndexAttr::static_kind():
    case SwiftAsyncContextAttr::static_kind():
    case SwiftContextAttr::static_kind():
    case SwiftErrorResultAttr::static_kind():
    case SwiftIndirectResultAttr::static_kind():
      return reinterpret_cast<const InheritableAttr &>(parent);
    default:
      return std::nullopt;
  }
}

std::optional<InheritableAttr> InheritableAttr::from(const Reference &r) {
  return InheritableAttr::from(r.as_attribute());
}

std::optional<InheritableAttr> InheritableAttr::from(const VariantEntity &e) {
  if (!std::holds_alternative<Attr>(e)) {
    return std::nullopt;
  }
  return from_base(std::get<Attr>(e));
}

std::optional<InheritableAttr> InheritableAttr::from(const TokenContext &t) {
  if (auto base = t.as_attribute()) {
    return from_base(base.value());
  }
  return std::nullopt;
}

bool InheritableAttr::should_inherit_even_if_already_present(void) const {
  return impl->reader.getVal14();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
