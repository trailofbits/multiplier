// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>
#include <filesystem>
#include <memory>
#include <optional>
#include <vector>

#include "../Iterator.h"
#include "../Types.h"
#include "../Token.h"
#include "../Use.h"

#include "AttrKind.h"
#include "TypeAttr.h"

namespace mx {
class Attr;
class TypeAttr;
class TypeNullableAttr;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using TypeNullableAttrRange = DerivedEntityRange<AttrIterator, TypeNullableAttr>;
using TypeNullableAttrContainingTokenRange = DerivedEntityRange<TokenContextIterator, TypeNullableAttr>;
class TypeNullableAttr : public TypeAttr {
 private:
  friend class FragmentImpl;
  friend class TypeAttr;
  friend class Attr;
 public:
  inline static TypeNullableAttrRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static TypeNullableAttrContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : TypeNullableAttr::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::TYPE_NULLABLE;
  }

  static std::optional<TypeNullableAttr> from(const TokenContext &c);
  static std::optional<TypeNullableAttr> from(const TypeAttr &parent);

  inline static std::optional<TypeNullableAttr> from(const std::optional<TypeAttr> &parent) {
    if (parent) {
      return TypeNullableAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<TypeNullableAttr> from(const Attr &parent);

  inline static std::optional<TypeNullableAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return TypeNullableAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  std::string_view spelling(void) const;
};

static_assert(sizeof(TypeNullableAttr) == sizeof(TypeAttr));

#endif
} // namespace mx
