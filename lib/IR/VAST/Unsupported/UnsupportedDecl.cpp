// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/IR/VAST/Unsupported/UnsupportedDecl.h>
#include <multiplier/IR/Attribute.h>
#include <multiplier/IR/Block.h>
#include <multiplier/IR/Region.h>
#include <multiplier/IR/Type.h>

#include <mlir/Dialect/SCF/IR/SCF.h>
#include <vast/Dialect/Dialects.hpp>
#include <vast/Dialect/Unsupported/UnsupportedOps.hpp>

namespace mx::ir::unsup {
std::optional<UnsupportedDecl> UnsupportedDecl::from(const ::mx::ir::Operation &that) {
  if (that.kind() == OperationKind::UNSUP_DECL) {
    return reinterpret_cast<const UnsupportedDecl &>(that);
  }
  return std::nullopt;
}

std::optional<UnsupportedDecl> UnsupportedDecl::producing(const ::mx::ir::Value &that) {
  if (auto op = ::mx::ir::Operation::producing(that)) {
    return from(op.value());
  }
  return std::nullopt;
}

::vast::unsup::UnsupportedDecl UnsupportedDecl::underlying_op(void) const noexcept {
  return ::vast::unsup::UnsupportedDecl(this->Operation::op_);
}

::mx::ir::Region UnsupportedDecl::body(void) const {
  auto &val = underlying_op().getBody();
  return ::mx::ir::Region(module_, val);
}

std::string_view UnsupportedDecl::name(void) const {
  auto val = underlying_op().getName();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return {};
  }
}

}  // namespace mx::ir::unsup
