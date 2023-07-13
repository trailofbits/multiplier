// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Operation.h"

namespace mlir::memref {
class LoadOp;
}  // namespace mlir::memref
namespace mx::ir::memref {
class LoadOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::MEMREF_LOAD;
  }

  static std::optional<LoadOp> from(const ::mx::ir::Operation &that);
  static std::optional<LoadOp> producing(const ::mx::ir::Value &val);

  ::mlir::memref::LoadOp underlying_op(void) const noexcept;

  // Imported methods:
  //::mlir::TypedValue<::mlir::MemRefType> memref(void) const;
  //::mlir::mlir::Operation::operand_range indices(void) const;
  ::mx::ir::Value result(void) const;
  //Value mem_ref(void) const;
  //MemRefType mem_ref_type(void) const;
};
static_assert(sizeof(LoadOp) == sizeof(Operation));

}  // namespace mx::ir::memref
