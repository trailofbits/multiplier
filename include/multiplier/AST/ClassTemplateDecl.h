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
class ClassTemplateDecl;
class Decl;
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
class MX_EXPORT ClassTemplateDecl : public RedeclarableTemplateDecl {
 private:
  friend class FragmentImpl;
  friend class RedeclarableTemplateDecl;
  friend class TemplateDecl;
  friend class NamedDecl;
  friend class Decl;
 public:
  static gap::generator<ClassTemplateDecl> in(const Index &index);
  static gap::generator<ClassTemplateDecl> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<ClassTemplateDecl> by_id(const Index &, EntityId);
  static gap::generator<ClassTemplateDecl> in(const Fragment &frag);
  static gap::generator<ClassTemplateDecl> in(const File &file);

  static std::optional<ClassTemplateDecl> from(const ir::hl::Operation &op);
  static gap::generator<std::pair<ClassTemplateDecl, ir::hl::Operation>> in(const Compilation &tu);

  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::CLASS_TEMPLATE;
  }

  static gap::generator<ClassTemplateDecl> containing(const Decl &decl);
  static gap::generator<ClassTemplateDecl> containing(const std::optional<Decl> &decl);

  static gap::generator<ClassTemplateDecl> containing(const Stmt &stmt);
  static gap::generator<ClassTemplateDecl> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  ClassTemplateDecl canonical_declaration(void) const;
  std::optional<ClassTemplateDecl> definition(void) const;
  gap::generator<ClassTemplateDecl> redeclarations(void) const &;
  static std::optional<ClassTemplateDecl> from_base(const Decl &parent);
  inline static std::optional<ClassTemplateDecl> from(const Decl &parent) {
    return from_base(parent);
  }
  static std::optional<ClassTemplateDecl> from(const std::optional<Decl> &parent);
  static std::optional<ClassTemplateDecl> from(const Reference &r);
  static std::optional<ClassTemplateDecl> from(const VariantEntity &e);
  static std::optional<ClassTemplateDecl> from(const TokenContext &t);

  bool is_this_declaration_a_definition(void) const;
};

static_assert(sizeof(ClassTemplateDecl) == sizeof(RedeclarableTemplateDecl));

#endif
} // namespace mx
