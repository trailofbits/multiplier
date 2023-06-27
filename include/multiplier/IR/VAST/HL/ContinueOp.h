// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Operation.h"

namespace vast::hl {
class ContinueOp;
}  // namespace vast::hl
namespace mx::ir::hl {
class ContinueOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::HL_CONTINUE;
  }

  static std::optional<ContinueOp> from(const ::mx::ir::Operation &that);
  static std::optional<ContinueOp> producing(const ::mx::ir::Value &val);

  vast::hl::ContinueOp underlying_op(void) const noexcept;

  // Imported methods:
};
static_assert(sizeof(ContinueOp) == sizeof(Operation));

}  // namespace mx::ir::hl
