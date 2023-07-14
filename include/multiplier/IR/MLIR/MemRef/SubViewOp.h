// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Operation.h"

namespace mlir::memref {
class SubViewOp;
}  // namespace mlir::memref
namespace mx::ir::memref {
class SubViewOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::MEMREF_SUBVIEW;
  }

  static std::optional<SubViewOp> from(const ::mx::ir::Operation &that);
  static std::optional<SubViewOp> producing(const ::mx::ir::Value &val);

  ::mlir::memref::SubViewOp underlying_op(void) const noexcept;

  // Imported methods:
  //::mlir::TypedValue<::mlir::MemRefType> source(void) const;
  gap::generator<::mx::ir::Operand> offsets(void) const;
  gap::generator<::mx::ir::Operand> sizes(void) const;
  gap::generator<::mx::ir::Operand> strides(void) const;
  //::mlir::TypedValue<::mlir::MemRefType> result(void) const;
  //::llvm::ArrayRef<int64_t> static_offsets(void) const;
  //::llvm::ArrayRef<int64_t> static_sizes(void) const;
  //::llvm::ArrayRef<int64_t> static_strides(void) const;
  ::mx::ir::Value view_source(void) const;
  gap::generator<::mx::ir::Operand> dynamic_sizes(void) const;
  //MemRefType source_type(void) const;
  //MemRefType type(void) const;
  //std::array<unsignedint,3> array_attr_max_ranks(void) const;
  //unsignedint offset_size_and_stride_start_operand_index(void) const;
  //llvm::SmallBitVector dropped_dims(void) const;
};
static_assert(sizeof(SubViewOp) == sizeof(Operation));

}  // namespace mx::ir::memref
