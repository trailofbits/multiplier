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

#include "DeclKind.h"
#include "DeclaratorDecl.h"
#include "LanguageLinkage.h"
#include "QualTypeDestructionKind.h"
#include "StorageClass.h"
#include "StorageDuration.h"
#include "TemplateSpecializationKind.h"
#include "ThreadStorageClassSpecifier.h"
#include "VarDeclInitializationStyle.h"
#include "VarDeclTLSKind.h"

namespace mx {
class Decl;
class DeclaratorDecl;
class Expr;
class NamedDecl;
class ValueDecl;
class VarDecl;
class VarTemplateDecl;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class VarDecl : public DeclaratorDecl {
 private:
  friend class FragmentImpl;
  friend class DeclaratorDecl;
  friend class ValueDecl;
  friend class NamedDecl;
  friend class Decl;
 public:
  inline static gap::generator<VarDecl> in(const Fragment &frag) {
    for (auto e : in_internal(frag)) {
      if (auto d = from(e)) {
        co_yield *d;
      }
    }
  }

  inline static gap::generator<VarDecl> containing(const Token &tok) {
    for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
      if (auto d = from(*ctx)) {
        co_yield *d;
      }
    }
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : VarDecl::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::VAR;
  }

  static gap::generator<VarDecl> containing(const Decl &decl);
  static gap::generator<VarDecl> containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<VarDecl> from(const TokenContext &c);
  static std::optional<VarDecl> from(const DeclaratorDecl &parent);

  inline static std::optional<VarDecl> from(const std::optional<DeclaratorDecl> &parent) {
    if (parent) {
      return VarDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<VarDecl> from(const ValueDecl &parent);

  inline static std::optional<VarDecl> from(const std::optional<ValueDecl> &parent) {
    if (parent) {
      return VarDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<VarDecl> from(const NamedDecl &parent);

  inline static std::optional<VarDecl> from(const std::optional<NamedDecl> &parent) {
    if (parent) {
      return VarDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<VarDecl> from(const Decl &parent);

  inline static std::optional<VarDecl> from(const std::optional<Decl> &parent) {
    if (parent) {
      return VarDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  std::optional<VarDecl> acting_definition(void) const;
  std::optional<VarTemplateDecl> described_variable_template(void) const;
  std::optional<Expr> initializer(void) const;
  VarDeclInitializationStyle initializer_style(void) const;
  std::optional<VarDecl> initializing_declaration(void) const;
  std::optional<VarDecl> instantiated_from_static_data_member(void) const;
  LanguageLinkage language_linkage(void) const;
  Token point_of_instantiation(void) const;
  StorageClass storage_class(void) const;
  StorageDuration storage_duration(void) const;
  VarDeclTLSKind tls_kind(void) const;
  ThreadStorageClassSpecifier tsc_spec(void) const;
  std::optional<VarDecl> template_instantiation_pattern(void) const;
  TemplateSpecializationKind template_specialization_kind(void) const;
  TemplateSpecializationKind template_specialization_kind_for_instantiation(void) const;
  bool has_constant_initialization(void) const;
  bool has_dependent_alignment(void) const;
  bool has_external_storage(void) const;
  std::optional<bool> has_flexible_array_initializer(void) const;
  bool has_global_storage(void) const;
  std::optional<bool> has_ice_initializer(void) const;
  bool has_initializer(void) const;
  bool has_local_storage(void) const;
  bool is_arc_pseudo_strong(void) const;
  bool is_cxx_for_range_declaration(void) const;
  bool is_constexpr(void) const;
  bool is_direct_initializer(void) const;
  bool is_escaping_byref(void) const;
  bool is_exception_variable(void) const;
  bool is_extern_c(void) const;
  bool is_file_variable_declaration(void) const;
  bool is_function_or_method_variable_declaration(void) const;
  bool is_in_extern_c_context(void) const;
  bool is_in_extern_cxx_context(void) const;
  bool is_initializer_capture(void) const;
  bool is_inline(void) const;
  bool is_inline_specified(void) const;
  bool is_known_to_be_defined(void) const;
  bool is_local_variable_declaration(void) const;
  bool is_local_variable_declaration_or_parm(void) const;
  bool is_nrvo_variable(void) const;
  bool is_no_destroy(void) const;
  bool is_non_escaping_byref(void) const;
  bool is_obj_c_for_declaration(void) const;
  bool is_previous_declaration_in_same_block_scope(void) const;
  bool is_static_data_member(void) const;
  bool is_static_local(void) const;
  bool is_demoted_definition(void) const;
  bool is_usable_in_constant_expressions(void) const;
  bool might_be_usable_in_constant_expressions(void) const;
  QualTypeDestructionKind needs_destruction(void) const;
};

static_assert(sizeof(VarDecl) == sizeof(DeclaratorDecl));

#endif
} // namespace mx
