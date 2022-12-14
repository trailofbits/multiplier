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

#include "OMPExecutableDirective.h"
#include "StmtKind.h"

namespace mx {
class OMPExecutableDirective;
class OMPFlushDirective;
class Stmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class OMPFlushDirective : public OMPExecutableDirective {
 private:
  friend class FragmentImpl;
  friend class OMPExecutableDirective;
  friend class Stmt;
 public:
  inline static gap::generator<OMPFlushDirective> in(const Fragment &frag) {
    for(auto e : in_internal(frag)) {
      if(auto d = from(e)) {
        co_yield *d;
      }
    }
  }

  inline static gap::generator<OMPFlushDirective> containing(const Token &tok) {
    for(auto ctx = TokenContext::of(tok); ctx.has_value(); ctx = ctx->parent()) {
      if(auto d = from(*ctx)) {
        co_yield *d;
      }
    }
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : OMPFlushDirective::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::OMP_FLUSH_DIRECTIVE;
  }

  static gap::generator<OMPFlushDirective> containing(const Decl &decl);
  static gap::generator<OMPFlushDirective> containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<OMPFlushDirective> from(const TokenContext &c);
  static std::optional<OMPFlushDirective> from(const OMPExecutableDirective &parent);

  inline static std::optional<OMPFlushDirective> from(const std::optional<OMPExecutableDirective> &parent) {
    if (parent) {
      return OMPFlushDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<OMPFlushDirective> from(const Stmt &parent);

  inline static std::optional<OMPFlushDirective> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return OMPFlushDirective::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

};

static_assert(sizeof(OMPFlushDirective) == sizeof(OMPExecutableDirective));

#endif
} // namespace mx
