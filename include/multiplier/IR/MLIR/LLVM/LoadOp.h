// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Operation.h"

namespace mlir::LLVM {
class LoadOp;
}  // namespace mlir::LLVM
namespace mx::ir::llvm {
class LoadOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_LOAD;
  }

  static std::optional<LoadOp> from(const ::mx::ir::Operation &that);
  static std::optional<LoadOp> producing(const ::mx::ir::Value &val);

  mlir::LLVM::LoadOp underlying_op(void) const noexcept;

  // Imported methods:
  //::mlir::TypedValue<::mlir::LLVM::LLVMPointerType> addr(void) const;
  ::mx::ir::Value res(void) const;
  //::std::optional<::mlir::ArrayAttr> access_groups(void) const;
  //::std::optional<::mlir::ArrayAttr> alias_scopes(void) const;
  //::std::optional<::mlir::ArrayAttr> noalias_scopes(void) const;
  //::std::optional<uint64_t> alignment(void) const;
  bool volatile__(void) const;
  bool nontemporal(void) const;
};
static_assert(sizeof(LoadOp) == sizeof(Operation));

}  // namespace mx::ir::llvm
