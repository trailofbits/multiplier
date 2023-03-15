// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Attr.h"

namespace mx {
class EntityProvider;
class Index;
class Attr;
class ObjCRuntimeNameAttr;
class Token;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class ObjCRuntimeNameAttr : public Attr {
 private:
  friend class FragmentImpl;
  friend class Attr;
 public:
  static gap::generator<ObjCRuntimeNameAttr> in(const Fragment &frag);
  static gap::generator<ObjCRuntimeNameAttr> in(const File &file);
  static gap::generator<ObjCRuntimeNameAttr> in(const Index &index);
  static gap::generator<ObjCRuntimeNameAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<ObjCRuntimeNameAttr> by_id(const Index &, EntityId);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::OBJ_C_RUNTIME_NAME;
  }

  static std::optional<ObjCRuntimeNameAttr> from(const Attr &parent);

  inline static std::optional<ObjCRuntimeNameAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return ObjCRuntimeNameAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ObjCRuntimeNameAttr> from(const Reference &r);
  static std::optional<ObjCRuntimeNameAttr> from(const TokenContext &t);

  std::string_view metadata_name(void) const;
};

static_assert(sizeof(ObjCRuntimeNameAttr) == sizeof(Attr));

#endif
} // namespace mx
