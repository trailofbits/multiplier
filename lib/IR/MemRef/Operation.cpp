// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/IR/MemRef/Operation.h>

#include <multiplier/IR/Attribute.h>
#include <multiplier/IR/Block.h>
#include <multiplier/IR/Region.h>
#include <multiplier/IR/Type.h>

#include <ios>
#include <string>

#include <mlir/Dialect/LLVMIR/LLVMDialect.h>
#include <mlir/Dialect/MemRef/IR/MemRef.h>

namespace mx::ir::memref {
std::optional<Operation> Operation::from(const ::mx::ir::Operation &that) {
  if (IsMemRefOperationKind(that.kind())) {
    return reinterpret_cast<const Operation &>(that);
  }
  return std::nullopt;
}

std::optional<AssumeAlignmentOp> AssumeAlignmentOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::MEMREF_ASSUME_ALIGNMENT) {
    return reinterpret_cast<const AssumeAlignmentOp &>(that);
  }
  return std::nullopt;
}

std::optional<AssumeAlignmentOp> AssumeAlignmentOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::memref::AssumeAlignmentOp AssumeAlignmentOp::underlying_repr(void) const noexcept {
  return ::mlir::memref::AssumeAlignmentOp(this->::mx::ir::Operation::op_);
}

uint32_t AssumeAlignmentOp::alignment(void) const {
  auto val = underlying_repr().getAlignment();
  return val;
}

std::optional<AtomicRMWOp> AtomicRMWOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::MEMREF_ATOMIC_RMW) {
    return reinterpret_cast<const AtomicRMWOp &>(that);
  }
  return std::nullopt;
}

std::optional<AtomicRMWOp> AtomicRMWOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::memref::AtomicRMWOp AtomicRMWOp::underlying_repr(void) const noexcept {
  return ::mlir::memref::AtomicRMWOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value AtomicRMWOp::value(void) const {
  auto val = underlying_repr().getValue();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value AtomicRMWOp::result(void) const {
  auto val = underlying_repr().getResult();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<AtomicYieldOp> AtomicYieldOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::MEMREF_ATOMIC_YIELD) {
    return reinterpret_cast<const AtomicYieldOp &>(that);
  }
  return std::nullopt;
}

std::optional<AtomicYieldOp> AtomicYieldOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::memref::AtomicYieldOp AtomicYieldOp::underlying_repr(void) const noexcept {
  return ::mlir::memref::AtomicYieldOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value AtomicYieldOp::result(void) const {
  auto val = underlying_repr().getResult();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<CopyOp> CopyOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::MEMREF_COPY) {
    return reinterpret_cast<const CopyOp &>(that);
  }
  return std::nullopt;
}

std::optional<CopyOp> CopyOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::memref::CopyOp CopyOp::underlying_repr(void) const noexcept {
  return ::mlir::memref::CopyOp(this->::mx::ir::Operation::op_);
}

std::optional<GenericAtomicRMWOp> GenericAtomicRMWOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::MEMREF_GENERIC_ATOMIC_RMW) {
    return reinterpret_cast<const GenericAtomicRMWOp &>(that);
  }
  return std::nullopt;
}

std::optional<GenericAtomicRMWOp> GenericAtomicRMWOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::memref::GenericAtomicRMWOp GenericAtomicRMWOp::underlying_repr(void) const noexcept {
  return ::mlir::memref::GenericAtomicRMWOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value GenericAtomicRMWOp::result(void) const {
  auto val = underlying_repr().getResult();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Region GenericAtomicRMWOp::atomic_body(void) const {
  auto &val = underlying_repr().getAtomicBody();
  return ::mx::ir::Region(module_, val);
}

std::optional<LoadOp> LoadOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::MEMREF_LOAD) {
    return reinterpret_cast<const LoadOp &>(that);
  }
  return std::nullopt;
}

