// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Operation.h"

namespace vast::ll {
class Br;
}  // namespace vast::ll
namespace mx::ir::ll {
class Br final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LL_BR;
  }

  static std::optional<Br> from(const ::mx::ir::Operation &that);
  static std::optional<Br> producing(const ::mx::ir::Value &val);

  ::vast::ll::Br underlying_op(void) const noexcept;

  // Imported methods:
  gap::generator<::mx::ir::Operand> operands(void) const;
  //::mlir::Block* dest(void) const;
};
static_assert(sizeof(Br) == sizeof(Operation));

}  // namespace mx::ir::ll
