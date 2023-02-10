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
#include <span>
#include <vector>

#include <gap/core/generator.hpp>
#include "../Iterator.h"
#include "../Reference.h"
#include "../Types.h"
#include "../Token.h"

#include "Expr.h"
#include "StmtKind.h"

namespace mx {
class CompoundLiteralExpr;
class Expr;
class Stmt;
class ValueStmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class CompoundLiteralExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  static gap::generator<CompoundLiteralExpr> in(const Fragment &frag);
  static gap::generator<CompoundLiteralExpr> in(const File &file);
  static gap::generator<CompoundLiteralExpr> in(const Index &index);
  static gap::generator<CompoundLiteralExpr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<CompoundLiteralExpr> by_id(const Index &, EntityId);

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::COMPOUND_LITERAL_EXPR;
  }

  static gap::generator<CompoundLiteralExpr> containing(const Decl &decl);
  static gap::generator<CompoundLiteralExpr> containing(const std::optional<Decl> &decl);

  static gap::generator<CompoundLiteralExpr> containing(const Stmt &stmt);
  static gap::generator<CompoundLiteralExpr> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<CompoundLiteralExpr> from(const Stmt &parent);

  inline static std::optional<CompoundLiteralExpr> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return CompoundLiteralExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  inline static std::optional<CompoundLiteralExpr> from(const Reference &r) {
    return CompoundLiteralExpr::from(r.as_statement());
  }

  inline static std::optional<CompoundLiteralExpr> from(const TokenContext &t) {
    return CompoundLiteralExpr::from(t.as_statement());
  }

  Expr initializer(void) const;
  Token l_paren_token(void) const;
  bool is_file_scope(void) const;
};

static_assert(sizeof(CompoundLiteralExpr) == sizeof(Expr));

#endif
} // namespace mx
