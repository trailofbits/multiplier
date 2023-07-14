// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Operation.h"

namespace mlir::memref {
class AllocOp;
}  // namespace mlir::memref
namespace mx::ir::memref {
class AllocOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::MEMREF_ALLOC;
  }

  static std::optional<AllocOp> from(const ::mx::ir::Operation &that);
  static std::optional<AllocOp> producing(const ::mx::ir::Value &val);

  ::mlir::memref::AllocOp underlying_op(void) const noexcept;

  // Imported methods:
  gap::generator<::mx::ir::Operand> dynamic_sizes(void) const;
  gap::generator<::mx::ir::Operand> symbol_operands(void) const;
  //::mlir::TypedValue<::mlir::MemRefType> memref(void) const;
  //::std::optional<uint64_t> alignment(void) const;
  //StringRef alignment_attr_str_name(void) const;
  //MemRefType type(void) const;
};
static_assert(sizeof(AllocOp) == sizeof(Operation));

}  // namespace mx::ir::memref
