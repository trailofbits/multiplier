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
#include "TypedefNameDecl.h"

namespace mx {
class Decl;
class NamedDecl;
class TypeDecl;
class TypedefDecl;
class TypedefNameDecl;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using TypedefDeclContainingTokenRange = DerivedEntityRange<TokenContextIterator, TypedefDecl>;
using TypedefDeclContainingDeclRange = DerivedEntityRange<ParentDeclIteratorImpl<Decl>, TypedefDecl>;

class TypedefDecl : public TypedefNameDecl {
 private:
  friend class FragmentImpl;
  friend class TypedefNameDecl;
  friend class TypeDecl;
  friend class NamedDecl;
  friend class Decl;
 public:
  inline static gap::generator<TypedefDecl> in(const Fragment &frag) {
    for(auto e : in_internal(frag)) {
      if(auto d = from(e)) {
        co_yield *d;
      }
    }
  }

  inline static TypedefDeclContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : TypedefDecl::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::TYPEDEF;
  }

  static TypedefDeclContainingDeclRange containing(const Decl &decl);
  static TypedefDeclContainingDeclRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<TypedefDecl> from(const TokenContext &c);
  static std::optional<TypedefDecl> from(const TypedefNameDecl &parent);

  inline static std::optional<TypedefDecl> from(const std::optional<TypedefNameDecl> &parent) {
    if (parent) {
      return TypedefDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<TypedefDecl> from(const TypeDecl &parent);

  inline static std::optional<TypedefDecl> from(const std::optional<TypeDecl> &parent) {
    if (parent) {
      return TypedefDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<TypedefDecl> from(const NamedDecl &parent);

  inline static std::optional<TypedefDecl> from(const std::optional<NamedDecl> &parent) {
    if (parent) {
      return TypedefDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<TypedefDecl> from(const Decl &parent);

  inline static std::optional<TypedefDecl> from(const std::optional<Decl> &parent) {
    if (parent) {
      return TypedefDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

};

static_assert(sizeof(TypedefDecl) == sizeof(TypedefNameDecl));

#endif
} // namespace mx
