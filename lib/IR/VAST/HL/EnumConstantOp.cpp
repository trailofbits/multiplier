// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/IR/VAST/HL/EnumConstantOp.h>
#include <multiplier/IR/Attribute.h>
#include <multiplier/IR/Block.h>
#include <multiplier/IR/Region.h>
#include <multiplier/IR/Type.h>

#include <vast/Dialect/Dialects.hpp>
#include <mlir/Dialect/SCF/IR/SCF.h>
#include <mlir/Dialect/LLVMIR/LLVMDialect.h>
#include <vast/Dialect/HighLevel/HighLevelOps.hpp>

namespace mx::ir::hl {
std::optional<EnumConstantOp> EnumConstantOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::HL_ENUM_CONST) {
    return reinterpret_cast<const EnumConstantOp &>(that);
  }
  return std::nullopt;
}

std::optional<EnumConstantOp> EnumConstantOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::vast::hl::EnumConstantOp EnumConstantOp::underlying_op(void) const noexcept {
  return ::vast::hl::EnumConstantOp(this->Operation::op_);
}

::mx::ir::Region EnumConstantOp::init(void) const {
  auto &val = underlying_op().getInit();
  return ::mx::ir::Region(module_, val);
}

std::string_view EnumConstantOp::name(void) const {
  auto val = underlying_op().getName();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return {};
  }
}

}  // namespace mx::ir::hl
