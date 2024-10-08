// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <multiplier/AST/DeclaratorDecl.h>
#include <multiplier/AST/LanguageLinkage.h>
#include <multiplier/AST/StorageClass.h>
#include <multiplier/AST/StorageDuration.h>
#include <multiplier/AST/ThreadStorageClassSpecifier.h>
#include <multiplier/AST/VarDeclInitializationStyle.h>
#include <multiplier/AST/VarDeclTLSKind.h>

namespace mx {
class EntityProvider;
class Fragment;
class Index;
class Decl;
class DeclaratorDecl;
class Expr;
class File;
class NamedDecl;
class Stmt;
class Token;
class ValueDecl;
class VarDecl;
class VarTemplateDecl;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT VarDecl : public DeclaratorDecl {
 private:
  friend class FragmentImpl;
  friend class DeclaratorDecl;
  friend class ValueDecl;
  friend class NamedDecl;
  friend class Decl;
 public:
  static gap::generator<VarDecl> in(const Index &index);
  static gap::generator<VarDecl> in(const Fragment &frag);
  static gap::generator<VarDecl> in(const File &file);
  static gap::generator<VarDecl> containing(const Token &tok);
  bool contains(const Token &tok) const;

  static std::optional<VarDecl> from(const ir::Operation &op);
  static gap::generator<std::pair<VarDecl, ir::Operation>> in(const Compilation &tu);
  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::VAR;
  }

  static gap::generator<VarDecl> containing(const Decl &decl);
  static gap::generator<VarDecl> containing(const std::optional<Decl> &decl);

  static gap::generator<VarDecl> containing(const Stmt &stmt);
  static gap::generator<VarDecl> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  VarDecl canonical_declaration(void) const;
  std::optional<VarDecl> definition(void) const;
  gap::generator<VarDecl> redeclarations(void) const &;
  static std::optional<VarDecl> by_id(const Index &, EntityId);

  static std::optional<VarDecl> from_base(const Decl &parent);
  inline static std::optional<VarDecl> from(const Decl &parent) {
    return from_base(parent);
  }
  static std::optional<VarDecl> from(const std::optional<Decl> &parent);
  static std::optional<VarDecl> from(const Reference &r);
  static std::optional<VarDecl> from(const VariantEntity &e);
  static std::optional<VarDecl> from(const TokenContext &t);

  std::optional<VarDecl> acting_definition(void) const;
  std::optional<VarTemplateDecl> described_variable_template(void) const;
  std::optional<Expr> initializer(void) const;
  VarDeclInitializationStyle initializer_style(void) const;
  std::optional<VarDecl> initializing_declaration(void) const;
  LanguageLinkage language_linkage(void) const;
  StorageClass storage_class(void) const;
  StorageDuration storage_duration(void) const;
  VarDeclTLSKind tls_kind(void) const;
  ThreadStorageClassSpecifier tsc_spec(void) const;
  bool has_constant_initialization(void) const;
  bool has_dependent_alignment(void) const;
  bool has_external_storage(void) const;
  std::optional<bool> has_flexible_array_initializer(void) const;
  bool has_global_storage(void) const;
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
  bool is_this_declaration_a_demoted_definition(void) const;
  bool is_usable_in_constant_expressions(void) const;
  bool might_be_usable_in_constant_expressions(void) const;
};

static_assert(sizeof(VarDecl) == sizeof(DeclaratorDecl));

#endif
} // namespace mx
