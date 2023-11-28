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
class ObjCDirectAttr;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class ObjCDirectAttr : public Attr {
 private:
  friend class FragmentImpl;
  friend class Attr;
 public:
  static gap::generator<ObjCDirectAttr> in(const Index &index);
  static gap::generator<ObjCDirectAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<ObjCDirectAttr> by_id(const Index &, EntityId);
  static gap::generator<ObjCDirectAttr> in(const Fragment &frag);
  static gap::generator<ObjCDirectAttr> in(const File &file);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::OBJ_C_DIRECT;
  }

  static std::optional<ObjCDirectAttr> from_base(const Attr &parent);
  inline static std::optional<ObjCDirectAttr> from(const Attr &parent) {
    return from_base(parent);
  }
  static std::optional<ObjCDirectAttr> from(const std::optional<Attr> &parent);
  static std::optional<ObjCDirectAttr> from(const Reference &r);
  static std::optional<ObjCDirectAttr> from(const VariantEntity &e);
  static std::optional<ObjCDirectAttr> from(const TokenContext &t);

};

static_assert(sizeof(ObjCDirectAttr) == sizeof(Attr));

#endif
} // namespace mx
