// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "../Operation.h"

namespace mlir::memref {
class AssumeAlignmentOp;
class AtomicRMWOp;
class AtomicYieldOp;
class CopyOp;
class GenericAtomicRMWOp;
class LoadOp;
class AllocOp;
class AllocaOp;
class AllocaScopeOp;
class AllocaScopeReturnOp;
class CastOp;
class CollapseShapeOp;
class DeallocOp;
class DimOp;
class DmaStartOp;
class DmaWaitOp;
class ExpandShapeOp;
class ExtractAlignedPointerAsIndexOp;
class ExtractStridedMetadataOp;
class GetGlobalOp;
class GlobalOp;
class MemorySpaceCastOp;
class PrefetchOp;
class RankOp;
class ReallocOp;
class ReinterpretCastOp;
class ReshapeOp;
class StoreOp;
class TransposeOp;
class ViewOp;
class SubViewOp;
}  // namespace mlir::memref
namespace mx::ir::memref {

class MX_EXPORT Operation : public ::mx::ir::Operation {
 public:
  static std::optional<Operation> from(const ::mx::ir::Operation &);
};
static_assert(sizeof(Operation) == sizeof(::mx::ir::Operation));

class MX_EXPORT AssumeAlignmentOp final : public Operation {
 public:
  inline static constexpr OperationKind static_kind(void) {
    return OperationKind::MEMREF_ASSUME_ALIGNMENT;
  }

  static std::optional<AssumeAlignmentOp> from(const ::mx::ir::Operation &that);
  static std::optional<AssumeAlignmentOp> producing(const ::mx::ir::Value &val);

  ::mlir::memref::AssumeAlignmentOp underlying_repr(void) const noexcept;

  // Imported methods:
  //::mlir::TypedValue<MemRefType> memref(void) const;
  uint32_t alignment(void) const;
};
static_assert(sizeof(AssumeAlignmentOp) == sizeof(Operation));

class MX_EXPORT AtomicRMWOp final : public Operation {
 public:
  inline static constexpr OperationKind static_kind(void) {
    return OperationKind::MEMREF_ATOMIC_RMW;
  }

  static std::optional<AtomicRMWOp> from(const ::mx::ir::Operation &that);
  static std::optional<AtomicRMWOp> producing(const ::mx::ir::Value &val);

  ::mlir::memref::AtomicRMWOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value value(void) const;
  //::mlir::TypedValue<MemRefType> memref(void) const;
  //::mlir::Operation::operand_range indices(void) const;
  ::mx::ir::Value result(void) const;
  //::mlir::arith::AtomicRMWKind kind(void) const;
  //MemRefType mem_ref_type(void) const;
};
static_assert(sizeof(AtomicRMWOp) == sizeof(Operation));

class MX_EXPORT AtomicYieldOp final : public Operation {
 public:
  inline static constexpr OperationKind static_kind(void) {
    return OperationKind::MEMREF_ATOMIC_YIELD;
  }

  static std::optional<AtomicYieldOp> from(const ::mx::ir::Operation &that);
  static std::optional<AtomicYieldOp> producing(const ::mx::ir::Value &val);

  ::mlir::memref::AtomicYieldOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value result(void) const;
};
static_assert(sizeof(AtomicYieldOp) == sizeof(Operation));

class MX_EXPORT CopyOp final : public Operation {
 public:
  inline static constexpr OperationKind static_kind(void) {
    return OperationKind::MEMREF_COPY;
  }

  static std::optional<CopyOp> from(const ::mx::ir::Operation &that);
  static std::optional<CopyOp> producing(const ::mx::ir::Value &val);

  ::mlir::memref::CopyOp underlying_repr(void) const noexcept;

  // Imported methods:
  //::mlir::TypedValue<BaseMemRefType> source(void) const;
  //::mlir::TypedValue<BaseMemRefType> target(void) const;
};
static_assert(sizeof(CopyOp) == sizeof(Operation));

class MX_EXPORT GenericAtomicRMWOp final : public Operation {
 public:
  inline static constexpr OperationKind static_kind(void) {
    return OperationKind::MEMREF_GENERIC_ATOMIC_RMW;
  }

