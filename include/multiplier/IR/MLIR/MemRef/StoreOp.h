// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Operation.h"

namespace mlir::memref {
class StoreOp;
}  // namespace mlir::memref
namespace mx::ir::memref {
class StoreOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::MEMREF_STORE;
  }

  static std::optional<StoreOp> from(const ::mx::ir::Operation &that);
  static std::optional<StoreOp> producing(const ::mx::ir::Value &val);

  mlir::memref::StoreOp underlying_op(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value value(void) const;
  //::mlir::TypedValue<::mlir::MemRefType> memref(void) const;
  //::mlir::Operation::operand_range indices(void) const;
  //Value value_to_store(void) const;
  //Value mem_ref(void) const;
  //MemRefType mem_ref_type(void) const;
};
static_assert(sizeof(StoreOp) == sizeof(Operation));

}  // namespace mx::ir::memref
