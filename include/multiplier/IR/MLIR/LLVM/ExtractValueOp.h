// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Operation.h"

namespace mlir::LLVM {
class ExtractValueOp;
}  // namespace mlir::LLVM
namespace mx::ir::llvm {
class ExtractValueOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_EXTRACTVALUE;
  }

  static std::optional<ExtractValueOp> from(const ::mx::ir::Operation &that);
  static std::optional<ExtractValueOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::ExtractValueOp underlying_op(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value container(void) const;
  ::mx::ir::Value res(void) const;
  //::llvm::ArrayRef<int64_t> position(void) const;
};
static_assert(sizeof(ExtractValueOp) == sizeof(Operation));

}  // namespace mx::ir::llvm
