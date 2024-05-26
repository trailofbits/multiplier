// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <multiplier/AST/Decl.h>

namespace mx {
class EntityProvider;
class Fragment;
class Index;
class Decl;
class File;
class OMPDeclarativeDirectiveDecl;
class Stmt;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT OMPDeclarativeDirectiveDecl : public Decl {
 private:
  friend class FragmentImpl;
  friend class Decl;
 public:
  static gap::generator<OMPDeclarativeDirectiveDecl> in(const Index &index);
  static gap::generator<OMPDeclarativeDirectiveDecl> in(const Fragment &frag);
  static gap::generator<OMPDeclarativeDirectiveDecl> in(const File &file);
  static gap::generator<OMPDeclarativeDirectiveDecl> containing(const Token &tok);
  bool contains(const Token &tok) const;

  static std::optional<OMPDeclarativeDirectiveDecl> from(const ir::Operation &op);
  static gap::generator<std::pair<OMPDeclarativeDirectiveDecl, ir::Operation>> in(const Compilation &tu);
  static gap::generator<OMPDeclarativeDirectiveDecl> containing(const Decl &decl);
  static gap::generator<OMPDeclarativeDirectiveDecl> containing(const std::optional<Decl> &decl);

  static gap::generator<OMPDeclarativeDirectiveDecl> containing(const Stmt &stmt);
  static gap::generator<OMPDeclarativeDirectiveDecl> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  OMPDeclarativeDirectiveDecl canonical_declaration(void) const;
  std::optional<OMPDeclarativeDirectiveDecl> definition(void) const;
  gap::generator<OMPDeclarativeDirectiveDecl> redeclarations(void) const &;
  static std::optional<OMPDeclarativeDirectiveDecl> by_id(const Index &, EntityId);

  static std::optional<OMPDeclarativeDirectiveDecl> from_base(const Decl &parent);
  inline static std::optional<OMPDeclarativeDirectiveDecl> from(const Decl &parent) {
    return from_base(parent);
  }
  static std::optional<OMPDeclarativeDirectiveDecl> from(const std::optional<Decl> &parent);
  static std::optional<OMPDeclarativeDirectiveDecl> from(const Reference &r);
  static std::optional<OMPDeclarativeDirectiveDecl> from(const VariantEntity &e);
  static std::optional<OMPDeclarativeDirectiveDecl> from(const TokenContext &t);

};

static_assert(sizeof(OMPDeclarativeDirectiveDecl) == sizeof(Decl));

#endif
} // namespace mx
