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

#include "../Iterator.h"
#include "../Types.h"
#include "../Token.h"
#include "../Use.h"

#include "DeclKind.h"
#include "DeclaratorDecl.h"
#include "InClassInitStyle.h"
#include "StmtUseSelector.h"
#include "TypeUseSelector.h"

namespace mx {
class Decl;
class DeclaratorDecl;
class Expr;
class FieldDecl;
class NamedDecl;
class ValueDecl;
class VariableArrayType;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using FieldDeclRange = DerivedEntityRange<DeclIterator, FieldDecl>;
using FieldDeclContainingTokenRange = DerivedEntityRange<TokenContextIterator, FieldDecl>;
using FieldDeclContainingDeclRange = DerivedEntityRange<ParentDeclIteratorImpl<Decl>, FieldDecl>;

class FieldDecl : public DeclaratorDecl {
 private:
  friend class FragmentImpl;
  friend class DeclaratorDecl;
  friend class ValueDecl;
  friend class NamedDecl;
  friend class Decl;
 public:
  inline static FieldDeclRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static FieldDeclContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : FieldDecl::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::FIELD;
  }

  static FieldDeclContainingDeclRange containing(const Decl &decl);
  static FieldDeclContainingDeclRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<FieldDecl> from(const TokenContext &c);
  static std::optional<FieldDecl> from(const DeclaratorDecl &parent);

  inline static std::optional<FieldDecl> from(const std::optional<DeclaratorDecl> &parent) {
    if (parent) {
      return FieldDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<FieldDecl> from(const ValueDecl &parent);

  inline static std::optional<FieldDecl> from(const std::optional<ValueDecl> &parent) {
    if (parent) {
      return FieldDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<FieldDecl> from(const NamedDecl &parent);

  inline static std::optional<FieldDecl> from(const std::optional<NamedDecl> &parent) {
    if (parent) {
      return FieldDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<FieldDecl> from(const Decl &parent);

  inline static std::optional<FieldDecl> from(const std::optional<Decl> &parent) {
    if (parent) {
      return FieldDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

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
