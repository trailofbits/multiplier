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

#include "AsmStmt.h"
#include "StmtKind.h"

namespace mx {
class AsmStmt;
class Expr;
class MSAsmStmt;
class Stmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MSAsmStmt : public AsmStmt {
 private:
  friend class FragmentImpl;
  friend class AsmStmt;
  friend class Stmt;
 public:
  inline static gap::generator<MSAsmStmt> in(const Fragment &frag) {
    for (auto e : in_internal(frag)) {
      if (auto d = from(e)) {
        co_yield *d;
      }
    }
  }

  inline static gap::generator<MSAsmStmt> containing(const Token &tok) {
    for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
      if (auto d = from(*ctx)) {
        co_yield *d;
      }
    }
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : MSAsmStmt::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::MS_ASM_STMT;
  }

  static gap::generator<MSAsmStmt> containing(const Decl &decl);
  static gap::generator<MSAsmStmt> containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<MSAsmStmt> from(const TokenContext &c);
  static std::optional<MSAsmStmt> from(const AsmStmt &parent);

  inline static std::optional<MSAsmStmt> from(const std::optional<AsmStmt> &parent) {
    if (parent) {
      return MSAsmStmt::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<MSAsmStmt> from(const Stmt &parent);

  inline static std::optional<MSAsmStmt> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return MSAsmStmt::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  std::vector<std::string_view> all_constraints(void) const;
  std::vector<Expr> all_expressions(void) const;
  std::string_view assembly_string(void) const;
  Token l_brace_token(void) const;
  bool has_braces(void) const;
};

static_assert(sizeof(MSAsmStmt) == sizeof(AsmStmt));

#endif
} // namespace mx
