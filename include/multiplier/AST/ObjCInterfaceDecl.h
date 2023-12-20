// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <multiplier/AST/ObjCContainerDecl.h>

namespace mx {
class EntityProvider;
class Fragment;
class Index;
class Decl;
class NamedDecl;
class ObjCCategoryDecl;
class ObjCContainerDecl;
class ObjCImplementationDecl;
class ObjCInterfaceDecl;
class ObjCIvarDecl;
class ObjCProtocolDecl;
class Stmt;
class Token;
class TokenRange;
class Type;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT ObjCInterfaceDecl : public ObjCContainerDecl {
 private:
  friend class FragmentImpl;
  friend class ObjCContainerDecl;
  friend class NamedDecl;
  friend class Decl;
 public:
  static gap::generator<ObjCInterfaceDecl> in(const Index &index);
  static gap::generator<ObjCInterfaceDecl> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<ObjCInterfaceDecl> by_id(const Index &, EntityId);
  static gap::generator<ObjCInterfaceDecl> in(const Fragment &frag);
  static gap::generator<ObjCInterfaceDecl> in(const File &file);

  static std::optional<ObjCInterfaceDecl> from(const ir::Operation &op);
  static gap::generator<std::pair<ObjCInterfaceDecl, ir::Operation>> in(const Compilation &tu);
  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::OBJ_C_INTERFACE;
  }

  static gap::generator<ObjCInterfaceDecl> containing(const Decl &decl);
  static gap::generator<ObjCInterfaceDecl> containing(const std::optional<Decl> &decl);

  static gap::generator<ObjCInterfaceDecl> containing(const Stmt &stmt);
  static gap::generator<ObjCInterfaceDecl> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  ObjCInterfaceDecl canonical_declaration(void) const;
  std::optional<ObjCInterfaceDecl> definition(void) const;
  gap::generator<ObjCInterfaceDecl> redeclarations(void) const &;
  static std::optional<ObjCInterfaceDecl> from_base(const Decl &parent);
  inline static std::optional<ObjCInterfaceDecl> from(const Decl &parent) {
    return from_base(parent);
  }
  static std::optional<ObjCInterfaceDecl> from(const std::optional<Decl> &parent);
  static std::optional<ObjCInterfaceDecl> from(const Reference &r);
  static std::optional<ObjCInterfaceDecl> from(const VariantEntity &e);
  static std::optional<ObjCInterfaceDecl> from(const TokenContext &t);

  std::optional<ObjCProtocolDecl> nth_all_referenced_protocol(unsigned n) const;
  unsigned num_all_referenced_protocols(void) const;
  gap::generator<ObjCProtocolDecl> all_referenced_protocols(void) const &;
  bool declares_or_inherits_designated_initializers(void) const;
  Token end_of_definition_token(void) const;
  ObjCImplementationDecl implementation(void) const;
  std::string_view obj_c_runtime_name_as_string(void) const;
  std::optional<ObjCInterfaceDecl> super_class(void) const;
  Token super_class_token(void) const;
  std::optional<Type> super_class_type(void) const;
  Type type_for_declaration(void) const;
  bool has_definition(void) const;
  bool has_designated_initializers(void) const;
  bool is_arc_weakref_unavailable(void) const;
  bool is_implicit_interface_declaration(void) const;
  ObjCInterfaceDecl is_obj_c_requires_property_definitions(void) const;
  bool is_this_declaration_a_definition(void) const;
  std::optional<ObjCIvarDecl> nth_instance_variable(unsigned n) const;
  unsigned num_instance_variables(void) const;
  gap::generator<ObjCIvarDecl> instance_variables(void) const &;
  std::optional<ObjCCategoryDecl> nth_known_categorie(unsigned n) const;
  unsigned num_known_categories(void) const;
  gap::generator<ObjCCategoryDecl> known_categories(void) const &;
  std::optional<ObjCCategoryDecl> nth_known_extension(unsigned n) const;
  unsigned num_known_extensions(void) const;
  gap::generator<ObjCCategoryDecl> known_extensions(void) const &;
  std::optional<Token> nth_protocol_token(unsigned n) const;
  unsigned num_protocol_tokens(void) const;
  gap::generator<Token> protocol_tokens(void) const &;
  std::optional<ObjCProtocolDecl> nth_protocol(unsigned n) const;
  unsigned num_protocols(void) const;
  gap::generator<ObjCProtocolDecl> protocols(void) const &;
  std::optional<ObjCCategoryDecl> nth_visible_categorie(unsigned n) const;
  unsigned num_visible_categories(void) const;
  gap::generator<ObjCCategoryDecl> visible_categories(void) const &;
  std::optional<ObjCCategoryDecl> nth_visible_extension(unsigned n) const;
  unsigned num_visible_extensions(void) const;
  gap::generator<ObjCCategoryDecl> visible_extensions(void) const &;
};

static_assert(sizeof(ObjCInterfaceDecl) == sizeof(ObjCContainerDecl));

#endif
} // namespace mx
