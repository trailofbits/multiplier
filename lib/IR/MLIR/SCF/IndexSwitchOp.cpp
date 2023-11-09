// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/IR/MLIR/SCF/IndexSwitchOp.h>
#include <multiplier/IR/Attribute.h>
#include <multiplier/IR/Block.h>
#include <multiplier/IR/Region.h>
#include <multiplier/IR/Type.h>

#include <mlir/Dialect/SCF/IR/SCF.h>

namespace mx::ir::scf {
std::optional<IndexSwitchOp> IndexSwitchOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::SCF_INDEX_SWITCH) {
    return reinterpret_cast<const IndexSwitchOp &>(that);
  }
  return std::nullopt;
}

std::optional<IndexSwitchOp> IndexSwitchOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::mlir::scf::IndexSwitchOp IndexSwitchOp::underlying_op(void) const noexcept {
  return ::mlir::scf::IndexSwitchOp(this->Operation::op_);
}

gap::generator<::mx::ir::Result> IndexSwitchOp::results(void) const {
  auto range = underlying_op().getResults();
  for (auto val : range) {
    co_yield ::mx::ir::Result(module_, val.getAsOpaquePointer());
  }
}

::mx::ir::Region IndexSwitchOp::default_region(void) const {
  auto &val = underlying_op().getDefaultRegion();
  return ::mx::ir::Region(module_, val);
}

}  // namespace mx::ir::scf
