// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Operation.h"

namespace mlir::LLVM {
class GlobalCtorsOp;
}  // namespace mlir::LLVM
namespace mx::ir::llvm {
class GlobalCtorsOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_MLIR_GLOBAL_CTORS;
  }

  static std::optional<GlobalCtorsOp> from(const ::mx::ir::Operation &that);
  static std::optional<GlobalCtorsOp> producing(const ::mx::ir::Value &val);

  mlir::LLVM::GlobalCtorsOp underlying_op(void) const noexcept;

  // Imported methods:
  //::mlir::ArrayAttr ctors(void) const;
  //::mlir::ArrayAttr priorities(void) const;
};
static_assert(sizeof(GlobalCtorsOp) == sizeof(Operation));

}  // namespace mx::ir::llvm
