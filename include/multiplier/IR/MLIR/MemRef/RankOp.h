// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Operation.h"

namespace mlir::memref {
class RankOp;
}  // namespace mlir::memref
namespace mx::ir::memref {
class RankOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::MEMREF_RANK;
  }

  static std::optional<RankOp> from(const ::mx::ir::Operation &that);
  static std::optional<RankOp> producing(const ::mx::ir::Value &val);

  ::mlir::memref::RankOp underlying_op(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value memref(void) const;
};
static_assert(sizeof(RankOp) == sizeof(Operation));

}  // namespace mx::ir::memref
