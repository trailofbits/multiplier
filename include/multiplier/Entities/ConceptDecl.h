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
#include "../Reference.h"
#include "../Types.h"
#include "../Token.h"

#include "DeclKind.h"
#include "TemplateDecl.h"

namespace mx {
class ConceptDecl;
class Decl;
class Expr;
class NamedDecl;
class TemplateDecl;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class ConceptDecl : public TemplateDecl {
 private:
  friend class FragmentImpl;
  friend class TemplateDecl;
  friend class NamedDecl;
  friend class Decl;
 public:
  static gap::generator<ConceptDecl> in(const Fragment &frag);
  static gap::generator<ConceptDecl> containing(const Token &tok);
  bool contains(const Token &tok) const;

  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::CONCEPT;
  }

  static gap::generator<ConceptDecl> containing(const Decl &decl);
  static gap::generator<ConceptDecl> containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  gap::generator<ConceptDecl> redeclarations(void) const;
  inline static std::optional<ConceptDecl> from(const Reference &r) {
    return from(r.as_declaration());
  }

  inline static std::optional<ConceptDecl> from(const TokenContext &t) {
    return from(t.as_declaration());
  }

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
