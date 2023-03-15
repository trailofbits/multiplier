// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "DeclaratorDecl.h"
#include "InClassInitStyle.h"

namespace mx {
class EntityProvider;
class Index;
class Decl;
class DeclaratorDecl;
class Expr;
class FieldDecl;
class NamedDecl;
class ObjCAtDefsFieldDecl;
class ObjCIvarDecl;
class Stmt;
class Token;
class ValueDecl;
class VariableArrayType;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class FieldDecl : public DeclaratorDecl {
 private:
  friend class FragmentImpl;
  friend class DeclaratorDecl;
  friend class ValueDecl;
  friend class NamedDecl;
  friend class Decl;
 public:
  static gap::generator<FieldDecl> in(const Fragment &frag);
  static gap::generator<FieldDecl> in(const File &file);
  static gap::generator<FieldDecl> in(const Index &index);
  static gap::generator<FieldDecl> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<FieldDecl> by_id(const Index &, EntityId);

  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::FIELD;
  }

  static gap::generator<FieldDecl> containing(const Decl &decl);
  static gap::generator<FieldDecl> containing(const std::optional<Decl> &decl);

  static gap::generator<FieldDecl> containing(const Stmt &stmt);
  static gap::generator<FieldDecl> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  gap::generator<FieldDecl> redeclarations(void) const &;
  static std::optional<FieldDecl> from(const Decl &parent);

  inline static std::optional<FieldDecl> from(const std::optional<Decl> &parent) {
    if (parent) {
      return FieldDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<FieldDecl> from(const Reference &r);
  static std::optional<FieldDecl> from(const TokenContext &t);

  std::optional<Expr> bit_width(void) const;
  std::optional<VariableArrayType> captured_vla_type(void) const;
  InClassInitStyle in_class_initializer_style(void) const;
  std::optional<Expr> in_class_initializer(void) const;
  bool has_captured_vla_type(void) const;
  bool has_in_class_initializer(void) const;
  bool is_anonymous_struct_or_union(void) const;
  bool is_bit_field(void) const;
  bool is_mutable(void) const;
  bool is_unnamed_bitfield(void) const;
  bool is_zero_length_bit_field(void) const;
  bool is_zero_size(void) const;
};

static_assert(sizeof(FieldDecl) == sizeof(DeclaratorDecl));

#endif
} // namespace mx
