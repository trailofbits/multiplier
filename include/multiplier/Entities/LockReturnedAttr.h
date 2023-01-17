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
class Expr;
class InheritableAttr;
class LockReturnedAttr;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class LockReturnedAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  inline static gap::generator<LockReturnedAttr> in(const Fragment &frag) {
    for(auto e : in_internal(frag)) {
      if(auto d = from(e)) {
        co_yield *d;
      }
    }
  }

  inline static gap::generator<LockReturnedAttr> containing(const Token &tok) {
    for(auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
      if(auto d = from(*ctx)) {
        co_yield *d;
      }
    }
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : LockReturnedAttr::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::LOCK_RETURNED;
  }

  static std::optional<LockReturnedAttr> from(const TokenContext &c);
  static std::optional<LockReturnedAttr> from(const InheritableAttr &parent);

  inline static std::optional<LockReturnedAttr> from(const std::optional<InheritableAttr> &parent) {
    if (parent) {
      return LockReturnedAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<LockReturnedAttr> from(const Attr &parent);

  inline static std::optional<LockReturnedAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return LockReturnedAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  Expr argument(void) const;
};

static_assert(sizeof(LockReturnedAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
