// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/InheritableAttr.h>

#include <multiplier/Entities/AArch64SVEPcsAttr.h>
#include <multiplier/Entities/AArch64VectorPcsAttr.h>
#include <multiplier/Entities/AMDGPUFlatWorkGroupSizeAttr.h>
#include <multiplier/Entities/AMDGPUKernelCallAttr.h>
#include <multiplier/Entities/AMDGPUNumSGPRAttr.h>
#include <multiplier/Entities/AMDGPUNumVGPRAttr.h>
#include <multiplier/Entities/AMDGPUWavesPerEUAttr.h>
#include <multiplier/Entities/ARMInterruptAttr.h>
#include <multiplier/Entities/AVRInterruptAttr.h>
#include <multiplier/Entities/AVRSignalAttr.h>
#include <multiplier/Entities/AcquireCapabilityAttr.h>
#include <multiplier/Entities/AcquireHandleAttr.h>
#include <multiplier/Entities/AcquiredAfterAttr.h>
#include <multiplier/Entities/AcquiredBeforeAttr.h>
#include <multiplier/Entities/AlignMac68kAttr.h>
#include <multiplier/Entities/AlignNaturalAttr.h>
#include <multiplier/Entities/AlignedAttr.h>
#include <multiplier/Entities/AllocAlignAttr.h>
#include <multiplier/Entities/AllocSizeAttr.h>
#include <multiplier/Entities/AlwaysDestroyAttr.h>
#include <multiplier/Entities/AlwaysInlineAttr.h>
#include <multiplier/Entities/AnalyzerNoReturnAttr.h>
#include <multiplier/Entities/AnnotateAttr.h>
#include <multiplier/Entities/AnyX86InterruptAttr.h>
#include <multiplier/Entities/AnyX86NoCallerSavedRegistersAttr.h>
#include <multiplier/Entities/AnyX86NoCfCheckAttr.h>
#include <multiplier/Entities/ArcWeakrefUnavailableAttr.h>
#include <multiplier/Entities/ArgumentWithTypeTagAttr.h>
#include <multiplier/Entities/ArmBuiltinAliasAttr.h>
#include <multiplier/Entities/ArmLocallyStreamingAttr.h>
#include <multiplier/Entities/ArmNewZAAttr.h>
#include <multiplier/Entities/ArtificialAttr.h>
#include <multiplier/Entities/AsmLabelAttr.h>
#include <multiplier/Entities/AssertCapabilityAttr.h>
#include <multiplier/Entities/AssertExclusiveLockAttr.h>
#include <multiplier/Entities/AssertSharedLockAttr.h>
#include <multiplier/Entities/AssumeAlignedAttr.h>
#include <multiplier/Entities/AssumptionAttr.h>
#include <multiplier/Entities/Attr.h>
#include <multiplier/Entities/AvailabilityAttr.h>
#include <multiplier/Entities/AvailableOnlyInDefaultEvalMethodAttr.h>
#include <multiplier/Entities/BPFPreserveAccessIndexAttr.h>
#include <multiplier/Entities/BTFDeclTagAttr.h>
#include <multiplier/Entities/BlocksAttr.h>
#include <multiplier/Entities/BuiltinAttr.h>
#include <multiplier/Entities/C11NoReturnAttr.h>
#include <multiplier/Entities/CDeclAttr.h>
#include <multiplier/Entities/CFAuditedTransferAttr.h>
#include <multiplier/Entities/CFConsumedAttr.h>
#include <multiplier/Entities/CFGuardAttr.h>
#include <multiplier/Entities/CFICanonicalJumpTableAttr.h>
#include <multiplier/Entities/CFReturnsNotRetainedAttr.h>
#include <multiplier/Entities/CFReturnsRetainedAttr.h>
#include <multiplier/Entities/CFUnknownTransferAttr.h>
#include <multiplier/Entities/CPUDispatchAttr.h>
#include <multiplier/Entities/CPUSpecificAttr.h>
#include <multiplier/Entities/CUDAConstantAttr.h>
#include <multiplier/Entities/CUDADeviceAttr.h>
#include <multiplier/Entities/CUDADeviceBuiltinSurfaceTypeAttr.h>
#include <multiplier/Entities/CUDADeviceBuiltinTextureTypeAttr.h>
#include <multiplier/Entities/CUDAGlobalAttr.h>
#include <multiplier/Entities/CUDAHostAttr.h>
#include <multiplier/Entities/CUDAInvalidTargetAttr.h>
#include <multiplier/Entities/CUDALaunchBoundsAttr.h>
#include <multiplier/Entities/CUDASharedAttr.h>
#include <multiplier/Entities/CXX11NoReturnAttr.h>
#include <multiplier/Entities/CallableWhenAttr.h>
#include <multiplier/Entities/CallbackAttr.h>
#include <multiplier/Entities/CapabilityAttr.h>
#include <multiplier/Entities/CapturedRecordAttr.h>
#include <multiplier/Entities/CarriesDependencyAttr.h>
#include <multiplier/Entities/CleanupAttr.h>
#include <multiplier/Entities/CmseNSEntryAttr.h>
#include <multiplier/Entities/CodeSegAttr.h>
#include <multiplier/Entities/ColdAttr.h>
#include <multiplier/Entities/CommonAttr.h>
#include <multiplier/Entities/ConstAttr.h>
#include <multiplier/Entities/ConstInitAttr.h>
#include <multiplier/Entities/ConstructorAttr.h>
#include <multiplier/Entities/ConsumableAttr.h>
#include <multiplier/Entities/ConsumableAutoCastAttr.h>
#include <multiplier/Entities/ConsumableSetOnReadAttr.h>
#include <multiplier/Entities/ConvergentAttr.h>
#include <multiplier/Entities/DLLExportAttr.h>
#include <multiplier/Entities/DLLExportStaticLocalAttr.h>
#include <multiplier/Entities/DLLImportAttr.h>
#include <multiplier/Entities/DLLImportStaticLocalAttr.h>
#include <multiplier/Entities/DeprecatedAttr.h>
#include <multiplier/Entities/DestructorAttr.h>
#include <multiplier/Entities/DiagnoseAsBuiltinAttr.h>
#include <multiplier/Entities/DiagnoseIfAttr.h>
#include <multiplier/Entities/DisableSanitizerInstrumentationAttr.h>
#include <multiplier/Entities/DisableTailCallsAttr.h>
#include <multiplier/Entities/EmptyBasesAttr.h>
#include <multiplier/Entities/EnableIfAttr.h>
#include <multiplier/Entities/EnforceTCBAttr.h>
#include <multiplier/Entities/EnforceTCBLeafAttr.h>
#include <multiplier/Entities/EnumExtensibilityAttr.h>
#include <multiplier/Entities/ErrorAttr.h>
#include <multiplier/Entities/ExcludeFromExplicitInstantiationAttr.h>
#include <multiplier/Entities/ExclusiveTrylockFunctionAttr.h>
#include <multiplier/Entities/ExternalSourceSymbolAttr.h>
#include <multiplier/Entities/FastCallAttr.h>
#include <multiplier/Entities/FinalAttr.h>
#include <multiplier/Entities/FlagEnumAttr.h>
#include <multiplier/Entities/FlattenAttr.h>
#include <multiplier/Entities/FormatArgAttr.h>
#include <multiplier/Entities/FormatAttr.h>
#include <multiplier/Entities/FunctionReturnThunksAttr.h>
#include <multiplier/Entities/GNUInlineAttr.h>
#include <multiplier/Entities/GuardedByAttr.h>
#include <multiplier/Entities/GuardedVarAttr.h>
#include <multiplier/Entities/HIPManagedAttr.h>
#include <multiplier/Entities/HLSLNumThreadsAttr.h>
#include <multiplier/Entities/HLSLResourceAttr.h>
#include <multiplier/Entities/HLSLResourceBindingAttr.h>
#include <multiplier/Entities/HLSLSV_DispatchThreadIDAttr.h>
#include <multiplier/Entities/HLSLSV_GroupIndexAttr.h>
#include <multiplier/Entities/HLSLShaderAttr.h>
#include <multiplier/Entities/HotAttr.h>
#include <multiplier/Entities/IBActionAttr.h>
#include <multiplier/Entities/IBOutletAttr.h>
#include <multiplier/Entities/IBOutletCollectionAttr.h>
#include <multiplier/Entities/InitPriorityAttr.h>
#include <multiplier/Entities/IntelOclBiccAttr.h>
#include <multiplier/Entities/InternalLinkageAttr.h>
#include <multiplier/Entities/LTOVisibilityPublicAttr.h>
#include <multiplier/Entities/LayoutVersionAttr.h>
#include <multiplier/Entities/LeafAttr.h>
#include <multiplier/Entities/LifetimeBoundAttr.h>
#include <multiplier/Entities/LockReturnedAttr.h>
#include <multiplier/Entities/LocksExcludedAttr.h>
#include <multiplier/Entities/M68kInterruptAttr.h>
#include <multiplier/Entities/MIGServerRoutineAttr.h>
#include <multiplier/Entities/MSABIAttr.h>
#include <multiplier/Entities/MSAllocatorAttr.h>
#include <multiplier/Entities/MSInheritanceAttr.h>
#include <multiplier/Entities/MSNoVTableAttr.h>
#include <multiplier/Entities/MSP430InterruptAttr.h>
#include <multiplier/Entities/MSStructAttr.h>
#include <multiplier/Entities/MSVtorDispAttr.h>
#include <multiplier/Entities/MaxFieldAlignmentAttr.h>
#include <multiplier/Entities/MayAliasAttr.h>
#include <multiplier/Entities/MaybeUndefAttr.h>
#include <multiplier/Entities/MicroMipsAttr.h>
#include <multiplier/Entities/MinSizeAttr.h>
#include <multiplier/Entities/MinVectorWidthAttr.h>
#include <multiplier/Entities/Mips16Attr.h>
#include <multiplier/Entities/MipsInterruptAttr.h>
#include <multiplier/Entities/MipsLongCallAttr.h>
#include <multiplier/Entities/MipsShortCallAttr.h>
#include <multiplier/Entities/NSConsumedAttr.h>
#include <multiplier/Entities/NSConsumesSelfAttr.h>
#include <multiplier/Entities/NSErrorDomainAttr.h>
#include <multiplier/Entities/NSReturnsAutoreleasedAttr.h>
#include <multiplier/Entities/NSReturnsNotRetainedAttr.h>
#include <multiplier/Entities/NSReturnsRetainedAttr.h>
#include <multiplier/Entities/NVPTXKernelAttr.h>
#include <multiplier/Entities/NakedAttr.h>
#include <multiplier/Entities/NoAliasAttr.h>
#include <multiplier/Entities/NoCommonAttr.h>
#include <multiplier/Entities/NoDebugAttr.h>
#include <multiplier/Entities/NoDestroyAttr.h>
#include <multiplier/Entities/NoDuplicateAttr.h>
#include <multiplier/Entities/NoInlineAttr.h>
#include <multiplier/Entities/NoInstrumentFunctionAttr.h>
#include <multiplier/Entities/NoMergeAttr.h>
#include <multiplier/Entities/NoMicroMipsAttr.h>
#include <multiplier/Entities/NoMips16Attr.h>
#include <multiplier/Entities/NoProfileFunctionAttr.h>
#include <multiplier/Entities/NoRandomizeLayoutAttr.h>
#include <multiplier/Entities/NoReturnAttr.h>
#include <multiplier/Entities/NoSanitizeAttr.h>
#include <multiplier/Entities/NoSpeculativeLoadHardeningAttr.h>
#include <multiplier/Entities/NoSplitStackAttr.h>
#include <multiplier/Entities/NoStackProtectorAttr.h>
#include <multiplier/Entities/NoThreadSafetyAnalysisAttr.h>
#include <multiplier/Entities/NoThrowAttr.h>
#include <multiplier/Entities/NoUniqueAddressAttr.h>
#include <multiplier/Entities/NoUwtableAttr.h>
#include <multiplier/Entities/NonNullAttr.h>
#include <multiplier/Entities/NotTailCalledAttr.h>
#include <multiplier/Entities/OMPAllocateDeclAttr.h>
#include <multiplier/Entities/OMPCaptureNoInitAttr.h>
#include <multiplier/Entities/OMPDeclareTargetDeclAttr.h>
#include <multiplier/Entities/OMPDeclareVariantAttr.h>
#include <multiplier/Entities/OMPThreadPrivateDeclAttr.h>
#include <multiplier/Entities/OSConsumedAttr.h>
#include <multiplier/Entities/OSConsumesThisAttr.h>
#include <multiplier/Entities/OSReturnsNotRetainedAttr.h>
#include <multiplier/Entities/OSReturnsRetainedAttr.h>
#include <multiplier/Entities/OSReturnsRetainedOnNonZeroAttr.h>
#include <multiplier/Entities/OSReturnsRetainedOnZeroAttr.h>
#include <multiplier/Entities/ObjCBridgeAttr.h>
#include <multiplier/Entities/ObjCBridgeMutableAttr.h>
#include <multiplier/Entities/ObjCBridgeRelatedAttr.h>
#include <multiplier/Entities/ObjCExceptionAttr.h>
#include <multiplier/Entities/ObjCExplicitProtocolImplAttr.h>
#include <multiplier/Entities/ObjCExternallyRetainedAttr.h>
#include <multiplier/Entities/ObjCIndependentClassAttr.h>
#include <multiplier/Entities/ObjCMethodFamilyAttr.h>
#include <multiplier/Entities/ObjCNSObjectAttr.h>
#include <multiplier/Entities/ObjCOwnershipAttr.h>
#include <multiplier/Entities/ObjCPreciseLifetimeAttr.h>
#include <multiplier/Entities/ObjCRequiresPropertyDefsAttr.h>
#include <multiplier/Entities/ObjCRequiresSuperAttr.h>
#include <multiplier/Entities/ObjCReturnsInnerPointerAttr.h>
#include <multiplier/Entities/ObjCRootClassAttr.h>
#include <multiplier/Entities/ObjCSubclassingRestrictedAttr.h>
#include <multiplier/Entities/OpenCLIntelReqdSubGroupSizeAttr.h>
#include <multiplier/Entities/OpenCLKernelAttr.h>
#include <multiplier/Entities/OptimizeNoneAttr.h>
#include <multiplier/Entities/OverrideAttr.h>
#include <multiplier/Entities/OwnerAttr.h>
#include <multiplier/Entities/OwnershipAttr.h>
#include <multiplier/Entities/PackedAttr.h>
#include <multiplier/Entities/ParamTypestateAttr.h>
#include <multiplier/Entities/PascalAttr.h>
#include <multiplier/Entities/PassObjectSizeAttr.h>
#include <multiplier/Entities/PatchableFunctionEntryAttr.h>
#include <multiplier/Entities/PcsAttr.h>
#include <multiplier/Entities/PointerAttr.h>
#include <multiplier/Entities/PragmaClangBSSSectionAttr.h>
#include <multiplier/Entities/PragmaClangDataSectionAttr.h>
#include <multiplier/Entities/PragmaClangRelroSectionAttr.h>
#include <multiplier/Entities/PragmaClangRodataSectionAttr.h>
#include <multiplier/Entities/PragmaClangTextSectionAttr.h>
#include <multiplier/Entities/PreferredNameAttr.h>
#include <multiplier/Entities/PreserveAllAttr.h>
#include <multiplier/Entities/PreserveMostAttr.h>
#include <multiplier/Entities/PtGuardedByAttr.h>
#include <multiplier/Entities/PtGuardedVarAttr.h>
#include <multiplier/Entities/PureAttr.h>
#include <multiplier/Entities/RISCVInterruptAttr.h>
#include <multiplier/Entities/RandomizeLayoutAttr.h>
#include <multiplier/Entities/ReadOnlyPlacementAttr.h>
#include <multiplier/Entities/RegCallAttr.h>
#include <multiplier/Entities/ReinitializesAttr.h>
#include <multiplier/Entities/ReleaseCapabilityAttr.h>
#include <multiplier/Entities/ReleaseHandleAttr.h>
#include <multiplier/Entities/ReqdWorkGroupSizeAttr.h>
#include <multiplier/Entities/RequiresCapabilityAttr.h>
#include <multiplier/Entities/RestrictAttr.h>
#include <multiplier/Entities/RetainAttr.h>
#include <multiplier/Entities/ReturnTypestateAttr.h>
#include <multiplier/Entities/ReturnsNonNullAttr.h>
#include <multiplier/Entities/ReturnsTwiceAttr.h>
#include <multiplier/Entities/SYCLKernelAttr.h>
#include <multiplier/Entities/SYCLSpecialClassAttr.h>
#include <multiplier/Entities/ScopedLockableAttr.h>
#include <multiplier/Entities/SectionAttr.h>
#include <multiplier/Entities/SelectAnyAttr.h>
#include <multiplier/Entities/SentinelAttr.h>
#include <multiplier/Entities/SetTypestateAttr.h>
#include <multiplier/Entities/SharedTrylockFunctionAttr.h>
#include <multiplier/Entities/SpeculativeLoadHardeningAttr.h>
#include <multiplier/Entities/StandaloneDebugAttr.h>
#include <multiplier/Entities/StdCallAttr.h>
#include <multiplier/Entities/StrictFPAttr.h>
#include <multiplier/Entities/StrictGuardStackCheckAttr.h>
#include <multiplier/Entities/SwiftAsyncAttr.h>
#include <multiplier/Entities/SwiftAsyncCallAttr.h>
#include <multiplier/Entities/SwiftAsyncContextAttr.h>
#include <multiplier/Entities/SwiftAsyncErrorAttr.h>
#include <multiplier/Entities/SwiftAsyncNameAttr.h>
#include <multiplier/Entities/SwiftAttrAttr.h>
#include <multiplier/Entities/SwiftBridgeAttr.h>
#include <multiplier/Entities/SwiftBridgedTypedefAttr.h>
#include <multiplier/Entities/SwiftCallAttr.h>
#include <multiplier/Entities/SwiftContextAttr.h>
#include <multiplier/Entities/SwiftErrorAttr.h>
#include <multiplier/Entities/SwiftErrorResultAttr.h>
#include <multiplier/Entities/SwiftIndirectResultAttr.h>
#include <multiplier/Entities/SwiftNameAttr.h>
#include <multiplier/Entities/SwiftNewTypeAttr.h>
#include <multiplier/Entities/SwiftPrivateAttr.h>
#include <multiplier/Entities/SysVABIAttr.h>
#include <multiplier/Entities/TLSModelAttr.h>
#include <multiplier/Entities/TargetAttr.h>
#include <multiplier/Entities/TargetClonesAttr.h>
#include <multiplier/Entities/TargetVersionAttr.h>
#include <multiplier/Entities/TestTypestateAttr.h>
#include <multiplier/Entities/ThisCallAttr.h>
#include <multiplier/Entities/Token.h>
#include <multiplier/Entities/TransparentUnionAttr.h>
#include <multiplier/Entities/TrivialABIAttr.h>
#include <multiplier/Entities/TryAcquireCapabilityAttr.h>
#include <multiplier/Entities/TypeTagForDatatypeAttr.h>
#include <multiplier/Entities/TypeVisibilityAttr.h>
#include <multiplier/Entities/UnavailableAttr.h>
#include <multiplier/Entities/UninitializedAttr.h>
#include <multiplier/Entities/UnsafeBufferUsageAttr.h>
#include <multiplier/Entities/UnusedAttr.h>
#include <multiplier/Entities/UseHandleAttr.h>
#include <multiplier/Entities/UsedAttr.h>
#include <multiplier/Entities/UsingIfExistsAttr.h>
#include <multiplier/Entities/UuidAttr.h>
#include <multiplier/Entities/VecReturnAttr.h>
#include <multiplier/Entities/VecTypeHintAttr.h>
#include <multiplier/Entities/VectorCallAttr.h>
#include <multiplier/Entities/VisibilityAttr.h>
#include <multiplier/Entities/WarnUnusedAttr.h>
#include <multiplier/Entities/WarnUnusedResultAttr.h>
#include <multiplier/Entities/WeakAttr.h>
#include <multiplier/Entities/WeakImportAttr.h>
#include <multiplier/Entities/WeakRefAttr.h>
#include <multiplier/Entities/WebAssemblyExportNameAttr.h>
#include <multiplier/Entities/WebAssemblyImportModuleAttr.h>
#include <multiplier/Entities/WebAssemblyImportNameAttr.h>
#include <multiplier/Entities/WorkGroupSizeHintAttr.h>
#include <multiplier/Entities/X86ForceAlignArgPointerAttr.h>
#include <multiplier/Entities/XRayInstrumentAttr.h>
#include <multiplier/Entities/XRayLogArgsAttr.h>
#include <multiplier/Entities/ZeroCallUsedRegsAttr.h>

