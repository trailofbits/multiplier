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

namespace mx {
class Decl;
class Expr;
class PackExpansionExpr;
class Stmt;
class Token;
class ValueStmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class PackExpansionExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  static gap::generator<PackExpansionExpr> in(const Fragment &frag);
  static gap::generator<PackExpansionExpr> in(const File &file);
  static gap::generator<PackExpansionExpr> in(const Index &index);
  static gap::generator<PackExpansionExpr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<PackExpansionExpr> by_id(const Index &, EntityId);

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::PACK_EXPANSION_EXPR;
  }

  static gap::generator<PackExpansionExpr> containing(const Decl &decl);
  static gap::generator<PackExpansionExpr> containing(const std::optional<Decl> &decl);

  static gap::generator<PackExpansionExpr> containing(const Stmt &stmt);
  static gap::generator<PackExpansionExpr> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<PackExpansionExpr> from(const Stmt &parent);

  inline static std::optional<PackExpansionExpr> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return PackExpansionExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  inline static std::optional<PackExpansionExpr> from(const Reference &r) {
    return PackExpansionExpr::from(r.as_statement());
  }

  inline static std::optional<PackExpansionExpr> from(const TokenContext &t) {
    return PackExpansionExpr::from(t.as_statement());
  }

  Token ellipsis_token(void) const;
  std::optional<unsigned> num_expansions(void) const;
  Expr pattern(void) const;
};

static_assert(sizeof(PackExpansionExpr) == sizeof(Expr));

#endif
} // namespace mx
