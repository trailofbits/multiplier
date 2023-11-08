// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Operation.h"

namespace mlir::LLVM {
class vector_reduce_smin;
}  // namespace mlir::LLVM
namespace mx::ir::llvm {
class vector_reduce_smin final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_VECTOR_REDUCE_SMIN;
  }

  static std::optional<vector_reduce_smin> from(const ::mx::ir::Operation &that);
  static std::optional<vector_reduce_smin> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::vector_reduce_smin underlying_op(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value res(void) const;
};
static_assert(sizeof(vector_reduce_smin) == sizeof(Operation));

}  // namespace mx::ir::llvm
