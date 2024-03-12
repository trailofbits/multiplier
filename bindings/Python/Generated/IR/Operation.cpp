// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/IR/Operation.h>

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
using T = mx::ir::Operation;

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
  if (tp < &(gTypes[939]) || tp >= &(gTypes[1372])) {
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

    case mx::ir::builtin::ModuleOp::static_kind():
      tp = &(gTypes[941]);
      break;

    case mx::ir::builtin::UnrealizedConversionCastOp::static_kind():
      tp = &(gTypes[942]);
      break;

    case mx::ir::llvm::AShrOp::static_kind():
      tp = &(gTypes[944]);
      break;

    case mx::ir::llvm::AddOp::static_kind():
      tp = &(gTypes[945]);
      break;

    case mx::ir::llvm::AddrSpaceCastOp::static_kind():
      tp = &(gTypes[946]);
      break;

    case mx::ir::llvm::AddressOfOp::static_kind():
      tp = &(gTypes[947]);
      break;

    case mx::ir::llvm::AllocaOp::static_kind():
      tp = &(gTypes[948]);
      break;

    case mx::ir::llvm::AndOp::static_kind():
      tp = &(gTypes[949]);
      break;

    case mx::ir::llvm::AtomicCmpXchgOp::static_kind():
      tp = &(gTypes[950]);
      break;

    case mx::ir::llvm::AtomicRMWOp::static_kind():
      tp = &(gTypes[951]);
      break;

    case mx::ir::llvm::BitcastOp::static_kind():
      tp = &(gTypes[952]);
      break;

    case mx::ir::llvm::BrOp::static_kind():
      tp = &(gTypes[953]);
      break;

    case mx::ir::llvm::CallOp::static_kind():
      tp = &(gTypes[954]);
      break;

    case mx::ir::llvm::ComdatOp::static_kind():
      tp = &(gTypes[955]);
      break;

    case mx::ir::llvm::ComdatSelectorOp::static_kind():
      tp = &(gTypes[956]);
      break;

    case mx::ir::llvm::CondBrOp::static_kind():
      tp = &(gTypes[957]);
      break;

    case mx::ir::llvm::ConstantOp::static_kind():
      tp = &(gTypes[958]);
      break;

    case mx::ir::llvm::ExtractElementOp::static_kind():
      tp = &(gTypes[959]);
      break;

    case mx::ir::llvm::ExtractValueOp::static_kind():
      tp = &(gTypes[960]);
      break;

    case mx::ir::llvm::FAddOp::static_kind():
      tp = &(gTypes[961]);
      break;

    case mx::ir::llvm::FCmpOp::static_kind():
      tp = &(gTypes[962]);
      break;

    case mx::ir::llvm::FDivOp::static_kind():
      tp = &(gTypes[963]);
      break;

    case mx::ir::llvm::FMulOp::static_kind():
      tp = &(gTypes[964]);
      break;

    case mx::ir::llvm::FNegOp::static_kind():
      tp = &(gTypes[965]);
      break;

    case mx::ir::llvm::FPExtOp::static_kind():
      tp = &(gTypes[966]);
      break;

    case mx::ir::llvm::FPToSIOp::static_kind():
      tp = &(gTypes[967]);
      break;

    case mx::ir::llvm::FPToUIOp::static_kind():
      tp = &(gTypes[968]);
      break;

    case mx::ir::llvm::FPTruncOp::static_kind():
      tp = &(gTypes[969]);
      break;

    case mx::ir::llvm::FRemOp::static_kind():
      tp = &(gTypes[970]);
      break;

    case mx::ir::llvm::FSubOp::static_kind():
      tp = &(gTypes[971]);
      break;

    case mx::ir::llvm::FenceOp::static_kind():
      tp = &(gTypes[972]);
      break;

    case mx::ir::llvm::FreezeOp::static_kind():
      tp = &(gTypes[973]);
      break;

    case mx::ir::llvm::GetElementPtrOp::static_kind():
      tp = &(gTypes[974]);
      break;

    case mx::ir::llvm::GlobalCtorsOp::static_kind():
      tp = &(gTypes[975]);
      break;

    case mx::ir::llvm::GlobalDtorsOp::static_kind():
      tp = &(gTypes[976]);
      break;

    case mx::ir::llvm::GlobalOp::static_kind():
      tp = &(gTypes[977]);
      break;

    case mx::ir::llvm::ICmpOp::static_kind():
      tp = &(gTypes[978]);
      break;

    case mx::ir::llvm::InlineAsmOp::static_kind():
      tp = &(gTypes[979]);
      break;

    case mx::ir::llvm::InsertElementOp::static_kind():
      tp = &(gTypes[980]);
      break;

    case mx::ir::llvm::InsertValueOp::static_kind():
      tp = &(gTypes[981]);
      break;

    case mx::ir::llvm::IntToPtrOp::static_kind():
      tp = &(gTypes[982]);
      break;

    case mx::ir::llvm::InvokeOp::static_kind():
      tp = &(gTypes[983]);
      break;

    case mx::ir::llvm::FuncOp::static_kind():
      tp = &(gTypes[984]);
      break;

    case mx::ir::llvm::LShrOp::static_kind():
      tp = &(gTypes[985]);
      break;

    case mx::ir::llvm::LandingpadOp::static_kind():
      tp = &(gTypes[986]);
      break;

    case mx::ir::llvm::LoadOp::static_kind():
      tp = &(gTypes[987]);
      break;

    case mx::ir::llvm::MetadataOp::static_kind():
      tp = &(gTypes[988]);
      break;

    case mx::ir::llvm::MulOp::static_kind():
      tp = &(gTypes[989]);
      break;

    case mx::ir::llvm::NullOp::static_kind():
      tp = &(gTypes[990]);
      break;

    case mx::ir::llvm::OrOp::static_kind():
      tp = &(gTypes[991]);
      break;

    case mx::ir::llvm::PoisonOp::static_kind():
      tp = &(gTypes[992]);
      break;

    case mx::ir::llvm::PtrToIntOp::static_kind():
      tp = &(gTypes[993]);
      break;

    case mx::ir::llvm::ResumeOp::static_kind():
      tp = &(gTypes[994]);
      break;

    case mx::ir::llvm::ReturnOp::static_kind():
      tp = &(gTypes[995]);
      break;

    case mx::ir::llvm::SDivOp::static_kind():
      tp = &(gTypes[996]);
      break;

    case mx::ir::llvm::SExtOp::static_kind():
      tp = &(gTypes[997]);
      break;

    case mx::ir::llvm::SIToFPOp::static_kind():
      tp = &(gTypes[998]);
      break;

    case mx::ir::llvm::SRemOp::static_kind():
      tp = &(gTypes[999]);
      break;

    case mx::ir::llvm::SelectOp::static_kind():
      tp = &(gTypes[1000]);
      break;

    case mx::ir::llvm::ShlOp::static_kind():
      tp = &(gTypes[1001]);
      break;

    case mx::ir::llvm::ShuffleVectorOp::static_kind():
      tp = &(gTypes[1002]);
      break;

    case mx::ir::llvm::StoreOp::static_kind():
      tp = &(gTypes[1003]);
      break;

    case mx::ir::llvm::SubOp::static_kind():
      tp = &(gTypes[1004]);
      break;

    case mx::ir::llvm::SwitchOp::static_kind():
      tp = &(gTypes[1005]);
      break;

    case mx::ir::llvm::TruncOp::static_kind():
      tp = &(gTypes[1006]);
      break;

    case mx::ir::llvm::UDivOp::static_kind():
      tp = &(gTypes[1007]);
      break;

    case mx::ir::llvm::UIToFPOp::static_kind():
      tp = &(gTypes[1008]);
      break;

    case mx::ir::llvm::URemOp::static_kind():
      tp = &(gTypes[1009]);
      break;

    case mx::ir::llvm::UndefOp::static_kind():
      tp = &(gTypes[1010]);
      break;

    case mx::ir::llvm::UnreachableOp::static_kind():
      tp = &(gTypes[1011]);
      break;

    case mx::ir::llvm::XOrOp::static_kind():
      tp = &(gTypes[1012]);
      break;

    case mx::ir::llvm::ZExtOp::static_kind():
      tp = &(gTypes[1013]);
      break;

    case mx::ir::llvm::AbsOp::static_kind():
      tp = &(gTypes[1014]);
      break;

    case mx::ir::llvm::AnnotationOp::static_kind():
      tp = &(gTypes[1015]);
      break;

    case mx::ir::llvm::AssumeOp::static_kind():
      tp = &(gTypes[1016]);
      break;

    case mx::ir::llvm::BitReverseOp::static_kind():
      tp = &(gTypes[1017]);
      break;

    case mx::ir::llvm::ByteSwapOp::static_kind():
      tp = &(gTypes[1018]);
      break;

    case mx::ir::llvm::CallIntrinsicOp::static_kind():
      tp = &(gTypes[1019]);
      break;

    case mx::ir::llvm::CopySignOp::static_kind():
      tp = &(gTypes[1020]);
      break;

    case mx::ir::llvm::CoroAlignOp::static_kind():
      tp = &(gTypes[1021]);
      break;

    case mx::ir::llvm::CoroBeginOp::static_kind():
      tp = &(gTypes[1022]);
      break;

    case mx::ir::llvm::CoroEndOp::static_kind():
      tp = &(gTypes[1023]);
      break;

    case mx::ir::llvm::CoroFreeOp::static_kind():
      tp = &(gTypes[1024]);
      break;

    case mx::ir::llvm::CoroIdOp::static_kind():
      tp = &(gTypes[1025]);
      break;

    case mx::ir::llvm::CoroResumeOp::static_kind():
      tp = &(gTypes[1026]);
      break;

    case mx::ir::llvm::CoroSaveOp::static_kind():
      tp = &(gTypes[1027]);
      break;

    case mx::ir::llvm::CoroSizeOp::static_kind():
      tp = &(gTypes[1028]);
      break;

    case mx::ir::llvm::CoroSuspendOp::static_kind():
      tp = &(gTypes[1029]);
      break;

    case mx::ir::llvm::CosOp::static_kind():
      tp = &(gTypes[1030]);
      break;

    case mx::ir::llvm::CountLeadingZerosOp::static_kind():
      tp = &(gTypes[1031]);
      break;

    case mx::ir::llvm::CountTrailingZerosOp::static_kind():
      tp = &(gTypes[1032]);
      break;

    case mx::ir::llvm::CtPopOp::static_kind():
      tp = &(gTypes[1033]);
      break;

    case mx::ir::llvm::DbgDeclareOp::static_kind():
      tp = &(gTypes[1034]);
      break;

    case mx::ir::llvm::DbgLabelOp::static_kind():
      tp = &(gTypes[1035]);
      break;

    case mx::ir::llvm::DbgValueOp::static_kind():
      tp = &(gTypes[1036]);
      break;

    case mx::ir::llvm::DebugTrapOp::static_kind():
      tp = &(gTypes[1037]);
      break;

    case mx::ir::llvm::EhTypeidForOp::static_kind():
      tp = &(gTypes[1038]);
      break;

    case mx::ir::llvm::Exp2Op::static_kind():
      tp = &(gTypes[1039]);
      break;

    case mx::ir::llvm::ExpOp::static_kind():
      tp = &(gTypes[1040]);
      break;

    case mx::ir::llvm::ExpectOp::static_kind():
      tp = &(gTypes[1041]);
      break;

    case mx::ir::llvm::ExpectWithProbabilityOp::static_kind():
      tp = &(gTypes[1042]);
      break;

    case mx::ir::llvm::FAbsOp::static_kind():
      tp = &(gTypes[1043]);
      break;

    case mx::ir::llvm::FCeilOp::static_kind():
      tp = &(gTypes[1044]);
      break;

    case mx::ir::llvm::FFloorOp::static_kind():
      tp = &(gTypes[1045]);
      break;

    case mx::ir::llvm::FMAOp::static_kind():
      tp = &(gTypes[1046]);
      break;

    case mx::ir::llvm::FMulAddOp::static_kind():
      tp = &(gTypes[1047]);
      break;

    case mx::ir::llvm::FTruncOp::static_kind():
      tp = &(gTypes[1048]);
      break;

    case mx::ir::llvm::FShlOp::static_kind():
      tp = &(gTypes[1049]);
      break;

    case mx::ir::llvm::FShrOp::static_kind():
      tp = &(gTypes[1050]);
      break;

    case mx::ir::llvm::GetActiveLaneMaskOp::static_kind():
      tp = &(gTypes[1051]);
      break;

    case mx::ir::llvm::IsConstantOp::static_kind():
      tp = &(gTypes[1052]);
      break;

    case mx::ir::llvm::IsFPClassOp::static_kind():
      tp = &(gTypes[1053]);
      break;

    case mx::ir::llvm::LifetimeEndOp::static_kind():
      tp = &(gTypes[1054]);
      break;

    case mx::ir::llvm::LifetimeStartOp::static_kind():
      tp = &(gTypes[1055]);
      break;

    case mx::ir::llvm::RoundAndCastToLongLongOp::static_kind():
      tp = &(gTypes[1056]);
      break;

    case mx::ir::llvm::RoundAndCastToNearestLongLongOp::static_kind():
      tp = &(gTypes[1057]);
      break;

    case mx::ir::llvm::Log10Op::static_kind():
      tp = &(gTypes[1058]);
      break;

    case mx::ir::llvm::Log2Op::static_kind():
      tp = &(gTypes[1059]);
      break;

    case mx::ir::llvm::LogOp::static_kind():
      tp = &(gTypes[1060]);
      break;

    case mx::ir::llvm::RoundAndCastToLongOp::static_kind():
      tp = &(gTypes[1061]);
      break;

    case mx::ir::llvm::RoundAndCastToNearestLongOp::static_kind():
      tp = &(gTypes[1062]);
      break;

    case mx::ir::llvm::MaskedLoadOp::static_kind():
      tp = &(gTypes[1063]);
      break;

    case mx::ir::llvm::MaskedStoreOp::static_kind():
      tp = &(gTypes[1064]);
      break;

    case mx::ir::llvm::MatrixColumnMajorLoadOp::static_kind():
      tp = &(gTypes[1065]);
      break;

    case mx::ir::llvm::MatrixColumnMajorStoreOp::static_kind():
      tp = &(gTypes[1066]);
      break;

    case mx::ir::llvm::MatrixMultiplyOp::static_kind():
      tp = &(gTypes[1067]);
      break;

    case mx::ir::llvm::MatrixTransposeOp::static_kind():
      tp = &(gTypes[1068]);
      break;

    case mx::ir::llvm::MaxNumOp::static_kind():
      tp = &(gTypes[1069]);
      break;

    case mx::ir::llvm::MaximumOp::static_kind():
      tp = &(gTypes[1070]);
      break;

    case mx::ir::llvm::MemcpyInlineOp::static_kind():
      tp = &(gTypes[1071]);
      break;

    case mx::ir::llvm::MemcpyOp::static_kind():
      tp = &(gTypes[1072]);
      break;

    case mx::ir::llvm::MemmoveOp::static_kind():
      tp = &(gTypes[1073]);
      break;

    case mx::ir::llvm::MemsetOp::static_kind():
      tp = &(gTypes[1074]);
      break;

    case mx::ir::llvm::MinNumOp::static_kind():
      tp = &(gTypes[1075]);
      break;

    case mx::ir::llvm::MinimumOp::static_kind():
      tp = &(gTypes[1076]);
      break;

    case mx::ir::llvm::RoundToNearbyIntOp::static_kind():
      tp = &(gTypes[1077]);
      break;

    case mx::ir::llvm::NoAliasScopeDeclOp::static_kind():
      tp = &(gTypes[1078]);
      break;

    case mx::ir::llvm::PowIOp::static_kind():
      tp = &(gTypes[1079]);
      break;

    case mx::ir::llvm::FPowOp::static_kind():
      tp = &(gTypes[1080]);
      break;

    case mx::ir::llvm::PrefetchOp::static_kind():
      tp = &(gTypes[1081]);
      break;

    case mx::ir::llvm::PtrAnnotationOp::static_kind():
      tp = &(gTypes[1082]);
      break;

    case mx::ir::llvm::RoundToIntOp::static_kind():
      tp = &(gTypes[1083]);
      break;

    case mx::ir::llvm::RoundToNearestEvenOp::static_kind():
      tp = &(gTypes[1084]);
      break;

    case mx::ir::llvm::RoundToNearestOp::static_kind():
      tp = &(gTypes[1085]);
      break;

    case mx::ir::llvm::SAddSatOp::static_kind():
      tp = &(gTypes[1086]);
      break;

    case mx::ir::llvm::SAddWithOverflowOp::static_kind():
      tp = &(gTypes[1087]);
      break;

    case mx::ir::llvm::SMaxOp::static_kind():
      tp = &(gTypes[1088]);
      break;

    case mx::ir::llvm::SMinOp::static_kind():
      tp = &(gTypes[1089]);
      break;

    case mx::ir::llvm::SMulWithOverflowOp::static_kind():
      tp = &(gTypes[1090]);
      break;

    case mx::ir::llvm::SSACopyOp::static_kind():
      tp = &(gTypes[1091]);
      break;

    case mx::ir::llvm::SShlSatOp::static_kind():
      tp = &(gTypes[1092]);
      break;

    case mx::ir::llvm::SSubSatOp::static_kind():
      tp = &(gTypes[1093]);
      break;

    case mx::ir::llvm::SSubWithOverflowOp::static_kind():
      tp = &(gTypes[1094]);
      break;

    case mx::ir::llvm::SinOp::static_kind():
      tp = &(gTypes[1095]);
      break;

    case mx::ir::llvm::SqrtOp::static_kind():
      tp = &(gTypes[1096]);
      break;

    case mx::ir::llvm::StackRestoreOp::static_kind():
      tp = &(gTypes[1097]);
      break;

    case mx::ir::llvm::StackSaveOp::static_kind():
      tp = &(gTypes[1098]);
      break;

    case mx::ir::llvm::StepVectorOp::static_kind():
      tp = &(gTypes[1099]);
      break;

    case mx::ir::llvm::ThreadLocalAddressOp::static_kind():
      tp = &(gTypes[1100]);
      break;

    case mx::ir::llvm::TrapOp::static_kind():
      tp = &(gTypes[1101]);
      break;

    case mx::ir::llvm::UAddSatOp::static_kind():
      tp = &(gTypes[1102]);
      break;

    case mx::ir::llvm::UAddWithOverflowOp::static_kind():
      tp = &(gTypes[1103]);
      break;

    case mx::ir::llvm::UBSanTrapOp::static_kind():
      tp = &(gTypes[1104]);
      break;

    case mx::ir::llvm::UMaxOp::static_kind():
      tp = &(gTypes[1105]);
      break;

    case mx::ir::llvm::UMinOp::static_kind():
      tp = &(gTypes[1106]);
      break;

    case mx::ir::llvm::UMulWithOverflowOp::static_kind():
      tp = &(gTypes[1107]);
      break;

    case mx::ir::llvm::UShlSatOp::static_kind():
      tp = &(gTypes[1108]);
      break;

    case mx::ir::llvm::USubSatOp::static_kind():
      tp = &(gTypes[1109]);
      break;

    case mx::ir::llvm::USubWithOverflowOp::static_kind():
      tp = &(gTypes[1110]);
      break;

    case mx::ir::llvm::VPAShrOp::static_kind():
      tp = &(gTypes[1111]);
      break;

    case mx::ir::llvm::VPAddOp::static_kind():
      tp = &(gTypes[1112]);
      break;

    case mx::ir::llvm::VPAndOp::static_kind():
      tp = &(gTypes[1113]);
      break;

    case mx::ir::llvm::VPFAddOp::static_kind():
      tp = &(gTypes[1114]);
      break;

    case mx::ir::llvm::VPFDivOp::static_kind():
      tp = &(gTypes[1115]);
      break;

    case mx::ir::llvm::VPFMulAddOp::static_kind():
      tp = &(gTypes[1116]);
      break;

    case mx::ir::llvm::VPFMulOp::static_kind():
      tp = &(gTypes[1117]);
      break;

    case mx::ir::llvm::VPFNegOp::static_kind():
      tp = &(gTypes[1118]);
      break;

    case mx::ir::llvm::VPFPExtOp::static_kind():
      tp = &(gTypes[1119]);
      break;

    case mx::ir::llvm::VPFPToSIOp::static_kind():
      tp = &(gTypes[1120]);
      break;

    case mx::ir::llvm::VPFPToUIOp::static_kind():
      tp = &(gTypes[1121]);
      break;

    case mx::ir::llvm::VPFPTruncOp::static_kind():
      tp = &(gTypes[1122]);
      break;

    case mx::ir::llvm::VPFRemOp::static_kind():
      tp = &(gTypes[1123]);
      break;

    case mx::ir::llvm::VPFSubOp::static_kind():
      tp = &(gTypes[1124]);
      break;

    case mx::ir::llvm::VPFmaOp::static_kind():
      tp = &(gTypes[1125]);
      break;

    case mx::ir::llvm::VPIntToPtrOp::static_kind():
      tp = &(gTypes[1126]);
      break;

    case mx::ir::llvm::VPLShrOp::static_kind():
      tp = &(gTypes[1127]);
      break;

    case mx::ir::llvm::VPLoadOp::static_kind():
      tp = &(gTypes[1128]);
      break;

    case mx::ir::llvm::VPMergeMinOp::static_kind():
      tp = &(gTypes[1129]);
      break;

    case mx::ir::llvm::VPMulOp::static_kind():
      tp = &(gTypes[1130]);
      break;

    case mx::ir::llvm::VPOrOp::static_kind():
      tp = &(gTypes[1131]);
      break;

    case mx::ir::llvm::VPPtrToIntOp::static_kind():
      tp = &(gTypes[1132]);
      break;

    case mx::ir::llvm::VPReduceAddOp::static_kind():
      tp = &(gTypes[1133]);
      break;

    case mx::ir::llvm::VPReduceAndOp::static_kind():
      tp = &(gTypes[1134]);
      break;

    case mx::ir::llvm::VPReduceFAddOp::static_kind():
      tp = &(gTypes[1135]);
      break;

    case mx::ir::llvm::VPReduceFMaxOp::static_kind():
      tp = &(gTypes[1136]);
      break;

    case mx::ir::llvm::VPReduceFMinOp::static_kind():
      tp = &(gTypes[1137]);
      break;

    case mx::ir::llvm::VPReduceFMulOp::static_kind():
      tp = &(gTypes[1138]);
      break;

    case mx::ir::llvm::VPReduceMulOp::static_kind():
      tp = &(gTypes[1139]);
      break;

    case mx::ir::llvm::VPReduceOrOp::static_kind():
      tp = &(gTypes[1140]);
      break;

    case mx::ir::llvm::VPReduceSMaxOp::static_kind():
      tp = &(gTypes[1141]);
      break;

    case mx::ir::llvm::VPReduceSMinOp::static_kind():
      tp = &(gTypes[1142]);
      break;

    case mx::ir::llvm::VPReduceUMaxOp::static_kind():
      tp = &(gTypes[1143]);
      break;

    case mx::ir::llvm::VPReduceUMinOp::static_kind():
      tp = &(gTypes[1144]);
      break;

    case mx::ir::llvm::VPReduceXorOp::static_kind():
      tp = &(gTypes[1145]);
      break;

    case mx::ir::llvm::VPSDivOp::static_kind():
      tp = &(gTypes[1146]);
      break;

    case mx::ir::llvm::VPSExtOp::static_kind():
      tp = &(gTypes[1147]);
      break;

    case mx::ir::llvm::VPSIToFPOp::static_kind():
      tp = &(gTypes[1148]);
      break;

    case mx::ir::llvm::VPSRemOp::static_kind():
      tp = &(gTypes[1149]);
      break;

    case mx::ir::llvm::VPSelectMinOp::static_kind():
      tp = &(gTypes[1150]);
      break;

    case mx::ir::llvm::VPShlOp::static_kind():
      tp = &(gTypes[1151]);
      break;

    case mx::ir::llvm::VPStoreOp::static_kind():
      tp = &(gTypes[1152]);
      break;

    case mx::ir::llvm::VPStridedLoadOp::static_kind():
      tp = &(gTypes[1153]);
      break;

    case mx::ir::llvm::VPStridedStoreOp::static_kind():
      tp = &(gTypes[1154]);
      break;

    case mx::ir::llvm::VPSubOp::static_kind():
      tp = &(gTypes[1155]);
      break;

    case mx::ir::llvm::VPTruncOp::static_kind():
      tp = &(gTypes[1156]);
      break;

    case mx::ir::llvm::VPUDivOp::static_kind():
      tp = &(gTypes[1157]);
      break;

    case mx::ir::llvm::VPUIToFPOp::static_kind():
      tp = &(gTypes[1158]);
      break;

    case mx::ir::llvm::VPURemOp::static_kind():
      tp = &(gTypes[1159]);
      break;

    case mx::ir::llvm::VPXorOp::static_kind():
      tp = &(gTypes[1160]);
      break;

    case mx::ir::llvm::VPZExtOp::static_kind():
      tp = &(gTypes[1161]);
      break;

    case mx::ir::llvm::VaCopyOp::static_kind():
      tp = &(gTypes[1162]);
      break;

    case mx::ir::llvm::VaEndOp::static_kind():
      tp = &(gTypes[1163]);
      break;

    case mx::ir::llvm::VaStartOp::static_kind():
      tp = &(gTypes[1164]);
      break;

    case mx::ir::llvm::VarAnnotationOp::static_kind():
      tp = &(gTypes[1165]);
      break;

    case mx::ir::llvm::MaskedCompressStoreOp::static_kind():
      tp = &(gTypes[1166]);
      break;

    case mx::ir::llvm::MaskedExpandLoadOp::static_kind():
      tp = &(gTypes[1167]);
      break;

    case mx::ir::llvm::MaskedGatherOp::static_kind():
      tp = &(gTypes[1168]);
      break;

    case mx::ir::llvm::MaskedScatterOp::static_kind():
      tp = &(gTypes[1169]);
      break;

    case mx::ir::llvm::VectorExtractOp::static_kind():
      tp = &(gTypes[1170]);
      break;

    case mx::ir::llvm::VectorInsertOp::static_kind():
      tp = &(gTypes[1171]);
      break;

    case mx::ir::llvm::VectorReduceAddOp::static_kind():
      tp = &(gTypes[1172]);
      break;

    case mx::ir::llvm::VectorReduceAndOp::static_kind():
      tp = &(gTypes[1173]);
      break;

    case mx::ir::llvm::VectorReduceFAddOp::static_kind():
      tp = &(gTypes[1174]);
      break;

    case mx::ir::llvm::VectorReduceFMaxOp::static_kind():
      tp = &(gTypes[1175]);
      break;

    case mx::ir::llvm::VectorReduceFMaximumOp::static_kind():
      tp = &(gTypes[1176]);
      break;

    case mx::ir::llvm::VectorReduceFMinOp::static_kind():
      tp = &(gTypes[1177]);
      break;

    case mx::ir::llvm::VectorReduceFMinimumOp::static_kind():
      tp = &(gTypes[1178]);
      break;

    case mx::ir::llvm::VectorReduceFMulOp::static_kind():
      tp = &(gTypes[1179]);
      break;

    case mx::ir::llvm::VectorReduceMulOp::static_kind():
      tp = &(gTypes[1180]);
      break;

    case mx::ir::llvm::VectorReduceOrOp::static_kind():
      tp = &(gTypes[1181]);
      break;

    case mx::ir::llvm::VectorReduceSMaxOp::static_kind():
      tp = &(gTypes[1182]);
      break;

    case mx::ir::llvm::VectorReduceSMinOp::static_kind():
      tp = &(gTypes[1183]);
      break;

    case mx::ir::llvm::VectorReduceUMaxOp::static_kind():
      tp = &(gTypes[1184]);
      break;

    case mx::ir::llvm::VectorReduceUMinOp::static_kind():
      tp = &(gTypes[1185]);
      break;

    case mx::ir::llvm::VectorReduceXorOp::static_kind():
      tp = &(gTypes[1186]);
      break;

    case mx::ir::llvm::VScaleOp::static_kind():
      tp = &(gTypes[1187]);
      break;

    case mx::ir::memref::AssumeAlignmentOp::static_kind():
      tp = &(gTypes[1189]);
      break;

    case mx::ir::memref::AtomicRMWOp::static_kind():
      tp = &(gTypes[1190]);
      break;

    case mx::ir::memref::AtomicYieldOp::static_kind():
      tp = &(gTypes[1191]);
      break;

    case mx::ir::memref::CopyOp::static_kind():
      tp = &(gTypes[1192]);
      break;

    case mx::ir::memref::GenericAtomicRMWOp::static_kind():
      tp = &(gTypes[1193]);
      break;

    case mx::ir::memref::LoadOp::static_kind():
      tp = &(gTypes[1194]);
      break;

    case mx::ir::memref::AllocOp::static_kind():
      tp = &(gTypes[1195]);
      break;

    case mx::ir::memref::AllocaOp::static_kind():
      tp = &(gTypes[1196]);
      break;

    case mx::ir::memref::AllocaScopeOp::static_kind():
      tp = &(gTypes[1197]);
      break;

    case mx::ir::memref::AllocaScopeReturnOp::static_kind():
      tp = &(gTypes[1198]);
      break;

    case mx::ir::memref::CastOp::static_kind():
      tp = &(gTypes[1199]);
      break;

    case mx::ir::memref::CollapseShapeOp::static_kind():
      tp = &(gTypes[1200]);
      break;

    case mx::ir::memref::DeallocOp::static_kind():
      tp = &(gTypes[1201]);
      break;

    case mx::ir::memref::DimOp::static_kind():
      tp = &(gTypes[1202]);
      break;

    case mx::ir::memref::DMAStartOp::static_kind():
      tp = &(gTypes[1203]);
      break;

    case mx::ir::memref::DMAWaitOp::static_kind():
      tp = &(gTypes[1204]);
      break;

    case mx::ir::memref::ExpandShapeOp::static_kind():
      tp = &(gTypes[1205]);
      break;

    case mx::ir::memref::ExtractAlignedPointerAsIndexOp::static_kind():
      tp = &(gTypes[1206]);
      break;

    case mx::ir::memref::ExtractStridedMetadataOp::static_kind():
      tp = &(gTypes[1207]);
      break;

    case mx::ir::memref::GetGlobalOp::static_kind():
      tp = &(gTypes[1208]);
      break;

    case mx::ir::memref::GlobalOp::static_kind():
      tp = &(gTypes[1209]);
      break;

    case mx::ir::memref::MemorySpaceCastOp::static_kind():
      tp = &(gTypes[1210]);
      break;

    case mx::ir::memref::PrefetchOp::static_kind():
      tp = &(gTypes[1211]);
      break;

    case mx::ir::memref::RankOp::static_kind():
      tp = &(gTypes[1212]);
      break;

    case mx::ir::memref::ReallocOp::static_kind():
      tp = &(gTypes[1213]);
      break;

    case mx::ir::memref::ReinterpretCastOp::static_kind():
      tp = &(gTypes[1214]);
      break;

    case mx::ir::memref::ReshapeOp::static_kind():
      tp = &(gTypes[1215]);
      break;

    case mx::ir::memref::StoreOp::static_kind():
      tp = &(gTypes[1216]);
      break;

    case mx::ir::memref::TransposeOp::static_kind():
      tp = &(gTypes[1217]);
      break;

    case mx::ir::memref::ViewOp::static_kind():
      tp = &(gTypes[1218]);
      break;

    case mx::ir::memref::SubViewOp::static_kind():
      tp = &(gTypes[1219]);
      break;

    case mx::ir::memref::TensorStoreOp::static_kind():
      tp = &(gTypes[1220]);
      break;

    case mx::ir::abi::CallArgsOp::static_kind():
      tp = &(gTypes[1222]);
      break;

    case mx::ir::abi::CallExecutionOp::static_kind():
      tp = &(gTypes[1223]);
      break;

    case mx::ir::abi::CallOp::static_kind():
      tp = &(gTypes[1224]);
      break;

    case mx::ir::abi::CallRetsOp::static_kind():
      tp = &(gTypes[1225]);
      break;

    case mx::ir::abi::DirectOp::static_kind():
      tp = &(gTypes[1226]);
      break;

    case mx::ir::abi::EpilogueOp::static_kind():
      tp = &(gTypes[1227]);
      break;

    case mx::ir::abi::FuncOp::static_kind():
      tp = &(gTypes[1228]);
      break;

    case mx::ir::abi::PrologueOp::static_kind():
      tp = &(gTypes[1229]);
      break;

    case mx::ir::abi::RetDirectOp::static_kind():
      tp = &(gTypes[1230]);
      break;

    case mx::ir::abi::TodoOp::static_kind():
      tp = &(gTypes[1231]);
      break;

    case mx::ir::abi::WrapFuncOp::static_kind():
      tp = &(gTypes[1232]);
      break;

    case mx::ir::abi::YieldOp::static_kind():
      tp = &(gTypes[1233]);
      break;

    case mx::ir::ll::BrOp::static_kind():
      tp = &(gTypes[1235]);
      break;

    case mx::ir::ll::ConcatOp::static_kind():
      tp = &(gTypes[1236]);
      break;

    case mx::ir::ll::CondBrOp::static_kind():
      tp = &(gTypes[1237]);
      break;

    case mx::ir::ll::CondScopeRetOp::static_kind():
      tp = &(gTypes[1238]);
      break;

    case mx::ir::ll::ExtractOp::static_kind():
      tp = &(gTypes[1239]);
      break;

    case mx::ir::ll::InitializeVarOp::static_kind():
      tp = &(gTypes[1240]);
      break;

    case mx::ir::ll::InlineScopeOp::static_kind():
      tp = &(gTypes[1241]);
      break;

    case mx::ir::ll::FuncOp::static_kind():
      tp = &(gTypes[1242]);
      break;

    case mx::ir::ll::StructGEPOp::static_kind():
      tp = &(gTypes[1243]);
      break;

    case mx::ir::ll::ReturnOp::static_kind():
      tp = &(gTypes[1244]);
      break;

    case mx::ir::ll::ScopeOp::static_kind():
      tp = &(gTypes[1245]);
      break;

    case mx::ir::ll::ScopeRecurseOp::static_kind():
      tp = &(gTypes[1246]);
      break;

    case mx::ir::ll::ScopeRetOp::static_kind():
      tp = &(gTypes[1247]);
      break;

    case mx::ir::ll::UninitializedVarOp::static_kind():
      tp = &(gTypes[1248]);
      break;

    case mx::ir::hl::AccessSpecifierOp::static_kind():
      tp = &(gTypes[1250]);
      break;

    case mx::ir::hl::AddFAssignOp::static_kind():
      tp = &(gTypes[1251]);
      break;

    case mx::ir::hl::AddFOp::static_kind():
      tp = &(gTypes[1252]);
      break;

    case mx::ir::hl::AddIAssignOp::static_kind():
      tp = &(gTypes[1253]);
      break;

    case mx::ir::hl::AddIOp::static_kind():
      tp = &(gTypes[1254]);
      break;

    case mx::ir::hl::AddrLabelExprOp::static_kind():
      tp = &(gTypes[1255]);
      break;

    case mx::ir::hl::AddressOfOp::static_kind():
      tp = &(gTypes[1256]);
      break;

    case mx::ir::hl::AlignOfExprOp::static_kind():
      tp = &(gTypes[1257]);
      break;

    case mx::ir::hl::AlignOfTypeOp::static_kind():
      tp = &(gTypes[1258]);
      break;

    case mx::ir::hl::AsmOp::static_kind():
      tp = &(gTypes[1259]);
      break;

    case mx::ir::hl::AssignOp::static_kind():
      tp = &(gTypes[1260]);
      break;

    case mx::ir::hl::BinAShrAssignOp::static_kind():
      tp = &(gTypes[1261]);
      break;

    case mx::ir::hl::BinAShrOp::static_kind():
      tp = &(gTypes[1262]);
      break;

    case mx::ir::hl::BinAndAssignOp::static_kind():
      tp = &(gTypes[1263]);
      break;

    case mx::ir::hl::BinAndOp::static_kind():
      tp = &(gTypes[1264]);
      break;

    case mx::ir::hl::BinCommaOp::static_kind():
      tp = &(gTypes[1265]);
      break;

    case mx::ir::hl::BinLAndOp::static_kind():
      tp = &(gTypes[1266]);
      break;

    case mx::ir::hl::BinLOrOp::static_kind():
      tp = &(gTypes[1267]);
      break;

    case mx::ir::hl::BinLShrAssignOp::static_kind():
      tp = &(gTypes[1268]);
      break;

    case mx::ir::hl::BinLShrOp::static_kind():
      tp = &(gTypes[1269]);
      break;

    case mx::ir::hl::BinOrAssignOp::static_kind():
      tp = &(gTypes[1270]);
      break;

    case mx::ir::hl::BinOrOp::static_kind():
      tp = &(gTypes[1271]);
      break;

    case mx::ir::hl::BinShlAssignOp::static_kind():
      tp = &(gTypes[1272]);
      break;

    case mx::ir::hl::BinShlOp::static_kind():
      tp = &(gTypes[1273]);
      break;

    case mx::ir::hl::BinXorAssignOp::static_kind():
      tp = &(gTypes[1274]);
      break;

    case mx::ir::hl::BinXorOp::static_kind():
      tp = &(gTypes[1275]);
      break;

    case mx::ir::hl::BuiltinBitCastOp::static_kind():
      tp = &(gTypes[1276]);
      break;

    case mx::ir::hl::CStyleCastOp::static_kind():
      tp = &(gTypes[1277]);
      break;

    case mx::ir::hl::CallOp::static_kind():
      tp = &(gTypes[1278]);
      break;

    case mx::ir::hl::ClassDeclOp::static_kind():
      tp = &(gTypes[1279]);
      break;

    case mx::ir::hl::CmpOp::static_kind():
      tp = &(gTypes[1280]);
      break;

    case mx::ir::hl::ConstantOp::static_kind():
      tp = &(gTypes[1281]);
      break;

    case mx::ir::hl::CxxBaseSpecifierOp::static_kind():
      tp = &(gTypes[1282]);
      break;

    case mx::ir::hl::CxxStructDeclOp::static_kind():
      tp = &(gTypes[1283]);
      break;

    case mx::ir::hl::DeclRefOp::static_kind():
      tp = &(gTypes[1284]);
      break;

    case mx::ir::hl::DerefOp::static_kind():
      tp = &(gTypes[1285]);
      break;

    case mx::ir::hl::DivFAssignOp::static_kind():
      tp = &(gTypes[1286]);
      break;

    case mx::ir::hl::DivFOp::static_kind():
      tp = &(gTypes[1287]);
      break;

    case mx::ir::hl::DivSAssignOp::static_kind():
      tp = &(gTypes[1288]);
      break;

    case mx::ir::hl::DivSOp::static_kind():
      tp = &(gTypes[1289]);
      break;

    case mx::ir::hl::DivUAssignOp::static_kind():
      tp = &(gTypes[1290]);
      break;

    case mx::ir::hl::DivUOp::static_kind():
      tp = &(gTypes[1291]);
      break;

    case mx::ir::hl::EnumConstantOp::static_kind():
      tp = &(gTypes[1292]);
      break;

    case mx::ir::hl::EnumDeclOp::static_kind():
      tp = &(gTypes[1293]);
      break;

    case mx::ir::hl::EnumRefOp::static_kind():
      tp = &(gTypes[1294]);
      break;

    case mx::ir::hl::ExprOp::static_kind():
      tp = &(gTypes[1295]);
      break;

    case mx::ir::hl::ExtensionOp::static_kind():
      tp = &(gTypes[1296]);
      break;

    case mx::ir::hl::FCmpOp::static_kind():
      tp = &(gTypes[1297]);
      break;

    case mx::ir::hl::FieldDeclOp::static_kind():
      tp = &(gTypes[1298]);
      break;

    case mx::ir::hl::FuncRefOp::static_kind():
      tp = &(gTypes[1299]);
      break;

    case mx::ir::hl::GlobalRefOp::static_kind():
      tp = &(gTypes[1300]);
      break;

    case mx::ir::hl::BreakOp::static_kind():
      tp = &(gTypes[1301]);
      break;

    case mx::ir::hl::CaseOp::static_kind():
      tp = &(gTypes[1302]);
      break;

    case mx::ir::hl::CondOp::static_kind():
      tp = &(gTypes[1303]);
      break;

    case mx::ir::hl::CondYieldOp::static_kind():
      tp = &(gTypes[1304]);
      break;

    case mx::ir::hl::ContinueOp::static_kind():
      tp = &(gTypes[1305]);
      break;

    case mx::ir::hl::DefaultOp::static_kind():
      tp = &(gTypes[1306]);
      break;

    case mx::ir::hl::DoOp::static_kind():
      tp = &(gTypes[1307]);
      break;

    case mx::ir::hl::EmptyDeclOp::static_kind():
      tp = &(gTypes[1308]);
      break;

    case mx::ir::hl::ForOp::static_kind():
      tp = &(gTypes[1309]);
      break;

    case mx::ir::hl::FuncOp::static_kind():
      tp = &(gTypes[1310]);
      break;

    case mx::ir::hl::GotoStmtOp::static_kind():
      tp = &(gTypes[1311]);
      break;

    case mx::ir::hl::IfOp::static_kind():
      tp = &(gTypes[1312]);
      break;

    case mx::ir::hl::LabelDeclOp::static_kind():
      tp = &(gTypes[1313]);
      break;

    case mx::ir::hl::LabelStmtOp::static_kind():
      tp = &(gTypes[1314]);
      break;

    case mx::ir::hl::SkipStmtOp::static_kind():
      tp = &(gTypes[1315]);
      break;

    case mx::ir::hl::SwitchOp::static_kind():
      tp = &(gTypes[1316]);
      break;

    case mx::ir::hl::TypeYieldOp::static_kind():
      tp = &(gTypes[1317]);
      break;

    case mx::ir::hl::ValueYieldOp::static_kind():
      tp = &(gTypes[1318]);
      break;

    case mx::ir::hl::VarDeclOp::static_kind():
      tp = &(gTypes[1319]);
      break;

    case mx::ir::hl::WhileOp::static_kind():
      tp = &(gTypes[1320]);
      break;

    case mx::ir::hl::ImplicitCastOp::static_kind():
      tp = &(gTypes[1321]);
      break;

    case mx::ir::hl::IndirectCallOp::static_kind():
      tp = &(gTypes[1322]);
      break;

    case mx::ir::hl::InitListExprOp::static_kind():
      tp = &(gTypes[1323]);
      break;

    case mx::ir::hl::LNotOp::static_kind():
      tp = &(gTypes[1324]);
      break;

    case mx::ir::hl::MinusOp::static_kind():
      tp = &(gTypes[1325]);
      break;

    case mx::ir::hl::MulFAssignOp::static_kind():
      tp = &(gTypes[1326]);
      break;

    case mx::ir::hl::MulFOp::static_kind():
      tp = &(gTypes[1327]);
      break;

    case mx::ir::hl::MulIAssignOp::static_kind():
      tp = &(gTypes[1328]);
      break;

    case mx::ir::hl::MulIOp::static_kind():
      tp = &(gTypes[1329]);
      break;

    case mx::ir::hl::NotOp::static_kind():
      tp = &(gTypes[1330]);
      break;

    case mx::ir::hl::PlusOp::static_kind():
      tp = &(gTypes[1331]);
      break;

    case mx::ir::hl::PostDecOp::static_kind():
      tp = &(gTypes[1332]);
      break;

    case mx::ir::hl::PostIncOp::static_kind():
      tp = &(gTypes[1333]);
      break;

    case mx::ir::hl::PreDecOp::static_kind():
      tp = &(gTypes[1334]);
      break;

    case mx::ir::hl::PreIncOp::static_kind():
      tp = &(gTypes[1335]);
      break;

    case mx::ir::hl::PredefinedExprOp::static_kind():
      tp = &(gTypes[1336]);
      break;

    case mx::ir::hl::RecordMemberOp::static_kind():
      tp = &(gTypes[1337]);
      break;

    case mx::ir::hl::RemFAssignOp::static_kind():
      tp = &(gTypes[1338]);
      break;

    case mx::ir::hl::RemFOp::static_kind():
      tp = &(gTypes[1339]);
      break;

    case mx::ir::hl::RemSAssignOp::static_kind():
      tp = &(gTypes[1340]);
      break;

    case mx::ir::hl::RemSOp::static_kind():
      tp = &(gTypes[1341]);
      break;

    case mx::ir::hl::RemUAssignOp::static_kind():
      tp = &(gTypes[1342]);
      break;

    case mx::ir::hl::RemUOp::static_kind():
      tp = &(gTypes[1343]);
      break;

    case mx::ir::hl::ReturnOp::static_kind():
      tp = &(gTypes[1344]);
      break;

    case mx::ir::hl::SizeOfExprOp::static_kind():
      tp = &(gTypes[1345]);
      break;

    case mx::ir::hl::SizeOfTypeOp::static_kind():
      tp = &(gTypes[1346]);
      break;

    case mx::ir::hl::StmtExprOp::static_kind():
      tp = &(gTypes[1347]);
      break;

    case mx::ir::hl::StructDeclOp::static_kind():
      tp = &(gTypes[1348]);
      break;

    case mx::ir::hl::SubFAssignOp::static_kind():
      tp = &(gTypes[1349]);
      break;

    case mx::ir::hl::SubFOp::static_kind():
      tp = &(gTypes[1350]);
      break;

    case mx::ir::hl::SubIAssignOp::static_kind():
      tp = &(gTypes[1351]);
      break;

    case mx::ir::hl::SubIOp::static_kind():
      tp = &(gTypes[1352]);
      break;

    case mx::ir::hl::SubscriptOp::static_kind():
      tp = &(gTypes[1353]);
      break;

    case mx::ir::hl::ThisOp::static_kind():
      tp = &(gTypes[1354]);
      break;

    case mx::ir::hl::TranslationUnitOp::static_kind():
      tp = &(gTypes[1355]);
      break;

    case mx::ir::hl::TypeDeclOp::static_kind():
      tp = &(gTypes[1356]);
      break;

    case mx::ir::hl::TypeDefOp::static_kind():
      tp = &(gTypes[1357]);
      break;

    case mx::ir::hl::TypeOfExprOp::static_kind():
      tp = &(gTypes[1358]);
      break;

    case mx::ir::hl::TypeOfTypeOp::static_kind():
      tp = &(gTypes[1359]);
      break;

    case mx::ir::hl::UnionDeclOp::static_kind():
      tp = &(gTypes[1360]);
      break;

    case mx::ir::hl::UnreachableOp::static_kind():
      tp = &(gTypes[1361]);
      break;

    case mx::ir::core::BinLAndOp::static_kind():
      tp = &(gTypes[1363]);
      break;

    case mx::ir::core::BinLOrOp::static_kind():
      tp = &(gTypes[1364]);
      break;

    case mx::ir::core::ImplicitReturnOp::static_kind():
      tp = &(gTypes[1365]);
      break;

    case mx::ir::core::LazyOp::static_kind():
      tp = &(gTypes[1366]);
      break;

    case mx::ir::core::ScopeOp::static_kind():
      tp = &(gTypes[1367]);
      break;

    case mx::ir::core::SelectOp::static_kind():
      tp = &(gTypes[1368]);
      break;

    case mx::ir::unsup::UnsupportedDeclOp::static_kind():
      tp = &(gTypes[1370]);
      break;

    case mx::ir::unsup::UnsupportedStmtOp::static_kind():
      tp = &(gTypes[1371]);
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
  if (0 != PyModule_AddObjectRef(module, "Operation", tp_obj)) {
    return false;
  }

  return true;
}

