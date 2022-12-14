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

#include "Stmt.h"
#include "StmtKind.h"

namespace mx {
class NullStmt;
class Stmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class NullStmt : public Stmt {
 private:
  friend class FragmentImpl;
  friend class Stmt;
 public:
  inline static gap::generator<NullStmt> in(const Fragment &frag) {
    for(auto e : in_internal(frag)) {
      if(auto d = from(e)) {
        co_yield *d;
      }
    }
  }

  inline static gap::generator<NullStmt> containing(const Token &tok) {
    for(auto ctx = TokenContext::of(tok); ctx.has_value(); ctx = ctx->parent()) {
      if(auto d = from(*ctx)) {
        co_yield *d;
      }
    }
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : NullStmt::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::NULL_STMT;
  }

  static gap::generator<NullStmt> containing(const Decl &decl);
  static gap::generator<NullStmt> containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<NullStmt> from(const TokenContext &c);
  static std::optional<NullStmt> from(const Stmt &parent);

  inline static std::optional<NullStmt> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return NullStmt::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  Token semi_token(void) const;
  bool has_leading_empty_macro(void) const;
};

static_assert(sizeof(NullStmt) == sizeof(Stmt));

#endif
} // namespace mx
