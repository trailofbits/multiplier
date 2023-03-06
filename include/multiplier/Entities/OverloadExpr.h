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
class CXXRecordDecl;
class Decl;
class Expr;
class OverloadExpr;
class Stmt;
class Token;
class UnresolvedLookupExpr;
class UnresolvedMemberExpr;
class ValueStmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class OverloadExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  static gap::generator<OverloadExpr> in(const Fragment &frag);
  static gap::generator<OverloadExpr> in(const File &file);
  static gap::generator<OverloadExpr> in(const Index &index);
  static gap::generator<OverloadExpr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<OverloadExpr> by_id(const Index &, EntityId);

  static gap::generator<OverloadExpr> containing(const Decl &decl);
  static gap::generator<OverloadExpr> containing(const std::optional<Decl> &decl);

  static gap::generator<OverloadExpr> containing(const Stmt &stmt);
  static gap::generator<OverloadExpr> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<OverloadExpr> from(const Stmt &parent);

  inline static std::optional<OverloadExpr> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return OverloadExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  inline static std::optional<OverloadExpr> from(const Reference &r) {
    return OverloadExpr::from(r.as_statement());
  }

  inline static std::optional<OverloadExpr> from(const TokenContext &t) {
    return OverloadExpr::from(t.as_statement());
  }

  Token l_angle_token(void) const;
  Token name_token(void) const;
  std::optional<CXXRecordDecl> naming_class(void) const;
  Token r_angle_token(void) const;
  Token template_keyword_token(void) const;
  bool has_explicit_template_arguments(void) const;
  bool has_template_keyword(void) const;
};

static_assert(sizeof(OverloadExpr) == sizeof(Expr));

#endif
} // namespace mx
