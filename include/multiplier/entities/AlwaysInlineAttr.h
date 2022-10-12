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

#include "AlwaysInlineAttrSpelling.h"
#include "AttrKind.h"
#include "InheritableAttr.h"

namespace mx {
class AlwaysInlineAttr;
class Attr;
class InheritableAttr;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using AlwaysInlineAttrRange = DerivedEntityRange<AttrIterator, AlwaysInlineAttr>;
using AlwaysInlineAttrContainingTokenRange = DerivedEntityRange<TokenContextIterator, AlwaysInlineAttr>;
class AlwaysInlineAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  inline static AlwaysInlineAttrRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static AlwaysInlineAttrContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : AlwaysInlineAttr::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::ALWAYS_INLINE;
  }

  static std::optional<AlwaysInlineAttr> from(const TokenContext &c);
  static std::optional<AlwaysInlineAttr> from(const InheritableAttr &parent);

  inline static std::optional<AlwaysInlineAttr> from(const std::optional<InheritableAttr> &parent) {
    if (parent) {
      return AlwaysInlineAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<AlwaysInlineAttr> from(const Attr &parent);

  inline static std::optional<AlwaysInlineAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return AlwaysInlineAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  AlwaysInlineAttrSpelling semantic_spelling(void) const;
  std::string_view spelling(void) const;
};

static_assert(sizeof(AlwaysInlineAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
