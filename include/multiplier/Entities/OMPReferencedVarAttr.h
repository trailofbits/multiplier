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

#include "Attr.h"
#include "AttrKind.h"

namespace mx {
class Attr;
class Expr;
class OMPReferencedVarAttr;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using OMPReferencedVarAttrContainingTokenRange = DerivedEntityRange<TokenContextIterator, OMPReferencedVarAttr>;
class OMPReferencedVarAttr : public Attr {
 private:
  friend class FragmentImpl;
  friend class Attr;
 public:
  inline static gap::generator<OMPReferencedVarAttr> in(const Fragment &frag) {
    for(auto e : in_internal(frag)) {
      if(auto d = from(e)) {
        co_yield *d;
      }
    }
  }

  inline static OMPReferencedVarAttrContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : OMPReferencedVarAttr::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::OMP_REFERENCED_VAR;
  }

  static std::optional<OMPReferencedVarAttr> from(const TokenContext &c);
  static std::optional<OMPReferencedVarAttr> from(const Attr &parent);

  inline static std::optional<OMPReferencedVarAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return OMPReferencedVarAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  Expr reference(void) const;
  std::string_view spelling(void) const;
};

static_assert(sizeof(OMPReferencedVarAttr) == sizeof(Attr));

#endif
} // namespace mx
