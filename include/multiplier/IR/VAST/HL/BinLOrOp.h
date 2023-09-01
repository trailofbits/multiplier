// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Operation.h"

namespace vast::hl {
class BinLOrOp;
}  // namespace vast::hl
namespace mx::ir::hl {
class BinLOrOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::HL_BIN_LOR;
  }

  static std::optional<BinLOrOp> from(const ::mx::ir::Operation &that);
  static std::optional<BinLOrOp> producing(const ::mx::ir::Value &val);

  ::vast::hl::BinLOrOp underlying_op(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value result(void) const;
  ::mx::ir::Region lhs(void) const;
  ::mx::ir::Region rhs(void) const;
};
static_assert(sizeof(BinLOrOp) == sizeof(Operation));

}  // namespace mx::ir::hl
