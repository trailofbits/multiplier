// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Operation.h"

namespace vast::ll {
class UninitializedVar;
}  // namespace vast::ll
namespace mx::ir::ll {
class UninitializedVar final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LL_UNINITIALIZED_VAR;
  }

  static std::optional<UninitializedVar> from(const ::mx::ir::Operation &that);
  static std::optional<UninitializedVar> producing(const ::mx::ir::Value &val);

  ::vast::ll::UninitializedVar underlying_op(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value result(void) const;
};
static_assert(sizeof(UninitializedVar) == sizeof(Operation));

}  // namespace mx::ir::ll
