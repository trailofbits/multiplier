// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Operation.h"

namespace mlir::scf {
class WhileOp;
}  // namespace mlir::scf
namespace mx::ir::scf {
class WhileOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::SCF_WHILE;
  }

  static std::optional<WhileOp> from(const ::mx::ir::Operation &that);
  static std::optional<WhileOp> producing(const ::mx::ir::Value &val);

  ::mlir::scf::WhileOp underlying_op(void) const noexcept;

  // Imported methods:
  //::mlir::mlir::Operation::operand_range inits(void) const;
  //::mlir::mlir::Operation::result_range results(void) const;
  ::mx::ir::Region before(void) const;
  ::mx::ir::Region after(void) const;
  //ConditionOp condition_op(void) const;
  //YieldOp yield_op(void) const;
  //mlir::Block::BlockArgListType before_arguments(void) const;
  //mlir::Block::BlockArgListType after_arguments(void) const;
};
static_assert(sizeof(WhileOp) == sizeof(Operation));

}  // namespace mx::ir::scf
