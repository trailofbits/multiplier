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
  static gap::generator<FunctionTemplateDecl> in(const Fragment &frag);
  static gap::generator<FunctionTemplateDecl> in(const File &file);
  static gap::generator<FunctionTemplateDecl> in(const Index &index);
  static gap::generator<FunctionTemplateDecl> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<FunctionTemplateDecl> by_id(const Index &, EntityId);

  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::FUNCTION_TEMPLATE;
  }

  static gap::generator<FunctionTemplateDecl> containing(const Decl &decl);
  static gap::generator<FunctionTemplateDecl> containing(const std::optional<Decl> &decl);

  static gap::generator<FunctionTemplateDecl> containing(const Stmt &stmt);
  static gap::generator<FunctionTemplateDecl> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  gap::generator<FunctionTemplateDecl> redeclarations(void) const &;
  static std::optional<FunctionTemplateDecl> from(const Decl &parent);

  inline static std::optional<FunctionTemplateDecl> from(const std::optional<Decl> &parent) {
    if (parent) {
      return FunctionTemplateDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  inline static std::optional<FunctionTemplateDecl> from(const Reference &r) {
    return FunctionTemplateDecl::from(r.as_declaration());
  }

  inline static std::optional<FunctionTemplateDecl> from(const TokenContext &t) {
    return FunctionTemplateDecl::from(t.as_declaration());
  }

  bool is_abbreviated(void) const;
  bool is_this_declaration_a_definition(void) const;
};

static_assert(sizeof(FunctionTemplateDecl) == sizeof(RedeclarableTemplateDecl));

#endif
} // namespace mx
