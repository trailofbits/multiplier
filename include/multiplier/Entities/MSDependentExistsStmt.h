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
class CompoundStmt;
class Decl;
class MSDependentExistsStmt;
class Stmt;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MSDependentExistsStmt : public Stmt {
 private:
  friend class FragmentImpl;
  friend class Stmt;
 public:
  static gap::generator<MSDependentExistsStmt> in(const Index &index);
  static gap::generator<MSDependentExistsStmt> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<MSDependentExistsStmt> by_id(const Index &, EntityId);
  static gap::generator<MSDependentExistsStmt> in(const Fragment &frag);
  static gap::generator<MSDependentExistsStmt> in(const File &file);

  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::MS_DEPENDENT_EXISTS_STMT;
  }

  static gap::generator<MSDependentExistsStmt> containing(const Decl &decl);
  static gap::generator<MSDependentExistsStmt> containing(const std::optional<Decl> &decl);

  static gap::generator<MSDependentExistsStmt> containing(const Stmt &stmt);
  static gap::generator<MSDependentExistsStmt> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<MSDependentExistsStmt> from(const Stmt &parent);

  inline static std::optional<MSDependentExistsStmt> from(const std::optional<Stmt> &parent) {
    if (parent) {
      return MSDependentExistsStmt::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<MSDependentExistsStmt> from(const Reference &r);
  static std::optional<MSDependentExistsStmt> from(const TokenContext &t);

  Token keyword_token(void) const;
  CompoundStmt sub_statement(void) const;
  bool is_if_exists(void) const;
  bool is_if_not_exists(void) const;
};

static_assert(sizeof(MSDependentExistsStmt) == sizeof(Stmt));

#endif
} // namespace mx
