// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/IR/LLVM/Operation.h>

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
using T = mx::ir::llvm::Operation;

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
  if (tp < &(gTypes[935]) || tp >= &(gTypes[1180])) {
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

    case mx::ir::llvm::AShrOp::static_kind():
      tp = &(gTypes[936]);
      break;

    case mx::ir::llvm::AddOp::static_kind():
      tp = &(gTypes[937]);
      break;

    case mx::ir::llvm::AddrSpaceCastOp::static_kind():
      tp = &(gTypes[938]);
      break;

    case mx::ir::llvm::AddressOfOp::static_kind():
      tp = &(gTypes[939]);
      break;

    case mx::ir::llvm::AllocaOp::static_kind():
      tp = &(gTypes[940]);
      break;

    case mx::ir::llvm::AndOp::static_kind():
      tp = &(gTypes[941]);
      break;

    case mx::ir::llvm::AtomicCmpXchgOp::static_kind():
      tp = &(gTypes[942]);
      break;

    case mx::ir::llvm::AtomicRMWOp::static_kind():
      tp = &(gTypes[943]);
      break;

    case mx::ir::llvm::BitcastOp::static_kind():
      tp = &(gTypes[944]);
      break;

    case mx::ir::llvm::BrOp::static_kind():
      tp = &(gTypes[945]);
      break;

    case mx::ir::llvm::CallOp::static_kind():
      tp = &(gTypes[946]);
      break;

    case mx::ir::llvm::ComdatOp::static_kind():
      tp = &(gTypes[947]);
      break;

    case mx::ir::llvm::ComdatSelectorOp::static_kind():
      tp = &(gTypes[948]);
      break;

    case mx::ir::llvm::CondBrOp::static_kind():
      tp = &(gTypes[949]);
      break;

    case mx::ir::llvm::ConstantOp::static_kind():
      tp = &(gTypes[950]);
      break;

    case mx::ir::llvm::ExtractElementOp::static_kind():
      tp = &(gTypes[951]);
      break;

    case mx::ir::llvm::ExtractValueOp::static_kind():
      tp = &(gTypes[952]);
      break;

    case mx::ir::llvm::FAddOp::static_kind():
      tp = &(gTypes[953]);
      break;

    case mx::ir::llvm::FCmpOp::static_kind():
      tp = &(gTypes[954]);
      break;

    case mx::ir::llvm::FDivOp::static_kind():
      tp = &(gTypes[955]);
      break;

    case mx::ir::llvm::FMulOp::static_kind():
      tp = &(gTypes[956]);
      break;

    case mx::ir::llvm::FNegOp::static_kind():
      tp = &(gTypes[957]);
      break;

    case mx::ir::llvm::FPExtOp::static_kind():
      tp = &(gTypes[958]);
      break;

    case mx::ir::llvm::FPToSIOp::static_kind():
      tp = &(gTypes[959]);
      break;

    case mx::ir::llvm::FPToUIOp::static_kind():
      tp = &(gTypes[960]);
      break;

    case mx::ir::llvm::FPTruncOp::static_kind():
      tp = &(gTypes[961]);
      break;

    case mx::ir::llvm::FRemOp::static_kind():
      tp = &(gTypes[962]);
      break;

    case mx::ir::llvm::FSubOp::static_kind():
      tp = &(gTypes[963]);
      break;

    case mx::ir::llvm::FenceOp::static_kind():
      tp = &(gTypes[964]);
      break;

    case mx::ir::llvm::FreezeOp::static_kind():
      tp = &(gTypes[965]);
      break;

    case mx::ir::llvm::GetElementPtrOp::static_kind():
      tp = &(gTypes[966]);
      break;

    case mx::ir::llvm::GlobalCtorsOp::static_kind():
      tp = &(gTypes[967]);
      break;

    case mx::ir::llvm::GlobalDtorsOp::static_kind():
      tp = &(gTypes[968]);
      break;

    case mx::ir::llvm::GlobalOp::static_kind():
      tp = &(gTypes[969]);
      break;

    case mx::ir::llvm::ICmpOp::static_kind():
      tp = &(gTypes[970]);
      break;

    case mx::ir::llvm::InlineAsmOp::static_kind():
      tp = &(gTypes[971]);
      break;

    case mx::ir::llvm::InsertElementOp::static_kind():
      tp = &(gTypes[972]);
      break;

    case mx::ir::llvm::InsertValueOp::static_kind():
      tp = &(gTypes[973]);
      break;

    case mx::ir::llvm::IntToPtrOp::static_kind():
      tp = &(gTypes[974]);
      break;

    case mx::ir::llvm::InvokeOp::static_kind():
      tp = &(gTypes[975]);
      break;

    case mx::ir::llvm::FuncOp::static_kind():
      tp = &(gTypes[976]);
      break;

    case mx::ir::llvm::LShrOp::static_kind():
      tp = &(gTypes[977]);
      break;

    case mx::ir::llvm::LandingpadOp::static_kind():
      tp = &(gTypes[978]);
      break;

    case mx::ir::llvm::LoadOp::static_kind():
      tp = &(gTypes[979]);
      break;

    case mx::ir::llvm::MetadataOp::static_kind():
      tp = &(gTypes[980]);
      break;

    case mx::ir::llvm::MulOp::static_kind():
      tp = &(gTypes[981]);
      break;

    case mx::ir::llvm::NullOp::static_kind():
      tp = &(gTypes[982]);
      break;

    case mx::ir::llvm::OrOp::static_kind():
      tp = &(gTypes[983]);
      break;

    case mx::ir::llvm::PoisonOp::static_kind():
      tp = &(gTypes[984]);
      break;

    case mx::ir::llvm::PtrToIntOp::static_kind():
      tp = &(gTypes[985]);
      break;

    case mx::ir::llvm::ResumeOp::static_kind():
      tp = &(gTypes[986]);
      break;

    case mx::ir::llvm::ReturnOp::static_kind():
      tp = &(gTypes[987]);
      break;

    case mx::ir::llvm::SDivOp::static_kind():
      tp = &(gTypes[988]);
      break;

    case mx::ir::llvm::SExtOp::static_kind():
      tp = &(gTypes[989]);
      break;

    case mx::ir::llvm::SIToFPOp::static_kind():
      tp = &(gTypes[990]);
      break;

    case mx::ir::llvm::SRemOp::static_kind():
      tp = &(gTypes[991]);
      break;

    case mx::ir::llvm::SelectOp::static_kind():
      tp = &(gTypes[992]);
      break;

    case mx::ir::llvm::ShlOp::static_kind():
      tp = &(gTypes[993]);
      break;

    case mx::ir::llvm::ShuffleVectorOp::static_kind():
      tp = &(gTypes[994]);
      break;

    case mx::ir::llvm::StoreOp::static_kind():
      tp = &(gTypes[995]);
      break;

    case mx::ir::llvm::SubOp::static_kind():
      tp = &(gTypes[996]);
      break;

    case mx::ir::llvm::SwitchOp::static_kind():
      tp = &(gTypes[997]);
      break;

    case mx::ir::llvm::TruncOp::static_kind():
      tp = &(gTypes[998]);
      break;

    case mx::ir::llvm::UDivOp::static_kind():
      tp = &(gTypes[999]);
      break;

    case mx::ir::llvm::UIToFPOp::static_kind():
      tp = &(gTypes[1000]);
      break;

    case mx::ir::llvm::URemOp::static_kind():
      tp = &(gTypes[1001]);
      break;

    case mx::ir::llvm::UndefOp::static_kind():
      tp = &(gTypes[1002]);
      break;

    case mx::ir::llvm::UnreachableOp::static_kind():
      tp = &(gTypes[1003]);
      break;

    case mx::ir::llvm::XOrOp::static_kind():
      tp = &(gTypes[1004]);
      break;

    case mx::ir::llvm::ZExtOp::static_kind():
      tp = &(gTypes[1005]);
      break;

    case mx::ir::llvm::AbsOp::static_kind():
      tp = &(gTypes[1006]);
      break;

    case mx::ir::llvm::AnnotationOp::static_kind():
      tp = &(gTypes[1007]);
      break;

    case mx::ir::llvm::AssumeOp::static_kind():
      tp = &(gTypes[1008]);
      break;

    case mx::ir::llvm::BitReverseOp::static_kind():
      tp = &(gTypes[1009]);
      break;

    case mx::ir::llvm::ByteSwapOp::static_kind():
      tp = &(gTypes[1010]);
      break;

    case mx::ir::llvm::CallIntrinsicOp::static_kind():
      tp = &(gTypes[1011]);
      break;

    case mx::ir::llvm::CopySignOp::static_kind():
      tp = &(gTypes[1012]);
      break;

    case mx::ir::llvm::CoroAlignOp::static_kind():
      tp = &(gTypes[1013]);
      break;

    case mx::ir::llvm::CoroBeginOp::static_kind():
      tp = &(gTypes[1014]);
      break;

    case mx::ir::llvm::CoroEndOp::static_kind():
      tp = &(gTypes[1015]);
      break;

    case mx::ir::llvm::CoroFreeOp::static_kind():
      tp = &(gTypes[1016]);
      break;

    case mx::ir::llvm::CoroIdOp::static_kind():
      tp = &(gTypes[1017]);
      break;

    case mx::ir::llvm::CoroResumeOp::static_kind():
      tp = &(gTypes[1018]);
      break;

    case mx::ir::llvm::CoroSaveOp::static_kind():
      tp = &(gTypes[1019]);
      break;

    case mx::ir::llvm::CoroSizeOp::static_kind():
      tp = &(gTypes[1020]);
      break;

    case mx::ir::llvm::CoroSuspendOp::static_kind():
      tp = &(gTypes[1021]);
      break;

    case mx::ir::llvm::CosOp::static_kind():
      tp = &(gTypes[1022]);
      break;

    case mx::ir::llvm::CountLeadingZerosOp::static_kind():
      tp = &(gTypes[1023]);
      break;

    case mx::ir::llvm::CountTrailingZerosOp::static_kind():
      tp = &(gTypes[1024]);
      break;

    case mx::ir::llvm::CtPopOp::static_kind():
      tp = &(gTypes[1025]);
      break;

    case mx::ir::llvm::DbgDeclareOp::static_kind():
      tp = &(gTypes[1026]);
      break;

    case mx::ir::llvm::DbgLabelOp::static_kind():
      tp = &(gTypes[1027]);
      break;

    case mx::ir::llvm::DbgValueOp::static_kind():
      tp = &(gTypes[1028]);
      break;

    case mx::ir::llvm::DebugTrapOp::static_kind():
      tp = &(gTypes[1029]);
      break;

    case mx::ir::llvm::EhTypeidForOp::static_kind():
      tp = &(gTypes[1030]);
      break;

    case mx::ir::llvm::Exp2Op::static_kind():
      tp = &(gTypes[1031]);
      break;

    case mx::ir::llvm::ExpOp::static_kind():
      tp = &(gTypes[1032]);
      break;

    case mx::ir::llvm::ExpectOp::static_kind():
      tp = &(gTypes[1033]);
      break;

    case mx::ir::llvm::ExpectWithProbabilityOp::static_kind():
      tp = &(gTypes[1034]);
      break;

    case mx::ir::llvm::FAbsOp::static_kind():
      tp = &(gTypes[1035]);
      break;

    case mx::ir::llvm::FCeilOp::static_kind():
      tp = &(gTypes[1036]);
      break;

    case mx::ir::llvm::FFloorOp::static_kind():
      tp = &(gTypes[1037]);
      break;

    case mx::ir::llvm::FMAOp::static_kind():
      tp = &(gTypes[1038]);
      break;

    case mx::ir::llvm::FMulAddOp::static_kind():
      tp = &(gTypes[1039]);
      break;

    case mx::ir::llvm::FTruncOp::static_kind():
      tp = &(gTypes[1040]);
      break;

    case mx::ir::llvm::FShlOp::static_kind():
      tp = &(gTypes[1041]);
      break;

    case mx::ir::llvm::FShrOp::static_kind():
      tp = &(gTypes[1042]);
      break;

    case mx::ir::llvm::GetActiveLaneMaskOp::static_kind():
      tp = &(gTypes[1043]);
      break;

    case mx::ir::llvm::IsConstantOp::static_kind():
      tp = &(gTypes[1044]);
      break;

    case mx::ir::llvm::IsFPClassOp::static_kind():
      tp = &(gTypes[1045]);
      break;

    case mx::ir::llvm::LifetimeEndOp::static_kind():
      tp = &(gTypes[1046]);
      break;

    case mx::ir::llvm::LifetimeStartOp::static_kind():
      tp = &(gTypes[1047]);
      break;

    case mx::ir::llvm::RoundAndCastToLongLongOp::static_kind():
      tp = &(gTypes[1048]);
      break;

    case mx::ir::llvm::RoundAndCastToNearestLongLongOp::static_kind():
      tp = &(gTypes[1049]);
      break;

    case mx::ir::llvm::Log10Op::static_kind():
      tp = &(gTypes[1050]);
      break;

    case mx::ir::llvm::Log2Op::static_kind():
      tp = &(gTypes[1051]);
      break;

    case mx::ir::llvm::LogOp::static_kind():
      tp = &(gTypes[1052]);
      break;

    case mx::ir::llvm::RoundAndCastToLongOp::static_kind():
      tp = &(gTypes[1053]);
      break;

    case mx::ir::llvm::RoundAndCastToNearestLongOp::static_kind():
      tp = &(gTypes[1054]);
      break;

    case mx::ir::llvm::MaskedLoadOp::static_kind():
      tp = &(gTypes[1055]);
      break;

    case mx::ir::llvm::MaskedStoreOp::static_kind():
      tp = &(gTypes[1056]);
      break;

    case mx::ir::llvm::MatrixColumnMajorLoadOp::static_kind():
      tp = &(gTypes[1057]);
      break;

    case mx::ir::llvm::MatrixColumnMajorStoreOp::static_kind():
      tp = &(gTypes[1058]);
      break;

    case mx::ir::llvm::MatrixMultiplyOp::static_kind():
      tp = &(gTypes[1059]);
      break;

    case mx::ir::llvm::MatrixTransposeOp::static_kind():
      tp = &(gTypes[1060]);
      break;

    case mx::ir::llvm::MaxNumOp::static_kind():
      tp = &(gTypes[1061]);
      break;

    case mx::ir::llvm::MaximumOp::static_kind():
      tp = &(gTypes[1062]);
      break;

    case mx::ir::llvm::MemcpyInlineOp::static_kind():
      tp = &(gTypes[1063]);
      break;

    case mx::ir::llvm::MemcpyOp::static_kind():
      tp = &(gTypes[1064]);
      break;

    case mx::ir::llvm::MemmoveOp::static_kind():
      tp = &(gTypes[1065]);
      break;

    case mx::ir::llvm::MemsetOp::static_kind():
      tp = &(gTypes[1066]);
      break;

    case mx::ir::llvm::MinNumOp::static_kind():
      tp = &(gTypes[1067]);
      break;

    case mx::ir::llvm::MinimumOp::static_kind():
      tp = &(gTypes[1068]);
      break;

    case mx::ir::llvm::RoundToNearbyIntOp::static_kind():
      tp = &(gTypes[1069]);
      break;

    case mx::ir::llvm::NoAliasScopeDeclOp::static_kind():
      tp = &(gTypes[1070]);
      break;

    case mx::ir::llvm::PowIOp::static_kind():
      tp = &(gTypes[1071]);
      break;

    case mx::ir::llvm::FPowOp::static_kind():
      tp = &(gTypes[1072]);
      break;

    case mx::ir::llvm::PrefetchOp::static_kind():
      tp = &(gTypes[1073]);
      break;

    case mx::ir::llvm::PtrAnnotationOp::static_kind():
      tp = &(gTypes[1074]);
      break;

    case mx::ir::llvm::RoundToIntOp::static_kind():
      tp = &(gTypes[1075]);
      break;

    case mx::ir::llvm::RoundToNearestEvenOp::static_kind():
      tp = &(gTypes[1076]);
      break;

    case mx::ir::llvm::RoundToNearestOp::static_kind():
      tp = &(gTypes[1077]);
      break;

    case mx::ir::llvm::SAddSatOp::static_kind():
      tp = &(gTypes[1078]);
      break;

    case mx::ir::llvm::SAddWithOverflowOp::static_kind():
      tp = &(gTypes[1079]);
      break;

    case mx::ir::llvm::SMaxOp::static_kind():
      tp = &(gTypes[1080]);
      break;

    case mx::ir::llvm::SMinOp::static_kind():
      tp = &(gTypes[1081]);
      break;

    case mx::ir::llvm::SMulWithOverflowOp::static_kind():
      tp = &(gTypes[1082]);
      break;

    case mx::ir::llvm::SSACopyOp::static_kind():
      tp = &(gTypes[1083]);
      break;

    case mx::ir::llvm::SShlSatOp::static_kind():
      tp = &(gTypes[1084]);
      break;

    case mx::ir::llvm::SSubSatOp::static_kind():
      tp = &(gTypes[1085]);
      break;

    case mx::ir::llvm::SSubWithOverflowOp::static_kind():
      tp = &(gTypes[1086]);
      break;

    case mx::ir::llvm::SinOp::static_kind():
      tp = &(gTypes[1087]);
      break;

    case mx::ir::llvm::SqrtOp::static_kind():
      tp = &(gTypes[1088]);
      break;

    case mx::ir::llvm::StackRestoreOp::static_kind():
      tp = &(gTypes[1089]);
      break;

    case mx::ir::llvm::StackSaveOp::static_kind():
      tp = &(gTypes[1090]);
      break;

    case mx::ir::llvm::StepVectorOp::static_kind():
      tp = &(gTypes[1091]);
      break;

    case mx::ir::llvm::ThreadLocalAddressOp::static_kind():
      tp = &(gTypes[1092]);
      break;

    case mx::ir::llvm::TrapOp::static_kind():
      tp = &(gTypes[1093]);
      break;

    case mx::ir::llvm::UAddSatOp::static_kind():
      tp = &(gTypes[1094]);
      break;

    case mx::ir::llvm::UAddWithOverflowOp::static_kind():
      tp = &(gTypes[1095]);
      break;

    case mx::ir::llvm::UBSanTrapOp::static_kind():
      tp = &(gTypes[1096]);
      break;

    case mx::ir::llvm::UMaxOp::static_kind():
      tp = &(gTypes[1097]);
      break;

    case mx::ir::llvm::UMinOp::static_kind():
      tp = &(gTypes[1098]);
      break;

    case mx::ir::llvm::UMulWithOverflowOp::static_kind():
      tp = &(gTypes[1099]);
      break;

    case mx::ir::llvm::UShlSatOp::static_kind():
      tp = &(gTypes[1100]);
      break;

    case mx::ir::llvm::USubSatOp::static_kind():
      tp = &(gTypes[1101]);
      break;

    case mx::ir::llvm::USubWithOverflowOp::static_kind():
      tp = &(gTypes[1102]);
      break;

    case mx::ir::llvm::VPAShrOp::static_kind():
      tp = &(gTypes[1103]);
      break;

    case mx::ir::llvm::VPAddOp::static_kind():
      tp = &(gTypes[1104]);
      break;

    case mx::ir::llvm::VPAndOp::static_kind():
      tp = &(gTypes[1105]);
      break;

    case mx::ir::llvm::VPFAddOp::static_kind():
      tp = &(gTypes[1106]);
      break;

    case mx::ir::llvm::VPFDivOp::static_kind():
      tp = &(gTypes[1107]);
      break;

    case mx::ir::llvm::VPFMulAddOp::static_kind():
      tp = &(gTypes[1108]);
      break;

    case mx::ir::llvm::VPFMulOp::static_kind():
      tp = &(gTypes[1109]);
      break;

    case mx::ir::llvm::VPFNegOp::static_kind():
      tp = &(gTypes[1110]);
      break;

    case mx::ir::llvm::VPFPExtOp::static_kind():
      tp = &(gTypes[1111]);
      break;

    case mx::ir::llvm::VPFPToSIOp::static_kind():
      tp = &(gTypes[1112]);
      break;

    case mx::ir::llvm::VPFPToUIOp::static_kind():
      tp = &(gTypes[1113]);
      break;

    case mx::ir::llvm::VPFPTruncOp::static_kind():
      tp = &(gTypes[1114]);
      break;

    case mx::ir::llvm::VPFRemOp::static_kind():
      tp = &(gTypes[1115]);
      break;

    case mx::ir::llvm::VPFSubOp::static_kind():
      tp = &(gTypes[1116]);
      break;

    case mx::ir::llvm::VPFmaOp::static_kind():
      tp = &(gTypes[1117]);
      break;

    case mx::ir::llvm::VPIntToPtrOp::static_kind():
      tp = &(gTypes[1118]);
      break;

    case mx::ir::llvm::VPLShrOp::static_kind():
      tp = &(gTypes[1119]);
      break;

    case mx::ir::llvm::VPLoadOp::static_kind():
      tp = &(gTypes[1120]);
      break;

    case mx::ir::llvm::VPMergeMinOp::static_kind():
      tp = &(gTypes[1121]);
      break;

    case mx::ir::llvm::VPMulOp::static_kind():
      tp = &(gTypes[1122]);
      break;

    case mx::ir::llvm::VPOrOp::static_kind():
      tp = &(gTypes[1123]);
      break;

    case mx::ir::llvm::VPPtrToIntOp::static_kind():
      tp = &(gTypes[1124]);
      break;

    case mx::ir::llvm::VPReduceAddOp::static_kind():
      tp = &(gTypes[1125]);
      break;

    case mx::ir::llvm::VPReduceAndOp::static_kind():
      tp = &(gTypes[1126]);
      break;

    case mx::ir::llvm::VPReduceFAddOp::static_kind():
      tp = &(gTypes[1127]);
      break;

    case mx::ir::llvm::VPReduceFMaxOp::static_kind():
      tp = &(gTypes[1128]);
      break;

    case mx::ir::llvm::VPReduceFMinOp::static_kind():
      tp = &(gTypes[1129]);
      break;

    case mx::ir::llvm::VPReduceFMulOp::static_kind():
      tp = &(gTypes[1130]);
      break;

    case mx::ir::llvm::VPReduceMulOp::static_kind():
      tp = &(gTypes[1131]);
      break;

    case mx::ir::llvm::VPReduceOrOp::static_kind():
      tp = &(gTypes[1132]);
      break;

    case mx::ir::llvm::VPReduceSMaxOp::static_kind():
      tp = &(gTypes[1133]);
      break;

    case mx::ir::llvm::VPReduceSMinOp::static_kind():
      tp = &(gTypes[1134]);
      break;

    case mx::ir::llvm::VPReduceUMaxOp::static_kind():
      tp = &(gTypes[1135]);
      break;

    case mx::ir::llvm::VPReduceUMinOp::static_kind():
      tp = &(gTypes[1136]);
      break;

    case mx::ir::llvm::VPReduceXorOp::static_kind():
      tp = &(gTypes[1137]);
      break;

    case mx::ir::llvm::VPSDivOp::static_kind():
      tp = &(gTypes[1138]);
      break;

    case mx::ir::llvm::VPSExtOp::static_kind():
      tp = &(gTypes[1139]);
      break;

    case mx::ir::llvm::VPSIToFPOp::static_kind():
      tp = &(gTypes[1140]);
      break;

    case mx::ir::llvm::VPSRemOp::static_kind():
      tp = &(gTypes[1141]);
      break;

    case mx::ir::llvm::VPSelectMinOp::static_kind():
      tp = &(gTypes[1142]);
      break;

    case mx::ir::llvm::VPShlOp::static_kind():
      tp = &(gTypes[1143]);
      break;

    case mx::ir::llvm::VPStoreOp::static_kind():
      tp = &(gTypes[1144]);
      break;

    case mx::ir::llvm::VPStridedLoadOp::static_kind():
      tp = &(gTypes[1145]);
      break;

    case mx::ir::llvm::VPStridedStoreOp::static_kind():
      tp = &(gTypes[1146]);
      break;

    case mx::ir::llvm::VPSubOp::static_kind():
      tp = &(gTypes[1147]);
      break;

    case mx::ir::llvm::VPTruncOp::static_kind():
      tp = &(gTypes[1148]);
      break;

    case mx::ir::llvm::VPUDivOp::static_kind():
      tp = &(gTypes[1149]);
      break;

    case mx::ir::llvm::VPUIToFPOp::static_kind():
      tp = &(gTypes[1150]);
      break;

    case mx::ir::llvm::VPURemOp::static_kind():
      tp = &(gTypes[1151]);
      break;

    case mx::ir::llvm::VPXorOp::static_kind():
      tp = &(gTypes[1152]);
      break;

    case mx::ir::llvm::VPZExtOp::static_kind():
      tp = &(gTypes[1153]);
      break;

    case mx::ir::llvm::VaCopyOp::static_kind():
      tp = &(gTypes[1154]);
      break;

    case mx::ir::llvm::VaEndOp::static_kind():
      tp = &(gTypes[1155]);
      break;

    case mx::ir::llvm::VaStartOp::static_kind():
      tp = &(gTypes[1156]);
      break;

    case mx::ir::llvm::VarAnnotationOp::static_kind():
      tp = &(gTypes[1157]);
      break;

    case mx::ir::llvm::MaskedCompressStoreOp::static_kind():
      tp = &(gTypes[1158]);
      break;

    case mx::ir::llvm::MaskedExpandLoadOp::static_kind():
      tp = &(gTypes[1159]);
      break;

    case mx::ir::llvm::MaskedGatherOp::static_kind():
      tp = &(gTypes[1160]);
      break;

    case mx::ir::llvm::MaskedScatterOp::static_kind():
      tp = &(gTypes[1161]);
      break;

    case mx::ir::llvm::VectorExtractOp::static_kind():
      tp = &(gTypes[1162]);
      break;

    case mx::ir::llvm::VectorInsertOp::static_kind():
      tp = &(gTypes[1163]);
      break;

    case mx::ir::llvm::VectorReduceAddOp::static_kind():
      tp = &(gTypes[1164]);
      break;

    case mx::ir::llvm::VectorReduceAndOp::static_kind():
      tp = &(gTypes[1165]);
      break;

    case mx::ir::llvm::VectorReduceFAddOp::static_kind():
      tp = &(gTypes[1166]);
      break;

    case mx::ir::llvm::VectorReduceFMaxOp::static_kind():
      tp = &(gTypes[1167]);
      break;

    case mx::ir::llvm::VectorReduceFMaximumOp::static_kind():
      tp = &(gTypes[1168]);
      break;

    case mx::ir::llvm::VectorReduceFMinOp::static_kind():
      tp = &(gTypes[1169]);
      break;

    case mx::ir::llvm::VectorReduceFMinimumOp::static_kind():
      tp = &(gTypes[1170]);
      break;

    case mx::ir::llvm::VectorReduceFMulOp::static_kind():
      tp = &(gTypes[1171]);
      break;

    case mx::ir::llvm::VectorReduceMulOp::static_kind():
      tp = &(gTypes[1172]);
      break;

    case mx::ir::llvm::VectorReduceOrOp::static_kind():
      tp = &(gTypes[1173]);
      break;

    case mx::ir::llvm::VectorReduceSMaxOp::static_kind():
      tp = &(gTypes[1174]);
      break;

    case mx::ir::llvm::VectorReduceSMinOp::static_kind():
      tp = &(gTypes[1175]);
      break;

    case mx::ir::llvm::VectorReduceUMaxOp::static_kind():
      tp = &(gTypes[1176]);
      break;

    case mx::ir::llvm::VectorReduceUMinOp::static_kind():
      tp = &(gTypes[1177]);
      break;

    case mx::ir::llvm::VectorReduceXorOp::static_kind():
      tp = &(gTypes[1178]);
      break;

    case mx::ir::llvm::VScaleOp::static_kind():
      tp = &(gTypes[1179]);
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
  {}  // Sentinel.
};
}  // namespace

