// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Operation.h"

namespace mlir::memref {
class CastOp;
}  // namespace mlir::memref
namespace mx::ir::memref {
class CastOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::MEMREF_CAST;
  }

  static std::optional<CastOp> from(const ::mx::ir::Operation &that);
  static std::optional<CastOp> producing(const ::mx::ir::Value &val);

  ::mlir::memref::CastOp underlying_op(void) const noexcept;

  // Imported methods:
  //::mlir::TypedValue<::mlir::BaseMemRefType> source(void) const;
  //::mlir::TypedValue<::mlir::BaseMemRefType> dest(void) const;
  //Value view_source(void) const;
};
static_assert(sizeof(CastOp) == sizeof(Operation));

}  // namespace mx::ir::memref
