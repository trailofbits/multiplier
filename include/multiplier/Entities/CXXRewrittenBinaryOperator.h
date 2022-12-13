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

#include "BinaryOperatorKind.h"
#include "Expr.h"
#include "StmtKind.h"

namespace mx {
class CXXRewrittenBinaryOperator;
class Expr;
class Stmt;
class ValueStmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using CXXRewrittenBinaryOperatorRange = DerivedEntityRange<StmtIterator, CXXRewrittenBinaryOperator>;
using CXXRewrittenBinaryOperatorContainingTokenRange = DerivedEntityRange<TokenContextIterator, CXXRewrittenBinaryOperator>;
using CXXRewrittenBinaryOperatorContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, CXXRewrittenBinaryOperator>;

class CXXRewrittenBinaryOperator : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static CXXRewrittenBinaryOperatorRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static CXXRewrittenBinaryOperatorContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : CXXRewrittenBinaryOperator::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::CXX_REWRITTEN_BINARY_OPERATOR;
  }

  static CXXRewrittenBinaryOperatorContainingStmtRange containing(const Decl &decl);
  static CXXRewrittenBinaryOperatorContainingStmtRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<CXXRewrittenBinaryOperator> from(const TokenContext &c);
  static std::optional<CXXRewrittenBinaryOperator> from(const Expr &parent);

  inline static std::optional<CXXRewrittenBinaryOperator> from(const std::optional<Expr> &parent) {
    if (parent) {
      return CXXRewrittenBinaryOperator::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<CXXRewrittenBinaryOperator> from(const ValueStmt &parent);

  inline static std::optional<CXXRewrittenBinaryOperator> from(const std::optional<ValueStmt> &parent) {
    if (parent) {
      return CXXRewrittenBinaryOperator::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<CXXRewrittenBinaryOperator> from(const Stmt &parent);

  inline static std::optional<CXXRewrittenBinaryOperator> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return CXXRewrittenBinaryOperator::from(parent.value());
    } else {
      return std::nullopt;
    }
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
