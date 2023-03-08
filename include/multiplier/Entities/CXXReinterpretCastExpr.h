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

#include "CXXNamedCastExpr.h"

namespace mx {
class CXXNamedCastExpr;
class CXXReinterpretCastExpr;
class CastExpr;
class Decl;
class ExplicitCastExpr;
class Expr;
class Stmt;
class Token;
class ValueStmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class CXXReinterpretCastExpr : public CXXNamedCastExpr {
 private:
  friend class FragmentImpl;
  friend class CXXNamedCastExpr;
  friend class ExplicitCastExpr;
  friend class CastExpr;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  static gap::generator<CXXReinterpretCastExpr> in(const Fragment &frag);
  static gap::generator<CXXReinterpretCastExpr> in(const File &file);
  static gap::generator<CXXReinterpretCastExpr> in(const Index &index);
  static gap::generator<CXXReinterpretCastExpr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<CXXReinterpretCastExpr> by_id(const Index &, EntityId);

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::CXX_REINTERPRET_CAST_EXPR;
  }

  static gap::generator<CXXReinterpretCastExpr> containing(const Decl &decl);
  static gap::generator<CXXReinterpretCastExpr> containing(const std::optional<Decl> &decl);

  static gap::generator<CXXReinterpretCastExpr> containing(const Stmt &stmt);
  static gap::generator<CXXReinterpretCastExpr> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<CXXReinterpretCastExpr> from(const Stmt &parent);

  inline static std::optional<CXXReinterpretCastExpr> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return CXXReinterpretCastExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  inline static std::optional<CXXReinterpretCastExpr> from(const Reference &r) {
    return CXXReinterpretCastExpr::from(r.as_statement());
  }

  inline static std::optional<CXXReinterpretCastExpr> from(const TokenContext &t) {
    return CXXReinterpretCastExpr::from(t.as_statement());
  }

};

static_assert(sizeof(CXXReinterpretCastExpr) == sizeof(CXXNamedCastExpr));

#endif
} // namespace mx
