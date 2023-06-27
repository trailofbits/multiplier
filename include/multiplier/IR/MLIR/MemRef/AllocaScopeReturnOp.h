// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Operation.h"

namespace mlir::memref {
class AllocaScopeReturnOp;
}  // namespace mlir::memref
namespace mx::ir::memref {
class AllocaScopeReturnOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::MEMREF_ALLOCA_SCOPE_RETURN;
  }

  static std::optional<AllocaScopeReturnOp> from(const ::mx::ir::Operation &that);
  static std::optional<AllocaScopeReturnOp> producing(const ::mx::ir::Value &val);

  mlir::memref::AllocaScopeReturnOp underlying_op(void) const noexcept;

  // Imported methods:
  //::mlir::Operation::operand_range results(void) const;
};
static_assert(sizeof(AllocaScopeReturnOp) == sizeof(Operation));

}  // namespace mx::ir::memref
