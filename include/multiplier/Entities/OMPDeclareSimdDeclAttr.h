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

#include "Attr.h"
#include "AttrKind.h"
#include "OMPDeclareSimdDeclAttrBranchStateTy.h"

namespace mx {
class Attr;
class Expr;
class OMPDeclareSimdDeclAttr;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using OMPDeclareSimdDeclAttrRange = DerivedEntityRange<AttrIterator, OMPDeclareSimdDeclAttr>;
using OMPDeclareSimdDeclAttrContainingTokenRange = DerivedEntityRange<TokenContextIterator, OMPDeclareSimdDeclAttr>;
class OMPDeclareSimdDeclAttr : public Attr {
 private:
  friend class FragmentImpl;
  friend class Attr;
 public:
  inline static OMPDeclareSimdDeclAttrRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static OMPDeclareSimdDeclAttrContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : OMPDeclareSimdDeclAttr::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::OMP_DECLARE_SIMD_DECL;
  }

  static std::optional<OMPDeclareSimdDeclAttr> from(const TokenContext &c);
  static std::optional<OMPDeclareSimdDeclAttr> from(const Attr &parent);

  inline static std::optional<OMPDeclareSimdDeclAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return OMPDeclareSimdDeclAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  OMPDeclareSimdDeclAttrBranchStateTy branch_state(void) const;
  Expr simdlen(void) const;
  std::string_view spelling(void) const;
};

static_assert(sizeof(OMPDeclareSimdDeclAttr) == sizeof(Attr));

#endif
} // namespace mx
