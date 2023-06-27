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
class RequiresExprBodyDecl;
class Stmt;
class Token;
namespace mx {
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class RequiresExprBodyDecl : public Decl {
 private:
  friend class FragmentImpl;
  friend class Decl;
 public:
  static gap::generator<RequiresExprBodyDecl> in(const Fragment &frag);
  static gap::generator<RequiresExprBodyDecl> in(const File &file);
  static gap::generator<RequiresExprBodyDecl> in(const Index &index);
  static gap::generator<RequiresExprBodyDecl> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<RequiresExprBodyDecl> by_id(const Index &, EntityId);

  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::REQUIRES_EXPR_BODY;
  }

  static gap::generator<RequiresExprBodyDecl> containing(const Decl &decl);
  static gap::generator<RequiresExprBodyDecl> containing(const std::optional<Decl> &decl);

  static gap::generator<RequiresExprBodyDecl> containing(const Stmt &stmt);
  static gap::generator<RequiresExprBodyDecl> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  RequiresExprBodyDecl canonical_declaration(void) const;
  std::optional<RequiresExprBodyDecl> definition(void) const;
  gap::generator<RequiresExprBodyDecl> redeclarations(void) const &;
  static std::optional<RequiresExprBodyDecl> from(const Decl &parent);

  inline static std::optional<RequiresExprBodyDecl> from(const std::optional<Decl> &parent) {
    if (parent) {
      return RequiresExprBodyDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<RequiresExprBodyDecl> from(const Reference &r);
  static std::optional<RequiresExprBodyDecl> from(const TokenContext &t);

  gap::generator<Decl> declarations_in_context(void) const &;
};

static_assert(sizeof(RequiresExprBodyDecl) == sizeof(Decl));

#endif
} // namespace mx
