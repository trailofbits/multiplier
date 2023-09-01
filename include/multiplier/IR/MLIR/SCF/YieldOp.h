// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Operation.h"

namespace mlir::scf {
class YieldOp;
}  // namespace mlir::scf
namespace mx::ir::scf {
class YieldOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::SCF_YIELD;
  }

  static std::optional<YieldOp> from(const ::mx::ir::Operation &that);
  static std::optional<YieldOp> producing(const ::mx::ir::Value &val);

  ::mlir::scf::YieldOp underlying_op(void) const noexcept;

  // Imported methods:
  gap::generator<::mx::ir::Operand> results(void) const;
};
static_assert(sizeof(YieldOp) == sizeof(Operation));

}  // namespace mx::ir::scf
