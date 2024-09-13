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
class Decl;
class Expr;
class File;
class NamedDecl;
class SizeOfPackExpr;
class Stmt;
class TemplateArgument;
class Token;
class ValueStmt;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT SizeOfPackExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  static gap::generator<SizeOfPackExpr> in(const Index &index);
  static gap::generator<SizeOfPackExpr> in(const Fragment &frag);
  static gap::generator<SizeOfPackExpr> in(const File &file);
  static gap::generator<SizeOfPackExpr> containing(const Token &tok);
  bool contains(const Token &tok) const;

  static std::optional<SizeOfPackExpr> from(const ir::Operation &op);
  static gap::generator<std::pair<SizeOfPackExpr, ir::Operation>> in(const Compilation &tu);
  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::SIZE_OF_PACK_EXPR;
  }

  static gap::generator<SizeOfPackExpr> containing(const Decl &decl);
  static gap::generator<SizeOfPackExpr> containing(const std::optional<Decl> &decl);

  static gap::generator<SizeOfPackExpr> containing(const Stmt &stmt);
  static gap::generator<SizeOfPackExpr> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<SizeOfPackExpr> by_id(const Index &, EntityId);

  static std::optional<SizeOfPackExpr> from_base(const Stmt &parent);
  inline static std::optional<SizeOfPackExpr> from(const Stmt &parent) {
    return from_base(parent);
  }
  static std::optional<SizeOfPackExpr> from(const std::optional<Stmt> &parent);
  static std::optional<SizeOfPackExpr> from(const Reference &r);
  static std::optional<SizeOfPackExpr> from(const VariantEntity &e);
  static std::optional<SizeOfPackExpr> from(const TokenContext &t);

  Token operator_token(void) const;
  NamedDecl pack(void) const;
  std::optional<uint32_t> pack_length(void) const;
  Token pack_token(void) const;
  std::optional<std::vector<TemplateArgument>> partial_arguments(void) const;
  Token r_paren_token(void) const;
  bool is_partially_substituted(void) const;
};

static_assert(sizeof(SizeOfPackExpr) == sizeof(Expr));

#endif
} // namespace mx
