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

#include "AccessSpecifier.h"
#include "AttrUseSelector.h"
#include "AvailabilityResult.h"
#include "DeclCategory.h"
#include "DeclFriendObjectKind.h"
#include "DeclKind.h"
#include "DeclModuleOwnershipKind.h"
#include "DeclUseSelector.h"

namespace mx {
class Attr;
class Decl;
class ExternalSourceSymbolAttr;
class Stmt;
class StmtReferenceRange;
class TemplateParameterList;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using DeclRange = DerivedEntityRange<DeclIterator, Decl>;
using DeclContainingTokenRange = DerivedEntityRange<TokenContextIterator, Decl>;
using DeclContainingDeclRange = DerivedEntityRange<ParentDeclIteratorImpl<Decl>, Decl>;

class Decl {
 protected:
  friend class Attr;
  friend class AttrIterator;
  friend class DeclIterator;
  friend class File;
  friend class Fragment;
  friend class FragmentImpl;
  friend class Index;
  friend class Macro;
  friend class MacroReferenceIterator;
  friend class ReferenceIteratorImpl;
  friend class Stmt;
  friend class StmtReferenceIterator;
  friend class StmtIterator;
  friend class TokenContext;
  friend class Type;
  friend class TypeIterator;
  friend class UseBase;
  friend class UseIteratorImpl;
  template <typename> friend class UseIterator;

  std::shared_ptr<const FragmentImpl> fragment;
  unsigned offset_;

 public:
  Decl(Decl &&) noexcept = default;
  Decl(const Decl &) = default;
  Decl &operator=(Decl &&) noexcept = default;
  Decl &operator=(const Decl &) = default;

  inline Decl(std::shared_ptr<const FragmentImpl> fragment_, unsigned offset__)
      : fragment(std::move(fragment_)),
        offset_(offset__) {}

  inline static std::optional<Decl> from(const Decl &self) {
    return self;
  }

  inline static std::optional<Decl> from(const std::optional<Decl> &self) {
    return self;
  }

  inline static std::optional<Decl> from(const TokenContext &c) {
    return c.as_declaration();
  }

  std::optional<Decl> parent_declaration(void) const;
  std::optional<Stmt> parent_statement(void) const;
  std::optional<Decl> definition(void) const;
  bool is_definition(void) const;
  std::vector<Decl> redeclarations(void) const;
  SpecificEntityId<DeclarationId> id(void) const;
  UseRange<DeclUseSelector> uses(void) const;
  StmtReferenceRange references(void) const;

 protected:
  static DeclIterator in_internal(const Fragment &fragment);

 public:
  inline static DeclRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static DeclContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(tok.context());
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : Decl::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  static DeclContainingDeclRange containing(const Decl &decl);
  static DeclContainingDeclRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  std::vector<Attr> attributes(void) const;
  AccessSpecifier access(void) const;
  AvailabilityResult availability(void) const;
  std::optional<Attr> defining_attribute(void) const;
  std::optional<TemplateParameterList> described_template_parameters(void) const;
  std::optional<ExternalSourceSymbolAttr> external_source_symbol_attribute(void) const;
  DeclFriendObjectKind friend_object_kind(void) const;
  DeclModuleOwnershipKind module_ownership_kind(void) const;
  std::optional<Decl> non_closure_context(void) const;
  bool has_attributes(void) const;
  bool has_owning_module(void) const;
  bool has_tag_identifier_namespace(void) const;
  bool is_defined_outside_function_or_method(void) const;
  bool is_deprecated(void) const;
  bool is_discarded_in_global_module_fragment(void) const;
  bool is_function_or_function_template(void) const;
  bool is_implicit(void) const;
  bool is_in_anonymous_namespace(void) const;
  bool is_in_export_declaration_context(void) const;
  bool is_in_local_scope_for_instantiation(void) const;
  bool is_in_std_namespace(void) const;
  bool is_invalid_declaration(void) const;
  bool is_invisible_outside_the_owning_module(void) const;
  bool is_module_private(void) const;
  bool is_out_of_line(void) const;
  bool is_parameter_pack(void) const;
  bool is_reachable(void) const;
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
