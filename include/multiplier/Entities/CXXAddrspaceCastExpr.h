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

#include "CXXNamedCastExpr.h"
#include "StmtKind.h"

namespace mx {
class CXXAddrspaceCastExpr;
class CXXNamedCastExpr;
class CastExpr;
class ExplicitCastExpr;
class Expr;
class Stmt;
class ValueStmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using CXXAddrspaceCastExprRange = DerivedEntityRange<StmtIterator, CXXAddrspaceCastExpr>;
using CXXAddrspaceCastExprContainingTokenRange = DerivedEntityRange<TokenContextIterator, CXXAddrspaceCastExpr>;
using CXXAddrspaceCastExprContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, CXXAddrspaceCastExpr>;

class CXXAddrspaceCastExpr : public CXXNamedCastExpr {
 private:
  friend class FragmentImpl;
  friend class CXXNamedCastExpr;
  friend class ExplicitCastExpr;
  friend class CastExpr;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static CXXAddrspaceCastExprRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static CXXAddrspaceCastExprContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : CXXAddrspaceCastExpr::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::CXX_ADDRSPACE_CAST_EXPR;
  }

  static CXXAddrspaceCastExprContainingStmtRange containing(const Decl &decl);
  static CXXAddrspaceCastExprContainingStmtRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<CXXAddrspaceCastExpr> from(const TokenContext &c);
  static std::optional<CXXAddrspaceCastExpr> from(const CXXNamedCastExpr &parent);

  inline static std::optional<CXXAddrspaceCastExpr> from(const std::optional<CXXNamedCastExpr> &parent) {
    if (parent) {
      return CXXAddrspaceCastExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<CXXAddrspaceCastExpr> from(const ExplicitCastExpr &parent);

  inline static std::optional<CXXAddrspaceCastExpr> from(const std::optional<ExplicitCastExpr> &parent) {
    if (parent) {
      return CXXAddrspaceCastExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<CXXAddrspaceCastExpr> from(const CastExpr &parent);

  inline static std::optional<CXXAddrspaceCastExpr> from(const std::optional<CastExpr> &parent) {
    if (parent) {
      return CXXAddrspaceCastExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<CXXAddrspaceCastExpr> from(const Expr &parent);

  inline static std::optional<CXXAddrspaceCastExpr> from(const std::optional<Expr> &parent) {
    if (parent) {
      return CXXAddrspaceCastExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<CXXAddrspaceCastExpr> from(const ValueStmt &parent);

  inline static std::optional<CXXAddrspaceCastExpr> from(const std::optional<ValueStmt> &parent) {
    if (parent) {
      return CXXAddrspaceCastExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<CXXAddrspaceCastExpr> from(const Stmt &parent);

  inline static std::optional<CXXAddrspaceCastExpr> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return CXXAddrspaceCastExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

};

static_assert(sizeof(CXXAddrspaceCastExpr) == sizeof(CXXNamedCastExpr));

#endif
} // namespace mx
