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
class AccessSpecDecl;
class Decl;
class Stmt;
class Token;
namespace mx {
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class AccessSpecDecl : public Decl {
 private:
  friend class FragmentImpl;
  friend class Decl;
 public:
  static gap::generator<AccessSpecDecl> in(const Fragment &frag);
  static gap::generator<AccessSpecDecl> in(const File &file);
  static gap::generator<AccessSpecDecl> in(const Index &index);
  static gap::generator<AccessSpecDecl> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<AccessSpecDecl> by_id(const Index &, EntityId);

  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::ACCESS_SPEC;
  }

  static gap::generator<AccessSpecDecl> containing(const Decl &decl);
  static gap::generator<AccessSpecDecl> containing(const std::optional<Decl> &decl);

  static gap::generator<AccessSpecDecl> containing(const Stmt &stmt);
  static gap::generator<AccessSpecDecl> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  AccessSpecDecl canonical_declaration(void) const;
  std::optional<AccessSpecDecl> definition(void) const;
  gap::generator<AccessSpecDecl> redeclarations(void) const &;
  static std::optional<AccessSpecDecl> from(const Decl &parent);

  inline static std::optional<AccessSpecDecl> from(const std::optional<Decl> &parent) {
    if (parent) {
      return AccessSpecDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<AccessSpecDecl> from(const Reference &r);
  static std::optional<AccessSpecDecl> from(const TokenContext &t);

  Token access_specifier_token(void) const;
  Token colon_token(void) const;
};

static_assert(sizeof(AccessSpecDecl) == sizeof(Decl));

#endif
} // namespace mx
