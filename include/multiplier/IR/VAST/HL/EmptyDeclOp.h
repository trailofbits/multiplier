// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Operation.h"

namespace vast::hl {
class EmptyDeclOp;
}  // namespace vast::hl
namespace mx::ir::hl {
class EmptyDeclOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::HL_EMPTY_DECL;
  }

  static std::optional<EmptyDeclOp> from(const ::mx::ir::Operation &that);
  static std::optional<EmptyDeclOp> producing(const ::mx::ir::Value &val);

  ::vast::hl::EmptyDeclOp underlying_op(void) const noexcept;

  // Imported methods:
};
static_assert(sizeof(EmptyDeclOp) == sizeof(Operation));

}  // namespace mx::ir::hl
