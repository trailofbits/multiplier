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
#include "CXX11NoReturnAttrSpelling.h"
#include "InheritableAttr.h"

namespace mx {
class Attr;
class CXX11NoReturnAttr;
class InheritableAttr;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using CXX11NoReturnAttrRange = DerivedEntityRange<AttrIterator, CXX11NoReturnAttr>;
using CXX11NoReturnAttrContainingTokenRange = DerivedEntityRange<TokenContextIterator, CXX11NoReturnAttr>;
class CXX11NoReturnAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  inline static CXX11NoReturnAttrRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static CXX11NoReturnAttrContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(tok.context());
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : CXX11NoReturnAttr::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::CXX11_NO_RETURN;
  }

  static std::optional<CXX11NoReturnAttr> from(const TokenContext &c);
  static std::optional<CXX11NoReturnAttr> from(const InheritableAttr &parent);

  inline static std::optional<CXX11NoReturnAttr> from(const std::optional<InheritableAttr> &parent) {
    if (parent) {
      return CXX11NoReturnAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<CXX11NoReturnAttr> from(const Attr &parent);

  inline static std::optional<CXX11NoReturnAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return CXX11NoReturnAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  CXX11NoReturnAttrSpelling semantic_spelling(void) const;
};

static_assert(sizeof(CXX11NoReturnAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
