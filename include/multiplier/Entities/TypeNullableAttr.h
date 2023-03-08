// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "TypeAttr.h"

namespace mx {
class EntityProvider;
class Index;
class Attr;
class Token;
class TypeAttr;
class TypeNullableAttr;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class TypeNullableAttr : public TypeAttr {
 private:
  friend class FragmentImpl;
  friend class TypeAttr;
  friend class Attr;
 public:
  static gap::generator<TypeNullableAttr> in(const Fragment &frag);
  static gap::generator<TypeNullableAttr> in(const File &file);
  static gap::generator<TypeNullableAttr> in(const Index &index);
  static gap::generator<TypeNullableAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<TypeNullableAttr> by_id(const Index &, EntityId);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::TYPE_NULLABLE;
  }

  static std::optional<TypeNullableAttr> from(const Attr &parent);

  inline static std::optional<TypeNullableAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return TypeNullableAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<TypeNullableAttr> from(const Reference &r);
  static std::optional<TypeNullableAttr> from(const TokenContext &t);

};

static_assert(sizeof(TypeNullableAttr) == sizeof(TypeAttr));

#endif
} // namespace mx
