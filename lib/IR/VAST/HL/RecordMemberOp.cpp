// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/IR/VAST/HL/RecordMemberOp.h>
#include <multiplier/IR/Attribute.h>
#include <multiplier/IR/Block.h>
#include <multiplier/IR/Region.h>
#include <multiplier/IR/Type.h>

#include <vast/Dialect/Dialects.hpp>
#include <mlir/Dialect/SCF/IR/SCF.h>
#include <mlir/Dialect/LLVMIR/LLVMDialect.h>
#include <vast/Dialect/HighLevel/HighLevelOps.hpp>

namespace mx::ir::hl {
std::optional<RecordMemberOp> RecordMemberOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::HL_MEMBER) {
    return reinterpret_cast<const RecordMemberOp &>(that);
  }
  return std::nullopt;
}

std::optional<RecordMemberOp> RecordMemberOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::vast::hl::RecordMemberOp RecordMemberOp::underlying_op(void) const noexcept {
  return ::vast::hl::RecordMemberOp(this->Operation::op_);
}

::mx::ir::Value RecordMemberOp::record(void) const {
  auto val = underlying_op().getRecord();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value RecordMemberOp::element(void) const {
  auto val = underlying_op().getElement();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

std::string_view RecordMemberOp::name(void) const {
  auto val = underlying_op().getName();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return {};
  }
}

}  // namespace mx::ir::hl
