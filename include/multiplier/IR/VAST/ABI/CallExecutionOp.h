// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Operation.h"

namespace vast::abi {
class CallExecutionOp;
}  // namespace vast::abi
namespace mx::ir::abi {
class CallExecutionOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::ABI_CALL_EXEC;
  }

  static std::optional<CallExecutionOp> from(const ::mx::ir::Operation &that);
  static std::optional<CallExecutionOp> producing(const ::mx::ir::Value &val);

  ::vast::abi::CallExecutionOp underlying_op(void) const noexcept;

  // Imported methods:
  gap::generator<::mx::ir::Operand> args(void) const;
  ::mx::ir::Value result(void) const;
  ::mx::ir::Region body(void) const;
  std::string_view callee(void) const;
  //::mlir::CallInterfaceCallable callable_for_callee(void) const;
  gap::generator<::mx::ir::Operand> arg_operands(void) const;
};
static_assert(sizeof(CallExecutionOp) == sizeof(Operation));

}  // namespace mx::ir::abi
