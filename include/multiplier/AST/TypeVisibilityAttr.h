// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <multiplier/AST/InheritableAttr.h>
#include <multiplier/AST/TypeVisibilityAttrVisibilityType.h>

namespace mx {
class EntityProvider;
class Fragment;
class Index;
class Attr;
class File;
class InheritableAttr;
class Token;
class TypeVisibilityAttr;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT TypeVisibilityAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<TypeVisibilityAttr> in(const Index &index);
  static gap::generator<TypeVisibilityAttr> in(const Fragment &frag);
  static gap::generator<TypeVisibilityAttr> in(const File &file);
  static gap::generator<TypeVisibilityAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::TYPE_VISIBILITY;
  }

  static std::optional<TypeVisibilityAttr> by_id(const Index &, EntityId);

  static std::optional<TypeVisibilityAttr> from_base(const Attr &parent);
  inline static std::optional<TypeVisibilityAttr> from(const Attr &parent) {
    return from_base(parent);
  }
  static std::optional<TypeVisibilityAttr> from(const std::optional<Attr> &parent);
  static std::optional<TypeVisibilityAttr> from(const Reference &r);
  static std::optional<TypeVisibilityAttr> from(const VariantEntity &e);
  static std::optional<TypeVisibilityAttr> from(const TokenContext &t);

  TypeVisibilityAttrVisibilityType visibility(void) const;
};

static_assert(sizeof(TypeVisibilityAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
