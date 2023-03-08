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
class Expr;
class InheritableAttr;
class SharedTrylockFunctionAttr;
class Token;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class SharedTrylockFunctionAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<SharedTrylockFunctionAttr> in(const Fragment &frag);
  static gap::generator<SharedTrylockFunctionAttr> in(const File &file);
  static gap::generator<SharedTrylockFunctionAttr> in(const Index &index);
  static gap::generator<SharedTrylockFunctionAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<SharedTrylockFunctionAttr> by_id(const Index &, EntityId);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::SHARED_TRYLOCK_FUNCTION;
  }

  static std::optional<SharedTrylockFunctionAttr> from(const Attr &parent);

  inline static std::optional<SharedTrylockFunctionAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return SharedTrylockFunctionAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<SharedTrylockFunctionAttr> from(const Reference &r);
  static std::optional<SharedTrylockFunctionAttr> from(const TokenContext &t);

  Expr success_value(void) const;
};

static_assert(sizeof(SharedTrylockFunctionAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
