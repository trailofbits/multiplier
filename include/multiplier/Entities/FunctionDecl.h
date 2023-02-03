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

#include <gap/core/generator.hpp>
#include "../Iterator.h"
#include "../Types.h"
#include "../Token.h"

#include "ConstexprSpecKind.h"
#include "DeclKind.h"
#include "DeclaratorDecl.h"
#include "ExceptionSpecificationType.h"
#include "FunctionDeclTemplatedKind.h"
#include "LanguageLinkage.h"
#include "MultiVersionKind.h"
#include "OverloadedOperatorKind.h"
#include "StorageClass.h"
#include "TemplateSpecializationKind.h"

namespace mx {
class Decl;
class DeclaratorDecl;
class FunctionDecl;
class FunctionTemplateDecl;
class NamedDecl;
class ParmVarDecl;
class Stmt;
class Type;
class ValueDecl;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class FunctionDecl : public DeclaratorDecl {
 private:
  friend class FragmentImpl;
  friend class DeclaratorDecl;
  friend class ValueDecl;
  friend class NamedDecl;
  friend class Decl;
 public:
  inline static gap::generator<FunctionDecl> in(const Fragment &frag) {
    for (auto e : in_internal(frag)) {
      if (auto d = from(e)) {
        co_yield *d;
      }
    }
  }

  inline static gap::generator<FunctionDecl> containing(const Token &tok) {
    for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
      if (auto d = from(*ctx)) {
        co_yield *d;
      }
    }
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : FunctionDecl::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::FUNCTION;
  }

  static gap::generator<FunctionDecl> containing(const Decl &decl);
  static gap::generator<FunctionDecl> containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<FunctionDecl> from(const TokenContext &c);
  static std::optional<FunctionDecl> from(const DeclaratorDecl &parent);

  inline static std::optional<FunctionDecl> from(const std::optional<DeclaratorDecl> &parent) {
    if (parent) {
      return FunctionDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<FunctionDecl> from(const ValueDecl &parent);

  inline static std::optional<FunctionDecl> from(const std::optional<ValueDecl> &parent) {
    if (parent) {
      return FunctionDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<FunctionDecl> from(const NamedDecl &parent);

  inline static std::optional<FunctionDecl> from(const std::optional<NamedDecl> &parent) {
    if (parent) {
      return FunctionDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<FunctionDecl> from(const Decl &parent);

  inline static std::optional<FunctionDecl> from(const std::optional<Decl> &parent) {
    if (parent) {
      return FunctionDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  bool uses_fp_intrin(void) const;
  std::optional<bool> does_declaration_force_externally_visible_definition(void) const;
  bool does_this_declaration_have_a_body(void) const;
  Type call_result_type(void) const;
  ConstexprSpecKind constexpr_kind(void) const;
  Type declared_return_type(void) const;
  std::optional<FunctionTemplateDecl> described_function_template(void) const;
  Token ellipsis_token(void) const;
  TokenRange exception_spec_source_range(void) const;
  ExceptionSpecificationType exception_spec_type(void) const;
  std::optional<FunctionDecl> instantiated_from_declaration(void) const;
  std::optional<FunctionDecl> instantiated_from_member_function(void) const;
  LanguageLinkage language_linkage(void) const;
  MultiVersionKind multi_version_kind(void) const;
  std::optional<unsigned> odr_hash(void) const;
  OverloadedOperatorKind overloaded_operator(void) const;
  TokenRange parameters_source_range(void) const;
  Token point_of_instantiation(void) const;
  std::optional<FunctionTemplateDecl> primary_template(void) const;
  Type return_type(void) const;
  TokenRange return_type_source_range(void) const;
  StorageClass storage_class(void) const;
  std::optional<FunctionDecl> template_instantiation_pattern(void) const;
  TemplateSpecializationKind template_specialization_kind(void) const;
  TemplateSpecializationKind template_specialization_kind_for_instantiation(void) const;
  FunctionDeclTemplatedKind templated_kind(void) const;
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
  bool is_multi_version(void) const;
  bool is_no_return(void) const;
  bool is_overloaded_operator(void) const;
  bool is_pure(void) const;
  bool is_replaceable_global_allocation_function(void) const;
  std::optional<bool> is_reserved_global_placement_operator(void) const;
  bool is_static(void) const;
  bool is_target_clones_multi_version(void) const;
  bool is_target_multi_version(void) const;
  bool is_template_instantiation(void) const;
  bool is_this_declaration_instantiated_from_a_friend_definition(void) const;
  bool is_trivial(void) const;
  bool is_trivial_for_call(void) const;
  bool is_user_provided(void) const;
  bool is_variadic(void) const;
  bool is_virtual_as_written(void) const;
  std::optional<ParmVarDecl> nth_parameter(unsigned n) const;
  gap::generator<ParmVarDecl> parameters(void) const;
  bool uses_seh_try(void) const;
  bool will_have_body(void) const;
  std::optional<Stmt> body(void) const;
  gap::generator<Decl> declarations_in_context(void) const;
};

static_assert(sizeof(FunctionDecl) == sizeof(DeclaratorDecl));

#endif
} // namespace mx
