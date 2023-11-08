// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "CharacterLiteralCharacterKind.h"
#include "Expr.h"

namespace mx {
class EntityProvider;
class Index;
class CharacterLiteral;
class Decl;
class Expr;
class Stmt;
class Token;
class ValueStmt;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class CharacterLiteral : public Expr {
 private:
  friend class FragmentImpl;
  friend class Expr;
  friend class ValueStmt;
  friend class Stmt;
 public:
  static gap::generator<CharacterLiteral> in(const Index &index);
  static gap::generator<CharacterLiteral> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<CharacterLiteral> by_id(const Index &, EntityId);
  static gap::generator<CharacterLiteral> in(const Fragment &frag);
  static gap::generator<CharacterLiteral> in(const File &file);

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::CHARACTER_LITERAL;
  }

  static gap::generator<CharacterLiteral> containing(const Decl &decl);
  static gap::generator<CharacterLiteral> containing(const std::optional<Decl> &decl);

  static gap::generator<CharacterLiteral> containing(const Stmt &stmt);
  static gap::generator<CharacterLiteral> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<CharacterLiteral> from(const Stmt &parent);

  inline static std::optional<CharacterLiteral> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return CharacterLiteral::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<CharacterLiteral> from(const Reference &r);
  static std::optional<CharacterLiteral> from(const TokenContext &t);

  CharacterLiteralCharacterKind literal_kind(void) const;
  Token token(void) const;
};

static_assert(sizeof(CharacterLiteral) == sizeof(Expr));

#endif
} // namespace mx
