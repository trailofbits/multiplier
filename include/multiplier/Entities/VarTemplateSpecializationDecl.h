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
#include "../Types.h"
#include "../Token.h"
#include "../Use.h"

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
  inline static gap::generator<VarTemplateSpecializationDecl> in(const Fragment &frag) {
    for (auto e : in_internal(frag)) {
      if (auto d = from(e)) {
        co_yield *d;
      }
    }
  }

  inline static gap::generator<VarTemplateSpecializationDecl> containing(const Token &tok) {
    for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
      if (auto d = from(*ctx)) {
        co_yield *d;
      }
    }
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : VarTemplateSpecializationDecl::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::VAR_TEMPLATE_SPECIALIZATION;
  }

  static gap::generator<VarTemplateSpecializationDecl> containing(const Decl &decl);
  static gap::generator<VarTemplateSpecializationDecl> containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<VarTemplateSpecializationDecl> from(const TokenContext &c);
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
  std::vector<TemplateArgument> template_arguments(void) const;
  std::vector<TemplateArgument> template_instantiation_arguments(void) const;
  Token template_keyword_token(void) const;
  Type type_as_written(void) const;
  bool is_class_scope_explicit_specialization(void) const;
  bool is_explicit_instantiation_or_specialization(void) const;
  bool is_explicit_specialization(void) const;
};

static_assert(sizeof(VarTemplateSpecializationDecl) == sizeof(VarDecl));

#endif
} // namespace mx
