// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Operation.h"

namespace vast::hl {
class CallOp;
}  // namespace vast::hl
namespace mx::ir::hl {
class CallOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::HL_CALL;
  }

  static std::optional<CallOp> from(const ::mx::ir::Operation &that);
  static std::optional<CallOp> producing(const ::mx::ir::Value &val);

  ::vast::hl::CallOp underlying_op(void) const noexcept;

  // Imported methods:
  //::mlir::mlir::Operation::operand_range arg_operands(void) const;
  //::mlir::mlir::Operation::result_range results(void) const;
  std::string_view callee(void) const;
  //::mlir::CallInterfaceCallable callable_for_callee(void) const;
};
static_assert(sizeof(CallOp) == sizeof(Operation));

}  // namespace mx::ir::hl
