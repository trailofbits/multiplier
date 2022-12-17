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
#include "TemplateDecl.h"

namespace mx {
class ConceptDecl;
class Decl;
class Expr;
class NamedDecl;
class TemplateDecl;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using ConceptDeclRange = DerivedEntityRange<DeclIterator, ConceptDecl>;
using ConceptDeclContainingTokenRange = DerivedEntityRange<TokenContextIterator, ConceptDecl>;
using ConceptDeclContainingDeclRange = DerivedEntityRange<ParentDeclIteratorImpl<Decl>, ConceptDecl>;

class ConceptDecl : public TemplateDecl {
 private:
  friend class FragmentImpl;
  friend class TemplateDecl;
  friend class NamedDecl;
  friend class Decl;
 public:
  inline static ConceptDeclRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static ConceptDeclContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    for (auto &parent : ConceptDecl::containing(tok)) {
      if (parent.id() == id()) { return true; }
    }
    return false;
  }

  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::CONCEPT;
  }

  static ConceptDeclContainingDeclRange containing(const Decl &decl);
  static ConceptDeclContainingDeclRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<ConceptDecl> from(const TokenContext &c);
  static std::optional<ConceptDecl> from(const TemplateDecl &parent);

  inline static std::optional<ConceptDecl> from(const std::optional<TemplateDecl> &parent) {
    if (parent) {
      return ConceptDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ConceptDecl> from(const NamedDecl &parent);

  inline static std::optional<ConceptDecl> from(const std::optional<NamedDecl> &parent) {
    if (parent) {
      return ConceptDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ConceptDecl> from(const Decl &parent);

  inline static std::optional<ConceptDecl> from(const std::optional<Decl> &parent) {
    if (parent) {
      return ConceptDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  Expr constraint_expression(void) const;
  bool is_type_concept(void) const;
};

static_assert(sizeof(ConceptDecl) == sizeof(TemplateDecl));

#endif
} // namespace mx
