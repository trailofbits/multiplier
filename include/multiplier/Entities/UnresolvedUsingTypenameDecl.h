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
#include "TypeDecl.h"

namespace mx {
class Decl;
class NamedDecl;
class TypeDecl;
class UnresolvedUsingTypenameDecl;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class UnresolvedUsingTypenameDecl : public TypeDecl {
 private:
  friend class FragmentImpl;
  friend class TypeDecl;
  friend class NamedDecl;
  friend class Decl;
 public:
  inline static gap::generator<UnresolvedUsingTypenameDecl> in(const Fragment &frag) {
    for(auto e : in_internal(frag)) {
      if(auto d = from(e)) {
        co_yield *d;
      }
    }
  }

  inline static gap::generator<UnresolvedUsingTypenameDecl> containing(const Token &tok) {
    for(auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
      if(auto d = from(*ctx)) {
        co_yield *d;
      }
    }
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : UnresolvedUsingTypenameDecl::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::UNRESOLVED_USING_TYPENAME;
  }

  static gap::generator<UnresolvedUsingTypenameDecl> containing(const Decl &decl);
  static gap::generator<UnresolvedUsingTypenameDecl> containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<UnresolvedUsingTypenameDecl> from(const TokenContext &c);
  static std::optional<UnresolvedUsingTypenameDecl> from(const TypeDecl &parent);

  inline static std::optional<UnresolvedUsingTypenameDecl> from(const std::optional<TypeDecl> &parent) {
    if (parent) {
      return UnresolvedUsingTypenameDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<UnresolvedUsingTypenameDecl> from(const NamedDecl &parent);

  inline static std::optional<UnresolvedUsingTypenameDecl> from(const std::optional<NamedDecl> &parent) {
    if (parent) {
      return UnresolvedUsingTypenameDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<UnresolvedUsingTypenameDecl> from(const Decl &parent);

  inline static std::optional<UnresolvedUsingTypenameDecl> from(const std::optional<Decl> &parent) {
    if (parent) {
      return UnresolvedUsingTypenameDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  Token ellipsis_token(void) const;
  Token typename_token(void) const;
  Token using_token(void) const;
  bool is_pack_expansion(void) const;
};

static_assert(sizeof(UnresolvedUsingTypenameDecl) == sizeof(TypeDecl));

#endif
} // namespace mx
