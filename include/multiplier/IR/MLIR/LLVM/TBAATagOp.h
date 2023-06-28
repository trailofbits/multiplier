// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Operation.h"

namespace mlir::LLVM {
class TBAATagOp;
}  // namespace mlir::LLVM
namespace mx::ir::llvm {
class TBAATagOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_TBAA_TAG;
  }

  static std::optional<TBAATagOp> from(const ::mx::ir::Operation &that);
  static std::optional<TBAATagOp> producing(const ::mx::ir::Value &val);

  mlir::LLVM::TBAATagOp underlying_op(void) const noexcept;

  // Imported methods:
  std::string_view sym_name(void) const;
  std::string_view base_type(void) const;
  std::string_view access_type(void) const;
  //uint64_t offset(void) const;
  bool constant(void) const;
};
static_assert(sizeof(TBAATagOp) == sizeof(Operation));

}  // namespace mx::ir::llvm