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
class UsingPackDecl;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class UsingPackDecl : public NamedDecl {
 private:
  friend class FragmentImpl;
  friend class NamedDecl;
  friend class Decl;
 public:
  static gap::generator<UsingPackDecl> in(const Fragment &frag);
  static gap::generator<UsingPackDecl> in(const File &file);
  static gap::generator<UsingPackDecl> in(const Index &index);
  static gap::generator<UsingPackDecl> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<UsingPackDecl> by_id(const Index &, EntityId);

  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::USING_PACK;
  }

  static gap::generator<UsingPackDecl> containing(const Decl &decl);
  static gap::generator<UsingPackDecl> containing(const std::optional<Decl> &decl);

  static gap::generator<UsingPackDecl> containing(const Stmt &stmt);
  static gap::generator<UsingPackDecl> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  UsingPackDecl canonical_declaration(void) const;
  std::optional<UsingPackDecl> definition(void) const;
  gap::generator<UsingPackDecl> redeclarations(void) const &;
  static std::optional<UsingPackDecl> from(const Decl &parent);

  inline static std::optional<UsingPackDecl> from(const std::optional<Decl> &parent) {
    if (parent) {
      return UsingPackDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<UsingPackDecl> from(const Reference &r);
  static std::optional<UsingPackDecl> from(const TokenContext &t);

  std::optional<NamedDecl> nth_expansion(unsigned n) const;
  unsigned num_expansions(void) const;
  gap::generator<NamedDecl> expansions(void) const &;
  NamedDecl instantiated_from_using_declaration(void) const;
};

static_assert(sizeof(UsingPackDecl) == sizeof(NamedDecl));

#endif
} // namespace mx
