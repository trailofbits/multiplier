// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Operation.h"

namespace vast::ll {
class CondBr;
}  // namespace vast::ll
namespace mx::ir::ll {
class CondBr final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LL_COND_BR;
  }

  static std::optional<CondBr> from(const ::mx::ir::Operation &that);
  static std::optional<CondBr> producing(const ::mx::ir::Value &val);

  ::vast::ll::CondBr underlying_op(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value cond(void) const;
  //::mlir::mlir::Operation::operand_range true_operands(void) const;
  //::mlir::mlir::Operation::operand_range false_operands(void) const;
  //::mlir::Block* true_dest(void) const;
  //::mlir::Block* false_dest(void) const;
};
static_assert(sizeof(CondBr) == sizeof(Operation));

}  // namespace mx::ir::ll
