// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Operation.h"

namespace mlir::memref {
class AtomicRMWOp;
}  // namespace mlir::memref
namespace mx::ir::memref {
class AtomicRMWOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::MEMREF_ATOMIC_RMW;
  }

  static std::optional<AtomicRMWOp> from(const ::mx::ir::Operation &that);
  static std::optional<AtomicRMWOp> producing(const ::mx::ir::Value &val);

  ::mlir::memref::AtomicRMWOp underlying_op(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value value(void) const;
  //::mlir::TypedValue<::mlir::MemRefType> memref(void) const;
  //::mlir::mlir::Operation::operand_range indices(void) const;
  ::mx::ir::Value result(void) const;
  //::mlir::arith::AtomicRMWKind kind(void) const;
  //MemRefType mem_ref_type(void) const;
};
static_assert(sizeof(AtomicRMWOp) == sizeof(Operation));

}  // namespace mx::ir::memref
