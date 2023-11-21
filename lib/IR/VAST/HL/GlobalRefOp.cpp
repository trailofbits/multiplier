// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/IR/VAST/HL/GlobalRefOp.h>
#include <multiplier/IR/Attribute.h>
#include <multiplier/IR/Block.h>
#include <multiplier/IR/Region.h>
#include <multiplier/IR/Type.h>

#include <mlir/Dialect/SCF/IR/SCF.h>
#include <mlir/Dialect/LLVMIR/LLVMDialect.h>
#include <vast/Dialect/Dialects.hpp>
#include <vast/Dialect/ABI/ABIOps.hpp>
#include <vast/Dialect/HighLevel/HighLevelOps.hpp>

namespace mx::ir::hl {
std::optional<GlobalRefOp> GlobalRefOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::HL_GLOBREF) {
    return reinterpret_cast<const GlobalRefOp &>(that);
  }
  return std::nullopt;
}

std::optional<GlobalRefOp> GlobalRefOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::vast::hl::GlobalRefOp GlobalRefOp::underlying_op(void) const noexcept {
  return ::vast::hl::GlobalRefOp(this->Operation::op_);
}

::mx::ir::Value GlobalRefOp::result(void) const {
  auto val = underlying_op().getResult();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::string_view GlobalRefOp::global(void) const {
  auto val = underlying_op().getGlobal();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return {};
  }
}

}  // namespace mx::ir::hl
