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
#include "StringLiteralStringKind.h"

namespace mx {
class Expr;
class Stmt;
class StringLiteral;
class ValueStmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class StringLiteral : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  static gap::generator<StringLiteral> in(const Fragment &frag);
  static gap::generator<StringLiteral> containing(const Token &tok);
  bool contains(const Token &tok) const;

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::STRING_LITERAL;
  }

  static gap::generator<StringLiteral> containing(const Decl &decl);
  static gap::generator<StringLiteral> containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  inline static std::optional<StringLiteral> from(const Reference &r) {
    return from(r.as_statement());
  }

  inline static std::optional<StringLiteral> from(const TokenContext &t) {
    return from(t.as_statement());
  }

  static std::optional<StringLiteral> from(const Expr &parent);

  inline static std::optional<StringLiteral> from(const std::optional<Expr> &parent) {
    if (parent) {
      return StringLiteral::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<StringLiteral> from(const ValueStmt &parent);

  inline static std::optional<StringLiteral> from(const std::optional<ValueStmt> &parent) {
    if (parent) {
      return StringLiteral::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<StringLiteral> from(const Stmt &parent);

  inline static std::optional<StringLiteral> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return StringLiteral::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  std::optional<bool> contains_non_ascii(void) const;
  std::optional<bool> contains_non_ascii_or_null(void) const;
  std::string_view bytes(void) const;
  StringLiteralStringKind string_kind(void) const;
  std::optional<std::string_view> string(void) const;
  bool is_ordinary(void) const;
  bool is_pascal(void) const;
  bool is_utf16(void) const;
  bool is_utf32(void) const;
  bool is_utf8(void) const;
  bool is_wide(void) const;
};

static_assert(sizeof(StringLiteral) == sizeof(Expr));

#endif
} // namespace mx
