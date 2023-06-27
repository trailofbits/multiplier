// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Operation.h"

namespace vast::hl {
class RecordMemberOp;
}  // namespace vast::hl
namespace mx::ir::hl {
class RecordMemberOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::HL_MEMBER;
  }

  static std::optional<RecordMemberOp> from(const ::mx::ir::Operation &that);
  static std::optional<RecordMemberOp> producing(const ::mx::ir::Value &val);

  vast::hl::RecordMemberOp underlying_op(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value record(void) const;
  ::mx::ir::Value element(void) const;
  std::string_view name(void) const;
};
static_assert(sizeof(RecordMemberOp) == sizeof(Operation));

}  // namespace mx::ir::hl
