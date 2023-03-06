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

#include "CXXConstructExprConstructionKind.h"
#include "Expr.h"

namespace mx {
class CXXConstructorDecl;
class CXXInheritedCtorInitExpr;
class Decl;
class Expr;
class Stmt;
class Token;
class ValueStmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class CXXInheritedCtorInitExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  static gap::generator<CXXInheritedCtorInitExpr> in(const Fragment &frag);
  static gap::generator<CXXInheritedCtorInitExpr> in(const File &file);
  static gap::generator<CXXInheritedCtorInitExpr> in(const Index &index);
  static gap::generator<CXXInheritedCtorInitExpr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<CXXInheritedCtorInitExpr> by_id(const Index &, EntityId);

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::CXX_INHERITED_CTOR_INIT_EXPR;
  }

  static gap::generator<CXXInheritedCtorInitExpr> containing(const Decl &decl);
  static gap::generator<CXXInheritedCtorInitExpr> containing(const std::optional<Decl> &decl);

  static gap::generator<CXXInheritedCtorInitExpr> containing(const Stmt &stmt);
  static gap::generator<CXXInheritedCtorInitExpr> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<CXXInheritedCtorInitExpr> from(const Stmt &parent);

  inline static std::optional<CXXInheritedCtorInitExpr> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return CXXInheritedCtorInitExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  inline static std::optional<CXXInheritedCtorInitExpr> from(const Reference &r) {
    return CXXInheritedCtorInitExpr::from(r.as_statement());
  }

  inline static std::optional<CXXInheritedCtorInitExpr> from(const TokenContext &t) {
    return CXXInheritedCtorInitExpr::from(t.as_statement());
  }

  bool constructs_virtual_base(void) const;
  CXXConstructExprConstructionKind construction_kind(void) const;
  CXXConstructorDecl constructor(void) const;
  Token token(void) const;
  bool inherited_from_virtual_base(void) const;
};

static_assert(sizeof(CXXInheritedCtorInitExpr) == sizeof(Expr));

#endif
} // namespace mx
