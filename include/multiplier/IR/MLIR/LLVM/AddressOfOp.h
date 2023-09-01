// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Operation.h"

namespace mlir::LLVM {
class AddressOfOp;
}  // namespace mlir::LLVM
namespace mx::ir::llvm {
class AddressOfOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_MLIR_ADDRESSOF;
  }

  static std::optional<AddressOfOp> from(const ::mx::ir::Operation &that);
  static std::optional<AddressOfOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::AddressOfOp underlying_op(void) const noexcept;

  // Imported methods:
  //::mlir::TypedValue<::mlir::LLVM::LLVMPointerType> res(void) const;
  std::string_view global_name(void) const;
};
static_assert(sizeof(AddressOfOp) == sizeof(Operation));

}  // namespace mx::ir::llvm
