// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Operation.h"

namespace vast::core {
class ImplicitReturnOp;
}  // namespace vast::core
namespace mx::ir::core {
class ImplicitReturnOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::CORE_IMPLICIT_RETURN;
  }

  static std::optional<ImplicitReturnOp> from(const ::mx::ir::Operation &that);
  static std::optional<ImplicitReturnOp> producing(const ::mx::ir::Value &val);

  ::vast::core::ImplicitReturnOp underlying_op(void) const noexcept;

  // Imported methods:
  gap::generator<::mx::ir::Operand> result(void) const;
};
static_assert(sizeof(ImplicitReturnOp) == sizeof(Operation));

}  // namespace mx::ir::core
