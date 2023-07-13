// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Operation.h"

namespace mlir::memref {
class DmaStartOp;
}  // namespace mlir::memref
namespace mx::ir::memref {
class DmaStartOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::MEMREF_DMA_START;
  }

  static std::optional<DmaStartOp> from(const ::mx::ir::Operation &that);
  static std::optional<DmaStartOp> producing(const ::mx::ir::Value &val);

  ::mlir::memref::DmaStartOp underlying_op(void) const noexcept;

  // Imported methods:
  //::mlir::mlir::Operation::operand_range operands(void) const;
  //Value src_mem_ref(void) const;
  //unsignedint src_mem_ref_rank(void) const;
  //operand_range src_indices(void) const;
  //Value dst_mem_ref(void) const;
  //unsignedint dst_mem_ref_rank(void) const;
  //unsignedint src_memory_space(void) const;
  //unsignedint dst_memory_space(void) const;
  //operand_range dst_indices(void) const;
  //Value num_elements(void) const;
  //Value tag_mem_ref(void) const;
  //unsignedint tag_mem_ref_rank(void) const;
  //operand_range tag_indices(void) const;
  bool is_dest_memory_space_faster(void) const;
  bool is_src_memory_space_faster(void) const;
  //unsignedint faster_mem_pos(void) const;
  bool is_strided(void) const;
  //Value stride(void) const;
  //Value num_elements_per_stride(void) const;
};
static_assert(sizeof(DmaStartOp) == sizeof(Operation));

}  // namespace mx::ir::memref
