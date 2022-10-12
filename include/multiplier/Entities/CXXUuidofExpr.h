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
#include "StmtUseSelector.h"

namespace mx {
class CXXUuidofExpr;
class Expr;
class MSGuidDecl;
class Stmt;
class Type;
class ValueStmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using CXXUuidofExprRange = DerivedEntityRange<StmtIterator, CXXUuidofExpr>;
using CXXUuidofExprContainingTokenRange = DerivedEntityRange<TokenContextIterator, CXXUuidofExpr>;
using CXXUuidofExprContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, CXXUuidofExpr>;

class CXXUuidofExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static CXXUuidofExprRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static CXXUuidofExprContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : CXXUuidofExpr::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::CXX_UUIDOF_EXPR;
  }

  static CXXUuidofExprContainingStmtRange containing(const Decl &decl);
  static CXXUuidofExprContainingStmtRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<CXXUuidofExpr> from(const TokenContext &c);
  static std::optional<CXXUuidofExpr> from(const Expr &parent);

  inline static std::optional<CXXUuidofExpr> from(const std::optional<Expr> &parent) {
    if (parent) {
      return CXXUuidofExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<CXXUuidofExpr> from(const ValueStmt &parent);

  inline static std::optional<CXXUuidofExpr> from(const std::optional<ValueStmt> &parent) {
    if (parent) {
      return CXXUuidofExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<CXXUuidofExpr> from(const Stmt &parent);

  inline static std::optional<CXXUuidofExpr> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return CXXUuidofExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  std::optional<Expr> expression_operand(void) const;
  MSGuidDecl guid_declaration(void) const;
  Type type_operand(void) const;
  Type type_operand_source_info(void) const;
  bool is_type_operand(void) const;
};

static_assert(sizeof(CXXUuidofExpr) == sizeof(Expr));

#endif
} // namespace mx
