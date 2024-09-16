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
class ObjCExplicitProtocolImplAttr;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT ObjCExplicitProtocolImplAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<ObjCExplicitProtocolImplAttr> in(const Index &index);
  static gap::generator<ObjCExplicitProtocolImplAttr> in(const Fragment &frag);
  static gap::generator<ObjCExplicitProtocolImplAttr> in(const File &file);
  static gap::generator<ObjCExplicitProtocolImplAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::OBJ_C_EXPLICIT_PROTOCOL_IMPL;
  }

  static std::optional<ObjCExplicitProtocolImplAttr> by_id(const Index &, EntityId);

  static std::optional<ObjCExplicitProtocolImplAttr> from_base(const Attr &parent);
  inline static std::optional<ObjCExplicitProtocolImplAttr> from(const Attr &parent) {
    return from_base(parent);
  }
  static std::optional<ObjCExplicitProtocolImplAttr> from(const std::optional<Attr> &parent);
  static std::optional<ObjCExplicitProtocolImplAttr> from(const Reference &r);
  static std::optional<ObjCExplicitProtocolImplAttr> from(const VariantEntity &e);
  static std::optional<ObjCExplicitProtocolImplAttr> from(const TokenContext &t);

};

static_assert(sizeof(ObjCExplicitProtocolImplAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
