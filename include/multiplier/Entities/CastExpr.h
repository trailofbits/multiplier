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
#include <span>
#include <vector>

#include <gap/core/generator.hpp>
#include "../Iterator.h"
#include "../Reference.h"
#include "../Types.h"
#include "../Token.h"

#include "CastKind.h"
#include "Expr.h"

namespace mx {
class BuiltinBitCastExpr;
class CStyleCastExpr;
class CXXAddrspaceCastExpr;
class CXXConstCastExpr;
class CXXDynamicCastExpr;
class CXXFunctionalCastExpr;
class CXXReinterpretCastExpr;
class CXXStaticCastExpr;
class CastExpr;
class Decl;
class Expr;
class FieldDecl;
class ImplicitCastExpr;
class NamedDecl;
class ObjCBridgedCastExpr;
class Stmt;
class Token;
class ValueStmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class CastExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  static gap::generator<CastExpr> in(const Fragment &frag);
  static gap::generator<CastExpr> in(const File &file);
  static gap::generator<CastExpr> in(const Index &index);
  static gap::generator<CastExpr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<CastExpr> by_id(const Index &, EntityId);

  static gap::generator<CastExpr> containing(const Decl &decl);
  static gap::generator<CastExpr> containing(const std::optional<Decl> &decl);

  static gap::generator<CastExpr> containing(const Stmt &stmt);
  static gap::generator<CastExpr> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<CastExpr> from(const Stmt &parent);

  inline static std::optional<CastExpr> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return CastExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  inline static std::optional<CastExpr> from(const Reference &r) {
    return CastExpr::from(r.as_statement());
  }

  inline static std::optional<CastExpr> from(const TokenContext &t) {
    return CastExpr::from(t.as_statement());
  }

  CastKind cast_kind(void) const;
  std::string_view cast_kind_name(void) const;
  std::optional<NamedDecl> conversion_function(void) const;
  Expr sub_expression(void) const;
  Expr sub_expression_as_written(void) const;
  std::optional<FieldDecl> target_union_field(void) const;
  bool has_stored_fp_features(void) const;
};

static_assert(sizeof(CastExpr) == sizeof(Expr));

#endif
} // namespace mx
