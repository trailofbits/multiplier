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

#include "Stmt.h"
#include "StmtKind.h"

namespace mx {
class CompoundStmt;
class SEHFinallyStmt;
class Stmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class SEHFinallyStmt : public Stmt {
 private:
  friend class FragmentImpl;
  friend class Stmt;
 public:
  inline static gap::generator<SEHFinallyStmt> in(const Fragment &frag) {
    for (auto e : in_internal(frag)) {
      if (auto d = from(e)) {
        co_yield *d;
      }
    }
  }

  inline static gap::generator<SEHFinallyStmt> containing(const Token &tok) {
    for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
      if (auto d = from(*ctx)) {
        co_yield *d;
      }
    }
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : SEHFinallyStmt::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::SEH_FINALLY_STMT;
  }

  static gap::generator<SEHFinallyStmt> containing(const Decl &decl);
  static gap::generator<SEHFinallyStmt> containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<SEHFinallyStmt> from(const TokenContext &c);
  static std::optional<SEHFinallyStmt> from(const Stmt &parent);

  inline static std::optional<SEHFinallyStmt> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return SEHFinallyStmt::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  CompoundStmt block(void) const;
  Token finally_token(void) const;
};

static_assert(sizeof(SEHFinallyStmt) == sizeof(Stmt));

#endif
} // namespace mx
