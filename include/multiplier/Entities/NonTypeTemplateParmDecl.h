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
#include "StmtUseSelector.h"

namespace mx {
class Decl;
class DeclaratorDecl;
class Expr;
class NamedDecl;
class NonTypeTemplateParmDecl;
class Type;
class ValueDecl;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using NonTypeTemplateParmDeclRange = DerivedEntityRange<DeclIterator, NonTypeTemplateParmDecl>;
using NonTypeTemplateParmDeclContainingTokenRange = DerivedEntityRange<TokenContextIterator, NonTypeTemplateParmDecl>;
using NonTypeTemplateParmDeclContainingDeclRange = DerivedEntityRange<ParentDeclIteratorImpl<Decl>, NonTypeTemplateParmDecl>;

class NonTypeTemplateParmDecl : public DeclaratorDecl {
 private:
  friend class FragmentImpl;
  friend class DeclaratorDecl;
  friend class ValueDecl;
  friend class NamedDecl;
  friend class Decl;
 public:
  inline static NonTypeTemplateParmDeclRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static NonTypeTemplateParmDeclContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for(auto &parent : NonTypeTemplateParmDecl::containing(tok)) {
      if(parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::NON_TYPE_TEMPLATE_PARM;
  }

  static NonTypeTemplateParmDeclContainingDeclRange containing(const Decl &decl);
  static NonTypeTemplateParmDeclContainingDeclRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<NonTypeTemplateParmDecl> from(const TokenContext &c);
  static std::optional<NonTypeTemplateParmDecl> from(const DeclaratorDecl &parent);

  inline static std::optional<NonTypeTemplateParmDecl> from(const std::optional<DeclaratorDecl> &parent) {
    if (parent) {
      return NonTypeTemplateParmDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<NonTypeTemplateParmDecl> from(const ValueDecl &parent);

  inline static std::optional<NonTypeTemplateParmDecl> from(const std::optional<ValueDecl> &parent) {
    if (parent) {
      return NonTypeTemplateParmDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<NonTypeTemplateParmDecl> from(const NamedDecl &parent);

  inline static std::optional<NonTypeTemplateParmDecl> from(const std::optional<NamedDecl> &parent) {
    if (parent) {
      return NonTypeTemplateParmDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<NonTypeTemplateParmDecl> from(const Decl &parent);

  inline static std::optional<NonTypeTemplateParmDecl> from(const std::optional<Decl> &parent) {
    if (parent) {
      return NonTypeTemplateParmDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  bool default_argument_was_inherited(void) const;
  std::optional<Expr> default_argument(void) const;
  Token default_argument_token(void) const;
  std::optional<unsigned> num_expansion_types(void) const;
  std::optional<Expr> placeholder_type_constraint(void) const;
  bool has_default_argument(void) const;
  bool has_placeholder_type_constraint(void) const;
  bool is_expanded_parameter_pack(void) const;
  bool is_pack_expansion(void) const;
  std::vector<Type> expansion_types(void) const;
};

static_assert(sizeof(NonTypeTemplateParmDecl) == sizeof(DeclaratorDecl));

#endif
} // namespace mx
