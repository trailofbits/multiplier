// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <compare>
#include <cstdint>
#include <filesystem>
#include <gap/core/generator.hpp>
#include <memory>
#include <optional>
#include <span>
#include <vector>

#include "../Entity.h"
#include "../Iterator.h"

#include <multiplier/AST/AccessSpecifier.h>
#include <multiplier/AST/AvailabilityResult.h>
#include <multiplier/AST/DeclCategory.h>
#include <multiplier/AST/DeclFriendObjectKind.h>
#include <multiplier/AST/DeclKind.h>
#include <multiplier/AST/DeclModuleOwnershipKind.h>

namespace mx {
class EntityProvider;
class Fragment;
class Index;
class Reference;
class Attr;
class Decl;
class DeclImpl;
class ExternalSourceSymbolAttr;
class File;
class Stmt;
class TemplateDecl;
class TemplateParameterList;
class Token;
class TokenRange;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class Decl {
 public:
  std::optional<Decl> parent_declaration(void) const;
  std::optional<Stmt> parent_statement(void) const;
 protected:
  friend class Attr;
  friend class File;
  friend class Fragment;
  friend class FragmentImpl;
  friend class Index;
  friend class Macro;
  friend class Reference;
  friend class Stmt;
  friend class TokenContext;
  friend class Type;
  friend class DeclImpl;
  friend class ir::Operation;
  friend class ir::Value;

  std::shared_ptr<const DeclImpl> impl;
  static std::shared_ptr<EntityProvider> entity_provider_of(const Index &);
  static std::shared_ptr<EntityProvider> entity_provider_of(const Fragment &);
  static std::shared_ptr<EntityProvider> entity_provider_of(const File &);
 public:
  Decl(Decl &&) noexcept = default;
  Decl(const Decl &) = default;
  Decl &operator=(Decl &&) noexcept = default;
  Decl &operator=(const Decl &) = default;

  inline bool operator==(const Decl &rhs) const noexcept {
    return id().Pack() == rhs.id().Pack();
  }

  /* implicit */ inline Decl(std::shared_ptr<const DeclImpl> impl_)
      : impl(std::move(impl_)) {}

  constexpr inline static EntityCategory static_category(void) {
    return EntityCategory::DECLARATION;
  }

  PackedDeclId id(void) const;

  std::optional<Decl> definition(void) const;
  bool is_definition(void) const;
  Decl canonical_declaration(void) const;
  gap::generator<Decl> redeclarations(void) const &;
 public:
  static gap::generator<Decl> in(const Index &index, std::span<DeclKind> kinds);
  static gap::generator<Decl> in(const Fragment &frag, std::span<DeclKind> kinds);
  static gap::generator<Decl> in(const File &file, std::span<DeclKind> kinds);
  static gap::generator<Decl> in(const Index &index);
  static gap::generator<Decl> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<Decl> by_id(const Index &, EntityId);
  static gap::generator<Decl> in(const Fragment &frag);
  static gap::generator<Decl> in(const File &file);

  static gap::generator<Decl> containing(const Decl &decl);
  static gap::generator<Decl> containing(const std::optional<Decl> &decl);

  static gap::generator<Decl> containing(const Stmt &stmt);
  static gap::generator<Decl> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  inline static std::optional<Decl> from(const Decl &self) {
    return self;
  }

  inline static std::optional<Decl> from(const std::optional<Decl> &self) {
    return self;
  }

  static std::optional<Decl> from(const Reference &r);
  static std::optional<Decl> from(const VariantEntity &e);
  static std::optional<Decl> from(const TokenContext &t);

  std::optional<Attr> nth_attribute(unsigned n) const;
  unsigned num_attributes(void) const;
  gap::generator<Attr> attributes(void) const &;
  AccessSpecifier access(void) const;
  AvailabilityResult availability(void) const;
  std::optional<Attr> defining_attribute(void) const;
  std::optional<TemplateDecl> described_template(void) const;
  std::optional<TemplateParameterList> described_template_parameters(void) const;
  std::optional<ExternalSourceSymbolAttr> external_source_symbol_attribute(void) const;
  DeclFriendObjectKind friend_object_kind(void) const;
  std::optional<uint32_t> max_alignment(void) const;
  DeclModuleOwnershipKind module_ownership_kind(void) const;
  std::optional<Decl> non_closure_context(void) const;
  bool has_attributes(void) const;
  bool has_owning_module(void) const;
  bool has_tag_identifier_namespace(void) const;
  bool is_defined_outside_function_or_method(void) const;
  bool is_deprecated(void) const;
  bool is_discarded_in_global_module_fragment(void) const;
  bool is_file_context_declaration(void) const;
  bool is_function_or_function_template(void) const;
  bool is_function_pointer_type(void) const;
  bool is_implicit(void) const;
  bool is_in_anonymous_namespace(void) const;
  bool is_in_another_module_unit(void) const;
  bool is_in_export_declaration_context(void) const;
  std::optional<bool> is_in_local_scope_for_instantiation(void) const;
  bool is_in_std_namespace(void) const;
  bool is_invisible_outside_the_owning_module(void) const;
  bool is_local_extern_declaration(void) const;
  bool is_module_private(void) const;
  bool is_out_of_line(void) const;
  bool is_parameter_pack(void) const;
  bool is_template_declaration(void) const;
  bool is_template_parameter(void) const;
  bool is_template_parameter_pack(void) const;
  bool is_templated(void) const;
  bool is_top_level_declaration_in_obj_c_container(void) const;
  bool is_unavailable(void) const;
  bool is_unconditionally_visible(void) const;
  bool is_weak_imported(void) const;
  DeclKind kind(void) const;
  DeclCategory category(void) const;
  Token token(void) const;
  TokenRange tokens(void) const;
};

#endif
} // namespace mx
