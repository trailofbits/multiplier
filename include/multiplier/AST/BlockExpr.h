// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
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
class BlockDecl;
class BlockExpr;
class Decl;
class Expr;
class File;
class FunctionProtoType;
class Stmt;
class Token;
class ValueStmt;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT BlockExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  static gap::generator<BlockExpr> in(const Index &index);
  static gap::generator<BlockExpr> in(const Fragment &frag);
  static gap::generator<BlockExpr> in(const File &file);
  static gap::generator<BlockExpr> containing(const Token &tok);
  bool contains(const Token &tok) const;

  static std::optional<BlockExpr> from(const ir::Operation &op);
  static gap::generator<std::pair<BlockExpr, ir::Operation>> in(const Compilation &tu);
  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::BLOCK_EXPR;
  }

  static gap::generator<BlockExpr> containing(const Decl &decl);
  static gap::generator<BlockExpr> containing(const std::optional<Decl> &decl);

  static gap::generator<BlockExpr> containing(const Stmt &stmt);
  static gap::generator<BlockExpr> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<BlockExpr> by_id(const Index &, EntityId);

  static std::optional<BlockExpr> from_base(const Stmt &parent);
  inline static std::optional<BlockExpr> from(const Stmt &parent) {
    return from_base(parent);
  }
  static std::optional<BlockExpr> from(const std::optional<Stmt> &parent);
  static std::optional<BlockExpr> from(const Reference &r);
  static std::optional<BlockExpr> from(const VariantEntity &e);
  static std::optional<BlockExpr> from(const TokenContext &t);

  BlockDecl block_declaration(void) const;
  Stmt body(void) const;
  Token caret_token(void) const;
  FunctionProtoType function_type(void) const;
};

static_assert(sizeof(BlockExpr) == sizeof(Expr));

#endif
} // namespace mx
