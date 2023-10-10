// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Operation.h"

namespace mlir::memref {
class ExtractAlignedPointerAsIndexOp;
}  // namespace mlir::memref
namespace mx::ir::memref {
class ExtractAlignedPointerAsIndexOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::MEMREF_EXTRACT_ALIGNED_POINTER_AS_INDEX;
  }

  static std::optional<ExtractAlignedPointerAsIndexOp> from(const ::mx::ir::Operation &that);
  static std::optional<ExtractAlignedPointerAsIndexOp> producing(const ::mx::ir::Value &val);

  ::mlir::memref::ExtractAlignedPointerAsIndexOp underlying_op(void) const noexcept;

  // Imported methods:
  //::mlir::TypedValue<::mlir::MemRefType> source(void) const;
  //::mlir::TypedValue<::mlir::IndexType> aligned_pointer(void) const;
};
static_assert(sizeof(ExtractAlignedPointerAsIndexOp) == sizeof(Operation));

}  // namespace mx::ir::memref
