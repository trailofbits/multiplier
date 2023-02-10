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
class SYCLUniqueStableNameExpr;
class Stmt;
class ValueStmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class SYCLUniqueStableNameExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  static gap::generator<SYCLUniqueStableNameExpr> in(const Fragment &frag);
  static gap::generator<SYCLUniqueStableNameExpr> in(const File &file);
  static gap::generator<SYCLUniqueStableNameExpr> in(const Index &index);
  static gap::generator<SYCLUniqueStableNameExpr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<SYCLUniqueStableNameExpr> by_id(const Index &, EntityId);

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::SYCL_UNIQUE_STABLE_NAME_EXPR;
  }

  static gap::generator<SYCLUniqueStableNameExpr> containing(const Decl &decl);
  static gap::generator<SYCLUniqueStableNameExpr> containing(const std::optional<Decl> &decl);

  static gap::generator<SYCLUniqueStableNameExpr> containing(const Stmt &stmt);
  static gap::generator<SYCLUniqueStableNameExpr> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<SYCLUniqueStableNameExpr> from(const Stmt &parent);

  inline static std::optional<SYCLUniqueStableNameExpr> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return SYCLUniqueStableNameExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  inline static std::optional<SYCLUniqueStableNameExpr> from(const Reference &r) {
    return SYCLUniqueStableNameExpr::from(r.as_statement());
  }

  inline static std::optional<SYCLUniqueStableNameExpr> from(const TokenContext &t) {
    return SYCLUniqueStableNameExpr::from(t.as_statement());
  }

  std::string_view compute_name(void) const;
  Token l_paren_token(void) const;
  Token token(void) const;
  Token r_paren_token(void) const;
};

static_assert(sizeof(SYCLUniqueStableNameExpr) == sizeof(Expr));

#endif
} // namespace mx
