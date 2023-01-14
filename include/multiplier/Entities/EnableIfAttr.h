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

namespace mx {
class Attr;
class EnableIfAttr;
class Expr;
class InheritableAttr;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using EnableIfAttrRange = DerivedEntityRange<AttrIterator, EnableIfAttr>;
using EnableIfAttrContainingTokenRange = DerivedEntityRange<TokenContextIterator, EnableIfAttr>;
class EnableIfAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  inline static EnableIfAttrRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static EnableIfAttrContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(tok.context());
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : EnableIfAttr::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::ENABLE_IF;
  }

  static std::optional<EnableIfAttr> from(const TokenContext &c);
  static std::optional<EnableIfAttr> from(const InheritableAttr &parent);

  inline static std::optional<EnableIfAttr> from(const std::optional<InheritableAttr> &parent) {
    if (parent) {
      return EnableIfAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<EnableIfAttr> from(const Attr &parent);

  inline static std::optional<EnableIfAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return EnableIfAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  Expr condition(void) const;
  std::string_view message(void) const;
};

static_assert(sizeof(EnableIfAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
