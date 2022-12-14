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

#include "DeclUseSelector.h"
#include "Stmt.h"
#include "StmtKind.h"

namespace mx {
class Expr;
class IndirectGotoStmt;
class LabelDecl;
class Stmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using IndirectGotoStmtContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, IndirectGotoStmt>;

class IndirectGotoStmt : public Stmt {
 private:
  friend class FragmentImpl;
  friend class Stmt;
 public:
  inline static gap::generator<IndirectGotoStmt> in(const Fragment &frag) {
    for(auto e : in_internal(frag)) {
      if(auto d = from(e)) {
        co_yield *d;
      }
    }
  }

  inline static gap::generator<IndirectGotoStmt> containing(const Token &tok) {
    for(auto ctx = TokenContext::of(tok); ctx.has_value(); ctx = ctx->parent()) {
      if(auto d = from(*ctx)) {
        co_yield *d;
      }
    }
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : IndirectGotoStmt::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::INDIRECT_GOTO_STMT;
  }

  static IndirectGotoStmtContainingStmtRange containing(const Decl &decl);
  static IndirectGotoStmtContainingStmtRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<IndirectGotoStmt> from(const TokenContext &c);
  static std::optional<IndirectGotoStmt> from(const Stmt &parent);

  inline static std::optional<IndirectGotoStmt> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return IndirectGotoStmt::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  std::optional<LabelDecl> constant_target(void) const;
  Token goto_token(void) const;
  Token star_token(void) const;
  Expr target(void) const;
};

static_assert(sizeof(IndirectGotoStmt) == sizeof(Stmt));

#endif
} // namespace mx
