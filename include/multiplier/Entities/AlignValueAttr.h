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
class AlignValueAttr;
class Attr;
class Expr;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using AlignValueAttrRange = DerivedEntityRange<AttrIterator, AlignValueAttr>;
using AlignValueAttrContainingTokenRange = DerivedEntityRange<TokenContextIterator, AlignValueAttr>;
class AlignValueAttr : public Attr {
 private:
  friend class FragmentImpl;
  friend class Attr;
 public:
  inline static AlignValueAttrRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static AlignValueAttrContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(tok.context());
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : AlignValueAttr::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::ALIGN_VALUE;
  }

  static std::optional<AlignValueAttr> from(const TokenContext &c);
  static std::optional<AlignValueAttr> from(const Attr &parent);

  inline static std::optional<AlignValueAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return AlignValueAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  Expr alignment(void) const;
  std::string_view spelling(void) const;
};

static_assert(sizeof(AlignValueAttr) == sizeof(Attr));

#endif
} // namespace mx
