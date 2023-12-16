// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <multiplier/AST/ValueDecl.h>

namespace mx {
class EntityProvider;
class Fragment;
class Index;
class Decl;
class NamedDecl;
class OMPDeclarativeDirectiveValueDecl;
class Stmt;
class Token;
class ValueDecl;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT OMPDeclarativeDirectiveValueDecl : public ValueDecl {
 private:
  friend class FragmentImpl;
  friend class ValueDecl;
  friend class NamedDecl;
  friend class Decl;
 public:
  static gap::generator<OMPDeclarativeDirectiveValueDecl> in(const Index &index);
  static gap::generator<OMPDeclarativeDirectiveValueDecl> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<OMPDeclarativeDirectiveValueDecl> by_id(const Index &, EntityId);
  static gap::generator<OMPDeclarativeDirectiveValueDecl> in(const Fragment &frag);
  static gap::generator<OMPDeclarativeDirectiveValueDecl> in(const File &file);

#ifndef MX_DISABLE_VAST
  static std::optional<OMPDeclarativeDirectiveValueDecl> from(const ir::Operation &op);
  static gap::generator<std::pair<OMPDeclarativeDirectiveValueDecl, ir::Operation>> in(const Compilation &tu);
#endif  // MX_DISABLE_VAST

  static gap::generator<OMPDeclarativeDirectiveValueDecl> containing(const Decl &decl);
  static gap::generator<OMPDeclarativeDirectiveValueDecl> containing(const std::optional<Decl> &decl);

  static gap::generator<OMPDeclarativeDirectiveValueDecl> containing(const Stmt &stmt);
  static gap::generator<OMPDeclarativeDirectiveValueDecl> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  OMPDeclarativeDirectiveValueDecl canonical_declaration(void) const;
  std::optional<OMPDeclarativeDirectiveValueDecl> definition(void) const;
  gap::generator<OMPDeclarativeDirectiveValueDecl> redeclarations(void) const &;
  static std::optional<OMPDeclarativeDirectiveValueDecl> from_base(const Decl &parent);
  inline static std::optional<OMPDeclarativeDirectiveValueDecl> from(const Decl &parent) {
    return from_base(parent);
  }
  static std::optional<OMPDeclarativeDirectiveValueDecl> from(const std::optional<Decl> &parent);
  static std::optional<OMPDeclarativeDirectiveValueDecl> from(const Reference &r);
  static std::optional<OMPDeclarativeDirectiveValueDecl> from(const VariantEntity &e);
  static std::optional<OMPDeclarativeDirectiveValueDecl> from(const TokenContext &t);

};

static_assert(sizeof(OMPDeclarativeDirectiveValueDecl) == sizeof(ValueDecl));

#endif
} // namespace mx
