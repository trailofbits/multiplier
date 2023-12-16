// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <multiplier/AST/NamedDecl.h>

namespace mx {
class EntityProvider;
class Fragment;
class Index;
class Decl;
class NamedDecl;
class Stmt;
class TemplateDecl;
class TemplateParameterList;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT TemplateDecl : public NamedDecl {
 private:
  friend class FragmentImpl;
  friend class NamedDecl;
  friend class Decl;
 public:
  static gap::generator<TemplateDecl> in(const Index &index);
  static gap::generator<TemplateDecl> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<TemplateDecl> by_id(const Index &, EntityId);
  static gap::generator<TemplateDecl> in(const Fragment &frag);
  static gap::generator<TemplateDecl> in(const File &file);

#ifndef MX_DISABLE_VAST
  static std::optional<TemplateDecl> from(const ir::Operation &op);
  static gap::generator<std::pair<TemplateDecl, ir::Operation>> in(const Compilation &tu);
#endif  // MX_DISABLE_VAST

  static gap::generator<TemplateDecl> containing(const Decl &decl);
  static gap::generator<TemplateDecl> containing(const std::optional<Decl> &decl);

  static gap::generator<TemplateDecl> containing(const Stmt &stmt);
  static gap::generator<TemplateDecl> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  TemplateDecl canonical_declaration(void) const;
  std::optional<TemplateDecl> definition(void) const;
  gap::generator<TemplateDecl> redeclarations(void) const &;
  static std::optional<TemplateDecl> from_base(const Decl &parent);
  inline static std::optional<TemplateDecl> from(const Decl &parent) {
    return from_base(parent);
  }
  static std::optional<TemplateDecl> from(const std::optional<Decl> &parent);
  static std::optional<TemplateDecl> from(const Reference &r);
  static std::optional<TemplateDecl> from(const VariantEntity &e);
  static std::optional<TemplateDecl> from(const TokenContext &t);

  TemplateParameterList template_parameters(void) const;
  NamedDecl templated_declaration(void) const;
  bool has_associated_constraints(void) const;
  bool is_type_alias(void) const;
};

static_assert(sizeof(TemplateDecl) == sizeof(NamedDecl));

#endif
} // namespace mx
