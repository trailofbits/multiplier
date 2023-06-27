// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "InheritableAttr.h"

namespace mx {
class EntityProvider;
class Index;
class Attr;
class InheritableAttr;
class ObjCRequiresSuperAttr;
class Token;
namespace mx {
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class ObjCRequiresSuperAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<ObjCRequiresSuperAttr> in(const Fragment &frag);
  static gap::generator<ObjCRequiresSuperAttr> in(const File &file);
  static gap::generator<ObjCRequiresSuperAttr> in(const Index &index);
  static gap::generator<ObjCRequiresSuperAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<ObjCRequiresSuperAttr> by_id(const Index &, EntityId);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::OBJ_C_REQUIRES_SUPER;
  }

  static std::optional<ObjCRequiresSuperAttr> from(const Attr &parent);

  inline static std::optional<ObjCRequiresSuperAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return ObjCRequiresSuperAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ObjCRequiresSuperAttr> from(const Reference &r);
  static std::optional<ObjCRequiresSuperAttr> from(const TokenContext &t);

};

static_assert(sizeof(ObjCRequiresSuperAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
