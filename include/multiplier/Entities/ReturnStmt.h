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

#include "DeclUseSelector.h"
#include "Stmt.h"
#include "StmtKind.h"
#include "StmtUseSelector.h"

namespace mx {
class Expr;
class ReturnStmt;
class Stmt;
class VarDecl;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class ReturnStmt : public Stmt {
 private:
  friend class FragmentImpl;
  friend class Stmt;
 public:
  inline static gap::generator<ReturnStmt> in(const Fragment &frag) {
    for (auto e : in_internal(frag)) {
      if (auto d = from(e)) {
        co_yield *d;
      }
    }
  }

  inline static gap::generator<ReturnStmt> containing(const Token &tok) {
    for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
      if (auto d = from(*ctx)) {
        co_yield *d;
      }
    }
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : ReturnStmt::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::RETURN_STMT;
  }

  static gap::generator<ReturnStmt> containing(const Decl &decl);
  static gap::generator<ReturnStmt> containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<ReturnStmt> from(const TokenContext &c);
  static std::optional<ReturnStmt> from(const Stmt &parent);

  inline static std::optional<ReturnStmt> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return ReturnStmt::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  std::optional<VarDecl> nrvo_candidate(void) const;
  std::optional<Expr> return_value(void) const;
  Token return_token(void) const;
};

static_assert(sizeof(ReturnStmt) == sizeof(Stmt));

#endif
} // namespace mx