  static std::optional<GenericAtomicRMWOp> from(const ::mx::ir::Operation &that);
  static std::optional<GenericAtomicRMWOp> producing(const ::mx::ir::Value &val);

  ::mlir::memref::GenericAtomicRMWOp underlying_repr(void) const noexcept;

  // Imported methods:
  //::mlir::TypedValue<MemRefType> memref(void) const;
  //::mlir::Operation::operand_range indices(void) const;
  ::mx::ir::Value result(void) const;
  ::mx::ir::Region atomic_body(void) const;
  //Region & body(void) const;
  //Value current_value(void) const;
  //MemRefType mem_ref_type(void) const;
};
static_assert(sizeof(GenericAtomicRMWOp) == sizeof(Operation));

class MX_EXPORT LoadOp final : public Operation {
 public:
  inline static constexpr OperationKind static_kind(void) {
    return OperationKind::MEMREF_LOAD;
  }

  static std::optional<LoadOp> from(const ::mx::ir::Operation &that);
  static std::optional<LoadOp> producing(const ::mx::ir::Value &val);

  ::mlir::memref::LoadOp underlying_repr(void) const noexcept;

  // Imported methods:
  //::mlir::TypedValue<MemRefType> memref(void) const;
  //::mlir::Operation::operand_range indices(void) const;
  ::mx::ir::Value result(void) const;
  bool nontemporal(void) const;
  //Value mem_ref(void) const;
  //MemRefType mem_ref_type(void) const;
};
static_assert(sizeof(LoadOp) == sizeof(Operation));

class MX_EXPORT AllocOp final : public Operation {
 public:
  inline static constexpr OperationKind static_kind(void) {
    return OperationKind::MEMREF_ALLOC;
  }

  static std::optional<AllocOp> from(const ::mx::ir::Operation &that);
  static std::optional<AllocOp> producing(const ::mx::ir::Value &val);

  ::mlir::memref::AllocOp underlying_repr(void) const noexcept;

  // Imported methods:
  //::mlir::Operation::operand_range dynamic_sizes(void) const;
  //::mlir::Operation::operand_range symbol_operands(void) const;
  //::mlir::TypedValue<MemRefType> memref(void) const;
  std::optional<unsigned long long> alignment(void) const;
  //StringRef alignment_attr_str_name(void) const;
  //MemRefType type(void) const;
  //SmallVector<OpFoldResult, 6> mixed_sizes(void) const;
};
static_assert(sizeof(AllocOp) == sizeof(Operation));

class MX_EXPORT AllocaOp final : public Operation {
 public:
  inline static constexpr OperationKind static_kind(void) {
    return OperationKind::MEMREF_ALLOCA;
  }

  static std::optional<AllocaOp> from(const ::mx::ir::Operation &that);
  static std::optional<AllocaOp> producing(const ::mx::ir::Value &val);

  ::mlir::memref::AllocaOp underlying_repr(void) const noexcept;

  // Imported methods:
  //::mlir::Operation::operand_range dynamic_sizes(void) const;
  //::mlir::Operation::operand_range symbol_operands(void) const;
  //::mlir::TypedValue<MemRefType> memref(void) const;
  std::optional<unsigned long long> alignment(void) const;
  //::llvm::SmallVector<MemorySlot, 3> promotable_slots(void) const;
  //::llvm::SmallVector<DestructurableMemorySlot, 1> destructurable_slots(void) const;
  //StringRef alignment_attr_str_name(void) const;
  //MemRefType type(void) const;
  //SmallVector<OpFoldResult, 6> mixed_sizes(void) const;
};
static_assert(sizeof(AllocaOp) == sizeof(Operation));

class MX_EXPORT AllocaScopeOp final : public Operation {
 public:
  inline static constexpr OperationKind static_kind(void) {
    return OperationKind::MEMREF_ALLOCA_SCOPE;
  }

  static std::optional<AllocaScopeOp> from(const ::mx::ir::Operation &that);
  static std::optional<AllocaScopeOp> producing(const ::mx::ir::Value &val);

  ::mlir::memref::AllocaScopeOp underlying_repr(void) const noexcept;

