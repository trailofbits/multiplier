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
class EnumDecl : public TagDecl {
 private:
  friend class FragmentImpl;
  friend class TagDecl;
  friend class TypeDecl;
  friend class NamedDecl;
  friend class Decl;
 public:
  inline static gap::generator<EnumDecl> in(const Fragment &frag) {
    for (auto e : in_internal(frag)) {
      if (auto d = from(e)) {
        co_yield *d;
      }
    }
  }

  inline static gap::generator<EnumDecl> containing(const Token &tok) {
    for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
      if (auto d = from(*ctx)) {
        co_yield *d;
      }
    }
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : EnumDecl::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::ENUM;
  }

  static gap::generator<EnumDecl> containing(const Decl &decl);
  static gap::generator<EnumDecl> containing(const Stmt &stmt);

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

  std::optional<EnumConstantDecl> nth_enumerator(unsigned n) const;
  gap::generator<EnumConstantDecl> enumerators(void) const;
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
