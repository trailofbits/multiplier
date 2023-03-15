// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "ValueDecl.h"

namespace mx {
class EntityProvider;
class Index;
class Decl;
class FieldDecl;
class IndirectFieldDecl;
class NamedDecl;
class Stmt;
class Token;
class ValueDecl;
class VarDecl;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class IndirectFieldDecl : public ValueDecl {
 private:
  friend class FragmentImpl;
  friend class ValueDecl;
  friend class NamedDecl;
  friend class Decl;
 public:
  static gap::generator<IndirectFieldDecl> in(const Fragment &frag);
  static gap::generator<IndirectFieldDecl> in(const File &file);
  static gap::generator<IndirectFieldDecl> in(const Index &index);
  static gap::generator<IndirectFieldDecl> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<IndirectFieldDecl> by_id(const Index &, EntityId);

  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::INDIRECT_FIELD;
  }

  static gap::generator<IndirectFieldDecl> containing(const Decl &decl);
  static gap::generator<IndirectFieldDecl> containing(const std::optional<Decl> &decl);

  static gap::generator<IndirectFieldDecl> containing(const Stmt &stmt);
  static gap::generator<IndirectFieldDecl> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  gap::generator<IndirectFieldDecl> redeclarations(void) const &;
  static std::optional<IndirectFieldDecl> from(const Decl &parent);

  inline static std::optional<IndirectFieldDecl> from(const std::optional<Decl> &parent) {
    if (parent) {
      return IndirectFieldDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<IndirectFieldDecl> from(const Reference &r);
  static std::optional<IndirectFieldDecl> from(const TokenContext &t);

  gap::generator<NamedDecl> chain(void) const &;
  std::optional<FieldDecl> anonymous_field(void) const;
  std::optional<VarDecl> variable_declaration(void) const;
};

static_assert(sizeof(IndirectFieldDecl) == sizeof(ValueDecl));

#endif
} // namespace mx
