// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Operation.h"

namespace vast::abi {
class DirectOp;
}  // namespace vast::abi
namespace mx::ir::abi {
class DirectOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::ABI_DIRECT;
  }

  static std::optional<DirectOp> from(const ::mx::ir::Operation &that);
  static std::optional<DirectOp> producing(const ::mx::ir::Value &val);

  ::vast::abi::DirectOp underlying_op(void) const noexcept;

  // Imported methods:
  gap::generator<::mx::ir::Operand> value(void) const;
  gap::generator<::mx::ir::Result> result(void) const;
};
static_assert(sizeof(DirectOp) == sizeof(Operation));

}  // namespace mx::ir::abi
