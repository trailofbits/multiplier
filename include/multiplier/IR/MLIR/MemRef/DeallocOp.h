// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Operation.h"

namespace mlir::memref {
class DeallocOp;
}  // namespace mlir::memref
namespace mx::ir::memref {
class DeallocOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::MEMREF_DEALLOC;
  }

  static std::optional<DeallocOp> from(const ::mx::ir::Operation &that);
  static std::optional<DeallocOp> producing(const ::mx::ir::Value &val);

  ::mlir::memref::DeallocOp underlying_op(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value memref(void) const;
};
static_assert(sizeof(DeallocOp) == sizeof(Operation));

}  // namespace mx::ir::memref
