// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Operation.h"

namespace vast::core {
class LazyOp;
}  // namespace vast::core
namespace mx::ir::core {
class LazyOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::CORE_LAZY_OP;
  }

  static std::optional<LazyOp> from(const ::mx::ir::Operation &that);
  static std::optional<LazyOp> producing(const ::mx::ir::Value &val);

  vast::core::LazyOp underlying_op(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value result(void) const;
  ::mx::ir::Region lazy(void) const;
};
static_assert(sizeof(LazyOp) == sizeof(Operation));

}  // namespace mx::ir::core
