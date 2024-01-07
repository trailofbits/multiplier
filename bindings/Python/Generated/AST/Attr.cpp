// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/Attr.h>

#include <multiplier/AST.h>
#include <multiplier/Fragment.h>
#include <multiplier/Frontend.h>
#include <multiplier/Index.h>
#include <multiplier/IR.h>
#include <multiplier/Re2.h>

#include <cassert>
#include <new>

#include "Binding.h"
#include "Error.h"
#include "Types.h"


#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wc99-extensions"
#pragma GCC diagnostic ignored "-Wunused-function"
namespace {
using T = mx::Attr;

struct O final : public ::PyObject {

  // When initialized, points to `backing_storage`.
  T *data{nullptr};

  // Aligned storage for `T`. Pointed to by `data`.
  alignas(alignof(T)) char backing_storage[sizeof(T)];  
};

inline static O *O_cast(void *obj) noexcept {
  return reinterpret_cast<O *>(obj);
}

inline static const O *O_cast(const void *obj) noexcept {
  return reinterpret_cast<const O *>(obj);
}

inline static T *T_cast(void *obj) noexcept {
  return O_cast(obj)->data;
}

inline static const T *T_cast(const void *obj) noexcept {
  return O_cast(obj)->data;
}

}  // namespace
namespace mx {

namespace {
static PyTypeObject *gType = nullptr;
}  // namespace

template <>
PyTypeObject *PythonBinding<T>::type(void) noexcept {
  return gType;
}

template <>
std::optional<T> PythonBinding<T>::from_python(BorrowedPyObject *obj) noexcept {
  if (!obj) {
    return std::nullopt;
  }

  PyTypeObject * const tp = Py_TYPE(obj);
  if (tp < &(gTypes[5]) || tp >= &(gTypes[385])) {
    return std::nullopt;
  }

  return *T_cast(obj);
}

template <>
SharedPyObject *PythonBinding<T>::to_python(T val) noexcept {
  PyTypeObject *tp = nullptr;
  switch (val.kind()) {
    default:
      assert(false);
      tp = gType;
      break;

    case mx::AlignValueAttr::static_kind():
      tp = &(gTypes[6]);
      break;

    case mx::AliasAttr::static_kind():
      tp = &(gTypes[7]);
      break;

    case mx::AbiTagAttr::static_kind():
      tp = &(gTypes[8]);
      break;

    case mx::SPtrAttr::static_kind():
      tp = &(gTypes[10]);
      break;

    case mx::Ptr64Attr::static_kind():
      tp = &(gTypes[11]);
      break;

    case mx::Ptr32Attr::static_kind():
      tp = &(gTypes[12]);
      break;

    case mx::OpenCLPrivateAddressSpaceAttr::static_kind():
      tp = &(gTypes[13]);
      break;

    case mx::OpenCLLocalAddressSpaceAttr::static_kind():
      tp = &(gTypes[14]);
      break;

    case mx::OpenCLGlobalHostAddressSpaceAttr::static_kind():
      tp = &(gTypes[15]);
      break;

    case mx::OpenCLGlobalDeviceAddressSpaceAttr::static_kind():
      tp = &(gTypes[16]);
      break;

    case mx::OpenCLGlobalAddressSpaceAttr::static_kind():
      tp = &(gTypes[17]);
      break;

    case mx::OpenCLGenericAddressSpaceAttr::static_kind():
      tp = &(gTypes[18]);
      break;

    case mx::OpenCLConstantAddressSpaceAttr::static_kind():
      tp = &(gTypes[19]);
      break;

    case mx::ObjCKindOfAttr::static_kind():
      tp = &(gTypes[20]);
      break;

    case mx::ObjCInertUnsafeUnretainedAttr::static_kind():
      tp = &(gTypes[21]);
      break;

    case mx::ObjCGCAttr::static_kind():
      tp = &(gTypes[22]);
      break;

    case mx::NoDerefAttr::static_kind():
      tp = &(gTypes[23]);
      break;

    case mx::HLSLGroupSharedAddressSpaceAttr::static_kind():
      tp = &(gTypes[24]);
      break;

    case mx::CmseNSCallAttr::static_kind():
      tp = &(gTypes[25]);
      break;

    case mx::BTFTypeTagAttr::static_kind():
      tp = &(gTypes[26]);
      break;

    case mx::ArmStreamingAttr::static_kind():
      tp = &(gTypes[27]);
      break;

    case mx::ArmMveStrictPolymorphismAttr::static_kind():
      tp = &(gTypes[28]);
      break;

    case mx::AnnotateTypeAttr::static_kind():
      tp = &(gTypes[29]);
      break;

    case mx::AddressSpaceAttr::static_kind():
      tp = &(gTypes[30]);
      break;

    case mx::WebAssemblyFuncrefAttr::static_kind():
      tp = &(gTypes[31]);
      break;

    case mx::UPtrAttr::static_kind():
      tp = &(gTypes[32]);
      break;

    case mx::TypeNullableResultAttr::static_kind():
      tp = &(gTypes[33]);
      break;

    case mx::TypeNullableAttr::static_kind():
      tp = &(gTypes[34]);
      break;

    case mx::TypeNullUnspecifiedAttr::static_kind():
      tp = &(gTypes[35]);
      break;

    case mx::TypeNonNullAttr::static_kind():
      tp = &(gTypes[36]);
      break;

    case mx::ThreadAttr::static_kind():
      tp = &(gTypes[37]);
      break;

    case mx::SwiftObjCMembersAttr::static_kind():
      tp = &(gTypes[38]);
      break;

    case mx::OpenCLUnrollHintAttr::static_kind():
      tp = &(gTypes[40]);
      break;

    case mx::MustTailAttr::static_kind():
      tp = &(gTypes[41]);
      break;

    case mx::LikelyAttr::static_kind():
      tp = &(gTypes[42]);
      break;

    case mx::FallThroughAttr::static_kind():
      tp = &(gTypes[43]);
      break;

    case mx::UnlikelyAttr::static_kind():
      tp = &(gTypes[44]);
      break;

    case mx::SuppressAttr::static_kind():
      tp = &(gTypes[45]);
      break;

    case mx::RenderScriptKernelAttr::static_kind():
      tp = &(gTypes[46]);
      break;

    case mx::OverloadableAttr::static_kind():
      tp = &(gTypes[47]);
      break;

    case mx::OpenCLAccessAttr::static_kind():
      tp = &(gTypes[48]);
      break;

    case mx::ObjCRuntimeVisibleAttr::static_kind():
      tp = &(gTypes[49]);
      break;

    case mx::ObjCRuntimeNameAttr::static_kind():
      tp = &(gTypes[50]);
      break;

    case mx::ObjCNonRuntimeProtocolAttr::static_kind():
      tp = &(gTypes[51]);
      break;

    case mx::ObjCNonLazyClassAttr::static_kind():
      tp = &(gTypes[52]);
      break;

    case mx::ObjCDirectMembersAttr::static_kind():
      tp = &(gTypes[53]);
      break;

    case mx::ObjCDirectAttr::static_kind():
      tp = &(gTypes[54]);
      break;

    case mx::ObjCDesignatedInitializerAttr::static_kind():
      tp = &(gTypes[55]);
      break;

    case mx::ObjCClassStubAttr::static_kind():
      tp = &(gTypes[56]);
      break;

    case mx::ObjCBoxableAttr::static_kind():
      tp = &(gTypes[57]);
      break;

    case mx::OMPReferencedVarAttr::static_kind():
      tp = &(gTypes[58]);
      break;

    case mx::OMPDeclareSimdDeclAttr::static_kind():
      tp = &(gTypes[59]);
      break;

    case mx::OMPCaptureKindAttr::static_kind():
      tp = &(gTypes[60]);
      break;

    case mx::NoEscapeAttr::static_kind():
      tp = &(gTypes[61]);
      break;

    case mx::NoBuiltinAttr::static_kind():
      tp = &(gTypes[62]);
      break;

    case mx::ModeAttr::static_kind():
      tp = &(gTypes[63]);
      break;

    case mx::LoopHintAttr::static_kind():
      tp = &(gTypes[64]);
      break;

    case mx::LoaderUninitializedAttr::static_kind():
      tp = &(gTypes[65]);
      break;

    case mx::InitSegAttr::static_kind():
      tp = &(gTypes[66]);
      break;

    case mx::IBOutletCollectionAttr::static_kind():
      tp = &(gTypes[68]);
      break;

    case mx::IBOutletAttr::static_kind():
      tp = &(gTypes[69]);
      break;

    case mx::IBActionAttr::static_kind():
      tp = &(gTypes[70]);
      break;

    case mx::HotAttr::static_kind():
      tp = &(gTypes[71]);
      break;

    case mx::HLSLShaderAttr::static_kind():
      tp = &(gTypes[72]);
      break;

    case mx::HLSLResourceBindingAttr::static_kind():
      tp = &(gTypes[73]);
      break;

    case mx::HLSLResourceAttr::static_kind():
      tp = &(gTypes[74]);
      break;

    case mx::HLSLNumThreadsAttr::static_kind():
      tp = &(gTypes[75]);
      break;

    case mx::HLSLSV_GroupIndexAttr::static_kind():
      tp = &(gTypes[77]);
      break;

    case mx::HLSLSV_DispatchThreadIDAttr::static_kind():
      tp = &(gTypes[78]);
      break;

    case mx::HIPManagedAttr::static_kind():
      tp = &(gTypes[79]);
      break;

    case mx::GuardedVarAttr::static_kind():
      tp = &(gTypes[80]);
      break;

    case mx::GuardedByAttr::static_kind():
      tp = &(gTypes[81]);
      break;

    case mx::GNUInlineAttr::static_kind():
      tp = &(gTypes[82]);
      break;

    case mx::FunctionReturnThunksAttr::static_kind():
      tp = &(gTypes[83]);
      break;

    case mx::FormatAttr::static_kind():
      tp = &(gTypes[84]);
      break;

    case mx::FormatArgAttr::static_kind():
      tp = &(gTypes[85]);
      break;

    case mx::FlattenAttr::static_kind():
      tp = &(gTypes[86]);
      break;

    case mx::FlagEnumAttr::static_kind():
      tp = &(gTypes[87]);
      break;

    case mx::FinalAttr::static_kind():
      tp = &(gTypes[88]);
      break;

    case mx::FastCallAttr::static_kind():
      tp = &(gTypes[89]);
      break;

    case mx::ExternalSourceSymbolAttr::static_kind():
      tp = &(gTypes[90]);
      break;

    case mx::ExclusiveTrylockFunctionAttr::static_kind():
      tp = &(gTypes[91]);
      break;

    case mx::ExcludeFromExplicitInstantiationAttr::static_kind():
      tp = &(gTypes[92]);
      break;

    case mx::ErrorAttr::static_kind():
      tp = &(gTypes[93]);
      break;

    case mx::EnumExtensibilityAttr::static_kind():
      tp = &(gTypes[94]);
      break;

    case mx::EnforceTCBLeafAttr::static_kind():
      tp = &(gTypes[95]);
      break;

    case mx::EnforceTCBAttr::static_kind():
      tp = &(gTypes[96]);
      break;

    case mx::EnableIfAttr::static_kind():
      tp = &(gTypes[97]);
      break;

    case mx::EmptyBasesAttr::static_kind():
      tp = &(gTypes[98]);
      break;

    case mx::DisableTailCallsAttr::static_kind():
      tp = &(gTypes[99]);
      break;

    case mx::DisableSanitizerInstrumentationAttr::static_kind():
      tp = &(gTypes[100]);
      break;

    case mx::DiagnoseIfAttr::static_kind():
      tp = &(gTypes[101]);
      break;

    case mx::DiagnoseAsBuiltinAttr::static_kind():
      tp = &(gTypes[102]);
      break;

    case mx::DestructorAttr::static_kind():
      tp = &(gTypes[103]);
      break;

    case mx::DeprecatedAttr::static_kind():
      tp = &(gTypes[104]);
      break;

    case mx::AlwaysInlineAttr::static_kind():
      tp = &(gTypes[106]);
      break;

    case mx::NoMergeAttr::static_kind():
      tp = &(gTypes[107]);
      break;

    case mx::NoInlineAttr::static_kind():
      tp = &(gTypes[108]);
      break;

    case mx::DLLImportStaticLocalAttr::static_kind():
      tp = &(gTypes[109]);
      break;

    case mx::DLLImportAttr::static_kind():
      tp = &(gTypes[110]);
      break;

    case mx::DLLExportStaticLocalAttr::static_kind():
      tp = &(gTypes[111]);
      break;

    case mx::DLLExportAttr::static_kind():
      tp = &(gTypes[112]);
      break;

    case mx::ConvergentAttr::static_kind():
      tp = &(gTypes[113]);
      break;

    case mx::ConsumableSetOnReadAttr::static_kind():
      tp = &(gTypes[114]);
      break;

    case mx::ConsumableAutoCastAttr::static_kind():
      tp = &(gTypes[115]);
      break;

    case mx::ConsumableAttr::static_kind():
      tp = &(gTypes[116]);
      break;

    case mx::ConstructorAttr::static_kind():
      tp = &(gTypes[117]);
      break;

    case mx::ConstInitAttr::static_kind():
      tp = &(gTypes[118]);
      break;

    case mx::ConstAttr::static_kind():
      tp = &(gTypes[119]);
      break;

    case mx::CommonAttr::static_kind():
      tp = &(gTypes[120]);
      break;

    case mx::ColdAttr::static_kind():
      tp = &(gTypes[121]);
      break;

    case mx::CodeSegAttr::static_kind():
      tp = &(gTypes[122]);
      break;

    case mx::CmseNSEntryAttr::static_kind():
      tp = &(gTypes[123]);
      break;

    case mx::CleanupAttr::static_kind():
      tp = &(gTypes[124]);
      break;

    case mx::CapturedRecordAttr::static_kind():
      tp = &(gTypes[125]);
      break;

    case mx::CapabilityAttr::static_kind():
      tp = &(gTypes[126]);
      break;

    case mx::CallbackAttr::static_kind():
      tp = &(gTypes[127]);
      break;

    case mx::CallableWhenAttr::static_kind():
      tp = &(gTypes[128]);
      break;

    case mx::CXX11NoReturnAttr::static_kind():
      tp = &(gTypes[129]);
      break;

    case mx::CUDASharedAttr::static_kind():
      tp = &(gTypes[130]);
      break;

    case mx::CUDALaunchBoundsAttr::static_kind():
      tp = &(gTypes[131]);
      break;

    case mx::CUDAInvalidTargetAttr::static_kind():
      tp = &(gTypes[132]);
      break;

    case mx::CUDAHostAttr::static_kind():
      tp = &(gTypes[133]);
      break;

    case mx::CUDAGlobalAttr::static_kind():
      tp = &(gTypes[134]);
      break;

    case mx::CUDADeviceBuiltinTextureTypeAttr::static_kind():
      tp = &(gTypes[135]);
      break;

    case mx::CUDADeviceBuiltinSurfaceTypeAttr::static_kind():
      tp = &(gTypes[136]);
      break;

    case mx::CUDADeviceAttr::static_kind():
      tp = &(gTypes[137]);
      break;

    case mx::CUDAConstantAttr::static_kind():
      tp = &(gTypes[138]);
      break;

    case mx::CPUSpecificAttr::static_kind():
      tp = &(gTypes[139]);
      break;

    case mx::CPUDispatchAttr::static_kind():
      tp = &(gTypes[140]);
      break;

    case mx::CFUnknownTransferAttr::static_kind():
      tp = &(gTypes[141]);
      break;

    case mx::CFReturnsRetainedAttr::static_kind():
      tp = &(gTypes[142]);
      break;

    case mx::CFReturnsNotRetainedAttr::static_kind():
      tp = &(gTypes[143]);
      break;

    case mx::CFICanonicalJumpTableAttr::static_kind():
      tp = &(gTypes[144]);
      break;

    case mx::CFGuardAttr::static_kind():
      tp = &(gTypes[145]);
      break;

    case mx::CFAuditedTransferAttr::static_kind():
      tp = &(gTypes[146]);
      break;

    case mx::CDeclAttr::static_kind():
      tp = &(gTypes[147]);
      break;

    case mx::C11NoReturnAttr::static_kind():
      tp = &(gTypes[148]);
      break;

    case mx::BuiltinAttr::static_kind():
      tp = &(gTypes[149]);
      break;

    case mx::BlocksAttr::static_kind():
      tp = &(gTypes[150]);
      break;

    case mx::BTFDeclTagAttr::static_kind():
      tp = &(gTypes[151]);
      break;

    case mx::BPFPreserveAccessIndexAttr::static_kind():
      tp = &(gTypes[152]);
      break;

    case mx::AvailableOnlyInDefaultEvalMethodAttr::static_kind():
      tp = &(gTypes[153]);
      break;

    case mx::AvailabilityAttr::static_kind():
      tp = &(gTypes[154]);
      break;

    case mx::AssumptionAttr::static_kind():
      tp = &(gTypes[155]);
      break;

    case mx::AssumeAlignedAttr::static_kind():
      tp = &(gTypes[156]);
      break;

    case mx::AssertSharedLockAttr::static_kind():
      tp = &(gTypes[157]);
      break;

    case mx::AssertExclusiveLockAttr::static_kind():
      tp = &(gTypes[158]);
      break;

    case mx::AssertCapabilityAttr::static_kind():
      tp = &(gTypes[159]);
      break;

    case mx::AsmLabelAttr::static_kind():
      tp = &(gTypes[160]);
      break;

    case mx::ArtificialAttr::static_kind():
      tp = &(gTypes[161]);
      break;

    case mx::ArmBuiltinAliasAttr::static_kind():
      tp = &(gTypes[162]);
      break;

    case mx::ArgumentWithTypeTagAttr::static_kind():
      tp = &(gTypes[163]);
      break;

    case mx::ArcWeakrefUnavailableAttr::static_kind():
      tp = &(gTypes[164]);
      break;

    case mx::AnyX86NoCfCheckAttr::static_kind():
      tp = &(gTypes[165]);
      break;

    case mx::AnyX86NoCallerSavedRegistersAttr::static_kind():
      tp = &(gTypes[166]);
      break;

    case mx::AnyX86InterruptAttr::static_kind():
      tp = &(gTypes[167]);
      break;

    case mx::AnalyzerNoReturnAttr::static_kind():
      tp = &(gTypes[168]);
      break;

    case mx::AlwaysDestroyAttr::static_kind():
      tp = &(gTypes[169]);
      break;

    case mx::AllocSizeAttr::static_kind():
      tp = &(gTypes[170]);
      break;

    case mx::AllocAlignAttr::static_kind():
      tp = &(gTypes[171]);
      break;

    case mx::AlignedAttr::static_kind():
      tp = &(gTypes[172]);
      break;

    case mx::AlignNaturalAttr::static_kind():
      tp = &(gTypes[173]);
      break;

    case mx::AlignMac68kAttr::static_kind():
      tp = &(gTypes[174]);
      break;

    case mx::AcquiredBeforeAttr::static_kind():
      tp = &(gTypes[175]);
      break;

    case mx::AcquiredAfterAttr::static_kind():
      tp = &(gTypes[176]);
      break;

    case mx::AcquireHandleAttr::static_kind():
      tp = &(gTypes[177]);
      break;

    case mx::AcquireCapabilityAttr::static_kind():
      tp = &(gTypes[178]);
      break;

    case mx::AVRSignalAttr::static_kind():
      tp = &(gTypes[179]);
      break;

    case mx::AVRInterruptAttr::static_kind():
      tp = &(gTypes[180]);
      break;

    case mx::ARMInterruptAttr::static_kind():
      tp = &(gTypes[181]);
      break;

    case mx::AMDGPUWavesPerEUAttr::static_kind():
      tp = &(gTypes[182]);
      break;

    case mx::AMDGPUNumVGPRAttr::static_kind():
      tp = &(gTypes[183]);
      break;

    case mx::AMDGPUNumSGPRAttr::static_kind():
      tp = &(gTypes[184]);
      break;

    case mx::AMDGPUKernelCallAttr::static_kind():
      tp = &(gTypes[185]);
      break;

    case mx::AMDGPUFlatWorkGroupSizeAttr::static_kind():
      tp = &(gTypes[186]);
      break;

    case mx::AArch64VectorPcsAttr::static_kind():
      tp = &(gTypes[187]);
      break;

    case mx::AArch64SVEPcsAttr::static_kind():
      tp = &(gTypes[188]);
      break;

    case mx::ZeroCallUsedRegsAttr::static_kind():
      tp = &(gTypes[189]);
      break;

    case mx::XRayLogArgsAttr::static_kind():
      tp = &(gTypes[190]);
      break;

    case mx::XRayInstrumentAttr::static_kind():
      tp = &(gTypes[191]);
      break;

    case mx::X86ForceAlignArgPointerAttr::static_kind():
      tp = &(gTypes[192]);
      break;

    case mx::WorkGroupSizeHintAttr::static_kind():
      tp = &(gTypes[193]);
      break;

    case mx::WebAssemblyImportNameAttr::static_kind():
      tp = &(gTypes[194]);
      break;

    case mx::WebAssemblyImportModuleAttr::static_kind():
      tp = &(gTypes[195]);
      break;

    case mx::WebAssemblyExportNameAttr::static_kind():
      tp = &(gTypes[196]);
      break;

    case mx::WeakRefAttr::static_kind():
      tp = &(gTypes[197]);
      break;

    case mx::WeakImportAttr::static_kind():
      tp = &(gTypes[198]);
      break;

    case mx::WeakAttr::static_kind():
      tp = &(gTypes[199]);
      break;

    case mx::WarnUnusedResultAttr::static_kind():
      tp = &(gTypes[200]);
      break;

    case mx::WarnUnusedAttr::static_kind():
      tp = &(gTypes[201]);
      break;

    case mx::VisibilityAttr::static_kind():
      tp = &(gTypes[202]);
      break;

    case mx::VectorCallAttr::static_kind():
      tp = &(gTypes[203]);
      break;

    case mx::VecTypeHintAttr::static_kind():
      tp = &(gTypes[204]);
      break;

    case mx::VecReturnAttr::static_kind():
      tp = &(gTypes[205]);
      break;

    case mx::UuidAttr::static_kind():
      tp = &(gTypes[206]);
      break;

    case mx::UsingIfExistsAttr::static_kind():
      tp = &(gTypes[207]);
      break;

    case mx::UsedAttr::static_kind():
      tp = &(gTypes[208]);
      break;

    case mx::UnusedAttr::static_kind():
      tp = &(gTypes[209]);
      break;

    case mx::UnsafeBufferUsageAttr::static_kind():
      tp = &(gTypes[210]);
      break;

    case mx::UninitializedAttr::static_kind():
      tp = &(gTypes[211]);
      break;

    case mx::UnavailableAttr::static_kind():
      tp = &(gTypes[212]);
      break;

    case mx::TypeVisibilityAttr::static_kind():
      tp = &(gTypes[213]);
      break;

    case mx::TypeTagForDatatypeAttr::static_kind():
      tp = &(gTypes[214]);
      break;

    case mx::TryAcquireCapabilityAttr::static_kind():
      tp = &(gTypes[215]);
      break;

    case mx::TrivialABIAttr::static_kind():
      tp = &(gTypes[216]);
      break;

    case mx::TransparentUnionAttr::static_kind():
      tp = &(gTypes[217]);
      break;

    case mx::ThisCallAttr::static_kind():
      tp = &(gTypes[218]);
      break;

    case mx::TestTypestateAttr::static_kind():
      tp = &(gTypes[219]);
      break;

    case mx::TargetVersionAttr::static_kind():
      tp = &(gTypes[220]);
      break;

    case mx::TargetClonesAttr::static_kind():
      tp = &(gTypes[221]);
      break;

    case mx::TargetAttr::static_kind():
      tp = &(gTypes[222]);
      break;

    case mx::TLSModelAttr::static_kind():
      tp = &(gTypes[223]);
      break;

    case mx::SysVABIAttr::static_kind():
      tp = &(gTypes[224]);
      break;

    case mx::SwiftPrivateAttr::static_kind():
      tp = &(gTypes[225]);
      break;

    case mx::SwiftNewTypeAttr::static_kind():
      tp = &(gTypes[226]);
      break;

    case mx::SwiftNameAttr::static_kind():
      tp = &(gTypes[227]);
      break;

    case mx::SwiftErrorAttr::static_kind():
      tp = &(gTypes[228]);
      break;

    case mx::SwiftCallAttr::static_kind():
      tp = &(gTypes[229]);
      break;

    case mx::SwiftBridgedTypedefAttr::static_kind():
      tp = &(gTypes[230]);
      break;

    case mx::SwiftBridgeAttr::static_kind():
      tp = &(gTypes[231]);
      break;

    case mx::SwiftAttrAttr::static_kind():
      tp = &(gTypes[232]);
      break;

    case mx::SwiftAsyncNameAttr::static_kind():
      tp = &(gTypes[233]);
      break;

    case mx::SwiftAsyncErrorAttr::static_kind():
      tp = &(gTypes[234]);
      break;

    case mx::SwiftAsyncCallAttr::static_kind():
      tp = &(gTypes[235]);
      break;

    case mx::SwiftAsyncAttr::static_kind():
      tp = &(gTypes[236]);
      break;

    case mx::StrictGuardStackCheckAttr::static_kind():
      tp = &(gTypes[237]);
      break;

    case mx::StrictFPAttr::static_kind():
      tp = &(gTypes[238]);
      break;

    case mx::StdCallAttr::static_kind():
      tp = &(gTypes[239]);
      break;

    case mx::StandaloneDebugAttr::static_kind():
      tp = &(gTypes[240]);
      break;

    case mx::SpeculativeLoadHardeningAttr::static_kind():
      tp = &(gTypes[241]);
      break;

    case mx::SharedTrylockFunctionAttr::static_kind():
      tp = &(gTypes[242]);
      break;

    case mx::SetTypestateAttr::static_kind():
      tp = &(gTypes[243]);
      break;

    case mx::SentinelAttr::static_kind():
      tp = &(gTypes[244]);
      break;

    case mx::SelectAnyAttr::static_kind():
      tp = &(gTypes[245]);
      break;

    case mx::SectionAttr::static_kind():
      tp = &(gTypes[246]);
      break;

    case mx::ScopedLockableAttr::static_kind():
      tp = &(gTypes[247]);
      break;

    case mx::SYCLSpecialClassAttr::static_kind():
      tp = &(gTypes[248]);
      break;

    case mx::SYCLKernelAttr::static_kind():
      tp = &(gTypes[249]);
      break;

    case mx::ReturnsTwiceAttr::static_kind():
      tp = &(gTypes[250]);
      break;

    case mx::ReturnsNonNullAttr::static_kind():
      tp = &(gTypes[251]);
      break;

    case mx::ReturnTypestateAttr::static_kind():
      tp = &(gTypes[252]);
      break;

    case mx::RetainAttr::static_kind():
      tp = &(gTypes[253]);
      break;

    case mx::RestrictAttr::static_kind():
      tp = &(gTypes[254]);
      break;

    case mx::RequiresCapabilityAttr::static_kind():
      tp = &(gTypes[255]);
      break;

    case mx::ReqdWorkGroupSizeAttr::static_kind():
      tp = &(gTypes[256]);
      break;

    case mx::ReleaseCapabilityAttr::static_kind():
      tp = &(gTypes[257]);
      break;

    case mx::ReinitializesAttr::static_kind():
      tp = &(gTypes[258]);
      break;

    case mx::RegCallAttr::static_kind():
      tp = &(gTypes[259]);
      break;

    case mx::ReadOnlyPlacementAttr::static_kind():
      tp = &(gTypes[260]);
      break;

    case mx::RandomizeLayoutAttr::static_kind():
      tp = &(gTypes[261]);
      break;

    case mx::RISCVInterruptAttr::static_kind():
      tp = &(gTypes[262]);
      break;

    case mx::PureAttr::static_kind():
      tp = &(gTypes[263]);
      break;

    case mx::PtGuardedVarAttr::static_kind():
      tp = &(gTypes[264]);
      break;

    case mx::PtGuardedByAttr::static_kind():
      tp = &(gTypes[265]);
      break;

    case mx::PreserveMostAttr::static_kind():
      tp = &(gTypes[266]);
      break;

    case mx::PreserveAllAttr::static_kind():
      tp = &(gTypes[267]);
      break;

    case mx::PreferredNameAttr::static_kind():
      tp = &(gTypes[268]);
      break;

    case mx::PragmaClangTextSectionAttr::static_kind():
      tp = &(gTypes[269]);
      break;

    case mx::PragmaClangRodataSectionAttr::static_kind():
      tp = &(gTypes[270]);
      break;

    case mx::PragmaClangRelroSectionAttr::static_kind():
      tp = &(gTypes[271]);
      break;

    case mx::PragmaClangDataSectionAttr::static_kind():
      tp = &(gTypes[272]);
      break;

    case mx::PragmaClangBSSSectionAttr::static_kind():
      tp = &(gTypes[273]);
      break;

    case mx::PointerAttr::static_kind():
      tp = &(gTypes[274]);
      break;

    case mx::PcsAttr::static_kind():
      tp = &(gTypes[275]);
      break;

    case mx::PatchableFunctionEntryAttr::static_kind():
      tp = &(gTypes[276]);
      break;

    case mx::PascalAttr::static_kind():
      tp = &(gTypes[277]);
      break;

    case mx::ParamTypestateAttr::static_kind():
      tp = &(gTypes[278]);
      break;

    case mx::PackedAttr::static_kind():
      tp = &(gTypes[279]);
      break;

    case mx::OwnershipAttr::static_kind():
      tp = &(gTypes[280]);
      break;

    case mx::OwnerAttr::static_kind():
      tp = &(gTypes[281]);
      break;

    case mx::OverrideAttr::static_kind():
      tp = &(gTypes[282]);
      break;

    case mx::OptimizeNoneAttr::static_kind():
      tp = &(gTypes[283]);
      break;

    case mx::OpenCLKernelAttr::static_kind():
      tp = &(gTypes[284]);
      break;

    case mx::OpenCLIntelReqdSubGroupSizeAttr::static_kind():
      tp = &(gTypes[285]);
      break;

    case mx::ObjCSubclassingRestrictedAttr::static_kind():
      tp = &(gTypes[286]);
      break;

    case mx::ObjCRootClassAttr::static_kind():
      tp = &(gTypes[287]);
      break;

    case mx::ObjCReturnsInnerPointerAttr::static_kind():
      tp = &(gTypes[288]);
      break;

    case mx::ObjCRequiresSuperAttr::static_kind():
      tp = &(gTypes[289]);
      break;

    case mx::ObjCRequiresPropertyDefsAttr::static_kind():
      tp = &(gTypes[290]);
      break;

    case mx::ObjCPreciseLifetimeAttr::static_kind():
      tp = &(gTypes[291]);
      break;

    case mx::ObjCOwnershipAttr::static_kind():
      tp = &(gTypes[292]);
      break;

    case mx::ObjCNSObjectAttr::static_kind():
      tp = &(gTypes[293]);
      break;

    case mx::ObjCMethodFamilyAttr::static_kind():
      tp = &(gTypes[294]);
      break;

    case mx::ObjCIndependentClassAttr::static_kind():
      tp = &(gTypes[295]);
      break;

    case mx::ObjCExternallyRetainedAttr::static_kind():
      tp = &(gTypes[296]);
      break;

    case mx::ObjCExplicitProtocolImplAttr::static_kind():
      tp = &(gTypes[297]);
      break;

    case mx::ObjCExceptionAttr::static_kind():
      tp = &(gTypes[298]);
      break;

    case mx::ObjCBridgeRelatedAttr::static_kind():
      tp = &(gTypes[299]);
      break;

    case mx::ObjCBridgeMutableAttr::static_kind():
      tp = &(gTypes[300]);
      break;

    case mx::ObjCBridgeAttr::static_kind():
      tp = &(gTypes[301]);
      break;

    case mx::OSReturnsRetainedOnZeroAttr::static_kind():
      tp = &(gTypes[302]);
      break;

    case mx::OSReturnsRetainedOnNonZeroAttr::static_kind():
      tp = &(gTypes[303]);
      break;

    case mx::OSReturnsRetainedAttr::static_kind():
      tp = &(gTypes[304]);
      break;

    case mx::OSReturnsNotRetainedAttr::static_kind():
      tp = &(gTypes[305]);
      break;

    case mx::OSConsumesThisAttr::static_kind():
      tp = &(gTypes[306]);
      break;

    case mx::OMPThreadPrivateDeclAttr::static_kind():
      tp = &(gTypes[307]);
      break;

    case mx::OMPDeclareVariantAttr::static_kind():
      tp = &(gTypes[308]);
      break;

    case mx::OMPDeclareTargetDeclAttr::static_kind():
      tp = &(gTypes[309]);
      break;

    case mx::OMPCaptureNoInitAttr::static_kind():
      tp = &(gTypes[310]);
      break;

    case mx::OMPAllocateDeclAttr::static_kind():
      tp = &(gTypes[311]);
      break;

    case mx::NotTailCalledAttr::static_kind():
      tp = &(gTypes[312]);
      break;

    case mx::NoUwtableAttr::static_kind():
      tp = &(gTypes[313]);
      break;

    case mx::NoUniqueAddressAttr::static_kind():
      tp = &(gTypes[314]);
      break;

    case mx::NoThrowAttr::static_kind():
      tp = &(gTypes[315]);
      break;

    case mx::NoThreadSafetyAnalysisAttr::static_kind():
      tp = &(gTypes[316]);
      break;

    case mx::NoStackProtectorAttr::static_kind():
      tp = &(gTypes[317]);
      break;

    case mx::NoSplitStackAttr::static_kind():
      tp = &(gTypes[318]);
      break;

    case mx::NoSpeculativeLoadHardeningAttr::static_kind():
      tp = &(gTypes[319]);
      break;

    case mx::NoSanitizeAttr::static_kind():
      tp = &(gTypes[320]);
      break;

    case mx::NoReturnAttr::static_kind():
      tp = &(gTypes[321]);
      break;

    case mx::NoRandomizeLayoutAttr::static_kind():
      tp = &(gTypes[322]);
      break;

    case mx::NoProfileFunctionAttr::static_kind():
      tp = &(gTypes[323]);
      break;

    case mx::NoMips16Attr::static_kind():
      tp = &(gTypes[324]);
      break;

    case mx::NoMicroMipsAttr::static_kind():
      tp = &(gTypes[325]);
      break;

    case mx::NoInstrumentFunctionAttr::static_kind():
      tp = &(gTypes[326]);
      break;

    case mx::NoDuplicateAttr::static_kind():
      tp = &(gTypes[327]);
      break;

    case mx::NoDestroyAttr::static_kind():
      tp = &(gTypes[328]);
      break;

    case mx::NoDebugAttr::static_kind():
      tp = &(gTypes[329]);
      break;

    case mx::NoCommonAttr::static_kind():
      tp = &(gTypes[330]);
      break;

    case mx::NoAliasAttr::static_kind():
      tp = &(gTypes[331]);
      break;

    case mx::NakedAttr::static_kind():
      tp = &(gTypes[332]);
      break;

    case mx::NVPTXKernelAttr::static_kind():
      tp = &(gTypes[333]);
      break;

    case mx::NSReturnsRetainedAttr::static_kind():
      tp = &(gTypes[334]);
      break;

    case mx::NSReturnsNotRetainedAttr::static_kind():
      tp = &(gTypes[335]);
      break;

    case mx::NSReturnsAutoreleasedAttr::static_kind():
      tp = &(gTypes[336]);
      break;

    case mx::NSErrorDomainAttr::static_kind():
      tp = &(gTypes[337]);
      break;

    case mx::NSConsumesSelfAttr::static_kind():
      tp = &(gTypes[338]);
      break;

    case mx::MipsShortCallAttr::static_kind():
      tp = &(gTypes[339]);
      break;

    case mx::MipsLongCallAttr::static_kind():
      tp = &(gTypes[340]);
      break;

    case mx::MipsInterruptAttr::static_kind():
      tp = &(gTypes[341]);
      break;

    case mx::Mips16Attr::static_kind():
      tp = &(gTypes[342]);
      break;

    case mx::MinVectorWidthAttr::static_kind():
      tp = &(gTypes[343]);
      break;

    case mx::MinSizeAttr::static_kind():
      tp = &(gTypes[344]);
      break;

    case mx::MicroMipsAttr::static_kind():
      tp = &(gTypes[345]);
      break;

    case mx::MaybeUndefAttr::static_kind():
      tp = &(gTypes[346]);
      break;

    case mx::MayAliasAttr::static_kind():
      tp = &(gTypes[347]);
      break;

    case mx::MaxFieldAlignmentAttr::static_kind():
      tp = &(gTypes[348]);
      break;

    case mx::MSVtorDispAttr::static_kind():
      tp = &(gTypes[349]);
      break;

    case mx::MSStructAttr::static_kind():
      tp = &(gTypes[350]);
      break;

    case mx::MSP430InterruptAttr::static_kind():
      tp = &(gTypes[351]);
      break;

    case mx::MSNoVTableAttr::static_kind():
      tp = &(gTypes[352]);
      break;

    case mx::MSInheritanceAttr::static_kind():
      tp = &(gTypes[353]);
      break;

    case mx::MSAllocatorAttr::static_kind():
      tp = &(gTypes[354]);
      break;

    case mx::MSABIAttr::static_kind():
      tp = &(gTypes[355]);
      break;

    case mx::MIGServerRoutineAttr::static_kind():
      tp = &(gTypes[356]);
      break;

    case mx::M68kInterruptAttr::static_kind():
      tp = &(gTypes[357]);
      break;

    case mx::LocksExcludedAttr::static_kind():
      tp = &(gTypes[358]);
      break;

    case mx::LockReturnedAttr::static_kind():
      tp = &(gTypes[359]);
      break;

    case mx::LifetimeBoundAttr::static_kind():
      tp = &(gTypes[360]);
      break;

    case mx::LeafAttr::static_kind():
      tp = &(gTypes[361]);
      break;

    case mx::LayoutVersionAttr::static_kind():
      tp = &(gTypes[362]);
      break;

    case mx::LTOVisibilityPublicAttr::static_kind():
      tp = &(gTypes[363]);
      break;

    case mx::InternalLinkageAttr::static_kind():
      tp = &(gTypes[364]);
      break;

    case mx::IntelOclBiccAttr::static_kind():
      tp = &(gTypes[365]);
      break;

    case mx::InitPriorityAttr::static_kind():
      tp = &(gTypes[366]);
      break;

    case mx::CarriesDependencyAttr::static_kind():
      tp = &(gTypes[368]);
      break;

    case mx::CFConsumedAttr::static_kind():
      tp = &(gTypes[369]);
      break;

    case mx::AnnotateAttr::static_kind():
      tp = &(gTypes[370]);
      break;

    case mx::UseHandleAttr::static_kind():
      tp = &(gTypes[371]);
      break;

    case mx::ReleaseHandleAttr::static_kind():
      tp = &(gTypes[372]);
      break;

    case mx::PassObjectSizeAttr::static_kind():
      tp = &(gTypes[373]);
      break;

    case mx::SwiftIndirectResultAttr::static_kind():
      tp = &(gTypes[375]);
      break;

    case mx::SwiftErrorResultAttr::static_kind():
      tp = &(gTypes[376]);
      break;

    case mx::SwiftContextAttr::static_kind():
      tp = &(gTypes[377]);
      break;

    case mx::SwiftAsyncContextAttr::static_kind():
      tp = &(gTypes[378]);
      break;

    case mx::OSConsumedAttr::static_kind():
      tp = &(gTypes[379]);
      break;

    case mx::NonNullAttr::static_kind():
      tp = &(gTypes[380]);
      break;

    case mx::NSConsumedAttr::static_kind():
      tp = &(gTypes[381]);
      break;

    case mx::IFuncAttr::static_kind():
      tp = &(gTypes[382]);
      break;

    case mx::CalledOnceAttr::static_kind():
      tp = &(gTypes[383]);
      break;

    case mx::BuiltinAliasAttr::static_kind():
      tp = &(gTypes[384]);
      break;

  }
  auto ret = tp->tp_alloc(tp, 0);
  if (auto obj = O_cast(ret)) {
    obj->data = new (obj->backing_storage) T(std::move(val));
  }
  return ret;
}

namespace {
static PyTypeObject *InitType(void) noexcept;
}  // namespace

template <>
bool PythonBinding<T>::load(BorrowedPyObject *module) noexcept {
  if (!gType) {
    gType = InitType();
    if (!gType) {
      return false;
    }
  }

  auto tp_obj = reinterpret_cast<BorrowedPyObject *>(gType);
  if (0 != PyModule_AddObjectRef(module, "Attr", tp_obj)) {
    return false;
  }

  return true;
}

namespace {
static PyGetSetDef gProperties[] = {
  {
    "id",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->id());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::Attr::id"),
    nullptr,
  },
  {
    "token",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->token());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::Attr::token"),
    nullptr,
  },
  {
    "is_implicit",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->is_implicit());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::Attr::is_implicit"),
    nullptr,
  },
  {
    "is_inherited",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->is_inherited());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::Attr::is_inherited"),
    nullptr,
  },
  {
    "is_late_parsed",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->is_late_parsed());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::Attr::is_late_parsed"),
    nullptr,
  },
  {
    "is_pack_expansion",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->is_pack_expansion());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::Attr::is_pack_expansion"),
    nullptr,
  },
  {
    "kind",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->kind());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::Attr::kind"),
    nullptr,
  },
  {
    "tokens",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->tokens());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::Attr::tokens"),
    nullptr,
  },
  {}  // Sentinel.
};
}  // namespace

