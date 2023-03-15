// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Stmt.h"

namespace mx {
class EntityProvider;
class Index;
class Decl;
class Expr;
class ReturnStmt;
class Stmt;
class Token;
class VarDecl;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class ReturnStmt : public Stmt {
 private:
  friend class FragmentImpl;
  friend class Stmt;
 public:
  static gap::generator<ReturnStmt> in(const Fragment &frag);
  static gap::generator<ReturnStmt> in(const File &file);
  static gap::generator<ReturnStmt> in(const Index &index);
  static gap::generator<ReturnStmt> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<ReturnStmt> by_id(const Index &, EntityId);

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::RETURN_STMT;
  }

  static gap::generator<ReturnStmt> containing(const Decl &decl);
  static gap::generator<ReturnStmt> containing(const std::optional<Decl> &decl);

  static gap::generator<ReturnStmt> containing(const Stmt &stmt);
  static gap::generator<ReturnStmt> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<ReturnStmt> from(const Stmt &parent);

  inline static std::optional<ReturnStmt> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return ReturnStmt::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ReturnStmt> from(const Reference &r);
  static std::optional<ReturnStmt> from(const TokenContext &t);

  std::optional<VarDecl> nrvo_candidate(void) const;
  std::optional<Expr> return_value(void) const;
  Token return_token(void) const;
};

static_assert(sizeof(ReturnStmt) == sizeof(Stmt));

#endif
} // namespace mx
