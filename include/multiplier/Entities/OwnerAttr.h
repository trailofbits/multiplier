// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "InheritableAttr.h"

namespace mx {
class EntityProvider;
class Index;
class Attr;
class InheritableAttr;
class OwnerAttr;
class Token;
class Type;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class OwnerAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<OwnerAttr> in(const Fragment &frag);
  static gap::generator<OwnerAttr> in(const File &file);
  static gap::generator<OwnerAttr> in(const Index &index);
  static gap::generator<OwnerAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<OwnerAttr> by_id(const Index &, EntityId);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::OWNER;
  }

  static std::optional<OwnerAttr> from(const Attr &parent);

  inline static std::optional<OwnerAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return OwnerAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<OwnerAttr> from(const Reference &r);
  static std::optional<OwnerAttr> from(const TokenContext &t);

  Type deref_type(void) const;
  Type deref_type_token(void) const;
};

static_assert(sizeof(OwnerAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
