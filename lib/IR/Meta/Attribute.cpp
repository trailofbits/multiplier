// Copyright (c) 2023-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/IR/Meta/Attribute.h>

#include <multiplier/IR/Type.h>

#include <mlir/Dialect/LLVMIR/LLVMDialect.h>
#include <vast/Dialect/Dialects.hpp>
#include <vast/Dialect/Meta/MetaAttributes.hpp>

namespace mx::ir::meta {
std::optional<Attribute> Attribute::from(const ::mx::ir::Attribute &that) {
  if (IsMetaAttributeKind(that.kind())) {
    return reinterpret_cast<const Attribute &>(that);
  }
  return std::nullopt;
}

std::optional<IdentifierAttr> IdentifierAttr::from(const ::mx::ir::Attribute &that) {
  if (that.kind() == AttributeKind::META_IDENTIFIER) {
    return reinterpret_cast<const IdentifierAttr &>(that);
  }
  return std::nullopt;
}

::vast::meta::IdentifierAttr IdentifierAttr::underlying_repr(void) const noexcept {
  return ::vast::meta::IdentifierAttr(this->::mx::ir::Attribute::attr_);
}

}  // namespace mx::ir::meta
