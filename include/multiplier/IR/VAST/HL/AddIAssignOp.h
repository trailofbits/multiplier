// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Operation.h"

namespace vast::hl {
class AddIAssignOp;
}  // namespace vast::hl
namespace mx::ir::hl {
class AddIAssignOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::HL_ASSIGN_ADD;
  }

  static std::optional<AddIAssignOp> from(const ::mx::ir::Operation &that);
  static std::optional<AddIAssignOp> producing(const ::mx::ir::Value &val);

  ::vast::hl::AddIAssignOp underlying_op(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value src(void) const;
  ::mx::ir::Value dst(void) const;
  ::mx::ir::Value result(void) const;
};
static_assert(sizeof(AddIAssignOp) == sizeof(Operation));

}  // namespace mx::ir::hl
