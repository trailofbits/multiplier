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

#include "StmtKind.h"
#include "SwitchCase.h"

namespace mx {
class DefaultStmt;
class Stmt;
class SwitchCase;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using DefaultStmtContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, DefaultStmt>;

class DefaultStmt : public SwitchCase {
 private:
  friend class FragmentImpl;
  friend class SwitchCase;
  friend class Stmt;
 public:
  inline static gap::generator<DefaultStmt> in(const Fragment &frag) {
    for(auto e : in_internal(frag)) {
      if(auto d = from(e)) {
        co_yield *d;
      }
    }
  }

  inline static gap::generator<DefaultStmt> containing(const Token &tok) {
    for(auto ctx = TokenContext::of(tok); ctx.has_value(); ctx = ctx->parent()) {
      if(auto d = from(*ctx)) {
        co_yield *d;
      }
    }
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : DefaultStmt::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::DEFAULT_STMT;
  }

  static DefaultStmtContainingStmtRange containing(const Decl &decl);
  static DefaultStmtContainingStmtRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<DefaultStmt> from(const TokenContext &c);
  static std::optional<DefaultStmt> from(const SwitchCase &parent);

  inline static std::optional<DefaultStmt> from(const std::optional<SwitchCase> &parent) {
    if (parent) {
      return DefaultStmt::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<DefaultStmt> from(const Stmt &parent);

  inline static std::optional<DefaultStmt> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return DefaultStmt::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  Token default_token(void) const;
};

static_assert(sizeof(DefaultStmt) == sizeof(SwitchCase));

#endif
} // namespace mx
