// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Operation.h"

namespace vast::abi {
class YieldOp;
}  // namespace vast::abi
namespace mx::ir::abi {
class YieldOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::ABI_YIELD;
  }

  static std::optional<YieldOp> from(const ::mx::ir::Operation &that);
  static std::optional<YieldOp> producing(const ::mx::ir::Value &val);

  ::vast::abi::YieldOp underlying_op(void) const noexcept;

  // Imported methods:
  gap::generator<::mx::ir::Operand> values(void) const;
  gap::generator<::mx::ir::Result> result(void) const;
};
static_assert(sizeof(YieldOp) == sizeof(Operation));

}  // namespace mx::ir::abi
