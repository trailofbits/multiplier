// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Operation.h"

namespace mlir::memref {
class AtomicYieldOp;
}  // namespace mlir::memref
namespace mx::ir::memref {
class AtomicYieldOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::MEMREF_ATOMIC_YIELD;
  }

  static std::optional<AtomicYieldOp> from(const ::mx::ir::Operation &that);
  static std::optional<AtomicYieldOp> producing(const ::mx::ir::Value &val);

  mlir::memref::AtomicYieldOp underlying_op(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value result(void) const;
};
static_assert(sizeof(AtomicYieldOp) == sizeof(Operation));

}  // namespace mx::ir::memref
