// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Operation.h"

namespace vast::hl {
class DeclRefOp;
}  // namespace vast::hl
namespace mx::ir::hl {
class DeclRefOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::HL_REF;
  }

  static std::optional<DeclRefOp> from(const ::mx::ir::Operation &that);
  static std::optional<DeclRefOp> producing(const ::mx::ir::Value &val);

  ::vast::hl::DeclRefOp underlying_op(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value decl(void) const;
  ::mx::ir::Value result(void) const;
};
static_assert(sizeof(DeclRefOp) == sizeof(Operation));

}  // namespace mx::ir::hl
