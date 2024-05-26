// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <multiplier/AST/TypeDecl.h>

namespace mx {
class EntityProvider;
class Fragment;
class Index;
class Decl;
class File;
class NamedDecl;
class Stmt;
class TemplateTypeParmDecl;
class Token;
class Type;
class TypeDecl;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT TemplateTypeParmDecl : public TypeDecl {
 private:
  friend class FragmentImpl;
  friend class TypeDecl;
  friend class NamedDecl;
  friend class Decl;
 public:
  static gap::generator<TemplateTypeParmDecl> in(const Index &index);
  static gap::generator<TemplateTypeParmDecl> in(const Fragment &frag);
  static gap::generator<TemplateTypeParmDecl> in(const File &file);
  static gap::generator<TemplateTypeParmDecl> containing(const Token &tok);
  bool contains(const Token &tok) const;

  static std::optional<TemplateTypeParmDecl> from(const ir::Operation &op);
  static gap::generator<std::pair<TemplateTypeParmDecl, ir::Operation>> in(const Compilation &tu);
  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::TEMPLATE_TYPE_PARM;
  }

  static gap::generator<TemplateTypeParmDecl> containing(const Decl &decl);
  static gap::generator<TemplateTypeParmDecl> containing(const std::optional<Decl> &decl);

  static gap::generator<TemplateTypeParmDecl> containing(const Stmt &stmt);
  static gap::generator<TemplateTypeParmDecl> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  TemplateTypeParmDecl canonical_declaration(void) const;
  std::optional<TemplateTypeParmDecl> definition(void) const;
  gap::generator<TemplateTypeParmDecl> redeclarations(void) const &;
  static std::optional<TemplateTypeParmDecl> by_id(const Index &, EntityId);

  static std::optional<TemplateTypeParmDecl> from_base(const Decl &parent);
  inline static std::optional<TemplateTypeParmDecl> from(const Decl &parent) {
    return from_base(parent);
  }
  static std::optional<TemplateTypeParmDecl> from(const std::optional<Decl> &parent);
  static std::optional<TemplateTypeParmDecl> from(const Reference &r);
  static std::optional<TemplateTypeParmDecl> from(const VariantEntity &e);
  static std::optional<TemplateTypeParmDecl> from(const TokenContext &t);

  bool default_argument_was_inherited(void) const;
  std::optional<Type> default_argument(void) const;
  std::optional<Type> default_argument_info(void) const;
  Token default_argument_token(void) const;
  bool has_default_argument(void) const;
  bool has_type_constraint(void) const;
  bool is_expanded_parameter_pack(void) const;
  bool is_pack_expansion(void) const;
  bool was_declared_with_typename(void) const;
};

static_assert(sizeof(TemplateTypeParmDecl) == sizeof(TypeDecl));

#endif
} // namespace mx
