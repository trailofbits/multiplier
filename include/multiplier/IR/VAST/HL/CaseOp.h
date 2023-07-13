// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Operation.h"

namespace vast::hl {
class CaseOp;
}  // namespace vast::hl
namespace mx::ir::hl {
class CaseOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::HL_CASE;
  }

  static std::optional<CaseOp> from(const ::mx::ir::Operation &that);
  static std::optional<CaseOp> producing(const ::mx::ir::Value &val);

  ::vast::hl::CaseOp underlying_op(void) const noexcept;

  // Imported methods:
  ::mx::ir::Region lhs(void) const;
  ::mx::ir::Region body(void) const;
};
static_assert(sizeof(CaseOp) == sizeof(Operation));

}  // namespace mx::ir::hl
