// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <multiplier/AST/InheritableAttr.h>

namespace mx {
class EntityProvider;
class Fragment;
class Index;
class Attr;
class CoroLifetimeBoundAttr;
class File;
class InheritableAttr;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT CoroLifetimeBoundAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<CoroLifetimeBoundAttr> in(const Index &index);
  static gap::generator<CoroLifetimeBoundAttr> in(const Fragment &frag);
  static gap::generator<CoroLifetimeBoundAttr> in(const File &file);
  static gap::generator<CoroLifetimeBoundAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::CORO_LIFETIME_BOUND;
  }

  static std::optional<CoroLifetimeBoundAttr> by_id(const Index &, EntityId);

  static std::optional<CoroLifetimeBoundAttr> from_base(const Attr &parent);
  inline static std::optional<CoroLifetimeBoundAttr> from(const Attr &parent) {
    return from_base(parent);
  }
  static std::optional<CoroLifetimeBoundAttr> from(const std::optional<Attr> &parent);
  static std::optional<CoroLifetimeBoundAttr> from(const Reference &r);
  static std::optional<CoroLifetimeBoundAttr> from(const VariantEntity &e);
  static std::optional<CoroLifetimeBoundAttr> from(const TokenContext &t);

};

static_assert(sizeof(CoroLifetimeBoundAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