namespace {
static PyMethodDef gMethods[] = {
  {
    "static_category",
    reinterpret_cast<PyCFunction>(
        +[] (BorrowedPyObject *, BorrowedPyObject * const *args, int num_args) -> SharedPyObject * {
          (void) args;
          while (num_args == 0) {

            return ::mx::to_python(T::static_category());
          }

          PyErrorStreamer(PyExc_TypeError)
              << "Invalid arguments passed to 'static_category'";
          return nullptr;
        }),
    METH_FASTCALL | METH_STATIC,
    PyDoc_STR("Wrapper for mx::Attr::static_category"),
  },
  {
    "IN",
    reinterpret_cast<PyCFunction>(
        +[] (BorrowedPyObject *, BorrowedPyObject * const *args, int num_args) -> SharedPyObject * {
          (void) args;
          while (num_args == 2) {
            auto arg_0 = ::mx::from_python<mx::Index>(args[0]);
            if (!arg_0.has_value()) {
              break;
            }
            auto arg_1 = ::mx::from_python<std::span<mx::AttrKind>>(args[1]);
            if (!arg_1.has_value()) {
              break;
            }

            return ::mx::to_python(T::in(arg_0.value(), std::move(arg_1.value())));
          }
          while (num_args == 2) {
            auto arg_0 = ::mx::from_python<mx::Fragment>(args[0]);
            if (!arg_0.has_value()) {
              break;
            }
            auto arg_1 = ::mx::from_python<std::span<mx::AttrKind>>(args[1]);
            if (!arg_1.has_value()) {
              break;
            }

            return ::mx::to_python(T::in(arg_0.value(), std::move(arg_1.value())));
          }
          while (num_args == 2) {
            auto arg_0 = ::mx::from_python<mx::File>(args[0]);
            if (!arg_0.has_value()) {
              break;
            }
            auto arg_1 = ::mx::from_python<std::span<mx::AttrKind>>(args[1]);
            if (!arg_1.has_value()) {
              break;
            }

            return ::mx::to_python(T::in(arg_0.value(), std::move(arg_1.value())));
          }
          while (num_args == 1) {
            auto arg_0 = ::mx::from_python<mx::Index>(args[0]);
            if (!arg_0.has_value()) {
              break;
            }

            return ::mx::to_python(T::in(arg_0.value()));
          }
          while (num_args == 1) {
            auto arg_0 = ::mx::from_python<mx::Fragment>(args[0]);
            if (!arg_0.has_value()) {
              break;
            }

            return ::mx::to_python(T::in(arg_0.value()));
          }
          while (num_args == 1) {
            auto arg_0 = ::mx::from_python<mx::File>(args[0]);
            if (!arg_0.has_value()) {
              break;
            }

            return ::mx::to_python(T::in(arg_0.value()));
          }

          PyErrorStreamer(PyExc_TypeError)
              << "Invalid arguments passed to 'IN'";
          return nullptr;
        }),
    METH_FASTCALL | METH_STATIC,
    PyDoc_STR("Wrapper for mx::Attr::in"),
  },
  {
    "containing",
    reinterpret_cast<PyCFunction>(
        +[] (BorrowedPyObject *, BorrowedPyObject * const *args, int num_args) -> SharedPyObject * {
          (void) args;
          while (num_args == 1) {
            auto arg_0 = ::mx::from_python<mx::Token>(args[0]);
            if (!arg_0.has_value()) {
              break;
            }

            return ::mx::to_python(T::containing(arg_0.value()));
          }

          PyErrorStreamer(PyExc_TypeError)
              << "Invalid arguments passed to 'containing'";
          return nullptr;
        }),
    METH_FASTCALL | METH_STATIC,
    PyDoc_STR("Wrapper for mx::Attr::containing"),
  },
  {
    "by_id",
    reinterpret_cast<PyCFunction>(
        +[] (BorrowedPyObject *, BorrowedPyObject * const *args, int num_args) -> SharedPyObject * {
          (void) args;
          while (num_args == 2) {
            auto arg_0 = ::mx::from_python<mx::Index>(args[0]);
            if (!arg_0.has_value()) {
              break;
            }
            auto arg_1 = ::mx::from_python<EntityId>(args[1]);
            if (!arg_1.has_value()) {
              break;
            }

            return ::mx::to_python(T::by_id(arg_0.value(), std::move(arg_1.value())));
          }

          PyErrorStreamer(PyExc_TypeError)
              << "Invalid arguments passed to 'by_id'";
          return nullptr;
        }),
    METH_FASTCALL | METH_STATIC,
    PyDoc_STR("Wrapper for mx::Attr::by_id"),
  },
  {
    "FROM",
    reinterpret_cast<PyCFunction>(
        +[] (BorrowedPyObject *, BorrowedPyObject * const *args, int num_args) -> SharedPyObject * {
          (void) args;
          while (num_args == 1) {
            auto arg_0 = ::mx::from_python<mx::Attr>(args[0]);
            if (!arg_0.has_value()) {
              break;
            }

            return ::mx::to_python(T::from(arg_0.value()));
          }
          while (num_args == 1) {
            auto arg_0 = ::mx::from_python<std::optional<mx::Attr>>(args[0]);
            if (!arg_0.has_value()) {
              break;
            }

            return ::mx::to_python(T::from(arg_0.value()));
          }
          while (num_args == 1) {
            auto arg_0 = ::mx::from_python<mx::Reference>(args[0]);
            if (!arg_0.has_value()) {
              break;
            }

            return ::mx::to_python(T::from(arg_0.value()));
          }
          while (num_args == 1) {
            auto arg_0 = ::mx::from_python<std::variant<std::monostate, mx::Fragment, mx::Decl, mx::Stmt, mx::Attr, mx::Macro, mx::Type, mx::File, mx::Token, mx::TemplateArgument, mx::TemplateParameterList, mx::CXXBaseSpecifier, mx::Designator, mx::Compilation, mx::ir::Operation>>(args[0]);
            if (!arg_0.has_value()) {
              break;
            }

            return ::mx::to_python(T::from(arg_0.value()));
          }
          while (num_args == 1) {
            auto arg_0 = ::mx::from_python<mx::TokenContext>(args[0]);
            if (!arg_0.has_value()) {
              break;
            }

            return ::mx::to_python(T::from(arg_0.value()));
          }

          PyErrorStreamer(PyExc_TypeError)
              << "Invalid arguments passed to 'FROM'";
          return nullptr;
        }),
    METH_FASTCALL | METH_STATIC,
    PyDoc_STR("Wrapper for mx::Attr::from"),
  },
  {
    "contains",
    reinterpret_cast<PyCFunction>(
        +[] (BorrowedPyObject *self, BorrowedPyObject * const *args, int num_args) -> SharedPyObject * {
          T *obj = T_cast(self);
          (void) args;
          while (num_args == 1) {
            auto arg_0 = ::mx::from_python<mx::Token>(args[0]);
            if (!arg_0.has_value()) {
              break;
            }

            return ::mx::to_python(obj->contains(arg_0.value()));
          }

          PyErrorStreamer(PyExc_TypeError)
              << "Invalid arguments passed to 'contains'";
          return nullptr;
        }),
    METH_FASTCALL,
    PyDoc_STR("Wrapper for mx::Attr::contains"),
  },
  {}  // Sentinel.
};
}  // namespace

