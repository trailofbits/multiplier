// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Operation.h"

namespace mlir::memref {
class GenericAtomicRMWOp;
}  // namespace mlir::memref
namespace mx::ir::memref {
class GenericAtomicRMWOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::MEMREF_GENERIC_ATOMIC_RMW;
  }

  static std::optional<GenericAtomicRMWOp> from(const ::mx::ir::Operation &that);
  static std::optional<GenericAtomicRMWOp> producing(const ::mx::ir::Value &val);

  mlir::memref::GenericAtomicRMWOp underlying_op(void) const noexcept;

  // Imported methods:
  //::mlir::TypedValue<::mlir::MemRefType> memref(void) const;
  //::mlir::Operation::operand_range indices(void) const;
  ::mx::ir::Value result(void) const;
  ::mx::ir::Region atomic_body(void) const;
  //Region& body(void) const;
  //Value current_value(void) const;
  //MemRefType mem_ref_type(void) const;
};
static_assert(sizeof(GenericAtomicRMWOp) == sizeof(Operation));

}  // namespace mx::ir::memref
