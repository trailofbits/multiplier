// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <multiplier/AST/CallExpr.h>

namespace mx {
class EntityProvider;
class Fragment;
class Index;
class CXXMemberCallExpr;
class CXXMethodDecl;
class CXXRecordDecl;
class CallExpr;
class Decl;
class Expr;
class Stmt;
class Token;
class Type;
class ValueStmt;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class CXXMemberCallExpr : public CallExpr {
 private:
  friend class FragmentImpl;
  friend class CallExpr;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  static gap::generator<CXXMemberCallExpr> in(const Index &index);
  static gap::generator<CXXMemberCallExpr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<CXXMemberCallExpr> by_id(const Index &, EntityId);
  static gap::generator<CXXMemberCallExpr> in(const Fragment &frag);
  static gap::generator<CXXMemberCallExpr> in(const File &file);

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::CXX_MEMBER_CALL_EXPR;
  }

  static gap::generator<CXXMemberCallExpr> containing(const Decl &decl);
  static gap::generator<CXXMemberCallExpr> containing(const std::optional<Decl> &decl);

  static gap::generator<CXXMemberCallExpr> containing(const Stmt &stmt);
  static gap::generator<CXXMemberCallExpr> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<CXXMemberCallExpr> from_base(const Stmt &parent);
  inline static std::optional<CXXMemberCallExpr> from(const Stmt &parent) {
    return from_base(parent);
  }
  static std::optional<CXXMemberCallExpr> from(const std::optional<Stmt> &parent);
  static std::optional<CXXMemberCallExpr> from(const Reference &r);
  static std::optional<CXXMemberCallExpr> from(const VariantEntity &e);
  static std::optional<CXXMemberCallExpr> from(const TokenContext &t);

  Expr implicit_object_argument(void) const;
  std::optional<CXXMethodDecl> method_declaration(void) const;
  Type object_type(void) const;
  CXXRecordDecl record_declaration(void) const;
};

static_assert(sizeof(CXXMemberCallExpr) == sizeof(CallExpr));

#endif
} // namespace mx
