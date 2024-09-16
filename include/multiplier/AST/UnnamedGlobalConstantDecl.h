// Copyright (c) 2022-present, Trail of Bits, Inc.
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
class File;
class NamedDecl;
class Stmt;
class Token;
class UnnamedGlobalConstantDecl;
class ValueDecl;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT UnnamedGlobalConstantDecl : public ValueDecl {
 private:
  friend class FragmentImpl;
  friend class ValueDecl;
  friend class NamedDecl;
  friend class Decl;
 public:
  static gap::generator<UnnamedGlobalConstantDecl> in(const Index &index);
  static gap::generator<UnnamedGlobalConstantDecl> in(const Fragment &frag);
  static gap::generator<UnnamedGlobalConstantDecl> in(const File &file);
  static gap::generator<UnnamedGlobalConstantDecl> containing(const Token &tok);
  bool contains(const Token &tok) const;

  static std::optional<UnnamedGlobalConstantDecl> from(const ir::Operation &op);
  static gap::generator<std::pair<UnnamedGlobalConstantDecl, ir::Operation>> in(const Compilation &tu);
  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::UNNAMED_GLOBAL_CONSTANT;
  }

  static gap::generator<UnnamedGlobalConstantDecl> containing(const Decl &decl);
  static gap::generator<UnnamedGlobalConstantDecl> containing(const std::optional<Decl> &decl);

  static gap::generator<UnnamedGlobalConstantDecl> containing(const Stmt &stmt);
  static gap::generator<UnnamedGlobalConstantDecl> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  UnnamedGlobalConstantDecl canonical_declaration(void) const;
  std::optional<UnnamedGlobalConstantDecl> definition(void) const;
  gap::generator<UnnamedGlobalConstantDecl> redeclarations(void) const &;
  static std::optional<UnnamedGlobalConstantDecl> by_id(const Index &, EntityId);

  static std::optional<UnnamedGlobalConstantDecl> from_base(const Decl &parent);
  inline static std::optional<UnnamedGlobalConstantDecl> from(const Decl &parent) {
    return from_base(parent);
  }
  static std::optional<UnnamedGlobalConstantDecl> from(const std::optional<Decl> &parent);
  static std::optional<UnnamedGlobalConstantDecl> from(const Reference &r);
  static std::optional<UnnamedGlobalConstantDecl> from(const VariantEntity &e);
  static std::optional<UnnamedGlobalConstantDecl> from(const TokenContext &t);

};

static_assert(sizeof(UnnamedGlobalConstantDecl) == sizeof(ValueDecl));

#endif
} // namespace mx