std::optional<LoadOp> LoadOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::memref::LoadOp LoadOp::underlying_repr(void) const noexcept {
  return ::mlir::memref::LoadOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value LoadOp::result(void) const {
  auto val = underlying_repr().getResult();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

bool LoadOp::nontemporal(void) const {
  auto val = underlying_repr().getNontemporal();
  return val;
}

std::optional<AllocOp> AllocOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::MEMREF_ALLOC) {
    return reinterpret_cast<const AllocOp &>(that);
  }
  return std::nullopt;
}

std::optional<AllocOp> AllocOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::memref::AllocOp AllocOp::underlying_repr(void) const noexcept {
  return ::mlir::memref::AllocOp(this->::mx::ir::Operation::op_);
}

std::optional<unsigned long long> AllocOp::alignment(void) const {
  auto opt_val = underlying_repr().getAlignment();
  if (!opt_val) {
    return std::nullopt;
  }
  auto &val = opt_val.value();
  return val;
}

std::optional<AllocaOp> AllocaOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::MEMREF_ALLOCA) {
    return reinterpret_cast<const AllocaOp &>(that);
  }
  return std::nullopt;
}

std::optional<AllocaOp> AllocaOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::memref::AllocaOp AllocaOp::underlying_repr(void) const noexcept {
  return ::mlir::memref::AllocaOp(this->::mx::ir::Operation::op_);
}

std::optional<unsigned long long> AllocaOp::alignment(void) const {
  auto opt_val = underlying_repr().getAlignment();
  if (!opt_val) {
    return std::nullopt;
  }
  auto &val = opt_val.value();
  return val;
}

std::optional<AllocaScopeOp> AllocaScopeOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::MEMREF_ALLOCA_SCOPE) {
    return reinterpret_cast<const AllocaScopeOp &>(that);
  }
  return std::nullopt;
}

std::optional<AllocaScopeOp> AllocaScopeOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::memref::AllocaScopeOp AllocaScopeOp::underlying_repr(void) const noexcept {
  return ::mlir::memref::AllocaScopeOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Region AllocaScopeOp::body_region(void) const {
  auto &val = underlying_repr().getBodyRegion();
  return ::mx::ir::Region(module_, val);
}

std::optional<AllocaScopeReturnOp> AllocaScopeReturnOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::MEMREF_ALLOCA_SCOPE_RETURN) {
    return reinterpret_cast<const AllocaScopeReturnOp &>(that);
  }
  return std::nullopt;
}

std::optional<AllocaScopeReturnOp> AllocaScopeReturnOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::memref::AllocaScopeReturnOp AllocaScopeReturnOp::underlying_repr(void) const noexcept {
  return ::mlir::memref::AllocaScopeReturnOp(this->::mx::ir::Operation::op_);
}

std::optional<CastOp> CastOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::MEMREF_CAST) {
    return reinterpret_cast<const CastOp &>(that);
  }
  return std::nullopt;
}

std::optional<CastOp> CastOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::memref::CastOp CastOp::underlying_repr(void) const noexcept {
  return ::mlir::memref::CastOp(this->::mx::ir::Operation::op_);
}

std::optional<CollapseShapeOp> CollapseShapeOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::MEMREF_COLLAPSE_SHAPE) {
    return reinterpret_cast<const CollapseShapeOp &>(that);
  }
  return std::nullopt;
}

std::optional<CollapseShapeOp> CollapseShapeOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::memref::CollapseShapeOp CollapseShapeOp::underlying_repr(void) const noexcept {
  return ::mlir::memref::CollapseShapeOp(this->::mx::ir::Operation::op_);
}

std::optional<DeallocOp> DeallocOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::MEMREF_DEALLOC) {
    return reinterpret_cast<const DeallocOp &>(that);
  }
  return std::nullopt;
}

std::optional<DeallocOp> DeallocOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::memref::DeallocOp DeallocOp::underlying_repr(void) const noexcept {
  return ::mlir::memref::DeallocOp(this->::mx::ir::Operation::op_);
}

std::optional<DimOp> DimOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::MEMREF_DIM) {
    return reinterpret_cast<const DimOp &>(that);
  }
  return std::nullopt;
}

