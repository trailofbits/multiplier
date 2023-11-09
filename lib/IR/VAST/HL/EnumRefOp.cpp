// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/IR/VAST/HL/EnumRefOp.h>
#include <multiplier/IR/Attribute.h>
#include <multiplier/IR/Block.h>
#include <multiplier/IR/Region.h>
#include <multiplier/IR/Type.h>

#include <mlir/Dialect/SCF/IR/SCF.h>
#include <mlir/Dialect/LLVMIR/LLVMDialect.h>
#include <vast/Dialect/Dialects.hpp>
#include <vast/Dialect/HighLevel/HighLevelOps.hpp>

namespace mx::ir::hl {
std::optional<EnumRefOp> EnumRefOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::HL_ENUMREF) {
    return reinterpret_cast<const EnumRefOp &>(that);
  }
  return std::nullopt;
}

std::optional<EnumRefOp> EnumRefOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::vast::hl::EnumRefOp EnumRefOp::underlying_op(void) const noexcept {
  return ::vast::hl::EnumRefOp(this->Operation::op_);
}

::mx::ir::Value EnumRefOp::result(void) const {
  auto val = underlying_op().getResult();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::string_view EnumRefOp::value(void) const {
  auto val = underlying_op().getValue();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return {};
  }
}

}  // namespace mx::ir::hl
