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
#include "ValueDecl.h"

namespace mx {
class Decl;
class DeclaratorDecl;
class Expr;
class NamedDecl;
class TemplateParameterList;
class ValueDecl;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class DeclaratorDecl : public ValueDecl {
 private:
  friend class FragmentImpl;
  friend class ValueDecl;
  friend class NamedDecl;
  friend class Decl;
 public:
  static gap::generator<DeclaratorDecl> in(const Fragment &frag);
  static gap::generator<DeclaratorDecl> containing(const Token &tok);
  bool contains(const Token &tok) const;

  static gap::generator<DeclKind> derived_kinds(void);
  static gap::generator<DeclaratorDecl> containing(const Decl &decl);
  static gap::generator<DeclaratorDecl> containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  gap::generator<DeclaratorDecl> redeclarations(void) const;
  inline static std::optional<DeclaratorDecl> from(const Reference &r) {
    return from(r.as_declaration());
  }

  inline static std::optional<DeclaratorDecl> from(const TokenContext &t) {
    return from(t.as_declaration());
  }

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
  std::optional<TemplateParameterList> nth_template_parameter_list(unsigned n) const;
  gap::generator<TemplateParameterList> template_parameter_lists(void) const;
};

static_assert(sizeof(DeclaratorDecl) == sizeof(ValueDecl));

#endif
} // namespace mx
