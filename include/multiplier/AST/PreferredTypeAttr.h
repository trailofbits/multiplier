// Copyright (c) 2022-present, Trail of Bits, Inc.
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
class File;
class InheritableAttr;
class PreferredTypeAttr;
class Token;
class Type;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT PreferredTypeAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<PreferredTypeAttr> in(const Index &index);
  static gap::generator<PreferredTypeAttr> in(const Fragment &frag);
  static gap::generator<PreferredTypeAttr> in(const File &file);
  static gap::generator<PreferredTypeAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::PREFERRED_TYPE;
  }

  static std::optional<PreferredTypeAttr> by_id(const Index &, EntityId);

  static std::optional<PreferredTypeAttr> from_base(const Attr &parent);
  inline static std::optional<PreferredTypeAttr> from(const Attr &parent) {
    return from_base(parent);
  }
  static std::optional<PreferredTypeAttr> from(const std::optional<Attr> &parent);
  static std::optional<PreferredTypeAttr> from(const Reference &r);
  static std::optional<PreferredTypeAttr> from(const VariantEntity &e);
  static std::optional<PreferredTypeAttr> from(const TokenContext &t);

  Type type(void) const;
  Type type_token(void) const;
};

static_assert(sizeof(PreferredTypeAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
