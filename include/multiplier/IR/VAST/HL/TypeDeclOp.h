// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Operation.h"

namespace vast::hl {
class TypeDeclOp;
}  // namespace vast::hl
namespace mx::ir::hl {
class TypeDeclOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::HL_TYPE;
  }

  static std::optional<TypeDeclOp> from(const ::mx::ir::Operation &that);
  static std::optional<TypeDeclOp> producing(const ::mx::ir::Value &val);

  vast::hl::TypeDeclOp underlying_op(void) const noexcept;

  // Imported methods:
  std::string_view name(void) const;
};
static_assert(sizeof(TypeDeclOp) == sizeof(Operation));

}  // namespace mx::ir::hl
