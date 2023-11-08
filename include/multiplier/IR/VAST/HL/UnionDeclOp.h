// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Operation.h"

namespace vast::hl {
class UnionDeclOp;
}  // namespace vast::hl
namespace mx::ir::hl {
class UnionDeclOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::HL_UNION;
  }

  static std::optional<UnionDeclOp> from(const ::mx::ir::Operation &that);
  static std::optional<UnionDeclOp> producing(const ::mx::ir::Value &val);

  ::vast::hl::UnionDeclOp underlying_op(void) const noexcept;

  // Imported methods:
  ::mx::ir::Region fields(void) const;
  std::string_view name(void) const;
};
static_assert(sizeof(UnionDeclOp) == sizeof(Operation));

}  // namespace mx::ir::hl
