// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <multiplier/AST/TemplateDecl.h>

namespace mx {
class EntityProvider;
class Fragment;
class Index;
class Decl;
class File;
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
class MX_EXPORT RedeclarableTemplateDecl : public TemplateDecl {
 private:
  friend class FragmentImpl;
  friend class TemplateDecl;
  friend class NamedDecl;
  friend class Decl;
 public:
  static gap::generator<RedeclarableTemplateDecl> in(const Index &index);
  static gap::generator<RedeclarableTemplateDecl> in(const Fragment &frag);
  static gap::generator<RedeclarableTemplateDecl> in(const File &file);
  static gap::generator<RedeclarableTemplateDecl> containing(const Token &tok);
  bool contains(const Token &tok) const;

  static std::optional<RedeclarableTemplateDecl> from(const ir::Operation &op);
  static gap::generator<std::pair<RedeclarableTemplateDecl, ir::Operation>> in(const Compilation &tu);
  static gap::generator<RedeclarableTemplateDecl> containing(const Decl &decl);
  static gap::generator<RedeclarableTemplateDecl> containing(const std::optional<Decl> &decl);

  static gap::generator<RedeclarableTemplateDecl> containing(const Stmt &stmt);
  static gap::generator<RedeclarableTemplateDecl> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  RedeclarableTemplateDecl canonical_declaration(void) const;
  std::optional<RedeclarableTemplateDecl> definition(void) const;
  gap::generator<RedeclarableTemplateDecl> redeclarations(void) const &;
  static std::optional<RedeclarableTemplateDecl> by_id(const Index &, EntityId);

  static std::optional<RedeclarableTemplateDecl> from_base(const Decl &parent);
  inline static std::optional<RedeclarableTemplateDecl> from(const Decl &parent) {
    return from_base(parent);
  }
  static std::optional<RedeclarableTemplateDecl> from(const std::optional<Decl> &parent);
  static std::optional<RedeclarableTemplateDecl> from(const Reference &r);
  static std::optional<RedeclarableTemplateDecl> from(const VariantEntity &e);
  static std::optional<RedeclarableTemplateDecl> from(const TokenContext &t);

  bool is_member_specialization(void) const;
};

static_assert(sizeof(RedeclarableTemplateDecl) == sizeof(TemplateDecl));

#endif
} // namespace mx
