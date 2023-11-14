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
class AddrLabelExpr;
class AsmStmt;
class Decl;
class GCCAsmStmt;
class Stmt;
class StringLiteral;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class GCCAsmStmt : public AsmStmt {
 private:
  friend class FragmentImpl;
  friend class AsmStmt;
  friend class Stmt;
 public:
  static gap::generator<GCCAsmStmt> in(const Index &index);
  static gap::generator<GCCAsmStmt> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<GCCAsmStmt> by_id(const Index &, EntityId);
  static gap::generator<GCCAsmStmt> in(const Fragment &frag);
  static gap::generator<GCCAsmStmt> in(const File &file);

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::GCC_ASM_STMT;
  }

  static gap::generator<GCCAsmStmt> containing(const Decl &decl);
  static gap::generator<GCCAsmStmt> containing(const std::optional<Decl> &decl);

  static gap::generator<GCCAsmStmt> containing(const Stmt &stmt);
  static gap::generator<GCCAsmStmt> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<GCCAsmStmt> from_base(const Stmt &parent);
  inline static std::optional<GCCAsmStmt> from(const Stmt &parent) {
    return from_base(parent);
  }
  static std::optional<GCCAsmStmt> from(const std::optional<Stmt> &parent);
  static std::optional<GCCAsmStmt> from(const Reference &r);
  static std::optional<GCCAsmStmt> from(const VariantEntity &e);
  static std::optional<GCCAsmStmt> from(const TokenContext &t);

  StringLiteral assembly_string(void) const;
  Token r_paren_token(void) const;
  bool is_assembly_goto(void) const;
  std::optional<AddrLabelExpr> nth_label(unsigned n) const;
  unsigned num_labels(void) const;
  gap::generator<AddrLabelExpr> labels(void) const &;
  std::optional<StringLiteral> nth_output_constraint_literal(unsigned n) const;
  unsigned num_output_constraint_literals(void) const;
  gap::generator<StringLiteral> output_constraint_literals(void) const &;
  gap::generator<std::string_view> output_names(void) const &;
  std::optional<StringLiteral> nth_input_constraint_literal(unsigned n) const;
  unsigned num_input_constraint_literals(void) const;
  gap::generator<StringLiteral> input_constraint_literals(void) const &;
  gap::generator<std::string_view> input_names(void) const &;
  std::optional<StringLiteral> nth_clobber_string_literal(unsigned n) const;
  unsigned num_clobber_string_literals(void) const;
  gap::generator<StringLiteral> clobber_string_literals(void) const &;
  std::optional<AddrLabelExpr> nth_label_expression(unsigned n) const;
  unsigned num_label_expressions(void) const;
  gap::generator<AddrLabelExpr> label_expressions(void) const &;
  gap::generator<std::string_view> label_names(void) const &;
};

static_assert(sizeof(GCCAsmStmt) == sizeof(AsmStmt));

#endif
} // namespace mx
