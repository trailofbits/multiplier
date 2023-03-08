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

#include "NamedDecl.h"

namespace mx {
class BuiltinTemplateDecl;
class ClassTemplateDecl;
class ConceptDecl;
class Decl;
class FunctionTemplateDecl;
class NamedDecl;
class Stmt;
class TemplateDecl;
class TemplateParameterList;
class TemplateTemplateParmDecl;
class Token;
class TypeAliasTemplateDecl;
class VarTemplateDecl;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class TemplateDecl : public NamedDecl {
 private:
  friend class FragmentImpl;
  friend class NamedDecl;
  friend class Decl;
 public:
  static gap::generator<TemplateDecl> in(const Fragment &frag);
  static gap::generator<TemplateDecl> in(const File &file);
  static gap::generator<TemplateDecl> in(const Index &index);
  static gap::generator<TemplateDecl> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<TemplateDecl> by_id(const Index &, EntityId);

  static gap::generator<TemplateDecl> containing(const Decl &decl);
  static gap::generator<TemplateDecl> containing(const std::optional<Decl> &decl);

  static gap::generator<TemplateDecl> containing(const Stmt &stmt);
  static gap::generator<TemplateDecl> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  gap::generator<TemplateDecl> redeclarations(void) const &;
  static std::optional<TemplateDecl> from(const Decl &parent);

  inline static std::optional<TemplateDecl> from(const std::optional<Decl> &parent) {
    if (parent) {
      return TemplateDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  inline static std::optional<TemplateDecl> from(const Reference &r) {
    return TemplateDecl::from(r.as_declaration());
  }

  inline static std::optional<TemplateDecl> from(const TokenContext &t) {
    return TemplateDecl::from(t.as_declaration());
  }

  TemplateParameterList template_parameters(void) const;
  NamedDecl templated_declaration(void) const;
  bool has_associated_constraints(void) const;
};

static_assert(sizeof(TemplateDecl) == sizeof(NamedDecl));

#endif
} // namespace mx
