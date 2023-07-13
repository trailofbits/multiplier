// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Operation.h"

namespace vast::ll {
class CondScopeRet;
}  // namespace vast::ll
namespace mx::ir::ll {
class CondScopeRet final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LL_COND_SCOPE_RET;
  }

  static std::optional<CondScopeRet> from(const ::mx::ir::Operation &that);
  static std::optional<CondScopeRet> producing(const ::mx::ir::Value &val);

  ::vast::ll::CondScopeRet underlying_op(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value cond(void) const;
  //::mlir::mlir::Operation::operand_range dest_operands(void) const;
  //::mlir::Block* dest(void) const;
};
static_assert(sizeof(CondScopeRet) == sizeof(Operation));

}  // namespace mx::ir::ll
