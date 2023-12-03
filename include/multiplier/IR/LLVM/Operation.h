// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "../Operation.h"

namespace mlir::LLVM {
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
class GEPOp;
class GlobalCtorsOp;
class GlobalDtorsOp;
class GlobalOp;
class ICmpOp;
class InlineAsmOp;
class InsertElementOp;
class InsertValueOp;
class IntToPtrOp;
class InvokeOp;
class LLVMFuncOp;
class LShrOp;
class LandingpadOp;
class LoadOp;
class MetadataOp;
class MulOp;
class NullOp;
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
class UnreachableOp;
class XOrOp;
class ZExtOp;
class AbsOp;
class Annotation;
class AssumeOp;
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
class DbgDeclareOp;
class DbgLabelOp;
class DbgValueOp;
class DebugTrap;
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
class FshlOp;
class FshrOp;
class GetActiveLaneMaskOp;
class IsConstantOp;
class IsFPClass;
class LifetimeEndOp;
class LifetimeStartOp;
class LlrintOp;
class LlroundOp;
class Log10Op;
class Log2Op;
class LogOp;
class LrintOp;
class LroundOp;
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
class NearbyintOp;
class NoAliasScopeDeclOp;
class PowIOp;
class PowOp;
class Prefetch;
class PtrAnnotation;
class RintOp;
class RoundEvenOp;
class RoundOp;
class SAddSat;
class SAddWithOverflowOp;
class SMaxOp;
class SMinOp;
class SMulWithOverflowOp;
class SSACopyOp;
class SSHLSat;
class SSubSat;
class SSubWithOverflowOp;
class SinOp;
class SqrtOp;
class StackRestoreOp;
class StackSaveOp;
class StepVectorOp;
class ThreadlocalAddressOp;
class Trap;
class UAddSat;
class UAddWithOverflowOp;
class UBSanTrap;
class UMaxOp;
class UMinOp;
class UMulWithOverflowOp;
class USHLSat;
class USubSat;
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
class VarAnnotation;
class masked_compressstore;
class masked_expandload;
class masked_gather;
class masked_scatter;
class vector_extract;
class vector_insert;
class vector_reduce_add;
class vector_reduce_and;
class vector_reduce_fadd;
class vector_reduce_fmax;
class vector_reduce_fmaximum;
class vector_reduce_fmin;
class vector_reduce_fminimum;
class vector_reduce_fmul;
class vector_reduce_mul;
class vector_reduce_or;
class vector_reduce_smax;
class vector_reduce_smin;
class vector_reduce_umax;
class vector_reduce_umin;
class vector_reduce_xor;
class vscale;
}  // namespace mlir::LLVM
namespace mx::ir::llvm {

class MX_EXPORT Operation : public ::mx::ir::Operation {
 public:
  static std::optional<Operation> from(const ::mx::ir::Operation &);
};
static_assert(sizeof(Operation) == sizeof(::mx::ir::Operation));

class MX_EXPORT AShrOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_ASHR;
  }

  static std::optional<AShrOp> from(const ::mx::ir::Operation &that);
  static std::optional<AShrOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::AShrOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value lhs(void) const;
  ::mx::ir::Value rhs(void) const;
  ::mx::ir::Value res(void) const;
};
static_assert(sizeof(AShrOp) == sizeof(Operation));

class MX_EXPORT AddOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_ADD;
  }

  static std::optional<AddOp> from(const ::mx::ir::Operation &that);
  static std::optional<AddOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::AddOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value lhs(void) const;
  ::mx::ir::Value rhs(void) const;
  ::mx::ir::Value res(void) const;
};
static_assert(sizeof(AddOp) == sizeof(Operation));

class MX_EXPORT AddrSpaceCastOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_ADDRSPACECAST;
  }

  static std::optional<AddrSpaceCastOp> from(const ::mx::ir::Operation &that);
  static std::optional<AddrSpaceCastOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::AddrSpaceCastOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value arg(void) const;
  ::mx::ir::Value res(void) const;
};
static_assert(sizeof(AddrSpaceCastOp) == sizeof(Operation));

class MX_EXPORT AddressOfOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_MLIR_ADDRESSOF;
  }

  static std::optional<AddressOfOp> from(const ::mx::ir::Operation &that);
  static std::optional<AddressOfOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::AddressOfOp underlying_repr(void) const noexcept;

  // Imported methods:
  //::mlir::TypedValue<::mlir::LLVM::LLVMPointerType> res(void) const;
  std::string_view global_name(void) const;
};
static_assert(sizeof(AddressOfOp) == sizeof(Operation));

class MX_EXPORT AllocaOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_ALLOCA;
  }

  static std::optional<AllocaOp> from(const ::mx::ir::Operation &that);
  static std::optional<AllocaOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::AllocaOp underlying_repr(void) const noexcept;

  // Imported methods:
  //::mlir::TypedValue<::mlir::IntegerType> array_size(void) const;
  //::mlir::TypedValue<::mlir::LLVM::LLVMPointerType> res(void) const;
  //::std::optional<uint64_t> alignment(void) const;
  //::std::optional<::mlir::Type> elem_type(void) const;
  bool inalloca(void) const;
  //::llvm::SmallVector<::mlir::MemorySlot> promotable_slots(void) const;
  //::llvm::SmallVector<::mlir::DestructurableMemorySlot> destructurable_slots(void) const;
  //Type result_ptr_element_type(void) const;
};
static_assert(sizeof(AllocaOp) == sizeof(Operation));

class MX_EXPORT AndOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_AND;
  }

  static std::optional<AndOp> from(const ::mx::ir::Operation &that);
  static std::optional<AndOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::AndOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value lhs(void) const;
  ::mx::ir::Value rhs(void) const;
  ::mx::ir::Value res(void) const;
};
static_assert(sizeof(AndOp) == sizeof(Operation));

class MX_EXPORT AtomicCmpXchgOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_CMPXCHG;
  }

  static std::optional<AtomicCmpXchgOp> from(const ::mx::ir::Operation &that);
  static std::optional<AtomicCmpXchgOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::AtomicCmpXchgOp underlying_repr(void) const noexcept;

  // Imported methods:
  //::mlir::TypedValue<::mlir::LLVM::LLVMPointerType> ptr(void) const;
  ::mx::ir::Value cmp(void) const;
  ::mx::ir::Value val(void) const;
  ::mx::ir::Value res(void) const;
  //::mlir::LLVM::AtomicOrdering success_ordering(void) const;
  //::mlir::LLVM::AtomicOrdering failure_ordering(void) const;
  std::optional<std::string_view> syncscope(void) const;
  //::std::optional<uint64_t> alignment(void) const;
  bool weak(void) const;
  bool volatile__(void) const;
  //::std::optional<::mlir::ArrayAttr> access_groups(void) const;
  //::std::optional<::mlir::ArrayAttr> alias_scopes(void) const;
  //::std::optional<::mlir::ArrayAttr> noalias_scopes(void) const;
  //::std::optional<::mlir::ArrayAttr> tbaa(void) const;
  //::llvm::SmallVector<::mlir::Value> accessed_operands(void) const;
};
static_assert(sizeof(AtomicCmpXchgOp) == sizeof(Operation));

class MX_EXPORT AtomicRMWOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_ATOMICRMW;
  }

  static std::optional<AtomicRMWOp> from(const ::mx::ir::Operation &that);
  static std::optional<AtomicRMWOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::AtomicRMWOp underlying_repr(void) const noexcept;

  // Imported methods:
  //::mlir::TypedValue<::mlir::LLVM::LLVMPointerType> ptr(void) const;
  ::mx::ir::Value val(void) const;
  ::mx::ir::Value res(void) const;
  //::mlir::LLVM::AtomicBinOp bin_op(void) const;
  //::mlir::LLVM::AtomicOrdering ordering(void) const;
  std::optional<std::string_view> syncscope(void) const;
  //::std::optional<uint64_t> alignment(void) const;
  bool volatile__(void) const;
  //::std::optional<::mlir::ArrayAttr> access_groups(void) const;
  //::std::optional<::mlir::ArrayAttr> alias_scopes(void) const;
  //::std::optional<::mlir::ArrayAttr> noalias_scopes(void) const;
  //::std::optional<::mlir::ArrayAttr> tbaa(void) const;
  //::llvm::SmallVector<::mlir::Value> accessed_operands(void) const;
};
static_assert(sizeof(AtomicRMWOp) == sizeof(Operation));

class MX_EXPORT BitcastOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_BITCAST;
  }

  static std::optional<BitcastOp> from(const ::mx::ir::Operation &that);
  static std::optional<BitcastOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::BitcastOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value arg(void) const;
  ::mx::ir::Value res(void) const;
};
static_assert(sizeof(BitcastOp) == sizeof(Operation));

class MX_EXPORT BrOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_BR;
  }

  static std::optional<BrOp> from(const ::mx::ir::Operation &that);
  static std::optional<BrOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::BrOp underlying_repr(void) const noexcept;

  // Imported methods:
  gap::generator<::mx::ir::Operand> dest_operands(void) const;
  //::mlir::Block* dest(void) const;
  //::std::optional<::mlir::LLVM::LoopAnnotationAttr> loop_annotation(void) const;
};
static_assert(sizeof(BrOp) == sizeof(Operation));

class MX_EXPORT CallOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_CALL;
  }

  static std::optional<CallOp> from(const ::mx::ir::Operation &that);
  static std::optional<CallOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::CallOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value result(void) const;
  std::optional<std::string_view> callee(void) const;
  //::mlir::LLVM::FastmathFlags fastmath_flags(void) const;
  //::std::optional<::llvm::ArrayRef<int32_t>> branch_weights(void) const;
  //::std::optional<::mlir::ArrayAttr> access_groups(void) const;
  //::std::optional<::mlir::ArrayAttr> alias_scopes(void) const;
  //::std::optional<::mlir::ArrayAttr> noalias_scopes(void) const;
  //::std::optional<::mlir::ArrayAttr> tbaa(void) const;
  //::llvm::SmallVector<::mlir::Value> accessed_operands(void) const;
  //::mlir::CallInterfaceCallable callable_for_callee(void) const;
  gap::generator<::mx::ir::Operand> arg_operands(void) const;
};
static_assert(sizeof(CallOp) == sizeof(Operation));

class MX_EXPORT ComdatOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_COMDAT;
  }

  static std::optional<ComdatOp> from(const ::mx::ir::Operation &that);
  static std::optional<ComdatOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::ComdatOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Region body(void) const;
  std::string_view sym_name(void) const;
};
static_assert(sizeof(ComdatOp) == sizeof(Operation));

class MX_EXPORT ComdatSelectorOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_COMDAT_SELECTOR;
  }

  static std::optional<ComdatSelectorOp> from(const ::mx::ir::Operation &that);
  static std::optional<ComdatSelectorOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::ComdatSelectorOp underlying_repr(void) const noexcept;

  // Imported methods:
  std::string_view sym_name(void) const;
  //::mlir::LLVM::comdat::Comdat comdat(void) const;
};
static_assert(sizeof(ComdatSelectorOp) == sizeof(Operation));

class MX_EXPORT CondBrOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_COND_BR;
  }

  static std::optional<CondBrOp> from(const ::mx::ir::Operation &that);
  static std::optional<CondBrOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::CondBrOp underlying_repr(void) const noexcept;

  // Imported methods:
  //::mlir::TypedValue<::mlir::IntegerType> condition(void) const;
  gap::generator<::mx::ir::Operand> true_dest_operands(void) const;
  gap::generator<::mx::ir::Operand> false_dest_operands(void) const;
  //::mlir::Block* true_dest(void) const;
  //::mlir::Block* false_dest(void) const;
  //::std::optional<::llvm::ArrayRef<int32_t>> branch_weights(void) const;
  //::std::optional<::mlir::LLVM::LoopAnnotationAttr> loop_annotation(void) const;
};
static_assert(sizeof(CondBrOp) == sizeof(Operation));

class MX_EXPORT ConstantOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_MLIR_CONSTANT;
  }

  static std::optional<ConstantOp> from(const ::mx::ir::Operation &that);
  static std::optional<ConstantOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::ConstantOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value res(void) const;
  //::mlir::Attribute value(void) const;
};
static_assert(sizeof(ConstantOp) == sizeof(Operation));

class MX_EXPORT ExtractElementOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_EXTRACTELEMENT;
  }

  static std::optional<ExtractElementOp> from(const ::mx::ir::Operation &that);
  static std::optional<ExtractElementOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::ExtractElementOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value vector(void) const;
  //::mlir::TypedValue<::mlir::IntegerType> position(void) const;
  ::mx::ir::Value res(void) const;
};
static_assert(sizeof(ExtractElementOp) == sizeof(Operation));

class MX_EXPORT ExtractValueOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_EXTRACTVALUE;
  }

  static std::optional<ExtractValueOp> from(const ::mx::ir::Operation &that);
  static std::optional<ExtractValueOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::ExtractValueOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value container(void) const;
  ::mx::ir::Value res(void) const;
  //::llvm::ArrayRef<int64_t> position(void) const;
};
static_assert(sizeof(ExtractValueOp) == sizeof(Operation));

class MX_EXPORT FAddOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_FADD;
  }

  static std::optional<FAddOp> from(const ::mx::ir::Operation &that);
  static std::optional<FAddOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::FAddOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value lhs(void) const;
  ::mx::ir::Value rhs(void) const;
  ::mx::ir::Value res(void) const;
  //::mlir::LLVM::FastmathFlags fastmath_flags(void) const;
};
static_assert(sizeof(FAddOp) == sizeof(Operation));

class MX_EXPORT FCmpOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_FCMP;
  }

  static std::optional<FCmpOp> from(const ::mx::ir::Operation &that);
  static std::optional<FCmpOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::FCmpOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value lhs(void) const;
  ::mx::ir::Value rhs(void) const;
  ::mx::ir::Value res(void) const;
  //::mlir::LLVM::FCmpPredicate predicate(void) const;
  //::mlir::LLVM::FastmathFlags fastmath_flags(void) const;
};
static_assert(sizeof(FCmpOp) == sizeof(Operation));

class MX_EXPORT FDivOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_FDIV;
  }

  static std::optional<FDivOp> from(const ::mx::ir::Operation &that);
  static std::optional<FDivOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::FDivOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value lhs(void) const;
  ::mx::ir::Value rhs(void) const;
  ::mx::ir::Value res(void) const;
  //::mlir::LLVM::FastmathFlags fastmath_flags(void) const;
};
static_assert(sizeof(FDivOp) == sizeof(Operation));

class MX_EXPORT FMulOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_FMUL;
  }

  static std::optional<FMulOp> from(const ::mx::ir::Operation &that);
  static std::optional<FMulOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::FMulOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value lhs(void) const;
  ::mx::ir::Value rhs(void) const;
  ::mx::ir::Value res(void) const;
  //::mlir::LLVM::FastmathFlags fastmath_flags(void) const;
};
static_assert(sizeof(FMulOp) == sizeof(Operation));

class MX_EXPORT FNegOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_FNEG;
  }

  static std::optional<FNegOp> from(const ::mx::ir::Operation &that);
  static std::optional<FNegOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::FNegOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value operand(void) const;
  ::mx::ir::Value res(void) const;
  //::mlir::LLVM::FastmathFlags fastmath_flags(void) const;
};
static_assert(sizeof(FNegOp) == sizeof(Operation));

class MX_EXPORT FPExtOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_FPEXT;
  }

  static std::optional<FPExtOp> from(const ::mx::ir::Operation &that);
  static std::optional<FPExtOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::FPExtOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value arg(void) const;
  ::mx::ir::Value res(void) const;
};
static_assert(sizeof(FPExtOp) == sizeof(Operation));

