// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Operation.h"

namespace mlir::memref {
class ReallocOp;
}  // namespace mlir::memref
namespace mx::ir::memref {
class ReallocOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::MEMREF_REALLOC;
  }

  static std::optional<ReallocOp> from(const ::mx::ir::Operation &that);
  static std::optional<ReallocOp> producing(const ::mx::ir::Value &val);

  ::mlir::memref::ReallocOp underlying_op(void) const noexcept;

  // Imported methods:
  //::mlir::TypedValue<::mlir::MemRefType> source(void) const;
  //::mlir::TypedValue<::mlir::IndexType> dynamic_result_size(void) const;
  //::std::optional<uint64_t> alignment(void) const;
  //MemRefType type(void) const;
};
static_assert(sizeof(ReallocOp) == sizeof(Operation));

}  // namespace mx::ir::memref
