// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Operation.h"

namespace vast::hl {
class PostDecOp;
}  // namespace vast::hl
namespace mx::ir::hl {
class PostDecOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::HL_POST_DEC;
  }

  static std::optional<PostDecOp> from(const ::mx::ir::Operation &that);
  static std::optional<PostDecOp> producing(const ::mx::ir::Value &val);

  vast::hl::PostDecOp underlying_op(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value arg(void) const;
  ::mx::ir::Value result(void) const;
};
static_assert(sizeof(PostDecOp) == sizeof(Operation));

}  // namespace mx::ir::hl
