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

#include "DeclUseSelector.h"
#include "Stmt.h"
#include "StmtKind.h"
#include "StmtUseSelector.h"

namespace mx {
class DeclStmt;
class Expr;
class Stmt;
class VarDecl;
class WhileStmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using WhileStmtRange = DerivedEntityRange<StmtIterator, WhileStmt>;
using WhileStmtContainingTokenRange = DerivedEntityRange<TokenContextIterator, WhileStmt>;
using WhileStmtContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, WhileStmt>;

class WhileStmt : public Stmt {
 private:
  friend class FragmentImpl;
  friend class Stmt;
 public:
  inline static WhileStmtRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static WhileStmtContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : WhileStmt::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::WHILE_STMT;
  }

  static WhileStmtContainingStmtRange containing(const Decl &decl);
  static WhileStmtContainingStmtRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<WhileStmt> from(const TokenContext &c);
  static std::optional<WhileStmt> from(const Stmt &parent);

  inline static std::optional<WhileStmt> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return WhileStmt::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  Stmt body(void) const;
  Expr condition(void) const;
  std::optional<VarDecl> condition_variable(void) const;
  std::optional<DeclStmt> condition_variable_declaration_statement(void) const;
  Token l_paren_token(void) const;
  Token r_paren_token(void) const;
  Token while_token(void) const;
  bool has_variable_storage(void) const;
};

static_assert(sizeof(WhileStmt) == sizeof(Stmt));

#endif
} // namespace mx