class MX_EXPORT FPToSIOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_FPTOSI;
  }

  static std::optional<FPToSIOp> from(const ::mx::ir::Operation &that);
  static std::optional<FPToSIOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::FPToSIOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value arg(void) const;
  ::mx::ir::Value res(void) const;
};
static_assert(sizeof(FPToSIOp) == sizeof(Operation));

class MX_EXPORT FPToUIOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_FPTOUI;
  }

  static std::optional<FPToUIOp> from(const ::mx::ir::Operation &that);
  static std::optional<FPToUIOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::FPToUIOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value arg(void) const;
  ::mx::ir::Value res(void) const;
};
static_assert(sizeof(FPToUIOp) == sizeof(Operation));

class MX_EXPORT FPTruncOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_FPTRUNC;
  }

  static std::optional<FPTruncOp> from(const ::mx::ir::Operation &that);
  static std::optional<FPTruncOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::FPTruncOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value arg(void) const;
  ::mx::ir::Value res(void) const;
};
static_assert(sizeof(FPTruncOp) == sizeof(Operation));

class MX_EXPORT FRemOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_FREM;
  }

  static std::optional<FRemOp> from(const ::mx::ir::Operation &that);
  static std::optional<FRemOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::FRemOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value lhs(void) const;
  ::mx::ir::Value rhs(void) const;
  ::mx::ir::Value res(void) const;
  //::mlir::LLVM::FastmathFlags fastmath_flags(void) const;
};
static_assert(sizeof(FRemOp) == sizeof(Operation));

class MX_EXPORT FSubOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_FSUB;
  }

  static std::optional<FSubOp> from(const ::mx::ir::Operation &that);
  static std::optional<FSubOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::FSubOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value lhs(void) const;
  ::mx::ir::Value rhs(void) const;
  ::mx::ir::Value res(void) const;
  //::mlir::LLVM::FastmathFlags fastmath_flags(void) const;
};
static_assert(sizeof(FSubOp) == sizeof(Operation));

class MX_EXPORT FenceOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_FENCE;
  }

  static std::optional<FenceOp> from(const ::mx::ir::Operation &that);
  static std::optional<FenceOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::FenceOp underlying_repr(void) const noexcept;

  // Imported methods:
  //::mlir::LLVM::AtomicOrdering ordering(void) const;
  std::optional<std::string_view> syncscope(void) const;
};
static_assert(sizeof(FenceOp) == sizeof(Operation));

class MX_EXPORT FreezeOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_FREEZE;
  }

  static std::optional<FreezeOp> from(const ::mx::ir::Operation &that);
  static std::optional<FreezeOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::FreezeOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value val(void) const;
  ::mx::ir::Value res(void) const;
};
static_assert(sizeof(FreezeOp) == sizeof(Operation));

class MX_EXPORT GetElementPtrOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_GETELEMENTPTR;
  }

  static std::optional<GetElementPtrOp> from(const ::mx::ir::Operation &that);
  static std::optional<GetElementPtrOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::GEPOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value base(void) const;
  gap::generator<::mx::ir::Operand> dynamic_indices(void) const;
  ::mx::ir::Value res(void) const;
  //::llvm::ArrayRef<int32_t> raw_constant_indices(void) const;
  //::std::optional<::mlir::Type> elem_type(void) const;
  bool inbounds(void) const;
  //Type result_ptr_element_type(void) const;
  //Type source_element_type(void) const;
  //GEPIndicesAdaptor<ValueRange> indices(void) const;
};
static_assert(sizeof(GetElementPtrOp) == sizeof(Operation));

class MX_EXPORT GlobalCtorsOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_MLIR_GLOBAL_CTORS;
  }

  static std::optional<GlobalCtorsOp> from(const ::mx::ir::Operation &that);
  static std::optional<GlobalCtorsOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::GlobalCtorsOp underlying_repr(void) const noexcept;

  // Imported methods:
  //::mlir::ArrayAttr ctors(void) const;
  //::mlir::ArrayAttr priorities(void) const;
};
static_assert(sizeof(GlobalCtorsOp) == sizeof(Operation));

class MX_EXPORT GlobalDtorsOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_MLIR_GLOBAL_DTORS;
  }

  static std::optional<GlobalDtorsOp> from(const ::mx::ir::Operation &that);
  static std::optional<GlobalDtorsOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::GlobalDtorsOp underlying_repr(void) const noexcept;

  // Imported methods:
  //::mlir::ArrayAttr dtors(void) const;
  //::mlir::ArrayAttr priorities(void) const;
};
static_assert(sizeof(GlobalDtorsOp) == sizeof(Operation));

class MX_EXPORT GlobalOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_MLIR_GLOBAL;
  }

  static std::optional<GlobalOp> from(const ::mx::ir::Operation &that);
  static std::optional<GlobalOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::GlobalOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Region initializer(void) const;
  //::mlir::Type global_type(void) const;
  bool constant(void) const;
  std::string_view sym_name(void) const;
  //::mlir::LLVM::Linkage linkage(void) const;
  bool dso_local(void) const;
  bool thread_local__(void) const;
  //::std::optional<::mlir::Attribute> value(void) const;
  //::std::optional<uint64_t> alignment(void) const;
  uint32_t addr_space(void) const;
  //::std::optional<::mlir::LLVM::UnnamedAddr> unnamed_addr(void) const;
  std::optional<std::string_view> section(void) const;
  //::std::optional<::mlir::SymbolRefAttr> comdat(void) const;
  //::mlir::LLVM::Visibility visibility__(void) const;
  //Type type(void) const;
  //Attribute value_or_null(void) const;
  //Region& initializer_region(void) const;
  //Block* initializer_block(void) const;
};
static_assert(sizeof(GlobalOp) == sizeof(Operation));

class MX_EXPORT ICmpOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_ICMP;
  }

  static std::optional<ICmpOp> from(const ::mx::ir::Operation &that);
  static std::optional<ICmpOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::ICmpOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value lhs(void) const;
  ::mx::ir::Value rhs(void) const;
  ::mx::ir::Value res(void) const;
  //::mlir::LLVM::ICmpPredicate predicate(void) const;
};
static_assert(sizeof(ICmpOp) == sizeof(Operation));

class MX_EXPORT InlineAsmOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INLINE_ASM;
  }

  static std::optional<InlineAsmOp> from(const ::mx::ir::Operation &that);
  static std::optional<InlineAsmOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::InlineAsmOp underlying_repr(void) const noexcept;

  // Imported methods:
  gap::generator<::mx::ir::Operand> operands(void) const;
  ::mx::ir::Value res(void) const;
  std::string_view asm_string(void) const;
  std::string_view constraints(void) const;
  bool has_side_effects(void) const;
  bool is_align_stack(void) const;
  //::std::optional<::mlir::LLVM::AsmDialect> asm_dialect(void) const;
  //::std::optional<::mlir::ArrayAttr> operand_attrs(void) const;
};
static_assert(sizeof(InlineAsmOp) == sizeof(Operation));

class MX_EXPORT InsertElementOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INSERTELEMENT;
  }

  static std::optional<InsertElementOp> from(const ::mx::ir::Operation &that);
  static std::optional<InsertElementOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::InsertElementOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value vector(void) const;
  ::mx::ir::Value value(void) const;
  //::mlir::TypedValue<::mlir::IntegerType> position(void) const;
  ::mx::ir::Value res(void) const;
};
static_assert(sizeof(InsertElementOp) == sizeof(Operation));

class MX_EXPORT InsertValueOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INSERTVALUE;
  }

  static std::optional<InsertValueOp> from(const ::mx::ir::Operation &that);
  static std::optional<InsertValueOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::InsertValueOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value container(void) const;
  ::mx::ir::Value value(void) const;
  ::mx::ir::Value res(void) const;
  //::llvm::ArrayRef<int64_t> position(void) const;
};
static_assert(sizeof(InsertValueOp) == sizeof(Operation));

class MX_EXPORT IntToPtrOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTTOPTR;
  }

  static std::optional<IntToPtrOp> from(const ::mx::ir::Operation &that);
  static std::optional<IntToPtrOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::IntToPtrOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value arg(void) const;
  ::mx::ir::Value res(void) const;
};
static_assert(sizeof(IntToPtrOp) == sizeof(Operation));

class MX_EXPORT InvokeOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INVOKE;
  }

  static std::optional<InvokeOp> from(const ::mx::ir::Operation &that);
  static std::optional<InvokeOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::InvokeOp underlying_repr(void) const noexcept;

  // Imported methods:
  gap::generator<::mx::ir::Operand> callee_operands(void) const;
  gap::generator<::mx::ir::Operand> normal_dest_operands(void) const;
  gap::generator<::mx::ir::Operand> unwind_dest_operands(void) const;
  //::mlir::Block* normal_dest(void) const;
  //::mlir::Block* unwind_dest(void) const;
  std::optional<std::string_view> callee(void) const;
  //::std::optional<::llvm::ArrayRef<int32_t>> branch_weights(void) const;
  //::mlir::CallInterfaceCallable callable_for_callee(void) const;
  gap::generator<::mx::ir::Operand> arg_operands(void) const;
};
static_assert(sizeof(InvokeOp) == sizeof(Operation));

class MX_EXPORT FuncOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_FUNC;
  }

  static std::optional<FuncOp> from(const ::mx::ir::Operation &that);
  static std::optional<FuncOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::LLVMFuncOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Region body(void) const;
  std::string_view sym_name(void) const;
  //::mlir::LLVM::LLVMFunctionType function_type(void) const;
  //::mlir::LLVM::Linkage linkage(void) const;
  bool dso_local(void) const;
  //::mlir::LLVM::cconv::CConv c_conv(void) const;
  //::std::optional<::mlir::SymbolRefAttr> comdat(void) const;
  std::optional<std::string_view> personality(void) const;
  std::optional<std::string_view> garbage_collector(void) const;
  //::std::optional<::mlir::ArrayAttr> passthrough(void) const;
  //::std::optional<::mlir::ArrayAttr> arg_attrs(void) const;
  //::std::optional<::mlir::ArrayAttr> res_attrs(void) const;
  //::std::optional<uint64_t> function_entry_count(void) const;
  //::std::optional<::mlir::LLVM::MemoryEffectsAttr> memory(void) const;
  //::mlir::LLVM::Visibility visibility__(void) const;
  //::std::optional<bool> arm_streaming(void) const;
  //::std::optional<bool> arm_locally_streaming(void) const;
  std::optional<std::string_view> section(void) const;
  //::std::optional<::mlir::LLVM::UnnamedAddr> unnamed_addr(void) const;
  //::std::optional<uint64_t> alignment(void) const;
  //Block* add_entry_block(void) const;
  bool is_var_arg(void) const;
  //ArrayRef<Type> argument_types(void) const;
  //ArrayRef<Type> result_types(void) const;
  //Region* callable_region(void) const;
  //ArrayRef<Type> callable_results(void) const;
  //::mlir::ArrayAttr callable_arg_attrs(void) const;
  //::mlir::ArrayAttr callable_res_attrs(void) const;
};
static_assert(sizeof(FuncOp) == sizeof(Operation));

class MX_EXPORT LShrOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_LSHR;
  }

  static std::optional<LShrOp> from(const ::mx::ir::Operation &that);
  static std::optional<LShrOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::LShrOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value lhs(void) const;
  ::mx::ir::Value rhs(void) const;
  ::mx::ir::Value res(void) const;
};
static_assert(sizeof(LShrOp) == sizeof(Operation));

class MX_EXPORT LandingpadOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_LANDINGPAD;
  }

  static std::optional<LandingpadOp> from(const ::mx::ir::Operation &that);
  static std::optional<LandingpadOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::LandingpadOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value res(void) const;
  bool cleanup(void) const;
};
static_assert(sizeof(LandingpadOp) == sizeof(Operation));

class MX_EXPORT LoadOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_LOAD;
  }

  static std::optional<LoadOp> from(const ::mx::ir::Operation &that);
  static std::optional<LoadOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::LoadOp underlying_repr(void) const noexcept;

  // Imported methods:
  //::mlir::TypedValue<::mlir::LLVM::LLVMPointerType> addr(void) const;
  ::mx::ir::Value res(void) const;
  //::std::optional<uint64_t> alignment(void) const;
  bool volatile__(void) const;
  bool nontemporal(void) const;
  //::mlir::LLVM::AtomicOrdering ordering(void) const;
  std::optional<std::string_view> syncscope(void) const;
  //::std::optional<::mlir::ArrayAttr> access_groups(void) const;
  //::std::optional<::mlir::ArrayAttr> alias_scopes(void) const;
  //::std::optional<::mlir::ArrayAttr> noalias_scopes(void) const;
  //::std::optional<::mlir::ArrayAttr> tbaa(void) const;
  //::llvm::SmallVector<::mlir::Value> accessed_operands(void) const;
};
static_assert(sizeof(LoadOp) == sizeof(Operation));

class MX_EXPORT MetadataOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_METADATA;
  }

  static std::optional<MetadataOp> from(const ::mx::ir::Operation &that);
  static std::optional<MetadataOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::MetadataOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Region body(void) const;
  std::string_view sym_name(void) const;
};
static_assert(sizeof(MetadataOp) == sizeof(Operation));

class MX_EXPORT MulOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_MUL;
  }

  static std::optional<MulOp> from(const ::mx::ir::Operation &that);
  static std::optional<MulOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::MulOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value lhs(void) const;
  ::mx::ir::Value rhs(void) const;
  ::mx::ir::Value res(void) const;
};
static_assert(sizeof(MulOp) == sizeof(Operation));

class MX_EXPORT NullOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_MLIR_NULL;
  }

  static std::optional<NullOp> from(const ::mx::ir::Operation &that);
  static std::optional<NullOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::NullOp underlying_repr(void) const noexcept;

  // Imported methods:
  //::mlir::TypedValue<::mlir::LLVM::LLVMPointerType> res(void) const;
};
static_assert(sizeof(NullOp) == sizeof(Operation));

class MX_EXPORT OrOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_OR;
  }

  static std::optional<OrOp> from(const ::mx::ir::Operation &that);
  static std::optional<OrOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::OrOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value lhs(void) const;
  ::mx::ir::Value rhs(void) const;
  ::mx::ir::Value res(void) const;
};
static_assert(sizeof(OrOp) == sizeof(Operation));

class MX_EXPORT PoisonOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_MLIR_POISON;
  }

  static std::optional<PoisonOp> from(const ::mx::ir::Operation &that);
  static std::optional<PoisonOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::PoisonOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value res(void) const;
};
static_assert(sizeof(PoisonOp) == sizeof(Operation));

class MX_EXPORT PtrToIntOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_PTRTOINT;
  }

  static std::optional<PtrToIntOp> from(const ::mx::ir::Operation &that);
  static std::optional<PtrToIntOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::PtrToIntOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value arg(void) const;
  ::mx::ir::Value res(void) const;
};
static_assert(sizeof(PtrToIntOp) == sizeof(Operation));

class MX_EXPORT ResumeOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_RESUME;
  }

  static std::optional<ResumeOp> from(const ::mx::ir::Operation &that);
  static std::optional<ResumeOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::ResumeOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value value(void) const;
};
static_assert(sizeof(ResumeOp) == sizeof(Operation));

class MX_EXPORT ReturnOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_RETURN;
  }

  static std::optional<ReturnOp> from(const ::mx::ir::Operation &that);
  static std::optional<ReturnOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::ReturnOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value arg(void) const;
};
static_assert(sizeof(ReturnOp) == sizeof(Operation));

