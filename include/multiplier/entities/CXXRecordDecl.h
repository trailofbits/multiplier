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
#include "DeclUseSelector.h"
#include "LambdaCaptureDefault.h"
#include "MSInheritanceModel.h"
#include "MSVtorDispMode.h"
#include "RecordDecl.h"
#include "TemplateSpecializationKind.h"
#include "TypeUseSelector.h"

namespace mx {
class CXXBaseSpecifier;
class CXXConstructorDecl;
class CXXDestructorDecl;
class CXXMethodDecl;
class CXXRecordDecl;
class Decl;
class FriendDecl;
class FunctionDecl;
class NamedDecl;
class RecordDecl;
class TagDecl;
class TemplateParameterList;
class Type;
class TypeDecl;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using CXXRecordDeclRange = DerivedEntityRange<DeclIterator, CXXRecordDecl>;
using CXXRecordDeclContainingTokenRange = DerivedEntityRange<TokenContextIterator, CXXRecordDecl>;
using CXXRecordDeclContainingDeclRange = DerivedEntityRange<ParentDeclIteratorImpl<Decl>, CXXRecordDecl>;

class CXXRecordDecl : public RecordDecl {
 private:
  friend class FragmentImpl;
  friend class RecordDecl;
  friend class TagDecl;
  friend class TypeDecl;
  friend class NamedDecl;
  friend class Decl;
 public:
  inline static CXXRecordDeclRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static CXXRecordDeclContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : CXXRecordDecl::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::CXX_RECORD;
  }

  static CXXRecordDeclContainingDeclRange containing(const Decl &decl);
  static CXXRecordDeclContainingDeclRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<CXXRecordDecl> from(const TokenContext &c);
  static std::optional<CXXRecordDecl> from(const RecordDecl &parent);

