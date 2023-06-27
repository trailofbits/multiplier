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
class TypeNonNullAttr;
namespace mx {
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class TypeNonNullAttr : public TypeAttr {
 private:
  friend class FragmentImpl;
  friend class TypeAttr;
  friend class Attr;
 public:
  static gap::generator<TypeNonNullAttr> in(const Fragment &frag);
  static gap::generator<TypeNonNullAttr> in(const File &file);
  static gap::generator<TypeNonNullAttr> in(const Index &index);
  static gap::generator<TypeNonNullAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<TypeNonNullAttr> by_id(const Index &, EntityId);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::TYPE_NON_NULL;
  }

  static std::optional<TypeNonNullAttr> from(const Attr &parent);

  inline static std::optional<TypeNonNullAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return TypeNonNullAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<TypeNonNullAttr> from(const Reference &r);
  static std::optional<TypeNonNullAttr> from(const TokenContext &t);

};

static_assert(sizeof(TypeNonNullAttr) == sizeof(TypeAttr));

#endif
} // namespace mx
