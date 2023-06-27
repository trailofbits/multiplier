// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Operation.h"

namespace mlir::LLVM {
class vector_extract;
}  // namespace mlir::LLVM
namespace mx::ir::llvm {
class vector_extract final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_INTR_VECTOR_EXTRACT;
  }

  static std::optional<vector_extract> from(const ::mx::ir::Operation &that);
  static std::optional<vector_extract> producing(const ::mx::ir::Value &val);

  mlir::LLVM::vector_extract underlying_op(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value srcvec(void) const;
  ::mx::ir::Value res(void) const;
  //uint64_t pos(void) const;
  //uint64_t src_vector_bit_width(void) const;
  //uint64_t res_vector_bit_width(void) const;
};
static_assert(sizeof(vector_extract) == sizeof(Operation));

}  // namespace mx::ir::llvm
