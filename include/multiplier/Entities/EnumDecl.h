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
#include "TagDecl.h"
#include "TemplateSpecializationKind.h"
#include "TypeUseSelector.h"

namespace mx {
class Decl;
class EnumConstantDecl;
class EnumDecl;
class NamedDecl;
class TagDecl;
class Type;
class TypeDecl;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using EnumDeclRange = DerivedEntityRange<DeclIterator, EnumDecl>;
using EnumDeclContainingTokenRange = DerivedEntityRange<TokenContextIterator, EnumDecl>;
using EnumDeclContainingDeclRange = DerivedEntityRange<ParentDeclIteratorImpl<Decl>, EnumDecl>;

class EnumDecl : public TagDecl {
 private:
  friend class FragmentImpl;
  friend class TagDecl;
  friend class TypeDecl;
  friend class NamedDecl;
  friend class Decl;
 public:
  inline static EnumDeclRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static EnumDeclContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : EnumDecl::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::ENUM;
  }

  static EnumDeclContainingDeclRange containing(const Decl &decl);
  static EnumDeclContainingDeclRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<EnumDecl> from(const TokenContext &c);
  static std::optional<EnumDecl> from(const TagDecl &parent);

  inline static std::optional<EnumDecl> from(const std::optional<TagDecl> &parent) {
    if (parent) {
      return EnumDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<EnumDecl> from(const TypeDecl &parent);

  inline static std::optional<EnumDecl> from(const std::optional<TypeDecl> &parent) {
    if (parent) {
      return EnumDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<EnumDecl> from(const NamedDecl &parent);

  inline static std::optional<EnumDecl> from(const std::optional<NamedDecl> &parent) {
    if (parent) {
      return EnumDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<EnumDecl> from(const Decl &parent);

  inline static std::optional<EnumDecl> from(const std::optional<Decl> &parent) {
    if (parent) {
      return EnumDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  std::vector<EnumConstantDecl> enumerators(void) const;
  std::optional<EnumDecl> instantiated_from_member_enum(void) const;
  std::optional<Type> integer_type(void) const;
  TokenRange integer_type_range(void) const;
  std::optional<unsigned> odr_hash(void) const;
  std::optional<Type> promotion_type(void) const;
  std::optional<EnumDecl> template_instantiation_pattern(void) const;
  TemplateSpecializationKind template_specialization_kind(void) const;
  bool is_closed(void) const;
  bool is_closed_flag(void) const;
  bool is_closed_non_flag(void) const;
  bool is_complete(void) const;
  bool is_fixed(void) const;
  bool is_scoped(void) const;
  bool is_scoped_using_class_tag(void) const;
};

static_assert(sizeof(EnumDecl) == sizeof(TagDecl));

#endif
} // namespace mx
