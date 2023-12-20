// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
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
class Decl;
class NamedDecl;
class Stmt;
class Token;
class Type;
class TypeDecl;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT TypeDecl : public NamedDecl {
 private:
  friend class FragmentImpl;
  friend class NamedDecl;
  friend class Decl;
 public:
  static gap::generator<TypeDecl> in(const Index &index);
  static gap::generator<TypeDecl> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<TypeDecl> by_id(const Index &, EntityId);
  static gap::generator<TypeDecl> in(const Fragment &frag);
  static gap::generator<TypeDecl> in(const File &file);

  static std::optional<TypeDecl> from(const ir::Operation &op);
  static gap::generator<std::pair<TypeDecl, ir::Operation>> in(const Compilation &tu);
  static gap::generator<TypeDecl> containing(const Decl &decl);
  static gap::generator<TypeDecl> containing(const std::optional<Decl> &decl);

  static gap::generator<TypeDecl> containing(const Stmt &stmt);
  static gap::generator<TypeDecl> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  TypeDecl canonical_declaration(void) const;
  std::optional<TypeDecl> definition(void) const;
  gap::generator<TypeDecl> redeclarations(void) const &;
  static std::optional<TypeDecl> from_base(const Decl &parent);
  inline static std::optional<TypeDecl> from(const Decl &parent) {
    return from_base(parent);
  }
  static std::optional<TypeDecl> from(const std::optional<Decl> &parent);
  static std::optional<TypeDecl> from(const Reference &r);
  static std::optional<TypeDecl> from(const VariantEntity &e);
  static std::optional<TypeDecl> from(const TokenContext &t);

  std::optional<Type> type_for_declaration(void) const;
};

static_assert(sizeof(TypeDecl) == sizeof(NamedDecl));

#endif
} // namespace mx
