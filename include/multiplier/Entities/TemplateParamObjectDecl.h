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
class NamedDecl;
class TemplateParamObjectDecl;
class ValueDecl;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class TemplateParamObjectDecl : public ValueDecl {
 private:
  friend class FragmentImpl;
  friend class ValueDecl;
  friend class NamedDecl;
  friend class Decl;
 public:
  static gap::generator<TemplateParamObjectDecl> in(const Fragment &frag);
  static gap::generator<TemplateParamObjectDecl> containing(const Token &tok);
  bool contains(const Token &tok) const;

  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::TEMPLATE_PARAM_OBJECT;
  }

  static gap::generator<DeclKind> derived_kinds(void);
  static gap::generator<TemplateParamObjectDecl> containing(const Decl &decl);
  static gap::generator<TemplateParamObjectDecl> containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  gap::generator<TemplateParamObjectDecl> redeclarations(void) const;
  inline static std::optional<TemplateParamObjectDecl> from(const Reference &r) {
    return from(r.as_declaration());
  }

  inline static std::optional<TemplateParamObjectDecl> from(const TokenContext &t) {
    return from(t.as_declaration());
  }

  static std::optional<TemplateParamObjectDecl> from(const ValueDecl &parent);

  inline static std::optional<TemplateParamObjectDecl> from(const std::optional<ValueDecl> &parent) {
    if (parent) {
      return TemplateParamObjectDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<TemplateParamObjectDecl> from(const NamedDecl &parent);

  inline static std::optional<TemplateParamObjectDecl> from(const std::optional<NamedDecl> &parent) {
    if (parent) {
      return TemplateParamObjectDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<TemplateParamObjectDecl> from(const Decl &parent);

  inline static std::optional<TemplateParamObjectDecl> from(const std::optional<Decl> &parent) {
    if (parent) {
      return TemplateParamObjectDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

};

static_assert(sizeof(TemplateParamObjectDecl) == sizeof(ValueDecl));

#endif
} // namespace mx
