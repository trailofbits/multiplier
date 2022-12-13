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
#include "IfStatementKind.h"
#include "Stmt.h"
#include "StmtKind.h"
#include "StmtUseSelector.h"

namespace mx {
class DeclStmt;
class Expr;
class IfStmt;
class Stmt;
class VarDecl;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using IfStmtRange = DerivedEntityRange<StmtIterator, IfStmt>;
using IfStmtContainingTokenRange = DerivedEntityRange<TokenContextIterator, IfStmt>;
using IfStmtContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, IfStmt>;

class IfStmt : public Stmt {
 private:
  friend class FragmentImpl;
  friend class Stmt;
 public:
  inline static IfStmtRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static IfStmtContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : IfStmt::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::IF_STMT;
  }

  static IfStmtContainingStmtRange containing(const Decl &decl);
  static IfStmtContainingStmtRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<IfStmt> from(const TokenContext &c);
  static std::optional<IfStmt> from(const Stmt &parent);

  inline static std::optional<IfStmt> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return IfStmt::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  Expr condition(void) const;
  std::optional<VarDecl> condition_variable(void) const;
  std::optional<DeclStmt> condition_variable_declaration_statement(void) const;
  std::optional<Stmt> else_(void) const;
  Token else_token(void) const;
  Token if_token(void) const;
  std::optional<Stmt> initializer(void) const;
  Token l_paren_token(void) const;
  Token r_paren_token(void) const;
  IfStatementKind statement_kind(void) const;
  Stmt then(void) const;
  bool has_else_storage(void) const;
  bool has_initializer_storage(void) const;
  bool has_variable_storage(void) const;
  bool is_consteval(void) const;
  bool is_constexpr(void) const;
  bool is_negated_consteval(void) const;
  bool is_non_negated_consteval(void) const;
  bool is_obj_c_availability_check(void) const;
};

static_assert(sizeof(IfStmt) == sizeof(Stmt));

#endif
} // namespace mx
