// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Operation.h"

namespace mlir::LLVM {
class ShuffleVectorOp;
}  // namespace mlir::LLVM
namespace mx::ir::llvm {
class ShuffleVectorOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_SHUFFLEVECTOR;
  }

  static std::optional<ShuffleVectorOp> from(const ::mx::ir::Operation &that);
  static std::optional<ShuffleVectorOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::ShuffleVectorOp underlying_op(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value v1(void) const;
  ::mx::ir::Value v2(void) const;
  ::mx::ir::Value res(void) const;
  //::llvm::ArrayRef<int32_t> mask(void) const;
};
static_assert(sizeof(ShuffleVectorOp) == sizeof(Operation));

}  // namespace mx::ir::llvm