std::optional<DimOp> DimOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::memref::DimOp DimOp::underlying_repr(void) const noexcept {
  return ::mlir::memref::DimOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value DimOp::source(void) const {
  auto val = underlying_repr().getSource();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<long long> DimOp::constant_index(void) const {
  auto opt_val = underlying_repr().getConstantIndex();
  if (!opt_val) {
    return std::nullopt;
  }
  auto &val = opt_val.value();
  return val;
}

std::optional<DMAStartOp> DMAStartOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::MEMREF_DMA_START) {
    return reinterpret_cast<const DMAStartOp &>(that);
  }
  return std::nullopt;
}

std::optional<DMAStartOp> DMAStartOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::memref::DmaStartOp DMAStartOp::underlying_repr(void) const noexcept {
  return ::mlir::memref::DmaStartOp(this->::mx::ir::Operation::op_);
}

unsigned int DMAStartOp::src_mem_ref_rank(void) const {
  auto val = underlying_repr().getSrcMemRefRank();
  return val;
}

unsigned int DMAStartOp::dst_mem_ref_rank(void) const {
  auto val = underlying_repr().getDstMemRefRank();
  return val;
}

unsigned int DMAStartOp::src_memory_space(void) const {
  auto val = underlying_repr().getSrcMemorySpace();
  return val;
}

unsigned int DMAStartOp::dst_memory_space(void) const {
  auto val = underlying_repr().getDstMemorySpace();
  return val;
}

unsigned int DMAStartOp::tag_mem_ref_rank(void) const {
  auto val = underlying_repr().getTagMemRefRank();
  return val;
}

bool DMAStartOp::is_dest_memory_space_faster(void) const {
  auto val = underlying_repr().isDestMemorySpaceFaster();
  return val;
}

bool DMAStartOp::is_src_memory_space_faster(void) const {
  auto val = underlying_repr().isSrcMemorySpaceFaster();
  return val;
}

unsigned int DMAStartOp::faster_mem_pos(void) const {
  auto val = underlying_repr().getFasterMemPos();
  return val;
}

bool DMAStartOp::is_strided(void) const {
  auto val = underlying_repr().isStrided();
  return val;
}

std::optional<DMAWaitOp> DMAWaitOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::MEMREF_DMA_WAIT) {
    return reinterpret_cast<const DMAWaitOp &>(that);
  }
  return std::nullopt;
}

std::optional<DMAWaitOp> DMAWaitOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::memref::DmaWaitOp DMAWaitOp::underlying_repr(void) const noexcept {
  return ::mlir::memref::DmaWaitOp(this->::mx::ir::Operation::op_);
}

unsigned int DMAWaitOp::tag_mem_ref_rank(void) const {
  auto val = underlying_repr().getTagMemRefRank();
  return val;
}

std::optional<ExpandShapeOp> ExpandShapeOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::MEMREF_EXPAND_SHAPE) {
    return reinterpret_cast<const ExpandShapeOp &>(that);
  }
  return std::nullopt;
}

std::optional<ExpandShapeOp> ExpandShapeOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::memref::ExpandShapeOp ExpandShapeOp::underlying_repr(void) const noexcept {
  return ::mlir::memref::ExpandShapeOp(this->::mx::ir::Operation::op_);
}

std::optional<ExtractAlignedPointerAsIndexOp> ExtractAlignedPointerAsIndexOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::MEMREF_EXTRACT_ALIGNED_POINTER_AS_INDEX) {
    return reinterpret_cast<const ExtractAlignedPointerAsIndexOp &>(that);
  }
  return std::nullopt;
}

std::optional<ExtractAlignedPointerAsIndexOp> ExtractAlignedPointerAsIndexOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::memref::ExtractAlignedPointerAsIndexOp ExtractAlignedPointerAsIndexOp::underlying_repr(void) const noexcept {
  return ::mlir::memref::ExtractAlignedPointerAsIndexOp(this->::mx::ir::Operation::op_);
}

std::optional<ExtractStridedMetadataOp> ExtractStridedMetadataOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::MEMREF_EXTRACT_STRIDED_METADATA) {
    return reinterpret_cast<const ExtractStridedMetadataOp &>(that);
  }
  return std::nullopt;
}

