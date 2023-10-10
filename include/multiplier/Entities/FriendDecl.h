// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Decl.h"

namespace mx {
class EntityProvider;
class Index;
class Decl;
class FriendDecl;
class NamedDecl;
class Stmt;
class TemplateParameterList;
class Token;
class Type;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class FriendDecl : public Decl {
 private:
  friend class FragmentImpl;
  friend class Decl;
 public:
  static gap::generator<FriendDecl> in(const Index &index);
  static gap::generator<FriendDecl> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<FriendDecl> by_id(const Index &, EntityId);
  static gap::generator<FriendDecl> in(const Fragment &frag);
  static gap::generator<FriendDecl> in(const File &file);

  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::FRIEND;
  }

  static gap::generator<FriendDecl> containing(const Decl &decl);
  static gap::generator<FriendDecl> containing(const std::optional<Decl> &decl);

  static gap::generator<FriendDecl> containing(const Stmt &stmt);
  static gap::generator<FriendDecl> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  FriendDecl canonical_declaration(void) const;
  std::optional<FriendDecl> definition(void) const;
  gap::generator<FriendDecl> redeclarations(void) const &;
  static std::optional<FriendDecl> from(const Decl &parent);

  inline static std::optional<FriendDecl> from(const std::optional<Decl> &parent) {
    if (parent) {
      return FriendDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<FriendDecl> from(const Reference &r);
  static std::optional<FriendDecl> from(const TokenContext &t);

  std::optional<NamedDecl> friend_declaration(void) const;
  Token friend_token(void) const;
  std::optional<Type> friend_type(void) const;
  bool is_unsupported_friend(void) const;
  std::optional<TemplateParameterList> nth_friend_type_template_parameter_list(unsigned n) const;
  unsigned num_friend_type_template_parameter_lists(void) const;
  gap::generator<TemplateParameterList> friend_type_template_parameter_lists(void) const &;
};

static_assert(sizeof(FriendDecl) == sizeof(Decl));

#endif
} // namespace mx
