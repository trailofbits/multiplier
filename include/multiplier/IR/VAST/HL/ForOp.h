// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Operation.h"

namespace vast::hl {
class ForOp;
}  // namespace vast::hl
namespace mx::ir::hl {
class ForOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::HL_FOR;
  }

  static std::optional<ForOp> from(const ::mx::ir::Operation &that);
  static std::optional<ForOp> producing(const ::mx::ir::Value &val);

  ::vast::hl::ForOp underlying_op(void) const noexcept;

  // Imported methods:
  ::mx::ir::Region cond_region(void) const;
  ::mx::ir::Region incr_region(void) const;
  ::mx::ir::Region body_region(void) const;
};
static_assert(sizeof(ForOp) == sizeof(Operation));

}  // namespace mx::ir::hl
