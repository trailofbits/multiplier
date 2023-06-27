// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Operation.h"

namespace mlir::memref {
class CollapseShapeOp;
}  // namespace mlir::memref
namespace mx::ir::memref {
class CollapseShapeOp final : public Operation {
 public:
  inline static OperationKind static_kind(void) {
    return OperationKind::MEMREF_COLLAPSE_SHAPE;
  }

  static std::optional<CollapseShapeOp> from(const ::mx::ir::Operation &that);
  static std::optional<CollapseShapeOp> producing(const ::mx::ir::Value &val);

  mlir::memref::CollapseShapeOp underlying_op(void) const noexcept;

  // Imported methods:
  //::mlir::TypedValue<::mlir::MemRefType> src(void) const;
  //::mlir::TypedValue<::mlir::MemRefType> result(void) const;
  //::mlir::ArrayAttr reassociation(void) const;
  //SmallVector<AffineMap,4> reassociation_maps(void) const;
  //SmallVector<ReassociationExprs,4> reassociation_exprs(void) const;
  //SmallVector<ReassociationIndices,4> reassociation_indices(void) const;
  //MemRefType src_type(void) const;
  //MemRefType result_type(void) const;
  //Value view_source(void) const;
};
static_assert(sizeof(CollapseShapeOp) == sizeof(Operation));

}  // namespace mx::ir::memref
