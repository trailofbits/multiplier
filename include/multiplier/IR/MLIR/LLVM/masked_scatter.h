// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Operation.h"

namespace mlir::LLVM {
class masked_scatter;
}  // namespace mlir::LLVM
namespace mx::ir::llvm {
class masked_scatter final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_MASKED_SCATTER;
  }

  static std::optional<masked_scatter> from(const ::mx::ir::Operation &that);
  static std::optional<masked_scatter> producing(const ::mx::ir::Value &val);

  mlir::LLVM::masked_scatter underlying_op(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value value(void) const;
  ::mx::ir::Value ptrs(void) const;
  ::mx::ir::Value mask(void) const;
  uint32_t alignment(void) const;
};
static_assert(sizeof(masked_scatter) == sizeof(Operation));

}  // namespace mx::ir::llvm
