// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Decl.h"

namespace mx {
class EntityProvider;
class Index;
class Decl;
class Expr;
class StaticAssertDecl;
class Stmt;
class StringLiteral;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class StaticAssertDecl : public Decl {
 private:
  friend class FragmentImpl;
  friend class Decl;
 public:
  static gap::generator<StaticAssertDecl> in(const Index &index);
  static gap::generator<StaticAssertDecl> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<StaticAssertDecl> by_id(const Index &, EntityId);
  static gap::generator<StaticAssertDecl> in(const Fragment &frag);
  static gap::generator<StaticAssertDecl> in(const File &file);

  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::STATIC_ASSERT;
  }

  static gap::generator<StaticAssertDecl> containing(const Decl &decl);
  static gap::generator<StaticAssertDecl> containing(const std::optional<Decl> &decl);

  static gap::generator<StaticAssertDecl> containing(const Stmt &stmt);
  static gap::generator<StaticAssertDecl> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  StaticAssertDecl canonical_declaration(void) const;
  std::optional<StaticAssertDecl> definition(void) const;
  gap::generator<StaticAssertDecl> redeclarations(void) const &;
  static std::optional<StaticAssertDecl> from(const Decl &parent);

  inline static std::optional<StaticAssertDecl> from(const std::optional<Decl> &parent) {
    if (parent) {
      return StaticAssertDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<StaticAssertDecl> from(const Reference &r);
  static std::optional<StaticAssertDecl> from(const TokenContext &t);

  Expr assert_expression(void) const;
  StringLiteral message(void) const;
  Token r_paren_token(void) const;
  bool is_failed(void) const;
};

static_assert(sizeof(StaticAssertDecl) == sizeof(Decl));

#endif
} // namespace mx