class MX_EXPORT SDivOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_SDIV;
  }

  static std::optional<SDivOp> from(const ::mx::ir::Operation &that);
  static std::optional<SDivOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::SDivOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value lhs(void) const;
  ::mx::ir::Value rhs(void) const;
  ::mx::ir::Value res(void) const;
};
static_assert(sizeof(SDivOp) == sizeof(Operation));

class MX_EXPORT SExtOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_SEXT;
  }

  static std::optional<SExtOp> from(const ::mx::ir::Operation &that);
  static std::optional<SExtOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::SExtOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value arg(void) const;
  ::mx::ir::Value res(void) const;
};
static_assert(sizeof(SExtOp) == sizeof(Operation));

class MX_EXPORT SIToFPOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_SITOFP;
  }

  static std::optional<SIToFPOp> from(const ::mx::ir::Operation &that);
  static std::optional<SIToFPOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::SIToFPOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value arg(void) const;
  ::mx::ir::Value res(void) const;
};
static_assert(sizeof(SIToFPOp) == sizeof(Operation));

class MX_EXPORT SRemOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_SREM;
  }

  static std::optional<SRemOp> from(const ::mx::ir::Operation &that);
  static std::optional<SRemOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::SRemOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value lhs(void) const;
  ::mx::ir::Value rhs(void) const;
  ::mx::ir::Value res(void) const;
};
static_assert(sizeof(SRemOp) == sizeof(Operation));

class MX_EXPORT SelectOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_SELECT;
  }

  static std::optional<SelectOp> from(const ::mx::ir::Operation &that);
  static std::optional<SelectOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::SelectOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value condition(void) const;
  ::mx::ir::Value true_value(void) const;
  ::mx::ir::Value false_value(void) const;
  ::mx::ir::Value res(void) const;
  //::mlir::LLVM::FastmathFlags fastmath_flags(void) const;
};
static_assert(sizeof(SelectOp) == sizeof(Operation));

class MX_EXPORT ShlOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_SHL;
  }

  static std::optional<ShlOp> from(const ::mx::ir::Operation &that);
  static std::optional<ShlOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::ShlOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value lhs(void) const;
  ::mx::ir::Value rhs(void) const;
  ::mx::ir::Value res(void) const;
};
static_assert(sizeof(ShlOp) == sizeof(Operation));

class MX_EXPORT ShuffleVectorOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_SHUFFLEVECTOR;
  }

  static std::optional<ShuffleVectorOp> from(const ::mx::ir::Operation &that);
  static std::optional<ShuffleVectorOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::ShuffleVectorOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value v1(void) const;
  ::mx::ir::Value v2(void) const;
  ::mx::ir::Value res(void) const;
  //::llvm::ArrayRef<int32_t> mask(void) const;
};
static_assert(sizeof(ShuffleVectorOp) == sizeof(Operation));

class MX_EXPORT StoreOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_STORE;
  }

  static std::optional<StoreOp> from(const ::mx::ir::Operation &that);
  static std::optional<StoreOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::StoreOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value value(void) const;
  //::mlir::TypedValue<::mlir::LLVM::LLVMPointerType> addr(void) const;
  //::std::optional<uint64_t> alignment(void) const;
  bool volatile__(void) const;
  bool nontemporal(void) const;
  //::mlir::LLVM::AtomicOrdering ordering(void) const;
  std::optional<std::string_view> syncscope(void) const;
  //::std::optional<::mlir::ArrayAttr> access_groups(void) const;
  //::std::optional<::mlir::ArrayAttr> alias_scopes(void) const;
  //::std::optional<::mlir::ArrayAttr> noalias_scopes(void) const;
  //::std::optional<::mlir::ArrayAttr> tbaa(void) const;
  //::llvm::SmallVector<::mlir::Value> accessed_operands(void) const;
};
static_assert(sizeof(StoreOp) == sizeof(Operation));

class MX_EXPORT SubOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_SUB;
  }

  static std::optional<SubOp> from(const ::mx::ir::Operation &that);
  static std::optional<SubOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::SubOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value lhs(void) const;
  ::mx::ir::Value rhs(void) const;
  ::mx::ir::Value res(void) const;
};
static_assert(sizeof(SubOp) == sizeof(Operation));

class MX_EXPORT SwitchOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_SWITCH;
  }

  static std::optional<SwitchOp> from(const ::mx::ir::Operation &that);
  static std::optional<SwitchOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::SwitchOp underlying_repr(void) const noexcept;

  // Imported methods:
  //::mlir::TypedValue<::mlir::IntegerType> value(void) const;
  gap::generator<::mx::ir::Operand> default_operands(void) const;
  //::mlir::OperandRangeRange case_operands(void) const;
  //::mlir::Block* default_destination(void) const;
  //::mlir::SuccessorRange case_destinations(void) const;
  //::std::optional<::mlir::DenseIntElementsAttr> case_values(void) const;
  //::llvm::ArrayRef<int32_t> case_operand_segments(void) const;
  //::std::optional<::llvm::ArrayRef<int32_t>> branch_weights(void) const;
};
static_assert(sizeof(SwitchOp) == sizeof(Operation));

class MX_EXPORT TruncOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_TRUNC;
  }

  static std::optional<TruncOp> from(const ::mx::ir::Operation &that);
  static std::optional<TruncOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::TruncOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value arg(void) const;
  ::mx::ir::Value res(void) const;
};
static_assert(sizeof(TruncOp) == sizeof(Operation));

class MX_EXPORT UDivOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_UDIV;
  }

  static std::optional<UDivOp> from(const ::mx::ir::Operation &that);
  static std::optional<UDivOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::UDivOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value lhs(void) const;
  ::mx::ir::Value rhs(void) const;
  ::mx::ir::Value res(void) const;
};
static_assert(sizeof(UDivOp) == sizeof(Operation));

class MX_EXPORT UIToFPOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_UITOFP;
  }

  static std::optional<UIToFPOp> from(const ::mx::ir::Operation &that);
  static std::optional<UIToFPOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::UIToFPOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value arg(void) const;
  ::mx::ir::Value res(void) const;
};
static_assert(sizeof(UIToFPOp) == sizeof(Operation));

class MX_EXPORT URemOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_UREM;
  }

  static std::optional<URemOp> from(const ::mx::ir::Operation &that);
  static std::optional<URemOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::URemOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value lhs(void) const;
  ::mx::ir::Value rhs(void) const;
  ::mx::ir::Value res(void) const;
};
static_assert(sizeof(URemOp) == sizeof(Operation));

class MX_EXPORT UndefOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_MLIR_UNDEF;
  }

  static std::optional<UndefOp> from(const ::mx::ir::Operation &that);
  static std::optional<UndefOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::UndefOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value res(void) const;
};
static_assert(sizeof(UndefOp) == sizeof(Operation));

class MX_EXPORT UnreachableOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_UNREACHABLE;
  }

  static std::optional<UnreachableOp> from(const ::mx::ir::Operation &that);
  static std::optional<UnreachableOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::UnreachableOp underlying_repr(void) const noexcept;

  // Imported methods:
};
static_assert(sizeof(UnreachableOp) == sizeof(Operation));

class MX_EXPORT XOrOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_XOR;
  }

  static std::optional<XOrOp> from(const ::mx::ir::Operation &that);
  static std::optional<XOrOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::XOrOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value lhs(void) const;
  ::mx::ir::Value rhs(void) const;
  ::mx::ir::Value res(void) const;
};
static_assert(sizeof(XOrOp) == sizeof(Operation));

class MX_EXPORT ZExtOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_ZEXT;
  }

  static std::optional<ZExtOp> from(const ::mx::ir::Operation &that);
  static std::optional<ZExtOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::ZExtOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value arg(void) const;
  ::mx::ir::Value res(void) const;
};
static_assert(sizeof(ZExtOp) == sizeof(Operation));

class MX_EXPORT AbsOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_ABS;
  }

  static std::optional<AbsOp> from(const ::mx::ir::Operation &that);
  static std::optional<AbsOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::AbsOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value in(void) const;
  ::mx::ir::Value res(void) const;
  bool is_int_min_poison(void) const;
};
static_assert(sizeof(AbsOp) == sizeof(Operation));

class MX_EXPORT AnnotationOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_ANNOTATION;
  }

  static std::optional<AnnotationOp> from(const ::mx::ir::Operation &that);
  static std::optional<AnnotationOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::Annotation underlying_repr(void) const noexcept;

  // Imported methods:
  //::mlir::TypedValue<::mlir::IntegerType> integer(void) const;
  //::mlir::TypedValue<::mlir::LLVM::LLVMPointerType> annotation(void) const;
  //::mlir::TypedValue<::mlir::LLVM::LLVMPointerType> file_name(void) const;
  //::mlir::TypedValue<::mlir::IntegerType> line(void) const;
  //::mlir::TypedValue<::mlir::IntegerType> res(void) const;
};
static_assert(sizeof(AnnotationOp) == sizeof(Operation));

class MX_EXPORT AssumeOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_ASSUME;
  }

  static std::optional<AssumeOp> from(const ::mx::ir::Operation &that);
  static std::optional<AssumeOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::AssumeOp underlying_repr(void) const noexcept;

  // Imported methods:
  //::mlir::TypedValue<::mlir::IntegerType> cond(void) const;
};
static_assert(sizeof(AssumeOp) == sizeof(Operation));

class MX_EXPORT BitReverseOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_BITREVERSE;
  }

  static std::optional<BitReverseOp> from(const ::mx::ir::Operation &that);
  static std::optional<BitReverseOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::BitReverseOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value in(void) const;
  ::mx::ir::Value res(void) const;
};
static_assert(sizeof(BitReverseOp) == sizeof(Operation));

class MX_EXPORT ByteSwapOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_BSWAP;
  }

  static std::optional<ByteSwapOp> from(const ::mx::ir::Operation &that);
  static std::optional<ByteSwapOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::ByteSwapOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value in(void) const;
  ::mx::ir::Value res(void) const;
};
static_assert(sizeof(ByteSwapOp) == sizeof(Operation));

class MX_EXPORT CallIntrinsicOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_CALL_INTRINSIC;
  }

  static std::optional<CallIntrinsicOp> from(const ::mx::ir::Operation &that);
  static std::optional<CallIntrinsicOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::CallIntrinsicOp underlying_repr(void) const noexcept;

  // Imported methods:
  gap::generator<::mx::ir::Operand> args(void) const;
  gap::generator<::mx::ir::Result> results(void) const;
  std::string_view intrin(void) const;
  //::mlir::LLVM::FastmathFlags fastmath_flags(void) const;
};
static_assert(sizeof(CallIntrinsicOp) == sizeof(Operation));

class MX_EXPORT CopySignOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_COPYSIGN;
  }

  static std::optional<CopySignOp> from(const ::mx::ir::Operation &that);
  static std::optional<CopySignOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::CopySignOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value a(void) const;
  ::mx::ir::Value b(void) const;
  ::mx::ir::Value res(void) const;
  //::mlir::LLVM::FastmathFlags fastmath_flags(void) const;
};
static_assert(sizeof(CopySignOp) == sizeof(Operation));

class MX_EXPORT CoroAlignOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_CORO_ALIGN;
  }

  static std::optional<CoroAlignOp> from(const ::mx::ir::Operation &that);
  static std::optional<CoroAlignOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::CoroAlignOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value res(void) const;
};
static_assert(sizeof(CoroAlignOp) == sizeof(Operation));

class MX_EXPORT CoroBeginOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_CORO_BEGIN;
  }

  static std::optional<CoroBeginOp> from(const ::mx::ir::Operation &that);
  static std::optional<CoroBeginOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::CoroBeginOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value token(void) const;
  ::mx::ir::Value mem(void) const;
  ::mx::ir::Value res(void) const;
};
static_assert(sizeof(CoroBeginOp) == sizeof(Operation));

class MX_EXPORT CoroEndOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_CORO_END;
  }

  static std::optional<CoroEndOp> from(const ::mx::ir::Operation &that);
  static std::optional<CoroEndOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::CoroEndOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value handle(void) const;
  //::mlir::TypedValue<::mlir::IntegerType> unwind(void) const;
  ::mx::ir::Value res(void) const;
};
static_assert(sizeof(CoroEndOp) == sizeof(Operation));

class MX_EXPORT CoroFreeOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_CORO_FREE;
  }

  static std::optional<CoroFreeOp> from(const ::mx::ir::Operation &that);
  static std::optional<CoroFreeOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::CoroFreeOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value id(void) const;
  ::mx::ir::Value handle(void) const;
  ::mx::ir::Value res(void) const;
};
static_assert(sizeof(CoroFreeOp) == sizeof(Operation));

class MX_EXPORT CoroIdOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_CORO_ID;
  }

  static std::optional<CoroIdOp> from(const ::mx::ir::Operation &that);
  static std::optional<CoroIdOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::CoroIdOp underlying_repr(void) const noexcept;

  // Imported methods:
  //::mlir::TypedValue<::mlir::IntegerType> align(void) const;
  ::mx::ir::Value promise(void) const;
  ::mx::ir::Value coroaddr(void) const;
  ::mx::ir::Value fnaddrs(void) const;
  ::mx::ir::Value res(void) const;
};
static_assert(sizeof(CoroIdOp) == sizeof(Operation));

class MX_EXPORT CoroResumeOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_CORO_RESUME;
  }

  static std::optional<CoroResumeOp> from(const ::mx::ir::Operation &that);
  static std::optional<CoroResumeOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::CoroResumeOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value handle(void) const;
};
static_assert(sizeof(CoroResumeOp) == sizeof(Operation));

class MX_EXPORT CoroSaveOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_CORO_SAVE;
  }

  static std::optional<CoroSaveOp> from(const ::mx::ir::Operation &that);
  static std::optional<CoroSaveOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::CoroSaveOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value handle(void) const;
  ::mx::ir::Value res(void) const;
};
static_assert(sizeof(CoroSaveOp) == sizeof(Operation));

class MX_EXPORT CoroSizeOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_CORO_SIZE;
  }

  static std::optional<CoroSizeOp> from(const ::mx::ir::Operation &that);
  static std::optional<CoroSizeOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::CoroSizeOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value res(void) const;
};
static_assert(sizeof(CoroSizeOp) == sizeof(Operation));

class MX_EXPORT CoroSuspendOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_CORO_SUSPEND;
  }

  static std::optional<CoroSuspendOp> from(const ::mx::ir::Operation &that);
  static std::optional<CoroSuspendOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::CoroSuspendOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value save(void) const;
  //::mlir::TypedValue<::mlir::IntegerType> final(void) const;
  ::mx::ir::Value res(void) const;
};
static_assert(sizeof(CoroSuspendOp) == sizeof(Operation));

class MX_EXPORT CosOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_COS;
  }

  static std::optional<CosOp> from(const ::mx::ir::Operation &that);
  static std::optional<CosOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::CosOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value in(void) const;
  ::mx::ir::Value res(void) const;
  //::mlir::LLVM::FastmathFlags fastmath_flags(void) const;
};
static_assert(sizeof(CosOp) == sizeof(Operation));

class MX_EXPORT CountLeadingZerosOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_CTLZ;
  }

  static std::optional<CountLeadingZerosOp> from(const ::mx::ir::Operation &that);
  static std::optional<CountLeadingZerosOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::CountLeadingZerosOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value in(void) const;
  ::mx::ir::Value res(void) const;
  bool is_zero_poison(void) const;
};
static_assert(sizeof(CountLeadingZerosOp) == sizeof(Operation));

class MX_EXPORT CountTrailingZerosOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_CTTZ;
  }

  static std::optional<CountTrailingZerosOp> from(const ::mx::ir::Operation &that);
  static std::optional<CountTrailingZerosOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::CountTrailingZerosOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value in(void) const;
  ::mx::ir::Value res(void) const;
  bool is_zero_poison(void) const;
};
static_assert(sizeof(CountTrailingZerosOp) == sizeof(Operation));

