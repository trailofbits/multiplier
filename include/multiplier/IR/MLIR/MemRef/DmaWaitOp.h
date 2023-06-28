// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Operation.h"

namespace mlir::memref {
class DmaWaitOp;
}  // namespace mlir::memref
namespace mx::ir::memref {
class DmaWaitOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::MEMREF_DMA_WAIT;
  }

  static std::optional<DmaWaitOp> from(const ::mx::ir::Operation &that);
  static std::optional<DmaWaitOp> producing(const ::mx::ir::Value &val);

  mlir::memref::DmaWaitOp underlying_op(void) const noexcept;

  // Imported methods:
  //::mlir::TypedValue<::mlir::MemRefType> tag_mem_ref(void) const;
  //::mlir::Operation::operand_range tag_indices(void) const;
  //::mlir::TypedValue<::mlir::IndexType> num_elements(void) const;
  //unsignedint tag_mem_ref_rank(void) const;
};
static_assert(sizeof(DmaWaitOp) == sizeof(Operation));

}  // namespace mx::ir::memref