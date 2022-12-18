// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>
#include <filesystem>
#include <memory>
#include <optional>
#include <vector>

#include "../Iterator.h"
#include "../Types.h"
#include "../Token.h"
#include "../Use.h"

#include "DeclKind.h"
#include "DeclObjCDeclQualifier.h"
#include "NamedDecl.h"
#include "ObjCMethodDeclImplementationControl.h"
#include "ObjCMethodFamily.h"

namespace mx {
class Decl;
class ImplicitParamDecl;
class NamedDecl;
class ObjCInterfaceDecl;
class ObjCMethodDecl;
class ObjCPropertyDecl;
class ParmVarDecl;
class Token;
class Type;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using ObjCMethodDeclRange = DerivedEntityRange<DeclIterator, ObjCMethodDecl>;
using ObjCMethodDeclContainingTokenRange = DerivedEntityRange<TokenContextIterator, ObjCMethodDecl>;
using ObjCMethodDeclContainingDeclRange = DerivedEntityRange<ParentDeclIteratorImpl<Decl>, ObjCMethodDecl>;

class ObjCMethodDecl : public NamedDecl {
 private:
  friend class FragmentImpl;
  friend class NamedDecl;
  friend class Decl;
 public:
  inline static ObjCMethodDeclRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static ObjCMethodDeclContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : ObjCMethodDecl::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::OBJ_C_METHOD;
  }

  static ObjCMethodDeclContainingDeclRange containing(const Decl &decl);
  static ObjCMethodDeclContainingDeclRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<ObjCMethodDecl> from(const TokenContext &c);
  static std::optional<ObjCMethodDecl> from(const NamedDecl &parent);

  inline static std::optional<ObjCMethodDecl> from(const std::optional<NamedDecl> &parent) {
    if (parent) {
      return ObjCMethodDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ObjCMethodDecl> from(const Decl &parent);

  inline static std::optional<ObjCMethodDecl> from(const std::optional<Decl> &parent) {
    if (parent) {
      return ObjCMethodDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

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
  bool is_this_declaration_a_designated_initializer(void) const;
  bool is_variadic(void) const;
  std::vector<ParmVarDecl> parameters(void) const;
  std::vector<Token> selector_tokens(void) const;
  std::vector<Decl> declarations_in_context(void) const;
};

static_assert(sizeof(ObjCMethodDecl) == sizeof(NamedDecl));

#endif
} // namespace mx
