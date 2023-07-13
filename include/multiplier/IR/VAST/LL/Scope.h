// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Operation.h"

namespace vast::ll {
class Scope;
}  // namespace vast::ll
namespace mx::ir::ll {
class Scope final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LL_SCOPE;
  }

  static std::optional<Scope> from(const ::mx::ir::Operation &that);
  static std::optional<Scope> producing(const ::mx::ir::Value &val);

  ::vast::ll::Scope underlying_op(void) const noexcept;

  // Imported methods:
  ::mx::ir::Region body(void) const;
  //mlir::Block* start__block(void) const;
};
static_assert(sizeof(Scope) == sizeof(Operation));

}  // namespace mx::ir::ll
