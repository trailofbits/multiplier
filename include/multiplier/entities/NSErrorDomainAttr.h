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
class NSErrorDomainAttr;
class VarDecl;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using NSErrorDomainAttrRange = DerivedEntityRange<AttrIterator, NSErrorDomainAttr>;
using NSErrorDomainAttrContainingTokenRange = DerivedEntityRange<TokenContextIterator, NSErrorDomainAttr>;
class NSErrorDomainAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  inline static NSErrorDomainAttrRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static NSErrorDomainAttrContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : NSErrorDomainAttr::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::NS_ERROR_DOMAIN;
  }

  static std::optional<NSErrorDomainAttr> from(const TokenContext &c);
  static std::optional<NSErrorDomainAttr> from(const InheritableAttr &parent);

  inline static std::optional<NSErrorDomainAttr> from(const std::optional<InheritableAttr> &parent) {
    if (parent) {
      return NSErrorDomainAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<NSErrorDomainAttr> from(const Attr &parent);

  inline static std::optional<NSErrorDomainAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return NSErrorDomainAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  VarDecl error_domain(void) const;
  std::string_view spelling(void) const;
};

static_assert(sizeof(NSErrorDomainAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
