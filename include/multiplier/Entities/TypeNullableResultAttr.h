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
class TypeNullableResultAttr;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class TypeNullableResultAttr : public TypeAttr {
 private:
  friend class FragmentImpl;
  friend class TypeAttr;
  friend class Attr;
 public:
  static gap::generator<TypeNullableResultAttr> in(const Fragment &frag);
  static gap::generator<TypeNullableResultAttr> in(const File &file);
  static gap::generator<TypeNullableResultAttr> in(const Index &index);
  static gap::generator<TypeNullableResultAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<TypeNullableResultAttr> by_id(const Index &, EntityId);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::TYPE_NULLABLE_RESULT;
  }

  static std::optional<TypeNullableResultAttr> from(const Attr &parent);

  inline static std::optional<TypeNullableResultAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return TypeNullableResultAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<TypeNullableResultAttr> from(const Reference &r);
  static std::optional<TypeNullableResultAttr> from(const TokenContext &t);

};

static_assert(sizeof(TypeNullableResultAttr) == sizeof(TypeAttr));

#endif
} // namespace mx
