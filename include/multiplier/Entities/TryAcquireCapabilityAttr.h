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
#include "TryAcquireCapabilityAttrSpelling.h"

namespace mx {
class Attr;
class Expr;
class InheritableAttr;
class TryAcquireCapabilityAttr;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using TryAcquireCapabilityAttrContainingTokenRange = DerivedEntityRange<TokenContextIterator, TryAcquireCapabilityAttr>;
class TryAcquireCapabilityAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  inline static gap::generator<TryAcquireCapabilityAttr> in(const Fragment &frag) {
    for(auto e : in_internal(frag)) {
      if(auto d = from(e)) {
        co_yield *d;
      }
    }
  }

  inline static TryAcquireCapabilityAttrContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : TryAcquireCapabilityAttr::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::TRY_ACQUIRE_CAPABILITY;
  }

  static std::optional<TryAcquireCapabilityAttr> from(const TokenContext &c);
  static std::optional<TryAcquireCapabilityAttr> from(const InheritableAttr &parent);

  inline static std::optional<TryAcquireCapabilityAttr> from(const std::optional<InheritableAttr> &parent) {
    if (parent) {
      return TryAcquireCapabilityAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<TryAcquireCapabilityAttr> from(const Attr &parent);

  inline static std::optional<TryAcquireCapabilityAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return TryAcquireCapabilityAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  TryAcquireCapabilityAttrSpelling semantic_spelling(void) const;
  std::string_view spelling(void) const;
  Expr success_value(void) const;
  bool is_shared(void) const;
};

static_assert(sizeof(TryAcquireCapabilityAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
