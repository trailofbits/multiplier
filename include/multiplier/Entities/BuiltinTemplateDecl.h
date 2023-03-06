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

#include "TemplateDecl.h"

namespace mx {
class BuiltinTemplateDecl;
class Decl;
class NamedDecl;
class Stmt;
class TemplateDecl;
class Token;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class BuiltinTemplateDecl : public TemplateDecl {
 private:
  friend class FragmentImpl;
  friend class TemplateDecl;
  friend class NamedDecl;
  friend class Decl;
 public:
  static gap::generator<BuiltinTemplateDecl> in(const Fragment &frag);
  static gap::generator<BuiltinTemplateDecl> in(const File &file);
  static gap::generator<BuiltinTemplateDecl> in(const Index &index);
  static gap::generator<BuiltinTemplateDecl> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<BuiltinTemplateDecl> by_id(const Index &, EntityId);

  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::BUILTIN_TEMPLATE;
  }

  static gap::generator<BuiltinTemplateDecl> containing(const Decl &decl);
  static gap::generator<BuiltinTemplateDecl> containing(const std::optional<Decl> &decl);

  static gap::generator<BuiltinTemplateDecl> containing(const Stmt &stmt);
  static gap::generator<BuiltinTemplateDecl> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  gap::generator<BuiltinTemplateDecl> redeclarations(void) const &;
  static std::optional<BuiltinTemplateDecl> from(const Decl &parent);

  inline static std::optional<BuiltinTemplateDecl> from(const std::optional<Decl> &parent) {
    if (parent) {
      return BuiltinTemplateDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  inline static std::optional<BuiltinTemplateDecl> from(const Reference &r) {
    return BuiltinTemplateDecl::from(r.as_declaration());
  }

  inline static std::optional<BuiltinTemplateDecl> from(const TokenContext &t) {
    return BuiltinTemplateDecl::from(t.as_declaration());
  }

};

static_assert(sizeof(BuiltinTemplateDecl) == sizeof(TemplateDecl));

#endif
} // namespace mx
