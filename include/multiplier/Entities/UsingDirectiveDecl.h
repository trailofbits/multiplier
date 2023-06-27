// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "NamedDecl.h"

namespace mx {
class EntityProvider;
class Index;
class Decl;
class NamedDecl;
class Stmt;
class Token;
class UsingDirectiveDecl;
namespace mx {
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class UsingDirectiveDecl : public NamedDecl {
 private:
  friend class FragmentImpl;
  friend class NamedDecl;
  friend class Decl;
 public:
  static gap::generator<UsingDirectiveDecl> in(const Fragment &frag);
  static gap::generator<UsingDirectiveDecl> in(const File &file);
  static gap::generator<UsingDirectiveDecl> in(const Index &index);
  static gap::generator<UsingDirectiveDecl> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<UsingDirectiveDecl> by_id(const Index &, EntityId);

  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::USING_DIRECTIVE;
  }

  static gap::generator<UsingDirectiveDecl> containing(const Decl &decl);
  static gap::generator<UsingDirectiveDecl> containing(const std::optional<Decl> &decl);

  static gap::generator<UsingDirectiveDecl> containing(const Stmt &stmt);
  static gap::generator<UsingDirectiveDecl> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  UsingDirectiveDecl canonical_declaration(void) const;
  std::optional<UsingDirectiveDecl> definition(void) const;
  gap::generator<UsingDirectiveDecl> redeclarations(void) const &;
  static std::optional<UsingDirectiveDecl> from(const Decl &parent);

  inline static std::optional<UsingDirectiveDecl> from(const std::optional<Decl> &parent) {
    if (parent) {
      return UsingDirectiveDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<UsingDirectiveDecl> from(const Reference &r);
  static std::optional<UsingDirectiveDecl> from(const TokenContext &t);

  Token identifier_token(void) const;
  Token namespace_key_token(void) const;
  NamedDecl nominated_namespace_as_written(void) const;
  Token using_token(void) const;
};

static_assert(sizeof(UsingDirectiveDecl) == sizeof(NamedDecl));

#endif
} // namespace mx
