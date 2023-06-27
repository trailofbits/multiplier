// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Operation.h"

namespace mlir::memref {
class AllocaOp;
}  // namespace mlir::memref
namespace mx::ir::memref {
class AllocaOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::MEMREF_ALLOCA;
  }

  static std::optional<AllocaOp> from(const ::mx::ir::Operation &that);
  static std::optional<AllocaOp> producing(const ::mx::ir::Value &val);

  mlir::memref::AllocaOp underlying_op(void) const noexcept;

  // Imported methods:
  //::mlir::Operation::operand_range dynamic_sizes(void) const;
  //::mlir::Operation::operand_range symbol_operands(void) const;
  //::mlir::TypedValue<::mlir::MemRefType> memref(void) const;
  //::std::optional<uint64_t> alignment(void) const;
  //StringRef alignment_attr_str_name(void) const;
  //MemRefType type(void) const;
};
static_assert(sizeof(AllocaOp) == sizeof(Operation));

}  // namespace mx::ir::memref
