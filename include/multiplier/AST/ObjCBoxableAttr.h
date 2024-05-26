// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
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
class ObjCBoxableAttr;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT ObjCBoxableAttr : public Attr {
 private:
  friend class FragmentImpl;
  friend class Attr;
 public:
  static gap::generator<ObjCBoxableAttr> in(const Index &index);
  static gap::generator<ObjCBoxableAttr> in(const Fragment &frag);
  static gap::generator<ObjCBoxableAttr> in(const File &file);
  static gap::generator<ObjCBoxableAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::OBJ_C_BOXABLE;
  }

  static std::optional<ObjCBoxableAttr> by_id(const Index &, EntityId);

  static std::optional<ObjCBoxableAttr> from_base(const Attr &parent);
  inline static std::optional<ObjCBoxableAttr> from(const Attr &parent) {
    return from_base(parent);
  }
  static std::optional<ObjCBoxableAttr> from(const std::optional<Attr> &parent);
  static std::optional<ObjCBoxableAttr> from(const Reference &r);
  static std::optional<ObjCBoxableAttr> from(const VariantEntity &e);
  static std::optional<ObjCBoxableAttr> from(const TokenContext &t);

};

static_assert(sizeof(ObjCBoxableAttr) == sizeof(Attr));

#endif
} // namespace mx
