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

#include "DeclKind.h"
#include "RedeclarableTemplateDecl.h"

namespace mx {
class Decl;
class FunctionTemplateDecl;
class NamedDecl;
class RedeclarableTemplateDecl;
class TemplateDecl;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class FunctionTemplateDecl : public RedeclarableTemplateDecl {
 private:
  friend class FragmentImpl;
  friend class RedeclarableTemplateDecl;
  friend class TemplateDecl;
  friend class NamedDecl;
  friend class Decl;
 public:
  inline static gap::generator<FunctionTemplateDecl> in(const Fragment &frag) {
    for (auto e : in_internal(frag)) {
      if (auto d = from(e)) {
        co_yield *d;
      }
    }
  }

  inline static gap::generator<FunctionTemplateDecl> containing(const Token &tok) {
    for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
      if (auto d = from(*ctx)) {
        co_yield *d;
      }
    }
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : FunctionTemplateDecl::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::FUNCTION_TEMPLATE;
  }

  static gap::generator<FunctionTemplateDecl> containing(const Decl &decl);
  static gap::generator<FunctionTemplateDecl> containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<FunctionTemplateDecl> from(const TokenContext &c);
  static std::optional<FunctionTemplateDecl> from(const RedeclarableTemplateDecl &parent);

  inline static std::optional<FunctionTemplateDecl> from(const std::optional<RedeclarableTemplateDecl> &parent) {
    if (parent) {
      return FunctionTemplateDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<FunctionTemplateDecl> from(const TemplateDecl &parent);

  inline static std::optional<FunctionTemplateDecl> from(const std::optional<TemplateDecl> &parent) {
    if (parent) {
      return FunctionTemplateDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<FunctionTemplateDecl> from(const NamedDecl &parent);

  inline static std::optional<FunctionTemplateDecl> from(const std::optional<NamedDecl> &parent) {
    if (parent) {
      return FunctionTemplateDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<FunctionTemplateDecl> from(const Decl &parent);

  inline static std::optional<FunctionTemplateDecl> from(const std::optional<Decl> &parent) {
    if (parent) {
      return FunctionTemplateDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  bool is_abbreviated(void) const;
};

static_assert(sizeof(FunctionTemplateDecl) == sizeof(RedeclarableTemplateDecl));

#endif
} // namespace mx
