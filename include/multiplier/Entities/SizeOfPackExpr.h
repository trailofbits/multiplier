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

#include "../Iterator.h"
#include "../Types.h"
#include "../Token.h"
#include "../Use.h"

#include "Expr.h"
#include "StmtKind.h"

namespace mx {
class Expr;
class NamedDecl;
class SizeOfPackExpr;
class Stmt;
class TemplateArgument;
class ValueStmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using SizeOfPackExprRange = DerivedEntityRange<StmtIterator, SizeOfPackExpr>;
using SizeOfPackExprContainingTokenRange = DerivedEntityRange<TokenContextIterator, SizeOfPackExpr>;
using SizeOfPackExprContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, SizeOfPackExpr>;

class SizeOfPackExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static SizeOfPackExprRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static SizeOfPackExprContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(tok.context());
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : SizeOfPackExpr::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::SIZE_OF_PACK_EXPR;
  }

  static SizeOfPackExprContainingStmtRange containing(const Decl &decl);
  static SizeOfPackExprContainingStmtRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<SizeOfPackExpr> from(const TokenContext &c);
  static std::optional<SizeOfPackExpr> from(const Expr &parent);

  inline static std::optional<SizeOfPackExpr> from(const std::optional<Expr> &parent) {
    if (parent) {
      return SizeOfPackExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<SizeOfPackExpr> from(const ValueStmt &parent);

  inline static std::optional<SizeOfPackExpr> from(const std::optional<ValueStmt> &parent) {
    if (parent) {
      return SizeOfPackExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<SizeOfPackExpr> from(const Stmt &parent);

  inline static std::optional<SizeOfPackExpr> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return SizeOfPackExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  Token operator_token(void) const;
  NamedDecl pack(void) const;
  std::optional<unsigned> pack_length(void) const;
  Token pack_token(void) const;
  std::optional<std::vector<TemplateArgument>> partial_arguments(void) const;
  Token r_paren_token(void) const;
  bool is_partially_substituted(void) const;
};

static_assert(sizeof(SizeOfPackExpr) == sizeof(Expr));

#endif
} // namespace mx
