// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <multiplier/AST/Decl.h>

namespace mx {
class EntityProvider;
class Fragment;
class Index;
class Decl;
class ExportDecl;
class Stmt;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT ExportDecl : public Decl {
 private:
  friend class FragmentImpl;
  friend class Decl;
 public:
  static gap::generator<ExportDecl> in(const Index &index);
  static gap::generator<ExportDecl> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<ExportDecl> by_id(const Index &, EntityId);
  static gap::generator<ExportDecl> in(const Fragment &frag);
  static gap::generator<ExportDecl> in(const File &file);

  static std::optional<ExportDecl> from(const ir::hl::Operation &op);
  static gap::generator<std::pair<ExportDecl, ir::hl::Operation>> in(const Compilation &tu);

  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::EXPORT;
  }

  static gap::generator<ExportDecl> containing(const Decl &decl);
  static gap::generator<ExportDecl> containing(const std::optional<Decl> &decl);

  static gap::generator<ExportDecl> containing(const Stmt &stmt);
  static gap::generator<ExportDecl> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  ExportDecl canonical_declaration(void) const;
  std::optional<ExportDecl> definition(void) const;
  gap::generator<ExportDecl> redeclarations(void) const &;
  static std::optional<ExportDecl> from_base(const Decl &parent);
  inline static std::optional<ExportDecl> from(const Decl &parent) {
    return from_base(parent);
  }
  static std::optional<ExportDecl> from(const std::optional<Decl> &parent);
  static std::optional<ExportDecl> from(const Reference &r);
  static std::optional<ExportDecl> from(const VariantEntity &e);
  static std::optional<ExportDecl> from(const TokenContext &t);

  Token export_token(void) const;
  Token r_brace_token(void) const;
  bool has_braces(void) const;
  gap::generator<Decl> declarations_in_context(void) const &;
};

static_assert(sizeof(ExportDecl) == sizeof(Decl));

#endif
} // namespace mx