  // Imported methods:
  //::mlir::Operation::result_range results(void) const;
  ::mx::ir::Region body_region(void) const;
};
static_assert(sizeof(AllocaScopeOp) == sizeof(Operation));

class MX_EXPORT AllocaScopeReturnOp final : public Operation {
 public:
  inline static constexpr OperationKind static_kind(void) {
    return OperationKind::MEMREF_ALLOCA_SCOPE_RETURN;
  }

  static std::optional<AllocaScopeReturnOp> from(const ::mx::ir::Operation &that);
  static std::optional<AllocaScopeReturnOp> producing(const ::mx::ir::Value &val);

  ::mlir::memref::AllocaScopeReturnOp underlying_repr(void) const noexcept;

  // Imported methods:
  //::mlir::Operation::operand_range results(void) const;
};
static_assert(sizeof(AllocaScopeReturnOp) == sizeof(Operation));

class MX_EXPORT CastOp final : public Operation {
 public:
  inline static constexpr OperationKind static_kind(void) {
    return OperationKind::MEMREF_CAST;
  }

  static std::optional<CastOp> from(const ::mx::ir::Operation &that);
  static std::optional<CastOp> producing(const ::mx::ir::Value &val);

  ::mlir::memref::CastOp underlying_repr(void) const noexcept;

  // Imported methods:
  //::mlir::TypedValue<BaseMemRefType> source(void) const;
  //::mlir::TypedValue<BaseMemRefType> dest(void) const;
  //Value view_source(void) const;
};
static_assert(sizeof(CastOp) == sizeof(Operation));

class MX_EXPORT CollapseShapeOp final : public Operation {
 public:
  inline static constexpr OperationKind static_kind(void) {
    return OperationKind::MEMREF_COLLAPSE_SHAPE;
  }

  static std::optional<CollapseShapeOp> from(const ::mx::ir::Operation &that);
  static std::optional<CollapseShapeOp> producing(const ::mx::ir::Value &val);

  ::mlir::memref::CollapseShapeOp underlying_repr(void) const noexcept;

  // Imported methods:
  //::mlir::TypedValue<MemRefType> src(void) const;
  //::mlir::TypedValue<MemRefType> result(void) const;
  //::mlir::ArrayAttr reassociation(void) const;
  //SmallVector<AffineMap, 4> reassociation_maps(void) const;
  //SmallVector<SmallVector<AffineExpr, 2>, 4> reassociation_exprs(void) const;
  //SmallVector<SmallVector<long long, 2>, 4> reassociation_indices(void) const;
  //MemRefType src_type(void) const;
  //MemRefType result_type(void) const;
  //Value view_source(void) const;
};
static_assert(sizeof(CollapseShapeOp) == sizeof(Operation));

class MX_EXPORT DeallocOp final : public Operation {
 public:
  inline static constexpr OperationKind static_kind(void) {
    return OperationKind::MEMREF_DEALLOC;
  }

  static std::optional<DeallocOp> from(const ::mx::ir::Operation &that);
  static std::optional<DeallocOp> producing(const ::mx::ir::Value &val);

  ::mlir::memref::DeallocOp underlying_repr(void) const noexcept;

  // Imported methods:
  //::mlir::TypedValue<BaseMemRefType> memref(void) const;
};
static_assert(sizeof(DeallocOp) == sizeof(Operation));

class MX_EXPORT DimOp final : public Operation {
 public:
  inline static constexpr OperationKind static_kind(void) {
    return OperationKind::MEMREF_DIM;
  }

  static std::optional<DimOp> from(const ::mx::ir::Operation &that);
  static std::optional<DimOp> producing(const ::mx::ir::Value &val);

  ::mlir::memref::DimOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value source(void) const;
  //::mlir::TypedValue<IndexType> index(void) const;
  //::mlir::TypedValue<IndexType> result(void) const;
  std::optional<long long> constant_index(void) const;
  //Value shaped_value(void) const;
  //OpFoldResult dimension(void) const;
  //Speculation::Speculatability speculatability(void) const;
};
static_assert(sizeof(DimOp) == sizeof(Operation));

class MX_EXPORT DMAStartOp final : public Operation {
 public:
  inline static constexpr OperationKind static_kind(void) {
    return OperationKind::MEMREF_DMA_START;
  }