namespace {
static PyGetSetDef gProperties[] = {
  {
    "kind_name",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->kind_name());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::ir::Operation::kind_name"),
    nullptr,
  },
  {
    "id",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->id());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::ir::Operation::id"),
    nullptr,
  },
  {
    "kind",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->kind());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::ir::Operation::kind"),
    nullptr,
  },
  {
    "num_operands",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->num_operands());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::ir::Operation::num_operands"),
    nullptr,
  },
  {
    "operands",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->operands());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::ir::Operation::operands"),
    nullptr,
  },
  {
    "num_results",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->num_results());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::ir::Operation::num_results"),
    nullptr,
  },
  {
    "results",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->results());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::ir::Operation::results"),
    nullptr,
  },
  {
    "num_regions",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->num_regions());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::ir::Operation::num_regions"),
    nullptr,
  },
  {
    "regions",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->regions());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::ir::Operation::regions"),
    nullptr,
  },
  {
    "only_region",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->only_region());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::ir::Operation::only_region"),
    nullptr,
  },
  {
    "only_region_blocks",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->only_region_blocks());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::ir::Operation::only_region_blocks"),
    nullptr,
  },
  {
    "uses",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->uses());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::ir::Operation::uses"),
    nullptr,
  },
  {}  // Sentinel.
};
}  // namespace

