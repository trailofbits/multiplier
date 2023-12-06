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
class MSGuidDecl;
class Token;
class UuidAttr;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT UuidAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<UuidAttr> in(const Index &index);
  static gap::generator<UuidAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<UuidAttr> by_id(const Index &, EntityId);
  static gap::generator<UuidAttr> in(const Fragment &frag);
  static gap::generator<UuidAttr> in(const File &file);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::UUID;
  }

  static std::optional<UuidAttr> from_base(const Attr &parent);
  inline static std::optional<UuidAttr> from(const Attr &parent) {
    return from_base(parent);
  }
  static std::optional<UuidAttr> from(const std::optional<Attr> &parent);
  static std::optional<UuidAttr> from(const Reference &r);
  static std::optional<UuidAttr> from(const VariantEntity &e);
  static std::optional<UuidAttr> from(const TokenContext &t);

  std::string_view guid(void) const;
  MSGuidDecl guid_declaration(void) const;
};

static_assert(sizeof(UuidAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
