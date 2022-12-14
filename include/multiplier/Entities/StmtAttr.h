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
class StmtAttr;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class StmtAttr : public Attr {
 private:
  friend class FragmentImpl;
  friend class Attr;
 public:
  inline static gap::generator<StmtAttr> in(const Fragment &frag) {
    for(auto e : in_internal(frag)) {
      if(auto d = from(e)) {
        co_yield *d;
      }
    }
  }

  inline static gap::generator<StmtAttr> containing(const Token &tok) {
    for(auto ctx = TokenContext::of(tok); ctx.has_value(); ctx = ctx->parent()) {
      if(auto d = from(*ctx)) {
        co_yield *d;
      }
    }
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : StmtAttr::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  static std::optional<StmtAttr> from(const TokenContext &c);
  static std::optional<StmtAttr> from(const Attr &parent);

  inline static std::optional<StmtAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return StmtAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

};

static_assert(sizeof(StmtAttr) == sizeof(Attr));

#endif
} // namespace mx
