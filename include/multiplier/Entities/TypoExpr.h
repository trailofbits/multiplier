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
class Expr;
class Stmt;
class TypoExpr;
class ValueStmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class TypoExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  static gap::generator<TypoExpr> in(const Fragment &frag);
  static gap::generator<TypoExpr> in(const File &file);
  static gap::generator<TypoExpr> in(const Index &index);
  static gap::generator<TypoExpr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<TypoExpr> by_id(const Index &, EntityId);

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::TYPO_EXPR;
  }

  static gap::generator<TypoExpr> containing(const Decl &decl);
  static gap::generator<TypoExpr> containing(const std::optional<Decl> &decl);

  static gap::generator<TypoExpr> containing(const Stmt &stmt);
  static gap::generator<TypoExpr> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<TypoExpr> from(const Stmt &parent);

  inline static std::optional<TypoExpr> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return TypoExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  inline static std::optional<TypoExpr> from(const Reference &r) {
    return TypoExpr::from(r.as_statement());
  }

  inline static std::optional<TypoExpr> from(const TokenContext &t) {
    return TypoExpr::from(t.as_statement());
  }

};

static_assert(sizeof(TypoExpr) == sizeof(Expr));

#endif
} // namespace mx
