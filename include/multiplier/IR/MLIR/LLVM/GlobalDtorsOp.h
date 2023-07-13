// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Operation.h"

namespace mlir::LLVM {
class GlobalDtorsOp;
}  // namespace mlir::LLVM
namespace mx::ir::llvm {
class GlobalDtorsOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_MLIR_GLOBAL_DTORS;
  }

  static std::optional<GlobalDtorsOp> from(const ::mx::ir::Operation &that);
  static std::optional<GlobalDtorsOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::GlobalDtorsOp underlying_op(void) const noexcept;

  // Imported methods:
  //::mlir::ArrayAttr dtors(void) const;
  //::mlir::ArrayAttr priorities(void) const;
};
static_assert(sizeof(GlobalDtorsOp) == sizeof(Operation));

}  // namespace mx::ir::llvm
