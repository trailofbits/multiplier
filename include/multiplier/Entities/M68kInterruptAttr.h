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
class InheritableAttr;
class M68kInterruptAttr;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using M68kInterruptAttrRange = DerivedEntityRange<AttrIterator, M68kInterruptAttr>;
using M68kInterruptAttrContainingTokenRange = DerivedEntityRange<TokenContextIterator, M68kInterruptAttr>;
class M68kInterruptAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  inline static M68kInterruptAttrRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static M68kInterruptAttrContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : M68kInterruptAttr::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::M68K_INTERRUPT;
  }

  static std::optional<M68kInterruptAttr> from(const TokenContext &c);
  static std::optional<M68kInterruptAttr> from(const InheritableAttr &parent);

  inline static std::optional<M68kInterruptAttr> from(const std::optional<InheritableAttr> &parent) {
    if (parent) {
      return M68kInterruptAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<M68kInterruptAttr> from(const Attr &parent);

  inline static std::optional<M68kInterruptAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return M68kInterruptAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  std::string_view spelling(void) const;
};

static_assert(sizeof(M68kInterruptAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
