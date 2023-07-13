// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Operation.h"

namespace mlir::LLVM {
class TBAATypeDescriptorOp;
}  // namespace mlir::LLVM
namespace mx::ir::llvm {
class TBAATypeDescriptorOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_TBAA_TYPE_DESC;
  }

  static std::optional<TBAATypeDescriptorOp> from(const ::mx::ir::Operation &that);
  static std::optional<TBAATypeDescriptorOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::TBAATypeDescriptorOp underlying_op(void) const noexcept;

  // Imported methods:
  std::string_view sym_name(void) const;
  std::optional<std::string_view> identity(void) const;
  //::mlir::ArrayAttr members(void) const;
  //::llvm::ArrayRef<int64_t> offsets(void) const;
};
static_assert(sizeof(TBAATypeDescriptorOp) == sizeof(Operation));

}  // namespace mx::ir::llvm
