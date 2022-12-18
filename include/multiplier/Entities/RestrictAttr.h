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
#include "InheritableAttr.h"
#include "RestrictAttrSpelling.h"

namespace mx {
class Attr;
class InheritableAttr;
class RestrictAttr;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using RestrictAttrRange = DerivedEntityRange<AttrIterator, RestrictAttr>;
using RestrictAttrContainingTokenRange = DerivedEntityRange<TokenContextIterator, RestrictAttr>;
class RestrictAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  inline static RestrictAttrRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static RestrictAttrContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(tok.context());
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : RestrictAttr::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::RESTRICT;
  }

  static std::optional<RestrictAttr> from(const TokenContext &c);
  static std::optional<RestrictAttr> from(const InheritableAttr &parent);

  inline static std::optional<RestrictAttr> from(const std::optional<InheritableAttr> &parent) {
    if (parent) {
      return RestrictAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<RestrictAttr> from(const Attr &parent);

  inline static std::optional<RestrictAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return RestrictAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  RestrictAttrSpelling semantic_spelling(void) const;
  std::string_view spelling(void) const;
};

static_assert(sizeof(RestrictAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
