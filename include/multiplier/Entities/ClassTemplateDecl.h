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
#include "RedeclarableTemplateDecl.h"

namespace mx {
class ClassTemplateDecl;
class Decl;
class NamedDecl;
class RedeclarableTemplateDecl;
class TemplateDecl;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class ClassTemplateDecl : public RedeclarableTemplateDecl {
 private:
  friend class FragmentImpl;
  friend class RedeclarableTemplateDecl;
  friend class TemplateDecl;
  friend class NamedDecl;
  friend class Decl;
 public:
  static gap::generator<ClassTemplateDecl> in(const Fragment &frag);
  static gap::generator<ClassTemplateDecl> in(const Index &index);
  static gap::generator<ClassTemplateDecl> containing(const Token &tok);
  bool contains(const Token &tok) const;
  std::optional<ClassTemplateDecl> by(const Index &, EntityId);

  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::CLASS_TEMPLATE;
  }

  static gap::generator<ClassTemplateDecl> containing(const Decl &decl);
  static gap::generator<ClassTemplateDecl> containing(const std::optional<Decl> &decl);

  static gap::generator<ClassTemplateDecl> containing(const Stmt &stmt);
  static gap::generator<ClassTemplateDecl> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  gap::generator<ClassTemplateDecl> redeclarations(void) const;
  inline static std::optional<ClassTemplateDecl> from(const Reference &r) {
    return from(r.as_declaration());
  }

  inline static std::optional<ClassTemplateDecl> from(const TokenContext &t) {
    return from(t.as_declaration());
  }

  static std::optional<ClassTemplateDecl> from(const RedeclarableTemplateDecl &parent);

  inline static std::optional<ClassTemplateDecl> from(const std::optional<RedeclarableTemplateDecl> &parent) {
    if (parent) {
      return ClassTemplateDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ClassTemplateDecl> from(const TemplateDecl &parent);

  inline static std::optional<ClassTemplateDecl> from(const std::optional<TemplateDecl> &parent) {
    if (parent) {
      return ClassTemplateDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ClassTemplateDecl> from(const NamedDecl &parent);

  inline static std::optional<ClassTemplateDecl> from(const std::optional<NamedDecl> &parent) {
    if (parent) {
      return ClassTemplateDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ClassTemplateDecl> from(const Decl &parent);

  inline static std::optional<ClassTemplateDecl> from(const std::optional<Decl> &parent) {
    if (parent) {
      return ClassTemplateDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  bool is_this_declaration_a_definition(void) const;
};

static_assert(sizeof(ClassTemplateDecl) == sizeof(RedeclarableTemplateDecl));

#endif
} // namespace mx
