// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Operation.h"

namespace vast::hl {
class UnsupportedDeclOp;
}  // namespace vast::hl
namespace mx::ir::hl {
class UnsupportedDeclOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::HL_UNSUPPORTEDDECL;
  }

  static std::optional<UnsupportedDeclOp> from(const ::mx::ir::Operation &that);
  static std::optional<UnsupportedDeclOp> producing(const ::mx::ir::Value &val);

  ::vast::hl::UnsupportedDeclOp underlying_op(void) const noexcept;

  // Imported methods:
  gap::generator<::mx::ir::Operand> elements(void) const;
  std::string_view name(void) const;
};
static_assert(sizeof(UnsupportedDeclOp) == sizeof(Operation));

}  // namespace mx::ir::hl
