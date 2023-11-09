// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Operation.h"

namespace mlir::LLVM {
class IsFPClass;
}  // namespace mlir::LLVM
namespace mx::ir::llvm {
class IsFPClass final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_IS_FPCLASS;
  }

  static std::optional<IsFPClass> from(const ::mx::ir::Operation &that);
  static std::optional<IsFPClass> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::IsFPClass underlying_op(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value in(void) const;
  ::mx::ir::Value res(void) const;
  uint32_t bit(void) const;
};
static_assert(sizeof(IsFPClass) == sizeof(Operation));

}  // namespace mx::ir::llvm
