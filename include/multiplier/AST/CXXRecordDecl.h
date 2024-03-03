// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <multiplier/AST/LambdaCaptureDefault.h>
#include <multiplier/AST/MSInheritanceModel.h>
#include <multiplier/AST/MSVtorDispMode.h>
#include <multiplier/AST/RecordDecl.h>
#include <multiplier/AST/TemplateSpecializationKind.h>

namespace mx {
class EntityProvider;
class Fragment;
class Index;
class CXXBaseSpecifier;
class CXXConstructorDecl;
class CXXDestructorDecl;
class CXXMethodDecl;
class CXXRecordDecl;
class ClassTemplateDecl;
class Decl;
class FriendDecl;
class FunctionDecl;
class FunctionTemplateDecl;
class NamedDecl;
class RecordDecl;
class Stmt;
class TagDecl;
class TemplateParameterList;
class Token;
class TypeDecl;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT CXXRecordDecl : public RecordDecl {
 private:
  friend class FragmentImpl;
  friend class RecordDecl;
  friend class TagDecl;
  friend class TypeDecl;
  friend class NamedDecl;
  friend class Decl;
 public:
  static gap::generator<CXXRecordDecl> in(const Index &index);
  static gap::generator<CXXRecordDecl> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<CXXRecordDecl> by_id(const Index &, EntityId);
  static gap::generator<CXXRecordDecl> in(const Fragment &frag);
  static gap::generator<CXXRecordDecl> in(const File &file);

  static std::optional<CXXRecordDecl> from(const ir::Operation &op);
  static gap::generator<std::pair<CXXRecordDecl, ir::Operation>> in(const Compilation &tu);
  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::CXX_RECORD;
  }

  static gap::generator<CXXRecordDecl> containing(const Decl &decl);
  static gap::generator<CXXRecordDecl> containing(const std::optional<Decl> &decl);

  static gap::generator<CXXRecordDecl> containing(const Stmt &stmt);
  static gap::generator<CXXRecordDecl> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  CXXRecordDecl canonical_declaration(void) const;
  std::optional<CXXRecordDecl> definition(void) const;
  gap::generator<CXXRecordDecl> redeclarations(void) const &;
  static std::optional<CXXRecordDecl> from_base(const Decl &parent);
  inline static std::optional<CXXRecordDecl> from(const Decl &parent) {
    return from_base(parent);
  }
  static std::optional<CXXRecordDecl> from(const std::optional<Decl> &parent);
  static std::optional<CXXRecordDecl> from(const Reference &r);
  static std::optional<CXXRecordDecl> from(const VariantEntity &e);
  static std::optional<CXXRecordDecl> from(const TokenContext &t);

  std::optional<bool> allow_const_default_initializer(void) const;
  std::optional<std::vector<CXXBaseSpecifier>> bases(void) const;
  std::optional<MSInheritanceModel> calculate_inheritance_model(void) const;
  std::optional<CXXConstructorDecl> nth_constructor(unsigned n) const;
  unsigned num_constructors(void) const;
  gap::generator<CXXConstructorDecl> constructors(void) const &;
  std::optional<std::vector<FriendDecl>> friends(void) const;
  std::optional<FunctionTemplateDecl> dependent_lambda_call_operator(void) const;
  std::optional<ClassTemplateDecl> described_class_template(void) const;
  std::optional<CXXDestructorDecl> destructor(void) const;
  std::optional<TemplateParameterList> generic_lambda_template_parameter_list(void) const;
  std::optional<CXXRecordDecl> instantiated_from_member_class(void) const;
  std::optional<CXXMethodDecl> lambda_call_operator(void) const;
  std::optional<LambdaCaptureDefault> lambda_capture_default(void) const;
  std::optional<Decl> lambda_context_declaration(void) const;
  std::optional<std::vector<NamedDecl>> lambda_explicit_template_parameters(void) const;
  std::optional<uint32_t> lambda_mangling_number(void) const;
  std::optional<MSInheritanceModel> ms_inheritance_model(void) const;
  MSVtorDispMode ms_vtor_disp_mode(void) const;
  std::optional<uint32_t> odr_hash(void) const;
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
  std::optional<bool> is_literal(void) const;
  std::optional<FunctionDecl> is_local_class(void) const;
  bool is_never_dependent_lambda(void) const;
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
  std::optional<uint64_t> size_without_virtual_bases(void) const;
  std::optional<CXXRecordDecl> primary_base(void) const;
  std::optional<bool> has_own_virtual_function_table_pointer(void) const;
  std::optional<bool> has_extendable_virtual_function_table_pointer(void) const;
  std::optional<bool> has_virtual_base_table_pointer(void) const;
  std::optional<bool> has_own_virtual_base_table_pointer(void) const;
};

static_assert(sizeof(CXXRecordDecl) == sizeof(RecordDecl));

#endif
} // namespace mx
