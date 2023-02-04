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
#include "TemplateSpecializationKind.h"
#include "VarDecl.h"

namespace mx {
class Decl;
class DeclaratorDecl;
class NamedDecl;
class TemplateArgument;
class Type;
class ValueDecl;
class VarDecl;
class VarTemplateDecl;
class VarTemplateSpecializationDecl;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class VarTemplateSpecializationDecl : public VarDecl {
 private:
  friend class FragmentImpl;
  friend class VarDecl;
  friend class DeclaratorDecl;
  friend class ValueDecl;
  friend class NamedDecl;
  friend class Decl;
 public:
  static gap::generator<VarTemplateSpecializationDecl> in(const Fragment &frag);
  static gap::generator<VarTemplateSpecializationDecl> containing(const Token &tok);
  bool contains(const Token &tok) const;

  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::VAR_TEMPLATE_SPECIALIZATION;
  }

  static gap::generator<VarTemplateSpecializationDecl> containing(const Decl &decl);
  static gap::generator<VarTemplateSpecializationDecl> containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  gap::generator<VarTemplateSpecializationDecl> redeclarations(void) const;
  inline static std::optional<VarTemplateSpecializationDecl> from(const Reference &r) {
    return from(r.as_declaration());
  }

  inline static std::optional<VarTemplateSpecializationDecl> from(const TokenContext &t) {
    return from(t.as_declaration());
  }

  static std::optional<VarTemplateSpecializationDecl> from(const VarDecl &parent);

  inline static std::optional<VarTemplateSpecializationDecl> from(const std::optional<VarDecl> &parent) {
    if (parent) {
      return VarTemplateSpecializationDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<VarTemplateSpecializationDecl> from(const DeclaratorDecl &parent);

  inline static std::optional<VarTemplateSpecializationDecl> from(const std::optional<DeclaratorDecl> &parent) {
    if (parent) {
      return VarTemplateSpecializationDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<VarTemplateSpecializationDecl> from(const ValueDecl &parent);

  inline static std::optional<VarTemplateSpecializationDecl> from(const std::optional<ValueDecl> &parent) {
    if (parent) {
      return VarTemplateSpecializationDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<VarTemplateSpecializationDecl> from(const NamedDecl &parent);

  inline static std::optional<VarTemplateSpecializationDecl> from(const std::optional<NamedDecl> &parent) {
    if (parent) {
      return VarTemplateSpecializationDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<VarTemplateSpecializationDecl> from(const Decl &parent);

  inline static std::optional<VarTemplateSpecializationDecl> from(const std::optional<Decl> &parent) {
    if (parent) {
      return VarTemplateSpecializationDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  Token extern_token(void) const;
  TemplateSpecializationKind specialization_kind(void) const;
  VarTemplateDecl specialized_template(void) const;
  std::optional<TemplateArgument> nth_template_argument(unsigned n) const;
  gap::generator<TemplateArgument> template_arguments(void) const;
  std::optional<TemplateArgument> nth_template_instantiation_argument(unsigned n) const;
  gap::generator<TemplateArgument> template_instantiation_arguments(void) const;
  Token template_keyword_token(void) const;
  Type type_as_written(void) const;
  bool is_class_scope_explicit_specialization(void) const;
  bool is_explicit_instantiation_or_specialization(void) const;
  bool is_explicit_specialization(void) const;
};

static_assert(sizeof(VarTemplateSpecializationDecl) == sizeof(VarDecl));

#endif
} // namespace mx
