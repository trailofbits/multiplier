// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Operation.h"

namespace vast::ll {
class Extract;
}  // namespace vast::ll
namespace mx::ir::ll {
class Extract final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LL_EXTRACT;
  }

  static std::optional<Extract> from(const ::mx::ir::Operation &that);
  static std::optional<Extract> producing(const ::mx::ir::Value &val);

  ::vast::ll::Extract underlying_op(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value arg(void) const;
  ::mx::ir::Value result(void) const;
  //::mlir::TypedAttr from(void) const;
  //::mlir::TypedAttr to(void) const;
};
static_assert(sizeof(Extract) == sizeof(Operation));

}  // namespace mx::ir::ll
