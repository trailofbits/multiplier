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
  inline static gap::generator<GCCAsmStmt> in(const Fragment &frag) {
    for(auto e : in_internal(frag)) {
      if(auto d = from(e)) {
        co_yield *d;
      }
    }
  }

  inline static gap::generator<GCCAsmStmt> containing(const Token &tok) {
    for(auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
      if(auto d = from(*ctx)) {
        co_yield *d;
      }
    }
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

  static gap::generator<GCCAsmStmt> containing(const Decl &decl);
  static gap::generator<GCCAsmStmt> containing(const Stmt &stmt);

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
