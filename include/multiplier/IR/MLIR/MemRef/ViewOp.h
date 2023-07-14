// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Operation.h"

namespace mlir::memref {
class ViewOp;
}  // namespace mlir::memref
namespace mx::ir::memref {
class ViewOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::MEMREF_VIEW;
  }

  static std::optional<ViewOp> from(const ::mx::ir::Operation &that);
  static std::optional<ViewOp> producing(const ::mx::ir::Value &val);

  ::mlir::memref::ViewOp underlying_op(void) const noexcept;

  // Imported methods:
  //::mlir::TypedValue<::mlir::MemRefType> source(void) const;
  //::mlir::TypedValue<::mlir::IndexType> byte_shift(void) const;
  gap::generator<::mx::ir::Operand> sizes(void) const;
  ::mx::ir::Value view_source(void) const;
  //MemRefType type(void) const;
  //operand_range dynamic_sizes(void) const;
};
static_assert(sizeof(ViewOp) == sizeof(Operation));

}  // namespace mx::ir::memref
