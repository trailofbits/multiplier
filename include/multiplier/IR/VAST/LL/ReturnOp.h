// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Operation.h"

namespace vast::ll {
class ReturnOp;
}  // namespace vast::ll
namespace mx::ir::ll {
class ReturnOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LL_RETURN;
  }

  static std::optional<ReturnOp> from(const ::mx::ir::Operation &that);
  static std::optional<ReturnOp> producing(const ::mx::ir::Value &val);

  ::vast::ll::ReturnOp underlying_op(void) const noexcept;

  // Imported methods:
  //::mlir::mlir::Operation::operand_range result(void) const;
};
static_assert(sizeof(ReturnOp) == sizeof(Operation));

}  // namespace mx::ir::ll
