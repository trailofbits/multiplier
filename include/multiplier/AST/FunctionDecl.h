// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <multiplier/AST/ConstexprSpecKind.h>
#include <multiplier/AST/DeclaratorDecl.h>
#include <multiplier/AST/ExceptionSpecificationType.h>
#include <multiplier/AST/FunctionDeclTemplatedKind.h>
#include <multiplier/AST/LanguageLinkage.h>
#include <multiplier/AST/MultiVersionKind.h>
#include <multiplier/AST/OverloadedOperatorKind.h>
#include <multiplier/AST/StorageClass.h>

namespace mx {
class EntityProvider;
class Fragment;
class Index;
class Reference;
class Decl;
class DeclaratorDecl;
class FunctionDecl;
class FunctionTemplateDecl;
class NamedDecl;
class ParmVarDecl;
class Stmt;
class TemplateArgument;
class Token;
class TokenRange;
class Type;
class ValueDecl;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT FunctionDecl : public DeclaratorDecl {
 private:
  friend class FragmentImpl;
  friend class DeclaratorDecl;
  friend class ValueDecl;
  friend class NamedDecl;
  friend class Decl;
 public:
  static gap::generator<FunctionDecl> in(const Index &index);
  static gap::generator<FunctionDecl> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<FunctionDecl> by_id(const Index &, EntityId);
  static gap::generator<FunctionDecl> in(const Fragment &frag);
  static gap::generator<FunctionDecl> in(const File &file);

  static std::optional<FunctionDecl> from(const ir::Operation &op);
  static gap::generator<std::pair<FunctionDecl, ir::Operation>> in(const Compilation &tu);
  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::FUNCTION;
  }

  static gap::generator<FunctionDecl> containing(const Decl &decl);
  static gap::generator<FunctionDecl> containing(const std::optional<Decl> &decl);

  static gap::generator<FunctionDecl> containing(const Stmt &stmt);
  static gap::generator<FunctionDecl> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  FunctionDecl canonical_declaration(void) const;
  std::optional<FunctionDecl> definition(void) const;
  gap::generator<FunctionDecl> redeclarations(void) const &;
  static std::optional<FunctionDecl> from_base(const Decl &parent);
  inline static std::optional<FunctionDecl> from(const Decl &parent) {
    return from_base(parent);
  }
  static std::optional<FunctionDecl> from(const std::optional<Decl> &parent);
  static std::optional<FunctionDecl> from(const Reference &r);
  static std::optional<FunctionDecl> from(const VariantEntity &e);
  static std::optional<FunctionDecl> from(const TokenContext &t);

  bool body_contains_immediate_escalating_expressions(void) const;
  bool friend_constraint_refers_to_enclosing_template(void) const;
  bool uses_fp_intrin(void) const;
  std::optional<bool> does_declaration_force_externally_visible_definition(void) const;
  bool does_this_declaration_have_a_body(void) const;
  Type call_result_type(void) const;
  ConstexprSpecKind constexpr_kind(void) const;
  Type declared_return_type(void) const;
  Token default_token(void) const;
  std::optional<FunctionTemplateDecl> described_function_template(void) const;
  Token ellipsis_token(void) const;
  TokenRange exception_spec_tokens(void) const;
  ExceptionSpecificationType exception_spec_type(void) const;
  LanguageLinkage language_linkage(void) const;
  MultiVersionKind multi_version_kind(void) const;
  OverloadedOperatorKind overloaded_operator(void) const;
  TokenRange parameters_tokens(void) const;
  Type return_type(void) const;
  StorageClass storage_class(void) const;
  FunctionDeclTemplatedKind templated_kind(void) const;
  bool has_cxx_explicit_function_object_parameter(void) const;
  bool has_implicit_return_zero(void) const;
  bool has_inherited_prototype(void) const;
  bool has_one_parameter_or_default_arguments(void) const;
  bool has_prototype(void) const;
  bool has_skipped_body(void) const;
  bool has_trivial_body(void) const;
  bool has_written_prototype(void) const;
  bool instantiation_is_pending(void) const;
  bool is_cpu_dispatch_multi_version(void) const;
  bool is_cpu_specific_multi_version(void) const;
  bool is_consteval(void) const;
  bool is_constexpr(void) const;
  bool is_constexpr_specified(void) const;
  bool is_defaulted(void) const;
  bool is_deleted(void) const;
  bool is_deleted_as_written(void) const;
  bool is_destroying_operator_delete(void) const;
  bool is_explicitly_defaulted(void) const;
  bool is_extern_c(void) const;
  bool is_function_template_specialization(void) const;
  bool is_global(void) const;
  bool is_immediate_escalating(void) const;
  bool is_immediate_function(void) const;
  bool is_implicitly_instantiable(void) const;
  bool is_in_extern_c_context(void) const;
  bool is_in_extern_cxx_context(void) const;
  bool is_ineligible_or_not_selected(void) const;
  bool is_inline_builtin_declaration(void) const;
  std::optional<bool> is_inline_definition_externally_visible(void) const;
  bool is_inline_specified(void) const;
  bool is_inlined(void) const;
  bool is_late_template_parsed(void) const;
  std::optional<bool> is_ms_extern_inline(void) const;
  bool is_msvcrt_entry_point(void) const;
  bool is_main(void) const;
  bool is_member_like_constrained_friend(void) const;
  bool is_multi_version(void) const;
  bool is_no_return(void) const;
  bool is_overloaded_operator(void) const;
  bool is_pure_virtual(void) const;
  bool is_replaceable_global_allocation_function(void) const;
  std::optional<bool> is_reserved_global_placement_operator(void) const;
  bool is_static(void) const;
  bool is_target_clones_multi_version(void) const;
  bool is_target_multi_version(void) const;
  bool is_template_instantiation(void) const;
  bool is_this_declaration_a_definition(void) const;
  bool is_trivial(void) const;
  bool is_trivial_for_call(void) const;
  bool is_user_provided(void) const;
  bool is_variadic(void) const;
  bool is_virtual_as_written(void) const;
  std::optional<ParmVarDecl> nth_parameter(unsigned n) const;
  unsigned num_parameters(void) const;
  gap::generator<ParmVarDecl> parameters(void) const &;
  bool uses_seh_try(void) const;
  std::optional<Stmt> body(void) const;
  std::optional<TemplateArgument> nth_template_argument(unsigned n) const;
  unsigned num_template_arguments(void) const;
  gap::generator<TemplateArgument> template_arguments(void) const &;
  gap::generator<Decl> contained_declarations(void) const &;
  // Callers of a `FunctionDecl` can be `CallExpr`, `CxxNewExpr`,
  // `CxxConstructExpr`, etc. Even `CastExpr` can sometimes be a call
  // if it needs to invoke a function call to perform the conversion.
  gap::generator<Stmt> callers(void) const &;
};

static_assert(sizeof(FunctionDecl) == sizeof(DeclaratorDecl));

#endif
} // namespace mx
