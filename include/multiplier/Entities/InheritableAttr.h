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
#include <span>
#include <vector>

#include <gap/core/generator.hpp>
#include "../Iterator.h"
#include "../Reference.h"
#include "../Types.h"
#include "../Token.h"

#include "Attr.h"

namespace mx {
class AArch64SVEPcsAttr;
class AArch64VectorPcsAttr;
class AMDGPUFlatWorkGroupSizeAttr;
class AMDGPUKernelCallAttr;
class AMDGPUNumSGPRAttr;
class AMDGPUNumVGPRAttr;
class AMDGPUWavesPerEUAttr;
class ARMInterruptAttr;
class AVRInterruptAttr;
class AVRSignalAttr;
class AcquireCapabilityAttr;
class AcquireHandleAttr;
class AcquiredAfterAttr;
class AcquiredBeforeAttr;
class AlignMac68kAttr;
class AlignNaturalAttr;
class AlignedAttr;
class AllocAlignAttr;
class AllocSizeAttr;
class AlwaysDestroyAttr;
class AlwaysInlineAttr;
class AnalyzerNoReturnAttr;
class AnnotateAttr;
class AnyX86InterruptAttr;
class AnyX86NoCallerSavedRegistersAttr;
class AnyX86NoCfCheckAttr;
class ArcWeakrefUnavailableAttr;
class ArgumentWithTypeTagAttr;
class ArmBuiltinAliasAttr;
class ArtificialAttr;
class AsmLabelAttr;
class AssertCapabilityAttr;
class AssertExclusiveLockAttr;
class AssertSharedLockAttr;
class AssumeAlignedAttr;
class AssumptionAttr;
class Attr;
class AvailabilityAttr;
class BPFPreserveAccessIndexAttr;
class BTFDeclTagAttr;
class BlocksAttr;
class BuiltinAttr;
class C11NoReturnAttr;
class CDeclAttr;
class CFAuditedTransferAttr;
class CFConsumedAttr;
class CFGuardAttr;
class CFICanonicalJumpTableAttr;
class CFReturnsNotRetainedAttr;
class CFReturnsRetainedAttr;
class CFUnknownTransferAttr;
class CPUDispatchAttr;
class CPUSpecificAttr;
class CUDAConstantAttr;
class CUDADeviceAttr;
class CUDADeviceBuiltinSurfaceTypeAttr;
class CUDADeviceBuiltinTextureTypeAttr;
class CUDAGlobalAttr;
class CUDAHostAttr;
class CUDAInvalidTargetAttr;
class CUDALaunchBoundsAttr;
class CUDASharedAttr;
class CXX11NoReturnAttr;
class CallableWhenAttr;
class CallbackAttr;
class CapabilityAttr;
class CapturedRecordAttr;
class CarriesDependencyAttr;
class CleanupAttr;
class CmseNSEntryAttr;
class CodeSegAttr;
class ColdAttr;
class CommonAttr;
class ConstAttr;
class ConstInitAttr;
class ConstructorAttr;
class ConsumableAttr;
class ConsumableAutoCastAttr;
class ConsumableSetOnReadAttr;
class ConvergentAttr;
class DLLExportAttr;
class DLLExportStaticLocalAttr;
class DLLImportAttr;
class DLLImportStaticLocalAttr;
class DeprecatedAttr;
class DestructorAttr;
class DiagnoseAsBuiltinAttr;
class DiagnoseIfAttr;
class DisableSanitizerInstrumentationAttr;
class DisableTailCallsAttr;
class EmptyBasesAttr;
class EnableIfAttr;
class EnforceTCBAttr;
class EnforceTCBLeafAttr;
class EnumExtensibilityAttr;
class ErrorAttr;
class ExcludeFromExplicitInstantiationAttr;
class ExclusiveTrylockFunctionAttr;
class ExternalSourceSymbolAttr;
class FastCallAttr;
class FinalAttr;
class FlagEnumAttr;
class FlattenAttr;
class FormatArgAttr;
class FormatAttr;
class FunctionReturnThunksAttr;
class GNUInlineAttr;
class GuardedByAttr;
class GuardedVarAttr;
class HIPManagedAttr;
class HLSLNumThreadsAttr;
class HLSLSV_GroupIndexAttr;
class HLSLShaderAttr;
class HotAttr;
class IBActionAttr;
class IBOutletAttr;
class IBOutletCollectionAttr;
class InheritableAttr;
class InitPriorityAttr;
class IntelOclBiccAttr;
class InternalLinkageAttr;
class LTOVisibilityPublicAttr;
class LayoutVersionAttr;
class LeafAttr;
class LifetimeBoundAttr;
class LockReturnedAttr;
class LocksExcludedAttr;
class M68kInterruptAttr;
class MIGServerRoutineAttr;
class MSABIAttr;
class MSAllocatorAttr;
class MSInheritanceAttr;
class MSNoVTableAttr;
class MSP430InterruptAttr;
class MSStructAttr;
class MSVtorDispAttr;
class MaxFieldAlignmentAttr;
class MayAliasAttr;
class MicroMipsAttr;
class MinSizeAttr;
class MinVectorWidthAttr;
class Mips16Attr;
class MipsInterruptAttr;
class MipsLongCallAttr;
class MipsShortCallAttr;
class NSConsumedAttr;
class NSConsumesSelfAttr;
class NSErrorDomainAttr;
class NSReturnsAutoreleasedAttr;
class NSReturnsNotRetainedAttr;
class NSReturnsRetainedAttr;
class NakedAttr;
class NoAliasAttr;
class NoCommonAttr;
class NoDebugAttr;
class NoDestroyAttr;
class NoDuplicateAttr;
class NoInlineAttr;
class NoInstrumentFunctionAttr;
class NoMergeAttr;
class NoMicroMipsAttr;
class NoMips16Attr;
class NoProfileFunctionAttr;
class NoRandomizeLayoutAttr;
class NoReturnAttr;
class NoSanitizeAttr;
class NoSpeculativeLoadHardeningAttr;
class NoSplitStackAttr;
class NoStackProtectorAttr;
class NoThreadSafetyAnalysisAttr;
class NoThrowAttr;
class NoUniqueAddressAttr;
class NonNullAttr;
class NotTailCalledAttr;
class OMPAllocateDeclAttr;
class OMPCaptureNoInitAttr;
class OMPDeclareTargetDeclAttr;
class OMPDeclareVariantAttr;
class OMPThreadPrivateDeclAttr;
class OSConsumedAttr;
class OSConsumesThisAttr;
class OSReturnsNotRetainedAttr;
class OSReturnsRetainedAttr;
class OSReturnsRetainedOnNonZeroAttr;
class OSReturnsRetainedOnZeroAttr;
class ObjCBridgeAttr;
class ObjCBridgeMutableAttr;
class ObjCBridgeRelatedAttr;
class ObjCExceptionAttr;
class ObjCExplicitProtocolImplAttr;
class ObjCExternallyRetainedAttr;
class ObjCIndependentClassAttr;
class ObjCMethodFamilyAttr;
class ObjCNSObjectAttr;
class ObjCOwnershipAttr;
class ObjCPreciseLifetimeAttr;
class ObjCRequiresPropertyDefsAttr;
class ObjCRequiresSuperAttr;
class ObjCReturnsInnerPointerAttr;
class ObjCRootClassAttr;
class ObjCSubclassingRestrictedAttr;
class OpenCLIntelReqdSubGroupSizeAttr;
class OpenCLKernelAttr;
class OptimizeNoneAttr;
class OverrideAttr;
class OwnerAttr;
class OwnershipAttr;
class PackedAttr;
class ParamTypestateAttr;
class PascalAttr;
class PassObjectSizeAttr;
class PatchableFunctionEntryAttr;
class PcsAttr;
class PointerAttr;
class PragmaClangBSSSectionAttr;
class PragmaClangDataSectionAttr;
class PragmaClangRelroSectionAttr;
class PragmaClangRodataSectionAttr;
class PragmaClangTextSectionAttr;
class PreferredNameAttr;
class PreserveAllAttr;
class PreserveMostAttr;
class PtGuardedByAttr;
class PtGuardedVarAttr;
class PureAttr;
class RISCVInterruptAttr;
class RandomizeLayoutAttr;
class RegCallAttr;
class ReinitializesAttr;
class ReleaseCapabilityAttr;
class ReleaseHandleAttr;
class ReqdWorkGroupSizeAttr;
class RequiresCapabilityAttr;
class RestrictAttr;
class RetainAttr;
class ReturnTypestateAttr;
class ReturnsNonNullAttr;
class ReturnsTwiceAttr;
class SYCLKernelAttr;
class SYCLSpecialClassAttr;
class ScopedLockableAttr;
class SectionAttr;
class SelectAnyAttr;
class SentinelAttr;
class SetTypestateAttr;
class SharedTrylockFunctionAttr;
class SpeculativeLoadHardeningAttr;
class StandaloneDebugAttr;
class StdCallAttr;
class StrictFPAttr;
class SwiftAsyncAttr;
class SwiftAsyncCallAttr;
class SwiftAsyncContextAttr;
class SwiftAsyncErrorAttr;
class SwiftAsyncNameAttr;
class SwiftAttrAttr;
class SwiftBridgeAttr;
class SwiftBridgedTypedefAttr;
class SwiftCallAttr;
class SwiftContextAttr;
class SwiftErrorAttr;
class SwiftErrorResultAttr;
class SwiftIndirectResultAttr;
class SwiftNameAttr;
class SwiftNewTypeAttr;
class SwiftPrivateAttr;
class SysVABIAttr;
class TLSModelAttr;
class TargetAttr;
class TargetClonesAttr;
class TestTypestateAttr;
class ThisCallAttr;
class Token;
class TransparentUnionAttr;
class TrivialABIAttr;
class TryAcquireCapabilityAttr;
class TypeTagForDatatypeAttr;
class TypeVisibilityAttr;
class UnavailableAttr;
class UninitializedAttr;
class UnusedAttr;
class UseHandleAttr;
class UsedAttr;
class UsingIfExistsAttr;
class UuidAttr;
class VecReturnAttr;
class VecTypeHintAttr;
class VectorCallAttr;
class VisibilityAttr;
class WarnUnusedAttr;
class WarnUnusedResultAttr;
class WeakAttr;
class WeakImportAttr;
class WeakRefAttr;
class WebAssemblyExportNameAttr;
class WebAssemblyImportModuleAttr;
class WebAssemblyImportNameAttr;
class WorkGroupSizeHintAttr;
class X86ForceAlignArgPointerAttr;
class XRayInstrumentAttr;
class XRayLogArgsAttr;
class ZeroCallUsedRegsAttr;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class InheritableAttr : public Attr {
 private:
  friend class FragmentImpl;
  friend class Attr;
 public:
  static gap::generator<InheritableAttr> in(const Fragment &frag);
  static gap::generator<InheritableAttr> in(const File &file);
  static gap::generator<InheritableAttr> in(const Index &index);
  static gap::generator<InheritableAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<InheritableAttr> by_id(const Index &, EntityId);

  static std::optional<InheritableAttr> from(const Attr &parent);

  inline static std::optional<InheritableAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return InheritableAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  inline static std::optional<InheritableAttr> from(const Reference &r) {
    return InheritableAttr::from(r.as_attribute());
  }

  inline static std::optional<InheritableAttr> from(const TokenContext &t) {
    return InheritableAttr::from(t.as_attribute());
  }

  bool should_inherit_even_if_already_present(void) const;
};

static_assert(sizeof(InheritableAttr) == sizeof(Attr));

#endif
} // namespace mx
