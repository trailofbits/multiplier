// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <multiplier/AST/Expr.h>

namespace mx {
class EntityProvider;
class Fragment;
class Index;
class CXXNoexceptExpr;
class Decl;
class Expr;
class File;
class Stmt;
class Token;
class ValueStmt;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT CXXNoexceptExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  static gap::generator<CXXNoexceptExpr> in(const Index &index);
  static gap::generator<CXXNoexceptExpr> in(const Fragment &frag);
  static gap::generator<CXXNoexceptExpr> in(const File &file);
  static gap::generator<CXXNoexceptExpr> containing(const Token &tok);
  bool contains(const Token &tok) const;

  static std::optional<CXXNoexceptExpr> from(const ir::Operation &op);
  static gap::generator<std::pair<CXXNoexceptExpr, ir::Operation>> in(const Compilation &tu);
  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::CXX_NOEXCEPT_EXPR;
  }

  static gap::generator<CXXNoexceptExpr> containing(const Decl &decl);
  static gap::generator<CXXNoexceptExpr> containing(const std::optional<Decl> &decl);

  static gap::generator<CXXNoexceptExpr> containing(const Stmt &stmt);
  static gap::generator<CXXNoexceptExpr> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<CXXNoexceptExpr> by_id(const Index &, EntityId);

  static std::optional<CXXNoexceptExpr> from_base(const Stmt &parent);
  inline static std::optional<CXXNoexceptExpr> from(const Stmt &parent) {
    return from_base(parent);
  }
  static std::optional<CXXNoexceptExpr> from(const std::optional<Stmt> &parent);
  static std::optional<CXXNoexceptExpr> from(const Reference &r);
  static std::optional<CXXNoexceptExpr> from(const VariantEntity &e);
  static std::optional<CXXNoexceptExpr> from(const TokenContext &t);

  Expr operand(void) const;
  bool value(void) const;
};

static_assert(sizeof(CXXNoexceptExpr) == sizeof(Expr));

#endif
} // namespace mx
