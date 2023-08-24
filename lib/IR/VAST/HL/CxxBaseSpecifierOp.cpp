// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/IR/VAST/HL/CxxBaseSpecifierOp.h>
#include <multiplier/IR/Attribute.h>
#include <multiplier/IR/Block.h>
#include <multiplier/IR/Region.h>
#include <multiplier/IR/Type.h>

#include <vast/Dialect/Dialects.hpp>
#include <mlir/Dialect/SCF/IR/SCF.h>
#include <mlir/Dialect/LLVMIR/LLVMDialect.h>
#include <vast/Dialect/HighLevel/HighLevelOps.hpp>

namespace mx::ir::hl {
std::optional<CxxBaseSpecifierOp> CxxBaseSpecifierOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::HL_BASE) {
    return reinterpret_cast<const CxxBaseSpecifierOp &>(that);
  }
  return std::nullopt;
}

std::optional<CxxBaseSpecifierOp> CxxBaseSpecifierOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::vast::hl::CxxBaseSpecifierOp CxxBaseSpecifierOp::underlying_op(void) const noexcept {
  return ::vast::hl::CxxBaseSpecifierOp(this->Operation::op_);
}

bool CxxBaseSpecifierOp::is_virtual(void) const {
  auto val = underlying_op().getIsVirtual();
  return val;
}

}  // namespace mx::ir::hl
