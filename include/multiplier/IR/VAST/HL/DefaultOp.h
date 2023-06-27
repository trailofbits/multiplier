// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Operation.h"

namespace vast::hl {
class DefaultOp;
}  // namespace vast::hl
namespace mx::ir::hl {
class DefaultOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::HL_DEFAULT;
  }

  static std::optional<DefaultOp> from(const ::mx::ir::Operation &that);
  static std::optional<DefaultOp> producing(const ::mx::ir::Value &val);

  vast::hl::DefaultOp underlying_op(void) const noexcept;

  // Imported methods:
  ::mx::ir::Region body(void) const;
};
static_assert(sizeof(DefaultOp) == sizeof(Operation));

}  // namespace mx::ir::hl
