// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Operation.h"

namespace mlir::memref {
class ReshapeOp;
}  // namespace mlir::memref
namespace mx::ir::memref {
class ReshapeOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::MEMREF_RESHAPE;
  }

  static std::optional<ReshapeOp> from(const ::mx::ir::Operation &that);
  static std::optional<ReshapeOp> producing(const ::mx::ir::Value &val);

  ::mlir::memref::ReshapeOp underlying_op(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value source(void) const;
  //::mlir::TypedValue<::mlir::MemRefType> shape(void) const;
  ::mx::ir::Value result(void) const;
  //MemRefType type(void) const;
  //Value view_source(void) const;
};
static_assert(sizeof(ReshapeOp) == sizeof(Operation));

}  // namespace mx::ir::memref
