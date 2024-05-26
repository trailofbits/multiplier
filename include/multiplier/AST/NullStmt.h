// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <multiplier/AST/Stmt.h>

namespace mx {
class EntityProvider;
class Fragment;
class Index;
class Decl;
class File;
class NullStmt;
class Stmt;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT NullStmt : public Stmt {
 private:
  friend class FragmentImpl;
  friend class Stmt;
 public:
  static gap::generator<NullStmt> in(const Index &index);
  static gap::generator<NullStmt> in(const Fragment &frag);
  static gap::generator<NullStmt> in(const File &file);
  static gap::generator<NullStmt> containing(const Token &tok);
  bool contains(const Token &tok) const;

  static std::optional<NullStmt> from(const ir::Operation &op);
  static gap::generator<std::pair<NullStmt, ir::Operation>> in(const Compilation &tu);
  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::NULL_STMT;
  }

  static gap::generator<NullStmt> containing(const Decl &decl);
  static gap::generator<NullStmt> containing(const std::optional<Decl> &decl);

  static gap::generator<NullStmt> containing(const Stmt &stmt);
  static gap::generator<NullStmt> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<NullStmt> by_id(const Index &, EntityId);

  static std::optional<NullStmt> from_base(const Stmt &parent);
  inline static std::optional<NullStmt> from(const Stmt &parent) {
    return from_base(parent);
  }
  static std::optional<NullStmt> from(const std::optional<Stmt> &parent);
  static std::optional<NullStmt> from(const Reference &r);
  static std::optional<NullStmt> from(const VariantEntity &e);
  static std::optional<NullStmt> from(const TokenContext &t);

  Token semi_token(void) const;
  bool has_leading_empty_macro(void) const;
};

static_assert(sizeof(NullStmt) == sizeof(Stmt));

#endif
} // namespace mx
