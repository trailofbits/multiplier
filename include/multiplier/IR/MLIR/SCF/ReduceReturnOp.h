// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Operation.h"

namespace mlir::scf {
class ReduceReturnOp;
}  // namespace mlir::scf
namespace mx::ir::scf {
class ReduceReturnOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::SCF_REDUCE_RETURN;
  }

  static std::optional<ReduceReturnOp> from(const ::mx::ir::Operation &that);
  static std::optional<ReduceReturnOp> producing(const ::mx::ir::Value &val);

  mlir::scf::ReduceReturnOp underlying_op(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value result(void) const;
};
static_assert(sizeof(ReduceReturnOp) == sizeof(Operation));

}  // namespace mx::ir::scf