std::optional<ExtractStridedMetadataOp> ExtractStridedMetadataOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::memref::ExtractStridedMetadataOp ExtractStridedMetadataOp::underlying_repr(void) const noexcept {
  return ::mlir::memref::ExtractStridedMetadataOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value ExtractStridedMetadataOp::base_buffer(void) const {
  auto val = underlying_repr().getBaseBuffer();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value ExtractStridedMetadataOp::view_source(void) const {
  auto val = underlying_repr().getViewSource();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<GetGlobalOp> GetGlobalOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::MEMREF_GET_GLOBAL) {
    return reinterpret_cast<const GetGlobalOp &>(that);
  }
  return std::nullopt;
}

std::optional<GetGlobalOp> GetGlobalOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::memref::GetGlobalOp GetGlobalOp::underlying_repr(void) const noexcept {
  return ::mlir::memref::GetGlobalOp(this->::mx::ir::Operation::op_);
}

std::string_view GetGlobalOp::name(void) const {
  auto val = underlying_repr().getName();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return {};
  }
}

std::optional<GlobalOp> GlobalOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::MEMREF_GLOBAL) {
    return reinterpret_cast<const GlobalOp &>(that);
  }
  return std::nullopt;
}

std::optional<GlobalOp> GlobalOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::memref::GlobalOp GlobalOp::underlying_repr(void) const noexcept {
  return ::mlir::memref::GlobalOp(this->::mx::ir::Operation::op_);
}

std::string_view GlobalOp::sym_name(void) const {
  auto val = underlying_repr().getSymName();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return {};
  }
}

std::optional<std::string_view> GlobalOp::sym_visibility(void) const {
  auto opt_val = underlying_repr().getSymVisibility();
  if (!opt_val) {
    return std::nullopt;
  }
  auto &val = opt_val.value();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return {};
  }
}

bool GlobalOp::constant(void) const {
  auto val = underlying_repr().getConstant();
  return val;
}

std::optional<unsigned long long> GlobalOp::alignment(void) const {
  auto opt_val = underlying_repr().getAlignment();
  if (!opt_val) {
    return std::nullopt;
  }
  auto &val = opt_val.value();
  return val;
}

bool GlobalOp::is_external(void) const {
  auto val = underlying_repr().isExternal();
  return val;
}

bool GlobalOp::is_uninitialized(void) const {
  auto val = underlying_repr().isUninitialized();
  return val;
}

std::optional<MemorySpaceCastOp> MemorySpaceCastOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::MEMREF_MEMORY_SPACE_CAST) {
    return reinterpret_cast<const MemorySpaceCastOp &>(that);
  }
  return std::nullopt;
}

std::optional<MemorySpaceCastOp> MemorySpaceCastOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::memref::MemorySpaceCastOp MemorySpaceCastOp::underlying_repr(void) const noexcept {
  return ::mlir::memref::MemorySpaceCastOp(this->::mx::ir::Operation::op_);
}

std::optional<PrefetchOp> PrefetchOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::MEMREF_PREFETCH) {
    return reinterpret_cast<const PrefetchOp &>(that);
  }
  return std::nullopt;
}

std::optional<PrefetchOp> PrefetchOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::memref::PrefetchOp PrefetchOp::underlying_repr(void) const noexcept {
  return ::mlir::memref::PrefetchOp(this->::mx::ir::Operation::op_);
}

bool PrefetchOp::is_write(void) const {
  auto val = underlying_repr().getIsWrite();
  return val;
}

uint32_t PrefetchOp::locality_hint(void) const {
  auto val = underlying_repr().getLocalityHint();
  return val;
}

bool PrefetchOp::is_data_cache(void) const {
  auto val = underlying_repr().getIsDataCache();
  return val;
}

std::optional<RankOp> RankOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::MEMREF_RANK) {
    return reinterpret_cast<const RankOp &>(that);
  }
  return std::nullopt;
}

std::optional<RankOp> RankOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::memref::RankOp RankOp::underlying_repr(void) const noexcept {
  return ::mlir::memref::RankOp(this->::mx::ir::Operation::op_);
}

