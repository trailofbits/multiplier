// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Operation.h"

namespace mlir::memref {
class AllocaScopeOp;
}  // namespace mlir::memref
namespace mx::ir::memref {
class AllocaScopeOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::MEMREF_ALLOCA_SCOPE;
  }

  static std::optional<AllocaScopeOp> from(const ::mx::ir::Operation &that);
  static std::optional<AllocaScopeOp> producing(const ::mx::ir::Value &val);

  ::mlir::memref::AllocaScopeOp underlying_op(void) const noexcept;

  // Imported methods:
  //::mlir::mlir::Operation::result_range results(void) const;
  ::mx::ir::Region body_region(void) const;
};
static_assert(sizeof(AllocaScopeOp) == sizeof(Operation));

}  // namespace mx::ir::memref
