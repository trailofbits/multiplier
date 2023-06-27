// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Operation.h"

namespace mlir::scf {
class ConditionOp;
}  // namespace mlir::scf
namespace mx::ir::scf {
class ConditionOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::SCF_CONDITION;
  }

  static std::optional<ConditionOp> from(const ::mx::ir::Operation &that);
  static std::optional<ConditionOp> producing(const ::mx::ir::Value &val);

  mlir::scf::ConditionOp underlying_op(void) const noexcept;

  // Imported methods:
  //::mlir::TypedValue<::mlir::IntegerType> condition(void) const;
  //::mlir::Operation::operand_range args(void) const;
};
static_assert(sizeof(ConditionOp) == sizeof(Operation));

}  // namespace mx::ir::scf
