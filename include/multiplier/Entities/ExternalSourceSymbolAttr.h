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

namespace mx {
class Attr;
class ExternalSourceSymbolAttr;
class InheritableAttr;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using ExternalSourceSymbolAttrRange = DerivedEntityRange<AttrIterator, ExternalSourceSymbolAttr>;
using ExternalSourceSymbolAttrContainingTokenRange = DerivedEntityRange<TokenContextIterator, ExternalSourceSymbolAttr>;
class ExternalSourceSymbolAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  inline static ExternalSourceSymbolAttrRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static ExternalSourceSymbolAttrContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : ExternalSourceSymbolAttr::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::EXTERNAL_SOURCE_SYMBOL;
  }

  static std::optional<ExternalSourceSymbolAttr> from(const TokenContext &c);
  static std::optional<ExternalSourceSymbolAttr> from(const InheritableAttr &parent);

  inline static std::optional<ExternalSourceSymbolAttr> from(const std::optional<InheritableAttr> &parent) {
    if (parent) {
      return ExternalSourceSymbolAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ExternalSourceSymbolAttr> from(const Attr &parent);

  inline static std::optional<ExternalSourceSymbolAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return ExternalSourceSymbolAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  std::string_view defined_in(void) const;
  bool generated_declaration(void) const;
  std::string_view language(void) const;
  std::string_view spelling(void) const;
};

static_assert(sizeof(ExternalSourceSymbolAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
