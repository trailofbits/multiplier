// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Operation.h"

namespace mlir::LLVM {
class ComdatSelectorOp;
}  // namespace mlir::LLVM
namespace mx::ir::llvm {
class ComdatSelectorOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_COMDAT_SELECTOR;
  }

  static std::optional<ComdatSelectorOp> from(const ::mx::ir::Operation &that);
  static std::optional<ComdatSelectorOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::ComdatSelectorOp underlying_op(void) const noexcept;

  // Imported methods:
  std::string_view sym_name(void) const;
  //::mlir::LLVM::comdat::Comdat comdat(void) const;
};
static_assert(sizeof(ComdatSelectorOp) == sizeof(Operation));

}  // namespace mx::ir::llvm
