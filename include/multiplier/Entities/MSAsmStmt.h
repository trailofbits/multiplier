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
#include "../Reference.h"
#include "../Types.h"
#include "../Token.h"

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
  static gap::generator<MSAsmStmt> in(const Fragment &frag);
  static gap::generator<MSAsmStmt> containing(const Token &tok);
  bool contains(const Token &tok) const;

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::MS_ASM_STMT;
  }

  static gap::generator<StmtKind> derived_kinds(void);
  static gap::generator<MSAsmStmt> containing(const Decl &decl);
  static gap::generator<MSAsmStmt> containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  inline static std::optional<MSAsmStmt> from(const Reference &r) {
    return from(r.as_statement());
  }

  inline static std::optional<MSAsmStmt> from(const TokenContext &t) {
    return from(t.as_statement());
  }

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

  std::optional<std::string_view> nth_all_constraint(unsigned n) const;
  gap::generator<std::string_view> all_constraints(void) const;
  std::optional<Expr> nth_all_expression(unsigned n) const;
  gap::generator<Expr> all_expressions(void) const;
  std::string_view assembly_string(void) const;
  Token l_brace_token(void) const;
  bool has_braces(void) const;
};

static_assert(sizeof(MSAsmStmt) == sizeof(AsmStmt));

#endif
} // namespace mx
