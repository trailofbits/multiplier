// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Operation.h"

namespace mlir::scf {
class ExecuteRegionOp;
}  // namespace mlir::scf
namespace mx::ir::scf {
class ExecuteRegionOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::SCF_EXECUTE_REGION;
  }

  static std::optional<ExecuteRegionOp> from(const ::mx::ir::Operation &that);
  static std::optional<ExecuteRegionOp> producing(const ::mx::ir::Value &val);

  ::mlir::scf::ExecuteRegionOp underlying_op(void) const noexcept;

  // Imported methods:
  ::mx::ir::Region region(void) const;
};
static_assert(sizeof(ExecuteRegionOp) == sizeof(Operation));

}  // namespace mx::ir::scf
