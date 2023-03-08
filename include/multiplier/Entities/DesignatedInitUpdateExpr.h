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

#include "Expr.h"

namespace mx {
class Decl;
class DesignatedInitUpdateExpr;
class Expr;
class InitListExpr;
class Stmt;
class Token;
class ValueStmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class DesignatedInitUpdateExpr : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  static gap::generator<DesignatedInitUpdateExpr> in(const Fragment &frag);
  static gap::generator<DesignatedInitUpdateExpr> in(const File &file);
  static gap::generator<DesignatedInitUpdateExpr> in(const Index &index);
  static gap::generator<DesignatedInitUpdateExpr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<DesignatedInitUpdateExpr> by_id(const Index &, EntityId);

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::DESIGNATED_INIT_UPDATE_EXPR;
  }

  static gap::generator<DesignatedInitUpdateExpr> containing(const Decl &decl);
  static gap::generator<DesignatedInitUpdateExpr> containing(const std::optional<Decl> &decl);

  static gap::generator<DesignatedInitUpdateExpr> containing(const Stmt &stmt);
  static gap::generator<DesignatedInitUpdateExpr> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<DesignatedInitUpdateExpr> from(const Stmt &parent);

  inline static std::optional<DesignatedInitUpdateExpr> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return DesignatedInitUpdateExpr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  inline static std::optional<DesignatedInitUpdateExpr> from(const Reference &r) {
    return DesignatedInitUpdateExpr::from(r.as_statement());
  }

  inline static std::optional<DesignatedInitUpdateExpr> from(const TokenContext &t) {
    return DesignatedInitUpdateExpr::from(t.as_statement());
  }

  Expr base(void) const;
  InitListExpr updater(void) const;
};

static_assert(sizeof(DesignatedInitUpdateExpr) == sizeof(Expr));

#endif
} // namespace mx