#include "../EntityProvider.h"
#include "../Attr.h"

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

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
    return InheritableAttr::from(index.attribute(eid.Pack()));
  } else if (std::holds_alternative<InvalidId>(vid)) {
    assert(eid.Pack() == kInvalidEntityId);
  }
  return std::nullopt;
}

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
    MIGServerRoutineAttr::static_kind(),
    MSABIAttr::static_kind(),
    MSAllocatorAttr::static_kind(),
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
    ArmNewZAAttr::static_kind(),
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
    AlwaysInlineAttr::static_kind(),
    HLSLSV_DispatchThreadIDAttr::static_kind(),
    HLSLSV_GroupIndexAttr::static_kind(),
    SwiftAsyncContextAttr::static_kind(),
    SwiftContextAttr::static_kind(),
    SwiftErrorResultAttr::static_kind(),
    SwiftIndirectResultAttr::static_kind(),
};

std::optional<InheritableAttr> InheritableAttr::from(const Attr &parent) {
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
    case MIGServerRoutineAttr::static_kind():
    case MSABIAttr::static_kind():
    case MSAllocatorAttr::static_kind():
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
    case ArmNewZAAttr::static_kind():
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

gap::generator<InheritableAttr> InheritableAttr::in(const Index &index) {
  const EntityProviderPtr ep = entity_provider_of(index);
  for (AttrKind k : kInheritableAttrDerivedKinds) {
    for (AttrImplPtr eptr : ep->AttrsFor(ep, k)) {
      if (std::optional<InheritableAttr> e = InheritableAttr::from(Attr(std::move(eptr)))) {
        co_yield std::move(e.value());
      }
    }
  }
}

gap::generator<InheritableAttr> InheritableAttr::in(const Fragment &frag) {
  const EntityProviderPtr ep = entity_provider_of(frag);
  PackedFragmentId frag_id = frag.id();
  for (AttrKind k : kInheritableAttrDerivedKinds) {
    for (AttrImplPtr eptr : ep->AttrsFor(ep, k, frag_id)) {
      if (std::optional<InheritableAttr> e = InheritableAttr::from(Attr(std::move(eptr)))) {
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
        if (std::optional<InheritableAttr> e = InheritableAttr::from(Attr(std::move(eptr)))) {
          co_yield std::move(e.value());
        }
      }
    }
  }
}

std::optional<InheritableAttr> InheritableAttr::from(const Reference &r) {
  return InheritableAttr::from(r.as_attribute());
}

std::optional<InheritableAttr> InheritableAttr::from(const TokenContext &t) {
  return InheritableAttr::from(t.as_attribute());
}

bool InheritableAttr::should_inherit_even_if_already_present(void) const {
  return impl->reader.getVal11();
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
