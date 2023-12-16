// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <multiplier/AST/RedeclarableTemplateDecl.h>

namespace mx {
class EntityProvider;
class Fragment;
class Index;
class Decl;
class FunctionTemplateDecl;
class NamedDecl;
class RedeclarableTemplateDecl;
class Stmt;
class TemplateDecl;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT FunctionTemplateDecl : public RedeclarableTemplateDecl {
 private:
  friend class FragmentImpl;
  friend class RedeclarableTemplateDecl;
  friend class TemplateDecl;
  friend class NamedDecl;
  friend class Decl;
 public:
  static gap::generator<FunctionTemplateDecl> in(const Index &index);
  static gap::generator<FunctionTemplateDecl> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<FunctionTemplateDecl> by_id(const Index &, EntityId);
  static gap::generator<FunctionTemplateDecl> in(const Fragment &frag);
  static gap::generator<FunctionTemplateDecl> in(const File &file);

#ifndef MX_DISABLE_VAST
  static std::optional<FunctionTemplateDecl> from(const ir::Operation &op);
  static gap::generator<std::pair<FunctionTemplateDecl, ir::Operation>> in(const Compilation &tu);
#endif  // MX_DISABLE_VAST

  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::FUNCTION_TEMPLATE;
  }

  static gap::generator<FunctionTemplateDecl> containing(const Decl &decl);
  static gap::generator<FunctionTemplateDecl> containing(const std::optional<Decl> &decl);

  static gap::generator<FunctionTemplateDecl> containing(const Stmt &stmt);
  static gap::generator<FunctionTemplateDecl> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  FunctionTemplateDecl canonical_declaration(void) const;
  std::optional<FunctionTemplateDecl> definition(void) const;
  gap::generator<FunctionTemplateDecl> redeclarations(void) const &;
  static std::optional<FunctionTemplateDecl> from_base(const Decl &parent);
  inline static std::optional<FunctionTemplateDecl> from(const Decl &parent) {
    return from_base(parent);
  }
  static std::optional<FunctionTemplateDecl> from(const std::optional<Decl> &parent);
  static std::optional<FunctionTemplateDecl> from(const Reference &r);
  static std::optional<FunctionTemplateDecl> from(const VariantEntity &e);
  static std::optional<FunctionTemplateDecl> from(const TokenContext &t);

  bool is_abbreviated(void) const;
  bool is_this_declaration_a_definition(void) const;
};

static_assert(sizeof(FunctionTemplateDecl) == sizeof(RedeclarableTemplateDecl));

#endif
} // namespace mx
