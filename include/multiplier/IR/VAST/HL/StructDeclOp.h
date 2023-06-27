// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Operation.h"

namespace vast::hl {
class StructDeclOp;
}  // namespace vast::hl
namespace mx::ir::hl {
class StructDeclOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::HL_STRUCT;
  }

  static std::optional<StructDeclOp> from(const ::mx::ir::Operation &that);
  static std::optional<StructDeclOp> producing(const ::mx::ir::Value &val);

  vast::hl::StructDeclOp underlying_op(void) const noexcept;

  // Imported methods:
  ::mx::ir::Region fields(void) const;
  std::string_view name(void) const;
};
static_assert(sizeof(StructDeclOp) == sizeof(Operation));

}  // namespace mx::ir::hl
