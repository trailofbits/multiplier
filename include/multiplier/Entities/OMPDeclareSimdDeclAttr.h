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
#include "OMPDeclareSimdDeclAttrBranchStateTy.h"

namespace mx {
class Attr;
class Expr;
class OMPDeclareSimdDeclAttr;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class OMPDeclareSimdDeclAttr : public Attr {
 private:
  friend class FragmentImpl;
  friend class Attr;
 public:
  inline static gap::generator<OMPDeclareSimdDeclAttr> in(const Fragment &frag) {
    for (auto e : in_internal(frag)) {
      if (auto d = from(e)) {
        co_yield *d;
      }
    }
  }

  inline static gap::generator<OMPDeclareSimdDeclAttr> containing(const Token &tok) {
    for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
      if (auto d = from(*ctx)) {
        co_yield *d;
      }
    }
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : OMPDeclareSimdDeclAttr::containing(tok)) {
      if (parent.id() == id_) { return true; }
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
};

static_assert(sizeof(OMPDeclareSimdDeclAttr) == sizeof(Attr));

#endif
} // namespace mx
