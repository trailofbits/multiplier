// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>
#include <filesystem>
#include <memory>
#include <optional>
#include <vector>

#include "../Iterator.h"
#include "../Types.h"
#include "../Token.h"
#include "../Use.h"

#include "AttrKind.h"
#include "TypeAttr.h"

namespace mx {
class Attr;
class ObjCKindOfAttr;
class TypeAttr;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using ObjCKindOfAttrRange = DerivedEntityRange<AttrIterator, ObjCKindOfAttr>;
using ObjCKindOfAttrContainingTokenRange = DerivedEntityRange<TokenContextIterator, ObjCKindOfAttr>;
class ObjCKindOfAttr : public TypeAttr {
 private:
  friend class FragmentImpl;
  friend class TypeAttr;
  friend class Attr;
 public:
  inline static ObjCKindOfAttrRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static ObjCKindOfAttrContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : ObjCKindOfAttr::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::OBJ_C_KIND_OF;
  }

  static std::optional<ObjCKindOfAttr> from(const TokenContext &c);
  static std::optional<ObjCKindOfAttr> from(const TypeAttr &parent);

  inline static std::optional<ObjCKindOfAttr> from(const std::optional<TypeAttr> &parent) {
    if (parent) {
      return ObjCKindOfAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ObjCKindOfAttr> from(const Attr &parent);

  inline static std::optional<ObjCKindOfAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return ObjCKindOfAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  std::string_view spelling(void) const;
};

static_assert(sizeof(ObjCKindOfAttr) == sizeof(TypeAttr));

#endif
} // namespace mx
