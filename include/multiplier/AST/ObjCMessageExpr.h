// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <multiplier/AST/Expr.h>
#include <multiplier/AST/ObjCMessageExprReceiverKind.h>
#include <multiplier/AST/ObjCMethodFamily.h>

namespace mx {
class EntityProvider;
class Fragment;
class Index;
class Decl;
class Expr;
class ObjCInterfaceDecl;
class ObjCMessageExpr;
class ObjCMethodDecl;
class Stmt;
class Token;
class TokenRange;
class Type;
class ValueStmt;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT ObjCMessageExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  static gap::generator<ObjCMessageExpr> in(const Index &index);
  static gap::generator<ObjCMessageExpr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<ObjCMessageExpr> by_id(const Index &, EntityId);
  static gap::generator<ObjCMessageExpr> in(const Fragment &frag);
  static gap::generator<ObjCMessageExpr> in(const File &file);

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::OBJ_C_MESSAGE_EXPR;
  }

  static gap::generator<ObjCMessageExpr> containing(const Decl &decl);
  static gap::generator<ObjCMessageExpr> containing(const std::optional<Decl> &decl);

  static gap::generator<ObjCMessageExpr> containing(const Stmt &stmt);
  static gap::generator<ObjCMessageExpr> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<ObjCMessageExpr> from_base(const Stmt &parent);
  inline static std::optional<ObjCMessageExpr> from(const Stmt &parent) {
    return from_base(parent);
  }
  static std::optional<ObjCMessageExpr> from(const std::optional<Stmt> &parent);
  static std::optional<ObjCMessageExpr> from(const Reference &r);
  static std::optional<ObjCMessageExpr> from(const VariantEntity &e);
  static std::optional<ObjCMessageExpr> from(const TokenContext &t);

  std::optional<Expr> nth_argument(unsigned n) const;
  unsigned num_arguments(void) const;
  gap::generator<Expr> arguments(void) const &;
  Type call_return_type(void) const;
  Type class_receiver(void) const;
  Expr instance_receiver(void) const;
  Token left_token(void) const;
  ObjCMethodDecl method_declaration(void) const;
  ObjCMethodFamily method_family(void) const;
  ObjCInterfaceDecl receiver_interface(void) const;
  ObjCMessageExprReceiverKind receiver_kind(void) const;
  TokenRange receiver_range(void) const;
  Type receiver_type(void) const;
  Token right_token(void) const;
  Token selector_start_token(void) const;
  Token super_token(void) const;
  Type super_type(void) const;
  bool is_class_message(void) const;
  bool is_delegate_initializer_call(void) const;
  bool is_implicit(void) const;
  bool is_instance_message(void) const;
  std::optional<Token> nth_selector_token(unsigned n) const;
  unsigned num_selector_tokens(void) const;
  gap::generator<Token> selector_tokens(void) const &;
};

static_assert(sizeof(ObjCMessageExpr) == sizeof(Expr));

#endif
} // namespace mx
