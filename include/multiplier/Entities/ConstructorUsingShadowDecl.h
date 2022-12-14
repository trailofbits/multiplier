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
#include "UsingShadowDecl.h"

namespace mx {
class CXXRecordDecl;
class ConstructorUsingShadowDecl;
class Decl;
class NamedDecl;
class UsingShadowDecl;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using ConstructorUsingShadowDeclContainingDeclRange = DerivedEntityRange<ParentDeclIteratorImpl<Decl>, ConstructorUsingShadowDecl>;

class ConstructorUsingShadowDecl : public UsingShadowDecl {
 private:
  friend class FragmentImpl;
  friend class UsingShadowDecl;
  friend class NamedDecl;
  friend class Decl;
 public:
  inline static gap::generator<ConstructorUsingShadowDecl> in(const Fragment &frag) {
    for(auto e : in_internal(frag)) {
      if(auto d = from(e)) {
        co_yield *d;
      }
    }
  }

  inline static gap::generator<ConstructorUsingShadowDecl> containing(const Token &tok) {
    for(auto ctx = TokenContext::of(tok); ctx.has_value(); ctx = ctx->parent()) {
      if(auto d = from(*ctx)) {
        co_yield *d;
      }
    }
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : ConstructorUsingShadowDecl::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::CONSTRUCTOR_USING_SHADOW;
  }

  static ConstructorUsingShadowDeclContainingDeclRange containing(const Decl &decl);
  static ConstructorUsingShadowDeclContainingDeclRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<ConstructorUsingShadowDecl> from(const TokenContext &c);
  static std::optional<ConstructorUsingShadowDecl> from(const UsingShadowDecl &parent);

  inline static std::optional<ConstructorUsingShadowDecl> from(const std::optional<UsingShadowDecl> &parent) {
    if (parent) {
      return ConstructorUsingShadowDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ConstructorUsingShadowDecl> from(const NamedDecl &parent);

  inline static std::optional<ConstructorUsingShadowDecl> from(const std::optional<NamedDecl> &parent) {
    if (parent) {
      return ConstructorUsingShadowDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ConstructorUsingShadowDecl> from(const Decl &parent);

  inline static std::optional<ConstructorUsingShadowDecl> from(const std::optional<Decl> &parent) {
    if (parent) {
      return ConstructorUsingShadowDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  bool constructs_virtual_base(void) const;
  CXXRecordDecl constructed_base_class(void) const;
  std::optional<ConstructorUsingShadowDecl> constructed_base_class_shadow_declaration(void) const;
  CXXRecordDecl nominated_base_class(void) const;
  std::optional<ConstructorUsingShadowDecl> nominated_base_class_shadow_declaration(void) const;
};

static_assert(sizeof(ConstructorUsingShadowDecl) == sizeof(UsingShadowDecl));

#endif
} // namespace mx
