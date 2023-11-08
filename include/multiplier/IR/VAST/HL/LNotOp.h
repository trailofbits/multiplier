// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Operation.h"

namespace vast::hl {
class LNotOp;
}  // namespace vast::hl
namespace mx::ir::hl {
class LNotOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::HL_LNOT;
  }

  static std::optional<LNotOp> from(const ::mx::ir::Operation &that);
  static std::optional<LNotOp> producing(const ::mx::ir::Value &val);

  ::vast::hl::LNotOp underlying_op(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value arg(void) const;
  ::mx::ir::Value res(void) const;
};
static_assert(sizeof(LNotOp) == sizeof(Operation));

}  // namespace mx::ir::hl
