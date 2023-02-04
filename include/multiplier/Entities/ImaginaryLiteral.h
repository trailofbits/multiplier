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

#include "Expr.h"
#include "StmtKind.h"

namespace mx {
class Expr;
class ImaginaryLiteral;
class Stmt;
class ValueStmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class ImaginaryLiteral : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  static gap::generator<ImaginaryLiteral> in(const Fragment &frag);
  static gap::generator<ImaginaryLiteral> containing(const Token &tok);
  bool contains(const Token &tok) const;

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::IMAGINARY_LITERAL;
  }

  static gap::generator<ImaginaryLiteral> containing(const Decl &decl);
  static gap::generator<ImaginaryLiteral> containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  inline static std::optional<ImaginaryLiteral> from(const Reference &r) {
    return from(r.as_statement());
  }

  inline static std::optional<ImaginaryLiteral> from(const TokenContext &t) {
    return from(t.as_statement());
  }

  static std::optional<ImaginaryLiteral> from(const Expr &parent);

  inline static std::optional<ImaginaryLiteral> from(const std::optional<Expr> &parent) {
    if (parent) {
      return ImaginaryLiteral::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ImaginaryLiteral> from(const ValueStmt &parent);

  inline static std::optional<ImaginaryLiteral> from(const std::optional<ValueStmt> &parent) {
    if (parent) {
      return ImaginaryLiteral::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ImaginaryLiteral> from(const Stmt &parent);

  inline static std::optional<ImaginaryLiteral> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return ImaginaryLiteral::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  Expr sub_expression(void) const;
};

static_assert(sizeof(ImaginaryLiteral) == sizeof(Expr));

#endif
} // namespace mx
