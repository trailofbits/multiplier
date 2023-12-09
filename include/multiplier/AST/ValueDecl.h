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
class ValueDecl;
class VarDecl;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT ValueDecl : public NamedDecl {
 private:
  friend class FragmentImpl;
  friend class NamedDecl;
  friend class Decl;
 public:
  static gap::generator<ValueDecl> in(const Index &index);
  static gap::generator<ValueDecl> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<ValueDecl> by_id(const Index &, EntityId);
  static gap::generator<ValueDecl> in(const Fragment &frag);
  static gap::generator<ValueDecl> in(const File &file);

  static std::optional<ValueDecl> from(const ir::hl::Operation &op);
  static gap::generator<std::pair<ValueDecl, ir::hl::Operation>> in(const Compilation &tu);

  static gap::generator<ValueDecl> containing(const Decl &decl);
  static gap::generator<ValueDecl> containing(const std::optional<Decl> &decl);

  static gap::generator<ValueDecl> containing(const Stmt &stmt);
  static gap::generator<ValueDecl> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  ValueDecl canonical_declaration(void) const;
  std::optional<ValueDecl> definition(void) const;
  gap::generator<ValueDecl> redeclarations(void) const &;
  static std::optional<ValueDecl> from_base(const Decl &parent);
  inline static std::optional<ValueDecl> from(const Decl &parent) {
    return from_base(parent);
  }
  static std::optional<ValueDecl> from(const std::optional<Decl> &parent);
  static std::optional<ValueDecl> from(const Reference &r);
  static std::optional<ValueDecl> from(const VariantEntity &e);
  static std::optional<ValueDecl> from(const TokenContext &t);

  std::optional<VarDecl> potentially_decomposed_variable_declaration(void) const;
  Type type(void) const;
  bool is_initializer_capture(void) const;
  bool is_weak(void) const;
};

static_assert(sizeof(ValueDecl) == sizeof(NamedDecl));

#endif
} // namespace mx
