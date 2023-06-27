// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Operation.h"

namespace mlir::memref {
class AssumeAlignmentOp;
}  // namespace mlir::memref
namespace mx::ir::memref {
class AssumeAlignmentOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::MEMREF_ASSUME_ALIGNMENT;
  }

  static std::optional<AssumeAlignmentOp> from(const ::mx::ir::Operation &that);
  static std::optional<AssumeAlignmentOp> producing(const ::mx::ir::Value &val);

  mlir::memref::AssumeAlignmentOp underlying_op(void) const noexcept;

  // Imported methods:
  //::mlir::TypedValue<::mlir::MemRefType> memref(void) const;
  uint32_t alignment(void) const;
};
static_assert(sizeof(AssumeAlignmentOp) == sizeof(Operation));

}  // namespace mx::ir::memref
