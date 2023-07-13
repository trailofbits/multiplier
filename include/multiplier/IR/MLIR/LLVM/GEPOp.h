// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Operation.h"

namespace mlir::LLVM {
class GEPOp;
}  // namespace mlir::LLVM
namespace mx::ir::llvm {
class GEPOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::LLVM_GETELEMENTPTR;
  }

  static std::optional<GEPOp> from(const ::mx::ir::Operation &that);
  static std::optional<GEPOp> producing(const ::mx::ir::Value &val);

  ::mlir::LLVM::GEPOp underlying_op(void) const noexcept;

  // Imported methods:
  ::mx::ir::Value base(void) const;
  //::mlir::mlir::Operation::operand_range dynamic_indices(void) const;
  ::mx::ir::Value res(void) const;
  //::llvm::ArrayRef<int32_t> raw_constant_indices(void) const;
  //::std::optional<::mlir::Type> elem_type(void) const;
  bool inbounds(void) const;
  //Type source_element_type(void) const;
  //GEPIndicesAdaptor<ValueRange> indices(void) const;
};
static_assert(sizeof(GEPOp) == sizeof(Operation));

}  // namespace mx::ir::llvm