  inline static std::optional<CXXRecordDecl> from(const std::optional<RecordDecl> &parent) {
    if (parent) {
      return CXXRecordDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<CXXRecordDecl> from(const TagDecl &parent);

  inline static std::optional<CXXRecordDecl> from(const std::optional<TagDecl> &parent) {
    if (parent) {
      return CXXRecordDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<CXXRecordDecl> from(const TypeDecl &parent);

  inline static std::optional<CXXRecordDecl> from(const std::optional<TypeDecl> &parent) {
    if (parent) {
      return CXXRecordDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<CXXRecordDecl> from(const NamedDecl &parent);

  inline static std::optional<CXXRecordDecl> from(const std::optional<NamedDecl> &parent) {
    if (parent) {
      return CXXRecordDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<CXXRecordDecl> from(const Decl &parent);

  inline static std::optional<CXXRecordDecl> from(const std::optional<Decl> &parent) {
    if (parent) {
      return CXXRecordDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  std::optional<bool> allow_const_default_initializer(void) const;
  std::optional<std::vector<CXXBaseSpecifier>> bases(void) const;
  std::optional<MSInheritanceModel> calculate_inheritance_model(void) const;
  std::vector<CXXConstructorDecl> constructors(void) const;
  std::optional<std::vector<FriendDecl>> friends(void) const;
  std::optional<CXXDestructorDecl> destructor(void) const;
  std::optional<TemplateParameterList> generic_lambda_template_parameter_list(void) const;
  std::optional<CXXRecordDecl> instantiated_from_member_class(void) const;
  std::optional<CXXMethodDecl> lambda_call_operator(void) const;
  std::optional<LambdaCaptureDefault> lambda_capture_default(void) const;
  std::optional<Decl> lambda_context_declaration(void) const;
  std::optional<std::vector<NamedDecl>> lambda_explicit_template_parameters(void) const;
  std::optional<unsigned> lambda_mangling_number(void) const;
  std::optional<Type> lambda_type(void) const;
  std::optional<MSInheritanceModel> ms_inheritance_model(void) const;
  MSVtorDispMode ms_vtor_disp_mode(void) const;
  std::optional<unsigned> num_bases(void) const;
  std::optional<unsigned> num_virtual_bases(void) const;
  std::optional<unsigned> odr_hash(void) const;
  std::optional<CXXRecordDecl> template_instantiation_pattern(void) const;
  TemplateSpecializationKind template_specialization_kind(void) const;
  std::optional<bool> has_any_dependent_bases(void) const;
  std::optional<bool> has_constexpr_default_constructor(void) const;
  std::optional<bool> has_constexpr_destructor(void) const;
  std::optional<bool> has_constexpr_non_copy_move_constructor(void) const;
  std::optional<bool> has_copy_assignment_with_const_parameter(void) const;
  std::optional<bool> has_copy_constructor_with_const_parameter(void) const;
  std::optional<bool> has_default_constructor(void) const;
  std::optional<bool> has_definition(void) const;
  std::optional<bool> has_direct_fields(void) const;
  std::optional<bool> has_friends(void) const;
  std::optional<bool> has_in_class_initializer(void) const;
  std::optional<bool> has_inherited_assignment(void) const;
  std::optional<bool> has_inherited_constructor(void) const;
  std::optional<bool> has_initializer_method(void) const;
  std::optional<bool> has_irrelevant_destructor(void) const;
  std::optional<bool> has_known_lambda_internal_linkage(void) const;
  std::optional<bool> has_move_assignment(void) const;
  std::optional<bool> has_move_constructor(void) const;
  std::optional<bool> has_mutable_fields(void) const;
  std::optional<bool> has_non_literal_type_fields_or_bases(void) const;
  std::optional<bool> has_non_trivial_copy_assignment(void) const;
  std::optional<bool> has_non_trivial_copy_constructor(void) const;
  std::optional<bool> has_non_trivial_copy_constructor_for_call(void) const;
  std::optional<bool> has_non_trivial_default_constructor(void) const;
  std::optional<bool> has_non_trivial_destructor(void) const;
  std::optional<bool> has_non_trivial_destructor_for_call(void) const;
  std::optional<bool> has_non_trivial_move_assignment(void) const;
  std::optional<bool> has_non_trivial_move_constructor(void) const;
  std::optional<bool> has_non_trivial_move_constructor_for_call(void) const;
  std::optional<bool> has_private_fields(void) const;
  std::optional<bool> has_protected_fields(void) const;
  std::optional<bool> has_simple_copy_assignment(void) const;
  std::optional<bool> has_simple_copy_constructor(void) const;
  std::optional<bool> has_simple_destructor(void) const;
  std::optional<bool> has_simple_move_assignment(void) const;
  std::optional<bool> has_simple_move_constructor(void) const;
  std::optional<bool> has_trivial_copy_assignment(void) const;
  std::optional<bool> has_trivial_copy_constructor(void) const;
  std::optional<bool> has_trivial_copy_constructor_for_call(void) const;
  std::optional<bool> has_trivial_default_constructor(void) const;
  std::optional<bool> has_trivial_destructor(void) const;
  std::optional<bool> has_trivial_destructor_for_call(void) const;
  std::optional<bool> has_trivial_move_assignment(void) const;
  std::optional<bool> has_trivial_move_constructor(void) const;
  std::optional<bool> has_trivial_move_constructor_for_call(void) const;
  std::optional<bool> has_uninitialized_reference_member(void) const;
  std::optional<bool> has_user_declared_constructor(void) const;
  std::optional<bool> has_user_declared_copy_assignment(void) const;
  std::optional<bool> has_user_declared_copy_constructor(void) const;
  std::optional<bool> has_user_declared_destructor(void) const;
  std::optional<bool> has_user_declared_move_assignment(void) const;
  std::optional<bool> has_user_declared_move_constructor(void) const;
  std::optional<bool> has_user_declared_move_operation(void) const;
  std::optional<bool> has_user_provided_default_constructor(void) const;
  std::optional<bool> has_variant_members(void) const;
  std::optional<bool> implicit_copy_assignment_has_const_parameter(void) const;
  std::optional<bool> implicit_copy_constructor_has_const_parameter(void) const;
  std::optional<bool> is_abstract(void) const;
  std::optional<bool> is_aggregate(void) const;
  std::optional<bool> is_any_destructor_no_return(void) const;
  std::optional<bool> is_c_like(void) const;
  std::optional<bool> is_cxx11_standard_layout(void) const;
  bool is_dependent_lambda(void) const;
  std::optional<bool> is_dynamic_class(void) const;
  std::optional<bool> is_effectively_final(void) const;
  std::optional<bool> is_empty(void) const;
  bool is_generic_lambda(void) const;
  std::optional<bool> is_interface_like(void) const;
  std::optional<bool> is_literal(void) const;
  std::optional<FunctionDecl> is_local_class(void) const;
  std::optional<bool> is_pod(void) const;
  std::optional<bool> is_polymorphic(void) const;
  std::optional<bool> is_standard_layout(void) const;
  std::optional<bool> is_structural(void) const;
  std::optional<bool> is_trivial(void) const;
  std::optional<bool> is_trivially_copyable(void) const;
  std::optional<bool> lambda_is_default_constructible_and_assignable(void) const;
  std::optional<bool> may_be_abstract(void) const;
  std::optional<bool> may_be_dynamic_class(void) const;
  std::optional<bool> may_be_non_dynamic_class(void) const;
  std::optional<std::vector<CXXMethodDecl>> methods(void) const;
  std::optional<bool> needs_implicit_copy_assignment(void) const;
  std::optional<bool> needs_implicit_copy_constructor(void) const;
  std::optional<bool> needs_implicit_default_constructor(void) const;
  std::optional<bool> needs_implicit_destructor(void) const;
  std::optional<bool> needs_implicit_move_assignment(void) const;
  std::optional<bool> needs_implicit_move_constructor(void) const;
  std::optional<bool> needs_overload_resolution_for_copy_assignment(void) const;
  std::optional<bool> needs_overload_resolution_for_copy_constructor(void) const;
  std::optional<bool> needs_overload_resolution_for_destructor(void) const;
  std::optional<bool> needs_overload_resolution_for_move_assignment(void) const;
  std::optional<bool> needs_overload_resolution_for_move_constructor(void) const;
  std::optional<bool> null_field_offset_is_zero(void) const;
  std::optional<std::vector<CXXBaseSpecifier>> virtual_bases(void) const;
};

static_assert(sizeof(CXXRecordDecl) == sizeof(RecordDecl));

#endif
} // namespace mx
