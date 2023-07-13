// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Operation.h"

namespace vast::hl {
class EnumDeclOp;
}  // namespace vast::hl
namespace mx::ir::hl {
class EnumDeclOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::HL_ENUM;
  }

  static std::optional<EnumDeclOp> from(const ::mx::ir::Operation &that);
  static std::optional<EnumDeclOp> producing(const ::mx::ir::Value &val);

  ::vast::hl::EnumDeclOp underlying_op(void) const noexcept;

  // Imported methods:
  ::mx::ir::Region constants(void) const;
  std::string_view name(void) const;
  ::mx::ir::Type type(void) const;
};
static_assert(sizeof(EnumDeclOp) == sizeof(Operation));

}  // namespace mx::ir::hl
