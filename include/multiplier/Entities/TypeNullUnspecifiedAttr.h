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
class TypeNullUnspecifiedAttr;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class TypeNullUnspecifiedAttr : public TypeAttr {
 private:
  friend class FragmentImpl;
  friend class TypeAttr;
  friend class Attr;
 public:
  static gap::generator<TypeNullUnspecifiedAttr> in(const Index &index);
  static gap::generator<TypeNullUnspecifiedAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<TypeNullUnspecifiedAttr> by_id(const Index &, EntityId);
  static gap::generator<TypeNullUnspecifiedAttr> in(const Fragment &frag);
  static gap::generator<TypeNullUnspecifiedAttr> in(const File &file);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::TYPE_NULL_UNSPECIFIED;
  }

  static std::optional<TypeNullUnspecifiedAttr> from_base(const Attr &parent);
  inline static std::optional<TypeNullUnspecifiedAttr> from(const Attr &parent) {
    return from_base(parent);
  }
  static std::optional<TypeNullUnspecifiedAttr> from(const std::optional<Attr> &parent);
  static std::optional<TypeNullUnspecifiedAttr> from(const Reference &r);
  static std::optional<TypeNullUnspecifiedAttr> from(const VariantEntity &e);
  static std::optional<TypeNullUnspecifiedAttr> from(const TokenContext &t);

};

static_assert(sizeof(TypeNullUnspecifiedAttr) == sizeof(TypeAttr));

#endif
} // namespace mx
