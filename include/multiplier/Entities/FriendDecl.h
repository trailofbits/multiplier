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

#include "Decl.h"
#include "DeclKind.h"
#include "DeclUseSelector.h"
#include "TypeUseSelector.h"

namespace mx {
class Decl;
class FriendDecl;
class NamedDecl;
class TemplateParameterList;
class Type;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class FriendDecl : public Decl {
 private:
  friend class FragmentImpl;
  friend class Decl;
 public:
  inline static gap::generator<FriendDecl> in(const Fragment &frag) {
    for (auto e : in_internal(frag)) {
      if (auto d = from(e)) {
        co_yield *d;
      }
    }
  }

  inline static gap::generator<FriendDecl> containing(const Token &tok) {
    for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
      if (auto d = from(*ctx)) {
        co_yield *d;
      }
    }
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : FriendDecl::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::FRIEND;
  }

  static gap::generator<FriendDecl> containing(const Decl &decl);
  static gap::generator<FriendDecl> containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<FriendDecl> from(const TokenContext &c);
  static std::optional<FriendDecl> from(const Decl &parent);

  inline static std::optional<FriendDecl> from(const std::optional<Decl> &parent) {
    if (parent) {
      return FriendDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  std::optional<NamedDecl> friend_declaration(void) const;
  Token friend_token(void) const;
  std::optional<Type> friend_type(void) const;
  bool is_unsupported_friend(void) const;
  std::optional<TemplateParameterList> nth_friend_type_template_parameter_list(unsigned n) const;
  gap::generator<TemplateParameterList> friend_type_template_parameter_lists(void) const;
};

static_assert(sizeof(FriendDecl) == sizeof(Decl));

#endif
} // namespace mx
