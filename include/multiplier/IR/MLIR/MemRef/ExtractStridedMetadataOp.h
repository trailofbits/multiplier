// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Operation.h"

namespace mlir::memref {
class ExtractStridedMetadataOp;
}  // namespace mlir::memref
namespace mx::ir::memref {
class ExtractStridedMetadataOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::MEMREF_EXTRACT_STRIDED_METADATA;
  }

  static std::optional<ExtractStridedMetadataOp> from(const ::mx::ir::Operation &that);
  static std::optional<ExtractStridedMetadataOp> producing(const ::mx::ir::Value &val);

  ::mlir::memref::ExtractStridedMetadataOp underlying_op(void) const noexcept;

  // Imported methods:
  //::mlir::TypedValue<::mlir::MemRefType> source(void) const;
  ::mx::ir::Value base_buffer(void) const;
  //::mlir::TypedValue<::mlir::IndexType> offset(void) const;
  gap::generator<::mx::ir::Result> sizes(void) const;
  gap::generator<::mx::ir::Result> strides(void) const;
  //SmallVector<OpFoldResult> constified_mixed_sizes(void) const;
  //SmallVector<OpFoldResult> constified_mixed_strides(void) const;
  //OpFoldResult constified_mixed_offset(void) const;
};
static_assert(sizeof(ExtractStridedMetadataOp) == sizeof(Operation));

}  // namespace mx::ir::memref