  static std::optional<DMAStartOp> from(const ::mx::ir::Operation &that);
  static std::optional<DMAStartOp> producing(const ::mx::ir::Value &val);

  ::mlir::memref::DmaStartOp underlying_repr(void) const noexcept;

  // Imported methods:
  //::mlir::Operation::operand_range operands(void) const;
  //Value src_mem_ref(void) const;
  unsigned int src_mem_ref_rank(void) const;
  //operand_range src_indices(void) const;
  //Value dst_mem_ref(void) const;
  unsigned int dst_mem_ref_rank(void) const;
  unsigned int src_memory_space(void) const;
  unsigned int dst_memory_space(void) const;
  //operand_range dst_indices(void) const;
  //Value num_elements(void) const;
  //Value tag_mem_ref(void) const;
  unsigned int tag_mem_ref_rank(void) const;
  //operand_range tag_indices(void) const;
  bool is_dest_memory_space_faster(void) const;
  bool is_src_memory_space_faster(void) const;
  unsigned int faster_mem_pos(void) const;
  bool is_strided(void) const;
  //Value stride(void) const;
  //Value num_elements_per_stride(void) const;
};
static_assert(sizeof(DMAStartOp) == sizeof(Operation));

class MX_EXPORT DMAWaitOp final : public Operation {
 public:
  inline static constexpr OperationKind static_kind(void) {
    return OperationKind::MEMREF_DMA_WAIT;
  }

  static std::optional<DMAWaitOp> from(const ::mx::ir::Operation &that);
  static std::optional<DMAWaitOp> producing(const ::mx::ir::Value &val);

  ::mlir::memref::DmaWaitOp underlying_repr(void) const noexcept;

  // Imported methods:
  //::mlir::TypedValue<MemRefType> tag_mem_ref(void) const;
  //::mlir::Operation::operand_range tag_indices(void) const;
  //::mlir::TypedValue<IndexType> num_elements(void) const;
  unsigned int tag_mem_ref_rank(void) const;
};
static_assert(sizeof(DMAWaitOp) == sizeof(Operation));

class MX_EXPORT ExpandShapeOp final : public Operation {
 public:
  inline static constexpr OperationKind static_kind(void) {
    return OperationKind::MEMREF_EXPAND_SHAPE;
  }

  static std::optional<ExpandShapeOp> from(const ::mx::ir::Operation &that);
  static std::optional<ExpandShapeOp> producing(const ::mx::ir::Value &val);

  ::mlir::memref::ExpandShapeOp underlying_repr(void) const noexcept;

  // Imported methods:
  //::mlir::TypedValue<MemRefType> src(void) const;
  //::mlir::TypedValue<MemRefType> result(void) const;
  //::mlir::ArrayAttr reassociation(void) const;
  //SmallVector<AffineMap, 4> reassociation_maps(void) const;
  //SmallVector<SmallVector<AffineExpr, 2>, 4> reassociation_exprs(void) const;
  //SmallVector<SmallVector<long long, 2>, 4> reassociation_indices(void) const;
  //MemRefType src_type(void) const;
  //MemRefType result_type(void) const;
  //Value view_source(void) const;
};
static_assert(sizeof(ExpandShapeOp) == sizeof(Operation));

class MX_EXPORT ExtractAlignedPointerAsIndexOp final : public Operation {
 public:
  inline static constexpr OperationKind static_kind(void) {
    return OperationKind::MEMREF_EXTRACT_ALIGNED_POINTER_AS_INDEX;
  }

  static std::optional<ExtractAlignedPointerAsIndexOp> from(const ::mx::ir::Operation &that);
  static std::optional<ExtractAlignedPointerAsIndexOp> producing(const ::mx::ir::Value &val);

  ::mlir::memref::ExtractAlignedPointerAsIndexOp underlying_repr(void) const noexcept;