namespace {
static PyMethodDef gMethods[] = {
  {
    "classify",
    reinterpret_cast<PyCFunction>(
        +[] (BorrowedPyObject *, BorrowedPyObject * const *args, int num_args) -> SharedPyObject * {
          (void) args;
          while (num_args == 1) {
            auto arg_0 = ::mx::from_python<std::string_view>(args[0]);
            if (!arg_0.has_value()) {
              break;
            }

            return ::mx::to_python(T::classify(std::move(arg_0.value())));
          }

          PyErrorStreamer(PyExc_TypeError)
              << "Invalid arguments passed to 'classify'";
          return nullptr;
        }),
    METH_FASTCALL | METH_STATIC,
    PyDoc_STR("Wrapper for mx::ir::Operation::classify"),
  },
  {
    "producing",
    reinterpret_cast<PyCFunction>(
        +[] (BorrowedPyObject *, BorrowedPyObject * const *args, int num_args) -> SharedPyObject * {
          (void) args;
          while (num_args == 1) {
            auto arg_0 = ::mx::from_python<mx::ir::Result>(args[0]);
            if (!arg_0.has_value()) {
              break;
            }

            return ::mx::to_python(T::producing(arg_0.value()));
          }
          while (num_args == 1) {
            auto arg_0 = ::mx::from_python<mx::ir::Value>(args[0]);
            if (!arg_0.has_value()) {
              break;
            }

            return ::mx::to_python(T::producing(arg_0.value()));
          }

          PyErrorStreamer(PyExc_TypeError)
              << "Invalid arguments passed to 'producing'";
          return nullptr;
        }),
    METH_FASTCALL | METH_STATIC,
    PyDoc_STR("Wrapper for mx::ir::Operation::producing"),
  },
  {
    "containing",
    reinterpret_cast<PyCFunction>(
        +[] (BorrowedPyObject *, BorrowedPyObject * const *args, int num_args) -> SharedPyObject * {
          (void) args;
          while (num_args == 1) {
            auto arg_0 = ::mx::from_python<mx::ir::Region>(args[0]);
            if (!arg_0.has_value()) {
              break;
            }

            return ::mx::to_python(T::containing(arg_0.value()));
          }
          while (num_args == 1) {
            auto arg_0 = ::mx::from_python<mx::ir::Block>(args[0]);
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
    PyDoc_STR("Wrapper for mx::ir::Operation::containing"),
  },
  {
    "first_from",
    reinterpret_cast<PyCFunction>(
        +[] (BorrowedPyObject *, BorrowedPyObject * const *args, int num_args) -> SharedPyObject * {
          (void) args;
          while (num_args == 1) {
            auto arg_0 = ::mx::from_python<mx::Decl>(args[0]);
            if (!arg_0.has_value()) {
              break;
            }

            return ::mx::to_python(T::first_from(arg_0.value()));
          }
          while (num_args == 2) {
            auto arg_0 = ::mx::from_python<mx::Decl>(args[0]);
            if (!arg_0.has_value()) {
              break;
            }
            auto arg_1 = ::mx::from_python<mx::ir::OperationKind>(args[1]);
            if (!arg_1.has_value()) {
              break;
            }

            return ::mx::to_python(T::first_from(arg_0.value(), std::move(arg_1.value())));
          }
          while (num_args == 1) {
            auto arg_0 = ::mx::from_python<mx::Stmt>(args[0]);
            if (!arg_0.has_value()) {
              break;
            }

            return ::mx::to_python(T::first_from(arg_0.value()));
          }
          while (num_args == 2) {
            auto arg_0 = ::mx::from_python<mx::Stmt>(args[0]);
            if (!arg_0.has_value()) {
              break;
            }
            auto arg_1 = ::mx::from_python<mx::ir::OperationKind>(args[1]);
            if (!arg_1.has_value()) {
              break;
            }

            return ::mx::to_python(T::first_from(arg_0.value(), std::move(arg_1.value())));
          }

          PyErrorStreamer(PyExc_TypeError)
              << "Invalid arguments passed to 'first_from'";
          return nullptr;
        }),
    METH_FASTCALL | METH_STATIC,
    PyDoc_STR("Wrapper for mx::ir::Operation::first_from"),
  },
  {
    "all_from",
    reinterpret_cast<PyCFunction>(
        +[] (BorrowedPyObject *, BorrowedPyObject * const *args, int num_args) -> SharedPyObject * {
          (void) args;
          while (num_args == 1) {
            auto arg_0 = ::mx::from_python<mx::Decl>(args[0]);
            if (!arg_0.has_value()) {
              break;
            }

            return ::mx::to_python(T::all_from(arg_0.value()));
          }
          while (num_args == 1) {
            auto arg_0 = ::mx::from_python<mx::Stmt>(args[0]);
            if (!arg_0.has_value()) {
              break;
            }

            return ::mx::to_python(T::all_from(arg_0.value()));
          }

          PyErrorStreamer(PyExc_TypeError)
              << "Invalid arguments passed to 'all_from'";
          return nullptr;
        }),
    METH_FASTCALL | METH_STATIC,
    PyDoc_STR("Wrapper for mx::ir::Operation::all_from"),
  },
  {
    "nth_operand",
    reinterpret_cast<PyCFunction>(
        +[] (BorrowedPyObject *self, BorrowedPyObject * const *args, int num_args) -> SharedPyObject * {
          T *obj = T_cast(self);
          (void) args;
          while (num_args == 1) {
            auto arg_0 = ::mx::from_python<uint32_t>(args[0]);
            if (!arg_0.has_value()) {
              break;
            }

            return ::mx::to_python(obj->nth_operand(std::move(arg_0.value())));
          }

          PyErrorStreamer(PyExc_TypeError)
              << "Invalid arguments passed to 'nth_operand'";
          return nullptr;
        }),
    METH_FASTCALL,
    PyDoc_STR("Wrapper for mx::ir::Operation::nth_operand"),
  },
  {
    "nth_result",
    reinterpret_cast<PyCFunction>(
        +[] (BorrowedPyObject *self, BorrowedPyObject * const *args, int num_args) -> SharedPyObject * {
          T *obj = T_cast(self);
          (void) args;
          while (num_args == 1) {
            auto arg_0 = ::mx::from_python<uint32_t>(args[0]);
            if (!arg_0.has_value()) {
              break;
            }

            return ::mx::to_python(obj->nth_result(std::move(arg_0.value())));
          }

          PyErrorStreamer(PyExc_TypeError)
              << "Invalid arguments passed to 'nth_result'";
          return nullptr;
        }),
    METH_FASTCALL,
    PyDoc_STR("Wrapper for mx::ir::Operation::nth_result"),
  },
  {
    "nth_region",
    reinterpret_cast<PyCFunction>(
        +[] (BorrowedPyObject *self, BorrowedPyObject * const *args, int num_args) -> SharedPyObject * {
          T *obj = T_cast(self);
          (void) args;
          while (num_args == 1) {
            auto arg_0 = ::mx::from_python<uint32_t>(args[0]);
            if (!arg_0.has_value()) {
              break;
            }

            return ::mx::to_python(obj->nth_region(std::move(arg_0.value())));
          }

          PyErrorStreamer(PyExc_TypeError)
              << "Invalid arguments passed to 'nth_region'";
          return nullptr;
        }),
    METH_FASTCALL,
    PyDoc_STR("Wrapper for mx::ir::Operation::nth_region"),
  },
  {}  // Sentinel.
};
}  // namespace

namespace {

PyTypeObject *InitType(void) noexcept {
  PyTypeObject * const tp = &(gTypes[939]);
  tp->tp_basicsize = sizeof(O);
  tp->tp_itemsize = 0;
  tp->tp_dealloc = [] (::PyObject *obj) {
    if (auto *data = T_cast(obj)) {
      data->~T();
    }
    PyObject_Free(obj);
  };
  tp->tp_name = "multiplier.ir.Operation";
  tp->tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_DISALLOW_INSTANTIATION;
  tp->tp_doc = PyDoc_STR("Wrapper for mx::ir::::Operation");
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
          << "'Operation.__init__' does not take any keyword arguments";
      return -1;
    }

    if (!args || !PySequence_Check(args)) {
      PyErrorStreamer(PyExc_TypeError)
          << "Invalid positional arguments passed to 'Operation.__init__'";
      return -1;
    }

    auto obj = O_cast(self);
    auto num_args = PySequence_Size(args);
    
    (void) obj;
    (void) num_args;
    PyErrorStreamer(PyExc_TypeError)
        << "Class 'Operation' cannot be directly instantiated";
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
