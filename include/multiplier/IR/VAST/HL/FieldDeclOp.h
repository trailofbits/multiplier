// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Operation.h"

namespace vast::hl {
class FieldDeclOp;
}  // namespace vast::hl
namespace mx::ir::hl {
class FieldDeclOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::HL_FIELD;
  }

  static std::optional<FieldDeclOp> from(const ::mx::ir::Operation &that);
  static std::optional<FieldDeclOp> producing(const ::mx::ir::Value &val);

  vast::hl::FieldDeclOp underlying_op(void) const noexcept;

  // Imported methods:
  std::string_view name(void) const;
  ::mx::ir::Type type(void) const;
  std::optional<uint32_t> bits(void) const;
};
static_assert(sizeof(FieldDeclOp) == sizeof(Operation));

}  // namespace mx::ir::hl
