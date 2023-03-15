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
class OMPDeclarativeDirectiveValueDecl;
class OMPDeclareMapperDecl;
class Stmt;
class Token;
class ValueDecl;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class OMPDeclarativeDirectiveValueDecl : public ValueDecl {
 private:
  friend class FragmentImpl;
  friend class ValueDecl;
  friend class NamedDecl;
  friend class Decl;
 public:
  static gap::generator<OMPDeclarativeDirectiveValueDecl> in(const Fragment &frag);
  static gap::generator<OMPDeclarativeDirectiveValueDecl> in(const File &file);
  static gap::generator<OMPDeclarativeDirectiveValueDecl> in(const Index &index);
  static gap::generator<OMPDeclarativeDirectiveValueDecl> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<OMPDeclarativeDirectiveValueDecl> by_id(const Index &, EntityId);

  static gap::generator<OMPDeclarativeDirectiveValueDecl> containing(const Decl &decl);
  static gap::generator<OMPDeclarativeDirectiveValueDecl> containing(const std::optional<Decl> &decl);

  static gap::generator<OMPDeclarativeDirectiveValueDecl> containing(const Stmt &stmt);
  static gap::generator<OMPDeclarativeDirectiveValueDecl> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  gap::generator<OMPDeclarativeDirectiveValueDecl> redeclarations(void) const &;
  static std::optional<OMPDeclarativeDirectiveValueDecl> from(const Decl &parent);

  inline static std::optional<OMPDeclarativeDirectiveValueDecl> from(const std::optional<Decl> &parent) {
    if (parent) {
      return OMPDeclarativeDirectiveValueDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<OMPDeclarativeDirectiveValueDecl> from(const Reference &r);
  static std::optional<OMPDeclarativeDirectiveValueDecl> from(const TokenContext &t);

};

static_assert(sizeof(OMPDeclarativeDirectiveValueDecl) == sizeof(ValueDecl));

#endif
} // namespace mx
