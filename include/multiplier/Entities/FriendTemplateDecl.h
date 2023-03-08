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
#include <span>
#include <vector>

#include <gap/core/generator.hpp>
#include "../Iterator.h"
#include "../Reference.h"
#include "../Types.h"
#include "../Token.h"

#include "Decl.h"

namespace mx {
class Decl;
class FriendTemplateDecl;
class NamedDecl;
class Stmt;
class TemplateParameterList;
class Token;
class Type;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class FriendTemplateDecl : public Decl {
 private:
  friend class FragmentImpl;
  friend class Decl;
 public:
  static gap::generator<FriendTemplateDecl> in(const Fragment &frag);
  static gap::generator<FriendTemplateDecl> in(const File &file);
  static gap::generator<FriendTemplateDecl> in(const Index &index);
  static gap::generator<FriendTemplateDecl> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<FriendTemplateDecl> by_id(const Index &, EntityId);

  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::FRIEND_TEMPLATE;
  }

  static gap::generator<FriendTemplateDecl> containing(const Decl &decl);
  static gap::generator<FriendTemplateDecl> containing(const std::optional<Decl> &decl);

  static gap::generator<FriendTemplateDecl> containing(const Stmt &stmt);
  static gap::generator<FriendTemplateDecl> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  gap::generator<FriendTemplateDecl> redeclarations(void) const &;
  static std::optional<FriendTemplateDecl> from(const Decl &parent);

  inline static std::optional<FriendTemplateDecl> from(const std::optional<Decl> &parent) {
    if (parent) {
      return FriendTemplateDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  inline static std::optional<FriendTemplateDecl> from(const Reference &r) {
    return FriendTemplateDecl::from(r.as_declaration());
  }

  inline static std::optional<FriendTemplateDecl> from(const TokenContext &t) {
    return FriendTemplateDecl::from(t.as_declaration());
  }

  NamedDecl friend_declaration(void) const;
  Token friend_token(void) const;
  Type friend_type(void) const;
  std::optional<TemplateParameterList> nth_template_parameter_list(unsigned n) const;
  unsigned num_template_parameter_lists(void) const;
  gap::generator<TemplateParameterList> template_parameter_lists(void) const &;
};

static_assert(sizeof(FriendTemplateDecl) == sizeof(Decl));

#endif
} // namespace mx
