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

#include "StmtKind.h"
#include "StmtUseSelector.h"
#include "SwitchCase.h"

namespace mx {
class CaseStmt;
class Expr;
class Stmt;
class SwitchCase;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using CaseStmtContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, CaseStmt>;

class CaseStmt : public SwitchCase {
 private:
  friend class FragmentImpl;
  friend class SwitchCase;
  friend class Stmt;
 public:
  inline static gap::generator<CaseStmt> in(const Fragment &frag) {
    for(auto e : in_internal(frag)) {
      if(auto d = from(e)) {
        co_yield *d;
      }
    }
  }

  inline static gap::generator<CaseStmt> containing(const Token &tok) {
    for(auto ctx = TokenContext::of(tok); ctx.has_value(); ctx = ctx->parent()) {
      if(auto d = from(*ctx)) {
        co_yield *d;
      }
    }
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : CaseStmt::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::CASE_STMT;
  }

  static CaseStmtContainingStmtRange containing(const Decl &decl);
  static CaseStmtContainingStmtRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<CaseStmt> from(const TokenContext &c);
  static std::optional<CaseStmt> from(const SwitchCase &parent);

  inline static std::optional<CaseStmt> from(const std::optional<SwitchCase> &parent) {
    if (parent) {
      return CaseStmt::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<CaseStmt> from(const Stmt &parent);

  inline static std::optional<CaseStmt> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return CaseStmt::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  bool case_statement_is_gnu_range(void) const;
  Token case_token(void) const;
  Token ellipsis_token(void) const;
  Expr lhs(void) const;
  std::optional<Expr> rhs(void) const;
};

static_assert(sizeof(CaseStmt) == sizeof(SwitchCase));

#endif
} // namespace mx
