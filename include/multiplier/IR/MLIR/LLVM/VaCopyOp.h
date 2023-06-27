// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Operation.h"

namespace mlir::LLVM {
class VaCopyOp;
}  // namespace mlir::LLVM
namespace mx::ir::llvm {
class VaCopyOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_VACOPY;
  }

  static std::optional<VaCopyOp> from(const ::mx::ir::Operation &that);
  static std::optional<VaCopyOp> producing(const ::mx::ir::Value &val);

  mlir::LLVM::VaCopyOp underlying_op(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value dest_list(void) const;
  ::mx::ir::Value src_list(void) const;
};
static_assert(sizeof(VaCopyOp) == sizeof(Operation));

}  // namespace mx::ir::llvm