class MX_EXPORT CtPopOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_CTPOP;
  }

  static std::optional<CtPopOp> from(const ::mx::ir::Operation &that);
  static std::optional<CtPopOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::CtPopOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value in(void) const;
  ::mx::ir::Value res(void) const;
};
static_assert(sizeof(CtPopOp) == sizeof(Operation));

class MX_EXPORT DbgDeclareOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_DBG_DECLARE;
  }

  static std::optional<DbgDeclareOp> from(const ::mx::ir::Operation &that);
  static std::optional<DbgDeclareOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::DbgDeclareOp underlying_repr(void) const noexcept;

  // Imported methods:
  //::mlir::TypedValue<::mlir::LLVM::LLVMPointerType> addr(void) const;
  //::mlir::LLVM::DILocalVariableAttr var_info(void) const;
};
static_assert(sizeof(DbgDeclareOp) == sizeof(Operation));

class MX_EXPORT DbgLabelOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_DBG_LABEL;
  }

  static std::optional<DbgLabelOp> from(const ::mx::ir::Operation &that);
  static std::optional<DbgLabelOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::DbgLabelOp underlying_repr(void) const noexcept;

  // Imported methods:
  //::mlir::LLVM::DILabelAttr label(void) const;
};
static_assert(sizeof(DbgLabelOp) == sizeof(Operation));

class MX_EXPORT DbgValueOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_DBG_VALUE;
  }

  static std::optional<DbgValueOp> from(const ::mx::ir::Operation &that);
  static std::optional<DbgValueOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::DbgValueOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value value(void) const;
  //::mlir::LLVM::DILocalVariableAttr var_info(void) const;
};
static_assert(sizeof(DbgValueOp) == sizeof(Operation));

class MX_EXPORT DebugTrapOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_DEBUGTRAP;
  }

  static std::optional<DebugTrapOp> from(const ::mx::ir::Operation &that);
  static std::optional<DebugTrapOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::DebugTrap underlying_repr(void) const noexcept;

  // Imported methods:
};
static_assert(sizeof(DebugTrapOp) == sizeof(Operation));

class MX_EXPORT EhTypeidForOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_EH_TYPEID_FOR;
  }

  static std::optional<EhTypeidForOp> from(const ::mx::ir::Operation &that);
  static std::optional<EhTypeidForOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::EhTypeidForOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value type_info(void) const;
  ::mx::ir::Value res(void) const;
};
static_assert(sizeof(EhTypeidForOp) == sizeof(Operation));

class MX_EXPORT Exp2Op final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_EXP2;
  }

  static std::optional<Exp2Op> from(const ::mx::ir::Operation &that);
  static std::optional<Exp2Op> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::Exp2Op underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value in(void) const;
  ::mx::ir::Value res(void) const;
  //::mlir::LLVM::FastmathFlags fastmath_flags(void) const;
};
static_assert(sizeof(Exp2Op) == sizeof(Operation));

class MX_EXPORT ExpOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_EXP;
  }

  static std::optional<ExpOp> from(const ::mx::ir::Operation &that);
  static std::optional<ExpOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::ExpOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value in(void) const;
  ::mx::ir::Value res(void) const;
  //::mlir::LLVM::FastmathFlags fastmath_flags(void) const;
};
static_assert(sizeof(ExpOp) == sizeof(Operation));

class MX_EXPORT ExpectOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_EXPECT;
  }

  static std::optional<ExpectOp> from(const ::mx::ir::Operation &that);
  static std::optional<ExpectOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::ExpectOp underlying_repr(void) const noexcept;

  // Imported methods:
  //::mlir::TypedValue<::mlir::IntegerType> val(void) const;
  //::mlir::TypedValue<::mlir::IntegerType> expected(void) const;
  ::mx::ir::Value res(void) const;
};
static_assert(sizeof(ExpectOp) == sizeof(Operation));

class MX_EXPORT ExpectWithProbabilityOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_EXPECT_WITH_PROBABILITY;
  }

  static std::optional<ExpectWithProbabilityOp> from(const ::mx::ir::Operation &that);
  static std::optional<ExpectWithProbabilityOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::ExpectWithProbabilityOp underlying_repr(void) const noexcept;

  // Imported methods:
  //::mlir::TypedValue<::mlir::IntegerType> val(void) const;
  //::mlir::TypedValue<::mlir::IntegerType> expected(void) const;
  ::mx::ir::Value res(void) const;
  //::llvm::APFloat prob(void) const;
};
static_assert(sizeof(ExpectWithProbabilityOp) == sizeof(Operation));

class MX_EXPORT FAbsOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_FABS;
  }

  static std::optional<FAbsOp> from(const ::mx::ir::Operation &that);
  static std::optional<FAbsOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::FAbsOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value in(void) const;
  ::mx::ir::Value res(void) const;
  //::mlir::LLVM::FastmathFlags fastmath_flags(void) const;
};
static_assert(sizeof(FAbsOp) == sizeof(Operation));

class MX_EXPORT FCeilOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_CEIL;
  }

  static std::optional<FCeilOp> from(const ::mx::ir::Operation &that);
  static std::optional<FCeilOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::FCeilOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value in(void) const;
  ::mx::ir::Value res(void) const;
  //::mlir::LLVM::FastmathFlags fastmath_flags(void) const;
};
static_assert(sizeof(FCeilOp) == sizeof(Operation));

class MX_EXPORT FFloorOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_FLOOR;
  }

  static std::optional<FFloorOp> from(const ::mx::ir::Operation &that);
  static std::optional<FFloorOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::FFloorOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value in(void) const;
  ::mx::ir::Value res(void) const;
  //::mlir::LLVM::FastmathFlags fastmath_flags(void) const;
};
static_assert(sizeof(FFloorOp) == sizeof(Operation));

class MX_EXPORT FMAOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_FMA;
  }

  static std::optional<FMAOp> from(const ::mx::ir::Operation &that);
  static std::optional<FMAOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::FMAOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value a(void) const;
  ::mx::ir::Value b(void) const;
  ::mx::ir::Value c(void) const;
  ::mx::ir::Value res(void) const;
  //::mlir::LLVM::FastmathFlags fastmath_flags(void) const;
};
static_assert(sizeof(FMAOp) == sizeof(Operation));

class MX_EXPORT FMulAddOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_FMULADD;
  }

  static std::optional<FMulAddOp> from(const ::mx::ir::Operation &that);
  static std::optional<FMulAddOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::FMulAddOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value a(void) const;
  ::mx::ir::Value b(void) const;
  ::mx::ir::Value c(void) const;
  ::mx::ir::Value res(void) const;
  //::mlir::LLVM::FastmathFlags fastmath_flags(void) const;
};
static_assert(sizeof(FMulAddOp) == sizeof(Operation));

class MX_EXPORT FTruncOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_TRUNC;
  }

  static std::optional<FTruncOp> from(const ::mx::ir::Operation &that);
  static std::optional<FTruncOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::FTruncOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value in(void) const;
  ::mx::ir::Value res(void) const;
  //::mlir::LLVM::FastmathFlags fastmath_flags(void) const;
};
static_assert(sizeof(FTruncOp) == sizeof(Operation));

class MX_EXPORT FShlOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_FSHL;
  }

  static std::optional<FShlOp> from(const ::mx::ir::Operation &that);
  static std::optional<FShlOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::FshlOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value a(void) const;
  ::mx::ir::Value b(void) const;
  ::mx::ir::Value c(void) const;
  ::mx::ir::Value res(void) const;
};
static_assert(sizeof(FShlOp) == sizeof(Operation));

class MX_EXPORT FShrOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_FSHR;
  }

  static std::optional<FShrOp> from(const ::mx::ir::Operation &that);
  static std::optional<FShrOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::FshrOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value a(void) const;
  ::mx::ir::Value b(void) const;
  ::mx::ir::Value c(void) const;
  ::mx::ir::Value res(void) const;
};
static_assert(sizeof(FShrOp) == sizeof(Operation));

class MX_EXPORT GetActiveLaneMaskOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_GET_ACTIVE_LANE_MASK;
  }

  static std::optional<GetActiveLaneMaskOp> from(const ::mx::ir::Operation &that);
  static std::optional<GetActiveLaneMaskOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::GetActiveLaneMaskOp underlying_repr(void) const noexcept;

  // Imported methods:
  //::mlir::TypedValue<::mlir::IntegerType> base(void) const;
  //::mlir::TypedValue<::mlir::IntegerType> n(void) const;
  ::mx::ir::Value res(void) const;
};
static_assert(sizeof(GetActiveLaneMaskOp) == sizeof(Operation));

class MX_EXPORT IsConstantOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_IS_CONSTANT;
  }

  static std::optional<IsConstantOp> from(const ::mx::ir::Operation &that);
  static std::optional<IsConstantOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::IsConstantOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value val(void) const;
  //::mlir::TypedValue<::mlir::IntegerType> res(void) const;
};
static_assert(sizeof(IsConstantOp) == sizeof(Operation));

class MX_EXPORT IsFPClassOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_IS_FPCLASS;
  }

  static std::optional<IsFPClassOp> from(const ::mx::ir::Operation &that);
  static std::optional<IsFPClassOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::IsFPClass underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value in(void) const;
  ::mx::ir::Value res(void) const;
  uint32_t bit(void) const;
};
static_assert(sizeof(IsFPClassOp) == sizeof(Operation));

class MX_EXPORT LifetimeEndOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_LIFETIME_END;
  }

  static std::optional<LifetimeEndOp> from(const ::mx::ir::Operation &that);
  static std::optional<LifetimeEndOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::LifetimeEndOp underlying_repr(void) const noexcept;

  // Imported methods:
  //::mlir::TypedValue<::mlir::LLVM::LLVMPointerType> ptr(void) const;
  uint64_t size(void) const;
};
static_assert(sizeof(LifetimeEndOp) == sizeof(Operation));

class MX_EXPORT LifetimeStartOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_LIFETIME_START;
  }

  static std::optional<LifetimeStartOp> from(const ::mx::ir::Operation &that);
  static std::optional<LifetimeStartOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::LifetimeStartOp underlying_repr(void) const noexcept;

  // Imported methods:
  //::mlir::TypedValue<::mlir::LLVM::LLVMPointerType> ptr(void) const;
  uint64_t size(void) const;
};
static_assert(sizeof(LifetimeStartOp) == sizeof(Operation));

class MX_EXPORT RoundAndCastToLongLongOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_LLRINT;
  }

  static std::optional<RoundAndCastToLongLongOp> from(const ::mx::ir::Operation &that);
  static std::optional<RoundAndCastToLongLongOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::LlrintOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value val(void) const;
  ::mx::ir::Value res(void) const;
};
static_assert(sizeof(RoundAndCastToLongLongOp) == sizeof(Operation));

class MX_EXPORT RoundAndCastToNearestLongLongOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_LLROUND;
  }

  static std::optional<RoundAndCastToNearestLongLongOp> from(const ::mx::ir::Operation &that);
  static std::optional<RoundAndCastToNearestLongLongOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::LlroundOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value val(void) const;
  ::mx::ir::Value res(void) const;
};
static_assert(sizeof(RoundAndCastToNearestLongLongOp) == sizeof(Operation));

class MX_EXPORT Log10Op final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_LOG10;
  }

  static std::optional<Log10Op> from(const ::mx::ir::Operation &that);
  static std::optional<Log10Op> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::Log10Op underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value in(void) const;
  ::mx::ir::Value res(void) const;
  //::mlir::LLVM::FastmathFlags fastmath_flags(void) const;
};
static_assert(sizeof(Log10Op) == sizeof(Operation));

class MX_EXPORT Log2Op final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_LOG2;
  }

  static std::optional<Log2Op> from(const ::mx::ir::Operation &that);
  static std::optional<Log2Op> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::Log2Op underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value in(void) const;
  ::mx::ir::Value res(void) const;
  //::mlir::LLVM::FastmathFlags fastmath_flags(void) const;
};
static_assert(sizeof(Log2Op) == sizeof(Operation));

class MX_EXPORT LogOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_LOG;
  }

  static std::optional<LogOp> from(const ::mx::ir::Operation &that);
  static std::optional<LogOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::LogOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value in(void) const;
  ::mx::ir::Value res(void) const;
  //::mlir::LLVM::FastmathFlags fastmath_flags(void) const;
};
static_assert(sizeof(LogOp) == sizeof(Operation));

class MX_EXPORT RoundAndCastToLongOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_LRINT;
  }

  static std::optional<RoundAndCastToLongOp> from(const ::mx::ir::Operation &that);
  static std::optional<RoundAndCastToLongOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::LrintOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value val(void) const;
  ::mx::ir::Value res(void) const;
};
static_assert(sizeof(RoundAndCastToLongOp) == sizeof(Operation));

class MX_EXPORT RoundAndCastToNearestLongOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_LROUND;
  }

  static std::optional<RoundAndCastToNearestLongOp> from(const ::mx::ir::Operation &that);
  static std::optional<RoundAndCastToNearestLongOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::LroundOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value val(void) const;
  ::mx::ir::Value res(void) const;
};
static_assert(sizeof(RoundAndCastToNearestLongOp) == sizeof(Operation));

class MX_EXPORT MaskedLoadOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_MASKED_LOAD;
  }

  static std::optional<MaskedLoadOp> from(const ::mx::ir::Operation &that);
  static std::optional<MaskedLoadOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::MaskedLoadOp underlying_repr(void) const noexcept;

  // Imported methods:
  //::mlir::TypedValue<::mlir::LLVM::LLVMPointerType> data(void) const;
  ::mx::ir::Value mask(void) const;
  gap::generator<::mx::ir::Operand> pass_thru(void) const;
  ::mx::ir::Value res(void) const;
  uint32_t alignment(void) const;
};
static_assert(sizeof(MaskedLoadOp) == sizeof(Operation));

class MX_EXPORT MaskedStoreOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_MASKED_STORE;
  }

  static std::optional<MaskedStoreOp> from(const ::mx::ir::Operation &that);
  static std::optional<MaskedStoreOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::MaskedStoreOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value value(void) const;
  //::mlir::TypedValue<::mlir::LLVM::LLVMPointerType> data(void) const;
  ::mx::ir::Value mask(void) const;
  uint32_t alignment(void) const;
};
static_assert(sizeof(MaskedStoreOp) == sizeof(Operation));

class MX_EXPORT MatrixColumnMajorLoadOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_MATRIX_COLUMN_MAJOR_LOAD;
  }

  static std::optional<MatrixColumnMajorLoadOp> from(const ::mx::ir::Operation &that);
  static std::optional<MatrixColumnMajorLoadOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::MatrixColumnMajorLoadOp underlying_repr(void) const noexcept;

  // Imported methods:
  //::mlir::TypedValue<::mlir::LLVM::LLVMPointerType> data(void) const;
  //::mlir::TypedValue<::mlir::IntegerType> stride(void) const;
  ::mx::ir::Value res(void) const;
  bool is_volatile(void) const;
  uint32_t rows(void) const;
  uint32_t columns(void) const;
};
static_assert(sizeof(MatrixColumnMajorLoadOp) == sizeof(Operation));