std::optional<ReallocOp> ReallocOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::MEMREF_REALLOC) {
    return reinterpret_cast<const ReallocOp &>(that);
  }
  return std::nullopt;
}

std::optional<ReallocOp> ReallocOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::memref::ReallocOp ReallocOp::underlying_repr(void) const noexcept {
  return ::mlir::memref::ReallocOp(this->::mx::ir::Operation::op_);
}

std::optional<unsigned long long> ReallocOp::alignment(void) const {
  auto opt_val = underlying_repr().getAlignment();
  if (!opt_val) {
    return std::nullopt;
  }
  auto &val = opt_val.value();
  return val;
}

std::optional<ReinterpretCastOp> ReinterpretCastOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::MEMREF_REINTERPRET_CAST) {
    return reinterpret_cast<const ReinterpretCastOp &>(that);
  }
  return std::nullopt;
}

std::optional<ReinterpretCastOp> ReinterpretCastOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::memref::ReinterpretCastOp ReinterpretCastOp::underlying_repr(void) const noexcept {
  return ::mlir::memref::ReinterpretCastOp(this->::mx::ir::Operation::op_);
}

unsigned int ReinterpretCastOp::result_rank(void) const {
  auto val = underlying_repr().getResultRank();
  return val;
}

unsigned int ReinterpretCastOp::offset_size_and_stride_start_operand_index(void) const {
  auto val = underlying_repr().getOffsetSizeAndStrideStartOperandIndex();
  return val;
}

std::optional<ReshapeOp> ReshapeOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::MEMREF_RESHAPE) {
    return reinterpret_cast<const ReshapeOp &>(that);
  }
  return std::nullopt;
}

std::optional<ReshapeOp> ReshapeOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::memref::ReshapeOp ReshapeOp::underlying_repr(void) const noexcept {
  return ::mlir::memref::ReshapeOp(this->::mx::ir::Operation::op_);
}

std::optional<StoreOp> StoreOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::MEMREF_STORE) {
    return reinterpret_cast<const StoreOp &>(that);
  }
  return std::nullopt;
}

std::optional<StoreOp> StoreOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::memref::StoreOp StoreOp::underlying_repr(void) const noexcept {
  return ::mlir::memref::StoreOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value StoreOp::value(void) const {
  auto val = underlying_repr().getValue();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

bool StoreOp::nontemporal(void) const {
  auto val = underlying_repr().getNontemporal();
  return val;
}

std::optional<TransposeOp> TransposeOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::MEMREF_TRANSPOSE) {
    return reinterpret_cast<const TransposeOp &>(that);
  }
  return std::nullopt;
}

std::optional<TransposeOp> TransposeOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::memref::TransposeOp TransposeOp::underlying_repr(void) const noexcept {
  return ::mlir::memref::TransposeOp(this->::mx::ir::Operation::op_);
}

std::optional<ViewOp> ViewOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::MEMREF_VIEW) {
    return reinterpret_cast<const ViewOp &>(that);
  }
  return std::nullopt;
}

std::optional<ViewOp> ViewOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::memref::ViewOp ViewOp::underlying_repr(void) const noexcept {
  return ::mlir::memref::ViewOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value ViewOp::view_source(void) const {
  auto val = underlying_repr().getViewSource();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::optional<SubViewOp> SubViewOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::MEMREF_SUBVIEW) {
    return reinterpret_cast<const SubViewOp &>(that);
  }
  return std::nullopt;
}

std::optional<SubViewOp> SubViewOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::memref::SubViewOp SubViewOp::underlying_repr(void) const noexcept {
  return ::mlir::memref::SubViewOp(this->::mx::ir::Operation::op_);
}

::mx::ir::Value SubViewOp::view_source(void) const {
  auto val = underlying_repr().getViewSource();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

unsigned int SubViewOp::offset_size_and_stride_start_operand_index(void) const {
  auto val = underlying_repr().getOffsetSizeAndStrideStartOperandIndex();
  return val;
}

}  // namespace mx::ir::memref
