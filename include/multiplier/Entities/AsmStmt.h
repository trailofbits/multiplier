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

#include "Stmt.h"
#include "StmtKind.h"

namespace mx {
class AsmStmt;
class Expr;
class Stmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class AsmStmt : public Stmt {
 private:
  friend class FragmentImpl;
  friend class Stmt;
 public:
  inline static gap::generator<AsmStmt> in(const Fragment &frag) {
    for(auto e : in_internal(frag)) {
      if(auto d = from(e)) {
        co_yield *d;
      }
    }
  }

  inline static gap::generator<AsmStmt> containing(const Token &tok) {
    for(auto ctx = TokenContext::of(tok); ctx.has_value(); ctx = ctx->parent()) {
      if(auto d = from(*ctx)) {
        co_yield *d;
      }
    }
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : AsmStmt::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  static gap::generator<AsmStmt> containing(const Decl &decl);
  static gap::generator<AsmStmt> containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<AsmStmt> from(const TokenContext &c);
  static std::optional<AsmStmt> from(const Stmt &parent);

  inline static std::optional<AsmStmt> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return AsmStmt::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  std::string_view generate_assembly_string(void) const;
  Token assembly_token(void) const;
  std::vector<Expr> inputs(void) const;
  bool is_simple(void) const;
  bool is_volatile(void) const;
  std::vector<Expr> outputs(void) const;
  std::vector<std::string_view> output_constraints(void) const;
  std::vector<Expr> output_expressions(void) const;
  std::vector<std::string_view> input_constraints(void) const;
  std::vector<Expr> input_expressions(void) const;
  std::vector<std::string_view> clobbers(void) const;
};

static_assert(sizeof(AsmStmt) == sizeof(Stmt));

#endif
} // namespace mx
