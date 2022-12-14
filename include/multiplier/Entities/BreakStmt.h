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
class BreakStmt;
class Stmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using BreakStmtContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, BreakStmt>;

class BreakStmt : public Stmt {
 private:
  friend class FragmentImpl;
  friend class Stmt;
 public:
  inline static gap::generator<BreakStmt> in(const Fragment &frag) {
    for(auto e : in_internal(frag)) {
      if(auto d = from(e)) {
        co_yield *d;
      }
    }
  }

  inline static gap::generator<BreakStmt> containing(const Token &tok) {
    for(auto ctx = TokenContext::of(tok); ctx.has_value(); ctx = ctx->parent()) {
      if(auto d = from(*ctx)) {
        co_yield *d;
      }
    }
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : BreakStmt::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::BREAK_STMT;
  }

  static BreakStmtContainingStmtRange containing(const Decl &decl);
  static BreakStmtContainingStmtRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<BreakStmt> from(const TokenContext &c);
  static std::optional<BreakStmt> from(const Stmt &parent);

  inline static std::optional<BreakStmt> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return BreakStmt::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  Token break_token(void) const;
};

static_assert(sizeof(BreakStmt) == sizeof(Stmt));

#endif
} // namespace mx
