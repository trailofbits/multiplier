// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "../../Attribute.h"

namespace vast::meta {
class IdentifierAttr;
}  // namespace vast::meta
namespace mx::ir::meta {

class Attribute : public ::mx::ir::Attribute {
 public:
  static std::optional<Attribute> from(const ::mx::ir::Attribute &);
};
static_assert(sizeof(Attribute) == sizeof(::mx::ir::Attribute));

class IdentifierAttr final : public Attribute {
 public:
  inline static AttributeKind static_kind(void) {
    return AttributeKind::META_IDENTIFIER;
  }

  static std::optional<IdentifierAttr> from(const ::mx::ir::Attribute &that);

  ::vast::meta::IdentifierAttr underlying_repr(void) const noexcept;

  // Imported methods:
  //identifier_t value(void) const;
};
static_assert(sizeof(IdentifierAttr) == sizeof(Attribute));

}  // namespace mx::ir::meta
