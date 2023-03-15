// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Stmt.h"

namespace mx {
class EntityProvider;
class Index;
class AsmStmt;
class Decl;
class Expr;
class GCCAsmStmt;
class MSAsmStmt;
class Stmt;
class Token;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class AsmStmt : public Stmt {
 private:
  friend class FragmentImpl;
  friend class Stmt;
 public:
  static gap::generator<AsmStmt> in(const Fragment &frag);
  static gap::generator<AsmStmt> in(const File &file);
  static gap::generator<AsmStmt> in(const Index &index);
  static gap::generator<AsmStmt> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<AsmStmt> by_id(const Index &, EntityId);

  static gap::generator<AsmStmt> containing(const Decl &decl);
  static gap::generator<AsmStmt> containing(const std::optional<Decl> &decl);

  static gap::generator<AsmStmt> containing(const Stmt &stmt);
  static gap::generator<AsmStmt> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<AsmStmt> from(const Stmt &parent);

  inline static std::optional<AsmStmt> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return AsmStmt::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<AsmStmt> from(const Reference &r);
  static std::optional<AsmStmt> from(const TokenContext &t);

  std::string_view generate_assembly_string(void) const;
  Token assembly_token(void) const;
  std::optional<Expr> nth_input(unsigned n) const;
  unsigned num_inputs(void) const;
  gap::generator<Expr> inputs(void) const &;
  bool is_simple(void) const;
  bool is_volatile(void) const;
  std::optional<Expr> nth_output(unsigned n) const;
  unsigned num_outputs(void) const;
  gap::generator<Expr> outputs(void) const &;
  gap::generator<std::string_view> output_constraints(void) const &;
  std::optional<Expr> nth_output_expression(unsigned n) const;
  unsigned num_output_expressions(void) const;
  gap::generator<Expr> output_expressions(void) const &;
  gap::generator<std::string_view> input_constraints(void) const &;
  std::optional<Expr> nth_input_expression(unsigned n) const;
  unsigned num_input_expressions(void) const;
  gap::generator<Expr> input_expressions(void) const &;
  gap::generator<std::string_view> clobbers(void) const &;
};

static_assert(sizeof(AsmStmt) == sizeof(Stmt));

#endif
} // namespace mx
