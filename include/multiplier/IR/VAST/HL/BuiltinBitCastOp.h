// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Operation.h"

namespace vast::hl {
class BuiltinBitCastOp;
}  // namespace vast::hl
namespace mx::ir::hl {
class BuiltinBitCastOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::HL_BUILTIN_BITCAST;
  }

  static std::optional<BuiltinBitCastOp> from(const ::mx::ir::Operation &that);
  static std::optional<BuiltinBitCastOp> producing(const ::mx::ir::Value &val);

  ::vast::hl::BuiltinBitCastOp underlying_op(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value value(void) const;
  ::mx::ir::Value result(void) const;
  //::vast::hl::CastKind kind(void) const;
};
static_assert(sizeof(BuiltinBitCastOp) == sizeof(Operation));

}  // namespace mx::ir::hl
