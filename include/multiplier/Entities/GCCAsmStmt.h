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

#include "AsmStmt.h"
#include "StmtKind.h"

namespace mx {
class AddrLabelExpr;
class AsmStmt;
class GCCAsmStmt;
class Stmt;
class StringLiteral;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class GCCAsmStmt : public AsmStmt {
 private:
  friend class FragmentImpl;
  friend class AsmStmt;
  friend class Stmt;
 public:
  static gap::generator<GCCAsmStmt> in(const Fragment &frag);
  static gap::generator<GCCAsmStmt> in(const File &file);
  static gap::generator<GCCAsmStmt> in(const Index &index);
  static gap::generator<GCCAsmStmt> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<GCCAsmStmt> by_id(const Index &, EntityId);

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::GCC_ASM_STMT;
  }

  static gap::generator<GCCAsmStmt> containing(const Decl &decl);
  static gap::generator<GCCAsmStmt> containing(const std::optional<Decl> &decl);

  static gap::generator<GCCAsmStmt> containing(const Stmt &stmt);
  static gap::generator<GCCAsmStmt> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<GCCAsmStmt> from(const Stmt &parent);

  inline static std::optional<GCCAsmStmt> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return GCCAsmStmt::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  inline static std::optional<GCCAsmStmt> from(const Reference &r) {
    return GCCAsmStmt::from(r.as_statement());
  }

  inline static std::optional<GCCAsmStmt> from(const TokenContext &t) {
    return GCCAsmStmt::from(t.as_statement());
  }

  StringLiteral assembly_string(void) const;
  Token r_paren_token(void) const;
  bool is_assembly_goto(void) const;
  std::optional<AddrLabelExpr> nth_label(unsigned n) const;
  gap::generator<AddrLabelExpr> labels(void) const;
  std::optional<StringLiteral> nth_output_constraint_literal(unsigned n) const;
  gap::generator<StringLiteral> output_constraint_literals(void) const;
  std::optional<std::string_view> nth_output_name(unsigned n) const;
  gap::generator<std::string_view> output_names(void) const;
  std::optional<StringLiteral> nth_input_constraint_literal(unsigned n) const;
  gap::generator<StringLiteral> input_constraint_literals(void) const;
  std::optional<std::string_view> nth_input_name(unsigned n) const;
  gap::generator<std::string_view> input_names(void) const;
  std::optional<StringLiteral> nth_clobber_string_literal(unsigned n) const;
  gap::generator<StringLiteral> clobber_string_literals(void) const;
  std::optional<AddrLabelExpr> nth_label_expression(unsigned n) const;
  gap::generator<AddrLabelExpr> label_expressions(void) const;
  std::optional<std::string_view> nth_label_name(unsigned n) const;
  gap::generator<std::string_view> label_names(void) const;
};

static_assert(sizeof(GCCAsmStmt) == sizeof(AsmStmt));

#endif
} // namespace mx
