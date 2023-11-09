// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Operation.h"

namespace mlir::LLVM {
class NearbyintOp;
}  // namespace mlir::LLVM
namespace mx::ir::llvm {
class NearbyintOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_NEARBYINT;
  }

  static std::optional<NearbyintOp> from(const ::mx::ir::Operation &that);
  static std::optional<NearbyintOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::NearbyintOp underlying_op(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value in(void) const;
  ::mx::ir::Value res(void) const;
  //::mlir::LLVM::FastmathFlags fastmath_flags(void) const;
};
static_assert(sizeof(NearbyintOp) == sizeof(Operation));

}  // namespace mx::ir::llvm