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
class ObjCDesignatedInitializerAttr;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using ObjCDesignatedInitializerAttrRange = DerivedEntityRange<AttrIterator, ObjCDesignatedInitializerAttr>;
using ObjCDesignatedInitializerAttrContainingTokenRange = DerivedEntityRange<TokenContextIterator, ObjCDesignatedInitializerAttr>;
class ObjCDesignatedInitializerAttr : public Attr {
 private:
  friend class FragmentImpl;
  friend class Attr;
 public:
  inline static ObjCDesignatedInitializerAttrRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static ObjCDesignatedInitializerAttrContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : ObjCDesignatedInitializerAttr::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::OBJ_C_DESIGNATED_INITIALIZER;
  }

  static std::optional<ObjCDesignatedInitializerAttr> from(const TokenContext &c);
  static std::optional<ObjCDesignatedInitializerAttr> from(const Attr &parent);

  inline static std::optional<ObjCDesignatedInitializerAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return ObjCDesignatedInitializerAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  std::string_view spelling(void) const;
};

static_assert(sizeof(ObjCDesignatedInitializerAttr) == sizeof(Attr));

#endif
} // namespace mx
