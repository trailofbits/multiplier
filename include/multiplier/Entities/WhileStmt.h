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

#include "Stmt.h"
#include "StmtKind.h"

namespace mx {
class DeclStmt;
class Expr;
class Stmt;
class VarDecl;
class WhileStmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class WhileStmt : public Stmt {
 private:
  friend class FragmentImpl;
  friend class Stmt;
 public:
  inline static gap::generator<WhileStmt> in(const Fragment &frag) {
    for (auto e : in_internal(frag)) {
      if (auto d = from(e)) {
        co_yield *d;
      }
    }
  }

  inline static gap::generator<WhileStmt> containing(const Token &tok) {
    for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
      if (auto d = from(*ctx)) {
        co_yield *d;
      }
    }
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : WhileStmt::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::WHILE_STMT;
  }

  static gap::generator<WhileStmt> containing(const Decl &decl);
  static gap::generator<WhileStmt> containing(const Stmt &stmt);

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
