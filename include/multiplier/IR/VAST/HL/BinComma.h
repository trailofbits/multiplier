// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Operation.h"

namespace vast::hl {
class BinComma;
}  // namespace vast::hl
namespace mx::ir::hl {
class BinComma final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::HL_BIN_COMMA;
  }

  static std::optional<BinComma> from(const ::mx::ir::Operation &that);
  static std::optional<BinComma> producing(const ::mx::ir::Value &val);

  ::vast::hl::BinComma underlying_op(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value lhs(void) const;
  ::mx::ir::Value rhs(void) const;
  ::mx::ir::Value result(void) const;
};
static_assert(sizeof(BinComma) == sizeof(Operation));

}  // namespace mx::ir::hl
