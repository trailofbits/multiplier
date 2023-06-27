// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Operation.h"

namespace mlir::memref {
class TransposeOp;
}  // namespace mlir::memref
namespace mx::ir::memref {
class TransposeOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::MEMREF_TRANSPOSE;
  }

  static std::optional<TransposeOp> from(const ::mx::ir::Operation &that);
  static std::optional<TransposeOp> producing(const ::mx::ir::Value &val);

  mlir::memref::TransposeOp underlying_op(void) const noexcept;

  // Imported methods:
  //::mlir::TypedValue<::mlir::MemRefType> in(void) const;
  //::mlir::AffineMap permutation(void) const;
  //StringRef permutation_attr_str_name(void) const;
  //ShapedType shaped_type(void) const;
};
static_assert(sizeof(TransposeOp) == sizeof(Operation));

}  // namespace mx::ir::memref
