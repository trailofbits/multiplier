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
#include "CapabilityAttrSpelling.h"
#include "InheritableAttr.h"

namespace mx {
class Attr;
class CapabilityAttr;
class InheritableAttr;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using CapabilityAttrRange = DerivedEntityRange<AttrIterator, CapabilityAttr>;
using CapabilityAttrContainingTokenRange = DerivedEntityRange<TokenContextIterator, CapabilityAttr>;
class CapabilityAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  inline static CapabilityAttrRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static CapabilityAttrContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : CapabilityAttr::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::CAPABILITY;
  }

  static std::optional<CapabilityAttr> from(const TokenContext &c);
  static std::optional<CapabilityAttr> from(const InheritableAttr &parent);

  inline static std::optional<CapabilityAttr> from(const std::optional<InheritableAttr> &parent) {
    if (parent) {
      return CapabilityAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<CapabilityAttr> from(const Attr &parent);

  inline static std::optional<CapabilityAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return CapabilityAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  std::string_view name(void) const;
  CapabilityAttrSpelling semantic_spelling(void) const;
  std::string_view spelling(void) const;
  bool is_shared(void) const;
};

static_assert(sizeof(CapabilityAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
