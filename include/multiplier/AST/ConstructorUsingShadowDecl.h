// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <multiplier/AST/UsingShadowDecl.h>

namespace mx {
class EntityProvider;
class Fragment;
class Index;
class CXXRecordDecl;
class ConstructorUsingShadowDecl;
class Decl;
class NamedDecl;
class Stmt;
class Token;
class UsingShadowDecl;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT ConstructorUsingShadowDecl : public UsingShadowDecl {
 private:
  friend class FragmentImpl;
  friend class UsingShadowDecl;
  friend class NamedDecl;
  friend class Decl;
 public:
  static gap::generator<ConstructorUsingShadowDecl> in(const Index &index);
  static gap::generator<ConstructorUsingShadowDecl> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<ConstructorUsingShadowDecl> by_id(const Index &, EntityId);
  static gap::generator<ConstructorUsingShadowDecl> in(const Fragment &frag);
  static gap::generator<ConstructorUsingShadowDecl> in(const File &file);

  static std::optional<ConstructorUsingShadowDecl> from(const ir::Operation &op);
  static gap::generator<std::pair<ConstructorUsingShadowDecl, ir::Operation>> in(const Compilation &tu);
  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::CONSTRUCTOR_USING_SHADOW;
  }

  static gap::generator<ConstructorUsingShadowDecl> containing(const Decl &decl);
  static gap::generator<ConstructorUsingShadowDecl> containing(const std::optional<Decl> &decl);

  static gap::generator<ConstructorUsingShadowDecl> containing(const Stmt &stmt);
  static gap::generator<ConstructorUsingShadowDecl> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  ConstructorUsingShadowDecl canonical_declaration(void) const;
  std::optional<ConstructorUsingShadowDecl> definition(void) const;
  gap::generator<ConstructorUsingShadowDecl> redeclarations(void) const &;
  static std::optional<ConstructorUsingShadowDecl> from_base(const Decl &parent);
  inline static std::optional<ConstructorUsingShadowDecl> from(const Decl &parent) {
    return from_base(parent);
  }
  static std::optional<ConstructorUsingShadowDecl> from(const std::optional<Decl> &parent);
  static std::optional<ConstructorUsingShadowDecl> from(const Reference &r);
  static std::optional<ConstructorUsingShadowDecl> from(const VariantEntity &e);
  static std::optional<ConstructorUsingShadowDecl> from(const TokenContext &t);

  bool constructs_virtual_base(void) const;
  CXXRecordDecl constructed_base_class(void) const;
  std::optional<ConstructorUsingShadowDecl> constructed_base_class_shadow_declaration(void) const;
  CXXRecordDecl nominated_base_class(void) const;
  std::optional<ConstructorUsingShadowDecl> nominated_base_class_shadow_declaration(void) const;
};

static_assert(sizeof(ConstructorUsingShadowDecl) == sizeof(UsingShadowDecl));

#endif
} // namespace mx
