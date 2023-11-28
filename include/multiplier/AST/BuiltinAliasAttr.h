// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <multiplier/AST/Attr.h>
#include <multiplier/AST/BuiltinAliasAttrSpelling.h>

namespace mx {
class EntityProvider;
class Fragment;
class Index;
class Attr;
class BuiltinAliasAttr;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class BuiltinAliasAttr : public Attr {
 private:
  friend class FragmentImpl;
  friend class Attr;
 public:
  static gap::generator<BuiltinAliasAttr> in(const Index &index);
  static gap::generator<BuiltinAliasAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<BuiltinAliasAttr> by_id(const Index &, EntityId);
  static gap::generator<BuiltinAliasAttr> in(const Fragment &frag);
  static gap::generator<BuiltinAliasAttr> in(const File &file);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::BUILTIN_ALIAS;
  }

  static std::optional<BuiltinAliasAttr> from_base(const Attr &parent);
  inline static std::optional<BuiltinAliasAttr> from(const Attr &parent) {
    return from_base(parent);
  }
  static std::optional<BuiltinAliasAttr> from(const std::optional<Attr> &parent);
  static std::optional<BuiltinAliasAttr> from(const Reference &r);
  static std::optional<BuiltinAliasAttr> from(const VariantEntity &e);
  static std::optional<BuiltinAliasAttr> from(const TokenContext &t);

  BuiltinAliasAttrSpelling semantic_spelling(void) const;
};

static_assert(sizeof(BuiltinAliasAttr) == sizeof(Attr));

#endif
} // namespace mx