  // Imported methods:
  //::mlir::TypedValue<MemRefType> source(void) const;
  //::mlir::TypedValue<IndexType> aligned_pointer(void) const;
};
static_assert(sizeof(ExtractAlignedPointerAsIndexOp) == sizeof(Operation));

class MX_EXPORT ExtractStridedMetadataOp final : public Operation {
 public:
  inline static constexpr OperationKind static_kind(void) {
    return OperationKind::MEMREF_EXTRACT_STRIDED_METADATA;
  }

  static std::optional<ExtractStridedMetadataOp> from(const ::mx::ir::Operation &that);
  static std::optional<ExtractStridedMetadataOp> producing(const ::mx::ir::Value &val);

  ::mlir::memref::ExtractStridedMetadataOp underlying_repr(void) const noexcept;

  // Imported methods:
  //::mlir::TypedValue<MemRefType> source(void) const;
  ::mx::ir::Value base_buffer(void) const;
  //::mlir::TypedValue<IndexType> offset(void) const;
  //::mlir::Operation::result_range sizes(void) const;
  //::mlir::Operation::result_range strides(void) const;
  //SmallVector<OpFoldResult, 6> constified_mixed_sizes(void) const;
  //SmallVector<OpFoldResult, 6> constified_mixed_strides(void) const;
  //OpFoldResult constified_mixed_offset(void) const;
  ::mx::ir::Value view_source(void) const;
};
static_assert(sizeof(ExtractStridedMetadataOp) == sizeof(Operation));

class MX_EXPORT GetGlobalOp final : public Operation {
 public:
  inline static constexpr OperationKind static_kind(void) {
    return OperationKind::MEMREF_GET_GLOBAL;
  }

  static std::optional<GetGlobalOp> from(const ::mx::ir::Operation &that);
  static std::optional<GetGlobalOp> producing(const ::mx::ir::Value &val);

  ::mlir::memref::GetGlobalOp underlying_repr(void) const noexcept;

  // Imported methods:
  //::mlir::TypedValue<MemRefType> result(void) const;
  std::string_view name(void) const;
};
static_assert(sizeof(GetGlobalOp) == sizeof(Operation));

class MX_EXPORT GlobalOp final : public Operation {
 public:
  inline static constexpr OperationKind static_kind(void) {
    return OperationKind::MEMREF_GLOBAL;
  }

  static std::optional<GlobalOp> from(const ::mx::ir::Operation &that);
  static std::optional<GlobalOp> producing(const ::mx::ir::Value &val);

  ::mlir::memref::GlobalOp underlying_repr(void) const noexcept;

  // Imported methods:
  std::string_view sym_name(void) const;
  std::optional<std::string_view> sym_visibility(void) const;
  //::mlir::MemRefType type(void) const;
  //::std::optional<Attribute> initial_value(void) const;
  bool constant(void) const;
  std::optional<unsigned long long> alignment(void) const;
  bool is_external(void) const;
  bool is_uninitialized(void) const;
  //ElementsAttr constant_init_value(void) const;
};
static_assert(sizeof(GlobalOp) == sizeof(Operation));

class MX_EXPORT MemorySpaceCastOp final : public Operation {
 public:
  inline static constexpr OperationKind static_kind(void) {
    return OperationKind::MEMREF_MEMORY_SPACE_CAST;
  }

  static std::optional<MemorySpaceCastOp> from(const ::mx::ir::Operation &that);
  static std::optional<MemorySpaceCastOp> producing(const ::mx::ir::Value &val);

  ::mlir::memref::MemorySpaceCastOp underlying_repr(void) const noexcept;

  // Imported methods:
  //::mlir::TypedValue<BaseMemRefType> source(void) const;
  //::mlir::TypedValue<BaseMemRefType> dest(void) const;
  //Value view_source(void) const;
};
static_assert(sizeof(MemorySpaceCastOp) == sizeof(Operation));

class MX_EXPORT PrefetchOp final : public Operation {
 public:
  inline static constexpr OperationKind static_kind(void) {
    return OperationKind::MEMREF_PREFETCH;
  }

  static std::optional<PrefetchOp> from(const ::mx::ir::Operation &that);
  static std::optional<PrefetchOp> producing(const ::mx::ir::Value &val);

