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
class CompoundStmt;
class Decl;
class Expr;
class SEHExceptStmt;
class Stmt;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class SEHExceptStmt : public Stmt {
 private:
  friend class FragmentImpl;
  friend class Stmt;
 public:
  static gap::generator<SEHExceptStmt> in(const Index &index);
  static gap::generator<SEHExceptStmt> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<SEHExceptStmt> by_id(const Index &, EntityId);
  static gap::generator<SEHExceptStmt> in(const Fragment &frag);
  static gap::generator<SEHExceptStmt> in(const File &file);

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::SEH_EXCEPT_STMT;
  }

  static gap::generator<SEHExceptStmt> containing(const Decl &decl);
  static gap::generator<SEHExceptStmt> containing(const std::optional<Decl> &decl);

  static gap::generator<SEHExceptStmt> containing(const Stmt &stmt);
  static gap::generator<SEHExceptStmt> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<SEHExceptStmt> from_base(const Stmt &parent);
  inline static std::optional<SEHExceptStmt> from(const Stmt &parent) {
    return from_base(parent);
  }
  static std::optional<SEHExceptStmt> from(const std::optional<Stmt> &parent);
  static std::optional<SEHExceptStmt> from(const Reference &r);
  static std::optional<SEHExceptStmt> from(const VariantEntity &e);
  static std::optional<SEHExceptStmt> from(const TokenContext &t);

  CompoundStmt block(void) const;
  Token except_token(void) const;
  Expr filter_expression(void) const;
};

static_assert(sizeof(SEHExceptStmt) == sizeof(Stmt));

#endif
} // namespace mx
