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
class InheritableAttr;
class MayAliasAttr;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MayAliasAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<MayAliasAttr> in(const Index &index);
  static gap::generator<MayAliasAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<MayAliasAttr> by_id(const Index &, EntityId);
  static gap::generator<MayAliasAttr> in(const Fragment &frag);
  static gap::generator<MayAliasAttr> in(const File &file);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::MAY_ALIAS;
  }

  static std::optional<MayAliasAttr> from_base(const Attr &parent);
  inline static std::optional<MayAliasAttr> from(const Attr &parent) {
    return from_base(parent);
  }
  static std::optional<MayAliasAttr> from(const std::optional<Attr> &parent);
  static std::optional<MayAliasAttr> from(const Reference &r);
  static std::optional<MayAliasAttr> from(const VariantEntity &e);
  static std::optional<MayAliasAttr> from(const TokenContext &t);

};

static_assert(sizeof(MayAliasAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
