// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Operation.h"

namespace mlir::scf {
class IfOp;
}  // namespace mlir::scf
namespace mx::ir::scf {
class IfOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::SCF_IF;
  }

  static std::optional<IfOp> from(const ::mx::ir::Operation &that);
  static std::optional<IfOp> producing(const ::mx::ir::Value &val);

  mlir::scf::IfOp underlying_op(void) const noexcept;

  // Imported methods:
  //::mlir::TypedValue<::mlir::IntegerType> condition(void) const;
  //::mlir::Operation::result_range results(void) const;
  ::mx::ir::Region then_region(void) const;
  ::mx::ir::Region else_region(void) const;
  //Block* then_block(void) const;
  //YieldOp then_yield(void) const;
  //Block* else_block(void) const;
  //YieldOp else_yield(void) const;
};
static_assert(sizeof(IfOp) == sizeof(Operation));

}  // namespace mx::ir::scf
