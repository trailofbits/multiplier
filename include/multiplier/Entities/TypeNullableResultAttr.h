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

#include <gap/core/generator.hpp>
#include "../Iterator.h"
#include "../Types.h"
#include "../Token.h"
#include "../Use.h"

#include "AttrKind.h"
#include "TypeAttr.h"

namespace mx {
class Attr;
class TypeAttr;
class TypeNullableResultAttr;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using TypeNullableResultAttrContainingTokenRange = DerivedEntityRange<TokenContextIterator, TypeNullableResultAttr>;
class TypeNullableResultAttr : public TypeAttr {
 private:
  friend class FragmentImpl;
  friend class TypeAttr;
  friend class Attr;
 public:
  inline static gap::generator<TypeNullableResultAttr> in(const Fragment &frag) {
    for(auto e : in_internal(frag)) {
      if(auto d = from(e)) {
        co_yield *d;
      }
    }
  }

  inline static TypeNullableResultAttrContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : TypeNullableResultAttr::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::TYPE_NULLABLE_RESULT;
  }

  static std::optional<TypeNullableResultAttr> from(const TokenContext &c);
  static std::optional<TypeNullableResultAttr> from(const TypeAttr &parent);

  inline static std::optional<TypeNullableResultAttr> from(const std::optional<TypeAttr> &parent) {
    if (parent) {
      return TypeNullableResultAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<TypeNullableResultAttr> from(const Attr &parent);

  inline static std::optional<TypeNullableResultAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return TypeNullableResultAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  std::string_view spelling(void) const;
};

static_assert(sizeof(TypeNullableResultAttr) == sizeof(TypeAttr));

#endif
} // namespace mx
