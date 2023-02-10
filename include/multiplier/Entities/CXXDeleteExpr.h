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
class CXXDeleteExpr;
class Expr;
class FunctionDecl;
class Stmt;
class Type;
class ValueStmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class CXXDeleteExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  static gap::generator<CXXDeleteExpr> in(const Fragment &frag);
  static gap::generator<CXXDeleteExpr> in(const File &file);
  static gap::generator<CXXDeleteExpr> in(const Index &index);
  static gap::generator<CXXDeleteExpr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<CXXDeleteExpr> by_id(const Index &, EntityId);

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::CXX_DELETE_EXPR;
  }

  static gap::generator<CXXDeleteExpr> containing(const Decl &decl);
  static gap::generator<CXXDeleteExpr> containing(const std::optional<Decl> &decl);

  static gap::generator<CXXDeleteExpr> containing(const Stmt &stmt);
  static gap::generator<CXXDeleteExpr> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<CXXDeleteExpr> from(const Stmt &parent);

  inline static std::optional<CXXDeleteExpr> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return CXXDeleteExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  inline static std::optional<CXXDeleteExpr> from(const Reference &r) {
    return CXXDeleteExpr::from(r.as_statement());
  }

  inline static std::optional<CXXDeleteExpr> from(const TokenContext &t) {
    return CXXDeleteExpr::from(t.as_statement());
  }

  bool does_usual_array_delete_want_size(void) const;
  Expr argument(void) const;
  Type destroyed_type(void) const;
  FunctionDecl operator_delete(void) const;
  bool is_array_form(void) const;
  bool is_array_form_as_written(void) const;
  bool is_global_delete(void) const;
};

static_assert(sizeof(CXXDeleteExpr) == sizeof(Expr));

#endif
} // namespace mx