  ::mlir::memref::PrefetchOp underlying_repr(void) const noexcept;

  // Imported methods:
  //::mlir::TypedValue<MemRefType> memref(void) const;
  //::mlir::Operation::operand_range indices(void) const;
  bool is_write(void) const;
  uint32_t locality_hint(void) const;
  bool is_data_cache(void) const;
  //MemRefType mem_ref_type(void) const;
  //StringRef locality_hint_attr_str_name(void) const;
  //StringRef is_write_attr_str_name(void) const;
  //StringRef is_data_cache_attr_str_name(void) const;
};
static_assert(sizeof(PrefetchOp) == sizeof(Operation));

class MX_EXPORT RankOp final : public Operation {
 public:
  inline static constexpr OperationKind static_kind(void) {
    return OperationKind::MEMREF_RANK;
  }

  static std::optional<RankOp> from(const ::mx::ir::Operation &that);
  static std::optional<RankOp> producing(const ::mx::ir::Value &val);

  ::mlir::memref::RankOp underlying_repr(void) const noexcept;

  // Imported methods:
  //::mlir::TypedValue<BaseMemRefType> memref(void) const;
};
static_assert(sizeof(RankOp) == sizeof(Operation));

class MX_EXPORT ReallocOp final : public Operation {
 public:
  inline static constexpr OperationKind static_kind(void) {
    return OperationKind::MEMREF_REALLOC;
  }

  static std::optional<ReallocOp> from(const ::mx::ir::Operation &that);
  static std::optional<ReallocOp> producing(const ::mx::ir::Value &val);

  ::mlir::memref::ReallocOp underlying_repr(void) const noexcept;

  // Imported methods:
  //::mlir::TypedValue<MemRefType> source(void) const;
  //::mlir::TypedValue<IndexType> dynamic_result_size(void) const;
  std::optional<unsigned long long> alignment(void) const;
  //MemRefType type(void) const;
};
static_assert(sizeof(ReallocOp) == sizeof(Operation));

class MX_EXPORT ReinterpretCastOp final : public Operation {
 public:
  inline static constexpr OperationKind static_kind(void) {
    return OperationKind::MEMREF_REINTERPRET_CAST;
  }

  static std::optional<ReinterpretCastOp> from(const ::mx::ir::Operation &that);
  static std::optional<ReinterpretCastOp> producing(const ::mx::ir::Value &val);

  ::mlir::memref::ReinterpretCastOp underlying_repr(void) const noexcept;

  // Imported methods:
  //::mlir::TypedValue<BaseMemRefType> source(void) const;
  //::mlir::Operation::operand_range offsets(void) const;
  //::mlir::Operation::operand_range sizes(void) const;
  //::mlir::Operation::operand_range strides(void) const;
  //::mlir::TypedValue<MemRefType> result(void) const;
  //::llvm::ArrayRef<long long> static_offsets(void) const;
  //::llvm::ArrayRef<long long> static_sizes(void) const;
  //::llvm::ArrayRef<long long> static_strides(void) const;
  //::mlir::Operation::operand_range dynamic_sizes(void) const;
  //MemRefType type(void) const;
  //Value view_source(void) const;
  unsigned int result_rank(void) const;
  //std::array<unsigned int, 3> array_attr_max_ranks(void) const;
  unsigned int offset_size_and_stride_start_operand_index(void) const;
  //SmallVector<OpFoldResult, 6> constified_mixed_sizes(void) const;
  //SmallVector<OpFoldResult, 6> constified_mixed_strides(void) const;
  //OpFoldResult constified_mixed_offset(void) const;
};
static_assert(sizeof(ReinterpretCastOp) == sizeof(Operation));

class MX_EXPORT ReshapeOp final : public Operation {
 public:
  inline static constexpr OperationKind static_kind(void) {
    return OperationKind::MEMREF_RESHAPE;
  }

  static std::optional<ReshapeOp> from(const ::mx::ir::Operation &that);
  static std::optional<ReshapeOp> producing(const ::mx::ir::Value &val);

  ::mlir::memref::ReshapeOp underlying_repr(void) const noexcept;

