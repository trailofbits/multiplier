// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Operation.h"

namespace vast::ll {
class InitializeVar;
}  // namespace vast::ll
namespace mx::ir::ll {
class InitializeVar final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LL_INITIALIZE;
  }

  static std::optional<InitializeVar> from(const ::mx::ir::Operation &that);
  static std::optional<InitializeVar> producing(const ::mx::ir::Value &val);

  vast::ll::InitializeVar underlying_op(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value var(void) const;
  //::mlir::Operation::operand_range elements(void) const;
  ::mx::ir::Value result(void) const;
};
static_assert(sizeof(InitializeVar) == sizeof(Operation));

}  // namespace mx::ir::ll
