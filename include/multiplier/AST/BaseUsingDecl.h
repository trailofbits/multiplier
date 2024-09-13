// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <multiplier/AST/NamedDecl.h>

namespace mx {
class EntityProvider;
class Fragment;
class Index;
class BaseUsingDecl;
class Decl;
class File;
class NamedDecl;
class Stmt;
class Token;
class UsingShadowDecl;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT BaseUsingDecl : public NamedDecl {
 private:
  friend class FragmentImpl;
  friend class NamedDecl;
  friend class Decl;
 public:
  static gap::generator<BaseUsingDecl> in(const Index &index);
  static gap::generator<BaseUsingDecl> in(const Fragment &frag);
  static gap::generator<BaseUsingDecl> in(const File &file);
  static gap::generator<BaseUsingDecl> containing(const Token &tok);
  bool contains(const Token &tok) const;

  static std::optional<BaseUsingDecl> from(const ir::Operation &op);
  static gap::generator<std::pair<BaseUsingDecl, ir::Operation>> in(const Compilation &tu);
  static gap::generator<BaseUsingDecl> containing(const Decl &decl);
  static gap::generator<BaseUsingDecl> containing(const std::optional<Decl> &decl);

  static gap::generator<BaseUsingDecl> containing(const Stmt &stmt);
  static gap::generator<BaseUsingDecl> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  BaseUsingDecl canonical_declaration(void) const;
  std::optional<BaseUsingDecl> definition(void) const;
  gap::generator<BaseUsingDecl> redeclarations(void) const &;
  static std::optional<BaseUsingDecl> by_id(const Index &, EntityId);

  static std::optional<BaseUsingDecl> from_base(const Decl &parent);
  inline static std::optional<BaseUsingDecl> from(const Decl &parent) {
    return from_base(parent);
  }
  static std::optional<BaseUsingDecl> from(const std::optional<Decl> &parent);
  static std::optional<BaseUsingDecl> from(const Reference &r);
  static std::optional<BaseUsingDecl> from(const VariantEntity &e);
  static std::optional<BaseUsingDecl> from(const TokenContext &t);

  std::optional<UsingShadowDecl> nth_shadow(unsigned n) const;
  unsigned num_shadows(void) const;
  gap::generator<UsingShadowDecl> shadows(void) const &;
};

static_assert(sizeof(BaseUsingDecl) == sizeof(NamedDecl));

#endif
} // namespace mx
