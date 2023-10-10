// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Operation.h"

namespace mlir::memref {
class GetGlobalOp;
}  // namespace mlir::memref
namespace mx::ir::memref {
class GetGlobalOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::MEMREF_GET_GLOBAL;
  }

  static std::optional<GetGlobalOp> from(const ::mx::ir::Operation &that);
  static std::optional<GetGlobalOp> producing(const ::mx::ir::Value &val);

  ::mlir::memref::GetGlobalOp underlying_op(void) const noexcept;

  // Imported methods:
  //::mlir::TypedValue<::mlir::MemRefType> result(void) const;
  std::string_view name(void) const;
};
static_assert(sizeof(GetGlobalOp) == sizeof(Operation));

}  // namespace mx::ir::memref
