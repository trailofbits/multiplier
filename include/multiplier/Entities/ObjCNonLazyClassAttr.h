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

#include "Attr.h"
#include "AttrKind.h"

namespace mx {
class Attr;
class ObjCNonLazyClassAttr;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using ObjCNonLazyClassAttrRange = DerivedEntityRange<AttrIterator, ObjCNonLazyClassAttr>;
using ObjCNonLazyClassAttrContainingTokenRange = DerivedEntityRange<TokenContextIterator, ObjCNonLazyClassAttr>;
class ObjCNonLazyClassAttr : public Attr {
 private:
  friend class FragmentImpl;
  friend class Attr;
 public:
  inline static ObjCNonLazyClassAttrRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static ObjCNonLazyClassAttrContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : ObjCNonLazyClassAttr::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::OBJ_C_NON_LAZY_CLASS;
  }

  static std::optional<ObjCNonLazyClassAttr> from(const TokenContext &c);
  static std::optional<ObjCNonLazyClassAttr> from(const Attr &parent);

  inline static std::optional<ObjCNonLazyClassAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return ObjCNonLazyClassAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  std::string_view spelling(void) const;
};

static_assert(sizeof(ObjCNonLazyClassAttr) == sizeof(Attr));

#endif
} // namespace mx
