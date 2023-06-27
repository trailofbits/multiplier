// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Operation.h"

namespace mlir::LLVM {
class masked_gather;
}  // namespace mlir::LLVM
namespace mx::ir::llvm {
class masked_gather final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_MASKED_GATHER;
  }

  static std::optional<masked_gather> from(const ::mx::ir::Operation &that);
  static std::optional<masked_gather> producing(const ::mx::ir::Value &val);

  mlir::LLVM::masked_gather underlying_op(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value ptrs(void) const;
  ::mx::ir::Value mask(void) const;
  //::mlir::Operation::operand_range pass_thru(void) const;
  ::mx::ir::Value res(void) const;
  uint32_t alignment(void) const;
};
static_assert(sizeof(masked_gather) == sizeof(Operation));

}  // namespace mx::ir::llvm