class MX_EXPORT MatrixColumnMajorStoreOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_MATRIX_COLUMN_MAJOR_STORE;
  }

  static std::optional<MatrixColumnMajorStoreOp> from(const ::mx::ir::Operation &that);
  static std::optional<MatrixColumnMajorStoreOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::MatrixColumnMajorStoreOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value matrix(void) const;
  //::mlir::TypedValue<::mlir::LLVM::LLVMPointerType> data(void) const;
  //::mlir::TypedValue<::mlir::IntegerType> stride(void) const;
  bool is_volatile(void) const;
  uint32_t rows(void) const;
  uint32_t columns(void) const;
};
static_assert(sizeof(MatrixColumnMajorStoreOp) == sizeof(Operation));

class MX_EXPORT MatrixMultiplyOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_MATRIX_MULTIPLY;
  }

  static std::optional<MatrixMultiplyOp> from(const ::mx::ir::Operation &that);
  static std::optional<MatrixMultiplyOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::MatrixMultiplyOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value lhs(void) const;
  ::mx::ir::Value rhs(void) const;
  ::mx::ir::Value res(void) const;
  uint32_t lhs_rows(void) const;
  uint32_t lhs_columns(void) const;
  uint32_t rhs_columns(void) const;
};
static_assert(sizeof(MatrixMultiplyOp) == sizeof(Operation));

class MX_EXPORT MatrixTransposeOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_MATRIX_TRANSPOSE;
  }

  static std::optional<MatrixTransposeOp> from(const ::mx::ir::Operation &that);
  static std::optional<MatrixTransposeOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::MatrixTransposeOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value matrix(void) const;
  ::mx::ir::Value res(void) const;
  uint32_t rows(void) const;
  uint32_t columns(void) const;
};
static_assert(sizeof(MatrixTransposeOp) == sizeof(Operation));

class MX_EXPORT MaxNumOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_MAXNUM;
  }

  static std::optional<MaxNumOp> from(const ::mx::ir::Operation &that);
  static std::optional<MaxNumOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::MaxNumOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value a(void) const;
  ::mx::ir::Value b(void) const;
  ::mx::ir::Value res(void) const;
  //::mlir::LLVM::FastmathFlags fastmath_flags(void) const;
};
static_assert(sizeof(MaxNumOp) == sizeof(Operation));

class MX_EXPORT MaximumOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_MAXIMUM;
  }

  static std::optional<MaximumOp> from(const ::mx::ir::Operation &that);
  static std::optional<MaximumOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::MaximumOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value a(void) const;
  ::mx::ir::Value b(void) const;
  ::mx::ir::Value res(void) const;
  //::mlir::LLVM::FastmathFlags fastmath_flags(void) const;
};
static_assert(sizeof(MaximumOp) == sizeof(Operation));

class MX_EXPORT MemcpyInlineOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_MEMCPY_INLINE;
  }

  static std::optional<MemcpyInlineOp> from(const ::mx::ir::Operation &that);
  static std::optional<MemcpyInlineOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::MemcpyInlineOp underlying_repr(void) const noexcept;

  // Imported methods:
  //::mlir::TypedValue<::mlir::LLVM::LLVMPointerType> dst(void) const;
  //::mlir::TypedValue<::mlir::LLVM::LLVMPointerType> src(void) const;
  //::mlir::APInt len(void) const;
  bool is_volatile(void) const;
  //::std::optional<::mlir::ArrayAttr> access_groups(void) const;
  //::std::optional<::mlir::ArrayAttr> alias_scopes(void) const;
  //::std::optional<::mlir::ArrayAttr> noalias_scopes(void) const;
  //::std::optional<::mlir::ArrayAttr> tbaa(void) const;
  //::llvm::SmallVector<::mlir::Value> accessed_operands(void) const;
};
static_assert(sizeof(MemcpyInlineOp) == sizeof(Operation));

class MX_EXPORT MemcpyOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_MEMCPY;
  }

  static std::optional<MemcpyOp> from(const ::mx::ir::Operation &that);
  static std::optional<MemcpyOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::MemcpyOp underlying_repr(void) const noexcept;

  // Imported methods:
  //::mlir::TypedValue<::mlir::LLVM::LLVMPointerType> dst(void) const;
  //::mlir::TypedValue<::mlir::LLVM::LLVMPointerType> src(void) const;
  //::mlir::TypedValue<::mlir::IntegerType> len(void) const;
  bool is_volatile(void) const;
  //::std::optional<::mlir::ArrayAttr> access_groups(void) const;
  //::std::optional<::mlir::ArrayAttr> alias_scopes(void) const;
  //::std::optional<::mlir::ArrayAttr> noalias_scopes(void) const;
  //::std::optional<::mlir::ArrayAttr> tbaa(void) const;
  //::llvm::SmallVector<::mlir::Value> accessed_operands(void) const;
};
static_assert(sizeof(MemcpyOp) == sizeof(Operation));

class MX_EXPORT MemmoveOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_MEMMOVE;
  }

  static std::optional<MemmoveOp> from(const ::mx::ir::Operation &that);
  static std::optional<MemmoveOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::MemmoveOp underlying_repr(void) const noexcept;

  // Imported methods:
  //::mlir::TypedValue<::mlir::LLVM::LLVMPointerType> dst(void) const;
  //::mlir::TypedValue<::mlir::LLVM::LLVMPointerType> src(void) const;
  //::mlir::TypedValue<::mlir::IntegerType> len(void) const;
  bool is_volatile(void) const;
  //::std::optional<::mlir::ArrayAttr> access_groups(void) const;
  //::std::optional<::mlir::ArrayAttr> alias_scopes(void) const;
  //::std::optional<::mlir::ArrayAttr> noalias_scopes(void) const;
  //::std::optional<::mlir::ArrayAttr> tbaa(void) const;
  //::llvm::SmallVector<::mlir::Value> accessed_operands(void) const;
};
static_assert(sizeof(MemmoveOp) == sizeof(Operation));

class MX_EXPORT MemsetOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_MEMSET;
  }

  static std::optional<MemsetOp> from(const ::mx::ir::Operation &that);
  static std::optional<MemsetOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::MemsetOp underlying_repr(void) const noexcept;

  // Imported methods:
  //::mlir::TypedValue<::mlir::LLVM::LLVMPointerType> dst(void) const;
  //::mlir::TypedValue<::mlir::IntegerType> val(void) const;
  //::mlir::TypedValue<::mlir::IntegerType> len(void) const;
  bool is_volatile(void) const;
  //::std::optional<::mlir::ArrayAttr> access_groups(void) const;
  //::std::optional<::mlir::ArrayAttr> alias_scopes(void) const;
  //::std::optional<::mlir::ArrayAttr> noalias_scopes(void) const;
  //::std::optional<::mlir::ArrayAttr> tbaa(void) const;
  //::llvm::SmallVector<::mlir::Value> accessed_operands(void) const;
};
static_assert(sizeof(MemsetOp) == sizeof(Operation));

class MX_EXPORT MinNumOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_MINNUM;
  }

  static std::optional<MinNumOp> from(const ::mx::ir::Operation &that);
  static std::optional<MinNumOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::MinNumOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value a(void) const;
  ::mx::ir::Value b(void) const;
  ::mx::ir::Value res(void) const;
  //::mlir::LLVM::FastmathFlags fastmath_flags(void) const;
};
static_assert(sizeof(MinNumOp) == sizeof(Operation));

class MX_EXPORT MinimumOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_MINIMUM;
  }

  static std::optional<MinimumOp> from(const ::mx::ir::Operation &that);
  static std::optional<MinimumOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::MinimumOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value a(void) const;
  ::mx::ir::Value b(void) const;
  ::mx::ir::Value res(void) const;
  //::mlir::LLVM::FastmathFlags fastmath_flags(void) const;
};
static_assert(sizeof(MinimumOp) == sizeof(Operation));

class MX_EXPORT RoundToNearbyIntOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_NEARBYINT;
  }

  static std::optional<RoundToNearbyIntOp> from(const ::mx::ir::Operation &that);
  static std::optional<RoundToNearbyIntOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::NearbyintOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value in(void) const;
  ::mx::ir::Value res(void) const;
  //::mlir::LLVM::FastmathFlags fastmath_flags(void) const;
};
static_assert(sizeof(RoundToNearbyIntOp) == sizeof(Operation));

class MX_EXPORT NoAliasScopeDeclOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_EXPERIMENTAL_NOALIAS_SCOPE_DECL;
  }

  static std::optional<NoAliasScopeDeclOp> from(const ::mx::ir::Operation &that);
  static std::optional<NoAliasScopeDeclOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::NoAliasScopeDeclOp underlying_repr(void) const noexcept;

  // Imported methods:
  //::mlir::LLVM::AliasScopeAttr scope(void) const;
};
static_assert(sizeof(NoAliasScopeDeclOp) == sizeof(Operation));

class MX_EXPORT PowIOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_POWI;
  }

  static std::optional<PowIOp> from(const ::mx::ir::Operation &that);
  static std::optional<PowIOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::PowIOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value val(void) const;
  //::mlir::TypedValue<::mlir::IntegerType> power(void) const;
  ::mx::ir::Value res(void) const;
  //::mlir::LLVM::FastmathFlags fastmath_flags(void) const;
};
static_assert(sizeof(PowIOp) == sizeof(Operation));

class MX_EXPORT FPowOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_POW;
  }

  static std::optional<FPowOp> from(const ::mx::ir::Operation &that);
  static std::optional<FPowOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::PowOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value a(void) const;
  ::mx::ir::Value b(void) const;
  ::mx::ir::Value res(void) const;
  //::mlir::LLVM::FastmathFlags fastmath_flags(void) const;
};
static_assert(sizeof(FPowOp) == sizeof(Operation));

class MX_EXPORT PrefetchOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_PREFETCH;
  }

  static std::optional<PrefetchOp> from(const ::mx::ir::Operation &that);
  static std::optional<PrefetchOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::Prefetch underlying_repr(void) const noexcept;

  // Imported methods:
  //::mlir::TypedValue<::mlir::LLVM::LLVMPointerType> addr(void) const;
  uint32_t rw(void) const;
  uint32_t hint(void) const;
  uint32_t cache(void) const;
};
static_assert(sizeof(PrefetchOp) == sizeof(Operation));

class MX_EXPORT PtrAnnotationOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_PTR_ANNOTATION;
  }

  static std::optional<PtrAnnotationOp> from(const ::mx::ir::Operation &that);
  static std::optional<PtrAnnotationOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::PtrAnnotation underlying_repr(void) const noexcept;

  // Imported methods:
  //::mlir::TypedValue<::mlir::LLVM::LLVMPointerType> ptr(void) const;
  //::mlir::TypedValue<::mlir::LLVM::LLVMPointerType> annotation(void) const;
  //::mlir::TypedValue<::mlir::LLVM::LLVMPointerType> file_name(void) const;
  //::mlir::TypedValue<::mlir::IntegerType> line(void) const;
  //::mlir::TypedValue<::mlir::LLVM::LLVMPointerType> attr(void) const;
  //::mlir::TypedValue<::mlir::LLVM::LLVMPointerType> res(void) const;
};
static_assert(sizeof(PtrAnnotationOp) == sizeof(Operation));

class MX_EXPORT RoundToIntOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_RINT;
  }

  static std::optional<RoundToIntOp> from(const ::mx::ir::Operation &that);
  static std::optional<RoundToIntOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::RintOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value in(void) const;
  ::mx::ir::Value res(void) const;
  //::mlir::LLVM::FastmathFlags fastmath_flags(void) const;
};
static_assert(sizeof(RoundToIntOp) == sizeof(Operation));

class MX_EXPORT RoundToNearestEvenOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_ROUNDEVEN;
  }

  static std::optional<RoundToNearestEvenOp> from(const ::mx::ir::Operation &that);
  static std::optional<RoundToNearestEvenOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::RoundEvenOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value in(void) const;
  ::mx::ir::Value res(void) const;
  //::mlir::LLVM::FastmathFlags fastmath_flags(void) const;
};
static_assert(sizeof(RoundToNearestEvenOp) == sizeof(Operation));

class MX_EXPORT RoundToNearestOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_ROUND;
  }

  static std::optional<RoundToNearestOp> from(const ::mx::ir::Operation &that);
  static std::optional<RoundToNearestOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::RoundOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value in(void) const;
  ::mx::ir::Value res(void) const;
  //::mlir::LLVM::FastmathFlags fastmath_flags(void) const;
};
static_assert(sizeof(RoundToNearestOp) == sizeof(Operation));

class MX_EXPORT SAddSatOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_SADD_SAT;
  }

  static std::optional<SAddSatOp> from(const ::mx::ir::Operation &that);
  static std::optional<SAddSatOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::SAddSat underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value a(void) const;
  ::mx::ir::Value b(void) const;
  ::mx::ir::Value res(void) const;
};
static_assert(sizeof(SAddSatOp) == sizeof(Operation));

class MX_EXPORT SAddWithOverflowOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_SADD_WITH_OVERFLOW;
  }

  static std::optional<SAddWithOverflowOp> from(const ::mx::ir::Operation &that);
  static std::optional<SAddWithOverflowOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::SAddWithOverflowOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value res(void) const;
};
static_assert(sizeof(SAddWithOverflowOp) == sizeof(Operation));

class MX_EXPORT SMaxOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_SMAX;
  }

  static std::optional<SMaxOp> from(const ::mx::ir::Operation &that);
  static std::optional<SMaxOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::SMaxOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value a(void) const;
  ::mx::ir::Value b(void) const;
  ::mx::ir::Value res(void) const;
};
static_assert(sizeof(SMaxOp) == sizeof(Operation));

class MX_EXPORT SMinOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_SMIN;
  }

  static std::optional<SMinOp> from(const ::mx::ir::Operation &that);
  static std::optional<SMinOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::SMinOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value a(void) const;
  ::mx::ir::Value b(void) const;
  ::mx::ir::Value res(void) const;
};
static_assert(sizeof(SMinOp) == sizeof(Operation));

class MX_EXPORT SMulWithOverflowOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_SMUL_WITH_OVERFLOW;
  }

  static std::optional<SMulWithOverflowOp> from(const ::mx::ir::Operation &that);
  static std::optional<SMulWithOverflowOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::SMulWithOverflowOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value res(void) const;
};
static_assert(sizeof(SMulWithOverflowOp) == sizeof(Operation));

class MX_EXPORT SSACopyOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_SSA_COPY;
  }

  static std::optional<SSACopyOp> from(const ::mx::ir::Operation &that);
  static std::optional<SSACopyOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::SSACopyOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value operand(void) const;
  ::mx::ir::Value res(void) const;
};
static_assert(sizeof(SSACopyOp) == sizeof(Operation));

class MX_EXPORT SShlSatOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_SSHL_SAT;
  }

  static std::optional<SShlSatOp> from(const ::mx::ir::Operation &that);
  static std::optional<SShlSatOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::SSHLSat underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value a(void) const;
  ::mx::ir::Value b(void) const;
  ::mx::ir::Value res(void) const;
};
static_assert(sizeof(SShlSatOp) == sizeof(Operation));

class MX_EXPORT SSubSatOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_SSUB_SAT;
  }

  static std::optional<SSubSatOp> from(const ::mx::ir::Operation &that);
  static std::optional<SSubSatOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::SSubSat underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value a(void) const;
  ::mx::ir::Value b(void) const;
  ::mx::ir::Value res(void) const;
};
static_assert(sizeof(SSubSatOp) == sizeof(Operation));

class MX_EXPORT SSubWithOverflowOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_SSUB_WITH_OVERFLOW;
  }

  static std::optional<SSubWithOverflowOp> from(const ::mx::ir::Operation &that);
  static std::optional<SSubWithOverflowOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::SSubWithOverflowOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value res(void) const;
};
static_assert(sizeof(SSubWithOverflowOp) == sizeof(Operation));

