// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Operation.h"

namespace vast::hl {
class AlignOfTypeOp;
}  // namespace vast::hl
namespace mx::ir::hl {
class AlignOfTypeOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::HL_ALIGNOF_TYPE;
  }

  static std::optional<AlignOfTypeOp> from(const ::mx::ir::Operation &that);
  static std::optional<AlignOfTypeOp> producing(const ::mx::ir::Value &val);

  ::vast::hl::AlignOfTypeOp underlying_op(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value result(void) const;
  ::mx::ir::Type arg(void) const;
};
static_assert(sizeof(AlignOfTypeOp) == sizeof(Operation));

}  // namespace mx::ir::hl
