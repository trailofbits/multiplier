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
class NoAliasAttr;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class NoAliasAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<NoAliasAttr> in(const Index &index);
  static gap::generator<NoAliasAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<NoAliasAttr> by_id(const Index &, EntityId);
  static gap::generator<NoAliasAttr> in(const Fragment &frag);
  static gap::generator<NoAliasAttr> in(const File &file);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::NO_ALIAS;
  }

  static std::optional<NoAliasAttr> from(const Attr &parent);

  inline static std::optional<NoAliasAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return NoAliasAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<NoAliasAttr> from(const Reference &r);
  static std::optional<NoAliasAttr> from(const TokenContext &t);

};

static_assert(sizeof(NoAliasAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