class MX_EXPORT SinOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_SIN;
  }

  static std::optional<SinOp> from(const ::mx::ir::Operation &that);
  static std::optional<SinOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::SinOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value in(void) const;
  ::mx::ir::Value res(void) const;
  //::mlir::LLVM::FastmathFlags fastmath_flags(void) const;
};
static_assert(sizeof(SinOp) == sizeof(Operation));

class MX_EXPORT SqrtOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_SQRT;
  }

  static std::optional<SqrtOp> from(const ::mx::ir::Operation &that);
  static std::optional<SqrtOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::SqrtOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value in(void) const;
  ::mx::ir::Value res(void) const;
  //::mlir::LLVM::FastmathFlags fastmath_flags(void) const;
};
static_assert(sizeof(SqrtOp) == sizeof(Operation));

class MX_EXPORT StackRestoreOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_STACKRESTORE;
  }

  static std::optional<StackRestoreOp> from(const ::mx::ir::Operation &that);
  static std::optional<StackRestoreOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::StackRestoreOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value ptr(void) const;
};
static_assert(sizeof(StackRestoreOp) == sizeof(Operation));

class MX_EXPORT StackSaveOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_STACKSAVE;
  }

  static std::optional<StackSaveOp> from(const ::mx::ir::Operation &that);
  static std::optional<StackSaveOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::StackSaveOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value res(void) const;
};
static_assert(sizeof(StackSaveOp) == sizeof(Operation));

class MX_EXPORT StepVectorOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_EXPERIMENTAL_STEPVECTOR;
  }

  static std::optional<StepVectorOp> from(const ::mx::ir::Operation &that);
  static std::optional<StepVectorOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::StepVectorOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value res(void) const;
};
static_assert(sizeof(StepVectorOp) == sizeof(Operation));

class MX_EXPORT ThreadLocalAddressOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_THREADLOCAL_ADDRESS;
  }

  static std::optional<ThreadLocalAddressOp> from(const ::mx::ir::Operation &that);
  static std::optional<ThreadLocalAddressOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::ThreadlocalAddressOp underlying_repr(void) const noexcept;

  // Imported methods:
  //::mlir::TypedValue<::mlir::LLVM::LLVMPointerType> global(void) const;
  ::mx::ir::Value res(void) const;
};
static_assert(sizeof(ThreadLocalAddressOp) == sizeof(Operation));

class MX_EXPORT TrapOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_TRAP;
  }

  static std::optional<TrapOp> from(const ::mx::ir::Operation &that);
  static std::optional<TrapOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::Trap underlying_repr(void) const noexcept;

  // Imported methods:
};
static_assert(sizeof(TrapOp) == sizeof(Operation));

class MX_EXPORT UAddSatOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_UADD_SAT;
  }

  static std::optional<UAddSatOp> from(const ::mx::ir::Operation &that);
  static std::optional<UAddSatOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::UAddSat underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value a(void) const;
  ::mx::ir::Value b(void) const;
  ::mx::ir::Value res(void) const;
};
static_assert(sizeof(UAddSatOp) == sizeof(Operation));

class MX_EXPORT UAddWithOverflowOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_UADD_WITH_OVERFLOW;
  }

  static std::optional<UAddWithOverflowOp> from(const ::mx::ir::Operation &that);
  static std::optional<UAddWithOverflowOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::UAddWithOverflowOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value res(void) const;
};
static_assert(sizeof(UAddWithOverflowOp) == sizeof(Operation));

class MX_EXPORT UBSanTrapOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_UBSANTRAP;
  }

  static std::optional<UBSanTrapOp> from(const ::mx::ir::Operation &that);
  static std::optional<UBSanTrapOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::UBSanTrap underlying_repr(void) const noexcept;

  // Imported methods:
  uint8_t failure_kind(void) const;
};
static_assert(sizeof(UBSanTrapOp) == sizeof(Operation));

class MX_EXPORT UMaxOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_UMAX;
  }

  static std::optional<UMaxOp> from(const ::mx::ir::Operation &that);
  static std::optional<UMaxOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::UMaxOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value a(void) const;
  ::mx::ir::Value b(void) const;
  ::mx::ir::Value res(void) const;
};
static_assert(sizeof(UMaxOp) == sizeof(Operation));

class MX_EXPORT UMinOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_UMIN;
  }

  static std::optional<UMinOp> from(const ::mx::ir::Operation &that);
  static std::optional<UMinOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::UMinOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value a(void) const;
  ::mx::ir::Value b(void) const;
  ::mx::ir::Value res(void) const;
};
static_assert(sizeof(UMinOp) == sizeof(Operation));

class MX_EXPORT UMulWithOverflowOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_UMUL_WITH_OVERFLOW;
  }

  static std::optional<UMulWithOverflowOp> from(const ::mx::ir::Operation &that);
  static std::optional<UMulWithOverflowOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::UMulWithOverflowOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value res(void) const;
};
static_assert(sizeof(UMulWithOverflowOp) == sizeof(Operation));

class MX_EXPORT UShlSatOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_USHL_SAT;
  }

  static std::optional<UShlSatOp> from(const ::mx::ir::Operation &that);
  static std::optional<UShlSatOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::USHLSat underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value a(void) const;
  ::mx::ir::Value b(void) const;
  ::mx::ir::Value res(void) const;
};
static_assert(sizeof(UShlSatOp) == sizeof(Operation));

class MX_EXPORT USubSatOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_USUB_SAT;
  }

  static std::optional<USubSatOp> from(const ::mx::ir::Operation &that);
  static std::optional<USubSatOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::USubSat underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value a(void) const;
  ::mx::ir::Value b(void) const;
  ::mx::ir::Value res(void) const;
};
static_assert(sizeof(USubSatOp) == sizeof(Operation));

class MX_EXPORT USubWithOverflowOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_USUB_WITH_OVERFLOW;
  }

  static std::optional<USubWithOverflowOp> from(const ::mx::ir::Operation &that);
  static std::optional<USubWithOverflowOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::USubWithOverflowOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value res(void) const;
};
static_assert(sizeof(USubWithOverflowOp) == sizeof(Operation));

class MX_EXPORT VPAShrOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_VP_ASHR;
  }

  static std::optional<VPAShrOp> from(const ::mx::ir::Operation &that);
  static std::optional<VPAShrOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::VPAShrOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value lhs(void) const;
  ::mx::ir::Value rhs(void) const;
  ::mx::ir::Value mask(void) const;
  //::mlir::TypedValue<::mlir::IntegerType> evl(void) const;
  ::mx::ir::Value res(void) const;
};
static_assert(sizeof(VPAShrOp) == sizeof(Operation));

class MX_EXPORT VPAddOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_VP_ADD;
  }

  static std::optional<VPAddOp> from(const ::mx::ir::Operation &that);
  static std::optional<VPAddOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::VPAddOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value lhs(void) const;
  ::mx::ir::Value rhs(void) const;
  ::mx::ir::Value mask(void) const;
  //::mlir::TypedValue<::mlir::IntegerType> evl(void) const;
  ::mx::ir::Value res(void) const;
};
static_assert(sizeof(VPAddOp) == sizeof(Operation));

class MX_EXPORT VPAndOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_VP_AND;
  }

  static std::optional<VPAndOp> from(const ::mx::ir::Operation &that);
  static std::optional<VPAndOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::VPAndOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value lhs(void) const;
  ::mx::ir::Value rhs(void) const;
  ::mx::ir::Value mask(void) const;
  //::mlir::TypedValue<::mlir::IntegerType> evl(void) const;
  ::mx::ir::Value res(void) const;
};
static_assert(sizeof(VPAndOp) == sizeof(Operation));

class MX_EXPORT VPFAddOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_VP_FADD;
  }

  static std::optional<VPFAddOp> from(const ::mx::ir::Operation &that);
  static std::optional<VPFAddOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::VPFAddOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value lhs(void) const;
  ::mx::ir::Value rhs(void) const;
  ::mx::ir::Value mask(void) const;
  //::mlir::TypedValue<::mlir::IntegerType> evl(void) const;
  ::mx::ir::Value res(void) const;
};
static_assert(sizeof(VPFAddOp) == sizeof(Operation));

class MX_EXPORT VPFDivOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_VP_FDIV;
  }

  static std::optional<VPFDivOp> from(const ::mx::ir::Operation &that);
  static std::optional<VPFDivOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::VPFDivOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value lhs(void) const;
  ::mx::ir::Value rhs(void) const;
  ::mx::ir::Value mask(void) const;
  //::mlir::TypedValue<::mlir::IntegerType> evl(void) const;
  ::mx::ir::Value res(void) const;
};
static_assert(sizeof(VPFDivOp) == sizeof(Operation));

class MX_EXPORT VPFMulAddOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_VP_FMULADD;
  }

  static std::optional<VPFMulAddOp> from(const ::mx::ir::Operation &that);
  static std::optional<VPFMulAddOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::VPFMulAddOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value op1(void) const;
  ::mx::ir::Value op2(void) const;
  ::mx::ir::Value op3(void) const;
  ::mx::ir::Value mask(void) const;
  //::mlir::TypedValue<::mlir::IntegerType> evl(void) const;
  ::mx::ir::Value res(void) const;
};
static_assert(sizeof(VPFMulAddOp) == sizeof(Operation));

class MX_EXPORT VPFMulOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_VP_FMUL;
  }

  static std::optional<VPFMulOp> from(const ::mx::ir::Operation &that);
  static std::optional<VPFMulOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::VPFMulOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value lhs(void) const;
  ::mx::ir::Value rhs(void) const;
  ::mx::ir::Value mask(void) const;
  //::mlir::TypedValue<::mlir::IntegerType> evl(void) const;
  ::mx::ir::Value res(void) const;
};
static_assert(sizeof(VPFMulOp) == sizeof(Operation));

class MX_EXPORT VPFNegOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_VP_FNEG;
  }

  static std::optional<VPFNegOp> from(const ::mx::ir::Operation &that);
  static std::optional<VPFNegOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::VPFNegOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value op(void) const;
  ::mx::ir::Value mask(void) const;
  //::mlir::TypedValue<::mlir::IntegerType> evl(void) const;
  ::mx::ir::Value res(void) const;
};
static_assert(sizeof(VPFNegOp) == sizeof(Operation));

class MX_EXPORT VPFPExtOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_VP_FPEXT;
  }

  static std::optional<VPFPExtOp> from(const ::mx::ir::Operation &that);
  static std::optional<VPFPExtOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::VPFPExtOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value src(void) const;
  ::mx::ir::Value mask(void) const;
  //::mlir::TypedValue<::mlir::IntegerType> evl(void) const;
  ::mx::ir::Value res(void) const;
};
static_assert(sizeof(VPFPExtOp) == sizeof(Operation));

class MX_EXPORT VPFPToSIOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_VP_FPTOSI;
  }

  static std::optional<VPFPToSIOp> from(const ::mx::ir::Operation &that);
  static std::optional<VPFPToSIOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::VPFPToSIOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value src(void) const;
  ::mx::ir::Value mask(void) const;
  //::mlir::TypedValue<::mlir::IntegerType> evl(void) const;
  ::mx::ir::Value res(void) const;
};
static_assert(sizeof(VPFPToSIOp) == sizeof(Operation));

class MX_EXPORT VPFPToUIOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_VP_FPTOUI;
  }

  static std::optional<VPFPToUIOp> from(const ::mx::ir::Operation &that);
  static std::optional<VPFPToUIOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::VPFPToUIOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value src(void) const;
  ::mx::ir::Value mask(void) const;
  //::mlir::TypedValue<::mlir::IntegerType> evl(void) const;
  ::mx::ir::Value res(void) const;
};
static_assert(sizeof(VPFPToUIOp) == sizeof(Operation));

class MX_EXPORT VPFPTruncOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_VP_FPTRUNC;
  }

  static std::optional<VPFPTruncOp> from(const ::mx::ir::Operation &that);
  static std::optional<VPFPTruncOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::VPFPTruncOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value src(void) const;
  ::mx::ir::Value mask(void) const;
  //::mlir::TypedValue<::mlir::IntegerType> evl(void) const;
  ::mx::ir::Value res(void) const;
};
static_assert(sizeof(VPFPTruncOp) == sizeof(Operation));

class MX_EXPORT VPFRemOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_VP_FREM;
  }

  static std::optional<VPFRemOp> from(const ::mx::ir::Operation &that);
  static std::optional<VPFRemOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::VPFRemOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value lhs(void) const;
  ::mx::ir::Value rhs(void) const;
  ::mx::ir::Value mask(void) const;
  //::mlir::TypedValue<::mlir::IntegerType> evl(void) const;
  ::mx::ir::Value res(void) const;
};
static_assert(sizeof(VPFRemOp) == sizeof(Operation));

class MX_EXPORT VPFSubOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_VP_FSUB;
  }

  static std::optional<VPFSubOp> from(const ::mx::ir::Operation &that);
  static std::optional<VPFSubOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::VPFSubOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value lhs(void) const;
  ::mx::ir::Value rhs(void) const;
  ::mx::ir::Value mask(void) const;
  //::mlir::TypedValue<::mlir::IntegerType> evl(void) const;
  ::mx::ir::Value res(void) const;
};
static_assert(sizeof(VPFSubOp) == sizeof(Operation));

class MX_EXPORT VPFmaOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_VP_FMA;
  }

  static std::optional<VPFmaOp> from(const ::mx::ir::Operation &that);
  static std::optional<VPFmaOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::VPFmaOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value op1(void) const;
  ::mx::ir::Value op2(void) const;
  ::mx::ir::Value op3(void) const;
  ::mx::ir::Value mask(void) const;
  //::mlir::TypedValue<::mlir::IntegerType> evl(void) const;
  ::mx::ir::Value res(void) const;
};
static_assert(sizeof(VPFmaOp) == sizeof(Operation));

class MX_EXPORT VPIntToPtrOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_VP_INTTOPTR;
  }

  static std::optional<VPIntToPtrOp> from(const ::mx::ir::Operation &that);
  static std::optional<VPIntToPtrOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::VPIntToPtrOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value src(void) const;
  ::mx::ir::Value mask(void) const;
  //::mlir::TypedValue<::mlir::IntegerType> evl(void) const;
  ::mx::ir::Value res(void) const;
};
static_assert(sizeof(VPIntToPtrOp) == sizeof(Operation));

class MX_EXPORT VPLShrOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_VP_LSHR;
  }

  static std::optional<VPLShrOp> from(const ::mx::ir::Operation &that);
  static std::optional<VPLShrOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::VPLShrOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value lhs(void) const;
  ::mx::ir::Value rhs(void) const;
  ::mx::ir::Value mask(void) const;
  //::mlir::TypedValue<::mlir::IntegerType> evl(void) const;
  ::mx::ir::Value res(void) const;
};
static_assert(sizeof(VPLShrOp) == sizeof(Operation));

class MX_EXPORT VPLoadOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_VP_LOAD;
  }

  static std::optional<VPLoadOp> from(const ::mx::ir::Operation &that);
  static std::optional<VPLoadOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::VPLoadOp underlying_repr(void) const noexcept;

  // Imported methods:
  //::mlir::TypedValue<::mlir::LLVM::LLVMPointerType> ptr(void) const;
  ::mx::ir::Value mask(void) const;
  //::mlir::TypedValue<::mlir::IntegerType> evl(void) const;
  ::mx::ir::Value res(void) const;
};
static_assert(sizeof(VPLoadOp) == sizeof(Operation));

class MX_EXPORT VPMergeMinOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_VP_MERGE;
  }

  static std::optional<VPMergeMinOp> from(const ::mx::ir::Operation &that);
  static std::optional<VPMergeMinOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::VPMergeMinOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value cond(void) const;
  ::mx::ir::Value true_val(void) const;
  ::mx::ir::Value false_val(void) const;
  //::mlir::TypedValue<::mlir::IntegerType> evl(void) const;
  ::mx::ir::Value res(void) const;
};
static_assert(sizeof(VPMergeMinOp) == sizeof(Operation));

