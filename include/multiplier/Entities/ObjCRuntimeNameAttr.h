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

#include <gap/core/generator.hpp>
#include "../Iterator.h"
#include "../Types.h"
#include "../Token.h"
#include "../Use.h"

#include "Attr.h"
#include "AttrKind.h"

namespace mx {
class Attr;
class ObjCRuntimeNameAttr;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using ObjCRuntimeNameAttrContainingTokenRange = DerivedEntityRange<TokenContextIterator, ObjCRuntimeNameAttr>;
class ObjCRuntimeNameAttr : public Attr {
 private:
  friend class FragmentImpl;
  friend class Attr;
 public:
  inline static gap::generator<ObjCRuntimeNameAttr> in(const Fragment &frag) {
    for(auto e : in_internal(frag)) {
      if(auto d = from(e)) {
        co_yield *d;
      }
    }
  }

  inline static ObjCRuntimeNameAttrContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : ObjCRuntimeNameAttr::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::OBJ_C_RUNTIME_NAME;
  }

  static std::optional<ObjCRuntimeNameAttr> from(const TokenContext &c);
  static std::optional<ObjCRuntimeNameAttr> from(const Attr &parent);

  inline static std::optional<ObjCRuntimeNameAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return ObjCRuntimeNameAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  std::string_view metadata_name(void) const;
  std::string_view spelling(void) const;
};

static_assert(sizeof(ObjCRuntimeNameAttr) == sizeof(Attr));

#endif
} // namespace mx