  // Imported methods:
  //::mlir::TypedValue<BaseMemRefType> source(void) const;
  //::mlir::TypedValue<MemRefType> shape(void) const;
  //::mlir::TypedValue<BaseMemRefType> result(void) const;
  //MemRefType type(void) const;
  //Value view_source(void) const;
};
static_assert(sizeof(ReshapeOp) == sizeof(Operation));

class MX_EXPORT StoreOp final : public Operation {
 public:
  inline static constexpr OperationKind static_kind(void) {
    return OperationKind::MEMREF_STORE;
  }

  static std::optional<StoreOp> from(const ::mx::ir::Operation &that);
  static std::optional<StoreOp> producing(const ::mx::ir::Value &val);

  ::mlir::memref::StoreOp underlying_repr(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value value(void) const;
  //::mlir::TypedValue<MemRefType> memref(void) const;
  //::mlir::Operation::operand_range indices(void) const;
  bool nontemporal(void) const;
  //Value value_to_store(void) const;
  //Value mem_ref(void) const;
  //MemRefType mem_ref_type(void) const;
};
static_assert(sizeof(StoreOp) == sizeof(Operation));

class MX_EXPORT TransposeOp final : public Operation {
 public:
  inline static constexpr OperationKind static_kind(void) {
    return OperationKind::MEMREF_TRANSPOSE;
  }

  static std::optional<TransposeOp> from(const ::mx::ir::Operation &that);
  static std::optional<TransposeOp> producing(const ::mx::ir::Value &val);

  ::mlir::memref::TransposeOp underlying_repr(void) const noexcept;

  // Imported methods:
  //::mlir::TypedValue<MemRefType> in(void) const;
  //::mlir::AffineMap permutation(void) const;
  //StringRef permutation_attr_str_name(void) const;
};
static_assert(sizeof(TransposeOp) == sizeof(Operation));

class MX_EXPORT ViewOp final : public Operation {
 public:
  inline static constexpr OperationKind static_kind(void) {
    return OperationKind::MEMREF_VIEW;
  }

  static std::optional<ViewOp> from(const ::mx::ir::Operation &that);
  static std::optional<ViewOp> producing(const ::mx::ir::Value &val);

  ::mlir::memref::ViewOp underlying_repr(void) const noexcept;

  // Imported methods:
  //::mlir::TypedValue<MemRefType> source(void) const;
  //::mlir::TypedValue<IndexType> byte_shift(void) const;
  //::mlir::Operation::operand_range sizes(void) const;
  ::mx::ir::Value view_source(void) const;
  //MemRefType type(void) const;
  //operand_range dynamic_sizes(void) const;
};
static_assert(sizeof(ViewOp) == sizeof(Operation));

class MX_EXPORT SubViewOp final : public Operation {
 public:
  inline static constexpr OperationKind static_kind(void) {
    return OperationKind::MEMREF_SUBVIEW;
  }

  static std::optional<SubViewOp> from(const ::mx::ir::Operation &that);
  static std::optional<SubViewOp> producing(const ::mx::ir::Value &val);

  ::mlir::memref::SubViewOp underlying_repr(void) const noexcept;

  // Imported methods:
  //::mlir::TypedValue<MemRefType> source(void) const;
  //::mlir::Operation::operand_range offsets(void) const;
  //::mlir::Operation::operand_range sizes(void) const;
  //::mlir::Operation::operand_range strides(void) const;
  //::mlir::TypedValue<MemRefType> result(void) const;
  //::llvm::ArrayRef<long long> static_offsets(void) const;
  //::llvm::ArrayRef<long long> static_sizes(void) const;
  //::llvm::ArrayRef<long long> static_strides(void) const;
  ::mx::ir::Value view_source(void) const;
  //::mlir::Operation::operand_range dynamic_sizes(void) const;
  //MemRefType source_type(void) const;
  //MemRefType type(void) const;
  //std::array<unsigned int, 3> array_attr_max_ranks(void) const;
  unsigned int offset_size_and_stride_start_operand_index(void) const;
  //llvm::SmallBitVector dropped_dims(void) const;
};
static_assert(sizeof(SubViewOp) == sizeof(Operation));

}  // namespace mx::ir::memref