class MX_EXPORT VPMulOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_VP_MUL;
  }

  static std::optional<VPMulOp> from(const ::mx::ir::Operation &that);
  static std::optional<VPMulOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::VPMulOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value lhs(void) const;
  ::mx::ir::Value rhs(void) const;
  ::mx::ir::Value mask(void) const;
  //::mlir::TypedValue<::mlir::IntegerType> evl(void) const;
  ::mx::ir::Value res(void) const;
};
static_assert(sizeof(VPMulOp) == sizeof(Operation));

class MX_EXPORT VPOrOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_VP_OR;
  }

  static std::optional<VPOrOp> from(const ::mx::ir::Operation &that);
  static std::optional<VPOrOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::VPOrOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value lhs(void) const;
  ::mx::ir::Value rhs(void) const;
  ::mx::ir::Value mask(void) const;
  //::mlir::TypedValue<::mlir::IntegerType> evl(void) const;
  ::mx::ir::Value res(void) const;
};
static_assert(sizeof(VPOrOp) == sizeof(Operation));

class MX_EXPORT VPPtrToIntOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_VP_PTRTOINT;
  }

  static std::optional<VPPtrToIntOp> from(const ::mx::ir::Operation &that);
  static std::optional<VPPtrToIntOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::VPPtrToIntOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value src(void) const;
  ::mx::ir::Value mask(void) const;
  //::mlir::TypedValue<::mlir::IntegerType> evl(void) const;
  ::mx::ir::Value res(void) const;
};
static_assert(sizeof(VPPtrToIntOp) == sizeof(Operation));

class MX_EXPORT VPReduceAddOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_VP_REDUCE_ADD;
  }

  static std::optional<VPReduceAddOp> from(const ::mx::ir::Operation &that);
  static std::optional<VPReduceAddOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::VPReduceAddOp underlying_repr(void) const noexcept;

  // Imported methods:
  //::mlir::TypedValue<::mlir::IntegerType> satrt_value(void) const;
  ::mx::ir::Value val(void) const;
  ::mx::ir::Value mask(void) const;
  //::mlir::TypedValue<::mlir::IntegerType> evl(void) const;
  ::mx::ir::Value res(void) const;
};
static_assert(sizeof(VPReduceAddOp) == sizeof(Operation));

class MX_EXPORT VPReduceAndOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_VP_REDUCE_AND;
  }

  static std::optional<VPReduceAndOp> from(const ::mx::ir::Operation &that);
  static std::optional<VPReduceAndOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::VPReduceAndOp underlying_repr(void) const noexcept;

  // Imported methods:
  //::mlir::TypedValue<::mlir::IntegerType> satrt_value(void) const;
  ::mx::ir::Value val(void) const;
  ::mx::ir::Value mask(void) const;
  //::mlir::TypedValue<::mlir::IntegerType> evl(void) const;
  ::mx::ir::Value res(void) const;
};
static_assert(sizeof(VPReduceAndOp) == sizeof(Operation));

class MX_EXPORT VPReduceFAddOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_VP_REDUCE_FADD;
  }

  static std::optional<VPReduceFAddOp> from(const ::mx::ir::Operation &that);
  static std::optional<VPReduceFAddOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::VPReduceFAddOp underlying_repr(void) const noexcept;

  // Imported methods:
  //::mlir::TypedValue<::mlir::FloatType> satrt_value(void) const;
  ::mx::ir::Value val(void) const;
  ::mx::ir::Value mask(void) const;
  //::mlir::TypedValue<::mlir::IntegerType> evl(void) const;
  ::mx::ir::Value res(void) const;
};
static_assert(sizeof(VPReduceFAddOp) == sizeof(Operation));

class MX_EXPORT VPReduceFMaxOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_VP_REDUCE_FMAX;
  }

  static std::optional<VPReduceFMaxOp> from(const ::mx::ir::Operation &that);
  static std::optional<VPReduceFMaxOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::VPReduceFMaxOp underlying_repr(void) const noexcept;

  // Imported methods:
  //::mlir::TypedValue<::mlir::FloatType> satrt_value(void) const;
  ::mx::ir::Value val(void) const;
  ::mx::ir::Value mask(void) const;
  //::mlir::TypedValue<::mlir::IntegerType> evl(void) const;
  ::mx::ir::Value res(void) const;
};
static_assert(sizeof(VPReduceFMaxOp) == sizeof(Operation));

class MX_EXPORT VPReduceFMinOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_VP_REDUCE_FMIN;
  }

  static std::optional<VPReduceFMinOp> from(const ::mx::ir::Operation &that);
  static std::optional<VPReduceFMinOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::VPReduceFMinOp underlying_repr(void) const noexcept;

  // Imported methods:
  //::mlir::TypedValue<::mlir::FloatType> satrt_value(void) const;
  ::mx::ir::Value val(void) const;
  ::mx::ir::Value mask(void) const;
  //::mlir::TypedValue<::mlir::IntegerType> evl(void) const;
  ::mx::ir::Value res(void) const;
};
static_assert(sizeof(VPReduceFMinOp) == sizeof(Operation));

class MX_EXPORT VPReduceFMulOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_VP_REDUCE_FMUL;
  }

  static std::optional<VPReduceFMulOp> from(const ::mx::ir::Operation &that);
  static std::optional<VPReduceFMulOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::VPReduceFMulOp underlying_repr(void) const noexcept;

  // Imported methods:
  //::mlir::TypedValue<::mlir::FloatType> satrt_value(void) const;
  ::mx::ir::Value val(void) const;
  ::mx::ir::Value mask(void) const;
  //::mlir::TypedValue<::mlir::IntegerType> evl(void) const;
  ::mx::ir::Value res(void) const;
};
static_assert(sizeof(VPReduceFMulOp) == sizeof(Operation));

class MX_EXPORT VPReduceMulOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_VP_REDUCE_MUL;
  }

  static std::optional<VPReduceMulOp> from(const ::mx::ir::Operation &that);
  static std::optional<VPReduceMulOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::VPReduceMulOp underlying_repr(void) const noexcept;

  // Imported methods:
  //::mlir::TypedValue<::mlir::IntegerType> satrt_value(void) const;
  ::mx::ir::Value val(void) const;
  ::mx::ir::Value mask(void) const;
  //::mlir::TypedValue<::mlir::IntegerType> evl(void) const;
  ::mx::ir::Value res(void) const;
};
static_assert(sizeof(VPReduceMulOp) == sizeof(Operation));

class MX_EXPORT VPReduceOrOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_VP_REDUCE_OR;
  }

  static std::optional<VPReduceOrOp> from(const ::mx::ir::Operation &that);
  static std::optional<VPReduceOrOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::VPReduceOrOp underlying_repr(void) const noexcept;

  // Imported methods:
  //::mlir::TypedValue<::mlir::IntegerType> satrt_value(void) const;
  ::mx::ir::Value val(void) const;
  ::mx::ir::Value mask(void) const;
  //::mlir::TypedValue<::mlir::IntegerType> evl(void) const;
  ::mx::ir::Value res(void) const;
};
static_assert(sizeof(VPReduceOrOp) == sizeof(Operation));

class MX_EXPORT VPReduceSMaxOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_VP_REDUCE_SMAX;
  }

  static std::optional<VPReduceSMaxOp> from(const ::mx::ir::Operation &that);
  static std::optional<VPReduceSMaxOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::VPReduceSMaxOp underlying_repr(void) const noexcept;

  // Imported methods:
  //::mlir::TypedValue<::mlir::IntegerType> satrt_value(void) const;
  ::mx::ir::Value val(void) const;
  ::mx::ir::Value mask(void) const;
  //::mlir::TypedValue<::mlir::IntegerType> evl(void) const;
  ::mx::ir::Value res(void) const;
};
static_assert(sizeof(VPReduceSMaxOp) == sizeof(Operation));

class MX_EXPORT VPReduceSMinOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_VP_REDUCE_SMIN;
  }

  static std::optional<VPReduceSMinOp> from(const ::mx::ir::Operation &that);
  static std::optional<VPReduceSMinOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::VPReduceSMinOp underlying_repr(void) const noexcept;

  // Imported methods:
  //::mlir::TypedValue<::mlir::IntegerType> satrt_value(void) const;
  ::mx::ir::Value val(void) const;
  ::mx::ir::Value mask(void) const;
  //::mlir::TypedValue<::mlir::IntegerType> evl(void) const;
  ::mx::ir::Value res(void) const;
};
static_assert(sizeof(VPReduceSMinOp) == sizeof(Operation));

class MX_EXPORT VPReduceUMaxOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_VP_REDUCE_UMAX;
  }

  static std::optional<VPReduceUMaxOp> from(const ::mx::ir::Operation &that);
  static std::optional<VPReduceUMaxOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::VPReduceUMaxOp underlying_repr(void) const noexcept;

  // Imported methods:
  //::mlir::TypedValue<::mlir::IntegerType> satrt_value(void) const;
  ::mx::ir::Value val(void) const;
  ::mx::ir::Value mask(void) const;
  //::mlir::TypedValue<::mlir::IntegerType> evl(void) const;
  ::mx::ir::Value res(void) const;
};
static_assert(sizeof(VPReduceUMaxOp) == sizeof(Operation));

class MX_EXPORT VPReduceUMinOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_VP_REDUCE_UMIN;
  }

  static std::optional<VPReduceUMinOp> from(const ::mx::ir::Operation &that);
  static std::optional<VPReduceUMinOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::VPReduceUMinOp underlying_repr(void) const noexcept;

  // Imported methods:
  //::mlir::TypedValue<::mlir::IntegerType> satrt_value(void) const;
  ::mx::ir::Value val(void) const;
  ::mx::ir::Value mask(void) const;
  //::mlir::TypedValue<::mlir::IntegerType> evl(void) const;
  ::mx::ir::Value res(void) const;
};
static_assert(sizeof(VPReduceUMinOp) == sizeof(Operation));

class MX_EXPORT VPReduceXorOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_VP_REDUCE_XOR;
  }

  static std::optional<VPReduceXorOp> from(const ::mx::ir::Operation &that);
  static std::optional<VPReduceXorOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::VPReduceXorOp underlying_repr(void) const noexcept;

  // Imported methods:
  //::mlir::TypedValue<::mlir::IntegerType> satrt_value(void) const;
  ::mx::ir::Value val(void) const;
  ::mx::ir::Value mask(void) const;
  //::mlir::TypedValue<::mlir::IntegerType> evl(void) const;
  ::mx::ir::Value res(void) const;
};
static_assert(sizeof(VPReduceXorOp) == sizeof(Operation));

class MX_EXPORT VPSDivOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_VP_SDIV;
  }

  static std::optional<VPSDivOp> from(const ::mx::ir::Operation &that);
  static std::optional<VPSDivOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::VPSDivOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value lhs(void) const;
  ::mx::ir::Value rhs(void) const;
  ::mx::ir::Value mask(void) const;
  //::mlir::TypedValue<::mlir::IntegerType> evl(void) const;
  ::mx::ir::Value res(void) const;
};
static_assert(sizeof(VPSDivOp) == sizeof(Operation));

class MX_EXPORT VPSExtOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_VP_SEXT;
  }

  static std::optional<VPSExtOp> from(const ::mx::ir::Operation &that);
  static std::optional<VPSExtOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::VPSExtOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value src(void) const;
  ::mx::ir::Value mask(void) const;
  //::mlir::TypedValue<::mlir::IntegerType> evl(void) const;
  ::mx::ir::Value res(void) const;
};
static_assert(sizeof(VPSExtOp) == sizeof(Operation));

class MX_EXPORT VPSIToFPOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_VP_SITOFP;
  }

  static std::optional<VPSIToFPOp> from(const ::mx::ir::Operation &that);
  static std::optional<VPSIToFPOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::VPSIToFPOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value src(void) const;
  ::mx::ir::Value mask(void) const;
  //::mlir::TypedValue<::mlir::IntegerType> evl(void) const;
  ::mx::ir::Value res(void) const;
};
static_assert(sizeof(VPSIToFPOp) == sizeof(Operation));

class MX_EXPORT VPSRemOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_VP_SREM;
  }

  static std::optional<VPSRemOp> from(const ::mx::ir::Operation &that);
  static std::optional<VPSRemOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::VPSRemOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value lhs(void) const;
  ::mx::ir::Value rhs(void) const;
  ::mx::ir::Value mask(void) const;
  //::mlir::TypedValue<::mlir::IntegerType> evl(void) const;
  ::mx::ir::Value res(void) const;
};
static_assert(sizeof(VPSRemOp) == sizeof(Operation));

class MX_EXPORT VPSelectMinOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_VP_SELECT;
  }

  static std::optional<VPSelectMinOp> from(const ::mx::ir::Operation &that);
  static std::optional<VPSelectMinOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::VPSelectMinOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value cond(void) const;
  ::mx::ir::Value true_val(void) const;
  ::mx::ir::Value false_val(void) const;
  //::mlir::TypedValue<::mlir::IntegerType> evl(void) const;
  ::mx::ir::Value res(void) const;
};
static_assert(sizeof(VPSelectMinOp) == sizeof(Operation));

class MX_EXPORT VPShlOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_VP_SHL;
  }

  static std::optional<VPShlOp> from(const ::mx::ir::Operation &that);
  static std::optional<VPShlOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::VPShlOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value lhs(void) const;
  ::mx::ir::Value rhs(void) const;
  ::mx::ir::Value mask(void) const;
  //::mlir::TypedValue<::mlir::IntegerType> evl(void) const;
  ::mx::ir::Value res(void) const;
};
static_assert(sizeof(VPShlOp) == sizeof(Operation));

class MX_EXPORT VPStoreOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_VP_STORE;
  }

  static std::optional<VPStoreOp> from(const ::mx::ir::Operation &that);
  static std::optional<VPStoreOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::VPStoreOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value val(void) const;
  //::mlir::TypedValue<::mlir::LLVM::LLVMPointerType> ptr(void) const;
  ::mx::ir::Value mask(void) const;
  //::mlir::TypedValue<::mlir::IntegerType> evl(void) const;
};
static_assert(sizeof(VPStoreOp) == sizeof(Operation));

class MX_EXPORT VPStridedLoadOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_EXPERIMENTAL_VP_STRIDED_LOAD;
  }

  static std::optional<VPStridedLoadOp> from(const ::mx::ir::Operation &that);
  static std::optional<VPStridedLoadOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::VPStridedLoadOp underlying_repr(void) const noexcept;

  // Imported methods:
  //::mlir::TypedValue<::mlir::LLVM::LLVMPointerType> ptr(void) const;
  //::mlir::TypedValue<::mlir::IntegerType> stride(void) const;
  ::mx::ir::Value mask(void) const;
  //::mlir::TypedValue<::mlir::IntegerType> evl(void) const;
  ::mx::ir::Value res(void) const;
};
static_assert(sizeof(VPStridedLoadOp) == sizeof(Operation));

class MX_EXPORT VPStridedStoreOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_EXPERIMENTAL_VP_STRIDED_STORE;
  }

  static std::optional<VPStridedStoreOp> from(const ::mx::ir::Operation &that);
  static std::optional<VPStridedStoreOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::VPStridedStoreOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value val(void) const;
  //::mlir::TypedValue<::mlir::LLVM::LLVMPointerType> ptr(void) const;
  //::mlir::TypedValue<::mlir::IntegerType> stride(void) const;
  ::mx::ir::Value mask(void) const;
  //::mlir::TypedValue<::mlir::IntegerType> evl(void) const;
};
static_assert(sizeof(VPStridedStoreOp) == sizeof(Operation));

