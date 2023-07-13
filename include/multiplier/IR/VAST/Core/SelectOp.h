// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Operation.h"

namespace vast::core {
class SelectOp;
}  // namespace vast::core
namespace mx::ir::core {
class SelectOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::CORE_SELECT;
  }

  static std::optional<SelectOp> from(const ::mx::ir::Operation &that);
  static std::optional<SelectOp> producing(const ::mx::ir::Value &val);

  ::vast::core::SelectOp underlying_op(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value cond(void) const;
  ::mx::ir::Value then_region(void) const;
  ::mx::ir::Value else_region(void) const;
  //::mlir::mlir::Operation::result_range results(void) const;
};
static_assert(sizeof(SelectOp) == sizeof(Operation));

}  // namespace mx::ir::core
