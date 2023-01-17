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
#include "NamedDecl.h"

namespace mx {
class Decl;
class NamedDecl;
class TemplateDecl;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class TemplateDecl : public NamedDecl {
 private:
  friend class FragmentImpl;
  friend class NamedDecl;
  friend class Decl;
 public:
  inline static gap::generator<TemplateDecl> in(const Fragment &frag) {
    for (auto e : in_internal(frag)) {
      if (auto d = from(e)) {
        co_yield *d;
      }
    }
  }

  inline static gap::generator<TemplateDecl> containing(const Token &tok) {
    for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
      if (auto d = from(*ctx)) {
        co_yield *d;
      }
    }
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : TemplateDecl::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  static gap::generator<TemplateDecl> containing(const Decl &decl);
  static gap::generator<TemplateDecl> containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<TemplateDecl> from(const TokenContext &c);
  static std::optional<TemplateDecl> from(const NamedDecl &parent);

  inline static std::optional<TemplateDecl> from(const std::optional<NamedDecl> &parent) {
    if (parent) {
      return TemplateDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<TemplateDecl> from(const Decl &parent);

  inline static std::optional<TemplateDecl> from(const std::optional<Decl> &parent) {
    if (parent) {
      return TemplateDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  TemplateParameterList template_parameters(void) const;
  NamedDecl templated_declaration(void) const;
  bool has_associated_constraints(void) const;
};

static_assert(sizeof(TemplateDecl) == sizeof(NamedDecl));

#endif
} // namespace mx
