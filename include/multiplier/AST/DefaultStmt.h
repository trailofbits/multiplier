// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <multiplier/AST/SwitchCase.h>

namespace mx {
class EntityProvider;
class Fragment;
class Index;
class Decl;
class DefaultStmt;
class Stmt;
class SwitchCase;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT DefaultStmt : public SwitchCase {
 private:
  friend class FragmentImpl;
  friend class SwitchCase;
  friend class Stmt;
 public:
  static gap::generator<DefaultStmt> in(const Index &index);
  static gap::generator<DefaultStmt> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<DefaultStmt> by_id(const Index &, EntityId);
  static gap::generator<DefaultStmt> in(const Fragment &frag);
  static gap::generator<DefaultStmt> in(const File &file);

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::DEFAULT_STMT;
  }

  static gap::generator<DefaultStmt> containing(const Decl &decl);
  static gap::generator<DefaultStmt> containing(const std::optional<Decl> &decl);

  static gap::generator<DefaultStmt> containing(const Stmt &stmt);
  static gap::generator<DefaultStmt> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<DefaultStmt> from_base(const Stmt &parent);
  inline static std::optional<DefaultStmt> from(const Stmt &parent) {
    return from_base(parent);
  }
  static std::optional<DefaultStmt> from(const std::optional<Stmt> &parent);
  static std::optional<DefaultStmt> from(const Reference &r);
  static std::optional<DefaultStmt> from(const VariantEntity &e);
  static std::optional<DefaultStmt> from(const TokenContext &t);

  Token default_token(void) const;
};

static_assert(sizeof(DefaultStmt) == sizeof(SwitchCase));

#endif
} // namespace mx