namespace {

PyTypeObject *InitType(void) noexcept {
  PyTypeObject * const tp = &(gTypes[5]);
  tp->tp_basicsize = sizeof(O);
  tp->tp_itemsize = 0;
  tp->tp_dealloc = [] (::PyObject *obj) {
    if (auto *data = T_cast(obj)) {
      data->~T();
    }
    PyObject_Free(obj);
  };
  tp->tp_name = "multiplier.ast.Attr";
  tp->tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_DISALLOW_INSTANTIATION;
  tp->tp_doc = PyDoc_STR("Wrapper for mx::::Attr");
  tp->tp_as_number = nullptr;
  tp->tp_as_sequence = nullptr;
  tp->tp_as_mapping = nullptr;
  tp->tp_hash = [] (BorrowedPyObject *obj) -> Py_hash_t {
    return static_cast<Py_hash_t>(EntityId(T_cast(obj)->id()).Pack());
  };
  tp->tp_richcompare = [] (BorrowedPyObject *a_obj, BorrowedPyObject *b_obj, int op) -> SharedPyObject * {
    do {
      if (Py_EQ != op && Py_NE != op) {
        break;
      }

      auto a = ::mx::from_python<T>(a_obj);
      if (!a.has_value()) {
        break;
      }

      auto b = ::mx::from_python<T>(b_obj);
      if (!b.has_value()) {
        break;
      }

      auto ret = (a.value() == b.value()) == (Py_EQ == op) ? Py_True : Py_False;
      Py_INCREF(ret);
      return ret;
    } while (false);

    static constexpr const char *kOperators[] = {"<", "<=", "==", "!=", ">", ">="};
    PyErrorStreamer(PyExc_TypeError)
        << "'" << kOperators[op] << "' not supported between instances of '"
        << Py_TYPE(a_obj)->tp_name << "' and '" << Py_TYPE(b_obj)->tp_name << "'";
    return nullptr;
  };
  tp->tp_iter = nullptr;
  tp->tp_methods = gMethods;
  tp->tp_getset = gProperties;
  tp->tp_base = PythonBinding<VariantEntity>::type();
  tp->tp_init = [] (BorrowedPyObject *self, BorrowedPyObject *args, BorrowedPyObject *kwargs) -> int {
    if (kwargs && (!PyMapping_Check(kwargs) || PyMapping_Size(kwargs))) {
      PyErrorStreamer(PyExc_TypeError)
          << "'Attr.__init__' does not take any keyword arguments";
      return -1;
    }

    if (!args || !PySequence_Check(args)) {
      PyErrorStreamer(PyExc_TypeError)
          << "Invalid positional arguments passed to 'Attr.__init__'";
      return -1;
    }

    auto obj = O_cast(self);
    auto num_args = PySequence_Size(args);
    
    (void) obj;
    (void) num_args;
    PyErrorStreamer(PyExc_TypeError)
        << "Class 'Attr' cannot be directly instantiated";
    return -1;

  };
  tp->tp_alloc = PyType_GenericAlloc;
  tp->tp_new = nullptr;

  if (0 != PyType_Ready(tp)) {
    return nullptr;
  }

  return tp;
}

}  // namespace

#pragma GCC diagnostic pop
}  // namespace mx
