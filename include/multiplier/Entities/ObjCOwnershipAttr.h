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

#include "AttrKind.h"
#include "InheritableAttr.h"

namespace mx {
class Attr;
class InheritableAttr;
class ObjCOwnershipAttr;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using ObjCOwnershipAttrContainingTokenRange = DerivedEntityRange<TokenContextIterator, ObjCOwnershipAttr>;
class ObjCOwnershipAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  inline static gap::generator<ObjCOwnershipAttr> in(const Fragment &frag) {
    for(auto e : in_internal(frag)) {
      if(auto d = from(e)) {
        co_yield *d;
      }
    }
  }

  inline static ObjCOwnershipAttrContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : ObjCOwnershipAttr::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::OBJ_C_OWNERSHIP;
  }

  static std::optional<ObjCOwnershipAttr> from(const TokenContext &c);
  static std::optional<ObjCOwnershipAttr> from(const InheritableAttr &parent);

  inline static std::optional<ObjCOwnershipAttr> from(const std::optional<InheritableAttr> &parent) {
    if (parent) {
      return ObjCOwnershipAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ObjCOwnershipAttr> from(const Attr &parent);

  inline static std::optional<ObjCOwnershipAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return ObjCOwnershipAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  std::string_view spelling(void) const;
};

static_assert(sizeof(ObjCOwnershipAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
