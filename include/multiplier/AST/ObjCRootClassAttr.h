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
class ObjCRootClassAttr;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class ObjCRootClassAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<ObjCRootClassAttr> in(const Index &index);
  static gap::generator<ObjCRootClassAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<ObjCRootClassAttr> by_id(const Index &, EntityId);
  static gap::generator<ObjCRootClassAttr> in(const Fragment &frag);
  static gap::generator<ObjCRootClassAttr> in(const File &file);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::OBJ_C_ROOT_CLASS;
  }

  static std::optional<ObjCRootClassAttr> from_base(const Attr &parent);
  inline static std::optional<ObjCRootClassAttr> from(const Attr &parent) {
    return from_base(parent);
  }
  static std::optional<ObjCRootClassAttr> from(const std::optional<Attr> &parent);
  static std::optional<ObjCRootClassAttr> from(const Reference &r);
  static std::optional<ObjCRootClassAttr> from(const VariantEntity &e);
  static std::optional<ObjCRootClassAttr> from(const TokenContext &t);

};

static_assert(sizeof(ObjCRootClassAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx