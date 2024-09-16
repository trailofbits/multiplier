// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <multiplier/AST/EnumExtensibilityAttrKind.h>
#include <multiplier/AST/InheritableAttr.h>

namespace mx {
class EntityProvider;
class Fragment;
class Index;
class Attr;
class EnumExtensibilityAttr;
class File;
class InheritableAttr;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT EnumExtensibilityAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<EnumExtensibilityAttr> in(const Index &index);
  static gap::generator<EnumExtensibilityAttr> in(const Fragment &frag);
  static gap::generator<EnumExtensibilityAttr> in(const File &file);
  static gap::generator<EnumExtensibilityAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::ENUM_EXTENSIBILITY;
  }

  static std::optional<EnumExtensibilityAttr> by_id(const Index &, EntityId);

  static std::optional<EnumExtensibilityAttr> from_base(const Attr &parent);
  inline static std::optional<EnumExtensibilityAttr> from(const Attr &parent) {
    return from_base(parent);
  }
  static std::optional<EnumExtensibilityAttr> from(const std::optional<Attr> &parent);
  static std::optional<EnumExtensibilityAttr> from(const Reference &r);
  static std::optional<EnumExtensibilityAttr> from(const VariantEntity &e);
  static std::optional<EnumExtensibilityAttr> from(const TokenContext &t);

  EnumExtensibilityAttrKind extensibility(void) const;
};

static_assert(sizeof(EnumExtensibilityAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
