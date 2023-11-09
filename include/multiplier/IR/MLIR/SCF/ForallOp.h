// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Operation.h"

namespace mlir::scf {
class ForallOp;
}  // namespace mlir::scf
namespace mx::ir::scf {
class ForallOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::SCF_FORALL;
  }

  static std::optional<ForallOp> from(const ::mx::ir::Operation &that);
  static std::optional<ForallOp> producing(const ::mx::ir::Value &val);

  ::mlir::scf::ForallOp underlying_op(void) const noexcept;

  // Imported methods:
  gap::generator<::mx::ir::Operand> dynamic_lower_bound(void) const;
  gap::generator<::mx::ir::Operand> dynamic_upper_bound(void) const;
  gap::generator<::mx::ir::Operand> dynamic_step(void) const;
  gap::generator<::mx::ir::Operand> outputs(void) const;
  gap::generator<::mx::ir::Result> results(void) const;
  ::mx::ir::Region region(void) const;
  //::llvm::ArrayRef<int64_t> static_lower_bound(void) const;
  //::llvm::ArrayRef<int64_t> static_upper_bound(void) const;
  //::llvm::ArrayRef<int64_t> static_step(void) const;
  //::std::optional<::mlir::ArrayAttr> mapping(void) const;
  ::mx::ir::Region loop_body(void) const;
  //SmallVector<OpFoldResult> mixed_lower_bound(void) const;
  //SmallVector<OpFoldResult> mixed_upper_bound(void) const;
  //SmallVector<OpFoldResult> mixed_step(void) const;
  int64_t rank(void) const;
  //unsignedint num_control_operands(void) const;
  //unsignedint num_dynamic_control_operands(void) const;
  //ArrayRef<BlockArgument> output_block_arguments(void) const;
  //::mlir::ValueRange induction_vars(void) const;
  //::mlir::mlir::Block::BlockArgListType region_out_args(void) const;
  bool is_normalized(void) const;
  //InParallelOp terminator(void) const;
};
static_assert(sizeof(ForallOp) == sizeof(Operation));

}  // namespace mx::ir::scf
