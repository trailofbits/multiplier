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
class IfStmt : public Stmt {
 private:
  friend class FragmentImpl;
  friend class Stmt;
 public:
  inline static gap::generator<IfStmt> in(const Fragment &frag) {
    for (auto e : in_internal(frag)) {
      if (auto d = from(e)) {
        co_yield *d;
      }
    }
  }

  inline static gap::generator<IfStmt> containing(const Token &tok) {
    for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
      if (auto d = from(*ctx)) {
        co_yield *d;
      }
    }
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : IfStmt::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::IF_STMT;
  }

  static gap::generator<IfStmt> containing(const Decl &decl);
  static gap::generator<IfStmt> containing(const Stmt &stmt);

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
