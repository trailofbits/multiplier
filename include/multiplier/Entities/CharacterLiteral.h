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

#include "CharacterLiteralCharacterKind.h"
#include "Expr.h"
#include "StmtKind.h"

namespace mx {
class CharacterLiteral;
class Expr;
class Stmt;
class ValueStmt;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using CharacterLiteralRange = DerivedEntityRange<StmtIterator, CharacterLiteral>;
using CharacterLiteralContainingTokenRange = DerivedEntityRange<TokenContextIterator, CharacterLiteral>;
using CharacterLiteralContainingStmtRange = DerivedEntityRange<ParentStmtIteratorImpl<Stmt>, CharacterLiteral>;

class CharacterLiteral : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  inline static CharacterLiteralRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static CharacterLiteralContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for (auto &parent : CharacterLiteral::containing(tok)) {
      if (parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::CHARACTER_LITERAL;
  }

  static CharacterLiteralContainingStmtRange containing(const Decl &decl);
  static CharacterLiteralContainingStmtRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<CharacterLiteral> from(const TokenContext &c);
  static std::optional<CharacterLiteral> from(const Expr &parent);

  inline static std::optional<CharacterLiteral> from(const std::optional<Expr> &parent) {
    if (parent) {
      return CharacterLiteral::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<CharacterLiteral> from(const ValueStmt &parent);

  inline static std::optional<CharacterLiteral> from(const std::optional<ValueStmt> &parent) {
    if (parent) {
      return CharacterLiteral::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<CharacterLiteral> from(const Stmt &parent);

  inline static std::optional<CharacterLiteral> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return CharacterLiteral::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  CharacterLiteralCharacterKind character_kind(void) const;
  Token token(void) const;
};

static_assert(sizeof(CharacterLiteral) == sizeof(Expr));

#endif
} // namespace mx
