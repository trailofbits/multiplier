// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <multiplier/AST/Stmt.h>

namespace mx {
class EntityProvider;
class Fragment;
class Index;
class Decl;
class DoStmt;
class Expr;
class File;
class Stmt;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT DoStmt : public Stmt {
 private:
  friend class FragmentImpl;
  friend class Stmt;
 public:
  static gap::generator<DoStmt> in(const Index &index);
  static gap::generator<DoStmt> in(const Fragment &frag);
  static gap::generator<DoStmt> in(const File &file);
  static gap::generator<DoStmt> containing(const Token &tok);
  bool contains(const Token &tok) const;

  static std::optional<DoStmt> from(const ir::Operation &op);
  static gap::generator<std::pair<DoStmt, ir::Operation>> in(const Compilation &tu);
  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::DO_STMT;
  }

  static gap::generator<DoStmt> containing(const Decl &decl);
  static gap::generator<DoStmt> containing(const std::optional<Decl> &decl);

  static gap::generator<DoStmt> containing(const Stmt &stmt);
  static gap::generator<DoStmt> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<DoStmt> by_id(const Index &, EntityId);

  static std::optional<DoStmt> from_base(const Stmt &parent);
  inline static std::optional<DoStmt> from(const Stmt &parent) {
    return from_base(parent);
  }
  static std::optional<DoStmt> from(const std::optional<Stmt> &parent);
  static std::optional<DoStmt> from(const Reference &r);
  static std::optional<DoStmt> from(const VariantEntity &e);
  static std::optional<DoStmt> from(const TokenContext &t);

  Stmt body(void) const;
  Expr condition(void) const;
  Token do_token(void) const;
  Token r_paren_token(void) const;
  Token while_token(void) const;
};

static_assert(sizeof(DoStmt) == sizeof(Stmt));

#endif
} // namespace mx
