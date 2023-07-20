// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "AsmStmt.h"

namespace mx {
class EntityProvider;
class Index;
class AsmStmt;
class Decl;
class Expr;
class MSAsmStmt;
class Stmt;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MSAsmStmt : public AsmStmt {
 private:
  friend class FragmentImpl;
  friend class AsmStmt;
  friend class Stmt;
 public:
  static gap::generator<MSAsmStmt> in(const Index &index);
  static gap::generator<MSAsmStmt> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<MSAsmStmt> by_id(const Index &, EntityId);
  static gap::generator<MSAsmStmt> in(const Fragment &frag);
  static gap::generator<MSAsmStmt> in(const File &file);

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::MS_ASM_STMT;
  }

  static gap::generator<MSAsmStmt> containing(const Decl &decl);
  static gap::generator<MSAsmStmt> containing(const std::optional<Decl> &decl);

  static gap::generator<MSAsmStmt> containing(const Stmt &stmt);
  static gap::generator<MSAsmStmt> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<MSAsmStmt> from(const Stmt &parent);

  inline static std::optional<MSAsmStmt> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return MSAsmStmt::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<MSAsmStmt> from(const Reference &r);
  static std::optional<MSAsmStmt> from(const TokenContext &t);

  gap::generator<std::string_view> all_constraints(void) const &;
  std::optional<Expr> nth_all_expression(unsigned n) const;
  unsigned num_all_expressions(void) const;
  gap::generator<Expr> all_expressions(void) const &;
  std::string_view assembly_string(void) const;
  Token l_brace_token(void) const;
  bool has_braces(void) const;
};

static_assert(sizeof(MSAsmStmt) == sizeof(AsmStmt));

#endif
} // namespace mx
