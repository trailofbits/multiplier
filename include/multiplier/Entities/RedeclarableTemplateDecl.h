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
#include <span>
#include <vector>

#include <gap/core/generator.hpp>
#include "../Iterator.h"
#include "../Reference.h"
#include "../Types.h"
#include "../Token.h"

#include "DeclKind.h"
#include "TemplateDecl.h"

namespace mx {
class Decl;
class NamedDecl;
class RedeclarableTemplateDecl;
class TemplateDecl;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class RedeclarableTemplateDecl : public TemplateDecl {
 private:
  friend class FragmentImpl;
  friend class TemplateDecl;
  friend class NamedDecl;
  friend class Decl;
 public:
  static gap::generator<RedeclarableTemplateDecl> in(const Fragment &frag);
  static gap::generator<RedeclarableTemplateDecl> in(const Index &index);
  static gap::generator<RedeclarableTemplateDecl> containing(const Token &tok);
  bool contains(const Token &tok) const;
  std::optional<RedeclarableTemplateDecl> by(const Index &, EntityId);

  static gap::generator<RedeclarableTemplateDecl> containing(const Decl &decl);
  static gap::generator<RedeclarableTemplateDecl> containing(const std::optional<Decl> &decl);

  static gap::generator<RedeclarableTemplateDecl> containing(const Stmt &stmt);
  static gap::generator<RedeclarableTemplateDecl> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  gap::generator<RedeclarableTemplateDecl> redeclarations(void) const;
  inline static std::optional<RedeclarableTemplateDecl> from(const Reference &r) {
    return from(r.as_declaration());
  }

  inline static std::optional<RedeclarableTemplateDecl> from(const TokenContext &t) {
    return from(t.as_declaration());
  }

  static std::optional<RedeclarableTemplateDecl> from(const TemplateDecl &parent);

  inline static std::optional<RedeclarableTemplateDecl> from(const std::optional<TemplateDecl> &parent) {
    if (parent) {
      return RedeclarableTemplateDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<RedeclarableTemplateDecl> from(const NamedDecl &parent);

  inline static std::optional<RedeclarableTemplateDecl> from(const std::optional<NamedDecl> &parent) {
    if (parent) {
      return RedeclarableTemplateDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<RedeclarableTemplateDecl> from(const Decl &parent);

  inline static std::optional<RedeclarableTemplateDecl> from(const std::optional<Decl> &parent) {
    if (parent) {
      return RedeclarableTemplateDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  RedeclarableTemplateDecl instantiated_from_member_template(void) const;
  bool is_member_specialization(void) const;
};

static_assert(sizeof(RedeclarableTemplateDecl) == sizeof(TemplateDecl));

#endif
} // namespace mx
