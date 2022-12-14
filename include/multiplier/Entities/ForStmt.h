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
#include "StmtUseSelector.h"

namespace mx {
class DeclStmt;
class Expr;
class ForStmt;
class Stmt;
class VarDecl;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using ForStmtContainingTokenRange = DerivedEntityRange<TokenContextIterator, ForStmt>;
using ForStmtContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, ForStmt>;

class ForStmt : public Stmt {
 private:
  friend class FragmentImpl;
  friend class Stmt;
 public:
  inline static gap::generator<ForStmt> in(const Fragment &frag) {
    for(auto e : in_internal(frag)) {
      if(auto d = from(e)) {
        co_yield *d;
      }
    }
  }

  inline static ForStmtContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : ForStmt::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::FOR_STMT;
  }

  static ForStmtContainingStmtRange containing(const Decl &decl);
  static ForStmtContainingStmtRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<ForStmt> from(const TokenContext &c);
  static std::optional<ForStmt> from(const Stmt &parent);

  inline static std::optional<ForStmt> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return ForStmt::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  Stmt body(void) const;
  std::optional<Expr> condition(void) const;
  std::optional<VarDecl> condition_variable(void) const;
  std::optional<DeclStmt> condition_variable_declaration_statement(void) const;
  Token for_token(void) const;
  std::optional<Expr> increment(void) const;
  std::optional<Stmt> initializer(void) const;
  Token l_paren_token(void) const;
  Token r_paren_token(void) const;
};

static_assert(sizeof(ForStmt) == sizeof(Stmt));

#endif
} // namespace mx
