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
class NamedDecl;
class Stmt;
class Token;
class UnnamedGlobalConstantDecl;
class ValueDecl;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class UnnamedGlobalConstantDecl : public ValueDecl {
 private:
  friend class FragmentImpl;
  friend class ValueDecl;
  friend class NamedDecl;
  friend class Decl;
 public:
  static gap::generator<UnnamedGlobalConstantDecl> in(const Fragment &frag);
  static gap::generator<UnnamedGlobalConstantDecl> in(const File &file);
  static gap::generator<UnnamedGlobalConstantDecl> in(const Index &index);
  static gap::generator<UnnamedGlobalConstantDecl> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<UnnamedGlobalConstantDecl> by_id(const Index &, EntityId);

  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::UNNAMED_GLOBAL_CONSTANT;
  }

  static gap::generator<UnnamedGlobalConstantDecl> containing(const Decl &decl);
  static gap::generator<UnnamedGlobalConstantDecl> containing(const std::optional<Decl> &decl);

  static gap::generator<UnnamedGlobalConstantDecl> containing(const Stmt &stmt);
  static gap::generator<UnnamedGlobalConstantDecl> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  gap::generator<UnnamedGlobalConstantDecl> redeclarations(void) const &;
  static std::optional<UnnamedGlobalConstantDecl> from(const Decl &parent);

  inline static std::optional<UnnamedGlobalConstantDecl> from(const std::optional<Decl> &parent) {
    if (parent) {
      return UnnamedGlobalConstantDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<UnnamedGlobalConstantDecl> from(const Reference &r);
  static std::optional<UnnamedGlobalConstantDecl> from(const TokenContext &t);

};

static_assert(sizeof(UnnamedGlobalConstantDecl) == sizeof(ValueDecl));

#endif
} // namespace mx
