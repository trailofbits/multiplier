// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "OMPDeclarativeDirectiveDecl.h"

namespace mx {
class EntityProvider;
class Index;
class Decl;
class OMPDeclarativeDirectiveDecl;
class OMPRequiresDecl;
class Stmt;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class OMPRequiresDecl : public OMPDeclarativeDirectiveDecl {
 private:
  friend class FragmentImpl;
  friend class OMPDeclarativeDirectiveDecl;
  friend class Decl;
 public:
  static gap::generator<OMPRequiresDecl> in(const Fragment &frag);
  static gap::generator<OMPRequiresDecl> in(const File &file);
  static gap::generator<OMPRequiresDecl> in(const Index &index);
  static gap::generator<OMPRequiresDecl> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<OMPRequiresDecl> by_id(const Index &, EntityId);

  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::OMP_REQUIRES;
  }

  static gap::generator<OMPRequiresDecl> containing(const Decl &decl);
  static gap::generator<OMPRequiresDecl> containing(const std::optional<Decl> &decl);

  static gap::generator<OMPRequiresDecl> containing(const Stmt &stmt);
  static gap::generator<OMPRequiresDecl> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  OMPRequiresDecl canonical_declaration(void) const;
  std::optional<OMPRequiresDecl> definition(void) const;
  gap::generator<OMPRequiresDecl> redeclarations(void) const &;
  static std::optional<OMPRequiresDecl> from(const Decl &parent);

  inline static std::optional<OMPRequiresDecl> from(const std::optional<Decl> &parent) {
    if (parent) {
      return OMPRequiresDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<OMPRequiresDecl> from(const Reference &r);
  static std::optional<OMPRequiresDecl> from(const TokenContext &t);

};

static_assert(sizeof(OMPRequiresDecl) == sizeof(OMPDeclarativeDirectiveDecl));

#endif
} // namespace mx
