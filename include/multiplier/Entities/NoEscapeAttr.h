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
class NoEscapeAttr;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using NoEscapeAttrRange = DerivedEntityRange<AttrIterator, NoEscapeAttr>;
using NoEscapeAttrContainingTokenRange = DerivedEntityRange<TokenContextIterator, NoEscapeAttr>;
class NoEscapeAttr : public Attr {
 private:
  friend class FragmentImpl;
  friend class Attr;
 public:
  inline static NoEscapeAttrRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static NoEscapeAttrContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(tok.context());
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : NoEscapeAttr::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::NO_ESCAPE;
  }

  static std::optional<NoEscapeAttr> from(const TokenContext &c);
  static std::optional<NoEscapeAttr> from(const Attr &parent);

  inline static std::optional<NoEscapeAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return NoEscapeAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  std::string_view spelling(void) const;
};

static_assert(sizeof(NoEscapeAttr) == sizeof(Attr));

#endif
} // namespace mx
