// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/IR/VAST/LL/StructGEPOp.h>
#include <multiplier/IR/Attribute.h>
#include <multiplier/IR/Block.h>
#include <multiplier/IR/Region.h>
#include <multiplier/IR/Type.h>

#include <mlir/Dialect/SCF/IR/SCF.h>
#include <vast/Dialect/Dialects.hpp>
#include <vast/Dialect/ABI/ABIOps.hpp>
#include <vast/Dialect/LowLevel/LowLevelOps.hpp>

namespace mx::ir::ll {
std::optional<StructGEPOp> StructGEPOp::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::LL_GEP) {
    return reinterpret_cast<const StructGEPOp &>(that);
  }
  return std::nullopt;
}

std::optional<StructGEPOp> StructGEPOp::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::vast::ll::StructGEPOp StructGEPOp::underlying_op(void) const noexcept {
  return ::vast::ll::StructGEPOp(this->Operation::op_);
}

::mx::ir::Value StructGEPOp::record(void) const {
  auto val = underlying_op().getRecord();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

::mx::ir::Value StructGEPOp::element(void) const {
  auto val = underlying_op().getElement();
  return ::mx::ir::Value(module_, val.getAsOpaquePointer());
}

uint32_t StructGEPOp::idx(void) const {
  auto val = underlying_op().getIdx();
  return val;
}

std::string_view StructGEPOp::name(void) const {
  auto val = underlying_op().getName();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return {};
  }
}

}  // namespace mx::ir::ll
