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
#include "TagTypeKind.h"
#include "TypeDecl.h"

namespace mx {
class Decl;
class NamedDecl;
class TagDecl;
class TemplateParameterList;
class TypeDecl;
class TypedefNameDecl;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using TagDeclRange = DerivedEntityRange<DeclIterator, TagDecl>;
using TagDeclContainingTokenRange = DerivedEntityRange<TokenContextIterator, TagDecl>;
using TagDeclContainingDeclRange = DerivedEntityRange<ParentDeclIteratorImpl<Decl>, TagDecl>;

class TagDecl : public TypeDecl {
 private:
  friend class FragmentImpl;
  friend class TypeDecl;
  friend class NamedDecl;
  friend class Decl;
 public:
  inline static TagDeclRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static TagDeclContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : TagDecl::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::TAG;
  }

  static TagDeclContainingDeclRange containing(const Decl &decl);
  static TagDeclContainingDeclRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<TagDecl> from(const TokenContext &c);
  static std::optional<TagDecl> from(const TypeDecl &parent);

  inline static std::optional<TagDecl> from(const std::optional<TypeDecl> &parent) {
    if (parent) {
      return TagDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<TagDecl> from(const NamedDecl &parent);

  inline static std::optional<TagDecl> from(const std::optional<NamedDecl> &parent) {
    if (parent) {
      return TagDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<TagDecl> from(const Decl &parent);

  inline static std::optional<TagDecl> from(const std::optional<Decl> &parent) {
    if (parent) {
      return TagDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  TokenRange brace_range(void) const;
  Token first_inner_token(void) const;
  Token first_outer_token(void) const;
  TagTypeKind tag_kind(void) const;
  std::optional<TypedefNameDecl> typedef_name_for_anonymous_declaration(void) const;
  bool has_name_for_linkage(void) const;
  bool is_being_defined(void) const;
  bool is_class(void) const;
  bool is_complete_definition(void) const;
  bool is_complete_definition_required(void) const;
  bool is_dependent_type(void) const;
  bool is_embedded_in_declarator(void) const;
  bool is_enum(void) const;
  bool is_free_standing(void) const;
  bool is_interface(void) const;
  bool is_struct(void) const;
  bool is_demoted_definition(void) const;
  bool is_union(void) const;
  bool may_have_out_of_date_definition(void) const;
  std::vector<TemplateParameterList> template_parameter_lists(void) const;
  std::vector<Decl> declarations_in_context(void) const;
};

static_assert(sizeof(TagDecl) == sizeof(TypeDecl));

#endif
} // namespace mx
