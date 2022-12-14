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
#include <vector>

#include <gap/core/generator.hpp>
#include "../Iterator.h"
#include "../Types.h"
#include "../Token.h"
#include "../Use.h"

#include "Expr.h"
#include "ObjCMessageExprReceiverKind.h"
#include "ObjCMethodFamily.h"
#include "StmtKind.h"

namespace mx {
class Expr;
class ObjCInterfaceDecl;
class ObjCMessageExpr;
class ObjCMethodDecl;
class Stmt;
class Token;
class Type;
class ValueStmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using ObjCMessageExprContainingTokenRange = DerivedEntityRange<TokenContextIterator, ObjCMessageExpr>;
using ObjCMessageExprContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, ObjCMessageExpr>;

class ObjCMessageExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static gap::generator<ObjCMessageExpr> in(const Fragment &frag) {
    for(auto e : in_internal(frag)) {
      if(auto d = from(e)) {
        co_yield *d;
      }
    }
  }

  inline static ObjCMessageExprContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : ObjCMessageExpr::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::OBJ_C_MESSAGE_EXPR;
  }

  static ObjCMessageExprContainingStmtRange containing(const Decl &decl);
  static ObjCMessageExprContainingStmtRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<ObjCMessageExpr> from(const TokenContext &c);
  static std::optional<ObjCMessageExpr> from(const Expr &parent);

  inline static std::optional<ObjCMessageExpr> from(const std::optional<Expr> &parent) {
    if (parent) {
      return ObjCMessageExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ObjCMessageExpr> from(const ValueStmt &parent);

  inline static std::optional<ObjCMessageExpr> from(const std::optional<ValueStmt> &parent) {
    if (parent) {
      return ObjCMessageExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ObjCMessageExpr> from(const Stmt &parent);

  inline static std::optional<ObjCMessageExpr> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return ObjCMessageExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  std::vector<Expr> arguments(void) const;
  Type call_return_type(void) const;
  Type class_receiver(void) const;
  Type class_receiver_type(void) const;
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
  std::vector<Token> selector_tokens(void) const;
};

static_assert(sizeof(ObjCMessageExpr) == sizeof(Expr));

#endif
} // namespace mx
