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
class C11NoReturnAttr;
class InheritableAttr;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using C11NoReturnAttrRange = DerivedEntityRange<AttrIterator, C11NoReturnAttr>;
using C11NoReturnAttrContainingTokenRange = DerivedEntityRange<TokenContextIterator, C11NoReturnAttr>;
class C11NoReturnAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  inline static C11NoReturnAttrRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static C11NoReturnAttrContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : C11NoReturnAttr::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::C11_NO_RETURN;
  }

  static std::optional<C11NoReturnAttr> from(const TokenContext &c);
  static std::optional<C11NoReturnAttr> from(const InheritableAttr &parent);

  inline static std::optional<C11NoReturnAttr> from(const std::optional<InheritableAttr> &parent) {
    if (parent) {
      return C11NoReturnAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<C11NoReturnAttr> from(const Attr &parent);

  inline static std::optional<C11NoReturnAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return C11NoReturnAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  std::string_view spelling(void) const;
};

static_assert(sizeof(C11NoReturnAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
