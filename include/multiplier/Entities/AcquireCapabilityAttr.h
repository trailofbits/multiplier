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

#include "AcquireCapabilityAttrSpelling.h"
#include "AttrKind.h"
#include "InheritableAttr.h"

namespace mx {
class AcquireCapabilityAttr;
class Attr;
class InheritableAttr;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using AcquireCapabilityAttrRange = DerivedEntityRange<AttrIterator, AcquireCapabilityAttr>;
using AcquireCapabilityAttrContainingTokenRange = DerivedEntityRange<TokenContextIterator, AcquireCapabilityAttr>;
class AcquireCapabilityAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  inline static AcquireCapabilityAttrRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static AcquireCapabilityAttrContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : AcquireCapabilityAttr::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::ACQUIRE_CAPABILITY;
  }

  static std::optional<AcquireCapabilityAttr> from(const TokenContext &c);
  static std::optional<AcquireCapabilityAttr> from(const InheritableAttr &parent);

  inline static std::optional<AcquireCapabilityAttr> from(const std::optional<InheritableAttr> &parent) {
    if (parent) {
      return AcquireCapabilityAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<AcquireCapabilityAttr> from(const Attr &parent);

  inline static std::optional<AcquireCapabilityAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return AcquireCapabilityAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  AcquireCapabilityAttrSpelling semantic_spelling(void) const;
  std::string_view spelling(void) const;
  bool is_shared(void) const;
};

static_assert(sizeof(AcquireCapabilityAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
