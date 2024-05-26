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
class File;
class ImportDecl;
class Stmt;
class Token;
class TokenRange;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT ImportDecl : public Decl {
 private:
  friend class FragmentImpl;
  friend class Decl;
 public:
  static gap::generator<ImportDecl> in(const Index &index);
  static gap::generator<ImportDecl> in(const Fragment &frag);
  static gap::generator<ImportDecl> in(const File &file);
  static gap::generator<ImportDecl> containing(const Token &tok);
  bool contains(const Token &tok) const;

  static std::optional<ImportDecl> from(const ir::Operation &op);
  static gap::generator<std::pair<ImportDecl, ir::Operation>> in(const Compilation &tu);
  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::IMPORT;
  }

  static gap::generator<ImportDecl> containing(const Decl &decl);
  static gap::generator<ImportDecl> containing(const std::optional<Decl> &decl);

  static gap::generator<ImportDecl> containing(const Stmt &stmt);
  static gap::generator<ImportDecl> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  ImportDecl canonical_declaration(void) const;
  std::optional<ImportDecl> definition(void) const;
  gap::generator<ImportDecl> redeclarations(void) const &;
  static std::optional<ImportDecl> by_id(const Index &, EntityId);

  static std::optional<ImportDecl> from_base(const Decl &parent);
  inline static std::optional<ImportDecl> from(const Decl &parent) {
    return from_base(parent);
  }
  static std::optional<ImportDecl> from(const std::optional<Decl> &parent);
  static std::optional<ImportDecl> from(const Reference &r);
  static std::optional<ImportDecl> from(const VariantEntity &e);
  static std::optional<ImportDecl> from(const TokenContext &t);

  std::optional<Token> nth_identifier_token(unsigned n) const;
  unsigned num_identifier_tokens(void) const;
  gap::generator<Token> identifier_tokens(void) const &;
};

static_assert(sizeof(ImportDecl) == sizeof(Decl));

#endif
} // namespace mx
