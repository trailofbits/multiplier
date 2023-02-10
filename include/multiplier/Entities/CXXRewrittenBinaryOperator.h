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

#include "BinaryOperatorKind.h"
#include "Expr.h"
#include "StmtKind.h"

namespace mx {
class CXXRewrittenBinaryOperator;
class Expr;
class Stmt;
class ValueStmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class CXXRewrittenBinaryOperator : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  static gap::generator<CXXRewrittenBinaryOperator> in(const Fragment &frag);
  static gap::generator<CXXRewrittenBinaryOperator> in(const File &file);
  static gap::generator<CXXRewrittenBinaryOperator> in(const Index &index);
  static gap::generator<CXXRewrittenBinaryOperator> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<CXXRewrittenBinaryOperator> by_id(const Index &, EntityId);

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::CXX_REWRITTEN_BINARY_OPERATOR;
  }

  static gap::generator<CXXRewrittenBinaryOperator> containing(const Decl &decl);
  static gap::generator<CXXRewrittenBinaryOperator> containing(const std::optional<Decl> &decl);

  static gap::generator<CXXRewrittenBinaryOperator> containing(const Stmt &stmt);
  static gap::generator<CXXRewrittenBinaryOperator> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<CXXRewrittenBinaryOperator> from(const Stmt &parent);

  inline static std::optional<CXXRewrittenBinaryOperator> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return CXXRewrittenBinaryOperator::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  inline static std::optional<CXXRewrittenBinaryOperator> from(const Reference &r) {
    return CXXRewrittenBinaryOperator::from(r.as_statement());
  }

  inline static std::optional<CXXRewrittenBinaryOperator> from(const TokenContext &t) {
    return CXXRewrittenBinaryOperator::from(t.as_statement());
  }

  Expr lhs(void) const;
  BinaryOperatorKind opcode(void) const;
  std::string_view opcode_string(void) const;
  BinaryOperatorKind operator_(void) const;
  Token operator_token(void) const;
  Expr rhs(void) const;
  Expr semantic_form(void) const;
  bool is_assignment_operation(void) const;
  bool is_comparison_operation(void) const;
  bool is_reversed(void) const;
};

static_assert(sizeof(CXXRewrittenBinaryOperator) == sizeof(Expr));

#endif
} // namespace mx
