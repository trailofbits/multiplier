// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <multiplier/AST/Attr.h>

namespace mx {
class EntityProvider;
class Fragment;
class Index;
class Attr;
class File;
class ObjCDirectMembersAttr;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT ObjCDirectMembersAttr : public Attr {
 private:
  friend class FragmentImpl;
  friend class Attr;
 public:
  static gap::generator<ObjCDirectMembersAttr> in(const Index &index);
  static gap::generator<ObjCDirectMembersAttr> in(const Fragment &frag);
  static gap::generator<ObjCDirectMembersAttr> in(const File &file);
  static gap::generator<ObjCDirectMembersAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::OBJ_C_DIRECT_MEMBERS;
  }

  static std::optional<ObjCDirectMembersAttr> by_id(const Index &, EntityId);

  static std::optional<ObjCDirectMembersAttr> from_base(const Attr &parent);
  inline static std::optional<ObjCDirectMembersAttr> from(const Attr &parent) {
    return from_base(parent);
  }
  static std::optional<ObjCDirectMembersAttr> from(const std::optional<Attr> &parent);
  static std::optional<ObjCDirectMembersAttr> from(const Reference &r);
  static std::optional<ObjCDirectMembersAttr> from(const VariantEntity &e);
  static std::optional<ObjCDirectMembersAttr> from(const TokenContext &t);

};

static_assert(sizeof(ObjCDirectMembersAttr) == sizeof(Attr));

#endif
} // namespace mx
