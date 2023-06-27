// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Operation.h"

namespace mlir::memref {
class TensorStoreOp;
}  // namespace mlir::memref
namespace mx::ir::memref {
class TensorStoreOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::MEMREF_TENSOR_STORE;
  }

  static std::optional<TensorStoreOp> from(const ::mx::ir::Operation &that);
  static std::optional<TensorStoreOp> producing(const ::mx::ir::Value &val);

  mlir::memref::TensorStoreOp underlying_op(void) const noexcept;

  // Imported methods:
  //::mlir::TypedValue<::mlir::TensorType> tensor(void) const;
  ::mx::ir::Value memref(void) const;
};
static_assert(sizeof(TensorStoreOp) == sizeof(Operation));

}  // namespace mx::ir::memref
