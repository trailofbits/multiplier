// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Operation.h"

namespace vast::ll {
class Concat;
}  // namespace vast::ll
namespace mx::ir::ll {
class Concat final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LL_CONCAT;
  }

  static std::optional<Concat> from(const ::mx::ir::Operation &that);
  static std::optional<Concat> producing(const ::mx::ir::Value &val);

  ::vast::ll::Concat underlying_op(void) const noexcept;

  // Imported methods:
  gap::generator<::mx::ir::Operand> args(void) const;
  ::mx::ir::Value result(void) const;
};
static_assert(sizeof(Concat) == sizeof(Operation));

}  // namespace mx::ir::ll
