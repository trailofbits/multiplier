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
#include "TypeDecl.h"

namespace mx {
class Decl;
class NamedDecl;
class TagDecl;
class Type;
class TypeDecl;
class TypedefNameDecl;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using TypedefNameDeclContainingDeclRange = DerivedEntityRange<ParentDeclIteratorImpl<Decl>, TypedefNameDecl>;

class TypedefNameDecl : public TypeDecl {
 private:
  friend class FragmentImpl;
  friend class TypeDecl;
  friend class NamedDecl;
  friend class Decl;
 public:
  inline static gap::generator<TypedefNameDecl> in(const Fragment &frag) {
    for(auto e : in_internal(frag)) {
      if(auto d = from(e)) {
        co_yield *d;
      }
    }
  }

  inline static gap::generator<TypedefNameDecl> containing(const Token &tok) {
    for(auto ctx = TokenContext::of(tok); ctx.has_value(); ctx = ctx->parent()) {
      if(auto d = from(*ctx)) {
        co_yield *d;
      }
    }
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : TypedefNameDecl::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::TYPEDEF_NAME;
  }

  static TypedefNameDeclContainingDeclRange containing(const Decl &decl);
  static TypedefNameDeclContainingDeclRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<TypedefNameDecl> from(const TokenContext &c);
  static std::optional<TypedefNameDecl> from(const TypeDecl &parent);

  inline static std::optional<TypedefNameDecl> from(const std::optional<TypeDecl> &parent) {
    if (parent) {
      return TypedefNameDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<TypedefNameDecl> from(const NamedDecl &parent);

  inline static std::optional<TypedefNameDecl> from(const std::optional<NamedDecl> &parent) {
    if (parent) {
      return TypedefNameDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<TypedefNameDecl> from(const Decl &parent);

  inline static std::optional<TypedefNameDecl> from(const std::optional<Decl> &parent) {
    if (parent) {
      return TypedefNameDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  std::optional<TagDecl> anonymous_declaration_with_typedef_name(void) const;
  Type underlying_type(void) const;
  bool is_moded(void) const;
  bool is_transparent_tag(void) const;
};

static_assert(sizeof(TypedefNameDecl) == sizeof(TypeDecl));

#endif
} // namespace mx
