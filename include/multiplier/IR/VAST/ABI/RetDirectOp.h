// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Operation.h"

namespace vast::abi {
class RetDirectOp;
}  // namespace vast::abi
namespace mx::ir::abi {
class RetDirectOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::ABI_RET_DIRECT;
  }

  static std::optional<RetDirectOp> from(const ::mx::ir::Operation &that);
  static std::optional<RetDirectOp> producing(const ::mx::ir::Value &val);

  ::vast::abi::RetDirectOp underlying_op(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value value(void) const;
  gap::generator<::mx::ir::Result> result(void) const;
};
static_assert(sizeof(RetDirectOp) == sizeof(Operation));

}  // namespace mx::ir::abi
