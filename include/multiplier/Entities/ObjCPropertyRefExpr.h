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
#include "StmtKind.h"

namespace mx {
class Expr;
class ObjCInterfaceDecl;
class ObjCMethodDecl;
class ObjCPropertyDecl;
class ObjCPropertyRefExpr;
class Stmt;
class Type;
class ValueStmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using ObjCPropertyRefExprContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, ObjCPropertyRefExpr>;

class ObjCPropertyRefExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static gap::generator<ObjCPropertyRefExpr> in(const Fragment &frag) {
    for(auto e : in_internal(frag)) {
      if(auto d = from(e)) {
        co_yield *d;
      }
    }
  }

  inline static gap::generator<ObjCPropertyRefExpr> containing(const Token &tok) {
    for(auto ctx = TokenContext::of(tok); ctx.has_value(); ctx = ctx->parent()) {
      if(auto d = from(*ctx)) {
        co_yield *d;
      }
    }
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : ObjCPropertyRefExpr::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::OBJ_C_PROPERTY_REF_EXPR;
  }

  static ObjCPropertyRefExprContainingStmtRange containing(const Decl &decl);
  static ObjCPropertyRefExprContainingStmtRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<ObjCPropertyRefExpr> from(const TokenContext &c);
  static std::optional<ObjCPropertyRefExpr> from(const Expr &parent);

  inline static std::optional<ObjCPropertyRefExpr> from(const std::optional<Expr> &parent) {
    if (parent) {
      return ObjCPropertyRefExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ObjCPropertyRefExpr> from(const ValueStmt &parent);

  inline static std::optional<ObjCPropertyRefExpr> from(const std::optional<ValueStmt> &parent) {
    if (parent) {
      return ObjCPropertyRefExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ObjCPropertyRefExpr> from(const Stmt &parent);

  inline static std::optional<ObjCPropertyRefExpr> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return ObjCPropertyRefExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  Expr base(void) const;
  ObjCInterfaceDecl class_receiver(void) const;
  ObjCPropertyDecl explicit_property(void) const;
  ObjCMethodDecl implicit_property_getter(void) const;
  ObjCMethodDecl implicit_property_setter(void) const;
  Token token(void) const;
  Token receiver_token(void) const;
  Type receiver_type(void) const;
  Type super_receiver_type(void) const;
  bool is_class_receiver(void) const;
  bool is_explicit_property(void) const;
  bool is_implicit_property(void) const;
  bool is_messaging_getter(void) const;
  bool is_messaging_setter(void) const;
  bool is_object_receiver(void) const;
  bool is_super_receiver(void) const;
};

static_assert(sizeof(ObjCPropertyRefExpr) == sizeof(Expr));

#endif
} // namespace mx
