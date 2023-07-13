// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Operation.h"

namespace mlir::memref {
class ReinterpretCastOp;
}  // namespace mlir::memref
namespace mx::ir::memref {
class ReinterpretCastOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::MEMREF_REINTERPRET_CAST;
  }

  static std::optional<ReinterpretCastOp> from(const ::mx::ir::Operation &that);
  static std::optional<ReinterpretCastOp> producing(const ::mx::ir::Value &val);

  ::mlir::memref::ReinterpretCastOp underlying_op(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value source(void) const;
  //::mlir::mlir::Operation::operand_range offsets(void) const;
  //::mlir::mlir::Operation::operand_range sizes(void) const;
  //::mlir::mlir::Operation::operand_range strides(void) const;
  //::mlir::TypedValue<::mlir::MemRefType> result(void) const;
  //::llvm::ArrayRef<int64_t> static_offsets(void) const;
  //::llvm::ArrayRef<int64_t> static_sizes(void) const;
  //::llvm::ArrayRef<int64_t> static_strides(void) const;
  //::mlir::mlir::Operation::operand_range dynamic_sizes(void) const;
  //MemRefType type(void) const;
  //Value view_source(void) const;
  //unsignedint result_rank(void) const;
  //std::array<unsignedint,3> array_attr_max_ranks(void) const;
  //unsignedint offset_size_and_stride_start_operand_index(void) const;
  //SmallVector<OpFoldResult> constified_mixed_sizes(void) const;
  //SmallVector<OpFoldResult> constified_mixed_strides(void) const;
  //OpFoldResult constified_mixed_offset(void) const;
};
static_assert(sizeof(ReinterpretCastOp) == sizeof(Operation));

}  // namespace mx::ir::memref
