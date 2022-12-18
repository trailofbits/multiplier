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

#include "Expr.h"
#include "StmtKind.h"
#include "StringLiteralStringKind.h"

namespace mx {
class Expr;
class Stmt;
class StringLiteral;
class ValueStmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using StringLiteralRange = DerivedEntityRange<StmtIterator, StringLiteral>;
using StringLiteralContainingTokenRange = DerivedEntityRange<TokenContextIterator, StringLiteral>;
using StringLiteralContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, StringLiteral>;

class StringLiteral : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static StringLiteralRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static StringLiteralContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(tok.context());
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : StringLiteral::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::STRING_LITERAL;
  }

  static StringLiteralContainingStmtRange containing(const Decl &decl);
  static StringLiteralContainingStmtRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<StringLiteral> from(const TokenContext &c);
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