namespace {
static PyMethodDef gMethods[] = {
  {
    "FROM",
    reinterpret_cast<PyCFunction>(
        +[] (BorrowedPyObject *self, BorrowedPyObject * const *args, int num_args) -> SharedPyObject * {
          auto obj = T_cast(self);
          (void) args;
          while (num_args == 1) {
            auto arg_0 = PythonBinding<mx::ir::Operation>::from_python(args[0]);
            if (!arg_0.has_value()) {
              break;
            }

            return ::mx::to_python(obj->from(arg_0.value()));
          }

          PyErrorStreamer(PyExc_TypeError)
              << "Invalid arguments passed to 'FROM'";
          return nullptr;
        }),
    METH_FASTCALL | METH_STATIC,
    PyDoc_STR("Wrapper for mx::ir::llvm::Operation::from"),
  },
  {}  // Sentinel.
};
}  // namespace

namespace {

PyTypeObject *InitType(void) noexcept {
  PyTypeObject * const tp = &(gTypes[935]);
  tp->tp_basicsize = sizeof(O);
  tp->tp_itemsize = 0;
  tp->tp_dealloc = [] (::PyObject *obj) {
    if (auto *data = T_cast(obj)) {
      data->~T();
    }
    PyObject_Free(obj);
  };
  tp->tp_name = "multiplier.ir.llvm.Operation";
  tp->tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_DISALLOW_INSTANTIATION;
  tp->tp_doc = PyDoc_STR("Wrapper for mx::ir::llvm::::Operation");
  tp->tp_as_number = nullptr;
  tp->tp_as_sequence = nullptr;
  tp->tp_as_mapping = nullptr;
  tp->tp_hash = gTypes[931].tp_hash;
  tp->tp_richcompare = nullptr;
  tp->tp_iter = nullptr;
  tp->tp_methods = gMethods;
  tp->tp_getset = gProperties;
  tp->tp_base = &(gTypes[931]);
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
