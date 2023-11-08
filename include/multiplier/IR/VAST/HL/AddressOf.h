// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Operation.h"

namespace vast::hl {
class AddressOf;
}  // namespace vast::hl
namespace mx::ir::hl {
class AddressOf final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::HL_ADDRESSOF;
  }

  static std::optional<AddressOf> from(const ::mx::ir::Operation &that);
  static std::optional<AddressOf> producing(const ::mx::ir::Value &val);

  ::vast::hl::AddressOf underlying_op(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value value(void) const;
  ::mx::ir::Value result(void) const;
};
static_assert(sizeof(AddressOf) == sizeof(Operation));

}  // namespace mx::ir::hl
