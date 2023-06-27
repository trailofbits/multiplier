// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Operation.h"

namespace mlir::scf {
class ForOp;
}  // namespace mlir::scf
namespace mx::ir::scf {
class ForOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::SCF_FOR;
  }

  static std::optional<ForOp> from(const ::mx::ir::Operation &that);
  static std::optional<ForOp> producing(const ::mx::ir::Value &val);

  mlir::scf::ForOp underlying_op(void) const noexcept;

  // Imported methods:
  //::mlir::TypedValue<::mlir::IndexType> lower_bound(void) const;
  //::mlir::TypedValue<::mlir::IndexType> upper_bound(void) const;
  //::mlir::TypedValue<::mlir::IndexType> step(void) const;
  //::mlir::Operation::operand_range init_args(void) const;
  //::mlir::Operation::result_range results(void) const;
  ::mx::ir::Region region(void) const;
  ::mx::ir::Region loop_body(void) const;
  std::optional<::mx::ir::Value> single_induction_var(void) const;
  //::std::optional<::mlir::OpFoldResult> single_lower_bound(void) const;
  //::std::optional<::mlir::OpFoldResult> single_step(void) const;
  //::std::optional<::mlir::OpFoldResult> single_upper_bound(void) const;
  //Value induction_var(void) const;
  //Block::BlockArgListType region_iter_args(void) const;
  //Operation::operand_range iter_operands(void) const;
  //MutableArrayRef<OpOperand> iter_op_operands(void) const;
  //unsignedint num_induction_vars(void) const;
  //unsignedint num_region_iter_args(void) const;
  //unsignedint num_control_operands(void) const;
  bool has_iter_operands(void) const;
  //unsignedint num_iter_operands(void) const;
  //std::optional<APInt> constant_step(void) const;
  //Speculation::Speculatability speculatability(void) const;
};
static_assert(sizeof(ForOp) == sizeof(Operation));

}  // namespace mx::ir::scf
