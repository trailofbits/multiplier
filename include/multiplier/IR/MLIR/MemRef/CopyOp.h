// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Operation.h"

namespace mlir::memref {
class CopyOp;
}  // namespace mlir::memref
namespace mx::ir::memref {
class CopyOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::MEMREF_COPY;
  }

  static std::optional<CopyOp> from(const ::mx::ir::Operation &that);
  static std::optional<CopyOp> producing(const ::mx::ir::Value &val);

  mlir::memref::CopyOp underlying_op(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value source(void) const;
  ::mx::ir::Value target(void) const;
};
static_assert(sizeof(CopyOp) == sizeof(Operation));

}  // namespace mx::ir::memref
