// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Stmt.h"

namespace mx {
class EntityProvider;
class Index;
class Decl;
class DeclStmt;
class Stmt;
class Token;
namespace mx {
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class DeclStmt : public Stmt {
 private:
  friend class FragmentImpl;
  friend class Stmt;
 public:
  static gap::generator<DeclStmt> in(const Fragment &frag);
  static gap::generator<DeclStmt> in(const File &file);
  static gap::generator<DeclStmt> in(const Index &index);
  static gap::generator<DeclStmt> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<DeclStmt> by_id(const Index &, EntityId);

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::DECL_STMT;
  }

  static gap::generator<DeclStmt> containing(const Decl &decl);
  static gap::generator<DeclStmt> containing(const std::optional<Decl> &decl);

  static gap::generator<DeclStmt> containing(const Stmt &stmt);
  static gap::generator<DeclStmt> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<DeclStmt> from(const Stmt &parent);

  inline static std::optional<DeclStmt> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return DeclStmt::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<DeclStmt> from(const Reference &r);
  static std::optional<DeclStmt> from(const TokenContext &t);

  std::optional<Decl> nth_declaration(unsigned n) const;
  unsigned num_declarations(void) const;
  gap::generator<Decl> declarations(void) const &;
  std::optional<Decl> single_declaration(void) const;
  bool is_single_declaration(void) const;
};

static_assert(sizeof(DeclStmt) == sizeof(Stmt));

#endif
} // namespace mx
