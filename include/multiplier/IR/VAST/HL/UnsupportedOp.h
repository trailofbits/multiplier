// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Operation.h"

namespace vast::hl {
class UnsupportedOp;
}  // namespace vast::hl
namespace mx::ir::hl {
class UnsupportedOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::HL_UNSUPPORTEDOP;
  }

  static std::optional<UnsupportedOp> from(const ::mx::ir::Operation &that);
  static std::optional<UnsupportedOp> producing(const ::mx::ir::Value &val);

  ::vast::hl::UnsupportedOp underlying_op(void) const noexcept;

  // Imported methods:
  gap::generator<::mx::ir::Operand> elements(void) const;
  ::mx::ir::Value result(void) const;
  std::string_view name(void) const;
};
static_assert(sizeof(UnsupportedOp) == sizeof(Operation));

}  // namespace mx::ir::hl
