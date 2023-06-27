// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Operation.h"

namespace vast::hl {
class BinLAndOp;
}  // namespace vast::hl
namespace mx::ir::hl {
class BinLAndOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::HL_BIN_LAND;
  }

  static std::optional<BinLAndOp> from(const ::mx::ir::Operation &that);
  static std::optional<BinLAndOp> producing(const ::mx::ir::Value &val);

  vast::hl::BinLAndOp underlying_op(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value result(void) const;
  ::mx::ir::Region lhs(void) const;
  ::mx::ir::Region rhs(void) const;
};
static_assert(sizeof(BinLAndOp) == sizeof(Operation));

}  // namespace mx::ir::hl
