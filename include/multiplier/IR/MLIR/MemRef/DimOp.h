// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Operation.h"

namespace mlir::memref {
class DimOp;
}  // namespace mlir::memref
namespace mx::ir::memref {
class DimOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::MEMREF_DIM;
  }

  static std::optional<DimOp> from(const ::mx::ir::Operation &that);
  static std::optional<DimOp> producing(const ::mx::ir::Value &val);

  mlir::memref::DimOp underlying_op(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value source(void) const;
  //::mlir::TypedValue<::mlir::IndexType> index(void) const;
  //::mlir::TypedValue<::mlir::IndexType> result(void) const;
  //std::optional<int64_t> constant_index(void) const;
  //Value shaped_value(void) const;
  //OpFoldResult dimension(void) const;
  //Speculation::Speculatability speculatability(void) const;
};
static_assert(sizeof(DimOp) == sizeof(Operation));

}  // namespace mx::ir::memref
