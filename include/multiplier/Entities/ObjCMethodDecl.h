// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "DeclObjCDeclQualifier.h"
#include "NamedDecl.h"
#include "ObjCMethodDeclImplementationControl.h"
#include "ObjCMethodFamily.h"

namespace mx {
class EntityProvider;
class Index;
class Decl;
class ImplicitParamDecl;
class NamedDecl;
class ObjCInterfaceDecl;
class ObjCMethodDecl;
class ObjCPropertyDecl;
class ParmVarDecl;
class Stmt;
class Token;
class TokenRange;
class Type;
namespace mx {
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class ObjCMethodDecl : public NamedDecl {
 private:
  friend class FragmentImpl;
  friend class NamedDecl;
  friend class Decl;
 public:
  static gap::generator<ObjCMethodDecl> in(const Fragment &frag);
  static gap::generator<ObjCMethodDecl> in(const File &file);
  static gap::generator<ObjCMethodDecl> in(const Index &index);
  static gap::generator<ObjCMethodDecl> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<ObjCMethodDecl> by_id(const Index &, EntityId);

  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::OBJ_C_METHOD;
  }

  static gap::generator<ObjCMethodDecl> containing(const Decl &decl);
  static gap::generator<ObjCMethodDecl> containing(const std::optional<Decl> &decl);

  static gap::generator<ObjCMethodDecl> containing(const Stmt &stmt);
  static gap::generator<ObjCMethodDecl> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  ObjCMethodDecl canonical_declaration(void) const;
  std::optional<ObjCMethodDecl> definition(void) const;
  gap::generator<ObjCMethodDecl> redeclarations(void) const &;
  static std::optional<ObjCMethodDecl> from(const Decl &parent);

  inline static std::optional<ObjCMethodDecl> from(const std::optional<Decl> &parent) {
    if (parent) {
      return ObjCMethodDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ObjCMethodDecl> from(const Reference &r);
  static std::optional<ObjCMethodDecl> from(const TokenContext &t);

  bool defined_in_ns_object(void) const;
  ObjCPropertyDecl find_property_declaration(void) const;
  ObjCInterfaceDecl class_interface(void) const;
  ImplicitParamDecl command_declaration(void) const;
  Token declarator_end_token(void) const;
  ObjCMethodDeclImplementationControl implementation_control(void) const;
  ObjCMethodFamily method_family(void) const;
  DeclObjCDeclQualifier obj_c_decl_qualifier(void) const;
  Type return_type(void) const;
  TokenRange return_type_source_range(void) const;
  Token selector_start_token(void) const;
  ImplicitParamDecl self_declaration(void) const;
  bool has_parameter_destroyed_in_callee(void) const;
  bool has_redeclaration(void) const;
  bool has_related_result_type(void) const;
  bool has_skipped_body(void) const;
  bool is_class_method(void) const;
  bool is_defined(void) const;
  bool is_designated_initializer_for_the_interface(void) const;
  bool is_direct_method(void) const;
  bool is_instance_method(void) const;
  bool is_optional(void) const;
  bool is_overriding(void) const;
  bool is_property_accessor(void) const;
  bool is_redeclaration(void) const;
  bool is_synthesized_accessor_stub(void) const;
  bool is_this_declaration_a_definition(void) const;
  bool is_this_declaration_a_designated_initializer(void) const;
  bool is_variadic(void) const;
  std::optional<ParmVarDecl> nth_parameter(unsigned n) const;
  unsigned num_parameters(void) const;
  gap::generator<ParmVarDecl> parameters(void) const &;
  std::optional<Token> nth_selector_token(unsigned n) const;
  unsigned num_selector_tokens(void) const;
  gap::generator<Token> selector_tokens(void) const &;
  gap::generator<Decl> declarations_in_context(void) const &;
};

static_assert(sizeof(ObjCMethodDecl) == sizeof(NamedDecl));

#endif
} // namespace mx
