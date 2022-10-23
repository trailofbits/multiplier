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
class BTFTypeTagAttr;
class TypeAttr;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using BTFTypeTagAttrRange = DerivedEntityRange<AttrIterator, BTFTypeTagAttr>;
using BTFTypeTagAttrContainingTokenRange = DerivedEntityRange<TokenContextIterator, BTFTypeTagAttr>;
class BTFTypeTagAttr : public TypeAttr {
 private:
  friend class FragmentImpl;
  friend class TypeAttr;
  friend class Attr;
 public:
  inline static BTFTypeTagAttrRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static BTFTypeTagAttrContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : BTFTypeTagAttr::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::BTF_TYPE_TAG;
  }

  static std::optional<BTFTypeTagAttr> from(const TokenContext &c);
  static std::optional<BTFTypeTagAttr> from(const TypeAttr &parent);

  inline static std::optional<BTFTypeTagAttr> from(const std::optional<TypeAttr> &parent) {
    if (parent) {
      return BTFTypeTagAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<BTFTypeTagAttr> from(const Attr &parent);

  inline static std::optional<BTFTypeTagAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return BTFTypeTagAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  std::string_view btf_type_tag(void) const;
  std::string_view spelling(void) const;
};

static_assert(sizeof(BTFTypeTagAttr) == sizeof(TypeAttr));

#endif
} // namespace mx