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
class DLLImportStaticLocalAttr;
class InheritableAttr;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using DLLImportStaticLocalAttrContainingTokenRange = DerivedEntityRange<TokenContextIterator, DLLImportStaticLocalAttr>;
class DLLImportStaticLocalAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  inline static gap::generator<DLLImportStaticLocalAttr> in(const Fragment &frag) {
    for(auto e : in_internal(frag)) {
      if(auto d = from(e)) {
        co_yield *d;
      }
    }
  }

  inline static DLLImportStaticLocalAttrContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : DLLImportStaticLocalAttr::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::DLL_IMPORT_STATIC_LOCAL;
  }

  static std::optional<DLLImportStaticLocalAttr> from(const TokenContext &c);
  static std::optional<DLLImportStaticLocalAttr> from(const InheritableAttr &parent);

  inline static std::optional<DLLImportStaticLocalAttr> from(const std::optional<InheritableAttr> &parent) {
    if (parent) {
      return DLLImportStaticLocalAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<DLLImportStaticLocalAttr> from(const Attr &parent);

  inline static std::optional<DLLImportStaticLocalAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return DLLImportStaticLocalAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  std::string_view spelling(void) const;
};

static_assert(sizeof(DLLImportStaticLocalAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
