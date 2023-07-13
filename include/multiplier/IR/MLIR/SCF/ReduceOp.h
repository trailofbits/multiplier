// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Operation.h"

namespace mlir::scf {
class ReduceOp;
}  // namespace mlir::scf
namespace mx::ir::scf {
class ReduceOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::SCF_REDUCE;
  }

  static std::optional<ReduceOp> from(const ::mx::ir::Operation &that);
  static std::optional<ReduceOp> producing(const ::mx::ir::Value &val);

  ::mlir::scf::ReduceOp underlying_op(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value operand(void) const;
  ::mx::ir::Region reduction_operator(void) const;
};
static_assert(sizeof(ReduceOp) == sizeof(Operation));

}  // namespace mx::ir::scf
