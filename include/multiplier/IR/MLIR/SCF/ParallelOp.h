// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Operation.h"

namespace mlir::scf {
class ParallelOp;
}  // namespace mlir::scf
namespace mx::ir::scf {
class ParallelOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::SCF_PARALLEL;
  }

  static std::optional<ParallelOp> from(const ::mx::ir::Operation &that);
  static std::optional<ParallelOp> producing(const ::mx::ir::Value &val);

  ::mlir::scf::ParallelOp underlying_op(void) const noexcept;

  // Imported methods:
  gap::generator<::mx::ir::Operand> lower_bound(void) const;
  gap::generator<::mx::ir::Operand> upper_bound(void) const;
  gap::generator<::mx::ir::Operand> step(void) const;
  gap::generator<::mx::ir::Operand> init_vals(void) const;
  gap::generator<::mx::ir::Result> results(void) const;
  ::mx::ir::Region region(void) const;
  ::mx::ir::Region loop_body(void) const;
  //ValueRange induction_vars(void) const;
  //unsignedint num_loops(void) const;
  //unsignedint num_reductions(void) const;
};
static_assert(sizeof(ParallelOp) == sizeof(Operation));

}  // namespace mx::ir::scf
