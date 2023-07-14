// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Operation.h"

namespace vast::hl {
class IndirectCallOp;
}  // namespace vast::hl
namespace mx::ir::hl {
class IndirectCallOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::HL_INDIRECT_CALL;
  }

  static std::optional<IndirectCallOp> from(const ::mx::ir::Operation &that);
  static std::optional<IndirectCallOp> producing(const ::mx::ir::Value &val);

  ::vast::hl::IndirectCallOp underlying_op(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value callee(void) const;
  gap::generator<::mx::ir::Operand> arg_operands(void) const;
  gap::generator<::mx::ir::Result> results(void) const;
  //::mlir::CallInterfaceCallable callable_for_callee(void) const;
};
static_assert(sizeof(IndirectCallOp) == sizeof(Operation));

}  // namespace mx::ir::hl