class MX_EXPORT VPSubOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_VP_SUB;
  }

  static std::optional<VPSubOp> from(const ::mx::ir::Operation &that);
  static std::optional<VPSubOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::VPSubOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value lhs(void) const;
  ::mx::ir::Value rhs(void) const;
  ::mx::ir::Value mask(void) const;
  //::mlir::TypedValue<::mlir::IntegerType> evl(void) const;
  ::mx::ir::Value res(void) const;
};
static_assert(sizeof(VPSubOp) == sizeof(Operation));

class MX_EXPORT VPTruncOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_VP_TRUNC;
  }

  static std::optional<VPTruncOp> from(const ::mx::ir::Operation &that);
  static std::optional<VPTruncOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::VPTruncOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value src(void) const;
  ::mx::ir::Value mask(void) const;
  //::mlir::TypedValue<::mlir::IntegerType> evl(void) const;
  ::mx::ir::Value res(void) const;
};
static_assert(sizeof(VPTruncOp) == sizeof(Operation));

class MX_EXPORT VPUDivOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_VP_UDIV;
  }

  static std::optional<VPUDivOp> from(const ::mx::ir::Operation &that);
  static std::optional<VPUDivOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::VPUDivOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value lhs(void) const;
  ::mx::ir::Value rhs(void) const;
  ::mx::ir::Value mask(void) const;
  //::mlir::TypedValue<::mlir::IntegerType> evl(void) const;
  ::mx::ir::Value res(void) const;
};
static_assert(sizeof(VPUDivOp) == sizeof(Operation));

class MX_EXPORT VPUIToFPOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_VP_UITOFP;
  }

  static std::optional<VPUIToFPOp> from(const ::mx::ir::Operation &that);
  static std::optional<VPUIToFPOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::VPUIToFPOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value src(void) const;
  ::mx::ir::Value mask(void) const;
  //::mlir::TypedValue<::mlir::IntegerType> evl(void) const;
  ::mx::ir::Value res(void) const;
};
static_assert(sizeof(VPUIToFPOp) == sizeof(Operation));

class MX_EXPORT VPURemOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_VP_UREM;
  }

  static std::optional<VPURemOp> from(const ::mx::ir::Operation &that);
  static std::optional<VPURemOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::VPURemOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value lhs(void) const;
  ::mx::ir::Value rhs(void) const;
  ::mx::ir::Value mask(void) const;
  //::mlir::TypedValue<::mlir::IntegerType> evl(void) const;
  ::mx::ir::Value res(void) const;
};
static_assert(sizeof(VPURemOp) == sizeof(Operation));

class MX_EXPORT VPXorOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_VP_XOR;
  }

  static std::optional<VPXorOp> from(const ::mx::ir::Operation &that);
  static std::optional<VPXorOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::VPXorOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value lhs(void) const;
  ::mx::ir::Value rhs(void) const;
  ::mx::ir::Value mask(void) const;
  //::mlir::TypedValue<::mlir::IntegerType> evl(void) const;
  ::mx::ir::Value res(void) const;
};
static_assert(sizeof(VPXorOp) == sizeof(Operation));

class MX_EXPORT VPZExtOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_VP_ZEXT;
  }

  static std::optional<VPZExtOp> from(const ::mx::ir::Operation &that);
  static std::optional<VPZExtOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::VPZExtOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value src(void) const;
  ::mx::ir::Value mask(void) const;
  //::mlir::TypedValue<::mlir::IntegerType> evl(void) const;
  ::mx::ir::Value res(void) const;
};
static_assert(sizeof(VPZExtOp) == sizeof(Operation));

class MX_EXPORT VaCopyOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_VACOPY;
  }

  static std::optional<VaCopyOp> from(const ::mx::ir::Operation &that);
  static std::optional<VaCopyOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::VaCopyOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value dest_list(void) const;
  ::mx::ir::Value src_list(void) const;
};
static_assert(sizeof(VaCopyOp) == sizeof(Operation));

class MX_EXPORT VaEndOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_VAEND;
  }

  static std::optional<VaEndOp> from(const ::mx::ir::Operation &that);
  static std::optional<VaEndOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::VaEndOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value arg_list(void) const;
};
static_assert(sizeof(VaEndOp) == sizeof(Operation));

class MX_EXPORT VaStartOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_VASTART;
  }

  static std::optional<VaStartOp> from(const ::mx::ir::Operation &that);
  static std::optional<VaStartOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::VaStartOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value arg_list(void) const;
};
static_assert(sizeof(VaStartOp) == sizeof(Operation));

class MX_EXPORT VarAnnotationOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_VAR_ANNOTATION;
  }

  static std::optional<VarAnnotationOp> from(const ::mx::ir::Operation &that);
  static std::optional<VarAnnotationOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::VarAnnotation underlying_repr(void) const noexcept;

  // Imported methods:
  //::mlir::TypedValue<::mlir::LLVM::LLVMPointerType> val(void) const;
  //::mlir::TypedValue<::mlir::LLVM::LLVMPointerType> annotation(void) const;
  //::mlir::TypedValue<::mlir::LLVM::LLVMPointerType> file_name(void) const;
  //::mlir::TypedValue<::mlir::IntegerType> line(void) const;
  //::mlir::TypedValue<::mlir::LLVM::LLVMPointerType> attr(void) const;
};
static_assert(sizeof(VarAnnotationOp) == sizeof(Operation));

class MX_EXPORT MaskedCompressStoreOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_MASKED_COMPRESSSTORE;
  }

  static std::optional<MaskedCompressStoreOp> from(const ::mx::ir::Operation &that);
  static std::optional<MaskedCompressStoreOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::masked_compressstore underlying_repr(void) const noexcept;

  // Imported methods:
};
static_assert(sizeof(MaskedCompressStoreOp) == sizeof(Operation));

class MX_EXPORT MaskedExpandLoadOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_MASKED_EXPANDLOAD;
  }

  static std::optional<MaskedExpandLoadOp> from(const ::mx::ir::Operation &that);
  static std::optional<MaskedExpandLoadOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::masked_expandload underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value res(void) const;
};
static_assert(sizeof(MaskedExpandLoadOp) == sizeof(Operation));

class MX_EXPORT MaskedGatherOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_MASKED_GATHER;
  }

  static std::optional<MaskedGatherOp> from(const ::mx::ir::Operation &that);
  static std::optional<MaskedGatherOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::masked_gather underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value ptrs(void) const;
  ::mx::ir::Value mask(void) const;
  gap::generator<::mx::ir::Operand> pass_thru(void) const;
  ::mx::ir::Value res(void) const;
  uint32_t alignment(void) const;
};
static_assert(sizeof(MaskedGatherOp) == sizeof(Operation));

class MX_EXPORT MaskedScatterOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_MASKED_SCATTER;
  }

  static std::optional<MaskedScatterOp> from(const ::mx::ir::Operation &that);
  static std::optional<MaskedScatterOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::masked_scatter underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value value(void) const;
  ::mx::ir::Value ptrs(void) const;
  ::mx::ir::Value mask(void) const;
  uint32_t alignment(void) const;
};
static_assert(sizeof(MaskedScatterOp) == sizeof(Operation));

class MX_EXPORT VectorExtractOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_VECTOR_EXTRACT;
  }

  static std::optional<VectorExtractOp> from(const ::mx::ir::Operation &that);
  static std::optional<VectorExtractOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::vector_extract underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value srcvec(void) const;
  ::mx::ir::Value res(void) const;
  uint64_t pos(void) const;
  uint64_t src_vector_bit_width(void) const;
  uint64_t res_vector_bit_width(void) const;
};
static_assert(sizeof(VectorExtractOp) == sizeof(Operation));

class MX_EXPORT VectorInsertOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_VECTOR_INSERT;
  }

  static std::optional<VectorInsertOp> from(const ::mx::ir::Operation &that);
  static std::optional<VectorInsertOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::vector_insert underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value srcvec(void) const;
  ::mx::ir::Value dstvec(void) const;
  ::mx::ir::Value res(void) const;
  uint64_t pos(void) const;
  uint64_t src_vector_bit_width(void) const;
  uint64_t dst_vector_bit_width(void) const;
};
static_assert(sizeof(VectorInsertOp) == sizeof(Operation));

class MX_EXPORT VectorReduceAddOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_VECTOR_REDUCE_ADD;
  }

  static std::optional<VectorReduceAddOp> from(const ::mx::ir::Operation &that);
  static std::optional<VectorReduceAddOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::vector_reduce_add underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value in(void) const;
  ::mx::ir::Value res(void) const;
};
static_assert(sizeof(VectorReduceAddOp) == sizeof(Operation));

class MX_EXPORT VectorReduceAndOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_VECTOR_REDUCE_AND;
  }

  static std::optional<VectorReduceAndOp> from(const ::mx::ir::Operation &that);
  static std::optional<VectorReduceAndOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::vector_reduce_and underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value in(void) const;
  ::mx::ir::Value res(void) const;
};
static_assert(sizeof(VectorReduceAndOp) == sizeof(Operation));

class MX_EXPORT VectorReduceFAddOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_VECTOR_REDUCE_FADD;
  }

  static std::optional<VectorReduceFAddOp> from(const ::mx::ir::Operation &that);
  static std::optional<VectorReduceFAddOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::vector_reduce_fadd underlying_repr(void) const noexcept;

  // Imported methods:
  //::mlir::TypedValue<::mlir::FloatType> start_value(void) const;
  ::mx::ir::Value input(void) const;
  ::mx::ir::Value res(void) const;
  bool reassoc(void) const;
};
static_assert(sizeof(VectorReduceFAddOp) == sizeof(Operation));

class MX_EXPORT VectorReduceFMaxOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_VECTOR_REDUCE_FMAX;
  }

  static std::optional<VectorReduceFMaxOp> from(const ::mx::ir::Operation &that);
  static std::optional<VectorReduceFMaxOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::vector_reduce_fmax underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value in(void) const;
  ::mx::ir::Value res(void) const;
  //::mlir::LLVM::FastmathFlags fastmath_flags(void) const;
};
static_assert(sizeof(VectorReduceFMaxOp) == sizeof(Operation));

class MX_EXPORT VectorReduceFMaximumOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_VECTOR_REDUCE_FMAXIMUM;
  }

  static std::optional<VectorReduceFMaximumOp> from(const ::mx::ir::Operation &that);
  static std::optional<VectorReduceFMaximumOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::vector_reduce_fmaximum underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value in(void) const;
  ::mx::ir::Value res(void) const;
  //::mlir::LLVM::FastmathFlags fastmath_flags(void) const;
};
static_assert(sizeof(VectorReduceFMaximumOp) == sizeof(Operation));

class MX_EXPORT VectorReduceFMinOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_VECTOR_REDUCE_FMIN;
  }

  static std::optional<VectorReduceFMinOp> from(const ::mx::ir::Operation &that);
  static std::optional<VectorReduceFMinOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::vector_reduce_fmin underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value in(void) const;
  ::mx::ir::Value res(void) const;
  //::mlir::LLVM::FastmathFlags fastmath_flags(void) const;
};
static_assert(sizeof(VectorReduceFMinOp) == sizeof(Operation));

class MX_EXPORT VectorReduceFMinimumOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_VECTOR_REDUCE_FMINIMUM;
  }

  static std::optional<VectorReduceFMinimumOp> from(const ::mx::ir::Operation &that);
  static std::optional<VectorReduceFMinimumOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::vector_reduce_fminimum underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value in(void) const;
  ::mx::ir::Value res(void) const;
  //::mlir::LLVM::FastmathFlags fastmath_flags(void) const;
};
static_assert(sizeof(VectorReduceFMinimumOp) == sizeof(Operation));

class MX_EXPORT VectorReduceFMulOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_VECTOR_REDUCE_FMUL;
  }

  static std::optional<VectorReduceFMulOp> from(const ::mx::ir::Operation &that);
  static std::optional<VectorReduceFMulOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::vector_reduce_fmul underlying_repr(void) const noexcept;

  // Imported methods:
  //::mlir::TypedValue<::mlir::FloatType> start_value(void) const;
  ::mx::ir::Value input(void) const;
  ::mx::ir::Value res(void) const;
  bool reassoc(void) const;
};
static_assert(sizeof(VectorReduceFMulOp) == sizeof(Operation));

class MX_EXPORT VectorReduceMulOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_VECTOR_REDUCE_MUL;
  }

  static std::optional<VectorReduceMulOp> from(const ::mx::ir::Operation &that);
  static std::optional<VectorReduceMulOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::vector_reduce_mul underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value in(void) const;
  ::mx::ir::Value res(void) const;
};
static_assert(sizeof(VectorReduceMulOp) == sizeof(Operation));

class MX_EXPORT VectorReduceOrOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_VECTOR_REDUCE_OR;
  }

  static std::optional<VectorReduceOrOp> from(const ::mx::ir::Operation &that);
  static std::optional<VectorReduceOrOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::vector_reduce_or underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value in(void) const;
  ::mx::ir::Value res(void) const;
};
static_assert(sizeof(VectorReduceOrOp) == sizeof(Operation));

class MX_EXPORT VectorReduceSMaxOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_VECTOR_REDUCE_SMAX;
  }

  static std::optional<VectorReduceSMaxOp> from(const ::mx::ir::Operation &that);
  static std::optional<VectorReduceSMaxOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::vector_reduce_smax underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value in(void) const;
  ::mx::ir::Value res(void) const;
};
static_assert(sizeof(VectorReduceSMaxOp) == sizeof(Operation));

class MX_EXPORT VectorReduceSMinOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_VECTOR_REDUCE_SMIN;
  }

  static std::optional<VectorReduceSMinOp> from(const ::mx::ir::Operation &that);
  static std::optional<VectorReduceSMinOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::vector_reduce_smin underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value in(void) const;
  ::mx::ir::Value res(void) const;
};
static_assert(sizeof(VectorReduceSMinOp) == sizeof(Operation));

class MX_EXPORT VectorReduceUMaxOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_VECTOR_REDUCE_UMAX;
  }

  static std::optional<VectorReduceUMaxOp> from(const ::mx::ir::Operation &that);
  static std::optional<VectorReduceUMaxOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::vector_reduce_umax underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value in(void) const;
  ::mx::ir::Value res(void) const;
};
static_assert(sizeof(VectorReduceUMaxOp) == sizeof(Operation));

class MX_EXPORT VectorReduceUMinOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_VECTOR_REDUCE_UMIN;
  }

  static std::optional<VectorReduceUMinOp> from(const ::mx::ir::Operation &that);
  static std::optional<VectorReduceUMinOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::vector_reduce_umin underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value in(void) const;
  ::mx::ir::Value res(void) const;
};
static_assert(sizeof(VectorReduceUMinOp) == sizeof(Operation));

class MX_EXPORT VectorReduceXorOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_VECTOR_REDUCE_XOR;
  }

  static std::optional<VectorReduceXorOp> from(const ::mx::ir::Operation &that);
  static std::optional<VectorReduceXorOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::vector_reduce_xor underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value in(void) const;
  ::mx::ir::Value res(void) const;
};
static_assert(sizeof(VectorReduceXorOp) == sizeof(Operation));

class MX_EXPORT VScaleOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_VSCALE;
  }

  static std::optional<VScaleOp> from(const ::mx::ir::Operation &that);
  static std::optional<VScaleOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::vscale underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value res(void) const;
};
static_assert(sizeof(VScaleOp) == sizeof(Operation));

}  // namespace mx::ir::llvm
