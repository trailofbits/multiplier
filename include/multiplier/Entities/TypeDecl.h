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
#include "NamedDecl.h"
#include "TypeUseSelector.h"

namespace mx {
class Decl;
class NamedDecl;
class Type;
class TypeDecl;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using TypeDeclContainingTokenRange = DerivedEntityRange<TokenContextIterator, TypeDecl>;
using TypeDeclContainingDeclRange = DerivedEntityRange<ParentDeclIteratorImpl<Decl>, TypeDecl>;

class TypeDecl : public NamedDecl {
 private:
  friend class FragmentImpl;
  friend class NamedDecl;
  friend class Decl;
 public:
  inline static gap::generator<TypeDecl> in(const Fragment &frag) {
    for(auto e : in_internal(frag)) {
      if(auto d = from(e)) {
        co_yield *d;
      }
    }
  }

  inline static TypeDeclContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : TypeDecl::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::TYPE;
  }

  static TypeDeclContainingDeclRange containing(const Decl &decl);
  static TypeDeclContainingDeclRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<TypeDecl> from(const TokenContext &c);
  static std::optional<TypeDecl> from(const NamedDecl &parent);

  inline static std::optional<TypeDecl> from(const std::optional<NamedDecl> &parent) {
    if (parent) {
      return TypeDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<TypeDecl> from(const Decl &parent);

  inline static std::optional<TypeDecl> from(const std::optional<Decl> &parent) {
    if (parent) {
      return TypeDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  std::optional<Type> type_for_declaration(void) const;
};

static_assert(sizeof(TypeDecl) == sizeof(NamedDecl));

#endif
} // namespace mx
