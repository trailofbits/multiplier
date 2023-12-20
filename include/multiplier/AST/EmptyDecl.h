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
class EmptyDecl;
class Stmt;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT EmptyDecl : public Decl {
 private:
  friend class FragmentImpl;
  friend class Decl;
 public:
  static gap::generator<EmptyDecl> in(const Index &index);
  static gap::generator<EmptyDecl> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<EmptyDecl> by_id(const Index &, EntityId);
  static gap::generator<EmptyDecl> in(const Fragment &frag);
  static gap::generator<EmptyDecl> in(const File &file);

  static std::optional<EmptyDecl> from(const ir::Operation &op);
  static gap::generator<std::pair<EmptyDecl, ir::Operation>> in(const Compilation &tu);
  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::EMPTY;
  }

  static gap::generator<EmptyDecl> containing(const Decl &decl);
  static gap::generator<EmptyDecl> containing(const std::optional<Decl> &decl);

  static gap::generator<EmptyDecl> containing(const Stmt &stmt);
  static gap::generator<EmptyDecl> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  EmptyDecl canonical_declaration(void) const;
  std::optional<EmptyDecl> definition(void) const;
  gap::generator<EmptyDecl> redeclarations(void) const &;
  static std::optional<EmptyDecl> from_base(const Decl &parent);
  inline static std::optional<EmptyDecl> from(const Decl &parent) {
    return from_base(parent);
  }
  static std::optional<EmptyDecl> from(const std::optional<Decl> &parent);
  static std::optional<EmptyDecl> from(const Reference &r);
  static std::optional<EmptyDecl> from(const VariantEntity &e);
  static std::optional<EmptyDecl> from(const TokenContext &t);

};

static_assert(sizeof(EmptyDecl) == sizeof(Decl));

#endif
} // namespace mx
