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
#include "StmtUseSelector.h"
#include "ValueDecl.h"

namespace mx {
class Decl;
class DeclaratorDecl;
class Expr;
class NamedDecl;
class TemplateParameterList;
class ValueDecl;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using DeclaratorDeclRange = DerivedEntityRange<DeclIterator, DeclaratorDecl>;
using DeclaratorDeclContainingTokenRange = DerivedEntityRange<TokenContextIterator, DeclaratorDecl>;
using DeclaratorDeclContainingDeclRange = DerivedEntityRange<ParentDeclIteratorImpl<Decl>, DeclaratorDecl>;

class DeclaratorDecl : public ValueDecl {
 private:
  friend class FragmentImpl;
  friend class ValueDecl;
  friend class NamedDecl;
  friend class Decl;
 public:
  inline static DeclaratorDeclRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static DeclaratorDeclContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for (auto &parent : DeclaratorDecl::containing(tok)) {
      if (parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::DECLARATOR;
  }

  static DeclaratorDeclContainingDeclRange containing(const Decl &decl);
  static DeclaratorDeclContainingDeclRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<DeclaratorDecl> from(const TokenContext &c);
  static std::optional<DeclaratorDecl> from(const ValueDecl &parent);

  inline static std::optional<DeclaratorDecl> from(const std::optional<ValueDecl> &parent) {
    if (parent) {
      return DeclaratorDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<DeclaratorDecl> from(const NamedDecl &parent);

  inline static std::optional<DeclaratorDecl> from(const std::optional<NamedDecl> &parent) {
    if (parent) {
      return DeclaratorDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<DeclaratorDecl> from(const Decl &parent);

  inline static std::optional<DeclaratorDecl> from(const std::optional<Decl> &parent) {
    if (parent) {
      return DeclaratorDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  Token first_inner_token(void) const;
  Token first_outer_token(void) const;
  std::optional<Expr> trailing_requires_clause(void) const;
  Token type_spec_end_token(void) const;
  Token type_spec_start_token(void) const;
  std::vector<TemplateParameterList> template_parameter_lists(void) const;
};

static_assert(sizeof(DeclaratorDecl) == sizeof(ValueDecl));

#endif
} // namespace mx
