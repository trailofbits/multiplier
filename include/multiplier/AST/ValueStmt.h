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
class Expr;
class Stmt;
class Token;
class ValueStmt;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT ValueStmt : public Stmt {
 private:
  friend class FragmentImpl;
  friend class Stmt;
 public:
  static gap::generator<ValueStmt> in(const Index &index);
  static gap::generator<ValueStmt> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<ValueStmt> by_id(const Index &, EntityId);
  static gap::generator<ValueStmt> in(const Fragment &frag);
  static gap::generator<ValueStmt> in(const File &file);

  static gap::generator<ValueStmt> containing(const Decl &decl);
  static gap::generator<ValueStmt> containing(const std::optional<Decl> &decl);

  static gap::generator<ValueStmt> containing(const Stmt &stmt);
  static gap::generator<ValueStmt> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<ValueStmt> from_base(const Stmt &parent);
  inline static std::optional<ValueStmt> from(const Stmt &parent) {
    return from_base(parent);
  }
  static std::optional<ValueStmt> from(const std::optional<Stmt> &parent);
  static std::optional<ValueStmt> from(const Reference &r);
  static std::optional<ValueStmt> from(const VariantEntity &e);
  static std::optional<ValueStmt> from(const TokenContext &t);

  std::optional<Expr> expression_statement(void) const;
};

static_assert(sizeof(ValueStmt) == sizeof(Stmt));

#endif
} // namespace mx
