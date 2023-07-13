// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Operation.h"

namespace mlir::LLVM {
class masked_compressstore;
}  // namespace mlir::LLVM
namespace mx::ir::llvm {
class masked_compressstore final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_MASKED_COMPRESSSTORE;
  }

  static std::optional<masked_compressstore> from(const ::mx::ir::Operation &that);
  static std::optional<masked_compressstore> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::masked_compressstore underlying_op(void) const noexcept;

  // Imported methods:
};
static_assert(sizeof(masked_compressstore) == sizeof(Operation));

}  // namespace mx::ir::llvm
