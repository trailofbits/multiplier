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

#include "../Iterator.h"
#include "../Types.h"
#include "../Token.h"
#include "../Use.h"

#include "AsmStmt.h"
#include "StmtKind.h"

namespace mx {
class AddrLabelExpr;
class AsmStmt;
class GCCAsmStmt;
class Stmt;
class StringLiteral;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using GCCAsmStmtRange = DerivedEntityRange<StmtIterator, GCCAsmStmt>;
using GCCAsmStmtContainingTokenRange = DerivedEntityRange<TokenContextIterator, GCCAsmStmt>;
using GCCAsmStmtContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, GCCAsmStmt>;

class GCCAsmStmt : public AsmStmt {
 private:
  friend class FragmentImpl;
  friend class AsmStmt;
  friend class Stmt;
 public:
  inline static GCCAsmStmtRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static GCCAsmStmtContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(tok.context());
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : GCCAsmStmt::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::GCC_ASM_STMT;
  }

  static GCCAsmStmtContainingStmtRange containing(const Decl &decl);
  static GCCAsmStmtContainingStmtRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<GCCAsmStmt> from(const TokenContext &c);
  static std::optional<GCCAsmStmt> from(const AsmStmt &parent);

  inline static std::optional<GCCAsmStmt> from(const std::optional<AsmStmt> &parent) {
    if (parent) {
      return GCCAsmStmt::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<GCCAsmStmt> from(const Stmt &parent);

  inline static std::optional<GCCAsmStmt> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return GCCAsmStmt::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  StringLiteral assembly_string(void) const;
  Token r_paren_token(void) const;
  bool is_assembly_goto(void) const;
  std::vector<AddrLabelExpr> labels(void) const;
  std::vector<StringLiteral> output_constraint_literals(void) const;
  std::vector<std::string_view> output_names(void) const;
  std::vector<StringLiteral> input_constraint_literals(void) const;
  std::vector<std::string_view> input_names(void) const;
  std::vector<StringLiteral> clobber_string_literals(void) const;
  std::vector<AddrLabelExpr> label_expressions(void) const;
  std::vector<std::string_view> label_names(void) const;
};

static_assert(sizeof(GCCAsmStmt) == sizeof(AsmStmt));

#endif
} // namespace mx
